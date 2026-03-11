#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80004D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004D64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004D68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004D6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80004D70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80004D74: jal         0x80039D18
    // 0x80004D78: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80039D18(rdram, ctx);
        goto after_0;
    // 0x80004D78: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80004D7C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004D80: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80004D84: addiu       $a0, $a0, -0x4500
    ctx->r4 = ADD32(ctx->r4, -0X4500);
    // 0x80004D88: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    // 0x80004D8C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80004D90: lh          $t7, 0x1A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1A);
    // 0x80004D94: addiu       $t9, $zero, 0x950
    ctx->r25 = ADD32(0, 0X950);
    // 0x80004D98: sh          $t7, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r15;
    // 0x80004D9C: lh          $t8, 0x1E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X1E);
    // 0x80004DA0: sw          $t9, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r25;
    // 0x80004DA4: jal         0x8002EC64
    // 0x80004DA8: sh          $t8, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r24;
    func_8002EC64(rdram, ctx);
        goto after_1;
    // 0x80004DA8: sh          $t8, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r24;
    after_1:
    // 0x80004DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004DB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80004DB4: sw          $v0, -0x47C8($at)
    MEM_W(-0X47C8, ctx->r1) = ctx->r2;
    // 0x80004DB8: jr          $ra
    // 0x80004DBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80004DBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80004DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004DC0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80004DC4: lw          $t6, -0x44E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44E0);
    // FALLTHROUGH FIX: func_80004DC0 falls through to func_80004DC8
    func_80004DC8(rdram, ctx);
;}
RECOMP_FUNC void func_80004DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004DC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004DCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004DD0: lw          $v0, 0x6C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X6C);
    // 0x80004DD4: nop

    // 0x80004DD8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80004DDC: lh          $a0, 0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X4);
    // 0x80004DE0: lh          $a2, 0x6($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X6);
    // 0x80004DE4: jal         0x80004E38
    // 0x80004DE8: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    func_80004E38(rdram, ctx);
        goto after_0;
    // 0x80004DE8: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    after_0:
    // 0x80004DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004DF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004DF4: jr          $ra
    // 0x80004DF8: nop

    return;
    // 0x80004DF8: nop

;}
RECOMP_FUNC void func_80004DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004DFC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80004E00: lw          $t6, -0x44E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44E0);
    // FALLTHROUGH FIX: func_80004DFC falls through to func_80004E04
    func_80004E04(rdram, ctx);
;}
RECOMP_FUNC void func_80004E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004E04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004E0C: lw          $v0, 0x6C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X6C);
    // 0x80004E10: nop

    // 0x80004E14: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80004E18: lh          $a0, 0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X4);
    // 0x80004E1C: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    // 0x80004E20: jal         0x80004D64
    // 0x80004E24: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    func_80004D64(rdram, ctx);
        goto after_0;
    // 0x80004E24: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    after_0:
    // 0x80004E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004E2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004E30: jr          $ra
    // 0x80004E34: nop

    return;
    // 0x80004E34: nop

;}
RECOMP_FUNC void func_80004E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004E38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80004E3C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80004E40: addiu       $v0, $v0, -0x4500
    ctx->r2 = ADD32(ctx->r2, -0X4500);
    // 0x80004E44: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80004E48: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x80004E4C: lw          $t8, -0x47C8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X47C8);
    // 0x80004E50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004E54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80004E58: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80004E5C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80004E60: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80004E64: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80004E68: sw          $t8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r24;
    // 0x80004E6C: sh          $t6, 0x1C($t8)
    MEM_H(0X1C, ctx->r24) = ctx->r14;
    // 0x80004E70: lw          $t1, 0x20($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X20);
    // 0x80004E74: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x80004E78: nop

    // 0x80004E7C: sh          $t0, 0x20($t1)
    MEM_H(0X20, ctx->r9) = ctx->r8;
    // 0x80004E80: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    // 0x80004E84: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80004E88: lhu         $a1, 0x32($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X32);
    // 0x80004E8C: jal         0x80022F38
    // 0x80004E90: nop

    func_80022F38(rdram, ctx);
        goto after_0;
    // 0x80004E90: nop

    after_0:
    // 0x80004E94: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80004E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004E9C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80004EA0: addiu       $v0, $v0, -0x4500
    ctx->r2 = ADD32(ctx->r2, -0X4500);
    // 0x80004EA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80004EA8: jr          $ra
    // 0x80004EAC: sw          $t2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r10;
    return;
    // 0x80004EAC: sw          $t2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r10;
;}
RECOMP_FUNC void func_80004EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004EB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80004EB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80004EB8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80004EBC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80004EC0: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x80004EC4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80004EC8: beq         $s0, $zero, L_80004EEC
    if (ctx->r16 == 0) {
        // 0x80004ECC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80004EEC;
    }
    // 0x80004ECC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80004ED0:
    // 0x80004ED0: jal         0x80000A80
    // 0x80004ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80000A80(rdram, ctx);
        goto after_0;
    // 0x80004ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80004ED8: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80004EDC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80004EE0: bne         $s0, $zero, L_80004ED0
    if (ctx->r16 != 0) {
        // 0x80004EE4: nop
    
            goto L_80004ED0;
    }
    // 0x80004EE4: nop

    // 0x80004EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80004EEC:
    // 0x80004EEC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80004EF0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80004EF4: jr          $ra
    // 0x80004EF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80004EF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80004EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004EFC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80004F00: lhu         $t6, -0x47BE($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X47BE);
    // FALLTHROUGH FIX: func_80004EFC falls through to func_80004F04
    func_80004F04(rdram, ctx);
;}
RECOMP_FUNC void func_80004F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004F04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004F08: bne         $t6, $zero, L_80004F68
    if (ctx->r14 != 0) {
        // 0x80004F0C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80004F68;
    }
    // 0x80004F0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004F10: jal         0x80039D84
    // 0x80004F14: nop

    func_80039D84(rdram, ctx);
        goto after_0;
    // 0x80004F14: nop

    after_0:
    // 0x80004F18: jal         0x80030494
    // 0x80004F1C: nop

    func_80030494(rdram, ctx);
        goto after_1;
    // 0x80004F1C: nop

    after_1:
    // 0x80004F20: jal         0x80039BA0
    // 0x80004F24: nop

    func_80039BA0(rdram, ctx);
        goto after_2;
    // 0x80004F24: nop

    after_2:
    // 0x80004F28: jal         0x800037FC
    // 0x80004F2C: nop

    func_800037FC(rdram, ctx);
        goto after_3;
    // 0x80004F2C: nop

    after_3:
    // 0x80004F30: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80004F34: addiu       $a1, $a1, -0x47BC
    ctx->r5 = ADD32(ctx->r5, -0X47BC);
    // 0x80004F38: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x80004F3C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80004F40: sh          $zero, -0x9D6($at)
    MEM_H(-0X9D6, ctx->r1) = 0;
    // 0x80004F44: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004F48: sh          $zero, 0x77B4($at)
    MEM_H(0X77B4, ctx->r1) = 0;
    // 0x80004F4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80004F50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80004F54: sh          $t7, -0x47BE($at)
    MEM_H(-0X47BE, ctx->r1) = ctx->r15;
    // 0x80004F58: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80004F5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80004F60: b           L_80005060
    // 0x80004F64: sh          $a0, -0x4480($at)
    MEM_H(-0X4480, ctx->r1) = ctx->r4;
        goto L_80005060;
    // 0x80004F64: sh          $a0, -0x4480($at)
    MEM_H(-0X4480, ctx->r1) = ctx->r4;
L_80004F68:
    // 0x80004F68: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80004F6C: addiu       $a1, $a1, -0x47BC
    ctx->r5 = ADD32(ctx->r5, -0X47BC);
    // 0x80004F70: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80004F74: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004F78: bne         $v0, $zero, L_80004FF8
    if (ctx->r2 != 0) {
        // 0x80004F7C: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_80004FF8;
    }
    // 0x80004F7C: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80004F80: jal         0x8002F674
    // 0x80004F84: addiu       $a0, $zero, 0x402
    ctx->r4 = ADD32(0, 0X402);
    func_8002F674(rdram, ctx);
        goto after_4;
    // 0x80004F84: addiu       $a0, $zero, 0x402
    ctx->r4 = ADD32(0, 0X402);
    after_4:
    // 0x80004F88: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80004F8C: lh          $t8, 0x77B4($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X77B4);
    // 0x80004F90: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004F94: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80004F98: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80004F9C: lw          $a0, -0xE98($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XE98);
    // 0x80004FA0: nop

    // 0x80004FA4: bne         $a0, $zero, L_80004FBC
    if (ctx->r4 != 0) {
        // 0x80004FA8: nop
    
            goto L_80004FBC;
    }
    // 0x80004FA8: nop

    // 0x80004FAC: jal         0x800035CC
    // 0x80004FB0: nop

    func_800035CC(rdram, ctx);
        goto after_5;
    // 0x80004FB0: nop

    after_5:
    // 0x80004FB4: b           L_80005064
    // 0x80004FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80005064;
    // 0x80004FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80004FBC:
    // 0x80004FBC: jal         0x80004EB0
    // 0x80004FC0: nop

    func_80004EB0(rdram, ctx);
        goto after_6;
    // 0x80004FC0: nop

    after_6:
    // 0x80004FC4: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x80004FC8: lh          $t0, 0x77B4($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X77B4);
    // 0x80004FCC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004FD0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80004FD4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80004FD8: sh          $t1, 0x77B4($at)
    MEM_H(0X77B4, ctx->r1) = ctx->r9;
    // 0x80004FDC: addiu       $a1, $a1, -0x47BC
    ctx->r5 = ADD32(ctx->r5, -0X47BC);
    // 0x80004FE0: addiu       $t2, $zero, 0xF0
    ctx->r10 = ADD32(0, 0XF0);
    // 0x80004FE4: sh          $t2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r10;
    // 0x80004FE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80004FEC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80004FF0: b           L_80005060
    // 0x80004FF4: sh          $a0, -0x4480($at)
    MEM_H(-0X4480, ctx->r1) = ctx->r4;
        goto L_80005060;
    // 0x80004FF4: sh          $a0, -0x4480($at)
    MEM_H(-0X4480, ctx->r1) = ctx->r4;
L_80004FF8:
    // 0x80004FF8: lh          $a0, -0x4480($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4480);
    // 0x80004FFC: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80005000: beq         $a0, $zero, L_80005014
    if (ctx->r4 == 0) {
        // 0x80005004: lui         $at, 0x100
        ctx->r1 = S32(0X100 << 16);
            goto L_80005014;
    }
    // 0x80005004: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x80005008: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8000500C: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x80005010: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
L_80005014:
    // 0x80005014: sh          $t5, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r13;
    // 0x80005018: lw          $v1, -0x1524($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1524);
    // 0x8000501C: ori         $at, $at, 0x4010
    ctx->r1 = ctx->r1 | 0X4010;
    // 0x80005020: and         $t6, $v1, $at
    ctx->r14 = ctx->r3 & ctx->r1;
    // 0x80005024: beq         $t6, $zero, L_80005038
    if (ctx->r14 == 0) {
        // 0x80005028: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80005038;
    }
    // 0x80005028: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000502C: bne         $a0, $zero, L_80005038
    if (ctx->r4 != 0) {
        // 0x80005030: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80005038;
    }
    // 0x80005030: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80005034: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
L_80005038:
    // 0x80005038: sh          $a0, -0x4480($at)
    MEM_H(-0X4480, ctx->r1) = ctx->r4;
    // 0x8000503C: lui         $at, 0x1004
    ctx->r1 = S32(0X1004 << 16);
    // 0x80005040: ori         $at, $at, 0x100
    ctx->r1 = ctx->r1 | 0X100;
    // 0x80005044: and         $t8, $v1, $at
    ctx->r24 = ctx->r3 & ctx->r1;
    // 0x80005048: beq         $t8, $zero, L_80005060
    if (ctx->r24 == 0) {
        // 0x8000504C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80005060;
    }
    // 0x8000504C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005050: bne         $a0, $zero, L_80005060
    if (ctx->r4 != 0) {
        // 0x80005054: sh          $a0, -0x4480($at)
        MEM_H(-0X4480, ctx->r1) = ctx->r4;
            goto L_80005060;
    }
    // 0x80005054: sh          $a0, -0x4480($at)
    MEM_H(-0X4480, ctx->r1) = ctx->r4;
    // 0x80005058: jal         0x800035CC
    // 0x8000505C: nop

    func_800035CC(rdram, ctx);
        goto after_7;
    // 0x8000505C: nop

    after_7:
L_80005060:
    // 0x80005060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80005064:
    // 0x80005064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005068: jr          $ra
    // 0x8000506C: nop

    return;
    // 0x8000506C: nop

;}
RECOMP_FUNC void func_80005070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005070: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80005074: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005078: lw          $t6, -0x44E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44E0);
    // 0x8000507C: lhu         $v0, -0x16A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X16A);
    // FALLTHROUGH FIX: func_80005070 falls through to func_80005080
    func_80005080(rdram, ctx);
;}
RECOMP_FUNC void func_80005080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005080: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80005084: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005088: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000508C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80005090: beq         $v0, $zero, L_80005140
    if (ctx->r2 == 0) {
        // 0x80005094: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_80005140;
    }
    // 0x80005094: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80005098: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000509C: bne         $v0, $at, L_80005130
    if (ctx->r2 != ctx->r1) {
        // 0x800050A0: addiu       $t7, $zero, 0xB4
        ctx->r15 = ADD32(0, 0XB4);
            goto L_80005130;
    }
    // 0x800050A0: addiu       $t7, $zero, 0xB4
    ctx->r15 = ADD32(0, 0XB4);
    // 0x800050A4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800050A8: lw          $s0, -0x4F38($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X4F38);
    // 0x800050AC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800050B0: sh          $t7, -0x172($at)
    MEM_H(-0X172, ctx->r1) = ctx->r15;
    // 0x800050B4: jal         0x80005304
    // 0x800050B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80005304(rdram, ctx);
        goto after_0;
    // 0x800050B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800050BC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800050C0: addiu       $v1, $v1, -0x48A0
    ctx->r3 = ADD32(ctx->r3, -0X48A0);
    // 0x800050C4: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x800050C8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800050CC: bne         $t8, $zero, L_800050DC
    if (ctx->r24 != 0) {
        // 0x800050D0: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800050DC;
    }
    // 0x800050D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800050D4: b           L_800050FC
    // 0x800050D8: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
        goto L_800050FC;
    // 0x800050D8: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_800050DC:
    // 0x800050DC: lh          $v0, -0x4F2C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4F2C);
    // 0x800050E0: nop

    // 0x800050E4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800050E8: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x800050EC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800050F0: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x800050F4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800050F8: andi        $v0, $t9, 0xFFFF
    ctx->r2 = ctx->r25 & 0XFFFF;
L_800050FC:
    // 0x800050FC: jal         0x8004C780
    // 0x80005100: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8004C780(rdram, ctx);
        goto after_1;
    // 0x80005100: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80005104: lw          $t3, 0x54($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X54);
    // 0x80005108: addiu       $t2, $zero, 0x5F
    ctx->r10 = ADD32(0, 0X5F);
    // 0x8000510C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80005110: sh          $t2, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r10;
    // 0x80005114: sw          $zero, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = 0;
    // 0x80005118: addiu       $v0, $v0, -0x4F3C
    ctx->r2 = ADD32(ctx->r2, -0X4F3C);
    // 0x8000511C: sw          $zero, 0x14($t3)
    MEM_W(0X14, ctx->r11) = 0;
    // 0x80005120: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x80005124: nop

    // 0x80005128: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000512C: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
L_80005130:
    // 0x80005130: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80005134: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005138: b           L_80005230
    // 0x8000513C: sw          $t6, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r14;
        goto L_80005230;
    // 0x8000513C: sw          $t6, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r14;
L_80005140:
    // 0x80005140: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80005144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80005148: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8000514C: addiu       $a3, $a3, -0x798
    ctx->r7 = ADD32(ctx->r7, -0X798);
    // 0x80005150: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80005154: addiu       $t0, $zero, 0x1CC
    ctx->r8 = ADD32(0, 0X1CC);
L_80005158:
    // 0x80005158: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000515C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80005160: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x80005164: mflo        $t7
    ctx->r15 = lo;
    // 0x80005168: addu        $v0, $a3, $t7
    ctx->r2 = ADD32(ctx->r7, ctx->r15);
    // 0x8000516C: lhu         $t8, -0x188($v0)
    ctx->r24 = MEM_HU(ctx->r2, -0X188);
    // 0x80005170: addiu       $v1, $v0, -0x1CC
    ctx->r3 = ADD32(ctx->r2, -0X1CC);
    // 0x80005174: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80005178: beq         $t9, $zero, L_800051A0
    if (ctx->r25 == 0) {
        // 0x8000517C: nop
    
            goto L_800051A0;
    }
    // 0x8000517C: nop

    // 0x80005180: lhu         $t1, 0x134($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X134);
    // 0x80005184: nop

    // 0x80005188: bne         $t1, $zero, L_800051A0
    if (ctx->r9 != 0) {
        // 0x8000518C: nop
    
            goto L_800051A0;
    }
    // 0x8000518C: nop

    // 0x80005190: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80005194: andi        $t2, $a2, 0xFFFF
    ctx->r10 = ctx->r6 & 0XFFFF;
    // 0x80005198: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x8000519C: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800051A0:
    // 0x800051A0: bgtz        $a1, L_80005158
    if (SIGNED(ctx->r5) > 0) {
        // 0x800051A4: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80005158;
    }
    // 0x800051A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800051A8: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x800051AC: bne         $at, $zero, L_800051F8
    if (ctx->r1 != 0) {
        // 0x800051B0: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800051F8;
    }
    // 0x800051B0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800051B4: addiu       $v1, $v1, -0x48A0
    ctx->r3 = ADD32(ctx->r3, -0X48A0);
    // 0x800051B8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800051BC: addiu       $at, $zero, 0x21C
    ctx->r1 = ADD32(0, 0X21C);
    // 0x800051C0: blez        $v0, L_800051EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800051C4: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_800051EC;
    }
    // 0x800051C4: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x800051C8: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800051CC: bne         $t5, $at, L_800051DC
    if (ctx->r13 != ctx->r1) {
        // 0x800051D0: sh          $t4, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r12;
            goto L_800051DC;
    }
    // 0x800051D0: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x800051D4: jal         0x80005360
    // 0x800051D8: nop

    func_80005360(rdram, ctx);
        goto after_2;
    // 0x800051D8: nop

    after_2:
L_800051DC:
    // 0x800051DC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800051E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800051E4: b           L_80005230
    // 0x800051E8: sw          $t6, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r14;
        goto L_80005230;
    // 0x800051E8: sw          $t6, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r14;
L_800051EC:
    // 0x800051EC: jal         0x80005240
    // 0x800051F0: nop

    func_80005240(rdram, ctx);
        goto after_3;
    // 0x800051F0: nop

    after_3:
    // 0x800051F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800051F8:
    // 0x800051F8: jal         0x8005D200
    // 0x800051FC: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_8005D200(rdram, ctx);
        goto after_4;
    // 0x800051FC: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_4:
    // 0x80005200: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005204: jal         0x80005404
    // 0x80005208: sw          $s0, -0x4F38($at)
    MEM_W(-0X4F38, ctx->r1) = ctx->r16;
    func_80005404(rdram, ctx);
        goto after_5;
    // 0x80005208: sw          $s0, -0x4F38($at)
    MEM_W(-0X4F38, ctx->r1) = ctx->r16;
    after_5:
    // 0x8000520C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80005210: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005214: sh          $t7, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r15;
    // 0x80005218: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000521C: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80005220: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80005224: sh          $t8, -0x172($at)
    MEM_H(-0X172, ctx->r1) = ctx->r24;
    // 0x80005228: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000522C: sw          $t9, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r25;
L_80005230:
    // 0x80005230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80005234: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80005238: jr          $ra
    // 0x8000523C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000523C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80005240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005240: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80005244: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80005248: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000524C: addiu       $s3, $v0, -0x798
    ctx->r19 = ADD32(ctx->r2, -0X798);
    // 0x80005250: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80005254: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80005258: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000525C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80005260: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x80005264: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80005268: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000526C:
    // 0x8000526C: lhu         $t6, 0x44($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X44);
    // 0x80005270: nop

    // 0x80005274: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80005278: beq         $t7, $zero, L_800052D0
    if (ctx->r15 == 0) {
        // 0x8000527C: nop
    
            goto L_800052D0;
    }
    // 0x8000527C: nop

    // 0x80005280: lhu         $t8, 0x134($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X134);
    // 0x80005284: nop

    // 0x80005288: bne         $t8, $zero, L_800052D0
    if (ctx->r24 != 0) {
        // 0x8000528C: nop
    
            goto L_800052D0;
    }
    // 0x8000528C: nop

    // 0x80005290: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80005294: nop

    // 0x80005298: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8000529C: bne         $at, $zero, L_800052D0
    if (ctx->r1 != 0) {
        // 0x800052A0: nop
    
            goto L_800052D0;
    }
    // 0x800052A0: nop

    // 0x800052A4: bne         $s1, $v0, L_800052C8
    if (ctx->r17 != ctx->r2) {
        // 0x800052A8: addiu       $a0, $zero, 0x5F03
        ctx->r4 = ADD32(0, 0X5F03);
            goto L_800052C8;
    }
    // 0x800052A8: addiu       $a0, $zero, 0x5F03
    ctx->r4 = ADD32(0, 0X5F03);
    // 0x800052AC: jal         0x80000688
    // 0x800052B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80000688(rdram, ctx);
        goto after_0;
    // 0x800052B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800052B4: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800052B8: beq         $t9, $zero, L_800052D0
    if (ctx->r25 == 0) {
        // 0x800052BC: nop
    
            goto L_800052D0;
    }
    // 0x800052BC: nop

    // 0x800052C0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800052C4: nop

L_800052C8:
    // 0x800052C8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800052CC: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
L_800052D0:
    // 0x800052D0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800052D4: andi        $t0, $s2, 0xFFFF
    ctx->r8 = ctx->r18 & 0XFFFF;
    // 0x800052D8: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
    // 0x800052DC: bgtz        $t0, L_8000526C
    if (SIGNED(ctx->r8) > 0) {
        // 0x800052E0: addiu       $s0, $s0, 0x1CC
        ctx->r16 = ADD32(ctx->r16, 0X1CC);
            goto L_8000526C;
    }
    // 0x800052E0: addiu       $s0, $s0, 0x1CC
    ctx->r16 = ADD32(ctx->r16, 0X1CC);
    // 0x800052E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800052E8: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800052EC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800052F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800052F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800052F8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800052FC: jr          $ra
    // 0x80005300: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80005300: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80005304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005304: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80005308: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000530C: addiu       $v1, $v1, -0x798
    ctx->r3 = ADD32(ctx->r3, -0X798);
    // 0x80005310: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80005314: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
L_80005318:
    // 0x80005318: lhu         $t6, 0x44($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X44);
    // 0x8000531C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80005320: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80005324: beq         $t7, $zero, L_8000534C
    if (ctx->r15 == 0) {
        // 0x80005328: andi        $t9, $v0, 0xFFFF
        ctx->r25 = ctx->r2 & 0XFFFF;
            goto L_8000534C;
    }
    // 0x80005328: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x8000532C: lhu         $t8, 0x134($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X134);
    // 0x80005330: nop

    // 0x80005334: bne         $t8, $zero, L_8000534C
    if (ctx->r24 != 0) {
        // 0x80005338: nop
    
            goto L_8000534C;
    }
    // 0x80005338: nop

    // 0x8000533C: beq         $v1, $a0, L_8000534C
    if (ctx->r3 == ctx->r4) {
        // 0x80005340: nop
    
            goto L_8000534C;
    }
    // 0x80005340: nop

    // 0x80005344: sh          $a1, 0x46($v1)
    MEM_H(0X46, ctx->r3) = ctx->r5;
    // 0x80005348: sh          $a2, 0x134($v1)
    MEM_H(0X134, ctx->r3) = ctx->r6;
L_8000534C:
    // 0x8000534C: addiu       $v1, $v1, 0x1CC
    ctx->r3 = ADD32(ctx->r3, 0X1CC);
    // 0x80005350: bgtz        $t9, L_80005318
    if (SIGNED(ctx->r25) > 0) {
        // 0x80005354: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80005318;
    }
    // 0x80005354: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80005358: jr          $ra
    // 0x8000535C: nop

    return;
    // 0x8000535C: nop

;}
RECOMP_FUNC void func_80005360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005360: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80005364: lw          $t6, -0x44E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44E0);
    // FALLTHROUGH FIX: func_80005360 falls through to func_80005368
    func_80005368(rdram, ctx);
;}
RECOMP_FUNC void func_80005368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005368: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000536C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005370: jal         0x80039D18
    // 0x80005374: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80039D18(rdram, ctx);
        goto after_0;
    // 0x80005374: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80005378: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000537C: addiu       $a0, $a0, -0x4500
    ctx->r4 = ADD32(ctx->r4, -0X4500);
    // 0x80005380: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    // 0x80005384: lui         $t9, 0x4800
    ctx->r25 = S32(0X4800 << 16);
    // 0x80005388: addiu       $t7, $zero, 0xD8
    ctx->r15 = ADD32(0, 0XD8);
    // 0x8000538C: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80005390: ori         $t9, $t9, 0x2414
    ctx->r25 = ctx->r25 | 0X2414;
    // 0x80005394: addiu       $t0, $zero, 0x5000
    ctx->r8 = ADD32(0, 0X5000);
    // 0x80005398: sh          $t7, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r15;
    // 0x8000539C: sh          $t8, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r24;
    // 0x800053A0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800053A4: sw          $t0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r8;
    // 0x800053A8: jal         0x8002EC64
    // 0x800053AC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8002EC64(rdram, ctx);
        goto after_1;
    // 0x800053AC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x800053B0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800053B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800053B8: sw          $v0, -0x4F34($at)
    MEM_W(-0X4F34, ctx->r1) = ctx->r2;
    // 0x800053BC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800053C0: addiu       $a0, $a0, -0x63C0
    ctx->r4 = ADD32(ctx->r4, -0X63C0);
    // 0x800053C4: addiu       $t1, $zero, 0xC4
    ctx->r9 = ADD32(0, 0XC4);
    // 0x800053C8: addiu       $t2, $zero, 0x31
    ctx->r10 = ADD32(0, 0X31);
    // 0x800053CC: sh          $t1, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r9;
    // 0x800053D0: sh          $t2, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r10;
    // 0x800053D4: sw          $a0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r4;
    // 0x800053D8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800053DC: jal         0x8002EC64
    // 0x800053E0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    func_8002EC64(rdram, ctx);
        goto after_2;
    // 0x800053E0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    after_2:
    // 0x800053E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800053E8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800053EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800053F0: sw          $v0, -0x4F30($at)
    MEM_W(-0X4F30, ctx->r1) = ctx->r2;
    // 0x800053F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800053F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800053FC: jr          $ra
    // 0x80005400: sw          $t4, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r12;
    return;
    // 0x80005400: sw          $t4, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r12;
;}
RECOMP_FUNC void func_80005404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005404: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80005408: lw          $t6, -0x44E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44E0);
    // FALLTHROUGH FIX: func_80005404 falls through to func_8000540C
    func_8000540C(rdram, ctx);
;}
RECOMP_FUNC void func_8000540C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000540C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005410: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80005414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005418: lw          $a0, -0x4F34($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4F34);
    // 0x8000541C: jal         0x80037AD8
    // 0x80005420: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80037AD8(rdram, ctx);
        goto after_0;
    // 0x80005420: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80005424: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80005428: lw          $v0, -0x4F30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4F30);
    // 0x8000542C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005430: beq         $v0, $zero, L_80005454
    if (ctx->r2 == 0) {
        // 0x80005434: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80005454;
    }
    // 0x80005434: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80005438: jal         0x800304E4
    // 0x8000543C: sw          $v0, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r2;
    func_800304E4(rdram, ctx);
        goto after_1;
    // 0x8000543C: sw          $v0, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r2;
    after_1:
    // 0x80005440: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80005444: lw          $a0, -0x4F30($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4F30);
    // 0x80005448: jal         0x80037AD8
    // 0x8000544C: nop

    func_80037AD8(rdram, ctx);
        goto after_2;
    // 0x8000544C: nop

    after_2:
    // 0x80005450: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_80005454:
    // 0x80005454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005458: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000545C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80005460: jr          $ra
    // 0x80005464: sw          $t7, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r15;
    return;
    // 0x80005464: sw          $t7, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_80005468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005468: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8000546C: lh          $t7, -0x4F2C($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X4F2C);
    // 0x80005470: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80005474: lw          $t6, -0x44E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44E0);
    // FALLTHROUGH FIX: func_80005468 falls through to func_80005478
    func_80005478(rdram, ctx);
;}
RECOMP_FUNC void func_80005478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005478: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000547C: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80005480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005484: bne         $at, $zero, L_80005504
    if (ctx->r1 != 0) {
        // 0x80005488: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_80005504;
    }
    // 0x80005488: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8000548C: jal         0x80039D18
    // 0x80005490: nop

    func_80039D18(rdram, ctx);
        goto after_0;
    // 0x80005490: nop

    after_0:
    // 0x80005494: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80005498: addiu       $a0, $a0, -0x4500
    ctx->r4 = ADD32(ctx->r4, -0X4500);
    // 0x8000549C: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    // 0x800054A0: lui         $t9, 0x4F00
    ctx->r25 = S32(0X4F00 << 16);
    // 0x800054A4: addiu       $t8, $zero, 0x5000
    ctx->r24 = ADD32(0, 0X5000);
    // 0x800054A8: ori         $t9, $t9, 0x1E4
    ctx->r25 = ctx->r25 | 0X1E4;
    // 0x800054AC: addiu       $t0, $zero, 0x123
    ctx->r8 = ADD32(0, 0X123);
    // 0x800054B0: addiu       $t1, $zero, 0x58
    ctx->r9 = ADD32(0, 0X58);
    // 0x800054B4: sw          $t8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r24;
    // 0x800054B8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800054BC: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x800054C0: sh          $t1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r9;
    // 0x800054C4: jal         0x8002EC64
    // 0x800054C8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8002EC64(rdram, ctx);
        goto after_1;
    // 0x800054C8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x800054CC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800054D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800054D4: addiu       $a0, $a0, -0x4F30
    ctx->r4 = ADD32(ctx->r4, -0X4F30);
    // 0x800054D8: lui         $t2, 0x4F00
    ctx->r10 = S32(0X4F00 << 16);
    // 0x800054DC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800054E0: ori         $t2, $t2, 0x1E2
    ctx->r10 = ctx->r10 | 0X1E2;
    // 0x800054E4: addiu       $t3, $zero, 0x12D
    ctx->r11 = ADD32(0, 0X12D);
    // 0x800054E8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800054EC: jal         0x8002EC64
    // 0x800054F0: sh          $t3, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r11;
    func_8002EC64(rdram, ctx);
        goto after_2;
    // 0x800054F0: sh          $t3, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r11;
    after_2:
    // 0x800054F4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800054F8: addiu       $v1, $v1, -0x4F34
    ctx->r3 = ADD32(ctx->r3, -0X4F34);
    // 0x800054FC: b           L_80005550
    // 0x80005500: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80005550;
    // 0x80005500: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80005504:
    // 0x80005504: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80005508: addiu       $v1, $v1, -0x4F34
    ctx->r3 = ADD32(ctx->r3, -0X4F34);
    // 0x8000550C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80005510: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80005514: beq         $v0, $zero, L_80005530
    if (ctx->r2 == 0) {
        // 0x80005518: addiu       $a0, $a0, -0x4F30
        ctx->r4 = ADD32(ctx->r4, -0X4F30);
            goto L_80005530;
    }
    // 0x80005518: addiu       $a0, $a0, -0x4F30
    ctx->r4 = ADD32(ctx->r4, -0X4F30);
    // 0x8000551C: addiu       $t4, $zero, 0x136
    ctx->r12 = ADD32(0, 0X136);
    // 0x80005520: sh          $t4, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r12;
    // 0x80005524: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80005528: addiu       $t5, $zero, 0x46
    ctx->r13 = ADD32(0, 0X46);
    // 0x8000552C: sh          $t5, 0x20($t6)
    MEM_H(0X20, ctx->r14) = ctx->r13;
L_80005530:
    // 0x80005530: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80005534: addiu       $t7, $zero, 0x122
    ctx->r15 = ADD32(0, 0X122);
    // 0x80005538: beq         $v0, $zero, L_80005554
    if (ctx->r2 == 0) {
        // 0x8000553C: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_80005554;
    }
    // 0x8000553C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80005540: sh          $t7, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r15;
    // 0x80005544: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80005548: addiu       $t8, $zero, 0x58
    ctx->r24 = ADD32(0, 0X58);
    // 0x8000554C: sh          $t8, 0x20($t9)
    MEM_H(0X20, ctx->r25) = ctx->r24;
L_80005550:
    // 0x80005550: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
