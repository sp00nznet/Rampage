# Rampage Recompiled

A native port of **Rampage: World Tour** (N64, 1998) and **Rampage 2: Universal Tour** (N64, 1999)
for Windows, Linux and macOS, with Android and Linux arm64 builds, made by statically recompiling
the games' own code with [N64Recomp](https://github.com/N64Recomp/N64Recomp). You supply your own
ROMs; nothing from the games is in this repo or downloaded by it.

## Status

**v0.3.0, alpha.** Both games boot, take input, play, and have sound.

| | Rampage: World Tour | Rampage 2: Universal Tour |
|---|---|---|
| Boots to title, attract mode | yes | yes |
| Menus, character select | yes | yes |
| Gameplay (move, climb, punch, eat) | yes | yes (first levels tried) |
| Sound and music | yes | yes |
| Controllers: keyboard and up to 4 pads, configurable | yes | yes |
| Graphics (RT64) at any resolution | yes | yes |
| Controller pak saves | no: the game says no pak is inserted | no |
| Windows 10/11 x64 (D3D12) | yes | yes |
| Linux x64 (Vulkan), macOS on Apple Silicon (Metal) | builds; not yet played on real hardware | same |
| Android, Linux arm64 (made in Docker) | builds; not yet played on real hardware | same |

How the two games are made to work, and what had to be fixed on the way:
[docs/symbols.md](docs/symbols.md) and [docs/game-fixes.md](docs/game-fixes.md).

## Screenshots

| | |
|---|---|
| ![World Tour attract demo](docs/screenshots/wt-demo.png) | ![George climbing](docs/screenshots/wt-climbing.png) |
| *World Tour: attract demo* | *World Tour: George in Peoria* |
| ![Rampage 2 title](docs/screenshots/r2-title.png) | ![Curtis and a helicopter](docs/screenshots/r2-helicopter.png) |
| *Rampage 2: title* | *Rampage 2: Curtis, and trouble* |

