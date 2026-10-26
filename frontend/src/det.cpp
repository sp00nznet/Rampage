// Deterministic mode (netplay, or <prefix>DETERMINISTIC=1): N64ModernRuntime's ultramodern::det
// delivers retraces, timers and task completions at fixed points, so the same inputs give the same
// game. This file adds the game-side checks: <prefix>HASHLOG (a hash of game RAM per retrace) and
// <prefix>DUMPFRAME (a RAM dump at one retrace), to compare two runs or two machines.

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>

#include "ultramodern/ultramodern.hpp"
#include "config.hpp"
#include "internal.hpp"

namespace fe {
uint8_t* g_rdram = nullptr;
namespace {
FILE* g_hashlog = nullptr;
long long g_dump_frame = -1;
bool g_hash_blocks = false;
void (*g_next_callback)(uint64_t) = nullptr;

const char* env(const char* name) { return std::getenv((g_game.env_prefix + name).c_str()); }

// The runtime keeps a native pointer at OSThread+0x20 (its thread context), which differs per run;
// the game lists those words in GameInfo::det_mask_words.
bool masked(uint32_t offset) {
    for (uint32_t f : g_game.det_mask_words) if (offset == f || offset == f + 4) return true;
    return false;
}

void on_retrace(uint64_t retrace) {
    const uint8_t* rdram = g_rdram;
    if (rdram && g_hashlog) {
        std::fprintf(g_hashlog, "%llu %016llx", (unsigned long long)retrace, (unsigned long long)det_hash_game_ram());
        // <prefix>HASHBLOCKS=1: also one short hash per 64 KB block, to locate a divergence.
        if (g_hash_blocks) {
            for (uint32_t b = 0; b < g_game.det_ram_end; b += 0x10000) {
                uint32_t h = 2166136261u;
                for (uint32_t i = b; i < b + 0x10000; i += 4) {
                    if (!masked(i)) { h ^= *reinterpret_cast<const uint32_t*>(rdram + i); h *= 16777619u; }
                }
                std::fprintf(g_hashlog, " %08x", h);
            }
        }
        std::fputc('\n', g_hashlog);
        if ((retrace % 60) == 0) std::fflush(g_hashlog);
    }
    if (rdram && (long long)retrace == g_dump_frame) {
        std::string path = "ramdump_" + std::to_string(retrace) + ".bin";
        if (FILE* f = std::fopen(path.c_str(), "wb")) { std::fwrite(rdram, 1, 0x00800000, f); std::fclose(f); }
        std::fprintf(stderr, "[det] dumped RDRAM at retrace %llu to %s\n", (unsigned long long)retrace, path.c_str());
    }
    if (g_next_callback) g_next_callback(retrace);
}
} // namespace

void set_rdram(uint8_t* rdram) { g_rdram = rdram; }

// FNV-1a over game RAM, skipping the per-run fields.
uint64_t det_hash_game_ram() {
    const uint8_t* rdram = g_rdram;
    if (!rdram) return 0;
    uint64_t h = 1469598103934665603ULL;
    for (uint32_t i = 0; i < g_game.det_ram_end; i += 4) {
        if (masked(i)) continue;
        h ^= *reinterpret_cast<const uint32_t*>(rdram + i);
        h *= 1099511628211ULL;
    }
    return h;
}

bool det_enabled() { return ultramodern::det::enabled(); }
uint64_t det_frame() { return ultramodern::det::retrace_count(); }

// Turns on deterministic mode; `then` (netplay) runs after the checks at each retrace.
void det_start(void (*then)(uint64_t)) {
    if (const char* p = env("HASHLOG")) g_hashlog = std::fopen(p, "w");
    if (const char* e = env("DUMPFRAME")) g_dump_frame = std::atoll(e);
    g_hash_blocks = env("HASHBLOCKS") != nullptr;
    g_next_callback = then;
    ultramodern::det::enable();
    ultramodern::det::set_frame_callback(on_retrace);
}

} // namespace fe
