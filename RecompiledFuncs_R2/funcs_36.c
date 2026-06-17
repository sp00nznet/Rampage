#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_80029178(uint8_t* rdram, recomp_context* ctx);
void func_8002959C(uint8_t* rdram, recomp_context* ctx);
void func_800295E4(uint8_t* rdram, recomp_context* ctx);
void func_8002A038(uint8_t* rdram, recomp_context* ctx);
void func_8002A338(uint8_t* rdram, recomp_context* ctx);
void func_8002A81C(uint8_t* rdram, recomp_context* ctx);
void func_8002A904(uint8_t* rdram, recomp_context* ctx);
void func_8002AB28(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80028E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028E18: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80028E1C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80028E20: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80028E24: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80028E28: lw          $v1, -0x1034($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1034);
    // 0x80028E2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80028E30: beql        $v1, $v0, L_80028E78
    if (ctx->r3 == ctx->r2) {
        // 0x80028E34: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80028E78;
    }
    goto skip_0;
    // 0x80028E34: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
    // 0x80028E38: beq         $v1, $zero, L_80028E48
    if (ctx->r3 == 0) {
        // 0x80028E3C: sltiu       $v0, $v1, 0x4
        ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
            goto L_80028E48;
    }
    // 0x80028E3C: sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
    // 0x80028E40: bne         $v0, $zero, L_80028E64
    if (ctx->r2 != 0) {
        // 0x80028E44: nop
    
            goto L_80028E64;
    }
    // 0x80028E44: nop

L_80028E48:
    // 0x80028E48: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80028E4C: lhu         $v0, 0x4208($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4208);
    // 0x80028E50: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80028E54: bne         $v0, $zero, L_80028E7C
    if (ctx->r2 != 0) {
        // 0x80028E58: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80028E7C;
    }
    // 0x80028E58: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80028E5C: j           L_80028E7C
    // 0x80028E60: sh          $v0, 0x168($a0)
    MEM_H(0X168, ctx->r4) = ctx->r2;
        goto L_80028E7C;
    // 0x80028E60: sh          $v0, 0x168($a0)
    MEM_H(0X168, ctx->r4) = ctx->r2;
L_80028E64:
    // 0x80028E64: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x80028E68: lhu         $v1, 0x22($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X22);
    // 0x80028E6C: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x80028E70: sh          $v1, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r3;
    // 0x80028E74: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80028E78:
    // 0x80028E78: sh          $v0, 0x168($a0)
    MEM_H(0X168, ctx->r4) = ctx->r2;
L_80028E7C:
    // 0x80028E7C: jr          $ra
    // 0x80028E80: nop

    return;
    // 0x80028E80: nop

;}
RECOMP_FUNC void func_80028E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028E84: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80028E88: lh          $v1, -0x1D66($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X1D66);
    // FALLTHROUGH: func_80028E84 falls into func_80028E8C
    func_80028E8C(rdram, ctx);
;}
RECOMP_FUNC void func_80028E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028E8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80028E90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80028E94: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x80028E98: lw          $s2, 0x31C0($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X31C0);
    // 0x80028E9C: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
    // 0x80028EA0: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80028EA4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80028EA8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80028EAC: beq         $v1, $v0, L_80028EE4
    if (ctx->r3 == ctx->r2) {
        // 0x80028EB0: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80028EE4;
    }
    // 0x80028EB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80028EB4: slti        $v0, $v1, 0x32
    ctx->r2 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
    // 0x80028EB8: beq         $v0, $zero, L_80028ED0
    if (ctx->r2 == 0) {
        // 0x80028EBC: addiu       $v0, $zero, 0x18
        ctx->r2 = ADD32(0, 0X18);
            goto L_80028ED0;
    }
    // 0x80028EBC: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // 0x80028EC0: beq         $v1, $v0, L_80028EE4
    if (ctx->r3 == ctx->r2) {
        // 0x80028EC4: nop
    
            goto L_80028EE4;
    }
    // 0x80028EC4: nop

    // 0x80028EC8: j           L_80028FCC
    // 0x80028ECC: nop

        goto L_80028FCC;
    // 0x80028ECC: nop

L_80028ED0:
    // 0x80028ED0: addiu       $v0, $zero, 0x4A
    ctx->r2 = ADD32(0, 0X4A);
    // 0x80028ED4: beq         $v1, $v0, L_80028EE4
    if (ctx->r3 == ctx->r2) {
        // 0x80028ED8: addiu       $v0, $zero, 0x63
        ctx->r2 = ADD32(0, 0X63);
            goto L_80028EE4;
    }
    // 0x80028ED8: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x80028EDC: bne         $v1, $v0, L_80028FCC
    if (ctx->r3 != ctx->r2) {
        // 0x80028EE0: nop
    
            goto L_80028FCC;
    }
    // 0x80028EE0: nop

L_80028EE4:
    // 0x80028EE4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80028EE8: lh          $v0, -0x5AFC($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5AFC);
    // 0x80028EEC: beq         $v0, $zero, L_80028FCC
    if (ctx->r2 == 0) {
        // 0x80028EF0: nop
    
            goto L_80028FCC;
    }
    // 0x80028EF0: nop

    // 0x80028EF4: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80028EF8: addiu       $s3, $s3, 0x57E0
    ctx->r19 = ADD32(ctx->r19, 0X57E0);
    // 0x80028EFC: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80028F00: andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // 0x80028F04: bne         $v0, $zero, L_80028FA8
    if (ctx->r2 != 0) {
        // 0x80028F08: nop
    
            goto L_80028FA8;
    }
    // 0x80028F08: nop

    // 0x80028F0C: jal         0x800306EC
    // 0x80028F10: addiu       $s1, $zero, 0x7D0
    ctx->r17 = ADD32(0, 0X7D0);
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80028F10: addiu       $s1, $zero, 0x7D0
    ctx->r17 = ADD32(0, 0X7D0);
    after_0:
    // 0x80028F14: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80028F18: addiu       $v1, $v1, -0x71D4
    ctx->r3 = ADD32(ctx->r3, -0X71D4);
    // 0x80028F1C: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x80028F20: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80028F24: lhu         $a0, 0x6($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X6);
    // 0x80028F28: addiu       $v1, $zero, 0xC8
    ctx->r3 = ADD32(0, 0XC8);
    // 0x80028F2C: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x80028F30: addiu       $v1, $zero, 0xFA
    ctx->r3 = ADD32(0, 0XFA);
    // 0x80028F34: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x80028F38: addiu       $v1, $zero, 0x7000
    ctx->r3 = ADD32(0, 0X7000);
    // 0x80028F3C: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x80028F40: sw          $s1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r17;
    // 0x80028F44: ori         $a0, $a0, 0x20
    ctx->r4 = ctx->r4 | 0X20;
    // 0x80028F48: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80028F4C: jal         0x80023E44
    // 0x80028F50: sh          $a0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r4;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x80028F50: sh          $a0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r4;
    after_1:
    // 0x80028F54: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80028F58: lw          $a0, 0x5834($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5834);
    // 0x80028F5C: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    // 0x80028F60: ori         $a1, $a1, 0x404
    ctx->r5 = ctx->r5 | 0X404;
    // 0x80028F64: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80028F68: lhu         $v1, -0x5AFC($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X5AFC);
    // 0x80028F6C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80028F70: addiu       $s0, $s0, 0x31C0
    ctx->r16 = ADD32(ctx->r16, 0X31C0);
    // 0x80028F74: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80028F78: addiu       $v1, $v1, 0x28
    ctx->r3 = ADD32(ctx->r3, 0X28);
    // 0x80028F7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80028F80: sh          $v1, -0x5AFC($at)
    MEM_H(-0X5AFC, ctx->r1) = ctx->r3;
    // 0x80028F84: jal         0x80028B7C
    // 0x80028F88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80028B7C(rdram, ctx);
        goto after_2;
    // 0x80028F88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80028F8C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80028F90: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80028F94: sw          $s1, 0x5834($at)
    MEM_W(0X5834, ctx->r1) = ctx->r17;
    // 0x80028F98: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x80028F9C: ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // 0x80028FA0: j           L_80028FD4
    // 0x80028FA4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
        goto L_80028FD4;
    // 0x80028FA4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
L_80028FA8:
    // 0x80028FA8: lw          $v0, 0x54($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X54);
    // 0x80028FAC: beq         $v0, $zero, L_80028FCC
    if (ctx->r2 == 0) {
        // 0x80028FB0: addiu       $a0, $s3, 0x54
        ctx->r4 = ADD32(ctx->r19, 0X54);
            goto L_80028FCC;
    }
    // 0x80028FB0: addiu       $a0, $s3, 0x54
    ctx->r4 = ADD32(ctx->r19, 0X54);
    // 0x80028FB4: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80028FB8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80028FBC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80028FC0: addiu       $a2, $zero, -0x5
    ctx->r6 = ADD32(0, -0X5);
    // 0x80028FC4: jal         0x80028534
    // 0x80028FC8: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    func_80028534(rdram, ctx);
        goto after_3;
    // 0x80028FC8: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_3:
L_80028FCC:
    // 0x80028FCC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80028FD0: sw          $s2, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r18;
L_80028FD4:
    // 0x80028FD4: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80028FD8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80028FDC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80028FE0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80028FE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80028FE8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80028FEC: jr          $ra
    // 0x80028FF0: nop

    return;
    // 0x80028FF0: nop

;}
RECOMP_FUNC void func_80028FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028FF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028FF8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80028FFC: jal         0x80022CB4
    // 0x80029000: nop

    func_80022CB4(rdram, ctx);
        goto after_0;
    // 0x80029000: nop

    after_0:
    // 0x80029004: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80029008: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8002900C: addiu       $a0, $a0, -0x1030
    ctx->r4 = ADD32(ctx->r4, -0X1030);
    // 0x80029010: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80029014: addiu       $v0, $v0, 0x540
    ctx->r2 = ADD32(ctx->r2, 0X540);
    // 0x80029018: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8002901C: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x80029020: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80029024: sw          $v0, 0x548($at)
    MEM_W(0X548, ctx->r1) = ctx->r2;
    // 0x80029028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002902C: sw          $v0, 0x544($at)
    MEM_W(0X544, ctx->r1) = ctx->r2;
    // 0x80029030: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80029034:
    // 0x80029034: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80029038: beq         $v0, $zero, L_80029048
    if (ctx->r2 == 0) {
        // 0x8002903C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80029048;
    }
    // 0x8002903C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80029040: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80029044: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80029048:
    // 0x80029048: slti        $v0, $a1, 0x7
    ctx->r2 = SIGNED(ctx->r5) < 0X7 ? 1 : 0;
    // 0x8002904C: bne         $v0, $zero, L_80029034
    if (ctx->r2 != 0) {
        // 0x80029050: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80029034;
    }
    // 0x80029050: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80029054: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80029058: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002905C: addiu       $t1, $t1, 0x540
    ctx->r9 = ADD32(ctx->r9, 0X540);
    // 0x80029060: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x80029064: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80029068:
    // 0x80029068: addu        $a2, $t2, $zero
    ctx->r6 = ADD32(ctx->r10, 0);
    // 0x8002906C: addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
L_80029070:
    // 0x80029070: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80029074: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80029078: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002907C: beql        $v0, $zero, L_80029090
    if (ctx->r2 == 0) {
        // 0x80029080: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80029090;
    }
    goto skip_0;
    // 0x80029080: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_0:
    // 0x80029084: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80029088: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x8002908C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_80029090:
    // 0x80029090: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80029094: slti        $v0, $a3, 0x2
    ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x80029098: bne         $v0, $zero, L_80029070
    if (ctx->r2 != 0) {
        // 0x8002909C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80029070;
    }
    // 0x8002909C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800290A0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800290A4: slti        $v0, $t0, 0x2
    ctx->r2 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x800290A8: bne         $v0, $zero, L_80029068
    if (ctx->r2 != 0) {
        // 0x800290AC: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80029068;
    }
    // 0x800290AC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800290B0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800290B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800290B8: jr          $ra
    // 0x800290BC: nop

    return;
    // 0x800290BC: nop

;}
RECOMP_FUNC void func_800290C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800290C0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800290C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800290C8: addiu       $v0, $v0, 0x540
    ctx->r2 = ADD32(ctx->r2, 0X540);
    // 0x800290CC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x800290D0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_800290D4:
    // 0x800290D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800290D8: bnel        $a0, $v0, L_800290EC
    if (ctx->r4 != ctx->r2) {
        // 0x800290DC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800290EC;
    }
    goto skip_0;
    // 0x800290DC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    skip_0:
    // 0x800290E0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800290E4: j           L_80029104
    // 0x800290E8: nop

        goto L_80029104;
    // 0x800290E8: nop

L_800290EC:
    // 0x800290EC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800290F0: slti        $v0, $a2, 0x2
    ctx->r2 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x800290F4: bne         $v0, $zero, L_800290D4
    if (ctx->r2 != 0) {
        // 0x800290F8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800290D4;
    }
    // 0x800290F8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800290FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80029100: lw          $v0, 0x540($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X540);
L_80029104:
    // 0x80029104: jr          $ra
    // 0x80029108: nop

    return;
    // 0x80029108: nop

    // 0x8002910C: nop

;}
RECOMP_FUNC void func_80029110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029110: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80029114: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80029118: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x8002911C: lhu         $s1, -0x6DC4($s1)
    ctx->r17 = MEM_HU(ctx->r17, -0X6DC4);
    // 0x80029120: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80029124: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80029128: addiu       $s0, $s0, 0x50F8
    ctx->r16 = ADD32(ctx->r16, 0X50F8);
    // 0x8002912C: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x80029130: beq         $v0, $zero, L_80029160
    if (ctx->r2 == 0) {
        // 0x80029134: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80029160;
    }
    // 0x80029134: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80029138: sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x8002913C: beql        $v0, $zero, L_80029144
    if (ctx->r2 == 0) {
        // 0x80029140: addiu       $s1, $zero, 0x8
        ctx->r17 = ADD32(0, 0X8);
            goto L_80029144;
    }
    goto skip_0;
    // 0x80029140: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    skip_0:
L_80029144:
    // 0x80029144: jal         0x80029178
    // 0x80029148: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80029178(rdram, ctx);
        goto after_0;
    // 0x80029148: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8002914C: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x80029150: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80029154: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80029158: bne         $v0, $zero, L_80029144
    if (ctx->r2 != 0) {
        // 0x8002915C: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_80029144;
    }
    // 0x8002915C: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
L_80029160:
    // 0x80029160: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80029164: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80029168: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002916C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80029170: jr          $ra
    // 0x80029174: nop

    return;
    // 0x80029174: nop

