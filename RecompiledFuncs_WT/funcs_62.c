#include "recomp.h"
#include "funcs.h"
#include <stdio.h>


RECOMP_FUNC void func_80062B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80062B44: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80062B48: addiu       $t1, $t1, 0x5986
    ctx->r9 = ADD32(ctx->r9, 0X5986);
    // 0x80062B4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80062B50: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80062B54: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_80062B58:
    // 0x80062B58: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x80062B5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80062B60: beq         $v1, $zero, L_80062BB4
    if (ctx->r3 == 0) {
        // 0x80062B64: lui         $a3, 0x8008
        ctx->r7 = S32(0X8008 << 16);
            goto L_80062BB4;
    }
    // 0x80062B64: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80062B68: addiu       $a3, $a3, 0x5920
    ctx->r7 = ADD32(ctx->r7, 0X5920);
L_80062B6C:
    // 0x80062B6C: lbu         $t6, 0x1($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X1);
    // 0x80062B70: nop

    // 0x80062B74: bne         $v1, $t6, L_80062B88
    if (ctx->r3 != ctx->r14) {
        // 0x80062B78: nop
    
            goto L_80062B88;
    }
    // 0x80062B78: nop

    // 0x80062B7C: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x80062B80: b           L_80062B94
    // 0x80062B84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80062B94;
    // 0x80062B84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80062B88:
    // 0x80062B88: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80062B8C: bne         $a3, $t1, L_80062B6C
    if (ctx->r7 != ctx->r9) {
        // 0x80062B90: nop
    
            goto L_80062B6C;
    }
    // 0x80062B90: nop

L_80062B94:
    // 0x80062B94: bne         $a0, $zero, L_80062BA0
    if (ctx->r4 != 0) {
        // 0x80062B98: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80062BA0;
    }
    // 0x80062B98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80062B9C: addiu       $v1, $zero, 0x2A
    ctx->r3 = ADD32(0, 0X2A);
L_80062BA0:
    // 0x80062BA0: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80062BA4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80062BA8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80062BAC: bne         $at, $zero, L_80062B58
    if (ctx->r1 != 0) {
        // 0x80062BB0: sb          $v1, -0x1($t0)
        MEM_B(-0X1, ctx->r8) = ctx->r3;
            goto L_80062B58;
    }
    // 0x80062BB0: sb          $v1, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r3;
L_80062BB4:
    // 0x80062BB4: jr          $ra
    // 0x80062BB8: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    return;
    // 0x80062BB8: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
;}
RECOMP_FUNC void func_80062BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80062BBC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80062BC0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80062BC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80062BC8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_80062BCC:
    // 0x80062BCC: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80062BD0: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x80062BD4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80062BD8: beq         $t6, $t7, L_80062BE8
    if (ctx->r14 == ctx->r15) {
        // 0x80062BDC: nop
    
            goto L_80062BE8;
    }
    // 0x80062BDC: nop

    // 0x80062BE0: jr          $ra
    // 0x80062BE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80062BE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80062BE8:
    // 0x80062BE8: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x80062BEC: lbu         $t9, 0x1($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X1);
    // 0x80062BF0: nop

    // 0x80062BF4: beq         $t8, $t9, L_80062C04
    if (ctx->r24 == ctx->r25) {
        // 0x80062BF8: nop
    
            goto L_80062C04;
    }
    // 0x80062BF8: nop

    // 0x80062BFC: jr          $ra
    // 0x80062C00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80062C00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80062C04:
    // 0x80062C04: lbu         $t0, 0x2($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X2);
    // 0x80062C08: lbu         $t1, 0x2($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X2);
    // 0x80062C0C: nop

    // 0x80062C10: beq         $t0, $t1, L_80062C20
    if (ctx->r8 == ctx->r9) {
        // 0x80062C14: nop
    
            goto L_80062C20;
    }
    // 0x80062C14: nop

    // 0x80062C18: jr          $ra
    // 0x80062C1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80062C1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80062C20:
    // 0x80062C20: lbu         $t2, 0x3($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X3);
    // 0x80062C24: lbu         $t3, 0x3($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X3);
    // 0x80062C28: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80062C2C: beq         $t2, $t3, L_80062C3C
    if (ctx->r10 == ctx->r11) {
        // 0x80062C30: nop
    
            goto L_80062C3C;
    }
    // 0x80062C30: nop

    // 0x80062C34: jr          $ra
    // 0x80062C38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80062C38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80062C3C:
    // 0x80062C3C: bne         $v0, $a0, L_80062BCC
    if (ctx->r2 != ctx->r4) {
        // 0x80062C40: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80062BCC;
    }
    // 0x80062C40: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80062C44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80062C48: jr          $ra
    // 0x80062C4C: nop

    return;
    // 0x80062C4C: nop

;}
RECOMP_FUNC void func_80062C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80062C50: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80062C54: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80062C58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80062C5C:
    // 0x80062C5C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80062C60: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80062C64: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80062C68: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80062C6C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80062C70: bne         $v0, $a0, L_80062C5C
    if (ctx->r2 != ctx->r4) {
        // 0x80062C74: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_80062C5C;
    }
    // 0x80062C74: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x80062C78: jr          $ra
    // 0x80062C7C: nop

    return;
    // 0x80062C7C: nop

;}
RECOMP_FUNC void func_80062C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80062C80: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80062C84: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80062C88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80062C8C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_80062C90:
    // 0x80062C90: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x80062C94: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80062C98: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x80062C9C: lbu         $t7, 0x1($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X1);
    // 0x80062CA0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80062CA4: sb          $t7, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r15;
    // 0x80062CA8: lbu         $t8, 0x2($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X2);
    // 0x80062CAC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80062CB0: sb          $t8, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r24;
    // 0x80062CB4: lbu         $t9, -0x1($a2)
    ctx->r25 = MEM_BU(ctx->r6, -0X1);
    // 0x80062CB8: bne         $v0, $a0, L_80062C90
    if (ctx->r2 != ctx->r4) {
        // 0x80062CBC: sb          $t9, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r25;
            goto L_80062C90;
    }
    // 0x80062CBC: sb          $t9, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r25;
    // 0x80062CC0: jr          $ra
    // 0x80062CC4: nop

    return;
    // 0x80062CC4: nop

;}
RECOMP_FUNC void func_80062CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80062CC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80062CCC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80062CD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80062CD4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80062CD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80062CDC: bne         $a0, $at, L_80062CEC
    if (ctx->r4 != ctx->r1) {
        // 0x80062CE0: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80062CEC;
    }
    // 0x80062CE0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80062CE4: b           L_80062E00
    // 0x80062CE8: addiu       $v0, $zero, 0x12D
    ctx->r2 = ADD32(0, 0X12D);
        goto L_80062E00;
    // 0x80062CE8: addiu       $v0, $zero, 0x12D
    ctx->r2 = ADD32(0, 0X12D);
L_80062CEC:
    // 0x80062CEC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80062CF0: lbu         $t6, -0x31B0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X31B0);
    // 0x80062CF4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80062CF8: sllv        $t8, $t7, $s1
    ctx->r24 = S32(ctx->r15 << (ctx->r17 & 31));
    // 0x80062CFC: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x80062D00: bne         $t9, $zero, L_80062D10
    if (ctx->r25 != 0) {
        // 0x80062D04: sll         $t0, $s1, 3
        ctx->r8 = S32(ctx->r17 << 3);
            goto L_80062D10;
    }
    // 0x80062D04: sll         $t0, $s1, 3
    ctx->r8 = S32(ctx->r17 << 3);
    // 0x80062D08: b           L_80062E00
    // 0x80062D0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80062E00;
    // 0x80062D0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80062D10:
    // 0x80062D10: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x80062D14: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80062D18: addiu       $t1, $t1, -0x3198
    ctx->r9 = ADD32(ctx->r9, -0X3198);
    // 0x80062D1C: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80062D20: addu        $s0, $t0, $t1
    ctx->r16 = ADD32(ctx->r8, ctx->r9);
    // 0x80062D24: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80062D28: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80062D2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80062D30: sb          $t2, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r10;
    // 0x80062D34: addiu       $a0, $a0, 0x2860
    ctx->r4 = ADD32(ctx->r4, 0X2860);
    // 0x80062D38: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80062D3C: jal         0x8006B5A0
    // 0x80062D40: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    osPfsInitPak_recomp(rdram, ctx);
        goto after_0;
    // 0x80062D40: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
    // 0x80062D44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80062D48: bne         $v0, $at, L_80062D80
    if (ctx->r2 != ctx->r1) {
        // 0x80062D4C: sw          $v0, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->r2;
            goto L_80062D80;
    }
    // 0x80062D4C: sw          $v0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r2;
    // 0x80062D50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80062D54: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80062D58: addiu       $a0, $a0, 0x2860
    ctx->r4 = ADD32(ctx->r4, 0X2860);
    // 0x80062D5C: jal         0x8006B5A0
    // 0x80062D60: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    osPfsInitPak_recomp(rdram, ctx);
        goto after_1;
    // 0x80062D60: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x80062D64: sw          $v0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r2;
    // 0x80062D68: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x80062D6C: jal         0x80062BBC
    // 0x80062D70: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    func_80062BBC(rdram, ctx);
        goto after_2;
    // 0x80062D70: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    after_2:
    // 0x80062D74: bne         $v0, $zero, L_80062D80
    if (ctx->r2 != 0) {
        // 0x80062D78: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_80062D80;
    }
    // 0x80062D78: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80062D7C: sw          $t3, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r11;
L_80062D80:
    // 0x80062D80: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x80062D84: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x80062D88: bne         $v1, $zero, L_80062DA4
    if (ctx->r3 != 0) {
        // 0x80062D8C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80062DA4;
    }
    // 0x80062D8C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80062D90: jal         0x80062C80
    // 0x80062D94: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    func_80062C80(rdram, ctx);
        goto after_3;
    // 0x80062D94: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    after_3:
    // 0x80062D98: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x80062D9C: nop

    // 0x80062DA0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_80062DA4:
    // 0x80062DA4: bne         $v1, $at, L_80062DF4
    if (ctx->r3 != ctx->r1) {
        // 0x80062DA8: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80062DF4;
    }
    // 0x80062DA8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80062DAC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80062DB0: addiu       $a0, $a0, 0x2860
    ctx->r4 = ADD32(ctx->r4, 0X2860);
    // 0x80062DB4: jal         0x8006BC60
    // 0x80062DB8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_4;
    // 0x80062DB8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_4:
    // 0x80062DBC: beq         $v0, $zero, L_80062DCC
    if (ctx->r2 == 0) {
        // 0x80062DC0: addiu       $t4, $zero, 0x12E
        ctx->r12 = ADD32(0, 0X12E);
            goto L_80062DCC;
    }
    // 0x80062DC0: addiu       $t4, $zero, 0x12E
    ctx->r12 = ADD32(0, 0X12E);
    // 0x80062DC4: b           L_80062DD8
    // 0x80062DC8: sw          $t4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r12;
        goto L_80062DD8;
    // 0x80062DC8: sw          $t4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r12;
L_80062DCC:
    // 0x80062DCC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80062DD0: jal         0x8006B810
    // 0x80062DD4: nop

    osMotorStop_recomp(rdram, ctx);
        goto after_5;
    // 0x80062DD4: nop

    after_5:
L_80062DD8:
    // 0x80062DD8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80062DDC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80062DE0: addiu       $a0, $a0, 0x2860
    ctx->r4 = ADD32(ctx->r4, 0X2860);
    // 0x80062DE4: jal         0x8006B5A0
    // 0x80062DE8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    osPfsInitPak_recomp(rdram, ctx);
        goto after_6;
    // 0x80062DE8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_6:
    // 0x80062DEC: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x80062DF0: nop

L_80062DF4:
    // 0x80062DF4: sltiu       $t5, $v1, 0x1
    ctx->r13 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80062DF8: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x80062DFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80062E00:
    // 0x80062E00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80062E04: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80062E08: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80062E0C: jr          $ra
    // 0x80062E10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80062E10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80062E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80062E14: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80062E18: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80062E1C: lui         $s5, 0x8011
    ctx->r21 = S32(0X8011 << 16);
    // 0x80062E20: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80062E24: addiu       $s5, $s5, -0x31B0
    ctx->r21 = ADD32(ctx->r21, -0X31B0);
    // 0x80062E28: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80062E2C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80062E30: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80062E34: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80062E38: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80062E3C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80062E40: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80062E44: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80062E48: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80062E4C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80062E50: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80062E54: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80062E58: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80062E5C: addiu       $a0, $a0, 0x2860
    ctx->r4 = ADD32(ctx->r4, 0X2860);
    // 0x80062E60: jal         0x8006BE30
    // 0x80062E64: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_0;
    // 0x80062E64: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_0:
    // 0x80062E68: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80062E6C: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x80062E70: addiu       $s2, $s2, -0x3128
    ctx->r18 = ADD32(ctx->r18, -0X3128);
    // 0x80062E74: addiu       $s0, $s0, -0x3198
    ctx->r16 = ADD32(ctx->r16, -0X3198);
    // 0x80062E78: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80062E7C: addiu       $s7, $zero, 0x12E
    ctx->r23 = ADD32(0, 0X12E);
    // 0x80062E80: addiu       $s6, $zero, 0xB
    ctx->r22 = ADD32(0, 0XB);
    // 0x80062E84: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_80062E88:
    // 0x80062E88: jal         0x80062C50
    // 0x80062E8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80062C50(rdram, ctx);
        goto after_1;
    // 0x80062E8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80062E90: lbu         $t6, 0x0($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X0);
    // 0x80062E94: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80062E98: sllv        $t8, $t7, $s1
    ctx->r24 = S32(ctx->r15 << (ctx->r17 & 31));
    // 0x80062E9C: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x80062EA0: beq         $t9, $zero, L_80062ED8
    if (ctx->r25 == 0) {
        // 0x80062EA4: nop
    
            goto L_80062ED8;
    }
    // 0x80062EA4: nop

    // 0x80062EA8: jal         0x80062CC8
    // 0x80062EAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80062CC8(rdram, ctx);
        goto after_2;
    // 0x80062EAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80062EB0: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80062EB4: nop

    // 0x80062EB8: beq         $v0, $s3, L_80062ED0
    if (ctx->r2 == ctx->r19) {
        // 0x80062EBC: nop
    
            goto L_80062ED0;
    }
    // 0x80062EBC: nop

    // 0x80062EC0: beq         $v0, $s6, L_80062ED0
    if (ctx->r2 == ctx->r22) {
        // 0x80062EC4: nop
    
            goto L_80062ED0;
    }
    // 0x80062EC4: nop

    // 0x80062EC8: bne         $v0, $s7, L_80062EE4
    if (ctx->r2 != ctx->r23) {
        // 0x80062ECC: nop
    
            goto L_80062EE4;
    }
    // 0x80062ECC: nop

L_80062ED0:
    // 0x80062ED0: b           L_80062EE4
    // 0x80062ED4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
        goto L_80062EE4;
    // 0x80062ED4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_80062ED8:
    // 0x80062ED8: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80062EDC: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x80062EE0: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
L_80062EE4:
    // 0x80062EE4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80062EE8: addiu       $s0, $s0, 0x90
    ctx->r16 = ADD32(ctx->r16, 0X90);
    // 0x80062EEC: bne         $s1, $s3, L_80062E88
    if (ctx->r17 != ctx->r19) {
        // 0x80062EF0: addiu       $s2, $s2, 0x90
        ctx->r18 = ADD32(ctx->r18, 0X90);
            goto L_80062E88;
    }
    // 0x80062EF0: addiu       $s2, $s2, 0x90
    ctx->r18 = ADD32(ctx->r18, 0X90);
    // 0x80062EF4: lhu         $t0, 0x3E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3E);
    // 0x80062EF8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80062EFC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80062F00: sh          $t0, -0x31AE($at)
    MEM_H(-0X31AE, ctx->r1) = ctx->r8;
    // 0x80062F04: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80062F08: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80062F0C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80062F10: addiu       $a1, $a1, -0x31A8
    ctx->r5 = ADD32(ctx->r5, -0X31A8);
    // 0x80062F14: jal         0x80062A50
    // 0x80062F18: sw          $t1, -0x31AC($at)
    MEM_W(-0X31AC, ctx->r1) = ctx->r9;
    func_80062A50(rdram, ctx);
        goto after_3;
    // 0x80062F18: sw          $t1, -0x31AC($at)
    MEM_W(-0X31AC, ctx->r1) = ctx->r9;
    after_3:
    // 0x80062F1C: beq         $s4, $zero, L_80062F2C
    if (ctx->r20 == 0) {
        // 0x80062F20: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80062F2C;
    }
    // 0x80062F20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80062F24: b           L_80062F2C
    // 0x80062F28: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
        goto L_80062F2C;
    // 0x80062F28: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_80062F2C:
    // 0x80062F2C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80062F30: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80062F34: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80062F38: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80062F3C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80062F40: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80062F44: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80062F48: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80062F4C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80062F50: jr          $ra
    // 0x80062F54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80062F54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80062F58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80062F58: jr          $ra
    // 0x80062F5C: nop

    return;
    // 0x80062F5C: nop