L_80005554:
    // 0x80005554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005558: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000555C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80005560: jr          $ra
    // 0x80005564: sw          $t0, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r8;
    return;
    // 0x80005564: sw          $t0, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void func_80005568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005568: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000556C: lw          $t6, -0x44E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44E0);
    // 0x80005570: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005574: lw          $v0, 0x6C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X6C);
    // 0x80005578: nop

    // 0x8000557C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80005580: jr          $ra
    // 0x80005584: sh          $t7, -0x4F2C($at)
    MEM_H(-0X4F2C, ctx->r1) = ctx->r15;
    return;
    // 0x80005584: sh          $t7, -0x4F2C($at)
    MEM_H(-0X4F2C, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_80005588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005588: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000558C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80005590: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80005594: addiu       $s3, $s3, -0x4500
    ctx->r19 = ADD32(ctx->r19, -0X4500);
    // 0x80005598: lw          $t6, 0x20($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X20);
    // 0x8000559C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800055A0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800055A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800055A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800055AC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800055B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800055B4: jal         0x80039D18
    // 0x800055B8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80039D18(rdram, ctx);
        goto after_0;
    // 0x800055B8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x800055BC: sw          $v0, 0x3C($s3)
    MEM_W(0X3C, ctx->r19) = ctx->r2;
    // 0x800055C0: addiu       $t7, $zero, 0x5000
    ctx->r15 = ADD32(0, 0X5000);
    // 0x800055C4: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x800055C8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800055CC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800055D0: beq         $v1, $zero, L_80005614
    if (ctx->r3 == 0) {
        // 0x800055D4: nop
    
            goto L_80005614;
    }
    // 0x800055D4: nop

L_800055D8:
    // 0x800055D8: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x800055DC: lhu         $t8, 0x4($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X4);
    // 0x800055E0: nop

    // 0x800055E4: sh          $t8, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r24;
    // 0x800055E8: lhu         $t9, 0x6($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6);
    // 0x800055EC: jal         0x8002EC64
    // 0x800055F0: sh          $t9, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r25;
    func_8002EC64(rdram, ctx);
        goto after_1;
    // 0x800055F0: sh          $t9, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r25;
    after_1:
    // 0x800055F4: beq         $s2, $zero, L_80005604
    if (ctx->r18 == 0) {
        // 0x800055F8: sw          $v0, 0x20($s3)
        MEM_W(0X20, ctx->r19) = ctx->r2;
            goto L_80005604;
    }
    // 0x800055F8: sw          $v0, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r2;
    // 0x800055FC: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x80005600: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80005604:
    // 0x80005604: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80005608: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8000560C: bne         $v1, $zero, L_800055D8
    if (ctx->r3 != 0) {
        // 0x80005610: nop
    
            goto L_800055D8;
    }
    // 0x80005610: nop

L_80005614:
    // 0x80005614: beq         $s2, $zero, L_80005624
    if (ctx->r18 == 0) {
        // 0x80005618: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_80005624;
    }
    // 0x80005618: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8000561C: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x80005620: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
L_80005624:
    // 0x80005624: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80005628: sw          $t1, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r9;
    // 0x8000562C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80005630: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80005634: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80005638: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000563C: jr          $ra
    // 0x80005640: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80005640: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80005644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005644: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005648: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000564C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80005650: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80005654: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
    // 0x80005658: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000565C: beq         $s1, $zero, L_80005680
    if (ctx->r17 == 0) {
        // 0x80005660: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80005680;
    }
    // 0x80005660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80005664:
    // 0x80005664: jal         0x8002F750
    // 0x80005668: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8002F750(rdram, ctx);
        goto after_0;
    // 0x80005668: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8000566C: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x80005670: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80005674: bne         $s1, $zero, L_80005664
    if (ctx->r17 != 0) {
        // 0x80005678: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80005664;
    }
    // 0x80005678: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000567C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80005680:
    // 0x80005680: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80005684: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80005688: jr          $ra
    // 0x8000568C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000568C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80005690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005690: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005694: jr          $ra
    // 0x80005698: sh          $zero, -0x48A0($at)
    MEM_H(-0X48A0, ctx->r1) = 0;
    return;
    // 0x80005698: sh          $zero, -0x48A0($at)
    MEM_H(-0X48A0, ctx->r1) = 0;
;}
RECOMP_FUNC void func_8000569C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000569C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800056A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800056A4: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x800056A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800056AC: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800056B0: addiu       $s0, $s0, -0x818
    ctx->r16 = ADD32(ctx->r16, -0X818);
    // 0x800056B4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800056B8: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800056BC: addiu       $v1, $v1, 0x614
    ctx->r3 = ADD32(ctx->r3, 0X614);
    // 0x800056C0: addiu       $v0, $v0, 0x618
    ctx->r2 = ADD32(ctx->r2, 0X618);
    // 0x800056C4: addiu       $s1, $s1, -0x486E
    ctx->r17 = ADD32(ctx->r17, -0X486E);
    // 0x800056C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800056CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800056D0: sh          $zero, 0x26($s0)
    MEM_H(0X26, ctx->r16) = 0;
    // 0x800056D4: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x800056D8: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    // 0x800056DC: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800056E0: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x800056E4: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800056E8: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x800056EC: jal         0x80039D84
    // 0x800056F0: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    func_80039D84(rdram, ctx);
        goto after_0;
    // 0x800056F0: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    after_0:
    // 0x800056F4: jal         0x80030494
    // 0x800056F8: nop

    func_80030494(rdram, ctx);
        goto after_1;
    // 0x800056F8: nop

    after_1:
    // 0x800056FC: jal         0x80039D8C
    // 0x80005700: nop

    func_80039D8C(rdram, ctx);
        goto after_2;
    // 0x80005700: nop

    after_2:
    // 0x80005704: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80005708: jal         0x80067B38
    // 0x8000570C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80067B38(rdram, ctx);
        goto after_3;
    // 0x8000570C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80005710: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80005714: jal         0x80067B28
    // 0x80005718: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80067B28(rdram, ctx);
        goto after_4;
    // 0x80005718: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x8000571C: jal         0x8005CB90
    // 0x80005720: nop

    func_8005CB90(rdram, ctx);
        goto after_5;
    // 0x80005720: nop

    after_5:
    // 0x80005724: jal         0x800179E8
    // 0x80005728: nop

    func_800179E8(rdram, ctx);
        goto after_6;
    // 0x80005728: nop

    after_6:
    // 0x8000572C: jal         0x8004D2A0
    // 0x80005730: nop

    func_8004D2A0(rdram, ctx);
        goto after_7;
    // 0x80005730: nop

    after_7:
    // 0x80005734: jal         0x8000AF2C
    // 0x80005738: nop

    func_8000AF2C(rdram, ctx);
        goto after_8;
    // 0x80005738: nop

    after_8:
    // 0x8000573C: jal         0x80031DB4
    // 0x80005740: nop

    func_80031DB4(rdram, ctx);
        goto after_9;
    // 0x80005740: nop

    after_9:
    // 0x80005744: jal         0x8003D188
    // 0x80005748: nop

    func_8003D188(rdram, ctx);
        goto after_10;
    // 0x80005748: nop

    after_10:
    // 0x8000574C: jal         0x80046EE8
    // 0x80005750: nop

    func_80046EE8(rdram, ctx);
        goto after_11;
    // 0x80005750: nop

    after_11:
    // 0x80005754: jal         0x8004F688
    // 0x80005758: nop

    func_8004F688(rdram, ctx);
        goto after_12;
    // 0x80005758: nop

    after_12:
    // 0x8000575C: jal         0x80042F80
    // 0x80005760: nop

    func_80042F80(rdram, ctx);
        goto after_13;
    // 0x80005760: nop

    after_13:
    // 0x80005764: jal         0x8001EA10
    // 0x80005768: nop

    func_8001EA10(rdram, ctx);
        goto after_14;
    // 0x80005768: nop

    after_14:
    // 0x8000576C: jal         0x8002E60C
    // 0x80005770: nop

    func_8002E60C(rdram, ctx);
        goto after_15;
    // 0x80005770: nop

    after_15:
    // 0x80005774: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80005778: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000577C: addiu       $a1, $a1, -0x4F28
    ctx->r5 = ADD32(ctx->r5, -0X4F28);
    // 0x80005780: jal         0x80005588
    // 0x80005784: addiu       $a0, $a0, 0x77C0
    ctx->r4 = ADD32(ctx->r4, 0X77C0);
    func_80005588(rdram, ctx);
        goto after_16;
    // 0x80005784: addiu       $a0, $a0, 0x77C0
    ctx->r4 = ADD32(ctx->r4, 0X77C0);
    after_16:
    // 0x80005788: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8000578C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80005790: addiu       $a1, $a1, -0x4EF8
    ctx->r5 = ADD32(ctx->r5, -0X4EF8);
    // 0x80005794: jal         0x80005588
    // 0x80005798: addiu       $a0, $a0, 0x7820
    ctx->r4 = ADD32(ctx->r4, 0X7820);
    func_80005588(rdram, ctx);
        goto after_17;
    // 0x80005798: addiu       $a0, $a0, 0x7820
    ctx->r4 = ADD32(ctx->r4, 0X7820);
    after_17:
    // 0x8000579C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x800057A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800057A4: sh          $t6, -0x486C($at)
    MEM_H(-0X486C, ctx->r1) = ctx->r14;
    // 0x800057A8: addiu       $t7, $zero, 0x3FF
    ctx->r15 = ADD32(0, 0X3FF);
    // 0x800057AC: jal         0x8005EE20
    // 0x800057B0: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
    func_8005EE20(rdram, ctx);
        goto after_18;
    // 0x800057B0: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
    after_18:
    // 0x800057B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800057B8: sh          $zero, -0x4976($at)
    MEM_H(-0X4976, ctx->r1) = 0;
    // 0x800057BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800057C0: sw          $zero, -0x47E4($at)
    MEM_W(-0X47E4, ctx->r1) = 0;
    // 0x800057C4: jal         0x8002F674
    // 0x800057C8: addiu       $a0, $zero, 0x40F
    ctx->r4 = ADD32(0, 0X40F);
    func_8002F674(rdram, ctx);
        goto after_19;
    // 0x800057C8: addiu       $a0, $zero, 0x40F
    ctx->r4 = ADD32(0, 0X40F);
    after_19:
    // 0x800057CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800057D0: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
    // 0x800057D4: jal         0x80067BB4
    // 0x800057D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067BB4(rdram, ctx);
        goto after_20;
    // 0x800057D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x800057DC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800057E0: lhu         $a1, 0x6640($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6640);
    // 0x800057E4: jal         0x800330B4
    // 0x800057E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800330B4(rdram, ctx);
        goto after_21;
    // 0x800057E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_21:
    // 0x800057EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800057F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800057F4: sh          $t9, -0x4F64($at)
    MEM_H(-0X4F64, ctx->r1) = ctx->r25;
    // 0x800057F8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800057FC: addiu       $t0, $zero, 0x240
    ctx->r8 = ADD32(0, 0X240);
    // 0x80005800: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80005804: sh          $t0, -0x87A($at)
    MEM_H(-0X87A, ctx->r1) = ctx->r8;
    // 0x80005808: addiu       $s0, $s0, -0x798
    ctx->r16 = ADD32(ctx->r16, -0X798);
    // 0x8000580C: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80005810: lui         $s2, 0x64
    ctx->r18 = S32(0X64 << 16);
L_80005814:
    // 0x80005814: lhu         $t1, 0x44($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X44);
    // 0x80005818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000581C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80005820: beq         $t2, $zero, L_8000583C
    if (ctx->r10 == 0) {
        // 0x80005824: nop
    
            goto L_8000583C;
    }
    // 0x80005824: nop

    // 0x80005828: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8000582C: sw          $zero, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = 0;
    // 0x80005830: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80005834: jal         0x8000587C
    // 0x80005838: sw          $t3, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r11;
    func_8000587C(rdram, ctx);
        goto after_22;
    // 0x80005838: sw          $t3, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r11;
    after_22:
L_8000583C:
    // 0x8000583C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80005840: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x80005844: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x80005848: bgtz        $t4, L_80005814
    if (SIGNED(ctx->r12) > 0) {
        // 0x8000584C: addiu       $s0, $s0, 0x1CC
        ctx->r16 = ADD32(ctx->r16, 0X1CC);
            goto L_80005814;
    }
    // 0x8000584C: addiu       $s0, $s0, 0x1CC
    ctx->r16 = ADD32(ctx->r16, 0X1CC);
    // 0x80005850: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005854: jal         0x8005D1D0
    // 0x80005858: sh          $zero, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = 0;
    func_8005D1D0(rdram, ctx);
        goto after_23;
    // 0x80005858: sh          $zero, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = 0;
    after_23:
    // 0x8000585C: jal         0x8005D2C0
    // 0x80005860: nop

    func_8005D2C0(rdram, ctx);
        goto after_24;
    // 0x80005860: nop

    after_24:
    // 0x80005864: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80005868: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000586C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80005870: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80005874: jr          $ra
    // 0x80005878: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80005878: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000587C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000587C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80005880: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005884: beq         $v0, $at, L_800058A8
    if (ctx->r2 == ctx->r1) {
        // 0x80005888: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_800058A8;
    }
    // 0x80005888: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8000588C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80005890: beq         $v0, $at, L_800058E8
    if (ctx->r2 == ctx->r1) {
        // 0x80005894: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800058E8;
    }
    // 0x80005894: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80005898: beq         $v0, $at, L_800058CC
    if (ctx->r2 == ctx->r1) {
        // 0x8000589C: lui         $t7, 0x800C
        ctx->r15 = S32(0X800C << 16);
            goto L_800058CC;
    }
    // 0x8000589C: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x800058A0: b           L_800058B0
    // 0x800058A4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
        goto L_800058B0;
    // 0x800058A4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
L_800058A8:
    // 0x800058A8: jr          $ra
    // 0x800058AC: sh          $t6, 0x118($a0)
    MEM_H(0X118, ctx->r4) = ctx->r14;
    return;
    // 0x800058AC: sh          $t6, 0x118($a0)
    MEM_H(0X118, ctx->r4) = ctx->r14;
L_800058B0:
    // 0x800058B0: lhu         $t7, -0x754($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X754);
    // 0x800058B4: nop

    // 0x800058B8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800058BC: bne         $t8, $zero, L_800058E8
    if (ctx->r24 != 0) {
        // 0x800058C0: nop
    
            goto L_800058E8;
    }
    // 0x800058C0: nop

    // 0x800058C4: jr          $ra
    // 0x800058C8: sh          $t9, 0x118($a0)
    MEM_H(0X118, ctx->r4) = ctx->r25;
    return;
    // 0x800058C8: sh          $t9, 0x118($a0)
    MEM_H(0X118, ctx->r4) = ctx->r25;
L_800058CC:
    // 0x800058CC: lw          $v0, 0x54($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X54);
    // 0x800058D0: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x800058D4: lhu         $t0, 0x32($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X32);
    // 0x800058D8: nop

    // 0x800058DC: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x800058E0: sh          $t1, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r9;
    // 0x800058E4: sh          $t2, 0x118($a0)
    MEM_H(0X118, ctx->r4) = ctx->r10;
L_800058E8:
    // 0x800058E8: jr          $ra
    // 0x800058EC: nop

    return;
    // 0x800058EC: nop

;}
RECOMP_FUNC void func_800058F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800058F0: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x800058F4: lhu         $t6, -0x16A($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X16A);
    // FALLTHROUGH FIX: func_800058F0 falls through to func_800058F8
    func_800058F8(rdram, ctx);
;}
RECOMP_FUNC void func_800058F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800058F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800058FC: beq         $t6, $zero, L_80005BF4
    if (ctx->r14 == 0) {
        // 0x80005900: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80005BF4;
    }
    // 0x80005900: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005904: jal         0x80005D20
    // 0x80005908: nop

    func_80005D20(rdram, ctx);
        goto after_0;
    // 0x80005908: nop

    after_0:
    // 0x8000590C: jal         0x80005070
    // 0x80005910: nop

    func_80005070(rdram, ctx);
        goto after_1;
    // 0x80005910: nop

    after_1:
    // 0x80005914: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x80005918: addiu       $a2, $a2, -0x16A
    ctx->r6 = ADD32(ctx->r6, -0X16A);
    // 0x8000591C: lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X0);
    // 0x80005920: nop

    // 0x80005924: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80005928: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x8000592C: beq         $at, $zero, L_80005BBC
    if (ctx->r1 == 0) {
        // 0x80005930: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80005BBC;
    }
    // 0x80005930: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80005934: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80005938: addu        $at, $at, $t7
    gpr jr_addend_80005944 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8000593C: lw          $t7, 0x6DA0($at)
    ctx->r15 = ADD32(ctx->r1, 0X6DA0);
    // 0x80005940: nop

    // 0x80005944: jr          $t7
    // 0x80005948: nop

    switch (jr_addend_80005944 >> 2) {
        case 0: goto L_8000594C; break;
        case 1: goto L_8000597C; break;
        case 2: goto L_800059AC; break;
        case 3: goto L_80005A3C; break;
        case 4: goto L_80005A94; break;
        case 5: goto L_80005AEC; break;
        case 6: goto L_80005B3C; break;
        case 7: goto L_80005B8C; break;
        default: switch_error(__func__, 0x80005944, 0x80086DA0);
    }
    // 0x80005948: nop

L_8000594C:
    // 0x8000594C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005950: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80005954: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80005958: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8000595C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80005960: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x80005964: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x80005968: nop

    // 0x8000596C: bne         $t0, $zero, L_80005C44
    if (ctx->r8 != 0) {
        // 0x80005970: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80005C44;
    }
    // 0x80005970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005974: b           L_80005C40
    // 0x80005978: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
        goto L_80005C40;
    // 0x80005978: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
L_8000597C:
    // 0x8000597C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80005980: addiu       $a0, $a0, 0x7880
    ctx->r4 = ADD32(ctx->r4, 0X7880);
    // 0x80005984: jal         0x80005588
    // 0x80005988: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80005588(rdram, ctx);
        goto after_2;
    // 0x80005988: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8000598C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005990: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80005994: addiu       $t2, $zero, 0x46
    ctx->r10 = ADD32(0, 0X46);
    // 0x80005998: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x8000599C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800059A0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800059A4: b           L_80005C40
    // 0x800059A8: sh          $t3, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r11;
        goto L_80005C40;
    // 0x800059A8: sh          $t3, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r11;
L_800059AC:
    // 0x800059AC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800059B0: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x800059B4: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x800059B8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800059BC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800059C0: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x800059C4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800059C8: nop

    // 0x800059CC: bne         $t6, $zero, L_80005C44
    if (ctx->r14 != 0) {
        // 0x800059D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80005C44;
    }
    // 0x800059D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800059D4: lhu         $t7, -0x48A0($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X48A0);
    // 0x800059D8: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800059DC: beq         $t7, $zero, L_80005A14
    if (ctx->r15 == 0) {
        // 0x800059E0: addiu       $a0, $a0, 0x78B8
        ctx->r4 = ADD32(ctx->r4, 0X78B8);
            goto L_80005A14;
    }
    // 0x800059E0: addiu       $a0, $a0, 0x78B8
    ctx->r4 = ADD32(ctx->r4, 0X78B8);
    // 0x800059E4: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800059E8: addiu       $a0, $a0, 0x78F0
    ctx->r4 = ADD32(ctx->r4, 0X78F0);
    // 0x800059EC: jal         0x80005588
    // 0x800059F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80005588(rdram, ctx);
        goto after_3;
    // 0x800059F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800059F4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800059F8: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x800059FC: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80005A00: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80005A04: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80005A08: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005A0C: b           L_80005C40
    // 0x80005A10: sh          $t9, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r25;
        goto L_80005C40;
    // 0x80005A10: sh          $t9, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r25;
L_80005A14:
    // 0x80005A14: jal         0x80005588
    // 0x80005A18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80005588(rdram, ctx);
        goto after_4;
    // 0x80005A18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80005A1C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005A20: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80005A24: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80005A28: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x80005A2C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80005A30: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005A34: b           L_80005C40
    // 0x80005A38: sh          $t1, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r9;
        goto L_80005C40;
    // 0x80005A38: sh          $t1, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r9;
L_80005A3C:
    // 0x80005A3C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005A40: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80005A44: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x80005A48: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80005A4C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80005A50: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x80005A54: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x80005A58: addiu       $a0, $a0, 0x7970
    ctx->r4 = ADD32(ctx->r4, 0X7970);
    // 0x80005A5C: bne         $t4, $zero, L_80005C44
    if (ctx->r12 != 0) {
        // 0x80005A60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80005C44;
    }
    // 0x80005A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005A64: jal         0x80005588
    // 0x80005A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80005588(rdram, ctx);
        goto after_5;
    // 0x80005A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80005A6C: jal         0x8005D200
    // 0x80005A70: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    func_8005D200(rdram, ctx);
        goto after_6;
    // 0x80005A70: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    after_6:
    // 0x80005A74: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005A78: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80005A7C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005A80: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80005A84: sh          $t5, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r13;
    // 0x80005A88: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x80005A8C: b           L_80005C40
    // 0x80005A90: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
        goto L_80005C40;
    // 0x80005A90: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
L_80005A94:
    // 0x80005A94: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005A98: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80005A9C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80005AA0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80005AA4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80005AA8: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80005AAC: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80005AB0: addiu       $a0, $a0, 0x7928
    ctx->r4 = ADD32(ctx->r4, 0X7928);
    // 0x80005AB4: bne         $t9, $zero, L_80005C44
    if (ctx->r25 != 0) {
        // 0x80005AB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80005C44;
    }
    // 0x80005AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005ABC: jal         0x80005588
    // 0x80005AC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80005588(rdram, ctx);
        goto after_7;
    // 0x80005AC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80005AC4: jal         0x8005D200
    // 0x80005AC8: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    func_8005D200(rdram, ctx);
        goto after_8;
    // 0x80005AC8: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    after_8:
    // 0x80005ACC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005AD0: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80005AD4: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80005AD8: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x80005ADC: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80005AE0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005AE4: b           L_80005C40
    // 0x80005AE8: sh          $t1, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r9;
        goto L_80005C40;
    // 0x80005AE8: sh          $t1, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r9;
