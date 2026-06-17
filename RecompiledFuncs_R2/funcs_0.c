#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

// Forward declarations
void func_80000540(uint8_t* rdram, recomp_context* ctx);
void func_80000788(uint8_t* rdram, recomp_context* ctx);
void func_800008BC(uint8_t* rdram, recomp_context* ctx);
void func_80000D18(uint8_t* rdram, recomp_context* ctx);
void func_80000DCC(uint8_t* rdram, recomp_context* ctx);
void func_80000E14(uint8_t* rdram, recomp_context* ctx);
void func_80000E84(uint8_t* rdram, recomp_context* ctx);
void func_80000EDC(uint8_t* rdram, recomp_context* ctx);
void func_80000F5C(uint8_t* rdram, recomp_context* ctx);
void func_80000F64(uint8_t* rdram, recomp_context* ctx);
void func_80000F80(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000400: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80000404: addiu       $t0, $t0, 0x26E0
    ctx->r8 = ADD32(ctx->r8, 0X26E0);
    // 0x80000408: lui         $t1, 0xD
    ctx->r9 = S32(0XD << 16);
    // 0x8000040C: addiu       $t1, $t1, -0x36D0
    ctx->r9 = ADD32(ctx->r9, -0X36D0);
L_80000410:
    // 0x80000410: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80000414: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80000418: addi        $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8000041C: addi        $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x80000420: bne         $t1, $zero, L_80000410
    if (ctx->r9 != 0) {
        // 0x80000424: nop
    
            goto L_80000410;
    }
    // 0x80000424: nop

    // 0x80000428: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x8000042C: addiu       $t2, $t2, -0x3C10
    ctx->r10 = ADD32(ctx->r10, -0X3C10);
    // 0x80000430: lui         $sp, 0x8017
    ctx->r29 = S32(0X8017 << 16);
    // 0x80000434: jr          $t2
    // 0x80000438: addiu       $sp, $sp, 0x3AB0
    ctx->r29 = ADD32(ctx->r29, 0X3AB0);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    return;
    // 0x80000438: addiu       $sp, $sp, 0x3AB0
    ctx->r29 = ADD32(ctx->r29, 0X3AB0);
    // 0x8000043C: nop

    // 0x80000440: nop

    // 0x80000444: nop

    // 0x80000448: nop

    // 0x8000044C: nop

;}
RECOMP_FUNC void func_80000450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000450: jr          $ra
    // 0x80000454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80000454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80000458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000045C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80000460: jal         0x800304B4
    // 0x80000464: nop

    func_800304B4(rdram, ctx);
        goto after_0;
    // 0x80000464: nop

    after_0:
    // 0x80000468: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000046C: lhu         $v0, -0x59EE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X59EE);
    // 0x80000470: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80000474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000478: jr          $ra
    // 0x8000047C: nop

    return;
    // 0x8000047C: nop

;}
RECOMP_FUNC void func_80000480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80000484: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000488: sh          $v0, -0x59EE($at)
    MEM_H(-0X59EE, ctx->r1) = ctx->r2;
    // 0x8000048C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80000490: sh          $v0, 0x13A($at)
    MEM_H(0X13A, ctx->r1) = ctx->r2;
    // 0x80000494: jr          $ra
    // 0x80000498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80000498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8000049C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000049C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800004A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800004A4: sh          $v0, -0x59EE($at)
    MEM_H(-0X59EE, ctx->r1) = ctx->r2;
    // 0x800004A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800004AC: sh          $v0, 0x13A($at)
    MEM_H(0X13A, ctx->r1) = ctx->r2;
    // 0x800004B0: jr          $ra
    // 0x800004B4: nop

    return;
    // 0x800004B4: nop

;}
RECOMP_FUNC void func_800004B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800004B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800004BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800004C0: jal         0x80000458
    // 0x800004C4: nop

    func_80000458(rdram, ctx);
        goto after_0;
    // 0x800004C4: nop

    after_0:
    // 0x800004C8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800004CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800004D0: jr          $ra
    // 0x800004D4: nop

    return;
    // 0x800004D4: nop

;}
RECOMP_FUNC void func_800004D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800004D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800004DC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800004E0: jal         0x80000458
    // 0x800004E4: nop

    func_80000458(rdram, ctx);
        goto after_0;
    // 0x800004E4: nop

    after_0:
    // 0x800004E8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800004EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800004F0: jr          $ra
    // 0x800004F4: nop

    return;
    // 0x800004F4: nop

    // 0x800004F8: nop

    // 0x800004FC: nop

;}
RECOMP_FUNC void func_80000500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000500: jr          $ra
    // 0x80000504: nop

    return;
    // 0x80000504: nop

;}
RECOMP_FUNC void func_80000508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000508: jr          $ra
    // 0x8000050C: nop

    return;
    // 0x8000050C: nop

;}
RECOMP_FUNC void func_80000510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000510: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80000514: lw          $a0, 0x31A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31A0);
    // 0x80000518: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8000051C: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80000510 falls into func_80000520
    func_80000520(rdram, ctx);
;}
RECOMP_FUNC void func_80000520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000520: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000524: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80000528: jal         0x80000540
    // 0x8000052C: nop

    func_80000540(rdram, ctx);
        goto after_0;
    // 0x8000052C: nop

    after_0:
    // 0x80000530: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80000534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000538: jr          $ra
    // 0x8000053C: nop

    return;
    // 0x8000053C: nop

;}
RECOMP_FUNC void func_80000540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000540: jr          $ra
    // 0x80000544: nop

    return;
    // 0x80000544: nop

;}
RECOMP_FUNC void func_80000548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000548: jr          $ra
    // 0x8000054C: nop

    return;
    // 0x8000054C: nop

;}
RECOMP_FUNC void func_80000550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000550: jr          $ra
    // 0x80000554: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x80000554: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x80000558: nop

    // 0x8000055C: nop

;}
RECOMP_FUNC void func_80000560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000560: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80000564: lhu         $v1, 0x4E54($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X4E54);
    // 0x80000568: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000056C: lhu         $v0, -0x2080($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2080);
    // FALLTHROUGH: func_80000560 falls into func_80000570
    func_80000570(rdram, ctx);
;}
RECOMP_FUNC void func_80000570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000578: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000057C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80000580: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000584: sh          $v0, -0x2080($at)
    MEM_H(-0X2080, ctx->r1) = ctx->r2;
    // 0x80000588: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000058C: blez        $v0, L_8000059C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80000590: nop
    
            goto L_8000059C;
    }
    // 0x80000590: nop

    // 0x80000594: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000598: sh          $zero, -0x2080($at)
    MEM_H(-0X2080, ctx->r1) = 0;
