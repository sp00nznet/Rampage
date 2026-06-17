#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_80010DB0(uint8_t* rdram, recomp_context* ctx);
void func_80010F24(uint8_t* rdram, recomp_context* ctx);
void func_80010FB8(uint8_t* rdram, recomp_context* ctx);
void func_80011034(uint8_t* rdram, recomp_context* ctx);
void func_8001123C(uint8_t* rdram, recomp_context* ctx);
void func_80011288(uint8_t* rdram, recomp_context* ctx);
void func_80011458(uint8_t* rdram, recomp_context* ctx);
void func_80011544(uint8_t* rdram, recomp_context* ctx);
void func_80011584(uint8_t* rdram, recomp_context* ctx);
void func_80011624(uint8_t* rdram, recomp_context* ctx);
void func_8001167C(uint8_t* rdram, recomp_context* ctx);
void func_80011A28(uint8_t* rdram, recomp_context* ctx);
void func_80011A3C(uint8_t* rdram, recomp_context* ctx);
void func_80011E88(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80010890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010890: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80010894: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80010898: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8001089C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800108A0: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800108A4: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800108A8: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800108AC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800108B0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800108B4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800108B8: lhu         $v0, 0x6($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X6);
    // 0x800108BC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800108C0: addiu       $a0, $a0, 0x31C0
    ctx->r4 = ADD32(ctx->r4, 0X31C0);
    // 0x800108C4: lw          $s5, 0x0($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X0);
    // 0x800108C8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800108CC: bne         $v0, $zero, L_800108DC
    if (ctx->r2 != 0) {
        // 0x800108D0: nop
    
            goto L_800108DC;
    }
    // 0x800108D0: nop

    // 0x800108D4: bne         $s4, $zero, L_800109E8
    if (ctx->r20 != 0) {
        // 0x800108D8: nop
    
            goto L_800109E8;
    }
    // 0x800108D8: nop

L_800108DC:
    // 0x800108DC: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    // 0x800108E0: beq         $v1, $zero, L_800109E0
    if (ctx->r3 == 0) {
        // 0x800108E4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800109E0;
    }
    // 0x800108E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800108E8: bne         $v1, $v0, L_80010904
    if (ctx->r3 != ctx->r2) {
        // 0x800108EC: nop
    
            goto L_80010904;
    }
    // 0x800108EC: nop

    // 0x800108F0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800108F4: jal         0x8000F648
    // 0x800108F8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8000F648(rdram, ctx);
        goto after_0;
    // 0x800108F8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_0:
    // 0x800108FC: j           L_800109E0
    // 0x80010900: nop

        goto L_800109E0;
    // 0x80010900: nop

L_80010904:
    // 0x80010904: lw          $s1, 0x8($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X8);
    // 0x80010908: beq         $s4, $zero, L_80010928
    if (ctx->r20 == 0) {
        // 0x8001090C: nop
    
            goto L_80010928;
    }
    // 0x8001090C: nop

    // 0x80010910: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    // 0x80010914: sltu        $v0, $s2, $v0
    ctx->r2 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x80010918: bne         $v0, $zero, L_80010928
    if (ctx->r2 != 0) {
        // 0x8001091C: nop
    
            goto L_80010928;
    }
    // 0x8001091C: nop

    // 0x80010920: j           L_800109E8
    // 0x80010924: sw          $s5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r21;
        goto L_800109E8;
    // 0x80010924: sw          $s5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r21;
L_80010928:
    // 0x80010928: lhu         $v0, 0x76($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X76);
    // 0x8001092C: beq         $v0, $zero, L_80010940
    if (ctx->r2 == 0) {
        // 0x80010930: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80010940;
    }
    // 0x80010930: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80010934: lhu         $v0, 0x12($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X12);
    // 0x80010938: j           L_800109E0
    // 0x8001093C: sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
        goto L_800109E0;
    // 0x8001093C: sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
L_80010940:
    // 0x80010940: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x80010944: bne         $v1, $v0, L_8001095C
    if (ctx->r3 != ctx->r2) {
        // 0x80010948: addiu       $s3, $zero, 0x3C
        ctx->r19 = ADD32(0, 0X3C);
            goto L_8001095C;
    }
    // 0x80010948: addiu       $s3, $zero, 0x3C
    ctx->r19 = ADD32(0, 0X3C);
    // 0x8001094C: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80010950: addiu       $s0, $s0, 0x4294
    ctx->r16 = ADD32(ctx->r16, 0X4294);
    // 0x80010954: j           L_80010964
    // 0x80010958: addiu       $s3, $zero, 0x28
    ctx->r19 = ADD32(0, 0X28);
        goto L_80010964;
    // 0x80010958: addiu       $s3, $zero, 0x28
    ctx->r19 = ADD32(0, 0X28);
L_8001095C:
    // 0x8001095C: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80010960: addiu       $s0, $s0, 0x42E4
    ctx->r16 = ADD32(ctx->r16, 0X42E4);
L_80010964:
    // 0x80010964: jal         0x800306EC
    // 0x80010968: nop

    func_800306EC(rdram, ctx);
        goto after_1;
    // 0x80010968: nop

    after_1:
    // 0x8001096C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80010970: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x80010974: sw          $s0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r16;
    // 0x80010978: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8001097C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80010980: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80010984: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80010988: sw          $a0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r4;
    // 0x8001098C: lhu         $v1, 0x14($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X14);
    // 0x80010990: addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // 0x80010994: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x80010998: lhu         $v1, 0x18($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X18);
    // 0x8001099C: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x800109A0: lhu         $v1, 0x8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X8);
    // 0x800109A4: addiu       $v1, $v1, 0x11
    ctx->r3 = ADD32(ctx->r3, 0X11);
    // 0x800109A8: jal         0x80023E44
    // 0x800109AC: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_2;
    // 0x800109AC: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    after_2:
    // 0x800109B0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800109B4: sw          $s2, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->r18;
    // 0x800109B8: sw          $s4, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->r20;
    // 0x800109BC: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x800109C0: beq         $a0, $zero, L_800109E0
    if (ctx->r4 == 0) {
        // 0x800109C4: nop
    
            goto L_800109E0;
    }
    // 0x800109C4: nop

    // 0x800109C8: lhu         $v1, 0xA($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XA);
    // 0x800109CC: lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4);
    // 0x800109D0: bne         $v1, $v0, L_800109E0
    if (ctx->r3 != ctx->r2) {
        // 0x800109D4: nop
    
            goto L_800109E0;
    }
    // 0x800109D4: nop

    // 0x800109D8: jal         0x800107A8
    // 0x800109DC: nop

    func_800107A8(rdram, ctx);
        goto after_3;
    // 0x800109DC: nop

    after_3:
L_800109E0:
    // 0x800109E0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800109E4: sw          $s5, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r21;
L_800109E8:
    // 0x800109E8: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800109EC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800109F0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800109F4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800109F8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800109FC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80010A00: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80010A04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80010A08: jr          $ra
    // 0x80010A0C: nop

    return;
    // 0x80010A0C: nop

;}
RECOMP_FUNC void func_80010A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010A10: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80010A14: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80010A10 falls into func_80010A18
    func_80010A18(rdram, ctx);
;}
RECOMP_FUNC void func_80010A18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010A18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80010A1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80010A20: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80010A24: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80010A28: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80010A2C: lw          $s0, 0x90($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X90);
    // 0x80010A30: lw          $s2, 0x94($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X94);
    // 0x80010A34: lw          $s1, 0x8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X8);
    // 0x80010A38: sltu        $v0, $zero, $s2
    ctx->r2 = 0 < ctx->r18 ? 1 : 0;
    // 0x80010A3C: sltu        $v1, $zero, $s1
    ctx->r3 = 0 < ctx->r17 ? 1 : 0;
    // 0x80010A40: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80010A44: beq         $v0, $zero, L_80010A8C
    if (ctx->r2 == 0) {
        // 0x80010A48: nop
    
            goto L_80010A8C;
    }
    // 0x80010A48: nop

    // 0x80010A4C: lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X14);
    // 0x80010A50: sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x80010A54: beq         $v0, $zero, L_80010AC0
    if (ctx->r2 == 0) {
        // 0x80010A58: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80010AC0;
    }
    // 0x80010A58: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80010A5C: lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X10);
    // 0x80010A60: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80010A64: jal         0x8003D6D0
    // 0x80010A68: sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
    func_8003D6D0(rdram, ctx);
        goto after_0;
    // 0x80010A68: sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
    after_0:
    // 0x80010A6C: jal         0x8003D5C8
    // 0x80010A70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003D5C8(rdram, ctx);
        goto after_1;
    // 0x80010A70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80010A74: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80010A78: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80010A7C: jal         0x8000F1EC
    // 0x80010A80: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8000F1EC(rdram, ctx);
        goto after_2;
    // 0x80010A80: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80010A84: j           L_80010AC0
    // 0x80010A88: nop

        goto L_80010AC0;
    // 0x80010A88: nop

L_80010A8C:
    // 0x80010A8C: jal         0x800324EC
    // 0x80010A90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800324EC(rdram, ctx);
        goto after_3;
    // 0x80010A90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80010A94: jal         0x8003D5E4
    // 0x80010A98: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003D5E4(rdram, ctx);
        goto after_4;
    // 0x80010A98: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80010A9C: jal         0x8003D6D0
    // 0x80010AA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003D6D0(rdram, ctx);
        goto after_5;
    // 0x80010AA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80010AA4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80010AA8: beq         $a0, $zero, L_80010AB8
    if (ctx->r4 == 0) {
        // 0x80010AAC: nop
    
            goto L_80010AB8;
    }
    // 0x80010AAC: nop

    // 0x80010AB0: jal         0x80024764
    // 0x80010AB4: nop

    func_80024764(rdram, ctx);
        goto after_6;
    // 0x80010AB4: nop

    after_6:
L_80010AB8:
    // 0x80010AB8: jal         0x8003DB44
    // 0x80010ABC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003DB44(rdram, ctx);
        goto after_7;
    // 0x80010ABC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
L_80010AC0:
    // 0x80010AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80010AC4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80010AC8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80010ACC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80010AD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80010AD4: jr          $ra
    // 0x80010AD8: nop

    return;
    // 0x80010AD8: nop

;}
RECOMP_FUNC void func_80010ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010ADC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80010AE0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80010AE4: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x80010AE8: addiu       $s2, $s2, 0x31C0
    ctx->r18 = ADD32(ctx->r18, 0X31C0);
    // 0x80010AEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80010AF0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80010AF4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80010AF8: lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X0);
    // 0x80010AFC: beq         $s0, $zero, L_80010B6C
    if (ctx->r16 == 0) {
        // 0x80010B00: nop
    
            goto L_80010B6C;
    }
    // 0x80010B00: nop

    // 0x80010B04: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80010B08: beq         $v0, $zero, L_80010B6C
    if (ctx->r2 == 0) {
        // 0x80010B0C: nop
    
            goto L_80010B6C;
    }
    // 0x80010B0C: nop

    // 0x80010B10: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80010B14: beq         $v0, $zero, L_80010B6C
    if (ctx->r2 == 0) {
        // 0x80010B18: nop
    
            goto L_80010B6C;
    }
    // 0x80010B18: nop

    // 0x80010B1C: lw          $s0, 0x90($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X90);
    // 0x80010B20: lhu         $a1, 0x4($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X4);
    // 0x80010B24: jal         0x80001414
    // 0x80010B28: addiu       $a0, $a1, 0x5ABC
    ctx->r4 = ADD32(ctx->r5, 0X5ABC);
    func_80001414(rdram, ctx);
        goto after_0;
    // 0x80010B28: addiu       $a0, $a1, 0x5ABC
    ctx->r4 = ADD32(ctx->r5, 0X5ABC);
    after_0:
    // 0x80010B2C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80010B30: addiu       $a0, $a0, 0x44F4
    ctx->r4 = ADD32(ctx->r4, 0X44F4);
    // 0x80010B34: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80010B38: beq         $v0, $zero, L_80010B48
    if (ctx->r2 == 0) {
        // 0x80010B3C: nop
    
            goto L_80010B48;
    }
    // 0x80010B3C: nop

    // 0x80010B40: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80010B44: addiu       $a0, $a0, 0x4554
    ctx->r4 = ADD32(ctx->r4, 0X4554);
L_80010B48:
    // 0x80010B48: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80010B4C: lhu         $a1, 0x18($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X18);
    // 0x80010B50: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80010B54: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80010B58: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80010B5C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80010B60: jal         0x8001011C
    // 0x80010B64: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_8001011C(rdram, ctx);
        goto after_1;
    // 0x80010B64: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_1:
    // 0x80010B68: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
