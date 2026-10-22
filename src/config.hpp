// User configuration: rampage.json next to the executable, written with defaults on first run.
#pragma once

#include <array>
#include <filesystem>
#include <map>
#include <string>
#include <vector>

struct PlayerConfig {
    // "auto": player N takes the Nth connected controller (player 1 also gets the keyboard).
    // "controller": always controller `controller` (0-based connection order).
    // "keyboard": keyboard only. "none": port left empty.
    std::string device = "auto";
    int controller = -1;
};

struct GameConfig {
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

    // Input
    double deadzone = 0.15;
    std::array<PlayerConfig, 4> players{};
    // N64 button name -> list of inputs. Controller inputs use SDL names ("a", "leftshoulder",
    // "+lefttrigger", "-righty"); keyboard inputs use SDL key names ("Return", "Left Shift").
    std::map<std::string, std::vector<std::string>> controllerBindings;
    std::map<std::string, std::vector<std::string>> keyboardBindings;
};

// Loads `path`, filling anything missing with defaults, and writes the merged result back so the
// file always lists every option.
GameConfig load_config(const std::filesystem::path& path);

extern GameConfig g_config;
