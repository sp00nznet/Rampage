// The launcher and in-game menu: Dear ImGui drawn over the game through RT64's render hooks.
//
// The main thread (SDL events, the loop in recomp::start) builds an ImGui frame about 60 times a
// second; RT64's present thread draws the latest one on top of the game at each present. g_mutex
// guards the ImGui context between the two. It draws with whichever API RT64 picked: D3D12 on
// Windows, Vulkan on Linux, Metal on macOS (as RT64's own inspector does).
//
// ponytail: RT64's own inspector (developerMode) also uses ImGui's global context; don't open our
// menu while it's showing.

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include "rhi/rt64_render_hooks.h"
#include "plume_vulkan.h" // volk, before ImGui's Vulkan backend

#include "imgui.h"
#include "backends/imgui_impl_vulkan.h"
#include "imgui/imgui_impl_sdl2_custom.h"
#ifdef _WIN32
#include "plume_d3d12.h"
#include "backends/imgui_impl_dx12.h"
#endif
#ifdef __APPLE__
#include "plume_metal.h"
#include "backends/imgui_impl_metal.h"
#endif

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cfloat>
#include <cstdio>
#include <filesystem>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include "ultramodern/ultramodern.hpp"
#include "config.hpp"
#include "internal.hpp"

namespace fe {
namespace {

// --- Rendering (RT64's present thread) -------------------------------------------------------

enum class Api { None, D3D12, Vulkan, Metal };

std::mutex g_mutex;
ImGuiContext* g_ctx = nullptr;
Api g_api = Api::None;
plume::RenderDevice* g_device = nullptr;
std::atomic<bool> g_backend_ready = false;
bool g_has_frame = false; // a frame was built since the UI was last hidden

#ifdef _WIN32
ID3D12CommandQueue* g_queue = nullptr;
std::vector<std::unique_ptr<plume::RenderDescriptorSet>> g_srv_sets;

void srv_alloc(ImGui_ImplDX12_InitInfo*, D3D12_CPU_DESCRIPTOR_HANDLE* cpu, D3D12_GPU_DESCRIPTOR_HANDLE* gpu) {
    auto* dev = static_cast<plume::D3D12Device*>(g_device);
    plume::RenderDescriptorRange range(plume::RenderDescriptorRangeType::TEXTURE, 0, 1);
    std::unique_ptr<plume::RenderDescriptorSet> set = dev->createDescriptorSet(plume::RenderDescriptorSetDesc(&range, 1));
    auto* d = static_cast<plume::D3D12DescriptorSet*>(set.get());
    *cpu = dev->viewHeapAllocator->getCPUHandleAt(d->viewAllocation.offset);
    *gpu = dev->viewHeapAllocator->getGPUHandleAt(d->viewAllocation.offset);
    g_srv_sets.push_back(std::move(set));
}

// ponytail: descriptors are only released at shutdown; ImGui frees a few as its font atlas grows.
void srv_free(ImGui_ImplDX12_InitInfo*, D3D12_CPU_DESCRIPTOR_HANDLE, D3D12_GPU_DESCRIPTOR_HANDLE) {}
#endif

void vk_check(VkResult r) { if (r != VK_SUCCESS) fprintf(stderr, "[ui] Vulkan error %d\n", (int)r); }

void hook_init(RenderInterface*, RenderDevice* device) {
    g_device = device;
    g_api = Api::None;
#ifdef _WIN32
    if (dynamic_cast<plume::D3D12Device*>(device)) g_api = Api::D3D12;
#endif
#ifdef __APPLE__
    if (dynamic_cast<plume::MetalDevice*>(device)) g_api = Api::Metal;
#endif
    if (dynamic_cast<plume::VulkanDevice*>(device)) g_api = Api::Vulkan;
    if (g_api == Api::None) fprintf(stderr, "[ui] unknown graphics API; the launcher and menu are unavailable\n");
}

// The backend is set up on the first present, when the swap chain's format is known.
bool init_backend(RenderCommandList* list, RenderFramebuffer* fb) {
    switch (g_api) {
#ifdef _WIN32
    case Api::D3D12: {
        auto* dev = static_cast<plume::D3D12Device*>(g_device);
        const auto* d3d_fb = static_cast<const plume::D3D12Framebuffer*>(fb);
        D3D12_COMMAND_QUEUE_DESC qd{ D3D12_COMMAND_LIST_TYPE_DIRECT };
        if (d3d_fb->colorTargets.empty() || FAILED(dev->d3d->CreateCommandQueue(&qd, IID_PPV_ARGS(&g_queue)))) return false;
        ImGui_ImplDX12_InitInfo info;
        info.Device = dev->d3d;
        info.CommandQueue = g_queue;
        info.NumFramesInFlight = 2;
        info.RTVFormat = d3d_fb->colorTargets[0]->d3d->GetDesc().Format;
        info.SrvDescriptorHeap = dev->viewHeapAllocator->heap;
        info.SrvDescriptorAllocFn = srv_alloc;
        info.SrvDescriptorFreeFn = srv_free;
        return ImGui_ImplDX12_Init(&info);
    }
#endif
    case Api::Vulkan: {
        auto* dev = static_cast<plume::VulkanDevice*>(g_device);
        auto* cl = static_cast<plume::VulkanCommandList*>(list);
        const auto* vk_fb = static_cast<const plume::VulkanFramebuffer*>(fb);
        ImGui_ImplVulkan_LoadFunctions(VK_API_VERSION_1_2, [](const char* name, void* instance) {
            return vkGetInstanceProcAddr(*reinterpret_cast<VkInstance*>(instance), name);
        }, &dev->renderInterface->instance);
        ImGui_ImplVulkan_InitInfo info = {};
        info.Instance = dev->renderInterface->instance;
        info.PhysicalDevice = dev->physicalDevice;
        info.Device = dev->vk;
        // ponytail: shares RT64's present queue, as RT64's inspector does; ImGui submits on it only
        // to upload font textures, from this (the present) thread.
        info.QueueFamily = cl->queue->familyIndex;
        info.Queue = cl->queue->queue->vk;
        info.DescriptorPoolSize = IMGUI_IMPL_VULKAN_MINIMUM_SAMPLED_IMAGE_POOL_SIZE;
        info.MinImageCount = 2;
        info.ImageCount = 2;
        info.CheckVkResultFn = vk_check;
        info.PipelineInfoMain.RenderPass = vk_fb->renderPass; // every swap chain framebuffer's pass is compatible
        return ImGui_ImplVulkan_Init(&info);
    }
#ifdef __APPLE__
    case Api::Metal: {
        auto* dev = static_cast<plume::MetalDevice*>(g_device);
        if (!ImGui_ImplMetal_Init(dev->mtl)) return false;
        return ImGui_ImplMetal_CreateDeviceObjects(dev->mtl);
    }
#endif
    default: return false;
    }
}

void hook_draw(RenderCommandList* list, RenderFramebuffer* fb) {
    if (g_api == Api::None || !g_ctx) return;
    std::lock_guard lock{ g_mutex };
    ImGui::SetCurrentContext(g_ctx);
    if (!g_backend_ready) {
        if (!init_backend(list, fb)) { fprintf(stderr, "[ui] the overlay couldn't start; the launcher and menu are unavailable\n"); g_api = Api::None; return; }
        g_backend_ready = true;
        printf("[ui] overlay ready (api %d)\n", (int)g_api);
        return;
    }
    if (!g_has_frame) return;
    ImDrawData* dd = ImGui::GetDrawData();
    if (!dd || !dd->Valid) return;
    switch (g_api) {
#ifdef _WIN32
    case Api::D3D12: {
        auto* cl = static_cast<plume::D3D12CommandList*>(list);
        cl->checkDescriptorHeaps(); // ImGui's textures live in RT64's descriptor heap
        ImGui_ImplDX12_RenderDrawData(dd, cl->d3d);
        break;
    }
#endif
    case Api::Vulkan: {
        auto* cl = static_cast<plume::VulkanCommandList*>(list);
        cl->checkActiveRenderPass();
        ImGui_ImplVulkan_RenderDrawData(dd, cl->vk);
        break;
    }
#ifdef __APPLE__
    case Api::Metal: {
        NS::AutoreleasePool* pool = NS::AutoreleasePool::alloc()->init();
        auto* cl = static_cast<plume::MetalCommandList*>(list);
        cl->checkActiveRenderEncoder();
        MTL::RenderPassDescriptor* rp = MTL::RenderPassDescriptor::renderPassDescriptor();
        MTL::RenderPassColorAttachmentDescriptor* color = rp->colorAttachments()->object(0);
        color->setTexture(cl->targetFramebuffer->colorAttachments[0].getTexture());
        color->setLoadAction(MTL::LoadActionLoad);
        color->setStoreAction(MTL::StoreActionStore);
        ImGui_ImplMetal_NewFrame(rp);
        ImGui_ImplMetal_RenderDrawData(dd, cl->mtl, cl->activeRenderEncoder);
        pool->release();
        break;
    }
#endif
    default: break;
    }
}

void hook_deinit() {
    std::lock_guard lock{ g_mutex };
    if (g_backend_ready) {
        ImGui::SetCurrentContext(g_ctx);
        switch (g_api) {
#ifdef _WIN32
        case Api::D3D12: ImGui_ImplDX12_Shutdown(); break;
#endif
        case Api::Vulkan: ImGui_ImplVulkan_Shutdown(); break;
#ifdef __APPLE__
        case Api::Metal: ImGui_ImplMetal_Shutdown(); break;
#endif
        default: break;
        }
        g_backend_ready = false;
    }
#ifdef _WIN32
    g_srv_sets.clear();
    if (g_queue) { g_queue->Release(); g_queue = nullptr; }
#endif
    g_device = nullptr;
    g_api = Api::None;
}

// --- State (main thread) ---------------------------------------------------------------------

enum class Screen { Hidden, Launcher, Connecting, Settings, Menu };
Screen g_screen = Screen::Hidden;
Screen g_settings_back = Screen::Launcher; // where Settings' Back button goes
bool g_focus_first = true;                 // focus the first item when a screen opens
SDL_Window* g_window = nullptr;
float g_scale = 0.0f;
ImGuiStyle g_base_style;

std::string g_rom_error;
char g_rom_path[1024] = "";
char g_join_address[256] = "";

std::thread g_net_thread;
std::atomic<bool> g_net_cancel = false;
std::atomic<int> g_net_result = 0; // 0 connecting, 1 connected, -1 failed
bool g_net_hosting = false;
std::vector<std::string> g_addresses;

// Rebinding: the next matching input becomes the binding for g_capture_button.
std::string g_capture_button;
bool g_capture_keyboard = false;
bool g_bind_keyboard = false; // which bindings the Controls tab shows

std::string g_open_tab; // select this settings tab on the next frame

void show(Screen s) { g_screen = s; g_focus_first = true; printf("[ui] screen %d\n", (int)s); }

void focus_first() {
    if (g_focus_first) { ImGui::SetKeyboardFocusHere(); g_focus_first = false; }
}

// A centered panel `em` font-heights wide.
void panel_begin(const char* id, float em) {
    ImGuiIO& io = ImGui::GetIO();
    float w = em * ImGui::GetFontSize();
    ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSizeConstraints(ImVec2(w, 0), ImVec2(w, io.DisplaySize.y * 0.9f));
    ImGui::Begin(id, nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings);
}

void heading(const std::string& text, float size = 1.6f) {
    ImGui::PushFont(nullptr, ImGui::GetStyle().FontSizeBase * size);
    ImGui::TextUnformatted(text.c_str());
    ImGui::PopFont();
    ImGui::Spacing();
}

bool wide_button(const char* label) { return ImGui::Button(label, ImVec2(-FLT_MIN, 0)); }

bool combo(const char* label, std::string& value, std::initializer_list<std::pair<const char*, const char*>> options) {
    const char* shown = value.c_str();
    for (auto& [v, name] : options) if (value == v) shown = name;
    bool changed = false;
    if (ImGui::BeginCombo(label, shown)) {
        for (auto& [v, name] : options) {
            if (ImGui::Selectable(name, value == v)) { value = v; changed = true; }
        }
        ImGui::EndCombo();
    }
    return changed;
}

// --- Screens ---------------------------------------------------------------------------------

void start_netplay(bool hosting) {
    g_net_hosting = hosting;
    g_net_cancel = false;
    g_net_result = 0;
    if (hosting) g_addresses = net::local_addresses();
    std::string address = g_join_address;
    g_net_thread = std::thread([hosting, address] {
        bool ok = hosting ? net::host(g_config.netplayPort, g_net_cancel) : net::join(address, g_net_cancel);
        g_net_result = ok ? 1 : -1;
    });
    show(Screen::Connecting);
}

void launcher() {
    panel_begin("##launcher", 24);
    heading(g_game.title);
    if (!find_rom()) {
        ImGui::TextWrapped("Drop your %s ROM (USA, .z64) onto this window, or type where it is:", g_game.title.c_str());
        ImGui::SetNextItemWidth(-FLT_MIN);
        focus_first();
        bool enter = ImGui::InputText("##rom", g_rom_path, sizeof(g_rom_path), ImGuiInputTextFlags_EnterReturnsTrue);
        if (wide_button("Use this ROM") || enter) {
            std::string path = g_rom_path;
            if (path.size() > 1 && path.front() == '"') path = path.substr(1, path.size() - 2);
            import_rom(path, g_rom_error);
        }
        if (!g_rom_error.empty()) ImGui::TextColored(ImVec4(1, 0.5f, 0.4f, 1), "%s", g_rom_error.c_str());
        ImGui::Spacing();
        if (wide_button("Settings")) { g_settings_back = Screen::Launcher; show(Screen::Settings); }
        if (wide_button("Quit")) quit();
        ImGui::End();
        return;
    }
    focus_first();
    if (wide_button("Play")) { show(Screen::Hidden); start_game(); }
    if (g_game.netplay) {
        ImGui::Spacing();
        ImGui::SeparatorText("Netplay (2 players)");
        if (wide_button("Host a game")) start_netplay(true);
        ImGui::SetNextItemWidth(-ImGui::CalcTextSize("Join").x - ImGui::GetStyle().FramePadding.x * 2 - ImGui::GetStyle().ItemSpacing.x);
        bool enter = ImGui::InputTextWithHint("##join", "host address (e.g. 100.64.0.5)", g_join_address, sizeof(g_join_address),
            ImGuiInputTextFlags_EnterReturnsTrue);
        ImGui::SameLine();
        if ((ImGui::Button("Join") || enter) && g_join_address[0]) {
            g_config.netplayAddress = g_join_address;
            save_config();
            start_netplay(false);
        }
    }
    ImGui::Spacing();
    ImGui::Separator();
    if (wide_button("Settings")) { g_settings_back = Screen::Launcher; show(Screen::Settings); }
    if (wide_button("Quit")) quit();
    ImGui::Spacing();
    ImGui::TextDisabled("F11: fullscreen   Esc / Back: menu in game");
    ImGui::End();
}

void connecting() {
    if (g_net_result != 0 && g_net_thread.joinable()) g_net_thread.join();
    if (g_net_result == 1) {
        net::begin();
        show(Screen::Hidden);
       
        start_game();
        return;
    }
    panel_begin("##net", 26);
    heading(g_net_hosting ? "Hosting" : "Joining");
    ImGui::TextWrapped("%s", net::status().c_str());
    if (g_net_hosting && g_net_result == 0) {
        ImGui::Spacing();
        ImGui::TextWrapped("Player 2 joins one of these addresses (the 100.x one over Tailscale), UDP port %d:", g_config.netplayPort);
        for (const std::string& a : g_addresses) ImGui::BulletText("%s", a.c_str());
    }
    ImGui::Spacing();
    focus_first();
    if (g_net_result == 0) {
        if (wide_button("Cancel")) g_net_cancel = true;
    } else if (wide_button("Back")) {
        show(Screen::Launcher);
    }
    ImGui::End();
}

const std::pair<const char*, const char*> kBindRows[] = {
    { "A", "A" }, { "B", "B" }, { "Z", "Z" }, { "Start", "Start" }, { "L", "L" }, { "R", "R" },
    { "StickUp", "Stick up" }, { "StickDown", "Stick down" }, { "StickLeft", "Stick left" }, { "StickRight", "Stick right" },
    { "DUp", "D-pad up" }, { "DDown", "D-pad down" }, { "DLeft", "D-pad left" }, { "DRight", "D-pad right" },
    { "CUp", "C up" }, { "CDown", "C down" }, { "CLeft", "C left" }, { "CRight", "C right" },
};

void controls_tab() {
    float dz = (float)g_config.deadzone;
    if (ImGui::SliderFloat("Stick deadzone", &dz, 0.0f, 0.5f, "%.2f")) { g_config.deadzone = dz; input_rebuild(); }

    ImGui::SeparatorText("Players");
    std::vector<std::string> pads = input_controller_names();
    for (int p = 0; p < g_game.players; p++) {
        PlayerConfig& pc = g_config.players[p];
        std::string current = pc.device == "keyboard" ? "Keyboard" : pc.device == "none" ? "Nobody"
            : pc.device == "controller" ? "Controller " + std::to_string(pc.controller + 1) : "Auto";
        ImGui::PushID(p);
        ImGui::SetNextItemWidth(12 * ImGui::GetFontSize());
        bool changed = false;
        if (ImGui::BeginCombo(("Player " + std::to_string(p + 1)).c_str(), current.c_str())) {
            if (ImGui::Selectable("Auto (next controller plugged in)", pc.device == "auto")) { pc.device = "auto"; changed = true; }
            if (ImGui::Selectable("Keyboard", pc.device == "keyboard")) { pc.device = "keyboard"; changed = true; }
            for (size_t i = 0; i < pads.size(); i++) {
                std::string name = "Controller " + std::to_string(i + 1) + ": " + pads[i];
                if (ImGui::Selectable(name.c_str(), pc.device == "controller" && pc.controller == (int)i)) {
                    pc.device = "controller"; pc.controller = (int)i; changed = true;
                }
            }
            if (ImGui::Selectable("Nobody", pc.device == "none")) { pc.device = "none"; changed = true; }
            ImGui::EndCombo();
        }
        if (changed) input_rebuild();
        ImGui::SameLine();
        ImGui::TextDisabled("%s", input_port_device_name(p).c_str());
        ImGui::PopID();
    }

    ImGui::SeparatorText("Buttons (all players)");
    if (ImGui::RadioButton("Controller", !g_bind_keyboard)) g_bind_keyboard = false;
    ImGui::SameLine();
    if (ImGui::RadioButton("Keyboard", g_bind_keyboard)) g_bind_keyboard = true;
    ImGui::SameLine();
    if (ImGui::Button("Reset to defaults")) {
        if (g_bind_keyboard) g_config.keyboardBindings = g_game.keyboard_bindings.empty() ? default_keyboard_bindings() : g_game.keyboard_bindings;
        else g_config.controllerBindings = g_game.controller_bindings.empty() ? default_controller_bindings() : g_game.controller_bindings;
        input_rebuild();
    }
    Bindings& b = g_bind_keyboard ? g_config.keyboardBindings : g_config.controllerBindings;
    float rows_h = std::max(6.0f * ImGui::GetFrameHeightWithSpacing(), ImGui::GetIO().DisplaySize.y * 0.85f - ImGui::GetCursorScreenPos().y);
    if (ImGui::BeginTable("##binds", 3, ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp | ImGuiTableFlags_ScrollY, ImVec2(0, rows_h))) {
        for (auto& [key, label] : kBindRows) {
            ImGui::PushID(key);
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::TextUnformatted(label);
            ImGui::TableNextColumn();
            std::string joined;
            for (const std::string& s : b[key]) joined += (joined.empty() ? "" : ", ") + s;
            bool capturing = g_capture_button == key && g_capture_keyboard == g_bind_keyboard;
            ImGui::TextUnformatted(capturing ? "press a button... (Esc cancels)" : joined.empty() ? "-" : joined.c_str());
            ImGui::TableNextColumn();
            if (ImGui::SmallButton("Set")) { g_capture_button = key; g_capture_keyboard = g_bind_keyboard; }
            ImGui::SameLine();
            if (ImGui::SmallButton("Clear")) { b[key].clear(); input_rebuild(); }
            ImGui::PopID();
        }
        ImGui::EndTable();
    }
}

void graphics_tab() {
    bool changed = false;
    changed |= combo("Resolution", g_config.resolution, { { "Original", "Original (N64)" },
        { "WindowIntegerScale", "Match the window" }, { "Manual", "Multiplier" } });
    if (g_config.resolution == "Manual") {
        float m = (float)g_config.resolutionMultiplier;
        if (ImGui::SliderFloat("Multiplier", &m, 1.0f, 8.0f, "%.0fx")) { g_config.resolutionMultiplier = std::round(m); changed = true; }
    }
    changed |= combo("Aspect ratio", g_config.aspectRatio, { { "Original", "4:3 (original)" }, { "Expand", "Widescreen (experimental)" } });
    changed |= combo("Anti-aliasing", g_config.antialiasing, { { "None", "Off" }, { "MSAA2X", "MSAA 2x" },
        { "MSAA4X", "MSAA 4x" }, { "MSAA8X", "MSAA 8x" } });
    changed |= combo("Filtering", g_config.filtering, { { "Nearest", "Nearest" }, { "Linear", "Linear" },
        { "AntiAliasedPixelScaling", "Sharp pixel scaling" } });
    changed |= combo("Frame rate", g_config.refreshRate, { { "Original", "60 Hz (original)" }, { "Display", "Match the display" } });
    if (changed) g_graphics_dirty = true;

    ImGui::Spacing();
    if (ImGui::Checkbox("Fullscreen (F11)", &g_config.fullscreen)) apply_window_config();
    int displays = SDL_GetNumVideoDisplays();
    if (displays > 1) {
        const char* name = SDL_GetDisplayName(g_config.display);
        std::string shown = std::to_string(g_config.display + 1) + (name ? std::string(": ") + name : "");
        if (ImGui::BeginCombo("Monitor", shown.c_str())) {
            for (int d = 0; d < displays; d++) {
                const char* n = SDL_GetDisplayName(d);
                std::string label = std::to_string(d + 1) + (n ? std::string(": ") + n : "");
                if (ImGui::Selectable(label.c_str(), g_config.display == d)) { g_config.display = d; apply_window_config(); }
            }
            ImGui::EndCombo();
        }
    }
    ImGui::Checkbox("Texture packs (restart to apply)", &g_config.texturePacks);
}

void sound_tab() {
    int v = (int)std::lround(g_config.volume * 100);
    if (ImGui::SliderInt("Volume", &v, 0, 100, "%d%%")) g_config.volume = v / 100.0;
}

void netplay_tab() {
    ImGui::SliderInt("Input delay (frames)", &g_config.netplayInputDelay, 0, 10);
    ImGui::TextDisabled("More delay hides more lag. The host's setting is used. 2 suits most connections.");
    ImGui::InputInt("UDP port", &g_config.netplayPort);
    g_config.netplayPort = std::clamp(g_config.netplayPort, 1, 65535);
}

void cheats_tab() {
    auto list = cheats_list();
    if (list.empty()) {
        ImGui::TextWrapped("No cheats.cht next to the game. Put a GameShark code list there in Project64's "
                           ".cht format (Project64 ships one per game in Config\\Cheats), then restart.");
        return;
    }
    if (net::active()) ImGui::TextDisabled("Cheats are off during netplay.");
    for (auto& c : list) {
        bool on = c.enabled;
        if (ImGui::Checkbox(c.name.c_str(), &on)) cheats_set(c.name, on);
        if (!c.note.empty() && ImGui::IsItemHovered()) {
            ImGui::BeginTooltip();
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 28); // notes are long single lines
            ImGui::TextUnformatted(c.note.c_str());
            ImGui::PopTextWrapPos();
            ImGui::EndTooltip();
        }
    }
    ImGui::TextDisabled("Turning a cheat off doesn't undo what it already changed.");
}

void settings() {
    panel_begin("##settings", 36);
    heading("Settings", 1.4f);
    auto tab = [](const char* name) {
        ImGuiTabItemFlags f = g_open_tab == name ? ImGuiTabItemFlags_SetSelected : 0;
        return ImGui::BeginTabItem(name, nullptr, f);
    };
    if (ImGui::BeginTabBar("##tabs")) {
        if (tab("Controls")) { controls_tab(); ImGui::EndTabItem(); }
        if (tab("Graphics")) { graphics_tab(); ImGui::EndTabItem(); }
        if (tab("Sound")) { sound_tab(); ImGui::EndTabItem(); }
        if (g_game.netplay && tab("Netplay")) { netplay_tab(); ImGui::EndTabItem(); }
        if (tab("Cheats")) { cheats_tab(); ImGui::EndTabItem(); }
        ImGui::EndTabBar();
        g_open_tab.clear();
    }
    ImGui::Spacing();
    if (wide_button("Back")) { save_config(); show(g_settings_back); }
    ImGui::End();
}

void menu() {
    panel_begin("##menu", 18);
    heading(g_game.title, 1.2f);
    if (net::active()) {
        ImGui::TextDisabled("Netplay: you are player %d, %d frames delay", net::is_host() ? 1 : 2, net::delay());
        ImGui::TextDisabled("The game keeps running while this menu is open.");
    }
    focus_first();
    if (wide_button("Resume")) show(Screen::Hidden);
    if (wide_button("Settings")) { g_settings_back = Screen::Menu; show(Screen::Settings); }
    if (wide_button("Quit game")) quit();
    ImGui::End();
}

// Esc / the controller's Back or Guide button.
void back_pressed() {
    if (!g_capture_button.empty()) { g_capture_button.clear(); return; }
    switch (g_screen) {
    case Screen::Hidden: if (ultramodern::is_game_started()) show(Screen::Menu); break;
    case Screen::Menu: show(Screen::Hidden); break;
    case Screen::Settings: save_config(); show(g_settings_back); break;
    default: break;
    }
}

// The next input while rebinding. Returns true if it was used.
bool capture(const SDL_Event& e) {
    std::string input;
    if (g_capture_keyboard && e.type == SDL_KEYDOWN && e.key.keysym.scancode != SDL_SCANCODE_ESCAPE) {
        input = SDL_GetScancodeName(e.key.keysym.scancode);
    } else if (!g_capture_keyboard && e.type == SDL_CONTROLLERBUTTONDOWN &&
               e.cbutton.button != SDL_CONTROLLER_BUTTON_BACK && e.cbutton.button != SDL_CONTROLLER_BUTTON_GUIDE) {
        input = SDL_GameControllerGetStringForButton((SDL_GameControllerButton)e.cbutton.button);
    } else if (!g_capture_keyboard && e.type == SDL_CONTROLLERAXISMOTION && std::abs(e.caxis.value) > 24000) {
        input = std::string(e.caxis.value > 0 ? "+" : "-") + SDL_GameControllerGetStringForAxis((SDL_GameControllerAxis)e.caxis.axis);
    }
    if (input.empty()) return false;
    Bindings& b = g_capture_keyboard ? g_config.keyboardBindings : g_config.controllerBindings;
    b[g_capture_button] = { input };
    g_capture_button.clear();
    input_rebuild();
    return true;
}

// Controller -> ImGui gamepad navigation (RT64's SDL backend leaves gamepads to us).
void feed_gamepad(const SDL_Event& e) {
    ImGuiIO& io = ImGui::GetIO();
    if (e.type == SDL_CONTROLLERBUTTONDOWN || e.type == SDL_CONTROLLERBUTTONUP) {
        bool down = e.type == SDL_CONTROLLERBUTTONDOWN;
        ImGuiKey key = ImGuiKey_None;
        switch (e.cbutton.button) {
        case SDL_CONTROLLER_BUTTON_A: key = ImGuiKey_GamepadFaceDown; break;
        case SDL_CONTROLLER_BUTTON_B: key = ImGuiKey_GamepadFaceRight; break;
        case SDL_CONTROLLER_BUTTON_X: key = ImGuiKey_GamepadFaceLeft; break;
        case SDL_CONTROLLER_BUTTON_Y: key = ImGuiKey_GamepadFaceUp; break;
        case SDL_CONTROLLER_BUTTON_DPAD_UP: key = ImGuiKey_GamepadDpadUp; break;
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN: key = ImGuiKey_GamepadDpadDown; break;
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT: key = ImGuiKey_GamepadDpadLeft; break;
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT: key = ImGuiKey_GamepadDpadRight; break;
        case SDL_CONTROLLER_BUTTON_LEFTSHOULDER: key = ImGuiKey_GamepadL1; break;
        case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER: key = ImGuiKey_GamepadR1; break;
        }
        if (key != ImGuiKey_None) io.AddKeyEvent(key, down);
    } else if (e.type == SDL_CONTROLLERAXISMOTION) {
        float v = e.caxis.value / 32767.0f;
        auto pair = [&](ImGuiKey neg, ImGuiKey pos) {
            io.AddKeyAnalogEvent(neg, v < -0.3f, v < -0.3f ? -v : 0.0f);
            io.AddKeyAnalogEvent(pos, v > 0.3f, v > 0.3f ? v : 0.0f);
        };
        if (e.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX) pair(ImGuiKey_GamepadLStickLeft, ImGuiKey_GamepadLStickRight);
        if (e.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY) pair(ImGuiKey_GamepadLStickUp, ImGuiKey_GamepadLStickDown);
    }
}

// Scales the UI with the window: 1x at 600 lines.
void update_scale() {
    float scale = std::max(1.0f, ImGui::GetIO().DisplaySize.y / 600.0f);
    if (std::abs(scale - g_scale) < 0.01f) return;
    g_scale = scale;
    ImGuiStyle s = g_base_style;
    s.ScaleAllSizes(scale);
    s.FontScaleMain = scale;
    ImGui::GetStyle() = s;
}

} // namespace

