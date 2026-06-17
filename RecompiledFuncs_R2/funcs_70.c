#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_80068A90(uint8_t* rdram, recomp_context* ctx);
void func_80069338(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_800687DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800687DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800687E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800687E4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800687E8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800687EC: beq         $v0, $zero, L_80068808
    if (ctx->r2 == 0) {
        // 0x800687F0: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80068808;
    }
    // 0x800687F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800687F4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800687F8: jalr        $v0
    // 0x800687FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800687FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x80068800: b           L_80068810
    // 0x80068804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80068810;
    // 0x80068804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80068808:
    // 0x80068808: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006880C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80068810:
    // 0x80068810: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80068814: jr          $ra
    // 0x80068818: nop

    return;
    // 0x80068818: nop

;}
RECOMP_FUNC void func_8006881C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006881C: jr          $ra
    // 0x80068820: nop

    return;
    // 0x80068820: nop

;}
RECOMP_FUNC void func_80068824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068824: jr          $ra
    // 0x80068828: nop

    return;
    // 0x80068828: nop

;}
RECOMP_FUNC void func_8006882C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006882C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80068830: jr          $ra
    // 0x80068834: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80068834: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80068838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068838: jr          $ra
    // 0x8006883C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006883C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80068840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068840: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80068844: jr          $ra
    // 0x80068848: sw          $zero, 0xCC0($at)
    MEM_W(0XCC0, ctx->r1) = 0;
    return;
    // 0x80068848: sw          $zero, 0xCC0($at)
    MEM_W(0XCC0, ctx->r1) = 0;
;}
RECOMP_FUNC void func_8006884C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006884C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80068850: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80068854: jr          $ra
    // 0x80068858: sw          $t6, 0xCC0($at)
    MEM_W(0XCC0, ctx->r1) = ctx->r14;
    return;
    // 0x80068858: sw          $t6, 0xCC0($at)
    MEM_W(0XCC0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8006885C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006885C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80068860: addiu       $a0, $a0, 0xCC8
    ctx->r4 = ADD32(ctx->r4, 0XCC8);
    // 0x80068864: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // FALLTHROUGH: func_8006885C falls into func_80068868
    func_80068868(rdram, ctx);
;}
RECOMP_FUNC void func_80068868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068868: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006886C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80068870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068874: bne         $v0, $zero, L_8006888C
    if (ctx->r2 != 0) {
        // 0x80068878: sw          $t6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r14;
            goto L_8006888C;
    }
    // 0x80068878: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8006887C: jal         0x8006D8E0
    // 0x80068880: nop

    func_8006D8E0(rdram, ctx);
        goto after_0;
    // 0x80068880: nop

    after_0:
    // 0x80068884: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80068888: sw          $v0, -0x16A8($at)
    MEM_W(-0X16A8, ctx->r1) = ctx->r2;
L_8006888C:
    // 0x8006888C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068890: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068894: jr          $ra
    // 0x80068898: nop

    return;
    // 0x80068898: nop

;}
RECOMP_FUNC void func_8006889C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006889C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800688A0: addiu       $v0, $v0, 0xCC8
    ctx->r2 = ADD32(ctx->r2, 0XCC8);
    // 0x800688A4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // FALLTHROUGH: func_8006889C falls into func_800688A8
    func_800688A8(rdram, ctx);
;}
RECOMP_FUNC void func_800688A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800688A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800688AC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800688B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800688B4: bne         $t7, $zero, L_800688CC
    if (ctx->r15 != 0) {
        // 0x800688B8: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_800688CC;
    }
    // 0x800688B8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800688BC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800688C0: lw          $a0, -0x16A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X16A8);
    // 0x800688C4: jal         0x8006D900
    // 0x800688C8: nop

    func_8006D900(rdram, ctx);
        goto after_0;
    // 0x800688C8: nop

    after_0:
L_800688CC:
    // 0x800688CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800688D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800688D4: jr          $ra
    // 0x800688D8: nop

    return;
    // 0x800688D8: nop

;}
RECOMP_FUNC void func_800688DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800688DC: jr          $ra
    // 0x800688E0: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    return;
    // 0x800688E0: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
;}
RECOMP_FUNC void func_800688E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800688E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800688E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800688EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800688F0: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    // 0x800688F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800688F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800688FC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80068900: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x80068904: jal         0x80072FD0
    // 0x80068908: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    func_80072FD0(rdram, ctx);
        goto after_0;
    // 0x80068908: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_0:
    // 0x8006890C: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x80068910: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80068914: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80068918: jal         0x80072FD0
    // 0x8006891C: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    func_80072FD0(rdram, ctx);
        goto after_1;
    // 0x8006891C: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_1:
    // 0x80068920: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80068924: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80068928: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8006892C: jal         0x80072F44
    // 0x80068930: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    func_80072F44(rdram, ctx);
        goto after_2;
    // 0x80068930: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    after_2:
    // 0x80068934: lh          $a3, 0x1A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1A);
    // 0x80068938: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006893C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80068940: jal         0x80072F44
    // 0x80068944: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    func_80072F44(rdram, ctx);
        goto after_3;
    // 0x80068944: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_3:
    // 0x80068948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006894C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068950: jr          $ra
    // 0x80068954: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80068954: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80068958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068958: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8006895C: addiu       $v1, $v1, 0xCC4
    ctx->r3 = ADD32(ctx->r3, 0XCC4);
    // 0x80068960: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80068964: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x80068968: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8006896C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80068970: ori         $at, $at, 0x5555
    ctx->r1 = ctx->r1 | 0X5555;
    // 0x80068974: addiu       $a1, $a1, 0xCBC
    ctx->r5 = ADD32(ctx->r5, 0XCBC);
    // 0x80068978: addiu       $a0, $a0, 0xCB8
    ctx->r4 = ADD32(ctx->r4, 0XCB8);
    // 0x8006897C: addu        $v0, $t8, $at
    ctx->r2 = ADD32(ctx->r24, ctx->r1);
    // 0x80068980: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80068984: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80068988: srl         $t1, $v0, 16
    ctx->r9 = S32(U32(ctx->r2) >> 16);
    // 0x8006898C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80068990: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x80068994: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80068998: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8006899C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800689A0: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800689A4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800689A8: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x800689AC: lw          $t4, 0xCC0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XCC0);

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_800689B0
    func_800689B0(rdram, ctx);
}
RECOMP_FUNC void func_800689B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800689B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800689B4: beq         $t4, $zero, L_800689CC
    if (ctx->r12 == 0) {
        // 0x800689B8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800689CC;
    }
    // 0x800689B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800689BC: jal         0x80069338
    // 0x800689C0: nop

    func_80069338(rdram, ctx);
        goto after_0;
    // 0x800689C0: nop

    after_0:
    // 0x800689C4: jal         0x8006A8AC
    // 0x800689C8: nop

    func_8006A8AC(rdram, ctx);
        goto after_1;
    // 0x800689C8: nop

    after_1:
L_800689CC:
    // 0x800689CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800689D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800689D4: jr          $ra
    // 0x800689D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800689D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_800689DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800689DC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800689E0: sw          $zero, 0xCC0($at)
    MEM_W(0XCC0, ctx->r1) = 0;
    // 0x800689E4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800689E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800689EC: jr          $ra
    // 0x800689F0: sw          $t6, 0xCB4($at)
    MEM_W(0XCB4, ctx->r1) = ctx->r14;
    return;
    // 0x800689F0: sw          $t6, 0xCB4($at)
    MEM_W(0XCB4, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_800689F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800689F4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800689F8: jr          $ra
    // 0x800689FC: sw          $zero, 0xCB4($at)
    MEM_W(0XCB4, ctx->r1) = 0;
    return;
    // 0x800689FC: sw          $zero, 0xCB4($at)
    MEM_W(0XCB4, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80068A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068A00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80068A04: jr          $ra
    // 0x80068A08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80068A08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80068A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068A0C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80068A10: addiu       $v0, $v1, -0x16C0
    ctx->r2 = ADD32(ctx->r3, -0X16C0);
    // 0x80068A14: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80068A18: jr          $ra
    // 0x80068A1C: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    return;
    // 0x80068A1C: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_80068A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068A20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068A24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80068A28: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80068A2C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80068A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068A34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80068A38: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80068A3C: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x80068A40: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80068A44: jal         0x80061824
    // 0x80068A48: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80061824(rdram, ctx);
        goto after_0;
    // 0x80068A48: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80068A4C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80068A50: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80068A54: lw          $t6, 0x4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4);
    // 0x80068A58: nop

    // 0x80068A5C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80068A60: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x80068A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068A6C: jr          $ra
    // 0x80068A70: nop

    return;
    // 0x80068A70: nop

;}
RECOMP_FUNC void func_80068A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068A74: bne         $a2, $zero, L_80068A90
    if (ctx->r6 != 0) {
            // 0x80068A78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    func_80068A90(rdram, ctx);
    return;
    }
    // 0x80068A78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80068A7C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80068A80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80068A84: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80068A88: jr          $ra
    // 0x80068A8C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    return;
    // 0x80068A8C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80068A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068A90: bne         $a2, $at, L_80068AA8
    if (ctx->r6 != ctx->r1) {
        // 0x80068A94: nop
    
            goto L_80068AA8;
    }
    // 0x80068A94: nop

    // 0x80068A98: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80068A9C: nop

    // 0x80068AA0: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80068AA4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
L_80068AA8:
    // 0x80068AA8: jr          $ra
    // 0x80068AAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80068AAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80068AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068AB0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80068AB4: jr          $ra
    // 0x80068AB8: nop

    return;
    // 0x80068AB8: nop

;}
RECOMP_FUNC void func_80068ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068ABC: jr          $ra
    // 0x80068AC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80068AC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80068AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068AC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80068AC8: jr          $ra
    // 0x80068ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80068ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80068AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068AD0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80068AD4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80068AD8: jr          $ra
    // 0x80068ADC: addiu       $v0, $v0, -0x16B8
    ctx->r2 = ADD32(ctx->r2, -0X16B8);
    return;
    // 0x80068ADC: addiu       $v0, $v0, -0x16B8
    ctx->r2 = ADD32(ctx->r2, -0X16B8);
;}
RECOMP_FUNC void func_80068AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068AE0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80068AE4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80068AE8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80068AEC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80068AF0: jr          $ra
    // 0x80068AF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80068AF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80068AF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068AF8: jr          $ra
    // 0x80068AFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80068AFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80068B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068B00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068B08: jal         0x80062974
    // 0x80068B0C: nop

    func_80062974(rdram, ctx);
        goto after_0;
    // 0x80068B0C: nop

    after_0:
    // 0x80068B10: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80068B14: lw          $v1, 0xC94($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC94);
    // 0x80068B18: nop

    // 0x80068B1C: sltiu       $at, $v1, 0x80
    ctx->r1 = ctx->r3 < 0X80 ? 1 : 0;
    // 0x80068B20: bne         $at, $zero, L_80068B30
    if (ctx->r1 != 0) {
        // 0x80068B24: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_80068B30;
    }
    // 0x80068B24: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80068B28: b           L_80068B30
    // 0x80068B2C: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
        goto L_80068B30;
    // 0x80068B2C: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
L_80068B30:
    // 0x80068B30: beq         $v0, $zero, L_80068C8C
    if (ctx->r2 == 0) {
        // 0x80068B34: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80068C8C;
    }
    // 0x80068B34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80068B38: blez        $t1, L_80068C84
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80068B3C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80068C84;
    }
    // 0x80068B3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80068B40: andi        $a2, $t1, 0x3
    ctx->r6 = ctx->r9 & 0X3;
    // 0x80068B44: beq         $a2, $zero, L_80068BA4
    if (ctx->r6 == 0) {
        // 0x80068B48: or          $t0, $a2, $zero
        ctx->r8 = ctx->r6 | 0;
            goto L_80068BA4;
    }
    // 0x80068B48: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80068B4C: sll         $a0, $zero, 2
    ctx->r4 = S32(0 << 2);
    // 0x80068B50: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80068B54: addiu       $t6, $t6, -0x16A0
    ctx->r14 = ADD32(ctx->r14, -0X16A0);
    // 0x80068B58: subu        $a0, $a0, $zero
    ctx->r4 = SUB32(ctx->r4, 0);
    // 0x80068B5C: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80068B60: addu        $v1, $zero, $t6
    ctx->r3 = ADD32(0, ctx->r14);
    // 0x80068B64: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x80068B68: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
L_80068B6C:
    // 0x80068B6C: lw          $t7, 0x18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18);
    // 0x80068B70: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80068B74: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80068B78: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80068B7C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x80068B80: srl         $t2, $t9, 31
    ctx->r10 = S32(U32(ctx->r25) >> 31);
    // 0x80068B84: beq         $t2, $zero, L_80068B94
    if (ctx->r10 == 0) {
        // 0x80068B88: nop
    
            goto L_80068B94;
    }
    // 0x80068B88: nop

    // 0x80068B8C: b           L_80068B98
    // 0x80068B90: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_80068B98;
    // 0x80068B90: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_80068B94:
    // 0x80068B94: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
L_80068B98:
    // 0x80068B98: bne         $t0, $a1, L_80068B6C
    if (ctx->r8 != ctx->r5) {
        // 0x80068B9C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80068B6C;
    }
    // 0x80068B9C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80068BA0: beq         $a1, $t1, L_80068C84
    if (ctx->r5 == ctx->r9) {
        // 0x80068BA4: lui         $t3, 0x800D
        ctx->r11 = S32(0X800D << 16);
            goto L_80068C84;
    }
