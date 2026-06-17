#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_80002F38(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80002EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002EB8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80002EBC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80002EB8 falls into func_80002EC0
    func_80002EC0(rdram, ctx);
;}
RECOMP_FUNC void func_80002EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002EC4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80002EC8: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80002ECC: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80002ED0: bne         $v0, $zero, L_80002EEC
    if (ctx->r2 != 0) {
        // 0x80002ED4: nop
    
            goto L_80002EEC;
    }
    // 0x80002ED4: nop

    // 0x80002ED8: jal         0x80002F38
    // 0x80002EDC: nop

    func_80002F38(rdram, ctx);
        goto after_0;
    // 0x80002EDC: nop

    after_0:
    // 0x80002EE0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80002EE4: bne         $v0, $zero, L_80002F04
    if (ctx->r2 != 0) {
        // 0x80002EE8: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_80002F04;
    }
    // 0x80002EE8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80002EEC:
    // 0x80002EEC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80002EF0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80002EF4: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80002EF8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80002EFC: j           L_80002F28
    // 0x80002F00: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
        goto L_80002F28;
    // 0x80002F00: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
L_80002F04:
    // 0x80002F04: jal         0x80001414
    // 0x80002F08: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80001414(rdram, ctx);
        goto after_1;
    // 0x80002F08: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x80002F0C: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80002F10: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80002F14: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80002F18: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80002F1C: lhu         $a0, 0x1480($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X1480);
    // 0x80002F20: jal         0x8004C79C
    // 0x80002F24: nop

    func_8004C79C(rdram, ctx);
        goto after_2;
    // 0x80002F24: nop

    after_2:
L_80002F28:
    // 0x80002F28: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80002F2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002F30: jr          $ra
    // 0x80002F34: nop

    return;
    // 0x80002F34: nop

;}
RECOMP_FUNC void func_80002F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002F38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002F3C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80002F40: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    // 0x80002F44: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80002F48: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80002F4C: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
L_80002F50:
    // 0x80002F50: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80002F54: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002F58: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80002F5C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80002F60: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80002F64: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80002F68: addiu       $v1, $v1, 0x3F94
    ctx->r3 = ADD32(ctx->r3, 0X3F94);
    // 0x80002F6C: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80002F70: lhu         $v0, 0x58($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X58);
    // 0x80002F74: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80002F78: beq         $v0, $zero, L_80003040
    if (ctx->r2 == 0) {
        // 0x80002F7C: addiu       $v0, $zero, 0xE1
        ctx->r2 = ADD32(0, 0XE1);
            goto L_80003040;
    }
    // 0x80002F7C: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x80002F80: lw          $s0, 0x68($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X68);
    // 0x80002F84: lh          $v1, 0x18($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X18);
    // 0x80002F88: bne         $v1, $v0, L_80003044
    if (ctx->r3 != ctx->r2) {
        // 0x80002F8C: addiu       $v0, $s1, -0x1
        ctx->r2 = ADD32(ctx->r17, -0X1);
            goto L_80003044;
    }
    // 0x80002F8C: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x80002F90: lhu         $v0, 0x18E($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X18E);
    // 0x80002F94: bne         $v0, $zero, L_80002FA8
    if (ctx->r2 != 0) {
        // 0x80002F98: nop
    
            goto L_80002FA8;
    }
    // 0x80002F98: nop

    // 0x80002F9C: lhu         $v0, 0x1DE($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1DE);
    // 0x80002FA0: beq         $v0, $zero, L_80003044
    if (ctx->r2 == 0) {
        // 0x80002FA4: addiu       $v0, $s1, -0x1
        ctx->r2 = ADD32(ctx->r17, -0X1);
            goto L_80003044;
    }
    // 0x80002FA4: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
L_80002FA8:
    // 0x80002FA8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80002FAC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80002FB0: lh          $a0, 0x14($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X14);
    // 0x80002FB4: lh          $a1, 0x14($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X14);
    // 0x80002FB8: jal         0x8003F1F0
    // 0x80002FBC: nop

    func_8003F1F0(rdram, ctx);
        goto after_0;
    // 0x80002FBC: nop

    after_0:
    // 0x80002FC0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80002FC4: bgez        $v0, L_80003004
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80002FC8: nop
    
            goto L_80003004;
    }
    // 0x80002FC8: nop

    // 0x80002FCC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80002FD0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80002FD4: lh          $a0, 0x14($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X14);
    // 0x80002FD8: lh          $a1, 0x14($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X14);
    // 0x80002FDC: jal         0x8003F1F0
    // 0x80002FE0: nop

    func_8003F1F0(rdram, ctx);
        goto after_1;
    // 0x80002FE0: nop

    after_1:
    // 0x80002FE4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80002FE8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80002FEC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80002FF0: slti        $v0, $v0, 0x81
    ctx->r2 = SIGNED(ctx->r2) < 0X81 ? 1 : 0;
    // 0x80002FF4: bne         $v0, $zero, L_80003030
    if (ctx->r2 != 0) {
        // 0x80002FF8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80003030;
    }
    // 0x80002FF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002FFC: j           L_80003044
    // 0x80003000: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
        goto L_80003044;
    // 0x80003000: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
