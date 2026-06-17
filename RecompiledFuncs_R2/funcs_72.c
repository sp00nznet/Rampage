#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_8006B754(uint8_t* rdram, recomp_context* ctx);
void func_8006C2E4(uint8_t* rdram, recomp_context* ctx);
void func_8006C3F8(uint8_t* rdram, recomp_context* ctx);
void func_8006C4BC(uint8_t* rdram, recomp_context* ctx);
void func_8006C584(uint8_t* rdram, recomp_context* ctx);
void func_8006CC40(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_8006B56C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B56C: jr          $ra
    // 0x8006B570: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006B570: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8006B574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B574: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006B578: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006B57C: lw          $t6, 0xE30($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE30);
    // 0x8006B580: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006B584: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006B588: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006B58C: lbu         $t7, 0x6($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X6);
    // 0x8006B590: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B594: beq         $t7, $zero, L_8006B69C
    if (ctx->r15 == 0) {
        // 0x8006B598: sw          $t7, 0x10E0($at)
        MEM_W(0X10E0, ctx->r1) = ctx->r15;
            goto L_8006B69C;
    }
    // 0x8006B598: sw          $t7, 0x10E0($at)
    MEM_W(0X10E0, ctx->r1) = ctx->r15;
    // 0x8006B59C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8006B5A0: lw          $t8, 0xE40($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE40);
    // 0x8006B5A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B5A8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006B5AC: sw          $t8, 0x10E4($at)
    MEM_W(0X10E4, ctx->r1) = ctx->r24;
    // 0x8006B5B0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8006B5B4: lw          $a0, 0xE3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE3C);
    // 0x8006B5B8: sw          $t9, 0x10E4($at)
    MEM_W(0X10E4, ctx->r1) = ctx->r25;
    // 0x8006B5BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B5C0: beq         $t8, $zero, L_8006B69C
    if (ctx->r24 == 0) {
        // 0x8006B5C4: sw          $a0, 0x10E8($at)
        MEM_W(0X10E8, ctx->r1) = ctx->r4;
            goto L_8006B69C;
    }
    // 0x8006B5C4: sw          $a0, 0x10E8($at)
    MEM_W(0X10E8, ctx->r1) = ctx->r4;
    // 0x8006B5C8: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8006B5CC: addiu       $s0, $s0, 0xE48
    ctx->r16 = ADD32(ctx->r16, 0XE48);
L_8006B5D0:
    // 0x8006B5D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006B5D4: nop

    // 0x8006B5D8: srl         $t0, $v0, 31
    ctx->r8 = S32(U32(ctx->r2) >> 31);
    // 0x8006B5DC: beq         $t0, $zero, L_8006B678
    if (ctx->r8 == 0) {
        // 0x8006B5E0: sll         $t2, $v0, 1
        ctx->r10 = S32(ctx->r2 << 1);
            goto L_8006B678;
    }
    // 0x8006B5E0: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x8006B5E4: bgez        $t2, L_8006B618
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8006B5E8: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8006B618;
    }
    // 0x8006B5E8: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8006B5EC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8006B5F0: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
    // 0x8006B5F4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8006B5F8: nop

    // 0x8006B5FC: sltu        $at, $t3, $t5
    ctx->r1 = ctx->r11 < ctx->r13 ? 1 : 0;
    // 0x8006B600: beq         $at, $zero, L_8006B618
    if (ctx->r1 == 0) {
        // 0x8006B604: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8006B618;
    }
    // 0x8006B604: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B608: jal         0x8006C2E4
    // 0x8006B60C: sw          $a0, 0x10E8($at)
    MEM_W(0X10E8, ctx->r1) = ctx->r4;
    func_8006C2E4(rdram, ctx);
        goto after_0;
    // 0x8006B60C: sw          $a0, 0x10E8($at)
    MEM_W(0X10E8, ctx->r1) = ctx->r4;
    after_0:
    // 0x8006B610: b           L_8006B658
    // 0x8006B614: nop

        goto L_8006B658;
    // 0x8006B614: nop

L_8006B618:
    // 0x8006B618: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B61C: bgez        $t7, L_8006B658
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8006B620: sw          $a0, 0x10E8($at)
        MEM_W(0X10E8, ctx->r1) = ctx->r4;
            goto L_8006B658;
    }
    // 0x8006B620: sw          $a0, 0x10E8($at)
    MEM_W(0X10E8, ctx->r1) = ctx->r4;
    // 0x8006B624: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B628: sw          $a0, 0x10E8($at)
    MEM_W(0X10E8, ctx->r1) = ctx->r4;
    // 0x8006B62C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8006B630: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8006B634: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x8006B638: lhu         $t0, 0xC($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0XC);
    // 0x8006B63C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8006B640: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8006B644: sltu        $at, $t1, $t4
    ctx->r1 = ctx->r9 < ctx->r12 ? 1 : 0;
    // 0x8006B648: beq         $at, $zero, L_8006B658
    if (ctx->r1 == 0) {
        // 0x8006B64C: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8006B658;
    }
    // 0x8006B64C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B650: jal         0x8006C584
    // 0x8006B654: sw          $a0, 0x10E8($at)
    MEM_W(0X10E8, ctx->r1) = ctx->r4;
    func_8006C584(rdram, ctx);
        goto after_1;
    // 0x8006B654: sw          $a0, 0x10E8($at)
    MEM_W(0X10E8, ctx->r1) = ctx->r4;
    after_1:
L_8006B658:
    // 0x8006B658: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8006B65C: lw          $t3, 0x10E0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X10E0);
    // 0x8006B660: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006B664: lw          $a0, 0x10E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10E8);
    // 0x8006B668: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B66C: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x8006B670: beq         $t5, $zero, L_8006B69C
    if (ctx->r13 == 0) {
        // 0x8006B674: sw          $t5, 0x10E0($at)
        MEM_W(0X10E0, ctx->r1) = ctx->r13;
            goto L_8006B69C;
    }
    // 0x8006B674: sw          $t5, 0x10E0($at)
    MEM_W(0X10E0, ctx->r1) = ctx->r13;
L_8006B678:
    // 0x8006B678: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006B67C: lw          $t6, 0x10E4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X10E4);
    // 0x8006B680: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B684: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8006B688: sw          $t7, 0x10E4($at)
    MEM_W(0X10E4, ctx->r1) = ctx->r15;
    // 0x8006B68C: bne         $t6, $zero, L_8006B5D0
    if (ctx->r14 != 0) {
        // 0x8006B690: addiu       $a0, $a0, 0x14
        ctx->r4 = ADD32(ctx->r4, 0X14);
            goto L_8006B5D0;
    }
    // 0x8006B690: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x8006B694: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B698: sw          $a0, 0x10E8($at)
    MEM_W(0X10E8, ctx->r1) = ctx->r4;
L_8006B69C:
    // 0x8006B69C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B6A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006B6A4: jr          $ra
    // 0x8006B6A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006B6A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006B6AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B6AC: jr          $ra
    // 0x8006B6B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006B6B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8006B6B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B6B4: jr          $ra
    // 0x8006B6B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006B6B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8006B6BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B6BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B6C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B6C4: lbu         $t6, 0x2($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2);
    // 0x8006B6C8: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8006B6CC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006B6D0: lw          $t8, 0xE34($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE34);
    // 0x8006B6D4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006B6D8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8006B6DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B6E0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B6E4: sw          $v0, 0x10EC($at)
    MEM_W(0X10EC, ctx->r1) = ctx->r2;
    // 0x8006B6E8: jal         0x8006B754
    // 0x8006B6EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8006B754(rdram, ctx);
        goto after_0;
    // 0x8006B6EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006B6F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006B6F4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006B6F8: lbu         $t9, 0x11($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X11);
    // 0x8006B6FC: nop

    // 0x8006B700: beq         $t9, $zero, L_8006B73C
    if (ctx->r25 == 0) {
        // 0x8006B704: nop
    
            goto L_8006B73C;
    }
    // 0x8006B704: nop

    // 0x8006B708: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    // 0x8006B70C: lw          $v0, 0x10EC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10EC);
    // 0x8006B710: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x8006B714: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x8006B718: lbu         $t3, 0x5($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X5);
    // 0x8006B71C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B720: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8006B724: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8006B728: bne         $t5, $zero, L_8006B744
    if (ctx->r13 != 0) {
        // 0x8006B72C: sb          $t4, 0x5($v0)
        MEM_B(0X5, ctx->r2) = ctx->r12;
            goto L_8006B744;
    }
    // 0x8006B72C: sb          $t4, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r12;
    // 0x8006B730: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8006B734: b           L_8006B744
    // 0x8006B738: sw          $v0, 0x10EC($at)
    MEM_W(0X10EC, ctx->r1) = ctx->r2;
        goto L_8006B744;
    // 0x8006B738: sw          $v0, 0x10EC($at)
    MEM_W(0X10EC, ctx->r1) = ctx->r2;
L_8006B73C:
    // 0x8006B73C: jal         0x8006961C
    // 0x8006B740: nop

    func_8006961C(rdram, ctx);
        goto after_1;
    // 0x8006B740: nop

    after_1:
L_8006B744:
    // 0x8006B744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B74C: jr          $ra
    // 0x8006B750: nop

    return;
    // 0x8006B750: nop

;}
RECOMP_FUNC void func_8006B754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B754: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8006B758: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8006B75C: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8006B760: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8006B764: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8006B768: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8006B76C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8006B770: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8006B774: lbu         $v0, 0x11($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X11);
    // 0x8006B778: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B77C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8006B780: beq         $v0, $zero, L_8006B8D4
    if (ctx->r2 == 0) {
        // 0x8006B784: sw          $v0, 0x10F0($at)
        MEM_W(0X10F0, ctx->r1) = ctx->r2;
            goto L_8006B8D4;
    }
    // 0x8006B784: sw          $v0, 0x10F0($at)
    MEM_W(0X10F0, ctx->r1) = ctx->r2;
    // 0x8006B788: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006B78C: lw          $t6, 0xE40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE40);
    // 0x8006B790: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B794: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8006B798: sw          $t6, 0x10F4($at)
    MEM_W(0X10F4, ctx->r1) = ctx->r14;
    // 0x8006B79C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8006B7A0: lw          $s0, 0xE3C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XE3C);
    // 0x8006B7A4: sw          $t7, 0x10F4($at)
    MEM_W(0X10F4, ctx->r1) = ctx->r15;
    // 0x8006B7A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B7AC: beq         $t6, $zero, L_8006B8D4
    if (ctx->r14 == 0) {
        // 0x8006B7B0: sw          $s0, 0x10F8($at)
        MEM_W(0X10F8, ctx->r1) = ctx->r16;
            goto L_8006B8D4;
    }
    // 0x8006B7B0: sw          $s0, 0x10F8($at)
    MEM_W(0X10F8, ctx->r1) = ctx->r16;
    // 0x8006B7B4: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x8006B7B8: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8006B7BC: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8006B7C0: addiu       $s2, $s2, 0xE7C
    ctx->r18 = ADD32(ctx->r18, 0XE7C);
    // 0x8006B7C4: addiu       $s4, $s4, 0xE34
    ctx->r20 = ADD32(ctx->r20, 0XE34);
    // 0x8006B7C8: addiu       $s5, $s5, 0xE78
    ctx->r21 = ADD32(ctx->r21, 0XE78);
    // 0x8006B7CC: addiu       $s3, $zero, 0x18
    ctx->r19 = ADD32(0, 0X18);
L_8006B7D0:
    // 0x8006B7D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006B7D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B7D8: srl         $t8, $v0, 31
    ctx->r24 = S32(U32(ctx->r2) >> 31);
    // 0x8006B7DC: beq         $t8, $zero, L_8006B8A8
    if (ctx->r24 == 0) {
        // 0x8006B7E0: sw          $s0, 0x10F8($at)
        MEM_W(0X10F8, ctx->r1) = ctx->r16;
            goto L_8006B8A8;
    }
    // 0x8006B7E0: sw          $s0, 0x10F8($at)
    MEM_W(0X10F8, ctx->r1) = ctx->r16;
    // 0x8006B7E4: lbu         $v1, 0x3($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X3);
    // 0x8006B7E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B7EC: sw          $s0, 0x10F8($at)
    MEM_W(0X10F8, ctx->r1) = ctx->r16;
    // 0x8006B7F0: lbu         $t9, 0x1($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X1);
    // 0x8006B7F4: nop

    // 0x8006B7F8: bne         $t9, $v1, L_8006B8A8
    if (ctx->r25 != ctx->r3) {
        // 0x8006B7FC: nop
    
            goto L_8006B8A8;
    }
    // 0x8006B7FC: nop

    // 0x8006B800: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8006B804: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x8006B808: beq         $t0, $zero, L_8006B87C
    if (ctx->r8 == 0) {
        // 0x8006B80C: nop
    
            goto L_8006B87C;
    }
    // 0x8006B80C: nop

    // 0x8006B810: bltz        $t2, L_8006B87C
    if (SIGNED(ctx->r10) < 0) {
        // 0x8006B814: nop
    
            goto L_8006B87C;
    }
    // 0x8006B814: nop

    // 0x8006B818: lbu         $t3, 0x7($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X7);
    // 0x8006B81C: nop

    // 0x8006B820: bne         $t3, $zero, L_8006B87C
    if (ctx->r11 != 0) {
        // 0x8006B824: nop
    
            goto L_8006B87C;
    }
    // 0x8006B824: nop

    // 0x8006B828: lbu         $t4, 0x2($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X2);
    // 0x8006B82C: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8006B830: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006B834: lbu         $t8, 0x6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6);
    // 0x8006B838: lbu         $a3, 0x5($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X5);
    // 0x8006B83C: sll         $a2, $v1, 16
    ctx->r6 = S32(ctx->r3 << 16);
    // 0x8006B840: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006B844: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B848: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8006B84C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006B850: mflo        $t5
    ctx->r13 = lo;
    // 0x8006B854: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8006B858: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x8006B85C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8006B860: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8006B864: nop

    // 0x8006B868: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8006B86C: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x8006B870: sw          $v0, 0x10FC($at)
    MEM_W(0X10FC, ctx->r1) = ctx->r2;
    // 0x8006B874: jal         0x8006ADA8
    // 0x8006B878: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_8006ADA8(rdram, ctx);
        goto after_0;
    // 0x8006B878: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
L_8006B87C:
    // 0x8006B87C: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x8006B880: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B884: sw          $s0, 0x10F8($at)
    MEM_W(0X10F8, ctx->r1) = ctx->r16;
    // 0x8006B888: jal         0x8006C3F8
    // 0x8006B88C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006C3F8(rdram, ctx);
        goto after_1;
    // 0x8006B88C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8006B890: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006B894: lw          $v0, 0x10F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10F0);
    // 0x8006B898: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B89C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006B8A0: beq         $v0, $zero, L_8006B8D4
    if (ctx->r2 == 0) {
        // 0x8006B8A4: sw          $v0, 0x10F0($at)
        MEM_W(0X10F0, ctx->r1) = ctx->r2;
            goto L_8006B8D4;
    }
    // 0x8006B8A4: sw          $v0, 0x10F0($at)
    MEM_W(0X10F0, ctx->r1) = ctx->r2;
L_8006B8A8:
    // 0x8006B8A8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8006B8AC: lw          $t1, 0x10F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X10F4);
    // 0x8006B8B0: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8006B8B4: lw          $s0, 0x10F8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10F8);
    // 0x8006B8B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B8BC: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8006B8C0: sw          $t2, 0x10F4($at)
    MEM_W(0X10F4, ctx->r1) = ctx->r10;
    // 0x8006B8C4: bne         $t1, $zero, L_8006B7D0
    if (ctx->r9 != 0) {
        // 0x8006B8C8: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_8006B7D0;
    }
    // 0x8006B8C8: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8006B8CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B8D0: sw          $s0, 0x10F8($at)
    MEM_W(0X10F8, ctx->r1) = ctx->r16;