L_80005AEC:
    // 0x80005AEC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005AF0: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80005AF4: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x80005AF8: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80005AFC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80005B00: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x80005B04: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x80005B08: addiu       $a0, $a0, 0x7960
    ctx->r4 = ADD32(ctx->r4, 0X7960);
    // 0x80005B0C: bne         $t4, $zero, L_80005C44
    if (ctx->r12 != 0) {
        // 0x80005B10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80005C44;
    }
    // 0x80005B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005B14: jal         0x80005588
    // 0x80005B18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80005588(rdram, ctx);
        goto after_9;
    // 0x80005B18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80005B1C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005B20: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80005B24: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x80005B28: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x80005B2C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80005B30: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005B34: b           L_80005C40
    // 0x80005B38: sh          $t6, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r14;
        goto L_80005C40;
    // 0x80005B38: sh          $t6, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r14;
L_80005B3C:
    // 0x80005B3C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005B40: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80005B44: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80005B48: nop

    // 0x80005B4C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80005B50: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80005B54: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80005B58: nop

    // 0x80005B5C: bne         $t9, $zero, L_80005C44
    if (ctx->r25 != 0) {
        // 0x80005B60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80005C44;
    }
    // 0x80005B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005B64: jal         0x80005468
    // 0x80005B68: nop

    func_80005468(rdram, ctx);
        goto after_10;
    // 0x80005B68: nop

    after_10:
    // 0x80005B6C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005B70: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80005B74: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005B78: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80005B7C: sh          $t0, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r8;
    // 0x80005B80: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x80005B84: b           L_80005C40
    // 0x80005B88: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
        goto L_80005C40;
    // 0x80005B88: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_80005B8C:
    // 0x80005B8C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005B90: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80005B94: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x80005B98: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x80005B9C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80005BA0: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x80005BA4: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x80005BA8: nop

    // 0x80005BAC: bne         $t4, $zero, L_80005C44
    if (ctx->r12 != 0) {
        // 0x80005BB0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80005C44;
    }
    // 0x80005BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005BB4: b           L_80005C40
    // 0x80005BB8: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
        goto L_80005C40;
    // 0x80005BB8: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
L_80005BBC:
    // 0x80005BBC: jal         0x80005CC8
    // 0x80005BC0: nop

    func_80005CC8(rdram, ctx);
        goto after_11;
    // 0x80005BC0: nop

    after_11:
    // 0x80005BC4: addiu       $t6, $zero, 0x200
    ctx->r14 = ADD32(0, 0X200);
    // 0x80005BC8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005BCC: sh          $t6, -0x87A($at)
    MEM_H(-0X87A, ctx->r1) = ctx->r14;
    // 0x80005BD0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005BD4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005BD8: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80005BDC: sh          $zero, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = 0;
    // 0x80005BE0: addiu       $t7, $zero, 0x78
    ctx->r15 = ADD32(0, 0X78);
    // 0x80005BE4: jal         0x80039D8C
    // 0x80005BE8: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    func_80039D8C(rdram, ctx);
        goto after_12;
    // 0x80005BE8: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    after_12:
    // 0x80005BEC: b           L_80005C44
    // 0x80005BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80005C44;
    // 0x80005BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80005BF4:
    // 0x80005BF4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80005BF8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80005BFC: lhu         $t9, -0x48A0($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X48A0);
    // 0x80005C00: lhu         $t8, -0x488A($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X488A);
    // 0x80005C04: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80005C08: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80005C0C: bne         $t0, $at, L_80005C28
    if (ctx->r8 != ctx->r1) {
        // 0x80005C10: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80005C28;
    }
    // 0x80005C10: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80005C14: jal         0x80005644
    // 0x80005C18: addiu       $a0, $a0, -0x4F28
    ctx->r4 = ADD32(ctx->r4, -0X4F28);
    func_80005644(rdram, ctx);
        goto after_13;
    // 0x80005C18: addiu       $a0, $a0, -0x4F28
    ctx->r4 = ADD32(ctx->r4, -0X4F28);
    after_13:
    // 0x80005C1C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80005C20: jal         0x80005644
    // 0x80005C24: addiu       $a0, $a0, -0x4EF8
    ctx->r4 = ADD32(ctx->r4, -0X4EF8);
    func_80005644(rdram, ctx);
        goto after_14;
    // 0x80005C24: addiu       $a0, $a0, -0x4EF8
    ctx->r4 = ADD32(ctx->r4, -0X4EF8);
    after_14:
L_80005C28:
    // 0x80005C28: jal         0x80005C50
    // 0x80005C2C: nop

    func_80005C50(rdram, ctx);
        goto after_15;
    // 0x80005C2C: nop

    after_15:
    // 0x80005C30: jal         0x80005D20
    // 0x80005C34: nop

    func_80005D20(rdram, ctx);
        goto after_16;
    // 0x80005C34: nop

    after_16:
    // 0x80005C38: jal         0x80005070
    // 0x80005C3C: nop

    func_80005070(rdram, ctx);
        goto after_17;
    // 0x80005C3C: nop

    after_17:
L_80005C40:
    // 0x80005C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80005C44:
    // 0x80005C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005C48: jr          $ra
    // 0x80005C4C: nop

    return;
    // 0x80005C4C: nop

;}
RECOMP_FUNC void func_80005C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80005C54: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80005C58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80005C5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005C60: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x80005C64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80005C68: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80005C6C: addiu       $s1, $s1, -0x798
    ctx->r17 = ADD32(ctx->r17, -0X798);
    // 0x80005C70: addiu       $s2, $zero, 0x1CC
    ctx->r18 = ADD32(0, 0X1CC);
    // 0x80005C74: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80005C78:
    // 0x80005C78: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80005C7C: mflo        $t6
    ctx->r14 = lo;
    // 0x80005C80: addu        $v0, $s1, $t6
    ctx->r2 = ADD32(ctx->r17, ctx->r14);
    // 0x80005C84: lhu         $t7, -0x188($v0)
    ctx->r15 = MEM_HU(ctx->r2, -0X188);
    // 0x80005C88: addiu       $a0, $v0, -0x1CC
    ctx->r4 = ADD32(ctx->r2, -0X1CC);
    // 0x80005C8C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80005C90: beq         $t8, $zero, L_80005CA0
    if (ctx->r24 == 0) {
        // 0x80005C94: nop
    
            goto L_80005CA0;
    }
    // 0x80005C94: nop

    // 0x80005C98: jal         0x8002DFD8
    // 0x80005C9C: nop

    func_8002DFD8(rdram, ctx);
        goto after_0;
    // 0x80005C9C: nop

    after_0:
L_80005CA0:
    // 0x80005CA0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80005CA4: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x80005CA8: bgtz        $v1, L_80005C78
    if (SIGNED(ctx->r3) > 0) {
        // 0x80005CAC: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_80005C78;
    }
    // 0x80005CAC: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x80005CB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80005CB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80005CB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80005CBC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80005CC0: jr          $ra
    // 0x80005CC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80005CC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80005CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CC8: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x80005CCC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80005CD0: addiu       $a2, $a2, -0x798
    ctx->r6 = ADD32(ctx->r6, -0X798);
    // 0x80005CD4: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80005CD8: addiu       $a3, $zero, 0x1CC
    ctx->r7 = ADD32(0, 0X1CC);
L_80005CDC:
    // 0x80005CDC: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80005CE0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80005CE4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80005CE8: mflo        $t6
    ctx->r14 = lo;
    // 0x80005CEC: addu        $a0, $a2, $t6
    ctx->r4 = ADD32(ctx->r6, ctx->r14);
    // 0x80005CF0: lhu         $t7, -0x188($a0)
    ctx->r15 = MEM_HU(ctx->r4, -0X188);
    // 0x80005CF4: addiu       $a1, $a0, -0x1CC
    ctx->r5 = ADD32(ctx->r4, -0X1CC);
    // 0x80005CF8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80005CFC: beq         $t8, $zero, L_80005D10
    if (ctx->r24 == 0) {
        // 0x80005D00: nop
    
            goto L_80005D10;
    }
    // 0x80005D00: nop

    // 0x80005D04: lw          $t9, 0x12C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X12C);
    // 0x80005D08: sw          $zero, 0xAC($a1)
    MEM_W(0XAC, ctx->r5) = 0;
    // 0x80005D0C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
L_80005D10:
    // 0x80005D10: bgtz        $v1, L_80005CDC
    if (SIGNED(ctx->r3) > 0) {
        // 0x80005D14: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80005CDC;
    }
    // 0x80005D14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80005D18: jr          $ra
    // 0x80005D1C: nop

    return;
    // 0x80005D1C: nop

;}
RECOMP_FUNC void func_80005D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D20: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005D24: addiu       $v0, $v0, 0x606
    ctx->r2 = ADD32(ctx->r2, 0X606);
    // 0x80005D28: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x80005D2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005D30: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80005D34: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80005D38: sh          $zero, -0x487E($at)
    MEM_H(-0X487E, ctx->r1) = 0;
    // 0x80005D3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005D40: sh          $zero, -0x483E($at)
    MEM_H(-0X483E, ctx->r1) = 0;
    // FALLTHROUGH FIX: func_80005D20 falls through to func_80005D44
    func_80005D44(rdram, ctx);
;}
RECOMP_FUNC void func_80005D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80005D48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005D4C: sh          $zero, -0x483C($at)
    MEM_H(-0X483C, ctx->r1) = 0;
    // 0x80005D50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80005D54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005D58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80005D5C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80005D60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005D64: jal         0x8002B180
    // 0x80005D68: sh          $zero, -0x4840($at)
    MEM_H(-0X4840, ctx->r1) = 0;
    func_8002B180(rdram, ctx);
        goto after_0;
    // 0x80005D68: sh          $zero, -0x4840($at)
    MEM_H(-0X4840, ctx->r1) = 0;
    after_0:
    // 0x80005D6C: jal         0x8002B2A4
    // 0x80005D70: nop

    func_8002B2A4(rdram, ctx);
        goto after_1;
    // 0x80005D70: nop

    after_1:
    // 0x80005D74: jal         0x8002E090
    // 0x80005D78: nop

    func_8002E090(rdram, ctx);
        goto after_2;
    // 0x80005D78: nop

    after_2:
    // 0x80005D7C: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x80005D80: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80005D84:
    // 0x80005D84: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80005D88: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x80005D8C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80005D90: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x80005D94: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80005D98: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x80005D9C: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80005DA0: addiu       $t9, $t9, -0x798
    ctx->r25 = ADD32(ctx->r25, -0X798);
    // 0x80005DA4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80005DA8: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80005DAC: lw          $s1, -0x178($v0)
    ctx->r17 = MEM_W(ctx->r2, -0X178);
    // 0x80005DB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005DB4: sw          $s1, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r17;
    // 0x80005DB8: lhu         $t0, -0x1CC($v0)
    ctx->r8 = MEM_HU(ctx->r2, -0X1CC);
    // 0x80005DBC: addiu       $s0, $v0, -0x1CC
    ctx->r16 = ADD32(ctx->r2, -0X1CC);
    // 0x80005DC0: beq         $t0, $zero, L_80005E84
    if (ctx->r8 == 0) {
        // 0x80005DC4: andi        $a0, $s2, 0xFFFF
        ctx->r4 = ctx->r18 & 0XFFFF;
            goto L_80005E84;
    }
    // 0x80005DC4: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x80005DC8: beq         $s1, $zero, L_80005E84
    if (ctx->r17 == 0) {
        // 0x80005DCC: nop
    
            goto L_80005E84;
    }
    // 0x80005DCC: nop

    // 0x80005DD0: addiu       $s0, $v0, -0x1CC
    ctx->r16 = ADD32(ctx->r2, -0X1CC);
    // 0x80005DD4: lhu         $t2, 0x44($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X44);
    // 0x80005DD8: lhu         $t1, 0x88($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X88);
    // 0x80005DDC: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80005DE0: beq         $t3, $zero, L_80005E3C
    if (ctx->r11 == 0) {
        // 0x80005DE4: sh          $t1, 0xDA($s0)
        MEM_H(0XDA, ctx->r16) = ctx->r9;
            goto L_80005E3C;
    }
    // 0x80005DE4: sh          $t1, 0xDA($s0)
    MEM_H(0XDA, ctx->r16) = ctx->r9;
    // 0x80005DE8: jal         0x8002B4E4
    // 0x80005DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002B4E4(rdram, ctx);
        goto after_3;
    // 0x80005DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80005DF0: jal         0x8004B970
    // 0x80005DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004B970(rdram, ctx);
        goto after_4;
    // 0x80005DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80005DF8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80005DFC: lw          $t4, -0x4F38($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4F38);
    // 0x80005E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80005E04: bne         $t4, $zero, L_80005E14
    if (ctx->r12 != 0) {
        // 0x80005E08: nop
    
            goto L_80005E14;
    }
    // 0x80005E08: nop

    // 0x80005E0C: jal         0x8002C928
    // 0x80005E10: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    func_8002C928(rdram, ctx);
        goto after_5;
    // 0x80005E10: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    after_5:
L_80005E14:
    // 0x80005E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80005E18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80005E1C: jal         0x80047AC0
    // 0x80005E20: andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    func_80047AC0(rdram, ctx);
        goto after_6;
    // 0x80005E20: andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    after_6:
    // 0x80005E24: sh          $zero, 0x160($s0)
    MEM_H(0X160, ctx->r16) = 0;
    // 0x80005E28: sh          $zero, 0x162($s0)
    MEM_H(0X162, ctx->r16) = 0;
    // 0x80005E2C: jal         0x8002B530
    // 0x80005E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002B530(rdram, ctx);
        goto after_7;
    // 0x80005E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80005E34: jal         0x8002BD5C
    // 0x80005E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002BD5C(rdram, ctx);
        goto after_8;
    // 0x80005E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80005E3C:
    // 0x80005E3C: jal         0x8002E2E4
    // 0x80005E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002E2E4(rdram, ctx);
        goto after_9;
    // 0x80005E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80005E44: jal         0x8002C654
    // 0x80005E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002C654(rdram, ctx);
        goto after_10;
    // 0x80005E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80005E4C: jal         0x8002C354
    // 0x80005E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002C354(rdram, ctx);
        goto after_11;
    // 0x80005E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80005E54: jal         0x8002C500
    // 0x80005E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002C500(rdram, ctx);
        goto after_12;
    // 0x80005E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80005E5C: jal         0x80028734
    // 0x80005E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028734(rdram, ctx);
        goto after_13;
    // 0x80005E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80005E64: jal         0x8002E440
    // 0x80005E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002E440(rdram, ctx);
        goto after_14;
    // 0x80005E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80005E6C: lw          $a1, 0x58($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X58);
    // 0x80005E70: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x80005E74: jal         0x8002B374
    // 0x80005E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002B374(rdram, ctx);
        goto after_15;
    // 0x80005E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80005E7C: b           L_80005E8C
    // 0x80005E80: nop

        goto L_80005E8C;
    // 0x80005E80: nop

L_80005E84:
    // 0x80005E84: jal         0x8002C4D0
    // 0x80005E88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8002C4D0(rdram, ctx);
        goto after_16;
    // 0x80005E88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
L_80005E8C:
    // 0x80005E8C: jal         0x8002E748
    // 0x80005E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002E748(rdram, ctx);
        goto after_17;
    // 0x80005E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80005E94: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80005E98: andi        $v1, $s2, 0xFFFF
    ctx->r3 = ctx->r18 & 0XFFFF;
    // 0x80005E9C: bgtz        $v1, L_80005D84
    if (SIGNED(ctx->r3) > 0) {
        // 0x80005EA0: or          $s2, $v1, $zero
        ctx->r18 = ctx->r3 | 0;
            goto L_80005D84;
    }
    // 0x80005EA0: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x80005EA4: jal         0x8002E228
    // 0x80005EA8: nop

    func_8002E228(rdram, ctx);
        goto after_18;
    // 0x80005EA8: nop

    after_18:
    // 0x80005EAC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80005EB0: addiu       $v0, $v0, -0x4F64
    ctx->r2 = ADD32(ctx->r2, -0X4F64);
    // 0x80005EB4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80005EB8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80005EBC: bne         $t6, $zero, L_80005ECC
    if (ctx->r14 != 0) {
        // 0x80005EC0: nop
    
            goto L_80005ECC;
    }
    // 0x80005EC0: nop

    // 0x80005EC4: b           L_80005F78
    // 0x80005EC8: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
        goto L_80005F78;
    // 0x80005EC8: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
L_80005ECC:
    // 0x80005ECC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80005ED0: addiu       $v1, $v1, -0x4F46
    ctx->r3 = ADD32(ctx->r3, -0X4F46);
    // 0x80005ED4: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80005ED8: nop

    // 0x80005EDC: beq         $v0, $zero, L_80005F14
    if (ctx->r2 == 0) {
        // 0x80005EE0: addiu       $at, $zero, 0x78
        ctx->r1 = ADD32(0, 0X78);
            goto L_80005F14;
    }
    // 0x80005EE0: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80005EE4: bne         $v0, $at, L_80005EF8
    if (ctx->r2 != ctx->r1) {
        // 0x80005EE8: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80005EF8;
    }
    // 0x80005EE8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80005EEC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80005EF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005EF4: sh          $t8, -0x483E($at)
    MEM_H(-0X483E, ctx->r1) = ctx->r24;
L_80005EF8:
    // 0x80005EF8: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x80005EFC: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80005F00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005F04: bne         $t0, $zero, L_80005F7C
    if (ctx->r8 != 0) {
        // 0x80005F08: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80005F7C;
    }
    // 0x80005F08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80005F0C: b           L_80005F78
    // 0x80005F10: sh          $zero, -0x4F48($at)
    MEM_H(-0X4F48, ctx->r1) = 0;
        goto L_80005F78;
    // 0x80005F10: sh          $zero, -0x4F48($at)
    MEM_H(-0X4F48, ctx->r1) = 0;
