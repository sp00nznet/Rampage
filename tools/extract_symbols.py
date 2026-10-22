#!/usr/bin/env python3
"""
MIPS N64 ROM Symbol Extractor for N64Recomp
Detects function boundaries from raw MIPS binary and outputs TOML symbol files.

Usage:
    python extract_symbols.py <rom_path> <output_toml> [--bss-start ADDR] [--vram-start ADDR] [--rom-offset OFFSET]
"""

import struct
import argparse
import os


def read_rom(rom_path):
    """Read entire ROM file."""
    with open(rom_path, 'rb') as f:
        return f.read()


def parse_rom_header(rom_data):
    """Parse N64 ROM header (big-endian .z64 format)."""
    if len(rom_data) < 0x40:
        raise ValueError("ROM too small to contain header")

    pi_bsd = struct.unpack('>I', rom_data[0x00:0x04])[0]
    clock_rate = struct.unpack('>I', rom_data[0x04:0x08])[0]
    entry_point = struct.unpack('>I', rom_data[0x08:0x0C])[0]
    release_addr = struct.unpack('>I', rom_data[0x0C:0x10])[0]
    crc1 = struct.unpack('>I', rom_data[0x10:0x14])[0]
    crc2 = struct.unpack('>I', rom_data[0x14:0x18])[0]
    title = rom_data[0x20:0x34].decode('ascii', errors='replace').strip('\x00').strip()
    dev_id = chr(rom_data[0x3B])
    cart_id = rom_data[0x3C:0x3E].decode('ascii', errors='replace')
    country = chr(rom_data[0x3E])
    version = rom_data[0x3F]

    return {
        'pi_bsd': pi_bsd,
        'clock_rate': clock_rate,
        'entry_point': entry_point,
        'release_addr': release_addr,
        'crc1': crc1,
        'crc2': crc2,
        'title': title,
        'dev_id': dev_id,
        'cart_id': cart_id,
        'country': country,
        'version': version,
    }


def detect_bss_start(rom_data, vram_start=0x80000400, rom_offset=0x1000):
    """
    Detect BSS start by analyzing the bootstrap code at the entry point.
    The bootstrap typically does:
        lui t0, BSS_HI
        addiu t0, t0, BSS_LO    -> BSS start address
        lui t1, SIZE_HI
        ori/addiu t1, t1, SIZE_LO -> BSS size
    """
    # Read first 20 instructions of boot code
    instructions = []
    for i in range(20):
        offset = rom_offset + i * 4
        if offset + 4 <= len(rom_data):
            insn = struct.unpack('>I', rom_data[offset:offset + 4])[0]
            instructions.append(insn)

    # Look for lui+addiu pattern that loads BSS start
    bss_start = None
    bss_size = None

    regs = {}  # Track register values

    for i, insn in enumerate(instructions):
        opcode = (insn >> 26) & 0x3F
        rs = (insn >> 21) & 0x1F
        rt = (insn >> 16) & 0x1F
        imm = insn & 0xFFFF
        imm_signed = imm if imm < 0x8000 else imm - 0x10000

        if opcode == 0x0F:  # lui
            regs[rt] = imm << 16
        elif opcode == 0x09:  # addiu
            if rs in regs:
                regs[rt] = (regs[rs] + imm_signed) & 0xFFFFFFFF
        elif opcode == 0x0D:  # ori
            if rs in regs:
                regs[rt] = regs[rs] | imm

    # The bootstrap loads BSS start into t0 (reg 8) and BSS size into t1 (reg 9)
    if 8 in regs:
        bss_start = regs[8]
    if 9 in regs:
        bss_size = regs[9]

    return bss_start, bss_size


def detect_main_func(rom_data, vram_start=0x80000400, rom_offset=0x1000):
    """
    Detect main function address from the bootstrap code.
    The bootstrap typically loads an address into a register then does jr to it.
    """
    instructions = []
    for i in range(20):
        offset = rom_offset + i * 4
        if offset + 4 <= len(rom_data):
            insn = struct.unpack('>I', rom_data[offset:offset + 4])[0]
            instructions.append(insn)

    regs = {}

    for i, insn in enumerate(instructions):
        opcode = (insn >> 26) & 0x3F
        rs = (insn >> 21) & 0x1F
        rt = (insn >> 16) & 0x1F
        rd = (insn >> 11) & 0x1F
        imm = insn & 0xFFFF
        imm_signed = imm if imm < 0x8000 else imm - 0x10000

        if opcode == 0x0F:  # lui
            regs[rt] = imm << 16
        elif opcode == 0x09:  # addiu
            if rs in regs:
                regs[rt] = (regs[rs] + imm_signed) & 0xFFFFFFFF
        elif opcode == 0x0D:  # ori
            if rs in regs:
                regs[rt] = regs[rs] | imm
        elif opcode == 0x00:  # SPECIAL
            funct = insn & 0x3F
            if funct == 0x08:  # jr
                target_reg = rs
                if target_reg in regs:
                    return regs[target_reg]

    return None


