#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_80067510(uint8_t* rdram, recomp_context* ctx);
void func_8006779C(uint8_t* rdram, recomp_context* ctx);
void func_80067C68(uint8_t* rdram, recomp_context* ctx);
void func_800680DC(uint8_t* rdram, recomp_context* ctx);
void func_800681A8(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80066954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066954: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80066958: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006695C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80066960: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066964: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80066968: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8006696C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80066970: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80066974: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80066978: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006697C: jal         0x800629A8
    // 0x80066980: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    func_800629A8(rdram, ctx);
        goto after_0;
    // 0x80066980: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x80066984: beq         $v0, $zero, L_80066A20
    if (ctx->r2 == 0) {
        // 0x80066988: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80066A20;
    }
    // 0x80066988: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006698C: jal         0x8006885C
    // 0x80066990: nop

    func_8006885C(rdram, ctx);
        goto after_1;
    // 0x80066990: nop

    after_1:
    // 0x80066994: jal         0x80066380
    // 0x80066998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80066380(rdram, ctx);
        goto after_2;
    // 0x80066998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8006699C: beq         $v0, $zero, L_80066A14
    if (ctx->r2 == 0) {
        // 0x800669A0: lui         $s5, 0x800D
        ctx->r21 = S32(0X800D << 16);
            goto L_80066A14;
    }
    // 0x800669A0: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x800669A4: addiu       $s5, $s5, -0x16F4
    ctx->r21 = ADD32(ctx->r21, -0X16F4);
    // 0x800669A8: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x800669AC: lbu         $s1, 0x4($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0X4);
    // 0x800669B0: lbu         $s0, 0xA($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0XA);
    // 0x800669B4: lw          $s2, 0xC($v0)
    ctx->r18 = MEM_W(ctx->r2, 0XC);
    // 0x800669B8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800669BC: beq         $s0, $zero, L_80066A14
    if (ctx->r16 == 0) {
        // 0x800669C0: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80066A14;
    }
    // 0x800669C0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800669C4: addiu       $s4, $zero, 0x50
    ctx->r20 = ADD32(0, 0X50);
    // 0x800669C8: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
L_800669CC:
    // 0x800669CC: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800669D0: nop

    // 0x800669D4: beq         $s3, $v0, L_80066A08
    if (ctx->r19 == ctx->r2) {
        // 0x800669D8: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80066A08;
    }
    // 0x800669D8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800669DC: multu       $v0, $s4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800669E0: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x800669E4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800669E8: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x800669EC: mflo        $t7
    ctx->r15 = lo;
    // 0x800669F0: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x800669F4: jal         0x8006779C
    // 0x800669F8: nop

    func_8006779C(rdram, ctx);
        goto after_3;
    // 0x800669F8: nop

    after_3:
    // 0x800669FC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80066A00: beq         $s1, $zero, L_80066A14
    if (ctx->r17 == 0) {
        // 0x80066A04: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80066A14;
    }
    // 0x80066A04: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_80066A08:
    // 0x80066A08: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80066A0C: bne         $s0, $zero, L_800669CC
    if (ctx->r16 != 0) {
        // 0x80066A10: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800669CC;
    }
    // 0x80066A10: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80066A14:
    // 0x80066A14: jal         0x8006889C
    // 0x80066A18: nop

    func_8006889C(rdram, ctx);
        goto after_4;
    // 0x80066A18: nop

    after_4:
    // 0x80066A1C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80066A20:
    // 0x80066A20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066A24: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80066A28: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80066A2C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80066A30: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80066A34: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80066A38: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80066A3C: jr          $ra
    // 0x80066A40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80066A40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80066A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066A44: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80066A48: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80066A4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066A50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80066A54: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80066A58: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80066A5C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80066A60: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80066A64: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80066A68: jal         0x800629A8
    // 0x80066A6C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    func_800629A8(rdram, ctx);
        goto after_0;
    // 0x80066A6C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x80066A70: beq         $v0, $zero, L_80066B34
    if (ctx->r2 == 0) {
        // 0x80066A74: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80066B34;
    }
    // 0x80066A74: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80066A78: jal         0x8006885C
    // 0x80066A7C: nop

    func_8006885C(rdram, ctx);
        goto after_1;
    // 0x80066A7C: nop

    after_1:
    // 0x80066A80: jal         0x80066380
    // 0x80066A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80066380(rdram, ctx);
        goto after_2;
    // 0x80066A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80066A88: beq         $v0, $zero, L_80066B28
    if (ctx->r2 == 0) {
        // 0x80066A8C: lui         $s6, 0x800D
        ctx->r22 = S32(0X800D << 16);
            goto L_80066B28;
    }
    // 0x80066A8C: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x80066A90: addiu       $s6, $s6, -0x16F4
    ctx->r22 = ADD32(ctx->r22, -0X16F4);
    // 0x80066A94: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x80066A98: lbu         $s1, 0x4($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0X4);
    // 0x80066A9C: lbu         $s0, 0xA($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0XA);
    // 0x80066AA0: lw          $s2, 0xC($v0)
    ctx->r18 = MEM_W(ctx->r2, 0XC);
    // 0x80066AA4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80066AA8: beq         $s0, $zero, L_80066B28
    if (ctx->r16 == 0) {
        // 0x80066AAC: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80066B28;
    }
    // 0x80066AAC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80066AB0: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x80066AB4: addiu       $s5, $s5, 0xC50
    ctx->r21 = ADD32(ctx->r21, 0XC50);
    // 0x80066AB8: addiu       $s4, $zero, 0x50
    ctx->r20 = ADD32(0, 0X50);
    // 0x80066ABC: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
L_80066AC0:
    // 0x80066AC0: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x80066AC4: nop

    // 0x80066AC8: beq         $s3, $v0, L_80066B1C
    if (ctx->r19 == ctx->r2) {
        // 0x80066ACC: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80066B1C;
    }
    // 0x80066ACC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80066AD0: multu       $v0, $s4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066AD4: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x80066AD8: nop

    // 0x80066ADC: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x80066AE0: mflo        $t7
    ctx->r15 = lo;
    // 0x80066AE4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x80066AE8: lbu         $t0, 0x10($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X10);
    // 0x80066AEC: nop

    // 0x80066AF0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80066AF4: addu        $t2, $s5, $t1
    ctx->r10 = ADD32(ctx->r21, ctx->r9);
    // 0x80066AF8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80066AFC: nop

    // 0x80066B00: lw          $t9, 0x14($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X14);
    // 0x80066B04: nop

    // 0x80066B08: jalr        $t9
    // 0x80066B0C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80066B0C: nop

    after_3:
    // 0x80066B10: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80066B14: beq         $s1, $zero, L_80066B28
    if (ctx->r17 == 0) {
        // 0x80066B18: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80066B28;
    }
    // 0x80066B18: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_80066B1C:
    // 0x80066B1C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80066B20: bne         $s0, $zero, L_80066AC0
    if (ctx->r16 != 0) {
        // 0x80066B24: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80066AC0;
    }
    // 0x80066B24: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80066B28:
    // 0x80066B28: jal         0x8006889C
    // 0x80066B2C: nop

    func_8006889C(rdram, ctx);
        goto after_4;
    // 0x80066B2C: nop

    after_4:
    // 0x80066B30: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80066B34:
    // 0x80066B34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066B38: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80066B3C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80066B40: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80066B44: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80066B48: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80066B4C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80066B50: jr          $ra
    // 0x80066B54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80066B54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80066B58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066B58: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80066B5C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80066B60: sll         $s7, $a1, 16
    ctx->r23 = S32(ctx->r5 << 16);
    // 0x80066B64: sra         $t6, $s7, 16
    ctx->r14 = S32(SIGNED(ctx->r23) >> 16);
    // 0x80066B68: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80066B6C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80066B70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80066B74: or          $s7, $t6, $zero
    ctx->r23 = ctx->r14 | 0;
    // 0x80066B78: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80066B7C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80066B80: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80066B84: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80066B88: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80066B8C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80066B90: jal         0x800629A8
    // 0x80066B94: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_800629A8(rdram, ctx);
        goto after_0;
    // 0x80066B94: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80066B98: beq         $v0, $zero, L_80066C60
    if (ctx->r2 == 0) {
        // 0x80066B9C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80066C60;
    }
    // 0x80066B9C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80066BA0: jal         0x8006885C
    // 0x80066BA4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    func_8006885C(rdram, ctx);
        goto after_1;
    // 0x80066BA4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_1:
    // 0x80066BA8: jal         0x80066380
    // 0x80066BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80066380(rdram, ctx);
        goto after_2;
    // 0x80066BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80066BB0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80066BB4: beq         $v0, $zero, L_80066C54
    if (ctx->r2 == 0) {
        // 0x80066BB8: lui         $s4, 0x800D
        ctx->r20 = S32(0X800D << 16);
            goto L_80066C54;
    }
    // 0x80066BB8: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x80066BBC: addiu       $s4, $s4, -0x16F4
    ctx->r20 = ADD32(ctx->r20, -0X16F4);
    // 0x80066BC0: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80066BC4: lbu         $s2, 0x4($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X4);
    // 0x80066BC8: lbu         $s1, 0xA($t7)
    ctx->r17 = MEM_BU(ctx->r15, 0XA);
    // 0x80066BCC: lw          $s3, 0xC($v0)
    ctx->r19 = MEM_W(ctx->r2, 0XC);
    // 0x80066BD0: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80066BD4: beq         $s1, $zero, L_80066C54
    if (ctx->r17 == 0) {
        // 0x80066BD8: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80066C54;
    }
    // 0x80066BD8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80066BDC: addiu       $s6, $zero, 0x50
    ctx->r22 = ADD32(0, 0X50);
    // 0x80066BE0: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
L_80066BE4:
    // 0x80066BE4: lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X0);
    // 0x80066BE8: nop

    // 0x80066BEC: beq         $s5, $v0, L_80066C48
    if (ctx->r21 == ctx->r2) {
        // 0x80066BF0: or          $v1, $s1, $zero
        ctx->r3 = ctx->r17 | 0;
            goto L_80066C48;
    }
    // 0x80066BF0: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80066BF4: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066BF8: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80066BFC: nop

    // 0x80066C00: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x80066C04: mflo        $t8
    ctx->r24 = lo;
    // 0x80066C08: addu        $s0, $t8, $t0
    ctx->r16 = ADD32(ctx->r24, ctx->r8);
    // 0x80066C0C: bne         $a1, $zero, L_80066C38
    if (ctx->r5 != 0) {
        // 0x80066C10: sh          $s7, 0x16($s0)
        MEM_H(0X16, ctx->r16) = ctx->r23;
            goto L_80066C38;
    }
    // 0x80066C10: sh          $s7, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r23;
    // 0x80066C14: jal         0x800688DC
    // 0x80066C18: nop

    func_800688DC(rdram, ctx);
        goto after_3;
    // 0x80066C18: nop

    after_3:
    // 0x80066C1C: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80066C20: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80066C24: lh          $a1, 0x14($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X14);
    // 0x80066C28: lh          $a2, 0x16($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X16);
    // 0x80066C2C: jal         0x800688E4
    // 0x80066C30: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800688E4(rdram, ctx);
        goto after_4;
    // 0x80066C30: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_4:
    // 0x80066C34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80066C38:
    // 0x80066C38: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80066C3C: beq         $s2, $zero, L_80066C54
    if (ctx->r18 == 0) {
        // 0x80066C40: sw          $a1, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->r5;
            goto L_80066C54;
    }
    // 0x80066C40: sw          $a1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r5;
    // 0x80066C44: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_80066C48:
    // 0x80066C48: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80066C4C: bne         $s1, $zero, L_80066BE4
    if (ctx->r17 != 0) {
        // 0x80066C50: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80066BE4;
    }
    // 0x80066C50: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80066C54:
    // 0x80066C54: jal         0x8006889C
    // 0x80066C58: nop

    func_8006889C(rdram, ctx);
        goto after_5;
    // 0x80066C58: nop

    after_5:
    // 0x80066C5C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80066C60:
    // 0x80066C60: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80066C64: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80066C68: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80066C6C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80066C70: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80066C74: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80066C78: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80066C7C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80066C80: jr          $ra
    // 0x80066C84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80066C84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80066C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066C88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066C8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066C90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80066C94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80066C98: jal         0x800629A8
    // 0x80066C9C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800629A8(rdram, ctx);
        goto after_0;
    // 0x80066C9C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80066CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066CA8: jr          $ra
    // 0x80066CAC: nop

    return;
    // 0x80066CAC: nop

;}
RECOMP_FUNC void func_80066CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066CB0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80066CB4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80066CB8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80066CBC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80066CC0: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80066CC4: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80066CC8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80066CCC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80066CD0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80066CD4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80066CD8: jal         0x800629A8
    // 0x80066CDC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_800629A8(rdram, ctx);
        goto after_0;
    // 0x80066CDC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x80066CE0: bne         $v0, $zero, L_80066CF0
    if (ctx->r2 != 0) {
        // 0x80066CE4: nop
    
            goto L_80066CF0;
    }
    // 0x80066CE4: nop

    // 0x80066CE8: b           L_80066DC4
    // 0x80066CEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80066DC4;
    // 0x80066CEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80066CF0:
    // 0x80066CF0: jal         0x8006885C
    // 0x80066CF4: nop

    func_8006885C(rdram, ctx);
        goto after_1;
    // 0x80066CF4: nop

    after_1:
    // 0x80066CF8: jal         0x80066380
    // 0x80066CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80066380(rdram, ctx);
        goto after_2;
    // 0x80066CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80066D00: beq         $v0, $zero, L_80066DB8
    if (ctx->r2 == 0) {
        // 0x80066D04: lui         $s7, 0x800D
        ctx->r23 = S32(0X800D << 16);
            goto L_80066DB8;
    }
    // 0x80066D04: lui         $s7, 0x800D
    ctx->r23 = S32(0X800D << 16);
    // 0x80066D08: addiu       $s7, $s7, -0x16F4
    ctx->r23 = ADD32(ctx->r23, -0X16F4);
    // 0x80066D0C: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80066D10: lbu         $s2, 0x4($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X4);
    // 0x80066D14: lbu         $s1, 0xA($t6)
    ctx->r17 = MEM_BU(ctx->r14, 0XA);
    // 0x80066D18: lw          $s3, 0xC($v0)
    ctx->r19 = MEM_W(ctx->r2, 0XC);
    // 0x80066D1C: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80066D20: beq         $s1, $zero, L_80066DB8
    if (ctx->r17 == 0) {
        // 0x80066D24: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80066DB8;
    }
    // 0x80066D24: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80066D28: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x80066D2C: addiu       $s6, $s6, 0xC50
    ctx->r22 = ADD32(ctx->r22, 0XC50);
    // 0x80066D30: addiu       $s5, $zero, 0x50
    ctx->r21 = ADD32(0, 0X50);
    // 0x80066D34: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
