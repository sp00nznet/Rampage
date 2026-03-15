#!/usr/bin/env python3
"""
Fix cross-function goto and fallthrough bugs in R2 recompiled code.

Strategy:
1. Find functions that have `goto after_X` but no matching `after_X:` label
   -> Merge the next function's body into this one (the label is in the next func)
2. Find remaining `goto L_XXXXXXXX` where the label is in another function
   -> Replace with `func_XXXXXXXX(rdram, ctx); return;` if the target addr is a func start
   -> Otherwise replace with call to containing function + return
"""

import re
import os
import sys
from collections import defaultdict

FUNCS_DIR = sys.argv[1] if len(sys.argv) > 1 else r"D:\rampage\RecompiledFuncs_R2"


def parse_functions(funcs_dir):
    """Parse all functions from all .c files, tracking labels and gotos."""
    all_funcs = []  # (filename, func_name, func_addr, start_line, end_line, lines, labels, gotos)
    func_by_addr = {}  # addr -> (filename, func_name)

    for fname in sorted(os.listdir(funcs_dir)):
        if not fname.endswith('.c') or fname == 'func_stubs.c':
            continue
        fpath = os.path.join(funcs_dir, fname)
        with open(fpath, 'r') as f:
            lines = f.readlines()

        func_starts = []
        for i, line in enumerate(lines):
            m = re.match(r'RECOMP_FUNC void (\w+)\(', line)
            if m:
                func_name = m.group(1)
                # Extract address from func name
                addr_match = re.search(r'(?:func_|recomp_entrypoint_main)(\w+)', func_name)
                if func_name == 'recomp_entrypoint':
                    addr = 0x80000400  # entry point
                elif func_name == 'recomp_entrypoint_main':
                    addr = 0x8005C3F0  # main renamed
                elif addr_match and func_name.startswith('func_'):
                    addr = int(func_name[5:], 16)
                else:
                    addr = 0
                func_starts.append((i, func_name, addr))

        for j, (start, func_name, addr) in enumerate(func_starts):
            end = func_starts[j + 1][0] - 1 if j + 1 < len(func_starts) else len(lines) - 1
            func_lines = lines[start:end + 1]

            labels = set()
            gotos = []
            for li, l in enumerate(func_lines):
                lbl = re.match(r'\s*(L_[0-9A-Fa-f]+|after_\d+):', l)
                if lbl:
                    labels.add(lbl.group(1))
                gm = re.search(r'goto (L_[0-9A-Fa-f]+|after_\d+);', l)
                if gm:
                    gotos.append((li, gm.group(1)))

            all_funcs.append((fname, func_name, addr, start, end, func_lines, labels, gotos))
            if addr:
                func_by_addr[addr] = (fname, func_name)

    return all_funcs, func_by_addr


def fix_after_fallthroughs(funcs_dir, all_funcs):
    """Fix functions with goto after_X where the label is in the next function."""
    fixes = []  # (filename, func_name, next_func_name)

    for i, (fname, func_name, addr, start, end, func_lines, labels, gotos) in enumerate(all_funcs):
        # Check for goto after_X with no matching label
        for goto_line, goto_target in gotos:
            if goto_target.startswith('after_') and goto_target not in labels:
                # Find the next function that has this label
                for j in range(i + 1, min(i + 5, len(all_funcs))):
                    next_fname, next_func, _, _, _, _, next_labels, _ = all_funcs[j]
                    if goto_target in next_labels:
                        if fname == next_fname:
                            fixes.append((fname, func_name, next_func))
                        else:
                            fixes.append((fname, func_name, next_func, next_fname))
                        break

    # Deduplicate
    seen = set()
    unique_fixes = []
    for fix in fixes:
        key = (fix[0], fix[1], fix[2])
        if key not in seen:
            seen.add(key)
            unique_fixes.append(fix)

    return unique_fixes


def fix_cross_func_gotos(funcs_dir, all_funcs, func_by_addr):
    """Fix goto L_XXXXXXXX that target labels in other functions."""
    fixes = []  # (filename, line_num_in_file, old_goto, replacement)

    for fname, func_name, addr, start, end, func_lines, labels, gotos in all_funcs:
        for goto_line_offset, goto_target in gotos:
            if goto_target.startswith('after_'):
                continue
            if goto_target in labels:
                continue

            # Extract target address
            if goto_target.startswith('L_'):
                target_addr = int(goto_target[2:], 16)
            else:
                continue

            # Check if target address is a function entry point
            if target_addr in func_by_addr:
                target_fname, target_func = func_by_addr[target_addr]
                replacement = f'{target_func}(rdram, ctx); return;'
                fixes.append((fname, start + goto_line_offset, goto_target, replacement))
            else:
                # Find containing function (largest addr <= target_addr)
                containing = None
                for faddr in sorted(func_by_addr.keys()):
                    if faddr <= target_addr:
                        containing = func_by_addr[faddr]
                    else:
                        break
                if containing:
                    target_fname, target_func = containing
                    replacement = f'{target_func}(rdram, ctx); return;'
                    fixes.append((fname, start + goto_line_offset, goto_target, replacement))

    return fixes


