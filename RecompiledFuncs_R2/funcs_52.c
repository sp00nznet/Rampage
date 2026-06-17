#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_800434E8(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80043154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043154: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80043158: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8004315C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80043160: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80043164: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80043168: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004316C: lw          $v0, 0x98($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X98);
    // 0x80043170: bne         $v0, $zero, L_80043248
    if (ctx->r2 != 0) {
        // 0x80043174: addiu       $s1, $zero, 0x7
        ctx->r17 = ADD32(0, 0X7);
            goto L_80043248;
    }
    // 0x80043174: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    // 0x80043178: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x8004317C: addiu       $s2, $s2, 0x3F94
    ctx->r18 = ADD32(ctx->r18, 0X3F94);
    // 0x80043180: addiu       $s3, $zero, 0x2B
    ctx->r19 = ADD32(0, 0X2B);
    // 0x80043184: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
L_80043188:
    // 0x80043188: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8004318C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80043190: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80043194: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80043198: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004319C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800431A0: lw          $a0, 0x9C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X9C);
    // 0x800431A4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800431A8: beq         $a0, $v0, L_80043234
    if (ctx->r4 == ctx->r2) {
        // 0x800431AC: addu        $s0, $v1, $s2
        ctx->r16 = ADD32(ctx->r3, ctx->r18);
            goto L_80043234;
    }
    // 0x800431AC: addu        $s0, $v1, $s2
    ctx->r16 = ADD32(ctx->r3, ctx->r18);
    // 0x800431B0: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
    // 0x800431B4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800431B8: beq         $v0, $zero, L_80043238
    if (ctx->r2 == 0) {
        // 0x800431BC: addiu       $v0, $s1, -0x1
        ctx->r2 = ADD32(ctx->r17, -0X1);
            goto L_80043238;
    }
    // 0x800431BC: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x800431C0: lhu         $v0, 0xDC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XDC);
    // 0x800431C4: beq         $v0, $zero, L_80043238
    if (ctx->r2 == 0) {
        // 0x800431C8: addiu       $v0, $s1, -0x1
        ctx->r2 = ADD32(ctx->r17, -0X1);
            goto L_80043238;
    }
    // 0x800431C8: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x800431CC: lh          $a0, 0x14($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X14);
    // 0x800431D0: lh          $a1, 0x18($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X18);
    // 0x800431D4: jal         0x8003B4A4
    // 0x800431D8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8003B4A4(rdram, ctx);
        goto after_0;
    // 0x800431D8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800431DC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800431E0: beq         $v0, $zero, L_80043238
    if (ctx->r2 == 0) {
        // 0x800431E4: addiu       $v0, $s1, -0x1
        ctx->r2 = ADD32(ctx->r17, -0X1);
            goto L_80043238;
    }
    // 0x800431E4: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x800431E8: lhu         $v0, 0x1A8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A8);
    // 0x800431EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800431F0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800431F4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800431F8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800431FC: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80043200: bne         $v0, $zero, L_80043210
    if (ctx->r2 != 0) {
        // 0x80043204: lui         $a0, 0x3
        ctx->r4 = S32(0X3 << 16);
            goto L_80043210;
    }
    // 0x80043204: lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // 0x80043208: sh          $s3, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r19;
    // 0x8004320C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80043210:
    // 0x80043210: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    // 0x80043214: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80043218: jal         0x8003BA80
    // 0x8004321C: sh          $v1, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r3;
    func_8003BA80(rdram, ctx);
        goto after_1;
    // 0x8004321C: sh          $v1, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r3;
    after_1:
    // 0x80043220: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043224: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043228: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x8004322C: j           L_80043248
    // 0x80043230: sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
        goto L_80043248;
    // 0x80043230: sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
L_80043234:
    // 0x80043234: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
L_80043238:
    // 0x80043238: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8004323C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80043240: bne         $v0, $zero, L_80043188
    if (ctx->r2 != 0) {
        // 0x80043244: andi        $v0, $s1, 0xFFFF
        ctx->r2 = ctx->r17 & 0XFFFF;
            goto L_80043188;
    }
    // 0x80043244: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
L_80043248:
    // 0x80043248: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8004324C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80043250: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80043254: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80043258: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004325C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80043260: jr          $ra
    // 0x80043264: nop

    return;
    // 0x80043264: nop

;}
RECOMP_FUNC void func_80043268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043268: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004326C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043270: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80043274: lw          $a0, 0x14($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X14);
    // 0x80043278: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8004327C: lw          $a1, 0x3294($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3294);
    // 0x80043280: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80043284: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x80043288: jr          $ra
    // 0x8004328C: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    return;
    // 0x8004328C: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80043290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043290: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043294: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043298: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8004329C: lhu         $a0, -0x2074($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2074);
    // 0x800432A0: lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X14);
    // 0x800432A4: beq         $a0, $zero, L_800432D0
    if (ctx->r4 == 0) {
        // 0x800432A8: sll         $v0, $v0, 16
        ctx->r2 = S32(ctx->r2 << 16);
            goto L_800432D0;
    }
    // 0x800432A8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800432AC: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800432B0: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800432B4: bne         $v0, $zero, L_800432D4
    if (ctx->r2 != 0) {
        // 0x800432B8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800432D4;
    }
    // 0x800432B8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800432BC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800432C0: lhu         $v0, 0x3EF4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3EF4);
    // 0x800432C4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800432C8: beq         $v0, $zero, L_800432D4
    if (ctx->r2 == 0) {
        // 0x800432CC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800432D4;
    }
    // 0x800432CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800432D0:
    // 0x800432D0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800432D4:
    // 0x800432D4: jr          $ra
    // 0x800432D8: nop

    return;
    // 0x800432D8: nop

;}
RECOMP_FUNC void func_800432DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800432DC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800432E0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800432E4: lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X90);
    // 0x800432E8: lw          $v1, 0x1D4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1D4);
    // 0x800432EC: beq         $v1, $zero, L_80043300
    if (ctx->r3 == 0) {
        // 0x800432F0: nop
    
            goto L_80043300;
    }
    // 0x800432F0: nop

    // 0x800432F4: lhu         $v0, 0x6A($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6A);
    // 0x800432F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800432FC: sh          $v0, 0x6A($v1)
    MEM_H(0X6A, ctx->r3) = ctx->r2;
L_80043300:
    // 0x80043300: jr          $ra
    // 0x80043304: nop

    return;
    // 0x80043304: nop

;}
RECOMP_FUNC void func_80043308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043308: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004330C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80043308 falls into func_80043310
    func_80043310(rdram, ctx);
;}
RECOMP_FUNC void func_80043310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043310: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80043314: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80043318: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004331C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043320: lw          $s0, 0x90($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X90);
    // 0x80043324: lhu         $a0, 0x1B0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1B0);
    // 0x80043328: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8004332C: lw          $s1, 0x31C0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X31C0);
    // 0x80043330: sltiu       $v1, $a0, 0x1
    ctx->r3 = ctx->r4 < 0X1 ? 1 : 0;
    // 0x80043334: xori        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 ^ 0X3;
    // 0x80043338: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8004333C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80043340: bne         $v1, $zero, L_800433F4
    if (ctx->r3 != 0) {
        // 0x80043344: nop
    
            goto L_800433F4;
    }
    // 0x80043344: nop

    // 0x80043348: lhu         $v1, 0xEA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XEA);
    // 0x8004334C: addiu       $v0, $v1, -0x3
    ctx->r2 = ADD32(ctx->r3, -0X3);
    // 0x80043350: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80043354: bne         $v0, $zero, L_800433F4
    if (ctx->r2 != 0) {
        // 0x80043358: nop
    
            goto L_800433F4;
    }
    // 0x80043358: nop

    // 0x8004335C: beq         $v1, $a0, L_800433F4
    if (ctx->r3 == ctx->r4) {
        // 0x80043360: nop
    
            goto L_800433F4;
    }
    // 0x80043360: nop

    // 0x80043364: lhu         $a0, 0x1B2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1B2);
    // 0x80043368: jal         0x8001B7D0
    // 0x8004336C: nop

    func_8001B7D0(rdram, ctx);
        goto after_0;
    // 0x8004336C: nop

    after_0:
    // 0x80043370: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80043374: beq         $a2, $zero, L_800433EC
    if (ctx->r6 == 0) {
        // 0x80043378: nop
    
            goto L_800433EC;
    }
    // 0x80043378: nop

    // 0x8004337C: lhu         $v0, 0x120($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X120);
    // 0x80043380: lhu         $v1, 0x122($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X122);
    // 0x80043384: sh          $v0, 0xFA($s0)
    MEM_H(0XFA, ctx->r16) = ctx->r2;
    // 0x80043388: sh          $v1, 0xFC($s0)
    MEM_H(0XFC, ctx->r16) = ctx->r3;
    // 0x8004338C: lhu         $v0, 0x58($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X58);
    // 0x80043390: beq         $v0, $zero, L_800433AC
    if (ctx->r2 == 0) {
        // 0x80043394: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800433AC;
    }
    // 0x80043394: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80043398: jal         0x8000CD10
    // 0x8004339C: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    func_8000CD10(rdram, ctx);
        goto after_1;
    // 0x8004339C: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    after_1:
    // 0x800433A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800433A4: j           L_800433EC
    // 0x800433A8: sh          $v0, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r2;
        goto L_800433EC;
    // 0x800433A8: sh          $v0, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r2;
