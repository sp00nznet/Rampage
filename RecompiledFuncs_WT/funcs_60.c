#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

RECOMP_FUNC void func_8005F414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F414: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005F418: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8005F41C: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8005F420: addiu       $fp, $fp, -0x489E
    ctx->r30 = ADD32(ctx->r30, -0X489E);
    // 0x8005F424: lhu         $t6, 0x0($fp)
    ctx->r14 = MEM_HU(ctx->r30, 0X0);
    // 0x8005F428: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005F42C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005F430: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8005F434: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8005F438: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8005F43C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8005F440: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8005F444: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005F448: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005F44C: beq         $t6, $at, L_8005F460
    if (ctx->r14 == ctx->r1) {
        // 0x8005F450: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8005F460;
    }
    // 0x8005F450: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005F454: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8005F458: b           L_8005F468
    // 0x8005F45C: sh          $t7, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r15;
        goto L_8005F468;
    // 0x8005F45C: sh          $t7, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r15;
L_8005F460:
    // 0x8005F460: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8005F464: sh          $t8, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r24;
L_8005F468:
    // 0x8005F468: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8005F46C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8005F470: lui         $s7, 0x800A
    ctx->r23 = S32(0X800A << 16);
    // 0x8005F474: lui         $s6, 0x800C
    ctx->r22 = S32(0X800C << 16);
    // 0x8005F478: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x8005F47C: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x8005F480: lhu         $s2, -0x488C($s2)
    ctx->r18 = MEM_HU(ctx->r18, -0X488C);
    // 0x8005F484: addiu       $s1, $s1, -0x4968
    ctx->r17 = ADD32(ctx->r17, -0X4968);
    // 0x8005F488: addiu       $s4, $s4, -0x47A8
    ctx->r20 = ADD32(ctx->r20, -0X47A8);
    // 0x8005F48C: addiu       $s5, $s5, 0x614
    ctx->r21 = ADD32(ctx->r21, 0X614);
    // 0x8005F490: addiu       $s6, $s6, -0x878
    ctx->r22 = ADD32(ctx->r22, -0X878);
    // 0x8005F494: addiu       $s7, $s7, -0x4788
    ctx->r23 = ADD32(ctx->r23, -0X4788);
    // 0x8005F498: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
L_8005F49C:
    // 0x8005F49C: sh          $zero, 0xE($s1)
    MEM_H(0XE, ctx->r17) = 0;
    // 0x8005F4A0: lhu         $t9, 0x0($fp)
    ctx->r25 = MEM_HU(ctx->r30, 0X0);
    // 0x8005F4A4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8005F4A8: bne         $s3, $t9, L_8005F4CC
    if (ctx->r19 != ctx->r25) {
        // 0x8005F4AC: or          $a1, $s7, $zero
        ctx->r5 = ctx->r23 | 0;
            goto L_8005F4CC;
    }
    // 0x8005F4AC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8005F4B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F4B4: jal         0x800303A0
    // 0x8005F4B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800303A0(rdram, ctx);
        goto after_0;
    // 0x8005F4B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x8005F4BC: lh          $v0, 0x6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X6);
    // 0x8005F4C0: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
    // 0x8005F4C4: b           L_8005F4E4
    // 0x8005F4C8: sh          $v1, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r3;
        goto L_8005F4E4;
    // 0x8005F4C8: sh          $v1, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r3;
L_8005F4CC:
    // 0x8005F4CC: jal         0x800303A0
    // 0x8005F4D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800303A0(rdram, ctx);
        goto after_1;
    // 0x8005F4D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8005F4D4: lh          $v0, 0x4($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4);
    // 0x8005F4D8: lh          $v1, 0xC($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XC);
    // 0x8005F4DC: nop

    // 0x8005F4E0: sh          $v1, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r3;
L_8005F4E4:
    // 0x8005F4E4: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x8005F4E8: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x8005F4EC: lhu         $t5, 0x32($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X32);
    // 0x8005F4F0: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8005F4F4: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x8005F4F8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8005F4FC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8005F500: andi        $t9, $s2, 0xFFFF
    ctx->r25 = ctx->r18 & 0XFFFF;
    // 0x8005F504: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8005F508: xori        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 ^ 0X10;
    // 0x8005F50C: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8005F510: sw          $t4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r12;
    // 0x8005F514: sh          $t6, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r14;
    // 0x8005F518: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x8005F51C: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x8005F520: bgtz        $t9, L_8005F49C
    if (SIGNED(ctx->r25) > 0) {
        // 0x8005F524: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_8005F49C;
    }
    // 0x8005F524: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x8005F528: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005F52C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005F530: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F534: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005F538: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005F53C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8005F540: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F544: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8005F548: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8005F54C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8005F550: jr          $ra
    // 0x8005F554: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005F554: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8005F558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F558: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // FALLTHROUGH FIX: func_8005F558 falls through to func_8005F55C
    func_8005F55C(rdram, ctx);
;}
RECOMP_FUNC void func_8005F55C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F55C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F560: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005F564: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8005F568: lhu         $a1, -0x488C($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X488C);
    // 0x8005F56C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F570: addiu       $a0, $a0, -0x4968
    ctx->r4 = ADD32(ctx->r4, -0X4968);
    // 0x8005F574: addiu       $a2, $a2, -0x878
    ctx->r6 = ADD32(ctx->r6, -0X878);
L_8005F578:
    // 0x8005F578: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005F57C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8005F580: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x8005F584: lw          $t6, 0x1C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1C);
    // 0x8005F588: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8005F58C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8005F590: andi        $t8, $a1, 0xFFFF
    ctx->r24 = ctx->r5 & 0XFFFF;
    // 0x8005F594: and         $v0, $v0, $t7
    ctx->r2 = ctx->r2 & ctx->r15;
    // 0x8005F598: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8005F59C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x8005F5A0: bgtz        $t8, L_8005F578
    if (SIGNED(ctx->r24) > 0) {
        // 0x8005F5A4: sw          $v0, 0x1C($v1)
        MEM_W(0X1C, ctx->r3) = ctx->r2;
            goto L_8005F578;
    }
    // 0x8005F5A4: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x8005F5A8: jal         0x8005FC50
    // 0x8005F5AC: nop

    func_8005FC50(rdram, ctx);
        goto after_0;
    // 0x8005F5AC: nop

    after_0:
    // 0x8005F5B0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8005F5B4: lhu         $t9, -0x489A($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X489A);
    // 0x8005F5B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005F5BC: bne         $t9, $at, L_8005F5CC
    if (ctx->r25 != ctx->r1) {
        // 0x8005F5C0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8005F5CC;
    }
    // 0x8005F5C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005F5C4: b           L_8005F5D0
    // 0x8005F5C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8005F5D0;
    // 0x8005F5C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8005F5CC:
    // 0x8005F5CC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_8005F5D0:
    // 0x8005F5D0: addiu       $a0, $a0, -0x4968
    ctx->r4 = ADD32(ctx->r4, -0X4968);
    // 0x8005F5D4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8005F5D8: jal         0x8005F674
    // 0x8005F5DC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_8005F674(rdram, ctx);
        goto after_1;
    // 0x8005F5DC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_1:
    // 0x8005F5E0: bne         $v0, $zero, L_8005F60C
    if (ctx->r2 != 0) {
        // 0x8005F5E4: lui         $a3, 0x800E
        ctx->r7 = S32(0X800E << 16);
            goto L_8005F60C;
    }
    // 0x8005F5E4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8005F5E8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8005F5EC: lhu         $t0, -0x489A($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X489A);
    // 0x8005F5F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005F5F4: bne         $t0, $at, L_8005F668
    if (ctx->r8 != ctx->r1) {
        // 0x8005F5F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005F668;
    }
    // 0x8005F5F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F5FC: jal         0x8005F814
    // 0x8005F600: nop

    func_8005F814(rdram, ctx);
        goto after_2;
    // 0x8005F600: nop

    after_2:
    // 0x8005F604: b           L_8005F668
    // 0x8005F608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005F668;
    // 0x8005F608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005F60C:
    // 0x8005F60C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005F610: lhu         $a3, -0x488C($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X488C);
    // 0x8005F614: addiu       $a0, $a0, -0x4968
    ctx->r4 = ADD32(ctx->r4, -0X4968);
L_8005F618:
    // 0x8005F618: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005F61C: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8005F620: lh          $t1, 0x20($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X20);
    // 0x8005F624: andi        $t3, $a3, 0xFFFF
    ctx->r11 = ctx->r7 & 0XFFFF;
    // 0x8005F628: addiu       $t2, $t1, 0x250
    ctx->r10 = ADD32(ctx->r9, 0X250);
    // 0x8005F62C: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x8005F630: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x8005F634: bgtz        $t3, L_8005F618
    if (SIGNED(ctx->r11) > 0) {
        // 0x8005F638: sh          $t2, 0x20($v1)
        MEM_H(0X20, ctx->r3) = ctx->r10;
            goto L_8005F618;
    }
    // 0x8005F638: sh          $t2, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r10;
    // 0x8005F63C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005F640: addiu       $v0, $v0, -0x489E
    ctx->r2 = ADD32(ctx->r2, -0X489E);
    // 0x8005F644: lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X0);
    // 0x8005F648: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8005F64C: bne         $t4, $at, L_8005F660
    if (ctx->r12 != ctx->r1) {
        // 0x8005F650: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8005F660;
    }
    // 0x8005F650: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005F654: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8005F658: b           L_8005F664
    // 0x8005F65C: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
        goto L_8005F664;
    // 0x8005F65C: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
L_8005F660:
    // 0x8005F660: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
L_8005F664:
    // 0x8005F664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005F668:
    // 0x8005F668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F66C: jr          $ra
    // 0x8005F670: nop

    return;
    // 0x8005F670: nop

;}
RECOMP_FUNC void func_8005F674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F678: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F67C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005F680: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8005F684: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8005F688: lhu         $t8, 0x7C($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X7C);
    // 0x8005F68C: lhu         $v0, 0xE($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XE);
    // 0x8005F690: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x8005F694: beq         $t9, $zero, L_8005F6BC
    if (ctx->r25 == 0) {
        // 0x8005F698: andi        $t6, $a3, 0xFFFF
        ctx->r14 = ctx->r7 & 0XFFFF;
            goto L_8005F6BC;
    }
    // 0x8005F698: andi        $t6, $a3, 0xFFFF
    ctx->r14 = ctx->r7 & 0XFFFF;
    // 0x8005F69C: beq         $v0, $zero, L_8005F6D4
    if (ctx->r2 == 0) {
        // 0x8005F6A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005F6D4;
    }
    // 0x8005F6A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005F6A4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8005F6A8: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    // 0x8005F6AC: jal         0x8005F6E4
    // 0x8005F6B0: andi        $a2, $t6, 0xFFFF
    ctx->r6 = ctx->r14 & 0XFFFF;
    func_8005F6E4(rdram, ctx);
        goto after_0;
    // 0x8005F6B0: andi        $a2, $t6, 0xFFFF
    ctx->r6 = ctx->r14 & 0XFFFF;
    after_0:
    // 0x8005F6B4: b           L_8005F6D8
    // 0x8005F6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005F6D8;
    // 0x8005F6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005F6BC:
    // 0x8005F6BC: bne         $v0, $zero, L_8005F6D4
    if (ctx->r2 != 0) {
        // 0x8005F6C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005F6D4;
    }
    // 0x8005F6C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005F6C4: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8005F6C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005F6CC: sh          $t0, 0xE($t1)
    MEM_H(0XE, ctx->r9) = ctx->r8;
    // 0x8005F6D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005F6D4:
    // 0x8005F6D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005F6D8:
    // 0x8005F6D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F6DC: jr          $ra
    // 0x8005F6E0: nop

    return;
    // 0x8005F6E0: nop

;}
RECOMP_FUNC void func_8005F6E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F6E4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8005F6E8: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x8005F6EC: lw          $v0, 0x614($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X614);
    // 0x8005F6F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F6F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005F6F8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8005F6FC: beq         $t8, $at, L_8005F74C
    if (ctx->r24 == ctx->r1) {
        // 0x8005F700: sll         $a3, $a1, 16
        ctx->r7 = S32(ctx->r5 << 16);
            goto L_8005F74C;
    }
    // 0x8005F700: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x8005F704: lui         $at, 0x190
    ctx->r1 = S32(0X190 << 16);
    // 0x8005F708: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8005F70C: lw          $t9, -0x878($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X878);
    // 0x8005F710: addu        $v1, $a3, $at
    ctx->r3 = ADD32(ctx->r7, ctx->r1);
    // 0x8005F714: lw          $t0, 0x1C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1C);
    // 0x8005F718: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005F71C: and         $v0, $v0, $t9
    ctx->r2 = ctx->r2 & ctx->r25;
    // 0x8005F720: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005F724: bne         $at, $zero, L_8005F740
    if (ctx->r1 != 0) {
        // 0x8005F728: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8005F740;
    }
    // 0x8005F728: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005F72C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005F730: addiu       $v1, $v1, -0x4500
    ctx->r3 = ADD32(ctx->r3, -0X4500);
    // 0x8005F734: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005F738: b           L_8005F794
    // 0x8005F73C: sh          $t1, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r9;
        goto L_8005F794;
    // 0x8005F73C: sh          $t1, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r9;
L_8005F740:
    // 0x8005F740: addiu       $v1, $v1, -0x4500
    ctx->r3 = ADD32(ctx->r3, -0X4500);
    // 0x8005F744: b           L_8005F794
    // 0x8005F748: sh          $zero, 0x78($v1)
    MEM_H(0X78, ctx->r3) = 0;
        goto L_8005F794;
    // 0x8005F748: sh          $zero, 0x78($v1)
    MEM_H(0X78, ctx->r3) = 0;
