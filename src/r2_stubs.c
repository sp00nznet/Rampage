// Rampage 2: Universal Tour - hand-written replacements for functions the recompiler leaves out
// (rampage2_ut.toml's ignored list) and libultra internals the runtime doesn't provide.
#include <stdio.h>

#include "recomp.h"
#include "funcs.h"
#include "hooks.h"

// Logs the first call to an otherwise silent stub, so a newly reached one shows up in the log.
#define LOG_ONCE(name) do { static int seen; if (!seen++) fprintf(stderr, "[stub] %s (a0=0x%08X a1=0x%08X)\n", name, (unsigned)ctx->r4, (unsigned)ctx->r5); } while (0)
#define NOOP(name) RECOMP_FUNC void name(uint8_t* rdram, recomp_context* ctx) { LOG_ONCE(#name); }

// ---- libultra internals ----
// Their only callers are libultra code the runtime bypasses: the VI manager thread (never
// started; osCreateViManager is the runtime's), osDestroyThread's queue handling, and the
// controller pak routines (paks aren't emulated, so pak access fails as if none is inserted).
NOOP(__osDispatchThread_recomp)
NOOP(__osDequeueThread_recomp)
NOOP(__osTimerInterrupt_recomp)
NOOP(__osViSwapContext_recomp)
NOOP(__osViGetCurrentContext_recomp)
NOOP(__osSiGetAccess_recomp)
NOOP(__osSiRelAccess_recomp)
NOOP(__osContRamRead_recomp)
NOOP(__osContRamWrite_recomp)
NOOP(__osPfsGetStatus_recomp)
NOOP(__osPfsRWInode_recomp)
NOOP(__osPfsSelectBank_recomp)
NOOP(__osCheckId_recomp)
NOOP(osPfsIsPlug_recomp)