;}
RECOMP_FUNC void func_80062F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80062F60: slti        $v0, $a0, 0x0
    ctx->r2 = SIGNED(ctx->r4) < 0X0 ? 1 : 0;
    // 0x80062F64: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80062F68: beq         $v0, $zero, L_80062F90
    if (ctx->r2 == 0) {
        // 0x80062F6C: sll         $t6, $a0, 3
        ctx->r14 = S32(ctx->r4 << 3);
            goto L_80062F90;
    }
    // 0x80062F6C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80062F70: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80062F74: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80062F78: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80062F7C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80062F80: lbu         $v0, -0x3198($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3198);
    // 0x80062F84: nop

    // 0x80062F88: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80062F8C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80062F90:
    // 0x80062F90: jr          $ra
    // 0x80062F94: nop

    return;
    // 0x80062F94: nop

;}
RECOMP_FUNC void func_80062F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80062F98: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80062F9C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80062FA0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80062FA4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80062FA8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80062FAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80062FB0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80062FB4: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80062FB8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80062FBC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80062FC0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80062FC4: sw          $s3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r19;
    // 0x80062FC8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80062FCC: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
L_80062FD0:
    // 0x80062FD0: jal         0x80062F60
    // 0x80062FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80062F60(rdram, ctx);
        goto after_0;
    // 0x80062FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80062FD8: beq         $v0, $zero, L_80063004
    if (ctx->r2 == 0) {
        // 0x80062FDC: nop
    
            goto L_80063004;
    }
    // 0x80062FDC: nop

    // 0x80062FE0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80062FE4: nop

    // 0x80062FE8: bne         $s3, $t6, L_80062FF4
    if (ctx->r19 != ctx->r14) {
        // 0x80062FEC: nop
    
            goto L_80062FF4;
    }
    // 0x80062FEC: nop

    // 0x80062FF0: sw          $s0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r16;
L_80062FF4:
    // 0x80062FF4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80062FF8: nop

    // 0x80062FFC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80063000: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
L_80063004:
    // 0x80063004: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80063008: bne         $s0, $s4, L_80062FD0
    if (ctx->r16 != ctx->r20) {
        // 0x8006300C: nop
    
            goto L_80062FD0;
    }
    // 0x8006300C: nop

    // 0x80063010: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80063014: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80063018: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006301C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80063020: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80063024: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80063028: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006302C: jr          $ra
    // 0x80063030: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80063030: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80063034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063034: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80063038: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006303C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063040: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80063044: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80063048: bne         $a0, $at, L_80063058
    if (ctx->r4 != ctx->r1) {
        // 0x8006304C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80063058;
    }
    // 0x8006304C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80063050: b           L_8006317C
    // 0x80063054: addiu       $v0, $zero, 0x12D
    ctx->r2 = ADD32(0, 0X12D);
        goto L_8006317C;
    // 0x80063054: addiu       $v0, $zero, 0x12D
    ctx->r2 = ADD32(0, 0X12D);
L_80063058:
    // 0x80063058: bltz        $a3, L_80063080
    if (SIGNED(ctx->r7) < 0) {
        // 0x8006305C: sll         $t6, $a3, 3
        ctx->r14 = S32(ctx->r7 << 3);
            goto L_80063080;
    }
    // 0x8006305C: sll         $t6, $a3, 3
    ctx->r14 = S32(ctx->r7 << 3);
    // 0x80063060: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x80063064: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80063068: addiu       $t7, $t7, -0x3198
    ctx->r15 = ADD32(ctx->r15, -0X3198);
    // 0x8006306C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80063070: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80063074: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80063078: nop

    // 0x8006307C: bne         $t8, $zero, L_800630D4
    if (ctx->r24 != 0) {
        // 0x80063080: sll         $t9, $a3, 3
        ctx->r25 = S32(ctx->r7 << 3);
            goto L_800630D4;
    }
L_80063080:
    // 0x80063080: sll         $t9, $a3, 3
    ctx->r25 = S32(ctx->r7 << 3);
    // 0x80063084: addu        $t9, $t9, $a3
    ctx->r25 = ADD32(ctx->r25, ctx->r7);
    // 0x80063088: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x8006308C: addiu       $t0, $t0, -0x3198
    ctx->r8 = ADD32(ctx->r8, -0X3198);
    // 0x80063090: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80063094: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x80063098: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8006309C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800630A0: jal         0x80062CC8
    // 0x800630A4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80062CC8(rdram, ctx);
        goto after_0;
    // 0x800630A4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x800630A8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800630AC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800630B0: bltz        $a3, L_800630C8
    if (SIGNED(ctx->r7) < 0) {
        // 0x800630B4: nop
    
            goto L_800630C8;
    }
    // 0x800630B4: nop

    // 0x800630B8: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x800630BC: nop

    // 0x800630C0: bne         $t1, $zero, L_800630D8
    if (ctx->r9 != 0) {
        // 0x800630C4: addiu       $a0, $v1, 0x4
        ctx->r4 = ADD32(ctx->r3, 0X4);
            goto L_800630D8;
    }
    // 0x800630C4: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
L_800630C8:
    // 0x800630C8: lw          $v0, 0x6C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6C);
    // 0x800630CC: b           L_80063180
    // 0x800630D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80063180;
    // 0x800630D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800630D4:
    // 0x800630D4: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
L_800630D8:
    // 0x800630D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800630DC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800630E0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800630E4: jal         0x8006C1A0
    // 0x800630E8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_1;
    // 0x800630E8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_1:
    // 0x800630EC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800630F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800630F4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800630F8: beq         $v0, $zero, L_8006313C
    if (ctx->r2 == 0) {
        // 0x800630FC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8006313C;
    }
    // 0x800630FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80063100: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80063104: bne         $v0, $at, L_80063134
    if (ctx->r2 != ctx->r1) {
        // 0x80063108: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80063134;
    }
    // 0x80063108: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8006310C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80063110: jal         0x80062CC8
    // 0x80063114: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80062CC8(rdram, ctx);
        goto after_2;
    // 0x80063114: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80063118: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8006311C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80063120: lw          $a0, 0x6C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X6C);
    // 0x80063124: nop

    // 0x80063128: beq         $a0, $zero, L_80063134
    if (ctx->r4 == 0) {
        // 0x8006312C: nop
    
            goto L_80063134;
    }
    // 0x8006312C: nop

    // 0x80063130: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_80063134:
    // 0x80063134: b           L_8006317C
    // 0x80063138: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8006317C;
    // 0x80063138: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8006313C:
    // 0x8006313C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80063140: jal         0x8006C2F0
    // 0x80063144: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_3;
    // 0x80063144: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x80063148: beq         $v0, $zero, L_8006315C
    if (ctx->r2 == 0) {
        // 0x8006314C: lw          $t2, 0x2C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X2C);
            goto L_8006315C;
    }
    // 0x8006314C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80063150: b           L_80063180
    // 0x80063154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80063180;
    // 0x80063154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063158: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_8006315C:
    // 0x8006315C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80063160: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80063164: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80063168: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8006316C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80063170: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80063174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80063178: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_8006317C:
    // 0x8006317C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80063180:
    // 0x80063180: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80063184: jr          $ra
    // 0x80063188: nop

    return;
    // 0x80063188: nop

;}
RECOMP_FUNC void func_8006318C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006318C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80063190: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80063194: lw          $t6, 0x5988($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5988);
    // 0x80063198: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006319C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800631A0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800631A4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800631A8: bne         $a0, $at, L_800631B8
    if (ctx->r4 != ctx->r1) {
        // 0x800631AC: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_800631B8;
    }
    // 0x800631AC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800631B0: b           L_80063274
    // 0x800631B4: addiu       $v0, $zero, 0x12D
    ctx->r2 = ADD32(0, 0X12D);
        goto L_80063274;
    // 0x800631B4: addiu       $v0, $zero, 0x12D
    ctx->r2 = ADD32(0, 0X12D);
L_800631B8:
    // 0x800631B8: bltz        $a0, L_800631E0
    if (SIGNED(ctx->r4) < 0) {
        // 0x800631BC: sll         $t7, $a0, 3
        ctx->r15 = S32(ctx->r4 << 3);
            goto L_800631E0;
    }
    // 0x800631BC: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800631C0: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800631C4: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800631C8: addiu       $t8, $t8, -0x3198
    ctx->r24 = ADD32(ctx->r24, -0X3198);
    // 0x800631CC: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800631D0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800631D4: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800631D8: nop

    // 0x800631DC: bne         $t9, $zero, L_80063234
    if (ctx->r25 != 0) {
        // 0x800631E0: sll         $t0, $a0, 3
        ctx->r8 = S32(ctx->r4 << 3);
            goto L_80063234;
    }
L_800631E0:
    // 0x800631E0: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x800631E4: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x800631E8: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800631EC: addiu       $t1, $t1, -0x3198
    ctx->r9 = ADD32(ctx->r9, -0X3198);
    // 0x800631F0: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x800631F4: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x800631F8: jal         0x80062CC8
    // 0x800631FC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80062CC8(rdram, ctx);
        goto after_0;
    // 0x800631FC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x80063200: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80063204: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x80063208: addiu       $t2, $t2, -0x3198
    ctx->r10 = ADD32(ctx->r10, -0X3198);
    // 0x8006320C: sltu        $at, $v1, $t2
    ctx->r1 = ctx->r3 < ctx->r10 ? 1 : 0;
    // 0x80063210: bne         $at, $zero, L_80063228
    if (ctx->r1 != 0) {
        // 0x80063214: nop
    
            goto L_80063228;
    }
    // 0x80063214: nop

    // 0x80063218: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x8006321C: nop

    // 0x80063220: bne         $t3, $zero, L_80063234
    if (ctx->r11 != 0) {
        // 0x80063224: nop
    
            goto L_80063234;
    }
    // 0x80063224: nop

L_80063228:
    // 0x80063228: lw          $v0, 0x6C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6C);
    // 0x8006322C: b           L_80063278
    // 0x80063230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80063278;
    // 0x80063230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80063234:
    // 0x80063234: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80063238: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8006323C: lw          $a2, -0x31AC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X31AC);
    // 0x80063240: lhu         $a1, -0x31AE($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X31AE);
    // 0x80063244: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80063248: addiu       $t4, $sp, 0x2C
    ctx->r12 = ADD32(ctx->r29, 0X2C);
    // 0x8006324C: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x80063250: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80063254: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80063258: addiu       $a3, $a3, -0x31A8
    ctx->r7 = ADD32(ctx->r7, -0X31A8);
    // 0x8006325C: jal         0x8006C440
    // 0x80063260: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    osPfsFindFile_recomp(rdram, ctx);
        goto after_1;
    // 0x80063260: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    after_1:
    // 0x80063264: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80063268: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8006326C: nop

    // 0x80063270: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_80063274:
    // 0x80063274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80063278:
    // 0x80063278: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006327C: jr          $ra
    // 0x80063280: nop

    return;
    // 0x80063280: nop

;}
RECOMP_FUNC void func_80063284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063284: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80063288: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8006328C: lw          $t6, 0x598C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X598C);
    // 0x80063290: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80063294: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80063298: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8006329C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800632A0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800632A4: bne         $a0, $at, L_800632B4
    if (ctx->r4 != ctx->r1) {
        // 0x800632A8: sw          $t6, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r14;
            goto L_800632B4;
    }
    // 0x800632A8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x800632AC: b           L_800633E8
    // 0x800632B0: addiu       $v0, $zero, 0x12D
    ctx->r2 = ADD32(0, 0X12D);
        goto L_800633E8;
    // 0x800632B0: addiu       $v0, $zero, 0x12D
    ctx->r2 = ADD32(0, 0X12D);
L_800632B4:
    // 0x800632B4: bltz        $a0, L_800632DC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800632B8: sll         $t7, $a0, 3
        ctx->r15 = S32(ctx->r4 << 3);
            goto L_800632DC;
    }
    // 0x800632B8: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800632BC: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800632C0: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800632C4: addiu       $t8, $t8, -0x3198
    ctx->r24 = ADD32(ctx->r24, -0X3198);
    // 0x800632C8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800632CC: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800632D0: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800632D4: nop

    // 0x800632D8: bne         $t9, $zero, L_80063330
    if (ctx->r25 != 0) {
        // 0x800632DC: sll         $t0, $a0, 3
        ctx->r8 = S32(ctx->r4 << 3);
            goto L_80063330;
    }
L_800632DC:
    // 0x800632DC: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x800632E0: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x800632E4: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800632E8: addiu       $t1, $t1, -0x3198
    ctx->r9 = ADD32(ctx->r9, -0X3198);
    // 0x800632EC: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x800632F0: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x800632F4: jal         0x80062CC8
    // 0x800632F8: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_80062CC8(rdram, ctx);
        goto after_0;
    // 0x800632F8: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_0:
    // 0x800632FC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80063300: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x80063304: addiu       $t2, $t2, -0x3198
    ctx->r10 = ADD32(ctx->r10, -0X3198);
    // 0x80063308: sltu        $at, $v1, $t2
    ctx->r1 = ctx->r3 < ctx->r10 ? 1 : 0;
    // 0x8006330C: bne         $at, $zero, L_80063324
    if (ctx->r1 != 0) {
        // 0x80063310: nop
    
            goto L_80063324;
    }
    // 0x80063310: nop

    // 0x80063314: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x80063318: nop

    // 0x8006331C: bne         $t3, $zero, L_80063334
    if (ctx->r11 != 0) {
        // 0x80063320: lw          $t4, 0x48($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X48);
            goto L_80063334;
    }
    // 0x80063320: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
L_80063324:
    // 0x80063324: lw          $v0, 0x6C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6C);
    // 0x80063328: b           L_800633EC
    // 0x8006332C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800633EC;
    // 0x8006332C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80063330:
    // 0x80063330: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
L_80063334:
    // 0x80063334: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x80063338: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8006333C: beq         $t5, $zero, L_80063360
    if (ctx->r13 == 0) {
        // 0x80063340: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_80063360;
    }
    // 0x80063340: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80063344: addiu       $t6, $t4, 0xFF
    ctx->r14 = ADD32(ctx->r12, 0XFF);
    // 0x80063348: bgez        $t6, L_80063358
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006334C: sra         $t7, $t6, 8
        ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
            goto L_80063358;
    }
    // 0x8006334C: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80063350: addiu       $at, $t6, 0xFF
    ctx->r1 = ADD32(ctx->r14, 0XFF);
    // 0x80063354: sra         $t7, $at, 8
    ctx->r15 = S32(SIGNED(ctx->r1) >> 8);
L_80063358:
    // 0x80063358: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8006335C: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
L_80063360:
    // 0x80063360: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80063364: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80063368: lw          $a2, -0x31AC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X31AC);
    // 0x8006336C: lhu         $a1, -0x31AE($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X31AE);
    // 0x80063370: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80063374: addiu       $t9, $sp, 0x3C
    ctx->r25 = ADD32(ctx->r29, 0X3C);
    // 0x80063378: addiu       $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x8006337C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80063380: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80063384: addiu       $a3, $a3, -0x31A8
    ctx->r7 = ADD32(ctx->r7, -0X31A8);
    // 0x80063388: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8006338C: jal         0x8006C600
    // 0x80063390: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    osPfsAllocateFile_recomp(rdram, ctx);
        goto after_1;
    // 0x80063390: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_1:
    // 0x80063394: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80063398: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8006339C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800633A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800633A4: bne         $v0, $zero, L_800633E4
    if (ctx->r2 != 0) {
        // 0x800633A8: sw          $t2, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r10;
            goto L_800633E4;
    }
    // 0x800633A8: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800633AC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800633B0: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800633B4: lw          $a2, -0x31AC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X31AC);
    // 0x800633B8: lhu         $a1, -0x31AE($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X31AE);
    // 0x800633BC: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800633C0: addiu       $t5, $sp, 0x3C
    ctx->r13 = ADD32(ctx->r29, 0X3C);
    // 0x800633C4: addiu       $t4, $sp, 0x38
    ctx->r12 = ADD32(ctx->r29, 0X38);
    // 0x800633C8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800633CC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800633D0: jal         0x8006C440
    // 0x800633D4: addiu       $a3, $a3, -0x31A8
    ctx->r7 = ADD32(ctx->r7, -0X31A8);
    osPfsFindFile_recomp(rdram, ctx);
        goto after_2;
    // 0x800633D4: addiu       $a3, $a3, -0x31A8
    ctx->r7 = ADD32(ctx->r7, -0X31A8);
    after_2:
    // 0x800633D8: beq         $v0, $zero, L_800633E4
    if (ctx->r2 == 0) {
        // 0x800633DC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800633E4;
    }
    // 0x800633DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800633E0: addiu       $v1, $zero, 0x12E
    ctx->r3 = ADD32(0, 0X12E);