L_8005F74C:
    // 0x8005F74C: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x8005F750: bgtz        $v0, L_8005F764
    if (SIGNED(ctx->r2) > 0) {
        // 0x8005F754: lui         $t2, 0x800C
        ctx->r10 = S32(0X800C << 16);
            goto L_8005F764;
    }
    // 0x8005F754: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8005F758: lw          $t2, -0x878($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X878);
    // 0x8005F75C: nop

    // 0x8005F760: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
L_8005F764:
    // 0x8005F764: lw          $t3, 0x1C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1C);
    // 0x8005F768: nop

    // 0x8005F76C: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8005F770: bne         $at, $zero, L_8005F788
    if (ctx->r1 != 0) {
        // 0x8005F774: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8005F788;
    }
    // 0x8005F774: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005F778: addiu       $v1, $v1, -0x4500
    ctx->r3 = ADD32(ctx->r3, -0X4500);
    // 0x8005F77C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005F780: b           L_8005F794
    // 0x8005F784: sh          $t4, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r12;
        goto L_8005F794;
    // 0x8005F784: sh          $t4, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r12;
L_8005F788:
    // 0x8005F788: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005F78C: addiu       $v1, $v1, -0x4500
    ctx->r3 = ADD32(ctx->r3, -0X4500);
    // 0x8005F790: sh          $zero, 0x78($v1)
    MEM_H(0X78, ctx->r3) = 0;
L_8005F794:
    // 0x8005F794: lhu         $v0, 0x78($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X78);
    // 0x8005F798: jr          $ra
    // 0x8005F79C: nop

    return;
    // 0x8005F79C: nop

;}
RECOMP_FUNC void func_8005F7A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F7A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005F7A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005F7A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005F7AC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8005F7B0: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8005F7B4: lhu         $s0, -0x488C($s0)
    ctx->r16 = MEM_HU(ctx->r16, -0X488C);
    // 0x8005F7B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005F7BC: addiu       $s1, $s1, -0x4968
    ctx->r17 = ADD32(ctx->r17, -0X4968);
L_8005F7C0:
    // 0x8005F7C0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005F7C4: nop

    // 0x8005F7C8: beq         $a0, $zero, L_8005F7D8
    if (ctx->r4 == 0) {
        // 0x8005F7CC: nop
    
            goto L_8005F7D8;
    }
    // 0x8005F7CC: nop

    // 0x8005F7D0: jal         0x8002F750
    // 0x8005F7D4: nop

    func_8002F750(rdram, ctx);
        goto after_0;
    // 0x8005F7D4: nop

    after_0:
L_8005F7D8:
    // 0x8005F7D8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8005F7DC: andi        $t6, $s0, 0xFFFF
    ctx->r14 = ctx->r16 & 0XFFFF;
    // 0x8005F7E0: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8005F7E4: bgtz        $t6, L_8005F7C0
    if (SIGNED(ctx->r14) > 0) {
        // 0x8005F7E8: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_8005F7C0;
    }
    // 0x8005F7E8: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x8005F7EC: jal         0x8005EF90
    // 0x8005F7F0: nop

    func_8005EF90(rdram, ctx);
        goto after_1;
    // 0x8005F7F0: nop

    after_1:
    // 0x8005F7F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F7F8: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x8005F7FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F800: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005F804: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005F808: sh          $t7, -0x489E($at)
    MEM_H(-0X489E, ctx->r1) = ctx->r15;
    // 0x8005F80C: jr          $ra
    // 0x8005F810: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005F810: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005F814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F814: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005F818: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8005F81C: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8005F820: addiu       $s3, $s3, -0x4500
    ctx->r19 = ADD32(ctx->r19, -0X4500);
    // 0x8005F824: lw          $t6, 0x20($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X20);
    // 0x8005F828: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005F82C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005F830: addiu       $s1, $v0, -0x4968
    ctx->r17 = ADD32(ctx->r2, -0X4968);
    // 0x8005F834: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005F838: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8005F83C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8005F840: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8005F844: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005F848: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8005F84C: lw          $t7, 0x10($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X10);
    // 0x8005F850: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005F854: bne         $t7, $zero, L_8005F944
    if (ctx->r15 != 0) {
        // 0x8005F858: lui         $a0, 0x800C
        ctx->r4 = S32(0X800C << 16);
            goto L_8005F944;
    }
    // 0x8005F858: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8005F85C: lw          $v0, -0x4968($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4968);
    // 0x8005F860: lw          $a0, 0x614($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X614);
    // 0x8005F864: lw          $v1, 0x1C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C);
    // 0x8005F868: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8005F86C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005F870: beq         $at, $zero, L_8005F888
    if (ctx->r1 == 0) {
        // 0x8005F874: lui         $at, 0x82
        ctx->r1 = S32(0X82 << 16);
            goto L_8005F888;
    }
    // 0x8005F874: lui         $at, 0x82
    ctx->r1 = S32(0X82 << 16);
    // 0x8005F878: lw          $t8, -0x878($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X878);
    // 0x8005F87C: nop

    // 0x8005F880: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x8005F884: lui         $at, 0x82
    ctx->r1 = S32(0X82 << 16);
L_8005F888:
    // 0x8005F888: addu        $v0, $a0, $at
    ctx->r2 = ADD32(ctx->r4, ctx->r1);
    // 0x8005F88C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005F890: bne         $at, $zero, L_8005F944
    if (ctx->r1 != 0) {
        // 0x8005F894: lui         $v0, 0x800C
        ctx->r2 = S32(0X800C << 16);
            goto L_8005F944;
    }
    // 0x8005F894: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8005F898: lw          $v0, -0x878($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X878);
    // 0x8005F89C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8005F8A0: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8005F8A4: addu        $v0, $t9, $a0
    ctx->r2 = ADD32(ctx->r25, ctx->r4);
    // 0x8005F8A8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005F8AC: bne         $at, $zero, L_8005F948
    if (ctx->r1 != 0) {
        // 0x8005F8B0: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_8005F948;
    }
    // 0x8005F8B0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8005F8B4: lhu         $s2, -0x488C($s2)
    ctx->r18 = MEM_HU(ctx->r18, -0X488C);
    // 0x8005F8B8: jal         0x80039D18
    // 0x8005F8BC: nop

    func_80039D18(rdram, ctx);
        goto after_0;
    // 0x8005F8BC: nop

    after_0:
    // 0x8005F8C0: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x8005F8C4: sw          $v0, 0x3C($s3)
    MEM_W(0X3C, ctx->r19) = ctx->r2;
    // 0x8005F8C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005F8CC: addiu       $s4, $s4, -0x4960
    ctx->r20 = ADD32(ctx->r20, -0X4960);
    // 0x8005F8D0: ori         $s5, $zero, 0x9000
    ctx->r21 = 0 | 0X9000;
L_8005F8D4:
    // 0x8005F8D4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005F8D8: nop

    // 0x8005F8DC: lw          $t0, 0x1C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1C);
    // 0x8005F8E0: nop

    // 0x8005F8E4: sw          $t0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r8;
    // 0x8005F8E8: lw          $t1, 0x20($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X20);
    // 0x8005F8EC: sw          $s4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r20;
    // 0x8005F8F0: sw          $t1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r9;
    // 0x8005F8F4: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x8005F8F8: nop

    // 0x8005F8FC: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8005F900: lhu         $t3, 0x88($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X88);
    // 0x8005F904: jal         0x8002EC64
    // 0x8005F908: sw          $t3, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r11;
    func_8002EC64(rdram, ctx);
        goto after_1;
    // 0x8005F908: sw          $t3, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r11;
    after_1:
    // 0x8005F90C: sw          $v0, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r2;
    // 0x8005F910: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x8005F914: lw          $t6, 0x20($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X20);
    // 0x8005F918: lw          $t5, 0x14($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X14);
    // 0x8005F91C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8005F920: sw          $t5, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r13;
    // 0x8005F924: lw          $t7, 0x20($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X20);
    // 0x8005F928: andi        $t8, $s2, 0xFFFF
    ctx->r24 = ctx->r18 & 0XFFFF;
    // 0x8005F92C: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x8005F930: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x8005F934: bgtz        $t8, L_8005F8D4
    if (SIGNED(ctx->r24) > 0) {
        // 0x8005F938: sw          $s5, 0x90($t7)
        MEM_W(0X90, ctx->r15) = ctx->r21;
            goto L_8005F8D4;
    }
    // 0x8005F938: sw          $s5, 0x90($t7)
    MEM_W(0X90, ctx->r15) = ctx->r21;
    // 0x8005F93C: jal         0x8005F970
    // 0x8005F940: nop

    func_8005F970(rdram, ctx);
        goto after_2;
    // 0x8005F940: nop

    after_2:
L_8005F944:
    // 0x8005F944: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8005F948:
    // 0x8005F948: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F94C: sw          $t9, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r25;
    // 0x8005F950: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8005F954: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005F958: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005F95C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F960: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8005F964: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8005F968: jr          $ra
    // 0x8005F96C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005F96C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005F970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F970: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005F974: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005F978: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8005F97C: addiu       $s0, $s0, -0x4500
    ctx->r16 = ADD32(ctx->r16, -0X4500);
    // 0x8005F980: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x8005F984: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005F988: jal         0x80039D18
    // 0x8005F98C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80039D18(rdram, ctx);
        goto after_0;
    // 0x8005F98C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x8005F990: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8005F994: addiu       $a0, $a0, -0x4768
    ctx->r4 = ADD32(ctx->r4, -0X4768);
    // 0x8005F998: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x8005F99C: sw          $a0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r4;
    // 0x8005F9A0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005F9A4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8005F9A8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005F9AC: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8005F9B0: lw          $t0, -0x878($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X878);
    // 0x8005F9B4: lw          $t8, 0x614($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X614);
    // 0x8005F9B8: lhu         $t4, 0x4($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X4);
    // 0x8005F9BC: lui         $at, 0x1D6
    ctx->r1 = S32(0X1D6 << 16);
    // 0x8005F9C0: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x8005F9C4: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x8005F9C8: addiu       $t3, $zero, 0x4000
    ctx->r11 = ADD32(0, 0X4000);
    // 0x8005F9CC: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x8005F9D0: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x8005F9D4: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x8005F9D8: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
    // 0x8005F9DC: sw          $t3, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r11;
    // 0x8005F9E0: jal         0x8002EC64
    // 0x8005F9E4: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    func_8002EC64(rdram, ctx);
        goto after_1;
    // 0x8005F9E4: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    after_1:
    // 0x8005F9E8: beq         $v0, $zero, L_8005FA20
    if (ctx->r2 == 0) {
        // 0x8005F9EC: sw          $v0, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->r2;
            goto L_8005FA20;
    }
    // 0x8005F9EC: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x8005F9F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005F9F4: addiu       $a0, $a0, -0x4910
    ctx->r4 = ADD32(ctx->r4, -0X4910);
    // 0x8005F9F8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8005F9FC: sw          $a0, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r4;
    // 0x8005FA00: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x8005FA04: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x8005FA08: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x8005FA0C: jal         0x8005FA38
    // 0x8005FA10: sw          $t6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r14;
    func_8005FA38(rdram, ctx);
        goto after_2;
    // 0x8005FA10: sw          $t6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r14;
    after_2:
    // 0x8005FA14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005FA18: jal         0x8005FAE8
    // 0x8005FA1C: addiu       $a0, $a0, -0x4910
    ctx->r4 = ADD32(ctx->r4, -0X4910);
    func_8005FAE8(rdram, ctx);
        goto after_3;
    // 0x8005FA1C: addiu       $a0, $a0, -0x4910
    ctx->r4 = ADD32(ctx->r4, -0X4910);
    after_3:
L_8005FA20:
    // 0x8005FA20: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005FA24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FA28: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x8005FA2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005FA30: jr          $ra
    // 0x8005FA34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005FA34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005FA38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FA38: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005FA3C: addiu       $a1, $a1, -0x4500
    ctx->r5 = ADD32(ctx->r5, -0X4500);
    // 0x8005FA40: lw          $t6, 0x20($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X20);
    // FALLTHROUGH FIX: func_8005FA38 falls through to func_8005FA44
    func_8005FA44(rdram, ctx);
;}
RECOMP_FUNC void func_8005FA44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FA44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FA48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FA4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005FA50: jal         0x80039D18
    // 0x8005FA54: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_80039D18(rdram, ctx);
        goto after_0;
    // 0x8005FA54: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x8005FA58: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005FA5C: addiu       $a1, $a1, -0x4500
    ctx->r5 = ADD32(ctx->r5, -0X4500);
    // 0x8005FA60: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x8005FA64: sw          $v0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r2;
    // 0x8005FA68: ori         $t7, $t7, 0x598
    ctx->r15 = ctx->r15 | 0X598;
    // 0x8005FA6C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005FA70: lw          $t8, 0x20($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X20);
    // 0x8005FA74: lhu         $t5, 0x4($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X4);
    // 0x8005FA78: lhu         $t9, 0x88($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X88);
    // 0x8005FA7C: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x8005FA80: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005FA84: sw          $t0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r8;
    // 0x8005FA88: lw          $t1, 0x20($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X20);
    // 0x8005FA8C: nop

    // 0x8005FA90: lh          $t2, 0x1C($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X1C);
    // 0x8005FA94: nop

    // 0x8005FA98: sh          $t2, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r10;
    // 0x8005FA9C: lw          $t3, 0x20($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X20);
    // 0x8005FAA0: nop

    // 0x8005FAA4: lh          $t4, 0x20($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X20);
    // 0x8005FAA8: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x8005FAAC: jal         0x8002EC64
    // 0x8005FAB0: sh          $t4, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r12;
    func_8002EC64(rdram, ctx);
        goto after_1;
    // 0x8005FAB0: sh          $t4, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r12;
    after_1:
    // 0x8005FAB4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005FAB8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8005FABC: addiu       $a1, $a1, -0x4500
    ctx->r5 = ADD32(ctx->r5, -0X4500);
    // 0x8005FAC0: sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
    // 0x8005FAC4: sw          $v0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r2;
    // 0x8005FAC8: lw          $t8, 0x20($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X20);
    // 0x8005FACC: nop

    // 0x8005FAD0: sw          $v1, 0x98($t8)
    MEM_W(0X98, ctx->r24) = ctx->r3;
    // 0x8005FAD4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8005FAD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005FADC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005FAE0: jr          $ra
    // 0x8005FAE4: sw          $t9, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r25;
    return;
    // 0x8005FAE4: sw          $t9, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r25;
