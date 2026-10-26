// Sound: the game's AI buffers (16-bit stereo, from osAiSetNextBuffer) go to an SDL audio queue.
//
// The game asks how much is still buffered (osAiGetLength) to decide how much to mix next. Normally
// that's the real queue. In deterministic mode (netplay) the real queue differs per machine, which
// would change what the game does, so the answer comes from game time instead: what the game queued
// minus what game time says has played. Both machines then mix the same amounts.

#include <SDL.h>

#include <algorithm>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "config.hpp"
#include "internal.hpp"

namespace fe {
namespace {

SDL_AudioDeviceID g_device = 0;
uint32_t g_rate = 0;
constexpr int kChannels = 2;
constexpr uint32_t kBytesPerFrame = kChannels * sizeof(float);

// Deterministic mode's model of the buffer, in sample frames.
uint64_t g_det_queued = 0;
uint64_t g_det_first_retrace = 0;
bool g_det_started = false;

void open_device(uint32_t rate) {
    if (g_device) SDL_CloseAudioDevice(g_device);
    SDL_AudioSpec want{}, have{};
    want.freq = (int)rate;
    want.format = AUDIO_F32SYS;
    want.channels = kChannels;
    want.samples = 512;
    g_device = SDL_OpenAudioDevice(nullptr, 0, &want, &have, 0);
    if (!g_device) { fprintf(stderr, "[audio] can't open an audio device: %s\n", SDL_GetError()); return; }
    SDL_PauseAudioDevice(g_device, 0);
    printf("[audio] %u Hz\n", rate);
}

void queue_samples(int16_t* data, size_t count) {
    if (det_enabled()) {
        if (!g_det_started) { g_det_started = true; g_det_first_retrace = det_frame(); }
        g_det_queued += count / kChannels;
    }
    if (!g_device) return;
    // ponytail: in deterministic mode game time and the sound card drift apart slowly; drop a buffer
    // when the queue passes 200 ms rather than resampling.
    if (det_enabled() && SDL_GetQueuedAudioSize(g_device) > g_rate * kBytesPerFrame / 5) return;

    static std::vector<float> out;
    out.resize(count);
    const float volume = std::clamp((float)g_config.volume, 0.0f, 1.0f) / 32768.0f;
    // The buffer is read through the N64's byte-swapped memory, so each frame's channels come swapped.
    for (size_t i = 0; i + 1 < count; i += 2) {
        out[i] = data[i + 1] * volume;
        out[i + 1] = data[i] * volume;
    }
    // <prefix>AUDIODUMP=<file>: also write the output as raw 16-bit stereo, for checks without speakers.
    static FILE* dump = [] { const char* p = std::getenv((g_game.env_prefix + "AUDIODUMP").c_str()); return p ? std::fopen(p, "wb") : nullptr; }();
    if (dump) {
        for (size_t i = 0; i + 1 < count; i += 2) { int16_t lr[2] = { data[i + 1], data[i] }; std::fwrite(lr, sizeof(lr), 1, dump); }
        std::fflush(dump);
    }
    SDL_QueueAudio(g_device, out.data(), (Uint32)(count * sizeof(float)));
}

size_t queued_frames() {
    if (det_enabled()) {
        if (!g_det_started || g_rate == 0) return 0;
        uint64_t played = (det_frame() - g_det_first_retrace) * g_rate / 60;
        return g_det_queued > played ? (size_t)(g_det_queued - played) : 0;
    }
    // (The runtime reports half a frame less than this, so the game mixes a little ahead.)
    return g_device ? SDL_GetQueuedAudioSize(g_device) / kBytesPerFrame : 0;
}

// Never report more than GameInfo::audio_max_queued_frames video frames' worth (two by default).
// Real hardware never has more queued than that, and games mix "a frame minus what's queued" in 16
// bits: Racer's mixer wraps a big backlog (after a hitch) into a huge positive count, overflows its
// command list and halts forever; Rampage's goes negative at two frames, so it uses one. Reporting
// "plenty" makes the game mix its minimum, so a backlog drains on its own.
size_t get_frames_remaining() {
    return std::min(queued_frames(), (size_t)(g_rate * g_game.audio_max_queued_frames / 60));
}

void set_frequency(uint32_t rate) {
    if (rate == g_rate) return;
    g_rate = rate; // even if no device opens: deterministic mode's model needs it on every machine
    open_device(rate);
}

} // namespace

ultramodern::audio_callbacks_t audio_callbacks() {
    return { queue_samples, get_frames_remaining, set_frequency };
}

} // namespace fe
