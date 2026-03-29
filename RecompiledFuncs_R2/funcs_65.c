#include <stdio.h>
#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_8005E844(uint8_t* rdram, recomp_context* ctx);
void func_8005F130(uint8_t* rdram, recomp_context* ctx);
void func_8005F340(uint8_t* rdram, recomp_context* ctx);
void func_8005F380(uint8_t* rdram, recomp_context* ctx);
void func_8005F530(uint8_t* rdram, recomp_context* ctx);
void func_8005F548(uint8_t* rdram, recomp_context* ctx);
void func_80060454(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_8005E370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005E374: slti        $a0, $a0, 0x2EE0
    ctx->r4 = SIGNED(ctx->r4) < 0X2EE0 ? 1 : 0;
    // 0x8005E378: beq         $a0, $zero, L_8005E388
    if (ctx->r4 == 0) {
        // 0x8005E37C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8005E388;
    }
    // 0x8005E37C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005E380: jal         0x8005F380
    // 0x8005E384: nop

    func_8005F380(rdram, ctx);
        goto after_0;
    // 0x8005E384: nop

    after_0:
L_8005E388:
    // 0x8005E388: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005E38C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005E390: jr          $ra
    // 0x8005E394: nop

    return;
    // 0x8005E394: nop

;}
RECOMP_FUNC void func_8005E398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005E39C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
L_8005E3A0:
    // 0x8005E3A0: jal         0x8005C838
    // 0x8005E3A4: nop

    func_8005C838(rdram, ctx);
        goto after_0;
    // 0x8005E3A4: nop

    after_0:
    // 0x8005E3A8: bne         $v0, $zero, L_8005E3A0
    if (ctx->r2 != 0) {
        // 0x8005E3AC: lui         $a1, 0xBC00
        ctx->r5 = S32(0XBC00 << 16);
            goto L_8005E3A0;
    }
    // 0x8005E3AC: lui         $a1, 0xBC00
    ctx->r5 = S32(0XBC00 << 16);
    // 0x8005E3B0: ori         $a1, $a1, 0x806
    ctx->r5 = ctx->r5 | 0X806;
    // 0x8005E3B4: lui         $a2, 0xBC00
    ctx->r6 = S32(0XBC00 << 16);
    // 0x8005E3B8: ori         $a2, $a2, 0x6
    ctx->r6 = ctx->r6 | 0X6;
    // 0x8005E3BC: lui         $a3, 0x103
    ctx->r7 = S32(0X103 << 16);
    // 0x8005E3C0: ori         $a3, $a3, 0x40
    ctx->r7 = ctx->r7 | 0X40;
    // 0x8005E3C4: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x8005E3C8: ori         $t1, $t1, 0x40
    ctx->r9 = ctx->r9 | 0X40;
    // 0x8005E3CC: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8005E3D0: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8005E3D4: lw          $v1, 0x5578($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5578);
    // 0x8005E3D8: ori         $t0, $t0, 0x40
    ctx->r8 = ctx->r8 | 0X40;
    // 0x8005E3DC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8005E3E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E3E4: sw          $v0, 0x4DF0($at)
    MEM_W(0X4DF0, ctx->r1) = ctx->r2;
    // 0x8005E3E8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005E3EC: addiu       $v0, $v0, -0x1CE0
    ctx->r2 = ADD32(ctx->r2, -0X1CE0);
    // 0x8005E3F0: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    // 0x8005E3F4: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8005E3F8: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x8005E3FC: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8005E400: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8005E404: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8005E408: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005E40C: lw          $v1, 0x3EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3EF0);
    // 0x8005E410: sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4 << 6);
    // 0x8005E414: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8005E418: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8005E41C: sw          $a0, -0x1038($at)
    MEM_W(-0X1038, ctx->r1) = ctx->r4;
    // 0x8005E420: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8005E424: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005E428: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005E42C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8005E430: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005E434: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005E438: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8005E43C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8005E440: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x8005E444: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005E448: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005E44C: lui         $v0, 0x9
    ctx->r2 = S32(0X9 << 16);
    // 0x8005E450: addiu       $v0, $v0, -0x7C8
    ctx->r2 = ADD32(ctx->r2, -0X7C8);
    // 0x8005E454: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8005E458: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x8005E45C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005E460: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005E464: lui         $v0, 0x9
    ctx->r2 = S32(0X9 << 16);
    // 0x8005E468: addiu       $v0, $v0, -0x810
    ctx->r2 = ADD32(ctx->r2, -0X810);
    // 0x8005E46C: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x8005E470: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x8005E474: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005E478: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005E47C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005E480: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x8005E484: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
    // 0x8005E488: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8005E48C: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8005E490: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005E494: sw          $a2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r6;
    // 0x8005E498: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8005E49C: sw          $a1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r5;
    // 0x8005E4A0: sw          $a1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r5;
    // 0x8005E4A4: sw          $a3, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r7;
    // 0x8005E4A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005E4AC: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005E4B0: sw          $t1, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r9;
    // 0x8005E4B4: jal         0x8005F530
    // 0x8005E4B8: sw          $a0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r4;
    func_8005F530(rdram, ctx);
        goto after_1;
    // 0x8005E4B8: sw          $a0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r4;
    after_1:
    // 0x8005E4BC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005E4C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005E4C4: jr          $ra
    // 0x8005E4C8: nop

    return;
    // 0x8005E4C8: nop

;}
RECOMP_FUNC void func_8005E4CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E4CC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005E4D0: lw          $v1, 0x3EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3EF0);
;}
RECOMP_FUNC void func_8005E4D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E4D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005E4D8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005E4DC: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8005E4E0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005E4E4: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005E4E8: lui         $v0, 0xE900
    ctx->r2 = S32(0XE900 << 16);
    // 0x8005E4EC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005E4F0: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8005E4F4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005E4F8: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005E4FC: lui         $v0, 0xB800
    ctx->r2 = S32(0XB800 << 16);
    // 0x8005E500: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005E504: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8005E508: jal         0x8005C8C8
    // 0x8005E50C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    func_8005C8C8(rdram, ctx);
        goto after_0;
    // 0x8005E50C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    after_0:
    // 0x8005E510: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005E514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005E518: jr          $ra
    // 0x8005E51C: nop

    return;
    // 0x8005E51C: nop

;}
RECOMP_FUNC void func_8005E520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E520: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005E524: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005E528: jal         0x80070590
    // 0x8005E52C: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x8005E52C: nop

    after_0:
    // 0x8005E530: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8005E534: lw          $a0, -0x30F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X30F8);
    // 0x8005E538: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8005E53C: lw          $a1, -0x30F4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X30F4);
    // 0x8005E540: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005E544: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    // 0x8005E548: sltu        $t0, $v1, $a1
    ctx->r8 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8005E54C: subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // 0x8005E550: subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // 0x8005E554: subu        $a0, $a0, $t0
    ctx->r4 = SUB32(ctx->r4, ctx->r8);
    // 0x8005E558: sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4 << 6);
    // 0x8005E55C: srl         $v0, $a1, 26
    ctx->r2 = S32(U32(ctx->r5) >> 26);
    // 0x8005E560: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x8005E564: jal         0x8007E4E0
    // 0x8005E568: sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5 << 6);
    func_8007E4E0(rdram, ctx);
        goto after_1;
    // 0x8005E568: sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5 << 6);
    after_1:
    // 0x8005E56C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8005E570: sw          $v0, -0x3088($at)
    MEM_W(-0X3088, ctx->r1) = ctx->r2;
    // 0x8005E574: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8005E578: sw          $v1, -0x3084($at)
    MEM_W(-0X3084, ctx->r1) = ctx->r3;
    // 0x8005E57C: jal         0x8005E370
    // 0x8005E580: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8005E370(rdram, ctx);
        goto after_2;
    // 0x8005E580: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_2:
    // 0x8005E584: jal         0x8005C158
    // 0x8005E588: nop

    func_8005C158(rdram, ctx);
        goto after_3;
    // 0x8005E588: nop

    after_3:
    // 0x8005E58C: jal         0x80070590
    // 0x8005E590: nop

    osGetTime_recomp(rdram, ctx);
        goto after_4;
    // 0x8005E590: nop

    after_4:
    // 0x8005E594: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8005E598: lw          $a0, -0x30F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X30F8);
    // 0x8005E59C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8005E5A0: lw          $a1, -0x30F4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X30F4);
    // 0x8005E5A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005E5A8: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    // 0x8005E5AC: sltu        $t0, $v1, $a1
    ctx->r8 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8005E5B0: subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // 0x8005E5B4: subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // 0x8005E5B8: subu        $a0, $a0, $t0
    ctx->r4 = SUB32(ctx->r4, ctx->r8);
    // 0x8005E5BC: sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4 << 6);
    // 0x8005E5C0: srl         $v0, $a1, 26
    ctx->r2 = S32(U32(ctx->r5) >> 26);
    // 0x8005E5C4: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x8005E5C8: jal         0x8007E4E0
    // 0x8005E5CC: sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5 << 6);
    func_8007E4E0(rdram, ctx);
        goto after_5;
    // 0x8005E5CC: sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5 << 6);
    after_5:
    // 0x8005E5D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8005E5D4: sw          $v0, -0x3088($at)
    MEM_W(-0X3088, ctx->r1) = ctx->r2;
    // 0x8005E5D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8005E5DC: sw          $v1, -0x3084($at)
    MEM_W(-0X3084, ctx->r1) = ctx->r3;
    // 0x8005E5E0: jal         0x8005C95C
    // 0x8005E5E4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8005C95C(rdram, ctx);
        goto after_6;
    // 0x8005E5E4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_6:
L_8005E5E8:
    // BYPASS: Force frame-done flag to 1. On real N64, this is set by the scheduler
    // after osViSwapBuffer completes. R2's first frame has no display list submission,
    // so the flag never gets set naturally. Force it so the render loop can continue.
    MEM_H(0X32A0, S32(0X8017 << 16)) = 1;
    // 0x8005E5E8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005E5EC: lhu         $v0, 0x32A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X32A0);
    // 0x8005E5F4: nop

    // 0x8005E5F8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8005E5FC: lw          $v0, -0x74E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X74E0);
    // 0x8005E600: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005E604: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8005E608: sw          $v0, -0x74E0($at)
    MEM_W(-0X74E0, ctx->r1) = ctx->r2;
    // 0x8005E60C: jal         0x8005E4CC
    // 0x8005E610: nop

    func_8005E4CC(rdram, ctx);
        goto after_7;
    // 0x8005E610: nop

    after_7:
    // 0x8005E614: jal         0x80070590
    // 0x8005E618: nop

    osGetTime_recomp(rdram, ctx);
        goto after_8;
    // 0x8005E618: nop

    after_8:
    // 0x8005E61C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8005E620: lw          $a0, -0x30F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X30F8);
    // 0x8005E624: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8005E628: lw          $a1, -0x30F4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X30F4);
    // 0x8005E62C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005E630: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    // 0x8005E634: sltu        $t0, $v1, $a1
    ctx->r8 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8005E638: subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // 0x8005E63C: subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // 0x8005E640: subu        $a0, $a0, $t0
    ctx->r4 = SUB32(ctx->r4, ctx->r8);
    // 0x8005E644: sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4 << 6);
    // 0x8005E648: srl         $v0, $a1, 26
    ctx->r2 = S32(U32(ctx->r5) >> 26);
    // 0x8005E64C: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x8005E650: jal         0x8007E4E0
    // 0x8005E654: sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5 << 6);
    func_8007E4E0(rdram, ctx);
        goto after_9;
    // 0x8005E654: sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5 << 6);
    after_9:
    // 0x8005E658: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005E65C: sw          $v0, 0x100($at)
    MEM_W(0X100, ctx->r1) = ctx->r2;
    // 0x8005E660: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005E664: sw          $v1, 0x104($at)
    MEM_W(0X104, ctx->r1) = ctx->r3;
    // 0x8005E668: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005E66C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005E670: jr          $ra
    // 0x8005E674: nop

    return;
    // 0x8005E674: nop

;}
RECOMP_FUNC void func_8005E678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E678: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005E67C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8005E680: jal         0x80070590
    // 0x8005E684: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x8005E684: nop

    after_0:
    // 0x8005E688: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8005E68C: sw          $v0, -0x30F8($at)
    MEM_W(-0X30F8, ctx->r1) = ctx->r2;
    // 0x8005E690: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8005E694: sw          $v1, -0x30F4($at)
    MEM_W(-0X30F4, ctx->r1) = ctx->r3;
    // 0x8005E698: jal         0x80002A20
    // 0x8005E69C: nop

    func_80002A20(rdram, ctx);
        goto after_1;
    // 0x8005E69C: nop

    after_1:
    // 0x8005E6A0: jal         0x800613B0
    // 0x8005E6A4: nop

    func_800613B0(rdram, ctx);
        goto after_2;
    // 0x8005E6A4: nop

    after_2:
    // 0x8005E6A8: jal         0x8005E398
    // 0x8005E6AC: nop

    func_8005E398(rdram, ctx);
        goto after_3;
    // 0x8005E6AC: nop

    after_3:
    // 0x8005E6B0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8005E6B4: lbu         $a0, 0x46B1($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X46B1);
    // 0x8005E6B8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8005E6BC: lbu         $a1, 0x46B2($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X46B2);
    // 0x8005E6C0: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8005E6C4: lbu         $a2, 0x46B3($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X46B3);
    // 0x8005E6C8: jal         0x8005F548
    // 0x8005E6CC: nop

    func_8005F548(rdram, ctx);
        goto after_4;
    // 0x8005E6CC: nop

    after_4:
    // 0x8005E6D0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8005E6D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005E6D8: jr          $ra
    // 0x8005E6DC: nop

    return;
    // 0x8005E6DC: nop

;}
RECOMP_FUNC void func_8005E6E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E6E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005E6E4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005E6E8: jal         0x80060AE0
    // 0x8005E6EC: nop

    func_80060AE0(rdram, ctx);
        goto after_0;
    // 0x8005E6EC: nop

    after_0:
    fprintf(stderr, "[R2-INIT] func_8005E6E0: calling func_8005E198 (resource loading)\n"); fflush(stderr);
    // 0x8005E6F0: jal         0x8005E198
    // 0x8005E6F4: nop

    func_8005E198(rdram, ctx);
        goto after_1;
    // 0x8005E6F4: nop

    after_1:
    fprintf(stderr, "[R2-INIT] func_8005E6E0: func_8005E198 returned, calling func_80001940\n"); fflush(stderr);
    // 0x8005E6F8: jal         0x80001940
    // 0x8005E6FC: nop

    func_80001940(rdram, ctx);
        goto after_2;
    // 0x8005E6FC: nop

    after_2:
    // 0x8005E700: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005E704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005E708: jr          $ra
    // 0x8005E70C: nop

    return;
    // 0x8005E70C: nop

;}
RECOMP_FUNC void func_8005E710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    fprintf(stderr, "[R2-THREAD2] func_8005E710 ENTERED (Thread 2 start)\n"); fflush(stderr);
    // 0x8005E710: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005E714: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005E718: lui         $a0, 0x3D
    ctx->r4 = S32(0X3D << 16);
    // 0x8005E71C: jal         0x8005DA90
    // 0x8005E720: ori         $a0, $a0, 0x900
    ctx->r4 = ctx->r4 | 0X900;
    func_8005DA90(rdram, ctx);
        goto after_0;
    // 0x8005E720: ori         $a0, $a0, 0x900
    ctx->r4 = ctx->r4 | 0X900;
    after_0:
    fprintf(stderr, "[R2-INIT] heap init done, calling func_8005C5F0 (threads/timer)\n"); fflush(stderr);
    // 0x8005E724: jal         0x8005C5F0
    // 0x8005E728: nop

    func_8005C5F0(rdram, ctx);
        goto after_1;
    // 0x8005E728: nop

    after_1:
    fprintf(stderr, "[R2-INIT] threads/timer done, calling func_8005E6E0 (resource loading)\n"); fflush(stderr);
    // 0x8005E72C: jal         0x8005E6E0
    // 0x8005E730: nop

    func_8005E6E0(rdram, ctx);
        goto after_2;
    // 0x8005E730: nop

    after_2:
    fprintf(stderr, "[R2-INIT] func_8005E710: func_8005E6E0 returned, calling func_80001730\n"); fflush(stderr);
    // 0x8005E734: jal         0x80001730
    // 0x8005E738: nop

    func_80001730(rdram, ctx);
        goto after_3;
    // 0x8005E738: nop

    after_3:
    fprintf(stderr, "[R2-INIT] func_8005E710: func_80001730 returned, Thread 2 init COMPLETE\n"); fflush(stderr);
    // 0x8005E73C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005E740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005E744: jr          $ra
    // 0x8005E748: nop

    return;
    // 0x8005E748: nop

    // 0x8005E74C: nop

;}
RECOMP_FUNC void func_8005E750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E750: lhu         $v1, 0x6C($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6C);
    // 0x8005E754: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x8005E758: bne         $v0, $zero, L_8005E77C
    if (ctx->r2 != 0) {
        // 0x8005E75C: ori         $v1, $v1, 0x80
        ctx->r3 = ctx->r3 | 0X80;
            goto L_8005E77C;
    }
    // 0x8005E75C: ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    // 0x8005E760: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x8005E764: beq         $v0, $zero, L_8005E77C
    if (ctx->r2 == 0) {
        // 0x8005E768: sh          $v1, 0x6C($a0)
        MEM_H(0X6C, ctx->r4) = ctx->r3;
            goto L_8005E77C;
    }
    // 0x8005E768: sh          $v1, 0x6C($a0)
    MEM_H(0X6C, ctx->r4) = ctx->r3;
    // 0x8005E76C: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x8005E770: beq         $v0, $zero, L_8005E77C
    if (ctx->r2 == 0) {
        // 0x8005E774: andi        $v0, $v1, 0xFBFF
        ctx->r2 = ctx->r3 & 0XFBFF;
            goto L_8005E77C;
    }
    // 0x8005E774: andi        $v0, $v1, 0xFBFF
    ctx->r2 = ctx->r3 & 0XFBFF;
    // 0x8005E778: sh          $v0, 0x6C($a0)
    MEM_H(0X6C, ctx->r4) = ctx->r2;
