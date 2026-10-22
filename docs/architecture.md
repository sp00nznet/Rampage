# Architecture

```
 your ROM ──► N64Recomp ──► gen/<game>/*.c ──┐            (tools/regen.py; local only)
 symbols/*.toml, rampage_*.toml ─────────────┘
                                              ▼
 gen/<game>/funcs_*.c + src/<game>_stubs.c ──► RecompiledFuncs.lib
 src/*.cpp (shell) ─────────────────────────► RampageWorldTour.exe / Rampage2.exe
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
| Shell | `src/main.cpp`, `overlays.cpp`, `rt64_render_context.cpp`, `config.cpp`, `input.cpp`, `sn64_rom_helpers.cpp` | Window, input, config file, ROM lookup, the game registration librecomp needs, and the debugging tools (`--headless`, `RAMPAGE_*`). Shares its design with sp00nznet's Racer port. |
| N64ModernRuntime | `deps/` or a sibling checkout | librecomp (ROM, saves, overlays, the libultra functions recompiled code calls) and ultramodern (threads, message queues, VI timing, input). |
| RT64 | `deps/` or a sibling checkout | Takes the display lists the game submits and draws them with D3D12. |

## Threads, and why some loops need a yield

ultramodern runs each game thread on its own OS thread but lets only one run at a time, switching
when the running one blocks (`osRecvMesg`) or yields. Interrupt-driven work (VI retrace messages,
the scheduler waking up) only happens at those points. A game loop that polls memory, waiting for
another thread to change it, therefore never ends: on hardware an interrupt preempts it. Rampage 2
has two such loops; each gets a `yield_self` hook ([game-fixes.md](game-fixes.md)).

## Audio

Both games' audio goes through Midway's SN64 engine, which the games load into RAM at run time.
It isn't recompiled, so its entry points are stubs that load the sound banks and otherwise do
nothing, and the RSP audio tasks are acknowledged without being run. The games play silently.