L_80068BA4:
    // 0x80068BA4: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80068BA8: addiu       $t3, $t3, -0x16A0
    ctx->r11 = ADD32(ctx->r11, -0X16A0);
    // 0x80068BAC: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x80068BB0: subu        $a0, $a0, $a1
    ctx->r4 = SUB32(ctx->r4, ctx->r5);
    // 0x80068BB4: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80068BB8: addu        $v1, $a1, $t3
    ctx->r3 = ADD32(ctx->r5, ctx->r11);
    // 0x80068BBC: addu        $t0, $t1, $t3
    ctx->r8 = ADD32(ctx->r9, ctx->r11);
    // 0x80068BC0: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
    // 0x80068BC4: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
L_80068BC8:
    // 0x80068BC8: lw          $t4, 0x18($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X18);
    // 0x80068BCC: nop

    // 0x80068BD0: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80068BD4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80068BD8: nop

    // 0x80068BDC: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80068BE0: beq         $t7, $zero, L_80068BF0
    if (ctx->r15 == 0) {
        // 0x80068BE4: nop
    
            goto L_80068BF0;
    }
    // 0x80068BE4: nop

    // 0x80068BE8: b           L_80068BF4
    // 0x80068BEC: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_80068BF4;
    // 0x80068BEC: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_80068BF0:
    // 0x80068BF0: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
L_80068BF4:
    // 0x80068BF4: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x80068BF8: nop

    // 0x80068BFC: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x80068C00: lw          $t2, 0x18($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X18);
    // 0x80068C04: nop

    // 0x80068C08: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x80068C0C: beq         $t3, $zero, L_80068C1C
    if (ctx->r11 == 0) {
        // 0x80068C10: nop
    
            goto L_80068C1C;
    }
    // 0x80068C10: nop

    // 0x80068C14: b           L_80068C20
    // 0x80068C18: sb          $a2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r6;
        goto L_80068C20;
    // 0x80068C18: sb          $a2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r6;
L_80068C1C:
    // 0x80068C1C: sb          $a3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r7;
L_80068C20:
    // 0x80068C20: lw          $t4, 0x18($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X18);
    // 0x80068C24: nop

    // 0x80068C28: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80068C2C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80068C30: nop

    // 0x80068C34: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80068C38: beq         $t7, $zero, L_80068C48
    if (ctx->r15 == 0) {
        // 0x80068C3C: nop
    
            goto L_80068C48;
    }
    // 0x80068C3C: nop

    // 0x80068C40: b           L_80068C4C
    // 0x80068C44: sb          $a2, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r6;
        goto L_80068C4C;
    // 0x80068C44: sb          $a2, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r6;
L_80068C48:
    // 0x80068C48: sb          $a3, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r7;
L_80068C4C:
    // 0x80068C4C: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x80068C50: nop

    // 0x80068C54: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x80068C58: lw          $t2, 0x48($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X48);
    // 0x80068C5C: nop

    // 0x80068C60: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x80068C64: beq         $t3, $zero, L_80068C74
    if (ctx->r11 == 0) {
        // 0x80068C68: nop
    
            goto L_80068C74;
    }
    // 0x80068C68: nop

    // 0x80068C6C: b           L_80068C78
    // 0x80068C70: sb          $a2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r6;
        goto L_80068C78;
    // 0x80068C70: sb          $a2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r6;
L_80068C74:
    // 0x80068C74: sb          $a3, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r7;
L_80068C78:
    // 0x80068C78: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80068C7C: bne         $v1, $t0, L_80068BC8
    if (ctx->r3 != ctx->r8) {
        // 0x80068C80: addiu       $a0, $a0, 0x60
        ctx->r4 = ADD32(ctx->r4, 0X60);
            goto L_80068BC8;
    }
    // 0x80068C80: addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
L_80068C84:
    // 0x80068C84: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80068C88: sb          $zero, -0x16A0($at)
    MEM_B(-0X16A0, ctx->r1) = 0;
L_80068C8C:
    // 0x80068C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068C90: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80068C94: addiu       $v0, $v0, -0x16A0
    ctx->r2 = ADD32(ctx->r2, -0X16A0);
    // 0x80068C98: jr          $ra
    // 0x80068C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80068C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80068CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068CA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068CA8: jal         0x80062974
    // 0x80068CAC: nop

    func_80062974(rdram, ctx);
        goto after_0;
    // 0x80068CAC: nop

    after_0:
    // 0x80068CB0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80068CB4: lw          $v1, 0xC98($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC98);
    // 0x80068CB8: nop

    // 0x80068CBC: sltiu       $at, $v1, 0x80
    ctx->r1 = ctx->r3 < 0X80 ? 1 : 0;
    // 0x80068CC0: bne         $at, $zero, L_80068CD0
    if (ctx->r1 != 0) {
        // 0x80068CC4: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_80068CD0;
    }
    // 0x80068CC4: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80068CC8: b           L_80068CD0
    // 0x80068CCC: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
        goto L_80068CD0;
    // 0x80068CCC: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
L_80068CD0:
    // 0x80068CD0: beq         $v0, $zero, L_80068E28
    if (ctx->r2 == 0) {
        // 0x80068CD4: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80068E28;
    }
    // 0x80068CD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80068CD8: blez        $t1, L_80068E20
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80068CDC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80068E20;
    }
    // 0x80068CDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80068CE0: andi        $a2, $t1, 0x3
    ctx->r6 = ctx->r9 & 0X3;
    // 0x80068CE4: beq         $a2, $zero, L_80068D40
    if (ctx->r6 == 0) {
        // 0x80068CE8: or          $t0, $a2, $zero
        ctx->r8 = ctx->r6 | 0;
            goto L_80068D40;
    }
    // 0x80068CE8: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80068CEC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80068CF0: addiu       $t6, $t6, -0x1620
    ctx->r14 = ADD32(ctx->r14, -0X1620);
    // 0x80068CF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80068CF8: sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4 << 6);
    // 0x80068CFC: addu        $v1, $zero, $t6
    ctx->r3 = ADD32(0, ctx->r14);
    // 0x80068D00: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x80068D04: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
L_80068D08:
    // 0x80068D08: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x80068D0C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80068D10: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80068D14: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80068D18: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x80068D1C: srl         $t2, $t9, 31
    ctx->r10 = S32(U32(ctx->r25) >> 31);
    // 0x80068D20: beq         $t2, $zero, L_80068D30
    if (ctx->r10 == 0) {
        // 0x80068D24: nop
    
            goto L_80068D30;
    }
    // 0x80068D24: nop

    // 0x80068D28: b           L_80068D34
    // 0x80068D2C: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_80068D34;
    // 0x80068D2C: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_80068D30:
    // 0x80068D30: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
