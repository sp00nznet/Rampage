#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_8003B458(uint8_t* rdram, recomp_context* ctx);
void func_8003B5BC(uint8_t* rdram, recomp_context* ctx);
void func_8003B780(uint8_t* rdram, recomp_context* ctx);
void func_8003BB8C(uint8_t* rdram, recomp_context* ctx);
void func_8003C5C8(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_8003AA84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AA84: jr          $ra
    // 0x8003AA88: nop

    return;
    // 0x8003AA88: nop

;}
RECOMP_FUNC void func_8003AA8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AA8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003AA90: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003AA94: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8003AA98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003AA9C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003AAA0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003AAA4: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8003AAA8: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8003AAAC: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x8003AAB0: beq         $v0, $zero, L_8003AD64
    if (ctx->r2 == 0) {
        // 0x8003AAB4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8003AD64;
    }
    // 0x8003AAB4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8003AAB8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8003AABC: addu        $at, $at, $v0
    gpr jr_addend_8003AAC4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003AAC0: lw          $v0, 0x4060($at)
    ctx->r2 = ADD32(ctx->r1, 0X4060);
    // 0x8003AAC4: jr          $v0
    // 0x8003AAC8: nop

    switch (jr_addend_8003AAC4 >> 2) {
        case 0: goto L_8003AD64; break;
        case 1: goto L_8003AD64; break;
        case 2: goto L_8003AACC; break;
        case 3: goto L_8003AC68; break;
        case 4: goto L_8003AC50; break;
        case 5: goto L_8003AD64; break;
        case 6: goto L_8003AD64; break;
        default: switch_error(__func__, 0x8003AAC4, 0x80094060);
    }
    // 0x8003AAC8: nop

L_8003AACC:
    // 0x8003AACC: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8003AAD0: lhu         $v1, 0xCC($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XCC);
    // 0x8003AAD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003AAD8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8003AADC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003AAE0: lw          $v0, 0x7954($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7954);
    // 0x8003AAE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003AAE8: sw          $v1, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = ctx->r3;
    // 0x8003AAEC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8003AAF0: lhu         $a0, 0x168($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X168);
    // 0x8003AAF4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003AAF8: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8003AAFC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8003AB00: bne         $a0, $v0, L_8003AB4C
    if (ctx->r4 != ctx->r2) {
        // 0x8003AB04: nop
    
            goto L_8003AB4C;
    }
    // 0x8003AB04: nop

    // 0x8003AB08: lhu         $a0, 0xCC($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XCC);
    // 0x8003AB0C: sltiu       $v1, $a0, 0x2
    ctx->r3 = ctx->r4 < 0X2 ? 1 : 0;
    // 0x8003AB10: xori        $v0, $a0, 0x5
    ctx->r2 = ctx->r4 ^ 0X5;
    // 0x8003AB14: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8003AB18: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8003AB1C: bnel        $v1, $zero, L_8003AB94
    if (ctx->r3 != 0) {
        // 0x8003AB20: sw          $zero, 0x100($s1)
        MEM_W(0X100, ctx->r17) = 0;
            goto L_8003AB94;
    }
    goto skip_0;
    // 0x8003AB20: sw          $zero, 0x100($s1)
    MEM_W(0X100, ctx->r17) = 0;
    skip_0:
    // 0x8003AB24: sltiu       $v0, $a0, 0x5
    ctx->r2 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x8003AB28: beql        $v0, $zero, L_8003ABA0
    if (ctx->r2 == 0) {
        // 0x8003AB2C: sw          $a1, 0x100($s1)
        MEM_W(0X100, ctx->r17) = ctx->r5;
            goto L_8003ABA0;
    }
    goto skip_1;
    // 0x8003AB2C: sw          $a1, 0x100($s1)
    MEM_W(0X100, ctx->r17) = ctx->r5;
    skip_1:
    // 0x8003AB30: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AB34: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AB38: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x8003AB3C: andi        $v0, $v0, 0xFFEF
    ctx->r2 = ctx->r2 & 0XFFEF;
    // 0x8003AB40: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x8003AB44: j           L_8003AB8C
    // 0x8003AB48: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_8003AB8C;
    // 0x8003AB48: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_8003AB4C:
    // 0x8003AB4C: lhu         $a0, 0xCC($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XCC);
    // 0x8003AB50: sltiu       $v1, $a0, 0x2
    ctx->r3 = ctx->r4 < 0X2 ? 1 : 0;
    // 0x8003AB54: xori        $v0, $a0, 0x5
    ctx->r2 = ctx->r4 ^ 0X5;
    // 0x8003AB58: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8003AB5C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8003AB60: bnel        $v1, $zero, L_8003AB94
    if (ctx->r3 != 0) {
        // 0x8003AB64: sw          $zero, 0x100($s1)
        MEM_W(0X100, ctx->r17) = 0;
            goto L_8003AB94;
    }
    goto skip_2;
    // 0x8003AB64: sw          $zero, 0x100($s1)
    MEM_W(0X100, ctx->r17) = 0;
    skip_2:
    // 0x8003AB68: sltiu       $v0, $a0, 0x6
    ctx->r2 = ctx->r4 < 0X6 ? 1 : 0;
    // 0x8003AB6C: bnel        $v0, $zero, L_8003ABA0
    if (ctx->r2 != 0) {
        // 0x8003AB70: sw          $a1, 0x100($s1)
        MEM_W(0X100, ctx->r17) = ctx->r5;
            goto L_8003ABA0;
    }
    goto skip_3;
    // 0x8003AB70: sw          $a1, 0x100($s1)
    MEM_W(0X100, ctx->r17) = ctx->r5;
    skip_3:
    // 0x8003AB74: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AB78: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AB7C: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x8003AB80: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // 0x8003AB84: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x8003AB88: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8003AB8C:
    // 0x8003AB8C: sh          $v0, 0x168($s1)
    MEM_H(0X168, ctx->r17) = ctx->r2;
    // 0x8003AB90: sw          $zero, 0x100($s1)
    MEM_W(0X100, ctx->r17) = 0;
L_8003AB94:
    // 0x8003AB94: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003AB98: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003AB9C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
L_8003ABA0:
    // 0x8003ABA0: lhu         $v1, 0x1B0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X1B0);
    // 0x8003ABA4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8003ABA8: bne         $v1, $v0, L_8003AC08
    if (ctx->r3 != ctx->r2) {
        // 0x8003ABAC: addiu       $v0, $zero, 0xE1
        ctx->r2 = ADD32(0, 0XE1);
            goto L_8003AC08;
    }
    // 0x8003ABAC: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x8003ABB0: lhu         $a0, 0x1B2($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X1B2);
    // 0x8003ABB4: jal         0x8001B7D0
    // 0x8003ABB8: nop

    func_8001B7D0(rdram, ctx);
        goto after_0;
    // 0x8003ABB8: nop

    after_0:
    // 0x8003ABBC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8003ABC0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003ABC4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003ABC8: lhu         $v0, 0x14($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X14);
    // 0x8003ABCC: lhu         $v1, 0x14($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X14);
    // 0x8003ABD0: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x8003ABD4: beq         $v0, $zero, L_8003AC00
    if (ctx->r2 == 0) {
        // 0x8003ABD8: sll         $v1, $v1, 16
        ctx->r3 = S32(ctx->r3 << 16);
            goto L_8003AC00;
    }
    // 0x8003ABD8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8003ABDC: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    // 0x8003ABE0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003ABE4: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003ABE8: bnel        $v0, $zero, L_8003AD64
    if (ctx->r2 != 0) {
        // 0x8003ABEC: sh          $zero, 0x1B0($s1)
        MEM_H(0X1B0, ctx->r17) = 0;
            goto L_8003AD64;
    }
    goto skip_4;
    // 0x8003ABEC: sh          $zero, 0x1B0($s1)
    MEM_H(0X1B0, ctx->r17) = 0;
    skip_4:
    // 0x8003ABF0: lh          $v0, 0xE($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XE);
    // 0x8003ABF4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003ABF8: beq         $v0, $zero, L_8003AD64
    if (ctx->r2 == 0) {
        // 0x8003ABFC: nop
    
            goto L_8003AD64;
    }
    // 0x8003ABFC: nop

L_8003AC00:
    // 0x8003AC00: j           L_8003AD64
    // 0x8003AC04: sh          $zero, 0x1B0($s1)
    MEM_H(0X1B0, ctx->r17) = 0;
        goto L_8003AD64;
    // 0x8003AC04: sh          $zero, 0x1B0($s1)
    MEM_H(0X1B0, ctx->r17) = 0;
L_8003AC08:
    // 0x8003AC08: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8003AC0C: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x8003AC10: lh          $v1, 0x18($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X18);
    // 0x8003AC14: beq         $v1, $v0, L_8003AD64
    if (ctx->r3 == ctx->r2) {
        // 0x8003AC18: lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
            goto L_8003AD64;
    }
    // 0x8003AC18: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8003AC1C: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8003AC20: ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // 0x8003AC24: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003AC28: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x8003AC2C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AC30: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AC34: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x8003AC38: lui         $a0, 0xE1
    ctx->r4 = S32(0XE1 << 16);
    // 0x8003AC3C: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003AC40: bnel        $v0, $zero, L_8003AD64
    if (ctx->r2 != 0) {
        // 0x8003AC44: sw          $a0, 0x18($v1)
        MEM_W(0X18, ctx->r3) = ctx->r4;
            goto L_8003AD64;
    }
    goto skip_5;
    // 0x8003AC44: sw          $a0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r4;
    skip_5:
    // 0x8003AC48: j           L_8003AD64
    // 0x8003AC4C: nop

        goto L_8003AD64;
    // 0x8003AC4C: nop

L_8003AC50:
    // 0x8003AC50: jal         0x8001D744
    // 0x8003AC54: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D744(rdram, ctx);
        goto after_1;
    // 0x8003AC54: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8003AC58: jal         0x80049560
    // 0x8003AC5C: nop

    func_80049560(rdram, ctx);
        goto after_2;
    // 0x8003AC5C: nop

    after_2:
    // 0x8003AC60: j           L_8003AD64
    // 0x8003AC64: nop

        goto L_8003AD64;
    // 0x8003AC64: nop

L_8003AC68:
    // 0x8003AC68: lw          $v0, 0x68($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X68);
    // 0x8003AC6C: lh          $v0, 0x10($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X10);
    // 0x8003AC70: blez        $v0, L_8003AD64
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003AC74: nop
    
            goto L_8003AD64;
    }
    // 0x8003AC74: nop

    // 0x8003AC78: lh          $v0, 0xF4($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XF4);
    // 0x8003AC7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003AC80: sw          $v0, 0x31AC($at)
    MEM_W(0X31AC, ctx->r1) = ctx->r2;
    // 0x8003AC84: lw          $v0, 0x68($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X68);
    // 0x8003AC88: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8003AC8C: lh          $v1, 0x3E4($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X3E4);
    // 0x8003AC90: lh          $v0, 0x18($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X18);
    // 0x8003AC94: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8003AC98: addiu       $s0, $s0, -0x6C70
    ctx->r16 = ADD32(ctx->r16, -0X6C70);
    // 0x8003AC9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003ACA0: sw          $v0, 0x31B0($at)
    MEM_W(0X31B0, ctx->r1) = ctx->r2;
    // 0x8003ACA4: blez        $v1, L_8003ACF4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8003ACA8: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_8003ACF4;
    }
    // 0x8003ACA8: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_8003ACAC:
    // 0x8003ACAC: lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X14);
    // 0x8003ACB0: beq         $v0, $zero, L_8003ACC0
    if (ctx->r2 == 0) {
        // 0x8003ACB4: addu        $a2, $s0, $zero
        ctx->r6 = ADD32(ctx->r16, 0);
            goto L_8003ACC0;
    }
    // 0x8003ACB4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8003ACB8: j           L_8003ACD0
    // 0x8003ACBC: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
        goto L_8003ACD0;
    // 0x8003ACBC: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
L_8003ACC0:
    // 0x8003ACC0: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
    // 0x8003ACC4: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
    // 0x8003ACC8: jal         0x8003C5C8
    // 0x8003ACCC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8003C5C8(rdram, ctx);
        goto after_3;
    // 0x8003ACCC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
L_8003ACD0:
    // 0x8003ACD0: addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
    // 0x8003ACD4: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8003ACD8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8003ACDC: lh          $v1, 0x3E4($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X3E4);
    // 0x8003ACE0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003ACE4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003ACE8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003ACEC: bne         $v0, $zero, L_8003ACAC
    if (ctx->r2 != 0) {
        // 0x8003ACF0: nop
    
            goto L_8003ACAC;
    }
    // 0x8003ACF0: nop

L_8003ACF4:
    // 0x8003ACF4: lhu         $v0, 0x5A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X5A);
    // 0x8003ACF8: bne         $v0, $zero, L_8003AD64
    if (ctx->r2 != 0) {
        // 0x8003ACFC: nop
    
            goto L_8003AD64;
    }
    // 0x8003ACFC: nop

    // 0x8003AD00: jal         0x80049200
    // 0x8003AD04: nop

    func_80049200(rdram, ctx);
        goto after_4;
    // 0x8003AD04: nop

    after_4:
    // 0x8003AD08: jal         0x8004C79C
    // 0x8003AD0C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_8004C79C(rdram, ctx);
        goto after_5;
    // 0x8003AD0C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_5:
    // 0x8003AD10: jal         0x800306EC
    // 0x8003AD14: nop

    func_800306EC(rdram, ctx);
        goto after_6;
    // 0x8003AD14: nop

    after_6:
    // 0x8003AD18: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8003AD1C: addiu       $v0, $zero, 0x1006
    ctx->r2 = ADD32(0, 0X1006);
    // 0x8003AD20: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003AD24: sw          $a1, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r5;
    // 0x8003AD28: sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
    // 0x8003AD2C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8003AD30: addiu       $v0, $v0, -0x7228
    ctx->r2 = ADD32(ctx->r2, -0X7228);
    // 0x8003AD34: sw          $v0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r2;
    // 0x8003AD38: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003AD3C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8003AD40: lw          $v0, 0x68($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X68);
    // 0x8003AD44: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x8003AD48: lui         $v1, 0xFFFB
    ctx->r3 = S32(0XFFFB << 16);
    // 0x8003AD4C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003AD50: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    // 0x8003AD54: lw          $a0, 0x68($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X68);
    // 0x8003AD58: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8003AD5C: jal         0x80023E44
    // 0x8003AD60: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    func_80023E44(rdram, ctx);
        goto after_7;
    // 0x8003AD60: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    after_7:
L_8003AD64:
    // 0x8003AD64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003AD68: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003AD6C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003AD70: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003AD74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003AD78: jr          $ra
    // 0x8003AD7C: nop

    return;
    // 0x8003AD7C: nop

;}
RECOMP_FUNC void func_8003AD80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AD80: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003AD84: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003AD88: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8003AD8C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003AD90: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003AD94: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8003AD98: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003AD9C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003ADA0: sw          $zero, 0x84($v0)
    MEM_W(0X84, ctx->r2) = 0;
    // 0x8003ADA4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003ADA8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003ADAC: sw          $zero, 0x84($v0)
    MEM_W(0X84, ctx->r2) = 0;
    // 0x8003ADB0: sw          $zero, 0x100($a0)
    MEM_W(0X100, ctx->r4) = 0;
    // 0x8003ADB4: jr          $ra
    // 0x8003ADB8: sw          $zero, 0x104($a0)
    MEM_W(0X104, ctx->r4) = 0;
    return;
    // 0x8003ADB8: sw          $zero, 0x104($a0)
    MEM_W(0X104, ctx->r4) = 0;
;}
RECOMP_FUNC void func_8003ADBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003ADBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003ADC0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8003ADC4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003ADC8: lw          $a0, 0x218($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X218);
    // 0x8003ADCC: beq         $a0, $zero, L_8003ADE4
    if (ctx->r4 == 0) {
        // 0x8003ADD0: nop
    
            goto L_8003ADE4;
    }
    // 0x8003ADD0: nop

    // 0x8003ADD4: jal         0x8003B458
    // 0x8003ADD8: nop

    func_8003B458(rdram, ctx);
        goto after_0;
    // 0x8003ADD8: nop

    after_0:
    // 0x8003ADDC: j           L_8003B144
    // 0x8003ADE0: nop

        goto L_8003B144;
    // 0x8003ADE0: nop