L_80010B6C:
    // 0x80010B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80010B70: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80010B74: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80010B78: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80010B7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80010B80: jr          $ra
    // 0x80010B84: nop

    return;
    // 0x80010B84: nop

;}
RECOMP_FUNC void func_80010B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010B88: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80010B8C: addiu       $v1, $v1, 0x41B0
    ctx->r3 = ADD32(ctx->r3, 0X41B0);
    // 0x80010B90: sltu        $v0, $a1, $v1
    ctx->r2 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80010B94: bne         $v0, $zero, L_80010BB4
    if (ctx->r2 != 0) {
        // 0x80010B98: addiu       $v0, $v1, 0xCA8
        ctx->r2 = ADD32(ctx->r3, 0XCA8);
            goto L_80010BB4;
    }
    // 0x80010B98: addiu       $v0, $v1, 0xCA8
    ctx->r2 = ADD32(ctx->r3, 0XCA8);
    // 0x80010B9C: sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80010BA0: bne         $v0, $zero, L_80010BB4
    if (ctx->r2 != 0) {
        // 0x80010BA4: nop
    
            goto L_80010BB4;
    }
    // 0x80010BA4: nop

    // 0x80010BA8: lhu         $v0, 0x26($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X26);
    // 0x80010BAC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80010BB0: sh          $v0, 0x26($a1)
    MEM_H(0X26, ctx->r5) = ctx->r2;
L_80010BB4:
    // 0x80010BB4: jr          $ra
    // 0x80010BB8: nop

    return;
    // 0x80010BB8: nop

;}
RECOMP_FUNC void func_80010BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010BBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80010BC0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80010BC4: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80010BC8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80010BCC: addiu       $v1, $v1, 0x41B0
    ctx->r3 = ADD32(ctx->r3, 0X41B0);
    // 0x80010BD0: sltu        $v0, $s0, $v1
    ctx->r2 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80010BD4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80010BD8: bne         $v0, $zero, L_80010C78
    if (ctx->r2 != 0) {
        // 0x80010BDC: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_80010C78;
    }
    // 0x80010BDC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80010BE0: addiu       $v0, $v1, 0xCA8
    ctx->r2 = ADD32(ctx->r3, 0XCA8);
    // 0x80010BE4: sltu        $v0, $v0, $s0
    ctx->r2 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x80010BE8: bne         $v0, $zero, L_80010C78
    if (ctx->r2 != 0) {
        // 0x80010BEC: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_80010C78;
    }
    // 0x80010BEC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80010BF0: sltiu       $v0, $a0, 0x4
    ctx->r2 = ctx->r4 < 0X4 ? 1 : 0;
    // 0x80010BF4: beq         $v0, $zero, L_80010C08
    if (ctx->r2 == 0) {
        // 0x80010BF8: addiu       $s1, $zero, 0xA
        ctx->r17 = ADD32(0, 0XA);
            goto L_80010C08;
    }
    // 0x80010BF8: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x80010BFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80010C00: j           L_80010C64
    // 0x80010C04: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
        goto L_80010C64;
    // 0x80010C04: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80010C08:
    // 0x80010C08: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80010C0C: beq         $a0, $v0, L_80010C58
    if (ctx->r4 == ctx->r2) {
        // 0x80010C10: slti        $v0, $a0, 0x7
        ctx->r2 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
            goto L_80010C58;
    }
    // 0x80010C10: slti        $v0, $a0, 0x7
    ctx->r2 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x80010C14: beq         $v0, $zero, L_80010C2C
    if (ctx->r2 == 0) {
        // 0x80010C18: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80010C2C;
    }
    // 0x80010C18: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80010C1C: beq         $a0, $v0, L_80010C40
    if (ctx->r4 == ctx->r2) {
        // 0x80010C20: addiu       $s1, $zero, 0x14
        ctx->r17 = ADD32(0, 0X14);
            goto L_80010C40;
    }
    // 0x80010C20: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
    // 0x80010C24: j           L_80010C78
    // 0x80010C28: nop

        goto L_80010C78;
    // 0x80010C28: nop

L_80010C2C:
    // 0x80010C2C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80010C30: beq         $a0, $v0, L_80010C4C
    if (ctx->r4 == ctx->r2) {
        // 0x80010C34: addiu       $s1, $zero, 0x14
        ctx->r17 = ADD32(0, 0X14);
            goto L_80010C4C;
    }
    // 0x80010C34: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
    // 0x80010C38: j           L_80010C78
    // 0x80010C3C: nop

        goto L_80010C78;
    // 0x80010C3C: nop

L_80010C40:
    // 0x80010C40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80010C44: j           L_80010C64
    // 0x80010C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80010C64;
    // 0x80010C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80010C4C:
    // 0x80010C4C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80010C50: j           L_80010C64
    // 0x80010C54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80010C64;
    // 0x80010C54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80010C58:
    // 0x80010C58: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x80010C5C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80010C60: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80010C64:
    // 0x80010C64: jal         0x80060F30
    // 0x80010C68: nop

    func_80060F30(rdram, ctx);
        goto after_0;
    // 0x80010C68: nop

    after_0:
    // 0x80010C6C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80010C70: jal         0x8003C34C
    // 0x80010C74: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003C34C(rdram, ctx);
        goto after_1;
    // 0x80010C74: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
L_80010C78:
    // 0x80010C78: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80010C7C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80010C80: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80010C84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80010C88: jr          $ra
    // 0x80010C8C: nop

    return;
    // 0x80010C8C: nop

;}
RECOMP_FUNC void func_80010C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80010C94: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80010C98: jal         0x8004C79C
    // 0x80010C9C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_8004C79C(rdram, ctx);
        goto after_0;
    // 0x80010C9C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_0:
    // 0x80010CA0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80010CA4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80010CA8: lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X90);
    // 0x80010CAC: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80010CB0: jal         0x80032B14
    // 0x80010CB4: nop

    func_80032B14(rdram, ctx);
        goto after_1;
    // 0x80010CB4: nop

    after_1:
    // 0x80010CB8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80010CBC: lhu         $v0, 0x14($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X14);
    // 0x80010CC0: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x80010CC4: beq         $v0, $zero, L_80010CD0
    if (ctx->r2 == 0) {
        // 0x80010CC8: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_80010CD0;
    }
    // 0x80010CC8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80010CCC: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
L_80010CD0:
    // 0x80010CD0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80010CD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80010CD8: jr          $ra
    // 0x80010CDC: nop

    return;
    // 0x80010CDC: nop

;}
RECOMP_FUNC void func_80010CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010CE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80010CE4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80010CE8: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80010CEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010CF0: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
    // 0x80010CF4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80010CF8: addiu       $v1, $v1, 0x5068
    ctx->r3 = ADD32(ctx->r3, 0X5068);
    // 0x80010CFC: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80010D00: bne         $v0, $zero, L_80010D10
    if (ctx->r2 != 0) {
        // 0x80010D04: nop
    
            goto L_80010D10;
    }
    // 0x80010D04: nop

    // 0x80010D08: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80010D0C: addiu       $v1, $v1, 0x5010
    ctx->r3 = ADD32(ctx->r3, 0X5010);
L_80010D10:
    // 0x80010D10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80010D14: beq         $v0, $zero, L_80010D9C
    if (ctx->r2 == 0) {
        // 0x80010D18: nop
    
            goto L_80010D9C;
    }
    // 0x80010D18: nop

L_80010D1C:
    // 0x80010D1C: beq         $v0, $a1, L_80010D30
    if (ctx->r2 == ctx->r5) {
        // 0x80010D20: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80010D30;
    }
    // 0x80010D20: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80010D24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80010D28: bne         $v0, $zero, L_80010D1C
    if (ctx->r2 != 0) {
        // 0x80010D2C: nop
    
            goto L_80010D1C;
    }
    // 0x80010D2C: nop

L_80010D30:
    // 0x80010D30: beq         $v0, $zero, L_80010D9C
    if (ctx->r2 == 0) {
        // 0x80010D34: nop
    
            goto L_80010D9C;
    }
    // 0x80010D34: nop

    // 0x80010D38: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
    // 0x80010D3C: beq         $v0, $zero, L_80010D54
    if (ctx->r2 == 0) {
        // 0x80010D40: nop
    
            goto L_80010D54;
    }
    // 0x80010D40: nop

    // 0x80010D44: jal         0x8000CD10
    // 0x80010D48: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8000CD10(rdram, ctx);
        goto after_0;
    // 0x80010D48: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80010D4C: j           L_80010D9C
    // 0x80010D50: nop

        goto L_80010D9C;
    // 0x80010D50: nop

L_80010D54:
    // 0x80010D54: lw          $v1, 0x70($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X70);
    // 0x80010D58: beq         $v1, $zero, L_80010D9C
    if (ctx->r3 == 0) {
        // 0x80010D5C: nop
    
            goto L_80010D9C;
    }
    // 0x80010D5C: nop

    // 0x80010D60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80010D64: beq         $v0, $zero, L_80010D9C
    if (ctx->r2 == 0) {
        // 0x80010D68: nop
    
            goto L_80010D9C;
    }
    // 0x80010D68: nop

    // 0x80010D6C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80010D70: beq         $v0, $zero, L_80010D9C
    if (ctx->r2 == 0) {
        // 0x80010D74: nop
    
            goto L_80010D9C;
    }
    // 0x80010D74: nop

    // 0x80010D78: jal         0x8000F16C
    // 0x80010D7C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8000F16C(rdram, ctx);
        goto after_1;
    // 0x80010D7C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80010D80: jal         0x8004C79C
    // 0x80010D84: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_8004C79C(rdram, ctx);
        goto after_2;
    // 0x80010D84: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_2:
    // 0x80010D88: lhu         $v0, 0x78($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X78);
    // 0x80010D8C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80010D90: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80010D94: jal         0x80010DB0
    // 0x80010D98: sh          $v0, 0x78($a0)
    MEM_H(0X78, ctx->r4) = ctx->r2;
    func_80010DB0(rdram, ctx);
        goto after_3;
    // 0x80010D98: sh          $v0, 0x78($a0)
    MEM_H(0X78, ctx->r4) = ctx->r2;
    after_3:
L_80010D9C:
    // 0x80010D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010DA0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80010DA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80010DA8: jr          $ra
    // 0x80010DAC: nop

    return;
    // 0x80010DAC: nop

;}
RECOMP_FUNC void func_80010DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010DB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80010DB4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80010DB8: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80010DBC: lw          $s1, 0x31C0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X31C0);
    // 0x80010DC0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80010DC4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80010DC8: jal         0x800306EC
    // 0x80010DCC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80010DCC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80010DD0: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80010DD4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80010DD8: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x80010DDC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80010DE0: addiu       $v0, $v0, 0x4224
    ctx->r2 = ADD32(ctx->r2, 0X4224);
    // 0x80010DE4: sw          $v0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r2;
    // 0x80010DE8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80010DEC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80010DF0: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x80010DF4: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x80010DF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80010DFC: bne         $v1, $v0, L_80010E08
    if (ctx->r3 != ctx->r2) {
        // 0x80010E00: addiu       $v0, $a0, 0x3C
        ctx->r2 = ADD32(ctx->r4, 0X3C);
            goto L_80010E08;
    }
    // 0x80010E00: addiu       $v0, $a0, 0x3C
    ctx->r2 = ADD32(ctx->r4, 0X3C);
    // 0x80010E04: addiu       $v0, $a0, 0x28
    ctx->r2 = ADD32(ctx->r4, 0X28);
L_80010E08:
    // 0x80010E08: sh          $v0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r2;
    // 0x80010E0C: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x80010E10: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80010E14: lhu         $v0, 0x30($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X30);
    // 0x80010E18: lhu         $v1, 0x18($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X18);
    // 0x80010E1C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80010E20: sra         $v0, $v0, 17
    ctx->r2 = S32(SIGNED(ctx->r2) >> 17);
    // 0x80010E24: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80010E28: sh          $v1, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r3;
    // 0x80010E2C: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80010E30: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // 0x80010E34: jal         0x80023E44
    // 0x80010E38: sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x80010E38: sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
    after_1:
    // 0x80010E3C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80010E40: sw          $s1, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r17;
    // 0x80010E44: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80010E48: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80010E4C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80010E50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80010E54: jr          $ra
    // 0x80010E58: nop

    return;
    // 0x80010E58: nop

;}
RECOMP_FUNC void func_80010E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010E5C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80010E60: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80010E64: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80010E68: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80010E6C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80010E70: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80010E74: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80010E78: jr          $ra
    // 0x80010E7C: addiu       $v0, $v0, 0x44
    ctx->r2 = ADD32(ctx->r2, 0X44);
    return;
    // 0x80010E7C: addiu       $v0, $v0, 0x44
    ctx->r2 = ADD32(ctx->r2, 0X44);
