#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

RECOMP_FUNC void func_80066554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066554: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066558: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8006655C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066560: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80066564: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80066568: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006656C: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x80066570: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x80066574: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80066578: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006657C: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x80066580: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80066584: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80066588: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006658C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80066590: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066594: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80066598: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006659C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800665A0: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x800665A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800665A8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800665AC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800665B0: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800665B4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800665B8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800665BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800665C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800665C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800665C8: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x800665CC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800665D0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800665D4: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x800665D8: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x800665DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800665E0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800665E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800665E8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800665EC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800665F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800665F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800665F8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800665FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066600: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x80066604: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80066608: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006660C: ori         $t6, $t6, 0xE02
    ctx->r14 = ctx->r14 | 0XE02;
    // 0x80066610: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80066614: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80066618: jal         0x800664C0
    // 0x8006661C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    func_800664C0(rdram, ctx);
        goto after_0;
    // 0x8006661C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_0:
    // 0x80066620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066628: jr          $ra
    // 0x8006662C: nop

    return;
    // 0x8006662C: nop

;}
RECOMP_FUNC void func_80066630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066630: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80066634: lw          $t6, 0x59EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X59EC);
    // 0x80066638: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8006663C: beq         $a0, $t6, L_80066AB8
    if (ctx->r4 == ctx->r14) {
        // 0x80066640: nop
    
            goto L_80066AB8;
    }
    // 0x80066640: nop

    // 0x80066644: sw          $a0, 0x59EC($at)
    MEM_W(0X59EC, ctx->r1) = ctx->r4;
    // 0x80066648: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    // 0x8006664C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80066650: bne         $v0, $at, L_800668D8
    if (ctx->r2 != ctx->r1) {
        // 0x80066654: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800668D8;
    }
    // 0x80066654: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80066658: addiu       $v1, $v1, -0x31D8
    ctx->r3 = ADD32(ctx->r3, -0X31D8);
    // 0x8006665C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066660: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x80066664: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80066668: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006666C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80066670: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x80066674: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x80066678: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8006667C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066680: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x80066684: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80066688: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006668C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80066690: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80066694: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066698: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8006669C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800666A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800666A4: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x800666A8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800666AC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800666B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800666B4: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800666B8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800666BC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800666C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800666C4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800666C8: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800666CC: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x800666D0: addiu       $t9, $t1, 0x8
    ctx->r25 = ADD32(ctx->r9, 0X8);
    // 0x800666D4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800666D8: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x800666DC: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x800666E0: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x800666E4: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x800666E8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800666EC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800666F0: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x800666F4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800666F8: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800666FC: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80066700: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066704: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x80066708: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8006670C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80066710: ori         $t7, $t7, 0xE02
    ctx->r15 = ctx->r15 | 0XE02;
    // 0x80066714: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x80066718: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8006671C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80066720: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80066724: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x80066728: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x8006672C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80066730: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80066734: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80066738: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x8006673C: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80066740: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80066744: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80066748: addiu       $t8, $t5, 0x8
    ctx->r24 = ADD32(ctx->r13, 0X8);
    // 0x8006674C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80066750: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x80066754: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x80066758: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x8006675C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066760: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80066764: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80066768: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006676C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80066770: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80066774: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80066778: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8006677C: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x80066780: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80066784: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80066788: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x8006678C: lh          $a3, 0x0($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X0);
    // 0x80066790: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
    // 0x80066794: multu       $a3, $t7
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066798: mflo        $t3
    ctx->r11 = lo;
    // 0x8006679C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800667A0: sra         $t8, $t3, 1
    ctx->r24 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800667A4: addiu       $t3, $t8, -0x1
    ctx->r11 = ADD32(ctx->r24, -0X1);
    // 0x800667A8: slti        $at, $t3, 0x7FF
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF ? 1 : 0;
    // 0x800667AC: beq         $at, $zero, L_800667BC
    if (ctx->r1 == 0) {
        // 0x800667B0: nop
    
            goto L_800667BC;
    }
    // 0x800667B0: nop

    // 0x800667B4: b           L_800667BC
    // 0x800667B8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
        goto L_800667BC;
    // 0x800667B8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_800667BC:
    // 0x800667BC: bgez        $a3, L_800667CC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800667C0: sra         $v0, $a3, 3
        ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
            goto L_800667CC;
    }
    // 0x800667C0: sra         $v0, $a3, 3
    ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
    // 0x800667C4: addiu       $at, $a3, 0x7
    ctx->r1 = ADD32(ctx->r7, 0X7);
    // 0x800667C8: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_800667CC:
    // 0x800667CC: bgtz        $v0, L_800667DC
    if (SIGNED(ctx->r2) > 0) {
        // 0x800667D0: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800667DC;
    }
    // 0x800667D0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800667D4: b           L_800667DC
    // 0x800667D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800667DC;
    // 0x800667D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800667DC:
    // 0x800667DC: bgtz        $v0, L_800667EC
    if (SIGNED(ctx->r2) > 0) {
        // 0x800667E0: addiu       $t9, $a3, 0x7FF
        ctx->r25 = ADD32(ctx->r7, 0X7FF);
            goto L_800667EC;
    }
    // 0x800667E0: addiu       $t9, $a3, 0x7FF
    ctx->r25 = ADD32(ctx->r7, 0X7FF);
    // 0x800667E4: b           L_800667F0
    // 0x800667E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_800667F0;
    // 0x800667E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800667EC:
    // 0x800667EC: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_800667F0:
    // 0x800667F0: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x800667F4: bne         $t0, $zero, L_80066800
    if (ctx->r8 != 0) {
        // 0x800667F8: nop
    
            goto L_80066800;
    }
    // 0x800667F8: nop

    // 0x800667FC: break       7
    do_break(2147903484);
L_80066800:
    // 0x80066800: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80066804: bne         $t0, $at, L_80066818
    if (ctx->r8 != ctx->r1) {
        // 0x80066808: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80066818;
    }
    // 0x80066808: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006680C: bne         $t9, $at, L_80066818
    if (ctx->r25 != ctx->r1) {
        // 0x80066810: nop
    
            goto L_80066818;
    }
    // 0x80066810: nop

    // 0x80066814: break       6
    do_break(2147903508);
L_80066818:
    // 0x80066818: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8006681C: andi        $t9, $a1, 0xFFF
    ctx->r25 = ctx->r5 & 0XFFF;
    // 0x80066820: mflo        $t6
    ctx->r14 = lo;
    // 0x80066824: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80066828: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8006682C: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80066830: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80066834: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80066838: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006683C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80066840: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80066844: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80066848: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006684C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80066850: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80066854: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066858: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8006685C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80066860: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80066864: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80066868: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8006686C: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x80066870: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80066874: andi        $t6, $t8, 0x1FF
    ctx->r14 = ctx->r24 & 0X1FF;
    // 0x80066878: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x8006687C: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x80066880: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80066884: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80066888: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8006688C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80066890: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066894: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x80066898: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8006689C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800668A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800668A4: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x800668A8: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800668AC: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x800668B0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800668B4: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x800668B8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800668BC: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800668C0: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800668C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800668C8: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800668CC: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800668D0: jr          $ra
    // 0x800668D4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    return;
    // 0x800668D4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800668D8:
    // 0x800668D8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800668DC: bne         $v0, $at, L_80066AB8
    if (ctx->r2 != ctx->r1) {
        // 0x800668E0: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80066AB8;
    }
    // 0x800668E0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800668E4: addiu       $v1, $v1, -0x31D8
    ctx->r3 = ADD32(ctx->r3, -0X31D8);
    // 0x800668E8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800668EC: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800668F0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800668F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800668F8: ori         $t9, $t9, 0xE02
    ctx->r25 = ctx->r25 | 0XE02;
    // 0x800668FC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80066900: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80066904: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066908: lui         $t6, 0xFD90
    ctx->r14 = S32(0XFD90 << 16);
    // 0x8006690C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80066910: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80066914: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80066918: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8006691C: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x80066920: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80066924: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80066928: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8006692C: addiu       $t9, $t1, 0x8
    ctx->r25 = ADD32(ctx->r9, 0X8);
    // 0x80066930: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80066934: lui         $t8, 0xF590
    ctx->r24 = S32(0XF590 << 16);
    // 0x80066938: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8006693C: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80066940: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80066944: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80066948: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x8006694C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80066950: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80066954: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80066958: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x8006695C: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80066960: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x80066964: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80066968: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8006696C: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80066970: lh          $a3, 0x0($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X0);
    // 0x80066974: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
    // 0x80066978: multu       $a3, $t7
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006697C: mflo        $t3
    ctx->r11 = lo;
    // 0x80066980: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80066984: sra         $t9, $t3, 1
    ctx->r25 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80066988: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x8006698C: slti        $at, $t3, 0x7FF
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF ? 1 : 0;
    // 0x80066990: beq         $at, $zero, L_800669A0
    if (ctx->r1 == 0) {
        // 0x80066994: nop
    
            goto L_800669A0;
    }
    // 0x80066994: nop

    // 0x80066998: b           L_800669A0
    // 0x8006699C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
        goto L_800669A0;
    // 0x8006699C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_800669A0:
    // 0x800669A0: bgez        $a3, L_800669B0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800669A4: sra         $v0, $a3, 3
        ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
            goto L_800669B0;
    }
    // 0x800669A4: sra         $v0, $a3, 3
    ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
    // 0x800669A8: addiu       $at, $a3, 0x7
    ctx->r1 = ADD32(ctx->r7, 0X7);
    // 0x800669AC: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_800669B0:
    // 0x800669B0: bgtz        $v0, L_800669C0
    if (SIGNED(ctx->r2) > 0) {
        // 0x800669B4: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800669C0;
    }
    // 0x800669B4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800669B8: b           L_800669C0
    // 0x800669BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800669C0;
    // 0x800669BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800669C0:
    // 0x800669C0: bgtz        $v0, L_800669D0
    if (SIGNED(ctx->r2) > 0) {
        // 0x800669C4: addiu       $t8, $a3, 0x7FF
        ctx->r24 = ADD32(ctx->r7, 0X7FF);
            goto L_800669D0;
    }
    // 0x800669C4: addiu       $t8, $a3, 0x7FF
    ctx->r24 = ADD32(ctx->r7, 0X7FF);
    // 0x800669C8: b           L_800669D4
    // 0x800669CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_800669D4;
    // 0x800669CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800669D0:
    // 0x800669D0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_800669D4:
    // 0x800669D4: div         $zero, $t8, $t0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r8)));
    // 0x800669D8: bne         $t0, $zero, L_800669E4
    if (ctx->r8 != 0) {
        // 0x800669DC: nop
    
            goto L_800669E4;
    }
    // 0x800669DC: nop

    // 0x800669E0: break       7
    do_break(2147903968);
L_800669E4:
    // 0x800669E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800669E8: bne         $t0, $at, L_800669FC
    if (ctx->r8 != ctx->r1) {
        // 0x800669EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800669FC;
    }
    // 0x800669EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800669F0: bne         $t8, $at, L_800669FC
    if (ctx->r24 != ctx->r1) {
        // 0x800669F4: nop
    
            goto L_800669FC;
    }
    // 0x800669F4: nop

    // 0x800669F8: break       6
    do_break(2147903992);
L_800669FC:
    // 0x800669FC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80066A00: andi        $t8, $a1, 0xFFF
    ctx->r24 = ctx->r5 & 0XFFF;
    // 0x80066A04: mflo        $t6
    ctx->r14 = lo;
    // 0x80066A08: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80066A0C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80066A10: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80066A14: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80066A18: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80066A1C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066A20: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80066A24: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80066A28: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80066A2C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80066A30: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80066A34: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80066A38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066A3C: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x80066A40: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80066A44: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80066A48: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80066A4C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80066A50: addiu       $t8, $t7, 0x7
    ctx->r24 = ADD32(ctx->r15, 0X7);
    // 0x80066A54: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80066A58: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x80066A5C: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x80066A60: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80066A64: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80066A68: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80066A6C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80066A70: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80066A74: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066A78: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x80066A7C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80066A80: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80066A84: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80066A88: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x80066A8C: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80066A90: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80066A94: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80066A98: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x80066A9C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80066AA0: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80066AA4: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x80066AA8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80066AAC: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80066AB0: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80066AB4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_80066AB8:
    // 0x80066AB8: jr          $ra
    // 0x80066ABC: nop

    return;
    // 0x80066ABC: nop

