# Game fixes

What each game needs beyond a correct symbol file ([symbols.md](symbols.md)), and why. Nothing
here edits generated code: in-function fixes are `[[patches.hook]]` entries in the game's `.toml`
(N64Recomp inserts the hook's text before the instruction at `before_vram`), and whole-function
replacements are `ignored` in the `.toml` and written in `src/<game>_stubs.c`. Hooks call helpers
declared in `src/hooks.h`, which the build force-includes into the generated code.

## Both games

| Fix | Where | Why |
|---|---|---|
| RSP audio tasks | `get_rsp_microcode` in `src/main.cpp` | Run by `aspMain`, libultra's audio microcode recompiled to C++ (`rsp/aspMain_<game>.toml`; both games carry the stock copy). Graphics tasks go to RT64. |
| How much sound is queued | `audio_max_queued_frames = 1`, `src/main.cpp` | The mixers ask how much is still queued and mix "a frame minus that". The shared frontend reports up to two frames by default (Racer's need); at that, both Rampage mixers compute a negative count and World Tour hands the AI a buffer with a negative length. Real hardware never reports more than the buffer playing now. |
| `osPfsIsPlug` | stubs file | Answers "no paks" (pattern 0, result 0). Paks aren't emulated; the old no-op left the result and the pattern as whatever was in the registers. |
| libultra internals | stubs file | Functions on N64Recomp's built-in ignore list that recompiled code still calls, but whose callers the runtime bypasses (the VI manager thread, controller pak routines). No-ops, with the first call logged as `[stub] <name>`. |

## Rampage: World Tour

| Fix | Hook / stub | Why |
|---|---|---|
| `osTvType = 0` | `on_game_init`, `src/main.cpp` | World Tour only starts its timer and audio threads on this path. It picks its NTSC video mode regardless. |
| Register the sound engine's code | `load_overlays` in `on_game_init`, `src/main.cpp` | The SN64 engine (symbols: `.sn64`, [symbols.md](symbols.md)) always sits at `0x801377C0`, but the game copies it there in pieces, which the runtime doesn't take as loading the section. Its functions are reached through pointers too, so it's registered up front. |
| The engine's own libultra calls | `sn64_*` in `src/wt_stubs.c` | The `.sn64` segment links its own `osAiSetFrequency`, `osAiSetNextBuffer`, `osAiGetLength`, `__osAiDeviceBusy`, `__osDisableInt` and `__osRestoreInt`, which poke hardware registers. Named as themselves they would clash with the main segment's copies, so they're named `sn64_*`, ignored, and forwarded to the runtime. |
| No pak in an empty slot | hook in `func_80062CC8` at `0x80062D08` → `wt_no_pak` | Records `PFS_ERR_NOPACK` as an empty slot's error (`0x8010CE68 + channel * 0x90`, `+0x6C`), as `osPfsInitPak` would. Left at 0, the game's pak layer reports success for the empty slot, "loads" an all-zero save record and applies its settings: music and effects volume 0, a silent game. |
| Graphics task NULL guards | three hooks in `func_800611A0` | The scheduler can run the task builder before its task pointer is set. |
| Button maps | hooks in `func_80068D0C` → `wt_write_button_maps` | State transitions clear the per-player maps (`0x80085BF0` on); they're rewritten every frame, and player 1 is treated as active so its map is used in gameplay. |
| SI and PI access queues | `__osSiCreateAccessQueue_recomp` etc. in `src/wt_stubs.c` | World Tour's own copies of these are recompiled and wait on the queues, so the queues get their token. |

## Rampage 2: Universal Tour

| Fix | Hook / stub | Why |
|---|---|---|
| Yield while waiting for the frame | hook in `func_8005E520` at `0x8005E5E8` | The main loop polls `0x801732A0` until the scheduler marks the last frame done. ultramodern only switches threads when one blocks or yields ([architecture.md](architecture.md)), so the scheduler never ran. The old build forced the flag to 1 instead. |
| Yield while waiting for an RSP slot | hook in `func_8005C95C` at its start | Same shape: polls `0x8016AB70`. |
| Yield while waiting for a display list buffer | hook in `func_8005E398` at `0x8005E3A8` | Same shape: retries `func_8005C838` until the scheduler frees one of two buffers. Only yields when it has to wait (yielding before the first try let the scheduler send a frame whose list wasn't built yet). Shows up once audio tasks take real time. |
| 64-bit math helpers | `ignored` (`__divdi3_recomp` and two more) | The runtime provides them; N64Recomp renames these to `*_recomp` before applying the ignore list, hence the suffix. |

Everything else the old Rampage 2 build patched by hand turned out to come from its symbol file:
the controller-init redirect, the synchronous DMA override, `osSpTaskStartGo`, the thread priority
juggling, the RCP register stubs and the cross-function branch rewrites. With correct boundaries
and names none of them is needed, and the game reaches gameplay.

## Removed from the old build

Kept here so nobody re-adds them: the SN64 entry-point stubs and World Tour's two
screen-transition hooks (resetting render state on a state change, forcing the fade flag at
`0x800BF7A4`), which stood in for the sound engine's callbacks before it was recompiled; per-frame
diagnostic `fprintf`s inside game functions, the
`osTvType` override in the runtime itself (now per game), RT64's unconditional COPY-mode alpha
discard (now RT64's correct rule, [sp00nznet/rt64#3](https://github.com/sp00nznet/rt64/pull/3)),
and `patches/` (Quest 64's patch file, unused).
