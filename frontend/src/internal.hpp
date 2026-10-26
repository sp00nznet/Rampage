// Shared between the frontend's files.
#pragma once

#include <atomic>
#include <cstdint>
#include <filesystem>
#include <string>
#include <vector>

#include <SDL.h>

#include "ultramodern/input.hpp"
#include "ultramodern/ultramodern.hpp"
#include "ultramodern/renderer_context.hpp"

namespace fe {

// app.cpp
SDL_Window* window();
bool headless();
const std::filesystem::path& base_dir();
bool find_rom();                      // stores a valid ROM if one is next to the exe; true if one is stored
bool import_rom(const std::filesystem::path& p, std::string& error);
void start_game();                    // from the launcher, or at once without it
void apply_window_config();           // fullscreen / monitor from g_config (main thread)
void quit();
std::string log_prefix();

// audio.cpp
ultramodern::audio_callbacks_t audio_callbacks();

// input.cpp
void input_init();
void input_rebuild();                 // after bindings or player devices change
void input_handle_event(const SDL_Event& e);
bool input_get(int port, uint16_t* buttons, float* x, float* y);
bool sample_local_input(uint16_t* buttons, float* x, float* y); // player 1 plus <prefix>AUTOPRESS
ultramodern::input::connected_device_info_t input_device_info(int port);
void input_set_rumble(int port, bool on);
std::string input_port_device_name(int port);   // what drives this port right now
std::vector<std::string> input_controller_names(); // connected, in connection order
extern std::atomic<bool> g_input_blocked;       // the menu is open: the game sees no buttons

// netplay.cpp
namespace net {
bool host(int port, const std::atomic<bool>& cancel);     // blocks until a player joins (or cancel/error)
bool join(const std::string& address, const std::atomic<bool>& cancel);
void begin();                         // after host/join: shared save folder + deterministic mode
bool active();
bool is_host();
int delay();
std::string status();                 // the last progress or error message
bool get_input(int port, uint16_t* buttons, float* x, float* y);
ultramodern::input::connected_device_info_t device_info(int port);
std::vector<std::string> local_addresses(); // IPv4 addresses to give the other player
}

// cheats.cpp
struct Cheat { std::string name, note; bool enabled; };
void cheats_load();                   // cheats.cht next to the exe; after load_config
std::vector<Cheat> cheats_list();
void cheats_set(const std::string& name, bool on); // also saves the config
void cheats_apply();                  // game thread, once per controller poll

// det.cpp
extern uint8_t* g_rdram;
void det_start(void (*then)(uint64_t));
uint64_t det_hash_game_ram();

// rt64_context.cpp
std::unique_ptr<ultramodern::renderer::RendererContext> create_render_context(
    uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode);
extern std::atomic<bool> g_graphics_dirty; // the menu changed graphics settings; applied at the next present

// ui.cpp
void ui_init();                       // before RT64 starts (installs its render hooks)
void ui_attach_window(SDL_Window* w);
bool ui_handle_event(const SDL_Event& e); // true if the UI used the event
void ui_frame();                      // main thread, every loop; builds the UI at ~60 Hz
void ui_show_launcher();
bool ui_visible();

} // namespace fe