;}
RECOMP_FUNC void func_80029178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002917C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80029180: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80029184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029188: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002918C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80029190: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x80029194: jal         0x80023470
    // 0x80029198: nop

    func_80023470(rdram, ctx);
        goto after_0;
    // 0x80029198: nop

    after_0:
    // 0x8002919C: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x800291A0: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800291A4: sltiu       $v0, $v1, 0x1C
    ctx->r2 = ctx->r3 < 0X1C ? 1 : 0;
    // 0x800291A8: beq         $v0, $zero, L_8002921C
    if (ctx->r2 == 0) {
        // 0x800291AC: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8002921C;
    }
    // 0x800291AC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800291B0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800291B4: addu        $at, $at, $v0
    gpr jr_addend_800291BC = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800291B8: lw          $v0, 0x3A98($at)
    ctx->r2 = ADD32(ctx->r1, 0X3A98);
    // 0x800291BC: jr          $v0
    // 0x800291C0: nop

    switch (jr_addend_800291BC >> 2) {
        case 0: goto L_800291C4; break;
        case 1: goto L_800291C4; break;
        case 2: goto L_800291C4; break;
        case 3: goto L_800291C4; break;
        case 4: goto L_800291C4; break;
        case 5: goto L_800291C4; break;
        case 6: goto L_800291C4; break;
        case 7: goto L_800291C4; break;
        case 8: goto L_800291C4; break;
        case 9: goto L_800291C4; break;
        case 10: goto L_800291C4; break;
        case 11: goto L_800291C4; break;
        case 12: goto L_800291C4; break;
        case 13: goto L_800291C4; break;
        case 14: goto L_800291C4; break;
        case 15: goto L_800291C4; break;
        case 16: goto L_800291C4; break;
        case 17: goto L_800291C4; break;
        case 18: goto L_800291C4; break;
        case 19: goto L_80029214; break;
        case 20: goto L_80029214; break;
        case 21: goto L_800291F4; break;
        case 22: goto L_800291F4; break;
        case 23: goto L_800291D4; break;
        case 24: goto L_8002921C; break;
        case 25: goto L_800291E4; break;
        case 26: goto L_80029204; break;
        case 27: goto L_800291E4; break;
        default: switch_error(__func__, 0x800291BC, 0x80093A98);
    }
    // 0x800291C0: nop

L_800291C4:
    // 0x800291C4: jal         0x80016D74
    // 0x800291C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80016D74(rdram, ctx);
        goto after_1;
    // 0x800291C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800291CC: j           L_8002921C
    // 0x800291D0: nop

        goto L_8002921C;
    // 0x800291D0: nop

L_800291D4:
    // 0x800291D4: jal         0x800180A8
    // 0x800291D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800180A8(rdram, ctx);
        goto after_2;
    // 0x800291D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800291DC: j           L_8002921C
    // 0x800291E0: nop

        goto L_8002921C;
    // 0x800291E0: nop

L_800291E4:
    // 0x800291E4: jal         0x8001867C
    // 0x800291E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001867C(rdram, ctx);
        goto after_3;
    // 0x800291E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800291EC: j           L_8002921C
    // 0x800291F0: nop

        goto L_8002921C;
    // 0x800291F0: nop

L_800291F4:
    // 0x800291F4: jal         0x800175A8
    // 0x800291F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800175A8(rdram, ctx);
        goto after_4;
    // 0x800291F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x800291FC: j           L_8002921C
    // 0x80029200: nop

        goto L_8002921C;
    // 0x80029200: nop

L_80029204:
    // 0x80029204: jal         0x80017AF0
    // 0x80029208: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80017AF0(rdram, ctx);
        goto after_5;
    // 0x80029208: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x8002920C: j           L_8002921C
    // 0x80029210: nop

        goto L_8002921C;
    // 0x80029210: nop

L_80029214:
    // 0x80029214: jal         0x80017DB0
    // 0x80029218: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80017DB0(rdram, ctx);
        goto after_6;
    // 0x80029218: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
L_8002921C:
    // 0x8002921C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029220: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80029224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80029228: jr          $ra
    // 0x8002922C: nop

    return;
    // 0x8002922C: nop

;}
RECOMP_FUNC void func_80029230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029230: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80029234: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80029238: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x8002923C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80029240: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80029244: addiu       $s0, $s0, 0x50F8
    ctx->r16 = ADD32(ctx->r16, 0X50F8);
    // 0x80029248: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_8002924C:
    // 0x8002924C: jal         0x8002959C
    // 0x80029250: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002959C(rdram, ctx);
        goto after_0;
    // 0x80029250: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80029254: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x80029258: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8002925C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80029260: bne         $v0, $zero, L_8002924C
    if (ctx->r2 != 0) {
        // 0x80029264: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_8002924C;
    }
    // 0x80029264: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x80029268: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8002926C: sh          $zero, -0x6DC4($at)
    MEM_H(-0X6DC4, ctx->r1) = 0;
    // 0x80029270: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80029274: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80029278: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002927C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80029280: jr          $ra
    // 0x80029284: nop

    return;
    // 0x80029284: nop

;}
RECOMP_FUNC void func_80029288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002928C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80029290: jal         0x80029230
    // 0x80029294: nop

    func_80029230(rdram, ctx);
        goto after_0;
    // 0x80029294: nop

    after_0:
    // 0x80029298: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002929C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800292A0: jr          $ra
    // 0x800292A4: nop

    return;
    // 0x800292A4: nop

;}
RECOMP_FUNC void func_800292A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800292A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800292AC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800292B0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800292B4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800292B8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800292BC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800292C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800292C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800292C8: jal         0x80029230
    // 0x800292CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80029230(rdram, ctx);
        goto after_0;
    // 0x800292CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800292D0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800292D4: addiu       $a0, $a0, 0x61C0
    ctx->r4 = ADD32(ctx->r4, 0X61C0);
    // 0x800292D8: jal         0x8003DBCC
    // 0x800292DC: nop

    func_8003DBCC(rdram, ctx);
        goto after_1;
    // 0x800292DC: nop

    after_1:
    // 0x800292E0: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800292E4: lhu         $s5, 0x4($s3)
    ctx->r21 = MEM_HU(ctx->r19, 0X4);
    // 0x800292E8: andi        $v0, $s5, 0xFFFF
    ctx->r2 = ctx->r21 & 0XFFFF;
    // 0x800292EC: beq         $v0, $zero, L_800294E8
    if (ctx->r2 == 0) {
        // 0x800292F0: addiu       $s3, $s3, 0x10
        ctx->r19 = ADD32(ctx->r19, 0X10);
            goto L_800294E8;
    }
    // 0x800292F0: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x800292F4: sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x800292F8: beql        $v0, $zero, L_80029300
    if (ctx->r2 == 0) {
        // 0x800292FC: addiu       $s5, $zero, 0x8
        ctx->r21 = ADD32(0, 0X8);
            goto L_80029300;
    }
    goto skip_0;
    // 0x800292FC: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    skip_0:
L_80029300:
    // 0x80029300: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80029304: sh          $s5, -0x6DC4($at)
    MEM_H(-0X6DC4, ctx->r1) = ctx->r21;
    // 0x80029308: lui         $s4, 0x8015
    ctx->r20 = S32(0X8015 << 16);
    // 0x8002930C: addiu       $s4, $s4, 0x50F8
    ctx->r20 = ADD32(ctx->r20, 0X50F8);
    // 0x80029310: addiu       $s6, $zero, 0x71A
    ctx->r22 = ADD32(0, 0X71A);
    // 0x80029314: addiu       $s1, $s4, 0x40
    ctx->r17 = ADD32(ctx->r20, 0X40);
    // 0x80029318: addiu       $s2, $s3, 0xE
    ctx->r18 = ADD32(ctx->r19, 0XE);
L_8002931C:
    // 0x8002931C: jal         0x800306EC
    // 0x80029320: nop

    func_800306EC(rdram, ctx);
        goto after_2;
    // 0x80029320: nop

    after_2:
    // 0x80029324: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80029328: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x8002932C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80029330: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80029334: sw          $v1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r3;
    // 0x80029338: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002933C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80029340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80029344: sh          $zero, -0x36($s1)
    MEM_H(-0X36, ctx->r17) = 0;
    // 0x80029348: sh          $v0, -0x38($s1)
    MEM_H(-0X38, ctx->r17) = ctx->r2;
    // 0x8002934C: lhu         $v0, -0xA($s2)
    ctx->r2 = MEM_HU(ctx->r18, -0XA);
    // 0x80029350: jal         0x80023E44
    // 0x80029354: sh          $v0, -0x3A($s1)
    MEM_H(-0X3A, ctx->r17) = ctx->r2;
    func_80023E44(rdram, ctx);
        goto after_3;
    // 0x80029354: sh          $v0, -0x3A($s1)
    MEM_H(-0X3A, ctx->r17) = ctx->r2;
    after_3:
    // 0x80029358: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8002935C: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    // 0x80029360: sw          $s4, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r20;
    // 0x80029364: lhu         $v0, -0x8($s2)
    ctx->r2 = MEM_HU(ctx->r18, -0X8);
    // 0x80029368: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    // 0x8002936C: lhu         $v0, -0x6($s2)
    ctx->r2 = MEM_HU(ctx->r18, -0X6);
    // 0x80029370: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // 0x80029374: lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X22);
    // 0x80029378: lhu         $v1, -0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, -0X4);
    // 0x8002937C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80029380: sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    // 0x80029384: lhu         $v0, -0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, -0X2);
    // 0x80029388: sh          $v0, 0x80($s0)
    MEM_H(0X80, ctx->r16) = ctx->r2;
    // 0x8002938C: lhu         $v1, -0x3A($s1)
    ctx->r3 = MEM_HU(ctx->r17, -0X3A);
    // 0x80029390: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
    // 0x80029394: beql        $v1, $v0, L_800293AC
    if (ctx->r3 == ctx->r2) {
        // 0x80029398: sh          $s6, 0x70($s0)
        MEM_H(0X70, ctx->r16) = ctx->r22;
            goto L_800293AC;
    }
    goto skip_1;
    // 0x80029398: sh          $s6, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r22;
    skip_1:
    // 0x8002939C: lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18);
    // 0x800293A0: addiu       $v0, $v0, 0xF23
    ctx->r2 = ADD32(ctx->r2, 0XF23);
    // 0x800293A4: sh          $v0, 0x80($s0)
    MEM_H(0X80, ctx->r16) = ctx->r2;
    // 0x800293A8: sh          $s6, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r22;
L_800293AC:
    // 0x800293AC: lh          $v1, 0x0($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X0);
    // 0x800293B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800293B4: bne         $v1, $v0, L_800293D0
    if (ctx->r3 != ctx->r2) {
        // 0x800293B8: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_800293D0;
    }
    // 0x800293B8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800293BC: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x800293C0: jal         0x80001414
    // 0x800293C4: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_80001414(rdram, ctx);
        goto after_4;
    // 0x800293C4: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_4:
    // 0x800293C8: j           L_800293D4
    // 0x800293CC: sh          $v0, -0x24($s1)
    MEM_H(-0X24, ctx->r17) = ctx->r2;
        goto L_800293D4;
    // 0x800293CC: sh          $v0, -0x24($s1)
    MEM_H(-0X24, ctx->r17) = ctx->r2;
L_800293D0:
    // 0x800293D0: sh          $a0, -0x24($s1)
    MEM_H(-0X24, ctx->r17) = ctx->r4;
L_800293D4:
    // 0x800293D4: lhu         $v0, -0x3A($s1)
    ctx->r2 = MEM_HU(ctx->r17, -0X3A);
    // 0x800293D8: addiu       $v0, $v0, -0x16
    ctx->r2 = ADD32(ctx->r2, -0X16);
    // 0x800293DC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800293E0: bne         $v0, $zero, L_800293F0
    if (ctx->r2 != 0) {
        // 0x800293E4: nop
    
            goto L_800293F0;
    }
    // 0x800293E4: nop

    // 0x800293E8: jal         0x8000B2F8
    // 0x800293EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000B2F8(rdram, ctx);
        goto after_5;
    // 0x800293EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
L_800293F0:
    // 0x800293F0: lhu         $v0, -0x3A($s1)
    ctx->r2 = MEM_HU(ctx->r17, -0X3A);
    // 0x800293F4: addiu       $v0, $v0, -0xD
    ctx->r2 = ADD32(ctx->r2, -0XD);
    // 0x800293F8: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x800293FC: beql        $v0, $zero, L_800294CC
    if (ctx->r2 == 0) {
        // 0x80029400: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_800294CC;
    }
    goto skip_2;
    // 0x80029400: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    skip_2:
    // 0x80029404: lhu         $v0, 0x80($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X80);
    // 0x80029408: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8002940C: jal         0x800306EC
    // 0x80029410: sh          $v0, 0x80($s0)
    MEM_H(0X80, ctx->r16) = ctx->r2;
    func_800306EC(rdram, ctx);
        goto after_6;
    // 0x80029410: sh          $v0, 0x80($s0)
    MEM_H(0X80, ctx->r16) = ctx->r2;
    after_6:
    // 0x80029414: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80029418: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x8002941C: lhu         $v1, -0x3A($s1)
    ctx->r3 = MEM_HU(ctx->r17, -0X3A);
    // 0x80029420: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80029424: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80029428: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8002942C: lw          $v1, 0x5F3C($at)
    ctx->r3 = MEM_W(ctx->r1, 0X5F3C);
    // 0x80029430: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80029434: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80029438: lhu         $v1, -0x3A($s1)
    ctx->r3 = MEM_HU(ctx->r17, -0X3A);
    // 0x8002943C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x80029440: bne         $v1, $v0, L_80029468
    if (ctx->r3 != ctx->r2) {
        // 0x80029444: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80029468;
    }
    // 0x80029444: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80029448: lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X22);
    // 0x8002944C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80029450: beq         $v0, $zero, L_80029464
    if (ctx->r2 == 0) {
        // 0x80029454: lui         $v0, 0x800
        ctx->r2 = S32(0X800 << 16);
            goto L_80029464;
    }
    // 0x80029454: lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
    // 0x80029458: ori         $v0, $v0, 0x27EA
    ctx->r2 = ctx->r2 | 0X27EA;
    // 0x8002945C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80029460: lhu         $v1, -0x3A($s1)
    ctx->r3 = MEM_HU(ctx->r17, -0X3A);
L_80029464:
    // 0x80029464: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80029468:
    // 0x80029468: bne         $v1, $v0, L_80029488
    if (ctx->r3 != ctx->r2) {
        // 0x8002946C: nop
    
            goto L_80029488;
    }
    // 0x8002946C: nop

    // 0x80029470: lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X22);
    // 0x80029474: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80029478: beq         $v0, $zero, L_80029488
    if (ctx->r2 == 0) {
        // 0x8002947C: lui         $v0, 0x800
        ctx->r2 = S32(0X800 << 16);
            goto L_80029488;
    }
    // 0x8002947C: lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
    // 0x80029480: ori         $v0, $v0, 0x27F4
    ctx->r2 = ctx->r2 | 0X27F4;
    // 0x80029484: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_80029488:
    // 0x80029488: jal         0x80023E44
    // 0x8002948C: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    func_80023E44(rdram, ctx);
        goto after_7;
    // 0x8002948C: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    after_7:
    // 0x80029490: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80029494: lhu         $v1, 0x22($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X22);
    // 0x80029498: sh          $v1, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r3;
    // 0x8002949C: lhu         $v0, 0x80($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X80);
    // 0x800294A0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800294A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800294A8: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
    // 0x800294AC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800294B0: sh          $s6, 0x70($v0)
    MEM_H(0X70, ctx->r2) = ctx->r22;
    // 0x800294B4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800294B8: lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X14);
    // 0x800294BC: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
    // 0x800294C0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800294C4: lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18);
    // 0x800294C8: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