;}
RECOMP_FUNC void func_8005FAE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FAE8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005FAEC: addiu       $a1, $a1, -0x4500
    ctx->r5 = ADD32(ctx->r5, -0X4500);
    // 0x8005FAF0: lw          $t6, 0x20($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X20);
    // FALLTHROUGH FIX: func_8005FAE8 falls through to func_8005FAF4
    func_8005FAF4(rdram, ctx);
;}
RECOMP_FUNC void func_8005FAF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FAF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FAF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FAFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005FB00: jal         0x80039D18
    // 0x8005FB04: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_80039D18(rdram, ctx);
        goto after_0;
    // 0x8005FB04: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x8005FB08: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005FB0C: addiu       $a1, $a1, -0x4500
    ctx->r5 = ADD32(ctx->r5, -0X4500);
    // 0x8005FB10: sw          $v0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r2;
    // 0x8005FB14: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x8005FB18: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8005FB1C: ori         $t7, $t7, 0xDB8
    ctx->r15 = ctx->r15 | 0XDB8;
    // 0x8005FB20: addiu       $t8, $t8, -0x4734
    ctx->r24 = ADD32(ctx->r24, -0X4734);
    // 0x8005FB24: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005FB28: sw          $t8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r24;
    // 0x8005FB2C: lw          $t9, 0x20($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X20);
    // 0x8005FB30: lhu         $t6, 0x4($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X4);
    // 0x8005FB34: lhu         $t0, 0x88($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X88);
    // 0x8005FB38: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8005FB3C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8005FB40: sw          $t1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r9;
    // 0x8005FB44: lw          $t2, 0x20($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X20);
    // 0x8005FB48: nop

    // 0x8005FB4C: lh          $t3, 0x1C($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X1C);
    // 0x8005FB50: nop

    // 0x8005FB54: sh          $t3, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r11;
    // 0x8005FB58: lw          $t4, 0x20($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X20);
    // 0x8005FB5C: nop

    // 0x8005FB60: lh          $t5, 0x20($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X20);
    // 0x8005FB64: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x8005FB68: jal         0x8002EC64
    // 0x8005FB6C: sh          $t5, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r13;
    func_8002EC64(rdram, ctx);
        goto after_1;
    // 0x8005FB6C: sh          $t5, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r13;
    after_1:
    // 0x8005FB70: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005FB74: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8005FB78: addiu       $a1, $a1, -0x4500
    ctx->r5 = ADD32(ctx->r5, -0X4500);
    // 0x8005FB7C: sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
    // 0x8005FB80: sw          $v0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r2;
    // 0x8005FB84: lw          $t9, 0x20($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X20);
    // 0x8005FB88: nop

    // 0x8005FB8C: sw          $v1, 0x98($t9)
    MEM_W(0X98, ctx->r25) = ctx->r3;
    // 0x8005FB90: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8005FB94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005FB98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005FB9C: jr          $ra
    // 0x8005FBA0: sw          $t0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r8;
    return;
    // 0x8005FBA0: sw          $t0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r8;
;}
RECOMP_FUNC void func_8005FBA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FBA4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005FBA8: addiu       $v0, $v0, -0x4500
    ctx->r2 = ADD32(ctx->r2, -0X4500);
    // 0x8005FBAC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8005FBB0: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x8005FBB4: lw          $t7, -0x4910($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4910);
    // FALLTHROUGH FIX: func_8005FBA4 falls through to func_8005FBB8
    func_8005FBB8(rdram, ctx);
;}
RECOMP_FUNC void func_8005FBB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FBB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FBBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FBC0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8005FBC4: beq         $t7, $zero, L_8005FC0C
    if (ctx->r15 == 0) {
        // 0x8005FBC8: sw          $t7, 0x20($v0)
        MEM_W(0X20, ctx->r2) = ctx->r15;
            goto L_8005FC0C;
    }
    // 0x8005FBC8: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x8005FBCC: jal         0x8005FC28
    // 0x8005FBD0: nop

    func_8005FC28(rdram, ctx);
        goto after_0;
    // 0x8005FBD0: nop

    after_0:
    // 0x8005FBD4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005FBD8: lw          $a0, -0x48C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X48C0);
    // 0x8005FBDC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005FBE0: beq         $a0, $zero, L_8005FBF0
    if (ctx->r4 == 0) {
        // 0x8005FBE4: nop
    
            goto L_8005FBF0;
    }
    // 0x8005FBE4: nop

    // 0x8005FBE8: jal         0x80037554
    // 0x8005FBEC: addiu       $a1, $a1, -0x4910
    ctx->r5 = ADD32(ctx->r5, -0X4910);
    func_80037554(rdram, ctx);
        goto after_1;
    // 0x8005FBEC: addiu       $a1, $a1, -0x4910
    ctx->r5 = ADD32(ctx->r5, -0X4910);
    after_1:
L_8005FBF0:
    // 0x8005FBF0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005FBF4: lw          $a0, -0x48A4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X48A4);
    // 0x8005FBF8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005FBFC: beq         $a0, $zero, L_8005FC10
    if (ctx->r4 == 0) {
        // 0x8005FC00: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_8005FC10;
    }
    // 0x8005FC00: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8005FC04: jal         0x80037554
    // 0x8005FC08: addiu       $a1, $a1, -0x4910
    ctx->r5 = ADD32(ctx->r5, -0X4910);
    func_80037554(rdram, ctx);
        goto after_2;
    // 0x8005FC08: addiu       $a1, $a1, -0x4910
    ctx->r5 = ADD32(ctx->r5, -0X4910);
    after_2:
L_8005FC0C:
    // 0x8005FC0C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_8005FC10:
    // 0x8005FC10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005FC14: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005FC18: addiu       $v0, $v0, -0x4500
    ctx->r2 = ADD32(ctx->r2, -0X4500);
    // 0x8005FC1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005FC20: jr          $ra
    // 0x8005FC24: sw          $t9, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r25;
    return;
    // 0x8005FC24: sw          $t9, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_8005FC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FC28: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005FC2C: lw          $v0, -0x44E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X44E0);
    // 0x8005FC30: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8005FC34: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x8005FC38: lw          $t7, 0x14($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14);
    // 0x8005FC3C: lw          $t9, -0x878($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X878);
    // 0x8005FC40: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8005FC44: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8005FC48: jr          $ra
    // 0x8005FC4C: sw          $t0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r8;
    return;
    // 0x8005FC4C: sw          $t0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void func_8005FC50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FC50: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005FC54: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005FC58: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8005FC5C: lw          $t6, -0x44E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44E0);
    // 0x8005FC60: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8005FC64: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8005FC68: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8005FC6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005FC70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005FC74: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8005FC78: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8005FC7C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8005FC80: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8005FC84: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8005FC88: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8005FC8C: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x8005FC90: lui         $s4, 0xD
    ctx->r20 = S32(0XD << 16);
    // 0x8005FC94: lui         $s6, 0xDC
    ctx->r22 = S32(0XDC << 16);
    // 0x8005FC98: lhu         $s1, -0x488C($s1)
    ctx->r17 = MEM_HU(ctx->r17, -0X488C);
    // 0x8005FC9C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005FCA0: addiu       $s0, $s0, -0x4968
    ctx->r16 = ADD32(ctx->r16, -0X4968);
    // 0x8005FCA4: ori         $s6, $s6, 0x1
    ctx->r22 = ctx->r22 | 0X1;
    // 0x8005FCA8: ori         $s4, $s4, 0x1
    ctx->r20 = ctx->r20 | 0X1;
    // 0x8005FCAC: addiu       $s3, $s3, -0x878
    ctx->r19 = ADD32(ctx->r19, -0X878);
    // 0x8005FCB0: addiu       $s2, $s2, -0x4898
    ctx->r18 = ADD32(ctx->r18, -0X4898);
    // 0x8005FCB4: lui         $s5, 0xD
    ctx->r21 = S32(0XD << 16);
    // 0x8005FCB8: lui         $s7, 0xDC
    ctx->r23 = S32(0XDC << 16);
    // 0x8005FCBC: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8005FCC0: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_8005FCC4:
    // 0x8005FCC4: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x8005FCC8: nop

    // 0x8005FCCC: beq         $a0, $zero, L_8005FD6C
    if (ctx->r4 == 0) {
        // 0x8005FCD0: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_8005FD6C;
    }
    // 0x8005FCD0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8005FCD4: lw          $t7, 0x1C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C);
    // 0x8005FCD8: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x8005FCDC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8005FCE0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8005FCE4: lw          $t0, 0x18($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X18);
    // 0x8005FCE8: lw          $t1, 0x90($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X90);
    // 0x8005FCEC: and         $v0, $v0, $t9
    ctx->r2 = ctx->r2 & ctx->r25;
    // 0x8005FCF0: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
    // 0x8005FCF4: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8005FCF8: slt         $at, $v0, $s4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8005FCFC: bne         $at, $zero, L_8005FD08
    if (ctx->r1 != 0) {
        // 0x8005FD00: nop
    
            goto L_8005FD08;
    }
    // 0x8005FD00: nop

    // 0x8005FD04: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_8005FD08:
    // 0x8005FD08: lw          $t2, 0x20($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X20);
    // 0x8005FD0C: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x8005FD10: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8005FD14: slt         $at, $t3, $s6
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8005FD18: bne         $at, $zero, L_8005FD54
    if (ctx->r1 != 0) {
        // 0x8005FD1C: sw          $t3, 0x20($a0)
        MEM_W(0X20, ctx->r4) = ctx->r11;
            goto L_8005FD54;
    }
    // 0x8005FD1C: sw          $t3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r11;
    // 0x8005FD20: sw          $s7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r23;
    // 0x8005FD24: sw          $zero, 0x90($a0)
    MEM_W(0X90, ctx->r4) = 0;
    // 0x8005FD28: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x8005FD2C: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8005FD30: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x8005FD34: jal         0x800303A0
    // 0x8005FD38: nop

    func_800303A0(rdram, ctx);
        goto after_0;
    // 0x8005FD38: nop

    after_0:
    // 0x8005FD3C: lhu         $t5, 0x0($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X0);
    // 0x8005FD40: nop

    // 0x8005FD44: bne         $t5, $zero, L_8005FD54
    if (ctx->r13 != 0) {
        // 0x8005FD48: nop
    
            goto L_8005FD54;
    }
    // 0x8005FD48: nop

    // 0x8005FD4C: jal         0x8005FE58
    // 0x8005FD50: sh          $fp, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r30;
    func_8005FE58(rdram, ctx);
        goto after_1;
    // 0x8005FD50: sh          $fp, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r30;
    after_1:
L_8005FD54:
    // 0x8005FD54: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8005FD58: andi        $t6, $s1, 0xFFFF
    ctx->r14 = ctx->r17 & 0XFFFF;
    // 0x8005FD5C: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8005FD60: bgtz        $t6, L_8005FCC4
    if (SIGNED(ctx->r14) > 0) {
        // 0x8005FD64: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_8005FCC4;
    }
    // 0x8005FD64: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8005FD68: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_8005FD6C:
    // 0x8005FD6C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005FD70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005FD74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005FD78: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FD7C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005FD80: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005FD84: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8005FD88: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8005FD8C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8005FD90: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8005FD94: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8005FD98: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8005FD9C: jr          $ra
    // 0x8005FDA0: sw          $t7, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r15;
    return;
    // 0x8005FDA0: sw          $t7, -0x44E0($at)
    MEM_W(-0X44E0, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_8005FDA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FDA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005FDA8: lhu         $a0, -0x4F4A($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4F4A);
    // 0x8005FDAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005FDB0: beq         $a0, $zero, L_8005FE4C
    if (ctx->r4 == 0) {
        // 0x8005FDB4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005FE4C;
    }
    // 0x8005FDB4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005FDB8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8005FDBC: addiu       $a1, $a1, 0x68E8
    ctx->r5 = ADD32(ctx->r5, 0X68E8);
L_8005FDC0:
    // 0x8005FDC0: lhu         $t6, 0x10($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X10);
    // 0x8005FDC4: lhu         $a2, 0x12($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X12);
    // 0x8005FDC8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8005FDCC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8005FDD0: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8005FDD4: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8005FDD8: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x8005FDDC: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x8005FDE0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8005FDE4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8005FDE8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8005FDEC: addiu       $a1, $a1, 0x584
    ctx->r5 = ADD32(ctx->r5, 0X584);
    // 0x8005FDF0: bgtz        $t9, L_8005FDC0
    if (SIGNED(ctx->r25) > 0) {
        // 0x8005FDF4: sh          $a2, -0x574($a1)
        MEM_H(-0X574, ctx->r5) = ctx->r6;
            goto L_8005FDC0;
    }
    // 0x8005FDF4: sh          $a2, -0x574($a1)
    MEM_H(-0X574, ctx->r5) = ctx->r6;
    // 0x8005FDF8: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8005FDFC: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
    // 0x8005FE00: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8005FE04: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8005FE08: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8005FE0C: div         $zero, $t0, $t8
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r24)));
    // 0x8005FE10: bne         $v1, $zero, L_8005FE1C
    if (ctx->r3 != 0) {
        // 0x8005FE14: nop
    
            goto L_8005FE1C;
    }
    // 0x8005FE14: nop

    // 0x8005FE18: break       7
    do_break(2147876376);
