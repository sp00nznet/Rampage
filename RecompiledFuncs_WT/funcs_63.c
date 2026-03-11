#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80064B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B08: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80064B0C: lhu         $t6, -0x7840($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X7840);
    // 0x80064B10: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80064B14: jr          $ra
    // 0x80064B18: sh          $t6, -0x783E($at)
    MEM_H(-0X783E, ctx->r1) = ctx->r14;
    return;
    // 0x80064B18: sh          $t6, -0x783E($at)
    MEM_H(-0X783E, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80064B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B1C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80064B20: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80064B24: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80064B28: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80064B2C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80064B30: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80064B34: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80064B38: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80064B3C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80064B40: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80064B44: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80064B48: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80064B4C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80064B50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80064B54: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80064B58: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80064B5C: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80064B60: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80064B64: addiu       $a2, $a2, -0x808
    ctx->r6 = ADD32(ctx->r6, -0X808);
    // 0x80064B68: addiu       $a0, $a0, 0x2160
    ctx->r4 = ADD32(ctx->r4, 0X2160);
    // 0x80064B6C: jal         0x80060DC0
    // 0x80064B70: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80060DC0(rdram, ctx);
        goto after_0;
    // 0x80064B70: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x80064B74: lui         $fp, 0x8011
    ctx->r30 = S32(0X8011 << 16);
    // 0x80064B78: lui         $s7, 0x8008
    ctx->r23 = S32(0X8008 << 16);
    // 0x80064B7C: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80064B80: addiu       $s6, $s6, 0x59C0
    ctx->r22 = ADD32(ctx->r22, 0X59C0);
    // 0x80064B84: addiu       $s7, $s7, 0x59C4
    ctx->r23 = ADD32(ctx->r23, 0X59C4);
    // 0x80064B88: addiu       $fp, $fp, -0x7D0
    ctx->r30 = ADD32(ctx->r30, -0X7D0);
    // 0x80064B8C: addiu       $s5, $sp, 0x54
    ctx->r21 = ADD32(ctx->r29, 0X54);
L_80064B90:
    // 0x80064B90: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80064B94: addiu       $a0, $a0, -0x808
    ctx->r4 = ADD32(ctx->r4, -0X808);
    // 0x80064B98: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80064B9C: jal         0x80069CF0
    // 0x80064BA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80064BA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80064BA4: jal         0x80064B08
    // 0x80064BA8: nop

    func_80064B08(rdram, ctx);
        goto after_2;
    // 0x80064BA8: nop

    after_2:
    // 0x80064BAC: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x80064BB0: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80064BB4: bne         $t6, $zero, L_80064CFC
    if (ctx->r14 != 0) {
        // 0x80064BB8: lui         $t8, 0x800F
        ctx->r24 = S32(0X800F << 16);
            goto L_80064CFC;
    }
    // 0x80064BB8: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80064BBC: addiu       $t8, $t8, 0x2160
    ctx->r24 = ADD32(ctx->r24, 0X2160);
    // 0x80064BC0: bne         $t7, $t8, L_80064CBC
    if (ctx->r15 != ctx->r24) {
        // 0x80064BC4: slti        $at, $s2, 0x3
        ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
            goto L_80064CBC;
    }
    // 0x80064BC4: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x80064BC8: beq         $at, $zero, L_80064C9C
    if (ctx->r1 == 0) {
        // 0x80064BCC: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_80064C9C;
    }
    // 0x80064BCC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80064BD0: jal         0x8006A690
    // 0x80064BD4: nop

    osGetTime_recomp(rdram, ctx);
        goto after_3;
    // 0x80064BD4: nop

    after_3:
    // 0x80064BD8: jal         0x80137FEC
    // 0x80064BDC: sw          $v1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r3;
    stub_80137FEC(rdram, ctx);
        goto after_4;
    // 0x80064BDC: sw          $v1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r3;
    after_4:
    // 0x80064BE0: beq         $v0, $zero, L_80064CFC
    if (ctx->r2 == 0) {
        // 0x80064BE4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80064CFC;
    }
    // 0x80064BE4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80064BE8: jal         0x8006A690
    // 0x80064BEC: nop

    osGetTime_recomp(rdram, ctx);
        goto after_5;
    // 0x80064BEC: nop

    after_5:
    // 0x80064BF0: lw          $t0, 0x0($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X0);
    // 0x80064BF4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80064BF8: subu        $t5, $v1, $t0
    ctx->r13 = SUB32(ctx->r3, ctx->r8);
    // 0x80064BFC: sw          $t5, 0x59C8($at)
    MEM_W(0X59C8, ctx->r1) = ctx->r13;
    // 0x80064C00: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80064C04: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x80064C08: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80064C0C: addiu       $t8, $t8, -0x2918
    ctx->r24 = ADD32(ctx->r24, -0X2918);
    // 0x80064C10: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80064C14: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80064C18: addiu       $t0, $s1, 0x3C
    ctx->r8 = ADD32(ctx->r17, 0X3C);
    // 0x80064C1C: or          $t2, $s1, $zero
    ctx->r10 = ctx->r17 | 0;
    // 0x80064C20: addiu       $a0, $a0, 0x2160
    ctx->r4 = ADD32(ctx->r4, 0X2160);
    // 0x80064C24: mfhi        $t6
    ctx->r14 = hi;
    // 0x80064C28: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80064C2C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80064C30: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80064C34: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80064C38: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80064C3C: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80064C40: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80064C44: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x80064C48: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80064C4C: sw          $fp, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r30;
    // 0x80064C50: or          $t3, $s0, $zero
    ctx->r11 = ctx->r16 | 0;
L_80064C54:
    // 0x80064C54: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80064C58: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80064C5C: sw          $at, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r1;
    // 0x80064C60: lw          $at, -0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X8);
    // 0x80064C64: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80064C68: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x80064C6C: lw          $at, -0x4($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X4);
    // 0x80064C70: bne         $t2, $t0, L_80064C54
    if (ctx->r10 != ctx->r8) {
        // 0x80064C74: sw          $at, 0xC($t3)
        MEM_W(0XC, ctx->r11) = ctx->r1;
            goto L_80064C54;
    }
    // 0x80064C74: sw          $at, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r1;
    // 0x80064C78: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80064C7C: jal         0x80060BDC
    // 0x80064C80: sw          $at, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r1;
    func_80060BDC(rdram, ctx);
        goto after_6;
    // 0x80064C80: sw          $at, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r1;
    after_6:
    // 0x80064C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80064C88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80064C8C: jal         0x8006A090
    // 0x80064C90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80064C90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80064C94: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80064C98: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_80064C9C:
    // 0x80064C9C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80064CA0: jal         0x80069CF0
    // 0x80064CA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x80064CA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80064CA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80064CAC: beq         $v0, $at, L_80064CFC
    if (ctx->r2 == ctx->r1) {
        // 0x80064CB0: nop
    
            goto L_80064CFC;
    }
    // 0x80064CB0: nop

    // 0x80064CB4: b           L_80064CFC
    // 0x80064CB8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_80064CFC;
    // 0x80064CB8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80064CBC:
    // 0x80064CBC: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80064CC0: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x80064CC4: lw          $t1, 0x0($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X0);
    // 0x80064CC8: addiu       $t4, $t4, 0x2162
    ctx->r12 = ADD32(ctx->r12, 0X2162);
    // 0x80064CCC: bne         $t4, $t1, L_80064CE0
    if (ctx->r12 != ctx->r9) {
        // 0x80064CD0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80064CE0;
    }
    // 0x80064CD0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80064CD4: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x80064CD8: b           L_80064CFC
    // 0x80064CDC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80064CFC;
    // 0x80064CDC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80064CE0:
    // 0x80064CE0: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80064CE4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80064CE8: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80064CEC: nop

    // 0x80064CF0: bne         $t8, $at, L_80064CFC
    if (ctx->r24 != ctx->r1) {
        // 0x80064CF4: nop
    
            goto L_80064CFC;
    }
    // 0x80064CF4: nop

    // 0x80064CF8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80064CFC:
    // 0x80064CFC: beq         $s3, $zero, L_80064B90
    if (ctx->r19 == 0) {
        // 0x80064D00: nop
    
            goto L_80064B90;
    }
    // 0x80064D00: nop

    // 0x80064D04: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80064D08: addiu       $a0, $a0, 0x2160
    ctx->r4 = ADD32(ctx->r4, 0X2160);
    // 0x80064D0C: jal         0x80060E14
    // 0x80064D10: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80060E14(rdram, ctx);
        goto after_9;
    // 0x80064D10: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_9:
    // 0x80064D14: jal         0x8013858C
    // 0x80064D18: nop

    stub_8013858C(rdram, ctx);
        goto after_10;
    // 0x80064D18: nop

    after_10:
    // 0x80064D1C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80064D20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064D24: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80064D28: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80064D2C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80064D30: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80064D34: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80064D38: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80064D3C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80064D40: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80064D44: jr          $ra
    // 0x80064D48: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80064D48: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80064D4C: nop

;}
RECOMP_FUNC void func_80064D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064D50: lui         $t7, 0x803F
    ctx->r15 = S32(0X803F << 16);
    // 0x80064D54: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80064D58: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80064D5C: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x80064D60: ori         $t7, $t7, 0xFE00
    ctx->r15 = ctx->r15 | 0XFE00;
    // 0x80064D64: addiu       $t0, $t0, -0x5A4
    ctx->r8 = ADD32(ctx->r8, -0X5A4);
    // 0x80064D68: addiu       $a3, $a3, -0x5A8
    ctx->r7 = ADD32(ctx->r7, -0X5A8);
    // 0x80064D6C: addiu       $t6, $t6, 0x4CC0
    ctx->r14 = ADD32(ctx->r14, 0X4CC0);
    // 0x80064D70: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80064D74: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80064D78: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80064D7C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80064D80: addiu       $a2, $a2, -0x59C
    ctx->r6 = ADD32(ctx->r6, -0X59C);
    // FALLTHROUGH FIX: func_80064D50 falls through to func_80064D84
    func_80064D84(rdram, ctx);
;}
RECOMP_FUNC void func_80064D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064D84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064D88: subu        $a1, $t7, $t6
    ctx->r5 = SUB32(ctx->r15, ctx->r14);
    // 0x80064D8C: sw          $t7, -0x5A0($at)
    MEM_W(-0X5A0, ctx->r1) = ctx->r15;
    // 0x80064D90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064D94: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80064D98: addiu       $t8, $a1, -0x8
    ctx->r24 = ADD32(ctx->r5, -0X8);
    // 0x80064D9C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80064DA0: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80064DA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064DA8: jal         0x80064DE8
    // 0x80064DAC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    func_80064DE8(rdram, ctx);
        goto after_0;
    // 0x80064DAC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_0:
    // 0x80064DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064DB8: jr          $ra
    // 0x80064DBC: nop

    return;
    // 0x80064DBC: nop

