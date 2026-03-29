#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

// Forward declarations
void func_8005B22C(uint8_t* rdram, recomp_context* ctx);
void func_8005B554(uint8_t* rdram, recomp_context* ctx);
void func_8005C1CC(uint8_t* rdram, recomp_context* ctx);
void func_8005C27C(uint8_t* rdram, recomp_context* ctx);
void func_8005C30C(uint8_t* rdram, recomp_context* ctx);
void func_8005C3C0(uint8_t* rdram, recomp_context* ctx);
void func_8005CA90(uint8_t* rdram, recomp_context* ctx);
void func_8005CB80(uint8_t* rdram, recomp_context* ctx);
void func_8005CC5C(uint8_t* rdram, recomp_context* ctx);
void func_8005CD94(uint8_t* rdram, recomp_context* ctx);
void func_8005CF00(uint8_t* rdram, recomp_context* ctx);
void func_8005CF98(uint8_t* rdram, recomp_context* ctx);
void func_8005CFC4(uint8_t* rdram, recomp_context* ctx);
void func_8005CFFC(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_800599B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800599B4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800599B8: lh          $v1, 0x4758($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X4758);
;}
RECOMP_FUNC void func_800599BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800599BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800599C0: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x800599C4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800599C8: sltiu       $v0, $v1, 0xF
    ctx->r2 = ctx->r3 < 0XF ? 1 : 0;
    // 0x800599CC: beq         $v0, $zero, L_8005A15C
    if (ctx->r2 == 0) {
        // 0x800599D0: sw          $s0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r16;
            goto L_8005A15C;
    }
    // 0x800599D0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800599D4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800599D8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800599DC: addu        $at, $at, $v0
    gpr jr_addend_800599E4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800599E0: lw          $v0, 0x48C0($at)
    ctx->r2 = ADD32(ctx->r1, 0X48C0);
    // 0x800599E4: jr          $v0
    // 0x800599E8: nop

    switch (jr_addend_800599E4 >> 2) {
        case 0: goto L_800599EC; break;
        case 1: goto L_8005A15C; break;
        case 2: goto L_8005A15C; break;
        case 3: goto L_80059BB0; break;
        case 4: goto L_8005A15C; break;
        case 5: goto L_8005A15C; break;
        case 6: goto L_8005A15C; break;
        case 7: goto L_8005A15C; break;
        case 8: goto L_8005A15C; break;
        case 9: goto L_8005A15C; break;
        case 10: goto L_8005A15C; break;
        case 11: goto L_80059B00; break;
        case 12: goto L_8005A15C; break;
        case 13: goto L_80059E7C; break;
        case 14: goto L_80059F3C; break;
        default: switch_error(__func__, 0x800599E4, 0x800948C0);
    }
    // 0x800599E8: nop

L_800599EC:
    // 0x800599EC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800599F0: addiu       $a0, $a0, 0x484C
    ctx->r4 = ADD32(ctx->r4, 0X484C);
    // 0x800599F4: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x800599F8: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x800599FC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80059A00: addiu       $v0, $zero, 0x679
    ctx->r2 = ADD32(0, 0X679);
    // 0x80059A04: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80059A08: sh          $v0, 0x5524($at)
    MEM_H(0X5524, ctx->r1) = ctx->r2;
    // 0x80059A0C: addiu       $v0, $zero, 0x677
    ctx->r2 = ADD32(0, 0X677);
    // 0x80059A10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059A14: sh          $v0, 0x4AAC($at)
    MEM_H(0X4AAC, ctx->r1) = ctx->r2;
    // 0x80059A18: addiu       $v0, $zero, 0x676
    ctx->r2 = ADD32(0, 0X676);
    // 0x80059A1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80059A20: sh          $v0, 0x3EE0($at)
    MEM_H(0X3EE0, ctx->r1) = ctx->r2;
    // 0x80059A24: addiu       $v0, $zero, 0x679
    ctx->r2 = ADD32(0, 0X679);
    // 0x80059A28: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80059A2C: addiu       $s1, $s1, 0xF20
    ctx->r17 = ADD32(ctx->r17, 0XF20);
    // 0x80059A30: addiu       $s0, $zero, 0x400
    ctx->r16 = ADD32(0, 0X400);
    // 0x80059A34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80059A38: sh          $zero, -0x1D10($at)
    MEM_H(-0X1D10, ctx->r1) = 0;
    // 0x80059A3C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80059A40: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80059A44: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80059A48: jal         0x800010CC
    // 0x80059A4C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_800010CC(rdram, ctx);
        goto after_0;
    // 0x80059A4C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80059A50: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80059A54: addiu       $a0, $a0, 0x4864
    ctx->r4 = ADD32(ctx->r4, 0X4864);
    // 0x80059A58: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80059A5C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80059A60: lh          $v0, 0x5524($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5524);
    // 0x80059A64: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x80059A68: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80059A6C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80059A70: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80059A74: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80059A78: jal         0x800010CC
    // 0x80059A7C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_1;
    // 0x80059A7C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x80059A80: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80059A84: addiu       $a0, $a0, 0x4870
    ctx->r4 = ADD32(ctx->r4, 0X4870);
    // 0x80059A88: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80059A8C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80059A90: lh          $v0, 0x5524($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5524);
    // 0x80059A94: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x80059A98: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80059A9C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80059AA0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80059AA4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80059AA8: jal         0x800010CC
    // 0x80059AAC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_2;
    // 0x80059AAC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80059AB0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80059AB4: addiu       $a0, $a0, 0x4888
    ctx->r4 = ADD32(ctx->r4, 0X4888);
    // 0x80059AB8: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80059ABC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80059AC0: lh          $v0, 0x5524($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5524);
    // 0x80059AC4: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x80059AC8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80059ACC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80059AD0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80059AD4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80059AD8: jal         0x800010CC
    // 0x80059ADC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_3;
    // 0x80059ADC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80059AE0: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
    // 0x80059AE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80059AE8: sh          $v0, -0x68E0($at)
    MEM_H(-0X68E0, ctx->r1) = ctx->r2;
    // 0x80059AEC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80059AF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059AF4: sh          $v0, 0x4758($at)
    MEM_H(0X4758, ctx->r1) = ctx->r2;
    // 0x80059AF8: j           L_8005A15C
    // 0x80059AFC: nop

        goto L_8005A15C;
    // 0x80059AFC: nop

L_80059B00:
    // 0x80059B00: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80059B04: lhu         $v0, -0x68E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X68E0);
    // 0x80059B08: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80059B0C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80059B10: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80059B14: sh          $v1, -0x68E0($at)
    MEM_H(-0X68E0, ctx->r1) = ctx->r3;
    // 0x80059B18: bgez        $v0, L_8005A15C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80059B1C: nop
    
            goto L_8005A15C;
    }
    // 0x80059B1C: nop

    // 0x80059B20: jal         0x800246DC
    // 0x80059B24: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    func_800246DC(rdram, ctx);
        goto after_4;
    // 0x80059B24: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_4:
    // 0x80059B28: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80059B2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059B30: sh          $v0, 0x4758($at)
    MEM_H(0X4758, ctx->r1) = ctx->r2;
    // 0x80059B34: jal         0x80058724
    // 0x80059B38: nop

    func_80058724(rdram, ctx);
        goto after_5;
    // 0x80059B38: nop

    after_5:
    // 0x80059B3C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80059B40: addiu       $a0, $a0, 0x4898
    ctx->r4 = ADD32(ctx->r4, 0X4898);
    // 0x80059B44: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80059B48: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80059B4C: lhu         $v1, 0x4AAC($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X4AAC);
    // 0x80059B50: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80059B54: lh          $t0, 0x3EE0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X3EE0);
    // 0x80059B58: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80059B5C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80059B60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059B64: sh          $v0, 0x46E2($at)
    MEM_H(0X46E2, ctx->r1) = ctx->r2;
    // 0x80059B68: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80059B6C: addiu       $v0, $v0, 0xF20
    ctx->r2 = ADD32(ctx->r2, 0XF20);
    // 0x80059B70: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80059B74: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x80059B78: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80059B7C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80059B80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80059B84: sh          $v1, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r3;
    // 0x80059B88: jal         0x800010CC
    // 0x80059B8C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800010CC(rdram, ctx);
        goto after_6;
    // 0x80059B8C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_6:
    // 0x80059B90: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80059B94: addiu       $a0, $a0, -0x6A8C
    ctx->r4 = ADD32(ctx->r4, -0X6A8C);
    // 0x80059B98: jal         0x80000760
    // 0x80059B9C: nop

    func_80000760(rdram, ctx);
        goto after_7;
    // 0x80059B9C: nop

    after_7:
    // 0x80059BA0: jal         0x80056D40
    // 0x80059BA4: nop

    func_80056D40(rdram, ctx);
        goto after_8;
    // 0x80059BA4: nop

    after_8:
    // 0x80059BA8: j           L_8005A15C
    // 0x80059BAC: nop

        goto L_8005A15C;
    // 0x80059BAC: nop

L_80059BB0:
    // 0x80059BB0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80059BB4: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x80059BB8: beq         $v0, $zero, L_80059BCC
    if (ctx->r2 == 0) {
        // 0x80059BBC: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80059BCC;
    }
    // 0x80059BBC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80059BC0: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80059BC4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80059BC8: sh          $v0, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r2;
L_80059BCC:
    // 0x80059BCC: jal         0x80060AE0
    // 0x80059BD0: nop

    func_80060AE0(rdram, ctx);
        goto after_9;
    // 0x80059BD0: nop

    after_9:
    // 0x80059BD4: lui         $a1, 0x3FFF
    ctx->r5 = S32(0X3FFF << 16);
    // 0x80059BD8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80059BDC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80059BE0: lw          $v1, 0x4720($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4720);
    // 0x80059BE4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80059BE8: lw          $v0, -0x68F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68F0);
    // 0x80059BEC: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x80059BF0: ori         $a0, $a0, 0x401
    ctx->r4 = ctx->r4 | 0X401;
    // 0x80059BF4: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x80059BF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059BFC: sw          $v0, 0x4720($at)
    MEM_W(0X4720, ctx->r1) = ctx->r2;
    // 0x80059C00: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x80059C04: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80059C08: sw          $v1, 0x2588($at)
    MEM_W(0X2588, ctx->r1) = ctx->r3;
    // 0x80059C0C: beq         $v0, $zero, L_80059C5C
    if (ctx->r2 == 0) {
        // 0x80059C10: nop
    
            goto L_80059C5C;
    }
    // 0x80059C10: nop

    // 0x80059C14: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80059C18: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x80059C1C: bne         $v0, $zero, L_80059C5C
    if (ctx->r2 != 0) {
        // 0x80059C20: nop
    
            goto L_80059C5C;
    }
    // 0x80059C20: nop

    // 0x80059C24: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80059C28: lhu         $v0, -0x3078($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3078);
    // 0x80059C2C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80059C30: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80059C34: sh          $v0, -0x3078($at)
    MEM_H(-0X3078, ctx->r1) = ctx->r2;
    // 0x80059C38: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80059C3C: bgez        $v0, L_80059CC0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80059C40: nop
    
            goto L_80059CC0;
    }
    // 0x80059C40: nop

    // 0x80059C44: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80059C48: lhu         $v0, 0x46E2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X46E2);
    // 0x80059C4C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80059C50: sh          $v0, -0x3078($at)
    MEM_H(-0X3078, ctx->r1) = ctx->r2;
    // 0x80059C54: j           L_80059CC0
    // 0x80059C58: nop

        goto L_80059CC0;
    // 0x80059C58: nop

L_80059C5C:
    // 0x80059C5C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80059C60: lw          $v0, 0x4720($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4720);
    // 0x80059C64: lui         $v1, 0x20
    ctx->r3 = S32(0X20 << 16);
    // 0x80059C68: ori         $v1, $v1, 0x802
    ctx->r3 = ctx->r3 | 0X802;
    // 0x80059C6C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80059C70: beq         $v0, $zero, L_80059D00
    if (ctx->r2 == 0) {
        // 0x80059C74: nop
    
            goto L_80059D00;
    }
    // 0x80059C74: nop

    // 0x80059C78: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80059C7C: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x80059C80: bne         $v0, $zero, L_80059D00
    if (ctx->r2 != 0) {
        // 0x80059C84: nop
    
            goto L_80059D00;
    }
    // 0x80059C84: nop

    // 0x80059C88: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80059C8C: lhu         $v0, -0x3078($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3078);
    // 0x80059C90: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80059C94: lh          $v1, 0x46E2($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46E2);
    // 0x80059C98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80059C9C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80059CA0: sh          $v0, -0x3078($at)
    MEM_H(-0X3078, ctx->r1) = ctx->r2;
    // 0x80059CA4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80059CA8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80059CAC: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80059CB0: beq         $v1, $zero, L_80059CC0
    if (ctx->r3 == 0) {
        // 0x80059CB4: nop
    
            goto L_80059CC0;
    }
    // 0x80059CB4: nop

    // 0x80059CB8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80059CBC: sh          $zero, -0x3078($at)
    MEM_H(-0X3078, ctx->r1) = 0;
L_80059CC0:
    // 0x80059CC0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80059CC4: lhu         $v0, 0x82($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X82);
    // 0x80059CC8: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
    // 0x80059CCC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80059CD0: sh          $v1, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r3;
    // 0x80059CD4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80059CD8: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80059CDC: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x80059CE0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80059CE4: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80059CE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059CEC: sh          $v1, 0x82($at)
    MEM_H(0X82, ctx->r1) = ctx->r3;
    // 0x80059CF0: jal         0x8004C79C
    // 0x80059CF4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_8004C79C(rdram, ctx);
        goto after_10;
    // 0x80059CF4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_10:
    // 0x80059CF8: j           L_80059E5C
    // 0x80059CFC: nop

        goto L_80059E5C;
    // 0x80059CFC: nop

L_80059D00:
    // 0x80059D00: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80059D04: lw          $v0, 0x4720($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4720);
    // 0x80059D08: lui         $v1, 0x1C0
    ctx->r3 = S32(0X1C0 << 16);
    // 0x80059D0C: ori         $v1, $v1, 0x701C
    ctx->r3 = ctx->r3 | 0X701C;
    // 0x80059D10: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80059D14: beq         $v0, $zero, L_80059DF0
    if (ctx->r2 == 0) {
        // 0x80059D18: nop
    
            goto L_80059DF0;
    }
    // 0x80059D18: nop

    // 0x80059D1C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80059D20: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x80059D24: bne         $v0, $zero, L_80059DF0
    if (ctx->r2 != 0) {
        // 0x80059D28: nop
    
            goto L_80059DF0;
    }
    // 0x80059D28: nop

    // 0x80059D2C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80059D30: lh          $v1, -0x3078($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X3078);
    // 0x80059D34: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80059D38: lh          $v0, 0x46E2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X46E2);
    // 0x80059D3C: bne         $v1, $v0, L_80059D98
    if (ctx->r3 != ctx->r2) {
        // 0x80059D40: addiu       $a0, $zero, 0x400
        ctx->r4 = ADD32(0, 0X400);
            goto L_80059D98;
    }
    // 0x80059D40: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x80059D44: jal         0x80024E5C
    // 0x80059D48: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    func_80024E5C(rdram, ctx);
        goto after_11;
    // 0x80059D48: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    after_11:
    // 0x80059D4C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80059D50: lhu         $a0, 0x4E66($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X4E66);
    // 0x80059D54: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80059D58: lhu         $v1, 0x82($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X82);
    // 0x80059D5C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80059D60: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80059D64: sh          $v0, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r2;
    // 0x80059D68: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x80059D6C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80059D70: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80059D74: srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // 0x80059D78: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80059D7C: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80059D80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059D84: sh          $a0, 0x4E66($at)
    MEM_H(0X4E66, ctx->r1) = ctx->r4;
    // 0x80059D88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059D8C: sh          $v0, 0x82($at)
    MEM_H(0X82, ctx->r1) = ctx->r2;
    // 0x80059D90: j           L_8005A164
    // 0x80059D94: nop

        goto L_8005A164;
    // 0x80059D94: nop

L_80059D98:
    // 0x80059D98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80059D9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059DA0: sh          $v0, 0x8E($at)
    MEM_H(0X8E, ctx->r1) = ctx->r2;
    // 0x80059DA4: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x80059DA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059DAC: sh          $v0, 0x4758($at)
    MEM_H(0X4758, ctx->r1) = ctx->r2;
    // 0x80059DB0: jal         0x80024E5C
    // 0x80059DB4: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    func_80024E5C(rdram, ctx);
        goto after_12;
    // 0x80059DB4: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    after_12:
    // 0x80059DB8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80059DBC: lhu         $v1, 0x82($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X82);
    // 0x80059DC0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80059DC4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80059DC8: sh          $v0, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r2;
    // 0x80059DCC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80059DD0: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80059DD4: srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // 0x80059DD8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80059DDC: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80059DE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059DE4: sh          $v0, 0x82($at)
    MEM_H(0X82, ctx->r1) = ctx->r2;
    // 0x80059DE8: j           L_80059E5C
    // 0x80059DEC: nop

        goto L_80059E5C;
    // 0x80059DEC: nop

L_80059DF0:
    // 0x80059DF0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80059DF4: lw          $v0, 0x4720($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4720);
    // 0x80059DF8: lui         $v1, 0x401
    ctx->r3 = S32(0X401 << 16);
    // 0x80059DFC: ori         $v1, $v1, 0x40
    ctx->r3 = ctx->r3 | 0X40;
    // 0x80059E00: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80059E04: beq         $v0, $zero, L_80059E5C
    if (ctx->r2 == 0) {
        // 0x80059E08: nop
    
            goto L_80059E5C;
    }
    // 0x80059E08: nop

    // 0x80059E0C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80059E10: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x80059E14: bne         $v0, $zero, L_80059E5C
    if (ctx->r2 != 0) {
        // 0x80059E18: nop
    
            goto L_80059E5C;
    }
    // 0x80059E18: nop

    // 0x80059E1C: jal         0x8004C79C
    // 0x80059E20: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_8004C79C(rdram, ctx);
        goto after_13;
    // 0x80059E20: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_13:
    // 0x80059E24: jal         0x80054970
    // 0x80059E28: nop

    func_80054970(rdram, ctx);
        goto after_14;
    // 0x80059E28: nop

    after_14:
    // 0x80059E2C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80059E30: lhu         $v0, 0x82($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X82);
    // 0x80059E34: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
    // 0x80059E38: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80059E3C: sh          $v1, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r3;
    // 0x80059E40: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80059E44: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80059E48: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x80059E4C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80059E50: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80059E54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059E58: sh          $v1, 0x82($at)
    MEM_H(0X82, ctx->r1) = ctx->r3;
L_80059E5C:
    // 0x80059E5C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80059E60: lh          $a0, 0x4AAC($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X4AAC);
    // 0x80059E64: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80059E68: lh          $a1, 0x5524($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X5524);
    // 0x80059E6C: jal         0x80055014
    // 0x80059E70: nop

    func_80055014(rdram, ctx);
        goto after_15;
    // 0x80059E70: nop

    after_15:
    // 0x80059E74: j           L_8005A15C
    // 0x80059E78: nop

        goto L_8005A15C;
    // 0x80059E78: nop

L_80059E7C:
    // 0x80059E7C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80059E80: addiu       $a0, $a0, 0x48A8
    ctx->r4 = ADD32(ctx->r4, 0X48A8);
    // 0x80059E84: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80059E88: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80059E8C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80059E90: lh          $v1, 0x3EE0($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X3EE0);
    // 0x80059E94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80059E98: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80059E9C: addiu       $v0, $v0, 0xF20
    ctx->r2 = ADD32(ctx->r2, 0XF20);
    // 0x80059EA0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80059EA4: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x80059EA8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80059EAC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80059EB0: jal         0x800010CC
    // 0x80059EB4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    func_800010CC(rdram, ctx);
        goto after_16;
    // 0x80059EB4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_16:
    // 0x80059EB8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80059EBC: addiu       $a0, $a0, 0x48B8
    ctx->r4 = ADD32(ctx->r4, 0X48B8);
    // 0x80059EC0: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80059EC4: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    // 0x80059EC8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80059ECC: lh          $v1, 0x5524($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X5524);
    // 0x80059ED0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80059ED4: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80059ED8: addiu       $s0, $s0, 0x10A0
    ctx->r16 = ADD32(ctx->r16, 0X10A0);
    // 0x80059EDC: addiu       $v0, $zero, 0x415
    ctx->r2 = ADD32(0, 0X415);
    // 0x80059EE0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80059EE4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80059EE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80059EEC: jal         0x800010CC
    // 0x80059EF0: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    func_800010CC(rdram, ctx);
        goto after_17;
    // 0x80059EF0: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_17:
    // 0x80059EF4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80059EF8: addiu       $a0, $a0, 0x48BC
    ctx->r4 = ADD32(ctx->r4, 0X48BC);
    // 0x80059EFC: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80059F00: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80059F04: lh          $v1, 0x4AAC($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X4AAC);
    // 0x80059F08: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    // 0x80059F0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80059F10: addiu       $v0, $zero, 0x416
    ctx->r2 = ADD32(0, 0X416);
    // 0x80059F14: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80059F18: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80059F1C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80059F20: jal         0x800010CC
    // 0x80059F24: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    func_800010CC(rdram, ctx);
        goto after_18;
    // 0x80059F24: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_18:
    // 0x80059F28: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x80059F2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059F30: sh          $v0, 0x4758($at)
    MEM_H(0X4758, ctx->r1) = ctx->r2;
    // 0x80059F34: j           L_8005A15C
    // 0x80059F38: nop

        goto L_8005A15C;
    // 0x80059F38: nop

L_80059F3C:
    // 0x80059F3C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80059F40: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x80059F44: beq         $v0, $zero, L_80059F58
    if (ctx->r2 == 0) {
        // 0x80059F48: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80059F58;
    }
    // 0x80059F48: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80059F4C: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80059F50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80059F54: sh          $v0, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r2;
L_80059F58:
    // 0x80059F58: jal         0x80060AE0
    // 0x80059F5C: nop

    func_80060AE0(rdram, ctx);
        goto after_19;
    // 0x80059F5C: nop

    after_19:
    // 0x80059F60: lui         $a1, 0x3FFF
    ctx->r5 = S32(0X3FFF << 16);
    // 0x80059F64: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80059F68: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80059F6C: lw          $v1, 0x4720($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4720);
    // 0x80059F70: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80059F74: lw          $v0, -0x68F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68F0);
    // 0x80059F78: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x80059F7C: ori         $a0, $a0, 0x401
    ctx->r4 = ctx->r4 | 0X401;
    // 0x80059F80: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x80059F84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059F88: sw          $v0, 0x4720($at)
    MEM_W(0X4720, ctx->r1) = ctx->r2;
    // 0x80059F8C: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x80059F90: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80059F94: sw          $v1, 0x2588($at)
    MEM_W(0X2588, ctx->r1) = ctx->r3;
    // 0x80059F98: beq         $v0, $zero, L_80059FB0
    if (ctx->r2 == 0) {
        // 0x80059F9C: nop
    
            goto L_80059FB0;
    }
    // 0x80059F9C: nop

    // 0x80059FA0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80059FA4: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x80059FA8: beq         $v0, $zero, L_80059FDC
    if (ctx->r2 == 0) {
        // 0x80059FAC: nop
    
            goto L_80059FDC;
    }
    // 0x80059FAC: nop

L_80059FB0:
    // 0x80059FB0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80059FB4: lw          $v0, 0x4720($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4720);
    // 0x80059FB8: lui         $v1, 0x20
    ctx->r3 = S32(0X20 << 16);
    // 0x80059FBC: ori         $v1, $v1, 0x802
    ctx->r3 = ctx->r3 | 0X802;
    // 0x80059FC0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80059FC4: beq         $v0, $zero, L_8005A030
    if (ctx->r2 == 0) {
        // 0x80059FC8: nop
    
            goto L_8005A030;
    }
    // 0x80059FC8: nop

    // 0x80059FCC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80059FD0: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x80059FD4: bne         $v0, $zero, L_8005A030
    if (ctx->r2 != 0) {
        // 0x80059FD8: nop
    
            goto L_8005A030;
    }
    // 0x80059FD8: nop

L_80059FDC:
    // 0x80059FDC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80059FE0: lhu         $a1, 0x8E($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X8E);
    // 0x80059FE4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80059FE8: lhu         $v1, 0x82($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X82);
    // 0x80059FEC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80059FF0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80059FF4: sh          $v0, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r2;
    // 0x80059FF8: xori        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 ^ 0X1;
    // 0x80059FFC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8005A000: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8005A004: srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // 0x8005A008: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005A00C: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8005A010: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A014: sh          $a1, 0x8E($at)
    MEM_H(0X8E, ctx->r1) = ctx->r5;
    // 0x8005A018: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A01C: sh          $v0, 0x82($at)
    MEM_H(0X82, ctx->r1) = ctx->r2;
    // 0x8005A020: jal         0x8004C79C
    // 0x8005A024: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_8004C79C(rdram, ctx);
        goto after_20;
    // 0x8005A024: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_20:
    // 0x8005A028: j           L_8005A10C
    // 0x8005A02C: nop

        goto L_8005A10C;
    // 0x8005A02C: nop