def find_code_end(rom_data, rom_offset, bss_rom_equivalent, vram_start, bss_start):
    """
    Find where actual code ends in the ROM.
    The code section in ROM goes from rom_offset to (bss_start - vram_start + rom_offset).
    But the actual end might be earlier if there's data between code and BSS.
    """
    code_rom_size = bss_start - vram_start
    code_end_rom = rom_offset + code_rom_size
    return min(code_end_rom, len(rom_data))


def extract_functions(rom_data, vram_start, rom_offset, code_size):
    """
    Extract function boundaries using multiple heuristics.
    Returns (func_entries dict, external_targets set).
    func_entries: vram -> confidence score for internal functions
    external_targets: set of VRAM addresses for JAL targets outside code section
    """
    num_instructions = code_size // 4
    instructions = []

    for i in range(num_instructions):
        offset = rom_offset + i * 4
        if offset + 4 <= len(rom_data):
            insn = struct.unpack('>I', rom_data[offset:offset + 4])[0]
            instructions.append(insn)
        else:
            instructions.append(0)

    func_entries = {}  # vram -> confidence score
    external_targets = set()  # JAL targets outside code section

    # Always include the entrypoint
    func_entries[vram_start] = 100

    code_end = vram_start + code_size
    print(f"  Scanning {num_instructions} instructions ({code_size} bytes)...")

    # Pass 1: Collect all JAL targets (highest confidence)
    jal_count = 0
    ext_jal_count = 0
    for i, insn in enumerate(instructions):
        opcode = (insn >> 26) & 0x3F
        vram = vram_start + i * 4

        if opcode == 0x03:  # JAL
            target = (insn & 0x03FFFFFF) << 2
            target |= (vram & 0xF0000000)
            if vram_start <= target < code_end:
                if target not in func_entries or func_entries[target] < 90:
                    func_entries[target] = 90
                jal_count += 1
            elif target >= 0x80000000:  # Valid KSEG0/KSEG1 address outside code
                external_targets.add(target)
                ext_jal_count += 1

    print(f"  Found {jal_count} internal JAL targets, {ext_jal_count} external JAL calls -> {len(external_targets)} unique external targets")

    # Pass 2: Detect stack frame prologues (high confidence)
    prologue_count = 0
    for i, insn in enumerate(instructions):
        # addiu sp, sp, -N -> 0x27BDXXXX where XXXX is negative (>= 0x8000)
        if (insn >> 16) == 0x27BD:
            imm = insn & 0xFFFF
            if imm >= 0x8000:  # Negative immediate = stack allocation
                vram = vram_start + i * 4
                if vram not in func_entries or func_entries[vram] < 80:
                    func_entries[vram] = 80
                prologue_count += 1

    print(f"  Found {prologue_count} stack prologues -> {len(func_entries)} total entries")

    # Pass 3: Post-return boundary detection
    # After jr ra + delay slot, the next non-NOP instruction starts a new function
    post_return_count = 0
    for i, insn in enumerate(instructions):
        if insn == 0x03E00008:  # jr ra
            # Skip the delay slot (i+1), then find the next non-NOP
            next_idx = i + 2
            while next_idx < num_instructions and instructions[next_idx] == 0x00000000:
                next_idx += 1

            if next_idx < num_instructions:
                candidate_vram = vram_start + next_idx * 4
                if candidate_vram not in func_entries or func_entries[candidate_vram] < 60:
                    func_entries[candidate_vram] = 60
                post_return_count += 1

    print(f"  Found {post_return_count} post-return boundaries -> {len(func_entries)} total entries")

    # Pass 4: Detect J (jump) targets that might be tail calls to the start of functions
    j_count = 0
    for i, insn in enumerate(instructions):
        opcode = (insn >> 26) & 0x3F
        vram = vram_start + i * 4

        if opcode == 0x02:  # J (jump, not JAL)
            target = (insn & 0x03FFFFFF) << 2
            target |= (vram & 0xF0000000)
            if vram_start <= target < code_end:
                # Only add if this target is already a known function entry
                # (J to known function = tail call, confirms the target)
                if target in func_entries:
                    func_entries[target] = max(func_entries[target], 85)
                    j_count += 1

    print(f"  Confirmed {j_count} J-target entries")

    return func_entries, external_targets


