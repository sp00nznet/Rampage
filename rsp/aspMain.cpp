// RSP Audio microcode stub for Rampage
// The actual audio microcode would need to be HLE'd for proper audio
#include "librecomp/rsp.hpp"

RspExitReason aspMain(uint8_t* rdram, uint32_t ucode_addr) {
    // Stub: no audio HLE implementation yet
    return RspExitReason::Broke;
}
