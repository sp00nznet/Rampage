// GameShark-style cheats. Codes come from cheats.cht next to the exe, in Project64's .cht format
// (the format most N64 code lists use):
//
//     $Infinite Truguts
//     Note=optional description
//     81113E7A FFFF
//
// Enabled cheats are listed by name in the config file and applied once per frame, on the game
// thread, when the game polls the controllers (like the real GameShark, which rewrote RAM every
// frame). Netplay ignores them: one player's codes would make the two games diverge.
//
// Code types: 80/A0 write byte, 81/A1 write halfword, D0/D1 only if byte/halfword equals,
// D2/D3 only if not equal, F0/F1 write (meant for boot, harmless every frame), 50 repeat the next
// code. Codes with "?" (pick-a-value options) are skipped.

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <mutex>
#include <set>

#include "config.hpp"
#include "internal.hpp"

namespace fe {
namespace {

struct Line { uint32_t code; uint16_t value; };
std::vector<Cheat> g_cheats;
std::vector<std::vector<Line>> g_lines; // parallel to g_cheats
std::mutex g_mutex;                      // the menu toggles while the game thread applies

// RDRAM is stored a word at a time in host order, so byte address a lives at a ^ 3.
void write8(uint8_t* ram, uint32_t a, uint8_t v) { ram[(a & 0x7FFFFF) ^ 3] = v; }
uint8_t read8(const uint8_t* ram, uint32_t a) { return ram[(a & 0x7FFFFF) ^ 3]; }
void write16(uint8_t* ram, uint32_t a, uint16_t v) { write8(ram, a, v >> 8); write8(ram, a + 1, v & 0xFF); }
uint16_t read16(const uint8_t* ram, uint32_t a) { return (read8(ram, a) << 8) | read8(ram, a + 1); }

void run(uint8_t* ram, const std::vector<Line>& lines) {
    for (size_t i = 0; i < lines.size(); i++) {
        uint32_t a = lines[i].code & 0xFFFFFF;
        uint16_t v = lines[i].value;
        switch (lines[i].code >> 24) {
        case 0x80: case 0xA0: case 0xF0: write8(ram, a, v & 0xFF); break;
        case 0x81: case 0xA1: case 0xF1: write16(ram, a, v); break;
        case 0xD0: if (read8(ram, a) != (v & 0xFF)) i++; break;
        case 0xD1: if (read16(ram, a) != v) i++; break;
        case 0xD2: if (read8(ram, a) == (v & 0xFF)) i++; break;
        case 0xD3: if (read16(ram, a) == v) i++; break;
        case 0x50:
            if (i + 1 < lines.size()) {
                uint32_t count = (lines[i].code >> 8) & 0xFF, step = lines[i].code & 0xFF;
                uint32_t to = lines[i + 1].code; uint16_t val = lines[i + 1].value;
                for (uint32_t n = 0; n < count; n++, to += step, val += v) {
                    if ((to >> 24) == 0x80) write8(ram, to & 0xFFFFFF, val & 0xFF);
                    else if ((to >> 24) == 0x81) write16(ram, to & 0xFFFFFF, val);
                }
                i++;
            }
            break;
        }
    }
}

} // namespace

void cheats_load() {
    std::lock_guard lock(g_mutex);
    g_cheats.clear(); g_lines.clear();
    std::ifstream f{ base_dir() / "cheats.cht" };
    std::string s;
    while (std::getline(f, s)) {
        if (!s.empty() && s.back() == '\r') s.pop_back();
        if (s.starts_with("$")) {
            g_cheats.push_back({ s.substr(1), "", false });
            g_lines.emplace_back();
        } else if (s.starts_with("Note=") && !g_cheats.empty()) {
            g_cheats.back().note = s.substr(5);
        } else if (!g_cheats.empty() && s.find('?') == std::string::npos) {
            unsigned code, value;
            if (std::sscanf(s.c_str(), "%8x %4x", &code, &value) == 2) g_lines.back().push_back({ code, (uint16_t)value });
        }
    }
    for (auto& c : g_cheats) c.enabled = std::count(g_config.cheats.begin(), g_config.cheats.end(), c.name) > 0;
    if (!g_cheats.empty()) printf("[cheats] %zu codes in cheats.cht\n", g_cheats.size());
}

std::vector<Cheat> cheats_list() {
    std::lock_guard lock(g_mutex);
    return g_cheats;
}

void cheats_set(const std::string& name, bool on) {
    {
        std::lock_guard lock(g_mutex);
        for (auto& c : g_cheats) if (c.name == name) c.enabled = on;
    }
    std::erase(g_config.cheats, name);
    if (on) g_config.cheats.push_back(name);
    save_config();
}

void cheats_apply() {
    if (det_enabled() || !g_rdram) return;
    std::lock_guard lock(g_mutex);
    for (size_t i = 0; i < g_cheats.size(); i++) if (g_cheats[i].enabled) run(g_rdram, g_lines[i]);
}

} // namespace fe