L_8003ADE4:
    // 0x8003ADE4: lw          $v0, 0x200($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X200);
    // 0x8003ADE8: beq         $v0, $zero, L_8003AE7C
    if (ctx->r2 == 0) {
        // 0x8003ADEC: nop
    
            goto L_8003AE7C;
    }
    // 0x8003ADEC: nop

    // 0x8003ADF0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8003ADF4: lw          $a2, 0x31C0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X31C0);
    // 0x8003ADF8: lw          $a0, 0x68($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X68);
    // 0x8003ADFC: lw          $t0, 0x14($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X14);
    // 0x8003AE00: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    // 0x8003AE04: bne         $t0, $a3, L_8003AE24
    if (ctx->r8 != ctx->r7) {
        // 0x8003AE08: slt         $v0, $t0, $a3
        ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_8003AE24;
    }
    // 0x8003AE08: slt         $v0, $t0, $a3
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8003AE0C: lw          $v1, 0x18($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X18);
    // 0x8003AE10: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8003AE14: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003AE18: bne         $v0, $zero, L_8003AE40
    if (ctx->r2 != 0) {
        // 0x8003AE1C: lui         $v0, 0x4
        ctx->r2 = S32(0X4 << 16);
            goto L_8003AE40;
    }
    // 0x8003AE1C: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x8003AE20: slt         $v0, $t0, $a3
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
L_8003AE24:
    // 0x8003AE24: bne         $v0, $zero, L_8003AE7C
    if (ctx->r2 != 0) {
        // 0x8003AE28: nop
    
            goto L_8003AE7C;
    }
    // 0x8003AE28: nop

    // 0x8003AE2C: lw          $v1, 0x18($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X18);
    // 0x8003AE30: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8003AE34: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003AE38: beq         $v0, $zero, L_8003AE4C
    if (ctx->r2 == 0) {
        // 0x8003AE3C: lui         $v0, 0x4
        ctx->r2 = S32(0X4 << 16);
            goto L_8003AE4C;
    }
    // 0x8003AE3C: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
L_8003AE40:
    // 0x8003AE40: sw          $v0, 0x208($a1)
    MEM_W(0X208, ctx->r5) = ctx->r2;
    // 0x8003AE44: j           L_8003AE58
    // 0x8003AE48: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
        goto L_8003AE58;
    // 0x8003AE48: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
L_8003AE4C:
    // 0x8003AE4C: lui         $v0, 0xFFFC
    ctx->r2 = S32(0XFFFC << 16);
    // 0x8003AE50: sw          $v0, 0x208($a1)
    MEM_W(0X208, ctx->r5) = ctx->r2;
    // 0x8003AE54: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
L_8003AE58:
    // 0x8003AE58: sw          $v0, 0x210($a1)
    MEM_W(0X210, ctx->r5) = ctx->r2;
    // 0x8003AE5C: lui         $v0, 0xFFF8
    ctx->r2 = S32(0XFFF8 << 16);
    // 0x8003AE60: sw          $v0, 0x20C($a1)
    MEM_W(0X20C, ctx->r5) = ctx->r2;
    // 0x8003AE64: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x8003AE68: sw          $v0, 0x214($a1)
    MEM_W(0X214, ctx->r5) = ctx->r2;
    // 0x8003AE6C: addiu       $v0, $zero, 0x58
    ctx->r2 = ADD32(0, 0X58);
    // 0x8003AE70: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    // 0x8003AE74: j           L_8003B144
    // 0x8003AE78: sw          $zero, 0x200($a1)
    MEM_W(0X200, ctx->r5) = 0;
        goto L_8003B144;
    // 0x8003AE78: sw          $zero, 0x200($a1)
    MEM_W(0X200, ctx->r5) = 0;
L_8003AE7C:
    // 0x8003AE7C: lhu         $v0, 0xCC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XCC);
    // 0x8003AE80: lw          $a2, 0x1FC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X1FC);
    // 0x8003AE84: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8003AE88: sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x8003AE8C: beq         $v0, $zero, L_8003AFEC
    if (ctx->r2 == 0) {
        // 0x8003AE90: sw          $zero, 0x200($a1)
        MEM_W(0X200, ctx->r5) = 0;
            goto L_8003AFEC;
    }
    // 0x8003AE90: sw          $zero, 0x200($a1)
    MEM_W(0X200, ctx->r5) = 0;
    // 0x8003AE94: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8003AE98: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8003AE9C: addu        $at, $at, $v0
    gpr jr_addend_8003AEA4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003AEA0: lw          $v0, 0x4080($at)
    ctx->r2 = ADD32(ctx->r1, 0X4080);
    // 0x8003AEA4: jr          $v0
    // 0x8003AEA8: nop

    switch (jr_addend_8003AEA4 >> 2) {
        case 0: goto L_8003AFBC; break;
        case 1: goto L_8003AEBC; break;
        case 2: goto L_8003AEAC; break;
        case 3: goto L_8003AEEC; break;
        case 4: goto L_8003AF8C; break;
        case 5: goto L_8003AF5C; break;
        case 6: goto L_8003AF1C; break;
        case 7: goto L_8003AF2C; break;
        default: switch_error(__func__, 0x8003AEA4, 0x80094080);
    }
    // 0x8003AEA8: nop

L_8003AEAC:
    // 0x8003AEAC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AEB0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AEB4: j           L_8003AFF8
    // 0x8003AEB8: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
        goto L_8003AFF8;
    // 0x8003AEB8: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
L_8003AEBC:
    // 0x8003AEBC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AEC0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AEC4: lui         $v0, 0x7
    ctx->r2 = S32(0X7 << 16);
    // 0x8003AEC8: ori         $v0, $v0, 0x7000
    ctx->r2 = ctx->r2 | 0X7000;
    // 0x8003AECC: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8003AED0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AED4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AED8: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8003AEDC: ori         $v0, $v0, 0xA000
    ctx->r2 = ctx->r2 | 0XA000;
    // 0x8003AEE0: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8003AEE4: j           L_8003B010
    // 0x8003AEE8: addiu       $v0, $zero, 0x52
    ctx->r2 = ADD32(0, 0X52);
        goto L_8003B010;
    // 0x8003AEE8: addiu       $v0, $zero, 0x52
    ctx->r2 = ADD32(0, 0X52);
L_8003AEEC:
    // 0x8003AEEC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AEF0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AEF4: lui         $v0, 0x7
    ctx->r2 = S32(0X7 << 16);
    // 0x8003AEF8: ori         $v0, $v0, 0x7000
    ctx->r2 = ctx->r2 | 0X7000;
    // 0x8003AEFC: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8003AF00: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AF04: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AF08: lui         $v0, 0xFFFE
    ctx->r2 = S32(0XFFFE << 16);
    // 0x8003AF0C: ori         $v0, $v0, 0x6000
    ctx->r2 = ctx->r2 | 0X6000;
    // 0x8003AF10: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8003AF14: j           L_8003B010
    // 0x8003AF18: addiu       $v0, $zero, 0x51
    ctx->r2 = ADD32(0, 0X51);
        goto L_8003B010;
    // 0x8003AF18: addiu       $v0, $zero, 0x51
    ctx->r2 = ADD32(0, 0X51);
L_8003AF1C:
    // 0x8003AF1C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AF20: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AF24: j           L_8003AFFC
    // 0x8003AF28: addiu       $v0, $zero, 0x7000
    ctx->r2 = ADD32(0, 0X7000);
        goto L_8003AFFC;
    // 0x8003AF28: addiu       $v0, $zero, 0x7000
    ctx->r2 = ADD32(0, 0X7000);
L_8003AF2C:
    // 0x8003AF2C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AF30: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AF34: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8003AF38: ori         $v0, $v0, 0x7000
    ctx->r2 = ctx->r2 | 0X7000;
    // 0x8003AF3C: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8003AF40: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AF44: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AF48: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8003AF4C: ori         $v0, $v0, 0xA000
    ctx->r2 = ctx->r2 | 0XA000;
    // 0x8003AF50: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8003AF54: j           L_8003B010
    // 0x8003AF58: addiu       $v0, $zero, 0x52
    ctx->r2 = ADD32(0, 0X52);
        goto L_8003B010;
    // 0x8003AF58: addiu       $v0, $zero, 0x52
    ctx->r2 = ADD32(0, 0X52);
L_8003AF5C:
    // 0x8003AF5C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AF60: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AF64: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8003AF68: ori         $v0, $v0, 0x7000
    ctx->r2 = ctx->r2 | 0X7000;
    // 0x8003AF6C: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8003AF70: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AF74: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AF78: lui         $v0, 0xFFFE
    ctx->r2 = S32(0XFFFE << 16);
    // 0x8003AF7C: ori         $v0, $v0, 0x6000
    ctx->r2 = ctx->r2 | 0X6000;
    // 0x8003AF80: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8003AF84: j           L_8003B010
    // 0x8003AF88: addiu       $v0, $zero, 0x51
    ctx->r2 = ADD32(0, 0X51);
        goto L_8003B010;
    // 0x8003AF88: addiu       $v0, $zero, 0x51
    ctx->r2 = ADD32(0, 0X51);
L_8003AF8C:
    // 0x8003AF8C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AF90: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AF94: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x8003AF98: ori         $v0, $v0, 0x7000
    ctx->r2 = ctx->r2 | 0X7000;
    // 0x8003AF9C: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8003AFA0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AFA4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AFA8: lui         $v0, 0xFFFC
    ctx->r2 = S32(0XFFFC << 16);
    // 0x8003AFAC: ori         $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 | 0XC000;
    // 0x8003AFB0: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8003AFB4: j           L_8003B010
    // 0x8003AFB8: addiu       $v0, $zero, 0x51
    ctx->r2 = ADD32(0, 0X51);
        goto L_8003B010;
    // 0x8003AFB8: addiu       $v0, $zero, 0x51
    ctx->r2 = ADD32(0, 0X51);
L_8003AFBC:
    // 0x8003AFBC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AFC0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AFC4: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x8003AFC8: ori         $v0, $v0, 0x7000
    ctx->r2 = ctx->r2 | 0X7000;
    // 0x8003AFCC: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8003AFD0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AFD4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AFD8: lui         $v0, 0x3
    ctx->r2 = S32(0X3 << 16);
    // 0x8003AFDC: ori         $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 | 0X4000;
    // 0x8003AFE0: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8003AFE4: j           L_8003B010
    // 0x8003AFE8: addiu       $v0, $zero, 0x52
    ctx->r2 = ADD32(0, 0X52);
        goto L_8003B010;
    // 0x8003AFE8: addiu       $v0, $zero, 0x52
    ctx->r2 = ADD32(0, 0X52);
L_8003AFEC:
    // 0x8003AFEC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003AFF0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003AFF4: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
L_8003AFF8:
    // 0x8003AFF8: ori         $v0, $v0, 0x7000
    ctx->r2 = ctx->r2 | 0X7000;
L_8003AFFC:
    // 0x8003AFFC: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8003B000: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B004: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003B008: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8003B00C: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
L_8003B010:
    // 0x8003B010: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    // 0x8003B014: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003B018: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003B01C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8003B020: lhu         $v0, 0x4E66($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E66);
    // 0x8003B024: lw          $a0, 0x14($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X14);
    // 0x8003B028: bne         $v0, $zero, L_8003B034
    if (ctx->r2 != 0) {
        // 0x8003B02C: lui         $v0, 0x4
        ctx->r2 = S32(0X4 << 16);
            goto L_8003B034;
    }
    // 0x8003B02C: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x8003B030: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
L_8003B034:
    // 0x8003B034: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8003B038: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8003B03C: addiu       $a1, $a1, 0x46A8
    ctx->r5 = ADD32(ctx->r5, 0X46A8);
    // 0x8003B040: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8003B044: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003B048: bne         $v0, $zero, L_8003B05C
    if (ctx->r2 != 0) {
        // 0x8003B04C: nop
    
            goto L_8003B05C;
    }
    // 0x8003B04C: nop

    // 0x8003B050: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B054: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x8003B058: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_8003B05C:
    // 0x8003B05C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8003B060: lhu         $v0, 0x4E66($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E66);
    // 0x8003B064: bne         $v0, $zero, L_8003B0A8
    if (ctx->r2 != 0) {
        // 0x8003B068: lui         $v0, 0x50
        ctx->r2 = S32(0X50 << 16);
            goto L_8003B0A8;
    }
    // 0x8003B068: lui         $v0, 0x50
    ctx->r2 = S32(0X50 << 16);
    // 0x8003B06C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003B070: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B074: bnel        $v0, $zero, L_8003B0A0
    if (ctx->r2 != 0) {
        // 0x8003B078: lui         $a0, 0x50
        ctx->r4 = S32(0X50 << 16);
            goto L_8003B0A0;
    }
    goto skip_0;
    // 0x8003B078: lui         $a0, 0x50
    ctx->r4 = S32(0X50 << 16);
    skip_0:
    // 0x8003B07C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8003B080: lui         $v0, 0x140
    ctx->r2 = S32(0X140 << 16);
    // 0x8003B084: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003B088: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003B08C: beq         $v0, $zero, L_8003B0A8
    if (ctx->r2 == 0) {
        // 0x8003B090: nop
    
            goto L_8003B0A8;
    }
    // 0x8003B090: nop

    // 0x8003B094: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8003B098: j           L_8003B0A4
    // 0x8003B09C: lui         $a0, 0x140
    ctx->r4 = S32(0X140 << 16);
        goto L_8003B0A4;
    // 0x8003B09C: lui         $a0, 0x140
    ctx->r4 = S32(0X140 << 16);
L_8003B0A0:
    // 0x8003B0A0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
L_8003B0A4:
    // 0x8003B0A4: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
L_8003B0A8:
    // 0x8003B0A8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B0AC: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x8003B0B0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003B0B4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003B0B8: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x8003B0BC: sw          $a0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r4;
    // 0x8003B0C0: sw          $a0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r4;
    // 0x8003B0C4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003B0C8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003B0CC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8003B0D0: lhu         $v0, 0x4E66($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E66);
    // 0x8003B0D4: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    // 0x8003B0D8: beq         $v0, $zero, L_8003B0E8
    if (ctx->r2 == 0) {
        // 0x8003B0DC: lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
            goto L_8003B0E8;
    }
    // 0x8003B0DC: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8003B0E0: j           L_8003B0EC
    // 0x8003B0E4: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
        goto L_8003B0EC;
    // 0x8003B0E4: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
L_8003B0E8:
    // 0x8003B0E8: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
L_8003B0EC:
    // 0x8003B0EC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8003B0F0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8003B0F4: lhu         $v0, 0x4E66($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E66);
    // 0x8003B0F8: bne         $v0, $zero, L_8003B120
    if (ctx->r2 != 0) {
        // 0x8003B0FC: lui         $v0, 0xFFC9
        ctx->r2 = S32(0XFFC9 << 16);
            goto L_8003B120;
    }
    // 0x8003B0FC: lui         $v0, 0xFFC9
    ctx->r2 = S32(0XFFC9 << 16);
    // 0x8003B100: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003B104: beq         $v0, $zero, L_8003B114
    if (ctx->r2 == 0) {
        // 0x8003B108: lui         $v0, 0x82
        ctx->r2 = S32(0X82 << 16);
            goto L_8003B114;
    }
    // 0x8003B108: lui         $v0, 0x82
    ctx->r2 = S32(0X82 << 16);
    // 0x8003B10C: j           L_8003B120
    // 0x8003B110: lui         $a0, 0xFFC9
    ctx->r4 = S32(0XFFC9 << 16);
        goto L_8003B120;
    // 0x8003B110: lui         $a0, 0xFFC9
    ctx->r4 = S32(0XFFC9 << 16);
L_8003B114:
    // 0x8003B114: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003B118: bnel        $v0, $zero, L_8003B120
    if (ctx->r2 != 0) {
        // 0x8003B11C: lui         $a0, 0x82
        ctx->r4 = S32(0X82 << 16);
            goto L_8003B120;
    }
    goto skip_1;
    // 0x8003B11C: lui         $a0, 0x82
    ctx->r4 = S32(0X82 << 16);
    skip_1:
L_8003B120:
    // 0x8003B120: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B124: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003B128: sw          $a0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r4;
    // 0x8003B12C: sw          $a0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r4;
    // 0x8003B130: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B134: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003B138: lhu         $v0, 0x80($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X80);
    // 0x8003B13C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8003B140: sh          $v0, 0x80($a2)
    MEM_H(0X80, ctx->r6) = ctx->r2;
L_8003B144:
    // 0x8003B144: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003B148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B14C: jr          $ra
    // 0x8003B150: nop

    return;
    // 0x8003B150: nop

;}
RECOMP_FUNC void func_8003B154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B154: lh          $v0, 0x10C($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X10C);
    // 0x8003B158: lh          $v1, 0x108($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X108);
    // 0x8003B15C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B160: bne         $v0, $zero, L_8003B1A0
    if (ctx->r2 != 0) {
        // 0x8003B164: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003B1A0;
    }
    // 0x8003B164: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003B168: lh          $v0, 0x10E($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X10E);
    // 0x8003B16C: lh          $v1, 0x10A($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X10A);
    // 0x8003B170: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B174: bne         $v0, $zero, L_8003B1A0
    if (ctx->r2 != 0) {
        // 0x8003B178: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003B1A0;
    }
    // 0x8003B178: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003B17C: lh          $v1, 0x108($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X108);
    // 0x8003B180: lh          $v0, 0x10C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X10C);
    // 0x8003B184: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B188: bne         $v0, $zero, L_8003B1A0
    if (ctx->r2 != 0) {
        // 0x8003B18C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003B1A0;
    }
    // 0x8003B18C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003B190: lh          $v1, 0x10A($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10A);
    // 0x8003B194: lh          $v0, 0x10E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X10E);
    // 0x8003B198: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B19C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_8003B1A0:
    // 0x8003B1A0: jr          $ra
    // 0x8003B1A4: nop

    return;
    // 0x8003B1A4: nop

