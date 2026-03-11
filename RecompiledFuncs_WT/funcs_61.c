#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

RECOMP_FUNC void func_800611A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800611A0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800611A4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800611A8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800611AC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800611B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800611B4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800611B8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800611BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800611C0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800611C4: lui         $s2, 0x800F
    ctx->r18 = S32(0X800F << 16);
    // 0x800611C8: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x800611CC: lui         $fp, 0x8008
    ctx->r30 = S32(0X8008 << 16);
    // 0x800611D0: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800611D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800611D8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800611DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800611E0: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x800611E4: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800611E8: addiu       $fp, $fp, 0x58DC
    ctx->r30 = ADD32(ctx->r30, 0X58DC);
    // 0x800611EC: addiu       $s5, $s5, 0x5D30
    ctx->r21 = ADD32(ctx->r21, 0X5D30);
    // 0x800611F0: addiu       $s2, $s2, -0x6300
    ctx->r18 = ADD32(ctx->r18, -0X6300);
    // 0x800611F4: addiu       $s4, $sp, 0x64
    ctx->r20 = ADD32(ctx->r29, 0X64);
    // 0x800611F8: addiu       $s6, $a0, 0x3C
    ctx->r22 = ADD32(ctx->r4, 0X3C);
    // 0x800611FC: addiu       $s7, $sp, 0x60
    ctx->r23 = ADD32(ctx->r29, 0X60);
    // 0x80061200: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80061204:
    // 0x80061204: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80061208: jal         0x80069CF0
    // 0x8006120C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8006120C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80061210: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80061214: jal         0x800614C0
    // 0x80061218: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800614C0(rdram, ctx);
        goto after_1;
    // 0x80061218: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8006121C: lw          $t6, 0x670($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X670);
    // 0x80061220: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80061224: beq         $t6, $zero, L_80061240
    if (ctx->r14 == 0) {
        // 0x80061228: addiu       $a0, $s1, 0x11C
        ctx->r4 = ADD32(ctx->r17, 0X11C);
            goto L_80061240;
    }
    // 0x80061228: addiu       $a0, $s1, 0x11C
    ctx->r4 = ADD32(ctx->r17, 0X11C);
    // 0x8006122C: sw          $t7, 0x674($s1)
    MEM_W(0X674, ctx->r17) = ctx->r15;
    // 0x80061230: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80061234: jal         0x80069CF0
    // 0x80061238: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80061238: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8006123C: sw          $zero, 0x674($s1)
    MEM_W(0X674, ctx->r17) = 0;
L_80061240:
    // 0x80061240: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // NULL guard: scheduler thread may not have set up task pointer yet
    if ((uint32_t)ctx->r24 == 0) {
        ctx->r13 = MEM_W(ctx->r29, 0X60);
        goto L_800612C0;
    }
    // 0x80061244: nop

    // 0x80061248: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8006124C: nop

    // 0x80061250: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x80061254: beq         $at, $zero, L_800612C0
    if (ctx->r1 == 0) {
        // 0x80061258: lw          $t5, 0x60($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X60);
            goto L_800612C0;
    }
    // 0x80061258: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8006125C: jal         0x8006A690
    // 0x80061260: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    osGetTime_recomp(rdram, ctx);
        goto after_3;
    // 0x80061260: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_3:
    // 0x80061264: lui         $a3, 0xF
    ctx->r7 = S32(0XF << 16);
    // 0x80061268: ori         $a3, $a3, 0x4240
    ctx->r7 = ctx->r7 | 0X4240;
    // 0x8006126C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80061270: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80061274: jal         0x8006A888
    // 0x80061278: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    __ll_mul_recomp(rdram, ctx);
        goto after_4;
    // 0x80061278: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_4:
    // 0x8006127C: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    // 0x80061280: lw          $a3, 0x4($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X4);
    // 0x80061284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80061288: jal         0x8006A788
    // 0x8006128C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_5;
    // 0x8006128C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_5:
    // 0x80061290: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80061294: sll         $t9, $s3, 3
    ctx->r25 = S32(ctx->r19 << 3);
    // 0x80061298: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8006129C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800612A0: addu        $t4, $a0, $t9
    ctx->r12 = ADD32(ctx->r4, ctx->r25);
    // 0x800612A4: subu        $t2, $v0, $t0
    ctx->r10 = SUB32(ctx->r2, ctx->r8);
    // 0x800612A8: sltu        $at, $v1, $t1
    ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
    // 0x800612AC: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x800612B0: subu        $t3, $v1, $t1
    ctx->r11 = SUB32(ctx->r3, ctx->r9);
    // 0x800612B4: sw          $t3, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r11;
    // 0x800612B8: sw          $t2, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r10;
    // 0x800612BC: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
L_800612C0:
    // 0x800612C0: addiu       $s0, $s1, 0xAC
    ctx->r16 = ADD32(ctx->r17, 0XAC);
    // 0x800612C4: sw          $t5, 0x66C($s1)
    MEM_W(0X66C, ctx->r17) = ctx->r13;
    // 0x800612C8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800612CC: jal         0x8006AC6C
    // 0x800612D0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_6;
    // 0x800612D0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_6:
    // 0x800612D4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800612D8: jal         0x8006ADFC
    // 0x800612DC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_7;
    // 0x800612DC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_7:
    // 0x800612E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800612E4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800612E8: jal         0x80069CF0
    // 0x800612EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x800612EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x800612F0: sw          $zero, 0x66C($s1)
    MEM_W(0X66C, ctx->r17) = 0;
    // 0x800612F4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // NULL guard: scheduler may not have set up task pointer
    if ((uint32_t)ctx->r14 == 0) {
        ctx->r4 = ADD32(ctx->r17, 0XE4);
        goto L_80061374;
    }
    // 0x800612F8: nop

    // 0x800612FC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80061300: nop

    // 0x80061304: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80061308: beq         $at, $zero, L_80061374
    if (ctx->r1 == 0) {
        // 0x8006130C: addiu       $a0, $s1, 0xE4
        ctx->r4 = ADD32(ctx->r17, 0XE4);
            goto L_80061374;
    }
    // 0x8006130C: addiu       $a0, $s1, 0xE4
    ctx->r4 = ADD32(ctx->r17, 0XE4);
    // 0x80061310: jal         0x8006A690
    // 0x80061314: sll         $s0, $s3, 3
    ctx->r16 = S32(ctx->r19 << 3);
    osGetTime_recomp(rdram, ctx);
        goto after_9;
    // 0x80061314: sll         $s0, $s3, 3
    ctx->r16 = S32(ctx->r19 << 3);
    after_9:
    // 0x80061318: lui         $a3, 0xF
    ctx->r7 = S32(0XF << 16);
    // 0x8006131C: ori         $a3, $a3, 0x4240
    ctx->r7 = ctx->r7 | 0X4240;
    // 0x80061320: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80061324: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80061328: jal         0x8006A888
    // 0x8006132C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    __ll_mul_recomp(rdram, ctx);
        goto after_10;
    // 0x8006132C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_10:
    // 0x80061330: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    // 0x80061334: lw          $a3, 0x4($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X4);
    // 0x80061338: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006133C: jal         0x8006A788
    // 0x80061340: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_11;
    // 0x80061340: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_11:
    // 0x80061344: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80061348: nop

    // 0x8006134C: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x80061350: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x80061354: addu        $t2, $a0, $s0
    ctx->r10 = ADD32(ctx->r4, ctx->r16);
    // 0x80061358: subu        $t0, $v0, $t8
    ctx->r8 = SUB32(ctx->r2, ctx->r24);
    // 0x8006135C: sltu        $at, $v1, $t9
    ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
    // 0x80061360: subu        $t0, $t0, $at
    ctx->r8 = SUB32(ctx->r8, ctx->r1);
    // 0x80061364: subu        $t1, $v1, $t9
    ctx->r9 = SUB32(ctx->r3, ctx->r25);
    // 0x80061368: sw          $t1, 0x94($t2)
    MEM_W(0X94, ctx->r10) = ctx->r9;
    // 0x8006136C: sw          $t0, 0x90($t2)
    MEM_W(0X90, ctx->r10) = ctx->r8;
    // 0x80061370: addiu       $a0, $s1, 0xE4
    ctx->r4 = ADD32(ctx->r17, 0XE4);
L_80061374:
    // 0x80061374: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80061378: jal         0x80069CF0
    // 0x8006137C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x8006137C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80061380: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // NULL guard: scheduler may not have set up task pointer
    if ((uint32_t)ctx->r11 == 0) {
        goto L_80061414;
    }
    // 0x80061384: nop

    // 0x80061388: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8006138C: nop

    // 0x80061390: sltiu       $at, $t4, 0x8
    ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
    // 0x80061394: beq         $at, $zero, L_80061414
    if (ctx->r1 == 0) {
        // 0x80061398: nop
    
            goto L_80061414;
    }
    // 0x80061398: nop

    // 0x8006139C: jal         0x8006A690
    // 0x800613A0: sll         $s0, $s3, 3
    ctx->r16 = S32(ctx->r19 << 3);
    osGetTime_recomp(rdram, ctx);
        goto after_13;
    // 0x800613A0: sll         $s0, $s3, 3
    ctx->r16 = S32(ctx->r19 << 3);
    after_13:
    // 0x800613A4: lui         $a3, 0xF
    ctx->r7 = S32(0XF << 16);
    // 0x800613A8: ori         $a3, $a3, 0x4240
    ctx->r7 = ctx->r7 | 0X4240;
    // 0x800613AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800613B0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800613B4: jal         0x8006A888
    // 0x800613B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    __ll_mul_recomp(rdram, ctx);
        goto after_14;
    // 0x800613B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_14:
    // 0x800613BC: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    // 0x800613C0: lw          $a3, 0x4($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X4);
    // 0x800613C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800613C8: jal         0x8006A788
    // 0x800613CC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_15;
    // 0x800613CC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_15:
    // 0x800613D0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800613D4: nop

    // 0x800613D8: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800613DC: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x800613E0: addu        $t5, $a0, $s0
    ctx->r13 = ADD32(ctx->r4, ctx->r16);
    // 0x800613E4: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x800613E8: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x800613EC: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x800613F0: subu        $t9, $v1, $t7
    ctx->r25 = SUB32(ctx->r3, ctx->r15);
    // 0x800613F4: sw          $t9, 0x54($t5)
    MEM_W(0X54, ctx->r13) = ctx->r25;
    // 0x800613F8: sw          $t8, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->r24;
    // 0x800613FC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80061400: nop

    // 0x80061404: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x80061408: nop

    // 0x8006140C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80061410: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_80061414:
    // 0x80061414: lw          $t2, 0x678($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X678);
    // 0x80061418: nop

    // 0x8006141C: beq         $t2, $zero, L_80061434
    if (ctx->r10 == 0) {
        // 0x80061420: lw          $t3, 0x60($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X60);
            goto L_80061434;
    }
    // 0x80061420: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80061424: jal         0x8006A5B0
    // 0x80061428: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_16;
    // 0x80061428: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x8006142C: sw          $zero, 0x678($s1)
    MEM_W(0X678, ctx->r17) = 0;
    // 0x80061430: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
L_80061434:
    // 0x80061434: nop

    // 0x80061438: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x8006143C: nop

    // 0x80061440: andi        $t6, $t4, 0x40
    ctx->r14 = ctx->r12 & 0X40;
    // 0x80061444: beq         $t6, $zero, L_80061460
    if (ctx->r14 == 0) {
        // 0x80061448: lw          $t7, 0x60($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X60);
            goto L_80061460;
    }
    // 0x80061448: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8006144C: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x80061450: jal         0x8006AE40
    // 0x80061454: nop

    osViSwapBuffer_recomp(rdram, ctx);
        goto after_17;
    // 0x80061454: nop

    after_17:
    // 0x80061458: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    // 0x8006145C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