L_8005E77C:
    // 0x8005E77C: jr          $ra
    // 0x8005E780: nop

    return;
    // 0x8005E780: nop

;}
RECOMP_FUNC void func_8005E784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E784: lhu         $v1, 0x6C($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6C);
    // 0x8005E788: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x8005E78C: andi        $a1, $v1, 0xFF7F
    ctx->r5 = ctx->r3 & 0XFF7F;
    // 0x8005E790: beq         $v0, $zero, L_8005E7A8
    if (ctx->r2 == 0) {
        // 0x8005E794: sh          $a1, 0x6C($a0)
        MEM_H(0X6C, ctx->r4) = ctx->r5;
            goto L_8005E7A8;
    }
    // 0x8005E794: sh          $a1, 0x6C($a0)
    MEM_H(0X6C, ctx->r4) = ctx->r5;
    // 0x8005E798: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x8005E79C: bne         $v0, $zero, L_8005E7A8
    if (ctx->r2 != 0) {
        // 0x8005E7A0: ori         $v0, $a1, 0x400
        ctx->r2 = ctx->r5 | 0X400;
            goto L_8005E7A8;
    }
    // 0x8005E7A0: ori         $v0, $a1, 0x400
    ctx->r2 = ctx->r5 | 0X400;
    // 0x8005E7A4: sh          $v0, 0x6C($a0)
    MEM_H(0X6C, ctx->r4) = ctx->r2;
L_8005E7A8:
    // 0x8005E7A8: jr          $ra
    // 0x8005E7AC: nop

    return;
    // 0x8005E7AC: nop

;}
RECOMP_FUNC void func_8005E7B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E7B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005E7B4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005E7B8: addiu       $v1, $zero, 0x6AE
    ctx->r3 = ADD32(0, 0X6AE);
    // 0x8005E7BC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8005E7C0: addiu       $v0, $v0, 0x4048
    ctx->r2 = ADD32(ctx->r2, 0X4048);
L_8005E7C4:
    // 0x8005E7C4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8005E7C8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8005E7CC: bgez        $v1, L_8005E7C4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005E7D0: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_8005E7C4;
    }
    // 0x8005E7D0: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8005E7D4: lui         $a0, 0xBD
    ctx->r4 = S32(0XBD << 16);
    // 0x8005E7D8: addiu       $a0, $a0, -0x2F60
    ctx->r4 = ADD32(ctx->r4, -0X2F60);
    // 0x8005E7DC: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8005E7E0: addiu       $a2, $a2, 0x5580
    ctx->r6 = ADD32(ctx->r6, 0X5580);
    // 0x8005E7E4: jal         0x80060D70
    // 0x8005E7E8: addiu       $a1, $zero, 0x3578
    ctx->r5 = ADD32(0, 0X3578);
    func_80060D70(rdram, ctx);
        goto after_0;
    // 0x8005E7E8: addiu       $a1, $zero, 0x3578
    ctx->r5 = ADD32(0, 0X3578);
    after_0:
    // 0x8005E7EC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005E7F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005E7F4: jr          $ra
    // 0x8005E7F8: nop

    return;
    // 0x8005E7F8: nop

;}
RECOMP_FUNC void func_8005E7FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E7FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005E800: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005E804: addiu       $v0, $v0, 0x3F00
    ctx->r2 = ADD32(ctx->r2, 0X3F00);
    // 0x8005E808: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005E80C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005E810: sw          $v0, -0x40($at)
    MEM_W(-0X40, ctx->r1) = ctx->r2;
    // 0x8005E814: jal         0x8005E7B0
    // 0x8005E818: nop

    func_8005E7B0(rdram, ctx);
        goto after_0;
    // 0x8005E818: nop

    after_0:
    // 0x8005E81C: jal         0x8005E844
    // 0x8005E820: nop

    func_8005E844(rdram, ctx);
        goto after_1;
    // 0x8005E820: nop

    after_1:
    // 0x8005E824: jal         0x8005F130
    // 0x8005E828: nop

    func_8005F130(rdram, ctx);
        goto after_2;
    // 0x8005E828: nop

    after_2:
    // 0x8005E82C: jal         0x8005E844
    // 0x8005E830: nop

    func_8005E844(rdram, ctx);
        goto after_3;
    // 0x8005E830: nop

    after_3:
    // 0x8005E834: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005E838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005E83C: jr          $ra
    // 0x8005E840: nop

    return;
    // 0x8005E840: nop

;}
RECOMP_FUNC void func_8005E844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E844: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8005E848: lhu         $v0, 0x53D2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X53D2);
    // FALLTHROUGH into func_8005E84C (resource system init)
    func_8005E84C(rdram, ctx);
;}
RECOMP_FUNC void func_8005E84C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E84C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005E850: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x8005E854: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8005E858: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8005E85C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8005E860: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8005E864: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8005E868: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005E86C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005E870: bne         $v0, $zero, L_8005E9A8
    if (ctx->r2 != 0) {
        // 0x8005E874: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8005E9A8;
    }
    // 0x8005E874: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005E878: lui         $s7, 0x800
    ctx->r23 = S32(0X800 << 16);
    // 0x8005E87C: lui         $s3, 0xF3FF
    ctx->r19 = S32(0XF3FF << 16);
    // 0x8005E880: ori         $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 | 0XFFFF;
    // 0x8005E884: lui         $s6, 0x400
    ctx->r22 = S32(0X400 << 16);
    // 0x8005E888: lui         $s5, 0x8000
    ctx->r21 = S32(0X8000 << 16);
    // 0x8005E88C: lui         $s2, 0xDFFF
    ctx->r18 = S32(0XDFFF << 16);
    // 0x8005E890: ori         $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 | 0XFFFF;
    // 0x8005E894: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8005E898: addiu       $s1, $s1, -0x5480
    ctx->r17 = ADD32(ctx->r17, -0X5480);
    // 0x8005E89C: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8005E8A0: addiu       $s0, $s0, 0x5A30
    ctx->r16 = ADD32(ctx->r16, 0X5A30);
    // 0x8005E8A4: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8005E8A8: addiu       $s4, $s4, -0x2100
    ctx->r20 = ADD32(ctx->r20, -0X2100);
L_8005E8AC:
    // 0x8005E8AC: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8005E8B0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8005E8B4: and         $v0, $v1, $s7
    ctx->r2 = ctx->r3 & ctx->r23;
    // 0x8005E8B8: bnel        $v0, $zero, L_8005E908
    if (ctx->r2 != 0) {
        // 0x8005E8BC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8005E908;
    }
    goto skip_0;
    // 0x8005E8BC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8005E8C0: beq         $v1, $zero, L_8005E904
    if (ctx->r3 == 0) {
        // 0x8005E8C4: and         $v0, $v1, $s6
        ctx->r2 = ctx->r3 & ctx->r22;
            goto L_8005E904;
    }
    // 0x8005E8C4: and         $v0, $v1, $s6
    ctx->r2 = ctx->r3 & ctx->r22;
    // 0x8005E8C8: beq         $v0, $zero, L_8005E8E8
    if (ctx->r2 == 0) {
        // 0x8005E8CC: and         $a0, $v1, $s3
        ctx->r4 = ctx->r3 & ctx->r19;
            goto L_8005E8E8;
    }
    // 0x8005E8CC: and         $a0, $v1, $s3
    ctx->r4 = ctx->r3 & ctx->r19;
    // 0x8005E8D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005E8D4: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8005E8D8: beql        $a0, $zero, L_8005E904
    if (ctx->r4 == 0) {
        // 0x8005E8DC: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_8005E904;
    }
    goto skip_1;
    // 0x8005E8DC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    skip_1:
    // 0x8005E8E0: j           L_8005E8F8
    // 0x8005E8E4: nop

        goto L_8005E8F8;
    // 0x8005E8E4: nop

L_8005E8E8:
    // 0x8005E8E8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8005E8EC: and         $v0, $a0, $s5
    ctx->r2 = ctx->r4 & ctx->r21;
    // 0x8005E8F0: beq         $v0, $zero, L_8005E900
    if (ctx->r2 == 0) {
        // 0x8005E8F4: and         $a0, $a0, $s2
        ctx->r4 = ctx->r4 & ctx->r18;
            goto L_8005E900;
    }
    // 0x8005E8F4: and         $a0, $a0, $s2
    ctx->r4 = ctx->r4 & ctx->r18;
L_8005E8F8:
    // 0x8005E8F8: jal         0x8005E06C
    // 0x8005E8FC: nop

    func_8005E06C(rdram, ctx);
        goto after_0;
    // 0x8005E8FC: nop

    after_0:
L_8005E900:
    // 0x8005E900: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8005E904:
    // 0x8005E904: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8005E908:
    // 0x8005E908: slt         $v0, $s0, $s4
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8005E90C: bne         $v0, $zero, L_8005E8AC
    if (ctx->r2 != 0) {
        // 0x8005E910: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8005E8AC;
    }
    // 0x8005E910: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8005E914: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8005E918: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8005E91C: addiu       $s0, $s0, -0x20
    ctx->r16 = ADD32(ctx->r16, -0X20);
L_8005E920:
    // 0x8005E920: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005E924: beql        $a0, $zero, L_8005E938
    if (ctx->r4 == 0) {
        // 0x8005E928: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_8005E938;
    }
    goto skip_2;
    // 0x8005E928: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    skip_2:
    // 0x8005E92C: jal         0x8005E06C
    // 0x8005E930: nop

    func_8005E06C(rdram, ctx);
        goto after_1;
    // 0x8005E930: nop

    after_1:
    // 0x8005E934: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8005E938:
    // 0x8005E938: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005E93C: slti        $v0, $s1, 0x14
    ctx->r2 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
    // 0x8005E940: bne         $v0, $zero, L_8005E920
    if (ctx->r2 != 0) {
        // 0x8005E944: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8005E920;
    }
    // 0x8005E944: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8005E948: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005E94C: lw          $v0, -0x40($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X40);
    // 0x8005E950: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8005E954: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8005E958: addiu       $s0, $s0, 0x2590
    ctx->r16 = ADD32(ctx->r16, 0X2590);
    // 0x8005E95C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8005E960: sw          $zero, -0x74E0($at)
    MEM_W(-0X74E0, ctx->r1) = 0;
    // 0x8005E964: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005E968: sw          $zero, -0x1D28($at)
    MEM_W(-0X1D28, ctx->r1) = 0;
    // 0x8005E96C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005E970: sw          $zero, -0x1D24($at)
    MEM_W(-0X1D24, ctx->r1) = 0;
    // 0x8005E974: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005E978: sw          $zero, 0x108($at)
    MEM_W(0X108, ctx->r1) = 0;
    // 0x8005E97C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8005E980: sw          $v0, 0x4058($at)
    MEM_W(0X4058, ctx->r1) = ctx->r2;
L_8005E984:
    // 0x8005E984: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005E988: beq         $a0, $zero, L_8005E99C
    if (ctx->r4 == 0) {
        // 0x8005E98C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8005E99C;
    }
    // 0x8005E98C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005E990: jal         0x8005E06C
    // 0x8005E994: nop

    func_8005E06C(rdram, ctx);
        goto after_2;
    // 0x8005E994: nop

    after_2:
    // 0x8005E998: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8005E99C:
    // 0x8005E99C: slti        $v0, $s1, 0x6AF
    ctx->r2 = SIGNED(ctx->r17) < 0X6AF ? 1 : 0;
    // 0x8005E9A0: bne         $v0, $zero, L_8005E984
    if (ctx->r2 != 0) {
        // 0x8005E9A4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8005E984;
    }
    // 0x8005E9A4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8005E9A8:
    // 0x8005E9A8: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x8005E9AC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8005E9B4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E9B8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8005E9BC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005E9C0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005E9C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E9C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005E9CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8005E9D0: jr          $ra
    // 0x8005E9D4: nop

    return;
    // 0x8005E9D4: nop

;}
RECOMP_FUNC void func_8005E9D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E9D8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005E9DC: addiu       $v1, $v1, -0x1D24
    ctx->r3 = ADD32(ctx->r3, -0X1D24);
    // 0x8005E9E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005E9E4: bne         $v0, $zero, L_8005EA00
    if (ctx->r2 != 0) {
        // 0x8005E9E8: addiu       $v0, $v1, -0x4
        ctx->r2 = ADD32(ctx->r3, -0X4);
            goto L_8005EA00;
    }
    // 0x8005E9E8: addiu       $v0, $v1, -0x4
    ctx->r2 = ADD32(ctx->r3, -0X4);
    // 0x8005E9EC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8005E9F0: sw          $a0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r4;
    // 0x8005E9F4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8005E9F8: j           L_8005EA1C
    // 0x8005E9FC: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
        goto L_8005EA1C;
    // 0x8005E9FC: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8005EA00:
    // 0x8005EA00: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005EA04: lw          $v0, -0x1D24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1D24);
    // 0x8005EA08: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8005EA0C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8005EA10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005EA14: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8005EA18: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8005EA1C:
    // 0x8005EA1C: jr          $ra
    // 0x8005EA20: nop

    return;
    // 0x8005EA20: nop

;}
RECOMP_FUNC void func_8005EA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EA24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005EA28: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005EA2C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005EA30: beq         $v1, $zero, L_8005EA50
    if (ctx->r3 == 0) {
        // 0x8005EA34: nop
    
            goto L_8005EA50;
    }
    // 0x8005EA34: nop

    // 0x8005EA38: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8005EA3C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8005EA40: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005EA44: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8005EA48: jal         0x8005E9D8
    // 0x8005EA4C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    func_8005E9D8(rdram, ctx);
        goto after_0;
    // 0x8005EA4C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    after_0:
L_8005EA50:
    // 0x8005EA50: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005EA54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005EA58: jr          $ra
    // 0x8005EA5C: nop

    return;
    // 0x8005EA5C: nop

;}
RECOMP_FUNC void func_8005EA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EA60: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8005EA64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005EA68: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8005EA6C: lw          $a0, -0x5480($at)
    ctx->r4 = MEM_W(ctx->r1, -0X5480);
    // 0x8005EA70: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8005EA74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005EA78: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005EA7C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005EA80: bne         $v1, $zero, L_8005EA9C
    if (ctx->r3 != 0) {
        // 0x8005EA84: nop
    
            goto L_8005EA9C;
    }
    // 0x8005EA84: nop

    // 0x8005EA88: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8005EA8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005EA90: sw          $v0, -0x1D24($at)
    MEM_W(-0X1D24, ctx->r1) = ctx->r2;
    // 0x8005EA94: j           L_8005EAA8
    // 0x8005EA98: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_8005EAA8;
    // 0x8005EA98: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8005EA9C:
    // 0x8005EA9C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8005EAA0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8005EAA4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8005EAA8:
    // 0x8005EAA8: jr          $ra
    // 0x8005EAAC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    return;
    // 0x8005EAAC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
;}
RECOMP_FUNC void func_8005EAB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EAB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005EAB4: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8005EAB8: beq         $a2, $zero, L_8005EB70
    if (ctx->r6 == 0) {
        // 0x8005EABC: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8005EB70;
    }
    // 0x8005EABC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005EAC0: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    // 0x8005EAC4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005EAC8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8005EACC: lw          $v0, 0x5A30($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5A30);
    // 0x8005EAD0: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x8005EAD4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8005EAD8: bne         $v0, $zero, L_8005EB70
    if (ctx->r2 != 0) {
        // 0x8005EADC: nop
    
            goto L_8005EB70;
    }
    // 0x8005EADC: nop

    // 0x8005EAE0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005EAE4: addiu       $v0, $v0, -0x5480
    ctx->r2 = ADD32(ctx->r2, -0X5480);
    // 0x8005EAE8: addu        $a3, $a0, $v0
    ctx->r7 = ADD32(ctx->r4, ctx->r2);
    // 0x8005EAEC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8005EAF0: beq         $a0, $zero, L_8005EB2C
    if (ctx->r4 == 0) {
        // 0x8005EAF4: nop
    
            goto L_8005EB2C;
    }
    // 0x8005EAF4: nop

    // 0x8005EAF8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8005EAFC: lw          $v0, -0x74E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X74E0);
    // 0x8005EB00: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8005EB04: beq         $v1, $zero, L_8005EB1C
    if (ctx->r3 == 0) {
        // 0x8005EB08: sw          $v0, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->r2;
            goto L_8005EB1C;
    }
    // 0x8005EB08: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x8005EB0C: jal         0x8005EA24
    // 0x8005EB10: nop

    func_8005EA24(rdram, ctx);
        goto after_0;
    // 0x8005EB10: nop

    after_0:
    // 0x8005EB14: j           L_8005EB70
    // 0x8005EB18: nop

        goto L_8005EB70;
    // 0x8005EB18: nop

L_8005EB1C:
    // 0x8005EB1C: jal         0x8005E9D8
    // 0x8005EB20: nop

    func_8005E9D8(rdram, ctx);
        goto after_1;
    // 0x8005EB20: nop

    after_1:
    // 0x8005EB24: j           L_8005EB70
    // 0x8005EB28: nop

        goto L_8005EB70;
    // 0x8005EB28: nop

L_8005EB2C:
    // 0x8005EB2C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005EB30: lw          $v0, 0x108($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X108);
    // 0x8005EB34: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8005EB38: addiu       $v1, $v1, -0x24B0
    ctx->r3 = ADD32(ctx->r3, -0X24B0);
    // 0x8005EB3C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8005EB40: lw          $a1, -0x74E0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X74E0);
    // 0x8005EB44: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8005EB48: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x8005EB4C: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x8005EB50: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
    // 0x8005EB54: jal         0x8005E9D8
    // 0x8005EB58: sw          $a0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r4;
    func_8005E9D8(rdram, ctx);
        goto after_2;
    // 0x8005EB58: sw          $a0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r4;
    after_2:
    // 0x8005EB5C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005EB60: lw          $v0, 0x108($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X108);
    // 0x8005EB64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005EB68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005EB6C: sw          $v0, 0x108($at)
    MEM_W(0X108, ctx->r1) = ctx->r2;