;}
RECOMP_FUNC void func_8003B1A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B1A8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8003B1AC: lhu         $v0, 0x4E66($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E66);
    // FALLTHROUGH: func_8003B1A8 falls into func_8003B1B0
    func_8003B1B0(rdram, ctx);
;}
RECOMP_FUNC void func_8003B1B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B1B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003B1B4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003B1B8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8003B1BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003B1C0: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8003B1C4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8003B1C8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003B1CC: bne         $v0, $zero, L_8003B24C
    if (ctx->r2 != 0) {
        // 0x8003B1D0: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8003B24C;
    }
    // 0x8003B1D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003B1D4: lhu         $v1, 0x5A($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X5A);
    // 0x8003B1D8: addiu       $v0, $zero, 0x58
    ctx->r2 = ADD32(0, 0X58);
    // 0x8003B1DC: beq         $v1, $v0, L_8003B24C
    if (ctx->r3 == ctx->r2) {
        // 0x8003B1E0: addiu       $s2, $zero, 0x7
        ctx->r18 = ADD32(0, 0X7);
            goto L_8003B24C;
    }
    // 0x8003B1E0: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
    // 0x8003B1E4: lui         $s4, 0x8015
    ctx->r20 = S32(0X8015 << 16);
    // 0x8003B1E8: addiu       $s4, $s4, 0x3F94
    ctx->r20 = ADD32(ctx->r20, 0X3F94);
    // 0x8003B1EC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8003B1F0: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
L_8003B1F4:
    // 0x8003B1F4: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8003B1F8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003B1FC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8003B200: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8003B204: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8003B208: addu        $s0, $v1, $s4
    ctx->r16 = ADD32(ctx->r3, ctx->r20);
    // 0x8003B20C: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
    // 0x8003B210: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8003B214: beql        $v0, $zero, L_8003B23C
    if (ctx->r2 == 0) {
        // 0x8003B218: addiu       $v0, $s2, -0x1
        ctx->r2 = ADD32(ctx->r18, -0X1);
            goto L_8003B23C;
    }
    goto skip_0;
    // 0x8003B218: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x8003B21C: beq         $s0, $s1, L_8003B238
    if (ctx->r16 == ctx->r17) {
        // 0x8003B220: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8003B238;
    }
    // 0x8003B220: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8003B224: jal         0x8003B154
    // 0x8003B228: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003B154(rdram, ctx);
        goto after_0;
    // 0x8003B228: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8003B22C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003B230: beql        $v0, $s3, L_8003B238
    if (ctx->r2 == ctx->r19) {
        // 0x8003B234: sw          $s0, 0x200($s1)
        MEM_W(0X200, ctx->r17) = ctx->r16;
            goto L_8003B238;
    }
    goto skip_1;
    // 0x8003B234: sw          $s0, 0x200($s1)
    MEM_W(0X200, ctx->r17) = ctx->r16;
    skip_1:
L_8003B238:
    // 0x8003B238: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
L_8003B23C:
    // 0x8003B23C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8003B240: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003B244: bne         $v0, $zero, L_8003B1F4
    if (ctx->r2 != 0) {
        // 0x8003B248: andi        $v0, $s2, 0xFFFF
        ctx->r2 = ctx->r18 & 0XFFFF;
            goto L_8003B1F4;
    }
    // 0x8003B248: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
L_8003B24C:
    // 0x8003B24C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003B250: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8003B254: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B258: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003B25C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003B260: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003B264: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003B268: jr          $ra
    // 0x8003B26C: nop

    return;
    // 0x8003B26C: nop

;}
RECOMP_FUNC void func_8003B270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B270: lw          $a1, 0x20C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X20C);
    // 0x8003B274: lw          $v1, 0x214($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X214);
    // 0x8003B278: lw          $a2, 0x1FC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1FC);
    // 0x8003B27C: sw          $zero, 0x200($a0)
    MEM_W(0X200, ctx->r4) = 0;
    // 0x8003B280: sw          $zero, 0x218($a0)
    MEM_W(0X218, ctx->r4) = 0;
    // 0x8003B284: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8003B288: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x8003B28C: bgez        $a1, L_8003B298
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8003B290: sw          $a1, 0x20C($a0)
        MEM_W(0X20C, ctx->r4) = ctx->r5;
            goto L_8003B298;
    }
    // 0x8003B290: sw          $a1, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->r5;
    // 0x8003B294: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
L_8003B298:
    // 0x8003B298: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8003B29C: bgez        $v1, L_8003B2A8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8003B2A0: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8003B2A8;
    }
    // 0x8003B2A0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8003B2A4: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_8003B2A8:
    // 0x8003B2A8: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003B2AC: beql        $v0, $zero, L_8003B2B4
    if (ctx->r2 == 0) {
        // 0x8003B2B0: sw          $zero, 0x214($a0)
        MEM_W(0X214, ctx->r4) = 0;
            goto L_8003B2B4;
    }
    goto skip_0;
    // 0x8003B2B0: sw          $zero, 0x214($a0)
    MEM_W(0X214, ctx->r4) = 0;
    skip_0:
L_8003B2B4:
    // 0x8003B2B4: lw          $a1, 0x20C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X20C);
    // 0x8003B2B8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B2BC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003B2C0: sw          $a1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r5;
    // 0x8003B2C4: lw          $a1, 0x208($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X208);
    // 0x8003B2C8: lw          $v1, 0x210($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X210);
    // 0x8003B2CC: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8003B2D0: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x8003B2D4: bgez        $a1, L_8003B2E0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8003B2D8: sw          $a1, 0x208($a0)
        MEM_W(0X208, ctx->r4) = ctx->r5;
            goto L_8003B2E0;
    }
    // 0x8003B2D8: sw          $a1, 0x208($a0)
    MEM_W(0X208, ctx->r4) = ctx->r5;
    // 0x8003B2DC: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
L_8003B2E0:
    // 0x8003B2E0: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8003B2E4: bgez        $v1, L_8003B2F0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8003B2E8: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8003B2F0;
    }
    // 0x8003B2E8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8003B2EC: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_8003B2F0:
    // 0x8003B2F0: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003B2F4: beql        $v0, $zero, L_8003B2FC
    if (ctx->r2 == 0) {
        // 0x8003B2F8: sw          $zero, 0x210($a0)
        MEM_W(0X210, ctx->r4) = 0;
            goto L_8003B2FC;
    }
    goto skip_1;
    // 0x8003B2F8: sw          $zero, 0x210($a0)
    MEM_W(0X210, ctx->r4) = 0;
    skip_1:
L_8003B2FC:
    // 0x8003B2FC: lw          $a1, 0x208($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X208);
    // 0x8003B300: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B304: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003B308: sw          $a1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r5;
    // 0x8003B30C: lw          $v0, 0x210($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X210);
    // 0x8003B310: lw          $v1, 0x214($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X214);
    // 0x8003B314: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8003B318: bne         $v0, $zero, L_8003B324
    if (ctx->r2 != 0) {
        // 0x8003B31C: addiu       $v0, $zero, 0x50
        ctx->r2 = ADD32(0, 0X50);
            goto L_8003B324;
    }
    // 0x8003B31C: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8003B320: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
L_8003B324:
    // 0x8003B324: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003B328: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003B32C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8003B330: lhu         $v0, 0x4E66($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E66);
    // 0x8003B334: lw          $a1, 0x14($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14);
    // 0x8003B338: bne         $v0, $zero, L_8003B344
    if (ctx->r2 != 0) {
        // 0x8003B33C: lui         $v0, 0x4
        ctx->r2 = S32(0X4 << 16);
            goto L_8003B344;
    }
    // 0x8003B33C: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x8003B340: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
L_8003B344:
    // 0x8003B344: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8003B348: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8003B34C: addiu       $a0, $a0, 0x46A8
    ctx->r4 = ADD32(ctx->r4, 0X46A8);
    // 0x8003B350: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8003B354: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003B358: bne         $v0, $zero, L_8003B36C
    if (ctx->r2 != 0) {
        // 0x8003B35C: nop
    
            goto L_8003B36C;
    }
    // 0x8003B35C: nop

    // 0x8003B360: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B364: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x8003B368: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
L_8003B36C:
    // 0x8003B36C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8003B370: lhu         $v0, 0x4E66($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E66);
    // 0x8003B374: bne         $v0, $zero, L_8003B3B8
    if (ctx->r2 != 0) {
        // 0x8003B378: lui         $v0, 0x50
        ctx->r2 = S32(0X50 << 16);
            goto L_8003B3B8;
    }
    // 0x8003B378: lui         $v0, 0x50
    ctx->r2 = S32(0X50 << 16);
    // 0x8003B37C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003B380: slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B384: beq         $v0, $zero, L_8003B398
    if (ctx->r2 == 0) {
        // 0x8003B388: lui         $v0, 0x140
        ctx->r2 = S32(0X140 << 16);
            goto L_8003B398;
    }
    // 0x8003B388: lui         $v0, 0x140
    ctx->r2 = S32(0X140 << 16);
    // 0x8003B38C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003B390: j           L_8003B3B4
    // 0x8003B394: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
        goto L_8003B3B4;
    // 0x8003B394: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
L_8003B398:
    // 0x8003B398: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8003B39C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003B3A0: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003B3A4: beq         $v0, $zero, L_8003B3B8
    if (ctx->r2 == 0) {
        // 0x8003B3A8: nop
    
            goto L_8003B3B8;
    }
    // 0x8003B3A8: nop

    // 0x8003B3AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003B3B0: lui         $a1, 0x140
    ctx->r5 = S32(0X140 << 16);
L_8003B3B4:
    // 0x8003B3B4: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
L_8003B3B8:
    // 0x8003B3B8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B3BC: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x8003B3C0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003B3C4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003B3C8: and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    // 0x8003B3CC: sw          $a1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r5;
    // 0x8003B3D0: sw          $a1, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r5;
    // 0x8003B3D4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003B3D8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003B3DC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8003B3E0: lhu         $v0, 0x4E66($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E66);
    // 0x8003B3E4: lw          $a1, 0x18($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X18);
    // 0x8003B3E8: beq         $v0, $zero, L_8003B3F8
    if (ctx->r2 == 0) {
        // 0x8003B3EC: lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
            goto L_8003B3F8;
    }
    // 0x8003B3EC: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8003B3F0: j           L_8003B3FC
    // 0x8003B3F4: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
        goto L_8003B3FC;
    // 0x8003B3F4: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
L_8003B3F8:
    // 0x8003B3F8: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
L_8003B3FC:
    // 0x8003B3FC: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8003B400: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8003B404: lhu         $v0, 0x4E66($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E66);
    // 0x8003B408: bne         $v0, $zero, L_8003B430
    if (ctx->r2 != 0) {
        // 0x8003B40C: lui         $v0, 0xFFC9
        ctx->r2 = S32(0XFFC9 << 16);
            goto L_8003B430;
    }
    // 0x8003B40C: lui         $v0, 0xFFC9
    ctx->r2 = S32(0XFFC9 << 16);
    // 0x8003B410: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003B414: beq         $v0, $zero, L_8003B424
    if (ctx->r2 == 0) {
        // 0x8003B418: lui         $v0, 0x82
        ctx->r2 = S32(0X82 << 16);
            goto L_8003B424;
    }
    // 0x8003B418: lui         $v0, 0x82
    ctx->r2 = S32(0X82 << 16);
    // 0x8003B41C: j           L_8003B430
    // 0x8003B420: lui         $a1, 0xFFC9
    ctx->r5 = S32(0XFFC9 << 16);
        goto L_8003B430;
    // 0x8003B420: lui         $a1, 0xFFC9
    ctx->r5 = S32(0XFFC9 << 16);
L_8003B424:
    // 0x8003B424: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003B428: bnel        $v0, $zero, L_8003B430
    if (ctx->r2 != 0) {
        // 0x8003B42C: lui         $a1, 0x82
        ctx->r5 = S32(0X82 << 16);
            goto L_8003B430;
    }
    goto skip_2;
    // 0x8003B42C: lui         $a1, 0x82
    ctx->r5 = S32(0X82 << 16);
    skip_2:
L_8003B430:
    // 0x8003B430: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B434: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003B438: sw          $a1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r5;
    // 0x8003B43C: sw          $a1, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r5;
    // 0x8003B440: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B444: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003B448: lhu         $v0, 0x80($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X80);
    // 0x8003B44C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8003B450: jr          $ra
    // 0x8003B454: sh          $v0, 0x80($a2)
    MEM_H(0X80, ctx->r6) = ctx->r2;
    return;
    // 0x8003B454: sh          $v0, 0x80($a2)
    MEM_H(0X80, ctx->r6) = ctx->r2;
;}
RECOMP_FUNC void func_8003B458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B458: sw          $zero, 0x208($a1)
    MEM_W(0X208, ctx->r5) = 0;
    // 0x8003B45C: sw          $zero, 0x210($a1)
    MEM_W(0X210, ctx->r5) = 0;
    // 0x8003B460: lui         $v0, 0xFFF6
    ctx->r2 = S32(0XFFF6 << 16);
    // 0x8003B464: sw          $v0, 0x20C($a1)
    MEM_W(0X20C, ctx->r5) = ctx->r2;
    // 0x8003B468: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x8003B46C: sw          $v0, 0x214($a1)
    MEM_W(0X214, ctx->r5) = ctx->r2;
    // 0x8003B470: addiu       $v0, $zero, 0x58
    ctx->r2 = ADD32(0, 0X58);
    // 0x8003B474: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    // 0x8003B478: jr          $ra
    // 0x8003B47C: sw          $zero, 0x200($a1)
    MEM_W(0X200, ctx->r5) = 0;
    return;
    // 0x8003B47C: sw          $zero, 0x200($a1)
    MEM_W(0X200, ctx->r5) = 0;
;}
RECOMP_FUNC void func_8003B480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B480: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B484: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003B488: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8003B48C: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x8003B490: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8003B494: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8003B498: lhu         $v1, 0x5874($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X5874);
    // 0x8003B49C: jr          $ra
    // 0x8003B4A0: sh          $v1, 0x8C($v0)
    MEM_H(0X8C, ctx->r2) = ctx->r3;
    return;
    // 0x8003B4A0: sh          $v1, 0x8C($v0)
    MEM_H(0X8C, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_8003B4A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B4A4: lhu         $v0, 0xDC($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XDC);
    // 0x8003B4A8: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x8003B4AC: beq         $v0, $zero, L_8003B4C4
    if (ctx->r2 == 0) {
        // 0x8003B4B0: addu        $t1, $a1, $zero
        ctx->r9 = ADD32(ctx->r5, 0);
            goto L_8003B4C4;
    }
    // 0x8003B4B0: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x8003B4B4: lhu         $v1, 0x5A($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X5A);
    // 0x8003B4B8: addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
    // 0x8003B4BC: bne         $v1, $v0, L_8003B4CC
    if (ctx->r3 != ctx->r2) {
        // 0x8003B4C0: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_8003B4CC;
    }
    // 0x8003B4C0: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_8003B4C4:
    // 0x8003B4C4: j           L_8003B5AC
    // 0x8003B4C8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8003B5AC;
    // 0x8003B4C8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003B4CC:
    // 0x8003B4CC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8003B4D0: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x8003B4D4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B4D8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B4DC: beq         $v0, $zero, L_8003B4F8
    if (ctx->r2 == 0) {
        // 0x8003B4E0: nop
    
            goto L_8003B4F8;
    }
    // 0x8003B4E0: nop

    // 0x8003B4E4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B4E8: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x8003B4EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003B4F0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B4F4: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
L_8003B4F8:
    // 0x8003B4F8: lh          $v1, 0x108($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X108);
    // 0x8003B4FC: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x8003B500: sra         $a3, $v0, 16
    ctx->r7 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B504: lh          $v0, 0x10A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X10A);
    // 0x8003B508: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x8003B50C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003B510: slt         $v1, $a3, $v1
    ctx->r3 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B514: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8003B518: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003B51C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8003B520: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8003B524: beq         $v1, $zero, L_8003B558
    if (ctx->r3 == 0) {
        // 0x8003B528: nop
    
            goto L_8003B558;
    }
    // 0x8003B528: nop

    // 0x8003B52C: lh          $v0, 0x10C($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X10C);
    // 0x8003B530: lh          $v1, 0x10E($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X10E);
    // 0x8003B534: slt         $v0, $v0, $a3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8003B538: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8003B53C: slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003B540: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8003B544: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8003B548: beq         $v0, $zero, L_8003B558
    if (ctx->r2 == 0) {
        // 0x8003B54C: nop
    
            goto L_8003B558;
    }
    // 0x8003B54C: nop

    // 0x8003B550: j           L_8003B5AC
    // 0x8003B554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003B5AC;
    // 0x8003B554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003B558:
    // 0x8003B558: lh          $a0, 0x110($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X110);
    // 0x8003B55C: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x8003B560: sra         $a3, $v1, 16
    ctx->r7 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003B564: lh          $v1, 0x112($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X112);
    // 0x8003B568: sll         $a1, $t1, 16
    ctx->r5 = S32(ctx->r9 << 16);
    // 0x8003B56C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8003B570: slt         $a0, $a3, $a0
    ctx->r4 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003B574: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
    // 0x8003B578: slt         $v1, $a1, $v1
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B57C: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8003B580: and         $a0, $a0, $v1
    ctx->r4 = ctx->r4 & ctx->r3;
    // 0x8003B584: beq         $a0, $zero, L_8003B5AC
    if (ctx->r4 == 0) {
        // 0x8003B588: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003B5AC;
    }
    // 0x8003B588: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003B58C: lh          $v0, 0x114($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X114);
    // 0x8003B590: lh          $v1, 0x116($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X116);
    // 0x8003B594: slt         $v0, $v0, $a3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8003B598: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8003B59C: slt         $v1, $v1, $a1
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003B5A0: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8003B5A4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8003B5A8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8003B5AC:
    // 0x8003B5AC: jr          $ra
    // 0x8003B5B0: nop

    return;
    // 0x8003B5B0: nop