L_8005A030:
    // 0x8005A030: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005A034: lw          $v0, 0x4720($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4720);
    // 0x8005A038: lui         $v1, 0x1C0
    ctx->r3 = S32(0X1C0 << 16);
    // 0x8005A03C: ori         $v1, $v1, 0x701C
    ctx->r3 = ctx->r3 | 0X701C;
    // 0x8005A040: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8005A044: beq         $v0, $zero, L_8005A10C
    if (ctx->r2 == 0) {
        // 0x8005A048: nop
    
            goto L_8005A10C;
    }
    // 0x8005A048: nop

    // 0x8005A04C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005A050: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x8005A054: bne         $v0, $zero, L_8005A10C
    if (ctx->r2 != 0) {
        // 0x8005A058: nop
    
            goto L_8005A10C;
    }
    // 0x8005A058: nop

    // 0x8005A05C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005A060: lh          $v0, 0x8E($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X8E);
    // 0x8005A064: bne         $v0, $zero, L_8005A0C0
    if (ctx->r2 != 0) {
        // 0x8005A068: addiu       $a0, $zero, 0x400
        ctx->r4 = ADD32(0, 0X400);
            goto L_8005A0C0;
    }
    // 0x8005A068: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x8005A06C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8005A070: lh          $v0, -0x3078($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X3078);
    // 0x8005A074: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005A078: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005A07C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005A080: lh          $v1, -0x2E($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X2E);
    // 0x8005A084: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A088: sh          $zero, 0x4AAA($at)
    MEM_H(0X4AAA, ctx->r1) = 0;
    // 0x8005A08C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A090: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A094: sh          $v0, 0x570A($at)
    MEM_H(0X570A, ctx->r1) = ctx->r2;
    // 0x8005A098: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005A09C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A0A0: sh          $v0, 0x5A28($at)
    MEM_H(0X5A28, ctx->r1) = ctx->r2;
    // 0x8005A0A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A0A8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005A0AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A0B0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8005A0B4: sw          $v0, 0x571C($at)
    MEM_W(0X571C, ctx->r1) = ctx->r2;
    // 0x8005A0B8: j           L_8005A0DC
    // 0x8005A0BC: nop

        goto L_8005A0DC;
    // 0x8005A0BC: nop

L_8005A0C0:
    // 0x8005A0C0: jal         0x80024E5C
    // 0x8005A0C4: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    func_80024E5C(rdram, ctx);
        goto after_21;
    // 0x8005A0C4: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    after_21:
    // 0x8005A0C8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005A0CC: lhu         $v0, 0x4E66($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E66);
    // 0x8005A0D0: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8005A0D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A0D8: sh          $v0, 0x4E66($at)
    MEM_H(0X4E66, ctx->r1) = ctx->r2;
L_8005A0DC:
    // 0x8005A0DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005A0E0: lhu         $v0, 0x82($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X82);
    // 0x8005A0E4: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
    // 0x8005A0E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005A0EC: sh          $v1, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r3;
    // 0x8005A0F0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005A0F4: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005A0F8: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x8005A0FC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005A100: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8005A104: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A108: sh          $v1, 0x82($at)
    MEM_H(0X82, ctx->r1) = ctx->r3;
L_8005A10C:
    // 0x8005A10C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005A110: lh          $v0, 0x8E($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X8E);
    // 0x8005A114: bne         $v0, $zero, L_8005A13C
    if (ctx->r2 != 0) {
        // 0x8005A118: nop
    
            goto L_8005A13C;
    }
    // 0x8005A118: nop

    // 0x8005A11C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8005A120: lh          $a1, 0x4AAC($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X4AAC);
    // 0x8005A124: jal         0x8000163C
    // 0x8005A128: addiu       $a0, $zero, 0x415
    ctx->r4 = ADD32(0, 0X415);
    func_8000163C(rdram, ctx);
        goto after_22;
    // 0x8005A128: addiu       $a0, $zero, 0x415
    ctx->r4 = ADD32(0, 0X415);
    after_22:
    // 0x8005A12C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8005A130: lh          $a1, 0x5524($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X5524);
    // 0x8005A134: j           L_8005A154
    // 0x8005A138: nop

        goto L_8005A154;
    // 0x8005A138: nop

L_8005A13C:
    // 0x8005A13C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8005A140: lh          $a1, 0x5524($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X5524);
    // 0x8005A144: jal         0x8000163C
    // 0x8005A148: addiu       $a0, $zero, 0x415
    ctx->r4 = ADD32(0, 0X415);
    func_8000163C(rdram, ctx);
        goto after_23;
    // 0x8005A148: addiu       $a0, $zero, 0x415
    ctx->r4 = ADD32(0, 0X415);
    after_23:
    // 0x8005A14C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8005A150: lh          $a1, 0x4AAC($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X4AAC);
L_8005A154:
    // 0x8005A154: jal         0x8000163C
    // 0x8005A158: addiu       $a0, $zero, 0x416
    ctx->r4 = ADD32(0, 0X416);
    func_8000163C(rdram, ctx);
        goto after_24;
    // 0x8005A158: addiu       $a0, $zero, 0x416
    ctx->r4 = ADD32(0, 0X416);
    after_24:
L_8005A15C:
    // 0x8005A15C: jal         0x800028FC
    // 0x8005A160: nop

    func_800028FC(rdram, ctx);
        goto after_25;
    // 0x8005A160: nop

    after_25:
L_8005A164:
    // 0x8005A164: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x8005A168: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8005A16C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8005A170: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8005A174: jr          $ra
    // 0x8005A178: nop

    return;
    // 0x8005A178: nop

;}
RECOMP_FUNC void func_8005A17C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A17C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8005A180: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8005A184:
    // 0x8005A184: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005A188: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8005A18C: lh          $v0, 0x5758($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5758);
    // 0x8005A190: bnel        $v0, $a0, L_8005A1A0
    if (ctx->r2 != ctx->r4) {
        // 0x8005A194: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8005A1A0;
    }
    goto skip_0;
    // 0x8005A194: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8005A198: j           L_8005A1B0
    // 0x8005A19C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005A1B0;
    // 0x8005A19C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8005A1A0:
    // 0x8005A1A0: slti        $v0, $v1, 0x6
    ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x8005A1A4: bne         $v0, $zero, L_8005A184
    if (ctx->r2 != 0) {
        // 0x8005A1A8: addiu       $a1, $a1, 0x70
        ctx->r5 = ADD32(ctx->r5, 0X70);
            goto L_8005A184;
    }
    // 0x8005A1A8: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x8005A1AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005A1B0:
    // 0x8005A1B0: jr          $ra
    // 0x8005A1B4: nop

    return;
    // 0x8005A1B4: nop

;}
RECOMP_FUNC void func_8005A1B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A1B8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005A1BC: lh          $v1, 0x4AAA($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X4AAA);
;}
RECOMP_FUNC void func_8005A1C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A1C0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8005A1C4: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8005A1C8: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8005A1CC: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8005A1D0: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8005A1D4: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8005A1D8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8005A1DC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8005A1E0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8005A1E4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8005A1E8: sltiu       $v0, $v1, 0x10
    ctx->r2 = ctx->r3 < 0X10 ? 1 : 0;
    // 0x8005A1EC: beq         $v0, $zero, L_8005A97C
    if (ctx->r2 == 0) {
        // 0x8005A1F0: sw          $s0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r16;
            goto L_8005A97C;
    }
    // 0x8005A1F0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8005A1F4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005A1F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005A1FC: addu        $at, $at, $v0
    gpr jr_addend_8005A204 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005A200: lw          $v0, 0x4948($at)
    ctx->r2 = ADD32(ctx->r1, 0X4948);
    // 0x8005A204: jr          $v0
    // 0x8005A208: nop

    switch (jr_addend_8005A204 >> 2) {
        case 0: goto L_8005A20C; break;
        case 1: goto L_8005A97C; break;
        case 2: goto L_8005A97C; break;
        case 3: goto L_8005A97C; break;
        case 4: goto L_8005A97C; break;
        case 5: goto L_8005A624; break;
        case 6: goto L_8005A6EC; break;
        case 7: goto L_8005A97C; break;
        case 8: goto L_8005A7E4; break;
        case 9: goto L_8005A810; break;
        case 10: goto L_8005A97C; break;
        case 11: goto L_8005A5E8; break;
        case 12: goto L_8005A97C; break;
        case 13: goto L_8005A97C; break;
        case 14: goto L_8005A97C; break;
        case 15: goto L_8005A8B4; break;
        default: switch_error(__func__, 0x8005A204, 0x80094948);
    }
    // 0x8005A208: nop

L_8005A20C:
    // 0x8005A20C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8005A210: lh          $a0, 0x5708($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X5708);
    // 0x8005A214: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8005A218: beq         $a0, $s0, L_8005A248
    if (ctx->r4 == ctx->r16) {
        // 0x8005A21C: nop
    
            goto L_8005A248;
    }
    // 0x8005A21C: nop

    // 0x8005A220: jal         0x8005A17C
    // 0x8005A224: nop

    func_8005A17C(rdram, ctx);
        goto after_0;
    // 0x8005A224: nop

    after_0:
    // 0x8005A228: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8005A22C: bne         $s3, $s0, L_8005A258
    if (ctx->r19 != ctx->r16) {
        // 0x8005A230: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_8005A258;
    }
    // 0x8005A230: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8005A234: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8005A238: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005A23C: sh          $v0, -0x68E0($at)
    MEM_H(-0X68E0, ctx->r1) = ctx->r2;
    // 0x8005A240: j           L_8005A6DC
    // 0x8005A244: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_8005A6DC;
    // 0x8005A244: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_8005A248:
    // 0x8005A248: jal         0x8005935C
    // 0x8005A24C: nop

    func_8005935C(rdram, ctx);
        goto after_1;
    // 0x8005A24C: nop

    after_1:
    // 0x8005A250: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8005A254: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
L_8005A258:
    // 0x8005A258: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x8005A25C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A260: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005A264: sw          $zero, 0x571C($at)
    MEM_W(0X571C, ctx->r1) = 0;
    // 0x8005A268: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005A26C: lw          $v1, 0x5718($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5718);
    // 0x8005A270: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8005A274: addiu       $a1, $a1, 0x48FC
    ctx->r5 = ADD32(ctx->r5, 0X48FC);
    // 0x8005A278: sll         $s1, $s3, 3
    ctx->r17 = S32(ctx->r19 << 3);
    // 0x8005A27C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A280: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A284: sw          $v0, 0x5718($at)
    MEM_W(0X5718, ctx->r1) = ctx->r2;
    // 0x8005A288: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005A28C: lh          $v0, -0x1D66($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X1D66);
    // 0x8005A290: subu        $s1, $s1, $s3
    ctx->r17 = SUB32(ctx->r17, ctx->r19);
    // 0x8005A294: sll         $s1, $s1, 4
    ctx->r17 = S32(ctx->r17 << 4);
    // 0x8005A298: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A29C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8005A2A0: sh          $v1, 0x5758($at)
    MEM_H(0X5758, ctx->r1) = ctx->r3;
    // 0x8005A2A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005A2A8: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8005A2AC: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8005A2B0: lw          $a2, -0x313C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X313C);
    // 0x8005A2B4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8005A2B8: addiu       $s0, $s0, 0x571C
    ctx->r16 = ADD32(ctx->r16, 0X571C);
    // 0x8005A2BC: jal         0x80073220
    // 0x8005A2C0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_2;
    // 0x8005A2C0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    after_2:
    // 0x8005A2C4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005A2C8: lhu         $v1, -0x1D66($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X1D66);
    // 0x8005A2CC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005A2D0: lhu         $a0, -0x5874($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X5874);
    // 0x8005A2D4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8005A2D8: lhu         $a1, 0x2560($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X2560);
    // 0x8005A2DC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8005A2E0: lhu         $a2, 0x538($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X538);
    // 0x8005A2E4: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x8005A2E8: lw          $a3, 0x4E0C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4E0C);
    // 0x8005A2EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005A2F0: lhu         $t0, 0x90($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X90);
    // 0x8005A2F4: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8005A2F8: lhu         $t1, 0x50EC($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X50EC);
    // 0x8005A2FC: addiu       $v0, $s0, 0x4E
    ctx->r2 = ADD32(ctx->r16, 0X4E);
    // 0x8005A300: addu        $fp, $s1, $v0
    ctx->r30 = ADD32(ctx->r17, ctx->r2);
    // 0x8005A304: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A308: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8005A30C: sh          $v1, 0x575A($at)
    MEM_H(0X575A, ctx->r1) = ctx->r3;
    // 0x8005A310: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A314: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8005A318: sh          $a0, 0x575C($at)
    MEM_H(0X575C, ctx->r1) = ctx->r4;
    // 0x8005A31C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A320: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8005A324: sh          $a1, 0x575E($at)
    MEM_H(0X575E, ctx->r1) = ctx->r5;
    // 0x8005A328: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A32C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8005A330: sh          $a2, 0x5760($at)
    MEM_H(0X5760, ctx->r1) = ctx->r6;
    // 0x8005A334: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A338: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8005A33C: sh          $a3, 0x5762($at)
    MEM_H(0X5762, ctx->r1) = ctx->r7;
    // 0x8005A340: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A344: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8005A348: sh          $t0, 0x5794($at)
    MEM_H(0X5794, ctx->r1) = ctx->r8;
    // 0x8005A34C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A350: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8005A354: sh          $t1, 0x57BC($at)
    MEM_H(0X57BC, ctx->r1) = ctx->r9;
    // 0x8005A358: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005A35C: lhu         $v1, 0x4716($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X4716);
    // 0x8005A360: addiu       $v0, $s0, 0x54
    ctx->r2 = ADD32(ctx->r16, 0X54);
    // 0x8005A364: addu        $s7, $s1, $v0
    ctx->r23 = ADD32(ctx->r17, ctx->r2);
    // 0x8005A368: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A36C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8005A370: sh          $v1, 0x57A6($at)
    MEM_H(0X57A6, ctx->r1) = ctx->r3;
    // 0x8005A374: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005A378: lhu         $v1, 0x4718($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X4718);
    // 0x8005A37C: addiu       $v0, $s0, 0x60
    ctx->r2 = ADD32(ctx->r16, 0X60);
    // 0x8005A380: addu        $s6, $s1, $v0
    ctx->r22 = ADD32(ctx->r17, ctx->r2);
    // 0x8005A384: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A388: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8005A38C: sh          $v1, 0x57A8($at)
    MEM_H(0X57A8, ctx->r1) = ctx->r3;
    // 0x8005A390: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005A394: lhu         $v1, 0x471A($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X471A);
    // 0x8005A398: addiu       $v0, $s0, 0x6C
    ctx->r2 = ADD32(ctx->r16, 0X6C);
    // 0x8005A39C: addu        $s5, $s1, $v0
    ctx->r21 = ADD32(ctx->r17, ctx->r2);
    // 0x8005A3A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A3A4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8005A3A8: sh          $v1, 0x57AA($at)
    MEM_H(0X57AA, ctx->r1) = ctx->r3;
    // 0x8005A3AC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005A3B0: lhu         $v0, 0x471C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X471C);
    // 0x8005A3B4: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x8005A3B8: addu        $s4, $s1, $s0
    ctx->r20 = ADD32(ctx->r17, ctx->r16);
    // 0x8005A3BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A3C0: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8005A3C4: sh          $v0, 0x57AC($at)
    MEM_H(0X57AC, ctx->r1) = ctx->r2;
    // 0x8005A3C8: addiu       $s0, $s2, 0x1
    ctx->r16 = ADD32(ctx->r18, 0X1);
L_8005A3CC:
    // 0x8005A3CC: jal         0x8001F310
    // 0x8005A3D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001F310(rdram, ctx);
        goto after_3;
    // 0x8005A3D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8005A3D4: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8005A3D8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005A3DC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8005A3E0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005A3E4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005A3E8: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8005A3EC: addiu       $t4, $t4, 0x3F94
    ctx->r12 = ADD32(ctx->r12, 0X3F94);
    // 0x8005A3F0: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x8005A3F4: sll         $a0, $s2, 1
    ctx->r4 = S32(ctx->r18 << 1);
    // 0x8005A3F8: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x8005A3FC: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8005A400: addiu       $t4, $t4, 0x5764
    ctx->r12 = ADD32(ctx->r12, 0X5764);
    // 0x8005A404: addu        $v0, $s1, $t4
    ctx->r2 = ADD32(ctx->r17, ctx->r12);
    // 0x8005A408: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8005A40C: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // 0x8005A410: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8005A414: addu        $a0, $a0, $fp
    ctx->r4 = ADD32(ctx->r4, ctx->r30);
    // 0x8005A418: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8005A41C: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x8005A420: sll         $a1, $s2, 2
    ctx->r5 = S32(ctx->r18 << 2);
    // 0x8005A424: addu        $v0, $a1, $s7
    ctx->r2 = ADD32(ctx->r5, ctx->r23);
    // 0x8005A428: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8005A42C: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x8005A430: addu        $v0, $a1, $s6
    ctx->r2 = ADD32(ctx->r5, ctx->r22);
    // 0x8005A434: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8005A438: lw          $v1, 0x38($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X38);
    // 0x8005A43C: addu        $v0, $a1, $s5
    ctx->r2 = ADD32(ctx->r5, ctx->r21);
    // 0x8005A440: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8005A444: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005A448: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8005A44C: lw          $v1, 0x4DF8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4DF8);
    // 0x8005A450: addu        $v0, $s4, $s2
    ctx->r2 = ADD32(ctx->r20, ctx->r18);
    // 0x8005A454: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // 0x8005A458: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8005A45C: slti        $v0, $s2, 0x3
    ctx->r2 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x8005A460: bne         $v0, $zero, L_8005A3CC
    if (ctx->r2 != 0) {
        // 0x8005A464: addiu       $s0, $s2, 0x1
        ctx->r16 = ADD32(ctx->r18, 0X1);
            goto L_8005A3CC;
    }
    // 0x8005A464: addiu       $s0, $s2, 0x1
    ctx->r16 = ADD32(ctx->r18, 0X1);
    // 0x8005A468: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8005A46C: sll         $v0, $s3, 3
    ctx->r2 = S32(ctx->r19 << 3);
    // 0x8005A470: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x8005A474: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8005A478: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8005A47C: addiu       $a0, $a0, 0x57AE
    ctx->r4 = ADD32(ctx->r4, 0X57AE);
    // 0x8005A480: addiu       $v1, $a0, -0xF
    ctx->r3 = ADD32(ctx->r4, -0XF);
    // 0x8005A484: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // 0x8005A488: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8005A48C: addiu       $a1, $a1, -0x1030
    ctx->r5 = ADD32(ctx->r5, -0X1030);
    // 0x8005A490: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x8005A494: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8005A498: addiu       $v1, $v1, -0x3074
    ctx->r3 = ADD32(ctx->r3, -0X3074);
L_8005A49C:
    // 0x8005A49C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8005A4A0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8005A4A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8005A4A8: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8005A4AC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8005A4B0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8005A4B4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8005A4B8: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8005A4BC: slti        $v0, $s2, 0x7
    ctx->r2 = SIGNED(ctx->r18) < 0X7 ? 1 : 0;
    // 0x8005A4C0: bne         $v0, $zero, L_8005A49C
    if (ctx->r2 != 0) {
        // 0x8005A4C4: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8005A49C;
    }
    // 0x8005A4C4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8005A4C8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8005A4CC: addiu       $a0, $a0, 0x5718
    ctx->r4 = ADD32(ctx->r4, 0X5718);
    // 0x8005A4D0: sll         $v0, $s3, 3
    ctx->r2 = S32(ctx->r19 << 3);
    // 0x8005A4D4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005A4D8: lhu         $v1, -0x5634($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X5634);
    // 0x8005A4DC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8005A4E0: lhu         $a1, 0x416A($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X416A);
    // 0x8005A4E4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8005A4E8: lhu         $a2, 0x13E6($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X13E6);
    // 0x8005A4EC: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8005A4F0: lhu         $a3, 0x13E8($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X13E8);
    // 0x8005A4F4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8005A4F8: lhu         $t0, -0x1D3C($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X1D3C);
    // 0x8005A4FC: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8005A500: lhu         $t1, 0x13E2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X13E2);
    // 0x8005A504: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8005A508: lhu         $t2, 0x13E4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X13E4);
    // 0x8005A50C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8005A510: lhu         $t3, 0x13EA($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X13EA);
    // 0x8005A514: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x8005A518: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8005A51C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A520: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005A524: sh          $v1, 0x5796($at)
    MEM_H(0X5796, ctx->r1) = ctx->r3;
    // 0x8005A528: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A52C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005A530: sh          $a1, 0x5798($at)
    MEM_H(0X5798, ctx->r1) = ctx->r5;
    // 0x8005A534: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A538: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005A53C: sh          $a2, 0x579A($at)
    MEM_H(0X579A, ctx->r1) = ctx->r6;
    // 0x8005A540: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A544: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005A548: sh          $a3, 0x57BE($at)
    MEM_H(0X57BE, ctx->r1) = ctx->r7;
    // 0x8005A54C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A550: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005A554: sh          $t0, 0x57C0($at)
    MEM_H(0X57C0, ctx->r1) = ctx->r8;
    // 0x8005A558: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A55C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005A560: sh          $t1, 0x57C2($at)
    MEM_H(0X57C2, ctx->r1) = ctx->r9;
    // 0x8005A564: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A568: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005A56C: sh          $t2, 0x57C4($at)
    MEM_H(0X57C4, ctx->r1) = ctx->r10;
    // 0x8005A570: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A574: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005A578: sh          $t3, 0x57C6($at)
    MEM_H(0X57C6, ctx->r1) = ctx->r11;
    // 0x8005A57C: jal         0x8005D9F0
    // 0x8005A580: nop

    func_8005D9F0(rdram, ctx);
        goto after_4;
    // 0x8005A580: nop

    after_4:
    // 0x8005A584: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005A588: addiu       $a0, $a0, 0x4900
    ctx->r4 = ADD32(ctx->r4, 0X4900);
    // 0x8005A58C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8005A590: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8005A594: lh          $v1, 0x5524($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X5524);
    // 0x8005A598: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x8005A59C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005A5A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A5A4: sw          $v0, 0x5750($at)
    MEM_W(0X5750, ctx->r1) = ctx->r2;
    // 0x8005A5A8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8005A5AC: addiu       $v0, $v0, 0xF20
    ctx->r2 = ADD32(ctx->r2, 0XF20);
    // 0x8005A5B0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005A5B4: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x8005A5B8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005A5BC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005A5C0: jal         0x800010CC
    // 0x8005A5C4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    func_800010CC(rdram, ctx);
        goto after_5;
    // 0x8005A5C4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_5:
    // 0x8005A5C8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8005A5CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A5D0: sh          $v0, 0x4AAA($at)
    MEM_H(0X4AAA, ctx->r1) = ctx->r2;
    // 0x8005A5D4: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x8005A5D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005A5DC: sh          $v0, -0x68E0($at)
    MEM_H(-0X68E0, ctx->r1) = ctx->r2;
    // 0x8005A5E0: j           L_8005A97C
    // 0x8005A5E4: nop

        goto L_8005A97C;
    // 0x8005A5E4: nop

L_8005A5E8:
    // 0x8005A5E8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005A5EC: lhu         $v0, -0x68E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X68E0);
    // 0x8005A5F0: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8005A5F4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005A5F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005A5FC: sh          $v1, -0x68E0($at)
    MEM_H(-0X68E0, ctx->r1) = ctx->r3;
    // 0x8005A600: bgez        $v0, L_8005A97C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005A604: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8005A97C;
    }
    // 0x8005A604: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8005A608: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A60C: sh          $v0, 0x4AAA($at)
    MEM_H(0X4AAA, ctx->r1) = ctx->r2;
    // 0x8005A610: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8005A614: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005A618: sh          $v0, -0x68E0($at)
    MEM_H(-0X68E0, ctx->r1) = ctx->r2;
    // 0x8005A61C: j           L_8005A97C
    // 0x8005A620: nop

        goto L_8005A97C;
    // 0x8005A620: nop

L_8005A624:
    // 0x8005A624: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8005A628: addiu       $a0, $a0, 0x5718
    ctx->r4 = ADD32(ctx->r4, 0X5718);
    // 0x8005A62C: jal         0x8005D71C
    // 0x8005A630: nop

    func_8005D71C(rdram, ctx);
        goto after_6;
    // 0x8005A630: nop

    after_6:
    // 0x8005A634: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A638: bne         $v1, $zero, L_8005A65C
    if (ctx->r3 != 0) {
        // 0x8005A63C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8005A65C;
    }
    // 0x8005A63C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8005A640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A644: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A648: sh          $v0, 0x570A($at)
    MEM_H(0X570A, ctx->r1) = ctx->r2;
    // 0x8005A64C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8005A650: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A654: sh          $v0, 0x4AAA($at)
    MEM_H(0X4AAA, ctx->r1) = ctx->r2;
    // 0x8005A658: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8005A65C:
    // 0x8005A65C: bne         $v1, $v0, L_8005A680
    if (ctx->r3 != ctx->r2) {
        // 0x8005A660: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005A680;
    }
    // 0x8005A660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A664: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A668: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A66C: sh          $v0, 0x570A($at)
    MEM_H(0X570A, ctx->r1) = ctx->r2;
    // 0x8005A670: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8005A674: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A678: sh          $v0, 0x5A28($at)
    MEM_H(0X5A28, ctx->r1) = ctx->r2;
    // 0x8005A67C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A680:
    // 0x8005A680: bne         $v1, $v0, L_8005A6A4
    if (ctx->r3 != ctx->r2) {
        // 0x8005A684: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8005A6A4;
    }
    // 0x8005A684: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8005A688: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A68C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A690: sh          $v0, 0x570A($at)
    MEM_H(0X570A, ctx->r1) = ctx->r2;
    // 0x8005A694: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8005A698: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A69C: sh          $v0, 0x4AAA($at)
    MEM_H(0X4AAA, ctx->r1) = ctx->r2;
    // 0x8005A6A0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8005A6A4:
    // 0x8005A6A4: bne         $v1, $v0, L_8005A6C8
    if (ctx->r3 != ctx->r2) {
        // 0x8005A6A8: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_8005A6C8;
    }
    // 0x8005A6A8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8005A6AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A6B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A6B4: sh          $v0, 0x570A($at)
    MEM_H(0X570A, ctx->r1) = ctx->r2;
    // 0x8005A6B8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8005A6BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A6C0: sh          $v0, 0x4AAA($at)
    MEM_H(0X4AAA, ctx->r1) = ctx->r2;
    // 0x8005A6C4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_8005A6C8:
    // 0x8005A6C8: bne         $v1, $v0, L_8005A97C
    if (ctx->r3 != ctx->r2) {
        // 0x8005A6CC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005A97C;
    }
    // 0x8005A6CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A6D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A6D4: sh          $v0, 0x570A($at)
    MEM_H(0X570A, ctx->r1) = ctx->r2;
    // 0x8005A6D8: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_8005A6DC:
    // 0x8005A6DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A6E0: sh          $v0, 0x4AAA($at)
    MEM_H(0X4AAA, ctx->r1) = ctx->r2;
    // 0x8005A6E4: j           L_8005A97C
    // 0x8005A6E8: nop

        goto L_8005A97C;
    // 0x8005A6E8: nop