L_800294CC:
    // 0x800294CC: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x800294D0: addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    // 0x800294D4: addiu       $v0, $s5, -0x1
    ctx->r2 = ADD32(ctx->r21, -0X1);
    // 0x800294D8: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x800294DC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800294E0: bne         $v0, $zero, L_8002931C
    if (ctx->r2 != 0) {
        // 0x800294E4: addiu       $s4, $s4, 0x58
        ctx->r20 = ADD32(ctx->r20, 0X58);
            goto L_8002931C;
    }
    // 0x800294E4: addiu       $s4, $s4, 0x58
    ctx->r20 = ADD32(ctx->r20, 0X58);
L_800294E8:
    // 0x800294E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800294EC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800294F0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800294F4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800294F8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800294FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80029500: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80029504: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029508: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8002950C: jr          $ra
    // 0x80029510: nop

    return;
    // 0x80029510: nop

;}
RECOMP_FUNC void func_80029514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029514: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80029518: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8002951C: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x80029520: lhu         $s1, -0x6DC4($s1)
    ctx->r17 = MEM_HU(ctx->r17, -0X6DC4);
    // 0x80029524: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80029528: beq         $s1, $zero, L_8002957C
    if (ctx->r17 == 0) {
        // 0x8002952C: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8002957C;
    }
    // 0x8002952C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80029530: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80029534: addiu       $s0, $s0, 0x50F8
    ctx->r16 = ADD32(ctx->r16, 0X50F8);
L_80029538:
    // 0x80029538: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8002953C: beq         $a0, $zero, L_8002954C
    if (ctx->r4 == 0) {
        // 0x80029540: nop
    
            goto L_8002954C;
    }
    // 0x80029540: nop

    // 0x80029544: jal         0x80024764
    // 0x80029548: nop

    func_80024764(rdram, ctx);
        goto after_0;
    // 0x80029548: nop

    after_0:
L_8002954C:
    // 0x8002954C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80029550: beq         $a0, $zero, L_8002956C
    if (ctx->r4 == 0) {
        // 0x80029554: addiu       $v0, $s1, -0x1
        ctx->r2 = ADD32(ctx->r17, -0X1);
            goto L_8002956C;
    }
    // 0x80029554: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x80029558: jal         0x80024764
    // 0x8002955C: nop

    func_80024764(rdram, ctx);
        goto after_1;
    // 0x8002955C: nop

    after_1:
    // 0x80029560: jal         0x8002959C
    // 0x80029564: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002959C(rdram, ctx);
        goto after_2;
    // 0x80029564: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80029568: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
L_8002956C:
    // 0x8002956C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80029570: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80029574: bne         $v0, $zero, L_80029538
    if (ctx->r2 != 0) {
        // 0x80029578: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_80029538;
    }
    // 0x80029578: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
L_8002957C:
    // 0x8002957C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80029580: sh          $zero, -0x6DC4($at)
    MEM_H(-0X6DC4, ctx->r1) = 0;
    // 0x80029584: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80029588: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002958C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80029590: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80029594: jr          $ra
    // 0x80029598: nop

    return;
    // 0x80029598: nop

;}
RECOMP_FUNC void func_8002959C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002959C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800295A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800295A4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800295A8: jal         0x8007DEC0
    // 0x800295AC: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    func_8007DEC0(rdram, ctx);
        goto after_0;
    // 0x800295AC: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    after_0:
    // 0x800295B0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800295B4: sh          $zero, -0x6DC4($at)
    MEM_H(-0X6DC4, ctx->r1) = 0;
    // 0x800295B8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800295BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800295C0: jr          $ra
    // 0x800295C4: nop

    return;
    // 0x800295C4: nop

;}
RECOMP_FUNC void func_800295C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800295C8: lh          $v0, 0x14($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X14);
    // 0x800295CC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800295D0: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x800295D4: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x800295D8: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x800295DC: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800295E0: beq         $v0, $zero, L_800295FC
    if (ctx->r2 == 0) {
                func_800295E4(rdram, ctx); return; // was goto L_800295FC
    }
;}
RECOMP_FUNC void func_800295E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800295E4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800295E8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800295EC: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x800295F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800295F4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800295F8: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x800295FC: lhu         $t1, 0x18($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X18);
    // 0x80029600: lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X22);
    // 0x80029604: lhu         $a0, 0x10($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X10);
    // 0x80029608: lhu         $v1, 0x12($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X12);
    // 0x8002960C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80029610: bnel        $v0, $zero, L_80029618
    if (ctx->r2 != 0) {
        // 0x80029614: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_80029618;
    }
    goto skip_0;
    // 0x80029614: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    skip_0:
L_80029618:
    // 0x80029618: lhu         $a2, 0x14($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X14);
    // 0x8002961C: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80029620: lhu         $v1, 0x16($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X16);
    // 0x80029624: beq         $v0, $zero, L_80029630
    if (ctx->r2 == 0) {
        // 0x80029628: addu        $a0, $a0, $a3
        ctx->r4 = ADD32(ctx->r4, ctx->r7);
            goto L_80029630;
    }
    // 0x80029628: addu        $a0, $a0, $a3
    ctx->r4 = ADD32(ctx->r4, ctx->r7);
    // 0x8002962C: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
L_80029630:
    // 0x80029630: addu        $a2, $a2, $a3
    ctx->r6 = ADD32(ctx->r6, ctx->r7);
    // 0x80029634: beq         $v0, $zero, L_80029648
    if (ctx->r2 == 0) {
        // 0x80029638: addu        $t0, $v1, $t1
        ctx->r8 = ADD32(ctx->r3, ctx->r9);
            goto L_80029648;
    }
    // 0x80029638: addu        $t0, $v1, $t1
    ctx->r8 = ADD32(ctx->r3, ctx->r9);
    // 0x8002963C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x80029640: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x80029644: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_80029648:
    // 0x80029648: lhu         $t1, 0x11E($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X11E);
    // 0x8002964C: lhu         $a3, 0x11A($a1)
    ctx->r7 = MEM_HU(ctx->r5, 0X11A);
    // 0x80029650: lh          $v1, 0x11C($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X11C);
    // 0x80029654: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80029658: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002965C: lh          $a1, 0x118($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X118);
    // 0x80029660: slt         $a0, $a0, $v1
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029664: sll         $v1, $a2, 16
    ctx->r3 = S32(ctx->r6 << 16);
    // 0x80029668: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8002966C: slt         $a1, $a1, $v1
    ctx->r5 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029670: and         $a0, $a0, $a1
    ctx->r4 = ctx->r4 & ctx->r5;
    // 0x80029674: beq         $a0, $zero, L_800296A8
    if (ctx->r4 == 0) {
        // 0x80029678: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800296A8;
    }
    // 0x80029678: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8002967C: sll         $a0, $t2, 16
    ctx->r4 = S32(ctx->r10 << 16);
    // 0x80029680: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80029684: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x80029688: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002968C: slt         $a0, $a0, $v0
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80029690: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x80029694: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80029698: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x8002969C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800296A0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800296A4: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
L_800296A8:
    // 0x800296A8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800296AC: jr          $ra
    // 0x800296B0: nop

    return;
    // 0x800296B0: nop

;}
RECOMP_FUNC void func_800296B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800296B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800296B8: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800296BC: lui         $s6, 0x8016
    ctx->r22 = S32(0X8016 << 16);
    // 0x800296C0: lhu         $s6, -0x6DC4($s6)
    ctx->r22 = MEM_HU(ctx->r22, -0X6DC4);
    // 0x800296C4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800296C8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800296CC: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800296D0: lui         $s5, 0x8015
    ctx->r21 = S32(0X8015 << 16);
    // 0x800296D4: addiu       $s5, $s5, 0x50F8
    ctx->r21 = ADD32(ctx->r21, 0X50F8);
    // 0x800296D8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800296DC: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x800296E0: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x800296E4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800296E8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800296EC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800296F0: beq         $s6, $zero, L_800298D4
    if (ctx->r22 == 0) {
        // 0x800296F4: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800298D4;
    }
    // 0x800296F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800296F8: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x800296FC: lui         $fp, 0x8015
    ctx->r30 = S32(0X8015 << 16);
    // 0x80029700: addiu       $fp, $fp, 0x4198
    ctx->r30 = ADD32(ctx->r30, 0X4198);
    // 0x80029704: addiu       $s3, $s5, 0x1A
    ctx->r19 = ADD32(ctx->r21, 0X1A);
L_80029708:
    // 0x80029708: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8002970C: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80029710: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80029714: bnel        $v0, $zero, L_800298C0
    if (ctx->r2 != 0) {
        // 0x80029718: addiu       $s3, $s3, 0x58
        ctx->r19 = ADD32(ctx->r19, 0X58);
            goto L_800298C0;
    }
    goto skip_0;
    // 0x80029718: addiu       $s3, $s3, 0x58
    ctx->r19 = ADD32(ctx->r19, 0X58);
    skip_0:
    // 0x8002971C: lhu         $v1, -0x12($s3)
    ctx->r3 = MEM_HU(ctx->r19, -0X12);
    // 0x80029720: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80029724: bnel        $v1, $v0, L_800298C0
    if (ctx->r3 != ctx->r2) {
        // 0x80029728: addiu       $s3, $s3, 0x58
        ctx->r19 = ADD32(ctx->r19, 0X58);
            goto L_800298C0;
    }
    goto skip_1;
    // 0x80029728: addiu       $s3, $s3, 0x58
    ctx->r19 = ADD32(ctx->r19, 0X58);
    skip_1:
    // 0x8002972C: lhu         $a0, -0x14($s3)
    ctx->r4 = MEM_HU(ctx->r19, -0X14);
    // 0x80029730: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80029734: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80029738: sltiu       $v0, $v0, 0x1D
    ctx->r2 = ctx->r2 < 0X1D ? 1 : 0;
    // 0x8002973C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80029740: beq         $v1, $zero, L_800298BC
    if (ctx->r3 == 0) {
        // 0x80029744: addiu       $v0, $a0, -0xD
        ctx->r2 = ADD32(ctx->r4, -0XD);
            goto L_800298BC;
    }
    // 0x80029744: addiu       $v0, $a0, -0xD
    ctx->r2 = ADD32(ctx->r4, -0XD);
    // 0x80029748: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x8002974C: beq         $v0, $zero, L_800297D8
    if (ctx->r2 == 0) {
        // 0x80029750: nop
    
            goto L_800297D8;
    }
    // 0x80029750: nop

    // 0x80029754: lw          $a0, 0x26($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X26);
    // 0x80029758: beq         $a0, $zero, L_800297D8
    if (ctx->r4 == 0) {
        // 0x8002975C: nop
    
            goto L_800297D8;
    }
    // 0x8002975C: nop

    // 0x80029760: jal         0x800295C8
    // 0x80029764: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_800295C8(rdram, ctx);
        goto after_0;
    // 0x80029764: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_0:
    // 0x80029768: beq         $v0, $zero, L_800297D8
    if (ctx->r2 == 0) {
        // 0x8002976C: addiu       $a0, $zero, 0x28
        ctx->r4 = ADD32(0, 0X28);
            goto L_800297D8;
    }
    // 0x8002976C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80029770: lhu         $v0, 0x24($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X24);
    // 0x80029774: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80029778: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002977C: jal         0x8003C34C
    // 0x80029780: sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    func_8003C34C(rdram, ctx);
        goto after_1;
    // 0x80029780: sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    after_1:
    // 0x80029784: sw          $s2, 0x3A($s3)
    MEM_W(0X3A, ctx->r19) = ctx->r18;
    // 0x80029788: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8002978C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80029790: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80029794: sh          $v0, 0x2A($s3)
    MEM_H(0X2A, ctx->r19) = ctx->r2;
    // 0x80029798: lhu         $v0, 0x120($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X120);
    // 0x8002979C: sh          $v0, 0x34($s3)
    MEM_H(0X34, ctx->r19) = ctx->r2;
    // 0x800297A0: lhu         $v0, 0x122($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X122);
    // 0x800297A4: sh          $v0, 0x36($s3)
    MEM_H(0X36, ctx->r19) = ctx->r2;
    // 0x800297A8: lhu         $v0, 0x142($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X142);
    // 0x800297AC: beql        $v0, $zero, L_800297C4
    if (ctx->r2 == 0) {
        // 0x800297B0: sh          $s7, 0x18A($s2)
        MEM_H(0X18A, ctx->r18) = ctx->r23;
            goto L_800297C4;
    }
    goto skip_2;
    // 0x800297B0: sh          $s7, 0x18A($s2)
    MEM_H(0X18A, ctx->r18) = ctx->r23;
    skip_2:
    // 0x800297B4: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x800297B8: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800297BC: sh          $v0, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r2;
    // 0x800297C0: sh          $s7, 0x18A($s2)
    MEM_H(0X18A, ctx->r18) = ctx->r23;
L_800297C4:
    // 0x800297C4: jal         0x80016FA8
    // 0x800297C8: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_80016FA8(rdram, ctx);
        goto after_2;
    // 0x800297C8: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_2:
    // 0x800297CC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800297D0: jal         0x80060F30
    // 0x800297D4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80060F30(rdram, ctx);
        goto after_3;
    // 0x800297D4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
L_800297D8:
    // 0x800297D8: lhu         $v0, -0x14($s3)
    ctx->r2 = MEM_HU(ctx->r19, -0X14);
    // 0x800297DC: addiu       $v0, $v0, -0x16
    ctx->r2 = ADD32(ctx->r2, -0X16);
    // 0x800297E0: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800297E4: beq         $v0, $zero, L_80029838
    if (ctx->r2 == 0) {
        // 0x800297E8: nop
    
            goto L_80029838;
    }
    // 0x800297E8: nop

    // 0x800297EC: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800297F0: addu        $s1, $fp, $zero
    ctx->r17 = ADD32(ctx->r30, 0);