L_8005EB70:
    // 0x8005EB70: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005EB74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005EB78: jr          $ra
    // 0x8005EB7C: nop

    return;
    // 0x8005EB7C: nop

;}
RECOMP_FUNC void func_8005EB80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EB80: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x8005EB84: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x8005EB88: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x8005EB8C: beq         $v0, $zero, L_8005EC10
    if (ctx->r2 == 0) {
        // 0x8005EB90: addu        $t3, $a2, $zero
        ctx->r11 = ADD32(ctx->r6, 0);
            goto L_8005EC10;
    }
    // 0x8005EB90: addu        $t3, $a2, $zero
    ctx->r11 = ADD32(ctx->r6, 0);
    // 0x8005EB94: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8005EB98: addiu       $t4, $t4, 0x5A30
    ctx->r12 = ADD32(ctx->r12, 0X5A30);
    // 0x8005EB9C: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
    // 0x8005EBA0: addiu       $a3, $a0, 0x4
    ctx->r7 = ADD32(ctx->r4, 0X4);
L_8005EBA4:
    // 0x8005EBA4: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x8005EBA8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8005EBAC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8005EBB0: addu        $a1, $t1, $a1
    ctx->r5 = ADD32(ctx->r9, ctx->r5);
    // 0x8005EBB4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005EBB8: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x8005EBBC: or          $v0, $a1, $t3
    ctx->r2 = ctx->r5 | ctx->r11;
    // 0x8005EBC0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005EBC4: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x8005EBC8: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x8005EBCC: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x8005EBD0: addu        $a2, $t1, $a2
    ctx->r6 = ADD32(ctx->r9, ctx->r6);
    // 0x8005EBD4: srl         $a0, $v1, 16
    ctx->r4 = S32(U32(ctx->r3) >> 16);
    // 0x8005EBD8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8005EBDC: and         $v1, $v1, $t2
    ctx->r3 = ctx->r3 & ctx->r10;
    // 0x8005EBE0: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8005EBE4: srl         $v1, $v0, 16
    ctx->r3 = S32(U32(ctx->r2) >> 16);
    // 0x8005EBE8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005EBEC: and         $v0, $v0, $t2
    ctx->r2 = ctx->r2 & ctx->r10;
    // 0x8005EBF0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005EBF4: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x8005EBF8: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x8005EBFC: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x8005EC00: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8005EC04: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8005EC08: bne         $v0, $zero, L_8005EBA4
    if (ctx->r2 != 0) {
        // 0x8005EC0C: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_8005EBA4;
    }
    // 0x8005EC0C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_8005EC10:
    // 0x8005EC10: jr          $ra
    // 0x8005EC14: nop

    return;
    // 0x8005EC14: nop

;}
RECOMP_FUNC void func_8005EC18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EC18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005EC1C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8005EC20: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8005EC24: sll         $v0, $s2, 3
    ctx->r2 = S32(ctx->r18 << 3);
    // 0x8005EC28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005EC2C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005EC30: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005EC34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005EC38: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005EC3C: lw          $v0, -0x20($at)
    ctx->r2 = MEM_W(ctx->r1, -0X20);
    // 0x8005EC40: bne         $v0, $zero, L_8005EE3C
    if (ctx->r2 != 0) {
        // 0x8005EC44: addiu       $a1, $a1, -0x2
        ctx->r5 = ADD32(ctx->r5, -0X2);
            goto L_8005EE3C;
    }
    // 0x8005EC44: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x8005EC48: sltiu       $v0, $a1, 0x28
    ctx->r2 = ctx->r5 < 0X28 ? 1 : 0;
    // 0x8005EC4C: beq         $v0, $zero, L_8005EDFC
    if (ctx->r2 == 0) {
        // 0x8005EC50: sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5 << 2);
            goto L_8005EDFC;
    }
    // 0x8005EC50: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8005EC54: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005EC58: addu        $at, $at, $v0
    gpr jr_addend_8005EC60 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005EC5C: lw          $v0, 0x1F30($at)
    ctx->r2 = ADD32(ctx->r1, 0X1F30);
    // 0x8005EC60: jr          $v0
    // 0x8005EC64: nop

    switch (jr_addend_8005EC60 >> 2) {
        case 0: goto L_8005EC68; break;
        case 1: goto L_8005EDFC; break;
        case 2: goto L_8005ECB0; break;
        case 3: goto L_8005EDFC; break;
        case 4: goto L_8005EC80; break;
        case 5: goto L_8005EDFC; break;
        case 6: goto L_8005ECC8; break;
        case 7: goto L_8005EDFC; break;
        case 8: goto L_8005ECE0; break;
        case 9: goto L_8005EDFC; break;
        case 10: goto L_8005EC98; break;
        case 11: goto L_8005EDFC; break;
        case 12: goto L_8005ECF8; break;
        case 13: goto L_8005EDFC; break;
        case 14: goto L_8005EDFC; break;
        case 15: goto L_8005EDFC; break;
        case 16: goto L_8005EDFC; break;
        case 17: goto L_8005EDFC; break;
        case 18: goto L_8005EDFC; break;
        case 19: goto L_8005ED10; break;
        case 20: goto L_8005EDFC; break;
        case 21: goto L_8005EDFC; break;
        case 22: goto L_8005EDFC; break;
        case 23: goto L_8005EDFC; break;
        case 24: goto L_8005EDFC; break;
        case 25: goto L_8005EDFC; break;
        case 26: goto L_8005EDFC; break;
        case 27: goto L_8005EDFC; break;
        case 28: goto L_8005ED28; break;
        case 29: goto L_8005ED40; break;
        case 30: goto L_8005EDFC; break;
        case 31: goto L_8005EDFC; break;
        case 32: goto L_8005EDFC; break;
        case 33: goto L_8005EDA0; break;
        case 34: goto L_8005EDB8; break;
        case 35: goto L_8005EDD0; break;
        case 36: goto L_8005ED58; break;
        case 37: goto L_8005ED70; break;
        case 38: goto L_8005ED88; break;
        case 39: goto L_8005EDE8; break;
        default: switch_error(__func__, 0x8005EC60, 0x800C1F30);
    }
    // 0x8005EC64: nop

L_8005EC68:
    // 0x8005EC68: lui         $s0, 0x9E
    ctx->r16 = S32(0X9E << 16);
    // 0x8005EC6C: addiu       $s0, $s0, 0xD30
    ctx->r16 = ADD32(ctx->r16, 0XD30);
    // 0x8005EC70: lui         $v0, 0xA2
    ctx->r2 = S32(0XA2 << 16);
    // 0x8005EC74: addiu       $v0, $v0, -0x3020
    ctx->r2 = ADD32(ctx->r2, -0X3020);
    // 0x8005EC78: j           L_8005EDFC
    // 0x8005EC7C: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005EC7C: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005EC80:
    // 0x8005EC80: lui         $s0, 0xA2
    ctx->r16 = S32(0XA2 << 16);
    // 0x8005EC84: addiu       $s0, $s0, -0x3020
    ctx->r16 = ADD32(ctx->r16, -0X3020);
    // 0x8005EC88: lui         $v0, 0xA5
    ctx->r2 = S32(0XA5 << 16);
    // 0x8005EC8C: addiu       $v0, $v0, 0x7570
    ctx->r2 = ADD32(ctx->r2, 0X7570);
    // 0x8005EC90: j           L_8005EDFC
    // 0x8005EC94: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005EC94: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005EC98:
    // 0x8005EC98: lui         $s0, 0x93
    ctx->r16 = S32(0X93 << 16);
    // 0x8005EC9C: addiu       $s0, $s0, 0x12A0
    ctx->r16 = ADD32(ctx->r16, 0X12A0);
    // 0x8005ECA0: lui         $v0, 0x97
    ctx->r2 = S32(0X97 << 16);
    // 0x8005ECA4: addiu       $v0, $v0, -0x4730
    ctx->r2 = ADD32(ctx->r2, -0X4730);
    // 0x8005ECA8: j           L_8005EDFC
    // 0x8005ECAC: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005ECAC: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005ECB0:
    // 0x8005ECB0: lui         $s0, 0x97
    ctx->r16 = S32(0X97 << 16);
    // 0x8005ECB4: addiu       $s0, $s0, -0x4730
    ctx->r16 = ADD32(ctx->r16, -0X4730);
    // 0x8005ECB8: lui         $v0, 0x9A
    ctx->r2 = S32(0X9A << 16);
    // 0x8005ECBC: addiu       $v0, $v0, 0x6200
    ctx->r2 = ADD32(ctx->r2, 0X6200);
    // 0x8005ECC0: j           L_8005EDFC
    // 0x8005ECC4: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005ECC4: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005ECC8:
    // 0x8005ECC8: lui         $s0, 0x9A
    ctx->r16 = S32(0X9A << 16);
    // 0x8005ECCC: addiu       $s0, $s0, 0x6200
    ctx->r16 = ADD32(ctx->r16, 0X6200);
    // 0x8005ECD0: lui         $v0, 0x9E
    ctx->r2 = S32(0X9E << 16);
    // 0x8005ECD4: addiu       $v0, $v0, 0xD30
    ctx->r2 = ADD32(ctx->r2, 0XD30);
    // 0x8005ECD8: j           L_8005EDFC
    // 0x8005ECDC: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005ECDC: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005ECE0:
    // 0x8005ECE0: lui         $s0, 0xA5
    ctx->r16 = S32(0XA5 << 16);
    // 0x8005ECE4: addiu       $s0, $s0, 0x7570
    ctx->r16 = ADD32(ctx->r16, 0X7570);
    // 0x8005ECE8: lui         $v0, 0xA9
    ctx->r2 = S32(0XA9 << 16);
    // 0x8005ECEC: addiu       $v0, $v0, 0x8B0
    ctx->r2 = ADD32(ctx->r2, 0X8B0);
    // 0x8005ECF0: j           L_8005EDFC
    // 0x8005ECF4: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005ECF4: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005ECF8:
    // 0x8005ECF8: lui         $s0, 0x8F
    ctx->r16 = S32(0X8F << 16);
    // 0x8005ECFC: addiu       $s0, $s0, 0x7CB0
    ctx->r16 = ADD32(ctx->r16, 0X7CB0);
    // 0x8005ED00: lui         $v0, 0x93
    ctx->r2 = S32(0X93 << 16);
    // 0x8005ED04: addiu       $v0, $v0, 0x12A0
    ctx->r2 = ADD32(ctx->r2, 0X12A0);
    // 0x8005ED08: j           L_8005EDFC
    // 0x8005ED0C: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005ED0C: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005ED10:
    // 0x8005ED10: lui         $s0, 0xA9
    ctx->r16 = S32(0XA9 << 16);
    // 0x8005ED14: addiu       $s0, $s0, 0x8B0
    ctx->r16 = ADD32(ctx->r16, 0X8B0);
    // 0x8005ED18: lui         $v0, 0xB4
    ctx->r2 = S32(0XB4 << 16);
    // 0x8005ED1C: addiu       $v0, $v0, 0x5660
    ctx->r2 = ADD32(ctx->r2, 0X5660);
    // 0x8005ED20: j           L_8005EDFC
    // 0x8005ED24: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005ED24: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005ED28:
    // 0x8005ED28: lui         $s0, 0xB4
    ctx->r16 = S32(0XB4 << 16);
    // 0x8005ED2C: addiu       $s0, $s0, 0x5660
    ctx->r16 = ADD32(ctx->r16, 0X5660);
    // 0x8005ED30: lui         $v0, 0xB7
    ctx->r2 = S32(0XB7 << 16);
    // 0x8005ED34: addiu       $v0, $v0, 0x56C0
    ctx->r2 = ADD32(ctx->r2, 0X56C0);
    // 0x8005ED38: j           L_8005EDFC
    // 0x8005ED3C: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005ED3C: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005ED40:
    // 0x8005ED40: lui         $s0, 0xB7
    ctx->r16 = S32(0XB7 << 16);
    // 0x8005ED44: addiu       $s0, $s0, 0x56C0
    ctx->r16 = ADD32(ctx->r16, 0X56C0);
    // 0x8005ED48: lui         $v0, 0xBA
    ctx->r2 = S32(0XBA << 16);
    // 0x8005ED4C: addiu       $v0, $v0, 0x1DC0
    ctx->r2 = ADD32(ctx->r2, 0X1DC0);
    // 0x8005ED50: j           L_8005EDFC
    // 0x8005ED54: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005ED54: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005ED58:
    // 0x8005ED58: lui         $s0, 0xBA
    ctx->r16 = S32(0XBA << 16);
    // 0x8005ED5C: addiu       $s0, $s0, 0x1DC0
    ctx->r16 = ADD32(ctx->r16, 0X1DC0);
    // 0x8005ED60: lui         $v0, 0xBA
    ctx->r2 = S32(0XBA << 16);
    // 0x8005ED64: addiu       $v0, $v0, 0x7B90
    ctx->r2 = ADD32(ctx->r2, 0X7B90);
    // 0x8005ED68: j           L_8005EDFC
    // 0x8005ED6C: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005ED6C: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005ED70:
    // 0x8005ED70: lui         $s0, 0xBA
    ctx->r16 = S32(0XBA << 16);
    // 0x8005ED74: addiu       $s0, $s0, 0x7B90
    ctx->r16 = ADD32(ctx->r16, 0X7B90);
    // 0x8005ED78: lui         $v0, 0xBB
    ctx->r2 = S32(0XBB << 16);
    // 0x8005ED7C: addiu       $v0, $v0, -0x2360
    ctx->r2 = ADD32(ctx->r2, -0X2360);
    // 0x8005ED80: j           L_8005EDFC
    // 0x8005ED84: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005ED84: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005ED88:
    // 0x8005ED88: lui         $s0, 0xBB
    ctx->r16 = S32(0XBB << 16);
    // 0x8005ED8C: addiu       $s0, $s0, -0x2360
    ctx->r16 = ADD32(ctx->r16, -0X2360);
    // 0x8005ED90: lui         $v0, 0xBB
    ctx->r2 = S32(0XBB << 16);
    // 0x8005ED94: addiu       $v0, $v0, 0x3A90
    ctx->r2 = ADD32(ctx->r2, 0X3A90);
    // 0x8005ED98: j           L_8005EDFC
    // 0x8005ED9C: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005ED9C: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005EDA0:
    // 0x8005EDA0: lui         $s0, 0xBB
    ctx->r16 = S32(0XBB << 16);
    // 0x8005EDA4: addiu       $s0, $s0, 0x3A90
    ctx->r16 = ADD32(ctx->r16, 0X3A90);
    // 0x8005EDA8: lui         $v0, 0xBC
    ctx->r2 = S32(0XBC << 16);
    // 0x8005EDAC: addiu       $v0, $v0, -0x7020
    ctx->r2 = ADD32(ctx->r2, -0X7020);
    // 0x8005EDB0: j           L_8005EDFC
    // 0x8005EDB4: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005EDB4: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005EDB8:
    // 0x8005EDB8: lui         $s0, 0xBC
    ctx->r16 = S32(0XBC << 16);
    // 0x8005EDBC: addiu       $s0, $s0, -0x7020
    ctx->r16 = ADD32(ctx->r16, -0X7020);
    // 0x8005EDC0: lui         $v0, 0xBC
    ctx->r2 = S32(0XBC << 16);
    // 0x8005EDC4: addiu       $v0, $v0, -0x13D0
    ctx->r2 = ADD32(ctx->r2, -0X13D0);
    // 0x8005EDC8: j           L_8005EDFC
    // 0x8005EDCC: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005EDCC: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005EDD0:
    // 0x8005EDD0: lui         $s0, 0xBC
    ctx->r16 = S32(0XBC << 16);
    // 0x8005EDD4: addiu       $s0, $s0, -0x13D0
    ctx->r16 = ADD32(ctx->r16, -0X13D0);
    // 0x8005EDD8: lui         $v0, 0xBC
    ctx->r2 = S32(0XBC << 16);
    // 0x8005EDDC: addiu       $v0, $v0, 0x5990
    ctx->r2 = ADD32(ctx->r2, 0X5990);
    // 0x8005EDE0: j           L_8005EDFC
    // 0x8005EDE4: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
        goto L_8005EDFC;
    // 0x8005EDE4: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005EDE8:
    // 0x8005EDE8: lui         $s0, 0xBC
    ctx->r16 = S32(0XBC << 16);
    // 0x8005EDEC: addiu       $s0, $s0, 0x5990
    ctx->r16 = ADD32(ctx->r16, 0X5990);
    // 0x8005EDF0: lui         $v0, 0xBD
    ctx->r2 = S32(0XBD << 16);
    // 0x8005EDF4: addiu       $v0, $v0, -0x2F60
    ctx->r2 = ADD32(ctx->r2, -0X2F60);
    // 0x8005EDF8: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
L_8005EDFC:
    // 0x8005EDFC: jal         0x8005DFF0
    // 0x8005EE00: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005DFF0(rdram, ctx);
        goto after_0;
    // 0x8005EE00: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8005EE04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005EE08: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8005EE0C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005EE10: sll         $v0, $s2, 3
    ctx->r2 = S32(ctx->r18 << 3);
    // 0x8005EE14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005EE18: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005EE1C: sw          $s0, -0x20($at)
    MEM_W(-0X20, ctx->r1) = ctx->r16;
    // 0x8005EE20: jal         0x80060D70
    // 0x8005EE24: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80060D70(rdram, ctx);
        goto after_1;
    // 0x8005EE24: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8005EE28: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005EE2C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005EE30: lui         $a2, 0x400
    ctx->r6 = S32(0X400 << 16);
    // 0x8005EE34: jal         0x8005EB80
    // 0x8005EE38: addu        $a0, $a1, $a0
    ctx->r4 = ADD32(ctx->r5, ctx->r4);
    func_8005EB80(rdram, ctx);
        goto after_2;
    // 0x8005EE38: addu        $a0, $a1, $a0
    ctx->r4 = ADD32(ctx->r5, ctx->r4);
    after_2:
L_8005EE3C:
    // 0x8005EE3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EE40: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8005EE44: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005EE48: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005EE4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005EE50: jr          $ra
    // 0x8005EE54: nop

    return;
    // 0x8005EE54: nop

;}
RECOMP_FUNC void func_8005EE58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EE58: jr          $ra
    // 0x8005EE5C: nop

    return;
    // 0x8005EE5C: nop

;}
RECOMP_FUNC void func_8005EE60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EE60: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005EE64: lh          $v1, 0x538($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X538);
;}
RECOMP_FUNC void func_8005EE68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EE68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005EE6C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005EE70: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005EE74: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005EE78: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8005EE7C: lw          $a0, -0x6B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B0);
    // 0x8005EE80: beq         $v1, $zero, L_8005EE98
    if (ctx->r3 == 0) {
        // 0x8005EE84: nop
    
            goto L_8005EE98;
    }
    // 0x8005EE84: nop

    // 0x8005EE88: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8005EE8C: lh          $v1, 0x2560($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X2560);
    // 0x8005EE90: j           L_8005EEA4
    // 0x8005EE94: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
        goto L_8005EEA4;
    // 0x8005EE94: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
L_8005EE98:
    // 0x8005EE98: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005EE9C: lh          $v1, -0x1D66($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X1D66);
    // 0x8005EEA0: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
L_8005EEA4:
    // 0x8005EEA4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8005EEA8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8005EEAC: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x8005EEB0: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8005EEB4: addiu       $a2, $a2, -0xFF0
    ctx->r6 = ADD32(ctx->r6, -0XFF0);
    // 0x8005EEB8: jal         0x80060D70
    // 0x8005EEBC: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    func_80060D70(rdram, ctx);
        goto after_0;
    // 0x8005EEBC: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    after_0:
    // 0x8005EEC0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005EEC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005EEC8: jr          $ra
    // 0x8005EECC: nop

    return;
    // 0x8005EECC: nop

;}
RECOMP_FUNC void func_8005EED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EED0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005EED4: lw          $v0, -0x1D28($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1D28);
    // 0x8005EED8: beql        $v0, $zero, L_8005EEE4
    if (ctx->r2 == 0) {
        // 0x8005EEDC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8005EEE4;
    }
    goto skip_0;
    // 0x8005EEDC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x8005EEE0: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
L_8005EEE4:
    // 0x8005EEE4: jr          $ra
    // 0x8005EEE8: nop

    return;
    // 0x8005EEE8: nop

;}
RECOMP_FUNC void func_8005EEEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EEEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005EEF0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005EEF4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8005EEF8: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x8005EEFC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8005EF00: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005EF04: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005EF08: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005EF0C: lw          $v1, 0x5A30($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5A30);
    // 0x8005EF10: lui         $v0, 0xF3FF
    ctx->r2 = S32(0XF3FF << 16);
    // 0x8005EF14: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x8005EF18: and         $s0, $v1, $v0
    ctx->r16 = ctx->r3 & ctx->r2;
    // 0x8005EF1C: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x8005EF20: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8005EF24: beq         $v1, $zero, L_8005EF4C
    if (ctx->r3 == 0) {
        // 0x8005EF28: nop
    
            goto L_8005EF4C;
    }
    // 0x8005EF28: nop

    // 0x8005EF2C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8005EF30: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8005EF34: beq         $a0, $zero, L_8005EF70
    if (ctx->r4 == 0) {
        // 0x8005EF38: nop
    
            goto L_8005EF70;
    }
    // 0x8005EF38: nop

    // 0x8005EF3C: jal         0x8005E06C
    // 0x8005EF40: nop

    func_8005E06C(rdram, ctx);
        goto after_0;
    // 0x8005EF40: nop

    after_0:
    // 0x8005EF44: j           L_8005EF68
    // 0x8005EF48: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
        goto L_8005EF68;
    // 0x8005EF48: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_8005EF4C:
    // 0x8005EF4C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005EF50: beq         $v0, $zero, L_8005EF70
    if (ctx->r2 == 0) {
        // 0x8005EF54: lui         $a0, 0xDFFF
        ctx->r4 = S32(0XDFFF << 16);
            goto L_8005EF70;
    }
    // 0x8005EF54: lui         $a0, 0xDFFF
    ctx->r4 = S32(0XDFFF << 16);
    // 0x8005EF58: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x8005EF5C: jal         0x8005E06C
    // 0x8005EF60: and         $a0, $v0, $a0
    ctx->r4 = ctx->r2 & ctx->r4;
    func_8005E06C(rdram, ctx);
        goto after_1;
    // 0x8005EF60: and         $a0, $v0, $a0
    ctx->r4 = ctx->r2 & ctx->r4;
    after_1:
    // 0x8005EF64: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8005EF68:
    // 0x8005EF68: jal         0x8005EA60
    // 0x8005EF6C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005EA60(rdram, ctx);
        goto after_2;
    // 0x8005EF6C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
L_8005EF70:
    // 0x8005EF70: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005EF74: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005EF78: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005EF7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005EF80: jr          $ra
    // 0x8005EF84: nop

    return;
    // 0x8005EF84: nop

;}
RECOMP_FUNC void func_8005EF88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EF88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005EF8C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8005EF90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005EF94: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005EF98: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005EF9C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005EFA0: lw          $v1, 0x5A30($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5A30);
    // 0x8005EFA4: lui         $v0, 0xF3FF
    ctx->r2 = S32(0XF3FF << 16);
    // 0x8005EFA8: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x8005EFAC: jal         0x800605A8
    // 0x8005EFB0: and         $s0, $v1, $v0
    ctx->r16 = ctx->r3 & ctx->r2;
    func_800605A8(rdram, ctx);
        goto after_0;
    // 0x8005EFB0: and         $s0, $v1, $v0
    ctx->r16 = ctx->r3 & ctx->r2;
    after_0:
    // 0x8005EFB4: beql        $v0, $zero, L_8005EFC0
    if (ctx->r2 == 0) {
        // 0x8005EFB8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8005EFC0;
    }
    goto skip_0;
    // 0x8005EFB8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
    // 0x8005EFBC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_8005EFC0:
    // 0x8005EFC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005EFC4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005EFC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005EFCC: jr          $ra
    // 0x8005EFD0: nop

    return;
    // 0x8005EFD0: nop

;}
RECOMP_FUNC void func_8005EFD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EFD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005EFD8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8005EFDC: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8005EFE0: sll         $v0, $s2, 8
    ctx->r2 = S32(ctx->r18 << 8);
    // 0x8005EFE4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005EFE8: srl         $s0, $v0, 9
    ctx->r16 = S32(U32(ctx->r2) >> 9);
    // 0x8005EFEC: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8005EFF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005EFF4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005EFF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005EFFC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005F000: lw          $v0, 0x5A30($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5A30);
    // 0x8005F004: lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // 0x8005F008: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8005F00C: beq         $v0, $zero, L_8005F0BC
    if (ctx->r2 == 0) {
        // 0x8005F010: addu        $s1, $a0, $zero
        ctx->r17 = ADD32(ctx->r4, 0);
            goto L_8005F0BC;
    }
    // 0x8005F010: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8005F014: jal         0x8005EAB0
    // 0x8005F018: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8005EAB0(rdram, ctx);
        goto after_0;
    // 0x8005F018: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8005F01C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8005F020: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8005F024: bne         $v0, $zero, L_8005F114
    if (ctx->r2 != 0) {
        // 0x8005F028: nop
    
            goto L_8005F114;
    }
    // 0x8005F028: nop

    // 0x8005F02C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005F030: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005F034: sw          $v0, -0x6C0($at)
    MEM_W(-0X6C0, ctx->r1) = ctx->r2;
L_8005F038:
    // 0x8005F038: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8005F03C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8005F040: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    // 0x8005F044: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005F048: mflo        $a0
    ctx->r4 = lo;
    // 0x8005F04C: nop

    // 0x8005F050: nop

    // 0x8005F054: jal         0x8005DFF0
    // 0x8005F058: nop

    func_8005DFF0(rdram, ctx);
        goto after_1;
    // 0x8005F058: nop

    after_1:
    // 0x8005F05C: bne         $v0, $zero, L_8005F080
    if (ctx->r2 != 0) {
        // 0x8005F060: sw          $v0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r2;
            goto L_8005F080;
    }
    // 0x8005F060: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8005F064: jal         0x8005EED0
    // 0x8005F068: nop

    func_8005EED0(rdram, ctx);
        goto after_2;
    // 0x8005F068: nop

    after_2:
    // 0x8005F06C: jal         0x8005EEEC
    // 0x8005F070: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8005EEEC(rdram, ctx);
        goto after_3;
    // 0x8005F070: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_3:
    // 0x8005F074: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8005F078: beq         $v0, $zero, L_8005F038
    if (ctx->r2 == 0) {
        // 0x8005F07C: nop
    
            goto L_8005F038;
    }
    // 0x8005F07C: nop

L_8005F080:
    // 0x8005F080: srl         $v0, $s2, 21
    ctx->r2 = S32(U32(ctx->r18) >> 21);
    // 0x8005F084: andi        $v0, $v0, 0x1F8
    ctx->r2 = ctx->r2 & 0X1F8;
    // 0x8005F088: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005F08C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8005F090: lw          $a0, -0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X20);
    // 0x8005F094: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8005F098: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x8005F09C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8005F0A0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005F0A4: sw          $zero, -0x6C0($at)
    MEM_W(-0X6C0, ctx->r1) = 0;
    // 0x8005F0A8: jal         0x8005BA80
    // 0x8005F0AC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_8005BA80(rdram, ctx);
        goto after_4;
    // 0x8005F0AC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_4:
    // 0x8005F0B0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8005F0B4: j           L_8005F114
    // 0x8005F0B8: nop

        goto L_8005F114;
    // 0x8005F0B8: nop

L_8005F0BC:
    // 0x8005F0BC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005F0C0: bgez        $v0, L_8005F0D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005F0C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005F0D0;
    }
    // 0x8005F0C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005F0C8: j           L_8005F108
    // 0x8005F0CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8005F108;
    // 0x8005F0CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8005F0D0:
    // 0x8005F0D0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005F0D4: sw          $v0, -0x6C0($at)
    MEM_W(-0X6C0, ctx->r1) = ctx->r2;
L_8005F0D8:
    // 0x8005F0D8: jal         0x8005EF88
    // 0x8005F0DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8005EF88(rdram, ctx);
        goto after_5;
    // 0x8005F0DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x8005F0E0: bne         $v0, $zero, L_8005F100
    if (ctx->r2 != 0) {
        // 0x8005F0E4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8005F100;
    }
    // 0x8005F0E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005F0E8: jal         0x8005EED0
    // 0x8005F0EC: nop

    func_8005EED0(rdram, ctx);
        goto after_6;
    // 0x8005F0EC: nop

    after_6:
    // 0x8005F0F0: jal         0x8005EEEC
    // 0x8005F0F4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8005EEEC(rdram, ctx);
        goto after_7;
    // 0x8005F0F4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_7:
    // 0x8005F0F8: j           L_8005F0D8
    // 0x8005F0FC: nop

        goto L_8005F0D8;
    // 0x8005F0FC: nop

L_8005F100:
    // 0x8005F100: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005F104: sw          $zero, -0x6C0($at)
    MEM_W(-0X6C0, ctx->r1) = 0;
L_8005F108:
    // 0x8005F108: jal         0x8005EAB0
    // 0x8005F10C: nop

    func_8005EAB0(rdram, ctx);
        goto after_8;
    // 0x8005F10C: nop

    after_8:
    // 0x8005F110: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8005F114:
    // 0x8005F114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F118: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8005F11C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005F120: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005F124: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005F128: jr          $ra
    // 0x8005F12C: nop

    return;
    // 0x8005F12C: nop

;}
RECOMP_FUNC void func_8005F130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F130: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005F134: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8005F138: addiu       $v1, $v1, -0x6A0
    ctx->r3 = ADD32(ctx->r3, -0X6A0);
    // 0x8005F13C: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8005F140: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8005F144: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8005F148: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8005F14C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005F150: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005F154: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005F158: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005F15C: beq         $v0, $zero, L_8005F1E4
    if (ctx->r2 == 0) {
        // 0x8005F160: nop
    
            goto L_8005F1E4;
    }
    // 0x8005F160: nop

    // 0x8005F164: lui         $s3, 0xFF
    ctx->r19 = S32(0XFF << 16);
    // 0x8005F168: ori         $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 | 0XFFFF;
    // 0x8005F16C: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x8005F170: addiu       $s5, $s5, 0x5A30
    ctx->r21 = ADD32(ctx->r21, 0X5A30);
    // 0x8005F174: lui         $s4, 0x800
    ctx->r20 = S32(0X800 << 16);
    // 0x8005F178: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8005F17C: addu        $v0, $s2, $v1
    ctx->r2 = ADD32(ctx->r18, ctx->r3);
L_8005F180:
    // 0x8005F180: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x8005F184: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005F188: beq         $v0, $zero, L_8005F1C8
    if (ctx->r2 == 0) {
        // 0x8005F18C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8005F1C8;
    }
    // 0x8005F18C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8005F190:
    // 0x8005F190: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8005F194: jal         0x8005F340
    // 0x8005F198: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8005F340(rdram, ctx);
        goto after_0;
    // 0x8005F198: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8005F19C: and         $s0, $s0, $s3
    ctx->r16 = ctx->r16 & ctx->r19;
    // 0x8005F1A0: srl         $s0, $s0, 1
    ctx->r16 = S32(U32(ctx->r16) >> 1);
    // 0x8005F1A4: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8005F1A8: addu        $s0, $s0, $s5
    ctx->r16 = ADD32(ctx->r16, ctx->r21);
    // 0x8005F1AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005F1B0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8005F1B4: or          $v0, $v0, $s4
    ctx->r2 = ctx->r2 | ctx->r20;
    // 0x8005F1B8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8005F1BC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005F1C0: bne         $v0, $zero, L_8005F190
    if (ctx->r2 != 0) {
        // 0x8005F1C4: nop
    
            goto L_8005F190;
    }
    // 0x8005F1C4: nop

L_8005F1C8:
    // 0x8005F1C8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005F1CC: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005F1D0: lw          $v0, -0x6A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6A0);
    // 0x8005F1D4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8005F1D8: addiu       $v1, $v1, -0x6A0
    ctx->r3 = ADD32(ctx->r3, -0X6A0);
    // 0x8005F1DC: bne         $v0, $zero, L_8005F180
    if (ctx->r2 != 0) {
        // 0x8005F1E0: addu        $v0, $s2, $v1
        ctx->r2 = ADD32(ctx->r18, ctx->r3);
            goto L_8005F180;
    }
    // 0x8005F1E0: addu        $v0, $s2, $v1
    ctx->r2 = ADD32(ctx->r18, ctx->r3);
L_8005F1E4:
    // 0x8005F1E4: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8005F1E8: lw          $v1, 0x4058($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4058);
    // 0x8005F1EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005F1F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F1F4: sw          $v1, -0x40($at)
    MEM_W(-0X40, ctx->r1) = ctx->r3;
    // 0x8005F1F8: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8005F1FC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F200: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8005F204: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005F208: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005F20C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F210: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005F214: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8005F218: jr          $ra
    // 0x8005F21C: nop

    return;
    // 0x8005F21C: nop

;}
RECOMP_FUNC void func_8005F220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F220: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005F224: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005F228: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8005F22C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8005F230: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8005F234: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005F238: bgez        $s1, L_8005F248
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8005F23C: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8005F248;
    }
    // 0x8005F23C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005F240: j           L_8005F304
    // 0x8005F244: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
        goto L_8005F304;
    // 0x8005F244: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_8005F248:
    // 0x8005F248: sll         $v0, $s1, 8
    ctx->r2 = S32(ctx->r17 << 8);
    // 0x8005F24C: srl         $s0, $v0, 9
    ctx->r16 = S32(U32(ctx->r2) >> 9);
    // 0x8005F250: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8005F254: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005F258: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005F25C: lw          $v1, 0x5A30($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5A30);
    // 0x8005F260: bne         $v1, $zero, L_8005F2D0
    if (ctx->r3 != 0) {
        // 0x8005F264: lui         $v0, 0xF3FF
        ctx->r2 = S32(0XF3FF << 16);
            goto L_8005F2D0;
    }
    // 0x8005F264: lui         $v0, 0xF3FF
    ctx->r2 = S32(0XF3FF << 16);
    // 0x8005F268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005F26C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005F270: sw          $v0, -0x6C0($at)
    MEM_W(-0X6C0, ctx->r1) = ctx->r2;
L_8005F274:
    // 0x8005F274: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005F278: addiu       $a0, $a0, 0x4058
    ctx->r4 = ADD32(ctx->r4, 0X4058);
    // 0x8005F27C: jal         0x80060454
    // 0x8005F280: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80060454(rdram, ctx);
        goto after_0;
    // 0x8005F280: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8005F284: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005F288: bne         $v1, $zero, L_8005F2A8
    if (ctx->r3 != 0) {
        // 0x8005F28C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8005F2A8;
    }
    // 0x8005F28C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005F290: jal         0x8005EED0
    // 0x8005F294: nop

    func_8005EED0(rdram, ctx);
        goto after_1;
    // 0x8005F294: nop

    after_1:
    // 0x8005F298: jal         0x8005EEEC
    // 0x8005F29C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8005EEEC(rdram, ctx);
        goto after_2;
    // 0x8005F29C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_2:
    // 0x8005F2A0: j           L_8005F274
    // 0x8005F2A4: nop

        goto L_8005F274;
    // 0x8005F2A4: nop