L_8006B8D4:
    // 0x8006B8D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8006B8D8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8006B8DC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8006B8E0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8006B8E4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8006B8E8: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8006B8EC: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8006B8F0: jr          $ra
    // 0x8006B8F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8006B8F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8006B8F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B8F8: lw          $v1, 0x34($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X34);
    // 0x8006B8FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B900: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x8006B904: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x8006B908: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8006B90C: or          $t0, $t6, $t8
    ctx->r8 = ctx->r14 | ctx->r24;
    // 0x8006B910: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    // 0x8006B914: jr          $ra
    // 0x8006B918: sh          $t0, 0x1100($at)
    MEM_H(0X1100, ctx->r1) = ctx->r8;
    return;
    // 0x8006B918: sh          $t0, 0x1100($at)
    MEM_H(0X1100, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void func_8006B91C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B91C: jr          $ra
    // 0x8006B920: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006B920: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8006B924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B924: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006B928: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006B92C: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8006B930: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8006B934: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8006B938: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8006B93C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8006B940: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8006B944: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8006B948: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8006B94C: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x8006B950: lh          $t1, 0x6($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X6);
    // 0x8006B954: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x8006B958: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x8006B95C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8006B960: or          $v1, $t6, $t8
    ctx->r3 = ctx->r14 | ctx->r24;
    // 0x8006B964: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8006B968: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8006B96C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8006B970: bne         $t0, $t1, L_8006B984
    if (ctx->r8 != ctx->r9) {
        // 0x8006B974: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_8006B984;
    }
    // 0x8006B974: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8006B978: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B97C: b           L_8006BB9C
    // 0x8006B980: sh          $t0, 0x1110($at)
    MEM_H(0X1110, ctx->r1) = ctx->r8;
        goto L_8006BB9C;
    // 0x8006B980: sh          $t0, 0x1110($at)
    MEM_H(0X1110, ctx->r1) = ctx->r8;
L_8006B984:
    // 0x8006B984: lbu         $v0, 0x11($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X11);
    // 0x8006B988: sh          $v1, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r3;
    // 0x8006B98C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B990: sw          $v0, 0x1104($at)
    MEM_W(0X1104, ctx->r1) = ctx->r2;
    // 0x8006B994: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B998: beq         $v0, $zero, L_8006BB9C
    if (ctx->r2 == 0) {
        // 0x8006B99C: sh          $v1, 0x1110($at)
        MEM_H(0X1110, ctx->r1) = ctx->r3;
            goto L_8006BB9C;
    }
    // 0x8006B99C: sh          $v1, 0x1110($at)
    MEM_H(0X1110, ctx->r1) = ctx->r3;
    // 0x8006B9A0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8006B9A4: lw          $t2, 0xE40($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE40);
    // 0x8006B9A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B9AC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8006B9B0: sw          $t2, 0x1108($at)
    MEM_W(0X1108, ctx->r1) = ctx->r10;
    // 0x8006B9B4: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8006B9B8: lw          $s0, 0xE3C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XE3C);
    // 0x8006B9BC: sw          $t3, 0x1108($at)
    MEM_W(0X1108, ctx->r1) = ctx->r11;
    // 0x8006B9C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B9C4: beq         $t2, $zero, L_8006BB9C
    if (ctx->r10 == 0) {
        // 0x8006B9C8: sw          $s0, 0x110C($at)
        MEM_W(0X110C, ctx->r1) = ctx->r16;
            goto L_8006BB9C;
    }
    // 0x8006B9C8: sw          $s0, 0x110C($at)
    MEM_W(0X110C, ctx->r1) = ctx->r16;
    // 0x8006B9CC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8006B9D0: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x8006B9D4: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8006B9D8: lwc1        $f21, 0x2090($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, 0X2090);
    // 0x8006B9DC: lwc1        $f20, 0x2094($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X2094);
    // 0x8006B9E0: addiu       $s3, $s3, 0x1040
    ctx->r19 = ADD32(ctx->r19, 0X1040);
    // 0x8006B9E4: addiu       $s5, $s5, -0x17E0
    ctx->r21 = ADD32(ctx->r21, -0X17E0);
    // 0x8006B9E8: addiu       $s4, $zero, 0x1C
    ctx->r20 = ADD32(0, 0X1C);
    // 0x8006B9EC: addiu       $s2, $zero, 0x64
    ctx->r18 = ADD32(0, 0X64);
L_8006B9F0:
    // 0x8006B9F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B9F4: sw          $s0, 0x110C($at)
    MEM_W(0X110C, ctx->r1) = ctx->r16;
    // 0x8006B9F8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8006B9FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BA00: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x8006BA04: beq         $t5, $zero, L_8006BB70
    if (ctx->r13 == 0) {
        // 0x8006BA08: nop
    
            goto L_8006BB70;
    }
    // 0x8006BA08: nop

    // 0x8006BA0C: sw          $s0, 0x110C($at)
    MEM_W(0X110C, ctx->r1) = ctx->r16;
    // 0x8006BA10: lbu         $t6, 0x3($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X3);
    // 0x8006BA14: lbu         $t7, 0x1($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1);
    // 0x8006BA18: nop

    // 0x8006BA1C: bne         $t7, $t6, L_8006BB70
    if (ctx->r15 != ctx->r14) {
        // 0x8006BA20: nop
    
            goto L_8006BB70;
    }
    // 0x8006BA20: nop

    // 0x8006BA24: lh          $v1, 0x6($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X6);
    // 0x8006BA28: nop

    // 0x8006BA2C: bne         $v1, $zero, L_8006BA40
    if (ctx->r3 != 0) {
        // 0x8006BA30: nop
    
            goto L_8006BA40;
    }
    // 0x8006BA30: nop

    // 0x8006BA34: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8006BA38: b           L_8006BAEC
    // 0x8006BA3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8006BAEC;
    // 0x8006BA3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8006BA40:
    // 0x8006BA40: blez        $v1, L_8006BA9C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8006BA44: nop
    
            goto L_8006BA9C;
    }
    // 0x8006BA44: nop

    // 0x8006BA48: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8006BA4C: nop

    // 0x8006BA50: lb          $t8, 0x9($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X9);
    // 0x8006BA54: nop

    // 0x8006BA58: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BA5C: mflo        $t9
    ctx->r25 = lo;
    // 0x8006BA60: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8006BA64: nop

    // 0x8006BA68: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8006BA6C: mul.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x8006BA70: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8006BA74: nop

    // 0x8006BA78: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8006BA7C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006BA80: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006BA84: nop

    // 0x8006BA88: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x8006BA8C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8006BA90: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8006BA94: b           L_8006BAF0
    // 0x8006BA98: lbu         $t4, 0x5($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X5);
        goto L_8006BAF0;
    // 0x8006BA98: lbu         $t4, 0x5($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X5);
L_8006BA9C:
    // 0x8006BA9C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8006BAA0: nop

    // 0x8006BAA4: lb          $t1, 0x8($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X8);
    // 0x8006BAA8: nop

    // 0x8006BAAC: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BAB0: mflo        $t2
    ctx->r10 = lo;
    // 0x8006BAB4: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8006BAB8: nop

    // 0x8006BABC: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8006BAC0: mul.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f20.d);
    // 0x8006BAC4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8006BAC8: nop

    // 0x8006BACC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8006BAD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006BAD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006BAD8: nop

    // 0x8006BADC: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x8006BAE0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8006BAE4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8006BAE8: nop

L_8006BAEC:
    // 0x8006BAEC: lbu         $t4, 0x5($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X5);
L_8006BAF0:
    // 0x8006BAF0: lbu         $t5, 0x4($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4);
    // 0x8006BAF4: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8006BAF8: subu        $t7, $t4, $t5
    ctx->r15 = SUB32(ctx->r12, ctx->r13);
    // 0x8006BAFC: multu       $t7, $s2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BB00: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x8006BB04: lb          $t2, 0x5($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X5);
    // 0x8006BB08: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x8006BB0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BB10: sw          $a1, 0x1118($at)
    MEM_W(0X1118, ctx->r1) = ctx->r5;
    // 0x8006BB14: mflo        $t6
    ctx->r14 = lo;
    // 0x8006BB18: addu        $t1, $t0, $t6
    ctx->r9 = ADD32(ctx->r8, ctx->r14);
    // 0x8006BB1C: jal         0x8006AF00
    // 0x8006BB20: subu        $a0, $t1, $t2
    ctx->r4 = SUB32(ctx->r9, ctx->r10);
    func_8006AF00(rdram, ctx);
        goto after_0;
    // 0x8006BB20: subu        $a0, $t1, $t2
    ctx->r4 = SUB32(ctx->r9, ctx->r10);
    after_0:
    // 0x8006BB24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BB28: swc1        $f0, 0x1114($at)
    MEM_W(0X1114, ctx->r1) = ctx->f0.u32l;
    // 0x8006BB2C: lbu         $t3, 0x2($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2);
    // 0x8006BB30: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8006BB34: multu       $t3, $s4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BB38: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8006BB3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BB40: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006BB44: sw          $s0, 0x110C($at)
    MEM_W(0X110C, ctx->r1) = ctx->r16;
    // 0x8006BB48: mflo        $t4
    ctx->r12 = lo;
    // 0x8006BB4C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x8006BB50: jal         0x80071B30
    // 0x8006BB54: nop

    func_80071B30(rdram, ctx);
        goto after_1;
    // 0x8006BB54: nop

    after_1:
    // 0x8006BB58: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006BB5C: lw          $v0, 0x1104($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1104);
    // 0x8006BB60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BB64: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006BB68: beq         $v0, $zero, L_8006BB9C
    if (ctx->r2 == 0) {
        // 0x8006BB6C: sw          $v0, 0x1104($at)
        MEM_W(0X1104, ctx->r1) = ctx->r2;
            goto L_8006BB9C;
    }
    // 0x8006BB6C: sw          $v0, 0x1104($at)
    MEM_W(0X1104, ctx->r1) = ctx->r2;
L_8006BB70:
    // 0x8006BB70: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006BB74: lw          $t7, 0x1108($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1108);
    // 0x8006BB78: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8006BB7C: lw          $s0, 0x110C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X110C);
    // 0x8006BB80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BB84: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8006BB88: sw          $t8, 0x1108($at)
    MEM_W(0X1108, ctx->r1) = ctx->r24;
    // 0x8006BB8C: bne         $t7, $zero, L_8006B9F0
    if (ctx->r15 != 0) {
        // 0x8006BB90: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_8006B9F0;
    }
    // 0x8006BB90: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8006BB94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BB98: sw          $s0, 0x110C($at)
    MEM_W(0X110C, ctx->r1) = ctx->r16;
L_8006BB9C:
    // 0x8006BB9C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006BBA0: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8006BBA4: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8006BBA8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8006BBAC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8006BBB0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8006BBB4: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8006BBB8: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8006BBBC: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8006BBC0: jr          $ra
    // 0x8006BBC4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006BBC4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006BBC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BBC8: jr          $ra
    // 0x8006BBCC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006BBCC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8006BBD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BBD0: jr          $ra
    // 0x8006BBD4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006BBD4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8006BBD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BBD8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006BBDC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006BBE0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8006BBE4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8006BBE8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006BBEC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006BBF0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006BBF4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006BBF8: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x8006BBFC: lbu         $t7, 0xD($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XD);
    // 0x8006BC00: lbu         $v1, 0x1($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X1);
    // 0x8006BC04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006BC08: bne         $v1, $t7, L_8006BC1C
    if (ctx->r3 != ctx->r15) {
        // 0x8006BC0C: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8006BC1C;
    }
    // 0x8006BC0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BC10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BC14: b           L_8006BDD8
    // 0x8006BC18: sb          $v1, 0x112C($at)
    MEM_B(0X112C, ctx->r1) = ctx->r3;
        goto L_8006BDD8;
    // 0x8006BC18: sb          $v1, 0x112C($at)
    MEM_B(0X112C, ctx->r1) = ctx->r3;
L_8006BC1C:
    // 0x8006BC1C: lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X11);
    // 0x8006BC20: sb          $v1, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r3;
    // 0x8006BC24: sw          $v0, 0x111C($at)
    MEM_W(0X111C, ctx->r1) = ctx->r2;
    // 0x8006BC28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BC2C: beq         $v0, $zero, L_8006BDD8
    if (ctx->r2 == 0) {
        // 0x8006BC30: sb          $v1, 0x112C($at)
        MEM_B(0X112C, ctx->r1) = ctx->r3;
            goto L_8006BDD8;
    }
    // 0x8006BC30: sb          $v1, 0x112C($at)
    MEM_B(0X112C, ctx->r1) = ctx->r3;
    // 0x8006BC34: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8006BC38: lw          $t8, 0xE40($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE40);
    // 0x8006BC3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BC40: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006BC44: sw          $t8, 0x1120($at)
    MEM_W(0X1120, ctx->r1) = ctx->r24;
    // 0x8006BC48: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8006BC4C: lw          $v0, 0xE3C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XE3C);
    // 0x8006BC50: sw          $t9, 0x1120($at)
    MEM_W(0X1120, ctx->r1) = ctx->r25;
    // 0x8006BC54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BC58: beq         $t8, $zero, L_8006BDD8
    if (ctx->r24 == 0) {
        // 0x8006BC5C: sw          $v0, 0x1128($at)
        MEM_W(0X1128, ctx->r1) = ctx->r2;
            goto L_8006BDD8;
    }
    // 0x8006BC5C: sw          $v0, 0x1128($at)
    MEM_W(0X1128, ctx->r1) = ctx->r2;
    // 0x8006BC60: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x8006BC64: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8006BC68: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8006BC6C: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8006BC70: addiu       $s1, $s1, 0xE6C
    ctx->r17 = ADD32(ctx->r17, 0XE6C);
    // 0x8006BC74: addiu       $s2, $s2, 0x1040
    ctx->r18 = ADD32(ctx->r18, 0X1040);
    // 0x8006BC78: addiu       $s4, $s4, -0x17E0
    ctx->r20 = ADD32(ctx->r20, -0X17E0);
    // 0x8006BC7C: addiu       $s5, $s5, 0xE70
    ctx->r21 = ADD32(ctx->r21, 0XE70);
    // 0x8006BC80: addiu       $s3, $zero, 0x1C
    ctx->r19 = ADD32(0, 0X1C);
L_8006BC84:
    // 0x8006BC84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BC88: sw          $v0, 0x1128($at)
    MEM_W(0X1128, ctx->r1) = ctx->r2;
    // 0x8006BC8C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8006BC90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BC94: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x8006BC98: beq         $t1, $zero, L_8006BDAC
    if (ctx->r9 == 0) {
        // 0x8006BC9C: nop
    
            goto L_8006BDAC;
    }
    // 0x8006BC9C: nop

    // 0x8006BCA0: sw          $v0, 0x1128($at)
    MEM_W(0X1128, ctx->r1) = ctx->r2;
    // 0x8006BCA4: lbu         $t3, 0x3($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X3);
    // 0x8006BCA8: lbu         $t2, 0x1($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1);
    // 0x8006BCAC: nop

    // 0x8006BCB0: bne         $t2, $t3, L_8006BDAC
    if (ctx->r10 != ctx->r11) {
        // 0x8006BCB4: nop
    
            goto L_8006BDAC;
    }
    // 0x8006BCB4: nop

    // 0x8006BCB8: lbu         $t4, 0x3($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X3);
    // 0x8006BCBC: nop

    // 0x8006BCC0: bne         $t4, $zero, L_8006BD10
    if (ctx->r12 != 0) {
        // 0x8006BCC4: nop
    
            goto L_8006BD10;
    }
    // 0x8006BCC4: nop

    // 0x8006BCC8: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8006BCCC: lbu         $t5, 0x6($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X6);
    // 0x8006BCD0: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x8006BCD4: lbu         $t9, 0xD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XD);
    // 0x8006BCD8: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BCDC: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x8006BCE0: mflo        $t8
    ctx->r24 = lo;
    // 0x8006BCE4: nop

    // 0x8006BCE8: nop

    // 0x8006BCEC: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BCF0: mflo        $t0
    ctx->r8 = lo;
    // 0x8006BCF4: nop

    // 0x8006BCF8: nop

    // 0x8006BCFC: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BD00: mflo        $v1
    ctx->r3 = lo;
    // 0x8006BD04: srl         $t2, $v1, 13
    ctx->r10 = S32(U32(ctx->r3) >> 13);
    // 0x8006BD08: b           L_8006BD54
    // 0x8006BD0C: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
        goto L_8006BD54;
    // 0x8006BD0C: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_8006BD10:
    // 0x8006BD10: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x8006BD14: lbu         $t3, 0x6($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X6);
    // 0x8006BD18: lbu         $t6, 0x1($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X1);
    // 0x8006BD1C: lbu         $t7, 0xD($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XD);
    // 0x8006BD20: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BD24: lbu         $t9, 0x0($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X0);
    // 0x8006BD28: mflo        $t5
    ctx->r13 = lo;
    // 0x8006BD2C: nop

    // 0x8006BD30: nop

    // 0x8006BD34: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BD38: mflo        $t8
    ctx->r24 = lo;
    // 0x8006BD3C: nop

    // 0x8006BD40: nop

    // 0x8006BD44: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BD48: mflo        $v1
    ctx->r3 = lo;
    // 0x8006BD4C: srl         $t0, $v1, 13
    ctx->r8 = S32(U32(ctx->r3) >> 13);
    // 0x8006BD50: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_8006BD54:
    // 0x8006BD54: lbu         $t1, 0x2($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2);
    // 0x8006BD58: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x8006BD5C: multu       $t1, $s3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BD60: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8006BD64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BD68: sw          $v0, 0x1128($at)
    MEM_W(0X1128, ctx->r1) = ctx->r2;
    // 0x8006BD6C: sll         $a2, $v1, 16
    ctx->r6 = S32(ctx->r3 << 16);
    // 0x8006BD70: sra         $t3, $a2, 16
    ctx->r11 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006BD74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BD78: sw          $v1, 0x1124($at)
    MEM_W(0X1124, ctx->r1) = ctx->r3;
    // 0x8006BD7C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8006BD80: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x8006BD84: mflo        $t2
    ctx->r10 = lo;
    // 0x8006BD88: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    // 0x8006BD8C: jal         0x80071BC0
    // 0x8006BD90: nop

    func_80071BC0(rdram, ctx);
        goto after_0;
    // 0x8006BD90: nop

    after_0:
    // 0x8006BD94: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006BD98: lw          $v0, 0x111C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X111C);
    // 0x8006BD9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BDA0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006BDA4: beq         $v0, $zero, L_8006BDD8
    if (ctx->r2 == 0) {
        // 0x8006BDA8: sw          $v0, 0x111C($at)
        MEM_W(0X111C, ctx->r1) = ctx->r2;
            goto L_8006BDD8;
    }
    // 0x8006BDA8: sw          $v0, 0x111C($at)
    MEM_W(0X111C, ctx->r1) = ctx->r2;