;}
RECOMP_FUNC void func_80010E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010E80: jr          $ra
    // 0x80010E84: nop

    return;
    // 0x80010E84: nop

    // 0x80010E88: nop

    // 0x80010E8C: nop

;}
RECOMP_FUNC void func_80010E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80010E94: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80010E98: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80010E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010EA0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80010EA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80010EA8: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x80010EAC: jal         0x80011A3C
    // 0x80010EB0: nop

    func_80011A3C(rdram, ctx);
        goto after_0;
    // 0x80010EB0: nop

    after_0:
    // 0x80010EB4: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x80010EB8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80010EBC: beq         $v1, $v0, L_80010F08
    if (ctx->r3 == ctx->r2) {
        // 0x80010EC0: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_80010F08;
    }
    // 0x80010EC0: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80010EC4: beq         $v0, $zero, L_80010EDC
    if (ctx->r2 == 0) {
        // 0x80010EC8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80010EDC;
    }
    // 0x80010EC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80010ECC: beq         $v1, $v0, L_80010EF8
    if (ctx->r3 == ctx->r2) {
        // 0x80010ED0: nop
    
            goto L_80010EF8;
    }
    // 0x80010ED0: nop

    // 0x80010ED4: j           L_80010F10
    // 0x80010ED8: nop

        goto L_80010F10;
    // 0x80010ED8: nop

L_80010EDC:
    // 0x80010EDC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80010EE0: bne         $v1, $v0, L_80010F10
    if (ctx->r3 != ctx->r2) {
        // 0x80010EE4: nop
    
            goto L_80010F10;
    }
    // 0x80010EE4: nop

    // 0x80010EE8: jal         0x80011624
    // 0x80010EEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80011624(rdram, ctx);
        goto after_1;
    // 0x80010EEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80010EF0: j           L_80010F10
    // 0x80010EF4: nop

        goto L_80010F10;
    // 0x80010EF4: nop

L_80010EF8:
    // 0x80010EF8: jal         0x80011544
    // 0x80010EFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80011544(rdram, ctx);
        goto after_2;
    // 0x80010EFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80010F00: j           L_80010F10
    // 0x80010F04: nop

        goto L_80010F10;
    // 0x80010F04: nop

L_80010F08:
    // 0x80010F08: jal         0x80010F24
    // 0x80010F0C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80010F24(rdram, ctx);
        goto after_3;
    // 0x80010F0C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
L_80010F10:
    // 0x80010F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010F14: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80010F18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80010F1C: jr          $ra
    // 0x80010F20: nop

    return;
    // 0x80010F20: nop

;}
RECOMP_FUNC void func_80010F24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010F24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80010F28: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80010F2C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80010F30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010F34: lhu         $v1, 0xA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XA);
    // 0x80010F38: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80010F3C: bne         $v1, $v0, L_80010F54
    if (ctx->r3 != ctx->r2) {
        // 0x80010F40: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80010F54;
    }
    // 0x80010F40: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80010F44: jal         0x8002A5F0
    // 0x80010F48: nop

    func_8002A5F0(rdram, ctx);
        goto after_0;
    // 0x80010F48: nop

    after_0:
    // 0x80010F4C: j           L_80010FA4
    // 0x80010F50: nop

        goto L_80010FA4;
    // 0x80010F50: nop

L_80010F54:
    // 0x80010F54: bne         $v1, $v0, L_80010F6C
    if (ctx->r3 != ctx->r2) {
        // 0x80010F58: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80010F6C;
    }
    // 0x80010F58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80010F5C: jal         0x8001167C
    // 0x80010F60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001167C(rdram, ctx);
        goto after_1;
    // 0x80010F60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80010F64: j           L_80010FA4
    // 0x80010F68: nop

        goto L_80010FA4;
    // 0x80010F68: nop

L_80010F6C:
    // 0x80010F6C: bne         $v1, $v0, L_80010F9C
    if (ctx->r3 != ctx->r2) {
        // 0x80010F70: nop
    
            goto L_80010F9C;
    }
    // 0x80010F70: nop

    // 0x80010F74: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80010F78: beq         $v0, $zero, L_80010F9C
    if (ctx->r2 == 0) {
        // 0x80010F7C: nop
    
            goto L_80010F9C;
    }
    // 0x80010F7C: nop

    // 0x80010F80: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x80010F84: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80010F88: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80010F8C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80010F90: addiu       $a0, $a0, -0x2EBC
    ctx->r4 = ADD32(ctx->r4, -0X2EBC);
    // 0x80010F94: jal         0x80037DDC
    // 0x80010F98: nop

    func_80037DDC(rdram, ctx);
        goto after_2;
    // 0x80010F98: nop

    after_2:
L_80010F9C:
    // 0x80010F9C: jal         0x80010FB8
    // 0x80010FA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80010FB8(rdram, ctx);
        goto after_3;
    // 0x80010FA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
L_80010FA4:
    // 0x80010FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010FA8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80010FAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80010FB0: jr          $ra
    // 0x80010FB4: nop

    return;
    // 0x80010FB4: nop

;}
RECOMP_FUNC void func_80010FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010FB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80010FBC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80010FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010FC4: jal         0x8002A5F0
    // 0x80010FC8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8002A5F0(rdram, ctx);
        goto after_0;
    // 0x80010FC8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80010FCC: jal         0x80011288
    // 0x80010FD0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80011288(rdram, ctx);
        goto after_1;
    // 0x80010FD0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80010FD4: jal         0x80011034
    // 0x80010FD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80011034(rdram, ctx);
        goto after_2;
    // 0x80010FD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80010FDC: jal         0x80011458
    // 0x80010FE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80011458(rdram, ctx);
        goto after_3;
    // 0x80010FE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80010FE4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80010FE8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80010FEC: bne         $v0, $v1, L_8001101C
    if (ctx->r2 != ctx->r3) {
        // 0x80010FF0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001101C;
    }
    // 0x80010FF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80010FF4: lhu         $v0, 0x4E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4E);
    // 0x80010FF8: beq         $v0, $zero, L_80011020
    if (ctx->r2 == 0) {
        // 0x80010FFC: nop
    
            goto L_80011020;
    }
    // 0x80010FFC: nop

    // 0x80011000: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011004: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011008: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x8001100C: xori        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 ^ 0X10;
    // 0x80011010: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x80011014: j           L_80011020
    // 0x80011018: sh          $zero, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = 0;
        goto L_80011020;
    // 0x80011018: sh          $zero, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = 0;
L_8001101C:
    // 0x8001101C: sh          $v0, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r2;
L_80011020:
    // 0x80011020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011024: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80011028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001102C: jr          $ra
    // 0x80011030: nop

    return;
    // 0x80011030: nop

;}
RECOMP_FUNC void func_80011034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011034: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80011038: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8001103C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80011040: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80011044: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
    // 0x80011048: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8001104C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80011050: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80011054: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80011058: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001105C: andi        $v1, $s3, 0xFFFF
    ctx->r3 = ctx->r19 & 0XFFFF;
L_80011060:
    // 0x80011060: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80011064: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80011068: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8001106C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80011070: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80011074: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80011078: addiu       $v1, $v1, 0x3F94
    ctx->r3 = ADD32(ctx->r3, 0X3F94);
    // 0x8001107C: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x80011080: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
    // 0x80011084: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80011088: beq         $v0, $zero, L_80011208
    if (ctx->r2 == 0) {
        // 0x8001108C: addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
            goto L_80011208;
    }
    // 0x8001108C: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x80011090: lhu         $v0, 0xDC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XDC);
    // 0x80011094: beq         $v0, $zero, L_80011208
    if (ctx->r2 == 0) {
        // 0x80011098: addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
            goto L_80011208;
    }
    // 0x80011098: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x8001109C: lhu         $v0, 0xA($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XA);
    // 0x800110A0: lw          $s1, 0x68($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X68);
    // 0x800110A4: beq         $v0, $s4, L_800110B8
    if (ctx->r2 == ctx->r20) {
        // 0x800110A8: nop
    
            goto L_800110B8;
    }
    // 0x800110A8: nop

    // 0x800110AC: lhu         $v0, 0x1B0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B0);
    // 0x800110B0: bne         $v0, $zero, L_80011208
    if (ctx->r2 != 0) {
        // 0x800110B4: addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
            goto L_80011208;
    }
    // 0x800110B4: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
L_800110B8:
    // 0x800110B8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800110BC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800110C0: lh          $a0, 0x14($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X14);
    // 0x800110C4: lh          $a1, 0x14($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X14);
    // 0x800110C8: jal         0x8003F1F0
    // 0x800110CC: nop

    func_8003F1F0(rdram, ctx);
        goto after_0;
    // 0x800110CC: nop

    after_0:
    // 0x800110D0: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800110D4: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x800110D8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800110DC: bltzl       $v0, L_800110F8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800110E0: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_800110F8;
    }
    goto skip_0;
    // 0x800110E0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_0:
    // 0x800110E4: slti        $v0, $v0, 0x31
    ctx->r2 = SIGNED(ctx->r2) < 0X31 ? 1 : 0;
    // 0x800110E8: bne         $v0, $zero, L_80011104
    if (ctx->r2 != 0) {
        // 0x800110EC: addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
            goto L_80011104;
    }
    // 0x800110EC: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x800110F0: j           L_80011208
    // 0x800110F4: nop

        goto L_80011208;
    // 0x800110F4: nop

L_800110F8:
    // 0x800110F8: slti        $v0, $v0, 0x31
    ctx->r2 = SIGNED(ctx->r2) < 0X31 ? 1 : 0;
    // 0x800110FC: beq         $v0, $zero, L_80011208
    if (ctx->r2 == 0) {
        // 0x80011100: addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
            goto L_80011208;
    }
    // 0x80011100: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
L_80011104:
    // 0x80011104: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011108: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8001110C: lhu         $v0, 0x30($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X30);
    // 0x80011110: lhu         $a0, 0x18($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X18);
    // 0x80011114: lhu         $v1, 0x30($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X30);
    // 0x80011118: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001111C: sra         $v0, $v0, 17
    ctx->r2 = S32(SIGNED(ctx->r2) >> 17);
    // 0x80011120: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
    // 0x80011124: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80011128: lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18);
    // 0x8001112C: sra         $a2, $v1, 16
    ctx->r6 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80011130: sra         $v1, $v1, 17
    ctx->r3 = S32(SIGNED(ctx->r3) >> 17);
    // 0x80011134: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80011138: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001113C: subu        $a1, $v0, $v1
    ctx->r5 = SUB32(ctx->r2, ctx->r3);
    // 0x80011140: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80011144: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80011148: slt         $a0, $a0, $v0
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001114C: bne         $a0, $zero, L_80011190
    if (ctx->r4 != 0) {
        // 0x80011150: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_80011190;
    }
    // 0x80011150: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80011154: sra         $a1, $v0, 16
    ctx->r5 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80011158: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x8001115C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80011160: subu        $a0, $a1, $v0
    ctx->r4 = SUB32(ctx->r5, ctx->r2);
    // 0x80011164: bltz        $a0, L_80011180
    if (SIGNED(ctx->r4) < 0) {
        // 0x80011168: addiu       $v1, $a2, -0x4
        ctx->r3 = ADD32(ctx->r6, -0X4);
            goto L_80011180;
    }
    // 0x80011168: addiu       $v1, $a2, -0x4
    ctx->r3 = ADD32(ctx->r6, -0X4);
    // 0x8001116C: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80011170: beq         $v0, $zero, L_80011190
    if (ctx->r2 == 0) {
        // 0x80011174: addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
            goto L_80011190;
    }
    // 0x80011174: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x80011178: j           L_80011208
    // 0x8001117C: nop

        goto L_80011208;
    // 0x8001117C: nop

L_80011180:
    // 0x80011180: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80011184: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80011188: bne         $v0, $zero, L_80011208
    if (ctx->r2 != 0) {
        // 0x8001118C: addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
            goto L_80011208;
    }
    // 0x8001118C: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