L_8005A6EC:
    // 0x8005A6EC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005A6F0: lh          $v1, -0x68E0($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X68E0);
    // 0x8005A6F4: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8005A6F8: bne         $v1, $v0, L_8005A7A8
    if (ctx->r3 != ctx->r2) {
        // 0x8005A6FC: addiu       $a1, $zero, 0xC8
        ctx->r5 = ADD32(0, 0XC8);
            goto L_8005A7A8;
    }
    // 0x8005A6FC: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8005A700: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005A704: addiu       $a0, $a0, 0x490C
    ctx->r4 = ADD32(ctx->r4, 0X490C);
    // 0x8005A708: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x8005A70C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005A710: lw          $v1, 0x5718($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5718);
    // 0x8005A714: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8005A718: lh          $t0, 0x5524($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X5524);
    // 0x8005A71C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005A720: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8005A724: addiu       $v0, $v0, 0xF20
    ctx->r2 = ADD32(ctx->r2, 0XF20);
    // 0x8005A728: addiu       $s0, $zero, 0x400
    ctx->r16 = ADD32(0, 0X400);
    // 0x8005A72C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005A730: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005A734: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005A738: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8005A73C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A740: sh          $v1, 0x5708($at)
    MEM_H(0X5708, ctx->r1) = ctx->r3;
    // 0x8005A744: jal         0x800010CC
    // 0x8005A748: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800010CC(rdram, ctx);
        goto after_7;
    // 0x8005A748: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_7:
    // 0x8005A74C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005A750: lh          $v0, -0x1D66($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X1D66);
    // 0x8005A754: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005A758: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8005A75C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8005A760: lw          $a2, -0x313C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X313C);
    // 0x8005A764: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8005A768: addiu       $a1, $a1, 0x48FC
    ctx->r5 = ADD32(ctx->r5, 0X48FC);
    // 0x8005A76C: jal         0x80073220
    // 0x8005A770: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_8;
    // 0x8005A770: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_8:
    // 0x8005A774: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8005A778: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8005A77C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8005A780: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8005A784: lh          $v1, 0x5524($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X5524);
    // 0x8005A788: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005A78C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8005A790: addiu       $v0, $v0, 0x10A0
    ctx->r2 = ADD32(ctx->r2, 0X10A0);
    // 0x8005A794: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005A798: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005A79C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005A7A0: jal         0x800010CC
    // 0x8005A7A4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    func_800010CC(rdram, ctx);
        goto after_9;
    // 0x8005A7A4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_9:
L_8005A7A8:
    // 0x8005A7A8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005A7AC: lhu         $v0, -0x68E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X68E0);
    // 0x8005A7B0: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8005A7B4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005A7B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005A7BC: sh          $v1, -0x68E0($at)
    MEM_H(-0X68E0, ctx->r1) = ctx->r3;
    // 0x8005A7C0: bgez        $v0, L_8005A97C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005A7C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005A97C;
    }
    // 0x8005A7C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A7C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A7CC: sh          $v0, 0x570A($at)
    MEM_H(0X570A, ctx->r1) = ctx->r2;
    // 0x8005A7D0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8005A7D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A7D8: sh          $v0, 0x5A28($at)
    MEM_H(0X5A28, ctx->r1) = ctx->r2;
    // 0x8005A7DC: j           L_8005A97C
    // 0x8005A7E0: nop

        goto L_8005A97C;
    // 0x8005A7E0: nop

L_8005A7E4:
    // 0x8005A7E4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005A7E8: lh          $v1, -0x68E0($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X68E0);
    // 0x8005A7EC: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8005A7F0: bne         $v1, $v0, L_8005A930
    if (ctx->r3 != ctx->r2) {
        // 0x8005A7F4: addiu       $a0, $zero, 0x400
        ctx->r4 = ADD32(0, 0X400);
            goto L_8005A930;
    }
    // 0x8005A7F4: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x8005A7F8: jal         0x80024E5C
    // 0x8005A7FC: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    func_80024E5C(rdram, ctx);
        goto after_10;
    // 0x8005A7FC: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    after_10:
    // 0x8005A800: jal         0x80058DD8
    // 0x8005A804: nop

    func_80058DD8(rdram, ctx);
        goto after_11;
    // 0x8005A804: nop

    after_11:
    // 0x8005A808: j           L_8005A930
    // 0x8005A80C: nop

        goto L_8005A930;
    // 0x8005A80C: nop

L_8005A810:
    // 0x8005A810: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005A814: lh          $v1, -0x68E0($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X68E0);
    // 0x8005A818: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8005A81C: bne         $v1, $v0, L_8005A88C
    if (ctx->r3 != ctx->r2) {
        // 0x8005A820: addiu       $a1, $zero, 0xC8
        ctx->r5 = ADD32(0, 0XC8);
            goto L_8005A88C;
    }
    // 0x8005A820: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8005A824: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005A828: addiu       $a0, $a0, 0x4918
    ctx->r4 = ADD32(ctx->r4, 0X4918);
    // 0x8005A82C: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x8005A830: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8005A834: lh          $v0, 0x5524($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5524);
    // 0x8005A838: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005A83C: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8005A840: addiu       $s1, $s1, 0xF20
    ctx->r17 = ADD32(ctx->r17, 0XF20);
    // 0x8005A844: addiu       $s0, $zero, 0x400
    ctx->r16 = ADD32(0, 0X400);
    // 0x8005A848: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005A84C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005A850: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005A854: jal         0x800010CC
    // 0x8005A858: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_12;
    // 0x8005A858: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_12:
    // 0x8005A85C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005A860: addiu       $a0, $a0, 0x4930
    ctx->r4 = ADD32(ctx->r4, 0X4930);
    // 0x8005A864: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8005A868: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8005A86C: lh          $v0, 0x5524($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5524);
    // 0x8005A870: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8005A874: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005A878: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005A87C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005A880: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005A884: jal         0x800010CC
    // 0x8005A888: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_13;
    // 0x8005A888: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_13:
L_8005A88C:
    // 0x8005A88C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005A890: lhu         $v0, -0x68E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X68E0);
    // 0x8005A894: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8005A898: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005A89C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005A8A0: sh          $v1, -0x68E0($at)
    MEM_H(-0X68E0, ctx->r1) = ctx->r3;
    // 0x8005A8A4: bgez        $v0, L_8005A97C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005A8A8: addiu       $a0, $zero, 0x400
        ctx->r4 = ADD32(0, 0X400);
            goto L_8005A97C;
    }
    // 0x8005A8A8: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x8005A8AC: j           L_8005A960
    // 0x8005A8B0: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
        goto L_8005A960;
    // 0x8005A8B0: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
L_8005A8B4:
    // 0x8005A8B4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005A8B8: lh          $v1, -0x68E0($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X68E0);
    // 0x8005A8BC: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8005A8C0: bne         $v1, $v0, L_8005A930
    if (ctx->r3 != ctx->r2) {
        // 0x8005A8C4: addiu       $a1, $zero, 0xC8
        ctx->r5 = ADD32(0, 0XC8);
            goto L_8005A930;
    }
    // 0x8005A8C4: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8005A8C8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005A8CC: addiu       $a0, $a0, 0x4650
    ctx->r4 = ADD32(ctx->r4, 0X4650);
    // 0x8005A8D0: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x8005A8D4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8005A8D8: lh          $v0, 0x5524($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5524);
    // 0x8005A8DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005A8E0: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8005A8E4: addiu       $s1, $s1, 0xF20
    ctx->r17 = ADD32(ctx->r17, 0XF20);
    // 0x8005A8E8: addiu       $s0, $zero, 0x400
    ctx->r16 = ADD32(0, 0X400);
    // 0x8005A8EC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005A8F0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005A8F4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005A8F8: jal         0x800010CC
    // 0x8005A8FC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_14;
    // 0x8005A8FC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_14:
    // 0x8005A900: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005A904: addiu       $a0, $a0, 0x4668
    ctx->r4 = ADD32(ctx->r4, 0X4668);
    // 0x8005A908: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8005A90C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8005A910: lh          $v0, 0x5524($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5524);
    // 0x8005A914: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8005A918: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005A91C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005A920: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005A924: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005A928: jal         0x800010CC
    // 0x8005A92C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_15;
    // 0x8005A92C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_15:
L_8005A930:
    // 0x8005A930: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005A934: lhu         $v0, -0x68E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X68E0);
    // 0x8005A938: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8005A93C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005A940: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005A944: sh          $v1, -0x68E0($at)
    MEM_H(-0X68E0, ctx->r1) = ctx->r3;
    // 0x8005A948: bgez        $v0, L_8005A97C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005A94C: addiu       $a0, $zero, 0x400
        ctx->r4 = ADD32(0, 0X400);
            goto L_8005A97C;
    }
    // 0x8005A94C: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x8005A950: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    // 0x8005A954: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005A958: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A95C: sh          $v0, 0x5708($at)
    MEM_H(0X5708, ctx->r1) = ctx->r2;
L_8005A960:
    // 0x8005A960: jal         0x80024E5C
    // 0x8005A964: nop

    func_80024E5C(rdram, ctx);
        goto after_16;
    // 0x8005A964: nop

    after_16:
    // 0x8005A968: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005A96C: lhu         $v0, 0x4E66($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E66);
    // 0x8005A970: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8005A974: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A978: sh          $v0, 0x4E66($at)
    MEM_H(0X4E66, ctx->r1) = ctx->r2;
L_8005A97C:
    // 0x8005A97C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8005A980: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8005A984: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8005A988: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8005A98C: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8005A990: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8005A994: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8005A998: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8005A99C: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8005A9A0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8005A9A4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8005A9A8: jr          $ra
    // 0x8005A9AC: nop

    return;
    // 0x8005A9AC: nop

;}
RECOMP_FUNC void func_8005A9B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A9B0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005A9B4: lhu         $v0, 0x4E66($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E66);
    // 0x8005A9B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005A9BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A9C0: sh          $v0, 0x4E66($at)
    MEM_H(0X4E66, ctx->r1) = ctx->r2;
    // 0x8005A9C4: jr          $ra
    // 0x8005A9C8: nop

    return;
    // 0x8005A9C8: nop

;}
RECOMP_FUNC void func_8005A9CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A9CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005A9D0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8005A9D4: lui         $s2, 0x98
    ctx->r18 = S32(0X98 << 16);
    // 0x8005A9D8: ori         $s2, $s2, 0x9680
    ctx->r18 = ctx->r18 | 0X9680;
    // 0x8005A9DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005A9E0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005A9E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005A9E8: jal         0x8005D558
    // 0x8005A9EC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_8005D558(rdram, ctx);
        goto after_0;
    // 0x8005A9EC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x8005A9F0: bne         $v0, $zero, L_8005ABC0
    if (ctx->r2 != 0) {
        // 0x8005A9F4: nop
    
            goto L_8005ABC0;
    }
    // 0x8005A9F4: nop

    // 0x8005A9F8: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8005A9FC: addiu       $s1, $s1, 0x5718
    ctx->r17 = ADD32(ctx->r17, 0X5718);
    // 0x8005AA00: jal         0x8005D5A0
    // 0x8005AA04: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005D5A0(rdram, ctx);
        goto after_1;
    // 0x8005AA04: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8005AA08: beq         $v0, $zero, L_8005AA20
    if (ctx->r2 == 0) {
        // 0x8005AA0C: addiu       $a3, $zero, -0x1
        ctx->r7 = ADD32(0, -0X1);
            goto L_8005AA20;
    }
    // 0x8005AA0C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8005AA10: jal         0x8005DA28
    // 0x8005AA14: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005DA28(rdram, ctx);
        goto after_2;
    // 0x8005AA14: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8005AA18: j           L_8005ABC0
    // 0x8005AA1C: nop

        goto L_8005ABC0;
    // 0x8005AA1C: nop

L_8005AA20:
    // 0x8005AA20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005AA24: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8005AA28: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
L_8005AA2C:
    // 0x8005AA2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005AA30: bnel        $v0, $zero, L_8005AA64
    if (ctx->r2 != 0) {
        // 0x8005AA34: addiu       $a2, $a2, 0x70
        ctx->r6 = ADD32(ctx->r6, 0X70);
            goto L_8005AA64;
    }
    goto skip_0;
    // 0x8005AA34: addiu       $a2, $a2, 0x70
    ctx->r6 = ADD32(ctx->r6, 0X70);
    skip_0:
    // 0x8005AA38: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005AA3C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8005AA40: lh          $v1, 0x5758($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X5758);
    // 0x8005AA44: slt         $v0, $a3, $v1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005AA48: beq         $v0, $zero, L_8005AA60
    if (ctx->r2 == 0) {
        // 0x8005AA4C: slt         $v0, $v1, $s2
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_8005AA60;
    }
    // 0x8005AA4C: slt         $v0, $v1, $s2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8005AA50: beql        $v0, $zero, L_8005AA64
    if (ctx->r2 == 0) {
        // 0x8005AA54: addiu       $a2, $a2, 0x70
        ctx->r6 = ADD32(ctx->r6, 0X70);
            goto L_8005AA64;
    }
    goto skip_1;
    // 0x8005AA54: addiu       $a2, $a2, 0x70
    ctx->r6 = ADD32(ctx->r6, 0X70);
    skip_1:
    // 0x8005AA58: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8005AA5C: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
L_8005AA60:
    // 0x8005AA60: addiu       $a2, $a2, 0x70
    ctx->r6 = ADD32(ctx->r6, 0X70);
L_8005AA64:
    // 0x8005AA64: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8005AA68: slti        $v0, $a1, 0x6
    ctx->r2 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x8005AA6C: bne         $v0, $zero, L_8005AA2C
    if (ctx->r2 != 0) {
        // 0x8005AA70: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8005AA2C;
    }
    // 0x8005AA70: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8005AA74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005AA78: beq         $a3, $v0, L_8005ABC0
    if (ctx->r7 == ctx->r2) {
        // 0x8005AA7C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8005ABC0;
    }
    // 0x8005AA7C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005AA80: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8005AA84: addiu       $a1, $a1, -0x3074
    ctx->r5 = ADD32(ctx->r5, -0X3074);
    // 0x8005AA88: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8005AA8C: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x8005AA90: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8005AA94: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005AA98: addiu       $v1, $v1, 0x57AE
    ctx->r3 = ADD32(ctx->r3, 0X57AE);
    // 0x8005AA9C: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
L_8005AAA0:
    // 0x8005AAA0: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8005AAA4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8005AAA8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005AAAC: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8005AAB0: slti        $v0, $a0, 0x7
    ctx->r2 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x8005AAB4: bne         $v0, $zero, L_8005AAA0
    if (ctx->r2 != 0) {
        // 0x8005AAB8: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_8005AAA0;
    }
    // 0x8005AAB8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8005AABC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005AAC0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8005AAC4: addiu       $a1, $a1, 0x4DF8
    ctx->r5 = ADD32(ctx->r5, 0X4DF8);
    // 0x8005AAC8: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8005AACC: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x8005AAD0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8005AAD4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005AAD8: addiu       $v1, $v1, 0x579C
    ctx->r3 = ADD32(ctx->r3, 0X579C);
    // 0x8005AADC: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
L_8005AAE0:
    // 0x8005AAE0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8005AAE4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005AAE8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005AAEC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8005AAF0: slti        $v0, $a0, 0x3
    ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8005AAF4: bne         $v0, $zero, L_8005AAE0
    if (ctx->r2 != 0) {
        // 0x8005AAF8: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8005AAE0;
    }
    // 0x8005AAF8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8005AAFC: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8005AB00: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x8005AB04: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8005AB08: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8005AB0C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8005AB10: lhu         $a1, 0x5796($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X5796);
    // 0x8005AB14: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005AB18: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005AB1C: lhu         $v1, 0x5798($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X5798);
    // 0x8005AB20: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8005AB24: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8005AB28: lhu         $a2, 0x579A($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X579A);
    // 0x8005AB2C: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x8005AB30: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8005AB34: lhu         $a3, 0x57BE($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X57BE);
    // 0x8005AB38: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8005AB3C: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x8005AB40: lhu         $t0, 0x57C0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X57C0);
    // 0x8005AB44: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8005AB48: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x8005AB4C: lhu         $t1, 0x57C2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X57C2);
    // 0x8005AB50: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8005AB54: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x8005AB58: lhu         $t2, 0x57C4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X57C4);
    // 0x8005AB5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005AB60: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005AB64: lhu         $v0, 0x57C6($at)
    ctx->r2 = MEM_HU(ctx->r1, 0X57C6);
    // 0x8005AB68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005AB6C: sh          $a1, -0x5634($at)
    MEM_H(-0X5634, ctx->r1) = ctx->r5;
    // 0x8005AB70: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8005AB74: sh          $v1, 0x416A($at)
    MEM_H(0X416A, ctx->r1) = ctx->r3;
    // 0x8005AB78: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005AB7C: sh          $a2, 0x13E6($at)
    MEM_H(0X13E6, ctx->r1) = ctx->r6;
    // 0x8005AB80: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005AB84: sh          $a3, 0x13E8($at)
    MEM_H(0X13E8, ctx->r1) = ctx->r7;
    // 0x8005AB88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005AB8C: sh          $t0, -0x1D3C($at)
    MEM_H(-0X1D3C, ctx->r1) = ctx->r8;
    // 0x8005AB90: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005AB94: sh          $t1, 0x13E2($at)
    MEM_H(0X13E2, ctx->r1) = ctx->r9;
    // 0x8005AB98: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005AB9C: sh          $t2, 0x13E4($at)
    MEM_H(0X13E4, ctx->r1) = ctx->r10;
    // 0x8005ABA0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005ABA4: sh          $v0, 0x13EA($at)
    MEM_H(0X13EA, ctx->r1) = ctx->r2;
    // 0x8005ABA8: jal         0x8001F0B8
    // 0x8005ABAC: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    func_8001F0B8(rdram, ctx);
        goto after_3;
    // 0x8005ABAC: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    after_3:
    // 0x8005ABB0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005ABB4: lbu         $a0, -0x5633($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X5633);
    // 0x8005ABB8: jal         0x8001F098
    // 0x8005ABBC: nop

    func_8001F098(rdram, ctx);
        goto after_4;
    // 0x8005ABBC: nop

    after_4:
L_8005ABC0:
    // 0x8005ABC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005ABC4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8005ABC8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005ABCC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005ABD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005ABD4: jr          $ra
    // 0x8005ABD8: nop

    return;
    // 0x8005ABD8: nop

;}
RECOMP_FUNC void func_8005ABDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005ABDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005ABE0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005ABE4: addiu       $a0, $a0, 0x4C98
    ctx->r4 = ADD32(ctx->r4, 0X4C98);
    // 0x8005ABE8: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8005ABEC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8005ABF0: lh          $v0, 0x5524($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5524);
    // 0x8005ABF4: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x8005ABF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005ABFC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005AC00: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8005AC04: addiu       $s1, $s1, 0xF20
    ctx->r17 = ADD32(ctx->r17, 0XF20);
    // 0x8005AC08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005AC0C: addiu       $s0, $zero, 0x400
    ctx->r16 = ADD32(0, 0X400);
    // 0x8005AC10: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8005AC14: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005AC18: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005AC1C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005AC20: jal         0x800010CC
    // 0x8005AC24: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_0;
    // 0x8005AC24: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x8005AC28: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005AC2C: addiu       $a0, $a0, 0x4CAC
    ctx->r4 = ADD32(ctx->r4, 0X4CAC);
    // 0x8005AC30: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8005AC34: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8005AC38: lh          $v0, 0x5524($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5524);
    // 0x8005AC3C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8005AC40: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005AC44: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005AC48: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005AC4C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005AC50: jal         0x800010CC
    // 0x8005AC54: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_1;
    // 0x8005AC54: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x8005AC58: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8005AC5C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005AC60: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005AC64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8005AC68: jr          $ra
    // 0x8005AC6C: nop

    return;
    // 0x8005AC6C: nop

;}
RECOMP_FUNC void func_8005AC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AC70: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8005AC74: sltiu       $v0, $a0, 0xB
    ctx->r2 = ctx->r4 < 0XB ? 1 : 0;
    // 0x8005AC78: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8005AC7C: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // 0x8005AC80: beq         $v0, $zero, L_8005B214
    if (ctx->r2 == 0) {
        // 0x8005AC84: sw          $zero, 0x60($sp)
        MEM_W(0X60, ctx->r29) = 0;
            goto L_8005B214;
    }
    // 0x8005AC84: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x8005AC88: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8005AC8C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005AC90: addu        $at, $at, $v0
    gpr jr_addend_8005AC98 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005AC94: lw          $v0, 0x4CB8($at)
    ctx->r2 = ADD32(ctx->r1, 0X4CB8);
    // 0x8005AC98: jr          $v0
    // 0x8005AC9C: nop

    switch (jr_addend_8005AC98 >> 2) {
        case 0: goto L_8005ACA0; break;
        case 1: goto L_8005AD44; break;
        case 2: goto L_8005ADB4; break;
        case 3: goto L_8005AF58; break;
        case 4: goto L_8005B004; break;
        case 5: goto L_8005B214; break;
        case 6: goto L_8005B214; break;
        case 7: goto L_8005B214; break;
        case 8: goto L_8005B214; break;
        case 9: goto L_8005B214; break;
        case 10: goto L_8005B1A8; break;
        default: switch_error(__func__, 0x8005AC98, 0x80094CB8);
    }
    // 0x8005AC9C: nop

L_8005ACA0:
    // 0x8005ACA0: addiu       $v0, $zero, 0x676
    ctx->r2 = ADD32(0, 0X676);
    // 0x8005ACA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005ACA8: sh          $v0, 0x3EE0($at)
    MEM_H(0X3EE0, ctx->r1) = ctx->r2;
    // 0x8005ACAC: addiu       $v0, $zero, 0x677
    ctx->r2 = ADD32(0, 0X677);
    // 0x8005ACB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005ACB4: sh          $v0, 0x4AAC($at)
    MEM_H(0X4AAC, ctx->r1) = ctx->r2;
    // 0x8005ACB8: addiu       $v0, $zero, 0x679
    ctx->r2 = ADD32(0, 0X679);
    // 0x8005ACBC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8005ACC0: sh          $v0, 0x5524($at)
    MEM_H(0X5524, ctx->r1) = ctx->r2;
    // 0x8005ACC4: jal         0x8005D558
    // 0x8005ACC8: nop

    func_8005D558(rdram, ctx);
        goto after_0;
    // 0x8005ACC8: nop

    after_0:
    // 0x8005ACCC: bne         $v0, $zero, L_8005B218
    if (ctx->r2 != 0) {
        // 0x8005ACD0: addiu       $v0, $zero, 0x64
        ctx->r2 = ADD32(0, 0X64);
            goto L_8005B218;
    }
    // 0x8005ACD0: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x8005ACD4: jal         0x8005D8DC
    // 0x8005ACD8: nop

    func_8005D8DC(rdram, ctx);
        goto after_1;
    // 0x8005ACD8: nop

    after_1:
    // 0x8005ACDC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005ACE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005ACE4: beq         $v1, $v0, L_8005B214
    if (ctx->r3 == ctx->r2) {
        // 0x8005ACE8: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8005B214;
    }
    // 0x8005ACE8: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8005ACEC: beql        $v0, $zero, L_8005AD04
    if (ctx->r2 == 0) {
        // 0x8005ACF0: slti        $v0, $v1, 0x5
        ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
            goto L_8005AD04;
    }
    goto skip_0;
    // 0x8005ACF0: slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    skip_0:
    // 0x8005ACF4: beq         $v1, $zero, L_8005B1E0
    if (ctx->r3 == 0) {
        // 0x8005ACF8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8005B1E0;
    }
    // 0x8005ACF8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005ACFC: j           L_8005AD44
    // 0x8005AD00: nop

        goto L_8005AD44;
    // 0x8005AD00: nop

