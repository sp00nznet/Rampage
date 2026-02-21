#include "recomp.h"
#include "funcs.h"
#include "sn64_rom_helpers.h"
#include <stdio.h>

RECOMP_FUNC void func_8006CDB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006CDB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006CDB4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006CDB8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006CDBC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CDC0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8006CDC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CDC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006CDCC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006CDD0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8006CDD4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8006CDD8: beq         $t7, $t9, L_8006CE14
    if (ctx->r15 == ctx->r25) {
        // 0x8006CDDC: nop
    
            goto L_8006CE14;
    }
    // 0x8006CDDC: nop

    // 0x8006CDE0: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x8006CDE4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8006CDE8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8006CDEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006CDF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006CDF4: jal         0x80070E0C
    // 0x8006CDF8: lbu         $a3, 0x0($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X0);
    __osPfsRWInode_recomp(rdram, ctx);
        goto after_0;
    // 0x8006CDF8: lbu         $a3, 0x0($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X0);
    after_0:
    // 0x8006CDFC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8006CE00: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CE04: beq         $t1, $zero, L_8006CE14
    if (ctx->r9 == 0) {
        // 0x8006CE08: nop
    
            goto L_8006CE14;
    }
    // 0x8006CE08: nop

    // 0x8006CE0C: b           L_8006CE9C
    // 0x8006CE10: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8006CE9C;
    // 0x8006CE10: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8006CE14:
    // 0x8006CE14: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CE18: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8006CE1C: lbu         $t4, 0x1($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X1);
    // 0x8006CE20: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8006CE24: addu        $t8, $t3, $t5
    ctx->r24 = ADD32(ctx->r11, ctx->r13);
    // 0x8006CE28: lhu         $at, 0x0($t8)
    ctx->r1 = MEM_HU(ctx->r24, 0X0);
    // 0x8006CE2C: sh          $at, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r1;
    // 0x8006CE30: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8006CE34: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CE38: lw          $t4, 0x60($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X60);
    // 0x8006CE3C: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
    // 0x8006CE40: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8006CE44: bne         $at, $zero, L_8006CE74
    if (ctx->r1 != 0) {
        // 0x8006CE48: nop
    
            goto L_8006CE74;
    }
    // 0x8006CE48: nop

    // 0x8006CE4C: lbu         $t3, 0x0($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X0);
    // 0x8006CE50: lbu         $t5, 0x64($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X64);
    // 0x8006CE54: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8006CE58: beq         $at, $zero, L_8006CE74
    if (ctx->r1 == 0) {
        // 0x8006CE5C: nop
    
            goto L_8006CE74;
    }
    // 0x8006CE5C: nop

    // 0x8006CE60: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x8006CE64: blez        $t7, L_8006CE74
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8006CE68: slti        $at, $t7, 0x80
        ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
            goto L_8006CE74;
    }
    // 0x8006CE68: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x8006CE6C: bne         $at, $zero, L_8006CE98
    if (ctx->r1 != 0) {
        // 0x8006CE70: nop
    
            goto L_8006CE98;
    }
    // 0x8006CE70: nop

L_8006CE74:
    // 0x8006CE74: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CE78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006CE7C: lhu         $t8, 0x0($t2)
    ctx->r24 = MEM_HU(ctx->r10, 0X0);
    // 0x8006CE80: bne         $t8, $at, L_8006CE90
    if (ctx->r24 != ctx->r1) {
        // 0x8006CE84: nop
    
            goto L_8006CE90;
    }
    // 0x8006CE84: nop

    // 0x8006CE88: b           L_8006CE9C
    // 0x8006CE8C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8006CE9C;
    // 0x8006CE8C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8006CE90:
    // 0x8006CE90: b           L_8006CE9C
    // 0x8006CE94: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8006CE9C;
    // 0x8006CE94: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8006CE98:
    // 0x8006CE98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006CE9C:
    // 0x8006CE9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CEA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006CEA4: jr          $ra
    // 0x8006CEA8: nop

    return;
    // 0x8006CEA8: nop

;}
RECOMP_FUNC void func_8006D9C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006D9C0: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8006D9C4: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x8006D9C8: subu        $v0, $v1, $t6
    ctx->r2 = SUB32(ctx->r3, ctx->r14);
    // 0x8006D9CC: beq         $v1, $v0, L_8006D9DC
    if (ctx->r3 == ctx->r2) {
        // 0x8006D9D0: addu        $t7, $a1, $v0
        ctx->r15 = ADD32(ctx->r5, ctx->r2);
            goto L_8006D9DC;
    }
    // 0x8006D9D0: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x8006D9D4: b           L_8006D9E0
    // 0x8006D9D8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_8006D9E0;
    // 0x8006D9D8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8006D9DC:
    // 0x8006D9DC: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_8006D9E0:
    // 0x8006D9E0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8006D9E4: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x8006D9E8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8006D9EC: jr          $ra
    // 0x8006D9F0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    return;
    // 0x8006D9F0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8006D9F4: nop

    // 0x8006D9F8: nop

    // 0x8006D9FC: nop

;}
RECOMP_FUNC void alHeapDBAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006DA00: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8006DA04: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006DA08: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006DA0C: multu       $a3, $t6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006DA10: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x8006DA14: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8006DA18: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x8006DA1C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8006DA20: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8006DA24: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006DA28: mflo        $v0
    ctx->r2 = lo;
    // 0x8006DA2C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x8006DA30: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x8006DA34: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x8006DA38: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x8006DA3C: bne         $at, $zero, L_8006DA4C
    if (ctx->r1 != 0) {
        // 0x8006DA40: addu        $t2, $a0, $t7
        ctx->r10 = ADD32(ctx->r4, ctx->r15);
            goto L_8006DA4C;
    }
    // 0x8006DA40: addu        $t2, $a0, $t7
    ctx->r10 = ADD32(ctx->r4, ctx->r15);
    // 0x8006DA44: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8006DA48: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
L_8006DA4C:
    // 0x8006DA4C: jr          $ra
    // 0x8006DA50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8006DA50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006DA54: nop

    // 0x8006DA58: nop

    // 0x8006DA5C: nop

;}
RECOMP_FUNC void func_8006E528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006E528: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006E52C: andi        $t7, $a2, 0x3
    ctx->r15 = ctx->r6 & 0X3;
    // 0x8006E530: beq         $t7, $zero, L_8006E54C
    if (ctx->r15 == 0) {
        // 0x8006E534: nop
    
            goto L_8006E54C;
    }
    // 0x8006E534: nop

L_8006E538:
    // 0x8006E538: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x8006E53C: lw          $a2, 0x10($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X10);
    // 0x8006E540: andi        $t9, $a2, 0x3
    ctx->r25 = ctx->r6 & 0X3;
    // 0x8006E544: bne         $t9, $zero, L_8006E538
    if (ctx->r25 != 0) {
        // 0x8006E548: nop
    
            goto L_8006E538;
    }
    // 0x8006E548: nop

L_8006E54C:
    // 0x8006E54C: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8006E550: lw          $t0, 0x308($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X308);
    // 0x8006E554: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x8006E558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006E55C: or          $t1, $t0, $a0
    ctx->r9 = ctx->r8 | ctx->r4;
    // 0x8006E560: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8006E564: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8006E568: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8006E56C: jr          $ra
    // 0x8006E570: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    return;
    // 0x8006E570: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8006E574: nop

    // 0x8006E578: nop

    // 0x8006E57C: nop

;}
// bzero_recomp: removed - HLE implementation in recomp_api.cpp takes priority
#if 0 // recompiled bzero - superseded by HLE
RECOMP_FUNC void bzero_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006E580: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x8006E584: bne         $at, $zero, L_8006E5FC
    if (ctx->r1 != 0) {
        // 0x8006E588: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_8006E5FC;
    }
    // 0x8006E588: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x8006E58C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8006E590: beq         $v1, $zero, L_8006E5A0
    if (ctx->r3 == 0) {
        // 0x8006E594: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_8006E5A0;
    }
    // 0x8006E594: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x8006E598: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x8006E59C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_8006E5A0:
    // 0x8006E5A0: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x8006E5A4: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x8006E5A8: beq         $a3, $zero, L_8006E5DC
    if (ctx->r7 == 0) {
        // 0x8006E5AC: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8006E5DC;
    }
    // 0x8006E5AC: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8006E5B0: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8006E5B4:
    // 0x8006E5B4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8006E5B8: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x8006E5BC: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x8006E5C0: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x8006E5C4: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x8006E5C8: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x8006E5CC: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x8006E5D0: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x8006E5D4: bne         $a0, $a3, L_8006E5B4
    if (ctx->r4 != ctx->r7) {
        // 0x8006E5D8: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_8006E5B4;
    }
    // 0x8006E5D8: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8006E5DC:
    // 0x8006E5DC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8006E5E0: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x8006E5E4: beq         $a3, $zero, L_8006E5FC
    if (ctx->r7 == 0) {
        // 0x8006E5E8: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8006E5FC;
    }
    // 0x8006E5E8: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8006E5EC: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8006E5F0:
    // 0x8006E5F0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8006E5F4: bne         $a0, $a3, L_8006E5F0
    if (ctx->r4 != ctx->r7) {
        // 0x8006E5F8: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_8006E5F0;
    }
    // 0x8006E5F8: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8006E5FC:
    // 0x8006E5FC: blez        $a1, L_8006E614
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8006E600: nop
    
            goto L_8006E614;
    }
    // 0x8006E600: nop

    // 0x8006E604: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_8006E608:
    // 0x8006E608: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006E60C: bne         $a0, $a1, L_8006E608
    if (ctx->r4 != ctx->r5) {
        // 0x8006E610: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_8006E608;
    }
    // 0x8006E610: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_8006E614:
    // 0x8006E614: jr          $ra
    // 0x8006E618: nop

    return;
    // 0x8006E618: nop

    // 0x8006E61C: nop

;}
#endif // recompiled bzero
RECOMP_FUNC void func_8006E668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006E668: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006E66C: beq         $a3, $zero, L_8006E698
    if (ctx->r7 == 0) {
        // 0x8006E670: nop
    
            goto L_8006E698;
    }
    // 0x8006E670: nop

L_8006E674:
    // 0x8006E674: bne         $a3, $a1, L_8006E688
    if (ctx->r7 != ctx->r5) {
        // 0x8006E678: nop
    
            goto L_8006E688;
    }
    // 0x8006E678: nop

    // 0x8006E67C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8006E680: b           L_8006E698
    // 0x8006E684: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
        goto L_8006E698;
    // 0x8006E684: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
L_8006E688:
    // 0x8006E688: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8006E68C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8006E690: bne         $a3, $zero, L_8006E674
    if (ctx->r7 != 0) {
        // 0x8006E694: nop
    
            goto L_8006E674;
    }
    // 0x8006E694: nop

L_8006E698:
    // 0x8006E698: jr          $ra
    // 0x8006E69C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006E69C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006E6A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006E6A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006E6AC: lui         $at, 0xB000
    ctx->r1 = S32(0XB000 << 16);
    // 0x8006E6B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E6B4: bne         $t6, $at, L_8006E6C8
    if (ctx->r14 != ctx->r1) {
        // 0x8006E6B8: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_8006E6C8;
    }
    // 0x8006E6B8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8006E6BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E6C0: b           L_8006E77C
    // 0x8006E6C4: addiu       $v0, $v0, 0x6460
    ctx->r2 = ADD32(ctx->r2, 0X6460);
        goto L_8006E77C;
    // 0x8006E6C4: addiu       $v0, $v0, 0x6460
    ctx->r2 = ADD32(ctx->r2, 0X6460);
L_8006E6C8:
    // 0x8006E6C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E6CC: sb          $zero, 0x6464($at)
    MEM_B(0X6464, ctx->r1) = 0;
    // 0x8006E6D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E6D4: lui         $t7, 0xB000
    ctx->r15 = S32(0XB000 << 16);
    // 0x8006E6D8: sw          $t7, 0x646C($at)
    MEM_W(0X646C, ctx->r1) = ctx->r15;
    // 0x8006E6DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006E6E0: jal         0x8006E520
    // 0x8006E6E4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    osPiRawReadIo_recomp(rdram, ctx);
        goto after_0;
    // 0x8006E6E4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8006E6E8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E6EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E6F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006E6F4: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8006E6F8: sb          $t9, 0x6465($at)
    MEM_B(0X6465, ctx->r1) = ctx->r25;
    // 0x8006E6FC: srl         $t0, $t8, 8
    ctx->r8 = S32(U32(ctx->r24) >> 8);
    // 0x8006E700: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8006E704: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E708: sb          $t1, 0x6468($at)
    MEM_B(0X6468, ctx->r1) = ctx->r9;
    // 0x8006E70C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E710: srl         $t2, $t8, 16
    ctx->r10 = S32(U32(ctx->r24) >> 16);
    // 0x8006E714: srl         $t4, $t8, 20
    ctx->r12 = S32(U32(ctx->r24) >> 20);
    // 0x8006E718: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x8006E71C: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x8006E720: sb          $t3, 0x6466($at)
    MEM_B(0X6466, ctx->r1) = ctx->r11;
    // 0x8006E724: sb          $t5, 0x6467($at)
    MEM_B(0X6467, ctx->r1) = ctx->r13;
    // 0x8006E728: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E72C: addiu       $a0, $a0, 0x6460
    ctx->r4 = ADD32(ctx->r4, 0X6460);
    // 0x8006E730: sb          $zero, 0x6469($at)
    MEM_B(0X6469, ctx->r1) = 0;
    // 0x8006E734: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x8006E738: jal         0x8006E580
    // 0x8006E73C: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    bzero_recomp(rdram, ctx);
        goto after_1;
    // 0x8006E73C: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_1:
    // 0x8006E740: jal         0x8006E620
    // 0x8006E744: nop

    __osDisableInt_recomp(rdram, ctx);
        goto after_2;
    // 0x8006E744: nop

    after_2:
    // 0x8006E748: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8006E74C: lw          $t6, 0x5D6C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5D6C);
    // 0x8006E750: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E754: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8006E758: sw          $t6, 0x6460($at)
    MEM_W(0X6460, ctx->r1) = ctx->r14;
    // 0x8006E75C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8006E760: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8006E764: addiu       $t7, $t7, 0x6460
    ctx->r15 = ADD32(ctx->r15, 0X6460);
    // 0x8006E768: sw          $t7, 0x5D6C($at)
    MEM_W(0X5D6C, ctx->r1) = ctx->r15;
    // 0x8006E76C: jal         0x8006E640
    // 0x8006E770: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_3;
    // 0x8006E770: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8006E774: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E778: addiu       $v0, $v0, 0x6460
    ctx->r2 = ADD32(ctx->r2, 0X6460);
L_8006E77C:
    // 0x8006E77C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E780: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006E784: jr          $ra
    // 0x8006E788: nop

    return;
    // 0x8006E788: nop

    // 0x8006E78C: nop

;}
RECOMP_FUNC void func_8006E790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006E790: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8006E794: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E798: sb          $t6, 0x64E4($at)
    MEM_B(0X64E4, ctx->r1) = ctx->r14;
    // 0x8006E79C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E7A0: lui         $t7, 0xA500
    ctx->r15 = S32(0XA500 << 16);
    // 0x8006E7A4: sw          $t7, 0x64EC($at)
    MEM_W(0X64EC, ctx->r1) = ctx->r15;
    // 0x8006E7A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E7AC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8006E7B0: sb          $t8, 0x64E5($at)
    MEM_B(0X64E5, ctx->r1) = ctx->r24;
    // 0x8006E7B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E7B8: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8006E7BC: sb          $t9, 0x64E8($at)
    MEM_B(0X64E8, ctx->r1) = ctx->r25;
    // 0x8006E7C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E7C4: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8006E7C8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8006E7CC: sb          $t0, 0x64E6($at)
    MEM_B(0X64E6, ctx->r1) = ctx->r8;
    // 0x8006E7D0: sb          $t1, 0x64E7($at)
    MEM_B(0X64E7, ctx->r1) = ctx->r9;
    ctx->hi = hi; ctx->lo = lo;
    func_8006E7D4(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_8006E7D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006E7D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006E7D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E7DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8006E7E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E7E4: sb          $t2, 0x64E9($at)
    MEM_B(0X64E9, ctx->r1) = ctx->r10;
    // 0x8006E7E8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8006E7EC: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x8006E7F0: sw          $t3, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r11;
    // 0x8006E7F4: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8006E7F8: lbu         $t5, 0x64E8($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X64E8);
    // 0x8006E7FC: lui         $t6, 0xA460
    ctx->r14 = S32(0XA460 << 16);
    // 0x8006E800: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8006E804: sw          $t5, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r13;
    // 0x8006E808: lbu         $t7, 0x64E6($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X64E6);
    // 0x8006E80C: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x8006E810: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8006E814: sw          $t7, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r15;
    // 0x8006E818: lbu         $t9, 0x64E7($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X64E7);
    // 0x8006E81C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006E820: lui         $t0, 0xA460
    ctx->r8 = S32(0XA460 << 16);
    // 0x8006E824: addiu       $a0, $a0, 0x64E0
    ctx->r4 = ADD32(ctx->r4, 0X64E0);
    // 0x8006E828: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x8006E82C: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x8006E830: jal         0x8006E580
    // 0x8006E834: sw          $t9, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r25;
    bzero_recomp(rdram, ctx);
        goto after_0;
    // 0x8006E834: sw          $t9, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r25;
    after_0:
    // 0x8006E838: jal         0x8006E620
    // 0x8006E83C: nop

    __osDisableInt_recomp(rdram, ctx);
        goto after_1;
    // 0x8006E83C: nop

    after_1:
    // 0x8006E840: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8006E844: lw          $t1, 0x5D6C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5D6C);
    // 0x8006E848: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E84C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8006E850: sw          $t1, 0x64E0($at)
    MEM_W(0X64E0, ctx->r1) = ctx->r9;
    // 0x8006E854: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8006E858: addiu       $t2, $t2, 0x64E0
    ctx->r10 = ADD32(ctx->r10, 0X64E0);
    // 0x8006E85C: sw          $t2, 0x5D6C($at)
    MEM_W(0X5D6C, ctx->r1) = ctx->r10;
    // 0x8006E860: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8006E864: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006E868: sw          $t2, 0x6554($at)
    MEM_W(0X6554, ctx->r1) = ctx->r10;
    // 0x8006E86C: jal         0x8006E640
    // 0x8006E870: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_2;
    // 0x8006E870: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8006E874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E878: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E87C: addiu       $v0, $v0, 0x64E0
    ctx->r2 = ADD32(ctx->r2, 0X64E0);
    // 0x8006E880: jr          $ra
    // 0x8006E884: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006E884: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006E888: nop

    // 0x8006E88C: nop

;}
RECOMP_FUNC void func_8006E8E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006E8E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006E8EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E8F0: bne         $t6, $zero, L_8006E900
    if (ctx->r14 != 0) {
        // 0x8006E8F4: nop
    
            goto L_8006E900;
    }
    // 0x8006E8F4: nop

    // 0x8006E8F8: jal         0x8006E890
    // 0x8006E8FC: nop

    __osPiCreateAccessQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8006E8FC: nop

    after_0:
L_8006E900:
    // 0x8006E900: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006E904: addiu       $a0, $a0, 0x6568
    ctx->r4 = ADD32(ctx->r4, 0X6568);
    // 0x8006E908: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8006E90C: jal         0x80069CF0
    // 0x8006E910: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8006E910: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8006E914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E918: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006E91C: jr          $ra
    // 0x8006E920: nop

    return;
    // 0x8006E920: nop

;}
RECOMP_FUNC void func_8006E924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006E924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E92C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006E930: addiu       $a0, $a0, 0x6568
    ctx->r4 = ADD32(ctx->r4, 0X6568);
    // 0x8006E934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006E938: jal         0x8006A090
    // 0x8006E93C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8006E93C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8006E940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E948: jr          $ra
    // 0x8006E94C: nop

    return;
    // 0x8006E94C: nop

;}
RECOMP_FUNC void func_8006F3D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006F3D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006F3DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F3E0: bne         $t6, $zero, L_8006F3F0
    if (ctx->r14 != 0) {
        // 0x8006F3E4: nop
    
            goto L_8006F3F0;
    }
    // 0x8006F3E4: nop

    // 0x8006F3E8: jal         0x8006F380
    // 0x8006F3EC: nop

    __osSiCreateAccessQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8006F3EC: nop

    after_0:
L_8006F3F0:
    // 0x8006F3F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006F3F4: addiu       $a0, $a0, 0x6588
    ctx->r4 = ADD32(ctx->r4, 0X6588);
    // 0x8006F3F8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8006F3FC: jal         0x80069CF0
    // 0x8006F400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8006F400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8006F404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F408: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006F40C: jr          $ra
    // 0x8006F410: nop

    return;
    // 0x8006F410: nop

;}
RECOMP_FUNC void func_8006F440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006F440: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006F444: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8006F448: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8006F44C: sw          $t7, 0x65C4($at)
    MEM_W(0X65C4, ctx->r1) = ctx->r15;
    // 0x8006F450: sw          $t6, 0x65C0($at)
    MEM_W(0X65C0, ctx->r1) = ctx->r14;
    // 0x8006F454: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006F458: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8006F45C: lw          $t8, 0x6B40($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6B40);
    // 0x8006F460: sw          $zero, 0x65C8($at)
    MEM_W(0X65C8, ctx->r1) = 0;
    // 0x8006F464: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006F468: sw          $zero, 0x65CC($at)
    MEM_W(0X65CC, ctx->r1) = 0;
    // 0x8006F46C: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8006F470: sw          $t8, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r24;
    // 0x8006F474: lw          $t9, 0x6B40($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6B40);
    // 0x8006F478: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8006F47C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8006F480: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8006F484: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8006F488: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8006F48C: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x8006F490: lw          $t1, 0x6B40($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6B40);
    // 0x8006F494: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8006F498: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8006F49C: sw          $t2, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r10;
    // 0x8006F4A0: sw          $t3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r11;
    // 0x8006F4A4: lw          $t4, 0x6B40($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6B40);
    // 0x8006F4A8: lw          $t6, 0x10($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10);
    // 0x8006F4AC: lw          $t7, 0x14($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X14);
    // 0x8006F4B0: sw          $t6, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r14;
    // 0x8006F4B4: sw          $t7, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r15;
    // 0x8006F4B8: lw          $t5, 0x6B40($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6B40);
    // 0x8006F4BC: sw          $zero, 0x18($t5)
    MEM_W(0X18, ctx->r13) = 0;
    // 0x8006F4C0: lw          $t8, 0x6B40($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6B40);
    // 0x8006F4C4: jr          $ra
    // 0x8006F4C8: sw          $zero, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = 0;
    return;
    // 0x8006F4C8: sw          $zero, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = 0;
