#!/usr/bin/env python3
"""Rebuild a symbol file's function boundaries by tracing the code.

    py tools/merge_fragments.py rampage2_ut.toml [--write] [--symbols=<copy.toml>]

The original symbol finder (extract_symbols.py) took every word in .text that decodes as a jal
as a call, data included, and started a new function after every jump. So switch cases, the code
after an early return, and addresses only "data jals" point at came out as separate tiny
functions. N64Recomp emits each as its own C function, and control flow between them breaks:
branches leave the function and code falls off the end.

This traces the code instead:
  - Strong entries are certainly entered from outside: the entrypoint, named symbols, functions
    the game's .toml names, and anything traced code calls (jal) or takes the address of
    (lui + addiu/ori).
  - Weak entries are symbols that open a stack frame (addiu sp, sp, -n): function starts, unless
    they fall inside a strong function's body (code scheduled before the prologue), in which
    case they're merged.
  - Each entry's control flow is walked: branches, jumps and jump tables extend it; it ends at a
    return or tail jump no pending branch skips, or at the next entry.
  - Symbols neither kind of entry covers are traced too, as they stand.
  - A jump or branch to the middle of another function is a shared tail (compilers merge
    identical function endings): its target becomes an entry of its own, so the jump is a tail
    call and the function containing it falls through into it.
Repeats until no new entries appear. Then every entry becomes one function spanning what was
traced; original symbols inside one are dropped; symbols no traced code reaches stay as they were.

Without --write it only reports. --symbols works on a copy of the symbol file instead.
"""
import re
import struct
import sys

SYM_RE = re.compile(r'^(\s*)\{ name = "(\w+)", vram = (0x[0-9A-Fa-f]+), size = (0x[0-9A-Fa-f]+) \},\s*$')
SECTION_RE = re.compile(r'^\s*(rom|vram|size) = (0x[0-9A-Fa-f]+)')
RA = 31
MAX_FUNC = 0x4000  # a branch further than this from its function's start isn't followed


def parse(path):
    """Returns (lines, sections); each section is {rom, vram, size, syms: [(line_no, name, vram, size)]}."""
    lines = open(path).read().split("\n")
    sections = []
    for i, line in enumerate(lines):
        if line.strip() == "[[section]]":
            sections.append({"syms": []})
        elif sections and not sections[-1]["syms"] and (m := SECTION_RE.match(line)):
            sections[-1][m.group(1)] = int(m.group(2), 16)
        elif (m := SYM_RE.match(line)):
            sections[-1]["syms"].append((i, m.group(2), int(m.group(3), 16), int(m.group(4), 16)))
    return lines, sections


def sext16(v):
    return v - 0x10000 if v & 0x8000 else v


