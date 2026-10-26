// RT64 render context: bridges ultramodern's RendererContext with the RT64 renderer, applying the
// config file's graphics settings (live when the menu changes them).

// NOMINMAX must be set globally via CMake (target_compile_definitions)
// Include RT64 first to avoid Windows.h macro conflicts
#include "hle/rt64_application.h"
#ifdef __linux__
#include <SDL_syswm.h>
#endif

#include <cstdio>
#include <cstring>
#include <memory>
#include <string>

#include "ultramodern/renderer_context.hpp"
#include "librecomp/game.hpp"
#include "config.hpp"
#include "internal.hpp"

#include <algorithm>
#include <filesystem>

namespace fe {

std::atomic<bool> g_graphics_dirty = false;

// Maps a config string onto an RT64 enum value; unknown names keep `fallback`.
template <typename E>
static E pick(const std::string& name, std::initializer_list<std::pair<const char*, E>> options, E fallback) {
    for (auto& [n, v] : options) if (name == n) return v;
    fprintf(stderr, "[config] unknown value '%s', using default\n", name.c_str());
    return fallback;
}

// Applies the config's graphics section to RT64.
static void apply_graphics_config(RT64::UserConfiguration& u) {
    using U = RT64::UserConfiguration;
    u.resolution = pick(g_config.resolution, { { "Original", U::Resolution::Original },
        { "WindowIntegerScale", U::Resolution::WindowIntegerScale }, { "Manual", U::Resolution::Manual } }, u.resolution);
    u.resolutionMultiplier = g_config.resolutionMultiplier;
    u.aspectRatio = pick(g_config.aspectRatio, { { "Original", U::AspectRatio::Original },
        { "Expand", U::AspectRatio::Expand } }, u.aspectRatio);
    u.antialiasing = pick(g_config.antialiasing, { { "None", U::Antialiasing::None }, { "MSAA2X", U::Antialiasing::MSAA2X },
        { "MSAA4X", U::Antialiasing::MSAA4X }, { "MSAA8X", U::Antialiasing::MSAA8X } }, u.antialiasing);
    u.filtering = pick(g_config.filtering, { { "Nearest", U::Filtering::Nearest }, { "Linear", U::Filtering::Linear },
        { "AntiAliasedPixelScaling", U::Filtering::AntiAliasedPixelScaling } }, u.filtering);
    u.refreshRate = pick(g_config.refreshRate, { { "Original", U::RefreshRate::Original },
        { "Display", U::RefreshRate::Display } }, u.refreshRate);
    u.developerMode = g_config.developerMode; // read at setup only
    u.validate();
}

// Loads every .rtz and folder in texture-packs/ (alphabetical) as RT64 replacement packs.
static void load_texture_packs(RT64::Application& app) {
    const std::filesystem::path dir = std::filesystem::current_path() / "texture-packs";
    std::filesystem::create_directories(dir);
    std::vector<RT64::ReplacementDirectory> packs;
    for (auto& e : std::filesystem::directory_iterator(dir)) {
        if (e.is_directory() || e.path().extension() == ".rtz") packs.emplace_back(e.path());
    }
    std::sort(packs.begin(), packs.end(), [](auto& a, auto& b) { return a.dirOrZipPath < b.dirOrZipPath; });
    if (packs.empty()) return;
    for (auto& p : packs) printf("[frontend] texture pack: %s\n", p.dirOrZipPath.filename().string().c_str());
    if (!app.textureCache->loadReplacementDirectories(packs)) {
        fprintf(stderr, "[frontend] failed to load texture packs\n");
    }
}

// Static buffers for RT64 Core (RSP memory, not used in HLE mode but required)
static uint8_t s_dmem[0x1000];
static uint8_t s_imem[0x1000];

// DPC registers (dummy storage - RT64 HLE doesn't use these directly)
static uint32_t s_dpc_start = 0;
static uint32_t s_dpc_end = 0;
static uint32_t s_dpc_current = 0;
static uint32_t s_dpc_status = 0;
static uint32_t s_dpc_clock = 0;
static uint32_t s_dpc_bufbusy = 0;
static uint32_t s_dpc_pipebusy = 0;
static uint32_t s_dpc_tmem = 0;
static uint32_t s_mi_intr = 0;

static void dummy_check_interrupts() {
    // No-op: ultramodern handles interrupts
}

class RT64Context : public ultramodern::renderer::RendererContext {
public:
    RT64Context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode)
        : rdram_(rdram), window_handle_(window_handle), developer_mode_(developer_mode)
    {
        setup_result = ultramodern::renderer::SetupResult::Success;

        // Get VI register pointers from ultramodern
        vi_regs_ = ultramodern::renderer::get_vi_regs();

        // Set up the RT64 Core structure
        RT64::Application::Core core{};
#if defined(_WIN32)
        core.window = window_handle.window;
        uint32_t thread_id = window_handle.thread_id;
#elif defined(__APPLE__)
        core.window = { window_handle.window, window_handle.view };
        uint32_t thread_id = 0;
#elif defined(__ANDROID__)
        SDL_SysWMinfo wm;
        SDL_VERSION(&wm.version);
        SDL_GetWindowWMInfo(window_handle, &wm);
        core.window = wm.info.android.window;
        uint32_t thread_id = 0;
#else
        // ponytail: X11 only; Wayland sessions run it through XWayland (SDL2 picks X11 by default)
        SDL_SysWMinfo wm;
        SDL_VERSION(&wm.version);
        SDL_GetWindowWMInfo(window_handle, &wm);
        core.window = { wm.info.x11.display, wm.info.x11.window };
        uint32_t thread_id = 0;
#endif
        core.RDRAM = rdram;
        core.DMEM = s_dmem;
        core.IMEM = s_imem;

        // ROM header (first 0x40 bytes)
        auto rom = recomp::get_rom();
        if (rom.size() >= 0x40) {
            rom_header_.assign(rom.begin(), rom.begin() + 0x40);
            core.HEADER = rom_header_.data();
        } else {
            rom_header_.resize(0x40, 0);
            core.HEADER = rom_header_.data();
        }

        // MI/DPC registers (dummy)
        core.MI_INTR_REG = &s_mi_intr;
        core.DPC_START_REG = &s_dpc_start;
        core.DPC_END_REG = &s_dpc_end;
        core.DPC_CURRENT_REG = &s_dpc_current;
        core.DPC_STATUS_REG = &s_dpc_status;
        core.DPC_CLOCK_REG = &s_dpc_clock;
        core.DPC_BUFBUSY_REG = &s_dpc_bufbusy;
        core.DPC_PIPEBUSY_REG = &s_dpc_pipebusy;
        core.DPC_TMEM_REG = &s_dpc_tmem;

        // VI registers - point into ultramodern's ViRegs struct
        core.VI_STATUS_REG = &vi_regs_->VI_STATUS_REG;
        core.VI_ORIGIN_REG = &vi_regs_->VI_ORIGIN_REG;
        core.VI_WIDTH_REG = &vi_regs_->VI_WIDTH_REG;
        core.VI_INTR_REG = &vi_regs_->VI_INTR_REG;
        core.VI_V_CURRENT_LINE_REG = &vi_regs_->VI_V_CURRENT_LINE_REG;
        core.VI_TIMING_REG = &vi_regs_->VI_TIMING_REG;
        core.VI_V_SYNC_REG = &vi_regs_->VI_V_SYNC_REG;
        core.VI_H_SYNC_REG = &vi_regs_->VI_H_SYNC_REG;
        core.VI_LEAP_REG = &vi_regs_->VI_LEAP_REG;
        core.VI_H_START_REG = &vi_regs_->VI_H_START_REG;
        core.VI_V_START_REG = &vi_regs_->VI_V_START_REG;
        core.VI_V_BURST_REG = &vi_regs_->VI_V_BURST_REG;
        core.VI_X_SCALE_REG = &vi_regs_->VI_X_SCALE_REG;
        core.VI_Y_SCALE_REG = &vi_regs_->VI_Y_SCALE_REG;

        core.checkInterrupts = dummy_check_interrupts;

        // Configure RT64 application
        RT64::ApplicationConfiguration app_config;
        app_config.appId = g_game.short_name;
        app_config.detectDataPath = true;
        app_config.useConfigurationFile = false; // settings come from our config file

        // Create the RT64 Application
        printf("[rt64] Creating RT64 application...\n");
        app_ = std::make_unique<RT64::Application>(core, app_config);
        apply_graphics_config(app_->userConfig);

        // Run setup (creates graphics device, swap chain, shader caches, etc.)
        auto result = app_->setup(thread_id);
        using API = RT64::UserConfiguration::GraphicsAPI;
        chosen_api = app_->chosenGraphicsAPI == API::D3D12 ? ultramodern::renderer::GraphicsApi::D3D12
                   : app_->chosenGraphicsAPI == API::Metal ? ultramodern::renderer::GraphicsApi::Metal
                   : ultramodern::renderer::GraphicsApi::Vulkan;

        switch (result) {
        case RT64::Application::SetupResult::Success:
            printf("[rt64] RT64 initialized successfully\n");
            if (g_config.texturePacks) {
                load_texture_packs(*app_);
            }
            is_valid_ = true;
            break;
        case RT64::Application::SetupResult::DynamicLibrariesNotFound:
            fprintf(stderr, "[rt64] RT64: Dynamic libraries not found\n");
            setup_result = ultramodern::renderer::SetupResult::DynamicLibrariesNotFound;
            break;
        case RT64::Application::SetupResult::InvalidGraphicsAPI:
            fprintf(stderr, "[rt64] RT64: Invalid graphics API\n");
            setup_result = ultramodern::renderer::SetupResult::InvalidGraphicsAPI;
            break;
        case RT64::Application::SetupResult::GraphicsAPINotFound:
            fprintf(stderr, "[rt64] RT64: Graphics API not found\n");
            setup_result = ultramodern::renderer::SetupResult::GraphicsAPINotFound;
            break;
        case RT64::Application::SetupResult::GraphicsDeviceNotFound:
            fprintf(stderr, "[rt64] RT64: Graphics device not found\n");
            setup_result = ultramodern::renderer::SetupResult::GraphicsDeviceNotFound;
            break;
        }
    }

