#!/usr/bin/env python3
"""Fix fall-through functions in recompiled N64 code.

N64Recomp splits MIPS fall-through functions into separate C functions,
losing the fall-through control flow. This script adds tail calls to
restore the intended behavior.

A fall-through function is one where the MIPS code has no 'jr $ra' and
execution falls through to the next function at the next address.
The fix: add a call to the next function at the end of each fall-through function.
"""

import re
import os
import sys
from pathlib import Path

def find_fallthrough_pairs(directory):
    """Find all fall-through function pairs in .c files."""

    all_pairs = []  # (filepath, func_name, next_func_name)

    for filepath in sorted(Path(directory).glob("funcs_*.c")):
        with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
            content = f.read()

        # Find all RECOMP_FUNC functions
        func_pattern = re.compile(
            r'RECOMP_FUNC void (func_[0-9a-fA-F]+)\(uint8_t\* rdram, recomp_context\* ctx\) \{'
        )

        functions = []
        for match in func_pattern.finditer(content):
            func_name = match.group(1)
            func_addr = int(func_name.replace('func_', ''), 16)
            start_pos = match.start()
            functions.append((func_name, func_addr, start_pos))

        for i, (func_name, func_addr, start_pos) in enumerate(functions):
            if i + 1 >= len(functions):
                continue

            next_func_name, next_func_addr, next_start_pos = functions[i + 1]
            func_body = content[start_pos:next_start_pos]

            # Check if this function has a 'jr' instruction
            has_jr = bool(re.search(r'//.*\bjr\b', func_body))
            if has_jr:
                continue

            # Find all MIPS instruction addresses
            addr_pattern = re.compile(r'// 0x([0-9a-fA-F]+):')
            addrs = [int(m.group(1), 16) for m in addr_pattern.finditer(func_body)]
            if not addrs:
                continue

            last_addr = max(addrs)
            gap = next_func_addr - last_addr

            # Fall-through: next function follows within 8 bytes (instruction + delay slot)
            if gap <= 8:
                all_pairs.append((filepath, func_name, next_func_name))

    return all_pairs


def fix_fallthrough_functions(directory, dry_run=False):
    """Add tail calls to fall-through functions."""

    pairs = find_fallthrough_pairs(directory)

    print(f"Found {len(pairs)} fall-through functions to fix")

    if dry_run:
        for filepath, func_name, next_func in pairs:
            print(f"  {func_name} -> {next_func} ({filepath.name})")
        return pairs

    # Group by file for efficient processing
    by_file = {}
    for filepath, func_name, next_func in pairs:
        if filepath not in by_file:
            by_file[filepath] = []
        by_file[filepath].append((func_name, next_func))

    fixed_count = 0
    for filepath, func_pairs in sorted(by_file.items()):
        with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
            content = f.read()

        original = content

        for func_name, next_func in func_pairs:
            # Find the function body and its closing ;}
            # Pattern: the function body ends with ;\n} before the next RECOMP_FUNC
            # We need to add the tail call before the closing ;}

            # Find the function start
            func_start_pattern = re.compile(
                r'RECOMP_FUNC void ' + re.escape(func_name) + r'\(uint8_t\* rdram, recomp_context\* ctx\) \{'
            )
            match = func_start_pattern.search(content)
            if not match:
                print(f"  WARNING: Could not find {func_name} in {filepath.name}")
                continue

            func_start = match.start()

            # Find the next RECOMP_FUNC after this one
            next_recomp = content.find('RECOMP_FUNC', func_start + 10)
            if next_recomp == -1:
                next_recomp = len(content)

            # Find the closing ;} of this function (last occurrence before next RECOMP_FUNC)
            func_body = content[func_start:next_recomp]

            # The function should end with ;}  (with possible whitespace)
            # Find the last ;} in the function body
            close_pattern = re.compile(r';\s*\}')
            close_matches = list(close_pattern.finditer(func_body))
            if not close_matches:
                print(f"  WARNING: Could not find closing ;}} for {func_name} in {filepath.name}")
                continue

            last_close = close_matches[-1]
            # Insert the tail call before the closing ;}
            insert_pos = func_start + last_close.start()

            # Check if we already added a tail call (idempotency)
            check_region = content[max(0, insert_pos - 200):insert_pos + 10]
            if f'{next_func}(rdram, ctx)' in check_region:
                continue

            # Find the last actual code line before the closing
            # We want to add the tail call after the last ctx->rXX = ... line
            tail_call = f'    {next_func}(rdram, ctx); // fall-through\n'

            content = content[:insert_pos] + tail_call + content[insert_pos:]
            fixed_count += 1

        if content != original:
            with open(filepath, 'w', encoding='utf-8', newline='\n') as f:
                f.write(content)
            print(f"  Fixed {len(func_pairs)} functions in {filepath.name}")

    print(f"\nTotal: Fixed {fixed_count} fall-through functions")
    return pairs


if __name__ == '__main__':
    directory = sys.argv[1] if len(sys.argv) > 1 else os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'RecompiledFuncs_WT')
    dry_run = '--dry-run' in sys.argv

    if dry_run:
        print("DRY RUN - no files will be modified\n")

    fix_fallthrough_functions(directory, dry_run=dry_run)
