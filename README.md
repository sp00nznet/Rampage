# Rampage: World Tour Recompiled

A PC port of **Rampage World Tour** (N64, 1997) and **Rampage 2: Universal Tour** (N64, 1999) using static recompilation via [N64Recomp](https://github.com/Mr-Wiseguy/N64Recomp).

## Current Status

**Work in progress** - The game boots, renders at 60fps, accepts keyboard/controller input, and reaches in-game gameplay.

### What Works
- Full static recompilation of both ROMs (World Tour: 3,736 functions, Rampage 2: 4,788 functions)
- Game boots and renders via RT64 (D3D12/Vulkan)
- Stable 60fps VI refresh rate
- Complete game state progression: title -> instructions -> menus -> character select -> **gameplay**
- Keyboard and controller input fully functional
- SDL2 window with gamepad support
- VI register configuration (400x240 framebuffer, xScale=1.6, double-buffered)

### What Doesn't Work Yet
- Audio (Midway's proprietary SN64 sound engine not yet implemented)
- Graphical artifacts under investigation: the game is 100% software-rendered (CPU renders scene, blits via TextureRect) which is unusual for RT64-based projects. Tile positioning and layering issues are being debugged.
- Controller pak save/load (low-level PFS stubs not implemented)
- 30 ignored functions in World Tour may cause missing functionality

### Rendering Notes
Unlike most N64 games, Rampage World Tour does **not** use RSP 3D triangle rendering. The game performs all scene rendering on the CPU and draws the result to the framebuffer using RDP TextureRect commands (~500+ per frame). This software-rendered approach with a non-standard 400x240 framebuffer presents unique challenges for RT64 integration.

## Screenshots

### In-Game Gameplay
![Gameplay](screenshots/02_gameplay.png)

*George the gorilla in gameplay - buildings, sky, and environment rendering at 60fps. Note viewport alignment issues on the left side.*

### "How to Play" Instructions Screen
![How to Play screen](screenshots/01_title_screen.png)

*The instructions/menu screen with monster artwork.*

## Building

### Requirements
- Windows 10/11
- LLVM/Clang (clang-cl)
- Visual Studio 2022 (for MSVC environment/libraries)
- Ninja build system
- CMake 3.20+
- N64 ROM files (not included)

### Build Steps
```bash
# Full build
cmd.exe /c "D:\rampage\_build_run.bat"

# Clean rebuild
cmd.exe /c "D:\rampage\_build_run.bat" clean
```

The build produces `build/RampageRecompiled.exe`.

### Running
Place your ROM file as `rampage_wt.z64` in the working directory. The game will auto-detect and validate the ROM on first launch.

## Architecture

Built on the [N64ModernRuntime](https://github.com/sonicdcer/N64ModernRuntime) framework (same approach as Zelda 64 Recomp / Quest64 Recomp):

- **N64Recomp** - Static MIPS-to-C recompilation
- **RT64** - N64 RDP GPU emulation via D3D12/Vulkan
- **ultramodern** - N64 OS function reimplementation (threads, scheduling, memory)
- **librecomp** - Runtime for loading and executing recompiled code
- **RmlUi** - Launcher/config UI framework

## Project Structure

```
src/main/          - Entry point, SDL window, audio, game registration
src/game/          - Input, config, controls, debug, recomp APIs
src/ui/            - UI system (RmlUi-based)
RecompiledFuncs_WT/ - 3,736 recompiled World Tour functions
RecompiledFuncs_R2/ - 4,788 recompiled Rampage 2 functions
rsp/               - RSP audio stub (not yet implemented)
symbols/           - Function symbol tables for both ROMs
tools/             - Python utilities for fixing recompilation issues
scripts/           - Build and capture helper scripts
```

## License

This project is for educational and preservation purposes. Original game assets are not included.
