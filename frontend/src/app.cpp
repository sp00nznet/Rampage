// The window, the event loop, how the game starts, and the callbacks fe::run hands librecomp.

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include <SDL.h>
#ifndef __linux__
#include <SDL_syswm.h> // on Linux it brings X11's macros (None) into the runtime's headers
#endif

#include <algorithm>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#ifdef __ANDROID__
#include <unistd.h>
#endif
#include <fstream>
#include <string>
#include <vector>

#include "librecomp/game.hpp"
#include "ultramodern/ultramodern.hpp"
#include "ultramodern/error_handling.hpp"
#include "ultramodern/events.hpp"
#include "config.hpp"
#include "internal.hpp"

namespace fe {
namespace {

SDL_Window* g_window = nullptr;
bool g_headless = false;
bool g_launcher = true;
std::filesystem::path g_base;
int g_window_display = -1;

const char* env(const char* name) { return std::getenv((g_game.env_prefix + name).c_str()); }

ultramodern::gfx_callbacks_t::gfx_data_t create_gfx() {
    SDL_SetHint(SDL_HINT_WINDOWS_DPI_AWARENESS, "permonitorv2");
    SDL_SetHint(SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS, "0");
    // Android: landscape either way up (SDL otherwise lets a resizable window turn portrait).
    SDL_SetHint(SDL_HINT_ORIENTATIONS, "LandscapeLeft LandscapeRight");
    // Keep reading controllers when the window isn't focused (remote desktop, a second monitor).
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "Failed to initialize SDL2: %s\n", SDL_GetError());
        std::exit(1);
    }
    return nullptr;
}

ultramodern::renderer::WindowHandle create_window(ultramodern::gfx_callbacks_t::gfx_data_t) {
    // <prefix>DISPLAY=<n> overrides the configured monitor.
    const char* d = env("DISPLAY");
    g_window_display = d ? std::atoi(d) : g_config.display;
    Uint32 flags = SDL_WINDOW_RESIZABLE | (g_config.fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    int x = SDL_WINDOWPOS_CENTERED_DISPLAY(g_window_display), y = x;
    if (g_headless) {
#ifdef _WIN32
        // Shown (so the compositor keeps drawing it and screenshots of it work) but placed past the
        // right edge of every monitor, with no taskbar button and never activated.
        flags = SDL_WINDOW_SKIP_TASKBAR | SDL_WINDOW_BORDERLESS;
        SDL_SetHint(SDL_HINT_WINDOW_NO_ACTIVATION_WHEN_SHOWN, "1");
        x = 0;
        for (int i = 0; i < SDL_GetNumVideoDisplays(); i++) {
            SDL_Rect r;
            if (SDL_GetDisplayBounds(i, &r) == 0) x = std::max(x, r.x + r.w);
        }
        x += 100;
        y = 0;
#else
        flags = SDL_WINDOW_HIDDEN;
#endif
    }
#if defined(__APPLE__)
    flags |= SDL_WINDOW_METAL; // RT64 draws into a Metal view on it (create_window)
#elif defined(__ANDROID__)
    flags |= SDL_WINDOW_VULKAN; // else SDL puts an OpenGL ES surface on it, and RT64's swap chain can't
#endif
    g_window = SDL_CreateWindow(g_game.title.c_str(), x, y, g_config.windowWidth, g_config.windowHeight, flags);
    if (!g_window) {
        fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
        std::exit(1);
    }
    ui_attach_window(g_window);

#ifndef __linux__
    SDL_SysWMinfo wminfo;
    SDL_VERSION(&wminfo.version);
    SDL_GetWindowWMInfo(g_window, &wminfo);
#endif
#if defined(_WIN32)
    ultramodern::renderer::WindowHandle handle{};
    handle.window = wminfo.info.win.window;
    handle.thread_id = GetCurrentThreadId();
    return handle;
#elif defined(__APPLE__)
    SDL_MetalView view = SDL_Metal_CreateView(g_window);
    return { wminfo.info.cocoa.window, SDL_Metal_GetLayer(view) };
#else
    return g_window; // rt64_context.cpp takes the X11 display and window from it
#endif
}

void update_gfx(ultramodern::gfx_callbacks_t::gfx_data_t) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        input_handle_event(e);
        if (e.type == SDL_QUIT) { quit(); continue; }
        if (ui_handle_event(e)) continue;
        if (e.type == SDL_KEYDOWN) {
            // F11 or Alt+Enter toggles borderless fullscreen.
            const SDL_Keysym& k = e.key.keysym;
            if (k.sym == SDLK_F11 || (k.sym == SDLK_RETURN && (k.mod & KMOD_ALT))) {
                g_config.fullscreen = !g_config.fullscreen;
                apply_window_config();
                save_config();
            }
        }
    }
    ui_frame();
}