;}
RECOMP_FUNC void func_8006F4CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006F4CC: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8006F4D0: lw          $t6, 0x6B40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6B40);
    ctx->hi = hi; ctx->lo = lo;
    func_8006F4D4(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_8006F4D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006F4D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006F4D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F4DC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8006F4E0: beq         $t7, $t6, L_8006F634
    if (ctx->r15 == ctx->r14) {
        // 0x8006F4E4: nop
    
            goto L_8006F634;
    }
    // 0x8006F4E4: nop

L_8006F4E8:
    // 0x8006F4E8: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8006F4EC: lw          $t8, 0x6B40($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6B40);
    // 0x8006F4F0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8006F4F4: bne         $t9, $t8, L_8006F510
    if (ctx->r25 != ctx->r24) {
        // 0x8006F4F8: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_8006F510;
    }
    // 0x8006F4F8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8006F4FC: jal         0x80072EE0
    // 0x8006F500: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    __osSetCompare_recomp(rdram, ctx);
        goto after_0;
    // 0x8006F500: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8006F504: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006F508: b           L_8006F634
    // 0x8006F50C: sw          $zero, 0x65D0($at)
    MEM_W(0X65D0, ctx->r1) = 0;
        goto L_8006F634;
    // 0x8006F50C: sw          $zero, 0x65D0($at)
    MEM_W(0X65D0, ctx->r1) = 0;
L_8006F510:
    // 0x8006F510: jal         0x8006FCF0
    // 0x8006F514: nop

    osGetCount_recomp(rdram, ctx);
        goto after_1;
    // 0x8006F514: nop

    after_1:
    // 0x8006F518: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8006F51C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8006F520: lw          $t1, 0x65D0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X65D0);
    // 0x8006F524: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006F528: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8006F52C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006F530: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x8006F534: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8006F538: sw          $t0, 0x65D0($at)
    MEM_W(0X65D0, ctx->r1) = ctx->r8;
    // 0x8006F53C: lw          $t6, 0x10($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X10);
    // 0x8006F540: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F544: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8006F548: or          $t9, $t7, $zero
    ctx->r25 = ctx->r15 | 0;
    // 0x8006F54C: sltu        $at, $t6, $t4
    ctx->r1 = ctx->r14 < ctx->r12 ? 1 : 0;
    // 0x8006F550: lw          $t7, 0x14($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X14);
    // 0x8006F554: bne         $at, $zero, L_8006F5B0
    if (ctx->r1 != 0) {
        // 0x8006F558: or          $t5, $t3, $zero
        ctx->r13 = ctx->r11 | 0;
            goto L_8006F5B0;
    }
    // 0x8006F558: or          $t5, $t3, $zero
    ctx->r13 = ctx->r11 | 0;
    // 0x8006F55C: sltu        $at, $t4, $t6
    ctx->r1 = ctx->r12 < ctx->r14 ? 1 : 0;
    // 0x8006F560: bne         $at, $zero, L_8006F570
    if (ctx->r1 != 0) {
        // 0x8006F564: sltu        $at, $t5, $t7
        ctx->r1 = ctx->r13 < ctx->r15 ? 1 : 0;
            goto L_8006F570;
    }
    // 0x8006F564: sltu        $at, $t5, $t7
    ctx->r1 = ctx->r13 < ctx->r15 ? 1 : 0;
    // 0x8006F568: beq         $at, $zero, L_8006F5B0
    if (ctx->r1 == 0) {
        // 0x8006F56C: nop
    
            goto L_8006F5B0;
    }
    // 0x8006F56C: nop

L_8006F570:
    // 0x8006F570: addiu       $t8, $t9, 0x10
    ctx->r24 = ADD32(ctx->r25, 0X10);
    // 0x8006F574: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8006F578: lw          $t3, 0x14($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X14);
    // 0x8006F57C: lw          $t2, 0x10($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X10);
    // 0x8006F580: sltu        $at, $t3, $t5
    ctx->r1 = ctx->r11 < ctx->r13 ? 1 : 0;
    // 0x8006F584: subu        $t0, $t2, $t4
    ctx->r8 = SUB32(ctx->r10, ctx->r12);
    // 0x8006F588: subu        $t0, $t0, $at
    ctx->r8 = SUB32(ctx->r8, ctx->r1);
    // 0x8006F58C: subu        $t1, $t3, $t5
    ctx->r9 = SUB32(ctx->r11, ctx->r13);
    // 0x8006F590: sw          $t1, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r9;
    // 0x8006F594: sw          $t0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r8;
    // 0x8006F598: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8006F59C: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    // 0x8006F5A0: jal         0x8006F644
    // 0x8006F5A4: lw          $a1, 0x14($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X14);
    __osSetTimerIntr_recomp(rdram, ctx);
        goto after_2;
    // 0x8006F5A4: lw          $a1, 0x14($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X14);
    after_2:
    // 0x8006F5A8: b           L_8006F634
    // 0x8006F5AC: nop

        goto L_8006F634;
    // 0x8006F5AC: nop

L_8006F5B0:
    // 0x8006F5B0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8006F5B4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8006F5B8: lw          $t2, 0x4($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X4);
    // 0x8006F5BC: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8006F5C0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8006F5C4: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8006F5C8: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8006F5CC: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8006F5D0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8006F5D4: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8006F5D8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8006F5DC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8006F5E0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8006F5E4: lw          $t6, 0x18($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X18);
    // 0x8006F5E8: beq         $t6, $zero, L_8006F600
    if (ctx->r14 == 0) {
        // 0x8006F5EC: nop
    
            goto L_8006F600;
    }
    // 0x8006F5EC: nop

    // 0x8006F5F0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8006F5F4: lw          $a1, 0x1C($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X1C);
    // 0x8006F5F8: jal         0x8006A090
    // 0x8006F5FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8006F5FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_8006F600:
    // 0x8006F600: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8006F604: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8006F608: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x8006F60C: bne         $t8, $zero, L_8006F61C
    if (ctx->r24 != 0) {
        // 0x8006F610: nop
    
            goto L_8006F61C;
    }
    // 0x8006F610: nop

    // 0x8006F614: beq         $t9, $zero, L_8006F4E8
    if (ctx->r25 == 0) {
        // 0x8006F618: nop
    
            goto L_8006F4E8;
    }
    // 0x8006F618: nop

L_8006F61C:
    // 0x8006F61C: sw          $t8, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r24;
    // 0x8006F620: sw          $t9, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r25;
    // 0x8006F624: jal         0x8006F6B8
    // 0x8006F628: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    __osInsertTimer_recomp(rdram, ctx);
        goto after_4;
    // 0x8006F628: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x8006F62C: b           L_8006F4E8
    // 0x8006F630: nop

        goto L_8006F4E8;
    // 0x8006F630: nop

L_8006F634:
    // 0x8006F634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F638: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006F63C: jr          $ra
    // 0x8006F640: nop

    return;
    // 0x8006F640: nop

;}
RECOMP_FUNC void func_8006F980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006F980: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8006F984: jr          $ra
    // 0x8006F988: lw          $v0, 0x6BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6BB0);
    return;
    // 0x8006F988: lw          $v0, 0x6BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6BB0);
    // 0x8006F98C: nop

;}
RECOMP_FUNC void func_800700B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800700B8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800700BC: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x800700C0: bne         $t7, $zero, L_800700D0
    if (ctx->r15 != 0) {
        // 0x800700C4: nop
    
            goto L_800700D0;
    }
    // 0x800700C4: nop

    // 0x800700C8: b           L_800700DC
    // 0x800700CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800700DC;
    // 0x800700CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800700D0:
    // 0x800700D0: lui         $t8, 0xA408
    ctx->r24 = S32(0XA408 << 16);
    // 0x800700D4: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x800700D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800700DC:
    // 0x800700DC: jr          $ra
    // 0x800700E0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800700E0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800700E4: nop

    // 0x800700E8: nop

    // 0x800700EC: nop

;}
RECOMP_FUNC void func_80070188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80070188: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007018C: andi        $t7, $a0, 0x1C
    ctx->r15 = ctx->r4 & 0X1C;
    // 0x80070190: beq         $t7, $zero, L_800701A0
    if (ctx->r15 == 0) {
        // 0x80070194: nop
    
            goto L_800701A0;
    }
    // 0x80070194: nop

    // 0x80070198: b           L_800701A4
    // 0x8007019C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800701A4;
    // 0x8007019C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800701A0:
    // 0x800701A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800701A4:
    // 0x800701A4: jr          $ra
    // 0x800701A8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800701A8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800701AC: nop

;}
RECOMP_FUNC void MusPtrBankGetCurrent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80070318: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8007031C: lw          $v0, 0x5D58($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5D58);
    // 0x80070320: jr          $ra
    // 0x80070324: nop

    return;
    // 0x80070324: nop

    // 0x80070328: nop

    // 0x8007032C: nop

;}
RECOMP_FUNC void __osSumcalc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80070440: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80070444: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x80070448: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x8007044C: blez        $a1, L_80070490
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80070450: sw          $zero, 0xC($sp)
        MEM_W(0XC, ctx->r29) = 0;
            goto L_80070490;
    }
    // 0x80070450: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_80070454:
    // 0x80070454: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80070458: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8007045C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x80070460: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80070464: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x80070468: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007046C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80070470: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80070474: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80070478: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007047C: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x80070480: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80070484: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x80070488: bne         $at, $zero, L_80070454
    if (ctx->r1 != 0) {
        // 0x8007048C: sw          $t2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r10;
            goto L_80070454;
    }
    // 0x8007048C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_80070490:
    // 0x80070490: lhu         $v0, 0xA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XA);
    // 0x80070494: jr          $ra
    // 0x80070498: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80070498: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void __osIdCheckSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8007049C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800704A0: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x800704A4: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x800704A8: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x800704AC: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800704B0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800704B4:
    // 0x800704B4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800704B8: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800704BC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800704C0: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x800704C4: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x800704C8: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x800704CC: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x800704D0: lhu         $t3, 0x6($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6);
    // 0x800704D4: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x800704D8: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x800704DC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800704E0: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // 0x800704E4: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800704E8: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800704EC: sltiu       $at, $t7, 0x1C
    ctx->r1 = ctx->r15 < 0X1C ? 1 : 0;
    // 0x800704F0: bne         $at, $zero, L_800704B4
    if (ctx->r1 != 0) {
        // 0x800704F4: sw          $t7, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r15;
            goto L_800704B4;
    }
    // 0x800704F4: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x800704F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800704FC: jr          $ra
    // 0x80070500: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80070500: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800713BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800713BC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800713C0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800713C4: addiu       $t6, $t6, 0x6420
    ctx->r14 = ADD32(ctx->r14, 0X6420);
    // 0x800713C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800713CC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800713D0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800713D4: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x800713D8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800713DC:
    // 0x800713DC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800713E0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800713E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800713E8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800713EC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800713F0: sw          $zero, 0x6420($at)
    MEM_W(0X6420, ctx->r1) = 0;
    // 0x800713F4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800713F8: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800713FC: bne         $at, $zero, L_800713DC
    if (ctx->r1 != 0) {
        // 0x80071400: sw          $t0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r8;
            goto L_800713DC;
    }
    // 0x80071400: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80071404: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80071408: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8007140C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80071410: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80071414: addiu       $t4, $zero, 0x21
    ctx->r12 = ADD32(0, 0X21);
    // 0x80071418: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8007141C: sw          $t1, 0x645C($at)
    MEM_W(0X645C, ctx->r1) = ctx->r9;
    // 0x80071420: sb          $t2, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r10;
    // 0x80071424: sb          $t3, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r11;
    // 0x80071428: sb          $t4, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r12;
    // 0x8007142C: sb          $t5, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r13;
    // 0x80071430: jal         0x80071F90
    // 0x80071434: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    __osContAddressCrc_recomp(rdram, ctx);
        goto after_0;
    // 0x80071434: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    after_0:
    // 0x80071438: lhu         $t6, 0x4E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4E);
    // 0x8007143C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80071440: sb          $t9, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r25;
    // 0x80071444: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80071448: or          $t8, $v0, $t7
    ctx->r24 = ctx->r2 | ctx->r15;
    // 0x8007144C: sh          $t8, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r24;
    // 0x80071450: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80071454:
    // 0x80071454: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80071458: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8007145C: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x80071460: sb          $t0, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r8;
    // 0x80071464: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80071468: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007146C: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x80071470: bne         $at, $zero, L_80071454
    if (ctx->r1 != 0) {
        // 0x80071474: sw          $t4, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r12;
            goto L_80071454;
    }
    // 0x80071474: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80071478: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8007147C: beq         $t5, $zero, L_800714B8
    if (ctx->r13 == 0) {
        // 0x80071480: nop
    
            goto L_800714B8;
    }
    // 0x80071480: nop

    // 0x80071484: blez        $t5, L_800714B8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80071488: sw          $zero, 0x18($sp)
        MEM_W(0X18, ctx->r29) = 0;
            goto L_800714B8;
    }
    // 0x80071488: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8007148C:
    // 0x8007148C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80071490: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80071494: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80071498: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8007149C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800714A0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800714A4: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800714A8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800714AC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800714B0: bne         $at, $zero, L_8007148C
    if (ctx->r1 != 0) {
        // 0x800714B4: sw          $t8, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r24;
            goto L_8007148C;
    }
    // 0x800714B4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_800714B8:
    // 0x800714B8: addiu       $t3, $sp, 0x1C
    ctx->r11 = ADD32(ctx->r29, 0X1C);
    // 0x800714BC: addiu       $t5, $t3, 0x24
    ctx->r13 = ADD32(ctx->r11, 0X24);
    // 0x800714C0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_800714C4:
    // 0x800714C4: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x800714C8: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x800714CC: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x800714D0: swl         $at, -0xC($t2)
    do_swl(rdram, -0XC, ctx->r10, ctx->r1);
    // 0x800714D4: swr         $at, -0x9($t2)
    do_swr(rdram, -0X9, ctx->r10, ctx->r1);
    // 0x800714D8: lw          $at, -0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X8);
    // 0x800714DC: swl         $at, -0x8($t2)
    do_swl(rdram, -0X8, ctx->r10, ctx->r1);
    // 0x800714E0: swr         $at, -0x5($t2)
    do_swr(rdram, -0X5, ctx->r10, ctx->r1);
    // 0x800714E4: lw          $at, -0x4($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X4);
    // 0x800714E8: swl         $at, -0x4($t2)
    do_swl(rdram, -0X4, ctx->r10, ctx->r1);
    // 0x800714EC: bne         $t3, $t5, L_800714C4
    if (ctx->r11 != ctx->r13) {
        // 0x800714F0: swr         $at, -0x1($t2)
        do_swr(rdram, -0X1, ctx->r10, ctx->r1);
            goto L_800714C4;
    }
    // 0x800714F0: swr         $at, -0x1($t2)
    do_swr(rdram, -0X1, ctx->r10, ctx->r1);
    // 0x800714F4: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x800714F8: addiu       $t8, $zero, 0xFE
    ctx->r24 = ADD32(0, 0XFE);
    // 0x800714FC: swl         $at, 0x0($t2)
    do_swl(rdram, 0X0, ctx->r10, ctx->r1);
    // 0x80071500: swr         $at, 0x3($t2)
    do_swr(rdram, 0X3, ctx->r10, ctx->r1);
    // 0x80071504: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80071508: addiu       $t7, $t6, 0x28
    ctx->r15 = ADD32(ctx->r14, 0X28);
    // 0x8007150C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80071510: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x80071514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071518: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8007151C: jr          $ra
    // 0x80071520: nop

    return;
    // 0x80071520: nop

    // 0x80071524: nop

    // 0x80071528: nop

    // 0x8007152C: nop

;}
RECOMP_FUNC void func_80072314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80072314: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80072318: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8007231C: addiu       $t6, $t6, 0x6420
    ctx->r14 = ADD32(ctx->r14, 0X6420);
    // 0x80072320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072324: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80072328: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8007232C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80072330: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80072334: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80072338:
    // 0x80072338: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8007233C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80072340: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80072344: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80072348: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8007234C: sw          $zero, 0x6420($at)
    MEM_W(0X6420, ctx->r1) = 0;
    // 0x80072350: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80072354: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x80072358: bne         $at, $zero, L_80072338
    if (ctx->r1 != 0) {
        // 0x8007235C: sw          $t0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r8;
            goto L_80072338;
    }
    // 0x8007235C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80072360: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80072364: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80072368: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8007236C: addiu       $t3, $zero, 0x23
    ctx->r11 = ADD32(0, 0X23);
    // 0x80072370: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80072374: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80072378: sw          $t1, 0x645C($at)
    MEM_W(0X645C, ctx->r1) = ctx->r9;
    // 0x8007237C: sb          $t2, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r10;
    // 0x80072380: sb          $t3, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r11;
    // 0x80072384: sb          $t4, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r12;
    // 0x80072388: sb          $t5, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r13;
    // 0x8007238C: jal         0x80071F90
    // 0x80072390: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    __osContAddressCrc_recomp(rdram, ctx);
        goto after_0;
    // 0x80072390: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    after_0:
    // 0x80072394: lhu         $t6, 0x4E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4E);
    // 0x80072398: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8007239C: sb          $t9, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r25;
    // 0x800723A0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800723A4: or          $t8, $v0, $t7
    ctx->r24 = ctx->r2 | ctx->r15;
    // 0x800723A8: sh          $t8, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r24;
    // 0x800723AC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800723B0:
    // 0x800723B0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800723B4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800723B8: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x800723BC: addu        $t3, $sp, $t2
    ctx->r11 = ADD32(ctx->r29, ctx->r10);
    // 0x800723C0: sb          $t1, 0x22($t3)
    MEM_B(0X22, ctx->r11) = ctx->r9;
    // 0x800723C4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800723C8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800723CC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800723D0: slti        $at, $t7, 0x20
    ctx->r1 = SIGNED(ctx->r15) < 0X20 ? 1 : 0;
    // 0x800723D4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800723D8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800723DC: bne         $at, $zero, L_800723B0
    if (ctx->r1 != 0) {
        // 0x800723E0: sw          $t5, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r13;
            goto L_800723B0;
    }
    // 0x800723E0: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x800723E4: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800723E8: beq         $t8, $zero, L_80072424
    if (ctx->r24 == 0) {
        // 0x800723EC: nop
    
            goto L_80072424;
    }
    // 0x800723EC: nop

    // 0x800723F0: blez        $t8, L_80072424
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800723F4: sw          $zero, 0x18($sp)
        MEM_W(0X18, ctx->r29) = 0;
            goto L_80072424;
    }
    // 0x800723F4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800723F8:
    // 0x800723F8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800723FC: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x80072400: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80072404: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80072408: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8007240C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80072410: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80072414: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80072418: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8007241C: bne         $at, $zero, L_800723F8
    if (ctx->r1 != 0) {
        // 0x80072420: sw          $t1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r9;
            goto L_800723F8;
    }
    // 0x80072420: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_80072424:
    // 0x80072424: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x80072428: addiu       $t8, $t6, 0x24
    ctx->r24 = ADD32(ctx->r14, 0X24);
    // 0x8007242C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
L_80072430:
    // 0x80072430: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80072434: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80072438: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8007243C: swl         $at, -0xC($t5)
    do_swl(rdram, -0XC, ctx->r13, ctx->r1);
    // 0x80072440: swr         $at, -0x9($t5)
    do_swr(rdram, -0X9, ctx->r13, ctx->r1);
    // 0x80072444: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x80072448: swl         $at, -0x8($t5)
    do_swl(rdram, -0X8, ctx->r13, ctx->r1);
    // 0x8007244C: swr         $at, -0x5($t5)
    do_swr(rdram, -0X5, ctx->r13, ctx->r1);
    // 0x80072450: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x80072454: swl         $at, -0x4($t5)
    do_swl(rdram, -0X4, ctx->r13, ctx->r1);
    // 0x80072458: bne         $t6, $t8, L_80072430
    if (ctx->r14 != ctx->r24) {
        // 0x8007245C: swr         $at, -0x1($t5)
        do_swr(rdram, -0X1, ctx->r13, ctx->r1);
            goto L_80072430;
    }
    // 0x8007245C: swr         $at, -0x1($t5)
    do_swr(rdram, -0X1, ctx->r13, ctx->r1);
    // 0x80072460: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80072464: addiu       $t1, $zero, 0xFE
    ctx->r9 = ADD32(0, 0XFE);
    // 0x80072468: swl         $at, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r1);
    // 0x8007246C: swr         $at, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r1);
    // 0x80072470: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80072474: addiu       $t0, $t9, 0x28
    ctx->r8 = ADD32(ctx->r25, 0X28);
    // 0x80072478: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8007247C: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
    // 0x80072480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072484: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80072488: jr          $ra
    // 0x8007248C: nop

    return;
    // 0x8007248C: nop

;}
RECOMP_FUNC void func_80072498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80072498: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007249C: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x800724A0: beq         $t7, $zero, L_800724B0
    if (ctx->r15 == 0) {
        // 0x800724A4: nop
    
            goto L_800724B0;
    }
    // 0x800724A4: nop

    // 0x800724A8: b           L_800724B4
    // 0x800724AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800724B4;
    // 0x800724AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800724B0:
    // 0x800724B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800724B4:
    // 0x800724B4: jr          $ra
    // 0x800724B8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800724B8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800724BC: nop