L_80066D38:
    // 0x80066D38: lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X0);
    // 0x80066D3C: nop

    // 0x80066D40: beq         $s4, $v0, L_80066DAC
    if (ctx->r20 == ctx->r2) {
        // 0x80066D44: or          $v1, $s1, $zero
        ctx->r3 = ctx->r17 | 0;
            goto L_80066DAC;
    }
    // 0x80066D44: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80066D48: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066D4C: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80066D50: nop

    // 0x80066D54: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x80066D58: mflo        $t7
    ctx->r15 = lo;
    // 0x80066D5C: addu        $s0, $t7, $t9
    ctx->r16 = ADD32(ctx->r15, ctx->r25);
    // 0x80066D60: lbu         $t0, 0x10($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X10);
    // 0x80066D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066D68: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80066D6C: addu        $t2, $s6, $t1
    ctx->r10 = ADD32(ctx->r22, ctx->r9);
    // 0x80066D70: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80066D74: nop

    // 0x80066D78: lw          $t9, 0x18($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X18);
    // 0x80066D7C: nop

    // 0x80066D80: jalr        $t9
    // 0x80066D84: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80066D84: nop

    after_3:
    // 0x80066D88: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80066D8C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80066D90: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80066D94: jal         0x80069480
    // 0x80066D98: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    func_80069480(rdram, ctx);
        goto after_4;
    // 0x80066D98: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    after_4:
    // 0x80066D9C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80066DA0: beq         $s2, $zero, L_80066DB8
    if (ctx->r18 == 0) {
        // 0x80066DA4: sw          $v0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r2;
            goto L_80066DB8;
    }
    // 0x80066DA4: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80066DA8: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_80066DAC:
    // 0x80066DAC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80066DB0: bne         $s1, $zero, L_80066D38
    if (ctx->r17 != 0) {
        // 0x80066DB4: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80066D38;
    }
    // 0x80066DB4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80066DB8:
    // 0x80066DB8: jal         0x8006889C
    // 0x80066DBC: nop

    func_8006889C(rdram, ctx);
        goto after_5;
    // 0x80066DBC: nop

    after_5:
    // 0x80066DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80066DC4:
    // 0x80066DC4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80066DC8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80066DCC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80066DD0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80066DD4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80066DD8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80066DDC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80066DE0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80066DE4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80066DE8: jr          $ra
    // 0x80066DEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80066DEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80066DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066DF0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80066DF4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80066DF8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80066DFC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80066E00: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80066E04: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80066E08: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80066E0C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80066E10: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80066E14: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80066E18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066E1C: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80066E20: lw          $t7, 0x20($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X20);
    // 0x80066E24: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80066E28: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80066E2C: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x80066E30: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80066E34: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x80066E38: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x80066E3C: lw          $s2, 0x34($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X34);
    // 0x80066E40: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80066E44: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80066E48: addiu       $s6, $s6, 0xDBC
    ctx->r22 = ADD32(ctx->r22, 0XDBC);
    // 0x80066E4C: addiu       $s3, $s3, 0xD20
    ctx->r19 = ADD32(ctx->r19, 0XD20);
    // 0x80066E50: addiu       $s4, $sp, 0x54
    ctx->r20 = ADD32(ctx->r29, 0X54);
    // 0x80066E54: addiu       $fp, $zero, 0x22
    ctx->r30 = ADD32(0, 0X22);
    // 0x80066E58: addu        $s5, $t6, $t8
    ctx->r21 = ADD32(ctx->r14, ctx->r24);
L_80066E5C:
    // 0x80066E5C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
L_80066E60:
    // 0x80066E60: nop

    // 0x80066E64: addu        $s5, $s5, $t0
    ctx->r21 = ADD32(ctx->r21, ctx->r8);
    // 0x80066E68: sltu        $at, $s5, $s7
    ctx->r1 = ctx->r21 < ctx->r23 ? 1 : 0;
    // 0x80066E6C: bne         $at, $zero, L_80066E7C
    if (ctx->r1 != 0) {
        // 0x80066E70: nop
    
            goto L_80066E7C;
    }
    // 0x80066E70: nop

    // 0x80066E74: b           L_80066FC0
    // 0x80066E78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80066FC0;
    // 0x80066E78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80066E7C:
    // 0x80066E7C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x80066E80: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80066E84: lbu         $s0, 0x0($a0)
    ctx->r16 = MEM_BU(ctx->r4, 0X0);
    // 0x80066E88: nop

    // 0x80066E8C: bne         $s0, $fp, L_80066E9C
    if (ctx->r16 != ctx->r30) {
        // 0x80066E90: addu        $t3, $s3, $s0
        ctx->r11 = ADD32(ctx->r19, ctx->r16);
            goto L_80066E9C;
    }
    // 0x80066E90: addu        $t3, $s3, $s0
    ctx->r11 = ADD32(ctx->r19, ctx->r16);
    // 0x80066E94: b           L_80066FC0
    // 0x80066E98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80066FC0;
    // 0x80066E98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80066E9C:
    // 0x80066E9C: beq         $s0, $at, L_80066FA0
    if (ctx->r16 == ctx->r1) {
        // 0x80066EA0: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_80066FA0;
    }
    // 0x80066EA0: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80066EA4: beq         $s0, $at, L_80066FA0
    if (ctx->r16 == ctx->r1) {
        // 0x80066EA8: slti        $at, $s0, 0x7
        ctx->r1 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
            goto L_80066FA0;
    }
    // 0x80066EA8: slti        $at, $s0, 0x7
    ctx->r1 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
    // 0x80066EAC: bne         $at, $zero, L_80066F10
    if (ctx->r1 != 0) {
        // 0x80066EB0: slti        $at, $s0, 0x13
        ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
            goto L_80066F10;
    }
    // 0x80066EB0: slti        $at, $s0, 0x13
    ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
    // 0x80066EB4: beq         $at, $zero, L_80066F14
    if (ctx->r1 == 0) {
        // 0x80066EB8: slti        $at, $s0, 0x13
        ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
            goto L_80066F14;
    }
    // 0x80066EB8: slti        $at, $s0, 0x13
    ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
    // 0x80066EBC: lbu         $t1, 0x10($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X10);
    // 0x80066EC0: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80066EC4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80066EC8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80066ECC: lw          $t3, 0xC50($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XC50);
    // 0x80066ED0: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80066ED4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80066ED8: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x80066EDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80066EE0: jalr        $t9
    // 0x80066EE4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80066EE4: nop

    after_0:
    // 0x80066EE8: addu        $t6, $s3, $s0
    ctx->r14 = ADD32(ctx->r19, ctx->r16);
    // 0x80066EEC: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x80066EF0: lw          $t7, 0x34($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X34);
    // 0x80066EF4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80066EF8: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x80066EFC: sw          $s2, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r18;
    // 0x80066F00: jal         0x80069480
    // 0x80066F04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80069480(rdram, ctx);
        goto after_1;
    // 0x80066F04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80066F08: b           L_80066E5C
    // 0x80066F0C: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
        goto L_80066E5C;
    // 0x80066F0C: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
L_80066F10:
    // 0x80066F10: slti        $at, $s0, 0x13
    ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
L_80066F14:
    // 0x80066F14: bne         $at, $zero, L_80066F84
    if (ctx->r1 != 0) {
        // 0x80066F18: slti        $at, $s0, 0x24
        ctx->r1 = SIGNED(ctx->r16) < 0X24 ? 1 : 0;
            goto L_80066F84;
    }
    // 0x80066F18: slti        $at, $s0, 0x24
    ctx->r1 = SIGNED(ctx->r16) < 0X24 ? 1 : 0;
    // 0x80066F1C: beq         $at, $zero, L_80066F84
    if (ctx->r1 == 0) {
        // 0x80066F20: sll         $t1, $s0, 2
        ctx->r9 = S32(ctx->r16 << 2);
            goto L_80066F84;
    }
    // 0x80066F20: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x80066F24: addu        $t2, $s6, $t1
    ctx->r10 = ADD32(ctx->r22, ctx->r9);
    // 0x80066F28: lw          $t9, -0x4C($t2)
    ctx->r25 = MEM_W(ctx->r10, -0X4C);
    // 0x80066F2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80066F30: jalr        $t9
    // 0x80066F34: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80066F34: nop

    after_2:
    // 0x80066F38: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80066F3C: addu        $t7, $s3, $s0
    ctx->r15 = ADD32(ctx->r19, ctx->r16);
    // 0x80066F40: sll         $t5, $t3, 6
    ctx->r13 = S32(ctx->r11 << 6);
    // 0x80066F44: bltz        $t5, L_80066F70
    if (SIGNED(ctx->r13) < 0) {
        // 0x80066F48: nop
    
            goto L_80066F70;
    }
    // 0x80066F48: nop

    // 0x80066F4C: lw          $t6, 0x34($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X34);
    // 0x80066F50: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80066F54: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80066F58: addu        $s2, $t6, $t8
    ctx->r18 = ADD32(ctx->r14, ctx->r24);
    // 0x80066F5C: sw          $s2, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r18;
    // 0x80066F60: jal         0x80069480
    // 0x80066F64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80069480(rdram, ctx);
        goto after_3;
    // 0x80066F64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80066F68: b           L_80066E5C
    // 0x80066F6C: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
        goto L_80066E5C;
    // 0x80066F6C: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
L_80066F70:
    // 0x80066F70: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x80066F74: lw          $s2, 0x34($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X34);
    // 0x80066F78: andi        $t2, $t1, 0xFFFD
    ctx->r10 = ctx->r9 & 0XFFFD;
    // 0x80066F7C: b           L_80066E5C
    // 0x80066F80: sb          $t2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r10;
        goto L_80066E5C;
    // 0x80066F80: sb          $t2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r10;
L_80066F84:
    // 0x80066F84: lw          $t9, 0x28($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X28);
    // 0x80066F88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80066F8C: jalr        $t9
    // 0x80066F90: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80066F90: nop

    after_4:
    // 0x80066F94: lw          $s2, 0x34($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X34);
    // 0x80066F98: b           L_80066E60
    // 0x80066F9C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
        goto L_80066E60;
    // 0x80066F9C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
L_80066FA0:
    // 0x80066FA0: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80066FA4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80066FA8: addu        $s2, $a0, $t4
    ctx->r18 = ADD32(ctx->r4, ctx->r12);
    // 0x80066FAC: sw          $s2, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r18;
    // 0x80066FB0: jal         0x80069480
    // 0x80066FB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80069480(rdram, ctx);
        goto after_5;
    // 0x80066FB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80066FB8: b           L_80066E5C
    // 0x80066FBC: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
        goto L_80066E5C;
    // 0x80066FBC: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
L_80066FC0:
    // 0x80066FC0: beq         $v0, $zero, L_80066FD8
    if (ctx->r2 == 0) {
        // 0x80066FC4: subu        $t7, $s5, $s7
        ctx->r15 = SUB32(ctx->r21, ctx->r23);
            goto L_80066FD8;
    }
    // 0x80066FC4: subu        $t7, $s5, $s7
    ctx->r15 = SUB32(ctx->r21, ctx->r23);
    // 0x80066FC8: sw          $t7, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r15;
    // 0x80066FCC: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x80066FD0: b           L_80066FE4
    // 0x80066FD4: sw          $s7, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r23;
        goto L_80066FE4;
    // 0x80066FD4: sw          $s7, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r23;
L_80066FD8:
    // 0x80066FD8: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x80066FDC: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x80066FE0: sw          $s5, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r21;
L_80066FE4:
    // 0x80066FE4: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80066FE8: nop

    // 0x80066FEC: sw          $s2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r18;
    // 0x80066FF0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80066FF4: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x80066FF8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80066FFC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80067000: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80067004: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80067008: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8006700C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80067010: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80067014: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80067018: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006701C: jr          $ra
    // 0x80067020: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80067020: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80067024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067024: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80067028: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006702C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80067030: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80067034: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80067038: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8006703C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80067040: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80067044: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80067048: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006704C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80067050: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80067054: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80067058: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x8006705C: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    // 0x80067060: addiu       $s2, $sp, 0x54
    ctx->r18 = ADD32(ctx->r29, 0X54);
    // 0x80067064: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80067068: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8006706C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80067070: sw          $a0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r4;
    // 0x80067074: jal         0x80069480
    // 0x80067078: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    func_80069480(rdram, ctx);
        goto after_0;
    // 0x80067078: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    after_0:
    // 0x8006707C: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x80067080: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80067084: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
    // 0x80067088: addiu       $s3, $s3, 0xD20
    ctx->r19 = ADD32(ctx->r19, 0XD20);
    // 0x8006708C: addiu       $s6, $s6, 0xDBC
    ctx->r22 = ADD32(ctx->r22, 0XDBC);
    // 0x80067090: addiu       $fp, $zero, 0x22
    ctx->r30 = ADD32(0, 0X22);
L_80067094:
    // 0x80067094: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