L_8000059C:
    // 0x8000059C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800005A0: addiu       $v1, $v1, 0x15A
    ctx->r3 = ADD32(ctx->r3, 0X15A);
    // 0x800005A4: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800005A8: beq         $v0, $zero, L_800005B4
    if (ctx->r2 == 0) {
        // 0x800005AC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800005B4;
    }
    // 0x800005AC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800005B0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_800005B4:
    // 0x800005B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800005B8: lhu         $v0, 0x1A4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1A4);
    // 0x800005BC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800005C0: lhu         $v1, 0x4E50($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X4E50);
    // 0x800005C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800005C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800005CC: sh          $v0, 0x1A4($at)
    MEM_H(0X1A4, ctx->r1) = ctx->r2;
    // 0x800005D0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800005D4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800005D8: slti        $v0, $v0, 0x3C
    ctx->r2 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x800005DC: bne         $v0, $zero, L_800006D8
    if (ctx->r2 != 0) {
        // 0x800005E0: nop
    
            goto L_800006D8;
    }
    // 0x800005E0: nop

    // 0x800005E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800005E8: lhu         $v0, 0x11E($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X11E);
    // 0x800005EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800005F0: sh          $zero, 0x1A4($at)
    MEM_H(0X1A4, ctx->r1) = 0;
    // 0x800005F4: bne         $v0, $zero, L_800006D8
    if (ctx->r2 != 0) {
        // 0x800005F8: addiu       $v0, $zero, 0x150
        ctx->r2 = ADD32(0, 0X150);
            goto L_800006D8;
    }
    // 0x800005F8: addiu       $v0, $zero, 0x150
    ctx->r2 = ADD32(0, 0X150);
    // 0x800005FC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80000600: lhu         $v1, 0x90($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X90);
    // 0x80000604: bne         $v1, $v0, L_800006D8
    if (ctx->r3 != ctx->r2) {
        // 0x80000608: nop
    
            goto L_800006D8;
    }
    // 0x80000608: nop

    // 0x8000060C: jal         0x8001F310
    // 0x80000610: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001F310(rdram, ctx);
        goto after_0;
    // 0x80000610: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80000614: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80000618: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000061C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80000620: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80000624: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80000628: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000062C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80000630: lhu         $v0, 0x3F94($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3F94);
    // 0x80000634: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80000638: addiu       $s0, $s0, 0x3F94
    ctx->r16 = ADD32(ctx->r16, 0X3F94);
    // 0x8000063C: beq         $v0, $zero, L_80000658
    if (ctx->r2 == 0) {
        // 0x80000640: nop
    
            goto L_80000658;
    }
    // 0x80000640: nop

    // 0x80000644: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80000648: lhu         $v0, -0x30FE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X30FE);
    // 0x8000064C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000650: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80000654: sh          $v0, -0x30FE($at)
    MEM_H(-0X30FE, ctx->r1) = ctx->r2;
L_80000658:
    // 0x80000658: jal         0x8001F310
    // 0x8000065C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8001F310(rdram, ctx);
        goto after_1;
    // 0x8000065C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80000660: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80000664: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80000668: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8000066C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80000670: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80000674: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x80000678: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8000067C: beq         $v0, $zero, L_80000698
    if (ctx->r2 == 0) {
        // 0x80000680: nop
    
            goto L_80000698;
    }
    // 0x80000680: nop

    // 0x80000684: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80000688: lhu         $v0, -0x740C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X740C);
    // 0x8000068C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000690: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000694: sh          $v0, -0x740C($at)
    MEM_H(-0X740C, ctx->r1) = ctx->r2;
L_80000698:
    // 0x80000698: jal         0x8001F310
    // 0x8000069C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001F310(rdram, ctx);
        goto after_2;
    // 0x8000069C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x800006A0: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800006A4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800006A8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800006AC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800006B0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800006B4: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x800006B8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800006BC: beq         $v0, $zero, L_800006D8
    if (ctx->r2 == 0) {
        // 0x800006C0: nop
    
            goto L_800006D8;
    }
    // 0x800006C0: nop

    // 0x800006C4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800006C8: lhu         $v0, 0x3EFC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3EFC);
    // 0x800006CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800006D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800006D4: sh          $v0, 0x3EFC($at)
    MEM_H(0X3EFC, ctx->r1) = ctx->r2;
L_800006D8:
    // 0x800006D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800006DC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800006E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800006E4: jr          $ra
    // 0x800006E8: nop

    return;
    // 0x800006E8: nop

;}
RECOMP_FUNC void func_800006EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800006EC: jr          $ra
    // 0x800006F0: nop

    return;
    // 0x800006F0: nop

;}
RECOMP_FUNC void func_800006F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    static int diag_count = 0;
    diag_count++;
    int do_diag = (diag_count <= 5);
    // 0x800006F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800006F8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    if (do_diag) { fprintf(stderr, "[R2-F6F4] call #%d: calling func_800241B8\n", diag_count); fflush(stderr); }
    // 0x800006FC: jal         0x800241B8
    // 0x80000700: nop

    func_800241B8(rdram, ctx);
        goto after_0;
    // 0x80000700: nop

    after_0:
    // 0x80000704: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80000708: lhu         $v0, 0x1A2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1A2);
    if (do_diag) { fprintf(stderr, "[R2-F6F4] 0x801201A2=0x%04X\n", (unsigned)(ctx->r2 & 0xFFFF)); fflush(stderr); }
    // 0x8000070C: bne         $v0, $zero, L_80000724
    if (ctx->r2 != 0) {
        // 0x80000710: nop

            goto L_80000724;
    }
    // 0x80000710: nop

    if (do_diag) { fprintf(stderr, "[R2-F6F4] calling func_80000560\n"); fflush(stderr); }
    // 0x80000714: jal         0x80000560
    // 0x80000718: nop

    func_80000560(rdram, ctx);
        goto after_1;
    // 0x80000718: nop

    after_1:
    if (do_diag) { fprintf(stderr, "[R2-F6F4] func_80000560 done, calling func_80016528\n"); fflush(stderr); }
    // 0x8000071C: jal         0x80016528
    // 0x80000720: nop

    func_80016528(rdram, ctx);
        goto after_2;
    // 0x80000720: nop

    after_2:
    if (do_diag) { fprintf(stderr, "[R2-F6F4] func_80016528 done\n"); fflush(stderr); }
L_80000724:
    // 0x80000724: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80000728: lhu         $v0, 0x4E50($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E50);
    // 0x8000072C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80000730: sh          $zero, 0x4E50($at)
    MEM_H(0X4E50, ctx->r1) = 0;
    // 0x80000734: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80000738: sh          $v0, 0x4E54($at)
    MEM_H(0X4E54, ctx->r1) = ctx->r2;
    // 0x8000073C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80000740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000744: jr          $ra
    // 0x80000748: nop

    return;
    // 0x80000748: nop

;}
RECOMP_FUNC void func_8000074C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000074C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80000750: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80000754: sh          $v0, 0x4E54($at)
    MEM_H(0X4E54, ctx->r1) = ctx->r2;
    // 0x80000758: jr          $ra
    // 0x8000075C: nop

    return;
    // 0x8000075C: nop

;}
RECOMP_FUNC void func_80000760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000764: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80000768: jal         0x80000E14
    // 0x8000076C: nop

    func_80000E14(rdram, ctx);
        goto after_0;
    // 0x8000076C: nop

    after_0:
    // 0x80000770: jal         0x80000788
    // 0x80000774: nop

    func_80000788(rdram, ctx);
        goto after_1;
    // 0x80000774: nop

    after_1:
    // 0x80000778: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000077C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000780: jr          $ra
    // 0x80000784: nop

    return;
    // 0x80000784: nop

;}
RECOMP_FUNC void func_80000788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000078C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80000790: jal         0x80000D18
    // 0x80000794: nop

    func_80000D18(rdram, ctx);
        goto after_0;
    // 0x80000794: nop

    after_0:
    // 0x80000798: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000079C: lw          $v0, -0x68B4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68B4);
    // 0x800007A0: jalr        $v0
    // 0x800007A4: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800007A4: nop

    after_1:
    // 0x800007A8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800007AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800007B0: jr          $ra
    // 0x800007B4: nop

    return;
    // 0x800007B4: nop

;}
RECOMP_FUNC void func_800007B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800007B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800007BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800007C0: jal         0x80000DCC
    // 0x800007C4: nop

    func_80000DCC(rdram, ctx);
        goto after_0;
    // 0x800007C4: nop

    after_0:
    // 0x800007C8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800007CC: lw          $v0, -0x68B4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68B4);
    // 0x800007D0: jalr        $v0
    // 0x800007D4: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800007D4: nop

    after_1:
    // 0x800007D8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800007DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800007E0: jr          $ra
    // 0x800007E4: nop

    return;
    // 0x800007E4: nop

