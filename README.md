# Rampage Recompiled

A PC port of **Rampage World Tour** (N64, 1997) and **Rampage 2: Universal Tour** (N64, 1999) using static recompilation via [N64Recomp](https://github.com/Mr-Wiseguy/N64Recomp).

## Current Status

### Rampage: World Tour - PLAYABLE
Fully playable at 60fps. All game states work: title screen, menus, character select, and gameplay. Keyboard and controller input, demo mode, ImGui menu bar. No audio output yet (SN64 engine stubbed).

### Rampage 2: Universal Tour - BOOTING (WIP)
Boots, loads assets, enters the main game loop. Currently rendering a black screen while the game state machine initializes. See [R2 Status](#rampage-2-universal-tour) for details.

## What Works (World Tour)

- Full static recompilation of all 3,736 game functions
- Renders via RT64 (D3D12/Vulkan) at 4x native resolution (1600x960) at 60fps
- Complete game state progression: title -> instructions -> menus -> character select -> **gameplay**
- **Gameplay controls fully functional** - move, punch, kick, jump, climb buildings
- Keyboard and controller input via SDL2
- Demo mode plays automatically when idle at title screen
- Audio initialization (Midway SN64 engine thread running, stubs in place)
- 418 N64Recomp fallthrough functions automatically fixed
- Render thread race condition resolved with NULL guards
- Fade transitions working (audio timer flag bypass)
- Sprite transparency fixed (COPY mode alpha discard in RT64 shaders)
- ImGui menu bar via RT64 Inspector (File/Config/About)

## What Doesn't Work Yet (World Tour)

- **Audio output** - Midway's proprietary SN64 sound engine is initialized but produces no sound
- Controller pak save/load (PFS stubs not implemented)
- Minor vi_thread_func crash on some frames (game recovers)

## Rampage 2: Universal Tour

R2 uses the same build system and runtime as World Tour with game-specific fixes.

### What Works (R2)

- Full static recompilation of 4,788 game functions with 35 named OS function interceptors
- Game boots through osInitialize, creates all 4 threads (boot, scheduler, main loop, idle)
- **PI DMA system working** - synchronous DMA override bypasses stubbed osCreatePiManager
- **2MB initial ROM load** - R2's code+data segment is 2MB (vs 1MB for WT)
- Resource system initialized - 20+ compressed assets loaded and decompressed via LZSS
- Timer system active (osSetTimer fires at 60Hz)
- Game state machine set to initial state function
- Thread 2 render loop running with cooperative scheduling yield
- 2 critical fallthrough functions manually fixed (resource init, frame processing)
- 46 cross-function gotos fixed, 17 after_X label merges, 49 function stubs
- 52 hardware register functions in ignored list

### What Doesn't Work Yet (R2)

- **Black screen** - render loop is active but not yet submitting RSP display list tasks
- ~879 potential 2-instruction fallthrough functions need systematic fixing
- Audio/SN64 stubs not yet applied for R2
- Gameplay controls mapping not yet configured
- Many game-specific data structures still being reverse-engineered

## Default Controls

| Key | N64 Button | Gameplay Action |
|-----|-----------|-----------------|
| Enter | START | Pause/Start |
| Space | A | Punch |
| Left Shift | B | Kick |
| WASD | Analog Stick | Move |
| Arrow Keys | C Buttons | Jump (C-Down) |
| IJKL | D-Pad | Direction |

## Screenshots

### World Tour - Title Screen
![Title screen](title.png)

### World Tour - Gameplay
![Gameplay](gameplay3.png)

*In-game gameplay with George climbing a building, running at 60fps.*

### World Tour - Demo Mode
![Demo mode](demo-mode.png)

## Dual-ROM Build System

Both games build from the same codebase with compile-time ROM selection:

```bash
# Build World Tour (default)
cmd.exe /c "_build_run.bat wt"

# Build Universal Tour
cmd.exe /c "_build_run.bat r2"

# Clean rebuild (required when switching games)
cmd.exe /c "_build_run.bat clean r2"
```

The build produces `build/RampageRecompiled.exe`.

## Building

### Requirements
- Windows 10/11
- LLVM/Clang (clang-cl)
- Visual Studio 2022 (for MSVC environment/libraries)
- Ninja build system
- CMake 3.20+
- N64 ROM files (not included)

### Running
Place your ROM file in the working directory:
- World Tour: `Rampage - World Tour (U) [!].z64`
- Universal Tour: `Rampage 2 - Universal Tour (U) [!].z64`

The game will auto-detect and validate the ROM on first launch.

## Architecture

Built on the [N64ModernRuntime](https://github.com/sonicdcer/N64ModernRuntime) framework:

- **N64Recomp** - Static MIPS-to-C recompilation
- **RT64** - N64 RDP GPU emulation via D3D12/Vulkan
- **ultramodern** - N64 OS function reimplementation (threads, scheduling, memory)
- **librecomp** - Runtime for loading and executing recompiled code
- **Dear ImGui** - Menu bar overlay via RT64's built-in Inspector

## Project Structure

```
src/main/           - Entry point, SDL window, audio, game registration
src/game/           - Input, config, controls, debug, recomp APIs
src/ui/             - UI system (RmlUi-based, currently stubbed)
RecompiledFuncs_WT/ - 3,736 recompiled World Tour functions
RecompiledFuncs_R2/ - 4,788 recompiled Rampage 2 functions
rsp/                - RSP audio stub
symbols/            - Function symbol tables for both ROMs
tools/              - Python utilities for fixing recompilation issues
scripts/            - Build, capture, and diagnostic helper scripts
```

## License

This project is for educational and preservation purposes. Original game assets are not included.