L_80003004:
    // 0x80003004: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80003008: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000300C: lh          $a0, 0x14($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X14);
    // 0x80003010: lh          $a1, 0x14($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X14);
    // 0x80003014: jal         0x8003F1F0
    // 0x80003018: nop

    func_8003F1F0(rdram, ctx);
        goto after_2;
    // 0x80003018: nop

    after_2:
    // 0x8000301C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80003020: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80003024: slti        $v0, $v0, 0x81
    ctx->r2 = SIGNED(ctx->r2) < 0X81 ? 1 : 0;
    // 0x80003028: beq         $v0, $zero, L_80003040
    if (ctx->r2 == 0) {
        // 0x8000302C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80003040;
    }
    // 0x8000302C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80003030:
    // 0x80003030: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80003034: sh          $v0, 0x3218($at)
    MEM_H(0X3218, ctx->r1) = ctx->r2;
    // 0x80003038: j           L_80003060
    // 0x8000303C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80003060;
    // 0x8000303C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80003040:
    // 0x80003040: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
L_80003044:
    // 0x80003044: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80003048: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000304C: bne         $v0, $zero, L_80002F50
    if (ctx->r2 != 0) {
        // 0x80003050: andi        $v1, $s1, 0xFFFF
        ctx->r3 = ctx->r17 & 0XFFFF;
            goto L_80002F50;
    }
    // 0x80003050: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
    // 0x80003054: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80003058: sh          $zero, 0x3218($at)
    MEM_H(0X3218, ctx->r1) = 0;
    // 0x8000305C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80003060:
    // 0x80003060: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80003064: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80003068: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000306C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80003070: jr          $ra
    // 0x80003074: nop

    return;
    // 0x80003074: nop

;}
RECOMP_FUNC void func_80003078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003078: jr          $ra
    // 0x8000307C: nop

    return;
    // 0x8000307C: nop

;}
RECOMP_FUNC void func_80003080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003080: jr          $ra
    // 0x80003084: nop

    return;
    // 0x80003084: nop

;}
RECOMP_FUNC void func_80003088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003088: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8000308C: lhu         $v0, -0x7340($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7340);
    // 0x80003090: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80003094: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80003098: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000309C: sh          $v0, -0x7340($at)
    MEM_H(-0X7340, ctx->r1) = ctx->r2;
    // 0x800030A0: bne         $v0, $zero, L_800030BC
    if (ctx->r2 != 0) {
        // 0x800030A4: nop
    
            goto L_800030BC;
    }
    // 0x800030A4: nop

    // 0x800030A8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800030AC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800030B0: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x800030B4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800030B8: sw          $v1, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r3;
L_800030BC:
    // 0x800030BC: jr          $ra
    // 0x800030C0: nop

    return;
    // 0x800030C0: nop

;}
RECOMP_FUNC void func_800030C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800030C4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800030C8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800030CC: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x800030D0: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x800030D4: jr          $ra
    // 0x800030D8: sh          $v1, 0x80($v0)
    MEM_H(0X80, ctx->r2) = ctx->r3;
    return;
    // 0x800030D8: sh          $v1, 0x80($v0)
    MEM_H(0X80, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_800030DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800030DC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800030E0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // FALLTHROUGH: func_800030DC falls into func_800030E4
    func_800030E4(rdram, ctx);
;}
RECOMP_FUNC void func_800030E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800030E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800030E8: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x800030EC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800030F0: jal         0x80040F44
    // 0x800030F4: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    func_80040F44(rdram, ctx);
        goto after_0;
    // 0x800030F4: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    after_0:
    // 0x800030F8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800030FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80003100: jr          $ra
    // 0x80003104: nop

    return;
    // 0x80003104: nop

    // 0x80003108: nop

    // 0x8000310C: nop

;}
RECOMP_FUNC void func_80003110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003110: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003114: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80003110 falls into func_80003118
    func_80003118(rdram, ctx);
;}
RECOMP_FUNC void func_80003118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000311C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003120: addiu       $a0, $a0, -0x7DC0
    ctx->r4 = ADD32(ctx->r4, -0X7DC0);
    // 0x80003124: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80003128: jal         0x80037DDC
    // 0x8000312C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000312C: nop

    after_0:
    // 0x80003130: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80003138: jr          $ra
    // 0x8000313C: nop

    return;
    // 0x8000313C: nop

;}
RECOMP_FUNC void func_80003140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003140: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003144: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80003140 falls into func_80003148
    func_80003148(rdram, ctx);
;}
RECOMP_FUNC void func_80003148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000314C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003150: addiu       $a0, $a0, -0x7D90
    ctx->r4 = ADD32(ctx->r4, -0X7D90);
    // 0x80003154: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80003158: jal         0x80037DDC
    // 0x8000315C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000315C: nop

    after_0:
    // 0x80003160: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80003168: jr          $ra
    // 0x8000316C: nop

    return;
    // 0x8000316C: nop

