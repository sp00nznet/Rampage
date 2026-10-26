#include "config.hpp"

#include <cstdio>
#include <fstream>

#include "json/json.hpp"

using json = nlohmann::ordered_json;

namespace fe {

Config g_config;
GameInfo g_game;
static std::filesystem::path g_path;

Bindings default_controller_bindings() {
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

Bindings default_keyboard_bindings() {
    return {
        { "A",          { "Return", "Space" } },
        { "B",          { "Left Shift" } },
        { "Z",          { "Z" } },
        { "L",          { "Q" } },
        { "R",          { "E" } },
        { "Start",      { "P", "Backspace" } }, // Escape opens the menu
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

void load_config(const std::filesystem::path& path) {
    g_path = path;
    Config& c = g_config;
    c = Config{};
    c.controllerBindings = g_game.controller_bindings.empty() ? default_controller_bindings() : g_game.controller_bindings;
    c.keyboardBindings = g_game.keyboard_bindings.empty() ? default_keyboard_bindings() : g_game.keyboard_bindings;

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

    const json au = j.value("audio", json::object());
    read(au, "volume", c.volume);

    const json np = j.value("netplay", json::object());
    read(np, "inputDelay", c.netplayInputDelay);
    read(np, "port", c.netplayPort);
    read(np, "address", c.netplayAddress);

    read(j, "cheats", c.cheats);

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

    // Escape belongs to the menu now (older files bound it to Start).
    for (auto& [button, keys] : c.keyboardBindings) std::erase(keys, std::string("Escape"));

    // Write back the merged config so every option is visible and editable.
    save_config();
}

void save_config() {
    const Config& c = g_config;
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
    out["audio"] = { { "volume", c.volume } };
    out["netplay"] = { { "inputDelay", c.netplayInputDelay }, { "port", c.netplayPort }, { "address", c.netplayAddress } };
    out["cheats"] = c.cheats;
    if (std::ofstream f{ g_path }) {
        f << out.dump(4) << "\n";
    }
}

} // namespace fe