;}
RECOMP_FUNC void func_80064DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064DC0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80064DC4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80064DC8: sw          $zero, -0x5A8($at)
    MEM_W(-0X5A8, ctx->r1) = 0;
    // 0x80064DCC: addiu       $v0, $v0, -0x5A4
    ctx->r2 = ADD32(ctx->r2, -0X5A4);
    // 0x80064DD0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80064DD4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80064DD8: sw          $zero, -0x5A0($at)
    MEM_W(-0X5A0, ctx->r1) = 0;
    // 0x80064DDC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80064DE0: jr          $ra
    // 0x80064DE4: sw          $zero, -0x59C($at)
    MEM_W(-0X59C, ctx->r1) = 0;
    return;
    // 0x80064DE4: sw          $zero, -0x59C($at)
    MEM_W(-0X59C, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80064DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064DE8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80064DEC: addiu       $v1, $v1, 0x59D8
    ctx->r3 = ADD32(ctx->r3, 0X59D8);
    // 0x80064DF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80064DF4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80064DF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80064DFC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80064E00: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80064E04: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80064E08: jr          $ra
    // 0x80064E0C: sw          $a0, -0x5D0($at)
    MEM_W(-0X5D0, ctx->r1) = ctx->r4;
    return;
    // 0x80064E0C: sw          $a0, -0x5D0($at)
    MEM_W(-0X5D0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80064E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064E10: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80064E14: addiu       $v0, $v0, 0x59D8
    ctx->r2 = ADD32(ctx->r2, 0X59D8);
    // 0x80064E18: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80064E1C: nop

    // 0x80064E20: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80064E24: jr          $ra
    // 0x80064E28: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x80064E28: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_80064E2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064E2C: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80064E30: addiu       $a2, $a2, -0x5A0
    ctx->r6 = ADD32(ctx->r6, -0X5A0);
    // 0x80064E34: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80064E38: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80064E3C: lw          $v1, -0x5A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A4);
    // 0x80064E40: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80064E44: bne         $v0, $v1, L_80064E5C
    if (ctx->r2 != ctx->r3) {
            // 0x80064E48: nop

    func_80064E5C(rdram, ctx);
    return;
    }
    // 0x80064E48: nop

    // 0x80064E4C: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x80064E50: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80064E54: jr          $ra
    // 0x80064E58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80064E58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80064E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064E5C: beq         $at, $zero, L_80064E74
    if (ctx->r1 == 0) {
            // 0x80064E60: nop

    func_80064E74(rdram, ctx);
    return;
    }
    // 0x80064E60: nop

    // 0x80064E64: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80064E68: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x80064E6C: jr          $ra
    // 0x80064E70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80064E70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80064E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064E74: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80064E78: nop

    // 0x80064E7C: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80064E80: beq         $at, $zero, L_80064EA0
    if (ctx->r1 == 0) {
        // 0x80064E84: nop
    
            goto L_80064EA0;
    }
    // 0x80064E84: nop

L_80064E88:
    // 0x80064E88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80064E8C: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x80064E90: nop

    // 0x80064E94: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80064E98: bne         $at, $zero, L_80064E88
    if (ctx->r1 != 0) {
        // 0x80064E9C: nop
    
            goto L_80064E88;
    }
    // 0x80064E9C: nop

L_80064EA0:
    // 0x80064EA0: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80064EA4: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80064EA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80064EAC: jr          $ra
    // 0x80064EB0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x80064EB0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_80064EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064EB4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80064EB8: addiu       $v1, $v1, -0x5A0
    ctx->r3 = ADD32(ctx->r3, -0X5A0);
    // 0x80064EBC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80064EC0: nop

    // 0x80064EC4: bne         $v0, $a0, L_80064ED8
    if (ctx->r2 != ctx->r4) {
            // 0x80064EC8: nop

    func_80064ED8(rdram, ctx);
    return;
    }
    // 0x80064EC8: nop

    // 0x80064ECC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80064ED0: jr          $ra
    // 0x80064ED4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    return;
    // 0x80064ED4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
;}
RECOMP_FUNC void func_80064ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064ED8: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80064EDC: nop

    // 0x80064EE0: beq         $a0, $v1, L_80064EFC
    if (ctx->r4 == ctx->r3) {
        // 0x80064EE4: nop
    
            goto L_80064EFC;
    }
    // 0x80064EE4: nop

L_80064EE8:
    // 0x80064EE8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80064EEC: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x80064EF0: nop

    // 0x80064EF4: bne         $a0, $v1, L_80064EE8
    if (ctx->r4 != ctx->r3) {
        // 0x80064EF8: nop
    
            goto L_80064EE8;
    }
    // 0x80064EF8: nop

L_80064EFC:
    // 0x80064EFC: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x80064F00: nop

    // 0x80064F04: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80064F08: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80064F0C: jr          $ra
    // 0x80064F10: nop

    return;
    // 0x80064F10: nop

;}
RECOMP_FUNC void func_80064F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064F14: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80064F18: addiu       $a1, $a1, -0x59C
    ctx->r5 = ADD32(ctx->r5, -0X59C);
    // 0x80064F1C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80064F20: nop

    // 0x80064F24: bne         $v0, $zero, L_80064F3C
    if (ctx->r2 != 0) {
            // 0x80064F28: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    func_80064F3C(rdram, ctx);
    return;
    }
    // 0x80064F28: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80064F2C: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x80064F30: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80064F34: jr          $ra
    // 0x80064F38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80064F38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80064F3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064F3C: beq         $at, $zero, L_80064F54
    if (ctx->r1 == 0) {
            // 0x80064F40: nop

    func_80064F54(rdram, ctx);
    return;
    }
    // 0x80064F40: nop

    // 0x80064F44: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80064F48: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x80064F4C: jr          $ra
    // 0x80064F50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80064F50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80064F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064F54: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80064F58: nop

    // 0x80064F5C: beq         $a1, $zero, L_80064F88
    if (ctx->r5 == 0) {
        // 0x80064F60: sltu        $at, $a1, $a0
        ctx->r1 = ctx->r5 < ctx->r4 ? 1 : 0;
            goto L_80064F88;
    }
    // 0x80064F60: sltu        $at, $a1, $a0
    ctx->r1 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x80064F64: beq         $at, $zero, L_80064F88
    if (ctx->r1 == 0) {
        // 0x80064F68: nop
    
            goto L_80064F88;
    }
    // 0x80064F68: nop

L_80064F6C:
    // 0x80064F6C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80064F70: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    // 0x80064F74: nop

    // 0x80064F78: beq         $a1, $zero, L_80064F88
    if (ctx->r5 == 0) {
        // 0x80064F7C: sltu        $at, $a1, $a0
        ctx->r1 = ctx->r5 < ctx->r4 ? 1 : 0;
            goto L_80064F88;
    }
    // 0x80064F7C: sltu        $at, $a1, $a0
    ctx->r1 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x80064F80: bne         $at, $zero, L_80064F6C
    if (ctx->r1 != 0) {
        // 0x80064F84: nop
    
            goto L_80064F6C;
    }
    // 0x80064F84: nop

L_80064F88:
    // 0x80064F88: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80064F8C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80064F90: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80064F94: jr          $ra
    // 0x80064F98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80064F98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80064F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064F9C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80064FA0: addiu       $v1, $v1, -0x59C
    ctx->r3 = ADD32(ctx->r3, -0X59C);
    // 0x80064FA4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80064FA8: nop

    // 0x80064FAC: bne         $v0, $a0, L_80064FC0
    if (ctx->r2 != ctx->r4) {
            // 0x80064FB0: nop

    func_80064FC0(rdram, ctx);
    return;
    }
    // 0x80064FB0: nop

    // 0x80064FB4: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80064FB8: jr          $ra
    // 0x80064FBC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    return;
    // 0x80064FBC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
;}
RECOMP_FUNC void func_80064FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064FC0: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80064FC4: nop

    // 0x80064FC8: beq         $a0, $v1, L_80064FE4
    if (ctx->r4 == ctx->r3) {
        // 0x80064FCC: nop
    
            goto L_80064FE4;
    }
    // 0x80064FCC: nop

L_80064FD0:
    // 0x80064FD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80064FD4: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x80064FD8: nop

    // 0x80064FDC: bne         $a0, $v1, L_80064FD0
    if (ctx->r4 != ctx->r3) {
        // 0x80064FE0: nop
    
            goto L_80064FD0;
    }
    // 0x80064FE0: nop

L_80064FE4:
    // 0x80064FE4: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x80064FE8: nop

    // 0x80064FEC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80064FF0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80064FF4: jr          $ra
    // 0x80064FF8: nop

    return;
    // 0x80064FF8: nop

;}
RECOMP_FUNC void func_80064FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064FFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80065000: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80065004: addiu       $v1, $a0, 0x7
    ctx->r3 = ADD32(ctx->r4, 0X7);
    // 0x80065008: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8006500C: and         $a3, $v1, $at
    ctx->r7 = ctx->r3 & ctx->r1;
    // 0x80065010: sltiu       $at, $a3, 0x10
    ctx->r1 = ctx->r7 < 0X10 ? 1 : 0;
    // 0x80065014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065018: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8006501C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80065020: beq         $at, $zero, L_8006502C
    if (ctx->r1 == 0) {
        // 0x80065024: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_8006502C;
    }
    // 0x80065024: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80065028: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
L_8006502C:
    // 0x8006502C: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80065030: lw          $t7, 0x59D8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X59D8);
    // 0x80065034: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80065038: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006503C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80065040: lw          $t9, -0x5D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5D0);
    // 0x80065044: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80065048: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006504C: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80065050: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x80065054: lw          $t9, 0x59D0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X59D0);
    // 0x80065058: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8006505C: jalr        $t9
    // 0x80065060: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80065060: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80065064: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80065068: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8006506C: beq         $v0, $zero, L_8006511C
    if (ctx->r2 == 0) {
        // 0x80065070: lui         $t8, 0x8008
        ctx->r24 = S32(0X8008 << 16);
            goto L_8006511C;
    }
    // 0x80065070: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80065074: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80065078: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8006507C: jal         0x80064F9C
    // 0x80065080: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80064F9C(rdram, ctx);
        goto after_1;
    // 0x80065080: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80065084: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80065088: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8006508C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80065090: lbu         $t2, 0x37($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X37);
    // 0x80065094: subu        $v0, $t1, $a3
    ctx->r2 = SUB32(ctx->r9, ctx->r7);
    // 0x80065098: sltiu       $at, $v0, 0x10
    ctx->r1 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x8006509C: beq         $at, $zero, L_800650AC
    if (ctx->r1 == 0) {
        // 0x800650A0: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800650AC;
    }
    // 0x800650A0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800650A4: b           L_800650E4
    // 0x800650A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800650E4;
    // 0x800650A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800650AC:
    // 0x800650AC: beq         $t2, $zero, L_800650C8
    if (ctx->r10 == 0) {
        // 0x800650B0: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800650C8;
    }
    // 0x800650B0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800650B4: addiu       $t3, $v0, -0x8
    ctx->r11 = ADD32(ctx->r2, -0X8);
    // 0x800650B8: addu        $a2, $a1, $t3
    ctx->r6 = ADD32(ctx->r5, ctx->r11);
    // 0x800650BC: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x800650C0: b           L_800650E0
    // 0x800650C4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
        goto L_800650E0;
    // 0x800650C4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_800650C8:
    // 0x800650C8: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800650CC: addu        $a1, $a1, $a3
    ctx->r5 = ADD32(ctx->r5, ctx->r7);
    // 0x800650D0: subu        $t6, $t5, $a3
    ctx->r14 = SUB32(ctx->r13, ctx->r7);
    // 0x800650D4: addiu       $t7, $t6, -0x8
    ctx->r15 = ADD32(ctx->r14, -0X8);
    // 0x800650D8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800650DC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_800650E0:
    // 0x800650E0: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
L_800650E4:
    // 0x800650E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800650E8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800650EC: jal         0x80064E2C
    // 0x800650F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80064E2C(rdram, ctx);
        goto after_2;
    // 0x800650F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_2:
    // 0x800650F4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800650F8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800650FC: beq         $a1, $zero, L_80065114
    if (ctx->r5 == 0) {
        // 0x80065100: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80065114;
    }
    // 0x80065100: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80065104: jal         0x80064F14
    // 0x80065108: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80064F14(rdram, ctx);
        goto after_3;
    // 0x80065108: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_3:
    // 0x8006510C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80065110: nop

L_80065114:
    // 0x80065114: b           L_80065140
    // 0x80065118: addiu       $v1, $a2, 0x8
    ctx->r3 = ADD32(ctx->r6, 0X8);
        goto L_80065140;
    // 0x80065118: addiu       $v1, $a2, 0x8
    ctx->r3 = ADD32(ctx->r6, 0X8);
L_8006511C:
    // 0x8006511C: lw          $t8, 0x59D4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X59D4);
    // 0x80065120: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80065124: bne         $t8, $zero, L_8006513C
    if (ctx->r24 != 0) {
        // 0x80065128: addiu       $a0, $a0, -0x25A8
        ctx->r4 = ADD32(ctx->r4, -0X25A8);
            goto L_8006513C;
    }
    // 0x80065128: addiu       $a0, $a0, -0x25A8
    ctx->r4 = ADD32(ctx->r4, -0X25A8);
    // 0x8006512C: jal         0x800653EC
    // 0x80065130: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_800653EC(rdram, ctx);
        goto after_4;
    // 0x80065130: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_4:
L_80065134:
    // 0x80065134: b           L_80065134
    pause_self(rdram);
    // 0x80065138: nop

L_8006513C:
    // 0x8006513C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80065140:
    // 0x80065140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065144: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80065148: jr          $ra
    // 0x8006514C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8006514C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80065150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065150: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80065154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065158: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006515C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80065160: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80065164: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80065168: beq         $a0, $zero, L_80065220
    if (ctx->r4 == 0) {
        // 0x8006516C: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80065220;
    }
    // 0x8006516C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80065170: addiu       $s0, $a0, -0x8
    ctx->r16 = ADD32(ctx->r4, -0X8);
    // 0x80065174: jal         0x80064EB4
    // 0x80065178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80064EB4(rdram, ctx);
        goto after_0;
    // 0x80065178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006517C: jal         0x80064F14
    // 0x80065180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80064F14(rdram, ctx);
        goto after_1;
    // 0x80065180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80065184: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80065188: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8006518C: addu        $a1, $s0, $t6
    ctx->r5 = ADD32(ctx->r16, ctx->r14);
    // 0x80065190: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80065194: bne         $a1, $t7, L_800651D4
    if (ctx->r5 != ctx->r15) {
        // 0x80065198: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800651D4;
    }
    // 0x80065198: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8006519C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800651A0: jal         0x80064F9C
    // 0x800651A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80064F9C(rdram, ctx);
        goto after_2;
    // 0x800651A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x800651A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800651AC: jal         0x80064F9C
    // 0x800651B0: nop

    func_80064F9C(rdram, ctx);
        goto after_3;
    // 0x800651B0: nop

    after_3:
    // 0x800651B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800651B8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800651BC: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800651C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800651C4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800651C8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800651CC: jal         0x80064F14
    // 0x800651D0: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    func_80064F14(rdram, ctx);
        goto after_4;
    // 0x800651D0: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    after_4:
L_800651D4:
    // 0x800651D4: beq         $s1, $zero, L_80065224
    if (ctx->r17 == 0) {
        // 0x800651D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80065224;
    }
    // 0x800651D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800651DC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800651E0: nop

    // 0x800651E4: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x800651E8: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800651EC: bne         $s0, $t4, L_80065224
    if (ctx->r16 != ctx->r12) {
        // 0x800651F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80065224;
    }
    // 0x800651F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800651F4: jal         0x80064F9C
    // 0x800651F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80064F9C(rdram, ctx);
        goto after_5;
    // 0x800651F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800651FC: jal         0x80064F9C
    // 0x80065200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80064F9C(rdram, ctx);
        goto after_6;
    // 0x80065200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80065204: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80065208: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006520C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80065210: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80065214: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80065218: jal         0x80064F14
    // 0x8006521C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    func_80064F14(rdram, ctx);
        goto after_7;
    // 0x8006521C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    after_7:
L_80065220:
    // 0x80065220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80065224:
    // 0x80065224: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80065228: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006522C: jr          $ra
    // 0x80065230: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80065230: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80065234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065234: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006523C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80065240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80065244: jal         0x80064FFC
    // 0x80065248: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80064FFC(rdram, ctx);
        goto after_0;
    // 0x80065248: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8006524C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065254: jr          $ra
    // 0x80065258: nop

    return;
    // 0x80065258: nop

;}
RECOMP_FUNC void func_8006525C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006525C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065268: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006526C: jal         0x80064FFC
    // 0x80065270: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80064FFC(rdram, ctx);
        goto after_0;
    // 0x80065270: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80065274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006527C: jr          $ra
    // 0x80065280: nop

    return;
    // 0x80065280: nop

;}
RECOMP_FUNC void func_80065284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065284: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006528C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065290: jal         0x80065150
    // 0x80065294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065150(rdram, ctx);
        goto after_0;
    // 0x80065294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80065298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006529C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800652A0: jr          $ra
    // 0x800652A4: nop

    return;
    // 0x800652A4: nop

;}
RECOMP_FUNC void func_800652A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800652A8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800652AC: lw          $v1, -0x59C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X59C);
    // 0x800652B0: nop

    // 0x800652B4: beq         $v1, $zero, L_800652F4
    if (ctx->r3 == 0) {
        // 0x800652B8: nop
    
            goto L_800652F4;
    }
    // 0x800652B8: nop

    // 0x800652BC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800652C0: nop

    // 0x800652C4: sltu        $at, $t6, $a0
    ctx->r1 = ctx->r14 < ctx->r4 ? 1 : 0;
    // 0x800652C8: beq         $at, $zero, L_800652F4
    if (ctx->r1 == 0) {
        // 0x800652CC: nop
    
            goto L_800652F4;
    }
    // 0x800652CC: nop

L_800652D0:
    // 0x800652D0: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x800652D4: nop

    // 0x800652D8: beq         $v1, $zero, L_800652F4
    if (ctx->r3 == 0) {
        // 0x800652DC: nop
    
            goto L_800652F4;
    }
    // 0x800652DC: nop

    // 0x800652E0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800652E4: nop

    // 0x800652E8: sltu        $at, $t7, $a0
    ctx->r1 = ctx->r15 < ctx->r4 ? 1 : 0;
    // 0x800652EC: bne         $at, $zero, L_800652D0
    if (ctx->r1 != 0) {
        // 0x800652F0: nop
    
            goto L_800652D0;
    }
    // 0x800652F0: nop

L_800652F4:
    // 0x800652F4: jr          $ra
    // 0x800652F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800652F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800652FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800652FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80065300: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80065304: lw          $v0, -0x5A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5A0);
    // 0x80065308: lw          $a1, -0x5A4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5A4);
    // 0x8006530C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80065310: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80065314: beq         $at, $zero, L_80065334
    if (ctx->r1 == 0) {
        // 0x80065318: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80065334;
    }
    // 0x80065318: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8006531C:
    // 0x8006531C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80065320: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80065324: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x80065328: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8006532C: bne         $at, $zero, L_8006531C
    if (ctx->r1 != 0) {
        // 0x80065330: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8006531C;
    }
    // 0x80065330: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80065334:
    // 0x80065334: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80065338: lw          $v0, -0x59C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X59C);
    // 0x8006533C: nop

    // 0x80065340: beq         $v0, $zero, L_8006535C
    if (ctx->r2 == 0) {
        // 0x80065344: nop
    
            goto L_8006535C;
    }
    // 0x80065344: nop

L_80065348:
    // 0x80065348: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8006534C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80065350: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80065354: bne         $v0, $zero, L_80065348
    if (ctx->r2 != 0) {
        // 0x80065358: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_80065348;
    }
    // 0x80065358: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8006535C:
    // 0x8006535C: jr          $ra
    // 0x80065360: nop

    return;
    // 0x80065360: nop

;}
RECOMP_FUNC void func_80065364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006536C: jal         0x8006525C
    // 0x80065370: nop

    func_8006525C(rdram, ctx);
        goto after_0;
    // 0x80065370: nop

    after_0:
    // 0x80065374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006537C: jr          $ra
    // 0x80065380: nop

    return;
    // 0x80065380: nop

;}
RECOMP_FUNC void func_80065384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065384: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // FALLTHROUGH FIX: func_80065384 falls through to func_80065388
    func_80065388(rdram, ctx);
;}
RECOMP_FUNC void func_80065388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // FALLTHROUGH FIX: recompute multu $a0, $a1 since lo/hi are local vars
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006538C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065390: mflo        $a2
    ctx->r6 = lo;
    // 0x80065394: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80065398: jal         0x8006525C
    // 0x8006539C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8006525C(rdram, ctx);
        goto after_0;
    // 0x8006539C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800653A0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800653A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800653A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800653AC: jal         0x80061938
    // 0x800653B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80061938(rdram, ctx);
        goto after_1;
    // 0x800653B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800653B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800653B8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800653BC: jr          $ra
    // 0x800653C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800653C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800653C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800653C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800653C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800653CC: jal         0x80065284
    // 0x800653D0: nop

    func_80065284(rdram, ctx);
        goto after_0;
    // 0x800653D0: nop

    after_0:
    // 0x800653D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800653D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800653DC: jr          $ra
    // 0x800653E0: nop

    return;
    // 0x800653E0: nop

;}
RECOMP_FUNC void func_800653E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800653E4: jr          $ra
    // 0x800653E8: nop

    return;
    // 0x800653E8: nop

;}
RECOMP_FUNC void func_800653EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800653EC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800653F0: lw          $v1, -0x59C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X59C);
    // 0x800653F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800653F8: beq         $v1, $zero, L_80065414
    if (ctx->r3 == 0) {
        // 0x800653FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80065414;
    }
    // 0x800653FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80065400:
    // 0x80065400: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80065404: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x80065408: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8006540C: bne         $v1, $zero, L_80065400
    if (ctx->r3 != 0) {
        // 0x80065410: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80065400;
    }
    // 0x80065410: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80065414:
    // 0x80065414: jr          $ra
    // 0x80065418: nop

    return;
    // 0x80065418: nop

;}
RECOMP_FUNC void func_8006541C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006541C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80065420: lw          $v0, -0x59C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X59C);
    // 0x80065424: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80065428: beq         $v0, $zero, L_8006545C
    if (ctx->r2 == 0) {
        // 0x8006542C: nop
    
            goto L_8006545C;
    }
    // 0x8006542C: nop

L_80065430:
    // 0x80065430: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80065434: nop

    // 0x80065438: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8006543C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80065440: beq         $at, $zero, L_8006544C
    if (ctx->r1 == 0) {
        // 0x80065444: nop
    
            goto L_8006544C;
    }
    // 0x80065444: nop

    // 0x80065448: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8006544C:
    // 0x8006544C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80065450: nop

    // 0x80065454: bne         $v0, $zero, L_80065430
    if (ctx->r2 != 0) {
        // 0x80065458: nop
    
            goto L_80065430;
    }
    // 0x80065458: nop

L_8006545C:
    // 0x8006545C: jr          $ra
    // 0x80065460: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80065460: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80065464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065464: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80065468: lw          $v0, -0x59C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X59C);
    // 0x8006546C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80065470: beq         $v0, $zero, L_8006548C
    if (ctx->r2 == 0) {
        // 0x80065474: nop
    
            goto L_8006548C;
    }
    // 0x80065474: nop

L_80065478:
    // 0x80065478: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8006547C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80065480: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80065484: bne         $v0, $zero, L_80065478
    if (ctx->r2 != 0) {
        // 0x80065488: addu        $v1, $v1, $a0
        ctx->r3 = ADD32(ctx->r3, ctx->r4);
            goto L_80065478;
    }
    // 0x80065488: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
L_8006548C:
    // 0x8006548C: jr          $ra
    // 0x80065490: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80065490: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80065494: nop

    // 0x80065498: nop

    // 0x8006549C: nop

;}
RECOMP_FUNC void func_800654A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800654A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800654A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800654A8: jal         0x80065364
    // 0x800654AC: addiu       $a0, $zero, 0x1011
    ctx->r4 = ADD32(0, 0X1011);
    func_80065364(rdram, ctx);
        goto after_0;
    // 0x800654AC: addiu       $a0, $zero, 0x1011
    ctx->r4 = ADD32(0, 0X1011);
    after_0:
    // 0x800654B0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800654B4: addiu       $v1, $v1, -0x590
    ctx->r3 = ADD32(ctx->r3, -0X590);
    // 0x800654B8: bne         $v0, $zero, L_800654C8
    if (ctx->r2 != 0) {
        // 0x800654BC: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800654C8;
    }
    // 0x800654BC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800654C0: b           L_80065598
    // 0x800654C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80065598;
    // 0x800654C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800654C8:
    // 0x800654C8: jal         0x80065364
    // 0x800654CC: addiu       $a0, $zero, 0x4004
    ctx->r4 = ADD32(0, 0X4004);
    func_80065364(rdram, ctx);
        goto after_1;
    // 0x800654CC: addiu       $a0, $zero, 0x4004
    ctx->r4 = ADD32(0, 0X4004);
    after_1:
    // 0x800654D0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800654D4: addiu       $a1, $a1, -0x584
    ctx->r5 = ADD32(ctx->r5, -0X584);
    // 0x800654D8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800654DC: addiu       $v1, $v1, -0x590
    ctx->r3 = ADD32(ctx->r3, -0X590);
    // 0x800654E0: bne         $v0, $zero, L_800654FC
    if (ctx->r2 != 0) {
        // 0x800654E4: sw          $v0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r2;
            goto L_800654FC;
    }
    // 0x800654E4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800654E8: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800654EC: jal         0x800653C4
    // 0x800654F0: nop

    func_800653C4(rdram, ctx);
        goto after_2;
    // 0x800654F0: nop

    after_2:
    // 0x800654F4: b           L_80065598
    // 0x800654F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80065598;
    // 0x800654F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800654FC:
    // 0x800654FC: jal         0x80065364
    // 0x80065500: addiu       $a0, $zero, 0x4004
    ctx->r4 = ADD32(0, 0X4004);
    func_80065364(rdram, ctx);
        goto after_3;
    // 0x80065500: addiu       $a0, $zero, 0x4004
    ctx->r4 = ADD32(0, 0X4004);
    after_3:
    // 0x80065504: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80065508: addiu       $a1, $a1, -0x58C
    ctx->r5 = ADD32(ctx->r5, -0X58C);
    // 0x8006550C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80065510: addiu       $v1, $v1, -0x590
    ctx->r3 = ADD32(ctx->r3, -0X590);
    // 0x80065514: bne         $v0, $zero, L_80065540
    if (ctx->r2 != 0) {
        // 0x80065518: sw          $v0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r2;
            goto L_80065540;
    }
    // 0x80065518: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8006551C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80065520: jal         0x800653C4
    // 0x80065524: nop

    func_800653C4(rdram, ctx);
        goto after_4;
    // 0x80065524: nop

    after_4:
    // 0x80065528: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8006552C: lw          $a0, -0x584($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X584);
    // 0x80065530: jal         0x800653C4
    // 0x80065534: nop

    func_800653C4(rdram, ctx);
        goto after_5;
    // 0x80065534: nop

    after_5:
    // 0x80065538: b           L_80065598
    // 0x8006553C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80065598;
    // 0x8006553C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80065540:
    // 0x80065540: jal         0x80065364
    // 0x80065544: addiu       $a0, $zero, 0x4404
    ctx->r4 = ADD32(0, 0X4404);
    func_80065364(rdram, ctx);
        goto after_6;
    // 0x80065544: addiu       $a0, $zero, 0x4404
    ctx->r4 = ADD32(0, 0X4404);
    after_6:
    // 0x80065548: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8006554C: addiu       $a0, $a0, -0x588
    ctx->r4 = ADD32(ctx->r4, -0X588);
    // 0x80065550: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80065554: addiu       $v1, $v1, -0x590
    ctx->r3 = ADD32(ctx->r3, -0X590);
    // 0x80065558: bne         $v0, $zero, L_80065594
    if (ctx->r2 != 0) {
        // 0x8006555C: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80065594;
    }
    // 0x8006555C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80065560: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80065564: jal         0x800653C4
    // 0x80065568: nop

    func_800653C4(rdram, ctx);
        goto after_7;
    // 0x80065568: nop

    after_7:
    // 0x8006556C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80065570: lw          $a0, -0x584($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X584);
    // 0x80065574: jal         0x800653C4
    // 0x80065578: nop

    func_800653C4(rdram, ctx);
        goto after_8;
    // 0x80065578: nop

    after_8:
    // 0x8006557C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80065580: lw          $a0, -0x58C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X58C);
    // 0x80065584: jal         0x800653C4
    // 0x80065588: nop

    func_800653C4(rdram, ctx);
        goto after_9;
    // 0x80065588: nop

    after_9:
    // 0x8006558C: b           L_80065598
    // 0x80065590: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80065598;
    // 0x80065590: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80065594:
    // 0x80065594: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80065598:
    // 0x80065598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006559C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800655A0: jr          $ra
    // 0x800655A4: nop

    return;
    // 0x800655A4: nop

