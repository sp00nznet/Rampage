#!/usr/bin/env python3
"""Fix function boundaries in the symbols file to resolve cross-function goto issues.

For each cross-function goto, extends the source function's size to encompass
the target address, and removes functions that are now fully contained within
the merged function.
"""

import re
import sys

# Cross-function goto pairs: (source_func_vram, target_addr)
# From analysis of recompiled C files
CROSS_FUNC_GOTOS = [
    (0x8000587C, 0x800058E8),
    (0x800058B0, 0x800058E8),
    (0x800082D0, 0x800082E4),
    (0x8000A32C, 0x8000A378),
    (0x8000A380, 0x8000A3E8),
    (0x8000A3BC, 0x8000A3E8),
    (0x8000AC20, 0x8000ACFC),
    (0x8000B334, 0x8000B414),
    (0x8000B41C, 0x8000B4FC),
    (0x8000B830, 0x8000B90C),
    (0x8000B914, 0x8000B9F4),
    (0x8000BBC0, 0x8000BC9C),
    (0x8000C188, 0x8000C268),
    (0x8000C270, 0x8000C350),
    (0x8000C56C, 0x8000C64C),
    (0x8000C654, 0x8000C734),
    (0x8000C73C, 0x8000C8C0),
    (0x8000C820, 0x8000C8C0),
    (0x8000C950, 0x8000CA2C),
    (0x8000D338, 0x8000D444),
    (0x80011858, 0x80011930),
    (0x800131A4, 0x80013298),
    (0x800185DC, 0x80018638),
    (0x800185DC, 0x80018640),
    (0x8001A110, 0x8001A150),
    (0x8001A110, 0x8001A158),
    (0x8001B7F4, 0x8001B84C),
    (0x8001C794, 0x8001C820),
    (0x8001C830, 0x8001C894),
    (0x80028D88, 0x80028E34),
    (0x8002999C, 0x800299E4),
    (0x80029D78, 0x80029DD0),
    (0x8002B4E4, 0x8002B528),
    (0x8002B6E0, 0x8002B71C),
    (0x8002B750, 0x8002B784),
    (0x8002B9DC, 0x8002BA24),
    (0x8002BA30, 0x8002BA78),
    (0x8002BA84, 0x8002BACC),
    (0x8002C9EC, 0x8002CA9C),
    (0x800362AC, 0x80036320),
    (0x80036328, 0x800363C8),
    (0x80039F84, 0x80039FF0),
    (0x8003CE6C, 0x8003CF08),
    (0x8003DACC, 0x8003DB00),
    (0x8003DACC, 0x8003DB08),
    (0x8003DB80, 0x8003DBB0),
    (0x8003DB80, 0x8003DBB8),
    (0x8003F918, 0x8003F988),
    (0x80042EF0, 0x80042F78),
    (0x80046B74, 0x80046BE0),
    (0x80046BBC, 0x80046BE0),
    (0x80046BE8, 0x80046C38),
    (0x80047568, 0x80047604),
    (0x8004B1B0, 0x8004B224),
    (0x8004B2D4, 0x8004B318),
    (0x8004BCFC, 0x8004BD70),
    (0x8004C260, 0x8004C3AC),
    (0x8004CBC0, 0x8004CC6C),
    (0x8004CC58, 0x8004CC6C),
    (0x8004E1B8, 0x8004E210),
    (0x80053E34, 0x80053E6C),
    (0x800543CC, 0x80054410),
    (0x80054FFC, 0x80055144),
    (0x80055E60, 0x80055F78),
    (0x80056400, 0x800564B8),
    (0x80058374, 0x80058404),
    (0x80058C94, 0x80058CDC),
    (0x8006B4A4, 0x8006B4CC),  # strchr_recomp
    (0x8006B4A4, 0x8006B4DC),  # strchr_recomp
]

SYMBOLS_FILE = "symbols/rampage_wt_syms.toml"

# Parse all function entries from the symbols file
func_pattern = re.compile(
    r'\{ name = "([^"]+)", vram = (0x[0-9A-Fa-f]+), size = (0x[0-9A-Fa-f]+) \}'
)

with open(SYMBOLS_FILE) as f:
    content = f.read()

# Build a dict of vram -> (name, size, line_text)
functions = {}
for match in func_pattern.finditer(content):
    name = match.group(1)
    vram = int(match.group(2), 16)
    size = int(match.group(3), 16)
    functions[vram] = {"name": name, "vram": vram, "size": size}

print(f"Parsed {len(functions)} functions from symbols file")

# Sort functions by address
sorted_addrs = sorted(functions.keys())

# For each cross-function goto, find what needs to be merged
# Strategy: extend the source function to encompass the target address + 4 bytes (one instruction)
# Then remove any functions that are now fully contained within the extended function

merges_needed = {}  # source_vram -> max target_addr