void poll_input() { cheats_apply(); } // once per frame on the game thread; SDL events are handled in update_gfx

bool get_input(int port, uint16_t* buttons, float* x, float* y) {
    if (net::active()) return net::get_input(port, buttons, x, y); // both players, sampled per retrace
    if (port == 0) return sample_local_input(buttons, x, y);
    return input_get(port, buttons, x, y);
}

ultramodern::input::connected_device_info_t get_connected_device_info(int port) {
    if (net::active()) return net::device_info(port);
    return input_device_info(port);
}

void gfx_init_callback() {
    // The renderer and VI thread are up, so the game (or the launcher) can start.
    if (g_launcher) ui_show_launcher();
    else start_game();
}

void error_message_box(const char* msg) {
    fprintf(stderr, "[%s ERROR] %s\n", g_game.short_name.c_str(), msg);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, g_game.title.c_str(), msg, g_window);
}

std::filesystem::path exe_dir() {
    char* p = SDL_GetBasePath();
    if (!p) return std::filesystem::current_path();
    std::filesystem::path dir = std::filesystem::u8path(p);
    SDL_free(p);
    return dir;
}

} // namespace

SDL_Window* window() { return g_window; }
bool headless() { return g_headless; }
const std::filesystem::path& base_dir() { return g_base; }
std::string log_prefix() { return "[" + g_game.short_name + "]"; }
void quit() { ultramodern::quit(); }

bool import_rom(const std::filesystem::path& p, std::string& error) {
    switch (recomp::select_rom(p, g_game.game_id)) {
    case recomp::RomValidationError::Good:
        // select_rom stores the ROM but only marks it valid on the next start: do that now, or the
        // launcher asks for it again on the first run.
        recomp::check_all_stored_roms();
        error.clear(); printf("%s using ROM %s\n", log_prefix().c_str(), p.string().c_str()); return true;
    case recomp::RomValidationError::FailedToOpen: error = "Couldn't open that file."; break;
    case recomp::RomValidationError::NotARom: error = "That file isn't an N64 ROM."; break;
    case recomp::RomValidationError::IncorrectRom: error = "That's a different game's ROM."; break;
    case recomp::RomValidationError::IncorrectVersion: error = "That's a different version of the game; this needs the USA release."; break;
    default: error = "That ROM can't be used."; break;
    }
    return false;
}

// librecomp keeps a validated copy of the ROM; failing that, look for one next to the exe.
bool find_rom() {
    if (recomp::is_rom_valid(g_game.game_id)) return true;
    static bool searched = false; // ponytail: looks once; the launcher's drop/path box handles the rest
    if (searched) return false;
    searched = true;
    for (const std::filesystem::path& dir : { exe_dir(), std::filesystem::current_path() }) {
        for (const std::string& name : g_game.rom_names) {
            std::string error;
            if (std::filesystem::exists(dir / name) && import_rom(dir / name, error)) return true;
        }
    }
    return false;
}

void start_game() {
    if (!find_rom()) {
        std::string msg = "Couldn't find the ROM. Put your copy of " + g_game.title + " (USA) next to the program" +
            (g_game.rom_names.empty() ? std::string(".") : ", named \"" + g_game.rom_names[0] + "\".");
        ultramodern::error_handling::message_box(msg.c_str());
        quit();
        return;
    }
    recomp::start_game(g_game.game_id, "");
    printf("%s game started\n", log_prefix().c_str());
}