L_800433AC:
    // 0x800433AC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800433B0: jal         0x80044748
    // 0x800433B4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80044748(rdram, ctx);
        goto after_2;
    // 0x800433B4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800433B8: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800433BC: beq         $a2, $zero, L_800433EC
    if (ctx->r6 == 0) {
        // 0x800433C0: nop
    
            goto L_800433EC;
    }
    // 0x800433C0: nop

    // 0x800433C4: lhu         $v0, 0x1BC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1BC);
    // 0x800433C8: bne         $v0, $zero, L_800433E0
    if (ctx->r2 != 0) {
        // 0x800433CC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800433E0;
    }
    // 0x800433CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800433D0: jal         0x80010890
    // 0x800433D4: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    func_80010890(rdram, ctx);
        goto after_3;
    // 0x800433D4: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    after_3:
    // 0x800433D8: j           L_800433EC
    // 0x800433DC: nop

        goto L_800433EC;
    // 0x800433DC: nop

L_800433E0:
    // 0x800433E0: lhu         $a0, 0x10($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X10);
    // 0x800433E4: jal         0x8000CBEC
    // 0x800433E8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8000CBEC(rdram, ctx);
        goto after_4;
    // 0x800433E8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_4:
L_800433EC:
    // 0x800433EC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800433F0: sw          $s1, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r17;
L_800433F4:
    // 0x800433F4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800433F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800433FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80043400: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80043404: jr          $ra
    // 0x80043408: nop

    return;
    // 0x80043408: nop

;}
RECOMP_FUNC void func_8004340C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004340C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043410: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043414: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x80043418: lhu         $v0, 0xCC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XCC);
    // 0x8004341C: addiu       $a0, $v0, -0x2
    ctx->r4 = ADD32(ctx->r2, -0X2);
    // 0x80043420: sltiu       $v0, $a0, 0x7
    ctx->r2 = ctx->r4 < 0X7 ? 1 : 0;
    // 0x80043424: beq         $v0, $zero, L_8004348C
    if (ctx->r2 == 0) {
        // 0x80043428: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_8004348C;
    }
    // 0x80043428: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8004342C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80043430: addu        $at, $at, $v0
    gpr jr_addend_80043438 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80043434: lw          $v0, 0x41A8($at)
    ctx->r2 = ADD32(ctx->r1, 0X41A8);
    // 0x80043438: jr          $v0
    // 0x8004343C: nop

    switch (jr_addend_80043438 >> 2) {
        case 0: goto L_80043458; break;
        case 1: goto L_80043458; break;
        case 2: goto L_80043458; break;
        case 3: goto L_8004348C; break;
        case 4: goto L_8004344C; break;
        case 5: goto L_80043440; break;
        case 6: goto L_8004344C; break;
        default: switch_error(__func__, 0x80043438, 0x800941A8);
    }
    // 0x8004343C: nop

L_80043440:
    // 0x80043440: lw          $v0, 0x100($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X100);
    // 0x80043444: j           L_80043460
    // 0x80043448: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
        goto L_80043460;
    // 0x80043448: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
L_8004344C:
    // 0x8004344C: lw          $v0, 0x100($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X100);
    // 0x80043450: j           L_80043460
    // 0x80043454: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
        goto L_80043460;
    // 0x80043454: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
L_80043458:
    // 0x80043458: lw          $v0, 0x100($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X100);
    // 0x8004345C: addiu       $v0, $v0, 0x2000
    ctx->r2 = ADD32(ctx->r2, 0X2000);
L_80043460:
    // 0x80043460: sw          $v0, 0x100($v1)
    MEM_W(0X100, ctx->r3) = ctx->r2;
    // 0x80043464: lw          $v0, 0x100($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X100);
    // 0x80043468: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8004346C: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80043470: bnel        $v0, $zero, L_80043478
    if (ctx->r2 != 0) {
        // 0x80043474: sw          $a0, 0x100($v1)
        MEM_W(0X100, ctx->r3) = ctx->r4;
            goto L_80043478;
    }
    goto skip_0;
    // 0x80043474: sw          $a0, 0x100($v1)
    MEM_W(0X100, ctx->r3) = ctx->r4;
    skip_0:
L_80043478:
    // 0x80043478: lw          $v0, 0x100($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X100);
    // 0x8004347C: lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
    // 0x80043480: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80043484: bnel        $v0, $zero, L_8004348C
    if (ctx->r2 != 0) {
        // 0x80043488: sw          $a0, 0x100($v1)
        MEM_W(0X100, ctx->r3) = ctx->r4;
            goto L_8004348C;
    }
    goto skip_1;
    // 0x80043488: sw          $a0, 0x100($v1)
    MEM_W(0X100, ctx->r3) = ctx->r4;
    skip_1:
L_8004348C:
    // 0x8004348C: jr          $ra
    // 0x80043490: nop

    return;
    // 0x80043490: nop

    // 0x80043494: nop

    // 0x80043498: nop

    // 0x8004349C: nop

;}
RECOMP_FUNC void func_800434A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800434A0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800434A4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_800434A0 falls into func_800434A8
    func_800434A8(rdram, ctx);
;}
RECOMP_FUNC void func_800434A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800434A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800434AC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800434B0: lw          $v0, 0x48($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X48);
    // 0x800434B4: bne         $v0, $a0, L_800434CC
    if (ctx->r2 != ctx->r4) {
        // 0x800434B8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800434CC;
    }
    // 0x800434B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800434BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800434C0: sh          $v0, 0x321A($at)
    MEM_H(0X321A, ctx->r1) = ctx->r2;
    // 0x800434C4: j           L_800434D8
    // 0x800434C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800434D8;
    // 0x800434C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800434CC:
    // 0x800434CC: jal         0x800434E8
    // 0x800434D0: nop

    func_800434E8(rdram, ctx);
        goto after_0;
    // 0x800434D0: nop

    after_0:
    // 0x800434D4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_800434D8:
    // 0x800434D8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800434DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800434E0: jr          $ra
    // 0x800434E4: nop

    return;
    // 0x800434E4: nop

;}
RECOMP_FUNC void func_800434E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800434E8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800434EC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_800434E8 falls into func_800434F0
    func_800434F0(rdram, ctx);
;}
RECOMP_FUNC void func_800434F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800434F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800434F4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x800434F8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800434FC: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x80043500: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043504: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043508: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
    // 0x8004350C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043510: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043514: sb          $zero, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = 0;
    // 0x80043518: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004351C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043520: sb          $zero, 0x4D($v0)
    MEM_B(0X4D, ctx->r2) = 0;
    // 0x80043524: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043528: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8004352C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80043530: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80043534: jal         0x80061084
    // 0x80043538: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    func_80061084(rdram, ctx);
        goto after_0;
    // 0x80043538: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    after_0:
    // 0x8004353C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043540: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043544: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x80043548: ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // 0x8004354C: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x80043550: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80043554: sh          $zero, 0x321A($at)
    MEM_H(0X321A, ctx->r1) = 0;
    // 0x80043558: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8004355C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80043560: jr          $ra
    // 0x80043564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80043564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80043568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043568: jr          $ra
    // 0x8004356C: nop

    return;
    // 0x8004356C: nop

