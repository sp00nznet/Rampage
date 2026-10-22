// Helpers called from the [[patches.hook]] entries in rampage_wt.toml / rampage2_ut.toml.
// Force-included into the generated code (CMakeLists.txt), so hook text can call them directly.
#ifndef RAMPAGE_HOOKS_H
#define RAMPAGE_HOOKS_H

#include "recomp.h"

#ifdef __cplusplus
extern "C" {
#endif

// From the runtime: lets other game threads run. ultramodern only switches threads when one
// blocks or yields, so a loop polling memory that another thread sets must yield to finish.
void yield_self(uint8_t* rdram);

// World Tour (src/wt_stubs.c)
void wt_on_state(uint8_t* rdram, recomp_context* ctx);
void wt_force_fade_flag(uint8_t* rdram);
void wt_write_button_maps(uint8_t* rdram);

// SN64 audio data helpers (src/sn64_rom_helpers.cpp)
void sn64_rom_to_rdram(uint8_t* rdram, uint32_t rom_offset, uint32_t rdram_addr, uint32_t size);

#ifdef __cplusplus
}
#endif

#endif