L_80067098:
    // 0x80067098: nop

    // 0x8006709C: addu        $s4, $s4, $t6
    ctx->r20 = ADD32(ctx->r20, ctx->r14);
    // 0x800670A0: sltu        $at, $s4, $s7
    ctx->r1 = ctx->r20 < ctx->r23 ? 1 : 0;
    // 0x800670A4: bne         $at, $zero, L_800670B4
    if (ctx->r1 != 0) {
        // 0x800670A8: nop
    
            goto L_800670B4;
    }
    // 0x800670A8: nop

    // 0x800670AC: b           L_800671F4
    // 0x800670B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800671F4;
    // 0x800670B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800670B4:
    // 0x800670B4: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x800670B8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800670BC: lbu         $s0, 0x0($a0)
    ctx->r16 = MEM_BU(ctx->r4, 0X0);
    // 0x800670C0: nop

    // 0x800670C4: bne         $s0, $fp, L_800670D4
    if (ctx->r16 != ctx->r30) {
        // 0x800670C8: addu        $t8, $s3, $s0
        ctx->r24 = ADD32(ctx->r19, ctx->r16);
            goto L_800670D4;
    }
    // 0x800670C8: addu        $t8, $s3, $s0
    ctx->r24 = ADD32(ctx->r19, ctx->r16);
    // 0x800670CC: b           L_800671F4
    // 0x800670D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800671F4;
    // 0x800670D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800670D4:
    // 0x800670D4: beq         $s0, $at, L_800671D4
    if (ctx->r16 == ctx->r1) {
        // 0x800670D8: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_800671D4;
    }
    // 0x800670D8: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800670DC: beq         $s0, $at, L_800671D4
    if (ctx->r16 == ctx->r1) {
        // 0x800670E0: slti        $at, $s0, 0x7
        ctx->r1 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
            goto L_800671D4;
    }
    // 0x800670E0: slti        $at, $s0, 0x7
    ctx->r1 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
    // 0x800670E4: bne         $at, $zero, L_80067148
    if (ctx->r1 != 0) {
        // 0x800670E8: slti        $at, $s0, 0x13
        ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
            goto L_80067148;
    }
    // 0x800670E8: slti        $at, $s0, 0x13
    ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
    // 0x800670EC: beq         $at, $zero, L_8006714C
    if (ctx->r1 == 0) {
        // 0x800670F0: slti        $at, $s0, 0x13
        ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
            goto L_8006714C;
    }
    // 0x800670F0: slti        $at, $s0, 0x13
    ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
    // 0x800670F4: lbu         $t7, 0x10($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X10);
    // 0x800670F8: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x800670FC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80067100: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80067104: lw          $t9, 0xC50($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XC50);
    // 0x80067108: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x8006710C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80067110: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80067114: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80067118: jalr        $t9
    // 0x8006711C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8006711C: nop

    after_1:
    // 0x80067120: addu        $t3, $s3, $s0
    ctx->r11 = ADD32(ctx->r19, ctx->r16);
    // 0x80067124: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80067128: lw          $t2, 0x34($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X34);
    // 0x8006712C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80067130: addu        $s5, $t2, $t4
    ctx->r21 = ADD32(ctx->r10, ctx->r12);
    // 0x80067134: sw          $s5, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r21;
    // 0x80067138: jal         0x80069480
    // 0x8006713C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80069480(rdram, ctx);
        goto after_2;
    // 0x8006713C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x80067140: b           L_80067094
    // 0x80067144: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
        goto L_80067094;
    // 0x80067144: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
L_80067148:
    // 0x80067148: slti        $at, $s0, 0x13
    ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
L_8006714C:
    // 0x8006714C: bne         $at, $zero, L_800671BC
    if (ctx->r1 != 0) {
        // 0x80067150: slti        $at, $s0, 0x24
        ctx->r1 = SIGNED(ctx->r16) < 0X24 ? 1 : 0;
            goto L_800671BC;
    }
    // 0x80067150: slti        $at, $s0, 0x24
    ctx->r1 = SIGNED(ctx->r16) < 0X24 ? 1 : 0;
    // 0x80067154: beq         $at, $zero, L_800671BC
    if (ctx->r1 == 0) {
        // 0x80067158: sll         $t6, $s0, 2
        ctx->r14 = S32(ctx->r16 << 2);
            goto L_800671BC;
    }
    // 0x80067158: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8006715C: addu        $t7, $s6, $t6
    ctx->r15 = ADD32(ctx->r22, ctx->r14);
    // 0x80067160: lw          $t9, -0x4C($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4C);
    // 0x80067164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80067168: jalr        $t9
    // 0x8006716C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8006716C: nop

    after_3:
    // 0x80067170: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80067174: addu        $t2, $s3, $s0
    ctx->r10 = ADD32(ctx->r19, ctx->r16);
    // 0x80067178: sll         $t1, $t8, 6
    ctx->r9 = S32(ctx->r24 << 6);
    // 0x8006717C: bltz        $t1, L_800671A8
    if (SIGNED(ctx->r9) < 0) {
        // 0x80067180: nop
    
            goto L_800671A8;
    }
    // 0x80067180: nop

    // 0x80067184: lw          $t3, 0x34($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X34);
    // 0x80067188: lbu         $t4, 0x0($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X0);
    // 0x8006718C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80067190: addu        $s5, $t3, $t4
    ctx->r21 = ADD32(ctx->r11, ctx->r12);
    // 0x80067194: sw          $s5, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r21;
    // 0x80067198: jal         0x80069480
    // 0x8006719C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80069480(rdram, ctx);
        goto after_4;
    // 0x8006719C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_4:
    // 0x800671A0: b           L_80067094
    // 0x800671A4: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
        goto L_80067094;
    // 0x800671A4: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
L_800671A8:
    // 0x800671A8: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x800671AC: nop

    // 0x800671B0: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x800671B4: b           L_80067094
    // 0x800671B8: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
        goto L_80067094;
    // 0x800671B8: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
L_800671BC:
    // 0x800671BC: lw          $t9, 0x28($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X28);
    // 0x800671C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800671C4: jalr        $t9
    // 0x800671C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x800671C8: nop

    after_5:
    // 0x800671CC: b           L_80067098
    // 0x800671D0: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
        goto L_80067098;
    // 0x800671D0: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
L_800671D4:
    // 0x800671D4: lbu         $t0, 0x0($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X0);
    // 0x800671D8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800671DC: addu        $s5, $a0, $t0
    ctx->r21 = ADD32(ctx->r4, ctx->r8);
    // 0x800671E0: sw          $s5, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r21;
    // 0x800671E4: jal         0x80069480
    // 0x800671E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80069480(rdram, ctx);
        goto after_6;
    // 0x800671E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x800671EC: b           L_80067094
    // 0x800671F0: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
        goto L_80067094;
    // 0x800671F0: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
L_800671F4:
    // 0x800671F4: beq         $v0, $zero, L_8006720C
    if (ctx->r2 == 0) {
        // 0x800671F8: subu        $t2, $s4, $s7
        ctx->r10 = SUB32(ctx->r20, ctx->r23);
            goto L_8006720C;
    }
    // 0x800671F8: subu        $t2, $s4, $s7
    ctx->r10 = SUB32(ctx->r20, ctx->r23);
    // 0x800671FC: sw          $t2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r10;
    // 0x80067200: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x80067204: b           L_80067218
    // 0x80067208: sw          $s7, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r23;
        goto L_80067218;
    // 0x80067208: sw          $s7, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r23;
L_8006720C:
    // 0x8006720C: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x80067210: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x80067214: sw          $s4, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r20;
L_80067218:
    // 0x80067218: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8006721C: nop

    // 0x80067220: sw          $s5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r21;
    // 0x80067224: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80067228: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x8006722C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80067230: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80067234: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80067238: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8006723C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80067240: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80067244: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80067248: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006724C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80067250: jr          $ra
    // 0x80067254: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80067254: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80067258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067258: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8006725C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80067260: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80067264: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80067268: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8006726C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80067270: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80067274: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80067278: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006727C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80067280: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80067284: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80067288: jal         0x800629A8
    // 0x8006728C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    func_800629A8(rdram, ctx);
        goto after_0;
    // 0x8006728C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80067290: bne         $v0, $zero, L_800672A0
    if (ctx->r2 != 0) {
        // 0x80067294: nop
    
            goto L_800672A0;
    }
    // 0x80067294: nop

    // 0x80067298: b           L_80067388
    // 0x8006729C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80067388;
    // 0x8006729C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800672A0:
    // 0x800672A0: jal         0x8006885C
    // 0x800672A4: nop

    func_8006885C(rdram, ctx);
        goto after_1;
    // 0x800672A4: nop

    after_1:
    // 0x800672A8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800672AC: jal         0x80066380
    // 0x800672B0: nop

    func_80066380(rdram, ctx);
        goto after_2;
    // 0x800672B0: nop

    after_2:
    // 0x800672B4: beq         $v0, $zero, L_80067374
    if (ctx->r2 == 0) {
        // 0x800672B8: nop
    
            goto L_80067374;
    }
    // 0x800672B8: nop

    // 0x800672BC: lui         $fp, 0x800D
    ctx->r30 = S32(0X800D << 16);
    // 0x800672C0: addiu       $fp, $fp, -0x16F4
    ctx->r30 = ADD32(ctx->r30, -0X16F4);
    // 0x800672C4: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x800672C8: lbu         $s2, 0x4($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X4);
    // 0x800672CC: lbu         $s1, 0xA($t6)
    ctx->r17 = MEM_BU(ctx->r14, 0XA);
    // 0x800672D0: lw          $s3, 0xC($v0)
    ctx->r19 = MEM_W(ctx->r2, 0XC);
    // 0x800672D4: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x800672D8: beq         $s1, $zero, L_80067374
    if (ctx->r17 == 0) {
        // 0x800672DC: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80067374;
    }
    // 0x800672DC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800672E0: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x800672E4: addiu       $s6, $s6, 0xC50
    ctx->r22 = ADD32(ctx->r22, 0XC50);
    // 0x800672E8: addiu       $s7, $sp, 0x5C
    ctx->r23 = ADD32(ctx->r29, 0X5C);
    // 0x800672EC: addiu       $s5, $zero, 0x50
    ctx->r21 = ADD32(0, 0X50);
    // 0x800672F0: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
L_800672F4:
    // 0x800672F4: lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X0);
    // 0x800672F8: nop

    // 0x800672FC: beq         $s4, $v0, L_80067368
    if (ctx->r20 == ctx->r2) {
        // 0x80067300: or          $v1, $s1, $zero
        ctx->r3 = ctx->r17 | 0;
            goto L_80067368;
    }
    // 0x80067300: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80067304: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80067308: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8006730C: nop

    // 0x80067310: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x80067314: mflo        $t7
    ctx->r15 = lo;
    // 0x80067318: addu        $s0, $t7, $t9
    ctx->r16 = ADD32(ctx->r15, ctx->r25);
    // 0x8006731C: lbu         $t0, 0x10($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X10);
    // 0x80067320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80067324: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80067328: addu        $t2, $s6, $t1
    ctx->r10 = ADD32(ctx->r22, ctx->r9);
    // 0x8006732C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80067330: nop

    // 0x80067334: lw          $t9, 0x18($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X18);
    // 0x80067338: nop

    // 0x8006733C: jalr        $t9
    // 0x80067340: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80067340: nop

    after_3:
    // 0x80067344: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80067348: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x8006734C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80067350: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80067354: jal         0x80066DF0
    // 0x80067358: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    func_80066DF0(rdram, ctx);
        goto after_4;
    // 0x80067358: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_4:
    // 0x8006735C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80067360: beq         $s2, $zero, L_80067374
    if (ctx->r18 == 0) {
        // 0x80067364: or          $v1, $s1, $zero
        ctx->r3 = ctx->r17 | 0;
            goto L_80067374;
    }
    // 0x80067364: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_80067368:
    // 0x80067368: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8006736C: bne         $s1, $zero, L_800672F4
    if (ctx->r17 != 0) {
        // 0x80067370: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_800672F4;
    }
    // 0x80067370: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80067374:
    // 0x80067374: jal         0x8006889C
    // 0x80067378: nop

    func_8006889C(rdram, ctx);
        goto after_5;
    // 0x80067378: nop

    after_5:
    // 0x8006737C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80067380: jal         0x80067510
    // 0x80067384: nop

    func_80067510(rdram, ctx);
        goto after_6;
    // 0x80067384: nop

    after_6:
L_80067388:
    // 0x80067388: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8006738C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80067390: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80067394: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80067398: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006739C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800673A0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800673A4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800673A8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800673AC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800673B0: jr          $ra
    // 0x800673B4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800673B4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800673B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800673B8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800673BC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800673C0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800673C4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800673C8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800673CC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800673D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800673D4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800673D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800673DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800673E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800673E4: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800673E8: jal         0x800629A8
    // 0x800673EC: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    func_800629A8(rdram, ctx);
        goto after_0;
    // 0x800673EC: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    after_0:
    // 0x800673F0: bne         $v0, $zero, L_80067400
    if (ctx->r2 != 0) {
        // 0x800673F4: nop
    
            goto L_80067400;
    }
    // 0x800673F4: nop

    // 0x800673F8: b           L_800674E0
    // 0x800673FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800674E0;
    // 0x800673FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80067400:
    // 0x80067400: jal         0x8006885C
    // 0x80067404: nop

    func_8006885C(rdram, ctx);
        goto after_1;
    // 0x80067404: nop

    after_1:
    // 0x80067408: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8006740C: jal         0x80066380
    // 0x80067410: nop

    func_80066380(rdram, ctx);
        goto after_2;
    // 0x80067410: nop

    after_2:
    // 0x80067414: beq         $v0, $zero, L_800674CC
    if (ctx->r2 == 0) {
        // 0x80067418: nop
    
            goto L_800674CC;
    }
    // 0x80067418: nop

    // 0x8006741C: lui         $fp, 0x800D
    ctx->r30 = S32(0X800D << 16);
    // 0x80067420: addiu       $fp, $fp, -0x16F4
    ctx->r30 = ADD32(ctx->r30, -0X16F4);
    // 0x80067424: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80067428: lbu         $s2, 0x4($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X4);
    // 0x8006742C: lbu         $s1, 0xA($t6)
    ctx->r17 = MEM_BU(ctx->r14, 0XA);
    // 0x80067430: lw          $s3, 0xC($v0)
    ctx->r19 = MEM_W(ctx->r2, 0XC);
    // 0x80067434: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80067438: beq         $s1, $zero, L_800674CC
    if (ctx->r17 == 0) {
        // 0x8006743C: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_800674CC;
    }
    // 0x8006743C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80067440: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x80067444: addiu       $s6, $s6, 0xC50
    ctx->r22 = ADD32(ctx->r22, 0XC50);
    // 0x80067448: addiu       $s7, $sp, 0x54
    ctx->r23 = ADD32(ctx->r29, 0X54);
    // 0x8006744C: addiu       $s5, $zero, 0x50
    ctx->r21 = ADD32(0, 0X50);
    // 0x80067450: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