;}
RECOMP_FUNC void func_800007E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800007E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800007EC: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x800007F0: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800007F4: ori         $v1, $zero, 0x8002
    ctx->r3 = 0 | 0X8002;
    // 0x800007F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800007FC: sw          $v0, -0x6894($at)
    MEM_W(-0X6894, ctx->r1) = ctx->r2;
    // 0x80000800: ori         $v0, $zero, 0x8101
    ctx->r2 = 0 | 0X8101;
    // 0x80000804: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80000808: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8000080C: sh          $v1, -0x6898($at)
    MEM_H(-0X6898, ctx->r1) = ctx->r3;
    // 0x80000810: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000814: sh          $v0, -0x6890($at)
    MEM_H(-0X6890, ctx->r1) = ctx->r2;
    // 0x80000818: jal         0x800008BC
    // 0x8000081C: nop

    func_800008BC(rdram, ctx);
        goto after_0;
    // 0x8000081C: nop

    after_0:
    // 0x80000820: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80000824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000828: jr          $ra
    // 0x8000082C: nop

    return;
    // 0x8000082C: nop

;}
RECOMP_FUNC void func_80000830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000834: ori         $v0, $zero, 0x8002
    ctx->r2 = 0 | 0X8002;
    // 0x80000838: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8000083C: sh          $v0, -0x6898($at)
    MEM_H(-0X6898, ctx->r1) = ctx->r2;
    // 0x80000840: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80000844: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000848: sw          $v0, -0x6894($at)
    MEM_W(-0X6894, ctx->r1) = ctx->r2;
    // 0x8000084C: ori         $v0, $zero, 0x8101
    ctx->r2 = 0 | 0X8101;
    // 0x80000850: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80000854: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000858: sh          $v0, -0x6890($at)
    MEM_H(-0X6890, ctx->r1) = ctx->r2;
    // 0x8000085C: jal         0x800008BC
    // 0x80000860: nop

    func_800008BC(rdram, ctx);
        goto after_0;
    // 0x80000860: nop

    after_0:
    // 0x80000864: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80000868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000086C: jr          $ra
    // 0x80000870: nop

    return;
    // 0x80000870: nop

;}
RECOMP_FUNC void func_80000874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000878: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8000087C: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x80000880: ori         $v1, $zero, 0x8002
    ctx->r3 = 0 | 0X8002;
    // 0x80000884: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000888: sw          $v0, -0x6894($at)
    MEM_W(-0X6894, ctx->r1) = ctx->r2;
    // 0x8000088C: ori         $v0, $zero, 0x8101
    ctx->r2 = 0 | 0X8101;
    // 0x80000890: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80000894: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000898: sh          $v1, -0x6898($at)
    MEM_H(-0X6898, ctx->r1) = ctx->r3;
    // 0x8000089C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800008A0: sh          $v0, -0x6890($at)
    MEM_H(-0X6890, ctx->r1) = ctx->r2;
    // 0x800008A4: jal         0x800008BC
    // 0x800008A8: nop

    func_800008BC(rdram, ctx);
        goto after_0;
    // 0x800008A8: nop

    after_0:
    // 0x800008AC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800008B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800008B4: jr          $ra
    // 0x800008B8: nop

    return;
    // 0x800008B8: nop

;}
RECOMP_FUNC void func_800008BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800008BC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800008C0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800008C4: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800008C8: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800008CC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800008D0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800008D4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800008D8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800008DC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800008E0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800008E4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800008E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800008EC: sw          $zero, -0x1CEC($at)
    MEM_W(-0X1CEC, ctx->r1) = 0;
    // 0x800008F0: jal         0x80000E84
    // 0x800008F4: nop

    func_80000E84(rdram, ctx);
        goto after_0;
    // 0x800008F4: nop

    after_0:
    // 0x800008F8: jal         0x80000F5C
    // 0x800008FC: nop

    func_80000F5C(rdram, ctx);
        goto after_1;
    // 0x800008FC: nop

    after_1:
    // 0x80000900: jal         0x80000F64
    // 0x80000904: nop

    func_80000F64(rdram, ctx);
        goto after_2;
    // 0x80000904: nop

    after_2:
    // 0x80000908: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8000090C: addiu       $s1, $s1, -0x68A8
    ctx->r17 = ADD32(ctx->r17, -0X68A8);
    // 0x80000910: lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X0);
    // 0x80000914: beq         $v0, $zero, L_80000928
    if (ctx->r2 == 0) {
        // 0x80000918: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80000928;
    }
    // 0x80000918: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000091C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000920: sh          $v1, -0x6888($at)
    MEM_H(-0X6888, ctx->r1) = ctx->r3;
    // 0x80000924: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_80000928:
    // 0x80000928: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000092C: lw          $v0, -0x68AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68AC);
    // 0x80000930: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000934: sw          $v0, -0x6884($at)
    MEM_W(-0X6884, ctx->r1) = ctx->r2;
    // 0x80000938: jal         0x80000EDC
    // 0x8000093C: nop

    func_80000EDC(rdram, ctx);
        goto after_3;
    // 0x8000093C: nop

    after_3:
    // 0x80000940: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80000944: lw          $v0, -0x689C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X689C);
    // 0x80000948: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8000094C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000950: sb          $v0, -0x687E($at)
    MEM_B(-0X687E, ctx->r1) = ctx->r2;
    // 0x80000954: beq         $v0, $zero, L_80000C88
    if (ctx->r2 == 0) {
        // 0x80000958: addiu       $s0, $s1, 0xC
        ctx->r16 = ADD32(ctx->r17, 0XC);
            goto L_80000C88;
    }
    // 0x80000958: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x8000095C: addiu       $s2, $s1, 0x28
    ctx->r18 = ADD32(ctx->r17, 0X28);
    // 0x80000960: addiu       $s4, $s1, -0x4
    ctx->r20 = ADD32(ctx->r17, -0X4);