void ui_init() {
    RT64::SetRenderHooks(hook_init, hook_draw, hook_deinit);
    IMGUI_CHECKVERSION();
    ImGuiContext* prev = ImGui::GetCurrentContext();
    g_ctx = ImGui::CreateContext();
    ImGui::SetCurrentContext(g_ctx);
    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_NavEnableGamepad;
    // Segoe UI where it exists, else ImGui's scalable default.
    if (!std::filesystem::exists("C:/Windows/Fonts/segoeui.ttf") || !io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/segoeui.ttf", 16.0f)) {
        io.Fonts->AddFontDefaultVector();
    }
    ImGui::StyleColorsDark();
    ImGuiStyle& s = ImGui::GetStyle();
    s.WindowRounding = 8; s.FrameRounding = 5; s.GrabRounding = 5; s.TabRounding = 5;
    s.WindowPadding = ImVec2(18, 16); s.FramePadding = ImVec2(10, 6); s.ItemSpacing = ImVec2(8, 7);
    s.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.07f, 0.09f, 0.94f);
    g_base_style = s;
    ImGui::SetCurrentContext(prev ? prev : g_ctx);
}

void ui_attach_window(SDL_Window* w) {
    std::lock_guard lock{ g_mutex };
    g_window = w;
    ImGui::SetCurrentContext(g_ctx);
    ImGui_ImplSDL2_InitForOther(w);
}

