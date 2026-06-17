#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_80041DB4(uint8_t* rdram, recomp_context* ctx);
void func_80042B08(uint8_t* rdram, recomp_context* ctx);
void func_80042B30(uint8_t* rdram, recomp_context* ctx);
void func_8004314C(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80041A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041A50: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80041A54: lh          $a3, 0x122($t3)
    ctx->r7 = MEM_H(ctx->r11, 0X122);
    // 0x80041A58: lh          $v0, 0x74($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X74);
    // 0x80041A5C: slt         $v0, $v0, $a3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80041A60: beq         $v0, $zero, L_80041B8C
    if (ctx->r2 == 0) {
        // 0x80041A64: addiu       $t1, $a1, 0x98
        ctx->r9 = ADD32(ctx->r5, 0X98);
            goto L_80041B8C;
    }
    // 0x80041A64: addiu       $t1, $a1, 0x98
    ctx->r9 = ADD32(ctx->r5, 0X98);
    // 0x80041A68: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x80041A6C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80041A70: lw          $t2, 0x98($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X98);
    // 0x80041A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80041A78: beq         $v1, $v0, L_80041AD4
    if (ctx->r3 == ctx->r2) {
        // 0x80041A7C: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80041AD4;
    }
    // 0x80041A7C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80041A80: lh          $v0, 0x18($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X18);
    // 0x80041A84: slt         $v0, $a3, $v0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80041A88: beq         $v0, $zero, L_80041AC4
    if (ctx->r2 == 0) {
        // 0x80041A8C: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80041AC4;
    }
    // 0x80041A8C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80041A90: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x80041A94: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80041A98:
    // 0x80041A98: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80041A9C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80041AA0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80041AA4: blez        $v0, L_80041AC0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80041AA8: addiu       $t1, $t1, 0x54
        ctx->r9 = ADD32(ctx->r9, 0X54);
            goto L_80041AC0;
    }
    // 0x80041AA8: addiu       $t1, $t1, 0x54
    ctx->r9 = ADD32(ctx->r9, 0X54);
    // 0x80041AAC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80041AB0: lh          $v0, 0x18($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X18);
    // 0x80041AB4: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80041AB8: bnel        $v0, $zero, L_80041A98
    if (ctx->r2 != 0) {
        // 0x80041ABC: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80041A98;
    }
    goto skip_0;
    // 0x80041ABC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
L_80041AC0:
    // 0x80041AC0: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80041AC4:
    // 0x80041AC4: bne         $v0, $zero, L_80041AD4
    if (ctx->r2 != 0) {
        // 0x80041AC8: nop
    
            goto L_80041AD4;
    }
    // 0x80041AC8: nop

    // 0x80041ACC: j           L_80041B90
    // 0x80041AD0: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
        goto L_80041B90;
    // 0x80041AD0: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
L_80041AD4:
    // 0x80041AD4: lhu         $v0, 0x58($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X58);
    // 0x80041AD8: bnel        $v0, $zero, L_80041B84
    if (ctx->r2 != 0) {
        // 0x80041ADC: sw          $t1, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r9;
            goto L_80041B84;
    }
    goto skip_1;
    // 0x80041ADC: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    skip_1:
    // 0x80041AE0: lhu         $v1, 0x6($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X6);
    // 0x80041AE4: beq         $v1, $zero, L_80041B08
    if (ctx->r3 == 0) {
        // 0x80041AE8: sltiu       $v1, $v1, 0x2
        ctx->r3 = ctx->r3 < 0X2 ? 1 : 0;
            goto L_80041B08;
    }
    // 0x80041AE8: sltiu       $v1, $v1, 0x2
    ctx->r3 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80041AEC: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x80041AF0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041AF4: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80041AF8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80041AFC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80041B00: beql        $v1, $zero, L_80041B90
    if (ctx->r3 == 0) {
        // 0x80041B04: sw          $t1, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r9;
            goto L_80041B90;
    }
    goto skip_2;
    // 0x80041B04: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    skip_2:
L_80041B08:
    // 0x80041B08: lhu         $t0, 0x4($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X4);
    // 0x80041B0C: lhu         $v0, 0x32($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X32);
    // 0x80041B10: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x80041B14: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80041B18: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x80041B1C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80041B20: slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80041B24: bne         $v1, $zero, L_80041B38
    if (ctx->r3 != 0) {
        // 0x80041B28: sra         $a3, $v0, 17
        ctx->r7 = S32(SIGNED(ctx->r2) >> 17);
            goto L_80041B38;
    }
    // 0x80041B28: sra         $a3, $v0, 17
    ctx->r7 = S32(SIGNED(ctx->r2) >> 17);
    // 0x80041B2C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041B30: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x80041B34: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
L_80041B38:
    // 0x80041B38: addu        $v0, $a3, $t0
    ctx->r2 = ADD32(ctx->r7, ctx->r8);
    // 0x80041B3C: lh          $v1, 0x120($t3)
    ctx->r3 = MEM_H(ctx->r11, 0X120);
    // 0x80041B40: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80041B44: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041B48: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80041B4C: bne         $v1, $zero, L_80041B70
    if (ctx->r3 != 0) {
        // 0x80041B50: sll         $v0, $t0, 16
        ctx->r2 = S32(ctx->r8 << 16);
            goto L_80041B70;
    }
    // 0x80041B50: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x80041B54: lhu         $v1, 0x28($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X28);
    // 0x80041B58: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041B5C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80041B60: beq         $v0, $zero, L_80041B84
    if (ctx->r2 == 0) {
        // 0x80041B64: sw          $t1, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r9;
            goto L_80041B84;
    }
    // 0x80041B64: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80041B68: j           L_80041B94
    // 0x80041B6C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80041B94;
    // 0x80041B6C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80041B70:
    // 0x80041B70: lhu         $v1, 0x24($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X24);
    // 0x80041B74: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041B78: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80041B7C: bne         $v0, $zero, L_80041B90
    if (ctx->r2 != 0) {
        // 0x80041B80: sw          $t1, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r9;
            goto L_80041B90;
    }
    // 0x80041B80: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
L_80041B84:
    // 0x80041B84: j           L_80041B94
    // 0x80041B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041B94;
    // 0x80041B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80041B8C:
    // 0x80041B8C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80041B90:
    // 0x80041B90: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80041B94:
    // 0x80041B94: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80041B98: jr          $ra
    // 0x80041B9C: nop

    return;
    // 0x80041B9C: nop

;}
RECOMP_FUNC void func_80041BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041BA0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041BA4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80041BA8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80041BAC: lh          $a0, 0x46A8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X46A8);
    // FALLTHROUGH: func_80041BA0 falls into func_80041BB0
    func_80041BB0(rdram, ctx);
;}
RECOMP_FUNC void func_80041BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041BB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80041BB4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80041BB8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80041BBC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80041BC0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80041BC4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80041BC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80041BCC: lh          $v1, 0x14($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X14);
    // 0x80041BD0: lhu         $a1, 0x14($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X14);
    // 0x80041BD4: lw          $s4, 0x90($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X90);
    // 0x80041BD8: slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80041BDC: beq         $v1, $zero, L_80041BF0
    if (ctx->r3 == 0) {
        // 0x80041BE0: nop
    
            goto L_80041BF0;
    }
    // 0x80041BE0: nop

    // 0x80041BE4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041BE8: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x80041BEC: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
L_80041BF0:
    // 0x80041BF0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80041BF4: lhu         $s2, 0x3E4($s2)
    ctx->r18 = MEM_HU(ctx->r18, 0X3E4);
    // 0x80041BF8: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x80041BFC: addiu       $s1, $s1, -0x6C70
    ctx->r17 = ADD32(ctx->r17, -0X6C70);
    // 0x80041C00: beq         $s2, $zero, L_80041D50
    if (ctx->r18 == 0) {
        // 0x80041C04: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_80041D50;
    }
    // 0x80041C04: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80041C08: sra         $s3, $v0, 16
    ctx->r19 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041C0C: addiu       $s0, $s1, 0x10
    ctx->r16 = ADD32(ctx->r17, 0X10);
L_80041C10:
    // 0x80041C10: jal         0x80041DB4
    // 0x80041C14: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80041DB4(rdram, ctx);
        goto after_0;
    // 0x80041C14: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x80041C18: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80041C1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80041C20: bnel        $v0, $v1, L_80041D24
    if (ctx->r2 != ctx->r3) {
        // 0x80041C24: addiu       $s0, $s0, 0x584
        ctx->r16 = ADD32(ctx->r16, 0X584);
            goto L_80041D24;
    }
    goto skip_0;
    // 0x80041C24: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
    skip_0:
    // 0x80041C28: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041C2C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80041C30: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80041C34: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80041C38: beq         $v0, $zero, L_80041C4C
    if (ctx->r2 == 0) {
        // 0x80041C3C: nop
    
            goto L_80041C4C;
    }
    // 0x80041C3C: nop

    // 0x80041C40: lhu         $a1, -0xC($s0)
    ctx->r5 = MEM_HU(ctx->r16, -0XC);
    // 0x80041C44: j           L_80041C50
    // 0x80041C48: nop

        goto L_80041C50;
    // 0x80041C48: nop

L_80041C4C:
    // 0x80041C4C: lhu         $a1, -0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, -0X2);
L_80041C50:
    // 0x80041C50: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80041C54: lh          $a0, 0x46A8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X46A8);
    // 0x80041C58: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80041C5C: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041C60: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80041C64: beq         $v0, $zero, L_80041CA0
    if (ctx->r2 == 0) {
        // 0x80041C68: subu        $v0, $a0, $v1
        ctx->r2 = SUB32(ctx->r4, ctx->r3);
            goto L_80041CA0;
    }
    // 0x80041C68: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x80041C6C: bltz        $v0, L_80041C84
    if (SIGNED(ctx->r2) < 0) {
        // 0x80041C70: slti        $v0, $v0, 0xC9
        ctx->r2 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
            goto L_80041C84;
    }
    // 0x80041C70: slti        $v0, $v0, 0xC9
    ctx->r2 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80041C74: beq         $v0, $zero, L_80041C94
    if (ctx->r2 == 0) {
        // 0x80041C78: nop
    
            goto L_80041C94;
    }
    // 0x80041C78: nop

    // 0x80041C7C: j           L_80041CA0
    // 0x80041C80: nop

        goto L_80041CA0;
    // 0x80041C80: nop

L_80041C84:
    // 0x80041C84: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x80041C88: slti        $v0, $v0, 0xC9
    ctx->r2 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80041C8C: bne         $v0, $zero, L_80041CA0
    if (ctx->r2 != 0) {
        // 0x80041C90: nop
    
            goto L_80041CA0;
    }
    // 0x80041C90: nop

L_80041C94:
    // 0x80041C94: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041C98: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x80041C9C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