L_80061460:
    // 0x80061460: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80061464: lw          $a0, 0x50($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X50);
    // 0x80061468: lw          $a1, 0x54($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X54);
    // 0x8006146C: jal         0x8006A090
    // 0x80061470: nop

    osSendMesg_recomp(rdram, ctx);
        goto after_18;
    // 0x80061470: nop

    after_18:
    // 0x80061474: b           L_80061204
    // 0x80061478: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
        goto L_80061204;
    // 0x80061478: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8006147C: nop

    // 0x80061480: nop

    // 0x80061484: nop

    // 0x80061488: nop

    // 0x8006148C: nop

    // 0x80061490: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80061494: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80061498: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006149C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800614A0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800614A4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800614A8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800614AC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800614B0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800614B4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800614B8: jr          $ra
    // 0x800614BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800614BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800614C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800614C0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800614C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800614C8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800614CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800614D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800614D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800614D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800614DC: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800614E0: lw          $s3, 0xC($a1)
    ctx->r19 = MEM_W(ctx->r5, 0XC);
    // 0x800614E4: jal         0x8006AE90
    // 0x800614E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x800614E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    after_0:
    // 0x800614EC: beq         $v0, $s3, L_80061504
    if (ctx->r2 == ctx->r19) {
        // 0x800614F0: addiu       $s2, $sp, 0x3C
        ctx->r18 = ADD32(ctx->r29, 0X3C);
            goto L_80061504;
    }
    // 0x800614F0: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
    // 0x800614F4: jal         0x8006AED0
    // 0x800614F8: nop

    func_8006AED0(rdram, ctx);
        goto after_1;
    // 0x800614F8: nop

    after_1:
    // 0x800614FC: bne         $v0, $s3, L_80061558
    if (ctx->r2 != ctx->r19) {
        // 0x80061500: addiu       $s2, $sp, 0x3C
        ctx->r18 = ADD32(ctx->r29, 0X3C);
            goto L_80061558;
    }
    // 0x80061500: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
L_80061504:
    // 0x80061504: addiu       $s0, $s1, 0x11C
    ctx->r16 = ADD32(ctx->r17, 0X11C);
    // 0x80061508: addiu       $s4, $sp, 0x44
    ctx->r20 = ADD32(ctx->r29, 0X44);
    // 0x8006150C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80061510: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80061514: jal         0x80060DC0
    // 0x80061518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80060DC0(rdram, ctx);
        goto after_2;
    // 0x80061518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8006151C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061520: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80061524: jal         0x80069CF0
    // 0x80061528: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80061528: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8006152C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80061530: jal         0x80060E14
    // 0x80061534: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80060E14(rdram, ctx);
        goto after_4;
    // 0x80061534: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x80061538: jal         0x8006AE90
    // 0x8006153C: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_5;
    // 0x8006153C: nop

    after_5:
    // 0x80061540: beq         $v0, $s3, L_80061504
    if (ctx->r2 == ctx->r19) {
        // 0x80061544: addiu       $s2, $sp, 0x3C
        ctx->r18 = ADD32(ctx->r29, 0X3C);
            goto L_80061504;
    }
    // 0x80061544: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
    // 0x80061548: jal         0x8006AED0
    // 0x8006154C: nop

    func_8006AED0(rdram, ctx);
        goto after_6;
    // 0x8006154C: nop

    after_6:
    // 0x80061550: beq         $v0, $s3, L_80061504
    if (ctx->r2 == ctx->r19) {
        // 0x80061554: addiu       $s2, $sp, 0x3C
        ctx->r18 = ADD32(ctx->r29, 0X3C);
            goto L_80061504;
    }
    // 0x80061554: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
L_80061558:
    // 0x80061558: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006155C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80061560: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80061564: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80061568: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006156C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80061570: jr          $ra
    // 0x80061574: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80061574: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80061578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061578: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006157C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061580: jal         0x80060EA4
    // 0x80061584: addiu       $a1, $a0, 0x2
    ctx->r5 = ADD32(ctx->r4, 0X2);
    func_80060EA4(rdram, ctx);
        goto after_0;
    // 0x80061584: addiu       $a1, $a0, 0x2
    ctx->r5 = ADD32(ctx->r4, 0X2);
    after_0:
    // 0x80061588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006158C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80061590: jr          $ra
    // 0x80061594: nop

    return;
    // 0x80061594: nop

    // 0x80061598: nop

    // 0x8006159C: nop

;}
RECOMP_FUNC void func_800615A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800615A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800615A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800615A8: jal         0x8006AF10
    // 0x800615AC: ori         $a0, $zero, 0xAC44
    ctx->r4 = 0 | 0XAC44;
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_0;
    // 0x800615AC: ori         $a0, $zero, 0xAC44
    ctx->r4 = 0 | 0XAC44;
    after_0:
    // 0x800615B0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800615B4: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800615B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800615BC: bne         $t6, $at, L_80061610
    if (ctx->r14 != ctx->r1) {
        // 0x800615C0: lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
            goto L_80061610;
    }
    // 0x800615C0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800615C4: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x800615C8: addiu       $t8, $t8, 0x6710
    ctx->r24 = ADD32(ctx->r24, 0X6710);
    // 0x800615CC: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800615D0: addiu       $t7, $t7, 0x2110
    ctx->r15 = ADD32(ctx->r15, 0X2110);
    // 0x800615D4: addiu       $t0, $t8, 0x48
    ctx->r8 = ADD32(ctx->r24, 0X48);
L_800615D8:
    // 0x800615D8: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x800615DC: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x800615E0: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x800615E4: lw          $at, -0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X8);
    // 0x800615E8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800615EC: sw          $at, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r1;
    // 0x800615F0: lw          $at, -0x4($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X4);
    // 0x800615F4: bne         $t8, $t0, L_800615D8
    if (ctx->r24 != ctx->r8) {
        // 0x800615F8: sw          $at, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r1;
            goto L_800615D8;
    }
    // 0x800615F8: sw          $at, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r1;
    // 0x800615FC: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80061600: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x80061604: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x80061608: b           L_80061658
    // 0x8006160C: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
        goto L_80061658;
    // 0x8006160C: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
L_80061610:
    // 0x80061610: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80061614: addiu       $t2, $t2, 0x5E50
    ctx->r10 = ADD32(ctx->r10, 0X5E50);
    // 0x80061618: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x8006161C: addiu       $t1, $t1, 0x2110
    ctx->r9 = ADD32(ctx->r9, 0X2110);
    // 0x80061620: addiu       $t4, $t2, 0x48
    ctx->r12 = ADD32(ctx->r10, 0X48);
L_80061624:
    // 0x80061624: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80061628: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8006162C: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80061630: lw          $at, -0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X8);
    // 0x80061634: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80061638: sw          $at, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r1;
    // 0x8006163C: lw          $at, -0x4($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X4);
    // 0x80061640: bne         $t2, $t4, L_80061624
    if (ctx->r10 != ctx->r12) {
        // 0x80061644: sw          $at, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r1;
            goto L_80061624;
    }
    // 0x80061644: sw          $at, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r1;
    // 0x80061648: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8006164C: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x80061650: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80061654: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
L_80061658:
    // 0x80061658: addiu       $v0, $v0, 0x58E0
    ctx->r2 = ADD32(ctx->r2, 0X58E0);
    // 0x8006165C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80061660: addiu       $t5, $zero, 0x190
    ctx->r13 = ADD32(0, 0X190);
    // 0x80061664: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x80061668: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8006166C: addiu       $t9, $zero, 0x280
    ctx->r25 = ADD32(0, 0X280);
    // 0x80061670: sw          $t9, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r25;
    // 0x80061674: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80061678: addiu       $t8, $zero, 0x320
    ctx->r24 = ADD32(0, 0X320);
    // 0x8006167C: sw          $t8, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->r24;
    // 0x80061680: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80061684: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80061688: addiu       $a0, $a0, 0x2160
    ctx->r4 = ADD32(ctx->r4, 0X2160);
    // 0x8006168C: jal         0x80060A10
    // 0x80061690: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80060A10(rdram, ctx);
        goto after_1;
    // 0x80061690: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80061694: jal         0x80062820
    // 0x80061698: nop

    func_80062820(rdram, ctx);
        goto after_2;
    // 0x80061698: nop

    after_2:
    // 0x8006169C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800616A0: addiu       $a0, $a0, 0x2160
    ctx->r4 = ADD32(ctx->r4, 0X2160);
    // 0x800616A4: jal         0x800605CC
    // 0x800616A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800605CC(rdram, ctx);
        goto after_3;
    // 0x800616A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800616AC: jal         0x8006B0D0
    // 0x800616B0: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_4;
    // 0x800616B0: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_4:
    // 0x800616B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800616B8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800616BC: addiu       $a1, $a1, 0x3840
    ctx->r5 = ADD32(ctx->r5, 0X3840);
    // 0x800616C0: addiu       $a0, $a0, 0x3848
    ctx->r4 = ADD32(ctx->r4, 0X3848);
    // 0x800616C4: jal         0x800697E0
    // 0x800616C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_5;
    // 0x800616C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800616CC: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x800616D0: lui         $t4, 0x10
    ctx->r12 = S32(0X10 << 16);
    // 0x800616D4: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800616D8: lui         $t3, 0x803F
    ctx->r11 = S32(0X803F << 16);
    // 0x800616DC: addiu       $t4, $t4, -0x2560
    ctx->r12 = ADD32(ctx->r12, -0X2560);
    // 0x800616E0: addiu       $a3, $a3, -0x26A0
    ctx->r7 = ADD32(ctx->r7, -0X26A0);
    // 0x800616E4: addiu       $v1, $v1, 0x27E0
    ctx->r3 = ADD32(ctx->r3, 0X27E0);
    // 0x800616E8: ori         $a0, $t3, 0xFE00
    ctx->r4 = ctx->r11 | 0XFE00;
    // 0x800616EC: subu        $v0, $t4, $a3
    ctx->r2 = SUB32(ctx->r12, ctx->r7);
    // 0x800616F0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800616F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800616F8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800616FC: jal         0x8006B290
    // 0x80061700: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    osInvalDCache_recomp(rdram, ctx);
        goto after_6;
    // 0x80061700: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80061704: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x80061708: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8006170C: lw          $t2, 0x27E0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X27E0);
    // 0x80061710: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80061714: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80061718: addiu       $t1, $t1, 0x3848
    ctx->r9 = ADD32(ctx->r9, 0X3848);
    // 0x8006171C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80061720: addiu       $a0, $a0, 0x3860
    ctx->r4 = ADD32(ctx->r4, 0X3860);
    // 0x80061724: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80061728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006172C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80061730: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80061734: jal         0x8006B340
    // 0x80061738: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    osPiStartDma_recomp(rdram, ctx);
        goto after_7;
    // 0x80061738: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_7:
    // 0x8006173C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80061740: addiu       $a0, $a0, 0x3848
    ctx->r4 = ADD32(ctx->r4, 0X3848);
    // 0x80061744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061748: jal         0x80069CF0
    // 0x8006174C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x8006174C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80061750: lui         $a0, 0xC
    ctx->r4 = S32(0XC << 16);
    // 0x80061754: lui         $a1, 0xD
    ctx->r5 = S32(0XD << 16);
    // 0x80061758: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8006175C: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x80061760: addiu       $a3, $a3, -0x1FE0
    ctx->r7 = ADD32(ctx->r7, -0X1FE0);
    // 0x80061764: addiu       $a2, $a2, 0x77C0
    ctx->r6 = ADD32(ctx->r6, 0X77C0);
    // 0x80061768: addiu       $a1, $a1, 0x23B0
    ctx->r5 = ADD32(ctx->r5, 0X23B0);
    // 0x8006176C: jal         0x80062740
    // 0x80061770: addiu       $a0, $a0, -0xB00
    ctx->r4 = ADD32(ctx->r4, -0XB00);
    func_80062740(rdram, ctx);
        goto after_9;
    // 0x80061770: addiu       $a0, $a0, -0xB00
    ctx->r4 = ADD32(ctx->r4, -0XB00);
    after_9:
    // 0x80061774: jal         0x800601C0
    // 0x80061778: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800601C0(rdram, ctx);
        goto after_10;
    // 0x80061778: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_10:
    // 0x8006177C: jal         0x800603AC
    // 0x80061780: nop

    func_800603AC(rdram, ctx);
        goto after_11;
    // 0x80061780: nop

    after_11:
    // 0x80061784: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80061788: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006178C: jr          $ra
    // 0x80061790: nop

    return;
    // 0x80061790: nop

