// SN64 ROM helper functions - C-callable wrappers for librecomp ROM access.
// Used by the SN64 audio stubs to DMA audio data from ROM to RDRAM.
#include "librecomp/game.hpp"
#include "librecomp/addresses.hpp"
#include "recomp.h"
#include "sn64_rom_helpers.h"
#include <cstdio>

extern "C" {

void sn64_rom_to_rdram(uint8_t* rdram, uint32_t rom_offset, uint32_t rdram_addr, uint32_t size) {
    uint32_t physical_addr = rom_offset + recomp::rom_base;
    gpr ram_addr = (gpr)(int64_t)(int32_t)rdram_addr;
    fprintf(stderr, "[SN64-DMA] ROM 0x%08X -> RDRAM 0x%08X, size=0x%X\n",
            rom_offset, rdram_addr, size);
    fflush(stderr);
    recomp::do_rom_read(rdram, ram_addr, physical_addr, size);
}

uint32_t sn64_read_rom_word(uint32_t rom_offset) {
    auto rom = recomp::get_rom();
    if (rom_offset + 4 > rom.size()) return 0;
    return ((uint32_t)rom[rom_offset] << 24) | ((uint32_t)rom[rom_offset+1] << 16) |
           ((uint32_t)rom[rom_offset+2] << 8) | (uint32_t)rom[rom_offset+3];
}

uint16_t sn64_read_rom_half(uint32_t rom_offset) {
    auto rom = recomp::get_rom();
    if (rom_offset + 2 > rom.size()) return 0;
    return ((uint16_t)rom[rom_offset] << 8) | (uint16_t)rom[rom_offset+1];
}

} // extern "C"