L_80067454:
    // 0x80067454: lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X0);
    // 0x80067458: nop

    // 0x8006745C: beq         $s4, $v0, L_800674C0
    if (ctx->r20 == ctx->r2) {
        // 0x80067460: or          $v1, $s1, $zero
        ctx->r3 = ctx->r17 | 0;
            goto L_800674C0;
    }
    // 0x80067460: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80067464: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80067468: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8006746C: nop

    // 0x80067470: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x80067474: mflo        $t7
    ctx->r15 = lo;
    // 0x80067478: addu        $s0, $t7, $t9
    ctx->r16 = ADD32(ctx->r15, ctx->r25);
    // 0x8006747C: lbu         $t0, 0x10($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X10);
    // 0x80067480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80067484: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80067488: addu        $t2, $s6, $t1
    ctx->r10 = ADD32(ctx->r22, ctx->r9);
    // 0x8006748C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80067490: nop

    // 0x80067494: lw          $t9, 0x18($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X18);
    // 0x80067498: nop

    // 0x8006749C: jalr        $t9
    // 0x800674A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800674A0: nop

    after_3:
    // 0x800674A4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800674A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800674AC: jal         0x80067024
    // 0x800674B0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_80067024(rdram, ctx);
        goto after_4;
    // 0x800674B0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_4:
    // 0x800674B4: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800674B8: beq         $s2, $zero, L_800674CC
    if (ctx->r18 == 0) {
        // 0x800674BC: or          $v1, $s1, $zero
        ctx->r3 = ctx->r17 | 0;
            goto L_800674CC;
    }
    // 0x800674BC: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_800674C0:
    // 0x800674C0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800674C4: bne         $s1, $zero, L_80067454
    if (ctx->r17 != 0) {
        // 0x800674C8: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80067454;
    }
    // 0x800674C8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_800674CC:
    // 0x800674CC: jal         0x8006889C
    // 0x800674D0: nop

    func_8006889C(rdram, ctx);
        goto after_5;
    // 0x800674D0: nop

    after_5:
    // 0x800674D4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800674D8: jal         0x80067510
    // 0x800674DC: nop

    func_80067510(rdram, ctx);
        goto after_6;
    // 0x800674DC: nop

    after_6:
L_800674E0:
    // 0x800674E0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800674E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800674E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800674EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800674F0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800674F4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800674F8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800674FC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80067500: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80067504: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80067508: jr          $ra
    // 0x8006750C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006750C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80067510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067510: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80067518: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006751C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80067520: jal         0x800629A8
    // 0x80067524: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800629A8(rdram, ctx);
        goto after_0;
    // 0x80067524: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x80067528: bne         $v0, $zero, L_80067538
    if (ctx->r2 != 0) {
        // 0x8006752C: nop
    
            goto L_80067538;
    }
    // 0x8006752C: nop

    // 0x80067530: b           L_800675D0
    // 0x80067534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800675D0;
    // 0x80067534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80067538:
    // 0x80067538: jal         0x8006885C
    // 0x8006753C: nop

    func_8006885C(rdram, ctx);
        goto after_1;
    // 0x8006753C: nop

    after_1:
    // 0x80067540: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80067544: jal         0x80066380
    // 0x80067548: nop

    func_80066380(rdram, ctx);
        goto after_2;
    // 0x80067548: nop

    after_2:
    // 0x8006754C: beq         $v0, $zero, L_800675C4
    if (ctx->r2 == 0) {
        // 0x80067550: lui         $t2, 0x800D
        ctx->r10 = S32(0X800D << 16);
            goto L_800675C4;
    }
    // 0x80067550: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80067554: lw          $t2, -0x16F4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X16F4);
    // 0x80067558: lbu         $a2, 0x4($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X4);
    // 0x8006755C: lbu         $a1, 0xA($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0XA);
    // 0x80067560: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x80067564: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80067568: beq         $a1, $zero, L_800675C4
    if (ctx->r5 == 0) {
        // 0x8006756C: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800675C4;
    }
    // 0x8006756C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80067570: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x80067574: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_80067578:
    // 0x80067578: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x8006757C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80067580: beq         $t0, $v1, L_800675B8
    if (ctx->r8 == ctx->r3) {
        // 0x80067584: nop
    
            goto L_800675B8;
    }
    // 0x80067584: nop

    // 0x80067588: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006758C: lw          $t7, 0x1C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X1C);
    // 0x80067590: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80067594: mflo        $t6
    ctx->r14 = lo;
    // 0x80067598: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8006759C: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    // 0x800675A0: nop

    // 0x800675A4: sltu        $at, $s0, $a0
    ctx->r1 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x800675A8: beq         $at, $zero, L_800675B4
    if (ctx->r1 == 0) {
        // 0x800675AC: nop
    
            goto L_800675B4;
    }
    // 0x800675AC: nop

    // 0x800675B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
L_800675B4:
    // 0x800675B4: beq         $a2, $zero, L_800675C4
    if (ctx->r6 == 0) {
        // 0x800675B8: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800675C4;
    }
L_800675B8:
    // 0x800675B8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800675BC: bne         $a1, $zero, L_80067578
    if (ctx->r5 != 0) {
        // 0x800675C0: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_80067578;
    }
    // 0x800675C0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_800675C4:
    // 0x800675C4: jal         0x8006889C
    // 0x800675C8: nop

    func_8006889C(rdram, ctx);
        goto after_3;
    // 0x800675C8: nop

    after_3:
    // 0x800675CC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800675D0:
    // 0x800675D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800675D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800675D8: jr          $ra
    // 0x800675DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800675DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800675E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800675E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800675E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800675E8: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x800675EC: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x800675F0: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800675F4: lw          $t9, 0x34($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X34);
    // 0x800675F8: sra         $t0, $a1, 8
    ctx->r8 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800675FC: sb          $a1, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r5;
    // 0x80067600: lw          $t1, 0x34($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X34);
    // 0x80067604: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80067608: sb          $t0, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r8;
    // 0x8006760C: lbu         $t2, 0x10($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X10);
    // 0x80067610: nop

    // 0x80067614: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80067618: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006761C: lw          $t4, 0xC50($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XC50);
    // 0x80067620: nop

    // 0x80067624: lw          $t9, 0x1C($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X1C);
    // 0x80067628: nop

    // 0x8006762C: jalr        $t9
    // 0x80067630: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80067630: nop

    after_0:
    // 0x80067634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006763C: jr          $ra
    // 0x80067640: nop

    return;
    // 0x80067640: nop

;}
RECOMP_FUNC void func_80067644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067644: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006764C: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x80067650: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80067654: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80067658: lw          $t9, 0x34($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X34);
    // 0x8006765C: sra         $t0, $a1, 8
    ctx->r8 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067660: sb          $a1, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r5;
    // 0x80067664: lw          $t1, 0x34($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X34);
    // 0x80067668: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x8006766C: sb          $t0, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r8;
    // 0x80067670: lbu         $t2, 0x10($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X10);
    // 0x80067674: nop

    // 0x80067678: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8006767C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80067680: lw          $t4, 0xC50($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XC50);
    // 0x80067684: nop

    // 0x80067688: lw          $t9, 0x24($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X24);
    // 0x8006768C: nop

    // 0x80067690: jalr        $t9
    // 0x80067694: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80067694: nop

    after_0:
    // 0x80067698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006769C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800676A0: jr          $ra
    // 0x800676A4: nop

    return;
    // 0x800676A4: nop

;}
RECOMP_FUNC void func_800676A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800676A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800676AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800676B0: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x800676B4: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x800676B8: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800676BC: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x800676C0: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x800676C4: sb          $a1, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r5;
    // 0x800676C8: lbu         $t9, 0x10($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X10);
    // 0x800676CC: nop

    // 0x800676D0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800676D4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800676D8: lw          $t1, 0xC50($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XC50);
    // 0x800676DC: nop

    // 0x800676E0: lw          $t9, 0x30($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X30);
    // 0x800676E4: nop

    // 0x800676E8: jalr        $t9
    // 0x800676EC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800676EC: nop

    after_0:
    // 0x800676F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800676F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800676F8: jr          $ra
    // 0x800676FC: nop

    return;
    // 0x800676FC: nop

;}
RECOMP_FUNC void func_80067700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067708: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x8006770C: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x80067710: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80067714: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x80067718: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8006771C: sb          $a1, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r5;
    // 0x80067720: lbu         $t9, 0x10($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X10);
    // 0x80067724: nop

    // 0x80067728: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006772C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80067730: lw          $t1, 0xC50($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XC50);
    // 0x80067734: nop

    // 0x80067738: lw          $t9, 0x34($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X34);
    // 0x8006773C: nop

    // 0x80067740: jalr        $t9
    // 0x80067744: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80067744: nop

    after_0:
    // 0x80067748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006774C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067750: jr          $ra
    // 0x80067754: nop

    return;
    // 0x80067754: nop

;}
RECOMP_FUNC void func_80067758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067758: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006775C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067760: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x80067764: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80067768: addiu       $t7, $t7, -0x16E0
    ctx->r15 = ADD32(ctx->r15, -0X16E0);
    // 0x8006776C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80067770: sw          $t7, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r15;
    // 0x80067774: jalr        $a2
    // 0x80067778: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r6)(rdram, ctx);
        goto after_0;
    // 0x80067778: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006777C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80067780: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80067784: nop

    // 0x80067788: sw          $t8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r24;
    // 0x8006778C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067790: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80067794: jr          $ra
    // 0x80067798: nop

    return;
    // 0x80067798: nop

;}
RECOMP_FUNC void func_8006779C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006779C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800677A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800677A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800677A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800677AC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800677B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800677B4: andi        $t8, $t6, 0xFFF7
    ctx->r24 = ctx->r14 & 0XFFF7;
    // 0x800677B8: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x800677BC: andi        $t9, $t8, 0xFB
    ctx->r25 = ctx->r24 & 0XFB;
    // 0x800677C0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800677C4: beq         $a1, $zero, L_800679F4
    if (ctx->r5 == 0) {
        // 0x800677C8: sb          $t9, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r25;
            goto L_800679F4;
    }
    // 0x800677C8: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x800677CC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800677D0: nop

    // 0x800677D4: beq         $v0, $zero, L_800679F4
    if (ctx->r2 == 0) {
        // 0x800677D8: andi        $t0, $v0, 0x1
        ctx->r8 = ctx->r2 & 0X1;
            goto L_800679F4;
    }
    // 0x800677D8: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x800677DC: beq         $t0, $zero, L_80067814
    if (ctx->r8 == 0) {
        // 0x800677E0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80067814;
    }
    // 0x800677E0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800677E4: lbu         $t1, 0x4($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X4);
    // 0x800677E8: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x800677EC: sb          $t1, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r9;
    // 0x800677F0: lbu         $a1, 0x4($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X4);
    // 0x800677F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800677F8: jal         0x80067758
    // 0x800677FC: addiu       $a2, $a2, 0x76A8
    ctx->r6 = ADD32(ctx->r6, 0X76A8);
    func_80067758(rdram, ctx);
        goto after_0;
    // 0x800677FC: addiu       $a2, $a2, 0x76A8
    ctx->r6 = ADD32(ctx->r6, 0X76A8);
    after_0:
    // 0x80067800: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80067804: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80067808: and         $t2, $v1, $at
    ctx->r10 = ctx->r3 & ctx->r1;
    // 0x8006780C: beq         $t2, $zero, L_800679F4
    if (ctx->r10 == 0) {
        // 0x80067810: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_800679F4;
    }
    // 0x80067810: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_80067814:
    // 0x80067814: andi        $t3, $v1, 0x2
    ctx->r11 = ctx->r3 & 0X2;
    // 0x80067818: beq         $t3, $zero, L_80067850
    if (ctx->r11 == 0) {
        // 0x8006781C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80067850;
    }
    // 0x8006781C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80067820: lbu         $t4, 0x5($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X5);
    // 0x80067824: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80067828: sb          $t4, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r12;
    // 0x8006782C: lbu         $a1, 0x5($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X5);
    // 0x80067830: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80067834: jal         0x80067758
    // 0x80067838: addiu       $a2, $a2, 0x7700
    ctx->r6 = ADD32(ctx->r6, 0X7700);
    func_80067758(rdram, ctx);
        goto after_1;
    // 0x80067838: addiu       $a2, $a2, 0x7700
    ctx->r6 = ADD32(ctx->r6, 0X7700);
    after_1:
    // 0x8006783C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80067840: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80067844: and         $t5, $v1, $at
    ctx->r13 = ctx->r3 & ctx->r1;
    // 0x80067848: beq         $t5, $zero, L_800679F4
    if (ctx->r13 == 0) {
        // 0x8006784C: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_800679F4;
    }
    // 0x8006784C: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_80067850:
    // 0x80067850: andi        $t6, $v1, 0x4
    ctx->r14 = ctx->r3 & 0X4;
    // 0x80067854: beq         $t6, $zero, L_8006788C
    if (ctx->r14 == 0) {
        // 0x80067858: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8006788C;
    }
    // 0x80067858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006785C: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x80067860: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80067864: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    // 0x80067868: lh          $a1, 0x6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X6);
    // 0x8006786C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80067870: jal         0x80067758
    // 0x80067874: addiu       $a2, $a2, 0x75E0
    ctx->r6 = ADD32(ctx->r6, 0X75E0);
    func_80067758(rdram, ctx);
        goto after_2;
    // 0x80067874: addiu       $a2, $a2, 0x75E0
    ctx->r6 = ADD32(ctx->r6, 0X75E0);
    after_2:
    // 0x80067878: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8006787C: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80067880: and         $t8, $v1, $at
    ctx->r24 = ctx->r3 & ctx->r1;
    // 0x80067884: beq         $t8, $zero, L_800679F4
    if (ctx->r24 == 0) {
        // 0x80067888: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800679F4;
    }
    // 0x80067888: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8006788C:
    // 0x8006788C: andi        $t9, $v1, 0x8
    ctx->r25 = ctx->r3 & 0X8;
    // 0x80067890: beq         $t9, $zero, L_800678C8
    if (ctx->r25 == 0) {
        // 0x80067894: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800678C8;
    }
    // 0x80067894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80067898: lh          $t0, 0x8($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X8);
    // 0x8006789C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x800678A0: sh          $t0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r8;
    // 0x800678A4: lh          $a1, 0x8($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X8);
    // 0x800678A8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800678AC: jal         0x80067758
    // 0x800678B0: addiu       $a2, $a2, 0x7644
    ctx->r6 = ADD32(ctx->r6, 0X7644);
    func_80067758(rdram, ctx);
        goto after_3;
    // 0x800678B0: addiu       $a2, $a2, 0x7644
    ctx->r6 = ADD32(ctx->r6, 0X7644);
    after_3:
    // 0x800678B4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800678B8: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800678BC: and         $t1, $v1, $at
    ctx->r9 = ctx->r3 & ctx->r1;
    // 0x800678C0: beq         $t1, $zero, L_800679F4
    if (ctx->r9 == 0) {
        // 0x800678C4: or          $v1, $t1, $zero
        ctx->r3 = ctx->r9 | 0;
            goto L_800679F4;
    }
    // 0x800678C4: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_800678C8:
    // 0x800678C8: andi        $t2, $v1, 0x10
    ctx->r10 = ctx->r3 & 0X10;
    // 0x800678CC: beq         $t2, $zero, L_80067954
    if (ctx->r10 == 0) {
        // 0x800678D0: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80067954;
    }
    // 0x800678D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800678D4: lbu         $t4, 0xA($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0XA);
    // 0x800678D8: lbu         $t3, 0xF($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XF);
    // 0x800678DC: sllv        $t6, $t5, $t4
    ctx->r14 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x800678E0: and         $t7, $t3, $t6
    ctx->r15 = ctx->r11 & ctx->r14;
    // 0x800678E4: beq         $t7, $zero, L_80067934
    if (ctx->r15 == 0) {
        // 0x800678E8: nop
    
            goto L_80067934;
    }
    // 0x800678E8: nop

    // 0x800678EC: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x800678F0: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x800678F4: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x800678F8: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
    // 0x800678FC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80067900: lbu         $t1, 0x10($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X10);
    // 0x80067904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80067908: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8006790C: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x80067910: lw          $t5, 0xC50($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XC50);
    // 0x80067914: nop

    // 0x80067918: lw          $t9, 0x18($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X18);
    // 0x8006791C: nop

    // 0x80067920: jalr        $t9
    // 0x80067924: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80067924: nop

    after_4:
    // 0x80067928: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8006792C: b           L_80067948
    // 0x80067930: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
        goto L_80067948;
    // 0x80067930: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