;}
RECOMP_FUNC void func_80066AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066AC0: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x80066AC4: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    // 0x80066AC8: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x80066ACC: addiu       $t7, $a1, 0x3F
    ctx->r15 = ADD32(ctx->r5, 0X3F);
    // 0x80066AD0: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x80066AD4: addiu       $t6, $t9, 0x1F
    ctx->r14 = ADD32(ctx->r25, 0X1F);
    // 0x80066AD8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80066ADC: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x80066AE0: addiu       $s2, $s2, -0x31D8
    ctx->r18 = ADD32(ctx->r18, -0X31D8);
    // 0x80066AE4: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x80066AE8: lw          $t9, 0x104($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X104);
    // 0x80066AEC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80066AF0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80066AF4: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80066AF8: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80066AFC: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80066B00: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80066B04: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80066B08: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80066B0C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80066B10: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80066B14: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x80066B18: bgez        $t7, L_80066B28
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80066B1C: sra         $t8, $t7, 6
        ctx->r24 = S32(SIGNED(ctx->r15) >> 6);
            goto L_80066B28;
    }
    // 0x80066B1C: sra         $t8, $t7, 6
    ctx->r24 = S32(SIGNED(ctx->r15) >> 6);
    // 0x80066B20: addiu       $at, $t7, 0x3F
    ctx->r1 = ADD32(ctx->r15, 0X3F);
    // 0x80066B24: sra         $t8, $at, 6
    ctx->r24 = S32(SIGNED(ctx->r1) >> 6);
L_80066B28:
    // 0x80066B28: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80066B2C: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
    // 0x80066B30: bgez        $t6, L_80066B40
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80066B34: sra         $t7, $t6, 5
        ctx->r15 = S32(SIGNED(ctx->r14) >> 5);
            goto L_80066B40;
    }
    // 0x80066B34: sra         $t7, $t6, 5
    ctx->r15 = S32(SIGNED(ctx->r14) >> 5);
    // 0x80066B38: addiu       $at, $t6, 0x1F
    ctx->r1 = ADD32(ctx->r14, 0X1F);
    // 0x80066B3C: sra         $t7, $at, 5
    ctx->r15 = S32(SIGNED(ctx->r1) >> 5);
L_80066B40:
    // 0x80066B40: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x80066B44: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x80066B48: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x80066B4C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80066B50: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80066B54: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80066B58: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x80066B5C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80066B60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80066B64: addu        $t9, $a0, $at
    ctx->r25 = ADD32(ctx->r4, ctx->r1);
    // 0x80066B68: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80066B6C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80066B70: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80066B74: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80066B78: blez        $t6, L_800671D8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80066B7C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800671D8;
    }
    // 0x80066B7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80066B80: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
L_80066B84:
    // 0x80066B84: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80066B88: blez        $t7, L_800671C0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80066B8C: addiu       $t8, $t0, 0x1
        ctx->r24 = ADD32(ctx->r8, 0X1);
            goto L_800671C0;
    }
    // 0x80066B8C: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x80066B90: lw          $t9, 0x10C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10C);
    // 0x80066B94: sll         $v0, $t0, 6
    ctx->r2 = S32(ctx->r8 << 6);
    // 0x80066B98: lw          $s7, 0x110($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X110);
    // 0x80066B9C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80066BA0: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x80066BA4: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80066BA8: sw          $t0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r8;
    // 0x80066BAC: addu        $fp, $t9, $v0
    ctx->r30 = ADD32(ctx->r25, ctx->r2);
L_80066BB0:
    // 0x80066BB0: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80066BB4: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80066BB8: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80066BBC: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80066BC0: lbu         $t5, 0x59E0($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X59E0);
    // 0x80066BC4: or          $s6, $ra, $zero
    ctx->r22 = ctx->r31 | 0;
    // 0x80066BC8: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x80066BCC: or          $s4, $s7, $zero
    ctx->r20 = ctx->r23 | 0;
    // 0x80066BD0: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x80066BD4: bne         $t6, $t7, L_80066C04
    if (ctx->r14 != ctx->r15) {
        // 0x80066BD8: addiu       $s1, $zero, 0x20
        ctx->r17 = ADD32(0, 0X20);
            goto L_80066C04;
    }
    // 0x80066BD8: addiu       $s1, $zero, 0x20
    ctx->r17 = ADD32(0, 0X20);
    // 0x80066BDC: lw          $v0, 0x104($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X104);
    // 0x80066BE0: nop

    // 0x80066BE4: bgez        $v0, L_80066BF8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80066BE8: andi        $t8, $v0, 0x3F
        ctx->r24 = ctx->r2 & 0X3F;
            goto L_80066BF8;
    }
    // 0x80066BE8: andi        $t8, $v0, 0x3F
    ctx->r24 = ctx->r2 & 0X3F;
    // 0x80066BEC: beq         $t8, $zero, L_80066BF8
    if (ctx->r24 == 0) {
        // 0x80066BF0: nop
    
            goto L_80066BF8;
    }
    // 0x80066BF0: nop

    // 0x80066BF4: addiu       $t8, $t8, -0x40
    ctx->r24 = ADD32(ctx->r24, -0X40);
L_80066BF8:
    // 0x80066BF8: bne         $t8, $zero, L_80066C04
    if (ctx->r24 != 0) {
        // 0x80066BFC: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_80066C04;
    }
    // 0x80066BFC: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80066C00: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
L_80066C04:
    // 0x80066C04: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80066C08: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80066C0C: bne         $t9, $v0, L_80066C3C
    if (ctx->r25 != ctx->r2) {
        // 0x80066C10: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_80066C3C;
    }
    // 0x80066C10: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80066C14: lw          $v0, 0x108($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X108);
    // 0x80066C18: nop

    // 0x80066C1C: bgez        $v0, L_80066C30
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80066C20: andi        $t6, $v0, 0x1F
        ctx->r14 = ctx->r2 & 0X1F;
            goto L_80066C30;
    }
    // 0x80066C20: andi        $t6, $v0, 0x1F
    ctx->r14 = ctx->r2 & 0X1F;
    // 0x80066C24: beq         $t6, $zero, L_80066C30
    if (ctx->r14 == 0) {
        // 0x80066C28: nop
    
            goto L_80066C30;
    }
    // 0x80066C28: nop

    // 0x80066C2C: addiu       $t6, $t6, -0x20
    ctx->r14 = ADD32(ctx->r14, -0X20);
L_80066C30:
    // 0x80066C30: bne         $t6, $zero, L_80066C3C
    if (ctx->r14 != 0) {
        // 0x80066C34: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_80066C3C;
    }
    // 0x80066C34: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80066C38: addiu       $s1, $zero, 0x20
    ctx->r17 = ADD32(0, 0X20);
L_80066C3C:
    // 0x80066C3C: bne         $t5, $zero, L_80066C88
    if (ctx->r13 != 0) {
        // 0x80066C40: lui         $t7, 0x8008
        ctx->r15 = S32(0X8008 << 16);
            goto L_80066C88;
    }
    // 0x80066C40: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80066C44: lbu         $t7, 0x59E4($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X59E4);
    // 0x80066C48: nop

    // 0x80066C4C: bne         $t7, $zero, L_80066C8C
    if (ctx->r15 != 0) {
        // 0x80066C50: addiu       $t1, $s5, 0x40
        ctx->r9 = ADD32(ctx->r21, 0X40);
            goto L_80066C8C;
    }
    // 0x80066C50: addiu       $t1, $s5, 0x40
    ctx->r9 = ADD32(ctx->r21, 0X40);
    // 0x80066C54: bgez        $fp, L_80066C70
    if (SIGNED(ctx->r30) >= 0) {
        // 0x80066C58: slti        $at, $fp, -0x40
        ctx->r1 = SIGNED(ctx->r30) < -0X40 ? 1 : 0;
            goto L_80066C70;
    }
    // 0x80066C58: slti        $at, $fp, -0x40
    ctx->r1 = SIGNED(ctx->r30) < -0X40 ? 1 : 0;
    // 0x80066C5C: bne         $at, $zero, L_800671A4
    if (ctx->r1 != 0) {
        // 0x80066C60: addu        $s0, $s0, $fp
        ctx->r16 = ADD32(ctx->r16, ctx->r30);
            goto L_800671A4;
    }
    // 0x80066C60: addu        $s0, $s0, $fp
    ctx->r16 = ADD32(ctx->r16, ctx->r30);
    // 0x80066C64: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80066C68: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80066C6C: subu        $s5, $t8, $fp
    ctx->r21 = SUB32(ctx->r24, ctx->r30);
L_80066C70:
    // 0x80066C70: bgez        $s7, L_80066C88
    if (SIGNED(ctx->r23) >= 0) {
        // 0x80066C74: slti        $at, $s7, -0x20
        ctx->r1 = SIGNED(ctx->r23) < -0X20 ? 1 : 0;
            goto L_80066C88;
    }
    // 0x80066C74: slti        $at, $s7, -0x20
    ctx->r1 = SIGNED(ctx->r23) < -0X20 ? 1 : 0;
    // 0x80066C78: bne         $at, $zero, L_800671A4
    if (ctx->r1 != 0) {
        // 0x80066C7C: addu        $s1, $s1, $s7
        ctx->r17 = ADD32(ctx->r17, ctx->r23);
            goto L_800671A4;
    }
    // 0x80066C7C: addu        $s1, $s1, $s7
    ctx->r17 = ADD32(ctx->r17, ctx->r23);
    // 0x80066C80: subu        $s6, $ra, $s7
    ctx->r22 = SUB32(ctx->r31, ctx->r23);
    // 0x80066C84: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80066C88:
    // 0x80066C88: addiu       $t1, $s5, 0x40
    ctx->r9 = ADD32(ctx->r21, 0X40);
L_80066C8C:
    // 0x80066C8C: subu        $t2, $t1, $s5
    ctx->r10 = SUB32(ctx->r9, ctx->r21);
    // 0x80066C90: addiu       $t2, $t2, 0x7
    ctx->r10 = ADD32(ctx->r10, 0X7);
    // 0x80066C94: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80066C98: sra         $t6, $t2, 3
    ctx->r14 = S32(SIGNED(ctx->r10) >> 3);
    // 0x80066C9C: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80066CA0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80066CA4: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80066CA8: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x80066CAC: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x80066CB0: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80066CB4: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x80066CB8: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80066CBC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80066CC0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80066CC4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80066CC8: sll         $a1, $s5, 2
    ctx->r5 = S32(ctx->r21 << 2);
    // 0x80066CCC: andi        $t8, $a1, 0xFFF
    ctx->r24 = ctx->r5 & 0XFFF;
    // 0x80066CD0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80066CD4: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80066CD8: sll         $a1, $t8, 12
    ctx->r5 = S32(ctx->r24 << 12);
    // 0x80066CDC: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80066CE0: sll         $a2, $s6, 2
    ctx->r6 = S32(ctx->r22 << 2);
    // 0x80066CE4: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x80066CE8: or          $t7, $a1, $at
    ctx->r15 = ctx->r5 | ctx->r1;
    // 0x80066CEC: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80066CF0: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x80066CF4: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80066CF8: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80066CFC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80066D00: addiu       $t4, $s6, 0x1F
    ctx->r12 = ADD32(ctx->r22, 0X1F);
    // 0x80066D04: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80066D08: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80066D0C: sll         $t3, $t6, 12
    ctx->r11 = S32(ctx->r14 << 12);
    // 0x80066D10: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80066D14: or          $t6, $t3, $at
    ctx->r14 = ctx->r11 | ctx->r1;
    // 0x80066D18: andi        $t4, $t8, 0xFFF
    ctx->r12 = ctx->r24 & 0XFFF;
    // 0x80066D1C: or          $t7, $t6, $t4
    ctx->r15 = ctx->r14 | ctx->r12;
    // 0x80066D20: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80066D24: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80066D28: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80066D2C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80066D30: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80066D34: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80066D38: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80066D3C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80066D40: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80066D44: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80066D48: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80066D4C: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80066D50: or          $t7, $a1, $at
    ctx->r15 = ctx->r5 | ctx->r1;
    // 0x80066D54: or          $t8, $t7, $a2
    ctx->r24 = ctx->r15 | ctx->r6;
    // 0x80066D58: or          $t9, $t3, $t4
    ctx->r25 = ctx->r11 | ctx->r12;
    // 0x80066D5C: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80066D60: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80066D64: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80066D68: lbu         $t5, 0x59E0($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X59E0);
    // 0x80066D6C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80066D70: bne         $t5, $zero, L_80066D88
    if (ctx->r13 != 0) {
        // 0x80066D74: lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
            goto L_80066D88;
    }
    // 0x80066D74: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80066D78: lbu         $t6, 0x59E4($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X59E4);
    // 0x80066D7C: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80066D80: beq         $t6, $zero, L_80066FE4
    if (ctx->r14 == 0) {
        // 0x80066D84: lui         $at, 0xE400
        ctx->r1 = S32(0XE400 << 16);
            goto L_80066FE4;
    }
    // 0x80066D84: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