L_80041CA0:
    // 0x80041CA0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041CA4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80041CA8: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80041CAC: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80041CB0: beq         $v0, $zero, L_80041CE4
    if (ctx->r2 == 0) {
        // 0x80041CB4: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_80041CE4;
    }
    // 0x80041CB4: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80041CB8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041CBC: slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80041CC0: bnel        $v0, $zero, L_80041D24
    if (ctx->r2 != 0) {
        // 0x80041CC4: addiu       $s0, $s0, 0x584
        ctx->r16 = ADD32(ctx->r16, 0X584);
            goto L_80041D24;
    }
    goto skip_1;
    // 0x80041CC4: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
    skip_1:
    // 0x80041CC8: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    // 0x80041CCC: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x80041CD0: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x80041CD4: bgezl       $v0, L_80041D0C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80041CD8: subu        $a0, $a0, $v1
        ctx->r4 = SUB32(ctx->r4, ctx->r3);
            goto L_80041D0C;
    }
    goto skip_2;
    // 0x80041CD8: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    skip_2:
    // 0x80041CDC: j           L_80041D0C
    // 0x80041CE0: subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
        goto L_80041D0C;
    // 0x80041CE0: subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
L_80041CE4:
    // 0x80041CE4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041CE8: slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80041CEC: bnel        $v0, $zero, L_80041D24
    if (ctx->r2 != 0) {
        // 0x80041CF0: addiu       $s0, $s0, 0x584
        ctx->r16 = ADD32(ctx->r16, 0X584);
            goto L_80041D24;
    }
    goto skip_3;
    // 0x80041CF0: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
    skip_3:
    // 0x80041CF4: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    // 0x80041CF8: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x80041CFC: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x80041D00: bltzl       $v0, L_80041D0C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80041D04: subu        $a0, $v1, $a0
        ctx->r4 = SUB32(ctx->r3, ctx->r4);
            goto L_80041D0C;
    }
    goto skip_4;
    // 0x80041D04: subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    skip_4:
    // 0x80041D08: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
L_80041D0C:
    // 0x80041D0C: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x80041D10: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80041D14: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80041D18: jal         0x80010B88
    // 0x80041D1C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    func_80010B88(rdram, ctx);
        goto after_1;
    // 0x80041D1C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    after_1:
    // 0x80041D20: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
L_80041D24:
    // 0x80041D24: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x80041D28: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80041D2C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80041D30: bne         $v0, $zero, L_80041C10
    if (ctx->r2 != 0) {
        // 0x80041D34: addiu       $s1, $s1, 0x584
        ctx->r17 = ADD32(ctx->r17, 0X584);
            goto L_80041C10;
    }
    // 0x80041D34: addiu       $s1, $s1, 0x584
    ctx->r17 = ADD32(ctx->r17, 0X584);
    // 0x80041D38: jal         0x8000A4BC
    // 0x80041D3C: nop

    func_8000A4BC(rdram, ctx);
        goto after_2;
    // 0x80041D3C: nop

    after_2:
    // 0x80041D40: jal         0x8003FA40
    // 0x80041D44: nop

    func_8003FA40(rdram, ctx);
        goto after_3;
    // 0x80041D44: nop

    after_3:
    // 0x80041D48: jal         0x80029D6C
    // 0x80041D4C: nop

    func_80029D6C(rdram, ctx);
        goto after_4;
    // 0x80041D4C: nop

    after_4:
L_80041D50:
    // 0x80041D50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80041D54: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80041D58: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80041D5C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80041D60: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80041D64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041D68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80041D6C: jr          $ra
    // 0x80041D70: nop

    return;
    // 0x80041D70: nop

;}
RECOMP_FUNC void func_80041D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041D74: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041D78: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80041D74 falls into func_80041D7C
    func_80041D7C(rdram, ctx);
;}
RECOMP_FUNC void func_80041D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041D7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041D84: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80041D88: lw          $s0, 0x90($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X90);
    // 0x80041D8C: jal         0x80047540
    // 0x80041D90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80047540(rdram, ctx);
        goto after_0;
    // 0x80041D90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80041D94: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80041D98: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x80041D9C: sh          $zero, 0x1B0($s0)
    MEM_H(0X1B0, ctx->r16) = 0;
    // 0x80041DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041DA4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80041DA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80041DAC: jr          $ra
    // 0x80041DB0: nop

    return;
    // 0x80041DB0: nop

;}
RECOMP_FUNC void func_80041DB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041DB4: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x80041DB8: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
L_80041DBC:
    // 0x80041DBC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80041DC0: beql        $v0, $zero, L_80041DE0
    if (ctx->r2 == 0) {
        // 0x80041DC4: addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
            goto L_80041DE0;
    }
    goto skip_0;
    // 0x80041DC4: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x80041DC8: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80041DCC: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80041DD0: bne         $v0, $zero, L_80041DE0
    if (ctx->r2 != 0) {
        // 0x80041DD4: addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
            goto L_80041DE0;
    }
    // 0x80041DD4: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80041DD8: j           L_80041DF4
    // 0x80041DDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041DF4;
    // 0x80041DDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80041DE0:
    // 0x80041DE0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80041DE4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80041DE8: bne         $v0, $zero, L_80041DBC
    if (ctx->r2 != 0) {
        // 0x80041DEC: addiu       $a0, $a0, 0x54
        ctx->r4 = ADD32(ctx->r4, 0X54);
            goto L_80041DBC;
    }
    // 0x80041DEC: addiu       $a0, $a0, 0x54
    ctx->r4 = ADD32(ctx->r4, 0X54);
    // 0x80041DF0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80041DF4:
    // 0x80041DF4: jr          $ra
    // 0x80041DF8: nop

    return;
    // 0x80041DF8: nop

;}
RECOMP_FUNC void func_80041DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041DFC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041E00: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80041E04: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80041E08: lh          $a0, 0x46A8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X46A8);
    // FALLTHROUGH: func_80041DFC falls into func_80041E0C
    func_80041E0C(rdram, ctx);
;}
RECOMP_FUNC void func_80041E0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041E0C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80041E10: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80041E14: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80041E18: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80041E1C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80041E20: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80041E24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80041E28: lh          $v1, 0x14($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X14);
    // 0x80041E2C: lhu         $a1, 0x14($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X14);
    // 0x80041E30: slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80041E34: beq         $v1, $zero, L_80041E48
    if (ctx->r3 == 0) {
        // 0x80041E38: nop
    
            goto L_80041E48;
    }
    // 0x80041E38: nop

    // 0x80041E3C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041E40: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x80041E44: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
L_80041E48:
    // 0x80041E48: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x80041E4C: addiu       $s1, $s1, -0x6C70
    ctx->r17 = ADD32(ctx->r17, -0X6C70);
    // 0x80041E50: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80041E54: lhu         $s3, 0x3E4($s3)
    ctx->r19 = MEM_HU(ctx->r19, 0X3E4);
    // 0x80041E58: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80041E5C: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80041E60: sra         $s2, $v0, 16
    ctx->r18 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041E64: addiu       $s0, $s1, 0x14
    ctx->r16 = ADD32(ctx->r17, 0X14);
L_80041E68:
    // 0x80041E68: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80041E6C: bnel        $v0, $zero, L_80041F38
    if (ctx->r2 != 0) {
        // 0x80041E70: addiu       $s0, $s0, 0x584
        ctx->r16 = ADD32(ctx->r16, 0X584);
            goto L_80041F38;
    }
    goto skip_0;
    // 0x80041E70: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
    skip_0:
    // 0x80041E74: jal         0x80041DB4
    // 0x80041E78: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80041DB4(rdram, ctx);
        goto after_0;
    // 0x80041E78: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x80041E7C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80041E80: bnel        $v0, $s4, L_80041F38
    if (ctx->r2 != ctx->r20) {
        // 0x80041E84: addiu       $s0, $s0, 0x584
        ctx->r16 = ADD32(ctx->r16, 0X584);
            goto L_80041F38;
    }
    goto skip_1;
    // 0x80041E84: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
    skip_1:
    // 0x80041E88: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041E8C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80041E90: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80041E94: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80041E98: beq         $v0, $zero, L_80041EAC
    if (ctx->r2 == 0) {
        // 0x80041E9C: nop
    
            goto L_80041EAC;
    }
    // 0x80041E9C: nop

    // 0x80041EA0: lhu         $a1, -0x10($s0)
    ctx->r5 = MEM_HU(ctx->r16, -0X10);
    // 0x80041EA4: j           L_80041EB0
    // 0x80041EA8: nop

        goto L_80041EB0;
    // 0x80041EA8: nop

L_80041EAC:
    // 0x80041EAC: lhu         $a1, -0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, -0X6);
L_80041EB0:
    // 0x80041EB0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80041EB4: lh          $a0, 0x46A8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X46A8);
    // 0x80041EB8: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80041EBC: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041EC0: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80041EC4: beq         $v0, $zero, L_80041F00
    if (ctx->r2 == 0) {
        // 0x80041EC8: subu        $v0, $a0, $v1
        ctx->r2 = SUB32(ctx->r4, ctx->r3);
            goto L_80041F00;
    }
    // 0x80041EC8: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x80041ECC: bltz        $v0, L_80041EE4
    if (SIGNED(ctx->r2) < 0) {
        // 0x80041ED0: slti        $v0, $v0, 0xC9
        ctx->r2 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
            goto L_80041EE4;
    }
    // 0x80041ED0: slti        $v0, $v0, 0xC9
    ctx->r2 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80041ED4: beq         $v0, $zero, L_80041EF4
    if (ctx->r2 == 0) {
        // 0x80041ED8: nop
    
            goto L_80041EF4;
    }
    // 0x80041ED8: nop

    // 0x80041EDC: j           L_80041F00
    // 0x80041EE0: nop

        goto L_80041F00;
    // 0x80041EE0: nop

L_80041EE4:
    // 0x80041EE4: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x80041EE8: slti        $v0, $v0, 0xC9
    ctx->r2 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80041EEC: bne         $v0, $zero, L_80041F00
    if (ctx->r2 != 0) {
        // 0x80041EF0: nop
    
            goto L_80041F00;
    }
    // 0x80041EF0: nop

L_80041EF4:
    // 0x80041EF4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041EF8: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x80041EFC: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
L_80041F00:
    // 0x80041F00: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041F04: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80041F08: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80041F0C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80041F10: beq         $v0, $zero, L_80041F24
    if (ctx->r2 == 0) {
        // 0x80041F14: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_80041F24;
    }
    // 0x80041F14: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80041F18: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041F1C: j           L_80041F2C
    // 0x80041F20: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
        goto L_80041F2C;
    // 0x80041F20: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
L_80041F24:
    // 0x80041F24: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041F28: slt         $v0, $v0, $s2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
L_80041F2C:
    // 0x80041F2C: beql        $v0, $zero, L_80041F34
    if (ctx->r2 == 0) {
        // 0x80041F30: sh          $s4, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r20;
            goto L_80041F34;
    }
    goto skip_2;
    // 0x80041F30: sh          $s4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r20;
    skip_2:
L_80041F34:
    // 0x80041F34: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
L_80041F38:
    // 0x80041F38: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x80041F3C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80041F40: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80041F44: bne         $v0, $zero, L_80041E68
    if (ctx->r2 != 0) {
        // 0x80041F48: addiu       $s1, $s1, 0x584
        ctx->r17 = ADD32(ctx->r17, 0X584);
            goto L_80041E68;
    }
    // 0x80041F48: addiu       $s1, $s1, 0x584
    ctx->r17 = ADD32(ctx->r17, 0X584);
    // 0x80041F4C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80041F50: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80041F54: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80041F58: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80041F5C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80041F60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041F64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80041F68: jr          $ra
    // 0x80041F6C: nop

    return;
    // 0x80041F6C: nop

