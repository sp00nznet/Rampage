// Rampage Recompiled - entry point.
//
// One source tree builds either game: RAMPAGE_R2 selects Rampage 2: Universal Tour, otherwise
// Rampage: World Tour. Each build links that game's generated code (gen/wt or gen/r2), made
// locally from the player's ROM by tools/regen.py. The window, launcher, input, sound and config
// come from the shared frontend (frontend/, the same as sp00nznet's Racer port).

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <dbghelp.h>
#include <tlhelp32.h>
#include <SDL.h>
#include <SDL_syswm.h>
#endif

#include "recomp.h"
#include "librecomp/game.hpp"
#include "librecomp/overlays.hpp"
#include "librecomp/rsp.hpp"
#include "ultramodern/ultramodern.hpp"
#include "ultramodern/threads.hpp"
#include "frontend/frontend.hpp"

#ifdef _WIN32
namespace fe { SDL_Window* window(); }
#endif

// overlays.cpp (wraps the generated recomp_overlays.inl)
void register_rampage_overlays();

// Generated: lookup.cpp and the recompiled entrypoint.
gpr get_entrypoint_address();
extern "C" void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx);

// libultra's audio microcode, recompiled from the ROM by RSPRecomp (rsp/aspMain_<game>.toml)
extern RspUcodeFunc aspMain;

// =============================================================================
// The game this build runs
// =============================================================================
struct RampageGame {
    uint64_t rom_hash;          // XXH3_64bits of the decompressed .z64
    const char* internal_name;  // ROM header name
    const char* title;
    const char8_t* game_id;
    const char* short_name;     // config file, log prefix
    std::vector<std::string> rom_names; // looked for next to the exe and in the working directory
};

#ifdef RAMPAGE_R2
static const RampageGame kGame = { 0x61d6fbc04d8ee275ULL, "RAMPAGE2", "Rampage 2: Universal Tour",
    u8"rampage_r2", "rampage2", { "rampage2_ut.z64", "Rampage 2 - Universal Tour (U) [!].z64", "baserom.z64" } };
#else
static const RampageGame kGame = { 0x4cac6a61483a1ad8ULL, "RAMPAGE", "Rampage: World Tour",
    u8"rampage_wt", "rampage", { "rampage_wt.z64", "Rampage - World Tour (U) [!].z64", "baserom.z64" } };
#endif

static uint8_t* g_rdram_base = nullptr; // for translating crash addresses
// Set once a scripted run (RAMPAGE_QUIT_AFTER) is quitting: faults from game threads still
// polling memory at that point are noise.
static std::atomic<bool> g_quitting{ false };

// Graphics tasks go straight to RT64; audio tasks run the recompiled aspMain.
static RspExitReason noop_ucode(uint8_t*, uint32_t) { return RspExitReason::Broke; }

RspUcodeFunc* get_rsp_microcode(const OSTask* task) {
    return task->t.type == M_AUDTASK ? aspMain : noop_ucode;
}

// Runs after librecomp's init() has set up the boot state.
void on_game_init(uint8_t* rdram, recomp_context*) {
    g_rdram_base = rdram;
    fe::set_rdram(rdram);
#ifndef RAMPAGE_R2
    // osTvType = 0: World Tour only starts its timer and audio threads on this path, and picks
    // its NTSC video mode regardless. (Rampage 2 would pick a PAL mode, so it keeps NTSC.)
    *(int32_t*)(rdram + 0x300) = 0;
    // The SN64 sound engine (symbols: .sn64) always sits at 0x801377C0. The game copies it there in
    // pieces, which the runtime doesn't recognise as loading the section, so register it up front:
    // its functions are reached through pointers too.
    load_overlays(0xBF500, (int32_t)0x801377C0, 0x12620);
#endif
}

std::string get_game_thread_name(const OSThread* t) {
    return "[game] " + std::to_string(t->id);
}

#ifdef _WIN32
// =============================================================================
// Crash and hang diagnostics
//
// Release builds have no useful PDB symbols for the recompiled functions, but the linker .map
// lists every func_XXXXXXXX, so stack frames are resolved against it.
// =============================================================================
struct MapSym { uint32_t rva; std::string name; };
static std::vector<MapSym> g_map_syms;