;}
RECOMP_FUNC void func_80061794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80061798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006179C: lui         $a0, 0xD
    ctx->r4 = S32(0XD << 16);
    // 0x800617A0: lui         $a1, 0x10
    ctx->r5 = S32(0X10 << 16);
    // 0x800617A4: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x800617A8: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800617AC: addiu       $a3, $a3, 0x70C0
    ctx->r7 = ADD32(ctx->r7, 0X70C0);
    // 0x800617B0: addiu       $a2, $a2, -0x1FC0
    ctx->r6 = ADD32(ctx->r6, -0X1FC0);
    // 0x800617B4: addiu       $a1, $a1, -0x4BD0
    ctx->r5 = ADD32(ctx->r5, -0X4BD0);
    // 0x800617B8: jal         0x80062740
    // 0x800617BC: addiu       $a0, $a0, 0x23B0
    ctx->r4 = ADD32(ctx->r4, 0X23B0);
    func_80062740(rdram, ctx);
        goto after_0;
    // 0x800617BC: addiu       $a0, $a0, 0x23B0
    ctx->r4 = ADD32(ctx->r4, 0X23B0);
    after_0:
    // 0x800617C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800617C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800617C8: jr          $ra
    // 0x800617CC: nop

    return;
    // 0x800617CC: nop

;}
RECOMP_FUNC void func_800617D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800617D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800617D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800617D8: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x800617DC: lui         $a1, 0x10
    ctx->r5 = S32(0X10 << 16);
    // 0x800617E0: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x800617E4: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x800617E8: addiu       $a3, $a3, 0x5F0
    ctx->r7 = ADD32(ctx->r7, 0X5F0);
    // 0x800617EC: addiu       $a2, $a2, -0x1FC0
    ctx->r6 = ADD32(ctx->r6, -0X1FC0);
    // 0x800617F0: addiu       $a1, $a1, -0x26A0
    ctx->r5 = ADD32(ctx->r5, -0X26A0);
    // 0x800617F4: jal         0x80062740
    // 0x800617F8: addiu       $a0, $a0, -0x4BD0
    ctx->r4 = ADD32(ctx->r4, -0X4BD0);
    func_80062740(rdram, ctx);
        goto after_0;
    // 0x800617F8: addiu       $a0, $a0, -0x4BD0
    ctx->r4 = ADD32(ctx->r4, -0X4BD0);
    after_0:
    // 0x800617FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80061804: jr          $ra
    // 0x80061808: nop

    return;
    // 0x80061808: nop

;}
RECOMP_FUNC void func_8006180C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006180C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80061810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061814: jal         0x800617D0
    // 0x80061818: nop

    func_800617D0(rdram, ctx);
        goto after_0;
    // 0x80061818: nop

    after_0:
    // 0x8006181C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80061820: lw          $t6, 0x5698($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5698);
    // 0x80061824: nop

    // 0x80061828: bne         $t6, $zero, L_80061838
    if (ctx->r14 != 0) {
        // 0x8006182C: nop
    
            goto L_80061838;
    }
    // 0x8006182C: nop

    // 0x80061830: jal         0x800639FC
    // 0x80061834: nop

    func_800639FC(rdram, ctx);
        goto after_1;
    // 0x80061834: nop

    after_1:
L_80061838:
    // 0x80061838: jal         0x8014F648
    // 0x8006183C: nop

    stub_8014F648(rdram, ctx);
        goto after_2;
    // 0x8006183C: nop

    after_2:
    // 0x80061840: jal         0x8014F280
    // 0x80061844: nop

    stub_8014F280(rdram, ctx);
        goto after_3;
    // 0x80061844: nop

    after_3:
    // 0x80061848: jal         0x800603D8
    // 0x8006184C: nop

    func_800603D8(rdram, ctx);
        goto after_4;
    // 0x8006184C: nop

    after_4:
    // 0x80061850: jal         0x80064744
    // 0x80061854: nop

    func_80064744(rdram, ctx);
        goto after_5;
    // 0x80061854: nop

    after_5:
    // 0x80061858: jal         0x800603AC
    // 0x8006185C: nop

    func_800603AC(rdram, ctx);
        goto after_6;
    // 0x8006185C: nop

    after_6:
    // 0x80061860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80061868: jr          $ra
    // 0x8006186C: nop

    return;
    // 0x8006186C: nop

;}
RECOMP_FUNC void func_80061870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    fprintf(stderr, "[BOOT] func_80061870 entered\n"); fflush(stderr);
    // 0x80061870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80061874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061878: jal         0x80068E00
    // 0x8006187C: nop

    fprintf(stderr, "[BOOT] 61870: calling 80068E00\n"); fflush(stderr);
    func_80068E00(rdram, ctx);
        goto after_0;
    // 0x8006187C: nop

    after_0:
    // 0x80061880: jal         0x80067B6C
    // 0x80061884: nop

    fprintf(stderr, "[BOOT] 61870: calling 80067B6C\n"); fflush(stderr);
    func_80067B6C(rdram, ctx);
        goto after_1;
    // 0x80061884: nop

    after_1:
    // 0x80061888: jal         0x800023B0
    // 0x8006188C: nop

    fprintf(stderr, "[BOOT] 61870: calling 800023B0\n"); fflush(stderr);
    func_800023B0(rdram, ctx);
        goto after_2;
    // 0x8006188C: nop

    after_2:
    // 0x80061890: jal         0x80002330
    // 0x80061894: nop

    fprintf(stderr, "[BOOT] 61870: calling 80002330\n"); fflush(stderr);
    func_80002330(rdram, ctx);
        goto after_3;
    // 0x80061894: nop

    after_3:
    // 0x80061898: jal         0x80003044
    // 0x8006189C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    fprintf(stderr, "[BOOT] 61870: calling 80003044\n"); fflush(stderr);
    func_80003044(rdram, ctx);
        goto after_4;
    // 0x8006189C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x800618A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800618A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800618A8: jr          $ra
    // 0x800618AC: nop

    return;
    // 0x800618AC: nop

;}
RECOMP_FUNC void func_800618B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    fprintf(stderr, "[BOOT] func_800618B0 entered\n"); fflush(stderr);
    // 0x800618B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800618B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800618B8: jal         0x800615A0
    // 0x800618BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    fprintf(stderr, "[BOOT] calling func_800615A0\n"); fflush(stderr);
    func_800615A0(rdram, ctx);
        goto after_0;
    // 0x800618BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    fprintf(stderr, "[BOOT] calling func_80064D50\n"); fflush(stderr);
    // 0x800618C0: lui         $a0, 0x3D
    ctx->r4 = S32(0X3D << 16);
    // 0x800618C4: jal         0x80064D50
    // 0x800618C8: ori         $a0, $a0, 0x900
    ctx->r4 = ctx->r4 | 0X900;
    func_80064D50(rdram, ctx);
        goto after_1;
    // 0x800618C8: ori         $a0, $a0, 0x900
    ctx->r4 = ctx->r4 | 0X900;
    after_1:
    fprintf(stderr, "[BOOT] calling func_80061870\n"); fflush(stderr);
    // 0x800618CC: jal         0x80061870
    // 0x800618D0: nop

    func_80061870(rdram, ctx);
        goto after_2;
    // 0x800618D0: nop

    after_2:
    fprintf(stderr, "[BOOT] calling func_8006180C\n"); fflush(stderr);
    // 0x800618D4: jal         0x8006180C
    // 0x800618D8: nop

    func_8006180C(rdram, ctx);
        goto after_3;
    // 0x800618D8: nop

    after_3:
    fprintf(stderr, "[BOOT] calling func_80061794\n"); fflush(stderr);
    // 0x800618DC: jal         0x80061794
    // 0x800618E0: nop

    func_80061794(rdram, ctx);
        goto after_4;
    // 0x800618E0: nop

    after_4:
    fprintf(stderr, "[BOOT] entering main loop\n"); fflush(stderr);
L_800618E4:
    // 0x800618E4: jal         0x80002230
    // 0x800618E8: nop

    func_80002230(rdram, ctx);
        goto after_5;
    // 0x800618E8: nop

    after_5:
    // 0x800618EC: b           L_800618E4
    // 0x800618F0: nop

        goto L_800618E4;
    // 0x800618F0: nop

    // 0x800618F4: nop

    // 0x800618F8: nop

    // 0x800618FC: nop

    // 0x80061900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80061908: jr          $ra
    // 0x8006190C: nop

    return;
    // 0x8006190C: nop

;}
RECOMP_FUNC void func_80061910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061910: slti        $at, $a0, 0x61
    ctx->r1 = SIGNED(ctx->r4) < 0X61 ? 1 : 0;
    // 0x80061914: bne         $at, $zero, L_80061930
    if (ctx->r1 != 0) {
            // 0x80061918: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    func_80061930(rdram, ctx);
    return;
    }
    // 0x80061918: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006191C: slti        $at, $a0, 0x7B
    ctx->r1 = SIGNED(ctx->r4) < 0X7B ? 1 : 0;
    // 0x80061920: beq         $at, $zero, L_80061930
    if (ctx->r1 == 0) {
            // 0x80061924: nop

    func_80061930(rdram, ctx);
    return;
    }
    // 0x80061924: nop

    // 0x80061928: jr          $ra
    // 0x8006192C: addiu       $v0, $a0, -0x20
    ctx->r2 = ADD32(ctx->r4, -0X20);
    return;
    // 0x8006192C: addiu       $v0, $a0, -0x20
    ctx->r2 = ADD32(ctx->r4, -0X20);
;}
RECOMP_FUNC void func_80061930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061930: jr          $ra
    // 0x80061934: nop

    return;
    // 0x80061934: nop

;}
RECOMP_FUNC void func_80061938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061938: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
    // 0x8006193C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80061940: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80061944: bne         $at, $zero, L_80061994
    if (ctx->r1 != 0) {
        // 0x80061948: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80061994;
    }
    // 0x80061948: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006194C: subu        $a3, $v1, $a0
    ctx->r7 = SUB32(ctx->r3, ctx->r4);
    // 0x80061950: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80061954: andi        $t6, $a3, 0x3
    ctx->r14 = ctx->r7 & 0X3;
    // 0x80061958: negu        $a3, $t6
    ctx->r7 = SUB32(0, ctx->r14);
    // 0x8006195C: beq         $a3, $zero, L_80061978
    if (ctx->r7 == 0) {
        // 0x80061960: addu        $a2, $a3, $v1
        ctx->r6 = ADD32(ctx->r7, ctx->r3);
            goto L_80061978;
    }
    // 0x80061960: addu        $a2, $a3, $v1
    ctx->r6 = ADD32(ctx->r7, ctx->r3);