L_80068D34:
    // 0x80068D34: bne         $t0, $a1, L_80068D08
    if (ctx->r8 != ctx->r5) {
        // 0x80068D38: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80068D08;
    }
    // 0x80068D38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80068D3C: beq         $a1, $t1, L_80068E20
    if (ctx->r5 == ctx->r9) {
        // 0x80068D40: lui         $t3, 0x800D
        ctx->r11 = S32(0X800D << 16);
            goto L_80068E20;
    }
L_80068D40:
    // 0x80068D40: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80068D44: addiu       $t3, $t3, -0x1620
    ctx->r11 = ADD32(ctx->r11, -0X1620);
    // 0x80068D48: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x80068D4C: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x80068D50: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x80068D54: addu        $v1, $a1, $t3
    ctx->r3 = ADD32(ctx->r5, ctx->r11);
    // 0x80068D58: addu        $t0, $t1, $t3
    ctx->r8 = ADD32(ctx->r9, ctx->r11);
    // 0x80068D5C: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
    // 0x80068D60: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
L_80068D64:
    // 0x80068D64: lw          $t4, 0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C);
    // 0x80068D68: nop

    // 0x80068D6C: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80068D70: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80068D74: nop

    // 0x80068D78: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80068D7C: beq         $t7, $zero, L_80068D8C
    if (ctx->r15 == 0) {
        // 0x80068D80: nop
    
            goto L_80068D8C;
    }
    // 0x80068D80: nop

    // 0x80068D84: b           L_80068D90
    // 0x80068D88: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_80068D90;
    // 0x80068D88: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_80068D8C:
    // 0x80068D8C: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
L_80068D90:
    // 0x80068D90: lw          $t8, 0x1C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1C);
    // 0x80068D94: nop

    // 0x80068D98: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x80068D9C: lw          $t2, 0x50($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X50);
    // 0x80068DA0: nop

    // 0x80068DA4: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x80068DA8: beq         $t3, $zero, L_80068DB8
    if (ctx->r11 == 0) {
        // 0x80068DAC: nop
    
            goto L_80068DB8;
    }
    // 0x80068DAC: nop

    // 0x80068DB0: b           L_80068DBC
    // 0x80068DB4: sb          $a2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r6;
        goto L_80068DBC;
    // 0x80068DB4: sb          $a2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r6;
L_80068DB8:
    // 0x80068DB8: sb          $a3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r7;
L_80068DBC:
    // 0x80068DBC: lw          $t4, 0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C);
    // 0x80068DC0: nop

    // 0x80068DC4: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80068DC8: lw          $t6, 0xA0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XA0);
    // 0x80068DCC: nop

    // 0x80068DD0: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80068DD4: beq         $t7, $zero, L_80068DE4
    if (ctx->r15 == 0) {
        // 0x80068DD8: nop
    
            goto L_80068DE4;
    }
    // 0x80068DD8: nop

    // 0x80068DDC: b           L_80068DE8
    // 0x80068DE0: sb          $a2, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r6;
        goto L_80068DE8;
    // 0x80068DE0: sb          $a2, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r6;
L_80068DE4:
    // 0x80068DE4: sb          $a3, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r7;
L_80068DE8:
    // 0x80068DE8: lw          $t8, 0x1C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1C);
    // 0x80068DEC: nop

    // 0x80068DF0: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x80068DF4: lw          $t2, 0xF0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0XF0);
    // 0x80068DF8: nop

    // 0x80068DFC: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x80068E00: beq         $t3, $zero, L_80068E10
    if (ctx->r11 == 0) {
        // 0x80068E04: nop
    
            goto L_80068E10;
    }
    // 0x80068E04: nop

    // 0x80068E08: b           L_80068E14
    // 0x80068E0C: sb          $a2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r6;
        goto L_80068E14;
    // 0x80068E0C: sb          $a2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r6;
L_80068E10:
    // 0x80068E10: sb          $a3, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r7;
L_80068E14:
    // 0x80068E14: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80068E18: bne         $v1, $t0, L_80068D64
    if (ctx->r3 != ctx->r8) {
        // 0x80068E1C: addiu       $a0, $a0, 0x140
        ctx->r4 = ADD32(ctx->r4, 0X140);
            goto L_80068D64;
    }
    // 0x80068E1C: addiu       $a0, $a0, 0x140
    ctx->r4 = ADD32(ctx->r4, 0X140);
L_80068E20:
    // 0x80068E20: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80068E24: sb          $zero, -0x1620($at)
    MEM_B(-0X1620, ctx->r1) = 0;
L_80068E28:
    // 0x80068E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068E2C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80068E30: addiu       $v0, $v0, -0x1620
    ctx->r2 = ADD32(ctx->r2, -0X1620);
    // 0x80068E34: jr          $ra
    // 0x80068E38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80068E38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80068E3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068E3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068E40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068E44: jal         0x80062974
    // 0x80068E48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80062974(rdram, ctx);
        goto after_0;
    // 0x80068E48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80068E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068E50: beq         $v0, $zero, L_80068E7C
    if (ctx->r2 == 0) {
        // 0x80068E54: nop
    
            goto L_80068E7C;
    }
    // 0x80068E54: nop

    // 0x80068E58: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80068E5C: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x80068E60: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80068E64: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80068E68: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80068E6C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80068E70: lbu         $v0, 0xD($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0XD);
    // 0x80068E74: b           L_80068E80
    // 0x80068E78: nop

        goto L_80068E80;
    // 0x80068E78: nop

L_80068E7C:
    // 0x80068E7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80068E80:
    // 0x80068E80: jr          $ra
    // 0x80068E84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80068E84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80068E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068E88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068E8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068E90: jal         0x80062974
    // 0x80068E94: nop

    func_80062974(rdram, ctx);
        goto after_0;
    // 0x80068E94: nop

    after_0:
    // 0x80068E98: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80068E9C: lw          $v1, 0xC8C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC8C);
    // 0x80068EA0: nop

    // 0x80068EA4: sltiu       $at, $v1, 0x80
    ctx->r1 = ctx->r3 < 0X80 ? 1 : 0;
    // 0x80068EA8: bne         $at, $zero, L_80068EB8
    if (ctx->r1 != 0) {
        // 0x80068EAC: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_80068EB8;
    }
    // 0x80068EAC: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80068EB0: b           L_80068EB8
    // 0x80068EB4: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
        goto L_80068EB8;
    // 0x80068EB4: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
