// The frontend shared by our N64 recomps: config file, controllers and keyboard, the RT64 renderer,
// the window, a launcher and an in-game menu (Esc or the controller's Back button), and 2-player
// netplay. A game describes itself with GameInfo and hands its recomp::Configuration to fe::run.
#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "librecomp/game.hpp"

namespace fe {

// N64 button name ("A", "Start", "CUp", "StickLeft", ...) -> inputs. Controller inputs use SDL names
// ("a", "leftshoulder", "+lefttrigger", "-righty"); keys use SDL key names ("Return", "Left Shift").
using Bindings = std::map<std::string, std::vector<std::string>>;

struct GameInfo {
    std::string title;                  // window and launcher title
    std::u8string game_id;              // the recomp::GameEntry's game_id
    std::string short_name;             // config file is <short_name>.json; log prefix
    std::vector<std::string> rom_names; // looked for next to the exe and in the working directory
    int players = 4;                    // controller ports the game reads
    std::string env_prefix;             // debug switches: <prefix>HEADLESS, DISPLAY, AUTOPRESS, DETERMINISTIC, HASHLOG, ...
    Bindings controller_bindings;       // defaults (empty: default_controller_bindings())
    Bindings keyboard_bindings;         // defaults (empty: default_keyboard_bindings())

    // Most sound the game is told is still queued, in video frames (audio.cpp). Games that mix
    // "a frame minus what's queued" go negative if this is more than they could see on hardware.
    double audio_max_queued_frames = 2;

    // Netplay: 2-player lockstep, which needs the runtime's deterministic mode to hold for this game.
    bool netplay = false;
    std::vector<uint32_t> det_mask_words; // RDRAM offsets holding per-run native pointers (OSThread+0x20)
    uint32_t det_ram_end = 0x400000;      // the desync hash covers RDRAM below this
};

Bindings default_controller_bindings();
Bindings default_keyboard_bindings();

// Fills cfg's renderer, audio, input, gfx, gfx-init and error-box callbacks (the game sets rsp,
// threads and vi_callback), then runs the game. Shows the launcher unless started with --headless,
// --play, --host [port] or --join address[:port]. Returns when the program exits.
int run(const GameInfo& game, recomp::Configuration& cfg, int argc, char** argv);

// Call from the GameEntry's on_init_callback: netplay's desync check reads RDRAM.
void set_rdram(uint8_t* rdram);

// Deterministic mode (netplay, or <prefix>DETERMINISTIC=1).
bool det_enabled();
uint64_t det_frame();

} // namespace fe