;}
RECOMP_FUNC void func_800655A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800655A8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800655AC: lw          $a0, -0x590($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X590);
    // FALLTHROUGH FIX: func_800655A8 falls through to func_800655B0
    func_800655B0(rdram, ctx);
;}
RECOMP_FUNC void func_800655B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800655B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800655B4: beq         $a0, $zero, L_800655C4
    if (ctx->r4 == 0) {
        // 0x800655B8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800655C4;
    }
    // 0x800655B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800655BC: jal         0x800653C4
    // 0x800655C0: nop

    func_800653C4(rdram, ctx);
        goto after_0;
    // 0x800655C0: nop

    after_0:
L_800655C4:
    // 0x800655C4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800655C8: lw          $a0, -0x584($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X584);
    // 0x800655CC: nop

    // 0x800655D0: beq         $a0, $zero, L_800655E0
    if (ctx->r4 == 0) {
        // 0x800655D4: nop
    
            goto L_800655E0;
    }
    // 0x800655D4: nop

    // 0x800655D8: jal         0x800653C4
    // 0x800655DC: nop

    func_800653C4(rdram, ctx);
        goto after_1;
    // 0x800655DC: nop

    after_1:
L_800655E0:
    // 0x800655E0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800655E4: lw          $a0, -0x58C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X58C);
    // 0x800655E8: nop

    // 0x800655EC: beq         $a0, $zero, L_800655FC
    if (ctx->r4 == 0) {
        // 0x800655F0: nop
    
            goto L_800655FC;
    }
    // 0x800655F0: nop

    // 0x800655F4: jal         0x800653C4
    // 0x800655F8: nop

    func_800653C4(rdram, ctx);
        goto after_2;
    // 0x800655F8: nop

    after_2:
L_800655FC:
    // 0x800655FC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80065600: lw          $a0, -0x588($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X588);
    // 0x80065604: nop

    // 0x80065608: beq         $a0, $zero, L_8006561C
    if (ctx->r4 == 0) {
        // 0x8006560C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006561C;
    }
    // 0x8006560C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065610: jal         0x800653C4
    // 0x80065614: nop

    func_800653C4(rdram, ctx);
        goto after_3;
    // 0x80065614: nop

    after_3:
    // 0x80065618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006561C:
    // 0x8006561C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065620: jr          $ra
    // 0x80065624: nop

    return;
    // 0x80065624: nop

;}
RECOMP_FUNC void func_80065628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006562C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065630: jal         0x80065364
    // 0x80065634: addiu       $a0, $zero, 0x1011
    ctx->r4 = ADD32(0, 0X1011);
    func_80065364(rdram, ctx);
        goto after_0;
    // 0x80065634: addiu       $a0, $zero, 0x1011
    ctx->r4 = ADD32(0, 0X1011);
    after_0:
    // 0x80065638: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8006563C: addiu       $v1, $v1, -0x590
    ctx->r3 = ADD32(ctx->r3, -0X590);
    // 0x80065640: bne         $v0, $zero, L_80065650
    if (ctx->r2 != 0) {
        // 0x80065644: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80065650;
    }
    // 0x80065644: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80065648: b           L_80065654
    // 0x8006564C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80065654;
    // 0x8006564C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80065650:
    // 0x80065650: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80065654:
    // 0x80065654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006565C: jr          $ra
    // 0x80065660: nop

    return;
    // 0x80065660: nop

;}
RECOMP_FUNC void func_80065664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065664: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80065668: lw          $a0, -0x590($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X590);
    // FALLTHROUGH FIX: func_80065664 falls through to func_8006566C
    func_8006566C(rdram, ctx);
;}
RECOMP_FUNC void func_8006566C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006566C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065670: beq         $a0, $zero, L_80065680
    if (ctx->r4 == 0) {
        // 0x80065674: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80065680;
    }
    // 0x80065674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065678: jal         0x800653C4
    // 0x8006567C: nop

    func_800653C4(rdram, ctx);
        goto after_0;
    // 0x8006567C: nop

    after_0:
L_80065680:
    // 0x80065680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065688: jr          $ra
    // 0x8006568C: nop

    return;
    // 0x8006568C: nop

;}
RECOMP_FUNC void func_80065690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065690: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80065694: addiu       $v0, $v0, -0x588
    ctx->r2 = ADD32(ctx->r2, -0X588);
    // 0x80065698: addiu       $v1, $zero, 0x4004
    ctx->r3 = ADD32(0, 0X4004);
    // 0x8006569C: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
L_800656A0:
    // 0x800656A0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800656A4: nop

    // 0x800656A8: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800656AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800656B0: slti        $at, $v1, 0x4404
    ctx->r1 = SIGNED(ctx->r3) < 0X4404 ? 1 : 0;
    // 0x800656B4: bne         $at, $zero, L_800656A0
    if (ctx->r1 != 0) {
        // 0x800656B8: sw          $a0, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->r4;
            goto L_800656A0;
    }
    // 0x800656B8: sw          $a0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r4;
    // 0x800656BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800656C0: addiu       $v0, $v0, -0x584
    ctx->r2 = ADD32(ctx->r2, -0X584);
    // 0x800656C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800656C8: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
L_800656CC:
    // 0x800656CC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800656D0: nop

    // 0x800656D4: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800656D8: sw          $a0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r4;
    // 0x800656DC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800656E0: nop

    // 0x800656E4: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x800656E8: sw          $a0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r4;
    // 0x800656EC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800656F0: nop

    // 0x800656F4: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x800656F8: sw          $a0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r4;
    // 0x800656FC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80065700: nop

    // 0x80065704: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80065708: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8006570C: bne         $v1, $a1, L_800656CC
    if (ctx->r3 != ctx->r5) {
        // 0x80065710: sw          $a0, 0xC($t5)
        MEM_W(0XC, ctx->r13) = ctx->r4;
            goto L_800656CC;
    }
    // 0x80065710: sw          $a0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r4;
    // 0x80065714: jr          $ra
    // 0x80065718: nop

    return;
    // 0x80065718: nop

;}
RECOMP_FUNC void func_8006571C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006571C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80065720: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80065724: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80065728: lw          $t6, -0x590($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X590);
    // 0x8006572C: addiu       $a1, $a1, -0x58C
    ctx->r5 = ADD32(ctx->r5, -0X58C);
    // 0x80065730: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80065734: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x80065738: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x8006573C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80065740: sll         $a3, $a0, 2
    ctx->r7 = S32(ctx->r4 << 2);
    // 0x80065744: addu        $t1, $t6, $a0
    ctx->r9 = ADD32(ctx->r14, ctx->r4);
    // 0x80065748: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x8006574C: addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
    // 0x80065750: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x80065754: sw          $v1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r3;
    // 0x80065758: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8006575C: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80065760: addiu       $a2, $a2, -0x588
    ctx->r6 = ADD32(ctx->r6, -0X588);
    // 0x80065764: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80065768: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x8006576C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80065770: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80065774: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x80065778: addiu       $s0, $s0, -0x57C
    ctx->r16 = ADD32(ctx->r16, -0X57C);
    // 0x8006577C: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80065780: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x80065784: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80065788: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8006578C: addiu       $s1, $s1, -0x580
    ctx->r17 = ADD32(ctx->r17, -0X580);
    // 0x80065790: addiu       $s2, $zero, 0x12
    ctx->r18 = ADD32(0, 0X12);
    // 0x80065794: addiu       $v0, $v0, 0x1001
    ctx->r2 = ADD32(ctx->r2, 0X1001);
L_80065798:
    // 0x80065798: bltz        $t0, L_800657F0
    if (SIGNED(ctx->r8) < 0) {
        // 0x8006579C: nop
    
            goto L_800657F0;
    }
    // 0x8006579C: nop

    // 0x800657A0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800657A4: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800657A8: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x800657AC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800657B0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800657B4: beq         $v1, $t2, L_800657D0
    if (ctx->r3 == ctx->r10) {
        // 0x800657B8: nop
    
            goto L_800657D0;
    }
    // 0x800657B8: nop

    // 0x800657BC: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800657C0: lw          $t0, -0x590($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X590);
    // 0x800657C4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800657C8: b           L_80065844
    // 0x800657CC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_80065844;
    // 0x800657CC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800657D0:
    // 0x800657D0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800657D4: addiu       $s0, $s0, -0x584
    ctx->r16 = ADD32(ctx->r16, -0X584);
    // 0x800657D8: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    // 0x800657DC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800657E0: nop

    // 0x800657E4: addu        $t9, $t7, $a3
    ctx->r25 = ADD32(ctx->r15, ctx->r7);
    // 0x800657E8: b           L_80065974
    // 0x800657EC: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
        goto L_80065974;
    // 0x800657EC: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
L_800657F0:
    // 0x800657F0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800657F4: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800657F8: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x800657FC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80065800: nop

    // 0x80065804: beq         $v1, $t2, L_80065824
    if (ctx->r3 == ctx->r10) {
        // 0x80065808: nop
    
            goto L_80065824;
    }
    // 0x80065808: nop

    // 0x8006580C: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80065810: lw          $t0, -0x590($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X590);
    // 0x80065814: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80065818: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006581C: b           L_80065844
    // 0x80065820: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_80065844;
    // 0x80065820: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80065824:
    // 0x80065824: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80065828: addiu       $s0, $s0, -0x584
    ctx->r16 = ADD32(ctx->r16, -0X584);
    // 0x8006582C: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    // 0x80065830: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80065834: nop

    // 0x80065838: addu        $t9, $t7, $a3
    ctx->r25 = ADD32(ctx->r15, ctx->r7);
    // 0x8006583C: b           L_80065974
    // 0x80065840: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
        goto L_80065974;
    // 0x80065840: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
L_80065844:
    // 0x80065844: addu        $t4, $v0, $t0
    ctx->r12 = ADD32(ctx->r2, ctx->r8);
    // 0x80065848: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8006584C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
L_80065850:
    // 0x80065850: lbu         $t6, 0x0($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X0);
    // 0x80065854: lbu         $t8, 0x0($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X0);
    // 0x80065858: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8006585C: subu        $t0, $t6, $t8
    ctx->r8 = SUB32(ctx->r14, ctx->r24);
    // 0x80065860: bne         $t0, $zero, L_80065878
    if (ctx->r8 != 0) {
        // 0x80065864: slt         $at, $t5, $t3
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_80065878;
    }
    // 0x80065864: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80065868: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8006586C: bne         $t3, $s2, L_80065850
    if (ctx->r11 != ctx->r18) {
        // 0x80065870: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_80065850;
    }
    // 0x80065870: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80065874: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
