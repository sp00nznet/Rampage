#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_800405C4(uint8_t* rdram, recomp_context* ctx);
void func_80040CD8(uint8_t* rdram, recomp_context* ctx);
void func_80040D50(uint8_t* rdram, recomp_context* ctx);
void func_80040EEC(uint8_t* rdram, recomp_context* ctx);
void func_80040F28(uint8_t* rdram, recomp_context* ctx);
void func_80040F44(uint8_t* rdram, recomp_context* ctx);
void func_8004175C(uint8_t* rdram, recomp_context* ctx);
void func_80041894(uint8_t* rdram, recomp_context* ctx);
void func_80041A44(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80040310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040314: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80040318: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004031C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80040320: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x80040324: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80040328: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8004032C: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x80040330: jal         0x80040F44
    // 0x80040334: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    func_80040F44(rdram, ctx);
        goto after_0;
    // 0x80040334: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    after_0:
    // 0x80040338: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8004033C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040340: jr          $ra
    // 0x80040344: nop

    return;
    // 0x80040344: nop

;}
RECOMP_FUNC void func_80040348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004034C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80040350: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80040354: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80040358: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x8004035C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040360: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80040364: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x80040368: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x8004036C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80040370: lw          $a0, 0x3294($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3294);
    // 0x80040374: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x80040378: and         $a1, $a1, $a0
    ctx->r5 = ctx->r5 & ctx->r4;
    // 0x8004037C: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
    // 0x80040380: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80040384: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80040388: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8004038C: addiu       $a1, $v0, 0x6500
    ctx->r5 = ADD32(ctx->r2, 0X6500);
    // 0x80040390: sw          $a1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r5;
    // 0x80040394: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80040398: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8004039C: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x800403A0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800403A4: blez        $a1, L_800403D4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800403A8: sw          $v0, 0x18($v1)
        MEM_W(0X18, ctx->r3) = ctx->r2;
            goto L_800403D4;
    }
    // 0x800403A8: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x800403AC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800403B0: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x800403B4: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x800403B8: lui         $v0, 0xA5
    ctx->r2 = S32(0XA5 << 16);
    // 0x800403BC: ori         $v0, $v0, 0xC100
    ctx->r2 = ctx->r2 | 0XC100;
    // 0x800403C0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800403C4: beq         $v0, $zero, L_800403D4
    if (ctx->r2 == 0) {
        // 0x800403C8: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_800403D4;
    }
    // 0x800403C8: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x800403CC: jal         0x80040F44
    // 0x800403D0: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    func_80040F44(rdram, ctx);
        goto after_0;
    // 0x800403D0: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    after_0:
L_800403D4:
    // 0x800403D4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800403D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800403DC: jr          $ra
    // 0x800403E0: nop

    return;
    // 0x800403E0: nop

;}
RECOMP_FUNC void func_800403E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800403E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800403E8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800403EC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800403F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800403F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800403F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800403FC: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x80040400: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040404: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80040408: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    // 0x8004040C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80040410: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80040414: lw          $a0, 0x3294($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3294);
    // 0x80040418: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8004041C: and         $a1, $a1, $a0
    ctx->r5 = ctx->r5 & ctx->r4;
    // 0x80040420: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
    // 0x80040424: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80040428: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8004042C: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x80040430: addiu       $a1, $v0, 0x6500
    ctx->r5 = ADD32(ctx->r2, 0X6500);
    // 0x80040434: sw          $a1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r5;
    // 0x80040438: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004043C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80040440: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x80040444: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80040448: blez        $a1, L_80040484
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8004044C: sw          $v0, 0x18($v1)
        MEM_W(0X18, ctx->r3) = ctx->r2;
            goto L_80040484;
    }
    // 0x8004044C: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80040450: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80040454: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80040458: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x8004045C: lui         $v0, 0xE0
    ctx->r2 = S32(0XE0 << 16);
    // 0x80040460: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80040464: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80040468: beq         $v0, $zero, L_80040484
    if (ctx->r2 == 0) {
        // 0x8004046C: lui         $v0, 0xE1
        ctx->r2 = S32(0XE1 << 16);
            goto L_80040484;
    }
    // 0x8004046C: lui         $v0, 0xE1
    ctx->r2 = S32(0XE1 << 16);
    // 0x80040470: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x80040474: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80040478: jal         0x80040EEC
    // 0x8004047C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80040EEC(rdram, ctx);
        goto after_0;
    // 0x8004047C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80040480: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
L_80040484:
    // 0x80040484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040488: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004048C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040490: jr          $ra
    // 0x80040494: nop

    return;
    // 0x80040494: nop

;}
RECOMP_FUNC void func_80040498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004049C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800404A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800404A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800404A8: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x800404AC: lhu         $v0, 0x28($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X28);
    // 0x800404B0: beq         $v0, $zero, L_800404C8
    if (ctx->r2 == 0) {
        // 0x800404B4: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_800404C8;
    }
    // 0x800404B4: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x800404B8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800404BC: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800404C0: jal         0x80040F44
    // 0x800404C4: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    func_80040F44(rdram, ctx);
        goto after_0;
    // 0x800404C4: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    after_0:
L_800404C8:
    // 0x800404C8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800404CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800404D0: jr          $ra
    // 0x800404D4: nop

    return;
    // 0x800404D4: nop

;}
RECOMP_FUNC void func_800404D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800404D8: jr          $ra
    // 0x800404DC: nop

    return;
    // 0x800404DC: nop

;}
RECOMP_FUNC void func_800404E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800404E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800404E4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800404E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800404EC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800404F0: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x800404F4: lhu         $v0, 0x28($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X28);
    // 0x800404F8: beq         $v0, $zero, L_80040514
    if (ctx->r2 == 0) {
        // 0x800404FC: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_80040514;
    }
    // 0x800404FC: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x80040500: sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // 0x80040504: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80040508: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8004050C: jal         0x80040F44
    // 0x80040510: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    func_80040F44(rdram, ctx);
        goto after_0;
    // 0x80040510: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    after_0:
L_80040514:
    // 0x80040514: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80040518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004051C: jr          $ra
    // 0x80040520: nop

    return;
    // 0x80040520: nop

;}
RECOMP_FUNC void func_80040524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040528: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004052C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80040530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040534: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80040538: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004053C: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x80040540: lhu         $v0, 0x28($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X28);
    // 0x80040544: beq         $v0, $zero, L_8004058C
    if (ctx->r2 == 0) {
        // 0x80040548: lui         $v0, 0xFFF6
        ctx->r2 = S32(0XFFF6 << 16);
            goto L_8004058C;
    }
    // 0x80040548: lui         $v0, 0xFFF6
    ctx->r2 = S32(0XFFF6 << 16);
    // 0x8004054C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80040550: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80040554: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80040558: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004055C: lw          $a2, 0x31C0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X31C0);
    // 0x80040560: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80040564: lw          $v0, 0x18($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X18);
    // 0x80040568: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004056C: lui         $v1, 0xFFF8
    ctx->r3 = S32(0XFFF8 << 16);
    // 0x80040570: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80040574: jal         0x80040EEC
    // 0x80040578: sw          $v0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r2;
    func_80040EEC(rdram, ctx);
        goto after_0;
    // 0x80040578: sw          $v0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r2;
    after_0:
    // 0x8004057C: jal         0x800405C4
    // 0x80040580: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800405C4(rdram, ctx);
        goto after_1;
    // 0x80040580: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80040584: j           L_800405B0
    // 0x80040588: nop

        goto L_800405B0;
    // 0x80040588: nop

L_8004058C:
    // 0x8004058C: lh          $v0, 0x12($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X12);
    // 0x80040590: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80040594: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x80040598: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8004059C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800405A0: beq         $v1, $zero, L_800405B0
    if (ctx->r3 == 0) {
        // 0x800405A4: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_800405B0;
    }
    // 0x800405A4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800405A8: jal         0x80040EEC
    // 0x800405AC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80040EEC(rdram, ctx);
        goto after_2;
    // 0x800405AC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
L_800405B0:
    // 0x800405B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800405B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800405B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800405BC: jr          $ra
    // 0x800405C0: nop

    return;
    // 0x800405C0: nop

;}
RECOMP_FUNC void func_800405C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800405C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800405C8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800405CC: lhu         $a0, 0x3E($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X3E);
    // 0x800405D0: sltu        $v0, $zero, $a0
    ctx->r2 = 0 < ctx->r4 ? 1 : 0;
    // 0x800405D4: sltiu       $v1, $a0, 0x6
    ctx->r3 = ctx->r4 < 0X6 ? 1 : 0;
    // 0x800405D8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800405DC: beq         $v0, $zero, L_800405F8
    if (ctx->r2 == 0) {
        // 0x800405E0: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_800405F8;
    }
    // 0x800405E0: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800405E4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800405E8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800405EC: lw          $v0, -0x7EE0($at)
    ctx->r2 = MEM_W(ctx->r1, -0X7EE0);
    // 0x800405F0: jalr        $v0
    // 0x800405F4: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800405F4: nop

    after_0:
L_800405F8:
    // 0x800405F8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800405FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040600: jr          $ra
    // 0x80040604: nop

    return;
    // 0x80040604: nop

;}
RECOMP_FUNC void func_80040608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040608: jr          $ra
    // 0x8004060C: nop

    return;
    // 0x8004060C: nop

;}
RECOMP_FUNC void func_80040610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040610: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040614: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80040610 falls into func_80040618
    func_80040618(rdram, ctx);
;}
RECOMP_FUNC void func_80040618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004061C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80040620: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80040624: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80040628: bne         $v0, $zero, L_80040638
    if (ctx->r2 != 0) {
        // 0x8004062C: nop
    
            goto L_80040638;
    }
    // 0x8004062C: nop

    // 0x80040630: jal         0x8004C79C
    // 0x80040634: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_8004C79C(rdram, ctx);
        goto after_0;
    // 0x80040634: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_0:
L_80040638:
    // 0x80040638: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8004063C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040640: jr          $ra
    // 0x80040644: nop

    return;
    // 0x80040644: nop

;}
RECOMP_FUNC void func_80040648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040648: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004064C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80040648 falls into func_80040650
    func_80040650(rdram, ctx);
;}
RECOMP_FUNC void func_80040650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040650: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040654: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80040658: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x8004065C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80040660: bne         $v0, $zero, L_80040670
    if (ctx->r2 != 0) {
        // 0x80040664: nop
    
            goto L_80040670;
    }
    // 0x80040664: nop

    // 0x80040668: jal         0x8004C79C
    // 0x8004066C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_8004C79C(rdram, ctx);
        goto after_0;
    // 0x8004066C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
L_80040670:
    // 0x80040670: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80040674: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040678: jr          $ra
    // 0x8004067C: nop

    return;
    // 0x8004067C: nop

;}
RECOMP_FUNC void func_80040680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040680: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040684: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80040680 falls into func_80040688
    func_80040688(rdram, ctx);
;}
RECOMP_FUNC void func_80040688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004068C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80040690: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80040694: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80040698: bne         $v0, $zero, L_800406A8
    if (ctx->r2 != 0) {
        // 0x8004069C: nop
    
            goto L_800406A8;
    }
    // 0x8004069C: nop

    // 0x800406A0: jal         0x8004C79C
    // 0x800406A4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_8004C79C(rdram, ctx);
        goto after_0;
    // 0x800406A4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
