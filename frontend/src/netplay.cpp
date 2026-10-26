// Netplay: 2-player deterministic lockstep over UDP.
//
// Both machines run the game in ultramodern's deterministic mode. At every virtual retrace each side
// samples its local controller once, sends it for retrace + delay, and waits for the other side's
// input for this retrace before the game sees the frame, so both games get identical inputs at
// identical points. Every 60 retraces both sides exchange a hash of game RAM to detect a desync.
//
// Before the game starts, the host sends its save (unlocks change the game, so both sides need the
// same one). Netplay uses its own config folder (netplay/) so normal saves are untouched.

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
using SOCKET = int;
constexpr SOCKET INVALID_SOCKET = -1;
static int closesocket(SOCKET s) { return close(s); }
struct WSADATA {};
static int WSAStartup(int, WSADATA*) { return 0; }
static int WSACleanup() { return 0; }
#define MAKEWORD(a, b) 0
#endif

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <map>
#include <mutex>
#include <string>
#include <vector>

#include "librecomp/game.hpp"
#include "ultramodern/error_handling.hpp"
#include "config.hpp"
#include "internal.hpp"

namespace fe::net {
namespace {

constexpr uint32_t kMagic = 0x4E363446; // "N64F"
constexpr uint32_t kVersion = 2;
constexpr int kRedundancy = 16;     // each input packet repeats this many recent frames
constexpr int kHashEvery = 60;      // retraces between desync checks
constexpr uint32_t kMaxSave = 4096; // ponytail: one datagram, enough for EEPROM; chunk it for SRAM/flash saves

enum PacketType : uint32_t { PKT_HELLO = 1, PKT_WELCOME = 2, PKT_ACK = 3, PKT_INPUT = 4, PKT_HASH = 5 };

struct Input { uint16_t buttons = 0; float x = 0, y = 0; };

#pragma pack(push, 1)
struct Header { uint32_t magic, type, version, game; };
struct WelcomePacket { Header h; uint32_t delay; uint32_t save_len; uint8_t save[kMaxSave]; };
struct InputPacket { Header h; uint64_t first; uint32_t count; Input inputs[kRedundancy]; };
struct HashPacket { Header h; uint64_t frame; uint64_t hash; };
#pragma pack(pop)

bool g_active = false;
bool g_is_host = false;
int g_delay = 2;
SOCKET g_sock = INVALID_SOCKET;
sockaddr_storage g_peer{};
int g_peer_len = 0;
std::vector<uint8_t> g_save; // the shared save, written into netplay/ by begin()

std::map<uint64_t, Input> g_local, g_remote; // by retrace
std::map<uint64_t, uint64_t> g_local_hash, g_remote_hash;
Input g_frame_inputs[2];                     // what the game reads this retrace: [player 1, player 2]

std::mutex g_status_mutex;
std::string g_status;

void set_status(const std::string& s) {
    printf("[netplay] %s\n", s.c_str());
    std::lock_guard lock{ g_status_mutex };
    g_status = s;
}

// Identifies the game, so two different recomps never pair up.
uint32_t game_tag() {
    uint32_t h = 2166136261u;
    for (char8_t c : g_game.game_id) { h ^= (uint8_t)c; h *= 16777619u; }
    return h;
}

Header header(PacketType t) { return { kMagic, t, kVersion, game_tag() }; }

void send_raw(const void* data, int len) {
    sendto(g_sock, (const char*)data, len, 0, (const sockaddr*)&g_peer, g_peer_len);
}

// Receives one packet (waiting up to `ms`). On the host, the first sender becomes the peer.
int recv_raw(void* buf, int cap, int ms) {
    fd_set fds; FD_ZERO(&fds); FD_SET(g_sock, &fds);
    timeval tv{ ms / 1000, (ms % 1000) * 1000 };
    if (select((int)g_sock + 1, &fds, nullptr, nullptr, &tv) <= 0) return 0;
    sockaddr_storage from{}; socklen_t from_len = sizeof(from);
    int n = recvfrom(g_sock, (char*)buf, cap, 0, (sockaddr*)&from, &from_len);
    if (n < (int)sizeof(Header) || ((Header*)buf)->magic != kMagic) return 0;
    if (g_peer_len == 0) { g_peer = from; g_peer_len = from_len; }
    return n;
}

void handle_packet(const uint8_t* buf, int n) {
    const Header* h = (const Header*)buf;
    if (h->type == PKT_INPUT && n >= (int)offsetof(InputPacket, inputs)) {
        const InputPacket* p = (const InputPacket*)buf;
        for (uint32_t i = 0; i < p->count && i < kRedundancy; i++) g_remote.emplace(p->first + i, p->inputs[i]);
    } else if (h->type == PKT_HASH && n >= (int)sizeof(HashPacket)) {
        const HashPacket* p = (const HashPacket*)buf;
        g_remote_hash[p->frame] = p->hash;
    }
}

void send_inputs(uint64_t newest) {
    InputPacket p{ header(PKT_INPUT) };
    p.first = newest >= kRedundancy - 1 ? newest - (kRedundancy - 1) : 0;
    p.count = (uint32_t)(newest - p.first + 1);
    for (uint32_t i = 0; i < p.count; i++) p.inputs[i] = g_local[p.first + i];
    send_raw(&p, (int)(offsetof(InputPacket, inputs) + p.count * sizeof(Input)));
}

void check_hashes() {
    for (auto it = g_local_hash.begin(); it != g_local_hash.end();) {
        auto r = g_remote_hash.find(it->first);
        if (r == g_remote_hash.end()) { ++it; continue; }
        if (r->second != it->second) {
            fprintf(stderr, "[netplay] DESYNC at retrace %llu (local %016llx, remote %016llx)\n",
                    (unsigned long long)it->first, (unsigned long long)it->second, (unsigned long long)r->second);
        }
        g_remote_hash.erase(r);
        it = g_local_hash.erase(it);
    }
}

// The lockstep step, run by the deterministic scheduler at every retrace (on a game thread).
void on_retrace(uint64_t r) {
    Input local;
    sample_local_input(&local.buttons, &local.x, &local.y);
    g_local[r + g_delay] = local;
    send_inputs(r + g_delay);

    if (r % kHashEvery == 0) {
        uint64_t h = det_hash_game_ram();
        g_local_hash[r] = h;
        HashPacket p{ header(PKT_HASH), r, h };
        send_raw(&p, sizeof(p));
    }

    // Wait for the peer's input for this retrace, resending ours meanwhile (the first `delay`
    // retraces have no input from anyone).
    auto start = std::chrono::steady_clock::now();
    auto last_note = start;
    while (r >= (uint64_t)g_delay && g_remote.find(r) == g_remote.end()) {
        uint8_t buf[sizeof(WelcomePacket)];
        int n = recv_raw(buf, sizeof(buf), 4);
        if (n > 0) { handle_packet(buf, n); continue; }
        send_inputs(r + g_delay);
        auto now = std::chrono::steady_clock::now();
        if (now - last_note > std::chrono::seconds(3)) {
            last_note = now;
            fprintf(stderr, "[netplay] waiting for the other player (retrace %llu)...\n", (unsigned long long)r);
        }
        if (now - start > std::chrono::seconds(30)) {
            ultramodern::error_handling::message_box("The other player stopped responding. The game will close.");
            std::exit(1);
        }
    }
    // Drain whatever else arrived.
    for (;;) { uint8_t buf[sizeof(WelcomePacket)]; int n = recv_raw(buf, sizeof(buf), 0); if (n <= 0) break; handle_packet(buf, n); }

    Input mine = r >= (uint64_t)g_delay ? g_local[r] : Input{};
    Input theirs = r >= (uint64_t)g_delay ? g_remote[r] : Input{};
    g_frame_inputs[0] = g_is_host ? mine : theirs;
    g_frame_inputs[1] = g_is_host ? theirs : mine;

    // Forget old frames.
    if (r > 120) { g_local.erase(g_local.begin(), g_local.lower_bound(r - 120)); g_remote.erase(g_remote.begin(), g_remote.lower_bound(r - 120)); }
    check_hashes();
}

bool open_socket(int bind_port) {
    static bool wsa_started = false;
    WSADATA wsa;
    if (!wsa_started && WSAStartup(MAKEWORD(2, 2), &wsa) != 0) { set_status("Networking is unavailable."); return false; }
    wsa_started = true;
    if (g_sock != INVALID_SOCKET) closesocket(g_sock);
    g_peer_len = 0;
    g_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (g_sock == INVALID_SOCKET) { set_status("Couldn't open a UDP socket."); return false; }
    sockaddr_in addr{}; addr.sin_family = AF_INET; addr.sin_port = htons((uint16_t)bind_port); addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(g_sock, (sockaddr*)&addr, sizeof(addr)) != 0) {
        set_status("UDP port " + std::to_string(bind_port) + " is in use.");
        return false;
    }
    return true;
}

void close_socket() {
    if (g_sock != INVALID_SOCKET) closesocket(g_sock);
    g_sock = INVALID_SOCKET;
}

std::filesystem::path save_path(const std::filesystem::path& dir) {
    return dir / "saves" / (std::filesystem::path(g_game.game_id).string() + ".bin");
}

std::vector<uint8_t> read_file(const std::filesystem::path& p) {
    std::ifstream f(p, std::ios::binary);
    return std::vector<uint8_t>((std::istreambuf_iterator<char>(f)), {});
}

} // namespace