L_80066D88:
    // 0x80066D88: lbu         $v0, 0x59E4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X59E4);
    // 0x80066D8C: beq         $t5, $zero, L_80066DBC
    if (ctx->r13 == 0) {
        // 0x80066D90: lui         $at, 0xE400
        ctx->r1 = S32(0XE400 << 16);
            goto L_80066DBC;
    }
    // 0x80066D90: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80066D94: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x80066D98: lw          $t9, 0x10C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10C);
    // 0x80066D9C: subu        $t8, $t7, $s3
    ctx->r24 = SUB32(ctx->r15, ctx->r19);
    // 0x80066DA0: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80066DA4: subu        $t7, $t6, $s0
    ctx->r15 = SUB32(ctx->r14, ctx->r16);
    // 0x80066DA8: addu        $s5, $s5, $s0
    ctx->r21 = ADD32(ctx->r21, ctx->r16);
    // 0x80066DAC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80066DB0: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80066DB4: b           L_80066DC0
    // 0x80066DB8: addu        $s3, $t7, $t9
    ctx->r19 = ADD32(ctx->r15, ctx->r25);
        goto L_80066DC0;
    // 0x80066DB8: addu        $s3, $t7, $t9
    ctx->r19 = ADD32(ctx->r15, ctx->r25);
L_80066DBC:
    // 0x80066DBC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80066DC0:
    // 0x80066DC0: beq         $v0, $zero, L_80066DF0
    if (ctx->r2 == 0) {
        // 0x80066DC4: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80066DF0;
    }
    // 0x80066DC4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80066DC8: lw          $t8, 0x108($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X108);
    // 0x80066DCC: lw          $v0, 0x110($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X110);
    // 0x80066DD0: subu        $t6, $t8, $s4
    ctx->r14 = SUB32(ctx->r24, ctx->r20);
    // 0x80066DD4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80066DD8: subu        $t9, $t7, $s1
    ctx->r25 = SUB32(ctx->r15, ctx->r17);
    // 0x80066DDC: addu        $s6, $s6, $s1
    ctx->r22 = ADD32(ctx->r22, ctx->r17);
    // 0x80066DE0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80066DE4: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x80066DE8: b           L_80066DF4
    // 0x80066DEC: addu        $s4, $t9, $v0
    ctx->r20 = ADD32(ctx->r25, ctx->r2);
        goto L_80066DF4;
    // 0x80066DEC: addu        $s4, $t9, $v0
    ctx->r20 = ADD32(ctx->r25, ctx->r2);
L_80066DF0:
    // 0x80066DF0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_80066DF4:
    // 0x80066DF4: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80066DF8: addu        $t6, $s3, $s0
    ctx->r14 = ADD32(ctx->r19, ctx->r16);
    // 0x80066DFC: sll         $t7, $t6, 18
    ctx->r15 = S32(ctx->r14 << 18);
    // 0x80066E00: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80066E04: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x80066E08: blez        $t9, L_80066E18
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80066E0C: sw          $t8, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r24;
            goto L_80066E18;
    }
    // 0x80066E0C: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80066E10: b           L_80066E1C
    // 0x80066E14: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
        goto L_80066E1C;
    // 0x80066E14: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_80066E18:
    // 0x80066E18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80066E1C:
    // 0x80066E1C: addu        $t8, $s4, $s1
    ctx->r24 = ADD32(ctx->r20, ctx->r17);
    // 0x80066E20: sll         $t6, $t8, 18
    ctx->r14 = S32(ctx->r24 << 18);
    // 0x80066E24: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80066E28: blez        $t7, L_80066E38
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80066E2C: andi        $t6, $a0, 0xFFF
        ctx->r14 = ctx->r4 & 0XFFF;
            goto L_80066E38;
    }
    // 0x80066E2C: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x80066E30: b           L_80066E3C
    // 0x80066E34: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_80066E3C;
    // 0x80066E34: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_80066E38:
    // 0x80066E38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80066E3C:
    // 0x80066E3C: andi        $t9, $v1, 0xFFF
    ctx->r25 = ctx->r3 & 0XFFF;
    // 0x80066E40: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80066E44: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80066E48: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80066E4C: sll         $t6, $a1, 18
    ctx->r14 = S32(ctx->r5 << 18);
    // 0x80066E50: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80066E54: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80066E58: blez        $t8, L_80066E68
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80066E5C: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_80066E68;
    }
    // 0x80066E5C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80066E60: b           L_80066E6C
    // 0x80066E64: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
        goto L_80066E6C;
    // 0x80066E64: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
L_80066E68:
    // 0x80066E68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80066E6C:
    // 0x80066E6C: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x80066E70: sll         $t1, $t2, 16
    ctx->r9 = S32(ctx->r10 << 16);
    // 0x80066E74: sra         $t7, $t1, 16
    ctx->r15 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80066E78: blez        $t7, L_80066E88
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80066E7C: or          $t1, $t7, $zero
        ctx->r9 = ctx->r15 | 0;
            goto L_80066E88;
    }
    // 0x80066E7C: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x80066E80: b           L_80066E8C
    // 0x80066E84: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_80066E8C;
    // 0x80066E84: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_80066E88:
    // 0x80066E88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80066E8C:
    // 0x80066E8C: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x80066E90: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80066E94: andi        $t9, $v1, 0xFFF
    ctx->r25 = ctx->r3 & 0XFFF;
    // 0x80066E98: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80066E9C: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80066EA0: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80066EA4: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x80066EA8: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80066EAC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80066EB0: bgez        $a1, L_80066F20
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80066EB4: sw          $t9, 0x0($t5)
        MEM_W(0X0, ctx->r13) = ctx->r25;
            goto L_80066F20;
    }
    // 0x80066EB4: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x80066EB8: sll         $t3, $t0, 10
    ctx->r11 = S32(ctx->r8 << 10);
    // 0x80066EBC: sll         $v1, $t3, 16
    ctx->r3 = S32(ctx->r11 << 16);
    // 0x80066EC0: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80066EC4: bgez        $t8, L_80066EF4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80066EC8: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_80066EF4;
    }
    // 0x80066EC8: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80066ECC: multu       $a1, $t8
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066ED0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80066ED4: mflo        $v0
    ctx->r2 = lo;
    // 0x80066ED8: sra         $t7, $v0, 7
    ctx->r15 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80066EDC: blez        $t7, L_80066EEC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80066EE0: nop
    
            goto L_80066EEC;
    }
    // 0x80066EE0: nop

    // 0x80066EE4: b           L_80066F28
    // 0x80066EE8: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
        goto L_80066F28;
    // 0x80066EE8: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
L_80066EEC:
    // 0x80066EEC: b           L_80066F28
    // 0x80066EF0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
        goto L_80066F28;
    // 0x80066EF0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_80066EF4:
    // 0x80066EF4: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066EF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80066EFC: mflo        $v0
    ctx->r2 = lo;
    // 0x80066F00: sra         $t6, $v0, 7
    ctx->r14 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80066F04: bgez        $t6, L_80066F14
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80066F08: nop
    
            goto L_80066F14;
    }
    // 0x80066F08: nop

    // 0x80066F0C: b           L_80066F14
    // 0x80066F10: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
        goto L_80066F14;
    // 0x80066F10: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_80066F14:
    // 0x80066F14: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80066F18: b           L_80066F28
    // 0x80066F1C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_80066F28;
    // 0x80066F1C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_80066F20:
    // 0x80066F20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80066F24: sll         $t3, $t0, 10
    ctx->r11 = S32(ctx->r8 << 10);
L_80066F28:
    // 0x80066F28: bgez        $t2, L_80066F98
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80066F2C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80066F98;
    }
    // 0x80066F2C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80066F30: sll         $t0, $t4, 10
    ctx->r8 = S32(ctx->r12 << 10);
    // 0x80066F34: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x80066F38: sra         $t9, $v1, 16
    ctx->r25 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80066F3C: bgez        $t9, L_80066F6C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80066F40: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_80066F6C;
    }
    // 0x80066F40: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x80066F44: multu       $t1, $t9
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066F48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80066F4C: mflo        $v0
    ctx->r2 = lo;
    // 0x80066F50: sra         $t8, $v0, 7
    ctx->r24 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80066F54: blez        $t8, L_80066F64
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80066F58: nop
    
            goto L_80066F64;
    }
    // 0x80066F58: nop

    // 0x80066F5C: b           L_80066F9C
    // 0x80066F60: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_80066F9C;
    // 0x80066F60: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_80066F64:
    // 0x80066F64: b           L_80066F9C
    // 0x80066F68: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
        goto L_80066F9C;
    // 0x80066F68: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_80066F6C:
    // 0x80066F6C: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066F70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80066F74: mflo        $v0
    ctx->r2 = lo;
    // 0x80066F78: sra         $t7, $v0, 7
    ctx->r15 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80066F7C: bgez        $t7, L_80066F8C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80066F80: nop
    
            goto L_80066F8C;
    }
    // 0x80066F80: nop

    // 0x80066F84: b           L_80066F8C
    // 0x80066F88: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
        goto L_80066F8C;
    // 0x80066F88: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_80066F8C:
    // 0x80066F8C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80066F90: b           L_80066F9C
    // 0x80066F94: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_80066F9C;
    // 0x80066F94: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80066F98:
    // 0x80066F98: sll         $t0, $t4, 10
    ctx->r8 = S32(ctx->r12 << 10);
L_80066F9C:
    // 0x80066F9C: sll         $t9, $s6, 5
    ctx->r25 = S32(ctx->r22 << 5);
    // 0x80066FA0: subu        $t8, $t9, $v1
    ctx->r24 = SUB32(ctx->r25, ctx->r3);
    // 0x80066FA4: sll         $t9, $s5, 5
    ctx->r25 = S32(ctx->r21 << 5);
    // 0x80066FA8: subu        $t6, $t9, $a3
    ctx->r14 = SUB32(ctx->r25, ctx->r7);
    // 0x80066FAC: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x80066FB0: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x80066FB4: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80066FB8: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80066FBC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80066FC0: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80066FC4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80066FC8: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80066FCC: andi        $t6, $t0, 0xFFFF
    ctx->r14 = ctx->r8 & 0XFFFF;
    // 0x80066FD0: sll         $t8, $t3, 16
    ctx->r24 = S32(ctx->r11 << 16);
    // 0x80066FD4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80066FD8: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80066FDC: b           L_800671A4
    // 0x80066FE0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_800671A4;
    // 0x80066FE0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_80066FE4:
    // 0x80066FE4: lbu         $t9, 0x59E8($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X59E8);
    // 0x80066FE8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80066FEC: beq         $t9, $zero, L_80066FFC
    if (ctx->r25 == 0) {
        // 0x80066FF0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80066FFC;
    }
    // 0x80066FF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80066FF4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80066FF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80066FFC:
    // 0x80066FFC: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80067000: addu        $t6, $s3, $s0
    ctx->r14 = ADD32(ctx->r19, ctx->r16);
    // 0x80067004: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x80067008: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x8006700C: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80067010: sll         $t9, $t7, 18
    ctx->r25 = S32(ctx->r15 << 18);
    // 0x80067014: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80067018: blez        $t8, L_80067028
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8006701C: addu        $t6, $s4, $s1
        ctx->r14 = ADD32(ctx->r20, ctx->r17);
            goto L_80067028;
    }
    // 0x8006701C: addu        $t6, $s4, $s1
    ctx->r14 = ADD32(ctx->r20, ctx->r17);
    // 0x80067020: b           L_8006702C
    // 0x80067024: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
        goto L_8006702C;
    // 0x80067024: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