L_80011190:
    // 0x80011190: lhu         $a2, 0xA($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0XA);
    // 0x80011194: bne         $a2, $s4, L_800111AC
    if (ctx->r6 != ctx->r20) {
        // 0x80011198: addiu       $v0, $zero, 0xE1
        ctx->r2 = ADD32(0, 0XE1);
            goto L_800111AC;
    }
    // 0x80011198: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x8001119C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x800111A0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800111A4: j           L_800111FC
    // 0x800111A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800111FC;
    // 0x800111A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800111AC:
    // 0x800111AC: lh          $v1, 0x18($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X18);
    // 0x800111B0: beq         $v1, $v0, L_800111CC
    if (ctx->r3 == ctx->r2) {
        // 0x800111B4: nop
    
            goto L_800111CC;
    }
    // 0x800111B4: nop

    // 0x800111B8: jal         0x80015268
    // 0x800111BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80015268(rdram, ctx);
        goto after_1;
    // 0x800111BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800111C0: lhu         $a2, 0xA($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0XA);
    // 0x800111C4: j           L_800111F8
    // 0x800111C8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_800111F8;
    // 0x800111C8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800111CC:
    // 0x800111CC: lhu         $v0, 0x22($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X22);
    // 0x800111D0: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800111D4: bne         $v0, $zero, L_800111EC
    if (ctx->r2 != 0) {
        // 0x800111D8: sll         $v0, $t0, 16
        ctx->r2 = S32(ctx->r8 << 16);
            goto L_800111EC;
    }
    // 0x800111D8: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x800111DC: bgez        $v0, L_800111F8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800111E0: addiu       $a0, $zero, 0x22
        ctx->r4 = ADD32(0, 0X22);
            goto L_800111F8;
    }
    // 0x800111E0: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x800111E4: j           L_800111F8
    // 0x800111E8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
        goto L_800111F8;
    // 0x800111E8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_800111EC:
    // 0x800111EC: bgtz        $v0, L_800111F8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800111F0: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_800111F8;
    }
    // 0x800111F0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800111F4: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
L_800111F8:
    // 0x800111F8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_800111FC:
    // 0x800111FC: jal         0x8001123C
    // 0x80011200: nop

    func_8001123C(rdram, ctx);
        goto after_2;
    // 0x80011200: nop

    after_2:
    // 0x80011204: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
L_80011208:
    // 0x80011208: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8001120C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80011210: bne         $v0, $zero, L_80011060
    if (ctx->r2 != 0) {
        // 0x80011214: andi        $v1, $s3, 0xFFFF
        ctx->r3 = ctx->r19 & 0XFFFF;
            goto L_80011060;
    }
    // 0x80011214: andi        $v1, $s3, 0xFFFF
    ctx->r3 = ctx->r19 & 0XFFFF;
    // 0x80011218: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001121C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80011220: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80011224: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80011228: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8001122C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80011230: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80011234: jr          $ra
    // 0x80011238: nop

    return;
    // 0x80011238: nop

;}
RECOMP_FUNC void func_8001123C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001123C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011240: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80011244: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80011248: beq         $a0, $zero, L_8001125C
    if (ctx->r4 == 0) {
        // 0x8001124C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8001125C;
    }
    // 0x8001124C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80011250: lw          $v0, 0x68($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X68);
    // 0x80011254: sh          $a3, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r7;
    // 0x80011258: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
L_8001125C:
    // 0x8001125C: andi        $v1, $a2, 0xFFFF
    ctx->r3 = ctx->r6 & 0XFFFF;
    // 0x80011260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80011264: bne         $v1, $v0, L_80011270
    if (ctx->r3 != ctx->r2) {
        // 0x80011268: lui         $a0, 0x6
        ctx->r4 = S32(0X6 << 16);
            goto L_80011270;
    }
    // 0x80011268: lui         $a0, 0x6
    ctx->r4 = S32(0X6 << 16);
    // 0x8001126C: lui         $a0, 0xC
    ctx->r4 = S32(0XC << 16);
L_80011270:
    // 0x80011270: jal         0x8003BA80
    // 0x80011274: nop

    func_8003BA80(rdram, ctx);
        goto after_0;
    // 0x80011274: nop

    after_0:
    // 0x80011278: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001127C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80011280: jr          $ra
    // 0x80011284: nop

    return;
    // 0x80011284: nop

;}
RECOMP_FUNC void func_80011288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011288: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001128C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80011290: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80011294: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80011298: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
    // 0x8001129C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800112A0: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x800112A4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800112A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800112AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800112B0: andi        $v1, $s3, 0xFFFF
    ctx->r3 = ctx->r19 & 0XFFFF;
L_800112B4:
    // 0x800112B4: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800112B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800112BC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800112C0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800112C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800112C8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800112CC: addiu       $v1, $v1, 0x3F94
    ctx->r3 = ADD32(ctx->r3, 0X3F94);
    // 0x800112D0: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // 0x800112D4: lhu         $v0, 0x58($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X58);
    // 0x800112D8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800112DC: beq         $v0, $zero, L_80011424
    if (ctx->r2 == 0) {
        // 0x800112E0: addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
            goto L_80011424;
    }
    // 0x800112E0: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x800112E4: lhu         $a0, 0xA($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0XA);
    // 0x800112E8: xori        $v1, $a0, 0x1
    ctx->r3 = ctx->r4 ^ 0X1;
    // 0x800112EC: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x800112F0: xori        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 ^ 0X3;
    // 0x800112F4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800112F8: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800112FC: beq         $v1, $zero, L_80011424
    if (ctx->r3 == 0) {
        // 0x80011300: addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
            goto L_80011424;
    }
    // 0x80011300: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x80011304: beql        $a0, $s4, L_80011428
    if (ctx->r4 == ctx->r20) {
        // 0x80011308: addu        $s3, $v0, $zero
        ctx->r19 = ADD32(ctx->r2, 0);
            goto L_80011428;
    }
    goto skip_0;
    // 0x80011308: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    skip_0:
    // 0x8001130C: lhu         $a0, 0x5A($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X5A);
    // 0x80011310: xori        $v1, $a0, 0x4E
    ctx->r3 = ctx->r4 ^ 0X4E;
    // 0x80011314: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80011318: xori        $v0, $a0, 0x2
    ctx->r2 = ctx->r4 ^ 0X2;
    // 0x8001131C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80011320: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80011324: bne         $v1, $zero, L_80011334
    if (ctx->r3 != 0) {
        // 0x80011328: addiu       $v0, $zero, 0x2C
        ctx->r2 = ADD32(0, 0X2C);
            goto L_80011334;
    }
    // 0x80011328: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // 0x8001132C: bne         $a0, $v0, L_80011424
    if (ctx->r4 != ctx->r2) {
        // 0x80011330: addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
            goto L_80011424;
    }
    // 0x80011330: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
L_80011334:
    // 0x80011334: lw          $s0, 0x68($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X68);
    // 0x80011338: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x8001133C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80011340: ori         $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 | 0X7FFF;
    // 0x80011344: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80011348: beq         $v0, $zero, L_80011424
    if (ctx->r2 == 0) {
        // 0x8001134C: addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
            goto L_80011424;
    }
    // 0x8001134C: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x80011350: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011354: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80011358: lh          $a0, 0x14($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X14);
    // 0x8001135C: lh          $a1, 0x14($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X14);
    // 0x80011360: jal         0x8003F1F0
    // 0x80011364: nop

    func_8003F1F0(rdram, ctx);
        goto after_0;
    // 0x80011364: nop

    after_0:
    // 0x80011368: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001136C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80011370: bltzl       $v0, L_8001138C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80011374: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_8001138C;
    }
    goto skip_1;
    // 0x80011374: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_1:
    // 0x80011378: slti        $v0, $v0, 0x29
    ctx->r2 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x8001137C: bne         $v0, $zero, L_80011398
    if (ctx->r2 != 0) {
        // 0x80011380: addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
            goto L_80011398;
    }
    // 0x80011380: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x80011384: j           L_80011424
    // 0x80011388: nop

        goto L_80011424;
    // 0x80011388: nop

L_8001138C:
    // 0x8001138C: slti        $v0, $v0, 0x29
    ctx->r2 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x80011390: beq         $v0, $zero, L_80011424
    if (ctx->r2 == 0) {
        // 0x80011394: addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
            goto L_80011424;
    }
    // 0x80011394: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
L_80011398:
    // 0x80011398: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8001139C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800113A0: lhu         $v0, 0x30($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X30);
    // 0x800113A4: lhu         $v1, 0x18($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X18);
    // 0x800113A8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800113AC: sra         $v0, $v0, 17
    ctx->r2 = S32(SIGNED(ctx->r2) >> 17);
    // 0x800113B0: srl         $a2, $v0, 1
    ctx->r6 = S32(U32(ctx->r2) >> 1);
    // 0x800113B4: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // 0x800113B8: lh          $v1, 0x18($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X18);
    // 0x800113BC: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x800113C0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800113C4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800113C8: bltz        $v0, L_800113D8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800113CC: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_800113D8;
    }
    // 0x800113CC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800113D0: j           L_800113DC
    // 0x800113D4: subu        $v1, $a1, $a0
    ctx->r3 = SUB32(ctx->r5, ctx->r4);
        goto L_800113DC;
    // 0x800113D4: subu        $v1, $a1, $a0
    ctx->r3 = SUB32(ctx->r5, ctx->r4);
L_800113D8:
    // 0x800113D8: subu        $v1, $a0, $a1
    ctx->r3 = SUB32(ctx->r4, ctx->r5);
L_800113DC:
    // 0x800113DC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800113E0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800113E4: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x800113E8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800113EC: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800113F0: bne         $v0, $zero, L_80011424
    if (ctx->r2 != 0) {
        // 0x800113F4: addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
            goto L_80011424;
    }
    // 0x800113F4: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x800113F8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800113FC: jal         0x80047540
    // 0x80011400: sh          $s4, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r20;
    func_80047540(rdram, ctx);
        goto after_1;
    // 0x80011400: sh          $s4, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r20;
    after_1:
    // 0x80011404: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80011408: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8001140C: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80011410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80011414: sh          $s4, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r20;
    // 0x80011418: sh          $v0, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r2;
    // 0x8001141C: j           L_80011434
    // 0x80011420: sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
        goto L_80011434;
    // 0x80011420: sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
L_80011424:
    // 0x80011424: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_80011428:
    // 0x80011428: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8001142C: bne         $v0, $zero, L_800112B4
    if (ctx->r2 != 0) {
        // 0x80011430: andi        $v1, $s3, 0xFFFF
        ctx->r3 = ctx->r19 & 0XFFFF;
            goto L_800112B4;
    }
    // 0x80011430: andi        $v1, $s3, 0xFFFF
    ctx->r3 = ctx->r19 & 0XFFFF;
L_80011434:
    // 0x80011434: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80011438: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001143C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80011440: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80011444: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80011448: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001144C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80011450: jr          $ra
    // 0x80011454: nop

    return;
    // 0x80011454: nop

;}
RECOMP_FUNC void func_80011458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011458: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8001145C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80011458 falls into func_80011460
    func_80011460(rdram, ctx);
;}
RECOMP_FUNC void func_80011460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011460: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011464: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80011468: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8001146C: addiu       $s0, $s0, 0x46A8
    ctx->r16 = ADD32(ctx->r16, 0X46A8);
    // 0x80011470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011474: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80011478: lh          $a0, 0x14($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X14);
    // 0x8001147C: jal         0x8003F1F0
    // 0x80011480: nop

    func_8003F1F0(rdram, ctx);
        goto after_0;
    // 0x80011480: nop

    after_0:
    // 0x80011484: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80011488: addiu       $v0, $v1, 0x12C
    ctx->r2 = ADD32(ctx->r3, 0X12C);
    // 0x8001148C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80011490: sltiu       $v0, $v0, 0x12C
    ctx->r2 = ctx->r2 < 0X12C ? 1 : 0;
    // 0x80011494: bne         $v0, $zero, L_800114FC
    if (ctx->r2 != 0) {
        // 0x80011498: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_800114FC;
    }
    // 0x80011498: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8001149C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800114A0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800114A4: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x800114A8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800114AC: lhu         $a1, 0x3294($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X3294);
    // 0x800114B0: lh          $a0, 0x14($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X14);
    // 0x800114B4: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, 0X190);
    // 0x800114B8: and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    // 0x800114BC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800114C0: jal         0x8003F1F0
    // 0x800114C4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_8003F1F0(rdram, ctx);
        goto after_1;
    // 0x800114C4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_1:
    // 0x800114C8: addiu       $v0, $v0, -0x46
    ctx->r2 = ADD32(ctx->r2, -0X46);
    // 0x800114CC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800114D0: sltiu       $v0, $v0, 0xE7
    ctx->r2 = ctx->r2 < 0XE7 ? 1 : 0;
    // 0x800114D4: beq         $v0, $zero, L_80011530
    if (ctx->r2 == 0) {
        // 0x800114D8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80011530;
    }
    // 0x800114D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800114DC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800114E0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800114E4: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x800114E8: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800114EC: bne         $v0, $zero, L_80011530
    if (ctx->r2 != 0) {
        // 0x800114F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80011530;
    }
    // 0x800114F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800114F4: j           L_80011530
    // 0x800114F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80011530;
    // 0x800114F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800114FC:
    // 0x800114FC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80011500: bltzl       $v0, L_80011508
    if (SIGNED(ctx->r2) < 0) {
        // 0x80011504: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_80011508;
    }
    goto skip_0;
    // 0x80011504: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_0:
L_80011508:
    // 0x80011508: slti        $v0, $v0, 0x46
    ctx->r2 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
    // 0x8001150C: bne         $v0, $zero, L_80011530
    if (ctx->r2 != 0) {
        // 0x80011510: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80011530;
    }
    // 0x80011510: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80011514: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011518: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8001151C: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80011520: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80011524: bne         $v0, $zero, L_80011530
    if (ctx->r2 != 0) {
        // 0x80011528: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80011530;
    }
    // 0x80011528: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8001152C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80011530:
    // 0x80011530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011534: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80011538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001153C: jr          $ra
    // 0x80011540: nop

    return;
    // 0x80011540: nop

;}
RECOMP_FUNC void func_80011544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011544: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80011548: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8001154C: lh          $v0, 0x1C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X1C);
    // 0x80011550: bne         $v0, $zero, L_80011568
    if (ctx->r2 != 0) {
        // 0x80011554: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80011568;
    }
    // 0x80011554: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80011558: jal         0x80011584
    // 0x8001155C: nop

    func_80011584(rdram, ctx);
        goto after_0;
    // 0x8001155C: nop

    after_0:
    // 0x80011560: j           L_80011574
    // 0x80011564: nop

        goto L_80011574;
    // 0x80011564: nop

L_80011568:
    // 0x80011568: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8001156C: jal         0x8002E3DC
    // 0x80011570: sh          $v0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r2;
    func_8002E3DC(rdram, ctx);
        goto after_1;
    // 0x80011570: sh          $v0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r2;
    after_1:
L_80011574:
    // 0x80011574: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80011578: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001157C: jr          $ra
    // 0x80011580: nop

    return;
    // 0x80011580: nop

;}
RECOMP_FUNC void func_80011584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011584: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011588: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001158C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011590: jal         0x80011A28
    // 0x80011594: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80011A28(rdram, ctx);
        goto after_0;
    // 0x80011594: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80011598: sh          $zero, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = 0;
    // 0x8001159C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800115A0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800115A4: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x800115A8: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // 0x800115AC: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x800115B0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800115B4: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x800115B8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800115BC: lw          $v0, 0x46A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X46A8);
    // 0x800115C0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800115C4: lw          $a0, 0x3294($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3294);
    // 0x800115C8: lui         $v1, 0xFF9C
    ctx->r3 = S32(0XFF9C << 16);
    // 0x800115CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800115D0: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x800115D4: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    // 0x800115D8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800115DC: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800115E0: lui         $v0, 0xE6
    ctx->r2 = S32(0XE6 << 16);
    // 0x800115E4: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x800115E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800115EC: sh          $zero, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = 0;
    // 0x800115F0: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
    // 0x800115F4: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x800115F8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800115FC: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80011600: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80011604: addiu       $a0, $a0, -0x2EBC
    ctx->r4 = ADD32(ctx->r4, -0X2EBC);
    // 0x80011608: jal         0x80037DDC
    // 0x8001160C: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x8001160C: nop

    after_1:
    // 0x80011610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011614: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80011618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001161C: jr          $ra
    // 0x80011620: nop

    return;
    // 0x80011620: nop

;}
RECOMP_FUNC void func_80011624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011624: lhu         $a1, 0xA($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0XA);
    // 0x80011628: xori        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 ^ 0X3;
    // 0x8001162C: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80011630: xori        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 ^ 0X1;
    // 0x80011634: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80011638: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8001163C: beq         $v1, $zero, L_80011670
    if (ctx->r3 == 0) {
        // 0x80011640: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80011670;
    }
    // 0x80011640: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80011644: beq         $a1, $v0, L_80011674
    if (ctx->r5 == ctx->r2) {
        // 0x80011648: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80011674;
    }
    // 0x80011648: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001164C: lw          $v0, 0x60($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X60);
    // 0x80011650: beql        $v0, $zero, L_80011674
    if (ctx->r2 == 0) {
        // 0x80011654: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80011674;
    }
    goto skip_0;
    // 0x80011654: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80011658: lhu         $v0, 0x1B0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1B0);
    // 0x8001165C: bne         $v0, $zero, L_80011674
    if (ctx->r2 != 0) {
        // 0x80011660: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80011674;
    }
    // 0x80011660: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80011664: sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
    // 0x80011668: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x8001166C: sh          $zero, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = 0;
L_80011670:
    // 0x80011670: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80011674:
    // 0x80011674: jr          $ra
    // 0x80011678: sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
    return;
    // 0x80011678: sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8001167C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001167C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011680: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80011684: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80011688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001168C: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80011690: beq         $v0, $zero, L_800116F8
    if (ctx->r2 == 0) {
        // 0x80011694: nop
    
            goto L_800116F8;
    }
    // 0x80011694: nop

    // 0x80011698: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8001169C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800116A0: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800116A4: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800116A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800116AC: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x800116B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800116B4: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x800116B8: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x800116BC: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // 0x800116C0: sh          $zero, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = 0;
    // 0x800116C4: sh          $zero, 0x20($s0)
    MEM_H(0X20, ctx->r16) = 0;
    // 0x800116C8: sh          $zero, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = 0;
    // 0x800116CC: sh          $zero, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = 0;
    // 0x800116D0: sh          $zero, 0x22($s0)
    MEM_H(0X22, ctx->r16) = 0;
    // 0x800116D4: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x800116D8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800116DC: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x800116E0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800116E4: addiu       $a0, $a0, -0x2EBC
    ctx->r4 = ADD32(ctx->r4, -0X2EBC);
    // 0x800116E8: jal         0x80037DDC
    // 0x800116EC: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800116EC: nop

    after_0:
    // 0x800116F0: j           L_80011920
    // 0x800116F4: nop

        goto L_80011920;
    // 0x800116F4: nop

L_800116F8:
    // 0x800116F8: lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X22);
    // 0x800116FC: beq         $v0, $zero, L_80011720
    if (ctx->r2 == 0) {
        // 0x80011700: nop
    
            goto L_80011720;
    }
    // 0x80011700: nop

    // 0x80011704: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011708: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8001170C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80011710: sra         $a0, $v1, 4
    ctx->r4 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80011714: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80011718: j           L_800118E4
    // 0x8001171C: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
        goto L_800118E4;
    // 0x8001171C: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_80011720:
    // 0x80011720: lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1E);
    // 0x80011724: beq         $v0, $zero, L_80011738
    if (ctx->r2 == 0) {
        // 0x80011728: nop
    
            goto L_80011738;
    }
    // 0x80011728: nop

    // 0x8001172C: lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A);
    // 0x80011730: j           L_80011740
    // 0x80011734: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
        goto L_80011740;
    // 0x80011734: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
L_80011738:
    // 0x80011738: lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A);
    // 0x8001173C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80011740:
    // 0x80011740: sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // 0x80011744: lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A);
    // 0x80011748: sltiu       $v0, $v0, 0x15
    ctx->r2 = ctx->r2 < 0X15 ? 1 : 0;
    // 0x8001174C: bne         $v0, $zero, L_800117B4
    if (ctx->r2 != 0) {
        // 0x80011750: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800117B4;
    }
    // 0x80011750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80011754: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011758: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8001175C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80011760: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80011764: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x80011768: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x8001176C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80011770: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80011774: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80011778: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x8001177C: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // 0x80011780: sh          $zero, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = 0;
    // 0x80011784: sh          $zero, 0x20($s0)
    MEM_H(0X20, ctx->r16) = 0;
    // 0x80011788: sh          $zero, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = 0;
    // 0x8001178C: sh          $zero, 0x22($s0)
    MEM_H(0X22, ctx->r16) = 0;
    // 0x80011790: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x80011794: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80011798: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x8001179C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800117A0: addiu       $a0, $a0, -0x2EBC
    ctx->r4 = ADD32(ctx->r4, -0X2EBC);
    // 0x800117A4: jal         0x80037DDC
    // 0x800117A8: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x800117A8: nop

    after_1:
    // 0x800117AC: j           L_80011920
    // 0x800117B0: nop

        goto L_80011920;
    // 0x800117B0: nop

L_800117B4:
    // 0x800117B4: sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    // 0x800117B8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800117BC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800117C0: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800117C4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800117C8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800117CC: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800117D0: lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1E);
    // 0x800117D4: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x800117D8: beq         $v0, $zero, L_80011818
    if (ctx->r2 == 0) {
        // 0x800117DC: sw          $zero, 0x30($s0)
        MEM_W(0X30, ctx->r16) = 0;
            goto L_80011818;
    }
    // 0x800117DC: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x800117E0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800117E4: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x800117E8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800117EC: addiu       $a0, $a0, -0x2EBC
    ctx->r4 = ADD32(ctx->r4, -0X2EBC);
    // 0x800117F0: jal         0x80037DDC
    // 0x800117F4: nop

    func_80037DDC(rdram, ctx);
        goto after_2;
    // 0x800117F4: nop

    after_2:
    // 0x800117F8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800117FC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80011800: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80011804: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011808: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8001180C: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80011810: j           L_800118E0
    // 0x80011814: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
        goto L_800118E0;
    // 0x80011814: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
L_80011818:
    // 0x80011818: lhu         $v0, 0x54($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X54);
    // 0x8001181C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011820: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011824: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80011828: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8001182C: lhu         $v1, 0x22($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X22);
    // 0x80011830: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80011834: andi        $v1, $v1, 0x10
    ctx->r3 = ctx->r3 & 0X10;
    // 0x80011838: beq         $v1, $zero, L_80011850
    if (ctx->r3 == 0) {
        // 0x8001183C: ori         $v0, $v0, 0x1
        ctx->r2 = ctx->r2 | 0X1;
            goto L_80011850;
    }
    // 0x8001183C: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80011840: blez        $v0, L_80011890
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80011844: nop
    
            goto L_80011890;
    }
    // 0x80011844: nop

    // 0x80011848: j           L_80011858
    // 0x8001184C: nop

        goto L_80011858;
    // 0x8001184C: nop

L_80011850:
    // 0x80011850: bgez        $v0, L_80011890
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80011854: nop
    
            goto L_80011890;
    }
    // 0x80011854: nop

L_80011858:
    // 0x80011858: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8001185C: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80011860: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80011864: addiu       $a0, $a0, -0x2EBC
    ctx->r4 = ADD32(ctx->r4, -0X2EBC);
    // 0x80011868: jal         0x80037DDC
    // 0x8001186C: nop

    func_80037DDC(rdram, ctx);
        goto after_3;
    // 0x8001186C: nop

    after_3:
    // 0x80011870: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80011874: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80011878: lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X22);
    // 0x8001187C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80011880: beq         $v0, $zero, L_800118CC
    if (ctx->r2 == 0) {
        // 0x80011884: lui         $v1, 0xFFF9
        ctx->r3 = S32(0XFFF9 << 16);
            goto L_800118CC;
    }
    // 0x80011884: lui         $v1, 0xFFF9
    ctx->r3 = S32(0XFFF9 << 16);
    // 0x80011888: j           L_800118CC
    // 0x8001188C: lui         $v1, 0x7
    ctx->r3 = S32(0X7 << 16);
        goto L_800118CC;
    // 0x8001188C: lui         $v1, 0x7
    ctx->r3 = S32(0X7 << 16);
L_80011890:
    // 0x80011890: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80011894: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80011898: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8001189C: addiu       $a0, $a0, -0x2EBC
    ctx->r4 = ADD32(ctx->r4, -0X2EBC);
    // 0x800118A0: jal         0x80037DDC
    // 0x800118A4: nop

    func_80037DDC(rdram, ctx);
        goto after_4;
    // 0x800118A4: nop

    after_4:
    // 0x800118A8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800118AC: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x800118B0: lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X22);
    // 0x800118B4: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x800118B8: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800118BC: beq         $v0, $zero, L_800118CC
    if (ctx->r2 == 0) {
        // 0x800118C0: ori         $v1, $v1, 0x8000
        ctx->r3 = ctx->r3 | 0X8000;
            goto L_800118CC;
    }
    // 0x800118C0: ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // 0x800118C4: lui         $v1, 0xFFFE
    ctx->r3 = S32(0XFFFE << 16);
    // 0x800118C8: ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
L_800118CC:
    // 0x800118CC: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x800118D0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800118D4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800118D8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800118DC: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
L_800118E0:
    // 0x800118E0: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
