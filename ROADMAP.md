# Roadmap

## Next

- **Sound.** Recompile Midway's SN64 engine, which the games load into RAM: find its ROM range and
  load address, add it as a section to the symbol files, and run the RSP audio microcode (N64Recomp's
  RSPRecomp) instead of dropping audio tasks.
- **World Tour through `merge_fragments.py` and `apply_n64sym.py`.** Its symbol file was cleaned
  by hand and works, but hasn't had the traced boundaries or a fresh n64sym pass. Then drop any of
  its hooks that turn out to be symptoms, as happened with Rampage 2.
- **Play both games further.** Only the first levels have been tried; multiplayer (2 and 3
  players) hasn't been tested.
- **netlab.** An N64 builder (DXC, an MSVC-built SDL2) and a test VM with a GPU, so builds and
  headless runs move off the workstation.

## Later

- Controller pak saves (both games ask for one): emulate the pak, or save through EEPROM-style
  files.
- Proper raw SI emulation (a PIF answering the game's own command blocks), so titles whose
  controller code isn't libultra's still get input. Racer would use it too: a toolkit candidate.
- Shut ultramodern down in an order that stops game threads before RDRAM goes, and drop the
  quit-time fault guard in `src/main.cpp`; the same for RT64's destructor crash.
- Linux build.
- Merge the fork branches back to the forks' `main` once their PRs land, and offer the generic
  ones upstream.

## Out of scope

- Distributing anything from the games: ROMs, generated code, or builds made from them.
- The RmlUi launcher and mod menu the old build carried (Starfox64Recomp's, GPL-3.0). A menu, if
  it comes back, gets written fresh.