L_8005AD04:
    // 0x8005AD04: beq         $v0, $zero, L_8005AD44
    if (ctx->r2 == 0) {
        // 0x8005AD08: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_8005AD44;
    }
    // 0x8005AD08: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8005AD0C: bne         $v0, $zero, L_8005AD44
    if (ctx->r2 != 0) {
        // 0x8005AD10: addiu       $a0, $zero, 0x400
        ctx->r4 = ADD32(0, 0X400);
            goto L_8005AD44;
    }
    // 0x8005AD10: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x8005AD14: jal         0x80024E5C
    // 0x8005AD18: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    func_80024E5C(rdram, ctx);
        goto after_2;
    // 0x8005AD18: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    after_2:
    // 0x8005AD1C: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x8005AD20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005AD24: sh          $v1, 0x5A28($at)
    MEM_H(0X5A28, ctx->r1) = ctx->r3;
    // 0x8005AD28: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
    // 0x8005AD2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005AD30: sh          $zero, 0x4E22($at)
    MEM_H(0X4E22, ctx->r1) = 0;
    // 0x8005AD34: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005AD38: sh          $v1, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r3;
    // 0x8005AD3C: j           L_8005B218
    // 0x8005AD40: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_8005B218;
    // 0x8005AD40: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8005AD44:
    // 0x8005AD44: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005AD48: addiu       $a0, $a0, 0x40E0
    ctx->r4 = ADD32(ctx->r4, 0X40E0);
    // 0x8005AD4C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8005AD50: addiu       $s0, $s0, -0x5858
    ctx->r16 = ADD32(ctx->r16, -0X5858);
    // 0x8005AD54: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005AD58: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8005AD5C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8005AD60: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005AD64: sh          $v0, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r2;
    // 0x8005AD68: jal         0x8005C27C
    // 0x8005AD6C: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    func_8005C27C(rdram, ctx);
        goto after_3;
    // 0x8005AD6C: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    after_3:
    // 0x8005AD70: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8005AD74: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005AD78: jal         0x8005B22C
    // 0x8005AD7C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_8005B22C(rdram, ctx);
        goto after_4;
    // 0x8005AD7C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_4:
    // 0x8005AD80: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005AD84: addiu       $a0, $a0, -0x6A8C
    ctx->r4 = ADD32(ctx->r4, -0X6A8C);
    // 0x8005AD88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005AD8C: sh          $v0, 0x46E2($at)
    MEM_H(0X46E2, ctx->r1) = ctx->r2;
    // 0x8005AD90: jal         0x80000760
    // 0x8005AD94: nop

    func_80000760(rdram, ctx);
        goto after_5;
    // 0x8005AD94: nop

    after_5:
    // 0x8005AD98: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8005AD9C: lh          $a2, 0x46E2($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X46E2);
    // 0x8005ADA0: addiu       $a0, $zero, 0x6AC
    ctx->r4 = ADD32(0, 0X6AC);
    // 0x8005ADA4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8005ADA8: sh          $zero, -0x3078($at)
    MEM_H(-0X3078, ctx->r1) = 0;
    // 0x8005ADAC: j           L_8005AF48
    // 0x8005ADB0: addiu       $a1, $zero, 0x6AD
    ctx->r5 = ADD32(0, 0X6AD);
        goto L_8005AF48;
    // 0x8005ADB0: addiu       $a1, $zero, 0x6AD
    ctx->r5 = ADD32(0, 0X6AD);
L_8005ADB4:
    // 0x8005ADB4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005ADB8: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x8005ADBC: beq         $v0, $zero, L_8005ADD0
    if (ctx->r2 == 0) {
        // 0x8005ADC0: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8005ADD0;
    }
    // 0x8005ADC0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005ADC4: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8005ADC8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005ADCC: sh          $v0, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r2;
L_8005ADD0:
    // 0x8005ADD0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8005ADD4: lw          $a0, 0x4720($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4720);
    // 0x8005ADD8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005ADDC: lw          $v1, -0x68F0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X68F0);
    // 0x8005ADE0: lui         $v0, 0x3FFF
    ctx->r2 = S32(0X3FFF << 16);
    // 0x8005ADE4: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x8005ADE8: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8005ADEC: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x8005ADF0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8005ADF4: sw          $a0, 0x2588($at)
    MEM_W(0X2588, ctx->r1) = ctx->r4;
    // 0x8005ADF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005ADFC: sw          $v0, 0x4720($at)
    MEM_W(0X4720, ctx->r1) = ctx->r2;
    // 0x8005AE00: beq         $v1, $zero, L_8005AE50
    if (ctx->r3 == 0) {
        // 0x8005AE04: nop
    
            goto L_8005AE50;
    }
    // 0x8005AE04: nop

    // 0x8005AE08: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005AE0C: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x8005AE10: bne         $v0, $zero, L_8005AE50
    if (ctx->r2 != 0) {
        // 0x8005AE14: nop
    
            goto L_8005AE50;
    }
    // 0x8005AE14: nop

    // 0x8005AE18: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8005AE1C: lhu         $v0, -0x3078($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3078);
    // 0x8005AE20: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8005AE24: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8005AE28: sh          $v0, -0x3078($at)
    MEM_H(-0X3078, ctx->r1) = ctx->r2;
    // 0x8005AE2C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005AE30: bgez        $v0, L_8005AEAC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005AE34: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_8005AEAC;
    }
    // 0x8005AE34: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8005AE38: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005AE3C: lhu         $v0, 0x46E2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X46E2);
    // 0x8005AE40: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8005AE44: sh          $v0, -0x3078($at)
    MEM_H(-0X3078, ctx->r1) = ctx->r2;
    // 0x8005AE48: j           L_8005AEAC
    // 0x8005AE4C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_8005AEAC;
    // 0x8005AE4C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_8005AE50:
    // 0x8005AE50: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005AE54: lw          $v0, 0x4720($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4720);
    // 0x8005AE58: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8005AE5C: beq         $v0, $zero, L_8005AEC4
    if (ctx->r2 == 0) {
        // 0x8005AE60: nop
    
            goto L_8005AEC4;
    }
    // 0x8005AE60: nop

    // 0x8005AE64: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005AE68: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x8005AE6C: bne         $v0, $zero, L_8005AEC4
    if (ctx->r2 != 0) {
        // 0x8005AE70: nop
    
            goto L_8005AEC4;
    }
    // 0x8005AE70: nop

    // 0x8005AE74: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8005AE78: lhu         $v0, -0x3078($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3078);
    // 0x8005AE7C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005AE80: lh          $v1, 0x46E2($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46E2);
    // 0x8005AE84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005AE88: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8005AE8C: sh          $v0, -0x3078($at)
    MEM_H(-0X3078, ctx->r1) = ctx->r2;
    // 0x8005AE90: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005AE94: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005AE98: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005AE9C: beq         $v1, $zero, L_8005AEAC
    if (ctx->r3 == 0) {
        // 0x8005AEA0: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_8005AEAC;
    }
    // 0x8005AEA0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8005AEA4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8005AEA8: sh          $zero, -0x3078($at)
    MEM_H(-0X3078, ctx->r1) = 0;
L_8005AEAC:
    // 0x8005AEAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005AEB0: sh          $v0, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r2;
    // 0x8005AEB4: jal         0x8004C79C
    // 0x8005AEB8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_8004C79C(rdram, ctx);
        goto after_6;
    // 0x8005AEB8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_6:
    // 0x8005AEBC: j           L_8005AF38
    // 0x8005AEC0: nop

        goto L_8005AF38;
    // 0x8005AEC0: nop

L_8005AEC4:
    // 0x8005AEC4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005AEC8: lw          $v0, 0x4720($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4720);
    // 0x8005AECC: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8005AED0: beq         $v0, $zero, L_8005AF38
    if (ctx->r2 == 0) {
        // 0x8005AED4: nop
    
            goto L_8005AF38;
    }
    // 0x8005AED4: nop

    // 0x8005AED8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005AEDC: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x8005AEE0: bne         $v0, $zero, L_8005AF38
    if (ctx->r2 != 0) {
        // 0x8005AEE4: nop
    
            goto L_8005AF38;
    }
    // 0x8005AEE4: nop

    // 0x8005AEE8: jal         0x8004C79C
    // 0x8005AEEC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_8004C79C(rdram, ctx);
        goto after_7;
    // 0x8005AEEC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_7:
    // 0x8005AEF0: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8005AEF4: lh          $a0, -0x3078($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X3078);
    // 0x8005AEF8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005AEFC: lh          $v1, 0x46E2($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46E2);
    // 0x8005AF00: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8005AF04: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005AF08: sh          $v0, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r2;
    // 0x8005AF0C: bne         $a0, $v1, L_8005AF28
    if (ctx->r4 != ctx->r3) {
        // 0x8005AF10: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005AF28;
    }
    // 0x8005AF10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005AF14: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
L_8005AF18:
    // 0x8005AF18: jal         0x80024E5C
    // 0x8005AF1C: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    func_80024E5C(rdram, ctx);
        goto after_8;
    // 0x8005AF1C: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    after_8:
    // 0x8005AF20: j           L_8005B218
    // 0x8005AF24: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
        goto L_8005B218;
    // 0x8005AF24: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_8005AF28:
    // 0x8005AF28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AF2C: sh          $v0, 0x8E($at)
    MEM_H(0X8E, ctx->r1) = ctx->r2;
    // 0x8005AF30: j           L_8005B218
    // 0x8005AF34: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8005B218;
    // 0x8005AF34: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8005AF38:
    // 0x8005AF38: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8005AF3C: lh          $a2, 0x46E2($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X46E2);
    // 0x8005AF40: addiu       $a0, $zero, 0x6AC
    ctx->r4 = ADD32(0, 0X6AC);
    // 0x8005AF44: addiu       $a1, $zero, 0x6AD
    ctx->r5 = ADD32(0, 0X6AD);
L_8005AF48:
    // 0x8005AF48: jal         0x800550BC
    // 0x8005AF4C: nop

    func_800550BC(rdram, ctx);
        goto after_9;
    // 0x8005AF4C: nop

    after_9:
    // 0x8005AF50: j           L_8005B218
    // 0x8005AF54: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8005B218;
    // 0x8005AF54: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8005AF58:
    // 0x8005AF58: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005AF5C: addiu       $a0, $a0, 0x48A8
    ctx->r4 = ADD32(ctx->r4, 0X48A8);
    // 0x8005AF60: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x8005AF64: addiu       $a2, $zero, 0xC3
    ctx->r6 = ADD32(0, 0XC3);
    // 0x8005AF68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005AF6C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8005AF70: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005AF74: sh          $v0, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r2;
    // 0x8005AF78: addiu       $v0, $zero, 0x6AE
    ctx->r2 = ADD32(0, 0X6AE);
    // 0x8005AF7C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8005AF80: addiu       $s0, $s0, 0x1220
    ctx->r16 = ADD32(ctx->r16, 0X1220);
    // 0x8005AF84: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005AF88: addiu       $v0, $zero, 0x414
    ctx->r2 = ADD32(0, 0X414);
    // 0x8005AF8C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005AF90: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005AF94: jal         0x800010CC
    // 0x8005AF98: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_10;
    // 0x8005AF98: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_10:
    // 0x8005AF9C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005AFA0: addiu       $a0, $a0, 0x48B8
    ctx->r4 = ADD32(ctx->r4, 0X48B8);
    // 0x8005AFA4: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x8005AFA8: addiu       $a2, $zero, 0xCD
    ctx->r6 = ADD32(0, 0XCD);
    // 0x8005AFAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005AFB0: addiu       $v0, $zero, 0x6AD
    ctx->r2 = ADD32(0, 0X6AD);
    // 0x8005AFB4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005AFB8: addiu       $v0, $zero, 0x415
    ctx->r2 = ADD32(0, 0X415);
    // 0x8005AFBC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005AFC0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005AFC4: jal         0x800010CC
    // 0x8005AFC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_11;
    // 0x8005AFC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_11:
    // 0x8005AFCC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005AFD0: addiu       $a0, $a0, 0x48BC
    ctx->r4 = ADD32(ctx->r4, 0X48BC);
    // 0x8005AFD4: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x8005AFD8: addiu       $a2, $zero, 0xD7
    ctx->r6 = ADD32(0, 0XD7);
    // 0x8005AFDC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005AFE0: addiu       $v0, $zero, 0x6AC
    ctx->r2 = ADD32(0, 0X6AC);
    // 0x8005AFE4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005AFE8: addiu       $v0, $zero, 0x416
    ctx->r2 = ADD32(0, 0X416);
    // 0x8005AFEC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005AFF0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005AFF4: jal         0x800010CC
    // 0x8005AFF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_12;
    // 0x8005AFF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_12:
    // 0x8005AFFC: j           L_8005B218
    // 0x8005B000: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8005B218;
    // 0x8005B000: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8005B004:
    // 0x8005B004: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005B008: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x8005B00C: beq         $v0, $zero, L_8005B020
    if (ctx->r2 == 0) {
        // 0x8005B010: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8005B020;
    }
    // 0x8005B010: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005B014: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8005B018: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005B01C: sh          $v0, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r2;
L_8005B020:
    // 0x8005B020: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8005B024: lw          $a0, 0x4720($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4720);
    // 0x8005B028: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005B02C: lw          $v1, -0x68F0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X68F0);
    // 0x8005B030: lui         $v0, 0x3FFF
    ctx->r2 = S32(0X3FFF << 16);
    // 0x8005B034: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x8005B038: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8005B03C: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x8005B040: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8005B044: sw          $a0, 0x2588($at)
    MEM_W(0X2588, ctx->r1) = ctx->r4;
    // 0x8005B048: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005B04C: sw          $v0, 0x4720($at)
    MEM_W(0X4720, ctx->r1) = ctx->r2;
    // 0x8005B050: beq         $v1, $zero, L_8005B068
    if (ctx->r3 == 0) {
        // 0x8005B054: nop
    
            goto L_8005B068;
    }
    // 0x8005B054: nop

    // 0x8005B058: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005B05C: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x8005B060: beq         $v0, $zero, L_8005B08C
    if (ctx->r2 == 0) {
        // 0x8005B064: nop
    
            goto L_8005B08C;
    }
    // 0x8005B064: nop

L_8005B068:
    // 0x8005B068: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005B06C: lw          $v0, 0x4720($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4720);
    // 0x8005B070: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8005B074: beq         $v0, $zero, L_8005B0BC
    if (ctx->r2 == 0) {
        // 0x8005B078: nop
    
            goto L_8005B0BC;
    }
    // 0x8005B078: nop

    // 0x8005B07C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005B080: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x8005B084: bne         $v0, $zero, L_8005B0BC
    if (ctx->r2 != 0) {
        // 0x8005B088: nop
    
            goto L_8005B0BC;
    }
    // 0x8005B088: nop

L_8005B08C:
    // 0x8005B08C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B090: lhu         $v1, 0x8E($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X8E);
    // 0x8005B094: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8005B098: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005B09C: sh          $v0, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r2;
    // 0x8005B0A0: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8005B0A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005B0A8: sh          $v1, 0x8E($at)
    MEM_H(0X8E, ctx->r1) = ctx->r3;
    // 0x8005B0AC: jal         0x8004C79C
    // 0x8005B0B0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_8004C79C(rdram, ctx);
        goto after_13;
    // 0x8005B0B0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_13:
    // 0x8005B0B4: j           L_8005B164
    // 0x8005B0B8: nop

        goto L_8005B164;
    // 0x8005B0B8: nop

L_8005B0BC:
    // 0x8005B0BC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005B0C0: lw          $v0, 0x4720($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4720);
    // 0x8005B0C4: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8005B0C8: beq         $v0, $zero, L_8005B164
    if (ctx->r2 == 0) {
        // 0x8005B0CC: nop
    
            goto L_8005B164;
    }
    // 0x8005B0CC: nop

    // 0x8005B0D0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005B0D4: lh          $v0, -0x672E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X672E);
    // 0x8005B0D8: bne         $v0, $zero, L_8005B164
    if (ctx->r2 != 0) {
        // 0x8005B0DC: nop
    
            goto L_8005B164;
    }
    // 0x8005B0DC: nop

    // 0x8005B0E0: jal         0x8004C79C
    // 0x8005B0E4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_8004C79C(rdram, ctx);
        goto after_14;
    // 0x8005B0E4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_14:
    // 0x8005B0E8: jal         0x800246DC
    // 0x8005B0EC: addiu       $a0, $zero, 0x414
    ctx->r4 = ADD32(0, 0X414);
    func_800246DC(rdram, ctx);
        goto after_15;
    // 0x8005B0EC: addiu       $a0, $zero, 0x414
    ctx->r4 = ADD32(0, 0X414);
    after_15:
    // 0x8005B0F0: jal         0x800246DC
    // 0x8005B0F4: addiu       $a0, $zero, 0x415
    ctx->r4 = ADD32(0, 0X415);
    func_800246DC(rdram, ctx);
        goto after_16;
    // 0x8005B0F4: addiu       $a0, $zero, 0x415
    ctx->r4 = ADD32(0, 0X415);
    after_16:
    // 0x8005B0F8: jal         0x800246DC
    // 0x8005B0FC: addiu       $a0, $zero, 0x416
    ctx->r4 = ADD32(0, 0X416);
    func_800246DC(rdram, ctx);
        goto after_17;
    // 0x8005B0FC: addiu       $a0, $zero, 0x416
    ctx->r4 = ADD32(0, 0X416);
    after_17:
    // 0x8005B100: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B104: lh          $v1, 0x8E($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X8E);
    // 0x8005B108: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8005B10C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005B110: sh          $v0, -0x672E($at)
    MEM_H(-0X672E, ctx->r1) = ctx->r2;
    // 0x8005B114: bnel        $v1, $zero, L_8005B218
    if (ctx->r3 != 0) {
        // 0x8005B118: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8005B218;
    }
    goto skip_1;
    // 0x8005B118: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_1:
    // 0x8005B11C: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x8005B120: jal         0x80024E5C
    // 0x8005B124: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    func_80024E5C(rdram, ctx);
        goto after_18;
    // 0x8005B124: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    after_18:
    // 0x8005B128: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8005B12C: lh          $v0, -0x3078($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X3078);
    // 0x8005B130: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005B134: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8005B138: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8005B13C: lw          $a1, -0x30D0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X30D0);
    // 0x8005B140: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005B144: addiu       $a0, $a0, 0x40E0
    ctx->r4 = ADD32(ctx->r4, 0X40E0);
    // 0x8005B148: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005B14C: addiu       $v0, $v0, -0x5858
    ctx->r2 = ADD32(ctx->r2, -0X5858);
    // 0x8005B150: sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5 << 5);
    // 0x8005B154: jal         0x8005C1CC
    // 0x8005B158: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    func_8005C1CC(rdram, ctx);
        goto after_19;
    // 0x8005B158: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    after_19:
    // 0x8005B15C: j           L_8005B1E0
    // 0x8005B160: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_8005B1E0;
    // 0x8005B160: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8005B164:
    // 0x8005B164: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B168: lh          $v0, 0x8E($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X8E);
    // 0x8005B16C: bne         $v0, $zero, L_8005B188
    if (ctx->r2 != 0) {
        // 0x8005B170: addiu       $a0, $zero, 0x415
        ctx->r4 = ADD32(0, 0X415);
            goto L_8005B188;
    }
    // 0x8005B170: addiu       $a0, $zero, 0x415
    ctx->r4 = ADD32(0, 0X415);
    // 0x8005B174: jal         0x8000163C
    // 0x8005B178: addiu       $a1, $zero, 0x6AC
    ctx->r5 = ADD32(0, 0X6AC);
    func_8000163C(rdram, ctx);
        goto after_20;
    // 0x8005B178: addiu       $a1, $zero, 0x6AC
    ctx->r5 = ADD32(0, 0X6AC);
    after_20:
    // 0x8005B17C: addiu       $a0, $zero, 0x416
    ctx->r4 = ADD32(0, 0X416);
    // 0x8005B180: j           L_8005B198
    // 0x8005B184: addiu       $a1, $zero, 0x6AD
    ctx->r5 = ADD32(0, 0X6AD);
        goto L_8005B198;
    // 0x8005B184: addiu       $a1, $zero, 0x6AD
    ctx->r5 = ADD32(0, 0X6AD);
L_8005B188:
    // 0x8005B188: jal         0x8000163C
    // 0x8005B18C: addiu       $a1, $zero, 0x6AD
    ctx->r5 = ADD32(0, 0X6AD);
    func_8000163C(rdram, ctx);
        goto after_21;
    // 0x8005B18C: addiu       $a1, $zero, 0x6AD
    ctx->r5 = ADD32(0, 0X6AD);
    after_21:
    // 0x8005B190: addiu       $a0, $zero, 0x416
    ctx->r4 = ADD32(0, 0X416);
    // 0x8005B194: addiu       $a1, $zero, 0x6AC
    ctx->r5 = ADD32(0, 0X6AC);
L_8005B198:
    // 0x8005B198: jal         0x8000163C
    // 0x8005B19C: nop

    func_8000163C(rdram, ctx);
        goto after_22;
    // 0x8005B19C: nop

    after_22:
    // 0x8005B1A0: j           L_8005B218
    // 0x8005B1A4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8005B218;
    // 0x8005B1A4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8005B1A8:
    // 0x8005B1A8: jal         0x80059394
    // 0x8005B1AC: nop

    func_80059394(rdram, ctx);
        goto after_23;
    // 0x8005B1AC: nop

    after_23:
    // 0x8005B1B0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005B1B4: lhu         $v1, 0x4E66($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X4E66);
    // 0x8005B1B8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8005B1BC: bnel        $v1, $v0, L_8005B1F0
    if (ctx->r3 != ctx->r2) {
        // 0x8005B1C0: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8005B1F0;
    }
    goto skip_2;
    // 0x8005B1C0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    skip_2:
    // 0x8005B1C4: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x8005B1C8: jal         0x80024E5C
    // 0x8005B1CC: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    func_80024E5C(rdram, ctx);
        goto after_24;
    // 0x8005B1CC: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    after_24:
    // 0x8005B1D0: addiu       $a0, $zero, 0x550
    ctx->r4 = ADD32(0, 0X550);
    // 0x8005B1D4: jal         0x80024E5C
    // 0x8005B1D8: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    func_80024E5C(rdram, ctx);
        goto after_25;
    // 0x8005B1D8: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    after_25:
    // 0x8005B1DC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8005B1E0:
    // 0x8005B1E0: jal         0x8005AC70
    // 0x8005B1E4: nop

    func_8005AC70(rdram, ctx);
        goto after_26;
    // 0x8005B1E4: nop

    after_26:
    // 0x8005B1E8: j           L_8005B218
    // 0x8005B1EC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
        goto L_8005B218;
    // 0x8005B1EC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_8005B1F0:
    // 0x8005B1F0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005B1F4: lh          $v1, 0x5A28($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X5A28);
    // 0x8005B1F8: bne         $v1, $v0, L_8005B218
    if (ctx->r3 != ctx->r2) {
        // 0x8005B1FC: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8005B218;
    }
    // 0x8005B1FC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8005B200: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x8005B204: jal         0x80024E5C
    // 0x8005B208: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    func_80024E5C(rdram, ctx);
        goto after_27;
    // 0x8005B208: addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    after_27:
    // 0x8005B20C: j           L_8005AF18
    // 0x8005B210: addiu       $a0, $zero, 0x550
    ctx->r4 = ADD32(0, 0X550);
        goto L_8005AF18;
    // 0x8005B210: addiu       $a0, $zero, 0x550
    ctx->r4 = ADD32(0, 0X550);
L_8005B214:
    // 0x8005B214: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_8005B218:
    // 0x8005B218: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8005B21C: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x8005B220: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8005B224: jr          $ra
    // 0x8005B228: nop

    return;
    // 0x8005B228: nop

;}
RECOMP_FUNC void func_8005B22C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B22C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8005B230: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8005B234: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8005B238: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8005B23C: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8005B240: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8005B244: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x8005B248: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005B24C: addiu       $a0, $a0, 0x4CE4
    ctx->r4 = ADD32(ctx->r4, 0X4CE4);
    // 0x8005B250: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8005B254: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x8005B258: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x8005B25C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005B260: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8005B264: addiu       $s2, $zero, 0x6AE
    ctx->r18 = ADD32(0, 0X6AE);
    // 0x8005B268: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8005B26C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8005B270: addiu       $s0, $s0, 0x1220
    ctx->r16 = ADD32(ctx->r16, 0X1220);
    // 0x8005B274: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005B278: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8005B27C: addiu       $s1, $zero, 0x400
    ctx->r17 = ADD32(0, 0X400);
    // 0x8005B280: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8005B284: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8005B288: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8005B28C: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8005B290: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8005B294: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005B298: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8005B29C: jal         0x800010CC
    // 0x8005B2A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    func_800010CC(rdram, ctx);
        goto after_0;
    // 0x8005B2A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x8005B2A4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005B2A8: addiu       $a0, $a0, 0x4CF0
    ctx->r4 = ADD32(ctx->r4, 0X4CF0);
    // 0x8005B2AC: addiu       $a1, $zero, 0x10E
    ctx->r5 = ADD32(0, 0X10E);
    // 0x8005B2B0: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x8005B2B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005B2B8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8005B2BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005B2C0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005B2C4: jal         0x800010CC
    // 0x8005B2C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    func_800010CC(rdram, ctx);
        goto after_1;
    // 0x8005B2C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_1:
    // 0x8005B2CC: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x8005B2D0: addu        $s7, $s0, $zero
    ctx->r23 = ADD32(ctx->r16, 0);
    // 0x8005B2D4: addiu       $s1, $zero, 0x23
    ctx->r17 = ADD32(0, 0X23);
    // 0x8005B2D8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8005B2DC: addu        $s6, $s4, $zero
    ctx->r22 = ADD32(ctx->r20, 0);
    // 0x8005B2E0: lui         $s4, 0x8019
    ctx->r20 = S32(0X8019 << 16);
    // 0x8005B2E4: addiu       $s4, $s4, -0x30D0
    ctx->r20 = ADD32(ctx->r20, -0X30D0);
