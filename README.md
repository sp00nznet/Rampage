# Rampage Recompiled

A PC port of **Rampage World Tour** (N64, 1997) and **Rampage 2: Universal Tour** (N64, 1999) using static recompilation via [N64Recomp](https://github.com/Mr-Wiseguy/N64Recomp).

## Current Status

### Rampage: World Tour - PLAYABLE
**Phase 5: Runtime Integration** - Fully playable with working controls. Boots, renders at 60fps via RT64 D3D12, accepts keyboard/controller input, and plays through all game states including gameplay.

### Rampage 2: Universal Tour - IN PROGRESS
**Phase 5: Runtime Integration** - Boots successfully, creates all game threads, VI mode active. Currently blocked on game state machine initialization (timer message delivery issue). See [R2 Status](#rampage-2-status) below.

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

## What Works (World Tour)
- Full static recompilation (3,736 functions)
- Game boots and renders via RT64 (D3D12/Vulkan) at 4x native resolution (1600x960)
- Stable 60fps VI refresh rate
- Complete game state progression: title -> instructions -> menus -> character select -> **gameplay**
- **Gameplay controls fully functional** - move, punch, kick, jump, climb buildings
- Keyboard and controller input (SDL2 gamepad support)
- Demo mode plays automatically when idle
- Audio initialization (Midway SN64 engine stubs, audio thread running)
- 418 N64Recomp fallthrough functions automatically fixed
- Render thread race condition resolved

## What Doesn't Work Yet (World Tour)
- **Audio output** - Midway's proprietary SN64 sound engine initialized but no actual sound
- Controller pak save/load (PFS stubs not implemented)

## Rampage 2 Status

R2 support was added on 2026-03-14/15. The build system, recompilation pipeline, and runtime integration are working:

### What Works (R2)
- Full static recompilation (4,788 functions) with 35 OS function interceptors
- N64Recomp re-run with named OS symbols for proper `_recomp` wrappers
- Game boots through osInitialize, creates all threads (boot, game init, scheduler, main loop)
- VI mode set correctly (ctrl=0x320E, 320x240)
- Timer system active (osSetTimer fires at ~77Hz)
- COP0 CU1 bit handling added to librecomp (FPU usable flag)
- 46 cross-function gotos fixed, 17 after_X label merges, 49 function stubs
- 52 hardware register functions in ignored list (SI, RI, PI, VI MMIO)

### What Doesn't Work Yet (R2)
- **Black screen** - VI mode is set but game state machine hasn't progressed to rendering
- Timer messages from osSetTimer don't reach the main game loop thread
- `osSpTaskLoad` interceptor may need address verification
- Many OS functions still unidentified (osJamMesg, osDestroyThread, osContGetReadData, etc.)
- Audio/SN64 stubs not yet applied
- Render thread race condition fix not yet applied

### R2 Known Issues
- `osTvType` set to 0 in librecomp (needed to enable timer/audio init path in R2)
- This affects both games - WT may need conditional handling

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
![Title screen](screenshots/title.png)

### World Tour - Gameplay
![Gameplay](screenshots/gameplay3.png)

*In-game gameplay with George climbing a building, running at 60fps.*

### World Tour - Demo Mode
![Demo mode](screenshots/demo-mode.png)

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
# World Tour
cmd.exe /c "_build_run.bat wt"

# Universal Tour
cmd.exe /c "_build_run.bat r2"

# Clean rebuild (required when switching games)
cmd.exe /c "_build_run.bat clean r2"
```

The build produces `build/RampageRecompiled.exe`.

### Running
Place your ROM file in the working directory:
- World Tour: `rampage_wt.z64` or `Rampage - World Tour (U) [!].z64`
- Universal Tour: `rampage2_ut.z64` or `Rampage 2 - Universal Tour (U) [!].z64`

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
src/main/          - Entry point, SDL window, audio, game registration
src/game/          - Input, config, controls, debug, recomp APIs
src/ui/            - UI system (RmlUi-based)
RecompiledFuncs_WT/ - 3,736 recompiled World Tour functions
RecompiledFuncs_R2/ - 4,788 recompiled Rampage 2 functions
rsp/               - RSP audio stub
symbols/           - Function symbol tables for both ROMs
tools/             - Python utilities for fixing recompilation issues
scripts/           - Build, capture, and diagnostic helper scripts
```

## License

This project is for educational and preservation purposes. Original game assets are not included.