L_80000964:
    // 0x80000964: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80000968: lbu         $a0, 0x1E($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1E);
    // 0x8000096C: sh          $zero, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = 0;
    // 0x80000970: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000974: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80000978: sltiu       $v0, $a0, 0x21
    ctx->r2 = ctx->r4 < 0X21 ? 1 : 0;
    // 0x8000097C: bne         $v0, $zero, L_80000C00
    if (ctx->r2 != 0) {
        // 0x80000980: sltiu       $v0, $a0, 0x20
        ctx->r2 = ctx->r4 < 0X20 ? 1 : 0;
            goto L_80000C00;
    }
    // 0x80000980: sltiu       $v0, $a0, 0x20
    ctx->r2 = ctx->r4 < 0X20 ? 1 : 0;
    // 0x80000984: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80000988: lw          $v1, -0x68A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X68A4);
    // 0x8000098C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80000990: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x80000994: lw          $s6, -0x1C($s0)
    ctx->r22 = MEM_W(ctx->r16, -0X1C);
    // 0x80000998: lw          $s7, 0x18($s0)
    ctx->r23 = MEM_W(ctx->r16, 0X18);
    // 0x8000099C: lw          $fp, -0x14($s0)
    ctx->r30 = MEM_W(ctx->r16, -0X14);
    // 0x800009A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800009A4: lw          $s1, -0x84($v0)
    ctx->r17 = MEM_W(ctx->r2, -0X84);
    // 0x800009A8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800009AC: lw          $s5, -0xC($s0)
    ctx->r21 = MEM_W(ctx->r16, -0XC);
    // 0x800009B0: jal         0x8005F360
    // 0x800009B4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005F360(rdram, ctx);
        goto after_4;
    // 0x800009B4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // 0x800009B8: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
    // 0x800009BC: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800009C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800009C4: lhu         $a1, 0x4($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X4);
    // 0x800009C8: addiu       $a2, $s0, 0x14
    ctx->r6 = ADD32(ctx->r16, 0X14);
    // 0x800009CC: jal         0x80024900
    // 0x800009D0: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_80024900(rdram, ctx);
        goto after_5;
    // 0x800009D0: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x800009D4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800009D8: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x800009DC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800009E0: beq         $v0, $zero, L_80000BF0
    if (ctx->r2 == 0) {
        // 0x800009E4: nop
    
            goto L_80000BF0;
    }
    // 0x800009E4: nop

    // 0x800009E8: jal         0x80024430
    // 0x800009EC: nop

    func_80024430(rdram, ctx);
        goto after_6;
    // 0x800009EC: nop

    after_6:
    // 0x800009F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800009F4: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x800009F8: beq         $v0, $zero, L_80000B5C
    if (ctx->r2 == 0) {
        // 0x800009FC: nop
    
            goto L_80000B5C;
    }
    // 0x800009FC: nop

    // 0x80000A00: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80000A04: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80000A08: sw          $s1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r17;
    // 0x80000A0C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80000A10: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80000A14: sw          $s3, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r19;
    // 0x80000A18: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80000A1C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80000A20: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80000A24: sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    // 0x80000A28: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80000A2C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80000A30: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80000A34: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
    // 0x80000A38: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80000A3C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80000A40: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80000A44: lhu         $v0, -0x1D0A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X1D0A);
    // 0x80000A48: sh          $v0, 0x74($v1)
    MEM_H(0X74, ctx->r3) = ctx->r2;
    // 0x80000A4C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80000A50: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80000A54: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80000A58: sw          $v0, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->r2;
    // 0x80000A5C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80000A60: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80000A64: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80000A68: sh          $v0, 0x72($v1)
    MEM_H(0X72, ctx->r3) = ctx->r2;
    // 0x80000A6C: lhu         $v0, -0xE($s0)
    ctx->r2 = MEM_HU(ctx->r16, -0XE);
    // 0x80000A70: lhu         $v1, 0x14($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X14);
    // 0x80000A74: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80000A78: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80000A7C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80000A80: sh          $v0, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r2;
    // 0x80000A84: sh          $v0, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r2;
    // 0x80000A88: lhu         $v0, -0x10($s0)
    ctx->r2 = MEM_HU(ctx->r16, -0X10);
    // 0x80000A8C: lhu         $v1, 0x10($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X10);
    // 0x80000A90: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80000A94: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80000A98: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80000A9C: sh          $v0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r2;
    // 0x80000AA0: sh          $v0, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r2;
    // 0x80000AA4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80000AA8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80000AAC: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x80000AB0: sh          $v0, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r2;
    // 0x80000AB4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80000AB8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80000ABC: sh          $zero, 0x20($v0)
    MEM_H(0X20, ctx->r2) = 0;
    // 0x80000AC0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80000AC4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80000AC8: lw          $v0, -0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X4);
    // 0x80000ACC: sh          $v0, 0x70($v1)
    MEM_H(0X70, ctx->r3) = ctx->r2;
    // 0x80000AD0: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80000AD4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80000AD8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80000ADC: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x80000AE0: sh          $v0, 0x6C($v1)
    MEM_H(0X6C, ctx->r3) = ctx->r2;
    // 0x80000AE4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80000AE8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80000AEC: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x80000AF0: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
    // 0x80000AF4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80000AF8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80000AFC: addiu       $v0, $zero, 0x7000
    ctx->r2 = ADD32(0, 0X7000);
    // 0x80000B00: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
    // 0x80000B04: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80000B08: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80000B0C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80000B10: lw          $v1, -0x1CEC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1CEC);
    // 0x80000B14: bne         $v1, $zero, L_80000B2C
    if (ctx->r3 != 0) {
        // 0x80000B18: sh          $zero, 0x82($v0)
        MEM_H(0X82, ctx->r2) = 0;
            goto L_80000B2C;
    }
    // 0x80000B18: sh          $zero, 0x82($v0)
    MEM_H(0X82, ctx->r2) = 0;
    // 0x80000B1C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80000B20: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80000B24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000B28: sw          $v0, -0x1CEC($at)
    MEM_W(-0X1CEC, ctx->r1) = ctx->r2;
L_80000B2C:
    // 0x80000B2C: lh          $v0, 0x1C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1C);
    // 0x80000B30: bnel        $v0, $zero, L_80000B6C
    if (ctx->r2 != 0) {
        // 0x80000B34: sw          $s6, -0xC($s4)
        MEM_W(-0XC, ctx->r20) = ctx->r22;
            goto L_80000B6C;
    }
    goto skip_0;
    // 0x80000B34: sw          $s6, -0xC($s4)
    MEM_W(-0XC, ctx->r20) = ctx->r22;
    skip_0:
    // 0x80000B38: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80000B3C: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x80000B40: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80000B44: bne         $v0, $zero, L_80000B5C
    if (ctx->r2 != 0) {
        // 0x80000B48: nop
    
            goto L_80000B5C;
    }
    // 0x80000B48: nop

    // 0x80000B4C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80000B50: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80000B54: jal         0x80024564
    // 0x80000B58: nop

    func_80024564(rdram, ctx);
        goto after_7;
    // 0x80000B58: nop

    after_7:
L_80000B5C:
    // 0x80000B5C: lh          $v0, 0x0($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X0);
    // 0x80000B60: beq         $v0, $zero, L_80000B8C
    if (ctx->r2 == 0) {
        // 0x80000B64: nop
    
            goto L_80000B8C;
    }
    // 0x80000B64: nop

    // 0x80000B68: sw          $s6, -0xC($s4)
    MEM_W(-0XC, ctx->r20) = ctx->r22;
L_80000B6C:
    // 0x80000B6C: sw          $s7, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->r23;
    // 0x80000B70: sw          $fp, -0x4($s4)
    MEM_W(-0X4, ctx->r20) = ctx->r30;
    // 0x80000B74: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80000B78: lw          $v0, 0x30($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X30);
    // 0x80000B7C: sw          $t0, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->r8;
    // 0x80000B80: sw          $s5, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r21;
    // 0x80000B84: j           L_80000C6C
    // 0x80000B88: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
        goto L_80000C6C;
    // 0x80000B88: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
L_80000B8C:
    // 0x80000B8C: lw          $v0, -0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, -0X14);
    // 0x80000B90: lhu         $a0, 0x6($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X6);
    // 0x80000B94: andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // 0x80000B98: bne         $v0, $zero, L_80000BB4
    if (ctx->r2 != 0) {
        // 0x80000B9C: nop
    
            goto L_80000BB4;
    }
    // 0x80000B9C: nop

    // 0x80000BA0: lhu         $v0, -0x2A($s2)
    ctx->r2 = MEM_HU(ctx->r18, -0X2A);
    // 0x80000BA4: lhu         $v1, -0x2C($s2)
    ctx->r3 = MEM_HU(ctx->r18, -0X2C);
    // 0x80000BA8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80000BAC: sh          $v0, -0x2A($s2)
    MEM_H(-0X2A, ctx->r18) = ctx->r2;
    // 0x80000BB0: sh          $v1, -0x2C($s2)
    MEM_H(-0X2C, ctx->r18) = ctx->r3;
L_80000BB4:
    // 0x80000BB4: lhu         $v0, -0x2A($s2)
    ctx->r2 = MEM_HU(ctx->r18, -0X2A);
    // 0x80000BB8: sw          $s5, -0x28($s2)
    MEM_W(-0X28, ctx->r18) = ctx->r21;
    // 0x80000BBC: lhu         $a0, -0x26($s2)
    ctx->r4 = MEM_HU(ctx->r18, -0X26);
    // 0x80000BC0: lhu         $v1, -0x2C($s2)
    ctx->r3 = MEM_HU(ctx->r18, -0X2C);
    // 0x80000BC4: lhu         $a1, -0x28($s2)
    ctx->r5 = MEM_HU(ctx->r18, -0X28);
    // 0x80000BC8: sw          $s6, -0x38($s2)
    MEM_W(-0X38, ctx->r18) = ctx->r22;
    // 0x80000BCC: sw          $s7, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->r23;
    // 0x80000BD0: sw          $fp, -0x30($s2)
    MEM_W(-0X30, ctx->r18) = ctx->r30;
    // 0x80000BD4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80000BD8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80000BDC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80000BE0: sw          $t0, -0x8($s2)
    MEM_W(-0X8, ctx->r18) = ctx->r8;
    // 0x80000BE4: sh          $v0, -0x2A($s2)
    MEM_H(-0X2A, ctx->r18) = ctx->r2;
    // 0x80000BE8: j           L_80000C6C
    // 0x80000BEC: sh          $v1, -0x2C($s2)
    MEM_H(-0X2C, ctx->r18) = ctx->r3;
        goto L_80000C6C;
    // 0x80000BEC: sh          $v1, -0x2C($s2)
    MEM_H(-0X2C, ctx->r18) = ctx->r3;
