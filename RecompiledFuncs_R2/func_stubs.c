#include <stdio.h>
#include "recomp.h"
#include "funcs.h"

// Controller init function override
// func_800724D8 is the game's internal osContInit variant that does SI operations
// and blocks on osRecvMesg waiting for SI completion. Since SI hardware isn't
// emulated, redirect to osContInit_recomp which handles this properly.
extern void osContInit_recomp(uint8_t* rdram, recomp_context* ctx);
RECOMP_FUNC void func_800724D8(uint8_t* rdram, recomp_context* ctx) {
    // a0 = mq, a1 = bitpattern_out, a2 = status_out
    // osContInit_recomp reads these from ctx registers
    osContInit_recomp(rdram, ctx);
}

// PI DMA request function override
// Original func_80072B20 sends DMA ioMesg to the PI manager thread, but
// osCreatePiManager is stubbed. Override: do synchronous DMA directly.
//
// Args: a0=ioMesg buffer, a1=priority (0=send, 1=jam), a2=type_flag, a3=devAddr,
//       sp+0x10=dramAddr, sp+0x14=size, sp+0x18=completion_queue
// NOTE: a1 is NOT the DMA direction! It controls osSendMesg vs osJamMesg.
//       DMA is always a ROM read (direction=0).
extern void osPiStartDma_recomp(uint8_t* rdram, recomp_context* ctx);
RECOMP_FUNC void func_80072B20(uint8_t* rdram, recomp_context* ctx) {
    uint32_t priority = (uint32_t)ctx->r5;   // a1 = priority (not direction!)
    uint32_t devAddr = (uint32_t)ctx->r7;    // a3 = ROM/device address
    uint32_t dramAddr = (uint32_t)MEM_W(0x10, ctx->r29);
    uint32_t size = (uint32_t)MEM_W(0x14, ctx->r29);
    uint32_t mq = (uint32_t)MEM_W(0x18, ctx->r29);

    static int dma_count = 0;
    if (dma_count < 50) {
        fprintf(stderr, "[R2-DMA] #%d pri=%d dev=0x%08X dram=0x%08X size=0x%X mq=0x%08X\n",
                dma_count, priority, devAddr, dramAddr, size, mq);
        fflush(stderr);
    }
    dma_count++;

    // Remap to osPiStartDma register convention:
    // r4 = mb (unused), r5 = pri (unused), r6 = direction (always 0=read), r7 = devAddr
    ctx->r6 = 0;  // direction = OS_READ (read from cart ROM to DRAM)
    // r7 already has devAddr
    // sp+0x10=dramAddr, sp+0x14=size, sp+0x18=mq are already correct

    osPiStartDma_recomp(rdram, ctx);
    ctx->r2 = 0; // return success
}

RECOMP_FUNC void func_800702D0(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80071DC0(uint8_t* rdram, recomp_context* ctx) { }
// func_80071E70 = osSpTaskStartGo - starts RSP task execution
extern void osSpTaskStartGo_recomp(uint8_t* rdram, recomp_context* ctx);
RECOMP_FUNC void func_80071E70(uint8_t* rdram, recomp_context* ctx) {
    osSpTaskStartGo_recomp(rdram, ctx);
}
RECOMP_FUNC void func_80072BD0(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80074C60(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80075050(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_800759DC(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80075AE4(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80075B2C(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80075B3C(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_800760C0(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80076220(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80005768(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80005938(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_800059A0(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80005A90(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80005C80(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80005CD8(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80005D30(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80005E80(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80005ED8(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80005FB0(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80005FC0(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80005FE8(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80006020(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_800061E0(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80008B28(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80008B68(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void func_80008B80(uint8_t* rdram, recomp_context* ctx) { }
