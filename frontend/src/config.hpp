// User configuration: <short_name>.json in the working directory, written with defaults on first
// run and again whenever the launcher or menu changes something.
#pragma once

#include <array>
#include <filesystem>
#include <string>

#include "frontend/frontend.hpp"

namespace fe {

struct PlayerConfig {
    // "auto": player N gets the next controller plugged in, and keeps it until it's unplugged
    //         (player 1 also gets the keyboard).
    // "controller": always controller `controller` (0-based connection order).
    // "keyboard": keyboard only. "none": port left empty.
    std::string device = "auto";
    int controller = -1;
};

struct Config {
    // Graphics (mapped onto RT64's user configuration).
    std::string resolution = "WindowIntegerScale"; // Original | WindowIntegerScale | Manual
    double resolutionMultiplier = 2.0;             // used when resolution = Manual
    std::string aspectRatio = "Original";          // Original | Expand (widescreen)
    std::string antialiasing = "MSAA4X";           // None | MSAA2X | MSAA4X | MSAA8X
    std::string filtering = "AntiAliasedPixelScaling"; // Nearest | Linear | AntiAliasedPixelScaling
    std::string refreshRate = "Original";          // Original (60 Hz) | Display
    bool fullscreen = false;
    int windowWidth = 1280;
    int windowHeight = 960;
    int display = 0;                               // monitor index
    bool texturePacks = true;                      // load texture-packs/*.rtz and folders
    bool developerMode = false;                    // RT64 inspector (F1): texture dumping, debug views

    // Sound
    double volume = 0.8;                           // 0 (muted) to 1

    // Netplay
    int netplayInputDelay = 2;                     // frames of input delay (more hides more latency)
    int netplayPort = 7777;                        // UDP port the host listens on
    std::string netplayAddress;                    // last address joined

    // Cheats enabled, by their name in cheats.cht
    std::vector<std::string> cheats;

    // Input
    double deadzone = 0.15;
    std::array<PlayerConfig, 4> players{};
    Bindings controllerBindings;
    Bindings keyboardBindings;
};

extern Config g_config;
extern GameInfo g_game;

// Loads `path`, filling anything missing with the game's defaults, and writes the merged result
// back so the file always lists every option.
void load_config(const std::filesystem::path& path);
void save_config();

} // namespace fe