L_80061964:
    // 0x80061964: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80061968: bne         $a2, $v0, L_80061964
    if (ctx->r6 != ctx->r2) {
        // 0x8006196C: sb          $a1, 0x1($v0)
        MEM_B(0X1, ctx->r2) = ctx->r5;
            goto L_80061964;
    }
    // 0x8006196C: sb          $a1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r5;
    // 0x80061970: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80061974: beq         $t7, $a0, L_80061994
    if (ctx->r15 == ctx->r4) {
        // 0x80061978: addiu       $v1, $a0, -0x1
        ctx->r3 = ADD32(ctx->r4, -0X1);
            goto L_80061994;
    }
L_80061978:
    // 0x80061978: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
L_8006197C:
    // 0x8006197C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80061980: sb          $a1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r5;
    // 0x80061984: sb          $a1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r5;
    // 0x80061988: sb          $a1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r5;
    // 0x8006198C: bne         $v0, $v1, L_8006197C
    if (ctx->r2 != ctx->r3) {
        // 0x80061990: sb          $a1, 0x4($v0)
        MEM_B(0X4, ctx->r2) = ctx->r5;
            goto L_8006197C;
    }
    // 0x80061990: sb          $a1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r5;
L_80061994:
    // 0x80061994: jr          $ra
    // 0x80061998: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80061998: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_8006199C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006199C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
L_800619A0:
    // 0x800619A0: b           L_800619A0
    pause_self(rdram);
    // 0x800619A4: nop

    // 0x800619A8: nop

    // 0x800619AC: nop

    // 0x800619B0: jr          $ra
    // 0x800619B4: nop

    return;
    // 0x800619B4: nop

;}
RECOMP_FUNC void func_800619B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800619B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800619BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800619C0: jal         0x8006B450
    // 0x800619C4: nop

    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800619C4: nop

    after_0:
    // 0x800619C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800619CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800619D0: jr          $ra
    // 0x800619D4: nop

    return;
    // 0x800619D4: nop

;}
RECOMP_FUNC void func_800619D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800619D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800619DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800619E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800619E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800619E8: jal         0x8006B47C
    // 0x800619EC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    strlen_recomp(rdram, ctx);
        goto after_0;
    // 0x800619EC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800619F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800619F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800619F8: jal         0x8006B450
    // 0x800619FC: addiu       $a2, $v0, 0x1
    ctx->r6 = ADD32(ctx->r2, 0X1);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x800619FC: addiu       $a2, $v0, 0x1
    ctx->r6 = ADD32(ctx->r2, 0X1);
    after_1:
    // 0x80061A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80061A08: jr          $ra
    // 0x80061A0C: nop

    return;
    // 0x80061A0C: nop

;}
RECOMP_FUNC void func_80061A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80061A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061A18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80061A1C: jal         0x8006B47C
    // 0x80061A20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    strlen_recomp(rdram, ctx);
        goto after_0;
    // 0x80061A20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80061A24: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80061A28: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80061A2C: jal         0x800619D8
    // 0x80061A30: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    func_800619D8(rdram, ctx);
        goto after_1;
    // 0x80061A30: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    after_1:
    // 0x80061A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061A38: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80061A3C: jr          $ra
    // 0x80061A40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80061A40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80061A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061A44: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80061A48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80061A4C: beq         $t6, $zero, L_80061AA4
    if (ctx->r14 == 0) {
        // 0x80061A50: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80061AA4;
    }
    // 0x80061A50: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80061A54: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x80061A58: nop

    // 0x80061A5C: beq         $t7, $zero, L_80061AA4
    if (ctx->r15 == 0) {
        // 0x80061A60: nop
    
            goto L_80061AA4;
    }
    // 0x80061A60: nop

    // 0x80061A64: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x80061A68: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x80061A6C: nop

    // 0x80061A70: subu        $a1, $a0, $a2
    ctx->r5 = SUB32(ctx->r4, ctx->r6);
L_80061A74:
    // 0x80061A74: beq         $a1, $zero, L_80061A84
    if (ctx->r5 == 0) {
        // 0x80061A78: nop
    
            goto L_80061A84;
    }
    // 0x80061A78: nop

    // 0x80061A7C: jr          $ra
    // 0x80061A80: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x80061A80: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80061A84:
    // 0x80061A84: lbu         $a2, 0x1($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X1);
    // 0x80061A88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80061A8C: beq         $a2, $zero, L_80061AA4
    if (ctx->r6 == 0) {
        // 0x80061A90: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80061AA4;
    }
    // 0x80061A90: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80061A94: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x80061A98: nop

    // 0x80061A9C: bne         $a0, $zero, L_80061A74
    if (ctx->r4 != 0) {
        // 0x80061AA0: subu        $a1, $a0, $a2
        ctx->r5 = SUB32(ctx->r4, ctx->r6);
            goto L_80061A74;
    }
    // 0x80061AA0: subu        $a1, $a0, $a2
    ctx->r5 = SUB32(ctx->r4, ctx->r6);
L_80061AA4:
    // 0x80061AA4: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80061AA8: nop

    // 0x80061AAC: beq         $t8, $zero, L_80061ABC
    if (ctx->r24 == 0) {
            // 0x80061AB0: nop

    func_80061ABC(rdram, ctx);
    return;
    }
    // 0x80061AB0: nop

    // 0x80061AB4: jr          $ra
    // 0x80061AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80061AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80061ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061ABC: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80061AC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061AC4: beq         $t9, $zero, L_80061AD4
    if (ctx->r25 == 0) {
            // 0x80061AC8: nop

    func_80061AD4(rdram, ctx);
    return;
    }
    // 0x80061AC8: nop

    // 0x80061ACC: jr          $ra
    // 0x80061AD0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80061AD0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
;}
RECOMP_FUNC void func_80061AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061AD4: jr          $ra
    // 0x80061AD8: nop

    return;
    // 0x80061AD8: nop

;}
RECOMP_FUNC void func_80061ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80061AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061AE4: jal         0x8006B4F0
    // 0x80061AE8: nop

    func_8006B4F0(rdram, ctx);
        goto after_0;
    // 0x80061AE8: nop

    after_0:
    // 0x80061AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061AF0: sra         $t6, $v0, 3
    ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80061AF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80061AF8: jr          $ra
    // 0x80061AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80061AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80061B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061B00: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80061B04: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80061B08: addiu       $v0, $v0, 0x480C
    ctx->r2 = ADD32(ctx->r2, 0X480C);
    // 0x80061B0C: addiu       $t6, $t6, 0x4800
    ctx->r14 = ADD32(ctx->r14, 0X4800);
    // 0x80061B10: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80061B14: sw          $a0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r4;
    // 0x80061B18: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80061B1C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80061B20: sw          $a1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r5;
    // 0x80061B24: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80061B28: addiu       $v1, $v1, 0x58F0
    ctx->r3 = ADD32(ctx->r3, 0X58F0);
    // 0x80061B2C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80061B30: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80061B34: nop

    // 0x80061B38: addiu       $t1, $t0, 0xF
    ctx->r9 = ADD32(ctx->r8, 0XF);
    // 0x80061B3C: srl         $t2, $t1, 4
    ctx->r10 = S32(U32(ctx->r9) >> 4);
    // 0x80061B40: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80061B44: jr          $ra
    // 0x80061B48: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    return;
    // 0x80061B48: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
;}
RECOMP_FUNC void func_80061B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061B4C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80061B50: addiu       $v1, $v1, 0x480C
    ctx->r3 = ADD32(ctx->r3, 0X480C);
    // 0x80061B54: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80061B58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80061B5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80061B60: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80061B64: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80061B68: jr          $ra
    // 0x80061B6C: nop

    return;
    // 0x80061B6C: nop

;}
RECOMP_FUNC void func_80061B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061B70: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80061B74: lw          $t6, 0x480C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X480C);
    // 0x80061B78: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80061B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061B80: jr          $ra
    // 0x80061B84: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    return;
    // 0x80061B84: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
;}
RECOMP_FUNC void func_80061B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061B88: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80061B8C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80061B90: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80061B94: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80061B98: jr          $ra
    // 0x80061B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80061B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80061BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061BA0: bne         $a2, $zero, L_80061BB8
    if (ctx->r6 != 0) {
        // 0x80061BA4: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_80061BB8;
    }
    // 0x80061BA4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80061BA8: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80061BAC: lw          $t6, 0x480C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X480C);
    // 0x80061BB0: b           L_80061BDC
    // 0x80061BB4: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
        goto L_80061BDC;
    // 0x80061BB4: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
L_80061BB8:
    // 0x80061BB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80061BBC: bne         $a2, $at, L_80061BDC
    if (ctx->r6 != ctx->r1) {
        // 0x80061BC0: lui         $v1, 0x800F
        ctx->r3 = S32(0X800F << 16);
            goto L_80061BDC;
    }
    // 0x80061BC0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80061BC4: lw          $v1, 0x480C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X480C);
    // 0x80061BC8: nop

    // 0x80061BCC: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80061BD0: nop

    // 0x80061BD4: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x80061BD8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_80061BDC:
    // 0x80061BDC: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80061BE0: lw          $v1, 0x480C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X480C);
    // 0x80061BE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061BE8: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x80061BEC: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x80061BF0: nop

    // 0x80061BF4: sltu        $at, $a0, $t9
    ctx->r1 = ctx->r4 < ctx->r25 ? 1 : 0;
    // 0x80061BF8: beq         $at, $zero, L_80061C0C
    if (ctx->r1 == 0) {
            // 0x80061BFC: nop

    func_80061C0C(rdram, ctx);
    return;
    }
    // 0x80061BFC: nop

    // 0x80061C00: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x80061C04: jr          $ra
    // 0x80061C08: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80061C08: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
;}
RECOMP_FUNC void func_80061C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061C0C: jr          $ra
    // 0x80061C10: nop

    return;
    // 0x80061C10: nop

;}
RECOMP_FUNC void func_80061C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061C14: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80061C18: lw          $t6, 0x480C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X480C);
    // 0x80061C1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80061C20: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x80061C24: jr          $ra
    // 0x80061C28: nop

    return;
    // 0x80061C28: nop

;}
RECOMP_FUNC void func_80061C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061C2C: multu       $a1, $a2
    // INLINED FALLTHROUGH: func_80061C2C does multu then falls through to func_80061C30
    // We compute multu here and also at start of func_80061C30 since lo is local
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // Store result in context regs temporarily so func_80061C30 can read them
    // Actually, just inline the call and compute lo/hi at callee start
    func_80061C30(rdram, ctx);
;}
RECOMP_FUNC void func_80061C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // FALLTHROUGH FIX: recompute multu $a1, $a2 since lo/hi are local vars
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061C30: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80061C34: addiu       $t8, $a0, 0xF
    ctx->r24 = ADD32(ctx->r4, 0XF);
    // 0x80061C38: srl         $t9, $t8, 4
    ctx->r25 = S32(U32(ctx->r24) >> 4);
    // 0x80061C3C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80061C40: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80061C44: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80061C48: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80061C4C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80061C50: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80061C54: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80061C58: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80061C5C: mflo        $t7
    ctx->r15 = lo;
    // 0x80061C60: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80061C64: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80061C68: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80061C6C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80061C70: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80061C74: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x80061C78: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x80061C7C: or          $s6, $t7, $zero
    ctx->r22 = ctx->r15 | 0;
    // 0x80061C80: bne         $a0, $t0, L_80061C9C
    if (ctx->r4 != ctx->r8) {
        // 0x80061C84: or          $t6, $a1, $zero
        ctx->r14 = ctx->r5 | 0;
            goto L_80061C9C;
    }
    // 0x80061C84: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x80061C88: andi        $t1, $t7, 0x1
    ctx->r9 = ctx->r15 & 0X1;
    // 0x80061C8C: bne         $t1, $zero, L_80061C9C
    if (ctx->r9 != 0) {
        // 0x80061C90: or          $s3, $a0, $zero
        ctx->r19 = ctx->r4 | 0;
            goto L_80061C9C;
    }
    // 0x80061C90: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80061C94: b           L_80061CCC
    // 0x80061C98: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
        goto L_80061CCC;
    // 0x80061C98: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