L_80067934:
    // 0x80067934: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x80067938: nop

    // 0x8006793C: andi        $t3, $t4, 0xFFBF
    ctx->r11 = ctx->r12 & 0XFFBF;
    // 0x80067940: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x80067944: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
L_80067948:
    // 0x80067948: and         $t6, $v1, $at
    ctx->r14 = ctx->r3 & ctx->r1;
    // 0x8006794C: beq         $t6, $zero, L_800679F4
    if (ctx->r14 == 0) {
        // 0x80067950: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800679F4;
    }
    // 0x80067950: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80067954:
    // 0x80067954: andi        $t7, $v1, 0x20
    ctx->r15 = ctx->r3 & 0X20;
    // 0x80067958: beq         $t7, $zero, L_800679A8
    if (ctx->r15 == 0) {
        // 0x8006795C: andi        $t2, $v1, 0x40
        ctx->r10 = ctx->r3 & 0X40;
            goto L_800679A8;
    }
    // 0x8006795C: andi        $t2, $v1, 0x40
    ctx->r10 = ctx->r3 & 0X40;
    // 0x80067960: lhu         $t8, 0xC($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0XC);
    // 0x80067964: nop

    // 0x80067968: sh          $t8, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r24;
    // 0x8006796C: jal         0x800688DC
    // 0x80067970: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800688DC(rdram, ctx);
        goto after_5;
    // 0x80067970: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_5:
    // 0x80067974: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80067978: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8006797C: lh          $a1, 0x14($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X14);
    // 0x80067980: lh          $a2, 0x16($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X16);
    // 0x80067984: jal         0x800688E4
    // 0x80067988: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800688E4(rdram, ctx);
        goto after_6;
    // 0x80067988: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_6:
    // 0x8006798C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80067990: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80067994: and         $t1, $v1, $at
    ctx->r9 = ctx->r3 & ctx->r1;
    // 0x80067998: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x8006799C: beq         $t1, $zero, L_800679F4
    if (ctx->r9 == 0) {
        // 0x800679A0: or          $v1, $t1, $zero
        ctx->r3 = ctx->r9 | 0;
            goto L_800679F4;
    }
    // 0x800679A0: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800679A4: andi        $t2, $v1, 0x40
    ctx->r10 = ctx->r3 & 0X40;
L_800679A8:
    // 0x800679A8: beq         $t2, $zero, L_800679D8
    if (ctx->r10 == 0) {
        // 0x800679AC: addiu       $at, $zero, -0x41
        ctx->r1 = ADD32(0, -0X41);
            goto L_800679D8;
    }
    // 0x800679AC: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x800679B0: lw          $t5, 0x28($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28);
    // 0x800679B4: lw          $t9, 0x10($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X10);
    // 0x800679B8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x800679BC: and         $t8, $v1, $at
    ctx->r24 = ctx->r3 & ctx->r1;
    // 0x800679C0: addu        $t4, $t5, $t9
    ctx->r12 = ADD32(ctx->r13, ctx->r25);
    // 0x800679C4: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x800679C8: sw          $t4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r12;
    // 0x800679CC: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x800679D0: beq         $t8, $zero, L_800679F4
    if (ctx->r24 == 0) {
        // 0x800679D4: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800679F4;
    }
    // 0x800679D4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800679D8:
    // 0x800679D8: andi        $t0, $v1, 0x80
    ctx->r8 = ctx->r3 & 0X80;
    // 0x800679DC: beq         $t0, $zero, L_800679F8
    if (ctx->r8 == 0) {
        // 0x800679E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800679F8;
    }
    // 0x800679E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800679E4: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x800679E8: nop

    // 0x800679EC: ori         $t5, $t2, 0x4
    ctx->r13 = ctx->r10 | 0X4;
    // 0x800679F0: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
L_800679F4:
    // 0x800679F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800679F8:
    // 0x800679F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800679FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80067A00: jr          $ra
    // 0x80067A04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80067A04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80067A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A08: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80067A0C: nop

    // 0x80067A10: beq         $v0, $zero, L_80067B5C
    if (ctx->r2 == 0) {
        // 0x80067A14: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_80067B5C;
    }
    // 0x80067A14: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80067A18: beq         $t6, $zero, L_80067A34
    if (ctx->r14 == 0) {
        // 0x80067A1C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80067A34;
    }
    // 0x80067A1C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80067A20: lbu         $t7, 0xD($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XD);
    // 0x80067A24: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80067A28: and         $v1, $v0, $at
    ctx->r3 = ctx->r2 & ctx->r1;
    // 0x80067A2C: beq         $v1, $zero, L_80067B5C
    if (ctx->r3 == 0) {
        // 0x80067A30: sb          $t7, 0x4($a1)
        MEM_B(0X4, ctx->r5) = ctx->r15;
            goto L_80067B5C;
    }
    // 0x80067A30: sb          $t7, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r15;
L_80067A34:
    // 0x80067A34: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
    // 0x80067A38: beq         $t9, $zero, L_80067A54
    if (ctx->r25 == 0) {
        // 0x80067A3C: addiu       $at, $zero, -0x3
        ctx->r1 = ADD32(0, -0X3);
            goto L_80067A54;
    }
    // 0x80067A3C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80067A40: lbu         $t0, 0xE($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XE);
    // 0x80067A44: and         $t1, $v1, $at
    ctx->r9 = ctx->r3 & ctx->r1;
    // 0x80067A48: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80067A4C: beq         $t1, $zero, L_80067B5C
    if (ctx->r9 == 0) {
        // 0x80067A50: sb          $t0, 0x5($a1)
        MEM_B(0X5, ctx->r5) = ctx->r8;
            goto L_80067B5C;
    }
    // 0x80067A50: sb          $t0, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r8;
L_80067A54:
    // 0x80067A54: andi        $t2, $v1, 0x4
    ctx->r10 = ctx->r3 & 0X4;
    // 0x80067A58: beq         $t2, $zero, L_80067A74
    if (ctx->r10 == 0) {
        // 0x80067A5C: addiu       $at, $zero, -0x5
        ctx->r1 = ADD32(0, -0X5);
            goto L_80067A74;
    }
    // 0x80067A5C: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80067A60: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x80067A64: and         $t4, $v1, $at
    ctx->r12 = ctx->r3 & ctx->r1;
    // 0x80067A68: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80067A6C: beq         $t4, $zero, L_80067B5C
    if (ctx->r12 == 0) {
        // 0x80067A70: sh          $t3, 0x6($a1)
        MEM_H(0X6, ctx->r5) = ctx->r11;
            goto L_80067B5C;
    }
    // 0x80067A70: sh          $t3, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r11;
L_80067A74:
    // 0x80067A74: andi        $t5, $v1, 0x8
    ctx->r13 = ctx->r3 & 0X8;
    // 0x80067A78: beq         $t5, $zero, L_80067A94
    if (ctx->r13 == 0) {
        // 0x80067A7C: addiu       $at, $zero, -0x9
        ctx->r1 = ADD32(0, -0X9);
            goto L_80067A94;
    }
    // 0x80067A7C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80067A80: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80067A84: and         $t7, $v1, $at
    ctx->r15 = ctx->r3 & ctx->r1;
    // 0x80067A88: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80067A8C: beq         $t7, $zero, L_80067B5C
    if (ctx->r15 == 0) {
        // 0x80067A90: sh          $t6, 0x8($a1)
        MEM_H(0X8, ctx->r5) = ctx->r14;
            goto L_80067B5C;
    }
    // 0x80067A90: sh          $t6, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r14;
L_80067A94:
    // 0x80067A94: andi        $t8, $v1, 0x10
    ctx->r24 = ctx->r3 & 0X10;
    // 0x80067A98: beq         $t8, $zero, L_80067AB4
    if (ctx->r24 == 0) {
        // 0x80067A9C: addiu       $at, $zero, -0x11
        ctx->r1 = ADD32(0, -0X11);
            goto L_80067AB4;
    }
    // 0x80067A9C: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80067AA0: lbu         $t9, 0xF($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XF);
    // 0x80067AA4: and         $t0, $v1, $at
    ctx->r8 = ctx->r3 & ctx->r1;
    // 0x80067AA8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80067AAC: beq         $t0, $zero, L_80067B5C
    if (ctx->r8 == 0) {
        // 0x80067AB0: sb          $t9, 0xA($a1)
        MEM_B(0XA, ctx->r5) = ctx->r25;
            goto L_80067B5C;
    }
    // 0x80067AB0: sb          $t9, 0xA($a1)
    MEM_B(0XA, ctx->r5) = ctx->r25;
L_80067AB4:
    // 0x80067AB4: andi        $t1, $v1, 0x20
    ctx->r9 = ctx->r3 & 0X20;
    // 0x80067AB8: beq         $t1, $zero, L_80067AD4
    if (ctx->r9 == 0) {
        // 0x80067ABC: addiu       $at, $zero, -0x21
        ctx->r1 = ADD32(0, -0X21);
            goto L_80067AD4;
    }
    // 0x80067ABC: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80067AC0: lh          $t2, 0x16($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X16);
    // 0x80067AC4: and         $t3, $v1, $at
    ctx->r11 = ctx->r3 & ctx->r1;
    // 0x80067AC8: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80067ACC: beq         $t3, $zero, L_80067B5C
    if (ctx->r11 == 0) {
        // 0x80067AD0: sh          $t2, 0xC($a1)
        MEM_H(0XC, ctx->r5) = ctx->r10;
            goto L_80067B5C;
    }
    // 0x80067AD0: sh          $t2, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r10;
L_80067AD4:
    // 0x80067AD4: andi        $t4, $v1, 0x40
    ctx->r12 = ctx->r3 & 0X40;
    // 0x80067AD8: beq         $t4, $zero, L_80067B30
    if (ctx->r12 == 0) {
        // 0x80067ADC: andi        $t4, $v1, 0x80
        ctx->r12 = ctx->r3 & 0X80;
            goto L_80067B30;
    }
    // 0x80067ADC: andi        $t4, $v1, 0x80
    ctx->r12 = ctx->r3 & 0X80;
    // 0x80067AE0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80067AE4: nop

    // 0x80067AE8: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x80067AEC: bltz        $t7, L_80067B08
    if (SIGNED(ctx->r15) < 0) {
        // 0x80067AF0: nop
    
            goto L_80067B08;
    }
    // 0x80067AF0: nop

    // 0x80067AF4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80067AF8: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80067AFC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80067B00: b           L_80067B1C
    // 0x80067B04: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
        goto L_80067B1C;
    // 0x80067B04: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_80067B08:
    // 0x80067B08: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x80067B0C: lw          $t1, 0x28($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X28);
    // 0x80067B10: nop

    // 0x80067B14: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80067B18: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
L_80067B1C:
    // 0x80067B1C: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80067B20: and         $t3, $v1, $at
    ctx->r11 = ctx->r3 & ctx->r1;
    // 0x80067B24: beq         $t3, $zero, L_80067B5C
    if (ctx->r11 == 0) {
        // 0x80067B28: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80067B5C;
    }
    // 0x80067B28: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80067B2C: andi        $t4, $v1, 0x80
    ctx->r12 = ctx->r3 & 0X80;