for src_vram, target_addr in CROSS_FUNC_GOTOS:
    if src_vram not in functions:
        print(f"WARNING: Source function 0x{src_vram:08X} not found in symbols!")
        continue

    if src_vram not in merges_needed:
        merges_needed[src_vram] = target_addr
    else:
        merges_needed[src_vram] = max(merges_needed[src_vram], target_addr)

# Now for each source function, find the function containing the target address
# and extend the source to cover through the end of that function
changes = []
for src_vram, max_target in sorted(merges_needed.items()):
    src = functions[src_vram]
    src_end = src_vram + src["size"]

    # Find the function that contains the target address
    target_func_vram = None
    for addr in sorted_addrs:
        func = functions[addr]
        func_end = addr + func["size"]
        if addr <= max_target < func_end:
            target_func_vram = addr
            break

    if target_func_vram is None:
        # Target might be past the last instruction of a function
        # Find the function just before the target
        for addr in reversed(sorted_addrs):
            if addr <= max_target:
                target_func_vram = addr
                break

    if target_func_vram is None:
        print(f"WARNING: Could not find function containing target 0x{max_target:08X}")
        continue

    target_func = functions[target_func_vram]
    new_end = target_func_vram + target_func["size"]

    if new_end <= src_end:
        # Target is already within source function bounds (shouldn't happen)
        print(f"SKIP: 0x{src_vram:08X} already encompasses target 0x{max_target:08X}")
        continue

    new_size = new_end - src_vram
    changes.append({
        "src_vram": src_vram,
        "src_name": src["name"],
        "old_size": src["size"],
        "new_size": new_size,
        "target_end": new_end,
    })

print(f"\n{len(changes)} functions need size extension")

# Apply changes iteratively - some merges may cascade
# First pass: compute all new sizes
# Handle cascading: if func_A extends to cover func_B, and func_B extends to cover func_C,
# then func_A should extend to cover func_C too.
# But since we only extend source functions (which have gotos), cascading is handled by
# the fact that the extended function will be re-parsed and the gotos from sub-functions
# will be part of the new larger function.

# Actually, cascading isn't needed here because we're fixing the symbols file, not the C code.
# After fixing the symbols, N64Recomp will re-generate the C code with correct function boundaries.

# Collect all functions that will be absorbed (fully contained within an extended function)
absorbed = set()
for change in changes:
    src_vram = change["src_vram"]
    target_end = change["target_end"]

    # Find all functions between src_vram and target_end (exclusive of src itself)
    for addr in sorted_addrs:
        if addr > src_vram and addr < target_end:
            absorbed.add(addr)

print(f"{len(absorbed)} functions will be absorbed into parent functions")

# Check for conflicts: is any absorbed function also a source function that needs extension?
conflicts = absorbed & set(merges_needed.keys())
if conflicts:
    print(f"\nWARNING: {len(conflicts)} absorbed functions are also merge sources:")
    for addr in sorted(conflicts):
        print(f"  0x{addr:08X} ({functions[addr]['name']})")
    print("These will be handled by the parent function's extension.")

# Now apply changes to the symbols file content
new_content = content

# First, update the sizes of source functions
for change in changes:
    src = functions[change["src_vram"]]
    old_entry = f'{{ name = "{src["name"]}", vram = 0x{src["vram"]:08X}, size = 0x{src["size"]:X} }}'
    new_entry = f'{{ name = "{src["name"]}", vram = 0x{src["vram"]:08X}, size = 0x{change["new_size"]:X} }}'

    if old_entry in new_content:
        new_content = new_content.replace(old_entry, new_entry, 1)
        print(f"  Extended: {src['name']} size 0x{src['size']:X} -> 0x{change['new_size']:X}")
    else:
        print(f"  WARNING: Could not find entry for {src['name']} (0x{src['vram']:08X})")

# Then, remove absorbed functions
removed_count = 0
for addr in sorted(absorbed):
    func = functions[addr]
    entry = f'    {{ name = "{func["name"]}", vram = 0x{func["vram"]:08X}, size = 0x{func["size"]:X} }},\n'
    if entry in new_content:
        new_content = new_content.replace(entry, "", 1)
        removed_count += 1
    else:
        # Try without trailing comma (might be last in list)
        entry2 = f'    {{ name = "{func["name"]}", vram = 0x{func["vram"]:08X}, size = 0x{func["size"]:X} }}\n'
        if entry2 in new_content:
            new_content = new_content.replace(entry2, "", 1)
            removed_count += 1
        else:
            print(f"  WARNING: Could not remove absorbed function {func['name']} (0x{func['vram']:08X})")

print(f"\nRemoved {removed_count} absorbed functions")

# Write the updated file
with open(SYMBOLS_FILE, "w") as f:
    f.write(new_content)

print(f"\nSymbols file updated: {SYMBOLS_FILE}")
print(f"Total changes: {len(changes)} extensions, {removed_count} removals")