L_8006BDAC:
    // 0x8006BDAC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006BDB0: lw          $t6, 0x1120($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1120);
    // 0x8006BDB4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006BDB8: lw          $v0, 0x1128($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1128);
    // 0x8006BDBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BDC0: addiu       $t5, $t6, -0x1
    ctx->r13 = ADD32(ctx->r14, -0X1);
    // 0x8006BDC4: sw          $t5, 0x1120($at)
    MEM_W(0X1120, ctx->r1) = ctx->r13;
    // 0x8006BDC8: bne         $t6, $zero, L_8006BC84
    if (ctx->r14 != 0) {
        // 0x8006BDCC: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_8006BC84;
    }
    // 0x8006BDCC: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x8006BDD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BDD4: sw          $v0, 0x1128($at)
    MEM_W(0X1128, ctx->r1) = ctx->r2;
L_8006BDD8:
    // 0x8006BDD8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006BDDC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006BDE0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006BDE4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006BDE8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006BDEC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8006BDF0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8006BDF4: jr          $ra
    // 0x8006BDF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006BDF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006BDFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BDFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006BE00: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006BE04: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006BE08: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006BE0C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006BE10: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006BE14: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x8006BE18: lbu         $t7, 0xE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XE);
    // 0x8006BE1C: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
    // 0x8006BE20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006BE24: bne         $v0, $t7, L_8006BE38
    if (ctx->r2 != ctx->r15) {
        // 0x8006BE28: lui         $t8, 0x8009
        ctx->r24 = S32(0X8009 << 16);
            goto L_8006BE38;
    }
    // 0x8006BE28: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8006BE2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BE30: b           L_8006BF84
    // 0x8006BE34: sb          $v0, 0x113E($at)
    MEM_B(0X113E, ctx->r1) = ctx->r2;
        goto L_8006BF84;
    // 0x8006BE34: sb          $v0, 0x113E($at)
    MEM_B(0X113E, ctx->r1) = ctx->r2;
L_8006BE38:
    // 0x8006BE38: sb          $v0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r2;
    // 0x8006BE3C: lbu         $t8, 0xE74($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0XE74);
    // 0x8006BE40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BE44: beq         $t8, $zero, L_8006BF84
    if (ctx->r24 == 0) {
        // 0x8006BE48: sb          $v0, 0x113E($at)
        MEM_B(0X113E, ctx->r1) = ctx->r2;
            goto L_8006BF84;
    }
    // 0x8006BE48: sb          $v0, 0x113E($at)
    MEM_B(0X113E, ctx->r1) = ctx->r2;
    // 0x8006BE4C: lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X11);
    // 0x8006BE50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BE54: beq         $v0, $zero, L_8006BF84
    if (ctx->r2 == 0) {
        // 0x8006BE58: sw          $v0, 0x1130($at)
        MEM_W(0X1130, ctx->r1) = ctx->r2;
            goto L_8006BF84;
    }
    // 0x8006BE58: sw          $v0, 0x1130($at)
    MEM_W(0X1130, ctx->r1) = ctx->r2;
    // 0x8006BE5C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8006BE60: lw          $t9, 0xE40($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE40);
    // 0x8006BE64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BE68: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8006BE6C: sw          $t9, 0x1134($at)
    MEM_W(0X1134, ctx->r1) = ctx->r25;
    // 0x8006BE70: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8006BE74: lw          $v1, 0xE3C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XE3C);
    // 0x8006BE78: sw          $t0, 0x1134($at)
    MEM_W(0X1134, ctx->r1) = ctx->r8;
    // 0x8006BE7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BE80: beq         $t9, $zero, L_8006BF84
    if (ctx->r25 == 0) {
        // 0x8006BE84: sw          $v1, 0x1138($at)
        MEM_W(0X1138, ctx->r1) = ctx->r3;
            goto L_8006BF84;
    }
    // 0x8006BE84: sw          $v1, 0x1138($at)
    MEM_W(0X1138, ctx->r1) = ctx->r3;
    // 0x8006BE88: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x8006BE8C: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8006BE90: addiu       $s1, $s1, 0x1040
    ctx->r17 = ADD32(ctx->r17, 0X1040);
    // 0x8006BE94: addiu       $s3, $s3, -0x17E0
    ctx->r19 = ADD32(ctx->r19, -0X17E0);
    // 0x8006BE98: addiu       $s2, $zero, 0x1C
    ctx->r18 = ADD32(0, 0X1C);
L_8006BE9C:
    // 0x8006BE9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BEA0: sw          $v1, 0x1138($at)
    MEM_W(0X1138, ctx->r1) = ctx->r3;
    // 0x8006BEA4: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8006BEA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BEAC: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x8006BEB0: beq         $t2, $zero, L_8006BF58
    if (ctx->r10 == 0) {
        // 0x8006BEB4: nop
    
            goto L_8006BF58;
    }
    // 0x8006BEB4: nop

    // 0x8006BEB8: sw          $v1, 0x1138($at)
    MEM_W(0X1138, ctx->r1) = ctx->r3;
    // 0x8006BEBC: lbu         $t4, 0x3($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X3);
    // 0x8006BEC0: lbu         $t3, 0x1($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1);
    // 0x8006BEC4: nop

    // 0x8006BEC8: bne         $t3, $t4, L_8006BF58
    if (ctx->r11 != ctx->r12) {
        // 0x8006BECC: nop
    
            goto L_8006BF58;
    }
    // 0x8006BECC: nop

    // 0x8006BED0: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x8006BED4: lbu         $t5, 0xE($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XE);
    // 0x8006BED8: lb          $t7, 0x2($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X2);
    // 0x8006BEDC: nop

    // 0x8006BEE0: addu        $v0, $t5, $t7
    ctx->r2 = ADD32(ctx->r13, ctx->r15);
    // 0x8006BEE4: addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    // 0x8006BEE8: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8006BEEC: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8006BEF0: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x8006BEF4: bne         $at, $zero, L_8006BF00
    if (ctx->r1 != 0) {
        // 0x8006BEF8: nop
    
            goto L_8006BF00;
    }
    // 0x8006BEF8: nop

    // 0x8006BEFC: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_8006BF00:
    // 0x8006BF00: bgez        $v0, L_8006BF0C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006BF04: nop
    
            goto L_8006BF0C;
    }
    // 0x8006BF04: nop

    // 0x8006BF08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006BF0C:
    // 0x8006BF0C: lbu         $t0, 0x2($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X2);
    // 0x8006BF10: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8006BF14: multu       $t0, $s2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BF18: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006BF1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BF20: sh          $v0, 0x113C($at)
    MEM_H(0X113C, ctx->r1) = ctx->r2;
    // 0x8006BF24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BF28: sw          $v1, 0x1138($at)
    MEM_W(0X1138, ctx->r1) = ctx->r3;
    // 0x8006BF2C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x8006BF30: mflo        $t1
    ctx->r9 = lo;
    // 0x8006BF34: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x8006BF38: jal         0x80071C80
    // 0x8006BF3C: nop

    func_80071C80(rdram, ctx);
        goto after_0;
    // 0x8006BF3C: nop

    after_0:
    // 0x8006BF40: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006BF44: lw          $v0, 0x1130($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1130);
    // 0x8006BF48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BF4C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006BF50: beq         $v0, $zero, L_8006BF84
    if (ctx->r2 == 0) {
        // 0x8006BF54: sw          $v0, 0x1130($at)
        MEM_W(0X1130, ctx->r1) = ctx->r2;
            goto L_8006BF84;
    }
    // 0x8006BF54: sw          $v0, 0x1130($at)
    MEM_W(0X1130, ctx->r1) = ctx->r2;
L_8006BF58:
    // 0x8006BF58: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8006BF5C: lw          $t3, 0x1134($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1134);
    // 0x8006BF60: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8006BF64: lw          $v1, 0x1138($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1138);
    // 0x8006BF68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BF6C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8006BF70: sw          $t4, 0x1134($at)
    MEM_W(0X1134, ctx->r1) = ctx->r12;
    // 0x8006BF74: bne         $t3, $zero, L_8006BE9C
    if (ctx->r11 != 0) {
        // 0x8006BF78: addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
            goto L_8006BE9C;
    }
    // 0x8006BF78: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // 0x8006BF7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BF80: sw          $v1, 0x1138($at)
    MEM_W(0X1138, ctx->r1) = ctx->r3;
L_8006BF84:
    // 0x8006BF84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006BF88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006BF8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006BF90: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006BF94: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006BF98: jr          $ra
    // 0x8006BF9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006BF9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006BFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BFA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006BFA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006BFA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006BFAC: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x8006BFB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006BFB4: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x8006BFB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BFBC: bne         $t7, $zero, L_8006C0B8
    if (ctx->r15 != 0) {
        // 0x8006BFC0: nop
    
            goto L_8006C0B8;
    }
    // 0x8006BFC0: nop

    // 0x8006BFC4: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x8006BFC8: lbu         $v0, 0x11($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X11);
    // 0x8006BFCC: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8006BFD0: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    // 0x8006BFD4: beq         $v0, $zero, L_8006C0C8
    if (ctx->r2 == 0) {
        // 0x8006BFD8: sb          $v0, 0x113F($at)
        MEM_B(0X113F, ctx->r1) = ctx->r2;
            goto L_8006C0C8;
    }
    // 0x8006BFD8: sb          $v0, 0x113F($at)
    MEM_B(0X113F, ctx->r1) = ctx->r2;
    // 0x8006BFDC: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8006BFE0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8006BFE4: lw          $t1, 0xE3C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE3C);
    // 0x8006BFE8: lw          $t3, 0xE40($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XE40);
    // 0x8006BFEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BFF0: sw          $t1, 0x1144($at)
    MEM_W(0X1144, ctx->r1) = ctx->r9;
    // 0x8006BFF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BFF8: sb          $t3, 0x1140($at)
    MEM_B(0X1140, ctx->r1) = ctx->r11;
    // 0x8006BFFC: andi        $v0, $t3, 0xFF
    ctx->r2 = ctx->r11 & 0XFF;
    // 0x8006C000: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8006C004: beq         $v0, $zero, L_8006C0C8
    if (ctx->r2 == 0) {
        // 0x8006C008: sb          $t4, 0x1140($at)
        MEM_B(0X1140, ctx->r1) = ctx->r12;
            goto L_8006C0C8;
    }
    // 0x8006C008: sb          $t4, 0x1140($at)
    MEM_B(0X1140, ctx->r1) = ctx->r12;
L_8006C00C:
    // 0x8006C00C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8006C010: lw          $t5, 0x1144($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1144);
    // 0x8006C014: nop

    // 0x8006C018: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8006C01C: nop

    // 0x8006C020: srl         $t6, $v0, 31
    ctx->r14 = S32(U32(ctx->r2) >> 31);
    // 0x8006C024: beq         $t6, $zero, L_8006C084
    if (ctx->r14 == 0) {
        // 0x8006C028: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_8006C084;
    }
    // 0x8006C028: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8006C02C: bltz        $t8, L_8006C084
    if (SIGNED(ctx->r24) < 0) {
        // 0x8006C030: nop
    
            goto L_8006C084;
    }
    // 0x8006C030: nop

    // 0x8006C034: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x8006C038: lbu         $t0, 0x3($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X3);
    // 0x8006C03C: nop

    // 0x8006C040: bne         $t9, $t0, L_8006C084
    if (ctx->r25 != ctx->r8) {
        // 0x8006C044: nop
    
            goto L_8006C084;
    }
    // 0x8006C044: nop

    // 0x8006C048: lbu         $t1, 0x7($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0X7);
    // 0x8006C04C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006C050: beq         $t1, $zero, L_8006C084
    if (ctx->r9 == 0) {
        // 0x8006C054: nop
    
            goto L_8006C084;
    }
    // 0x8006C054: nop

    // 0x8006C058: sb          $zero, 0x7($t5)
    MEM_B(0X7, ctx->r13) = 0;
    // 0x8006C05C: lw          $a0, 0x1144($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1144);
    // 0x8006C060: jal         0x8006C4BC
    // 0x8006C064: nop

    func_8006C4BC(rdram, ctx);
        goto after_0;
    // 0x8006C064: nop

    after_0:
    // 0x8006C068: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006C06C: lbu         $v0, 0x113F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X113F);
    // 0x8006C070: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C074: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006C078: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x8006C07C: beq         $t2, $zero, L_8006C0C8
    if (ctx->r10 == 0) {
        // 0x8006C080: sb          $t2, 0x113F($at)
        MEM_B(0X113F, ctx->r1) = ctx->r10;
            goto L_8006C0C8;
    }
    // 0x8006C080: sb          $t2, 0x113F($at)
    MEM_B(0X113F, ctx->r1) = ctx->r10;
L_8006C084:
    // 0x8006C084: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8006C088: lw          $t3, 0x1144($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1144);
    // 0x8006C08C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006C090: lbu         $t6, 0x1140($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1140);
    // 0x8006C094: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C098: addiu       $t4, $t3, 0x14
    ctx->r12 = ADD32(ctx->r11, 0X14);
    // 0x8006C09C: sw          $t4, 0x1144($at)
    MEM_W(0X1144, ctx->r1) = ctx->r12;
    // 0x8006C0A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C0A4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8006C0A8: bne         $t6, $zero, L_8006C00C
    if (ctx->r14 != 0) {
        // 0x8006C0AC: sb          $t7, 0x1140($at)
        MEM_B(0X1140, ctx->r1) = ctx->r15;
            goto L_8006C00C;
    }
    // 0x8006C0AC: sb          $t7, 0x1140($at)
    MEM_B(0X1140, ctx->r1) = ctx->r15;
    // 0x8006C0B0: b           L_8006C0CC
    // 0x8006C0B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8006C0CC;
    // 0x8006C0B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006C0B8:
    // 0x8006C0B8: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x8006C0BC: nop

    // 0x8006C0C0: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x8006C0C4: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