;}
RECOMP_FUNC void func_80041F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041F70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80041F74: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80041F78: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80041F7C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80041F80: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80041F84: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80041F88: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80041F8C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80041F90: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80041F94: jal         0x800306EC
    // 0x80041F98: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80041F98: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    after_0:
    // 0x80041F9C: lh          $v1, 0x14($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X14);
    // 0x80041FA0: lhu         $a0, 0x14($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X14);
    // 0x80041FA4: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80041FA8: lh          $a3, 0x46A8($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X46A8);
    // 0x80041FAC: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80041FB0: slt         $v1, $a3, $v1
    ctx->r3 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80041FB4: bne         $v1, $zero, L_80041FC8
    if (ctx->r3 != 0) {
        // 0x80041FB8: addu        $a2, $v0, $zero
        ctx->r6 = ADD32(ctx->r2, 0);
            goto L_80041FC8;
    }
    // 0x80041FB8: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80041FBC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041FC0: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x80041FC4: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
L_80041FC8:
    // 0x80041FC8: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80041FCC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80041FD0: slt         $v0, $a3, $v0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80041FD4: bne         $v0, $zero, L_80041FEC
    if (ctx->r2 != 0) {
        // 0x80041FD8: addu        $v0, $a1, $a0
        ctx->r2 = ADD32(ctx->r5, ctx->r4);
            goto L_80041FEC;
    }
    // 0x80041FD8: addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // 0x80041FDC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80041FE0: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x80041FE4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80041FE8: addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
L_80041FEC:
    // 0x80041FEC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80041FF0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80041FF4: lh          $v1, 0x3294($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X3294);
    // 0x80041FF8: sra         $v0, $v0, 17
    ctx->r2 = S32(SIGNED(ctx->r2) >> 17);
    // 0x80041FFC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80042000: slt         $v1, $v0, $v1
    ctx->r3 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80042004: bne         $v1, $zero, L_80042010
    if (ctx->r3 != 0) {
        // 0x80042008: addu        $a1, $v0, $zero
        ctx->r5 = ADD32(ctx->r2, 0);
            goto L_80042010;
    }
    // 0x80042008: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8004200C: subu        $a1, $v0, $a0
    ctx->r5 = SUB32(ctx->r2, ctx->r4);
L_80042010:
    // 0x80042010: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x80042014: sh          $a1, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r5;
    // 0x80042018: sh          $a1, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r5;
    // 0x8004201C: sh          $a1, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r5;
    // 0x80042020: lhu         $v1, 0x18($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X18);
    // 0x80042024: ori         $a0, $a0, 0x5E
    ctx->r4 = ctx->r4 | 0X5E;
    // 0x80042028: addiu       $v0, $zero, 0x5500
    ctx->r2 = ADD32(0, 0X5500);
    // 0x8004202C: sw          $v0, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r2;
    // 0x80042030: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80042034: addiu       $v0, $v0, 0xFF0
    ctx->r2 = ADD32(ctx->r2, 0XFF0);
    // 0x80042038: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x8004203C: sw          $v0, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r2;
    // 0x80042040: sh          $v1, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r3;
    // 0x80042044: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80042048: sw          $a2, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r6;
    // 0x8004204C: jal         0x80023E44
    // 0x80042050: nop

    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x80042050: nop

    after_1:
    // 0x80042054: addiu       $v1, $zero, 0x743
    ctx->r3 = ADD32(0, 0X743);
    // 0x80042058: sh          $v1, 0x70($v0)
    MEM_H(0X70, ctx->r2) = ctx->r3;
    // 0x8004205C: sh          $zero, 0xDC($s3)
    MEM_H(0XDC, ctx->r19) = 0;
    // 0x80042060: sh          $zero, 0xDC($s2)
    MEM_H(0XDC, ctx->r18) = 0;
    // 0x80042064: sw          $s2, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r18;
    // 0x80042068: sw          $s3, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->r19;
    // 0x8004206C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80042070: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80042074: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80042078: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8004207C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80042080: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80042084: jr          $ra
    // 0x80042088: nop

    return;
    // 0x80042088: nop

;}
RECOMP_FUNC void func_8004208C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004208C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042090: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_8004208C falls into func_80042094
    func_80042094(rdram, ctx);
;}
RECOMP_FUNC void func_80042094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042094: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80042098: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8004209C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800420A0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800420A4: lw          $s0, 0x94($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X94);
    // 0x800420A8: lw          $s1, 0x90($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X90);
    // 0x800420AC: lhu         $v1, 0x18C($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X18C);
    // 0x800420B0: lhu         $v0, 0x18C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18C);
    // 0x800420B4: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800420B8: beq         $v0, $zero, L_800420D4
    if (ctx->r2 == 0) {
        // 0x800420BC: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_800420D4;
    }
    // 0x800420BC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x800420C0: jal         0x80001414
    // 0x800420C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80001414(rdram, ctx);
        goto after_0;
    // 0x800420C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800420C8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800420CC: bne         $v0, $zero, L_800420E8
    if (ctx->r2 != 0) {
        // 0x800420D0: nop
    
            goto L_800420E8;
    }
    // 0x800420D0: nop

L_800420D4:
    // 0x800420D4: addiu       $v0, $zero, 0x43
    ctx->r2 = ADD32(0, 0X43);
    // 0x800420D8: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x800420DC: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x800420E0: j           L_800421A0
    // 0x800420E4: sh          $v0, 0x5A($s1)
    MEM_H(0X5A, ctx->r17) = ctx->r2;
        goto L_800421A0;
    // 0x800420E4: sh          $v0, 0x5A($s1)
    MEM_H(0X5A, ctx->r17) = ctx->r2;
L_800420E8:
    // 0x800420E8: lhu         $v0, 0x3C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X3C);
    // 0x800420EC: beq         $v0, $zero, L_8004210C
    if (ctx->r2 == 0) {
        // 0x800420F0: nop
    
            goto L_8004210C;
    }
    // 0x800420F0: nop

    // 0x800420F4: sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
    // 0x800420F8: lhu         $v0, 0x3E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3E);
    // 0x800420FC: lhu         $v1, 0x3E($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X3E);
    // 0x80042100: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80042104: sh          $v0, 0x3E($s0)
    MEM_H(0X3E, ctx->r16) = ctx->r2;
    // 0x80042108: sh          $zero, 0x3E($s1)
    MEM_H(0X3E, ctx->r17) = 0;
L_8004210C:
    // 0x8004210C: lhu         $v1, 0x140($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X140);
    // 0x80042110: beq         $v1, $zero, L_80042128
    if (ctx->r3 == 0) {
        // 0x80042114: nop
    
            goto L_80042128;
    }
    // 0x80042114: nop

    // 0x80042118: lhu         $v0, 0x140($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X140);
    // 0x8004211C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80042120: sh          $v0, 0x140($s0)
    MEM_H(0X140, ctx->r16) = ctx->r2;
    // 0x80042124: sh          $zero, 0x140($s1)
    MEM_H(0X140, ctx->r17) = 0;
L_80042128:
    // 0x80042128: lhu         $v1, 0x142($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X142);
    // 0x8004212C: beq         $v1, $zero, L_80042144
    if (ctx->r3 == 0) {
        // 0x80042130: nop
    
            goto L_80042144;
    }
    // 0x80042130: nop

    // 0x80042134: lhu         $v0, 0x142($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X142);
    // 0x80042138: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004213C: sh          $v0, 0x142($s0)
    MEM_H(0X142, ctx->r16) = ctx->r2;
    // 0x80042140: sh          $zero, 0x142($s1)
    MEM_H(0X142, ctx->r17) = 0;
L_80042144:
    // 0x80042144: lhu         $v1, 0x142($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X142);
    // 0x80042148: lhu         $a0, 0x140($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X140);
    // 0x8004214C: sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x80042150: bne         $v0, $zero, L_80042180
    if (ctx->r2 != 0) {
        // 0x80042154: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80042180;
    }
    // 0x80042154: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80042158: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8004215C: bne         $v0, $zero, L_80042180
    if (ctx->r2 != 0) {
        // 0x80042160: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80042180;
    }
    // 0x80042160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80042164: bne         $v1, $zero, L_80042180
    if (ctx->r3 != 0) {
        // 0x80042168: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80042180;
    }
    // 0x80042168: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004216C: lhu         $v0, 0x3C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3C);
    // 0x80042170: bne         $v0, $zero, L_80042180
    if (ctx->r2 != 0) {
        // 0x80042174: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80042180;
    }
    // 0x80042174: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80042178: j           L_80042184
    // 0x8004217C: sh          $zero, 0x56($s0)
    MEM_H(0X56, ctx->r16) = 0;
        goto L_80042184;
    // 0x8004217C: sh          $zero, 0x56($s0)
    MEM_H(0X56, ctx->r16) = 0;
L_80042180:
    // 0x80042180: sh          $v0, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r2;
L_80042184:
    // 0x80042184: lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // 0x80042188: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8004218C: addiu       $v0, $zero, 0x43
    ctx->r2 = ADD32(0, 0X43);
    // 0x80042190: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x80042194: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x80042198: jal         0x8003BA80
    // 0x8004219C: sh          $v0, 0x5A($s1)
    MEM_H(0X5A, ctx->r17) = ctx->r2;
    func_8003BA80(rdram, ctx);
        goto after_1;
    // 0x8004219C: sh          $v0, 0x5A($s1)
    MEM_H(0X5A, ctx->r17) = ctx->r2;
    after_1:
L_800421A0:
    // 0x800421A0: sh          $zero, 0x1C8($s0)
    MEM_H(0X1C8, ctx->r16) = 0;
    // 0x800421A4: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x800421A8: addiu       $v1, $zero, 0xE1
    ctx->r3 = ADD32(0, 0XE1);
    // 0x800421AC: sh          $v1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r3;
    // 0x800421B0: lw          $v0, 0x68($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X68);
    // 0x800421B4: sh          $v1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r3;
    // 0x800421B8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800421BC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800421C0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800421C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800421C8: jr          $ra
    // 0x800421CC: nop

    return;
    // 0x800421CC: nop

;}
RECOMP_FUNC void func_800421D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800421D0: jr          $ra
    // 0x800421D4: nop

    return;
    // 0x800421D4: nop