L_8005FE1C:
    // 0x8005FE1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005FE20: bne         $v1, $at, L_8005FE34
    if (ctx->r3 != ctx->r1) {
        // 0x8005FE24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005FE34;
    }
    // 0x8005FE24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005FE28: bne         $t0, $at, L_8005FE34
    if (ctx->r8 != ctx->r1) {
        // 0x8005FE2C: nop
    
            goto L_8005FE34;
    }
    // 0x8005FE2C: nop

    // 0x8005FE30: break       6
    do_break(2147876400);
L_8005FE34:
    // 0x8005FE34: mflo        $v0
    ctx->r2 = lo;
    // 0x8005FE38: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x8005FE3C: slti        $at, $t1, 0x64
    ctx->r1 = SIGNED(ctx->r9) < 0X64 ? 1 : 0;
    // 0x8005FE40: bne         $at, $zero, L_8005FE4C
    if (ctx->r1 != 0) {
        // 0x8005FE44: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_8005FE4C;
    }
    // 0x8005FE44: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8005FE48: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
L_8005FE4C:
    // 0x8005FE4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005FE50: jr          $ra
    // 0x8005FE54: sw          $v0, -0x4894($at)
    MEM_W(-0X4894, ctx->r1) = ctx->r2;
    return;
    // 0x8005FE54: sw          $v0, -0x4894($at)
    MEM_W(-0X4894, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_8005FE58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FE58: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005FE5C: addiu       $v0, $v0, -0x4890
    ctx->r2 = ADD32(ctx->r2, -0X4890);
    // 0x8005FE60: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // FALLTHROUGH FIX: func_8005FE58 falls through to func_8005FE64
    func_8005FE64(rdram, ctx);
;}
RECOMP_FUNC void func_8005FE64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FE64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005FE68: bne         $t6, $zero, L_8005FEA4
    if (ctx->r14 != 0) {
        // 0x8005FE6C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8005FEA4;
    }
    // 0x8005FE6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FE70: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x8005FE74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005FE78: sh          $t7, -0x488E($at)
    MEM_H(-0X488E, ctx->r1) = ctx->r15;
    // 0x8005FE7C: addiu       $t8, $zero, 0x46
    ctx->r24 = ADD32(0, 0X46);
    // 0x8005FE80: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8005FE84: jal         0x80069020
    // 0x8005FE88: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_80069020(rdram, ctx);
        goto after_0;
    // 0x8005FE88: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x8005FE8C: jal         0x8000CED0
    // 0x8005FE90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8000CED0(rdram, ctx);
        goto after_1;
    // 0x8005FE90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8005FE94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005FE98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005FE9C: jal         0x80032E84
    // 0x8005FEA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80032E84(rdram, ctx);
        goto after_2;
    // 0x8005FEA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_8005FEA4:
    // 0x8005FEA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005FEA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005FEAC: jr          $ra
    // 0x8005FEB0: nop

    return;
    // 0x8005FEB0: nop

;}
RECOMP_FUNC void func_8005FEB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FEB4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005FEB8: addiu       $v0, $v0, -0x488E
    ctx->r2 = ADD32(ctx->r2, -0X488E);
    // 0x8005FEBC: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // FALLTHROUGH FIX: func_8005FEB4 falls through to func_8005FEC0
    func_8005FEC0(rdram, ctx);
;}
RECOMP_FUNC void func_8005FEC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FEC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005FEC4: beq         $v1, $zero, L_8005FF50
    if (ctx->r3 == 0) {
        // 0x8005FEC8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8005FF50;
    }
    // 0x8005FEC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FECC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005FED0: addiu       $a1, $a1, -0x4890
    ctx->r5 = ADD32(ctx->r5, -0X4890);
    // 0x8005FED4: lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X0);
    // 0x8005FED8: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8005FEDC: beq         $a0, $zero, L_8005FF4C
    if (ctx->r4 == 0) {
        // 0x8005FEE0: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_8005FF4C;
    }
    // 0x8005FEE0: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x8005FEE4: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x8005FEE8: bne         $v0, $at, L_8005FF0C
    if (ctx->r2 != ctx->r1) {
        // 0x8005FEEC: sh          $t6, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r14;
            goto L_8005FF0C;
    }
    // 0x8005FEEC: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x8005FEF0: jal         0x8005FDA4
    // 0x8005FEF4: nop

    func_8005FDA4(rdram, ctx);
        goto after_0;
    // 0x8005FEF4: nop

    after_0:
    // 0x8005FEF8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005FEFC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005FF00: lhu         $v0, -0x4890($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4890);
    // 0x8005FF04: lhu         $v1, -0x488E($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X488E);
    // 0x8005FF08: nop

L_8005FF0C:
    // 0x8005FF0C: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8005FF10: beq         $t7, $zero, L_8005FF34
    if (ctx->r15 == 0) {
        // 0x8005FF14: lui         $v0, 0x800C
        ctx->r2 = S32(0X800C << 16);
            goto L_8005FF34;
    }
    // 0x8005FF14: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8005FF18: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8005FF1C: addiu       $v0, $v0, 0x618
    ctx->r2 = ADD32(ctx->r2, 0X618);
    // 0x8005FF20: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8005FF24: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8005FF28: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8005FF2C: b           L_8005FF50
    // 0x8005FF30: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
        goto L_8005FF50;
    // 0x8005FF30: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_8005FF34:
    // 0x8005FF34: addiu       $v0, $v0, 0x618
    ctx->r2 = ADD32(ctx->r2, 0X618);
    // 0x8005FF38: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8005FF3C: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x8005FF40: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8005FF44: b           L_8005FF50
    // 0x8005FF48: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8005FF50;
    // 0x8005FF48: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8005FF4C:
    // 0x8005FF4C: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_8005FF50:
    // 0x8005FF50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005FF54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005FF58: jr          $ra
    // 0x8005FF5C: nop

    return;
    // 0x8005FF5C: nop

;}
RECOMP_FUNC void func_8005FF60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FF60: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005FF64: lh          $v0, -0x4F56($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4F56);
    // 0x8005FF68: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8005FF6C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8005FF70: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8005FF74: lw          $v1, 0x5244($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5244);
    // 0x8005FF78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005FF7C: lhu         $a1, 0x2($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X2);
    // 0x8005FF80: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005FF84: bne         $v0, $zero, L_8005FF9C
    if (ctx->r2 != 0) {
        // 0x8005FF88: sh          $a1, -0x4F58($at)
        MEM_H(-0X4F58, ctx->r1) = ctx->r5;
            goto L_8005FF9C;
    }
    // 0x8005FF88: sh          $a1, -0x4F58($at)
    MEM_H(-0X4F58, ctx->r1) = ctx->r5;
    // 0x8005FF8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005FF90: lhu         $a0, -0x4F60($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4F60);
    // 0x8005FF94: b           L_8005FFAC
    // 0x8005FF98: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
        goto L_8005FFAC;
    // 0x8005FF98: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_8005FF9C:
    // 0x8005FF9C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005FFA0: lhu         $a0, -0x4F5A($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4F5A);
    // 0x8005FFA4: nop

    // 0x8005FFA8: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_8005FFAC:
    // 0x8005FFAC: bne         $at, $zero, L_8005FFC4
    if (ctx->r1 != 0) {
        // 0x8005FFB0: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8005FFC4;
    }
    // 0x8005FFB0: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8005FFB4: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    // 0x8005FFB8: andi        $t7, $a0, 0xFFFF
    ctx->r15 = ctx->r4 & 0XFFFF;
    // 0x8005FFBC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8005FFC0: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
L_8005FFC4:
    // 0x8005FFC4: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8005FFC8: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8005FFCC: jr          $ra
    // 0x8005FFD0: nop

    return;
    // 0x8005FFD0: nop

;}
RECOMP_FUNC void func_8005FFD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FFD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005FFD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FFDC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8005FFE0: jal         0x800010A4
    // 0x8005FFE4: addiu       $a0, $a0, 0x5280
    ctx->r4 = ADD32(ctx->r4, 0X5280);
    func_800010A4(rdram, ctx);
        goto after_0;
    // 0x8005FFE4: addiu       $a0, $a0, 0x5280
    ctx->r4 = ADD32(ctx->r4, 0X5280);
    after_0:
    // 0x8005FFE8: jal         0x8005FF60
    // 0x8005FFEC: nop

    func_8005FF60(rdram, ctx);
        goto after_1;
    // 0x8005FFEC: nop

    after_1:
    // 0x8005FFF0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005FFF4: jal         0x80000ADC
    // 0x8005FFF8: sw          $v0, -0x1C4($at)
    MEM_W(-0X1C4, ctx->r1) = ctx->r2;
    func_80000ADC(rdram, ctx);
        goto after_2;
    // 0x8005FFF8: sw          $v0, -0x1C4($at)
    MEM_W(-0X1C4, ctx->r1) = ctx->r2;
    after_2:
    // 0x8005FFFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060000: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060004: jr          $ra
    // 0x80060008: nop

    return;
    // 0x80060008: nop

;}
RECOMP_FUNC void func_8006000C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006000C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80060010: lh          $v0, -0x4F56($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4F56);
    // FALLTHROUGH FIX: func_8006000C falls through to func_80060014
    func_80060014(rdram, ctx);
;}
RECOMP_FUNC void func_80060014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060014: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80060018: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8006001C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80060020: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80060024: lw          $a1, 0x564C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X564C);
    // 0x80060028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006002C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80060030: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80060034: lhu         $a0, 0x2($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X2);
    // 0x80060038: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006003C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80060040: bne         $v0, $zero, L_80060058
    if (ctx->r2 != 0) {
        // 0x80060044: sh          $a0, -0x4F58($at)
        MEM_H(-0X4F58, ctx->r1) = ctx->r4;
            goto L_80060058;
    }
    // 0x80060044: sh          $a0, -0x4F58($at)
    MEM_H(-0X4F58, ctx->r1) = ctx->r4;
    // 0x80060048: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006004C: lhu         $v0, -0x4F60($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4F60);
    // 0x80060050: b           L_80060068
    // 0x80060054: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
        goto L_80060068;
    // 0x80060054: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
L_80060058:
    // 0x80060058: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006005C: lhu         $v0, -0x4F5A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4F5A);
    // 0x80060060: nop

    // 0x80060064: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
L_80060068:
    // 0x80060068: bne         $at, $zero, L_80060080
    if (ctx->r1 != 0) {
        // 0x8006006C: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80060080;
    }
    // 0x8006006C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80060070: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80060074: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x80060078: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006007C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
L_80060080:
    // 0x80060080: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x80060084: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x80060088: nop

    // 0x8006008C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80060090: nop

    // 0x80060094: beq         $s1, $zero, L_800600B8
    if (ctx->r17 == 0) {
        // 0x80060098: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800600B8;
    }
    // 0x80060098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006009C:
    // 0x8006009C: jal         0x80000A80
    // 0x800600A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80000A80(rdram, ctx);
        goto after_0;
    // 0x800600A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800600A4: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x800600A8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800600AC: bne         $s1, $zero, L_8006009C
    if (ctx->r17 != 0) {
        // 0x800600B0: nop
    
            goto L_8006009C;
    }
    // 0x800600B0: nop

    // 0x800600B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800600B8:
    // 0x800600B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800600BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800600C0: jr          $ra
    // 0x800600C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800600C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800600C8: nop

    // 0x800600CC: nop

;}
RECOMP_FUNC void game_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    fprintf(stderr, "[BOOT] game_main entered\n"); fflush(stderr);
    // 0x800600D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800600D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800600D8: jal         0x80069120
    // 0x800600DC: nop

    osInitialize_recomp(rdram, ctx);
        goto after_0;
    // 0x800600DC: nop

    after_0:
    // 0x800600E0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800600E4: addiu       $t6, $t6, 0x860
    ctx->r14 = ADD32(ctx->r14, 0X860);
    // 0x800600E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800600EC: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x800600F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800600F4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800600F8: addiu       $a2, $a2, 0x12C
    ctx->r6 = ADD32(ctx->r6, 0X12C);
    // 0x800600FC: addiu       $a0, $a0, -0x1B00
    ctx->r4 = ADD32(ctx->r4, -0X1B00);
    // 0x80060100: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80060104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80060108: jal         0x800693B0
    // 0x8006010C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x8006010C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80060110: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80060114: jal         0x80069500
    // 0x80060118: addiu       $a0, $a0, -0x1B00
    ctx->r4 = ADD32(ctx->r4, -0X1B00);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80060118: addiu       $a0, $a0, -0x1B00
    ctx->r4 = ADD32(ctx->r4, -0X1B00);
    after_2:
    // 0x8006011C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80060120: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80060124: jr          $ra
    // 0x80060128: nop

    return;
    // 0x80060128: nop

;}
RECOMP_FUNC void func_8006012C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006012C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80060130: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060134: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80060138: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006013C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80060140: addiu       $a2, $a2, 0x3800
    ctx->r6 = ADD32(ctx->r6, 0X3800);
    // 0x80060144: addiu       $a1, $a1, 0x3828
    ctx->r5 = ADD32(ctx->r5, 0X3828);
    // 0x80060148: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x8006014C: jal         0x80069650
    // 0x80060150: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_0;
    // 0x80060150: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_0:
    // 0x80060154: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80060158: addiu       $t6, $t6, 0x2860
    ctx->r14 = ADD32(ctx->r14, 0X2860);
    // 0x8006015C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80060160: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80060164: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80060168: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8006016C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80060170: addiu       $a2, $a2, 0x18B0
    ctx->r6 = ADD32(ctx->r6, 0X18B0);
    // 0x80060174: addiu       $a0, $a0, -0x1950
    ctx->r4 = ADD32(ctx->r4, -0X1950);
    // 0x80060178: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8006017C: jal         0x800693B0
    // 0x80060180: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80060180: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80060184: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80060188: jal         0x80069500
    // 0x8006018C: addiu       $a0, $a0, -0x1950
    ctx->r4 = ADD32(ctx->r4, -0X1950);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x8006018C: addiu       $a0, $a0, -0x1950
    ctx->r4 = ADD32(ctx->r4, -0X1950);
    after_2:
L_80060190:
    // 0x80060190: b           L_80060190
    pause_self(rdram);
    // 0x80060194: nop

    // 0x80060198: nop

    // 0x8006019C: nop

    // 0x800601A0: nop

    // 0x800601A4: nop

    // 0x800601A8: nop

    // 0x800601AC: nop

    // 0x800601B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800601B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800601B8: jr          $ra
    // 0x800601BC: nop

    return;
    // 0x800601BC: nop

;}
RECOMP_FUNC void func_800601C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800601C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800601C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800601C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800601CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800601D0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800601D4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800601D8: jal         0x800697E0
    // 0x800601DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800601DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800601E0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800601E4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800601E8: jal         0x80069810
    // 0x800601EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800601EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800601F0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800601F4: addiu       $a2, $a2, 0x2880
    ctx->r6 = ADD32(ctx->r6, 0X2880);
    // 0x800601F8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800601FC: jal         0x80069880
    // 0x80060200: addiu       $a1, $sp, 0x4B
    ctx->r5 = ADD32(ctx->r29, 0X4B);
    osContInit_recomp(rdram, ctx);
        goto after_2;
    // 0x80060200: addiu       $a1, $sp, 0x4B
    ctx->r5 = ADD32(ctx->r29, 0X4B);
    after_2:
    // 0x80060204: jal         0x80069C40
    // 0x80060208: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    osContStartQuery_recomp(rdram, ctx);
        goto after_3;
    // 0x80060208: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x8006020C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80060210: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80060214: jal         0x80069CF0
    // 0x80060218: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80060218: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8006021C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80060220: jal         0x80069CC4
    // 0x80060224: addiu       $a0, $a0, 0x2880
    ctx->r4 = ADD32(ctx->r4, 0X2880);
    osContGetQuery_recomp(rdram, ctx);
        goto after_5;
    // 0x80060224: addiu       $a0, $a0, 0x2880
    ctx->r4 = ADD32(ctx->r4, 0X2880);
    after_5:
    // 0x80060228: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006022C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80060230: addiu       $a1, $a1, 0x2878
    ctx->r5 = ADD32(ctx->r5, 0X2878);
    // 0x80060234: addiu       $a0, $a0, 0x2860
    ctx->r4 = ADD32(ctx->r4, 0X2860);
    // 0x80060238: jal         0x800697E0
    // 0x8006023C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_6;
    // 0x8006023C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80060240: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80060244: addiu       $a1, $a1, 0x2860
    ctx->r5 = ADD32(ctx->r5, 0X2860);
    // 0x80060248: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8006024C: jal         0x80069810
    // 0x80060250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80060250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80060254: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80060258: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8006025C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80060260: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80060264: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80060268: addiu       $a0, $a0, 0x5690
    ctx->r4 = ADD32(ctx->r4, 0X5690);
    // 0x8006026C: addiu       $a3, $a3, 0x28D8
    ctx->r7 = ADD32(ctx->r7, 0X28D8);
    // 0x80060270: addiu       $v0, $v0, 0x28C8
    ctx->r2 = ADD32(ctx->r2, 0X28C8);
    // 0x80060274: addiu       $a2, $a2, 0x28B8
    ctx->r6 = ADD32(ctx->r6, 0X28B8);
    // 0x80060278: addiu       $a1, $a1, 0x28A8
    ctx->r5 = ADD32(ctx->r5, 0X28A8);
    // 0x8006027C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80060280:
    // 0x80060280: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80060284: sltu        $at, $v0, $a3
    ctx->r1 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x80060288: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8006028C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80060290: sw          $a0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r4;
    // 0x80060294: sw          $v1, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r3;
    // 0x80060298: bne         $at, $zero, L_80060280
    if (ctx->r1 != 0) {
        // 0x8006029C: sw          $v1, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r3;
            goto L_80060280;
    }
    // 0x8006029C: sw          $v1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r3;
    // 0x800602A0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800602A4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800602A8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800602AC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800602B0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800602B4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800602B8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800602BC: lw          $v1, 0x5698($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5698);
    // 0x800602C0: addiu       $a1, $a1, 0x5698
    ctx->r5 = ADD32(ctx->r5, 0X5698);
    // 0x800602C4: addiu       $t1, $t1, 0x28B8
    ctx->r9 = ADD32(ctx->r9, 0X28B8);
    // 0x800602C8: addiu       $t2, $t2, 0x28C8
    ctx->r10 = ADD32(ctx->r10, 0X28C8);
    // 0x800602CC: addiu       $t3, $t3, 0x28A8
    ctx->r11 = ADD32(ctx->r11, 0X28A8);
    // 0x800602D0: addiu       $t4, $t4, 0x2890
    ctx->r12 = ADD32(ctx->r12, 0X2890);
    // 0x800602D4: addiu       $a3, $a3, 0x2880
    ctx->r7 = ADD32(ctx->r7, 0X2880);
    // 0x800602D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800602DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800602E0: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800602E4: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
L_800602E8:
    // 0x800602E8: lbu         $t6, 0x3($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X3);
    // 0x800602EC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800602F0: beq         $t0, $t6, L_80060334
    if (ctx->r8 == ctx->r14) {
        // 0x800602F4: addu        $t7, $t1, $v0
        ctx->r15 = ADD32(ctx->r9, ctx->r2);
            goto L_80060334;
    }
    // 0x800602F4: addu        $t7, $t1, $v0
    ctx->r15 = ADD32(ctx->r9, ctx->r2);
    // 0x800602F8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800602FC: sw          $a0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r4;
    // 0x80060300: addu        $t8, $t2, $a2
    ctx->r24 = ADD32(ctx->r10, ctx->r6);
    // 0x80060304: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x80060308: sw          $v1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r3;
    // 0x8006030C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80060310: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x80060314: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80060318: addu        $t7, $t3, $v0
    ctx->r15 = ADD32(ctx->r11, ctx->r2);
    // 0x8006031C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80060320: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80060324: bne         $s0, $t8, L_80060334
    if (ctx->r16 != ctx->r24) {
        // 0x80060328: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_80060334;
    }
    // 0x80060328: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8006032C: b           L_8006039C
    // 0x80060330: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8006039C;
    // 0x80060330: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80060334:
    // 0x80060334: lbu         $t9, 0x7($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X7);
    // 0x80060338: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8006033C: beq         $t0, $t9, L_80060388
    if (ctx->r8 == ctx->r25) {
        // 0x80060340: addiu       $t6, $a0, 0x1
        ctx->r14 = ADD32(ctx->r4, 0X1);
            goto L_80060388;
    }
    // 0x80060340: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x80060344: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80060348: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8006034C: addu        $t7, $t1, $v0
    ctx->r15 = ADD32(ctx->r9, ctx->r2);
    // 0x80060350: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80060354: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80060358: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x8006035C: addu        $t8, $t2, $a2
    ctx->r24 = ADD32(ctx->r10, ctx->r6);
    // 0x80060360: sw          $v1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r3;
    // 0x80060364: addu        $t8, $t3, $v0
    ctx->r24 = ADD32(ctx->r11, ctx->r2);
    // 0x80060368: addiu       $t7, $t6, 0x6
    ctx->r15 = ADD32(ctx->r14, 0X6);
    // 0x8006036C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x80060370: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80060374: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80060378: bne         $s0, $t9, L_80060388
    if (ctx->r16 != ctx->r25) {
        // 0x8006037C: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_80060388;
    }
    // 0x8006037C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x80060380: b           L_8006039C
    // 0x80060384: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8006039C;
    // 0x80060384: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80060388:
    // 0x80060388: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8006038C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80060390: bne         $a0, $t5, L_800602E8
    if (ctx->r4 != ctx->r13) {
        // 0x80060394: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_800602E8;
    }
    // 0x80060394: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80060398: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8006039C:
    // 0x8006039C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800603A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800603A4: jr          $ra
    // 0x800603A8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800603A8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800603AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800603AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800603B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800603B4: jal         0x800609A0
    // 0x800603B8: nop

    func_800609A0(rdram, ctx);
        goto after_0;
    // 0x800603B8: nop

    after_0:
    // 0x800603BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800603C0: jal         0x80069E30
    // 0x800603C4: addiu       $a0, $a0, 0x2860
    ctx->r4 = ADD32(ctx->r4, 0X2860);
    osContStartReadData_recomp(rdram, ctx);
        goto after_1;
    // 0x800603C4: addiu       $a0, $a0, 0x2860
    ctx->r4 = ADD32(ctx->r4, 0X2860);
    after_1:
    // 0x800603C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800603CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800603D0: jr          $ra
    // 0x800603D4: nop

    return;
    // 0x800603D4: nop

;}
RECOMP_FUNC void func_800603D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800603D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800603DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800603E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800603E4: addiu       $a0, $a0, 0x2860
    ctx->r4 = ADD32(ctx->r4, 0X2860);
    // 0x800603E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800603EC: jal         0x80069CF0
    // 0x800603F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800603F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800603F4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800603F8: jal         0x80069EF4
    // 0x800603FC: addiu       $a0, $a0, 0x2890
    ctx->r4 = ADD32(ctx->r4, 0X2890);
    osContGetReadData_recomp(rdram, ctx);
        goto after_1;
    // 0x800603FC: addiu       $a0, $a0, 0x2890
    ctx->r4 = ADD32(ctx->r4, 0X2890);
    after_1:
    // 0x80060400: jal         0x800609E0
    // 0x80060404: nop

    __osSiRelAccess_recomp(rdram, ctx);
        goto after_2;
    // 0x80060404: nop

    after_2:
    // 0x80060408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006040C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060410: jr          $ra
    // 0x80060414: nop

    return;
    // 0x80060414: nop

;}
RECOMP_FUNC void func_80060418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060418: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006041C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80060420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060424: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80060428: addiu       $a0, $a0, 0x2860
    ctx->r4 = ADD32(ctx->r4, 0X2860);
    // 0x8006042C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80060430: jal         0x80069CF0
    // 0x80060434: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80060434: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80060438: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006043C: beq         $v0, $at, L_800604AC
    if (ctx->r2 == ctx->r1) {
        // 0x80060440: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800604AC;
    }
    // 0x80060440: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80060444: jal         0x80069EF4
    // 0x80060448: addiu       $a0, $a0, 0x2890
    ctx->r4 = ADD32(ctx->r4, 0X2890);
    osContGetReadData_recomp(rdram, ctx);
        goto after_1;
    // 0x80060448: addiu       $a0, $a0, 0x2890
    ctx->r4 = ADD32(ctx->r4, 0X2890);
    after_1:
    // 0x8006044C: jal         0x800609E0
    // 0x80060450: nop

    __osSiRelAccess_recomp(rdram, ctx);
        goto after_2;
    // 0x80060450: nop

    after_2:
    // 0x80060454: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80060458: addiu       $t0, $t0, 0x5698
    ctx->r8 = ADD32(ctx->r8, 0X5698);
    // 0x8006045C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80060460: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80060464: blez        $a1, L_80060498
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80060468: addiu       $v1, $v1, 0x28E0
        ctx->r3 = ADD32(ctx->r3, 0X28E0);
            goto L_80060498;
    }
    // 0x80060468: addiu       $v1, $v1, 0x28E0
    ctx->r3 = ADD32(ctx->r3, 0X28E0);
    // 0x8006046C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80060470: addiu       $v0, $t6, 0x28A8
    ctx->r2 = ADD32(ctx->r14, 0X28A8);
    // 0x80060474: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80060478: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
L_8006047C:
    // 0x8006047C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80060480: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80060484: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80060488: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8006048C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80060490: bne         $at, $zero, L_8006047C
    if (ctx->r1 != 0) {
        // 0x80060494: sh          $t9, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r25;
            goto L_8006047C;
    }
    // 0x80060494: sh          $t9, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r25;
L_80060498:
    // 0x80060498: jal         0x800609A0
    // 0x8006049C: nop

    func_800609A0(rdram, ctx);
        goto after_3;
    // 0x8006049C: nop

    after_3:
    // 0x800604A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800604A4: jal         0x80069E30
    // 0x800604A8: addiu       $a0, $a0, 0x2860
    ctx->r4 = ADD32(ctx->r4, 0X2860);
    osContStartReadData_recomp(rdram, ctx);
        goto after_4;
    // 0x800604A8: addiu       $a0, $a0, 0x2860
    ctx->r4 = ADD32(ctx->r4, 0X2860);
    after_4:
L_800604AC:
    // 0x800604AC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800604B0: addiu       $t1, $t1, 0x28A8
    ctx->r9 = ADD32(ctx->r9, 0X28A8);
    // 0x800604B4: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800604B8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800604BC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800604C0: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x800604C4: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // 0x800604C8: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x800604CC: xor         $t5, $v0, $t4
    ctx->r13 = ctx->r2 ^ ctx->r12;
    // 0x800604D0: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x800604D4: xor         $t2, $v0, $t9
    ctx->r10 = ctx->r2 ^ ctx->r25;
    // 0x800604D8: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x800604DC: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x800604E0: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x800604E4: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800604E8: or          $t3, $t7, $t2
    ctx->r11 = ctx->r15 | ctx->r10;
    // 0x800604EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800604F0: addiu       $t0, $t0, 0x5698
    ctx->r8 = ADD32(ctx->r8, 0X5698);
    // 0x800604F4: sw          $t3, 0x569C($at)
    MEM_W(0X569C, ctx->r1) = ctx->r11;
    // 0x800604F8: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800604FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80060500: blez        $t4, L_80060560
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80060504: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_80060560;
    }
    // 0x80060504: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80060508: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8006050C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80060510: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80060514: addiu       $a1, $a1, 0x28D8
    ctx->r5 = ADD32(ctx->r5, 0X28D8);
    // 0x80060518: addiu       $v0, $v0, 0x28A8
    ctx->r2 = ADD32(ctx->r2, 0X28A8);
    // 0x8006051C: addiu       $v1, $v1, 0x28E0
    ctx->r3 = ADD32(ctx->r3, 0X28E0);
    // 0x80060520: nor         $a3, $a3, $zero
    ctx->r7 = ~(ctx->r7 | 0);