    ~RT64Context() override {
        if (app_) {
            printf("[rt64] Destroying RT64 application\n");
            app_->end(); // ~Application is empty; end() tears down in order (and calls our deinit hook)
            app_.reset();
        }
    }

    bool valid() override { return is_valid_; }

    bool update_config(const ultramodern::renderer::GraphicsConfig& old_config,
                       const ultramodern::renderer::GraphicsConfig& new_config) override {
        // TODO: forward config changes to RT64
        return true;
    }

    void enable_instant_present() override {
        // RT64 doesn't have a separate instant present mode
    }

    void send_dl(const OSTask* task) override {
        if (!app_ || !is_valid_) return;

        dl_count_++;
        if (dl_count_ <= 5 || (dl_count_ % 60 == 0)) {
            printf("[rt64] send_dl #%u: data_ptr=0x%08X ucode=0x%08X ucode_data=0x%08X type=%u\n",
                   dl_count_, (uint32_t)task->t.data_ptr, (uint32_t)task->t.ucode,
                   (uint32_t)task->t.ucode_data, task->t.type);
        }

        // Tell RT64's HLE interpreter which microcode/GBI to use BEFORE parsing
        // the display list. Without this the interpreter has no GBI command map
        // and crashes in processDisplayLists. ucode/ucode_data/data_ptr are MIPS
        // virtual addresses; mask to the RDRAM physical offset RT64 indexes by.
        uint32_t ucode      = (uint32_t)task->t.ucode      & 0x3FFFFFF;
        uint32_t ucode_data = (uint32_t)task->t.ucode_data & 0x3FFFFFF;
        uint32_t dl_address = (uint32_t)task->t.data_ptr   & 0x3FFFFFF;
        app_->interpreter->loadUCodeGBI(ucode, ucode_data, true);
        app_->processDisplayLists(rdram_, dl_address, 0, true);
    }