L_8005F2A8:
    // 0x8005F2A8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005F2AC: addiu       $v0, $v0, 0x5A30
    ctx->r2 = ADD32(ctx->r2, 0X5A30);
    // 0x8005F2B0: sll         $s0, $a0, 2
    ctx->r16 = S32(ctx->r4 << 2);
    // 0x8005F2B4: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8005F2B8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005F2BC: sw          $zero, -0x6C0($at)
    MEM_W(-0X6C0, ctx->r1) = 0;
    // 0x8005F2C0: jal         0x8005EAB0
    // 0x8005F2C4: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    func_8005EAB0(rdram, ctx);
        goto after_3;
    // 0x8005F2C4: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    after_3:
    // 0x8005F2C8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8005F2CC: lui         $v0, 0xF3FF
    ctx->r2 = S32(0XF3FF << 16);
L_8005F2D0:
    // 0x8005F2D0: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x8005F2D4: beq         $s2, $zero, L_8005F300
    if (ctx->r18 == 0) {
        // 0x8005F2D8: and         $v1, $v1, $v0
        ctx->r3 = ctx->r3 & ctx->r2;
            goto L_8005F300;
    }
    // 0x8005F2D8: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8005F2DC: lhu         $a0, 0x6C($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X6C);
    // 0x8005F2E0: andi        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 & 0X80;
    // 0x8005F2E4: bne         $v0, $zero, L_8005F300
    if (ctx->r2 != 0) {
        // 0x8005F2E8: sw          $s1, 0x38($s2)
        MEM_W(0X38, ctx->r18) = ctx->r17;
            goto L_8005F300;
    }
    // 0x8005F2E8: sw          $s1, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r17;
    // 0x8005F2EC: andi        $v0, $a0, 0x400
    ctx->r2 = ctx->r4 & 0X400;
    // 0x8005F2F0: bne         $v0, $zero, L_8005F304
    if (ctx->r2 != 0) {
        // 0x8005F2F4: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8005F304;
    }
    // 0x8005F2F4: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8005F2F8: ori         $v0, $a0, 0x400
    ctx->r2 = ctx->r4 | 0X400;
    // 0x8005F2FC: sh          $v0, 0x6C($s2)
    MEM_H(0X6C, ctx->r18) = ctx->r2;
L_8005F300:
    // 0x8005F300: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8005F304:
    // 0x8005F304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F308: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8005F30C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005F310: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005F314: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005F318: jr          $ra
    // 0x8005F31C: nop

    return;
    // 0x8005F31C: nop

;}
RECOMP_FUNC void func_8005F320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F324: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005F328: jal         0x8005F220
    // 0x8005F32C: nop

    func_8005F220(rdram, ctx);
        goto after_0;
    // 0x8005F32C: nop

    after_0:
    // 0x8005F330: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005F334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F338: jr          $ra
    // 0x8005F33C: nop

    return;
    // 0x8005F33C: nop

;}
RECOMP_FUNC void func_8005F340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F344: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005F348: jal         0x8005F220
    // 0x8005F34C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8005F220(rdram, ctx);
        goto after_0;
    // 0x8005F34C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8005F350: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005F354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F358: jr          $ra
    // 0x8005F35C: nop

    return;
    // 0x8005F35C: nop

;}
RECOMP_FUNC void func_8005F360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F364: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005F368: jal         0x8005F220
    // 0x8005F36C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8005F220(rdram, ctx);
        goto after_0;
    // 0x8005F36C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8005F370: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005F374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F378: jr          $ra
    // 0x8005F37C: nop

    return;
    // 0x8005F37C: nop

;}
RECOMP_FUNC void func_8005F380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F380: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005F384: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005F388: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005F38C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8005F390: lui         $s2, 0x3
    ctx->r18 = S32(0X3 << 16);
    // 0x8005F394: ori         $s2, $s2, 0xD40
    ctx->r18 = ctx->r18 | 0XD40;
    // 0x8005F398: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005F39C: lui         $s1, 0x1
    ctx->r17 = S32(0X1 << 16);
    // 0x8005F3A0: ori         $s1, $s1, 0x3880
    ctx->r17 = ctx->r17 | 0X3880;
    // 0x8005F3A4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8005F3A8: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8005F3AC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8005F3B0: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x8005F3B4: addiu       $s3, $s3, -0x5480
    ctx->r19 = ADD32(ctx->r19, -0X5480);
    // 0x8005F3B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_8005F3BC:
    // 0x8005F3BC: jal         0x8005E124
    // 0x8005F3C0: nop

    func_8005E124(rdram, ctx);
        goto after_0;
    // 0x8005F3C0: nop

    after_0:
    // 0x8005F3C4: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005F3C8: beq         $v0, $zero, L_8005F3E4
    if (ctx->r2 == 0) {
        // 0x8005F3CC: nop
    
            goto L_8005F3E4;
    }
    // 0x8005F3CC: nop

    // 0x8005F3D0: jal         0x8005E0EC
    // 0x8005F3D4: nop

    func_8005E0EC(rdram, ctx);
        goto after_1;
    // 0x8005F3D4: nop

    after_1:
    // 0x8005F3D8: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005F3DC: bne         $v0, $zero, L_8005F438
    if (ctx->r2 != 0) {
        // 0x8005F3E0: nop
    
            goto L_8005F438;
    }
    // 0x8005F3E0: nop

L_8005F3E4:
    // 0x8005F3E4: jal         0x8005EED0
    // 0x8005F3E8: nop

    func_8005EED0(rdram, ctx);
        goto after_2;
    // 0x8005F3E8: nop

    after_2:
    // 0x8005F3EC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005F3F0: beq         $a0, $s4, L_8005F438
    if (ctx->r4 == ctx->r20) {
        // 0x8005F3F4: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_8005F438;
    }
    // 0x8005F3F4: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8005F3F8: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8005F3FC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005F400: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8005F404: lw          $v1, -0x74E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X74E0);
    // 0x8005F408: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x8005F40C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005F410: slti        $v0, $v1, 0x14
    ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x8005F414: bne         $v0, $zero, L_8005F438
    if (ctx->r2 != 0) {
        // 0x8005F418: slti        $v0, $v1, 0x385
        ctx->r2 = SIGNED(ctx->r3) < 0X385 ? 1 : 0;
            goto L_8005F438;
    }
    // 0x8005F418: slti        $v0, $v1, 0x385
    ctx->r2 = SIGNED(ctx->r3) < 0X385 ? 1 : 0;
    // 0x8005F41C: bne         $v0, $zero, L_8005F42C
    if (ctx->r2 != 0) {
        // 0x8005F420: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8005F42C;
    }
    // 0x8005F420: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005F424: jal         0x8005EEEC
    // 0x8005F428: nop

    func_8005EEEC(rdram, ctx);
        goto after_3;
    // 0x8005F428: nop

    after_3:
L_8005F42C:
    // 0x8005F42C: slti        $v0, $s0, 0x5
    ctx->r2 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8005F430: bne         $v0, $zero, L_8005F3BC
    if (ctx->r2 != 0) {
        // 0x8005F434: nop
    
            goto L_8005F3BC;
    }
    // 0x8005F434: nop

L_8005F438:
    // 0x8005F438: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005F43C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8005F440: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F444: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8005F448: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005F44C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005F450: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005F454: jr          $ra
    // 0x8005F458: nop

    return;
    // 0x8005F458: nop

;}
RECOMP_FUNC void func_8005F45C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F45C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005F460: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005F464: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8005F468: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005F46C: bne         $a0, $v0, L_8005F47C
    if (ctx->r4 != ctx->r2) {
        // 0x8005F470: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8005F47C;
    }
    // 0x8005F470: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005F474: lw          $v0, 0x34($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X34);
    // 0x8005F478: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
L_8005F47C:
    // 0x8005F47C: sltiu       $v0, $a0, 0x6AF
    ctx->r2 = ctx->r4 < 0X6AF ? 1 : 0;
    // 0x8005F480: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8005F484: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x8005F488: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8005F48C: addiu       $v1, $v1, 0x2590
    ctx->r3 = ADD32(ctx->r3, 0X2590);
    // 0x8005F490: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8005F494: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // 0x8005F498: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005F49C: bne         $v0, $zero, L_8005F4EC
    if (ctx->r2 != 0) {
        // 0x8005F4A0: sll         $s0, $a0, 3
        ctx->r16 = S32(ctx->r4 << 3);
            goto L_8005F4EC;
    }
    // 0x8005F4A0: sll         $s0, $a0, 3
    ctx->r16 = S32(ctx->r4 << 3);
    // 0x8005F4A4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005F4A8: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x8005F4AC: lw          $a0, 0x5584($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5584);
    // 0x8005F4B0: jal         0x8005DFF0
    // 0x8005F4B4: nop

    func_8005DFF0(rdram, ctx);
        goto after_0;
    // 0x8005F4B4: nop

    after_0:
    // 0x8005F4B8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8005F4BC: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8005F4C0: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x8005F4C4: lw          $v1, 0x5580($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5580);
    // 0x8005F4C8: lui         $a0, 0xBD
    ctx->r4 = S32(0XBD << 16);
    // 0x8005F4CC: addiu       $a0, $a0, -0x2F60
    ctx->r4 = ADD32(ctx->r4, -0X2F60);
    // 0x8005F4D0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8005F4D4: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x8005F4D8: lw          $a1, 0x5584($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5584);
    // 0x8005F4DC: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8005F4E0: jal         0x80060D70
    // 0x8005F4E4: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    func_80060D70(rdram, ctx);
        goto after_1;
    // 0x8005F4E4: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_1:
    // 0x8005F4E8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8005F4EC:
    // 0x8005F4EC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005F4F0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005F4F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005F4F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005F4FC: jr          $ra
    // 0x8005F500: nop

    return;
    // 0x8005F500: nop

;}
RECOMP_FUNC void func_8005F504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F504: jr          $ra
    // 0x8005F508: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x8005F508: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void func_8005F50C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F50C: jr          $ra
    // 0x8005F510: nop

    return;
    // 0x8005F510: nop

;}
RECOMP_FUNC void func_8005F514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F514: jr          $ra
    // 0x8005F518: nop

    return;
    // 0x8005F518: nop

;}
RECOMP_FUNC void func_8005F51C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F51C: jr          $ra
    // 0x8005F520: nop

    return;
    // 0x8005F520: nop

    // 0x8005F524: nop

    // 0x8005F528: nop

    // 0x8005F52C: nop

;}
RECOMP_FUNC void func_8005F530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F530: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005F534: sw          $zero, -0x68C($at)
    MEM_W(-0X68C, ctx->r1) = 0;
    // 0x8005F538: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005F53C: sw          $zero, -0x688($at)
    MEM_W(-0X688, ctx->r1) = 0;
    // 0x8005F540: jr          $ra
    // 0x8005F544: nop

    return;
    // 0x8005F544: nop

;}
RECOMP_FUNC void func_8005F548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F548: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F54C: lui         $a3, 0xBA00
    ctx->r7 = S32(0XBA00 << 16);
    // 0x8005F550: ori         $a3, $a3, 0x1402
    ctx->r7 = ctx->r7 | 0X1402;
    // 0x8005F554: lui         $t0, 0xB900
    ctx->r8 = S32(0XB900 << 16);
    // 0x8005F558: ori         $t0, $t0, 0x31D
    ctx->r8 = ctx->r8 | 0X31D;
    // 0x8005F55C: lui         $t1, 0xFF10
    ctx->r9 = S32(0XFF10 << 16);
    // 0x8005F560: ori         $t1, $t1, 0x18F
    ctx->r9 = ctx->r9 | 0X18F;
    // 0x8005F564: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005F568: lw          $v1, 0x3EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3EF0);
    // 0x8005F56C: lui         $t2, 0xF663
    ctx->r10 = S32(0XF663 << 16);
    // 0x8005F570: ori         $t2, $t2, 0xC3BC
    ctx->r10 = ctx->r10 | 0XC3BC;
    // 0x8005F574: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
    // 0x8005F578: andi        $a0, $a0, 0xF800
    ctx->r4 = ctx->r4 & 0XF800;
    // 0x8005F57C: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x8005F580: andi        $a1, $a1, 0x7C0
    ctx->r5 = ctx->r5 & 0X7C0;
    // 0x8005F584: or          $a0, $a0, $a1
    ctx->r4 = ctx->r4 | ctx->r5;
    // 0x8005F588: sra         $a2, $a2, 2
    ctx->r6 = S32(SIGNED(ctx->r6) >> 2);
    // 0x8005F58C: andi        $a2, $a2, 0x3E
    ctx->r6 = ctx->r6 & 0X3E;
    // 0x8005F590: or          $a0, $a0, $a2
    ctx->r4 = ctx->r4 | ctx->r6;
    // 0x8005F594: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005F598: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8005F59C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F5A0: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F5A4: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8005F5A8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005F5AC: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8005F5B0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F5B4: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F5B8: lui         $v0, 0x30
    ctx->r2 = S32(0X30 << 16);
    // 0x8005F5BC: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8005F5C0: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8005F5C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F5C8: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F5CC: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x8005F5D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F5D4: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F5D8: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8005F5DC: addiu       $v0, $v0, 0x0
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x8005F5E0: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x8005F5E4: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x8005F5E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F5EC: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F5F0: lui         $v0, 0xF700
    ctx->r2 = S32(0XF700 << 16);
    // 0x8005F5F4: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x8005F5F8: ori         $v0, $a0, 0x1
    ctx->r2 = ctx->r4 | 0X1;
    // 0x8005F5FC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005F600: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8005F604: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8005F608: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
    // 0x8005F60C: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8005F610: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005F614: sw          $a3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r7;
    // 0x8005F618: sw          $t0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r8;
    // 0x8005F61C: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x8005F620: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
    // 0x8005F624: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F628: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F62C: sw          $t2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r10;
    // 0x8005F630: jal         0x8005F530
    // 0x8005F634: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    func_8005F530(rdram, ctx);
        goto after_0;
    // 0x8005F634: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    after_0:
    // 0x8005F638: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005F63C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F640: jr          $ra
    // 0x8005F644: nop

    return;
    // 0x8005F644: nop

;}
RECOMP_FUNC void func_8005F648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F648: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8005F64C: bne         $a2, $zero, L_8005F67C
    if (ctx->r6 != 0) {
        // 0x8005F650: lui         $a1, 0xB900
        ctx->r5 = S32(0XB900 << 16);
            goto L_8005F67C;
    }
    // 0x8005F650: lui         $a1, 0xB900
    ctx->r5 = S32(0XB900 << 16);
    // 0x8005F654: ori         $a1, $a1, 0x31D
    ctx->r5 = ctx->r5 | 0X31D;
    // 0x8005F658: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005F65C: lw          $v1, 0x3EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3EF0);
    // 0x8005F660: lui         $a0, 0xF0A
    ctx->r4 = S32(0XF0A << 16);
    // 0x8005F664: ori         $a0, $a0, 0x7008
    ctx->r4 = ctx->r4 | 0X7008;
    // 0x8005F668: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8005F66C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F670: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F674: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8005F678: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
L_8005F67C:
    // 0x8005F67C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005F680: lw          $v0, 0x3EF0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3EF0);
    // 0x8005F684: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x8005F688: ori         $a0, $a0, 0x1402
    ctx->r4 = ctx->r4 | 0X1402;
    // 0x8005F68C: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8005F690: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F694: sw          $v1, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r3;
    // 0x8005F698: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8005F69C: jr          $ra
    // 0x8005F6A0: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    return;
    // 0x8005F6A0: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void func_8005F6A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F6A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F6A8: bne         $a0, $zero, L_8005F6CC
    if (ctx->r4 != 0) {
        // 0x8005F6AC: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8005F6CC;
    }
    // 0x8005F6AC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005F6B0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005F6B4: lw          $v0, -0x68C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68C);
    // 0x8005F6B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005F6BC: beq         $v0, $v1, L_8005F740
    if (ctx->r2 == ctx->r3) {
        // 0x8005F6C0: nop
    
            goto L_8005F740;
    }
    // 0x8005F6C0: nop

    // 0x8005F6C4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005F6C8: sw          $v1, -0x68C($at)
    MEM_W(-0X68C, ctx->r1) = ctx->r3;
L_8005F6CC:
    // 0x8005F6CC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005F6D0: lw          $v1, 0x3EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3EF0);
    // 0x8005F6D4: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8005F6D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F6DC: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F6E0: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8005F6E4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005F6E8: jal         0x8005F648
    // 0x8005F6EC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    func_8005F648(rdram, ctx);
        goto after_0;
    // 0x8005F6EC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    after_0:
    // 0x8005F6F0: lui         $a2, 0xBB00
    ctx->r6 = S32(0XBB00 << 16);
    // 0x8005F6F4: ori         $a2, $a2, 0x1
    ctx->r6 = ctx->r6 | 0X1;
    // 0x8005F6F8: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8005F6FC: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x8005F700: lui         $a3, 0xFC11
    ctx->r7 = S32(0XFC11 << 16);
    // 0x8005F704: ori         $a3, $a3, 0x9623
    ctx->r7 = ctx->r7 | 0X9623;
    // 0x8005F708: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005F70C: lw          $v1, 0x3EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3EF0);
    // 0x8005F710: lui         $a0, 0xFF2F
    ctx->r4 = S32(0XFF2F << 16);
    // 0x8005F714: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x8005F718: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8005F71C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F720: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F724: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8005F728: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x8005F72C: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8005F730: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F734: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F738: sw          $a3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r7;
    // 0x8005F73C: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
L_8005F740:
    // 0x8005F740: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005F744: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F748: jr          $ra
    // 0x8005F74C: nop

    return;
    // 0x8005F74C: nop