bool active() { return g_active; }
bool is_host() { return g_is_host; }
int delay() { return g_delay; }

std::string status() {
    std::lock_guard lock{ g_status_mutex };
    return g_status;
}

bool host(int port, const std::atomic<bool>& cancel) {
    if (!open_socket(port)) return false;
    g_is_host = true;
    g_delay = g_config.netplayInputDelay;
    set_status("Waiting for player 2 on UDP port " + std::to_string(port) + "...");
    g_save = read_file(save_path(base_dir()));
    if (g_save.size() > kMaxSave) {
        set_status("This game's save is too big to share; player 2 starts without it.");
        g_save.clear();
    }
    WelcomePacket w{ header(PKT_WELCOME), (uint32_t)g_delay, (uint32_t)g_save.size() };
    std::memcpy(w.save, g_save.data(), g_save.size());
    const int welcome_len = (int)(offsetof(WelcomePacket, save) + g_save.size());
    bool joined = false;
    while (!cancel) {
        uint8_t buf[sizeof(WelcomePacket)];
        int n = recv_raw(buf, sizeof(buf), 50);
        if (n <= 0) { if (joined) send_raw(&w, welcome_len); continue; }
        const Header* h = (const Header*)buf;
        if (h->version != kVersion || h->game != game_tag()) {
            set_status("Someone tried to join with a different game or build.");
            g_peer_len = 0;
            continue;
        }
        if (h->type == PKT_HELLO) {
            if (!joined) set_status("Player 2 connected; sending the save...");
            joined = true;
            send_raw(&w, welcome_len);
        } else if (h->type == PKT_ACK) {
            return true;
        } else if (h->type == PKT_INPUT) {
            handle_packet(buf, n); // the joiner already started (its ACKs were lost)
            return true;
        }
    }
    close_socket();
    set_status("Cancelled.");
    return false;
}