L_800406A8:
    // 0x800406A8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800406AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800406B0: jr          $ra
    // 0x800406B4: nop

    return;
    // 0x800406B4: nop

;}
RECOMP_FUNC void func_800406B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800406B8: jr          $ra
    // 0x800406BC: nop

    return;
    // 0x800406BC: nop

;}
RECOMP_FUNC void func_800406C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800406C0: jr          $ra
    // 0x800406C4: nop

    return;
    // 0x800406C4: nop

;}
RECOMP_FUNC void func_800406C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800406C8: jr          $ra
    // 0x800406CC: nop

    return;
    // 0x800406CC: nop

;}
RECOMP_FUNC void func_800406D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800406D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800406D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800406D8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800406DC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800406E0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800406E4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800406E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800406EC: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x800406F0: lhu         $v0, 0x28($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X28);
    // 0x800406F4: beq         $v0, $zero, L_80040760
    if (ctx->r2 == 0) {
        // 0x800406F8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80040760;
    }
    // 0x800406F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800406FC: lhu         $v1, 0x14($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X14);
    // 0x80040700: beq         $v1, $v0, L_80040744
    if (ctx->r3 == ctx->r2) {
        // 0x80040704: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_80040744;
    }
    // 0x80040704: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80040708: beql        $v0, $zero, L_80040720
    if (ctx->r2 == 0) {
        // 0x8004070C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80040720;
    }
    goto skip_0;
    // 0x8004070C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
    // 0x80040710: beq         $v1, $zero, L_80040730
    if (ctx->r3 == 0) {
        // 0x80040714: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_80040730;
    }
    // 0x80040714: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80040718: j           L_8004074C
    // 0x8004071C: sh          $zero, 0x14($s1)
    MEM_H(0X14, ctx->r17) = 0;
        goto L_8004074C;
    // 0x8004071C: sh          $zero, 0x14($s1)
    MEM_H(0X14, ctx->r17) = 0;
L_80040720:
    // 0x80040720: beq         $v1, $v0, L_80040750
    if (ctx->r3 == ctx->r2) {
        // 0x80040724: addiu       $s0, $zero, 0x3
        ctx->r16 = ADD32(0, 0X3);
            goto L_80040750;
    }
    // 0x80040724: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80040728: j           L_8004074C
    // 0x8004072C: sh          $zero, 0x14($s1)
    MEM_H(0X14, ctx->r17) = 0;
        goto L_8004074C;
    // 0x8004072C: sh          $zero, 0x14($s1)
    MEM_H(0X14, ctx->r17) = 0;
L_80040730:
    // 0x80040730: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80040734: jal         0x80040EEC
    // 0x80040738: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80040EEC(rdram, ctx);
        goto after_0;
    // 0x80040738: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8004073C: j           L_80040750
    // 0x80040740: sh          $s0, 0x28($s1)
    MEM_H(0X28, ctx->r17) = ctx->r16;
        goto L_80040750;
    // 0x80040740: sh          $s0, 0x28($s1)
    MEM_H(0X28, ctx->r17) = ctx->r16;
L_80040744:
    // 0x80040744: j           L_80040750
    // 0x80040748: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80040750;
    // 0x80040748: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_8004074C:
    // 0x8004074C: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_80040750:
    // 0x80040750: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80040754: jal         0x80040EEC
    // 0x80040758: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80040EEC(rdram, ctx);
        goto after_1;
    // 0x80040758: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8004075C: sh          $zero, 0x28($s1)
    MEM_H(0X28, ctx->r17) = 0;
L_80040760:
    // 0x80040760: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80040764: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80040768: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004076C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80040770: jr          $ra
    // 0x80040774: nop

    return;
    // 0x80040774: nop

;}
RECOMP_FUNC void func_80040778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040778: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004077C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80040780: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80040784: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040788: addiu       $v0, $v0, 0x31C0
    ctx->r2 = ADD32(ctx->r2, 0X31C0);
    // 0x8004078C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80040790: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80040794: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80040798: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004079C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800407A0: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x800407A4: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800407A8: lhu         $v0, 0x30($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X30);
    // 0x800407AC: bne         $v0, $zero, L_80040860
    if (ctx->r2 != 0) {
        // 0x800407B0: nop
    
            goto L_80040860;
    }
    // 0x800407B0: nop

    // 0x800407B4: lhu         $v0, 0x28($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X28);
    // 0x800407B8: beq         $v0, $zero, L_80040854
    if (ctx->r2 == 0) {
        // 0x800407BC: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_80040854;
    }
    // 0x800407BC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800407C0: lhu         $v1, 0x32($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X32);
    // 0x800407C4: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x800407C8: sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
    // 0x800407CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800407D0: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x800407D4: jal         0x80040CD8
    // 0x800407D8: sh          $v1, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r3;
    func_80040CD8(rdram, ctx);
        goto after_0;
    // 0x800407D8: sh          $v1, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r3;
    after_0:
    // 0x800407DC: lhu         $v0, 0x32($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X32);
    // 0x800407E0: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x800407E4: bne         $v0, $zero, L_80040854
    if (ctx->r2 != 0) {
        // 0x800407E8: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80040854;
    }
    // 0x800407E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800407EC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800407F0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800407F4: lhu         $s0, 0x1E($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X1E);
    // 0x800407F8: lhu         $s1, 0x1C($v0)
    ctx->r17 = MEM_HU(ctx->r2, 0X1C);
    // 0x800407FC: jal         0x80040EEC
    // 0x80040800: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80040EEC(rdram, ctx);
        goto after_1;
    // 0x80040800: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
    // 0x80040804: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040808: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8004080C: lw          $v0, 0x48($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X48);
    // 0x80040810: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80040814: jal         0x8005F340
    // 0x80040818: nop

    func_8005F340(rdram, ctx);
        goto after_2;
    // 0x80040818: nop

    after_2:
    // 0x8004081C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80040820: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80040824: lhu         $a1, 0xA($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0XA);
    // 0x80040828: lhu         $v1, 0x14($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X14);
    // 0x8004082C: subu        $s0, $a1, $s0
    ctx->r16 = SUB32(ctx->r5, ctx->r16);
    // 0x80040830: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x80040834: sh          $v1, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r3;
    // 0x80040838: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004083C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80040840: lhu         $a1, 0x8($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X8);
    // 0x80040844: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x80040848: subu        $s1, $a1, $s1
    ctx->r17 = SUB32(ctx->r5, ctx->r17);
    // 0x8004084C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80040850: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
L_80040854:
    // 0x80040854: lhu         $v0, 0x30($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X30);
    // 0x80040858: beql        $v0, $zero, L_80040870
    if (ctx->r2 == 0) {
        // 0x8004085C: sh          $zero, 0x28($s2)
        MEM_H(0X28, ctx->r18) = 0;
            goto L_80040870;
    }
    goto skip_0;
    // 0x8004085C: sh          $zero, 0x28($s2)
    MEM_H(0X28, ctx->r18) = 0;
    skip_0:
L_80040860:
    // 0x80040860: lhu         $v0, 0x30($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X30);
    // 0x80040864: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80040868: sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
    // 0x8004086C: sh          $zero, 0x28($s2)
    MEM_H(0X28, ctx->r18) = 0;
L_80040870:
    // 0x80040870: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80040874: sw          $s3, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r19;
    // 0x80040878: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8004087C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80040880: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80040884: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80040888: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004088C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80040890: jr          $ra
    // 0x80040894: nop

    return;
    // 0x80040894: nop

;}
RECOMP_FUNC void func_80040898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040898: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004089C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800408A0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800408A4: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x800408A8: addiu       $s0, $s0, 0x31C0
    ctx->r16 = ADD32(ctx->r16, 0X31C0);
    // 0x800408AC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800408B0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800408B4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800408B8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800408BC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800408C0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800408C4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800408C8: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x800408CC: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800408D0: beq         $v0, $zero, L_800408F4
    if (ctx->r2 == 0) {
        // 0x800408D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800408F4;
    }
    // 0x800408D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800408D8: lhu         $v0, 0x16($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X16);
    // 0x800408DC: beq         $v0, $zero, L_800408F8
    if (ctx->r2 == 0) {
        // 0x800408E0: nop
    
            goto L_800408F8;
    }
    // 0x800408E0: nop

    // 0x800408E4: jal         0x80040F44
    // 0x800408E8: nop

    func_80040F44(rdram, ctx);
        goto after_0;
    // 0x800408E8: nop

    after_0:
    // 0x800408EC: j           L_80040960
    // 0x800408F0: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
        goto L_80040960;
    // 0x800408F0: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
L_800408F4:
    // 0x800408F4: sh          $v0, 0x16($a2)
    MEM_H(0X16, ctx->r6) = ctx->r2;
L_800408F8:
    // 0x800408F8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800408FC: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80040900: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x80040904: lw          $a1, 0x14($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X14);
    // 0x80040908: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004090C: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x80040910: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80040914: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80040918: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x8004091C: lhu         $v0, 0x30($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X30);
    // 0x80040920: bne         $v0, $zero, L_80040958
    if (ctx->r2 != 0) {
        // 0x80040924: nop
    
            goto L_80040958;
    }
    // 0x80040924: nop

    // 0x80040928: lhu         $v0, 0x28($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X28);
    // 0x8004092C: beq         $v0, $zero, L_80040958
    if (ctx->r2 == 0) {
        // 0x80040930: addiu       $v1, $zero, 0x3C
        ctx->r3 = ADD32(0, 0X3C);
            goto L_80040958;
    }
    // 0x80040930: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x80040934: lhu         $v0, 0x32($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X32);
    // 0x80040938: sh          $v1, 0x30($a2)
    MEM_H(0X30, ctx->r6) = ctx->r3;
    // 0x8004093C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80040940: sh          $v0, 0x32($a2)
    MEM_H(0X32, ctx->r6) = ctx->r2;
    // 0x80040944: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80040948: beq         $v0, $zero, L_80040958
    if (ctx->r2 == 0) {
        // 0x8004094C: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80040958;
    }
    // 0x8004094C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80040950: jal         0x80040EEC
    // 0x80040954: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    func_80040EEC(rdram, ctx);
        goto after_1;
    // 0x80040954: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    after_1:
L_80040958:
    // 0x80040958: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004095C: sw          $s1, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r17;
L_80040960:
    // 0x80040960: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80040964: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80040968: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004096C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80040970: jr          $ra
    // 0x80040974: nop

    return;
    // 0x80040974: nop

;}
RECOMP_FUNC void func_80040978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040978: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004097C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80040980: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80040984: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80040988: addiu       $v1, $v1, 0x31C0
    ctx->r3 = ADD32(ctx->r3, 0X31C0);
    // 0x8004098C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80040990: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80040994: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80040998: lw          $s1, 0x0($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X0);
    // 0x8004099C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800409A0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800409A4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800409A8: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x800409AC: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800409B0: beq         $v0, $zero, L_800409D4
    if (ctx->r2 == 0) {
        // 0x800409B4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800409D4;
    }
    // 0x800409B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800409B8: lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X16);
    // 0x800409BC: beql        $v0, $zero, L_80040A6C
    if (ctx->r2 == 0) {
        // 0x800409C0: sw          $s1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r17;
            goto L_80040A6C;
    }
    goto skip_0;
    // 0x800409C0: sw          $s1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r17;
    skip_0:
    // 0x800409C4: jal         0x80040F44
    // 0x800409C8: nop

    func_80040F44(rdram, ctx);
        goto after_0;
    // 0x800409C8: nop

    after_0:
    // 0x800409CC: j           L_800409D8
    // 0x800409D0: nop

        goto L_800409D8;
    // 0x800409D0: nop