;}
RECOMP_FUNC void func_8003B5B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B5B4: lhu         $v0, 0xDC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XDC);
    // 0x8003B5B8: beq         $v0, $zero, L_8003B5EC
    if (ctx->r2 == 0) {
                func_8003B5BC(rdram, ctx); return; // was goto L_8003B5EC
    }
;}
RECOMP_FUNC void func_8003B5BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B5BC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8003B5C0: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8003B5C4: lw          $v0, -0x307C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X307C);
    // 0x8003B5C8: andi        $v0, $v0, 0x7000
    ctx->r2 = ctx->r2 & 0X7000;
    // 0x8003B5CC: beq         $v0, $zero, L_8003B600
    if (ctx->r2 == 0) {
        // 0x8003B5D0: nop
    
            goto L_8003B600;
    }
    // 0x8003B5D0: nop

    // 0x8003B5D4: lhu         $v0, 0x1B0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1B0);
    // 0x8003B5D8: beq         $v0, $zero, L_8003B5F4
    if (ctx->r2 == 0) {
        // 0x8003B5DC: nop
    
            goto L_8003B5F4;
    }
    // 0x8003B5DC: nop

    // 0x8003B5E0: lhu         $v0, 0x1B0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1B0);
    // 0x8003B5E4: bne         $v0, $zero, L_8003B600
    if (ctx->r2 != 0) {
        // 0x8003B5E8: nop
    
            goto L_8003B600;
    }
    // 0x8003B5E8: nop

    // 0x8003B5EC: j           L_8003B710
    // 0x8003B5F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8003B710;
    // 0x8003B5F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003B5F4:
    // 0x8003B5F4: lhu         $v0, 0x1B0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1B0);
    // 0x8003B5F8: bne         $v0, $zero, L_8003B710
    if (ctx->r2 != 0) {
        // 0x8003B5FC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003B710;
    }
    // 0x8003B5FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003B600:
    // 0x8003B600: lh          $v0, 0x118($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X118);
    // 0x8003B604: lhu         $t0, 0x11C($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X11C);
    // 0x8003B608: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8003B60C: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x8003B610: lhu         $t2, 0x11A($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X11A);
    // 0x8003B614: lhu         $t3, 0x11E($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X11E);
    // 0x8003B618: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8003B61C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B620: beq         $v0, $zero, L_8003B640
    if (ctx->r2 == 0) {
        // 0x8003B624: nop
    
            goto L_8003B640;
    }
    // 0x8003B624: nop

    // 0x8003B628: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B62C: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x8003B630: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003B634: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B638: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8003B63C: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
L_8003B640:
    // 0x8003B640: lhu         $t1, 0x10A($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X10A);
    // 0x8003B644: lhu         $a3, 0x10E($a1)
    ctx->r7 = MEM_HU(ctx->r5, 0X10E);
    // 0x8003B648: lh          $v0, 0x10C($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X10C);
    // 0x8003B64C: sll         $v1, $a2, 16
    ctx->r3 = S32(ctx->r6 << 16);
    // 0x8003B650: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003B654: lh          $a0, 0x108($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X108);
    // 0x8003B658: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003B65C: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x8003B660: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B664: slt         $a0, $a0, $v0
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003B668: and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // 0x8003B66C: beq         $v1, $zero, L_8003B6AC
    if (ctx->r3 == 0) {
        // 0x8003B670: sll         $v1, $t2, 16
        ctx->r3 = S32(ctx->r10 << 16);
            goto L_8003B6AC;
    }
    // 0x8003B670: sll         $v1, $t2, 16
    ctx->r3 = S32(ctx->r10 << 16);
    // 0x8003B674: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003B678: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x8003B67C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B680: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003B684: sll         $a0, $t3, 16
    ctx->r4 = S32(ctx->r11 << 16);
    // 0x8003B688: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003B68C: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x8003B690: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B694: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003B698: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8003B69C: beq         $v1, $zero, L_8003B6AC
    if (ctx->r3 == 0) {
        // 0x8003B6A0: nop
    
            goto L_8003B6AC;
    }
    // 0x8003B6A0: nop

    // 0x8003B6A4: j           L_8003B710
    // 0x8003B6A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003B710;
    // 0x8003B6A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003B6AC:
    // 0x8003B6AC: lhu         $t1, 0x112($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X112);
    // 0x8003B6B0: lhu         $a3, 0x116($a1)
    ctx->r7 = MEM_HU(ctx->r5, 0X116);
    // 0x8003B6B4: lh          $v1, 0x114($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X114);
    // 0x8003B6B8: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    // 0x8003B6BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003B6C0: lh          $a1, 0x110($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X110);
    // 0x8003B6C4: slt         $a0, $a0, $v1
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B6C8: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x8003B6CC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003B6D0: slt         $a1, $a1, $v1
    ctx->r5 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B6D4: and         $a0, $a0, $a1
    ctx->r4 = ctx->r4 & ctx->r5;
    // 0x8003B6D8: beq         $a0, $zero, L_8003B710
    if (ctx->r4 == 0) {
        // 0x8003B6DC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003B710;
    }
    // 0x8003B6DC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003B6E0: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x8003B6E4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B6E8: sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7 << 16);
    // 0x8003B6EC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003B6F0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B6F4: sll         $a0, $t3, 16
    ctx->r4 = S32(ctx->r11 << 16);
    // 0x8003B6F8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003B6FC: sll         $v1, $t1, 16
    ctx->r3 = S32(ctx->r9 << 16);
    // 0x8003B700: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003B704: slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003B708: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8003B70C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8003B710:
    // 0x8003B710: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8003B714: jr          $ra
    // 0x8003B718: nop

    return;
    // 0x8003B718: nop

;}
RECOMP_FUNC void func_8003B71C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B71C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003B720: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8003B724: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8003B728: lhu         $v0, 0xDC($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0XDC);
    // 0x8003B72C: beq         $v0, $zero, L_8003B740
    if (ctx->r2 == 0) {
        // 0x8003B730: addiu       $v0, $zero, 0x37
        ctx->r2 = ADD32(0, 0X37);
            goto L_8003B740;
    }
    // 0x8003B730: addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
    // 0x8003B734: lhu         $v1, 0x5A($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X5A);
    // 0x8003B738: bnel        $v1, $v0, L_8003B748
    if (ctx->r3 != ctx->r2) {
        // 0x8003B73C: sw          $t0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r8;
            goto L_8003B748;
    }
    goto skip_0;
    // 0x8003B73C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    skip_0:
L_8003B740:
    // 0x8003B740: j           L_8003B770
    // 0x8003B744: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8003B770;
    // 0x8003B744: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003B748:
    // 0x8003B748: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8003B74C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8003B750: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8003B754: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8003B758: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003B75C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8003B760: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8003B764: jal         0x8003B780
    // 0x8003B768: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    func_8003B780(rdram, ctx);
        goto after_0;
    // 0x8003B768: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    after_0:
    // 0x8003B76C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_8003B770:
    // 0x8003B770: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8003B774: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003B778: jr          $ra
    // 0x8003B77C: nop

    return;
    // 0x8003B77C: nop

;}
RECOMP_FUNC void func_8003B780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B780: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x8003B784: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8003B788: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x8003B78C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8003B790: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B794: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B798: beq         $v0, $zero, L_8003B7B4
    if (ctx->r2 == 0) {
        // 0x8003B79C: addu        $t0, $a0, $zero
        ctx->r8 = ADD32(ctx->r4, 0);
            goto L_8003B7B4;
    }
    // 0x8003B79C: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x8003B7A0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B7A4: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x8003B7A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003B7AC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B7B0: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
L_8003B7B4:
    // 0x8003B7B4: lhu         $v0, 0x108($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X108);
    // 0x8003B7B8: lhu         $v1, 0x10A($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X10A);
    // 0x8003B7BC: sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8 << 16);
    // 0x8003B7C0: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003B7C4: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x8003B7C8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003B7CC: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x8003B7D0: subu        $v1, $v1, $a3
    ctx->r3 = SUB32(ctx->r3, ctx->r7);
    // 0x8003B7D4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003B7D8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B7DC: slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003B7E0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8003B7E4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003B7E8: slt         $v1, $a0, $v1
    ctx->r3 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B7EC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8003B7F0: bne         $v0, $zero, L_8003B828
    if (ctx->r2 != 0) {
        // 0x8003B7F4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003B828;
    }
    // 0x8003B7F4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003B7F8: lhu         $v0, 0x10C($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X10C);
    // 0x8003B7FC: lhu         $v1, 0x10E($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X10E);
    // 0x8003B800: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8003B804: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x8003B808: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003B80C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B810: slt         $v0, $v0, $t0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8003B814: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8003B818: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003B81C: slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003B820: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8003B824: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_8003B828:
    // 0x8003B828: jr          $ra
    // 0x8003B82C: nop

    return;
    // 0x8003B82C: nop

;}
RECOMP_FUNC void func_8003B830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B830: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x8003B834: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x8003B838: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8003B83C: addu        $t5, $t1, $zero
    ctx->r13 = ADD32(ctx->r9, 0);
    // 0x8003B840: lhu         $v0, 0xDC($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0XDC);
    // 0x8003B844: addu        $t3, $a2, $zero
    ctx->r11 = ADD32(ctx->r6, 0);
    // 0x8003B848: beq         $v0, $zero, L_8003B860
    if (ctx->r2 == 0) {
        // 0x8003B84C: addu        $t4, $a3, $zero
        ctx->r12 = ADD32(ctx->r7, 0);
            goto L_8003B860;
    }
    // 0x8003B84C: addu        $t4, $a3, $zero
    ctx->r12 = ADD32(ctx->r7, 0);
    // 0x8003B850: lhu         $v1, 0x5A($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X5A);
    // 0x8003B854: addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
    // 0x8003B858: bne         $v1, $v0, L_8003B868
    if (ctx->r3 != ctx->r2) {
        // 0x8003B85C: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_8003B868;
    }
    // 0x8003B85C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_8003B860:
    // 0x8003B860: j           L_8003B9A8
    // 0x8003B864: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8003B9A8;
    // 0x8003B864: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003B868:
    // 0x8003B868: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8003B86C: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x8003B870: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B874: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B878: beq         $v0, $zero, L_8003B894
    if (ctx->r2 == 0) {
        // 0x8003B87C: nop
    
            goto L_8003B894;
    }
    // 0x8003B87C: nop

    // 0x8003B880: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B884: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x8003B888: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003B88C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B890: addu        $a1, $a0, $v0
    ctx->r5 = ADD32(ctx->r4, ctx->r2);
L_8003B894:
    // 0x8003B894: lhu         $v1, 0x108($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X108);
    // 0x8003B898: lhu         $a0, 0x10A($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X10A);
    // 0x8003B89C: subu        $v0, $v1, $a2
    ctx->r2 = SUB32(ctx->r3, ctx->r6);
    // 0x8003B8A0: subu        $v1, $a0, $a3
    ctx->r3 = SUB32(ctx->r4, ctx->r7);
    // 0x8003B8A4: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x8003B8A8: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003B8AC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003B8B0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B8B4: slt         $v0, $t2, $v0
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003B8B8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8003B8BC: sll         $a0, $t1, 16
    ctx->r4 = S32(ctx->r9 << 16);
    // 0x8003B8C0: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003B8C4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8003B8C8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003B8CC: slt         $v1, $t1, $v1
    ctx->r3 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B8D0: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8003B8D4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8003B8D8: beq         $v0, $zero, L_8003B924
    if (ctx->r2 == 0) {
        // 0x8003B8DC: nop
    
            goto L_8003B924;
    }
    // 0x8003B8DC: nop

    // 0x8003B8E0: lhu         $v1, 0x10C($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X10C);
    // 0x8003B8E4: lhu         $a0, 0x10E($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X10E);
    // 0x8003B8E8: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8003B8EC: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
    // 0x8003B8F0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8003B8F4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003B8F8: slt         $v1, $v1, $t2
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003B8FC: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8003B900: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003B904: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B908: slt         $v0, $v0, $t1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8003B90C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8003B910: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8003B914: beq         $v1, $zero, L_8003B924
    if (ctx->r3 == 0) {
        // 0x8003B918: nop
    
            goto L_8003B924;
    }
    // 0x8003B918: nop

    // 0x8003B91C: j           L_8003B9A8
    // 0x8003B920: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003B9A8;
    // 0x8003B920: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003B924:
    // 0x8003B924: lhu         $v1, 0x110($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X110);
    // 0x8003B928: lhu         $a0, 0x112($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X112);
    // 0x8003B92C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8003B930: sra         $a2, $a1, 16
    ctx->r6 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8003B934: sll         $a1, $t5, 16
    ctx->r5 = S32(ctx->r13 << 16);
    // 0x8003B938: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8003B93C: subu        $v1, $v1, $t3
    ctx->r3 = SUB32(ctx->r3, ctx->r11);
    // 0x8003B940: subu        $a0, $a0, $t4
    ctx->r4 = SUB32(ctx->r4, ctx->r12);
    // 0x8003B944: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8003B948: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003B94C: slt         $v1, $a2, $v1
    ctx->r3 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B950: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8003B954: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8003B958: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003B95C: slt         $a0, $a1, $a0
    ctx->r4 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003B960: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
    // 0x8003B964: and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // 0x8003B968: beq         $v1, $zero, L_8003B9A8
    if (ctx->r3 == 0) {
        // 0x8003B96C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003B9A8;
    }
    // 0x8003B96C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003B970: lhu         $v1, 0x114($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X114);
    // 0x8003B974: lhu         $a0, 0x116($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X116);
    // 0x8003B978: addu        $v0, $v1, $t3
    ctx->r2 = ADD32(ctx->r3, ctx->r11);
    // 0x8003B97C: addu        $v1, $a0, $t4
    ctx->r3 = ADD32(ctx->r4, ctx->r12);
    // 0x8003B980: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003B984: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B988: slt         $v0, $v0, $a2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8003B98C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8003B990: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8003B994: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003B998: slt         $v1, $v1, $a1
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003B99C: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8003B9A0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8003B9A4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8003B9A8:
    // 0x8003B9A8: jr          $ra
    // 0x8003B9AC: nop

    return;
    // 0x8003B9AC: nop

;}
RECOMP_FUNC void func_8003B9B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B9B0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8003B9B4: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x8003B9B8: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8003B9BC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B9C0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003B9C4: beq         $v0, $zero, L_8003B9E0
    if (ctx->r2 == 0) {
        // 0x8003B9C8: addu        $a3, $a0, $zero
        ctx->r7 = ADD32(ctx->r4, 0);
            goto L_8003B9E0;
    }
    // 0x8003B9C8: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8003B9CC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003B9D0: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x8003B9D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003B9D8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B9DC: addu        $a3, $a0, $v0
    ctx->r7 = ADD32(ctx->r4, ctx->r2);
L_8003B9E0:
    // 0x8003B9E0: lhu         $v0, 0x108($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X108);
    // 0x8003B9E4: sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7 << 16);
    // 0x8003B9E8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003B9EC: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8003B9F0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003B9F4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003B9F8: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003B9FC: bne         $v0, $zero, L_8003BA1C
    if (ctx->r2 != 0) {
        // 0x8003BA00: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003BA1C;
    }
    // 0x8003BA00: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003BA04: lhu         $v0, 0x10C($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X10C);
    // 0x8003BA08: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8003BA0C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003BA10: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003BA14: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003BA18: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_8003BA1C:
    // 0x8003BA1C: jr          $ra
    // 0x8003BA20: nop

    return;
    // 0x8003BA20: nop

