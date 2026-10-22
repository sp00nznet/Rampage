// Rampage: World Tour - hand-written replacements for functions the recompiler leaves out, and
// the helpers its [[patches.hook]] entries call (rampage_wt.toml).
//
// Three groups:
//  - functions in rampage_wt.toml's ignored list that still have callers: no-ops;
//  - libultra internals the runtime doesn't provide: no-ops, or the access-queue setup they do;
//  - the SN64 audio engine entry points (Midway's sound library, loaded into RAM at runtime and
//    not recompiled): enough behaviour for the game to boot and play silently.
#include <stdio.h>
#include <string.h>

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
NOOP(osPfsIsPlug_recomp)
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

// ---- SN64 audio engine ----
// ponytail: silent. Real audio means recompiling the SN64 code the game loads into RAM
// (ROADMAP: audio).

// alInit: global library init.
NOOP(stub_801378DC)

// Fetch the next audio command list; 0 = nothing to process.
RECOMP_FUNC void stub_80137FEC(uint8_t* rdram, recomp_context* ctx) { ctx->r2 = 0; }

// DMA wait: DMA is synchronous here.
RECOMP_FUNC void stub_80138934(uint8_t* rdram, recomp_context* ctx) { ctx->r2 = 0; }

// Size of the ctl bank at ROM a0 (0x906290). Measured from the ROM: 0x11008 bytes.
RECOMP_FUNC void stub_80138C30(uint8_t* rdram, recomp_context* ctx) { ctx->r2 = 0x11008; }

// Copy the ctl bank: a0 = ROM offset, a1 = RDRAM destination, a2 = size.
RECOMP_FUNC void stub_80138EFC(uint8_t* rdram, recomp_context* ctx) {
    sn64_rom_to_rdram(rdram, (uint32_t)ctx->r4, (uint32_t)ctx->r5, (uint32_t)ctx->r6);
    ctx->r2 = 0;
}

// Get a handle; callers treat 0 as failure.
RECOMP_FUNC void stub_80142BCC(uint8_t* rdram, recomp_context* ctx) {
    static uint32_t next_handle = 1;
    ctx->r2 = next_handle++;
}

// Size of the sequence table at ROM a1 (0x9172D0): it runs up to the sample data at 0x9253C0.
RECOMP_FUNC void stub_801430E0(uint8_t* rdram, recomp_context* ctx) { ctx->r2 = 0xE0F0; }

// Load the sequence table: a1 = ROM offset, a3 = destination, stack+0x10 = size.
RECOMP_FUNC void stub_801431A4(uint8_t* rdram, recomp_context* ctx) {
    uint32_t size = MEM_W(0x10, ctx->r29);
    if (size != 0 && (uint32_t)ctx->r7 != 0) {
        sn64_rom_to_rdram(rdram, (uint32_t)ctx->r5, (uint32_t)ctx->r7, size);
    }
    ctx->r2 = 0;
}

// Create the music / sound effect players.
RECOMP_FUNC void stub_801436F0(uint8_t* rdram, recomp_context* ctx) { ctx->r2 = 0; }
RECOMP_FUNC void stub_8014376C(uint8_t* rdram, recomp_context* ctx) { ctx->r2 = 0; }

// ---- Hook helpers ----

// Called with the game state in $v0. On a change, clear the flags that make the next screen
// reload its textures, and blank both framebuffers (400x240 RGBA5551).
void wt_on_state(uint8_t* rdram, recomp_context* ctx) {
    static uint16_t prev_state = 0;
    uint16_t state = (uint16_t)ctx->r2;
    if (state != prev_state && prev_state != 0) {
        MEM_H(0, VADDR(0x800BFE96)) = 0;  // texture tables loaded (read by func_80037C48)
        MEM_H(0, VADDR(0x800BFE8E)) = 0;  // transition countdown
        MEM_H(0, VADDR(0x800BED98)) = 0;  // secondary init flag
        memset(rdram + 0x001A5EC0, 0, 400 * 240 * 2);
        memset(rdram + 0x001770C0, 0, 400 * 240 * 2);
    }
    prev_state = state;
}

void wt_force_fade_flag(uint8_t* rdram) {
    MEM_H(0, VADDR(0x800BF7A4)) = 1;
}

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