;}
RECOMP_FUNC void func_800421D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800421D8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800421DC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800421E0: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x800421E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800421E8: sh          $v0, 0x1C8($v1)
    MEM_H(0X1C8, ctx->r3) = ctx->r2;
    // 0x800421EC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800421F0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800421F4: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x800421F8: jr          $ra
    // 0x800421FC: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    return;
    // 0x800421FC: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80042200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042200: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042204: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042208: lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X90);
    // 0x8004220C: lw          $v0, 0x1D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1D0);
    // 0x80042210: beq         $v0, $zero, L_80042238
    if (ctx->r2 == 0) {
        // 0x80042214: nop
    
            goto L_80042238;
    }
    // 0x80042214: nop

    // 0x80042218: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8004221C: lh          $v0, 0x18($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X18);
    // 0x80042220: slti        $v0, $v0, 0x150
    ctx->r2 = SIGNED(ctx->r2) < 0X150 ? 1 : 0;
    // 0x80042224: beq         $v0, $zero, L_80042238
    if (ctx->r2 == 0) {
        // 0x80042228: nop
    
            goto L_80042238;
    }
    // 0x80042228: nop

    // 0x8004222C: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x80042230: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80042234: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
L_80042238:
    // 0x80042238: jr          $ra
    // 0x8004223C: nop

    return;
    // 0x8004223C: nop

;}
RECOMP_FUNC void func_80042240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042240: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042244: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80042248: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x8004224C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80042250: jr          $ra
    // 0x80042254: sh          $v0, 0xDC($v1)
    MEM_H(0XDC, ctx->r3) = ctx->r2;
    return;
    // 0x80042254: sh          $v0, 0xDC($v1)
    MEM_H(0XDC, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80042258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042258: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004225C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80042260: lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X90);
    // 0x80042264: jr          $ra
    // 0x80042268: sh          $zero, 0xDC($v0)
    MEM_H(0XDC, ctx->r2) = 0;
    return;
    // 0x80042268: sh          $zero, 0xDC($v0)
    MEM_H(0XDC, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8004226C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004226C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042270: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80042274: lw          $a0, 0x90($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X90);
    // 0x80042278: lw          $v1, 0x1C4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C4);
    // 0x8004227C: lui         $v0, 0x27
    ctx->r2 = S32(0X27 << 16);
    // 0x80042280: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80042284: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80042288: bne         $v0, $zero, L_8004229C
    if (ctx->r2 != 0) {
        // 0x8004228C: lui         $v0, 0x14F
        ctx->r2 = S32(0X14F << 16);
            goto L_8004229C;
    }
    // 0x8004228C: lui         $v0, 0x14F
    ctx->r2 = S32(0X14F << 16);
    // 0x80042290: lhu         $v1, 0x168($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X168);
    // 0x80042294: j           L_800422B0
    // 0x80042298: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_800422B0;
    // 0x80042298: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_8004229C:
    // 0x8004229C: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x800422A0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800422A4: beq         $v0, $zero, L_800422BC
    if (ctx->r2 == 0) {
        // 0x800422A8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800422BC;
    }
    // 0x800422A8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800422AC: lhu         $v1, 0x168($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X168);
L_800422B0:
    // 0x800422B0: bne         $v1, $v0, L_800422BC
    if (ctx->r3 != ctx->r2) {
        // 0x800422B4: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_800422BC;
    }
    // 0x800422B4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800422B8: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
L_800422BC:
    // 0x800422BC: jr          $ra
    // 0x800422C0: nop

    return;
    // 0x800422C0: nop

;}
RECOMP_FUNC void func_800422C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800422C4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800422C8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800422CC: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x800422D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800422D4: sh          $v0, 0x18E($v1)
    MEM_H(0X18E, ctx->r3) = ctx->r2;
    // 0x800422D8: addiu       $v0, $zero, 0x4C
    ctx->r2 = ADD32(0, 0X4C);
    // 0x800422DC: sh          $v0, 0x5A($v1)
    MEM_H(0X5A, ctx->r3) = ctx->r2;
    // 0x800422E0: lui         $v0, 0x44
    ctx->r2 = S32(0X44 << 16);
    // 0x800422E4: jr          $ra
    // 0x800422E8: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    return;
    // 0x800422E8: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_800422EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800422EC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800422F0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800422F4: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x800422F8: addiu       $v0, $zero, 0x1A4
    ctx->r2 = ADD32(0, 0X1A4);
    // 0x800422FC: jr          $ra
    // 0x80042300: sh          $v0, 0x13E($v1)
    MEM_H(0X13E, ctx->r3) = ctx->r2;
    return;
    // 0x80042300: sh          $v0, 0x13E($v1)
    MEM_H(0X13E, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80042304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042304: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80042308: lhu         $v0, 0x11C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X11C);
    // 0x8004230C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042310: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042314: bne         $v0, $zero, L_8004235C
    if (ctx->r2 != 0) {
        // 0x80042318: nop
    
            goto L_8004235C;
    }
    // 0x80042318: nop

    // 0x8004231C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80042320: lhu         $v0, 0x5A2A($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X5A2A);
    // 0x80042324: beq         $v0, $zero, L_8004235C
    if (ctx->r2 == 0) {
        // 0x80042328: nop
    
            goto L_8004235C;
    }
    // 0x80042328: nop

    // 0x8004232C: lh          $a0, 0x14($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X14);
    // 0x80042330: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042334: bne         $v0, $zero, L_8004235C
    if (ctx->r2 != 0) {
        // 0x80042338: nop
    
            goto L_8004235C;
    }
    // 0x80042338: nop

    // 0x8004233C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042340: lhu         $v0, -0x671C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X671C);
    // 0x80042344: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80042348: bne         $v0, $zero, L_8004235C
    if (ctx->r2 != 0) {
        // 0x8004234C: nop
    
            goto L_8004235C;
    }
    // 0x8004234C: nop

    // 0x80042350: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x80042354: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80042358: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
L_8004235C:
    // 0x8004235C: jr          $ra
    // 0x80042360: nop

    return;
    // 0x80042360: nop

;}
RECOMP_FUNC void func_80042364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042364: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042368: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8004236C: lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X90);
    // 0x80042370: jr          $ra
    // 0x80042374: sh          $zero, 0x18A($v0)
    MEM_H(0X18A, ctx->r2) = 0;
    return;
    // 0x80042374: sh          $zero, 0x18A($v0)
    MEM_H(0X18A, ctx->r2) = 0;
    // 0x80042378: nop

    // 0x8004237C: nop

;}
RECOMP_FUNC void func_80042380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042380: jr          $ra
    // 0x80042384: nop

    return;
    // 0x80042384: nop

;}
RECOMP_FUNC void func_80042388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042388: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004238C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042390: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80042394: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x80042398: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004239C: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x800423A0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800423A4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800423A8: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x800423AC: addiu       $v0, $v0, 0x3000
    ctx->r2 = ADD32(ctx->r2, 0X3000);
    // 0x800423B0: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x800423B4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800423B8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800423BC: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x800423C0: lui         $a0, 0x6
    ctx->r4 = S32(0X6 << 16);
    // 0x800423C4: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800423C8: bnel        $v0, $zero, L_800423D0
    if (ctx->r2 != 0) {
        // 0x800423CC: sw          $a0, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->r4;
            goto L_800423D0;
    }
    goto skip_0;
    // 0x800423CC: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    skip_0:
L_800423D0:
    // 0x800423D0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800423D4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800423D8: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x800423DC: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x800423E0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800423E4: jr          $ra
    // 0x800423E8: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    return;
    // 0x800423E8: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_800423EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800423EC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800423F0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_800423EC falls into func_800423F4
    func_800423F4(rdram, ctx);
;}
RECOMP_FUNC void func_800423F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800423F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800423F8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800423FC: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80042400: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80042404: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80042408: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004240C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80042410: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x80042414: beq         $v1, $zero, L_80042430
    if (ctx->r3 == 0) {
        // 0x80042418: addiu       $v0, $zero, 0xE0
        ctx->r2 = ADD32(0, 0XE0);
            goto L_80042430;
    }
    // 0x80042418: addiu       $v0, $zero, 0xE0
    ctx->r2 = ADD32(0, 0XE0);
    // 0x8004241C: lhu         $v0, 0x76($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X76);
    // 0x80042420: bne         $v0, $zero, L_80042430
    if (ctx->r2 != 0) {
        // 0x80042424: addiu       $v0, $zero, 0xE0
        ctx->r2 = ADD32(0, 0XE0);
            goto L_80042430;
    }
    // 0x80042424: addiu       $v0, $zero, 0xE0
    ctx->r2 = ADD32(0, 0XE0);
    // 0x80042428: lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6);
    // 0x8004242C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80042430:
    // 0x80042430: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80042434: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80042438: lh          $v1, 0x18($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X18);
    // 0x8004243C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80042440: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042444: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042448: bne         $v1, $zero, L_80042468
    if (ctx->r3 != 0) {
        // 0x8004244C: nop
    
            goto L_80042468;
    }
    // 0x8004244C: nop

    // 0x80042450: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x80042454: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80042458: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x8004245C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80042460: jal         0x800249B4
    // 0x80042464: nop

    func_800249B4(rdram, ctx);
        goto after_0;
    // 0x80042464: nop

    after_0:
L_80042468:
    // 0x80042468: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8004246C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80042470: jr          $ra
    // 0x80042474: nop

    return;
    // 0x80042474: nop

;}
RECOMP_FUNC void func_80042478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042478: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004247C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80042478 falls into func_80042480
    func_80042480(rdram, ctx);
;}
RECOMP_FUNC void func_80042480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042480: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80042484: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042488: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004248C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80042490: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80042494: lw          $s1, 0x90($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X90);
    // 0x80042498: beq         $s1, $zero, L_8004254C
    if (ctx->r17 == 0) {
        // 0x8004249C: nop
    
            goto L_8004254C;
    }
    // 0x8004249C: nop

    // 0x800424A0: lhu         $v0, 0x76($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X76);
    // 0x800424A4: bne         $v0, $zero, L_8004254C
    if (ctx->r2 != 0) {
        // 0x800424A8: nop
    
            goto L_8004254C;
    }
    // 0x800424A8: nop

    // 0x800424AC: lw          $v0, 0x90($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X90);
    // 0x800424B0: bne         $v0, $zero, L_80042568
    if (ctx->r2 != 0) {
        // 0x800424B4: nop
    
            goto L_80042568;
    }
    // 0x800424B4: nop

    // 0x800424B8: lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X14);
    // 0x800424BC: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800424C0: xori        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 ^ 0X2;
    // 0x800424C4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800424C8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800424CC: beq         $v1, $zero, L_80042558
    if (ctx->r3 == 0) {
        // 0x800424D0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80042558;
    }
    // 0x800424D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800424D4: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x800424D8: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x800424DC: addiu       $s2, $s2, 0x10AC
    ctx->r18 = ADD32(ctx->r18, 0X10AC);
    // 0x800424E0: bne         $v1, $v0, L_800424F0
    if (ctx->r3 != ctx->r2) {
        // 0x800424E4: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800424F0;
    }
    // 0x800424E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800424E8: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x800424EC: addiu       $s2, $s2, 0x10AC
    ctx->r18 = ADD32(ctx->r18, 0X10AC);