L_80060524:
    // 0x80060524: lhu         $t5, 0x0($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X0);
    // 0x80060528: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x8006052C: nor         $t6, $t5, $zero
    ctx->r14 = ~(ctx->r13 | 0);
    // 0x80060530: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80060534: or          $t8, $t6, $a3
    ctx->r24 = ctx->r14 | ctx->r7;
    // 0x80060538: and         $t9, $t8, $a0
    ctx->r25 = ctx->r24 & ctx->r4;
    // 0x8006053C: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
    // 0x80060540: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80060544: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80060548: slt         $at, $a2, $t2
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8006054C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80060550: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80060554: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80060558: bne         $at, $zero, L_80060524
    if (ctx->r1 != 0) {
        // 0x8006055C: sh          $a0, -0x2($a1)
        MEM_H(-0X2, ctx->r5) = ctx->r4;
            goto L_80060524;
    }
    // 0x8006055C: sh          $a0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r4;
L_80060560:
    // 0x80060560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060568: jr          $ra
    // 0x8006056C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x8006056C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void func_80060570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060574: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80060578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006057C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80060580: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80060584: addiu       $a1, $a1, 0x37C8
    ctx->r5 = ADD32(ctx->r5, 0X37C8);
    // 0x80060588: addiu       $a0, $a0, 0x37B0
    ctx->r4 = ADD32(ctx->r4, 0X37B0);
    // 0x8006058C: jal         0x800697E0
    // 0x80060590: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80060590: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x80060594: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80060598: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006059C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800605A0: addiu       $a2, $a2, 0x37B0
    ctx->r6 = ADD32(ctx->r6, 0X37B0);
    // 0x800605A4: jal         0x80060DC0
    // 0x800605A8: addiu       $a1, $a1, 0x37E8
    ctx->r5 = ADD32(ctx->r5, 0X37E8);
    func_80060DC0(rdram, ctx);
        goto after_1;
    // 0x800605A8: addiu       $a1, $a1, 0x37E8
    ctx->r5 = ADD32(ctx->r5, 0X37E8);
    after_1:
    // 0x800605AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800605B0: jal         0x80060BE4
    // 0x800605B4: nop

    func_80060BE4(rdram, ctx);
        goto after_2;
    // 0x800605B4: nop

    after_2:
    // 0x800605B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800605BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800605C0: sw          $v0, 0x37F0($at)
    MEM_W(0X37F0, ctx->r1) = ctx->r2;
    // 0x800605C4: jr          $ra
    // 0x800605C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800605C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800605CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800605CC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800605D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800605D4: sh          $t6, 0x37F4($at)
    MEM_H(0X37F4, ctx->r1) = ctx->r14;
    // 0x800605D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800605DC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // FALLTHROUGH FIX: func_800605CC falls through to func_800605E0
    func_800605E0(rdram, ctx);
;}
RECOMP_FUNC void func_800605E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800605E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800605E4: sh          $t7, 0x37F6($at)
    MEM_H(0X37F6, ctx->r1) = ctx->r15;
    // 0x800605E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800605EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800605F0: jal         0x80060570
    // 0x800605F4: sw          $zero, 0x37F8($at)
    MEM_W(0X37F8, ctx->r1) = 0;
    func_80060570(rdram, ctx);
        goto after_0;
    // 0x800605F4: sw          $zero, 0x37F8($at)
    MEM_W(0X37F8, ctx->r1) = 0;
    after_0:
    // 0x800605F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800605FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060600: jr          $ra
    // 0x80060604: nop

    return;
    // 0x80060604: nop

;}
RECOMP_FUNC void func_80060608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060608: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006060C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060610: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80060614: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80060618: addiu       $a0, $a0, 0x37B0
    ctx->r4 = ADD32(ctx->r4, 0X37B0);
    // 0x8006061C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80060620: jal         0x80069CF0
    // 0x80060624: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80060624: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80060628: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8006062C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80060630: lh          $v1, 0x0($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X0);
    // 0x80060634: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80060638: bne         $v1, $at, L_8006064C
    if (ctx->r3 != ctx->r1) {
        // 0x8006063C: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_8006064C;
    }
    // 0x8006063C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80060640: sw          $t7, 0x58B0($at)
    MEM_W(0X58B0, ctx->r1) = ctx->r15;
    // 0x80060644: lh          $v1, 0x0($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X0);
    // 0x80060648: nop

L_8006064C:
    // 0x8006064C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060650: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80060654: jr          $ra
    // 0x80060658: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80060658: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8006065C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006065C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80060660: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80060664: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80060668: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006066C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80060670: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80060674: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80060678: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006067C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80060680: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80060684: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80060688: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006068C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80060690: addiu       $s6, $s6, 0x58B0
    ctx->r22 = ADD32(ctx->r22, 0X58B0);
    // 0x80060694: addiu       $s2, $s2, 0x37B0
    ctx->r18 = ADD32(ctx->r18, 0X37B0);
    // 0x80060698: addiu       $s1, $s1, 0x37FC
    ctx->r17 = ADD32(ctx->r17, 0X37FC);
    // 0x8006069C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800606A0: addiu       $s3, $sp, 0x3C
    ctx->r19 = ADD32(ctx->r29, 0X3C);
    // 0x800606A4: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x800606A8: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x800606AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800606B0:
    // 0x800606B0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800606B4: jal         0x80069CF0
    // 0x800606B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800606B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x800606BC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800606C0: nop

    // 0x800606C4: lh          $v0, 0x0($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X0);
    // 0x800606C8: nop

    // 0x800606CC: bne         $s0, $v0, L_800606F0
    if (ctx->r16 != ctx->r2) {
        // 0x800606D0: nop
    
            goto L_800606F0;
    }
    // 0x800606D0: nop

    // 0x800606D4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800606D8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800606DC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800606E0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800606E4: lh          $v0, 0x0($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X0);
    // 0x800606E8: b           L_80060708
    // 0x800606EC: nop

        goto L_80060708;
    // 0x800606EC: nop

L_800606F0:
    // 0x800606F0: bne         $s5, $v0, L_80060708
    if (ctx->r21 != ctx->r2) {
        // 0x800606F4: nop
    
            goto L_80060708;
    }
    // 0x800606F4: nop

    // 0x800606F8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800606FC: sw          $s0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r16;
    // 0x80060700: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x80060704: nop

L_80060708:
    // 0x80060708: bne         $s4, $v0, L_800606B0
    if (ctx->r20 != ctx->r2) {
        // 0x8006070C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800606B0;
    }
    // 0x8006070C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80060710: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80060714: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060718: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006071C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80060720: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80060724: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80060728: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8006072C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80060730: jr          $ra
    // 0x80060734: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80060734: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80060738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060738: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8006073C: lw          $t6, 0x58B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X58B0);
    // FALLTHROUGH FIX: func_80060738 falls through to func_80060740
    func_80060740(rdram, ctx);
;}
RECOMP_FUNC void func_80060740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060740: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80060744: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80060748: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006074C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060750: bne         $t6, $zero, L_800608B0
    if (ctx->r14 != 0) {
        // 0x80060754: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_800608B0;
    }
    // 0x80060754: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80060758: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8006075C: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80060760: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80060764: addiu       $v0, $v0, 0x4BE0
    ctx->r2 = ADD32(ctx->r2, 0X4BE0);
    // 0x80060768: addiu       $t8, $t8, 0x4CB0
    ctx->r24 = ADD32(ctx->r24, 0X4CB0);
    // 0x8006076C: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x80060770: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80060774: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    // 0x80060778: sw          $t9, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r25;
    // 0x8006077C: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x80060780: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x80060784: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80060788: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x8006078C: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x80060790: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80060794: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80060798: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006079C: addiu       $t0, $t0, 0x4CB0
    ctx->r8 = ADD32(ctx->r8, 0X4CB0);
    // 0x800607A0: addiu       $t1, $t1, -0x21C0
    ctx->r9 = ADD32(ctx->r9, -0X21C0);
    // 0x800607A4: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
    // 0x800607A8: addiu       $t3, $t3, -0x62F0
    ctx->r11 = ADD32(ctx->r11, -0X62F0);
    // 0x800607AC: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x800607B0: addiu       $t5, $t5, -0x5EF0
    ctx->r13 = ADD32(ctx->r13, -0X5EF0);
    // 0x800607B4: addiu       $t6, $t6, 0x2110
    ctx->r14 = ADD32(ctx->r14, 0X2110);
    // 0x800607B8: addiu       $t7, $t7, 0x28F0
    ctx->r15 = ADD32(ctx->r15, 0X28F0);
    // 0x800607BC: addiu       $t8, $zero, 0xC00
    ctx->r24 = ADD32(0, 0XC00);
    // 0x800607C0: addiu       $t9, $t9, 0x37B0
    ctx->r25 = ADD32(ctx->r25, 0X37B0);
    // 0x800607C4: andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // 0x800607C8: sw          $a1, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r5;
    // 0x800607CC: sw          $a2, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r6;
    // 0x800607D0: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800607D4: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x800607D8: sw          $t1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r9;
    // 0x800607DC: sw          $t2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r10;
    // 0x800607E0: sw          $t3, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r11;
    // 0x800607E4: sw          $t4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r12;
    // 0x800607E8: sw          $t5, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r13;
    // 0x800607EC: sw          $t6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r14;
    // 0x800607F0: sw          $t7, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r15;
    // 0x800607F4: sw          $t8, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r24;
    // 0x800607F8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800607FC: sw          $t9, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r25;
    // 0x80060800: beq         $v0, $zero, L_80060818
    if (ctx->r2 == 0) {
        // 0x80060804: sw          $v1, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r3;
            goto L_80060818;
    }
    // 0x80060804: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // 0x80060808: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006080C: addiu       $t0, $t0, 0x37F4
    ctx->r8 = ADD32(ctx->r8, 0X37F4);
    // 0x80060810: b           L_80060824
    // 0x80060814: sw          $t0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r8;
        goto L_80060824;
    // 0x80060814: sw          $t0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r8;
L_80060818:
    // 0x80060818: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8006081C: addiu       $t1, $t1, 0x37F6
    ctx->r9 = ADD32(ctx->r9, 0X37F6);
    // 0x80060820: sw          $t1, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r9;
L_80060824:
    // 0x80060824: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80060828: lw          $t2, 0x58B4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X58B4);
    // 0x8006082C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80060830: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80060834: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80060838: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x8006083C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80060840: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80060844: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80060848: sll         $t3, $t3, 9
    ctx->r11 = S32(ctx->r11 << 9);
    // 0x8006084C: addiu       $t4, $t4, 0x70C0
    ctx->r12 = ADD32(ctx->r12, 0X70C0);
    // 0x80060850: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80060854: sw          $t5, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r13;
    // 0x80060858: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006085C: lw          $a0, 0x37F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37F0);
    // 0x80060860: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80060864: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80060868: jal         0x8006A090
    // 0x8006086C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8006086C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80060870: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80060874: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80060878: beq         $v0, $zero, L_80060890
    if (ctx->r2 == 0) {
        // 0x8006087C: addiu       $v1, $v1, 0x58B4
        ctx->r3 = ADD32(ctx->r3, 0X58B4);
            goto L_80060890;
    }
    // 0x8006087C: addiu       $v1, $v1, 0x58B4
    ctx->r3 = ADD32(ctx->r3, 0X58B4);
    // 0x80060880: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80060884: nop

    // 0x80060888: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x8006088C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80060890:
    // 0x80060890: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80060894: addiu       $v0, $v0, 0x37F8
    ctx->r2 = ADD32(ctx->r2, 0X37F8);
    // 0x80060898: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8006089C: nop

    // 0x800608A0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800608A4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800608A8: andi        $t1, $t9, 0x7
    ctx->r9 = ctx->r25 & 0X7;
    // 0x800608AC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_800608B0:
    // 0x800608B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800608B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800608B8: jr          $ra
    // 0x800608BC: nop

    return;
    // 0x800608BC: nop

;}
RECOMP_FUNC void func_800608C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800608C0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800608C4: lw          $t6, 0x58B8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X58B8);
    // FALLTHROUGH FIX: func_800608C0 falls through to func_800608C8
    func_800608C8(rdram, ctx);
;}
RECOMP_FUNC void func_800608C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800608C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800608CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800608D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800608D4: beq         $t6, $zero, L_800608E8
    if (ctx->r14 == 0) {
        // 0x800608D8: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800608E8;
    }
    // 0x800608D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800608DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800608E0: b           L_800608F0
    // 0x800608E4: sw          $zero, 0x58B8($at)
    MEM_W(0X58B8, ctx->r1) = 0;
        goto L_800608F0;
    // 0x800608E4: sw          $zero, 0x58B8($at)
    MEM_W(0X58B8, ctx->r1) = 0;
L_800608E8:
    // 0x800608E8: jal         0x8006065C
    // 0x800608EC: nop

    func_8006065C(rdram, ctx);
        goto after_0;
    // 0x800608EC: nop

    after_0:
L_800608F0:
    // 0x800608F0: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x800608F4: lw          $t7, 0x58B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X58B4);
    // 0x800608F8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800608FC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80060900: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80060904: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80060908: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8006090C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80060910: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80060914: subu        $a2, $t1, $a1
    ctx->r6 = SUB32(ctx->r9, ctx->r5);
    // 0x80060918: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8006091C: addiu       $t9, $t9, 0x34F0
    ctx->r25 = ADD32(ctx->r25, 0X34F0);
    // 0x80060920: sra         $t2, $a2, 3
    ctx->r10 = S32(SIGNED(ctx->r6) >> 3);
    // 0x80060924: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x80060928: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8006092C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80060930: sll         $a2, $t2, 3
    ctx->r6 = S32(ctx->r10 << 3);
    // 0x80060934: jal         0x80060738
    // 0x80060938: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80060738(rdram, ctx);
        goto after_1;
    // 0x80060938: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8006093C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80060940: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80060944: jr          $ra
    // 0x80060948: nop

    return;
    // 0x80060948: nop

    // 0x8006094C: nop