;}
RECOMP_FUNC void func_80003170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003170: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003174: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80003170 falls into func_80003178
    func_80003178(rdram, ctx);
;}
RECOMP_FUNC void func_80003178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000317C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003180: addiu       $a0, $a0, -0x7D68
    ctx->r4 = ADD32(ctx->r4, -0X7D68);
    // 0x80003184: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80003188: jal         0x80037DDC
    // 0x8000318C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000318C: nop

    after_0:
    // 0x80003190: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003194: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80003198: jr          $ra
    // 0x8000319C: nop

    return;
    // 0x8000319C: nop

;}
RECOMP_FUNC void func_800031A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800031A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800031A4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800031A8: jal         0x80014DEC
    // 0x800031AC: nop

    func_80014DEC(rdram, ctx);
        goto after_0;
    // 0x800031AC: nop

    after_0:
    // 0x800031B0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x800031B4: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x800031B8: beq         $v0, $zero, L_80003214
    if (ctx->r2 == 0) {
        // 0x800031BC: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80003214;
    }
    // 0x800031BC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800031C0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800031C4: addu        $at, $at, $v0
    gpr jr_addend_800031CC = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800031C8: lw          $v0, 0x3228($at)
    ctx->r2 = ADD32(ctx->r1, 0X3228);
    // 0x800031CC: jr          $v0
    // 0x800031D0: nop

    switch (jr_addend_800031CC >> 2) {
        case 0: goto L_800031D4; break;
        case 1: goto L_800031E4; break;
        case 2: goto L_800031E4; break;
        case 3: goto L_800031F4; break;
        case 4: goto L_800031F4; break;
        case 5: goto L_80003204; break;
        case 6: goto L_80003204; break;
        default: switch_error(__func__, 0x800031CC, 0x80093228);
    }
    // 0x800031D0: nop

L_800031D4:
    // 0x800031D4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800031D8: addiu       $a0, $a0, -0x7D5C
    ctx->r4 = ADD32(ctx->r4, -0X7D5C);
    // 0x800031DC: j           L_8000321C
    // 0x800031E0: nop

        goto L_8000321C;
    // 0x800031E0: nop

L_800031E4:
    // 0x800031E4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800031E8: addiu       $a0, $a0, -0x7CEC
    ctx->r4 = ADD32(ctx->r4, -0X7CEC);
    // 0x800031EC: j           L_8000321C
    // 0x800031F0: nop

        goto L_8000321C;
    // 0x800031F0: nop

L_800031F4:
    // 0x800031F4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800031F8: addiu       $a0, $a0, -0x7C7C
    ctx->r4 = ADD32(ctx->r4, -0X7C7C);
    // 0x800031FC: j           L_8000321C
    // 0x80003200: nop

        goto L_8000321C;
    // 0x80003200: nop

L_80003204:
    // 0x80003204: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003208: addiu       $a0, $a0, -0x7C0C
    ctx->r4 = ADD32(ctx->r4, -0X7C0C);
    // 0x8000320C: j           L_8000321C
    // 0x80003210: nop

        goto L_8000321C;
    // 0x80003210: nop

L_80003214:
    // 0x80003214: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003218: addiu       $a0, $a0, -0x7B9C
    ctx->r4 = ADD32(ctx->r4, -0X7B9C);
L_8000321C:
    // 0x8000321C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003220: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80003224: jal         0x80037DDC
    // 0x80003228: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x80003228: nop

    after_1:
    // 0x8000322C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80003234: jr          $ra
    // 0x80003238: nop

    return;
    // 0x80003238: nop

;}
RECOMP_FUNC void func_8000323C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000323C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003240: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80003244: jal         0x80014DEC
    // 0x80003248: nop

    func_80014DEC(rdram, ctx);
        goto after_0;
    // 0x80003248: nop

    after_0:
    // 0x8000324C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80003250: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x80003254: beq         $v0, $zero, L_800032E0
    if (ctx->r2 == 0) {
        // 0x80003258: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800032E0;
    }
    // 0x80003258: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8000325C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80003260: addu        $at, $at, $v0
    gpr jr_addend_80003268 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80003264: lw          $v0, 0x3248($at)
    ctx->r2 = ADD32(ctx->r1, 0X3248);
    // 0x80003268: jr          $v0
    // 0x8000326C: nop

    switch (jr_addend_80003268 >> 2) {
        case 0: goto L_80003270; break;
        case 1: goto L_80003280; break;
        case 2: goto L_80003290; break;
        case 3: goto L_800032A0; break;
        case 4: goto L_800032B0; break;
        case 5: goto L_800032C0; break;
        case 6: goto L_800032D0; break;
        default: switch_error(__func__, 0x80003268, 0x80093248);
    }
    // 0x8000326C: nop

L_80003270:
    // 0x80003270: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003274: addiu       $a0, $a0, -0x7B2C
    ctx->r4 = ADD32(ctx->r4, -0X7B2C);
    // 0x80003278: j           L_800032E8
    // 0x8000327C: nop

        goto L_800032E8;
    // 0x8000327C: nop