;}
RECOMP_FUNC void func_800724C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800724C0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800724C4: lw          $t6, 0x6554($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6554);
    ctx->hi = hi; ctx->lo = lo;
    func_800724C8(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_800724C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800724C8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800724CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800724D0: addiu       $t7, $t6, 0x14
    ctx->r15 = ADD32(ctx->r14, 0X14);
    // 0x800724D4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x800724D8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x800724DC: lhu         $t8, 0x1A($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X1A);
    // 0x800724E0: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x800724E4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800724E8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800724EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800724F0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800724F4: addiu       $t1, $t0, 0x18
    ctx->r9 = ADD32(ctx->r8, 0X18);
    // 0x800724F8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800724FC: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80072500: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80072504: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80072508: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8007250C: beq         $t5, $zero, L_80072540
    if (ctx->r13 == 0) {
        // 0x80072510: nop
    
            goto L_80072540;
    }
    // 0x80072510: nop

    // 0x80072514: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80072518: lw          $t6, 0x5D40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5D40);
    // 0x8007251C: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80072520: addiu       $t7, $zero, 0x1D
    ctx->r15 = ADD32(0, 0X1D);
    // 0x80072524: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80072528: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8007252C: sw          $t8, 0x5D40($at)
    MEM_W(0X5D40, ctx->r1) = ctx->r24;
    // 0x80072530: jal         0x80072C4C
    // 0x80072534: sw          $t7, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r15;
    func_80072C4C(rdram, ctx);
        goto after_0;
    // 0x80072534: sw          $t7, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r15;
    after_0:
    // 0x80072538: b           L_80072B54
    // 0x8007253C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072B54;
    // 0x8007253C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072540:
    // 0x80072540: lui         $t9, 0xA460
    ctx->r25 = S32(0XA460 << 16);
    // 0x80072544: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x80072548: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8007254C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80072550: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x80072554: beq         $t3, $zero, L_80072578
    if (ctx->r11 == 0) {
        // 0x80072558: nop
    
            goto L_80072578;
    }
    // 0x80072558: nop

L_8007255C:
    // 0x8007255C: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x80072560: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x80072564: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80072568: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8007256C: andi        $t8, $t6, 0x3
    ctx->r24 = ctx->r14 & 0X3;
    // 0x80072570: bne         $t8, $zero, L_8007255C
    if (ctx->r24 != 0) {
        // 0x80072574: nop
    
            goto L_8007255C;
    }
    // 0x80072574: nop

L_80072578:
    // 0x80072578: lui         $t7, 0xA500
    ctx->r15 = S32(0XA500 << 16);
    // 0x8007257C: lw          $t0, 0x508($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X508);
    // 0x80072580: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x80072584: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80072588: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8007258C: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80072590: beq         $t1, $zero, L_800725F8
    if (ctx->r9 == 0) {
        // 0x80072594: nop
    
            goto L_800725F8;
    }
    // 0x80072594: nop

    // 0x80072598: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x8007259C: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x800725A0: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x800725A4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800725A8: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x800725AC: beq         $t5, $zero, L_800725D0
    if (ctx->r13 == 0) {
        // 0x800725B0: nop
    
            goto L_800725D0;
    }
    // 0x800725B0: nop

L_800725B4:
    // 0x800725B4: lui         $t6, 0xA460
    ctx->r14 = S32(0XA460 << 16);
    // 0x800725B8: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x800725BC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800725C0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800725C4: andi        $t0, $t7, 0x3
    ctx->r8 = ctx->r15 & 0X3;
    // 0x800725C8: bne         $t0, $zero, L_800725B4
    if (ctx->r8 != 0) {
        // 0x800725CC: nop
    
            goto L_800725B4;
    }
    // 0x800725CC: nop

L_800725D0:
    // 0x800725D0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800725D4: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800725D8: lui         $t3, 0xA500
    ctx->r11 = S32(0XA500 << 16);
    // 0x800725DC: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x800725E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800725E4: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x800725E8: sw          $t2, 0x510($t3)
    MEM_W(0X510, ctx->r11) = ctx->r10;
    // 0x800725EC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800725F0: b           L_80072B54
    // 0x800725F4: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
        goto L_80072B54;
    // 0x800725F4: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_800725F8:
    // 0x800725F8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800725FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80072600: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80072604: bne         $t6, $at, L_80072614
    if (ctx->r14 != ctx->r1) {
        // 0x80072608: nop
    
            goto L_80072614;
    }
    // 0x80072608: nop

    // 0x8007260C: b           L_80072B54
    // 0x80072610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072B54;
    // 0x80072610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072614:
    // 0x80072614: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80072618: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8007261C: and         $t7, $t8, $at
    ctx->r15 = ctx->r24 & ctx->r1;
    // 0x80072620: beq         $t7, $zero, L_800726AC
    if (ctx->r15 == 0) {
        // 0x80072624: nop
    
            goto L_800726AC;
    }
    // 0x80072624: nop

    // 0x80072628: lui         $t0, 0xA460
    ctx->r8 = S32(0XA460 << 16);
    // 0x8007262C: lw          $t9, 0x10($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X10);
    // 0x80072630: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80072634: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80072638: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x8007263C: beq         $t2, $zero, L_80072660
    if (ctx->r10 == 0) {
        // 0x80072640: nop
    
            goto L_80072660;
    }
    // 0x80072640: nop

L_80072644:
    // 0x80072644: lui         $t3, 0xA460
    ctx->r11 = S32(0XA460 << 16);
    // 0x80072648: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8007264C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80072650: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80072654: andi        $t6, $t5, 0x3
    ctx->r14 = ctx->r13 & 0X3;
    // 0x80072658: bne         $t6, $zero, L_80072644
    if (ctx->r14 != 0) {
        // 0x8007265C: nop
    
            goto L_80072644;
    }
    // 0x8007265C: nop

L_80072660:
    // 0x80072660: lui         $t8, 0xA500
    ctx->r24 = S32(0XA500 << 16);
    // 0x80072664: lw          $t7, 0x508($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X508);
    // 0x80072668: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007266C: addiu       $t0, $zero, 0x16
    ctx->r8 = ADD32(0, 0X16);
    // 0x80072670: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80072674: jal         0x80072C4C
    // 0x80072678: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    func_80072C4C(rdram, ctx);
        goto after_1;
    // 0x80072678: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    after_1:
    // 0x8007267C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80072680: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x80072684: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
    // 0x80072688: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8007268C: lw          $t3, 0x5D40($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5D40);
    // 0x80072690: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80072694: ori         $at, $at, 0x401
    ctx->r1 = ctx->r1 | 0X401;
    // 0x80072698: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8007269C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800726A0: sw          $t4, 0x5D40($at)
    MEM_W(0X5D40, ctx->r1) = ctx->r12;
    // 0x800726A4: b           L_80072B54
    // 0x800726A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072B54;
    // 0x800726A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800726AC:
    // 0x800726AC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800726B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800726B4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800726B8: bne         $t6, $at, L_800727A8
    if (ctx->r14 != ctx->r1) {
        // 0x800726BC: nop
    
            goto L_800727A8;
    }
    // 0x800726BC: nop

    // 0x800726C0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800726C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800726C8: and         $t7, $t8, $at
    ctx->r15 = ctx->r24 & ctx->r1;
    // 0x800726CC: bne         $t7, $zero, L_80072754
    if (ctx->r15 != 0) {
        // 0x800726D0: nop
    
            goto L_80072754;
    }
    // 0x800726D0: nop

    // 0x800726D4: lhu         $t1, 0x4($t5)
    ctx->r9 = MEM_HU(ctx->r13, 0X4);
    // 0x800726D8: lw          $t0, 0x8($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X8);
    // 0x800726DC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800726E0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800726E4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800726E8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800726EC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800726F0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800726F4: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800726F8: beq         $t9, $t2, L_80072718
    if (ctx->r25 == ctx->r10) {
        // 0x800726FC: nop
    
            goto L_80072718;
    }
    // 0x800726FC: nop

    // 0x80072700: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80072704: addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    // 0x80072708: jal         0x80072B64
    // 0x8007270C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    func_80072B64(rdram, ctx);
        goto after_2;
    // 0x8007270C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    after_2:
    // 0x80072710: b           L_80072B54
    // 0x80072714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072B54;
    // 0x80072714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072718:
    // 0x80072718: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8007271C: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x80072720: sw          $t6, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r14;
    // 0x80072724: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80072728: lw          $t7, 0x5D40($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5D40);
    // 0x8007272C: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80072730: ori         $at, $at, 0x401
    ctx->r1 = ctx->r1 | 0X401;
    // 0x80072734: or          $t0, $t7, $at
    ctx->r8 = ctx->r15 | ctx->r1;
    // 0x80072738: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007273C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80072740: sw          $t0, 0x5D40($at)
    MEM_W(0X5D40, ctx->r1) = ctx->r8;
    // 0x80072744: jal         0x80072C4C
    // 0x80072748: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    func_80072C4C(rdram, ctx);
        goto after_3;
    // 0x80072748: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    after_3:
    // 0x8007274C: b           L_80072B54
    // 0x80072750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072B54;
    // 0x80072750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072754:
    // 0x80072754: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80072758: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8007275C: lui         $a2, 0x500
    ctx->r6 = S32(0X500 << 16);
    // 0x80072760: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x80072764: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80072768: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x8007276C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80072770: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80072774: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80072778: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007277C: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x80072780: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80072784: sw          $t8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r24;
    // 0x80072788: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007278C: lw          $a0, 0x6554($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6554);
    // 0x80072790: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x80072794: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x80072798: jal         0x8006EB30
    // 0x8007279C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    osEPiRawStartDma_recomp(rdram, ctx);
        goto after_4;
    // 0x8007279C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_4:
    // 0x800727A0: b           L_80072B54
    // 0x800727A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072B54;
    // 0x800727A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800727A8:
    // 0x800727A8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800727AC: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x800727B0: bne         $t9, $zero, L_80072B40
    if (ctx->r25 != 0) {
        // 0x800727B4: nop
    
            goto L_80072B40;
    }
    // 0x800727B4: nop

    // 0x800727B8: lhu         $t2, 0x4($t5)
    ctx->r10 = MEM_HU(ctx->r13, 0X4);
    // 0x800727BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800727C0: bne         $t2, $at, L_80072820
    if (ctx->r10 != ctx->r1) {
        // 0x800727C4: nop
    
            goto L_80072820;
    }
    // 0x800727C4: nop

    // 0x800727C8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800727CC: lw          $t3, 0x8($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X8);
    // 0x800727D0: lw          $t6, 0x10($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X10);
    // 0x800727D4: addiu       $t8, $t6, 0x11
    ctx->r24 = ADD32(ctx->r14, 0X11);
    // 0x800727D8: slt         $at, $t8, $t3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800727DC: beq         $at, $zero, L_800727F4
    if (ctx->r1 == 0) {
        // 0x800727E0: nop
    
            goto L_800727F4;
    }
    // 0x800727E0: nop

    // 0x800727E4: jal         0x80072B64
    // 0x800727E8: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    func_80072B64(rdram, ctx);
        goto after_5;
    // 0x800727E8: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    after_5:
    // 0x800727EC: b           L_80072B54
    // 0x800727F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072B54;
    // 0x800727F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800727F4:
    // 0x800727F4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800727F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800727FC: and         $t7, $t4, $at
    ctx->r15 = ctx->r12 & ctx->r1;
    // 0x80072800: bne         $t7, $zero, L_80072834
    if (ctx->r15 != 0) {
        // 0x80072804: nop
    
            goto L_80072834;
    }
    // 0x80072804: nop

    // 0x80072808: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007280C: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x80072810: jal         0x80072B64
    // 0x80072814: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    func_80072B64(rdram, ctx);
        goto after_6;
    // 0x80072814: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    after_6:
    // 0x80072818: b           L_80072B54
    // 0x8007281C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072B54;
    // 0x8007281C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072820:
    // 0x80072820: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80072824: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80072828: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x8007282C: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x80072830: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
L_80072834:
    // 0x80072834: lui         $t8, 0xA500
    ctx->r24 = S32(0XA500 << 16);
    // 0x80072838: lw          $t1, 0x510($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X510);
    // 0x8007283C: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x80072840: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80072844: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80072848: and         $t7, $t4, $at
    ctx->r15 = ctx->r12 & ctx->r1;
    // 0x8007284C: beq         $t7, $zero, L_80072860
    if (ctx->r15 == 0) {
        // 0x80072850: lui         $at, 0x40
        ctx->r1 = S32(0X40 << 16);
            goto L_80072860;
    }
    // 0x80072850: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x80072854: and         $t0, $t4, $at
    ctx->r8 = ctx->r12 & ctx->r1;
    // 0x80072858: bne         $t0, $zero, L_80072874
    if (ctx->r8 != 0) {
        // 0x8007285C: nop
    
            goto L_80072874;
    }
    // 0x8007285C: nop

L_80072860:
    // 0x80072860: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80072864: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x80072868: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x8007286C: beq         $t5, $zero, L_800728F8
    if (ctx->r13 == 0) {
        // 0x80072870: nop
    
            goto L_800728F8;
    }
    // 0x80072870: nop

L_80072874:
    // 0x80072874: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80072878: lw          $t3, 0x10($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X10);
    // 0x8007287C: sltiu       $at, $t3, 0x4
    ctx->r1 = ctx->r11 < 0X4 ? 1 : 0;
    // 0x80072880: bne         $at, $zero, L_800728C4
    if (ctx->r1 != 0) {
        // 0x80072884: nop
    
            goto L_800728C4;
    }
    // 0x80072884: nop

    // 0x80072888: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007288C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80072890: lhu         $t8, 0x4($t2)
    ctx->r24 = MEM_HU(ctx->r10, 0X4);
    // 0x80072894: bne         $t8, $at, L_800728AC
    if (ctx->r24 != ctx->r1) {
        // 0x80072898: nop
    
            goto L_800728AC;
    }
    // 0x80072898: nop

    // 0x8007289C: lw          $t1, 0x8($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X8);
    // 0x800728A0: slti        $at, $t1, 0x53
    ctx->r1 = SIGNED(ctx->r9) < 0X53 ? 1 : 0;
    // 0x800728A4: bne         $at, $zero, L_800728E8
    if (ctx->r1 != 0) {
        // 0x800728A8: nop
    
            goto L_800728E8;
    }
    // 0x800728A8: nop

L_800728AC:
    // 0x800728AC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800728B0: addiu       $t7, $zero, 0x17
    ctx->r15 = ADD32(0, 0X17);
    // 0x800728B4: jal         0x80072B64
    // 0x800728B8: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    func_80072B64(rdram, ctx);
        goto after_7;
    // 0x800728B8: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    after_7:
    // 0x800728BC: b           L_80072B54
    // 0x800728C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072B54;
    // 0x800728C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800728C4:
    // 0x800728C4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800728C8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800728CC: lw          $t9, 0x10($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X10);
    // 0x800728D0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800728D4: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x800728D8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800728DC: addu        $t2, $t0, $t8
    ctx->r10 = ADD32(ctx->r8, ctx->r24);
    // 0x800728E0: addiu       $t3, $t6, 0x1
    ctx->r11 = ADD32(ctx->r14, 0X1);
    // 0x800728E4: sw          $t3, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r11;
L_800728E8:
    // 0x800728E8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800728EC: lw          $t7, 0x10($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X10);
    // 0x800728F0: addiu       $t4, $t7, 0x1
    ctx->r12 = ADD32(ctx->r15, 0X1);
    // 0x800728F4: sw          $t4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r12;
L_800728F8:
    // 0x800728F8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800728FC: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80072900: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80072904: beq         $t6, $zero, L_800729F4
    if (ctx->r14 == 0) {
        // 0x80072908: nop
    
            goto L_800729F4;
    }
    // 0x80072908: nop

    // 0x8007290C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80072910: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x80072914: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80072918: beq         $t0, $at, L_80072930
    if (ctx->r8 == ctx->r1) {
        // 0x8007291C: nop
    
            goto L_80072930;
    }
    // 0x8007291C: nop

    // 0x80072920: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80072924: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x80072928: jal         0x80072B64
    // 0x8007292C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    func_80072B64(rdram, ctx);
        goto after_8;
    // 0x8007292C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    after_8:
L_80072930:
    // 0x80072930: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80072934: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80072938: lhu         $t7, 0x4($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X4);
    // 0x8007293C: bne         $t7, $at, L_80072988
    if (ctx->r15 != ctx->r1) {
        // 0x80072940: nop
    
            goto L_80072988;
    }
    // 0x80072940: nop

    // 0x80072944: lhu         $t4, 0x6($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X6);
    // 0x80072948: bne         $t4, $zero, L_80072988
    if (ctx->r12 != 0) {
        // 0x8007294C: nop
    
            goto L_80072988;
    }
    // 0x8007294C: nop

    // 0x80072950: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80072954: sh          $t1, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r9;
    // 0x80072958: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007295C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80072960: addiu       $t7, $zero, 0x16
    ctx->r15 = ADD32(0, 0X16);
    // 0x80072964: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x80072968: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007296C: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x80072970: lw          $t8, 0x48($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X48);
    // 0x80072974: subu        $t3, $t0, $t8
    ctx->r11 = SUB32(ctx->r8, ctx->r24);
    // 0x80072978: sw          $t3, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->r11;
    // 0x8007297C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80072980: b           L_800729C4
    // 0x80072984: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
        goto L_800729C4;
    // 0x80072984: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
L_80072988:
    // 0x80072988: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8007298C: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x80072990: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
    // 0x80072994: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80072998: lw          $t5, 0x5D40($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5D40);
    // 0x8007299C: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x800729A0: ori         $at, $at, 0x401
    ctx->r1 = ctx->r1 | 0X401;
    // 0x800729A4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800729A8: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800729AC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800729B0: sw          $t6, 0x5D40($at)
    MEM_W(0X5D40, ctx->r1) = ctx->r14;
    // 0x800729B4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800729B8: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x800729BC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800729C0: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_800729C4:
    // 0x800729C4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800729C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800729CC: lw          $a0, 0x6554($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6554);
    // 0x800729D0: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x800729D4: lw          $a3, 0x8($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X8);
    // 0x800729D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800729DC: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x800729E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800729E4: jal         0x8006EB30
    // 0x800729E8: lui         $a2, 0x500
    ctx->r6 = S32(0X500 << 16);
    osEPiRawStartDma_recomp(rdram, ctx);
        goto after_9;
    // 0x800729E8: lui         $a2, 0x500
    ctx->r6 = S32(0X500 << 16);
    after_9:
    // 0x800729EC: b           L_80072B54
    // 0x800729F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072B54;
    // 0x800729F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800729F4:
    // 0x800729F4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800729F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800729FC: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80072A00: bne         $t2, $at, L_80072A84
    if (ctx->r10 != ctx->r1) {
        // 0x80072A04: nop
    
            goto L_80072A84;
    }
    // 0x80072A04: nop

    // 0x80072A08: lhu         $t5, 0x4($t1)
    ctx->r13 = MEM_HU(ctx->r9, 0X4);
    // 0x80072A0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80072A10: bne         $t5, $at, L_80072A84
    if (ctx->r13 != ctx->r1) {
        // 0x80072A14: nop
    
            goto L_80072A84;
    }
    // 0x80072A14: nop

    // 0x80072A18: lhu         $t6, 0x6($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X6);
    // 0x80072A1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80072A20: bne         $t6, $at, L_80072A84
    if (ctx->r14 != ctx->r1) {
        // 0x80072A24: nop
    
            goto L_80072A84;
    }
    // 0x80072A24: nop

    // 0x80072A28: addiu       $t0, $t1, 0x18
    ctx->r8 = ADD32(ctx->r9, 0X18);
    // 0x80072A2C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80072A30: lw          $t8, 0x28($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X28);
    // 0x80072A34: bne         $t8, $zero, L_80072A78
    if (ctx->r24 != 0) {
        // 0x80072A38: nop
    
            goto L_80072A78;
    }
    // 0x80072A38: nop

    // 0x80072A3C: lw          $t3, 0x20($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X20);
    // 0x80072A40: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x80072A44: lw          $t7, 0x4($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X4);
    // 0x80072A48: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x80072A4C: lw          $t6, 0xC($t3)
    ctx->r14 = MEM_W(ctx->r11, 0XC);
    // 0x80072A50: or          $t4, $t9, $t7
    ctx->r12 = ctx->r25 | ctx->r15;
    // 0x80072A54: or          $t5, $t4, $t2
    ctx->r13 = ctx->r12 | ctx->r10;
    // 0x80072A58: or          $t0, $t6, $t5
    ctx->r8 = ctx->r14 | ctx->r13;
    // 0x80072A5C: beq         $t0, $zero, L_80072A78
    if (ctx->r8 == 0) {
        // 0x80072A60: nop
    
            goto L_80072A78;
    }
    // 0x80072A60: nop

    // 0x80072A64: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x80072A68: jal         0x80072B64
    // 0x80072A6C: sw          $t8, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r24;
    func_80072B64(rdram, ctx);
        goto after_10;
    // 0x80072A6C: sw          $t8, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r24;
    after_10:
    // 0x80072A70: b           L_80072B54
    // 0x80072A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072B54;
    // 0x80072A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072A78:
    // 0x80072A78: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80072A7C: jal         0x80072C4C
    // 0x80072A80: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    func_80072C4C(rdram, ctx);
        goto after_11;
    // 0x80072A80: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    after_11:
L_80072A84:
    // 0x80072A84: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80072A88: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80072A8C: lw          $t4, 0x8($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X8);
    // 0x80072A90: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x80072A94: sw          $t2, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r10;
    // 0x80072A98: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80072A9C: and         $t6, $t3, $at
    ctx->r14 = ctx->r11 & ctx->r1;
    // 0x80072AA0: beq         $t6, $zero, L_80072B0C
    if (ctx->r14 == 0) {
        // 0x80072AA4: nop
    
            goto L_80072B0C;
    }
    // 0x80072AA4: nop

    // 0x80072AA8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80072AAC: lw          $t0, 0x8($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X8);
    // 0x80072AB0: slti        $at, $t0, 0x55
    ctx->r1 = SIGNED(ctx->r8) < 0X55 ? 1 : 0;
    // 0x80072AB4: bne         $at, $zero, L_80072AD4
    if (ctx->r1 != 0) {
        // 0x80072AB8: nop
    
            goto L_80072AD4;
    }
    // 0x80072AB8: nop

    // 0x80072ABC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80072AC0: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x80072AC4: jal         0x80072B64
    // 0x80072AC8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    func_80072B64(rdram, ctx);
        goto after_12;
    // 0x80072AC8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    after_12:
    // 0x80072ACC: b           L_80072B54
    // 0x80072AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072B54;
    // 0x80072AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072AD4:
    // 0x80072AD4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80072AD8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80072ADC: lui         $a2, 0x500
    ctx->r6 = S32(0X500 << 16);
    // 0x80072AE0: lw          $t4, 0xC($t9)
    ctx->r12 = MEM_W(ctx->r25, 0XC);
    // 0x80072AE4: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x80072AE8: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x80072AEC: lw          $a0, 0x6554($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6554);
    // 0x80072AF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80072AF4: jal         0x8006EB30
    // 0x80072AF8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    osEPiRawStartDma_recomp(rdram, ctx);
        goto after_13;
    // 0x80072AF8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_13:
    // 0x80072AFC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80072B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80072B04: b           L_80072B54
    // 0x80072B08: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
        goto L_80072B54;
    // 0x80072B08: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80072B0C:
    // 0x80072B0C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80072B10: lw          $t3, 0x8($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X8);
    // 0x80072B14: slti        $at, $t3, 0x55
    ctx->r1 = SIGNED(ctx->r11) < 0X55 ? 1 : 0;
    // 0x80072B18: beq         $at, $zero, L_80072B38
    if (ctx->r1 == 0) {
        // 0x80072B1C: nop
    
            goto L_80072B38;
    }
    // 0x80072B1C: nop

    // 0x80072B20: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80072B24: addiu       $t6, $zero, 0x18
    ctx->r14 = ADD32(0, 0X18);
    // 0x80072B28: jal         0x80072B64
    // 0x80072B2C: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    func_80072B64(rdram, ctx);
        goto after_14;
    // 0x80072B2C: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    after_14:
    // 0x80072B30: b           L_80072B54
    // 0x80072B34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072B54;
    // 0x80072B34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072B38:
    // 0x80072B38: b           L_80072B54
    // 0x80072B3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072B54;
    // 0x80072B3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072B40:
    // 0x80072B40: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80072B44: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80072B48: jal         0x80072B64
    // 0x80072B4C: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    func_80072B64(rdram, ctx);
        goto after_15;
    // 0x80072B4C: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    after_15:
    // 0x80072B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072B54:
    // 0x80072B54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072B58: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80072B5C: jr          $ra
    // 0x80072B60: nop

    return;
    // 0x80072B60: nop

;}
RECOMP_FUNC void func_80072B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80072B64: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80072B68: lw          $t6, 0x6554($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6554);
    ctx->hi = hi; ctx->lo = lo;
    func_80072B6C(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_80072B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80072B6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80072B70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072B74: addiu       $t7, $t6, 0x14
    ctx->r15 = ADD32(ctx->r14, 0X14);
    // 0x80072B78: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80072B7C: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x80072B80: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80072B84: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80072B88: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80072B8C: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80072B90: beq         $t1, $zero, L_80072BB4
    if (ctx->r9 == 0) {
        // 0x80072B94: nop
    
            goto L_80072BB4;
    }
    // 0x80072B94: nop

L_80072B98:
    // 0x80072B98: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x80072B9C: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80072BA0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80072BA4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80072BA8: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x80072BAC: bne         $t5, $zero, L_80072B98
    if (ctx->r13 != 0) {
        // 0x80072BB0: nop
    
            goto L_80072B98;
    }
    // 0x80072BB0: nop

L_80072BB4:
    // 0x80072BB4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80072BB8: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80072BBC: lui         $t9, 0xA500
    ctx->r25 = S32(0XA500 << 16);
    // 0x80072BC0: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80072BC4: lui         $t0, 0xA460
    ctx->r8 = S32(0XA460 << 16);
    // 0x80072BC8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80072BCC: sw          $t8, 0x510($t9)
    MEM_W(0X510, ctx->r25) = ctx->r24;
    // 0x80072BD0: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80072BD4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80072BD8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80072BDC: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x80072BE0: beq         $t3, $zero, L_80072C04
    if (ctx->r11 == 0) {
        // 0x80072BE4: nop
    
            goto L_80072C04;
    }
    // 0x80072BE4: nop

L_80072BE8:
    // 0x80072BE8: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x80072BEC: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x80072BF0: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80072BF4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80072BF8: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80072BFC: bne         $t7, $zero, L_80072BE8
    if (ctx->r15 != 0) {
        // 0x80072C00: nop
    
            goto L_80072BE8;
    }
    // 0x80072C00: nop

L_80072C04:
    // 0x80072C04: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80072C08: lui         $t0, 0xA500
    ctx->r8 = S32(0XA500 << 16);
    // 0x80072C0C: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80072C10: jal         0x80072C4C
    // 0x80072C14: sw          $t9, 0x510($t0)
    MEM_W(0X510, ctx->r8) = ctx->r25;
    func_80072C4C(rdram, ctx);
        goto after_0;
    // 0x80072C14: sw          $t9, 0x510($t0)
    MEM_W(0X510, ctx->r8) = ctx->r25;
    after_0:
    // 0x80072C18: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80072C1C: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x80072C20: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
    // 0x80072C24: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80072C28: lw          $t3, 0x5D40($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5D40);
    // 0x80072C2C: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80072C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072C34: ori         $at, $at, 0x401
    ctx->r1 = ctx->r1 | 0X401;
    // 0x80072C38: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80072C3C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80072C40: sw          $t4, 0x5D40($at)
    MEM_W(0X5D40, ctx->r1) = ctx->r12;
    // 0x80072C44: jr          $ra
    // 0x80072C48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80072C48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80072C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80072C4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80072C50: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80072C54: addiu       $t6, $t6, 0x4E70
    ctx->r14 = ADD32(ctx->r14, 0X4E70);
    // 0x80072C58: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x80072C5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072C60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80072C64: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80072C68: lw          $t8, 0x40($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X40);
    // 0x80072C6C: beq         $t8, $zero, L_80072D24
    if (ctx->r24 == 0) {
        // 0x80072C70: sw          $t8, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r24;
            goto L_80072D24;
    }
    // 0x80072C70: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80072C74: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80072C78: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x80072C7C: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80072C80: beq         $at, $zero, L_80072D24
    if (ctx->r1 == 0) {
        // 0x80072C84: nop
    
            goto L_80072D24;
    }
    // 0x80072C84: nop

    // 0x80072C88: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80072C8C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80072C90: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80072C94: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80072C98: lw          $t5, 0x10($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X10);
    // 0x80072C9C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80072CA0: div         $zero, $t4, $t5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r13)));
    // 0x80072CA4: mfhi        $t7
    ctx->r15 = hi;
    // 0x80072CA8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80072CAC: lw          $t0, 0x14($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X14);
    // 0x80072CB0: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80072CB4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80072CB8: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x80072CBC: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x80072CC0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80072CC4: bne         $t5, $zero, L_80072CD0
    if (ctx->r13 != 0) {
        // 0x80072CC8: nop
    
            goto L_80072CD0;
    }
    // 0x80072CC8: nop

    // 0x80072CCC: break       7
    do_break(2147953868);
L_80072CD0:
    // 0x80072CD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80072CD4: bne         $t5, $at, L_80072CE8
    if (ctx->r13 != ctx->r1) {
        // 0x80072CD8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80072CE8;
    }
    // 0x80072CD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80072CDC: bne         $t4, $at, L_80072CE8
    if (ctx->r12 != ctx->r1) {
        // 0x80072CE0: nop
    
            goto L_80072CE8;
    }
    // 0x80072CE0: nop

    // 0x80072CE4: break       6
    do_break(2147953892);
L_80072CE8:
    // 0x80072CE8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80072CEC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80072CF0: sw          $t5, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r13;
    // 0x80072CF4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80072CF8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80072CFC: lw          $t1, 0x0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X0);
    // 0x80072D00: beq         $t1, $zero, L_80072D24
    if (ctx->r9 == 0) {
        // 0x80072D04: nop
    
            goto L_80072D24;
    }
    // 0x80072D04: nop

    // 0x80072D08: jal         0x8006E2A4
    // 0x80072D0C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    __osPopThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80072D0C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80072D10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80072D14: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80072D18: addiu       $a0, $a0, 0x6B08
    ctx->r4 = ADD32(ctx->r4, 0X6B08);
    // 0x80072D1C: jal         0x8006E25C
    // 0x80072D20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __osEnqueueThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80072D20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
L_80072D24:
    // 0x80072D24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072D28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80072D2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80072D30: jr          $ra
    // 0x80072D34: nop

    return;
    // 0x80072D34: nop

    // 0x80072D38: nop

    // 0x80072D3C: nop

;}
RECOMP_FUNC void func_80072DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80072DA8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80072DAC: andi        $t7, $a3, 0x3
    ctx->r15 = ctx->r7 & 0X3;
    // 0x80072DB0: beq         $t7, $zero, L_80072DCC
    if (ctx->r15 == 0) {
        // 0x80072DB4: nop
    
            goto L_80072DCC;
    }
    // 0x80072DB4: nop