L_800118E4:
    // 0x800118E4: jal         0x8002A5F0
    // 0x800118E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002A5F0(rdram, ctx);
        goto after_5;
    // 0x800118E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x800118EC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800118F0: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x800118F4: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x800118F8: lui         $v0, 0xE5
    ctx->r2 = S32(0XE5 << 16);
    // 0x800118FC: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80011900: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80011904: beq         $v0, $zero, L_80011920
    if (ctx->r2 == 0) {
        // 0x80011908: lui         $v0, 0xE6
        ctx->r2 = S32(0XE6 << 16);
            goto L_80011920;
    }
    // 0x80011908: lui         $v0, 0xE6
    ctx->r2 = S32(0XE6 << 16);
    // 0x8001190C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x80011910: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80011914: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011918: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8001191C: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
L_80011920:
    // 0x80011920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011924: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80011928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001192C: jr          $ra
    // 0x80011930: nop

    return;
    // 0x80011930: nop

;}
RECOMP_FUNC void func_80011934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011934: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011938: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8001193C: lw          $a0, 0x90($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X90);
    // 0x80011940: lui         $v0, 0xFFFD
    ctx->r2 = S32(0XFFFD << 16);
    // 0x80011944: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // 0x80011948: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8001194C: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x80011950: sw          $v0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r2;
    // 0x80011954: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80011958: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x8001195C: lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X22);
    // 0x80011960: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80011964: beq         $v0, $zero, L_80011970
    if (ctx->r2 == 0) {
        // 0x80011968: lui         $v1, 0xFFFD
        ctx->r3 = S32(0XFFFD << 16);
            goto L_80011970;
    }
    // 0x80011968: lui         $v1, 0xFFFD
    ctx->r3 = S32(0XFFFD << 16);
    // 0x8001196C: lui         $v1, 0x3
    ctx->r3 = S32(0X3 << 16);
L_80011970:
    // 0x80011970: jr          $ra
    // 0x80011974: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    return;
    // 0x80011974: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_80011978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011978: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8001197C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011980: lw          $a0, 0x90($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X90);
    // 0x80011984: lui         $v0, 0xFFFA
    ctx->r2 = S32(0XFFFA << 16);
    // 0x80011988: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // 0x8001198C: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80011990: addiu       $v0, $zero, 0x3000
    ctx->r2 = ADD32(0, 0X3000);
    // 0x80011994: sw          $v0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r2;
    // 0x80011998: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8001199C: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x800119A0: lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X22);
    // 0x800119A4: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800119A8: beq         $v0, $zero, L_800119B4
    if (ctx->r2 == 0) {
        // 0x800119AC: lui         $v1, 0xFFF9
        ctx->r3 = S32(0XFFF9 << 16);
            goto L_800119B4;
    }
    // 0x800119AC: lui         $v1, 0xFFF9
    ctx->r3 = S32(0XFFF9 << 16);
    // 0x800119B0: lui         $v1, 0x7
    ctx->r3 = S32(0X7 << 16);
L_800119B4:
    // 0x800119B4: jr          $ra
    // 0x800119B8: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    return;
    // 0x800119B8: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_800119BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800119BC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800119C0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800119C4: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x800119C8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800119CC: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
    // 0x800119D0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800119D4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800119D8: jr          $ra
    // 0x800119DC: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    return;
    // 0x800119DC: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
;}
RECOMP_FUNC void func_800119E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800119E0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800119E4: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x800119E8: lui         $v0, 0xE5
    ctx->r2 = S32(0XE5 << 16);
    // 0x800119EC: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x800119F0: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x800119F4: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x800119F8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800119FC: bne         $v0, $zero, L_80011A0C
    if (ctx->r2 != 0) {
        // 0x80011A00: nop
    
            goto L_80011A0C;
    }
    // 0x80011A00: nop

    // 0x80011A04: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80011A08: sw          $v0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r2;
L_80011A0C:
    // 0x80011A0C: jr          $ra
    // 0x80011A10: nop

    return;
    // 0x80011A10: nop

;}
RECOMP_FUNC void func_80011A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011A14: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011A18: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80011A1C: lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X90);
    // 0x80011A20: jr          $ra
    // 0x80011A24: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    return;
    // 0x80011A24: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80011A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011A28: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011A2C: addiu       $v1, $v1, 0x31C0
    ctx->r3 = ADD32(ctx->r3, 0X31C0);
    // 0x80011A30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80011A34: jr          $ra
    // 0x80011A38: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    return;
    // 0x80011A38: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80011A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011A3C: lw          $v1, 0x50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X50);
    // 0x80011A40: beq         $v1, $zero, L_80011A58
    if (ctx->r3 == 0) {
        // 0x80011A44: nop
    
            goto L_80011A58;
    }
    // 0x80011A44: nop

    // 0x80011A48: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011A4C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80011A50: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x80011A54: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_80011A58:
    // 0x80011A58: jr          $ra
    // 0x80011A5C: nop

    return;
    // 0x80011A5C: nop

;}
RECOMP_FUNC void func_80011A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011A60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80011A64: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80011A68: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80011A6C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80011A70: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011A74: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80011A78: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x80011A7C: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x80011A80: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80011A84: beq         $v1, $v0, L_80011B48
    if (ctx->r3 == ctx->r2) {
        // 0x80011A88: slti        $v0, $v1, 0x5
        ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
            goto L_80011B48;
    }
    // 0x80011A88: slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x80011A8C: beq         $v0, $zero, L_80011AAC
    if (ctx->r2 == 0) {
        // 0x80011A90: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80011AAC;
    }
    // 0x80011A90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80011A94: beq         $v1, $v0, L_80011B8C
    if (ctx->r3 == ctx->r2) {
        // 0x80011A98: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80011B8C;
    }
    // 0x80011A98: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80011A9C: beq         $v1, $v0, L_80011AE8
    if (ctx->r3 == ctx->r2) {
        // 0x80011AA0: nop
    
            goto L_80011AE8;
    }
    // 0x80011AA0: nop

    // 0x80011AA4: j           L_80011BB4
    // 0x80011AA8: nop

        goto L_80011BB4;
    // 0x80011AA8: nop

L_80011AAC:
    // 0x80011AAC: addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // 0x80011AB0: beq         $v1, $v0, L_80011E74
    if (ctx->r3 == ctx->r2) {
        // 0x80011AB4: slti        $v0, $v1, 0x34
        ctx->r2 = SIGNED(ctx->r3) < 0X34 ? 1 : 0;
            goto L_80011E74;
    }
    // 0x80011AB4: slti        $v0, $v1, 0x34
    ctx->r2 = SIGNED(ctx->r3) < 0X34 ? 1 : 0;
    // 0x80011AB8: beq         $v0, $zero, L_80011AD0
    if (ctx->r2 == 0) {
        // 0x80011ABC: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80011AD0;
    }
    // 0x80011ABC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80011AC0: beq         $v1, $v0, L_80011AE8
    if (ctx->r3 == ctx->r2) {
        // 0x80011AC4: nop
    
            goto L_80011AE8;
    }
    // 0x80011AC4: nop

    // 0x80011AC8: j           L_80011BB4
    // 0x80011ACC: nop

        goto L_80011BB4;
    // 0x80011ACC: nop

L_80011AD0:
    // 0x80011AD0: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x80011AD4: bne         $v1, $v0, L_80011BB4
    if (ctx->r3 != ctx->r2) {
        // 0x80011AD8: nop
    
            goto L_80011BB4;
    }
    // 0x80011AD8: nop

    // 0x80011ADC: lh          $v0, 0x1C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1C);
    // 0x80011AE0: j           L_80011BA0
    // 0x80011AE4: nop

        goto L_80011BA0;
    // 0x80011AE4: nop

L_80011AE8:
    // 0x80011AE8: jal         0x8004C79C
    // 0x80011AEC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_8004C79C(rdram, ctx);
        goto after_0;
    // 0x80011AEC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_0:
    // 0x80011AF0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011AF4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80011AF8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80011AFC: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80011B00: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011B04: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011B08: addiu       $v0, $zero, 0x1300
    ctx->r2 = ADD32(0, 0X1300);
    // 0x80011B0C: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
    // 0x80011B10: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80011B14: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80011B18: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x80011B1C: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // 0x80011B20: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80011B24: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80011B28: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80011B2C: addiu       $a0, $a0, 0x6000
    ctx->r4 = ADD32(ctx->r4, 0X6000);
    // 0x80011B30: jal         0x80037DDC
    // 0x80011B34: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x80011B34: nop

    after_1:
    // 0x80011B38: jal         0x80011E88
    // 0x80011B3C: nop

    func_80011E88(rdram, ctx);
        goto after_2;
    // 0x80011B3C: nop

    after_2:
    // 0x80011B40: j           L_80011E74
    // 0x80011B44: nop

        goto L_80011E74;
    // 0x80011B44: nop

L_80011B48:
    // 0x80011B48: lh          $v0, 0x1C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1C);
    // 0x80011B4C: bne         $v0, $zero, L_80011BA8
    if (ctx->r2 != 0) {
        // 0x80011B50: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80011BA8;
    }
    // 0x80011B50: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80011B54: addiu       $v0, $zero, 0xBE
    ctx->r2 = ADD32(0, 0XBE);
    // 0x80011B58: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // 0x80011B5C: addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // 0x80011B60: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80011B64: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011B68: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80011B6C: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80011B70: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x80011B74: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011B78: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80011B7C: jal         0x8000B5D0
    // 0x80011B80: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    func_8000B5D0(rdram, ctx);
        goto after_3;
    // 0x80011B80: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    after_3:
    // 0x80011B84: j           L_80011E74
    // 0x80011B88: nop

        goto L_80011E74;
    // 0x80011B88: nop

L_80011B8C:
    // 0x80011B8C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011B90: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80011B94: lui         $v1, 0x190
    ctx->r3 = S32(0X190 << 16);
    // 0x80011B98: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x80011B9C: lh          $v0, 0x1C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1C);
L_80011BA0:
    // 0x80011BA0: beq         $v0, $zero, L_80011C78
    if (ctx->r2 == 0) {
        // 0x80011BA4: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80011C78;
    }
    // 0x80011BA4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80011BA8:
    // 0x80011BA8: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80011BAC: j           L_80011E74
    // 0x80011BB0: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
        goto L_80011E74;
    // 0x80011BB0: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
L_80011BB4:
    // 0x80011BB4: lhu         $v1, 0xA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XA);
    // 0x80011BB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80011BBC: beq         $v1, $v0, L_80011C48
    if (ctx->r3 == ctx->r2) {
        // 0x80011BC0: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80011C48;
    }
    // 0x80011BC0: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80011BC4: beql        $v0, $zero, L_80011BDC
    if (ctx->r2 == 0) {
        // 0x80011BC8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80011BDC;
    }
    goto skip_0;
    // 0x80011BC8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80011BCC: beq         $v1, $zero, L_80011BF4
    if (ctx->r3 == 0) {
        // 0x80011BD0: nop
    
            goto L_80011BF4;
    }
    // 0x80011BD0: nop

    // 0x80011BD4: j           L_80011DBC
    // 0x80011BD8: nop

        goto L_80011DBC;
    // 0x80011BD8: nop

L_80011BDC:
    // 0x80011BDC: beq         $v1, $v0, L_80011CE0
    if (ctx->r3 == ctx->r2) {
        // 0x80011BE0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80011CE0;
    }
    // 0x80011BE0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80011BE4: beq         $v1, $v0, L_80011D6C
    if (ctx->r3 == ctx->r2) {
        // 0x80011BE8: nop
    
            goto L_80011D6C;
    }
    // 0x80011BE8: nop

    // 0x80011BEC: j           L_80011DBC
    // 0x80011BF0: nop

        goto L_80011DBC;
    // 0x80011BF0: nop

L_80011BF4:
    // 0x80011BF4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011BF8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011BFC: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x80011C00: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x80011C04: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80011C08: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80011C0C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011C10: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80011C14: lh          $v0, 0x18($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X18);
    // 0x80011C18: slti        $v0, $v0, 0xFB
    ctx->r2 = SIGNED(ctx->r2) < 0XFB ? 1 : 0;
    // 0x80011C1C: beq         $v0, $zero, L_80011E74
    if (ctx->r2 == 0) {
        // 0x80011C20: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80011E74;
    }
    // 0x80011C20: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80011C24: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x80011C28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80011C2C: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // 0x80011C30: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80011C34: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80011C38: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80011C3C: addiu       $a0, $a0, 0x6418
    ctx->r4 = ADD32(ctx->r4, 0X6418);
    // 0x80011C40: j           L_80011E6C
    // 0x80011C44: nop

        goto L_80011E6C;
    // 0x80011C44: nop