L_80003280:
    // 0x80003280: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003284: addiu       $a0, $a0, -0x7ABC
    ctx->r4 = ADD32(ctx->r4, -0X7ABC);
    // 0x80003288: j           L_800032E8
    // 0x8000328C: nop

        goto L_800032E8;
    // 0x8000328C: nop

L_80003290:
    // 0x80003290: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003294: addiu       $a0, $a0, -0x7A4C
    ctx->r4 = ADD32(ctx->r4, -0X7A4C);
    // 0x80003298: j           L_800032E8
    // 0x8000329C: nop

        goto L_800032E8;
    // 0x8000329C: nop

L_800032A0:
    // 0x800032A0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800032A4: addiu       $a0, $a0, -0x79DC
    ctx->r4 = ADD32(ctx->r4, -0X79DC);
    // 0x800032A8: j           L_800032E8
    // 0x800032AC: nop

        goto L_800032E8;
    // 0x800032AC: nop

L_800032B0:
    // 0x800032B0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800032B4: addiu       $a0, $a0, -0x796C
    ctx->r4 = ADD32(ctx->r4, -0X796C);
    // 0x800032B8: j           L_800032E8
    // 0x800032BC: nop

        goto L_800032E8;
    // 0x800032BC: nop

L_800032C0:
    // 0x800032C0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800032C4: addiu       $a0, $a0, -0x78FC
    ctx->r4 = ADD32(ctx->r4, -0X78FC);
    // 0x800032C8: j           L_800032E8
    // 0x800032CC: nop

        goto L_800032E8;
    // 0x800032CC: nop

L_800032D0:
    // 0x800032D0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800032D4: addiu       $a0, $a0, -0x788C
    ctx->r4 = ADD32(ctx->r4, -0X788C);
    // 0x800032D8: j           L_800032E8
    // 0x800032DC: nop

        goto L_800032E8;
    // 0x800032DC: nop

L_800032E0:
    // 0x800032E0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800032E4: addiu       $a0, $a0, -0x781C
    ctx->r4 = ADD32(ctx->r4, -0X781C);
L_800032E8:
    // 0x800032E8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800032EC: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x800032F0: jal         0x80037DDC
    // 0x800032F4: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x800032F4: nop

    after_1:
    // 0x800032F8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800032FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80003300: jr          $ra
    // 0x80003304: nop

    return;
    // 0x80003304: nop

;}
RECOMP_FUNC void func_80003308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000330C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80003310: jal         0x80014DEC
    // 0x80003314: nop

    func_80014DEC(rdram, ctx);
        goto after_0;
    // 0x80003314: nop

    after_0:
    // 0x80003318: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8000331C: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x80003320: beq         $v0, $zero, L_800033AC
    if (ctx->r2 == 0) {
        // 0x80003324: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800033AC;
    }
    // 0x80003324: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80003328: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000332C: addu        $at, $at, $v0
    gpr jr_addend_80003334 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80003330: lw          $v0, 0x3268($at)
    ctx->r2 = ADD32(ctx->r1, 0X3268);
    // 0x80003334: jr          $v0
    // 0x80003338: nop

    switch (jr_addend_80003334 >> 2) {
        case 0: goto L_8000333C; break;
        case 1: goto L_8000334C; break;
        case 2: goto L_8000335C; break;
        case 3: goto L_8000336C; break;
        case 4: goto L_8000337C; break;
        case 5: goto L_8000338C; break;
        case 6: goto L_8000339C; break;
        default: switch_error(__func__, 0x80003334, 0x80093268);
    }
    // 0x80003338: nop

L_8000333C:
    // 0x8000333C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003340: addiu       $a0, $a0, -0x77AC
    ctx->r4 = ADD32(ctx->r4, -0X77AC);
    // 0x80003344: j           L_800033B4
    // 0x80003348: nop

        goto L_800033B4;
    // 0x80003348: nop

L_8000334C:
    // 0x8000334C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003350: addiu       $a0, $a0, -0x76E4
    ctx->r4 = ADD32(ctx->r4, -0X76E4);
    // 0x80003354: j           L_800033B4
    // 0x80003358: nop

        goto L_800033B4;
    // 0x80003358: nop

L_8000335C:
    // 0x8000335C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003360: addiu       $a0, $a0, -0x761C
    ctx->r4 = ADD32(ctx->r4, -0X761C);
    // 0x80003364: j           L_800033B4
    // 0x80003368: nop

        goto L_800033B4;
    // 0x80003368: nop

L_8000336C:
    // 0x8000336C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003370: addiu       $a0, $a0, -0x7554
    ctx->r4 = ADD32(ctx->r4, -0X7554);
    // 0x80003374: j           L_800033B4
    // 0x80003378: nop

        goto L_800033B4;
    // 0x80003378: nop

L_8000337C:
    // 0x8000337C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003380: addiu       $a0, $a0, -0x748C
    ctx->r4 = ADD32(ctx->r4, -0X748C);
    // 0x80003384: j           L_800033B4
    // 0x80003388: nop

        goto L_800033B4;
    // 0x80003388: nop