L_80065878:
    // 0x80065878: beq         $at, $zero, L_80065798
    if (ctx->r1 == 0) {
        // 0x8006587C: nop
    
            goto L_80065798;
    }
    // 0x8006587C: nop

    // 0x80065880: slti        $at, $t3, 0x12
    ctx->r1 = SIGNED(ctx->r11) < 0X12 ? 1 : 0;
    // 0x80065884: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80065888: bne         $at, $zero, L_80065798
    if (ctx->r1 != 0) {
        // 0x8006588C: sw          $t3, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r11;
            goto L_80065798;
    }
    // 0x8006588C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80065890: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80065894: addiu       $s0, $s0, -0x584
    ctx->r16 = ADD32(ctx->r16, -0X584);
    // 0x80065898: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8006589C: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800658A0: addu        $t9, $t3, $t2
    ctx->r25 = ADD32(ctx->r11, ctx->r10);
    // 0x800658A4: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800658A8: addu        $t8, $t3, $a3
    ctx->r24 = ADD32(ctx->r11, ctx->r7);
    // 0x800658AC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800658B0: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x800658B4: nop

    // 0x800658B8: addu        $t7, $t0, $t2
    ctx->r15 = ADD32(ctx->r8, ctx->r10);
    // 0x800658BC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800658C0: addu        $t6, $t0, $a3
    ctx->r14 = ADD32(ctx->r8, ctx->r7);
    // 0x800658C4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800658C8: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x800658CC: nop

    // 0x800658D0: addu        $t8, $t1, $t2
    ctx->r24 = ADD32(ctx->r9, ctx->r10);
    // 0x800658D4: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800658D8: addu        $t9, $t1, $a3
    ctx->r25 = ADD32(ctx->r9, ctx->r7);
    // 0x800658DC: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800658E0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800658E4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800658E8: addu        $t7, $t8, $t2
    ctx->r15 = ADD32(ctx->r24, ctx->r10);
    // 0x800658EC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800658F0: nop

    // 0x800658F4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800658F8: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800658FC: sw          $a0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r4;
    // 0x80065900: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80065904: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80065908: addu        $t8, $t6, $t2
    ctx->r24 = ADD32(ctx->r14, ctx->r10);
    // 0x8006590C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80065910: nop

    // 0x80065914: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80065918: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8006591C: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x80065920: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80065924: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80065928: addu        $t9, $t7, $t2
    ctx->r25 = ADD32(ctx->r15, ctx->r10);
    // 0x8006592C: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x80065930: nop

    // 0x80065934: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80065938: addu        $t5, $t8, $t6
    ctx->r13 = ADD32(ctx->r24, ctx->r14);
    // 0x8006593C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80065940: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x80065944: bne         $v0, $t7, L_80065954
    if (ctx->r2 != ctx->r15) {
        // 0x80065948: nop
    
            goto L_80065954;
    }
    // 0x80065948: nop

    // 0x8006594C: b           L_80065964
    // 0x80065950: sw          $a0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r4;
        goto L_80065964;
    // 0x80065950: sw          $a0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r4;
L_80065954:
    // 0x80065954: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80065958: nop

    // 0x8006595C: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x80065960: sw          $a0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r4;
L_80065964:
    // 0x80065964: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80065968: nop

    // 0x8006596C: addu        $t7, $t8, $t2
    ctx->r15 = ADD32(ctx->r24, ctx->r10);
    // 0x80065970: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
L_80065974:
    // 0x80065974: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80065978: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x8006597C: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80065980: jr          $ra
    // 0x80065984: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80065984: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80065988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065988: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006598C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80065990: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80065994: addiu       $s0, $s0, -0x584
    ctx->r16 = ADD32(ctx->r16, -0X584);
    // 0x80065998: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006599C: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800659A0: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x800659A4: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x800659A8: addiu       $t5, $zero, 0x1000
    ctx->r13 = ADD32(0, 0X1000);
    // 0x800659AC: beq         $t5, $a1, L_80065B70
    if (ctx->r13 == ctx->r5) {
        // 0x800659B0: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80065B70;
    }
    // 0x800659B0: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800659B4: lw          $a2, -0x588($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X588);
    // 0x800659B8: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800659BC: addu        $t7, $a2, $v1
    ctx->r15 = ADD32(ctx->r6, ctx->r3);
    // 0x800659C0: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    // 0x800659C4: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800659C8: bne         $t5, $a3, L_800659E8
    if (ctx->r13 != ctx->r7) {
        // 0x800659CC: nop
    
            goto L_800659E8;
    }
    // 0x800659CC: nop

    // 0x800659D0: lw          $t8, -0x58C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X58C);
    // 0x800659D4: nop

    // 0x800659D8: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800659DC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800659E0: b           L_80065B14
    // 0x800659E4: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
        goto L_80065B14;
    // 0x800659E4: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
L_800659E8:
    // 0x800659E8: lw          $t1, -0x58C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X58C);
    // 0x800659EC: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x800659F0: addu        $t6, $t1, $v1
    ctx->r14 = ADD32(ctx->r9, ctx->r3);
    // 0x800659F4: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x800659F8: nop

    // 0x800659FC: bne         $t5, $t2, L_80065A0C
    if (ctx->r13 != ctx->r10) {
        // 0x80065A00: sll         $t3, $t2, 2
        ctx->r11 = S32(ctx->r10 << 2);
            goto L_80065A0C;
    }
    // 0x80065A00: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80065A04: b           L_80065B14
    // 0x80065A08: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
        goto L_80065B14;
    // 0x80065A08: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
L_80065A0C:
    // 0x80065A0C: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x80065A10: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x80065A14: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x80065A18: beq         $t5, $a1, L_80065AD8
    if (ctx->r13 == ctx->r5) {
        // 0x80065A1C: nop
    
            goto L_80065AD8;
    }
    // 0x80065A1C: nop

L_80065A20:
    // 0x80065A20: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80065A24: addu        $t7, $a2, $t3
    ctx->r15 = ADD32(ctx->r6, ctx->r11);
    // 0x80065A28: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80065A2C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80065A30: nop

    // 0x80065A34: bne         $t5, $a1, L_80065A20
    if (ctx->r13 != ctx->r5) {
        // 0x80065A38: nop
    
            goto L_80065A20;
    }
    // 0x80065A38: nop

    // 0x80065A3C: addu        $t6, $v0, $t3
    ctx->r14 = ADD32(ctx->r2, ctx->r11);
    // 0x80065A40: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80065A44: addu        $t8, $t1, $t3
    ctx->r24 = ADD32(ctx->r9, ctx->r11);
    // 0x80065A48: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80065A4C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80065A50: addu        $t6, $a2, $t8
    ctx->r14 = ADD32(ctx->r6, ctx->r24);
    // 0x80065A54: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80065A58: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80065A5C: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80065A60: lw          $t9, -0x58C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X58C);
    // 0x80065A64: addu        $t7, $v0, $t3
    ctx->r15 = ADD32(ctx->r2, ctx->r11);
    // 0x80065A68: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80065A6C: addu        $t6, $t9, $t3
    ctx->r14 = ADD32(ctx->r25, ctx->r11);
    // 0x80065A70: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80065A74: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80065A78: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80065A7C: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x80065A80: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80065A84: lw          $t1, -0x58C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X58C);
    // 0x80065A88: nop

    // 0x80065A8C: addu        $t7, $t1, $v1
    ctx->r15 = ADD32(ctx->r9, ctx->r3);
    // 0x80065A90: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80065A94: addu        $t8, $t1, $t3
    ctx->r24 = ADD32(ctx->r9, ctx->r11);
    // 0x80065A98: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80065A9C: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x80065AA0: lw          $t7, -0x58C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X58C);
    // 0x80065AA4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80065AA8: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x80065AAC: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80065AB0: nop

    // 0x80065AB4: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80065AB8: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80065ABC: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x80065AC0: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80065AC4: lw          $t8, -0x588($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X588);
    // 0x80065AC8: nop

    // 0x80065ACC: addu        $t6, $t8, $v1
    ctx->r14 = ADD32(ctx->r24, ctx->r3);
    // 0x80065AD0: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    // 0x80065AD4: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
L_80065AD8:
    // 0x80065AD8: sw          $a3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r7;
    // 0x80065ADC: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80065AE0: lw          $t9, -0x588($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X588);
    // 0x80065AE4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80065AE8: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x80065AEC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80065AF0: nop

    // 0x80065AF4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80065AF8: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80065AFC: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x80065B00: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80065B04: nop

    // 0x80065B08: addu        $t8, $v0, $v1
    ctx->r24 = ADD32(ctx->r2, ctx->r3);
    // 0x80065B0C: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x80065B10: nop

L_80065B14:
    // 0x80065B14: addu        $t7, $v0, $t3
    ctx->r15 = ADD32(ctx->r2, ctx->r11);
    // 0x80065B18: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    // 0x80065B1C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80065B20: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80065B24: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x80065B28: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x80065B2C: lw          $t7, -0x588($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X588);
    // 0x80065B30: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80065B34: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x80065B38: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80065B3C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80065B40: bne         $a0, $t9, L_80065B50
    if (ctx->r4 != ctx->r25) {
        // 0x80065B44: lui         $t6, 0x8011
        ctx->r14 = S32(0X8011 << 16);
            goto L_80065B50;
    }
    // 0x80065B44: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80065B48: b           L_80065B60
    // 0x80065B4C: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
        goto L_80065B60;
    // 0x80065B4C: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
L_80065B50:
    // 0x80065B50: lw          $t6, -0x58C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X58C);
    // 0x80065B54: nop

    // 0x80065B58: addu        $t8, $t6, $a2
    ctx->r24 = ADD32(ctx->r14, ctx->r6);
    // 0x80065B5C: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
L_80065B60:
    // 0x80065B60: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80065B64: nop

    // 0x80065B68: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x80065B6C: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
L_80065B70:
    // 0x80065B70: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80065B74: jr          $ra
    // 0x80065B78: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80065B78: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80065B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065B7C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80065B80: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80065B84: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80065B88: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80065B8C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80065B90: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80065B94: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80065B98: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80065B9C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80065BA0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80065BA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80065BA8: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80065BAC: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x80065BB0: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
    // 0x80065BB4: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80065BB8: bne         $a2, $zero, L_80065BC8
    if (ctx->r6 != 0) {
        // 0x80065BBC: or          $s3, $a1, $zero
        ctx->r19 = ctx->r5 | 0;
            goto L_80065BC8;
    }
    // 0x80065BBC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80065BC0: b           L_80065F94
    // 0x80065BC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80065F94;
    // 0x80065BC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80065BC8:
    // 0x80065BC8: jal         0x80065690
    // 0x80065BCC: nop

    func_80065690(rdram, ctx);
        goto after_0;
    // 0x80065BCC: nop

    after_0:
    // 0x80065BD0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80065BD4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80065BD8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80065BDC: sb          $zero, 0x70($sp)
    MEM_B(0X70, ctx->r29) = 0;
    // 0x80065BE0: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
    // 0x80065BE4: sb          $t7, 0x6F($sp)
    MEM_B(0X6F, ctx->r29) = ctx->r15;
    // 0x80065BE8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80065BEC: addiu       $s6, $zero, 0xFEE
    ctx->r22 = ADD32(0, 0XFEE);
    // 0x80065BF0: addiu       $v1, $v1, -0x590
    ctx->r3 = ADD32(ctx->r3, -0X590);
    // 0x80065BF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80065BF8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_80065BFC:
    // 0x80065BFC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80065C00: nop

    // 0x80065C04: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x80065C08: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80065C0C: slt         $at, $s1, $s6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80065C10: bne         $at, $zero, L_80065BFC
    if (ctx->r1 != 0) {
        // 0x80065C14: sb          $v0, 0x0($t0)
        MEM_B(0X0, ctx->r8) = ctx->r2;
            goto L_80065BFC;
    }
    // 0x80065C14: sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
    // 0x80065C18: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x80065C1C: lw          $v0, 0xA8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA8);
    // 0x80065C20: subu        $t1, $a1, $a1
    ctx->r9 = SUB32(ctx->r5, ctx->r5);
    // 0x80065C24: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80065C28: beq         $at, $zero, L_80065C60
    if (ctx->r1 == 0) {
        // 0x80065C2C: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_80065C60;
    }
    // 0x80065C2C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_80065C30:
    // 0x80065C30: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80065C34: lbu         $s0, 0x0($fp)
    ctx->r16 = MEM_BU(ctx->r30, 0X0);
    // 0x80065C38: addu        $t3, $t2, $s7
    ctx->r11 = ADD32(ctx->r10, ctx->r23);
    // 0x80065C3C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80065C40: slti        $at, $s7, 0x12
    ctx->r1 = SIGNED(ctx->r23) < 0X12 ? 1 : 0;
    // 0x80065C44: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80065C48: beq         $at, $zero, L_80065C60
    if (ctx->r1 == 0) {
        // 0x80065C4C: sb          $s0, 0xFEE($t3)
        MEM_B(0XFEE, ctx->r11) = ctx->r16;
            goto L_80065C60;
    }
    // 0x80065C4C: sb          $s0, 0xFEE($t3)
    MEM_B(0XFEE, ctx->r11) = ctx->r16;
    // 0x80065C50: subu        $t4, $fp, $a1
    ctx->r12 = SUB32(ctx->r30, ctx->r5);
    // 0x80065C54: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80065C58: bne         $at, $zero, L_80065C30
    if (ctx->r1 != 0) {
        // 0x80065C5C: nop
    
            goto L_80065C30;
    }
    // 0x80065C5C: nop

L_80065C60:
    // 0x80065C60: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80065C64: addiu       $s2, $zero, 0x13
    ctx->r18 = ADD32(0, 0X13);
    // 0x80065C68: addiu       $s0, $zero, 0xFEE
    ctx->r16 = ADD32(0, 0XFEE);
