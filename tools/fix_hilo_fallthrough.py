#!/usr/bin/env python3
"""Fix hi/lo register persistence across fall-through function boundaries.

In MIPS, the HI/LO registers (used by mult/div) persist across all instructions.
N64Recomp declares them as local variables in each function, initialized to 0.
When a fall-through function computes hi/lo and the next function reads them
via mfhi/mflo, the values are lost because each function has its own locals.

Fix strategy:
1. Before every fall-through tail call, save hi/lo to ctx->hi/ctx->lo
2. In every function, initialize hi/lo from ctx instead of 0

This ensures hi/lo values propagate correctly across fall-through boundaries
while being harmless for normal function calls (since those compute hi/lo
locally before using them).
"""

import re
import sys
import os
import glob

def fix_file(filepath):
    with open(filepath, 'r') as f:
        content = f.read()

    original = content
    changes = 0

    # Fix 1: Change "uint64_t hi = 0, lo = 0, result = 0;"
    # to "uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;"
    old_init = "uint64_t hi = 0, lo = 0, result = 0;"
    new_init = "uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;"
    count = content.count(old_init)
    if count > 0:
        content = content.replace(old_init, new_init)
        changes += count

    # Fix 2: Before every "// fall-through" tail call, save hi/lo to ctx
    # Pattern: "    func_XXXXXXXX(rdram, ctx); // fall-through"
    # Replace with: "    ctx->hi = hi; ctx->lo = lo;\n    func_XXXXXXXX(rdram, ctx); // fall-through"
    pattern = r'(    )(func_[0-9a-fA-F]+\(rdram, ctx\); // fall-through)'

    def add_hilo_save(match):
        indent = match.group(1)
        call = match.group(2)
        return f"{indent}ctx->hi = hi; ctx->lo = lo;\n{indent}{call}"

    new_content = re.sub(pattern, add_hilo_save, content)
    ft_changes = len(re.findall(pattern, content))
    if ft_changes > 0:
        content = new_content
        changes += ft_changes

    if content != original:
        with open(filepath, 'w') as f:
            f.write(content)
        return changes, count, ft_changes
    return 0, 0, 0

def main():
    if len(sys.argv) > 1:
        base_dir = sys.argv[1]
    else:
        base_dir = r'D:\rampage\RecompiledFuncs_WT'

    files = sorted(glob.glob(os.path.join(base_dir, 'funcs_*.c')))
    total_init = 0
    total_ft = 0
    total_files = 0

    for filepath in files:
        changes, init_count, ft_count = fix_file(filepath)
        if changes > 0:
            fname = os.path.basename(filepath)
            print(f"  {fname}: {init_count} init fixes, {ft_count} fall-through saves")
            total_init += init_count
            total_ft += ft_count
            total_files += 1

    print(f"\nTotal: {total_init} hi/lo initializers fixed, {total_ft} fall-through saves added across {total_files} files")

if __name__ == '__main__':
    main()
