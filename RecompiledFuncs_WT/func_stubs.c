// Stubs for ignored functions that are still called by recompiled code.
// These were in the 'ignored' list in rampage_wt.toml but have callers.
#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

static int stub_call_count[12] = {0};

RECOMP_FUNC void func_8002DA90(uint8_t* rdram, recomp_context* ctx) {
    if (stub_call_count[0]++ < 5) { fprintf(stderr, "[STUB] func_8002DA90 called (a0=0x%08X a1=0x%08X)\n", (unsigned)ctx->r4, (unsigned)ctx->r5); fflush(stderr); }
}
RECOMP_FUNC void func_8005DE4C(uint8_t* rdram, recomp_context* ctx) {
    if (stub_call_count[1]++ < 5) { fprintf(stderr, "[STUB] func_8005DE4C called (a0=0x%08X a1=0x%08X)\n", (unsigned)ctx->r4, (unsigned)ctx->r5); fflush(stderr); }
}
RECOMP_FUNC void func_8006AA80(uint8_t* rdram, recomp_context* ctx) {
    if (stub_call_count[2]++ < 5) { fprintf(stderr, "[STUB] func_8006AA80 called (a0=0x%08X a1=0x%08X)\n", (unsigned)ctx->r4, (unsigned)ctx->r5); fflush(stderr); }
}
RECOMP_FUNC void func_8006B290(uint8_t* rdram, recomp_context* ctx) {
    if (stub_call_count[3]++ < 5) { fprintf(stderr, "[STUB] func_8006B290 called (a0=0x%08X a1=0x%08X)\n", (unsigned)ctx->r4, (unsigned)ctx->r5); fflush(stderr); }
}
RECOMP_FUNC void func_8006B520(uint8_t* rdram, recomp_context* ctx) {
    if (stub_call_count[4]++ < 5) { fprintf(stderr, "[STUB] func_8006B520 called (a0=0x%08X a1=0x%08X)\n", (unsigned)ctx->r4, (unsigned)ctx->r5); fflush(stderr); }
}
RECOMP_FUNC void func_8006E2B4(uint8_t* rdram, recomp_context* ctx) {
    if (stub_call_count[5]++ < 5) { fprintf(stderr, "[STUB] func_8006E2B4 called (a0=0x%08X a1=0x%08X)\n", (unsigned)ctx->r4, (unsigned)ctx->r5); fflush(stderr); }
}
RECOMP_FUNC void func_8006E440(uint8_t* rdram, recomp_context* ctx) {
    if (stub_call_count[6]++ < 5) { fprintf(stderr, "[STUB] func_8006E440 called (a0=0x%08X a1=0x%08X)\n", (unsigned)ctx->r4, (unsigned)ctx->r5); fflush(stderr); }
}
RECOMP_FUNC void func_8006E4C0(uint8_t* rdram, recomp_context* ctx) {
    if (stub_call_count[7]++ < 5) { fprintf(stderr, "[STUB] func_8006E4C0 called (a0=0x%08X a1=0x%08X)\n", (unsigned)ctx->r4, (unsigned)ctx->r5); fflush(stderr); }
}
RECOMP_FUNC void func_8006FCF0(uint8_t* rdram, recomp_context* ctx) {
    if (stub_call_count[8]++ < 5) { fprintf(stderr, "[STUB] func_8006FCF0 called (a0=0x%08X a1=0x%08X)\n", (unsigned)ctx->r4, (unsigned)ctx->r5); fflush(stderr); }
}
RECOMP_FUNC void func_8006FD20(uint8_t* rdram, recomp_context* ctx) {
    if (stub_call_count[9]++ < 5) { fprintf(stderr, "[STUB] func_8006FD20 called (a0=0x%08X a1=0x%08X)\n", (unsigned)ctx->r4, (unsigned)ctx->r5); fflush(stderr); }
}
RECOMP_FUNC void func_80072EE0(uint8_t* rdram, recomp_context* ctx) {
    if (stub_call_count[10]++ < 5) { fprintf(stderr, "[STUB] func_80072EE0 called (a0=0x%08X a1=0x%08X)\n", (unsigned)ctx->r4, (unsigned)ctx->r5); fflush(stderr); }
}
RECOMP_FUNC void func_80072EF0(uint8_t* rdram, recomp_context* ctx) {
    if (stub_call_count[11]++ < 5) { fprintf(stderr, "[STUB] func_80072EF0 called (a0=0x%08X a1=0x%08X)\n", (unsigned)ctx->r4, (unsigned)ctx->r5); fflush(stderr); }
}