void ui_show_launcher() {
    if (g_config.netplayAddress.size() < sizeof(g_join_address)) strcpy(g_join_address, g_config.netplayAddress.c_str());
    show(Screen::Launcher);
}

bool ui_visible() { return g_screen != Screen::Hidden; }

bool ui_handle_event(const SDL_Event& e) {
    if (!g_window) return false;
    if (e.type == SDL_DROPFILE) {
        if (g_screen == Screen::Launcher && !find_rom()) import_rom(e.drop.file, g_rom_error);
        SDL_free(e.drop.file);
        return true;
    }
    if (!g_capture_button.empty() && capture(e)) return true;
    bool back = (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE && !e.key.repeat) ||
        (e.type == SDL_CONTROLLERBUTTONDOWN && (e.cbutton.button == SDL_CONTROLLER_BUTTON_BACK || e.cbutton.button == SDL_CONTROLLER_BUTTON_GUIDE));
    if (back) back_pressed();
    std::lock_guard lock{ g_mutex };
    ImGui::SetCurrentContext(g_ctx);
    ImGui_ImplSDL2_ProcessEvent(&e);
    feed_gamepad(e);
    return back;
}

void ui_frame() {
    g_input_blocked = ui_visible();
    if (!g_backend_ready || !g_window) return;
    static uint64_t last = 0;
    uint64_t now = SDL_GetTicks64();
    if (now - last < 16) return;
    last = now;

    // <prefix>UI=launcher|menu|settings[:Controls|Graphics|Netplay] opens that screen once the game
    // (or launcher) is up: for screenshots and checks without anyone at the keyboard.
    static std::string debug_screen = [] { const char* e = std::getenv((g_game.env_prefix + "UI").c_str()); return std::string(e ? e : ""); }();
    if (!debug_screen.empty() && (ultramodern::is_game_started() || g_screen == Screen::Launcher)) {
        std::string tab = debug_screen.find(':') != std::string::npos ? debug_screen.substr(debug_screen.find(':') + 1) : "";
        std::string screen = debug_screen.substr(0, debug_screen.find(':'));
        if (screen == "menu") show(Screen::Menu);
        else if (screen == "launcher") show(Screen::Launcher);
        else if (screen == "settings") { g_settings_back = g_screen == Screen::Launcher ? Screen::Launcher : Screen::Menu; show(Screen::Settings); g_open_tab = tab; }
        debug_screen.clear();
    }

    std::lock_guard lock{ g_mutex };
    ImGui::SetCurrentContext(g_ctx);
    if (!ui_visible()) { g_has_frame = false; return; }
#ifdef _WIN32
    if (g_api == Api::D3D12) ImGui_ImplDX12_NewFrame();
#endif
    if (g_api == Api::Vulkan) ImGui_ImplVulkan_NewFrame();
    // Metal starts its frame at draw time: it needs that present's render pass.
    ImGui_ImplSDL2_NewFrame();
    ImGui::GetIO().BackendFlags |= ImGuiBackendFlags_HasGamepad;
    update_scale();
    ImGui::NewFrame();

    // Dim the game behind the menu; the launcher gets a plain backdrop.
    ImVec2 size = ImGui::GetIO().DisplaySize;
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(0, 0), size, ultramodern::is_game_started() ? IM_COL32(0, 0, 0, 150) : IM_COL32(10, 12, 18, 255));

    switch (g_screen) {
    case Screen::Launcher: launcher(); break;
    case Screen::Connecting: connecting(); break;
    case Screen::Settings: settings(); break;
    case Screen::Menu: menu(); break;
    case Screen::Hidden: break;
    }
    ImGui::Render();
    g_has_frame = true;
}

} // namespace fe
