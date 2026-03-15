#!/usr/bin/env python3
"""
Fix missing after_X labels in R2 recompiled code.

Pattern: func A has `goto after_X;` right before `;}`, but after_X: is not defined.
This happens because N64Recomp split a function after a JAL (function call).
The delay slot instruction went to func A, the continuation went to func B.

Fix: merge func B into func A and insert `after_X:` at the merge point.
"""

import re
import os
import sys

FUNCS_DIR = sys.argv[1] if len(sys.argv) > 1 else r"D:\rampage\RecompiledFuncs_R2"


def process_file(fpath):
    """Process a single file, fixing missing after_X labels by merging functions."""
    with open(fpath, 'r') as f:
        content = f.read()

    changes = 0
    # Keep iterating until no more fixes needed
    while True:
        lines = content.split('\n')

        # Find functions with missing after_X
        func_ranges = []  # (start_line, func_name)
        for i, line in enumerate(lines):
            m = re.match(r'RECOMP_FUNC void (\w+)\(', line)
            if m:
                func_ranges.append((i, m.group(1)))

        found_fix = False
        for fi in range(len(func_ranges)):
            func_start, func_name = func_ranges[fi]
            func_end = func_ranges[fi + 1][0] if fi + 1 < len(func_ranges) else len(lines)

            # Get labels and gotos in this function
            func_body = lines[func_start:func_end]
            labels = set()
            missing_afters = []

            for li, l in enumerate(func_body):
                lm = re.match(r'\s*(after_\d+):', l)
                if lm:
                    labels.add(lm.group(1))
                gm = re.search(r'goto (after_\d+);', l)
                if gm and gm.group(1) not in labels:
                    # Check if this label might appear later in the function
                    found_later = False
                    for lj in range(li + 1, len(func_body)):
                        if re.match(r'\s*' + re.escape(gm.group(1)) + r':', func_body[lj]):
                            found_later = True
                            break
                    if not found_later:
                        missing_afters.append((li, gm.group(1)))

            if not missing_afters:
                continue

            # We have missing after_X labels - need to merge next function
            if fi + 1 >= len(func_ranges):
                continue

            next_start, next_func = func_ranges[fi + 1]

            # Find the ;} boundary and the next RECOMP_FUNC header
            # Pattern: ;}\nRECOMP_FUNC void next_func(...) {\n    uint64_t...\n    int c1cs...\n
            boundary = re.compile(
                r'(;\})\s*\n'
                r'RECOMP_FUNC void ' + re.escape(next_func) + r'\(uint8_t\* rdram, recomp_context\* ctx\) \{\n'
                r'(?:\s+uint64_t hi = 0, lo = 0, result = 0;\n)?'
                r'(?:\s+int c1cs = 0;\n)?',
                re.DOTALL
            )

            m = boundary.search(content)
            if m:
                # Build the after_X labels we need to insert
                after_labels = '\n'.join(f'    {a}:' for _, a in missing_afters)
                merge_comment = f'    // MERGE: {next_func} merged for after_X labels\n'
                replacement = after_labels + '\n' + merge_comment
                content = content[:m.start()] + replacement + content[m.end():]
                changes += 1
                print(f"  Merged {next_func} into {func_name} ({[a for _, a in missing_afters]})")
                found_fix = True
                break  # Restart since line numbers changed

        if not found_fix:
            break

    if changes > 0:
        with open(fpath, 'w') as f:
            f.write(content)

    return changes


def main():
    total = 0
    for fname in sorted(os.listdir(FUNCS_DIR)):
        if not fname.endswith('.c') or fname == 'func_stubs.c':
            continue
        fpath = os.path.join(FUNCS_DIR, fname)
        n = process_file(fpath)
        if n > 0:
            total += n

    print(f"\nTotal: {total} merges applied")


if __name__ == '__main__':
    main()