L_800409D4:
    // 0x800409D4: sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
L_800409D8:
    // 0x800409D8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800409DC: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x800409E0: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x800409E4: lw          $a1, 0x14($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X14);
    // 0x800409E8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800409EC: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x800409F0: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800409F4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800409F8: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x800409FC: lhu         $v0, 0x30($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X30);
    // 0x80040A00: bne         $v0, $zero, L_80040A54
    if (ctx->r2 != 0) {
        // 0x80040A04: nop
    
            goto L_80040A54;
    }
    // 0x80040A04: nop

    // 0x80040A08: lhu         $v0, 0x28($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X28);
    // 0x80040A0C: beq         $v0, $zero, L_80040A48
    if (ctx->r2 == 0) {
        // 0x80040A10: addiu       $v0, $zero, 0x3C
        ctx->r2 = ADD32(0, 0X3C);
            goto L_80040A48;
    }
    // 0x80040A10: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80040A14: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x80040A18: sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // 0x80040A1C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040A20: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80040A24: sw          $v0, 0x218($v1)
    MEM_W(0X218, ctx->r3) = ctx->r2;
    // 0x80040A28: lhu         $v0, 0x32($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X32);
    // 0x80040A2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80040A30: sh          $v0, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r2;
    // 0x80040A34: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80040A38: beq         $v0, $zero, L_80040A48
    if (ctx->r2 == 0) {
        // 0x80040A3C: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80040A48;
    }
    // 0x80040A3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80040A40: jal         0x80040EEC
    // 0x80040A44: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80040EEC(rdram, ctx);
        goto after_1;
    // 0x80040A44: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
L_80040A48:
    // 0x80040A48: lhu         $v0, 0x30($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X30);
    // 0x80040A4C: beql        $v0, $zero, L_80040A64
    if (ctx->r2 == 0) {
        // 0x80040A50: sh          $zero, 0x28($s0)
        MEM_H(0X28, ctx->r16) = 0;
            goto L_80040A64;
    }
    goto skip_1;
    // 0x80040A50: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    skip_1:
L_80040A54:
    // 0x80040A54: lhu         $v0, 0x30($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X30);
    // 0x80040A58: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80040A5C: sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // 0x80040A60: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
L_80040A64:
    // 0x80040A64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80040A68: sw          $s1, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r17;
L_80040A6C:
    // 0x80040A6C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80040A70: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80040A74: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80040A78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80040A7C: jr          $ra
    // 0x80040A80: nop

    return;
    // 0x80040A80: nop

;}
RECOMP_FUNC void func_80040A84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040A84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80040A88: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80040A8C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80040A90: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80040A94: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80040A98: addiu       $s1, $s1, 0x31C0
    ctx->r17 = ADD32(ctx->r17, 0X31C0);
    // 0x80040A9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80040AA0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80040AA4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80040AA8: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x80040AAC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80040AB0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040AB4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80040AB8: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80040ABC: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80040AC0: beq         $v0, $zero, L_80040AE4
    if (ctx->r2 == 0) {
        // 0x80040AC4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80040AE4;
    }
    // 0x80040AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80040AC8: lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X16);
    // 0x80040ACC: beq         $v0, $zero, L_80040AE8
    if (ctx->r2 == 0) {
        // 0x80040AD0: nop
    
            goto L_80040AE8;
    }
    // 0x80040AD0: nop

    // 0x80040AD4: jal         0x80040F44
    // 0x80040AD8: nop

    func_80040F44(rdram, ctx);
        goto after_0;
    // 0x80040AD8: nop

    after_0:
    // 0x80040ADC: j           L_80040B88
    // 0x80040AE0: sw          $s2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r18;
        goto L_80040B88;
    // 0x80040AE0: sw          $s2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r18;
L_80040AE4:
    // 0x80040AE4: sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
L_80040AE8:
    // 0x80040AE8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80040AEC: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80040AF0: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x80040AF4: lw          $a1, 0x14($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X14);
    // 0x80040AF8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040AFC: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x80040B00: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80040B04: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80040B08: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x80040B0C: lhu         $v0, 0x30($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X30);
    // 0x80040B10: bne         $v0, $zero, L_80040B70
    if (ctx->r2 != 0) {
        // 0x80040B14: nop
    
            goto L_80040B70;
    }
    // 0x80040B14: nop

    // 0x80040B18: lhu         $v0, 0x28($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X28);
    // 0x80040B1C: beq         $v0, $zero, L_80040B64
    if (ctx->r2 == 0) {
        // 0x80040B20: addiu       $v0, $zero, 0x3C
        ctx->r2 = ADD32(0, 0X3C);
            goto L_80040B64;
    }
    // 0x80040B20: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80040B24: lhu         $v1, 0x32($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X32);
    // 0x80040B28: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80040B2C: sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // 0x80040B30: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80040B34: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x80040B38: jal         0x80040D50
    // 0x80040B3C: sh          $v1, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r3;
    func_80040D50(rdram, ctx);
        goto after_1;
    // 0x80040B3C: sh          $v1, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r3;
    after_1:
    // 0x80040B40: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x80040B44: lhu         $v0, 0x204($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X204);
    // 0x80040B48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80040B4C: sh          $v0, 0x204($v1)
    MEM_H(0X204, ctx->r3) = ctx->r2;
    // 0x80040B50: lhu         $v0, 0x32($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X32);
    // 0x80040B54: beq         $v0, $zero, L_80040B64
    if (ctx->r2 == 0) {
        // 0x80040B58: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80040B64;
    }
    // 0x80040B58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80040B5C: jal         0x80040EEC
    // 0x80040B60: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80040EEC(rdram, ctx);
        goto after_2;
    // 0x80040B60: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
L_80040B64:
    // 0x80040B64: lhu         $v0, 0x30($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X30);
    // 0x80040B68: beql        $v0, $zero, L_80040B80
    if (ctx->r2 == 0) {
        // 0x80040B6C: sh          $zero, 0x28($s0)
        MEM_H(0X28, ctx->r16) = 0;
            goto L_80040B80;
    }
    goto skip_0;
    // 0x80040B6C: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    skip_0:
L_80040B70:
    // 0x80040B70: lhu         $v0, 0x30($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X30);
    // 0x80040B74: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80040B78: sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // 0x80040B7C: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
L_80040B80:
    // 0x80040B80: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80040B84: sw          $s2, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r18;
L_80040B88:
    // 0x80040B88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80040B8C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80040B90: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80040B94: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80040B98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80040B9C: jr          $ra
    // 0x80040BA0: nop

    return;
    // 0x80040BA0: nop

;}
RECOMP_FUNC void func_80040BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040BA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80040BA8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80040BAC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80040BB0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040BB4: addiu       $v0, $v0, 0x31C0
    ctx->r2 = ADD32(ctx->r2, 0X31C0);
    // 0x80040BB8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80040BBC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80040BC0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80040BC4: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x80040BC8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80040BCC: lhu         $v0, 0x30($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X30);
    // 0x80040BD0: bne         $v0, $zero, L_80040C20
    if (ctx->r2 != 0) {
        // 0x80040BD4: nop
    
            goto L_80040C20;
    }
    // 0x80040BD4: nop

    // 0x80040BD8: lhu         $v0, 0x28($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X28);
    // 0x80040BDC: beq         $v0, $zero, L_80040C20
    if (ctx->r2 == 0) {
        // 0x80040BE0: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80040C20;
    }
    // 0x80040BE0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80040BE4: lhu         $v1, 0x32($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X32);
    // 0x80040BE8: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80040BEC: sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // 0x80040BF0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80040BF4: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x80040BF8: jal         0x80040CD8
    // 0x80040BFC: sh          $v1, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r3;
    func_80040CD8(rdram, ctx);
        goto after_0;
    // 0x80040BFC: sh          $v1, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r3;
    after_0:
    // 0x80040C00: lhu         $v0, 0x32($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X32);
    // 0x80040C04: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x80040C08: bne         $v0, $zero, L_80040CA4
    if (ctx->r2 != 0) {
        // 0x80040C0C: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80040CA4;
    }
    // 0x80040C0C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80040C10: jal         0x80040EEC
    // 0x80040C14: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80040EEC(rdram, ctx);
        goto after_1;
    // 0x80040C14: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80040C18: j           L_80040CA4
    // 0x80040C1C: nop

        goto L_80040CA4;
    // 0x80040C1C: nop

L_80040C20:
    // 0x80040C20: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040C24: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80040C28: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x80040C2C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80040C30: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80040C34: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x80040C38: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80040C3C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80040C40: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80040C44: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80040C48: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80040C4C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80040C50: lw          $a2, 0x31C0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X31C0);
    // 0x80040C54: lh          $v1, 0x38($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X38);
    // 0x80040C58: lh          $a1, 0x14($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X14);
    // 0x80040C5C: subu        $a0, $a1, $v1
    ctx->r4 = SUB32(ctx->r5, ctx->r3);
    // 0x80040C60: bltzl       $a0, L_80040C68
    if (SIGNED(ctx->r4) < 0) {
        // 0x80040C64: subu        $a0, $v1, $a1
        ctx->r4 = SUB32(ctx->r3, ctx->r5);
            goto L_80040C68;
    }
    goto skip_0;
    // 0x80040C64: subu        $a0, $v1, $a1
    ctx->r4 = SUB32(ctx->r3, ctx->r5);
    skip_0:
L_80040C68:
    // 0x80040C68: slti        $v0, $a0, 0x32
    ctx->r2 = SIGNED(ctx->r4) < 0X32 ? 1 : 0;
    // 0x80040C6C: beql        $v0, $zero, L_80040C90
    if (ctx->r2 == 0) {
        // 0x80040C70: addiu       $a0, $v1, 0x32
        ctx->r4 = ADD32(ctx->r3, 0X32);
            goto L_80040C90;
    }
    goto skip_1;
    // 0x80040C70: addiu       $a0, $v1, 0x32
    ctx->r4 = ADD32(ctx->r3, 0X32);
    skip_1:
    // 0x80040C74: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    // 0x80040C78: beq         $v0, $zero, L_80040C88
    if (ctx->r2 == 0) {
        // 0x80040C7C: addiu       $v0, $zero, 0x3500
        ctx->r2 = ADD32(0, 0X3500);
            goto L_80040C88;
    }
    // 0x80040C7C: addiu       $v0, $zero, 0x3500
    ctx->r2 = ADD32(0, 0X3500);
    // 0x80040C80: j           L_80040CA4
    // 0x80040C84: sw          $zero, 0x84($a2)
    MEM_W(0X84, ctx->r6) = 0;
        goto L_80040CA4;
    // 0x80040C84: sw          $zero, 0x84($a2)
    MEM_W(0X84, ctx->r6) = 0;
L_80040C88:
    // 0x80040C88: j           L_80040CA4
    // 0x80040C8C: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
        goto L_80040CA4;
    // 0x80040C8C: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