L_800424F0:
    // 0x800424F0: sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
    // 0x800424F4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800424F8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800424FC: sw          $v0, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r2;
    // 0x80042500: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042504: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80042508: lw          $s0, 0x94($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X94);
    // 0x8004250C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80042510: jal         0x80010B88
    // 0x80042514: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80010B88(rdram, ctx);
        goto after_0;
    // 0x80042514: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80042518: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8004251C: jal         0x80010BBC
    // 0x80042520: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80010BBC(rdram, ctx);
        goto after_1;
    // 0x80042520: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80042524: lhu         $v0, 0x58($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X58);
    // 0x80042528: bne         $v0, $zero, L_80042534
    if (ctx->r2 != 0) {
        // 0x8004252C: addiu       $v1, $zero, 0x50
        ctx->r3 = ADD32(0, 0X50);
            goto L_80042534;
    }
    // 0x8004252C: addiu       $v1, $zero, 0x50
    ctx->r3 = ADD32(0, 0X50);
    // 0x80042530: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
L_80042534:
    // 0x80042534: sh          $v1, 0x82($s1)
    MEM_H(0X82, ctx->r17) = ctx->r3;
    // 0x80042538: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004253C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042540: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x80042544: j           L_800425A8
    // 0x80042548: addiu       $v0, $v0, -0x17
    ctx->r2 = ADD32(ctx->r2, -0X17);
        goto L_800425A8;
    // 0x80042548: addiu       $v0, $v0, -0x17
    ctx->r2 = ADD32(ctx->r2, -0X17);
L_8004254C:
    // 0x8004254C: lw          $v0, 0x90($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X90);
    // 0x80042550: bne         $v0, $zero, L_80042568
    if (ctx->r2 != 0) {
        // 0x80042554: nop
    
            goto L_80042568;
    }
    // 0x80042554: nop

L_80042558:
    // 0x80042558: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8004255C: addiu       $s2, $s2, 0x10AC
    ctx->r18 = ADD32(ctx->r18, 0X10AC);
    // 0x80042560: j           L_800425AC
    // 0x80042564: nop

        goto L_800425AC;
    // 0x80042564: nop

L_80042568:
    // 0x80042568: jal         0x80043290
    // 0x8004256C: nop

    func_80043290(rdram, ctx);
        goto after_2;
    // 0x8004256C: nop

    after_2:
    // 0x80042570: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80042574: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80042578: bne         $v0, $v1, L_80042590
    if (ctx->r2 != ctx->r3) {
        // 0x8004257C: nop
    
            goto L_80042590;
    }
    // 0x8004257C: nop

    // 0x80042580: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x80042584: addiu       $s2, $s2, 0xF50
    ctx->r18 = ADD32(ctx->r18, 0XF50);
    // 0x80042588: j           L_800425AC
    // 0x8004258C: nop

        goto L_800425AC;
    // 0x8004258C: nop

L_80042590:
    // 0x80042590: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042594: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042598: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x8004259C: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x800425A0: addiu       $s2, $s2, 0x10AC
    ctx->r18 = ADD32(ctx->r18, 0X10AC);
    // 0x800425A4: addiu       $v0, $v0, -0x17
    ctx->r2 = ADD32(ctx->r2, -0X17);
L_800425A8:
    // 0x800425A8: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
L_800425AC:
    // 0x800425AC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800425B0: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x800425B4: jal         0x800249B4
    // 0x800425B8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_800249B4(rdram, ctx);
        goto after_3;
    // 0x800425B8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_3:
    // 0x800425BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800425C0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800425C4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800425C8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800425CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800425D0: jr          $ra
    // 0x800425D4: nop

    return;
    // 0x800425D4: nop

;}
RECOMP_FUNC void func_800425D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800425D8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800425DC: lhu         $v1, 0x90($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X90);
    // 0x800425E0: addiu       $v0, $zero, 0x240
    ctx->r2 = ADD32(0, 0X240);
    // 0x800425E4: beq         $v1, $v0, L_800425F8
    if (ctx->r3 == ctx->r2) {
        // 0x800425E8: nop
    
            goto L_800425F8;
    }
    // 0x800425E8: nop

    // 0x800425EC: lhu         $v0, 0x28($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X28);
    // 0x800425F0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800425F4: sh          $v0, 0x28($a1)
    MEM_H(0X28, ctx->r5) = ctx->r2;
L_800425F8:
    // 0x800425F8: jr          $ra
    // 0x800425FC: nop

    return;
    // 0x800425FC: nop

;}
RECOMP_FUNC void func_80042600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042600: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042604: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // FALLTHROUGH: func_80042600 falls into func_80042608
    func_80042608(rdram, ctx);
;}
RECOMP_FUNC void func_80042608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042608: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004260C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80042610: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80042614: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80042618: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004261C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80042620: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80042624: lw          $s3, 0x90($v1)
    ctx->r19 = MEM_W(ctx->r3, 0X90);
    // 0x80042628: lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // 0x8004262C: lw          $s4, 0x31C0($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X31C0);
    // 0x80042630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80042634: lhu         $a0, 0x1B0($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X1B0);
    // 0x80042638: lhu         $s0, 0x14($v1)
    ctx->r16 = MEM_HU(ctx->r3, 0X14);
    // 0x8004263C: lhu         $s1, 0x18($v1)
    ctx->r17 = MEM_HU(ctx->r3, 0X18);
    // 0x80042640: beq         $a0, $v0, L_80042660
    if (ctx->r4 == ctx->r2) {
        // 0x80042644: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80042660;
    }
    // 0x80042644: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80042648: bne         $a0, $v0, L_80042670
    if (ctx->r4 != ctx->r2) {
        // 0x8004264C: nop
    
            goto L_80042670;
    }
    // 0x8004264C: nop

    // 0x80042650: addiu       $s0, $s0, -0x24
    ctx->r16 = ADD32(ctx->r16, -0X24);
    // 0x80042654: addiu       $s1, $s1, -0x2B
    ctx->r17 = ADD32(ctx->r17, -0X2B);
    // 0x80042658: j           L_80042698
    // 0x8004265C: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
        goto L_80042698;
    // 0x8004265C: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_80042660:
    // 0x80042660: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x80042664: addiu       $s1, $s1, -0x2B
    ctx->r17 = ADD32(ctx->r17, -0X2B);
    // 0x80042668: j           L_80042698
    // 0x8004266C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
        goto L_80042698;
    // 0x8004266C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_80042670:
    // 0x80042670: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x80042674: sll         $v1, $s0, 16
    ctx->r3 = S32(ctx->r16 << 16);
    // 0x80042678: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004267C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80042680: bne         $v0, $zero, L_80042690
    if (ctx->r2 != 0) {
        // 0x80042684: addu        $s2, $v0, $zero
        ctx->r18 = ADD32(ctx->r2, 0);
            goto L_80042690;
    }
    // 0x80042684: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80042688: j           L_80042694
    // 0x8004268C: addiu       $s0, $v1, 0x21
    ctx->r16 = ADD32(ctx->r3, 0X21);
        goto L_80042694;
    // 0x8004268C: addiu       $s0, $v1, 0x21
    ctx->r16 = ADD32(ctx->r3, 0X21);
L_80042690:
    // 0x80042690: addiu       $s0, $v1, -0x21
    ctx->r16 = ADD32(ctx->r3, -0X21);
L_80042694:
    // 0x80042694: addiu       $s1, $s1, -0x2A
    ctx->r17 = ADD32(ctx->r17, -0X2A);
L_80042698:
    // 0x80042698: jal         0x800306EC
    // 0x8004269C: nop

    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x8004269C: nop

    after_0:
    // 0x800426A0: lui         $a0, 0x4F00
    ctx->r4 = S32(0X4F00 << 16);
    // 0x800426A4: ori         $a0, $a0, 0xC2
    ctx->r4 = ctx->r4 | 0XC2;
    // 0x800426A8: addiu       $v1, $zero, 0x1100
    ctx->r3 = ADD32(0, 0X1100);
    // 0x800426AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800426B0: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x800426B4: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x800426B8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800426BC: addiu       $v1, $v1, 0x10AC
    ctx->r3 = ADD32(ctx->r3, 0X10AC);
    // 0x800426C0: sh          $s0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r16;
    // 0x800426C4: sh          $s1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r17;
    // 0x800426C8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800426CC: jal         0x80023E44
    // 0x800426D0: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x800426D0: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    after_1:
    // 0x800426D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800426D8: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x800426DC: lhu         $v1, 0x22($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X22);
    // 0x800426E0: or          $v1, $v1, $s2
    ctx->r3 = ctx->r3 | ctx->r18;
    // 0x800426E4: sh          $v1, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r3;
    // 0x800426E8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800426EC: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800426F0: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x800426F4: sw          $v0, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->r2;
    // 0x800426F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800426FC: sw          $s4, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r20;
    // 0x80042700: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80042704: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80042708: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8004270C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80042710: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80042714: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80042718: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004271C: jr          $ra
    // 0x80042720: nop

    return;
    // 0x80042720: nop

;}
RECOMP_FUNC void func_80042724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042724: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042728: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80042724 falls into func_8004272C
    func_8004272C(rdram, ctx);
;}
RECOMP_FUNC void func_8004272C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004272C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80042730: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80042734: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80042738: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8004273C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80042740: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80042744: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80042748: lw          $s3, 0x90($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X90);
    // 0x8004274C: lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // 0x80042750: lw          $s4, 0x31C0($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X31C0);
    // 0x80042754: lhu         $s1, 0x14($v0)
    ctx->r17 = MEM_HU(ctx->r2, 0X14);
    // 0x80042758: lhu         $v1, 0x1B0($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X1B0);
    // 0x8004275C: lhu         $s0, 0x18($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X18);
    // 0x80042760: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80042764: bnel        $v1, $v0, L_8004277C
    if (ctx->r3 != ctx->r2) {
        // 0x80042768: addiu       $s1, $s1, -0x4
        ctx->r17 = ADD32(ctx->r17, -0X4);
            goto L_8004277C;
    }
    goto skip_0;
    // 0x80042768: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    skip_0:
    // 0x8004276C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80042770: addiu       $s0, $s0, -0x28
    ctx->r16 = ADD32(ctx->r16, -0X28);
    // 0x80042774: j           L_80042784
    // 0x80042778: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
        goto L_80042784;
    // 0x80042778: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_8004277C:
    // 0x8004277C: addiu       $s0, $s0, -0x28
    ctx->r16 = ADD32(ctx->r16, -0X28);
    // 0x80042780: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_80042784:
    // 0x80042784: jal         0x800306EC
    // 0x80042788: nop

    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80042788: nop

    after_0:
    // 0x8004278C: lui         $a0, 0x4F00
    ctx->r4 = S32(0X4F00 << 16);
    // 0x80042790: ori         $a0, $a0, 0xC2
    ctx->r4 = ctx->r4 | 0XC2;
    // 0x80042794: addiu       $v1, $zero, 0x1100
    ctx->r3 = ADD32(0, 0X1100);
    // 0x80042798: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004279C: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x800427A0: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x800427A4: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800427A8: addiu       $v1, $v1, 0x10AC
    ctx->r3 = ADD32(ctx->r3, 0X10AC);
    // 0x800427AC: sh          $s1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r17;
    // 0x800427B0: sh          $s0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r16;
    // 0x800427B4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800427B8: jal         0x80023E44
    // 0x800427BC: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x800427BC: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    after_1:
    // 0x800427C0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800427C4: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x800427C8: lhu         $v1, 0x22($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X22);
    // 0x800427CC: or          $v1, $v1, $s2
    ctx->r3 = ctx->r3 | ctx->r18;
    // 0x800427D0: sh          $v1, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r3;
    // 0x800427D4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800427D8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800427DC: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x800427E0: sw          $v0, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->r2;
    // 0x800427E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800427E8: sw          $s4, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r20;
    // 0x800427EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800427F0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800427F4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800427F8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800427FC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80042800: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80042804: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80042808: jr          $ra
    // 0x8004280C: nop

    return;
    // 0x8004280C: nop