// Internal N64 OS functions - handled by ultramodern at a higher level.
// These are in N64Recomp's ignored_funcs list but still referenced by recompiled code.
RECOMP_FUNC void __osEnqueueThread_recomp(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void __osViInit_recomp(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void __osViSwapContext_recomp(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void __osPfsSelectBank_recomp(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void __osContRamWrite_recomp(uint8_t* rdram, recomp_context* ctx) { }
// __osSiRelAccess: return the SI access token to the queue
// SI access queue is at 0x800E3888
RECOMP_FUNC void __osSiRelAccess_recomp(uint8_t* rdram, recomp_context* ctx) {
    // osSendMesg(&siAccessQueue, NULL, OS_MESG_NOBLOCK)
    ctx->r4 = 0x800E3888u;  // queue address
    ctx->r5 = 0;             // msg = NULL (token)
    ctx->r6 = 0;             // OS_MESG_NOBLOCK
    osSendMesg_recomp(rdram, ctx);
}
RECOMP_FUNC void osPfsIsPlug_recomp(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void __osGetId_recomp(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void __osContAddressCrc_recomp(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void __osInsertTimer_recomp(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void __osPfsRWInode_recomp(uint8_t* rdram, recomp_context* ctx) { }
// __osPiCreateAccessQueue: initialize PI access queue with one token message
// Queue at 0x80136568, message buffer at 0x80136580
RECOMP_FUNC void __osPiCreateAccessQueue_recomp(uint8_t* rdram, recomp_context* ctx) {
    // osCreateMesgQueue(&piAccessQueue, &piAccessBuf, 1)
    ctx->r4 = 0x80136568u;  // queue address
    ctx->r5 = 0x80136580u;  // msg buffer (just after the queue struct)
    ctx->r6 = 1;             // count = 1
    osCreateMesgQueue_recomp(rdram, ctx);

    // osSendMesg(&piAccessQueue, NULL, OS_MESG_NOBLOCK) - put initial token
    ctx->r4 = 0x80136568u;
    ctx->r5 = 0;
    ctx->r6 = 0;             // OS_MESG_NOBLOCK
    osSendMesg_recomp(rdram, ctx);
}
RECOMP_FUNC void __osPopThread_recomp(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void __osSetCompare_recomp(uint8_t* rdram, recomp_context* ctx) { }
RECOMP_FUNC void __osSetTimerIntr_recomp(uint8_t* rdram, recomp_context* ctx) { }
// __osSiCreateAccessQueue: initialize SI access queue with one token message
// Queue at 0x800E3888, message buffer at 0x800E38A0
RECOMP_FUNC void __osSiCreateAccessQueue_recomp(uint8_t* rdram, recomp_context* ctx) {
    // osCreateMesgQueue(&siAccessQueue, &siAccessBuf, 1)
    ctx->r4 = 0x800E3888u;  // queue address
    ctx->r5 = 0x800E38A0u;  // msg buffer (just after the queue struct)
    ctx->r6 = 1;             // count = 1
    osCreateMesgQueue_recomp(rdram, ctx);

    // osSendMesg(&siAccessQueue, NULL, OS_MESG_NOBLOCK) - put initial token
    ctx->r4 = 0x800E3888u;
    ctx->r5 = 0;
    ctx->r6 = 0;             // OS_MESG_NOBLOCK
    osSendMesg_recomp(rdram, ctx);
}
RECOMP_FUNC void osPiRawReadIo_recomp(uint8_t* rdram, recomp_context* ctx) { }