L_80067028:
    // 0x80067028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8006702C:
    // 0x8006702C: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x80067030: sll         $t9, $t7, 18
    ctx->r25 = S32(ctx->r15 << 18);
    // 0x80067034: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80067038: blez        $t8, L_80067048
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8006703C: andi        $t9, $a0, 0xFFF
        ctx->r25 = ctx->r4 & 0XFFF;
            goto L_80067048;
    }
    // 0x8006703C: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x80067040: b           L_8006704C
    // 0x80067044: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_8006704C;
    // 0x80067044: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_80067048:
    // 0x80067048: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8006704C:
    // 0x8006704C: andi        $t6, $v1, 0xFFF
    ctx->r14 = ctx->r3 & 0XFFF;
    // 0x80067050: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80067054: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80067058: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8006705C: sll         $t9, $a1, 18
    ctx->r25 = S32(ctx->r5 << 18);
    // 0x80067060: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80067064: sra         $t7, $t9, 16
    ctx->r15 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80067068: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8006706C: blez        $t7, L_8006707C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80067070: sw          $t6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r14;
            goto L_8006707C;
    }
    // 0x80067070: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80067074: b           L_80067080
    // 0x80067078: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
        goto L_80067080;
    // 0x80067078: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_8006707C:
    // 0x8006707C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80067080:
    // 0x80067080: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x80067084: sll         $t1, $t2, 16
    ctx->r9 = S32(ctx->r10 << 16);
    // 0x80067088: sra         $t8, $t1, 16
    ctx->r24 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8006708C: blez        $t8, L_8006709C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80067090: or          $t1, $t8, $zero
        ctx->r9 = ctx->r24 | 0;
            goto L_8006709C;
    }
    // 0x80067090: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x80067094: b           L_800670A0
    // 0x80067098: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_800670A0;
    // 0x80067098: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8006709C:
    // 0x8006709C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800670A0:
    // 0x800670A0: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x800670A4: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x800670A8: andi        $t6, $v1, 0xFFF
    ctx->r14 = ctx->r3 & 0XFFF;
    // 0x800670AC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800670B0: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800670B4: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800670B8: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x800670BC: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x800670C0: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800670C4: bgez        $a1, L_80067134
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800670C8: sw          $t6, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r14;
            goto L_80067134;
    }
    // 0x800670C8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800670CC: sll         $t0, $a3, 10
    ctx->r8 = S32(ctx->r7 << 10);
    // 0x800670D0: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x800670D4: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800670D8: bgez        $t7, L_80067108
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800670DC: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_80067108;
    }
    // 0x800670DC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800670E0: multu       $a1, $t7
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800670E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800670E8: mflo        $v0
    ctx->r2 = lo;
    // 0x800670EC: sra         $t8, $v0, 7
    ctx->r24 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800670F0: blez        $t8, L_80067100
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800670F4: nop
    
            goto L_80067100;
    }
    // 0x800670F4: nop

    // 0x800670F8: b           L_8006713C
    // 0x800670FC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
        goto L_8006713C;
    // 0x800670FC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
L_80067100:
    // 0x80067100: b           L_8006713C
    // 0x80067104: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
        goto L_8006713C;
    // 0x80067104: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
L_80067108:
    // 0x80067108: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006710C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80067110: mflo        $v0
    ctx->r2 = lo;
    // 0x80067114: sra         $t9, $v0, 7
    ctx->r25 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80067118: bgez        $t9, L_80067128
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8006711C: nop
    
            goto L_80067128;
    }
    // 0x8006711C: nop

    // 0x80067120: b           L_80067128
    // 0x80067124: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
        goto L_80067128;
    // 0x80067124: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_80067128:
    // 0x80067128: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8006712C: b           L_8006713C
    // 0x80067130: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
        goto L_8006713C;
    // 0x80067130: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_80067134:
    // 0x80067134: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80067138: sll         $t0, $a3, 10
    ctx->r8 = S32(ctx->r7 << 10);
L_8006713C:
    // 0x8006713C: bgez        $t2, L_80067164
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80067140: sll         $t8, $s6, 5
        ctx->r24 = S32(ctx->r22 << 5);
            goto L_80067164;
    }
    // 0x80067140: sll         $t8, $s6, 5
    ctx->r24 = S32(ctx->r22 << 5);
    // 0x80067144: sll         $v0, $t1, 10
    ctx->r2 = S32(ctx->r9 << 10);
    // 0x80067148: sra         $t6, $v0, 7
    ctx->r14 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8006714C: bgez        $t6, L_8006715C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80067150: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8006715C;
    }
    // 0x80067150: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80067154: b           L_80067168
    // 0x80067158: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
        goto L_80067168;
    // 0x80067158: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8006715C:
    // 0x8006715C: b           L_80067168
    // 0x80067160: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_80067168;
    // 0x80067160: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80067164:
    // 0x80067164: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80067168:
    // 0x80067168: subu        $t9, $t8, $v1
    ctx->r25 = SUB32(ctx->r24, ctx->r3);
    // 0x8006716C: sll         $t8, $s5, 5
    ctx->r24 = S32(ctx->r21 << 5);
    // 0x80067170: subu        $t7, $t8, $a2
    ctx->r15 = SUB32(ctx->r24, ctx->r6);
    // 0x80067174: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80067178: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8006717C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80067180: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x80067184: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80067188: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x8006718C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80067190: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80067194: ori         $t7, $t9, 0x400
    ctx->r15 = ctx->r25 | 0X400;
    // 0x80067198: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x8006719C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800671A0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_800671A4:
    // 0x800671A4: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x800671A8: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800671AC: addiu       $ra, $ra, 0x20
    ctx->r31 = ADD32(ctx->r31, 0X20);
    // 0x800671B0: bne         $v1, $t6, L_80066BB0
    if (ctx->r3 != ctx->r14) {
        // 0x800671B4: addiu       $s7, $s7, 0x20
        ctx->r23 = ADD32(ctx->r23, 0X20);
            goto L_80066BB0;
    }
    // 0x800671B4: addiu       $s7, $s7, 0x20
    ctx->r23 = ADD32(ctx->r23, 0X20);
    // 0x800671B8: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x800671BC: nop

L_800671C0:
    // 0x800671C0: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x800671C4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800671C8: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800671CC: bne         $at, $zero, L_80066B84
    if (ctx->r1 != 0) {
        // 0x800671D0: lw          $t7, 0x5C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5C);
            goto L_80066B84;
    }
    // 0x800671D0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800671D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800671D8:
    // 0x800671D8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800671DC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800671E0: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x800671E4: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x800671E8: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x800671EC: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x800671F0: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x800671F4: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x800671F8: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x800671FC: jr          $ra
    // 0x80067200: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80067200: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    // 0x80067204: nop

    // 0x80067208: nop

    // 0x8006720C: nop

;}
RECOMP_FUNC void func_80067210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067214: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80067218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006721C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067220: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80067224: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80067228: jal         0x80061C2C
    // 0x8006722C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80061C2C(rdram, ctx);
        goto after_0;
    // 0x8006722C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80067230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067234: bgtz        $v0, L_80067248
    if (SIGNED(ctx->r2) > 0) {
        // 0x80067238: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80067248;
    }
    // 0x80067238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006723C: b           L_80067248
    // 0x80067240: addiu       $v0, $zero, 0x3EC
    ctx->r2 = ADD32(0, 0X3EC);
        goto L_80067248;
    // 0x80067240: addiu       $v0, $zero, 0x3EC
    ctx->r2 = ADD32(0, 0X3EC);
    // 0x80067244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80067248:
    // 0x80067248: jr          $ra
    // 0x8006724C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006724C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80067250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067254: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80067258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006725C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067260: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80067264: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067268: jal         0x80061C2C
    // 0x8006726C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80061C2C(rdram, ctx);
        goto after_0;
    // 0x8006726C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x80067270: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80067274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067278: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006727C: beq         $at, $zero, L_8006728C
    if (ctx->r1 == 0) {
        // 0x80067280: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006728C;
    }
    // 0x80067280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80067284: b           L_8006728C
    // 0x80067288: addiu       $v0, $zero, 0x3EC
    ctx->r2 = ADD32(0, 0X3EC);
        goto L_8006728C;
    // 0x80067288: addiu       $v0, $zero, 0x3EC
    ctx->r2 = ADD32(0, 0X3EC);
L_8006728C:
    // 0x8006728C: jr          $ra
    // 0x80067290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80067290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80067294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067294: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80067298: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006729C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800672A0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800672A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800672A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800672AC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800672B0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800672B4: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800672B8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800672BC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800672C0: blez        $v0, L_80067328
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800672C4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80067328;
    }
    // 0x800672C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800672C8:
    // 0x800672C8: lw          $t6, 0x24($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X24);
    // 0x800672CC: sll         $t7, $s1, 5
    ctx->r15 = S32(ctx->r17 << 5);
    // 0x800672D0: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800672D4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800672D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800672DC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800672E0: beq         $t9, $zero, L_80067318
    if (ctx->r25 == 0) {
        // 0x800672E4: nop
    
            goto L_80067318;
    }
    // 0x800672E4: nop

    // 0x800672E8: jal         0x80061A44
    // 0x800672EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_80061A44(rdram, ctx);
        goto after_0;
    // 0x800672EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x800672F0: bne         $v0, $zero, L_80067310
    if (ctx->r2 != 0) {
        // 0x800672F4: nop
    
            goto L_80067310;
    }
    // 0x800672F4: nop

    // 0x800672F8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800672FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80067300: sw          $s0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r16;
    // 0x80067304: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80067308: b           L_8006732C
    // 0x8006730C: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
        goto L_8006732C;
    // 0x8006730C: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
L_80067310:
    // 0x80067310: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x80067314: nop

L_80067318:
    // 0x80067318: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006731C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80067320: bne         $at, $zero, L_800672C8
    if (ctx->r1 != 0) {
        // 0x80067324: nop
    
            goto L_800672C8;
    }
    // 0x80067324: nop

L_80067328:
    // 0x80067328: addiu       $v0, $zero, 0x3EF
    ctx->r2 = ADD32(0, 0X3EF);
L_8006732C:
    // 0x8006732C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80067330: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80067334: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80067338: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006733C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80067340: jr          $ra
    // 0x80067344: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80067344: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80067348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067348: jr          $ra
    // 0x8006734C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006734C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80067350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067350: jr          $ra
    // 0x80067354: nop

    return;
    // 0x80067354: nop

;}
RECOMP_FUNC void func_80067358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067358: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006735C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80067360: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80067364: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80067368: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x8006736C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80067370: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80067374: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80067378: jal         0x80061B4C
    // 0x8006737C: addiu       $a1, $a1, -0x24C0
    ctx->r5 = ADD32(ctx->r5, -0X24C0);
    func_80061B4C(rdram, ctx);
        goto after_0;
    // 0x8006737C: addiu       $a1, $a1, -0x24C0
    ctx->r5 = ADD32(ctx->r5, -0X24C0);
    after_0:
    // 0x80067380: bne         $v0, $zero, L_80067390
    if (ctx->r2 != 0) {
        // 0x80067384: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80067390;
    }
    // 0x80067384: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80067388: b           L_800673FC
    // 0x8006738C: addiu       $v0, $zero, 0x3E9
    ctx->r2 = ADD32(0, 0X3E9);
        goto L_800673FC;
    // 0x8006738C: addiu       $v0, $zero, 0x3E9
    ctx->r2 = ADD32(0, 0X3E9);
L_80067390:
    // 0x80067390: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80067394: jal         0x80067210
    // 0x80067398: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_80067210(rdram, ctx);
        goto after_1;
    // 0x80067398: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x8006739C: bne         $v0, $zero, L_800673E8
    if (ctx->r2 != 0) {
        // 0x800673A0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800673E8;
    }
    // 0x800673A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800673A4: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800673A8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x800673AC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800673B0: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800673B4: sll         $t8, $a0, 5
    ctx->r24 = S32(ctx->r4 << 5);
    // 0x800673B8: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x800673BC: jal         0x80065364
    // 0x800673C0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80065364(rdram, ctx);
        goto after_2;
    // 0x800673C0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_2:
    // 0x800673C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800673C8: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x800673CC: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x800673D0: jal         0x80067250
    // 0x800673D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067250(rdram, ctx);
        goto after_3;
    // 0x800673D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x800673D8: bne         $v0, $zero, L_800673E8
    if (ctx->r2 != 0) {
        // 0x800673DC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800673E8;
    }
    // 0x800673DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800673E0: b           L_800673FC
    // 0x800673E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800673FC;
    // 0x800673E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800673E8:
    // 0x800673E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800673EC: jal         0x8006740C
    // 0x800673F0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8006740C(rdram, ctx);
        goto after_4;
    // 0x800673F0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x800673F4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800673F8: nop

L_800673FC:
    // 0x800673FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80067400: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80067404: jr          $ra
    // 0x80067408: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80067408: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006740C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006740C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067414: lw          $a2, 0x24($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X24);
    // 0x80067418: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006741C: beq         $a2, $zero, L_80067438
    if (ctx->r6 == 0) {
        // 0x80067420: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80067438;
    }
    // 0x80067420: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80067424: jal         0x800653C4
    // 0x80067428: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800653C4(rdram, ctx);
        goto after_0;
    // 0x80067428: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006742C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80067430: nop

    // 0x80067434: sw          $zero, 0x24($a1)
    MEM_W(0X24, ctx->r5) = 0;