L_80065C6C:
    // 0x80065C6C: jal         0x8006571C
    // 0x80065C70: subu        $a0, $s0, $s1
    ctx->r4 = SUB32(ctx->r16, ctx->r17);
    func_8006571C(rdram, ctx);
        goto after_1;
    // 0x80065C70: subu        $a0, $s0, $s1
    ctx->r4 = SUB32(ctx->r16, ctx->r17);
    after_1:
    // 0x80065C74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80065C78: bne         $s1, $s2, L_80065C6C
    if (ctx->r17 != ctx->r18) {
        // 0x80065C7C: nop
    
            goto L_80065C6C;
    }
    // 0x80065C7C: nop

    // 0x80065C80: jal         0x8006571C
    // 0x80065C84: addiu       $a0, $zero, 0xFEE
    ctx->r4 = ADD32(0, 0XFEE);
    func_8006571C(rdram, ctx);
        goto after_2;
    // 0x80065C84: addiu       $a0, $zero, 0xFEE
    ctx->r4 = ADD32(0, 0XFEE);
    after_2:
    // 0x80065C88: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80065C8C: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x80065C90: addiu       $a2, $a2, -0x57C
    ctx->r6 = ADD32(ctx->r6, -0X57C);
L_80065C94:
    // 0x80065C94: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80065C98: lbu         $a1, 0x6F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X6F);
    // 0x80065C9C: addiu       $t5, $sp, 0x70
    ctx->r13 = ADD32(ctx->r29, 0X70);
    // 0x80065CA0: slt         $at, $s7, $a0
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80065CA4: beq         $at, $zero, L_80065CB4
    if (ctx->r1 == 0) {
        // 0x80065CA8: addu        $v0, $a3, $t5
        ctx->r2 = ADD32(ctx->r7, ctx->r13);
            goto L_80065CB4;
    }
    // 0x80065CA8: addu        $v0, $a3, $t5
    ctx->r2 = ADD32(ctx->r7, ctx->r13);
    // 0x80065CAC: sw          $s7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r23;
    // 0x80065CB0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80065CB4:
    // 0x80065CB4: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80065CB8: beq         $at, $zero, L_80065CF0
    if (ctx->r1 == 0) {
        // 0x80065CBC: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80065CF0;
    }
    // 0x80065CBC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80065CC0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80065CC4: lbu         $t7, 0x70($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X70);
    // 0x80065CC8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80065CCC: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80065CD0: lw          $t9, -0x590($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X590);
    // 0x80065CD4: or          $t8, $t7, $a1
    ctx->r24 = ctx->r15 | ctx->r5;
    // 0x80065CD8: sb          $t8, 0x70($sp)
    MEM_B(0X70, ctx->r29) = ctx->r24;
    // 0x80065CDC: addu        $t0, $t9, $s6
    ctx->r8 = ADD32(ctx->r25, ctx->r22);
    // 0x80065CE0: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80065CE4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80065CE8: b           L_80065D14
    // 0x80065CEC: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
        goto L_80065D14;
    // 0x80065CEC: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
L_80065CF0:
    // 0x80065CF0: lw          $v1, -0x580($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X580);
    // 0x80065CF4: addiu       $t4, $a0, -0x3
    ctx->r12 = ADD32(ctx->r4, -0X3);
    // 0x80065CF8: sra         $t2, $v1, 4
    ctx->r10 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80065CFC: andi        $t3, $t2, 0xF0
    ctx->r11 = ctx->r10 & 0XF0;
    // 0x80065D00: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80065D04: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80065D08: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x80065D0C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80065D10: sb          $v1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r3;
L_80065D14:
    // 0x80065D14: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80065D18: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80065D1C: bne         $t7, $zero, L_80065DC8
    if (ctx->r15 != 0) {
        // 0x80065D20: sb          $t6, 0x6F($sp)
        MEM_B(0X6F, ctx->r29) = ctx->r14;
            goto L_80065DC8;
    }
    // 0x80065D20: sb          $t6, 0x6F($sp)
    MEM_B(0X6F, ctx->r29) = ctx->r14;
    // 0x80065D24: blez        $a3, L_80065DAC
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80065D28: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80065DAC;
    }
    // 0x80065D28: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80065D2C: andi        $a0, $a3, 0x3
    ctx->r4 = ctx->r7 & 0X3;
    // 0x80065D30: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    // 0x80065D34: beq         $a0, $zero, L_80065D64
    if (ctx->r4 == 0) {
        // 0x80065D38: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80065D64;
    }
    // 0x80065D38: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80065D3C: addiu       $t8, $sp, 0x70
    ctx->r24 = ADD32(ctx->r29, 0X70);
    // 0x80065D40: addu        $v0, $zero, $t8
    ctx->r2 = ADD32(0, ctx->r24);
    // 0x80065D44: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80065D48:
    // 0x80065D48: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80065D4C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80065D50: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80065D54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80065D58: bne         $v1, $s1, L_80065D48
    if (ctx->r3 != ctx->r17) {
        // 0x80065D5C: sb          $t9, -0x1($s3)
        MEM_B(-0X1, ctx->r19) = ctx->r25;
            goto L_80065D48;
    }
    // 0x80065D5C: sb          $t9, -0x1($s3)
    MEM_B(-0X1, ctx->r19) = ctx->r25;
    // 0x80065D60: beq         $s1, $a1, L_80065DA0
    if (ctx->r17 == ctx->r5) {
        // 0x80065D64: addiu       $t0, $sp, 0x70
        ctx->r8 = ADD32(ctx->r29, 0X70);
            goto L_80065DA0;
    }
L_80065D64:
    // 0x80065D64: addiu       $t0, $sp, 0x70
    ctx->r8 = ADD32(ctx->r29, 0X70);
    // 0x80065D68: addu        $v0, $s1, $t0
    ctx->r2 = ADD32(ctx->r17, ctx->r8);
    // 0x80065D6C: addu        $v1, $a1, $t0
    ctx->r3 = ADD32(ctx->r5, ctx->r8);
L_80065D70:
    // 0x80065D70: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80065D74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80065D78: sb          $t1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r9;
    // 0x80065D7C: lbu         $t2, -0x3($v0)
    ctx->r10 = MEM_BU(ctx->r2, -0X3);
    // 0x80065D80: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80065D84: sb          $t2, -0x3($s3)
    MEM_B(-0X3, ctx->r19) = ctx->r10;
    // 0x80065D88: lbu         $t3, -0x2($v0)
    ctx->r11 = MEM_BU(ctx->r2, -0X2);
    // 0x80065D8C: nop

    // 0x80065D90: sb          $t3, -0x2($s3)
    MEM_B(-0X2, ctx->r19) = ctx->r11;
    // 0x80065D94: lbu         $t4, -0x1($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0X1);
    // 0x80065D98: bne         $v0, $v1, L_80065D70
    if (ctx->r2 != ctx->r3) {
        // 0x80065D9C: sb          $t4, -0x1($s3)
        MEM_B(-0X1, ctx->r19) = ctx->r12;
            goto L_80065D70;
    }
    // 0x80065D9C: sb          $t4, -0x1($s3)
    MEM_B(-0X1, ctx->r19) = ctx->r12;
L_80065DA0:
    // 0x80065DA0: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80065DA4: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x80065DA8: addiu       $a2, $a2, -0x57C
    ctx->r6 = ADD32(ctx->r6, -0X57C);
L_80065DAC:
    // 0x80065DAC: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x80065DB0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80065DB4: addu        $t6, $t5, $a3
    ctx->r14 = ADD32(ctx->r13, ctx->r7);
    // 0x80065DB8: sw          $t6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r14;
    // 0x80065DBC: sb          $zero, 0x70($sp)
    MEM_B(0X70, ctx->r29) = 0;
    // 0x80065DC0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80065DC4: sb          $t7, 0x6F($sp)
    MEM_B(0X6F, ctx->r29) = ctx->r15;
L_80065DC8:
    // 0x80065DC8: lw          $s5, 0x0($a2)
    ctx->r21 = MEM_W(ctx->r6, 0X0);
    // 0x80065DCC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80065DD0: blez        $s5, L_80065E74
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80065DD4: sw          $a3, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r7;
            goto L_80065E74;
    }
    // 0x80065DD4: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    // 0x80065DD8: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x80065DDC: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x80065DE0: subu        $s2, $fp, $t8
    ctx->r18 = SUB32(ctx->r30, ctx->r24);
    // 0x80065DE4: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80065DE8: beq         $at, $zero, L_80065E74
    if (ctx->r1 == 0) {
        // 0x80065DEC: sw          $a3, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r7;
            goto L_80065E74;
    }
    // 0x80065DEC: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    // 0x80065DF0: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
L_80065DF4:
    // 0x80065DF4: lbu         $s0, 0x0($fp)
    ctx->r16 = MEM_BU(ctx->r30, 0X0);
    // 0x80065DF8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80065DFC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80065E00: jal         0x80065988
    // 0x80065E04: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80065988(rdram, ctx);
        goto after_3;
    // 0x80065E04: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x80065E08: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80065E0C: addiu       $v0, $v0, -0x590
    ctx->r2 = ADD32(ctx->r2, -0X590);
    // 0x80065E10: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80065E14: slti        $at, $s4, 0x11
    ctx->r1 = SIGNED(ctx->r20) < 0X11 ? 1 : 0;
    // 0x80065E18: addu        $t1, $t0, $s4
    ctx->r9 = ADD32(ctx->r8, ctx->r20);
    // 0x80065E1C: beq         $at, $zero, L_80065E34
    if (ctx->r1 == 0) {
        // 0x80065E20: sb          $s0, 0x0($t1)
        MEM_B(0X0, ctx->r9) = ctx->r16;
            goto L_80065E34;
    }
    // 0x80065E20: sb          $s0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r16;
    // 0x80065E24: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80065E28: nop

    // 0x80065E2C: addu        $t3, $t2, $s4
    ctx->r11 = ADD32(ctx->r10, ctx->r20);
    // 0x80065E30: sb          $s0, 0x1000($t3)
    MEM_B(0X1000, ctx->r11) = ctx->r16;
L_80065E34:
    // 0x80065E34: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80065E38: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80065E3C: andi        $t4, $s4, 0xFFF
    ctx->r12 = ctx->r20 & 0XFFF;
    // 0x80065E40: andi        $a0, $s6, 0xFFF
    ctx->r4 = ctx->r22 & 0XFFF;
    // 0x80065E44: or          $s4, $t4, $zero
    ctx->r20 = ctx->r12 | 0;
    // 0x80065E48: jal         0x8006571C
    // 0x80065E4C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    func_8006571C(rdram, ctx);
        goto after_4;
    // 0x80065E4C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_4:
    // 0x80065E50: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80065E54: slt         $at, $s1, $s5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80065E58: beq         $at, $zero, L_80065E74
    if (ctx->r1 == 0) {
        // 0x80065E5C: nop
    
            goto L_80065E74;
    }
    // 0x80065E5C: nop

    // 0x80065E60: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80065E64: nop

    // 0x80065E68: slt         $at, $s2, $t6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80065E6C: bne         $at, $zero, L_80065DF4
    if (ctx->r1 != 0) {
        // 0x80065E70: nop
    
            goto L_80065DF4;
    }
    // 0x80065E70: nop

L_80065E74:
    // 0x80065E74: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80065E78: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x80065E7C: slt         $v0, $s1, $s5
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80065E80: addiu       $a2, $a2, -0x57C
    ctx->r6 = ADD32(ctx->r6, -0X57C);
    // 0x80065E84: beq         $v0, $zero, L_80065ED4
    if (ctx->r2 == 0) {
        // 0x80065E88: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80065ED4;
    }
    // 0x80065E88: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80065E8C: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
L_80065E90:
    // 0x80065E90: jal         0x80065988
    // 0x80065E94: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80065988(rdram, ctx);
        goto after_5;
    // 0x80065E94: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x80065E98: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80065E9C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80065EA0: andi        $t7, $s4, 0xFFF
    ctx->r15 = ctx->r20 & 0XFFF;
    // 0x80065EA4: andi        $t8, $s6, 0xFFF
    ctx->r24 = ctx->r22 & 0XFFF;
    // 0x80065EA8: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x80065EAC: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x80065EB0: beq         $s7, $zero, L_80065EC0
    if (ctx->r23 == 0) {
        // 0x80065EB4: or          $s6, $t8, $zero
        ctx->r22 = ctx->r24 | 0;
            goto L_80065EC0;
    }
    // 0x80065EB4: or          $s6, $t8, $zero
    ctx->r22 = ctx->r24 | 0;
    // 0x80065EB8: jal         0x8006571C
    // 0x80065EBC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_8006571C(rdram, ctx);
        goto after_6;
    // 0x80065EBC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_6:
L_80065EC0:
    // 0x80065EC0: slt         $v0, $s1, $s5
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80065EC4: bne         $v0, $zero, L_80065E90
    if (ctx->r2 != 0) {
        // 0x80065EC8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80065E90;
    }
    // 0x80065EC8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80065ECC: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80065ED0: addiu       $a2, $a2, -0x57C
    ctx->r6 = ADD32(ctx->r6, -0X57C);
L_80065ED4:
    // 0x80065ED4: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x80065ED8: bgtz        $s7, L_80065C94
    if (SIGNED(ctx->r23) > 0) {
        // 0x80065EDC: nop
    
            goto L_80065C94;
    }
    // 0x80065EDC: nop

    // 0x80065EE0: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x80065EE4: bne         $at, $zero, L_80065F90
    if (ctx->r1 != 0) {
        // 0x80065EE8: lw          $v0, 0x84($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X84);
            goto L_80065F90;
    }
    // 0x80065EE8: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x80065EEC: blez        $a3, L_80065F7C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80065EF0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80065F7C;
    }
    // 0x80065EF0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80065EF4: andi        $t9, $a3, 0x3
    ctx->r25 = ctx->r7 & 0X3;
    // 0x80065EF8: beq         $t9, $zero, L_80065F34
    if (ctx->r25 == 0) {
        // 0x80065EFC: sw          $a3, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r7;
            goto L_80065F34;
    }
    // 0x80065EFC: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    // 0x80065F00: addiu       $t0, $sp, 0x70
    ctx->r8 = ADD32(ctx->r29, 0X70);
    // 0x80065F04: addu        $v0, $zero, $t0
    ctx->r2 = ADD32(0, ctx->r8);
    // 0x80065F08: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_80065F0C:
    // 0x80065F0C: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80065F10: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80065F14: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80065F18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80065F1C: bne         $v1, $s1, L_80065F0C
    if (ctx->r3 != ctx->r17) {
        // 0x80065F20: sb          $t1, -0x1($s3)
        MEM_B(-0X1, ctx->r19) = ctx->r9;
            goto L_80065F0C;
    }
    // 0x80065F20: sb          $t1, -0x1($s3)
    MEM_B(-0X1, ctx->r19) = ctx->r9;
    // 0x80065F24: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x80065F28: nop

    // 0x80065F2C: beq         $s1, $t2, L_80065F78
    if (ctx->r17 == ctx->r10) {
        // 0x80065F30: lw          $a3, 0x88($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X88);
            goto L_80065F78;
    }
    // 0x80065F30: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
L_80065F34:
    // 0x80065F34: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80065F38: addiu       $t3, $sp, 0x70
    ctx->r11 = ADD32(ctx->r29, 0X70);
    // 0x80065F3C: addu        $v0, $s1, $t3
    ctx->r2 = ADD32(ctx->r17, ctx->r11);
    // 0x80065F40: addu        $v1, $t4, $t3
    ctx->r3 = ADD32(ctx->r12, ctx->r11);
L_80065F44:
    // 0x80065F44: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80065F48: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80065F4C: sb          $t5, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r13;
    // 0x80065F50: lbu         $t6, -0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X3);
    // 0x80065F54: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80065F58: sb          $t6, -0x3($s3)
    MEM_B(-0X3, ctx->r19) = ctx->r14;
    // 0x80065F5C: lbu         $t7, -0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X2);
    // 0x80065F60: nop

    // 0x80065F64: sb          $t7, -0x2($s3)
    MEM_B(-0X2, ctx->r19) = ctx->r15;
    // 0x80065F68: lbu         $t8, -0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X1);
    // 0x80065F6C: bne         $v0, $v1, L_80065F44
    if (ctx->r2 != ctx->r3) {
        // 0x80065F70: sb          $t8, -0x1($s3)
        MEM_B(-0X1, ctx->r19) = ctx->r24;
            goto L_80065F44;
    }
    // 0x80065F70: sb          $t8, -0x1($s3)
    MEM_B(-0X1, ctx->r19) = ctx->r24;
    // 0x80065F74: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
L_80065F78:
    // 0x80065F78: nop

L_80065F7C:
    // 0x80065F7C: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x80065F80: nop

    // 0x80065F84: addu        $t0, $t9, $a3
    ctx->r8 = ADD32(ctx->r25, ctx->r7);
    // 0x80065F88: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    // 0x80065F8C: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
L_80065F90:
    // 0x80065F90: nop

L_80065F94:
    // 0x80065F94: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80065F98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80065F9C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80065FA0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80065FA4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80065FA8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80065FAC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80065FB0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80065FB4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80065FB8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80065FBC: jr          $ra
    // 0x80065FC0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80065FC0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80065FC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065FC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065FC8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80065FCC: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x80065FD0: addiu       $s3, $s3, -0x590
    ctx->r19 = ADD32(ctx->r19, -0X590);
    // 0x80065FD4: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80065FD8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80065FDC: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80065FE0: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80065FE4: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80065FE8: sb          $a3, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r7;
    // 0x80065FEC: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80065FF0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80065FF4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80065FF8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80065FFC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80066000: addiu       $t0, $zero, 0xFEE
    ctx->r8 = ADD32(0, 0XFEE);
    // 0x80066004: sb          $a3, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r7;
L_80066008:
    // 0x80066008: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8006600C: nop

    // 0x80066010: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x80066014: sb          $a3, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r7;
    // 0x80066018: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8006601C: nop

    // 0x80066020: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x80066024: sb          $a3, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r7;
    // 0x80066028: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8006602C: nop

    // 0x80066030: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x80066034: sb          $a3, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r7;
    // 0x80066038: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8006603C: nop

    // 0x80066040: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x80066044: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80066048: bne         $a2, $t0, L_80066008
    if (ctx->r6 != ctx->r8) {
        // 0x8006604C: sb          $a3, 0x3($t7)
        MEM_B(0X3, ctx->r15) = ctx->r7;
            goto L_80066008;
    }
    // 0x8006604C: sb          $a3, 0x3($t7)
    MEM_B(0X3, ctx->r15) = ctx->r7;
    // 0x80066050: addiu       $a3, $zero, 0xFEE
    ctx->r7 = ADD32(0, 0XFEE);
    // 0x80066054: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80066058: subu        $t1, $v0, $a0
    ctx->r9 = SUB32(ctx->r2, ctx->r4);
L_8006605C:
    // 0x8006605C: srl         $t8, $t0, 1
    ctx->r24 = S32(U32(ctx->r8) >> 1);
L_80066060:
    // 0x80066060: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x80066064: bne         $t9, $zero, L_80066084
    if (ctx->r25 != 0) {
        // 0x80066068: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_80066084;
    }
    // 0x80066068: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8006606C: slt         $at, $t1, $s0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80066070: beq         $at, $zero, L_8006624C
    if (ctx->r1 == 0) {
        // 0x80066074: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8006624C;
    }
    // 0x80066074: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80066078: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x8006607C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80066080: ori         $t0, $a0, 0xFF00
    ctx->r8 = ctx->r4 | 0XFF00;
L_80066084:
    // 0x80066084: andi        $t6, $t0, 0x1
    ctx->r14 = ctx->r8 & 0X1;
    // 0x80066088: beq         $t6, $zero, L_800660C8
    if (ctx->r14 == 0) {
        // 0x8006608C: slt         $at, $t1, $s0
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_800660C8;
    }
    // 0x8006608C: slt         $at, $t1, $s0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80066090: slt         $at, $t1, $s0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80066094: beq         $at, $zero, L_8006624C
    if (ctx->r1 == 0) {
        // 0x80066098: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8006624C;
    }
    // 0x80066098: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8006609C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800660A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800660A4: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x800660A8: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800660AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800660B0: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x800660B4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800660B8: andi        $t9, $a3, 0xFFF
    ctx->r25 = ctx->r7 & 0XFFF;
    // 0x800660BC: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800660C0: b           L_8006605C
    // 0x800660C4: sb          $a0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r4;
        goto L_8006605C;
    // 0x800660C4: sb          $a0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r4;
L_800660C8:
    // 0x800660C8: beq         $at, $zero, L_8006624C
    if (ctx->r1 == 0) {
        // 0x800660CC: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8006624C;
    }
    // 0x800660CC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800660D0: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x800660D4: slt         $at, $t1, $s0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800660D8: beq         $at, $zero, L_8006624C
    if (ctx->r1 == 0) {
        // 0x800660DC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8006624C;
    }
    // 0x800660DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800660E0: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x800660E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800660E8: andi        $t6, $t2, 0xF0
    ctx->r14 = ctx->r10 & 0XF0;
    // 0x800660EC: andi        $t8, $t2, 0xF
    ctx->r24 = ctx->r10 & 0XF;
    // 0x800660F0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800660F4: addiu       $t2, $t8, 0x2
    ctx->r10 = ADD32(ctx->r24, 0X2);
    // 0x800660F8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800660FC: or          $a2, $a2, $t7
    ctx->r6 = ctx->r6 | ctx->r15;
    // 0x80066100: bltz        $t2, L_8006605C
    if (SIGNED(ctx->r10) < 0) {
        // 0x80066104: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_8006605C;
    }
    // 0x80066104: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80066108: addiu       $a0, $t2, 0x1
    ctx->r4 = ADD32(ctx->r10, 0X1);
    // 0x8006610C: andi        $t9, $a0, 0x3
    ctx->r25 = ctx->r4 & 0X3;
    // 0x80066110: beq         $t9, $zero, L_80066164
    if (ctx->r25 == 0) {
        // 0x80066114: or          $t5, $t9, $zero
        ctx->r13 = ctx->r25 | 0;
            goto L_80066164;
    }
    // 0x80066114: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x80066118: addu        $t4, $a2, $zero
    ctx->r12 = ADD32(ctx->r6, 0);
L_8006611C:
    // 0x8006611C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80066120: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x80066124: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80066128: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8006612C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80066130: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x80066134: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80066138: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8006613C: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x80066140: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80066144: andi        $t7, $a3, 0xFFF
    ctx->r15 = ctx->r7 & 0XFFF;
    // 0x80066148: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8006614C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80066150: bne         $t5, $t3, L_8006611C
    if (ctx->r13 != ctx->r11) {
        // 0x80066154: sb          $a0, 0x0($t6)
        MEM_B(0X0, ctx->r14) = ctx->r4;
            goto L_8006611C;
    }
    // 0x80066154: sb          $a0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r4;
    // 0x80066158: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8006615C: beq         $t8, $t3, L_80066060
    if (ctx->r24 == ctx->r11) {
        // 0x80066160: srl         $t8, $t0, 1
        ctx->r24 = S32(U32(ctx->r8) >> 1);
            goto L_80066060;
    }
    // 0x80066160: srl         $t8, $t0, 1
    ctx->r24 = S32(U32(ctx->r8) >> 1);
L_80066164:
    // 0x80066164: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x80066168: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8006616C: addiu       $s1, $t4, 0x2
    ctx->r17 = ADD32(ctx->r12, 0X2);
    // 0x80066170: addiu       $s2, $t4, 0x3
    ctx->r18 = ADD32(ctx->r12, 0X3);
L_80066174:
    // 0x80066174: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80066178: andi        $t9, $t4, 0xFFF
    ctx->r25 = ctx->r12 & 0XFFF;
    // 0x8006617C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80066180: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x80066184: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x80066188: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x8006618C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80066190: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x80066194: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x80066198: sb          $a0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r4;
    // 0x8006619C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800661A0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800661A4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800661A8: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x800661AC: andi        $t6, $a3, 0xFFF
    ctx->r14 = ctx->r7 & 0XFFF;
    // 0x800661B0: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800661B4: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x800661B8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800661BC: andi        $t9, $s1, 0xFFF
    ctx->r25 = ctx->r17 & 0XFFF;
    // 0x800661C0: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x800661C4: sb          $a0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r4;
    // 0x800661C8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800661CC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800661D0: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800661D4: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x800661D8: andi        $t8, $a3, 0xFFF
    ctx->r24 = ctx->r7 & 0XFFF;
    // 0x800661DC: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x800661E0: sb          $a0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r4;
    // 0x800661E4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800661E8: andi        $t7, $s2, 0xFFF
    ctx->r15 = ctx->r18 & 0XFFF;
    // 0x800661EC: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x800661F0: sb          $a0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r4;
    // 0x800661F4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800661F8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800661FC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80066200: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x80066204: andi        $t6, $a3, 0xFFF
    ctx->r14 = ctx->r7 & 0XFFF;
    // 0x80066208: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8006620C: sb          $a0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r4;
    // 0x80066210: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80066214: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x80066218: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x8006621C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80066220: andi        $t8, $a3, 0xFFF
    ctx->r24 = ctx->r7 & 0XFFF;
    // 0x80066224: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80066228: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8006622C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80066230: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x80066234: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80066238: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006623C: bne         $t9, $t3, L_80066174
    if (ctx->r25 != ctx->r11) {
        // 0x80066240: sb          $a0, 0x0($t7)
        MEM_B(0X0, ctx->r15) = ctx->r4;
            goto L_80066174;
    }
    // 0x80066240: sb          $a0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r4;
    // 0x80066244: b           L_80066060
    // 0x80066248: srl         $t8, $t0, 1
    ctx->r24 = S32(U32(ctx->r8) >> 1);
        goto L_80066060;
    // 0x80066248: srl         $t8, $t0, 1
    ctx->r24 = S32(U32(ctx->r8) >> 1);
