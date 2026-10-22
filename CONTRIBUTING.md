# Contributing

Bug reports, test runs and fixes are welcome.

## Reporting a problem

Open an issue with the game, what you did, what happened, and the console output. A hang is
much easier to find with a stack dump: run with `RAMPAGE_STACKDUMP=<seconds>` set and paste the
`[stack]` lines (README, Usage).

## Changing code

- Never commit anything from the games: no ROMs, nothing from `gen/`, no recompiled or
  disassembled code, no screenshots' source assets. Generated code stays generated.
- Fix the cause, in the right place: a wrong function boundary in the symbol file, a fix inside a
  function as a `[[patches.hook]]` in the game's `.toml`, a whole function in `src/<game>_stubs.c`
  ([docs/game-fixes.md](docs/game-fixes.md)). Something every N64 title could hit belongs in
  N64Recomp, N64ModernRuntime or RT64; open it there, and link it here.
- Check both games still boot and play before sending a change (`--headless` with
  `RAMPAGE_SHOT` and `RAMPAGE_AUTOPRESS` makes that a one-liner).

## Where your code comes from

This repo is MIT. Code derived from a copyleft project can't come in, even rewritten, and that
includes reading one emulator's source and writing "our own" version. The ones most likely to be
open when working on N64 code: **mupen64plus** and its plugins, **Project64**, **simple64**,
**angrylion-rdp**, **GLideN64** and **Starfox64Recomp / Zelda64Recomp** (all GPL). Hardware
documentation (n64brew), measuring the games themselves, and permissively licensed code with its
notice kept (N64Recomp and RT64 are MIT, ares is ISC) are fine. N64ModernRuntime is GPL-3.0: this
repo links it but takes no code from it, and changes to it go to its repo. Say where
unusual knowledge came from in the PR.

AI-assisted contributions are welcome, as long as a person understood and checked the change.