L_8000338C:
    // 0x8000338C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003390: addiu       $a0, $a0, -0x73C4
    ctx->r4 = ADD32(ctx->r4, -0X73C4);
    // 0x80003394: j           L_800033B4
    // 0x80003398: nop

        goto L_800033B4;
    // 0x80003398: nop

L_8000339C:
    // 0x8000339C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800033A0: addiu       $a0, $a0, -0x72FC
    ctx->r4 = ADD32(ctx->r4, -0X72FC);
    // 0x800033A4: j           L_800033B4
    // 0x800033A8: nop

        goto L_800033B4;
    // 0x800033A8: nop

L_800033AC:
    // 0x800033AC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800033B0: addiu       $a0, $a0, -0x7234
    ctx->r4 = ADD32(ctx->r4, -0X7234);
L_800033B4:
    // 0x800033B4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800033B8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x800033BC: jal         0x80037DDC
    // 0x800033C0: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x800033C0: nop

    after_1:
    // 0x800033C4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800033C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800033CC: jr          $ra
    // 0x800033D0: nop

    return;
    // 0x800033D0: nop

;}
RECOMP_FUNC void func_800033D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800033D4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800033D8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_800033D4 falls into func_800033DC
    func_800033DC(rdram, ctx);
;}
RECOMP_FUNC void func_800033DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800033DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800033E0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800033E4: addiu       $a0, $a0, -0x716C
    ctx->r4 = ADD32(ctx->r4, -0X716C);
    // 0x800033E8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800033EC: jal         0x80037DDC
    // 0x800033F0: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800033F0: nop

    after_0:
    // 0x800033F4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800033F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800033FC: jr          $ra
    // 0x80003400: nop

    return;
    // 0x80003400: nop

;}
RECOMP_FUNC void func_80003404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003404: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003408: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80003404 falls into func_8000340C
    func_8000340C(rdram, ctx);
;}
RECOMP_FUNC void func_8000340C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000340C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003410: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003414: addiu       $a0, $a0, -0x712C
    ctx->r4 = ADD32(ctx->r4, -0X712C);
    // 0x80003418: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000341C: jal         0x80037DDC
    // 0x80003420: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x80003420: nop

    after_0:
    // 0x80003424: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000342C: jr          $ra
    // 0x80003430: nop

    return;
    // 0x80003430: nop

;}
RECOMP_FUNC void func_80003434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003434: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003438: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80003434 falls into func_8000343C
    func_8000343C(rdram, ctx);
;}
RECOMP_FUNC void func_8000343C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000343C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003440: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003444: addiu       $a0, $a0, -0x70AC
    ctx->r4 = ADD32(ctx->r4, -0X70AC);
    // 0x80003448: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000344C: jal         0x80037DDC
    // 0x80003450: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x80003450: nop

    after_0:
    // 0x80003454: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000345C: jr          $ra
    // 0x80003460: nop

    return;
    // 0x80003460: nop

;}
RECOMP_FUNC void func_80003464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003464: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003468: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80003464 falls into func_8000346C
    func_8000346C(rdram, ctx);
;}
RECOMP_FUNC void func_8000346C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000346C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003470: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003474: addiu       $a0, $a0, -0x70AC
    ctx->r4 = ADD32(ctx->r4, -0X70AC);
    // 0x80003478: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000347C: jal         0x80037DDC
    // 0x80003480: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x80003480: nop

    after_0:
    // 0x80003484: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003488: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000348C: jr          $ra
    // 0x80003490: nop

    return;
    // 0x80003490: nop

;}
RECOMP_FUNC void func_80003494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003494: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003498: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80003494 falls into func_8000349C
    func_8000349C(rdram, ctx);
;}
RECOMP_FUNC void func_8000349C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000349C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800034A0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800034A4: addiu       $a0, $a0, -0x7074
    ctx->r4 = ADD32(ctx->r4, -0X7074);
    // 0x800034A8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800034AC: jal         0x80037DDC
    // 0x800034B0: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800034B0: nop

    after_0:
    // 0x800034B4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800034B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800034BC: jr          $ra
    // 0x800034C0: nop

    return;
    // 0x800034C0: nop

;}
RECOMP_FUNC void func_800034C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800034C4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800034C8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_800034C4 falls into func_800034CC
    func_800034CC(rdram, ctx);
;}
RECOMP_FUNC void func_800034CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800034CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800034D0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800034D4: addiu       $a0, $a0, -0x7034
    ctx->r4 = ADD32(ctx->r4, -0X7034);
    // 0x800034D8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800034DC: jal         0x80037DDC
    // 0x800034E0: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800034E0: nop

    after_0:
    // 0x800034E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800034E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800034EC: jr          $ra
    // 0x800034F0: nop

    return;
    // 0x800034F0: nop

;}
RECOMP_FUNC void func_800034F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800034F4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800034F8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_800034F4 falls into func_800034FC
    func_800034FC(rdram, ctx);