L_8006C0C8:
    // 0x8006C0C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006C0CC:
    // 0x8006C0CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006C0D0: jr          $ra
    // 0x8006C0D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006C0D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006C0D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C0D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006C0DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006C0E0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006C0E4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006C0E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006C0EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006C0F0: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x8006C0F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C0F8: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x8006C0FC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8006C100: sb          $t7, 0x1154($at)
    MEM_B(0X1154, ctx->r1) = ctx->r15;
    // 0x8006C104: lbu         $t9, 0xC($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XC);
    // 0x8006C108: lbu         $t8, 0x1154($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1154);
    // 0x8006C10C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8006C110: beq         $t8, $t9, L_8006C210
    if (ctx->r24 == ctx->r25) {
        // 0x8006C114: lui         $t0, 0x800D
        ctx->r8 = S32(0X800D << 16);
            goto L_8006C210;
    }
    // 0x8006C114: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8006C118: lbu         $t0, 0x1154($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X1154);
    // 0x8006C11C: lbu         $v0, 0x11($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X11);
    // 0x8006C120: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C124: sb          $t0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r8;
    // 0x8006C128: beq         $v0, $zero, L_8006C210
    if (ctx->r2 == 0) {
        // 0x8006C12C: sw          $v0, 0x1148($at)
        MEM_W(0X1148, ctx->r1) = ctx->r2;
            goto L_8006C210;
    }
    // 0x8006C12C: sw          $v0, 0x1148($at)
    MEM_W(0X1148, ctx->r1) = ctx->r2;
    // 0x8006C130: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8006C134: lw          $t1, 0xE3C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE3C);
    // 0x8006C138: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8006C13C: lw          $t2, 0xE40($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE40);
    // 0x8006C140: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C144: sw          $t1, 0x1150($at)
    MEM_W(0X1150, ctx->r1) = ctx->r9;
    // 0x8006C148: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C14C: sw          $t2, 0x114C($at)
    MEM_W(0X114C, ctx->r1) = ctx->r10;
    // 0x8006C150: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8006C154: beq         $t2, $zero, L_8006C210
    if (ctx->r10 == 0) {
        // 0x8006C158: sw          $t3, 0x114C($at)
        MEM_W(0X114C, ctx->r1) = ctx->r11;
            goto L_8006C210;
    }
    // 0x8006C158: sw          $t3, 0x114C($at)
    MEM_W(0X114C, ctx->r1) = ctx->r11;
    // 0x8006C15C: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x8006C160: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8006C164: addiu       $s0, $s0, 0x1040
    ctx->r16 = ADD32(ctx->r16, 0X1040);
    // 0x8006C168: addiu       $s2, $s2, -0x17E0
    ctx->r18 = ADD32(ctx->r18, -0X17E0);
    // 0x8006C16C: addiu       $s1, $zero, 0x1C
    ctx->r17 = ADD32(0, 0X1C);
L_8006C170:
    // 0x8006C170: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8006C174: lw          $t4, 0x1150($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1150);
    // 0x8006C178: nop

    // 0x8006C17C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8006C180: nop

    // 0x8006C184: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x8006C188: beq         $t6, $zero, L_8006C1E4
    if (ctx->r14 == 0) {
        // 0x8006C18C: nop
    
            goto L_8006C1E4;
    }
    // 0x8006C18C: nop

    // 0x8006C190: lbu         $t7, 0x1($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X1);
    // 0x8006C194: lbu         $t8, 0x3($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X3);
    // 0x8006C198: nop

    // 0x8006C19C: bne         $t7, $t8, L_8006C1E4
    if (ctx->r15 != ctx->r24) {
        // 0x8006C1A0: nop
    
            goto L_8006C1E4;
    }
    // 0x8006C1A0: nop

    // 0x8006C1A4: lbu         $t9, 0x2($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X2);
    // 0x8006C1A8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8006C1AC: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006C1B0: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006C1B4: lbu         $a2, 0x1154($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X1154);
    // 0x8006C1B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006C1BC: mflo        $t0
    ctx->r8 = lo;
    // 0x8006C1C0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x8006C1C4: jal         0x80071C80
    // 0x8006C1C8: nop

    func_80071C80(rdram, ctx);
        goto after_0;
    // 0x8006C1C8: nop

    after_0:
    // 0x8006C1CC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006C1D0: lw          $v0, 0x1148($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1148);
    // 0x8006C1D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C1D8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006C1DC: beq         $v0, $zero, L_8006C210
    if (ctx->r2 == 0) {
        // 0x8006C1E0: sw          $v0, 0x1148($at)
        MEM_W(0X1148, ctx->r1) = ctx->r2;
            goto L_8006C210;
    }
    // 0x8006C1E0: sw          $v0, 0x1148($at)
    MEM_W(0X1148, ctx->r1) = ctx->r2;
L_8006C1E4:
    // 0x8006C1E4: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8006C1E8: lw          $t2, 0x1150($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1150);
    // 0x8006C1EC: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8006C1F0: lw          $t5, 0x114C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X114C);
    // 0x8006C1F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C1F8: addiu       $t3, $t2, 0x14
    ctx->r11 = ADD32(ctx->r10, 0X14);
    // 0x8006C1FC: sw          $t3, 0x1150($at)
    MEM_W(0X1150, ctx->r1) = ctx->r11;
    // 0x8006C200: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C204: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8006C208: bne         $t5, $zero, L_8006C170
    if (ctx->r13 != 0) {
        // 0x8006C20C: sw          $t6, 0x114C($at)
        MEM_W(0X114C, ctx->r1) = ctx->r14;
            goto L_8006C170;
    }
    // 0x8006C20C: sw          $t6, 0x114C($at)
    MEM_W(0X114C, ctx->r1) = ctx->r14;
L_8006C210:
    // 0x8006C210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006C214: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006C218: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006C21C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C220: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006C224: jr          $ra
    // 0x8006C228: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006C228: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006C22C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C22C: jr          $ra
    // 0x8006C230: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006C230: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8006C234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C234: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C23C: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8006C240: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8006C244: ori         $t9, $t7, 0x80
    ctx->r25 = ctx->r15 | 0X80;
    // 0x8006C248: andi        $t2, $t9, 0xBF
    ctx->r10 = ctx->r25 & 0XBF;
    // 0x8006C24C: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x8006C250: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x8006C254: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x8006C258: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // 0x8006C25C: lbu         $t4, 0x1($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X1);
    // 0x8006C260: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006C264: sb          $t4, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r12;
    // 0x8006C268: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x8006C26C: nop

    // 0x8006C270: sb          $t5, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r13;
    // 0x8006C274: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x8006C278: nop

    // 0x8006C27C: sb          $t6, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r14;
    // 0x8006C280: lbu         $t7, 0x2F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2F);
    // 0x8006C284: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // 0x8006C288: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x8006C28C: sw          $a3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r7;
    // 0x8006C290: sb          $t7, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r15;
    // 0x8006C294: lw          $t8, 0xE48($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE48);
    // 0x8006C298: nop

    // 0x8006C29C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8006C2A0: nop

    // 0x8006C2A4: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
    // 0x8006C2A8: lbu         $t0, 0x11($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X11);
    // 0x8006C2AC: nop

    // 0x8006C2B0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8006C2B4: sb          $t1, 0x11($a1)
    MEM_B(0X11, ctx->r5) = ctx->r9;
    // 0x8006C2B8: lw          $v0, 0xE30($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XE30);
    // 0x8006C2BC: nop

    // 0x8006C2C0: lbu         $t2, 0x6($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X6);
    // 0x8006C2C4: nop

    // 0x8006C2C8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8006C2CC: jal         0x8006AF64
    // 0x8006C2D0: sb          $t3, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r11;
    func_8006AF64(rdram, ctx);
        goto after_0;
    // 0x8006C2D0: sb          $t3, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r11;
    after_0:
    // 0x8006C2D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C2D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C2DC: jr          $ra
    // 0x8006C2E0: nop

    return;
    // 0x8006C2E0: nop

;}
RECOMP_FUNC void func_8006C2E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C2E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006C2E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006C2EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006C2F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006C2F4: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    // 0x8006C2F8: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8006C2FC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8006C300: lw          $t8, -0x17E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X17E0);
    // 0x8006C304: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8006C308: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006C30C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8006C310: lw          $a0, 0x1040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1040);
    // 0x8006C314: jal         0x800719B0
    // 0x8006C318: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x8006C318: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x8006C31C: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
    // 0x8006C320: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8006C324: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8006C328: lw          $t1, -0x17E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X17E0);
    // 0x8006C32C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8006C330: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8006C334: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8006C338: lw          $a0, 0x1040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1040);
    // 0x8006C33C: jal         0x80071730
    // 0x8006C340: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    func_80071730(rdram, ctx);
        goto after_1;
    // 0x8006C340: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_1:
    // 0x8006C344: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006C348: lbu         $t2, 0x3($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X3);
    // 0x8006C34C: lw          $v0, 0xE30($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XE30);
    // 0x8006C350: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8006C354: lbu         $t5, 0x6($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X6);
    // 0x8006C358: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8006C35C: lw          $t4, 0xE38($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE38);
    // 0x8006C360: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8006C364: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x8006C368: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8006C36C: sb          $t6, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r14;
    // 0x8006C370: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x8006C374: lbu         $t7, 0x11($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X11);
    // 0x8006C378: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C37C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8006C380: sb          $t8, 0x11($a0)
    MEM_B(0X11, ctx->r4) = ctx->r24;
    // 0x8006C384: sw          $a0, 0x1158($at)
    MEM_W(0X1158, ctx->r1) = ctx->r4;
    // 0x8006C388: lbu         $t9, 0x11($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X11);
    // 0x8006C38C: nop

    // 0x8006C390: bne         $t9, $zero, L_8006C3C8
    if (ctx->r25 != 0) {
        // 0x8006C394: nop
    
            goto L_8006C3C8;
    }
    // 0x8006C394: nop

    // 0x8006C398: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006C39C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C3A0: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x8006C3A4: bgez        $t1, L_8006C3C8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8006C3A8: sw          $a0, 0x1158($at)
        MEM_W(0X1158, ctx->r1) = ctx->r4;
            goto L_8006C3C8;
    }
    // 0x8006C3A8: sw          $a0, 0x1158($at)
    MEM_W(0X1158, ctx->r1) = ctx->r4;
    // 0x8006C3AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C3B0: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x8006C3B4: bltz        $t3, L_8006C3C8
    if (SIGNED(ctx->r11) < 0) {
        // 0x8006C3B8: sw          $a0, 0x1158($at)
        MEM_W(0X1158, ctx->r1) = ctx->r4;
            goto L_8006C3C8;
    }
    // 0x8006C3B8: sw          $a0, 0x1158($at)
    MEM_W(0X1158, ctx->r1) = ctx->r4;
    // 0x8006C3BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C3C0: jal         0x8006961C
    // 0x8006C3C4: sw          $a0, 0x1158($at)
    MEM_W(0X1158, ctx->r1) = ctx->r4;
    func_8006961C(rdram, ctx);
        goto after_2;
    // 0x8006C3C4: sw          $a0, 0x1158($at)
    MEM_W(0X1158, ctx->r1) = ctx->r4;
    after_2:
L_8006C3C8:
    // 0x8006C3C8: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x8006C3CC: nop

    // 0x8006C3D0: andi        $t6, $t4, 0xFF7F
    ctx->r14 = ctx->r12 & 0XFF7F;
    // 0x8006C3D4: andi        $t8, $t6, 0xBF
    ctx->r24 = ctx->r14 & 0XBF;
    // 0x8006C3D8: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8006C3DC: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x8006C3E0: andi        $t9, $t8, 0xDF
    ctx->r25 = ctx->r24 & 0XDF;
    // 0x8006C3E4: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x8006C3E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C3EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006C3F0: jr          $ra
    // 0x8006C3F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006C3F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006C3F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006C3FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006C400: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006C404: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006C408: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006C40C: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    // 0x8006C410: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8006C414: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8006C418: lw          $t8, -0x17E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X17E0);
    // 0x8006C41C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8006C420: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006C424: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8006C428: lw          $a0, 0x1040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1040);
    // 0x8006C42C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006C430: jal         0x80071D10
    // 0x8006C434: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    func_80071D10(rdram, ctx);
        goto after_0;
    // 0x8006C434: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x8006C438: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8006C43C: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
    // 0x8006C440: sll         $t2, $a3, 5
    ctx->r10 = S32(ctx->r7 << 5);
    // 0x8006C444: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8006C448: subu        $t2, $t2, $a3
    ctx->r10 = SUB32(ctx->r10, ctx->r7);
    // 0x8006C44C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8006C450: lw          $t1, -0x17E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X17E0);
    // 0x8006C454: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8006C458: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8006C45C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8006C460: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8006C464: lw          $a0, 0x1040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1040);
    // 0x8006C468: addu        $t2, $t2, $a3
    ctx->r10 = ADD32(ctx->r10, ctx->r7);
    // 0x8006C46C: sll         $a3, $t2, 3
    ctx->r7 = S32(ctx->r10 << 3);
    // 0x8006C470: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006C474: jal         0x80071BC0
    // 0x8006C478: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    func_80071BC0(rdram, ctx);
        goto after_1;
    // 0x8006C478: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_1:
    // 0x8006C47C: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x8006C480: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8006C484: ori         $t6, $t4, 0x40
    ctx->r14 = ctx->r12 | 0X40;
    // 0x8006C488: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8006C48C: andi        $t7, $t6, 0xDF
    ctx->r15 = ctx->r14 & 0XDF;
    // 0x8006C490: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x8006C494: lw          $t8, 0xE48($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE48);
    // 0x8006C498: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8006C49C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8006C4A0: nop

    // 0x8006C4A4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8006C4A8: sw          $t1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r9;
    // 0x8006C4AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C4B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006C4B4: jr          $ra
    // 0x8006C4B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006C4B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006C4BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C4BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006C4C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006C4C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006C4C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006C4CC: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    // 0x8006C4D0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8006C4D4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8006C4D8: lw          $t8, -0x17E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X17E0);
    // 0x8006C4DC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8006C4E0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006C4E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8006C4E8: lw          $a0, 0x1040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1040);
    // 0x8006C4EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006C4F0: jal         0x80071D10
    // 0x8006C4F4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    func_80071D10(rdram, ctx);
        goto after_0;
    // 0x8006C4F4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x8006C4F8: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x8006C4FC: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
    // 0x8006C500: lhu         $a3, 0x10($t2)
    ctx->r7 = MEM_HU(ctx->r10, 0X10);
    // 0x8006C504: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8006C508: sll         $t3, $a3, 5
    ctx->r11 = S32(ctx->r7 << 5);
    // 0x8006C50C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8006C510: subu        $t3, $t3, $a3
    ctx->r11 = SUB32(ctx->r11, ctx->r7);
    // 0x8006C514: lw          $t1, -0x17E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X17E0);
    // 0x8006C518: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8006C51C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8006C520: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8006C524: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8006C528: lw          $a0, 0x1040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1040);
    // 0x8006C52C: addu        $t3, $t3, $a3
    ctx->r11 = ADD32(ctx->r11, ctx->r7);
    // 0x8006C530: sll         $a3, $t3, 3
    ctx->r7 = S32(ctx->r11 << 3);
    // 0x8006C534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006C538: jal         0x80071BC0
    // 0x8006C53C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    func_80071BC0(rdram, ctx);
        goto after_1;
    // 0x8006C53C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_1:
    // 0x8006C540: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x8006C544: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8006C548: ori         $t7, $t5, 0x40
    ctx->r15 = ctx->r13 | 0X40;
    // 0x8006C54C: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x8006C550: andi        $t8, $t7, 0xDF
    ctx->r24 = ctx->r15 & 0XDF;
    // 0x8006C554: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x8006C558: lw          $t9, 0xE48($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE48);
    // 0x8006C55C: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x8006C560: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8006C564: lhu         $t2, 0x10($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X10);
    // 0x8006C568: nop

    // 0x8006C56C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8006C570: sw          $t3, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r11;
    // 0x8006C574: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C578: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006C57C: jr          $ra
    // 0x8006C580: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006C580: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006C584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C584: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006C588: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006C58C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006C590: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x8006C594: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8006C598: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006C59C: lw          $t8, 0xE38($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE38);
    // 0x8006C5A0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006C5A4: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8006C5A8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8006C5AC: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x8006C5B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006C5B4: bne         $t9, $zero, L_8006C610
    if (ctx->r25 != 0) {
        // 0x8006C5B8: nop
    
            goto L_8006C610;
    }
    // 0x8006C5B8: nop

    // 0x8006C5BC: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8006C5C0: lbu         $t0, 0x6($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X6);
    // 0x8006C5C4: lbu         $t1, 0x1($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1);
    // 0x8006C5C8: lbu         $t3, 0xD($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0XD);
    // 0x8006C5CC: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006C5D0: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8006C5D4: lbu         $t5, 0xE6C($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0XE6C);
    // 0x8006C5D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C5DC: sw          $a1, 0x1160($at)
    MEM_W(0X1160, ctx->r1) = ctx->r5;
    // 0x8006C5E0: mflo        $t2
    ctx->r10 = lo;
    // 0x8006C5E4: nop

    // 0x8006C5E8: nop

    // 0x8006C5EC: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006C5F0: mflo        $t4
    ctx->r12 = lo;
    // 0x8006C5F4: nop

    // 0x8006C5F8: nop

    // 0x8006C5FC: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006C600: mflo        $v1
    ctx->r3 = lo;
    // 0x8006C604: srl         $t6, $v1, 13
    ctx->r14 = S32(U32(ctx->r3) >> 13);
    // 0x8006C608: b           L_8006C660
    // 0x8006C60C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
        goto L_8006C660;
    // 0x8006C60C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8006C610:
    // 0x8006C610: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8006C614: lbu         $t7, 0x6($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6);
    // 0x8006C618: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8006C61C: lbu         $t0, 0xD($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XD);
    // 0x8006C620: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006C624: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8006C628: lbu         $t2, 0xE70($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0XE70);
    // 0x8006C62C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C630: sw          $a1, 0x1160($at)
    MEM_W(0X1160, ctx->r1) = ctx->r5;
    // 0x8006C634: mflo        $t9
    ctx->r25 = lo;
    // 0x8006C638: nop

    // 0x8006C63C: nop

    // 0x8006C640: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006C644: mflo        $t1
    ctx->r9 = lo;
    // 0x8006C648: nop

    // 0x8006C64C: nop

    // 0x8006C650: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006C654: mflo        $v1
    ctx->r3 = lo;
    // 0x8006C658: srl         $t3, $v1, 13
    ctx->r11 = S32(U32(ctx->r3) >> 13);
    // 0x8006C65C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