All captured from the real build (`--headless` with `RAMPAGE_SHOT`, see [Usage](#usage)).

## Getting Started

You need your own USA ROM of either game as a `.z64` file (big-endian, the usual No-Intro dump:
World Tour CRC `C29FF9E4`, Rampage 2 CRC `673D099B`), about 8 GB of free disk, and one of:

- Windows 10/11 x64 with a DirectX 12 GPU;
- Linux x64 with a Vulkan driver (Debian/Ubuntu, Fedora or Arch: setup uses apt, dnf or pacman);
- macOS on Apple Silicon, with Xcode installed (for its Metal shader compiler).

The Android and Linux arm64 builds are made on any of those, in Docker.

### Installer

Download **Rampage-Installer** for your system from the
[latest release](https://github.com/sp00nznet/Rampage/releases), run it, point it at the folder
with your ROMs, and tick what to build:

- **This computer**: the games for the PC you're on, with a launcher for each.
- **Android**: an `.apk` per game, for arm64 phones and handhelds with Vulkan.
- **Linux arm64**: Raspberry Pi 5 and other arm64 Linux with Vulkan.

Android and Linux arm64 are built in Docker (Docker Desktop on Windows and macOS; on Windows the
installer offers to install it), and only the toolchains for what you tick are downloaded.
[docs/other-builds.md](docs/other-builds.md) says how to put them on the device.

### Quick start, without the installer

1. Download this repo ([Code → Download ZIP](https://github.com/sp00nznet/Rampage/archive/refs/heads/main.zip))
   and unzip it anywhere.
2. Put your ROM(s) in that folder. Any file name works.
3. Run setup. It checks for the build tools and asks before installing any that are missing, then
   downloads the recompiler, runtime and renderer, recompiles your ROMs and builds the games. The
   first run takes 20 to 60 minutes; a rerun after a failure picks up where it stopped. If it
   stops, it says why in one sentence; the full log is `logs/setup.log`.
   - Windows: double-click **`Setup.cmd`** (Git, Python, CMake and Visual Studio's C++ build tools
     come from winget).
   - Linux and macOS: `./setup.sh` (packages from apt, dnf or pacman, or Homebrew).
   - To also make the other builds: `powershell -File tools\setup.ps1 -Targets pc,android,linux-arm64`
     on Windows, `./setup.sh --targets pc,android,linux-arm64` elsewhere.
4. Start **`Rampage World Tour (recomp)`** or **`Rampage 2 Universal Tour (recomp)`** (`.cmd` on
   Windows, `.sh` on Linux, `.command` on macOS).

### Step by step (Windows)

Each command runs in the repo folder (`setup.sh` is these steps for Linux and macOS). Expected output is shown where it tells you something.

1. Install the prerequisites: [Git](https://git-scm.com/), [Python 3.10+](https://www.python.org/)
   (the `py` launcher), [CMake 3.20+](https://cmake.org/), and Visual Studio 2022 (or its Build
   Tools) with the **Desktop development with C++** workload. Open a new terminal afterwards so
   `PATH` is current.
2. Get the toolkits. Rampage builds against sp00nznet's forks, each carrying fixes it needs (and has
   sent upstream as PRs, listed in [docs/building.md](docs/building.md)):
   ```
   git clone --recurse-submodules -b fix/fallthrough-tail-call https://github.com/sp00nznet/N64Recomp deps\N64Recomp
   git clone --recurse-submodules -b rampage https://github.com/sp00nznet/N64ModernRuntime deps\N64ModernRuntime
   git clone --recurse-submodules -b rampage https://github.com/sp00nznet/rt64 deps\rt64
   ```
3. Build the recompiler:
   ```
   cmake -S deps\N64Recomp -B deps\N64Recomp\build -G "Visual Studio 17 2022" -A x64
   cmake --build deps\N64Recomp\build --config Release --target N64RecompCLI RSPRecomp
   ```
4. Copy your ROM into the repo folder under the name the game's `.toml` expects:
   `Rampage - World Tour (U) [!].z64` and/or `Rampage 2 - Universal Tour (U) [!].z64`.
5. Recompile it (`wt` for World Tour, `r2` for Rampage 2). This also turns the game's audio
   microcode into C++ (`rsp/aspMain_wt.cpp`):
   ```
   set N64RECOMP=deps\N64Recomp\build\Release\N64Recomp.exe
   py tools\regen.py wt
   ```
   ```
   wt: 77 files in gen/wt, 451 fallthroughs, 0 warnings (full log: gen/wt.log)
   ```
   Rampage 2 prints `r2: 82 files in gen/r2, 420 fallthroughs, 0 warnings`.
6. Build:
   ```
   cmake -S . -B build\wt -G "Visual Studio 17 2022" -A x64 -DRAMPAGE_GAME=wt
   cmake --build build\wt --config Release --parallel
   ```
   The game is `build\wt\Release\RampageWorldTour.exe` (`build\r2\Release\Rampage2.exe` for
   Rampage 2).
7. Run it from the repo folder (it finds the ROM there): `build\wt\Release\RampageWorldTour.exe`.

Usual trip-ups: `python` opening the Microsoft Store means the Store alias is on; use `py`, or
turn the alias off in Settings → Apps → Advanced app settings → App execution aliases. A tool
"not found" right after installing it means the terminal predates the install: open a new one.

## Usage

Each game opens on a small launcher (Play, Settings, Quit). In game, **Esc** or the pad's
Back/Guide button opens the menu: controls, graphics, sound volume, fullscreen. Settings are kept
in `rampage.json` (World Tour) and `rampage2.json` (Rampage 2) in the folder the launcher runs
from.

Default controls:

| N64 | Keyboard | Pad |
|---|---|---|
| Stick | W A S D / arrows | left stick |
| A / B | Enter or Space / Left Shift | A or right trigger / X |
| Start | P or Backspace | Start |
| C buttons | numpad 8 4 6 2 | right stick, Y / B |
| D-pad | I J K L | D-pad |
| Z / L / R | Z / Q / E | left trigger / shoulders |

Player 1 gets the keyboard and the first pad; players 2 and 3 get the next pads plugged in. F11 or
Alt+Enter toggles fullscreen.

For testing and debugging, the exe takes `--play` (straight into the game, no launcher),
`--headless` (the same, and on Windows the window sits off-screen, never on your monitors, and is
still rendered) and these environment variables (`SHOT`, `STACKDUMP`, `WATCH` and `PEEK` are
Windows-only):

| Variable | Does |
|---|---|
| `RAMPAGE_SHOT=10:a.bmp,30:b.bmp` | saves the window to those files at those times (seconds) |
| `RAMPAGE_QUIT_AFTER=40` | quits after that many seconds |
| `RAMPAGE_AUTOPRESS=12:1000,15:8000` | holds N64 buttons (hex mask: 1000 Start, 8000 A) for 0.25 s at those times |
| `RAMPAGE_STACKDUMP=20` | prints every thread's stack at that time, for hangs |
| `RAMPAGE_WATCH=0x801732A0@5` | after 5 s, reports the first write to that RDRAM word and who did it |
| `RAMPAGE_PEEK=0x801732A0,...` | prints those RDRAM words with a stack dump or crash |
| `RAMPAGE_DISPLAY=1` | opens on that monitor |
| `RAMPAGE_AUDIODUMP=out.raw` | also writes the sound as raw 16-bit stereo, for checks without speakers |

```
set RAMPAGE_SHOT=25:demo.bmp
set RAMPAGE_QUIT_AFTER=26
build\wt\Release\RampageWorldTour.exe --headless
```

## Building from source

The step-by-step route above is the build. [docs/building.md](docs/building.md) covers the
toolkit branches, what each step produces, using your own toolkit checkouts, and the generated
code (`gen/`, never committed). [docs/architecture.md](docs/architecture.md) explains how the
pieces fit.

This is a [N64Recomp](https://github.com/N64Recomp/N64Recomp) project in sp00nznet's recomp house
style: the toolkit ships, the generated code never does, and fixes found here go back to the
toolkits as PRs.

Want to help? [CONTRIBUTING.md](CONTRIBUTING.md).

## License

This repo's own code is MIT, see [LICENSE](LICENSE). A built game links
[N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime), which is GPL-3.0, so the exe as a
whole falls under GPL-3.0; N64Recomp and RT64 are MIT, SDL2 zlib. No builds are distributed: you
make your own from your own copy. Rampage is © Midway; none of the games' code or data is here.
