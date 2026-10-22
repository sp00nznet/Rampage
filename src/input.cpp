// Input: keyboard + up to 4 SDL game controllers, mapped to the 4 N64 controller ports per
// rampage.json (see config.hpp).

#include <SDL.h>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <mutex>
#include <string>
#include <vector>

#include "config.hpp"
#include "ultramodern/input.hpp"

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

// One controller input: a button, or an axis read in one direction ("+lefttrigger", "-righty").
struct PadInput {
    SDL_GameControllerButton button = SDL_CONTROLLER_BUTTON_INVALID;
    SDL_GameControllerAxis axis = SDL_CONTROLLER_AXIS_INVALID;
    int sign = 0;
};

struct Binding { uint16_t mask; std::vector<PadInput> pad; std::vector<SDL_Scancode> keys; };

std::vector<Binding> g_bindings;
std::vector<SDL_Scancode> g_stick_keys[4]; // up, down, left, right
std::mutex g_pads_mutex;
std::vector<SDL_GameController*> g_pads; // in connection order

void build_bindings() {
    for (auto& [name, mask] : kButtons) {
        Binding b{ mask };
        if (auto it = g_config.controllerBindings.find(name); it != g_config.controllerBindings.end()) {
            for (const std::string& s : it->second) {
                PadInput in;
                if (!s.empty() && (s[0] == '+' || s[0] == '-')) {
                    in.sign = (s[0] == '+') ? 1 : -1;
                    in.axis = SDL_GameControllerGetAxisFromString(s.c_str() + 1);
                } else {
                    in.button = SDL_GameControllerGetButtonFromString(s.c_str());
                }
                if (in.axis == SDL_CONTROLLER_AXIS_INVALID && in.button == SDL_CONTROLLER_BUTTON_INVALID) {
                    fprintf(stderr, "[input] unknown controller input '%s' for %s\n", s.c_str(), name);
                } else {
                    b.pad.push_back(in);
                }
            }
        }
        if (auto it = g_config.keyboardBindings.find(name); it != g_config.keyboardBindings.end()) {
            for (const std::string& s : it->second) {
                SDL_Scancode sc = SDL_GetScancodeFromName(s.c_str());
                if (sc == SDL_SCANCODE_UNKNOWN) fprintf(stderr, "[input] unknown key '%s' for %s\n", s.c_str(), name);
                else b.keys.push_back(sc);
            }
        }
        g_bindings.push_back(std::move(b));
    }
    const char* stick_names[4] = { "StickUp", "StickDown", "StickLeft", "StickRight" };
    for (int i = 0; i < 4; i++) {
        if (auto it = g_config.keyboardBindings.find(stick_names[i]); it != g_config.keyboardBindings.end()) {
            for (const std::string& s : it->second) {
                SDL_Scancode sc = SDL_GetScancodeFromName(s.c_str());
                if (sc != SDL_SCANCODE_UNKNOWN) g_stick_keys[i].push_back(sc);
            }
        }
    }
}

// Which controller (if any) and whether the keyboard drive N64 port `port`.
struct Source { SDL_GameController* pad = nullptr; bool keyboard = false; bool connected = false; };

Source source_for(int port) {
    const PlayerConfig& p = g_config.players[port];
    Source s;
    if (p.device == "none") return s;
    if (p.device == "keyboard") { s.keyboard = s.connected = true; return s; }
    int index = (p.device == "controller" && p.controller >= 0) ? p.controller : port;
    std::lock_guard lock{ g_pads_mutex };
    if (index < (int)g_pads.size()) s.pad = g_pads[index];
    s.keyboard = (p.device == "auto" && port == 0);
    s.connected = s.pad != nullptr || s.keyboard;
    return s;
}

float axis(SDL_GameController* pad, SDL_GameControllerAxis a) {
    return std::clamp(SDL_GameControllerGetAxis(pad, a) / 32767.0f, -1.0f, 1.0f);
}

} // namespace

void input_init() {
    build_bindings();
}

// Called from the SDL event loop.
void input_handle_event(const SDL_Event& e) {
    if (e.type == SDL_CONTROLLERDEVICEADDED) {
        if (SDL_GameController* pad = SDL_GameControllerOpen(e.cdevice.which)) {
            std::lock_guard lock{ g_pads_mutex };
            g_pads.push_back(pad);
            printf("[input] controller %zu connected: %s\n", g_pads.size() - 1, SDL_GameControllerName(pad));
        }
    } else if (e.type == SDL_CONTROLLERDEVICEREMOVED) {
        std::lock_guard lock{ g_pads_mutex };
        auto it = std::find_if(g_pads.begin(), g_pads.end(), [&](SDL_GameController* p) {
            return SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(p)) == e.cdevice.which;
        });
        if (it != g_pads.end()) {
            printf("[input] controller %td disconnected\n", it - g_pads.begin());
            SDL_GameControllerClose(*it);
            g_pads.erase(it);
        }
    }
}

bool input_get(int port, uint16_t* buttons, float* x, float* y) {
    *buttons = 0; *x = 0.0f; *y = 0.0f;
    if (port < 0 || port >= 4) return false;
    Source s = source_for(port);
    if (!s.connected) return false;

    const uint8_t* keys = s.keyboard ? SDL_GetKeyboardState(nullptr) : nullptr;
    for (const Binding& b : g_bindings) {
        bool down = false;
        if (keys) for (SDL_Scancode k : b.keys) down |= keys[k] != 0;
        if (s.pad) for (const PadInput& in : b.pad) {
            if (in.button != SDL_CONTROLLER_BUTTON_INVALID) down |= SDL_GameControllerGetButton(s.pad, in.button) != 0;
            else down |= axis(s.pad, in.axis) * in.sign > 0.5f;
        }
        if (down) *buttons |= b.mask;
    }

    if (keys) {
        auto held = [&](int dir) { for (SDL_Scancode k : g_stick_keys[dir]) if (keys[k]) return true; return false; };
        *y += (held(0) ? 1.0f : 0.0f) - (held(1) ? 1.0f : 0.0f);
        *x += (held(3) ? 1.0f : 0.0f) - (held(2) ? 1.0f : 0.0f);
    }
    if (s.pad) {
        // Radial deadzone, rescaled so the stick still reaches full deflection.
        float sx = axis(s.pad, SDL_CONTROLLER_AXIS_LEFTX), sy = -axis(s.pad, SDL_CONTROLLER_AXIS_LEFTY);
        float mag = std::sqrt(sx * sx + sy * sy);
        if (mag > (float)g_config.deadzone) {
            float dz = (float)g_config.deadzone;
            float scale = std::min(1.0f, (mag - dz) / (1.0f - dz)) / mag;
            *x += sx * scale;
            *y += sy * scale;
        }
    }
    *x = std::clamp(*x, -1.0f, 1.0f);
    *y = std::clamp(*y, -1.0f, 1.0f);
    return true;
}

ultramodern::input::connected_device_info_t input_device_info(int port) {
    if (port >= 0 && port < 4 && source_for(port).connected) {
        return { ultramodern::input::Device::Controller, ultramodern::input::Pak::None };
    }
    return { ultramodern::input::Device::None, ultramodern::input::Pak::None };
}

void input_set_rumble(int port, bool on) {
    if (port < 0 || port >= 4) return;
    if (SDL_GameController* pad = source_for(port).pad) {
        SDL_GameControllerRumble(pad, on ? 0xC000 : 0, on ? 0xC000 : 0, on ? 1000 : 0);
    }
}