L_80061C9C:
    // 0x80061C9C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80061CA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80061CA4: bgez        $t2, L_80061CB8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80061CA8: andi        $t3, $t2, 0x1
        ctx->r11 = ctx->r10 & 0X1;
            goto L_80061CB8;
    }
    // 0x80061CA8: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80061CAC: beq         $t3, $zero, L_80061CB8
    if (ctx->r11 == 0) {
        // 0x80061CB0: nop
    
            goto L_80061CB8;
    }
    // 0x80061CB0: nop

    // 0x80061CB4: addiu       $t3, $t3, -0x2
    ctx->r11 = ADD32(ctx->r11, -0X2);
L_80061CB8:
    // 0x80061CB8: bne         $t3, $at, L_80061CC4
    if (ctx->r11 != ctx->r1) {
        // 0x80061CBC: lui         $s3, 0x8008
        ctx->r19 = S32(0X8008 << 16);
            goto L_80061CC4;
    }
    // 0x80061CBC: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80061CC0: addiu       $s6, $t2, 0x1
    ctx->r22 = ADD32(ctx->r10, 0X1);
L_80061CC4:
    // 0x80061CC4: lw          $s3, 0x58F0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X58F0);
    // 0x80061CC8: addiu       $s5, $zero, 0x2000
    ctx->r21 = ADD32(0, 0X2000);
L_80061CCC:
    // 0x80061CCC: bgtz        $s6, L_80061CDC
    if (SIGNED(ctx->r22) > 0) {
        // 0x80061CD0: lui         $s4, 0x800F
        ctx->r20 = S32(0X800F << 16);
            goto L_80061CDC;
    }
    // 0x80061CD0: lui         $s4, 0x800F
    ctx->r20 = S32(0X800F << 16);
    // 0x80061CD4: b           L_80061DE4
    // 0x80061CD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80061DE4;
    // 0x80061CD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061CDC:
    // 0x80061CDC: addiu       $s4, $s4, 0x480C
    ctx->r20 = ADD32(ctx->r20, 0X480C);
    // 0x80061CE0: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x80061CE4: nop

    // 0x80061CE8: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80061CEC: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80061CF0: addu        $t4, $s6, $a0
    ctx->r12 = ADD32(ctx->r22, ctx->r4);
    // 0x80061CF4: sltu        $at, $v0, $t4
    ctx->r1 = ctx->r2 < ctx->r12 ? 1 : 0;
    // 0x80061CF8: beq         $at, $zero, L_80061D04
    if (ctx->r1 == 0) {
        // 0x80061CFC: nop
    
            goto L_80061D04;
    }
    // 0x80061CFC: nop

    // 0x80061D00: subu        $s6, $v0, $a0
    ctx->r22 = SUB32(ctx->r2, ctx->r4);
L_80061D04:
    // 0x80061D04: blez        $s6, L_80061DBC
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80061D08: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80061DBC;
    }
    // 0x80061D08: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80061D0C: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x80061D10: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80061D14: addiu       $s2, $s2, 0x3848
    ctx->r18 = ADD32(ctx->r18, 0X3848);
    // 0x80061D18: addiu       $s7, $s7, 0x3860
    ctx->r23 = ADD32(ctx->r23, 0X3860);
L_80061D1C:
    // 0x80061D1C: subu        $v0, $s6, $s1
    ctx->r2 = SUB32(ctx->r22, ctx->r17);
    // 0x80061D20: slt         $at, $v0, $s5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80061D24: beq         $at, $zero, L_80061D30
    if (ctx->r1 == 0) {
        // 0x80061D28: or          $s0, $s5, $zero
        ctx->r16 = ctx->r21 | 0;
            goto L_80061D30;
    }
    // 0x80061D28: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x80061D2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80061D30:
    // 0x80061D30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80061D34: jal         0x8006B290
    // 0x80061D38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80061D38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80061D3C: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x80061D40: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80061D44: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80061D48: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x80061D4C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80061D50: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80061D54: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80061D58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061D5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80061D60: jal         0x8006B340
    // 0x80061D64: addu        $a3, $t5, $t6
    ctx->r7 = ADD32(ctx->r13, ctx->r14);
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x80061D64: addu        $a3, $t5, $t6
    ctx->r7 = ADD32(ctx->r13, ctx->r14);
    after_1:
    // 0x80061D68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80061D6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061D70: jal         0x80069CF0
    // 0x80061D74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80061D74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80061D78: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x80061D7C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80061D80: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80061D84: nop

    // 0x80061D88: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80061D8C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80061D90: lw          $a1, 0x58F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X58F0);
    // 0x80061D94: nop

    // 0x80061D98: bne         $s3, $a1, L_80061DAC
    if (ctx->r19 != ctx->r5) {
        // 0x80061D9C: nop
    
            goto L_80061DAC;
    }
    // 0x80061D9C: nop

    // 0x80061DA0: addu        $a0, $fp, $s1
    ctx->r4 = ADD32(ctx->r30, ctx->r17);
    // 0x80061DA4: jal         0x8006B450
    // 0x80061DA8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x80061DA8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
L_80061DAC:
    // 0x80061DAC: addu        $s1, $s1, $s0
    ctx->r17 = ADD32(ctx->r17, ctx->r16);
    // 0x80061DB0: slt         $at, $s1, $s6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80061DB4: bne         $at, $zero, L_80061D1C
    if (ctx->r1 != 0) {
        // 0x80061DB8: nop
    
            goto L_80061D1C;
    }
    // 0x80061DB8: nop

L_80061DBC:
    // 0x80061DBC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80061DC0: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x80061DC4: nop

    // 0x80061DC8: divu        $zero, $t0, $t1
    lo = S32(U32(ctx->r8) / U32(ctx->r9)); hi = S32(U32(ctx->r8) % U32(ctx->r9));
    // 0x80061DCC: bne         $t1, $zero, L_80061DD8
    if (ctx->r9 != 0) {
        // 0x80061DD0: nop
    
            goto L_80061DD8;
    }
    // 0x80061DD0: nop

    // 0x80061DD4: break       7
    do_break(2147884500);
L_80061DD8:
    // 0x80061DD8: mflo        $v0
    ctx->r2 = lo;
    // 0x80061DDC: nop

    // 0x80061DE0: nop

L_80061DE4:
    // 0x80061DE4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80061DE8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80061DEC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80061DF0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80061DF4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80061DF8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80061DFC: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80061E00: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80061E04: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80061E08: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80061E0C: jr          $ra
    // 0x80061E10: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80061E10: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80061E14: nop

    // 0x80061E18: nop

    // 0x80061E1C: nop

;}
RECOMP_FUNC void func_80061E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061E20: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80061E24: sw          $zero, 0x5900($at)
    MEM_W(0X5900, ctx->r1) = 0;
    // 0x80061E28: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80061E2C: jr          $ra
    // 0x80061E30: sw          $zero, 0x5904($at)
    MEM_W(0X5904, ctx->r1) = 0;
    return;
    // 0x80061E30: sw          $zero, 0x5904($at)
    MEM_W(0X5904, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80061E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061E34: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80061E38: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80061E3C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80061E40: addiu       $s0, $s0, -0x31D8
    ctx->r16 = ADD32(ctx->r16, -0X31D8);
    // 0x80061E44: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80061E48: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x80061E4C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80061E50: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80061E54: ori         $t7, $t7, 0x1402
    ctx->r15 = ctx->r15 | 0X1402;
    // 0x80061E58: lui         $t8, 0x30
    ctx->r24 = S32(0X30 << 16);
    // 0x80061E5C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80061E60: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80061E64: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80061E68: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80061E6C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80061E70: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80061E74: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061E78: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80061E7C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80061E80: lui         $t9, 0x200
    ctx->r25 = S32(0X200 << 16);
    // 0x80061E84: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80061E88: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80061E8C: lui         $t8, 0xFF10
    ctx->r24 = S32(0XFF10 << 16);
    // 0x80061E90: ori         $t8, $t8, 0x18F
    ctx->r24 = ctx->r24 | 0X18F;
    // 0x80061E94: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x80061E98: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80061E9C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80061EA0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80061EA4: lui         $t7, 0xF700
    ctx->r15 = S32(0XF700 << 16);
    // 0x80061EA8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80061EAC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80061EB0: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x80061EB4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80061EB8: andi        $t7, $t6, 0x7C0
    ctx->r15 = ctx->r14 & 0X7C0;
    // 0x80061EBC: sll         $t8, $a0, 8
    ctx->r24 = S32(ctx->r4 << 8);
    // 0x80061EC0: andi        $t9, $t8, 0xF800
    ctx->r25 = ctx->r24 & 0XF800;
    // 0x80061EC4: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80061EC8: sra         $t6, $a2, 2
    ctx->r14 = S32(SIGNED(ctx->r6) >> 2);
    // 0x80061ECC: andi        $t9, $t6, 0x3E
    ctx->r25 = ctx->r14 & 0X3E;
    // 0x80061ED0: or          $t2, $t8, $t9
    ctx->r10 = ctx->r24 | ctx->r25;
    // 0x80061ED4: ori         $t7, $t2, 0x1
    ctx->r15 = ctx->r10 | 0X1;
    // 0x80061ED8: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80061EDC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80061EE0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80061EE4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80061EE8: lui         $t7, 0xF663
    ctx->r15 = S32(0XF663 << 16);
    // 0x80061EEC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80061EF0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80061EF4: ori         $t7, $t7, 0xC3BC
    ctx->r15 = ctx->r15 | 0XC3BC;
    // 0x80061EF8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80061EFC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061F00: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80061F04: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80061F08: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80061F0C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80061F10: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061F14: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80061F18: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80061F1C: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x80061F20: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80061F24: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80061F28: ori         $t7, $t7, 0x1402
    ctx->r15 = ctx->r15 | 0X1402;
    // 0x80061F2C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80061F30: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061F34: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80061F38: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80061F3C: sw          $zero, 0x5900($at)
    MEM_W(0X5900, ctx->r1) = 0;
    // 0x80061F40: jr          $ra
    // 0x80061F44: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80061F44: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80061F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061F48: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80061F4C: addiu       $a2, $a2, -0x31D8
    ctx->r6 = ADD32(ctx->r6, -0X31D8);
    // 0x80061F50: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80061F54: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x80061F58: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80061F5C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80061F60: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x80061F64: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x80061F68: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80061F6C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80061F70: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80061F74: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x80061F78: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80061F7C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80061F80: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x80061F84: jr          $ra
    // 0x80061F88: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    return;
    // 0x80061F88: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
;}
RECOMP_FUNC void func_80061F8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061F8C: bne         $a0, $zero, L_80061FE4
    if (ctx->r4 != 0) {
        // 0x80061F90: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80061FE4;
    }
    // 0x80061F90: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80061F94: addiu       $a2, $a2, -0x31D8
    ctx->r6 = ADD32(ctx->r6, -0X31D8);
    // 0x80061F98: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80061F9C: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80061FA0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80061FA4: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80061FA8: lui         $t8, 0xF0A
    ctx->r24 = S32(0XF0A << 16);
    // 0x80061FAC: ori         $t8, $t8, 0x7008
    ctx->r24 = ctx->r24 | 0X7008;
    // 0x80061FB0: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x80061FB4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80061FB8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80061FBC: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80061FC0: lui         $t0, 0xB900
    ctx->r8 = S32(0XB900 << 16);
    // 0x80061FC4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80061FC8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80061FCC: ori         $t0, $t0, 0x2
    ctx->r8 = ctx->r8 | 0X2;
    // 0x80061FD0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80061FD4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80061FD8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061FDC: b           L_80062038
    // 0x80061FE0: sb          $zero, 0x59E8($at)
    MEM_B(0X59E8, ctx->r1) = 0;
        goto L_80062038;
    // 0x80061FE0: sb          $zero, 0x59E8($at)
    MEM_B(0X59E8, ctx->r1) = 0;