;}
RECOMP_FUNC void func_8005F750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F750: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005F754: lw          $v0, -0x68C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68C);
;}
RECOMP_FUNC void func_8005F758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F75C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005F760: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8005F764: beq         $v0, $s0, L_8005F7CC
    if (ctx->r2 == ctx->r16) {
        // 0x8005F768: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8005F7CC;
    }
    // 0x8005F768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F76C: jal         0x8005F6A4
    // 0x8005F770: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8005F6A4(rdram, ctx);
        goto after_0;
    // 0x8005F770: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x8005F774: lui         $a2, 0xB900
    ctx->r6 = S32(0XB900 << 16);
    // 0x8005F778: ori         $a2, $a2, 0x31D
    ctx->r6 = ctx->r6 | 0X31D;
    // 0x8005F77C: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x8005F780: ori         $a1, $a1, 0x4240
    ctx->r5 = ctx->r5 | 0X4240;
    // 0x8005F784: lui         $a3, 0xFC11
    ctx->r7 = S32(0XFC11 << 16);
    // 0x8005F788: ori         $a3, $a3, 0x9623
    ctx->r7 = ctx->r7 | 0X9623;
    // 0x8005F78C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005F790: lw          $v1, 0x3EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3EF0);
    // 0x8005F794: lui         $a0, 0xFF2F
    ctx->r4 = S32(0XFF2F << 16);
    // 0x8005F798: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x8005F79C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005F7A0: sw          $s0, -0x68C($at)
    MEM_W(-0X68C, ctx->r1) = ctx->r16;
    // 0x8005F7A4: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8005F7A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F7AC: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F7B0: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8005F7B4: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x8005F7B8: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8005F7BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F7C0: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F7C4: sw          $a3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r7;
    // 0x8005F7C8: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
L_8005F7CC:
    // 0x8005F7CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F7D0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005F7D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F7D8: jr          $ra
    // 0x8005F7DC: nop

    return;
    // 0x8005F7DC: nop

;}
RECOMP_FUNC void func_8005F7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F7E0: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8005F7E4: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8005F7E8: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8005F7EC: beq         $v0, $zero, L_8005F7F8
    if (ctx->r2 == 0) {
        // 0x8005F7F0: addiu       $a3, $zero, 0xFF
        ctx->r7 = ADD32(0, 0XFF);
            goto L_8005F7F8;
    }
    // 0x8005F7F0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8005F7F4: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
L_8005F7F8:
    // 0x8005F7F8: sra         $a0, $a0, 8
    ctx->r4 = S32(SIGNED(ctx->r4) >> 8);
    // 0x8005F7FC: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8005F800: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8005F804: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8005F808: beq         $v0, $zero, L_8005F814
    if (ctx->r2 == 0) {
        // 0x8005F80C: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_8005F814;
    }
    // 0x8005F80C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8005F810: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
L_8005F814:
    // 0x8005F814: sra         $v0, $a0, 7
    ctx->r2 = S32(SIGNED(ctx->r4) >> 7);
    // 0x8005F818: andi        $a0, $v0, 0x1FE
    ctx->r4 = ctx->r2 & 0X1FE;
    // 0x8005F81C: slti        $v0, $a0, 0x100
    ctx->r2 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x8005F820: beq         $v0, $zero, L_8005F82C
    if (ctx->r2 == 0) {
        // 0x8005F824: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_8005F82C;
    }
    // 0x8005F824: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8005F828: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8005F82C:
    // 0x8005F82C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005F830: lw          $a0, 0x3EF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3EF0);
    // 0x8005F834: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x8005F838: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8005F83C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F840: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F844: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8005F848: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8005F84C: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8005F850: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005F854: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005F858: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x8005F85C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8005F860: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005F864: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8005F868: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005F86C: jr          $ra
    // 0x8005F870: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    return;
    // 0x8005F870: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_8005F874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F874: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005F878: lw          $v0, -0x688($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X688);
    // 0x8005F87C: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8005F880: beq         $a3, $v0, L_8005F948
    if (ctx->r7 == ctx->r2) {
        // 0x8005F884: lui         $a1, 0xF500
        ctx->r5 = S32(0XF500 << 16);
            goto L_8005F948;
    }
    // 0x8005F884: lui         $a1, 0xF500
    ctx->r5 = S32(0XF500 << 16);
    // 0x8005F888: ori         $a1, $a1, 0x100
    ctx->r5 = ctx->r5 | 0X100;
    // 0x8005F88C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005F890: lw          $v0, 0x3EF0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3EF0);
    // 0x8005F894: lui         $a2, 0x73F
    ctx->r6 = S32(0X73F << 16);
    // 0x8005F898: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x8005F89C: lui         $a0, 0xE700
    ctx->r4 = S32(0XE700 << 16);
    // 0x8005F8A0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005F8A4: sw          $a3, -0x688($at)
    MEM_W(-0X688, ctx->r1) = ctx->r7;
    // 0x8005F8A8: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8005F8AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F8B0: sw          $v1, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r3;
    // 0x8005F8B4: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x8005F8B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F8BC: sw          $v1, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r3;
    // 0x8005F8C0: lui         $v1, 0xFD10
    ctx->r3 = S32(0XFD10 << 16);
    // 0x8005F8C4: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x8005F8C8: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x8005F8CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F8D0: sw          $v1, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r3;
    // 0x8005F8D4: lui         $v1, 0xE800
    ctx->r3 = S32(0XE800 << 16);
    // 0x8005F8D8: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x8005F8DC: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x8005F8E0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F8E4: sw          $v1, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r3;
    // 0x8005F8E8: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x8005F8EC: sw          $v1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r3;
    // 0x8005F8F0: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x8005F8F4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F8F8: sw          $v1, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r3;
    // 0x8005F8FC: lui         $v1, 0xE600
    ctx->r3 = S32(0XE600 << 16);
    // 0x8005F900: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x8005F904: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x8005F908: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F90C: sw          $v1, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r3;
    // 0x8005F910: lui         $v1, 0xF000
    ctx->r3 = S32(0XF000 << 16);
    // 0x8005F914: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x8005F918: addiu       $v1, $v0, 0x38
    ctx->r3 = ADD32(ctx->r2, 0X38);
    // 0x8005F91C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8005F920: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8005F924: sw          $a3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r7;
    // 0x8005F928: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x8005F92C: sw          $a1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r5;
    // 0x8005F930: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x8005F934: sw          $a2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r6;
    // 0x8005F938: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F93C: sw          $v1, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r3;
    // 0x8005F940: sw          $a0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r4;
    // 0x8005F944: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
L_8005F948:
    // 0x8005F948: jr          $ra
    // 0x8005F94C: nop

    return;
    // 0x8005F94C: nop

;}
RECOMP_FUNC void func_8005F950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F950: addu        $t5, $a0, $zero
    ctx->r13 = ADD32(ctx->r4, 0);
    // 0x8005F954: addu        $t7, $a1, $zero
    ctx->r15 = ADD32(ctx->r5, 0);
    // 0x8005F958: addu        $t8, $a2, $zero
    ctx->r24 = ADD32(ctx->r6, 0);
    // 0x8005F95C: addu        $t9, $a3, $zero
    ctx->r25 = ADD32(ctx->r7, 0);
    // 0x8005F960: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8005F964: lw          $t0, 0x3EF0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3EF0);
    // 0x8005F968: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x8005F96C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8005F970: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x8005F974: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F978: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F97C: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8005F980: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8005F984: srl         $v0, $v1, 16
    ctx->r2 = S32(U32(ctx->r3) >> 16);
    // 0x8005F988: andi        $t4, $v0, 0xFF
    ctx->r12 = ctx->r2 & 0XFF;
    // 0x8005F98C: andi        $v0, $v1, 0xFF00
    ctx->r2 = ctx->r3 & 0XFF00;
    // 0x8005F990: srl         $t2, $v0, 8
    ctx->r10 = S32(U32(ctx->r2) >> 8);
    // 0x8005F994: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005F998: lw          $v0, -0x68C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68C);
    // 0x8005F99C: srl         $t6, $v1, 24
    ctx->r14 = S32(U32(ctx->r3) >> 24);
    // 0x8005F9A0: andi        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 & 0XFF;
    // 0x8005F9A4: beq         $v0, $t1, L_8005FA18
    if (ctx->r2 == ctx->r9) {
        // 0x8005F9A8: sw          $zero, 0x4($t0)
        MEM_W(0X4, ctx->r8) = 0;
            goto L_8005FA18;
    }
    // 0x8005F9A8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8005F9AC: lui         $v1, 0xBA00
    ctx->r3 = S32(0XBA00 << 16);
    // 0x8005F9B0: ori         $v1, $v1, 0x1402
    ctx->r3 = ctx->r3 | 0X1402;
    // 0x8005F9B4: lui         $a2, 0xFCFF
    ctx->r6 = S32(0XFCFF << 16);
    // 0x8005F9B8: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x8005F9BC: lui         $a0, 0xFFFD
    ctx->r4 = S32(0XFFFD << 16);
    // 0x8005F9C0: ori         $a0, $a0, 0xF6FB
    ctx->r4 = ctx->r4 | 0XF6FB;
    // 0x8005F9C4: lui         $a3, 0xB900
    ctx->r7 = S32(0XB900 << 16);
    // 0x8005F9C8: ori         $a3, $a3, 0x31D
    ctx->r7 = ctx->r7 | 0X31D;
    // 0x8005F9CC: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x8005F9D0: ori         $a1, $a1, 0x4240
    ctx->r5 = ctx->r5 | 0X4240;
    // 0x8005F9D4: addiu       $v0, $t0, 0x10
    ctx->r2 = ADD32(ctx->r8, 0X10);
    // 0x8005F9D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F9DC: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F9E0: addiu       $v0, $t0, 0x18
    ctx->r2 = ADD32(ctx->r8, 0X18);
    // 0x8005F9E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F9E8: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005F9EC: addiu       $v0, $t0, 0x20
    ctx->r2 = ADD32(ctx->r8, 0X20);
    // 0x8005F9F0: sw          $v1, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r3;
    // 0x8005F9F4: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
    // 0x8005F9F8: sw          $a2, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r6;
    // 0x8005F9FC: sw          $a0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r4;
    // 0x8005FA00: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FA04: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FA08: sw          $a3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r7;
    // 0x8005FA0C: sw          $a1, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r5;
    // 0x8005FA10: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005FA14: sw          $t1, -0x68C($at)
    MEM_W(-0X68C, ctx->r1) = ctx->r9;
L_8005FA18:
    // 0x8005FA18: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8005FA1C: lw          $a1, 0x3EF0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3EF0);
    // 0x8005FA20: sll         $v1, $t2, 16
    ctx->r3 = S32(ctx->r10 << 16);
    // 0x8005FA24: lui         $a0, 0xF600
    ctx->r4 = S32(0XF600 << 16);
    // 0x8005FA28: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x8005FA2C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FA30: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FA34: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8005FA38: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8005FA3C: sll         $v0, $t4, 24
    ctx->r2 = S32(ctx->r12 << 24);
    // 0x8005FA40: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005FA44: sll         $v1, $t3, 8
    ctx->r3 = S32(ctx->r11 << 8);
    // 0x8005FA48: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005FA4C: or          $v0, $v0, $t6
    ctx->r2 = ctx->r2 | ctx->r14;
    // 0x8005FA50: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8005FA54: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x8005FA58: addu        $v1, $t5, $t8
    ctx->r3 = ADD32(ctx->r13, ctx->r24);
    // 0x8005FA5C: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x8005FA60: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x8005FA64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FA68: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FA6C: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x8005FA70: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x8005FA74: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005FA78: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8005FA7C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005FA80: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x8005FA84: andi        $v1, $t5, 0x3FF
    ctx->r3 = ctx->r13 & 0X3FF;
    // 0x8005FA88: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x8005FA8C: andi        $v0, $t7, 0x3FF
    ctx->r2 = ctx->r15 & 0X3FF;
    // 0x8005FA90: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005FA94: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005FA98: jr          $ra
    // 0x8005FA9C: sw          $v1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r3;
    return;
    // 0x8005FA9C: sw          $v1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r3;
;}
RECOMP_FUNC void func_8005FAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FAA0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8005FAA4: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x8005FAA8: addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // 0x8005FAAC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8005FAB0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8005FAB4: slti        $v0, $a3, 0x191
    ctx->r2 = SIGNED(ctx->r7) < 0X191 ? 1 : 0;
    // 0x8005FAB8: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x8005FABC: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8005FAC0: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8005FAC4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8005FAC8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8005FACC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8005FAD0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8005FAD4: beq         $v0, $zero, L_800603C8
    if (ctx->r2 == 0) {
        // 0x8005FAD8: sw          $s0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r16;
            goto L_800603C8;
    }
    // 0x8005FAD8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8005FADC: addu        $v0, $a3, $s1
    ctx->r2 = ADD32(ctx->r7, ctx->r17);
    // 0x8005FAE0: blez        $v0, L_800603C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005FAE4: lui         $v1, 0xDFFF
        ctx->r3 = S32(0XDFFF << 16);
            goto L_800603C8;
    }
    // 0x8005FAE4: lui         $v1, 0xDFFF
    ctx->r3 = S32(0XDFFF << 16);
    // 0x8005FAE8: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8005FAEC: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8005FAF0: lw          $t0, 0x3EF0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3EF0);
    // 0x8005FAF4: lui         $v0, 0x2000
    ctx->r2 = S32(0X2000 << 16);
    // 0x8005FAF8: and         $v0, $t2, $v0
    ctx->r2 = ctx->r10 & ctx->r2;
    // 0x8005FAFC: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8005FB00: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x8005FB04: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FB08: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FB0C: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8005FB10: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8005FB14: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8005FB18: lw          $s3, 0x4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4);
    // 0x8005FB1C: and         $t2, $t2, $v1
    ctx->r10 = ctx->r10 & ctx->r3;
    // 0x8005FB20: beq         $s3, $zero, L_8005FBC0
    if (ctx->r19 == 0) {
        // 0x8005FB24: addu        $s7, $a2, $zero
        ctx->r23 = ADD32(ctx->r6, 0);
            goto L_8005FBC0;
    }
    // 0x8005FB24: addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // 0x8005FB28: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x8005FB2C: sra         $t1, $v0, 1
    ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8005FB30: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
    // 0x8005FB34: addiu       $v1, $t1, 0x7
    ctx->r3 = ADD32(ctx->r9, 0X7);
    // 0x8005FB38: addiu       $v0, $zero, -0x8
    ctx->r2 = ADD32(0, -0X8);
    // 0x8005FB3C: and         $t1, $v1, $v0
    ctx->r9 = ctx->r3 & ctx->r2;
    // 0x8005FB40: lui         $a1, 0x708
    ctx->r5 = S32(0X708 << 16);
    // 0x8005FB44: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x8005FB48: lui         $a2, 0x8
    ctx->r6 = S32(0X8 << 16);
    // 0x8005FB4C: ori         $a2, $a2, 0x200
    ctx->r6 = ctx->r6 | 0X200;
    // 0x8005FB50: addiu       $v0, $t0, 0x10
    ctx->r2 = ADD32(ctx->r8, 0X10);
    // 0x8005FB54: andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // 0x8005FB58: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FB5C: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FB60: lui         $v0, 0xFD48
    ctx->r2 = S32(0XFD48 << 16);
    // 0x8005FB64: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x8005FB68: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005FB6C: subu        $v0, $t2, $v0
    ctx->r2 = SUB32(ctx->r10, ctx->r2);
    // 0x8005FB70: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x8005FB74: addiu       $v0, $t0, 0x18
    ctx->r2 = ADD32(ctx->r8, 0X18);
    // 0x8005FB78: sra         $v1, $t1, 3
    ctx->r3 = S32(SIGNED(ctx->r9) >> 3);
    // 0x8005FB7C: andi        $v1, $v1, 0x1FF
    ctx->r3 = ctx->r3 & 0X1FF;
    // 0x8005FB80: sll         $v1, $v1, 9
    ctx->r3 = S32(ctx->r3 << 9);
    // 0x8005FB84: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FB88: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FB8C: lui         $v0, 0xF548
    ctx->r2 = S32(0XF548 << 16);
    // 0x8005FB90: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x8005FB94: sw          $v0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r2;
    // 0x8005FB98: addiu       $v0, $t0, 0x20
    ctx->r2 = ADD32(ctx->r8, 0X20);
    // 0x8005FB9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FBA0: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FBA4: lui         $v0, 0xF540
    ctx->r2 = S32(0XF540 << 16);
    // 0x8005FBA8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005FBAC: sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // 0x8005FBB0: sw          $a1, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r5;
    // 0x8005FBB4: sw          $v1, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r3;
    // 0x8005FBB8: j           L_8005FC44
    // 0x8005FBBC: sw          $a2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r6;
        goto L_8005FC44;
    // 0x8005FBBC: sw          $a2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r6;
L_8005FBC0:
    // 0x8005FBC0: addiu       $v1, $s1, 0x7
    ctx->r3 = ADD32(ctx->r17, 0X7);
    // 0x8005FBC4: addiu       $v0, $zero, -0x8
    ctx->r2 = ADD32(0, -0X8);
    // 0x8005FBC8: and         $t1, $v1, $v0
    ctx->r9 = ctx->r3 & ctx->r2;
    // 0x8005FBCC: lui         $a0, 0x708
    ctx->r4 = S32(0X708 << 16);
    // 0x8005FBD0: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x8005FBD4: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    // 0x8005FBD8: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x8005FBDC: addiu       $v0, $t0, 0x10
    ctx->r2 = ADD32(ctx->r8, 0X10);
    // 0x8005FBE0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FBE4: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FBE8: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x8005FBEC: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8005FBF0: lui         $v1, 0xFD48
    ctx->r3 = S32(0XFD48 << 16);
    // 0x8005FBF4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005FBF8: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x8005FBFC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005FC00: subu        $v0, $t2, $v0
    ctx->r2 = SUB32(ctx->r10, ctx->r2);
    // 0x8005FC04: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x8005FC08: addiu       $v0, $t0, 0x18
    ctx->r2 = ADD32(ctx->r8, 0X18);
    // 0x8005FC0C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FC10: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FC14: sra         $v0, $t1, 3
    ctx->r2 = S32(SIGNED(ctx->r9) >> 3);
    // 0x8005FC18: andi        $v0, $v0, 0x1FF
    ctx->r2 = ctx->r2 & 0X1FF;
    // 0x8005FC1C: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x8005FC20: lui         $v1, 0xF548
    ctx->r3 = S32(0XF548 << 16);
    // 0x8005FC24: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005FC28: addiu       $v1, $t0, 0x20
    ctx->r3 = ADD32(ctx->r8, 0X20);
    // 0x8005FC2C: sw          $v0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r2;
    // 0x8005FC30: sw          $a0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r4;
    // 0x8005FC34: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FC38: sw          $v1, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r3;
    // 0x8005FC3C: sw          $v0, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r2;
    // 0x8005FC40: sw          $a1, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r5;