;}
RECOMP_FUNC void func_8003BA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BA24: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8003BA28: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x8003BA2C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8003BA30: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003BA34: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003BA38: beq         $v0, $zero, L_8003BA54
    if (ctx->r2 == 0) {
        // 0x8003BA3C: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_8003BA54;
    }
    // 0x8003BA3C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8003BA40: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003BA44: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x8003BA48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003BA4C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003BA50: addu        $a2, $a0, $v0
    ctx->r6 = ADD32(ctx->r4, ctx->r2);
L_8003BA54:
    // 0x8003BA54: lh          $v0, 0x108($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X108);
    // 0x8003BA58: sll         $v1, $a2, 16
    ctx->r3 = S32(ctx->r6 << 16);
    // 0x8003BA5C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003BA60: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003BA64: bne         $v0, $zero, L_8003BA78
    if (ctx->r2 != 0) {
        // 0x8003BA68: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003BA78;
    }
    // 0x8003BA68: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003BA6C: lh          $v0, 0x10C($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X10C);
    // 0x8003BA70: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003BA74: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_8003BA78:
    // 0x8003BA78: jr          $ra
    // 0x8003BA7C: nop

    return;
    // 0x8003BA7C: nop

;}
RECOMP_FUNC void func_8003BA80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BA80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BA84: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003BA88: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8003BA8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BA90: lhu         $v0, 0x140($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X140);
    // 0x8003BA94: bnel        $v0, $zero, L_8003BB40
    if (ctx->r2 != 0) {
        // 0x8003BA98: sra         $a0, $a0, 1
        ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
            goto L_8003BB40;
    }
    goto skip_0;
    // 0x8003BA98: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    skip_0:
    // 0x8003BA9C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8003BAA0: lhu         $v0, -0x1D0E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X1D0E);
    // 0x8003BAA4: sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x8003BAA8: beql        $v0, $zero, L_8003BB40
    if (ctx->r2 == 0) {
        // 0x8003BAAC: sra         $a0, $a0, 1
        ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
            goto L_8003BB40;
    }
    goto skip_1;
    // 0x8003BAAC: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    skip_1:
    // 0x8003BAB0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003BAB4: lh          $v0, -0x5AFC($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5AFC);
    // 0x8003BAB8: bnel        $v0, $zero, L_8003BB40
    if (ctx->r2 != 0) {
        // 0x8003BABC: sra         $a0, $a0, 1
        ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
            goto L_8003BB40;
    }
    goto skip_2;
    // 0x8003BABC: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    skip_2:
    // 0x8003BAC0: lhu         $v0, 0x5A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X5A);
    // 0x8003BAC4: addiu       $v0, $v0, -0x34
    ctx->r2 = ADD32(ctx->r2, -0X34);
    // 0x8003BAC8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8003BACC: bnel        $v0, $zero, L_8003BB30
    if (ctx->r2 != 0) {
        // 0x8003BAD0: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_8003BB30;
    }
    goto skip_3;
    // 0x8003BAD0: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    skip_3:
    // 0x8003BAD4: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8003BAD8: lw          $v0, -0x307C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X307C);
    // 0x8003BADC: bnel        $v0, $zero, L_8003BB2C
    if (ctx->r2 != 0) {
        // 0x8003BAE0: sll         $a0, $a0, 2
        ctx->r4 = S32(ctx->r4 << 2);
            goto L_8003BB2C;
    }
    goto skip_4;
    // 0x8003BAE0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    skip_4:
    // 0x8003BAE4: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x8003BAE8: slti        $v0, $v0, 0x78
    ctx->r2 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x8003BAEC: beq         $v0, $zero, L_8003BB2C
    if (ctx->r2 == 0) {
        // 0x8003BAF0: lui         $v0, 0x68DB
        ctx->r2 = S32(0X68DB << 16);
            goto L_8003BB2C;
    }
    // 0x8003BAF0: lui         $v0, 0x68DB
    ctx->r2 = S32(0X68DB << 16);
    // 0x8003BAF4: ori         $v0, $v0, 0x8BAD
    ctx->r2 = ctx->r2 | 0X8BAD;
    // 0x8003BAF8: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003BAFC: sra         $v0, $a0, 31
    ctx->r2 = S32(SIGNED(ctx->r4) >> 31);
    // 0x8003BB00: mfhi        $a2
    ctx->r6 = hi;
    // 0x8003BB04: nop

    // 0x8003BB08: nop

    // 0x8003BB0C: sra         $v1, $a2, 13
    ctx->r3 = S32(SIGNED(ctx->r6) >> 13);
    // 0x8003BB10: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // 0x8003BB14: slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8003BB18: beql        $v0, $zero, L_8003BB20
    if (ctx->r2 == 0) {
        // 0x8003BB1C: addiu       $a1, $zero, 0xF
        ctx->r5 = ADD32(0, 0XF);
            goto L_8003BB20;
    }
    goto skip_5;
    // 0x8003BB1C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    skip_5:
L_8003BB20:
    // 0x8003BB20: jal         0x80060F0C
    // 0x8003BB24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80060F0C(rdram, ctx);
        goto after_0;
    // 0x8003BB24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8003BB28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8003BB2C:
    // 0x8003BB2C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_8003BB30:
    // 0x8003BB30: jal         0x8003BB8C
    // 0x8003BB34: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003BB8C(rdram, ctx);
        goto after_1;
    // 0x8003BB34: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003BB38: j           L_8003BB78
    // 0x8003BB3C: nop

        goto L_8003BB78;
    // 0x8003BB3C: nop

L_8003BB40:
    // 0x8003BB40: lui         $v0, 0x68DB
    ctx->r2 = S32(0X68DB << 16);
    // 0x8003BB44: ori         $v0, $v0, 0x8BAD
    ctx->r2 = ctx->r2 | 0X8BAD;
    // 0x8003BB48: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003BB4C: sra         $v0, $a0, 31
    ctx->r2 = S32(SIGNED(ctx->r4) >> 31);
    // 0x8003BB50: mfhi        $a2
    ctx->r6 = hi;
    // 0x8003BB54: nop

    // 0x8003BB58: nop

    // 0x8003BB5C: sra         $v1, $a2, 13
    ctx->r3 = S32(SIGNED(ctx->r6) >> 13);
    // 0x8003BB60: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // 0x8003BB64: slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8003BB68: beql        $v0, $zero, L_8003BB70
    if (ctx->r2 == 0) {
        // 0x8003BB6C: addiu       $a1, $zero, 0xF
        ctx->r5 = ADD32(0, 0XF);
            goto L_8003BB70;
    }
    goto skip_6;
    // 0x8003BB6C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    skip_6:
L_8003BB70:
    // 0x8003BB70: jal         0x80060F0C
    // 0x8003BB74: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80060F0C(rdram, ctx);
        goto after_2;
    // 0x8003BB74: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_8003BB78:
    // 0x8003BB78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BB7C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003BB80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003BB84: jr          $ra
    // 0x8003BB88: nop

    return;
    // 0x8003BB88: nop

;}
RECOMP_FUNC void func_8003BB8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BB8C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8003BB90: lw          $v0, 0x57E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X57E0);
    // FALLTHROUGH: func_8003BB8C falls into func_8003BB94
    func_8003BB94(rdram, ctx);
;}
RECOMP_FUNC void func_8003BB94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BB94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BB98: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8003BB9C: andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // 0x8003BBA0: bne         $v0, $zero, L_8003BBF8
    if (ctx->r2 != 0) {
        // 0x8003BBA4: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8003BBF8;
    }
    // 0x8003BBA4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003BBA8: lw          $v0, 0xF0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XF0);
    // 0x8003BBAC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003BBB0: blez        $a0, L_8003BBBC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8003BBB4: sw          $v0, 0xF0($a2)
        MEM_W(0XF0, ctx->r6) = ctx->r2;
            goto L_8003BBBC;
    }
    // 0x8003BBB4: sw          $v0, 0xF0($a2)
    MEM_W(0XF0, ctx->r6) = ctx->r2;
    // 0x8003BBB8: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_8003BBBC:
    // 0x8003BBBC: lui         $v1, 0x68DB
    ctx->r3 = S32(0X68DB << 16);
    // 0x8003BBC0: ori         $v1, $v1, 0x8BAD
    ctx->r3 = ctx->r3 | 0X8BAD;
    // 0x8003BBC4: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
    // 0x8003BBC8: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003BBCC: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8003BBD0: mfhi        $a3
    ctx->r7 = hi;
    // 0x8003BBD4: nop

    // 0x8003BBD8: nop

    // 0x8003BBDC: sra         $v1, $a3, 13
    ctx->r3 = S32(SIGNED(ctx->r7) >> 13);
    // 0x8003BBE0: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // 0x8003BBE4: slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8003BBE8: beql        $v0, $zero, L_8003BBF0
    if (ctx->r2 == 0) {
        // 0x8003BBEC: addiu       $a1, $zero, 0xF
        ctx->r5 = ADD32(0, 0XF);
            goto L_8003BBF0;
    }
    goto skip_0;
    // 0x8003BBEC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    skip_0:
L_8003BBF0:
    // 0x8003BBF0: jal         0x80060F0C
    // 0x8003BBF4: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    func_80060F0C(rdram, ctx);
        goto after_0;
    // 0x8003BBF4: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    after_0:
L_8003BBF8:
    // 0x8003BBF8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003BBFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003BC00: jr          $ra
    // 0x8003BC04: nop

    return;
    // 0x8003BC04: nop

;}
RECOMP_FUNC void func_8003BC08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BC08: jr          $ra
    // 0x8003BC0C: nop

    return;
    // 0x8003BC0C: nop

;}
RECOMP_FUNC void func_8003BC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BC10: lhu         $v0, 0x18E($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X18E);
    // 0x8003BC14: bne         $v0, $zero, L_8003BC80
    if (ctx->r2 != 0) {
        // 0x8003BC18: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003BC80;
    }
    // 0x8003BC18: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003BC1C: lhu         $v1, 0x5A($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X5A);
    // 0x8003BC20: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    // 0x8003BC24: bne         $v1, $v0, L_8003BC80
    if (ctx->r3 != ctx->r2) {
        // 0x8003BC28: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003BC80;
    }
    // 0x8003BC28: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003BC2C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003BC30: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003BC34: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x8003BC38: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8003BC3C: beq         $v0, $zero, L_8003BC50
    if (ctx->r2 == 0) {
        // 0x8003BC40: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8003BC50;
    }
    // 0x8003BC40: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8003BC44: lhu         $v1, 0xCC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XCC);
    // 0x8003BC48: j           L_8003BC58
    // 0x8003BC4C: nop

        goto L_8003BC58;
    // 0x8003BC4C: nop

L_8003BC50:
    // 0x8003BC50: lhu         $v1, 0xCC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XCC);
    // 0x8003BC54: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_8003BC58:
    // 0x8003BC58: bne         $v1, $v0, L_8003BC80
    if (ctx->r3 != ctx->r2) {
        // 0x8003BC5C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003BC80;
    }
    // 0x8003BC5C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003BC60: lhu         $v0, 0xD0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XD0);
    // 0x8003BC64: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8003BC68: bne         $v0, $zero, L_8003BC78
    if (ctx->r2 != 0) {
        // 0x8003BC6C: addiu       $v0, $zero, 0x32
        ctx->r2 = ADD32(0, 0X32);
            goto L_8003BC78;
    }
    // 0x8003BC6C: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // 0x8003BC70: j           L_8003BC80
    // 0x8003BC74: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8003BC80;
    // 0x8003BC74: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003BC78:
    // 0x8003BC78: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
    // 0x8003BC7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003BC80:
    // 0x8003BC80: jr          $ra
    // 0x8003BC84: nop

    return;
    // 0x8003BC84: nop

;}
RECOMP_FUNC void func_8003BC88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BC88: jr          $ra
    // 0x8003BC8C: nop

    return;
    // 0x8003BC8C: nop

;}
RECOMP_FUNC void func_8003BC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BC90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003BC94: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003BC98: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8003BC9C: lw          $s0, 0x31C0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X31C0);
    // 0x8003BCA0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8003BCA4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8003BCA8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003BCAC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003BCB0: lhu         $v0, 0x6C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6C);
    // 0x8003BCB4: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8003BCB8: beq         $v0, $zero, L_8003BCD0
    if (ctx->r2 == 0) {
        // 0x8003BCBC: lui         $a1, 0x2
        ctx->r5 = S32(0X2 << 16);
            goto L_8003BCD0;
    }
    // 0x8003BCBC: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // 0x8003BCC0: jal         0x80024764
    // 0x8003BCC4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80024764(rdram, ctx);
        goto after_0;
    // 0x8003BCC4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8003BCC8: j           L_8003BDAC
    // 0x8003BCCC: nop

        goto L_8003BDAC;
    // 0x8003BCCC: nop

L_8003BCD0:
    // 0x8003BCD0: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x8003BCD4: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8003BCD8: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x8003BCDC: ori         $a1, $a1, 0x8
    ctx->r5 = ctx->r5 | 0X8;
    // 0x8003BCE0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003BCE4: addiu       $v1, $v1, 0x1800
    ctx->r3 = ADD32(ctx->r3, 0X1800);
    // 0x8003BCE8: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // 0x8003BCEC: slt         $v1, $a1, $v1
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003BCF0: bne         $v1, $zero, L_8003BCFC
    if (ctx->r3 != 0) {
        // 0x8003BCF4: sw          $v0, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r2;
            goto L_8003BCFC;
    }
    // 0x8003BCF4: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8003BCF8: sw          $a1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r5;
L_8003BCFC:
    // 0x8003BCFC: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x8003BD00: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x8003BD04: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003BD08: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8003BD0C: lh          $v0, 0x18($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18);
    // 0x8003BD10: slti        $v0, $v0, 0x100
    ctx->r2 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x8003BD14: bne         $v0, $zero, L_8003BD40
    if (ctx->r2 != 0) {
        // 0x8003BD18: addiu       $s2, $zero, 0x7
        ctx->r18 = ADD32(0, 0X7);
            goto L_8003BD40;
    }
    // 0x8003BD18: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
    // 0x8003BD1C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8003BD20: addiu       $v0, $v0, 0xEE0
    ctx->r2 = ADD32(ctx->r2, 0XEE0);
    // 0x8003BD24: j           L_8003BDAC
    // 0x8003BD28: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
        goto L_8003BDAC;
    // 0x8003BD28: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
L_8003BD2C:
    // 0x8003BD2C: sh          $v0, 0x5A($s1)
    MEM_H(0X5A, ctx->r17) = ctx->r2;
    // 0x8003BD30: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8003BD34: addiu       $v0, $v0, 0xEF0
    ctx->r2 = ADD32(ctx->r2, 0XEF0);
    // 0x8003BD38: j           L_8003BDAC
    // 0x8003BD3C: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
        goto L_8003BDAC;
    // 0x8003BD3C: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
L_8003BD40:
    // 0x8003BD40: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x8003BD44: addiu       $s3, $s3, 0x3F94
    ctx->r19 = ADD32(ctx->r19, 0X3F94);
L_8003BD48:
    // 0x8003BD48: lw          $v0, 0x9C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9C);
    // 0x8003BD4C: andi        $v1, $s2, 0xFFFF
    ctx->r3 = ctx->r18 & 0XFFFF;
    // 0x8003BD50: beq         $v1, $v0, L_8003BD98
    if (ctx->r3 == ctx->r2) {
        // 0x8003BD54: sll         $v0, $v1, 4
        ctx->r2 = S32(ctx->r3 << 4);
            goto L_8003BD98;
    }
    // 0x8003BD54: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8003BD58: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003BD5C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003BD60: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8003BD64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003BD68: addu        $s1, $v0, $s3
    ctx->r17 = ADD32(ctx->r2, ctx->r19);
    // 0x8003BD6C: lhu         $v0, 0x58($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X58);
    // 0x8003BD70: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8003BD74: beq         $v0, $zero, L_8003BD9C
    if (ctx->r2 == 0) {
        // 0x8003BD78: addiu       $v0, $s2, -0x1
        ctx->r2 = ADD32(ctx->r18, -0X1);
            goto L_8003BD9C;
    }
    // 0x8003BD78: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x8003BD7C: lh          $a0, 0x14($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X14);
    // 0x8003BD80: lh          $a1, 0x18($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X18);
    // 0x8003BD84: jal         0x8003B4A4
    // 0x8003BD88: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003B4A4(rdram, ctx);
        goto after_1;
    // 0x8003BD88: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8003BD8C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003BD90: bne         $v0, $zero, L_8003BD2C
    if (ctx->r2 != 0) {
        // 0x8003BD94: addiu       $v0, $zero, 0x2B
        ctx->r2 = ADD32(0, 0X2B);
            goto L_8003BD2C;
    }
    // 0x8003BD94: addiu       $v0, $zero, 0x2B
    ctx->r2 = ADD32(0, 0X2B);