L_80061FE4:
    // 0x80061FE4: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x80061FE8: bne         $a0, $at, L_80062038
    if (ctx->r4 != ctx->r1) {
        // 0x80061FEC: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80062038;
    }
    // 0x80061FEC: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80061FF0: addiu       $a2, $a2, -0x31D8
    ctx->r6 = ADD32(ctx->r6, -0X31D8);
    // 0x80061FF4: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80061FF8: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x80061FFC: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80062000: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80062004: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x80062008: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8006200C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80062010: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80062014: lui         $t4, 0xB900
    ctx->r12 = S32(0XB900 << 16);
    // 0x80062018: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8006201C: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80062020: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80062024: ori         $t4, $t4, 0x2
    ctx->r12 = ctx->r12 | 0X2;
    // 0x80062028: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8006202C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80062030: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80062034: sb          $a3, 0x59E8($at)
    MEM_B(0X59E8, ctx->r1) = ctx->r7;
L_80062038:
    // 0x80062038: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8006203C: addiu       $a2, $a2, -0x31D8
    ctx->r6 = ADD32(ctx->r6, -0X31D8);
    // 0x80062040: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80062044: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x80062048: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8006204C: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80062050: ori         $t6, $t6, 0x1402
    ctx->r14 = ctx->r14 | 0X1402;
    // 0x80062054: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80062058: jr          $ra
    // 0x8006205C: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    return;
    // 0x8006205C: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
;}
RECOMP_FUNC void func_80062060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062068: bne         $a0, $zero, L_80062090
    if (ctx->r4 != 0) {
        // 0x8006206C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80062090;
    }
    // 0x8006206C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80062070: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80062074: addiu       $v0, $v0, 0x5900
    ctx->r2 = ADD32(ctx->r2, 0X5900);
    // 0x80062078: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006207C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80062080: beq         $v1, $t6, L_80062190
    if (ctx->r3 == ctx->r14) {
        // 0x80062084: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80062190;
    }
    // 0x80062084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062088: b           L_800620AC
    // 0x8006208C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
        goto L_800620AC;
    // 0x8006208C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_80062090:
    // 0x80062090: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80062094: addiu       $v0, $v0, 0x5900
    ctx->r2 = ADD32(ctx->r2, 0X5900);
    // 0x80062098: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8006209C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800620A0: beq         $v1, $t7, L_80062190
    if (ctx->r3 == ctx->r15) {
        // 0x800620A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80062190;
    }
    // 0x800620A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800620A8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_800620AC:
    // 0x800620AC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800620B0: addiu       $v1, $v1, -0x31D8
    ctx->r3 = ADD32(ctx->r3, -0X31D8);
    // 0x800620B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800620B8: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800620BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800620C0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800620C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800620C8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800620CC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800620D0: jal         0x80061F48
    // 0x800620D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80061F48(rdram, ctx);
        goto after_0;
    // 0x800620D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800620D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800620DC: jal         0x80061F8C
    // 0x800620E0: nop

    func_80061F8C(rdram, ctx);
        goto after_1;
    // 0x800620E0: nop

    after_1:
    // 0x800620E4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800620E8: addiu       $v1, $v1, -0x31D8
    ctx->r3 = ADD32(ctx->r3, -0X31D8);
    // 0x800620EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800620F0: lui         $t2, 0xBB00
    ctx->r10 = S32(0XBB00 << 16);
    // 0x800620F4: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800620F8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800620FC: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80062100: ori         $t3, $t3, 0x8000
    ctx->r11 = ctx->r11 | 0X8000;
    // 0x80062104: ori         $t2, $t2, 0x1
    ctx->r10 = ctx->r10 | 0X1;
    // 0x80062108: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8006210C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80062110: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80062114: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x80062118: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8006211C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80062120: ori         $t5, $t5, 0x1001
    ctx->r13 = ctx->r13 | 0X1001;
    // 0x80062124: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80062128: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006212C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80062130: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x80062134: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80062138: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006213C: ori         $t7, $t7, 0x1301
    ctx->r15 = ctx->r15 | 0X1301;
    // 0x80062140: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80062144: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80062148: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006214C: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x80062150: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80062154: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80062158: ori         $t9, $t9, 0xC02
    ctx->r25 = ctx->r25 | 0XC02;
    // 0x8006215C: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    // 0x80062160: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80062164: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80062168: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006216C: lui         $t4, 0xFFFC
    ctx->r12 = S32(0XFFFC << 16);
    // 0x80062170: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80062174: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80062178: lui         $t3, 0xFCFF
    ctx->r11 = S32(0XFCFF << 16);
    // 0x8006217C: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x80062180: ori         $t4, $t4, 0xF279
    ctx->r12 = ctx->r12 | 0XF279;
    // 0x80062184: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80062188: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8006218C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80062190:
    // 0x80062190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062194: jr          $ra
    // 0x80062198: nop

    return;
    // 0x80062198: nop

;}
RECOMP_FUNC void func_8006219C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006219C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800621A0: lw          $t6, 0x5900($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5900);
    // FALLTHROUGH FIX: func_8006219C falls through to func_800621A4
    func_800621A4(rdram, ctx);
;}
RECOMP_FUNC void func_800621A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800621A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800621A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800621AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800621B0: beq         $t6, $at, L_8006221C
    if (ctx->r14 == ctx->r1) {
        // 0x800621B4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8006221C;
    }
    // 0x800621B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800621B8: jal         0x80062060
    // 0x800621BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80062060(rdram, ctx);
        goto after_0;
    // 0x800621BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800621C0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800621C4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800621C8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800621CC: addiu       $a1, $a1, -0x31D8
    ctx->r5 = ADD32(ctx->r5, -0X31D8);
    // 0x800621D0: sw          $t7, 0x5900($at)
    MEM_W(0X5900, ctx->r1) = ctx->r15;
    // 0x800621D4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800621D8: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x800621DC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800621E0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800621E4: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x800621E8: ori         $t0, $t0, 0x41C8
    ctx->r8 = ctx->r8 | 0X41C8;
    // 0x800621EC: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x800621F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800621F4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800621F8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800621FC: lui         $t2, 0xFCFF
    ctx->r10 = S32(0XFCFF << 16);
    // 0x80062200: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80062204: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80062208: lui         $t3, 0xFF2C
    ctx->r11 = S32(0XFF2C << 16);
    // 0x8006220C: ori         $t3, $t3, 0xFE7F
    ctx->r11 = ctx->r11 | 0XFE7F;
    // 0x80062210: ori         $t2, $t2, 0x97FF
    ctx->r10 = ctx->r10 | 0X97FF;
    // 0x80062214: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80062218: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
L_8006221C:
    // 0x8006221C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80062220: addiu       $a1, $a1, -0x31D8
    ctx->r5 = ADD32(ctx->r5, -0X31D8);
    // 0x80062224: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80062228: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8006222C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80062230: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80062234: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80062238: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006223C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80062240: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80062244: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80062248: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8006224C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062254: jr          $ra
    // 0x80062258: nop

    return;
    // 0x80062258: nop

;}
RECOMP_FUNC void func_8006225C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006225C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80062260: addiu       $t3, $t3, 0x5904
    ctx->r11 = ADD32(ctx->r11, 0X5904);
    // 0x80062264: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x80062268: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8006226C: beq         $a0, $t6, L_80062338
    if (ctx->r4 == ctx->r14) {
        // 0x80062270: addiu       $t4, $t4, -0x31D8
        ctx->r12 = ADD32(ctx->r12, -0X31D8);
            goto L_80062338;
    }
    // 0x80062270: addiu       $t4, $t4, -0x31D8
    ctx->r12 = ADD32(ctx->r12, -0X31D8);
    // 0x80062274: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80062278: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8006227C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80062280: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80062284: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x80062288: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006228C: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80062290: lui         $t5, 0xE800
    ctx->r13 = S32(0XE800 << 16);
    // 0x80062294: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80062298: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8006229C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800622A0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800622A4: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x800622A8: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x800622AC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800622B0: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800622B4: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x800622B8: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x800622BC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800622C0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800622C4: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x800622C8: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x800622CC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800622D0: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x800622D4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800622D8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800622DC: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x800622E0: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x800622E4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800622E8: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800622EC: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x800622F0: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x800622F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800622F8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800622FC: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80062300: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80062304: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80062308: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8006230C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80062310: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80062314: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80062318: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8006231C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80062320: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80062324: ori         $t7, $t7, 0xE02
    ctx->r15 = ctx->r15 | 0XE02;
    // 0x80062328: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x8006232C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80062330: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80062334: sw          $a0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r4;
L_80062338:
    // 0x80062338: jr          $ra
    // 0x8006233C: nop

    return;
    // 0x8006233C: nop

;}
RECOMP_FUNC void func_80062340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062340: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80062344: addiu       $v1, $v1, -0x31D8
    ctx->r3 = ADD32(ctx->r3, -0X31D8);
    // 0x80062348: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006234C: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80062350: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80062354: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80062358: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8006235C: addiu       $t4, $t4, 0x5900
    ctx->r12 = ADD32(ctx->r12, 0X5900);
    // 0x80062360: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80062364: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80062368: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8006236C: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80062370: beq         $t3, $t8, L_800623E0
    if (ctx->r11 == ctx->r24) {
        // 0x80062374: lui         $at, 0xFF
        ctx->r1 = S32(0XFF << 16);
            goto L_800623E0;
    }
    // 0x80062374: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80062378: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006237C: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x80062380: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80062384: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80062388: ori         $t5, $t5, 0x1402
    ctx->r13 = ctx->r13 | 0X1402;
    // 0x8006238C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80062390: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80062394: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80062398: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x8006239C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800623A0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800623A4: lui         $t8, 0xFFFD
    ctx->r24 = S32(0XFFFD << 16);
    // 0x800623A8: ori         $t8, $t8, 0xF6FB
    ctx->r24 = ctx->r24 | 0XF6FB;
    // 0x800623AC: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x800623B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800623B4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800623B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800623BC: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x800623C0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800623C4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800623C8: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x800623CC: ori         $t5, $t5, 0x31D
    ctx->r13 = ctx->r13 | 0X31D;
    // 0x800623D0: ori         $t6, $t6, 0x4240
    ctx->r14 = ctx->r14 | 0X4240;
    // 0x800623D4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800623D8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800623DC: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_800623E0:
    // 0x800623E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800623E4: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x800623E8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800623EC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800623F0: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800623F4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800623F8: and         $t9, $t0, $at
    ctx->r25 = ctx->r8 & ctx->r1;
    // 0x800623FC: srl         $t6, $t9, 16
    ctx->r14 = S32(U32(ctx->r25) >> 16);
    // 0x80062400: andi        $t8, $t0, 0xFF00
    ctx->r24 = ctx->r8 & 0XFF00;
    // 0x80062404: srl         $t9, $t8, 8
    ctx->r25 = S32(U32(ctx->r24) >> 8);
    // 0x80062408: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x8006240C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80062410: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80062414: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80062418: andi        $t5, $t0, 0xFF
    ctx->r13 = ctx->r8 & 0XFF;
    // 0x8006241C: sll         $t7, $t5, 8
    ctx->r15 = S32(ctx->r13 << 8);
    // 0x80062420: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80062424: and         $t9, $t0, $at
    ctx->r25 = ctx->r8 & ctx->r1;
    // 0x80062428: srl         $t5, $t9, 24
    ctx->r13 = S32(U32(ctx->r25) >> 24);
    // 0x8006242C: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80062430: andi        $t8, $t5, 0xFF
    ctx->r24 = ctx->r13 & 0XFF;
    // 0x80062434: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80062438: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8006243C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80062440: addu        $t5, $a0, $a2
    ctx->r13 = ADD32(ctx->r4, ctx->r6);
    // 0x80062444: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80062448: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006244C: andi        $t6, $t5, 0x3FF
    ctx->r14 = ctx->r13 & 0X3FF;
    // 0x80062450: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80062454: addu        $t9, $a1, $a3
    ctx->r25 = ADD32(ctx->r5, ctx->r7);
    // 0x80062458: andi        $t5, $t9, 0x3FF
    ctx->r13 = ctx->r25 & 0X3FF;
    // 0x8006245C: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80062460: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x80062464: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80062468: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8006246C: andi        $t7, $a1, 0x3FF
    ctx->r15 = ctx->r5 & 0X3FF;
    // 0x80062470: andi        $t9, $a0, 0x3FF
    ctx->r25 = ctx->r4 & 0X3FF;
    // 0x80062474: sll         $t5, $t9, 14
    ctx->r13 = S32(ctx->r25 << 14);
    // 0x80062478: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8006247C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80062480: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x80062484: jr          $ra
    // 0x80062488: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    return;
    // 0x80062488: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_8006248C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006248C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80062490: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80062494: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80062498: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x8006249C: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800624A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800624A4: addiu       $s1, $s1, 0x4858
    ctx->r17 = ADD32(ctx->r17, 0X4858);
    // 0x800624A8: addiu       $s0, $s0, 0x4810
    ctx->r16 = ADD32(ctx->r16, 0X4810);