;}
RECOMP_FUNC void func_80043570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043570: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043574: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043578: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8004357C: jr          $ra
    // 0x80043580: sh          $v0, 0x74($v1)
    MEM_H(0X74, ctx->r3) = ctx->r2;
    return;
    // 0x80043580: sh          $v0, 0x74($v1)
    MEM_H(0X74, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80043584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043584: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043588: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80043584 falls into func_8004358C
    func_8004358C(rdram, ctx);
;}
RECOMP_FUNC void func_8004358C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004358C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80043590: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80043594: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80043598: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004359C: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x800435A0: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x800435A4: lw          $s1, 0x31C0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X31C0);
    // 0x800435A8: lhu         $a1, 0x22($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X22);
    // 0x800435AC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800435B0: lw          $s0, 0x90($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X90);
    // 0x800435B4: jal         0x80016BA0
    // 0x800435B8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80016BA0(rdram, ctx);
        goto after_0;
    // 0x800435B8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800435BC: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800435C0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800435C4: bne         $v1, $v0, L_800435E4
    if (ctx->r3 != ctx->r2) {
        // 0x800435C8: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_800435E4;
    }
    // 0x800435C8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800435CC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800435D0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800435D4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800435D8: lhu         $v0, -0x1D3C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X1D3C);
    // 0x800435DC: j           L_800435FC
    // 0x800435E0: sh          $v0, 0x74($v1)
    MEM_H(0X74, ctx->r3) = ctx->r2;
        goto L_800435FC;
    // 0x800435E0: sh          $v0, 0x74($v1)
    MEM_H(0X74, ctx->r3) = ctx->r2;
L_800435E4:
    // 0x800435E4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800435E8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800435EC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800435F0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800435F4: lhu         $v1, -0x3A4A($at)
    ctx->r3 = MEM_HU(ctx->r1, -0X3A4A);
    // 0x800435F8: sh          $v1, 0x74($v0)
    MEM_H(0X74, ctx->r2) = ctx->r3;
L_800435FC:
    // 0x800435FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80043600: sw          $s1, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r17;
    // 0x80043604: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80043608: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004360C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80043610: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80043614: jr          $ra
    // 0x80043618: nop

    return;
    // 0x80043618: nop

;}
RECOMP_FUNC void func_8004361C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004361C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80043620: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80043624: lw          $a0, 0x5C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X5C);
    // 0x80043628: lw          $v0, 0x48($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X48);
    // 0x8004362C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80043630: bne         $v0, $v1, L_80043644
    if (ctx->r2 != ctx->r3) {
        // 0x80043634: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80043644;
    }
    // 0x80043634: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80043638: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004363C: sw          $v0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r2;
    // 0x80043640: sw          $v0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r2;
L_80043644:
    // 0x80043644: jr          $ra
    // 0x80043648: nop

    return;
    // 0x80043648: nop

;}
RECOMP_FUNC void func_8004364C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004364C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043650: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043654: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80043658: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8004365C: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
    // 0x80043660: jr          $ra
    // 0x80043664: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    return;
    // 0x80043664: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_80043668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043668: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004366C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043670: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80043674: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80043678: jr          $ra
    // 0x8004367C: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
    return;
    // 0x8004367C: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_80043680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043680: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043684: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043688: lw          $a0, 0x5C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X5C);
    // 0x8004368C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80043690: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
    // 0x80043694: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043698: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8004369C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800436A0: jr          $ra
    // 0x800436A4: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    return;
    // 0x800436A4: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_800436A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800436A8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800436AC: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x800436B0: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x800436B4: lw          $v1, 0x90($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X90);
    // 0x800436B8: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800436BC: lhu         $v1, 0x5A($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X5A);
    // 0x800436C0: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x800436C4: addiu       $v0, $zero, 0x4E
    ctx->r2 = ADD32(0, 0X4E);
    // 0x800436C8: bnel        $v1, $v0, L_800436DC
    if (ctx->r3 != ctx->r2) {
        // 0x800436CC: sw          $a2, 0x48($a0)
        MEM_W(0X48, ctx->r4) = ctx->r6;
            goto L_800436DC;
    }
    goto skip_0;
    // 0x800436CC: sw          $a2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800436D0: sw          $a1, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r5;
    // 0x800436D4: j           L_800436E0
    // 0x800436D8: sw          $a1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r5;
        goto L_800436E0;
    // 0x800436D8: sw          $a1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r5;
L_800436DC:
    // 0x800436DC: sw          $a2, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r6;
L_800436E0:
    // 0x800436E0: jr          $ra
    // 0x800436E4: nop

    return;
    // 0x800436E4: nop

;}
RECOMP_FUNC void func_800436E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800436E8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800436EC: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x800436F0: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
    // 0x800436F4: lhu         $v1, 0x5A($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X5A);
    // 0x800436F8: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x800436FC: addiu       $v0, $zero, 0x4E
    ctx->r2 = ADD32(0, 0X4E);
    // 0x80043700: beq         $v1, $v0, L_80043714
    if (ctx->r3 == ctx->r2) {
        // 0x80043704: nop
    
            goto L_80043714;
    }
    // 0x80043704: nop

    // 0x80043708: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8004370C: sw          $v0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r2;
    // 0x80043710: sw          $v0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r2;
L_80043714:
    // 0x80043714: jr          $ra
    // 0x80043718: nop

    return;
    // 0x80043718: nop

;}
RECOMP_FUNC void func_8004371C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004371C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043720: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_8004371C falls into func_80043724
    func_80043724(rdram, ctx);
;}
RECOMP_FUNC void func_80043724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043724: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80043728: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8004372C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80043730: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80043734: lw          $s0, 0x90($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X90);
    // 0x80043738: lh          $v1, 0x5A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X5A);
    // 0x8004373C: lh          $v0, 0x170($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X170);
    // 0x80043740: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80043744: lw          $s1, 0x31C0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X31C0);
    // 0x80043748: bne         $v1, $v0, L_800437A8
    if (ctx->r3 != ctx->r2) {
        // 0x8004374C: nop
    
            goto L_800437A8;
    }
    // 0x8004374C: nop

    // 0x80043750: lhu         $v0, 0x1B0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B0);
    // 0x80043754: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80043758: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x8004375C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80043760: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80043764: beq         $v1, $zero, L_80043774
    if (ctx->r3 == 0) {
        // 0x80043768: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_80043774;
    }
    // 0x80043768: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8004376C: j           L_80043778
    // 0x80043770: sh          $zero, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = 0;
        goto L_80043778;
    // 0x80043770: sh          $zero, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = 0;
L_80043774:
    // 0x80043774: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
L_80043778:
    // 0x80043778: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    // 0x8004377C: sh          $zero, 0xE0($s0)
    MEM_H(0XE0, ctx->r16) = 0;
    // 0x80043780: sh          $zero, 0xE2($s0)
    MEM_H(0XE2, ctx->r16) = 0;
    // 0x80043784: sh          $zero, 0x126($s0)
    MEM_H(0X126, ctx->r16) = 0;
    // 0x80043788: sh          $zero, 0x12A($s0)
    MEM_H(0X12A, ctx->r16) = 0;
    // 0x8004378C: sh          $zero, 0x1CA($s0)
    MEM_H(0X1CA, ctx->r16) = 0;
    // 0x80043790: sh          $zero, 0x1C8($s0)
    MEM_H(0X1C8, ctx->r16) = 0;
    // 0x80043794: beq         $a0, $zero, L_800437A8
    if (ctx->r4 == 0) {
        // 0x80043798: sw          $zero, 0x180($s0)
        MEM_W(0X180, ctx->r16) = 0;
            goto L_800437A8;
    }
    // 0x80043798: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8004379C: jal         0x80024764
    // 0x800437A0: nop

    func_80024764(rdram, ctx);
        goto after_0;
    // 0x800437A0: nop

    after_0:
    // 0x800437A4: sw          $zero, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = 0;
L_800437A8:
    // 0x800437A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800437AC: sw          $s1, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r17;
    // 0x800437B0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800437B4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800437B8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800437BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800437C0: jr          $ra
    // 0x800437C4: nop

    return;
    // 0x800437C4: nop

;}
RECOMP_FUNC void func_800437C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800437C8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800437CC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800437D0: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x800437D4: lw          $v1, -0x307C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X307C);
    // FALLTHROUGH: func_800437C8 falls into func_800437D8
    func_800437D8(rdram, ctx);