L_8005B2E8:
    // 0x8005B2E8: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8005B2EC: bne         $v0, $zero, L_8005B3B8
    if (ctx->r2 != 0) {
        // 0x8005B2F0: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_8005B3B8;
    }
    // 0x8005B2F0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8005B2F4: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8005B2F8: addiu       $a1, $a1, 0x4CF8
    ctx->r5 = ADD32(ctx->r5, 0X4CF8);
    // 0x8005B2FC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8005B300: jal         0x80073220
    // 0x8005B304: sw          $s5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r21;
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_2;
    // 0x8005B304: sw          $s5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r21;
    after_2:
    // 0x8005B308: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8005B30C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8005B310: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8005B314: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005B318: addiu       $t1, $zero, 0x87
    ctx->r9 = ADD32(0, 0X87);
    // 0x8005B31C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8005B320: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005B324: addiu       $s0, $fp, 0x450
    ctx->r16 = ADD32(ctx->r30, 0X450);
    // 0x8005B328: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x8005B32C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8005B330: jal         0x800010CC
    // 0x8005B334: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_800010CC(rdram, ctx);
        goto after_3;
    // 0x8005B334: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_3:
    // 0x8005B338: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8005B33C: jal         0x8005B554
    // 0x8005B340: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_8005B554(rdram, ctx);
        goto after_4;
    // 0x8005B340: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_4:
    // 0x8005B344: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8005B348: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8005B34C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8005B350: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005B354: addiu       $t1, $zero, 0x87
    ctx->r9 = ADD32(0, 0X87);
    // 0x8005B358: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8005B35C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005B360: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x8005B364: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8005B368: jal         0x800010CC
    // 0x8005B36C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_800010CC(rdram, ctx);
        goto after_5;
    // 0x8005B36C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_5:
    // 0x8005B370: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8005B374: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8005B378: addiu       $a1, $a1, 0x4CFC
    ctx->r5 = ADD32(ctx->r5, 0X4CFC);
    // 0x8005B37C: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x8005B380: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8005B384: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8005B388: jal         0x80073220
    // 0x8005B38C: srl         $a2, $a2, 8
    ctx->r6 = S32(U32(ctx->r6) >> 8);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_6;
    // 0x8005B38C: srl         $a2, $a2, 8
    ctx->r6 = S32(U32(ctx->r6) >> 8);
    after_6:
    // 0x8005B390: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8005B394: addiu       $a1, $zero, 0x10E
    ctx->r5 = ADD32(0, 0X10E);
    // 0x8005B398: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8005B39C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005B3A0: addiu       $t1, $zero, 0x87
    ctx->r9 = ADD32(0, 0X87);
    // 0x8005B3A4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8005B3A8: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x8005B3AC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005B3B0: j           L_8005B3F4
    // 0x8005B3B4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
        goto L_8005B3F4;
    // 0x8005B3B4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
L_8005B3B8:
    // 0x8005B3B8: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8005B3BC: addiu       $a1, $a1, 0x4CF8
    ctx->r5 = ADD32(ctx->r5, 0X4CF8);
    // 0x8005B3C0: jal         0x80073220
    // 0x8005B3C4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_7;
    // 0x8005B3C4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_7:
    // 0x8005B3C8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8005B3CC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8005B3D0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8005B3D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005B3D8: addiu       $v0, $zero, 0x6AD
    ctx->r2 = ADD32(0, 0X6AD);
    // 0x8005B3DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005B3E0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005B3E4: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x8005B3E8: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x8005B3EC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8005B3F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_8005B3F4:
    // 0x8005B3F4: jal         0x800010CC
    // 0x8005B3F8: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    func_800010CC(rdram, ctx);
        goto after_8;
    // 0x8005B3F8: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    after_8:
    // 0x8005B3FC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8005B400: addiu       $s3, $s3, 0x20
    ctx->r19 = ADD32(ctx->r19, 0X20);
    // 0x8005B404: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8005B408: slti        $v0, $s5, 0x10
    ctx->r2 = SIGNED(ctx->r21) < 0X10 ? 1 : 0;
    // 0x8005B40C: bne         $v0, $zero, L_8005B2E8
    if (ctx->r2 != 0) {
        // 0x8005B410: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_8005B2E8;
    }
    // 0x8005B410: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8005B414: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B418: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8005B41C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8005B420: addiu       $a1, $a1, 0x4D00
    ctx->r5 = ADD32(ctx->r5, 0X4D00);
    // 0x8005B424: jal         0x80073220
    // 0x8005B428: sra         $a2, $t1, 8
    ctx->r6 = S32(SIGNED(ctx->r9) >> 8);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_9;
    // 0x8005B428: sra         $a2, $t1, 8
    ctx->r6 = S32(SIGNED(ctx->r9) >> 8);
    after_9:
    // 0x8005B42C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8005B430: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x8005B434: addiu       $a2, $zero, 0xD2
    ctx->r6 = ADD32(0, 0XD2);
    // 0x8005B438: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005B43C: addiu       $s2, $zero, 0x6AE
    ctx->r18 = ADD32(0, 0X6AE);
    // 0x8005B440: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8005B444: addiu       $s1, $s1, 0x1220
    ctx->r17 = ADD32(ctx->r17, 0X1220);
    // 0x8005B448: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005B44C: addiu       $s0, $zero, 0x400
    ctx->r16 = ADD32(0, 0X400);
    // 0x8005B450: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8005B454: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005B458: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8005B45C: jal         0x800010CC
    // 0x8005B460: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_800010CC(rdram, ctx);
        goto after_10;
    // 0x8005B460: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_10:
    // 0x8005B464: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005B468: addiu       $a0, $a0, 0x4D10
    ctx->r4 = ADD32(ctx->r4, 0X4D10);
    // 0x8005B46C: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x8005B470: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8005B474: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005B478: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8005B47C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005B480: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005B484: jal         0x800010CC
    // 0x8005B488: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_800010CC(rdram, ctx);
        goto after_11;
    // 0x8005B488: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_11:
    // 0x8005B48C: jal         0x800306EC
    // 0x8005B490: nop

    func_800306EC(rdram, ctx);
        goto after_12;
    // 0x8005B490: nop

    after_12:
    // 0x8005B494: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005B498: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x8005B49C: lhu         $v1, 0x6($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6);
    // 0x8005B4A0: lui         $a0, 0x4F00
    ctx->r4 = S32(0X4F00 << 16);
    // 0x8005B4A4: ori         $a0, $a0, 0x3E78
    ctx->r4 = ctx->r4 | 0X3E78;
    // 0x8005B4A8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8005B4AC: ori         $v1, $v1, 0x20
    ctx->r3 = ctx->r3 | 0X20;
    // 0x8005B4B0: jal         0x80023E44
    // 0x8005B4B4: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_13;
    // 0x8005B4B4: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    after_13:
    // 0x8005B4B8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005B4BC: addiu       $a0, $a0, 0x4D18
    ctx->r4 = ADD32(ctx->r4, 0X4D18);
    // 0x8005B4C0: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x8005B4C4: lw          $a3, 0x34($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X34);
    // 0x8005B4C8: addiu       $a2, $zero, 0x84
    ctx->r6 = ADD32(0, 0X84);
    // 0x8005B4CC: addiu       $v1, $zero, 0x400
    ctx->r3 = ADD32(0, 0X400);
    // 0x8005B4D0: sh          $v1, 0x70($v0)
    MEM_H(0X70, ctx->r2) = ctx->r3;
    // 0x8005B4D4: lhu         $t0, 0x6($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X6);
    // 0x8005B4D8: lui         $v1, 0x6E
    ctx->r3 = S32(0X6E << 16);
    // 0x8005B4DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005B4E0: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x8005B4E4: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8005B4E8: sra         $v1, $t0, 16
    ctx->r3 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8005B4EC: srl         $t0, $t0, 31
    ctx->r8 = S32(U32(ctx->r8) >> 31);
    // 0x8005B4F0: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8005B4F4: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8005B4F8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8005B4FC: lui         $t0, 0x154
    ctx->r8 = S32(0X154 << 16);
    // 0x8005B500: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x8005B504: sw          $t0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r8;
    // 0x8005B508: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8005B50C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005B510: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005B514: jal         0x800010CC
    // 0x8005B518: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_800010CC(rdram, ctx);
        goto after_14;
    // 0x8005B518: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_14:
    // 0x8005B51C: addu        $v0, $fp, $zero
    ctx->r2 = ADD32(ctx->r30, 0);
    // 0x8005B520: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8005B524: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8005B528: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8005B52C: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8005B530: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8005B534: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8005B538: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8005B53C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8005B540: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8005B544: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8005B548: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8005B54C: jr          $ra
    // 0x8005B550: nop

    return;
    // 0x8005B550: nop

;}
RECOMP_FUNC void func_8005B554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B554: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8005B558: addiu       $t1, $t1, 0x4D24
    ctx->r9 = ADD32(ctx->r9, 0X4D24);
    // 0x8005B55C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8005B560: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8005B564: addiu       $t2, $zero, 0x2A
    ctx->r10 = ADD32(0, 0X2A);
    // 0x8005B568: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8005B56C: addu        $v0, $a0, $t0
    ctx->r2 = ADD32(ctx->r4, ctx->r8);
L_8005B570:
    // 0x8005B570: lbu         $v0, 0xE($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XE);
    // 0x8005B574: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8005B578: beq         $v1, $zero, L_8005B5BC
    if (ctx->r3 == 0) {
        // 0x8005B57C: addiu       $v0, $v0, -0xF
        ctx->r2 = ADD32(ctx->r2, -0XF);
            goto L_8005B5BC;
    }
    // 0x8005B57C: addiu       $v0, $v0, -0xF
    ctx->r2 = ADD32(ctx->r2, -0XF);
    // 0x8005B580: sltiu       $v0, $v0, 0x33
    ctx->r2 = ctx->r2 < 0X33 ? 1 : 0;
    // 0x8005B584: bne         $v0, $zero, L_8005B59C
    if (ctx->r2 != 0) {
        // 0x8005B588: addu        $v0, $v1, $t1
        ctx->r2 = ADD32(ctx->r3, ctx->r9);
            goto L_8005B59C;
    }
    // 0x8005B588: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // 0x8005B58C: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x8005B590: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8005B594: j           L_8005B5AC
    // 0x8005B598: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
        goto L_8005B5AC;
    // 0x8005B598: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_8005B59C:
    // 0x8005B59C: lbu         $v0, -0xF($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XF);
    // 0x8005B5A0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8005B5A4: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8005B5A8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8005B5AC:
    // 0x8005B5AC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005B5B0: slti        $v0, $t0, 0x10
    ctx->r2 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x8005B5B4: bne         $v0, $zero, L_8005B570
    if (ctx->r2 != 0) {
        // 0x8005B5B8: addu        $v0, $a0, $t0
        ctx->r2 = ADD32(ctx->r4, ctx->r8);
            goto L_8005B570;
    }
    // 0x8005B5B8: addu        $v0, $a0, $t0
    ctx->r2 = ADD32(ctx->r4, ctx->r8);
L_8005B5BC:
    // 0x8005B5BC: lbu         $v0, 0xA($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA);
    // 0x8005B5C0: beq         $v0, $zero, L_8005B60C
    if (ctx->r2 == 0) {
        // 0x8005B5C4: addu        $v1, $a1, $a3
        ctx->r3 = ADD32(ctx->r5, ctx->r7);
            goto L_8005B60C;
    }
    // 0x8005B5C4: addu        $v1, $a1, $a3
    ctx->r3 = ADD32(ctx->r5, ctx->r7);
    // 0x8005B5C8: addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // 0x8005B5CC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8005B5D0: lbu         $a0, 0xA($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XA);
    // 0x8005B5D4: addiu       $v0, $a0, -0xF
    ctx->r2 = ADD32(ctx->r4, -0XF);
    // 0x8005B5D8: sltiu       $v0, $v0, 0x33
    ctx->r2 = ctx->r2 < 0X33 ? 1 : 0;
    // 0x8005B5DC: bne         $v0, $zero, L_8005B5F8
    if (ctx->r2 != 0) {
        // 0x8005B5E0: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_8005B5F8;
    }
    // 0x8005B5E0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8005B5E4: addu        $v1, $a1, $a3
    ctx->r3 = ADD32(ctx->r5, ctx->r7);
    // 0x8005B5E8: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x8005B5EC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8005B5F0: j           L_8005B60C
    // 0x8005B5F4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
        goto L_8005B60C;
    // 0x8005B5F4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_8005B5F8:
    // 0x8005B5F8: addu        $v0, $a0, $t1
    ctx->r2 = ADD32(ctx->r4, ctx->r9);
    // 0x8005B5FC: lbu         $v1, -0xF($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0XF);
    // 0x8005B600: addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // 0x8005B604: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8005B608: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8005B60C:
    // 0x8005B60C: addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // 0x8005B610: jr          $ra
    // 0x8005B614: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    return;
    // 0x8005B614: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8005B618: nop

    // 0x8005B61C: nop

;}
RECOMP_FUNC void func_8005BA80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BA80: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005BA84: addu        $t8, $a1, $zero
    ctx->r24 = ADD32(ctx->r5, 0);
    // 0x8005BA88: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8005BA8C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8005BA90: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8005BA94: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8005BA98: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8005BA9C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8005BAA0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005BAA4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005BAA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005BAAC: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x8005BAB0: addiu       $t8, $t8, 0x4
    ctx->r24 = ADD32(ctx->r24, 0X4);
    // 0x8005BAB4: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x8005BAB8: addiu       $t8, $t8, 0x4
    ctx->r24 = ADD32(ctx->r24, 0X4);
    // 0x8005BABC: addiu       $t6, $zero, 0x1A
    ctx->r14 = ADD32(0, 0X1A);
    // 0x8005BAC0: andi        $t0, $a2, 0xFFFF
    ctx->r8 = ctx->r6 & 0XFFFF;
    // 0x8005BAC4: addu        $t2, $t0, $zero
    ctx->r10 = ADD32(ctx->r8, 0);
    // 0x8005BAC8: lhu         $t1, 0x0($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X0);
    // 0x8005BACC: srl         $a1, $t5, 26
    ctx->r5 = S32(U32(ctx->r13) >> 26);
    // 0x8005BAD0: sll         $t5, $t5, 6
    ctx->r13 = S32(ctx->r13 << 6);
    // 0x8005BAD4: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x8005BAD8: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8005BADC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005BAE0: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8005BAE4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8005BAE8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005BAEC: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x8005BAF0: lhu         $a1, 0x2($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X2);
    // 0x8005BAF4: lhu         $t4, 0x4($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X4);
    // 0x8005BAF8: addiu       $s6, $v1, 0x6
    ctx->r22 = ADD32(ctx->r3, 0X6);
    // 0x8005BAFC: addiu       $s7, $v1, 0x28
    ctx->r23 = ADD32(ctx->r3, 0X28);
    // 0x8005BB00: addiu       $fp, $v1, 0x5C
    ctx->r30 = ADD32(ctx->r3, 0X5C);
    // 0x8005BB04: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8005BB08: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8005BB0C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005BB10: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8005BB14: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005BB18: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8005BB1C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8005BB20: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8005BB24: sw          $s7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r23;
    // 0x8005BB28: addiu       $s7, $v1, 0x20
    ctx->r23 = ADD32(ctx->r3, 0X20);
    // 0x8005BB2C: sw          $s7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r23;
    // 0x8005BB30: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x8005BB34: bgez        $t0, L_8005BB40
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005BB38: sw          $a0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r4;
            goto L_8005BB40;
    }
    // 0x8005BB38: sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // 0x8005BB3C: addiu       $t2, $t0, 0x3
    ctx->r10 = ADD32(ctx->r8, 0X3);
L_8005BB40:
    // 0x8005BB40: sra         $v0, $a2, 16
    ctx->r2 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8005BB44: div         $zero, $v0, $t1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r9)));
    // 0x8005BB48: bne         $t1, $zero, L_8005BB54
    if (ctx->r9 != 0) {
        // 0x8005BB4C: nop
    
            goto L_8005BB54;
    }
    // 0x8005BB4C: nop

    // 0x8005BB50: break       7
    do_break(2147859280);
L_8005BB54:
    // 0x8005BB54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BB58: bne         $t1, $at, L_8005BB6C
    if (ctx->r9 != ctx->r1) {
        // 0x8005BB5C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005BB6C;
    }
    // 0x8005BB5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005BB60: bne         $v0, $at, L_8005BB6C
    if (ctx->r2 != ctx->r1) {
        // 0x8005BB64: nop
    
            goto L_8005BB6C;
    }
    // 0x8005BB64: nop

    // 0x8005BB68: break       6
    do_break(2147859304);
L_8005BB6C:
    // 0x8005BB6C: mflo        $v0
    ctx->r2 = lo;
    // 0x8005BB70: nop

    // 0x8005BB74: nop

    // 0x8005BB78: sra         $v1, $t2, 2
    ctx->r3 = S32(SIGNED(ctx->r10) >> 2);
    // 0x8005BB7C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005BB80: mflo        $s1
    ctx->r17 = lo;
    // 0x8005BB84: nop

    // 0x8005BB88: nop

    // 0x8005BB8C: sll         $v0, $t4, 2
    ctx->r2 = S32(ctx->r12 << 2);
    // 0x8005BB90: mult        $t1, $v0
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005BB94: mflo        $v0
    ctx->r2 = lo;
    // 0x8005BB98: nop

    // 0x8005BB9C: nop

    // 0x8005BBA0: addu        $s5, $v1, $zero
    ctx->r21 = ADD32(ctx->r3, 0);
    // 0x8005BBA4: bgez        $v0, L_8005BBB0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005BBA8: addu        $s4, $t0, $zero
        ctx->r20 = ADD32(ctx->r8, 0);
            goto L_8005BBB0;
    }
    // 0x8005BBA8: addu        $s4, $t0, $zero
    ctx->r20 = ADD32(ctx->r8, 0);
    // 0x8005BBAC: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
L_8005BBB0:
    // 0x8005BBB0: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8005BBB4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005BBB8: addu        $t7, $zero, $zero
    ctx->r15 = ADD32(0, 0);
    // 0x8005BBBC: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
    // 0x8005BBC0: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8005BBC4: subu        $a0, $t9, $t4
    ctx->r4 = SUB32(ctx->r25, ctx->r12);
    // 0x8005BBC8: addiu       $v0, $t1, -0x1
    ctx->r2 = ADD32(ctx->r9, -0X1);
    // 0x8005BBCC: mult        $v0, $s4
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005BBD0: mflo        $s2
    ctx->r18 = lo;
    // 0x8005BBD4: nop

    // 0x8005BBD8: nop

    // 0x8005BBDC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_8005BBE0:
    // 0x8005BBE0: slti        $v0, $t6, 0x4
    ctx->r2 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x8005BBE4: beq         $v0, $zero, L_8005BC04
    if (ctx->r2 == 0) {
        // 0x8005BBE8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8005BC04;
    }
    // 0x8005BBE8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005BBEC: srl         $a1, $t5, 28
    ctx->r5 = S32(U32(ctx->r13) >> 28);
    // 0x8005BBF0: addu        $t5, $s0, $zero
    ctx->r13 = ADD32(ctx->r16, 0);
    // 0x8005BBF4: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x8005BBF8: addiu       $t8, $t8, 0x4
    ctx->r24 = ADD32(ctx->r24, 0X4);
    // 0x8005BBFC: subu        $v1, $v1, $t6
    ctx->r3 = SUB32(ctx->r3, ctx->r14);
    // 0x8005BC00: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
L_8005BC04:
    // 0x8005BC04: subu        $v0, $s3, $v1
    ctx->r2 = SUB32(ctx->r19, ctx->r3);
    // 0x8005BC08: srlv        $v0, $t5, $v0
    ctx->r2 = S32(U32(ctx->r13) >> (ctx->r2 & 31));
    // 0x8005BC0C: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x8005BC10: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8005BC14: slti        $v0, $a1, 0xD
    ctx->r2 = SIGNED(ctx->r5) < 0XD ? 1 : 0;
    // 0x8005BC18: bne         $v0, $zero, L_8005BCC8
    if (ctx->r2 != 0) {
        // 0x8005BC1C: sllv        $t5, $t5, $v1
        ctx->r13 = S32(ctx->r13 << (ctx->r3 & 31));
            goto L_8005BCC8;
    }
    // 0x8005BC1C: sllv        $t5, $t5, $v1
    ctx->r13 = S32(ctx->r13 << (ctx->r3 & 31));
    // 0x8005BC20: lw          $s7, 0x4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4);
    // 0x8005BC24: addiu       $t0, $a1, -0xD
    ctx->r8 = ADD32(ctx->r5, -0XD);
    // 0x8005BC28: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x8005BC2C: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8005BC30: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8005BC34: slt         $v0, $t6, $v1
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005BC38: beq         $v0, $zero, L_8005BC5C
    if (ctx->r2 == 0) {
        // 0x8005BC3C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8005BC5C;
    }
    // 0x8005BC3C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005BC40: subu        $v0, $s3, $v1
    ctx->r2 = SUB32(ctx->r19, ctx->r3);
    // 0x8005BC44: srlv        $a1, $t5, $v0
    ctx->r5 = S32(U32(ctx->r13) >> (ctx->r2 & 31));
    // 0x8005BC48: addu        $t5, $s0, $zero
    ctx->r13 = ADD32(ctx->r16, 0);
    // 0x8005BC4C: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x8005BC50: addiu       $t8, $t8, 0x4
    ctx->r24 = ADD32(ctx->r24, 0X4);
    // 0x8005BC54: subu        $v1, $v1, $t6
    ctx->r3 = SUB32(ctx->r3, ctx->r14);
    // 0x8005BC58: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
L_8005BC5C:
    // 0x8005BC5C: subu        $v0, $s3, $v1
    ctx->r2 = SUB32(ctx->r19, ctx->r3);
    // 0x8005BC60: srlv        $v0, $t5, $v0
    ctx->r2 = S32(U32(ctx->r13) >> (ctx->r2 & 31));
    // 0x8005BC64: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x8005BC68: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8005BC6C: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x8005BC70: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005BC74: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8005BC78: sllv        $t5, $t5, $v1
    ctx->r13 = S32(ctx->r13 << (ctx->r3 & 31));
    // 0x8005BC7C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8005BC80: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x8005BC84: bltz        $a1, L_8005BFA4
    if (SIGNED(ctx->r5) < 0) {
        // 0x8005BC88: subu        $s1, $v0, $a1
        ctx->r17 = SUB32(ctx->r2, ctx->r5);
            goto L_8005BFA4;
    }
    // 0x8005BC88: subu        $s1, $v0, $a1
    ctx->r17 = SUB32(ctx->r2, ctx->r5);
    // 0x8005BC8C: addu        $v0, $a3, $s4
    ctx->r2 = ADD32(ctx->r7, ctx->r20);
    // 0x8005BC90: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_8005BC94:
    // 0x8005BC94: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8005BC98: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8005BC9C: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x8005BCA0: bne         $t7, $s5, L_8005BCB4
    if (ctx->r15 != ctx->r21) {
        // 0x8005BCA4: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8005BCB4;
    }
    // 0x8005BCA4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8005BCA8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005BCAC: addu        $a3, $a3, $s2
    ctx->r7 = ADD32(ctx->r7, ctx->r18);
    // 0x8005BCB0: addu        $t7, $zero, $zero
    ctx->r15 = ADD32(0, 0);
L_8005BCB4:
    // 0x8005BCB4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8005BCB8: bgezl       $a1, L_8005BC94
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8005BCBC: sw          $zero, 0x0($a3)
        MEM_W(0X0, ctx->r7) = 0;
            goto L_8005BC94;
    }
    goto skip_0;
    // 0x8005BCBC: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    skip_0:
    // 0x8005BCC0: j           L_8005BFA4
    // 0x8005BCC4: nop

        goto L_8005BFA4;
    // 0x8005BCC4: nop

L_8005BCC8:
    // 0x8005BCC8: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8005BCCC: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x8005BCD0: lhu         $a2, 0x0($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X0);
    // 0x8005BCD4: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8005BCD8: slt         $v0, $t6, $a2
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8005BCDC: beq         $v0, $zero, L_8005BD0C
    if (ctx->r2 == 0) {
        // 0x8005BCE0: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8005BD0C;
    }
    // 0x8005BCE0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005BCE4: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x8005BCE8: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x8005BCEC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8005BCF0: subu        $a2, $a2, $t6
    ctx->r6 = SUB32(ctx->r6, ctx->r14);
    // 0x8005BCF4: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8005BCF8: subu        $v0, $s3, $v0
    ctx->r2 = SUB32(ctx->r19, ctx->r2);
    // 0x8005BCFC: srlv        $a1, $t5, $v0
    ctx->r5 = S32(U32(ctx->r13) >> (ctx->r2 & 31));
    // 0x8005BD00: addu        $t5, $s0, $zero
    ctx->r13 = ADD32(ctx->r16, 0);
    // 0x8005BD04: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x8005BD08: addiu       $t8, $t8, 0x4
    ctx->r24 = ADD32(ctx->r24, 0X4);
L_8005BD0C:
    // 0x8005BD0C: subu        $v1, $s3, $a2
    ctx->r3 = SUB32(ctx->r19, ctx->r6);
    // 0x8005BD10: lw          $s7, 0xC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XC);
    // 0x8005BD14: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8005BD18: srlv        $v1, $t5, $v1
    ctx->r3 = S32(U32(ctx->r13) >> (ctx->r3 & 31));
    // 0x8005BD1C: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8005BD20: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005BD24: lw          $s7, 0x1C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X1C);
    // 0x8005BD28: or          $a1, $a1, $v1
    ctx->r5 = ctx->r5 | ctx->r3;
    // 0x8005BD2C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8005BD30: nop

    // 0x8005BD34: mult        $a1, $s7
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005BD38: mflo        $v0
    ctx->r2 = lo;
    // 0x8005BD3C: nop

    // 0x8005BD40: nop

    // 0x8005BD44: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x8005BD48: sllv        $t5, $t5, $a2
    ctx->r13 = S32(ctx->r13 << (ctx->r6 & 31));
    // 0x8005BD4C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8005BD50: lw          $s7, 0x14($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X14);
    // 0x8005BD54: addu        $a2, $t4, $zero
    ctx->r6 = ADD32(ctx->r12, 0);
    // 0x8005BD58: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005BD5C: addu        $t1, $s7, $v0
    ctx->r9 = ADD32(ctx->r23, ctx->r2);
    // 0x8005BD60: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8005BD64: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005BD68: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8005BD6C: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8005BD70: beq         $v0, $zero, L_8005BD90
    if (ctx->r2 == 0) {
        // 0x8005BD74: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8005BD90;
    }
    // 0x8005BD74: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005BD78: subu        $v0, $t0, $t4
    ctx->r2 = SUB32(ctx->r8, ctx->r12);
    // 0x8005BD7C: srlv        $a1, $v1, $v0
    ctx->r5 = S32(U32(ctx->r3) >> (ctx->r2 & 31));
    // 0x8005BD80: addu        $v1, $t3, $zero
    ctx->r3 = ADD32(ctx->r11, 0);
    // 0x8005BD84: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8005BD88: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005BD8C: addiu       $a2, $t4, -0x8
    ctx->r6 = ADD32(ctx->r12, -0X8);