L_80000BF0:
    // 0x80000BF0: jal         0x8005E178
    // 0x80000BF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8005E178(rdram, ctx);
        goto after_8;
    // 0x80000BF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x80000BF8: j           L_80000C6C
    // 0x80000BFC: nop

        goto L_80000C6C;
    // 0x80000BFC: nop

L_80000C00:
    // 0x80000C00: beq         $v0, $zero, L_80000C24
    if (ctx->r2 == 0) {
        // 0x80000C04: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_80000C24;
    }
    // 0x80000C04: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80000C08: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000C0C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80000C10: lw          $v0, 0x139C($at)
    ctx->r2 = MEM_W(ctx->r1, 0X139C);
    // 0x80000C14: jalr        $v0
    // 0x80000C18: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_9;
    // 0x80000C18: nop

    after_9:
    // 0x80000C1C: j           L_80000C6C
    // 0x80000C20: nop

        goto L_80000C6C;
    // 0x80000C20: nop

L_80000C24:
    // 0x80000C24: lw          $v1, -0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X10);
    // 0x80000C28: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80000C2C: sb          $zero, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = 0;
    // 0x80000C30: andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // 0x80000C34: bne         $v0, $zero, L_80000C4C
    if (ctx->r2 != 0) {
        // 0x80000C38: sw          $v1, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->r3;
            goto L_80000C4C;
    }
    // 0x80000C38: sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
    // 0x80000C3C: lhu         $v0, -0xE($s0)
    ctx->r2 = MEM_HU(ctx->r16, -0XE);
    // 0x80000C40: lhu         $v1, 0x16($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X16);
    // 0x80000C44: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80000C48: sh          $v0, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r2;
L_80000C4C:
    // 0x80000C4C: lhu         $v0, -0xE($s0)
    ctx->r2 = MEM_HU(ctx->r16, -0XE);
    // 0x80000C50: lhu         $a0, -0xA($s0)
    ctx->r4 = MEM_HU(ctx->r16, -0XA);
    // 0x80000C54: lhu         $v1, -0x10($s0)
    ctx->r3 = MEM_HU(ctx->r16, -0X10);
    // 0x80000C58: lhu         $a1, -0xC($s0)
    ctx->r5 = MEM_HU(ctx->r16, -0XC);
    // 0x80000C5C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80000C60: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80000C64: sh          $v0, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r2;
    // 0x80000C68: sh          $v1, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r3;
L_80000C6C:
    // 0x80000C6C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80000C70: lw          $v0, -0x689C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X689C);
    // 0x80000C74: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80000C78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000C7C: sb          $v0, -0x687E($at)
    MEM_B(-0X687E, ctx->r1) = ctx->r2;
    // 0x80000C80: bne         $v0, $zero, L_80000964
    if (ctx->r2 != 0) {
        // 0x80000C84: nop
    
            goto L_80000964;
    }
    // 0x80000C84: nop

L_80000C88:
    // 0x80000C88: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80000C8C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80000C90: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80000C94: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80000C98: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80000C9C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80000CA0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80000CA4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80000CA8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80000CAC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80000CB0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80000CB4: jr          $ra
    // 0x80000CB8: nop

    return;
    // 0x80000CB8: nop

;}
RECOMP_FUNC void func_80000CBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000CBC: jr          $ra
    // 0x80000CC0: nop

    return;
    // 0x80000CC0: nop

;}
RECOMP_FUNC void func_80000CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000CC4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80000CC8: lhu         $v0, -0x6882($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6882);
    // 0x80000CCC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80000CD0: lhu         $v1, -0x6884($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6884);
    // 0x80000CD4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80000CD8: lhu         $a0, -0x6888($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X6888);

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_80000CDC
    func_80000CDC(rdram, ctx);
}
RECOMP_FUNC void func_80000CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000CE0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80000CE4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80000CE8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000CEC: sh          $v0, -0x68AA($at)
    MEM_H(-0X68AA, ctx->r1) = ctx->r2;
    // 0x80000CF0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000CF4: sh          $v1, -0x68AC($at)
    MEM_H(-0X68AC, ctx->r1) = ctx->r3;
    // 0x80000CF8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000CFC: sh          $v1, -0x6884($at)
    MEM_H(-0X6884, ctx->r1) = ctx->r3;
    // 0x80000D00: jal         0x80000EDC
    // 0x80000D04: nop

    func_80000EDC(rdram, ctx);
        goto after_0;
    // 0x80000D04: nop

    after_0:
    // 0x80000D08: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80000D0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000D10: jr          $ra
    // 0x80000D14: nop

    return;
    // 0x80000D14: nop

;}
RECOMP_FUNC void func_80000D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000D1C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80000D20: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80000D24: addiu       $s0, $s0, -0x689C
    ctx->r16 = ADD32(ctx->r16, -0X689C);
    // 0x80000D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000D2C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80000D30: jal         0x800731C8
    // 0x80000D34: nop

    func_800731C8(rdram, ctx);
        goto after_0;
    // 0x80000D34: nop

    after_0:
    // 0x80000D38: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80000D3C: lui         $a0, 0x1F
    ctx->r4 = S32(0X1F << 16);
    // 0x80000D40: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
    // 0x80000D44: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80000D48: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80000D4C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80000D50: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80000D54: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x80000D58: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80000D5C: subu        $v0, $a2, $v0
    ctx->r2 = SUB32(ctx->r6, ctx->r2);
    // 0x80000D60: sltu        $a0, $a0, $v0
    ctx->r4 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80000D64: bne         $a0, $zero, L_80000D90
    if (ctx->r4 != 0) {
        // 0x80000D68: andi        $v0, $a2, 0x3
        ctx->r2 = ctx->r6 & 0X3;
            goto L_80000D90;
    }
    // 0x80000D68: andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // 0x80000D6C: bne         $v0, $zero, L_80000D90
    if (ctx->r2 != 0) {
        // 0x80000D70: nop
    
            goto L_80000D90;
    }
    // 0x80000D70: nop

    // 0x80000D74: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    // 0x80000D78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80000D7C: addiu       $a0, $a0, 0x1A8
    ctx->r4 = ADD32(ctx->r4, 0X1A8);
    // 0x80000D80: jal         0x80073220
    // 0x80000D84: nop

    osAiSetFrequency_recomp(rdram, ctx);
        goto after_1;
    // 0x80000D84: nop

    after_1:
    // 0x80000D88: j           L_80000DA8
    // 0x80000D8C: nop

        goto L_80000DA8;
    // 0x80000D8C: nop

L_80000D90:
    // 0x80000D90: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80000D94: lw          $a1, -0x689C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X689C);
    // 0x80000D98: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80000D9C: addiu       $a0, $a0, 0x1A8
    ctx->r4 = ADD32(ctx->r4, 0X1A8);
    // 0x80000DA0: jal         0x80073220
    // 0x80000DA4: nop

    osAiSetFrequency_recomp(rdram, ctx);
        goto after_2;
    // 0x80000DA4: nop

    after_2:
L_80000DA8:
    // 0x80000DA8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80000DAC: addiu       $v0, $v0, 0x1A8
    ctx->r2 = ADD32(ctx->r2, 0X1A8);
    // 0x80000DB0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000DB4: sw          $v0, -0x689C($at)
    MEM_W(-0X689C, ctx->r1) = ctx->r2;
    // 0x80000DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000DBC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80000DC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000DC4: jr          $ra
    // 0x80000DC8: nop

    return;
    // 0x80000DC8: nop