;}
RECOMP_FUNC void func_800437D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800437D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800437DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800437E0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800437E4: lw          $s0, 0x90($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X90);
    // 0x800437E8: beq         $v1, $zero, L_800438D8
    if (ctx->r3 == 0) {
        // 0x800437EC: nop
    
            goto L_800438D8;
    }
    // 0x800437EC: nop

    // 0x800437F0: jal         0x80027338
    // 0x800437F4: nop

    func_80027338(rdram, ctx);
        goto after_0;
    // 0x800437F4: nop

    after_0:
    // 0x800437F8: xori        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 ^ 0X4;
    // 0x800437FC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80043800: sltiu       $v1, $s0, 0x1
    ctx->r3 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80043804: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80043808: bne         $v0, $zero, L_800438D8
    if (ctx->r2 != 0) {
        // 0x8004380C: lui         $v0, 0x4
        ctx->r2 = S32(0X4 << 16);
            goto L_800438D8;
    }
    // 0x8004380C: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x80043810: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80043814: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80043818: bne         $v0, $zero, L_800438D8
    if (ctx->r2 != 0) {
        // 0x8004381C: nop
    
            goto L_800438D8;
    }
    // 0x8004381C: nop

    // 0x80043820: lhu         $v0, 0x184($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X184);
    // 0x80043824: bne         $v0, $zero, L_800438D8
    if (ctx->r2 != 0) {
        // 0x80043828: nop
    
            goto L_800438D8;
    }
    // 0x80043828: nop

    // 0x8004382C: lhu         $v0, 0x5A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X5A);
    // 0x80043830: addiu       $v1, $v0, -0xA
    ctx->r3 = ADD32(ctx->r2, -0XA);
    // 0x80043834: sltiu       $v0, $v1, 0x31
    ctx->r2 = ctx->r3 < 0X31 ? 1 : 0;
    // 0x80043838: beq         $v0, $zero, L_800438A0
    if (ctx->r2 == 0) {
        // 0x8004383C: sh          $zero, 0x8($s0)
        MEM_H(0X8, ctx->r16) = 0;
            goto L_800438A0;
    }
    // 0x8004383C: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x80043840: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80043844: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80043848: addu        $at, $at, $v0
    gpr jr_addend_80043850 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004384C: lw          $v0, 0x41C8($at)
    ctx->r2 = ADD32(ctx->r1, 0X41C8);
    // 0x80043850: jr          $v0
    // 0x80043854: nop

    switch (jr_addend_80043850 >> 2) {
        case 0: goto L_80043864; break;
        case 1: goto L_80043870; break;
        case 2: goto L_800438A0; break;
        case 3: goto L_800438A0; break;
        case 4: goto L_800438A0; break;
        case 5: goto L_800438A0; break;
        case 6: goto L_800438A0; break;
        case 7: goto L_800438A0; break;
        case 8: goto L_800438A0; break;
        case 9: goto L_800438A0; break;
        case 10: goto L_800438A0; break;
        case 11: goto L_800438A0; break;
        case 12: goto L_800438A0; break;
        case 13: goto L_800438A0; break;
        case 14: goto L_800438A0; break;
        case 15: goto L_800438A0; break;
        case 16: goto L_800438A0; break;
        case 17: goto L_800438A0; break;
        case 18: goto L_80043858; break;
        case 19: goto L_800438A0; break;
        case 20: goto L_80043894; break;
        case 21: goto L_800438A0; break;
        case 22: goto L_800438A0; break;
        case 23: goto L_800438A0; break;
        case 24: goto L_80043870; break;
        case 25: goto L_800438A0; break;
        case 26: goto L_80043864; break;
        case 27: goto L_800438A0; break;
        case 28: goto L_800438A0; break;
        case 29: goto L_800438A0; break;
        case 30: goto L_8004387C; break;
        case 31: goto L_80043894; break;
        case 32: goto L_800438A0; break;
        case 33: goto L_800438A0; break;
        case 34: goto L_800438A0; break;
        case 35: goto L_800438A0; break;
        case 36: goto L_800438A0; break;
        case 37: goto L_80043864; break;
        case 38: goto L_800438A0; break;
        case 39: goto L_800438A0; break;
        case 40: goto L_800438A0; break;
        case 41: goto L_800438A0; break;
        case 42: goto L_800438A0; break;
        case 43: goto L_800438A0; break;
        case 44: goto L_800438A0; break;
        case 45: goto L_800438A0; break;
        case 46: goto L_800438A0; break;
        case 47: goto L_80043858; break;
        case 48: goto L_80043888; break;
        default: switch_error(__func__, 0x80043850, 0x800941C8);
    }
    // 0x80043854: nop

L_80043858:
    // 0x80043858: addiu       $v0, $zero, 0x5B
    ctx->r2 = ADD32(0, 0X5B);
    // 0x8004385C: j           L_800438AC
    // 0x80043860: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
        goto L_800438AC;
    // 0x80043860: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
L_80043864:
    // 0x80043864: addiu       $v0, $zero, 0x59
    ctx->r2 = ADD32(0, 0X59);
    // 0x80043868: j           L_800438AC
    // 0x8004386C: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
        goto L_800438AC;
    // 0x8004386C: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
L_80043870:
    // 0x80043870: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // 0x80043874: j           L_800438AC
    // 0x80043878: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
        goto L_800438AC;
    // 0x80043878: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
L_8004387C:
    // 0x8004387C: addiu       $v0, $zero, 0x5C
    ctx->r2 = ADD32(0, 0X5C);
    // 0x80043880: j           L_800438AC
    // 0x80043884: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
        goto L_800438AC;
    // 0x80043884: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
L_80043888:
    // 0x80043888: addiu       $v0, $zero, 0x5E
    ctx->r2 = ADD32(0, 0X5E);
    // 0x8004388C: j           L_800438AC
    // 0x80043890: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
        goto L_800438AC;
    // 0x80043890: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
L_80043894:
    // 0x80043894: addiu       $v0, $zero, 0x5D
    ctx->r2 = ADD32(0, 0X5D);
    // 0x80043898: j           L_800438AC
    // 0x8004389C: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
        goto L_800438AC;
    // 0x8004389C: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
L_800438A0:
    // 0x800438A0: addiu       $v0, $zero, 0x59
    ctx->r2 = ADD32(0, 0X59);
    // 0x800438A4: j           L_800438D8
    // 0x800438A8: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
        goto L_800438D8;
    // 0x800438A8: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
L_800438AC:
    // 0x800438AC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800438B0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800438B4: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x800438B8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800438BC: beql        $v0, $zero, L_800438D0
    if (ctx->r2 == 0) {
        // 0x800438C0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800438D0;
    }
    goto skip_0;
    // 0x800438C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800438C4: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x800438C8: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
    // 0x800438CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800438D0:
    // 0x800438D0: sh          $zero, 0xDC($s0)
    MEM_H(0XDC, ctx->r16) = 0;
    // 0x800438D4: sh          $v0, 0x184($s0)
    MEM_H(0X184, ctx->r16) = ctx->r2;
L_800438D8:
    // 0x800438D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800438DC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800438E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800438E4: jr          $ra
    // 0x800438E8: nop

    return;
    // 0x800438E8: nop

;}
RECOMP_FUNC void func_800438EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800438EC: jr          $ra
    // 0x800438F0: nop

    return;
    // 0x800438F0: nop

;}
RECOMP_FUNC void func_800438F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800438F4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800438F8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800438FC: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x80043900: lhu         $v0, 0x5A($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X5A);
    // 0x80043904: jr          $ra
    // 0x80043908: sh          $v0, 0x170($v1)
    MEM_H(0X170, ctx->r3) = ctx->r2;
    return;
    // 0x80043908: sh          $v0, 0x170($v1)
    MEM_H(0X170, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_8004390C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004390C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043910: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043914: lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X90);
    // 0x80043918: lw          $v1, 0x5C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5C);
    // 0x8004391C: lhu         $a0, 0x5A($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X5A);
    // 0x80043920: sh          $a0, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r4;
    // 0x80043924: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x80043928: sw          $zero, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = 0;
    // 0x8004392C: jr          $ra
    // 0x80043930: sh          $v1, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = ctx->r3;
    return;
    // 0x80043930: sh          $v1, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_80043934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043934: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80043938: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x8004393C: lw          $a1, 0x90($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X90);
    // 0x80043940: lhu         $v1, 0xCC($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XCC);
    // 0x80043944: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80043948: bne         $v1, $v0, L_800439B8
    if (ctx->r3 != ctx->r2) {
        // 0x8004394C: nop
    
            goto L_800439B8;
    }
    // 0x8004394C: nop

    // 0x80043950: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x80043954: slti        $v0, $v0, 0xDC
    ctx->r2 = SIGNED(ctx->r2) < 0XDC ? 1 : 0;
    // 0x80043958: bne         $v0, $zero, L_800439B8
    if (ctx->r2 != 0) {
        // 0x8004395C: addiu       $v0, $zero, 0xE1
        ctx->r2 = ADD32(0, 0XE1);
            goto L_800439B8;
    }
    // 0x8004395C: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x80043960: sh          $v0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r2;
    // 0x80043964: addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
    // 0x80043968: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    // 0x8004396C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043970: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043974: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80043978: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004397C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043980: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80043984: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043988: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8004398C: sw          $zero, 0x84($v0)
    MEM_W(0X84, ctx->r2) = 0;
    // 0x80043990: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043994: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043998: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
    // 0x8004399C: sw          $zero, 0x100($a1)
    MEM_W(0X100, ctx->r5) = 0;
    // 0x800439A0: sw          $zero, 0x104($a1)
    MEM_W(0X104, ctx->r5) = 0;
    // 0x800439A4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800439A8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800439AC: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x800439B0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800439B4: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
