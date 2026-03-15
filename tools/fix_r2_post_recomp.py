#!/usr/bin/env python3
"""Post-N64Recomp fix script for R2. Run after N64Recomp regenerates RecompiledFuncs_R2."""
import re, os, subprocess, sys

D = "RecompiledFuncs_R2"

print("=== Step 1: Rename main ===")
for fname in ["funcs.h", "funcs_63.c"]:
    path = os.path.join(D, fname)
    with open(path) as f: c = f.read()
    c = c.replace("void main(uint8_t* rdram", "void recomp_entrypoint_main(uint8_t* rdram")
    with open(path, 'w') as f: f.write(c)
path = os.path.join(D, "recomp_overlays.inl")
with open(path) as f: c = f.read()
c = c.replace(".func = main,", ".func = recomp_entrypoint_main,")
with open(path, 'w') as f: f.write(c)
print("  Done")

print("=== Step 2: Fix cross-function gotos (return-targeting) ===")
subprocess.run([sys.executable, "tools/fix_cross_func_gotos.py", D])

print("=== Step 3: Fix after_X labels ===")
subprocess.run([sys.executable, "tools/fix_r2_after_labels.py", D])

print("=== Step 4: Fix remaining cross-func gotos ===")
subprocess.run([sys.executable, "tools/fix_r2_fallthroughs.py", D])

print("=== Step 5: Add forward declarations ===")
for fname in sorted(os.listdir(D)):
    if not fname.endswith('.c') or fname == 'func_stubs.c': continue
    path = os.path.join(D, fname)
    with open(path) as f: content = f.read()

    # Find functions called before defined
    defs = {}
    for m in re.finditer(r'RECOMP_FUNC void (\w+)\(', content):
        defs[m.group(1)] = m.start()

    calls = {}
    for m in re.finditer(r'\b(func_\w+)\(rdram', content):
        name = m.group(1)
        if name not in calls or m.start() < calls[name]:
            calls[name] = m.start()

    forward = [n for n, p in calls.items() if n in defs and p < defs[n]]
    if forward:
        decls = "\n".join(f"void {f}(uint8_t* rdram, recomp_context* ctx);" for f in sorted(forward))
        content = content.replace('#include "funcs.h"\n', f'#include "funcs.h"\n\n// Forward declarations\n{decls}\n')
        with open(path, 'w') as f: f.write(content)
        print(f"  {fname}: {len(forward)} forward declarations added")

print("=== Step 6: Generate func_stubs.c ===")
with open(os.path.join(D, 'recomp_overlays.inl')) as f:
    overlay_funcs = set(re.findall(r'\.func = (func_\w+|recomp_entrypoint\w*)', f.read()))
defined = set()
for fname in sorted(os.listdir(D)):
    if not fname.endswith('.c'): continue
    with open(os.path.join(D, fname)) as f:
        for m in re.finditer(r'RECOMP_FUNC void (\w+)\(', f.read()):
            defined.add(m.group(1))
missing = overlay_funcs - defined

with open('rampage2_ut.toml') as f:
    toml = f.read()
ign = set(re.findall(r'"(func_\w+)"', re.search(r'ignored\s*=\s*\[(.*?)\]', toml, re.DOTALL).group(1)))
called_ign = set()
for fname in sorted(os.listdir(D)):
    if not fname.endswith('.c') or fname == 'func_stubs.c': continue
    with open(os.path.join(D, fname)) as f:
        code = f.read()
    for func in ign:
        if func + '(rdram' in code: called_ign.add(func)

all_stubs = missing | called_ign
lines = ['#include "recomp.h"', '#include "funcs.h"', '']
for func in sorted(all_stubs):
    lines.append(f'RECOMP_FUNC void {func}(uint8_t* rdram, recomp_context* ctx) {{ }}')
with open(os.path.join(D, 'func_stubs.c'), 'w') as f:
    f.write('\n'.join(lines) + '\n')
print(f"  Written {len(all_stubs)} stubs")

print("=== Done ===")