L_8003BD98:
    // 0x8003BD98: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
L_8003BD9C:
    // 0x8003BD9C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8003BDA0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003BDA4: bne         $v0, $zero, L_8003BD48
    if (ctx->r2 != 0) {
        // 0x8003BDA8: nop
    
            goto L_8003BD48;
    }
    // 0x8003BDA8: nop

L_8003BDAC:
    // 0x8003BDAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003BDB0: sw          $s0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r16;
    // 0x8003BDB4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8003BDB8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BDBC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003BDC0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003BDC4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003BDC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003BDCC: jr          $ra
    // 0x8003BDD0: nop

    return;
    // 0x8003BDD0: nop

;}
RECOMP_FUNC void func_8003BDD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BDD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003BDD8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003BDDC: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8003BDE0: lw          $s0, 0x31C0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X31C0);
    // 0x8003BDE4: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x8003BDE8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8003BDEC: jal         0x8004C79C
    // 0x8003BDF0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_8004C79C(rdram, ctx);
        goto after_0;
    // 0x8003BDF0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x8003BDF4: lw          $v0, 0x90($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X90);
    // 0x8003BDF8: lw          $s0, 0x68($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X68);
    // 0x8003BDFC: lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X22);
    // 0x8003BE00: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8003BE04: beq         $v0, $zero, L_8003BE1C
    if (ctx->r2 == 0) {
        // 0x8003BE08: nop
    
            goto L_8003BE1C;
    }
    // 0x8003BE08: nop

    // 0x8003BE0C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8003BE10: lhu         $s1, -0x2074($s1)
    ctx->r17 = MEM_HU(ctx->r17, -0X2074);
    // 0x8003BE14: j           L_8003BE24
    // 0x8003BE18: nop

        goto L_8003BE24;
    // 0x8003BE18: nop

L_8003BE1C:
    // 0x8003BE1C: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8003BE20: lhu         $s1, 0x3EF4($s1)
    ctx->r17 = MEM_HU(ctx->r17, 0X3EF4);
L_8003BE24:
    // 0x8003BE24: jal         0x800306EC
    // 0x8003BE28: nop

    func_800306EC(rdram, ctx);
        goto after_1;
    // 0x8003BE28: nop

    after_1:
    // 0x8003BE2C: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x8003BE30: ori         $a0, $a0, 0x35C2
    ctx->r4 = ctx->r4 | 0X35C2;
    // 0x8003BE34: addiu       $v1, $zero, 0x738
    ctx->r3 = ADD32(0, 0X738);
    // 0x8003BE38: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x8003BE3C: addiu       $v1, $zero, 0x4000
    ctx->r3 = ADD32(0, 0X4000);
    // 0x8003BE40: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x8003BE44: addiu       $v1, $zero, 0xED
    ctx->r3 = ADD32(0, 0XED);
    // 0x8003BE48: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x8003BE4C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8003BE50: addiu       $v1, $v1, 0xF50
    ctx->r3 = ADD32(ctx->r3, 0XF50);
    // 0x8003BE54: sh          $s1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r17;
    // 0x8003BE58: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8003BE5C: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x8003BE60: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003BE64: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x8003BE68: jal         0x80023E44
    // 0x8003BE6C: nop

    func_80023E44(rdram, ctx);
        goto after_2;
    // 0x8003BE6C: nop

    after_2:
    // 0x8003BE70: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003BE74: sw          $s0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r16;
    // 0x8003BE78: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8003BE7C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003BE80: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003BE84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003BE88: jr          $ra
    // 0x8003BE8C: nop

    return;
    // 0x8003BE8C: nop

;}
RECOMP_FUNC void func_8003BE90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BE90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003BE94: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003BE98: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8003BE9C: lw          $s0, 0x31C0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X31C0);
    // 0x8003BEA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003BEA4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8003BEA8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8003BEAC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003BEB0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003BEB4: lhu         $s2, 0x18($s0)
    ctx->r18 = MEM_HU(ctx->r16, 0X18);
    // 0x8003BEB8: lw          $s4, 0x90($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X90);
    // 0x8003BEBC: lhu         $s1, 0x14($s0)
    ctx->r17 = MEM_HU(ctx->r16, 0X14);
    // 0x8003BEC0: jal         0x8004C79C
    // 0x8003BEC4: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    func_8004C79C(rdram, ctx);
        goto after_0;
    // 0x8003BEC4: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    after_0:
    // 0x8003BEC8: lhu         $v0, 0x1B0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X1B0);
    // 0x8003BECC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8003BED0: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8003BED4: beq         $v0, $zero, L_8003BF0C
    if (ctx->r2 == 0) {
        // 0x8003BED8: sll         $v0, $s1, 16
        ctx->r2 = S32(ctx->r17 << 16);
            goto L_8003BF0C;
    }
    // 0x8003BED8: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x8003BEDC: lhu         $v1, 0x22($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X22);
    // 0x8003BEE0: addiu       $s2, $s2, -0x13
    ctx->r18 = ADD32(ctx->r18, -0X13);
    // 0x8003BEE4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003BEE8: andi        $v1, $v1, 0x10
    ctx->r3 = ctx->r3 & 0X10;
    // 0x8003BEEC: bne         $v1, $zero, L_8003BEFC
    if (ctx->r3 != 0) {
        // 0x8003BEF0: addu        $s3, $v1, $zero
        ctx->r19 = ADD32(ctx->r3, 0);
            goto L_8003BEFC;
    }
    // 0x8003BEF0: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // 0x8003BEF4: j           L_8003BF00
    // 0x8003BEF8: addiu       $s1, $v0, -0x6
    ctx->r17 = ADD32(ctx->r2, -0X6);
        goto L_8003BF00;
    // 0x8003BEF8: addiu       $s1, $v0, -0x6
    ctx->r17 = ADD32(ctx->r2, -0X6);
L_8003BEFC:
    // 0x8003BEFC: addiu       $s1, $v0, 0x6
    ctx->r17 = ADD32(ctx->r2, 0X6);
L_8003BF00:
    // 0x8003BF00: sltiu       $v0, $s3, 0x1
    ctx->r2 = ctx->r19 < 0X1 ? 1 : 0;
    // 0x8003BF04: j           L_8003BF30
    // 0x8003BF08: sll         $s3, $v0, 4
    ctx->r19 = S32(ctx->r2 << 4);
        goto L_8003BF30;
    // 0x8003BF08: sll         $s3, $v0, 4
    ctx->r19 = S32(ctx->r2 << 4);
L_8003BF0C:
    // 0x8003BF0C: lhu         $v1, 0x22($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X22);
    // 0x8003BF10: addiu       $s2, $s2, -0x20
    ctx->r18 = ADD32(ctx->r18, -0X20);
    // 0x8003BF14: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003BF18: andi        $v1, $v1, 0x10
    ctx->r3 = ctx->r3 & 0X10;
    // 0x8003BF1C: beq         $v1, $zero, L_8003BF2C
    if (ctx->r3 == 0) {
        // 0x8003BF20: addu        $s3, $v1, $zero
        ctx->r19 = ADD32(ctx->r3, 0);
            goto L_8003BF2C;
    }
    // 0x8003BF20: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // 0x8003BF24: j           L_8003BF30
    // 0x8003BF28: addiu       $s1, $v0, -0x31
    ctx->r17 = ADD32(ctx->r2, -0X31);
        goto L_8003BF30;
    // 0x8003BF28: addiu       $s1, $v0, -0x31
    ctx->r17 = ADD32(ctx->r2, -0X31);
L_8003BF2C:
    // 0x8003BF2C: addiu       $s1, $v0, 0x31
    ctx->r17 = ADD32(ctx->r2, 0X31);
L_8003BF30:
    // 0x8003BF30: jal         0x800306EC
    // 0x8003BF34: nop

    func_800306EC(rdram, ctx);
        goto after_1;
    // 0x8003BF34: nop

    after_1:
    // 0x8003BF38: lui         $a0, 0x4F00
    ctx->r4 = S32(0X4F00 << 16);
    // 0x8003BF3C: ori         $a0, $a0, 0xB2
    ctx->r4 = ctx->r4 | 0XB2;
    // 0x8003BF40: addiu       $v1, $zero, 0x739
    ctx->r3 = ADD32(0, 0X739);
    // 0x8003BF44: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003BF48: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x8003BF4C: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x8003BF50: addiu       $v1, $zero, 0x1100
    ctx->r3 = ADD32(0, 0X1100);
    // 0x8003BF54: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x8003BF58: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8003BF5C: addiu       $v1, $v1, -0x7E80
    ctx->r3 = ADD32(ctx->r3, -0X7E80);
    // 0x8003BF60: sh          $s2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r18;
    // 0x8003BF64: sh          $s1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r17;
    // 0x8003BF68: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8003BF6C: jal         0x80023E44
    // 0x8003BF70: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_2;
    // 0x8003BF70: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    after_2:
    // 0x8003BF74: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8003BF78: lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X22);
    // 0x8003BF7C: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x8003BF80: sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    // 0x8003BF84: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x8003BF88: sw          $v0, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->r2;
    // 0x8003BF8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003BF90: sw          $s0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r16;
    // 0x8003BF94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003BF98: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8003BF9C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BFA0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003BFA4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003BFA8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003BFAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003BFB0: jr          $ra
    // 0x8003BFB4: nop

    return;
    // 0x8003BFB4: nop

;}
RECOMP_FUNC void func_8003BFB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BFB8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003BFBC: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003BFC0: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8003BFC4: addiu       $a0, $v0, 0x3000
    ctx->r4 = ADD32(ctx->r2, 0X3000);
    // 0x8003BFC8: lui         $v0, 0x6
    ctx->r2 = S32(0X6 << 16);
    // 0x8003BFCC: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003BFD0: bnel        $v0, $zero, L_8003BFD8
    if (ctx->r2 != 0) {
        // 0x8003BFD4: lui         $a0, 0x6
        ctx->r4 = S32(0X6 << 16);
            goto L_8003BFD8;
    }
    goto skip_0;
    // 0x8003BFD4: lui         $a0, 0x6
    ctx->r4 = S32(0X6 << 16);
    skip_0:
L_8003BFD8:
    // 0x8003BFD8: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x8003BFDC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003BFE0: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x8003BFE4: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
    // 0x8003BFE8: slti        $v0, $v0, 0xC0
    ctx->r2 = SIGNED(ctx->r2) < 0XC0 ? 1 : 0;
    // 0x8003BFEC: bne         $v0, $zero, L_8003C000
    if (ctx->r2 != 0) {
        // 0x8003BFF0: sw          $a0, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->r4;
            goto L_8003C000;
    }
    // 0x8003BFF0: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    // 0x8003BFF4: addiu       $v0, $zero, 0x319
    ctx->r2 = ADD32(0, 0X319);
    // 0x8003BFF8: j           L_8003C00C
    // 0x8003BFFC: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
        goto L_8003C00C;
    // 0x8003BFFC: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
L_8003C000:
    // 0x8003C000: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x8003C004: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003C008: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
L_8003C00C:
    // 0x8003C00C: jr          $ra
    // 0x8003C010: nop

    return;
    // 0x8003C010: nop

;}
RECOMP_FUNC void func_8003C014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C014: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003C018: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003C01C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003C020: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8003C024: addiu       $s1, $s1, 0x31C0
    ctx->r17 = ADD32(ctx->r17, 0X31C0);
    // 0x8003C028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003C02C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003C030: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8003C034: jal         0x800306EC
    // 0x8003C038: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x8003C038: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8003C03C: addiu       $v1, $zero, 0x743
    ctx->r3 = ADD32(0, 0X743);
    // 0x8003C040: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003C044: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x8003C048: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x8003C04C: addiu       $v1, $zero, 0x4000
    ctx->r3 = ADD32(0, 0X4000);
    // 0x8003C050: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x8003C054: lhu         $v1, 0x120($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X120);
    // 0x8003C058: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x8003C05C: lhu         $a0, 0x122($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X122);
    // 0x8003C060: lui         $v1, 0x4F00
    ctx->r3 = S32(0X4F00 << 16);
    // 0x8003C064: ori         $v1, $v1, 0x52
    ctx->r3 = ctx->r3 | 0X52;
    // 0x8003C068: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8003C06C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8003C070: addiu       $v1, $v1, 0x4764
    ctx->r3 = ADD32(ctx->r3, 0X4764);
    // 0x8003C074: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x8003C078: jal         0x80023E44
    // 0x8003C07C: sh          $a0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r4;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x8003C07C: sh          $a0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r4;
    after_1:
    // 0x8003C080: sw          $s2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r18;
    // 0x8003C084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C088: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003C08C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003C090: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003C094: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003C098: jr          $ra
    // 0x8003C09C: nop

    return;
    // 0x8003C09C: nop

;}
RECOMP_FUNC void func_8003C0A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C0A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003C0A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003C0A8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003C0AC: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8003C0B0: addiu       $s1, $s1, 0x31C0
    ctx->r17 = ADD32(ctx->r17, 0X31C0);
    // 0x8003C0B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003C0B8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003C0BC: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8003C0C0: jal         0x800012DC
    // 0x8003C0C4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_800012DC(rdram, ctx);
        goto after_0;
    // 0x8003C0C4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8003C0C8: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8003C0CC: jal         0x8004C79C
    // 0x8003C0D0: addiu       $a0, $v0, 0x21
    ctx->r4 = ADD32(ctx->r2, 0X21);
    func_8004C79C(rdram, ctx);
        goto after_1;
    // 0x8003C0D0: addiu       $a0, $v0, 0x21
    ctx->r4 = ADD32(ctx->r2, 0X21);
    after_1:
    // 0x8003C0D4: jal         0x800012DC
    // 0x8003C0D8: nop

    func_800012DC(rdram, ctx);
        goto after_2;
    // 0x8003C0D8: nop

    after_2:
    // 0x8003C0DC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8003C0E0: jal         0x8004C79C
    // 0x8003C0E4: addiu       $a0, $v0, 0x1F
    ctx->r4 = ADD32(ctx->r2, 0X1F);
    func_8004C79C(rdram, ctx);
        goto after_3;
    // 0x8003C0E4: addiu       $a0, $v0, 0x1F
    ctx->r4 = ADD32(ctx->r2, 0X1F);
    after_3:
    // 0x8003C0E8: jal         0x800306EC
    // 0x8003C0EC: nop

    func_800306EC(rdram, ctx);
        goto after_4;
    // 0x8003C0EC: nop

    after_4:
    // 0x8003C0F0: addiu       $v1, $zero, 0x741
    ctx->r3 = ADD32(0, 0X741);
    // 0x8003C0F4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003C0F8: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x8003C0FC: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x8003C100: addiu       $v1, $zero, 0x4000
    ctx->r3 = ADD32(0, 0X4000);
    // 0x8003C104: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x8003C108: lhu         $v1, 0x120($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X120);
    // 0x8003C10C: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x8003C110: lhu         $a0, 0x122($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X122);
    // 0x8003C114: lui         $v1, 0x4F00
    ctx->r3 = S32(0X4F00 << 16);
    // 0x8003C118: ori         $v1, $v1, 0x66
    ctx->r3 = ctx->r3 | 0X66;
    // 0x8003C11C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8003C120: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8003C124: addiu       $v1, $v1, 0xF28
    ctx->r3 = ADD32(ctx->r3, 0XF28);
    // 0x8003C128: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x8003C12C: jal         0x80023E44
    // 0x8003C130: sh          $a0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r4;
    func_80023E44(rdram, ctx);
        goto after_5;
    // 0x8003C130: sh          $a0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r4;
    after_5:
    // 0x8003C134: sw          $s2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r18;
    // 0x8003C138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C13C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003C140: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003C144: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003C148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003C14C: jr          $ra
    // 0x8003C150: nop

    return;
    // 0x8003C150: nop