L_80067B30:
    // 0x80067B30: beq         $t4, $zero, L_80067B5C
    if (ctx->r12 == 0) {
        // 0x80067B34: nop
    
            goto L_80067B5C;
    }
    // 0x80067B34: nop

    // 0x80067B38: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80067B3C: nop

    // 0x80067B40: sll         $t7, $t5, 5
    ctx->r15 = S32(ctx->r13 << 5);
    // 0x80067B44: bltz        $t7, L_80067B5C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80067B48: nop
    
            goto L_80067B5C;
    }
    // 0x80067B48: nop

    // 0x80067B4C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80067B50: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80067B54: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80067B58: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_80067B5C:
    // 0x80067B5C: jr          $ra
    // 0x80067B60: nop

    return;
    // 0x80067B60: nop

    // 0x80067B64: nop

    // 0x80067B68: nop

    // 0x80067B6C: nop

;}
RECOMP_FUNC void func_80067B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067B74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067B78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067B7C: lhu         $a2, 0x22($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X22);
    // 0x80067B80: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80067B84: jal         0x800680DC
    // 0x80067B88: addiu       $a3, $a3, 0x75E0
    ctx->r7 = ADD32(ctx->r7, 0X75E0);
    func_800680DC(rdram, ctx);
        goto after_0;
    // 0x80067B88: addiu       $a3, $a3, 0x75E0
    ctx->r7 = ADD32(ctx->r7, 0X75E0);
    after_0:
    // 0x80067B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067B90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067B94: jr          $ra
    // 0x80067B98: nop

    return;
    // 0x80067B98: nop

;}
RECOMP_FUNC void func_80067B9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067BA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067BA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067BA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067BAC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067BB0: jal         0x8006885C
    // 0x80067BB4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_8006885C(rdram, ctx);
        goto after_0;
    // 0x80067BB4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80067BB8: jal         0x800691F0
    // 0x80067BBC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800691F0(rdram, ctx);
        goto after_1;
    // 0x80067BBC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x80067BC0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80067BC4: jal         0x80069248
    // 0x80067BC8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80069248(rdram, ctx);
        goto after_2;
    // 0x80067BC8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80067BCC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80067BD0: jal         0x80069248
    // 0x80067BD4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80069248(rdram, ctx);
        goto after_3;
    // 0x80067BD4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80067BD8: addiu       $a0, $sp, 0x23
    ctx->r4 = ADD32(ctx->r29, 0X23);
    // 0x80067BDC: jal         0x80069248
    // 0x80067BE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80069248(rdram, ctx);
        goto after_4;
    // 0x80067BE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80067BE4: addiu       $a0, $sp, 0x27
    ctx->r4 = ADD32(ctx->r29, 0X27);
    // 0x80067BE8: jal         0x80069248
    // 0x80067BEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80069248(rdram, ctx);
        goto after_5;
    // 0x80067BEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80067BF0: jal         0x8006889C
    // 0x80067BF4: nop

    func_8006889C(rdram, ctx);
        goto after_6;
    // 0x80067BF4: nop

    after_6:
    // 0x80067BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067C00: jr          $ra
    // 0x80067C04: nop

    return;
    // 0x80067C04: nop

;}
RECOMP_FUNC void func_80067C08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067C08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80067C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067C10: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80067C14: jal         0x800692F4
    // 0x80067C18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800692F4(rdram, ctx);
        goto after_0;
    // 0x80067C18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80067C1C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80067C20: jal         0x800692F4
    // 0x80067C24: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800692F4(rdram, ctx);
        goto after_1;
    // 0x80067C24: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80067C28: addiu       $a0, $sp, 0x1F
    ctx->r4 = ADD32(ctx->r29, 0X1F);
    // 0x80067C2C: jal         0x800692F4
    // 0x80067C30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800692F4(rdram, ctx);
        goto after_2;
    // 0x80067C30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80067C34: addiu       $a0, $sp, 0x1E
    ctx->r4 = ADD32(ctx->r29, 0X1E);
    // 0x80067C38: jal         0x800692F4
    // 0x80067C3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800692F4(rdram, ctx);
        goto after_3;
    // 0x80067C3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80067C40: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80067C44: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80067C48: lbu         $a2, 0x1F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1F);
    // 0x80067C4C: lbu         $a3, 0x1E($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X1E);
    // 0x80067C50: jal         0x80067C68
    // 0x80067C54: nop

    func_80067C68(rdram, ctx);
        goto after_4;
    // 0x80067C54: nop

    after_4:
    // 0x80067C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067C5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80067C60: jr          $ra
    // 0x80067C64: nop

    return;
    // 0x80067C64: nop

;}
RECOMP_FUNC void func_80067C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067C68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067C6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067C70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80067C74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80067C78: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80067C7C: jal         0x800629A8
    // 0x80067C80: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800629A8(rdram, ctx);
        goto after_0;
    // 0x80067C80: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80067C84: beq         $v0, $zero, L_80067D30
    if (ctx->r2 == 0) {
        // 0x80067C88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80067D30;
    }
    // 0x80067C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067C8C: jal         0x8006885C
    // 0x80067C90: nop

    func_8006885C(rdram, ctx);
        goto after_1;
    // 0x80067C90: nop

    after_1:
    // 0x80067C94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80067C98: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80067C9C: jal         0x800663E0
    // 0x80067CA0: nop

    func_800663E0(rdram, ctx);
        goto after_2;
    // 0x80067CA0: nop

    after_2:
    // 0x80067CA4: beq         $v0, $zero, L_80067D24
    if (ctx->r2 == 0) {
        // 0x80067CA8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80067D24;
    }
    // 0x80067CA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80067CAC: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x80067CB0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80067CB4: addiu       $v0, $v0, -0x16E0
    ctx->r2 = ADD32(ctx->r2, -0X16E0);
    // 0x80067CB8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80067CBC: sw          $v0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r2;
    // 0x80067CC0: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x80067CC4: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80067CC8: lw          $t9, 0x34($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X34);
    // 0x80067CCC: lbu         $t8, 0x2B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2B);
    // 0x80067CD0: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80067CD4: sb          $t8, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r24;
    // 0x80067CD8: lw          $t1, 0x34($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X34);
    // 0x80067CDC: lbu         $t0, 0x2F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2F);
    // 0x80067CE0: nop

    // 0x80067CE4: sb          $t0, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r8;
    // 0x80067CE8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80067CEC: lbu         $t2, 0x10($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X10);
    // 0x80067CF0: nop

    // 0x80067CF4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80067CF8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80067CFC: lw          $t4, 0xC50($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XC50);
    // 0x80067D00: nop

    // 0x80067D04: lw          $t9, 0x44($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X44);
    // 0x80067D08: nop

    // 0x80067D0C: jalr        $t9
    // 0x80067D10: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80067D10: nop

    after_3:
    // 0x80067D14: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80067D18: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80067D1C: nop

    // 0x80067D20: sw          $t5, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r13;
L_80067D24:
    // 0x80067D24: jal         0x8006889C
    // 0x80067D28: nop

    func_8006889C(rdram, ctx);
        goto after_4;
    // 0x80067D28: nop

    after_4:
    // 0x80067D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80067D30:
    // 0x80067D30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80067D34: jr          $ra
    // 0x80067D38: nop

    return;
    // 0x80067D38: nop

;}
RECOMP_FUNC void func_80067D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067D40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067D44: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x80067D48: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x80067D4C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80067D50: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x80067D54: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80067D58: sb          $a1, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r5;
    // 0x80067D5C: lbu         $t9, 0x10($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X10);
    // 0x80067D60: nop

    // 0x80067D64: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80067D68: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80067D6C: lw          $t1, 0xC50($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XC50);
    // 0x80067D70: nop

    // 0x80067D74: lw          $t9, 0x48($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X48);
    // 0x80067D78: nop

    // 0x80067D7C: jalr        $t9
    // 0x80067D80: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80067D80: nop

    after_0:
    // 0x80067D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067D8C: jr          $ra
    // 0x80067D90: nop

    return;
    // 0x80067D90: nop

;}
RECOMP_FUNC void func_80067D94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067D98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067DA0: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x80067DA4: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80067DA8: jal         0x800680DC
    // 0x80067DAC: addiu       $a3, $a3, 0x7D3C
    ctx->r7 = ADD32(ctx->r7, 0X7D3C);
    func_800680DC(rdram, ctx);
        goto after_0;
    // 0x80067DAC: addiu       $a3, $a3, 0x7D3C
    ctx->r7 = ADD32(ctx->r7, 0X7D3C);
    after_0:
    // 0x80067DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067DB8: jr          $ra
    // 0x80067DBC: nop

    return;
    // 0x80067DBC: nop

;}
RECOMP_FUNC void func_80067DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067DC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067DC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067DCC: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80067DD0: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80067DD4: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80067DD8: jal         0x800680DC
    // 0x80067DDC: addiu       $a3, $a3, 0x7644
    ctx->r7 = ADD32(ctx->r7, 0X7644);
    func_800680DC(rdram, ctx);
        goto after_0;
    // 0x80067DDC: addiu       $a3, $a3, 0x7644
    ctx->r7 = ADD32(ctx->r7, 0X7644);
    after_0:
    // 0x80067DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067DE8: jr          $ra
    // 0x80067DEC: nop

    return;
    // 0x80067DEC: nop

;}
RECOMP_FUNC void func_80067DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067DF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067DF8: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x80067DFC: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80067E00: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80067E04: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x80067E08: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80067E0C: sb          $a1, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r5;
    // 0x80067E10: lbu         $t9, 0x10($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X10);
    // 0x80067E14: nop

    // 0x80067E18: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80067E1C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80067E20: lw          $t1, 0xC50($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XC50);
    // 0x80067E24: nop

    // 0x80067E28: lw          $t9, 0x28($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X28);
    // 0x80067E2C: nop

    // 0x80067E30: jalr        $t9
    // 0x80067E34: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80067E34: nop

    after_0:
    // 0x80067E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067E3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067E40: jr          $ra
    // 0x80067E44: nop

    return;
    // 0x80067E44: nop

;}
RECOMP_FUNC void func_80067E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067E48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067E4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067E50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067E54: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x80067E58: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80067E5C: jal         0x800680DC
    // 0x80067E60: addiu       $a3, $a3, 0x7DF0
    ctx->r7 = ADD32(ctx->r7, 0X7DF0);
    func_800680DC(rdram, ctx);
        goto after_0;
    // 0x80067E60: addiu       $a3, $a3, 0x7DF0
    ctx->r7 = ADD32(ctx->r7, 0X7DF0);
    after_0:
    // 0x80067E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067E68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067E6C: jr          $ra
    // 0x80067E70: nop

    return;
    // 0x80067E70: nop

;}
RECOMP_FUNC void func_80067E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067E74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067E7C: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x80067E80: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x80067E84: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80067E88: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x80067E8C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80067E90: sb          $a1, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r5;
    // 0x80067E94: lbu         $t9, 0x10($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X10);
    // 0x80067E98: nop

    // 0x80067E9C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80067EA0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80067EA4: lw          $t1, 0xC50($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XC50);
    // 0x80067EA8: nop

    // 0x80067EAC: lw          $t9, 0x2C($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X2C);
    // 0x80067EB0: nop

    // 0x80067EB4: jalr        $t9
    // 0x80067EB8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80067EB8: nop

    after_0:
    // 0x80067EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067EC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067EC4: jr          $ra
    // 0x80067EC8: nop

    return;
    // 0x80067EC8: nop

;}
RECOMP_FUNC void func_80067ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067ECC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067ED0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067ED8: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x80067EDC: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80067EE0: jal         0x800680DC
    // 0x80067EE4: addiu       $a3, $a3, 0x7E74
    ctx->r7 = ADD32(ctx->r7, 0X7E74);
    func_800680DC(rdram, ctx);
        goto after_0;
    // 0x80067EE4: addiu       $a3, $a3, 0x7E74
    ctx->r7 = ADD32(ctx->r7, 0X7E74);
    after_0:
    // 0x80067EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067EEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067EF0: jr          $ra
    // 0x80067EF4: nop

    return;
    // 0x80067EF4: nop

;}
RECOMP_FUNC void func_80067EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067EF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067EFC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067F04: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x80067F08: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80067F0C: jal         0x800680DC
    // 0x80067F10: addiu       $a3, $a3, 0x76A8
    ctx->r7 = ADD32(ctx->r7, 0X76A8);
    func_800680DC(rdram, ctx);
        goto after_0;
    // 0x80067F10: addiu       $a3, $a3, 0x76A8
    ctx->r7 = ADD32(ctx->r7, 0X76A8);
    after_0:
    // 0x80067F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067F18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067F1C: jr          $ra
    // 0x80067F20: nop

    return;
    // 0x80067F20: nop

;}
RECOMP_FUNC void func_80067F24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067F28: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067F30: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x80067F34: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80067F38: jal         0x800680DC
    // 0x80067F3C: addiu       $a3, $a3, 0x7700
    ctx->r7 = ADD32(ctx->r7, 0X7700);
    func_800680DC(rdram, ctx);
        goto after_0;
    // 0x80067F3C: addiu       $a3, $a3, 0x7700
    ctx->r7 = ADD32(ctx->r7, 0X7700);
    after_0:
    // 0x80067F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067F48: jr          $ra
    // 0x80067F4C: nop

    return;
    // 0x80067F4C: nop

;}
RECOMP_FUNC void func_80067F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067F54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067F58: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x80067F5C: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x80067F60: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80067F64: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x80067F68: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80067F6C: sb          $a1, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r5;
    // 0x80067F70: lbu         $t9, 0x10($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X10);
    // 0x80067F74: nop

    // 0x80067F78: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80067F7C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80067F80: lw          $t1, 0xC50($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XC50);
    // 0x80067F84: nop

    // 0x80067F88: lw          $t9, 0x38($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X38);
    // 0x80067F8C: nop

    // 0x80067F90: jalr        $t9
    // 0x80067F94: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80067F94: nop

    after_0:
    // 0x80067F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067F9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067FA0: jr          $ra
    // 0x80067FA4: nop

    return;
    // 0x80067FA4: nop

;}
RECOMP_FUNC void func_80067FA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067FA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067FAC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067FB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067FB4: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x80067FB8: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80067FBC: jal         0x800680DC
    // 0x80067FC0: addiu       $a3, $a3, 0x7F50
    ctx->r7 = ADD32(ctx->r7, 0X7F50);
    func_800680DC(rdram, ctx);
        goto after_0;
    // 0x80067FC0: addiu       $a3, $a3, 0x7F50
    ctx->r7 = ADD32(ctx->r7, 0X7F50);
    after_0:
    // 0x80067FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067FCC: jr          $ra
    // 0x80067FD0: nop

    return;
    // 0x80067FD0: nop