L_800297F4:
    // 0x800297F4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800297F8: beql        $s0, $zero, L_8002982C
    if (ctx->r16 == 0) {
        // 0x800297FC: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8002982C;
    }
    goto skip_3;
    // 0x800297FC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_3:
    // 0x80029800: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80029804: jal         0x800295C8
    // 0x80029808: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_800295C8(rdram, ctx);
        goto after_4;
    // 0x80029808: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_4:
    // 0x8002980C: beql        $v0, $zero, L_8002982C
    if (ctx->r2 == 0) {
        // 0x80029810: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8002982C;
    }
    goto skip_4;
    // 0x80029810: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_4:
    // 0x80029814: jal         0x8004C79C
    // 0x80029818: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    func_8004C79C(rdram, ctx);
        goto after_5;
    // 0x80029818: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    after_5:
    // 0x8002981C: jal         0x80017660
    // 0x80029820: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80017660(rdram, ctx);
        goto after_6;
    // 0x80029820: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x80029824: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80029828: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8002982C:
    // 0x8002982C: slti        $v0, $s4, 0x3
    ctx->r2 = SIGNED(ctx->r20) < 0X3 ? 1 : 0;
    // 0x80029830: bne         $v0, $zero, L_800297F4
    if (ctx->r2 != 0) {
        // 0x80029834: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800297F4;
    }
    // 0x80029834: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80029838:
    // 0x80029838: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8002983C: jal         0x800295C8
    // 0x80029840: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_800295C8(rdram, ctx);
        goto after_7;
    // 0x80029840: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_7:
    // 0x80029844: beq         $v0, $zero, L_800298BC
    if (ctx->r2 == 0) {
        // 0x80029848: addiu       $a0, $zero, 0x28
        ctx->r4 = ADD32(0, 0X28);
            goto L_800298BC;
    }
    // 0x80029848: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8002984C: lhu         $v0, 0x24($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X24);
    // 0x80029850: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80029854: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80029858: jal         0x8003C34C
    // 0x8002985C: sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    func_8003C34C(rdram, ctx);
        goto after_8;
    // 0x8002985C: sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    after_8:
    // 0x80029860: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80029864: sh          $v0, -0x12($s3)
    MEM_H(-0X12, ctx->r19) = ctx->r2;
    // 0x80029868: sw          $s2, 0x3A($s3)
    MEM_W(0X3A, ctx->r19) = ctx->r18;
    // 0x8002986C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80029870: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80029874: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80029878: sh          $v0, 0x2A($s3)
    MEM_H(0X2A, ctx->r19) = ctx->r2;
    // 0x8002987C: lhu         $v0, 0x120($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X120);
    // 0x80029880: sh          $v0, 0x34($s3)
    MEM_H(0X34, ctx->r19) = ctx->r2;
    // 0x80029884: lhu         $v0, 0x122($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X122);
    // 0x80029888: sh          $v0, 0x36($s3)
    MEM_H(0X36, ctx->r19) = ctx->r2;
    // 0x8002988C: lhu         $v0, 0x142($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X142);
    // 0x80029890: beql        $v0, $zero, L_800298A8
    if (ctx->r2 == 0) {
        // 0x80029894: sh          $s7, 0x18A($s2)
        MEM_H(0X18A, ctx->r18) = ctx->r23;
            goto L_800298A8;
    }
    goto skip_5;
    // 0x80029894: sh          $s7, 0x18A($s2)
    MEM_H(0X18A, ctx->r18) = ctx->r23;
    skip_5:
    // 0x80029898: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x8002989C: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800298A0: sh          $v0, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r2;
    // 0x800298A4: sh          $s7, 0x18A($s2)
    MEM_H(0X18A, ctx->r18) = ctx->r23;
L_800298A8:
    // 0x800298A8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800298AC: jal         0x80060F30
    // 0x800298B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80060F30(rdram, ctx);
        goto after_9;
    // 0x800298B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x800298B4: j           L_800298D4
    // 0x800298B8: nop

        goto L_800298D4;
    // 0x800298B8: nop

L_800298BC:
    // 0x800298BC: addiu       $s3, $s3, 0x58
    ctx->r19 = ADD32(ctx->r19, 0X58);
L_800298C0:
    // 0x800298C0: addiu       $v0, $s6, -0x1
    ctx->r2 = ADD32(ctx->r22, -0X1);
    // 0x800298C4: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // 0x800298C8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800298CC: bne         $v0, $zero, L_80029708
    if (ctx->r2 != 0) {
        // 0x800298D0: addiu       $s5, $s5, 0x58
        ctx->r21 = ADD32(ctx->r21, 0X58);
            goto L_80029708;
    }
    // 0x800298D0: addiu       $s5, $s5, 0x58
    ctx->r21 = ADD32(ctx->r21, 0X58);
L_800298D4:
    // 0x800298D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800298D8: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x800298DC: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800298E0: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800298E4: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800298E8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800298EC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800298F0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800298F4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800298F8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800298FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80029900: jr          $ra
    // 0x80029904: nop

    return;
    // 0x80029904: nop

;}
RECOMP_FUNC void func_80029908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029908: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x8002990C: lhu         $a3, -0x6DC4($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X6DC4);
    // FALLTHROUGH: func_80029908 falls into func_80029910
    func_80029910(rdram, ctx);
;}
RECOMP_FUNC void func_80029910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029910: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80029914: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80029918: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x8002991C: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80029920: addiu       $a2, $a2, 0x50F8
    ctx->r6 = ADD32(ctx->r6, 0X50F8);
    // 0x80029924: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80029928: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8002992C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80029930: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80029934: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80029938: beq         $a3, $zero, L_80029B78
    if (ctx->r7 == 0) {
        // 0x8002993C: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_80029B78;
    }
    // 0x8002993C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80029940: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80029944: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80029948: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8002994C: sra         $t0, $v0, 16
    ctx->r8 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80029950: addiu       $s0, $a2, 0x50
    ctx->r16 = ADD32(ctx->r6, 0X50);
L_80029954:
    // 0x80029954: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80029958: lhu         $v0, 0x6C($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6C);
    // 0x8002995C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80029960: bnel        $v0, $zero, L_80029B64
    if (ctx->r2 != 0) {
        // 0x80029964: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_80029B64;
    }
    goto skip_0;
    // 0x80029964: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    skip_0:
    // 0x80029968: lhu         $v1, -0x48($s0)
    ctx->r3 = MEM_HU(ctx->r16, -0X48);
    // 0x8002996C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80029970: bnel        $v1, $v0, L_80029B64
    if (ctx->r3 != ctx->r2) {
        // 0x80029974: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_80029B64;
    }
    goto skip_1;
    // 0x80029974: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    skip_1:
    // 0x80029978: lhu         $a0, -0x4A($s0)
    ctx->r4 = MEM_HU(ctx->r16, -0X4A);
    // 0x8002997C: sltu        $v0, $zero, $a0
    ctx->r2 = 0 < ctx->r4 ? 1 : 0;
    // 0x80029980: sltiu       $v1, $a0, 0x1D
    ctx->r3 = ctx->r4 < 0X1D ? 1 : 0;
    // 0x80029984: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80029988: beq         $v0, $zero, L_80029B60
    if (ctx->r2 == 0) {
        // 0x8002998C: addiu       $v0, $zero, 0x1B
        ctx->r2 = ADD32(0, 0X1B);
            goto L_80029B60;
    }
    // 0x8002998C: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    // 0x80029990: bne         $a0, $v0, L_80029A58
    if (ctx->r4 != ctx->r2) {
        // 0x80029994: nop
    
            goto L_80029A58;
    }
    // 0x80029994: nop

    // 0x80029998: lh          $v0, 0x14($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X14);
    // 0x8002999C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800299A0: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x800299A4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800299A8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800299AC: beq         $v0, $zero, L_800299CC
    if (ctx->r2 == 0) {
        // 0x800299B0: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_800299CC;
    }
    // 0x800299B0: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x800299B4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800299B8: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x800299BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800299C0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800299C4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800299C8: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_800299CC:
    // 0x800299CC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800299D0: subu        $v0, $v0, $t1
    ctx->r2 = SUB32(ctx->r2, ctx->r9);
    // 0x800299D4: bgez        $v0, L_800299E0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800299D8: subu        $v1, $a0, $s2
        ctx->r3 = SUB32(ctx->r4, ctx->r18);
            goto L_800299E0;
    }
    // 0x800299D8: subu        $v1, $a0, $s2
    ctx->r3 = SUB32(ctx->r4, ctx->r18);
    // 0x800299DC: subu        $v1, $s2, $a0
    ctx->r3 = SUB32(ctx->r18, ctx->r4);
L_800299E0:
    // 0x800299E0: lhu         $v0, 0x32($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X32);
    // 0x800299E4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800299E8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800299EC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800299F0: sra         $v0, $v0, 17
    ctx->r2 = S32(SIGNED(ctx->r2) >> 17);
    // 0x800299F4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800299F8: bnel        $v0, $zero, L_80029B64
    if (ctx->r2 != 0) {
        // 0x800299FC: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_80029B64;
    }
    goto skip_2;
    // 0x800299FC: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    skip_2:
    // 0x80029A00: lhu         $v1, 0x30($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X30);
    // 0x80029A04: lhu         $a0, 0x18($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X18);
    // 0x80029A08: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80029A0C: sra         $v1, $v1, 18
    ctx->r3 = S32(SIGNED(ctx->r3) >> 18);
    // 0x80029A10: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80029A14: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80029A18: subu        $v1, $a0, $v1
    ctx->r3 = SUB32(ctx->r4, ctx->r3);
    // 0x80029A1C: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80029A20: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80029A24: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x80029A28: bltzl       $v0, L_80029A34
    if (SIGNED(ctx->r2) < 0) {
        // 0x80029A2C: subu        $v1, $s3, $v1
        ctx->r3 = SUB32(ctx->r19, ctx->r3);
            goto L_80029A34;
    }
    goto skip_3;
    // 0x80029A2C: subu        $v1, $s3, $v1
    ctx->r3 = SUB32(ctx->r19, ctx->r3);
    skip_3:
    // 0x80029A30: subu        $v1, $v1, $s3
    ctx->r3 = SUB32(ctx->r3, ctx->r19);
L_80029A34:
    // 0x80029A34: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80029A38: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80029A3C: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80029A40: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80029A44: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029A48: beq         $v0, $zero, L_80029B0C
    if (ctx->r2 == 0) {
        // 0x80029A4C: nop
    
            goto L_80029B0C;
    }
    // 0x80029A4C: nop

    // 0x80029A50: j           L_80029B64
    // 0x80029A54: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
        goto L_80029B64;
    // 0x80029A54: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
L_80029A58:
    // 0x80029A58: lh          $v0, 0x14($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X14);
    // 0x80029A5C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80029A60: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x80029A64: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80029A68: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029A6C: beq         $v0, $zero, L_80029A8C
    if (ctx->r2 == 0) {
        // 0x80029A70: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80029A8C;
    }
    // 0x80029A70: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80029A74: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80029A78: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x80029A7C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80029A80: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80029A84: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80029A88: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80029A8C:
    // 0x80029A8C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80029A90: subu        $v0, $v0, $t1
    ctx->r2 = SUB32(ctx->r2, ctx->r9);
    // 0x80029A94: bgez        $v0, L_80029AA0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80029A98: subu        $v1, $a0, $s2
        ctx->r3 = SUB32(ctx->r4, ctx->r18);
            goto L_80029AA0;
    }
    // 0x80029A98: subu        $v1, $a0, $s2
    ctx->r3 = SUB32(ctx->r4, ctx->r18);
    // 0x80029A9C: subu        $v1, $s2, $a0
    ctx->r3 = SUB32(ctx->r18, ctx->r4);
L_80029AA0:
    // 0x80029AA0: lhu         $v0, 0x32($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X32);
    // 0x80029AA4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80029AA8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80029AAC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80029AB0: sra         $v0, $v0, 17
    ctx->r2 = S32(SIGNED(ctx->r2) >> 17);
    // 0x80029AB4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029AB8: bnel        $v0, $zero, L_80029B64
    if (ctx->r2 != 0) {
        // 0x80029ABC: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_80029B64;
    }
    goto skip_4;
    // 0x80029ABC: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    skip_4:
    // 0x80029AC0: lhu         $v0, 0x30($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X30);
    // 0x80029AC4: lhu         $a0, 0x18($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X18);
    // 0x80029AC8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80029ACC: sra         $v0, $v0, 17
    ctx->r2 = S32(SIGNED(ctx->r2) >> 17);
    // 0x80029AD0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80029AD4: subu        $v1, $a0, $v0
    ctx->r3 = SUB32(ctx->r4, ctx->r2);
    // 0x80029AD8: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80029ADC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80029AE0: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x80029AE4: bltzl       $v0, L_80029AF0
    if (SIGNED(ctx->r2) < 0) {
        // 0x80029AE8: subu        $v1, $s3, $v1
        ctx->r3 = SUB32(ctx->r19, ctx->r3);
            goto L_80029AF0;
    }
    goto skip_5;
    // 0x80029AE8: subu        $v1, $s3, $v1
    ctx->r3 = SUB32(ctx->r19, ctx->r3);
    skip_5:
    // 0x80029AEC: subu        $v1, $v1, $s3
    ctx->r3 = SUB32(ctx->r3, ctx->r19);
L_80029AF0:
    // 0x80029AF0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80029AF4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80029AF8: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80029AFC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80029B00: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029B04: bnel        $v0, $zero, L_80029B64
    if (ctx->r2 != 0) {
        // 0x80029B08: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_80029B64;
    }
    goto skip_6;
    // 0x80029B08: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    skip_6:
L_80029B0C:
    // 0x80029B0C: lhu         $v0, 0x24($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X24);
    // 0x80029B10: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80029B14: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80029B18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80029B1C: jal         0x8003C34C
    // 0x80029B20: sh          $v0, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r2;
    func_8003C34C(rdram, ctx);
        goto after_0;
    // 0x80029B20: sh          $v0, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r2;
    after_0:
    // 0x80029B24: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80029B28: jal         0x80060F30
    // 0x80029B2C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80060F30(rdram, ctx);
        goto after_1;
    // 0x80029B2C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80029B30: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80029B34: sh          $v0, -0x48($s0)
    MEM_H(-0X48, ctx->r16) = ctx->r2;
    // 0x80029B38: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
    // 0x80029B3C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80029B40: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80029B44: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80029B48: sh          $s2, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r18;
    // 0x80029B4C: sh          $s3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r19;
    // 0x80029B50: sh          $v0, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r2;
    // 0x80029B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80029B58: j           L_80029B78
    // 0x80029B5C: sh          $v0, 0x18A($s1)
    MEM_H(0X18A, ctx->r17) = ctx->r2;
        goto L_80029B78;
    // 0x80029B5C: sh          $v0, 0x18A($s1)
    MEM_H(0X18A, ctx->r17) = ctx->r2;
L_80029B60:
    // 0x80029B60: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
L_80029B64:
    // 0x80029B64: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // 0x80029B68: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80029B6C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80029B70: bne         $v0, $zero, L_80029954
    if (ctx->r2 != 0) {
        // 0x80029B74: addiu       $a2, $a2, 0x58
        ctx->r6 = ADD32(ctx->r6, 0X58);
            goto L_80029954;
    }
    // 0x80029B74: addiu       $a2, $a2, 0x58
    ctx->r6 = ADD32(ctx->r6, 0X58);
L_80029B78:
    // 0x80029B78: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80029B7C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80029B80: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80029B84: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80029B88: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80029B8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80029B90: jr          $ra
    // 0x80029B94: nop

    return;
    // 0x80029B94: nop

;}
RECOMP_FUNC void func_80029B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029B98: jr          $ra
    // 0x80029B9C: nop

    return;
    // 0x80029B9C: nop

