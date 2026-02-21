#ifndef SN64_ROM_HELPERS_H
#define SN64_ROM_HELPERS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Copy ROM data to RDRAM. rom_offset is the N64 cart-relative offset (e.g. 0x906290).
// rdram_addr is the N64 virtual address (e.g. 0x80xxxxxx).
void sn64_rom_to_rdram(uint8_t* rdram, uint32_t rom_offset, uint32_t rdram_addr, uint32_t size);

// Read a big-endian 32-bit word directly from ROM at the given offset.
uint32_t sn64_read_rom_word(uint32_t rom_offset);

// Read a big-endian 16-bit halfword directly from ROM at the given offset.
uint16_t sn64_read_rom_half(uint32_t rom_offset);

#ifdef __cplusplus
}
#endif

#endif