L_800624AC:
    // 0x800624AC: addiu       $a0, $zero, 0x17C
    ctx->r4 = ADD32(0, 0X17C);
    // 0x800624B0: jal         0x80000688
    // 0x800624B4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80000688(rdram, ctx);
        goto after_0;
    // 0x800624B4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x800624B8: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x800624BC: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x800624C0: jal         0x80000688
    // 0x800624C4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80000688(rdram, ctx);
        goto after_1;
    // 0x800624C4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
    // 0x800624C8: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x800624CC: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800624D0: jal         0x80000688
    // 0x800624D4: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    func_80000688(rdram, ctx);
        goto after_2;
    // 0x800624D4: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_2:
    // 0x800624D8: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x800624DC: bne         $s0, $s1, L_800624AC
    if (ctx->r16 != ctx->r17) {
        // 0x800624E0: sh          $v0, -0x2($s0)
        MEM_H(-0X2, ctx->r16) = ctx->r2;
            goto L_800624AC;
    }
    // 0x800624E0: sh          $v0, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r2;
    // 0x800624E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800624E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800624EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800624F0: jr          $ra
    // 0x800624F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800624F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800624F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800624F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800624FC: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80062500: lw          $t6, 0x5908($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5908);
    // 0x80062504: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80062508: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006250C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80062510: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80062514: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80062518: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006251C: bne         $t6, $zero, L_80062534
    if (ctx->r14 != 0) {
        // 0x80062520: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_80062534;
    }
    // 0x80062520: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80062524: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80062528: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8006252C: jal         0x8006248C
    // 0x80062530: sw          $t7, 0x5908($at)
    MEM_W(0X5908, ctx->r1) = ctx->r15;
    func_8006248C(rdram, ctx);
        goto after_0;
    // 0x80062530: sw          $t7, 0x5908($at)
    MEM_W(0X5908, ctx->r1) = ctx->r15;
    after_0:
L_80062534:
    // 0x80062534: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x80062538: addiu       $s2, $s2, -0x31D8
    ctx->r18 = ADD32(ctx->r18, -0X31D8);
    // 0x8006253C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80062540: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80062544: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80062548: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8006254C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80062550: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80062554: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80062558: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8006255C: sw          $t0, 0x5900($at)
    MEM_W(0X5900, ctx->r1) = ctx->r8;
    // 0x80062560: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80062564: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x80062568: addiu       $t1, $a0, 0x8
    ctx->r9 = ADD32(ctx->r4, 0X8);
    // 0x8006256C: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x80062570: ori         $t2, $t2, 0x1402
    ctx->r10 = ctx->r10 | 0X1402;
    // 0x80062574: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80062578: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8006257C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80062580: lui         $t4, 0xFCFF
    ctx->r12 = S32(0XFCFF << 16);
    // 0x80062584: addiu       $t3, $a0, 0x8
    ctx->r11 = ADD32(ctx->r4, 0X8);
    // 0x80062588: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x8006258C: lui         $t5, 0xFFFD
    ctx->r13 = S32(0XFFFD << 16);
    // 0x80062590: ori         $t5, $t5, 0xF6FB
    ctx->r13 = ctx->r13 | 0XF6FB;
    // 0x80062594: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x80062598: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8006259C: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x800625A0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800625A4: lui         $t8, 0xF0A
    ctx->r24 = S32(0XF0A << 16);
    // 0x800625A8: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x800625AC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800625B0: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x800625B4: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x800625B8: ori         $t8, $t8, 0x4000
    ctx->r24 = ctx->r24 | 0X4000;
    // 0x800625BC: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800625C0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800625C4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800625C8: lui         $t1, 0xA28
    ctx->r9 = S32(0XA28 << 16);
    // 0x800625CC: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x800625D0: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800625D4: ori         $t1, $t1, 0xDCFF
    ctx->r9 = ctx->r9 | 0XDCFF;
    // 0x800625D8: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x800625DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800625E0: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x800625E4: lui         $s3, 0xF600
    ctx->r19 = S32(0XF600 << 16);
    // 0x800625E8: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800625EC: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
L_800625F0:
    // 0x800625F0: addiu       $a0, $zero, 0x188
    ctx->r4 = ADD32(0, 0X188);
    // 0x800625F4: jal         0x80000688
    // 0x800625F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80000688(rdram, ctx);
        goto after_1;
    // 0x800625F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x800625FC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80062600: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    // 0x80062604: jal         0x80000688
    // 0x80062608: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80000688(rdram, ctx);
        goto after_2;
    // 0x80062608: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8006260C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80062610: addiu       $t3, $s1, 0x1
    ctx->r11 = ADD32(ctx->r17, 0X1);
    // 0x80062614: andi        $t4, $t3, 0x3FF
    ctx->r12 = ctx->r11 & 0X3FF;
    // 0x80062618: sll         $t5, $t4, 14
    ctx->r13 = S32(ctx->r12 << 14);
    // 0x8006261C: addiu       $t7, $v0, 0xE
    ctx->r15 = ADD32(ctx->r2, 0XE);
    // 0x80062620: addiu       $t2, $a0, 0x8
    ctx->r10 = ADD32(ctx->r4, 0X8);
    // 0x80062624: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x80062628: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8006262C: or          $t6, $t5, $s3
    ctx->r14 = ctx->r13 | ctx->r19;
    // 0x80062630: andi        $t3, $v0, 0x3FF
    ctx->r11 = ctx->r2 & 0X3FF;
    // 0x80062634: andi        $t1, $s1, 0x3FF
    ctx->r9 = ctx->r17 & 0X3FF;
    // 0x80062638: sll         $t2, $t1, 14
    ctx->r10 = S32(ctx->r9 << 14);
    // 0x8006263C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80062640: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80062644: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80062648: or          $t0, $t6, $t9
    ctx->r8 = ctx->r14 | ctx->r25;
    // 0x8006264C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80062650: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x80062654: bne         $s0, $s4, L_800625F0
    if (ctx->r16 != ctx->r20) {
        // 0x80062658: sw          $t0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r8;
            goto L_800625F0;
    }
    // 0x80062658: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8006265C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80062660: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062664: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80062668: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006266C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80062670: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80062674: jr          $ra
    // 0x80062678: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80062678: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006267C: nop

;}
RECOMP_FUNC void func_80062680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062680: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80062684: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80062688: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006268C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80062690: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80062694: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80062698: subu        $a1, $a3, $a2
    ctx->r5 = SUB32(ctx->r7, ctx->r6);
    // 0x8006269C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800626A0: jal         0x8006B290
    // 0x800626A4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x800626A4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x800626A8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800626AC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800626B0: jal         0x8006B520
    // 0x800626B4: subu        $a1, $t6, $a0
    ctx->r5 = SUB32(ctx->r14, ctx->r4);
    osInvalICache_recomp(rdram, ctx);
        goto after_1;
    // 0x800626B4: subu        $a1, $t6, $a0
    ctx->r5 = SUB32(ctx->r14, ctx->r4);
    after_1:
    // 0x800626B8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800626BC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800626C0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800626C4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800626C8: addiu       $t0, $t0, 0x3848
    ctx->r8 = ADD32(ctx->r8, 0X3848);
    // 0x800626CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800626D0: subu        $t9, $t8, $a3
    ctx->r25 = SUB32(ctx->r24, ctx->r7);
    // 0x800626D4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800626D8: addiu       $a0, $a0, 0x3860
    ctx->r4 = ADD32(ctx->r4, 0X3860);
    // 0x800626DC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800626E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800626E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800626E8: jal         0x8006B340
    // 0x800626EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    osPiStartDma_recomp(rdram, ctx);
        goto after_2;
    // 0x800626EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x800626F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800626F4: addiu       $a0, $a0, 0x3848
    ctx->r4 = ADD32(ctx->r4, 0X3848);
    // 0x800626F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800626FC: jal         0x80069CF0
    // 0x80062700: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80062700: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80062704: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80062708: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8006270C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80062710: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80062714: subu        $v0, $t3, $t4
    ctx->r2 = SUB32(ctx->r11, ctx->r12);
    // 0x80062718: sltu        $at, $v0, $s0
    ctx->r1 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x8006271C: beq         $at, $zero, L_80062730
    if (ctx->r1 == 0) {
        // 0x80062720: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80062730;
    }
L_80062720:
    // 0x80062720: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80062724: sltu        $at, $v0, $s0
    ctx->r1 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x80062728: bne         $at, $zero, L_80062720
    if (ctx->r1 != 0) {
        // 0x8006272C: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_80062720;
    }
    // 0x8006272C: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
L_80062730:
    // 0x80062730: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80062734: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80062738: jr          $ra
    // 0x8006273C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006273C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80062740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062740: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80062744: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80062748: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006274C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80062750: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80062754: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80062758: subu        $a1, $a3, $a2
    ctx->r5 = SUB32(ctx->r7, ctx->r6);
    // 0x8006275C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80062760: jal         0x8006B290
    // 0x80062764: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80062764: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80062768: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8006276C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80062770: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80062774: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80062778: addiu       $t9, $t9, 0x3848
    ctx->r25 = ADD32(ctx->r25, 0X3848);
    // 0x8006277C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80062780: subu        $t8, $t7, $a3
    ctx->r24 = SUB32(ctx->r15, ctx->r7);
    // 0x80062784: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80062788: addiu       $a0, $a0, 0x3860
    ctx->r4 = ADD32(ctx->r4, 0X3860);
    // 0x8006278C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80062790: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80062794: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80062798: jal         0x8006B340
    // 0x8006279C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x8006279C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x800627A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800627A4: addiu       $a0, $a0, 0x3848
    ctx->r4 = ADD32(ctx->r4, 0X3848);
    // 0x800627A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800627AC: jal         0x80069CF0
    // 0x800627B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800627B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800627B4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800627B8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800627BC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800627C0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800627C4: subu        $v0, $t2, $t3
    ctx->r2 = SUB32(ctx->r10, ctx->r11);
    // 0x800627C8: sltu        $at, $v0, $s0
    ctx->r1 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x800627CC: beq         $at, $zero, L_800627E0
    if (ctx->r1 == 0) {
        // 0x800627D0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800627E0;
    }