L_8006624C:
    // 0x8006624C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80066250: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80066254: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80066258: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8006625C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066260: jr          $ra
    // 0x80066264: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    return;
    // 0x80066264: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
;}
RECOMP_FUNC void func_80066268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066268: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8006626C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80066270: bne         $a2, $zero, L_80066280
    if (ctx->r6 != 0) {
        // 0x80066274: sw          $s0, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r16;
            goto L_80066280;
    }
    // 0x80066274: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80066278: b           L_80066404
    // 0x8006627C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80066404;
    // 0x8006627C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80066280:
    // 0x80066280: addu        $a3, $a0, $a2
    ctx->r7 = ADD32(ctx->r4, ctx->r6);
    // 0x80066284: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80066288: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8006628C: subu        $t0, $a3, $a0
    ctx->r8 = SUB32(ctx->r7, ctx->r4);
    // 0x80066290: addiu       $s1, $sp, 0x24
    ctx->r17 = ADD32(ctx->r29, 0X24);
    // 0x80066294: addiu       $s0, $zero, 0x7F
    ctx->r16 = ADD32(0, 0X7F);
    // 0x80066298: addiu       $t5, $zero, 0x81
    ctx->r13 = ADD32(0, 0X81);
    // 0x8006629C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_800662A0:
    // 0x800662A0: bne         $t4, $t0, L_800662C4
    if (ctx->r12 != ctx->r8) {
        // 0x800662A4: nop
    
            goto L_800662C4;
    }
    // 0x800662A4: nop

    // 0x800662A8: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x800662AC: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800662B0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800662B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800662B8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800662BC: b           L_800663F4
    // 0x800662C0: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
        goto L_800663F4;
    // 0x800662C0: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
L_800662C4:
    // 0x800662C4: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800662C8: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800662CC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800662D0: bne         $t7, $t8, L_80066348
    if (ctx->r15 != ctx->r24) {
        // 0x800662D4: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_80066348;
    }
    // 0x800662D4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800662D8: sb          $zero, 0x24($sp)
    MEM_B(0X24, ctx->r29) = 0;
    // 0x800662DC: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800662E0: nop

    // 0x800662E4: sb          $t9, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r25;
    // 0x800662E8: andi        $a0, $t9, 0xFF
    ctx->r4 = ctx->r25 & 0XFF;
L_800662EC:
    // 0x800662EC: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800662F0: lbu         $t7, 0x24($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X24);
    // 0x800662F4: bne         $t6, $a0, L_80066318
    if (ctx->r14 != ctx->r4) {
        // 0x800662F8: addiu       $t8, $t7, 0x1
        ctx->r24 = ADD32(ctx->r15, 0X1);
            goto L_80066318;
    }
    // 0x800662F8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800662FC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80066300: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80066304: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80066308: bne         $s0, $t9, L_8006631C
    if (ctx->r16 != ctx->r25) {
        // 0x8006630C: sb          $t8, 0x24($sp)
        MEM_B(0X24, ctx->r29) = ctx->r24;
            goto L_8006631C;
    }
    // 0x8006630C: sb          $t8, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r24;
    // 0x80066310: b           L_8006631C
    // 0x80066314: or          $t1, $t4, $zero
    ctx->r9 = ctx->r12 | 0;
        goto L_8006631C;
    // 0x80066314: or          $t1, $t4, $zero
    ctx->r9 = ctx->r12 | 0;
L_80066318:
    // 0x80066318: or          $t1, $t4, $zero
    ctx->r9 = ctx->r12 | 0;
L_8006631C:
    // 0x8006631C: sltu        $at, $v0, $a3
    ctx->r1 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x80066320: beq         $at, $zero, L_80066334
    if (ctx->r1 == 0) {
        // 0x80066324: lbu         $t6, 0x24($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X24);
            goto L_80066334;
    }
    // 0x80066324: lbu         $t6, 0x24($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X24);
    // 0x80066328: beq         $t1, $zero, L_800662EC
    if (ctx->r9 == 0) {
        // 0x8006632C: nop
    
            goto L_800662EC;
    }
    // 0x8006632C: nop

    // 0x80066330: lbu         $t6, 0x24($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X24);
L_80066334:
    // 0x80066334: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80066338: sb          $t6, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r14;
    // 0x8006633C: lbu         $t7, 0x25($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X25);
    // 0x80066340: b           L_800663F4
    // 0x80066344: sb          $t7, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r15;
        goto L_800663F4;
    // 0x80066344: sb          $t7, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r15;
L_80066348:
    // 0x80066348: sb          $t5, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r13;
    // 0x8006634C: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80066350: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80066354: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80066358: addiu       $a2, $v0, 0x1
    ctx->r6 = ADD32(ctx->r2, 0X1);
    // 0x8006635C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80066360: sb          $t8, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r24;
L_80066364:
    // 0x80066364: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80066368: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x8006636C: addu        $t6, $s1, $t2
    ctx->r14 = ADD32(ctx->r17, ctx->r10);
    // 0x80066370: beq         $a0, $t9, L_800663A4
    if (ctx->r4 == ctx->r25) {
        // 0x80066374: nop
    
            goto L_800663A4;
    }
    // 0x80066374: nop

    // 0x80066378: sb          $a0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r4;
    // 0x8006637C: lbu         $t7, 0x24($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X24);
    // 0x80066380: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80066384: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80066388: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8006638C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80066390: bne         $t2, $s0, L_8006639C
    if (ctx->r10 != ctx->r16) {
        // 0x80066394: sb          $t8, 0x24($sp)
        MEM_B(0X24, ctx->r29) = ctx->r24;
            goto L_8006639C;
    }
    // 0x80066394: sb          $t8, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r24;
    // 0x80066398: or          $t1, $t4, $zero
    ctx->r9 = ctx->r12 | 0;
L_8006639C:
    // 0x8006639C: b           L_800663A8
    // 0x800663A0: addiu       $a2, $v0, 0x1
    ctx->r6 = ADD32(ctx->r2, 0X1);
        goto L_800663A8;
    // 0x800663A0: addiu       $a2, $v0, 0x1
    ctx->r6 = ADD32(ctx->r2, 0X1);
L_800663A4:
    // 0x800663A4: or          $t1, $t4, $zero
    ctx->r9 = ctx->r12 | 0;
L_800663A8:
    // 0x800663A8: sltu        $at, $a2, $a3
    ctx->r1 = ctx->r6 < ctx->r7 ? 1 : 0;
    // 0x800663AC: beq         $at, $zero, L_800663C0
    if (ctx->r1 == 0) {
        // 0x800663B0: lbu         $t9, 0x24($sp)
        ctx->r25 = MEM_BU(ctx->r29, 0X24);
            goto L_800663C0;
    }
    // 0x800663B0: lbu         $t9, 0x24($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X24);
    // 0x800663B4: beq         $t1, $zero, L_80066364
    if (ctx->r9 == 0) {
        // 0x800663B8: nop
    
            goto L_80066364;
    }
    // 0x800663B8: nop

    // 0x800663BC: lbu         $t9, 0x24($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X24);
L_800663C0:
    // 0x800663C0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800663C4: andi        $t6, $t9, 0x7F
    ctx->r14 = ctx->r25 & 0X7F;
    // 0x800663C8: bltz        $t6, L_800663F8
    if (SIGNED(ctx->r14) < 0) {
        // 0x800663CC: sltu        $at, $v0, $a3
        ctx->r1 = ctx->r2 < ctx->r7 ? 1 : 0;
            goto L_800663F8;
    }
    // 0x800663CC: sltu        $at, $v0, $a3
    ctx->r1 = ctx->r2 < ctx->r7 ? 1 : 0;
L_800663D0:
    // 0x800663D0: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x800663D4: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800663D8: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x800663DC: lbu         $t8, 0x24($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X24);
    // 0x800663E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800663E4: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x800663E8: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800663EC: beq         $at, $zero, L_800663D0
    if (ctx->r1 == 0) {
        // 0x800663F0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800663D0;
    }
    // 0x800663F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800663F4:
    // 0x800663F4: sltu        $at, $v0, $a3
    ctx->r1 = ctx->r2 < ctx->r7 ? 1 : 0;
L_800663F8:
    // 0x800663F8: bne         $at, $zero, L_800662A0
    if (ctx->r1 != 0) {
        // 0x800663FC: nop
    
            goto L_800662A0;
    }
    // 0x800663FC: nop

    // 0x80066400: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
L_80066404:
    // 0x80066404: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80066408: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8006640C: jr          $ra
    // 0x80066410: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80066410: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_80066414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066414: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80066418: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006641C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80066420: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80066424: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80066428: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006642C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80066430: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80066434: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80066438: addu        $s3, $a0, $a2
    ctx->r19 = ADD32(ctx->r4, ctx->r6);
L_8006643C:
    // 0x8006643C: lbu         $s1, 0x0($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X0);
    // 0x80066440: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80066444: andi        $t6, $s1, 0x80
    ctx->r14 = ctx->r17 & 0X80;
    // 0x80066448: beq         $t6, $zero, L_80066470
    if (ctx->r14 == 0) {
        // 0x8006644C: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_80066470;
    }
    // 0x8006644C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80066450: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80066454: andi        $a2, $s1, 0x7F
    ctx->r6 = ctx->r17 & 0X7F;
    // 0x80066458: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8006645C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80066460: jal         0x8006B450
    // 0x80066464: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x80066464: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80066468: b           L_80066484
    // 0x8006646C: addu        $s0, $s0, $s1
    ctx->r16 = ADD32(ctx->r16, ctx->r17);
        goto L_80066484;
    // 0x8006646C: addu        $s0, $s0, $s1
    ctx->r16 = ADD32(ctx->r16, ctx->r17);
L_80066470:
    // 0x80066470: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x80066474: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80066478: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8006647C: jal         0x80061938
    // 0x80066480: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_80061938(rdram, ctx);
        goto after_1;
    // 0x80066480: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_1:
L_80066484:
    // 0x80066484: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80066488: bne         $at, $zero, L_8006643C
    if (ctx->r1 != 0) {
        // 0x8006648C: addu        $s2, $s2, $s1
        ctx->r18 = ADD32(ctx->r18, ctx->r17);
            goto L_8006643C;
    }
    // 0x8006648C: addu        $s2, $s2, $s1
    ctx->r18 = ADD32(ctx->r18, ctx->r17);
    // 0x80066490: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80066494: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80066498: subu        $v0, $s2, $t8
    ctx->r2 = SUB32(ctx->r18, ctx->r24);
    // 0x8006649C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800664A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800664A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800664A8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800664AC: jr          $ra
    // 0x800664B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800664B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800664B4: nop

    // 0x800664B8: nop

    // 0x800664BC: nop

;}
RECOMP_FUNC void func_800664C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800664C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800664C4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800664C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800664CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800664D0: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800664D4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800664D8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800664DC: lh          $a1, 0x0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X0);
    // 0x800664E0: lh          $a2, 0x2($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X2);
    // 0x800664E4: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    // 0x800664E8: jal         0x80066AC0
    // 0x800664EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80066AC0(rdram, ctx);
        goto after_0;
    // 0x800664EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x800664F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800664F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800664F8: jr          $ra
    // 0x800664FC: nop

    return;
    // 0x800664FC: nop

;}
RECOMP_FUNC void func_80066500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066500: jr          $ra
    // 0x80066504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80066504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80066508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066508: jr          $ra
    // 0x8006650C: nop

    return;
    // 0x8006650C: nop

;}
RECOMP_FUNC void func_80066510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066510: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066514: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066518: beq         $a0, $zero, L_80066538
    if (ctx->r4 == 0) {
        // 0x8006651C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80066538;
    }
    // 0x8006651C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80066520: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    // 0x80066524: jal         0x800653C4
    // 0x80066528: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800653C4(rdram, ctx);
        goto after_0;
    // 0x80066528: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006652C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80066530: jal         0x800653C4
    // 0x80066534: nop

    func_800653C4(rdram, ctx);
        goto after_1;
    // 0x80066534: nop

    after_1:
L_80066538:
    // 0x80066538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006653C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066540: jr          $ra
    // 0x80066544: nop

    return;
    // 0x80066544: nop

;}
RECOMP_FUNC void func_80066548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066548: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8006654C: addiu       $v1, $v1, -0x31D8
    ctx->r3 = ADD32(ctx->r3, -0X31D8);
    // 0x80066550: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // FALLTHROUGH FIX: func_80066548 falls through to func_80066554
    func_80066554(rdram, ctx);
;}