;}
RECOMP_FUNC void func_80000DCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000DCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80000DD0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80000DD4: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80000DD8: addiu       $s1, $s1, -0x689C
    ctx->r17 = ADD32(ctx->r17, -0X689C);
    // 0x80000DDC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80000DE0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80000DE4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80000DE8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80000DEC: addiu       $s0, $s0, 0x1A8
    ctx->r16 = ADD32(ctx->r16, 0X1A8);
    // 0x80000DF0: jal         0x80073220
    // 0x80000DF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_0;
    // 0x80000DF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80000DF8: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x80000DFC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80000E00: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80000E04: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80000E08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80000E0C: jr          $ra
    // 0x80000E10: nop

    return;
    // 0x80000E10: nop

;}
RECOMP_FUNC void func_80000E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000E14: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000E18: sw          $zero, -0x68B8($at)
    MEM_W(-0X68B8, ctx->r1) = 0;
    // 0x80000E1C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80000E20: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000E24: sw          $v0, -0x68B4($at)
    MEM_W(-0X68B4, ctx->r1) = ctx->r2;
    // 0x80000E28: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80000E2C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000E30: sw          $v0, -0x68B0($at)
    MEM_W(-0X68B0, ctx->r1) = ctx->r2;
    // 0x80000E34: lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X8);
    // 0x80000E38: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000E3C: sh          $v0, -0x68AA($at)
    MEM_H(-0X68AA, ctx->r1) = ctx->r2;
    // 0x80000E40: lhu         $v0, 0xA($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XA);
    // 0x80000E44: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000E48: sh          $v0, -0x68AC($at)
    MEM_H(-0X68AC, ctx->r1) = ctx->r2;
    // 0x80000E4C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80000E50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000E54: sw          $v0, -0x68A8($at)
    MEM_W(-0X68A8, ctx->r1) = ctx->r2;
    // 0x80000E58: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80000E5C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000E60: sw          $v0, -0x68A4($at)
    MEM_W(-0X68A4, ctx->r1) = ctx->r2;
    // 0x80000E64: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80000E68: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x80000E6C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000E70: sw          $a0, -0x689C($at)
    MEM_W(-0X689C, ctx->r1) = ctx->r4;
    // 0x80000E74: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000E78: sw          $v0, -0x68A0($at)
    MEM_W(-0X68A0, ctx->r1) = ctx->r2;
    // 0x80000E7C: jr          $ra
    // 0x80000E80: nop

    return;
    // 0x80000E80: nop

;}
RECOMP_FUNC void func_80000E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000E84: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80000E88: lw          $v0, -0x68A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68A4);
    // FALLTHROUGH: func_80000E84 falls into func_80000E8C
    func_80000E8C(rdram, ctx);
;}
RECOMP_FUNC void func_80000E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000E8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000E90: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80000E94: lw          $a0, 0x9C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X9C);
    // 0x80000E98: jal         0x8005F360
    // 0x80000E9C: nop

    func_8005F360(rdram, ctx);
        goto after_0;
    // 0x80000E9C: nop

    after_0:
    // 0x80000EA0: lhu         $v1, 0x6($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6);
    // 0x80000EA4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80000EA8: sra         $v1, $v1, 17
    ctx->r3 = S32(SIGNED(ctx->r3) >> 17);
    // 0x80000EAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000EB0: sh          $v1, -0x6886($at)
    MEM_H(-0X6886, ctx->r1) = ctx->r3;
    // 0x80000EB4: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x80000EB8: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80000EBC: sra         $v0, $v0, 17
    ctx->r2 = S32(SIGNED(ctx->r2) >> 17);
    // 0x80000EC0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80000EC4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000EC8: sh          $v1, -0x6888($at)
    MEM_H(-0X6888, ctx->r1) = ctx->r3;
    // 0x80000ECC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80000ED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000ED4: jr          $ra
    // 0x80000ED8: nop

    return;
    // 0x80000ED8: nop

;}
RECOMP_FUNC void func_80000EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000EDC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80000EE0: lw          $v0, -0x6894($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6894);
    // FALLTHROUGH: func_80000EDC falls into func_80000EE4
    func_80000EE4(rdram, ctx);
;}
RECOMP_FUNC void func_80000EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000EE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000EE8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80000EEC: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x80000EF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80000EF4: beq         $v1, $v0, L_80000F24
    if (ctx->r3 == ctx->r2) {
        // 0x80000EF8: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80000F24;
    }
    // 0x80000EF8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80000EFC: beq         $v1, $zero, L_80000F3C
    if (ctx->r3 == 0) {
        // 0x80000F00: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80000F3C;
    }
    // 0x80000F00: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80000F04: bne         $v1, $v0, L_80000F3C
    if (ctx->r3 != ctx->r2) {
        // 0x80000F08: nop
    
            goto L_80000F3C;
    }
    // 0x80000F08: nop

    // 0x80000F0C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80000F10: lw          $a0, -0x689C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X689C);
    // 0x80000F14: jal         0x80000F80
    // 0x80000F18: nop

    func_80000F80(rdram, ctx);
        goto after_0;
    // 0x80000F18: nop

    after_0:
    // 0x80000F1C: j           L_80000F3C
    // 0x80000F20: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_80000F3C;
    // 0x80000F20: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80000F24:
    // 0x80000F24: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80000F28: lw          $a0, -0x689C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X689C);
    // 0x80000F2C: jal         0x80000F80
    // 0x80000F30: nop

    func_80000F80(rdram, ctx);
        goto after_1;
    // 0x80000F30: nop

    after_1:
    // 0x80000F34: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80000F38: sra         $a0, $v0, 17
    ctx->r4 = S32(SIGNED(ctx->r2) >> 17);
L_80000F3C:
    // 0x80000F3C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80000F40: addiu       $v1, $v1, -0x68AA
    ctx->r3 = ADD32(ctx->r3, -0X68AA);
    // 0x80000F44: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80000F48: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80000F4C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80000F50: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80000F54: jr          $ra
    // 0x80000F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80000F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80000F5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000F5C: jr          $ra
    // 0x80000F60: nop

    return;
    // 0x80000F60: nop

;}
RECOMP_FUNC void func_80000F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000F64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80000F68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000F6C: sh          $v0, -0x688C($at)
    MEM_H(-0X688C, ctx->r1) = ctx->r2;
    // 0x80000F70: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80000F74: sh          $v0, -0x688A($at)
    MEM_H(-0X688A, ctx->r1) = ctx->r2;
    // 0x80000F78: jr          $ra
    // 0x80000F7C: nop

    return;
    // 0x80000F7C: nop

;}
RECOMP_FUNC void func_80000F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000F80: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80000F84: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80000F88: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80000F8C: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x80000F90: addiu       $s2, $s2, -0x68B8
    ctx->r18 = ADD32(ctx->r18, -0X68B8);
    // 0x80000F94: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80000F98: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80000F9C: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80000FA0: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80000FA4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80000FA8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80000FAC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80000FB0: lw          $s5, 0x0($s2)
    ctx->r21 = MEM_W(ctx->r18, 0X0);
    // 0x80000FB4: lui         $s6, 0x8017
    ctx->r22 = S32(0X8017 << 16);
    // 0x80000FB8: lw          $s6, -0x6888($s6)
    ctx->r22 = MEM_W(ctx->r22, -0X6888);
    // 0x80000FBC: lui         $s7, 0x8017
    ctx->r23 = S32(0X8017 << 16);
    // 0x80000FC0: lw          $s7, -0x68A8($s7)
    ctx->r23 = MEM_W(ctx->r23, -0X68A8);
    // 0x80000FC4: jal         0x80000E84
    // 0x80000FC8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    func_80000E84(rdram, ctx);
        goto after_0;
    // 0x80000FC8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80000FCC: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x80000FD0: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80000FD4: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80000FD8: xori        $v0, $v0, 0xD
    ctx->r2 = ctx->r2 ^ 0XD;
    // 0x80000FDC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80000FE0: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80000FE4: beq         $v1, $zero, L_80001080
    if (ctx->r3 == 0) {
        // 0x80000FE8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80001080;
    }
    // 0x80000FE8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80000FEC: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x80000FF0: addiu       $s2, $s2, 0x24
    ctx->r18 = ADD32(ctx->r18, 0X24);
    // 0x80000FF4: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
    // 0x80000FF8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