L_80067438:
    // 0x80067438: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8006743C: jal         0x80061B70
    // 0x80067440: nop

    func_80061B70(rdram, ctx);
        goto after_1;
    // 0x80067440: nop

    after_1:
    // 0x80067444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006744C: jr          $ra
    // 0x80067450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80067450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80067454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067454: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006745C: jal         0x80067294
    // 0x80067460: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    func_80067294(rdram, ctx);
        goto after_0;
    // 0x80067460: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80067464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067468: bne         $v0, $zero, L_8006747C
    if (ctx->r2 != 0) {
        // 0x8006746C: addiu       $v0, $zero, 0x3EF
        ctx->r2 = ADD32(0, 0X3EF);
            goto L_8006747C;
    }
    // 0x8006746C: addiu       $v0, $zero, 0x3EF
    ctx->r2 = ADD32(0, 0X3EF);
    // 0x80067470: b           L_8006747C
    // 0x80067474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006747C;
    // 0x80067474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80067478: addiu       $v0, $zero, 0x3EF
    ctx->r2 = ADD32(0, 0X3EF);
L_8006747C:
    // 0x8006747C: jr          $ra
    // 0x80067480: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80067480: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80067484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006748C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067490: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067494: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067498: lw          $a1, 0x18($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X18);
    // 0x8006749C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800674A0: jal         0x80061BA0
    // 0x800674A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80061BA0(rdram, ctx);
        goto after_0;
    // 0x800674A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800674A8: beq         $v0, $zero, L_800674BC
    if (ctx->r2 == 0) {
        // 0x800674AC: lw          $t8, 0x1C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1C);
            goto L_800674BC;
    }
    // 0x800674AC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800674B0: b           L_800674E8
    // 0x800674B4: addiu       $v0, $zero, 0x3ED
    ctx->r2 = ADD32(0, 0X3ED);
        goto L_800674E8;
    // 0x800674B4: addiu       $v0, $zero, 0x3ED
    ctx->r2 = ADD32(0, 0X3ED);
    // 0x800674B8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
L_800674BC:
    // 0x800674BC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800674C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800674C4: lw          $a1, 0x1C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X1C);
    // 0x800674C8: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x800674CC: jal         0x80061C2C
    // 0x800674D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80061C2C(rdram, ctx);
        goto after_1;
    // 0x800674D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800674D4: bgtz        $v0, L_800674E8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800674D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800674E8;
    }
    // 0x800674D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800674DC: b           L_800674E8
    // 0x800674E0: addiu       $v0, $zero, 0x3EC
    ctx->r2 = ADD32(0, 0X3EC);
        goto L_800674E8;
    // 0x800674E0: addiu       $v0, $zero, 0x3EC
    ctx->r2 = ADD32(0, 0X3EC);
    // 0x800674E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800674E8:
    // 0x800674E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800674EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800674F0: jr          $ra
    // 0x800674F4: nop

    return;
    // 0x800674F4: nop

;}
RECOMP_FUNC void func_800674F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800674F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800674FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067500: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80067504: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80067508: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006750C: jal         0x80067454
    // 0x80067510: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_80067454(rdram, ctx);
        goto after_0;
    // 0x80067510: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80067514: beq         $v0, $zero, L_80067528
    if (ctx->r2 == 0) {
        // 0x80067518: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80067528;
    }
    // 0x80067518: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8006751C: b           L_80067574
    // 0x80067520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80067574;
    // 0x80067520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067524: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_80067528:
    // 0x80067528: nop

    // 0x8006752C: lw          $a0, 0x1C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X1C);
    // 0x80067530: jal         0x80065364
    // 0x80067534: nop

    func_80065364(rdram, ctx);
        goto after_1;
    // 0x80067534: nop

    after_1:
    // 0x80067538: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8006753C: bne         $v0, $zero, L_8006754C
    if (ctx->r2 != 0) {
        // 0x80067540: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8006754C;
    }
    // 0x80067540: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80067544: b           L_80067570
    // 0x80067548: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
        goto L_80067570;
    // 0x80067548: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
L_8006754C:
    // 0x8006754C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80067550: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80067554: lw          $t8, 0x1C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1C);
    // 0x80067558: nop

    // 0x8006755C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80067560: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80067564: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80067568: jal         0x80067484
    // 0x8006756C: nop

    func_80067484(rdram, ctx);
        goto after_2;
    // 0x8006756C: nop

    after_2:
L_80067570:
    // 0x80067570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80067574:
    // 0x80067574: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80067578: jr          $ra
    // 0x8006757C: nop

    return;
    // 0x8006757C: nop

;}
RECOMP_FUNC void func_80067580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067580: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067588: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006758C: jal         0x80067454
    // 0x80067590: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_80067454(rdram, ctx);
        goto after_0;
    // 0x80067590: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80067594: beq         $v0, $zero, L_800675A8
    if (ctx->r2 == 0) {
        // 0x80067598: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_800675A8;
    }
    // 0x80067598: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8006759C: b           L_800675BC
    // 0x800675A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800675BC;
    // 0x800675A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800675A4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_800675A8:
    // 0x800675A8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800675AC: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x800675B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800675B4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800675B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800675BC:
    // 0x800675BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800675C0: jr          $ra
    // 0x800675C4: nop

    return;
    // 0x800675C4: nop

    // 0x800675C8: nop

    // 0x800675CC: nop

;}
RECOMP_FUNC void func_800675D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800675D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800675D4: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x800675D8: lui         $t6, 0x90
    ctx->r14 = S32(0X90 << 16);
    // 0x800675DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800675E0: addiu       $t6, $t6, 0x6290
    ctx->r14 = ADD32(ctx->r14, 0X6290);
    // 0x800675E4: addiu       $a0, $a0, -0x2560
    ctx->r4 = ADD32(ctx->r4, -0X2560);
    // 0x800675E8: jal         0x80061B00
    // 0x800675EC: subu        $a1, $t6, $a0
    ctx->r5 = SUB32(ctx->r14, ctx->r4);
    func_80061B00(rdram, ctx);
        goto after_0;
    // 0x800675EC: subu        $a1, $t6, $a0
    ctx->r5 = SUB32(ctx->r14, ctx->r4);
    after_0:
    // 0x800675F0: jal         0x80067348
    // 0x800675F4: nop

    func_80067348(rdram, ctx);
        goto after_1;
    // 0x800675F4: nop

    after_1:
    // 0x800675F8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800675FC: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80067600: addiu       $v0, $v0, 0x5AD0
    ctx->r2 = ADD32(ctx->r2, 0X5AD0);
    // 0x80067604: addiu       $a0, $t7, -0x570
    ctx->r4 = ADD32(ctx->r15, -0X570);
    // 0x80067608: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8006760C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80067610: jal         0x80067358
    // 0x80067614: addiu       $a1, $a1, -0x24B0
    ctx->r5 = ADD32(ctx->r5, -0X24B0);
    func_80067358(rdram, ctx);
        goto after_2;
    // 0x80067614: addiu       $a1, $a1, -0x24B0
    ctx->r5 = ADD32(ctx->r5, -0X24B0);
    after_2:
    // 0x80067618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006761C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067620: jr          $ra
    // 0x80067624: nop

    return;
    // 0x80067624: nop

;}
RECOMP_FUNC void func_80067628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067628: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006762C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80067630: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80067634: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80067638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006763C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80067640: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80067644: lw          $a0, 0x5AD0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5AD0);
    // 0x80067648: jal         0x800674F8
    // 0x8006764C: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    func_800674F8(rdram, ctx);
        goto after_0;
    // 0x8006764C: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80067650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067654: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80067658: jr          $ra
    // 0x8006765C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006765C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80067660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067660: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80067664: lhu         $v0, -0x4F56($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4F56);
    // 0x80067668: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8006766C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80067670: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80067674: lh          $a2, -0x4F58($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X4F58);
    // 0x80067678: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8006767C: lw          $v1, 0x5A94($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5A94);
    // 0x80067680: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80067684: beq         $v0, $zero, L_800676B8
    if (ctx->r2 == 0) {
        // 0x80067688: andi        $a1, $a2, 0xFFFF
        ctx->r5 = ctx->r6 & 0XFFFF;
            goto L_800676B8;
    }
    // 0x80067688: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
    // 0x8006768C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80067690: lhu         $a1, -0x4F4C($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X4F4C);
    // 0x80067694: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80067698: bne         $v0, $at, L_800676A8
    if (ctx->r2 != ctx->r1) {
        // 0x8006769C: nop
    
            goto L_800676A8;
    }
    // 0x8006769C: nop

    // 0x800676A0: b           L_800676DC
    // 0x800676A4: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
        goto L_800676DC;
    // 0x800676A4: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
L_800676A8:
    // 0x800676A8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800676AC: lhu         $v0, -0x4F5A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4F5A);
    // 0x800676B0: b           L_800676C4
    // 0x800676B4: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
        goto L_800676C4;
    // 0x800676B4: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
L_800676B8:
    // 0x800676B8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800676BC: lhu         $v0, -0x4F60($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4F60);
    // 0x800676C0: nop

L_800676C4:
    // 0x800676C4: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800676C8: bne         $at, $zero, L_800676E0
    if (ctx->r1 != 0) {
        // 0x800676CC: addu        $t8, $v0, $v1
        ctx->r24 = ADD32(ctx->r2, ctx->r3);
            goto L_800676E0;
    }
    // 0x800676CC: addu        $t8, $v0, $v1
    ctx->r24 = ADD32(ctx->r2, ctx->r3);
    // 0x800676D0: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x800676D4: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x800676D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800676DC:
    // 0x800676DC: addu        $t8, $v0, $v1
    ctx->r24 = ADD32(ctx->r2, ctx->r3);
L_800676E0:
    // 0x800676E0: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x800676E4: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800676E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800676EC: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800676F0: beq         $t0, $at, L_800676FC
    if (ctx->r8 == ctx->r1) {
        // 0x800676F4: addiu       $a0, $t9, -0x42
        ctx->r4 = ADD32(ctx->r25, -0X42);
            goto L_800676FC;
    }
    // 0x800676F4: addiu       $a0, $t9, -0x42
    ctx->r4 = ADD32(ctx->r25, -0X42);
    // 0x800676F8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800676FC:
    // 0x800676FC: jr          $ra
    // 0x80067700: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80067700: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_80067704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    fprintf(stderr, "[BOOT] ENTERED func_80067704, rdram=%p ctx=%p\n", (void*)rdram, (void*)ctx); fflush(stderr);
    // 0x80067704: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80067708: lw          $a0, 0x5AD0($a0)
    fprintf(stderr, "[BOOT] func_80067704: about to read MEM_W at N64 addr 0x%08X\n", (uint32_t)(ctx->r4 + 0X5AD0)); fflush(stderr);
    ctx->r4 = MEM_W(ctx->r4, 0X5AD0);
    fprintf(stderr, "[BOOT] func_80067704: a0=0x%08X\n", (uint32_t)ctx->r4); fflush(stderr);
    // FALLTHROUGH FIX: func_80067704 falls through to func_8006770C
    func_8006770C(rdram, ctx);
;}
RECOMP_FUNC void func_8006770C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006770C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80067710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067714: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80067718: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8006771C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80067720: addiu       $a1, $a1, -0x24A4
    ctx->r5 = ADD32(ctx->r5, -0X24A4);
    // 0x80067724: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80067728: jal         0x80067454
    // 0x8006772C: sw          $t6, 0x5AD4($at)
    MEM_W(0X5AD4, ctx->r1) = ctx->r14;
    func_80067454(rdram, ctx);
        goto after_0;
    // 0x8006772C: sw          $t6, 0x5AD4($at)
    MEM_W(0X5AD4, ctx->r1) = ctx->r14;
    after_0:
    // 0x80067730: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80067734: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80067738: lw          $a1, 0x18($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X18);
    // 0x8006773C: addiu       $v0, $v0, 0x5AD8
    ctx->r2 = ADD32(ctx->r2, 0X5AD8);
    // 0x80067740: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80067744: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80067748: lw          $a0, 0x5AD4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5AD4);
    // 0x8006774C: jal         0x80061BA0
    // 0x80067750: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80061BA0(rdram, ctx);
        goto after_1;
    // 0x80067750: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80067754: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80067758: lw          $a3, 0x5AD4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5AD4);
    // 0x8006775C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80067760: addiu       $a0, $a0, -0x14A8
    ctx->r4 = ADD32(ctx->r4, -0X14A8);
    // 0x80067764: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80067768: jal         0x80061C2C
    // 0x8006776C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80061C2C(rdram, ctx);
        goto after_2;
    // 0x8006776C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80067770: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80067774: lw          $a3, 0x5AD4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5AD4);
    // 0x80067778: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8006777C: addiu       $a0, $a0, -0x548
    ctx->r4 = ADD32(ctx->r4, -0X548);
    // 0x80067780: ori         $a1, $zero, 0xF0A0
    ctx->r5 = 0 | 0XF0A0;
    // 0x80067784: jal         0x80061C2C
    // 0x80067788: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80061C2C(rdram, ctx);
        goto after_3;
    // 0x80067788: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8006778C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067790: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80067794: jr          $ra
    // 0x80067798: nop

    return;
    // 0x80067798: nop