L_800439B8:
    // 0x800439B8: jr          $ra
    // 0x800439BC: nop

    return;
    // 0x800439BC: nop

;}
RECOMP_FUNC void func_800439C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800439C0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800439C4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800439C8: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
    // 0x800439CC: ori         $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 | 0X4000;
    // 0x800439D0: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x800439D4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800439D8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800439DC: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x800439E0: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x800439E4: jr          $ra
    // 0x800439E8: sh          $v0, 0x150($v1)
    MEM_H(0X150, ctx->r3) = ctx->r2;
    return;
    // 0x800439E8: sh          $v0, 0x150($v1)
    MEM_H(0X150, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_800439EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800439EC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800439F0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800439F4: lw          $a1, 0x90($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X90);
    // 0x800439F8: lh          $v0, 0x150($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X150);

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_800439FC
    func_800439FC(rdram, ctx);
}
RECOMP_FUNC void func_800439FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800439FC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80043A00: beq         $v0, $zero, L_80043A10
    if (ctx->r2 == 0) {
        // 0x80043A04: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80043A10;
    }
    // 0x80043A04: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80043A08: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80043A0C: sh          $v0, 0x150($a1)
    MEM_H(0X150, ctx->r5) = ctx->r2;
L_80043A10:
    // 0x80043A10: lhu         $v0, 0x5A($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X5A);
    // 0x80043A14: xori        $v1, $v0, 0x20
    ctx->r3 = ctx->r2 ^ 0X20;
    // 0x80043A18: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80043A1C: xori        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 ^ 0XF;
    // 0x80043A20: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80043A24: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80043A28: beq         $v1, $zero, L_80043A34
    if (ctx->r3 == 0) {
        // 0x80043A2C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80043A34;
    }
    // 0x80043A2C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80043A30: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
L_80043A34:
    // 0x80043A34: lhu         $v0, 0x166($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X166);
    // 0x80043A38: lw          $a0, 0x100($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X100);
    // 0x80043A3C: bne         $v0, $zero, L_80043B4C
    if (ctx->r2 != 0) {
        // 0x80043A40: nop
    
            goto L_80043B4C;
    }
    // 0x80043A40: nop

    // 0x80043A44: lhu         $v0, 0xCC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XCC);
    // 0x80043A48: addiu       $v1, $v0, -0x2
    ctx->r3 = ADD32(ctx->r2, -0X2);
    // 0x80043A4C: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x80043A50: beq         $v0, $zero, L_80043B4C
    if (ctx->r2 == 0) {
        // 0x80043A54: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80043B4C;
    }
    // 0x80043A54: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80043A58: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80043A5C: addu        $at, $at, $v0
    gpr jr_addend_80043A64 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80043A60: lw          $v0, 0x4290($at)
    ctx->r2 = ADD32(ctx->r1, 0X4290);
    // 0x80043A64: jr          $v0
    // 0x80043A68: nop

    switch (jr_addend_80043A64 >> 2) {
        case 0: goto L_80043A74; break;
        case 1: goto L_80043A74; break;
        case 2: goto L_80043A74; break;
        case 3: goto L_80043B4C; break;
        case 4: goto L_80043A6C; break;
        case 5: goto L_80043A6C; break;
        case 6: goto L_80043A6C; break;
        default: switch_error(__func__, 0x80043A64, 0x80094290);
    }
    // 0x80043A68: nop

L_80043A6C:
    // 0x80043A6C: j           L_80043A78
    // 0x80043A70: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, -0X2000);
        goto L_80043A78;
    // 0x80043A70: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, -0X2000);
L_80043A74:
    // 0x80043A74: addiu       $a0, $a0, 0x2000
    ctx->r4 = ADD32(ctx->r4, 0X2000);
L_80043A78:
    // 0x80043A78: lh          $v0, 0x150($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X150);
    // 0x80043A7C: bne         $v0, $zero, L_80043AA4
    if (ctx->r2 != 0) {
        // 0x80043A80: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_80043AA4;
    }
    // 0x80043A80: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80043A84: lhu         $v1, 0x168($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X168);
    // 0x80043A88: beq         $v1, $v0, L_80043A98
    if (ctx->r3 == ctx->r2) {
        // 0x80043A8C: nor         $v0, $zero, $a0
        ctx->r2 = ~(0 | ctx->r4);
            goto L_80043A98;
    }
    // 0x80043A8C: nor         $v0, $zero, $a0
    ctx->r2 = ~(0 | ctx->r4);
    // 0x80043A90: j           L_80043AA0
    // 0x80043A94: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
        goto L_80043AA0;
    // 0x80043A94: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
L_80043A98:
    // 0x80043A98: slti        $v0, $a0, 0x1
    ctx->r2 = SIGNED(ctx->r4) < 0X1 ? 1 : 0;
    // 0x80043A9C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80043AA0:
    // 0x80043AA0: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
L_80043AA4:
    // 0x80043AA4: lhu         $v0, 0x152($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X152);
    // 0x80043AA8: bne         $v0, $zero, L_80043B2C
    if (ctx->r2 != 0) {
        // 0x80043AAC: ori         $v0, $zero, 0x8000
        ctx->r2 = 0 | 0X8000;
            goto L_80043B2C;
    }
    // 0x80043AAC: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80043AB0: lh          $v0, 0x150($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X150);
    // 0x80043AB4: bne         $v0, $zero, L_80043AF4
    if (ctx->r2 != 0) {
        // 0x80043AB8: lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
            goto L_80043AF4;
    }
    // 0x80043AB8: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80043ABC: ori         $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 | 0X4000;
    // 0x80043AC0: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80043AC4: beq         $v0, $zero, L_80043AD8
    if (ctx->r2 == 0) {
        // 0x80043AC8: lui         $v0, 0xFFFE
        ctx->r2 = S32(0XFFFE << 16);
            goto L_80043AD8;
    }
    // 0x80043AC8: lui         $v0, 0xFFFE
    ctx->r2 = S32(0XFFFE << 16);
    // 0x80043ACC: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x80043AD0: j           L_80043B48
    // 0x80043AD4: ori         $a0, $a0, 0x4000
    ctx->r4 = ctx->r4 | 0X4000;
        goto L_80043B48;
    // 0x80043AD4: ori         $a0, $a0, 0x4000
    ctx->r4 = ctx->r4 | 0X4000;
L_80043AD8:
    // 0x80043AD8: ori         $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 | 0XC000;
    // 0x80043ADC: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80043AE0: beql        $v0, $zero, L_80043B4C
    if (ctx->r2 == 0) {
        // 0x80043AE4: sw          $a0, 0x100($a1)
        MEM_W(0X100, ctx->r5) = ctx->r4;
            goto L_80043B4C;
    }
    goto skip_0;
    // 0x80043AE4: sw          $a0, 0x100($a1)
    MEM_W(0X100, ctx->r5) = ctx->r4;
    skip_0:
    // 0x80043AE8: lui         $a0, 0xFFFE
    ctx->r4 = S32(0XFFFE << 16);
    // 0x80043AEC: j           L_80043B48
    // 0x80043AF0: ori         $a0, $a0, 0xC000
    ctx->r4 = ctx->r4 | 0XC000;
        goto L_80043B48;
    // 0x80043AF0: ori         $a0, $a0, 0xC000
    ctx->r4 = ctx->r4 | 0XC000;
L_80043AF4:
    // 0x80043AF4: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
    // 0x80043AF8: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80043AFC: beq         $v0, $zero, L_80043B10
    if (ctx->r2 == 0) {
        // 0x80043B00: lui         $v0, 0xFFFE
        ctx->r2 = S32(0XFFFE << 16);
            goto L_80043B10;
    }
    // 0x80043B00: lui         $v0, 0xFFFE
    ctx->r2 = S32(0XFFFE << 16);
    // 0x80043B04: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x80043B08: j           L_80043B48
    // 0x80043B0C: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
        goto L_80043B48;
    // 0x80043B0C: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