L_8006C660:
    // 0x8006C660: lbu         $t4, 0x13($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X13);
    // 0x8006C664: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8006C668: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006C66C: lw          $t6, 0xCB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCB0);
    // 0x8006C670: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C674: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8006C678: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8006C67C: mflo        $v1
    ctx->r3 = lo;
    // 0x8006C680: srl         $t5, $v1, 7
    ctx->r13 = S32(U32(ctx->r3) >> 7);
    // 0x8006C684: beq         $t6, $zero, L_8006C6D8
    if (ctx->r14 == 0) {
        // 0x8006C688: sw          $t5, 0x115C($at)
        MEM_W(0X115C, ctx->r1) = ctx->r13;
            goto L_8006C6D8;
    }
    // 0x8006C688: sw          $t5, 0x115C($at)
    MEM_W(0X115C, ctx->r1) = ctx->r13;
    // 0x8006C68C: lhu         $a3, 0xE($v0)
    ctx->r7 = MEM_HU(ctx->r2, 0XE);
    // 0x8006C690: lbu         $t7, 0x2($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2);
    // 0x8006C694: sll         $t1, $a3, 5
    ctx->r9 = S32(ctx->r7 << 5);
    // 0x8006C698: subu        $t1, $t1, $a3
    ctx->r9 = SUB32(ctx->r9, ctx->r7);
    // 0x8006C69C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8006C6A0: lw          $t9, -0x17E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X17E0);
    // 0x8006C6A4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8006C6A8: sll         $a2, $t5, 16
    ctx->r6 = S32(ctx->r13 << 16);
    // 0x8006C6AC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8006C6B0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8006C6B4: sra         $t0, $a2, 16
    ctx->r8 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006C6B8: lw          $a0, 0x1040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1040);
    // 0x8006C6BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C6C0: addu        $t1, $t1, $a3
    ctx->r9 = ADD32(ctx->r9, ctx->r7);
    // 0x8006C6C4: sll         $a3, $t1, 3
    ctx->r7 = S32(ctx->r9 << 3);
    // 0x8006C6C8: sw          $t5, 0x115C($at)
    MEM_W(0X115C, ctx->r1) = ctx->r13;
    // 0x8006C6CC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8006C6D0: jal         0x80071BC0
    // 0x8006C6D4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80071BC0(rdram, ctx);
        goto after_0;
    // 0x8006C6D4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
L_8006C6D8:
    // 0x8006C6D8: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x8006C6DC: nop

    // 0x8006C6E0: andi        $t3, $t2, 0xFFDF
    ctx->r11 = ctx->r10 & 0XFFDF;
    // 0x8006C6E4: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x8006C6E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C6EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006C6F0: jr          $ra
    // 0x8006C6F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006C6F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006C6F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C6F8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8006C6FC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8006C700: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C704: lw          $t3, 0xE40($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE40);
    // 0x8006C708: sw          $t0, 0x1178($at)
    MEM_W(0X1178, ctx->r1) = ctx->r8;
    // FALLTHROUGH: func_8006C6F8 falls into func_8006C70C
    func_8006C70C(rdram, ctx);
;}
RECOMP_FUNC void func_8006C70C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C70C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006C710: addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
    // 0x8006C714: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C718: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006C71C: sw          $t1, 0x1174($at)
    MEM_W(0X1174, ctx->r1) = ctx->r9;
    // 0x8006C720: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006C724: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8006C728: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C72C: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x8006C730: lw          $s0, 0xE3C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XE3C);
    // 0x8006C734: sw          $t3, 0x1164($at)
    MEM_W(0X1164, ctx->r1) = ctx->r11;
    // 0x8006C738: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C73C: sw          $s0, 0x116C($at)
    MEM_W(0X116C, ctx->r1) = ctx->r16;
    // 0x8006C740: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006C744: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8006C748: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C74C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8006C750: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006C754: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8006C758: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8006C75C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8006C760: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006C764: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8006C768: beq         $v0, $zero, L_8006C8D0
    if (ctx->r2 == 0) {
        // 0x8006C76C: sw          $zero, 0x1170($at)
        MEM_W(0X1170, ctx->r1) = 0;
            goto L_8006C8D0;
    }
    // 0x8006C76C: sw          $zero, 0x1170($at)
    MEM_W(0X1170, ctx->r1) = 0;
L_8006C770:
    // 0x8006C770: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006C774: nop

    // 0x8006C778: srl         $t6, $v0, 31
    ctx->r14 = S32(U32(ctx->r2) >> 31);
    // 0x8006C77C: bne         $t6, $zero, L_8006C7DC
    if (ctx->r14 != 0) {
        // 0x8006C780: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8006C7DC;
    }
    // 0x8006C780: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C784: sw          $s1, 0x1170($at)
    MEM_W(0X1170, ctx->r1) = ctx->r17;
    // 0x8006C788: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C78C: sw          $t3, 0x1164($at)
    MEM_W(0X1164, ctx->r1) = ctx->r11;
    // 0x8006C790: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C794: sw          $t2, 0x1168($at)
    MEM_W(0X1168, ctx->r1) = ctx->r10;
    // 0x8006C798: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C79C: sw          $t1, 0x1174($at)
    MEM_W(0X1174, ctx->r1) = ctx->r9;
    // 0x8006C7A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C7A4: lbu         $t7, 0x3F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3F);
    // 0x8006C7A8: lbu         $t8, 0x43($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X43);
    // 0x8006C7AC: sw          $t0, 0x1178($at)
    MEM_W(0X1178, ctx->r1) = ctx->r8;
    // 0x8006C7B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C7B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8006C7B8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8006C7BC: sw          $s0, 0x116C($at)
    MEM_W(0X116C, ctx->r1) = ctx->r16;
    // 0x8006C7C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006C7C4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8006C7C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006C7CC: jal         0x8006C234
    // 0x8006C7D0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_8006C234(rdram, ctx);
        goto after_0;
    // 0x8006C7D0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x8006C7D4: b           L_8006C8D0
    // 0x8006C7D8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
        goto L_8006C8D0;
    // 0x8006C7D8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8006C7DC:
    // 0x8006C7DC: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x8006C7E0: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x8006C7E4: nop

    // 0x8006C7E8: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006C7EC: bne         $at, $zero, L_8006C898
    if (ctx->r1 != 0) {
        // 0x8006C7F0: slt         $at, $v1, $t1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8006C898;
    }
    // 0x8006C7F0: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8006C7F4: beq         $at, $zero, L_8006C810
    if (ctx->r1 == 0) {
        // 0x8006C7F8: nop
    
            goto L_8006C810;
    }
    // 0x8006C7F8: nop

    // 0x8006C7FC: lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10);
    // 0x8006C800: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8006C804: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8006C808: b           L_8006C898
    // 0x8006C80C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
        goto L_8006C898;
    // 0x8006C80C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_8006C810:
    // 0x8006C810: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006C814: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8006C818: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x8006C81C: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x8006C820: bgez        $t7, L_8006C86C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8006C824: or          $a0, $t5, $zero
        ctx->r4 = ctx->r13 | 0;
            goto L_8006C86C;
    }
    // 0x8006C824: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8006C828: beq         $t5, $zero, L_8006C858
    if (ctx->r13 == 0) {
        // 0x8006C82C: nop
    
            goto L_8006C858;
    }
    // 0x8006C82C: nop

    // 0x8006C830: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x8006C834: nop

    // 0x8006C838: sltu        $at, $v0, $t0
    ctx->r1 = ctx->r2 < ctx->r8 ? 1 : 0;
    // 0x8006C83C: beq         $at, $zero, L_8006C898
    if (ctx->r1 == 0) {
        // 0x8006C840: nop
    
            goto L_8006C898;
    }
    // 0x8006C840: nop

    // 0x8006C844: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8006C848: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8006C84C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8006C850: b           L_8006C898
    // 0x8006C854: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
        goto L_8006C898;
    // 0x8006C854: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_8006C858:
    // 0x8006C858: lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10);
    // 0x8006C85C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8006C860: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8006C864: b           L_8006C898
    // 0x8006C868: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
        goto L_8006C898;
    // 0x8006C868: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_8006C86C:
    // 0x8006C86C: bne         $a0, $zero, L_8006C89C
    if (ctx->r4 != 0) {
        // 0x8006C870: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_8006C89C;
    }
    // 0x8006C870: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006C874: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x8006C878: nop

    // 0x8006C87C: sltu        $at, $v0, $t0
    ctx->r1 = ctx->r2 < ctx->r8 ? 1 : 0;
    // 0x8006C880: beq         $at, $zero, L_8006C898
    if (ctx->r1 == 0) {
        // 0x8006C884: nop
    
            goto L_8006C898;
    }
    // 0x8006C884: nop

    // 0x8006C888: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8006C88C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8006C890: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8006C894: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_8006C898:
    // 0x8006C898: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_8006C89C:
    // 0x8006C89C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8006C8A0: bne         $t3, $zero, L_8006C770
    if (ctx->r11 != 0) {
        // 0x8006C8A4: addiu       $t3, $t3, -0x1
        ctx->r11 = ADD32(ctx->r11, -0X1);
            goto L_8006C770;
    }
    // 0x8006C8A4: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x8006C8A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C8AC: sw          $s0, 0x116C($at)
    MEM_W(0X116C, ctx->r1) = ctx->r16;
    // 0x8006C8B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C8B4: sw          $t3, 0x1164($at)
    MEM_W(0X1164, ctx->r1) = ctx->r11;
    // 0x8006C8B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C8BC: sw          $t1, 0x1174($at)
    MEM_W(0X1174, ctx->r1) = ctx->r9;
    // 0x8006C8C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C8C4: sw          $t0, 0x1178($at)
    MEM_W(0X1178, ctx->r1) = ctx->r8;
    // 0x8006C8C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C8CC: sw          $s1, 0x1170($at)
    MEM_W(0X1170, ctx->r1) = ctx->r17;
L_8006C8D0:
    // 0x8006C8D0: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8006C8D4: lw          $s1, 0x1170($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X1170);
    // 0x8006C8D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C8DC: beq         $t2, $zero, L_8006C91C
    if (ctx->r10 == 0) {
        // 0x8006C8E0: sw          $t2, 0x1168($at)
        MEM_W(0X1168, ctx->r1) = ctx->r10;
            goto L_8006C91C;
    }
    // 0x8006C8E0: sw          $t2, 0x1168($at)
    MEM_W(0X1168, ctx->r1) = ctx->r10;
    // 0x8006C8E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C8E8: sw          $s1, 0x1170($at)
    MEM_W(0X1170, ctx->r1) = ctx->r17;
    // 0x8006C8EC: jal         0x8006C2E4
    // 0x8006C8F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8006C2E4(rdram, ctx);
        goto after_1;
    // 0x8006C8F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8006C8F4: lbu         $t8, 0x3F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3F);
    // 0x8006C8F8: lbu         $t9, 0x43($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X43);
    // 0x8006C8FC: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8006C900: lw          $a0, 0x1170($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1170);
    // 0x8006C904: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8006C908: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8006C90C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8006C910: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8006C914: jal         0x8006C234
    // 0x8006C918: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_8006C234(rdram, ctx);
        goto after_2;
    // 0x8006C918: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_2:
L_8006C91C:
    // 0x8006C91C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006C920: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006C924: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8006C928: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8006C92C: jr          $ra
    // 0x8006C930: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006C930: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006C934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C934: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006C938: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006C93C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8006C940: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8006C944: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006C948: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8006C94C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006C950: lw          $v1, 0x34($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X34);
    // 0x8006C954: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C958: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x8006C95C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8006C960: sb          $t6, 0x1180($at)
    MEM_B(0X1180, ctx->r1) = ctx->r14;
    // 0x8006C964: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x8006C968: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C96C: sb          $t7, 0x1181($at)
    MEM_B(0X1181, ctx->r1) = ctx->r15;
    // 0x8006C970: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x8006C974: lw          $t0, 0xE4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE4C);
    // 0x8006C978: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006C97C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C980: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8006C984: sw          $t1, 0x1184($at)
    MEM_W(0X1184, ctx->r1) = ctx->r9;
    // 0x8006C988: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x8006C98C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C990: sb          $t2, 0x1182($at)
    MEM_B(0X1182, ctx->r1) = ctx->r10;
    // 0x8006C994: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C998: sw          $zero, 0x117C($at)
    MEM_W(0X117C, ctx->r1) = 0;
    // 0x8006C99C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C9A0: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8006C9A4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8006C9A8: beq         $t2, $zero, L_8006CA94
    if (ctx->r10 == 0) {
        // 0x8006C9AC: sb          $t3, 0x1182($at)
        MEM_B(0X1182, ctx->r1) = ctx->r11;
            goto L_8006CA94;
    }
    // 0x8006C9AC: sb          $t3, 0x1182($at)
    MEM_B(0X1182, ctx->r1) = ctx->r11;
    // 0x8006C9B0: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x8006C9B4: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8006C9B8: addiu       $s1, $s1, 0xE50
    ctx->r17 = ADD32(ctx->r17, 0XE50);
    // 0x8006C9BC: addiu       $s3, $s3, 0xE54
    ctx->r19 = ADD32(ctx->r19, 0XE54);
    // 0x8006C9C0: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
    // 0x8006C9C4: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
L_8006C9C8:
    // 0x8006C9C8: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8006C9CC: lw          $t4, 0x1184($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1184);
    // 0x8006C9D0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006C9D4: lw          $t6, 0x117C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X117C);
    // 0x8006C9D8: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x8006C9DC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006C9E0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8006C9E4: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006C9E8: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8006C9EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C9F0: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8006C9F4: lbu         $t4, 0x1180($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X1180);
    // 0x8006C9F8: mflo        $t8
    ctx->r24 = lo;
    // 0x8006C9FC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x8006CA00: lh          $t0, 0xA($a1)
    ctx->r8 = MEM_H(ctx->r5, 0XA);
    // 0x8006CA04: nop

    // 0x8006CA08: multu       $t0, $s2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006CA0C: mflo        $t1
    ctx->r9 = lo;
    // 0x8006CA10: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8006CA14: sw          $t3, 0x118C($at)
    MEM_W(0X118C, ctx->r1) = ctx->r11;
    // 0x8006CA18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CA1C: sw          $a1, 0x1188($at)
    MEM_W(0X1188, ctx->r1) = ctx->r5;
    // 0x8006CA20: lbu         $t5, 0x6($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X6);
    // 0x8006CA24: nop

    // 0x8006CA28: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8006CA2C: bne         $at, $zero, L_8006CA68
    if (ctx->r1 != 0) {
        // 0x8006CA30: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8006CA68;
    }
    // 0x8006CA30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CA34: sw          $a1, 0x1188($at)
    MEM_W(0X1188, ctx->r1) = ctx->r5;
    // 0x8006CA38: lbu         $t6, 0x7($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X7);
    // 0x8006CA3C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8006CA40: slt         $at, $t6, $t4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8006CA44: bne         $at, $zero, L_8006CA68
    if (ctx->r1 != 0) {
        // 0x8006CA48: or          $a2, $t3, $zero
        ctx->r6 = ctx->r11 | 0;
            goto L_8006CA68;
    }
    // 0x8006CA48: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8006CA4C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006CA50: lbu         $t7, 0x1181($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1181);
    // 0x8006CA54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CA58: sw          $a1, 0x1188($at)
    MEM_W(0X1188, ctx->r1) = ctx->r5;
    // 0x8006CA5C: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x8006CA60: jal         0x8006C6F8
    // 0x8006CA64: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8006C6F8(rdram, ctx);
        goto after_0;
    // 0x8006CA64: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