L_8005FC44:
    // 0x8005FC44: nop

    // 0x8005FC48: mult        $s7, $t1
    result = S64(S32(ctx->r23)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005FC4C: mflo        $v0
    ctx->r2 = lo;
    // 0x8005FC50: nop

    // 0x8005FC54: nop

    // 0x8005FC58: slti        $v0, $v0, 0x7D1
    ctx->r2 = SIGNED(ctx->r2) < 0X7D1 ? 1 : 0;
    // 0x8005FC5C: beq         $v0, $zero, L_8005FC6C
    if (ctx->r2 == 0) {
        // 0x8005FC60: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_8005FC6C;
    }
    // 0x8005FC60: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8005FC64: j           L_8005FCEC
    // 0x8005FC68: addu        $t2, $s7, $zero
    ctx->r10 = ADD32(ctx->r23, 0);
        goto L_8005FCEC;
    // 0x8005FC68: addu        $t2, $s7, $zero
    ctx->r10 = ADD32(ctx->r23, 0);
L_8005FC6C:
    // 0x8005FC6C: addiu       $v0, $zero, 0x7D0
    ctx->r2 = ADD32(0, 0X7D0);
    // 0x8005FC70: div         $zero, $v0, $t1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r9)));
    // 0x8005FC74: bne         $t1, $zero, L_8005FC80
    if (ctx->r9 != 0) {
        // 0x8005FC78: nop
    
            goto L_8005FC80;
    }
    // 0x8005FC78: nop

    // 0x8005FC7C: break       7
    do_break(2147875964);
L_8005FC80:
    // 0x8005FC80: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005FC84: bne         $t1, $at, L_8005FC98
    if (ctx->r9 != ctx->r1) {
        // 0x8005FC88: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005FC98;
    }
    // 0x8005FC88: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005FC8C: bne         $v0, $at, L_8005FC98
    if (ctx->r2 != ctx->r1) {
        // 0x8005FC90: nop
    
            goto L_8005FC98;
    }
    // 0x8005FC90: nop

    // 0x8005FC94: break       6
    do_break(2147875988);
L_8005FC98:
    // 0x8005FC98: mflo        $t2
    ctx->r10 = lo;
    // 0x8005FC9C: nop

    // 0x8005FCA0: nop

    // 0x8005FCA4: div         $zero, $s7, $t2
    lo = S32(S64(S32(ctx->r23)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r23)) % S64(S32(ctx->r10)));
    // 0x8005FCA8: bne         $t2, $zero, L_8005FCB4
    if (ctx->r10 != 0) {
        // 0x8005FCAC: nop
    
            goto L_8005FCB4;
    }
    // 0x8005FCAC: nop

    // 0x8005FCB0: break       7
    do_break(2147876016);
L_8005FCB4:
    // 0x8005FCB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005FCB8: bne         $t2, $at, L_8005FCCC
    if (ctx->r10 != ctx->r1) {
        // 0x8005FCBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005FCCC;
    }
    // 0x8005FCBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005FCC0: bne         $s7, $at, L_8005FCCC
    if (ctx->r23 != ctx->r1) {
        // 0x8005FCC4: nop
    
            goto L_8005FCCC;
    }
    // 0x8005FCC4: nop

    // 0x8005FCC8: break       6
    do_break(2147876040);
L_8005FCCC:
    // 0x8005FCCC: mflo        $s2
    ctx->r18 = lo;
    // 0x8005FCD0: nop

    // 0x8005FCD4: nop

    // 0x8005FCD8: mfhi        $v0
    ctx->r2 = hi;
    // 0x8005FCDC: nop

    // 0x8005FCE0: nop

    // 0x8005FCE4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8005FCE8: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_8005FCEC:
    // 0x8005FCEC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8005FCF0: addiu       $s6, $s1, -0x1
    ctx->r22 = ADD32(ctx->r17, -0X1);
    // 0x8005FCF4: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x8005FCF8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005FCFC: lbu         $v0, -0x690($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X690);
    // 0x8005FD00: addu        $s5, $t2, $zero
    ctx->r21 = ADD32(ctx->r10, 0);
    // 0x8005FD04: beq         $v0, $zero, L_8005FD1C
    if (ctx->r2 == 0) {
        // 0x8005FD08: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8005FD1C;
    }
    // 0x8005FD08: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8005FD0C: sll         $s0, $a3, 2
    ctx->r16 = S32(ctx->r7 << 2);
    // 0x8005FD10: sll         $t8, $s6, 5
    ctx->r24 = S32(ctx->r22 << 5);
    // 0x8005FD14: j           L_8005FD28
    // 0x8005FD18: addiu       $s3, $zero, -0x400
    ctx->r19 = ADD32(0, -0X400);
        goto L_8005FD28;
    // 0x8005FD18: addiu       $s3, $zero, -0x400
    ctx->r19 = ADD32(0, -0X400);
L_8005FD1C:
    // 0x8005FD1C: sll         $s0, $a3, 2
    ctx->r16 = S32(ctx->r7 << 2);
    // 0x8005FD20: addu        $t8, $zero, $zero
    ctx->r24 = ADD32(0, 0);
    // 0x8005FD24: addiu       $s3, $zero, 0x400
    ctx->r19 = ADD32(0, 0X400);
L_8005FD28:
    // 0x8005FD28: sw          $s3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r19;
    // 0x8005FD2C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005FD30: lbu         $v0, -0x68F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X68F);
    // 0x8005FD34: beq         $v0, $zero, L_8005FD54
    if (ctx->r2 == 0) {
        // 0x8005FD38: addu        $v0, $t3, $s7
        ctx->r2 = ADD32(ctx->r11, ctx->r23);
            goto L_8005FD54;
    }
    // 0x8005FD38: addu        $v0, $t3, $s7
    ctx->r2 = ADD32(ctx->r11, ctx->r23);
    // 0x8005FD3C: subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // 0x8005FD40: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8005FD44: negu        $v0, $s5
    ctx->r2 = SUB32(0, ctx->r21);
    // 0x8005FD48: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8005FD4C: j           L_8005FD60
    // 0x8005FD50: addiu       $fp, $zero, -0x400
    ctx->r30 = ADD32(0, -0X400);
        goto L_8005FD60;
    // 0x8005FD50: addiu       $fp, $zero, -0x400
    ctx->r30 = ADD32(0, -0X400);
L_8005FD54:
    // 0x8005FD54: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x8005FD58: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x8005FD5C: addiu       $fp, $zero, 0x400
    ctx->r30 = ADD32(0, 0X400);
L_8005FD60:
    // 0x8005FD60: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x8005FD64: blez        $v0, L_800600D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005FD68: addu        $t6, $zero, $zero
        ctx->r14 = ADD32(0, 0);
            goto L_800600D0;
    }
    // 0x8005FD68: addu        $t6, $zero, $zero
    ctx->r14 = ADD32(0, 0);
    // 0x8005FD6C: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8005FD70: lbu         $s3, -0x68F($s3)
    ctx->r19 = MEM_BU(ctx->r19, -0X68F);
    // 0x8005FD74: sll         $v0, $s6, 1
    ctx->r2 = S32(ctx->r22 << 1);
    // 0x8005FD78: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8005FD7C: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8005FD80: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8005FD84: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8005FD88: sll         $v0, $s6, 2
    ctx->r2 = S32(ctx->r22 << 2);
    // 0x8005FD8C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8005FD90: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8005FD94: addu        $v1, $s0, $s1
    ctx->r3 = ADD32(ctx->r16, ctx->r17);
    // 0x8005FD98: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8005FD9C: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8005FDA0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005FDA4: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8005FDA8: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005FDAC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8005FDB0: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8005FDB4: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8005FDB8: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x8005FDBC: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005FDC0: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8005FDC4: addu        $t9, $fp, $zero
    ctx->r25 = ADD32(ctx->r30, 0);
    // 0x8005FDC8: sll         $t3, $t1, 16
    ctx->r11 = S32(ctx->r9 << 16);
    // 0x8005FDCC: addu        $t2, $t1, $t2
    ctx->r10 = ADD32(ctx->r9, ctx->r10);
    // 0x8005FDD0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8005FDD4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8005FDD8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
L_8005FDDC:
    // 0x8005FDDC: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8005FDE0: addu        $v0, $a2, $s5
    ctx->r2 = ADD32(ctx->r6, ctx->r21);
    // 0x8005FDE4: beq         $s3, $zero, L_8005FDF4
    if (ctx->r19 == 0) {
        // 0x8005FDE8: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_8005FDF4;
    }
    // 0x8005FDE8: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8005FDEC: j           L_8005FDF8
    // 0x8005FDF0: sll         $t5, $t0, 5
    ctx->r13 = S32(ctx->r8 << 5);
        goto L_8005FDF8;
    // 0x8005FDF0: sll         $t5, $t0, 5
    ctx->r13 = S32(ctx->r8 << 5);
L_8005FDF4:
    // 0x8005FDF4: sll         $t5, $a2, 5
    ctx->r13 = S32(ctx->r6 << 5);
L_8005FDF8:
    // 0x8005FDF8: slti        $v0, $t1, 0x3C0
    ctx->r2 = SIGNED(ctx->r9) < 0X3C0 ? 1 : 0;
    // 0x8005FDFC: beql        $v0, $zero, L_800600B0
    if (ctx->r2 == 0) {
        // 0x8005FE00: addiu       $a2, $t0, 0x1
        ctx->r6 = ADD32(ctx->r8, 0X1);
            goto L_800600B0;
    }
    goto skip_0;
    // 0x8005FE00: addiu       $a2, $t0, 0x1
    ctx->r6 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x8005FE04: blezl       $t2, L_800600B0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8005FE08: addiu       $a2, $t0, 0x1
        ctx->r6 = ADD32(ctx->r8, 0X1);
            goto L_800600B0;
    }
    goto skip_1;
    // 0x8005FE08: addiu       $a2, $t0, 0x1
    ctx->r6 = ADD32(ctx->r8, 0X1);
    skip_1:
    // 0x8005FE0C: lw          $s3, 0x4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4);
    // 0x8005FE10: beq         $s3, $zero, L_8005FE78
    if (ctx->r19 == 0) {
        // 0x8005FE14: lui         $s3, 0xE600
        ctx->r19 = S32(0XE600 << 16);
            goto L_8005FE78;
    }
    // 0x8005FE14: lui         $s3, 0xE600
    ctx->r19 = S32(0XE600 << 16);
    // 0x8005FE18: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005FE1C: lw          $v1, 0x3EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3EF0);
    // 0x8005FE20: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8005FE24: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FE28: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FE2C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8005FE30: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FE34: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FE38: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8005FE3C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8005FE40: sw          $s3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r19;
    // 0x8005FE44: lui         $s3, 0xF400
    ctx->r19 = S32(0XF400 << 16);
    // 0x8005FE48: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x8005FE4C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005FE50: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FE54: or          $v0, $s3, $v0
    ctx->r2 = ctx->r19 | ctx->r2;
    // 0x8005FE58: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8005FE5C: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8005FE60: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8005FE64: lui         $s3, 0x700
    ctx->r19 = S32(0X700 << 16);
    // 0x8005FE68: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x8005FE6C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005FE70: j           L_8005FED0
    // 0x8005FE74: or          $v0, $s3, $v0
    ctx->r2 = ctx->r19 | ctx->r2;
        goto L_8005FED0;
    // 0x8005FE74: or          $v0, $s3, $v0
    ctx->r2 = ctx->r19 | ctx->r2;
L_8005FE78:
    // 0x8005FE78: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005FE7C: lw          $v1, 0x3EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3EF0);
    // 0x8005FE80: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8005FE84: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FE88: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FE8C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8005FE90: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FE94: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FE98: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8005FE9C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8005FEA0: sw          $s3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r19;
    // 0x8005FEA4: lui         $s3, 0xF400
    ctx->r19 = S32(0XF400 << 16);
    // 0x8005FEA8: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x8005FEAC: or          $v0, $s4, $v0
    ctx->r2 = ctx->r20 | ctx->r2;
    // 0x8005FEB0: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8005FEB4: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8005FEB8: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8005FEBC: lui         $s3, 0x700
    ctx->r19 = S32(0X700 << 16);
    // 0x8005FEC0: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x8005FEC4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005FEC8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8005FECC: or          $v0, $s3, $v0
    ctx->r2 = ctx->r19 | ctx->r2;
L_8005FED0:
    // 0x8005FED0: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8005FED4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005FED8: lw          $a0, 0x3EF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3EF0);
    // 0x8005FEDC: lui         $v1, 0xF200
    ctx->r3 = S32(0XF200 << 16);
    // 0x8005FEE0: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8005FEE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FEE8: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FEEC: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8005FEF0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8005FEF4: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x8005FEF8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FEFC: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FF00: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8005FF04: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8005FF08: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005FF0C: or          $v0, $s4, $v0
    ctx->r2 = ctx->r20 | ctx->r2;
    // 0x8005FF10: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x8005FF14: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8005FF18: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8005FF1C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8005FF20: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8005FF24: addiu       $a1, $a0, 0x18
    ctx->r5 = ADD32(ctx->r4, 0X18);
    // 0x8005FF28: lui         $v1, 0xE400
    ctx->r3 = S32(0XE400 << 16);
    // 0x8005FF2C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FF30: sw          $a1, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r5;
    // 0x8005FF34: or          $v0, $s3, $v0
    ctx->r2 = ctx->r19 | ctx->r2;
    // 0x8005FF38: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x8005FF3C: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x8005FF40: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005FF44: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8005FF48: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005FF4C: and         $v0, $t2, $v0
    ctx->r2 = ctx->r10 & ctx->r2;
    // 0x8005FF50: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8005FF54: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005FF58: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8005FF5C: nor         $v1, $zero, $t4
    ctx->r3 = ~(0 | ctx->r12);
    // 0x8005FF60: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8005FF64: and         $v1, $s0, $v1
    ctx->r3 = ctx->r16 & ctx->r3;
    // 0x8005FF68: andi        $v1, $v1, 0xFFC
    ctx->r3 = ctx->r3 & 0XFFC;
    // 0x8005FF6C: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8005FF70: or          $v0, $s3, $v0
    ctx->r2 = ctx->r19 | ctx->r2;
    // 0x8005FF74: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x8005FF78: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8005FF7C: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8005FF80: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005FF84: and         $v0, $t1, $v0
    ctx->r2 = ctx->r9 & ctx->r2;
    // 0x8005FF88: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8005FF8C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005FF90: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
    // 0x8005FF94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FF98: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8005FF9C: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x8005FFA0: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    // 0x8005FFA4: bgez        $t4, L_80060004
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8005FFA8: sw          $v0, 0x18($a0)
        MEM_W(0X18, ctx->r4) = ctx->r2;
            goto L_80060004;
    }
    // 0x8005FFA8: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x8005FFAC: bgez        $a3, L_8005FFD4
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8005FFB0: nop
    
            goto L_8005FFD4;
    }
    // 0x8005FFB0: nop

    // 0x8005FFB4: mult        $t4, $a3
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005FFB8: mflo        $v0
    ctx->r2 = lo;
    // 0x8005FFBC: nop

    // 0x8005FFC0: nop

    // 0x8005FFC4: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8005FFC8: nor         $v1, $zero, $v0
    ctx->r3 = ~(0 | ctx->r2);
    // 0x8005FFCC: j           L_8005FFF4
    // 0x8005FFD0: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
        goto L_8005FFF4;
    // 0x8005FFD0: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
L_8005FFD4:
    // 0x8005FFD4: nop

    // 0x8005FFD8: mult        $t4, $a3
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005FFDC: mflo        $v0
    ctx->r2 = lo;
    // 0x8005FFE0: nop

    // 0x8005FFE4: nop

    // 0x8005FFE8: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8005FFEC: slti        $v1, $v0, 0x1
    ctx->r3 = SIGNED(ctx->r2) < 0X1 ? 1 : 0;
    // 0x8005FFF0: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_8005FFF4:
    // 0x8005FFF4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8005FFF8: subu        $v0, $t8, $v0
    ctx->r2 = SUB32(ctx->r24, ctx->r2);
    // 0x8005FFFC: j           L_80060008
    // 0x80060000: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
        goto L_80060008;
    // 0x80060000: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
L_80060004:
    // 0x80060004: sll         $a0, $t8, 16
    ctx->r4 = S32(ctx->r24 << 16);
