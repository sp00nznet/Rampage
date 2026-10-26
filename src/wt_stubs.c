// Rampage: World Tour - hand-written replacements for functions the recompiler leaves out, and
// the helpers its [[patches.hook]] entries call (rampage_wt.toml).
//
// Three groups:
//  - functions in rampage_wt.toml's ignored list that still have callers: no-ops;
//  - libultra internals the runtime doesn't provide: no-ops, or the access-queue setup they do;
//  - the sound engine's own copies of libultra's AI and interrupt calls: forwarded to the runtime.
#include <stdio.h>

#include "recomp.h"
#include "funcs.h"
#include "hooks.h"

// Logs the first call to an otherwise silent stub, so a newly reached one shows up in the log.
#define LOG_ONCE(name) do { static int seen; if (!seen++) fprintf(stderr, "[stub] %s (a0=0x%08X a1=0x%08X)\n", name, (unsigned)ctx->r4, (unsigned)ctx->r5); } while (0)
// RDRAM address as the sign-extended register value the MEM_* macros expect.
#define VADDR(a) ((gpr)(int32_t)(a))
#define NOOP(name) RECOMP_FUNC void name(uint8_t* rdram, recomp_context* ctx) { LOG_ONCE(#name); }

// ---- Ignored functions that are still called ----
NOOP(func_8002DA90)
NOOP(func_8005DE4C)
NOOP(func_8006AA80)
NOOP(func_8006B290)
NOOP(func_8006B520)
NOOP(func_8006E2B4)
NOOP(func_8006E440)
NOOP(func_8006E4C0)
NOOP(func_8006FCF0)
NOOP(func_8006FD20)
NOOP(func_80072EE0)
NOOP(func_80072EF0)

// ---- libultra internals ----
NOOP(__osEnqueueThread_recomp)
NOOP(__osViInit_recomp)
NOOP(__osViSwapContext_recomp)
NOOP(__osPfsSelectBank_recomp)
NOOP(__osContRamWrite_recomp)
NOOP(__osGetId_recomp)
NOOP(__osContAddressCrc_recomp)
NOOP(__osInsertTimer_recomp)
NOOP(__osPfsRWInode_recomp)
NOOP(__osPopThread_recomp)
NOOP(__osSetCompare_recomp)
NOOP(__osSetTimerIntr_recomp)
NOOP(osPiRawReadIo_recomp)

// The game's SI and PI access queues: a one-message queue holding a token.
#define SI_ACCESS_QUEUE 0x800E3888u
#define PI_ACCESS_QUEUE 0x80136568u

static void create_access_queue(uint8_t* rdram, recomp_context* ctx, uint32_t queue) {
    ctx->r4 = queue;
    ctx->r5 = queue + 0x18;  // message buffer just after the OSMesgQueue
    ctx->r6 = 1;
    osCreateMesgQueue_recomp(rdram, ctx);
    ctx->r4 = queue;
    ctx->r5 = 0;
    ctx->r6 = 0;             // OS_MESG_NOBLOCK
    osSendMesg_recomp(rdram, ctx);
}

RECOMP_FUNC void __osSiCreateAccessQueue_recomp(uint8_t* rdram, recomp_context* ctx) {
    create_access_queue(rdram, ctx, SI_ACCESS_QUEUE);
}

RECOMP_FUNC void __osPiCreateAccessQueue_recomp(uint8_t* rdram, recomp_context* ctx) {
    create_access_queue(rdram, ctx, PI_ACCESS_QUEUE);
}

// Returns the SI access token.
RECOMP_FUNC void __osSiRelAccess_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r4 = SI_ACCESS_QUEUE;
    ctx->r5 = 0;
    ctx->r6 = 0;
    osSendMesg_recomp(rdram, ctx);
}

// ---- The SN64 segment's own libultra calls ----
// The sound engine (the .sn64 section) links its own copies of these. Named, they would clash with
// the main segment's copies, so they're routed to the runtime's versions here.
void osAiSetNextBuffer_recomp(uint8_t* rdram, recomp_context* ctx);
void osAiGetLength_recomp(uint8_t* rdram, recomp_context* ctx);
void osAiSetFrequency_recomp(uint8_t* rdram, recomp_context* ctx);
void __osDisableInt_recomp(uint8_t* rdram, recomp_context* ctx);
void __osRestoreInt_recomp(uint8_t* rdram, recomp_context* ctx);
RECOMP_FUNC void sn64_osAiSetFrequency(uint8_t* rdram, recomp_context* ctx) { osAiSetFrequency_recomp(rdram, ctx); }
RECOMP_FUNC void sn64_osAiSetNextBuffer(uint8_t* rdram, recomp_context* ctx) { osAiSetNextBuffer_recomp(rdram, ctx); }
RECOMP_FUNC void sn64_osAiGetLength(uint8_t* rdram, recomp_context* ctx) { osAiGetLength_recomp(rdram, ctx); }
RECOMP_FUNC void sn64___osAiDeviceBusy(uint8_t* rdram, recomp_context* ctx) { ctx->r2 = 0; }
RECOMP_FUNC void sn64___osDisableInt(uint8_t* rdram, recomp_context* ctx) { __osDisableInt_recomp(rdram, ctx); }
RECOMP_FUNC void sn64___osRestoreInt(uint8_t* rdram, recomp_context* ctx) { __osRestoreInt_recomp(rdram, ctx); }

// ---- Hook helpers ----

// Button maps at 0x80085BD0 (menus) and 0x80085BF0/0x80085C10/0x80085C30 (players 1-3):
// 16 halfwords each, N64 button bit -> game action bit. Words hold two entries in RDRAM's
// swapped order (upper half = even entry).
void wt_write_button_maps(uint8_t* rdram) {
    const gpr base = VADDR(0x80080000);
    MEM_W(0x5BE0, base) = 0x00080004; MEM_W(0x5BE4, base) = 0x00020001;
    MEM_W(0x5BE8, base) = 0x01000020; MEM_W(0x5BEC, base) = 0x00400010;
    for (uint32_t map = 0x5BF0; map <= 0x5C30; map += 0x20) {
        MEM_W(map + 0x04, base) = 0x00200000;
        MEM_W(map + 0x10, base) = 0x00080004; MEM_W(map + 0x14, base) = 0x00020001;
        MEM_W(map + 0x18, base) = 0x01000000; MEM_W(map + 0x1C, base) = 0x00100040;
    }
}

// Pak setup for an empty slot ($s1 = channel): store PFS_ERR_NOPACK in the slot's error word
// (0x8010CE68 + channel * 0x90, offset 0x6C), where the game's pak calls read it back.
void wt_no_pak(uint8_t* rdram, recomp_context* ctx) {
    MEM_W(0x6C, VADDR(0x8010CE68 + (uint32_t)ctx->r17 * 0x90)) = 1;
}

// osPfsIsPlug(queue, &pattern): no controller has a pak (paks aren't emulated). A bare no-op left the
// result and the pattern as whatever happened to be there.
RECOMP_FUNC void osPfsIsPlug_recomp(uint8_t* rdram, recomp_context* ctx) {
    MEM_B(0, ctx->r5) = 0;
    ctx->r2 = 0;
}