L_80068EB8:
    // 0x80068EB8: beq         $v0, $zero, L_80069010
    if (ctx->r2 == 0) {
        // 0x80068EBC: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80069010;
    }
    // 0x80068EBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80068EC0: blez        $t1, L_80069008
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80068EC4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80069008;
    }
    // 0x80068EC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80068EC8: andi        $a2, $t1, 0x3
    ctx->r6 = ctx->r9 & 0X3;
    // 0x80068ECC: beq         $a2, $zero, L_80068F28
    if (ctx->r6 == 0) {
        // 0x80068ED0: or          $t0, $a2, $zero
        ctx->r8 = ctx->r6 | 0;
            goto L_80068F28;
    }
    // 0x80068ED0: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80068ED4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80068ED8: addiu       $t6, $t6, -0x15A0
    ctx->r14 = ADD32(ctx->r14, -0X15A0);
    // 0x80068EDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80068EE0: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x80068EE4: addu        $v1, $zero, $t6
    ctx->r3 = ADD32(0, ctx->r14);
    // 0x80068EE8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x80068EEC: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
L_80068EF0:
    // 0x80068EF0: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x80068EF4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80068EF8: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80068EFC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80068F00: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x80068F04: srl         $t2, $t9, 31
    ctx->r10 = S32(U32(ctx->r25) >> 31);
    // 0x80068F08: beq         $t2, $zero, L_80068F18
    if (ctx->r10 == 0) {
        // 0x80068F0C: nop
    
            goto L_80068F18;
    }
    // 0x80068F0C: nop

    // 0x80068F10: b           L_80068F1C
    // 0x80068F14: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_80068F1C;
    // 0x80068F14: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_80068F18:
    // 0x80068F18: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
L_80068F1C:
    // 0x80068F1C: bne         $t0, $a1, L_80068EF0
    if (ctx->r8 != ctx->r5) {
        // 0x80068F20: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80068EF0;
    }
    // 0x80068F20: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80068F24: beq         $a1, $t1, L_80069008
    if (ctx->r5 == ctx->r9) {
        // 0x80068F28: lui         $t3, 0x800D
        ctx->r11 = S32(0X800D << 16);
            goto L_80069008;
    }
L_80068F28:
    // 0x80068F28: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80068F2C: addiu       $t3, $t3, -0x15A0
    ctx->r11 = ADD32(ctx->r11, -0X15A0);
    // 0x80068F30: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x80068F34: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x80068F38: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80068F3C: addu        $v1, $a1, $t3
    ctx->r3 = ADD32(ctx->r5, ctx->r11);
    // 0x80068F40: addu        $t0, $t1, $t3
    ctx->r8 = ADD32(ctx->r9, ctx->r11);
    // 0x80068F44: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
    // 0x80068F48: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
L_80068F4C:
    // 0x80068F4C: lw          $t4, 0x20($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X20);
    // 0x80068F50: nop

    // 0x80068F54: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80068F58: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80068F5C: nop

    // 0x80068F60: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80068F64: beq         $t7, $zero, L_80068F74
    if (ctx->r15 == 0) {
        // 0x80068F68: nop
    
            goto L_80068F74;
    }
    // 0x80068F68: nop

    // 0x80068F6C: b           L_80068F78
    // 0x80068F70: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_80068F78;
    // 0x80068F70: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_80068F74:
    // 0x80068F74: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
L_80068F78:
    // 0x80068F78: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x80068F7C: nop

    // 0x80068F80: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x80068F84: lw          $t2, 0x14($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X14);
    // 0x80068F88: nop

    // 0x80068F8C: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x80068F90: beq         $t3, $zero, L_80068FA0
    if (ctx->r11 == 0) {
        // 0x80068F94: nop
    
            goto L_80068FA0;
    }
    // 0x80068F94: nop

    // 0x80068F98: b           L_80068FA4
    // 0x80068F9C: sb          $a2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r6;
        goto L_80068FA4;
    // 0x80068F9C: sb          $a2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r6;
L_80068FA0:
    // 0x80068FA0: sb          $a3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r7;
L_80068FA4:
    // 0x80068FA4: lw          $t4, 0x20($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X20);
    // 0x80068FA8: nop

    // 0x80068FAC: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80068FB0: lw          $t6, 0x28($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X28);
    // 0x80068FB4: nop

    // 0x80068FB8: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80068FBC: beq         $t7, $zero, L_80068FCC
    if (ctx->r15 == 0) {
        // 0x80068FC0: nop
    
            goto L_80068FCC;
    }
    // 0x80068FC0: nop

    // 0x80068FC4: b           L_80068FD0
    // 0x80068FC8: sb          $a2, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r6;
        goto L_80068FD0;
    // 0x80068FC8: sb          $a2, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r6;
L_80068FCC:
    // 0x80068FCC: sb          $a3, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r7;
L_80068FD0:
    // 0x80068FD0: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x80068FD4: nop

    // 0x80068FD8: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x80068FDC: lw          $t2, 0x3C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X3C);
    // 0x80068FE0: nop

    // 0x80068FE4: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x80068FE8: beq         $t3, $zero, L_80068FF8
    if (ctx->r11 == 0) {
        // 0x80068FEC: nop
    
            goto L_80068FF8;
    }
    // 0x80068FEC: nop

    // 0x80068FF0: b           L_80068FFC
    // 0x80068FF4: sb          $a2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r6;
        goto L_80068FFC;
    // 0x80068FF4: sb          $a2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r6;
L_80068FF8:
    // 0x80068FF8: sb          $a3, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r7;
L_80068FFC:
    // 0x80068FFC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80069000: bne         $v1, $t0, L_80068F4C
    if (ctx->r3 != ctx->r8) {
        // 0x80069004: addiu       $a0, $a0, 0x50
        ctx->r4 = ADD32(ctx->r4, 0X50);
            goto L_80068F4C;
    }
    // 0x80069004: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
L_80069008:
    // 0x80069008: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8006900C: sb          $zero, -0x15A0($at)
    MEM_B(-0X15A0, ctx->r1) = 0;
L_80069010:
    // 0x80069010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069014: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80069018: addiu       $v0, $v0, -0x15A0
    ctx->r2 = ADD32(ctx->r2, -0X15A0);
    // 0x8006901C: jr          $ra
    // 0x80069020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80069020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80069024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006902C: jal         0x80062974
    // 0x80069030: nop

    func_80062974(rdram, ctx);
        goto after_0;
    // 0x80069030: nop

    after_0:
    // 0x80069034: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80069038: lw          $v1, 0xC8C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC8C);
    // 0x8006903C: nop

    // 0x80069040: sltiu       $at, $v1, 0x80
    ctx->r1 = ctx->r3 < 0X80 ? 1 : 0;
    // 0x80069044: bne         $at, $zero, L_80069054
    if (ctx->r1 != 0) {
        // 0x80069048: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_80069054;
    }
    // 0x80069048: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8006904C: b           L_80069054
    // 0x80069050: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
        goto L_80069054;
    // 0x80069050: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
