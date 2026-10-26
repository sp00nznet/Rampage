// Input: keyboard + SDL game controllers, mapped to the N64 controller ports per the config file.
//
// Players set to "auto" keep the controller they got: a controller plugged in goes to the lowest
// auto player without one, and unplugging it frees only that player's slot (nobody shifts up).

#include <SDL.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <string>
#include <vector>

#include "config.hpp"
#include "internal.hpp"

namespace fe {

std::atomic<bool> g_input_blocked = false;

namespace {

enum N64Button : uint16_t {
    BTN_A = 0x8000, BTN_B = 0x4000, BTN_Z = 0x2000, BTN_START = 0x1000,
    BTN_DUP = 0x0800, BTN_DDOWN = 0x0400, BTN_DLEFT = 0x0200, BTN_DRIGHT = 0x0100,
    BTN_L = 0x0020, BTN_R = 0x0010,
    BTN_CUP = 0x0008, BTN_CDOWN = 0x0004, BTN_CLEFT = 0x0002, BTN_CRIGHT = 0x0001,
};

const std::pair<const char*, uint16_t> kButtons[] = {
    { "A", BTN_A }, { "B", BTN_B }, { "Z", BTN_Z }, { "Start", BTN_START },
    { "DUp", BTN_DUP }, { "DDown", BTN_DDOWN }, { "DLeft", BTN_DLEFT }, { "DRight", BTN_DRIGHT },
    { "L", BTN_L }, { "R", BTN_R },
    { "CUp", BTN_CUP }, { "CDown", BTN_CDOWN }, { "CLeft", BTN_CLEFT }, { "CRight", BTN_CRIGHT },
};
const char* kStickNames[4] = { "StickUp", "StickDown", "StickLeft", "StickRight" };

// One controller input: a button, or an axis read in one direction ("+lefttrigger", "-righty").
struct PadInput {
    SDL_GameControllerButton button = SDL_CONTROLLER_BUTTON_INVALID;
    SDL_GameControllerAxis axis = SDL_CONTROLLER_AXIS_INVALID;
    int sign = 0;
};

struct Binding { uint16_t mask; std::vector<PadInput> pad; std::vector<SDL_Scancode> keys; };

struct Pad { SDL_GameController* gc; SDL_JoystickID id; };

enum class Mode { None, Auto, Controller, Keyboard };

// Everything below is guarded by g_mutex: SDL events and the menu change it on the main thread,
// the game reads it on its own threads.
std::mutex g_mutex;
std::vector<Binding> g_bindings;
std::vector<SDL_Scancode> g_stick_keys[4]; // up, down, left, right
std::vector<PadInput> g_stick_pad[4];
std::vector<Pad> g_pads;                   // in connection order
std::array<SDL_JoystickID, 4> g_slot{ -1, -1, -1, -1 }; // the pad each auto player holds
std::array<Mode, 4> g_mode{};
std::array<int, 4> g_index{ -1, -1, -1, -1 };           // Mode::Controller: index into g_pads
float g_deadzone = 0.15f;

// "a" / "leftshoulder" -> button; "+lefttrigger" / "-righty" -> axis direction.
bool parse_pad_input(const std::string& s, PadInput& in) {
    if (!s.empty() && (s[0] == '+' || s[0] == '-')) {
        in.sign = (s[0] == '+') ? 1 : -1;
        in.axis = SDL_GameControllerGetAxisFromString(s.c_str() + 1);
    } else {
        in.button = SDL_GameControllerGetButtonFromString(s.c_str());
    }
    if (in.axis == SDL_CONTROLLER_AXIS_INVALID && in.button == SDL_CONTROLLER_BUTTON_INVALID) {
        fprintf(stderr, "[input] unknown controller input '%s'\n", s.c_str());
        return false;
    }
    return true;
}

float axis(SDL_GameController* pad, SDL_GameControllerAxis a) {
    return std::clamp(SDL_GameControllerGetAxis(pad, a) / 32767.0f, -1.0f, 1.0f);
}

bool pad_held(SDL_GameController* pad, const PadInput& in) {
    if (in.button != SDL_CONTROLLER_BUTTON_INVALID) return SDL_GameControllerGetButton(pad, in.button) != 0;
    return axis(pad, in.axis) * in.sign > 0.5f;
}

std::vector<PadInput> pad_inputs(const char* name) {
    std::vector<PadInput> out;
    if (auto it = g_config.controllerBindings.find(name); it != g_config.controllerBindings.end()) {
        for (const std::string& s : it->second) { PadInput in; if (parse_pad_input(s, in)) out.push_back(in); }
    }
    return out;
}

std::vector<SDL_Scancode> key_inputs(const char* name) {
    std::vector<SDL_Scancode> out;
    if (auto it = g_config.keyboardBindings.find(name); it != g_config.keyboardBindings.end()) {
        for (const std::string& s : it->second) {
            SDL_Scancode sc = SDL_GetScancodeFromName(s.c_str());
            if (sc == SDL_SCANCODE_UNKNOWN) fprintf(stderr, "[input] unknown key '%s' for %s\n", s.c_str(), name);
            else out.push_back(sc);
        }
    }
    return out;
}

std::string pad_name(SDL_GameController* gc) {
    const char* n = SDL_GameControllerName(gc);
    return n ? n : "Controller";
}

bool pad_present(SDL_JoystickID id) {
    return std::any_of(g_pads.begin(), g_pads.end(), [&](const Pad& p) { return p.id == id; });
}

// Gives unclaimed pads to auto players without one. Call with g_mutex held.
void assign_pads() {
    for (int p = 0; p < 4; p++) {
        if (g_mode[p] != Mode::Auto || !pad_present(g_slot[p])) g_slot[p] = -1;
    }
    for (size_t i = 0; i < g_pads.size(); i++) {
        const Pad& pad = g_pads[i];
        bool taken = std::find(g_slot.begin(), g_slot.end(), pad.id) != g_slot.end();
        for (int p = 0; p < 4; p++) taken |= g_mode[p] == Mode::Controller && g_index[p] == (int)i;
        if (taken) continue;
        for (int p = 0; p < g_game.players; p++) {
            if (g_mode[p] == Mode::Auto && g_slot[p] == -1) {
                g_slot[p] = pad.id;
                printf("[input] player %d: %s\n", p + 1, SDL_GameControllerName(pad.gc));
                break;
            }
        }
    }
}

struct Source { SDL_GameController* pad = nullptr; bool keyboard = false; bool connected = false; };

// Which controller (if any) and whether the keyboard drive `port`. Call with g_mutex held.
Source source_for(int port) {
    Source s;
    switch (g_mode[port]) {
    case Mode::None: return s;
    case Mode::Keyboard: s.keyboard = true; break;
    case Mode::Controller:
        if (g_index[port] >= 0 && g_index[port] < (int)g_pads.size()) s.pad = g_pads[g_index[port]].gc;
        break;
    case Mode::Auto:
        for (const Pad& p : g_pads) if (p.id == g_slot[port]) s.pad = p.gc;
        s.keyboard = port == 0;
        break;
    }
    s.connected = s.pad != nullptr || s.keyboard;
    return s;
}

} // namespace

void input_rebuild() {
    std::lock_guard lock{ g_mutex };
    g_bindings.clear();
    for (auto& [name, mask] : kButtons) g_bindings.push_back({ mask, pad_inputs(name), key_inputs(name) });
    for (int i = 0; i < 4; i++) { g_stick_pad[i] = pad_inputs(kStickNames[i]); g_stick_keys[i] = key_inputs(kStickNames[i]); }
    for (int p = 0; p < 4; p++) {
        const PlayerConfig& pc = g_config.players[p];
        g_mode[p] = p >= g_game.players ? Mode::None
            : pc.device == "keyboard" ? Mode::Keyboard
            : pc.device == "controller" ? Mode::Controller
            : pc.device == "none" ? Mode::None : Mode::Auto;
        g_index[p] = pc.controller;
    }
    g_deadzone = (float)g_config.deadzone;
    assign_pads();
}

void input_init() { input_rebuild(); }

// Called from the SDL event loop (main thread).
void input_handle_event(const SDL_Event& e) {
    if (e.type == SDL_CONTROLLERDEVICEADDED) {
        if (SDL_GameController* gc = SDL_GameControllerOpen(e.cdevice.which)) {
            std::lock_guard lock{ g_mutex };
            SDL_JoystickID id = SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(gc));
            if (pad_present(id)) { SDL_GameControllerClose(gc); return; } // already open
            g_pads.push_back({ gc, id });
            printf("[input] controller %zu connected: %s\n", g_pads.size() - 1, SDL_GameControllerName(gc));
            assign_pads();
        }
    } else if (e.type == SDL_CONTROLLERDEVICEREMOVED) {
        std::lock_guard lock{ g_mutex };
        auto it = std::find_if(g_pads.begin(), g_pads.end(), [&](const Pad& p) { return p.id == e.cdevice.which; });
        if (it != g_pads.end()) {
            printf("[input] controller %td disconnected\n", it - g_pads.begin());
            SDL_GameControllerClose(it->gc);
            g_pads.erase(it);
            assign_pads();
        }
    }
}