;}
RECOMP_FUNC void func_8003C154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C154: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003C158: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003C15C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003C160: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8003C164: addiu       $s1, $s1, 0x31C0
    ctx->r17 = ADD32(ctx->r17, 0X31C0);
    // 0x8003C168: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003C16C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003C170: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8003C174: jal         0x800012DC
    // 0x8003C178: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_800012DC(rdram, ctx);
        goto after_0;
    // 0x8003C178: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8003C17C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8003C180: jal         0x8004C79C
    // 0x8003C184: addiu       $a0, $v0, 0x25
    ctx->r4 = ADD32(ctx->r2, 0X25);
    func_8004C79C(rdram, ctx);
        goto after_1;
    // 0x8003C184: addiu       $a0, $v0, 0x25
    ctx->r4 = ADD32(ctx->r2, 0X25);
    after_1:
    // 0x8003C188: jal         0x8004C79C
    // 0x8003C18C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_8004C79C(rdram, ctx);
        goto after_2;
    // 0x8003C18C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_2:
    // 0x8003C190: jal         0x800306EC
    // 0x8003C194: nop

    func_800306EC(rdram, ctx);
        goto after_3;
    // 0x8003C194: nop

    after_3:
    // 0x8003C198: addiu       $v1, $zero, 0x742
    ctx->r3 = ADD32(0, 0X742);
    // 0x8003C19C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003C1A0: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x8003C1A4: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x8003C1A8: addiu       $v1, $zero, 0x4000
    ctx->r3 = ADD32(0, 0X4000);
    // 0x8003C1AC: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x8003C1B0: lhu         $v1, 0x120($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X120);
    // 0x8003C1B4: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x8003C1B8: lhu         $a0, 0x122($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X122);
    // 0x8003C1BC: lui         $v1, 0x4F00
    ctx->r3 = S32(0X4F00 << 16);
    // 0x8003C1C0: ori         $v1, $v1, 0x60
    ctx->r3 = ctx->r3 | 0X60;
    // 0x8003C1C4: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8003C1C8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8003C1CC: addiu       $v1, $v1, 0xF00
    ctx->r3 = ADD32(ctx->r3, 0XF00);
    // 0x8003C1D0: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x8003C1D4: jal         0x80023E44
    // 0x8003C1D8: sh          $a0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r4;
    func_80023E44(rdram, ctx);
        goto after_4;
    // 0x8003C1D8: sh          $a0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r4;
    after_4:
    // 0x8003C1DC: sw          $s2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r18;
    // 0x8003C1E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C1E4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003C1E8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003C1EC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003C1F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003C1F4: jr          $ra
    // 0x8003C1F8: nop

    return;
    // 0x8003C1F8: nop

;}
RECOMP_FUNC void func_8003C1FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C1FC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003C200: lhu         $v0, -0x7502($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7502);
    // FALLTHROUGH: func_8003C1FC falls into func_8003C204
    func_8003C204(rdram, ctx);
;}
RECOMP_FUNC void func_8003C204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003C208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003C20C: beq         $v0, $zero, L_8003C338
    if (ctx->r2 == 0) {
        // 0x8003C210: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8003C338;
    }
    // 0x8003C210: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003C214: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003C218: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003C21C: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8003C220: lui         $v0, 0x58
    ctx->r2 = S32(0X58 << 16);
    // 0x8003C224: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003C228: beq         $v0, $zero, L_8003C338
    if (ctx->r2 == 0) {
        // 0x8003C22C: addiu       $a3, $zero, 0x7
        ctx->r7 = ADD32(0, 0X7);
            goto L_8003C338;
    }
    // 0x8003C22C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
L_8003C230:
    // 0x8003C230: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8003C234: andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // 0x8003C238: beq         $v0, $v1, L_8003C324
    if (ctx->r2 == ctx->r3) {
        // 0x8003C23C: sll         $v0, $v1, 4
        ctx->r2 = S32(ctx->r3 << 4);
            goto L_8003C324;
    }
    // 0x8003C23C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8003C240: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003C244: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003C248: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8003C24C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003C250: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8003C254: addiu       $v1, $v1, 0x3F94
    ctx->r3 = ADD32(ctx->r3, 0X3F94);
    // 0x8003C258: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x8003C25C: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
    // 0x8003C260: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8003C264: beq         $v0, $zero, L_8003C328
    if (ctx->r2 == 0) {
        // 0x8003C268: addiu       $v0, $a3, -0x1
        ctx->r2 = ADD32(ctx->r7, -0X1);
            goto L_8003C328;
    }
    // 0x8003C268: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // 0x8003C26C: lhu         $v0, 0xDC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XDC);
    // 0x8003C270: beq         $v0, $zero, L_8003C324
    if (ctx->r2 == 0) {
        // 0x8003C274: addiu       $v0, $zero, 0x37
        ctx->r2 = ADD32(0, 0X37);
            goto L_8003C324;
    }
    // 0x8003C274: addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
    // 0x8003C278: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x8003C27C: beq         $v1, $v0, L_8003C328
    if (ctx->r3 == ctx->r2) {
        // 0x8003C280: addiu       $v0, $a3, -0x1
        ctx->r2 = ADD32(ctx->r7, -0X1);
            goto L_8003C328;
    }
    // 0x8003C280: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // 0x8003C284: lhu         $v0, 0x1B0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B0);
    // 0x8003C288: bne         $v0, $zero, L_8003C328
    if (ctx->r2 != 0) {
        // 0x8003C28C: addiu       $v0, $a3, -0x1
        ctx->r2 = ADD32(ctx->r7, -0X1);
            goto L_8003C328;
    }
    // 0x8003C28C: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // 0x8003C290: lw          $a2, 0x68($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X68);
    // 0x8003C294: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003C298: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003C29C: lh          $a1, 0x14($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X14);
    // 0x8003C2A0: lh          $v1, 0x14($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X14);
    // 0x8003C2A4: subu        $v0, $a1, $v1
    ctx->r2 = SUB32(ctx->r5, ctx->r3);
    // 0x8003C2A8: bltz        $v0, L_8003C2C0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8003C2AC: slti        $v0, $v0, 0x13
        ctx->r2 = SIGNED(ctx->r2) < 0X13 ? 1 : 0;
            goto L_8003C2C0;
    }
    // 0x8003C2AC: slti        $v0, $v0, 0x13
    ctx->r2 = SIGNED(ctx->r2) < 0X13 ? 1 : 0;
    // 0x8003C2B0: bne         $v0, $zero, L_8003C2D0
    if (ctx->r2 != 0) {
        // 0x8003C2B4: addiu       $v0, $a3, -0x1
        ctx->r2 = ADD32(ctx->r7, -0X1);
            goto L_8003C2D0;
    }
    // 0x8003C2B4: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // 0x8003C2B8: j           L_8003C328
    // 0x8003C2BC: nop

        goto L_8003C328;
    // 0x8003C2BC: nop

L_8003C2C0:
    // 0x8003C2C0: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // 0x8003C2C4: slti        $v0, $v0, 0x13
    ctx->r2 = SIGNED(ctx->r2) < 0X13 ? 1 : 0;
    // 0x8003C2C8: beq         $v0, $zero, L_8003C328
    if (ctx->r2 == 0) {
        // 0x8003C2CC: addiu       $v0, $a3, -0x1
        ctx->r2 = ADD32(ctx->r7, -0X1);
            goto L_8003C328;
    }
    // 0x8003C2CC: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
L_8003C2D0:
    // 0x8003C2D0: lh          $v1, 0x18($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X18);
    // 0x8003C2D4: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x8003C2D8: bne         $v1, $v0, L_8003C328
    if (ctx->r3 != ctx->r2) {
        // 0x8003C2DC: addiu       $v0, $a3, -0x1
        ctx->r2 = ADD32(ctx->r7, -0X1);
            goto L_8003C328;
    }
    // 0x8003C2DC: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // 0x8003C2E0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8003C2E4: lh          $v0, 0x13E6($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X13E6);
    // 0x8003C2E8: beq         $v0, $zero, L_8003C2FC
    if (ctx->r2 == 0) {
        // 0x8003C2EC: sw          $a0, 0x180($s0)
        MEM_W(0X180, ctx->r16) = ctx->r4;
            goto L_8003C2FC;
    }
    // 0x8003C2EC: sw          $a0, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->r4;
    // 0x8003C2F0: lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // 0x8003C2F4: jal         0x8003BA80
    // 0x8003C2F8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003BA80(rdram, ctx);
        goto after_0;
    // 0x8003C2F8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
L_8003C2FC:
    // 0x8003C2FC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003C300: jal         0x80060F30
    // 0x8003C304: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80060F30(rdram, ctx);
        goto after_1;
    // 0x8003C304: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x8003C308: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x8003C30C: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x8003C310: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003C314: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003C318: lui         $v0, 0xFFFB
    ctx->r2 = S32(0XFFFB << 16);
    // 0x8003C31C: j           L_8003C338
    // 0x8003C320: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
        goto L_8003C338;
    // 0x8003C320: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
L_8003C324:
    // 0x8003C324: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
L_8003C328:
    // 0x8003C328: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x8003C32C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003C330: bne         $v0, $zero, L_8003C230
    if (ctx->r2 != 0) {
        // 0x8003C334: nop
    
            goto L_8003C230;
    }
    // 0x8003C334: nop

L_8003C338:
    // 0x8003C338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003C33C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003C340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003C344: jr          $ra
    // 0x8003C348: nop

    return;
    // 0x8003C348: nop

;}
RECOMP_FUNC void func_8003C34C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C34C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003C350: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003C354: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x8003C358: beq         $v0, $zero, L_8003C3B8
    if (ctx->r2 == 0) {
        // 0x8003C35C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8003C3B8;
    }
    // 0x8003C35C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8003C360: ori         $a3, $zero, 0xC350
    ctx->r7 = 0 | 0XC350;
    // 0x8003C364: lw          $t0, 0x38($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X38);
    // 0x8003C368: ori         $v1, $zero, 0xC350
    ctx->r3 = 0 | 0XC350;
    // 0x8003C36C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8003C370: addu        $v0, $t0, $a0
    ctx->r2 = ADD32(ctx->r8, ctx->r4);
    // 0x8003C374: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8003C378: sw          $a0, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->r4;
L_8003C37C:
    // 0x8003C37C: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003C380: bne         $v0, $zero, L_8003C3B8
    if (ctx->r2 != 0) {
        // 0x8003C384: slt         $v0, $t0, $v1
        ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8003C3B8;
    }
    // 0x8003C384: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003C388: bnel        $v0, $zero, L_8003C3A8
    if (ctx->r2 != 0) {
        // 0x8003C38C: addiu       $a0, $zero, 0x82
        ctx->r4 = ADD32(0, 0X82);
            goto L_8003C3A8;
    }
    goto skip_0;
    // 0x8003C38C: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    skip_0:
    // 0x8003C390: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8003C394: bne         $a2, $t1, L_8003C37C
    if (ctx->r6 != ctx->r9) {
        // 0x8003C398: addu        $v1, $v1, $a3
        ctx->r3 = ADD32(ctx->r3, ctx->r7);
            goto L_8003C37C;
    }
    // 0x8003C398: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x8003C39C: addiu       $a3, $a3, 0x61A8
    ctx->r7 = ADD32(ctx->r7, 0X61A8);
    // 0x8003C3A0: j           L_8003C37C
    // 0x8003C3A4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
        goto L_8003C37C;
    // 0x8003C3A4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8003C3A8:
    // 0x8003C3A8: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x8003C3AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003C3B0: jal         0x8004C79C
    // 0x8003C3B4: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    func_8004C79C(rdram, ctx);
        goto after_0;
    // 0x8003C3B4: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    after_0:
L_8003C3B8:
    // 0x8003C3B8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003C3BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003C3C0: jr          $ra
    // 0x8003C3C4: nop

    return;
    // 0x8003C3C4: nop

;}
RECOMP_FUNC void func_8003C3C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C3C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003C3CC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003C3D0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8003C3D4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8003C3D8: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x8003C3DC: addiu       $s3, $s3, 0x3F94
    ctx->r19 = ADD32(ctx->r19, 0X3F94);
    // 0x8003C3E0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003C3E4: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x8003C3E8: addiu       $s2, $s2, -0x1034
    ctx->r18 = ADD32(ctx->r18, -0X1034);
    // 0x8003C3EC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003C3F0: addiu       $s1, $zero, -0x2
    ctx->r17 = ADD32(0, -0X2);
    // 0x8003C3F4: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
L_8003C3F8:
    // 0x8003C3F8: jal         0x8001F310
    // 0x8003C3FC: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    func_8001F310(rdram, ctx);
        goto after_0;
    // 0x8003C3FC: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_0:
    // 0x8003C400: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8003C404: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003C408: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8003C40C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8003C410: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8003C414: addu        $a0, $v1, $s3
    ctx->r4 = ADD32(ctx->r3, ctx->r19);
    // 0x8003C418: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8003C41C: beq         $v0, $zero, L_8003C48C
    if (ctx->r2 == 0) {
        // 0x8003C420: sw          $zero, 0x68($a0)
        MEM_W(0X68, ctx->r4) = 0;
            goto L_8003C48C;
    }
    // 0x8003C420: sw          $zero, 0x68($a0)
    MEM_W(0X68, ctx->r4) = 0;
    // 0x8003C424: lhu         $v0, 0x5A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X5A);
    // 0x8003C428: xori        $v0, $v0, 0x37
    ctx->r2 = ctx->r2 ^ 0X37;
    // 0x8003C42C: bne         $v0, $zero, L_8003C490
    if (ctx->r2 != 0) {
        // 0x8003C430: addiu       $v0, $s0, -0x1
        ctx->r2 = ADD32(ctx->r16, -0X1);
            goto L_8003C490;
    }
    // 0x8003C430: addiu       $v0, $s0, -0x1
    ctx->r2 = ADD32(ctx->r16, -0X1);
    // 0x8003C434: lhu         $v0, 0x58($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X58);
    // 0x8003C438: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8003C43C: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x8003C440: sh          $v0, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r2;
    // 0x8003C444: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8003C448: lhu         $v0, 0x6AF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6AF0);
    // 0x8003C44C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8003C450: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x8003C454: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8003C458: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8003C45C: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8003C460: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8003C464: sh          $v0, 0x6AF0($at)
    MEM_H(0X6AF0, ctx->r1) = ctx->r2;
    // 0x8003C468: jal         0x8004C718
    // 0x8003C46C: nop

    func_8004C718(rdram, ctx);
        goto after_1;
    // 0x8003C46C: nop

    after_1:
    // 0x8003C470: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8003C474: lhu         $v0, 0x6AF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6AF0);
    // 0x8003C478: and         $v0, $v0, $s1
    ctx->r2 = ctx->r2 & ctx->r17;
    // 0x8003C47C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8003C480: sh          $v0, 0x6AF0($at)
    MEM_H(0X6AF0, ctx->r1) = ctx->r2;
    // 0x8003C484: jal         0x80028FF4
    // 0x8003C488: nop

    func_80028FF4(rdram, ctx);
        goto after_2;
    // 0x8003C488: nop

    after_2:
L_8003C48C:
    // 0x8003C48C: addiu       $v0, $s0, -0x1
    ctx->r2 = ADD32(ctx->r16, -0X1);
L_8003C490:
    // 0x8003C490: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8003C494: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003C498: bne         $v0, $zero, L_8003C3F8
    if (ctx->r2 != 0) {
        // 0x8003C49C: nop
    
            goto L_8003C3F8;
    }
    // 0x8003C49C: nop

    // 0x8003C4A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003C4A4: sh          $zero, -0x7458($at)
    MEM_H(-0X7458, ctx->r1) = 0;
    // 0x8003C4A8: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8003C4AC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C4B0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003C4B4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003C4B8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003C4BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003C4C0: jr          $ra
    // 0x8003C4C4: nop

    return;
    // 0x8003C4C4: nop

;}
RECOMP_FUNC void func_8003C4C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C4C8: lhu         $v1, 0x5A($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X5A);
    // 0x8003C4CC: addiu       $v0, $zero, 0x47
    ctx->r2 = ADD32(0, 0X47);
    // 0x8003C4D0: bne         $v1, $v0, L_8003C4EC
    if (ctx->r3 != ctx->r2) {
        // 0x8003C4D4: nop
    
            goto L_8003C4EC;
    }
    // 0x8003C4D4: nop

    // 0x8003C4D8: lhu         $v0, 0x14($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X14);
    // 0x8003C4DC: sh          $v0, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r2;
    // 0x8003C4E0: lhu         $v0, 0x18($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X18);
    // 0x8003C4E4: j           L_8003C508
    // 0x8003C4E8: sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
        goto L_8003C508;
    // 0x8003C4E8: sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
L_8003C4EC:
    // 0x8003C4EC: lw          $v0, 0x120($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X120);
    // 0x8003C4F0: beq         $v0, $zero, L_8003C508
    if (ctx->r2 == 0) {
        // 0x8003C4F4: nop
    
            goto L_8003C508;
    }
    // 0x8003C4F4: nop

    // 0x8003C4F8: lhu         $v0, 0x120($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X120);
    // 0x8003C4FC: sh          $v0, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r2;
    // 0x8003C500: lhu         $v0, 0x122($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X122);
    // 0x8003C504: sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