L_800627D0:
    // 0x800627D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800627D4: sltu        $at, $v0, $s0
    ctx->r1 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x800627D8: bne         $at, $zero, L_800627D0
    if (ctx->r1 != 0) {
        // 0x800627DC: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_800627D0;
    }
    // 0x800627DC: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
L_800627E0:
    // 0x800627E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800627E4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800627E8: jr          $ra
    // 0x800627EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800627EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800627F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800627F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800627F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800627F8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800627FC: lui         $a2, 0x5
    ctx->r6 = S32(0X5 << 16);
    // 0x80062800: ori         $a2, $a2, 0xDC00
    ctx->r6 = ctx->r6 | 0XDC00;
    // 0x80062804: addiu       $a0, $a0, 0x70C0
    ctx->r4 = ADD32(ctx->r4, 0X70C0);
    // 0x80062808: jal         0x80061938
    // 0x8006280C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80061938(rdram, ctx);
        goto after_0;
    // 0x8006280C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80062810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062818: jr          $ra
    // 0x8006281C: nop

    return;
    // 0x8006281C: nop

;}
RECOMP_FUNC void func_80062820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062828: jal         0x800627F0
    // 0x8006282C: nop

    func_800627F0(rdram, ctx);
        goto after_0;
    // 0x8006282C: nop

    after_0:
    // 0x80062830: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80062834: jal         0x8006AE40
    // 0x80062838: addiu       $a0, $a0, 0x5EC0
    ctx->r4 = ADD32(ctx->r4, 0X5EC0);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x80062838: addiu       $a0, $a0, 0x5EC0
    ctx->r4 = ADD32(ctx->r4, 0X5EC0);
    after_1:
    // 0x8006283C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062844: jr          $ra
    // 0x80062848: nop

    return;
    // 0x80062848: nop

;}
RECOMP_FUNC void func_8006284C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006284C: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x80062850: addiu       $t2, $t2, -0x31DC
    ctx->r10 = ADD32(ctx->r10, -0X31DC);
    // 0x80062854: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80062858: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8006285C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80062860: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80062864: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80062868: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006286C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80062870: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80062874: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80062878: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006287C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80062880: addiu       $t8, $t8, 0x4860
    ctx->r24 = ADD32(ctx->r24, 0X4860);
    // 0x80062884: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80062888: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8006288C: addiu       $t6, $t9, 0x120
    ctx->r14 = ADD32(ctx->r25, 0X120);
    // 0x80062890: addiu       $v1, $v1, -0x31D8
    ctx->r3 = ADD32(ctx->r3, -0X31D8);
    // 0x80062894: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80062898: addiu       $t1, $t1, -0x31E0
    ctx->r9 = ADD32(ctx->r9, -0X31E0);
    // FALLTHROUGH FIX: func_8006284C falls through to func_8006289C
    func_8006289C(rdram, ctx);
;}
RECOMP_FUNC void func_8006289C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006289C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800628A0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800628A4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800628A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800628AC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800628B0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800628B4: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x800628B8: ori         $t8, $t8, 0x6
    ctx->r24 = ctx->r24 | 0X6;
    // 0x800628BC: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800628C0: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800628C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800628C8: lui         $t5, 0xBC00
    ctx->r13 = S32(0XBC00 << 16);
    // 0x800628CC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800628D0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800628D4: ori         $t5, $t5, 0x406
    ctx->r13 = ctx->r13 | 0X406;
    // 0x800628D8: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800628DC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800628E0: lw          $t6, 0x27E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X27E0);
    // 0x800628E4: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800628E8: addu        $t7, $t6, $t3
    ctx->r15 = ADD32(ctx->r14, ctx->r11);
    // 0x800628EC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800628F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800628F4: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800628F8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800628FC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80062900: ori         $t9, $t9, 0x806
    ctx->r25 = ctx->r25 | 0X806;
    // 0x80062904: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80062908: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x8006290C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80062910: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80062914: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80062918: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8006291C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80062920: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80062924: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80062928: sll         $t6, $t6, 9
    ctx->r14 = S32(ctx->r14 << 9);
    // 0x8006292C: addu        $t7, $t6, $t3
    ctx->r15 = ADD32(ctx->r14, ctx->r11);
    // 0x80062930: addiu       $t8, $t8, 0x70C0
    ctx->r24 = ADD32(ctx->r24, 0X70C0);
    // 0x80062934: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80062938: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8006293C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80062940: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x80062944: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80062948: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8006294C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80062950: addiu       $t6, $t6, 0x38
    ctx->r14 = ADD32(ctx->r14, 0X38);
    // 0x80062954: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80062958: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8006295C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80062960: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x80062964: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80062968: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006296C: addiu       $t8, $t8, 0x10
    ctx->r24 = ADD32(ctx->r24, 0X10);
    // 0x80062970: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80062974: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80062978: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8006297C: jal         0x8006A690
    // 0x80062980: sw          $zero, -0x31D4($at)
    MEM_W(-0X31D4, ctx->r1) = 0;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x80062980: sw          $zero, -0x31D4($at)
    MEM_W(-0X31D4, ctx->r1) = 0;
    after_0:
    // 0x80062984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062988: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8006298C: sw          $v0, -0x31D0($at)
    MEM_W(-0X31D0, ctx->r1) = ctx->r2;
    // 0x80062990: sw          $v1, -0x31CC($at)
    MEM_W(-0X31CC, ctx->r1) = ctx->r3;
    // 0x80062994: jr          $ra
    // 0x80062998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80062998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006299C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006299C: jr          $ra
    // 0x800629A0: nop

    return;
    // 0x800629A0: nop

;}
RECOMP_FUNC void func_800629A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800629A4: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800629A8: addiu       $a2, $a2, -0x31D8
    ctx->r6 = ADD32(ctx->r6, -0X31D8);
    // 0x800629AC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // FALLTHROUGH FIX: func_800629A4 falls through to func_800629B0
    func_800629B0(rdram, ctx);
;}
RECOMP_FUNC void func_800629B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800629B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800629B4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800629B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800629BC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800629C0: lui         $t7, 0xE900
    ctx->r15 = S32(0XE900 << 16);
    // 0x800629C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800629C8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800629CC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800629D0: lui         $t9, 0xB800
    ctx->r25 = S32(0XB800 << 16);
    // 0x800629D4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800629D8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800629DC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800629E0: jal         0x8006AA80
    // 0x800629E4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x800629E4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x800629E8: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800629EC: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800629F0: lw          $t1, -0x31C4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X31C4);
    // 0x800629F4: lw          $t0, -0x31C8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X31C8);
    // 0x800629F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800629FC: sw          $t1, 0x5914($at)
    MEM_W(0X5914, ctx->r1) = ctx->r9;
    // 0x80062A00: jal         0x8006A690
    // 0x80062A04: sw          $t0, 0x5910($at)
    MEM_W(0X5910, ctx->r1) = ctx->r8;
    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x80062A04: sw          $t0, 0x5910($at)
    MEM_W(0X5910, ctx->r1) = ctx->r8;
    after_1:
    // 0x80062A08: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80062A0C: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80062A10: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80062A14: lw          $a0, -0x31E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X31E0);
    // 0x80062A18: addiu       $a2, $a2, -0x31D8
    ctx->r6 = ADD32(ctx->r6, -0X31D8);
    // 0x80062A1C: sw          $v0, -0x31C8($at)
    MEM_W(-0X31C8, ctx->r1) = ctx->r2;
    // 0x80062A20: sw          $v1, -0x31C4($at)
    MEM_W(-0X31C4, ctx->r1) = ctx->r3;
    // 0x80062A24: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80062A28: jal         0x800608C0
    // 0x80062A2C: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, 0X120);
    func_800608C0(rdram, ctx);
        goto after_2;
    // 0x80062A2C: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, 0X120);
    after_2:
    // 0x80062A30: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80062A34: addiu       $v0, $v0, -0x31DC
    ctx->r2 = ADD32(ctx->r2, -0X31DC);
    // 0x80062A38: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80062A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062A40: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x80062A44: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80062A48: jr          $ra
    // 0x80062A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80062A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80062A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062A50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80062A54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80062A58: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80062A5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80062A60: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80062A64: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80062A68: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80062A6C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80062A70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80062A74: jal         0x8006B47C
    // 0x80062A78: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    strlen_recomp(rdram, ctx);
        goto after_0;
    // 0x80062A78: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80062A7C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80062A80: blez        $v0, L_80062AF4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80062A84: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80062AF4;
    }
    // 0x80062A84: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80062A88: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x80062A8C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80062A90: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80062A94: addiu       $s0, $s0, 0x5986
    ctx->r16 = ADD32(ctx->r16, 0X5986);
L_80062A98:
    // 0x80062A98: lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X0);
    // 0x80062A9C: jal         0x80061910
    // 0x80062AA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    func_80061910(rdram, ctx);
        goto after_1;
    // 0x80062AA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    after_1:
    // 0x80062AA4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80062AA8: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x80062AAC: addiu       $v1, $v1, 0x5920
    ctx->r3 = ADD32(ctx->r3, 0X5920);
    // 0x80062AB0: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
L_80062AB4:
    // 0x80062AB4: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80062AB8: nop

    // 0x80062ABC: bne         $a0, $t6, L_80062AD0
    if (ctx->r4 != ctx->r14) {
        // 0x80062AC0: nop
    
            goto L_80062AD0;
    }
    // 0x80062AC0: nop

    // 0x80062AC4: lbu         $s1, 0x1($v1)
    ctx->r17 = MEM_BU(ctx->r3, 0X1);
    // 0x80062AC8: b           L_80062AE0
    // 0x80062ACC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80062AE0;
    // 0x80062ACC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80062AD0:
    // 0x80062AD0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80062AD4: bne         $v1, $s0, L_80062AB4
    if (ctx->r3 != ctx->r16) {
        // 0x80062AD8: nop
    
            goto L_80062AB4;
    }
    // 0x80062AD8: nop

    // 0x80062ADC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80062AE0:
    // 0x80062AE0: slt         $at, $s2, $s5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80062AE4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80062AE8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80062AEC: bne         $at, $zero, L_80062A98
    if (ctx->r1 != 0) {
        // 0x80062AF0: sb          $s1, -0x1($s3)
        MEM_B(-0X1, ctx->r19) = ctx->r17;
            goto L_80062A98;
    }
    // 0x80062AF0: sb          $s1, -0x1($s3)
    MEM_B(-0X1, ctx->r19) = ctx->r17;
L_80062AF4:
    // 0x80062AF4: slti        $at, $s2, 0x10
    ctx->r1 = SIGNED(ctx->r18) < 0X10 ? 1 : 0;
    // 0x80062AF8: beq         $at, $zero, L_80062B24
    if (ctx->r1 == 0) {
        // 0x80062AFC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80062B24;
    }
    // 0x80062AFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80062B00: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80062B04: nop

    // 0x80062B08: addu        $s3, $t7, $s2
    ctx->r19 = ADD32(ctx->r15, ctx->r18);
L_80062B0C:
    // 0x80062B0C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80062B10: slti        $at, $s2, 0x10
    ctx->r1 = SIGNED(ctx->r18) < 0X10 ? 1 : 0;
    // 0x80062B14: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80062B18: bne         $at, $zero, L_80062B0C
    if (ctx->r1 != 0) {
        // 0x80062B1C: sb          $zero, -0x1($s3)
        MEM_B(-0X1, ctx->r19) = 0;
            goto L_80062B0C;
    }
    // 0x80062B1C: sb          $zero, -0x1($s3)
    MEM_B(-0X1, ctx->r19) = 0;
    // 0x80062B20: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80062B24:
    // 0x80062B24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80062B28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80062B2C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80062B30: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80062B34: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80062B38: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80062B3C: jr          $ra
    // 0x80062B40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80062B40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