;}
RECOMP_FUNC void func_80029BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029BA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80029BA4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80029BA8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80029BAC: lhu         $v1, 0x8($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X8);
    // 0x80029BB0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80029BB4: bne         $v1, $v0, L_80029C78
    if (ctx->r3 != ctx->r2) {
        // 0x80029BB8: nop
    
            goto L_80029C78;
    }
    // 0x80029BB8: nop

    // 0x80029BBC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80029BC0: lh          $v0, -0x67CE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X67CE);
    // 0x80029BC4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80029BC8: lhu         $a0, -0x67CE($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X67CE);
    // 0x80029BCC: beq         $v0, $zero, L_80029C04
    if (ctx->r2 == 0) {
        // 0x80029BD0: nop
    
            goto L_80029C04;
    }
    // 0x80029BD0: nop

    // 0x80029BD4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80029BD8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80029BDC: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x80029BE0: lhu         $v1, 0x14($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X14);
    // 0x80029BE4: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80029BE8: beql        $v0, $zero, L_80029C58
    if (ctx->r2 == 0) {
        // 0x80029BEC: subu        $v0, $a0, $v1
        ctx->r2 = SUB32(ctx->r4, ctx->r3);
            goto L_80029C58;
    }
    goto skip_0;
    // 0x80029BEC: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    skip_0:
    // 0x80029BF0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80029BF4: lhu         $v0, -0x7344($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7344);
    // 0x80029BF8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80029BFC: j           L_80029C58
    // 0x80029C00: addiu       $v0, $v0, 0x31
    ctx->r2 = ADD32(ctx->r2, 0X31);
        goto L_80029C58;
    // 0x80029C00: addiu       $v0, $v0, 0x31
    ctx->r2 = ADD32(ctx->r2, 0X31);
L_80029C04:
    // 0x80029C04: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80029C08: lhu         $v0, 0x11C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X11C);
    // 0x80029C0C: bne         $v0, $zero, L_80029C78
    if (ctx->r2 != 0) {
        // 0x80029C10: nop
    
            goto L_80029C78;
    }
    // 0x80029C10: nop

    // 0x80029C14: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80029C18: lh          $v0, 0x5A2A($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5A2A);
    // 0x80029C1C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80029C20: lhu         $a0, 0x5A2A($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X5A2A);
    // 0x80029C24: beq         $v0, $zero, L_80029C78
    if (ctx->r2 == 0) {
        // 0x80029C28: nop
    
            goto L_80029C78;
    }
    // 0x80029C28: nop

    // 0x80029C2C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80029C30: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80029C34: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x80029C38: lhu         $v1, 0x14($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X14);
    // 0x80029C3C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80029C40: beql        $v0, $zero, L_80029C58
    if (ctx->r2 == 0) {
        // 0x80029C44: subu        $v0, $a0, $v1
        ctx->r2 = SUB32(ctx->r4, ctx->r3);
            goto L_80029C58;
    }
    goto skip_1;
    // 0x80029C44: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    skip_1:
    // 0x80029C48: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80029C4C: lhu         $v0, -0x671C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X671C);
    // 0x80029C50: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80029C54: addiu       $v0, $v0, 0x31
    ctx->r2 = ADD32(ctx->r2, 0X31);
L_80029C58:
    // 0x80029C58: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80029C5C: sltiu       $v0, $v0, 0x32
    ctx->r2 = ctx->r2 < 0X32 ? 1 : 0;
    // 0x80029C60: beq         $v0, $zero, L_80029C78
    if (ctx->r2 == 0) {
        // 0x80029C64: nop
    
            goto L_80029C78;
    }
    // 0x80029C64: nop

    // 0x80029C68: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80029C6C: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80029C70: jal         0x8002A038
    // 0x80029C74: nop

    func_8002A038(rdram, ctx);
        goto after_0;
    // 0x80029C74: nop

    after_0:
L_80029C78:
    // 0x80029C78: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80029C7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80029C80: jr          $ra
    // 0x80029C84: nop

    return;
    // 0x80029C84: nop

;}
RECOMP_FUNC void func_80029C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029C88: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80029C8C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80029C90: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80029C94: lw          $v1, 0x30($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X30);
    // 0x80029C98: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80029C9C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80029CA0: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x80029CA4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80029CA8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80029CAC: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x80029CB0: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x80029CB4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80029CB8: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80029CBC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80029CC0: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80029CC4: lw          $v1, 0x34($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X34);
    // 0x80029CC8: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80029CCC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80029CD0: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x80029CD4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80029CD8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80029CDC: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80029CE0: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x80029CE4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80029CE8: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80029CEC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80029CF0: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80029CF4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80029CF8: lw          $v1, 0x3294($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3294);
    // 0x80029CFC: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80029D00: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80029D04: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x80029D08: lhu         $v0, 0x3E($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X3E);
    // 0x80029D0C: beq         $v0, $zero, L_80029D3C
    if (ctx->r2 == 0) {
        // 0x80029D10: nop
    
            goto L_80029D3C;
    }
    // 0x80029D10: nop

    // 0x80029D14: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80029D18: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80029D1C: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80029D20: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80029D24: beq         $v0, $zero, L_80029D58
    if (ctx->r2 == 0) {
        // 0x80029D28: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80029D58;
    }
    // 0x80029D28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80029D2C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80029D30: sh          $v0, 0x3218($at)
    MEM_H(0X3218, ctx->r1) = ctx->r2;
    // 0x80029D34: j           L_80029D64
    // 0x80029D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80029D64;
    // 0x80029D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80029D3C:
    // 0x80029D3C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80029D40: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80029D44: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80029D48: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80029D4C: bne         $v0, $zero, L_80029D58
    if (ctx->r2 != 0) {
        // 0x80029D50: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80029D58;
    }
    // 0x80029D50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80029D54: sh          $v0, 0x3E($a1)
    MEM_H(0X3E, ctx->r5) = ctx->r2;
L_80029D58:
    // 0x80029D58: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80029D5C: sh          $zero, 0x3218($at)
    MEM_H(0X3218, ctx->r1) = 0;
    // 0x80029D60: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80029D64:
    // 0x80029D64: jr          $ra
    // 0x80029D68: nop

    return;
    // 0x80029D68: nop

;}
RECOMP_FUNC void func_80029D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029D6C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80029D70: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80029D74: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80029D78: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // FALLTHROUGH: func_80029D6C falls into func_80029D7C
    func_80029D7C(rdram, ctx);
;}
RECOMP_FUNC void func_80029D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029D7C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80029D80: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80029D84: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80029D88: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80029D8C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80029D90: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80029D94: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80029D98: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80029D9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80029DA0: lh          $a0, 0x14($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X14);
    // 0x80029DA4: lhu         $s4, 0x14($v0)
    ctx->r20 = MEM_HU(ctx->r2, 0X14);
    // 0x80029DA8: lw          $s2, 0x90($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X90);
    // 0x80029DAC: slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80029DB0: beq         $v1, $zero, L_80029DC4
    if (ctx->r3 == 0) {
        // 0x80029DB4: nop
    
            goto L_80029DC4;
    }
    // 0x80029DB4: nop

    // 0x80029DB8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80029DBC: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x80029DC0: addu        $s4, $s4, $v0
    ctx->r20 = ADD32(ctx->r20, ctx->r2);
L_80029DC4:
    // 0x80029DC4: lui         $s5, 0x8016
    ctx->r21 = S32(0X8016 << 16);
    // 0x80029DC8: lhu         $s5, -0x6DC4($s5)
    ctx->r21 = MEM_HU(ctx->r21, -0X6DC4);
    // 0x80029DCC: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x80029DD0: addiu       $s3, $s3, 0x50F8
    ctx->r19 = ADD32(ctx->r19, 0X50F8);
    // 0x80029DD4: beq         $s5, $zero, L_80029F00
    if (ctx->r21 == 0) {
        // 0x80029DD8: sll         $v0, $s4, 16
        ctx->r2 = S32(ctx->r20 << 16);
            goto L_80029F00;
    }
    // 0x80029DD8: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x80029DDC: sra         $s6, $v0, 16
    ctx->r22 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80029DE0: addiu       $s0, $s3, 0x50
    ctx->r16 = ADD32(ctx->r19, 0X50);
L_80029DE4:
    // 0x80029DE4: lhu         $v0, -0x4A($s0)
    ctx->r2 = MEM_HU(ctx->r16, -0X4A);
    // 0x80029DE8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80029DEC: beql        $v0, $zero, L_80029EEC
    if (ctx->r2 == 0) {
        // 0x80029DF0: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_80029EEC;
    }
    goto skip_0;
    // 0x80029DF0: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    skip_0:
    // 0x80029DF4: lhu         $v0, 0x6C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6C);
    // 0x80029DF8: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80029DFC: bnel        $v0, $zero, L_80029EEC
    if (ctx->r2 != 0) {
        // 0x80029E00: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_80029EEC;
    }
    goto skip_1;
    // 0x80029E00: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    skip_1:
    // 0x80029E04: lh          $a0, 0x14($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X14);
    // 0x80029E08: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80029E0C: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x80029E10: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029E14: beq         $v0, $zero, L_80029E54
    if (ctx->r2 == 0) {
        // 0x80029E18: addu        $s1, $a0, $zero
        ctx->r17 = ADD32(ctx->r4, 0);
            goto L_80029E54;
    }
    // 0x80029E18: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80029E1C: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x80029E20: bltz        $v0, L_80029E38
    if (SIGNED(ctx->r2) < 0) {
        // 0x80029E24: slti        $v0, $v0, 0xC8
        ctx->r2 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
            goto L_80029E38;
    }
    // 0x80029E24: slti        $v0, $v0, 0xC8
    ctx->r2 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x80029E28: beq         $v0, $zero, L_80029E48
    if (ctx->r2 == 0) {
        // 0x80029E2C: nop
    
            goto L_80029E48;
    }
    // 0x80029E2C: nop

    // 0x80029E30: j           L_80029E54
    // 0x80029E34: nop

        goto L_80029E54;
    // 0x80029E34: nop

L_80029E38:
    // 0x80029E38: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x80029E3C: slti        $v0, $v0, 0xC8
    ctx->r2 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x80029E40: bne         $v0, $zero, L_80029E54
    if (ctx->r2 != 0) {
        // 0x80029E44: nop
    
            goto L_80029E54;
    }
    // 0x80029E44: nop

L_80029E48:
    // 0x80029E48: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80029E4C: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x80029E50: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
L_80029E54:
    // 0x80029E54: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80029E58: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80029E5C: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80029E60: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80029E64: beq         $v0, $zero, L_80029E84
    if (ctx->r2 == 0) {
        // 0x80029E68: sll         $v0, $s1, 16
        ctx->r2 = S32(ctx->r17 << 16);
            goto L_80029E84;
    }
    // 0x80029E68: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x80029E6C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80029E70: slt         $v0, $s6, $v0
    ctx->r2 = SIGNED(ctx->r22) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80029E74: beq         $v0, $zero, L_80029E94
    if (ctx->r2 == 0) {
        // 0x80029E78: nop
    
            goto L_80029E94;
    }
    // 0x80029E78: nop

    // 0x80029E7C: j           L_80029EEC
    // 0x80029E80: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
        goto L_80029EEC;
    // 0x80029E80: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
L_80029E84:
    // 0x80029E84: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80029E88: slt         $v0, $v0, $s6
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80029E8C: bnel        $v0, $zero, L_80029EEC
    if (ctx->r2 != 0) {
        // 0x80029E90: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_80029EEC;
    }
    goto skip_2;
    // 0x80029E90: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    skip_2:
L_80029E94:
    // 0x80029E94: lhu         $v0, 0x24($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X24);
    // 0x80029E98: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80029E9C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80029EA0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80029EA4: jal         0x8003C34C
    // 0x80029EA8: sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    func_8003C34C(rdram, ctx);
        goto after_0;
    // 0x80029EA8: sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    after_0:
    // 0x80029EAC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80029EB0: jal         0x80060F30
    // 0x80029EB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80060F30(rdram, ctx);
        goto after_1;
    // 0x80029EB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80029EB8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80029EBC: sh          $v0, -0x48($s0)
    MEM_H(-0X48, ctx->r16) = ctx->r2;
    // 0x80029EC0: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80029EC4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80029EC8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80029ECC: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80029ED0: sh          $s1, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r17;
    // 0x80029ED4: sh          $s4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r20;
    // 0x80029ED8: sh          $v0, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r2;
    // 0x80029EDC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80029EE0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80029EE4: sw          $s3, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r19;
    // 0x80029EE8: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
L_80029EEC:
    // 0x80029EEC: addiu       $v0, $s5, -0x1
    ctx->r2 = ADD32(ctx->r21, -0X1);
    // 0x80029EF0: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x80029EF4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80029EF8: bne         $v0, $zero, L_80029DE4
    if (ctx->r2 != 0) {
        // 0x80029EFC: addiu       $s3, $s3, 0x58
        ctx->r19 = ADD32(ctx->r19, 0X58);
            goto L_80029DE4;
    }
    // 0x80029EFC: addiu       $s3, $s3, 0x58
    ctx->r19 = ADD32(ctx->r19, 0X58);
L_80029F00:
    // 0x80029F00: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80029F04: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80029F08: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80029F0C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80029F10: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80029F14: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80029F18: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80029F1C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80029F20: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80029F24: jr          $ra
    // 0x80029F28: nop

    return;
    // 0x80029F28: nop

;}
RECOMP_FUNC void func_80029F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029F2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80029F30: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80029F34: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x80029F38: lhu         $s2, -0x6DC4($s2)
    ctx->r18 = MEM_HU(ctx->r18, -0X6DC4);
    // 0x80029F3C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80029F40: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80029F44: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80029F48: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80029F4C: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80029F50: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x80029F54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80029F58: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80029F5C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80029F60: beq         $s2, $zero, L_8002A00C
    if (ctx->r18 == 0) {
        // 0x80029F64: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_8002A00C;
    }
    // 0x80029F64: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80029F68: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x80029F6C: addiu       $s1, $s1, 0x50F8
    ctx->r17 = ADD32(ctx->r17, 0X50F8);
    // 0x80029F70: sltiu       $s3, $s0, 0x1
    ctx->r19 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80029F74: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
L_80029F78:
    // 0x80029F78: lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6);
    // 0x80029F7C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80029F80: beq         $v0, $zero, L_80029FFC
    if (ctx->r2 == 0) {
        // 0x80029F84: addiu       $v0, $s2, -0x1
        ctx->r2 = ADD32(ctx->r18, -0X1);
            goto L_80029FFC;
    }
    // 0x80029F84: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x80029F88: lhu         $v0, 0x6C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6C);
    // 0x80029F8C: srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // 0x80029F90: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80029F94: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80029F98: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x80029F9C: beql        $v0, $zero, L_80029FFC
    if (ctx->r2 == 0) {
        // 0x80029FA0: addiu       $v0, $s2, -0x1
        ctx->r2 = ADD32(ctx->r18, -0X1);
            goto L_80029FFC;
    }
    goto skip_0;
    // 0x80029FA0: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x80029FA4: beq         $s0, $zero, L_80029FCC
    if (ctx->r16 == 0) {
        // 0x80029FA8: addiu       $a0, $zero, 0x28
        ctx->r4 = ADD32(0, 0X28);
            goto L_80029FCC;
    }
    // 0x80029FA8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80029FAC: lhu         $v0, 0x24($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X24);
    // 0x80029FB0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80029FB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80029FB8: jal         0x8003C34C
    // 0x80029FBC: sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    func_8003C34C(rdram, ctx);
        goto after_0;
    // 0x80029FBC: sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    after_0:
    // 0x80029FC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80029FC4: jal         0x80060F30
    // 0x80029FC8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80060F30(rdram, ctx);
        goto after_1;
    // 0x80029FC8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
