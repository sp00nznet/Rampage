# Changelog

All notable changes, newest first. Format: [Keep a Changelog](https://keepachangelog.com/);
versions: [SemVer](https://semver.org/).

## [Unreleased]

## [0.3.0] - 2026-10-26

Sound, Linux and macOS, and Android and Linux arm64 builds, all from one installer.

### Added
- Sound and music in both games. The audio microcode (libultra's stock `aspMain`, in both ROMs)
  is recompiled to C++ by RSPRecomp, and World Tour's sound engine, a second code segment the game
  copies to `0x801377C0`, is recompiled as the `.sn64` section of its symbol file instead of
  stubbed ([docs/symbols.md](docs/symbols.md), [docs/game-fixes.md](docs/game-fixes.md)).
- Linux (Vulkan) and macOS (Metal) builds: `setup.sh` does what `Setup.cmd` does, with
  apt/dnf/pacman or Homebrew.
- Android (`.apk` per game) and Linux arm64 builds, made in Docker: `setup-builds.sh`,
  `tools/setup-builds.ps1`, [docs/other-builds.md](docs/other-builds.md).
- One installer for all of it: recomp-launcher shows **This computer**, **Android** and
  **Linux arm64** to tick; installers for Windows, Linux and macOS on each release.
- A launcher screen and an in-game menu (Esc or the pad's Back): controls, graphics, volume.
- `RAMPAGE_AUDIODUMP`, `--play`.

### Changed
- The window, input, config and renderer hookup are the shared frontend from sp00nznet's Racer
  port (`frontend/`), replacing this repo's Windows-only shell. Settings files are now
  `rampage.json` and `rampage2.json` in the working folder. Esc opens the menu; Start is P or
  Backspace on the keyboard.
- `tools/regen.py` also recompiles the audio microcode, and skips a game whose inputs haven't
  changed. Setup refreshes `deps/` to the pinned toolkit branches on every run.
- Toolkit branches: N64ModernRuntime `rampage` and rt64 `rampage` now include their forks' `main`
  (deterministic mode, the shutdown fix, the Android build).
- CI: a compile check on Linux and macOS.

### Fixed
- `tools/merge_fragments.py` cut functions where a not-yet-traced symbol stopped short; it now
  looks for shared tails only after every callee is known (`frexp` in World Tour's sound engine
  was cut in three and looped forever).
- `osPfsIsPlug` answers "no paks" instead of leaving the registers as they were (both games).
- World Tour: an empty controller slot reads as "no pak" in the game's pak layer, so the game
  keeps its default volumes instead of loading zeros from a save that isn't there.
- Rampage 2: a third busy-wait (for a display list buffer) yields, so the scheduler gets to run.

### Removed
- World Tour's SN64 stubs and the two screen-transition hooks that stood in for the sound engine.

## [0.2.0] - 2026-10-22

Rebuilt on current N64Recomp, N64ModernRuntime and RT64 (sp00nznet's forks), with a new shell of
this project's own. Rampage 2 now plays.

### Added
- Rampage 2: Universal Tour reaches gameplay (it used to hang at a blank title screen).
- `Setup.cmd` quick start: checks and offers to install the prerequisites, finds your ROMs,
  fetches the toolkits, recompiles and builds, and leaves a launcher per game.
- `tools/regen.py`: recompiles a ROM into the gitignored `gen/`.
- `tools/merge_fragments.py`: rebuilds function boundaries by tracing the code
  ([docs/symbols.md](docs/symbols.md)).
- `tools/apply_n64sym.py`: names libultra functions from n64sym's output.
- `--headless`, `RAMPAGE_SHOT`, `RAMPAGE_QUIT_AFTER`, `RAMPAGE_AUTOPRESS` and the stack, watch and
  peek tools for unattended runs and debugging.
- Up to 4 controllers plus keyboard, bindings and graphics options in `rampage.json`.
- `launcher/launcher.json` and the installer workflow for recomp-launcher.
- Docs: architecture, building, symbols, game fixes.

### Changed
- In-game fixes are `[[patches.hook]]` entries in the game's `.toml` and replacement functions in
  `src/*_stubs.c`, instead of edits to generated code.
- Rampage 2's symbol file: fragments merged (3,958 symbols to 3,357 functions), 182 libultra
  functions named, 11 wrong names corrected.
- SDL2 comes from RT64's bundled Windows build; vcpkg is no longer needed.
- Licensed MIT.

### Fixed
- Sprites drawn in COPY mode keep their transparency, by RT64's corrected alpha compare
  ([sp00nznet/rt64#3](https://github.com/sp00nznet/rt64/pull/3)).
- Boot crash in `load_overlays` with symbol-only sections
  ([sp00nznet/N64ModernRuntime#9](https://github.com/sp00nznet/N64ModernRuntime/pull/9)).
- Code running off a function's end is followed instead of skipped
  ([sp00nznet/N64Recomp#1](https://github.com/sp00nznet/N64Recomp/pull/1)).
- Quitting no longer crashes.

### Removed
- Recompiled game code from the repository (and its history): it's generated locally now.
- The UI, launcher, mod and config code taken from Starfox64Recomp (GPL-3.0), and Quest 64's
  patch file. Third-party binaries (n64sym, simple64) and per-session logs.
- Hand-written workarounds that turned out to be symptoms of the symbol file
  ([docs/game-fixes.md](docs/game-fixes.md)).

## [0.1.0] - 2026-06-17

World Tour playable without sound; Rampage 2 boots and renders, hanging at the title. Built on an
older N64ModernRuntime with local patches.