bool join(const std::string& address, const std::atomic<bool>& cancel) {
    std::string addr = address, port = std::to_string(g_config.netplayPort);
    if (auto c = addr.rfind(':'); c != std::string::npos) { port = addr.substr(c + 1); addr = addr.substr(0, c); }
    if (!open_socket(0)) return false;
    g_is_host = false;
    addrinfo hints{}; hints.ai_family = AF_INET; hints.ai_socktype = SOCK_DGRAM;
    addrinfo* res = nullptr;
    if (getaddrinfo(addr.c_str(), port.c_str(), &hints, &res) != 0 || !res) {
        set_status("Can't find " + addr + ".");
        close_socket();
        return false;
    }
    std::memcpy(&g_peer, res->ai_addr, res->ai_addrlen); g_peer_len = (int)res->ai_addrlen;
    freeaddrinfo(res);
    set_status("Joining " + addr + ":" + port + "...");
    Header hello = header(PKT_HELLO);
    auto start = std::chrono::steady_clock::now();
    for (;;) {
        if (cancel) { close_socket(); set_status("Cancelled."); return false; }
        if (std::chrono::steady_clock::now() - start > std::chrono::seconds(30)) {
            close_socket();
            set_status("No answer from " + addr + ":" + port + ". Is the host waiting, and is UDP port " + port + " reachable?");
            return false;
        }
        send_raw(&hello, sizeof(hello));
        uint8_t buf[sizeof(WelcomePacket)];
        int n = recv_raw(buf, sizeof(buf), 200);
        if (n < (int)offsetof(WelcomePacket, save) || ((Header*)buf)->type != PKT_WELCOME) continue;
        const WelcomePacket* w = (const WelcomePacket*)buf;
        if (w->h.version != kVersion || w->h.game != game_tag()) {
            close_socket();
            set_status("The host is running a different game or build.");
            return false;
        }
        g_delay = (int)w->delay;
        uint32_t len = std::min<uint32_t>(w->save_len, (uint32_t)(n - offsetof(WelcomePacket, save)));
        g_save.assign(w->save, w->save + len);
        break;
    }
    Header ack = header(PKT_ACK);
    for (int i = 0; i < 5; i++) send_raw(&ack, sizeof(ack));
    set_status("Connected; input delay " + std::to_string(g_delay) + " frames.");
    return true;
}