L_80072DB8:
    // 0x80072DB8: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x80072DBC: lw          $a3, 0x10($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X10);
    // 0x80072DC0: andi        $t9, $a3, 0x3
    ctx->r25 = ctx->r7 & 0X3;
    // 0x80072DC4: bne         $t9, $zero, L_80072DB8
    if (ctx->r25 != 0) {
        // 0x80072DC8: nop
    
            goto L_80072DB8;
    }
    // 0x80072DC8: nop

L_80072DCC:
    // 0x80072DCC: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x80072DD0: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x80072DD4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80072DD8: or          $t1, $t0, $a1
    ctx->r9 = ctx->r8 | ctx->r5;
    // 0x80072DDC: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x80072DE0: sw          $a2, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r6;
    // 0x80072DE4: jr          $ra
    // 0x80072DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80072DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80072DEC: nop

;}
RECOMP_FUNC void func_80072DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80072DF8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80072DFC: andi        $t7, $a3, 0x3
    ctx->r15 = ctx->r7 & 0X3;
    // 0x80072E00: beq         $t7, $zero, L_80072E1C
    if (ctx->r15 == 0) {
        // 0x80072E04: nop
    
            goto L_80072E1C;
    }
    // 0x80072E04: nop

L_80072E08:
    // 0x80072E08: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x80072E0C: lw          $a3, 0x10($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X10);
    // 0x80072E10: andi        $t9, $a3, 0x3
    ctx->r25 = ctx->r7 & 0X3;
    // 0x80072E14: bne         $t9, $zero, L_80072E08
    if (ctx->r25 != 0) {
        // 0x80072E18: nop
    
            goto L_80072E08;
    }
    // 0x80072E18: nop

L_80072E1C:
    // 0x80072E1C: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x80072E20: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x80072E24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80072E28: or          $t1, $t0, $a1
    ctx->r9 = ctx->r8 | ctx->r5;
    // 0x80072E2C: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x80072E30: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80072E34: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80072E38: jr          $ra
    // 0x80072E3C: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    return;
    // 0x80072E3C: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
;}
RECOMP_FUNC void func_80072FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80072FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072FB8: jal         0x8006B450
    // 0x80072FBC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x80072FBC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80072FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072FC4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80072FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072FCC: jr          $ra
    // 0x80072FD0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    return;
    // 0x80072FD0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
;}
RECOMP_FUNC void sprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80072FD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80072FD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80072FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072FE0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80072FE4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80072FE8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80072FEC: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80072FF0: addiu       $a0, $a0, 0x2FB0
    ctx->r4 = ADD32(ctx->r4, 0X2FB0);
    // 0x80072FF4: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80072FF8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80072FFC: jal         0x800736A0
    // 0x80073000: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _Printf(rdram, ctx);
        goto after_0;
    // 0x80073000: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80073004: bltz        $v0, L_80073018
    if (SIGNED(ctx->r2) < 0) {
        // 0x80073008: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80073018;
    }
    // 0x80073008: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007300C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80073010: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80073014: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
L_80073018:
    // 0x80073018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007301C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80073020: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80073024: jr          $ra
    // 0x80073028: nop

    return;
    // 0x80073028: nop

    // 0x8007302C: nop

;}
RECOMP_FUNC void func_80073030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80073030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073034: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80073038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007303C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80073040: slti        $at, $t6, 0x26
    ctx->r1 = SIGNED(ctx->r14) < 0X26 ? 1 : 0;
    // 0x80073044: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80073048: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8007304C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x80073050: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80073054: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80073058: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8007305C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80073060: bne         $at, $zero, L_8007308C
    if (ctx->r1 != 0) {
        // 0x80073064: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8007308C;
    }
    // 0x80073064: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80073068: addiu       $t7, $t6, -0x45
    ctx->r15 = ADD32(ctx->r14, -0X45);
    // 0x8007306C: sltiu       $at, $t7, 0x34
    ctx->r1 = ctx->r15 < 0X34 ? 1 : 0;
    // 0x80073070: beq         $at, $zero, L_80073678
    if (ctx->r1 == 0) {
        // 0x80073074: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80073678;
    }
    // 0x80073074: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80073078: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8007307C: addu        $at, $at, $t7
    gpr jr_addend_80073084 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80073080: lw          $t7, -0x22FC($at)
    ctx->r15 = ADD32(ctx->r1, -0X22FC);
    // 0x80073084: jr          $t7
    // 0x80073088: nop

    switch (jr_addend_80073084 >> 2) {
        case 0: goto L_80073398; break;
        case 1: goto L_80073678; break;
        case 2: goto L_80073398; break;
        case 3: goto L_80073678; break;
        case 4: goto L_80073678; break;
        case 5: goto L_80073678; break;
        case 6: goto L_80073678; break;
        case 7: goto L_80073678; break;
        case 8: goto L_80073678; break;
        case 9: goto L_80073678; break;
        case 10: goto L_80073678; break;
        case 11: goto L_80073678; break;
        case 12: goto L_80073678; break;
        case 13: goto L_80073678; break;
        case 14: goto L_80073678; break;
        case 15: goto L_80073678; break;
        case 16: goto L_80073678; break;
        case 17: goto L_80073678; break;
        case 18: goto L_80073678; break;
        case 19: goto L_80073248; break;
        case 20: goto L_80073678; break;
        case 21: goto L_80073678; break;
        case 22: goto L_80073678; break;
        case 23: goto L_80073678; break;
        case 24: goto L_80073678; break;
        case 25: goto L_80073678; break;
        case 26: goto L_80073678; break;
        case 27: goto L_80073678; break;
        case 28: goto L_80073678; break;
        case 29: goto L_80073678; break;
        case 30: goto L_800730A0; break;
        case 31: goto L_800730D8; break;
        case 32: goto L_80073398; break;
        case 33: goto L_80073398; break;
        case 34: goto L_80073398; break;
        case 35: goto L_80073678; break;
        case 36: goto L_800730D8; break;
        case 37: goto L_80073678; break;
        case 38: goto L_80073678; break;
        case 39: goto L_80073678; break;
        case 40: goto L_80073678; break;
        case 41: goto L_800734FC; break;
        case 42: goto L_80073248; break;
        case 43: goto L_800735CC; break;
        case 44: goto L_80073678; break;
        case 45: goto L_80073678; break;
        case 46: goto L_80073614; break;
        case 47: goto L_80073678; break;
        case 48: goto L_80073248; break;
        case 49: goto L_80073678; break;
        case 50: goto L_80073678; break;
        case 51: goto L_80073248; break;
        default: switch_error(__func__, 0x80073084, 0x800BDD04);
    }
    // 0x80073088: nop

L_8007308C:
    // 0x8007308C: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80073090: beql        $v1, $at, L_8007365C
    if (ctx->r3 == ctx->r1) {
        // 0x80073094: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_8007365C;
    }
    goto skip_0;
    // 0x80073094: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x80073098: b           L_8007367C
    // 0x8007309C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
        goto L_8007367C;
    // 0x8007309C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_800730A0:
    // 0x800730A0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800730A4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800730A8: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x800730AC: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x800730B0: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800730B4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800730B8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800730BC: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800730C0: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x800730C4: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800730C8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800730CC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800730D0: b           L_80073690
    // 0x800730D4: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_80073690;
    // 0x800730D4: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_800730D8:
    // 0x800730D8: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800730DC: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800730E0: bnel        $v0, $at, L_80073118
    if (ctx->r2 != ctx->r1) {
        // 0x800730E4: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_80073118;
    }
    goto skip_1;
    // 0x800730E4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_1:
    // 0x800730E8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800730EC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800730F0: addiu       $t7, $t9, 0x3
    ctx->r15 = ADD32(ctx->r25, 0X3);
    // 0x800730F4: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800730F8: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800730FC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80073100: lw          $t7, -0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X4);
    // 0x80073104: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x80073108: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8007310C: b           L_80073174
    // 0x80073110: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_80073174;
    // 0x80073110: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80073114: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_80073118:
    // 0x80073118: bnel        $v0, $at, L_80073150
    if (ctx->r2 != ctx->r1) {
        // 0x8007311C: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_80073150;
    }
    goto skip_2;
    // 0x8007311C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_2:
    // 0x80073120: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80073124: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80073128: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x8007312C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80073130: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80073134: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80073138: lw          $t8, -0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X8);
    // 0x8007313C: lw          $t9, -0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4);
    // 0x80073140: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80073144: b           L_80073174
    // 0x80073148: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_80073174;
    // 0x80073148: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x8007314C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_80073150:
    // 0x80073150: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80073154: addiu       $t6, $t7, 0x3
    ctx->r14 = ADD32(ctx->r15, 0X3);
    // 0x80073158: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x8007315C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x80073160: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80073164: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x80073168: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x8007316C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80073170: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_80073174:
    // 0x80073174: lbu         $t7, 0x34($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X34);
    // 0x80073178: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8007317C: bnel        $t7, $at, L_800731A0
    if (ctx->r15 != ctx->r1) {
        // 0x80073180: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_800731A0;
    }
    goto skip_3;
    // 0x80073180: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x80073184: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80073188: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x8007318C: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80073190: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x80073194: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80073198: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x8007319C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_800731A0:
    // 0x800731A0: bgtzl       $t6, L_800731DC
    if (SIGNED(ctx->r14) > 0) {
        // 0x800731A4: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_800731DC;
    }
    goto skip_4;
    // 0x800731A4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_4:
    // 0x800731A8: bltzl       $t6, L_800731BC
    if (SIGNED(ctx->r14) < 0) {
        // 0x800731AC: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_800731BC;
    }
    goto skip_5;
    // 0x800731AC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_5:
    // 0x800731B0: b           L_800731DC
    // 0x800731B4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
        goto L_800731DC;
    // 0x800731B4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x800731B8: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_800731BC:
    // 0x800731BC: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x800731C0: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800731C4: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800731C8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800731CC: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800731D0: b           L_8007322C
    // 0x800731D4: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
        goto L_8007322C;
    // 0x800731D4: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800731D8: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_800731DC:
    // 0x800731DC: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x800731E0: beq         $t8, $zero, L_80073208
    if (ctx->r24 == 0) {
        // 0x800731E4: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_80073208;
    }
    // 0x800731E4: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800731E8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800731EC: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x800731F0: addu        $t9, $a3, $t7
    ctx->r25 = ADD32(ctx->r7, ctx->r15);
    // 0x800731F4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800731F8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800731FC: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80073200: b           L_8007322C
    // 0x80073204: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
        goto L_8007322C;
    // 0x80073204: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
L_80073208:
    // 0x80073208: beql        $t6, $zero, L_80073230
    if (ctx->r14 == 0) {
        // 0x8007320C: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_80073230;
    }
    goto skip_6;
    // 0x8007320C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_6:
    // 0x80073210: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80073214: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80073218: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x8007321C: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x80073220: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80073224: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80073228: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_8007322C:
    // 0x8007322C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_80073230:
    // 0x80073230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80073234: addu        $t7, $t9, $a3
    ctx->r15 = ADD32(ctx->r25, ctx->r7);
    // 0x80073238: jal         0x80073CF0
    // 0x8007323C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_0;
    // 0x8007323C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_0:
    // 0x80073240: b           L_80073694
    // 0x80073244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80073694;
    // 0x80073244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80073248:
    // 0x80073248: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x8007324C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x80073250: bnel        $v0, $at, L_80073288
    if (ctx->r2 != ctx->r1) {
        // 0x80073254: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_80073288;
    }
    goto skip_7;
    // 0x80073254: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_7:
    // 0x80073258: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8007325C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80073260: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x80073264: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80073268: addiu       $t7, $t9, 0x4
    ctx->r15 = ADD32(ctx->r25, 0X4);
    // 0x8007326C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80073270: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x80073274: sra         $t6, $t8, 31
    ctx->r14 = S32(SIGNED(ctx->r24) >> 31);
    // 0x80073278: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8007327C: b           L_800732E4
    // 0x80073280: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_800732E4;
    // 0x80073280: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80073284: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_80073288:
    // 0x80073288: bnel        $v0, $at, L_800732C0
    if (ctx->r2 != ctx->r1) {
        // 0x8007328C: lw          $t6, 0x0($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X0);
            goto L_800732C0;
    }
    goto skip_8;
    // 0x8007328C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    skip_8:
    // 0x80073290: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80073294: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80073298: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x8007329C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800732A0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800732A4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800732A8: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800732AC: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x800732B0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800732B4: b           L_800732E4
    // 0x800732B8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_800732E4;
    // 0x800732B8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800732BC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
L_800732C0:
    // 0x800732C0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800732C4: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x800732C8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800732CC: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800732D0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800732D4: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x800732D8: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800732DC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800732E0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800732E4:
    // 0x800732E4: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800732E8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800732EC: bne         $v0, $at, L_8007330C
    if (ctx->r2 != ctx->r1) {
        // 0x800732F0: nop
    
            goto L_8007330C;
    }
    // 0x800732F0: nop

    // 0x800732F4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800732F8: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800732FC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80073300: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80073304: b           L_80073324
    // 0x80073308: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_80073324;
    // 0x80073308: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_8007330C:
    // 0x8007330C: bnel        $v0, $zero, L_80073328
    if (ctx->r2 != 0) {
        // 0x80073310: lw          $t7, 0x30($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X30);
            goto L_80073328;
    }
    goto skip_9;
    // 0x80073310: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    skip_9:
    // 0x80073314: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80073318: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8007331C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80073320: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_80073324:
    // 0x80073324: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
L_80073328:
    // 0x80073328: andi        $t6, $t7, 0x8
    ctx->r14 = ctx->r15 & 0X8;
    // 0x8007332C: beql        $t6, $zero, L_80073380
    if (ctx->r14 == 0) {
        // 0x80073330: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_80073380;
    }
    goto skip_10;
    // 0x80073330: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_10:
    // 0x80073334: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80073338: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x8007333C: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80073340: addu        $t7, $a3, $t9
    ctx->r15 = ADD32(ctx->r7, ctx->r25);
    // 0x80073344: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x80073348: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8007334C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80073350: beq         $v1, $at, L_80073364
    if (ctx->r3 == ctx->r1) {
        // 0x80073354: sw          $t9, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r25;
            goto L_80073364;
    }
    // 0x80073354: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x80073358: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x8007335C: bnel        $v1, $at, L_80073380
    if (ctx->r3 != ctx->r1) {
        // 0x80073360: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_80073380;
    }
    goto skip_11;
    // 0x80073360: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_11:
L_80073364:
    // 0x80073364: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80073368: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x8007336C: sb          $a1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r5;
    // 0x80073370: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80073374: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80073378: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x8007337C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_80073380:
    // 0x80073380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80073384: addu        $t7, $t8, $a3
    ctx->r15 = ADD32(ctx->r24, ctx->r7);
    // 0x80073388: jal         0x80073CF0
    // 0x8007338C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_1;
    // 0x8007338C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_1:
    // 0x80073390: b           L_80073694
    // 0x80073394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80073694;
    // 0x80073394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80073398:
    // 0x80073398: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x8007339C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800733A0: bnel        $t6, $at, L_80073408
    if (ctx->r14 != ctx->r1) {
        // 0x800733A4: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_80073408;
    }
    goto skip_12;
    // 0x800733A4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_12:
    // 0x800733A8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800733AC: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800733B0: beq         $t9, $zero, L_800733C8
    if (ctx->r25 == 0) {
        // 0x800733B4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800733C8;
    }
    // 0x800733B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800733B8: addiu       $t8, $v1, 0x7
    ctx->r24 = ADD32(ctx->r3, 0X7);
    // 0x800733BC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800733C0: b           L_800733F8
    // 0x800733C4: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
        goto L_800733F8;
    // 0x800733C4: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
L_800733C8:
    // 0x800733C8: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x800733CC: beq         $t7, $zero, L_800733E4
    if (ctx->r15 == 0) {
        // 0x800733D0: addiu       $t9, $v0, 0x7
        ctx->r25 = ADD32(ctx->r2, 0X7);
            goto L_800733E4;
    }
    // 0x800733D0: addiu       $t9, $v0, 0x7
    ctx->r25 = ADD32(ctx->r2, 0X7);
    // 0x800733D4: addiu       $t6, $v1, 0xA
    ctx->r14 = ADD32(ctx->r3, 0XA);
    // 0x800733D8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800733DC: b           L_800733F4
    // 0x800733E0: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
        goto L_800733F4;
    // 0x800733E0: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
L_800733E4:
    // 0x800733E4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800733E8: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800733EC: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x800733F0: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_800733F4:
    // 0x800733F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800733F8:
    // 0x800733F8: ldc1        $f4, -0x8($v0)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r2, -0X8);
    // 0x800733FC: b           L_8007345C
    // 0x80073400: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
        goto L_8007345C;
    // 0x80073400: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
    // 0x80073404: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80073408:
    // 0x80073408: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8007340C: beq         $t6, $zero, L_80073424
    if (ctx->r14 == 0) {
        // 0x80073410: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80073424;
    }
    // 0x80073410: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073414: addiu       $t9, $v1, 0x7
    ctx->r25 = ADD32(ctx->r3, 0X7);
    // 0x80073418: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8007341C: b           L_80073454
    // 0x80073420: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
        goto L_80073454;
    // 0x80073420: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
L_80073424:
    // 0x80073424: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x80073428: beq         $t8, $zero, L_80073440
    if (ctx->r24 == 0) {
        // 0x8007342C: addiu       $t6, $v0, 0x7
        ctx->r14 = ADD32(ctx->r2, 0X7);
            goto L_80073440;
    }
    // 0x8007342C: addiu       $t6, $v0, 0x7
    ctx->r14 = ADD32(ctx->r2, 0X7);
    // 0x80073430: addiu       $t7, $v1, 0xA
    ctx->r15 = ADD32(ctx->r3, 0XA);
    // 0x80073434: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80073438: b           L_80073450
    // 0x8007343C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
        goto L_80073450;
    // 0x8007343C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
L_80073440:
    // 0x80073440: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80073444: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x80073448: addiu       $a0, $t9, 0x8
    ctx->r4 = ADD32(ctx->r25, 0X8);
    // 0x8007344C: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_80073450:
    // 0x80073450: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80073454:
    // 0x80073454: ldc1        $f6, -0x8($v0)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r2, -0X8);
    // 0x80073458: sdc1        $f6, 0x0($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X0, ctx->r16);
L_8007345C:
    // 0x8007345C: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x80073460: andi        $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 & 0X8000;
    // 0x80073464: beql        $t6, $zero, L_80073490
    if (ctx->r14 == 0) {
        // 0x80073468: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_80073490;
    }
    goto skip_13;
    // 0x80073468: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_13:
    // 0x8007346C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80073470: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x80073474: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x80073478: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x8007347C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80073480: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80073484: b           L_800734E0
    // 0x80073488: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_800734E0;
    // 0x80073488: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x8007348C: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_80073490:
    // 0x80073490: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x80073494: beq         $t9, $zero, L_800734BC
    if (ctx->r25 == 0) {
        // 0x80073498: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_800734BC;
    }
    // 0x80073498: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8007349C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800734A0: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x800734A4: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x800734A8: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800734AC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800734B0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800734B4: b           L_800734E0
    // 0x800734B8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_800734E0;
    // 0x800734B8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_800734BC:
    // 0x800734BC: beql        $t7, $zero, L_800734E4
    if (ctx->r15 == 0) {
        // 0x800734C0: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800734E4;
    }
    goto skip_14;
    // 0x800734C0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_14:
    // 0x800734C4: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800734C8: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800734CC: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800734D0: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800734D4: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800734D8: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800734DC: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
L_800734E0:
    // 0x800734E0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_800734E4:
    // 0x800734E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800734E8: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x800734EC: jal         0x80074500
    // 0x800734F0: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Ldtob(rdram, ctx);
        goto after_2;
    // 0x800734F0: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_2:
    // 0x800734F4: b           L_80073694
    // 0x800734F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80073694;
    // 0x800734F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800734FC:
    // 0x800734FC: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x80073500: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80073504: bnel        $v0, $at, L_80073538
    if (ctx->r2 != ctx->r1) {
        // 0x80073508: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_80073538;
    }
    goto skip_15;
    // 0x80073508: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    skip_15:
    // 0x8007350C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80073510: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80073514: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x80073518: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x8007351C: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x80073520: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80073524: lw          $t9, -0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X4);
    // 0x80073528: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8007352C: b           L_80073690
    // 0x80073530: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
        goto L_80073690;
    // 0x80073530: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x80073534: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
L_80073538:
    // 0x80073538: bnel        $v0, $at, L_8007356C
    if (ctx->r2 != ctx->r1) {
        // 0x8007353C: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_8007356C;
    }
    goto skip_16;
    // 0x8007353C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_16:
    // 0x80073540: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80073544: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80073548: addiu       $t6, $t8, 0x3
    ctx->r14 = ADD32(ctx->r24, 0X3);
    // 0x8007354C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80073550: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x80073554: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80073558: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x8007355C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80073560: b           L_80073690
    // 0x80073564: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
        goto L_80073690;
    // 0x80073564: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80073568: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_8007356C:
    // 0x8007356C: bnel        $v0, $at, L_800735A8
    if (ctx->r2 != ctx->r1) {
        // 0x80073570: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_800735A8;
    }
    goto skip_17;
    // 0x80073570: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_17:
    // 0x80073574: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80073578: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8007357C: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x80073580: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x80073584: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x80073588: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8007358C: lw          $t6, -0x4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4);
    // 0x80073590: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80073594: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80073598: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8007359C: b           L_80073690
    // 0x800735A0: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
        goto L_80073690;
    // 0x800735A0: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800735A4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_800735A8:
    // 0x800735A8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800735AC: addiu       $t8, $t7, 0x3
    ctx->r24 = ADD32(ctx->r15, 0X3);
    // 0x800735B0: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800735B4: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800735B8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800735BC: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x800735C0: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800735C4: b           L_80073690
    // 0x800735C8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_80073690;
    // 0x800735C8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_800735CC:
    // 0x800735CC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800735D0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800735D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800735D8: addiu       $t6, $t9, 0x3
    ctx->r14 = ADD32(ctx->r25, 0X3);
    // 0x800735DC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800735E0: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800735E4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800735E8: lw          $t6, -0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X4);
    // 0x800735EC: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800735F0: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x800735F4: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800735F8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800735FC: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x80073600: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80073604: jal         0x80073CF0
    // 0x80073608: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Litob(rdram, ctx);
        goto after_3;
    // 0x80073608: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_3:
    // 0x8007360C: b           L_80073694
    // 0x80073610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80073694;
    // 0x80073610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80073614:
    // 0x80073614: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80073618: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8007361C: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x80073620: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x80073624: addiu       $t6, $t7, 0x4
    ctx->r14 = ADD32(ctx->r15, 0X4);
    // 0x80073628: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8007362C: lw          $a0, -0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, -0X4);
    // 0x80073630: jal         0x8006B47C
    // 0x80073634: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    strlen_recomp(rdram, ctx);
        goto after_4;
    // 0x80073634: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    after_4:
    // 0x80073638: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8007363C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80073640: bltz        $v1, L_80073690
    if (SIGNED(ctx->r3) < 0) {
        // 0x80073644: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80073690;
    }
    // 0x80073644: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80073648: beql        $at, $zero, L_80073694
    if (ctx->r1 == 0) {
        // 0x8007364C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80073694;
    }
    goto skip_18;
    // 0x8007364C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_18:
    // 0x80073650: b           L_80073690
    // 0x80073654: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
        goto L_80073690;
    // 0x80073654: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x80073658: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_8007365C:
    // 0x8007365C: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x80073660: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x80073664: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x80073668: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8007366C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80073670: b           L_80073690
    // 0x80073674: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_80073690;
    // 0x80073674: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_80073678:
    // 0x80073678: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_8007367C:
    // 0x8007367C: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x80073680: sb          $a1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r5;
    // 0x80073684: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80073688: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8007368C: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_80073690:
    // 0x80073690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80073694:
    // 0x80073694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073698: jr          $ra
    // 0x8007369C: nop

    return;
    // 0x8007369C: nop

;}
RECOMP_FUNC void _Printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800736A0: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x800736A4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800736A8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800736AC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800736B0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800736B4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800736B8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800736BC: sw          $a3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r7;
    // 0x800736C0: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x800736C4: lui         $s6, 0x800C
    ctx->r22 = S32(0X800C << 16);
    // 0x800736C8: lui         $s7, 0x8008
    ctx->r23 = S32(0X8008 << 16);
    // 0x800736CC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800736D0: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800736D4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800736D8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800736DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800736E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800736E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800736E8: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x800736EC: sw          $zero, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = 0;
    // 0x800736F0: addiu       $s7, $s7, 0x6CB0
    ctx->r23 = ADD32(ctx->r23, 0X6CB0);
    // 0x800736F4: addiu       $s6, $s6, -0x231C
    ctx->r22 = ADD32(ctx->r22, -0X231C);
    // 0x800736F8: addiu       $s5, $s5, 0x6CD4
    ctx->r21 = ADD32(ctx->r21, 0X6CD4);
    // 0x800736FC: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
L_80073700:
    // 0x80073700: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80073704: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80073708: addiu       $v1, $zero, 0x25
    ctx->r3 = ADD32(0, 0X25);
    // 0x8007370C: beq         $v0, $zero, L_80073734
    if (ctx->r2 == 0) {
        // 0x80073710: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80073734;
    }
    // 0x80073710: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80073714: beql        $v1, $v0, L_80073738
    if (ctx->r3 == ctx->r2) {
        // 0x80073718: subu        $v0, $s2, $a3
        ctx->r2 = SUB32(ctx->r18, ctx->r7);
            goto L_80073738;
    }
    goto skip_0;
    // 0x80073718: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
    skip_0:
    // 0x8007371C: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
L_80073720:
    // 0x80073720: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80073724: beq         $v0, $zero, L_80073734
    if (ctx->r2 == 0) {
        // 0x80073728: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80073734;
    }
    // 0x80073728: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007372C: bnel        $v1, $v0, L_80073720
    if (ctx->r3 != ctx->r2) {
        // 0x80073730: lbu         $v0, 0x1($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X1);
            goto L_80073720;
    }
    goto skip_1;
    // 0x80073730: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    skip_1:
L_80073734:
    // 0x80073734: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
L_80073738:
    // 0x80073738: blez        $v0, L_80073770
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007373C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80073770;
    }
    // 0x8007373C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80073740: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80073744: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80073748: jalr        $s4
    // 0x8007374C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x8007374C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_0:
    // 0x80073750: beq         $v0, $zero, L_80073768
    if (ctx->r2 == 0) {
        // 0x80073754: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80073768;
    }
    // 0x80073754: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80073758: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8007375C: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80073760: b           L_80073770
    // 0x80073764: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_80073770;
    // 0x80073764: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_80073768:
    // 0x80073768: b           L_80073CB8
    // 0x8007376C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80073CB8;
    // 0x8007376C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80073770:
    // 0x80073770: bne         $s0, $zero, L_80073780
    if (ctx->r16 != 0) {
        // 0x80073774: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80073780;
    }
    // 0x80073774: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80073778: b           L_80073CB8
    // 0x8007377C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80073CB8;
    // 0x8007377C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80073780:
    // 0x80073780: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
    // 0x80073784: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x80073788: jal         0x8006B4A4
    // 0x8007378C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    strchr_recomp(rdram, ctx);
        goto after_1;
    // 0x8007378C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x80073790: beq         $v0, $zero, L_800737D0
    if (ctx->r2 == 0) {
        // 0x80073794: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800737D0;
    }
    // 0x80073794: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80073798:
    // 0x80073798: subu        $t9, $s0, $s6
    ctx->r25 = SUB32(ctx->r16, ctx->r22);
    // 0x8007379C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800737A0: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x800737A4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800737A8: lw          $t7, -0x2314($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2314);
    // 0x800737AC: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800737B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800737B4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800737B8: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800737BC: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x800737C0: jal         0x8006B4A4
    // 0x800737C4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    strchr_recomp(rdram, ctx);
        goto after_2;
    // 0x800737C4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_2:
    // 0x800737C8: bne         $v0, $zero, L_80073798
    if (ctx->r2 != 0) {
        // 0x800737CC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80073798;
    }
    // 0x800737CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800737D0:
    // 0x800737D0: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x800737D4: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x800737D8: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x800737DC: bne         $v0, $t6, L_80073824
    if (ctx->r2 != ctx->r14) {
        // 0x800737E0: lui         $a0, 0x800C
        ctx->r4 = S32(0X800C << 16);
            goto L_80073824;
    }
    // 0x800737E0: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800737E4: addiu       $t7, $t8, 0x3
    ctx->r15 = ADD32(ctx->r24, 0X3);
    // 0x800737E8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800737EC: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x800737F0: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800737F4: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x800737F8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800737FC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80073800: bgez        $t8, L_8007381C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80073804: sw          $t8, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r24;
            goto L_8007381C;
    }
    // 0x80073804: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80073808: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x8007380C: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x80073810: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x80073814: ori         $t9, $t6, 0x4
    ctx->r25 = ctx->r14 | 0X4;
    // 0x80073818: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
L_8007381C:
    // 0x8007381C: b           L_80073880
    // 0x80073820: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_80073880;
    // 0x80073820: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_80073824:
    // 0x80073824: sw          $zero, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = 0;
    // 0x80073828: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x8007382C: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x80073830: bne         $at, $zero, L_80073880
    if (ctx->r1 != 0) {
        // 0x80073834: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_80073880;
    }
    // 0x80073834: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80073838: beql        $at, $zero, L_80073884
    if (ctx->r1 == 0) {
        // 0x8007383C: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80073884;
    }
    goto skip_2;
    // 0x8007383C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_2:
    // 0x80073840: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
L_80073844:
    // 0x80073844: slti        $at, $t8, 0x3E7
    ctx->r1 = SIGNED(ctx->r24) < 0X3E7 ? 1 : 0;
    // 0x80073848: beql        $at, $zero, L_80073868
    if (ctx->r1 == 0) {
        // 0x8007384C: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_80073868;
    }
    goto skip_3;
    // 0x8007384C: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_3:
    // 0x80073850: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80073854: mflo        $t7
    ctx->r15 = lo;
    // 0x80073858: addu        $t6, $a1, $t7
    ctx->r14 = ADD32(ctx->r5, ctx->r15);
    // 0x8007385C: addiu       $t9, $t6, -0x30
    ctx->r25 = ADD32(ctx->r14, -0X30);
    // 0x80073860: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x80073864: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_80073868:
    // 0x80073868: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007386C: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x80073870: bne         $at, $zero, L_80073880
    if (ctx->r1 != 0) {
        // 0x80073874: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_80073880;
    }
    // 0x80073874: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80073878: bnel        $at, $zero, L_80073844
    if (ctx->r1 != 0) {
        // 0x8007387C: lw          $t8, 0xC8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC8);
            goto L_80073844;
    }
    goto skip_4;
    // 0x8007387C: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    skip_4:
L_80073880:
    // 0x80073880: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_80073884:
    // 0x80073884: beq         $a1, $at, L_80073898
    if (ctx->r5 == ctx->r1) {
        // 0x80073888: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_80073898;
    }
    // 0x80073888: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8007388C: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x80073890: b           L_8007392C
    // 0x80073894: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_8007392C;
    // 0x80073894: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_80073898:
    // 0x80073898: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x8007389C: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x800738A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800738A4: bne         $v0, $t7, L_800738D0
    if (ctx->r2 != ctx->r15) {
        // 0x800738A8: addiu       $t9, $t6, 0x3
        ctx->r25 = ADD32(ctx->r14, 0X3);
            goto L_800738D0;
    }
    // 0x800738A8: addiu       $t9, $t6, 0x3
    ctx->r25 = ADD32(ctx->r14, 0X3);
    // 0x800738AC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800738B0: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800738B4: addiu       $t7, $t8, 0x4
    ctx->r15 = ADD32(ctx->r24, 0X4);
    // 0x800738B8: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x800738BC: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800738C0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800738C4: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800738C8: b           L_8007392C
    // 0x800738CC: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_8007392C;
    // 0x800738CC: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800738D0:
    // 0x800738D0: sw          $zero, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = 0;
    // 0x800738D4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800738D8: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800738DC: bne         $at, $zero, L_8007392C
    if (ctx->r1 != 0) {
        // 0x800738E0: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_8007392C;
    }
    // 0x800738E0: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800738E4: beq         $at, $zero, L_8007392C
    if (ctx->r1 == 0) {
        // 0x800738E8: nop
    
            goto L_8007392C;
    }
    // 0x800738E8: nop

    // 0x800738EC: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
L_800738F0:
    // 0x800738F0: slti        $at, $t9, 0x3E7
    ctx->r1 = SIGNED(ctx->r25) < 0X3E7 ? 1 : 0;
    // 0x800738F4: beql        $at, $zero, L_80073914
    if (ctx->r1 == 0) {
        // 0x800738F8: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_80073914;
    }
    goto skip_5;
    // 0x800738F8: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_5:
    // 0x800738FC: multu       $t9, $fp
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80073900: mflo        $t7
    ctx->r15 = lo;
    // 0x80073904: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x80073908: addiu       $t6, $t8, -0x30
    ctx->r14 = ADD32(ctx->r24, -0X30);
    // 0x8007390C: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x80073910: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_80073914:
    // 0x80073914: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80073918: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x8007391C: bne         $at, $zero, L_8007392C
    if (ctx->r1 != 0) {
        // 0x80073920: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_8007392C;
    }
    // 0x80073920: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80073924: bnel        $at, $zero, L_800738F0
    if (ctx->r1 != 0) {
        // 0x80073928: lw          $t9, 0xC4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC4);
            goto L_800738F0;
    }
    goto skip_6;
    // 0x80073928: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    skip_6:
L_8007392C:
    // 0x8007392C: jal         0x8006B4A4
    // 0x80073930: addiu       $a0, $a0, -0x2320
    ctx->r4 = ADD32(ctx->r4, -0X2320);
    strchr_recomp(rdram, ctx);
        goto after_3;
    // 0x80073930: addiu       $a0, $a0, -0x2320
    ctx->r4 = ADD32(ctx->r4, -0X2320);
    after_3:
    // 0x80073934: beq         $v0, $zero, L_8007394C
    if (ctx->r2 == 0) {
        // 0x80073938: addiu       $s0, $sp, 0xA0
        ctx->r16 = ADD32(ctx->r29, 0XA0);
            goto L_8007394C;
    }
    // 0x80073938: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
    // 0x8007393C: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x80073940: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80073944: b           L_80073950
    // 0x80073948: sb          $t9, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r25;
        goto L_80073950;
    // 0x80073948: sb          $t9, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r25;
L_8007394C:
    // 0x8007394C: sb          $zero, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = 0;
L_80073950:
    // 0x80073950: lbu         $t7, 0xD4($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD4);
    // 0x80073954: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x80073958: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x8007395C: bne         $v0, $t7, L_8007397C
    if (ctx->r2 != ctx->r15) {
        // 0x80073960: addiu       $a3, $sp, 0x74
        ctx->r7 = ADD32(ctx->r29, 0X74);
            goto L_8007397C;
    }
    // 0x80073960: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    // 0x80073964: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x80073968: addiu       $t6, $zero, 0x4C
    ctx->r14 = ADD32(0, 0X4C);
    // 0x8007396C: bne         $v0, $t8, L_8007397C
    if (ctx->r2 != ctx->r24) {
        // 0x80073970: nop
    
            goto L_8007397C;
    }
    // 0x80073970: nop

    // 0x80073974: sb          $t6, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r14;
    // 0x80073978: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8007397C:
    // 0x8007397C: jal         0x80073030
    // 0x80073980: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    func_80073030(rdram, ctx);
        goto after_4;
    // 0x80073980: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_4:
    // 0x80073984: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x80073988: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8007398C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80073990: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x80073994: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x80073998: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x8007399C: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800739A0: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800739A4: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800739A8: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800739AC: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800739B0: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800739B4: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x800739B8: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800739BC: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x800739C0: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x800739C4: bne         $t8, $zero, L_80073A30
    if (ctx->r24 != 0) {
        // 0x800739C8: slt         $t6, $zero, $t9
        ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_80073A30;
    }
    // 0x800739C8: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800739CC: beql        $t6, $zero, L_80073A34
    if (ctx->r14 == 0) {
        // 0x800739D0: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_80073A34;
    }
    goto skip_7;
    // 0x800739D0: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    skip_7:
    // 0x800739D4: beq         $t6, $zero, L_80073A30
    if (ctx->r14 == 0) {
        // 0x800739D8: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_80073A30;
    }
    // 0x800739D8: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800739DC: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800739E0:
    // 0x800739E0: bne         $at, $zero, L_800739F0
    if (ctx->r1 != 0) {
        // 0x800739E4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800739F0;
    }
    // 0x800739E4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800739E8: b           L_800739F0
    // 0x800739EC: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800739F0;
    // 0x800739EC: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800739F0:
    // 0x800739F0: blez        $s0, L_80073A24
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800739F4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80073A24;
    }
    // 0x800739F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800739F8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800739FC: jalr        $s4
    // 0x80073A00: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_5;
    // 0x80073A00: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x80073A04: beq         $v0, $zero, L_80073A1C
    if (ctx->r2 == 0) {
        // 0x80073A08: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80073A1C;
    }
    // 0x80073A08: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80073A0C: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x80073A10: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80073A14: b           L_80073A24
    // 0x80073A18: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80073A24;
    // 0x80073A18: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80073A1C:
    // 0x80073A1C: b           L_80073CB8
    // 0x80073A20: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80073CB8;
    // 0x80073A20: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80073A24:
    // 0x80073A24: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80073A28: bgtzl       $s1, L_800739E0
    if (SIGNED(ctx->r17) > 0) {
        // 0x80073A2C: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800739E0;
    }
    goto skip_8;
    // 0x80073A2C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_8:
L_80073A30:
    // 0x80073A30: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
L_80073A34:
    // 0x80073A34: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80073A38: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80073A3C: blezl       $t9, L_80073A74
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80073A40: lw          $t9, 0xB0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB0);
            goto L_80073A74;
    }
    goto skip_9;
    // 0x80073A40: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    skip_9:
    // 0x80073A44: jalr        $s4
    // 0x80073A48: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_6;
    // 0x80073A48: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_6:
    // 0x80073A4C: beq         $v0, $zero, L_80073A68
    if (ctx->r2 == 0) {
        // 0x80073A50: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80073A68;
    }
    // 0x80073A50: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80073A54: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x80073A58: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80073A5C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80073A60: b           L_80073A70
    // 0x80073A64: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80073A70;
    // 0x80073A64: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80073A68:
    // 0x80073A68: b           L_80073CB8
    // 0x80073A6C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80073CB8;
    // 0x80073A6C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80073A70:
    // 0x80073A70: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
L_80073A74:
    // 0x80073A74: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80073A78: beql        $t6, $zero, L_80073AE0
    if (ctx->r14 == 0) {
        // 0x80073A7C: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_80073AE0;
    }
    goto skip_10;
    // 0x80073A7C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_10:
    // 0x80073A80: beq         $t6, $zero, L_80073ADC
    if (ctx->r14 == 0) {
        // 0x80073A84: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_80073ADC;
    }
    // 0x80073A84: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80073A88: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80073A8C:
    // 0x80073A8C: bne         $at, $zero, L_80073A9C
    if (ctx->r1 != 0) {
        // 0x80073A90: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80073A9C;
    }
    // 0x80073A90: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80073A94: b           L_80073A9C
    // 0x80073A98: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80073A9C;
    // 0x80073A98: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80073A9C:
    // 0x80073A9C: blez        $s0, L_80073AD0
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80073AA0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80073AD0;
    }
    // 0x80073AA0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80073AA4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80073AA8: jalr        $s4
    // 0x80073AAC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_7;
    // 0x80073AAC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80073AB0: beq         $v0, $zero, L_80073AC8
    if (ctx->r2 == 0) {
        // 0x80073AB4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80073AC8;
    }
    // 0x80073AB4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80073AB8: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x80073ABC: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80073AC0: b           L_80073AD0
    // 0x80073AC4: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80073AD0;
    // 0x80073AC4: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80073AC8:
    // 0x80073AC8: b           L_80073CB8
    // 0x80073ACC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80073CB8;
    // 0x80073ACC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80073AD0:
    // 0x80073AD0: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80073AD4: bgtzl       $s1, L_80073A8C
    if (SIGNED(ctx->r17) > 0) {
        // 0x80073AD8: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80073A8C;
    }
    goto skip_11;
    // 0x80073AD8: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_11:
L_80073ADC:
    // 0x80073ADC: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_80073AE0:
    // 0x80073AE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80073AE4: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x80073AE8: blezl       $t9, L_80073B20
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80073AEC: lw          $t9, 0xB8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB8);
            goto L_80073B20;
    }
    goto skip_12;
    // 0x80073AEC: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    skip_12:
    // 0x80073AF0: jalr        $s4
    // 0x80073AF4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_8;
    // 0x80073AF4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_8:
    // 0x80073AF8: beq         $v0, $zero, L_80073B14
    if (ctx->r2 == 0) {
        // 0x80073AFC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80073B14;
    }
    // 0x80073AFC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80073B00: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x80073B04: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x80073B08: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80073B0C: b           L_80073B1C
    // 0x80073B10: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80073B1C;
    // 0x80073B10: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80073B14:
    // 0x80073B14: b           L_80073CB8
    // 0x80073B18: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80073CB8;
    // 0x80073B18: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80073B1C:
    // 0x80073B1C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
L_80073B20:
    // 0x80073B20: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80073B24: beql        $t6, $zero, L_80073B8C
    if (ctx->r14 == 0) {
        // 0x80073B28: lw          $t9, 0xBC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XBC);
            goto L_80073B8C;
    }
    goto skip_13;
    // 0x80073B28: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    skip_13:
    // 0x80073B2C: beq         $t6, $zero, L_80073B88
    if (ctx->r14 == 0) {
        // 0x80073B30: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_80073B88;
    }
    // 0x80073B30: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80073B34: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80073B38:
    // 0x80073B38: bne         $at, $zero, L_80073B48
    if (ctx->r1 != 0) {
        // 0x80073B3C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80073B48;
    }
    // 0x80073B3C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80073B40: b           L_80073B48
    // 0x80073B44: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80073B48;
    // 0x80073B44: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80073B48:
    // 0x80073B48: blez        $s0, L_80073B7C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80073B4C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80073B7C;
    }
    // 0x80073B4C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80073B50: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80073B54: jalr        $s4
    // 0x80073B58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_9;
    // 0x80073B58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x80073B5C: beq         $v0, $zero, L_80073B74
    if (ctx->r2 == 0) {
        // 0x80073B60: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80073B74;
    }
    // 0x80073B60: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80073B64: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x80073B68: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80073B6C: b           L_80073B7C
    // 0x80073B70: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80073B7C;
    // 0x80073B70: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80073B74:
    // 0x80073B74: b           L_80073CB8
    // 0x80073B78: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80073CB8;
    // 0x80073B78: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80073B7C:
    // 0x80073B7C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80073B80: bgtzl       $s1, L_80073B38
    if (SIGNED(ctx->r17) > 0) {
        // 0x80073B84: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80073B38;
    }
    goto skip_14;
    // 0x80073B84: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_14:
L_80073B88:
    // 0x80073B88: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
L_80073B8C:
    // 0x80073B8C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80073B90: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80073B94: blez        $t9, L_80073BCC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80073B98: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_80073BCC;
    }
    // 0x80073B98: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x80073B9C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80073BA0: jalr        $s4
    // 0x80073BA4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_10;
    // 0x80073BA4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_10:
    // 0x80073BA8: beq         $v0, $zero, L_80073BC4
    if (ctx->r2 == 0) {
        // 0x80073BAC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80073BC4;
    }
    // 0x80073BAC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80073BB0: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x80073BB4: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x80073BB8: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80073BBC: b           L_80073BCC
    // 0x80073BC0: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_80073BCC;
    // 0x80073BC0: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_80073BC4:
    // 0x80073BC4: b           L_80073CB8
    // 0x80073BC8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80073CB8;
    // 0x80073BC8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80073BCC:
    // 0x80073BCC: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x80073BD0: slt         $t8, $zero, $t9
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80073BD4: beql        $t8, $zero, L_80073C3C
    if (ctx->r24 == 0) {
        // 0x80073BD8: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_80073C3C;
    }
    goto skip_15;
    // 0x80073BD8: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    skip_15:
    // 0x80073BDC: beq         $t8, $zero, L_80073C38
    if (ctx->r24 == 0) {
        // 0x80073BE0: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_80073C38;
    }
    // 0x80073BE0: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80073BE4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80073BE8:
    // 0x80073BE8: bne         $at, $zero, L_80073BF8
    if (ctx->r1 != 0) {
        // 0x80073BEC: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80073BF8;
    }
    // 0x80073BEC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80073BF0: b           L_80073BF8
    // 0x80073BF4: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80073BF8;
    // 0x80073BF4: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80073BF8:
    // 0x80073BF8: blez        $s0, L_80073C2C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80073BFC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80073C2C;
    }
    // 0x80073BFC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80073C00: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80073C04: jalr        $s4
    // 0x80073C08: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_11;
    // 0x80073C08: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x80073C0C: beq         $v0, $zero, L_80073C24
    if (ctx->r2 == 0) {
        // 0x80073C10: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80073C24;
    }
    // 0x80073C10: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80073C14: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x80073C18: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80073C1C: b           L_80073C2C
    // 0x80073C20: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_80073C2C;
    // 0x80073C20: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_80073C24:
    // 0x80073C24: b           L_80073CB8
    // 0x80073C28: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80073CB8;
    // 0x80073C28: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80073C2C:
    // 0x80073C2C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80073C30: bgtzl       $s1, L_80073BE8
    if (SIGNED(ctx->r17) > 0) {
        // 0x80073C34: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80073BE8;
    }
    goto skip_16;
    // 0x80073C34: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_16:
L_80073C38:
    // 0x80073C38: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
L_80073C3C:
    // 0x80073C3C: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80073C40: andi        $t8, $t9, 0x4
    ctx->r24 = ctx->r25 & 0X4;
    // 0x80073C44: beq         $t8, $zero, L_80073CB0
    if (ctx->r24 == 0) {
        // 0x80073C48: slt         $t7, $zero, $t6
        ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_80073CB0;
    }
    // 0x80073C48: slt         $t7, $zero, $t6
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80073C4C: beq         $t7, $zero, L_80073CB0
    if (ctx->r15 == 0) {
        // 0x80073C50: nop
    
            goto L_80073CB0;
    }
    // 0x80073C50: nop

    // 0x80073C54: beq         $t7, $zero, L_80073CB0
    if (ctx->r15 == 0) {
        // 0x80073C58: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_80073CB0;
    }
    // 0x80073C58: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80073C5C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80073C60:
    // 0x80073C60: bne         $at, $zero, L_80073C70
    if (ctx->r1 != 0) {
        // 0x80073C64: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80073C70;
    }
    // 0x80073C64: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80073C68: b           L_80073C70
    // 0x80073C6C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80073C70;
    // 0x80073C6C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80073C70:
    // 0x80073C70: blez        $s0, L_80073CA4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80073C74: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80073CA4;
    }
    // 0x80073C74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80073C78: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80073C7C: jalr        $s4
    // 0x80073C80: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_12;
    // 0x80073C80: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x80073C84: beq         $v0, $zero, L_80073C9C
    if (ctx->r2 == 0) {
        // 0x80073C88: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80073C9C;
    }
    // 0x80073C88: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80073C8C: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x80073C90: addu        $t8, $t9, $s0
    ctx->r24 = ADD32(ctx->r25, ctx->r16);
    // 0x80073C94: b           L_80073CA4
    // 0x80073C98: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80073CA4;
    // 0x80073C98: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80073C9C:
    // 0x80073C9C: b           L_80073CB8
    // 0x80073CA0: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80073CB8;
    // 0x80073CA0: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80073CA4:
    // 0x80073CA4: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80073CA8: bgtzl       $s1, L_80073C60
    if (SIGNED(ctx->r17) > 0) {
        // 0x80073CAC: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80073C60;
    }
    goto skip_17;
    // 0x80073CAC: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_17:
L_80073CB0:
    // 0x80073CB0: b           L_80073700
    // 0x80073CB4: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
        goto L_80073700;
    // 0x80073CB4: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
L_80073CB8:
    // 0x80073CB8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80073CBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80073CC0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80073CC4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80073CC8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80073CCC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80073CD0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80073CD4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80073CD8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80073CDC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80073CE0: jr          $ra
    // 0x80073CE4: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x80073CE4: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x80073CE8: nop

    // 0x80073CEC: nop

;}
RECOMP_FUNC void _Litob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80073CF0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80073CF4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80073CF8: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80073CFC: addiu       $v1, $zero, 0x58
    ctx->r3 = ADD32(0, 0X58);
    // 0x80073D00: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80073D04: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80073D08: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80073D0C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80073D10: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80073D14: bne         $v1, $v0, L_80073D28
    if (ctx->r3 != ctx->r2) {
        // 0x80073D18: sw          $a1, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r5;
            goto L_80073D28;
    }
    // 0x80073D18: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80073D1C: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80073D20: b           L_80073D30
    // 0x80073D24: addiu       $s3, $s3, 0x6D14
    ctx->r19 = ADD32(ctx->r19, 0X6D14);
        goto L_80073D30;
    // 0x80073D24: addiu       $s3, $s3, 0x6D14
    ctx->r19 = ADD32(ctx->r19, 0X6D14);
L_80073D28:
    // 0x80073D28: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80073D2C: addiu       $s3, $s3, 0x6D00
    ctx->r19 = ADD32(ctx->r19, 0X6D00);
L_80073D30:
    // 0x80073D30: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x80073D34: bne         $v0, $at, L_80073D44
    if (ctx->r2 != ctx->r1) {
        // 0x80073D38: addiu       $s0, $zero, 0x18
        ctx->r16 = ADD32(0, 0X18);
            goto L_80073D44;
    }
    // 0x80073D38: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x80073D3C: b           L_80073D64
    // 0x80073D40: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
        goto L_80073D64;
    // 0x80073D40: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_80073D44:
    // 0x80073D44: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80073D48: beq         $v0, $at, L_80073D60
    if (ctx->r2 == ctx->r1) {
        // 0x80073D4C: addiu       $t0, $zero, 0x10
        ctx->r8 = ADD32(0, 0X10);
            goto L_80073D60;
    }
    // 0x80073D4C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80073D50: beq         $v1, $v0, L_80073D60
    if (ctx->r3 == ctx->r2) {
        // 0x80073D54: nop
    
            goto L_80073D60;
    }
    // 0x80073D54: nop

    // 0x80073D58: b           L_80073D60
    // 0x80073D5C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
        goto L_80073D60;
    // 0x80073D5C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_80073D60:
    // 0x80073D60: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_80073D64:
    // 0x80073D64: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80073D68: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80073D6C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80073D70: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80073D74: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80073D78: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80073D7C: beq         $v0, $at, L_80073D90
    if (ctx->r2 == ctx->r1) {
        // 0x80073D80: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_80073D90;
    }
    // 0x80073D80: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80073D84: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x80073D88: bnel        $v0, $at, L_80073DCC
    if (ctx->r2 != ctx->r1) {
        // 0x80073D8C: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_80073DCC;
    }
    goto skip_0;
    // 0x80073D8C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_0:
L_80073D90:
    // 0x80073D90: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80073D94: bgtzl       $t4, L_80073DCC
    if (SIGNED(ctx->r12) > 0) {
        // 0x80073D98: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_80073DCC;
    }
    goto skip_1;
    // 0x80073D98: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x80073D9C: bltz        $t4, L_80073DAC
    if (SIGNED(ctx->r12) < 0) {
        // 0x80073DA0: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_80073DAC;
    }
    // 0x80073DA0: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80073DA4: b           L_80073DCC
    // 0x80073DA8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
        goto L_80073DCC;
    // 0x80073DA8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_80073DAC:
    // 0x80073DAC: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80073DB0: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x80073DB4: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073DB8: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x80073DBC: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x80073DC0: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80073DC4: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80073DC8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_80073DCC:
    // 0x80073DCC: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80073DD0: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x80073DD4: bne         $t2, $zero, L_80073DF0
    if (ctx->r10 != 0) {
        // 0x80073DD8: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80073DF0;
    }
    // 0x80073DD8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80073DDC: bnel        $t3, $zero, L_80073DF4
    if (ctx->r11 != 0) {
        // 0x80073DE0: addiu       $s0, $zero, 0x17
        ctx->r16 = ADD32(0, 0X17);
            goto L_80073DF4;
    }
    goto skip_2;
    // 0x80073DE0: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
    skip_2:
    // 0x80073DE4: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x80073DE8: beql        $t4, $zero, L_80073E2C
    if (ctx->r12 == 0) {
        // 0x80073DEC: addiu       $s2, $sp, 0x78
        ctx->r18 = ADD32(ctx->r29, 0X78);
            goto L_80073E2C;
    }
    goto skip_3;
    // 0x80073DEC: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    skip_3:
L_80073DF0:
    // 0x80073DF0: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
L_80073DF4:
    // 0x80073DF4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80073DF8: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80073DFC: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80073E00: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80073E04: jal         0x8006A74C
    // 0x80073E08: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x80073E08: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_0:
    // 0x80073E0C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80073E10: addu        $t6, $v1, $s3
    ctx->r14 = ADD32(ctx->r3, ctx->r19);
    // 0x80073E14: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80073E18: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x80073E1C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80073E20: addu        $t8, $s2, $t0
    ctx->r24 = ADD32(ctx->r18, ctx->r8);
    // 0x80073E24: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80073E28: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
L_80073E2C:
    // 0x80073E2C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80073E30: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80073E34: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80073E38: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80073E3C: jal         0x8006A788
    // 0x80073E40: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80073E40: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_1:
    // 0x80073E44: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80073E48: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x80073E4C: bltz        $v0, L_80073EFC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80073E50: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_80073EFC;
    }
    // 0x80073E50: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80073E54: bgtz        $v0, L_80073E64
    if (SIGNED(ctx->r2) > 0) {
        // 0x80073E58: nop
    
            goto L_80073E64;
    }
    // 0x80073E58: nop

    // 0x80073E5C: beql        $v1, $zero, L_80073F00
    if (ctx->r3 == 0) {
        // 0x80073E60: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_80073F00;
    }
    goto skip_4;
    // 0x80073E60: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_4:
L_80073E64:
    // 0x80073E64: blez        $s0, L_80073EFC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80073E68: sra         $t4, $t1, 31
        ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
            goto L_80073EFC;
    }
    // 0x80073E68: sra         $t4, $t1, 31
    ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80073E6C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80073E70: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x80073E74: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80073E78: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80073E7C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80073E80: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80073E84: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_80073E88:
    // 0x80073E88: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80073E8C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80073E90: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80073E94: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80073E98: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80073E9C: jal         0x80074A50
    // 0x80073EA0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    lldiv_recomp(rdram, ctx);
        goto after_2;
    // 0x80073EA0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x80073EA4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80073EA8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80073EAC: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x80073EB0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80073EB4: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x80073EB8: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80073EBC: addu        $t7, $s2, $a0
    ctx->r15 = ADD32(ctx->r18, ctx->r4);
    // 0x80073EC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80073EC4: addu        $t5, $t3, $s3
    ctx->r13 = ADD32(ctx->r11, ctx->r19);
    // 0x80073EC8: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x80073ECC: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80073ED0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80073ED4: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80073ED8: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80073EDC: bltz        $t8, L_80073EFC
    if (SIGNED(ctx->r24) < 0) {
        // 0x80073EE0: sw          $t9, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r25;
            goto L_80073EFC;
    }
    // 0x80073EE0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80073EE4: bgtz        $t8, L_80073EF4
    if (SIGNED(ctx->r24) > 0) {
        // 0x80073EE8: nop
    
            goto L_80073EF4;
    }
    // 0x80073EE8: nop

    // 0x80073EEC: beql        $t9, $zero, L_80073F00
    if (ctx->r25 == 0) {
        // 0x80073EF0: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_80073F00;
    }
    goto skip_5;
    // 0x80073EF0: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_5:
L_80073EF4:
    // 0x80073EF4: bgtzl       $s0, L_80073E88
    if (SIGNED(ctx->r16) > 0) {
        // 0x80073EF8: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80073E88;
    }
    goto skip_6;
    // 0x80073EF8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_6:
L_80073EFC:
    // 0x80073EFC: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
L_80073F00:
    // 0x80073F00: subu        $a2, $t4, $s0
    ctx->r6 = SUB32(ctx->r12, ctx->r16);
    // 0x80073F04: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x80073F08: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x80073F0C: jal         0x8006B450
    // 0x80073F10: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x80073F10: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    after_3:
    // 0x80073F14: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x80073F18: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x80073F1C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80073F20: beq         $at, $zero, L_80073F2C
    if (ctx->r1 == 0) {
        // 0x80073F24: subu        $t5, $a0, $a1
        ctx->r13 = SUB32(ctx->r4, ctx->r5);
            goto L_80073F2C;
    }
    // 0x80073F24: subu        $t5, $a0, $a1
    ctx->r13 = SUB32(ctx->r4, ctx->r5);
    // 0x80073F28: sw          $t5, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r13;
L_80073F2C:
    // 0x80073F2C: bgezl       $a0, L_80073F70
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80073F30: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80073F70;
    }
    goto skip_7;
    // 0x80073F30: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x80073F34: lw          $t6, 0x30($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X30);
    // 0x80073F38: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80073F3C: andi        $t7, $t6, 0x14
    ctx->r15 = ctx->r14 & 0X14;
    // 0x80073F40: bnel        $t7, $at, L_80073F70
    if (ctx->r15 != ctx->r1) {
        // 0x80073F44: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80073F70;
    }
    goto skip_8;
    // 0x80073F44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x80073F48: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x80073F4C: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x80073F50: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x80073F54: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x80073F58: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x80073F5C: subu        $s0, $t3, $a1
    ctx->r16 = SUB32(ctx->r11, ctx->r5);
    // 0x80073F60: blez        $s0, L_80073F6C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80073F64: addu        $t4, $v0, $s0
        ctx->r12 = ADD32(ctx->r2, ctx->r16);
            goto L_80073F6C;
    }
    // 0x80073F64: addu        $t4, $v0, $s0
    ctx->r12 = ADD32(ctx->r2, ctx->r16);
    // 0x80073F68: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