L_80043B10:
    // 0x80043B10: ori         $v0, $v0, 0xE000
    ctx->r2 = ctx->r2 | 0XE000;
    // 0x80043B14: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80043B18: beql        $v0, $zero, L_80043B4C
    if (ctx->r2 == 0) {
        // 0x80043B1C: sw          $a0, 0x100($a1)
        MEM_W(0X100, ctx->r5) = ctx->r4;
            goto L_80043B4C;
    }
    goto skip_1;
    // 0x80043B1C: sw          $a0, 0x100($a1)
    MEM_W(0X100, ctx->r5) = ctx->r4;
    skip_1:
    // 0x80043B20: lui         $a0, 0xFFFE
    ctx->r4 = S32(0XFFFE << 16);
    // 0x80043B24: j           L_80043B48
    // 0x80043B28: ori         $a0, $a0, 0xE000
    ctx->r4 = ctx->r4 | 0XE000;
        goto L_80043B48;
    // 0x80043B28: ori         $a0, $a0, 0xE000
    ctx->r4 = ctx->r4 | 0XE000;
L_80043B2C:
    // 0x80043B2C: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80043B30: beq         $v0, $zero, L_80043B40
    if (ctx->r2 == 0) {
        // 0x80043B34: slti        $v0, $a0, -0x8000
        ctx->r2 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
            goto L_80043B40;
    }
    // 0x80043B34: slti        $v0, $a0, -0x8000
    ctx->r2 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x80043B38: j           L_80043B48
    // 0x80043B3C: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
        goto L_80043B48;
    // 0x80043B3C: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
L_80043B40:
    // 0x80043B40: bnel        $v0, $zero, L_80043B48
    if (ctx->r2 != 0) {
        // 0x80043B44: addiu       $a0, $zero, -0x8000
        ctx->r4 = ADD32(0, -0X8000);
            goto L_80043B48;
    }
    goto skip_2;
    // 0x80043B44: addiu       $a0, $zero, -0x8000
    ctx->r4 = ADD32(0, -0X8000);
    skip_2:
L_80043B48:
    // 0x80043B48: sw          $a0, 0x100($a1)
    MEM_W(0X100, ctx->r5) = ctx->r4;
L_80043B4C:
    // 0x80043B4C: lhu         $v0, 0xD0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XD0);
    // 0x80043B50: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80043B54: beq         $v0, $zero, L_80043BE8
    if (ctx->r2 == 0) {
        // 0x80043B58: nop
    
            goto L_80043BE8;
    }
    // 0x80043B58: nop

    // 0x80043B5C: lhu         $a0, 0xCC($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0XCC);
    // 0x80043B60: xori        $v1, $a0, 0x1
    ctx->r3 = ctx->r4 ^ 0X1;
    // 0x80043B64: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80043B68: xori        $v0, $a0, 0x8
    ctx->r2 = ctx->r4 ^ 0X8;
    // 0x80043B6C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80043B70: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80043B74: beq         $v1, $zero, L_80043BE8
    if (ctx->r3 == 0) {
        // 0x80043B78: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80043BE8;
    }
    // 0x80043B78: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80043B7C: beq         $a0, $v0, L_80043BE8
    if (ctx->r4 == ctx->r2) {
        // 0x80043B80: lui         $v1, 0x2
        ctx->r3 = S32(0X2 << 16);
            goto L_80043BE8;
    }
    // 0x80043B80: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x80043B84: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043B88: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043B8C: ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // 0x80043B90: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80043B94: lui         $v0, 0x5
    ctx->r2 = S32(0X5 << 16);
    // 0x80043B98: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // 0x80043B9C: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80043BA0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80043BA4: bne         $v0, $zero, L_80043BE8
    if (ctx->r2 != 0) {
        // 0x80043BA8: nop
    
            goto L_80043BE8;
    }
    // 0x80043BA8: nop

    // 0x80043BAC: lhu         $v0, 0x1AA($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1AA);
    // 0x80043BB0: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80043BB4: beq         $v0, $zero, L_80043BE8
    if (ctx->r2 == 0) {
        // 0x80043BB8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80043BE8;
    }
    // 0x80043BB8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80043BBC: bltz        $a0, L_80043BD0
    if (SIGNED(ctx->r4) < 0) {
        // 0x80043BC0: sh          $v0, 0x1AA($a1)
        MEM_H(0X1AA, ctx->r5) = ctx->r2;
            goto L_80043BD0;
    }
    // 0x80043BC0: sh          $v0, 0x1AA($a1)
    MEM_H(0X1AA, ctx->r5) = ctx->r2;
    // 0x80043BC4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043BC8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043BCC: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
L_80043BD0:
    // 0x80043BD0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043BD4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043BD8: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80043BDC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80043BE0: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x80043BE4: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
L_80043BE8:
    // 0x80043BE8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80043BEC: jr          $ra
    // 0x80043BF0: nop

    return;
    // 0x80043BF0: nop

;}
RECOMP_FUNC void func_80043BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043BF4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043BF8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043BFC: lw          $a1, 0x90($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X90);
    // 0x80043C00: lhu         $v1, 0x5A($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X5A);
    // 0x80043C04: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80043C08: beq         $v1, $v0, L_80043C14
    if (ctx->r3 == ctx->r2) {
        // 0x80043C0C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80043C14;
    }
    // 0x80043C0C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80043C10: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
L_80043C14:
    // 0x80043C14: lhu         $v0, 0xC8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC8);
    // 0x80043C18: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80043C1C: beq         $v0, $zero, L_80043C7C
    if (ctx->r2 == 0) {
        // 0x80043C20: lui         $v1, 0xFFFD
        ctx->r3 = S32(0XFFFD << 16);
            goto L_80043C7C;
    }
    // 0x80043C20: lui         $v1, 0xFFFD
    ctx->r3 = S32(0XFFFD << 16);
    // 0x80043C24: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043C28: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043C2C: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80043C30: ori         $v1, $v1, 0x4000
    ctx->r3 = ctx->r3 | 0X4000;
    // 0x80043C34: lui         $v0, 0x3
    ctx->r2 = S32(0X3 << 16);
    // 0x80043C38: slt         $v1, $a0, $v1
    ctx->r3 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80043C3C: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80043C40: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80043C44: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80043C48: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80043C4C: beq         $v1, $zero, L_80043C7C
    if (ctx->r3 == 0) {
        // 0x80043C50: nop
    
            goto L_80043C7C;
    }
    // 0x80043C50: nop

    // 0x80043C54: lhu         $v0, 0x1AA($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1AA);
    // 0x80043C58: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80043C5C: beq         $v0, $zero, L_80043C7C
    if (ctx->r2 == 0) {
        // 0x80043C60: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80043C7C;
    }
    // 0x80043C60: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80043C64: bltz        $a0, L_80043C94
    if (SIGNED(ctx->r4) < 0) {
        // 0x80043C68: sh          $v0, 0x1AA($a1)
        MEM_H(0X1AA, ctx->r5) = ctx->r2;
            goto L_80043C94;
    }
    // 0x80043C68: sh          $v0, 0x1AA($a1)
    MEM_H(0X1AA, ctx->r5) = ctx->r2;
    // 0x80043C6C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043C70: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043C74: j           L_80043C94
    // 0x80043C78: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
        goto L_80043C94;
    // 0x80043C78: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
L_80043C7C:
    // 0x80043C7C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043C80: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043C84: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80043C88: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80043C8C: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x80043C90: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
L_80043C94:
    // 0x80043C94: jr          $ra
    // 0x80043C98: nop

    return;
    // 0x80043C98: nop

;}
RECOMP_FUNC void func_80043C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043C9C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043CA0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043CA4: lw          $a1, 0x90($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X90);
    // 0x80043CA8: lhu         $v1, 0x5A($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X5A);
    // 0x80043CAC: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80043CB0: beq         $v1, $v0, L_80043CBC
    if (ctx->r3 == ctx->r2) {
        // 0x80043CB4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80043CBC;
    }
    // 0x80043CB4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80043CB8: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