L_800633E4:
    // 0x800633E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800633E8:
    // 0x800633E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800633EC:
    // 0x800633EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800633F0: jr          $ra
    // 0x800633F4: nop

    return;
    // 0x800633F4: nop

;}
RECOMP_FUNC void func_800633F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800633F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800633FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80063400: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80063404: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80063408: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8006340C: bne         $a0, $at, L_8006341C
    if (ctx->r4 != ctx->r1) {
        // 0x80063410: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_8006341C;
    }
    // 0x80063410: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80063414: b           L_800634BC
    // 0x80063418: addiu       $v0, $zero, 0x12D
    ctx->r2 = ADD32(0, 0X12D);
        goto L_800634BC;
    // 0x80063418: addiu       $v0, $zero, 0x12D
    ctx->r2 = ADD32(0, 0X12D);
L_8006341C:
    // 0x8006341C: bltz        $a0, L_80063444
    if (SIGNED(ctx->r4) < 0) {
        // 0x80063420: sll         $t6, $a0, 3
        ctx->r14 = S32(ctx->r4 << 3);
            goto L_80063444;
    }
    // 0x80063420: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80063424: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80063428: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8006342C: addiu       $t7, $t7, -0x3198
    ctx->r15 = ADD32(ctx->r15, -0X3198);
    // 0x80063430: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80063434: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80063438: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8006343C: nop

    // 0x80063440: bne         $t8, $zero, L_80063498
    if (ctx->r24 != 0) {
        // 0x80063444: sll         $t9, $a0, 3
        ctx->r25 = S32(ctx->r4 << 3);
            goto L_80063498;
    }
L_80063444:
    // 0x80063444: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x80063448: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8006344C: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80063450: addiu       $t0, $t0, -0x3198
    ctx->r8 = ADD32(ctx->r8, -0X3198);
    // 0x80063454: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80063458: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x8006345C: jal         0x80062CC8
    // 0x80063460: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80062CC8(rdram, ctx);
        goto after_0;
    // 0x80063460: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x80063464: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80063468: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8006346C: addiu       $t1, $t1, -0x3198
    ctx->r9 = ADD32(ctx->r9, -0X3198);
    // 0x80063470: sltu        $at, $v1, $t1
    ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
    // 0x80063474: bne         $at, $zero, L_8006348C
    if (ctx->r1 != 0) {
        // 0x80063478: nop
    
            goto L_8006348C;
    }
    // 0x80063478: nop

    // 0x8006347C: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x80063480: nop

    // 0x80063484: bne         $t2, $zero, L_8006349C
    if (ctx->r10 != 0) {
        // 0x80063488: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_8006349C;
    }
    // 0x80063488: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_8006348C:
    // 0x8006348C: lw          $v0, 0x6C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6C);
    // 0x80063490: b           L_800634C0
    // 0x80063494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800634C0;
    // 0x80063494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80063498:
    // 0x80063498: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_8006349C:
    // 0x8006349C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800634A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800634A4: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x800634A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800634AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800634B0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800634B4: jal         0x8006CEAC
    // 0x800634B8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_1;
    // 0x800634B8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_1:
L_800634BC:
    // 0x800634BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800634C0:
    // 0x800634C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800634C4: jr          $ra
    // 0x800634C8: nop

    return;
    // 0x800634C8: nop

;}
RECOMP_FUNC void func_800634CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800634CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800634D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800634D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800634D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800634DC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800634E0: bne         $a0, $at, L_800634F0
    if (ctx->r4 != ctx->r1) {
        // 0x800634E4: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_800634F0;
    }
    // 0x800634E4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800634E8: b           L_80063590
    // 0x800634EC: addiu       $v0, $zero, 0x12D
    ctx->r2 = ADD32(0, 0X12D);
        goto L_80063590;
    // 0x800634EC: addiu       $v0, $zero, 0x12D
    ctx->r2 = ADD32(0, 0X12D);
L_800634F0:
    // 0x800634F0: bltz        $a0, L_80063518
    if (SIGNED(ctx->r4) < 0) {
        // 0x800634F4: sll         $t6, $a0, 3
        ctx->r14 = S32(ctx->r4 << 3);
            goto L_80063518;
    }
    // 0x800634F4: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800634F8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800634FC: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80063500: addiu       $t7, $t7, -0x3198
    ctx->r15 = ADD32(ctx->r15, -0X3198);
    // 0x80063504: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80063508: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8006350C: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80063510: nop

    // 0x80063514: bne         $t8, $zero, L_8006356C
    if (ctx->r24 != 0) {
        // 0x80063518: sll         $t9, $a0, 3
        ctx->r25 = S32(ctx->r4 << 3);
            goto L_8006356C;
    }
L_80063518:
    // 0x80063518: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8006351C: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x80063520: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80063524: addiu       $t0, $t0, -0x3198
    ctx->r8 = ADD32(ctx->r8, -0X3198);
    // 0x80063528: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8006352C: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x80063530: jal         0x80062CC8
    // 0x80063534: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80062CC8(rdram, ctx);
        goto after_0;
    // 0x80063534: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x80063538: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8006353C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80063540: addiu       $t1, $t1, -0x3198
    ctx->r9 = ADD32(ctx->r9, -0X3198);
    // 0x80063544: sltu        $at, $v1, $t1
    ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
    // 0x80063548: bne         $at, $zero, L_80063560
    if (ctx->r1 != 0) {
        // 0x8006354C: nop
    
            goto L_80063560;
    }
    // 0x8006354C: nop

    // 0x80063550: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x80063554: nop

    // 0x80063558: bne         $t2, $zero, L_80063570
    if (ctx->r10 != 0) {
        // 0x8006355C: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_80063570;
    }
    // 0x8006355C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_80063560:
    // 0x80063560: lw          $v0, 0x6C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6C);
    // 0x80063564: b           L_80063594
    // 0x80063568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80063594;
    // 0x80063568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006356C:
    // 0x8006356C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_80063570:
    // 0x80063570: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80063574: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80063578: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x8006357C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80063580: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80063584: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80063588: jal         0x8006CEAC
    // 0x8006358C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_1;
    // 0x8006358C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_1:
L_80063590:
    // 0x80063590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80063594:
    // 0x80063594: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80063598: jr          $ra
    // 0x8006359C: nop

    return;
    // 0x8006359C: nop

;}
RECOMP_FUNC void func_800635A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800635A0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800635A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800635A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800635AC: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800635B0: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800635B4: bne         $a0, $at, L_800635C4
    if (ctx->r4 != ctx->r1) {
        // 0x800635B8: sw          $a3, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r7;
            goto L_800635C4;
    }
    // 0x800635B8: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800635BC: b           L_800636E8
    // 0x800635C0: addiu       $v0, $zero, 0x12D
    ctx->r2 = ADD32(0, 0X12D);
        goto L_800636E8;
    // 0x800635C0: addiu       $v0, $zero, 0x12D
    ctx->r2 = ADD32(0, 0X12D);
L_800635C4:
    // 0x800635C4: bltz        $a0, L_800635EC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800635C8: sll         $t6, $a0, 3
        ctx->r14 = S32(ctx->r4 << 3);
            goto L_800635EC;
    }
    // 0x800635C8: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800635CC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800635D0: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800635D4: addiu       $t7, $t7, -0x3198
    ctx->r15 = ADD32(ctx->r15, -0X3198);
    // 0x800635D8: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800635DC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800635E0: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x800635E4: nop

    // 0x800635E8: bne         $t8, $zero, L_80063640
    if (ctx->r24 != 0) {
        // 0x800635EC: sll         $t9, $a0, 3
        ctx->r25 = S32(ctx->r4 << 3);
            goto L_80063640;
    }
L_800635EC:
    // 0x800635EC: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x800635F0: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800635F4: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800635F8: addiu       $t0, $t0, -0x3198
    ctx->r8 = ADD32(ctx->r8, -0X3198);
    // 0x800635FC: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80063600: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x80063604: jal         0x80062CC8
    // 0x80063608: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_80062CC8(rdram, ctx);
        goto after_0;
    // 0x80063608: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x8006360C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80063610: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80063614: addiu       $t1, $t1, -0x3198
    ctx->r9 = ADD32(ctx->r9, -0X3198);
    // 0x80063618: sltu        $at, $v1, $t1
    ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
    // 0x8006361C: bne         $at, $zero, L_80063634
    if (ctx->r1 != 0) {
        // 0x80063620: nop
    
            goto L_80063634;
    }
    // 0x80063620: nop

    // 0x80063624: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x80063628: nop

    // 0x8006362C: bne         $t2, $zero, L_80063644
    if (ctx->r10 != 0) {
        // 0x80063630: lw          $t3, 0x60($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X60);
            goto L_80063644;
    }
    // 0x80063630: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
L_80063634:
    // 0x80063634: lw          $v0, 0x6C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6C);
    // 0x80063638: b           L_800636EC
    // 0x8006363C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800636EC;
    // 0x8006363C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80063640:
    // 0x80063640: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
L_80063644:
    // 0x80063644: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x80063648: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8006364C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80063650: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80063654: jal         0x8006D2B0
    // 0x80063658: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    osPfsFileState_recomp(rdram, ctx);
        goto after_1;
    // 0x80063658: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_1:
    // 0x8006365C: beq         $v0, $zero, L_80063670
    if (ctx->r2 == 0) {
        // 0x80063660: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80063670;
    }
    // 0x80063660: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80063664: b           L_800636EC
    // 0x80063668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800636EC;
    // 0x80063668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006366C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80063670:
    // 0x80063670: jal         0x80065364
    // 0x80063674: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80065364(rdram, ctx);
        goto after_2;
    // 0x80063674: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_2:
    // 0x80063678: bne         $v0, $zero, L_80063688
    if (ctx->r2 != 0) {
        // 0x8006367C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80063688;
    }
    // 0x8006367C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80063680: b           L_800636E8
    // 0x80063684: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
        goto L_800636E8;
    // 0x80063684: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
L_80063688:
    // 0x80063688: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8006368C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80063690: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80063694: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80063698: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006369C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800636A0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800636A4: jal         0x8006CEAC
    // 0x800636A8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_3;
    // 0x800636A8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x800636AC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800636B0: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x800636B4: nop

    // 0x800636B8: sw          $a0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r4;
    // 0x800636BC: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800636C0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800636C4: beq         $v0, $zero, L_800636E4
    if (ctx->r2 == 0) {
        // 0x800636C8: sw          $t6, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->r14;
            goto L_800636E4;
    }
    // 0x800636C8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800636CC: jal         0x800653C4
    // 0x800636D0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800653C4(rdram, ctx);
        goto after_4;
    // 0x800636D0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_4:
    // 0x800636D4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800636D8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800636DC: b           L_800636E8
    // 0x800636E0: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
        goto L_800636E8;
    // 0x800636E0: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_800636E4:
    // 0x800636E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800636E8:
    // 0x800636E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800636EC:
    // 0x800636EC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800636F0: jr          $ra
    // 0x800636F4: nop

    return;
    // 0x800636F4: nop

;}
RECOMP_FUNC void func_800636F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800636F8: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800636FC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    ctx->hi = hi; ctx->lo = lo;
    func_80063700(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_80063700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063704: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80063708: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8006370C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063710: addiu       $t8, $t8, -0x3198
    ctx->r24 = ADD32(ctx->r24, -0X3198);
    // 0x80063714: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x80063718: jal         0x8006D5A0
    // 0x8006371C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    __osGetId_recomp(rdram, ctx);
        goto after_0;
    // 0x8006371C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80063720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063724: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063728: jr          $ra
    // 0x8006372C: nop

    return;
    // 0x8006372C: nop

;}
RECOMP_FUNC void func_80063730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063730: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80063734: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80063738: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006373C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80063740: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x80063744: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80063748: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006374C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80063750: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80063754: addiu       $s3, $s3, -0x3198
    ctx->r19 = ADD32(ctx->r19, -0X3198);
    // 0x80063758: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006375C: addiu       $s4, $zero, 0x90
    ctx->r20 = ADD32(0, 0X90);
L_80063760:
    // 0x80063760: bltz        $s0, L_800637A0
    if (SIGNED(ctx->r16) < 0) {
        // 0x80063764: nop
    
            goto L_800637A0;
    }
    // 0x80063764: nop

    // 0x80063768: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006376C: mflo        $t6
    ctx->r14 = lo;
    // 0x80063770: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x80063774: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80063778: nop

    // 0x8006377C: beq         $t8, $zero, L_800637A0
    if (ctx->r24 == 0) {
        // 0x80063780: nop
    
            goto L_800637A0;
    }
    // 0x80063780: nop

    // 0x80063784: sw          $s0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r16;
    // 0x80063788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006378C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80063790: jal         0x80063034
    // 0x80063794: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_80063034(rdram, ctx);
        goto after_0;
    // 0x80063794: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80063798: b           L_80063870
    // 0x8006379C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80063870;
    // 0x8006379C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800637A0:
    // 0x800637A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800637A4: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x800637A8: bne         $at, $zero, L_80063760
    if (ctx->r1 != 0) {
        // 0x800637AC: nop
    
            goto L_80063760;
    }
    // 0x800637AC: nop

    // 0x800637B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800637B4: addiu       $v0, $v0, -0x3198
    ctx->r2 = ADD32(ctx->r2, -0X3198);
    // 0x800637B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800637BC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800637C0:
    // 0x800637C0: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x800637C4: nop

    // 0x800637C8: beq         $t9, $zero, L_800637EC
    if (ctx->r25 == 0) {
        // 0x800637CC: nop
    
            goto L_800637EC;
    }
    // 0x800637CC: nop

    // 0x800637D0: lw          $t0, 0x6C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X6C);
    // 0x800637D4: nop

    // 0x800637D8: beq         $s1, $t0, L_800637EC
    if (ctx->r17 == ctx->r8) {
        // 0x800637DC: nop
    
            goto L_800637EC;
    }
    // 0x800637DC: nop

    // 0x800637E0: sw          $s0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r16;
    // 0x800637E4: b           L_8006386C
    // 0x800637E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006386C;
    // 0x800637E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800637EC:
    // 0x800637EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800637F0: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x800637F4: bne         $at, $zero, L_800637C0
    if (ctx->r1 != 0) {
        // 0x800637F8: addiu       $v0, $v0, 0x90
        ctx->r2 = ADD32(ctx->r2, 0X90);
            goto L_800637C0;
    }
    // 0x800637F8: addiu       $v0, $v0, 0x90
    ctx->r2 = ADD32(ctx->r2, 0X90);
    // 0x800637FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80063800: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80063804: addiu       $a1, $a1, -0x31B0
    ctx->r5 = ADD32(ctx->r5, -0X31B0);
    // 0x80063808: addiu       $a0, $a0, 0x2860
    ctx->r4 = ADD32(ctx->r4, 0X2860);
    // 0x8006380C: jal         0x8006BE30
    // 0x80063810: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_1;
    // 0x80063810: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    after_1:
    // 0x80063814: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80063818: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_8006381C:
    // 0x8006381C: jal         0x80062CC8
    // 0x80063820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80062CC8(rdram, ctx);
        goto after_2;
    // 0x80063820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80063824: beq         $v0, $s1, L_80063850
    if (ctx->r2 == ctx->r17) {
        // 0x80063828: nop
    
            goto L_80063850;
    }
    // 0x80063828: nop

    // 0x8006382C: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063830: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80063834: nop

    // 0x80063838: sw          $s0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r16;
    // 0x8006383C: mflo        $t2
    ctx->r10 = lo;
    // 0x80063840: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x80063844: lw          $v0, 0x6C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X6C);
    // 0x80063848: b           L_80063870
    // 0x8006384C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80063870;
    // 0x8006384C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80063850:
    // 0x80063850: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80063854: bne         $s0, $s2, L_8006381C
    if (ctx->r16 != ctx->r18) {
        // 0x80063858: nop
    
            goto L_8006381C;
    }
    // 0x80063858: nop

    // 0x8006385C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80063860: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80063864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80063868: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