;}
RECOMP_FUNC void func_8006779C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006779C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800677A0: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800677A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800677A8: addiu       $t7, $t7, -0x548
    ctx->r15 = ADD32(ctx->r15, -0X548);
    // 0x800677AC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800677B0: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800677B4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800677B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800677BC: bne         $t8, $zero, L_800677CC
    if (ctx->r24 != 0) {
        // 0x800677C0: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_800677CC;
    }
    // 0x800677C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800677C4: b           L_8006788C
    // 0x800677C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006788C;
    // 0x800677C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800677CC:
    // 0x800677CC: lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X4);
    // 0x800677D0: jal         0x80065364
    // 0x800677D4: nop

    func_80065364(rdram, ctx);
        goto after_0;
    // 0x800677D4: nop

    after_0:
    // 0x800677D8: lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6);
    // 0x800677DC: jal         0x80065364
    // 0x800677E0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_80065364(rdram, ctx);
        goto after_1;
    // 0x800677E0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_1:
    // 0x800677E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800677E8: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800677EC: lw          $t0, 0x5AD8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5AD8);
    // 0x800677F0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800677F4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800677F8: lw          $a0, 0x5AD4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5AD4);
    // 0x800677FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80067800: jal         0x80061BA0
    // 0x80067804: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    func_80061BA0(rdram, ctx);
        goto after_2;
    // 0x80067804: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_2:
    // 0x80067808: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8006780C: lw          $a3, 0x5AD4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5AD4);
    // 0x80067810: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80067814: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x80067818: jal         0x80061C2C
    // 0x8006781C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80061C2C(rdram, ctx);
        goto after_3;
    // 0x8006781C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80067820: lhu         $a2, 0x4($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X4);
    // 0x80067824: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80067828: jal         0x80061938
    // 0x8006782C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    func_80061938(rdram, ctx);
        goto after_4;
    // 0x8006782C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_4:
    // 0x80067830: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80067834: lhu         $a2, 0x6($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X6);
    // 0x80067838: jal         0x80065FC4
    // 0x8006783C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80065FC4(rdram, ctx);
        goto after_5;
    // 0x8006783C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x80067840: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x80067844: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x80067848: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
    // 0x8006784C: sra         $t1, $v1, 16
    ctx->r9 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80067850: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x80067854: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80067858: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8006785C: and         $t4, $t3, $a2
    ctx->r12 = ctx->r11 & ctx->r6;
    // 0x80067860: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80067864: and         $t9, $t8, $a2
    ctx->r25 = ctx->r24 & ctx->r6;
    // 0x80067868: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8006786C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80067870: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80067874: sw          $t5, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r13;
    // 0x80067878: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
    // 0x8006787C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80067880: jal         0x800653C4
    // 0x80067884: nop

    func_800653C4(rdram, ctx);
        goto after_6;
    // 0x80067884: nop

    after_6:
    // 0x80067888: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8006788C:
    // 0x8006788C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80067890: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80067894: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80067898: jr          $ra
    // 0x8006789C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006789C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800678A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800678A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800678A4: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800678A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800678AC: addiu       $t8, $t8, -0x548
    ctx->r24 = ADD32(ctx->r24, -0X548);
    // 0x800678B0: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x800678B4: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x800678B8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800678BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800678C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800678C4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800678C8: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800678CC: bne         $t9, $zero, L_800678DC
    if (ctx->r25 != 0) {
        // 0x800678D0: nop
    
            goto L_800678DC;
    }
    // 0x800678D0: nop

    // 0x800678D4: b           L_800679BC
    // 0x800678D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800679BC;
    // 0x800678D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800678DC:
    // 0x800678DC: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x800678E0: nop

    // 0x800678E4: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800678E8: jal         0x80065364
    // 0x800678EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80065364(rdram, ctx);
        goto after_0;
    // 0x800678EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800678F0: bne         $v0, $zero, L_80067900
    if (ctx->r2 != 0) {
        // 0x800678F4: sw          $v0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r2;
            goto L_80067900;
    }
    // 0x800678F4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800678F8: b           L_800679BC
    // 0x800678FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800679BC;
    // 0x800678FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80067900:
    // 0x80067900: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80067904: lw          $t2, 0x5AD8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5AD8);
    // 0x80067908: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8006790C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80067910: lw          $a0, 0x5AD4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5AD4);
    // 0x80067914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80067918: jal         0x80061BA0
    // 0x8006791C: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    func_80061BA0(rdram, ctx);
        goto after_1;
    // 0x8006791C: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x80067920: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80067924: lw          $a3, 0x5AD4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5AD4);
    // 0x80067928: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006792C: lhu         $a1, 0x6($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X6);
    // 0x80067930: addiu       $a0, $a0, -0x1488
    ctx->r4 = ADD32(ctx->r4, -0X1488);
    // 0x80067934: jal         0x80061C2C
    // 0x80067938: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80061C2C(rdram, ctx);
        goto after_2;
    // 0x80067938: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8006793C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80067940: lhu         $a2, 0x6($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X6);
    // 0x80067944: addiu       $a0, $a0, -0x1488
    ctx->r4 = ADD32(ctx->r4, -0X1488);
    // 0x80067948: jal         0x80065FC4
    // 0x8006794C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80065FC4(rdram, ctx);
        goto after_3;
    // 0x8006794C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80067950: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80067954: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80067958: lui         $t0, 0xFFFF
    ctx->r8 = S32(0XFFFF << 16);
    // 0x8006795C: sra         $t3, $v1, 16
    ctx->r11 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80067960: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x80067964: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x80067968: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006796C: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x80067970: and         $t6, $t5, $t0
    ctx->r14 = ctx->r13 & ctx->r8;
    // 0x80067974: and         $t2, $t1, $t0
    ctx->r10 = ctx->r9 & ctx->r8;
    // 0x80067978: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8006797C: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80067980: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x80067984: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80067988: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x8006798C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80067990: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80067994: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80067998: jal         0x8006B450
    // 0x8006799C: addu        $a1, $t5, $s0
    ctx->r5 = ADD32(ctx->r13, ctx->r16);
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x8006799C: addu        $a1, $t5, $s0
    ctx->r5 = ADD32(ctx->r13, ctx->r16);
    after_4:
    // 0x800679A0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800679A4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800679A8: addu        $t6, $t4, $s0
    ctx->r14 = ADD32(ctx->r12, ctx->r16);
    // 0x800679AC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800679B0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800679B4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800679B8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_800679BC:
    // 0x800679BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800679C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800679C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800679C8: jr          $ra
    // 0x800679CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800679CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800679D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800679D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800679D4: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800679D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800679DC: addiu       $t7, $t7, -0x548
    ctx->r15 = ADD32(ctx->r15, -0X548);
    // 0x800679E0: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800679E4: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800679E8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800679EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800679F0: bne         $t8, $zero, L_80067A00
    if (ctx->r24 != 0) {
        // 0x800679F4: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_80067A00;
    }
    // 0x800679F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800679F8: b           L_80067A88
    // 0x800679FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80067A88;
    // 0x800679FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80067A00:
    // 0x80067A00: lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X4);
    // 0x80067A04: jal         0x80065364
    // 0x80067A08: nop

    func_80065364(rdram, ctx);
        goto after_0;
    // 0x80067A08: nop

    after_0:
    // 0x80067A0C: bne         $v0, $zero, L_80067A1C
    if (ctx->r2 != 0) {
        // 0x80067A10: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80067A1C;
    }
    // 0x80067A10: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80067A14: b           L_80067A88
    // 0x80067A18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80067A88;
    // 0x80067A18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80067A1C:
    // 0x80067A1C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80067A20: lw          $t0, 0x5AD8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5AD8);
    // 0x80067A24: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80067A28: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80067A2C: lw          $a0, 0x5AD4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5AD4);
    // 0x80067A30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80067A34: jal         0x80061BA0
    // 0x80067A38: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    func_80061BA0(rdram, ctx);
        goto after_1;
    // 0x80067A38: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_1:
    // 0x80067A3C: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80067A40: lw          $a3, 0x5AD4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5AD4);
    // 0x80067A44: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80067A48: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x80067A4C: addiu       $a0, $a0, -0x1488
    ctx->r4 = ADD32(ctx->r4, -0X1488);
    // 0x80067A50: jal         0x80061C2C
    // 0x80067A54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80061C2C(rdram, ctx);
        goto after_2;
    // 0x80067A54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80067A58: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80067A5C: lhu         $a2, 0x6($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X6);
    // 0x80067A60: addiu       $a0, $a0, -0x1488
    ctx->r4 = ADD32(ctx->r4, -0X1488);
    // 0x80067A64: jal         0x80065FC4
    // 0x80067A68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80065FC4(rdram, ctx);
        goto after_3;
    // 0x80067A68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80067A6C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80067A70: lhu         $t1, 0x4($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X4);
    // 0x80067A74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80067A78: addu        $a1, $v1, $s1
    ctx->r5 = ADD32(ctx->r3, ctx->r17);
    // 0x80067A7C: jal         0x800619B8
    // 0x80067A80: subu        $a2, $t1, $v1
    ctx->r6 = SUB32(ctx->r9, ctx->r3);
    func_800619B8(rdram, ctx);
        goto after_4;
    // 0x80067A80: subu        $a2, $t1, $v1
    ctx->r6 = SUB32(ctx->r9, ctx->r3);
    after_4:
    // 0x80067A84: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80067A88:
    // 0x80067A88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80067A8C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80067A90: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80067A94: jr          $ra
    // 0x80067A98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80067A98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80067A9C: nop

;}
RECOMP_FUNC void func_80067AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067AA0: jr          $ra
    // 0x80067AA4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80067AA4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80067AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067AA8: lh          $v0, 0x38($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X38);
    // 0x80067AAC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80067AB0: blez        $v0, L_80067ADC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80067AB4: andi        $a1, $v0, 0x3
        ctx->r5 = ctx->r2 & 0X3;
            goto L_80067ADC;
    }
    // 0x80067AB4: andi        $a1, $v0, 0x3
    ctx->r5 = ctx->r2 & 0X3;
    // 0x80067AB8: beq         $a1, $zero, L_80067AD0
    if (ctx->r5 == 0) {
        // 0x80067ABC: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80067AD0;
    }
    // 0x80067ABC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80067AC0:
    // 0x80067AC0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80067AC4: bne         $a0, $v1, L_80067AC0
    if (ctx->r4 != ctx->r3) {
        // 0x80067AC8: nop
    
            goto L_80067AC0;
    }
    // 0x80067AC8: nop

    // 0x80067ACC: beq         $v1, $v0, L_80067ADC
    if (ctx->r3 == ctx->r2) {
        // 0x80067AD0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80067ADC;
    }
L_80067AD0:
    // 0x80067AD0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80067AD4:
    // 0x80067AD4: bne         $v1, $v0, L_80067AD4
    if (ctx->r3 != ctx->r2) {
        // 0x80067AD8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80067AD4;
    }
    // 0x80067AD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80067ADC:
    // 0x80067ADC: jr          $ra
    // 0x80067AE0: nop

    return;
    // 0x80067AE0: nop

;}
RECOMP_FUNC void func_80067AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067AE4: jr          $ra
    // 0x80067AE8: nop

    return;
    // 0x80067AE8: nop

;}
RECOMP_FUNC void func_80067AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067AEC: jr          $ra
    // 0x80067AF0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80067AF0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void alHeapCheck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067AF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80067AF8: jr          $ra
    // 0x80067AFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80067AFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80067B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80067B04: jr          $ra
    // 0x80067B08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80067B08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80067B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B0C: jr          $ra
    // 0x80067B10: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80067B10: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80067B14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B14: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