L_80043CBC:
    // 0x80043CBC: lhu         $v0, 0xC8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC8);
    // 0x80043CC0: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80043CC4: beq         $v0, $zero, L_80043D38
    if (ctx->r2 == 0) {
        // 0x80043CC8: lui         $v1, 0xFFFD
        ctx->r3 = S32(0XFFFD << 16);
            goto L_80043D38;
    }
    // 0x80043CC8: lui         $v1, 0xFFFD
    ctx->r3 = S32(0XFFFD << 16);
    // 0x80043CCC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043CD0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043CD4: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80043CD8: ori         $v1, $v1, 0x4000
    ctx->r3 = ctx->r3 | 0X4000;
    // 0x80043CDC: lui         $v0, 0x3
    ctx->r2 = S32(0X3 << 16);
    // 0x80043CE0: slt         $v1, $a0, $v1
    ctx->r3 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80043CE4: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80043CE8: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80043CEC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80043CF0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80043CF4: beq         $v1, $zero, L_80043D38
    if (ctx->r3 == 0) {
        // 0x80043CF8: nop
    
            goto L_80043D38;
    }
    // 0x80043CF8: nop

    // 0x80043CFC: lhu         $v0, 0x1AA($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1AA);
    // 0x80043D00: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80043D04: beq         $v0, $zero, L_80043D38
    if (ctx->r2 == 0) {
        // 0x80043D08: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80043D38;
    }
    // 0x80043D08: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80043D0C: bltz        $a0, L_80043D20
    if (SIGNED(ctx->r4) < 0) {
        // 0x80043D10: sh          $v0, 0x1AA($a1)
        MEM_H(0X1AA, ctx->r5) = ctx->r2;
            goto L_80043D20;
    }
    // 0x80043D10: sh          $v0, 0x1AA($a1)
    MEM_H(0X1AA, ctx->r5) = ctx->r2;
    // 0x80043D14: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043D18: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043D1C: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
L_80043D20:
    // 0x80043D20: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043D24: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043D28: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80043D2C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80043D30: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x80043D34: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
L_80043D38:
    // 0x80043D38: jr          $ra
    // 0x80043D3C: nop

    return;
    // 0x80043D3C: nop

;}
RECOMP_FUNC void func_80043D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043D40: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043D44: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043D48: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
    // 0x80043D4C: lw          $a1, 0x90($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X90);
    // 0x80043D50: slti        $v0, $v0, 0x50
    ctx->r2 = SIGNED(ctx->r2) < 0X50 ? 1 : 0;
    // 0x80043D54: bne         $v0, $zero, L_80043DB0
    if (ctx->r2 != 0) {
        // 0x80043D58: addiu       $a0, $zero, -0x8000
        ctx->r4 = ADD32(0, -0X8000);
            goto L_80043DB0;
    }
    // 0x80043D58: addiu       $a0, $zero, -0x8000
    ctx->r4 = ADD32(0, -0X8000);
    // 0x80043D5C: lhu         $a2, 0x5A($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X5A);
    // 0x80043D60: lhu         $v0, 0x168($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X168);
    // 0x80043D64: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
    // 0x80043D68: sh          $v1, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r3;
    // 0x80043D6C: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x80043D70: beq         $v0, $v1, L_80043D8C
    if (ctx->r2 == ctx->r3) {
        // 0x80043D74: xori        $v0, $a2, 0x3D
        ctx->r2 = ctx->r6 ^ 0X3D;
            goto L_80043D8C;
    }
    // 0x80043D74: xori        $v0, $a2, 0x3D
    ctx->r2 = ctx->r6 ^ 0X3D;
    // 0x80043D78: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80043D7C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80043D80: andi        $v0, $v0, 0x6000
    ctx->r2 = ctx->r2 & 0X6000;
    // 0x80043D84: j           L_80043DA0
    // 0x80043D88: ori         $a0, $v0, 0x4000
    ctx->r4 = ctx->r2 | 0X4000;
        goto L_80043DA0;
    // 0x80043D88: ori         $a0, $v0, 0x4000
    ctx->r4 = ctx->r2 | 0X4000;
L_80043D8C:
    // 0x80043D8C: andi        $v1, $a2, 0xFFFF
    ctx->r3 = ctx->r6 & 0XFFFF;
    // 0x80043D90: addiu       $v0, $zero, 0x3D
    ctx->r2 = ADD32(0, 0X3D);
    // 0x80043D94: bne         $v1, $v0, L_80043DA0
    if (ctx->r3 != ctx->r2) {
        // 0x80043D98: addiu       $a0, $zero, -0x4000
        ctx->r4 = ADD32(0, -0X4000);
            goto L_80043DA0;
    }
    // 0x80043D98: addiu       $a0, $zero, -0x4000
    ctx->r4 = ADD32(0, -0X4000);
    // 0x80043D9C: addiu       $a0, $zero, -0x6000
    ctx->r4 = ADD32(0, -0X6000);
L_80043DA0:
    // 0x80043DA0: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x80043DA4: sw          $a0, 0x100($a1)
    MEM_W(0X100, ctx->r5) = ctx->r4;
    // 0x80043DA8: j           L_80043DDC
    // 0x80043DAC: sw          $v0, 0x104($a1)
    MEM_W(0X104, ctx->r5) = ctx->r2;
        goto L_80043DDC;
    // 0x80043DAC: sw          $v0, 0x104($a1)
    MEM_W(0X104, ctx->r5) = ctx->r2;
L_80043DB0:
    // 0x80043DB0: lhu         $v0, 0x168($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X168);
    // 0x80043DB4: addiu       $v1, $zero, 0x17
    ctx->r3 = ADD32(0, 0X17);
    // 0x80043DB8: sh          $v1, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r3;
    // 0x80043DBC: addiu       $v1, $zero, 0x4000
    ctx->r3 = ADD32(0, 0X4000);
    // 0x80043DC0: sw          $v1, 0x104($a1)
    MEM_W(0X104, ctx->r5) = ctx->r3;
    // 0x80043DC4: xori        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 ^ 0X7;
    // 0x80043DC8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80043DCC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80043DD0: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x80043DD4: ori         $a0, $v0, 0x8000
    ctx->r4 = ctx->r2 | 0X8000;
    // 0x80043DD8: sw          $a0, 0x100($a1)
    MEM_W(0X100, ctx->r5) = ctx->r4;