L_80005F14:
    // 0x80005F14: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80005F18: lhu         $t1, -0x87C($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X87C);
    // 0x80005F1C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80005F20: bne         $t1, $zero, L_80005F7C
    if (ctx->r9 != 0) {
        // 0x80005F24: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80005F7C;
    }
    // 0x80005F24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80005F28: lhu         $t2, -0x487A($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X487A);
    // 0x80005F2C: nop

    // 0x80005F30: bne         $t2, $zero, L_80005F7C
    if (ctx->r10 != 0) {
        // 0x80005F34: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80005F7C;
    }
    // 0x80005F34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80005F38: jal         0x8003ABCC
    // 0x80005F3C: nop

    func_8003ABCC(rdram, ctx);
        goto after_19;
    // 0x80005F3C: nop

    after_19:
    // 0x80005F40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005F44: bne         $v0, $at, L_80005F78
    if (ctx->r2 != ctx->r1) {
        // 0x80005F48: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_80005F78;
    }
    // 0x80005F48: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80005F4C: addiu       $v1, $v1, -0x483A
    ctx->r3 = ADD32(ctx->r3, -0X483A);
    // 0x80005F50: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80005F54: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80005F58: bne         $v0, $zero, L_80005F74
    if (ctx->r2 != 0) {
        // 0x80005F5C: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_80005F74;
    }
    // 0x80005F5C: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80005F60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005F64: sh          $t3, -0x483E($at)
    MEM_H(-0X483E, ctx->r1) = ctx->r11;
    // 0x80005F68: addiu       $t4, $zero, 0x77
    ctx->r12 = ADD32(0, 0X77);
    // 0x80005F6C: b           L_80005F78
    // 0x80005F70: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
        goto L_80005F78;
    // 0x80005F70: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_80005F74:
    // 0x80005F74: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
L_80005F78:
    // 0x80005F78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80005F7C:
    // 0x80005F7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80005F80: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80005F84: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80005F88: jr          $ra
    // 0x80005F8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80005F8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80005F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005F90: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80005F94: lh          $v0, -0x4F3C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4F3C);
    // 0x80005F98: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80005F9C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // FALLTHROUGH FIX: func_80005F90 falls through to func_80005FA0
    func_80005FA0(rdram, ctx);
;}
RECOMP_FUNC void func_80005FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // FALLTHROUGH FIX: recompute div $zero, $v0, $at since hi/lo are local vars
    if (ctx->r1 != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1))); }
    // 0x80005FA0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80005FA4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80005FA8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80005FAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005FB0: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x80005FB4: addiu       $s2, $s2, -0x4500
    ctx->r18 = ADD32(ctx->r18, -0X4500);
    // 0x80005FB8: lui         $s0, 0x8007
    ctx->r16 = S32(0X8007 << 16);
    // 0x80005FBC: lw          $t6, 0x20($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X20);
    // 0x80005FC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80005FC4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80005FC8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80005FCC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80005FD0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80005FD4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80005FD8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80005FDC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80005FE0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80005FE4: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80005FE8: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x80005FEC: lui         $s4, 0x4800
    ctx->r20 = S32(0X4800 << 16);
    // 0x80005FF0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80005FF4: addiu       $s1, $s1, -0x16D8
    ctx->r17 = ADD32(ctx->r17, -0X16D8);
    // 0x80005FF8: ori         $s4, $s4, 0x2CE6
    ctx->r20 = ctx->r20 | 0X2CE6;
    // 0x80005FFC: addiu       $s5, $zero, 0x4000
    ctx->r21 = ADD32(0, 0X4000);
    // 0x80006000: addiu       $s6, $zero, 0x510
    ctx->r22 = ADD32(0, 0X510);
    // 0x80006004: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80006008: addiu       $fp, $zero, 0x100
    ctx->r30 = ADD32(0, 0X100);
    // 0x8000600C: mfhi        $t7
    ctx->r15 = hi;
    // 0x80006010: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80006014: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80006018: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8000601C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80006020: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80006024: lhu         $t2, 0x79A0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X79A0);
    // 0x80006028: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x8000602C: lw          $s0, 0x7AEC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7AEC);
    // 0x80006030: sh          $t2, 0x6640($at)
    MEM_H(0X6640, ctx->r1) = ctx->r10;
    // 0x80006034: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80006038: nop

    // 0x8000603C: beq         $t3, $zero, L_800060CC
    if (ctx->r11 == 0) {
        // 0x80006040: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_800060CC;
    }
    // 0x80006040: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_80006044:
    // 0x80006044: jal         0x80039D18
    // 0x80006048: nop

    func_80039D18(rdram, ctx);
        goto after_0;
    // 0x80006048: nop

    after_0:
    // 0x8000604C: sw          $v0, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r2;
    // 0x80006050: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80006054: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80006058: bne         $s4, $t4, L_80006068
    if (ctx->r20 != ctx->r12) {
        // 0x8000605C: sw          $t4, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r12;
            goto L_80006068;
    }
    // 0x8000605C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80006060: b           L_80006070
    // 0x80006064: sw          $s5, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r21;
        goto L_80006070;
    // 0x80006064: sw          $s5, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r21;
L_80006068:
    // 0x80006068: sw          $s7, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r23;
    // 0x8000606C: sw          $fp, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r30;
L_80006070:
    // 0x80006070: lhu         $t6, 0x4($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X4);
    // 0x80006074: lhu         $t7, 0x8($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X8);
    // 0x80006078: lhu         $t1, 0x6($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X6);
    // 0x8000607C: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80006080: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80006084: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
    // 0x80006088: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x8000608C: sh          $t9, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r25;
    // 0x80006090: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x80006094: sh          $t2, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r10;
    // 0x80006098: sw          $s6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r22;
    // 0x8000609C: jal         0x8002EC64
    // 0x800060A0: sh          $t0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r8;
    func_8002EC64(rdram, ctx);
        goto after_1;
    // 0x800060A0: sh          $t0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r8;
    after_1:
    // 0x800060A4: sw          $v0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r2;
    // 0x800060A8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800060AC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800060B0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800060B4: sll         $t4, $s3, 16
    ctx->r12 = S32(ctx->r19 << 16);
    // 0x800060B8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800060BC: sra         $s3, $t4, 16
    ctx->r19 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800060C0: bne         $t6, $zero, L_80006044
    if (ctx->r14 != 0) {
        // 0x800060C4: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80006044;
    }
    // 0x800060C4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800060C8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_800060CC:
    // 0x800060CC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800060D0: sh          $s3, -0x83A($at)
    MEM_H(-0X83A, ctx->r1) = ctx->r19;
    // 0x800060D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800060D8: sw          $t7, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r15;
    // 0x800060DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800060E0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800060E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800060E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800060EC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800060F0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800060F4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800060F8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800060FC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80006100: jr          $ra
    // 0x80006104: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80006104: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80006108: nop

    // 0x8000610C: nop

;}
RECOMP_FUNC void func_80006110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006110: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80006114: lhu         $v0, -0x87C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X87C);
    // 0x80006118: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000611C: bne         $v0, $at, L_80006134
    if (ctx->r2 != ctx->r1) {
        // 0x80006120: lui         $t6, 0x8008
        ctx->r14 = S32(0X8008 << 16);
            goto L_80006134;
    }
    // 0x80006120: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80006124: lw          $t6, -0x7C20($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C20);
    // 0x80006128: nop

    // 0x8000612C: slti        $at, $t6, 0x29
    ctx->r1 = SIGNED(ctx->r14) < 0X29 ? 1 : 0;
    // 0x80006130: beq         $at, $zero, L_80006150
    if (ctx->r1 == 0) {
        // 0x80006134: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80006150;
    }
L_80006134:
    // 0x80006134: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80006138: bne         $v0, $at, L_8000617C
    if (ctx->r2 != ctx->r1) {
            // 0x8000613C: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    func_8000617C(rdram, ctx);
    return;
    }
    // 0x8000613C: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80006140: lw          $t7, -0x7C20($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C20);
    // 0x80006144: nop

    // 0x80006148: slti        $at, $t7, 0x3B
    ctx->r1 = SIGNED(ctx->r15) < 0X3B ? 1 : 0;
    // 0x8000614C: bne         $at, $zero, L_8000617C
    if (ctx->r1 != 0) {
            // 0x80006150: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    func_8000617C(rdram, ctx);
    return;
    }
L_80006150:
    // 0x80006150: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006154: sw          $zero, -0x4F38($at)
    MEM_W(-0X4F38, ctx->r1) = 0;
    // 0x80006158: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000615C: sw          $zero, -0x4F34($at)
    MEM_W(-0X4F34, ctx->r1) = 0;
    // 0x80006160: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006164: sw          $zero, -0x4F30($at)
    MEM_W(-0X4F30, ctx->r1) = 0;
    // 0x80006168: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000616C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80006170: sh          $t8, -0x4F2C($at)
    MEM_H(-0X4F2C, ctx->r1) = ctx->r24;
    // 0x80006174: jr          $ra
    // 0x80006178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80006178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8000617C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000617C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80006180: jr          $ra
    // 0x80006184: nop

    return;
    // 0x80006184: nop

;}
RECOMP_FUNC void func_80006188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006188: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000618C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80006190: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80006194: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006198: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x8000619C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800061A0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x800061A4: addiu       $s1, $s1, -0x798
    ctx->r17 = ADD32(ctx->r17, -0X798);
    // 0x800061A8: addiu       $s2, $zero, 0x1CC
    ctx->r18 = ADD32(0, 0X1CC);
    // 0x800061AC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800061B0:
    // 0x800061B0: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800061B4: mflo        $t6
    ctx->r14 = lo;
    // 0x800061B8: addu        $v0, $s1, $t6
    ctx->r2 = ADD32(ctx->r17, ctx->r14);
    // 0x800061BC: lhu         $t7, -0x188($v0)
    ctx->r15 = MEM_HU(ctx->r2, -0X188);
    // 0x800061C0: addiu       $a0, $v0, -0x1CC
    ctx->r4 = ADD32(ctx->r2, -0X1CC);
    // 0x800061C4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800061C8: beq         $t8, $zero, L_800061E4
    if (ctx->r24 == 0) {
        // 0x800061CC: nop
    
            goto L_800061E4;
    }
    // 0x800061CC: nop

    // 0x800061D0: lw          $t9, 0xAC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XAC);
    // 0x800061D4: nop

    // 0x800061D8: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x800061DC: jal         0x8002DFD8
    // 0x800061E0: sw          $t0, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->r8;
    func_8002DFD8(rdram, ctx);
        goto after_0;
    // 0x800061E0: sw          $t0, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->r8;
    after_0:
L_800061E4:
    // 0x800061E4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800061E8: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x800061EC: bgtz        $v1, L_800061B0
    if (SIGNED(ctx->r3) > 0) {
        // 0x800061F0: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_800061B0;
    }
    // 0x800061F0: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800061F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800061F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800061FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80006200: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80006204: jr          $ra
    // 0x80006208: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80006208: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000620C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000620C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006210: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006214: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80006218: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000621C: sh          $t6, -0x800($at)
    MEM_H(-0X800, ctx->r1) = ctx->r14;
    // 0x80006220: jal         0x80067BB4
    // 0x80006224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067BB4(rdram, ctx);
        goto after_0;
    // 0x80006224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80006228: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8000622C: jal         0x80000A80
    // 0x80006230: addiu       $a0, $a0, -0x33E4
    ctx->r4 = ADD32(ctx->r4, -0X33E4);
    func_80000A80(rdram, ctx);
        goto after_1;
    // 0x80006230: addiu       $a0, $a0, -0x33E4
    ctx->r4 = ADD32(ctx->r4, -0X33E4);
    after_1:
    // 0x80006234: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80006238: jal         0x80000A80
    // 0x8000623C: addiu       $a0, $a0, -0x33C0
    ctx->r4 = ADD32(ctx->r4, -0X33C0);
    func_80000A80(rdram, ctx);
        goto after_2;
    // 0x8000623C: addiu       $a0, $a0, -0x33C0
    ctx->r4 = ADD32(ctx->r4, -0X33C0);
    after_2:
    // 0x80006240: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80006244: jal         0x80000A80
    // 0x80006248: addiu       $a0, $a0, -0x3394
    ctx->r4 = ADD32(ctx->r4, -0X3394);
    func_80000A80(rdram, ctx);
        goto after_3;
    // 0x80006248: addiu       $a0, $a0, -0x3394
    ctx->r4 = ADD32(ctx->r4, -0X3394);
    after_3:
    // 0x8000624C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80006250: sh          $zero, -0x800($at)
    MEM_H(-0X800, ctx->r1) = 0;
    // 0x80006254: jal         0x80067BB4
    // 0x80006258: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80067BB4(rdram, ctx);
        goto after_4;
    // 0x80006258: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8000625C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006264: jr          $ra
    // 0x80006268: nop

    return;
    // 0x80006268: nop

;}
RECOMP_FUNC void func_8000626C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000626C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80006270: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80006274: lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // 0x80006278: addiu       $s2, $s2, 0x7B90
    ctx->r18 = ADD32(ctx->r18, 0X7B90);
    // 0x8000627C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80006280: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80006284: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80006288: beq         $t6, $zero, L_800062B0
    if (ctx->r14 == 0) {
        // 0x8000628C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800062B0;
    }
    // 0x8000628C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006290: jal         0x8000620C
    // 0x80006294: nop

    func_8000620C(rdram, ctx);
        goto after_0;
    // 0x80006294: nop

    after_0:
    // 0x80006298: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000629C: addiu       $v1, $v1, -0x4470
    ctx->r3 = ADD32(ctx->r3, -0X4470);
    // 0x800062A0: addiu       $t7, $zero, 0x12C
    ctx->r15 = ADD32(0, 0X12C);
    // 0x800062A4: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x800062A8: b           L_8000648C
    // 0x800062AC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
        goto L_8000648C;
    // 0x800062AC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800062B0:
    // 0x800062B0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800062B4: addiu       $v1, $v1, -0x4470
    ctx->r3 = ADD32(ctx->r3, -0X4470);
    // 0x800062B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800062BC: nop

    // 0x800062C0: blez        $v0, L_800062D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800062C4: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_800062D0;
    }
    // 0x800062C4: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800062C8: b           L_8000648C
    // 0x800062CC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_8000648C;
    // 0x800062CC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_800062D0:
    // 0x800062D0: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x800062D4: addiu       $s0, $s0, -0x818
    ctx->r16 = ADD32(ctx->r16, -0X818);
    // 0x800062D8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800062DC: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800062E0: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800062E4: addiu       $s1, $s1, -0x486E
    ctx->r17 = ADD32(ctx->r17, -0X486E);
    // 0x800062E8: addiu       $v1, $v1, 0x614
    ctx->r3 = ADD32(ctx->r3, 0X614);
    // 0x800062EC: addiu       $v0, $v0, 0x618
    ctx->r2 = ADD32(ctx->r2, 0X618);
    // 0x800062F0: sh          $zero, 0x26($s0)
    MEM_H(0X26, ctx->r16) = 0;
    // 0x800062F4: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x800062F8: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    // 0x800062FC: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80006300: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x80006304: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80006308: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x8000630C: jal         0x80039D84
    // 0x80006310: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    func_80039D84(rdram, ctx);
        goto after_1;
    // 0x80006310: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    after_1:
    // 0x80006314: jal         0x80030494
    // 0x80006318: nop

    func_80030494(rdram, ctx);
        goto after_2;
    // 0x80006318: nop

    after_2:
    // 0x8000631C: jal         0x80039D8C
    // 0x80006320: nop

    func_80039D8C(rdram, ctx);
        goto after_3;
    // 0x80006320: nop

    after_3:
    // 0x80006324: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80006328: jal         0x80067B38
    // 0x8000632C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80067B38(rdram, ctx);
        goto after_4;
    // 0x8000632C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x80006330: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80006334: jal         0x80067B28
    // 0x80006338: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80067B28(rdram, ctx);
        goto after_5;
    // 0x80006338: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x8000633C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006340: jal         0x8005CB90
    // 0x80006344: sw          $zero, -0x4F38($at)
    MEM_W(-0X4F38, ctx->r1) = 0;
    func_8005CB90(rdram, ctx);
        goto after_6;
    // 0x80006344: sw          $zero, -0x4F38($at)
    MEM_W(-0X4F38, ctx->r1) = 0;
    after_6:
    // 0x80006348: jal         0x80017A30
    // 0x8000634C: nop

    func_80017A30(rdram, ctx);
        goto after_7;
    // 0x8000634C: nop

    after_7:
    // 0x80006350: jal         0x8004D2A0
    // 0x80006354: nop

    func_8004D2A0(rdram, ctx);
        goto after_8;
    // 0x80006354: nop

    after_8:
    // 0x80006358: jal         0x8000AF2C
    // 0x8000635C: nop

    func_8000AF2C(rdram, ctx);
        goto after_9;
    // 0x8000635C: nop

    after_9:
    // 0x80006360: jal         0x80031DB4
    // 0x80006364: nop

    func_80031DB4(rdram, ctx);
        goto after_10;
    // 0x80006364: nop

    after_10:
    // 0x80006368: jal         0x8003D188
    // 0x8000636C: nop

    func_8003D188(rdram, ctx);
        goto after_11;
    // 0x8000636C: nop

    after_11:
    // 0x80006370: jal         0x80046EE8
    // 0x80006374: nop

    func_80046EE8(rdram, ctx);
        goto after_12;
    // 0x80006374: nop

    after_12:
    // 0x80006378: jal         0x8004F688
    // 0x8000637C: nop

    func_8004F688(rdram, ctx);
        goto after_13;
    // 0x8000637C: nop

    after_13:
    // 0x80006380: jal         0x80042F80
    // 0x80006384: nop

    func_80042F80(rdram, ctx);
        goto after_14;
    // 0x80006384: nop

    after_14:
    // 0x80006388: jal         0x8001EA10
    // 0x8000638C: nop

    func_8001EA10(rdram, ctx);
        goto after_15;
    // 0x8000638C: nop

    after_15:
    // 0x80006390: jal         0x8002E60C
    // 0x80006394: nop

    func_8002E60C(rdram, ctx);
        goto after_16;
    // 0x80006394: nop

    after_16:
    // 0x80006398: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8000639C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800063A0: addiu       $a1, $a1, -0x4F28
    ctx->r5 = ADD32(ctx->r5, -0X4F28);
    // 0x800063A4: jal         0x80005588
    // 0x800063A8: addiu       $a0, $a0, 0x7B00
    ctx->r4 = ADD32(ctx->r4, 0X7B00);
    func_80005588(rdram, ctx);
        goto after_17;
    // 0x800063A8: addiu       $a0, $a0, 0x7B00
    ctx->r4 = ADD32(ctx->r4, 0X7B00);
    after_17:
    // 0x800063AC: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800063B0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800063B4: addiu       $a1, $a1, -0x4EF8
    ctx->r5 = ADD32(ctx->r5, -0X4EF8);
    // 0x800063B8: jal         0x80005588
    // 0x800063BC: addiu       $a0, $a0, 0x7820
    ctx->r4 = ADD32(ctx->r4, 0X7820);
    func_80005588(rdram, ctx);
        goto after_18;
    // 0x800063BC: addiu       $a0, $a0, 0x7820
    ctx->r4 = ADD32(ctx->r4, 0X7820);
    after_18:
    // 0x800063C0: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x800063C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800063C8: sh          $t9, -0x486C($at)
    MEM_H(-0X486C, ctx->r1) = ctx->r25;
    // 0x800063CC: addiu       $t0, $zero, 0x3FF
    ctx->r8 = ADD32(0, 0X3FF);
    // 0x800063D0: jal         0x8005EEA8
    // 0x800063D4: sh          $t0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r8;
    func_8005EEA8(rdram, ctx);
        goto after_19;
    // 0x800063D4: sh          $t0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r8;
    after_19:
    // 0x800063D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800063DC: sh          $zero, -0x4976($at)
    MEM_H(-0X4976, ctx->r1) = 0;
    // 0x800063E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800063E4: sw          $zero, -0x47E4($at)
    MEM_W(-0X47E4, ctx->r1) = 0;
    // 0x800063E8: jal         0x8002F674
    // 0x800063EC: addiu       $a0, $zero, 0x40F
    ctx->r4 = ADD32(0, 0X40F);
    func_8002F674(rdram, ctx);
        goto after_20;
    // 0x800063EC: addiu       $a0, $zero, 0x40F
    ctx->r4 = ADD32(0, 0X40F);
    after_20:
    // 0x800063F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800063F4: sh          $t1, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r9;
    // 0x800063F8: jal         0x80067BB4
    // 0x800063FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067BB4(rdram, ctx);
        goto after_21;
    // 0x800063FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_21:
    // 0x80006400: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80006404: lhu         $a1, 0x6640($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6640);
    // 0x80006408: jal         0x800330B4
    // 0x8000640C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800330B4(rdram, ctx);
        goto after_22;
    // 0x8000640C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_22:
    // 0x80006410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006414: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006418: sh          $v0, -0x4F64($at)
    MEM_H(-0X4F64, ctx->r1) = ctx->r2;
    // 0x8000641C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80006420: addiu       $t2, $zero, 0x310
    ctx->r10 = ADD32(0, 0X310);
    // 0x80006424: sh          $t2, -0x87A($at)
    MEM_H(-0X87A, ctx->r1) = ctx->r10;
    // 0x80006428: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x8000642C: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80006430: addiu       $s0, $s0, -0x798
    ctx->r16 = ADD32(ctx->r16, -0X798);
    // 0x80006434: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80006438: lui         $s2, 0x64
    ctx->r18 = S32(0X64 << 16);