static void load_map_symbols() {
    char exe[MAX_PATH];
    GetModuleFileNameA(NULL, exe, MAX_PATH);
    std::ifstream f(std::filesystem::path(exe).replace_extension(".map"));
    std::string line;
    while (std::getline(f, line)) {
        // " 0001:00025e00   <name>   0000000140026e00 f i x.obj"
        std::istringstream iss(line);
        std::vector<std::string> tok;
        for (std::string t; iss >> t; ) tok.push_back(t);
        if (tok.size() < 3 || tok[0].size() != 13 || tok[0][4] != ':') continue;
        for (size_t i = 2; i < tok.size(); i++) {
            if (tok[i].size() == 16 && tok[i].compare(0, 10, "0000000140") == 0) {
                g_map_syms.push_back({ (uint32_t)(strtoull(tok[i].c_str(), nullptr, 16) - 0x140000000ull), tok[i - 1] });
                break;
            }
        }
    }
    std::sort(g_map_syms.begin(), g_map_syms.end(), [](auto& a, auto& b) { return a.rva < b.rva; });
}

static std::string symbolize_rva(uint32_t rva) {
    auto it = std::upper_bound(g_map_syms.begin(), g_map_syms.end(), rva,
                               [](uint32_t v, const MapSym& m) { return v < m.rva; });
    if (it == g_map_syms.begin()) return {};
    --it;
    return it->name + " + 0x" + (std::stringstream{} << std::hex << (rva - it->rva)).str();
}

static void print_stack(HANDLE thread, CONTEXT ctx, int max_frames) {
    static bool sym_init = SymInitialize(GetCurrentProcess(), NULL, TRUE);
    (void)sym_init;
    uintptr_t base = (uintptr_t)GetModuleHandle(NULL);
    STACKFRAME64 frame{};
    frame.AddrPC = { ctx.Rip, 0, AddrModeFlat };
    frame.AddrStack = { ctx.Rsp, 0, AddrModeFlat };
    frame.AddrFrame = { ctx.Rbp, 0, AddrModeFlat };
    for (int i = 0; i < max_frames; i++) {
        if (!StackWalk64(IMAGE_FILE_MACHINE_AMD64, GetCurrentProcess(), thread, &frame, &ctx, NULL,
                         SymFunctionTableAccess64, SymGetModuleBase64, NULL)) break;
        uint64_t pc = frame.AddrPC.Offset;
        std::string name = pc >= base ? symbolize_rva((uint32_t)(pc - base)) : "";
        IMAGEHLP_LINE64 line{ sizeof(IMAGEHLP_LINE64) };
        DWORD disp = 0;
        if (SymGetLineFromAddr64(GetCurrentProcess(), pc, &disp, &line))
            fprintf(stderr, "  [%d] %s   (%s:%lu)\n", i, name.c_str(), line.FileName, line.LineNumber);
        else
            fprintf(stderr, "  [%d] %s   (0x%llX)\n", i, name.c_str(), (unsigned long long)pc);
    }
}

// RAMPAGE_PEEK=0x80113690,0x...: print those RDRAM words at a stack dump or crash.
static void print_peeks() {
    const char* p = std::getenv("RAMPAGE_PEEK");
    if (!p || !g_rdram_base) return;
    for (char* end; *p; p = (*end ? end + 1 : end)) {
        uint32_t a = (uint32_t)strtoul(p, &end, 16);
        if (end == p) break;
        fprintf(stderr, "[peek] 0x%08X = 0x%08X\n", a, *(uint32_t*)(g_rdram_base + (a - 0x80000000u)));
    }
}

static LONG WINAPI crash_handler(EXCEPTION_POINTERS* ep) {
    if (g_quitting) {
        TerminateProcess(GetCurrentProcess(), 0);
    }
    fprintf(stderr, "\n[crash] exception 0x%08lX at %p\n", ep->ExceptionRecord->ExceptionCode,
            ep->ExceptionRecord->ExceptionAddress);
    if (ep->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION && g_rdram_base) {
        uintptr_t fault = (uintptr_t)ep->ExceptionRecord->ExceptionInformation[1];
        int64_t off = (int64_t)(fault - (uintptr_t)g_rdram_base);
        fprintf(stderr, "[crash] %s %p = N64 0x%08X\n", ep->ExceptionRecord->ExceptionInformation[0] ? "writing" : "reading",
                (void*)fault, (uint32_t)(off + 0x80000000));
    }
    print_stack(GetCurrentThread(), *ep->ContextRecord, 24);
    print_peeks();
    return EXCEPTION_EXECUTE_HANDLER;
}