;}
RECOMP_FUNC void func_80042810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042810: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80042814: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // FALLTHROUGH: func_80042810 falls into func_80042818
    func_80042818(rdram, ctx);
;}
RECOMP_FUNC void func_80042818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042818: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004281C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80042820: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80042824: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80042828: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004282C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80042830: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80042834: lhu         $v1, 0x18($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X18);
    // 0x80042838: lw          $s3, 0x90($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X90);
    // 0x8004283C: lhu         $v0, 0x30($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X30);
    // 0x80042840: lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // 0x80042844: lw          $s4, 0x31C0($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X31C0);
    // 0x80042848: lhu         $a1, 0x1B0($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X1B0);
    // 0x8004284C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80042850: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80042854: beq         $a1, $v0, L_80042874
    if (ctx->r5 == ctx->r2) {
        // 0x80042858: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80042874;
    }
    // 0x80042858: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004285C: bne         $a1, $v0, L_80042884
    if (ctx->r5 != ctx->r2) {
        // 0x80042860: addiu       $s1, $v1, 0x21
        ctx->r17 = ADD32(ctx->r3, 0X21);
            goto L_80042884;
    }
    // 0x80042860: addiu       $s1, $v1, 0x21
    ctx->r17 = ADD32(ctx->r3, 0X21);
    // 0x80042864: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x80042868: addiu       $s1, $v1, 0x14
    ctx->r17 = ADD32(ctx->r3, 0X14);
    // 0x8004286C: j           L_8004289C
    // 0x80042870: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
        goto L_8004289C;
    // 0x80042870: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_80042874:
    // 0x80042874: addiu       $s0, $zero, -0x8
    ctx->r16 = ADD32(0, -0X8);
    // 0x80042878: addiu       $s1, $v1, 0x14
    ctx->r17 = ADD32(ctx->r3, 0X14);
    // 0x8004287C: j           L_8004289C
    // 0x80042880: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
        goto L_8004289C;
    // 0x80042880: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_80042884:
    // 0x80042884: lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X22);
    // 0x80042888: addiu       $s0, $zero, -0x1E
    ctx->r16 = ADD32(0, -0X1E);
    // 0x8004288C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80042890: bne         $v0, $zero, L_8004289C
    if (ctx->r2 != 0) {
        // 0x80042894: addu        $s2, $v0, $zero
        ctx->r18 = ADD32(ctx->r2, 0);
            goto L_8004289C;
    }
    // 0x80042894: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80042898: addiu       $s0, $zero, 0x1E
    ctx->r16 = ADD32(0, 0X1E);
L_8004289C:
    // 0x8004289C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800428A0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800428A4: lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X14);
    // 0x800428A8: jal         0x800306EC
    // 0x800428AC: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x800428AC: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    after_0:
    // 0x800428B0: addiu       $v1, $zero, 0x1100
    ctx->r3 = ADD32(0, 0X1100);
    // 0x800428B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800428B8: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x800428BC: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x800428C0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800428C4: addiu       $v1, $v1, 0x10FC
    ctx->r3 = ADD32(ctx->r3, 0X10FC);
    // 0x800428C8: sh          $s1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r17;
    // 0x800428CC: sh          $s0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r16;
    // 0x800428D0: jal         0x80023E44
    // 0x800428D4: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x800428D4: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    after_1:
    // 0x800428D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800428DC: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x800428E0: lhu         $v1, 0x22($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X22);
    // 0x800428E4: or          $v1, $v1, $s2
    ctx->r3 = ctx->r3 | ctx->r18;
    // 0x800428E8: sh          $v1, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r3;
    // 0x800428EC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800428F0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800428F4: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x800428F8: sw          $v0, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->r2;
    // 0x800428FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80042900: sw          $s4, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r20;
    // 0x80042904: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80042908: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8004290C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80042910: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80042914: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80042918: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004291C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80042920: jr          $ra
    // 0x80042924: nop

    return;
    // 0x80042924: nop

;}
RECOMP_FUNC void func_80042928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042928: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004292C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042930: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x80042934: ori         $a2, $zero, 0xC000
    ctx->r6 = 0 | 0XC000;
    // 0x80042938: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x8004293C: lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X0);
    // 0x80042940: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80042944: beq         $v0, $zero, L_80042958
    if (ctx->r2 == 0) {
        // 0x80042948: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_80042958;
    }
    // 0x80042948: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8004294C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80042950: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
    // 0x80042954: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
L_80042958:
    // 0x80042958: sw          $a2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r6;
    // 0x8004295C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042960: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042964: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // 0x80042968: sw          $v0, 0x88($v1)
    MEM_W(0X88, ctx->r3) = ctx->r2;
    // 0x8004296C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042970: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042974: lui         $v0, 0xFFFE
    ctx->r2 = S32(0XFFFE << 16);
    // 0x80042978: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // 0x8004297C: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80042980: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042984: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042988: lhu         $v0, 0x14($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X14);
    // 0x8004298C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80042990: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
    // 0x80042994: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042998: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8004299C: lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X0);
    // 0x800429A0: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x800429A4: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800429A8: jr          $ra
    // 0x800429AC: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    return;
    // 0x800429AC: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_800429B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800429B0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800429B4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // FALLTHROUGH: func_800429B0 falls into func_800429B8
    func_800429B8(rdram, ctx);
;}
RECOMP_FUNC void func_800429B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800429B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800429BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800429C0: lw          $v0, 0x88($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X88);
    // 0x800429C4: beq         $v0, $zero, L_800429F0
    if (ctx->r2 == 0) {
        // 0x800429C8: lui         $v0, 0x2
        ctx->r2 = S32(0X2 << 16);
            goto L_800429F0;
    }
    // 0x800429C8: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x800429CC: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x800429D0: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800429D4: bne         $v0, $zero, L_800429EC
    if (ctx->r2 != 0) {
        // 0x800429D8: addiu       $v0, $zero, -0x1000
        ctx->r2 = ADD32(0, -0X1000);
            goto L_800429EC;
    }
    // 0x800429D8: addiu       $v0, $zero, -0x1000
    ctx->r2 = ADD32(0, -0X1000);
    // 0x800429DC: lui         $v0, 0xFFFE
    ctx->r2 = S32(0XFFFE << 16);
    // 0x800429E0: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800429E4: beq         $v0, $zero, L_800429F0
    if (ctx->r2 == 0) {
        // 0x800429E8: addiu       $v0, $zero, 0x1000
        ctx->r2 = ADD32(0, 0X1000);
            goto L_800429F0;
    }
    // 0x800429E8: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
L_800429EC:
    // 0x800429EC: sw          $v0, 0x88($v1)
    MEM_W(0X88, ctx->r3) = ctx->r2;
L_800429F0:
    // 0x800429F0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800429F4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800429F8: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x800429FC: lw          $a0, 0x88($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X88);
    // 0x80042A00: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80042A04: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80042A08: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042A0C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042A10: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x80042A14: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x80042A18: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80042A1C: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80042A20: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042A24: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042A28: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80042A2C: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x80042A30: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80042A34: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80042A38: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80042A3C: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80042A40: lw          $v0, 0x90($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X90);
    // 0x80042A44: bne         $v0, $zero, L_80042ACC
    if (ctx->r2 != 0) {
        // 0x80042A48: lui         $v1, 0x27
        ctx->r3 = S32(0X27 << 16);
            goto L_80042ACC;
    }
    // 0x80042A48: lui         $v1, 0x27
    ctx->r3 = S32(0X27 << 16);
    // 0x80042A4C: jal         0x80042B08
    // 0x80042A50: nop

    func_80042B08(rdram, ctx);
        goto after_0;
    // 0x80042A50: nop

    after_0:
    // 0x80042A54: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80042A58: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80042A5C: bne         $v0, $v1, L_80042AA4
    if (ctx->r2 != ctx->r3) {
        // 0x80042A60: nop
    
            goto L_80042AA4;
    }
    // 0x80042A60: nop

    // 0x80042A64: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042A68: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80042A6C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80042A70: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042A74: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80042A78: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
    // 0x80042A7C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042A80: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042A84: lui         $v0, 0xFFFE
    ctx->r2 = S32(0XFFFE << 16);
    // 0x80042A88: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80042A8C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042A90: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042A94: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x80042A98: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80042A9C: j           L_80042AF8
    // 0x80042AA0: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
        goto L_80042AF8;
    // 0x80042AA0: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
L_80042AA4:
    // 0x80042AA4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042AA8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042AAC: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x80042AB0: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80042AB4: bne         $v0, $zero, L_80042AF8
    if (ctx->r2 != 0) {
        // 0x80042AB8: nop
    
            goto L_80042AF8;
    }
    // 0x80042AB8: nop

    // 0x80042ABC: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x80042AC0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80042AC4: j           L_80042AF8
    // 0x80042AC8: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
        goto L_80042AF8;
    // 0x80042AC8: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
L_80042ACC:
    // 0x80042ACC: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x80042AD0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80042AD4: lw          $a0, 0x3A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3A0);
    // 0x80042AD8: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80042ADC: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80042AE0: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042AE4: beq         $v1, $zero, L_80042AF8
    if (ctx->r3 == 0) {
        // 0x80042AE8: nop
    
            goto L_80042AF8;
    }
    // 0x80042AE8: nop

    // 0x80042AEC: lw          $v0, 0x5C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X5C);
    // 0x80042AF0: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80042AF4: sw          $v0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r2;
L_80042AF8:
    // 0x80042AF8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80042AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80042B00: jr          $ra
    // 0x80042B04: nop

    return;
    // 0x80042B04: nop

;}
RECOMP_FUNC void func_80042B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042B08: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042B0C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80042B10: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80042B14: addiu       $a1, $a1, 0x46A8
    ctx->r5 = ADD32(ctx->r5, 0X46A8);
    // 0x80042B18: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x80042B1C: lh          $a0, 0x14($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X14);
    // 0x80042B20: lhu         $a3, 0x14($v0)
    ctx->r7 = MEM_HU(ctx->r2, 0X14);
    // 0x80042B24: lhu         $t1, 0x18($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X18);
    // 0x80042B28: slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80042B2C: bne         $v1, $zero, L_80042B40
    if (ctx->r3 != 0) {
                func_80042B30(rdram, ctx); return; // was goto L_80042B40
    }