L_8006CA68:
    // 0x8006CA68: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8006CA6C: lw          $t8, 0x117C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X117C);
    // 0x8006CA70: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8006CA74: lbu         $t0, 0x1182($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X1182);
    // 0x8006CA78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CA7C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8006CA80: sw          $t9, 0x117C($at)
    MEM_W(0X117C, ctx->r1) = ctx->r25;
    // 0x8006CA84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CA88: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8006CA8C: bne         $t0, $zero, L_8006C9C8
    if (ctx->r8 != 0) {
        // 0x8006CA90: sb          $t1, 0x1182($at)
        MEM_B(0X1182, ctx->r1) = ctx->r9;
            goto L_8006C9C8;
    }
    // 0x8006CA90: sb          $t1, 0x1182($at)
    MEM_B(0X1182, ctx->r1) = ctx->r9;
L_8006CA94:
    // 0x8006CA94: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006CA98: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006CA9C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8006CAA0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8006CAA4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CAA8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8006CAAC: jr          $ra
    // 0x8006CAB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006CAB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006CAB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CAB4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006CAB8: lw          $t6, 0xE3C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE3C);
    // 0x8006CABC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006CAC0: lw          $t7, 0xE40($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE40);
    // 0x8006CAC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CAC8: sw          $t6, 0x1194($at)
    MEM_W(0X1194, ctx->r1) = ctx->r14;

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_8006CACC
    func_8006CACC(rdram, ctx);
}
RECOMP_FUNC void func_8006CACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CACC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006CAD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CAD4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006CAD8: sw          $t7, 0x1190($at)
    MEM_W(0X1190, ctx->r1) = ctx->r15;
    // 0x8006CADC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8006CAE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006CAE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006CAE8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006CAEC: beq         $t7, $zero, L_8006CBA8
    if (ctx->r15 == 0) {
        // 0x8006CAF0: sw          $t8, 0x1190($at)
        MEM_W(0X1190, ctx->r1) = ctx->r24;
            goto L_8006CBA8;
    }
    // 0x8006CAF0: sw          $t8, 0x1190($at)
    MEM_W(0X1190, ctx->r1) = ctx->r24;
    // 0x8006CAF4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8006CAF8:
    // 0x8006CAF8: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8006CAFC: lw          $t9, 0x1194($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1194);
    // 0x8006CB00: nop

    // 0x8006CB04: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8006CB08: nop

    // 0x8006CB0C: srl         $t0, $v0, 31
    ctx->r8 = S32(U32(ctx->r2) >> 31);
    // 0x8006CB10: beq         $t0, $zero, L_8006CB7C
    if (ctx->r8 == 0) {
        // 0x8006CB14: sll         $t2, $v0, 1
        ctx->r10 = S32(ctx->r2 << 1);
            goto L_8006CB7C;
    }
    // 0x8006CB14: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x8006CB18: bltz        $t2, L_8006CB7C
    if (SIGNED(ctx->r10) < 0) {
        // 0x8006CB1C: nop
    
            goto L_8006CB7C;
    }
    // 0x8006CB1C: nop

    // 0x8006CB20: lw          $t3, 0x34($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X34);
    // 0x8006CB24: lbu         $t5, 0x5($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X5);
    // 0x8006CB28: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x8006CB2C: nop

    // 0x8006CB30: bne         $t4, $t5, L_8006CB7C
    if (ctx->r12 != ctx->r13) {
        // 0x8006CB34: nop
    
            goto L_8006CB7C;
    }
    // 0x8006CB34: nop

    // 0x8006CB38: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x8006CB3C: lbu         $t7, 0x3($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X3);
    // 0x8006CB40: nop

    // 0x8006CB44: bne         $t6, $t7, L_8006CB7C
    if (ctx->r14 != ctx->r15) {
        // 0x8006CB48: nop
    
            goto L_8006CB7C;
    }
    // 0x8006CB48: nop

    // 0x8006CB4C: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x8006CB50: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8006CB54: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x8006CB58: beq         $t0, $zero, L_8006CB70
    if (ctx->r8 == 0) {
        // 0x8006CB5C: nop
    
            goto L_8006CB70;
    }
    // 0x8006CB5C: nop

    // 0x8006CB60: jal         0x8006C4BC
    // 0x8006CB64: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_8006C4BC(rdram, ctx);
        goto after_0;
    // 0x8006CB64: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x8006CB68: b           L_8006CB7C
    // 0x8006CB6C: nop

        goto L_8006CB7C;
    // 0x8006CB6C: nop

L_8006CB70:
    // 0x8006CB70: lw          $t1, 0x1194($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1194);
    // 0x8006CB74: nop

    // 0x8006CB78: sb          $s1, 0x7($t1)
    MEM_B(0X7, ctx->r9) = ctx->r17;
L_8006CB7C:
    // 0x8006CB7C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8006CB80: lw          $t2, 0x1194($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1194);
    // 0x8006CB84: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8006CB88: lw          $t4, 0x1190($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1190);
    // 0x8006CB8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CB90: addiu       $t3, $t2, 0x14
    ctx->r11 = ADD32(ctx->r10, 0X14);
    // 0x8006CB94: sw          $t3, 0x1194($at)
    MEM_W(0X1194, ctx->r1) = ctx->r11;
    // 0x8006CB98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CB9C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8006CBA0: bne         $t4, $zero, L_8006CAF8
    if (ctx->r12 != 0) {
        // 0x8006CBA4: sw          $t5, 0x1190($at)
        MEM_W(0X1190, ctx->r1) = ctx->r13;
            goto L_8006CAF8;
    }
    // 0x8006CBA4: sw          $t5, 0x1190($at)
    MEM_W(0X1190, ctx->r1) = ctx->r13;
L_8006CBA8:
    // 0x8006CBA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CBAC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006CBB0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006CBB4: jr          $ra
    // 0x8006CBB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006CBB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006CBBC: nop

;}
RECOMP_FUNC void func_8006CBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CBC0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006CBC4: lw          $v0, 0x11D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X11D0);
    // FALLTHROUGH: func_8006CBC0 falls into func_8006CBC8
    func_8006CBC8(rdram, ctx);
;}
RECOMP_FUNC void func_8006CBC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CBC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CBCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CBD0: beq         $v0, $zero, L_8006CBE8
    if (ctx->r2 == 0) {
        // 0x8006CBD4: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8006CBE8;
    }
    // 0x8006CBD4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006CBD8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006CBDC: lw          $a0, 0x11D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11D4);
    // 0x8006CBE0: jalr        $v0
    // 0x8006CBE4: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8006CBE4: nop

    after_0:
L_8006CBE8:
    // 0x8006CBE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CBEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CBF0: jr          $ra
    // 0x8006CBF4: nop

    return;
    // 0x8006CBF4: nop

;}
RECOMP_FUNC void func_8006CBF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CBF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CBFC: sw          $a0, 0x11D0($at)
    MEM_W(0X11D0, ctx->r1) = ctx->r4;
    // 0x8006CC00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CC04: jr          $ra
    // 0x8006CC08: sw          $a1, 0x11D4($at)
    MEM_W(0X11D4, ctx->r1) = ctx->r5;
    return;
    // 0x8006CC08: sw          $a1, 0x11D4($at)
    MEM_W(0X11D4, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_8006CC0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CC0C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006CC10: lw          $v0, 0x11C8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X11C8);
    // 0x8006CC14: jr          $ra
    // 0x8006CC18: nop

    return;
    // 0x8006CC18: nop

;}
RECOMP_FUNC void func_8006CC1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CC1C: bltz        $a0, L_8006CC38
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006CC20: lui         $t6, 0x800D
        ctx->r14 = S32(0X800D << 16);
            goto L_8006CC38;
    }
    // 0x8006CC20: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006CC24: lw          $t6, 0x11C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11C8);
    // 0x8006CC28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006CC2C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006CC30: bne         $at, $zero, L_8006CC40
    if (ctx->r1 != 0) {
            // 0x8006CC34: nop

    func_8006CC40(rdram, ctx);
    return;
    }
    // 0x8006CC34: nop

L_8006CC38:
    // 0x8006CC38: jr          $ra
    // 0x8006CC3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006CC3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8006CC40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CC40: jr          $ra
    // 0x8006CC44: nop

    return;
    // 0x8006CC44: nop

;}
RECOMP_FUNC void func_8006CC48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CC48: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8006CC4C: addiu       $v1, $v1, 0x11CC
    ctx->r3 = ADD32(ctx->r3, 0X11CC);
    // 0x8006CC50: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // FALLTHROUGH: func_8006CC48 falls into func_8006CC54
    func_8006CC54(rdram, ctx);
;}
RECOMP_FUNC void func_8006CC54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CC54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CC58: bne         $t6, $zero, L_8006CC98
    if (ctx->r14 != 0) {
        // 0x8006CC5C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006CC98;
    }
    // 0x8006CC5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CC60: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006CC64: lw          $a0, 0x11C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11C4);
    // 0x8006CC68: jal         0x80068A0C
    // 0x8006CC6C: nop

    func_80068A0C(rdram, ctx);
        goto after_0;
    // 0x8006CC6C: nop

    after_0:
    // 0x8006CC70: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006CC74: addiu       $a0, $a0, 0x11D8
    ctx->r4 = ADD32(ctx->r4, 0X11D8);
    // 0x8006CC78: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8006CC7C: addiu       $v1, $v1, 0x11CC
    ctx->r3 = ADD32(ctx->r3, 0X11CC);
    // 0x8006CC80: bne         $v0, $zero, L_8006CC98
    if (ctx->r2 != 0) {
        // 0x8006CC84: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_8006CC98;
    }
    // 0x8006CC84: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8006CC88: jal         0x8006CBC0
    // 0x8006CC8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8006CBC0(rdram, ctx);
        goto after_1;
    // 0x8006CC8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8006CC90: b           L_8006CCA8
    // 0x8006CC94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006CCA8;
    // 0x8006CC94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006CC98:
    // 0x8006CC98: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8006CC9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006CCA0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8006CCA4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8006CCA8:
    // 0x8006CCA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CCAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CCB0: jr          $ra
    // 0x8006CCB4: nop

    return;
    // 0x8006CCB4: nop

;}
RECOMP_FUNC void func_8006CCB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CCB8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006CCBC: lw          $v0, 0x11CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X11CC);
    // FALLTHROUGH: func_8006CCB8 falls into func_8006CCC0
    func_8006CCC0(rdram, ctx);
;}
RECOMP_FUNC void func_8006CCC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CCC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CCC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006CCC8: bne         $v0, $at, L_8006CCEC
    if (ctx->r2 != ctx->r1) {
        // 0x8006CCCC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006CCEC;
    }
    // 0x8006CCCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CCD0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006CCD4: lw          $a0, 0x11D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11D8);
    // 0x8006CCD8: jal         0x80068ABC
    // 0x8006CCDC: nop

    func_80068ABC(rdram, ctx);
        goto after_0;
    // 0x8006CCDC: nop

    after_0:
    // 0x8006CCE0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006CCE4: lw          $v0, 0x11CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X11CC);
    // 0x8006CCE8: nop

L_8006CCEC:
    // 0x8006CCEC: blez        $v0, L_8006CCFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006CCF0: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8006CCFC;
    }
    // 0x8006CCF0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8006CCF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CCF8: sw          $t6, 0x11CC($at)
    MEM_W(0X11CC, ctx->r1) = ctx->r14;
L_8006CCFC:
    // 0x8006CCFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CD00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CD04: jr          $ra
    // 0x8006CD08: nop

    return;
    // 0x8006CD08: nop

;}
RECOMP_FUNC void func_8006CD0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CD0C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006CD10: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006CD14: lw          $t6, 0x11E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11E0);
    // 0x8006CD18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006CD1C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8006CD20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006CD24: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8006CD28: beq         $t6, $zero, L_8006D104
    if (ctx->r14 == 0) {
        // 0x8006CD2C: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_8006D104;
    }
    // 0x8006CD2C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8006CD30: jal         0x8006CC1C
    // 0x8006CD34: nop

    func_8006CC1C(rdram, ctx);
        goto after_0;
    // 0x8006CD34: nop

    after_0:
    // 0x8006CD38: bne         $v0, $zero, L_8006CD48
    if (ctx->r2 != 0) {
        // 0x8006CD3C: lui         $t7, 0x800D
        ctx->r15 = S32(0X800D << 16);
            goto L_8006CD48;
    }
    // 0x8006CD3C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006CD40: b           L_8006D110
    // 0x8006CD44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D110;
    // 0x8006CD44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006CD48:
    // 0x8006CD48: lw          $t7, 0x11C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11C0);
    // 0x8006CD4C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8006CD50: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8006CD54: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8006CD58: lw          $t9, 0x20($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20);
    // 0x8006CD5C: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x8006CD60: addu        $t0, $t9, $t3
    ctx->r8 = ADD32(ctx->r25, ctx->r11);
    // 0x8006CD64: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x8006CD68: lw          $t4, 0xCA8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XCA8);
    // 0x8006CD6C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006CD70: sltu        $at, $t4, $v0
    ctx->r1 = ctx->r12 < ctx->r2 ? 1 : 0;
    // 0x8006CD74: beq         $at, $zero, L_8006CD84
    if (ctx->r1 == 0) {
        // 0x8006CD78: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8006CD84;
    }
    // 0x8006CD78: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8006CD7C: b           L_8006D110
    // 0x8006CD80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D110;
    // 0x8006CD80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006CD84:
    // 0x8006CD84: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8006CD88: lw          $t6, 0x11DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11DC);
    // 0x8006CD8C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8006CD90: sw          $s0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r16;
    // 0x8006CD94: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8006CD98: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x8006CD9C: andi        $t8, $s0, 0x1
    ctx->r24 = ctx->r16 & 0X1;
    // 0x8006CDA0: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x8006CDA4: andi        $t2, $s0, 0x2
    ctx->r10 = ctx->r16 & 0X2;
    // 0x8006CDA8: addu        $s0, $s0, $t2
    ctx->r16 = ADD32(ctx->r16, ctx->r10);
    // 0x8006CDAC: andi        $t9, $s0, 0x4
    ctx->r25 = ctx->r16 & 0X4;
    // 0x8006CDB0: lw          $t5, 0x8($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X8);
    // 0x8006CDB4: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x8006CDB8: lbu         $a0, 0x2($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X2);
    // 0x8006CDBC: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x8006CDC0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8006CDC4: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x8006CDC8: bne         $a0, $zero, L_8006CEB4
    if (ctx->r4 != 0) {
        // 0x8006CDCC: addu        $s0, $s0, $v1
        ctx->r16 = ADD32(ctx->r16, ctx->r3);
            goto L_8006CEB4;
    }
    // 0x8006CDCC: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x8006CDD0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8006CDD4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8006CDD8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8006CDDC: jal         0x8006CC48
    // 0x8006CDE0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    func_8006CC48(rdram, ctx);
        goto after_1;
    // 0x8006CDE0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_1:
    // 0x8006CDE4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8006CDE8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8006CDEC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8006CDF0: bne         $v0, $zero, L_8006CE08
    if (ctx->r2 != 0) {
        // 0x8006CDF4: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_8006CE08;
    }
    // 0x8006CDF4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006CDF8: jal         0x8006CBC0
    // 0x8006CDFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8006CBC0(rdram, ctx);
        goto after_2;
    // 0x8006CDFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8006CE00: b           L_8006D110
    // 0x8006CE04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D110;
    // 0x8006CE04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006CE08:
    // 0x8006CE08: lw          $a0, 0x11D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11D8);
    // 0x8006CE0C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CE10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006CE14: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8006CE18: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8006CE1C: jal         0x80068A74
    // 0x8006CE20: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    func_80068A74(rdram, ctx);
        goto after_3;
    // 0x8006CE20: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_3:
    // 0x8006CE24: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8006CE28: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8006CE2C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8006CE30: beq         $v0, $zero, L_8006CE48
    if (ctx->r2 == 0) {
        // 0x8006CE34: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8006CE48;
    }
    // 0x8006CE34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8006CE38: jal         0x8006CBC0
    // 0x8006CE3C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8006CBC0(rdram, ctx);
        goto after_4;
    // 0x8006CE3C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x8006CE40: b           L_8006D110
    // 0x8006CE44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D110;
    // 0x8006CE44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006CE48:
    // 0x8006CE48: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x8006CE4C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006CE50: lw          $a2, 0x11D8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X11D8);
    // 0x8006CE54: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8006CE58: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8006CE5C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8006CE60: jal         0x80068A20
    // 0x8006CE64: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_80068A20(rdram, ctx);
        goto after_5;
    // 0x8006CE64: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_5:
    // 0x8006CE68: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8006CE6C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8006CE70: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8006CE74: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8006CE78: beq         $a1, $v0, L_8006CE90
    if (ctx->r5 == ctx->r2) {
        // 0x8006CE7C: nop
    
            goto L_8006CE90;
    }
    // 0x8006CE7C: nop

    // 0x8006CE80: jal         0x8006CBC0
    // 0x8006CE84: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8006CBC0(rdram, ctx);
        goto after_6;
    // 0x8006CE84: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x8006CE88: b           L_8006D110
    // 0x8006CE8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D110;
    // 0x8006CE8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006CE90:
    // 0x8006CE90: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8006CE94: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8006CE98: jal         0x8006CCB8
    // 0x8006CE9C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    func_8006CCB8(rdram, ctx);
        goto after_7;
    // 0x8006CE9C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_7:
    // 0x8006CEA0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8006CEA4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8006CEA8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8006CEAC: b           L_8006CEEC
    // 0x8006CEB0: nop

        goto L_8006CEEC;
    // 0x8006CEB0: nop