// Suspends every other thread and prints its stack (RAMPAGE_STACKDUMP=<seconds>, for hangs).
static void dump_all_stacks() {
    DWORD self = GetCurrentThreadId(), pid = GetCurrentProcessId();
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    THREADENTRY32 te{ sizeof(te) };
    for (BOOL ok = Thread32First(snap, &te); ok; ok = Thread32Next(snap, &te)) {
        if (te.th32OwnerProcessID != pid || te.th32ThreadID == self) continue;
        HANDLE th = OpenThread(THREAD_ALL_ACCESS, FALSE, te.th32ThreadID);
        if (!th) continue;
        SuspendThread(th);
        CONTEXT ctx{};
        ctx.ContextFlags = CONTEXT_FULL;
        if (GetThreadContext(th, &ctx)) {
            fprintf(stderr, "[stack] thread %lu:\n", te.th32ThreadID);
            print_stack(th, ctx, 12);
        }
        ResumeThread(th);
        CloseHandle(th);
    }
    CloseHandle(snap);
    print_peeks();
}

// RAMPAGE_WATCH=<n64 addr>@<seconds>: then arm a hardware write watchpoint on that RDRAM word in
// every thread; the first write lands in crash_handler with the writer's stack.
static void watch_thread(uint32_t n64_addr, int seconds) {
    Sleep(seconds * 1000);
    if (!g_rdram_base) return;
    DWORD64 native = (DWORD64)(g_rdram_base + (n64_addr - 0x80000000u));
    fprintf(stderr, "[watch] armed on 0x%08X\n", n64_addr);
    DWORD self = GetCurrentThreadId(), pid = GetCurrentProcessId();
    while (true) { // re-arm so threads created later are covered
        HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
        THREADENTRY32 te{ sizeof(te) };
        for (BOOL ok = Thread32First(snap, &te); ok; ok = Thread32Next(snap, &te)) {
            if (te.th32OwnerProcessID != pid || te.th32ThreadID == self) continue;
            HANDLE th = OpenThread(THREAD_ALL_ACCESS, FALSE, te.th32ThreadID);
            if (!th) continue;
            SuspendThread(th);
            CONTEXT ctx{};
            ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;
            if (GetThreadContext(th, &ctx) && ctx.Dr0 != native) {
                ctx.Dr0 = native;
                ctx.Dr7 = 0x000D0001; // local enable 0, break on write, 4 bytes
                SetThreadContext(th, &ctx);
            }
            ResumeThread(th);
            CloseHandle(th);
        }
        CloseHandle(snap);
        Sleep(10);
    }
}

// Saves the game window's client area as a 24-bit BMP. PrintWindow's full-content mode also
// captures the D3D12 swap chain, and works while the window sits off-screen (--headless).
static void capture_window(const std::string& path) {
    SDL_SysWMinfo wm;
    SDL_VERSION(&wm.version);
    if (!fe::window() || !SDL_GetWindowWMInfo(fe::window(), &wm)) return;
    HWND hwnd = wm.info.win.window;
    RECT rc;
    GetClientRect(hwnd, &rc);
    int w = rc.right, h = rc.bottom;
    HDC wdc = GetDC(hwnd), mdc = CreateCompatibleDC(wdc);
    HBITMAP bmp = CreateCompatibleBitmap(wdc, w, h);
    HGDIOBJ old = SelectObject(mdc, bmp);
    PrintWindow(hwnd, mdc, PW_CLIENTONLY | PW_RENDERFULLCONTENT);
    BITMAPINFOHEADER bi{ sizeof(bi), w, h, 1, 24, BI_RGB };
    int stride = (w * 3 + 3) & ~3;
    std::vector<uint8_t> pixels((size_t)stride * h);
    GetDIBits(mdc, bmp, 0, h, pixels.data(), (BITMAPINFO*)&bi, DIB_RGB_COLORS);
    SelectObject(mdc, old);
    DeleteObject(bmp);
    DeleteDC(mdc);
    ReleaseDC(hwnd, wdc);

    BITMAPFILEHEADER bf{ 0x4D42, (DWORD)(sizeof(bf) + sizeof(bi) + pixels.size()), 0, 0, sizeof(bf) + sizeof(bi) };
    std::ofstream f(path, std::ios::binary);
    f.write((const char*)&bf, sizeof(bf));
    f.write((const char*)&bi, sizeof(bi));
    f.write((const char*)pixels.data(), pixels.size());
    printf("[rampage] saved %s (%dx%d)\n", path.c_str(), w, h);
}
#endif // _WIN32