L_8000643C:
    // 0x8000643C: lhu         $t3, 0x44($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X44);
    // 0x80006440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006444: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80006448: beq         $t4, $zero, L_80006464
    if (ctx->r12 == 0) {
        // 0x8000644C: nop
    
            goto L_80006464;
    }
    // 0x8000644C: nop

    // 0x80006450: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80006454: sw          $zero, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = 0;
    // 0x80006458: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x8000645C: jal         0x8000587C
    // 0x80006460: sw          $t5, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r13;
    func_8000587C(rdram, ctx);
        goto after_23;
    // 0x80006460: sw          $t5, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r13;
    after_23:
L_80006464:
    // 0x80006464: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80006468: andi        $t6, $s1, 0xFFFF
    ctx->r14 = ctx->r17 & 0XFFFF;
    // 0x8000646C: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80006470: bgtz        $t6, L_8000643C
    if (SIGNED(ctx->r14) > 0) {
        // 0x80006474: addiu       $s0, $s0, 0x1CC
        ctx->r16 = ADD32(ctx->r16, 0X1CC);
            goto L_8000643C;
    }
    // 0x80006474: addiu       $s0, $s0, 0x1CC
    ctx->r16 = ADD32(ctx->r16, 0X1CC);
    // 0x80006478: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000647C: jal         0x8005D1D0
    // 0x80006480: sh          $zero, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = 0;
    func_8005D1D0(rdram, ctx);
        goto after_24;
    // 0x80006480: sh          $zero, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = 0;
    after_24:
    // 0x80006484: jal         0x8005D2C0
    // 0x80006488: nop

    func_8005D2C0(rdram, ctx);
        goto after_25;
    // 0x80006488: nop

    after_25:
L_8000648C:
    // 0x8000648C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80006490: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006494: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80006498: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000649C: jr          $ra
    // 0x800064A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800064A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800064A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800064A4: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x800064A8: lhu         $t6, -0x16A($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X16A);
    // FALLTHROUGH FIX: func_800064A4 falls through to func_800064AC
    func_800064AC(rdram, ctx);
;}
RECOMP_FUNC void func_800064AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800064AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800064B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800064B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800064B8: beq         $t6, $zero, L_80006678
    if (ctx->r14 == 0) {
        // 0x800064BC: sw          $zero, -0x7C20($at)
        MEM_W(-0X7C20, ctx->r1) = 0;
            goto L_80006678;
    }
    // 0x800064BC: sw          $zero, -0x7C20($at)
    MEM_W(-0X7C20, ctx->r1) = 0;
    // 0x800064C0: jal         0x80005D20
    // 0x800064C4: nop

    func_80005D20(rdram, ctx);
        goto after_0;
    // 0x800064C4: nop

    after_0:
    // 0x800064C8: jal         0x80006814
    // 0x800064CC: nop

    func_80006814(rdram, ctx);
        goto after_1;
    // 0x800064CC: nop

    after_1:
    // 0x800064D0: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x800064D4: addiu       $a2, $a2, -0x16A
    ctx->r6 = ADD32(ctx->r6, -0X16A);
    // 0x800064D8: lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X0);
    // 0x800064DC: nop

    // 0x800064E0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x800064E4: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x800064E8: beq         $at, $zero, L_80006640
    if (ctx->r1 == 0) {
        // 0x800064EC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80006640;
    }
    // 0x800064EC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800064F0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800064F4: addu        $at, $at, $t7
    gpr jr_addend_80006500 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800064F8: lw          $t7, 0x6DC0($at)
    ctx->r15 = ADD32(ctx->r1, 0X6DC0);
    // 0x800064FC: nop

    // 0x80006500: jr          $t7
    // 0x80006504: nop

    switch (jr_addend_80006500 >> 2) {
        case 0: goto L_80006508; break;
        case 1: goto L_80006538; break;
        case 2: goto L_80006568; break;
        case 3: goto L_800065B8; break;
        case 4: goto L_80006640; break;
        case 5: goto L_80006640; break;
        case 6: goto L_80006640; break;
        case 7: goto L_80006610; break;
        default: switch_error(__func__, 0x80006500, 0x80086DC0);
    }
    // 0x80006504: nop

L_80006508:
    // 0x80006508: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000650C: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80006510: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80006514: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80006518: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8000651C: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x80006520: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x80006524: nop

    // 0x80006528: bne         $t0, $zero, L_800066C8
    if (ctx->r8 != 0) {
        // 0x8000652C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800066C8;
    }
    // 0x8000652C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006530: b           L_800066C4
    // 0x80006534: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
        goto L_800066C4;
    // 0x80006534: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
L_80006538:
    // 0x80006538: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8000653C: addiu       $a0, $a0, 0x7880
    ctx->r4 = ADD32(ctx->r4, 0X7880);
    // 0x80006540: jal         0x80005588
    // 0x80006544: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80005588(rdram, ctx);
        goto after_2;
    // 0x80006544: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80006548: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000654C: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80006550: addiu       $t2, $zero, 0x46
    ctx->r10 = ADD32(0, 0X46);
    // 0x80006554: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x80006558: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8000655C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80006560: b           L_800066C4
    // 0x80006564: sh          $t3, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r11;
        goto L_800066C4;
    // 0x80006564: sh          $t3, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r11;
L_80006568:
    // 0x80006568: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000656C: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80006570: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x80006574: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80006578: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8000657C: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x80006580: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80006584: addiu       $a0, $a0, 0x78B8
    ctx->r4 = ADD32(ctx->r4, 0X78B8);
    // 0x80006588: bne         $t6, $zero, L_800066C8
    if (ctx->r14 != 0) {
        // 0x8000658C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800066C8;
    }
    // 0x8000658C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006590: jal         0x80005588
    // 0x80006594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80005588(rdram, ctx);
        goto after_3;
    // 0x80006594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80006598: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000659C: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x800065A0: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x800065A4: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800065A8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800065AC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800065B0: b           L_800066C4
    // 0x800065B4: sh          $t8, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r24;
        goto L_800066C4;
    // 0x800065B4: sh          $t8, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r24;
L_800065B8:
    // 0x800065B8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800065BC: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x800065C0: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800065C4: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800065C8: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800065CC: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x800065D0: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x800065D4: addiu       $a0, $a0, 0x7970
    ctx->r4 = ADD32(ctx->r4, 0X7970);
    // 0x800065D8: bne         $t1, $zero, L_800066C8
    if (ctx->r9 != 0) {
        // 0x800065DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800066C8;
    }
    // 0x800065DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800065E0: jal         0x80005588
    // 0x800065E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80005588(rdram, ctx);
        goto after_4;
    // 0x800065E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800065E8: jal         0x8005D200
    // 0x800065EC: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    func_8005D200(rdram, ctx);
        goto after_5;
    // 0x800065EC: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    after_5:
    // 0x800065F0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800065F4: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x800065F8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800065FC: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80006600: sh          $t2, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r10;
    // 0x80006604: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x80006608: b           L_800066C4
    // 0x8000660C: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
        goto L_800066C4;
    // 0x8000660C: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
L_80006610:
    // 0x80006610: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80006614: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80006618: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x8000661C: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80006620: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80006624: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x80006628: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8000662C: nop

    // 0x80006630: bne         $t6, $zero, L_800066C8
    if (ctx->r14 != 0) {
        // 0x80006634: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800066C8;
    }
    // 0x80006634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006638: b           L_800066C4
    // 0x8000663C: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_800066C4;
    // 0x8000663C: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80006640:
    // 0x80006640: jal         0x80005CC8
    // 0x80006644: nop

    func_80005CC8(rdram, ctx);
        goto after_6;
    // 0x80006644: nop

    after_6:
    // 0x80006648: addiu       $t8, $zero, 0x200
    ctx->r24 = ADD32(0, 0X200);
    // 0x8000664C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80006650: sh          $t8, -0x87A($at)
    MEM_H(-0X87A, ctx->r1) = ctx->r24;
    // 0x80006654: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80006658: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000665C: addiu       $v0, $v0, -0x172
    ctx->r2 = ADD32(ctx->r2, -0X172);
    // 0x80006660: sh          $zero, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = 0;
    // 0x80006664: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x80006668: jal         0x80039D8C
    // 0x8000666C: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    func_80039D8C(rdram, ctx);
        goto after_7;
    // 0x8000666C: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    after_7:
    // 0x80006670: b           L_800066C8
    // 0x80006674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800066C8;
    // 0x80006674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006678:
    // 0x80006678: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8000667C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80006680: lhu         $t1, -0x48A0($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X48A0);
    // 0x80006684: lhu         $t0, -0x488A($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X488A);
    // 0x80006688: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x8000668C: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80006690: bne         $t2, $at, L_800066AC
    if (ctx->r10 != ctx->r1) {
        // 0x80006694: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800066AC;
    }
    // 0x80006694: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006698: jal         0x80005644
    // 0x8000669C: addiu       $a0, $a0, -0x4F28
    ctx->r4 = ADD32(ctx->r4, -0X4F28);
    func_80005644(rdram, ctx);
        goto after_8;
    // 0x8000669C: addiu       $a0, $a0, -0x4F28
    ctx->r4 = ADD32(ctx->r4, -0X4F28);
    after_8:
    // 0x800066A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800066A4: jal         0x80005644
    // 0x800066A8: addiu       $a0, $a0, -0x4EF8
    ctx->r4 = ADD32(ctx->r4, -0X4EF8);
    func_80005644(rdram, ctx);
        goto after_9;
    // 0x800066A8: addiu       $a0, $a0, -0x4EF8
    ctx->r4 = ADD32(ctx->r4, -0X4EF8);
    after_9:
L_800066AC:
    // 0x800066AC: jal         0x80006188
    // 0x800066B0: nop

    func_80006188(rdram, ctx);
        goto after_10;
    // 0x800066B0: nop

    after_10:
    // 0x800066B4: jal         0x80005D20
    // 0x800066B8: nop

    func_80005D20(rdram, ctx);
        goto after_11;
    // 0x800066B8: nop

    after_11:
    // 0x800066BC: jal         0x80006814
    // 0x800066C0: nop

    func_80006814(rdram, ctx);
        goto after_12;
    // 0x800066C0: nop

    after_12:
L_800066C4:
    // 0x800066C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800066C8:
    // 0x800066C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800066CC: jr          $ra
    // 0x800066D0: nop

    return;
    // 0x800066D0: nop

;}
RECOMP_FUNC void func_800066D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800066D4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800066D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800066DC: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800066E0: addiu       $s2, $s2, -0x4500
    ctx->r18 = ADD32(ctx->r18, -0X4500);
    // 0x800066E4: lw          $t6, 0x20($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X20);
    // 0x800066E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800066EC: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x800066F0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800066F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800066F8: addiu       $s0, $v0, 0x7B94
    ctx->r16 = ADD32(ctx->r2, 0X7B94);
    // 0x800066FC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80006700: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80006704: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80006708: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000670C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80006710: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80006714: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80006718: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000671C: sh          $t7, 0x6640($at)
    MEM_H(0X6640, ctx->r1) = ctx->r15;
    // 0x80006720: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80006724: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80006728: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x8000672C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80006730: beq         $t8, $zero, L_800067D4
    if (ctx->r24 == 0) {
        // 0x80006734: addiu       $s1, $s1, -0x16D8
        ctx->r17 = ADD32(ctx->r17, -0X16D8);
            goto L_800067D4;
    }
    // 0x80006734: addiu       $s1, $s1, -0x16D8
    ctx->r17 = ADD32(ctx->r17, -0X16D8);
    // 0x80006738: lui         $s4, 0x4800
    ctx->r20 = S32(0X4800 << 16);
    // 0x8000673C: ori         $s4, $s4, 0x2CE6
    ctx->r20 = ctx->r20 | 0X2CE6;
    // 0x80006740: addiu       $fp, $zero, 0x100
    ctx->r30 = ADD32(0, 0X100);
    // 0x80006744: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80006748: addiu       $s6, $zero, 0x510
    ctx->r22 = ADD32(0, 0X510);
    // 0x8000674C: addiu       $s5, $zero, 0x4000
    ctx->r21 = ADD32(0, 0X4000);
L_80006750:
    // 0x80006750: jal         0x80039D18
    // 0x80006754: nop

    func_80039D18(rdram, ctx);
        goto after_0;
    // 0x80006754: nop

    after_0:
    // 0x80006758: sw          $v0, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r2;
    // 0x8000675C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80006760: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80006764: bne         $s4, $t9, L_80006774
    if (ctx->r20 != ctx->r25) {
        // 0x80006768: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_80006774;
    }
    // 0x80006768: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8000676C: b           L_8000677C
    // 0x80006770: sw          $s5, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r21;
        goto L_8000677C;
    // 0x80006770: sw          $s5, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r21;
L_80006774:
    // 0x80006774: sw          $s7, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r23;
    // 0x80006778: sw          $fp, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r30;
L_8000677C:
    // 0x8000677C: lhu         $t1, 0x4($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X4);
    // 0x80006780: lhu         $t2, 0x8($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X8);
    // 0x80006784: lhu         $t6, 0x6($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X6);
    // 0x80006788: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x8000678C: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
    // 0x80006790: lh          $t4, 0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4);
    // 0x80006794: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80006798: sh          $t4, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r12;
    // 0x8000679C: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800067A0: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x800067A4: sw          $s6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r22;
    // 0x800067A8: jal         0x8002EC64
    // 0x800067AC: sh          $t5, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r13;
    func_8002EC64(rdram, ctx);
        goto after_1;
    // 0x800067AC: sh          $t5, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r13;
    after_1:
    // 0x800067B0: sw          $v0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r2;
    // 0x800067B4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800067B8: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x800067BC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800067C0: sll         $t9, $s3, 16
    ctx->r25 = S32(ctx->r19 << 16);
    // 0x800067C4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800067C8: sra         $s3, $t9, 16
    ctx->r19 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800067CC: bne         $t1, $zero, L_80006750
    if (ctx->r9 != 0) {
        // 0x800067D0: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80006750;
    }
    // 0x800067D0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_800067D4:
    // 0x800067D4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800067D8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800067DC: sh          $s3, -0x83A($at)
    MEM_H(-0X83A, ctx->r1) = ctx->r19;
    // 0x800067E0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800067E4: sw          $t2, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r10;
    // 0x800067E8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800067EC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800067F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800067F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800067F8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800067FC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80006800: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80006804: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80006808: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000680C: jr          $ra
    // 0x80006810: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80006810: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80006814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006814: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80006818: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000681C: lw          $t6, -0x44E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44E0);
    // 0x80006820: lhu         $v0, -0x16A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X16A);
    // FALLTHROUGH FIX: func_80006814 falls through to func_80006824
    func_80006824(rdram, ctx);
;}
RECOMP_FUNC void func_80006824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006824: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80006828: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000682C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80006830: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80006834: beq         $v0, $zero, L_800068DC
    if (ctx->r2 == 0) {
        // 0x80006838: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_800068DC;
    }
    // 0x80006838: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8000683C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80006840: bne         $v0, $at, L_800068CC
    if (ctx->r2 != ctx->r1) {
        // 0x80006844: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800068CC;
    }
    // 0x80006844: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80006848: addiu       $t7, $zero, 0xB4
    ctx->r15 = ADD32(0, 0XB4);
    // 0x8000684C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80006850: addiu       $v1, $v1, -0x48A0
    ctx->r3 = ADD32(ctx->r3, -0X48A0);
    // 0x80006854: sh          $t7, -0x172($at)
    MEM_H(-0X172, ctx->r1) = ctx->r15;
    // 0x80006858: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x8000685C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80006860: lw          $s0, -0x4F38($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X4F38);
    // 0x80006864: bne         $t8, $zero, L_80006874
    if (ctx->r24 != 0) {
        // 0x80006868: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80006874;
    }
    // 0x80006868: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000686C: b           L_80006894
    // 0x80006870: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
        goto L_80006894;
    // 0x80006870: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_80006874:
    // 0x80006874: lh          $v0, -0x4F2C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4F2C);
    // 0x80006878: nop

    // 0x8000687C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80006880: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80006884: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80006888: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8000688C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80006890: andi        $v0, $t9, 0xFFFF
    ctx->r2 = ctx->r25 & 0XFFFF;