L_80040C90:
    // 0x80040C90: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80040C94: beq         $v0, $zero, L_80040CA0
    if (ctx->r2 == 0) {
        // 0x80040C98: addiu       $v1, $zero, 0x300
        ctx->r3 = ADD32(0, 0X300);
            goto L_80040CA0;
    }
    // 0x80040C98: addiu       $v1, $zero, 0x300
    ctx->r3 = ADD32(0, 0X300);
    // 0x80040C9C: addiu       $v1, $zero, -0x300
    ctx->r3 = ADD32(0, -0X300);
L_80040CA0:
    // 0x80040CA0: sw          $v1, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->r3;
L_80040CA4:
    // 0x80040CA4: lhu         $v0, 0x30($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X30);
    // 0x80040CA8: beq         $v0, $zero, L_80040CB4
    if (ctx->r2 == 0) {
        // 0x80040CAC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80040CB4;
    }
    // 0x80040CAC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80040CB0: sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
L_80040CB4:
    // 0x80040CB4: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    // 0x80040CB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80040CBC: sw          $s1, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r17;
    // 0x80040CC0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80040CC4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80040CC8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80040CCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80040CD0: jr          $ra
    // 0x80040CD4: nop

    return;
    // 0x80040CD4: nop

;}
RECOMP_FUNC void func_80040CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040CD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80040CDC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80040CE0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80040CE4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80040CE8: sltiu       $v0, $v0, 0x7
    ctx->r2 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x80040CEC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80040CF0: bne         $v0, $zero, L_80040CFC
    if (ctx->r2 != 0) {
        // 0x80040CF4: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_80040CFC;
    }
    // 0x80040CF4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80040CF8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_80040CFC:
    // 0x80040CFC: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80040D00: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80040D04: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x80040D08: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80040D0C: addiu       $v1, $v1, -0x7EC8
    ctx->r3 = ADD32(ctx->r3, -0X7EC8);
    // 0x80040D10: beq         $a1, $zero, L_80040D24
    if (ctx->r5 == 0) {
        // 0x80040D14: addu        $s1, $v0, $v1
        ctx->r17 = ADD32(ctx->r2, ctx->r3);
            goto L_80040D24;
    }
    // 0x80040D14: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // 0x80040D18: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x80040D1C: jal         0x8003C34C
    // 0x80040D20: nop

    func_8003C34C(rdram, ctx);
        goto after_0;
    // 0x80040D20: nop

    after_0:
L_80040D24:
    // 0x80040D24: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80040D28: lh          $a1, 0x3A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X3A);
    // 0x80040D2C: lh          $a2, 0x3C($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X3C);
    // 0x80040D30: jal         0x80002CDC
    // 0x80040D34: nop

    func_80002CDC(rdram, ctx);
        goto after_1;
    // 0x80040D34: nop

    after_1:
    // 0x80040D38: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80040D3C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80040D40: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80040D44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80040D48: jr          $ra
    // 0x80040D4C: nop

    return;
    // 0x80040D4C: nop

;}
RECOMP_FUNC void func_80040D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040D50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80040D54: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80040D58: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80040D5C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80040D60: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80040D64: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80040D68: bne         $v0, $zero, L_80040D74
    if (ctx->r2 != 0) {
        // 0x80040D6C: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_80040D74;
    }
    // 0x80040D6C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80040D70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80040D74:
    // 0x80040D74: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80040D78: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80040D7C: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x80040D80: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80040D84: addiu       $v1, $v1, -0x7EC8
    ctx->r3 = ADD32(ctx->r3, -0X7EC8);
    // 0x80040D88: beq         $a1, $zero, L_80040D9C
    if (ctx->r5 == 0) {
        // 0x80040D8C: addu        $s1, $v0, $v1
        ctx->r17 = ADD32(ctx->r2, ctx->r3);
            goto L_80040D9C;
    }
    // 0x80040D8C: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // 0x80040D90: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x80040D94: jal         0x8003C34C
    // 0x80040D98: nop

    func_8003C34C(rdram, ctx);
        goto after_0;
    // 0x80040D98: nop

    after_0:
L_80040D9C:
    // 0x80040D9C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80040DA0: lh          $a1, 0x3A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X3A);
    // 0x80040DA4: lh          $a2, 0x3C($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X3C);
    // 0x80040DA8: jal         0x80002CDC
    // 0x80040DAC: nop

    func_80002CDC(rdram, ctx);
        goto after_1;
    // 0x80040DAC: nop

    after_1:
    // 0x80040DB0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80040DB4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80040DB8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80040DBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80040DC0: jr          $ra
    // 0x80040DC4: nop

    return;
    // 0x80040DC4: nop

;}
RECOMP_FUNC void func_80040DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040DC8: jr          $ra
    // 0x80040DCC: nop

    return;
    // 0x80040DCC: nop

;}
RECOMP_FUNC void func_80040DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040DD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80040DD4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80040DD8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80040DDC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80040DE0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80040DE4: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x80040DE8: addiu       $v0, $zero, 0x8E
    ctx->r2 = ADD32(0, 0X8E);
    // 0x80040DEC: bne         $v1, $v0, L_80040ED4
    if (ctx->r3 != ctx->r2) {
        // 0x80040DF0: nop
    
            goto L_80040ED4;
    }
    // 0x80040DF0: nop

    // 0x80040DF4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80040DF8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80040DFC: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x80040E00: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80040E04: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80040E08: lhu         $v0, 0x6C($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6C);
    // 0x80040E0C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80040E10: bne         $v0, $zero, L_80040ECC
    if (ctx->r2 != 0) {
        // 0x80040E14: nop
    
            goto L_80040ECC;
    }
    // 0x80040E14: nop

    // 0x80040E18: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x80040E1C: lw          $v1, 0x14($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X14);
    // 0x80040E20: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80040E24: lw          $a0, 0x3294($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3294);
    // 0x80040E28: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80040E2C: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x80040E30: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    // 0x80040E34: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80040E38: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80040E3C: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x80040E40: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x80040E44: addiu       $s0, $a0, 0x4000
    ctx->r16 = ADD32(ctx->r4, 0X4000);
    // 0x80040E48: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80040E4C: bltz        $s0, L_80040E94
    if (SIGNED(ctx->r16) < 0) {
        // 0x80040E50: sw          $v0, 0x18($v1)
        MEM_W(0X18, ctx->r3) = ctx->r2;
            goto L_80040E94;
    }
    // 0x80040E50: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80040E54: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040E58: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80040E5C: lh          $v0, 0x18($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X18);
    // 0x80040E60: slti        $v0, $v0, 0xDC
    ctx->r2 = SIGNED(ctx->r2) < 0XDC ? 1 : 0;
    // 0x80040E64: bne         $v0, $zero, L_80040E94
    if (ctx->r2 != 0) {
        // 0x80040E68: addiu       $a0, $zero, 0xBE
        ctx->r4 = ADD32(0, 0XBE);
            goto L_80040E94;
    }
    // 0x80040E68: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    // 0x80040E6C: jal         0x8004C86C
    // 0x80040E70: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_8004C86C(rdram, ctx);
        goto after_0;
    // 0x80040E70: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_0:
    // 0x80040E74: sra         $v0, $s0, 4
    ctx->r2 = S32(SIGNED(ctx->r16) >> 4);
    // 0x80040E78: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x80040E7C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80040E80: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80040E84: slt         $v0, $v0, $s0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80040E88: beql        $v0, $zero, L_80040E90
    if (ctx->r2 == 0) {
        // 0x80040E8C: lui         $s0, 0x2
        ctx->r16 = S32(0X2 << 16);
            goto L_80040E90;
    }
    goto skip_0;
    // 0x80040E8C: lui         $s0, 0x2
    ctx->r16 = S32(0X2 << 16);
    skip_0:
L_80040E90:
    // 0x80040E90: negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
L_80040E94:
    // 0x80040E94: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040E98: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80040E9C: sw          $s0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r16;
    // 0x80040EA0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040EA4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80040EA8: lw          $a2, 0x2C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2C);
    // 0x80040EAC: lh          $a0, 0x14($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X14);
    // 0x80040EB0: lh          $a1, 0x18($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X18);
    // 0x80040EB4: jal         0x80009C20
    // 0x80040EB8: nop

    func_80009C20(rdram, ctx);
        goto after_1;
    // 0x80040EB8: nop

    after_1:
    // 0x80040EBC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80040EC0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80040EC4: bne         $v0, $v1, L_80040ED4
    if (ctx->r2 != ctx->r3) {
        // 0x80040EC8: nop
    
            goto L_80040ED4;
    }
    // 0x80040EC8: nop

L_80040ECC:
    // 0x80040ECC: jal         0x80040F44
    // 0x80040ED0: nop

    func_80040F44(rdram, ctx);
        goto after_2;
    // 0x80040ED0: nop

    after_2:
L_80040ED4:
    // 0x80040ED4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80040ED8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80040EDC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80040EE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80040EE4: jr          $ra
    // 0x80040EE8: nop

    return;
    // 0x80040EE8: nop

;}
RECOMP_FUNC void func_80040EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040EEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040EF0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80040EF4: sh          $a0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r4;
    // 0x80040EF8: jal         0x80040F28
    // 0x80040EFC: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_80040F28(rdram, ctx);
        goto after_0;
    // 0x80040EFC: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80040F00: beq         $v0, $zero, L_80040F18
    if (ctx->r2 == 0) {
        // 0x80040F04: nop
    
            goto L_80040F18;
    }
    // 0x80040F04: nop

    // 0x80040F08: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80040F0C: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80040F10: jal         0x80037DDC
    // 0x80040F14: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x80040F14: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
L_80040F18:
    // 0x80040F18: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80040F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040F20: jr          $ra
    // 0x80040F24: nop

    return;
    // 0x80040F24: nop

;}
RECOMP_FUNC void func_80040F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040F28: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x80040F2C: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x80040F30: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80040F34: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80040F38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80040F3C: jr          $ra
    // 0x80040F40: nop

    return;
    // 0x80040F40: nop

;}
RECOMP_FUNC void func_80040F44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040F44: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040F48: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80040F44 falls into func_80040F4C
    func_80040F4C(rdram, ctx);
;}
RECOMP_FUNC void func_80040F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040F50: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80040F54: lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X90);
    // 0x80040F58: jal         0x80044514
    // 0x80040F5C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    func_80044514(rdram, ctx);
        goto after_0;
    // 0x80040F5C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    after_0:
    // 0x80040F60: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80040F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040F68: jr          $ra
    // 0x80040F6C: nop

    return;
    // 0x80040F6C: nop

;}
RECOMP_FUNC void func_80040F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040F70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040F74: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80040F78: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80040F7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80040F80: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x80040F84: jal         0x80044514
    // 0x80040F88: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    func_80044514(rdram, ctx);
        goto after_0;
    // 0x80040F88: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    after_0:
    // 0x80040F8C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80040F90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040F94: jr          $ra
    // 0x80040F98: nop

    return;
    // 0x80040F98: nop

    // 0x80040F9C: nop