;}
RECOMP_FUNC void func_80067FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067FD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067FD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067FDC: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x80067FE0: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80067FE4: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80067FE8: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x80067FEC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80067FF0: sb          $a1, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r5;
    // 0x80067FF4: lbu         $t9, 0x10($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X10);
    // 0x80067FF8: nop

    // 0x80067FFC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80068000: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80068004: lw          $t1, 0xC50($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XC50);
    // 0x80068008: nop

    // 0x8006800C: lw          $t9, 0x3C($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X3C);
    // 0x80068010: nop

    // 0x80068014: jalr        $t9
    // 0x80068018: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80068018: nop

    after_0:
    // 0x8006801C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068024: jr          $ra
    // 0x80068028: nop

    return;
    // 0x80068028: nop

;}
RECOMP_FUNC void func_8006802C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006802C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068030: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80068034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068038: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x8006803C: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80068040: jal         0x800680DC
    // 0x80068044: addiu       $a3, $a3, 0x7FD4
    ctx->r7 = ADD32(ctx->r7, 0X7FD4);
    func_800680DC(rdram, ctx);
        goto after_0;
    // 0x80068044: addiu       $a3, $a3, 0x7FD4
    ctx->r7 = ADD32(ctx->r7, 0X7FD4);
    after_0:
    // 0x80068048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006804C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068050: jr          $ra
    // 0x80068054: nop

    return;
    // 0x80068054: nop

;}
RECOMP_FUNC void func_80068058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006805C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068060: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x80068064: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80068068: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8006806C: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x80068070: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80068074: sb          $a1, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r5;
    // 0x80068078: lbu         $t9, 0x10($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X10);
    // 0x8006807C: nop

    // 0x80068080: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80068084: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80068088: lw          $t1, 0xC50($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XC50);
    // 0x8006808C: nop

    // 0x80068090: lw          $t9, 0x40($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X40);
    // 0x80068094: nop

    // 0x80068098: jalr        $t9
    // 0x8006809C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8006809C: nop

    after_0:
    // 0x800680A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800680A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800680A8: jr          $ra
    // 0x800680AC: nop

    return;
    // 0x800680AC: nop

;}
RECOMP_FUNC void func_800680B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800680B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800680B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800680B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800680BC: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x800680C0: lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // 0x800680C4: jal         0x800680DC
    // 0x800680C8: addiu       $a3, $a3, -0x7FA8
    ctx->r7 = ADD32(ctx->r7, -0X7FA8);
    func_800680DC(rdram, ctx);
        goto after_0;
    // 0x800680C8: addiu       $a3, $a3, -0x7FA8
    ctx->r7 = ADD32(ctx->r7, -0X7FA8);
    after_0:
    // 0x800680CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800680D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800680D4: jr          $ra
    // 0x800680D8: nop

    return;
    // 0x800680D8: nop

;}
RECOMP_FUNC void func_800680DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800680DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800680E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800680E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800680E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800680EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800680F0: jal         0x8006885C
    // 0x800680F4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_8006885C(rdram, ctx);
        goto after_0;
    // 0x800680F4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x800680F8: jal         0x800691F0
    // 0x800680FC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800691F0(rdram, ctx);
        goto after_1;
    // 0x800680FC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x80068100: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80068104: jal         0x80069248
    // 0x80068108: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80069248(rdram, ctx);
        goto after_2;
    // 0x80068108: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x8006810C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80068110: jal         0x80069248
    // 0x80068114: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80069248(rdram, ctx);
        goto after_3;
    // 0x80068114: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80068118: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8006811C: jal         0x80069248
    // 0x80068120: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80069248(rdram, ctx);
        goto after_4;
    // 0x80068120: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80068124: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80068128: jal         0x80069248
    // 0x8006812C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80069248(rdram, ctx);
        goto after_5;
    // 0x8006812C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80068130: jal         0x8006889C
    // 0x80068134: nop

    func_8006889C(rdram, ctx);
        goto after_6;
    // 0x80068134: nop

    after_6:
    // 0x80068138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006813C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068140: jr          $ra
    // 0x80068144: nop

    return;
    // 0x80068144: nop

;}
RECOMP_FUNC void func_80068148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068148: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006814C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068150: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80068154: jal         0x800692F4
    // 0x80068158: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800692F4(rdram, ctx);
        goto after_0;
    // 0x80068158: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8006815C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80068160: jal         0x800692F4
    // 0x80068164: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800692F4(rdram, ctx);
        goto after_1;
    // 0x80068164: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80068168: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8006816C: jal         0x800692F4
    // 0x80068170: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800692F4(rdram, ctx);
        goto after_2;
    // 0x80068170: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80068174: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80068178: jal         0x800692F4
    // 0x8006817C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800692F4(rdram, ctx);
        goto after_3;
    // 0x8006817C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80068180: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80068184: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80068188: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8006818C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80068190: jal         0x800681A8
    // 0x80068194: nop

    func_800681A8(rdram, ctx);
        goto after_4;
    // 0x80068194: nop

    after_4:
    // 0x80068198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006819C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800681A0: jr          $ra
    // 0x800681A4: nop

    return;
    // 0x800681A4: nop

;}
RECOMP_FUNC void func_800681A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800681A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800681AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800681B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800681B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800681B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800681BC: jal         0x800629A8
    // 0x800681C0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800629A8(rdram, ctx);
        goto after_0;
    // 0x800681C0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x800681C4: beq         $v0, $zero, L_80068208
    if (ctx->r2 == 0) {
        // 0x800681C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80068208;
    }
    // 0x800681C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800681CC: jal         0x8006885C
    // 0x800681D0: nop

    func_8006885C(rdram, ctx);
        goto after_1;
    // 0x800681D0: nop

    after_1:
    // 0x800681D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800681D8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800681DC: jal         0x800663E0
    // 0x800681E0: nop

    func_800663E0(rdram, ctx);
        goto after_2;
    // 0x800681E0: nop

    after_2:
    // 0x800681E4: beq         $v0, $zero, L_800681FC
    if (ctx->r2 == 0) {
        // 0x800681E8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800681FC;
    }
    // 0x800681E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800681EC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800681F0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800681F4: jal         0x80067758
    // 0x800681F8: nop

    func_80067758(rdram, ctx);
        goto after_3;
    // 0x800681F8: nop

    after_3:
L_800681FC:
    // 0x800681FC: jal         0x8006889C
    // 0x80068200: nop

    func_8006889C(rdram, ctx);
        goto after_4;
    // 0x80068200: nop

    after_4:
    // 0x80068204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80068208:
    // 0x80068208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006820C: jr          $ra
    // 0x80068210: nop

    return;
    // 0x80068210: nop

    // 0x80068214: nop

    // 0x80068218: nop

    // 0x8006821C: nop

;}
RECOMP_FUNC void func_80068220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068220: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80068224: lw          $t6, 0xC40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XC40);
    // FALLTHROUGH: func_80068220 falls into func_80068228
    func_80068228(rdram, ctx);
;}
RECOMP_FUNC void func_80068228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006822C: beq         $t6, $zero, L_80068260
    if (ctx->r14 == 0) {
        // 0x80068230: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80068260;
    }
    // 0x80068230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068234: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80068238: lw          $a0, 0xC44($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC44);
    // 0x8006823C: nop

    // 0x80068240: beq         $a0, $zero, L_80068258
    if (ctx->r4 == 0) {
        // 0x80068244: nop
    
            goto L_80068258;
    }
    // 0x80068244: nop

    // 0x80068248: jal         0x80068838
    // 0x8006824C: nop

    func_80068838(rdram, ctx);
        goto after_0;
    // 0x8006824C: nop

    after_0:
    // 0x80068250: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80068254: sw          $zero, 0xC44($at)
    MEM_W(0XC44, ctx->r1) = 0;
L_80068258:
    // 0x80068258: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8006825C: sw          $zero, 0xC40($at)
    MEM_W(0XC40, ctx->r1) = 0;
L_80068260:
    // 0x80068260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068268: jr          $ra
    // 0x8006826C: nop

    return;
    // 0x8006826C: nop

;}
RECOMP_FUNC void func_80068270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068270: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80068274: lw          $v0, 0xC44($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC44);
    // 0x80068278: jr          $ra
    // 0x8006827C: nop

    return;
    // 0x8006827C: nop

;}
RECOMP_FUNC void func_80068280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068280: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80068284: lw          $v0, 0xC48($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC48);
    // 0x80068288: jr          $ra
    // 0x8006828C: nop

    return;
    // 0x8006828C: nop

;}
RECOMP_FUNC void func_80068290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068290: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80068294: sw          $a0, 0xC30($at)
    MEM_W(0XC30, ctx->r1) = ctx->r4;
    // 0x80068298: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8006829C: sw          $a1, 0xC34($at)
    MEM_W(0XC34, ctx->r1) = ctx->r5;
    // 0x800682A0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800682A4: sw          $a2, 0xC38($at)
    MEM_W(0XC38, ctx->r1) = ctx->r6;
    // 0x800682A8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800682AC: jr          $ra
    // 0x800682B0: sw          $a3, 0xC3C($at)
    MEM_W(0XC3C, ctx->r1) = ctx->r7;
    return;
    // 0x800682B0: sw          $a3, 0xC3C($at)
    MEM_W(0XC3C, ctx->r1) = ctx->r7;
;}
RECOMP_FUNC void func_800682B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800682B4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800682B8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800682BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800682C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800682C4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800682C8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800682CC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800682D0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800682D4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800682D8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800682DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800682E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800682E4: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800682E8: jal         0x800629A8
    // 0x800682EC: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    func_800629A8(rdram, ctx);
        goto after_0;
    // 0x800682EC: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    after_0:
    // 0x800682F0: bne         $v0, $zero, L_80068300
    if (ctx->r2 != 0) {
        // 0x800682F4: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_80068300;
    }
    // 0x800682F4: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800682F8: b           L_8006875C
    // 0x800682FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006875C;
    // 0x800682FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80068300:
    // 0x80068300: sb          $zero, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = 0;
    // 0x80068304: sb          $zero, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = 0;
    // 0x80068308: bne         $s0, $zero, L_80068348
    if (ctx->r16 != 0) {
        // 0x8006830C: sw          $zero, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = 0;
            goto L_80068348;
    }
    // 0x8006830C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80068310: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80068314: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80068318: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8006831C: jal         0x8006882C
    // 0x80068320: sw          $t6, 0xC40($at)
    MEM_W(0XC40, ctx->r1) = ctx->r14;
    func_8006882C(rdram, ctx);
        goto after_1;
    // 0x80068320: sw          $t6, 0xC40($at)
    MEM_W(0XC40, ctx->r1) = ctx->r14;
    after_1:
    // 0x80068324: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80068328: sw          $v0, 0xC44($at)
    MEM_W(0XC44, ctx->r1) = ctx->r2;
    // 0x8006832C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80068330: lw          $t7, 0xC44($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XC44);
    // 0x80068334: nop

    // 0x80068338: bne         $t7, $zero, L_8006835C
    if (ctx->r15 != 0) {
        // 0x8006833C: lw          $t8, 0x78($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X78);
            goto L_8006835C;
    }
    // 0x8006833C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80068340: b           L_8006875C
    // 0x80068344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006875C;
    // 0x80068344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80068348:
    // 0x80068348: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8006834C: sw          $zero, 0xC40($at)
    MEM_W(0XC40, ctx->r1) = 0;
    // 0x80068350: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80068354: sw          $s0, 0xC44($at)
    MEM_W(0XC44, ctx->r1) = ctx->r16;
    // 0x80068358: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
L_8006835C:
    // 0x8006835C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80068360: jal         0x8006885C
    // 0x80068364: sw          $t8, 0xC48($at)
    MEM_W(0XC48, ctx->r1) = ctx->r24;
    func_8006885C(rdram, ctx);
        goto after_2;
    // 0x80068364: sw          $t8, 0xC48($at)
    MEM_W(0XC48, ctx->r1) = ctx->r24;
    after_2:
    // 0x80068368: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8006836C: lbu         $v0, 0xC9B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XC9B);
    // 0x80068370: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80068374: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80068378: blez        $v0, L_800683CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006837C: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_800683CC;
    }
    // 0x8006837C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80068380: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80068384: lw          $t1, -0x16F4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X16F4);
    // 0x80068388: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x8006838C: lw          $v0, 0x18($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X18);
    // 0x80068390: nop

L_80068394:
    // 0x80068394: multu       $s6, $v1
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068398: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8006839C: mflo        $t2
    ctx->r10 = lo;
    // 0x800683A0: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x800683A4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800683A8: nop

    // 0x800683AC: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x800683B0: beq         $t5, $zero, L_800683D0
    if (ctx->r13 == 0) {
        // 0x800683B4: lw          $t8, 0x44($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X44);
            goto L_800683D0;
    }
    // 0x800683B4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800683B8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800683BC: andi        $t6, $s6, 0xFF
    ctx->r14 = ctx->r22 & 0XFF;
    // 0x800683C0: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800683C4: bne         $at, $zero, L_80068394
    if (ctx->r1 != 0) {
        // 0x800683C8: or          $s6, $t6, $zero
        ctx->r22 = ctx->r14 | 0;
            goto L_80068394;
    }
    // 0x800683C8: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
L_800683CC:
    // 0x800683CC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
L_800683D0:
    // 0x800683D0: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x800683D4: bne         $t8, $s6, L_800683EC
    if (ctx->r24 != ctx->r22) {
        // 0x800683D8: sw          $s6, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r22;
            goto L_800683EC;
    }
    // 0x800683D8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800683DC: jal         0x8006889C
    // 0x800683E0: nop

    func_8006889C(rdram, ctx);
        goto after_3;
    // 0x800683E0: nop

    after_3:
    // 0x800683E4: b           L_8006875C
    // 0x800683E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006875C;
    // 0x800683E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800683EC:
    // 0x800683EC: multu       $s6, $v1
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800683F0: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800683F4: lw          $t1, -0x16F4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X16F4);
    // 0x800683F8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800683FC: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x80068400: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80068404: addiu       $s3, $s3, 0xC30
    ctx->r19 = ADD32(ctx->r19, 0XC30);
    // 0x80068408: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8006840C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80068410: mflo        $t3
    ctx->r11 = lo;
    // 0x80068414: addu        $fp, $t2, $t3
    ctx->r30 = ADD32(ctx->r10, ctx->r11);
    // 0x80068418: lw          $t4, 0xC($fp)
    ctx->r12 = MEM_W(ctx->r30, 0XC);
    // 0x8006841C: blez        $t5, L_800686E0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80068420: sw          $t4, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r12;
            goto L_800686E0;
    }
    // 0x80068420: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
