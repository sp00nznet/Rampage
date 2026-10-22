#!/usr/bin/env python3
"""Name a game's libultra functions from n64sym's output.

    n64sym "<rom>.z64" -s -t > r2_n64sym.txt          (n64sym: github.com/shygoo/n64sym)
    py tools/apply_n64sym.py rampage2_ut.toml r2_n64sym.txt [--write]

n64sym recognises library functions by signature. Named, they are replaced by the runtime's own
implementations (N64Recomp's reimplemented and ignored lists) instead of being recompiled as game
code that expects real hardware. Every func_XXXXXXXX symbol starting at an address n64sym names is
renamed. The game's .toml is updated to match: renamed functions leave its ignored and stubs lists
(the runtime provides them now) and hook entries follow the new name. n64sym itself is not part
of this repo; its output is a one-off input, and the result lives in the symbol file.
"""
import re
import sys


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    if len(args) != 2:
        sys.exit(__doc__)
    config_path, n64sym_path = args
    config = open(config_path).read()
    sym_path = re.search(r'symbols_file_path = "([^"]+)"', config).group(1)
    symbols = open(sym_path).read()

    # n64sym reports matches under two base guesses for a ROM, 0x80000000 and 0x70000000; some
    # only show up under one. Both are the same code, so fold the 0x70... ones onto 0x80...
    found, seen = {}, {}
    for line in open(n64sym_path):
        parts = line.split()
        if len(parts) == 2 and parts[0][:2] in ("70", "80"):
            addr = int(parts[0], 16)
            addr += 0x10000000 if addr >> 28 == 7 else 0
            if found.get(addr) != parts[1]:
                seen[parts[1]] = seen.get(parts[1], 0) + 1
            found.setdefault(addr, parts[1])
    # A name reported at more than one address is a loose match (e.g. __osCleanupThread a word
    # apart); trust only unique ones.
    found = {a: n for a, n in found.items() if seen[n] == 1}

    # Only functions: n64sym also labels data, and the RSP microcode linked after the CPU code
    # (rspbootTextStart onwards) marks where code ends.
    code_end = min([a for a, n in found.items() if n.endswith("TextStart")] or [0xFFFFFFFF])
    found = {a: n for a, n in found.items() if a < code_end and
             not re.search(r"_(text|data|rodata|bss)_[0-9A-F]{4}$|(Text|Data)Start$", n)}

    sym_re = re.compile(r'\{ name = "(\w+)", vram = (0x[0-9A-Fa-f]+), size = (0x[0-9A-Fa-f]+) \}')

    # Names the symbol file already has but n64sym contradicts (it names that address something
    # else, or finds that name elsewhere) were guesses; a signature match beats them. Reset them.
    # Rampage 2's file had osCreateViManager/osCreatePiManager swapped and osAiSetFrequency on
    # sprintf, among others, and the runtime then replaced the wrong functions.
    by_name = {n: a for a, n in found.items()}
    reset = []
    for m in list(sym_re.finditer(symbols)):
        name, addr = m.group(1), int(m.group(2), 16)
        if name.startswith(("func_", "stub_")) or not (0x80000400 <= addr < code_end):
            continue
        if (addr in found and found[addr] != name) or (name in by_name and by_name[name] != addr):
            symbols = symbols.replace(f'name = "{name}", vram = {m.group(2)}', f'name = "func_{addr:08X}", vram = {m.group(2)}', 1)
            reset.append(f"{name}@{addr:08X}")

    existing = set(re.findall(r'name = "(\w+)"', symbols))
    renamed, split, missing = {}, [], []
    for addr, name in sorted(found.items()):
        old = f"func_{addr:08X}"
        if name in existing:
            continue
        if f'name = "{old}"' in symbols:
            symbols = symbols.replace(f'name = "{old}"', f'name = "{name}"', 1)
            renamed[old] = name
            existing.add(name)
            continue
        # Inside another symbol: the library function's start is a real boundary, so split there.
        outer = next((m for m in sym_re.finditer(symbols)
                      if int(m.group(2), 16) < addr < int(m.group(2), 16) + int(m.group(3), 16)), None)
        if outer is None:
            missing.append(f"{name}@{addr:08X}")
            continue
        start, end = int(outer.group(2), 16), int(outer.group(2), 16) + int(outer.group(3), 16)
        indent = symbols[symbols.rfind("\n", 0, outer.start()) + 1:outer.start()]
        symbols = (symbols[:outer.start()] +
                   f'{{ name = "{outer.group(1)}", vram = 0x{start:08X}, size = 0x{addr - start:X} }},\n' +
                   f'{indent}{{ name = "{name}", vram = 0x{addr:08X}, size = 0x{end - addr:X} }}' +
                   symbols[outer.end():])
        split.append(f"{name}@{addr:08X} (split from {outer.group(1)})")
        existing.add(name)

    for old, name in renamed.items():
        config = re.sub(rf'\n\s*"{old}",', "", config)                 # ignored / stubs lists
        config = config.replace(f'func = "{old}"', f'func = "{name}"')  # hooks

    for old, name in renamed.items():
        print(f"{old} -> {name}")
    print("\n".join(split))
    print(f"reset {len(reset)} contradicted names: {' '.join(reset)}")
    print(f"{len(renamed)} renamed, {len(split)} split out; not in any function: {' '.join(missing)}")
    if "--write" in sys.argv:
        open(sym_path, "w").write(symbols)
        open(config_path, "w").write(config)
        print(f"wrote {sym_path} and {config_path}")


if __name__ == "__main__":
    main()