L_8003C508:
    // 0x8003C508: lhu         $v0, 0x80($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X80);
    // 0x8003C50C: addiu       $v0, $v0, 0x1000
    ctx->r2 = ADD32(ctx->r2, 0X1000);
    // 0x8003C510: jr          $ra
    // 0x8003C514: sh          $v0, 0x80($a1)
    MEM_H(0X80, ctx->r5) = ctx->r2;
    return;
    // 0x8003C514: sh          $v0, 0x80($a1)
    MEM_H(0X80, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void func_8003C518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C518: lhu         $v0, 0xDC($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XDC);
    // 0x8003C51C: lw          $a3, 0x68($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X68);
    // 0x8003C520: beq         $v0, $zero, L_8003C5BC
    if (ctx->r2 == 0) {
        // 0x8003C524: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_8003C5BC;
    }
    // 0x8003C524: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8003C528: lhu         $v1, 0x5A($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X5A);
    // 0x8003C52C: addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
    // 0x8003C530: beq         $v1, $v0, L_8003C5BC
    if (ctx->r3 == ctx->r2) {
        // 0x8003C534: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_8003C5BC;
    }
    // 0x8003C534: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8003C538: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8003C53C: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x8003C540: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003C544: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003C548: beq         $v0, $zero, L_8003C564
    if (ctx->r2 == 0) {
        // 0x8003C54C: nop
    
            goto L_8003C564;
    }
    // 0x8003C54C: nop

    // 0x8003C550: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003C554: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x8003C558: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003C55C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003C560: addu        $a1, $a0, $v0
    ctx->r5 = ADD32(ctx->r4, ctx->r2);
L_8003C564:
    // 0x8003C564: lh          $v0, 0x108($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X108);
    // 0x8003C568: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x8003C56C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003C570: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x8003C574: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003C578: bne         $v0, $zero, L_8003C5C0
    if (ctx->r2 != 0) {
        // 0x8003C57C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003C5C0;
    }
    // 0x8003C57C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003C580: lh          $a0, 0x10C($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X10C);
    // 0x8003C584: addiu       $v0, $a0, 0x30
    ctx->r2 = ADD32(ctx->r4, 0X30);
    // 0x8003C588: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003C58C: bne         $v0, $zero, L_8003C5C0
    if (ctx->r2 != 0) {
        // 0x8003C590: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003C5C0;
    }
    // 0x8003C590: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003C594: lhu         $v0, 0x22($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X22);
    // 0x8003C598: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8003C59C: beq         $v0, $zero, L_8003C5AC
    if (ctx->r2 == 0) {
        // 0x8003C5A0: slt         $v0, $v1, $a0
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8003C5AC;
    }
    // 0x8003C5A0: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003C5A4: lh          $v0, 0x108($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X108);
    // 0x8003C5A8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8003C5AC:
    // 0x8003C5AC: bne         $v0, $zero, L_8003C5C0
    if (ctx->r2 != 0) {
        // 0x8003C5B0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003C5C0;
    }
    // 0x8003C5B0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003C5B4: j           L_8003C5C0
    // 0x8003C5B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003C5C0;
    // 0x8003C5B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003C5BC:
    // 0x8003C5BC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003C5C0:
    // 0x8003C5C0: jr          $ra
    // 0x8003C5C4: nop

    return;
    // 0x8003C5C4: nop

;}
RECOMP_FUNC void func_8003C5C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C5C8: lhu         $v0, 0x14($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X14);
    // 0x8003C5CC: sltiu       $v0, $v0, 0xB
    ctx->r2 = ctx->r2 < 0XB ? 1 : 0;
    // 0x8003C5D0: beq         $v0, $zero, L_8003C674
    if (ctx->r2 == 0) {
        // 0x8003C5D4: andi        $v1, $a0, 0xFFFF
        ctx->r3 = ctx->r4 & 0XFFFF;
            goto L_8003C674;
    }
    // 0x8003C5D4: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8003C5D8: lhu         $v0, 0x8($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X8);
    // 0x8003C5DC: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8003C5E0: bne         $v0, $zero, L_8003C674
    if (ctx->r2 != 0) {
        // 0x8003C5E4: nop
    
            goto L_8003C674;
    }
    // 0x8003C5E4: nop

    // 0x8003C5E8: lw          $v0, 0x68($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X68);
    // 0x8003C5EC: lh          $a0, 0x18($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X18);
    // 0x8003C5F0: slti        $v0, $a0, 0xE1
    ctx->r2 = SIGNED(ctx->r4) < 0XE1 ? 1 : 0;
    // 0x8003C5F4: bne         $v0, $zero, L_8003C604
    if (ctx->r2 != 0) {
        // 0x8003C5F8: nop
    
            goto L_8003C604;
    }
    // 0x8003C5F8: nop

    // 0x8003C5FC: j           L_8003C674
    // 0x8003C600: sh          $zero, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = 0;
        goto L_8003C674;
    // 0x8003C600: sh          $zero, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = 0;
L_8003C604:
    // 0x8003C604: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    // 0x8003C608: lh          $v1, 0xF4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XF4);
    // 0x8003C60C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8003C610: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003C614: bne         $v0, $zero, L_8003C674
    if (ctx->r2 != 0) {
        // 0x8003C618: nop
    
            goto L_8003C674;
    }
    // 0x8003C618: nop

    // 0x8003C61C: lh          $v0, 0xE($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XE);
    // 0x8003C620: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x8003C624: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003C628: bne         $v0, $zero, L_8003C674
    if (ctx->r2 != 0) {
        // 0x8003C62C: nop
    
            goto L_8003C674;
    }
    // 0x8003C62C: nop

    // 0x8003C630: lh          $v1, 0x74($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X74);
    // 0x8003C634: addiu       $v0, $v1, -0x4
    ctx->r2 = ADD32(ctx->r3, -0X4);
    // 0x8003C638: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003C63C: bne         $v0, $zero, L_8003C674
    if (ctx->r2 != 0) {
        // 0x8003C640: addiu       $v0, $a0, 0x4
        ctx->r2 = ADD32(ctx->r4, 0X4);
            goto L_8003C674;
    }
    // 0x8003C640: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x8003C644: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x8003C648: slti        $v0, $v0, 0xB
    ctx->r2 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x8003C64C: beq         $v0, $zero, L_8003C674
    if (ctx->r2 == 0) {
        // 0x8003C650: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8003C674;
    }
    // 0x8003C650: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8003C654: lhu         $v1, 0x1E($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X1E);
    // 0x8003C658: sh          $v0, 0x1B0($a1)
    MEM_H(0X1B0, ctx->r5) = ctx->r2;
    // 0x8003C65C: sh          $zero, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = 0;
    // 0x8003C660: sh          $v1, 0x1B2($a1)
    MEM_H(0X1B2, ctx->r5) = ctx->r3;
    // 0x8003C664: lhu         $v0, 0x74($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X74);
    // 0x8003C668: lw          $v1, 0x68($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X68);
    // 0x8003C66C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8003C670: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
L_8003C674:
    // 0x8003C674: jr          $ra
    // 0x8003C678: nop

    return;
    // 0x8003C678: nop

    // 0x8003C67C: nop

;}
RECOMP_FUNC void func_8003C680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003C684: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003C688: lhu         $v0, 0xE($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XE);
    // 0x8003C68C: beq         $v0, $zero, L_8003C6D4
    if (ctx->r2 == 0) {
        // 0x8003C690: nop
    
            goto L_8003C6D4;
    }
    // 0x8003C690: nop

    // 0x8003C694: lhu         $v1, 0x8($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X8);
    // 0x8003C698: sltiu       $v0, $v1, 0xF
    ctx->r2 = ctx->r3 < 0XF ? 1 : 0;
    // 0x8003C69C: beq         $v0, $zero, L_8003C6D4
    if (ctx->r2 == 0) {
        // 0x8003C6A0: nop
    
            goto L_8003C6D4;
    }
    // 0x8003C6A0: nop

    // 0x8003C6A4: lhu         $v0, 0x1AE($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1AE);
    // 0x8003C6A8: beq         $v0, $zero, L_8003C6B8
    if (ctx->r2 == 0) {
        // 0x8003C6AC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003C6B8;
    }
    // 0x8003C6AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003C6B0: beql        $v1, $v0, L_8003C6B8
    if (ctx->r3 == ctx->r2) {
        // 0x8003C6B4: sh          $zero, 0x8($a0)
        MEM_H(0X8, ctx->r4) = 0;
            goto L_8003C6B8;
    }
    goto skip_0;
    // 0x8003C6B4: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    skip_0:
L_8003C6B8:
    // 0x8003C6B8: lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X8);
    // 0x8003C6BC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003C6C0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8003C6C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003C6C8: lw          $v0, 0x7B60($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7B60);
    // 0x8003C6CC: jalr        $v0
    // 0x8003C6D0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8003C6D0: nop

    after_0:
L_8003C6D4:
    // 0x8003C6D4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003C6D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003C6DC: jr          $ra
    // 0x8003C6E0: nop

    return;
    // 0x8003C6E0: nop

;}
RECOMP_FUNC void func_8003C6E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C6E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003C6E8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003C6EC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8003C6F0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003C6F4: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8003C6F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003C6FC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003C700: lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X22);
    // 0x8003C704: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003C708: jal         0x80032378
    // 0x8003C70C: sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    func_80032378(rdram, ctx);
        goto after_0;
    // 0x8003C70C: sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    after_0:
    // 0x8003C710: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003C714: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8003C718: bne         $v0, $s2, L_8003C728
    if (ctx->r2 != ctx->r18) {
        // 0x8003C71C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8003C728;
    }
    // 0x8003C71C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8003C720: j           L_8003C77C
    // 0x8003C724: addiu       $v0, $zero, 0x55
    ctx->r2 = ADD32(0, 0X55);
        goto L_8003C77C;
    // 0x8003C724: addiu       $v0, $zero, 0x55
    ctx->r2 = ADD32(0, 0X55);
L_8003C728:
    // 0x8003C728: jal         0x800322E0
    // 0x8003C72C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800322E0(rdram, ctx);
        goto after_1;
    // 0x8003C72C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003C730: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003C734: bne         $v0, $s2, L_8003C748
    if (ctx->r2 != ctx->r18) {
        // 0x8003C738: lui         $a0, 0xA
        ctx->r4 = S32(0XA << 16);
            goto L_8003C748;
    }
    // 0x8003C738: lui         $a0, 0xA
    ctx->r4 = S32(0XA << 16);
    // 0x8003C73C: lui         $a0, 0x22
    ctx->r4 = S32(0X22 << 16);
    // 0x8003C740: j           L_8003C750
    // 0x8003C744: lui         $v1, 0x1A
    ctx->r3 = S32(0X1A << 16);
        goto L_8003C750;
    // 0x8003C744: lui         $v1, 0x1A
    ctx->r3 = S32(0X1A << 16);
L_8003C748:
    // 0x8003C748: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8003C74C: ori         $v1, $v1, 0xC000
    ctx->r3 = ctx->r3 | 0XC000;
L_8003C750:
    // 0x8003C750: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x8003C754: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003C758: lui         $v1, 0x44
    ctx->r3 = S32(0X44 << 16);
    // 0x8003C75C: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8003C760: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003C764: bnel        $v0, $zero, L_8003C76C
    if (ctx->r2 != 0) {
        // 0x8003C768: sw          $v1, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r3;
            goto L_8003C76C;
    }
    goto skip_0;
    // 0x8003C768: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    skip_0:
L_8003C76C:
    // 0x8003C76C: jal         0x8003BB8C
    // 0x8003C770: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003BB8C(rdram, ctx);
        goto after_2;
    // 0x8003C770: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8003C774: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8003C778: sh          $zero, 0x126($s0)
    MEM_H(0X126, ctx->r16) = 0;
L_8003C77C:
    // 0x8003C77C: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x8003C780: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C784: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003C788: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003C78C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003C790: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003C794: jr          $ra
    // 0x8003C798: nop

    return;
    // 0x8003C798: nop

;}
RECOMP_FUNC void func_8003C79C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C79C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003C7A0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003C7A4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8003C7A8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003C7AC: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8003C7B0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8003C7B4: jal         0x8003BA80
    // 0x8003C7B8: lui         $a0, 0x4
    ctx->r4 = S32(0X4 << 16);
    func_8003BA80(rdram, ctx);
        goto after_0;
    // 0x8003C7B8: lui         $a0, 0x4
    ctx->r4 = S32(0X4 << 16);
    after_0:
    // 0x8003C7BC: lhu         $v1, 0x8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X8);
    // 0x8003C7C0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8003C7C4: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x8003C7C8: sh          $v1, 0x126($s0)
    MEM_H(0X126, ctx->r16) = ctx->r3;
    // 0x8003C7CC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8003C7D0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003C7D4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003C7D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003C7DC: jr          $ra
    // 0x8003C7E0: nop

    return;
    // 0x8003C7E0: nop

;}
RECOMP_FUNC void func_8003C7E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C7E4: lhu         $v1, 0x8($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X8);
    // 0x8003C7E8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8003C7EC: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    // 0x8003C7F0: jr          $ra
    // 0x8003C7F4: sh          $v1, 0x126($a1)
    MEM_H(0X126, ctx->r5) = ctx->r3;
    return;
    // 0x8003C7F4: sh          $v1, 0x126($a1)
    MEM_H(0X126, ctx->r5) = ctx->r3;
;}
RECOMP_FUNC void func_8003C7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C7F8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8003C7FC: sh          $v0, 0x126($a1)
    MEM_H(0X126, ctx->r5) = ctx->r2;
    // 0x8003C800: addiu       $v0, $zero, 0x25
    ctx->r2 = ADD32(0, 0X25);
    // 0x8003C804: jr          $ra
    // 0x8003C808: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    return;
    // 0x8003C808: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void func_8003C80C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C80C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8003C810: sh          $v0, 0x126($a1)
    MEM_H(0X126, ctx->r5) = ctx->r2;
    // 0x8003C814: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x8003C818: jr          $ra
    // 0x8003C81C: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    return;
    // 0x8003C81C: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void func_8003C820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003C824: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003C828: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8003C82C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003C830: jal         0x8004C79C
    // 0x8003C834: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    func_8004C79C(rdram, ctx);
        goto after_0;
    // 0x8003C834: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    after_0:
    // 0x8003C838: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8003C83C: sh          $v0, 0x126($s0)
    MEM_H(0X126, ctx->r16) = ctx->r2;
    // 0x8003C840: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    // 0x8003C844: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x8003C848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003C84C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003C850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003C854: jr          $ra
    // 0x8003C858: nop

    return;
    // 0x8003C858: nop

;}
RECOMP_FUNC void func_8003C85C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C85C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003C860: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_8003C85C falls into func_8003C864
    func_8003C864(rdram, ctx);
;}
RECOMP_FUNC void func_8003C864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003C868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003C86C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003C870: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x8003C874: lw          $s0, 0x90($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X90);
    // 0x8003C878: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x8003C87C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8003C880: jal         0x8003BA80
    // 0x8003C884: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    func_8003BA80(rdram, ctx);
        goto after_0;
    // 0x8003C884: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    after_0:
    // 0x8003C888: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    // 0x8003C88C: beq         $a0, $zero, L_8003C8A0
    if (ctx->r4 == 0) {
        // 0x8003C890: nop
    
            goto L_8003C8A0;
    }
    // 0x8003C890: nop

    // 0x8003C894: jal         0x80024764
    // 0x8003C898: nop

    func_80024764(rdram, ctx);
        goto after_1;
    // 0x8003C898: nop

    after_1:
    // 0x8003C89C: sw          $zero, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = 0;
L_8003C8A0:
    // 0x8003C8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003C8A4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003C8A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003C8AC: jr          $ra
    // 0x8003C8B0: nop

    return;
    // 0x8003C8B0: nop

;}
RECOMP_FUNC void func_8003C8B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C8B4: jr          $ra
    // 0x8003C8B8: nop

    return;
    // 0x8003C8B8: nop

    // 0x8003C8BC: nop

;}
RECOMP_FUNC void func_8003C8C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C8C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003C8C4: sh          $zero, 0x3E4($at)
    MEM_H(0X3E4, ctx->r1) = 0;
    // 0x8003C8C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8003C8CC: sh          $zero, -0x3076($at)
    MEM_H(-0X3076, ctx->r1) = 0;
    // 0x8003C8D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003C8D4: sh          $zero, -0x692C($at)
    MEM_H(-0X692C, ctx->r1) = 0;
    // 0x8003C8D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003C8DC: sh          $zero, -0x3C($at)
    MEM_H(-0X3C, ctx->r1) = 0;
    // 0x8003C8E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003C8E4: sh          $zero, 0x3D0($at)
    MEM_H(0X3D0, ctx->r1) = 0;
    // 0x8003C8E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003C8EC: sh          $zero, 0x475E($at)
    MEM_H(0X475E, ctx->r1) = 0;
    // 0x8003C8F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003C8F4: sh          $zero, 0x5650($at)
    MEM_H(0X5650, ctx->r1) = 0;
    // 0x8003C8F8: jr          $ra
    // 0x8003C8FC: nop

    return;
    // 0x8003C8FC: nop

;}
RECOMP_FUNC void func_8003C900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C900: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8003C904: lhu         $v0, 0x538($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X538);

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_8003C908
    func_8003C908(rdram, ctx);
}