// netplay/ gets the stored ROM (copied once) and the shared save; the game then runs from there
// in deterministic mode.
void begin() {
    find_rom(); // stores the ROM in the normal folder first, so there's one to copy
    const std::filesystem::path base = base_dir(), dir = base / "netplay";
    std::filesystem::create_directories(dir / "saves");
    const std::filesystem::path rom = std::filesystem::path(g_game.game_id).string() + ".z64";
    std::error_code ec;
    std::filesystem::copy_file(base / rom, dir / rom, std::filesystem::copy_options::skip_existing, ec);
    if (!g_save.empty()) std::ofstream(save_path(dir), std::ios::binary).write((const char*)g_save.data(), g_save.size());
    else std::filesystem::remove(save_path(dir), ec);
    recomp::register_config_path(dir);
    g_active = true;
    det_start(on_retrace);
}

// The game's controller reads while netplay is active: ports 1 and 2 are the two players.
bool get_input(int port, uint16_t* buttons, float* x, float* y) {
    *buttons = 0; *x = *y = 0;
    if (port < 0 || port > 1) return false;
    *buttons = g_frame_inputs[port].buttons; *x = g_frame_inputs[port].x; *y = g_frame_inputs[port].y;
    return true;
}

ultramodern::input::connected_device_info_t device_info(int port) {
    if (port == 0 || port == 1) return { ultramodern::input::Device::Controller, ultramodern::input::Pak::None };
    return { ultramodern::input::Device::None, ultramodern::input::Pak::None };
}

std::vector<std::string> local_addresses() {
    std::vector<std::string> out;
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return out;
    char name[256];
    if (gethostname(name, sizeof(name)) == 0) {
        addrinfo hints{}; hints.ai_family = AF_INET;
        addrinfo* res = nullptr;
        if (getaddrinfo(name, nullptr, &hints, &res) == 0) {
            for (addrinfo* a = res; a; a = a->ai_next) {
                char ip[INET_ADDRSTRLEN];
                inet_ntop(AF_INET, &((sockaddr_in*)a->ai_addr)->sin_addr, ip, sizeof(ip));
                if (std::find(out.begin(), out.end(), ip) == out.end()) out.push_back(ip);
            }
            freeaddrinfo(res);
        }
    }
    WSACleanup();
    return out;
}

} // namespace fe::net