;}
RECOMP_FUNC void func_80042B30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042B34: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042B38: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x80042B3C: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x80042B40: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80042B44: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80042B48: addiu       $t8, $t8, 0x3F94
    ctx->r24 = ADD32(ctx->r24, 0X3F94);
    // 0x80042B4C: addu        $t7, $a1, $zero
    ctx->r15 = ADD32(ctx->r5, 0);
    // 0x80042B50: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80042B54: addiu       $t6, $t6, 0x3294
    ctx->r14 = ADD32(ctx->r14, 0X3294);
    // 0x80042B58: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x80042B5C: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042B60: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x80042B64: sra         $t2, $v0, 16
    ctx->r10 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042B68: addiu       $t4, $zero, 0x57
    ctx->r12 = ADD32(0, 0X57);
    // 0x80042B6C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80042B70: addiu       $t5, $t5, 0x31C0
    ctx->r13 = ADD32(ctx->r13, 0X31C0);
    // 0x80042B74: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
L_80042B78:
    // 0x80042B78: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042B7C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80042B80: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80042B84: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80042B88: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80042B8C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80042B90: addu        $a1, $v1, $t8
    ctx->r5 = ADD32(ctx->r3, ctx->r24);
    // 0x80042B94: lhu         $v0, 0x58($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X58);
    // 0x80042B98: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80042B9C: beq         $v0, $zero, L_80042C4C
    if (ctx->r2 == 0) {
        // 0x80042BA0: addiu       $v0, $t0, -0x1
        ctx->r2 = ADD32(ctx->r8, -0X1);
            goto L_80042C4C;
    }
    // 0x80042BA0: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x80042BA4: lhu         $v0, 0xDC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XDC);
    // 0x80042BA8: beq         $v0, $zero, L_80042C4C
    if (ctx->r2 == 0) {
        // 0x80042BAC: addiu       $v0, $t0, -0x1
        ctx->r2 = ADD32(ctx->r8, -0X1);
            goto L_80042C4C;
    }
    // 0x80042BAC: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x80042BB0: lw          $a2, 0x68($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X68);
    // 0x80042BB4: lh          $v1, 0x14($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X14);
    // 0x80042BB8: lh          $v0, 0x0($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X0);
    // 0x80042BBC: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80042BC0: bne         $v0, $zero, L_80042BD0
    if (ctx->r2 != 0) {
        // 0x80042BC4: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80042BD0;
    }
    // 0x80042BC4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80042BC8: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
    // 0x80042BCC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_80042BD0:
    // 0x80042BD0: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80042BD4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042BD8: subu        $v0, $v0, $t3
    ctx->r2 = SUB32(ctx->r2, ctx->r11);
    // 0x80042BDC: bgez        $v0, L_80042BE8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80042BE0: subu        $v0, $a0, $a3
        ctx->r2 = SUB32(ctx->r4, ctx->r7);
            goto L_80042BE8;
    }
    // 0x80042BE0: subu        $v0, $a0, $a3
    ctx->r2 = SUB32(ctx->r4, ctx->r7);
    // 0x80042BE4: subu        $v0, $a3, $a0
    ctx->r2 = SUB32(ctx->r7, ctx->r4);
L_80042BE8:
    // 0x80042BE8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80042BEC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042BF0: slti        $v0, $v0, 0x11
    ctx->r2 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x80042BF4: beq         $v0, $zero, L_80042C4C
    if (ctx->r2 == 0) {
        // 0x80042BF8: addiu       $v0, $t0, -0x1
        ctx->r2 = ADD32(ctx->r8, -0X1);
            goto L_80042C4C;
    }
    // 0x80042BF8: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x80042BFC: lh          $v0, 0x18($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X18);
    // 0x80042C00: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80042C04: subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x80042C08: bgez        $v0, L_80042C14
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80042C0C: subu        $a0, $v1, $t1
        ctx->r4 = SUB32(ctx->r3, ctx->r9);
            goto L_80042C14;
    }
    // 0x80042C0C: subu        $a0, $v1, $t1
    ctx->r4 = SUB32(ctx->r3, ctx->r9);
    // 0x80042C10: subu        $a0, $t1, $v1
    ctx->r4 = SUB32(ctx->r9, ctx->r3);
L_80042C14:
    // 0x80042C14: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80042C18: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042C1C: slti        $v0, $v0, 0x40
    ctx->r2 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x80042C20: beq         $v0, $zero, L_80042C4C
    if (ctx->r2 == 0) {
        // 0x80042C24: addiu       $v0, $t0, -0x1
        ctx->r2 = ADD32(ctx->r8, -0X1);
            goto L_80042C4C;
    }
    // 0x80042C24: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x80042C28: sh          $t4, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r12;
    // 0x80042C2C: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x80042C30: sh          $zero, 0x1B0($a1)
    MEM_H(0X1B0, ctx->r5) = 0;
    // 0x80042C34: sw          $v0, 0x160($a1)
    MEM_W(0X160, ctx->r5) = ctx->r2;
    // 0x80042C38: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042C3C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042C40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80042C44: j           L_80042C60
    // 0x80042C48: sw          $a1, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r5;
        goto L_80042C60;
    // 0x80042C48: sw          $a1, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r5;
L_80042C4C:
    // 0x80042C4C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80042C50: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80042C54: bgtz        $v0, L_80042B78
    if (SIGNED(ctx->r2) > 0) {
        // 0x80042C58: sll         $v0, $t0, 16
        ctx->r2 = S32(ctx->r8 << 16);
            goto L_80042B78;
    }
    // 0x80042C58: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x80042C5C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80042C60:
    // 0x80042C60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80042C64: jr          $ra
    // 0x80042C68: nop

    return;
    // 0x80042C68: nop

;}
RECOMP_FUNC void func_80042C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042C6C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042C70: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80042C74: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x80042C78: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80042C7C: jr          $ra
    // 0x80042C80: sh          $v0, 0x5A($v1)
    MEM_H(0X5A, ctx->r3) = ctx->r2;
    return;
    // 0x80042C80: sh          $v0, 0x5A($v1)
    MEM_H(0X5A, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80042C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042C84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80042C88: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042C8C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80042C90: lui         $a0, 0x5
    ctx->r4 = S32(0X5 << 16);
    // 0x80042C94: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    // 0x80042C98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042C9C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80042CA0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80042CA4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80042CA8: lw          $s1, 0x90($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X90);
    // 0x80042CAC: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80042CB0: addiu       $s0, $s0, 0x31C0
    ctx->r16 = ADD32(ctx->r16, 0X31C0);
    // 0x80042CB4: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x80042CB8: jal         0x8003BA80
    // 0x80042CBC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8003BA80(rdram, ctx);
        goto after_0;
    // 0x80042CBC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_0:
    // 0x80042CC0: jal         0x800306EC
    // 0x80042CC4: nop

    func_800306EC(rdram, ctx);
        goto after_1;
    // 0x80042CC4: nop

    after_1:
    // 0x80042CC8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042CCC: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042CD0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80042CD4: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x80042CD8: lhu         $v1, 0x80($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X80);
    // 0x80042CDC: addiu       $v1, $v1, 0x100
    ctx->r3 = ADD32(ctx->r3, 0X100);
    // 0x80042CE0: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x80042CE4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042CE8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042CEC: lhu         $v1, 0x18($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X18);
    // 0x80042CF0: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x80042CF4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042CF8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042CFC: lhu         $a0, 0x14($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X14);
    // 0x80042D00: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80042D04: addiu       $v1, $v1, 0x10FC
    ctx->r3 = ADD32(ctx->r3, 0X10FC);
    // 0x80042D08: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x80042D0C: jal         0x80023E44
    // 0x80042D10: sh          $a0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r4;
    func_80023E44(rdram, ctx);
        goto after_2;
    // 0x80042D10: sh          $a0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r4;
    after_2:
    // 0x80042D14: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80042D18: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80042D1C: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80042D20: lhu         $v0, 0x22($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X22);
    // 0x80042D24: lhu         $v1, 0x22($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X22);
    // 0x80042D28: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80042D2C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80042D30: sh          $v1, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r3;
    // 0x80042D34: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80042D38: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80042D3C: bne         $v1, $v0, L_80042D48
    if (ctx->r3 != ctx->r2) {
        // 0x80042D40: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_80042D48;
    }
    // 0x80042D40: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80042D44: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
L_80042D48:
    // 0x80042D48: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042D4C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042D50: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x80042D54: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80042D58: beq         $v0, $zero, L_80042D6C
    if (ctx->r2 == 0) {
        // 0x80042D5C: nop
    
            goto L_80042D6C;
    }
    // 0x80042D5C: nop

    // 0x80042D60: lhu         $v0, 0x14($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X14);
    // 0x80042D64: j           L_80042D74
    // 0x80042D68: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
        goto L_80042D74;
    // 0x80042D68: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_80042D6C:
    // 0x80042D6C: lhu         $v0, 0x14($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X14);
    // 0x80042D70: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
L_80042D74:
    // 0x80042D74: jal         0x80043568
    // 0x80042D78: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
    func_80043568(rdram, ctx);
        goto after_3;
    // 0x80042D78: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
    after_3:
    // 0x80042D7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80042D80: sw          $s2, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r18;
    // 0x80042D84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80042D88: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80042D8C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80042D90: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80042D94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80042D98: jr          $ra
    // 0x80042D9C: nop

    return;
    // 0x80042D9C: nop

;}
RECOMP_FUNC void func_80042DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042DA0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80042DA4: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80042DA8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80042DAC: lh          $v0, 0x46A8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X46A8);
    // FALLTHROUGH: func_80042DA0 falls into func_80042DB0
    func_80042DB0(rdram, ctx);
;}
RECOMP_FUNC void func_80042DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042DB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80042DB4: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80042DB8: lh          $v1, 0x14($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X14);
    // 0x80042DBC: lhu         $a0, 0x14($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X14);
    // 0x80042DC0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80042DC4: bne         $v0, $zero, L_80042DD8
    if (ctx->r2 != 0) {
        // 0x80042DC8: addiu       $a2, $zero, 0x7
        ctx->r6 = ADD32(0, 0X7);
            goto L_80042DD8;
    }
    // 0x80042DC8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80042DCC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042DD0: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x80042DD4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_80042DD8:
    // 0x80042DD8: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80042DDC: addiu       $t4, $t4, 0x3F94
    ctx->r12 = ADD32(ctx->r12, 0X3F94);
    // 0x80042DE0: lhu         $v0, 0x32($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X32);
    // 0x80042DE4: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80042DE8: addiu       $t3, $t3, 0x3294
    ctx->r11 = ADD32(ctx->r11, 0X3294);
    // 0x80042DEC: addiu       $t2, $zero, 0x2B
    ctx->r10 = ADD32(0, 0X2B);
    // 0x80042DF0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80042DF4: sra         $v0, $v0, 17
    ctx->r2 = S32(SIGNED(ctx->r2) >> 17);
    // 0x80042DF8: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80042DFC: subu        $v0, $a0, $a3
    ctx->r2 = SUB32(ctx->r4, ctx->r7);
    // 0x80042E00: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80042E04: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042E08: addu        $v0, $a3, $a0
    ctx->r2 = ADD32(ctx->r7, ctx->r4);
    // 0x80042E0C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80042E10: sra         $t0, $v0, 16
    ctx->r8 = S32(SIGNED(ctx->r2) >> 16);