;}
RECOMP_FUNC void func_80040FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040FA0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80040FA4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80040FA8: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80040FAC: bne         $v0, $zero, L_80040FF4
    if (ctx->r2 != 0) {
        // 0x80040FB0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80040FF4;
    }
    // 0x80040FB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80040FB4: lw          $a1, 0x90($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X90);
    // 0x80040FB8: sh          $v0, 0x1C8($a1)
    MEM_H(0X1C8, ctx->r5) = ctx->r2;
    // 0x80040FBC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80040FC0: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80040FC4: lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X22);
    // 0x80040FC8: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80040FCC: beq         $v0, $zero, L_80040FD8
    if (ctx->r2 == 0) {
        // 0x80040FD0: lui         $v1, 0xF
        ctx->r3 = S32(0XF << 16);
            goto L_80040FD8;
    }
    // 0x80040FD0: lui         $v1, 0xF
    ctx->r3 = S32(0XF << 16);
    // 0x80040FD4: lui         $v1, 0xFFF1
    ctx->r3 = S32(0XFFF1 << 16);
L_80040FD8:
    // 0x80040FD8: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x80040FDC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80040FE0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80040FE4: lui         $v1, 0xFFF9
    ctx->r3 = S32(0XFFF9 << 16);
    // 0x80040FE8: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80040FEC: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80040FF0: sw          $v0, 0x104($a1)
    MEM_W(0X104, ctx->r5) = ctx->r2;
L_80040FF4:
    // 0x80040FF4: jr          $ra
    // 0x80040FF8: nop

    return;
    // 0x80040FF8: nop

;}
RECOMP_FUNC void func_80040FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040FFC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80041000: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80041004: lw          $v0, 0x90($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X90);
    // 0x80041008: lhu         $v1, 0x12A($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X12A);
    // 0x8004100C: beq         $v1, $zero, L_80041054
    if (ctx->r3 == 0) {
                return; // L_80041054 is jr $ra
    }

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_80041010
    func_80041010(rdram, ctx);
}
RECOMP_FUNC void func_80041010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041010: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80041014: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80041018: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004101C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80041020: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80041024: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041028: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8004102C: addiu       $v1, $v1, 0x3F94
    ctx->r3 = ADD32(ctx->r3, 0X3F94);
    // 0x80041030: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80041034: lh          $v0, 0x122($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X122);
    // 0x80041038: beq         $v0, $zero, L_80041054
    if (ctx->r2 == 0) {
        // 0x8004103C: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80041054;
    }
    // 0x8004103C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80041040: sh          $v1, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r3;
    // 0x80041044: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80041048: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8004104C: lhu         $v0, 0x120($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X120);
    // 0x80041050: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
L_80041054:
    // 0x80041054: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80041058: jr          $ra
    // 0x8004105C: nop

    return;
    // 0x8004105C: nop

;}
RECOMP_FUNC void func_80041060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041060: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041064: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80041068: lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X90);
    // 0x8004106C: lhu         $v1, 0x12A($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X12A);
    // 0x80041070: beq         $v1, $zero, L_8004109C
    if (ctx->r3 == 0) {
        // 0x80041074: nop
    
            goto L_8004109C;
    }
    // 0x80041074: nop

    // 0x80041078: sh          $zero, 0x12A($v0)
    MEM_H(0X12A, ctx->r2) = 0;
    // 0x8004107C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80041080: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80041084: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80041088: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004108C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041090: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80041094: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80041098: sh          $zero, 0x40BE($at)
    MEM_H(0X40BE, ctx->r1) = 0;
L_8004109C:
    // 0x8004109C: jr          $ra
    // 0x800410A0: nop

    return;
    // 0x800410A0: nop

;}
RECOMP_FUNC void func_800410A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800410A4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800410A8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_800410A4 falls into func_800410AC
    func_800410AC(rdram, ctx);
;}
RECOMP_FUNC void func_800410AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800410AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800410B0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800410B4: lw          $a1, 0x90($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X90);
    // 0x800410B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800410BC: sh          $v0, 0x1C8($a1)
    MEM_H(0X1C8, ctx->r5) = ctx->r2;
    // 0x800410C0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800410C4: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x800410C8: lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X22);
    // 0x800410CC: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800410D0: beq         $v0, $zero, L_800410DC
    if (ctx->r2 == 0) {
        // 0x800410D4: lui         $v1, 0xA
        ctx->r3 = S32(0XA << 16);
            goto L_800410DC;
    }
    // 0x800410D4: lui         $v1, 0xA
    ctx->r3 = S32(0XA << 16);
    // 0x800410D8: lui         $v1, 0xFFF6
    ctx->r3 = S32(0XFFF6 << 16);
L_800410DC:
    // 0x800410DC: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x800410E0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800410E4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800410E8: lui         $v0, 0xFFF9
    ctx->r2 = S32(0XFFF9 << 16);
    // 0x800410EC: lui         $a0, 0x4
    ctx->r4 = S32(0X4 << 16);
    // 0x800410F0: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x800410F4: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x800410F8: sw          $v0, 0x104($a1)
    MEM_W(0X104, ctx->r5) = ctx->r2;
    // 0x800410FC: addiu       $v0, $zero, 0x2F
    ctx->r2 = ADD32(0, 0X2F);
    // 0x80041100: jal         0x8003BA80
    // 0x80041104: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    func_8003BA80(rdram, ctx);
        goto after_0;
    // 0x80041104: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    after_0:
    // 0x80041108: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8004110C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80041110: jr          $ra
    // 0x80041114: nop

    return;
    // 0x80041114: nop