L_80006894:
    // 0x80006894: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80006898: jal         0x8004C780
    // 0x8000689C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004C780(rdram, ctx);
        goto after_0;
    // 0x8000689C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800068A0: lw          $t3, 0x54($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X54);
    // 0x800068A4: addiu       $t2, $zero, 0x5F
    ctx->r10 = ADD32(0, 0X5F);
    // 0x800068A8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800068AC: sh          $t2, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r10;
    // 0x800068B0: sw          $zero, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = 0;
    // 0x800068B4: addiu       $v0, $v0, -0x4F3C
    ctx->r2 = ADD32(ctx->r2, -0X4F3C);
    // 0x800068B8: sw          $zero, 0x14($t3)
    MEM_W(0X14, ctx->r11) = 0;
    // 0x800068BC: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x800068C0: nop

    // 0x800068C4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800068C8: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
L_800068CC:
    // 0x800068CC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800068D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800068D4: b           L_800069CC
    // 0x800068D8: sw          $t6, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r14;
        goto L_800069CC;
    // 0x800068D8: sw          $t6, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r14;
L_800068DC:
    // 0x800068DC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800068E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800068E4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800068E8: addiu       $a3, $a3, -0x798
    ctx->r7 = ADD32(ctx->r7, -0X798);
    // 0x800068EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800068F0: addiu       $t0, $zero, 0x1CC
    ctx->r8 = ADD32(0, 0X1CC);
L_800068F4:
    // 0x800068F4: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800068F8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800068FC: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x80006900: mflo        $t7
    ctx->r15 = lo;
    // 0x80006904: addu        $v0, $a3, $t7
    ctx->r2 = ADD32(ctx->r7, ctx->r15);
    // 0x80006908: lhu         $t8, -0x188($v0)
    ctx->r24 = MEM_HU(ctx->r2, -0X188);
    // 0x8000690C: addiu       $v1, $v0, -0x1CC
    ctx->r3 = ADD32(ctx->r2, -0X1CC);
    // 0x80006910: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80006914: beq         $t9, $zero, L_8000693C
    if (ctx->r25 == 0) {
        // 0x80006918: nop
    
            goto L_8000693C;
    }
    // 0x80006918: nop

    // 0x8000691C: lhu         $t1, 0x134($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X134);
    // 0x80006920: nop

    // 0x80006924: bne         $t1, $zero, L_8000693C
    if (ctx->r9 != 0) {
        // 0x80006928: nop
    
            goto L_8000693C;
    }
    // 0x80006928: nop

    // 0x8000692C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80006930: andi        $t2, $a2, 0xFFFF
    ctx->r10 = ctx->r6 & 0XFFFF;
    // 0x80006934: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x80006938: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_8000693C:
    // 0x8000693C: bgtz        $a1, L_800068F4
    if (SIGNED(ctx->r5) > 0) {
        // 0x80006940: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800068F4;
    }
    // 0x80006940: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80006944: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x80006948: bne         $at, $zero, L_80006994
    if (ctx->r1 != 0) {
        // 0x8000694C: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_80006994;
    }
    // 0x8000694C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80006950: addiu       $v1, $v1, -0x48A0
    ctx->r3 = ADD32(ctx->r3, -0X48A0);
    // 0x80006954: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80006958: addiu       $at, $zero, 0x21C
    ctx->r1 = ADD32(0, 0X21C);
    // 0x8000695C: blez        $v0, L_80006988
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80006960: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_80006988;
    }
    // 0x80006960: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80006964: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80006968: bne         $t5, $at, L_80006978
    if (ctx->r13 != ctx->r1) {
        // 0x8000696C: sh          $t4, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r12;
            goto L_80006978;
    }
    // 0x8000696C: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x80006970: jal         0x80005360
    // 0x80006974: nop

    func_80005360(rdram, ctx);
        goto after_1;
    // 0x80006974: nop

    after_1:
L_80006978:
    // 0x80006978: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8000697C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006980: b           L_800069CC
    // 0x80006984: sw          $t6, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r14;
        goto L_800069CC;
    // 0x80006984: sw          $t6, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r14;
L_80006988:
    // 0x80006988: jal         0x80005240
    // 0x8000698C: nop

    func_80005240(rdram, ctx);
        goto after_2;
    // 0x8000698C: nop

    after_2:
    // 0x80006990: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80006994:
    // 0x80006994: jal         0x8005D200
    // 0x80006998: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_8005D200(rdram, ctx);
        goto after_3;
    // 0x80006998: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_3:
    // 0x8000699C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069A0: jal         0x80005404
    // 0x800069A4: sw          $s0, -0x4F38($at)
    MEM_W(-0X4F38, ctx->r1) = ctx->r16;
    func_80005404(rdram, ctx);
        goto after_4;
    // 0x800069A4: sw          $s0, -0x4F38($at)
    MEM_W(-0X4F38, ctx->r1) = ctx->r16;
    after_4:
    // 0x800069A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800069AC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800069B0: sh          $t7, -0x16A($at)
    MEM_H(-0X16A, ctx->r1) = ctx->r15;
    // 0x800069B4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800069B8: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x800069BC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800069C0: sh          $t8, -0x172($at)
    MEM_H(-0X172, ctx->r1) = ctx->r24;
    // 0x800069C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069C8: sw          $t9, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r25;
L_800069CC:
    // 0x800069CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800069D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800069D4: jr          $ra
    // 0x800069D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800069D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800069DC: nop

;}
RECOMP_FUNC void func_800069E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800069E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800069E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800069E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800069EC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800069F0: sh          $t6, -0x800($at)
    MEM_H(-0X800, ctx->r1) = ctx->r14;
    // 0x800069F4: jal         0x80067BB4
    // 0x800069F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067BB4(rdram, ctx);
        goto after_0;
    // 0x800069F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800069FC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80006A00: jal         0x80000A80
    // 0x80006A04: addiu       $a0, $a0, -0x345C
    ctx->r4 = ADD32(ctx->r4, -0X345C);
    func_80000A80(rdram, ctx);
        goto after_1;
    // 0x80006A04: addiu       $a0, $a0, -0x345C
    ctx->r4 = ADD32(ctx->r4, -0X345C);
    after_1:
    // 0x80006A08: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80006A0C: jal         0x80000A80
    // 0x80006A10: addiu       $a0, $a0, -0x3438
    ctx->r4 = ADD32(ctx->r4, -0X3438);
    func_80000A80(rdram, ctx);
        goto after_2;
    // 0x80006A10: addiu       $a0, $a0, -0x3438
    ctx->r4 = ADD32(ctx->r4, -0X3438);
    after_2:
    // 0x80006A14: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80006A18: jal         0x80000A80
    // 0x80006A1C: addiu       $a0, $a0, -0x340C
    ctx->r4 = ADD32(ctx->r4, -0X340C);
    func_80000A80(rdram, ctx);
        goto after_3;
    // 0x80006A1C: addiu       $a0, $a0, -0x340C
    ctx->r4 = ADD32(ctx->r4, -0X340C);
    after_3:
    // 0x80006A20: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80006A24: sh          $zero, -0x800($at)
    MEM_H(-0X800, ctx->r1) = 0;
    // 0x80006A28: jal         0x80067BB4
    // 0x80006A2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80067BB4(rdram, ctx);
        goto after_4;
    // 0x80006A2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80006A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006A34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006A38: jr          $ra
    // 0x80006A3C: nop

    return;
    // 0x80006A3C: nop

;}
RECOMP_FUNC void func_80006A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006A40: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80006A44: lhu         $v0, -0x87C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X87C);
    // 0x80006A48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80006A4C: bne         $v0, $at, L_80006A74
    if (ctx->r2 != ctx->r1) {
        // 0x80006A50: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_80006A74;
    }
    // 0x80006A50: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80006A54: addiu       $a0, $a0, 0x7C00
    ctx->r4 = ADD32(ctx->r4, 0X7C00);
    // 0x80006A58: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80006A5C: nop

    // 0x80006A60: slti        $at, $t6, 0x12
    ctx->r1 = SIGNED(ctx->r14) < 0X12 ? 1 : 0;
    // 0x80006A64: bne         $at, $zero, L_80006A74
    if (ctx->r1 != 0) {
        // 0x80006A68: nop
    
            goto L_80006A74;
    }
    // 0x80006A68: nop

    // 0x80006A6C: b           L_80006AC8
    // 0x80006A70: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80006AC8;
    // 0x80006A70: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80006A74:
    // 0x80006A74: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80006A78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80006A7C: bne         $v0, $at, L_80006AA0
    if (ctx->r2 != ctx->r1) {
        // 0x80006A80: addiu       $a0, $a0, 0x7C00
        ctx->r4 = ADD32(ctx->r4, 0X7C00);
            goto L_80006AA0;
    }
    // 0x80006A80: addiu       $a0, $a0, 0x7C00
    ctx->r4 = ADD32(ctx->r4, 0X7C00);
    // 0x80006A84: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80006A88: nop

    // 0x80006A8C: slti        $at, $t7, 0x18
    ctx->r1 = SIGNED(ctx->r15) < 0X18 ? 1 : 0;
    // 0x80006A90: bne         $at, $zero, L_80006AA4
    if (ctx->r1 != 0) {
        // 0x80006A94: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80006AA4;
    }
    // 0x80006A94: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80006A98: b           L_80006AC8
    // 0x80006A9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80006AC8;
    // 0x80006A9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80006AA0:
    // 0x80006AA0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80006AA4:
    // 0x80006AA4: bne         $v0, $at, L_80006AC8
    if (ctx->r2 != ctx->r1) {
        // 0x80006AA8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80006AC8;
    }
    // 0x80006AA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80006AAC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80006AB0: nop

    // 0x80006AB4: slti        $at, $t8, 0x1D
    ctx->r1 = SIGNED(ctx->r24) < 0X1D ? 1 : 0;
    // 0x80006AB8: bne         $at, $zero, L_80006AC8
    if (ctx->r1 != 0) {
        // 0x80006ABC: nop
    
            goto L_80006AC8;
    }
    // 0x80006ABC: nop

    // 0x80006AC0: b           L_80006AC8
    // 0x80006AC4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80006AC8;
    // 0x80006AC4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80006AC8:
    // 0x80006AC8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80006ACC: jr          $ra
    // 0x80006AD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80006AD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80006AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006AD4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80006AD8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80006ADC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80006AE0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80006AE4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80006AE8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80006AEC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80006AF0: jal         0x80031D60
    // 0x80006AF4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_80031D60(rdram, ctx);
        goto after_0;
    // 0x80006AF4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80006AF8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80006AFC: jal         0x8004E24C
    // 0x80006B00: addiu       $a0, $a0, -0x46A4
    ctx->r4 = ADD32(ctx->r4, -0X46A4);
    func_8004E24C(rdram, ctx);
        goto after_1;
    // 0x80006B00: addiu       $a0, $a0, -0x46A4
    ctx->r4 = ADD32(ctx->r4, -0X46A4);
    after_1:
    // 0x80006B04: lhu         $s2, 0x4($v0)
    ctx->r18 = MEM_HU(ctx->r2, 0X4);
    // 0x80006B08: addiu       $s1, $v0, 0x10
    ctx->r17 = ADD32(ctx->r2, 0X10);
    // 0x80006B0C: beq         $s2, $zero, L_80006BF4
    if (ctx->r18 == 0) {
        // 0x80006B10: slti        $at, $s2, 0x4
        ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
            goto L_80006BF4;
    }
    // 0x80006B10: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x80006B14: bne         $at, $zero, L_80006B20
    if (ctx->r1 != 0) {
        // 0x80006B18: lui         $s0, 0x800C
        ctx->r16 = S32(0X800C << 16);
            goto L_80006B20;
    }
    // 0x80006B18: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80006B1C: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_80006B20:
    // 0x80006B20: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80006B24: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80006B28: sh          $s2, -0x1264($at)
    MEM_H(-0X1264, ctx->r1) = ctx->r18;
    // 0x80006B2C: addiu       $s0, $s0, -0x1260
    ctx->r16 = ADD32(ctx->r16, -0X1260);
    // 0x80006B30: addiu       $s3, $s3, -0x4500
    ctx->r19 = ADD32(ctx->r19, -0X4500);
    // 0x80006B34: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80006B38: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80006B3C:
    // 0x80006B3C: jal         0x80039D18
    // 0x80006B40: nop

    func_80039D18(rdram, ctx);
        goto after_2;
    // 0x80006B40: nop

    after_2:
    // 0x80006B44: sw          $v0, 0x3C($s3)
    MEM_W(0X3C, ctx->r19) = ctx->r2;
    // 0x80006B48: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80006B4C: nop

    // 0x80006B50: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    // 0x80006B54: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80006B58: nop

    // 0x80006B5C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80006B60: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x80006B64: sh          $s4, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r20;
    // 0x80006B68: lhu         $t9, 0x4($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X4);
    // 0x80006B6C: jal         0x8002EC64
    // 0x80006B70: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    func_8002EC64(rdram, ctx);
        goto after_3;
    // 0x80006B70: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    after_3:
    // 0x80006B74: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80006B78: sw          $s0, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r16;
    // 0x80006B7C: lh          $t0, 0x6($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X6);
    // 0x80006B80: lhu         $t2, 0x32($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X32);
    // 0x80006B84: sh          $t0, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r8;
    // 0x80006B88: lh          $t1, 0x8($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X8);
    // 0x80006B8C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80006B90: sh          $t1, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r9;
    // 0x80006B94: lhu         $t3, 0xA($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0XA);
    // 0x80006B98: nop

    // 0x80006B9C: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x80006BA0: sh          $t4, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r12;
    // 0x80006BA4: lhu         $t5, 0xC($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XC);
    // 0x80006BA8: nop

    // 0x80006BAC: sh          $t5, 0x88($v0)
    MEM_H(0X88, ctx->r2) = ctx->r13;
    // 0x80006BB0: lhu         $v1, 0xE($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XE);
    // 0x80006BB4: nop

    // 0x80006BB8: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80006BBC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80006BC0: bne         $s5, $t7, L_80006BD8
    if (ctx->r21 != ctx->r15) {
        // 0x80006BC4: nop
    
            goto L_80006BD8;
    }
    // 0x80006BC4: nop

    // 0x80006BC8: jal         0x80000688
    // 0x80006BCC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_80000688(rdram, ctx);
        goto after_4;
    // 0x80006BCC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_4:
    // 0x80006BD0: b           L_80006BDC
    // 0x80006BD4: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
        goto L_80006BDC;
    // 0x80006BD4: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
L_80006BD8:
    // 0x80006BD8: sh          $v1, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r3;
L_80006BDC:
    // 0x80006BDC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80006BE0: andi        $t8, $s2, 0xFFFF
    ctx->r24 = ctx->r18 & 0XFFFF;
    // 0x80006BE4: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80006BE8: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x80006BEC: bgtz        $t8, L_80006B3C
    if (SIGNED(ctx->r24) > 0) {
        // 0x80006BF0: addiu       $s0, $s0, 0x68
        ctx->r16 = ADD32(ctx->r16, 0X68);
            goto L_80006B3C;
    }
    // 0x80006BF0: addiu       $s0, $s0, 0x68
    ctx->r16 = ADD32(ctx->r16, 0X68);
L_80006BF4:
    // 0x80006BF4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80006BF8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80006BFC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80006C00: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80006C04: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80006C08: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80006C0C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80006C10: jr          $ra
    // 0x80006C14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80006C14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80006C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006C18: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80006C1C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80006C20: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80006C24: addiu       $s4, $s4, -0x4460
    ctx->r20 = ADD32(ctx->r20, -0X4460);
    // 0x80006C28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80006C2C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80006C30: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80006C34: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80006C38: addiu       $s6, $v1, -0x798
    ctx->r22 = ADD32(ctx->r3, -0X798);
    // 0x80006C3C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80006C40: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80006C44: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80006C48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006C4C: lui         $s5, 0x8007
    ctx->r21 = S32(0X8007 << 16);
    // 0x80006C50: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80006C54: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80006C58: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80006C5C: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x80006C60: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80006C64: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x80006C68: sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // 0x80006C6C: sw          $v0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r2;
    // 0x80006C70: addiu       $s5, $s5, 0x7C08
    ctx->r21 = ADD32(ctx->r21, 0X7C08);
L_80006C74:
    // 0x80006C74: lhu         $t6, 0x44($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X44);
    // 0x80006C78: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x80006C7C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80006C80: beq         $t7, $zero, L_80006CF4
    if (ctx->r15 == 0) {
        // 0x80006C84: nop
    
            goto L_80006CF4;
    }
    // 0x80006C84: nop

    // 0x80006C88: lhu         $t8, 0x10($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X10);
    // 0x80006C8C: lhu         $t9, 0x1A($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X1A);
    // 0x80006C90: addu        $t2, $s4, $t1
    ctx->r10 = ADD32(ctx->r20, ctx->r9);
    // 0x80006C94: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80006C98: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x80006C9C: lhu         $t4, 0x1A($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X1A);
    // 0x80006CA0: lhu         $t3, 0x10($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X10);
    // 0x80006CA4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80006CA8: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80006CAC: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80006CB0: bne         $at, $zero, L_80006CF4
    if (ctx->r1 != 0) {
        // 0x80006CB4: nop
    
            goto L_80006CF4;
    }
    // 0x80006CB4: nop

    // 0x80006CB8: bne         $s2, $v0, L_80006CE4
    if (ctx->r18 != ctx->r2) {
        // 0x80006CBC: addiu       $a0, $zero, 0x5F03
        ctx->r4 = ADD32(0, 0X5F03);
            goto L_80006CE4;
    }
    // 0x80006CBC: addiu       $a0, $zero, 0x5F03
    ctx->r4 = ADD32(0, 0X5F03);
    // 0x80006CC0: jal         0x80000688
    // 0x80006CC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80000688(rdram, ctx);
        goto after_0;
    // 0x80006CC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80006CC8: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x80006CCC: beq         $t5, $zero, L_80006CF4
    if (ctx->r13 == 0) {
        // 0x80006CD0: nop
    
            goto L_80006CF4;
    }
    // 0x80006CD0: nop

    // 0x80006CD4: lhu         $t6, 0x10($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X10);
    // 0x80006CD8: lhu         $t7, 0x1A($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1A);
    // 0x80006CDC: nop

    // 0x80006CE0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_80006CE4:
    // 0x80006CE4: lhu         $t8, 0x0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X0);
    // 0x80006CE8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80006CEC: or          $s6, $s0, $zero
    ctx->r22 = ctx->r16 | 0;
    // 0x80006CF0: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
