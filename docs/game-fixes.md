# Game fixes

What each game needs beyond a correct symbol file ([symbols.md](symbols.md)), and why. Nothing
here edits generated code: in-function fixes are `[[patches.hook]]` entries in the game's `.toml`
(N64Recomp inserts the hook's text before the instruction at `before_vram`), and whole-function
replacements are `ignored` in the `.toml` and written in `src/<game>_stubs.c`. Hooks call helpers
declared in `src/hooks.h`, which the build force-includes into the generated code.

## Both games

| Fix | Where | Why |
|---|---|---|
| SN64 audio entry points | `stubs`/`ignored` in the `.toml`, C in the stubs file | Midway's sound engine is loaded into RAM at run time and isn't recompiled. The stubs report sizes, copy the sound banks the game asks for (`sn64_rom_to_rdram`), and otherwise do nothing, so the games boot and run silently. |
| RSP audio tasks | `get_rsp_microcode` in `src/main.cpp` | Acknowledged without running; graphics tasks go to RT64. |
| libultra internals | stubs file | Functions on N64Recomp's built-in ignore list that recompiled code still calls, but whose callers the runtime bypasses (the VI manager thread, controller pak routines). No-ops, with the first call logged as `[stub] <name>`. |

## Rampage: World Tour

| Fix | Hook / stub | Why |
|---|---|---|
| `osTvType = 0` | `on_game_init`, `src/main.cpp` | World Tour only starts its timer and audio threads on this path. It picks its NTSC video mode regardless. |
| Reset render state when the screen changes | hook in `func_800376AC` at `0x800376C8` → `wt_on_state` | Clears the texture-table and transition flags (`0x800BFE96`, `0x800BFE8E`, `0x800BED98`) and blanks both framebuffers. Without the SN64 callbacks, transitions leave the last screen behind. |
| Force the fade flag | hook at `0x8003779C` → `wt_force_fade_flag` | The SN64 audio timer sets `0x800BF7A4`; without it fades never finish and the screen stays black. |
| Graphics task NULL guards | three hooks in `func_800611A0` | The scheduler can run the task builder before its task pointer is set. |
| Button maps | hooks in `func_80068D0C` → `wt_write_button_maps` | State transitions clear the per-player maps (`0x80085BF0` on); they're rewritten every frame, and player 1 is treated as active so its map is used in gameplay. |
| SI and PI access queues | `__osSiCreateAccessQueue_recomp` etc. in `src/wt_stubs.c` | World Tour's own copies of these are recompiled and wait on the queues, so the queues get their token. |

The addresses in the first two rows are what the old build actually used. Its comments said
`0x800CBE96` / `0x800CB7A4`, but its code computed `0x800C0000 - 0x16A` and friends.

## Rampage 2: Universal Tour

| Fix | Hook / stub | Why |
|---|---|---|
| Yield while waiting for the frame | hook in `func_8005E520` at `0x8005E5E8` | The main loop polls `0x801732A0` until the scheduler marks the last frame done. ultramodern only switches threads when one blocks or yields ([architecture.md](architecture.md)), so the scheduler never ran. The old build forced the flag to 1 instead. |
| Yield while waiting for an RSP slot | hook in `func_8005C95C` at its start | Same shape: polls `0x8016AB70`. |
| 64-bit math helpers | `ignored` (`__divdi3_recomp` and two more) | The runtime provides them; N64Recomp renames these to `*_recomp` before applying the ignore list, hence the suffix. |

Everything else the old Rampage 2 build patched by hand turned out to come from its symbol file:
the controller-init redirect, the synchronous DMA override, `osSpTaskStartGo`, the thread priority
juggling, the RCP register stubs and the cross-function branch rewrites. With correct boundaries
and names none of them is needed, and the game reaches gameplay.

## Removed from the old build

Kept here so nobody re-adds them: per-frame diagnostic `fprintf`s inside game functions, the
`osTvType` override in the runtime itself (now per game), RT64's unconditional COPY-mode alpha
discard (now RT64's correct rule, [sp00nznet/rt64#3](https://github.com/sp00nznet/rt64/pull/3)),
and `patches/` (Quest 64's patch file, unused).
