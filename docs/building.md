# Building

The README's Getting Started has the commands; this is the why and the details.

## Toolkits and the branches Rampage needs

| Toolkit | Branch | Carries |
|---|---|---|
| [sp00nznet/N64Recomp](https://github.com/sp00nznet/N64Recomp) | `fix/fallthrough-tail-call` | upstream `ffb39cd` + [#1](https://github.com/sp00nznet/N64Recomp/pull/1): code that runs off a function's end continues into the next function |
| [sp00nznet/N64ModernRuntime](https://github.com/sp00nznet/N64ModernRuntime) | `rampage` | fork `main` (upstream + Racer's fixes, PRs #1-#8, #10 deterministic mode, #12 shutdown) + [#9](https://github.com/sp00nznet/N64ModernRuntime/pull/9): `load_overlays` skips sections with no ROM data |
| [sp00nznet/rt64](https://github.com/sp00nznet/rt64) | `rampage` | fork `main` (including #5, the Android build) + [#3](https://github.com/sp00nznet/rt64/pull/3): COPY-mode alpha compare |

Each fix is generic and went in as its own PR on the fork. When they merge, the branches point at
the fork's `main` again.

`CMakeLists.txt` looks for the runtime and RT64 in `deps/` (where Setup puts them) and otherwise
next to the repo (`../N64ModernRuntime`, `../rt64`). Point it anywhere with
`-DN64_MODERN_RUNTIME_DIR=` and `-DRT64_DIR=`. `tools/regen.py` takes N64Recomp from `$N64RECOMP`,
else `../N64Recomp/build/Release/N64Recomp.exe`, and RSPRecomp from `$RSPRECOMP`, else next to it.
Setup refreshes `deps/` to the pinned branches on every run, so an update that needs newer toolkit
fixes gets them.

## What each step makes

| Step | Makes | Committed? |
|---|---|---|
| `py tools/regen.py wt` | `gen/wt/` (C, about 80 files), `rsp/aspMain_wt.cpp` (the audio microcode) and `gen/wt.log`; skipped while its inputs are unchanged (`gen/wt/inputs.txt`) | never: it's the game's code |
| `cmake -S . -B build/wt -DRAMPAGE_GAME=wt` | a Visual Studio solution in `build/wt` | no |
| `cmake --build build/wt --config Release` | `build/wt/Release/RampageWorldTour.exe` with `SDL2.dll`, `dxil.dll`, `dxcompiler.dll` and a `.map` | no |
| first run | `rampage.json` / `rampage2.json` (settings) and `saves/` in the working folder | no |

`regen.py` deletes `gen/<game>/` first: N64Recomp names its output `funcs_N.c` by count, and a
stale file from a bigger run would be compiled in too.

On Windows, SDL2 is the build RT64 ships in `src/contrib/mupen64plus-win32-deps`; no package
manager is involved. On Linux and macOS it's the system's (`setup.sh` installs it), on Android
SDL's source, built into the `.apk` ([other-builds.md](other-builds.md)).

On Windows, RT64 loads `dxil.dll` and `dxcompiler.dll` from next to the exe and silently skips
initialising without them, so the build copies them there.

The `.map` file is what crash and stack traces use to name recompiled functions
(`func_8005E520 + 0x1c8`): release builds have no useful PDB symbols for them.

## Linux and macOS

`setup.sh` runs the same steps with Ninja and Clang (Linux) or Apple Clang (macOS), into
`build/<game>/`, and writes `Rampage World Tour (recomp).sh` (`.command` on macOS) launchers. By
hand:

```
cmake -S deps/N64Recomp -B deps/N64Recomp/build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build deps/N64Recomp/build --target N64RecompCLI RSPRecomp
N64RECOMP=deps/N64Recomp/build/N64Recomp python3 tools/regen.py wt
cmake -S . -B build/wt -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo -DRAMPAGE_GAME=wt -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
cmake --build build/wt
```

CI compiles everything but the ROM-derived code on Linux and macOS (`.github/workflows/build.yml`).

## Changing a symbol file or a `.toml`

Re-run `tools/regen.py` and rebuild. The generator's summary line is the first check: new
`[Warn]` lines mean a boundary is wrong ([symbols.md](symbols.md)).

## Not on netlab yet

House rules want day-to-day builds and runs on [netlab](https://github.com/sp00nznet/recomp-netlab).
N64 recomps can't use it yet: no builder has RT64's toolchain (DXC, an MSVC-built SDL2), and the
test VM has no GPU for D3D12. Builds run on the workstation until netlab gains that; tests run
with `--headless`, which never puts a window on a monitor.