L_80029FCC:
    // 0x80029FCC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80029FD0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80029FD4: sh          $s6, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r22;
    // 0x80029FD8: sw          $s0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->r16;
    // 0x80029FDC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80029FE0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80029FE4: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80029FE8: sh          $s4, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r20;
    // 0x80029FEC: sh          $s5, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r21;
    // 0x80029FF0: sh          $v0, 0x44($s1)
    MEM_H(0X44, ctx->r17) = ctx->r2;
    // 0x80029FF4: sw          $s1, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r17;
    // 0x80029FF8: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
L_80029FFC:
    // 0x80029FFC: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8002A000: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8002A004: bne         $v0, $zero, L_80029F78
    if (ctx->r2 != 0) {
        // 0x8002A008: nop
    
            goto L_80029F78;
    }
    // 0x8002A008: nop

L_8002A00C:
    // 0x8002A00C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002A010: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8002A014: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8002A018: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8002A01C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A020: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8002A024: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002A028: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002A02C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002A030: jr          $ra
    // 0x8002A034: nop

    return;
    // 0x8002A034: nop

;}
RECOMP_FUNC void func_8002A038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002A03C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002A040: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8002A044: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8002A048: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8002A04C: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
    // 0x8002A050: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8002A054: addiu       $v0, $v1, -0x16
    ctx->r2 = ADD32(ctx->r3, -0X16);
    // 0x8002A058: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8002A05C: bne         $v0, $zero, L_8002A074
    if (ctx->r2 != 0) {
        // 0x8002A060: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8002A074;
    }
    // 0x8002A060: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8002A064: addiu       $v0, $v1, -0xD
    ctx->r2 = ADD32(ctx->r3, -0XD);
    // 0x8002A068: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x8002A06C: beq         $v0, $zero, L_8002A080
    if (ctx->r2 == 0) {
        // 0x8002A070: nop
    
            goto L_8002A080;
    }
    // 0x8002A070: nop

L_8002A074:
    // 0x8002A074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A078: j           L_8002A158
    // 0x8002A07C: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
        goto L_8002A158;
    // 0x8002A07C: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
L_8002A080:
    // 0x8002A080: lhu         $v1, 0x22($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X22);
    // 0x8002A084: andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // 0x8002A088: bne         $v0, $zero, L_8002A094
    if (ctx->r2 != 0) {
        // 0x8002A08C: andi        $v0, $v1, 0xFFEF
        ctx->r2 = ctx->r3 & 0XFFEF;
            goto L_8002A094;
    }
    // 0x8002A08C: andi        $v0, $v1, 0xFFEF
    ctx->r2 = ctx->r3 & 0XFFEF;
    // 0x8002A090: ori         $v0, $v1, 0x10
    ctx->r2 = ctx->r3 | 0X10;
L_8002A094:
    // 0x8002A094: sh          $v0, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r2;
    // 0x8002A098: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x8002A09C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8002A0A0: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x8002A0A4: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8002A0A8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8002A0AC: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x8002A0B0: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
    // 0x8002A0B4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8002A0B8: beq         $v1, $v0, L_8002A104
    if (ctx->r3 == ctx->r2) {
        // 0x8002A0BC: slti        $v0, $v1, 0x8
        ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_8002A104;
    }
    // 0x8002A0BC: slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8002A0C0: beq         $v0, $zero, L_8002A0D8
    if (ctx->r2 == 0) {
        // 0x8002A0C4: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_8002A0D8;
    }
    // 0x8002A0C4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8002A0C8: beq         $v1, $v0, L_8002A0F4
    if (ctx->r3 == ctx->r2) {
        // 0x8002A0CC: nop
    
            goto L_8002A0F4;
    }
    // 0x8002A0CC: nop

    // 0x8002A0D0: j           L_8002A130
    // 0x8002A0D4: nop

        goto L_8002A130;
    // 0x8002A0D4: nop

L_8002A0D8:
    // 0x8002A0D8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8002A0DC: beq         $v1, $v0, L_8002A114
    if (ctx->r3 == ctx->r2) {
        // 0x8002A0E0: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8002A114;
    }
    // 0x8002A0E0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8002A0E4: beq         $v1, $v0, L_8002A124
    if (ctx->r3 == ctx->r2) {
        // 0x8002A0E8: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_8002A124;
    }
    // 0x8002A0E8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8002A0EC: j           L_8002A130
    // 0x8002A0F0: nop

        goto L_8002A130;
    // 0x8002A0F0: nop

L_8002A0F4:
    // 0x8002A0F4: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8002A0F8: addiu       $a1, $a1, 0x5CFC
    ctx->r5 = ADD32(ctx->r5, 0X5CFC);
    // 0x8002A0FC: j           L_8002A12C
    // 0x8002A100: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_8002A12C;
    // 0x8002A100: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_8002A104:
    // 0x8002A104: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8002A108: addiu       $a1, $a1, 0x5CF0
    ctx->r5 = ADD32(ctx->r5, 0X5CF0);
    // 0x8002A10C: j           L_8002A12C
    // 0x8002A110: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_8002A12C;
    // 0x8002A110: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8002A114:
    // 0x8002A114: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8002A118: addiu       $a1, $a1, 0x5D20
    ctx->r5 = ADD32(ctx->r5, 0X5D20);
    // 0x8002A11C: j           L_8002A12C
    // 0x8002A120: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_8002A12C;
    // 0x8002A120: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_8002A124:
    // 0x8002A124: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8002A128: addiu       $a1, $a1, 0x5D14
    ctx->r5 = ADD32(ctx->r5, 0X5D14);
L_8002A12C:
    // 0x8002A12C: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
L_8002A130:
    // 0x8002A130: beq         $a1, $zero, L_8002A144
    if (ctx->r5 == 0) {
        // 0x8002A134: nop
    
            goto L_8002A144;
    }
    // 0x8002A134: nop

    // 0x8002A138: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8002A13C: jal         0x800249B4
    // 0x8002A140: nop

    func_800249B4(rdram, ctx);
        goto after_0;
    // 0x8002A140: nop

    after_0:
L_8002A144:
    // 0x8002A144: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8002A148: beq         $a0, $zero, L_8002A158
    if (ctx->r4 == 0) {
        // 0x8002A14C: nop
    
            goto L_8002A158;
    }
    // 0x8002A14C: nop

    // 0x8002A150: lhu         $v0, 0x22($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X22);
    // 0x8002A154: sh          $v0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r2;
L_8002A158:
    // 0x8002A158: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8002A15C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002A160: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002A164: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002A168: jr          $ra
    // 0x8002A16C: nop

    return;
    // 0x8002A16C: nop

;}
RECOMP_FUNC void func_8002A170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A170: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8002A174: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_8002A170 falls into func_8002A178
    func_8002A178(rdram, ctx);
;}
RECOMP_FUNC void func_8002A178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A17C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002A180: lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X90);
    // 0x8002A184: jal         0x80044514
    // 0x8002A188: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    func_80044514(rdram, ctx);
        goto after_0;
    // 0x8002A188: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    after_0:
    // 0x8002A18C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002A190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A194: jr          $ra
    // 0x8002A198: nop

    return;
    // 0x8002A198: nop

;}
RECOMP_FUNC void func_8002A19C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A19C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8002A1A0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8002A1A4: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x8002A1A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A1AC: jr          $ra
    // 0x8002A1B0: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
    return;
    // 0x8002A1B0: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_8002A1B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A1B4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8002A1B8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8002A1BC: lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X90);
    // 0x8002A1C0: jr          $ra
    // 0x8002A1C4: sh          $zero, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = 0;
    return;
    // 0x8002A1C4: sh          $zero, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8002A1C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A1C8: jr          $ra
    // 0x8002A1CC: nop

    return;
    // 0x8002A1CC: nop

;}
RECOMP_FUNC void func_8002A1D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A1D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A1D4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x8002A1D8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002A1DC: jal         0x80001414
    // 0x8002A1E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80001414(rdram, ctx);
        goto after_0;
    // 0x8002A1E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8002A1E4: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x8002A1E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002A1EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002A1F0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002A1F4: lw          $v0, 0x61D0($at)
    ctx->r2 = MEM_W(ctx->r1, 0X61D0);
    // 0x8002A1F8: jalr        $v0
    // 0x8002A1FC: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8002A1FC: nop

    after_1:
    // 0x8002A200: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002A204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A208: jr          $ra
    // 0x8002A20C: nop

    return;
    // 0x8002A20C: nop

;}
RECOMP_FUNC void func_8002A210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A210: jr          $ra
    // 0x8002A214: nop

    return;
    // 0x8002A214: nop

;}
RECOMP_FUNC void func_8002A218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A21C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002A220: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002A224: sh          $zero, 0x158($at)
    MEM_H(0X158, ctx->r1) = 0;
    // 0x8002A228: jal         0x8005E368
    // 0x8002A22C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005E368(rdram, ctx);
        goto after_0;
    // 0x8002A22C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8002A230: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002A234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A238: jr          $ra
    // 0x8002A23C: nop

    return;
    // 0x8002A23C: nop

;}
RECOMP_FUNC void func_8002A240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A244: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002A248: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8002A24C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002A250: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002A254: sh          $zero, 0x158($at)
    MEM_H(0X158, ctx->r1) = 0;
    // 0x8002A258: jal         0x8005E368
    // 0x8002A25C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005E368(rdram, ctx);
        goto after_0;
    // 0x8002A25C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8002A260: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x8002A264: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002A268: sw          $s0, 0x46B0($at)
    MEM_W(0X46B0, ctx->r1) = ctx->r16;
    // 0x8002A26C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A270: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002A274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A278: jr          $ra
    // 0x8002A27C: nop

    return;
    // 0x8002A27C: nop

;}
RECOMP_FUNC void func_8002A280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A284: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002A288: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8002A28C: addiu       $a0, $a0, 0xCD0
    ctx->r4 = ADD32(ctx->r4, 0XCD0);
    // 0x8002A290: jal         0x8003DBCC
    // 0x8002A294: nop

    func_8003DBCC(rdram, ctx);
        goto after_0;
    // 0x8002A294: nop

    after_0:
    // 0x8002A298: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8002A29C: addiu       $a1, $zero, 0x520
    ctx->r5 = ADD32(0, 0X520);
    // 0x8002A2A0: jal         0x8002A338
    // 0x8002A2A4: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    func_8002A338(rdram, ctx);
        goto after_1;
    // 0x8002A2A4: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_1:
    // 0x8002A2A8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8002A2AC: addiu       $a0, $a0, 0xA90
    ctx->r4 = ADD32(ctx->r4, 0XA90);
    // 0x8002A2B0: jal         0x8003DBCC
    // 0x8002A2B4: nop

    func_8003DBCC(rdram, ctx);
        goto after_2;
    // 0x8002A2B4: nop

    after_2:
    // 0x8002A2B8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8002A2BC: addiu       $a1, $zero, 0x500
    ctx->r5 = ADD32(0, 0X500);
    // 0x8002A2C0: jal         0x8002A338
    // 0x8002A2C4: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_8002A338(rdram, ctx);
        goto after_3;
    // 0x8002A2C4: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_3:
    // 0x8002A2C8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8002A2CC: addiu       $a0, $a0, 0xF10
    ctx->r4 = ADD32(ctx->r4, 0XF10);
    // 0x8002A2D0: jal         0x8003DBCC
    // 0x8002A2D4: nop

    func_8003DBCC(rdram, ctx);
        goto after_4;
    // 0x8002A2D4: nop

    after_4:
    // 0x8002A2D8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8002A2DC: addiu       $a1, $zero, 0x510
    ctx->r5 = ADD32(0, 0X510);
    // 0x8002A2E0: jal         0x8002A338
    // 0x8002A2E4: addiu       $a2, $zero, 0x199
    ctx->r6 = ADD32(0, 0X199);
    func_8002A338(rdram, ctx);
        goto after_5;
    // 0x8002A2E4: addiu       $a2, $zero, 0x199
    ctx->r6 = ADD32(0, 0X199);
    after_5:
    // 0x8002A2E8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8002A2EC: addiu       $a0, $a0, 0x3FA0
    ctx->r4 = ADD32(ctx->r4, 0X3FA0);
    // 0x8002A2F0: jal         0x8003DBCC
    // 0x8002A2F4: nop

    func_8003DBCC(rdram, ctx);
        goto after_6;
    // 0x8002A2F4: nop

    after_6:
    // 0x8002A2F8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8002A2FC: addiu       $a1, $zero, 0x540
    ctx->r5 = ADD32(0, 0X540);
    // 0x8002A300: jal         0x8002A338
    // 0x8002A304: addiu       $a2, $zero, 0x300
    ctx->r6 = ADD32(0, 0X300);
    func_8002A338(rdram, ctx);
        goto after_7;
    // 0x8002A304: addiu       $a2, $zero, 0x300
    ctx->r6 = ADD32(0, 0X300);
    after_7:
    // 0x8002A308: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8002A30C: addiu       $a0, $a0, 0x41E0
    ctx->r4 = ADD32(ctx->r4, 0X41E0);
    // 0x8002A310: jal         0x8003DBCC
    // 0x8002A314: nop

    func_8003DBCC(rdram, ctx);
        goto after_8;
    // 0x8002A314: nop

    after_8:
    // 0x8002A318: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8002A31C: addiu       $a1, $zero, 0x714
    ctx->r5 = ADD32(0, 0X714);
    // 0x8002A320: jal         0x8002A338
    // 0x8002A324: addiu       $a2, $zero, 0x300
    ctx->r6 = ADD32(0, 0X300);
    func_8002A338(rdram, ctx);
        goto after_9;
    // 0x8002A324: addiu       $a2, $zero, 0x300
    ctx->r6 = ADD32(0, 0X300);
    after_9:
    // 0x8002A328: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002A32C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A330: jr          $ra
    // 0x8002A334: nop

    return;
    // 0x8002A334: nop

;}
RECOMP_FUNC void func_8002A338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A338: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002A33C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8002A340: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8002A344: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002A348: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x8002A34C: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x8002A350: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8002A354: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8002A358: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8002A35C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8002A360: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8002A364: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002A368: lhu         $s4, 0x2($s2)
    ctx->r20 = MEM_HU(ctx->r18, 0X2);
    // 0x8002A36C: beq         $s4, $zero, L_8002A450
    if (ctx->r20 == 0) {
        // 0x8002A370: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8002A450;
    }
    // 0x8002A370: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8002A374: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8002A378: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8002A37C: sra         $s7, $v0, 16
    ctx->r23 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002A380: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x8002A384: sra         $s5, $v0, 16
    ctx->r21 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002A388: xori        $v0, $s5, 0x300
    ctx->r2 = ctx->r21 ^ 0X300;
    // 0x8002A38C: sltu        $s6, $zero, $v0
    ctx->r22 = 0 < ctx->r2 ? 1 : 0;