L_80043DDC:
    // 0x80043DDC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043DE0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043DE4: lui         $v0, 0xFFFC
    ctx->r2 = S32(0XFFFC << 16);
    // 0x80043DE8: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80043DEC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043DF0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043DF4: jr          $ra
    // 0x80043DF8: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    return;
    // 0x80043DF8: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80043DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043DFC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043E00: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043E04: lui         $v0, 0xFFFC
    ctx->r2 = S32(0XFFFC << 16);
    // 0x80043E08: jr          $ra
    // 0x80043E0C: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    return;
    // 0x80043E0C: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80043E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043E10: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043E14: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043E18: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x80043E1C: jr          $ra
    // 0x80043E20: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    return;
    // 0x80043E20: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80043E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043E24: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043E28: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043E2C: jr          $ra
    // 0x80043E30: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    return;
    // 0x80043E30: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80043E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043E34: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043E38: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043E3C: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x80043E40: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80043E44: sh          $zero, 0x5A($v1)
    MEM_H(0X5A, ctx->r3) = 0;
    // 0x80043E48: jr          $ra
    // 0x80043E4C: sh          $v0, 0x168($v1)
    MEM_H(0X168, ctx->r3) = ctx->r2;
    return;
    // 0x80043E4C: sh          $v0, 0x168($v1)
    MEM_H(0X168, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80043E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043E50: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043E54: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043E58: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x80043E5C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80043E60: sh          $zero, 0x5A($v1)
    MEM_H(0X5A, ctx->r3) = 0;
    // 0x80043E64: jr          $ra
    // 0x80043E68: sh          $v0, 0x168($v1)
    MEM_H(0X168, ctx->r3) = ctx->r2;
    return;
    // 0x80043E68: sh          $v0, 0x168($v1)
    MEM_H(0X168, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80043E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043E6C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043E70: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043E74: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x80043E78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80043E7C: sh          $v0, 0x5A($v1)
    MEM_H(0X5A, ctx->r3) = ctx->r2;
    // 0x80043E80: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80043E84: sh          $v0, 0x168($v1)
    MEM_H(0X168, ctx->r3) = ctx->r2;
    // 0x80043E88: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80043E8C: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80043E90: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x80043E94: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80043E98: sw          $v1, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r3;
    // 0x80043E9C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043EA0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043EA4: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80043EA8: jr          $ra
    // 0x80043EAC: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    return;
    // 0x80043EAC: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80043EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043EB0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043EB4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043EB8: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x80043EBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80043EC0: sh          $v0, 0x5A($v1)
    MEM_H(0X5A, ctx->r3) = ctx->r2;
    // 0x80043EC4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80043EC8: sh          $v0, 0x168($v1)
    MEM_H(0X168, ctx->r3) = ctx->r2;
    // 0x80043ECC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80043ED0: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80043ED4: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x80043ED8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80043EDC: sw          $v1, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r3;
    // 0x80043EE0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043EE4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043EE8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80043EEC: jr          $ra
    // 0x80043EF0: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    return;
    // 0x80043EF0: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80043EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043EF4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043EF8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043EFC: lw          $a0, 0x90($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X90);
    // 0x80043F00: lhu         $v1, 0x5C($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X5C);
    // 0x80043F04: slti        $v0, $v1, 0x16
    ctx->r2 = SIGNED(ctx->r3) < 0X16 ? 1 : 0;
    // 0x80043F08: beq         $v0, $zero, L_80043F28
    if (ctx->r2 == 0) {
        // 0x80043F0C: slti        $v0, $v1, 0x14
        ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
            goto L_80043F28;
    }
    // 0x80043F0C: slti        $v0, $v1, 0x14
    ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80043F10: beq         $v0, $zero, L_80043F60
    if (ctx->r2 == 0) {
        // 0x80043F14: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80043F60;
    }
    // 0x80043F14: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80043F18: beq         $v1, $v0, L_80043F60
    if (ctx->r3 == ctx->r2) {
        // 0x80043F1C: nop
    
            goto L_80043F60;
    }
    // 0x80043F1C: nop

    // 0x80043F20: j           L_80043F84
    // 0x80043F24: nop

        goto L_80043F84;
    // 0x80043F24: nop

L_80043F28:
    // 0x80043F28: addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
    // 0x80043F2C: beq         $v1, $v0, L_80043F7C
    if (ctx->r3 == ctx->r2) {
        // 0x80043F30: slti        $v0, $v1, 0x4E
        ctx->r2 = SIGNED(ctx->r3) < 0X4E ? 1 : 0;
            goto L_80043F7C;
    }
    // 0x80043F30: slti        $v0, $v1, 0x4E
    ctx->r2 = SIGNED(ctx->r3) < 0X4E ? 1 : 0;
    // 0x80043F34: beq         $v0, $zero, L_80043F4C
    if (ctx->r2 == 0) {
        // 0x80043F38: addiu       $v0, $zero, 0x18
        ctx->r2 = ADD32(0, 0X18);
            goto L_80043F4C;
    }
    // 0x80043F38: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // 0x80043F3C: beq         $v1, $v0, L_80043F60
    if (ctx->r3 == ctx->r2) {
        // 0x80043F40: nop
    
            goto L_80043F60;
    }
    // 0x80043F40: nop

    // 0x80043F44: j           L_80043F84
    // 0x80043F48: nop

        goto L_80043F84;
    // 0x80043F48: nop

L_80043F4C:
    // 0x80043F4C: addiu       $v0, $zero, 0x4E
    ctx->r2 = ADD32(0, 0X4E);
    // 0x80043F50: bne         $v1, $v0, L_80043F84
    if (ctx->r3 != ctx->r2) {
        // 0x80043F54: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80043F84;
    }
    // 0x80043F54: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80043F58: j           L_80043F8C
    // 0x80043F5C: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
        goto L_80043F8C;
    // 0x80043F5C: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
L_80043F60:
    // 0x80043F60: lhu         $v0, 0x1B0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1B0);
    // 0x80043F64: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80043F68: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x80043F6C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80043F70: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80043F74: beq         $v1, $zero, L_80043F88
    if (ctx->r3 == 0) {
        // 0x80043F78: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_80043F88;
    }
    // 0x80043F78: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80043F7C:
    // 0x80043F7C: j           L_80043F8C
    // 0x80043F80: sh          $zero, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = 0;
        goto L_80043F8C;
    // 0x80043F80: sh          $zero, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = 0;
L_80043F84:
    // 0x80043F84: lhu         $v0, 0x5C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X5C);
L_80043F88:
    // 0x80043F88: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
L_80043F8C:
    // 0x80043F8C: jr          $ra
    // 0x80043F90: nop

    return;
    // 0x80043F90: nop

;}
RECOMP_FUNC void func_80043F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043F94: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043F98: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043F9C: lw          $a0, 0x90($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X90);
    // 0x80043FA0: lhu         $v0, 0x1B0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1B0);
    // 0x80043FA4: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80043FA8: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x80043FAC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80043FB0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80043FB4: beq         $v1, $zero, L_80043FC4
    if (ctx->r3 == 0) {
        // 0x80043FB8: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_80043FC4;
    }
    // 0x80043FB8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80043FBC: j           L_80043FC8
    // 0x80043FC0: sh          $zero, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = 0;
        goto L_80043FC8;
    // 0x80043FC0: sh          $zero, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = 0;
L_80043FC4:
    // 0x80043FC4: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
L_80043FC8:
    // 0x80043FC8: jr          $ra
    // 0x80043FCC: nop

    return;
    // 0x80043FCC: nop

;}
RECOMP_FUNC void func_80043FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043FD0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043FD4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80043FD8: lw          $a0, 0x90($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X90);
    // 0x80043FDC: lhu         $v0, 0x1B0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1B0);
    // 0x80043FE0: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80043FE4: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x80043FE8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80043FEC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80043FF0: beq         $v1, $zero, L_80044000
    if (ctx->r3 == 0) {
        // 0x80043FF4: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_80044000;
    }
    // 0x80043FF4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80043FF8: j           L_80044004
    // 0x80043FFC: sh          $zero, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = 0;
        goto L_80044004;
    // 0x80043FFC: sh          $zero, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = 0;
L_80044000:
    // 0x80044000: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
L_80044004:
    // 0x80044004: jr          $ra
    // 0x80044008: nop

    return;
    // 0x80044008: nop

;}
RECOMP_FUNC void func_8004400C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004400C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80044010: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80044014: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x80044018: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8004401C: jr          $ra
    // 0x80044020: sh          $v0, 0x5A($v1)
    MEM_H(0X5A, ctx->r3) = ctx->r2;
    return;
    // 0x80044020: sh          $v0, 0x5A($v1)
    MEM_H(0X5A, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80044024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044024: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80044028: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x8004402C: lw          $v0, 0x90($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X90);
    // 0x80044030: lhu         $v1, 0x12A($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X12A);
    // 0x80044034: beq         $v1, $zero, L_8004407C
    if (ctx->r3 == 0) {
        // 0x80044038: sll         $v0, $v1, 4
        ctx->r2 = S32(ctx->r3 << 4);
            goto L_8004407C;
    }
    // 0x80044038: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8004403C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044040: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80044044: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80044048: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004404C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80044050: addiu       $v1, $v1, 0x3F94
    ctx->r3 = ADD32(ctx->r3, 0X3F94);
    // 0x80044054: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80044058: lh          $v0, 0x122($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X122);
    // 0x8004405C: beq         $v0, $zero, L_8004407C
    if (ctx->r2 == 0) {
        // 0x80044060: nop
    
            goto L_8004407C;
    }
    // 0x80044060: nop

    // 0x80044064: lhu         $v0, 0x120($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X120);
    // 0x80044068: sh          $v0, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r2;
    // 0x8004406C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80044070: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80044074: lhu         $v0, 0x122($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X122);
    // 0x80044078: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
L_8004407C:
    // 0x8004407C: jr          $ra
    // 0x80044080: nop

    return;
    // 0x80044080: nop

;}
RECOMP_FUNC void func_80044084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044084: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80044088: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x8004408C: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x80044090: addiu       $a0, $zero, -0x20
    ctx->r4 = ADD32(0, -0X20);
    // 0x80044094: lhu         $v1, 0x14($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X14);
    // 0x80044098: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8004409C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800440A0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800440A4: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x800440A8: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x800440AC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800440B0: sh          $v1, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r3;
    // 0x800440B4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800440B8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800440BC: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x800440C0: jr          $ra
    // 0x800440C4: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    return;
    // 0x800440C4: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_800440C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800440C8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800440CC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_800440C8 falls into func_800440D0
    func_800440D0(rdram, ctx);
;}
RECOMP_FUNC void func_800440D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800440D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800440D4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800440D8: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x800440DC: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800440E0: beq         $v0, $zero, L_800440F0
    if (ctx->r2 == 0) {
        // 0x800440E4: nop
    
            goto L_800440F0;
    }
    // 0x800440E4: nop

    // 0x800440E8: jal         0x800410A4
    // 0x800440EC: nop

    func_800410A4(rdram, ctx);
        goto after_0;
    // 0x800440EC: nop

    after_0:
L_800440F0:
    // 0x800440F0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800440F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800440F8: jr          $ra
    // 0x800440FC: nop

    return;
    // 0x800440FC: nop

;}