L_80068424:
    // 0x80068424: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80068428: lw          $t6, -0x16F4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X16F4);
    // 0x8006842C: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x80068430: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x80068434: addu        $t8, $t8, $s4
    ctx->r24 = ADD32(ctx->r24, ctx->r20);
    // 0x80068438: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8006843C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80068440: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80068444: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80068448: srl         $t1, $t9, 31
    ctx->r9 = S32(U32(ctx->r25) >> 31);
    // 0x8006844C: bne         $t1, $zero, L_800686CC
    if (ctx->r9 != 0) {
        // 0x80068450: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_800686CC;
    }
    // 0x80068450: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80068454: lw          $v0, 0xC34($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC34);
    // 0x80068458: lbu         $t7, 0x6B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X6B);
    // 0x8006845C: slt         $at, $s7, $v0
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80068460: beq         $at, $zero, L_800684A0
    if (ctx->r1 == 0) {
        // 0x80068464: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_800684A0;
    }
    // 0x80068464: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x80068468: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x8006846C: sb          $s5, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r21;
    // 0x80068470: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80068474: andi        $s2, $s7, 0xFF
    ctx->r18 = ctx->r23 & 0XFF;
    // 0x80068478: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8006847C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80068480: subu        $t5, $t0, $t4
    ctx->r13 = SUB32(ctx->r8, ctx->r12);
    // 0x80068484: andi        $t2, $s7, 0xFF
    ctx->r10 = ctx->r23 & 0XFF;
    // 0x80068488: sw          $t5, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r13;
    // 0x8006848C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80068490: or          $s7, $t2, $zero
    ctx->r23 = ctx->r10 | 0;
    // 0x80068494: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x80068498: b           L_80068564
    // 0x8006849C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80068564;
    // 0x8006849C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800684A0:
    // 0x800684A0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800684A4: lw          $a0, 0xC38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC38);
    // 0x800684A8: lbu         $t5, 0x6A($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X6A);
    // 0x800684AC: slt         $at, $t7, $a0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800684B0: beq         $at, $zero, L_800684F4
    if (ctx->r1 == 0) {
        // 0x800684B4: lui         $t6, 0x8009
        ctx->r14 = S32(0X8009 << 16);
            goto L_800684F4;
    }
    // 0x800684B4: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800684B8: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800684BC: sb          $t9, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r25;
    // 0x800684C0: sb          $s5, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r21;
    // 0x800684C4: sb          $s5, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r21;
    // 0x800684C8: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800684CC: addu        $s2, $t7, $v0
    ctx->r18 = ADD32(ctx->r15, ctx->r2);
    // 0x800684D0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800684D4: subu        $t3, $t0, $t2
    ctx->r11 = SUB32(ctx->r8, ctx->r10);
    // 0x800684D8: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x800684DC: sw          $t3, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r11;
    // 0x800684E0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800684E4: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800684E8: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800684EC: b           L_80068564
    // 0x800684F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80068564;
    // 0x800684F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800684F4:
    // 0x800684F4: lw          $t6, 0xC3C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XC3C);
    // 0x800684F8: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x800684FC: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80068500: beq         $at, $zero, L_800686E0
    if (ctx->r1 == 0) {
        // 0x80068504: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_800686E0;
    }
    // 0x80068504: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80068508: sb          $t9, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = ctx->r25;
    // 0x8006850C: sb          $t1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r9;
    // 0x80068510: sb          $s5, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r21;
    // 0x80068514: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80068518: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8006851C: lw          $t3, 0xC38($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XC38);
    // 0x80068520: lw          $t2, 0xC34($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XC34);
    // 0x80068524: addu        $t8, $t5, $v0
    ctx->r24 = ADD32(ctx->r13, ctx->r2);
    // 0x80068528: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8006852C: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068530: addu        $s2, $t8, $a0
    ctx->r18 = ADD32(ctx->r24, ctx->r4);
    // 0x80068534: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80068538: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8006853C: andi        $t7, $s2, 0xFF
    ctx->r15 = ctx->r18 & 0XFF;
    // 0x80068540: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x80068544: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x80068548: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8006854C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80068550: mflo        $t6
    ctx->r14 = lo;
    // 0x80068554: subu        $t7, $t8, $t6
    ctx->r15 = SUB32(ctx->r24, ctx->r14);
    // 0x80068558: subu        $t1, $t7, $t9
    ctx->r9 = SUB32(ctx->r15, ctx->r25);
    // 0x8006855C: sw          $t1, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r9;
    // 0x80068560: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
L_80068564:
    // 0x80068564: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80068568: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8006856C: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80068570: sb          $s4, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r20;
    // 0x80068574: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x80068578: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x8006857C: sb          $s6, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r22;
    // 0x80068580: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80068584: sb          $t8, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r24;
    // 0x80068588: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x8006858C: sb          $t6, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r14;
    // 0x80068590: sb          $zero, 0x11($s0)
    MEM_B(0X11, ctx->r16) = 0;
    // 0x80068594: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    // 0x80068598: jal         0x800688DC
    // 0x8006859C: sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    func_800688DC(rdram, ctx);
        goto after_4;
    // 0x8006859C: sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    after_4:
    // 0x800685A0: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x800685A4: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800685A8: lh          $a1, 0x14($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X14);
    // 0x800685AC: lh          $a2, 0x16($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X16);
    // 0x800685B0: jal         0x800688E4
    // 0x800685B4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_800688E4(rdram, ctx);
        goto after_5;
    // 0x800685B4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_5:
    // 0x800685B8: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x800685BC: lw          $t7, 0x3C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X3C);
    // 0x800685C0: multu       $s2, $t0
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800685C4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800685C8: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x800685CC: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800685D0: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x800685D4: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x800685D8: sw          $t9, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r25;
    // 0x800685DC: sw          $t7, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r15;
    // 0x800685E0: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800685E4: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x800685E8: lw          $t1, 0xC44($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XC44);
    // 0x800685EC: sh          $t2, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r10;
    // 0x800685F0: lh          $t3, 0x1A($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X1A);
    // 0x800685F4: mflo        $a3
    ctx->r7 = lo;
    // 0x800685F8: addu        $v1, $a3, $t1
    ctx->r3 = ADD32(ctx->r7, ctx->r9);
    // 0x800685FC: blez        $t3, L_8006861C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80068600: sw          $v1, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->r3;
            goto L_8006861C;
    }
    // 0x80068600: sw          $v1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r3;
L_80068604:
    // 0x80068604: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80068608: lh          $t4, 0x1A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A);
    // 0x8006860C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80068610: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80068614: bne         $at, $zero, L_80068604
    if (ctx->r1 != 0) {
        // 0x80068618: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80068604;
    }
    // 0x80068618: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8006861C:
    // 0x8006861C: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80068620: lw          $t8, 0xC44($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XC44);
    // 0x80068624: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80068628: addu        $t6, $a3, $t8
    ctx->r14 = ADD32(ctx->r7, ctx->r24);
    // 0x8006862C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80068630: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x80068634: sw          $a2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r6;
    // 0x80068638: addiu       $t9, $zero, 0x22
    ctx->r25 = ADD32(0, 0X22);
    // 0x8006863C: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x80068640: sb          $t9, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r25;
    // 0x80068644: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80068648: jal         0x80069480
    // 0x8006864C: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    func_80069480(rdram, ctx);
        goto after_6;
    // 0x8006864C: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    after_6:
    // 0x80068650: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x80068654: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80068658: andi        $t4, $t1, 0xFFBF
    ctx->r12 = ctx->r9 & 0XFFBF;
    // 0x8006865C: ori         $t6, $t4, 0x20
    ctx->r14 = ctx->r12 | 0X20;
    // 0x80068660: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x80068664: ori         $t1, $t6, 0x10
    ctx->r9 = ctx->r14 | 0X10;
    // 0x80068668: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8006866C: ori         $t3, $t1, 0x80
    ctx->r11 = ctx->r9 | 0X80;
    // 0x80068670: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
    // 0x80068674: andi        $t8, $t3, 0xF7
    ctx->r24 = ctx->r11 & 0XF7;
    // 0x80068678: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x8006867C: andi        $t6, $t8, 0xFB
    ctx->r14 = ctx->r24 & 0XFB;
    // 0x80068680: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x80068684: andi        $t1, $t6, 0xFD
    ctx->r9 = ctx->r14 & 0XFD;
    // 0x80068688: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8006868C: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
    // 0x80068690: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80068694: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80068698: sb          $zero, 0xF($s0)
    MEM_B(0XF, ctx->r16) = 0;
    // 0x8006869C: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
    // 0x800686A0: lbu         $t3, 0x4($fp)
    ctx->r11 = MEM_BU(ctx->r30, 0X4);
    // 0x800686A4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800686A8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800686AC: sb          $t4, 0x4($fp)
    MEM_B(0X4, ctx->r30) = ctx->r12;
    // 0x800686B0: lw          $v0, -0x16F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X16F4);
    // 0x800686B4: nop

    // 0x800686B8: lbu         $t8, 0x5($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5);
    // 0x800686BC: nop

    // 0x800686C0: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x800686C4: sb          $t5, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r13;
    // 0x800686C8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_800686CC:
    // 0x800686CC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800686D0: andi        $t6, $s4, 0xFF
    ctx->r14 = ctx->r20 & 0XFF;
    // 0x800686D4: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800686D8: bne         $at, $zero, L_80068424
    if (ctx->r1 != 0) {
        // 0x800686DC: or          $s4, $t6, $zero
        ctx->r20 = ctx->r14 | 0;
            goto L_80068424;
    }
    // 0x800686DC: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
L_800686E0:
    // 0x800686E0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800686E4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800686E8: beq         $t9, $zero, L_80068738
    if (ctx->r25 == 0) {
        // 0x800686EC: addiu       $t8, $zero, 0x80
        ctx->r24 = ADD32(0, 0X80);
            goto L_80068738;
    }
    // 0x800686EC: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800686F0: lbu         $t3, 0x0($fp)
    ctx->r11 = MEM_BU(ctx->r30, 0X0);
    // 0x800686F4: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x800686F8: ori         $t7, $t3, 0x40
    ctx->r15 = ctx->r11 | 0X40;
    // 0x800686FC: sb          $t7, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r15;
    // 0x80068700: ori         $t9, $t7, 0x80
    ctx->r25 = ctx->r15 | 0X80;
    // 0x80068704: sh          $t1, 0x2($fp)
    MEM_H(0X2, ctx->r30) = ctx->r9;
    // 0x80068708: sw          $zero, 0x8($fp)
    MEM_W(0X8, ctx->r30) = 0;
    // 0x8006870C: sb          $zero, 0x1($fp)
    MEM_B(0X1, ctx->r30) = 0;
    // 0x80068710: sb          $t8, 0x6($fp)
    MEM_B(0X6, ctx->r30) = ctx->r24;
    // 0x80068714: sb          $t5, 0x7($fp)
    MEM_B(0X7, ctx->r30) = ctx->r13;
    // 0x80068718: sb          $t9, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r25;
    // 0x8006871C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80068720: lw          $v0, -0x16F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X16F4);
    // 0x80068724: nop

    // 0x80068728: lbu         $t1, 0x4($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X4);
    // 0x8006872C: nop

    // 0x80068730: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80068734: sb          $t2, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r10;
L_80068738:
    // 0x80068738: jal         0x8006889C
    // 0x8006873C: nop

    func_8006889C(rdram, ctx);
        goto after_7;
    // 0x8006873C: nop

    after_7:
    // 0x80068740: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80068744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80068748: beq         $t3, $zero, L_8006875C
    if (ctx->r11 == 0) {
        // 0x8006874C: nop
    
            goto L_8006875C;
    }
    // 0x8006874C: nop

    // 0x80068750: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80068754: b           L_8006875C
    // 0x80068758: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8006875C;
    // 0x80068758: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006875C:
    // 0x8006875C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80068760: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068764: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80068768: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006876C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80068770: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80068774: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80068778: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8006877C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80068780: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80068784: jr          $ra
    // 0x80068788: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80068788: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8006878C: nop

;}
RECOMP_FUNC void func_80068790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068790: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80068794: jr          $ra
    // 0x80068798: sw          $a0, -0x16B0($at)
    MEM_W(-0X16B0, ctx->r1) = ctx->r4;
    return;
    // 0x80068798: sw          $a0, -0x16B0($at)
    MEM_W(-0X16B0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_8006879C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006879C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800687A0: lw          $v0, -0x16B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X16B0);
    // FALLTHROUGH: func_8006879C falls into func_800687A4
    func_800687A4(rdram, ctx);
;}
RECOMP_FUNC void func_800687A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800687A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800687A8: beq         $v0, $zero, L_800687B8
    if (ctx->r2 == 0) {
        // 0x800687AC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800687B8;
    }
    // 0x800687AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800687B0: jalr        $v0
    // 0x800687B4: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800687B4: nop

    after_0:
L_800687B8:
    // 0x800687B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800687BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800687C0: jr          $ra
    // 0x800687C4: nop

    return;
    // 0x800687C4: nop

;}
RECOMP_FUNC void func_800687C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800687C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800687CC: jr          $ra
    // 0x800687D0: sw          $a0, -0x16AC($at)
    MEM_W(-0X16AC, ctx->r1) = ctx->r4;
    return;
    // 0x800687D0: sw          $a0, -0x16AC($at)
    MEM_W(-0X16AC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800687D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800687D4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800687D8: lw          $v0, -0x16AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X16AC);

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_800687DC
    func_800687DC(rdram, ctx);
}