L_8005BD90:
    // 0x8005BD90: subu        $v0, $t9, $a2
    ctx->r2 = SUB32(ctx->r25, ctx->r6);
    // 0x8005BD94: srlv        $v0, $v1, $v0
    ctx->r2 = S32(U32(ctx->r3) >> (ctx->r2 & 31));
    // 0x8005BD98: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x8005BD9C: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8005BDA0: sllv        $v1, $v1, $a2
    ctx->r3 = S32(ctx->r3 << (ctx->r6 & 31));
    // 0x8005BDA4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8005BDA8: sll         $t2, $a1, 24
    ctx->r10 = S32(ctx->r5 << 24);
    // 0x8005BDAC: addu        $a2, $t4, $zero
    ctx->r6 = ADD32(ctx->r12, 0);
    // 0x8005BDB0: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8005BDB4: beq         $v0, $zero, L_8005BDD4
    if (ctx->r2 == 0) {
        // 0x8005BDB8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8005BDD4;
    }
    // 0x8005BDB8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005BDBC: srlv        $a1, $v1, $a0
    ctx->r5 = S32(U32(ctx->r3) >> (ctx->r4 & 31));
    // 0x8005BDC0: addu        $v1, $t3, $zero
    ctx->r3 = ADD32(ctx->r11, 0);
    // 0x8005BDC4: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8005BDC8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005BDCC: subu        $a2, $t4, $t0
    ctx->r6 = SUB32(ctx->r12, ctx->r8);
    // 0x8005BDD0: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
L_8005BDD4:
    // 0x8005BDD4: subu        $v0, $t9, $a2
    ctx->r2 = SUB32(ctx->r25, ctx->r6);
    // 0x8005BDD8: srlv        $v0, $v1, $v0
    ctx->r2 = S32(U32(ctx->r3) >> (ctx->r2 & 31));
    // 0x8005BDDC: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x8005BDE0: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8005BDE4: sllv        $v1, $v1, $a2
    ctx->r3 = S32(ctx->r3 << (ctx->r6 & 31));
    // 0x8005BDE8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8005BDEC: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8005BDF0: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
    // 0x8005BDF4: addu        $a2, $t4, $zero
    ctx->r6 = ADD32(ctx->r12, 0);
    // 0x8005BDF8: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8005BDFC: beq         $v0, $zero, L_8005BE1C
    if (ctx->r2 == 0) {
        // 0x8005BE00: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8005BE1C;
    }
    // 0x8005BE00: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005BE04: srlv        $a1, $v1, $a0
    ctx->r5 = S32(U32(ctx->r3) >> (ctx->r4 & 31));
    // 0x8005BE08: addu        $v1, $t3, $zero
    ctx->r3 = ADD32(ctx->r11, 0);
    // 0x8005BE0C: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8005BE10: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005BE14: subu        $a2, $t4, $t0
    ctx->r6 = SUB32(ctx->r12, ctx->r8);
    // 0x8005BE18: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
L_8005BE1C:
    // 0x8005BE1C: subu        $v0, $t9, $a2
    ctx->r2 = SUB32(ctx->r25, ctx->r6);
    // 0x8005BE20: srlv        $v0, $v1, $v0
    ctx->r2 = S32(U32(ctx->r3) >> (ctx->r2 & 31));
    // 0x8005BE24: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x8005BE28: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8005BE2C: sllv        $v1, $v1, $a2
    ctx->r3 = S32(ctx->r3 << (ctx->r6 & 31));
    // 0x8005BE30: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8005BE34: sll         $v0, $a1, 8
    ctx->r2 = S32(ctx->r5 << 8);
    // 0x8005BE38: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
    // 0x8005BE3C: addu        $a2, $t4, $zero
    ctx->r6 = ADD32(ctx->r12, 0);
    // 0x8005BE40: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8005BE44: beq         $v0, $zero, L_8005BE64
    if (ctx->r2 == 0) {
        // 0x8005BE48: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8005BE64;
    }
    // 0x8005BE48: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005BE4C: srlv        $a1, $v1, $a0
    ctx->r5 = S32(U32(ctx->r3) >> (ctx->r4 & 31));
    // 0x8005BE50: addu        $v1, $t3, $zero
    ctx->r3 = ADD32(ctx->r11, 0);
    // 0x8005BE54: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8005BE58: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005BE5C: subu        $a2, $t4, $t0
    ctx->r6 = SUB32(ctx->r12, ctx->r8);
    // 0x8005BE60: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
L_8005BE64:
    // 0x8005BE64: subu        $v0, $t9, $a2
    ctx->r2 = SUB32(ctx->r25, ctx->r6);
    // 0x8005BE68: srlv        $v0, $v1, $v0
    ctx->r2 = S32(U32(ctx->r3) >> (ctx->r2 & 31));
    // 0x8005BE6C: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x8005BE70: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8005BE74: sllv        $v1, $v1, $a2
    ctx->r3 = S32(ctx->r3 << (ctx->r6 & 31));
    // 0x8005BE78: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8005BE7C: or          $t2, $t2, $a1
    ctx->r10 = ctx->r10 | ctx->r5;
    // 0x8005BE80: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x8005BE84: addu        $a2, $t4, $zero
    ctx->r6 = ADD32(ctx->r12, 0);
    // 0x8005BE88: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8005BE8C: beq         $v0, $zero, L_8005BEAC
    if (ctx->r2 == 0) {
        // 0x8005BE90: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8005BEAC;
    }
    // 0x8005BE90: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005BE94: srlv        $a1, $v1, $a0
    ctx->r5 = S32(U32(ctx->r3) >> (ctx->r4 & 31));
    // 0x8005BE98: addu        $v1, $t3, $zero
    ctx->r3 = ADD32(ctx->r11, 0);
    // 0x8005BE9C: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8005BEA0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005BEA4: subu        $a2, $t4, $t0
    ctx->r6 = SUB32(ctx->r12, ctx->r8);
    // 0x8005BEA8: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
L_8005BEAC:
    // 0x8005BEAC: subu        $v0, $t9, $a2
    ctx->r2 = SUB32(ctx->r25, ctx->r6);
    // 0x8005BEB0: srlv        $v0, $v1, $v0
    ctx->r2 = S32(U32(ctx->r3) >> (ctx->r2 & 31));
    // 0x8005BEB4: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x8005BEB8: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8005BEBC: sllv        $v1, $v1, $a2
    ctx->r3 = S32(ctx->r3 << (ctx->r6 & 31));
    // 0x8005BEC0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8005BEC4: sll         $t2, $a1, 24
    ctx->r10 = S32(ctx->r5 << 24);
    // 0x8005BEC8: addu        $a2, $t4, $zero
    ctx->r6 = ADD32(ctx->r12, 0);
    // 0x8005BECC: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8005BED0: beq         $v0, $zero, L_8005BEF0
    if (ctx->r2 == 0) {
        // 0x8005BED4: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8005BEF0;
    }
    // 0x8005BED4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005BED8: srlv        $a1, $v1, $a0
    ctx->r5 = S32(U32(ctx->r3) >> (ctx->r4 & 31));
    // 0x8005BEDC: addu        $v1, $t3, $zero
    ctx->r3 = ADD32(ctx->r11, 0);
    // 0x8005BEE0: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8005BEE4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005BEE8: subu        $a2, $t4, $t0
    ctx->r6 = SUB32(ctx->r12, ctx->r8);
    // 0x8005BEEC: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
L_8005BEF0:
    // 0x8005BEF0: subu        $v0, $t9, $a2
    ctx->r2 = SUB32(ctx->r25, ctx->r6);
    // 0x8005BEF4: srlv        $v0, $v1, $v0
    ctx->r2 = S32(U32(ctx->r3) >> (ctx->r2 & 31));
    // 0x8005BEF8: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x8005BEFC: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8005BF00: sllv        $v1, $v1, $a2
    ctx->r3 = S32(ctx->r3 << (ctx->r6 & 31));
    // 0x8005BF04: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8005BF08: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8005BF0C: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
    // 0x8005BF10: addu        $a2, $t4, $zero
    ctx->r6 = ADD32(ctx->r12, 0);
    // 0x8005BF14: slt         $v0, $t0, $t4
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8005BF18: beq         $v0, $zero, L_8005BF34
    if (ctx->r2 == 0) {
        // 0x8005BF1C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8005BF34;
    }
    // 0x8005BF1C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005BF20: srlv        $a1, $v1, $a0
    ctx->r5 = S32(U32(ctx->r3) >> (ctx->r4 & 31));
    // 0x8005BF24: addu        $v1, $t3, $zero
    ctx->r3 = ADD32(ctx->r11, 0);
    // 0x8005BF28: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8005BF2C: subu        $a2, $t4, $t0
    ctx->r6 = SUB32(ctx->r12, ctx->r8);
    // 0x8005BF30: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
L_8005BF34:
    // 0x8005BF34: subu        $v0, $t9, $a2
    ctx->r2 = SUB32(ctx->r25, ctx->r6);
    // 0x8005BF38: srlv        $v0, $v1, $v0
    ctx->r2 = S32(U32(ctx->r3) >> (ctx->r2 & 31));
    // 0x8005BF3C: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x8005BF40: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8005BF44: sllv        $v1, $v1, $a2
    ctx->r3 = S32(ctx->r3 << (ctx->r6 & 31));
    // 0x8005BF48: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8005BF4C: sll         $v0, $a1, 8
    ctx->r2 = S32(ctx->r5 << 8);
    // 0x8005BF50: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
    // 0x8005BF54: addu        $a2, $t4, $zero
    ctx->r6 = ADD32(ctx->r12, 0);
    // 0x8005BF58: slt         $v0, $t0, $a2
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8005BF5C: beq         $v0, $zero, L_8005BF74
    if (ctx->r2 == 0) {
        // 0x8005BF60: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8005BF74;
    }
    // 0x8005BF60: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005BF64: subu        $v0, $t9, $a2
    ctx->r2 = SUB32(ctx->r25, ctx->r6);
    // 0x8005BF68: srlv        $a1, $v1, $v0
    ctx->r5 = S32(U32(ctx->r3) >> (ctx->r2 & 31));
    // 0x8005BF6C: addu        $v1, $t3, $zero
    ctx->r3 = ADD32(ctx->r11, 0);
    // 0x8005BF70: subu        $a2, $a2, $t0
    ctx->r6 = SUB32(ctx->r6, ctx->r8);
L_8005BF74:
    // 0x8005BF74: subu        $v0, $t9, $a2
    ctx->r2 = SUB32(ctx->r25, ctx->r6);
    // 0x8005BF78: srlv        $v0, $v1, $v0
    ctx->r2 = S32(U32(ctx->r3) >> (ctx->r2 & 31));
    // 0x8005BF7C: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x8005BF80: or          $t2, $t2, $a1
    ctx->r10 = ctx->r10 | ctx->r5;
    // 0x8005BF84: addu        $v0, $a3, $s4
    ctx->r2 = ADD32(ctx->r7, ctx->r20);
    // 0x8005BF88: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8005BF8C: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x8005BF90: bne         $t7, $s5, L_8005BFA0
    if (ctx->r15 != ctx->r21) {
        // 0x8005BF94: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8005BFA0;
    }
    // 0x8005BF94: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8005BF98: addu        $a3, $a3, $s2
    ctx->r7 = ADD32(ctx->r7, ctx->r18);
    // 0x8005BF9C: addu        $t7, $zero, $zero
    ctx->r15 = ADD32(0, 0);
L_8005BFA0:
    // 0x8005BFA0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8005BFA4:
    // 0x8005BFA4: bgtz        $s1, L_8005BBE0
    if (SIGNED(ctx->r17) > 0) {
        // 0x8005BFA8: addiu       $v1, $zero, 0x4
        ctx->r3 = ADD32(0, 0X4);
            goto L_8005BBE0;
    }
    // 0x8005BFA8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8005BFAC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8005BFB0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8005BFB4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8005BFB8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8005BFBC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8005BFC0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8005BFC4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005BFC8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005BFCC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005BFD0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8005BFD4: jr          $ra
    // 0x8005BFD8: nop

    return;
    // 0x8005BFD8: nop

    // 0x8005BFDC: nop

;}
RECOMP_FUNC void func_8005BFE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BFE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005BFE4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8005BFE8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8005BFEC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8005BFF0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8005BFF4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005BFF8: jal         0x800748C0
    // 0x8005BFFC: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    func_800748C0(rdram, ctx);
        goto after_0;
    // 0x8005BFFC: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_0:
    // 0x8005C000: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005C004: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005C008: jr          $ra
    // 0x8005C00C: nop

    return;
    // 0x8005C00C: nop

;}
RECOMP_FUNC void func_8005C010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C014: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005C018: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8005C01C: addiu       $s0, $s0, -0x5530
    ctx->r16 = ADD32(ctx->r16, -0X5530);
    // 0x8005C020: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C024: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8005C028: addiu       $a1, $a1, 0x53C0
    ctx->r5 = ADD32(ctx->r5, 0X53C0);
    // 0x8005C02C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C030: jal         0x80070490
    // 0x8005C034: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8005C034: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8005C038: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8005C03C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005C040: jal         0x80070880
    // 0x8005C044: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8005C044: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x8005C048: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005C04C: addiu       $a1, $a1, 0x1A6
    ctx->r5 = ADD32(ctx->r5, 0X1A6);
    // 0x8005C050: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8005C054: addiu       $a2, $a2, 0x4DE0
    ctx->r6 = ADD32(ctx->r6, 0X4DE0);
    // 0x8005C058: jal         0x800724D0
    // 0x8005C05C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800724D0(rdram, ctx);
        goto after_2;
    // 0x8005C05C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8005C060: jal         0x800727E0
    // 0x8005C064: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800727E0(rdram, ctx);
        goto after_3;
    // 0x8005C064: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x8005C068: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8005C06C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005C070: addiu       $v1, $v1, -0x67B4
    ctx->r3 = ADD32(ctx->r3, -0X67B4);
    // 0x8005C074: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005C078: addiu       $v0, $v0, -0x6916
    ctx->r2 = ADD32(ctx->r2, -0X6916);
L_8005C07C:
    // 0x8005C07C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005C080: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8005C084: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8005C088: bgez        $a0, L_8005C07C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005C08C: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8005C07C;
    }
    // 0x8005C08C: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8005C090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C094: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005C098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C09C: jr          $ra
    // 0x8005C0A0: nop

    return;
    // 0x8005C0A0: nop

;}
RECOMP_FUNC void func_8005C0A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C0A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005C0A8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8005C0AC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8005C0B0: addiu       $v1, $zero, 0x300
    ctx->r3 = ADD32(0, 0X300);
    // 0x8005C0B4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8005C0B8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8005C0BC: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8005C0C0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005C0C4: jal         0x80073940
    // 0x8005C0C8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_80073940(rdram, ctx);
        goto after_0;
    // 0x8005C0C8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
    // 0x8005C0CC: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8005C0D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005C0D4: jr          $ra
    // 0x8005C0D8: nop

    return;
    // 0x8005C0D8: nop

;}
RECOMP_FUNC void func_8005C0DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C0DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C0E0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005C0E4: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8005C0E8: addiu       $s0, $s0, -0x5530
    ctx->r16 = ADD32(ctx->r16, -0X5530);
    // 0x8005C0EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C0F0: jal         0x80072430
    // 0x8005C0F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80072430(rdram, ctx);
        goto after_0;
    // 0x8005C0F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8005C0F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C0FC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005C100: jal         0x80070620
    // 0x8005C104: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8005C104: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8005C108: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8005C10C: addiu       $a0, $a0, 0x4DE0
    ctx->r4 = ADD32(ctx->r4, 0X4DE0);
    // 0x8005C110: jal         0x800724B0
    // 0x8005C114: nop

    func_800724B0(rdram, ctx);
        goto after_2;
    // 0x8005C114: nop

    after_2:
    // 0x8005C118: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005C11C:
    // 0x8005C11C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005C120: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005C124: lbu         $v0, 0x4DE3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4DE3);
    // 0x8005C128: bne         $v0, $zero, L_8005C138
    if (ctx->r2 != 0) {
        // 0x8005C12C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8005C138;
    }
    // 0x8005C12C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005C130: j           L_8005C144
    // 0x8005C134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005C144;
    // 0x8005C134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005C138:
    // 0x8005C138: slti        $v0, $v1, 0xC
    ctx->r2 = SIGNED(ctx->r3) < 0XC ? 1 : 0;
    // 0x8005C13C: bne         $v0, $zero, L_8005C11C
    if (ctx->r2 != 0) {
        // 0x8005C140: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8005C11C;
    }
    // 0x8005C140: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005C144:
    // 0x8005C144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C148: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005C14C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C150: jr          $ra
    // 0x8005C154: nop

    return;
    // 0x8005C154: nop

;}
RECOMP_FUNC void func_8005C158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C158: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C15C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005C160: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005C164: addiu       $a0, $a0, -0x5530
    ctx->r4 = ADD32(ctx->r4, -0X5530);
    // 0x8005C168: jal         0x800733D0
    // 0x8005C16C: nop

    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x8005C16C: nop

    after_0:
    // 0x8005C170: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005C174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C178: jr          $ra
    // 0x8005C17C: nop

    return;
    // 0x8005C17C: nop

;}
RECOMP_FUNC void func_8005C180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C184: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005C188: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005C18C: addiu       $a0, $a0, -0x5530
    ctx->r4 = ADD32(ctx->r4, -0X5530);
    // 0x8005C190: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005C194: jal         0x80070620
    // 0x8005C198: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8005C198: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x8005C19C: bne         $v0, $zero, L_8005C1B4
    if (ctx->r2 != 0) {
        // 0x8005C1A0: nop
    
            goto L_8005C1B4;
    }
    // 0x8005C1A0: nop

    // 0x8005C1A4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005C1A8: addiu       $a0, $a0, -0x6928
    ctx->r4 = ADD32(ctx->r4, -0X6928);
    // 0x8005C1AC: jal         0x80073458
    // 0x8005C1B0: nop

    func_80073458(rdram, ctx);
        goto after_1;
    // 0x8005C1B0: nop

    after_1:
L_8005C1B4:
    // 0x8005C1B4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005C1B8: addiu       $v0, $v0, -0x67C0
    ctx->r2 = ADD32(ctx->r2, -0X67C0);
    // 0x8005C1BC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005C1C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C1C4: jr          $ra
    // 0x8005C1C8: nop

    return;
    // 0x8005C1C8: nop

;}
RECOMP_FUNC void func_8005C1CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C1CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005C1D0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8005C1D4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8005C1D8: lhu         $a1, 0x8($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0X8);
    // 0x8005C1DC: addiu       $v0, $a3, 0xA
    ctx->r2 = ADD32(ctx->r7, 0XA);
    // 0x8005C1E0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005C1E4: lw          $a2, 0x4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X4);
    // 0x8005C1E8: jal         0x80073D70
    // 0x8005C1EC: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    func_80073D70(rdram, ctx);
        goto after_0;
    // 0x8005C1EC: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    after_0:
    // 0x8005C1F0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005C1F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005C1F8: jr          $ra
    // 0x8005C1FC: nop

    return;
    // 0x8005C1FC: nop

;}
RECOMP_FUNC void func_8005C200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C200: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005C204: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005C208: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005C20C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005C210: addiu       $a0, $a0, -0x5530
    ctx->r4 = ADD32(ctx->r4, -0X5530);
    // 0x8005C214: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005C218: jal         0x80072840
    // 0x8005C21C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_80072840(rdram, ctx);
        goto after_0;
    // 0x8005C21C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x8005C220: bne         $v0, $zero, L_8005C268
    if (ctx->r2 != 0) {
        // 0x8005C224: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005C268;
    }
    // 0x8005C224: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005C228: lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X10);
    // 0x8005C22C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8005C230: beq         $v0, $zero, L_8005C268
    if (ctx->r2 == 0) {
        // 0x8005C234: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005C268;
    }
    // 0x8005C234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005C238: jal         0x8005C30C
    // 0x8005C23C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8005C30C(rdram, ctx);
        goto after_1;
    // 0x8005C23C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8005C240: xori        $v1, $v0, 0x2
    ctx->r3 = ctx->r2 ^ 0X2;
    // 0x8005C244: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8005C248: xori        $v0, $v0, 0xA
    ctx->r2 = ctx->r2 ^ 0XA;
    // 0x8005C24C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8005C250: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005C254: beql        $v1, $zero, L_8005C268
    if (ctx->r3 == 0) {
        // 0x8005C258: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8005C268;
    }
    goto skip_0;
    // 0x8005C258: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
    // 0x8005C25C: jal         0x8005C3C0
    // 0x8005C260: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8005C3C0(rdram, ctx);
        goto after_2;
    // 0x8005C260: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8005C264: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8005C268:
    // 0x8005C268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C26C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005C270: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005C274: jr          $ra
    // 0x8005C278: nop

    return;
    // 0x8005C278: nop

;}
RECOMP_FUNC void func_8005C27C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C27C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005C280: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8005C284: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8005C288: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8005C28C: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x8005C290: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005C294: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005C298: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8005C29C: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8005C2A0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005C2A4: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8005C2A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_8005C2AC:
    // 0x8005C2AC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8005C2B0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005C2B4: jal         0x80073F90
    // 0x8005C2B8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80073F90(rdram, ctx);
        goto after_0;
    // 0x8005C2B8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8005C2BC: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x8005C2C0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8005C2C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005C2C8: slti        $v0, $s0, 0x10
    ctx->r2 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x8005C2CC: bne         $v0, $zero, L_8005C2AC
    if (ctx->r2 != 0) {
        // 0x8005C2D0: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_8005C2AC;
    }
    // 0x8005C2D0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x8005C2D4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8005C2D8: jal         0x80074120
    // 0x8005C2DC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_80074120(rdram, ctx);
        goto after_1;
    // 0x8005C2DC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_1:
    // 0x8005C2E0: bnel        $v0, $zero, L_8005C2E8
    if (ctx->r2 != 0) {
        // 0x8005C2E4: sw          $zero, 0x0($s4)
        MEM_W(0X0, ctx->r20) = 0;
            goto L_8005C2E8;
    }
    goto skip_0;
    // 0x8005C2E4: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    skip_0:
L_8005C2E8:
    // 0x8005C2E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005C2EC: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8005C2F0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C2F4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8005C2F8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005C2FC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005C300: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005C304: jr          $ra
    // 0x8005C308: nop

    return;
    // 0x8005C308: nop

;}
RECOMP_FUNC void func_8005C30C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C30C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C310: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005C314: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8005C318: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005C31C: addiu       $a0, $a0, -0x5530
    ctx->r4 = ADD32(ctx->r4, -0X5530);
    // 0x8005C320: jal         0x80074230
    // 0x8005C324: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osContInit_recomp(rdram, ctx);
        goto after_0;
    // 0x8005C324: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x8005C328: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005C32C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C330: jr          $ra
    // 0x8005C334: nop

    return;
    // 0x8005C334: nop

;}
RECOMP_FUNC void func_8005C338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C33C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005C340: jal         0x80074860
    // 0x8005C344: nop

    func_80074860(rdram, ctx);
        goto after_0;
    // 0x8005C344: nop

    after_0:
    // 0x8005C348: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005C34C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C350: jr          $ra
    // 0x8005C354: nop

    return;
    // 0x8005C354: nop

;}
RECOMP_FUNC void func_8005C358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C358: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005C35C: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x8005C360: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8005C364: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005C368: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x8005C36C: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x8005C370: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8005C374: jal         0x80074420
    // 0x8005C378: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80074420(rdram, ctx);
        goto after_0;
    // 0x8005C378: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x8005C37C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005C380: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005C384: jr          $ra
    // 0x8005C388: nop

    return;
    // 0x8005C388: nop

;}
RECOMP_FUNC void func_8005C38C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C38C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005C390: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x8005C394: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8005C398: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005C39C: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x8005C3A0: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x8005C3A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005C3A8: jal         0x80074420
    // 0x8005C3AC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80074420(rdram, ctx);
        goto after_0;
    // 0x8005C3AC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x8005C3B0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005C3B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005C3B8: jr          $ra
    // 0x8005C3BC: nop

    return;
    // 0x8005C3BC: nop

;}
RECOMP_FUNC void func_8005C3C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C3C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C3C4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005C3C8: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8005C3CC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005C3D0: addiu       $a0, $a0, -0x5530
    ctx->r4 = ADD32(ctx->r4, -0X5530);
    // 0x8005C3D4: jal         0x800736F4
    // 0x8005C3D8: nop

    func_800736F4(rdram, ctx);
        goto after_0;
    // 0x8005C3D8: nop

    after_0:
    // 0x8005C3DC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005C3E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C3E4: jr          $ra
    // 0x8005C3E8: nop

    return;
    // 0x8005C3E8: nop

    // 0x8005C3EC: nop

;}
RECOMP_FUNC void recomp_entrypoint_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C3F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005C3F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005C3F8: jal         0x80075CD0
    // 0x8005C3FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    osInitialize_recomp(rdram, ctx);
        goto after_0;
    // 0x8005C3FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8005C400: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8005C404: addiu       $s0, $s0, 0x2718
    ctx->r16 = ADD32(ctx->r16, 0X2718);
    // 0x8005C408: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C40C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8005C410: addiu       $v0, $v0, 0x2CD0
    ctx->r2 = ADD32(ctx->r2, 0X2CD0);
    // 0x8005C414: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8005C418: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8005C41C: addiu       $a2, $a2, -0x3BB4
    ctx->r6 = ADD32(ctx->r6, -0X3BB4);
    // 0x8005C420: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8005C424: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005C428: jal         0x800704C0
    // 0x8005C42C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x8005C42C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x8005C430: jal         0x80070980
    // 0x8005C434: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x8005C434: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8005C438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C43C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005C440: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005C444: jr          $ra
    // 0x8005C448: nop

    return;
    // 0x8005C448: nop