;}
RECOMP_FUNC void func_800034FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800034FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003500: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003504: addiu       $a0, $a0, -0x70EC
    ctx->r4 = ADD32(ctx->r4, -0X70EC);
    // 0x80003508: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000350C: jal         0x80037DDC
    // 0x80003510: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x80003510: nop

    after_0:
    // 0x80003514: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000351C: jr          $ra
    // 0x80003520: nop

    return;
    // 0x80003520: nop

;}
RECOMP_FUNC void func_80003524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003524: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003528: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80003524 falls into func_8000352C
    func_8000352C(rdram, ctx);
;}
RECOMP_FUNC void func_8000352C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000352C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003530: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003534: addiu       $a0, $a0, -0x70E0
    ctx->r4 = ADD32(ctx->r4, -0X70E0);
    // 0x80003538: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000353C: jal         0x80037DDC
    // 0x80003540: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x80003540: nop

    after_0:
    // 0x80003544: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003548: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000354C: jr          $ra
    // 0x80003550: nop

    return;
    // 0x80003550: nop

;}
RECOMP_FUNC void func_80003554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003554: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003558: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80003554 falls into func_8000355C
    func_8000355C(rdram, ctx);
;}
RECOMP_FUNC void func_8000355C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000355C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003560: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003564: addiu       $a0, $a0, -0x7DCC
    ctx->r4 = ADD32(ctx->r4, -0X7DCC);
    // 0x80003568: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000356C: jal         0x80037DDC
    // 0x80003570: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x80003570: nop

    after_0:
    // 0x80003574: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000357C: jr          $ra
    // 0x80003580: nop

    return;
    // 0x80003580: nop

;}
RECOMP_FUNC void func_80003584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003584: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003588: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80003584 falls into func_8000358C
    func_8000358C(rdram, ctx);
;}
RECOMP_FUNC void func_8000358C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000358C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003590: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003594: addiu       $a0, $a0, -0x6F28
    ctx->r4 = ADD32(ctx->r4, -0X6F28);
    // 0x80003598: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000359C: jal         0x80037DDC
    // 0x800035A0: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800035A0: nop

    after_0:
    // 0x800035A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800035A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800035AC: jr          $ra
    // 0x800035B0: nop

    return;
    // 0x800035B0: nop

;}
RECOMP_FUNC void func_800035B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800035B4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800035B8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_800035B4 falls into func_800035BC
    func_800035BC(rdram, ctx);
;}
RECOMP_FUNC void func_800035BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800035BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800035C0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800035C4: addiu       $a0, $a0, -0x6EB8
    ctx->r4 = ADD32(ctx->r4, -0X6EB8);
    // 0x800035C8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800035CC: jal         0x80037DDC
    // 0x800035D0: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800035D0: nop

    after_0:
    // 0x800035D4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800035D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800035DC: jr          $ra
    // 0x800035E0: nop

    return;
    // 0x800035E0: nop

;}
RECOMP_FUNC void func_800035E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800035E4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800035E8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_800035E4 falls into func_800035EC
    func_800035EC(rdram, ctx);
;}
RECOMP_FUNC void func_800035EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800035EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800035F0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800035F4: addiu       $a0, $a0, -0x6E48
    ctx->r4 = ADD32(ctx->r4, -0X6E48);
    // 0x800035F8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800035FC: jal         0x80037DDC
    // 0x80003600: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x80003600: nop

    after_0:
    // 0x80003604: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000360C: jr          $ra
    // 0x80003610: nop

    return;
    // 0x80003610: nop

;}
RECOMP_FUNC void func_80003614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003614: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003618: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000361C: jal         0x80014DEC
    // 0x80003620: nop

    func_80014DEC(rdram, ctx);
        goto after_0;
    // 0x80003620: nop

    after_0:
    // 0x80003624: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80003628: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8000362C: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80003630: beq         $v0, $zero, L_800036AC
    if (ctx->r2 == 0) {
        // 0x80003634: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800036AC;
    }
    // 0x80003634: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80003638: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000363C: addu        $at, $at, $v0
    gpr jr_addend_80003644 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80003640: lw          $v0, 0x3288($at)
    ctx->r2 = ADD32(ctx->r1, 0X3288);
    // 0x80003644: jr          $v0
    // 0x80003648: nop

    switch (jr_addend_80003644 >> 2) {
        case 0: goto L_8000364C; break;
        case 1: goto L_8000365C; break;
        case 2: goto L_8000366C; break;
        case 3: goto L_8000367C; break;
        case 4: goto L_8000368C; break;
        case 5: goto L_8000369C; break;
        default: switch_error(__func__, 0x80003644, 0x80093288);
    }
    // 0x80003648: nop

L_8000364C:
    // 0x8000364C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003650: addiu       $a0, $a0, -0x6E3C
    ctx->r4 = ADD32(ctx->r4, -0X6E3C);
    // 0x80003654: j           L_800036B4
    // 0x80003658: nop

        goto L_800036B4;
    // 0x80003658: nop

L_8000365C:
    // 0x8000365C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003660: addiu       $a0, $a0, -0x6C50
    ctx->r4 = ADD32(ctx->r4, -0X6C50);
    // 0x80003664: j           L_800036B4
    // 0x80003668: nop

        goto L_800036B4;
    // 0x80003668: nop