L_80067B18:
    // 0x80067B18: b           L_80067B18
    pause_self(rdram);
    // 0x80067B1C: nop

    // 0x80067B20: jr          $ra
    // 0x80067B24: nop

    return;
    // 0x80067B24: nop

;}
RECOMP_FUNC void func_80067B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B28: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80067B2C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80067B30: jr          $ra
    // 0x80067B34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80067B34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80067B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067B3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067B40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067B44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067B48: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80067B4C: andi        $t7, $a1, 0xFFFF
    ctx->r15 = ctx->r5 & 0XFFFF;
    // 0x80067B50: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80067B54: jal         0x80067B28
    // 0x80067B58: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_80067B28(rdram, ctx);
        goto after_0;
    // 0x80067B58: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80067B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067B60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067B64: jr          $ra
    // 0x80067B68: nop

    return;
    // 0x80067B68: nop

;}
RECOMP_FUNC void func_80067B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    fprintf(stderr, "[BOOT] 67B6C entered\n"); fflush(stderr);
    // 0x80067B6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067B70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067B74: jal         0x80065628
    // 0x80067B78: nop

    fprintf(stderr, "[BOOT] 67B6C: ->65628\n"); fflush(stderr);
    func_80065628(rdram, ctx);
        goto after_0;
    // 0x80067B78: nop

    after_0:
    // 0x80067B7C: jal         0x800675D0
    // 0x80067B80: nop

    fprintf(stderr, "[BOOT] 67B6C: ->675D0\n"); fflush(stderr);
    func_800675D0(rdram, ctx);
        goto after_1;
    // 0x80067B80: nop

    after_1:
    // 0x80067B84: jal         0x80067704
    // 0x80067B88: nop

    fprintf(stderr, "[BOOT] 67B6C: ->67704\n"); fflush(stderr);
    func_80067704(rdram, ctx);
        goto after_2;
    // 0x80067B88: nop

    after_2:
    // 0x80067B8C: jal         0x80067D00
    // 0x80067B90: nop

    fprintf(stderr, "[BOOT] 67B6C: ->67D00\n"); fflush(stderr);
    func_80067D00(rdram, ctx);
        goto after_3;
    // 0x80067B90: nop

    after_3:
    // 0x80067B94: jal         0x80068648
    // 0x80067B98: nop

    fprintf(stderr, "[BOOT] 67B6C: ->68648\n"); fflush(stderr);
    func_80068648(rdram, ctx);
        goto after_4;
    // 0x80067B98: nop

    after_4:
    // 0x80067B9C: jal         0x8006284C
    // 0x80067BA0: nop

    fprintf(stderr, "[BOOT] 67B6C: ->6284C\n"); fflush(stderr);
    func_8006284C(rdram, ctx);
        goto after_5;
    // 0x80067BA0: nop

    after_5:
    // 0x80067BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067BA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067BAC: jr          $ra
    // 0x80067BB0: nop

    return;
    // 0x80067BB0: nop

;}
RECOMP_FUNC void func_80067BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067BB4: jr          $ra
    // 0x80067BB8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80067BB8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80067BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067BBC: jr          $ra
    // 0x80067BC0: nop

    return;
    // 0x80067BC0: nop

;}
RECOMP_FUNC void func_80067BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067BC8: slti        $at, $a0, 0x2EE0
    ctx->r1 = SIGNED(ctx->r4) < 0X2EE0 ? 1 : 0;
    // 0x80067BCC: beq         $at, $zero, L_80067BDC
    if (ctx->r1 == 0) {
        // 0x80067BD0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80067BDC;
    }
    // 0x80067BD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067BD4: jal         0x80068394
    // 0x80067BD8: nop

    func_80068394(rdram, ctx);
        goto after_0;
    // 0x80067BD8: nop

    after_0:
L_80067BDC:
    // 0x80067BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067BE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067BE4: jr          $ra
    // 0x80067BE8: nop

    return;
    // 0x80067BE8: nop

;}
RECOMP_FUNC void func_80067BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067BEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067BF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067BF4: jal         0x8006A690
    // 0x80067BF8: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x80067BF8: nop

    after_0:
    // 0x80067BFC: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80067C00: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80067C04: lw          $t7, 0x5AE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5AE4);
    // 0x80067C08: lw          $t6, 0x5AE0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5AE0);
    // 0x80067C0C: lui         $a3, 0xF
    ctx->r7 = S32(0XF << 16);
    // 0x80067C10: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x80067C14: subu        $a0, $v0, $t6
    ctx->r4 = SUB32(ctx->r2, ctx->r14);
    // 0x80067C18: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x80067C1C: ori         $a3, $a3, 0x4240
    ctx->r7 = ctx->r7 | 0X4240;
    // 0x80067C20: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80067C24: jal         0x8006A888
    // 0x80067C28: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80067C28: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    after_1:
    // 0x80067C2C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80067C30: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80067C34: lw          $a3, 0x5D34($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5D34);
    // 0x80067C38: lw          $a2, 0x5D30($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5D30);
    // 0x80067C3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80067C40: jal         0x8006A788
    // 0x80067C44: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_2;
    // 0x80067C44: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x80067C48: jal         0x80067BC4
    // 0x80067C4C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    func_80067BC4(rdram, ctx);
        goto after_3;
    // 0x80067C4C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    after_3:
    // 0x80067C50: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80067C54: addiu       $v1, $v1, -0x7840
    ctx->r3 = ADD32(ctx->r3, -0X7840);
    // 0x80067C58: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80067C5C: nop

    // 0x80067C60: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80067C64: jal         0x800629A4
    // 0x80067C68: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    func_800629A4(rdram, ctx);
        goto after_4;
    // 0x80067C68: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    after_4:
    // 0x80067C6C: jal         0x8006A690
    // 0x80067C70: nop

    osGetTime_recomp(rdram, ctx);
        goto after_5;
    // 0x80067C70: nop

    after_5:
    // 0x80067C74: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80067C78: lw          $t9, 0x58B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X58B0);
    // 0x80067C7C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80067C80: sw          $v0, 0x5AE0($at)
    MEM_W(0X5AE0, ctx->r1) = ctx->r2;
    // 0x80067C84: beq         $t9, $zero, L_80067C94
    if (ctx->r25 == 0) {
        // 0x80067C88: sw          $v1, 0x5AE4($at)
        MEM_W(0X5AE4, ctx->r1) = ctx->r3;
            goto L_80067C94;
    }
    // 0x80067C88: sw          $v1, 0x5AE4($at)
    MEM_W(0X5AE4, ctx->r1) = ctx->r3;
    // 0x80067C8C: jal         0x80063BD8
    // 0x80067C90: nop

    func_80063BD8(rdram, ctx);
        goto after_6;
    // 0x80067C90: nop

    after_6:
L_80067C94:
    // 0x80067C94: jal         0x800025E0
    // 0x80067C98: nop

    func_800025E0(rdram, ctx);
        goto after_7;
    // 0x80067C98: nop

    after_7:
    // 0x80067C9C: jal         0x80003054
    // 0x80067CA0: nop

    func_80003054(rdram, ctx);
        goto after_8;
    // 0x80067CA0: nop

    after_8:
    // 0x80067CA4: jal         0x80061E20
    // 0x80067CA8: nop

    func_80061E20(rdram, ctx);
        goto after_9;
    // 0x80067CA8: nop

    after_9:
    // 0x80067CAC: jal         0x8006284C
    // 0x80067CB0: nop

    func_8006284C(rdram, ctx);
        goto after_10;
    // 0x80067CB0: nop

    after_10:
    // 0x80067CB4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80067CB8: lhu         $v0, -0x9D6($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X9D6);
    // 0x80067CBC: nop

    // 0x80067CC0: andi        $v1, $v0, 0x7C00
    ctx->r3 = ctx->r2 & 0X7C00;
    // 0x80067CC4: andi        $a3, $v0, 0x3E0
    ctx->r7 = ctx->r2 & 0X3E0;
    // 0x80067CC8: sra         $t1, $v1, 10
    ctx->r9 = S32(SIGNED(ctx->r3) >> 10);
    // 0x80067CCC: sra         $t2, $a3, 5
    ctx->r10 = S32(SIGNED(ctx->r7) >> 5);
    // 0x80067CD0: andi        $t0, $v0, 0x1F
    ctx->r8 = ctx->r2 & 0X1F;
    // 0x80067CD4: sll         $a2, $t0, 3
    ctx->r6 = S32(ctx->r8 << 3);
    // 0x80067CD8: sll         $a1, $t2, 3
    ctx->r5 = S32(ctx->r10 << 3);
    // 0x80067CDC: jal         0x80061E34
    // 0x80067CE0: sll         $a0, $t1, 3
    ctx->r4 = S32(ctx->r9 << 3);
    func_80061E34(rdram, ctx);
        goto after_11;
    // 0x80067CE0: sll         $a0, $t1, 3
    ctx->r4 = S32(ctx->r9 << 3);
    after_11:
    // 0x80067CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067CEC: jr          $ra
    // 0x80067CF0: nop

    return;
    // 0x80067CF0: nop

    // 0x80067CF4: nop

    // 0x80067CF8: nop

    // 0x80067CFC: nop

;}
RECOMP_FUNC void func_80067D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067D08: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x80067D0C: jal         0x80065364
    // 0x80067D10: ori         $a0, $a0, 0xEE00
    ctx->r4 = ctx->r4 | 0XEE00;
    func_80065364(rdram, ctx);
        goto after_0;
    // 0x80067D10: ori         $a0, $a0, 0xEE00
    ctx->r4 = ctx->r4 | 0XEE00;
    after_0:
    // 0x80067D14: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80067D18: addiu       $v1, $v1, 0x3C4C
    ctx->r3 = ADD32(ctx->r3, 0X3C4C);
    // 0x80067D1C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80067D20: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80067D24: sw          $v0, 0x3C54($at)
    MEM_W(0X3C54, ctx->r1) = ctx->r2;
    // 0x80067D28: jal         0x8006779C
    // 0x80067D2C: addiu       $a0, $zero, 0x137
    ctx->r4 = ADD32(0, 0X137);
    func_8006779C(rdram, ctx);
        goto after_1;
    // 0x80067D2C: addiu       $a0, $zero, 0x137
    ctx->r4 = ADD32(0, 0X137);
    after_1:
    // 0x80067D30: addiu       $t7, $v0, 0x10
    ctx->r15 = ADD32(ctx->r2, 0X10);
    // 0x80067D34: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80067D38: jal         0x8006848C
    // 0x80067D3C: sw          $t7, 0x5AF0($at)
    MEM_W(0X5AF0, ctx->r1) = ctx->r15;
    func_8006848C(rdram, ctx);
        goto after_2;
    // 0x80067D3C: sw          $t7, 0x5AF0($at)
    MEM_W(0X5AF0, ctx->r1) = ctx->r15;
    after_2:
    // 0x80067D40: jal         0x8006813C
    // 0x80067D44: nop

    func_8006813C(rdram, ctx);
        goto after_3;
    // 0x80067D44: nop

    after_3:
    // 0x80067D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067D4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067D50: jr          $ra
    // 0x80067D54: nop

    return;
    // 0x80067D54: nop

;}
RECOMP_FUNC void func_80067D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D58: jr          $ra
    // 0x80067D5C: nop

    return;
    // 0x80067D5C: nop

;}
RECOMP_FUNC void func_80067D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D60: jr          $ra
    // 0x80067D64: nop

    return;
    // 0x80067D64: nop

;}
RECOMP_FUNC void func_80067D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D68: jr          $ra
    // 0x80067D6C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80067D6C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80067D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D70: lhu         $v0, 0x7C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X7C);
    // 0x80067D74: nop

    // 0x80067D78: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x80067D7C: bne         $t6, $zero, L_80067DA8
    if (ctx->r14 != 0) {
        // 0x80067D80: nop
    
            goto L_80067DA8;
    }
    // 0x80067D80: nop

    // 0x80067D84: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80067D88: ori         $t7, $v0, 0x80
    ctx->r15 = ctx->r2 | 0X80;
    // 0x80067D8C: beq         $t8, $zero, L_80067DA8
    if (ctx->r24 == 0) {
        // 0x80067D90: sh          $t7, 0x7C($a0)
        MEM_H(0X7C, ctx->r4) = ctx->r15;
            goto L_80067DA8;
    }
    // 0x80067D90: sh          $t7, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r15;
    // 0x80067D94: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    // 0x80067D98: andi        $t9, $v0, 0x400
    ctx->r25 = ctx->r2 & 0X400;
    // 0x80067D9C: beq         $t9, $zero, L_80067DA8
    if (ctx->r25 == 0) {
        // 0x80067DA0: andi        $t0, $v0, 0xFBFF
        ctx->r8 = ctx->r2 & 0XFBFF;
            goto L_80067DA8;
    }
    // 0x80067DA0: andi        $t0, $v0, 0xFBFF
    ctx->r8 = ctx->r2 & 0XFBFF;
    // 0x80067DA4: sh          $t0, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r8;