L_80000FFC:
    // 0x80000FFC: beq         $a0, $s4, L_80001084
    if (ctx->r4 == ctx->r20) {
        // 0x80001000: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_80001084;
    }
    // 0x80001000: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80001004: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80001008: andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // 0x8000100C: beq         $v0, $zero, L_80001020
    if (ctx->r2 == 0) {
        // 0x80001010: nop
    
            goto L_80001020;
    }
    // 0x80001010: nop

    // 0x80001014: lh          $v0, -0x12($s2)
    ctx->r2 = MEM_H(ctx->r18, -0X12);
    // 0x80001018: j           L_8000105C
    // 0x8000101C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
        goto L_8000105C;
    // 0x8000101C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_80001020:
    // 0x80001020: bne         $a0, $s3, L_80001034
    if (ctx->r4 != ctx->r19) {
        // 0x80001024: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_80001034;
    }
    // 0x80001024: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80001028: lh          $v0, 0xE($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XE);
    // 0x8000102C: j           L_80001050
    // 0x80001030: nop

        goto L_80001050;
    // 0x80001030: nop

L_80001034:
    // 0x80001034: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80001038: lw          $v1, -0x68A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X68A4);
    // 0x8000103C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80001040: lw          $a0, -0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X84);
    // 0x80001044: jal         0x8005F360
    // 0x80001048: nop

    func_8005F360(rdram, ctx);
        goto after_1;
    // 0x80001048: nop

    after_1:
    // 0x8000104C: lh          $v0, 0x6($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6);
L_80001050:
    // 0x80001050: lh          $v1, -0x12($s2)
    ctx->r3 = MEM_H(ctx->r18, -0X12);
    // 0x80001054: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80001058: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_8000105C:
    // 0x8000105C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80001060: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x80001064: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80001068: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x8000106C: xori        $v0, $v0, 0xD
    ctx->r2 = ctx->r2 ^ 0XD;
    // 0x80001070: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80001074: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80001078: bnel        $v1, $zero, L_80000FFC
    if (ctx->r3 != 0) {
        // 0x8000107C: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_80000FFC;
    }
    goto skip_0;
    // 0x8000107C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    skip_0:
L_80001080:
    // 0x80001080: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80001084:
    // 0x80001084: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001088: sw          $s5, -0x68B8($at)
    MEM_W(-0X68B8, ctx->r1) = ctx->r21;
    // 0x8000108C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001090: sw          $s6, -0x6888($at)
    MEM_W(-0X6888, ctx->r1) = ctx->r22;
    // 0x80001094: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001098: sw          $s7, -0x68A8($at)
    MEM_W(-0X68A8, ctx->r1) = ctx->r23;
    // 0x8000109C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800010A0: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800010A4: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800010A8: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800010AC: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800010B0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800010B4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800010B8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800010BC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800010C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800010C4: jr          $ra
    // 0x800010C8: nop

    return;
    // 0x800010C8: nop

;}
RECOMP_FUNC void func_800010CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800010CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800010D0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800010D4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800010D8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800010DC: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800010E0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800010E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800010E8: sw          $zero, -0x68B8($at)
    MEM_W(-0X68B8, ctx->r1) = 0;
    // 0x800010EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800010F0: sh          $t0, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r8;
    // 0x800010F4: bne         $v1, $zero, L_8000110C
    if (ctx->r3 != 0) {
        // 0x800010F8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000110C;
    }
    // 0x800010F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800010FC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80001100: addiu       $v0, $v0, 0x7E8
    ctx->r2 = ADD32(ctx->r2, 0X7E8);
    // 0x80001104: j           L_8000112C
    // 0x80001108: nop

        goto L_8000112C;
    // 0x80001108: nop

L_8000110C:
    // 0x8000110C: bne         $v1, $v0, L_80001124
    if (ctx->r3 != ctx->r2) {
        // 0x80001110: nop
    
            goto L_80001124;
    }
    // 0x80001110: nop

    // 0x80001114: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80001118: addiu       $v0, $v0, 0x830
    ctx->r2 = ADD32(ctx->r2, 0X830);
    // 0x8000111C: j           L_8000112C
    // 0x80001120: nop

        goto L_8000112C;
    // 0x80001120: nop

L_80001124:
    // 0x80001124: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80001128: addiu       $v0, $v0, 0x874
    ctx->r2 = ADD32(ctx->r2, 0X874);
L_8000112C:
    // 0x8000112C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001130: sw          $v0, -0x68B4($at)
    MEM_W(-0X68B4, ctx->r1) = ctx->r2;
    // 0x80001134: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001138: sw          $t0, -0x68B0($at)
    MEM_W(-0X68B0, ctx->r1) = ctx->r8;
    // 0x8000113C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001140: sh          $a1, -0x68AA($at)
    MEM_H(-0X68AA, ctx->r1) = ctx->r5;
    // 0x80001144: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001148: sh          $a2, -0x68AC($at)
    MEM_H(-0X68AC, ctx->r1) = ctx->r6;
    // 0x8000114C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001150: sw          $a3, -0x68A8($at)
    MEM_W(-0X68A8, ctx->r1) = ctx->r7;
    // 0x80001154: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001158: sw          $t2, -0x68A4($at)
    MEM_W(-0X68A4, ctx->r1) = ctx->r10;
    // 0x8000115C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001160: sw          $t1, -0x68A0($at)
    MEM_W(-0X68A0, ctx->r1) = ctx->r9;
    // 0x80001164: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001168: sw          $a0, -0x689C($at)
    MEM_W(-0X689C, ctx->r1) = ctx->r4;
    // 0x8000116C: jal         0x80000788
    // 0x80001170: nop

    func_80000788(rdram, ctx);
        goto after_0;
    // 0x80001170: nop

    after_0:
    // 0x80001174: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80001178: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000117C: jr          $ra
    // 0x80001180: nop

    return;
    // 0x80001180: nop

    // 0x80001184: nop

    // 0x80001188: nop

    // 0x8000118C: nop

;}
RECOMP_FUNC void func_80001190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001194: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80001198: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x8000119C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800011A0: jal         0x8007DEC0
    // 0x800011A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8007DEC0(rdram, ctx);
        goto after_0;
    // 0x800011A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800011A8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800011AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800011B0: jr          $ra
    // 0x800011B4: nop

    return;
    // 0x800011B4: nop

;}
RECOMP_FUNC void func_800011B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800011B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800011BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800011C0: jal         0x8005E844
    // 0x800011C4: nop

    func_8005E844(rdram, ctx);
        goto after_0;
    // 0x800011C4: nop

    after_0:
    // 0x800011C8: jal         0x80000508
    // 0x800011CC: nop

    func_80000508(rdram, ctx);
        goto after_1;
    // 0x800011CC: nop

    after_1:
    // 0x800011D0: jal         0x80000500
    // 0x800011D4: nop

    func_80000500(rdram, ctx);
        goto after_2;
    // 0x800011D4: nop

    after_2:
    // 0x800011D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800011DC: sh          $zero, 0x148($at)
    MEM_H(0X148, ctx->r1) = 0;
    // 0x800011E0: jal         0x800242C0
    // 0x800011E4: nop

    func_800242C0(rdram, ctx);
        goto after_3;
    // 0x800011E4: nop

    after_3:
    // 0x800011E8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800011EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800011F0: jr          $ra
    // 0x800011F4: nop

    return;
    // 0x800011F4: nop

;}
RECOMP_FUNC void func_800011F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800011F8: sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4 << 16);
    // 0x800011FC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80001200: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80001204: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80001208: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000120C: mflo        $v1
    ctx->r3 = lo;
    // 0x80001210: nop

    // 0x80001214: nop

    // 0x80001218: lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // 0x8000121C: ori         $v0, $v0, 0x5556
    ctx->r2 = ctx->r2 | 0X5556;
    // 0x80001220: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001224: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001228: sh          $a0, 0x3240($at)
    MEM_H(0X3240, ctx->r1) = ctx->r4;
    // 0x8000122C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80001230: sh          $a1, 0x26E0($at)
    MEM_H(0X26E0, ctx->r1) = ctx->r5;
    // 0x80001234: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x80001238: mfhi        $a2
    ctx->r6 = hi;
    // 0x8000123C: nop

    // 0x80001240: nop

    // 0x80001244: subu        $v1, $a2, $v1
    ctx->r3 = SUB32(ctx->r6, ctx->r3);
    // 0x80001248: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000124C: sh          $v1, 0x26E2($at)
    MEM_H(0X26E2, ctx->r1) = ctx->r3;
    // 0x80001250: jr          $ra
    // 0x80001254: nop

    return;
    // 0x80001254: nop