L_8006386C:
    // 0x8006386C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80063870:
    // 0x80063870: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80063874: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80063878: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006387C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80063880: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80063884: jr          $ra
    // 0x80063888: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80063888: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8006388C: nop

;}
RECOMP_FUNC void func_80063890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063890: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80063894: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80063898: addiu       $a0, $a0, 0x5990
    ctx->r4 = ADD32(ctx->r4, 0X5990);
    ctx->hi = hi; ctx->lo = lo;
    func_8006389C(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_8006389C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8006389C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800638A0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800638A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800638A8: addiu       $t6, $t6, 0xB10
    ctx->r14 = ADD32(ctx->r14, 0XB10);
    // 0x800638AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800638B0: sh          $a3, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r7;
    // 0x800638B4: sh          $a1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r5;
    // 0x800638B8: jal         0x800010A4
    // 0x800638BC: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    func_800010A4(rdram, ctx);
        goto after_0;
    // 0x800638BC: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    after_0:
    // 0x800638C0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800638C4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800638C8: jal         0x80000ADC
    // 0x800638CC: sw          $t7, -0x1C4($at)
    MEM_W(-0X1C4, ctx->r1) = ctx->r15;
    func_80000ADC(rdram, ctx);
        goto after_1;
    // 0x800638CC: sw          $t7, -0x1C4($at)
    MEM_W(-0X1C4, ctx->r1) = ctx->r15;
    after_1:
    // 0x800638D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800638D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800638D8: jr          $ra
    // 0x800638DC: nop

    return;
    // 0x800638DC: nop

;}
RECOMP_FUNC void func_800638E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800638E0: bne         $a0, $zero, L_800638FC
    if (ctx->r4 != 0) {
            // 0x800638E4: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    func_800638FC(rdram, ctx);
    return;
    }
    // 0x800638E4: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x800638E8: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x800638EC: addiu       $t6, $t6, 0x7380
    ctx->r14 = ADD32(ctx->r14, 0X7380);
    // 0x800638F0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800638F4: jr          $ra
    // 0x800638F8: sw          $t6, 0x5990($at)
    MEM_W(0X5990, ctx->r1) = ctx->r14;
    return;
    // 0x800638F8: sw          $t6, 0x5990($at)
    MEM_W(0X5990, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_800638FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800638FC: addiu       $t7, $t7, 0x7080
    ctx->r15 = ADD32(ctx->r15, 0X7080);
    // 0x80063900: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80063904: sw          $t7, 0x5990($at)
    MEM_W(0X5990, ctx->r1) = ctx->r15;
    // 0x80063908: jr          $ra
    // 0x8006390C: nop

    return;
    // 0x8006390C: nop

;}
RECOMP_FUNC void func_80063910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063910: bne         $a0, $zero, L_80063928
    if (ctx->r4 != 0) {
            // 0x80063914: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    func_80063928(rdram, ctx);
    return;
    }
    // 0x80063914: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80063918: addiu       $t6, $zero, 0x53
    ctx->r14 = ADD32(0, 0X53);
    // 0x8006391C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80063920: jr          $ra
    // 0x80063924: sw          $t6, 0x599C($at)
    MEM_W(0X599C, ctx->r1) = ctx->r14;
    return;
    // 0x80063924: sw          $t6, 0x599C($at)
    MEM_W(0X599C, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80063928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063928: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006392C: bne         $a0, $at, L_80063944
    if (ctx->r4 != ctx->r1) {
            // 0x80063930: addiu       $t8, $zero, 0x16A
    ctx->r24 = ADD32(0, 0X16A);
    func_80063944(rdram, ctx);
    return;
    }
    // 0x80063930: addiu       $t8, $zero, 0x16A
    ctx->r24 = ADD32(0, 0X16A);
    // 0x80063934: addiu       $t7, $zero, 0x164
    ctx->r15 = ADD32(0, 0X164);
    // 0x80063938: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8006393C: jr          $ra
    // 0x80063940: sw          $t7, 0x599C($at)
    MEM_W(0X599C, ctx->r1) = ctx->r15;
    return;
    // 0x80063940: sw          $t7, 0x599C($at)
    MEM_W(0X599C, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_80063944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063944: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80063948: sw          $t8, 0x599C($at)
    MEM_W(0X599C, ctx->r1) = ctx->r24;
    // 0x8006394C: jr          $ra
    // 0x80063950: nop

    return;
    // 0x80063950: nop

;}
RECOMP_FUNC void func_80063968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006396C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80063970: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80063974: lw          $t6, 0x59A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X59A8);
    // 0x80063978: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8006397C: addiu       $a0, $a0, 0x5990
    ctx->r4 = ADD32(ctx->r4, 0X5990);
    // 0x80063980: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80063984: sh          $t6, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r14;
    // 0x80063988: lw          $t7, 0x59AC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X59AC);
    // 0x8006398C: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80063990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063994: addiu       $t8, $t8, 0xB50
    ctx->r24 = ADD32(ctx->r24, 0XB50);
    // 0x80063998: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x8006399C: jal         0x800010A4
    // 0x800639A0: sh          $t7, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r15;
    func_800010A4(rdram, ctx);
        goto after_0;
    // 0x800639A0: sh          $t7, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r15;
    after_0:
    // 0x800639A4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800639A8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800639AC: jal         0x80000ADC
    // 0x800639B0: sw          $t9, -0x1C4($at)
    MEM_W(-0X1C4, ctx->r1) = ctx->r25;
    func_80000ADC(rdram, ctx);
        goto after_1;
    // 0x800639B0: sw          $t9, -0x1C4($at)
    MEM_W(-0X1C4, ctx->r1) = ctx->r25;
    after_1:
    // 0x800639B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800639B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800639BC: jr          $ra
    // 0x800639C0: nop

    return;
    // 0x800639C0: nop

;}
RECOMP_FUNC void func_800639C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800639C4: jr          $ra
    // 0x800639C8: nop

    return;
    // 0x800639C8: nop

;}
RECOMP_FUNC void func_800639CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800639CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800639D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800639D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800639D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800639DC: jal         0x80061E34
    // 0x800639E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80061E34(rdram, ctx);
        goto after_0;
    // 0x800639E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800639E4: jal         0x8002F674
    // 0x800639E8: addiu       $a0, $zero, 0x600
    ctx->r4 = ADD32(0, 0X600);
    func_8002F674(rdram, ctx);
        goto after_1;
    // 0x800639E8: addiu       $a0, $zero, 0x600
    ctx->r4 = ADD32(0, 0X600);
    after_1:
    // 0x800639EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800639F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800639F4: jr          $ra
    // 0x800639F8: nop

    return;
    // 0x800639F8: nop

;}
RECOMP_FUNC void func_800639FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800639FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063A04: jal         0x800639CC
    // 0x80063A08: nop

    func_800639CC(rdram, ctx);
        goto after_0;
    // 0x80063A08: nop

    after_0:
    // 0x80063A0C: jal         0x800638E0
    // 0x80063A10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800638E0(rdram, ctx);
        goto after_1;
    // 0x80063A10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80063A14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80063A18: jal         0x80063910
    // 0x80063A1C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_80063910(rdram, ctx);
        goto after_2;
    // 0x80063A1C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_2:
    // 0x80063A20: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x80063A24: addiu       $a2, $a2, -0x2610
    ctx->r6 = ADD32(ctx->r6, -0X2610);
    // 0x80063A28: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80063A2C: jal         0x80063890
    // 0x80063A30: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    func_80063890(rdram, ctx);
        goto after_3;
    // 0x80063A30: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_3:
    // 0x80063A34: jal         0x8002E840
    // 0x80063A38: nop

    func_8002E840(rdram, ctx);
        goto after_4;
    // 0x80063A38: nop

    after_4:
    // 0x80063A3C: jal         0x80003004
    // 0x80063A40: nop

    func_80003004(rdram, ctx);
        goto after_5;
    // 0x80063A40: nop

    after_5:
L_80063A44:
    // 0x80063A44: b           L_80063A44
    pause_self(rdram);
    // 0x80063A48: nop

    // 0x80063A4C: nop

    // 0x80063A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063A54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063A58: jr          $ra
    // 0x80063A5C: nop

    return;
    // 0x80063A5C: nop

;}
RECOMP_FUNC void func_80063A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063A60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80063A64: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80063A68: lw          $t7, 0x59B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X59B4);
    // 0x80063A6C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80063A70: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x80063A74: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80063A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063A7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80063A80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80063A84: beq         $t7, $zero, L_80063B1C
    if (ctx->r15 == 0) {
        // 0x80063A88: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80063B1C;
    }
    // 0x80063A88: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80063A8C: lbu         $t8, 0x18($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X18);
    // 0x80063A90: lbu         $t2, 0x23($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X23);
    // 0x80063A94: andi        $t9, $t8, 0xFF0F
    ctx->r25 = ctx->r24 & 0XFF0F;
    // 0x80063A98: ori         $t4, $t9, 0x10
    ctx->r12 = ctx->r25 | 0X10;
    // 0x80063A9C: andi        $t5, $t4, 0xF0
    ctx->r13 = ctx->r12 & 0XF0;
    // 0x80063AA0: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x80063AA4: lbu         $t7, 0x19($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X19);
    // 0x80063AA8: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80063AAC: lbu         $t5, 0x2B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2B);
    // 0x80063AB0: sb          $t4, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r12;
    // 0x80063AB4: lhu         $t9, 0x1A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X1A);
    // 0x80063AB8: sb          $t6, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r14;
    // 0x80063ABC: sll         $t1, $a3, 6
    ctx->r9 = S32(ctx->r7 << 6);
    // 0x80063AC0: andi        $t0, $t7, 0xFF7F
    ctx->r8 = ctx->r15 & 0XFF7F;
    // 0x80063AC4: andi        $t2, $t1, 0x40
    ctx->r10 = ctx->r9 & 0X40;
    // 0x80063AC8: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80063ACC: andi        $t4, $t0, 0xBF
    ctx->r12 = ctx->r8 & 0XBF;
    // 0x80063AD0: andi        $t7, $t6, 0x3FF0
    ctx->r15 = ctx->r14 & 0X3FF0;
    // 0x80063AD4: andi        $t1, $t9, 0xC00F
    ctx->r9 = ctx->r25 & 0XC00F;
    // 0x80063AD8: sb          $t0, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r8;
    // 0x80063ADC: or          $t3, $t2, $t4
    ctx->r11 = ctx->r10 | ctx->r12;
    // 0x80063AE0: or          $t8, $t7, $t1
    ctx->r24 = ctx->r15 | ctx->r9;
    // 0x80063AE4: sb          $t3, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r11;
    // 0x80063AE8: sh          $t8, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r24;
    // 0x80063AEC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80063AF0: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x80063AF4: srl         $t4, $t2, 14
    ctx->r12 = S32(U32(ctx->r10) >> 14);
    // 0x80063AF8: xor         $t3, $t0, $t4
    ctx->r11 = ctx->r8 ^ ctx->r12;
    // 0x80063AFC: sll         $t5, $t3, 24
    ctx->r13 = S32(ctx->r11 << 24);
    // 0x80063B00: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x80063B04: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80063B08: xor         $a1, $t6, $t2
    ctx->r5 = ctx->r14 ^ ctx->r10;
    // 0x80063B0C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80063B10: addiu       $a0, $a0, -0x2F20
    ctx->r4 = ADD32(ctx->r4, -0X2F20);
    // 0x80063B14: jal         0x8006A090
    // 0x80063B18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80063B18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_80063B1C:
    // 0x80063B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063B20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80063B24: jr          $ra
    // 0x80063B28: nop

    return;
    // 0x80063B28: nop

;}
RECOMP_FUNC void func_80063B2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063B2C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80063B30: lw          $t6, 0x59B4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X59B4);
    ctx->hi = hi; ctx->lo = lo;
    func_80063B34(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_80063B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063B34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80063B38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063B3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80063B40: beq         $t6, $zero, L_80063B78
    if (ctx->r14 == 0) {
        // 0x80063B44: andi        $a3, $a0, 0xFF
        ctx->r7 = ctx->r4 & 0XFF;
            goto L_80063B78;
    }
    // 0x80063B44: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80063B48: lbu         $v0, 0x18($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X18);
    // 0x80063B4C: andi        $t1, $a3, 0xF
    ctx->r9 = ctx->r7 & 0XF;
    // 0x80063B50: andi        $t7, $v0, 0xFF0F
    ctx->r15 = ctx->r2 & 0XFF0F;
    // 0x80063B54: ori         $t9, $t7, 0x30
    ctx->r25 = ctx->r15 | 0X30;
    // 0x80063B58: andi        $t2, $t9, 0xFFF0
    ctx->r10 = ctx->r25 & 0XFFF0;
    // 0x80063B5C: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x80063B60: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80063B64: addiu       $a0, $a0, -0x2F20
    ctx->r4 = ADD32(ctx->r4, -0X2F20);
    // 0x80063B68: sb          $t3, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r11;
    // 0x80063B6C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063B70: jal         0x8006A090
    // 0x80063B74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80063B74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
L_80063B78:
    // 0x80063B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063B7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80063B80: jr          $ra
    // 0x80063B84: nop

    return;
    // 0x80063B84: nop

;}
RECOMP_FUNC void func_80063B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063B88: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80063B8C: lw          $t6, 0x59B4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X59B4);
    ctx->hi = hi; ctx->lo = lo;
    func_80063B90(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_80063B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063B90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80063B94: beq         $t6, $zero, L_80063BC8
    if (ctx->r14 == 0) {
        // 0x80063B98: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80063BC8;
    }
    // 0x80063B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063B9C: lbu         $t7, 0x18($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X18);
    // 0x80063BA0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80063BA4: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x80063BA8: ori         $t1, $t8, 0x50
    ctx->r9 = ctx->r24 | 0X50;
    // 0x80063BAC: sb          $t1, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r9;
    // 0x80063BB0: ori         $t2, $t1, 0xF
    ctx->r10 = ctx->r9 | 0XF;
    // 0x80063BB4: sb          $t2, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r10;
    // 0x80063BB8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80063BBC: addiu       $a0, $a0, -0x2F20
    ctx->r4 = ADD32(ctx->r4, -0X2F20);
    // 0x80063BC0: jal         0x8006A090
    // 0x80063BC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80063BC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_80063BC8:
    // 0x80063BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063BCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80063BD0: jr          $ra
    // 0x80063BD4: nop

    return;
    // 0x80063BD4: nop

;}
RECOMP_FUNC void func_80063BD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063BD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063BDC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80063BE0: addiu       $v0, $v0, 0x59B4
    ctx->r2 = ADD32(ctx->r2, 0X59B4);
    // 0x80063BE4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80063BE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80063BEC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80063BF0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80063BF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80063BF8: beq         $t6, $zero, L_80063C68
    if (ctx->r14 == 0) {
        // 0x80063BFC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80063C68;
    }
    // 0x80063BFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80063C00: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80063C04: addiu       $s0, $s0, -0x2EE0
    ctx->r16 = ADD32(ctx->r16, -0X2EE0);
    // 0x80063C08: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80063C0C: jal         0x8006D800
    // 0x80063C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osStopThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80063C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80063C14: jal         0x8006D8C0
    // 0x80063C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osDestroyThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80063C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80063C1C: jal         0x800603D8
    // 0x80063C20: nop

    func_800603D8(rdram, ctx);
        goto after_2;
    // 0x80063C20: nop

    after_2:
    // 0x80063C24: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80063C28: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80063C2C: addiu       $s2, $s2, 0x2860
    ctx->r18 = ADD32(ctx->r18, 0X2860);
    // 0x80063C30: addiu       $s1, $s1, -0x3194
    ctx->r17 = ADD32(ctx->r17, -0X3194);
    // 0x80063C34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80063C38: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_80063C3C:
    // 0x80063C3C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80063C40: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80063C44: jal         0x8006BC60
    // 0x80063C48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_3;
    // 0x80063C48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80063C4C: jal         0x8006B810
    // 0x80063C50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osMotorStop_recomp(rdram, ctx);
        goto after_4;
    // 0x80063C50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80063C54: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80063C58: bne         $s0, $s3, L_80063C3C
    if (ctx->r16 != ctx->r19) {
        // 0x80063C5C: addiu       $s1, $s1, 0x90
        ctx->r17 = ADD32(ctx->r17, 0X90);
            goto L_80063C3C;
    }
    // 0x80063C5C: addiu       $s1, $s1, 0x90
    ctx->r17 = ADD32(ctx->r17, 0X90);
    // 0x80063C60: jal         0x800603AC
    // 0x80063C64: nop

    func_800603AC(rdram, ctx);
        goto after_5;
    // 0x80063C64: nop

    after_5:
L_80063C68:
    // 0x80063C68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80063C6C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80063C70: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80063C74: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80063C78: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80063C7C: jr          $ra
    // 0x80063C80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80063C80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80063C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063C84: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80063C88: lw          $t6, 0x59B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X59B0);
    ctx->hi = hi; ctx->lo = lo;
    func_80063C8C(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_80063C8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063C8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063C90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063C94: bne         $t6, $zero, L_80063CB0
    if (ctx->r14 != 0) {
        // 0x80063C98: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80063CB0;
    }
    // 0x80063C98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80063C9C: jal         0x800609A0
    // 0x80063CA0: nop

    func_800609A0(rdram, ctx);
        goto after_0;
    // 0x80063CA0: nop

    after_0:
    // 0x80063CA4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80063CA8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80063CAC: sw          $t7, 0x59B0($at)
    MEM_W(0X59B0, ctx->r1) = ctx->r15;
L_80063CB0:
    // 0x80063CB0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80063CB4: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80063CB8: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80063CBC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80063CC0: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80063CC4: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x80063CC8: addiu       $t1, $t1, -0x3198
    ctx->r9 = ADD32(ctx->r9, -0X3198);
    // 0x80063CCC: jal         0x8006B978
    // 0x80063CD0: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    osMotorStart_recomp(rdram, ctx);
        goto after_1;
    // 0x80063CD0: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_1:
    // 0x80063CD4: bne         $v0, $zero, L_80063CFC
    if (ctx->r2 != 0) {
        // 0x80063CD8: lui         $t4, 0x8011
        ctx->r12 = S32(0X8011 << 16);
            goto L_80063CFC;
    }
    // 0x80063CD8: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x80063CDC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80063CE0: addiu       $t4, $t4, -0x2F40
    ctx->r12 = ADD32(ctx->r12, -0X2F40);
    // 0x80063CE4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80063CE8: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80063CEC: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80063CF0: nop

    // 0x80063CF4: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x80063CF8: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_80063CFC:
    // 0x80063CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063D00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063D04: jr          $ra
    // 0x80063D08: nop

    return;
    // 0x80063D08: nop

;}
RECOMP_FUNC void func_80063D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063D0C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80063D10: lw          $t6, 0x59B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X59B0);
    ctx->hi = hi; ctx->lo = lo;
    func_80063D14(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_80063D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063D14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063D18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063D1C: bne         $t6, $zero, L_80063D38
    if (ctx->r14 != 0) {
        // 0x80063D20: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80063D38;
    }
    // 0x80063D20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80063D24: jal         0x800609A0
    // 0x80063D28: nop

    func_800609A0(rdram, ctx);
        goto after_0;
    // 0x80063D28: nop

    after_0:
    // 0x80063D2C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80063D30: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80063D34: sw          $t7, 0x59B0($at)
    MEM_W(0X59B0, ctx->r1) = ctx->r15;
L_80063D38:
    // 0x80063D38: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80063D3C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80063D40: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80063D44: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80063D48: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80063D4C: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x80063D50: addiu       $t1, $t1, -0x3198
    ctx->r9 = ADD32(ctx->r9, -0X3198);
    // 0x80063D54: jal         0x8006B810
    // 0x80063D58: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    osMotorStop_recomp(rdram, ctx);
        goto after_1;
    // 0x80063D58: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_1:
    // 0x80063D5C: bne         $v0, $zero, L_80063D84
    if (ctx->r2 != 0) {
        // 0x80063D60: lui         $t4, 0x8011
        ctx->r12 = S32(0X8011 << 16);
            goto L_80063D84;
    }
    // 0x80063D60: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x80063D64: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80063D68: addiu       $t4, $t4, -0x2F40
    ctx->r12 = ADD32(ctx->r12, -0X2F40);
    // 0x80063D6C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80063D70: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80063D74: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80063D78: nop

    // 0x80063D7C: andi        $t6, $t5, 0xFFDF
    ctx->r14 = ctx->r13 & 0XFFDF;
    // 0x80063D80: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
L_80063D84:
    // 0x80063D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063D8C: jr          $ra
    // 0x80063D90: nop

    return;
    // 0x80063D90: nop

;}
RECOMP_FUNC void func_80063D94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80063D94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063D98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80063D9C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80063DA0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80063DA4: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80063DA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80063DAC: addiu       $s0, $s0, -0x2F40
    ctx->r16 = ADD32(ctx->r16, -0X2F40);
    // 0x80063DB0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80063DB4: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_80063DB8:
    // 0x80063DB8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80063DBC: nop

    // 0x80063DC0: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80063DC4: beq         $t7, $zero, L_80063FDC
    if (ctx->r15 == 0) {
        // 0x80063DC8: nop
    
            goto L_80063FDC;
    }
    // 0x80063DC8: nop

    // 0x80063DCC: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80063DD0: lhu         $t3, 0x4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X4);
    // 0x80063DD4: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x80063DD8: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80063DDC: sll         $t2, $t0, 6
    ctx->r10 = S32(ctx->r8 << 6);
    // 0x80063DE0: andi        $t4, $t3, 0x3F
    ctx->r12 = ctx->r11 & 0X3F;
    // 0x80063DE4: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80063DE8: sh          $t5, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r13;
    // 0x80063DEC: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80063DF0: nop

    // 0x80063DF4: srl         $t6, $v1, 22
    ctx->r14 = S32(U32(ctx->r3) >> 22);
    // 0x80063DF8: beq         $t6, $zero, L_80063E24
    if (ctx->r14 == 0) {
        // 0x80063DFC: nop
    
            goto L_80063E24;
    }
    // 0x80063DFC: nop

    // 0x80063E00: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80063E04: sll         $t5, $v1, 10
    ctx->r13 = S32(ctx->r3 << 10);
    // 0x80063E08: sll         $a0, $v0, 6
    ctx->r4 = S32(ctx->r2 << 6);
    // 0x80063E0C: srl         $t7, $a0, 24
    ctx->r15 = S32(U32(ctx->r4) >> 24);
    // 0x80063E10: bne         $t7, $zero, L_80063E54
    if (ctx->r15 != 0) {
        // 0x80063E14: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_80063E54;
    }
    // 0x80063E14: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80063E18: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80063E1C: bltz        $t9, L_80063E58
    if (SIGNED(ctx->r25) < 0) {
        // 0x80063E20: srl         $t6, $t5, 24
        ctx->r14 = S32(U32(ctx->r13) >> 24);
            goto L_80063E58;
    }
    // 0x80063E20: srl         $t6, $t5, 24
    ctx->r14 = S32(U32(ctx->r13) >> 24);
L_80063E24:
    // 0x80063E24: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80063E28: nop

    // 0x80063E2C: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x80063E30: bgez        $t3, L_80063E40
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80063E34: nop
    
            goto L_80063E40;
    }
    // 0x80063E34: nop

    // 0x80063E38: jal         0x80063D0C
    // 0x80063E3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80063D0C(rdram, ctx);
        goto after_0;
    // 0x80063E3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
L_80063E40:
    // 0x80063E40: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x80063E44: nop

    // 0x80063E48: andi        $t4, $t2, 0xFF7F
    ctx->r12 = ctx->r10 & 0XFF7F;
    // 0x80063E4C: b           L_80063FDC
    // 0x80063E50: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
        goto L_80063FDC;
    // 0x80063E50: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
L_80063E54:
    // 0x80063E54: srl         $t6, $t5, 24
    ctx->r14 = S32(U32(ctx->r13) >> 24);
L_80063E58:
    // 0x80063E58: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80063E5C: srl         $t8, $v1, 14
    ctx->r24 = S32(U32(ctx->r3) >> 14);
    // 0x80063E60: xor         $t9, $t7, $t8
    ctx->r25 = ctx->r15 ^ ctx->r24;
    // 0x80063E64: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x80063E68: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x80063E6C: xor         $t3, $t1, $v1
    ctx->r11 = ctx->r9 ^ ctx->r3;
    // 0x80063E70: sll         $a1, $t3, 10
    ctx->r5 = S32(ctx->r11 << 10);
    // 0x80063E74: srl         $t2, $a1, 24
    ctx->r10 = S32(U32(ctx->r5) >> 24);
    // 0x80063E78: sltiu       $at, $t2, 0x40
    ctx->r1 = ctx->r10 < 0X40 ? 1 : 0;
    // 0x80063E7C: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x80063E80: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80063E84: bne         $at, $zero, L_80063ED8
    if (ctx->r1 != 0) {
        // 0x80063E88: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80063ED8;
    }
    // 0x80063E88: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80063E8C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80063E90: bltz        $t5, L_80063EB8
    if (SIGNED(ctx->r13) < 0) {
        // 0x80063E94: addiu       $t7, $a1, -0x40
        ctx->r15 = ADD32(ctx->r5, -0X40);
            goto L_80063EB8;
    }
    // 0x80063E94: addiu       $t7, $a1, -0x40
    ctx->r15 = ADD32(ctx->r5, -0X40);
    // 0x80063E98: jal         0x80063C84
    // 0x80063E9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80063C84(rdram, ctx);
        goto after_1;
    // 0x80063E9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80063EA0: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80063EA4: nop

    // 0x80063EA8: sll         $a1, $v1, 10
    ctx->r5 = S32(ctx->r3 << 10);
    // 0x80063EAC: srl         $t6, $a1, 24
    ctx->r14 = S32(U32(ctx->r5) >> 24);
    // 0x80063EB0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80063EB4: addiu       $t7, $a1, -0x40
    ctx->r15 = ADD32(ctx->r5, -0X40);
L_80063EB8:
    // 0x80063EB8: srl         $t8, $v1, 14
    ctx->r24 = S32(U32(ctx->r3) >> 14);
    // 0x80063EBC: xor         $t9, $t7, $t8
    ctx->r25 = ctx->r15 ^ ctx->r24;
    // 0x80063EC0: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x80063EC4: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x80063EC8: xor         $t3, $t1, $v1
    ctx->r11 = ctx->r9 ^ ctx->r3;
    // 0x80063ECC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80063ED0: b           L_80063EF4
    // 0x80063ED4: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
        goto L_80063EF4;
    // 0x80063ED4: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
L_80063ED8:
    // 0x80063ED8: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80063EDC: bgez        $t4, L_80063EF8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80063EE0: sll         $t6, $v0, 4
        ctx->r14 = S32(ctx->r2 << 4);
            goto L_80063EF8;
    }
    // 0x80063EE0: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80063EE4: jal         0x80063D0C
    // 0x80063EE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80063D0C(rdram, ctx);
        goto after_2;
    // 0x80063EE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80063EEC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80063EF0: nop

L_80063EF4:
    // 0x80063EF4: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
L_80063EF8:
    // 0x80063EF8: bgez        $t6, L_80063F74
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80063EFC: sll         $t9, $v0, 5
        ctx->r25 = S32(ctx->r2 << 5);
            goto L_80063F74;
    }
    // 0x80063EFC: sll         $t9, $v0, 5
    ctx->r25 = S32(ctx->r2 << 5);
    // 0x80063F00: sll         $t7, $v0, 6
    ctx->r15 = S32(ctx->r2 << 6);
    // 0x80063F04: sll         $t9, $v0, 22
    ctx->r25 = S32(ctx->r2 << 22);
    // 0x80063F08: srl         $t0, $t9, 24
    ctx->r8 = S32(U32(ctx->r25) >> 24);
    // 0x80063F0C: srl         $t8, $t7, 24
    ctx->r24 = S32(U32(ctx->r15) >> 24);
    // 0x80063F10: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
    // 0x80063F14: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80063F18: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80063F1C: andi        $t2, $t3, 0x3FC
    ctx->r10 = ctx->r11 & 0X3FC;
    // 0x80063F20: andi        $t5, $t4, 0xFC03
    ctx->r13 = ctx->r12 & 0XFC03;
    // 0x80063F24: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x80063F28: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x80063F2C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80063F30: or          $t3, $t6, $zero
    ctx->r11 = ctx->r14 | 0;
    // 0x80063F34: sll         $v1, $v0, 14
    ctx->r3 = S32(ctx->r2 << 14);
    // 0x80063F38: sll         $t9, $v0, 6
    ctx->r25 = S32(ctx->r2 << 6);
    // 0x80063F3C: srl         $t8, $t9, 24
    ctx->r24 = S32(U32(ctx->r25) >> 24);
    // 0x80063F40: srl         $t7, $v1, 24
    ctx->r15 = S32(U32(ctx->r3) >> 24);
    // 0x80063F44: sltu        $at, $t8, $t7
    ctx->r1 = ctx->r24 < ctx->r15 ? 1 : 0;
    // 0x80063F48: bne         $at, $zero, L_80063FDC
    if (ctx->r1 != 0) {
        // 0x80063F4C: sll         $t0, $t7, 2
        ctx->r8 = S32(ctx->r15 << 2);
            goto L_80063FDC;
    }
    // 0x80063F4C: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80063F50: andi        $t1, $t0, 0x3FC
    ctx->r9 = ctx->r8 & 0X3FC;
    // 0x80063F54: andi        $t4, $t3, 0xFC03
    ctx->r12 = ctx->r11 & 0XFC03;
    // 0x80063F58: or          $t2, $t1, $t4
    ctx->r10 = ctx->r9 | ctx->r12;
    // 0x80063F5C: sh          $t2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r10;
    // 0x80063F60: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x80063F64: nop

    // 0x80063F68: andi        $t6, $t5, 0xFFF7
    ctx->r14 = ctx->r13 & 0XFFF7;
    // 0x80063F6C: b           L_80063FDC
    // 0x80063F70: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
        goto L_80063FDC;
    // 0x80063F70: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
L_80063F74:
    // 0x80063F74: bgez        $t9, L_80063FDC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80063F78: sll         $v1, $v0, 22
        ctx->r3 = S32(ctx->r2 << 22);
            goto L_80063FDC;
    }
    // 0x80063F78: sll         $v1, $v0, 22
    ctx->r3 = S32(ctx->r2 << 22);
    // 0x80063F7C: sll         $a0, $v0, 6
    ctx->r4 = S32(ctx->r2 << 6);
    // 0x80063F80: srl         $t0, $a0, 24
    ctx->r8 = S32(U32(ctx->r4) >> 24);
    // 0x80063F84: srl         $t8, $v1, 24
    ctx->r24 = S32(U32(ctx->r3) >> 24);
    // 0x80063F88: sltu        $at, $t8, $t0
    ctx->r1 = ctx->r24 < ctx->r8 ? 1 : 0;
    // 0x80063F8C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80063F90: bne         $at, $zero, L_80063FC0
    if (ctx->r1 != 0) {
        // 0x80063F94: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80063FC0;
    }
    // 0x80063F94: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80063F98: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80063F9C: bgez        $t1, L_80063FAC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80063FA0: nop
    
            goto L_80063FAC;
    }
    // 0x80063FA0: nop

    // 0x80063FA4: jal         0x80063D0C
    // 0x80063FA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80063D0C(rdram, ctx);
        goto after_3;
    // 0x80063FA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
L_80063FAC:
    // 0x80063FAC: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x80063FB0: nop

    // 0x80063FB4: andi        $t2, $t4, 0xFF7F
    ctx->r10 = ctx->r12 & 0XFF7F;
    // 0x80063FB8: b           L_80063FDC
    // 0x80063FBC: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
        goto L_80063FDC;
    // 0x80063FBC: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
L_80063FC0:
    // 0x80063FC0: lhu         $t9, 0x0($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X0);
    // 0x80063FC4: subu        $t5, $a0, $v1
    ctx->r13 = SUB32(ctx->r4, ctx->r3);
    // 0x80063FC8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80063FCC: andi        $t7, $t6, 0x3FC
    ctx->r15 = ctx->r14 & 0X3FC;
    // 0x80063FD0: andi        $t8, $t9, 0xFC03
    ctx->r24 = ctx->r25 & 0XFC03;
    // 0x80063FD4: or          $t0, $t7, $t8
    ctx->r8 = ctx->r15 | ctx->r24;
    // 0x80063FD8: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