L_80006CF4:
    // 0x80006CF4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80006CF8: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x80006CFC: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80006D00: bgtz        $t9, L_80006C74
    if (SIGNED(ctx->r25) > 0) {
        // 0x80006D04: addiu       $s0, $s0, 0x1CC
        ctx->r16 = ADD32(ctx->r16, 0X1CC);
            goto L_80006C74;
    }
    // 0x80006D04: addiu       $s0, $s0, 0x1CC
    ctx->r16 = ADD32(ctx->r16, 0X1CC);
    // 0x80006D08: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80006D0C: bne         $s3, $v1, L_80006D28
    if (ctx->r19 != ctx->r3) {
        // 0x80006D10: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80006D28;
    }
    // 0x80006D10: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80006D14: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80006D18: lw          $t1, 0x4($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X4);
    // 0x80006D1C: sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // 0x80006D20: b           L_80006D40
    // 0x80006D24: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
        goto L_80006D40;
    // 0x80006D24: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
L_80006D28:
    // 0x80006D28: bne         $s3, $at, L_80006D44
    if (ctx->r19 != ctx->r1) {
        // 0x80006D2C: slti        $at, $s3, 0x2
        ctx->r1 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
            goto L_80006D44;
    }
    // 0x80006D2C: slti        $at, $s3, 0x2
    ctx->r1 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // 0x80006D30: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80006D34: lw          $t0, 0x8($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X8);
    // 0x80006D38: sw          $v0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r2;
    // 0x80006D3C: sw          $t0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r8;
L_80006D40:
    // 0x80006D40: slti        $at, $s3, 0x2
    ctx->r1 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
L_80006D44:
    // 0x80006D44: bne         $at, $zero, L_80006DA8
    if (ctx->r1 != 0) {
        // 0x80006D48: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80006DA8;
    }
    // 0x80006D48: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80006D4C: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80006D50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80006D54: bne         $v0, $at, L_80006D70
    if (ctx->r2 != ctx->r1) {
        // 0x80006D58: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_80006D70;
    }
    // 0x80006D58: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80006D5C: addiu       $a0, $a0, 0x7DE8
    ctx->r4 = ADD32(ctx->r4, 0X7DE8);
    // 0x80006D60: jal         0x80005588
    // 0x80006D64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80005588(rdram, ctx);
        goto after_1;
    // 0x80006D64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80006D68: b           L_80006DA8
    // 0x80006D6C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80006DA8;
    // 0x80006D6C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80006D70:
    // 0x80006D70: bne         $v1, $v0, L_80006D90
    if (ctx->r3 != ctx->r2) {
        // 0x80006D74: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80006D90;
    }
    // 0x80006D74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80006D78: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80006D7C: addiu       $a0, $a0, 0x7DB0
    ctx->r4 = ADD32(ctx->r4, 0X7DB0);
    // 0x80006D80: jal         0x80005588
    // 0x80006D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80005588(rdram, ctx);
        goto after_2;
    // 0x80006D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80006D88: b           L_80006DA8
    // 0x80006D8C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80006DA8;
    // 0x80006D8C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80006D90:
    // 0x80006D90: bne         $v0, $at, L_80006DA4
    if (ctx->r2 != ctx->r1) {
        // 0x80006D94: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_80006DA4;
    }
    // 0x80006D94: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80006D98: addiu       $a0, $a0, 0x7E28
    ctx->r4 = ADD32(ctx->r4, 0X7E28);
    // 0x80006D9C: jal         0x80005588
    // 0x80006DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80005588(rdram, ctx);
        goto after_3;
    // 0x80006DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_80006DA4:
    // 0x80006DA4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80006DA8:
    // 0x80006DA8: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80006DAC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80006DB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006DB4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80006DB8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80006DBC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80006DC0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80006DC4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80006DC8: jr          $ra
    // 0x80006DCC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80006DCC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80006DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006DD0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80006DD4: addiu       $a2, $a2, -0x4450
    ctx->r6 = ADD32(ctx->r6, -0X4450);
    // 0x80006DD8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80006DDC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80006DE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80006DE4: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x80006DE8: sw          $a1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r5;
    // 0x80006DEC: sw          $a1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r5;
    // 0x80006DF0: sw          $a1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r5;
    // 0x80006DF4: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80006DF8: addiu       $a3, $a3, -0x798
    ctx->r7 = ADD32(ctx->r7, -0X798);
    // 0x80006DFC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80006E00: addiu       $t0, $zero, 0x1CC
    ctx->r8 = ADD32(0, 0X1CC);
L_80006E04:
    // 0x80006E04: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006E08: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80006E0C: mflo        $t6
    ctx->r14 = lo;
    // 0x80006E10: addu        $a1, $a3, $t6
    ctx->r5 = ADD32(ctx->r7, ctx->r14);
    // 0x80006E14: addiu       $a1, $a1, -0x1CC
    ctx->r5 = ADD32(ctx->r5, -0X1CC);
    // 0x80006E18: beq         $a1, $zero, L_80006E48
    if (ctx->r5 == 0) {
        // 0x80006E1C: andi        $a0, $v1, 0xFFFF
        ctx->r4 = ctx->r3 & 0XFFFF;
            goto L_80006E48;
    }
    // 0x80006E1C: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x80006E20: lw          $t7, 0x54($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X54);
    // 0x80006E24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006E28: sw          $t7, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r15;
    // 0x80006E2C: lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X0);
    // 0x80006E30: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80006E34: beq         $a0, $zero, L_80006E44
    if (ctx->r4 == 0) {
        // 0x80006E38: addu        $t9, $a2, $t8
        ctx->r25 = ADD32(ctx->r6, ctx->r24);
            goto L_80006E44;
    }
    // 0x80006E38: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x80006E3C: sw          $a0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r4;
    // 0x80006E40: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80006E44:
    // 0x80006E44: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
L_80006E48:
    // 0x80006E48: bgtz        $a0, L_80006E04
    if (SIGNED(ctx->r4) > 0) {
        // 0x80006E4C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80006E04;
    }
    // 0x80006E4C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80006E50: jr          $ra
    // 0x80006E54: nop

    return;
    // 0x80006E54: nop

;}
RECOMP_FUNC void func_80006E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006E58: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80006E5C: addiu       $v0, $v0, 0x606
    ctx->r2 = ADD32(ctx->r2, 0X606);
    // 0x80006E60: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x80006E64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006E68: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80006E6C: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80006E70: sh          $zero, -0x487E($at)
    MEM_H(-0X487E, ctx->r1) = 0;
    // 0x80006E74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006E78: sh          $zero, -0x483E($at)
    MEM_H(-0X483E, ctx->r1) = 0;
    // FALLTHROUGH FIX: func_80006E58 falls through to func_80006E7C
    func_80006E7C(rdram, ctx);
;}
RECOMP_FUNC void func_80006E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006E7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80006E80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006E84: sh          $zero, -0x483C($at)
    MEM_H(-0X483C, ctx->r1) = 0;
    // 0x80006E88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80006E8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006E90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80006E94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80006E98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006E9C: jal         0x8002B180
    // 0x80006EA0: sh          $zero, -0x4840($at)
    MEM_H(-0X4840, ctx->r1) = 0;
    func_8002B180(rdram, ctx);
        goto after_0;
    // 0x80006EA0: sh          $zero, -0x4840($at)
    MEM_H(-0X4840, ctx->r1) = 0;
    after_0:
    // 0x80006EA4: jal         0x8002B2A4
    // 0x80006EA8: nop

    func_8002B2A4(rdram, ctx);
        goto after_1;
    // 0x80006EA8: nop

    after_1:
    // 0x80006EAC: jal         0x8002E090
    // 0x80006EB0: nop

    func_8002E090(rdram, ctx);
        goto after_2;
    // 0x80006EB0: nop

    after_2:
    // 0x80006EB4: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x80006EB8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80006EBC:
    // 0x80006EBC: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80006EC0: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x80006EC4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80006EC8: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x80006ECC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80006ED0: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x80006ED4: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80006ED8: addiu       $t9, $t9, -0x798
    ctx->r25 = ADD32(ctx->r25, -0X798);
    // 0x80006EDC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80006EE0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80006EE4: lw          $s1, -0x178($v0)
    ctx->r17 = MEM_W(ctx->r2, -0X178);
    // 0x80006EE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006EEC: sw          $s1, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r17;
    // 0x80006EF0: lhu         $t0, -0x1CC($v0)
    ctx->r8 = MEM_HU(ctx->r2, -0X1CC);
    // 0x80006EF4: addiu       $s0, $v0, -0x1CC
    ctx->r16 = ADD32(ctx->r2, -0X1CC);
    // 0x80006EF8: beq         $t0, $zero, L_80006FB8
    if (ctx->r8 == 0) {
        // 0x80006EFC: andi        $a0, $s2, 0xFFFF
        ctx->r4 = ctx->r18 & 0XFFFF;
            goto L_80006FB8;
    }
    // 0x80006EFC: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x80006F00: beq         $s0, $zero, L_80006FB8
    if (ctx->r16 == 0) {
        // 0x80006F04: nop
    
            goto L_80006FB8;
    }
    // 0x80006F04: nop

    // 0x80006F08: lhu         $t2, 0x44($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X44);
    // 0x80006F0C: lhu         $t1, 0x88($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X88);
    // 0x80006F10: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80006F14: beq         $t3, $zero, L_80006F70
    if (ctx->r11 == 0) {
        // 0x80006F18: sh          $t1, 0xDA($s0)
        MEM_H(0XDA, ctx->r16) = ctx->r9;
            goto L_80006F70;
    }
    // 0x80006F18: sh          $t1, 0xDA($s0)
    MEM_H(0XDA, ctx->r16) = ctx->r9;
    // 0x80006F1C: jal         0x8002B4E4
    // 0x80006F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002B4E4(rdram, ctx);
        goto after_3;
    // 0x80006F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80006F24: jal         0x8004B970
    // 0x80006F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004B970(rdram, ctx);
        goto after_4;
    // 0x80006F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80006F2C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80006F30: lw          $t4, -0x4F38($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4F38);
    // 0x80006F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006F38: bne         $t4, $zero, L_80006F48
    if (ctx->r12 != 0) {
        // 0x80006F3C: nop
    
            goto L_80006F48;
    }
    // 0x80006F3C: nop

    // 0x80006F40: jal         0x8002C928
    // 0x80006F44: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    func_8002C928(rdram, ctx);
        goto after_5;
    // 0x80006F44: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    after_5:
L_80006F48:
    // 0x80006F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006F4C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80006F50: jal         0x80047AC0
    // 0x80006F54: andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    func_80047AC0(rdram, ctx);
        goto after_6;
    // 0x80006F54: andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    after_6:
    // 0x80006F58: sh          $zero, 0x160($s0)
    MEM_H(0X160, ctx->r16) = 0;
    // 0x80006F5C: sh          $zero, 0x162($s0)
    MEM_H(0X162, ctx->r16) = 0;
    // 0x80006F60: jal         0x8002B530
    // 0x80006F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002B530(rdram, ctx);
        goto after_7;
    // 0x80006F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80006F68: jal         0x8002BD5C
    // 0x80006F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002BD5C(rdram, ctx);
        goto after_8;
    // 0x80006F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80006F70:
    // 0x80006F70: jal         0x8002E2E4
    // 0x80006F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002E2E4(rdram, ctx);
        goto after_9;
    // 0x80006F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80006F78: jal         0x8002C654
    // 0x80006F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002C654(rdram, ctx);
        goto after_10;
    // 0x80006F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80006F80: jal         0x8002C354
    // 0x80006F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002C354(rdram, ctx);
        goto after_11;
    // 0x80006F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80006F88: jal         0x8002C500
    // 0x80006F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002C500(rdram, ctx);
        goto after_12;
    // 0x80006F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80006F90: jal         0x80028734
    // 0x80006F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028734(rdram, ctx);
        goto after_13;
    // 0x80006F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80006F98: jal         0x8002E440
    // 0x80006F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002E440(rdram, ctx);
        goto after_14;
    // 0x80006F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80006FA0: lw          $a1, 0x58($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X58);
    // 0x80006FA4: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x80006FA8: jal         0x8002B374
    // 0x80006FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002B374(rdram, ctx);
        goto after_15;
    // 0x80006FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80006FB0: b           L_80006FC4
    // 0x80006FB4: nop

        goto L_80006FC4;
    // 0x80006FB4: nop

L_80006FB8:
    // 0x80006FB8: addiu       $s0, $v0, -0x1CC
    ctx->r16 = ADD32(ctx->r2, -0X1CC);
    // 0x80006FBC: jal         0x8002C4D0
    // 0x80006FC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8002C4D0(rdram, ctx);
        goto after_16;
    // 0x80006FC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
L_80006FC4:
    // 0x80006FC4: jal         0x8002E748
    // 0x80006FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002E748(rdram, ctx);
        goto after_17;
    // 0x80006FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80006FCC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80006FD0: andi        $v1, $s2, 0xFFFF
    ctx->r3 = ctx->r18 & 0XFFFF;
    // 0x80006FD4: bgtz        $v1, L_80006EBC
    if (SIGNED(ctx->r3) > 0) {
        // 0x80006FD8: or          $s2, $v1, $zero
        ctx->r18 = ctx->r3 | 0;
            goto L_80006EBC;
    }
    // 0x80006FD8: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x80006FDC: jal         0x8002E228
    // 0x80006FE0: nop

    func_8002E228(rdram, ctx);
        goto after_18;
    // 0x80006FE0: nop

    after_18:
    // 0x80006FE4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80006FE8: addiu       $v0, $v0, -0x4F64
    ctx->r2 = ADD32(ctx->r2, -0X4F64);
    // 0x80006FEC: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80006FF0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80006FF4: bne         $t6, $zero, L_80007004
    if (ctx->r14 != 0) {
        // 0x80006FF8: nop
    
            goto L_80007004;
    }
    // 0x80006FF8: nop

    // 0x80006FFC: b           L_800070C8
    // 0x80007000: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
        goto L_800070C8;
    // 0x80007000: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
L_80007004:
    // 0x80007004: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80007008: addiu       $v1, $v1, -0x4F46
    ctx->r3 = ADD32(ctx->r3, -0X4F46);
    // 0x8000700C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80007010: nop

    // 0x80007014: beq         $v0, $zero, L_8000704C
    if (ctx->r2 == 0) {
        // 0x80007018: addiu       $at, $zero, 0x78
        ctx->r1 = ADD32(0, 0X78);
            goto L_8000704C;
    }
    // 0x80007018: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x8000701C: bne         $v0, $at, L_80007030
    if (ctx->r2 != ctx->r1) {
        // 0x80007020: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80007030;
    }
    // 0x80007020: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80007024: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80007028: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000702C: sh          $t8, -0x483E($at)
    MEM_H(-0X483E, ctx->r1) = ctx->r24;
L_80007030:
    // 0x80007030: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x80007034: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80007038: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000703C: bne         $t0, $zero, L_800070B0
    if (ctx->r8 != 0) {
        // 0x80007040: nop
    
            goto L_800070B0;
    }
    // 0x80007040: nop

    // 0x80007044: b           L_800070B0
    // 0x80007048: sh          $zero, -0x4F48($at)
    MEM_H(-0X4F48, ctx->r1) = 0;
        goto L_800070B0;
    // 0x80007048: sh          $zero, -0x4F48($at)
    MEM_H(-0X4F48, ctx->r1) = 0;
L_8000704C:
    // 0x8000704C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80007050: lhu         $t1, -0x87C($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X87C);
    // 0x80007054: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80007058: bne         $t1, $zero, L_800070B0
    if (ctx->r9 != 0) {
        // 0x8000705C: nop
    
            goto L_800070B0;
    }
    // 0x8000705C: nop

    // 0x80007060: lhu         $t2, -0x487A($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X487A);
    // 0x80007064: nop

    // 0x80007068: bne         $t2, $zero, L_800070B0
    if (ctx->r10 != 0) {
        // 0x8000706C: nop
    
            goto L_800070B0;
    }
    // 0x8000706C: nop

    // 0x80007070: jal         0x8003ABCC
    // 0x80007074: nop

    func_8003ABCC(rdram, ctx);
        goto after_19;
    // 0x80007074: nop

    after_19:
    // 0x80007078: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000707C: bne         $v0, $at, L_800070B0
    if (ctx->r2 != ctx->r1) {
        // 0x80007080: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800070B0;
    }
    // 0x80007080: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80007084: addiu       $v1, $v1, -0x483A
    ctx->r3 = ADD32(ctx->r3, -0X483A);
    // 0x80007088: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8000708C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80007090: bne         $v0, $zero, L_800070AC
    if (ctx->r2 != 0) {
        // 0x80007094: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_800070AC;
    }
    // 0x80007094: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80007098: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000709C: sh          $t3, -0x483E($at)
    MEM_H(-0X483E, ctx->r1) = ctx->r11;
    // 0x800070A0: addiu       $t4, $zero, 0x77
    ctx->r12 = ADD32(0, 0X77);
    // 0x800070A4: b           L_800070B0
    // 0x800070A8: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
        goto L_800070B0;
    // 0x800070A8: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_800070AC:
    // 0x800070AC: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
L_800070B0:
    // 0x800070B0: jal         0x80031C40
    // 0x800070B4: nop

    func_80031C40(rdram, ctx);
        goto after_20;
    // 0x800070B4: nop

    after_20:
    // 0x800070B8: jal         0x8004F4E0
    // 0x800070BC: nop

    func_8004F4E0(rdram, ctx);
        goto after_21;
    // 0x800070BC: nop

    after_21:
    // 0x800070C0: jal         0x80042FD4
    // 0x800070C4: nop

    func_80042FD4(rdram, ctx);
        goto after_22;
    // 0x800070C4: nop

    after_22:
L_800070C8:
    // 0x800070C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800070CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800070D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800070D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800070D8: jr          $ra
    // 0x800070DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800070DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