void apply_window_config() {
    if (!g_window || g_headless) return;
    bool full = (SDL_GetWindowFlags(g_window) & SDL_WINDOW_FULLSCREEN_DESKTOP) != 0;
    if (g_config.display != g_window_display) {
        g_window_display = g_config.display;
        if (full) SDL_SetWindowFullscreen(g_window, 0);
        SDL_SetWindowPosition(g_window, SDL_WINDOWPOS_CENTERED_DISPLAY(g_window_display), SDL_WINDOWPOS_CENTERED_DISPLAY(g_window_display));
        full = false;
    }
    if (full != g_config.fullscreen) SDL_SetWindowFullscreen(g_window, g_config.fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
}

int run(const GameInfo& game, recomp::Configuration& cfg, int argc, char** argv) {
    g_game = game;
    g_base = std::filesystem::current_path();
#ifdef __ANDROID__
    // No writable working folder on Android: use the app's internal storage, and on the first run
    // take out the ROM that scripts/build_android.sh packed into the APK's assets.
    g_base = SDL_AndroidGetInternalStoragePath();
    std::filesystem::current_path(g_base);
    setenv("HOME", g_base.c_str(), 1); // RT64 keeps its data in $HOME, which Android doesn't set
    // stdout and stderr go nowhere on Android: keep them in Android/data/<app>/files/<short_name>.log,
    // where a file manager or adb can read them.
    if (const char* ext = SDL_AndroidGetExternalStoragePath()) freopen((std::string(ext) + "/" + g_game.short_name + ".log").c_str(), "w", stdout);
    dup2(fileno(stdout), fileno(stderr));
    setvbuf(stdout, nullptr, _IONBF, 0);
    if (!std::filesystem::exists("baserom.z64")) {
        if (SDL_RWops* in = SDL_RWFromFile("baserom.z64", "rb")) {
            std::vector<char> rom((size_t)SDL_RWsize(in));
            SDL_RWread(in, rom.data(), 1, rom.size());
            SDL_RWclose(in);
            std::ofstream("baserom.z64", std::ios::binary).write(rom.data(), rom.size());
        }
    }
#endif

    std::string host_port, join_address;
    bool host = false;
    for (int i = 1; i < argc; i++) {
        std::string a = argv[i];
        if (a == "--headless") g_headless = true;
        else if (a == "--play") g_launcher = false;
        else if (a == "--host") { host = true; if (i + 1 < argc && argv[i + 1][0] != '-') host_port = argv[++i]; }
        else if (a == "--join" && i + 1 < argc) join_address = argv[++i];
    }
    if (const char* h = env("HEADLESS"); h && *h == '1') g_headless = true;
    if (g_headless || host || !join_address.empty()) g_launcher = false;

    load_config(g_base / (g_game.short_name + ".json"));
    cheats_load();
    input_init();
    ui_init();
    recomp::register_config_path(g_base);

    // --host / --join from the command line: connect now, in the console.
    if ((host || !join_address.empty()) && g_game.netplay) {
        std::atomic<bool> never = false;
        bool ok = host ? net::host(host_port.empty() ? g_config.netplayPort : std::stoi(host_port), never)
                       : net::join(join_address, never);
        if (!ok) { fprintf(stderr, "[netplay] %s\n", net::status().c_str()); return 1; }
        net::begin();
    } else if (const char* d = env("DETERMINISTIC"); d && *d == '1') {
        det_start(nullptr);
        printf("%s deterministic mode\n", log_prefix().c_str());
    }

    cfg.renderer_callbacks.create_render_context = create_render_context;
    cfg.audio_callbacks = audio_callbacks();
    cfg.input_callbacks.poll_input = poll_input;
    cfg.input_callbacks.get_input = get_input;
    cfg.input_callbacks.set_rumble = input_set_rumble;
    cfg.input_callbacks.get_connected_device_info = get_connected_device_info;
    cfg.gfx_callbacks.create_gfx = create_gfx;
    cfg.gfx_callbacks.create_window = create_window;
    cfg.gfx_callbacks.update_gfx = update_gfx;
    cfg.events_callbacks.gfx_init_callback = gfx_init_callback;
    cfg.error_handling_callbacks.message_box = error_message_box;

    recomp::start(cfg); // returns when the program exits

    if (g_window) SDL_DestroyWindow(g_window);
    SDL_Quit();
    // The game's own threads are never joined and may still be running: end here, before static
    // destructors pull globals out from under them (a crash at exit on Linux and macOS). Saves,
    // config and RT64 are already shut down.
    printf("%s shutdown complete\n", log_prefix().c_str());
    fflush(nullptr);
    std::_Exit(0);
}

} // namespace fe
