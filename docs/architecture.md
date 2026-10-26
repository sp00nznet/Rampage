# Architecture

```
 your ROM ──► N64Recomp ──► gen/<game>/*.c ──┐            (tools/regen.py; local only)
 symbols/*.toml, rampage_*.toml ─────────────┘
 your ROM ──► RSPRecomp ──► rsp/aspMain_<game>.cpp        (the audio microcode, same step)
                                              ▼
 gen/<game>/funcs_*.c + src/<game>_stubs.c ──► RecompiledFuncs
 src/*.cpp, rsp/aspMain_<game>.cpp ──────────► RampageWorldTour / Rampage2
 frontend/ (window, launcher, input, sound) ─┤  (on Android: libmain.so in an .apk)
 N64ModernRuntime (librecomp + ultramodern) ─┤
 RT64 (renderer) ────────────────────────────┘
```

One source tree builds either game; `RAMPAGE_GAME` (`wt` or `r2`) picks which generated tree and
stubs file are compiled, and `RAMPAGE_R2` switches the few differences in `src/main.cpp`.

## The parts

| Part | Where | Owns |
|---|---|---|
| Symbol files | `symbols/rampage_wt_syms.toml`, `symbols/rampage2_ut_syms.toml` | Where every function starts and ends, and the names of the libultra ones. Names matter: a named libultra function is replaced by the runtime's own implementation instead of being recompiled. See [symbols.md](symbols.md). |
| Recompiler config | `rampage_wt.toml`, `rampage2_ut.toml` | Which functions are left out (`ignored`, `stubs`) and the in-function fixes (`[[patches.hook]]`), see [game-fixes.md](game-fixes.md). |
| Generated code | `gen/<game>/` (gitignored) | N64Recomp's C translation of the game. Made from the player's ROM by `tools/regen.py`; never committed. |
| Stubs | `src/wt_stubs.c`, `src/r2_stubs.c` | C for the functions the config leaves out, and the helpers hooks call (declared in `src/hooks.h`, which is force-included into the generated code). |
| Game shell | `src/main.cpp`, `overlays.cpp` | The game registration librecomp needs, the RSP microcode table, the per-game boot fixes, and the Windows debugging tools (`RAMPAGE_SHOT`, `STACKDUMP`, `WATCH`, `PEEK`). |
| Frontend | `frontend/` | The window (D3D12 on Windows, Vulkan on Linux and Android, Metal on macOS), the launcher and in-game menu, controllers and keyboard, the config file, SDL sound output, `--headless`/`--play`. The same module as sp00nznet's Racer port, copied in. |
| Audio microcode | `rsp/aspMain_<game>.toml` | libultra's `aspMain`, turned into C++ (`rsp/aspMain_<game>.cpp`, gitignored) by RSPRecomp. |
| N64ModernRuntime | `deps/` or a sibling checkout | librecomp (ROM, saves, overlays, the libultra functions recompiled code calls) and ultramodern (threads, message queues, VI timing, input). |
| RT64 | `deps/` or a sibling checkout | Takes the display lists the game submits and draws them with D3D12, Vulkan or Metal. |

## Threads, and why some loops need a yield

ultramodern runs each game thread on its own OS thread but lets only one run at a time, switching
when the running one blocks (`osRecvMesg`) or yields. Interrupt-driven work (VI retrace messages,
the scheduler waking up) only happens at those points. A game loop that polls memory, waiting for
another thread to change it, therefore never ends: on hardware an interrupt preempts it. Rampage 2
has three such loops; each gets a `yield_self` hook ([game-fixes.md](game-fixes.md)).

## Audio

The game builds an audio command list (Midway's sequencer on top of libultra's synthesis code) and
submits it as an RSP task. The RSP side is libultra's stock `aspMain` microcode, which both games
carry byte for byte as Racer and Pokemon Snap do: `tools/regen.py` turns it into C++ with
N64Recomp's RSPRecomp (`rsp/aspMain_<game>.toml`), and `get_rsp_microcode` runs it for audio
tasks. The mixed buffers reach the AI through `osAiSetNextBuffer`, which the runtime hands to the
frontend's SDL audio output.

In Rampage 2 all of this lives in the main code segment. World Tour keeps the engine in a second
segment it copies to `0x801377C0` at boot; it's the `.sn64` section of its symbol file
([symbols.md](symbols.md)).
