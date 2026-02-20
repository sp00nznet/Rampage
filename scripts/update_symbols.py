#!/usr/bin/env python3
"""Update the Rampage WT symbols file with libultra function names from n64sym output."""

import re

# Read n64sym VRAM output (80xxxxxx addresses)
n64sym_map = {}
with open("tools/n64sym/rampage_wt_syms.txt") as f:
    for line in f:
        line = line.strip()
        if not line:
            continue
        parts = line.split(None, 1)
        if len(parts) == 2:
            addr = int(parts[0], 16)
            name = parts[1]
            if 0x80000400 <= addr <= 0x800BE900:
                n64sym_map[addr] = name

# Read n64sym ROM output (70xxxxxx addresses) and convert to VRAM
# Conversion: VRAM = ROM_addr + 0x10000000 (verified: 700693B0 -> 800693B0)
with open("tools/n64sym/rampage_wt_rom_syms.txt") as f:
    for line in f:
        line = line.strip()
        if not line:
            continue
        parts = line.split(None, 1)
        if len(parts) == 2:
            rom_addr = int(parts[0], 16)
            name = parts[1]
            vram = rom_addr + 0x10000000
            if 0x80000400 <= vram <= 0x800BE900 and vram not in n64sym_map:
                n64sym_map[vram] = name

# Manual additions for functions confirmed by code analysis
manual_additions = {
    0x800697E0: "osCreateMesgQueue",
    0x8006E620: "__osDisableInt",
    0x8006E25C: "__osEnqueueThread",
    0x8006E15C: "__osEnqueueAndYield",
    0x8006E660: "__osDequeueThread",
    0x8006DA60: "__osSetSR",
    0x8006DA80: "__osSetFpcCsr",
    0x8006E520: "osPiRawReadIo",
    0x8006E580: "bzero",
    0x8006E440: "osWritebackDCache",
    0x8006B290: "osInvalDCache",
    0x8006B520: "osInvalICache",
    0x8006E890: "__osPiCreateAccessQueue",
}

for addr, name in manual_additions.items():
    if addr not in n64sym_map:
        n64sym_map[addr] = name

# Data symbols to skip (not functions)
skip_patterns = [
    '_bss_', '_data_', '_rodata_', 'text_0', 'osTvType', 'osRomBase',
    'osResetType', 'osAppNMIBuffer', 'osViMode', 'osViClock', 'osClockRate',
    '__OSGlobal', '__osRun', '__osActive', '__osRunning', '__osPiAccess',
    '__osTimer', 'vi_data', '__osViCurr', '__osViNext', '__osPiDev',
    '__osPiTable', '__osCurrentHandle', '__osContini', 'CartRomHandle',
    '__osSiAccess', '__osCurrentTime', '_Motor', '__osPfsPifRam',
    '__osContPifRam', '__osContLastCmd', '__osMaxControllers',
    '__osEepromTimer', '__osBaseCounter', '__osViIntrCount',
    '__osTimerCounter', '__osFinalrom', '__osRcpImTable',
    'devmgr_rodata', 'xprintf_', 'xlitob_', 'xldtob_',
    'osBbCardChange', 'osViExtend', 'myfree', 'leoInit',
    'alGlobals', 'aisetnextbuf_data', 'drvrNew_data', 'env_data',
    'synthesizer_rodata', 'drvrNew_rodata', 'resample_rodata',
    'env_rodata', 'reverb_rodata', '__additional', 'leomecha',
    '__osBbCard', 'FB_BGCOLOR', 'player_bss', 'siacs_bss',
    'pimgr_bss', '__osEventState', 'contreaddata_text',
    'contramread_text', 'contramwrite_text', 'pfsallocatefile_text',
    'pfsreadwritefile_text', 'sprintf_text', 'sptask_text',
    'motor_text',
]

def is_data_symbol(name):
    return any(pat in name for pat in skip_patterns)

func_map = {addr: name for addr, name in n64sym_map.items() if not is_data_symbol(name)}

print(f"Total code-range symbols: {len(n64sym_map)}")
print(f"After filtering data symbols: {len(func_map)}")

# Read the symbols file
with open("symbols/rampage_wt_syms.toml") as f:
    content = f.read()

# Rename functions
pattern = re.compile(
    r'\{ name = "func_([0-9A-Fa-f]{8})", vram = (0x[0-9A-Fa-f]+), size = (0x[0-9A-Fa-f]+) \}'
)

renamed_count = 0
def replace_func(match):
    global renamed_count
    func_addr = int(match.group(1), 16)
    vram_str = match.group(2)
    size_str = match.group(3)
    if func_addr in func_map:
        new_name = func_map[func_addr]
        renamed_count += 1
        return f'{{ name = "{new_name}", vram = {vram_str}, size = {size_str} }}'
    return match.group(0)

new_content = pattern.sub(replace_func, content)
print(f"Functions renamed: {renamed_count}")

with open("symbols/rampage_wt_syms.toml", "w") as f:
    f.write(new_content)

print("Symbols file updated!")

# Now check which TOML ignored functions were renamed and need updating
toml_ignored = [
    "func_8007623C", "func_80076210", "func_80075C88", "func_80075C30",
    "func_80075C28", "func_80075C08", "func_80075300", "func_800752B8",
    "func_80075290", "func_80074E14", "func_80074D58", "func_80074C34",
    "func_80074BE0", "func_80072EF0", "func_80072EE0", "func_8006FD20",
    "func_8006FCF0", "func_8006E4C0", "func_8006E490", "func_8006E440",
    "func_8006E2B4", "func_8006E074", "func_8006DB30", "func_8006B570",
    "func_8006B520", "func_8006B318", "func_8006B290", "func_8006AA80",
    "func_8005DE4C", "func_8002DA90",
]

print("\n=== TOML ignored list status ===")
needs_removal = []
for func_name in toml_ignored:
    addr = int(func_name.replace("func_", ""), 16)
    if addr in func_map:
        print(f"  RENAMED: {func_name} -> {func_map[addr]} (remove from TOML)")
        needs_removal.append(func_name)
    else:
        print(f"  OK: {func_name} (keep in TOML)")

print(f"\nFunctions to remove from TOML ignored list: {len(needs_removal)}")
for f in needs_removal:
    print(f"  - {f}")