L_80069054:
    // 0x80069054: beq         $v0, $zero, L_800691AC
    if (ctx->r2 == 0) {
        // 0x80069058: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800691AC;
    }
    // 0x80069058: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006905C: blez        $t1, L_800691A4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80069060: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800691A4;
    }
    // 0x80069060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80069064: andi        $a2, $t1, 0x3
    ctx->r6 = ctx->r9 & 0X3;
    // 0x80069068: beq         $a2, $zero, L_800690C4
    if (ctx->r6 == 0) {
        // 0x8006906C: or          $t0, $a2, $zero
        ctx->r8 = ctx->r6 | 0;
            goto L_800690C4;
    }
    // 0x8006906C: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80069070: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80069074: addiu       $t6, $t6, -0x1520
    ctx->r14 = ADD32(ctx->r14, -0X1520);
    // 0x80069078: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006907C: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x80069080: addu        $v1, $zero, $t6
    ctx->r3 = ADD32(0, ctx->r14);
    // 0x80069084: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x80069088: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
L_8006908C:
    // 0x8006908C: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x80069090: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80069094: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80069098: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8006909C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800690A0: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x800690A4: bgez        $t3, L_800690B4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800690A8: nop
    
            goto L_800690B4;
    }
    // 0x800690A8: nop

    // 0x800690AC: b           L_800690B8
    // 0x800690B0: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_800690B8;
    // 0x800690B0: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_800690B4:
    // 0x800690B4: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
L_800690B8:
    // 0x800690B8: bne         $t0, $a1, L_8006908C
    if (ctx->r8 != ctx->r5) {
        // 0x800690BC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8006908C;
    }
    // 0x800690BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800690C0: beq         $a1, $t1, L_800691A4
    if (ctx->r5 == ctx->r9) {
        // 0x800690C4: lui         $t4, 0x800D
        ctx->r12 = S32(0X800D << 16);
            goto L_800691A4;
    }
L_800690C4:
    // 0x800690C4: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800690C8: addiu       $t4, $t4, -0x1520
    ctx->r12 = ADD32(ctx->r12, -0X1520);
    // 0x800690CC: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x800690D0: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x800690D4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800690D8: addu        $v1, $a1, $t4
    ctx->r3 = ADD32(ctx->r5, ctx->r12);
    // 0x800690DC: addu        $t0, $t1, $t4
    ctx->r8 = ADD32(ctx->r9, ctx->r12);
    // 0x800690E0: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
    // 0x800690E4: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
L_800690E8:
    // 0x800690E8: lw          $t5, 0x20($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X20);
    // 0x800690EC: nop

    // 0x800690F0: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x800690F4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800690F8: nop

    // 0x800690FC: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80069100: bgez        $t9, L_80069110
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80069104: nop
    
            goto L_80069110;
    }
    // 0x80069104: nop

    // 0x80069108: b           L_80069114
    // 0x8006910C: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_80069114;
    // 0x8006910C: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_80069110:
    // 0x80069110: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
L_80069114:
    // 0x80069114: lw          $t2, 0x20($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X20);
    // 0x80069118: nop

    // 0x8006911C: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x80069120: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x80069124: nop

    // 0x80069128: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x8006912C: bgez        $t6, L_8006913C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80069130: nop
    
            goto L_8006913C;
    }
    // 0x80069130: nop

    // 0x80069134: b           L_80069140
    // 0x80069138: sb          $a2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r6;
        goto L_80069140;
    // 0x80069138: sb          $a2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r6;
L_8006913C:
    // 0x8006913C: sb          $a3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r7;
L_80069140:
    // 0x80069140: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x80069144: nop

    // 0x80069148: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8006914C: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x80069150: nop

    // 0x80069154: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x80069158: bgez        $t3, L_80069168
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8006915C: nop
    
            goto L_80069168;
    }
    // 0x8006915C: nop

    // 0x80069160: b           L_8006916C
    // 0x80069164: sb          $a2, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r6;
        goto L_8006916C;
    // 0x80069164: sb          $a2, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r6;
L_80069168:
    // 0x80069168: sb          $a3, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r7;
L_8006916C:
    // 0x8006916C: lw          $t4, 0x20($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X20);
    // 0x80069170: nop

    // 0x80069174: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80069178: lw          $t6, 0x3C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X3C);
    // 0x8006917C: nop

    // 0x80069180: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80069184: bgez        $t8, L_80069194
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80069188: nop
    
            goto L_80069194;
    }
    // 0x80069188: nop

    // 0x8006918C: b           L_80069198
    // 0x80069190: sb          $a2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r6;
        goto L_80069198;
    // 0x80069190: sb          $a2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r6;
L_80069194:
    // 0x80069194: sb          $a3, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r7;
L_80069198:
    // 0x80069198: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006919C: bne         $v1, $t0, L_800690E8
    if (ctx->r3 != ctx->r8) {
        // 0x800691A0: addiu       $a0, $a0, 0x50
        ctx->r4 = ADD32(ctx->r4, 0X50);
            goto L_800690E8;
    }
    // 0x800691A0: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
L_800691A4:
    // 0x800691A4: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800691A8: sb          $zero, -0x1520($at)
    MEM_B(-0X1520, ctx->r1) = 0;
L_800691AC:
    // 0x800691AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800691B0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800691B4: addiu       $v0, $v0, -0x1520
    ctx->r2 = ADD32(ctx->r2, -0X1520);
    // 0x800691B8: jr          $ra
    // 0x800691BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800691BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800691C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800691C0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800691C4: beq         $a2, $zero, L_800691E8
    if (ctx->r6 == 0) {
        // 0x800691C8: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800691E8;
    }
    // 0x800691C8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800691CC:
    // 0x800691CC: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800691D0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800691D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800691D8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800691DC: sb          $t6, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r14;
    // 0x800691E0: bne         $a2, $zero, L_800691CC
    if (ctx->r6 != 0) {
        // 0x800691E4: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800691CC;
    }
    // 0x800691E4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800691E8:
    // 0x800691E8: jr          $ra
    // 0x800691EC: nop

    return;
    // 0x800691EC: nop

;}
RECOMP_FUNC void func_800691F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800691F0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800691F4: addiu       $v0, $v0, 0xD10
    ctx->r2 = ADD32(ctx->r2, 0XD10);
    // 0x800691F8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800691FC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80069200: bne         $t6, $zero, L_80069240
    if (ctx->r14 != 0) {
        // 0x80069204: addiu       $v1, $v1, 0xD0C
        ctx->r3 = ADD32(ctx->r3, 0XD0C);
            return; // L_80069240 is jr $ra
    }
    // 0x80069204: addiu       $v1, $v1, 0xD0C
    ctx->r3 = ADD32(ctx->r3, 0XD0C);
    // 0x80069208: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8006920C: nop

    // 0x80069210: slti        $at, $t7, 0x200
    ctx->r1 = SIGNED(ctx->r15) < 0X200 ? 1 : 0;
    // 0x80069214: beq         $at, $zero, L_8006923C
    if (ctx->r1 == 0) {
        // 0x80069218: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            return; // L_8006923C is jr $ra
    }
    // 0x80069218: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006921C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80069220: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80069224: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80069228: sb          $a0, 0xB60($at)
    MEM_B(0XB60, ctx->r1) = ctx->r4;
    // 0x8006922C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80069230: jr          $ra
    // 0x80069234: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    return;
    // 0x80069234: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void func_80069238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069238: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006923C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80069240: jr          $ra
    // 0x80069244: nop

    return;
    // 0x80069244: nop