L_80060008:
    // 0x80060008: bgez        $t1, L_80060074
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8006000C: andi        $v0, $t5, 0xFFFF
        ctx->r2 = ctx->r13 & 0XFFFF;
            goto L_80060074;
    }
    // 0x8006000C: andi        $v0, $t5, 0xFFFF
    ctx->r2 = ctx->r13 & 0XFFFF;
    // 0x80060010: bgez        $t9, L_80060048
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80060014: sra         $v0, $t3, 16
        ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
            goto L_80060048;
    }
    // 0x80060014: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80060018: nop

    // 0x8006001C: mult        $v0, $t9
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060020: mflo        $v0
    ctx->r2 = lo;
    // 0x80060024: nop

    // 0x80060028: nop

    // 0x8006002C: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80060030: nor         $v1, $zero, $v0
    ctx->r3 = ~(0 | ctx->r2);
    // 0x80060034: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x80060038: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006003C: subu        $v0, $t5, $v0
    ctx->r2 = SUB32(ctx->r13, ctx->r2);
    // 0x80060040: j           L_80060074
    // 0x80060044: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
        goto L_80060074;
    // 0x80060044: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80060048:
    // 0x80060048: nop

    // 0x8006004C: mult        $v0, $t9
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060050: mflo        $v0
    ctx->r2 = lo;
    // 0x80060054: nop

    // 0x80060058: nop

    // 0x8006005C: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80060060: slti        $v1, $v0, 0x1
    ctx->r3 = SIGNED(ctx->r2) < 0X1 ? 1 : 0;
    // 0x80060064: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80060068: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006006C: subu        $v0, $t5, $v0
    ctx->r2 = SUB32(ctx->r13, ctx->r2);
    // 0x80060070: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80060074:
    // 0x80060074: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x80060078: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8006007C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80060080: lw          $a0, 0x3EF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3EF0);
    // 0x80060084: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80060088: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006008C: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x80060090: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x80060094: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80060098: lw          $s3, 0xC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC);
    // 0x8006009C: andi        $v1, $fp, 0xFFFF
    ctx->r3 = ctx->r30 & 0XFFFF;
    // 0x800600A0: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x800600A4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800600A8: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x800600AC: addiu       $a2, $t0, 0x1
    ctx->r6 = ADD32(ctx->r8, 0X1);
L_800600B0:
    // 0x800600B0: sll         $v0, $t7, 16
    ctx->r2 = S32(ctx->r15 << 16);
    // 0x800600B4: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x800600B8: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x800600BC: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x800600C0: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x800600C4: slt         $v0, $t6, $v0
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800600C8: bne         $v0, $zero, L_8005FDDC
    if (ctx->r2 != 0) {
        // 0x800600CC: addu        $t1, $t1, $t7
        ctx->r9 = ADD32(ctx->r9, ctx->r15);
            goto L_8005FDDC;
    }
    // 0x800600CC: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
L_800600D0:
    // 0x800600D0: addiu       $t0, $s7, -0x1
    ctx->r8 = ADD32(ctx->r23, -0X1);
    // 0x800600D4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800600D8: lbu         $v1, -0x68F($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X68F);
    // 0x800600DC: subu        $v0, $s7, $a2
    ctx->r2 = SUB32(ctx->r23, ctx->r6);
    // 0x800600E0: beq         $v1, $zero, L_800600F0
    if (ctx->r3 == 0) {
        // 0x800600E4: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_800600F0;
    }
    // 0x800600E4: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800600E8: j           L_800600F4
    // 0x800600EC: sll         $t5, $t0, 5
    ctx->r13 = S32(ctx->r8 << 5);
        goto L_800600F4;
    // 0x800600EC: sll         $t5, $t0, 5
    ctx->r13 = S32(ctx->r8 << 5);
L_800600F0:
    // 0x800600F0: sll         $t5, $a2, 5
    ctx->r13 = S32(ctx->r6 << 5);
L_800600F4:
    // 0x800600F4: slti        $v0, $t1, 0x3C1
    ctx->r2 = SIGNED(ctx->r9) < 0X3C1 ? 1 : 0;
    // 0x800600F8: beq         $v0, $zero, L_800603C8
    if (ctx->r2 == 0) {
        // 0x800600FC: addu        $v0, $t1, $t2
        ctx->r2 = ADD32(ctx->r9, ctx->r10);
            goto L_800603C8;
    }
    // 0x800600FC: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80060100: blez        $v0, L_800603C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80060104: nop
    
            goto L_800603C8;
    }
    // 0x80060104: nop

    // 0x80060108: lw          $s3, 0x4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4);
    // 0x8006010C: beq         $s3, $zero, L_80060158
    if (ctx->r19 == 0) {
        // 0x80060110: lui         $v1, 0xF400
        ctx->r3 = S32(0XF400 << 16);
            goto L_80060158;
    }
    // 0x80060110: lui         $v1, 0xF400
    ctx->r3 = S32(0XF400 << 16);
    // 0x80060114: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80060118: lw          $a1, 0x3EF0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3EF0);
    // 0x8006011C: lui         $a0, 0x700
    ctx->r4 = S32(0X700 << 16);
    // 0x80060120: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80060124: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80060128: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x8006012C: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x80060130: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80060134: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80060138: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006013C: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x80060140: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x80060144: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80060148: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006014C: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x80060150: j           L_80060198
    // 0x80060154: sll         $v0, $s6, 1
    ctx->r2 = S32(ctx->r22 << 1);
        goto L_80060198;
    // 0x80060154: sll         $v0, $s6, 1
    ctx->r2 = S32(ctx->r22 << 1);
L_80060158:
    // 0x80060158: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8006015C: lw          $a1, 0x3EF0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3EF0);
    // 0x80060160: lui         $a0, 0x700
    ctx->r4 = S32(0X700 << 16);
    // 0x80060164: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80060168: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006016C: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x80060170: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x80060174: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80060178: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x8006017C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80060180: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x80060184: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x80060188: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8006018C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80060190: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x80060194: sll         $v0, $s6, 2
    ctx->r2 = S32(ctx->r22 << 2);
L_80060198:
    // 0x80060198: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8006019C: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x800601A0: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x800601A4: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800601A8: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x800601AC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800601B0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800601B4: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x800601B8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800601BC: lw          $a1, 0x3EF0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3EF0);
    // 0x800601C0: lui         $v1, 0xF200
    ctx->r3 = S32(0XF200 << 16);
    // 0x800601C4: addu        $a0, $s0, $s1
    ctx->r4 = ADD32(ctx->r16, ctx->r17);
    // 0x800601C8: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x800601CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800601D0: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x800601D4: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x800601D8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800601DC: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x800601E0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800601E4: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x800601E8: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x800601EC: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800601F0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800601F4: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x800601F8: sll         $v0, $s6, 2
    ctx->r2 = S32(ctx->r22 << 2);
    // 0x800601FC: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80060200: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80060204: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x80060208: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8006020C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80060210: addiu       $a2, $a1, 0x18
    ctx->r6 = ADD32(ctx->r5, 0X18);
    // 0x80060214: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x80060218: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8006021C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80060220: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x80060224: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80060228: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x8006022C: andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // 0x80060230: sll         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4 << 12);
    // 0x80060234: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80060238: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8006023C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80060240: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x80060244: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80060248: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8006024C: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80060250: lui         $v0, 0xE400
    ctx->r2 = S32(0XE400 << 16);
    // 0x80060254: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80060258: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8006025C: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x80060260: sw          $a0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r4;
    // 0x80060264: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80060268: nor         $v1, $zero, $a0
    ctx->r3 = ~(0 | ctx->r4);
    // 0x8006026C: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x80060270: and         $v1, $s0, $v1
    ctx->r3 = ctx->r16 & ctx->r3;
    // 0x80060274: andi        $v1, $v1, 0xFFC
    ctx->r3 = ctx->r3 & 0XFFC;
    // 0x80060278: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8006027C: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x80060280: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80060284: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x80060288: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8006028C: and         $v0, $t1, $v0
    ctx->r2 = ctx->r9 & ctx->r2;
    // 0x80060290: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80060294: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80060298: addiu       $v0, $a1, 0x20
    ctx->r2 = ADD32(ctx->r5, 0X20);
    // 0x8006029C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800602A0: sw          $a2, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r6;
    // 0x800602A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800602A8: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x800602AC: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x800602B0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800602B4: sw          $v1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r3;
    // 0x800602B8: bgez        $a0, L_8006031C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800602BC: sw          $v0, 0x18($a1)
        MEM_W(0X18, ctx->r5) = ctx->r2;
            goto L_8006031C;
    }
    // 0x800602BC: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // 0x800602C0: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
    // 0x800602C4: bgez        $v0, L_800602EC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800602C8: nop
    
            goto L_800602EC;
    }
    // 0x800602C8: nop

    // 0x800602CC: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800602D0: mflo        $v0
    ctx->r2 = lo;
    // 0x800602D4: nop

    // 0x800602D8: nop

    // 0x800602DC: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800602E0: nor         $v1, $zero, $v0
    ctx->r3 = ~(0 | ctx->r2);
    // 0x800602E4: j           L_8006030C
    // 0x800602E8: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
        goto L_8006030C;
    // 0x800602E8: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
L_800602EC:
    // 0x800602EC: nop

    // 0x800602F0: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800602F4: mflo        $v0
    ctx->r2 = lo;
    // 0x800602F8: nop

    // 0x800602FC: nop

    // 0x80060300: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80060304: slti        $v1, $v0, 0x1
    ctx->r3 = SIGNED(ctx->r2) < 0X1 ? 1 : 0;
    // 0x80060308: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_8006030C:
    // 0x8006030C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80060310: subu        $v0, $t8, $v0
    ctx->r2 = SUB32(ctx->r24, ctx->r2);
    // 0x80060314: j           L_80060320
    // 0x80060318: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
        goto L_80060320;
    // 0x80060318: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
L_8006031C:
    // 0x8006031C: sll         $a0, $t8, 16
    ctx->r4 = S32(ctx->r24 << 16);
L_80060320:
    // 0x80060320: bgez        $t1, L_80060390
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80060324: andi        $v0, $t5, 0xFFFF
        ctx->r2 = ctx->r13 & 0XFFFF;
            goto L_80060390;
    }
    // 0x80060324: andi        $v0, $t5, 0xFFFF
    ctx->r2 = ctx->r13 & 0XFFFF;
    // 0x80060328: addu        $v1, $fp, $zero
    ctx->r3 = ADD32(ctx->r30, 0);
    // 0x8006032C: bgez        $v1, L_80060364
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80060330: sll         $v0, $t1, 16
        ctx->r2 = S32(ctx->r9 << 16);
            goto L_80060364;
    }
    // 0x80060330: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x80060334: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80060338: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006033C: mflo        $v0
    ctx->r2 = lo;
    // 0x80060340: nop

    // 0x80060344: nop

    // 0x80060348: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8006034C: nor         $v1, $zero, $v0
    ctx->r3 = ~(0 | ctx->r2);
    // 0x80060350: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x80060354: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80060358: subu        $v0, $t5, $v0
    ctx->r2 = SUB32(ctx->r13, ctx->r2);
    // 0x8006035C: j           L_80060390
    // 0x80060360: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
        goto L_80060390;
    // 0x80060360: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80060364:
    // 0x80060364: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80060368: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006036C: mflo        $v0
    ctx->r2 = lo;
    // 0x80060370: nop

    // 0x80060374: nop

    // 0x80060378: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8006037C: slti        $v1, $v0, 0x1
    ctx->r3 = SIGNED(ctx->r2) < 0X1 ? 1 : 0;
    // 0x80060380: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80060384: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80060388: subu        $v0, $t5, $v0
    ctx->r2 = SUB32(ctx->r13, ctx->r2);
    // 0x8006038C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80060390:
    // 0x80060390: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x80060394: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80060398: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8006039C: lw          $a0, 0x3EF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3EF0);
    // 0x800603A0: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x800603A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800603A8: sw          $v0, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r2;
    // 0x800603AC: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x800603B0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800603B4: lw          $s3, 0xC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC);
    // 0x800603B8: andi        $v1, $fp, 0xFFFF
    ctx->r3 = ctx->r30 & 0XFFFF;
    // 0x800603BC: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x800603C0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800603C4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_800603C8:
    // 0x800603C8: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800603CC: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800603D0: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800603D4: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800603D8: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800603DC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800603E0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800603E4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800603E8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800603EC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800603F0: jr          $ra
    // 0x800603F4: nop

    return;
    // 0x800603F4: nop

    // 0x800603F8: nop

    // 0x800603FC: nop

;}
RECOMP_FUNC void func_80060400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060404: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80060408: lui         $s0, 0x11
    ctx->r16 = S32(0X11 << 16);
    // 0x8006040C: addiu       $s0, $s0, 0x1850
    ctx->r16 = ADD32(ctx->r16, 0X1850);
    // 0x80060410: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80060414: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80060418: addiu       $a2, $a2, 0x4728
    ctx->r6 = ADD32(ctx->r6, 0X4728);
    // 0x8006041C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060420: jal         0x80060D70
    // 0x80060424: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80060D70(rdram, ctx);
        goto after_0;
    // 0x80060424: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x80060428: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x8006042C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80060430: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80060434: addiu       $a2, $a2, -0x9E0
    ctx->r6 = ADD32(ctx->r6, -0X9E0);
    // 0x80060438: jal         0x80060D70
    // 0x8006043C: ori         $a1, $a1, 0x9A0
    ctx->r5 = ctx->r5 | 0X9A0;
    func_80060D70(rdram, ctx);
        goto after_1;
    // 0x8006043C: ori         $a1, $a1, 0x9A0
    ctx->r5 = ctx->r5 | 0X9A0;
    after_1:
    // 0x80060440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060444: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80060448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006044C: jr          $ra
    // 0x80060450: nop

    return;
    // 0x80060450: nop

;}
RECOMP_FUNC void func_80060454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060454: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80060458: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x8006045C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80060460: addiu       $v0, $v0, -0x9E0
    ctx->r2 = ADD32(ctx->r2, -0X9E0);
    // 0x80060464: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80060468: addu        $s2, $a1, $v0
    ctx->r18 = ADD32(ctx->r5, ctx->r2);
    // 0x8006046C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80060470: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80060474: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80060478: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8006047C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80060480: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80060484: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80060488: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8006048C: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x80060490: lw          $s1, 0x0($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X0);
    // FIX: On N64, address 0 maps to physical RDRAM 0 (valid memory).
    // The game uses RDRAM 0 as scratch space for first-time resource decompression.
    // In the recomp, address 0 isn't sign-extended so MEM_B/MEM_W produce wild pointers.
    // Map 0 → 0x80000000 which is rdram[0] in the recomp.
    if ((uint32_t)ctx->r17 == 0) {
        ctx->r17 = (gpr)(int32_t)0x80000000;
    }
    // 0x80060494: bne         $v0, $zero, L_800604AC
    if (ctx->r2 != 0) {
        // 0x80060498: nop
    
            goto L_800604AC;
    }
    // 0x80060498: nop

    // 0x8006049C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800604A0: lw          $v0, 0x6D58($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D58);
    // 0x800604A4: j           L_8006057C
    // 0x800604A8: nop

        goto L_8006057C;
    // 0x800604A8: nop

L_800604AC:
    // 0x800604AC: lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4);
    // 0x800604B0: addiu       $s4, $v0, -0x10
    ctx->r20 = ADD32(ctx->r2, -0X10);
    // 0x800604B4: jal         0x8005DFF0
    // 0x800604B8: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_8005DFF0(rdram, ctx);
        goto after_0;
    // 0x800604B8: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_0:
    // 0x800604BC: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x800604C0: addiu       $s5, $s5, 0x67A0
    ctx->r21 = ADD32(ctx->r21, 0X67A0);
    // 0x800604C4: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800604C8: beq         $s3, $zero, L_80060578
    if (ctx->r19 == 0) {
        // 0x800604CC: addu        $a2, $s5, $zero
        ctx->r6 = ADD32(ctx->r21, 0);
            goto L_80060578;
    }
    // 0x800604CC: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x800604D0: lui         $s0, 0xDFFF
    ctx->r16 = S32(0XDFFF << 16);
    // 0x800604D4: ori         $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 | 0XFFFF;
    // 0x800604D8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800604DC: lhu         $v0, 0x6($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X6);
    // 0x800604E0: lui         $a0, 0x11
    ctx->r4 = S32(0X11 << 16);
    // 0x800604E4: addiu       $a0, $a0, 0x1850
    ctx->r4 = ADD32(ctx->r4, 0X1850);
    // 0x800604E8: addiu       $a1, $zero, -0x2
    ctx->r5 = ADD32(0, -0X2);
    // 0x800604EC: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x800604F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800604F4: jal         0x80060D70
    // 0x800604F8: and         $a1, $v0, $a1
    ctx->r5 = ctx->r2 & ctx->r5;
    func_80060D70(rdram, ctx);
        goto after_1;
    // 0x800604F8: and         $a1, $v0, $a1
    ctx->r5 = ctx->r2 & ctx->r5;
    after_1:
    // 0x800604FC: lhu         $a2, 0x6($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X6);
    // 0x80060500: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80060504: jal         0x8005D328
    // 0x80060508: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8005D328(rdram, ctx);
        goto after_2;
    // 0x80060508: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8006050C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80060510: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80060514: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x80060518: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8006051C: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80060520: and         $a1, $a1, $s0
    ctx->r5 = ctx->r5 & ctx->r16;
    // 0x80060524: addu        $a1, $s1, $a1
    ctx->r5 = ADD32(ctx->r17, ctx->r5);
    // 0x80060528: srl         $v0, $v1, 16
    ctx->r2 = S32(U32(ctx->r3) >> 16);
    // 0x8006052C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80060530: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80060534: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80060538: srl         $v0, $a3, 16
    ctx->r2 = S32(U32(ctx->r7) >> 16);
    // 0x8006053C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80060540: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
    // 0x80060544: jal         0x800731EC
    // 0x80060548: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    func_800731EC(rdram, ctx);
        goto after_3;
    // 0x80060548: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    after_3:
    // 0x8006054C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80060550: and         $v0, $v0, $s0
    ctx->r2 = ctx->r2 & ctx->r16;
    // 0x80060554: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x80060558: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x8006055C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80060560: lui         $a0, 0x2000
    ctx->r4 = S32(0X2000 << 16);
    // 0x80060564: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x80060568: and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // 0x8006056C: or          $v1, $s3, $v1
    ctx->r3 = ctx->r19 | ctx->r3;
    // 0x80060570: j           L_8006057C
    // 0x80060574: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
        goto L_8006057C;
    // 0x80060574: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_80060578:
    // 0x80060578: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006057C:
    // 0x8006057C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80060580: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80060584: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80060588: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8006058C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80060590: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80060594: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80060598: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006059C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800605A0: jr          $ra
    // 0x800605A4: nop

    return;
    // 0x800605A4: nop

;}