;}
RECOMP_FUNC void func_80001258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001258: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8000125C: lhu         $a2, 0x26E2($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X26E2);
    // 0x80001260: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80001264: lhu         $a3, 0x26E0($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X26E0);
    // 0x80001268: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000126C: lhu         $v1, 0x3240($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X3240);
    // 0x80001270: addiu       $a1, $a2, 0x1
    ctx->r5 = ADD32(ctx->r6, 0X1);
    // 0x80001274: sll         $v0, $a3, 5
    ctx->r2 = S32(ctx->r7 << 5);
    // 0x80001278: sll         $a0, $a2, 3
    ctx->r4 = S32(ctx->r6 << 3);
    // 0x8000127C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80001280: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80001284: xor         $v1, $v1, $v0
    ctx->r3 = ctx->r3 ^ ctx->r2;
    // 0x80001288: subu        $v1, $v1, $a3
    ctx->r3 = SUB32(ctx->r3, ctx->r7);
    // 0x8000128C: xor         $v1, $a2, $v1
    ctx->r3 = ctx->r6 ^ ctx->r3;
    // 0x80001290: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80001294: sh          $a1, 0x26E2($at)
    MEM_H(0X26E2, ctx->r1) = ctx->r5;
    // 0x80001298: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8000129C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800012A0: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x800012A4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800012A8: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800012AC: beq         $v0, $zero, L_800012C0
    if (ctx->r2 == 0) {
        // 0x800012B0: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_800012C0;
    }
    // 0x800012B0: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800012B4: addiu       $v0, $a2, 0x2
    ctx->r2 = ADD32(ctx->r6, 0X2);
    // 0x800012B8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800012BC: sh          $v0, 0x26E2($at)
    MEM_H(0X26E2, ctx->r1) = ctx->r2;
L_800012C0:
    // 0x800012C0: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800012C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800012C8: sh          $a3, 0x3240($at)
    MEM_H(0X3240, ctx->r1) = ctx->r7;
    // 0x800012CC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800012D0: sh          $a0, 0x26E0($at)
    MEM_H(0X26E0, ctx->r1) = ctx->r4;
    // 0x800012D4: jr          $ra
    // 0x800012D8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x800012D8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void func_800012DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800012DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800012E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800012E4: jal         0x80001258
    // 0x800012E8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80001258(rdram, ctx);
        goto after_0;
    // 0x800012E8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800012EC: jal         0x80001258
    // 0x800012F0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_80001258(rdram, ctx);
        goto after_1;
    // 0x800012F0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x800012F4: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x800012F8: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800012FC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80001300: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80001304: mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001308: mflo        $s0
    ctx->r16 = lo;
    // 0x8000130C: nop

    // 0x80001310: nop

    // 0x80001314: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80001318: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000131C: sw          $s0, 0x4E04($at)
    MEM_W(0X4E04, ctx->r1) = ctx->r16;
    // 0x80001320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001324: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80001328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000132C: jr          $ra
    // 0x80001330: nop

    return;
    // 0x80001330: nop

;}
RECOMP_FUNC void func_80001334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001334: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001338: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000133C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80001340: beq         $s0, $zero, L_80001374
    if (ctx->r16 == 0) {
        // 0x80001344: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80001374;
    }
    // 0x80001344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001348: jal         0x800012DC
    // 0x8000134C: nop

    func_800012DC(rdram, ctx);
        goto after_0;
    // 0x8000134C: nop

    after_0:
    // 0x80001350: divu        $zero, $v0, $s0
    lo = S32(U32(ctx->r2) / U32(ctx->r16)); hi = S32(U32(ctx->r2) % U32(ctx->r16));
    // 0x80001354: bne         $s0, $zero, L_80001360
    if (ctx->r16 != 0) {
        // 0x80001358: nop
    
            goto L_80001360;
    }
    // 0x80001358: nop

    // 0x8000135C: break       7
    do_break(2147488604);
L_80001360:
    // 0x80001360: mfhi        $v0
    ctx->r2 = hi;
    // 0x80001364: nop

    // 0x80001368: nop

    // 0x8000136C: j           L_80001378
    // 0x80001370: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80001378;
    // 0x80001370: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80001374:
    // 0x80001374: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80001378:
    // 0x80001378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000137C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80001380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001384: jr          $ra
    // 0x80001388: nop

    return;
    // 0x80001388: nop

;}
RECOMP_FUNC void func_8000138C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000138C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001390: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80001394: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80001398: beq         $s0, $zero, L_800013CC
    if (ctx->r16 == 0) {
        // 0x8000139C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800013CC;
    }
    // 0x8000139C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800013A0: jal         0x800012DC
    // 0x800013A4: nop

    func_800012DC(rdram, ctx);
        goto after_0;
    // 0x800013A4: nop

    after_0:
    // 0x800013A8: divu        $zero, $v0, $s0
    lo = S32(U32(ctx->r2) / U32(ctx->r16)); hi = S32(U32(ctx->r2) % U32(ctx->r16));
    // 0x800013AC: bne         $s0, $zero, L_800013B8
    if (ctx->r16 != 0) {
        // 0x800013B0: nop
    
            goto L_800013B8;
    }
    // 0x800013B0: nop

    // 0x800013B4: break       7
    do_break(2147488692);
L_800013B8:
    // 0x800013B8: mfhi        $v0
    ctx->r2 = hi;
    // 0x800013BC: nop

    // 0x800013C0: nop

    // 0x800013C4: j           L_800013D0
    // 0x800013C8: nop

        goto L_800013D0;
    // 0x800013C8: nop

L_800013CC:
    // 0x800013CC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800013D0:
    // 0x800013D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800013D4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800013D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800013DC: jr          $ra
    // 0x800013E0: nop

    return;
    // 0x800013E0: nop

;}
RECOMP_FUNC void func_800013E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800013E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800013E8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800013EC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800013F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800013F4: jal         0x80001334
    // 0x800013F8: sll         $a0, $s0, 1
    ctx->r4 = S32(ctx->r16 << 1);
    func_80001334(rdram, ctx);
        goto after_0;
    // 0x800013F8: sll         $a0, $s0, 1
    ctx->r4 = S32(ctx->r16 << 1);
    after_0:
    // 0x800013FC: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x80001400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001404: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80001408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000140C: jr          $ra
    // 0x80001410: nop

    return;
    // 0x80001410: nop

;}
RECOMP_FUNC void func_80001414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001418: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000141C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80001420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001424: jal         0x80001334
    // 0x80001428: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    func_80001334(rdram, ctx);
        goto after_0;
    // 0x80001428: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    after_0:
    // 0x8000142C: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x80001430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001434: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80001438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000143C: jr          $ra
    // 0x80001440: nop

    return;
    // 0x80001440: nop

;}
RECOMP_FUNC void func_80001444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001448: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000144C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80001450: slt         $v0, $a0, $s0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80001454: beq         $v0, $zero, L_80001468
    if (ctx->r2 == 0) {
        // 0x80001458: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80001468;
    }
    // 0x80001458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000145C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x80001460: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80001464: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80001468:
    // 0x80001468: jal         0x8000138C
    // 0x8000146C: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    func_8000138C(rdram, ctx);
        goto after_0;
    // 0x8000146C: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    after_0:
    // 0x80001470: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80001474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001478: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000147C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001480: jr          $ra
    // 0x80001484: nop

    return;
    // 0x80001484: nop

;}