L_8006CEB4:
    // 0x8006CEB4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006CEB8: lw          $a1, 0x11C4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X11C4);
    // 0x8006CEBC: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8006CEC0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8006CEC4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8006CEC8: jal         0x800687D4
    // 0x8006CECC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    func_800687D4(rdram, ctx);
        goto after_8;
    // 0x8006CECC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_8:
    // 0x8006CED0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8006CED4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8006CED8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8006CEDC: bgez        $v0, L_8006CEEC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006CEE0: nop
    
            goto L_8006CEEC;
    }
    // 0x8006CEE0: nop

    // 0x8006CEE4: b           L_8006D110
    // 0x8006CEE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D110;
    // 0x8006CEE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006CEEC:
    // 0x8006CEEC: blez        $t1, L_8006D104
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8006CEF0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8006D104;
    }
    // 0x8006CEF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006CEF4: andi        $v0, $t1, 0x3
    ctx->r2 = ctx->r9 & 0X3;
    // 0x8006CEF8: beq         $v0, $zero, L_8006CF74
    if (ctx->r2 == 0) {
        // 0x8006CEFC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8006CF74;
    }
    // 0x8006CEFC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8006CF00: sll         $v1, $zero, 2
    ctx->r3 = S32(0 << 2);
    // 0x8006CF04: subu        $v1, $v1, $zero
    ctx->r3 = SUB32(ctx->r3, 0);
    // 0x8006CF08: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x8006CF0C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
L_8006CF10:
    // 0x8006CF10: addu        $t3, $a0, $v1
    ctx->r11 = ADD32(ctx->r4, ctx->r3);
    // 0x8006CF14: sw          $a3, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r7;
    // 0x8006CF18: lw          $t4, 0xC($t0)
    ctx->r12 = MEM_W(ctx->r8, 0XC);
    // 0x8006CF1C: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x8006CF20: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x8006CF24: sw          $a3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r7;
    // 0x8006CF28: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x8006CF2C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006CF30: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8006CF34: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8006CF38: nop

    // 0x8006CF3C: lh          $t8, 0xE($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XE);
    // 0x8006CF40: nop

    // 0x8006CF44: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x8006CF48: addu        $a3, $a3, $t2
    ctx->r7 = ADD32(ctx->r7, ctx->r10);
    // 0x8006CF4C: sw          $a3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r7;
    // 0x8006CF50: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x8006CF54: nop

    // 0x8006CF58: addu        $t9, $a0, $v1
    ctx->r25 = ADD32(ctx->r4, ctx->r3);
    // 0x8006CF5C: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x8006CF60: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8006CF64: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8006CF68: bne         $a2, $a1, L_8006CF10
    if (ctx->r6 != ctx->r5) {
        // 0x8006CF6C: addu        $a3, $a3, $t4
        ctx->r7 = ADD32(ctx->r7, ctx->r12);
            goto L_8006CF10;
    }
    // 0x8006CF6C: addu        $a3, $a3, $t4
    ctx->r7 = ADD32(ctx->r7, ctx->r12);
    // 0x8006CF70: beq         $a1, $t1, L_8006D104
    if (ctx->r5 == ctx->r9) {
        // 0x8006CF74: sll         $v1, $a1, 2
        ctx->r3 = S32(ctx->r5 << 2);
            goto L_8006D104;
    }
L_8006CF74:
    // 0x8006CF74: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8006CF78: sll         $a2, $t1, 2
    ctx->r6 = S32(ctx->r9 << 2);
    // 0x8006CF7C: subu        $a2, $a2, $t1
    ctx->r6 = SUB32(ctx->r6, ctx->r9);
    // 0x8006CF80: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x8006CF84: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x8006CF88: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8006CF8C: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
L_8006CF90:
    // 0x8006CF90: addu        $t5, $a0, $v1
    ctx->r13 = ADD32(ctx->r4, ctx->r3);
    // 0x8006CF94: sw          $a3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r7;
    // 0x8006CF98: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x8006CF9C: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x8006CFA0: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8006CFA4: sw          $a3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r7;
    // 0x8006CFA8: lw          $t8, 0xC($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC);
    // 0x8006CFAC: nop

    // 0x8006CFB0: addu        $v0, $t8, $v1
    ctx->r2 = ADD32(ctx->r24, ctx->r3);
    // 0x8006CFB4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8006CFB8: nop

    // 0x8006CFBC: lh          $t9, 0xE($t2)
    ctx->r25 = MEM_H(ctx->r10, 0XE);
    // 0x8006CFC0: nop

    // 0x8006CFC4: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8006CFC8: addu        $a3, $a3, $t3
    ctx->r7 = ADD32(ctx->r7, ctx->r11);
    // 0x8006CFCC: sw          $a3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r7;
    // 0x8006CFD0: lw          $t4, 0xC($t0)
    ctx->r12 = MEM_W(ctx->r8, 0XC);
    // 0x8006CFD4: nop

    // 0x8006CFD8: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x8006CFDC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8006CFE0: nop

    // 0x8006CFE4: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x8006CFE8: nop

    // 0x8006CFEC: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x8006CFF0: sw          $a3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r7;
    // 0x8006CFF4: lw          $t7, 0xC($t0)
    ctx->r15 = MEM_W(ctx->r8, 0XC);
    // 0x8006CFF8: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x8006CFFC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006D000: sw          $a3, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r7;
    // 0x8006D004: lw          $t2, 0xC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC);
    // 0x8006D008: nop

    // 0x8006D00C: addu        $v0, $t2, $v1
    ctx->r2 = ADD32(ctx->r10, ctx->r3);
    // 0x8006D010: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8006D014: nop

    // 0x8006D018: lh          $t3, 0xE($t9)
    ctx->r11 = MEM_H(ctx->r25, 0XE);
    // 0x8006D01C: nop

    // 0x8006D020: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8006D024: addu        $a3, $a3, $t4
    ctx->r7 = ADD32(ctx->r7, ctx->r12);
    // 0x8006D028: sw          $a3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r7;
    // 0x8006D02C: lw          $t5, 0xC($t0)
    ctx->r13 = MEM_W(ctx->r8, 0XC);
    // 0x8006D030: nop

    // 0x8006D034: addu        $v0, $t5, $v1
    ctx->r2 = ADD32(ctx->r13, ctx->r3);
    // 0x8006D038: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x8006D03C: nop

    // 0x8006D040: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8006D044: nop

    // 0x8006D048: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x8006D04C: sw          $a3, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r7;
    // 0x8006D050: lw          $t8, 0xC($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC);
    // 0x8006D054: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x8006D058: addu        $t2, $t8, $v1
    ctx->r10 = ADD32(ctx->r24, ctx->r3);
    // 0x8006D05C: sw          $a3, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r7;
    // 0x8006D060: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x8006D064: nop

    // 0x8006D068: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x8006D06C: lw          $t3, 0x18($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X18);
    // 0x8006D070: nop

    // 0x8006D074: lh          $t4, 0xE($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XE);
    // 0x8006D078: nop

    // 0x8006D07C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8006D080: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x8006D084: sw          $a3, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r7;
    // 0x8006D088: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x8006D08C: nop

    // 0x8006D090: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8006D094: lw          $t7, 0x18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18);
    // 0x8006D098: nop

    // 0x8006D09C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8006D0A0: nop

    // 0x8006D0A4: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x8006D0A8: sw          $a3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r7;
    // 0x8006D0AC: lw          $t2, 0xC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC);
    // 0x8006D0B0: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x8006D0B4: addu        $t9, $t2, $v1
    ctx->r25 = ADD32(ctx->r10, ctx->r3);
    // 0x8006D0B8: sw          $a3, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r7;
    // 0x8006D0BC: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x8006D0C0: nop

    // 0x8006D0C4: addu        $v0, $t3, $v1
    ctx->r2 = ADD32(ctx->r11, ctx->r3);
    // 0x8006D0C8: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x8006D0CC: nop

    // 0x8006D0D0: lh          $t5, 0xE($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XE);
    // 0x8006D0D4: nop

    // 0x8006D0D8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006D0DC: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x8006D0E0: sw          $a3, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r7;
    // 0x8006D0E4: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x8006D0E8: nop

    // 0x8006D0EC: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x8006D0F0: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x8006D0F4: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x8006D0F8: lw          $t2, 0x10($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X10);
    // 0x8006D0FC: bne         $v1, $a2, L_8006CF90
    if (ctx->r3 != ctx->r6) {
        // 0x8006D100: addu        $a3, $a3, $t2
        ctx->r7 = ADD32(ctx->r7, ctx->r10);
            goto L_8006CF90;
    }
    // 0x8006D100: addu        $a3, $a3, $t2
    ctx->r7 = ADD32(ctx->r7, ctx->r10);
L_8006D104:
    // 0x8006D104: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8006D108: nop

    // 0x8006D10C: subu        $v0, $s0, $t9
    ctx->r2 = SUB32(ctx->r16, ctx->r25);
L_8006D110:
    // 0x8006D110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006D114: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006D118: jr          $ra
    // 0x8006D11C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006D11C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8006D120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D120: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006D124: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D128: addiu       $v0, $v0, 0x11C0
    ctx->r2 = ADD32(ctx->r2, 0X11C0);
    // FALLTHROUGH: func_8006D120 falls into func_8006D12C
    func_8006D12C(rdram, ctx);
;}
RECOMP_FUNC void func_8006D12C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D12C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006D130: sw          $a1, 0x11C4($at)
    MEM_W(0X11C4, ctx->r1) = ctx->r5;
    // 0x8006D134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D138: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006D13C: beq         $a0, $zero, L_8006D1D0
    if (ctx->r4 == 0) {
        // 0x8006D140: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_8006D1D0;
    }
    // 0x8006D140: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8006D144: jal         0x8006CC48
    // 0x8006D148: nop

    func_8006CC48(rdram, ctx);
        goto after_0;
    // 0x8006D148: nop

    after_0:
    // 0x8006D14C: bne         $v0, $zero, L_8006D164
    if (ctx->r2 != 0) {
        // 0x8006D150: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_8006D164;
    }
    // 0x8006D150: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006D154: jal         0x8006CBC0
    // 0x8006D158: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8006CBC0(rdram, ctx);
        goto after_1;
    // 0x8006D158: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8006D15C: b           L_8006D1D4
    // 0x8006D160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D1D4;
    // 0x8006D160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D164:
    // 0x8006D164: lw          $a0, 0x11D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11D8);
    // 0x8006D168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006D16C: jal         0x80068A74
    // 0x8006D170: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80068A74(rdram, ctx);
        goto after_2;
    // 0x8006D170: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8006D174: beq         $v0, $zero, L_8006D18C
    if (ctx->r2 == 0) {
        // 0x8006D178: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_8006D18C;
    }
    // 0x8006D178: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006D17C: jal         0x8006CBC0
    // 0x8006D180: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8006CBC0(rdram, ctx);
        goto after_3;
    // 0x8006D180: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x8006D184: b           L_8006D1D4
    // 0x8006D188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D1D4;
    // 0x8006D188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D18C:
    // 0x8006D18C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006D190: lw          $a2, 0x11D8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X11D8);
    // 0x8006D194: addiu       $a0, $a0, 0x11A0
    ctx->r4 = ADD32(ctx->r4, 0X11A0);
    // 0x8006D198: jal         0x80068A20
    // 0x8006D19C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80068A20(rdram, ctx);
        goto after_4;
    // 0x8006D19C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_4:
    // 0x8006D1A0: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8006D1A4: beq         $v0, $at, L_8006D1BC
    if (ctx->r2 == ctx->r1) {
        // 0x8006D1A8: lui         $v1, 0x800D
        ctx->r3 = S32(0X800D << 16);
            goto L_8006D1BC;
    }
    // 0x8006D1A8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8006D1AC: jal         0x8006CBC0
    // 0x8006D1B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8006CBC0(rdram, ctx);
        goto after_5;
    // 0x8006D1B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x8006D1B4: b           L_8006D1D4
    // 0x8006D1B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D1D4;
    // 0x8006D1B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D1BC:
    // 0x8006D1BC: lw          $v1, 0x11B8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X11B8);
    // 0x8006D1C0: jal         0x8006CCB8
    // 0x8006D1C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8006CCB8(rdram, ctx);
        goto after_6;
    // 0x8006D1C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_6:
    // 0x8006D1C8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D1CC: nop

L_8006D1D0:
    // 0x8006D1D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8006D1D4:
    // 0x8006D1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D1D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006D1DC: jr          $ra
    // 0x8006D1E0: nop

    return;
    // 0x8006D1E0: nop

;}
RECOMP_FUNC void func_8006D1E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D1E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // FALLTHROUGH: func_8006D1E4 falls into func_8006D1E8
    func_8006D1E8(rdram, ctx);