    // ponytail: only sent before the game starts (dummy VI frames); nothing to draw yet.
    void send_dummy_workload(uint32_t /*fb_address*/) override {}

    void update_screen() override {
        if (!app_ || !is_valid_) return;

        screen_count_++;
        if (screen_count_ <= 5 || (screen_count_ % 60 == 0)) {
            printf("[rt64] update_screen #%u VI origin=0x%08X width=%u hstart=0x%08X vstart=0x%08X status=0x%08X xscale=0x%X yscale=0x%X vsync=0x%X hsync=0x%X\n",
                   screen_count_, vi_regs_->VI_ORIGIN_REG, vi_regs_->VI_WIDTH_REG,
                   vi_regs_->VI_H_START_REG, vi_regs_->VI_V_START_REG, vi_regs_->VI_STATUS_REG,
                   vi_regs_->VI_X_SCALE_REG, vi_regs_->VI_Y_SCALE_REG, vi_regs_->VI_V_SYNC_REG, vi_regs_->VI_H_SYNC_REG);
        }

        // The menu changed graphics settings: apply them here, on the thread RT64 presents from.
        if (g_graphics_dirty.exchange(false)) {
            RT64::UserConfiguration::Antialiasing old_aa = app_->userConfig.antialiasing;
            apply_graphics_config(app_->userConfig);
            app_->updateUserConfig(true);
            if (app_->userConfig.antialiasing != old_aa) app_->updateMultisampling();
        }

        app_->updateScreen();
    }

    void shutdown() override {
        printf("[rt64] Render context shutdown\n");
        if (app_) {
            app_->end(); // ~Application is empty; end() tears down in order (and calls our deinit hook)
            app_.reset();
        }
        is_valid_ = false;
    }

    uint32_t get_display_framerate() const override {
        return 60; // TODO: query from RT64/display
    }

    float get_resolution_scale() const override {
        return 1.0f;
    }

private:
    uint8_t* rdram_;
    ultramodern::renderer::WindowHandle window_handle_;
    bool developer_mode_;
    bool is_valid_ = false;
    ultramodern::renderer::ViRegs* vi_regs_ = nullptr;
    std::unique_ptr<RT64::Application> app_;
    std::vector<uint8_t> rom_header_;
    uint32_t dl_count_ = 0;
    uint32_t screen_count_ = 0;
};

std::unique_ptr<ultramodern::renderer::RendererContext> create_render_context(
    uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
    return std::make_unique<RT64Context>(rdram, window_handle, developer_mode);
}

} // namespace fe
