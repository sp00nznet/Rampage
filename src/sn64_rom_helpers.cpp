// ROM access for the SN64 audio stubs (src/wt_stubs.c): copies audio data the game asks its
// sound engine to load straight from the cartridge image into RDRAM.
#include "librecomp/addresses.hpp"
#include "librecomp/game.hpp"
#include "recomp.h"

extern "C" void sn64_rom_to_rdram(uint8_t* rdram, uint32_t rom_offset, uint32_t rdram_addr, uint32_t size) {
    recomp::do_rom_read(rdram, (gpr)(int32_t)rdram_addr, rom_offset + recomp::rom_base, size);
}