L_80073F6C:
    // 0x80073F6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80073F70:
    // 0x80073F70: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80073F74: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80073F78: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80073F7C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80073F80: jr          $ra
    // 0x80073F84: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80073F84: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80073F88: nop

    // 0x80073F8C: nop

;}
RECOMP_FUNC void func_80073F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80073F90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073F94: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80073F98: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80073F9C: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80073FA0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80073FA4: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x80073FA8: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80073FAC: andi        $t6, $s4, 0xFF
    ctx->r14 = ctx->r20 & 0XFF;
    // 0x80073FB0: sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // 0x80073FB4: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x80073FB8: bgtz        $s3, L_80073FCC
    if (SIGNED(ctx->r19) > 0) {
        // 0x80073FBC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80073FCC;
    }
    // 0x80073FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073FC0: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x80073FC4: addiu       $s1, $s1, -0x21D0
    ctx->r17 = ADD32(ctx->r17, -0X21D0);
    // 0x80073FC8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80073FCC:
    // 0x80073FCC: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x80073FD0: beq         $v0, $s4, L_80074004
    if (ctx->r2 == ctx->r20) {
        // 0x80073FD4: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_80074004;
    }
    // 0x80073FD4: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x80073FD8: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x80073FDC: beq         $a0, $v1, L_80073FE8
    if (ctx->r4 == ctx->r3) {
        // 0x80073FE0: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_80073FE8;
    }
    // 0x80073FE0: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80073FE4: bne         $v1, $at, L_80074240
    if (ctx->r3 != ctx->r1) {
        // 0x80073FE8: slti        $at, $s2, -0x4
        ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
            goto L_80074240;
    }
L_80073FE8:
    // 0x80073FE8: slti        $at, $s2, -0x4
    ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
    // 0x80073FEC: bne         $at, $zero, L_80074240
    if (ctx->r1 != 0) {
        // 0x80073FF0: nop
    
            goto L_80074240;
    }
    // 0x80073FF0: nop

    // 0x80073FF4: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80073FF8: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80073FFC: beq         $at, $zero, L_80074240
    if (ctx->r1 == 0) {
        // 0x80074000: nop
    
            goto L_80074240;
    }
    // 0x80074000: nop

L_80074004:
    // 0x80074004: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80074008: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x8007400C: beq         $v0, $v1, L_80074048
    if (ctx->r2 == ctx->r3) {
        // 0x80074010: sra         $s2, $t8, 16
        ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
            goto L_80074048;
    }
    // 0x80074010: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80074014: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x80074018: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8007401C: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80074020: bne         $t7, $zero, L_80074038
    if (ctx->r15 != 0) {
        // 0x80074024: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80074038;
    }
    // 0x80074024: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80074028: beql        $at, $zero, L_8007403C
    if (ctx->r1 == 0) {
        // 0x8007402C: subu        $t8, $v0, $s2
        ctx->r24 = SUB32(ctx->r2, ctx->r18);
            goto L_8007403C;
    }
    goto skip_0;
    // 0x8007402C: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
    skip_0:
    // 0x80074030: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x80074034: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_80074038:
    // 0x80074038: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
L_8007403C:
    // 0x8007403C: bgez        $t8, L_80074048
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80074040: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_80074048;
    }
    // 0x80074040: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x80074044: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_80074048:
    // 0x80074048: bgtz        $s2, L_80074118
    if (SIGNED(ctx->r18) > 0) {
        // 0x8007404C: slt         $at, $s3, $s2
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_80074118;
    }
    // 0x8007404C: slt         $at, $s3, $s2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80074050: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80074054: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80074058: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x8007405C: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x80074060: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80074064: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x80074068: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8007406C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80074070: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80074074: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80074078: bgtz        $v0, L_80074090
    if (SIGNED(ctx->r2) > 0) {
        // 0x8007407C: sw          $t8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r24;
            goto L_80074090;
    }
    // 0x8007407C: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x80074080: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x80074084: andi        $t9, $t6, 0x8
    ctx->r25 = ctx->r14 & 0X8;
    // 0x80074088: beql        $t9, $zero, L_800740B8
    if (ctx->r25 == 0) {
        // 0x8007408C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800740B8;
    }
    goto skip_1;
    // 0x8007408C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
L_80074090:
    // 0x80074090: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80074094: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80074098: addiu       $t7, $zero, 0x2E
    ctx->r15 = ADD32(0, 0X2E);
    // 0x8007409C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x800740A0: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x800740A4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800740A8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800740AC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800740B0: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800740B4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800740B8:
    // 0x800740B8: beql        $at, $zero, L_800740D4
    if (ctx->r1 == 0) {
        // 0x800740BC: addu        $t8, $v0, $s2
        ctx->r24 = ADD32(ctx->r2, ctx->r18);
            goto L_800740D4;
    }
    goto skip_2;
    // 0x800740BC: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
    skip_2:
    // 0x800740C0: negu        $s2, $v0
    ctx->r18 = SUB32(0, ctx->r2);
    // 0x800740C4: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800740C8: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800740CC: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x800740D0: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
L_800740D4:
    // 0x800740D4: slt         $at, $t8, $s3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800740D8: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x800740DC: beq         $at, $zero, L_800740F0
    if (ctx->r1 == 0) {
        // 0x800740E0: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_800740F0;
    }
    // 0x800740E0: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800740E4: sll         $s3, $t8, 16
    ctx->r19 = S32(ctx->r24 << 16);
    // 0x800740E8: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800740EC: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800740F0:
    // 0x800740F0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800740F4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800740F8: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
    // 0x800740FC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80074100: jal         0x8006B450
    // 0x80074104: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x80074104: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x80074108: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8007410C: subu        $t6, $t8, $s3
    ctx->r14 = SUB32(ctx->r24, ctx->r19);
    // 0x80074110: b           L_8007449C
    // 0x80074114: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
        goto L_8007449C;
    // 0x80074114: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
L_80074118:
    // 0x80074118: beq         $at, $zero, L_80074190
    if (ctx->r1 == 0) {
        // 0x8007411C: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80074190;
    }
    // 0x8007411C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80074120: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80074124: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80074128: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8007412C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80074130: jal         0x8006B450
    // 0x80074134: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x80074134: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x80074138: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8007413C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80074140: subu        $t7, $s2, $s3
    ctx->r15 = SUB32(ctx->r18, ctx->r19);
    // 0x80074144: addu        $t6, $t8, $s3
    ctx->r14 = ADD32(ctx->r24, ctx->r19);
    // 0x80074148: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x8007414C: bgtz        $v0, L_80074164
    if (SIGNED(ctx->r2) > 0) {
        // 0x80074150: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_80074164;
    }
    // 0x80074150: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x80074154: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x80074158: andi        $t8, $t9, 0x8
    ctx->r24 = ctx->r25 & 0X8;
    // 0x8007415C: beq         $t8, $zero, L_80074188
    if (ctx->r24 == 0) {
        // 0x80074160: nop
    
            goto L_80074188;
    }
    // 0x80074160: nop

L_80074164:
    // 0x80074164: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80074168: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x8007416C: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x80074170: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80074174: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x80074178: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x8007417C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80074180: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80074184: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_80074188:
    // 0x80074188: b           L_8007449C
    // 0x8007418C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
        goto L_8007449C;
    // 0x8007418C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_80074190:
    // 0x80074190: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80074194: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80074198: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8007419C: jal         0x8006B450
    // 0x800741A0: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x800741A0: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_2:
    // 0x800741A4: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800741A8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800741AC: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800741B0: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800741B4: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800741B8: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x800741BC: bgtz        $v0, L_800741D4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800741C0: sra         $s3, $t6, 16
        ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
            goto L_800741D4;
    }
    // 0x800741C0: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800741C4: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x800741C8: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x800741CC: beql        $t9, $zero, L_800741FC
    if (ctx->r25 == 0) {
        // 0x800741D0: slt         $at, $v0, $s3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_800741FC;
    }
    goto skip_3;
    // 0x800741D0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    skip_3:
L_800741D4:
    // 0x800741D4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800741D8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800741DC: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800741E0: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800741E4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800741E8: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800741EC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800741F0: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800741F4: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800741F8: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
L_800741FC:
    // 0x800741FC: beq         $at, $zero, L_80074210
    if (ctx->r1 == 0) {
        // 0x80074200: addu        $a1, $s2, $s1
        ctx->r5 = ADD32(ctx->r18, ctx->r17);
            goto L_80074210;
    }
    // 0x80074200: addu        $a1, $s2, $s1
    ctx->r5 = ADD32(ctx->r18, ctx->r17);
    // 0x80074204: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80074208: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8007420C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_80074210:
    // 0x80074210: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80074214: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80074218: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8007421C: jal         0x8006B450
    // 0x80074220: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x80074220: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_3:
    // 0x80074224: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80074228: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8007422C: addu        $t6, $t7, $s3
    ctx->r14 = ADD32(ctx->r15, ctx->r19);
    // 0x80074230: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x80074234: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x80074238: b           L_8007449C
    // 0x8007423C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
        goto L_8007449C;
    // 0x8007423C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
L_80074240:
    // 0x80074240: beq         $a0, $v1, L_80074250
    if (ctx->r4 == ctx->r3) {
        // 0x80074244: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_80074250;
    }
    // 0x80074244: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80074248: bnel        $v1, $at, L_80074290
    if (ctx->r3 != ctx->r1) {
        // 0x8007424C: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_80074290;
    }
    goto skip_4;
    // 0x8007424C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_4:
L_80074250:
    // 0x80074250: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80074254: addiu       $s4, $zero, 0x45
    ctx->r20 = ADD32(0, 0X45);
    // 0x80074258: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007425C: beql        $at, $zero, L_80074270
    if (ctx->r1 == 0) {
        // 0x80074260: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80074270;
    }
    goto skip_5;
    // 0x80074260: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_5:
    // 0x80074264: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x80074268: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8007426C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_80074270:
    // 0x80074270: bgez        $t7, L_8007427C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80074274: sw          $t7, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r15;
            goto L_8007427C;
    }
    // 0x80074274: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x80074278: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_8007427C:
    // 0x8007427C: bne         $a0, $v1, L_8007428C
    if (ctx->r4 != ctx->r3) {
        // 0x80074280: nop
    
            goto L_8007428C;
    }
    // 0x80074280: nop

    // 0x80074284: b           L_8007428C
    // 0x80074288: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
        goto L_8007428C;
    // 0x80074288: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
L_8007428C:
    // 0x8007428C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_80074290:
    // 0x80074290: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80074294: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x80074298: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007429C: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800742A0: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x800742A4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800742A8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800742AC: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800742B0: bgtz        $v0, L_800742C8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800742B4: sw          $t7, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r15;
            goto L_800742C8;
    }
    // 0x800742B4: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800742B8: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800742BC: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x800742C0: beq         $t6, $zero, L_800742EC
    if (ctx->r14 == 0) {
        // 0x800742C4: nop
    
            goto L_800742EC;
    }
    // 0x800742C4: nop

L_800742C8:
    // 0x800742C8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800742CC: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800742D0: addiu       $t8, $zero, 0x2E
    ctx->r24 = ADD32(0, 0X2E);
    // 0x800742D4: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800742D8: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800742DC: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800742E0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800742E4: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800742E8: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
L_800742EC:
    // 0x800742EC: blezl       $v0, L_80074348
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800742F0: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_80074348;
    }
    goto skip_6;
    // 0x800742F0: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_6:
    // 0x800742F4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800742F8: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800742FC: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80074300: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80074304: beq         $at, $zero, L_80074318
    if (ctx->r1 == 0) {
        // 0x80074308: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80074318;
    }
    // 0x80074308: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8007430C: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80074310: sra         $t7, $s3, 16
    ctx->r15 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80074314: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_80074318:
    // 0x80074318: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8007431C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80074320: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80074324: jal         0x8006B450
    // 0x80074328: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x80074328: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_4:
    // 0x8007432C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80074330: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80074334: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x80074338: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x8007433C: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x80074340: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x80074344: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_80074348:
    // 0x80074348: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8007434C: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x80074350: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80074354: bltz        $s2, L_8007436C
    if (SIGNED(ctx->r18) < 0) {
        // 0x80074358: sb          $s4, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r20;
            goto L_8007436C;
    }
    // 0x80074358: sb          $s4, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r20;
    // 0x8007435C: addiu       $t9, $zero, 0x2B
    ctx->r25 = ADD32(0, 0X2B);
    // 0x80074360: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x80074364: b           L_80074388
    // 0x80074368: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80074388;
    // 0x80074368: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8007436C:
    // 0x8007436C: negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
    // 0x80074370: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80074374: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x80074378: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8007437C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x80074380: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80074384: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_80074388:
    // 0x80074388: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x8007438C: bnel        $at, $zero, L_80074438
    if (ctx->r1 != 0) {
        // 0x80074390: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80074438;
    }
    goto skip_7;
    // 0x80074390: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_7:
    // 0x80074394: slti        $at, $s2, 0x3E8
    ctx->r1 = SIGNED(ctx->r18) < 0X3E8 ? 1 : 0;
    // 0x80074398: bne         $at, $zero, L_800743E8
    if (ctx->r1 != 0) {
        // 0x8007439C: addiu       $v0, $zero, 0x3E8
        ctx->r2 = ADD32(0, 0X3E8);
            goto L_800743E8;
    }
    // 0x8007439C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x800743A0: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800743A4: bne         $v0, $zero, L_800743B0
    if (ctx->r2 != 0) {
        // 0x800743A8: nop
    
            goto L_800743B0;
    }
    // 0x800743A8: nop

    // 0x800743AC: break       7
    do_break(2147959724);
L_800743B0:
    // 0x800743B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800743B4: bne         $v0, $at, L_800743C8
    if (ctx->r2 != ctx->r1) {
        // 0x800743B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800743C8;
    }
    // 0x800743B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800743BC: bne         $s2, $at, L_800743C8
    if (ctx->r18 != ctx->r1) {
        // 0x800743C0: nop
    
            goto L_800743C8;
    }
    // 0x800743C0: nop

    // 0x800743C4: break       6
    do_break(2147959748);
L_800743C8:
    // 0x800743C8: mfhi        $s2
    ctx->r18 = hi;
    // 0x800743CC: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800743D0: mflo        $t9
    ctx->r25 = lo;
    // 0x800743D4: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800743D8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800743DC: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800743E0: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800743E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800743E8:
    // 0x800743E8: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x800743EC: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800743F0: bne         $v0, $zero, L_800743FC
    if (ctx->r2 != 0) {
        // 0x800743F4: nop
    
            goto L_800743FC;
    }
    // 0x800743F4: nop

    // 0x800743F8: break       7
    do_break(2147959800);
L_800743FC:
    // 0x800743FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80074400: bne         $v0, $at, L_80074414
    if (ctx->r2 != ctx->r1) {
        // 0x80074404: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80074414;
    }
    // 0x80074404: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80074408: bne         $s2, $at, L_80074414
    if (ctx->r18 != ctx->r1) {
        // 0x8007440C: nop
    
            goto L_80074414;
    }
    // 0x8007440C: nop

    // 0x80074410: break       6
    do_break(2147959824);
L_80074414:
    // 0x80074414: mfhi        $s2
    ctx->r18 = hi;
    // 0x80074418: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8007441C: mflo        $t9
    ctx->r25 = lo;
    // 0x80074420: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x80074424: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80074428: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8007442C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x80074430: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80074434: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80074438:
    // 0x80074438: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x8007443C: bne         $v0, $zero, L_80074448
    if (ctx->r2 != 0) {
        // 0x80074440: nop
    
            goto L_80074448;
    }
    // 0x80074440: nop

    // 0x80074444: break       7
    do_break(2147959876);
L_80074448:
    // 0x80074448: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007444C: bne         $v0, $at, L_80074460
    if (ctx->r2 != ctx->r1) {
        // 0x80074450: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80074460;
    }
    // 0x80074450: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80074454: bne         $s2, $at, L_80074460
    if (ctx->r18 != ctx->r1) {
        // 0x80074458: nop
    
            goto L_80074460;
    }
    // 0x80074458: nop

    // 0x8007445C: break       6
    do_break(2147959900);
L_80074460:
    // 0x80074460: mfhi        $s2
    ctx->r18 = hi;
    // 0x80074464: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80074468: mflo        $t9
    ctx->r25 = lo;
    // 0x8007446C: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x80074470: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80074474: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x80074478: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x8007447C: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x80074480: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80074484: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x80074488: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8007448C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80074490: subu        $t6, $s1, $t8
    ctx->r14 = SUB32(ctx->r17, ctx->r24);
    // 0x80074494: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x80074498: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_8007449C:
    // 0x8007449C: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x800744A0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800744A4: andi        $t6, $t8, 0x14
    ctx->r14 = ctx->r24 & 0X14;
    // 0x800744A8: bnel        $t6, $at, L_800744EC
    if (ctx->r14 != ctx->r1) {
        // 0x800744AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800744EC;
    }
    goto skip_8;
    // 0x800744AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x800744B0: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800744B4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800744B8: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x800744BC: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x800744C0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800744C4: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x800744C8: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800744CC: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800744D0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800744D4: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x800744D8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800744DC: beq         $at, $zero, L_800744E8
    if (ctx->r1 == 0) {
        // 0x800744E0: subu        $t7, $v1, $v0
        ctx->r15 = SUB32(ctx->r3, ctx->r2);
            goto L_800744E8;
    }
    // 0x800744E0: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x800744E4: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_800744E8:
    // 0x800744E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800744EC:
    // 0x800744EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800744F0: jr          $ra
    // 0x800744F4: nop

    return;
    // 0x800744F4: nop

;}
RECOMP_FUNC void func_800744F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800744F8: jr          $ra
    // 0x800744FC: nop

    return;
    // 0x800744FC: nop

;}
RECOMP_FUNC void _Ldtob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80074500: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80074504: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80074508: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8007450C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80074510: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80074514: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80074518: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8007451C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80074520: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80074524: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x80074528: sw          $a1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r5;
    // 0x8007452C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80074530: addiu       $s5, $sp, 0xB0
    ctx->r21 = ADD32(ctx->r29, 0XB0);
    // 0x80074534: ldc1        $f20, 0x0($a0)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r4, 0X0);
    // 0x80074538: bgez        $v0, L_80074548
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007453C: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_80074548;
    }
    // 0x8007453C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80074540: b           L_80074574
    // 0x80074544: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
        goto L_80074574;
    // 0x80074544: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
L_80074548:
    // 0x80074548: bne         $v0, $zero, L_80074574
    if (ctx->r2 != 0) {
        // 0x8007454C: lbu         $t8, 0xD7($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0XD7);
            goto L_80074574;
    }
    // 0x8007454C: lbu         $t8, 0xD7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD7);
    // 0x80074550: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x80074554: beq         $t8, $at, L_80074568
    if (ctx->r24 == ctx->r1) {
        // 0x80074558: sw          $t8, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r24;
            goto L_80074568;
    }
    // 0x80074558: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8007455C: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80074560: bnel        $t8, $at, L_80074578
    if (ctx->r24 != ctx->r1) {
        // 0x80074564: lw          $t6, 0xD0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XD0);
            goto L_80074578;
    }
    goto skip_0;
    // 0x80074564: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    skip_0:
L_80074568:
    // 0x80074568: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x8007456C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80074570: sw          $t9, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r25;
L_80074574:
    // 0x80074574: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
L_80074578:
    // 0x80074578: addiu       $at, $zero, 0x7FF
    ctx->r1 = ADD32(0, 0X7FF);
    // 0x8007457C: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x80074580: andi        $v1, $a0, 0x7FF0
    ctx->r3 = ctx->r4 & 0X7FF0;
    // 0x80074584: sra         $t8, $v1, 4
    ctx->r24 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80074588: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8007458C: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80074590: bne         $v1, $at, L_800745F4
    if (ctx->r3 != ctx->r1) {
        // 0x80074594: nop
    
            goto L_800745F4;
    }
    // 0x80074594: nop

    // 0x80074598: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x8007459C: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x800745A0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800745A4: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800745A8: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x800745AC: bnel        $t9, $zero, L_800745D8
    if (ctx->r25 != 0) {
        // 0x800745B0: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800745D8;
    }
    goto skip_1;
    // 0x800745B0: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_1:
    // 0x800745B4: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x800745B8: bnel        $t7, $zero, L_800745D8
    if (ctx->r15 != 0) {
        // 0x800745BC: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800745D8;
    }
    goto skip_2;
    // 0x800745BC: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_2:
    // 0x800745C0: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x800745C4: bnel        $t8, $zero, L_800745D8
    if (ctx->r24 != 0) {
        // 0x800745C8: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800745D8;
    }
    goto skip_3;
    // 0x800745C8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_3:
    // 0x800745CC: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x800745D0: beq         $t9, $zero, L_800745E0
    if (ctx->r25 == 0) {
        // 0x800745D4: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800745E0;
    }
    // 0x800745D4: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
L_800745D8:
    // 0x800745D8: b           L_8007462C
    // 0x800745DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8007462C;
    // 0x800745DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800745E0:
    // 0x800745E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800745E4: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800745E8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800745EC: b           L_8007462C
    // 0x800745F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8007462C;
    // 0x800745F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800745F4:
    // 0x800745F4: blez        $v1, L_80074618
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800745F8: andi        $t8, $a0, 0x800F
        ctx->r24 = ctx->r4 & 0X800F;
            goto L_80074618;
    }
    // 0x800745F8: andi        $t8, $a0, 0x800F
    ctx->r24 = ctx->r4 & 0X800F;
    // 0x800745FC: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x80074600: ori         $t6, $t8, 0x3FF0
    ctx->r14 = ctx->r24 | 0X3FF0;
    // 0x80074604: addiu       $t7, $v1, -0x3FE
    ctx->r15 = ADD32(ctx->r3, -0X3FE);
    // 0x80074608: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x8007460C: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x80074610: b           L_8007462C
    // 0x80074614: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8007462C;
    // 0x80074614: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074618:
    // 0x80074618: bgez        $v1, L_80074628
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007461C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80074628;
    }
    // 0x8007461C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80074620: b           L_8007462C
    // 0x80074624: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8007462C;
    // 0x80074624: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80074628:
    // 0x80074628: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_8007462C:
    // 0x8007462C: blez        $v0, L_80074678
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80074630: sll         $t8, $v0, 16
        ctx->r24 = S32(ctx->r2 << 16);
            goto L_80074678;
    }
    // 0x80074630: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80074634: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80074638: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8007463C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80074640: bne         $t6, $at, L_80074654
    if (ctx->r14 != ctx->r1) {
        // 0x80074644: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_80074654;
    }
    // 0x80074644: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x80074648: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8007464C: b           L_8007465C
    // 0x80074650: addiu       $a1, $a1, -0x21D8
    ctx->r5 = ADD32(ctx->r5, -0X21D8);
        goto L_8007465C;
    // 0x80074650: addiu       $a1, $a1, -0x21D8
    ctx->r5 = ADD32(ctx->r5, -0X21D8);
