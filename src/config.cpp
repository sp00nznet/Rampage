#include "config.hpp"

#include <cstdio>
#include <fstream>

#include "json/json.hpp"

using json = nlohmann::ordered_json;

GameConfig g_config;

static std::map<std::string, std::vector<std::string>> default_controller_bindings() {
    return {
        { "A",      { "a", "+righttrigger" } },
        { "B",      { "x" } },
        { "Z",      { "+lefttrigger" } },
        { "L",      { "leftshoulder" } },
        { "R",      { "rightshoulder" } },
        { "Start",  { "start" } },
        { "DUp",    { "dpup" } },
        { "DDown",  { "dpdown" } },
        { "DLeft",  { "dpleft" } },
        { "DRight", { "dpright" } },
        { "CUp",    { "-righty", "y" } },
        { "CDown",  { "+righty", "b" } },
        { "CLeft",  { "-rightx" } },
        { "CRight", { "+rightx" } },
    };
}

static std::map<std::string, std::vector<std::string>> default_keyboard_bindings() {
    return {
        { "A",          { "Return", "Space" } },
        { "B",          { "Left Shift" } },
        { "Z",          { "Z" } },
        { "L",          { "Q" } },
        { "R",          { "E" } },
        { "Start",      { "Escape", "P" } },
        { "DUp",        { "I" } },
        { "DDown",      { "K" } },
        { "DLeft",      { "J" } },
        { "DRight",     { "L" } },
        { "CUp",        { "Keypad 8" } },
        { "CDown",      { "Keypad 2" } },
        { "CLeft",      { "Keypad 4" } },
        { "CRight",     { "Keypad 6" } },
        { "StickUp",    { "W", "Up" } },
        { "StickDown",  { "S", "Down" } },
        { "StickLeft",  { "A", "Left" } },
        { "StickRight", { "D", "Right" } },
    };
}

GameConfig load_config(const std::filesystem::path& path) {
    GameConfig c;
    c.controllerBindings = default_controller_bindings();
    c.keyboardBindings = default_keyboard_bindings();

    json j = json::object();
    if (std::ifstream f{ path }) {
        try {
            j = json::parse(f, nullptr, true, true);
        } catch (const std::exception& e) {
            fprintf(stderr, "[config] %s is not valid JSON (%s); using defaults\n", path.string().c_str(), e.what());
            j = json::object();
        }
    }

    auto read = [](const json& obj, const char* key, auto& out) {
        if (obj.is_object() && obj.contains(key)) {
            try { out = obj.at(key).get<std::decay_t<decltype(out)>>(); }
            catch (const std::exception&) { fprintf(stderr, "[config] ignoring bad value for '%s'\n", key); }
        }
    };

    const json g = j.value("graphics", json::object());
    read(g, "resolution", c.resolution);
    read(g, "resolutionMultiplier", c.resolutionMultiplier);
    read(g, "aspectRatio", c.aspectRatio);
    read(g, "antialiasing", c.antialiasing);
    read(g, "filtering", c.filtering);
    read(g, "refreshRate", c.refreshRate);
    read(g, "fullscreen", c.fullscreen);
    read(g, "windowWidth", c.windowWidth);
    read(g, "windowHeight", c.windowHeight);
    read(g, "display", c.display);
    read(g, "texturePacks", c.texturePacks);
    read(g, "developerMode", c.developerMode);

    const json in = j.value("input", json::object());
    read(in, "deadzone", c.deadzone);
    if (in.contains("players") && in["players"].is_array()) {
        for (size_t i = 0; i < c.players.size() && i < in["players"].size(); i++) {
            read(in["players"][i], "device", c.players[i].device);
            read(in["players"][i], "controller", c.players[i].controller);
        }
    }
    // Bindings merge per button, so a file that only overrides "A" keeps the other defaults.
    for (auto [key, map] : { std::pair{ "controllerBindings", &c.controllerBindings },
                             std::pair{ "keyboardBindings", &c.keyboardBindings } }) {
        if (in.contains(key) && in[key].is_object()) {
            for (auto& [button, list] : in[key].items()) {
                try { (*map)[button] = list.get<std::vector<std::string>>(); }
                catch (const std::exception&) { fprintf(stderr, "[config] ignoring bad binding '%s'\n", button.c_str()); }
            }
        }
    }

    // Write back the merged config so every option is visible and editable.
    json out;
    out["graphics"] = {
        { "resolution", c.resolution }, { "resolutionMultiplier", c.resolutionMultiplier },
        { "aspectRatio", c.aspectRatio }, { "antialiasing", c.antialiasing },
        { "filtering", c.filtering }, { "refreshRate", c.refreshRate },
        { "fullscreen", c.fullscreen }, { "windowWidth", c.windowWidth },
        { "windowHeight", c.windowHeight }, { "display", c.display },
        { "texturePacks", c.texturePacks }, { "developerMode", c.developerMode },
    };
    json players = json::array();
    for (auto& p : c.players) players.push_back({ { "device", p.device }, { "controller", p.controller } });
    out["input"] = {
        { "deadzone", c.deadzone }, { "players", players },
        { "controllerBindings", c.controllerBindings }, { "keyboardBindings", c.keyboardBindings },
    };
    if (std::ofstream f{ path }) {
        f << out.dump(4) << "\n";
    }
    return c;
}