;}
RECOMP_FUNC void func_8006D1E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D1E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006D1EC: sw          $zero, 0x11E0($at)
    MEM_W(0X11E0, ctx->r1) = 0;
    // 0x8006D1F0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8006D1F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D1F8: addiu       $t0, $t0, 0x11C0
    ctx->r8 = ADD32(ctx->r8, 0X11C0);
    // 0x8006D1FC: sw          $a1, 0x11C4($at)
    MEM_W(0X11C4, ctx->r1) = ctx->r5;
    // 0x8006D200: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006D204: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8006D208: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8006D20C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8006D210: beq         $a0, $zero, L_8006D38C
    if (ctx->r4 == 0) {
        // 0x8006D214: sw          $a0, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r4;
            goto L_8006D38C;
    }
    // 0x8006D214: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    // 0x8006D218: jal         0x8006CC48
    // 0x8006D21C: nop

    func_8006CC48(rdram, ctx);
        goto after_0;
    // 0x8006D21C: nop

    after_0:
    // 0x8006D220: bne         $v0, $zero, L_8006D238
    if (ctx->r2 != 0) {
        // 0x8006D224: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_8006D238;
    }
    // 0x8006D224: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006D228: jal         0x8006CBC0
    // 0x8006D22C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8006CBC0(rdram, ctx);
        goto after_1;
    // 0x8006D22C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8006D230: b           L_8006D394
    // 0x8006D234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D394;
    // 0x8006D234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D238:
    // 0x8006D238: lw          $a0, 0x11D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11D8);
    // 0x8006D23C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006D240: jal         0x80068A74
    // 0x8006D244: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80068A74(rdram, ctx);
        goto after_2;
    // 0x8006D244: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8006D248: beq         $v0, $zero, L_8006D260
    if (ctx->r2 == 0) {
        // 0x8006D24C: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_8006D260;
    }
    // 0x8006D24C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006D250: jal         0x8006CBC0
    // 0x8006D254: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8006CBC0(rdram, ctx);
        goto after_3;
    // 0x8006D254: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x8006D258: b           L_8006D394
    // 0x8006D25C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D394;
    // 0x8006D25C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D260:
    // 0x8006D260: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006D264: lw          $a2, 0x11D8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X11D8);
    // 0x8006D268: addiu       $a0, $a0, 0x11A0
    ctx->r4 = ADD32(ctx->r4, 0X11A0);
    // 0x8006D26C: jal         0x80068A20
    // 0x8006D270: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80068A20(rdram, ctx);
        goto after_4;
    // 0x8006D270: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_4:
    // 0x8006D274: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8006D278: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8006D27C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8006D280: addiu       $t0, $t0, 0x11C0
    ctx->r8 = ADD32(ctx->r8, 0X11C0);
    // 0x8006D284: beq         $v0, $at, L_8006D29C
    if (ctx->r2 == ctx->r1) {
        // 0x8006D288: addiu       $v1, $v1, 0x11A0
        ctx->r3 = ADD32(ctx->r3, 0X11A0);
            goto L_8006D29C;
    }
    // 0x8006D288: addiu       $v1, $v1, 0x11A0
    ctx->r3 = ADD32(ctx->r3, 0X11A0);
    // 0x8006D28C: jal         0x8006CBC0
    // 0x8006D290: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8006CBC0(rdram, ctx);
        goto after_5;
    // 0x8006D290: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x8006D294: b           L_8006D394
    // 0x8006D298: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D394;
    // 0x8006D298: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D29C:
    // 0x8006D29C: lhu         $t7, 0xE($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0XE);
    // 0x8006D2A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D2A4: sw          $t7, 0x11C8($at)
    MEM_W(0X11C8, ctx->r1) = ctx->r15;
    // 0x8006D2A8: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x8006D2AC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8006D2B0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8006D2B4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8006D2B8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8006D2BC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006D2C0: sw          $t9, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r25;
    // 0x8006D2C4: lbu         $a0, 0x10($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X10);
    // 0x8006D2C8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8006D2CC: bne         $a0, $zero, L_8006D328
    if (ctx->r4 != 0) {
        // 0x8006D2D0: nop
    
            goto L_8006D328;
    }
    // 0x8006D2D0: nop

    // 0x8006D2D4: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8006D2D8: lw          $a1, 0x18($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X18);
    // 0x8006D2DC: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8006D2E0: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006D2E4: lw          $a2, 0x11D8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X11D8);
    // 0x8006D2E8: lw          $a0, 0x20($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X20);
    // 0x8006D2EC: jal         0x80068A20
    // 0x8006D2F0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_80068A20(rdram, ctx);
        goto after_6;
    // 0x8006D2F0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_6:
    // 0x8006D2F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8006D2F8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8006D2FC: beq         $a1, $v0, L_8006D314
    if (ctx->r5 == ctx->r2) {
        // 0x8006D300: addiu       $v1, $v1, 0x11A0
        ctx->r3 = ADD32(ctx->r3, 0X11A0);
            goto L_8006D314;
    }
    // 0x8006D300: addiu       $v1, $v1, 0x11A0
    ctx->r3 = ADD32(ctx->r3, 0X11A0);
    // 0x8006D304: jal         0x8006CBC0
    // 0x8006D308: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8006CBC0(rdram, ctx);
        goto after_7;
    // 0x8006D308: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x8006D30C: b           L_8006D394
    // 0x8006D310: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D394;
    // 0x8006D310: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D314:
    // 0x8006D314: lw          $t5, 0x18($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X18);
    // 0x8006D318: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D31C: addiu       $t6, $t5, 0x20
    ctx->r14 = ADD32(ctx->r13, 0X20);
    // 0x8006D320: b           L_8006D368
    // 0x8006D324: sw          $t6, 0x11DC($at)
    MEM_W(0X11DC, ctx->r1) = ctx->r14;
        goto L_8006D368;
    // 0x8006D324: sw          $t6, 0x11DC($at)
    MEM_W(0X11DC, ctx->r1) = ctx->r14;
L_8006D328:
    // 0x8006D328: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8006D32C: lw          $t1, 0x18($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X18);
    // 0x8006D330: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8006D334: lw          $a1, 0x11C4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X11C4);
    // 0x8006D338: lw          $a3, 0x20($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X20);
    // 0x8006D33C: jal         0x800687D4
    // 0x8006D340: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800687D4(rdram, ctx);
        goto after_8;
    // 0x8006D340: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_8:
    // 0x8006D344: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8006D348: bgez        $v0, L_8006D358
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006D34C: addiu       $v1, $v1, 0x11A0
        ctx->r3 = ADD32(ctx->r3, 0X11A0);
            goto L_8006D358;
    }
    // 0x8006D34C: addiu       $v1, $v1, 0x11A0
    ctx->r3 = ADD32(ctx->r3, 0X11A0);
    // 0x8006D350: b           L_8006D394
    // 0x8006D354: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D394;
    // 0x8006D354: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D358:
    // 0x8006D358: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x8006D35C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D360: addiu       $t2, $t9, 0x20
    ctx->r10 = ADD32(ctx->r25, 0X20);
    // 0x8006D364: sw          $t2, 0x11DC($at)
    MEM_W(0X11DC, ctx->r1) = ctx->r10;
L_8006D368:
    // 0x8006D368: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8006D36C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006D370: beq         $t3, $at, L_8006D384
    if (ctx->r11 == ctx->r1) {
        // 0x8006D374: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8006D384;
    }
    // 0x8006D374: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8006D378: jal         0x8006CCB8
    // 0x8006D37C: nop

    func_8006CCB8(rdram, ctx);
        goto after_9;
    // 0x8006D37C: nop

    after_9:
    // 0x8006D380: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8006D384:
    // 0x8006D384: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D388: sw          $t4, 0x11E0($at)
    MEM_W(0X11E0, ctx->r1) = ctx->r12;
L_8006D38C:
    // 0x8006D38C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8006D390: nop

L_8006D394:
    // 0x8006D394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D398: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006D39C: jr          $ra
    // 0x8006D3A0: nop

    return;
    // 0x8006D3A0: nop

;}
RECOMP_FUNC void func_8006D3A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D3A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D3A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D3AC: jal         0x8006CCB8
    // 0x8006D3B0: nop

    func_8006CCB8(rdram, ctx);
        goto after_0;
    // 0x8006D3B0: nop

    after_0:
    // 0x8006D3B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D3B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D3BC: sw          $zero, 0x11E0($at)
    MEM_W(0X11E0, ctx->r1) = 0;
    // 0x8006D3C0: jr          $ra
    // 0x8006D3C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006D3C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006D3C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D3C8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006D3CC: lw          $t6, 0x11E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11E0);
    // FALLTHROUGH: func_8006D3C8 falls into func_8006D3D0
    func_8006D3D0(rdram, ctx);
;}
RECOMP_FUNC void func_8006D3D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D3D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006D3D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D3D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006D3DC: beq         $t6, $zero, L_8006D470
    if (ctx->r14 == 0) {
        // 0x8006D3E0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8006D470;
    }
    // 0x8006D3E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006D3E4: jal         0x8006CC1C
    // 0x8006D3E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_8006CC1C(rdram, ctx);
        goto after_0;
    // 0x8006D3E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_0:
    // 0x8006D3EC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006D3F0: bne         $v0, $zero, L_8006D400
    if (ctx->r2 != 0) {
        // 0x8006D3F4: lui         $t7, 0x800D
        ctx->r15 = S32(0X800D << 16);
            goto L_8006D400;
    }
    // 0x8006D3F4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006D3F8: b           L_8006D474
    // 0x8006D3FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D474;
    // 0x8006D3FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D400:
    // 0x8006D400: lw          $t7, 0x11C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11C0);
    // 0x8006D404: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006D408: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8006D40C: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8006D410: lw          $t9, 0x20($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20);
    // 0x8006D414: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8006D418: addu        $v1, $t9, $t1
    ctx->r3 = ADD32(ctx->r25, ctx->r9);
    // 0x8006D41C: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x8006D420: lw          $t2, 0xCA8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCA8);
    // 0x8006D424: nop

    // 0x8006D428: sltu        $at, $t2, $a0
    ctx->r1 = ctx->r10 < ctx->r4 ? 1 : 0;
    // 0x8006D42C: beq         $at, $zero, L_8006D43C
    if (ctx->r1 == 0) {
        // 0x8006D430: nop
    
            goto L_8006D43C;
    }
    // 0x8006D430: nop

    // 0x8006D434: b           L_8006D474
    // 0x8006D438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D474;
    // 0x8006D438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D43C:
    // 0x8006D43C: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x8006D440: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8006D444: bne         $t3, $zero, L_8006D470
    if (ctx->r11 != 0) {
        // 0x8006D448: subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
            goto L_8006D470;
    }
    // 0x8006D448: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8006D44C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006D450: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x8006D454: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x8006D458: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    // 0x8006D45C: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x8006D460: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8006D464: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x8006D468: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8006D46C: addu        $a1, $t7, $v0
    ctx->r5 = ADD32(ctx->r15, ctx->r2);
L_8006D470:
    // 0x8006D470: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8006D474:
    // 0x8006D474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D478: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006D47C: jr          $ra
    // 0x8006D480: nop

    return;
    // 0x8006D480: nop

;}
RECOMP_FUNC void func_8006D484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D484: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006D488: lw          $t6, 0x11E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11E0);
    // FALLTHROUGH: func_8006D484 falls into func_8006D48C
    func_8006D48C(rdram, ctx);
;}
RECOMP_FUNC void func_8006D48C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D48C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006D490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D494: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006D498: beq         $t6, $zero, L_8006D4FC
    if (ctx->r14 == 0) {
        // 0x8006D49C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006D4FC;
    }
    // 0x8006D49C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006D4A0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8006D4A4: jal         0x8006CC1C
    // 0x8006D4A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8006CC1C(rdram, ctx);
        goto after_0;
    // 0x8006D4A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006D4AC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D4B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006D4B4: bne         $v0, $zero, L_8006D4C4
    if (ctx->r2 != 0) {
        // 0x8006D4B8: lui         $t7, 0x800D
        ctx->r15 = S32(0X800D << 16);
            goto L_8006D4C4;
    }
    // 0x8006D4B8: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006D4BC: b           L_8006D500
    // 0x8006D4C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D500;
    // 0x8006D4C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D4C4:
    // 0x8006D4C4: lw          $t7, 0x11C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11C0);
    // 0x8006D4C8: sll         $t0, $a0, 4
    ctx->r8 = S32(ctx->r4 << 4);
    // 0x8006D4CC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8006D4D0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006D4D4: lw          $t9, 0x20($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20);
    // 0x8006D4D8: nop

    // 0x8006D4DC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8006D4E0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8006D4E4: nop

    // 0x8006D4E8: bne         $t2, $zero, L_8006D500
    if (ctx->r10 != 0) {
        // 0x8006D4EC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8006D500;
    }
    // 0x8006D4EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006D4F0: jal         0x8006CD0C
    // 0x8006D4F4: nop

    func_8006CD0C(rdram, ctx);
        goto after_1;
    // 0x8006D4F4: nop

    after_1:
    // 0x8006D4F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8006D4FC:
    // 0x8006D4FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8006D500:
    // 0x8006D500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D504: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006D508: jr          $ra
    // 0x8006D50C: nop

    return;
    // 0x8006D50C: nop

;}
RECOMP_FUNC void func_8006D510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D510: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006D514: lw          $t6, 0x11E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11E0);
    // FALLTHROUGH: func_8006D510 falls into func_8006D518
    func_8006D518(rdram, ctx);
;}
RECOMP_FUNC void func_8006D518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D518: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006D51C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D520: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006D524: beq         $t6, $zero, L_8006D57C
    if (ctx->r14 == 0) {
        // 0x8006D528: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006D57C;
    }
    // 0x8006D528: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006D52C: jal         0x8006CC1C
    // 0x8006D530: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_8006CC1C(rdram, ctx);
        goto after_0;
    // 0x8006D530: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x8006D534: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D538: bne         $v0, $zero, L_8006D548
    if (ctx->r2 != 0) {
        // 0x8006D53C: lui         $t7, 0x800D
        ctx->r15 = S32(0X800D << 16);
            goto L_8006D548;
    }
    // 0x8006D53C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006D540: b           L_8006D580
    // 0x8006D544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D580;
    // 0x8006D544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D548:
    // 0x8006D548: lw          $t7, 0x11C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11C0);
    // 0x8006D54C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006D550: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8006D554: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8006D558: lw          $t9, 0x20($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20);
    // 0x8006D55C: nop

    // 0x8006D560: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x8006D564: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x8006D568: nop

    // 0x8006D56C: beq         $t2, $zero, L_8006D57C
    if (ctx->r10 == 0) {
        // 0x8006D570: nop
    
            goto L_8006D57C;
    }
    // 0x8006D570: nop

    // 0x8006D574: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8006D578: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8006D57C:
    // 0x8006D57C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8006D580:
    // 0x8006D580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D584: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006D588: jr          $ra
    // 0x8006D58C: nop

    return;
    // 0x8006D58C: nop

;}
RECOMP_FUNC void func_8006D590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D590: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006D594: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006D598: lw          $t6, 0x11E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11E0);
    // 0x8006D59C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006D5A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006D5A4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006D5A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006D5AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006D5B0: beq         $t6, $zero, L_8006D5E8
    if (ctx->r14 == 0) {
        // 0x8006D5B4: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8006D5E8;
    }
    // 0x8006D5B4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8006D5B8: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x8006D5BC: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x8006D5C0: beq         $s3, $t7, L_8006D5EC
    if (ctx->r19 == ctx->r15) {
        // 0x8006D5C4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006D5EC;
    }
    // 0x8006D5C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006D5C8: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x8006D5CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
L_8006D5D0:
    // 0x8006D5D0: jal         0x8006D3C8
    // 0x8006D5D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8006D3C8(rdram, ctx);
        goto after_0;
    // 0x8006D5D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8006D5D8: lh          $s1, 0x2($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X2);
    // 0x8006D5DC: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x8006D5E0: bne         $s3, $s1, L_8006D5D0
    if (ctx->r19 != ctx->r17) {
        // 0x8006D5E4: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8006D5D0;
    }
    // 0x8006D5E4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_8006D5E8:
    // 0x8006D5E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006D5EC:
    // 0x8006D5EC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8006D5F0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D5F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006D5F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006D5FC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006D600: jr          $ra
    // 0x8006D604: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006D604: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006D608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D608: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006D60C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006D610: lw          $t6, 0x11E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11E0);
    // 0x8006D614: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006D618: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006D61C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8006D620: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006D624: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006D628: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006D62C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006D630: beq         $t6, $zero, L_8006D690
    if (ctx->r14 == 0) {
        // 0x8006D634: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8006D690;
    }
    // 0x8006D634: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8006D638: jal         0x8006CC48
    // 0x8006D63C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_8006CC48(rdram, ctx);
        goto after_0;
    // 0x8006D63C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006D640: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8006D644: bne         $v0, $zero, L_8006D654
    if (ctx->r2 != 0) {
        // 0x8006D648: nop
    
            goto L_8006D654;
    }
    // 0x8006D648: nop

    // 0x8006D64C: b           L_8006D694
    // 0x8006D650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006D694;
    // 0x8006D650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D654:
    // 0x8006D654: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x8006D658: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x8006D65C: beq         $s3, $t7, L_8006D688
    if (ctx->r19 == ctx->r15) {
        // 0x8006D660: nop
    
            goto L_8006D688;
    }
    // 0x8006D660: nop

    // 0x8006D664: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x8006D668: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
L_8006D66C:
    // 0x8006D66C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006D670: jal         0x8006D484
    // 0x8006D674: addu        $a1, $s4, $s2
    ctx->r5 = ADD32(ctx->r20, ctx->r18);
    func_8006D484(rdram, ctx);
        goto after_1;
    // 0x8006D674: addu        $a1, $s4, $s2
    ctx->r5 = ADD32(ctx->r20, ctx->r18);
    after_1:
    // 0x8006D678: lh          $s1, 0x2($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X2);
    // 0x8006D67C: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x8006D680: bne         $s3, $s1, L_8006D66C
    if (ctx->r19 != ctx->r17) {
        // 0x8006D684: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8006D66C;
    }
    // 0x8006D684: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_8006D688:
    // 0x8006D688: jal         0x8006CCB8
    // 0x8006D68C: nop

    func_8006CCB8(rdram, ctx);
        goto after_2;
    // 0x8006D68C: nop

    after_2:
L_8006D690:
    // 0x8006D690: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8006D694:
    // 0x8006D694: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006D698: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006D69C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D6A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006D6A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006D6A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006D6AC: jr          $ra
    // 0x8006D6B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006D6B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
