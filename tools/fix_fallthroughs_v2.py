#!/usr/bin/env python3
"""
Fix function fallthrough bugs in recompiled code.
Skips funcs_66.c and funcs_67.c (manual stubs).
"""

import re
import os

SEARCH_DIR = r"D:\rampage\RecompiledFuncs_WT"
SKIP_FILES = {'funcs_66.c', 'funcs_67.c', 'funcs_68.c', 'funcs_69.c', 'func_stubs.c'}

def find_and_fix_fallthroughs():
    files = sorted([
        f for f in os.listdir(SEARCH_DIR)
        if re.match(r'funcs_\d+\.c$', f) and f not in SKIP_FILES
    ], key=lambda x: int(re.search(r'(\d+)', x).group(1)))

    all_functions = []

    for fname in files:
        fpath = os.path.join(SEARCH_DIR, fname)
        with open(fpath, 'r') as f:
            lines = f.readlines()

        current_func = None
        func_start_line = None
        has_return = False
        has_call = False

        for i, line in enumerate(lines):
            m = re.match(r'RECOMP_FUNC void (\w+)\(', line)
            if m:
                if current_func:
                    all_functions.append((fname, current_func, func_start_line, has_return, has_call, i - 1))
                current_func = m.group(1)
                func_start_line = i
                has_return = False
                has_call = False
                continue

            if current_func:
                stripped = line.strip()
                if stripped == 'return;':
                    has_return = True
                if re.search(r'\b(func_\w+|[a-zA-Z_]+_recomp)\s*\(rdram', stripped):
                    has_call = True
                if re.search(r'LOOKUP_FUNC\(', stripped):
                    has_call = True
                if re.search(r'pause_self\(', stripped):
                    has_call = True

        if current_func:
            all_functions.append((fname, current_func, func_start_line, has_return, has_call, len(lines) - 1))

    # Find fallthroughs
    fixes = []
    for idx, (fname, func_name, start_line, has_return, has_call, end_line) in enumerate(all_functions):
        if not has_return and not has_call:
            if idx + 1 < len(all_functions):
                next_fname, next_func, _, _, _, _ = all_functions[idx + 1]
                cross_file = fname != next_fname
                fixes.append((fname, func_name, next_func, next_fname, cross_file))

    print(f"Total fallthroughs to fix: {len(fixes)}")

    # Apply fixes
    # Group by file for efficiency
    file_fixes = {}
    for fname, func_name, next_func, next_fname, cross_file in fixes:
        if fname not in file_fixes:
            file_fixes[fname] = []
        file_fixes[fname].append((func_name, next_func, next_fname, cross_file))

    total_fixed = 0
    for fname, func_fixes in file_fixes.items():
        fpath = os.path.join(SEARCH_DIR, fname)
        with open(fpath, 'r') as f:
            content = f.read()

        for func_name, next_func, next_fname, cross_file in func_fixes:
            if f'FALLTHROUGH FIX: {func_name}' in content:
                continue

            if not cross_file:
                # Same-file: find pattern func_name ... ;} RECOMP_FUNC void next_func
                pattern = re.compile(
                    r'(RECOMP_FUNC void ' + re.escape(func_name) + r'\(.*?\n)(.*?)(;\}\nRECOMP_FUNC void ' + re.escape(next_func) + r')',
                    re.DOTALL
                )
            else:
                # Cross-file: find the closing ;} at the end of the function
                # Use a simpler pattern - find the ;} that's right before EOF or another function
                pattern = re.compile(
                    r'(RECOMP_FUNC void ' + re.escape(func_name) + r'\(.*?\n)(.*?)(;\})\s*$',
                    re.DOTALL | re.MULTILINE
                )

            m = pattern.search(content)
            if m:
                body = m.group(2)
                fix_comment = f'    // FALLTHROUGH FIX: {func_name} falls through to {next_func}\n'
                fix_call = f'    {next_func}(rdram, ctx);\n'
                new_body = body + fix_comment + fix_call
                content = content[:m.start(2)] + new_body + content[m.start(3):]
                total_fixed += 1
                xf = " (cross-file)" if cross_file else ""
                print(f"  {func_name} -> {next_func}{xf}")
            else:
                print(f"  WARNING: Could not match {func_name} in {fname}")

        with open(fpath, 'w') as f:
            f.write(content)

    print(f"\nFixed {total_fixed} fallthroughs in {len(file_fixes)} files")

if __name__ == '__main__':
    find_and_fix_fallthroughs()