L_80063FDC:
    // 0x80063FDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80063FE0: bne         $s1, $s2, L_80063DB8
    if (ctx->r17 != ctx->r18) {
        // 0x80063FE4: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80063DB8;
    }
    // 0x80063FE4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80063FE8: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80063FEC: addiu       $s0, $s0, 0x59B0
    ctx->r16 = ADD32(ctx->r16, 0X59B0);
    // 0x80063FF0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80063FF4: nop

    // 0x80063FF8: beq         $t3, $zero, L_80064010
    if (ctx->r11 == 0) {
        // 0x80063FFC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80064010;
    }
    // 0x80063FFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80064000: jal         0x800609E0
    // 0x80064004: nop

    __osSiRelAccess_recomp(rdram, ctx);
        goto after_4;
    // 0x80064004: nop

    after_4:
    // 0x80064008: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8006400C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064010:
    // 0x80064010: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064014: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80064018: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006401C: jr          $ra
    // 0x80064020: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80064020: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80064024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80064024: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80064028: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006402C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80064030: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80064034: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80064038: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x8006403C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80064040: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80064044: addiu       $s2, $s2, -0x2F40
    ctx->r18 = ADD32(ctx->r18, -0X2F40);
    // 0x80064048: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006404C: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_80064050:
    // 0x80064050: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80064054: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80064058: sllv        $t9, $t8, $s1
    ctx->r25 = S32(ctx->r24 << (ctx->r17 & 31));
    // 0x8006405C: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x80064060: and         $t0, $t7, $t9
    ctx->r8 = ctx->r15 & ctx->r25;
    // 0x80064064: beq         $t0, $zero, L_800642DC
    if (ctx->r8 == 0) {
        // 0x80064068: sll         $t1, $s1, 3
        ctx->r9 = S32(ctx->r17 << 3);
            goto L_800642DC;
    }
    // 0x80064068: sll         $t1, $s1, 3
    ctx->r9 = S32(ctx->r17 << 3);
    // 0x8006406C: addu        $v0, $s2, $t1
    ctx->r2 = ADD32(ctx->r18, ctx->r9);
    // 0x80064070: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80064074: nop

    // 0x80064078: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x8006407C: bgez        $t3, L_800642DC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80064080: srl         $t4, $v1, 31
        ctx->r12 = S32(U32(ctx->r3) >> 31);
            goto L_800642DC;
    }
    // 0x80064080: srl         $t4, $v1, 31
    ctx->r12 = S32(U32(ctx->r3) >> 31);
    // 0x80064084: beq         $t4, $zero, L_800640CC
    if (ctx->r12 == 0) {
        // 0x80064088: nop
    
            goto L_800640CC;
    }
    // 0x80064088: nop

    // 0x8006408C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80064090: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x80064094: sll         $t8, $a0, 18
    ctx->r24 = S32(ctx->r4 << 18);
    // 0x80064098: srl         $t7, $t8, 22
    ctx->r15 = S32(U32(ctx->r24) >> 22);
    // 0x8006409C: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x800640A0: srl         $t6, $t5, 22
    ctx->r14 = S32(U32(ctx->r13) >> 22);
    // 0x800640A4: sltu        $at, $t9, $t6
    ctx->r1 = ctx->r25 < ctx->r14 ? 1 : 0;
    // 0x800640A8: beq         $at, $zero, L_800640CC
    if (ctx->r1 == 0) {
        // 0x800640AC: sll         $t0, $v1, 14
        ctx->r8 = S32(ctx->r3 << 14);
            goto L_800640CC;
    }
    // 0x800640AC: sll         $t0, $v1, 14
    ctx->r8 = S32(ctx->r3 << 14);
    // 0x800640B0: sll         $t2, $a0, 10
    ctx->r10 = S32(ctx->r4 << 10);
    // 0x800640B4: srl         $t3, $t2, 24
    ctx->r11 = S32(U32(ctx->r10) >> 24);
    // 0x800640B8: addiu       $t4, $t3, -0x8
    ctx->r12 = ADD32(ctx->r11, -0X8);
    // 0x800640BC: srl         $t1, $t0, 24
    ctx->r9 = S32(U32(ctx->r8) >> 24);
    // 0x800640C0: sltu        $at, $t4, $t1
    ctx->r1 = ctx->r12 < ctx->r9 ? 1 : 0;
    // 0x800640C4: bne         $at, $zero, L_800642DC
    if (ctx->r1 != 0) {
        // 0x800640C8: nop
    
            goto L_800642DC;
    }
    // 0x800640C8: nop

L_800640CC:
    // 0x800640CC: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x800640D0: nop

    // 0x800640D4: ori         $t6, $t8, 0x80
    ctx->r14 = ctx->r24 | 0X80;
    // 0x800640D8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800640DC: andi        $t9, $t6, 0xDF
    ctx->r25 = ctx->r14 & 0XDF;
    // 0x800640E0: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800640E4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800640E8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800640EC: sll         $t2, $t0, 10
    ctx->r10 = S32(ctx->r8 << 10);
    // 0x800640F0: srl         $t3, $t2, 24
    ctx->r11 = S32(U32(ctx->r10) >> 24);
    // 0x800640F4: srl         $t1, $v1, 10
    ctx->r9 = S32(U32(ctx->r3) >> 10);
    // 0x800640F8: xor         $t4, $t3, $t1
    ctx->r12 = ctx->r11 ^ ctx->r9;
    // 0x800640FC: sll         $t5, $t4, 24
    ctx->r13 = S32(ctx->r12 << 24);
    // 0x80064100: srl         $t8, $t5, 14
    ctx->r24 = S32(U32(ctx->r13) >> 14);
    // 0x80064104: xor         $t7, $t8, $v1
    ctx->r15 = ctx->r24 ^ ctx->r3;
    // 0x80064108: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006410C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80064110: lhu         $t1, 0x4($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X4);
    // 0x80064114: sll         $t9, $t6, 18
    ctx->r25 = S32(ctx->r14 << 18);
    // 0x80064118: srl         $t0, $t9, 22
    ctx->r8 = S32(U32(ctx->r25) >> 22);
    // 0x8006411C: sll         $t3, $t0, 6
    ctx->r11 = S32(ctx->r8 << 6);
    // 0x80064120: andi        $t4, $t1, 0x3F
    ctx->r12 = ctx->r9 & 0X3F;
    // 0x80064124: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80064128: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x8006412C: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    // 0x80064130: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80064134: srl         $t7, $t8, 7
    ctx->r15 = S32(U32(ctx->r24) >> 7);
    // 0x80064138: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x8006413C: andi        $t9, $t6, 0x8
    ctx->r25 = ctx->r14 & 0X8;
    // 0x80064140: andi        $t2, $t0, 0xFFF7
    ctx->r10 = ctx->r8 & 0XFFF7;
    // 0x80064144: or          $t1, $t9, $t2
    ctx->r9 = ctx->r25 | ctx->r10;
    // 0x80064148: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8006414C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80064150: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80064154: sll         $t4, $t3, 9
    ctx->r12 = S32(ctx->r11 << 9);
    // 0x80064158: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x8006415C: andi        $t6, $t1, 0xFF
    ctx->r14 = ctx->r9 & 0XFF;
    // 0x80064160: srl         $t2, $a0, 14
    ctx->r10 = S32(U32(ctx->r4) >> 14);
    // 0x80064164: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80064168: sll         $t1, $t2, 24
    ctx->r9 = S32(ctx->r10 << 24);
    // 0x8006416C: andi        $t7, $t8, 0x4
    ctx->r15 = ctx->r24 & 0X4;
    // 0x80064170: andi        $t0, $t6, 0xFFFB
    ctx->r8 = ctx->r14 & 0XFFFB;
    // 0x80064174: srl         $t3, $t1, 10
    ctx->r11 = S32(U32(ctx->r9) >> 10);
    // 0x80064178: or          $t9, $t7, $t0
    ctx->r25 = ctx->r15 | ctx->r8;
    // 0x8006417C: xor         $t4, $t3, $a0
    ctx->r12 = ctx->r11 ^ ctx->r4;
    // 0x80064180: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80064184: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80064188: lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1);
    // 0x8006418C: nop

    // 0x80064190: srl         $t5, $v1, 7
    ctx->r13 = S32(U32(ctx->r3) >> 7);
    // 0x80064194: bne         $t5, $zero, L_800641B4
    if (ctx->r13 != 0) {
        // 0x80064198: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_800641B4;
    }
    // 0x80064198: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8006419C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800641A0: nop

    // 0x800641A4: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x800641A8: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x800641AC: beq         $t7, $zero, L_800642A4
    if (ctx->r15 == 0) {
        // 0x800641B0: nop
    
            goto L_800642A4;
    }
    // 0x800641B0: nop

L_800641B4:
    // 0x800641B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800641B8: nop

    // 0x800641BC: sll         $t0, $a0, 9
    ctx->r8 = S32(ctx->r4 << 9);
    // 0x800641C0: srl         $t9, $t0, 31
    ctx->r25 = S32(U32(ctx->r8) >> 31);
    // 0x800641C4: beq         $t9, $zero, L_8006421C
    if (ctx->r25 == 0) {
        // 0x800641C8: sll         $t4, $a0, 10
        ctx->r12 = S32(ctx->r4 << 10);
            goto L_8006421C;
    }
    // 0x800641C8: sll         $t4, $a0, 10
    ctx->r12 = S32(ctx->r4 << 10);
    // 0x800641CC: beq         $v1, $zero, L_80064220
    if (ctx->r3 == 0) {
        // 0x800641D0: sll         $t5, $a0, 18
        ctx->r13 = S32(ctx->r4 << 18);
            goto L_80064220;
    }
    // 0x800641D0: sll         $t5, $a0, 18
    ctx->r13 = S32(ctx->r4 << 18);
    // 0x800641D4: sll         $t3, $a0, 18
    ctx->r11 = S32(ctx->r4 << 18);
    // 0x800641D8: srl         $t4, $t3, 22
    ctx->r12 = S32(U32(ctx->r11) >> 22);
    // 0x800641DC: sll         $t2, $a0, 10
    ctx->r10 = S32(ctx->r4 << 10);
    // 0x800641E0: srl         $t1, $t2, 24
    ctx->r9 = S32(U32(ctx->r10) >> 24);
    // 0x800641E4: srl         $t5, $t4, 1
    ctx->r13 = S32(U32(ctx->r12) >> 1);
    // 0x800641E8: divu        $zero, $t1, $t5
    lo = S32(U32(ctx->r9) / U32(ctx->r13)); hi = S32(U32(ctx->r9) % U32(ctx->r13));
    // 0x800641EC: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800641F0: bne         $t5, $zero, L_800641FC
    if (ctx->r13 != 0) {
        // 0x800641F4: nop
    
            goto L_800641FC;
    }
    // 0x800641F4: nop

    // 0x800641F8: break       7
    do_break(2147893752);
L_800641FC:
    // 0x800641FC: andi        $t2, $t9, 0xFC03
    ctx->r10 = ctx->r25 & 0XFC03;
    // 0x80064200: mflo        $t8
    ctx->r24 = lo;
    // 0x80064204: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80064208: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006420C: andi        $t0, $t7, 0x3FC
    ctx->r8 = ctx->r15 & 0X3FC;
    // 0x80064210: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80064214: b           L_80064258
    // 0x80064218: sh          $t3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r11;
        goto L_80064258;
    // 0x80064218: sh          $t3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r11;
L_8006421C:
    // 0x8006421C: sll         $t5, $a0, 18
    ctx->r13 = S32(ctx->r4 << 18);
L_80064220:
    // 0x80064220: srl         $t8, $t5, 22
    ctx->r24 = S32(U32(ctx->r13) >> 22);
    // 0x80064224: srl         $t1, $t4, 24
    ctx->r9 = S32(U32(ctx->r12) >> 24);
    // 0x80064228: divu        $zero, $t1, $t8
    lo = S32(U32(ctx->r9) / U32(ctx->r24)); hi = S32(U32(ctx->r9) % U32(ctx->r24));
    // 0x8006422C: lhu         $t2, 0x2($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X2);
    // 0x80064230: bne         $t8, $zero, L_8006423C
    if (ctx->r24 != 0) {
        // 0x80064234: nop
    
            goto L_8006423C;
    }
    // 0x80064234: nop

    // 0x80064238: break       7
    do_break(2147893816);
L_8006423C:
    // 0x8006423C: andi        $t3, $t2, 0xFC03
    ctx->r11 = ctx->r10 & 0XFC03;
    // 0x80064240: mflo        $t6
    ctx->r14 = lo;
    // 0x80064244: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80064248: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8006424C: andi        $t0, $t9, 0x3FC
    ctx->r8 = ctx->r25 & 0X3FC;
    // 0x80064250: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x80064254: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
L_80064258:
    // 0x80064258: lb          $t1, 0x1($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1);
    // 0x8006425C: nop

    // 0x80064260: bgez        $t1, L_8006427C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80064264: nop
    
            goto L_8006427C;
    }
    // 0x80064264: nop

    // 0x80064268: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x8006426C: nop

    // 0x80064270: andi        $t6, $t8, 0xFC03
    ctx->r14 = ctx->r24 & 0XFC03;
    // 0x80064274: b           L_800642D4
    // 0x80064278: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
        goto L_800642D4;
    // 0x80064278: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
L_8006427C:
    // 0x8006427C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80064280: lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X0);
    // 0x80064284: sll         $t9, $t7, 10
    ctx->r25 = S32(ctx->r15 << 10);
    // 0x80064288: srl         $t2, $t9, 24
    ctx->r10 = S32(U32(ctx->r25) >> 24);
    // 0x8006428C: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x80064290: andi        $t3, $t0, 0x3FC
    ctx->r11 = ctx->r8 & 0X3FC;
    // 0x80064294: andi        $t5, $t4, 0xFC03
    ctx->r13 = ctx->r12 & 0XFC03;
    // 0x80064298: or          $t1, $t3, $t5
    ctx->r9 = ctx->r11 | ctx->r13;
    // 0x8006429C: b           L_800642D4
    // 0x800642A0: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
        goto L_800642D4;
    // 0x800642A0: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_800642A4:
    // 0x800642A4: lhu         $t8, 0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2);
    // 0x800642A8: lhu         $t3, 0x0($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X0);
    // 0x800642AC: andi        $t6, $t8, 0xFC03
    ctx->r14 = ctx->r24 & 0XFC03;
    // 0x800642B0: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x800642B4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800642B8: andi        $t5, $t3, 0xFC03
    ctx->r13 = ctx->r11 & 0XFC03;
    // 0x800642BC: sll         $t9, $t7, 10
    ctx->r25 = S32(ctx->r15 << 10);
    // 0x800642C0: srl         $t2, $t9, 24
    ctx->r10 = S32(U32(ctx->r25) >> 24);
    // 0x800642C4: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x800642C8: andi        $t4, $t0, 0x3FC
    ctx->r12 = ctx->r8 & 0X3FC;
    // 0x800642CC: or          $t1, $t4, $t5
    ctx->r9 = ctx->r12 | ctx->r13;
    // 0x800642D0: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_800642D4:
    // 0x800642D4: jal         0x80063C84
    // 0x800642D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80063C84(rdram, ctx);
        goto after_0;
    // 0x800642D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
L_800642DC:
    // 0x800642DC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800642E0: bne         $s1, $s3, L_80064050
    if (ctx->r17 != ctx->r19) {
        // 0x800642E4: nop
    
            goto L_80064050;
    }
    // 0x800642E4: nop

    // 0x800642E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800642EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800642F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800642F4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800642F8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800642FC: jr          $ra
    // 0x80064300: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80064300: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80064304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80064304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006430C: jal         0x800609A0
    // 0x80064310: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800609A0(rdram, ctx);
        goto after_0;
    // 0x80064310: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80064314: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80064318: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8006431C: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x80064320: addiu       $v0, $v0, -0x2F40
    ctx->r2 = ADD32(ctx->r2, -0X2F40);
    // 0x80064324: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80064328: beq         $t9, $zero, L_8006434C
    if (ctx->r25 == 0) {
        // 0x8006432C: nop
    
            goto L_8006434C;
    }
    // 0x8006432C: nop

    // 0x80064330: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80064334: nop

    // 0x80064338: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8006433C: bgez        $t2, L_8006434C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80064340: nop
    
            goto L_8006434C;
    }
    // 0x80064340: nop

    // 0x80064344: jal         0x80063D0C
    // 0x80064348: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80063D0C(rdram, ctx);
        goto after_1;
    // 0x80064348: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