;}
RECOMP_FUNC void func_8005C44C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C44C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005C450: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    // 0x8005C454: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005C458: jal         0x800732B0
    // 0x8005C45C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    osCartRomInit_recomp(rdram, ctx);
        goto after_0;
    // 0x8005C45C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8005C460: jal         0x80074D10
    // 0x8005C464: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_1;
    // 0x8005C464: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_1:
    // 0x8005C468: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x8005C46C: lw          $v1, 0x300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X300);
    // 0x8005C470: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005C474: bne         $v1, $v0, L_8005C4CC
    if (ctx->r3 != ctx->r2) {
        // 0x8005C478: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8005C4CC;
    }
    // 0x8005C478: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005C47C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8005C480: addiu       $s0, $s0, 0x10C0
    ctx->r16 = ADD32(ctx->r16, 0X10C0);
    // 0x8005C484: jal         0x800721C0
    // 0x8005C488: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osViSetMode_recomp(rdram, ctx);
        goto after_2;
    // 0x8005C488: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8005C48C: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8005C490: addiu       $a2, $a2, 0x6700
    ctx->r6 = ADD32(ctx->r6, 0X6700);
    // 0x8005C494: addiu       $a3, $s0, 0x50
    ctx->r7 = ADD32(ctx->r16, 0X50);
L_8005C498:
    // 0x8005C498: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C49C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8005C4A0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8005C4A4: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8005C4A8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8005C4AC: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x8005C4B0: sw          $a0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r4;
    // 0x8005C4B4: sw          $a1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r5;
    // 0x8005C4B8: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8005C4BC: bne         $s0, $a3, L_8005C498
    if (ctx->r16 != ctx->r7) {
        // 0x8005C4C0: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_8005C498;
    }
    // 0x8005C4C0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8005C4C4: j           L_8005C56C
    // 0x8005C4C8: nop

        goto L_8005C56C;
    // 0x8005C4C8: nop

L_8005C4CC:
    // 0x8005C4CC: bne         $v1, $v0, L_8005C524
    if (ctx->r3 != ctx->r2) {
        // 0x8005C4D0: nop
    
            goto L_8005C524;
    }
    // 0x8005C4D0: nop

    // 0x8005C4D4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8005C4D8: addiu       $s0, $s0, 0x1980
    ctx->r16 = ADD32(ctx->r16, 0X1980);
    // 0x8005C4DC: jal         0x800721C0
    // 0x8005C4E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osViSetMode_recomp(rdram, ctx);
        goto after_3;
    // 0x8005C4E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8005C4E4: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8005C4E8: addiu       $a2, $a2, 0x6700
    ctx->r6 = ADD32(ctx->r6, 0X6700);
    // 0x8005C4EC: addiu       $a3, $s0, 0x50
    ctx->r7 = ADD32(ctx->r16, 0X50);
L_8005C4F0:
    // 0x8005C4F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C4F4: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8005C4F8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8005C4FC: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8005C500: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8005C504: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x8005C508: sw          $a0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r4;
    // 0x8005C50C: sw          $a1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r5;
    // 0x8005C510: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8005C514: bne         $s0, $a3, L_8005C4F0
    if (ctx->r16 != ctx->r7) {
        // 0x8005C518: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_8005C4F0;
    }
    // 0x8005C518: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8005C51C: j           L_8005C56C
    // 0x8005C520: nop

        goto L_8005C56C;
    // 0x8005C520: nop

L_8005C524:
    // 0x8005C524: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8005C528: addiu       $s0, $s0, 0x1520
    ctx->r16 = ADD32(ctx->r16, 0X1520);
    // 0x8005C52C: jal         0x800721C0
    // 0x8005C530: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osViSetMode_recomp(rdram, ctx);
        goto after_4;
    // 0x8005C530: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8005C534: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8005C538: addiu       $a2, $a2, 0x6700
    ctx->r6 = ADD32(ctx->r6, 0X6700);
    // 0x8005C53C: addiu       $a3, $s0, 0x50
    ctx->r7 = ADD32(ctx->r16, 0X50);
L_8005C540:
    // 0x8005C540: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C544: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8005C548: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8005C54C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8005C550: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8005C554: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x8005C558: sw          $a0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r4;
    // 0x8005C55C: sw          $a1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r5;
    // 0x8005C560: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8005C564: bne         $s0, $a3, L_8005C540
    if (ctx->r16 != ctx->r7) {
        // 0x8005C568: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_8005C540;
    }
    // 0x8005C568: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
L_8005C56C:
    // 0x8005C56C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C570: sh          $zero, 0x475C($at)
    MEM_H(0X475C, ctx->r1) = 0;
    // 0x8005C574: jal         0x800723D0
    // 0x8005C578: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_5;
    // 0x8005C578: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8005C57C: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x8005C580: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8005C584: addiu       $a1, $a1, 0x4F80
    ctx->r5 = ADD32(ctx->r5, 0X4F80);
    // 0x8005C588: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8005C58C: addiu       $a2, $a2, 0x4E80
    ctx->r6 = ADD32(ctx->r6, 0X4E80);
    // 0x8005C590: jal         0x80074AD0
    // 0x8005C594: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    osCreateViManager_recomp(rdram, ctx);
        goto after_6;
    // 0x8005C594: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_6:
    // 0x8005C598: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8005C59C: addiu       $s0, $s0, 0x2CD0
    ctx->r16 = ADD32(ctx->r16, 0X2CD0);
    // 0x8005C5A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C5A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8005C5A8: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8005C5AC: addiu       $a2, $a2, -0x18F0
    ctx->r6 = ADD32(ctx->r6, -0X18F0);
    // 0x8005C5B0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8005C5B4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8005C5B8: addiu       $v0, $v0, 0x4E80
    ctx->r2 = ADD32(ctx->r2, 0X4E80);
    // 0x8005C5BC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005C5C0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8005C5C4: jal         0x800704C0
    // 0x8005C5C8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_7;
    // 0x8005C5C8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_7:
    // 0x8005C5CC: jal         0x80070980
    // 0x8005C5D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_8;
    // 0x8005C5D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
L_8005C5D4:
    // 0x8005C5D4: j           L_8005C5D4
    pause_self(rdram);
    // 0x8005C5D8: nop

    // 0x8005C5DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C5E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005C5E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005C5E8: jr          $ra
    // 0x8005C5EC: nop

    return;
    // 0x8005C5EC: nop

;}
RECOMP_FUNC void func_8005C5F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C5F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005C5F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005C5F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005C5FC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005C600: addiu       $a1, $a1, -0x1C60
    ctx->r5 = ADD32(ctx->r5, -0X1C60);
    // 0x8005C604: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8005C608: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005C60C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
L_8005C610:
    // 0x8005C610: ori         $v0, $zero, 0xC240
    ctx->r2 = 0 | 0XC240;
    // 0x8005C614: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005C618: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8005C61C: sw          $a1, -0x5AF0($at)
    MEM_W(-0X5AF0, ctx->r1) = ctx->r5;
    // 0x8005C620: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8005C624: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005C628: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8005C62C: sw          $a2, -0x5AE8($at)
    MEM_W(-0X5AE8, ctx->r1) = ctx->r6;
    // 0x8005C630: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005C634: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8005C638: bne         $v0, $zero, L_8005C610
    if (ctx->r2 != 0) {
        // 0x8005C63C: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_8005C610;
    }
    // 0x8005C63C: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8005C640: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005C644: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005C648: lui         $a1, 0x803A
    ctx->r5 = S32(0X803A << 16);
    // 0x8005C64C: addiu       $a1, $a1, 0x2400
    ctx->r5 = ADD32(ctx->r5, 0X2400);
    // 0x8005C650: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005C654:
    // 0x8005C654: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x8005C658: ori         $v0, $v0, 0xEE00
    ctx->r2 = ctx->r2 | 0XEE00;
    // 0x8005C65C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C660: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8005C664: sw          $a1, 0x528($at)
    MEM_W(0X528, ctx->r1) = ctx->r5;
    // 0x8005C668: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8005C66C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C670: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8005C674: sw          $a2, 0x52C($at)
    MEM_W(0X52C, ctx->r1) = ctx->r6;
    // 0x8005C678: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005C67C: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8005C680: bne         $v0, $zero, L_8005C654
    if (ctx->r2 != 0) {
        // 0x8005C684: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8005C654;
    }
    // 0x8005C684: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8005C688: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005C68C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8005C690: sw          $v0, 0x5578($at)
    MEM_W(0X5578, ctx->r1) = ctx->r2;
    // 0x8005C694: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C698: sw          $v0, 0x94($at)
    MEM_W(0X94, ctx->r1) = ctx->r2;
    // 0x8005C69C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C6A0: sw          $v0, -0x34($at)
    MEM_W(-0X34, ctx->r1) = ctx->r2;
    // 0x8005C6A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005C6A8: sw          $v0, -0x5490($at)
    MEM_W(-0X5490, ctx->r1) = ctx->r2;
    // 0x8005C6AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C6B0: sw          $v0, 0x134($at)
    MEM_W(0X134, ctx->r1) = ctx->r2;
    // 0x8005C6B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005C6B8: sw          $v0, -0x5638($at)
    MEM_W(-0X5638, ctx->r1) = ctx->r2;
    // 0x8005C6BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005C6C0: sw          $v0, 0x3EE4($at)
    MEM_W(0X3EE4, ctx->r1) = ctx->r2;
    // 0x8005C6C4: jal         0x8005C010
    // 0x8005C6C8: nop

    fprintf(stderr, "[R2-C5F0] calling func_8005C010\n"); fflush(stderr);
    func_8005C010(rdram, ctx);
        goto after_0;
    // 0x8005C6C8: nop

    after_0:
    fprintf(stderr, "[R2-C5F0] func_8005C010 returned, creating scheduler queue\n"); fflush(stderr);
    // 0x8005C6CC: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8005C6D0: addiu       $s0, $s0, -0x6908
    ctx->r16 = ADD32(ctx->r16, -0X6908);
    // 0x8005C6D4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C6D8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8005C6DC: addiu       $a1, $a1, 0x4060
    ctx->r5 = ADD32(ctx->r5, 0X4060);
    // 0x8005C6E0: jal         0x80070490
    // 0x8005C6E4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8005C6E4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_1:
    // 0x8005C6E8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8005C6EC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005C6F0: jal         0x80070880
    // 0x8005C6F4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8005C6F4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_2:
    // 0x8005C6F8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8005C6FC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005C700: jal         0x80070880
    // 0x8005C704: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8005C704: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8005C708: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8005C70C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005C710: jal         0x80070880
    // 0x8005C714: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8005C714: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x8005C718: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C71C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005C720: jal         0x80072160
    // 0x8005C724: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osViSetEvent_recomp(rdram, ctx);
        goto after_5;
    // 0x8005C724: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8005C728: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8005C72C: addiu       $s0, $s0, 0x4F98
    ctx->r16 = ADD32(ctx->r16, 0X4F98);
    // 0x8005C730: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C734: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005C738: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8005C73C: addiu       $a2, $a2, -0x367C
    ctx->r6 = ADD32(ctx->r6, -0X367C);
    // 0x8005C740: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8005C744: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8005C748: addiu       $v0, $v0, 0x6150
    ctx->r2 = ADD32(ctx->r2, 0X6150);
    // 0x8005C74C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005C750: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // 0x8005C754: jal         0x800704C0
    // 0x8005C758: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_6;
    // 0x8005C758: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_6:
    fprintf(stderr, "[R2-C5F0] Thread 3 (scheduler) created, starting it\n"); fflush(stderr);
    // 0x8005C75C: jal         0x80070980
    // 0x8005C760: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_7;
    // 0x8005C760: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    fprintf(stderr, "[R2-C5F0] Thread 3 started, checking osTvType\n"); fflush(stderr);
    // 0x8005C764: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005C768: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    fprintf(stderr, "[R2-C5F0] osTvType=0x%08X\n", (uint32_t)ctx->r2); fflush(stderr);
    // 0x8005C76C: bne         $v0, $zero, L_8005C7FC
    if (ctx->r2 != 0) {
        // 0x8005C770: nop
    
            goto L_8005C7FC;
    }
    // 0x8005C770: nop

    // 0x8005C774: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8005C778: addiu       $s0, $s0, 0x2568
    ctx->r16 = ADD32(ctx->r16, 0X2568);
    // 0x8005C77C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C780: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005C784: addiu       $a1, $a1, 0x54C
    ctx->r5 = ADD32(ctx->r5, 0X54C);
    // 0x8005C788: jal         0x80070490
    // 0x8005C78C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_8;
    // 0x8005C78C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
    // 0x8005C790: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005C794: addiu       $a0, $a0, -0x68D8
    ctx->r4 = ADD32(ctx->r4, -0X68D8);
    // 0x8005C798: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8005C79C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8005C7A0: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    // 0x8005C7A4: lui         $v1, 0xB
    ctx->r3 = S32(0XB << 16);
    // 0x8005C7A8: ori         $v1, $v1, 0xEBA2
    ctx->r3 = ctx->r3 | 0XEBA2;
    // 0x8005C7AC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005C7B0: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8005C7B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005C7B8: jal         0x800708E0
    // 0x8005C7BC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    osSetTimer_recomp(rdram, ctx);
        goto after_9;
    // 0x8005C7BC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_9:
    // 0x8005C7C0: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8005C7C4: addiu       $s0, $s0, 0x6150
    ctx->r16 = ADD32(ctx->r16, 0X6150);
    // 0x8005C7C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C7CC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8005C7D0: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8005C7D4: addiu       $a2, $a2, -0x35CC
    ctx->r6 = ADD32(ctx->r6, -0X35CC);
    // 0x8005C7D8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8005C7DC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8005C7E0: addiu       $v0, $v0, 0x6700
    ctx->r2 = ADD32(ctx->r2, 0X6700);
    // 0x8005C7E4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005C7E8: addiu       $v0, $zero, 0x55
    ctx->r2 = ADD32(0, 0X55);
    // 0x8005C7EC: jal         0x800704C0
    // 0x8005C7F0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_10;
    // 0x8005C7F0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_10:
    // 0x8005C7F4: jal         0x80070980
    // 0x8005C7F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_11;
    // 0x8005C7F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
L_8005C7FC:
    // 0x8005C7FC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8005C800: addiu       $a0, $a0, -0x74D8
    ctx->r4 = ADD32(ctx->r4, -0X74D8);
    // 0x8005C804: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8005C808: addiu       $a1, $a1, -0x5494
    ctx->r5 = ADD32(ctx->r5, -0X5494);
    // 0x8005C80C: jal         0x80070490
    // 0x8005C810: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_12;
    // 0x8005C810: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x8005C814: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005C818: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005C81C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005C820: jr          $ra
    // 0x8005C824: nop

    return;
    // 0x8005C824: nop

;}
RECOMP_FUNC void func_8005C828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C828: jr          $ra
    // 0x8005C82C: nop

    return;
    // 0x8005C82C: nop

;}
RECOMP_FUNC void func_8005C830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C830: jr          $ra
    // 0x8005C834: nop

    return;
    // 0x8005C834: nop

;}
RECOMP_FUNC void func_8005C838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C838: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8005C83C: lw          $v0, 0x5578($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5578);
    // 0x8005C840: bltz        $v0, L_8005C894
    if (SIGNED(ctx->r2) < 0) {
        // 0x8005C844: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8005C894;
    }
    // 0x8005C844: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005C848: j           L_8005C864
    // 0x8005C84C: nop

        goto L_8005C864;
    // 0x8005C84C: nop

L_8005C850:
    // 0x8005C850: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005C854: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8005C858: sw          $zero, -0x5AE8($at)
    MEM_W(-0X5AE8, ctx->r1) = 0;
    // 0x8005C85C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8005C860: sw          $a0, 0x5578($at)
    MEM_W(0X5578, ctx->r1) = ctx->r4;
L_8005C864:
    // 0x8005C864: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8005C868: lw          $v0, 0x5578($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5578);
    // 0x8005C86C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8005C870: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005C874: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005C878: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005C87C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8005C880: lw          $v1, -0x5AF0($at)
    ctx->r3 = MEM_W(ctx->r1, -0X5AF0);
    // 0x8005C884: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005C888: sw          $v1, 0x3EF0($at)
    MEM_W(0X3EF0, ctx->r1) = ctx->r3;
    // 0x8005C88C: j           L_8005C8C0
    // 0x8005C890: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005C8C0;
    // 0x8005C890: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005C894:
    // 0x8005C894: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005C898:
    // 0x8005C898: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005C89C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005C8A0: lw          $v0, -0x5AE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5AE8);
    // 0x8005C8A4: bne         $v0, $zero, L_8005C850
    if (ctx->r2 != 0) {
        // 0x8005C8A8: nop
    
            goto L_8005C850;
    }
    // 0x8005C8A8: nop

    // 0x8005C8AC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005C8B0: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8005C8B4: bne         $v0, $zero, L_8005C898
    if (ctx->r2 != 0) {
        // 0x8005C8B8: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_8005C898;
    }
    // 0x8005C8B8: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8005C8BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005C8C0:
    // 0x8005C8C0: jr          $ra
    // 0x8005C8C4: nop

    return;
    // 0x8005C8C4: nop

;}
RECOMP_FUNC void func_8005C8C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C8C8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8005C8CC: lw          $v0, 0x5578($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5578);
;}
RECOMP_FUNC void func_8005C8D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C8D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C8D4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005C8D8: beq         $v0, $a2, L_8005C94C
    if (ctx->r2 == ctx->r6) {
        // 0x8005C8DC: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8005C94C;
    }
    // 0x8005C8DC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005C8E0: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8005C8E4: lw          $v1, 0x5578($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5578);
    // 0x8005C8E8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8005C8EC: lw          $a1, 0x5578($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5578);
    // 0x8005C8F0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005C8F4: lw          $a0, 0x5578($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5578);
    // 0x8005C8F8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8005C8FC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005C900: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005C904: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005C908: lw          $v1, 0x3EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3EF0);
    // 0x8005C90C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005C910: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005C914: lw          $v0, -0x5AF0($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5AF0);
    // 0x8005C918: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C91C: sw          $a0, 0x94($at)
    MEM_W(0X94, ctx->r1) = ctx->r4;
    // 0x8005C920: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8005C924: sw          $a2, 0x5578($at)
    MEM_W(0X5578, ctx->r1) = ctx->r6;
    // 0x8005C928: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005C92C: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8005C930: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8005C934: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005C938: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005C93C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005C940: sw          $v1, -0x5AEC($at)
    MEM_W(-0X5AEC, ctx->r1) = ctx->r3;
    // 0x8005C944: jal         0x8005CF98
    // 0x8005C948: nop

    func_8005CF98(rdram, ctx);
        goto after_0;
    // 0x8005C948: nop

    after_0:
L_8005C94C:
    // 0x8005C94C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005C950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C954: jr          $ra
    // 0x8005C958: nop

    return;
    // 0x8005C958: nop

;}
RECOMP_FUNC void func_8005C95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    static int c95c_count = 0;
    c95c_count++;
    {
        int32_t val1 = (int32_t)MEM_W(S32(0x8017 << 16), -0x5490);
        int32_t val2 = (int32_t)MEM_W(S32(0x8017 << 16), -0x5638);
        if (c95c_count <= 3) {
            fprintf(stderr, "[R2-C95C] call #%d: slot1=0x%08X(%d) slot2=0x%08X(%d)\n",
                    c95c_count, (unsigned)val1, val1, (unsigned)val2, val2);
            fflush(stderr);
        }
    }
L_8005C95C:
    // YIELD: spin-wait for RSP task slots to become available.
    // On real N64, scheduler preempts. In cooperative mode, must yield.
    yield_self(rdram);
    // 0x8005C95C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005C960: lw          $v0, -0x5490($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5490);
    // 0x8005C964: bgez        $v0, L_8005C95C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005C968: nop

            goto L_8005C95C;
    }
    // 0x8005C968: nop

    // 0x8005C96C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005C970: lw          $v0, -0x5638($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5638);
    // 0x8005C974: bgez        $v0, L_8005C95C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005C978: nop

            goto L_8005C95C;
    }
    // 0x8005C978: nop

    // 0x8005C97C: jr          $ra
    // 0x8005C980: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8005C980: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8005C984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C984: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005C988: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005C98C: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8005C990: addiu       $s0, $s0, 0x1E00
    ctx->r16 = ADD32(ctx->r16, 0X1E00);
    // 0x8005C994: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_8005C998:
    {
        static int sched_loop = 0;
        if (sched_loop < 10 || (sched_loop % 300 == 0)) {
            fprintf(stderr, "[R2-SCHED] loop #%d: waiting for event on mq=0x801696F8\n", sched_loop);
            fflush(stderr);
        }
        sched_loop++;
    }
    // 0x8005C998: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005C99C: addiu       $a0, $a0, -0x6908
    ctx->r4 = ADD32(ctx->r4, -0X6908);
    // 0x8005C9A0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005C9A4: jal         0x80070620
    // 0x8005C9A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8005C9A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    {
        uint32_t msg = (uint32_t)MEM_W(ctx->r29, 0X10);
        static int sched_recv = 0;
        if (sched_recv < 10 || (sched_recv % 300 == 0)) {
            fprintf(stderr, "[R2-SCHED] received event #%d: msg=0x%08X\n", sched_recv, msg);
            fflush(stderr);
        }
        sched_recv++;
    }
    // 0x8005C9AC: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8005C9B0: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8005C9B4: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8005C9B8: beq         $v0, $zero, L_8005C998
    if (ctx->r2 == 0) {
        // 0x8005C9BC: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8005C998;
    }
    // 0x8005C9BC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005C9C0: addu        $v0, $v0, $s0
    gpr jr_addend_8005C9C8 = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8005C9C4: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x8005C9C8: jr          $v0
    // 0x8005C9CC: nop

    switch (jr_addend_8005C9C8 >> 2) {
        case 0: goto L_8005C9D0; break;
        case 1: goto L_8005C9E0; break;
        case 2: goto L_8005C9F0; break;
        case 3: goto L_8005CA00; break;
        case 4: goto L_8005CA10; break;
        default: switch_error(__func__, 0x8005C9C8, 0x800C1E00);
    }
    // 0x8005C9CC: nop

L_8005C9D0:
    // 0x8005C9D0: jal         0x8005CA90
    // 0x8005C9D4: nop

    func_8005CA90(rdram, ctx);
        goto after_1;
    // 0x8005C9D4: nop

    after_1:
    // 0x8005C9D8: j           L_8005C998
    // 0x8005C9DC: nop

        goto L_8005C998;
    // 0x8005C9DC: nop

L_8005C9E0:
    // 0x8005C9E0: jal         0x8005CB80
    // 0x8005C9E4: nop

    func_8005CB80(rdram, ctx);
        goto after_2;
    // 0x8005C9E4: nop

    after_2:
    // 0x8005C9E8: j           L_8005C998
    // 0x8005C9EC: nop

        goto L_8005C998;
    // 0x8005C9EC: nop

L_8005C9F0:
    // 0x8005C9F0: jal         0x8005CC5C
    // 0x8005C9F4: nop

    func_8005CC5C(rdram, ctx);
        goto after_3;
    // 0x8005C9F4: nop

    after_3:
    // 0x8005C9F8: j           L_8005C998
    // 0x8005C9FC: nop

        goto L_8005C998;
    // 0x8005C9FC: nop

L_8005CA00:
    // 0x8005CA00: jal         0x8005CD94
    // 0x8005CA04: nop

    func_8005CD94(rdram, ctx);
        goto after_4;
    // 0x8005CA04: nop

    after_4:
    // 0x8005CA08: j           L_8005C998
    // 0x8005CA0C: nop

        goto L_8005C998;
    // 0x8005CA0C: nop

L_8005CA10:
    // 0x8005CA10: jal         0x8005CF00
    // 0x8005CA14: nop

    func_8005CF00(rdram, ctx);
        goto after_5;
    // 0x8005CA14: nop

    after_5:
    // 0x8005CA18: j           L_8005C998
    // 0x8005CA1C: nop

        goto L_8005C998;
    // 0x8005CA1C: nop

    // 0x8005CA20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005CA24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005CA28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005CA2C: jr          $ra
    // 0x8005CA30: nop

    return;
    // 0x8005CA30: nop

;}
RECOMP_FUNC void func_8005CA34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CA34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CA38: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
L_8005CA3C:
    // FIX: On N64, Thread 2 (pri=10) gets CPU time via interrupt-driven scheduling.
    // In ultramodern's cooperative model, Thread 5 (pri=85) starves Thread 2 during
    // init because every timer message wakes Thread 5 first. When game state is 0
    // (init not complete), temporarily lower Thread 5's priority below Thread 2.
    {
        uint32_t state = *(uint32_t*)(rdram + 0xC2710);
        if (state == 0) {
            // Lower Thread 5 priority below Thread 2 (pri=10) during init
            ctx->r4 = 0; // NULL = this thread
            ctx->r5 = 1; // new priority = 1
            osSetThreadPri_recomp(rdram, ctx);
        }
    }
    // 0x8005CA3C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005CA40: addiu       $a0, $a0, 0x2568
    ctx->r4 = ADD32(ctx->r4, 0X2568);
    // 0x8005CA44: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005CA48: jal         0x80070620
    // 0x8005CA4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8005CA4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8005CA50: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8005CA54: lw          $v1, 0x2710($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2710);
    // 0x8005CA58: beq         $v1, $zero, L_8005CA3C
    if (ctx->r3 == 0) {
        // 0x8005CA5C: nop
    
            goto L_8005CA3C;
    }
    // 0x8005CA5C: nop

    // 0x8005CA60: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005CA64: lw          $v0, -0x5498($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5498);
    // 0x8005CA68: bne         $v0, $zero, L_8005CA3C
    if (ctx->r2 != 0) {
        // 0x8005CA6C: nop
    
            goto L_8005CA3C;
    }
    // 0x8005CA6C: nop

    // 0x8005CA70: jalr        $v1
    // 0x8005CA74: nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_1;
    // 0x8005CA74: nop

    after_1:
    // 0x8005CA78: j           L_8005CA3C
    // 0x8005CA7C: nop

        goto L_8005CA3C;
    // 0x8005CA7C: nop

    // 0x8005CA80: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005CA84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CA88: jr          $ra
    // 0x8005CA8C: nop

    return;
    // 0x8005CA8C: nop