def apply_fallthrough_merges(funcs_dir, fixes):
    """Merge next function's body into current function for fallthrough fixes."""
    # Group by file
    by_file = defaultdict(list)
    for fix in fixes:
        fname = fix[0]
        func_name = fix[1]
        next_func = fix[2]
        by_file[fname].append((func_name, next_func))

    total = 0
    for fname, file_fixes in sorted(by_file.items()):
        fpath = os.path.join(funcs_dir, fname)
        with open(fpath, 'r') as f:
            content = f.read()

        for func_name, next_func in file_fixes:
            if f'// MERGE: {next_func}' in content:
                continue

            # Find the boundary: ;}\nRECOMP_FUNC void next_func(
            # We need to:
            # 1. Remove the ;} closing of func_name
            # 2. Remove the RECOMP_FUNC void next_func(...) { header and variable declarations
            # 3. Insert the body of next_func into func_name

            boundary_pattern = re.compile(
                r'(;\})\s*\n(RECOMP_FUNC void ' + re.escape(next_func) + r'\(uint8_t\* rdram, recomp_context\* ctx\) \{\n'
                r'(?:\s+uint64_t hi = 0, lo = 0, result = 0;\n)?'
                r'(?:\s+int c1cs = 0;\n)?)',
                re.DOTALL
            )

            m = boundary_pattern.search(content)
            if m:
                # Replace boundary with merge comment, removing the function header
                merge_comment = f'    // MERGE: {next_func} merged (fallthrough)\n'
                content = content[:m.start()] + merge_comment + content[m.end():]
                total += 1
                print(f"  Merged {next_func} into {func_name} in {fname}")
            else:
                print(f"  WARNING: Could not find boundary {func_name} -> {next_func} in {fname}")

        with open(fpath, 'w') as f:
            f.write(content)

    return total


def apply_goto_fixes(funcs_dir, fixes):
    """Replace cross-function gotos with function calls."""
    by_file = defaultdict(list)
    for fname, line_num, goto_target, replacement in fixes:
        by_file[fname].append((line_num, goto_target, replacement))

    total = 0
    for fname, file_fixes in sorted(by_file.items()):
        fpath = os.path.join(funcs_dir, fname)
        with open(fpath, 'r') as f:
            lines = f.readlines()

        for line_num, goto_target, replacement in file_fixes:
            old = f'goto {goto_target};'
            if old in lines[line_num]:
                lines[line_num] = lines[line_num].replace(old, f'{replacement} // was goto {goto_target}')
                total += 1
                print(f"  Fixed {fname}:{line_num + 1}: goto {goto_target} -> {replacement}")

        with open(fpath, 'w') as f:
            f.writelines(lines)

    return total


def main():
    print(f"Scanning {FUNCS_DIR}...")
    all_funcs, func_by_addr = parse_functions(FUNCS_DIR)
    print(f"Found {len(all_funcs)} functions, {len(func_by_addr)} with addresses")

    # Step 1: Fix after_X fallthroughs by merging
    print("\n=== Step 1: Fixing after_X fallthroughs ===")
    fallthrough_fixes = fix_after_fallthroughs(FUNCS_DIR, all_funcs)
    print(f"Found {len(fallthrough_fixes)} fallthrough merges needed")
    if fallthrough_fixes:
        merged = apply_fallthrough_merges(FUNCS_DIR, fallthrough_fixes)
        print(f"Applied {merged} merges")

    # Re-parse after merges
    all_funcs, func_by_addr = parse_functions(FUNCS_DIR)

    # Step 2: Fix remaining cross-function gotos
    print("\n=== Step 2: Fixing cross-function gotos ===")
    goto_fixes = fix_cross_func_gotos(FUNCS_DIR, all_funcs, func_by_addr)
    print(f"Found {len(goto_fixes)} cross-function gotos to fix")
    if goto_fixes:
        fixed = apply_goto_fixes(FUNCS_DIR, goto_fixes)
        print(f"Applied {fixed} goto fixes")

    print("\nDone!")


if __name__ == '__main__':
    main()