;}
RECOMP_FUNC void func_80041118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041118: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8004111C: jr          $ra
    // 0x80041120: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    return;
    // 0x80041120: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void func_80041124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041124: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80041128: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8004112C: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x80041130: xori        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 ^ 0X10;
    // 0x80041134: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x80041138: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004113C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80041140: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x80041144: jr          $ra
    // 0x80041148: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
    return;
    // 0x80041148: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_8004114C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004114C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80041150: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x80041154: ori         $v0, $v0, 0x3E9E
    ctx->r2 = ctx->r2 | 0X3E9E;
    // 0x80041158: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8004115C: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80041160: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80041164: ori         $v1, $v1, 0x3E9A
    ctx->r3 = ctx->r3 | 0X3E9A;
    // 0x80041168: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8004116C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80041170: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80041174: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80041178: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004117C: lw          $a0, 0x38($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X38);
    // 0x80041180: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x80041184: lw          $s3, 0x31C0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X31C0);
    // 0x80041188: lw          $s1, 0x90($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X90);
    // 0x8004118C: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x80041190: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80041194: xor         $v1, $a0, $v1
    ctx->r3 = ctx->r4 ^ ctx->r3;
    // 0x80041198: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8004119C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800411A0: bne         $v0, $zero, L_800413B0
    if (ctx->r2 != 0) {
        // 0x800411A4: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_800413B0;
    }
    // 0x800411A4: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x800411A8: ori         $v0, $v0, 0x3E98
    ctx->r2 = ctx->r2 | 0X3E98;
    // 0x800411AC: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800411B0: ori         $v1, $v1, 0x3E9C
    ctx->r3 = ctx->r3 | 0X3E9C;
    // 0x800411B4: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x800411B8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800411BC: xor         $v1, $a0, $v1
    ctx->r3 = ctx->r4 ^ ctx->r3;
    // 0x800411C0: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800411C4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800411C8: bne         $v0, $zero, L_800413B0
    if (ctx->r2 != 0) {
        // 0x800411CC: lui         $v0, 0x300
        ctx->r2 = S32(0X300 << 16);
            goto L_800413B0;
    }
    // 0x800411CC: lui         $v0, 0x300
    ctx->r2 = S32(0X300 << 16);
    // 0x800411D0: ori         $v0, $v0, 0x3DFE
    ctx->r2 = ctx->r2 | 0X3DFE;
    // 0x800411D4: lui         $v1, 0x300
    ctx->r3 = S32(0X300 << 16);
    // 0x800411D8: ori         $v1, $v1, 0x3DFA
    ctx->r3 = ctx->r3 | 0X3DFA;
    // 0x800411DC: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x800411E0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800411E4: xor         $v1, $a0, $v1
    ctx->r3 = ctx->r4 ^ ctx->r3;
    // 0x800411E8: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800411EC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800411F0: bne         $v0, $zero, L_800413B0
    if (ctx->r2 != 0) {
        // 0x800411F4: lui         $v0, 0x300
        ctx->r2 = S32(0X300 << 16);
            goto L_800413B0;
    }
    // 0x800411F4: lui         $v0, 0x300
    ctx->r2 = S32(0X300 << 16);
    // 0x800411F8: ori         $v0, $v0, 0x3DF8
    ctx->r2 = ctx->r2 | 0X3DF8;
    // 0x800411FC: lui         $v1, 0x300
    ctx->r3 = S32(0X300 << 16);
    // 0x80041200: ori         $v1, $v1, 0x3DFC
    ctx->r3 = ctx->r3 | 0X3DFC;
    // 0x80041204: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x80041208: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8004120C: xor         $v1, $a0, $v1
    ctx->r3 = ctx->r4 ^ ctx->r3;
    // 0x80041210: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80041214: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80041218: bne         $v0, $zero, L_800413B0
    if (ctx->r2 != 0) {
        // 0x8004121C: lui         $v0, 0x400
        ctx->r2 = S32(0X400 << 16);
            goto L_800413B0;
    }
    // 0x8004121C: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x80041220: ori         $v0, $v0, 0x3DF6
    ctx->r2 = ctx->r2 | 0X3DF6;
    // 0x80041224: lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // 0x80041228: ori         $v1, $v1, 0x3DF2
    ctx->r3 = ctx->r3 | 0X3DF2;
    // 0x8004122C: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x80041230: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80041234: xor         $v1, $a0, $v1
    ctx->r3 = ctx->r4 ^ ctx->r3;
    // 0x80041238: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8004123C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80041240: bne         $v0, $zero, L_800413B0
    if (ctx->r2 != 0) {
        // 0x80041244: lui         $v0, 0x400
        ctx->r2 = S32(0X400 << 16);
            goto L_800413B0;
    }
    // 0x80041244: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x80041248: ori         $v0, $v0, 0x3DF0
    ctx->r2 = ctx->r2 | 0X3DF0;
    // 0x8004124C: lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // 0x80041250: ori         $v1, $v1, 0x3DF4
    ctx->r3 = ctx->r3 | 0X3DF4;
    // 0x80041254: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x80041258: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8004125C: xor         $v1, $a0, $v1
    ctx->r3 = ctx->r4 ^ ctx->r3;
    // 0x80041260: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80041264: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80041268: bne         $v0, $zero, L_800413B0
    if (ctx->r2 != 0) {
        // 0x8004126C: lui         $v0, 0xE00
        ctx->r2 = S32(0XE00 << 16);
            goto L_800413B0;
    }
    // 0x8004126C: lui         $v0, 0xE00
    ctx->r2 = S32(0XE00 << 16);
    // 0x80041270: ori         $v0, $v0, 0x3E8E
    ctx->r2 = ctx->r2 | 0X3E8E;
    // 0x80041274: lui         $v1, 0xE00
    ctx->r3 = S32(0XE00 << 16);
    // 0x80041278: ori         $v1, $v1, 0x3E8A
    ctx->r3 = ctx->r3 | 0X3E8A;
    // 0x8004127C: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x80041280: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80041284: xor         $v1, $a0, $v1
    ctx->r3 = ctx->r4 ^ ctx->r3;
    // 0x80041288: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8004128C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80041290: bne         $v0, $zero, L_800413B0
    if (ctx->r2 != 0) {
        // 0x80041294: lui         $v0, 0xE00
        ctx->r2 = S32(0XE00 << 16);
            goto L_800413B0;
    }
    // 0x80041294: lui         $v0, 0xE00
    ctx->r2 = S32(0XE00 << 16);
    // 0x80041298: ori         $v0, $v0, 0x3E88
    ctx->r2 = ctx->r2 | 0X3E88;
    // 0x8004129C: lui         $v1, 0xE00
    ctx->r3 = S32(0XE00 << 16);
    // 0x800412A0: ori         $v1, $v1, 0x3E8C
    ctx->r3 = ctx->r3 | 0X3E8C;
    // 0x800412A4: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x800412A8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800412AC: xor         $v1, $a0, $v1
    ctx->r3 = ctx->r4 ^ ctx->r3;
    // 0x800412B0: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800412B4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800412B8: bne         $v0, $zero, L_800413B0
    if (ctx->r2 != 0) {
        // 0x800412BC: lui         $v0, 0x900
        ctx->r2 = S32(0X900 << 16);
            goto L_800413B0;
    }
    // 0x800412BC: lui         $v0, 0x900
    ctx->r2 = S32(0X900 << 16);
    // 0x800412C0: ori         $v0, $v0, 0x3E94
    ctx->r2 = ctx->r2 | 0X3E94;
    // 0x800412C4: lui         $v1, 0x900
    ctx->r3 = S32(0X900 << 16);
    // 0x800412C8: ori         $v1, $v1, 0x3E92
    ctx->r3 = ctx->r3 | 0X3E92;
    // 0x800412CC: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x800412D0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800412D4: xor         $v1, $a0, $v1
    ctx->r3 = ctx->r4 ^ ctx->r3;
    // 0x800412D8: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800412DC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800412E0: bne         $v0, $zero, L_800413B0
    if (ctx->r2 != 0) {
        // 0x800412E4: lui         $v0, 0x900
        ctx->r2 = S32(0X900 << 16);
            goto L_800413B0;
    }
    // 0x800412E4: lui         $v0, 0x900
    ctx->r2 = S32(0X900 << 16);
    // 0x800412E8: ori         $v0, $v0, 0x3E90
    ctx->r2 = ctx->r2 | 0X3E90;
    // 0x800412EC: lui         $v1, 0x900
    ctx->r3 = S32(0X900 << 16);
    // 0x800412F0: ori         $v1, $v1, 0x3E96
    ctx->r3 = ctx->r3 | 0X3E96;
    // 0x800412F4: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x800412F8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800412FC: xor         $v1, $a0, $v1
    ctx->r3 = ctx->r4 ^ ctx->r3;
    // 0x80041300: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80041304: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80041308: bne         $v0, $zero, L_800413B0
    if (ctx->r2 != 0) {
        // 0x8004130C: lui         $v0, 0xC00
        ctx->r2 = S32(0XC00 << 16);
            goto L_800413B0;
    }
    // 0x8004130C: lui         $v0, 0xC00
    ctx->r2 = S32(0XC00 << 16);
    // 0x80041310: ori         $v0, $v0, 0x3E68
    ctx->r2 = ctx->r2 | 0X3E68;
    // 0x80041314: lui         $v1, 0xC00
    ctx->r3 = S32(0XC00 << 16);
    // 0x80041318: ori         $v1, $v1, 0x3E66
    ctx->r3 = ctx->r3 | 0X3E66;
    // 0x8004131C: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x80041320: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80041324: xor         $v1, $a0, $v1
    ctx->r3 = ctx->r4 ^ ctx->r3;
    // 0x80041328: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8004132C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80041330: bne         $v0, $zero, L_800413B0
    if (ctx->r2 != 0) {
        // 0x80041334: lui         $v0, 0xC00
        ctx->r2 = S32(0XC00 << 16);
            goto L_800413B0;
    }
    // 0x80041334: lui         $v0, 0xC00
    ctx->r2 = S32(0XC00 << 16);
    // 0x80041338: ori         $v0, $v0, 0x3E64
    ctx->r2 = ctx->r2 | 0X3E64;
    // 0x8004133C: lui         $v1, 0xC00
    ctx->r3 = S32(0XC00 << 16);
    // 0x80041340: ori         $v1, $v1, 0x3E6A
    ctx->r3 = ctx->r3 | 0X3E6A;
    // 0x80041344: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x80041348: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8004134C: xor         $v1, $a0, $v1
    ctx->r3 = ctx->r4 ^ ctx->r3;
    // 0x80041350: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80041354: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80041358: bne         $v0, $zero, L_800413B0
    if (ctx->r2 != 0) {
        // 0x8004135C: lui         $v0, 0xD00
        ctx->r2 = S32(0XD00 << 16);
            goto L_800413B0;
    }
    // 0x8004135C: lui         $v0, 0xD00
    ctx->r2 = S32(0XD00 << 16);
    // 0x80041360: ori         $v0, $v0, 0x3D94
    ctx->r2 = ctx->r2 | 0X3D94;
    // 0x80041364: lui         $v1, 0xD00
    ctx->r3 = S32(0XD00 << 16);
    // 0x80041368: ori         $v1, $v1, 0x3D92
    ctx->r3 = ctx->r3 | 0X3D92;
    // 0x8004136C: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x80041370: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80041374: xor         $v1, $a0, $v1
    ctx->r3 = ctx->r4 ^ ctx->r3;
    // 0x80041378: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8004137C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80041380: bne         $v0, $zero, L_800413B0
    if (ctx->r2 != 0) {
        // 0x80041384: lui         $v0, 0xD00
        ctx->r2 = S32(0XD00 << 16);
            goto L_800413B0;
    }
    // 0x80041384: lui         $v0, 0xD00
    ctx->r2 = S32(0XD00 << 16);
    // 0x80041388: ori         $v0, $v0, 0x3D90
    ctx->r2 = ctx->r2 | 0X3D90;
    // 0x8004138C: lui         $v1, 0xD00
    ctx->r3 = S32(0XD00 << 16);
    // 0x80041390: ori         $v1, $v1, 0x3D96
    ctx->r3 = ctx->r3 | 0X3D96;
    // 0x80041394: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x80041398: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8004139C: xor         $v1, $a0, $v1
    ctx->r3 = ctx->r4 ^ ctx->r3;
    // 0x800413A0: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800413A4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800413A8: beq         $v0, $zero, L_800413D4
    if (ctx->r2 == 0) {
        // 0x800413AC: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_800413D4;
    }
    // 0x800413AC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800413B0:
    // 0x800413B0: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800413B4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800413B8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800413BC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800413C0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800413C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800413C8: lhu         $v0, -0x4AF2($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X4AF2);
    // 0x800413CC: j           L_80041400
    // 0x800413D0: sh          $v0, 0x74($v1)
    MEM_H(0X74, ctx->r3) = ctx->r2;
        goto L_80041400;
    // 0x800413D0: sh          $v0, 0x74($v1)
    MEM_H(0X74, ctx->r3) = ctx->r2;
L_800413D4:
    // 0x800413D4: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x800413D8: bne         $v1, $v0, L_800413F0
    if (ctx->r3 != ctx->r2) {
        // 0x800413DC: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_800413F0;
    }
    // 0x800413DC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800413E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800413E4: lhu         $v0, -0x1D3C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X1D3C);
    // 0x800413E8: j           L_80041400
    // 0x800413EC: sh          $v0, 0x74($a1)
    MEM_H(0X74, ctx->r5) = ctx->r2;
        goto L_80041400;
    // 0x800413EC: sh          $v0, 0x74($a1)
    MEM_H(0X74, ctx->r5) = ctx->r2;
L_800413F0:
    // 0x800413F0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800413F4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800413F8: lhu         $v0, -0x4B02($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X4B02);
    // 0x800413FC: sh          $v0, 0x74($a1)
    MEM_H(0X74, ctx->r5) = ctx->r2;
L_80041400:
    // 0x80041400: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041404: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80041408: lw          $s2, 0x5C($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X5C);
    // 0x8004140C: lw          $v0, 0x16C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X16C);
    // 0x80041410: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80041414: addiu       $s0, $s0, 0x31C0
    ctx->r16 = ADD32(ctx->r16, 0X31C0);
    // 0x80041418: bne         $v0, $zero, L_80041464
    if (ctx->r2 != 0) {
        // 0x8004141C: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80041464;
    }
    // 0x8004141C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80041420: jal         0x800306EC
    // 0x80041424: nop

    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80041424: nop

    after_0:
    // 0x80041428: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004142C: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x80041430: lhu         $v1, 0x120($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X120);
    // 0x80041434: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x80041438: lhu         $v1, 0x122($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X122);
    // 0x8004143C: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x80041440: lhu         $v1, 0x80($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X80);
    // 0x80041444: lui         $a0, 0x4F00
    ctx->r4 = S32(0X4F00 << 16);
    // 0x80041448: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x8004144C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80041450: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80041454: jal         0x80023E44
    // 0x80041458: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x80041458: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    after_1:
    // 0x8004145C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80041460: sw          $v0, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->r2;
L_80041464:
    // 0x80041464: lhu         $v0, 0x80($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X80);
    // 0x80041468: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004146C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80041470: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80041474: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
    // 0x80041478: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004147C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80041480: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80041484: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80041488: lhu         $a1, 0x22($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X22);
    // 0x8004148C: jal         0x80016BA0
    // 0x80041490: nop

    func_80016BA0(rdram, ctx);
        goto after_2;
    // 0x80041490: nop

    after_2:
    // 0x80041494: sw          $s3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r19;
    // 0x80041498: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8004149C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800414A0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800414A4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800414A8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800414AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800414B0: jr          $ra
    // 0x800414B4: nop

    return;
    // 0x800414B4: nop

;}
RECOMP_FUNC void func_800414B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800414B8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800414BC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_800414B8 falls into func_800414C0
    func_800414C0(rdram, ctx);