L_8000366C:
    // 0x8000366C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003670: addiu       $a0, $a0, -0x6A40
    ctx->r4 = ADD32(ctx->r4, -0X6A40);
    // 0x80003674: j           L_800036B4
    // 0x80003678: nop

        goto L_800036B4;
    // 0x80003678: nop

L_8000367C:
    // 0x8000367C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003680: addiu       $a0, $a0, -0x6854
    ctx->r4 = ADD32(ctx->r4, -0X6854);
    // 0x80003684: j           L_800036B4
    // 0x80003688: nop

        goto L_800036B4;
    // 0x80003688: nop

L_8000368C:
    // 0x8000368C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003690: addiu       $a0, $a0, -0x6644
    ctx->r4 = ADD32(ctx->r4, -0X6644);
    // 0x80003694: j           L_800036B4
    // 0x80003698: nop

        goto L_800036B4;
    // 0x80003698: nop

L_8000369C:
    // 0x8000369C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800036A0: addiu       $a0, $a0, -0x6434
    ctx->r4 = ADD32(ctx->r4, -0X6434);
    // 0x800036A4: j           L_800036B4
    // 0x800036A8: nop

        goto L_800036B4;
    // 0x800036A8: nop

L_800036AC:
    // 0x800036AC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800036B0: addiu       $a0, $a0, -0x6248
    ctx->r4 = ADD32(ctx->r4, -0X6248);
L_800036B4:
    // 0x800036B4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800036B8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x800036BC: jal         0x80037DDC
    // 0x800036C0: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x800036C0: nop

    after_1:
    // 0x800036C4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800036C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800036CC: jr          $ra
    // 0x800036D0: nop

    return;
    // 0x800036D0: nop

;}
RECOMP_FUNC void func_800036D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800036D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800036D8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800036DC: jal         0x80014DEC
    // 0x800036E0: nop

    func_80014DEC(rdram, ctx);
        goto after_0;
    // 0x800036E0: nop

    after_0:
    // 0x800036E4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800036E8: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800036EC: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x800036F0: beq         $v0, $zero, L_8000376C
    if (ctx->r2 == 0) {
        // 0x800036F4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8000376C;
    }
    // 0x800036F4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800036F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800036FC: addu        $at, $at, $v0
    gpr jr_addend_80003704 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80003700: lw          $v0, 0x32A0($at)
    ctx->r2 = ADD32(ctx->r1, 0X32A0);
    // 0x80003704: jr          $v0
    // 0x80003708: nop

    switch (jr_addend_80003704 >> 2) {
        case 0: goto L_8000370C; break;
        case 1: goto L_8000371C; break;
        case 2: goto L_8000372C; break;
        case 3: goto L_8000373C; break;
        case 4: goto L_8000374C; break;
        case 5: goto L_8000375C; break;
        default: switch_error(__func__, 0x80003704, 0x800932A0);
    }
    // 0x80003708: nop

L_8000370C:
    // 0x8000370C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003710: addiu       $a0, $a0, -0x6DB0
    ctx->r4 = ADD32(ctx->r4, -0X6DB0);
    // 0x80003714: j           L_80003774
    // 0x80003718: nop

        goto L_80003774;
    // 0x80003718: nop

L_8000371C:
    // 0x8000371C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003720: addiu       $a0, $a0, -0x6BA0
    ctx->r4 = ADD32(ctx->r4, -0X6BA0);
    // 0x80003724: j           L_80003774
    // 0x80003728: nop

        goto L_80003774;
    // 0x80003728: nop

L_8000372C:
    // 0x8000372C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003730: addiu       $a0, $a0, -0x6990
    ctx->r4 = ADD32(ctx->r4, -0X6990);
    // 0x80003734: j           L_80003774
    // 0x80003738: nop

        goto L_80003774;
    // 0x80003738: nop

L_8000373C:
    // 0x8000373C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003740: addiu       $a0, $a0, -0x67A4
    ctx->r4 = ADD32(ctx->r4, -0X67A4);
    // 0x80003744: j           L_80003774
    // 0x80003748: nop

        goto L_80003774;
    // 0x80003748: nop

L_8000374C:
    // 0x8000374C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003750: addiu       $a0, $a0, -0x6594
    ctx->r4 = ADD32(ctx->r4, -0X6594);
    // 0x80003754: j           L_80003774
    // 0x80003758: nop

        goto L_80003774;
    // 0x80003758: nop

L_8000375C:
    // 0x8000375C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003760: addiu       $a0, $a0, -0x6384
    ctx->r4 = ADD32(ctx->r4, -0X6384);
    // 0x80003764: j           L_80003774
    // 0x80003768: nop

        goto L_80003774;
    // 0x80003768: nop

L_8000376C:
    // 0x8000376C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003770: addiu       $a0, $a0, -0x6198
    ctx->r4 = ADD32(ctx->r4, -0X6198);