bool input_get(int port, uint16_t* buttons, float* x, float* y) {
    *buttons = 0; *x = 0.0f; *y = 0.0f;
    if (port < 0 || port >= 4) return false;
    std::lock_guard lock{ g_mutex };
    Source s = source_for(port);
    if (!s.connected) return false;
    if (g_input_blocked) return true;

    const uint8_t* keys = s.keyboard ? SDL_GetKeyboardState(nullptr) : nullptr;
    for (const Binding& b : g_bindings) {
        bool down = false;
        if (keys) for (SDL_Scancode k : b.keys) down |= keys[k] != 0;
        if (s.pad) for (const PadInput& in : b.pad) down |= pad_held(s.pad, in);
        if (down) *buttons |= b.mask;
    }

    if (keys) {
        auto held = [&](int dir) { for (SDL_Scancode k : g_stick_keys[dir]) if (keys[k]) return true; return false; };
        *y += (held(0) ? 1.0f : 0.0f) - (held(1) ? 1.0f : 0.0f);
        *x += (held(3) ? 1.0f : 0.0f) - (held(2) ? 1.0f : 0.0f);
    }
    if (s.pad) {
        auto held = [&](int dir) { for (const PadInput& in : g_stick_pad[dir]) if (pad_held(s.pad, in)) return true; return false; };
        *y += (held(0) ? 1.0f : 0.0f) - (held(1) ? 1.0f : 0.0f);
        *x += (held(3) ? 1.0f : 0.0f) - (held(2) ? 1.0f : 0.0f);
        // Radial deadzone, rescaled so the stick still reaches full deflection.
        float sx = axis(s.pad, SDL_CONTROLLER_AXIS_LEFTX), sy = -axis(s.pad, SDL_CONTROLLER_AXIS_LEFTY);
        float mag = std::sqrt(sx * sx + sy * sy);
        if (mag > g_deadzone) {
            float scale = std::min(1.0f, (mag - g_deadzone) / (1.0f - g_deadzone)) / mag;
            *x += sx * scale;
            *y += sy * scale;
        }
    }
    *x = std::clamp(*x, -1.0f, 1.0f);
    *y = std::clamp(*y, -1.0f, 1.0f);
    return true;
}