class Code:
    def __init__(self, rom, sec):
        self.rom, self.start, self.end = rom, sec["vram"], sec["vram"] + sec["size"]
        self.rom_off = sec["rom"] - sec["vram"]

    def word(self, addr):
        if not (self.start <= addr < self.end):
            return None
        o = addr + self.rom_off
        return struct.unpack(">I", self.rom[o:o + 4])[0]

    def opens_frame(self, addr):
        w = self.word(addr) or 0
        return (w >> 16) == 0x27BD and bool(w & 0x8000)  # addiu sp, sp, -n

    def trace(self, entry, stop):
        """Walks the function at `entry`, which can't extend past `stop` (the next entry).
        Returns (end, calls, constants, outside), `outside` being branch/jump targets that leave
        the function."""
        calls, consts, outside = set(), set(), set()
        reach = entry  # furthest address a branch inside this function targets
        regs = {}      # register -> constant built from a recent lui
        tables = {}    # register -> jump table address its value was loaded from
        cases = None   # entry count from the last bounds check; tables are stored back to back
        pc = entry
        while pc < stop:
            w = self.word(pc)
            if w is None:
                break
            op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
            imm, funct = w & 0xFFFF, w & 63
            target = None
            if op == 3:                                         # jal
                calls.add(((pc + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2))
            elif op == 2:                                       # j
                target = ((pc + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
            elif op in (4, 5, 6, 7, 20, 21, 22, 23) or (op == 1 and rt in (0, 1, 2, 3, 16, 17, 18, 19)) \
                    or (op == 0x11 and rs == 8):                # conditional branches, incl. bc1t/bc1f
                target = pc + 4 + sext16(imm) * 4
            elif op == 0x0B:                                    # sltiu: a switch's bounds check
                cases = imm
            elif op == 0x0F:                                    # lui
                regs[rt] = imm << 16
            elif op in (0x09, 0x0D) and rs in regs:             # addiu / ori completing a constant
                value = (regs[rs] + (sext16(imm) if op == 0x09 else imm)) & 0xFFFFFFFF
                consts.add(value)
                regs[rt] = value
            elif op == 0x23 and rs in regs:                     # lw from a constant: jump table?
                tables[rt] = (regs[rs] + sext16(imm)) & 0xFFFFFFFF
            elif op == 0 and funct == 0x21 and (rs in regs or rt in regs):  # addu keeps a table base
                regs[(w >> 11) & 31] = regs.get(rs, regs.get(rt))
            if op == 0 and funct == 8:                          # jr
                if rs != RA and rs in tables:                   # jump table: read its cases
                    table = tables[rs]
                    limit = table + 4 * (cases or 0x400)
                    while table < limit and (case := self.word(table)) is not None and                             entry <= case < entry + MAX_FUNC and case % 4 == 0 and (cases or case < stop):
                        if case < stop:
                            reach = max(reach, case)
                        else:
                            outside.add(case)
                        table += 4
                elif pc >= reach:                               # nothing jumps past this return
                    return pc + 8, calls, consts, outside
            if target is not None:
                if entry <= target < stop:
                    reach = max(reach, target)
                else:
                    if abs(target - entry) < MAX_FUNC:
                        outside.add(target)
                    if op == 2 and pc >= reach:                 # tail jump out of the function
                        return pc + 8, calls, consts, outside
            pc += 4
        return min(pc, stop), calls, consts, outside


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    if len(args) != 1:
        sys.exit(__doc__)
    config = open(args[0]).read()
    setting = lambda key: re.search(key + r' = "([^"]+)"', config).group(1)
    sym_path, rom = setting("symbols_file_path"), open(setting("rom_file_path"), "rb").read()
    for a in sys.argv:
        if a.startswith("--symbols="):
            sym_path = a.split("=", 1)[1]
    keep = set(re.findall(r'"(func_[0-9A-Fa-f]{8})"', config))
    entrypoint = int(re.search(r"entrypoint = (0x[0-9A-Fa-f]+)", config).group(1), 16)

    lines, sections = parse(sym_path)
    report = []
    replace = {}  # first line of a section's function list -> new lines; other function lines dropped
    for sec in sections:
        if sec.get("rom", 0) == 0 or not sec["syms"]:
            continue  # stub sections have no code to read
        code = Code(rom, sec)
        syms = sorted(sec["syms"], key=lambda s: s[2])
        by_vram = {s[2]: s for s in syms}
        strong = {v for v, s in by_vram.items() if not s[1].startswith("func_") or s[1] in keep or v == entrypoint}
        strong.add(syms[0][2])
        weak = {v for v in by_vram if code.opens_frame(v)}

        def trace_all(heads, stops):
            stops = sorted(stops)
            out = {}
            for e in heads:
                nxt = next((s for s in stops if s > e), code.end)
                out[e] = code.trace(e, nxt)
            return out

        while True:
            traced = trace_all(strong, strong)
            covered = lambda v: any(e < v < r[0] for e, r in traced.items())
            entries = strong | {w for w in weak if not covered(w)}
            traced.update(trace_all(entries - strong, entries))
            # Whatever is still uncovered is traced as-is, so its jumps into neighbours count too.
            rest = {v for v in by_vram if v not in entries and not covered(v)}
            entries |= rest
            traced.update(trace_all(rest, entries))
            found = {c for r in traced.values() for c in r[1] | r[2] if c in by_vram}
            # Shared tails: targets in the middle of another traced function.
            found |= {t for r in traced.values() for t in r[3] if t % 4 == 0 and covered(t)}
            new = found - strong
            if not new:
                break
            strong |= new
        extents = {e: r[0] for e, r in traced.items()}

        # New function list: traced entries, plus original symbols no traced code covers.
        def inside_any(v):
            return any(e <= v < end for e, end in extents.items())
        funcs = {e: [by_vram[e][1] if e in by_vram else f"func_{e:08X}", end - e] for e, end in extents.items()}
        for _, name, vram, size in syms:
            if not inside_any(vram):
                funcs[vram] = [name, size]
        ordered = sorted(funcs)
        for a, b in zip(ordered, ordered[1:]):  # nothing may overlap the next function
            funcs[a][1] = min(funcs[a][1], b - a)
        indent = re.match(r"\s*", lines[syms[0][0]]).group(0)
        replace[syms[0][0]] = [f'{indent}{{ name = "{funcs[v][0]}", vram = 0x{v:08X}, size = 0x{funcs[v][1]:X} }},'
                               for v in ordered]
        replace.update({s[0]: None for s in syms[1:]})

        unreached = sum(1 for s in syms if not inside_any(s[2]))
        added = sum(1 for e in extents if e not in by_vram)
        report.append(f"section 0x{sec['vram']:08X}: {len(syms)} symbols -> {len(ordered)} functions "
                      f"({len(extents)} traced, {added} shared tails split out, {unreached} untouched)")
        referenced = {c for r in traced.values() for c in r[1] | r[2]}
        for name in sorted(keep):
            s = next((s for s in syms if s[1] == name), None)
            if s and s[2] not in referenced:
                report.append(f"  pinned by the .toml, never called: {name}")

    print("\n".join(report))
    if "--write" in sys.argv:
        out = []
        for i, line in enumerate(lines):
            if i not in replace:
                out.append(line)
            elif replace[i] is not None:
                out.extend(replace[i])
        open(sym_path, "w").write("\n".join(out))
        print(f"wrote {sym_path}")


if __name__ == "__main__":
    main()