L_80003774:
    // 0x80003774: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003778: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x8000377C: jal         0x80037DDC
    // 0x80003780: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x80003780: nop

    after_1:
    // 0x80003784: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000378C: jr          $ra
    // 0x80003790: nop

    return;
    // 0x80003790: nop

;}
RECOMP_FUNC void func_80003794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003798: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000379C: jal         0x80014DEC
    // 0x800037A0: nop

    func_80014DEC(rdram, ctx);
        goto after_0;
    // 0x800037A0: nop

    after_0:
    // 0x800037A4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800037A8: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800037AC: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x800037B0: beq         $v0, $zero, L_8000382C
    if (ctx->r2 == 0) {
        // 0x800037B4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8000382C;
    }
    // 0x800037B4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800037B8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800037BC: addu        $at, $at, $v0
    gpr jr_addend_800037C4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800037C0: lw          $v0, 0x32B8($at)
    ctx->r2 = ADD32(ctx->r1, 0X32B8);
    // 0x800037C4: jr          $v0
    // 0x800037C8: nop

    switch (jr_addend_800037C4 >> 2) {
        case 0: goto L_800037CC; break;
        case 1: goto L_800037DC; break;
        case 2: goto L_800037EC; break;
        case 3: goto L_800037FC; break;
        case 4: goto L_8000380C; break;
        case 5: goto L_8000381C; break;
        default: switch_error(__func__, 0x800037C4, 0x800932B8);
    }
    // 0x800037C8: nop

L_800037CC:
    // 0x800037CC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800037D0: addiu       $a0, $a0, -0x6D00
    ctx->r4 = ADD32(ctx->r4, -0X6D00);
    // 0x800037D4: j           L_80003834
    // 0x800037D8: nop

        goto L_80003834;
    // 0x800037D8: nop

L_800037DC:
    // 0x800037DC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800037E0: addiu       $a0, $a0, -0x6AF0
    ctx->r4 = ADD32(ctx->r4, -0X6AF0);
    // 0x800037E4: j           L_80003834
    // 0x800037E8: nop

        goto L_80003834;
    // 0x800037E8: nop

L_800037EC:
    // 0x800037EC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800037F0: addiu       $a0, $a0, -0x6904
    ctx->r4 = ADD32(ctx->r4, -0X6904);
    // 0x800037F4: j           L_80003834
    // 0x800037F8: nop

        goto L_80003834;
    // 0x800037F8: nop

L_800037FC:
    // 0x800037FC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003800: addiu       $a0, $a0, -0x66F4
    ctx->r4 = ADD32(ctx->r4, -0X66F4);
    // 0x80003804: j           L_80003834
    // 0x80003808: nop

        goto L_80003834;
    // 0x80003808: nop

L_8000380C:
    // 0x8000380C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003810: addiu       $a0, $a0, -0x64E4
    ctx->r4 = ADD32(ctx->r4, -0X64E4);
    // 0x80003814: j           L_80003834
    // 0x80003818: nop

        goto L_80003834;
    // 0x80003818: nop

L_8000381C:
    // 0x8000381C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003820: addiu       $a0, $a0, -0x62D4
    ctx->r4 = ADD32(ctx->r4, -0X62D4);
    // 0x80003824: j           L_80003834
    // 0x80003828: nop

        goto L_80003834;
    // 0x80003828: nop

L_8000382C:
    // 0x8000382C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003830: addiu       $a0, $a0, -0x60E8
    ctx->r4 = ADD32(ctx->r4, -0X60E8);
L_80003834:
    // 0x80003834: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003838: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x8000383C: jal         0x80037DDC
    // 0x80003840: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x80003840: nop

    after_1:
    // 0x80003844: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003848: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000384C: jr          $ra
    // 0x80003850: nop

    return;
    // 0x80003850: nop

;}
RECOMP_FUNC void func_80003854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003854: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003858: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80003854 falls into func_8000385C
    func_8000385C(rdram, ctx);
;}
RECOMP_FUNC void func_8000385C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000385C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003860: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003864: addiu       $a0, $a0, -0x6038
    ctx->r4 = ADD32(ctx->r4, -0X6038);
    // 0x80003868: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000386C: jal         0x80037DDC
    // 0x80003870: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x80003870: nop

    after_0:
    // 0x80003874: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000387C: jr          $ra
    // 0x80003880: nop

    return;
    // 0x80003880: nop

;}
RECOMP_FUNC void func_80003884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003884: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80003888: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80003884 falls into func_8000388C
    func_8000388C(rdram, ctx);
;}
RECOMP_FUNC void func_8000388C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000388C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003890: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80003894: addiu       $a0, $a0, -0x6010
    ctx->r4 = ADD32(ctx->r4, -0X6010);
    // 0x80003898: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000389C: jal         0x80037DDC
    // 0x800038A0: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800038A0: nop

    after_0:
    // 0x800038A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800038A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800038AC: jr          $ra
    // 0x800038B0: nop

    return;
    // 0x800038B0: nop

;}
RECOMP_FUNC void func_800038B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800038B4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800038B8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_800038BC
    func_800038BC(rdram, ctx);
}