// Player 1's local input, plus <prefix>AUTOPRESS="28:1000,31.5:8000": hold those N64 buttons for
// 0.25 s at each time (seconds since the first poll; frames/60 in deterministic mode), for
// scripted test runs. Netplay samples this once per retrace.
bool sample_local_input(uint16_t* buttons, float* x, float* y) {
    bool connected = input_get(0, buttons, x, y);
    static const std::vector<std::pair<double, uint16_t>> script = [] {
        std::vector<std::pair<double, uint16_t>> s;
        if (const char* e = std::getenv((g_game.env_prefix + "AUTOPRESS").c_str())) {
            for (const char* p = e; *p; ) {
                char* end;
                double t = strtod(p, &end);
                if (*end != ':') break;
                uint16_t b = (uint16_t)strtoul(end + 1, &end, 16);
                s.push_back({ t, b });
                p = (*end == ',') ? end + 1 : end;
            }
        }
        return s;
    }();
    if (script.empty()) return connected;
    static const uint64_t start_ticks = SDL_GetTicks64();
    double now = det_enabled() ? det_frame() / 60.0 : (SDL_GetTicks64() - start_ticks) / 1000.0;
    for (auto& [t, b] : script) {
        if (now >= t && now < t + 0.25) *buttons |= b;
    }
    return connected;
}

ultramodern::input::connected_device_info_t input_device_info(int port) {
    if (port >= 0 && port < 4) {
        std::lock_guard lock{ g_mutex };
        if (source_for(port).connected) return { ultramodern::input::Device::Controller, ultramodern::input::Pak::None };
    }
    return { ultramodern::input::Device::None, ultramodern::input::Pak::None };
}

void input_set_rumble(int port, bool on) {
    if (port < 0 || port >= 4) return;
    std::lock_guard lock{ g_mutex };
    if (SDL_GameController* pad = source_for(port).pad) {
        SDL_GameControllerRumble(pad, on ? 0xC000 : 0, on ? 0xC000 : 0, on ? 1000 : 0);
    }
}

std::string input_port_device_name(int port) {
    std::lock_guard lock{ g_mutex };
    Source s = source_for(port);
    std::string name = s.pad ? pad_name(s.pad) : "";
    if (s.keyboard) name = name.empty() ? "Keyboard" : name + " + keyboard";
    return name.empty() ? "Not connected" : name;
}

std::vector<std::string> input_controller_names() {
    std::lock_guard lock{ g_mutex };
    std::vector<std::string> out;
    for (const Pad& p : g_pads) out.push_back(pad_name(p.gc));
    return out;
}

} // namespace fe