;}
RECOMP_FUNC void func_80069248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069248: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8006924C: addiu       $t0, $t0, 0xD10
    ctx->r8 = ADD32(ctx->r8, 0XD10);
    // 0x80069250: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // FALLTHROUGH: func_80069248 falls into func_80069254
    func_80069254(rdram, ctx);
;}
RECOMP_FUNC void func_80069254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006925C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80069260: bne         $t6, $zero, L_800692E4
    if (ctx->r14 != 0) {
        // 0x80069264: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800692E4;
    }
    // 0x80069264: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80069268: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8006926C: addiu       $v0, $v0, 0xD14
    ctx->r2 = ADD32(ctx->r2, 0XD14);
    // 0x80069270: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80069274: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80069278: addiu       $t7, $t7, -0x14A0
    ctx->r15 = ADD32(ctx->r15, -0X14A0);
    // 0x8006927C: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x80069280: addiu       $t9, $t8, 0x2000
    ctx->r25 = ADD32(ctx->r24, 0X2000);
    // 0x80069284: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80069288: bne         $at, $zero, L_800692B8
    if (ctx->r1 != 0) {
        // 0x8006928C: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_800692B8;
    }
    // 0x8006928C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80069290: jal         0x800691C0
    // 0x80069294: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_800691C0(rdram, ctx);
        goto after_0;
    // 0x80069294: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80069298: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8006929C: addiu       $v0, $v0, 0xD14
    ctx->r2 = ADD32(ctx->r2, 0XD14);
    // 0x800692A0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800692A4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800692A8: nop

    // 0x800692AC: addu        $t2, $t1, $a2
    ctx->r10 = ADD32(ctx->r9, ctx->r6);
    // 0x800692B0: b           L_800692E4
    // 0x800692B4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
        goto L_800692E4;
    // 0x800692B4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_800692B8:
    // 0x800692B8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800692BC: addiu       $v1, $v1, 0xD0C
    ctx->r3 = ADD32(ctx->r3, 0XD0C);
    // 0x800692C0: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800692C4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800692C8: blez        $t3, L_800692E0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800692CC: nop
    
            goto L_800692E0;
    }
    // 0x800692CC: nop

    // 0x800692D0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800692D4: nop

    // 0x800692D8: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x800692DC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_800692E0:
    // 0x800692E0: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_800692E4:
    // 0x800692E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800692E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800692EC: jr          $ra
    // 0x800692F0: nop

    return;
    // 0x800692F0: nop

;}
RECOMP_FUNC void func_800692F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800692F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800692F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800692FC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069304: lw          $a1, 0xD60($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XD60);
    // 0x80069308: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8006930C: jal         0x800691C0
    // 0x80069310: nop

    func_800691C0(rdram, ctx);
        goto after_0;
    // 0x80069310: nop

    after_0:
    // 0x80069314: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80069318: addiu       $v0, $v0, 0xD60
    ctx->r2 = ADD32(ctx->r2, 0XD60);
    // 0x8006931C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80069320: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80069324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069328: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8006932C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80069330: jr          $ra
    // 0x80069334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80069334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80069338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069338: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006933C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80069340: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80069344: sw          $zero, 0xD10($at)
    MEM_W(0XD10, ctx->r1) = 0;
    // 0x80069348: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006934C: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80069350: addiu       $t6, $t6, -0x14A0
    ctx->r14 = ADD32(ctx->r14, -0X14A0);
    // 0x80069354: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80069358: addiu       $s3, $s3, 0xD0C
    ctx->r19 = ADD32(ctx->r19, 0XD0C);
    // 0x8006935C: sw          $t6, 0xD60($at)
    MEM_W(0XD60, ctx->r1) = ctx->r14;
    // 0x80069360: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80069364: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80069368: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006936C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80069370: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80069374: blez        $t7, L_800693C0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80069378: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800693C0;
    }
    // 0x80069378: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006937C: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80069380: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80069384: addiu       $s2, $s2, 0xCD0
    ctx->r18 = ADD32(ctx->r18, 0XCD0);
    // 0x80069388: addiu       $s1, $s1, 0xB60
    ctx->r17 = ADD32(ctx->r17, 0XB60);
L_8006938C:
    // 0x8006938C: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x80069390: nop

    // 0x80069394: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80069398: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x8006939C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800693A0: nop

    // 0x800693A4: jalr        $t9
    // 0x800693A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800693A8: nop

    after_0:
    // 0x800693AC: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800693B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800693B4: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800693B8: bne         $at, $zero, L_8006938C
    if (ctx->r1 != 0) {
        // 0x800693BC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8006938C;
    }
    // 0x800693BC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800693C0:
    // 0x800693C0: jal         0x8006885C
    // 0x800693C4: nop

    func_8006885C(rdram, ctx);
        goto after_1;
    // 0x800693C4: nop

    after_1:
    // 0x800693C8: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800693CC: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x800693D0: addiu       $t2, $t2, -0x14A0
    ctx->r10 = ADD32(ctx->r10, -0X14A0);
    // 0x800693D4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800693D8: jal         0x8006889C
    // 0x800693DC: sw          $t2, 0xD14($at)
    MEM_W(0XD14, ctx->r1) = ctx->r10;
    func_8006889C(rdram, ctx);
        goto after_2;
    // 0x800693DC: sw          $t2, 0xD14($at)
    MEM_W(0XD14, ctx->r1) = ctx->r10;
    after_2:
    // 0x800693E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800693E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800693E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800693EC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800693F0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800693F4: jr          $ra
    // 0x800693F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800693F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800693FC: nop

;}
RECOMP_FUNC void func_80069400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069408: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006940C: jal         0x800629CC
    // 0x80069410: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800629CC(rdram, ctx);
        goto after_0;
    // 0x80069410: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80069414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006941C: jr          $ra
    // 0x80069420: nop

    return;
    // 0x80069420: nop

;}
RECOMP_FUNC void func_80069424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069424: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006942C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80069430: jal         0x800629A8
    // 0x80069434: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800629A8(rdram, ctx);
        goto after_0;
    // 0x80069434: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80069438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006943C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069440: jr          $ra
    // 0x80069444: nop

    return;
    // 0x80069444: nop