L_8002A390:
    // 0x8002A390: lw          $s3, 0x0($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X0);
    // 0x8002A394: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8002A398: lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X0);
    // 0x8002A39C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8002A3A0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x8002A3A4: jal         0x800306EC
    // 0x8002A3A8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x8002A3A8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    after_0:
    // 0x8002A3AC: lui         $v1, 0xFF7F
    ctx->r3 = S32(0XFF7F << 16);
    // 0x8002A3B0: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8002A3B4: sw          $fp, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r30;
    // 0x8002A3B8: sw          $s5, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r21;
    // 0x8002A3BC: sw          $s7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r23;
    // 0x8002A3C0: and         $v1, $s3, $v1
    ctx->r3 = ctx->r19 & ctx->r3;
    // 0x8002A3C4: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8002A3C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8002A3CC: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x8002A3D0: jal         0x80023E44
    // 0x8002A3D4: nop

    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x8002A3D4: nop

    after_1:
    // 0x8002A3D8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8002A3DC: lhu         $v1, 0x30($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X30);
    // 0x8002A3E0: lhu         $v0, 0x1C($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1C);
    // 0x8002A3E4: sh          $s1, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r17;
    // 0x8002A3E8: sh          $s1, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r17;
    // 0x8002A3EC: subu        $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    // 0x8002A3F0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8002A3F4: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // 0x8002A3F8: beq         $s6, $zero, L_8002A40C
    if (ctx->r22 == 0) {
        // 0x8002A3FC: sh          $v0, 0x18($a1)
        MEM_H(0X18, ctx->r5) = ctx->r2;
            goto L_8002A40C;
    }
    // 0x8002A3FC: sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
    // 0x8002A400: lhu         $v0, 0x6C($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6C);
    // 0x8002A404: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // 0x8002A408: sh          $v0, 0x6C($a1)
    MEM_H(0X6C, ctx->r5) = ctx->r2;
L_8002A40C:
    // 0x8002A40C: lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
    // 0x8002A410: and         $v0, $s3, $v0
    ctx->r2 = ctx->r19 & ctx->r2;
    // 0x8002A414: beq         $v0, $zero, L_8002A440
    if (ctx->r2 == 0) {
        // 0x8002A418: addiu       $v0, $s4, -0x1
        ctx->r2 = ADD32(ctx->r20, -0X1);
            goto L_8002A440;
    }
    // 0x8002A418: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // 0x8002A41C: lhu         $v0, 0x14($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X14);
    // 0x8002A420: lhu         $a0, 0x32($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X32);
    // 0x8002A424: lhu         $v1, 0x22($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X22);
    // 0x8002A428: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8002A42C: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x8002A430: sh          $v1, 0x22($a1)
    MEM_H(0X22, ctx->r5) = ctx->r3;
    // 0x8002A434: sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // 0x8002A438: sh          $v0, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r2;
    // 0x8002A43C: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
L_8002A440:
    // 0x8002A440: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x8002A444: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8002A448: bne         $v0, $zero, L_8002A390
    if (ctx->r2 != 0) {
        // 0x8002A44C: nop
    
            goto L_8002A390;
    }
    // 0x8002A44C: nop

L_8002A450:
    // 0x8002A450: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8002A454: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x8002A458: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8002A45C: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8002A460: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8002A464: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8002A468: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A46C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8002A470: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002A474: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002A478: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8002A47C: jr          $ra
    // 0x8002A480: nop

    return;
    // 0x8002A480: nop

;}
RECOMP_FUNC void func_8002A484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A484: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002A488: lh          $v0, 0x166($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X166);
    // 0x8002A48C: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x8002A490: lw          $a3, 0x14($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X14);
    // 0x8002A494: bgtzl       $v0, L_8002A4E8
    if (SIGNED(ctx->r2) > 0) {
        // 0x8002A498: addu        $a3, $a3, $a1
        ctx->r7 = ADD32(ctx->r7, ctx->r5);
            goto L_8002A4E8;
    }
    goto skip_0;
    // 0x8002A498: addu        $a3, $a3, $a1
    ctx->r7 = ADD32(ctx->r7, ctx->r5);
    skip_0:
    // 0x8002A49C: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x8002A4A0: blez        $a3, L_8002A51C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8002A4A4: lui         $a0, 0x3FF
        ctx->r4 = S32(0X3FF << 16);
            goto L_8002A51C;
    }
    // 0x8002A4A4: lui         $a0, 0x3FF
    ctx->r4 = S32(0X3FF << 16);
    // 0x8002A4A8: lh          $v0, 0x32($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X32);
    // 0x8002A4AC: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x8002A4B0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8002A4B4: lw          $v1, 0x3294($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3294);
    // 0x8002A4B8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002A4BC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002A4C0: and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // 0x8002A4C4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002A4C8: bgez        $v0, L_8002A4D4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002A4CC: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_8002A4D4;
    }
    // 0x8002A4CC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8002A4D0: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_8002A4D4:
    // 0x8002A4D4: slt         $v0, $a3, $a0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002A4D8: bne         $v0, $zero, L_8002A51C
    if (ctx->r2 != 0) {
        // 0x8002A4DC: addiu       $v0, $a3, -0x1
        ctx->r2 = ADD32(ctx->r7, -0X1);
            goto L_8002A51C;
    }
    // 0x8002A4DC: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // 0x8002A4E0: j           L_8002A51C
    // 0x8002A4E4: subu        $a3, $v0, $v1
    ctx->r7 = SUB32(ctx->r2, ctx->r3);
        goto L_8002A51C;
    // 0x8002A4E4: subu        $a3, $v0, $v1
    ctx->r7 = SUB32(ctx->r2, ctx->r3);
L_8002A4E8:
    // 0x8002A4E8: bgez        $a3, L_8002A51C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8002A4EC: nop
    
            goto L_8002A51C;
    }
    // 0x8002A4EC: nop

    // 0x8002A4F0: lh          $v0, 0x32($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X32);
    // 0x8002A4F4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002A4F8: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8002A4FC: bgtz        $v0, L_8002A51C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8002A500: lui         $v0, 0x3FF
        ctx->r2 = S32(0X3FF << 16);
            goto L_8002A51C;
    }
    // 0x8002A500: lui         $v0, 0x3FF
    ctx->r2 = S32(0X3FF << 16);
    // 0x8002A504: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8002A508: lw          $v1, 0x3294($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3294);
    // 0x8002A50C: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x8002A510: addiu       $a0, $a3, 0x1
    ctx->r4 = ADD32(ctx->r7, 0X1);
    // 0x8002A514: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8002A518: addu        $a3, $a0, $v1
    ctx->r7 = ADD32(ctx->r4, ctx->r3);
L_8002A51C:
    // 0x8002A51C: jr          $ra
    // 0x8002A520: sw          $a3, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r7;
    return;
    // 0x8002A520: sw          $a3, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r7;
;}
RECOMP_FUNC void func_8002A524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A524: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002A528: lh          $v0, 0x166($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X166);
    // FALLTHROUGH: func_8002A524 falls into func_8002A52C
    func_8002A52C(rdram, ctx);
;}
RECOMP_FUNC void func_8002A52C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A52C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002A530: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002A534: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8002A538: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8002A53C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8002A540: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8002A544: beq         $v0, $zero, L_8002A5CC
    if (ctx->r2 == 0) {
        // 0x8002A548: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8002A5CC;
    }
    // 0x8002A548: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002A54C: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x8002A550: addiu       $s1, $s1, -0x7464
    ctx->r17 = ADD32(ctx->r17, -0X7464);
    // 0x8002A554: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8002A558: beq         $s0, $s1, L_8002A5CC
    if (ctx->r16 == ctx->r17) {
        // 0x8002A55C: addiu       $s4, $zero, 0x510
        ctx->r20 = ADD32(0, 0X510);
            goto L_8002A5CC;
    }
    // 0x8002A55C: addiu       $s4, $zero, 0x510
    ctx->r20 = ADD32(0, 0X510);
    // 0x8002A560: addiu       $s3, $zero, 0x500
    ctx->r19 = ADD32(0, 0X500);
    // 0x8002A564: addiu       $s2, $zero, 0x520
    ctx->r18 = ADD32(0, 0X520);
L_8002A568:
    // 0x8002A568: lhu         $v1, 0x70($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X70);
    // 0x8002A56C: beq         $v1, $s4, L_8002A5AC
    if (ctx->r3 == ctx->r20) {
        // 0x8002A570: slti        $v0, $v1, 0x511
        ctx->r2 = SIGNED(ctx->r3) < 0X511 ? 1 : 0;
            goto L_8002A5AC;
    }
    // 0x8002A570: slti        $v0, $v1, 0x511
    ctx->r2 = SIGNED(ctx->r3) < 0X511 ? 1 : 0;
    // 0x8002A574: beq         $v0, $zero, L_8002A58C
    if (ctx->r2 == 0) {
        // 0x8002A578: nop
    
            goto L_8002A58C;
    }
    // 0x8002A578: nop

    // 0x8002A57C: beq         $v1, $s3, L_8002A5A0
    if (ctx->r3 == ctx->r19) {
        // 0x8002A580: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8002A5A0;
    }
    // 0x8002A580: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002A584: j           L_8002A5C0
    // 0x8002A588: nop

        goto L_8002A5C0;
    // 0x8002A588: nop

L_8002A58C:
    // 0x8002A58C: bne         $v1, $s2, L_8002A5C0
    if (ctx->r3 != ctx->r18) {
        // 0x8002A590: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8002A5C0;
    }
    // 0x8002A590: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002A594: addiu       $a1, $zero, -0x4000
    ctx->r5 = ADD32(0, -0X4000);
    // 0x8002A598: j           L_8002A5B8
    // 0x8002A59C: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
        goto L_8002A5B8;
    // 0x8002A59C: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
L_8002A5A0:
    // 0x8002A5A0: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8002A5A4: j           L_8002A5B8
    // 0x8002A5A8: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
        goto L_8002A5B8;
    // 0x8002A5A8: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
L_8002A5AC:
    // 0x8002A5AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002A5B0: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8002A5B4: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
L_8002A5B8:
    // 0x8002A5B8: jal         0x8002A484
    // 0x8002A5BC: nop

    func_8002A484(rdram, ctx);
        goto after_0;
    // 0x8002A5BC: nop

    after_0:
L_8002A5C0:
    // 0x8002A5C0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8002A5C4: bne         $s0, $s1, L_8002A568
    if (ctx->r16 != ctx->r17) {
        // 0x8002A5C8: nop
    
            goto L_8002A568;
    }
    // 0x8002A5C8: nop

L_8002A5CC:
    // 0x8002A5CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002A5D0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8002A5D4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A5D8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8002A5DC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002A5E0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002A5E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002A5E8: jr          $ra
    // 0x8002A5EC: nop

    return;
    // 0x8002A5EC: nop

;}
RECOMP_FUNC void func_8002A5F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A5F0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8002A5F4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8002A5F8: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8002A5FC: lw          $a1, 0x30($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X30);
    // 0x8002A600: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8002A604: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    // 0x8002A608: sw          $a1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r5;
    // 0x8002A60C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8002A610: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8002A614: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x8002A618: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8002A61C: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x8002A620: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8002A624: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8002A628: lw          $a1, 0x34($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X34);
    // 0x8002A62C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8002A630: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    // 0x8002A634: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8002A638: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8002A63C: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x8002A640: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8002A644: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8002A648: lw          $v1, 0x3294($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3294);
    // 0x8002A64C: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    // 0x8002A650: and         $a1, $a1, $v1
    ctx->r5 = ctx->r5 & ctx->r3;
    // 0x8002A654: sw          $a1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r5;
    // 0x8002A658: lhu         $v0, 0x4E($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4E);
    // 0x8002A65C: beq         $v0, $zero, L_8002A67C
    if (ctx->r2 == 0) {
        // 0x8002A660: nop
    
            goto L_8002A67C;
    }
    // 0x8002A660: nop

    // 0x8002A664: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8002A668: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8002A66C: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x8002A670: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8002A674: j           L_8002A6A0
    // 0x8002A678: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
        goto L_8002A6A0;
    // 0x8002A678: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_8002A67C:
    // 0x8002A67C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8002A680: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8002A684: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x8002A688: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8002A68C: bne         $v0, $zero, L_8002A6A0
    if (ctx->r2 != 0) {
        // 0x8002A690: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002A6A0;
    }
    // 0x8002A690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A694: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A698: sh          $v0, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r2;
    // 0x8002A69C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002A6A0:
    // 0x8002A6A0: jr          $ra
    // 0x8002A6A4: nop

    return;
    // 0x8002A6A4: nop

;}
RECOMP_FUNC void func_8002A6A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A6A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002A6AC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002A6B0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8002A6B4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8002A6B8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8002A6BC: beq         $a0, $zero, L_8002A6D4
    if (ctx->r4 == 0) {
        // 0x8002A6C0: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_8002A6D4;
    }
    // 0x8002A6C0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8002A6C4: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x8002A6C8: addiu       $s1, $s1, -0x510
    ctx->r17 = ADD32(ctx->r17, -0X510);
    // 0x8002A6CC: j           L_8002A6E0
    // 0x8002A6D0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
        goto L_8002A6E0;
    // 0x8002A6D0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
L_8002A6D4:
    // 0x8002A6D4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8002A6D8: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x8002A6DC: addiu       $s1, $s1, -0x544
    ctx->r17 = ADD32(ctx->r17, -0X544);
L_8002A6E0:
    // 0x8002A6E0: lw          $a1, 0x60($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X60);
    // 0x8002A6E4: beq         $a1, $zero, L_8002A6F4
    if (ctx->r5 == 0) {
        // 0x8002A6E8: nop
    
            goto L_8002A6F4;
    }
    // 0x8002A6E8: nop

    // 0x8002A6EC: jal         0x8003C34C
    // 0x8002A6F0: nop

    func_8003C34C(rdram, ctx);
        goto after_0;
    // 0x8002A6F0: nop

    after_0:
L_8002A6F4:
    // 0x8002A6F4: lh          $a1, 0x5C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X5C);
    // 0x8002A6F8: lh          $a2, 0x5E($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X5E);
    // 0x8002A6FC: jal         0x80002CDC
    // 0x8002A700: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80002CDC(rdram, ctx);
        goto after_1;
    // 0x8002A700: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8002A704: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8002A708: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002A70C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002A710: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002A714: jr          $ra
    // 0x8002A718: nop

    return;
    // 0x8002A718: nop