;}
RECOMP_FUNC void func_800414C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800414C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800414C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800414C8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800414CC: lw          $s0, 0x90($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X90);
    // 0x800414D0: lhu         $v0, 0xEA($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XEA);
    // 0x800414D4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800414D8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800414DC: bne         $v0, $zero, L_8004158C
    if (ctx->r2 != 0) {
        // 0x800414E0: nop
    
            goto L_8004158C;
    }
    // 0x800414E0: nop

    // 0x800414E4: lhu         $v0, 0x1B0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B0);
    // 0x800414E8: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800414EC: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x800414F0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800414F4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800414F8: bne         $v1, $zero, L_8004158C
    if (ctx->r3 != 0) {
        // 0x800414FC: nop
    
            goto L_8004158C;
    }
    // 0x800414FC: nop

    // 0x80041500: lhu         $a0, 0x1B2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1B2);
    // 0x80041504: beq         $a0, $zero, L_8004158C
    if (ctx->r4 == 0) {
        // 0x80041508: nop
    
            goto L_8004158C;
    }
    // 0x80041508: nop

    // 0x8004150C: jal         0x8001B7D0
    // 0x80041510: nop

    func_8001B7D0(rdram, ctx);
        goto after_0;
    // 0x80041510: nop

    after_0:
    // 0x80041514: beq         $v0, $zero, L_8004158C
    if (ctx->r2 == 0) {
        // 0x80041518: nop
    
            goto L_8004158C;
    }
    // 0x80041518: nop

    // 0x8004151C: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80041520: beq         $a0, $zero, L_8004158C
    if (ctx->r4 == 0) {
        // 0x80041524: nop
    
            goto L_8004158C;
    }
    // 0x80041524: nop

    // 0x80041528: lh          $v1, 0x1C($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1C);
    // 0x8004152C: lhu         $v0, 0x1B0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B0);
    // 0x80041530: bne         $v1, $v0, L_8004158C
    if (ctx->r3 != ctx->r2) {
        // 0x80041534: nop
    
            goto L_8004158C;
    }
    // 0x80041534: nop

    // 0x80041538: lh          $v0, 0x1E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X1E);
    // 0x8004153C: lh          $v1, 0x122($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X122);
    // 0x80041540: addiu       $v0, $v0, 0xE
    ctx->r2 = ADD32(ctx->r2, 0XE);
    // 0x80041544: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80041548: bne         $v0, $zero, L_8004158C
    if (ctx->r2 != 0) {
        // 0x8004154C: nop
    
            goto L_8004158C;
    }
    // 0x8004154C: nop

    // 0x80041550: lh          $v0, 0xE($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XE);
    // 0x80041554: addiu       $v0, $v0, -0xE
    ctx->r2 = ADD32(ctx->r2, -0XE);
    // 0x80041558: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004155C: bne         $v0, $zero, L_8004158C
    if (ctx->r2 != 0) {
        // 0x80041560: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004158C;
    }
    // 0x80041560: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80041564: jal         0x8001076C
    // 0x80041568: sh          $v0, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r2;
    func_8001076C(rdram, ctx);
        goto after_1;
    // 0x80041568: sh          $v0, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r2;
    after_1:
    // 0x8004156C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80041570: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80041574: bne         $v0, $v1, L_8004158C
    if (ctx->r2 != ctx->r3) {
        // 0x80041578: lui         $a0, 0x5
        ctx->r4 = S32(0X5 << 16);
            goto L_8004158C;
    }
    // 0x80041578: lui         $a0, 0x5
    ctx->r4 = S32(0X5 << 16);
    // 0x8004157C: jal         0x8003BA80
    // 0x80041580: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003BA80(rdram, ctx);
        goto after_2;
    // 0x80041580: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80041584: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x80041588: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
L_8004158C:
    // 0x8004158C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041590: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80041594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80041598: jr          $ra
    // 0x8004159C: nop

    return;
    // 0x8004159C: nop

;}
RECOMP_FUNC void func_800415A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800415A0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800415A4: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x800415A8: lw          $v0, 0x90($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X90);
    // 0x800415AC: lw          $a0, 0x5C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X5C);
    // 0x800415B0: lhu         $v1, 0xEA($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XEA);
    // 0x800415B4: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x800415B8: addiu       $v0, $v1, -0x3
    ctx->r2 = ADD32(ctx->r3, -0X3);
    // 0x800415BC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800415C0: beq         $v0, $zero, L_800415E0
    if (ctx->r2 == 0) {
        // 0x800415C4: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800415E0;
    }
    // 0x800415C4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800415C8: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800415CC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800415D0: bnel        $v1, $v0, L_800415E0
    if (ctx->r3 != ctx->r2) {
        // 0x800415D4: sw          $a2, 0x44($a1)
        MEM_W(0X44, ctx->r5) = ctx->r6;
            goto L_800415E0;
    }
    goto skip_0;
    // 0x800415D4: sw          $a2, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r6;
    skip_0:
    // 0x800415D8: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x800415DC: sw          $a2, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r6;
L_800415E0:
    // 0x800415E0: jr          $ra
    // 0x800415E4: nop

    return;
    // 0x800415E4: nop

;}
RECOMP_FUNC void func_800415E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800415E8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800415EC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_800415E8 falls into func_800415F0
    func_800415F0(rdram, ctx);
;}
RECOMP_FUNC void func_800415F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800415F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800415F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800415F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800415FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80041600: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80041604: lw          $s0, 0x90($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X90);
    // 0x80041608: lhu         $v0, 0x18A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18A);
    // 0x8004160C: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x80041610: addiu       $s2, $s2, 0x31C0
    ctx->r18 = ADD32(ctx->r18, 0X31C0);
    // 0x80041614: lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X0);
    // 0x80041618: bne         $v0, $zero, L_80041738
    if (ctx->r2 != 0) {
        // 0x8004161C: nop
    
            goto L_80041738;
    }
    // 0x8004161C: nop

    // 0x80041620: lhu         $v0, 0x18E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18E);
    // 0x80041624: beq         $v0, $zero, L_800416C0
    if (ctx->r2 == 0) {
        // 0x80041628: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800416C0;
    }
    // 0x80041628: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004162C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80041630: jal         0x80041894
    // 0x80041634: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    func_80041894(rdram, ctx);
        goto after_0;
    // 0x80041634: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    after_0:
    // 0x80041638: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8004163C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80041640: bne         $v0, $v1, L_80041738
    if (ctx->r2 != ctx->r3) {
        // 0x80041644: nop
    
            goto L_80041738;
    }
    // 0x80041644: nop

    // 0x80041648: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x8004164C: lhu         $v0, 0x58($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X58);
    // 0x80041650: beq         $v0, $zero, L_80041688
    if (ctx->r2 == 0) {
        // 0x80041654: nop
    
            goto L_80041688;
    }
    // 0x80041654: nop

    // 0x80041658: jal         0x8000CD10
    // 0x8004165C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000CD10(rdram, ctx);
        goto after_1;
    // 0x8004165C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80041660: lhu         $v0, 0x120($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X120);
    // 0x80041664: lhu         $v1, 0x122($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X122);
    // 0x80041668: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004166C: sh          $v0, 0xFA($s0)
    MEM_H(0XFA, ctx->r16) = ctx->r2;
    // 0x80041670: jal         0x8003C014
    // 0x80041674: sh          $v1, 0xFC($s0)
    MEM_H(0XFC, ctx->r16) = ctx->r3;
    func_8003C014(rdram, ctx);
        goto after_2;
    // 0x80041674: sh          $v1, 0xFC($s0)
    MEM_H(0XFC, ctx->r16) = ctx->r3;
    after_2:
    // 0x80041678: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004167C: sh          $v0, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r2;
L_80041680:
    // 0x80041680: j           L_80041740
    // 0x80041684: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
        goto L_80041740;
    // 0x80041684: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
L_80041688:
    // 0x80041688: lw          $v1, 0x70($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X70);
    // 0x8004168C: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x80041690: bne         $v1, $v0, L_8004170C
    if (ctx->r3 != ctx->r2) {
        // 0x80041694: nop
    
            goto L_8004170C;
    }
    // 0x80041694: nop

    // 0x80041698: jal         0x8000F16C
    // 0x8004169C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000F16C(rdram, ctx);
        goto after_3;
    // 0x8004169C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800416A0: lhu         $v0, 0x120($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X120);
    // 0x800416A4: lhu         $v1, 0x122($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X122);
    // 0x800416A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800416AC: sh          $v0, 0xFA($a0)
    MEM_H(0XFA, ctx->r4) = ctx->r2;
    // 0x800416B0: jal         0x8003C014
    // 0x800416B4: sh          $v1, 0xFC($a0)
    MEM_H(0XFC, ctx->r4) = ctx->r3;
    func_8003C014(rdram, ctx);
        goto after_4;
    // 0x800416B4: sh          $v1, 0xFC($a0)
    MEM_H(0XFC, ctx->r4) = ctx->r3;
    after_4:
    // 0x800416B8: j           L_80041740
    // 0x800416BC: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
        goto L_80041740;
    // 0x800416BC: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
L_800416C0:
    // 0x800416C0: lhu         $v0, 0x1B0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B0);
    // 0x800416C4: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800416C8: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x800416CC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800416D0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800416D4: bnel        $v1, $zero, L_80041740
    if (ctx->r3 != 0) {
        // 0x800416D8: sw          $s1, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r17;
            goto L_80041740;
    }
    goto skip_0;
    // 0x800416D8: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    skip_0:
    // 0x800416DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800416E0: jal         0x8004175C
    // 0x800416E4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8004175C(rdram, ctx);
        goto after_5;
    // 0x800416E4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x800416E8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800416EC: beq         $v0, $zero, L_80041680
    if (ctx->r2 == 0) {
        // 0x800416F0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80041680;
    }
    // 0x800416F0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800416F4: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x800416F8: jal         0x80041A44
    // 0x800416FC: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    func_80041A44(rdram, ctx);
        goto after_6;
    // 0x800416FC: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    after_6:
    // 0x80041700: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80041704: beql        $v0, $zero, L_80041740
    if (ctx->r2 == 0) {
        // 0x80041708: sw          $s1, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r17;
            goto L_80041740;
    }
    goto skip_1;
    // 0x80041708: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    skip_1:
L_8004170C:
    // 0x8004170C: lw          $a1, 0x14($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14);
    // 0x80041710: lhu         $v0, 0x120($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X120);
    // 0x80041714: lhu         $v1, 0x122($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X122);
    // 0x80041718: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004171C: sh          $v0, 0xFA($s0)
    MEM_H(0XFA, ctx->r16) = ctx->r2;
    // 0x80041720: jal         0x80010890
    // 0x80041724: sh          $v1, 0xFC($s0)
    MEM_H(0XFC, ctx->r16) = ctx->r3;
    func_80010890(rdram, ctx);
        goto after_7;
    // 0x80041724: sh          $v1, 0xFC($s0)
    MEM_H(0XFC, ctx->r16) = ctx->r3;
    after_7:
    // 0x80041728: jal         0x8003C014
    // 0x8004172C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003C014(rdram, ctx);
        goto after_8;
    // 0x8004172C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // 0x80041730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80041734: sh          $v0, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r2;
L_80041738:
    // 0x80041738: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004173C: sw          $s1, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r17;
L_80041740:
    // 0x80041740: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80041744: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80041748: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004174C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041750: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80041754: jr          $ra
    // 0x80041758: nop

    return;
    // 0x80041758: nop

;}
RECOMP_FUNC void func_8004175C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004175C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80041760: lhu         $a3, 0x3E4($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X3E4);
    // 0x80041764: andi        $t0, $a3, 0xFFFF
    ctx->r8 = ctx->r7 & 0XFFFF;
    // 0x80041768: beq         $t0, $zero, L_8004188C
    if (ctx->r8 == 0) {
        // 0x8004176C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8004188C;
    }
    // 0x8004176C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80041770: lhu         $v1, 0x1B2($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X1B2);
    // 0x80041774: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x80041778: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8004177C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80041780: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80041784: beql        $v0, $zero, L_8004178C
    if (ctx->r2 == 0) {
        // 0x80041788: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_8004178C;
    }
    goto skip_0;
    // 0x80041788: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    skip_0:
L_8004178C:
    // 0x8004178C: addiu       $a3, $a2, 0x1
    ctx->r7 = ADD32(ctx->r6, 0X1);
    // 0x80041790: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x80041794: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x80041798: bnel        $v0, $zero, L_800417A0
    if (ctx->r2 != 0) {
        // 0x8004179C: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800417A0;
    }
    goto skip_1;
    // 0x8004179C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    skip_1:
L_800417A0:
    // 0x800417A0: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800417A4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800417A8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800417AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800417B0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800417B4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800417B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800417BC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800417C0: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800417C4: addiu       $v1, $v1, -0x71F4
    ctx->r3 = ADD32(ctx->r3, -0X71F4);
    // 0x800417C8: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // 0x800417CC: lhu         $v0, 0x14($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X14);
    // 0x800417D0: bne         $v0, $zero, L_80041810
    if (ctx->r2 != 0) {
        // 0x800417D4: andi        $v1, $a3, 0xFFFF
        ctx->r3 = ctx->r7 & 0XFFFF;
            goto L_80041810;
    }
    // 0x800417D4: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // 0x800417D8: lhu         $v1, 0x1B4($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X1B4);
    // 0x800417DC: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x800417E0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800417E4: bne         $v0, $zero, L_80041810
    if (ctx->r2 != 0) {
        // 0x800417E8: andi        $v1, $a3, 0xFFFF
        ctx->r3 = ctx->r7 & 0XFFFF;
            goto L_80041810;
    }
    // 0x800417E8: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // 0x800417EC: lh          $v1, 0x120($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X120);
    // 0x800417F0: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    // 0x800417F4: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800417F8: bnel        $v0, $zero, L_80041810
    if (ctx->r2 != 0) {
        // 0x800417FC: andi        $v1, $a3, 0xFFFF
        ctx->r3 = ctx->r7 & 0XFFFF;
            goto L_80041810;
    }
    goto skip_2;
    // 0x800417FC: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    skip_2:
    // 0x80041800: lh          $v0, 0xE($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XE);
    // 0x80041804: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80041808: beq         $v0, $zero, L_8004187C
    if (ctx->r2 == 0) {
        // 0x8004180C: andi        $v1, $a3, 0xFFFF
        ctx->r3 = ctx->r7 & 0XFFFF;
            goto L_8004187C;
    }
    // 0x8004180C: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
L_80041810:
    // 0x80041810: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80041814: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80041818: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004181C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80041820: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80041824: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80041828: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004182C: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80041830: addiu       $v1, $v1, -0x71F4
    ctx->r3 = ADD32(ctx->r3, -0X71F4);
    // 0x80041834: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // 0x80041838: lhu         $v0, 0x14($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X14);
    // 0x8004183C: bnel        $v0, $zero, L_80041888
    if (ctx->r2 != 0) {
        // 0x80041840: sw          $a2, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r6;
            goto L_80041888;
    }
    goto skip_3;
    // 0x80041840: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    skip_3:
    // 0x80041844: lhu         $v1, 0x1B4($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X1B4);
    // 0x80041848: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x8004184C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80041850: bnel        $v0, $zero, L_80041888
    if (ctx->r2 != 0) {
        // 0x80041854: sw          $a2, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r6;
            goto L_80041888;
    }
    goto skip_4;
    // 0x80041854: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    skip_4:
    // 0x80041858: lh          $a0, 0x120($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X120);
    // 0x8004185C: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    // 0x80041860: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80041864: bnel        $v0, $zero, L_80041888
    if (ctx->r2 != 0) {
        // 0x80041868: sw          $a2, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r6;
            goto L_80041888;
    }
    goto skip_5;
    // 0x80041868: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    skip_5:
    // 0x8004186C: lh          $v0, 0xE($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XE);
    // 0x80041870: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80041874: bnel        $v0, $zero, L_80041888
    if (ctx->r2 != 0) {
        // 0x80041878: sw          $a2, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r6;
            goto L_80041888;
    }
    goto skip_6;
    // 0x80041878: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    skip_6:
L_8004187C:
    // 0x8004187C: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x80041880: j           L_8004188C
    // 0x80041884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8004188C;
    // 0x80041884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80041888:
    // 0x80041888: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004188C:
    // 0x8004188C: jr          $ra
    // 0x80041890: nop

    return;
    // 0x80041890: nop

;}
RECOMP_FUNC void func_80041894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041894: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80041898: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8004189C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800418A0: lhu         $s3, 0x3E4($s3)
    ctx->r19 = MEM_HU(ctx->r19, 0X3E4);
    // 0x800418A4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800418A8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800418AC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800418B0: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x800418B4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800418B8: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x800418BC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800418C0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800418C4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800418C8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800418CC: beq         $s3, $zero, L_80041A04
    if (ctx->r19 == 0) {
        // 0x800418D0: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_80041A04;
    }
    // 0x800418D0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800418D4: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x800418D8: addiu       $s1, $s1, -0x6C70
    ctx->r17 = ADD32(ctx->r17, -0X6C70);
    // 0x800418DC: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800418E0: addiu       $s0, $s1, 0xE
    ctx->r16 = ADD32(ctx->r17, 0XE);
L_800418E4:
    // 0x800418E4: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x800418E8: bnel        $v0, $zero, L_800419F0
    if (ctx->r2 != 0) {
        // 0x800418EC: addiu       $s0, $s0, 0x584
        ctx->r16 = ADD32(ctx->r16, 0X584);
            goto L_800419F0;
    }
    goto skip_0;
    // 0x800418EC: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
    skip_0:
    // 0x800418F0: lh          $a2, -0xA($s0)
    ctx->r6 = MEM_H(ctx->r16, -0XA);
    // 0x800418F4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800418F8: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x800418FC: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x80041900: slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80041904: beq         $v0, $zero, L_80041944
    if (ctx->r2 == 0) {
        // 0x80041908: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80041944;
    }
    // 0x80041908: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8004190C: subu        $v0, $v1, $a2
    ctx->r2 = SUB32(ctx->r3, ctx->r6);
    // 0x80041910: bgez        $v0, L_8004191C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80041914: subu        $v0, $a0, $a1
        ctx->r2 = SUB32(ctx->r4, ctx->r5);
            goto L_8004191C;
    }
    // 0x80041914: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // 0x80041918: subu        $v0, $a1, $a0
    ctx->r2 = SUB32(ctx->r5, ctx->r4);
L_8004191C:
    // 0x8004191C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80041920: lhu         $a2, 0x3294($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X3294);
    // 0x80041924: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80041928: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8004192C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041930: sll         $v1, $a2, 16
    ctx->r3 = S32(ctx->r6 << 16);
    // 0x80041934: sra         $v1, $v1, 17
    ctx->r3 = S32(SIGNED(ctx->r3) >> 17);
    // 0x80041938: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004193C: beql        $v0, $zero, L_80041944
    if (ctx->r2 == 0) {
        // 0x80041940: addu        $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_80041944;
    }
    goto skip_1;
    // 0x80041940: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    skip_1:
L_80041944:
    // 0x80041944: lh          $v1, 0x120($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X120);
    // 0x80041948: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8004194C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041950: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80041954: bnel        $v1, $zero, L_800419F0
    if (ctx->r3 != 0) {
        // 0x80041958: addiu       $s0, $s0, 0x584
        ctx->r16 = ADD32(ctx->r16, 0X584);
            goto L_800419F0;
    }
    goto skip_2;
    // 0x80041958: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
    skip_2:
    // 0x8004195C: lh          $a2, 0x0($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X0);
    // 0x80041960: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80041964: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041968: slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004196C: beq         $v0, $zero, L_800419A8
    if (ctx->r2 == 0) {
        // 0x80041970: addu        $a1, $a2, $zero
        ctx->r5 = ADD32(ctx->r6, 0);
            goto L_800419A8;
    }
    // 0x80041970: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x80041974: subu        $v0, $a2, $v1
    ctx->r2 = SUB32(ctx->r6, ctx->r3);
    // 0x80041978: bgez        $v0, L_80041984
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004197C: subu        $v0, $a1, $a0
        ctx->r2 = SUB32(ctx->r5, ctx->r4);
            goto L_80041984;
    }
    // 0x8004197C: subu        $v0, $a1, $a0
    ctx->r2 = SUB32(ctx->r5, ctx->r4);
    // 0x80041980: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
L_80041984:
    // 0x80041984: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80041988: lhu         $a0, 0x3294($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X3294);
    // 0x8004198C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80041990: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041994: sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4 << 16);
    // 0x80041998: sra         $v1, $v1, 17
    ctx->r3 = S32(SIGNED(ctx->r3) >> 17);
    // 0x8004199C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800419A0: beql        $v0, $zero, L_800419A8
    if (ctx->r2 == 0) {
        // 0x800419A4: addu        $a1, $a1, $a0
        ctx->r5 = ADD32(ctx->r5, ctx->r4);
            goto L_800419A8;
    }
    goto skip_3;
    // 0x800419A4: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    skip_3:
L_800419A8:
    // 0x800419A8: lh          $v1, 0x120($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X120);
    // 0x800419AC: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x800419B0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800419B4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800419B8: bnel        $v0, $zero, L_800419F0
    if (ctx->r2 != 0) {
        // 0x800419BC: addiu       $s0, $s0, 0x584
        ctx->r16 = ADD32(ctx->r16, 0X584);
            goto L_800419F0;
    }
    goto skip_4;
    // 0x800419BC: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
    skip_4:
    // 0x800419C0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800419C4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800419C8: jal         0x80041A44
    // 0x800419CC: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_80041A44(rdram, ctx);
        goto after_0;
    // 0x800419CC: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_0:
    // 0x800419D0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800419D4: bne         $v0, $s6, L_800419F0
    if (ctx->r2 != ctx->r22) {
        // 0x800419D8: addiu       $s0, $s0, 0x584
        ctx->r16 = ADD32(ctx->r16, 0X584);
            goto L_800419F0;
    }
    // 0x800419D8: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
    // 0x800419DC: sw          $s1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r17;
    // 0x800419E0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800419E4: sh          $s6, 0x3218($at)
    MEM_H(0X3218, ctx->r1) = ctx->r22;
    // 0x800419E8: j           L_80041A18
    // 0x800419EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041A18;
    // 0x800419EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800419F0:
    // 0x800419F0: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x800419F4: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800419F8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800419FC: bne         $v0, $zero, L_800418E4
    if (ctx->r2 != 0) {
        // 0x80041A00: addiu       $s1, $s1, 0x584
        ctx->r17 = ADD32(ctx->r17, 0X584);
            goto L_800418E4;
    }
    // 0x80041A00: addiu       $s1, $s1, 0x584
    ctx->r17 = ADD32(ctx->r17, 0X584);
L_80041A04:
    // 0x80041A04: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80041A08: sw          $s1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r17;
    // 0x80041A0C: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x80041A10: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80041A14: sh          $zero, 0x3218($at)
    MEM_H(0X3218, ctx->r1) = 0;
L_80041A18:
    // 0x80041A18: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80041A1C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80041A20: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80041A24: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80041A28: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80041A2C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80041A30: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80041A34: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80041A38: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80041A3C: jr          $ra
    // 0x80041A40: nop

    return;
    // 0x80041A40: nop

;}
RECOMP_FUNC void func_80041A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041A44: addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // 0x80041A48: lw          $v0, 0x120($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X120);
    // 0x80041A4C: beq         $v0, $zero, L_80041B8C
    if (ctx->r2 == 0) {
                func_80041A50(rdram, ctx); return; // was goto L_80041B8C
    }
;}