;}
RECOMP_FUNC void func_80069448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006944C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069450: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80069454: jal         0x800629CC
    // 0x80069458: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800629CC(rdram, ctx);
        goto after_0;
    // 0x80069458: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8006945C: beq         $v0, $zero, L_80069474
    if (ctx->r2 == 0) {
        // 0x80069460: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069474;
    }
    // 0x80069460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069464: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80069468: jal         0x800629CC
    // 0x8006946C: nop

    func_800629CC(rdram, ctx);
        goto after_1;
    // 0x8006946C: nop

    after_1:
    // 0x80069470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069474:
    // 0x80069474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069478: jr          $ra
    // 0x8006947C: nop

    return;
    // 0x8006947C: nop

;}
RECOMP_FUNC void func_80069480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069480: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80069484: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80069488: andi        $t6, $v1, 0x80
    ctx->r14 = ctx->r3 & 0X80;
    // 0x8006948C: beq         $t6, $zero, L_800694C0
    if (ctx->r14 == 0) {
        // 0x80069490: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800694C0;
    }
    // 0x80069490: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80069494: andi        $t7, $v1, 0x7F
    ctx->r15 = ctx->r3 & 0X7F;
    // 0x80069498: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_8006949C:
    // 0x8006949C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800694A0: sll         $t9, $v1, 7
    ctx->r25 = S32(ctx->r3 << 7);
    // 0x800694A4: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x800694A8: andi        $t0, $v0, 0x80
    ctx->r8 = ctx->r2 & 0X80;
    // 0x800694AC: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800694B0: bne         $t0, $zero, L_8006949C
    if (ctx->r8 != 0) {
        // 0x800694B4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8006949C;
    }
    // 0x800694B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800694B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800694BC: sb          $v0, 0xD74($at)
    MEM_B(0XD74, ctx->r1) = ctx->r2;
L_800694C0:
    // 0x800694C0: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x800694C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800694C8: sw          $v1, 0xD70($at)
    MEM_W(0XD70, ctx->r1) = ctx->r3;
    // 0x800694CC: jr          $ra
    // 0x800694D0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800694D0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_800694D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800694D4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800694D8: andi        $t6, $a1, 0x7F
    ctx->r14 = ctx->r5 & 0X7F;
    // 0x800694DC: srl         $t7, $a1, 7
    ctx->r15 = S32(U32(ctx->r5) >> 7);
    // 0x800694E0: sb          $t6, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r14;
    // 0x800694E4: addiu       $v0, $sp, 0x5
    ctx->r2 = ADD32(ctx->r29, 0X5);
    // 0x800694E8: beq         $t7, $zero, L_8006950C
    if (ctx->r15 == 0) {
        // 0x800694EC: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_8006950C;
    }
    // 0x800694EC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_800694F0:
    // 0x800694F0: andi        $t8, $a1, 0x7F
    ctx->r24 = ctx->r5 & 0X7F;
    // 0x800694F4: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x800694F8: srl         $t0, $a1, 7
    ctx->r8 = S32(U32(ctx->r5) >> 7);
    // 0x800694FC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x80069500: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80069504: bne         $t0, $zero, L_800694F0
    if (ctx->r8 != 0) {
        // 0x80069508: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800694F0;
    }
    // 0x80069508: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006950C:
    // 0x8006950C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80069510:
    // 0x80069510: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80069514: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80069518: sb          $t1, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r9;
    // 0x8006951C: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80069520: nop

    // 0x80069524: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x80069528: beq         $t3, $zero, L_80069538
    if (ctx->r11 == 0) {
        // 0x8006952C: nop
    
            goto L_80069538;
    }
    // 0x8006952C: nop

    // 0x80069530: b           L_80069510
    // 0x80069534: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80069510;
    // 0x80069534: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80069538:
    // 0x80069538: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006953C: jr          $ra
    // 0x80069540: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80069540: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80069544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069544: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80069548: addiu       $a1, $sp, 0x4
    ctx->r5 = ADD32(ctx->r29, 0X4);
    // 0x8006954C: andi        $t6, $a0, 0x7F
    ctx->r14 = ctx->r4 & 0X7F;
    // 0x80069550: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x80069554: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80069558: sb          $t6, 0x14($sp)
    MEM_B(0X14, ctx->r29) = ctx->r14;
    // 0x8006955C: addiu       $v0, $sp, 0x15
    ctx->r2 = ADD32(ctx->r29, 0X15);
    // 0x80069560: beq         $t7, $zero, L_80069584
    if (ctx->r15 == 0) {
        // 0x80069564: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_80069584;
    }
    // 0x80069564: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_80069568:
    // 0x80069568: andi        $t8, $a0, 0x7F
    ctx->r24 = ctx->r4 & 0X7F;
    // 0x8006956C: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x80069570: srl         $t0, $a0, 7
    ctx->r8 = S32(U32(ctx->r4) >> 7);
    // 0x80069574: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80069578: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8006957C: bne         $t0, $zero, L_80069568
    if (ctx->r8 != 0) {
        // 0x80069580: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80069568;
    }
    // 0x80069580: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80069584:
    // 0x80069584: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80069588:
    // 0x80069588: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x8006958C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80069590: sb          $t1, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r9;
    // 0x80069594: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80069598: nop

    // 0x8006959C: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x800695A0: beq         $t3, $zero, L_800695B0
    if (ctx->r11 == 0) {
        // 0x800695A4: nop
    
            goto L_800695B0;
    }
    // 0x800695A4: nop

    // 0x800695A8: b           L_80069588
    // 0x800695AC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80069588;
    // 0x800695AC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800695B0:
    // 0x800695B0: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // 0x800695B4: andi        $t4, $v0, 0xFF
    ctx->r12 = ctx->r2 & 0XFF;
    // 0x800695B8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x800695BC: jr          $ra
    // 0x800695C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800695C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800695C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800695C4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800695C8: addiu       $v1, $v1, 0xE10
    ctx->r3 = ADD32(ctx->r3, 0XE10);
    // 0x800695CC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800695D0: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x800695D4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800695D8: sw          $t6, 0xE08($at)
    MEM_W(0XE08, ctx->r1) = ctx->r14;
    // 0x800695DC: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x800695E0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800695E4: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x800695E8: lw          $t8, 0xC98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XC98);
    // 0x800695EC: sw          $t7, 0xE0C($at)
    MEM_W(0XE0C, ctx->r1) = ctx->r15;
    // 0x800695F0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800695F4: jr          $ra
    // 0x800695F8: sb          $t8, 0xE04($at)
    MEM_B(0XE04, ctx->r1) = ctx->r24;
    return;
    // 0x800695F8: sb          $t8, 0xE04($at)
    MEM_B(0XE04, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void func_800695FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800695FC: jr          $ra
    // 0x80069600: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80069600: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80069604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069604: jr          $ra
    // 0x80069608: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80069608: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8006960C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006960C: jr          $ra
    // 0x80069610: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80069610: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