L_8006434C:
    // 0x8006434C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80064350: addiu       $v0, $v0, -0x2F40
    ctx->r2 = ADD32(ctx->r2, -0X2F40);
    // 0x80064354: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80064358: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8006435C: andi        $t4, $t3, 0xFF7F
    ctx->r12 = ctx->r11 & 0XFF7F;
    // 0x80064360: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x80064364: lbu         $t7, 0x0($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X0);
    // 0x80064368: nop

    // 0x8006436C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80064370: beq         $t8, $zero, L_8006439C
    if (ctx->r24 == 0) {
        // 0x80064374: nop
    
            goto L_8006439C;
    }
    // 0x80064374: nop

    // 0x80064378: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8006437C: nop

    // 0x80064380: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80064384: bgez        $t1, L_8006439C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80064388: nop
    
            goto L_8006439C;
    }
    // 0x80064388: nop

    // 0x8006438C: jal         0x80063D0C
    // 0x80064390: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80063D0C(rdram, ctx);
        goto after_2;
    // 0x80064390: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80064394: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80064398: addiu       $v0, $v0, -0x2F40
    ctx->r2 = ADD32(ctx->r2, -0X2F40);
L_8006439C:
    // 0x8006439C: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x800643A0: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800643A4: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x800643A8: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x800643AC: lbu         $t6, 0x0($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X0);
    // 0x800643B0: nop

    // 0x800643B4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800643B8: beq         $t7, $zero, L_800643E4
    if (ctx->r15 == 0) {
        // 0x800643BC: nop
    
            goto L_800643E4;
    }
    // 0x800643BC: nop

    // 0x800643C0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800643C4: nop

    // 0x800643C8: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800643CC: bgez        $t0, L_800643E4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800643D0: nop
    
            goto L_800643E4;
    }
    // 0x800643D0: nop

    // 0x800643D4: jal         0x80063D0C
    // 0x800643D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80063D0C(rdram, ctx);
        goto after_3;
    // 0x800643D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800643DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800643E0: addiu       $v0, $v0, -0x2F40
    ctx->r2 = ADD32(ctx->r2, -0X2F40);
L_800643E4:
    // 0x800643E4: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x800643E8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800643EC: andi        $t2, $t1, 0xFF7F
    ctx->r10 = ctx->r9 & 0XFF7F;
    // 0x800643F0: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x800643F4: lbu         $t5, 0x0($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X0);
    // 0x800643F8: nop

    // 0x800643FC: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80064400: beq         $t6, $zero, L_8006442C
    if (ctx->r14 == 0) {
        // 0x80064404: nop
    
            goto L_8006442C;
    }
    // 0x80064404: nop

    // 0x80064408: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8006440C: nop

    // 0x80064410: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80064414: bgez        $t9, L_8006442C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80064418: nop
    
            goto L_8006442C;
    }
    // 0x80064418: nop

    // 0x8006441C: jal         0x80063D0C
    // 0x80064420: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80063D0C(rdram, ctx);
        goto after_4;
    // 0x80064420: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80064424: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80064428: addiu       $v0, $v0, -0x2F40
    ctx->r2 = ADD32(ctx->r2, -0X2F40);
L_8006442C:
    // 0x8006442C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80064430: nop

    // 0x80064434: andi        $t1, $t0, 0xFF7F
    ctx->r9 = ctx->r8 & 0XFF7F;
    // 0x80064438: jal         0x800609E0
    // 0x8006443C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    __osSiRelAccess_recomp(rdram, ctx);
        goto after_5;
    // 0x8006443C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    after_5:
    // 0x80064440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064448: jr          $ra
    // 0x8006444C: nop

    return;
    // 0x8006444C: nop

;}
RECOMP_FUNC void func_80064450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80064450: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80064454: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80064458: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8006445C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80064460: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80064464: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80064468: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8006446C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80064470: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80064474: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80064478: jal         0x800609A0
    // 0x8006447C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800609A0(rdram, ctx);
        goto after_0;
    // 0x8006447C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80064480: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x80064484: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x80064488: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8006448C: addiu       $s3, $s3, 0x2860
    ctx->r19 = ADD32(ctx->r19, 0X2860);
    // 0x80064490: addiu       $s4, $s4, -0x3198
    ctx->r20 = ADD32(ctx->r20, -0X3198);
    // 0x80064494: addiu       $s2, $s2, -0x2F40
    ctx->r18 = ADD32(ctx->r18, -0X2F40);
    // 0x80064498: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006449C: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x800644A0: addiu       $s5, $zero, 0x90
    ctx->r21 = ADD32(0, 0X90);
L_800644A4:
    // 0x800644A4: lbu         $t6, 0x0($s7)
    ctx->r14 = MEM_BU(ctx->r23, 0X0);
    // 0x800644A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800644AC: sllv        $t9, $t8, $s0
    ctx->r25 = S32(ctx->r24 << (ctx->r16 & 31));
    // 0x800644B0: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800644B4: and         $t0, $t7, $t9
    ctx->r8 = ctx->r15 & ctx->r25;
    // 0x800644B8: beq         $t0, $zero, L_800644E8
    if (ctx->r8 == 0) {
        // 0x800644BC: nop
    
            goto L_800644E8;
    }
    // 0x800644BC: nop

    // 0x800644C0: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800644C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800644C8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800644CC: mflo        $t1
    ctx->r9 = lo;
    // 0x800644D0: addu        $s1, $s4, $t1
    ctx->r17 = ADD32(ctx->r20, ctx->r9);
    // 0x800644D4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800644D8: jal         0x8006BC60
    // 0x800644DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_1;
    // 0x800644DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800644E0: jal         0x8006B810
    // 0x800644E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osMotorStop_recomp(rdram, ctx);
        goto after_2;
    // 0x800644E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
L_800644E8:
    // 0x800644E8: lbu         $t2, 0x0($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X0);
    // 0x800644EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800644F0: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x800644F4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800644F8: bne         $s0, $s6, L_800644A4
    if (ctx->r16 != ctx->r22) {
        // 0x800644FC: sb          $t3, -0x8($s2)
        MEM_B(-0X8, ctx->r18) = ctx->r11;
            goto L_800644A4;
    }
    // 0x800644FC: sb          $t3, -0x8($s2)
    MEM_B(-0X8, ctx->r18) = ctx->r11;
    // 0x80064500: jal         0x800609E0
    // 0x80064504: nop

    __osSiRelAccess_recomp(rdram, ctx);
        goto after_3;
    // 0x80064504: nop

    after_3:
    // 0x80064508: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006450C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80064510: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80064514: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80064518: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006451C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80064520: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80064524: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80064528: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8006452C: jr          $ra
    // 0x80064530: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80064530: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80064534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80064534: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80064538: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006453C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80064540: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80064544: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80064548: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006454C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80064550: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80064554: lui         $s2, 0x800F
    ctx->r18 = S32(0X800F << 16);
    // 0x80064558: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006455C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80064560: addiu       $s2, $s2, 0x2160
    ctx->r18 = ADD32(ctx->r18, 0X2160);
    // 0x80064564: addiu       $s1, $s1, -0x2F20
    ctx->r17 = ADD32(ctx->r17, -0X2F20);
    // 0x80064568: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x8006456C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80064570: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x80064574: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
    // 0x80064578: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8006457C:
    // 0x8006457C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80064580: jal         0x80069CF0
    // 0x80064584: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80064584: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_0:
    // 0x80064588: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8006458C: nop

    // 0x80064590: bne         $v1, $s2, L_800645A8
    if (ctx->r3 != ctx->r18) {
        // 0x80064594: srl         $t6, $v1, 28
        ctx->r14 = S32(U32(ctx->r3) >> 28);
            goto L_800645A8;
    }
    // 0x80064594: srl         $t6, $v1, 28
    ctx->r14 = S32(U32(ctx->r3) >> 28);
    // 0x80064598: jal         0x80063D94
    // 0x8006459C: nop

    func_80063D94(rdram, ctx);
        goto after_1;
    // 0x8006459C: nop

    after_1:
    // 0x800645A0: b           L_8006457C
    // 0x800645A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_8006457C;
    // 0x800645A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800645A8:
    // 0x800645A8: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800645AC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800645B0: nop

    // 0x800645B4: beq         $v0, $s3, L_800645D4
    if (ctx->r2 == ctx->r19) {
        // 0x800645B8: nop
    
            goto L_800645D4;
    }
    // 0x800645B8: nop

    // 0x800645BC: beq         $v0, $s4, L_800645E4
    if (ctx->r2 == ctx->r20) {
        // 0x800645C0: nop
    
            goto L_800645E4;
    }
    // 0x800645C0: nop

    // 0x800645C4: beq         $v0, $s5, L_800645F4
    if (ctx->r2 == ctx->r21) {
        // 0x800645C8: nop
    
            goto L_800645F4;
    }
    // 0x800645C8: nop

    // 0x800645CC: b           L_8006457C
    // 0x800645D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_8006457C;
    // 0x800645D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800645D4:
    // 0x800645D4: jal         0x80064024
    // 0x800645D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80064024(rdram, ctx);
        goto after_2;
    // 0x800645D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800645DC: b           L_8006457C
    // 0x800645E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_8006457C;
    // 0x800645E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800645E4:
    // 0x800645E4: jal         0x80064304
    // 0x800645E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80064304(rdram, ctx);
        goto after_3;
    // 0x800645E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800645EC: b           L_8006457C
    // 0x800645F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_8006457C;
    // 0x800645F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800645F4:
    // 0x800645F4: jal         0x80064450
    // 0x800645F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80064450(rdram, ctx);
        goto after_4;
    // 0x800645F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800645FC: b           L_8006457C
    // 0x80064600: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_8006457C;
    // 0x80064600: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80064604: nop

    // 0x80064608: nop

    // 0x8006460C: nop

    // 0x80064610: nop

    // 0x80064614: nop

    // 0x80064618: nop

    // 0x8006461C: nop

    // 0x80064620: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80064624: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80064628: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006462C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80064630: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80064634: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80064638: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8006463C: jr          $ra
    // 0x80064640: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80064640: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80064644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80064644: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80064648: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8006464C: lw          $t6, 0x59B4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X59B4);
    // 0x80064650: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80064654: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80064658: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8006465C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80064660: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80064664: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80064668: beq         $t6, $zero, L_80064720
    if (ctx->r14 == 0) {
        // 0x8006466C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80064720;
    }
    // 0x8006466C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80064670: jal         0x800603D8
    // 0x80064674: nop

    func_800603D8(rdram, ctx);
        goto after_0;
    // 0x80064674: nop

    after_0:
    // 0x80064678: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8006467C: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x80064680: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x80064684: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80064688: addiu       $s4, $s4, 0x2860
    ctx->r20 = ADD32(ctx->r20, 0X2860);
    // 0x8006468C: addiu       $s3, $s3, -0x3194
    ctx->r19 = ADD32(ctx->r19, -0X3194);
    // 0x80064690: addiu       $s2, $s2, -0x3198
    ctx->r18 = ADD32(ctx->r18, -0X3198);
    // 0x80064694: addiu       $s0, $s0, -0x2F40
    ctx->r16 = ADD32(ctx->r16, -0X2F40);
    // 0x80064698: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006469C: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
L_800646A0:
    // 0x800646A0: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x800646A4: lbu         $t3, 0x1($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X1);
    // 0x800646A8: andi        $t9, $t7, 0xFF7F
    ctx->r25 = ctx->r15 & 0XFF7F;
    // 0x800646AC: andi        $t1, $t9, 0xDF
    ctx->r9 = ctx->r25 & 0XDF;
    // 0x800646B0: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800646B4: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
    // 0x800646B8: andi        $t2, $t1, 0xEF
    ctx->r10 = ctx->r9 & 0XEF;
    // 0x800646BC: bne         $t3, $zero, L_800646CC
    if (ctx->r11 != 0) {
        // 0x800646C0: sb          $t2, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r10;
            goto L_800646CC;
    }
    // 0x800646C0: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
    // 0x800646C4: jal         0x80062CC8
    // 0x800646C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80062CC8(rdram, ctx);
        goto after_1;
    // 0x800646C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
L_800646CC:
    // 0x800646CC: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x800646D0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800646D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800646D8: jal         0x8006BC60
    // 0x800646DC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_2;
    // 0x800646DC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x800646E0: bne         $v0, $zero, L_80064704
    if (ctx->r2 != 0) {
        // 0x800646E4: nop
    
            goto L_80064704;
    }
    // 0x800646E4: nop

    // 0x800646E8: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x800646EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800646F0: ori         $t8, $t5, 0x10
    ctx->r24 = ctx->r13 | 0X10;
    // 0x800646F4: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800646F8: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x800646FC: jal         0x8006B810
    // 0x80064700: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    osMotorStop_recomp(rdram, ctx);
        goto after_3;
    // 0x80064700: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    after_3:
L_80064704:
    // 0x80064704: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80064708: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8006470C: addiu       $s2, $s2, 0x90
    ctx->r18 = ADD32(ctx->r18, 0X90);
    // 0x80064710: bne         $s1, $s5, L_800646A0
    if (ctx->r17 != ctx->r21) {
        // 0x80064714: addiu       $s3, $s3, 0x90
        ctx->r19 = ADD32(ctx->r19, 0X90);
            goto L_800646A0;
    }
    // 0x80064714: addiu       $s3, $s3, 0x90
    ctx->r19 = ADD32(ctx->r19, 0X90);
    // 0x80064718: jal         0x800603AC
    // 0x8006471C: nop

    func_800603AC(rdram, ctx);
        goto after_4;
    // 0x8006471C: nop

    after_4:
L_80064720:
    // 0x80064720: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80064724: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80064728: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006472C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80064730: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80064734: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80064738: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8006473C: jr          $ra
    // 0x80064740: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80064740: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80064744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80064744: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80064748: lbu         $t7, -0x2F40($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X2F40);
    // 0x8006474C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80064750: lbu         $t1, -0x2F38($v1)
    ctx->r9 = MEM_BU(ctx->r3, -0X2F38);
    // 0x80064754: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80064758: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8006475C: lbu         $t9, -0x2F28($a1)
    ctx->r25 = MEM_BU(ctx->r5, -0X2F28);
    // 0x80064760: lbu         $t5, -0x2F30($a0)
    ctx->r13 = MEM_BU(ctx->r4, -0X2F30);
    // 0x80064764: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80064768: andi        $v0, $t7, 0xFFAF
    ctx->r2 = ctx->r15 & 0XFFAF;
    // 0x8006476C: sb          $v0, -0x2F40($at)
    MEM_B(-0X2F40, ctx->r1) = ctx->r2;
    // 0x80064770: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80064774: andi        $t3, $t1, 0xFFAF
    ctx->r11 = ctx->r9 & 0XFFAF;
    // 0x80064778: sb          $t3, -0x2F38($at)
    MEM_B(-0X2F38, ctx->r1) = ctx->r11;
    // 0x8006477C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80064780: andi        $t7, $t5, 0xFFAF
    ctx->r15 = ctx->r13 & 0XFFAF;
    ctx->hi = hi; ctx->lo = lo;
    func_80064784(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_80064784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80064784: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80064788: sb          $t7, -0x2F30($at)
    MEM_B(-0X2F30, ctx->r1) = ctx->r15;
    // 0x8006478C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80064790: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80064794: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80064798: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8006479C: andi        $t1, $t9, 0xFFAF
    ctx->r9 = ctx->r25 & 0XFFAF;
    // 0x800647A0: sb          $t1, -0x2F28($at)
    MEM_B(-0X2F28, ctx->r1) = ctx->r9;
    // 0x800647A4: addiu       $a1, $a1, -0x2F08
    ctx->r5 = ADD32(ctx->r5, -0X2F08);
    // 0x800647A8: addiu       $a0, $a0, -0x2F20
    ctx->r4 = ADD32(ctx->r4, -0X2F20);
    // 0x800647AC: jal         0x800697E0
    // 0x800647B0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800647B0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x800647B4: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800647B8: addiu       $t2, $t2, -0x2930
    ctx->r10 = ADD32(ctx->r10, -0X2930);
    // 0x800647BC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800647C0: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x800647C4: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x800647C8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800647CC: addiu       $a2, $a2, 0x4534
    ctx->r6 = ADD32(ctx->r6, 0X4534);
    // 0x800647D0: addiu       $a0, $a0, -0x2EE0
    ctx->r4 = ADD32(ctx->r4, -0X2EE0);
    // 0x800647D4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800647D8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800647DC: jal         0x800693B0
    // 0x800647E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800647E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800647E4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800647E8: jal         0x80069500
    // 0x800647EC: addiu       $a0, $a0, -0x2EE0
    ctx->r4 = ADD32(ctx->r4, -0X2EE0);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800647EC: addiu       $a0, $a0, -0x2EE0
    ctx->r4 = ADD32(ctx->r4, -0X2EE0);
    after_2:
    // 0x800647F0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800647F4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800647F8: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800647FC: addiu       $a2, $a2, -0x2F20
    ctx->r6 = ADD32(ctx->r6, -0X2F20);
    // 0x80064800: addiu       $a1, $a1, -0x2930
    ctx->r5 = ADD32(ctx->r5, -0X2930);
    // 0x80064804: jal         0x80060DC0
    // 0x80064808: addiu       $a0, $a0, 0x2160
    ctx->r4 = ADD32(ctx->r4, 0X2160);
    func_80060DC0(rdram, ctx);
        goto after_3;
    // 0x80064808: addiu       $a0, $a0, 0x2160
    ctx->r4 = ADD32(ctx->r4, 0X2160);
    after_3:
    // 0x8006480C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80064810: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80064814: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80064818: sw          $t4, 0x59B4($at)
    MEM_W(0X59B4, ctx->r1) = ctx->r12;
    // 0x8006481C: jr          $ra
    // 0x80064820: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80064820: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80064824: nop

    // 0x80064828: nop

    // 0x8006482C: nop

;}
RECOMP_FUNC void func_80064830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80064830: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80064834: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80064838: jr          $ra
    // 0x8006483C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x8006483C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void func_80064840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80064840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064844: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80064848: addu        $a0, $a1, $a2
    ctx->r4 = ADD32(ctx->r5, ctx->r6);
    // 0x8006484C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80064850: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80064854: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80064858: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8006485C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80064860: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064864: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x80064868: lw          $a2, -0x2920($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2920);
    // 0x8006486C: jal         0x801459C8
    // 0x80064870: ori         $a3, $a3, 0x86A0
    ctx->r7 = ctx->r7 | 0X86A0;
    stub_801459C8(rdram, ctx);
        goto after_0;
    // 0x80064870: ori         $a3, $a3, 0x86A0
    ctx->r7 = ctx->r7 | 0X86A0;
    after_0:
    // 0x80064874: beq         $v0, $zero, L_80064890
    if (ctx->r2 == 0) {
        // 0x80064878: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80064890;
    }
    // 0x80064878: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8006487C: lw          $a0, -0x2920($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2920);
    // 0x80064880: jal         0x800653C4
    // 0x80064884: nop

    func_800653C4(rdram, ctx);
        goto after_1;
    // 0x80064884: nop

    after_1:
    // 0x80064888: b           L_80064894
    // 0x8006488C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80064894;
    // 0x8006488C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80064890:
    // 0x80064890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80064894:
    // 0x80064894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006489C: jr          $ra
    // 0x800648A0: nop

    return;
    // 0x800648A0: nop

;}
RECOMP_FUNC void func_800648A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // Audio stubs now implemented - proceeding with SN64 audio initialization.
    fprintf(stderr, "[AUDIO-INIT] func_800648A4 STARTING (SN64 stubs active)\n");
    fflush(stderr);
    // 0x800648A4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    fprintf(stderr, "[AUDIO-INIT] sp adjusted to 0x%08X\n", (unsigned)ctx->r29); fflush(stderr);
    // 0x800648A8: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800648AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    fprintf(stderr, "[AUDIO-INIT] saved a0,ra ok\n"); fflush(stderr);
    // 0x800648B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800648B4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800648B8: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x800648BC: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800648C0: sw          $t6, 0x59CC($at)
    MEM_W(0X59CC, ctx->r1) = ctx->r14;
    fprintf(stderr, "[AUDIO-INIT] all stores done, calling osCreateThread\n"); fflush(stderr);
    // 0x800648C4: jal         0x8013E750
    // 0x800648C8: addiu       $a0, $a0, 0x4830
    ctx->r4 = ADD32(ctx->r4, 0X4830);
    fprintf(stderr, "[AUDIO] calling stub_8013E750 (osCreateThread)\n"); fflush(stderr);
    stub_8013E750(rdram, ctx);
        goto after_0;
    // 0x800648C8: addiu       $a0, $a0, 0x4830
    ctx->r4 = ADD32(ctx->r4, 0X4830);
    after_0:
    fprintf(stderr, "[AUDIO] after osCreateThread, calling func_80065364(0x30D40)\n"); fflush(stderr);
    // 0x800648CC: lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // 0x800648D0: jal         0x80065364
    // 0x800648D4: ori         $a0, $a0, 0xD40
    ctx->r4 = ctx->r4 | 0XD40;
    func_80065364(rdram, ctx);
        goto after_1;
    // 0x800648D4: ori         $a0, $a0, 0xD40
    ctx->r4 = ctx->r4 | 0XD40;
    after_1:
    fprintf(stderr, "[AUDIO] after alloc(0x30D40), ret=0x%08X, calling DMA\n", (unsigned)ctx->r2); fflush(stderr);
    // 0x800648D8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800648DC: addiu       $v1, $v1, -0x2810
    ctx->r3 = ADD32(ctx->r3, -0X2810);
    // 0x800648E0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800648E4: lui         $a2, 0x3
    ctx->r6 = S32(0X3 << 16);
    // 0x800648E8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800648EC: ori         $a2, $a2, 0xD40
    ctx->r6 = ctx->r6 | 0XD40;
    // 0x800648F0: addiu       $a0, $a0, -0x5E0
    ctx->r4 = ADD32(ctx->r4, -0X5E0);
    // 0x800648F4: jal         0x8006D9C0
    // 0x800648F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8006D9C0(rdram, ctx);
        goto after_2;
    // 0x800648F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    fprintf(stderr, "[AUDIO] after DMA, calling alloc(0x186A0)\n"); fflush(stderr);
    // 0x800648FC: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x80064900: jal         0x80065364
    // 0x80064904: ori         $a0, $a0, 0x86A0
    ctx->r4 = ctx->r4 | 0X86A0;
    func_80065364(rdram, ctx);
        goto after_3;
    // 0x80064904: ori         $a0, $a0, 0x86A0
    ctx->r4 = ctx->r4 | 0X86A0;
    after_3:
    fprintf(stderr, "[AUDIO] after alloc(0x186A0), ret=0x%08X\n", (unsigned)ctx->r2); fflush(stderr);
    // 0x80064908: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8006490C: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    fprintf(stderr, "[AUDIO] about to store at 0x%08X\n", (unsigned)(int32_t)(ctx->r1 + (-0x2920))); fflush(stderr);
    // 0x80064910: sw          $v0, -0x2920($at)
    MEM_W(-0X2920, ctx->r1) = ctx->r2;
    fprintf(stderr, "[AUDIO] store done\n"); fflush(stderr);
    // 0x80064914: jal         0x8013E788
    // 0x80064918: addiu       $a0, $a0, 0x4840
    ctx->r4 = ADD32(ctx->r4, 0X4840);
    fprintf(stderr, "[AUDIO] calling osStartThread\n"); fflush(stderr);
    stub_8013E788(rdram, ctx);
        goto after_4;
    // 0x80064918: addiu       $a0, $a0, 0x4840
    ctx->r4 = ADD32(ctx->r4, 0X4840);
    after_4:
    fprintf(stderr, "[AUDIO] after osStartThread\n"); fflush(stderr);
    // 0x8006491C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80064920: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80064924: div         $zero, $t8, $t7
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r15)));
    // 0x80064928: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x8006492C: lui         $t3, 0x92
    ctx->r11 = S32(0X92 << 16);
    // 0x80064930: addiu       $t0, $zero, 0x5622
    ctx->r8 = ADD32(0, 0X5622);
    // 0x80064934: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x80064938: addiu       $t2, $t2, -0x5E0
    ctx->r10 = ADD32(ctx->r10, -0X5E0);
    // 0x8006493C: addiu       $t3, $t3, -0x53C0
    ctx->r11 = ADD32(ctx->r11, -0X53C0);
    // 0x80064940: bne         $t7, $zero, L_8006494C
    if (ctx->r15 != 0) {
        // 0x80064944: nop
    
            goto L_8006494C;
    }
    // 0x80064944: nop

    // 0x80064948: break       7
    do_break(2147895624);
L_8006494C:
    // 0x8006494C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80064950: bne         $t7, $at, L_80064964
    if (ctx->r15 != ctx->r1) {
        // 0x80064954: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80064964;
    }
    // 0x80064954: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80064958: bne         $t8, $at, L_80064964
    if (ctx->r24 != ctx->r1) {
        // 0x8006495C: nop
    
            goto L_80064964;
    }
    // 0x8006495C: nop

    // 0x80064960: break       6
    do_break(2147895648);
L_80064964:
    // 0x80064964: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x80064968: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x8006496C: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x80064970: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80064974: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x80064978: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x8006497C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80064980: mflo        $t9
    ctx->r25 = lo;
    // 0x80064984: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80064988: nop

    // 0x8006498C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80064990: jal         0x801378DC
    // 0x80064994: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    fprintf(stderr, "[AUDIO] calling stub_801378DC (alInit)\n"); fflush(stderr);
    stub_801378DC(rdram, ctx);
        goto after_5;
    // 0x80064994: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_5:
    fprintf(stderr, "[AUDIO] after alInit\n"); fflush(stderr);
    // 0x80064998: lui         $a0, 0x90
    ctx->r4 = S32(0X90 << 16);
    // 0x8006499C: jal         0x80138C30
    // 0x800649A0: addiu       $a0, $a0, 0x6290
    ctx->r4 = ADD32(ctx->r4, 0X6290);
    stub_80138C30(rdram, ctx);
        goto after_6;
    // 0x800649A0: addiu       $a0, $a0, 0x6290
    ctx->r4 = ADD32(ctx->r4, 0X6290);
    after_6:
    fprintf(stderr, "[AUDIO] after stub_80138C30, ret=0x%08X\n", (unsigned)ctx->r2); fflush(stderr);
    // 0x800649A4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800649A8: jal         0x80065364
    // 0x800649AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80065364(rdram, ctx);
        goto after_7;
    // 0x800649AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    fprintf(stderr, "[AUDIO] after alloc for ctl, ret=0x%08X\n", (unsigned)ctx->r2); fflush(stderr);
    // 0x800649B0: lui         $a0, 0x90
    ctx->r4 = S32(0X90 << 16);
    // 0x800649B4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800649B8: addiu       $a0, $a0, 0x6290
    ctx->r4 = ADD32(ctx->r4, 0X6290);
    // 0x800649BC: jal         0x80138EFC
    // 0x800649C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    stub_80138EFC(rdram, ctx);
        goto after_8;
    // 0x800649C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    fprintf(stderr, "[AUDIO] after stub_80138EFC (DMA ctl)\n"); fflush(stderr);
    // 0x800649C4: jal         0x80138934
    // 0x800649C8: nop

    stub_80138934(rdram, ctx);
        goto after_9;
    // 0x800649C8: nop

    after_9:
    fprintf(stderr, "[AUDIO] after stub_80138934 (DMA wait), ret=0x%08X\n", (unsigned)ctx->r2); fflush(stderr);
    // 0x800649CC: lui         $a1, 0x91
    ctx->r5 = S32(0X91 << 16);
    // 0x800649D0: addiu       $a1, $a1, 0x72D0
    ctx->r5 = ADD32(ctx->r5, 0X72D0);
    // 0x800649D4: jal         0x801430E0
    // 0x800649D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    stub_801430E0(rdram, ctx);
        goto after_10;
    // 0x800649D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x800649DC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800649E0: jal         0x80065364
    // 0x800649E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80065364(rdram, ctx);
        goto after_11;
    // 0x800649E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x800649E8: jal         0x80138934
    // 0x800649EC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    stub_80138934(rdram, ctx);
        goto after_12;
    // 0x800649EC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_12:
    // 0x800649F0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800649F4: lui         $a1, 0x91
    ctx->r5 = S32(0X91 << 16);
    // 0x800649F8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800649FC: addiu       $a1, $a1, 0x72D0
    ctx->r5 = ADD32(ctx->r5, 0X72D0);
    // 0x80064A00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80064A04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80064A08: jal         0x801431A4
    // 0x80064A0C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    stub_801431A4(rdram, ctx);
        goto after_13;
    // 0x80064A0C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_13:
    // 0x80064A10: jal         0x80142BCC
    // 0x80064A14: nop

    stub_80142BCC(rdram, ctx);
        goto after_14;
    // 0x80064A14: nop

    after_14:
    // 0x80064A18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064A1C: jal         0x801436F0
    // 0x80064A20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    stub_801436F0(rdram, ctx);
        goto after_15;
    // 0x80064A20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_15:
    // 0x80064A24: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80064A28: addiu       $a2, $a2, -0x5E0
    ctx->r6 = ADD32(ctx->r6, -0X5E0);
    // 0x80064A2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064A30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80064A34: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80064A38: jal         0x8006DA00
    // 0x80064A3C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    alHeapDBAlloc(rdram, ctx);
        goto after_16;
    // 0x80064A3C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_16:
    // 0x80064A40: jal         0x80142BCC
    // 0x80064A44: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    stub_80142BCC(rdram, ctx);
        goto after_17;
    // 0x80064A44: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_17:
    // 0x80064A48: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80064A4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064A50: jal         0x8014376C
    // 0x80064A54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    stub_8014376C(rdram, ctx);
        goto after_18;
    // 0x80064A54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_18:
    // 0x80064A58: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80064A5C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80064A60: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80064A64: addiu       $a2, $a2, -0x5E0
    ctx->r6 = ADD32(ctx->r6, -0X5E0);
    // 0x80064A68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064A6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80064A70: jal         0x8006DA00
    // 0x80064A74: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_19;
    // 0x80064A74: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_19:
    // 0x80064A78: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80064A7C: addiu       $v1, $v1, -0x5E8
    ctx->r3 = ADD32(ctx->r3, -0X5E8);
    // 0x80064A80: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80064A84: addiu       $t8, $v0, 0x10
    ctx->r24 = ADD32(ctx->r2, 0X10);
    // 0x80064A88: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80064A8C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80064A90: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80064A94: addiu       $a1, $a1, -0x7B8
    ctx->r5 = ADD32(ctx->r5, -0X7B8);
    // 0x80064A98: addiu       $a0, $a0, -0x7D0
    ctx->r4 = ADD32(ctx->r4, -0X7D0);
    // 0x80064A9C: jal         0x800697E0
    // 0x80064AA0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_20;
    // 0x80064AA0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_20:
    // 0x80064AA4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80064AA8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80064AAC: addiu       $a1, $a1, -0x7F0
    ctx->r5 = ADD32(ctx->r5, -0X7F0);
    // 0x80064AB0: addiu       $a0, $a0, -0x808
    ctx->r4 = ADD32(ctx->r4, -0X808);
    // 0x80064AB4: jal         0x800697E0
    // 0x80064AB8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_21;
    // 0x80064AB8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_21:
    // 0x80064ABC: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80064AC0: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80064AC4: addiu       $t7, $t7, -0x808
    ctx->r15 = ADD32(ctx->r15, -0X808);
    // 0x80064AC8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80064ACC: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80064AD0: addiu       $a2, $a2, 0x4B1C
    ctx->r6 = ADD32(ctx->r6, 0X4B1C);
    // 0x80064AD4: addiu       $a0, $a0, -0x798
    ctx->r4 = ADD32(ctx->r4, -0X798);
    // 0x80064AD8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80064ADC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80064AE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80064AE4: jal         0x800693B0
    // 0x80064AE8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    osCreateThread_recomp(rdram, ctx);
        goto after_22;
    // 0x80064AE8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_22:
    // 0x80064AEC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80064AF0: jal         0x80069500
    // 0x80064AF4: addiu       $a0, $a0, -0x798
    ctx->r4 = ADD32(ctx->r4, -0X798);
    osStartThread_recomp(rdram, ctx);
        goto after_23;
    // 0x80064AF4: addiu       $a0, $a0, -0x798
    ctx->r4 = ADD32(ctx->r4, -0X798);
    after_23:
    // 0x80064AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80064AFC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80064B00: jr          $ra
    // 0x80064B04: nop

    return;
    // 0x80064B04: nop

;}