L_80042E14:
    // 0x80042E14: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042E18: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80042E1C: lw          $v1, 0x9C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C);
    // 0x80042E20: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x80042E24: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042E28: beq         $v1, $a0, L_80042EC4
    if (ctx->r3 == ctx->r4) {
        // 0x80042E2C: sll         $v0, $a0, 4
        ctx->r2 = S32(ctx->r4 << 4);
            goto L_80042EC4;
    }
    // 0x80042E2C: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80042E30: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80042E34: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80042E38: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80042E3C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80042E40: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    // 0x80042E44: lhu         $v0, 0x58($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X58);
    // 0x80042E48: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80042E4C: beq         $v0, $zero, L_80042EC8
    if (ctx->r2 == 0) {
        // 0x80042E50: addiu       $v0, $a2, -0x1
        ctx->r2 = ADD32(ctx->r6, -0X1);
            goto L_80042EC8;
    }
    // 0x80042E50: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x80042E54: lhu         $v0, 0xDC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XDC);
    // 0x80042E58: beq         $v0, $zero, L_80042EC8
    if (ctx->r2 == 0) {
        // 0x80042E5C: addiu       $v0, $a2, -0x1
        ctx->r2 = ADD32(ctx->r6, -0X1);
            goto L_80042EC8;
    }
    // 0x80042E5C: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x80042E60: lw          $a1, 0x68($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X68);
    // 0x80042E64: lh          $v0, 0x18($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X18);
    // 0x80042E68: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x80042E6C: bne         $v0, $zero, L_80042EC8
    if (ctx->r2 != 0) {
        // 0x80042E70: addiu       $v0, $a2, -0x1
        ctx->r2 = ADD32(ctx->r6, -0X1);
            goto L_80042EC8;
    }
    // 0x80042E70: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x80042E74: lh          $v0, 0x14($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X14);
    // 0x80042E78: lhu         $v1, 0x14($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X14);
    // 0x80042E7C: slt         $v0, $a3, $v0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042E80: bne         $v0, $zero, L_80042E94
    if (ctx->r2 != 0) {
        // 0x80042E84: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_80042E94;
    }
    // 0x80042E84: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80042E88: lhu         $v0, 0x0($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X0);
    // 0x80042E8C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80042E90: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
L_80042E94:
    // 0x80042E94: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042E98: slt         $v1, $v0, $t1
    ctx->r3 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80042E9C: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80042EA0: slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042EA4: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80042EA8: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80042EAC: beq         $v1, $zero, L_80042EC8
    if (ctx->r3 == 0) {
        // 0x80042EB0: addiu       $v0, $a2, -0x1
        ctx->r2 = ADD32(ctx->r6, -0X1);
            goto L_80042EC8;
    }
    // 0x80042EB0: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x80042EB4: sh          $t2, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r10;
    // 0x80042EB8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042EBC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80042EC0: sw          $a1, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r5;
L_80042EC4:
    // 0x80042EC4: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
L_80042EC8:
    // 0x80042EC8: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80042ECC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80042ED0: bgtz        $v0, L_80042E14
    if (SIGNED(ctx->r2) > 0) {
        // 0x80042ED4: nop
    
            goto L_80042E14;
    }
    // 0x80042ED4: nop

    // 0x80042ED8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042EDC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80042EE0: lw          $v0, 0x9C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X9C);
    // 0x80042EE4: beq         $v0, $zero, L_80042F0C
    if (ctx->r2 == 0) {
        // 0x80042EE8: sll         $a0, $v0, 4
        ctx->r4 = S32(ctx->r2 << 4);
            goto L_80042F0C;
    }
    // 0x80042EE8: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x80042EEC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80042EF0: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80042EF4: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80042EF8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80042EFC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80042F00: addiu       $v0, $v0, 0x3F94
    ctx->r2 = ADD32(ctx->r2, 0X3F94);
    // 0x80042F04: jal         0x8000A2EC
    // 0x80042F08: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    func_8000A2EC(rdram, ctx);
        goto after_0;
    // 0x80042F08: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_0:
L_80042F0C:
    // 0x80042F0C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80042F10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80042F14: jr          $ra
    // 0x80042F18: nop

    return;
    // 0x80042F18: nop

;}
RECOMP_FUNC void func_80042F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042F1C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042F20: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // FALLTHROUGH: func_80042F1C falls into func_80042F24
    func_80042F24(rdram, ctx);
;}
RECOMP_FUNC void func_80042F24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042F24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80042F28: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80042F2C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80042F30: addiu       $s0, $s0, 0x31C0
    ctx->r16 = ADD32(ctx->r16, 0X31C0);
    // 0x80042F34: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80042F38: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80042F3C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80042F40: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x80042F44: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80042F48: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80042F4C: lw          $v1, 0x90($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X90);
    // 0x80042F50: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80042F54: sw          $zero, 0x100($v1)
    MEM_W(0X100, ctx->r3) = 0;
    // 0x80042F58: jal         0x800306EC
    // 0x80042F5C: sw          $zero, 0x104($v1)
    MEM_W(0X104, ctx->r3) = 0;
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80042F5C: sw          $zero, 0x104($v1)
    MEM_W(0X104, ctx->r3) = 0;
    after_0:
    // 0x80042F60: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042F64: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042F68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80042F6C: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x80042F70: lhu         $v1, 0x80($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X80);
    // 0x80042F74: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80042F78: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x80042F7C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042F80: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042F84: lhu         $v1, 0x18($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X18);
    // 0x80042F88: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x80042F8C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042F90: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80042F94: lhu         $a0, 0x14($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X14);
    // 0x80042F98: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80042F9C: addiu       $v1, $v1, 0x10FC
    ctx->r3 = ADD32(ctx->r3, 0X10FC);
    // 0x80042FA0: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x80042FA4: jal         0x80023E44
    // 0x80042FA8: sh          $a0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r4;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x80042FA8: sh          $a0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r4;
    after_1:
    // 0x80042FAC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80042FB0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80042FB4: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80042FB8: lhu         $v0, 0x22($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X22);
    // 0x80042FBC: lhu         $v1, 0x22($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X22);
    // 0x80042FC0: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80042FC4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80042FC8: sh          $v1, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r3;
    // 0x80042FCC: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    // 0x80042FD0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80042FD4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80042FD8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80042FDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80042FE0: jr          $ra
    // 0x80042FE4: nop

    return;
    // 0x80042FE4: nop

;}
RECOMP_FUNC void func_80042FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042FE8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80042FEC: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // FALLTHROUGH: func_80042FE8 falls into func_80042FF0
    func_80042FF0(rdram, ctx);
;}
RECOMP_FUNC void func_80042FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042FF8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80042FFC: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80043000: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x80043004: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80043008: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8004300C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80043010: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80043014: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043018: lw          $v1, 0x3294($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3294);
    // 0x8004301C: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80043020: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80043024: jal         0x8004314C
    // 0x80043028: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    func_8004314C(rdram, ctx);
        goto after_0;
    // 0x80043028: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    after_0:
    // 0x8004302C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043030: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043034: lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X98);
    // 0x80043038: bne         $v0, $zero, L_800430D0
    if (ctx->r2 != 0) {
        // 0x8004303C: nop
    
            goto L_800430D0;
    }
    // 0x8004303C: nop

    // 0x80043040: lw          $v0, 0x9C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X9C);
    // 0x80043044: lh          $a0, 0x14($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X14);
    // 0x80043048: lh          $a1, 0x18($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X18);
    // 0x8004304C: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80043050: addiu       $s0, $s0, 0x3F94
    ctx->r16 = ADD32(ctx->r16, 0X3F94);
    // 0x80043054: sll         $a2, $v0, 4
    ctx->r6 = S32(ctx->r2 << 4);
    // 0x80043058: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8004305C: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x80043060: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x80043064: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80043068: jal         0x80009C20
    // 0x8004306C: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    func_80009C20(rdram, ctx);
        goto after_1;
    // 0x8004306C: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    after_1:
    // 0x80043070: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80043074: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043078: lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X98);
    // 0x8004307C: bne         $v0, $zero, L_800430D0
    if (ctx->r2 != 0) {
        // 0x80043080: nop
    
            goto L_800430D0;
    }
    // 0x80043080: nop

    // 0x80043084: lw          $v0, 0x9C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X9C);
    // 0x80043088: lh          $a0, 0x14($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X14);
    // 0x8004308C: lh          $a1, 0x18($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X18);
    // 0x80043090: sll         $a2, $v0, 4
    ctx->r6 = S32(ctx->r2 << 4);
    // 0x80043094: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80043098: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x8004309C: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800430A0: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x800430A4: jal         0x80029908
    // 0x800430A8: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    func_80029908(rdram, ctx);
        goto after_2;
    // 0x800430A8: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    after_2:
    // 0x800430AC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800430B0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800430B4: lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X98);
    // 0x800430B8: bne         $v0, $zero, L_800430D0
    if (ctx->r2 != 0) {
        // 0x800430BC: nop
    
            goto L_800430D0;
    }
    // 0x800430BC: nop

    // 0x800430C0: lhu         $v0, 0x8C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X8C);
    // 0x800430C4: beq         $v0, $zero, L_800430D0
    if (ctx->r2 == 0) {
        // 0x800430C8: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800430D0;
    }
    // 0x800430C8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800430CC: sh          $v0, 0x8C($v1)
    MEM_H(0X8C, ctx->r3) = ctx->r2;
L_800430D0:
    // 0x800430D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800430D4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800430D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800430DC: jr          $ra
    // 0x800430E0: nop

    return;
    // 0x800430E0: nop

;}
RECOMP_FUNC void func_800430E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800430E4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800430E8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800430EC: lhu         $v0, 0x8C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X8C);
    // 0x800430F0: beq         $v0, $zero, L_80043110
    if (ctx->r2 == 0) {
        // 0x800430F4: nop
    
            goto L_80043110;
    }
    // 0x800430F4: nop

    // 0x800430F8: lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X98);
    // 0x800430FC: bne         $v0, $zero, L_80043110
    if (ctx->r2 != 0) {
        // 0x80043100: nop
    
            goto L_80043110;
    }
    // 0x80043100: nop

    // 0x80043104: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x80043108: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8004310C: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
L_80043110:
    // 0x80043110: jr          $ra
    // 0x80043114: nop

    return;
    // 0x80043114: nop

;}
RECOMP_FUNC void func_80043118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043118: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004311C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80043120: lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X98);
    // 0x80043124: bne         $v0, $zero, L_80043144
    if (ctx->r2 != 0) {
        // 0x80043128: nop
    
            goto L_80043144;
    }
    // 0x80043128: nop

    // 0x8004312C: lhu         $v0, 0x8C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X8C);
    // 0x80043130: bne         $v0, $zero, L_80043144
    if (ctx->r2 != 0) {
        // 0x80043134: nop
    
            goto L_80043144;
    }
    // 0x80043134: nop

    // 0x80043138: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x8004313C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80043140: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
L_80043144:
    // 0x80043144: jr          $ra
    // 0x80043148: nop

    return;
    // 0x80043148: nop

;}
RECOMP_FUNC void func_8004314C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004314C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043150: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_80043154
    func_80043154(rdram, ctx);
}
