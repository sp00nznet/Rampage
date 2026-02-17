#!/usr/bin/env python3
"""
find_external_jals.py

Scans N64 ROM code sections for JAL (Jump And Link) instructions whose
target addresses fall OUTSIDE the defined code section.  This helps
identify functions that must be stubbed for N64Recomp.

JAL encoding (MIPS):
  Bits 31-26: opcode = 0b000011 (3)
  Bits 25-0 : instr_index

Target address = (instr_index << 2) | (PC & 0xF0000000)
"""

import struct
import sys
from collections import defaultdict


def analyze_rom(rom_path, code_vram_start, code_vram_end, rom_offset):
    """
    Analyze a ROM for JAL instructions targeting outside the code section.

    Parameters:
        rom_path:        Path to the .z64 ROM file (big-endian)
        code_vram_start: Start of code section in VRAM (inclusive)
        code_vram_end:   End of code section in VRAM (exclusive)
        rom_offset:      ROM file offset where the code section begins
    """
    code_size = code_vram_end - code_vram_start
    num_instructions = code_size // 4

    print(f"  ROM file        : {rom_path}")
    print(f"  Code VRAM range : 0x{code_vram_start:08X} - 0x{code_vram_end:08X}")
    print(f"  Code size       : {code_size:,} bytes ({num_instructions:,} instructions)")
    print(f"  ROM offset      : 0x{rom_offset:X}")
    print()

    with open(rom_path, "rb") as f:
        f.seek(rom_offset)
        code_data = f.read(code_size)

    if len(code_data) < code_size:
        print(f"  WARNING: Only read {len(code_data)} bytes, expected {code_size}")
        num_instructions = len(code_data) // 4

    # Track external JAL targets: target_addr -> list of source PCs
    external_targets = defaultdict(list)
    total_jals = 0
    internal_jals = 0

    for i in range(num_instructions):
        offset = i * 4
        word = struct.unpack(">I", code_data[offset:offset + 4])[0]

        opcode = (word >> 26) & 0x3F
        if opcode != 3:  # Not a JAL
            continue

        total_jals += 1
        pc = code_vram_start + offset

        # Extract target address
        instr_index = word & 0x03FFFFFF
        target = (instr_index << 2) | (pc & 0xF0000000)

        if code_vram_start <= target < code_vram_end:
            internal_jals += 1
        else:
            external_targets[target].append(pc)

    external_count = len(external_targets)
    external_call_count = sum(len(v) for v in external_targets.values())

    print(f"  Total JAL instructions  : {total_jals:,}")
    print(f"  Internal targets        : {internal_jals:,}")
    print(f"  External call sites     : {external_call_count:,}")
    print(f"  Unique external targets : {external_count}")
    print()

    if not external_targets:
        print("  No external JAL targets found.")
        return external_targets

    # Group by address ranges
    ranges = defaultdict(list)
    for addr in sorted(external_targets.keys()):
        if addr < 0x80000000:
            range_name = f"Below KSEG0 (< 0x80000000)"
        elif addr < code_vram_start:
            range_name = f"Before code (0x80000000 - 0x{code_vram_start:08X})"
        elif addr >= code_vram_end and addr < 0x80100000:
            range_name = f"After code  (0x{code_vram_end:08X} - 0x80100000)"
        elif addr >= 0x80100000 and addr < 0x80200000:
            range_name = f"Extended    (0x80100000 - 0x80200000)"
        elif addr >= 0x80200000 and addr < 0x80400000:
            range_name = f"High RAM    (0x80200000 - 0x80400000)"
        elif addr >= 0x80400000 and addr < 0x80800000:
            range_name = f"Very high   (0x80400000 - 0x80800000)"
        elif addr >= 0xA0000000 and addr < 0xC0000000:
            range_name = f"KSEG1 uncached (0xA0000000 - 0xC0000000)"
        else:
            range_name = f"Other       (0x{addr & 0xFFF00000:08X}+)"
        ranges[range_name].append(addr)

    print("  === External JAL Targets Grouped by Address Range ===")
    print()

    for range_name in sorted(ranges.keys()):
        addrs = sorted(ranges[range_name])
        print(f"  [{range_name}] ({len(addrs)} unique targets)")
        for addr in addrs:
            callers = external_targets[addr]
            caller_str = ", ".join(f"0x{c:08X}" for c in callers[:5])
            if len(callers) > 5:
                caller_str += f" ... (+{len(callers) - 5} more)"
            print(f"    0x{addr:08X}  (called {len(callers):>3} time(s))  from: {caller_str}")
        print()

    # Print a sorted flat list for easy copy-paste into recomp config
    print("  === Complete Sorted List of External JAL Targets ===")
    print()
    for addr in sorted(external_targets.keys()):
        call_count = len(external_targets[addr])
        print(f"    0x{addr:08X}  ({call_count} call(s))")
    print()

    return external_targets


def main():
    print("=" * 72)
    print("  N64 ROM External JAL Target Finder")
    print("  Identifies JAL targets outside the main code section")
    print("=" * 72)
    print()

    # --- Rampage World Tour ---
    print("-" * 72)
    print("  RAMPAGE WORLD TOUR (U)")
    print("-" * 72)
    print()
    rwt_targets = analyze_rom(
        rom_path=r"D:\rampage\Rampage - World Tour (U) [!].z64",
        code_vram_start=0x80000400,
        code_vram_end=0x800BE900,
        rom_offset=0x1000,
    )

    # --- Rampage 2 ---
    print("-" * 72)
    print("  RAMPAGE 2 - UNIVERSAL TOUR (U)")
    print("-" * 72)
    print()
    r2_targets = analyze_rom(
        rom_path=r"D:\rampage\Rampage 2 - Universal Tour (U) [!].z64",
        code_vram_start=0x80000400,
        code_vram_end=0x800C26E0,
        rom_offset=0x1000,
    )

    # --- Summary ---
    print("=" * 72)
    print("  SUMMARY")
    print("=" * 72)
    print()
    print(f"  Rampage World Tour : {len(rwt_targets)} unique external JAL targets")
    print(f"  Rampage 2          : {len(r2_targets)} unique external JAL targets")
    print()

    # Find common external targets
    common = set(rwt_targets.keys()) & set(r2_targets.keys())
    if common:
        print(f"  Common external targets between both ROMs: {len(common)}")
        for addr in sorted(common):
            print(f"    0x{addr:08X}")
        print()

    rwt_only = set(rwt_targets.keys()) - set(r2_targets.keys())
    r2_only = set(r2_targets.keys()) - set(rwt_targets.keys())
    if rwt_only:
        print(f"  External targets unique to Rampage World Tour: {len(rwt_only)}")
        for addr in sorted(rwt_only):
            print(f"    0x{addr:08X}")
        print()
    if r2_only:
        print(f"  External targets unique to Rampage 2: {len(r2_only)}")
        for addr in sorted(r2_only):
            print(f"    0x{addr:08X}")
        print()


if __name__ == "__main__":
    main()
