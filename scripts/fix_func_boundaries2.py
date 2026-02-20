#!/usr/bin/env python3
"""Fix remaining function boundaries from N64Recomp warnings (round 2).

Handles both forward and backward cross-function branches by always extending
the earlier (by address) function to cover the later one.
"""

import re

SYMBOLS_FILE = "symbols/rampage_wt_syms.toml"

# Each merge: (earlier_func_vram, new_end_addr, [functions_to_remove])
# Computed from N64Recomp [Warn] output
MERGES = [
    # 1. func_80017FC4 -> 0x8001816C (in func_80018140, ends 0x80018174)
    (0x80017FC4, 0x80018174, [0x8001803C, 0x80018094, 0x800180EC, 0x80018140]),

    # 2. func_80047F1C -> 0x80047FA0 (in func_80047F7C, ends 0x80047FA8)
    (0x80047F1C, 0x80047FA8, [0x80047F7C]),

    # 3. func_80050F80 -> 0x80051004 (in func_80050FE0, ends 0x8005100C)
    (0x80050F80, 0x8005100C, [0x80050FE0]),

    # 4. func_800571F8 -> 0x80057284 (in func_80057250, ends 0x8005728C)
    (0x800571F8, 0x8005728C, [0x80057250]),

    # 5&9. func_80061A44 <-> func_80061A84 (mutual, merge into 80061A44)
    (0x80061A44, 0x80061ABC, [0x80061A84]),

    # 6. func_80066630 -> 0x80066AB8 (in func_800668D8, ends 0x80066AC0)
    (0x80066630, 0x80066AC0, [0x800668D8]),

    # 7. func_8003AC10 -> 0x8003ABE4 (backward, in func_8003ABCC, ends 0x8003AC10)
    (0x8003ABCC, 0x8003AC24, [0x8003AC10]),

    # 8. func_8005DF84 -> 0x8005DEAC (backward, in func_8005DE4C, ends 0x8005DF84)
    # Note: func_8005DE4C is in TOML ignored list
    (0x8005DE4C, 0x8005DF9C, [0x8005DF84]),

    # 10. func_80062C3C -> 0x80062BCC (backward, in func_80062BBC)
    (0x80062BBC, 0x80062C50, [0x80062BE8, 0x80062C04, 0x80062C20, 0x80062C3C]),

    # 11. func_80068C0C -> 0x80068BE0 (backward, in func_80068BCC)
    (0x80068BCC, 0x80068C20, [0x80068C0C]),

    # 12&13&14. Chain: func_8006FD20 <- func_8006FD94 <- func_8006FF04
    # Note: func_8006FD20 is in TOML ignored list
    (0x8006FD20, 0x80070030, [0x8006FD94, 0x8006FF04]),
]

# Parse the symbols file
func_pattern = re.compile(
    r'\{ name = "([^"]+)", vram = (0x[0-9A-Fa-f]+), size = (0x[0-9A-Fa-f]+) \}'
)

with open(SYMBOLS_FILE) as f:
    content = f.read()

functions = {}
for match in func_pattern.finditer(content):
    name = match.group(1)
    vram = int(match.group(2), 16)
    size = int(match.group(3), 16)
    functions[vram] = {"name": name, "vram": vram, "size": size}

print(f"Parsed {len(functions)} functions")

new_content = content

for base_vram, new_end, remove_list in MERGES:
    if base_vram not in functions:
        print(f"WARNING: Base function 0x{base_vram:08X} not found!")
        continue

    func = functions[base_vram]
    old_size = func["size"]
    new_size = new_end - base_vram

    old_entry = f'{{ name = "{func["name"]}", vram = 0x{func["vram"]:08X}, size = 0x{old_size:X} }}'
    new_entry = f'{{ name = "{func["name"]}", vram = 0x{func["vram"]:08X}, size = 0x{new_size:X} }}'

    if old_entry in new_content:
        new_content = new_content.replace(old_entry, new_entry, 1)
        print(f"Extended: {func['name']} size 0x{old_size:X} -> 0x{new_size:X}")
    else:
        print(f"WARNING: Could not find entry for {func['name']}")

    for rm_vram in remove_list:
        if rm_vram not in functions:
            print(f"  WARNING: Function to remove 0x{rm_vram:08X} not found!")
            continue
        rm_func = functions[rm_vram]
        rm_entry = f'    {{ name = "{rm_func["name"]}", vram = 0x{rm_func["vram"]:08X}, size = 0x{rm_func["size"]:X} }},\n'
        if rm_entry in new_content:
            new_content = new_content.replace(rm_entry, "", 1)
            print(f"  Removed: {rm_func['name']}")
        else:
            # Try without trailing comma
            rm_entry2 = f'    {{ name = "{rm_func["name"]}", vram = 0x{rm_func["vram"]:08X}, size = 0x{rm_func["size"]:X} }}\n'
            if rm_entry2 in new_content:
                new_content = new_content.replace(rm_entry2, "", 1)
                print(f"  Removed: {rm_func['name']}")
            else:
                print(f"  WARNING: Could not remove {rm_func['name']}")

with open(SYMBOLS_FILE, "w") as f:
    f.write(new_content)

print(f"\nSymbols file updated!")