;}
RECOMP_FUNC void func_8002A71C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A71C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A720: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002A724: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8002A728: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8002A72C: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x8002A730: lhu         $v1, 0x8($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X8);
    // 0x8002A734: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8002A738: beq         $v1, $v0, L_8002A7D8
    if (ctx->r3 == ctx->r2) {
        // 0x8002A73C: slti        $v0, $v1, 0x5
        ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
            goto L_8002A7D8;
    }
    // 0x8002A73C: slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8002A740: beq         $v0, $zero, L_8002A768
    if (ctx->r2 == 0) {
        // 0x8002A744: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002A768;
    }
    // 0x8002A744: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002A748: beq         $v1, $v0, L_8002A7F8
    if (ctx->r3 == ctx->r2) {
        // 0x8002A74C: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_8002A7F8;
    }
    // 0x8002A74C: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8002A750: beq         $v0, $zero, L_8002A7B8
    if (ctx->r2 == 0) {
        // 0x8002A754: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002A7B8;
    }
    // 0x8002A754: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A758: beq         $v1, $v0, L_8002A7E8
    if (ctx->r3 == ctx->r2) {
        // 0x8002A75C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002A7E8;
    }
    // 0x8002A75C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A760: j           L_8002A808
    // 0x8002A764: nop

        goto L_8002A808;
    // 0x8002A764: nop

L_8002A768:
    // 0x8002A768: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x8002A76C: beq         $v1, $v0, L_8002A7A8
    if (ctx->r3 == ctx->r2) {
        // 0x8002A770: slti        $v0, $v1, 0x64
        ctx->r2 = SIGNED(ctx->r3) < 0X64 ? 1 : 0;
            goto L_8002A7A8;
    }
    // 0x8002A770: slti        $v0, $v1, 0x64
    ctx->r2 = SIGNED(ctx->r3) < 0X64 ? 1 : 0;
    // 0x8002A774: beq         $v0, $zero, L_8002A78C
    if (ctx->r2 == 0) {
        // 0x8002A778: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_8002A78C;
    }
    // 0x8002A778: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8002A77C: beq         $v1, $v0, L_8002A7C8
    if (ctx->r3 == ctx->r2) {
        // 0x8002A780: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002A7C8;
    }
    // 0x8002A780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A784: j           L_8002A808
    // 0x8002A788: nop

        goto L_8002A808;
    // 0x8002A788: nop

L_8002A78C:
    // 0x8002A78C: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x8002A790: bne         $v1, $v0, L_8002A808
    if (ctx->r3 != ctx->r2) {
        // 0x8002A794: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002A808;
    }
    // 0x8002A794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A798: jal         0x8002AB28
    // 0x8002A79C: nop

    func_8002AB28(rdram, ctx);
        goto after_0;
    // 0x8002A79C: nop

    after_0:
    // 0x8002A7A0: j           L_8002A80C
    // 0x8002A7A4: nop

        goto L_8002A80C;
    // 0x8002A7A4: nop

L_8002A7A8:
    // 0x8002A7A8: jal         0x8002ACB8
    // 0x8002A7AC: nop

    func_8002ACB8(rdram, ctx);
        goto after_1;
    // 0x8002A7AC: nop

    after_1:
    // 0x8002A7B0: j           L_8002A80C
    // 0x8002A7B4: nop

        goto L_8002A80C;
    // 0x8002A7B4: nop

L_8002A7B8:
    // 0x8002A7B8: jal         0x8002AD3C
    // 0x8002A7BC: nop

    func_8002AD3C(rdram, ctx);
        goto after_2;
    // 0x8002A7BC: nop

    after_2:
    // 0x8002A7C0: j           L_8002A80C
    // 0x8002A7C4: nop

        goto L_8002A80C;
    // 0x8002A7C4: nop

L_8002A7C8:
    // 0x8002A7C8: jal         0x8002AFF8
    // 0x8002A7CC: nop

    func_8002AFF8(rdram, ctx);
        goto after_3;
    // 0x8002A7CC: nop

    after_3:
    // 0x8002A7D0: j           L_8002A80C
    // 0x8002A7D4: nop

        goto L_8002A80C;
    // 0x8002A7D4: nop

L_8002A7D8:
    // 0x8002A7D8: jal         0x8002AF70
    // 0x8002A7DC: nop

    func_8002AF70(rdram, ctx);
        goto after_4;
    // 0x8002A7DC: nop

    after_4:
    // 0x8002A7E0: j           L_8002A80C
    // 0x8002A7E4: nop

        goto L_8002A80C;
    // 0x8002A7E4: nop

L_8002A7E8:
    // 0x8002A7E8: jal         0x8002A904
    // 0x8002A7EC: nop

    func_8002A904(rdram, ctx);
        goto after_5;
    // 0x8002A7EC: nop

    after_5:
    // 0x8002A7F0: j           L_8002A80C
    // 0x8002A7F4: nop

        goto L_8002A80C;
    // 0x8002A7F4: nop

L_8002A7F8:
    // 0x8002A7F8: jal         0x8002A81C
    // 0x8002A7FC: nop

    func_8002A81C(rdram, ctx);
        goto after_6;
    // 0x8002A7FC: nop

    after_6:
    // 0x8002A800: j           L_8002A80C
    // 0x8002A804: nop

        goto L_8002A80C;
    // 0x8002A804: nop

L_8002A808:
    // 0x8002A808: sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
L_8002A80C:
    // 0x8002A80C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002A810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A814: jr          $ra
    // 0x8002A818: nop

    return;
    // 0x8002A818: nop

;}
RECOMP_FUNC void func_8002A81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A81C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002A820: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002A824: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8002A828: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8002A82C: addiu       $s1, $s1, 0x31C0
    ctx->r17 = ADD32(ctx->r17, 0X31C0);
    // 0x8002A830: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002A834: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8002A838: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002A83C: jal         0x8002A5F0
    // 0x8002A840: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8002A5F0(rdram, ctx);
        goto after_0;
    // 0x8002A840: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8002A844: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x8002A848: bne         $v0, $zero, L_8002A8AC
    if (ctx->r2 != 0) {
        // 0x8002A84C: nop
    
            goto L_8002A8AC;
    }
    // 0x8002A84C: nop

    // 0x8002A850: jal         0x800306EC
    // 0x8002A854: nop

    func_800306EC(rdram, ctx);
        goto after_1;
    // 0x8002A854: nop

    after_1:
    // 0x8002A858: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x8002A85C: ori         $v1, $v1, 0x84
    ctx->r3 = ctx->r3 | 0X84;
    // 0x8002A860: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8002A864: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x8002A868: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8002A86C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8002A870: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8002A874: lhu         $v1, 0x80($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X80);
    // 0x8002A878: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002A87C: jal         0x80023E44
    // 0x8002A880: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_2;
    // 0x8002A880: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    after_2:
    // 0x8002A884: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8002A888: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x8002A88C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8002A890: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8002A894: sw          $s0, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->r16;
    // 0x8002A898: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8002A89C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8002A8A0: addiu       $v0, $zero, 0x713
    ctx->r2 = ADD32(0, 0X713);
    // 0x8002A8A4: sh          $v0, 0x70($v1)
    MEM_H(0X70, ctx->r3) = ctx->r2;
    // 0x8002A8A8: sw          $s2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r18;
L_8002A8AC:
    // 0x8002A8AC: jal         0x8002E6C0
    // 0x8002A8B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002E6C0(rdram, ctx);
        goto after_3;
    // 0x8002A8B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8002A8B4: lhu         $v1, 0x24($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X24);
    // 0x8002A8B8: lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XA);
    // 0x8002A8BC: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8002A8C0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8002A8C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002A8C8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8002A8CC: lw          $v1, 0x6370($at)
    ctx->r3 = MEM_W(ctx->r1, 0X6370);
    // 0x8002A8D0: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x8002A8D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002A8D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002A8DC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8002A8E0: jalr        $v0
    // 0x8002A8E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x8002A8E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8002A8E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A8EC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8002A8F0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002A8F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002A8F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002A8FC: jr          $ra
    // 0x8002A900: nop

    return;
    // 0x8002A900: nop

;}
RECOMP_FUNC void func_8002A904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A908: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002A90C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8002A910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002A914: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8002A918: beq         $a0, $zero, L_8002A92C
    if (ctx->r4 == 0) {
        // 0x8002A91C: nop
    
            goto L_8002A92C;
    }
    // 0x8002A91C: nop

    // 0x8002A920: jal         0x80024764
    // 0x8002A924: nop

    func_80024764(rdram, ctx);
        goto after_0;
    // 0x8002A924: nop

    after_0:
    // 0x8002A928: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_8002A92C:
    // 0x8002A92C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8002A930: lhu         $v0, -0x68E8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X68E8);
    // 0x8002A934: bne         $v0, $zero, L_8002A958
    if (ctx->r2 != 0) {
        // 0x8002A938: nop
    
            goto L_8002A958;
    }
    // 0x8002A938: nop

    // 0x8002A93C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8002A940: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x8002A944: beq         $v0, $zero, L_8002A950
    if (ctx->r2 == 0) {
        // 0x8002A948: addiu       $v0, $zero, 0x64
        ctx->r2 = ADD32(0, 0X64);
            goto L_8002A950;
    }
    // 0x8002A948: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x8002A94C: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
L_8002A950:
    // 0x8002A950: jal         0x8002E3DC
    // 0x8002A954: nop

    func_8002E3DC(rdram, ctx);
        goto after_1;
    // 0x8002A954: nop

    after_1:
L_8002A958:
    // 0x8002A958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A95C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002A960: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A964: jr          $ra
    // 0x8002A968: nop

    return;
    // 0x8002A968: nop

;}
RECOMP_FUNC void func_8002A96C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A96C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002A970: lhu         $v0, 0x13F0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X13F0);
    // FALLTHROUGH: func_8002A96C falls into func_8002A974
    func_8002A974(rdram, ctx);
;}
RECOMP_FUNC void func_8002A974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A974: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A978: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x8002A97C: beq         $v0, $zero, L_8002A9A0
    if (ctx->r2 == 0) {
        // 0x8002A980: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8002A9A0;
    }
    // 0x8002A980: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002A984: jal         0x8001F1C4
    // 0x8002A988: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_8001F1C4(rdram, ctx);
        goto after_0;
    // 0x8002A988: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x8002A98C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002A990: lhu         $v0, 0x13F0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X13F0);
    // 0x8002A994: andi        $v0, $v0, 0xFFFB
    ctx->r2 = ctx->r2 & 0XFFFB;
    // 0x8002A998: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002A99C: sh          $v0, 0x13F0($at)
    MEM_H(0X13F0, ctx->r1) = ctx->r2;
L_8002A9A0:
    // 0x8002A9A0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002A9A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A9A8: jr          $ra
    // 0x8002A9AC: nop

    return;
    // 0x8002A9AC: nop

;}
RECOMP_FUNC void func_8002A9B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A9B0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002A9B4: lhu         $v0, 0x13F0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X13F0);
    // FALLTHROUGH: func_8002A9B0 falls into func_8002A9B8
    func_8002A9B8(rdram, ctx);
;}
RECOMP_FUNC void func_8002A9B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A9B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A9BC: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x8002A9C0: bne         $v0, $zero, L_8002A9E8
    if (ctx->r2 != 0) {
        // 0x8002A9C4: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8002A9E8;
    }
    // 0x8002A9C4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002A9C8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x8002A9CC: jal         0x8004C86C
    // 0x8002A9D0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_8004C86C(rdram, ctx);
        goto after_0;
    // 0x8002A9D0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_0:
    // 0x8002A9D4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002A9D8: lhu         $v0, 0x13F0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X13F0);
    // 0x8002A9DC: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // 0x8002A9E0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002A9E4: sh          $v0, 0x13F0($at)
    MEM_H(0X13F0, ctx->r1) = ctx->r2;
L_8002A9E8:
    // 0x8002A9E8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002A9EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A9F0: jr          $ra
    // 0x8002A9F4: nop

    return;
    // 0x8002A9F4: nop

;}
RECOMP_FUNC void func_8002A9F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A9F8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8002A9FC: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // FALLTHROUGH: func_8002A9F8 falls into func_8002AA00
    func_8002AA00(rdram, ctx);
;}
RECOMP_FUNC void func_8002AA00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AA00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AA04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AA08: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002AA0C: lhu         $v0, 0x6C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6C);
    // 0x8002AA10: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8002AA14: andi        $v0, $v0, 0xFFEF
    ctx->r2 = ctx->r2 & 0XFFEF;
    // 0x8002AA18: jal         0x8000AA30
    // 0x8002AA1C: sh          $v0, 0x6C($v1)
    MEM_H(0X6C, ctx->r3) = ctx->r2;
    func_8000AA30(rdram, ctx);
        goto after_0;
    // 0x8002AA1C: sh          $v0, 0x6C($v1)
    MEM_H(0X6C, ctx->r3) = ctx->r2;
    after_0:
    // 0x8002AA20: lhu         $v0, 0x3A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3A);
    // 0x8002AA24: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002AA28: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8002AA2C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8002AA30: lw          $a1, 0x6408($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6408);
    // 0x8002AA34: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8002AA38: lw          $v0, 0x46A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X46A8);
    // 0x8002AA3C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8002AA40: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8002AA44: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x8002AA48: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002AA4C: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x8002AA50: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002AA54: lw          $v0, 0x3A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A0);
    // 0x8002AA58: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x8002AA5C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8002AA60: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x8002AA64: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002AA68: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x8002AA6C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8002AA70: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8002AA74: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x8002AA78: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8002AA7C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8002AA80: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8002AA84: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x8002AA88: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8002AA8C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8002AA90: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8002AA94: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x8002AA98: andi        $v0, $v0, 0xFFEF
    ctx->r2 = ctx->r2 & 0XFFEF;
    // 0x8002AA9C: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x8002AAA0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8002AAA4: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x8002AAA8: lhu         $v1, 0x10($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X10);
    // 0x8002AAAC: lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X22);
    // 0x8002AAB0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8002AAB4: sh          $v0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r2;
    // 0x8002AAB8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8002AABC: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8002AAC0: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x8002AAC4: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
    // 0x8002AAC8: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
    // 0x8002AACC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002AAD0: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x8002AAD4: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x8002AAD8: sh          $zero, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = 0;
    // 0x8002AADC: bne         $v1, $v0, L_8002AAFC
    if (ctx->r3 != ctx->r2) {
        // 0x8002AAE0: sh          $zero, 0xC($s0)
        MEM_H(0XC, ctx->r16) = 0;
            goto L_8002AAFC;
    }
    // 0x8002AAE0: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // 0x8002AAE4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8002AAE8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x8002AAEC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8002AAF0: addiu       $a0, $a0, 0x2E24
    ctx->r4 = ADD32(ctx->r4, 0X2E24);
    // 0x8002AAF4: j           L_8002AB0C
    // 0x8002AAF8: nop

        goto L_8002AB0C;
    // 0x8002AAF8: nop

L_8002AAFC:
    // 0x8002AAFC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8002AB00: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x8002AB04: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002AB08: addiu       $a0, $a0, 0x67AC
    ctx->r4 = ADD32(ctx->r4, 0X67AC);
L_8002AB0C:
    // 0x8002AB0C: jal         0x80037DDC
    // 0x8002AB10: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x8002AB10: nop

    after_1:
    // 0x8002AB14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002AB18: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002AB1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002AB20: jr          $ra
    // 0x8002AB24: nop

    return;
    // 0x8002AB24: nop

;}
RECOMP_FUNC void func_8002AB28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AB28: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8002AB2C: lhu         $v0, -0x68E8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X68E8);

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_8002AB30
    func_8002AB30(rdram, ctx);
}
