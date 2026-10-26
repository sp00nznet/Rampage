# Symbol files: function boundaries and names

N64Recomp translates one function at a time, so it needs to know where every function starts and
ends (`symbols/*.toml`). Getting that wrong produces C that compiles and then misbehaves in ways
that are expensive to trace. Rampage 2 was stuck at its title screen for months because of it.
This file records what was wrong and how the symbol files are made now.

## Where the first symbol files came from

`tools/extract_symbols.py` guessed boundaries from the ROM: every `jal` target is a function, and
a new function starts after every return or jump. Two things went wrong:

- It scanned all of `.text`, which in these games runs on past the code into data. Data words
  that happen to decode as `jal` became "calls", and their targets became functions.
- Starting a new function after every jump cut switch statements into one tiny function per case,
  and split off the code after an early return.

Rampage 2's file ended up with 1,070 functions eight bytes long. Where one piece runs into the
next, N64Recomp's C returned instead (fixed in the toolkit, below), and branches between the pieces
can't be expressed at all (`[Warn] Function X is branching outside of the function`). The old
build patched about 900 such spots by hand in the committed generated code, and emptied some
switch cases outright.

## The fixes

### Runs off the end: N64Recomp

[sp00nznet/N64Recomp#1](https://github.com/sp00nznet/N64Recomp/pull/1): when a function's end is
reachable, the generator now calls the function that follows (as hardware would fall into it),
and hands `hi`/`lo` over through the context. That covers code placed before a prologue and real
multi-entry functions, which a correct symbol file still has. `tools/regen.py` prints how many it
emitted (`438 fallthroughs` for World Tour).

### Boundaries: `tools/merge_fragments.py`

Traces the code instead of guessing: from entries that are certainly real (the entrypoint, named
functions, anything traced code calls or takes the address of), it follows branches, jumps and
jump tables until a return nothing branches past, and turns everything traced into one function.
Details are in the script's docstring. Points that took a while:

- **Jump tables are stored back to back.** Reading entries until one looks wrong runs into the next
  function's table. The case count comes from the switch's bounds check (`sltiu`).
- **A jump into the middle of another function is a shared tail.** The compiler merges identical
  function endings (several functions end with `j 0x80003E28`, inside a neighbour). The target
  becomes its own function: the jumps are tail calls, and the neighbour falls through into it.
- **`addiu sp, sp, -n` is a strong hint, not proof.** Prologue-opening symbols are function
  starts unless they fall inside a traced function's body; then the real start is a few
  instructions earlier (sometimes the prologue is in a branch delay slot).
- **Unconditional jumps to addresses no entry starts at are internal** (`j` used as a branch).
- **FPU branches (`bc1t`/`bc1f`) are branches** too.

Run on Rampage 2: 3,958 symbols became 3,357 functions, and N64Recomp warns about nothing.

```
py tools/merge_fragments.py rampage2_ut.toml --write
section 0x80000400: 3958 symbols -> 3357 functions (3357 traced, 44 shared tails split out, 0 untouched)
```

World Tour's file was cleaned by hand earlier (`fix_func_boundaries`, since removed) and already
recompiles cleanly; it hasn't been through this tool.

### Names: `tools/apply_n64sym.py`

A named libultra function (`osSendMesg`, `osPiStartDma`, `osContStartReadData`...) is replaced by
the runtime's implementation; an unnamed one is recompiled as game code and talks to hardware that
isn't there. World Tour's file named most of libultra (from n64sym); Rampage 2's named 37
functions, and 11 of those names were wrong:

| Address | Was named | Actually (n64sym) |
|---|---|---|
| 0x80074AD0 / 0x80074D10 | osCreateViManager / osCreatePiManager | swapped |
| 0x80073220 | osAiSetFrequency | sprintf (the old "osAiSetFrequency gets a pointer" bug) |
| 0x800733D0 | osInvalDCache | osContStartReadData |
| 0x80078B0C | osContStartReadData | alResampleParam (an audio function) |
| 0x80070D90 | osPiStartDma | __osInsertTimer |
| 0x8007AF04 | osSpTaskStartGo | __osIdCheckSum |

The runtime was replacing an audio function with a controller read, and the timer queue with a
PI DMA. With the right names (182 added), the scheduler, controller and DMA hacks Rampage 2 needed
are gone.

[n64sym](https://github.com/shygoo/n64sym) is run by hand and its output applied; n64sym itself
isn't part of this repo:

```
n64sym "Rampage 2 - Universal Tour (U) [!].z64" -s -t > r2_n64sym.txt
py tools/apply_n64sym.py rampage2_ut.toml r2_n64sym.txt --write
```

The tool trusts n64sym over existing names that contradict it, skips names n64sym reports at more
than one address (loose matches), skips its data and object-offset labels (`*_data_0010`,
`load_text_00CC`), and folds the matches n64sym prints under its second base guess (`0x70...`)
onto `0x80...`.

Matching World Tour's names against Rampage 2 directly doesn't work: World Tour's libultra was
built unoptimized (arguments spilled to the stack), Rampage 2's optimized.

## World Tour's sound engine: the `.sn64` section

Midway's SN64 sound engine (the sequencer and voice code, with its own copy of libultra's audio
library) is a second code segment World Tour copies from ROM `0xBF500`-`0xD23B0` to `0x801377C0`
at boot (`func_80061794` → `func_80062740`). The first symbol file only had the calls into it, as
stubs. It now has a section of its own:

- `tools/extract_symbols.py` on the segment (`--vram-start 0x801377C0 --rom-offset 0xBF500
  --code-size 0x12620`; code ends at `0x80149DE0`, the rest is its data), then
  `merge_fragments.py` on that section alone: 415 symbols became 379 functions.
- n64sym on a RAM image (the main segment plus this one) named the libultra half (`alSynNew`,
  `alEnvmixerPull`, `_frexpf`, ...). Only the functions that touch hardware are named in the file,
  as `sn64_*` ([game-fixes.md](game-fixes.md)); the rest are recompiled like game code.

`merge_fragments.py` had to learn one thing for it: shared tails are only looked for once no new
callees turn up. Before, a symbol not yet known to be called was traced as a leftover, stopped at
the next leftover symbol, and its branches past that point were taken as jumps into a shared tail.
That cut `_frexpf` in three; the FPU condition flag doesn't survive a cut, so `frexp` negated its
argument and looped forever, and the audio thread with it. Rampage 2's result is unchanged by this.

## Rebuilding Rampage 2's symbol file

From the file as `extract_symbols.py` made it, in this order: rename its `main` symbol to
`game_main` (it would collide with C's `main`), `merge_fragments.py --write`, then
`apply_n64sym.py --write`.