// =============================================================================
// Main
// =============================================================================
int main(int argc, char* argv[]) {
    setvbuf(stdout, nullptr, _IONBF, 0);
    setvbuf(stderr, nullptr, _IONBF, 0);
#ifdef _WIN32
    // Started without a terminal (the launcher, a shortcut): keep stderr in <short_name>.log.
    HANDLE err = GetStdHandle(STD_ERROR_HANDLE);
    if (err == nullptr || err == INVALID_HANDLE_VALUE || GetFileType(err) == FILE_TYPE_UNKNOWN) {
        freopen((std::string(kGame.short_name) + ".log").c_str(), "w", stderr);
        setvbuf(stderr, nullptr, _IONBF, 0);
    }
    load_map_symbols();
    SetUnhandledExceptionFilter(crash_handler);
    if (const char* s = std::getenv("RAMPAGE_STACKDUMP")) {
        std::thread([n = std::atoi(s)] { Sleep(n * 1000); dump_all_stacks(); }).detach();
    }
    // RAMPAGE_SHOT="10:title.bmp,30:menu.bmp": capture the window at those times (seconds).
    if (const char* s = std::getenv("RAMPAGE_SHOT")) {
        std::thread([spec = std::string(s)] {
            double elapsed = 0;
            for (std::stringstream ss(spec); ss.good(); ) {
                std::string item;
                std::getline(ss, item, ',');
                size_t colon = item.find(':');
                if (colon == std::string::npos) continue;
                double t = std::atof(item.c_str());
                if (t > elapsed) Sleep((DWORD)((t - elapsed) * 1000));
                elapsed = std::max(elapsed, t);
                capture_window(item.substr(colon + 1));
            }
        }).detach();
    }
    if (const char* w = std::getenv("RAMPAGE_WATCH")) {
        const char* at = strchr(w, '@');
        std::thread(watch_thread, (uint32_t)strtoul(w, nullptr, 16), at ? std::atoi(at + 1) : 0).detach();
    }
#endif
    // RAMPAGE_QUIT_AFTER=<seconds>: exit on its own, for scripted and recorded runs.
    if (const char* q = std::getenv("RAMPAGE_QUIT_AFTER")) {
        std::thread([n = std::atoi(q)] {
            std::this_thread::sleep_for(std::chrono::seconds(n));
            g_quitting = true;
            ultramodern::quit();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            fprintf(stderr, "[rampage] did not quit cleanly; exiting\n");
            std::_Exit(0);
        }).detach();
    }

    printf("%s - Rampage Recompiled %s\n", kGame.title, RAMPAGE_VERSION);

    recomp::GameEntry entry{};
    entry.rom_hash = kGame.rom_hash;
    entry.internal_name = kGame.internal_name;
    entry.display_name = kGame.title;
    entry.game_id = kGame.game_id;
    entry.save_type = recomp::SaveType::AllowAll;
    entry.is_enabled = true;
    entry.entrypoint_address = get_entrypoint_address();
    entry.entrypoint = recomp_entrypoint;
    entry.on_init_callback = on_game_init;

    register_rampage_overlays();
    if (!recomp::register_game(entry)) {
        fprintf(stderr, "Failed to register game\n");
        return 1;
    }

    recomp::Configuration cfg{};
    cfg.project_version = { 0, 3, 0 };
    cfg.rsp_callbacks.get_rsp_microcode = get_rsp_microcode;
    cfg.threads_callbacks.get_game_thread_name = get_game_thread_name;

    fe::GameInfo game;
    game.title = kGame.title;
    game.game_id = kGame.game_id;
    game.short_name = kGame.short_name;
    game.rom_names = kGame.rom_names;
    game.players = 3;
    game.env_prefix = "RAMPAGE_";
    game.audio_max_queued_frames = 1; // the mixer computes "a frame minus what's queued"
    return fe::run(game, cfg, argc, argv); // ends the process itself on a normal exit
}