;}
RECOMP_FUNC void func_800609A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800609A0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800609A4: lw          $t6, 0x58C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X58C0);
    // FALLTHROUGH FIX: func_800609A0 falls through to func_800609A8
    func_800609A8(rdram, ctx);
;}
RECOMP_FUNC void func_800609A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800609A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800609AC: bne         $t6, $zero, L_800609BC
    if (ctx->r14 != 0) {
        // 0x800609B0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800609BC;
    }
    // 0x800609B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800609B4: jal         0x80060950
    // 0x800609B8: nop

    __osSiCreateAccessQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800609B8: nop

    after_0:
L_800609BC:
    // 0x800609BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800609C0: addiu       $a0, $a0, 0x3888
    ctx->r4 = ADD32(ctx->r4, 0X3888);
    // 0x800609C4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800609C8: jal         0x80069CF0
    // 0x800609CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800609CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800609D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800609D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800609D8: jr          $ra
    // 0x800609DC: nop

    return;
    // 0x800609DC: nop

;}
RECOMP_FUNC void func_80060A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060A10: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80060A14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80060A18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80060A1C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80060A20: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80060A24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80060A28: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80060A2C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80060A30: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80060A34: sw          $zero, 0x66C($a0)
    MEM_W(0X66C, ctx->r4) = 0;
    // 0x80060A38: sw          $zero, 0x670($a0)
    MEM_W(0X670, ctx->r4) = 0;
    // 0x80060A3C: sw          $zero, 0x674($a0)
    MEM_W(0X674, ctx->r4) = 0;
    // 0x80060A40: sw          $zero, 0x668($a0)
    MEM_W(0X668, ctx->r4) = 0;
    // 0x80060A44: sw          $t6, 0x678($a0)
    MEM_W(0X678, ctx->r4) = ctx->r14;
    // 0x80060A48: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80060A4C: sh          $t8, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r24;
    // 0x80060A50: addiu       $a0, $a0, 0x74
    ctx->r4 = ADD32(ctx->r4, 0X74);
    // 0x80060A54: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80060A58: addiu       $a1, $s0, 0x8C
    ctx->r5 = ADD32(ctx->r16, 0X8C);
    // 0x80060A5C: jal         0x800697E0
    // 0x80060A60: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80060A60: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x80060A64: addiu       $a0, $s0, 0xAC
    ctx->r4 = ADD32(ctx->r16, 0XAC);
    // 0x80060A68: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80060A6C: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x80060A70: jal         0x800697E0
    // 0x80060A74: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80060A74: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x80060A78: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x80060A7C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80060A80: addiu       $a1, $s0, 0xFC
    ctx->r5 = ADD32(ctx->r16, 0XFC);
    // 0x80060A84: jal         0x800697E0
    // 0x80060A88: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x80060A88: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x80060A8C: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x80060A90: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x80060A94: jal         0x800697E0
    // 0x80060A98: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x80060A98: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x80060A9C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80060AA0: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x80060AA4: jal         0x800697E0
    // 0x80060AA8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x80060AA8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
    // 0x80060AAC: addiu       $a0, $s0, 0x11C
    ctx->r4 = ADD32(ctx->r16, 0X11C);
    // 0x80060AB0: addiu       $a1, $s0, 0x134
    ctx->r5 = ADD32(ctx->r16, 0X134);
    // 0x80060AB4: jal         0x800697E0
    // 0x80060AB8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_5;
    // 0x80060AB8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x80060ABC: jal         0x8006A1E0
    // 0x80060AC0: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    func_8006A1E0(rdram, ctx);
        goto after_6;
    // 0x80060AC0: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_6:
    // 0x80060AC4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80060AC8: jal         0x8006A540
    // 0x80060ACC: nop

    osViSetMode_recomp(rdram, ctx);
        goto after_7;
    // 0x80060ACC: nop

    after_7:
    // 0x80060AD0: jal         0x8006A5B0
    // 0x80060AD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_8;
    // 0x80060AD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80060AD8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80060ADC: lbu         $a2, 0x43($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X43);
    // 0x80060AE0: jal         0x8006A620
    // 0x80060AE4: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    osViSetEvent_recomp(rdram, ctx);
        goto after_9;
    // 0x80060AE4: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    after_9:
    // 0x80060AE8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80060AEC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80060AF0: jal         0x80069810
    // 0x80060AF4: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x80060AF4: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    after_10:
    // 0x80060AF8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80060AFC: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80060B00: jal         0x80069810
    // 0x80060B04: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x80060B04: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    after_11:
    // 0x80060B08: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80060B0C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80060B10: jal         0x80069810
    // 0x80060B14: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x80060B14: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    after_12:
    // 0x80060B18: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80060B1C: addiu       $t9, $t9, 0x58A0
    ctx->r25 = ADD32(ctx->r25, 0X58A0);
    // 0x80060B20: addiu       $a0, $s0, 0x158
    ctx->r4 = ADD32(ctx->r16, 0X158);
    // 0x80060B24: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80060B28: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x80060B2C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80060B30: addiu       $a2, $a2, 0xBEC
    ctx->r6 = ADD32(ctx->r6, 0XBEC);
    // 0x80060B34: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80060B38: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80060B3C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80060B40: jal         0x800693B0
    // 0x80060B44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_13;
    // 0x80060B44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_13:
    // 0x80060B48: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80060B4C: jal         0x80069500
    // 0x80060B50: nop

    osStartThread_recomp(rdram, ctx);
        goto after_14;
    // 0x80060B50: nop

    after_14:
    // 0x80060B54: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80060B58: addiu       $t1, $t1, 0x78A0
    ctx->r9 = ADD32(ctx->r9, 0X78A0);
    // 0x80060B5C: addiu       $a0, $s0, 0x308
    ctx->r4 = ADD32(ctx->r16, 0X308);
    // 0x80060B60: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80060B64: addiu       $t2, $zero, 0x6E
    ctx->r10 = ADD32(0, 0X6E);
    // 0x80060B68: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80060B6C: addiu       $a2, $a2, 0xEF8
    ctx->r6 = ADD32(ctx->r6, 0XEF8);
    // 0x80060B70: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80060B74: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80060B78: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80060B7C: jal         0x800693B0
    // 0x80060B80: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_15;
    // 0x80060B80: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_15:
    // 0x80060B84: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80060B88: jal         0x80069500
    // 0x80060B8C: nop

    osStartThread_recomp(rdram, ctx);
        goto after_16;
    // 0x80060B8C: nop

    after_16:
    // 0x80060B90: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x80060B94: addiu       $t3, $t3, -0x6760
    ctx->r11 = ADD32(ctx->r11, -0X6760);
    // 0x80060B98: addiu       $a0, $s0, 0x4B8
    ctx->r4 = ADD32(ctx->r16, 0X4B8);
    // 0x80060B9C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80060BA0: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80060BA4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80060BA8: addiu       $a2, $a2, 0x11A0
    ctx->r6 = ADD32(ctx->r6, 0X11A0);
    // 0x80060BAC: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80060BB0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80060BB4: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80060BB8: jal         0x800693B0
    // 0x80060BBC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_17;
    // 0x80060BBC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_17:
    // 0x80060BC0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80060BC4: jal         0x80069500
    // 0x80060BC8: nop

    osStartThread_recomp(rdram, ctx);
        goto after_18;
    // 0x80060BC8: nop

    after_18:
    // 0x80060BCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80060BD0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80060BD4: jr          $ra
    // 0x80060BD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80060BD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80060BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060BDC: jr          $ra
    // 0x80060BE0: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    return;
    // 0x80060BE0: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
;}
RECOMP_FUNC void func_80060BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060BE4: jr          $ra
    // 0x80060BE8: addiu       $v0, $a0, 0x3C
    ctx->r2 = ADD32(ctx->r4, 0X3C);
    return;
    // 0x80060BE8: addiu       $v0, $a0, 0x3C
    ctx->r2 = ADD32(ctx->r4, 0X3C);
;}
RECOMP_FUNC void func_80060BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060BEC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80060BF0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80060BF4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80060BF8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80060BFC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80060C00: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80060C04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060C08: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80060C0C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80060C10: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80060C14: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80060C18: lui         $s2, 0x800F
    ctx->r18 = S32(0X800F << 16);
    // 0x80060C1C: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80060C20: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x80060C24: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x80060C28: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80060C2C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80060C30: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80060C34: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x80060C38: addiu       $s6, $s6, 0x58D8
    ctx->r22 = ADD32(ctx->r22, 0X58D8);
    // 0x80060C3C: addiu       $s5, $s5, -0x6760
    ctx->r21 = ADD32(ctx->r21, -0X6760);
    // 0x80060C40: addiu       $s4, $s4, 0x58DC
    ctx->r20 = ADD32(ctx->r20, 0X58DC);
    // 0x80060C44: addiu       $s3, $s3, 0x58D0
    ctx->r19 = ADD32(ctx->r19, 0X58D0);
    // 0x80060C48: addiu       $s2, $s2, -0x6300
    ctx->r18 = ADD32(ctx->r18, -0X6300);
    // 0x80060C4C: addiu       $s0, $s0, 0x58D4
    ctx->r16 = ADD32(ctx->r16, 0X58D4);
    // 0x80060C50: addiu       $s7, $a0, 0x74
    ctx->r23 = ADD32(ctx->r4, 0X74);
    // 0x80060C54: addiu       $fp, $sp, 0x5C
    ctx->r30 = ADD32(ctx->r29, 0X5C);
L_80060C58:
    // 0x80060C58: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80060C5C:
    // 0x80060C5C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80060C60: jal         0x80069CF0
    // 0x80060C64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80060C64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80060C68: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80060C6C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80060C70: addiu       $at, $zero, 0x29A
    ctx->r1 = ADD32(0, 0X29A);
    // 0x80060C74: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80060C78: beq         $t8, $at, L_80060C94
    if (ctx->r24 == ctx->r1) {
        // 0x80060C7C: sw          $t7, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r15;
            goto L_80060C94;
    }
    // 0x80060C7C: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80060C80: addiu       $at, $zero, 0x29D
    ctx->r1 = ADD32(0, 0X29D);
    // 0x80060C84: beq         $t8, $at, L_80060D6C
    if (ctx->r24 == ctx->r1) {
        // 0x80060C88: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80060D6C;
    }
    // 0x80060C88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80060C8C: b           L_80060C5C
    // 0x80060C90: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_80060C5C;
    // 0x80060C90: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80060C94:
    // 0x80060C94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80060C98: jal         0x80060EA4
    // 0x80060C9C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80060EA4(rdram, ctx);
        goto after_1;
    // 0x80060C9C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80060CA0: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x80060CA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80060CA8: bne         $v1, $zero, L_80060D58
    if (ctx->r3 != 0) {
        // 0x80060CAC: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_80060D58;
    }
    // 0x80060CAC: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x80060CB0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80060CB4: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x80060CB8: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x80060CBC: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80060CC0: andi        $t4, $t2, 0x3
    ctx->r12 = ctx->r10 & 0X3;
    // 0x80060CC4: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x80060CC8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80060CCC: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x80060CD0: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x80060CD4: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x80060CD8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80060CDC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80060CE0: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x80060CE4: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x80060CE8: sw          $t1, -0x62FC($at)
    MEM_W(-0X62FC, ctx->r1) = ctx->r9;
    // 0x80060CEC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80060CF0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80060CF4: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x80060CF8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80060CFC: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80060D00: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80060D04: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80060D08: jal         0x8006A690
    // 0x80060D0C: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    osGetTime_recomp(rdram, ctx);
        goto after_2;
    // 0x80060D0C: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    after_2:
    // 0x80060D10: lui         $a3, 0xF
    ctx->r7 = S32(0XF << 16);
    // 0x80060D14: ori         $a3, $a3, 0x4240
    ctx->r7 = ctx->r7 | 0X4240;
    // 0x80060D18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80060D1C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80060D20: jal         0x8006A888
    // 0x80060D24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    __ll_mul_recomp(rdram, ctx);
        goto after_3;
    // 0x80060D24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_3:
    // 0x80060D28: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80060D2C: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80060D30: lw          $a3, 0x5D34($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5D34);
    // 0x80060D34: lw          $a2, 0x5D30($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5D30);
    // 0x80060D38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80060D3C: jal         0x8006A788
    // 0x80060D40: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_4;
    // 0x80060D40: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_4:
    // 0x80060D44: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80060D48: nop

    // 0x80060D4C: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x80060D50: b           L_80060C58
    // 0x80060D54: sw          $v1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r3;
        goto L_80060C58;
    // 0x80060D54: sw          $v1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r3;
L_80060D58:
    // 0x80060D58: lw          $t1, 0x0($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X0);
    // 0x80060D5C: nop

    // 0x80060D60: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80060D64: b           L_80060C58
    // 0x80060D68: sw          $t2, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r10;
        goto L_80060C58;
    // 0x80060D68: sw          $t2, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r10;