def build_function_list(func_entries, vram_start, code_size):
    """
    Convert function entries into a contiguous list with sizes.
    Functions are sorted by address and sizes fill gaps between them.
    """
    sorted_entries = sorted(func_entries.keys())
    code_end = vram_start + code_size

    functions = []
    for i, entry in enumerate(sorted_entries):
        if entry >= code_end:
            break

        if i + 1 < len(sorted_entries) and sorted_entries[i + 1] <= code_end:
            size = sorted_entries[i + 1] - entry
        else:
            size = code_end - entry

        # Ensure size is a multiple of 4
        size = (size // 4) * 4
        if size <= 0:
            continue

        # Name based on address
        if entry == vram_start:
            name = "recomp_entrypoint"
        else:
            name = f"func_{entry:08X}"

        confidence = func_entries[entry]
        functions.append({
            'name': name,
            'vram': entry,
            'size': size,
            'confidence': confidence,
        })

    return functions


def group_external_targets(external_targets, rom_size):
    """
    Group external targets into sections where all functions map to valid ROM offsets.
    Each section has rom_addr=0, so func.rom = func.vram - section.vram.
    We need func.rom + 4 <= rom_size, meaning func.vram - section.vram < rom_size.
    Max span per section: rom_size - 4.
    """
    if not external_targets:
        return []

    sorted_targets = sorted(external_targets)
    max_span = rom_size - 4

    sections = []
    current_section_start = sorted_targets[0]
    current_section_targets = [sorted_targets[0]]

    for target in sorted_targets[1:]:
        if target - current_section_start < max_span:
            current_section_targets.append(target)
        else:
            sections.append((current_section_start, current_section_targets))
            current_section_start = target
            current_section_targets = [target]

    sections.append((current_section_start, current_section_targets))
    return sections


def write_toml(functions, external_targets, output_path, vram_start, rom_offset, code_size, header_info, rom_size):
    """Write the symbol file in N64Recomp's expected TOML format."""
    # Group external targets into sections
    ext_sections = group_external_targets(external_targets, rom_size)
    ext_func_names = []

    with open(output_path, 'w') as f:
        f.write(f"# Auto-generated symbol file for {header_info['title']}\n")
        f.write(f"# Game ID: {header_info['dev_id']}{header_info['cart_id']}{header_info['country']}\n")
        f.write(f"# CRC: {header_info['crc1']:08X} {header_info['crc2']:08X}\n")
        f.write(f"# Entry point: 0x{header_info['entry_point']:08X}\n")
        f.write(f"# Total functions detected: {len(functions)}\n")
        f.write(f"# External stub functions: {len(external_targets)}\n")
        f.write(f"#\n")
        f.write(f"# Generated by extract_symbols.py\n\n")

        # Main code section
        f.write(f"[[section]]\n")
        f.write(f'name = ".text"\n')
        f.write(f"rom = 0x{rom_offset:08X}\n")
        f.write(f"vram = 0x{vram_start:08X}\n")
        f.write(f"size = 0x{code_size:X}\n\n")

        f.write(f"functions = [\n")
        for i, func in enumerate(functions):
            comma = "," if i < len(functions) - 1 else ""
            f.write(f'    {{ name = "{func["name"]}", '
                    f'vram = 0x{func["vram"]:08X}, '
                    f'size = 0x{func["size"]:X} '
                    f'}}{comma}\n')
        f.write(f"]\n")

        # External stub sections
        for sec_idx, (sec_start, targets) in enumerate(ext_sections):
            sec_end = max(targets) + 4
            sec_size = sec_end - sec_start

            f.write(f"\n# External stub section {sec_idx} "
                    f"(0x{sec_start:08X} - 0x{sec_end:08X}, {len(targets)} stubs)\n")
            f.write(f"[[section]]\n")
            f.write(f'name = ".ext_stub_{sec_idx}"\n')
            f.write(f"rom = 0x00000000\n")
            f.write(f"vram = 0x{sec_start:08X}\n")
            f.write(f"size = 0x{sec_size:X}\n\n")

            f.write(f"functions = [\n")
            for i, target in enumerate(targets):
                name = f"stub_{target:08X}"
                ext_func_names.append(name)
                comma = "," if i < len(targets) - 1 else ""
                f.write(f'    {{ name = "{name}", '
                        f'vram = 0x{target:08X}, '
                        f'size = 0x4 '
                        f'}}{comma}\n')
            f.write(f"]\n")

    print(f"\nWrote {len(functions)} functions + {len(ext_func_names)} external stubs to {output_path}")
    return ext_func_names


def main():
    parser = argparse.ArgumentParser(description='Extract MIPS function symbols from N64 ROM')
    parser.add_argument('rom_path', help='Path to N64 ROM (.z64 big-endian)')
    parser.add_argument('output_toml', help='Output TOML symbol file path')
    parser.add_argument('--vram-start', type=lambda x: int(x, 0), default=None,
                        help='VRAM start address (default: auto-detect from header)')
    parser.add_argument('--rom-offset', type=lambda x: int(x, 0), default=0x1000,
                        help='ROM offset where code starts (default: 0x1000)')
    parser.add_argument('--bss-start', type=lambda x: int(x, 0), default=None,
                        help='BSS start VRAM address (default: auto-detect from bootstrap)')
    parser.add_argument('--code-size', type=lambda x: int(x, 0), default=None,
                        help='Code section size in bytes (default: bss_start - vram_start)')
    args = parser.parse_args()

    print(f"Reading ROM: {args.rom_path}")
    rom_data = read_rom(args.rom_path)
    print(f"  ROM size: {len(rom_data)} bytes ({len(rom_data) / 1024 / 1024:.1f} MB)")

    # Parse header
    header = parse_rom_header(rom_data)
    print(f"\n=== ROM Header ===")
    print(f"  Title: {header['title']}")
    print(f"  Game ID: {header['dev_id']}{header['cart_id']}{header['country']}")
    print(f"  Entry Point: 0x{header['entry_point']:08X}")
    print(f"  CRC: {header['crc1']:08X} / {header['crc2']:08X}")

    # Determine VRAM start
    vram_start = args.vram_start or header['entry_point']
    rom_offset = args.rom_offset
    print(f"\n  VRAM start: 0x{vram_start:08X}")
    print(f"  ROM offset: 0x{rom_offset:08X}")

    # Detect BSS start
    if args.bss_start:
        bss_start = args.bss_start
    else:
        bss_start, bss_size = detect_bss_start(rom_data, vram_start, rom_offset)
        if bss_start:
            print(f"  BSS start (auto-detected): 0x{bss_start:08X}")
            if bss_size:
                print(f"  BSS size (auto-detected): 0x{bss_size:X}")
        else:
            print("  WARNING: Could not auto-detect BSS start!")
            print("  Please provide --bss-start manually.")
            return

    # Calculate code size
    if args.code_size:
        code_size = args.code_size
    else:
        code_size = bss_start - vram_start

    print(f"  Code size: 0x{code_size:X} ({code_size} bytes)")

    # Detect main function
    main_addr = detect_main_func(rom_data, vram_start, rom_offset)
    if main_addr:
        print(f"  Main function: 0x{main_addr:08X}")

    # Extract function boundaries
    print(f"\n=== Extracting Functions ===")
    func_entries, external_targets = extract_functions(rom_data, vram_start, rom_offset, code_size)

    # Build contiguous function list
    functions = build_function_list(func_entries, vram_start, code_size)

    # Rename main function if detected
    if main_addr:
        for func in functions:
            if func['vram'] == main_addr:
                func['name'] = 'main'
                break

    # Print stats
    print(f"\n=== Statistics ===")
    print(f"  Total functions: {len(functions)}")
    print(f"  External targets (stubs): {len(external_targets)}")
    if functions:
        sizes = [f['size'] for f in functions]
        print(f"  Smallest function: {min(sizes)} bytes")
        print(f"  Largest function: {max(sizes)} bytes")
        print(f"  Average function size: {sum(sizes) / len(sizes):.0f} bytes")

        # Confidence breakdown
        conf_90 = sum(1 for f in functions if f['confidence'] >= 90)
        conf_80 = sum(1 for f in functions if 80 <= f['confidence'] < 90)
        conf_60 = sum(1 for f in functions if f['confidence'] < 80)
        print(f"  High confidence (JAL target): {conf_90}")
        print(f"  Medium confidence (prologue): {conf_80}")
        print(f"  Lower confidence (post-return): {conf_60}")

    # Verify coverage
    total_covered = sum(f['size'] for f in functions)
    print(f"  Total coverage: 0x{total_covered:X} / 0x{code_size:X} bytes "
          f"({total_covered * 100 / code_size:.1f}%)")

    # Create output directory if needed
    os.makedirs(os.path.dirname(os.path.abspath(args.output_toml)), exist_ok=True)

    # Write TOML with external stubs
    ext_func_names = write_toml(functions, external_targets, args.output_toml,
                                 vram_start, rom_offset, code_size, header, len(rom_data))

    # Write stubs list file (for use in the config TOML)
    stubs_path = args.output_toml.replace('.toml', '_stubs.txt')
    with open(stubs_path, 'w') as f:
        for name in sorted(ext_func_names):
            f.write(f'    "{name}",\n')
    print(f"Wrote {len(ext_func_names)} stub names to {stubs_path}")

    print(f"\nDone! Symbol file written to: {args.output_toml}")


if __name__ == '__main__':
    main()