;}
RECOMP_FUNC void func_8005CA90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CA90: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005CA94: lw          $v0, -0x734($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X734);
;}
RECOMP_FUNC void func_8005CA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CA98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CA9C: beq         $v0, $zero, L_8005CB38
    if (ctx->r2 == 0) {
        // 0x8005CAA0: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8005CB38;
    }
    // 0x8005CAA0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005CAA4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005CAA8: lh          $v0, 0x4748($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4748);
    // 0x8005CAAC: beq         $v0, $zero, L_8005CAC4
    if (ctx->r2 == 0) {
        // 0x8005CAB0: nop
    
            goto L_8005CAC4;
    }
    // 0x8005CAB0: nop

    // 0x8005CAB4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005CAB8: sw          $zero, -0x734($at)
    MEM_W(-0X734, ctx->r1) = 0;
    // 0x8005CABC: j           L_8005CB68
    // 0x8005CAC0: nop

        goto L_8005CB68;
    // 0x8005CAC0: nop

L_8005CAC4:
    // 0x8005CAC4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005CAC8: addiu       $a0, $a0, -0x728
    ctx->r4 = ADD32(ctx->r4, -0X728);
    // 0x8005CACC: jal         0x800720D0
    // 0x8005CAD0: nop

    func_800720D0(rdram, ctx);
        goto after_0;
    // 0x8005CAD0: nop

    after_0:
    // 0x8005CAD4: bne         $v0, $zero, L_8005CB14
    if (ctx->r2 != 0) {
        // 0x8005CAD8: nop
    
            goto L_8005CB14;
    }
    // 0x8005CAD8: nop

    // 0x8005CADC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005CAE0: sh          $zero, 0x5652($at)
    MEM_H(0X5652, ctx->r1) = 0;
    // 0x8005CAE4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005CAE8: lw          $v1, -0x34($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34);
    // 0x8005CAEC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8005CAF0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005CAF4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005CAF8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005CAFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005CB00: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005CB04: sw          $v1, -0x5AE8($at)
    MEM_W(-0X5AE8, ctx->r1) = ctx->r3;
    // 0x8005CB08: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005CB0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005CB10: sw          $v0, -0x34($at)
    MEM_W(-0X34, ctx->r1) = ctx->r2;
L_8005CB14:
    // 0x8005CB14: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005CB18: lw          $a0, -0x734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X734);
    // 0x8005CB1C: jal         0x8005CFC4
    // 0x8005CB20: nop

    func_8005CFC4(rdram, ctx);
        goto after_1;
    // 0x8005CB20: nop

    after_1:
    // 0x8005CB24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005CB28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005CB2C: sh          $v0, 0x4748($at)
    MEM_H(0X4748, ctx->r1) = ctx->r2;
    // 0x8005CB30: j           L_8005CB70
    // 0x8005CB34: nop

        goto L_8005CB70;
    // 0x8005CB34: nop

L_8005CB38:
    // 0x8005CB38: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005CB3C: lw          $v1, -0x34($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34);
    // 0x8005CB40: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8005CB44: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005CB48: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005CB4C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005CB50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005CB54: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005CB58: sw          $v1, -0x5AE8($at)
    MEM_W(-0X5AE8, ctx->r1) = ctx->r3;
    // 0x8005CB5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005CB60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005CB64: sw          $v0, -0x34($at)
    MEM_W(-0X34, ctx->r1) = ctx->r2;
L_8005CB68:
    // 0x8005CB68: jal         0x8005CF98
    // 0x8005CB6C: nop

    func_8005CF98(rdram, ctx);
        goto after_2;
    // 0x8005CB6C: nop

    after_2:
L_8005CB70:
    // 0x8005CB70: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005CB74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CB78: jr          $ra
    // 0x8005CB7C: nop

    return;
    // 0x8005CB7C: nop

;}
RECOMP_FUNC void func_8005CB80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CB80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CB84: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005CB88: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8005CB8C: lw          $s0, -0x5490($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X5490);
    // 0x8005CB90: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8005CB94: lw          $v1, -0x730($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X730);
    // 0x8005CB98: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005CB9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CBA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005CBA4: sw          $v0, -0x5490($at)
    MEM_W(-0X5490, ctx->r1) = ctx->r2;
    // 0x8005CBA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005CBAC: sw          $s0, -0x5638($at)
    MEM_W(-0X5638, ctx->r1) = ctx->r16;
    // 0x8005CBB0: beq         $v1, $zero, L_8005CC28
    if (ctx->r3 == 0) {
        // 0x8005CBB4: addiu       $v0, $zero, 0x190
        ctx->r2 = ADD32(0, 0X190);
            goto L_8005CC28;
    }
    // 0x8005CBB4: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
    // 0x8005CBB8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005CBBC: lw          $a0, -0x72C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72C);
    // 0x8005CBC0: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x8005CBC4: lw          $v1, 0x300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X300);
    // 0x8005CBC8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005CBCC: sw          $zero, -0x730($at)
    MEM_W(-0X730, ctx->r1) = 0;
    // 0x8005CBD0: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x8005CBD4: addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // 0x8005CBD8: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
    // 0x8005CBDC: addiu       $v0, $zero, 0x320
    ctx->r2 = ADD32(0, 0X320);
    // 0x8005CBE0: bne         $v1, $zero, L_8005CBFC
    if (ctx->r3 != 0) {
        // 0x8005CBE4: sw          $v0, 0x28($a0)
        MEM_W(0X28, ctx->r4) = ctx->r2;
            goto L_8005CBFC;
    }
    // 0x8005CBE4: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x8005CBE8: lui         $v1, 0x32
    ctx->r3 = S32(0X32 << 16);
    // 0x8005CBEC: ori         $v1, $v1, 0x258
    ctx->r3 = ctx->r3 | 0X258;
    // 0x8005CBF0: addiu       $v0, $zero, 0x358
    ctx->r2 = ADD32(0, 0X358);
    // 0x8005CBF4: sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    // 0x8005CBF8: sw          $v1, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r3;
L_8005CBFC:
    // 0x8005CBFC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005CC00: lw          $a0, -0x72C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72C);
    // 0x8005CC04: jal         0x800721C0
    // 0x8005CC08: nop

    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x8005CC08: nop

    after_0:
    // 0x8005CC0C: jal         0x80072210
    // 0x8005CC10: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_1;
    // 0x8005CC10: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    after_1:
    // 0x8005CC14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005CC18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005CC1C: sh          $v0, 0x475C($at)
    MEM_H(0X475C, ctx->r1) = ctx->r2;
    // 0x8005CC20: jal         0x800723D0
    // 0x8005CC24: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    osViBlack_recomp(rdram, ctx);
        goto after_2;
    // 0x8005CC24: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
L_8005CC28:
    // 0x8005CC28: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8005CC2C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005CC30: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8005CC34: lw          $a0, 0x528($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X528);
    // 0x8005CC38: jal         0x80072380
    // 0x8005CC3C: nop

    osViSwapBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x8005CC3C: nop

    after_3:
    // 0x8005CC40: jal         0x8005CF98
    // 0x8005CC44: nop

    func_8005CF98(rdram, ctx);
        goto after_4;
    // 0x8005CC44: nop

    after_4:
    // 0x8005CC48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005CC4C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005CC50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CC54: jr          $ra
    // 0x8005CC58: nop

    return;
    // 0x8005CC58: nop

;}
RECOMP_FUNC void func_8005CC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CC5C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005CC60: lw          $v0, -0x73C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X73C);
;}
RECOMP_FUNC void func_8005CC64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CC64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CC68: beq         $v0, $zero, L_8005CC88
    if (ctx->r2 == 0) {
        // 0x8005CC6C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8005CC88;
    }
    // 0x8005CC6C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005CC70: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005CC74: sw          $v0, -0x738($at)
    MEM_W(-0X738, ctx->r1) = ctx->r2;
    // 0x8005CC78: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005CC7C: sw          $zero, -0x73C($at)
    MEM_W(-0X73C, ctx->r1) = 0;
    // 0x8005CC80: jal         0x8005CD94
    // 0x8005CC84: nop

    func_8005CD94(rdram, ctx);
        goto after_0;
    // 0x8005CC84: nop

    after_0:
L_8005CC88:
    // 0x8005CC88: jal         0x80072120
    // 0x8005CC8C: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x8005CC8C: nop

    after_1:
    // 0x8005CC90: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005CC94: lw          $v1, 0x528($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X528);
    // 0x8005CC98: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005CC9C: bne         $a0, $v1, L_8005CCAC
    if (ctx->r4 != ctx->r3) {
        // 0x8005CCA0: nop
    
            goto L_8005CCAC;
    }
    // 0x8005CCA0: nop

    // 0x8005CCA4: j           L_8005CCC4
    // 0x8005CCA8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_8005CCC4;
    // 0x8005CCA8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8005CCAC:
    // 0x8005CCAC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005CCB0: lw          $v0, 0x530($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X530);
    // 0x8005CCB4: xor         $v0, $a0, $v0
    ctx->r2 = ctx->r4 ^ ctx->r2;
    // 0x8005CCB8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8005CCBC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8005CCC0: ori         $a0, $v0, 0x1
    ctx->r4 = ctx->r2 | 0X1;
L_8005CCC4:
    // 0x8005CCC4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005CCC8: lw          $v0, 0x3EE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3EE4);
    // 0x8005CCCC: beq         $a0, $v0, L_8005CD1C
    if (ctx->r4 == ctx->r2) {
        // 0x8005CCD0: nop
    
            goto L_8005CD1C;
    }
    // 0x8005CCD0: nop

    // 0x8005CCD4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005CCD8: lw          $v0, 0x3EE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3EE4);
    // 0x8005CCDC: bltz        $v0, L_8005CD04
    if (SIGNED(ctx->r2) < 0) {
        // 0x8005CCE0: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8005CD04;
    }
    // 0x8005CCE0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005CCE4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005CCE8: lw          $v0, 0x3EE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3EE4);
    // 0x8005CCEC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005CCF0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005CCF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005CCF8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005CCFC: sw          $v1, 0x52C($at)
    MEM_W(0X52C, ctx->r1) = ctx->r3;
    // 0x8005CD00: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005CD04:
    // 0x8005CD04: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005CD08: sw          $a0, 0x3EE4($at)
    MEM_W(0X3EE4, ctx->r1) = ctx->r4;
    // 0x8005CD0C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005CD10: sw          $v0, -0x5638($at)
    MEM_W(-0X5638, ctx->r1) = ctx->r2;
    // 0x8005CD14: jal         0x8005CF98
    // 0x8005CD18: nop

    func_8005CF98(rdram, ctx);
        goto after_2;
    // 0x8005CD18: nop

    after_2:
L_8005CD1C:
    // 0x8005CD1C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005CD20: lw          $v0, -0x740($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X740);
    // 0x8005CD24: beq         $v0, $zero, L_8005CD3C
    if (ctx->r2 == 0) {
        // 0x8005CD28: nop
    
            goto L_8005CD3C;
    }
    // 0x8005CD28: nop

    // 0x8005CD2C: jal         0x8006201C
    // 0x8005CD30: nop

    func_8006201C(rdram, ctx);
        goto after_3;
    // 0x8005CD30: nop

    after_3:
    // 0x8005CD34: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005CD38: sw          $v0, -0x73C($at)
    MEM_W(-0X73C, ctx->r1) = ctx->r2;
L_8005CD3C:
    // 0x8005CD3C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005CD40: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x8005CD44: beq         $v0, $zero, L_8005CD74
    if (ctx->r2 == 0) {
        // 0x8005CD48: nop
    
            goto L_8005CD74;
    }
    // 0x8005CD48: nop

    // 0x8005CD4C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8005CD50: lw          $v1, 0x2710($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2710);
    // 0x8005CD54: beq         $v1, $zero, L_8005CD74
    if (ctx->r3 == 0) {
        // 0x8005CD58: nop
    
            goto L_8005CD74;
    }
    // 0x8005CD58: nop

    // 0x8005CD5C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005CD60: lw          $v0, -0x5498($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5498);
    // 0x8005CD64: bne         $v0, $zero, L_8005CD74
    if (ctx->r2 != 0) {
        // 0x8005CD68: nop
    
            goto L_8005CD74;
    }
    // 0x8005CD68: nop

    // 0x8005CD6C: jalr        $v1
    // 0x8005CD70: nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_4;
    // 0x8005CD70: nop

    after_4:
L_8005CD74:
    // 0x8005CD74: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005CD78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CD7C: jr          $ra
    // 0x8005CD80: nop

    return;
    // 0x8005CD80: nop

;}
RECOMP_FUNC void func_8005CD84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    fprintf(stderr, "[R2-STATE] Setting game state to 0x%08X\n", (uint32_t)ctx->r4);
    fflush(stderr);
    // 0x8005CD84: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005CD88: sw          $a0, 0x2710($at)
    MEM_W(0X2710, ctx->r1) = ctx->r4;
    // 0x8005CD8C: jr          $ra
    // 0x8005CD90: nop

    return;
    // 0x8005CD90: nop

;}
RECOMP_FUNC void func_8005CD94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CD94: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005CD98: lw          $v0, -0x734($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X734);
;}
RECOMP_FUNC void func_8005CD9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CD9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CDA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CDA4: bne         $v0, $zero, L_8005CEEC
    if (ctx->r2 != 0) {
        // 0x8005CDA8: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8005CEEC;
    }
    // 0x8005CDA8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005CDAC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005CDB0: lw          $a0, -0x738($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X738);
    // 0x8005CDB4: beq         $a0, $zero, L_8005CE14
    if (ctx->r4 == 0) {
        // 0x8005CDB8: nop
    
            goto L_8005CE14;
    }
    // 0x8005CDB8: nop

    // 0x8005CDBC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005CDC0: lw          $v0, -0x34($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34);
    // 0x8005CDC4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005CDC8: sw          $a0, -0x734($at)
    MEM_W(-0X734, ctx->r1) = ctx->r4;
    // 0x8005CDCC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005CDD0: sw          $zero, -0x738($at)
    MEM_W(-0X738, ctx->r1) = 0;
    // 0x8005CDD4: bltz        $v0, L_8005CDFC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8005CDD8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005CDFC;
    }
    // 0x8005CDD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005CDDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005CDE0: sh          $v0, 0x5652($at)
    MEM_H(0X5652, ctx->r1) = ctx->r2;
    // 0x8005CDE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005CDE8: sh          $zero, 0x4748($at)
    MEM_H(0X4748, ctx->r1) = 0;
    // 0x8005CDEC: jal         0x800720B0
    // 0x8005CDF0: nop

    func_800720B0(rdram, ctx);
        goto after_0;
    // 0x8005CDF0: nop

    after_0:
    // 0x8005CDF4: j           L_8005CEEC
    // 0x8005CDF8: nop

        goto L_8005CEEC;
    // 0x8005CDF8: nop

L_8005CDFC:
    // 0x8005CDFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005CE00: sh          $v0, 0x4748($at)
    MEM_H(0X4748, ctx->r1) = ctx->r2;
    // 0x8005CE04: jal         0x8005CFC4
    // 0x8005CE08: nop

    func_8005CFC4(rdram, ctx);
        goto after_1;
    // 0x8005CE08: nop

    after_1:
    // 0x8005CE0C: j           L_8005CEEC
    // 0x8005CE10: nop

        goto L_8005CEEC;
    // 0x8005CE10: nop

L_8005CE14:
    // 0x8005CE14: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005CE18: lhu         $v0, 0x5652($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X5652);
    // 0x8005CE1C: beq         $v0, $zero, L_8005CE94
    if (ctx->r2 == 0) {
        // 0x8005CE20: nop
    
            goto L_8005CE94;
    }
    // 0x8005CE20: nop

    // 0x8005CE24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005CE28: sh          $zero, 0x5652($at)
    MEM_H(0X5652, ctx->r1) = 0;
    // 0x8005CE2C: j           L_8005CE7C
    // 0x8005CE30: nop

        goto L_8005CE7C;
    // 0x8005CE30: nop

L_8005CE34:
    // 0x8005CE34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005CE38: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8005CE3C: sw          $zero, 0x52C($at)
    MEM_W(0X52C, ctx->r1) = 0;
    // 0x8005CE40: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005CE44: lw          $v0, 0x94($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X94);
    // 0x8005CE48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005CE4C: sw          $v0, -0x34($at)
    MEM_W(-0X34, ctx->r1) = ctx->r2;
    // 0x8005CE50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005CE54: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005CE58: sw          $a0, -0x5490($at)
    MEM_W(-0X5490, ctx->r1) = ctx->r4;
    // 0x8005CE5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005CE60: sw          $v0, 0x94($at)
    MEM_W(0X94, ctx->r1) = ctx->r2;
    // 0x8005CE64: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005CE68: lw          $a0, -0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X34);
    // 0x8005CE6C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8005CE70: addiu       $s0, $s0, -0x724
    ctx->r16 = ADD32(ctx->r16, -0X724);
    // 0x8005CE74: jal         0x8005CFFC
    // 0x8005CE78: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    func_8005CFFC(rdram, ctx);
        goto after_2;
    // 0x8005CE78: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    after_2:
L_8005CE7C:
    // 0x8005CE7C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005CE80: addiu       $a0, $a0, -0x728
    ctx->r4 = ADD32(ctx->r4, -0X728);
    // 0x8005CE84: jal         0x8005CFC4
    // 0x8005CE88: nop

    func_8005CFC4(rdram, ctx);
        goto after_3;
    // 0x8005CE88: nop

    after_3:
    // 0x8005CE8C: j           L_8005CEEC
    // 0x8005CE90: nop

        goto L_8005CEEC;
    // 0x8005CE90: nop

L_8005CE94:
    // 0x8005CE94: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005CE98: lw          $v0, -0x5490($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5490);
    // 0x8005CE9C: bgez        $v0, L_8005CEEC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005CEA0: nop
    
            goto L_8005CEEC;
    }
    // 0x8005CEA0: nop

    // 0x8005CEA4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005CEA8: lw          $v0, -0x34($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34);
    // 0x8005CEAC: bgez        $v0, L_8005CEEC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005CEB0: nop
    
            goto L_8005CEEC;
    }
    // 0x8005CEB0: nop

    // 0x8005CEB4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005CEB8: lw          $v0, 0x94($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X94);
    // 0x8005CEBC: bltz        $v0, L_8005CEEC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8005CEC0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8005CEEC;
    }
    // 0x8005CEC0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005CEC4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005CEC8:
    // 0x8005CEC8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005CECC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005CED0: lw          $v0, 0x52C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52C);
    // 0x8005CED4: bne         $v0, $zero, L_8005CE34
    if (ctx->r2 != 0) {
        // 0x8005CED8: nop
    
            goto L_8005CE34;
    }
    // 0x8005CED8: nop

    // 0x8005CEDC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005CEE0: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8005CEE4: bne         $v0, $zero, L_8005CEC8
    if (ctx->r2 != 0) {
        // 0x8005CEE8: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8005CEC8;
    }
    // 0x8005CEE8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_8005CEEC:
    // 0x8005CEEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005CEF0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005CEF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CEF8: jr          $ra
    // 0x8005CEFC: nop

    return;
    // 0x8005CEFC: nop

;}
RECOMP_FUNC void func_8005CF00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CF00: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x8005CF04: lw          $v1, 0x300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X300);
;}
RECOMP_FUNC void func_8005CF08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CF08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CF0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005CF10: bne         $v1, $v0, L_8005CF28
    if (ctx->r3 != ctx->r2) {
        // 0x8005CF14: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8005CF28;
    }
    // 0x8005CF14: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005CF18: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005CF1C: addiu       $a0, $a0, 0x10C0
    ctx->r4 = ADD32(ctx->r4, 0X10C0);
    // 0x8005CF20: j           L_8005CF44
    // 0x8005CF24: nop

        goto L_8005CF44;
    // 0x8005CF24: nop

L_8005CF28:
    // 0x8005CF28: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005CF2C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005CF30: addiu       $a0, $a0, 0x1520
    ctx->r4 = ADD32(ctx->r4, 0X1520);
    // 0x8005CF34: bne         $v1, $v0, L_8005CF44
    if (ctx->r3 != ctx->r2) {
        // 0x8005CF38: nop
    
            goto L_8005CF44;
    }
    // 0x8005CF38: nop

    // 0x8005CF3C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8005CF40: addiu       $a0, $a0, 0x1980
    ctx->r4 = ADD32(ctx->r4, 0X1980);
L_8005CF44:
    // 0x8005CF44: jal         0x800721C0
    // 0x8005CF48: nop

    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x8005CF48: nop

    after_0:
    // 0x8005CF4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005CF50: sh          $zero, 0x475C($at)
    MEM_H(0X475C, ctx->r1) = 0;
    // 0x8005CF54: jal         0x800723D0
    // 0x8005CF58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_1;
    // 0x8005CF58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8005CF5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005CF60: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005CF64: sw          $v0, -0x5498($at)
    MEM_W(-0X5498, ctx->r1) = ctx->r2;
    // 0x8005CF68: jal         0x80064168
    // 0x8005CF6C: nop

    func_80064168(rdram, ctx);
        goto after_2;
    // 0x8005CF6C: nop

    after_2:
    // 0x8005CF70: jal         0x80061274
    // 0x8005CF74: nop

    func_80061274(rdram, ctx);
        goto after_3;
    // 0x8005CF74: nop

    after_3:
    // 0x8005CF78: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8005CF7C: addiu       $a0, $a0, 0x2CD0
    ctx->r4 = ADD32(ctx->r4, 0X2CD0);
    // 0x8005CF80: jal         0x80070AA0
    // 0x8005CF84: nop

    osStopThread_recomp(rdram, ctx);
        goto after_4;
    // 0x8005CF84: nop

    after_4:
    // 0x8005CF88: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005CF8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CF90: jr          $ra
    // 0x8005CF94: nop

    return;
    // 0x8005CF94: nop

;}
RECOMP_FUNC void func_8005CF98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CF98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CF9C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005CFA0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005CFA4: addiu       $a0, $a0, -0x6908
    ctx->r4 = ADD32(ctx->r4, -0X6908);
    // 0x8005CFA8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005CFAC: jal         0x80070750
    // 0x8005CFB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8005CFB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8005CFB4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005CFB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CFBC: jr          $ra
    // 0x8005CFC0: nop

    return;
    // 0x8005CFC0: nop

;}
RECOMP_FUNC void func_8005CFC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CFC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CFC8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005CFCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CFD0: jal         0x80070460
    // 0x8005CFD4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x8005CFD4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8005CFD8: jal         0x80071E70
    // 0x8005CFDC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80071E70(rdram, ctx);
        goto after_1;
    // 0x8005CFDC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8005CFE0: jal         0x8007207C
    // 0x8005CFE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8007207C(rdram, ctx);
        goto after_2;
    // 0x8005CFE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8005CFE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005CFEC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005CFF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CFF4: jr          $ra
    // 0x8005CFF8: nop

    return;
    // 0x8005CFF8: nop

;}
RECOMP_FUNC void func_8005CFFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CFFC: sll         $a1, $a0, 1
    ctx->r5 = S32(ctx->r4 << 1);
    // 0x8005D000: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x8005D004: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8005D008: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005D00C: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x8005D010: lw          $a0, -0x5AF0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5AF0);
    // 0x8005D014: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005D018: lw          $v0, -0x5490($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5490);
    // 0x8005D01C: lui         $v1, 0xBC00
    ctx->r3 = S32(0XBC00 << 16);
    // 0x8005D020: ori         $v1, $v1, 0x806
    ctx->r3 = ctx->r3 | 0X806;
    // 0x8005D024: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005D028: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8005D02C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005D030: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005D034: lw          $v0, 0x528($at)
    ctx->r2 = MEM_W(ctx->r1, 0X528);
    // 0x8005D038: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x8005D03C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005D040: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8005D044: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8005D048: addiu       $v0, $v0, -0x19F0
    ctx->r2 = ADD32(ctx->r2, -0X19F0);
    // 0x8005D04C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8005D050: addiu       $v1, $v1, -0x1AC0
    ctx->r3 = ADD32(ctx->r3, -0X1AC0);
    // 0x8005D054: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005D058: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005D05C: sw          $v0, -0x71C($at)
    MEM_W(-0X71C, ctx->r1) = ctx->r2;
    // 0x8005D060: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005D064: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8005D068: lw          $v0, -0x5AF0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5AF0);
    // 0x8005D06C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005D070: sw          $v0, -0x6F8($at)
    MEM_W(-0X6F8, ctx->r1) = ctx->r2;
    // 0x8005D074: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005D078: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8005D07C: lw          $v1, -0x5AEC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5AEC);
    // 0x8005D080: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8005D084: addiu       $v0, $v0, -0x1050
    ctx->r2 = ADD32(ctx->r2, -0X1050);
    // 0x8005D088: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005D08C: sw          $v0, -0x6FC($at)
    MEM_W(-0X6FC, ctx->r1) = ctx->r2;
    // 0x8005D090: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005D094: sw          $v1, -0x6F4($at)
    MEM_W(-0X6F4, ctx->r1) = ctx->r3;
    // 0x8005D098: jr          $ra
    // 0x8005D09C: nop

    return;
    // 0x8005D09C: nop

;}
