"""Find all cross-function goto labels in recompiled C files and fix them.

For each goto L_XXXXXXXX where the label doesn't exist in the same function,
check what instruction is at that address. If it's a 'jr $ra' (return),
replace the goto with 'return;'.
"""
import re
import os
import sys
from collections import defaultdict

FUNCS_DIR = sys.argv[1] if len(sys.argv) > 1 else r"D:\rampage\RecompiledFuncs_WT"

def find_all_labels_and_gotos(funcs_dir):
    """Find all label definitions and goto targets across all .c files."""
    # Map: label -> list of (file, line_num) where it's defined
    label_defs = defaultdict(list)
    # Map: label -> list of (file, line_num, line_content) where it's used in goto
    goto_uses = defaultdict(list)

    for fname in sorted(os.listdir(funcs_dir)):
        if not fname.endswith('.c'):
            continue
        fpath = os.path.join(funcs_dir, fname)
        with open(fpath, 'r') as f:
            lines = f.readlines()

        # Track which function we're in
        current_func = None
        func_labels = set()
        func_gotos = []

        for i, line in enumerate(lines, 1):
            # Check for function definition
            func_match = re.match(r'RECOMP_FUNC void (\w+)\(', line)
            if func_match:
                # Process previous function
                if current_func and func_gotos:
                    for goto_label, goto_line, goto_content in func_gotos:
                        if goto_label not in func_labels:
                            goto_uses[goto_label].append((fname, goto_line, goto_content.strip(), current_func))

                current_func = func_match.group(1)
                func_labels = set()
                func_gotos = []

            # Check for label definition
            label_def = re.match(r'\s*(L_[0-9A-Fa-f]+):', line)
            if label_def:
                label_name = label_def.group(1)
                func_labels.add(label_name)
                label_defs[label_name].append((fname, i))

            # Check for goto
            goto_match = re.search(r'goto (L_[0-9A-Fa-f]+);', line)
            if goto_match:
                label_name = goto_match.group(1)
                func_gotos.append((label_name, i, line))

        # Process last function
        if current_func and func_gotos:
            for goto_label, goto_line, goto_content in func_gotos:
                if goto_label not in func_labels:
                    goto_uses[goto_label].append((fname, goto_line, goto_content.strip(), current_func))

    return label_defs, goto_uses

def find_instruction_at_address(funcs_dir, addr_hex):
    """Find what instruction is at the given address."""
    addr_str = f"0x{addr_hex}"

    for fname in sorted(os.listdir(funcs_dir)):
        if not fname.endswith('.c'):
            continue
        fpath = os.path.join(funcs_dir, fname)
        with open(fpath, 'r') as f:
            lines = f.readlines()

        for i, line in enumerate(lines):
            if f"// {addr_str}:" in line or f"// {addr_str.upper()}:" in line:
                # Return this line and next few for context
                context = []
                for j in range(i, min(i+5, len(lines))):
                    context.append(lines[j].rstrip())
                return fname, i+1, context

    return None, None, None

def main():
    print(f"Scanning {FUNCS_DIR}...")
    label_defs, goto_uses = find_all_labels_and_gotos(FUNCS_DIR)

    if not goto_uses:
        print("No cross-function gotos found!")
        return

    print(f"\nFound {sum(len(v) for v in goto_uses.values())} cross-function goto(s) targeting {len(goto_uses)} unique label(s):\n")

    fixes = []  # (file, line_num, old_text, new_text, reason)

    for label in sorted(goto_uses.keys()):
        addr_hex = label[2:]  # Strip "L_"
        fname, line_num, context = find_instruction_at_address(FUNCS_DIR, addr_hex)

        is_return = False
        reason = ""
        if context:
            context_str = " | ".join(context[:3])
            # Check if it's a jr $ra (return)
            for ctx_line in context:
                if 'jr' in ctx_line and '$ra' in ctx_line:
                    is_return = True
                    break
            reason = f"{'RETURN' if is_return else 'OTHER'}: {context_str}"
        else:
            reason = "ADDRESS NOT FOUND"

        for use_file, use_line, use_content, use_func in goto_uses[label]:
            print(f"  {use_file}:{use_line} in {use_func}: goto {label}")
            print(f"    -> {reason}")

            if is_return:
                fixes.append((use_file, use_line, f"goto {label};", "return;", label))

    print(f"\n--- Applying {len(fixes)} fix(es) ---\n")

    # Group fixes by file
    fixes_by_file = defaultdict(list)
    for fix_file, fix_line, old, new, label in fixes:
        fixes_by_file[fix_file].append((fix_line, old, new, label))

    for fname, file_fixes in sorted(fixes_by_file.items()):
        fpath = os.path.join(FUNCS_DIR, fname)
        with open(fpath, 'r') as f:
            lines = f.readlines()

        changes = 0
        for fix_line, old, new, label in file_fixes:
            idx = fix_line - 1
            if old in lines[idx]:
                lines[idx] = lines[idx].replace(old, f"{new} // {label} is jr $ra")
                changes += 1
                print(f"  Fixed {fname}:{fix_line}: {old} -> {new}")
            else:
                print(f"  WARNING: Could not find '{old}' at {fname}:{fix_line}")

        if changes > 0:
            with open(fpath, 'w') as f:
                f.writelines(lines)
            print(f"  Wrote {changes} fix(es) to {fname}")

    # Report unfixable gotos
    unfixed = []
    for label in sorted(goto_uses.keys()):
        addr_hex = label[2:]
        fname, line_num, context = find_instruction_at_address(FUNCS_DIR, addr_hex)
        is_return = False
        if context:
            for ctx_line in context:
                if 'jr' in ctx_line and '$ra' in ctx_line:
                    is_return = True
                    break
        if not is_return:
            for use_file, use_line, use_content, use_func in goto_uses[label]:
                unfixed.append((use_file, use_line, label, context))

    if unfixed:
        print(f"\n--- {len(unfixed)} UNFIXABLE goto(s) (not simple returns) ---")
        for uf_file, uf_line, uf_label, uf_context in unfixed:
            print(f"  {uf_file}:{uf_line}: goto {uf_label}")
            if uf_context:
                for c in uf_context[:3]:
                    print(f"    {c}")

if __name__ == "__main__":
    main()