L_80074654:
    // 0x80074654: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80074658: addiu       $a1, $a1, -0x21D4
    ctx->r5 = ADD32(ctx->r5, -0X21D4);
L_8007465C:
    // 0x8007465C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80074660: sw          $t7, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r15;
    // 0x80074664: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x80074668: jal         0x8006B450
    // 0x8007466C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x8007466C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80074670: b           L_80074A28
    // 0x80074674: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80074A28;
    // 0x80074674: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80074678:
    // 0x80074678: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8007467C: bne         $t6, $zero, L_8007468C
    if (ctx->r14 != 0) {
        // 0x80074680: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8007468C;
    }
    // 0x80074680: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80074684: b           L_80074A10
    // 0x80074688: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
        goto L_80074A10;
    // 0x80074688: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_8007468C:
    // 0x8007468C: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x80074690: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80074694: lbu         $t7, 0xD7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD7);
    // 0x80074698: lh          $t9, 0x9A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X9A);
    // 0x8007469C: c.lt.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d < ctx->f2.d;
    // 0x800746A0: addiu       $at, $zero, 0x7597
    ctx->r1 = ADD32(0, 0X7597);
    // 0x800746A4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800746A8: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x800746AC: bc1f        L_800746B8
    if (!c1cs) {
        // 0x800746B0: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_800746B8;
    }
    // 0x800746B0: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800746B4: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
L_800746B8:
    // 0x800746B8: multu       $t9, $at
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800746BC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800746C0: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x800746C4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800746C8: mflo        $t8
    ctx->r24 = lo;
    // 0x800746CC: nop

    // 0x800746D0: nop

    // 0x800746D4: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x800746D8: mflo        $t6
    ctx->r14 = lo;
    // 0x800746DC: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x800746E0: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800746E4: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800746E8: bgez        $t8, L_80074750
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800746EC: sh          $t7, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r15;
            goto L_80074750;
    }
    // 0x800746EC: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800746F0: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800746F4: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800746F8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800746FC: subu        $a0, $t6, $t8
    ctx->r4 = SUB32(ctx->r14, ctx->r24);
    // 0x80074700: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80074704: and         $v0, $a0, $at
    ctx->r2 = ctx->r4 & ctx->r1;
    // 0x80074708: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x8007470C: blez        $v0, L_800747C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80074710: sh          $t9, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r25;
            goto L_800747C0;
    }
    // 0x80074710: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x80074714: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80074718: addiu       $a0, $a0, -0x2220
    ctx->r4 = ADD32(ctx->r4, -0X2220);
L_8007471C:
    // 0x8007471C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80074720: beq         $t6, $zero, L_8007473C
    if (ctx->r14 == 0) {
        // 0x80074724: sra         $t9, $v0, 1
        ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8007473C;
    }
    // 0x80074724: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80074728: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8007472C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80074730: ldc1        $f4, 0x0($t7)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r15, 0X0);
    // 0x80074734: mul.d       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f20.d = MUL_D(ctx->f20.d, ctx->f4.d);
    // 0x80074738: nop

L_8007473C:
    // 0x8007473C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80074740: bgtz        $t9, L_8007471C
    if (SIGNED(ctx->r25) > 0) {
        // 0x80074744: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8007471C;
    }
    // 0x80074744: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80074748: b           L_800747C4
    // 0x8007474C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
        goto L_800747C4;
    // 0x8007474C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_80074750:
    // 0x80074750: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x80074754: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80074758: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007475C: blez        $t6, L_800747C0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80074760: andi        $t8, $t6, 0xFFFC
        ctx->r24 = ctx->r14 & 0XFFFC;
            goto L_800747C0;
    }
    // 0x80074760: andi        $t8, $t6, 0xFFFC
    ctx->r24 = ctx->r14 & 0XFFFC;
    // 0x80074764: sll         $v0, $t8, 16
    ctx->r2 = S32(ctx->r24 << 16);
    // 0x80074768: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8007476C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80074770: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80074774: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80074778: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007477C: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x80074780: blez        $t6, L_800747BC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80074784: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800747BC;
    }
    // 0x80074784: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074788: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8007478C: addiu       $a0, $a0, -0x2220
    ctx->r4 = ADD32(ctx->r4, -0X2220);
L_80074790:
    // 0x80074790: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80074794: beq         $t7, $zero, L_800747B0
    if (ctx->r15 == 0) {
        // 0x80074798: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800747B0;
    }
    // 0x80074798: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8007479C: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800747A0: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800747A4: ldc1        $f6, 0x0($t9)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r25, 0X0);
    // 0x800747A8: mul.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800747AC: nop

L_800747B0:
    // 0x800747B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800747B4: bgtz        $t6, L_80074790
    if (SIGNED(ctx->r14) > 0) {
        // 0x800747B8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80074790;
    }
    // 0x800747B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800747BC:
    // 0x800747BC: div.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = DIV_D(ctx->f20.d, ctx->f0.d);
L_800747C0:
    // 0x800747C0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_800747C4:
    // 0x800747C4: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x800747C8: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800747CC: bne         $t7, $at, L_800747E0
    if (ctx->r15 != ctx->r1) {
        // 0x800747D0: addiu       $t6, $zero, 0x30
        ctx->r14 = ADD32(0, 0X30);
            goto L_800747E0;
    }
    // 0x800747D0: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800747D4: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x800747D8: b           L_800747E0
    // 0x800747DC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
        goto L_800747E0;
    // 0x800747DC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
L_800747E0:
    // 0x800747E0: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x800747E4: addu        $s4, $a1, $t9
    ctx->r20 = ADD32(ctx->r5, ctx->r25);
    // 0x800747E8: slti        $at, $s4, 0x14
    ctx->r1 = SIGNED(ctx->r20) < 0X14 ? 1 : 0;
    // 0x800747EC: bne         $at, $zero, L_800747F8
    if (ctx->r1 != 0) {
        // 0x800747F0: nop
    
            goto L_800747F8;
    }
    // 0x800747F0: nop

    // 0x800747F4: addiu       $s4, $zero, 0x13
    ctx->r20 = ADD32(0, 0X13);
L_800747F8:
    // 0x800747F8: blez        $s4, L_800748C8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800747FC: sb          $t6, 0xB0($sp)
        MEM_B(0XB0, ctx->r29) = ctx->r14;
            goto L_800748C8;
    }
    // 0x800747FC: sb          $t6, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r14;
    // 0x80074800: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x80074804: addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
    // 0x80074808: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x8007480C: bc1fl       L_800748CC
    if (!c1cs) {
        // 0x80074810: lh          $t8, 0x9A($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X9A);
            goto L_800748CC;
    }
    goto skip_4;
    // 0x80074810: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
    skip_4:
    // 0x80074814: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
L_80074818:
    // 0x80074818: addiu       $s4, $s4, -0x8
    ctx->r20 = ADD32(ctx->r20, -0X8);
    // 0x8007481C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80074820: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x80074824: blez        $s4, L_80074848
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80074828: nop
    
            goto L_80074848;
    }
    // 0x80074828: nop

    // 0x8007482C: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x80074830: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80074834: ldc1        $f8, -0x21C8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X21C8);
    // 0x80074838: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x8007483C: sub.d       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f20.d - ctx->f4.d;
    // 0x80074840: mul.d       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f20.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80074844: nop

L_80074848:
    // 0x80074848: blez        $s1, L_80074890
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8007484C: addiu       $s0, $zero, 0x8
        ctx->r16 = ADD32(0, 0X8);
            goto L_80074890;
    }
    // 0x8007484C: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x80074850: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x80074854: bltz        $s0, L_80074890
    if (SIGNED(ctx->r16) < 0) {
        // 0x80074858: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80074890;
    }
    // 0x80074858: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8007485C:
    // 0x8007485C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80074860: jal         0x80074B50
    // 0x80074864: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    ldiv_recomp(rdram, ctx);
        goto after_1;
    // 0x80074864: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x80074868: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8007486C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80074870: addiu       $t9, $t8, 0x30
    ctx->r25 = ADD32(ctx->r24, 0X30);
    // 0x80074874: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
    // 0x80074878: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x8007487C: blezl       $s1, L_80074894
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80074880: mtc1        $zero, $f3
        ctx->f_odd[(3 - 1) * 2] = 0;
            goto L_80074894;
    }
    goto skip_5;
    // 0x80074880: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    skip_5:
    // 0x80074884: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80074888: bgezl       $s0, L_8007485C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8007488C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8007485C;
    }
    goto skip_6;
    // 0x8007488C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
L_80074890:
    // 0x80074890: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
L_80074894:
    // 0x80074894: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80074898: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8007489C: bltz        $s0, L_800748B0
    if (SIGNED(ctx->r16) < 0) {
        // 0x800748A0: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800748B0;
    }
L_800748A0:
    // 0x800748A0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800748A4: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800748A8: bgez        $s0, L_800748A0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800748AC: sb          $s3, 0x0($s5)
        MEM_B(0X0, ctx->r21) = ctx->r19;
            goto L_800748A0;
    }
    // 0x800748AC: sb          $s3, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r19;
L_800748B0:
    // 0x800748B0: blez        $s4, L_800748C8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800748B4: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_800748C8;
    }
    // 0x800748B4: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800748B8: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800748BC: nop

    // 0x800748C0: bc1tl       L_80074818
    if (c1cs) {
        // 0x800748C4: trunc.w.d   $f8, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
            goto L_80074818;
    }
    goto skip_7;
    // 0x800748C4: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
    skip_7:
L_800748C8:
    // 0x800748C8: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
L_800748CC:
    // 0x800748CC: lbu         $t6, 0xB1($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB1);
    // 0x800748D0: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x800748D4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800748D8: subu        $s4, $s5, $t7
    ctx->r20 = SUB32(ctx->r21, ctx->r15);
    // 0x800748DC: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800748E0: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800748E4: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x800748E8: bne         $v0, $t6, L_80074910
    if (ctx->r2 != ctx->r14) {
        // 0x800748EC: addiu       $s5, $sp, 0xB1
        ctx->r21 = ADD32(ctx->r29, 0XB1);
            goto L_80074910;
    }
    // 0x800748EC: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x800748F0: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
L_800748F4:
    // 0x800748F4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800748F8: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800748FC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80074900: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x80074904: lbu         $t9, 0x0($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X0);
    // 0x80074908: beql        $v0, $t9, L_800748F4
    if (ctx->r2 == ctx->r25) {
        // 0x8007490C: lh          $t7, 0x9A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X9A);
            goto L_800748F4;
    }
    goto skip_8;
    // 0x8007490C: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
    skip_8:
L_80074910:
    // 0x80074910: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80074914: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80074918: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x8007491C: bne         $t6, $at, L_80074930
    if (ctx->r14 != ctx->r1) {
        // 0x80074920: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_80074930;
    }
    // 0x80074920: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80074924: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x80074928: b           L_80074950
    // 0x8007492C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80074950;
    // 0x8007492C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80074930:
    // 0x80074930: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80074934: beq         $t7, $at, L_80074944
    if (ctx->r15 == ctx->r1) {
        // 0x80074938: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_80074944;
    }
    // 0x80074938: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x8007493C: bne         $t7, $at, L_8007494C
    if (ctx->r15 != ctx->r1) {
        // 0x80074940: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007494C;
    }
    // 0x80074940: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80074944:
    // 0x80074944: b           L_8007494C
    // 0x80074948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007494C;
    // 0x80074948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007494C:
    // 0x8007494C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80074950:
    // 0x80074950: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x80074954: addu        $s3, $a1, $t9
    ctx->r19 = ADD32(ctx->r5, ctx->r25);
    // 0x80074958: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x8007495C: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80074960: slt         $at, $s4, $s3
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80074964: beq         $at, $zero, L_80074978
    if (ctx->r1 == 0) {
        // 0x80074968: nop
    
            goto L_80074978;
    }
    // 0x80074968: nop

    // 0x8007496C: sll         $s3, $s4, 16
    ctx->r19 = S32(ctx->r20 << 16);
    // 0x80074970: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80074974: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
L_80074978:
    // 0x80074978: blez        $s3, L_80074A10
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8007497C: slt         $at, $s3, $s4
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_80074A10;
    }
    // 0x8007497C: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80074980: beq         $at, $zero, L_800749A0
    if (ctx->r1 == 0) {
        // 0x80074984: addu        $v0, $s3, $s5
        ctx->r2 = ADD32(ctx->r19, ctx->r21);
            goto L_800749A0;
    }
    // 0x80074984: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
    // 0x80074988: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8007498C: slti        $at, $t9, 0x35
    ctx->r1 = SIGNED(ctx->r25) < 0X35 ? 1 : 0;
    // 0x80074990: bnel        $at, $zero, L_800749A4
    if (ctx->r1 != 0) {
        // 0x80074994: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_800749A4;
    }
    goto skip_9;
    // 0x80074994: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    skip_9:
    // 0x80074998: b           L_800749A8
    // 0x8007499C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
        goto L_800749A8;
    // 0x8007499C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
L_800749A0:
    // 0x800749A0: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
L_800749A4:
    // 0x800749A4: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
L_800749A8:
    // 0x800749A8: lbu         $t6, -0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X1);
    // 0x800749AC: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x800749B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800749B4: bne         $a1, $t6, L_800749DC
    if (ctx->r5 != ctx->r14) {
        // 0x800749B8: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_800749DC;
    }
    // 0x800749B8: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x800749BC: addu        $v0, $v1, $s5
    ctx->r2 = ADD32(ctx->r3, ctx->r21);
L_800749C0:
    // 0x800749C0: lbu         $t9, -0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X1);
    // 0x800749C4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800749C8: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x800749CC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800749D0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800749D4: beq         $a0, $t9, L_800749C0
    if (ctx->r4 == ctx->r25) {
        // 0x800749D8: sra         $s3, $t7, 16
        ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
            goto L_800749C0;
    }
    // 0x800749D8: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
L_800749DC:
    // 0x800749DC: bne         $a0, $at, L_800749F0
    if (ctx->r4 != ctx->r1) {
        // 0x800749E0: addu        $v0, $s5, $v1
        ctx->r2 = ADD32(ctx->r21, ctx->r3);
            goto L_800749F0;
    }
    // 0x800749E0: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x800749E4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800749E8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800749EC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_800749F0:
    // 0x800749F0: bgez        $v1, L_80074A10
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800749F4: lh          $t6, 0x9A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X9A);
            goto L_80074A10;
    }
    // 0x800749F4: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x800749F8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800749FC: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x80074A00: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80074A04: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x80074A08: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80074A0C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_80074A10:
    // 0x80074A10: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
    // 0x80074A14: lbu         $s4, 0xD7($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0XD7);
    // 0x80074A18: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x80074A1C: jal         0x80073F90
    // 0x80074A20: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    func_80073F90(rdram, ctx);
        goto after_2;
    // 0x80074A20: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    after_2:
    // 0x80074A24: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80074A28:
    // 0x80074A28: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80074A2C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80074A30: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80074A34: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80074A38: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80074A3C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80074A40: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80074A44: jr          $ra
    // 0x80074A48: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80074A48: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    // 0x80074A4C: nop

;}
RECOMP_FUNC void lldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80074A50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80074A54: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80074A58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074A5C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80074A60: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80074A64: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80074A68: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80074A6C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80074A70: jal         0x8006A82C
    // 0x80074A74: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    __ll_div_recomp(rdram, ctx);
        goto after_0;
    // 0x80074A74: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x80074A78: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80074A7C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80074A80: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80074A84: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80074A88: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80074A8C: jal         0x8006A888
    // 0x80074A90: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80074A90: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_1:
    // 0x80074A94: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80074A98: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80074A9C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80074AA0: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x80074AA4: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x80074AA8: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x80074AAC: subu        $t9, $t7, $v1
    ctx->r25 = SUB32(ctx->r15, ctx->r3);
    // 0x80074AB0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80074AB4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80074AB8: bgtz        $t0, L_80074B18
    if (SIGNED(ctx->r8) > 0) {
        // 0x80074ABC: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80074B18;
    }
    // 0x80074ABC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80074AC0: bltz        $t0, L_80074AD0
    if (SIGNED(ctx->r8) < 0) {
        // 0x80074AC4: nop
    
            goto L_80074AD0;
    }
    // 0x80074AC4: nop

    // 0x80074AC8: b           L_80074B1C
    // 0x80074ACC: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
        goto L_80074B1C;
    // 0x80074ACC: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_80074AD0:
    // 0x80074AD0: bltzl       $t8, L_80074B1C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80074AD4: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_80074B1C;
    }
    goto skip_0;
    // 0x80074AD4: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_0:
    // 0x80074AD8: bgtz        $t8, L_80074AE8
    if (SIGNED(ctx->r24) > 0) {
        // 0x80074ADC: addiu       $t3, $t1, 0x1
        ctx->r11 = ADD32(ctx->r9, 0X1);
            goto L_80074AE8;
    }
    // 0x80074ADC: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80074AE0: beql        $t9, $zero, L_80074B1C
    if (ctx->r25 == 0) {
        // 0x80074AE4: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_80074B1C;
    }
    goto skip_1;
    // 0x80074AE4: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_1:
L_80074AE8:
    // 0x80074AE8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80074AEC: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80074AF0: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80074AF4: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x80074AF8: subu        $t6, $t8, $t4
    ctx->r14 = SUB32(ctx->r24, ctx->r12);
    // 0x80074AFC: sltu        $at, $t9, $t5
    ctx->r1 = ctx->r25 < ctx->r13 ? 1 : 0;
    // 0x80074B00: subu        $t6, $t6, $at
    ctx->r14 = SUB32(ctx->r14, ctx->r1);
    // 0x80074B04: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x80074B08: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80074B0C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80074B10: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80074B14: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_80074B18:
    // 0x80074B18: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_80074B1C:
    // 0x80074B1C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80074B20: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80074B24: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x80074B28: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80074B2C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80074B30: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80074B34: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x80074B38: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x80074B3C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x80074B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074B44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80074B48: jr          $ra
    // 0x80074B4C: nop

    return;
    // 0x80074B4C: nop

;}
RECOMP_FUNC void ldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80074B50: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x80074B54: mflo        $v0
    ctx->r2 = lo;
;}
RECOMP_FUNC void func_80074B58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80074B58: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80074B5C: bne         $a2, $zero, L_80074B68
    if (ctx->r6 != 0) {
        // 0x80074B60: nop
    
            goto L_80074B68;
    }
    // 0x80074B60: nop

    // 0x80074B64: break       7
    do_break(2147961700);
L_80074B68:
    // 0x80074B68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80074B6C: bne         $a2, $at, L_80074B80
    if (ctx->r6 != ctx->r1) {
        // 0x80074B70: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80074B80;
    }
    // 0x80074B70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80074B74: bne         $a1, $at, L_80074B80
    if (ctx->r5 != ctx->r1) {
        // 0x80074B78: nop
    
            goto L_80074B80;
    }
    // 0x80074B78: nop

    // 0x80074B7C: break       6
    do_break(2147961724);
L_80074B80:
    // 0x80074B80: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80074B84: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x80074B88: addiu       $t7, $sp, 0x0
    ctx->r15 = ADD32(ctx->r29, 0X0);
    // 0x80074B8C: mflo        $t6
    ctx->r14 = lo;
    // 0x80074B90: subu        $v1, $a1, $t6
    ctx->r3 = SUB32(ctx->r5, ctx->r14);
    // 0x80074B94: bgez        $v0, L_80074BB8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80074B98: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_80074BB8;
    }
    // 0x80074B98: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x80074B9C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x80074BA0: blez        $v1, L_80074BB8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80074BA4: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_80074BB8;
    }
    // 0x80074BA4: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x80074BA8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80074BAC: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x80074BB0: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x80074BB4: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_80074BB8:
    // 0x80074BB8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80074BBC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80074BC0: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x80074BC4: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80074BC8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80074BCC: jr          $ra
    // 0x80074BD0: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    return;
    // 0x80074BD0: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80074BD4: nop

    // 0x80074BD8: nop

    // 0x80074BDC: nop

;}
RECOMP_FUNC void stub_80000000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_801378DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // alInit - SN64 audio library global init. No-op stub since we don't have
    // the SN64 audio engine. The audio thread will run but produce no output.
    fprintf(stderr, "[SN64] alInit called (stub - no audio engine)\n");
    fflush(stderr);
;}
RECOMP_FUNC void stub_80137FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // SN64 audio command list fetch. Returns pointer to ABI command list, or 0 if none.
    // The audio thread checks this return value - if non-zero, it processes audio commands.
    // Return 0 to skip audio processing since we have no real audio engine.
    ctx->r2 = 0;
;}
RECOMP_FUNC void stub_8013858C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_80138934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // DMA wait/sync - DMA is synchronous in recomp, so nothing to wait for.
    ctx->r2 = 0; // return 0 (success)
;}
RECOMP_FUNC void stub_80138C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // Get SN64 ctl bank size. a0 = ROM address of bank (e.g. 0x906290).
    // The bank size is known to be 0x11008 bytes for Rampage World Tour.
    // This value is used by func_800648A4 to allocate a buffer for the ctl bank.
    uint32_t rom_addr = (uint32_t)ctx->r4;
    ctx->r2 = (uint64_t)0x11008;
    fprintf(stderr, "[SN64] getCtlBankSize(ROM=0x%08X) -> 0x%X\n",
            rom_addr, (unsigned)ctx->r2);
    fflush(stderr);
;}
RECOMP_FUNC void stub_80138EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // DMA SN64 ctl bank from ROM to RDRAM.
    // a0 = ROM address, a1 = RDRAM dest (N64 virtual addr), a2 = size
    uint32_t rom_addr = (uint32_t)ctx->r4;
    uint32_t rdram_dest = (uint32_t)ctx->r5;
    uint32_t size = (uint32_t)ctx->r6;
    sn64_rom_to_rdram(rdram, rom_addr, rdram_dest, size);
    ctx->r2 = 0; // return success
;}
RECOMP_FUNC void stub_80139D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