L_80011C48:
    // 0x80011C48: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011C4C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011C50: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x80011C54: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x80011C58: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80011C5C: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80011C60: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011C64: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80011C68: lh          $v0, 0x18($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X18);
    // 0x80011C6C: slti        $v0, $v0, 0x154
    ctx->r2 = SIGNED(ctx->r2) < 0X154 ? 1 : 0;
    // 0x80011C70: bne         $v0, $zero, L_80011E74
    if (ctx->r2 != 0) {
        // 0x80011C74: nop
    
            goto L_80011E74;
    }
    // 0x80011C74: nop

L_80011C78:
    // 0x80011C78: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80011C7C: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x80011C80: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80011C84: lhu         $v0, 0x12C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X12C);
    // 0x80011C88: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x80011C8C: sh          $zero, 0x20($s0)
    MEM_H(0X20, ctx->r16) = 0;
    // 0x80011C90: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011C94: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011C98: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80011C9C: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
    // 0x80011CA0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011CA4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011CA8: lui         $v0, 0x154
    ctx->r2 = S32(0X154 << 16);
    // 0x80011CAC: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80011CB0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011CB4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011CB8: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x80011CBC: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80011CC0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80011CC4: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80011CC8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80011CCC: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80011CD0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80011CD4: addiu       $a0, $a0, 0x6448
    ctx->r4 = ADD32(ctx->r4, 0X6448);
    // 0x80011CD8: j           L_80011E6C
    // 0x80011CDC: nop

        goto L_80011E6C;
    // 0x80011CDC: nop

L_80011CE0:
    // 0x80011CE0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011CE4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011CE8: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x80011CEC: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x80011CF0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80011CF4: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80011CF8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011CFC: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011D00: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
    // 0x80011D04: slti        $v0, $v0, 0xF1
    ctx->r2 = SIGNED(ctx->r2) < 0XF1 ? 1 : 0;
    // 0x80011D08: beq         $v0, $zero, L_80011D14
    if (ctx->r2 == 0) {
        // 0x80011D0C: lui         $v0, 0xF0
        ctx->r2 = S32(0XF0 << 16);
            goto L_80011D14;
    }
    // 0x80011D0C: lui         $v0, 0xF0
    ctx->r2 = S32(0XF0 << 16);
    // 0x80011D10: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
L_80011D14:
    // 0x80011D14: lh          $v0, 0x1C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1C);
    // 0x80011D18: bne         $v0, $zero, L_80011E74
    if (ctx->r2 != 0) {
        // 0x80011D1C: addiu       $v1, $zero, 0x4
        ctx->r3 = ADD32(0, 0X4);
            goto L_80011E74;
    }
    // 0x80011D1C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80011D20: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    // 0x80011D24: sh          $v1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r3;
    // 0x80011D28: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80011D2C: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80011D30: addiu       $v1, $zero, -0x8000
    ctx->r3 = ADD32(0, -0X8000);
    // 0x80011D34: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80011D38: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80011D3C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80011D40: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // 0x80011D44: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x80011D48: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011D4C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80011D50: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80011D54: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80011D58: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80011D5C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80011D60: addiu       $a0, $a0, 0x63C8
    ctx->r4 = ADD32(ctx->r4, 0X63C8);
    // 0x80011D64: j           L_80011E6C
    // 0x80011D68: nop

        goto L_80011E6C;
    // 0x80011D68: nop

L_80011D6C:
    // 0x80011D6C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011D70: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011D74: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x80011D78: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x80011D7C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80011D80: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80011D84: lh          $v0, 0x1C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1C);
    // 0x80011D88: bne         $v0, $zero, L_80011E74
    if (ctx->r2 != 0) {
        // 0x80011D8C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80011E74;
    }
    // 0x80011D8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80011D90: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x80011D94: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011D98: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011D9C: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80011DA0: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80011DA4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80011DA8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80011DAC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80011DB0: addiu       $a0, $a0, 0x6460
    ctx->r4 = ADD32(ctx->r4, 0X6460);
    // 0x80011DB4: j           L_80011E6C
    // 0x80011DB8: nop

        goto L_80011E6C;
    // 0x80011DB8: nop

L_80011DBC:
    // 0x80011DBC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011DC0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011DC4: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x80011DC8: bgtz        $a0, L_80011E04
    if (SIGNED(ctx->r4) > 0) {
        // 0x80011DCC: nop
    
            goto L_80011E04;
    }
    // 0x80011DCC: nop

    // 0x80011DD0: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80011DD4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80011DD8: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80011DDC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011DE0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80011DE4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80011DE8: lhu         $v1, 0x12C($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X12C);
    // 0x80011DEC: lh          $v0, 0x14($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X14);
    // 0x80011DF0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80011DF4: beq         $v0, $zero, L_80011E74
    if (ctx->r2 == 0) {
        // 0x80011DF8: nop
    
            goto L_80011E74;
    }
    // 0x80011DF8: nop

    // 0x80011DFC: j           L_80011E30
    // 0x80011E00: nop

        goto L_80011E30;
    // 0x80011E00: nop

L_80011E04:
    // 0x80011E04: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80011E08: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80011E0C: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80011E10: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011E14: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80011E18: lh          $v1, 0x14($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X14);
    // 0x80011E1C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80011E20: lhu         $v0, -0x38($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38);
    // 0x80011E24: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80011E28: beq         $v0, $zero, L_80011E74
    if (ctx->r2 == 0) {
        // 0x80011E2C: nop
    
            goto L_80011E74;
    }
    // 0x80011E2C: nop

L_80011E30:
    // 0x80011E30: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011E34: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80011E38: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80011E3C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011E40: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011E44: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80011E48: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80011E4C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80011E50: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x80011E54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80011E58: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // 0x80011E5C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80011E60: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80011E64: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80011E68: addiu       $a0, $a0, 0x63E8
    ctx->r4 = ADD32(ctx->r4, 0X63E8);
L_80011E6C:
    // 0x80011E6C: jal         0x80037DDC
    // 0x80011E70: nop

    func_80037DDC(rdram, ctx);
        goto after_4;
    // 0x80011E70: nop

    after_4:
L_80011E74:
    // 0x80011E74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80011E78: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80011E7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80011E80: jr          $ra
    // 0x80011E84: nop

    return;
    // 0x80011E84: nop

;}
RECOMP_FUNC void func_80011E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011E88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011E8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011E90: jal         0x800306EC
    // 0x80011E94: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80011E94: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80011E98: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011E9C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011EA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80011EA4: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x80011EA8: lhu         $v1, 0x14($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X14);
    // 0x80011EAC: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x80011EB0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80011EB4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80011EB8: lhu         $a0, 0x18($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X18);
    // 0x80011EBC: addiu       $v1, $zero, 0x4100
    ctx->r3 = ADD32(0, 0X4100);
    // 0x80011EC0: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x80011EC4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80011EC8: addiu       $v1, $v1, 0x6000
    ctx->r3 = ADD32(ctx->r3, 0X6000);
    // 0x80011ECC: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x80011ED0: addiu       $a0, $a0, -0xA
    ctx->r4 = ADD32(ctx->r4, -0XA);
    // 0x80011ED4: sh          $a0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r4;
    // 0x80011ED8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80011EDC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80011EE0: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80011EE4: lw          $s0, 0x31C0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X31C0);
    // 0x80011EE8: jal         0x80023E44
    // 0x80011EEC: nop

    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x80011EEC: nop

    after_1:
    // 0x80011EF0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80011EF4: sw          $s0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r16;
    // 0x80011EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011EFC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80011F00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80011F04: jr          $ra
    // 0x80011F08: nop

    return;
    // 0x80011F08: nop

    // 0x80011F0C: nop

;}
RECOMP_FUNC void func_80011F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011F10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80011F14: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80011F18: addiu       $s1, $zero, 0x15
    ctx->r17 = ADD32(0, 0X15);
    // 0x80011F1C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80011F20: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80011F24: addiu       $s0, $s0, 0x4958
    ctx->r16 = ADD32(ctx->r16, 0X4958);
    // 0x80011F28: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_80011F2C:
    // 0x80011F2C: jal         0x800157F4
    // 0x80011F30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800157F4(rdram, ctx);
        goto after_0;
    // 0x80011F30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80011F34: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x80011F38: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80011F3C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80011F40: bne         $v0, $zero, L_80011F2C
    if (ctx->r2 != 0) {
        // 0x80011F44: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_80011F2C;
    }
    // 0x80011F44: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80011F48: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80011F4C: sh          $s1, 0x3ACA($at)
    MEM_H(0X3ACA, ctx->r1) = ctx->r17;
    // 0x80011F50: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80011F54: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80011F58: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80011F5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80011F60: jr          $ra
    // 0x80011F64: nop

    return;
    // 0x80011F64: nop

;}
RECOMP_FUNC void func_80011F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011F68: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011F6C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80011F68 falls into func_80011F70
    func_80011F70(rdram, ctx);
;}
RECOMP_FUNC void func_80011F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011F70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80011F74: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80011F78: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80011F7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80011F80: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80011F84: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80011F88: lw          $s1, 0x31C0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X31C0);
    // 0x80011F8C: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80011F90: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x80011F94: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80011F98: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x80011F9C: lhu         $s0, 0x2($v1)
    ctx->r16 = MEM_HU(ctx->r3, 0X2);
    // 0x80011FA0: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80011FA4: bne         $v0, $zero, L_80011FD8
    if (ctx->r2 != 0) {
        // 0x80011FA8: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_80011FD8;
    }
    // 0x80011FA8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80011FAC: beql        $a1, $zero, L_80011FC0
    if (ctx->r5 == 0) {
        // 0x80011FB0: andi        $a1, $s0, 0xFFFF
        ctx->r5 = ctx->r16 & 0XFFFF;
            goto L_80011FC0;
    }
    goto skip_0;
    // 0x80011FB0: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    skip_0:
    // 0x80011FB4: jal         0x8004C86C
    // 0x80011FB8: nop

    func_8004C86C(rdram, ctx);
        goto after_0;
    // 0x80011FB8: nop

    after_0:
    // 0x80011FBC: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
L_80011FC0:
    // 0x80011FC0: beq         $a1, $zero, L_80011FD8
    if (ctx->r5 == 0) {
        // 0x80011FC4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80011FD8;
    }
    // 0x80011FC4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80011FC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80011FCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80011FD0: jal         0x80015304
    // 0x80011FD4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80015304(rdram, ctx);
        goto after_1;
    // 0x80011FD4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_80011FD8:
    // 0x80011FD8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80011FDC: sw          $s1, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r17;
    // 0x80011FE0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80011FE4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80011FE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80011FEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80011FF0: jr          $ra
    // 0x80011FF4: nop

    return;
    // 0x80011FF4: nop

;}
RECOMP_FUNC void func_80011FF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011FF8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80011FFC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80011FF8 falls into func_80012000
    func_80012000(rdram, ctx);
;}
RECOMP_FUNC void func_80012000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80012004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80012008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001200C: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80012010: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80012014: lw          $s0, 0x31C0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X31C0);
    // 0x80012018: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x8001201C: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x80012020: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x80012024: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80012028: bne         $v0, $zero, L_80012058
    if (ctx->r2 != 0) {
        // 0x8001202C: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_80012058;
    }
    // 0x8001202C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80012030: beql        $a1, $zero, L_80012044
    if (ctx->r5 == 0) {
        // 0x80012034: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_80012044;
    }
    goto skip_0;
    // 0x80012034: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_0:
    // 0x80012038: jal         0x8004C86C
    // 0x8001203C: nop

    func_8004C86C(rdram, ctx);
        goto after_0;
    // 0x8001203C: nop

    after_0:
    // 0x80012040: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_80012044:
    // 0x80012044: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80012048: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001204C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80012050: jal         0x80015304
    // 0x80012054: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80015304(rdram, ctx);
        goto after_1;
    // 0x80012054: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_80012058:
    // 0x80012058: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8001205C: sw          $s0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r16;
    // 0x80012060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80012064: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80012068: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001206C: jr          $ra
    // 0x80012070: nop

    return;
    // 0x80012070: nop

;}
RECOMP_FUNC void func_80012074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012074: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80012078: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // FALLTHROUGH: func_80012074 falls into func_8001207C
    func_8001207C(rdram, ctx);
;}
RECOMP_FUNC void func_8001207C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001207C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80012080: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80012084: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80012088: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001208C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80012090: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80012094: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80012098: lhu         $v0, 0x6C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6C);
    // 0x8001209C: lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // 0x800120A0: lw          $s4, 0x31C0($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X31C0);
    // 0x800120A4: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800120A8: bne         $v0, $zero, L_800121D8
    if (ctx->r2 != 0) {
        // 0x800120AC: nop
    
            goto L_800121D8;
    }
    // 0x800120AC: nop

    // 0x800120B0: lw          $s1, 0x90($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X90);
    // 0x800120B4: lhu         $v0, 0x22($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X22);
    // 0x800120B8: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x800120BC: beql        $v0, $zero, L_800120C4
    if (ctx->r2 == 0) {
        // 0x800120C0: sh          $zero, 0x22($s1)
        MEM_H(0X22, ctx->r17) = 0;
            goto L_800120C4;
    }
    goto skip_0;
    // 0x800120C0: sh          $zero, 0x22($s1)
    MEM_H(0X22, ctx->r17) = 0;
    skip_0:
L_800120C4:
    // 0x800120C4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800120C8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x800120CC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800120D0: lhu         $v0, 0x46A8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X46A8);
    // 0x800120D4: lhu         $v1, 0x14($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X14);
    // 0x800120D8: subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
    // 0x800120DC: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x800120E0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800120E4: slti        $v1, $v0, 0x1
    ctx->r3 = SIGNED(ctx->r2) < 0X1 ? 1 : 0;
    // 0x800120E8: slti        $v0, $v0, -0x1F3
    ctx->r2 = SIGNED(ctx->r2) < -0X1F3 ? 1 : 0;
    // 0x800120EC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800120F0: beq         $v1, $zero, L_80012104
    if (ctx->r3 == 0) {
        // 0x800120F4: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_80012104;
    }
    // 0x800120F4: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800120F8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800120FC: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x80012100: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
L_80012104:
    // 0x80012104: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x80012108: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8001210C: beq         $v0, $zero, L_8001212C
    if (ctx->r2 == 0) {
        // 0x80012110: sll         $v0, $a2, 16
        ctx->r2 = S32(ctx->r6 << 16);
            goto L_8001212C;
    }
    // 0x80012110: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x80012114: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80012118: slti        $v0, $v0, 0xC9
    ctx->r2 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x8001211C: beq         $v0, $zero, L_8001213C
    if (ctx->r2 == 0) {
        // 0x80012120: nop
    
            goto L_8001213C;
    }
    // 0x80012120: nop

    // 0x80012124: j           L_8001215C
    // 0x80012128: nop

        goto L_8001215C;
    // 0x80012128: nop

L_8001212C:
    // 0x8001212C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80012130: slti        $v0, $v0, 0xC8
    ctx->r2 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x80012134: beq         $v0, $zero, L_8001215C
    if (ctx->r2 == 0) {
        // 0x80012138: nop
    
            goto L_8001215C;
    }
    // 0x80012138: nop

L_8001213C:
    // 0x8001213C: lhu         $v0, 0x22($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X22);
    // 0x80012140: addiu       $s3, $zero, -0x8
    ctx->r19 = ADD32(0, -0X8);
    // 0x80012144: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80012148: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8001214C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80012150: lhu         $s0, 0x50B0($s0)
    ctx->r16 = MEM_HU(ctx->r16, 0X50B0);
    // 0x80012154: j           L_80012178
    // 0x80012158: addiu       $s2, $zero, -0x10
    ctx->r18 = ADD32(0, -0X10);
        goto L_80012178;
    // 0x80012158: addiu       $s2, $zero, -0x10
    ctx->r18 = ADD32(0, -0X10);
L_8001215C:
    // 0x8001215C: lhu         $v0, 0x22($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X22);
    // 0x80012160: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80012164: addiu       $s2, $zero, -0x12
    ctx->r18 = ADD32(0, -0X12);
    // 0x80012168: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001216C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80012170: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80012174: lhu         $s0, 0x50BC($s0)
    ctx->r16 = MEM_HU(ctx->r16, 0X50BC);
L_80012178:
    // 0x80012178: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8001217C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80012180: lw          $v0, 0x5C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5C);
    // 0x80012184: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x80012188: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8001218C: lhu         $a2, 0x0($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X0);
    // 0x80012190: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80012194: beq         $v0, $zero, L_800121A4
    if (ctx->r2 == 0) {
        // 0x80012198: nop
    
            goto L_800121A4;
    }
    // 0x80012198: nop

    // 0x8001219C: jal         0x8004C86C
    // 0x800121A0: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    func_8004C86C(rdram, ctx);
        goto after_0;
    // 0x800121A0: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    after_0:
L_800121A4:
    // 0x800121A4: beq         $s0, $zero, L_800121D8
    if (ctx->r16 == 0) {
        // 0x800121A8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800121D8;
    }
    // 0x800121A8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800121AC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800121B0: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
    // 0x800121B4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800121B8: sll         $a3, $s3, 16
    ctx->r7 = S32(ctx->r19 << 16);
    // 0x800121BC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x800121C0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800121C4: jal         0x80015304
    // 0x800121C8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80015304(rdram, ctx);
        goto after_1;
    // 0x800121C8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x800121CC: lhu         $v0, 0x22($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X22);
    // 0x800121D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800121D4: sh          $v0, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r2;
L_800121D8:
    // 0x800121D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800121DC: sw          $s4, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r20;
    // 0x800121E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800121E4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800121E8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800121EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800121F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800121F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800121F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800121FC: jr          $ra
    // 0x80012200: nop

    return;
    // 0x80012200: nop

;}
RECOMP_FUNC void func_80012204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012204: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80012208: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80012204 falls into func_8001220C
    func_8001220C(rdram, ctx);
;}
RECOMP_FUNC void func_8001220C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001220C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80012210: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80012214: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80012218: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001221C: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80012220: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80012224: lw          $s1, 0x31C0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X31C0);
    // 0x80012228: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x8001222C: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x80012230: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80012234: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x80012238: lhu         $s0, 0x2($v1)
    ctx->r16 = MEM_HU(ctx->r3, 0X2);
    // 0x8001223C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80012240: bne         $v0, $zero, L_80012274
    if (ctx->r2 != 0) {
        // 0x80012244: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_80012274;
    }
    // 0x80012244: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80012248: beql        $a1, $zero, L_8001225C
    if (ctx->r5 == 0) {
        // 0x8001224C: andi        $a1, $s0, 0xFFFF
        ctx->r5 = ctx->r16 & 0XFFFF;
            goto L_8001225C;
    }
    goto skip_0;
    // 0x8001224C: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    skip_0:
    // 0x80012250: jal         0x8004C86C
    // 0x80012254: nop

    func_8004C86C(rdram, ctx);
        goto after_0;
    // 0x80012254: nop

    after_0:
    // 0x80012258: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
L_8001225C:
    // 0x8001225C: beq         $a1, $zero, L_80012274
    if (ctx->r5 == 0) {
        // 0x80012260: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80012274;
    }
    // 0x80012260: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80012264: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80012268: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x8001226C: jal         0x80015304
    // 0x80012270: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80015304(rdram, ctx);
        goto after_1;
    // 0x80012270: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_80012274:
    // 0x80012274: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80012278: sw          $s1, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r17;
    // 0x8001227C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80012280: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80012284: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80012288: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001228C: jr          $ra
    // 0x80012290: nop

    return;
    // 0x80012290: nop

;}
RECOMP_FUNC void func_80012294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012294: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80012298: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80012294 falls into func_8001229C
    func_8001229C(rdram, ctx);
;}
RECOMP_FUNC void func_8001229C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001229C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800122A0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800122A4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800122A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800122AC: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x800122B0: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x800122B4: lw          $s1, 0x31C0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X31C0);
    // 0x800122B8: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x800122BC: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x800122C0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800122C4: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x800122C8: lhu         $s0, 0x2($v1)
    ctx->r16 = MEM_HU(ctx->r3, 0X2);
    // 0x800122CC: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800122D0: bne         $v0, $zero, L_80012300
    if (ctx->r2 != 0) {
        // 0x800122D4: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_80012300;
    }
    // 0x800122D4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800122D8: beql        $a1, $zero, L_800122EC
    if (ctx->r5 == 0) {
        // 0x800122DC: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_800122EC;
    }
    goto skip_0;
    // 0x800122DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_0:
    // 0x800122E0: jal         0x8004C86C
    // 0x800122E4: nop

    func_8004C86C(rdram, ctx);
        goto after_0;
    // 0x800122E4: nop

    after_0:
    // 0x800122E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800122EC:
    // 0x800122EC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800122F0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800122F4: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x800122F8: jal         0x80015304
    // 0x800122FC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80015304(rdram, ctx);
        goto after_1;
    // 0x800122FC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_80012300:
    // 0x80012300: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80012304: sw          $s1, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r17;
    // 0x80012308: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8001230C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80012310: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80012314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80012318: jr          $ra
    // 0x8001231C: nop

    return;
    // 0x8001231C: nop

;}
RECOMP_FUNC void func_80012320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012320: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80012324: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80012320 falls into func_80012328
    func_80012328(rdram, ctx);
;}
RECOMP_FUNC void func_80012328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012328: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001232C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80012330: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80012334: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80012338: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8001233C: lw          $s0, 0x31C0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X31C0);
    // 0x80012340: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80012344: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x80012348: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x8001234C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80012350: bne         $v0, $zero, L_80012380
    if (ctx->r2 != 0) {
        // 0x80012354: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_80012380;
    }
    // 0x80012354: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80012358: beql        $a1, $zero, L_8001236C
    if (ctx->r5 == 0) {
        // 0x8001235C: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_8001236C;
    }
    goto skip_0;
    // 0x8001235C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_0:
    // 0x80012360: jal         0x8004C86C
    // 0x80012364: nop

    func_8004C86C(rdram, ctx);
        goto after_0;
    // 0x80012364: nop

    after_0:
    // 0x80012368: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_8001236C:
    // 0x8001236C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80012370: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80012374: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80012378: jal         0x80015304
    // 0x8001237C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80015304(rdram, ctx);
        goto after_1;
    // 0x8001237C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_80012380:
    // 0x80012380: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80012384: sw          $s0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r16;
    // 0x80012388: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001238C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80012390: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80012394: jr          $ra
    // 0x80012398: nop

    return;
    // 0x80012398: nop

;}
RECOMP_FUNC void func_8001239C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001239C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800123A0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_8001239C falls into func_800123A4
    func_800123A4(rdram, ctx);
;}
RECOMP_FUNC void func_800123A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800123A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800123A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800123AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800123B0: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x800123B4: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x800123B8: lw          $s0, 0x31C0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X31C0);
    // 0x800123BC: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x800123C0: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x800123C4: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x800123C8: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800123CC: bne         $v0, $zero, L_800123FC
    if (ctx->r2 != 0) {
        // 0x800123D0: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_800123FC;
    }
    // 0x800123D0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800123D4: beql        $a1, $zero, L_800123E8
    if (ctx->r5 == 0) {
        // 0x800123D8: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_800123E8;
    }
    goto skip_0;
    // 0x800123D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_0:
    // 0x800123DC: jal         0x8004C86C
    // 0x800123E0: nop

    func_8004C86C(rdram, ctx);
        goto after_0;
    // 0x800123E0: nop

    after_0:
    // 0x800123E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800123E8:
    // 0x800123E8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800123EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800123F0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800123F4: jal         0x80015304
    // 0x800123F8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80015304(rdram, ctx);
        goto after_1;
    // 0x800123F8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_800123FC:
    // 0x800123FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80012400: sw          $s0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r16;
    // 0x80012404: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80012408: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001240C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80012410: jr          $ra
    // 0x80012414: nop

    return;
    // 0x80012414: nop

;}
RECOMP_FUNC void func_80012418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012418: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8001241C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80012418 falls into func_80012420
    func_80012420(rdram, ctx);
;}
RECOMP_FUNC void func_80012420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012420: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80012424: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80012428: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001242C: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80012430: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80012434: lw          $s0, 0x31C0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X31C0);
    // 0x80012438: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x8001243C: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x80012440: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x80012444: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80012448: bne         $v0, $zero, L_80012478
    if (ctx->r2 != 0) {
        // 0x8001244C: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_80012478;
    }
    // 0x8001244C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80012450: beql        $a1, $zero, L_80012464
    if (ctx->r5 == 0) {
        // 0x80012454: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_80012464;
    }
    goto skip_0;
    // 0x80012454: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_0:
    // 0x80012458: jal         0x8004C86C
    // 0x8001245C: nop

    func_8004C86C(rdram, ctx);
        goto after_0;
    // 0x8001245C: nop

    after_0:
    // 0x80012460: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_80012464:
    // 0x80012464: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80012468: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001246C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80012470: jal         0x80015304
    // 0x80012474: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80015304(rdram, ctx);
        goto after_1;
    // 0x80012474: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_80012478:
    // 0x80012478: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8001247C: sw          $s0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r16;
    // 0x80012480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80012484: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80012488: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001248C: jr          $ra
    // 0x80012490: nop

    return;
    // 0x80012490: nop

;}
RECOMP_FUNC void func_80012494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012494: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80012498: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_8001249C
    func_8001249C(rdram, ctx);
}
