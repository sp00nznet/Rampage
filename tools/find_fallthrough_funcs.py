#!/usr/bin/env python3
"""Find all fall-through functions in recompiled code.

A fall-through function is one where MIPS code has no 'jr $ra' instruction,
meaning it falls through into the next function at the next address.
The N64Recomp recompiler incorrectly splits these into separate functions,
causing the fall-through logic to be lost (the function just returns).

Detection: Look for RECOMP_FUNC functions that do NOT contain 'jr' in their
MIPS disassembly comments AND are immediately followed by another function
at the next address.
"""

import re
import os
import sys
from pathlib import Path

def find_fallthrough_functions(directory):
    """Find all fall-through functions in .c files in the directory."""

    results = []

    for filepath in sorted(Path(directory).glob("funcs_*.c")):
        with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
            content = f.read()

        # Find all functions with their address ranges
        # Pattern: RECOMP_FUNC void func_XXXXXXXX
        func_pattern = re.compile(r'RECOMP_FUNC void (func_[0-9a-fA-F]+)\(uint8_t\* rdram, recomp_context\* ctx\) \{')

        functions = []
        for match in func_pattern.finditer(content):
            func_name = match.group(1)
            func_addr = int(func_name.replace('func_', ''), 16)
            start_pos = match.start()
            functions.append((func_name, func_addr, start_pos))

        # For each function, find its body and check for 'jr' instruction
        for i, (func_name, func_addr, start_pos) in enumerate(functions):
            # Find the end of this function (next RECOMP_FUNC or end of file)
            if i + 1 < len(functions):
                end_pos = functions[i + 1][2]
                next_func_name = functions[i + 1][0]
                next_func_addr = functions[i + 1][1]
            else:
                end_pos = len(content)
                next_func_name = None
                next_func_addr = None

            func_body = content[start_pos:end_pos]

            # Check if this function has a 'jr' instruction in its MIPS disassembly
            has_jr = bool(re.search(r'//.*\bjr\b', func_body))

            # Check if this function has a branch/jump that goes beyond its own range
            # to the next function (which would indicate intended fall-through)

            if not has_jr and next_func_name:
                # Find all MIPS instruction addresses in this function
                addr_pattern = re.compile(r'// 0x([0-9a-fA-F]+):')
                addrs = [int(m.group(1), 16) for m in addr_pattern.finditer(func_body)]

                if addrs:
                    last_addr = max(addrs)
                    # Check if the next function follows immediately (within 4-8 bytes)
                    gap = next_func_addr - last_addr
                    if gap <= 8:  # Next instruction or delay slot
                        # Count instructions to assess function size
                        num_instrs = len(set(addrs))

                        results.append({
                            'file': filepath.name,
                            'func': func_name,
                            'addr': hex(func_addr),
                            'next_func': next_func_name,
                            'next_addr': hex(next_func_addr),
                            'num_instrs': num_instrs,
                            'gap': gap,
                        })

    return results

if __name__ == '__main__':
    directory = sys.argv[1] if len(sys.argv) > 1 else r'D:\rampage\RecompiledFuncs_WT'

    results = find_fallthrough_functions(directory)

    print(f"Found {len(results)} potential fall-through functions:\n")
    print(f"{'Function':<25} {'Addr':<14} {'Next Function':<25} {'#Instr':<8} {'File'}")
    print("-" * 100)
    for r in results:
        print(f"{r['func']:<25} {r['addr']:<14} {r['next_func']:<25} {r['num_instrs']:<8} {r['file']}")