L_80060D6C:
    // 0x80060D6C: jal         0x80060EA4
    // 0x80060D70: addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    func_80060EA4(rdram, ctx);
        goto after_5;
    // 0x80060D70: addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    after_5:
    // 0x80060D74: b           L_80060C5C
    // 0x80060D78: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_80060C5C;
    // 0x80060D78: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80060D7C: nop

    // 0x80060D80: nop

    // 0x80060D84: nop

    // 0x80060D88: nop

    // 0x80060D8C: nop

    // 0x80060D90: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80060D94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060D98: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80060D9C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80060DA0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80060DA4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80060DA8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80060DAC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80060DB0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80060DB4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80060DB8: jr          $ra
    // 0x80060DBC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80060DBC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80060DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060DC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060DC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80060DCC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80060DD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80060DD4: jal         0x8006A9E0
    // 0x80060DD8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80060DD8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80060DDC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80060DE0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80060DE4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80060DE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80060DEC: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80060DF0: lw          $t7, 0x668($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X668);
    // 0x80060DF4: nop

    // 0x80060DF8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80060DFC: jal         0x8006A9E0
    // 0x80060E00: sw          $a1, 0x668($v1)
    MEM_W(0X668, ctx->r3) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80060E00: sw          $a1, 0x668($v1)
    MEM_W(0X668, ctx->r3) = ctx->r5;
    after_1:
    // 0x80060E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060E08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060E0C: jr          $ra
    // 0x80060E10: nop

    return;
    // 0x80060E10: nop

;}
RECOMP_FUNC void func_80060E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060E14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80060E18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060E1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80060E20: lw          $v1, 0x668($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X668);
    // 0x80060E24: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80060E28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80060E2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80060E30: jal         0x8006A9E0
    // 0x80060E34: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80060E34: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80060E38: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80060E3C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80060E40: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80060E44: beq         $v1, $zero, L_80060E8C
    if (ctx->r3 == 0) {
        // 0x80060E48: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80060E8C;
    }
    // 0x80060E48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80060E4C:
    // 0x80060E4C: bne         $v1, $a1, L_80060E78
    if (ctx->r3 != ctx->r5) {
        // 0x80060E50: nop
    
            goto L_80060E78;
    }
    // 0x80060E50: nop

    // 0x80060E54: beq         $a2, $zero, L_80060E68
    if (ctx->r6 == 0) {
        // 0x80060E58: nop
    
            goto L_80060E68;
    }
    // 0x80060E58: nop

    // 0x80060E5C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80060E60: b           L_80060E8C
    // 0x80060E64: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
        goto L_80060E8C;
    // 0x80060E64: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_80060E68:
    // 0x80060E68: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80060E6C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80060E70: b           L_80060E8C
    // 0x80060E74: sw          $t8, 0x668($t9)
    MEM_W(0X668, ctx->r25) = ctx->r24;
        goto L_80060E8C;
    // 0x80060E74: sw          $t8, 0x668($t9)
    MEM_W(0X668, ctx->r25) = ctx->r24;
L_80060E78:
    // 0x80060E78: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80060E7C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80060E80: nop

    // 0x80060E84: bne         $v1, $zero, L_80060E4C
    if (ctx->r3 != 0) {
        // 0x80060E88: nop
    
            goto L_80060E4C;
    }
    // 0x80060E88: nop

L_80060E8C:
    // 0x80060E8C: jal         0x8006A9E0
    // 0x80060E90: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80060E90: nop

    after_1:
    // 0x80060E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060E98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80060E9C: jr          $ra
    // 0x80060EA0: nop

    return;
    // 0x80060EA0: nop

;}
RECOMP_FUNC void func_80060EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060EA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80060EA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060EAC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80060EB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80060EB4: lw          $s0, 0x668($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X668);
    // 0x80060EB8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80060EBC: beq         $s0, $zero, L_80060EE8
    if (ctx->r16 == 0) {
        // 0x80060EC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80060EE8;
    }
    // 0x80060EC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80060EC4:
    // 0x80060EC4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80060EC8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80060ECC: jal         0x8006A090
    // 0x80060ED0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80060ED0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80060ED4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80060ED8: nop

    // 0x80060EDC: bne         $s0, $zero, L_80060EC4
    if (ctx->r16 != 0) {
        // 0x80060EE0: nop
    
            goto L_80060EC4;
    }
    // 0x80060EE0: nop

    // 0x80060EE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80060EE8:
    // 0x80060EE8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80060EEC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80060EF0: jr          $ra
    // 0x80060EF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80060EF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80060EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060EF8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80060EFC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80060F00: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80060F04: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80060F08: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80060F0C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80060F10: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80060F14: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x80060F18: lui         $fp, 0x8008
    ctx->r30 = S32(0X8008 << 16);
    // 0x80060F1C: addiu       $a3, $a0, 0x4
    ctx->r7 = ADD32(ctx->r4, 0X4);
    // 0x80060F20: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80060F24: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80060F28: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80060F2C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80060F30: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80060F34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060F38: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x80060F3C: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x80060F40: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80060F44: addiu       $fp, $fp, 0x5D30
    ctx->r30 = ADD32(ctx->r30, 0X5D30);
    // 0x80060F48: addiu       $s5, $s5, -0x6300
    ctx->r21 = ADD32(ctx->r21, -0X6300);
    // 0x80060F4C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80060F50: addiu       $s6, $sp, 0x74
    ctx->r22 = ADD32(ctx->r29, 0X74);
    // 0x80060F54: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_80060F58:
    // 0x80060F58: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80060F5C: jal         0x80069CF0
    // 0x80060F60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80060F60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80060F64: jal         0x8006AA80
    // 0x80060F68: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_1;
    // 0x80060F68: nop

    after_1:
    // 0x80060F6C: lw          $s4, 0x66C($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X66C);
    // 0x80060F70: nop

    // 0x80060F74: beq         $s4, $zero, L_80060FAC
    if (ctx->r20 == 0) {
        // 0x80060F78: nop
    
            goto L_80060FAC;
    }
    // 0x80060F78: nop

    // 0x80060F7C: jal         0x8006AAB0
    // 0x80060F80: addiu       $s0, $s2, 0xAC
    ctx->r16 = ADD32(ctx->r18, 0XAC);
    osSpTaskYield_recomp(rdram, ctx);
        goto after_2;
    // 0x80060F80: addiu       $s0, $s2, 0xAC
    ctx->r16 = ADD32(ctx->r18, 0XAC);
    after_2:
    // 0x80060F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80060F88: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80060F8C: jal         0x80069CF0
    // 0x80060F90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80060F90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80060F94: jal         0x8006AAD0
    // 0x80060F98: addiu       $a0, $s4, 0x10
    ctx->r4 = ADD32(ctx->r20, 0X10);
    osSpTaskYielded_recomp(rdram, ctx);
        goto after_4;
    // 0x80060F98: addiu       $a0, $s4, 0x10
    ctx->r4 = ADD32(ctx->r20, 0X10);
    after_4:
    // 0x80060F9C: beq         $v0, $zero, L_80060FAC
    if (ctx->r2 == 0) {
        // 0x80060FA0: addiu       $s3, $zero, 0x2
        ctx->r19 = ADD32(0, 0X2);
            goto L_80060FAC;
    }
    // 0x80060FA0: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80060FA4: b           L_80060FAC
    // 0x80060FA8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80060FAC;
    // 0x80060FA8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80060FAC:
    // 0x80060FAC: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80060FB0: nop

    // 0x80060FB4: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x80060FB8: nop

    // 0x80060FBC: sltiu       $at, $v0, 0x4
    ctx->r1 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x80060FC0: beq         $at, $zero, L_8006102C
    if (ctx->r1 == 0) {
        // 0x80060FC4: lw          $t3, 0x70($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X70);
            goto L_8006102C;
    }
    // 0x80060FC4: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80060FC8: jal         0x8006A690
    // 0x80060FCC: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    osGetTime_recomp(rdram, ctx);
        goto after_5;
    // 0x80060FCC: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    after_5:
    // 0x80060FD0: lui         $a3, 0xF
    ctx->r7 = S32(0XF << 16);
    // 0x80060FD4: ori         $a3, $a3, 0x4240
    ctx->r7 = ctx->r7 | 0X4240;
    // 0x80060FD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80060FDC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80060FE0: jal         0x8006A888
    // 0x80060FE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    __ll_mul_recomp(rdram, ctx);
        goto after_6;
    // 0x80060FE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_6:
    // 0x80060FE8: lw          $a2, 0x0($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X0);
    // 0x80060FEC: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x80060FF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80060FF4: jal         0x8006A788
    // 0x80060FF8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_7;
    // 0x80060FF8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_7:
    // 0x80060FFC: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x80061000: sll         $t7, $s7, 3
    ctx->r15 = S32(ctx->r23 << 3);
    // 0x80061004: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x80061008: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x8006100C: addu        $t2, $a0, $t7
    ctx->r10 = ADD32(ctx->r4, ctx->r15);
    // 0x80061010: subu        $t0, $v0, $t8
    ctx->r8 = SUB32(ctx->r2, ctx->r24);
    // 0x80061014: sltu        $at, $v1, $t9
    ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
    // 0x80061018: subu        $t0, $t0, $at
    ctx->r8 = SUB32(ctx->r8, ctx->r1);
    // 0x8006101C: subu        $t1, $v1, $t9
    ctx->r9 = SUB32(ctx->r3, ctx->r25);
    // 0x80061020: sw          $t1, 0xD4($t2)
    MEM_W(0XD4, ctx->r10) = ctx->r9;
    // 0x80061024: sw          $t0, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->r8;
    // 0x80061028: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
L_8006102C:
    // 0x8006102C: addiu       $s0, $s2, 0xAC
    ctx->r16 = ADD32(ctx->r18, 0XAC);
    // 0x80061030: sw          $t3, 0x670($s2)
    MEM_W(0X670, ctx->r18) = ctx->r11;
    // 0x80061034: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80061038: jal         0x8006AC6C
    // 0x8006103C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_8;
    // 0x8006103C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_8:
    // 0x80061040: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80061044: jal         0x8006ADFC
    // 0x80061048: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_9;
    // 0x80061048: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_9:
    // 0x8006104C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061050: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80061054: jal         0x80069CF0
    // 0x80061058: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x80061058: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x8006105C: sw          $zero, 0x670($s2)
    MEM_W(0X670, ctx->r18) = 0;
    // 0x80061060: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x80061064: nop

    // 0x80061068: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8006106C: nop

    // 0x80061070: sltiu       $at, $t5, 0x4
    ctx->r1 = ctx->r13 < 0X4 ? 1 : 0;
    // 0x80061074: beq         $at, $zero, L_800610F4
    if (ctx->r1 == 0) {
        // 0x80061078: nop
    
            goto L_800610F4;
    }
    // 0x80061078: nop

    // 0x8006107C: jal         0x8006A690
    // 0x80061080: sll         $s1, $s7, 3
    ctx->r17 = S32(ctx->r23 << 3);
    osGetTime_recomp(rdram, ctx);
        goto after_11;
    // 0x80061080: sll         $s1, $s7, 3
    ctx->r17 = S32(ctx->r23 << 3);
    after_11:
    // 0x80061084: lui         $a3, 0xF
    ctx->r7 = S32(0XF << 16);
    // 0x80061088: ori         $a3, $a3, 0x4240
    ctx->r7 = ctx->r7 | 0X4240;
    // 0x8006108C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80061090: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80061094: jal         0x8006A888
    // 0x80061098: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    __ll_mul_recomp(rdram, ctx);
        goto after_12;
    // 0x80061098: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_12:
    // 0x8006109C: lw          $a2, 0x0($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X0);
    // 0x800610A0: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x800610A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800610A8: jal         0x8006A788
    // 0x800610AC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_13;
    // 0x800610AC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_13:
    // 0x800610B0: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x800610B4: nop

    // 0x800610B8: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800610BC: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x800610C0: addu        $t0, $a0, $s1
    ctx->r8 = ADD32(ctx->r4, ctx->r17);
    // 0x800610C4: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x800610C8: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x800610CC: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x800610D0: subu        $t9, $v1, $t7
    ctx->r25 = SUB32(ctx->r3, ctx->r15);
    // 0x800610D4: sw          $t9, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->r25;
    // 0x800610D8: sw          $t8, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->r24;
    // 0x800610DC: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x800610E0: nop

    // 0x800610E4: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x800610E8: nop

    // 0x800610EC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800610F0: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
L_800610F4:
    // 0x800610F4: lw          $t3, 0x674($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X674);
    // 0x800610F8: addiu       $a0, $s2, 0x11C
    ctx->r4 = ADD32(ctx->r18, 0X11C);
    // 0x800610FC: beq         $t3, $zero, L_8006110C
    if (ctx->r11 == 0) {
        // 0x80061100: or          $a1, $s6, $zero
        ctx->r5 = ctx->r22 | 0;
            goto L_8006110C;
    }
    // 0x80061100: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80061104: jal         0x8006A090
    // 0x80061108: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x80061108: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
L_8006110C:
    // 0x8006110C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80061110: bne         $s3, $at, L_80061138
    if (ctx->r19 != ctx->r1) {
        // 0x80061114: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80061138;
    }
    // 0x80061114: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80061118: addiu       $s0, $s4, 0x10
    ctx->r16 = ADD32(ctx->r20, 0X10);
    // 0x8006111C: jal         0x8006AC6C
    // 0x80061120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_15;
    // 0x80061120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80061124: jal         0x8006ADFC
    // 0x80061128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_16;
    // 0x80061128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8006112C: b           L_80061150
    // 0x80061130: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
        goto L_80061150;
    // 0x80061130: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80061134: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80061138:
    // 0x80061138: bne         $s3, $at, L_8006114C
    if (ctx->r19 != ctx->r1) {
        // 0x8006113C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8006114C;
    }
    // 0x8006113C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061140: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80061144: jal         0x8006A090
    // 0x80061148: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_17;
    // 0x80061148: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
L_8006114C:
    // 0x8006114C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
L_80061150:
    // 0x80061150: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80061154: lw          $a0, 0x50($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X50);
    // 0x80061158: lw          $a1, 0x54($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X54);
    // 0x8006115C: jal         0x8006A090
    // 0x80061160: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_18;
    // 0x80061160: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_18:
    // 0x80061164: b           L_80060F58
    // 0x80061168: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
        goto L_80060F58;
    // 0x80061168: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8006116C: nop

    // 0x80061170: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80061174: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80061178: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006117C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80061180: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80061184: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80061188: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8006118C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80061190: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80061194: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80061198: jr          $ra
    // 0x8006119C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8006119C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
