"""
Fix short fallthrough functions in R2 recompiled code.

N64Recomp splits continuous MIPS at function boundaries. When a function
ends without jr $ra (just falls through to the next), N64Recomp creates
a tiny function (1-3 instructions) that doesn't return. This script
detects these and adds a call to the next function.

Only fixes functions that:
1. Have no 'return;' statement
2. Have no 'goto L_' (no internal branches = no loops)
3. Have <= 6 real instructions
4. Are immediately followed by another RECOMP_FUNC
5. Don't already call the next function
"""
import os
import re
import sys

FUNCS_DIR = os.path.join(os.path.dirname(os.path.dirname(__file__)), 'RecompiledFuncs_R2')

def fix_file(filepath, dry_run=False):
    with open(filepath) as f:
        content = f.read()

    # Find all function boundaries
    func_pattern = re.compile(r'(RECOMP_FUNC void (func_[0-9A-Fa-f]+)\(uint8_t\* rdram, recomp_context\* ctx\) \{)')
    matches = list(func_pattern.finditer(content))

    fixes = []

    for i in range(len(matches) - 1):
        func_start = matches[i].start()
        func_name = matches[i].group(2)
        next_func_start = matches[i + 1].start()
        next_func_name = matches[i + 1].group(2)

        body = content[func_start:next_func_start]

        # Skip if already has return
        if 'return;' in body:
            continue

        # Skip if has internal gotos (loops/branches)
        if re.search(r'goto L_', body):
            continue

        # Skip if already calls the next function
        if next_func_name + '(rdram, ctx)' in body:
            continue

        # KEY CHECK: Only fix if there's no 'jr' instruction in the MIPS comments.
        # A real fallthrough has no jr $ra (return) instruction.
        # Functions that DO have jr $ra but no C 'return;' are just quirks of the
        # decompiler output format — they still return normally.
        if re.search(r'//.*\bjr\b', body):
            continue

        # Count real instructions
        instruction_count = len(re.findall(r'ctx->r\d+\s*=|MEM_[WHBU]', body))
        if instruction_count > 6:
            continue

        # Skip stub functions (empty or just nop)
        if instruction_count == 0:
            continue

        # This is a fallthrough! Find the closing ;} before the next function
        # Look for the pattern: last instruction line, then ;}
        close_pattern = re.compile(r'(;\})\s*$', re.MULTILINE)
        close_match = close_pattern.search(body)
        if not close_match:
            continue

        close_pos = func_start + close_match.start()

        fixes.append({
            'func': func_name,
            'next_func': next_func_name,
            'instructions': instruction_count,
            'insert_pos': close_pos,
            'insert_text': f'    // FALLTHROUGH: {func_name} falls into {next_func_name}\n    {next_func_name}(rdram, ctx);\n'
        })

    if not fixes:
        return 0

    if dry_run:
        for fix in fixes:
            print(f"  {fix['func']} -> {fix['next_func']} ({fix['instructions']} insns)")
        return len(fixes)

    # Apply fixes in reverse order to preserve positions
    for fix in reversed(fixes):
        content = content[:fix['insert_pos']] + fix['insert_text'] + content[fix['insert_pos']:]

    with open(filepath, 'w') as f:
        f.write(content)

    return len(fixes)

def main():
    dry_run = '--dry-run' in sys.argv
    total = 0

    for fname in sorted(os.listdir(FUNCS_DIR)):
        if not fname.startswith('funcs_') or not fname.endswith('.c'):
            continue
        filepath = os.path.join(FUNCS_DIR, fname)
        count = fix_file(filepath, dry_run)
        if count > 0:
            print(f"{fname}: {count} fallthroughs {'found' if dry_run else 'fixed'}")
            total += count

    print(f"\nTotal: {total} fallthroughs {'found' if dry_run else 'fixed'}")

if __name__ == '__main__':
    main()