L_80067DA8:
    // 0x80067DA8: jr          $ra
    // 0x80067DAC: nop

    return;
    // 0x80067DAC: nop

;}
RECOMP_FUNC void func_80067DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067DB0: lhu         $t6, 0x7C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X7C);
    // 0x80067DB4: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80067DB8: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80067DBC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80067DC0: beq         $t8, $zero, L_80067DDC
    if (ctx->r24 == 0) {
        // 0x80067DC4: sh          $t7, 0x7C($a0)
        MEM_H(0X7C, ctx->r4) = ctx->r15;
            goto L_80067DDC;
    }
    // 0x80067DC4: sh          $t7, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r15;
    // 0x80067DC8: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    // 0x80067DCC: andi        $t9, $v0, 0x400
    ctx->r25 = ctx->r2 & 0X400;
    // 0x80067DD0: bne         $t9, $zero, L_80067DDC
    if (ctx->r25 != 0) {
        // 0x80067DD4: ori         $t0, $v0, 0x400
        ctx->r8 = ctx->r2 | 0X400;
            goto L_80067DDC;
    }
    // 0x80067DD4: ori         $t0, $v0, 0x400
    ctx->r8 = ctx->r2 | 0X400;
    // 0x80067DD8: sh          $t0, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r8;
L_80067DDC:
    // 0x80067DDC: jr          $ra
    // 0x80067DE0: nop

    return;
    // 0x80067DE0: nop

;}
RECOMP_FUNC void func_80067DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067DE4: jr          $ra
    // 0x80067DE8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80067DE8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80067DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067DEC: jr          $ra
    // 0x80067DF0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80067DF0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80067DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067DF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80067DF8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80067DFC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80067E00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80067E04: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80067E08: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80067E0C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80067E10: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80067E14: lui         $s3, 0xF7FF
    ctx->r19 = S32(0XF7FF << 16);
    // 0x80067E18: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80067E1C: ori         $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 | 0XFFFF;
    // 0x80067E20: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x80067E24: addiu       $s0, $s0, -0x7830
    ctx->r16 = ADD32(ctx->r16, -0X7830);
    // 0x80067E28: lui         $s1, 0x800
    ctx->r17 = S32(0X800 << 16);
    // 0x80067E2C: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
L_80067E30:
    // 0x80067E30: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80067E34: nop

    // 0x80067E38: and         $t6, $v0, $s1
    ctx->r14 = ctx->r2 & ctx->r17;
    // 0x80067E3C: bne         $t6, $zero, L_80067E6C
    if (ctx->r14 != 0) {
        // 0x80067E40: nop
    
            goto L_80067E6C;
    }
    // 0x80067E40: nop

    // 0x80067E44: beq         $v0, $zero, L_80067E6C
    if (ctx->r2 == 0) {
        // 0x80067E48: and         $v1, $v0, $s3
        ctx->r3 = ctx->r2 & ctx->r19;
            goto L_80067E6C;
    }
    // 0x80067E48: and         $v1, $v0, $s3
    ctx->r3 = ctx->r2 & ctx->r19;
    // 0x80067E4C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80067E50: nop

    // 0x80067E54: and         $t7, $a0, $s4
    ctx->r15 = ctx->r4 & ctx->r20;
    // 0x80067E58: beq         $t7, $zero, L_80067E68
    if (ctx->r15 == 0) {
        // 0x80067E5C: nop
    
            goto L_80067E68;
    }
    // 0x80067E5C: nop

    // 0x80067E60: jal         0x800653C4
    // 0x80067E64: nop

    func_800653C4(rdram, ctx);
        goto after_0;
    // 0x80067E64: nop

    after_0:
L_80067E68:
    // 0x80067E68: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80067E6C:
    // 0x80067E6C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80067E70: bne         $s0, $s2, L_80067E30
    if (ctx->r16 != ctx->r18) {
        // 0x80067E74: nop
    
            goto L_80067E30;
    }
    // 0x80067E74: nop

    // 0x80067E78: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80067E7C: lw          $t8, 0x3C50($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3C50);
    // 0x80067E80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80067E84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80067E88: sw          $t8, 0x3C54($at)
    MEM_W(0X3C54, ctx->r1) = ctx->r24;
    // 0x80067E8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80067E90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80067E94: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80067E98: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80067E9C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80067EA0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80067EA4: sh          $zero, -0x7840($at)
    MEM_H(-0X7840, ctx->r1) = 0;
    // 0x80067EA8: jr          $ra
    // 0x80067EAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80067EAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80067EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067EB0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80067EB4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80067EB8: lui         $t0, 0xF7FF
    ctx->r8 = S32(0XF7FF << 16);
    // 0x80067EBC: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80067EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80067EC4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80067EC8: addiu       $a3, $a3, -0x7830
    ctx->r7 = ADD32(ctx->r7, -0X7830);
    // 0x80067ECC: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x80067ED0: addiu       $t2, $t2, -0x7840
    ctx->r10 = ADD32(ctx->r10, -0X7840);
    // 0x80067ED4: addiu       $t3, $t3, 0x20
    ctx->r11 = ADD32(ctx->r11, 0X20);
    // 0x80067ED8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80067EDC: addiu       $t4, $zero, 0x1E14
    ctx->r12 = ADD32(0, 0X1E14);
    // 0x80067EE0: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80067EE4: slti        $at, $a0, 0xA8
    ctx->r1 = SIGNED(ctx->r4) < 0XA8 ? 1 : 0;
L_80067EE8:
    // 0x80067EE8: bne         $at, $zero, L_80067EF8
    if (ctx->r1 != 0) {
        // 0x80067EEC: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80067EF8;
    }
    // 0x80067EEC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80067EF0: slti        $at, $a0, 0x1EB
    ctx->r1 = SIGNED(ctx->r4) < 0X1EB ? 1 : 0;
    // 0x80067EF4: bne         $at, $zero, L_80067F44
    if (ctx->r1 != 0) {
        // 0x80067EF8: addu        $t7, $a3, $t6
        ctx->r15 = ADD32(ctx->r7, ctx->r14);
            goto L_80067F44;
    }
L_80067EF8:
    // 0x80067EF8: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80067EFC: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80067F00: nop

    // 0x80067F04: beq         $a1, $zero, L_80067F44
    if (ctx->r5 == 0) {
        // 0x80067F08: and         $a2, $a1, $t0
        ctx->r6 = ctx->r5 & ctx->r8;
            goto L_80067F44;
    }
    // 0x80067F08: and         $a2, $a1, $t0
    ctx->r6 = ctx->r5 & ctx->r8;
    // 0x80067F0C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80067F10: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80067F14: and         $t9, $t8, $t1
    ctx->r25 = ctx->r24 & ctx->r9;
    // 0x80067F18: beq         $t9, $zero, L_80067F44
    if (ctx->r25 == 0) {
        // 0x80067F1C: addu        $t7, $t3, $t6
        ctx->r15 = ADD32(ctx->r11, ctx->r14);
            goto L_80067F44;
    }
    // 0x80067F1C: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x80067F20: lhu         $t5, 0x0($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X0);
    // 0x80067F24: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80067F28: nop

    // 0x80067F2C: subu        $a1, $t5, $t8
    ctx->r5 = SUB32(ctx->r13, ctx->r24);
    // 0x80067F30: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80067F34: beq         $at, $zero, L_80067F48
    if (ctx->r1 == 0) {
        // 0x80067F38: slti        $at, $a0, 0xA7
        ctx->r1 = SIGNED(ctx->r4) < 0XA7 ? 1 : 0;
            goto L_80067F48;
    }
    // 0x80067F38: slti        $at, $a0, 0xA7
    ctx->r1 = SIGNED(ctx->r4) < 0XA7 ? 1 : 0;
    // 0x80067F3C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80067F40: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80067F44:
    // 0x80067F44: slti        $at, $a0, 0xA7
    ctx->r1 = SIGNED(ctx->r4) < 0XA7 ? 1 : 0;
L_80067F48:
    // 0x80067F48: bne         $at, $zero, L_80067F58
    if (ctx->r1 != 0) {
        // 0x80067F4C: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_80067F58;
    }
    // 0x80067F4C: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80067F50: slti        $at, $a0, 0x1EA
    ctx->r1 = SIGNED(ctx->r4) < 0X1EA ? 1 : 0;
    // 0x80067F54: bne         $at, $zero, L_80067FA4
    if (ctx->r1 != 0) {
        // 0x80067F58: addu        $t6, $a3, $t9
        ctx->r14 = ADD32(ctx->r7, ctx->r25);
            goto L_80067FA4;
    }
L_80067F58:
    // 0x80067F58: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x80067F5C: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x80067F60: nop

    // 0x80067F64: beq         $a1, $zero, L_80067FA4
    if (ctx->r5 == 0) {
        // 0x80067F68: and         $a2, $a1, $t0
        ctx->r6 = ctx->r5 & ctx->r8;
            goto L_80067FA4;
    }
    // 0x80067F68: and         $a2, $a1, $t0
    ctx->r6 = ctx->r5 & ctx->r8;
    // 0x80067F6C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80067F70: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80067F74: and         $t5, $t7, $t1
    ctx->r13 = ctx->r15 & ctx->r9;
    // 0x80067F78: beq         $t5, $zero, L_80067FA4
    if (ctx->r13 == 0) {
        // 0x80067F7C: addu        $t6, $t3, $t9
        ctx->r14 = ADD32(ctx->r11, ctx->r25);
            goto L_80067FA4;
    }
    // 0x80067F7C: addu        $t6, $t3, $t9
    ctx->r14 = ADD32(ctx->r11, ctx->r25);
    // 0x80067F80: lhu         $t8, 0x0($t2)
    ctx->r24 = MEM_HU(ctx->r10, 0X0);
    // 0x80067F84: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x80067F88: nop

    // 0x80067F8C: subu        $a1, $t8, $t7
    ctx->r5 = SUB32(ctx->r24, ctx->r15);
    // 0x80067F90: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80067F94: beq         $at, $zero, L_80067FA4
    if (ctx->r1 == 0) {
        // 0x80067F98: nop
    
            goto L_80067FA4;
    }
    // 0x80067F98: nop

    // 0x80067F9C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80067FA0: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
L_80067FA4:
    // 0x80067FA4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80067FA8: bne         $a0, $t4, L_80067EE8
    if (ctx->r4 != ctx->r12) {
        // 0x80067FAC: slti        $at, $a0, 0xA8
        ctx->r1 = SIGNED(ctx->r4) < 0XA8 ? 1 : 0;
            goto L_80067EE8;
    }
    // 0x80067FAC: slti        $at, $a0, 0xA8
    ctx->r1 = SIGNED(ctx->r4) < 0XA8 ? 1 : 0;
    // 0x80067FB0: jr          $ra
    // 0x80067FB4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80067FB4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80067FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067FB8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80067FBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80067FC0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80067FC4: lw          $v0, -0x7830($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7830);
    // 0x80067FC8: lui         $at, 0xF7FF
    ctx->r1 = S32(0XF7FF << 16);
    // FALLTHROUGH FIX: func_80067FB8 falls through to func_80067FCC
    func_80067FCC(rdram, ctx);
;}
RECOMP_FUNC void func_80067FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067FCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067FD0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80067FD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067FD8: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x80067FDC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80067FE0: jal         0x800653C4
    // 0x80067FE4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_800653C4(rdram, ctx);
        goto after_0;
    // 0x80067FE4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80067FE8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80067FEC: nop

    // 0x80067FF0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80067FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067FF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80067FFC: jr          $ra
    // 0x80068000: nop

    return;
    // 0x80068000: nop

;}
RECOMP_FUNC void func_80068004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068004: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80068008: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8006800C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80068010: lw          $t7, -0x7830($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7830);
    // 0x80068014: lui         $at, 0xF7FF
    ctx->r1 = S32(0XF7FF << 16);
    // FALLTHROUGH FIX: func_80068004 falls through to func_80068018
    func_80068018(rdram, ctx);
;}
