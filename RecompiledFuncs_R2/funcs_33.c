#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_80021418(uint8_t* rdram, recomp_context* ctx);
void func_80021C60(uint8_t* rdram, recomp_context* ctx);
void func_80021FD0(uint8_t* rdram, recomp_context* ctx);
void func_8002220C(uint8_t* rdram, recomp_context* ctx);
void func_8002225C(uint8_t* rdram, recomp_context* ctx);
void func_800232B8(uint8_t* rdram, recomp_context* ctx);
void func_800234AC(uint8_t* rdram, recomp_context* ctx);
void func_80023AE0(uint8_t* rdram, recomp_context* ctx);
void func_80023B08(uint8_t* rdram, recomp_context* ctx);
void func_80023B30(uint8_t* rdram, recomp_context* ctx);
void func_80023E44(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80021274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021274: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80021278: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8002127C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80021280: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80021284: lw          $v0, -0x1034($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1034);
    // 0x80021288: beq         $v0, $zero, L_800212B8
    if (ctx->r2 == 0) {
                return; // L_800212B8 is jr $ra
    }

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_8002128C
    func_8002128C(rdram, ctx);
}
RECOMP_FUNC void func_8002128C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002128C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80021290: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80021294: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80021298: lui         $v1, 0x12C
    ctx->r3 = S32(0X12C << 16);
    // 0x8002129C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800212A0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800212A4: sw          $v1, 0x178($at)
    MEM_W(0X178, ctx->r1) = ctx->r3;
    // 0x800212A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800212AC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800212B0: sw          $zero, 0x184($at)
    MEM_W(0X184, ctx->r1) = 0;
    // 0x800212B4: sw          $zero, 0x1C0($a1)
    MEM_W(0X1C0, ctx->r5) = 0;
    // 0x800212B8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800212BC: jr          $ra
    // 0x800212C0: nop

    return;
    // 0x800212C0: nop

;}
RECOMP_FUNC void func_800212C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800212C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800212C8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800212CC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800212D0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800212D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800212D8: lw          $s1, 0x68($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X68);
    // 0x800212DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800212E0: sw          $s1, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r17;
    // 0x800212E4: lhu         $a0, 0x5A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X5A);
    // 0x800212E8: xori        $v1, $a0, 0x1F
    ctx->r3 = ctx->r4 ^ 0X1F;
    // 0x800212EC: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x800212F0: xori        $v0, $a0, 0x57
    ctx->r2 = ctx->r4 ^ 0X57;
    // 0x800212F4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800212F8: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800212FC: beq         $v1, $zero, L_800213F0
    if (ctx->r3 == 0) {
        // 0x80021300: addiu       $v0, $zero, 0x37
        ctx->r2 = ADD32(0, 0X37);
            goto L_800213F0;
    }
    // 0x80021300: addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
    // 0x80021304: beq         $a0, $v0, L_800213F0
    if (ctx->r4 == ctx->r2) {
        // 0x80021308: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_800213F0;
    }
    // 0x80021308: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8002130C: bnel        $a0, $v0, L_8002134C
    if (ctx->r4 != ctx->r2) {
        // 0x80021310: xori        $v1, $a0, 0x2
        ctx->r3 = ctx->r4 ^ 0X2;
            goto L_8002134C;
    }
    goto skip_0;
    // 0x80021310: xori        $v1, $a0, 0x2
    ctx->r3 = ctx->r4 ^ 0X2;
    skip_0:
    // 0x80021314: lhu         $a0, 0x1B2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1B2);
    // 0x80021318: beq         $a0, $zero, L_800213F0
    if (ctx->r4 == 0) {
        // 0x8002131C: nop
    
            goto L_800213F0;
    }
    // 0x8002131C: nop

    // 0x80021320: jal         0x8001B7D0
    // 0x80021324: nop

    func_8001B7D0(rdram, ctx);
        goto after_0;
    // 0x80021324: nop

    after_0:
    // 0x80021328: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8002132C: beq         $v1, $zero, L_800213F0
    if (ctx->r3 == 0) {
        // 0x80021330: nop
    
            goto L_800213F0;
    }
    // 0x80021330: nop

    // 0x80021334: lhu         $v0, 0x128($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X128);
    // 0x80021338: lhu         $v1, 0x8($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X8);
    // 0x8002133C: addiu       $v0, $v0, 0x9
    ctx->r2 = ADD32(ctx->r2, 0X9);
    // 0x80021340: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80021344: j           L_800213F0
    // 0x80021348: sh          $v1, 0x80($s1)
    MEM_H(0X80, ctx->r17) = ctx->r3;
        goto L_800213F0;
    // 0x80021348: sh          $v1, 0x80($s1)
    MEM_H(0X80, ctx->r17) = ctx->r3;
L_8002134C:
    // 0x8002134C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80021350: xori        $v0, $a0, 0x4E
    ctx->r2 = ctx->r4 ^ 0X4E;
    // 0x80021354: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80021358: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8002135C: beq         $v1, $zero, L_8002137C
    if (ctx->r3 == 0) {
        // 0x80021360: nop
    
            goto L_8002137C;
    }
    // 0x80021360: nop

    // 0x80021364: lhu         $v0, 0x1BE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1BE);
    // 0x80021368: beq         $v0, $zero, L_8002137C
    if (ctx->r2 == 0) {
        // 0x8002136C: nop
    
            goto L_8002137C;
    }
    // 0x8002136C: nop

    // 0x80021370: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x80021374: blez        $v0, L_800213F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80021378: nop
    
            goto L_800213F0;
    }
    // 0x80021378: nop

L_8002137C:
    // 0x8002137C: lhu         $v0, 0x1B0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B0);
    // 0x80021380: bne         $v0, $zero, L_80021398
    if (ctx->r2 != 0) {
        // 0x80021384: nop
    
            goto L_80021398;
    }
    // 0x80021384: nop

    // 0x80021388: lhu         $v0, 0x128($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X128);
    // 0x8002138C: addiu       $v0, $v0, 0x1000
    ctx->r2 = ADD32(ctx->r2, 0X1000);
    // 0x80021390: j           L_800213F0
    // 0x80021394: sh          $v0, 0x80($s1)
    MEM_H(0X80, ctx->r17) = ctx->r2;
        goto L_800213F0;
    // 0x80021394: sh          $v0, 0x80($s1)
    MEM_H(0X80, ctx->r17) = ctx->r2;
L_80021398:
    // 0x80021398: lhu         $a0, 0x1B2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1B2);
    // 0x8002139C: beq         $a0, $zero, L_800213F0
    if (ctx->r4 == 0) {
        // 0x800213A0: nop
    
            goto L_800213F0;
    }
    // 0x800213A0: nop

    // 0x800213A4: jal         0x8001B7D0
    // 0x800213A8: nop

    func_8001B7D0(rdram, ctx);
        goto after_1;
    // 0x800213A8: nop

    after_1:
    // 0x800213AC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800213B0: beq         $v1, $zero, L_800213F0
    if (ctx->r3 == 0) {
        // 0x800213B4: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_800213F0;
    }
    // 0x800213B4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800213B8: lhu         $a0, 0x8($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X8);
    // 0x800213BC: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x800213C0: lhu         $a1, 0x128($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X128);
    // 0x800213C4: beq         $v1, $v0, L_800213D8
    if (ctx->r3 == ctx->r2) {
        // 0x800213C8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800213D8;
    }
    // 0x800213C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800213CC: lhu         $v1, 0x1B0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X1B0);
    // 0x800213D0: bne         $v1, $v0, L_800213E8
    if (ctx->r3 != ctx->r2) {
        // 0x800213D4: addiu       $v0, $a0, 0x32
        ctx->r2 = ADD32(ctx->r4, 0X32);
            goto L_800213E8;
    }
    // 0x800213D4: addiu       $v0, $a0, 0x32
    ctx->r2 = ADD32(ctx->r4, 0X32);
L_800213D8:
    // 0x800213D8: addiu       $v0, $a1, 0x9
    ctx->r2 = ADD32(ctx->r5, 0X9);
    // 0x800213DC: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x800213E0: j           L_800213F0
    // 0x800213E4: sh          $v0, 0x80($s1)
    MEM_H(0X80, ctx->r17) = ctx->r2;
        goto L_800213F0;
    // 0x800213E4: sh          $v0, 0x80($s1)
    MEM_H(0X80, ctx->r17) = ctx->r2;
L_800213E8:
    // 0x800213E8: addu        $a0, $a1, $v0
    ctx->r4 = ADD32(ctx->r5, ctx->r2);
    // 0x800213EC: sh          $a0, 0x80($s1)
    MEM_H(0X80, ctx->r17) = ctx->r4;
L_800213F0:
    // 0x800213F0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800213F4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800213F8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800213FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80021400: jr          $ra
    // 0x80021404: nop

    return;
    // 0x80021404: nop

;}
RECOMP_FUNC void func_80021408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021408: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
    // 0x8002140C: lhu         $v0, 0x6C($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X6C);
    // 0x80021410: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80021414: beq         $v0, $zero, L_80021448
    if (ctx->r2 == 0) {
                func_80021418(rdram, ctx); return; // was goto L_80021448
    }
;}
RECOMP_FUNC void func_80021418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021418: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8002141C: sh          $zero, 0x120($a0)
    MEM_H(0X120, ctx->r4) = 0;
    // 0x80021420: sh          $zero, 0x122($a0)
    MEM_H(0X122, ctx->r4) = 0;
    // 0x80021424: sh          $zero, 0x110($a0)
    MEM_H(0X110, ctx->r4) = 0;
    // 0x80021428: sh          $zero, 0x114($a0)
    MEM_H(0X114, ctx->r4) = 0;
    // 0x8002142C: sh          $zero, 0x108($a0)
    MEM_H(0X108, ctx->r4) = 0;
    // 0x80021430: sh          $zero, 0x10C($a0)
    MEM_H(0X10C, ctx->r4) = 0;
    // 0x80021434: sh          $zero, 0x118($a0)
    MEM_H(0X118, ctx->r4) = 0;
    // 0x80021438: sh          $zero, 0x11A($a0)
    MEM_H(0X11A, ctx->r4) = 0;
    // 0x8002143C: sh          $zero, 0x11C($a0)
    MEM_H(0X11C, ctx->r4) = 0;
    // 0x80021440: j           L_800216DC
    // 0x80021444: sh          $zero, 0x11E($a0)
    MEM_H(0X11E, ctx->r4) = 0;
        goto L_800216DC;
    // 0x80021444: sh          $zero, 0x11E($a0)
    MEM_H(0X11E, ctx->r4) = 0;
    // 0x80021448: lh          $v0, 0x14($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X14);
    // 0x8002144C: lw          $t0, 0x34($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X34);
    // 0x80021450: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80021454: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x80021458: addu        $t2, $v0, $zero
    ctx->r10 = ADD32(ctx->r2, 0);
    // 0x8002145C: lhu         $a3, 0xA($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0XA);
    // 0x80021460: lhu         $t4, 0x8($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X8);
    // 0x80021464: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021468: beq         $v0, $zero, L_80021484
    if (ctx->r2 == 0) {
        // 0x8002146C: nop
    
            goto L_80021484;
    }
    // 0x8002146C: nop

    // 0x80021470: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80021474: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x80021478: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002147C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80021480: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
L_80021484:
    // 0x80021484: lhu         $t3, 0x18($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X18);
    // 0x80021488: sh          $zero, 0x120($a0)
    MEM_H(0X120, ctx->r4) = 0;
    // 0x8002148C: sh          $zero, 0x122($a0)
    MEM_H(0X122, ctx->r4) = 0;
    // 0x80021490: sh          $zero, 0x118($a0)
    MEM_H(0X118, ctx->r4) = 0;
    // 0x80021494: sh          $zero, 0x11A($a0)
    MEM_H(0X11A, ctx->r4) = 0;
    // 0x80021498: sh          $zero, 0x11C($a0)
    MEM_H(0X11C, ctx->r4) = 0;
    // 0x8002149C: sh          $zero, 0x11E($a0)
    MEM_H(0X11E, ctx->r4) = 0;
    // 0x800214A0: lb          $v1, 0x14($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X14);
    // 0x800214A4: lb          $v0, 0x16($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X16);
    // 0x800214A8: beq         $v1, $v0, L_80021534
    if (ctx->r3 == ctx->r2) {
        // 0x800214AC: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_80021534;
    }
    // 0x800214AC: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x800214B0: lbu         $v0, 0x15($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X15);
    // 0x800214B4: lhu         $v1, 0x22($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X22);
    // 0x800214B8: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800214BC: andi        $v1, $v1, 0x10
    ctx->r3 = ctx->r3 & 0X10;
    // 0x800214C0: beq         $v1, $zero, L_800214CC
    if (ctx->r3 == 0) {
        // 0x800214C4: sra         $a2, $v0, 24
        ctx->r6 = S32(SIGNED(ctx->r2) >> 24);
            goto L_800214CC;
    }
    // 0x800214C4: sra         $a2, $v0, 24
    ctx->r6 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800214C8: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_800214CC:
    // 0x800214CC: addu        $v0, $a1, $t2
    ctx->r2 = ADD32(ctx->r5, ctx->r10);
    // 0x800214D0: sh          $v0, 0x118($a0)
    MEM_H(0X118, ctx->r4) = ctx->r2;
    // 0x800214D4: addu        $v0, $a2, $t3
    ctx->r2 = ADD32(ctx->r6, ctx->r11);
    // 0x800214D8: sh          $v0, 0x11A($a0)
    MEM_H(0X11A, ctx->r4) = ctx->r2;
    // 0x800214DC: lbu         $v0, 0x16($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X16);
    // 0x800214E0: lbu         $v1, 0x17($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X17);
    // 0x800214E4: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800214E8: sra         $a1, $v0, 24
    ctx->r5 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800214EC: lhu         $v0, 0x22($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X22);
    // 0x800214F0: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x800214F4: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800214F8: beq         $v0, $zero, L_80021504
    if (ctx->r2 == 0) {
        // 0x800214FC: sra         $a2, $v1, 24
        ctx->r6 = S32(SIGNED(ctx->r3) >> 24);
            goto L_80021504;
    }
    // 0x800214FC: sra         $a2, $v1, 24
    ctx->r6 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80021500: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_80021504:
    // 0x80021504: addu        $v0, $a1, $t2
    ctx->r2 = ADD32(ctx->r5, ctx->r10);
    // 0x80021508: sh          $v0, 0x11C($a0)
    MEM_H(0X11C, ctx->r4) = ctx->r2;
    // 0x8002150C: addu        $v0, $a2, $t3
    ctx->r2 = ADD32(ctx->r6, ctx->r11);
    // 0x80021510: sh          $v0, 0x11E($a0)
    MEM_H(0X11E, ctx->r4) = ctx->r2;
    // 0x80021514: lhu         $v0, 0x22($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X22);
    // 0x80021518: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8002151C: beq         $v0, $zero, L_80021534
    if (ctx->r2 == 0) {
        // 0x80021520: nop
    
            goto L_80021534;
    }
    // 0x80021520: nop

    // 0x80021524: lhu         $v0, 0x11C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X11C);
    // 0x80021528: lhu         $a1, 0x118($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X118);
    // 0x8002152C: sh          $v0, 0x118($a0)
    MEM_H(0X118, ctx->r4) = ctx->r2;
    // 0x80021530: sh          $a1, 0x11C($a0)
    MEM_H(0X11C, ctx->r4) = ctx->r5;
L_80021534:
    // 0x80021534: lb          $v1, 0x18($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X18);
    // 0x80021538: beq         $v1, $zero, L_80021574
    if (ctx->r3 == 0) {
        // 0x8002153C: subu        $a2, $v1, $a3
        ctx->r6 = SUB32(ctx->r3, ctx->r7);
            goto L_80021574;
    }
    // 0x8002153C: subu        $a2, $v1, $a3
    ctx->r6 = SUB32(ctx->r3, ctx->r7);
    // 0x80021540: lbu         $v0, 0x19($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X19);
    // 0x80021544: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x80021548: lhu         $v1, 0x22($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X22);
    // 0x8002154C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80021550: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80021554: andi        $v1, $v1, 0x10
    ctx->r3 = ctx->r3 & 0X10;
    // 0x80021558: beq         $v1, $zero, L_80021564
    if (ctx->r3 == 0) {
        // 0x8002155C: subu        $a3, $v0, $t4
        ctx->r7 = SUB32(ctx->r2, ctx->r12);
            goto L_80021564;
    }
    // 0x8002155C: subu        $a3, $v0, $t4
    ctx->r7 = SUB32(ctx->r2, ctx->r12);
    // 0x80021560: negu        $a1, $a2
    ctx->r5 = SUB32(0, ctx->r6);
L_80021564:
    // 0x80021564: addu        $v0, $a1, $t2
    ctx->r2 = ADD32(ctx->r5, ctx->r10);
    // 0x80021568: sh          $v0, 0x120($a0)
    MEM_H(0X120, ctx->r4) = ctx->r2;
    // 0x8002156C: addu        $v0, $a3, $t3
    ctx->r2 = ADD32(ctx->r7, ctx->r11);
    // 0x80021570: sh          $v0, 0x122($a0)
    MEM_H(0X122, ctx->r4) = ctx->r2;
L_80021574:
    // 0x80021574: lhu         $v0, 0xDC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XDC);
    // 0x80021578: bne         $v0, $zero, L_80021594
    if (ctx->r2 != 0) {
        // 0x8002157C: addiu       $v0, $zero, 0x37
        ctx->r2 = ADD32(0, 0X37);
            goto L_80021594;
    }
    // 0x8002157C: addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
    // 0x80021580: sh          $zero, 0x110($a0)
    MEM_H(0X110, ctx->r4) = 0;
    // 0x80021584: sh          $zero, 0x114($a0)
    MEM_H(0X114, ctx->r4) = 0;
    // 0x80021588: sh          $zero, 0x108($a0)
    MEM_H(0X108, ctx->r4) = 0;
    // 0x8002158C: j           L_800216DC
    // 0x80021590: sh          $zero, 0x10C($a0)
    MEM_H(0X10C, ctx->r4) = 0;
        goto L_800216DC;
    // 0x80021590: sh          $zero, 0x10C($a0)
    MEM_H(0X10C, ctx->r4) = 0;
L_80021594:
    // 0x80021594: lhu         $v1, 0x5A($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X5A);
    // 0x80021598: bne         $v1, $v0, L_800215CC
    if (ctx->r3 != ctx->r2) {
        // 0x8002159C: addiu       $a1, $t2, -0xA
        ctx->r5 = ADD32(ctx->r10, -0XA);
            goto L_800215CC;
    }
    // 0x8002159C: addiu       $a1, $t2, -0xA
    ctx->r5 = ADD32(ctx->r10, -0XA);
    // 0x800215A0: sh          $a1, 0x108($a0)
    MEM_H(0X108, ctx->r4) = ctx->r5;
    // 0x800215A4: addiu       $a1, $t2, 0xA
    ctx->r5 = ADD32(ctx->r10, 0XA);
    // 0x800215A8: sh          $a1, 0x10C($a0)
    MEM_H(0X10C, ctx->r4) = ctx->r5;
    // 0x800215AC: addiu       $a1, $t3, -0xA
    ctx->r5 = ADD32(ctx->r11, -0XA);
    // 0x800215B0: sh          $a1, 0x10A($a0)
    MEM_H(0X10A, ctx->r4) = ctx->r5;
    // 0x800215B4: sh          $t3, 0x10E($a0)
    MEM_H(0X10E, ctx->r4) = ctx->r11;
    // 0x800215B8: sh          $zero, 0x110($a0)
    MEM_H(0X110, ctx->r4) = 0;
    // 0x800215BC: sh          $zero, 0x114($a0)
    MEM_H(0X114, ctx->r4) = 0;
    // 0x800215C0: sh          $zero, 0x112($a0)
    MEM_H(0X112, ctx->r4) = 0;
    // 0x800215C4: j           L_800216DC
    // 0x800215C8: sh          $zero, 0x116($a0)
    MEM_H(0X116, ctx->r4) = 0;
        goto L_800216DC;
    // 0x800215C8: sh          $zero, 0x116($a0)
    MEM_H(0X116, ctx->r4) = 0;
L_800215CC:
    // 0x800215CC: lbu         $v0, 0xC($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XC);
    // 0x800215D0: lbu         $v1, 0xD($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XD);
    // 0x800215D4: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800215D8: sra         $a1, $v0, 24
    ctx->r5 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800215DC: lhu         $v0, 0x22($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X22);
    // 0x800215E0: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x800215E4: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800215E8: beq         $v0, $zero, L_800215F4
    if (ctx->r2 == 0) {
        // 0x800215EC: sra         $a2, $v1, 24
        ctx->r6 = S32(SIGNED(ctx->r3) >> 24);
            goto L_800215F4;
    }
    // 0x800215EC: sra         $a2, $v1, 24
    ctx->r6 = S32(SIGNED(ctx->r3) >> 24);
    // 0x800215F0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_800215F4:
    // 0x800215F4: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x800215F8: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x800215FC: sh          $a1, 0x110($a0)
    MEM_H(0X110, ctx->r4) = ctx->r5;
    // 0x80021600: sh          $a2, 0x112($a0)
    MEM_H(0X112, ctx->r4) = ctx->r6;
    // 0x80021604: lbu         $v0, 0xE($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XE);
    // 0x80021608: lbu         $v1, 0xF($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XF);
    // 0x8002160C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80021610: sra         $a3, $v0, 24
    ctx->r7 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80021614: lhu         $v0, 0x22($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X22);
    // 0x80021618: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x8002161C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80021620: beq         $v0, $zero, L_8002162C
    if (ctx->r2 == 0) {
        // 0x80021624: sra         $a2, $v1, 24
        ctx->r6 = S32(SIGNED(ctx->r3) >> 24);
            goto L_8002162C;
    }
    // 0x80021624: sra         $a2, $v1, 24
    ctx->r6 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80021628: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
L_8002162C:
    // 0x8002162C: addu        $a3, $a3, $t2
    ctx->r7 = ADD32(ctx->r7, ctx->r10);
    // 0x80021630: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x80021634: sh          $a3, 0x114($a0)
    MEM_H(0X114, ctx->r4) = ctx->r7;
    // 0x80021638: sh          $a2, 0x116($a0)
    MEM_H(0X116, ctx->r4) = ctx->r6;
    // 0x8002163C: lhu         $v0, 0x22($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X22);
    // 0x80021640: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80021644: beq         $v0, $zero, L_80021654
    if (ctx->r2 == 0) {
        // 0x80021648: nop
    
            goto L_80021654;
    }
    // 0x80021648: nop

    // 0x8002164C: sh          $a1, 0x114($a0)
    MEM_H(0X114, ctx->r4) = ctx->r5;
    // 0x80021650: sh          $a3, 0x110($a0)
    MEM_H(0X110, ctx->r4) = ctx->r7;
L_80021654:
    // 0x80021654: lbu         $v0, 0x10($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X10);
    // 0x80021658: lbu         $v1, 0x11($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X11);
    // 0x8002165C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80021660: sra         $a1, $v0, 24
    ctx->r5 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80021664: lhu         $v0, 0x22($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X22);
    // 0x80021668: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x8002166C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80021670: beq         $v0, $zero, L_8002167C
    if (ctx->r2 == 0) {
        // 0x80021674: sra         $a2, $v1, 24
        ctx->r6 = S32(SIGNED(ctx->r3) >> 24);
            goto L_8002167C;
    }
    // 0x80021674: sra         $a2, $v1, 24
    ctx->r6 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80021678: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_8002167C:
    // 0x8002167C: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x80021680: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x80021684: sh          $a1, 0x108($a0)
    MEM_H(0X108, ctx->r4) = ctx->r5;
    // 0x80021688: sh          $a2, 0x10A($a0)
    MEM_H(0X10A, ctx->r4) = ctx->r6;
    // 0x8002168C: lbu         $v0, 0x12($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X12);
    // 0x80021690: lbu         $v1, 0x13($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X13);
    // 0x80021694: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80021698: sra         $a3, $v0, 24
    ctx->r7 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8002169C: lhu         $v0, 0x22($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X22);
    // 0x800216A0: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x800216A4: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800216A8: beq         $v0, $zero, L_800216B4
    if (ctx->r2 == 0) {
        // 0x800216AC: sra         $a2, $v1, 24
        ctx->r6 = S32(SIGNED(ctx->r3) >> 24);
            goto L_800216B4;
    }
    // 0x800216AC: sra         $a2, $v1, 24
    ctx->r6 = S32(SIGNED(ctx->r3) >> 24);
    // 0x800216B0: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
L_800216B4:
    // 0x800216B4: addu        $a3, $a3, $t2
    ctx->r7 = ADD32(ctx->r7, ctx->r10);
    // 0x800216B8: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x800216BC: sh          $a3, 0x10C($a0)
    MEM_H(0X10C, ctx->r4) = ctx->r7;
    // 0x800216C0: sh          $a2, 0x10E($a0)
    MEM_H(0X10E, ctx->r4) = ctx->r6;
    // 0x800216C4: lhu         $v0, 0x22($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X22);
    // 0x800216C8: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800216CC: beq         $v0, $zero, L_800216DC
    if (ctx->r2 == 0) {
        // 0x800216D0: nop
    
            goto L_800216DC;
    }
    // 0x800216D0: nop

    // 0x800216D4: sh          $a1, 0x10C($a0)
    MEM_H(0X10C, ctx->r4) = ctx->r5;
    // 0x800216D8: sh          $a3, 0x108($a0)
    MEM_H(0X108, ctx->r4) = ctx->r7;
L_800216DC:
    // 0x800216DC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800216E0: jr          $ra
    // 0x800216E4: nop

    return;
    // 0x800216E4: nop

;}
RECOMP_FUNC void func_800216E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800216E8: jr          $ra
    // 0x800216EC: nop

    return;
    // 0x800216EC: nop

;}
RECOMP_FUNC void func_800216F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800216F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800216F4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800216F8: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800216FC: beq         $v0, $zero, L_80021718
    if (ctx->r2 == 0) {
        // 0x80021700: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80021718;
    }
    // 0x80021700: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80021704: lhu         $v1, 0x5A($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X5A);
    // 0x80021708: addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // 0x8002170C: beq         $v1, $v0, L_8002171C
    if (ctx->r3 == ctx->r2) {
        // 0x80021710: andi        $v0, $a3, 0xF
        ctx->r2 = ctx->r7 & 0XF;
            goto L_8002171C;
    }
    // 0x80021710: andi        $v0, $a3, 0xF
    ctx->r2 = ctx->r7 & 0XF;
    // 0x80021714: lhu         $a3, 0xC8($a0)
    ctx->r7 = MEM_HU(ctx->r4, 0XC8);
L_80021718:
    // 0x80021718: andi        $v0, $a3, 0xF
    ctx->r2 = ctx->r7 & 0XF;
L_8002171C:
    // 0x8002171C: sltiu       $v1, $v0, 0x9
    ctx->r3 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x80021720: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80021724: and         $a3, $v0, $v1
    ctx->r7 = ctx->r2 & ctx->r3;
    // 0x80021728: lhu         $a1, 0x5A($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X5A);
    // 0x8002172C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80021730: addiu       $a2, $a2, 0x5BD8
    ctx->r6 = ADD32(ctx->r6, 0X5BD8);
    // 0x80021734: addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
    // 0x80021738: bne         $a1, $v0, L_80021750
    if (ctx->r5 != ctx->r2) {
        // 0x8002173C: xori        $v1, $a1, 0x2
        ctx->r3 = ctx->r5 ^ 0X2;
            goto L_80021750;
    }
    // 0x8002173C: xori        $v1, $a1, 0x2
    ctx->r3 = ctx->r5 ^ 0X2;
    // 0x80021740: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80021744: addiu       $a2, $a2, 0x5BB4
    ctx->r6 = ADD32(ctx->r6, 0X5BB4);
    // 0x80021748: j           L_80021794
    // 0x8002174C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
        goto L_80021794;
    // 0x8002174C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_80021750:
    // 0x80021750: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80021754: xori        $v0, $a1, 0x4E
    ctx->r2 = ctx->r5 ^ 0X4E;
    // 0x80021758: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8002175C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021760: bne         $v1, $zero, L_80021788
    if (ctx->r3 != 0) {
        // 0x80021764: nop
    
            goto L_80021788;
    }
    // 0x80021764: nop

    // 0x80021768: lhu         $v0, 0x5C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X5C);
    // 0x8002176C: xori        $v1, $v0, 0x2
    ctx->r3 = ctx->r2 ^ 0X2;
    // 0x80021770: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80021774: xori        $v0, $v0, 0x4E
    ctx->r2 = ctx->r2 ^ 0X4E;
    // 0x80021778: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8002177C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021780: beq         $v1, $zero, L_80021794
    if (ctx->r3 == 0) {
        // 0x80021784: sll         $v0, $a3, 2
        ctx->r2 = S32(ctx->r7 << 2);
            goto L_80021794;
    }
    // 0x80021784: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_80021788:
    // 0x80021788: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8002178C: addiu       $a2, $a2, 0x5BFC
    ctx->r6 = ADD32(ctx->r6, 0X5BFC);
    // 0x80021790: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_80021794:
    // 0x80021794: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80021798: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8002179C: jalr        $v0
    // 0x800217A0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800217A0: nop

    after_0:
    // 0x800217A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800217A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800217AC: jr          $ra
    // 0x800217B0: nop

    return;
    // 0x800217B0: nop

;}
RECOMP_FUNC void func_800217B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800217B4: lhu         $v1, 0x18C($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X18C);
    // 0x800217B8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800217BC: addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // 0x800217C0: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    // 0x800217C4: beq         $a0, $zero, L_800217E0
    if (ctx->r4 == 0) {
        // 0x800217C8: addu        $t0, $a1, $zero
        ctx->r8 = ADD32(ctx->r5, 0);
            goto L_800217E0;
    }
    // 0x800217C8: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x800217CC: andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
    // 0x800217D0: bne         $v0, $zero, L_800217E4
    if (ctx->r2 != 0) {
        // 0x800217D4: andi        $v0, $t1, 0x2
        ctx->r2 = ctx->r9 & 0X2;
            goto L_800217E4;
    }
    // 0x800217D4: andi        $v0, $t1, 0x2
    ctx->r2 = ctx->r9 & 0X2;
    // 0x800217D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800217DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800217E0:
    // 0x800217E0: andi        $v0, $t1, 0x2
    ctx->r2 = ctx->r9 & 0X2;
L_800217E4:
    // 0x800217E4: beq         $v0, $zero, L_800217FC
    if (ctx->r2 == 0) {
        // 0x800217E8: andi        $v0, $t0, 0x2
        ctx->r2 = ctx->r8 & 0X2;
            goto L_800217FC;
    }
    // 0x800217E8: andi        $v0, $t0, 0x2
    ctx->r2 = ctx->r8 & 0X2;
    // 0x800217EC: bne         $v0, $zero, L_80021800
    if (ctx->r2 != 0) {
        // 0x800217F0: andi        $v0, $t1, 0x4
        ctx->r2 = ctx->r9 & 0X4;
            goto L_80021800;
    }
    // 0x800217F0: andi        $v0, $t1, 0x4
    ctx->r2 = ctx->r9 & 0X4;
    // 0x800217F4: ori         $a3, $a3, 0x2
    ctx->r7 = ctx->r7 | 0X2;
    // 0x800217F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800217FC:
    // 0x800217FC: andi        $v0, $t1, 0x4
    ctx->r2 = ctx->r9 & 0X4;
L_80021800:
    // 0x80021800: beq         $v0, $zero, L_80021818
    if (ctx->r2 == 0) {
        // 0x80021804: andi        $v0, $t0, 0x4
        ctx->r2 = ctx->r8 & 0X4;
            goto L_80021818;
    }
    // 0x80021804: andi        $v0, $t0, 0x4
    ctx->r2 = ctx->r8 & 0X4;
    // 0x80021808: bne         $v0, $zero, L_8002181C
    if (ctx->r2 != 0) {
        // 0x8002180C: andi        $v0, $t1, 0x8
        ctx->r2 = ctx->r9 & 0X8;
            goto L_8002181C;
    }
    // 0x8002180C: andi        $v0, $t1, 0x8
    ctx->r2 = ctx->r9 & 0X8;
    // 0x80021810: ori         $a3, $a3, 0x4
    ctx->r7 = ctx->r7 | 0X4;
    // 0x80021814: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80021818:
    // 0x80021818: andi        $v0, $t1, 0x8
    ctx->r2 = ctx->r9 & 0X8;
L_8002181C:
    // 0x8002181C: beq         $v0, $zero, L_80021834
    if (ctx->r2 == 0) {
        // 0x80021820: andi        $v0, $t0, 0x8
        ctx->r2 = ctx->r8 & 0X8;
            goto L_80021834;
    }
    // 0x80021820: andi        $v0, $t0, 0x8
    ctx->r2 = ctx->r8 & 0X8;
    // 0x80021824: bne         $v0, $zero, L_80021838
    if (ctx->r2 != 0) {
        // 0x80021828: andi        $v0, $t1, 0x4
        ctx->r2 = ctx->r9 & 0X4;
            goto L_80021838;
    }
    // 0x80021828: andi        $v0, $t1, 0x4
    ctx->r2 = ctx->r9 & 0X4;
    // 0x8002182C: ori         $a3, $a3, 0x8
    ctx->r7 = ctx->r7 | 0X8;
    // 0x80021830: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80021834:
    // 0x80021834: andi        $v0, $t1, 0x4
    ctx->r2 = ctx->r9 & 0X4;
L_80021838:
    // 0x80021838: sh          $a3, 0xD0($a2)
    MEM_H(0XD0, ctx->r6) = ctx->r7;
    // 0x8002183C: beq         $v0, $zero, L_80021858
    if (ctx->r2 == 0) {
        // 0x80021840: sh          $v1, 0x18C($a2)
        MEM_H(0X18C, ctx->r6) = ctx->r3;
            goto L_80021858;
    }
    // 0x80021840: sh          $v1, 0x18C($a2)
    MEM_H(0X18C, ctx->r6) = ctx->r3;
    // 0x80021844: lhu         $v0, 0x1AA($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X1AA);
    // 0x80021848: bne         $v0, $zero, L_8002185C
    if (ctx->r2 != 0) {
        // 0x8002184C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002185C;
    }
    // 0x8002184C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80021850: j           L_8002185C
    // 0x80021854: sh          $v0, 0x1AA($a2)
    MEM_H(0X1AA, ctx->r6) = ctx->r2;
        goto L_8002185C;
    // 0x80021854: sh          $v0, 0x1AA($a2)
    MEM_H(0X1AA, ctx->r6) = ctx->r2;
L_80021858:
    // 0x80021858: sh          $zero, 0x1AA($a2)
    MEM_H(0X1AA, ctx->r6) = 0;
L_8002185C:
    // 0x8002185C: jr          $ra
    // 0x80021860: nop

    return;
    // 0x80021860: nop

;}
RECOMP_FUNC void func_80021864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021864: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80021868: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8002186C: beql        $a0, $v0, L_80021878
    if (ctx->r4 == ctx->r2) {
        // 0x80021870: sh          $zero, 0xCE($a1)
        MEM_H(0XCE, ctx->r5) = 0;
            goto L_80021878;
    }
    goto skip_0;
    // 0x80021870: sh          $zero, 0xCE($a1)
    MEM_H(0XCE, ctx->r5) = 0;
    skip_0:
    // 0x80021874: sh          $a2, 0xCE($a1)
    MEM_H(0XCE, ctx->r5) = ctx->r6;
L_80021878:
    // 0x80021878: jr          $ra
    // 0x8002187C: nop

    return;
    // 0x8002187C: nop

;}
RECOMP_FUNC void func_80021880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021880: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021884: sh          $zero, 0x166($at)
    MEM_H(0X166, ctx->r1) = 0;
    // 0x80021888: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8002188C: sw          $zero, -0x7374($at)
    MEM_W(-0X7374, ctx->r1) = 0;
    // 0x80021890: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021894: sh          $zero, 0x168($at)
    MEM_H(0X168, ctx->r1) = 0;
    // 0x80021898: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002189C: sw          $zero, 0x3A0($at)
    MEM_W(0X3A0, ctx->r1) = 0;
    // 0x800218A0: jr          $ra
    // 0x800218A4: nop

    return;
    // 0x800218A4: nop

;}
RECOMP_FUNC void func_800218A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800218A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800218AC: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800218B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800218B4: jal         0x8002656C
    // 0x800218B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8002656C(rdram, ctx);
        goto after_0;
    // 0x800218B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800218BC: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800218C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800218C4: beq         $s1, $v0, L_80021910
    if (ctx->r17 == ctx->r2) {
        // 0x800218C8: nop
    
            goto L_80021910;
    }
    // 0x800218C8: nop

    // 0x800218CC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800218D0: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x800218D4: beq         $v0, $zero, L_80021910
    if (ctx->r2 == 0) {
        // 0x800218D8: nop
    
            goto L_80021910;
    }
    // 0x800218D8: nop

    // 0x800218DC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800218E0: lhu         $v0, 0x416C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X416C);
    // 0x800218E4: bne         $v0, $zero, L_80021910
    if (ctx->r2 != 0) {
        // 0x800218E8: nop
    
            goto L_80021910;
    }
    // 0x800218E8: nop

    // 0x800218EC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800218F0: lhu         $v0, -0x68E8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X68E8);
    // 0x800218F4: bne         $v0, $zero, L_80021910
    if (ctx->r2 != 0) {
        // 0x800218F8: nop
    
            goto L_80021910;
    }
    // 0x800218F8: nop

    // 0x800218FC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80021900: addiu       $s0, $s0, 0x164
    ctx->r16 = ADD32(ctx->r16, 0X164);
    // 0x80021904: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80021908: beq         $v0, $zero, L_80021920
    if (ctx->r2 == 0) {
        // 0x8002190C: andi        $v0, $s1, 0x2
        ctx->r2 = ctx->r17 & 0X2;
            goto L_80021920;
    }
    // 0x8002190C: andi        $v0, $s1, 0x2
    ctx->r2 = ctx->r17 & 0X2;
L_80021910:
    // 0x80021910: jal         0x80021880
    // 0x80021914: nop

    func_80021880(rdram, ctx);
        goto after_1;
    // 0x80021914: nop

    after_1:
    // 0x80021918: j           L_80021BF8
    // 0x8002191C: nop

        goto L_80021BF8;
    // 0x8002191C: nop

L_80021920:
    // 0x80021920: beq         $v0, $zero, L_80021940
    if (ctx->r2 == 0) {
        // 0x80021924: nop
    
            goto L_80021940;
    }
    // 0x80021924: nop

    // 0x80021928: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8002192C: lw          $a1, 0x57E4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X57E4);
    // 0x80021930: jal         0x800234AC
    // 0x80021934: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800234AC(rdram, ctx);
        goto after_2;
    // 0x80021934: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x80021938: j           L_80021BF8
    // 0x8002193C: nop

        goto L_80021BF8;
    // 0x8002193C: nop

L_80021940:
    // 0x80021940: jal         0x8002225C
    // 0x80021944: nop

    func_8002225C(rdram, ctx);
        goto after_3;
    // 0x80021944: nop

    after_3:
    // 0x80021948: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8002194C: jal         0x80021FD0
    // 0x80021950: addiu       $a1, $sp, 0x14
    ctx->r5 = ADD32(ctx->r29, 0X14);
    func_80021FD0(rdram, ctx);
        goto after_4;
    // 0x80021950: addiu       $a1, $sp, 0x14
    ctx->r5 = ADD32(ctx->r29, 0X14);
    after_4:
    // 0x80021954: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80021958: lh          $v1, 0x166($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X166);
    // 0x8002195C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80021960: lh          $a1, 0x4E28($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X4E28);
    // 0x80021964: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80021968: beq         $v1, $zero, L_80021A18
    if (ctx->r3 == 0) {
        // 0x8002196C: nop
    
            goto L_80021A18;
    }
    // 0x8002196C: nop

    // 0x80021970: blez        $v1, L_800219BC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80021974: nop
    
            goto L_800219BC;
    }
    // 0x80021974: nop

    // 0x80021978: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8002197C: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x80021980: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80021984: slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80021988: beql        $v0, $zero, L_80021990
    if (ctx->r2 == 0) {
        // 0x8002198C: addu        $a0, $a2, $zero
        ctx->r4 = ADD32(ctx->r6, 0);
            goto L_80021990;
    }
    goto skip_0;
    // 0x8002198C: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    skip_0:
L_80021990:
    // 0x80021990: slti        $v0, $a1, 0xD3
    ctx->r2 = SIGNED(ctx->r5) < 0XD3 ? 1 : 0;
    // 0x80021994: bnel        $v0, $zero, L_800219AC
    if (ctx->r2 != 0) {
        // 0x80021998: slti        $v0, $a1, 0xBF
        ctx->r2 = SIGNED(ctx->r5) < 0XBF ? 1 : 0;
            goto L_800219AC;
    }
    goto skip_1;
    // 0x80021998: slti        $v0, $a1, 0xBF
    ctx->r2 = SIGNED(ctx->r5) < 0XBF ? 1 : 0;
    skip_1:
    // 0x8002199C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x800219A0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800219A4: j           L_800219E8
    // 0x800219A8: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_800219E8;
    // 0x800219A8: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
L_800219AC:
    // 0x800219AC: beq         $v0, $zero, L_80021AD4
    if (ctx->r2 == 0) {
        // 0x800219B0: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_80021AD4;
    }
    // 0x800219B0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800219B4: j           L_80021A08
    // 0x800219B8: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
        goto L_80021A08;
    // 0x800219B8: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
L_800219BC:
    // 0x800219BC: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800219C0: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x800219C4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800219C8: slt         $v0, $a0, $a2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800219CC: beql        $v0, $zero, L_800219D4
    if (ctx->r2 == 0) {
        // 0x800219D0: addu        $a0, $a2, $zero
        ctx->r4 = ADD32(ctx->r6, 0);
            goto L_800219D4;
    }
    goto skip_2;
    // 0x800219D0: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    skip_2:
L_800219D4:
    // 0x800219D4: slti        $v0, $a1, 0xBE
    ctx->r2 = SIGNED(ctx->r5) < 0XBE ? 1 : 0;
    // 0x800219D8: beq         $v0, $zero, L_800219F8
    if (ctx->r2 == 0) {
        // 0x800219DC: lui         $v0, 0xFFFF
        ctx->r2 = S32(0XFFFF << 16);
            goto L_800219F8;
    }
    // 0x800219DC: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
    // 0x800219E0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800219E4: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_800219E8:
    // 0x800219E8: bnel        $v0, $zero, L_80021B9C
    if (ctx->r2 != 0) {
        // 0x800219EC: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80021B9C;
    }
    goto skip_3;
    // 0x800219EC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    skip_3:
    // 0x800219F0: j           L_80021BA0
    // 0x800219F4: andi        $v0, $s1, 0x4
    ctx->r2 = ctx->r17 & 0X4;
        goto L_80021BA0;
    // 0x800219F4: andi        $v0, $s1, 0x4
    ctx->r2 = ctx->r17 & 0X4;
L_800219F8:
    // 0x800219F8: slti        $v0, $a1, 0xD3
    ctx->r2 = SIGNED(ctx->r5) < 0XD3 ? 1 : 0;
    // 0x800219FC: bne         $v0, $zero, L_80021B70
    if (ctx->r2 != 0) {
        // 0x80021A00: lui         $v0, 0xFFFF
        ctx->r2 = S32(0XFFFF << 16);
            goto L_80021B70;
    }
    // 0x80021A00: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
    // 0x80021A04: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
L_80021A08:
    // 0x80021A08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021A0C: sw          $zero, 0x16C($at)
    MEM_W(0X16C, ctx->r1) = 0;
    // 0x80021A10: j           L_80021BF0
    // 0x80021A14: nop

        goto L_80021BF0;
    // 0x80021A14: nop

L_80021A18:
    // 0x80021A18: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80021A1C: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x80021A20: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80021A24: beq         $v0, $zero, L_80021A44
    if (ctx->r2 == 0) {
        // 0x80021A28: slti        $v0, $a1, 0x12D
        ctx->r2 = SIGNED(ctx->r5) < 0X12D ? 1 : 0;
            goto L_80021A44;
    }
    // 0x80021A28: slti        $v0, $a1, 0x12D
    ctx->r2 = SIGNED(ctx->r5) < 0X12D ? 1 : 0;
    // 0x80021A2C: beq         $v0, $zero, L_80021A90
    if (ctx->r2 == 0) {
        // 0x80021A30: slti        $v0, $a1, 0x64
        ctx->r2 = SIGNED(ctx->r5) < 0X64 ? 1 : 0;
            goto L_80021A90;
    }
    // 0x80021A30: slti        $v0, $a1, 0x64
    ctx->r2 = SIGNED(ctx->r5) < 0X64 ? 1 : 0;
    // 0x80021A34: beq         $v0, $zero, L_80021B84
    if (ctx->r2 == 0) {
        // 0x80021A38: nop
    
            goto L_80021B84;
    }
    // 0x80021A38: nop

    // 0x80021A3C: j           L_80021B30
    // 0x80021A40: nop

        goto L_80021B30;
    // 0x80021A40: nop

L_80021A44:
    // 0x80021A44: slti        $v0, $a1, 0xF1
    ctx->r2 = SIGNED(ctx->r5) < 0XF1 ? 1 : 0;
    // 0x80021A48: bne         $v0, $zero, L_80021AE8
    if (ctx->r2 != 0) {
        // 0x80021A4C: slti        $v0, $a1, 0xA0
        ctx->r2 = SIGNED(ctx->r5) < 0XA0 ? 1 : 0;
            goto L_80021AE8;
    }
    // 0x80021A4C: slti        $v0, $a1, 0xA0
    ctx->r2 = SIGNED(ctx->r5) < 0XA0 ? 1 : 0;
    // 0x80021A50: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80021A54: bltz        $v0, L_80021A70
    if (SIGNED(ctx->r2) < 0) {
        // 0x80021A58: nop
    
            goto L_80021A70;
    }
    // 0x80021A58: nop

    // 0x80021A5C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80021A60: lh          $a1, -0x1014($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X1014);
    // 0x80021A64: slti        $v0, $a1, 0x12C
    ctx->r2 = SIGNED(ctx->r5) < 0X12C ? 1 : 0;
    // 0x80021A68: beq         $v0, $zero, L_80021A90
    if (ctx->r2 == 0) {
        // 0x80021A6C: nop
    
            goto L_80021A90;
    }
    // 0x80021A6C: nop

L_80021A70:
    // 0x80021A70: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x80021A74: bltz        $v0, L_80021B84
    if (SIGNED(ctx->r2) < 0) {
        // 0x80021A78: nop
    
            goto L_80021B84;
    }
    // 0x80021A78: nop

    // 0x80021A7C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80021A80: lh          $a1, -0x1D76($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X1D76);
    // 0x80021A84: slti        $v0, $a1, 0x12C
    ctx->r2 = SIGNED(ctx->r5) < 0X12C ? 1 : 0;
    // 0x80021A88: bne         $v0, $zero, L_80021B84
    if (ctx->r2 != 0) {
        // 0x80021A8C: nop
    
            goto L_80021B84;
    }
    // 0x80021A8C: nop

L_80021A90:
    // 0x80021A90: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80021A94: lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X14);
    // 0x80021A98: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80021A9C: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80021AA0: beql        $v0, $zero, L_80021AA8
    if (ctx->r2 == 0) {
        // 0x80021AA4: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80021AA8;
    }
    goto skip_4;
    // 0x80021AA4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    skip_4:
L_80021AA8:
    // 0x80021AA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021AAC: sw          $a0, 0x16C($at)
    MEM_W(0X16C, ctx->r1) = ctx->r4;
    // 0x80021AB0: slti        $v0, $a1, 0x12D
    ctx->r2 = SIGNED(ctx->r5) < 0X12D ? 1 : 0;
    // 0x80021AB4: bne         $v0, $zero, L_80021AC8
    if (ctx->r2 != 0) {
        // 0x80021AB8: slti        $v0, $a1, 0xDD
        ctx->r2 = SIGNED(ctx->r5) < 0XDD ? 1 : 0;
            goto L_80021AC8;
    }
    // 0x80021AB8: slti        $v0, $a1, 0xDD
    ctx->r2 = SIGNED(ctx->r5) < 0XDD ? 1 : 0;
    // 0x80021ABC: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80021AC0: j           L_80021B9C
    // 0x80021AC4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
        goto L_80021B9C;
    // 0x80021AC4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_80021AC8:
    // 0x80021AC8: bnel        $v0, $zero, L_80021B9C
    if (ctx->r2 != 0) {
        // 0x80021ACC: lui         $a0, 0x1
        ctx->r4 = S32(0X1 << 16);
            goto L_80021B9C;
    }
    goto skip_5;
    // 0x80021ACC: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    skip_5:
    // 0x80021AD0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80021AD4:
    // 0x80021AD4: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80021AD8: bne         $v0, $zero, L_80021BA0
    if (ctx->r2 != 0) {
        // 0x80021ADC: andi        $v0, $s1, 0x4
        ctx->r2 = ctx->r17 & 0X4;
            goto L_80021BA0;
    }
    // 0x80021ADC: andi        $v0, $s1, 0x4
    ctx->r2 = ctx->r17 & 0X4;
    // 0x80021AE0: j           L_80021BA0
    // 0x80021AE4: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
        goto L_80021BA0;
    // 0x80021AE4: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
L_80021AE8:
    // 0x80021AE8: beq         $v0, $zero, L_80021B84
    if (ctx->r2 == 0) {
        // 0x80021AEC: nop
    
            goto L_80021B84;
    }
    // 0x80021AEC: nop

    // 0x80021AF0: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80021AF4: bgtz        $v0, L_80021B10
    if (SIGNED(ctx->r2) > 0) {
        // 0x80021AF8: nop
    
            goto L_80021B10;
    }
    // 0x80021AF8: nop

    // 0x80021AFC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80021B00: lh          $a1, -0x1014($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X1014);
    // 0x80021B04: slti        $v0, $a1, 0x65
    ctx->r2 = SIGNED(ctx->r5) < 0X65 ? 1 : 0;
    // 0x80021B08: bne         $v0, $zero, L_80021B30
    if (ctx->r2 != 0) {
        // 0x80021B0C: nop
    
            goto L_80021B30;
    }
    // 0x80021B0C: nop

L_80021B10:
    // 0x80021B10: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x80021B14: bgtz        $v0, L_80021B84
    if (SIGNED(ctx->r2) > 0) {
        // 0x80021B18: nop
    
            goto L_80021B84;
    }
    // 0x80021B18: nop

    // 0x80021B1C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80021B20: lh          $a1, -0x1D76($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X1D76);
    // 0x80021B24: slti        $v0, $a1, 0x65
    ctx->r2 = SIGNED(ctx->r5) < 0X65 ? 1 : 0;
    // 0x80021B28: beq         $v0, $zero, L_80021B84
    if (ctx->r2 == 0) {
        // 0x80021B2C: nop
    
            goto L_80021B84;
    }
    // 0x80021B2C: nop

L_80021B30:
    // 0x80021B30: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80021B34: lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X14);
    // 0x80021B38: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80021B3C: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021B40: beql        $v0, $zero, L_80021B48
    if (ctx->r2 == 0) {
        // 0x80021B44: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80021B48;
    }
    goto skip_6;
    // 0x80021B44: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    skip_6:
L_80021B48:
    // 0x80021B48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021B4C: sw          $a0, 0x16C($at)
    MEM_W(0X16C, ctx->r1) = ctx->r4;
    // 0x80021B50: slti        $v0, $a1, 0x64
    ctx->r2 = SIGNED(ctx->r5) < 0X64 ? 1 : 0;
    // 0x80021B54: beq         $v0, $zero, L_80021B64
    if (ctx->r2 == 0) {
        // 0x80021B58: lui         $v0, 0xFFFF
        ctx->r2 = S32(0XFFFF << 16);
            goto L_80021B64;
    }
    // 0x80021B58: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
    // 0x80021B5C: j           L_80021B9C
    // 0x80021B60: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
        goto L_80021B9C;
    // 0x80021B60: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_80021B64:
    // 0x80021B64: slti        $v0, $a1, 0xB4
    ctx->r2 = SIGNED(ctx->r5) < 0XB4 ? 1 : 0;
    // 0x80021B68: beq         $v0, $zero, L_80021B7C
    if (ctx->r2 == 0) {
        // 0x80021B6C: lui         $v0, 0xFFFF
        ctx->r2 = S32(0XFFFF << 16);
            goto L_80021B7C;
    }
    // 0x80021B6C: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
L_80021B70:
    // 0x80021B70: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80021B74: beq         $v0, $zero, L_80021BA0
    if (ctx->r2 == 0) {
        // 0x80021B78: andi        $v0, $s1, 0x4
        ctx->r2 = ctx->r17 & 0X4;
            goto L_80021BA0;
    }
    // 0x80021B78: andi        $v0, $s1, 0x4
    ctx->r2 = ctx->r17 & 0X4;
L_80021B7C:
    // 0x80021B7C: j           L_80021B9C
    // 0x80021B80: lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
        goto L_80021B9C;
    // 0x80021B80: lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
L_80021B84:
    // 0x80021B84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021B88: sh          $zero, 0x166($at)
    MEM_H(0X166, ctx->r1) = 0;
    // 0x80021B8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021B90: sw          $zero, 0x16C($at)
    MEM_W(0X16C, ctx->r1) = 0;
    // 0x80021B94: j           L_80021BF0
    // 0x80021B98: nop

        goto L_80021BF0;
    // 0x80021B98: nop

L_80021B9C:
    // 0x80021B9C: andi        $v0, $s1, 0x4
    ctx->r2 = ctx->r17 & 0X4;
L_80021BA0:
    // 0x80021BA0: bne         $v0, $zero, L_80021BF0
    if (ctx->r2 != 0) {
        // 0x80021BA4: nop
    
            goto L_80021BF0;
    }
    // 0x80021BA4: nop

    // 0x80021BA8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80021BAC: lw          $a1, 0x46A8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X46A8);
    // 0x80021BB0: bgez        $a0, L_80021BC8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80021BB4: lui         $v0, 0xFFFF
        ctx->r2 = S32(0XFFFF << 16);
            goto L_80021BC8;
    }
    // 0x80021BB4: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
    // 0x80021BB8: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x80021BBC: and         $a0, $v1, $v0
    ctx->r4 = ctx->r3 & ctx->r2;
    // 0x80021BC0: j           L_80021BCC
    // 0x80021BC4: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
        goto L_80021BCC;
    // 0x80021BC4: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_80021BC8:
    // 0x80021BC8: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
L_80021BCC:
    // 0x80021BCC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80021BD0: lw          $v1, 0x3294($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3294);
    // 0x80021BD4: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x80021BD8: sra         $v0, $a0, 16
    ctx->r2 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80021BDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021BE0: sh          $v0, 0x166($at)
    MEM_H(0X166, ctx->r1) = ctx->r2;
    // 0x80021BE4: and         $v1, $a1, $v1
    ctx->r3 = ctx->r5 & ctx->r3;
    // 0x80021BE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80021BEC: sw          $v1, 0x46A8($at)
    MEM_W(0X46A8, ctx->r1) = ctx->r3;
L_80021BF0:
    // 0x80021BF0: jal         0x80021C60
    // 0x80021BF4: nop

    func_80021C60(rdram, ctx);
        goto after_5;
    // 0x80021BF4: nop

    after_5:
L_80021BF8:
    // 0x80021BF8: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80021BFC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80021C00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80021C04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80021C08: jr          $ra
    // 0x80021C0C: nop

    return;
    // 0x80021C0C: nop

;}
RECOMP_FUNC void func_80021C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021C10: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80021C14: lhu         $v0, -0x7334($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7334);
    // 0x80021C18: bne         $v0, $zero, L_80021C24
    if (ctx->r2 != 0) {
        // 0x80021C1C: lui         $v1, 0x2
        ctx->r3 = S32(0X2 << 16);
            goto L_80021C24;
    }
    // 0x80021C1C: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x80021C20: lui         $v1, 0x8
    ctx->r3 = S32(0X8 << 16);
L_80021C24:
    // 0x80021C24: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80021C28: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80021C2C: sw          $v1, -0x7374($at)
    MEM_W(-0X7374, ctx->r1) = ctx->r3;
    // 0x80021C30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021C34: sh          $v0, 0x168($at)
    MEM_H(0X168, ctx->r1) = ctx->r2;
    // 0x80021C38: jr          $ra
    // 0x80021C3C: nop

    return;
    // 0x80021C3C: nop

;}
RECOMP_FUNC void func_80021C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021C40: lui         $v0, 0xFFFE
    ctx->r2 = S32(0XFFFE << 16);
    // 0x80021C44: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80021C48: sw          $v0, -0x7374($at)
    MEM_W(-0X7374, ctx->r1) = ctx->r2;
    // 0x80021C4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80021C50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021C54: sh          $v0, 0x168($at)
    MEM_H(0X168, ctx->r1) = ctx->r2;
    // 0x80021C58: jr          $ra
    // 0x80021C5C: nop

    return;
    // 0x80021C5C: nop

;}
RECOMP_FUNC void func_80021C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021C60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80021C64: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80021C68: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80021C6C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80021C70: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80021C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80021C78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80021C7C: addiu       $a0, $a0, 0x184
    ctx->r4 = ADD32(ctx->r4, 0X184);
    // 0x80021C80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80021C84: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80021C88: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80021C8C: lui         $s1, 0x7777
    ctx->r17 = S32(0X7777 << 16);
    // 0x80021C90: beq         $v1, $zero, L_80021CA0
    if (ctx->r3 == 0) {
        // 0x80021C94: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80021CA0;
    }
    // 0x80021C94: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80021C98: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // 0x80021C9C: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
L_80021CA0:
    // 0x80021CA0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80021CA4: beq         $v1, $zero, L_80021CD0
    if (ctx->r3 == 0) {
        // 0x80021CA8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80021CD0;
    }
    // 0x80021CA8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80021CAC: slt         $v0, $v1, $s0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80021CB0: bne         $v0, $zero, L_80021CC0
    if (ctx->r2 != 0) {
        // 0x80021CB4: slt         $v0, $s1, $v1
        ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80021CC0;
    }
    // 0x80021CB4: slt         $v0, $s1, $v1
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021CB8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x80021CBC: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_80021CC0:
    // 0x80021CC0: bne         $v0, $zero, L_80021CD0
    if (ctx->r2 != 0) {
        // 0x80021CC4: nop
    
            goto L_80021CD0;
    }
    // 0x80021CC4: nop

    // 0x80021CC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80021CCC: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_80021CD0:
    // 0x80021CD0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80021CD4: beq         $v1, $zero, L_80021CFC
    if (ctx->r3 == 0) {
        // 0x80021CD8: slt         $v0, $v1, $s0
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_80021CFC;
    }
    // 0x80021CD8: slt         $v0, $v1, $s0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80021CDC: bne         $v0, $zero, L_80021CEC
    if (ctx->r2 != 0) {
        // 0x80021CE0: slt         $v0, $s1, $v1
        ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80021CEC;
    }
    // 0x80021CE0: slt         $v0, $s1, $v1
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021CE4: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x80021CE8: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_80021CEC:
    // 0x80021CEC: bne         $v0, $zero, L_80021CFC
    if (ctx->r2 != 0) {
        // 0x80021CF0: nop
    
            goto L_80021CFC;
    }
    // 0x80021CF0: nop

    // 0x80021CF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80021CF8: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_80021CFC:
    // 0x80021CFC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80021D00: lh          $v1, 0x168($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X168);
    // 0x80021D04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021D08: sw          $s0, 0x170($at)
    MEM_W(0X170, ctx->r1) = ctx->r16;
    // 0x80021D0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021D10: sw          $s1, 0x174($at)
    MEM_W(0X174, ctx->r1) = ctx->r17;
    // 0x80021D14: bne         $v1, $zero, L_80021E80
    if (ctx->r3 != 0) {
        // 0x80021D18: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80021E80;
    }
    // 0x80021D18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80021D1C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80021D20: lhu         $v0, -0x7502($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7502);
    // 0x80021D24: beq         $v0, $zero, L_80021DB4
    if (ctx->r2 == 0) {
        // 0x80021D28: lui         $v0, 0x87
        ctx->r2 = S32(0X87 << 16);
            goto L_80021DB4;
    }
    // 0x80021D28: lui         $v0, 0x87
    ctx->r2 = S32(0X87 << 16);
L_80021D2C:
    // 0x80021D2C: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80021D30: lui         $v1, 0xEF
    ctx->r3 = S32(0XEF << 16);
    // 0x80021D34: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80021D38: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80021D3C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80021D40: slt         $v1, $v1, $s0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80021D44: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80021D48: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80021D4C: bne         $v0, $zero, L_80021D88
    if (ctx->r2 != 0) {
        // 0x80021D50: lui         $v1, 0xA7
        ctx->r3 = S32(0XA7 << 16);
            goto L_80021D88;
    }
    // 0x80021D50: lui         $v1, 0xA7
    ctx->r3 = S32(0XA7 << 16);
    // 0x80021D54: jal         0x8001F310
    // 0x80021D58: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001F310(rdram, ctx);
        goto after_0;
    // 0x80021D58: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // 0x80021D5C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80021D60: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80021D64: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80021D68: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80021D6C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80021D70: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80021D74: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80021D78: lw          $v0, 0x3FFC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3FFC);
    // 0x80021D7C: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80021D80: bgtz        $v0, L_80021DFC
    if (SIGNED(ctx->r2) > 0) {
        // 0x80021D84: lui         $v1, 0xA7
        ctx->r3 = S32(0XA7 << 16);
            goto L_80021DFC;
    }
    // 0x80021D84: lui         $v1, 0xA7
    ctx->r3 = S32(0XA7 << 16);
L_80021D88:
    // 0x80021D88: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80021D8C: lui         $v0, 0xDF
    ctx->r2 = S32(0XDF << 16);
    // 0x80021D90: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80021D94: slt         $v1, $v1, $s1
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80021D98: slt         $v0, $v0, $s0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80021D9C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80021DA0: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80021DA4: beq         $v1, $zero, L_80021DFC
    if (ctx->r3 == 0) {
        // 0x80021DA8: nop
    
            goto L_80021DFC;
    }
    // 0x80021DA8: nop

    // 0x80021DAC: j           L_80021FB4
    // 0x80021DB0: nop

        goto L_80021FB4;
    // 0x80021DB0: nop

L_80021DB4:
    // 0x80021DB4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80021DB8: lhu         $v0, -0x68E8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X68E8);
    // 0x80021DBC: bne         $v0, $zero, L_80021DE4
    if (ctx->r2 != 0) {
        // 0x80021DC0: nop
    
            goto L_80021DE4;
    }
    // 0x80021DC0: nop

    // 0x80021DC4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80021DC8: lhu         $v0, 0x416C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X416C);
    // 0x80021DCC: bne         $v0, $zero, L_80021DE4
    if (ctx->r2 != 0) {
        // 0x80021DD0: nop
    
            goto L_80021DE4;
    }
    // 0x80021DD0: nop

    // 0x80021DD4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80021DD8: lhu         $v0, 0x19A($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X19A);
    // 0x80021DDC: beq         $v0, $zero, L_80021E0C
    if (ctx->r2 == 0) {
        // 0x80021DE0: lui         $v1, 0xF0
        ctx->r3 = S32(0XF0 << 16);
            goto L_80021E0C;
    }
    // 0x80021DE0: lui         $v1, 0xF0
    ctx->r3 = S32(0XF0 << 16);
L_80021DE4:
    // 0x80021DE4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80021DE8: lw          $s0, 0x3A0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X3A0);
    // 0x80021DEC: beq         $s0, $zero, L_80021FB4
    if (ctx->r16 == 0) {
        // 0x80021DF0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80021FB4;
    }
    // 0x80021DF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80021DF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021DF8: sh          $v0, 0x19A($at)
    MEM_H(0X19A, ctx->r1) = ctx->r2;
L_80021DFC:
    // 0x80021DFC: jal         0x80021C10
    // 0x80021E00: nop

    func_80021C10(rdram, ctx);
        goto after_1;
    // 0x80021E00: nop

    after_1:
    // 0x80021E04: j           L_80021FB4
    // 0x80021E08: nop

        goto L_80021FB4;
    // 0x80021E08: nop

L_80021E0C:
    // 0x80021E0C: slt         $v1, $v1, $s0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80021E10: lui         $v0, 0x70
    ctx->r2 = S32(0X70 << 16);
    // 0x80021E14: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80021E18: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021E1C: bne         $v1, $zero, L_80021E58
    if (ctx->r3 != 0) {
        // 0x80021E20: lui         $v1, 0xB8
        ctx->r3 = S32(0XB8 << 16);
            goto L_80021E58;
    }
    // 0x80021E20: lui         $v1, 0xB8
    ctx->r3 = S32(0XB8 << 16);
    // 0x80021E24: jal         0x8001F310
    // 0x80021E28: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_8001F310(rdram, ctx);
        goto after_2;
    // 0x80021E28: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_2:
    // 0x80021E2C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80021E30: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80021E34: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80021E38: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80021E3C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80021E40: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80021E44: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80021E48: lw          $v0, 0x3FFC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3FFC);
    // 0x80021E4C: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80021E50: bltz        $v0, L_80021E70
    if (SIGNED(ctx->r2) < 0) {
        // 0x80021E54: lui         $v1, 0xB8
        ctx->r3 = S32(0XB8 << 16);
            goto L_80021E70;
    }
    // 0x80021E54: lui         $v1, 0xB8
    ctx->r3 = S32(0XB8 << 16);
L_80021E58:
    // 0x80021E58: slt         $v1, $v1, $s0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80021E5C: lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
    // 0x80021E60: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80021E64: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80021E68: bne         $v1, $zero, L_80021D2C
    if (ctx->r3 != 0) {
        // 0x80021E6C: lui         $v0, 0x87
        ctx->r2 = S32(0X87 << 16);
            goto L_80021D2C;
    }
    // 0x80021E6C: lui         $v0, 0x87
    ctx->r2 = S32(0X87 << 16);
L_80021E70:
    // 0x80021E70: jal         0x80021C40
    // 0x80021E74: nop

    func_80021C40(rdram, ctx);
        goto after_3;
    // 0x80021E74: nop

    after_3:
    // 0x80021E78: j           L_80021FB4
    // 0x80021E7C: nop

        goto L_80021FB4;
    // 0x80021E7C: nop

L_80021E80:
    // 0x80021E80: bne         $v1, $v0, L_80021EE8
    if (ctx->r3 != ctx->r2) {
        // 0x80021E84: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80021EE8;
    }
    // 0x80021E84: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80021E88: lui         $v0, 0x77
    ctx->r2 = S32(0X77 << 16);
    // 0x80021E8C: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80021E90: lui         $v1, 0xEF
    ctx->r3 = S32(0XEF << 16);
    // 0x80021E94: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80021E98: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80021E9C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80021EA0: slt         $v1, $v1, $s0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80021EA4: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80021EA8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80021EAC: beq         $v0, $zero, L_80021F8C
    if (ctx->r2 == 0) {
        // 0x80021EB0: nop
    
            goto L_80021F8C;
    }
    // 0x80021EB0: nop

    // 0x80021EB4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80021EB8: addiu       $a0, $a0, 0x3A0
    ctx->r4 = ADD32(ctx->r4, 0X3A0);
    // 0x80021EBC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80021EC0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80021EC4: lw          $v0, -0x7374($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7374);
    // 0x80021EC8: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80021ECC: lui         $v0, 0xFEB4
    ctx->r2 = S32(0XFEB4 << 16);
    // 0x80021ED0: slt         $v0, $v0, $s0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80021ED4: bne         $v0, $zero, L_80021FB4
    if (ctx->r2 != 0) {
        // 0x80021ED8: sw          $s0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r16;
            goto L_80021FB4;
    }
    // 0x80021ED8: sw          $s0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r16;
    // 0x80021EDC: lui         $s0, 0xFEB4
    ctx->r16 = S32(0XFEB4 << 16);
    // 0x80021EE0: j           L_80021F8C
    // 0x80021EE4: sw          $s0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r16;
        goto L_80021F8C;
    // 0x80021EE4: sw          $s0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r16;
L_80021EE8:
    // 0x80021EE8: bne         $v1, $v0, L_80021FB4
    if (ctx->r3 != ctx->r2) {
        // 0x80021EEC: nop
    
            goto L_80021FB4;
    }
    // 0x80021EEC: nop

    // 0x80021EF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80021EF4: lhu         $v0, 0x19A($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X19A);
    // 0x80021EF8: bne         $v0, $zero, L_80021F18
    if (ctx->r2 != 0) {
        // 0x80021EFC: lui         $v1, 0xC0
        ctx->r3 = S32(0XC0 << 16);
            goto L_80021F18;
    }
    // 0x80021EFC: lui         $v1, 0xC0
    ctx->r3 = S32(0XC0 << 16);
    // 0x80021F00: slt         $v1, $v1, $s0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80021F04: lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
    // 0x80021F08: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80021F0C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80021F10: beq         $v1, $zero, L_80021F8C
    if (ctx->r3 == 0) {
        // 0x80021F14: nop
    
            goto L_80021F8C;
    }
    // 0x80021F14: nop

L_80021F18:
    // 0x80021F18: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80021F1C: addiu       $a0, $a0, 0x3A0
    ctx->r4 = ADD32(ctx->r4, 0X3A0);
    // 0x80021F20: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80021F24: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80021F28: lw          $v0, -0x7374($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7374);
    // 0x80021F2C: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80021F30: bgtz        $s0, L_80021F9C
    if (SIGNED(ctx->r16) > 0) {
        // 0x80021F34: sw          $s0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r16;
            goto L_80021F9C;
    }
    // 0x80021F34: sw          $s0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r16;
    // 0x80021F38: lui         $v0, 0xFFE
    ctx->r2 = S32(0XFFE << 16);
    // 0x80021F3C: ori         $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 | 0X7FFF;
    // 0x80021F40: slt         $v0, $v0, $s0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80021F44: beq         $v0, $zero, L_80021FB4
    if (ctx->r2 == 0) {
        // 0x80021F48: nop
    
            goto L_80021FB4;
    }
    // 0x80021F48: nop

    // 0x80021F4C: jal         0x8001F310
    // 0x80021F50: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_8001F310(rdram, ctx);
        goto after_4;
    // 0x80021F50: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_4:
    // 0x80021F54: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80021F58: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80021F5C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80021F60: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80021F64: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80021F68: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80021F6C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80021F70: lw          $v0, 0x3FFC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3FFC);
    // 0x80021F74: lh          $v0, 0x14($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X14);
    // 0x80021F78: slti        $v0, $v0, 0x71
    ctx->r2 = SIGNED(ctx->r2) < 0X71 ? 1 : 0;
    // 0x80021F7C: beq         $v0, $zero, L_80021FB4
    if (ctx->r2 == 0) {
        // 0x80021F80: nop
    
            goto L_80021FB4;
    }
    // 0x80021F80: nop

    // 0x80021F84: j           L_80021F9C
    // 0x80021F88: nop

        goto L_80021F9C;
    // 0x80021F88: nop

L_80021F8C:
    // 0x80021F8C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80021F90: lw          $v0, 0x3A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A0);
    // 0x80021F94: bltz        $v0, L_80021FA4
    if (SIGNED(ctx->r2) < 0) {
        // 0x80021F98: nop
    
            goto L_80021FA4;
    }
    // 0x80021F98: nop

L_80021F9C:
    // 0x80021F9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021FA0: sw          $zero, 0x3A0($at)
    MEM_W(0X3A0, ctx->r1) = 0;
L_80021FA4:
    // 0x80021FA4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80021FA8: sw          $zero, -0x7374($at)
    MEM_W(-0X7374, ctx->r1) = 0;
    // 0x80021FAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80021FB0: sh          $zero, 0x168($at)
    MEM_H(0X168, ctx->r1) = 0;
L_80021FB4:
    // 0x80021FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80021FB8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80021FBC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80021FC0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80021FC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80021FC8: jr          $ra
    // 0x80021FCC: nop

    return;
    // 0x80021FCC: nop

;}
RECOMP_FUNC void func_80021FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021FD0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80021FD4: lh          $v1, -0x6730($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X6730);
    // FALLTHROUGH: func_80021FD0 falls into func_80021FD8
    func_80021FD8(rdram, ctx);
;}
RECOMP_FUNC void func_80021FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021FD8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80021FDC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80021FE0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80021FE4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80021FE8: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x80021FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80021FF0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80021FF4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80021FF8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80021FFC: beq         $v1, $v0, L_80022018
    if (ctx->r3 == ctx->r2) {
        // 0x80022000: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80022018;
    }
    // 0x80022000: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80022004: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80022008: beq         $v1, $v0, L_8002204C
    if (ctx->r3 == ctx->r2) {
        // 0x8002200C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8002204C;
    }
    // 0x8002200C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80022010: j           L_8002204C
    // 0x80022014: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8002204C;
    // 0x80022014: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80022018:
    // 0x80022018: jal         0x8001F310
    // 0x8002201C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001F310(rdram, ctx);
        goto after_0;
    // 0x8002201C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80022020: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80022024: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80022028: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8002202C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80022030: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022034: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80022038: addiu       $s0, $s0, 0x3F94
    ctx->r16 = ADD32(ctx->r16, 0X3F94);
    // 0x8002203C: addu        $s1, $v1, $s0
    ctx->r17 = ADD32(ctx->r3, ctx->r16);
    // 0x80022040: lw          $s2, 0x68($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X68);
    // 0x80022044: j           L_8002207C
    // 0x80022048: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8002207C;
    // 0x80022048: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8002204C:
    // 0x8002204C: jal         0x8001F310
    // 0x80022050: nop

    func_8001F310(rdram, ctx);
        goto after_1;
    // 0x80022050: nop

    after_1:
    // 0x80022054: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80022058: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002205C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80022060: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80022064: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022068: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8002206C: addiu       $s0, $s0, 0x3F94
    ctx->r16 = ADD32(ctx->r16, 0X3F94);
    // 0x80022070: addu        $s1, $v1, $s0
    ctx->r17 = ADD32(ctx->r3, ctx->r16);
    // 0x80022074: lw          $s2, 0x68($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X68);
    // 0x80022078: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8002207C:
    // 0x8002207C: jal         0x8001F310
    // 0x80022080: nop

    func_8001F310(rdram, ctx);
        goto after_2;
    // 0x80022080: nop

    after_2:
    // 0x80022084: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80022088: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002208C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80022090: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80022094: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022098: addu        $a3, $v1, $s0
    ctx->r7 = ADD32(ctx->r3, ctx->r16);
    // 0x8002209C: lw          $t0, 0x68($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X68);
    // 0x800220A0: beql        $t0, $zero, L_800220A8
    if (ctx->r8 == 0) {
        // 0x800220A4: addu        $t0, $s2, $zero
        ctx->r8 = ADD32(ctx->r18, 0);
            goto L_800220A8;
    }
    goto skip_0;
    // 0x800220A4: addu        $t0, $s2, $zero
    ctx->r8 = ADD32(ctx->r18, 0);
    skip_0:
L_800220A8:
    // 0x800220A8: beql        $s2, $zero, L_800220B0
    if (ctx->r18 == 0) {
        // 0x800220AC: addu        $s2, $t0, $zero
        ctx->r18 = ADD32(ctx->r8, 0);
            goto L_800220B0;
    }
    goto skip_1;
    // 0x800220AC: addu        $s2, $t0, $zero
    ctx->r18 = ADD32(ctx->r8, 0);
    skip_1:
L_800220B0:
    // 0x800220B0: lhu         $t1, 0x14($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X14);
    // 0x800220B4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800220B8: lh          $v1, 0x3294($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X3294);
    // 0x800220BC: lhu         $a2, 0x14($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X14);
    // 0x800220C0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800220C4: lh          $v0, 0x46A8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X46A8);
    // 0x800220C8: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x800220CC: addiu       $v1, $v1, -0x18F
    ctx->r3 = ADD32(ctx->r3, -0X18F);
    // 0x800220D0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800220D4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800220D8: bnel        $v0, $zero, L_8002210C
    if (ctx->r2 != 0) {
        // 0x800220DC: subu        $a1, $t1, $a0
        ctx->r5 = SUB32(ctx->r9, ctx->r4);
            goto L_8002210C;
    }
    goto skip_2;
    // 0x800220DC: subu        $a1, $t1, $a0
    ctx->r5 = SUB32(ctx->r9, ctx->r4);
    skip_2:
    // 0x800220E0: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x800220E4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800220E8: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800220EC: beql        $v0, $zero, L_800220F4
    if (ctx->r2 == 0) {
        // 0x800220F0: addu        $t1, $t1, $a1
        ctx->r9 = ADD32(ctx->r9, ctx->r5);
            goto L_800220F4;
    }
    goto skip_3;
    // 0x800220F0: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    skip_3:
L_800220F4:
    // 0x800220F4: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x800220F8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800220FC: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80022100: beql        $v0, $zero, L_80022108
    if (ctx->r2 == 0) {
        // 0x80022104: addu        $a2, $a2, $a1
        ctx->r6 = ADD32(ctx->r6, ctx->r5);
            goto L_80022108;
    }
    goto skip_4;
    // 0x80022104: addu        $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
    skip_4:
L_80022108:
    // 0x80022108: subu        $a1, $t1, $a0
    ctx->r5 = SUB32(ctx->r9, ctx->r4);
L_8002210C:
    // 0x8002210C: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x80022110: lhu         $v1, 0x5A($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X5A);
    // 0x80022114: subu        $a0, $a2, $a0
    ctx->r4 = SUB32(ctx->r6, ctx->r4);
    // 0x80022118: xori        $v0, $v1, 0x37
    ctx->r2 = ctx->r3 ^ 0X37;
    // 0x8002211C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80022120: xori        $v1, $v1, 0x26
    ctx->r3 = ctx->r3 ^ 0X26;
    // 0x80022124: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80022128: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8002212C: bne         $v0, $zero, L_8002214C
    if (ctx->r2 != 0) {
        // 0x80022130: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_8002214C;
    }
    // 0x80022130: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80022134: lhu         $v0, 0x1C8($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X1C8);
    // 0x80022138: bne         $v0, $zero, L_8002214C
    if (ctx->r2 != 0) {
        // 0x8002213C: nop
    
            goto L_8002214C;
    }
    // 0x8002213C: nop

    // 0x80022140: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x80022144: bne         $v0, $zero, L_80022164
    if (ctx->r2 != 0) {
        // 0x80022148: nop
    
            goto L_80022164;
    }
    // 0x80022148: nop

L_8002214C:
    // 0x8002214C: lw          $v1, 0xC($t0)
    ctx->r3 = MEM_W(ctx->r8, 0XC);
    // 0x80022150: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x80022154: sra         $a1, $v0, 16
    ctx->r5 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022158: sw          $v1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r3;
    // 0x8002215C: j           L_800221E0
    // 0x80022160: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
        goto L_800221E0;
    // 0x80022160: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
L_80022164:
    // 0x80022164: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x80022168: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x8002216C: lhu         $v0, 0x1C8($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X1C8);
    // 0x80022170: bnel        $v0, $zero, L_800221A8
    if (ctx->r2 != 0) {
        // 0x80022174: sw          $zero, 0x0($s3)
        MEM_W(0X0, ctx->r19) = 0;
            goto L_800221A8;
    }
    goto skip_5;
    // 0x80022174: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    skip_5:
    // 0x80022178: lhu         $v0, 0x5A($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X5A);
    // 0x8002217C: xori        $v1, $v0, 0x37
    ctx->r3 = ctx->r2 ^ 0X37;
    // 0x80022180: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80022184: xori        $v0, $v0, 0x26
    ctx->r2 = ctx->r2 ^ 0X26;
    // 0x80022188: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8002218C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80022190: bnel        $v1, $zero, L_800221A8
    if (ctx->r3 != 0) {
        // 0x80022194: sw          $zero, 0x0($s3)
        MEM_W(0X0, ctx->r19) = 0;
            goto L_800221A8;
    }
    goto skip_6;
    // 0x80022194: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    skip_6:
    // 0x80022198: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x8002219C: bne         $v0, $zero, L_800221B0
    if (ctx->r2 != 0) {
        // 0x800221A0: sll         $a0, $a0, 16
        ctx->r4 = S32(ctx->r4 << 16);
            goto L_800221B0;
    }
    // 0x800221A0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800221A4: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_800221A8:
    // 0x800221A8: j           L_800221DC
    // 0x800221AC: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
        goto L_800221DC;
    // 0x800221AC: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
L_800221B0:
    // 0x800221B0: lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XC);
    // 0x800221B4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800221B8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800221BC: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800221C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800221C4: sh          $a2, -0x1014($at)
    MEM_H(-0X1014, ctx->r1) = ctx->r6;
    // 0x800221C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800221CC: sh          $t1, -0x1D76($at)
    MEM_H(-0X1D76, ctx->r1) = ctx->r9;
    // 0x800221D0: jal         0x8002220C
    // 0x800221D4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_8002220C(rdram, ctx);
        goto after_3;
    // 0x800221D4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_3:
    // 0x800221D8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
L_800221DC:
    // 0x800221DC: sra         $a1, $v0, 16
    ctx->r5 = S32(SIGNED(ctx->r2) >> 16);
L_800221E0:
    // 0x800221E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800221E4: sh          $a1, 0x4E28($at)
    MEM_H(0X4E28, ctx->r1) = ctx->r5;
    // 0x800221E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800221EC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800221F0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800221F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800221F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800221FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80022200: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80022204: jr          $ra
    // 0x80022208: nop

    return;
    // 0x80022208: nop

;}
RECOMP_FUNC void func_8002220C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002220C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80022210: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80022214: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80022218: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002221C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80022220: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80022224: slt         $a0, $a0, $a1
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80022228: bne         $a0, $zero, L_80022240
    if (ctx->r4 != 0) {
        // 0x8002222C: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80022240;
    }
    // 0x8002222C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80022230: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x80022234: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80022238: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8002223C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80022240:
    // 0x80022240: subu        $v0, $v1, $a2
    ctx->r2 = SUB32(ctx->r3, ctx->r6);
    // 0x80022244: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80022248: sra         $v0, $v0, 17
    ctx->r2 = S32(SIGNED(ctx->r2) >> 17);
    // 0x8002224C: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x80022250: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80022254: jr          $ra
    // 0x80022258: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x80022258: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void func_8002225C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002225C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80022260: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80022264: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x80022268: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8002226C: addiu       $a1, $a1, -0x5870
    ctx->r5 = ADD32(ctx->r5, -0X5870);
    // 0x80022270: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80022274: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80022278: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x8002227C: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80022280: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80022284: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80022288: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8002228C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80022290: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80022294: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80022298: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8002229C: addiu       $s5, $v0, 0x1
    ctx->r21 = ADD32(ctx->r2, 0X1);
    // 0x800222A0: addiu       $s4, $v0, -0x18F
    ctx->r20 = ADD32(ctx->r2, -0X18F);
    // 0x800222A4: addu        $fp, $s4, $zero
    ctx->r30 = ADD32(ctx->r20, 0);
    // 0x800222A8: sh          $s5, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r21;
L_800222AC:
    // 0x800222AC: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x800222B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800222B4: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x800222B8: sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x800222BC: bne         $v0, $zero, L_800222AC
    if (ctx->r2 != 0) {
        // 0x800222C0: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_800222AC;
    }
    // 0x800222C0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800222C4: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800222C8: lhu         $s3, 0x46A8($s3)
    ctx->r19 = MEM_HU(ctx->r19, 0X46A8);
    // 0x800222CC: jal         0x8001F310
    // 0x800222D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001F310(rdram, ctx);
        goto after_0;
    // 0x800222D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800222D4: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800222D8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800222DC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800222E0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800222E4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800222E8: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x800222EC: addiu       $s0, $s0, 0x3F94
    ctx->r16 = ADD32(ctx->r16, 0X3F94);
    // 0x800222F0: addu        $a0, $v1, $s0
    ctx->r4 = ADD32(ctx->r3, ctx->r16);
    // 0x800222F4: lhu         $v0, 0x58($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X58);
    // 0x800222F8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800222FC: beq         $v0, $zero, L_80022568
    if (ctx->r2 == 0) {
        // 0x80022300: addu        $s7, $s3, $zero
        ctx->r23 = ADD32(ctx->r19, 0);
            goto L_80022568;
    }
    // 0x80022300: addu        $s7, $s3, $zero
    ctx->r23 = ADD32(ctx->r19, 0);
    // 0x80022304: lhu         $v0, 0x5A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X5A);
    // 0x80022308: xori        $v1, $v0, 0x37
    ctx->r3 = ctx->r2 ^ 0X37;
    // 0x8002230C: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80022310: xori        $v0, $v0, 0x26
    ctx->r2 = ctx->r2 ^ 0X26;
    // 0x80022314: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80022318: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8002231C: beq         $v1, $zero, L_80022568
    if (ctx->r3 == 0) {
        // 0x80022320: sll         $v1, $s4, 16
        ctx->r3 = S32(ctx->r20 << 16);
            goto L_80022568;
    }
    // 0x80022320: sll         $v1, $s4, 16
    ctx->r3 = S32(ctx->r20 << 16);
    // 0x80022324: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x80022328: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8002232C: lh          $a0, 0x14($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X14);
    // 0x80022330: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x80022334: sra         $s6, $v0, 16
    ctx->r22 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022338: slt         $v0, $s6, $v1
    ctx->r2 = SIGNED(ctx->r22) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002233C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80022340: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80022344: slt         $a0, $a0, $v1
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022348: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x8002234C: bnel        $v0, $zero, L_80022354
    if (ctx->r2 != 0) {
        // 0x80022350: addu        $s2, $s2, $s5
        ctx->r18 = ADD32(ctx->r18, ctx->r21);
            goto L_80022354;
    }
    goto skip_0;
    // 0x80022350: addu        $s2, $s2, $s5
    ctx->r18 = ADD32(ctx->r18, ctx->r21);
    skip_0:
L_80022354:
    // 0x80022354: jal         0x8001F310
    // 0x80022358: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8001F310(rdram, ctx);
        goto after_1;
    // 0x80022358: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8002235C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80022360: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80022364: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80022368: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8002236C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022370: addu        $a0, $v1, $s0
    ctx->r4 = ADD32(ctx->r3, ctx->r16);
    // 0x80022374: lhu         $v1, 0x5A($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X5A);
    // 0x80022378: addu        $s0, $s2, $s3
    ctx->r16 = ADD32(ctx->r18, ctx->r19);
    // 0x8002237C: xori        $v0, $v1, 0x37
    ctx->r2 = ctx->r3 ^ 0X37;
    // 0x80022380: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80022384: xori        $v1, $v1, 0x26
    ctx->r3 = ctx->r3 ^ 0X26;
    // 0x80022388: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8002238C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80022390: bne         $v0, $zero, L_800223B4
    if (ctx->r2 != 0) {
        // 0x80022394: addu        $s2, $s0, $zero
        ctx->r18 = ADD32(ctx->r16, 0);
            goto L_800223B4;
    }
    // 0x80022394: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // 0x80022398: lhu         $v0, 0x1C8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1C8);
    // 0x8002239C: bne         $v0, $zero, L_800223B4
    if (ctx->r2 != 0) {
        // 0x800223A0: nop
    
            goto L_800223B4;
    }
    // 0x800223A0: nop

    // 0x800223A4: lhu         $v0, 0x58($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X58);
    // 0x800223A8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800223AC: bne         $v0, $zero, L_800223C4
    if (ctx->r2 != 0) {
        // 0x800223B0: sll         $v1, $fp, 16
        ctx->r3 = S32(ctx->r30 << 16);
            goto L_800223C4;
    }
    // 0x800223B0: sll         $v1, $fp, 16
    ctx->r3 = S32(ctx->r30 << 16);
L_800223B4:
    // 0x800223B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800223B8: sh          $s2, -0x5868($at)
    MEM_H(-0X5868, ctx->r1) = ctx->r18;
    // 0x800223BC: j           L_8002245C
    // 0x800223C0: nop

        goto L_8002245C;
    // 0x800223C0: nop

L_800223C4:
    // 0x800223C4: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x800223C8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800223CC: lh          $a0, 0x14($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X14);
    // 0x800223D0: slt         $v0, $s6, $v1
    ctx->r2 = SIGNED(ctx->r22) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800223D4: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800223D8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800223DC: slt         $a0, $a0, $v1
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800223E0: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x800223E4: beql        $v0, $zero, L_800223F8
    if (ctx->r2 == 0) {
        // 0x800223E8: addu        $s1, $s1, $s3
        ctx->r17 = ADD32(ctx->r17, ctx->r19);
            goto L_800223F8;
    }
    goto skip_1;
    // 0x800223E8: addu        $s1, $s1, $s3
    ctx->r17 = ADD32(ctx->r17, ctx->r19);
    skip_1:
    // 0x800223EC: lhu         $t0, 0x16($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X16);
    // 0x800223F0: addu        $s1, $s1, $t0
    ctx->r17 = ADD32(ctx->r17, ctx->r8);
    // 0x800223F4: addu        $s1, $s1, $s3
    ctx->r17 = ADD32(ctx->r17, ctx->r19);
L_800223F8:
    // 0x800223F8: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x800223FC: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80022400: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80022404: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80022408: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002240C: jal         0x8002220C
    // 0x80022410: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8002220C(rdram, ctx);
        goto after_2;
    // 0x80022410: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80022414: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80022418: sh          $v0, -0x5868($at)
    MEM_H(-0X5868, ctx->r1) = ctx->r2;
    // 0x8002241C: bltzl       $s0, L_80022424
    if (SIGNED(ctx->r16) < 0) {
        // 0x80022420: negu        $s0, $s0
        ctx->r16 = SUB32(0, ctx->r16);
            goto L_80022424;
    }
    goto skip_2;
    // 0x80022420: negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
    skip_2:
L_80022424:
    // 0x80022424: bltzl       $s1, L_8002242C
    if (SIGNED(ctx->r17) < 0) {
        // 0x80022428: negu        $s1, $s1
        ctx->r17 = SUB32(0, ctx->r17);
            goto L_8002242C;
    }
    goto skip_3;
    // 0x80022428: negu        $s1, $s1
    ctx->r17 = SUB32(0, ctx->r17);
    skip_3:
L_8002242C:
    // 0x8002242C: sll         $v1, $s1, 16
    ctx->r3 = S32(ctx->r17 << 16);
    // 0x80022430: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80022434: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x80022438: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002243C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80022440: bltz        $v1, L_80022450
    if (SIGNED(ctx->r3) < 0) {
        // 0x80022444: addu        $s2, $s0, $zero
        ctx->r18 = ADD32(ctx->r16, 0);
            goto L_80022450;
    }
    // 0x80022444: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // 0x80022448: j           L_80022454
    // 0x8002244C: subu        $v0, $s1, $s0
    ctx->r2 = SUB32(ctx->r17, ctx->r16);
        goto L_80022454;
    // 0x8002244C: subu        $v0, $s1, $s0
    ctx->r2 = SUB32(ctx->r17, ctx->r16);
L_80022450:
    // 0x80022450: subu        $v0, $s0, $s1
    ctx->r2 = SUB32(ctx->r16, ctx->r17);
L_80022454:
    // 0x80022454: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80022458: sh          $v0, -0x5870($at)
    MEM_H(-0X5870, ctx->r1) = ctx->r2;
L_8002245C:
    // 0x8002245C: jal         0x8001F310
    // 0x80022460: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001F310(rdram, ctx);
        goto after_3;
    // 0x80022460: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x80022464: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80022468: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002246C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80022470: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80022474: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022478: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8002247C: addiu       $v0, $v0, 0x3F94
    ctx->r2 = ADD32(ctx->r2, 0X3F94);
    // 0x80022480: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x80022484: lhu         $v0, 0x5A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X5A);
    // 0x80022488: xori        $v1, $v0, 0x37
    ctx->r3 = ctx->r2 ^ 0X37;
    // 0x8002248C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80022490: xori        $v0, $v0, 0x26
    ctx->r2 = ctx->r2 ^ 0X26;
    // 0x80022494: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80022498: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8002249C: bne         $v1, $zero, L_800224C0
    if (ctx->r3 != 0) {
        // 0x800224A0: nop
    
            goto L_800224C0;
    }
    // 0x800224A0: nop

    // 0x800224A4: lhu         $v0, 0x1C8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1C8);
    // 0x800224A8: bne         $v0, $zero, L_800224C0
    if (ctx->r2 != 0) {
        // 0x800224AC: nop
    
            goto L_800224C0;
    }
    // 0x800224AC: nop

    // 0x800224B0: lhu         $v0, 0x58($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X58);
    // 0x800224B4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800224B8: bne         $v0, $zero, L_800224D0
    if (ctx->r2 != 0) {
        // 0x800224BC: sll         $v1, $fp, 16
        ctx->r3 = S32(ctx->r30 << 16);
            goto L_800224D0;
    }
    // 0x800224BC: sll         $v1, $fp, 16
    ctx->r3 = S32(ctx->r30 << 16);
L_800224C0:
    // 0x800224C0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800224C4: sh          $s2, -0x5866($at)
    MEM_H(-0X5866, ctx->r1) = ctx->r18;
    // 0x800224C8: j           L_80022568
    // 0x800224CC: nop

        goto L_80022568;
    // 0x800224CC: nop

L_800224D0:
    // 0x800224D0: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x800224D4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800224D8: lh          $a0, 0x14($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X14);
    // 0x800224DC: sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23 << 16);
    // 0x800224E0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800224E4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800224E8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800224EC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800224F0: slt         $a0, $a0, $v1
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800224F4: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x800224F8: beql        $v0, $zero, L_8002250C
    if (ctx->r2 == 0) {
        // 0x800224FC: addu        $s1, $s1, $s7
        ctx->r17 = ADD32(ctx->r17, ctx->r23);
            goto L_8002250C;
    }
    goto skip_4;
    // 0x800224FC: addu        $s1, $s1, $s7
    ctx->r17 = ADD32(ctx->r17, ctx->r23);
    skip_4:
    // 0x80022500: lhu         $t0, 0x16($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X16);
    // 0x80022504: addu        $s1, $s1, $t0
    ctx->r17 = ADD32(ctx->r17, ctx->r8);
    // 0x80022508: addu        $s1, $s1, $s7
    ctx->r17 = ADD32(ctx->r17, ctx->r23);
L_8002250C:
    // 0x8002250C: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80022510: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80022514: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80022518: sll         $s0, $s2, 16
    ctx->r16 = S32(ctx->r18 << 16);
    // 0x8002251C: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80022520: jal         0x8002220C
    // 0x80022524: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8002220C(rdram, ctx);
        goto after_4;
    // 0x80022524: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80022528: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8002252C: sh          $v0, -0x5866($at)
    MEM_H(-0X5866, ctx->r1) = ctx->r2;
    // 0x80022530: bltzl       $s0, L_80022538
    if (SIGNED(ctx->r16) < 0) {
        // 0x80022534: negu        $s0, $s0
        ctx->r16 = SUB32(0, ctx->r16);
            goto L_80022538;
    }
    goto skip_5;
    // 0x80022534: negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
    skip_5:
L_80022538:
    // 0x80022538: bltzl       $s1, L_80022540
    if (SIGNED(ctx->r17) < 0) {
        // 0x8002253C: negu        $s1, $s1
        ctx->r17 = SUB32(0, ctx->r17);
            goto L_80022540;
    }
    goto skip_6;
    // 0x8002253C: negu        $s1, $s1
    ctx->r17 = SUB32(0, ctx->r17);
    skip_6:
L_80022540:
    // 0x80022540: sll         $v1, $s1, 16
    ctx->r3 = S32(ctx->r17 << 16);
    // 0x80022544: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80022548: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x8002254C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022550: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80022554: bgez        $v1, L_80022560
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80022558: subu        $v0, $s1, $s0
        ctx->r2 = SUB32(ctx->r17, ctx->r16);
            goto L_80022560;
    }
    // 0x80022558: subu        $v0, $s1, $s0
    ctx->r2 = SUB32(ctx->r17, ctx->r16);
    // 0x8002255C: subu        $v0, $s0, $s1
    ctx->r2 = SUB32(ctx->r16, ctx->r17);
L_80022560:
    // 0x80022560: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80022564: sh          $v0, -0x586E($at)
    MEM_H(-0X586E, ctx->r1) = ctx->r2;
L_80022568:
    // 0x80022568: jal         0x8001F310
    // 0x8002256C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8001F310(rdram, ctx);
        goto after_5;
    // 0x8002256C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x80022570: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80022574: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80022578: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8002257C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80022580: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022584: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80022588: addiu       $s0, $s0, 0x3F94
    ctx->r16 = ADD32(ctx->r16, 0X3F94);
    // 0x8002258C: addu        $a0, $v1, $s0
    ctx->r4 = ADD32(ctx->r3, ctx->r16);
    // 0x80022590: lhu         $v0, 0x58($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X58);
    // 0x80022594: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80022598: beq         $v0, $zero, L_8002271C
    if (ctx->r2 == 0) {
        // 0x8002259C: nop
    
            goto L_8002271C;
    }
    // 0x8002259C: nop

    // 0x800225A0: lhu         $v0, 0x5A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X5A);
    // 0x800225A4: xori        $v1, $v0, 0x37
    ctx->r3 = ctx->r2 ^ 0X37;
    // 0x800225A8: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x800225AC: xori        $v0, $v0, 0x26
    ctx->r2 = ctx->r2 ^ 0X26;
    // 0x800225B0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800225B4: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800225B8: beq         $v1, $zero, L_8002271C
    if (ctx->r3 == 0) {
        // 0x800225BC: nop
    
            goto L_8002271C;
    }
    // 0x800225BC: nop

    // 0x800225C0: lhu         $v0, 0x1C8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1C8);
    // 0x800225C4: bne         $v0, $zero, L_8002271C
    if (ctx->r2 != 0) {
        // 0x800225C8: sll         $v1, $s4, 16
        ctx->r3 = S32(ctx->r20 << 16);
            goto L_8002271C;
    }
    // 0x800225C8: sll         $v1, $s4, 16
    ctx->r3 = S32(ctx->r20 << 16);
    // 0x800225CC: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x800225D0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800225D4: lh          $a0, 0x14($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X14);
    // 0x800225D8: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x800225DC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800225E0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800225E4: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800225E8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800225EC: slt         $a0, $a0, $v1
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800225F0: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x800225F4: bnel        $v0, $zero, L_800225FC
    if (ctx->r2 != 0) {
        // 0x800225F8: addu        $s2, $s2, $s5
        ctx->r18 = ADD32(ctx->r18, ctx->r21);
            goto L_800225FC;
    }
    goto skip_7;
    // 0x800225F8: addu        $s2, $s2, $s5
    ctx->r18 = ADD32(ctx->r18, ctx->r21);
    skip_7:
L_800225FC:
    // 0x800225FC: jal         0x8001F310
    // 0x80022600: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001F310(rdram, ctx);
        goto after_6;
    // 0x80022600: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x80022604: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80022608: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002260C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80022610: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80022614: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022618: addu        $a0, $v1, $s0
    ctx->r4 = ADD32(ctx->r3, ctx->r16);
    // 0x8002261C: lhu         $v1, 0x5A($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X5A);
    // 0x80022620: addu        $s0, $s2, $s3
    ctx->r16 = ADD32(ctx->r18, ctx->r19);
    // 0x80022624: xori        $v0, $v1, 0x37
    ctx->r2 = ctx->r3 ^ 0X37;
    // 0x80022628: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8002262C: xori        $v1, $v1, 0x26
    ctx->r3 = ctx->r3 ^ 0X26;
    // 0x80022630: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80022634: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80022638: bne         $v0, $zero, L_8002265C
    if (ctx->r2 != 0) {
        // 0x8002263C: addu        $s2, $s0, $zero
        ctx->r18 = ADD32(ctx->r16, 0);
            goto L_8002265C;
    }
    // 0x8002263C: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // 0x80022640: lhu         $v0, 0x1C8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1C8);
    // 0x80022644: bne         $v0, $zero, L_8002265C
    if (ctx->r2 != 0) {
        // 0x80022648: nop
    
            goto L_8002265C;
    }
    // 0x80022648: nop

    // 0x8002264C: lhu         $v0, 0x58($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X58);
    // 0x80022650: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80022654: bne         $v0, $zero, L_8002266C
    if (ctx->r2 != 0) {
        // 0x80022658: sll         $v1, $fp, 16
        ctx->r3 = S32(ctx->r30 << 16);
            goto L_8002266C;
    }
    // 0x80022658: sll         $v1, $fp, 16
    ctx->r3 = S32(ctx->r30 << 16);
L_8002265C:
    // 0x8002265C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80022660: sh          $s2, -0x5864($at)
    MEM_H(-0X5864, ctx->r1) = ctx->r18;
    // 0x80022664: j           L_800227C0
    // 0x80022668: nop

        goto L_800227C0;
    // 0x80022668: nop

L_8002266C:
    // 0x8002266C: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x80022670: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80022674: lh          $a0, 0x14($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X14);
    // 0x80022678: sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23 << 16);
    // 0x8002267C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022680: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022684: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80022688: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8002268C: slt         $a0, $a0, $v1
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022690: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x80022694: beql        $v0, $zero, L_800226A8
    if (ctx->r2 == 0) {
        // 0x80022698: addu        $s1, $s1, $s7
        ctx->r17 = ADD32(ctx->r17, ctx->r23);
            goto L_800226A8;
    }
    goto skip_8;
    // 0x80022698: addu        $s1, $s1, $s7
    ctx->r17 = ADD32(ctx->r17, ctx->r23);
    skip_8:
    // 0x8002269C: lhu         $t0, 0x16($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X16);
    // 0x800226A0: addu        $s1, $s1, $t0
    ctx->r17 = ADD32(ctx->r17, ctx->r8);
    // 0x800226A4: addu        $s1, $s1, $s7
    ctx->r17 = ADD32(ctx->r17, ctx->r23);
L_800226A8:
    // 0x800226A8: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x800226AC: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800226B0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800226B4: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x800226B8: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800226BC: jal         0x8002220C
    // 0x800226C0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8002220C(rdram, ctx);
        goto after_7;
    // 0x800226C0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_7:
    // 0x800226C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800226C8: sh          $v0, -0x5864($at)
    MEM_H(-0X5864, ctx->r1) = ctx->r2;
    // 0x800226CC: bltzl       $s0, L_800226D4
    if (SIGNED(ctx->r16) < 0) {
        // 0x800226D0: negu        $s0, $s0
        ctx->r16 = SUB32(0, ctx->r16);
            goto L_800226D4;
    }
    goto skip_9;
    // 0x800226D0: negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
    skip_9:
L_800226D4:
    // 0x800226D4: bltzl       $s1, L_800226DC
    if (SIGNED(ctx->r17) < 0) {
        // 0x800226D8: negu        $s1, $s1
        ctx->r17 = SUB32(0, ctx->r17);
            goto L_800226DC;
    }
    goto skip_10;
    // 0x800226D8: negu        $s1, $s1
    ctx->r17 = SUB32(0, ctx->r17);
    skip_10:
L_800226DC:
    // 0x800226DC: sll         $v1, $s1, 16
    ctx->r3 = S32(ctx->r17 << 16);
    // 0x800226E0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800226E4: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x800226E8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800226EC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800226F0: bltz        $v1, L_80022708
    if (SIGNED(ctx->r3) < 0) {
        // 0x800226F4: subu        $v0, $s1, $s0
        ctx->r2 = SUB32(ctx->r17, ctx->r16);
            goto L_80022708;
    }
    // 0x800226F4: subu        $v0, $s1, $s0
    ctx->r2 = SUB32(ctx->r17, ctx->r16);
    // 0x800226F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800226FC: sh          $v0, -0x586C($at)
    MEM_H(-0X586C, ctx->r1) = ctx->r2;
    // 0x80022700: j           L_800227C0
    // 0x80022704: nop

        goto L_800227C0;
    // 0x80022704: nop

L_80022708:
    // 0x80022708: subu        $v0, $s0, $s1
    ctx->r2 = SUB32(ctx->r16, ctx->r17);
    // 0x8002270C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80022710: sh          $v0, -0x586C($at)
    MEM_H(-0X586C, ctx->r1) = ctx->r2;
    // 0x80022714: j           L_800227C0
    // 0x80022718: nop

        goto L_800227C0;
    // 0x80022718: nop

L_8002271C:
    // 0x8002271C: jal         0x8001F310
    // 0x80022720: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001F310(rdram, ctx);
        goto after_8;
    // 0x80022720: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_8:
    // 0x80022724: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80022728: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002272C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80022730: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80022734: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022738: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8002273C: addiu       $v0, $v0, 0x3F94
    ctx->r2 = ADD32(ctx->r2, 0X3F94);
    // 0x80022740: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x80022744: lhu         $v0, 0x58($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X58);
    // 0x80022748: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8002274C: beq         $v0, $zero, L_800227C0
    if (ctx->r2 == 0) {
        // 0x80022750: nop
    
            goto L_800227C0;
    }
    // 0x80022750: nop

    // 0x80022754: lhu         $v0, 0x5A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X5A);
    // 0x80022758: xori        $v1, $v0, 0x37
    ctx->r3 = ctx->r2 ^ 0X37;
    // 0x8002275C: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80022760: xori        $v0, $v0, 0x26
    ctx->r2 = ctx->r2 ^ 0X26;
    // 0x80022764: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80022768: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8002276C: beq         $v1, $zero, L_800227C0
    if (ctx->r3 == 0) {
        // 0x80022770: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800227C0;
    }
    // 0x80022770: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80022774: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80022778: lhu         $v1, -0x6DF0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6DF0);
    // 0x8002277C: bne         $v1, $v0, L_800227C0
    if (ctx->r3 != ctx->r2) {
        // 0x80022780: sll         $v1, $s4, 16
        ctx->r3 = S32(ctx->r20 << 16);
            goto L_800227C0;
    }
    // 0x80022780: sll         $v1, $s4, 16
    ctx->r3 = S32(ctx->r20 << 16);
    // 0x80022784: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x80022788: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8002278C: lh          $a0, 0x14($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X14);
    // 0x80022790: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x80022794: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022798: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002279C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800227A0: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800227A4: slt         $a0, $a0, $v1
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800227A8: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x800227AC: bnel        $v0, $zero, L_800227B4
    if (ctx->r2 != 0) {
        // 0x800227B0: addu        $s2, $s2, $s5
        ctx->r18 = ADD32(ctx->r18, ctx->r21);
            goto L_800227B4;
    }
    goto skip_11;
    // 0x800227B0: addu        $s2, $s2, $s5
    ctx->r18 = ADD32(ctx->r18, ctx->r21);
    skip_11:
L_800227B4:
    // 0x800227B4: addu        $s2, $s2, $s3
    ctx->r18 = ADD32(ctx->r18, ctx->r19);
    // 0x800227B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800227BC: sh          $s2, -0x5862($at)
    MEM_H(-0X5862, ctx->r1) = ctx->r18;
L_800227C0:
    // 0x800227C0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800227C4: addiu       $v1, $v1, 0x31A0
    ctx->r3 = ADD32(ctx->r3, 0X31A0);
    // 0x800227C8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800227CC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800227D0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800227D4: addiu       $a1, $a1, -0x5870
    ctx->r5 = ADD32(ctx->r5, -0X5870);
    // 0x800227D8: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x800227DC: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x800227E0: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
L_800227E4:
    // 0x800227E4: lhu         $s4, 0x0($a1)
    ctx->r20 = MEM_HU(ctx->r5, 0X0);
    // 0x800227E8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800227EC: lhu         $s3, 0x0($a2)
    ctx->r19 = MEM_HU(ctx->r6, 0X0);
    // 0x800227F0: sll         $v1, $s5, 16
    ctx->r3 = S32(ctx->r21 << 16);
    // 0x800227F4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800227F8: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x800227FC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022800: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022804: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80022808: sltu        $v1, $zero, $s3
    ctx->r3 = 0 < ctx->r19 ? 1 : 0;
    // 0x8002280C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80022810: beq         $v0, $zero, L_80022844
    if (ctx->r2 == 0) {
        // 0x80022814: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_80022844;
    }
    // 0x80022814: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80022818: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8002281C: addiu       $v1, $a0, -0x4
    ctx->r3 = ADD32(ctx->r4, -0X4);
    // 0x80022820: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80022824: bltz        $v0, L_80022834
    if (SIGNED(ctx->r2) < 0) {
        // 0x80022828: addu        $s5, $s4, $zero
        ctx->r21 = ADD32(ctx->r20, 0);
            goto L_80022834;
    }
    // 0x80022828: addu        $s5, $s4, $zero
    ctx->r21 = ADD32(ctx->r20, 0);
    // 0x8002282C: j           L_8002283C
    // 0x80022830: addiu       $v0, $a0, -0x3
    ctx->r2 = ADD32(ctx->r4, -0X3);
        goto L_8002283C;
    // 0x80022830: addiu       $v0, $a0, -0x3
    ctx->r2 = ADD32(ctx->r4, -0X3);
L_80022834:
    // 0x80022834: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80022838: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8002283C:
    // 0x8002283C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80022840: sh          $v0, -0x6730($at)
    MEM_H(-0X6730, ctx->r1) = ctx->r2;
L_80022844:
    // 0x80022844: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80022848: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002284C: bne         $v0, $zero, L_800227E4
    if (ctx->r2 != 0) {
        // 0x80022850: sw          $v0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r2;
            goto L_800227E4;
    }
    // 0x80022850: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80022854: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80022858: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8002285C: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80022860: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80022864: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80022868: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8002286C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80022870: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80022874: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80022878: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8002287C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80022880: jr          $ra
    // 0x80022884: nop

    return;
    // 0x80022884: nop

;}
RECOMP_FUNC void func_80022888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022888: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x8002288C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80022890: addiu       $a2, $a2, 0x19E
    ctx->r6 = ADD32(ctx->r6, 0X19E);
    // 0x80022894: lhu         $a3, 0x0($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X0);
    // 0x80022898: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002289C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800228A0: slt         $a0, $a3, $a0
    ctx->r4 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800228A4: beq         $a0, $zero, L_800228D8
    if (ctx->r4 == 0) {
        // 0x800228A8: nop
    
            goto L_800228D8;
    }
    // 0x800228A8: nop

    // 0x800228AC: lhu         $v0, -0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, -0X2);
    // 0x800228B0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800228B4: beq         $v0, $zero, L_800228D0
    if (ctx->r2 == 0) {
        // 0x800228B8: sll         $a0, $a3, 16
        ctx->r4 = S32(ctx->r7 << 16);
            goto L_800228D0;
    }
    // 0x800228B8: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x800228BC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800228C0: addiu       $v0, $v0, 0x3A0
    ctx->r2 = ADD32(ctx->r2, 0X3A0);
    // 0x800228C4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800228C8: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800228CC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_800228D0:
    // 0x800228D0: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // 0x800228D4: sh          $a1, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r5;
L_800228D8:
    // 0x800228D8: jr          $ra
    // 0x800228DC: nop

    return;
    // 0x800228DC: nop

;}
RECOMP_FUNC void func_800228E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800228E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800228E4: lhu         $v0, 0x19C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X19C);
    // 0x800228E8: beq         $v0, $zero, L_80022950
    if (ctx->r2 == 0) {
        // 0x800228EC: andi        $v0, $v0, 0x1
        ctx->r2 = ctx->r2 & 0X1;
            goto L_80022950;
    }
    // 0x800228EC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800228F0: beq         $v0, $zero, L_80022918
    if (ctx->r2 == 0) {
        // 0x800228F4: nop
    
            goto L_80022918;
    }
    // 0x800228F4: nop

    // 0x800228F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800228FC: addiu       $v0, $v0, 0x3A0
    ctx->r2 = ADD32(ctx->r2, 0X3A0);
    // 0x80022900: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80022904: lhu         $v1, 0x19E($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X19E);
    // 0x80022908: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8002290C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80022910: j           L_80022934
    // 0x80022914: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
        goto L_80022934;
    // 0x80022914: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
L_80022918:
    // 0x80022918: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002291C: addiu       $v0, $v0, 0x3A0
    ctx->r2 = ADD32(ctx->r2, 0X3A0);
    // 0x80022920: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80022924: lhu         $v1, 0x19E($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X19E);
    // 0x80022928: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8002292C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80022930: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_80022934:
    // 0x80022934: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80022938: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002293C: addiu       $v1, $v1, 0x19C
    ctx->r3 = ADD32(ctx->r3, 0X19C);
    // 0x80022940: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80022944: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80022948: j           L_80022958
    // 0x8002294C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
        goto L_80022958;
    // 0x8002294C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_80022950:
    // 0x80022950: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022954: sh          $zero, 0x19E($at)
    MEM_H(0X19E, ctx->r1) = 0;
L_80022958:
    // 0x80022958: jr          $ra
    // 0x8002295C: nop

    return;
    // 0x8002295C: nop

;}
RECOMP_FUNC void func_80022960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022960: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80022964: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80022968: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8002296C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80022970: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80022974: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
    // 0x80022978: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8002297C: beq         $v0, $zero, L_80022C28
    if (ctx->r2 == 0) {
        // 0x80022980: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_80022C28;
    }
    // 0x80022980: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80022984: lhu         $v0, 0x46($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X46);
    // 0x80022988: bne         $v0, $zero, L_80022C2C
    if (ctx->r2 != 0) {
        // 0x8002298C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80022C2C;
    }
    // 0x8002298C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80022990: lhu         $a0, 0x5A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X5A);
    // 0x80022994: xori        $v1, $a0, 0x37
    ctx->r3 = ctx->r4 ^ 0X37;
    // 0x80022998: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8002299C: xori        $v0, $a0, 0x26
    ctx->r2 = ctx->r4 ^ 0X26;
    // 0x800229A0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800229A4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800229A8: beq         $v1, $zero, L_80022A68
    if (ctx->r3 == 0) {
        // 0x800229AC: addiu       $v0, $zero, 0x60
        ctx->r2 = ADD32(0, 0X60);
            goto L_80022A68;
    }
    // 0x800229AC: addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // 0x800229B0: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x800229B4: bne         $v0, $zero, L_80022B94
    if (ctx->r2 != 0) {
        // 0x800229B8: nop
    
            goto L_80022B94;
    }
    // 0x800229B8: nop

    // 0x800229BC: lhu         $v0, 0x5E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X5E);
    // 0x800229C0: beq         $v0, $zero, L_80022C2C
    if (ctx->r2 == 0) {
        // 0x800229C4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80022C2C;
    }
    // 0x800229C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800229C8: lhu         $a1, 0x0($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X0);
    // 0x800229CC: jal         0x80024FB0
    // 0x800229D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80024FB0(rdram, ctx);
        goto after_0;
    // 0x800229D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800229D4: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
    // 0x800229D8: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800229DC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800229E0: lhu         $a1, 0x6AF0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6AF0);
    // 0x800229E4: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x800229E8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800229EC: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x800229F0: sh          $v0, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r2;
    // 0x800229F4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800229F8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800229FC: sw          $zero, -0x1034($at)
    MEM_W(-0X1034, ctx->r1) = 0;
    // 0x80022A00: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80022A04: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80022A08: sh          $a1, 0x6AF0($at)
    MEM_H(0X6AF0, ctx->r1) = ctx->r5;
    // 0x80022A0C: jal         0x8004C718
    // 0x80022A10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004C718(rdram, ctx);
        goto after_1;
    // 0x80022A10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80022A14: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80022A18: lhu         $v1, 0x6AF0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X6AF0);
    // 0x80022A1C: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    // 0x80022A20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80022A24: sh          $v0, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r2;
    // 0x80022A28: andi        $v1, $v1, 0xFFFE
    ctx->r3 = ctx->r3 & 0XFFFE;
    // 0x80022A2C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80022A30: sh          $v1, 0x6AF0($at)
    MEM_H(0X6AF0, ctx->r1) = ctx->r3;
    // 0x80022A34: beq         $a0, $zero, L_80022A48
    if (ctx->r4 == 0) {
        // 0x80022A38: nop
    
            goto L_80022A48;
    }
    // 0x80022A38: nop

    // 0x80022A3C: jal         0x80024764
    // 0x80022A40: nop

    func_80024764(rdram, ctx);
        goto after_2;
    // 0x80022A40: nop

    after_2:
    // 0x80022A44: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
L_80022A48:
    // 0x80022A48: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80022A4C: addiu       $a0, $a0, 0x790
    ctx->r4 = ADD32(ctx->r4, 0X790);
    // 0x80022A50: jal         0x800246DC
    // 0x80022A54: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_800246DC(rdram, ctx);
        goto after_3;
    // 0x80022A54: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_3:
    // 0x80022A58: jal         0x80028FF4
    // 0x80022A5C: sh          $zero, 0x178($s0)
    MEM_H(0X178, ctx->r16) = 0;
    func_80028FF4(rdram, ctx);
        goto after_4;
    // 0x80022A5C: sh          $zero, 0x178($s0)
    MEM_H(0X178, ctx->r16) = 0;
    after_4:
    // 0x80022A60: j           L_80022C2C
    // 0x80022A64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80022C2C;
    // 0x80022A64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80022A68:
    // 0x80022A68: bne         $a0, $v0, L_80022A78
    if (ctx->r4 != ctx->r2) {
        // 0x80022A6C: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_80022A78;
    }
    // 0x80022A6C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80022A70: j           L_80022C28
    // 0x80022A74: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
        goto L_80022C28;
    // 0x80022A74: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
L_80022A78:
    // 0x80022A78: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80022A7C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022A80: bne         $v0, $zero, L_80022C2C
    if (ctx->r2 != 0) {
        // 0x80022A84: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80022C2C;
    }
    // 0x80022A84: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80022A88: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x80022A8C: bne         $v0, $zero, L_80022B94
    if (ctx->r2 != 0) {
        // 0x80022A90: sw          $zero, 0x8($s0)
        MEM_W(0X8, ctx->r16) = 0;
            goto L_80022B94;
    }
    // 0x80022A90: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80022A94: lhu         $v0, 0x18E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18E);
    // 0x80022A98: bne         $v0, $zero, L_80022B8C
    if (ctx->r2 != 0) {
        // 0x80022A9C: lui         $v0, 0x5
        ctx->r2 = S32(0X5 << 16);
            goto L_80022B8C;
    }
    // 0x80022A9C: lui         $v0, 0x5
    ctx->r2 = S32(0X5 << 16);
    // 0x80022AA0: lhu         $v0, 0x1B0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B0);
    // 0x80022AA4: bne         $v0, $zero, L_80022C24
    if (ctx->r2 != 0) {
        // 0x80022AA8: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80022C24;
    }
    // 0x80022AA8: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80022AAC: lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18);
    // 0x80022AB0: addiu       $v0, $v0, -0xE1
    ctx->r2 = ADD32(ctx->r2, -0XE1);
    // 0x80022AB4: sltiu       $v0, $v0, 0x18
    ctx->r2 = ctx->r2 < 0X18 ? 1 : 0;
    // 0x80022AB8: bne         $v0, $zero, L_80022AD4
    if (ctx->r2 != 0) {
        // 0x80022ABC: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80022AD4;
    }
    // 0x80022ABC: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80022AC0: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x80022AC4: jal         0x8004C79C
    // 0x80022AC8: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    func_8004C79C(rdram, ctx);
        goto after_5;
    // 0x80022AC8: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    after_5:
    // 0x80022ACC: j           L_80022C2C
    // 0x80022AD0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80022C2C;
    // 0x80022AD0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80022AD4:
    // 0x80022AD4: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x80022AD8: addiu       $v0, $v1, -0x34
    ctx->r2 = ADD32(ctx->r3, -0X34);
    // 0x80022ADC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80022AE0: bne         $v0, $zero, L_80022AFC
    if (ctx->r2 != 0) {
        // 0x80022AE4: addiu       $v0, $zero, 0x26
        ctx->r2 = ADD32(0, 0X26);
            goto L_80022AFC;
    }
    // 0x80022AE4: addiu       $v0, $zero, 0x26
    ctx->r2 = ADD32(0, 0X26);
    // 0x80022AE8: addiu       $v0, $v1, -0x9
    ctx->r2 = ADD32(ctx->r3, -0X9);
    // 0x80022AEC: sltiu       $v0, $v0, 0x6
    ctx->r2 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x80022AF0: bne         $v0, $zero, L_80022C2C
    if (ctx->r2 != 0) {
        // 0x80022AF4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80022C2C;
    }
    // 0x80022AF4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80022AF8: addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
L_80022AFC:
    // 0x80022AFC: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x80022B00: sh          $zero, 0xDC($s0)
    MEM_H(0XDC, ctx->r16) = 0;
    // 0x80022B04: sh          $zero, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = 0;
    // 0x80022B08: sh          $zero, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = 0;
    // 0x80022B0C: jal         0x8004C79C
    // 0x80022B10: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    func_8004C79C(rdram, ctx);
        goto after_6;
    // 0x80022B10: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    after_6:
    // 0x80022B14: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80022B18: lw          $v0, 0x3A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A0);
    // 0x80022B1C: beq         $v0, $zero, L_80022C28
    if (ctx->r2 == 0) {
        // 0x80022B20: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_80022C28;
    }
    // 0x80022B20: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80022B24: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80022B28: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x80022B2C: addiu       $a3, $a3, 0x3F94
    ctx->r7 = ADD32(ctx->r7, 0X3F94);
    // 0x80022B30: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80022B34: andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
L_80022B38:
    // 0x80022B38: beq         $a0, $v1, L_80022B70
    if (ctx->r4 == ctx->r3) {
        // 0x80022B3C: sll         $v0, $v1, 4
        ctx->r2 = S32(ctx->r3 << 4);
            goto L_80022B70;
    }
    // 0x80022B3C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80022B40: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022B44: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80022B48: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80022B4C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80022B50: addu        $v1, $v0, $a3
    ctx->r3 = ADD32(ctx->r2, ctx->r7);
    // 0x80022B54: lhu         $v0, 0x58($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X58);
    // 0x80022B58: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80022B5C: beq         $v0, $zero, L_80022B74
    if (ctx->r2 == 0) {
        // 0x80022B60: addiu       $v0, $a1, -0x1
        ctx->r2 = ADD32(ctx->r5, -0X1);
            goto L_80022B74;
    }
    // 0x80022B60: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x80022B64: lhu         $v0, 0x1B0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1B0);
    // 0x80022B68: bnel        $v0, $zero, L_80022B70
    if (ctx->r2 != 0) {
        // 0x80022B6C: sh          $a2, 0x5A($v1)
        MEM_H(0X5A, ctx->r3) = ctx->r6;
            goto L_80022B70;
    }
    goto skip_0;
    // 0x80022B6C: sh          $a2, 0x5A($v1)
    MEM_H(0X5A, ctx->r3) = ctx->r6;
    skip_0:
L_80022B70:
    // 0x80022B70: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
L_80022B74:
    // 0x80022B74: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80022B78: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80022B7C: bne         $v0, $zero, L_80022B38
    if (ctx->r2 != 0) {
        // 0x80022B80: andi        $v1, $a1, 0xFFFF
        ctx->r3 = ctx->r5 & 0XFFFF;
            goto L_80022B38;
    }
    // 0x80022B80: andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // 0x80022B84: j           L_80022C2C
    // 0x80022B88: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80022C2C;
    // 0x80022B88: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80022B8C:
    // 0x80022B8C: j           L_80022C28
    // 0x80022B90: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
        goto L_80022C28;
    // 0x80022B90: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_80022B94:
    // 0x80022B94: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x80022B98: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022B9C: lui         $v0, 0x44
    ctx->r2 = S32(0X44 << 16);
    // 0x80022BA0: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80022BA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80022BA8: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // 0x80022BAC: sw          $zero, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = 0;
    // 0x80022BB0: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x80022BB4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80022BB8: jal         0x8004C79C
    // 0x80022BBC: sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    func_8004C79C(rdram, ctx);
        goto after_7;
    // 0x80022BBC: sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    after_7:
    // 0x80022BC0: jal         0x8004C79C
    // 0x80022BC4: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    func_8004C79C(rdram, ctx);
        goto after_8;
    // 0x80022BC4: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    after_8:
    // 0x80022BC8: lhu         $a0, 0x5A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X5A);
    // 0x80022BCC: addiu       $v0, $zero, 0x26
    ctx->r2 = ADD32(0, 0X26);
    // 0x80022BD0: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80022BD4: bne         $v1, $v0, L_80022BE4
    if (ctx->r3 != ctx->r2) {
        // 0x80022BD8: addiu       $v0, $zero, 0x37
        ctx->r2 = ADD32(0, 0X37);
            goto L_80022BE4;
    }
    // 0x80022BD8: addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
    // 0x80022BDC: j           L_80022C24
    // 0x80022BE0: addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
        goto L_80022C24;
    // 0x80022BE0: addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
L_80022BE4:
    // 0x80022BE4: beq         $v1, $v0, L_80022C24
    if (ctx->r3 == ctx->r2) {
        // 0x80022BE8: addiu       $v0, $zero, 0xE
        ctx->r2 = ADD32(0, 0XE);
            goto L_80022C24;
    }
    // 0x80022BE8: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x80022BEC: lhu         $v0, 0x1B0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B0);
    // 0x80022BF0: bne         $v0, $zero, L_80022C24
    if (ctx->r2 != 0) {
        // 0x80022BF4: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80022C24;
    }
    // 0x80022BF4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80022BF8: lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18);
    // 0x80022BFC: addiu       $v0, $v0, -0xE1
    ctx->r2 = ADD32(ctx->r2, -0XE1);
    // 0x80022C00: sltiu       $v0, $v0, 0x18
    ctx->r2 = ctx->r2 < 0X18 ? 1 : 0;
    // 0x80022C04: bne         $v0, $zero, L_80022C14
    if (ctx->r2 != 0) {
        // 0x80022C08: addiu       $v0, $a0, -0x34
        ctx->r2 = ADD32(ctx->r4, -0X34);
            goto L_80022C14;
    }
    // 0x80022C08: addiu       $v0, $a0, -0x34
    ctx->r2 = ADD32(ctx->r4, -0X34);
    // 0x80022C0C: j           L_80022C24
    // 0x80022C10: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_80022C24;
    // 0x80022C10: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80022C14:
    // 0x80022C14: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80022C18: bne         $v0, $zero, L_80022C2C
    if (ctx->r2 != 0) {
        // 0x80022C1C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80022C2C;
    }
    // 0x80022C1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80022C20: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80022C24:
    // 0x80022C24: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
L_80022C28:
    // 0x80022C28: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80022C2C:
    // 0x80022C2C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80022C30: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80022C34: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80022C38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80022C3C: jr          $ra
    // 0x80022C40: nop

    return;
    // 0x80022C40: nop

;}
RECOMP_FUNC void func_80022C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022C44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022C48: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80022C4C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80022C50: lw          $a2, 0x8($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X8);
    // 0x80022C54: lw          $v0, 0xF0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XF0);
    // 0x80022C58: bne         $v0, $zero, L_80022C6C
    if (ctx->r2 != 0) {
        // 0x80022C5C: addu        $a0, $a2, $zero
        ctx->r4 = ADD32(ctx->r6, 0);
            goto L_80022C6C;
    }
    // 0x80022C5C: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x80022C60: lhu         $v0, 0x64($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X64);
    // 0x80022C64: beq         $v0, $zero, L_80022C9C
    if (ctx->r2 == 0) {
        // 0x80022C68: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80022C9C;
    }
    // 0x80022C68: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80022C6C:
    // 0x80022C6C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80022C70: bltz        $a2, L_80022C90
    if (SIGNED(ctx->r6) < 0) {
        // 0x80022C74: lui         $v0, 0x44
        ctx->r2 = S32(0X44 << 16);
            goto L_80022C90;
    }
    // 0x80022C74: lui         $v0, 0x44
    ctx->r2 = S32(0X44 << 16);
    // 0x80022C78: slt         $v0, $v0, $a2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80022C7C: bnel        $v0, $zero, L_80022C84
    if (ctx->r2 != 0) {
        // 0x80022C80: lui         $a2, 0x44
        ctx->r6 = S32(0X44 << 16);
            goto L_80022C84;
    }
    goto skip_0;
    // 0x80022C80: lui         $a2, 0x44
    ctx->r6 = S32(0X44 << 16);
    skip_0:
L_80022C84:
    // 0x80022C84: sw          $zero, 0xF0($a1)
    MEM_W(0XF0, ctx->r5) = 0;
    // 0x80022C88: j           L_80022C9C
    // 0x80022C8C: sw          $a2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r6;
        goto L_80022C9C;
    // 0x80022C8C: sw          $a2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r6;
L_80022C90:
    // 0x80022C90: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80022C94: sw          $zero, 0xF0($a1)
    MEM_W(0XF0, ctx->r5) = 0;
    // 0x80022C98: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
L_80022C9C:
    // 0x80022C9C: jal         0x80025ABC
    // 0x80022CA0: nop

    func_80025ABC(rdram, ctx);
        goto after_0;
    // 0x80022CA0: nop

    after_0:
    // 0x80022CA4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80022CA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022CAC: jr          $ra
    // 0x80022CB0: nop

    return;
    // 0x80022CB0: nop

;}
RECOMP_FUNC void func_80022CB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022CB4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80022CB8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80022CBC: addiu       $v0, $v0, 0x31AC
    ctx->r2 = ADD32(ctx->r2, 0X31AC);
    // 0x80022CC0: addiu       $a2, $v0, -0x4
    ctx->r6 = ADD32(ctx->r2, -0X4);
    // 0x80022CC4: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80022CC8: addiu       $t1, $t1, 0x3F94
    ctx->r9 = ADD32(ctx->r9, 0X3F94);
    // 0x80022CCC: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80022CD0: addiu       $t0, $zero, 0x1F
    ctx->r8 = ADD32(0, 0X1F);
    // 0x80022CD4: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80022CD8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80022CDC: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80022CE0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80022CE4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80022CE8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80022CEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80022CF0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80022CF4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80022CF8: sw          $zero, 0x31B0($at)
    MEM_W(0X31B0, ctx->r1) = 0;
    // 0x80022CFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80022D00: sw          $zero, 0x31B4($at)
    MEM_W(0X31B4, ctx->r1) = 0;
    // 0x80022D04: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80022D08: sw          $zero, 0x31BC($at)
    MEM_W(0X31BC, ctx->r1) = 0;
    // 0x80022D0C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80022D10: sw          $zero, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = 0;
    // 0x80022D14: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80022D18: sw          $v0, 0x31A8($at)
    MEM_W(0X31A8, ctx->r1) = ctx->r2;
L_80022D1C:
    // 0x80022D1C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80022D20: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80022D24: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80022D28: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80022D2C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80022D30: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022D34: addu        $a0, $v1, $t1
    ctx->r4 = ADD32(ctx->r3, ctx->r9);
    // 0x80022D38: lhu         $v0, 0x58($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X58);
    // 0x80022D3C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80022D40: beq         $v0, $zero, L_80022DF0
    if (ctx->r2 == 0) {
        // 0x80022D44: nop
    
            goto L_80022DF0;
    }
    // 0x80022D44: nop

    // 0x80022D48: lhu         $v0, 0x5A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X5A);
    // 0x80022D4C: xori        $v1, $v0, 0x37
    ctx->r3 = ctx->r2 ^ 0X37;
    // 0x80022D50: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80022D54: xori        $v0, $v0, 0x26
    ctx->r2 = ctx->r2 ^ 0X26;
    // 0x80022D58: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80022D5C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80022D60: beq         $v1, $zero, L_80022D90
    if (ctx->r3 == 0) {
        // 0x80022D64: nop
    
            goto L_80022D90;
    }
    // 0x80022D64: nop

    // 0x80022D68: lhu         $v0, 0x1C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1C);
    // 0x80022D6C: beq         $v0, $zero, L_80022D84
    if (ctx->r2 == 0) {
        // 0x80022D70: nop
    
            goto L_80022D84;
    }
    // 0x80022D70: nop

    // 0x80022D74: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x80022D78: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022D7C: j           L_80022DF0
    // 0x80022D80: sw          $v0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r2;
        goto L_80022DF0;
    // 0x80022D80: sw          $v0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r2;
L_80022D84:
    // 0x80022D84: lw          $v0, 0x1C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1C);
    // 0x80022D88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022D8C: sw          $v0, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r2;
L_80022D90:
    // 0x80022D90: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80022D94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022D98: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80022D9C: lhu         $v0, 0x1C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1C);
    // 0x80022DA0: bne         $v0, $zero, L_80022DB4
    if (ctx->r2 != 0) {
        // 0x80022DA4: nop
    
            goto L_80022DB4;
    }
    // 0x80022DA4: nop

    // 0x80022DA8: lhu         $v1, 0x5A($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X5A);
    // 0x80022DAC: bne         $v1, $t0, L_80022DC4
    if (ctx->r3 != ctx->r8) {
        // 0x80022DB0: nop
    
            goto L_80022DC4;
    }
    // 0x80022DB0: nop

L_80022DB4:
    // 0x80022DB4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80022DB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022DBC: j           L_80022DF0
    // 0x80022DC0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
        goto L_80022DF0;
    // 0x80022DC0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_80022DC4:
    // 0x80022DC4: bne         $v1, $zero, L_80022DDC
    if (ctx->r3 != 0) {
        // 0x80022DC8: nop
    
            goto L_80022DDC;
    }
    // 0x80022DC8: nop

    // 0x80022DCC: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x80022DD0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022DD4: j           L_80022DF0
    // 0x80022DD8: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
        goto L_80022DF0;
    // 0x80022DD8: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
L_80022DDC:
    // 0x80022DDC: bne         $v1, $a3, L_80022DF0
    if (ctx->r3 != ctx->r7) {
        // 0x80022DE0: nop
    
            goto L_80022DF0;
    }
    // 0x80022DE0: nop

    // 0x80022DE4: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x80022DE8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022DEC: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
L_80022DF0:
    // 0x80022DF0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80022DF4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80022DF8: bne         $v0, $zero, L_80022D1C
    if (ctx->r2 != 0) {
        // 0x80022DFC: sw          $v0, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r2;
            goto L_80022D1C;
    }
    // 0x80022DFC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80022E00: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80022E04: lw          $v0, 0x31AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31AC);
    // 0x80022E08: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80022E0C: lw          $v1, 0x31B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31B0);
    // 0x80022E10: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80022E14: lw          $a0, 0x31B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31B4);
    // 0x80022E18: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80022E1C: lw          $a1, 0x31BC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31BC);
    // 0x80022E20: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80022E24: lw          $a2, 0x31C4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X31C4);
    // 0x80022E28: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80022E2C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80022E30: sh          $v0, -0x6DF0($at)
    MEM_H(-0X6DF0, ctx->r1) = ctx->r2;
    // 0x80022E34: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80022E38: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80022E3C: sh          $v1, -0x68E8($at)
    MEM_H(-0X68E8, ctx->r1) = ctx->r3;
    // 0x80022E40: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80022E44: sh          $a0, -0x3090($at)
    MEM_H(-0X3090, ctx->r1) = ctx->r4;
    // 0x80022E48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022E4C: sh          $a1, 0x8C($at)
    MEM_H(0X8C, ctx->r1) = ctx->r5;
    // 0x80022E50: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80022E54: sh          $a2, 0x5520($at)
    MEM_H(0X5520, ctx->r1) = ctx->r6;
    // 0x80022E58: blez        $v0, L_80022ED0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80022E5C: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80022ED0;
    }
    // 0x80022E5C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80022E60: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x80022E64: addiu       $s3, $s3, 0x3F94
    ctx->r19 = ADD32(ctx->r19, 0X3F94);
    // 0x80022E68: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80022E6C: addiu       $s1, $s1, 0x540
    ctx->r17 = ADD32(ctx->r17, 0X540);
L_80022E70:
    // 0x80022E70: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80022E74: jal         0x8001F310
    // 0x80022E78: nop

    func_8001F310(rdram, ctx);
        goto after_0;
    // 0x80022E78: nop

    after_0:
    // 0x80022E7C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80022E80: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80022E84: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80022E88: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80022E8C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022E90: addu        $a0, $v1, $s3
    ctx->r4 = ADD32(ctx->r3, ctx->r19);
    // 0x80022E94: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    // 0x80022E98: bne         $v0, $zero, L_80022EAC
    if (ctx->r2 != 0) {
        // 0x80022E9C: nop
    
            goto L_80022EAC;
    }
    // 0x80022E9C: nop

    // 0x80022EA0: lh          $v0, 0x8($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X8);
    // 0x80022EA4: beql        $v0, $zero, L_80022EBC
    if (ctx->r2 == 0) {
        // 0x80022EA8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80022EBC;
    }
    goto skip_0;
    // 0x80022EA8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
L_80022EAC:
    // 0x80022EAC: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x80022EB0: lhu         $s2, -0x6DF0($s2)
    ctx->r18 = MEM_HU(ctx->r18, -0X6DF0);
    // 0x80022EB4: j           L_80022ED0
    // 0x80022EB8: nop

        goto L_80022ED0;
    // 0x80022EB8: nop

L_80022EBC:
    // 0x80022EBC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80022EC0: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x80022EC4: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80022EC8: bne         $v0, $zero, L_80022E70
    if (ctx->r2 != 0) {
        // 0x80022ECC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80022E70;
    }
    // 0x80022ECC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80022ED0:
    // 0x80022ED0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80022ED4: sh          $s2, -0x6DF0($at)
    MEM_H(-0X6DF0, ctx->r1) = ctx->r18;
    // 0x80022ED8: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80022EDC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80022EE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80022EE4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80022EE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80022EEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80022EF0: jr          $ra
    // 0x80022EF4: nop

    return;
    // 0x80022EF4: nop

;}
RECOMP_FUNC void func_80022EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022EF8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80022EFC: addiu       $v0, $v0, 0x31AC
    ctx->r2 = ADD32(ctx->r2, 0X31AC);
    // 0x80022F00: addiu       $a0, $v0, -0x4
    ctx->r4 = ADD32(ctx->r2, -0X4);
    // 0x80022F04: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80022F08: addiu       $a1, $a1, 0x3F94
    ctx->r5 = ADD32(ctx->r5, 0X3F94);
    // 0x80022F0C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80022F10: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80022F14: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80022F18: sw          $zero, 0x31B0($at)
    MEM_W(0X31B0, ctx->r1) = 0;
    // 0x80022F1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80022F20: sw          $v0, 0x31A8($at)
    MEM_W(0X31A8, ctx->r1) = ctx->r2;
L_80022F24:
    // 0x80022F24: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80022F28: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80022F2C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80022F30: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80022F34: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80022F38: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80022F3C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80022F40: lhu         $v0, 0x58($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X58);
    // 0x80022F44: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80022F48: beq         $v0, $zero, L_80022F80
    if (ctx->r2 == 0) {
        // 0x80022F4C: nop
    
            goto L_80022F80;
    }
    // 0x80022F4C: nop

    // 0x80022F50: lhu         $v0, 0x1B0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1B0);
    // 0x80022F54: beq         $v0, $zero, L_80022F68
    if (ctx->r2 == 0) {
        // 0x80022F58: nop
    
            goto L_80022F68;
    }
    // 0x80022F58: nop

    // 0x80022F5C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80022F60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022F64: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
L_80022F68:
    // 0x80022F68: lhu         $v0, 0x1DE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1DE);
    // 0x80022F6C: beq         $v0, $zero, L_80022F80
    if (ctx->r2 == 0) {
        // 0x80022F70: nop
    
            goto L_80022F80;
    }
    // 0x80022F70: nop

    // 0x80022F74: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80022F78: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022F7C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80022F80:
    // 0x80022F80: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80022F84: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80022F88: bne         $v0, $zero, L_80022F24
    if (ctx->r2 != 0) {
        // 0x80022F8C: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80022F24;
    }
    // 0x80022F8C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80022F90: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80022F94: lw          $v0, 0x31AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31AC);
    // 0x80022F98: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80022F9C: lw          $v1, 0x31B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31B0);
    // 0x80022FA0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80022FA4: sh          $v0, -0x7502($at)
    MEM_H(-0X7502, ctx->r1) = ctx->r2;
    // 0x80022FA8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80022FAC: sh          $v1, -0x7334($at)
    MEM_H(-0X7334, ctx->r1) = ctx->r3;
    // 0x80022FB0: jr          $ra
    // 0x80022FB4: nop

    return;
    // 0x80022FB4: nop

;}
RECOMP_FUNC void func_80022FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022FB8: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80022FBC: lw          $v0, -0x307C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X307C);
    // 0x80022FC0: beq         $v0, $zero, L_80022FEC
    if (ctx->r2 == 0) {
        // 0x80022FC4: nop
    
            goto L_80022FEC;
    }
    // 0x80022FC4: nop

    // 0x80022FC8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80022FCC: lw          $v0, 0x57E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X57E0);
    // 0x80022FD0: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x80022FD4: beq         $v0, $zero, L_80022FEC
    if (ctx->r2 == 0) {
        // 0x80022FD8: nop
    
            goto L_80022FEC;
    }
    // 0x80022FD8: nop

    // 0x80022FDC: j           L_80023078
    // 0x80022FE0: sh          $zero, 0xDC($a0)
    MEM_H(0XDC, ctx->r4) = 0;
        goto L_80023078;
    // 0x80022FE0: sh          $zero, 0xDC($a0)
    MEM_H(0XDC, ctx->r4) = 0;
L_80022FE4:
    // 0x80022FE4: j           L_80023074
    // 0x80022FE8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80023074;
    // 0x80022FE8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80022FEC:
    // 0x80022FEC: lhu         $a3, 0x5A($a0)
    ctx->r7 = MEM_HU(ctx->r4, 0X5A);
    // 0x80022FF0: xori        $v1, $a3, 0x37
    ctx->r3 = ctx->r7 ^ 0X37;
    // 0x80022FF4: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80022FF8: xori        $v0, $a3, 0x26
    ctx->r2 = ctx->r7 ^ 0X26;
    // 0x80022FFC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80023000: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80023004: beq         $v1, $zero, L_80023078
    if (ctx->r3 == 0) {
        // 0x80023008: nop
    
            goto L_80023078;
    }
    // 0x80023008: nop

    // 0x8002300C: lhu         $v1, 0x126($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X126);
    // 0x80023010: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // 0x80023014: beq         $v1, $v0, L_80023074
    if (ctx->r3 == ctx->r2) {
        // 0x80023018: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80023074;
    }
    // 0x80023018: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8002301C: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x80023020: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80023024: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80023028: bnel        $v0, $zero, L_80023078
    if (ctx->r2 != 0) {
        // 0x8002302C: sh          $t0, 0xDC($a0)
        MEM_H(0XDC, ctx->r4) = ctx->r8;
            goto L_80023078;
    }
    goto skip_0;
    // 0x8002302C: sh          $t0, 0xDC($a0)
    MEM_H(0XDC, ctx->r4) = ctx->r8;
    skip_0:
    // 0x80023030: lhu         $v0, 0x140($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X140);
    // 0x80023034: bnel        $v0, $zero, L_80023078
    if (ctx->r2 != 0) {
        // 0x80023038: sh          $t0, 0xDC($a0)
        MEM_H(0XDC, ctx->r4) = ctx->r8;
            goto L_80023078;
    }
    goto skip_1;
    // 0x80023038: sh          $t0, 0xDC($a0)
    MEM_H(0XDC, ctx->r4) = ctx->r8;
    skip_1:
    // 0x8002303C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80023040: addiu       $a2, $a2, 0x5C3C
    ctx->r6 = ADD32(ctx->r6, 0X5C3C);
    // 0x80023044: lhu         $a1, 0x0($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X0);
    // 0x80023048: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8002304C: andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // 0x80023050: beql        $v1, $v0, L_80023078
    if (ctx->r3 == ctx->r2) {
        // 0x80023054: sh          $t0, 0xDC($a0)
        MEM_H(0XDC, ctx->r4) = ctx->r8;
            goto L_80023078;
    }
    goto skip_2;
    // 0x80023054: sh          $t0, 0xDC($a0)
    MEM_H(0XDC, ctx->r4) = ctx->r8;
    skip_2:
    // 0x80023058: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x8002305C: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
L_80023060:
    // 0x80023060: beq         $a1, $v0, L_80022FE4
    if (ctx->r5 == ctx->r2) {
        // 0x80023064: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_80022FE4;
    }
    // 0x80023064: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80023068: lhu         $a1, 0x0($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X0);
    // 0x8002306C: bne         $a1, $v1, L_80023060
    if (ctx->r5 != ctx->r3) {
        // 0x80023070: nop
    
            goto L_80023060;
    }
    // 0x80023070: nop

L_80023074:
    // 0x80023074: sh          $t0, 0xDC($a0)
    MEM_H(0XDC, ctx->r4) = ctx->r8;
L_80023078:
    // 0x80023078: jr          $ra
    // 0x8002307C: nop

    return;
    // 0x8002307C: nop

;}
RECOMP_FUNC void func_80023080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023080: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80023084: lh          $v1, 0x4E18($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X4E18);
    // FALLTHROUGH: func_80023080 falls into func_80023088
    func_80023088(rdram, ctx);
;}
RECOMP_FUNC void func_80023088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002308C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80023090: bne         $v1, $v0, L_800230A8
    if (ctx->r3 != ctx->r2) {
        // 0x80023094: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800230A8;
    }
    // 0x80023094: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80023098: jal         0x80026684
    // 0x8002309C: nop

    func_80026684(rdram, ctx);
        goto after_0;
    // 0x8002309C: nop

    after_0:
    // 0x800230A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800230A4: sh          $v0, 0x4E18($at)
    MEM_H(0X4E18, ctx->r1) = ctx->r2;
L_800230A8:
    // 0x800230A8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800230AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800230B0: jr          $ra
    // 0x800230B4: nop

    return;
    // 0x800230B4: nop

;}
RECOMP_FUNC void func_800230B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800230B8: addiu       $v1, $a0, 0x130
    ctx->r3 = ADD32(ctx->r4, 0X130);
    // 0x800230BC: addiu       $a0, $a0, 0x14A
    ctx->r4 = ADD32(ctx->r4, 0X14A);
    // 0x800230C0: sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x800230C4: bne         $v0, $zero, L_800230EC
    if (ctx->r2 != 0) {
        // 0x800230C8: nop
    
            goto L_800230EC;
    }
    // 0x800230C8: nop

L_800230CC:
    // 0x800230CC: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800230D0: beq         $v0, $zero, L_800230DC
    if (ctx->r2 == 0) {
        // 0x800230D4: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800230DC;
    }
    // 0x800230D4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800230D8: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_800230DC:
    // 0x800230DC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800230E0: sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x800230E4: beq         $v0, $zero, L_800230CC
    if (ctx->r2 == 0) {
        // 0x800230E8: nop
    
            goto L_800230CC;
    }
    // 0x800230E8: nop

L_800230EC:
    // 0x800230EC: jr          $ra
    // 0x800230F0: nop

    return;
    // 0x800230F0: nop

;}
RECOMP_FUNC void func_800230F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800230F4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800230F8: lh          $v0, -0x67C6($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X67C6);
    // FALLTHROUGH: func_800230F4 falls into func_800230FC
    func_800230FC(rdram, ctx);
;}
RECOMP_FUNC void func_800230FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800230FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80023100: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80023104: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80023108: addiu       $s1, $s1, 0x4760
    ctx->r17 = ADD32(ctx->r17, 0X4760);
    // 0x8002310C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80023110: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80023114: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80023118: beq         $v0, $zero, L_80023160
    if (ctx->r2 == 0) {
        // 0x8002311C: nop
    
            goto L_80023160;
    }
    // 0x8002311C: nop

    // 0x80023120: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80023124: lh          $v0, -0x5AFC($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5AFC);
    // 0x80023128: bgtz        $v0, L_80023160
    if (SIGNED(ctx->r2) > 0) {
        // 0x8002312C: nop
    
            goto L_80023160;
    }
    // 0x8002312C: nop

    // 0x80023130: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80023134: lhu         $v0, 0x46CE($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X46CE);
    // 0x80023138: bne         $v0, $zero, L_80023160
    if (ctx->r2 != 0) {
        // 0x8002313C: nop
    
            goto L_80023160;
    }
    // 0x8002313C: nop

    // 0x80023140: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80023144: lh          $v0, 0x166($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X166);
    // 0x80023148: bne         $v0, $zero, L_80023160
    if (ctx->r2 != 0) {
        // 0x8002314C: nop
    
            goto L_80023160;
    }
    // 0x8002314C: nop

    // 0x80023150: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80023154: lw          $v0, 0x3A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A0);
    // 0x80023158: beq         $v0, $zero, L_80023178
    if (ctx->r2 == 0) {
        // 0x8002315C: nop
    
            goto L_80023178;
    }
    // 0x8002315C: nop

L_80023160:
    // 0x80023160: beq         $s0, $zero, L_80023274
    if (ctx->r16 == 0) {
        // 0x80023164: addiu       $v0, $zero, 0x190
        ctx->r2 = ADD32(0, 0X190);
            goto L_80023274;
    }
    // 0x80023164: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
    // 0x80023168: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002316C: sh          $zero, 0x4764($at)
    MEM_H(0X4764, ctx->r1) = 0;
    // 0x80023170: j           L_8002326C
    // 0x80023174: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
        goto L_8002326C;
    // 0x80023174: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
L_80023178:
    // 0x80023178: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002317C: lhu         $v1, 0x4764($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X4764);
    // 0x80023180: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80023184: slti        $v0, $v0, 0xB4
    ctx->r2 = SIGNED(ctx->r2) < 0XB4 ? 1 : 0;
    // 0x80023188: bnel        $v0, $zero, L_80023258
    if (ctx->r2 != 0) {
        // 0x8002318C: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80023258;
    }
    goto skip_0;
    // 0x8002318C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80023190: bne         $s0, $zero, L_80023208
    if (ctx->r16 != 0) {
        // 0x80023194: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80023208;
    }
    // 0x80023194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80023198: jal         0x800306EC
    // 0x8002319C: nop

    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x8002319C: nop

    after_0:
    // 0x800231A0: lui         $a1, 0x4F00
    ctx->r5 = S32(0X4F00 << 16);
    // 0x800231A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800231A8: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x800231AC: lhu         $a0, 0x6($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X6);
    // 0x800231B0: ori         $a1, $a1, 0xA2
    ctx->r5 = ctx->r5 | 0XA2;
    // 0x800231B4: addiu       $v1, $zero, 0x7000
    ctx->r3 = ADD32(0, 0X7000);
    // 0x800231B8: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x800231BC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800231C0: addiu       $v1, $v1, -0x5FC
    ctx->r3 = ADD32(ctx->r3, -0X5FC);
    // 0x800231C4: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x800231C8: addiu       $v1, $zero, 0x150
    ctx->r3 = ADD32(0, 0X150);
    // 0x800231CC: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x800231D0: addiu       $v1, $zero, 0x190
    ctx->r3 = ADD32(0, 0X190);
    // 0x800231D4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x800231D8: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x800231DC: ori         $a0, $a0, 0x20
    ctx->r4 = ctx->r4 | 0X20;
    // 0x800231E0: jal         0x80023E44
    // 0x800231E4: sh          $a0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r4;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x800231E4: sh          $a0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r4;
    after_1:
    // 0x800231E8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800231EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800231F0: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x800231F4: sw          $s1, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r17;
    // 0x800231F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800231FC: sh          $v0, 0x4766($at)
    MEM_H(0X4766, ctx->r1) = ctx->r2;
    // 0x80023200: j           L_80023274
    // 0x80023204: nop

        goto L_80023274;
    // 0x80023204: nop

L_80023208:
    // 0x80023208: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002320C: sh          $v0, 0x4766($at)
    MEM_H(0X4766, ctx->r1) = ctx->r2;
    // 0x80023210: addiu       $v0, $zero, 0x7C
    ctx->r2 = ADD32(0, 0X7C);
    // 0x80023214: jal         0x800232B8
    // 0x80023218: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    func_800232B8(rdram, ctx);
        goto after_2;
    // 0x80023218: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    after_2:
    // 0x8002321C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80023220: beq         $v0, $zero, L_80023238
    if (ctx->r2 == 0) {
        // 0x80023224: addiu       $v0, $zero, 0x30
        ctx->r2 = ADD32(0, 0X30);
            goto L_80023238;
    }
    // 0x80023224: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x80023228: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8002322C: addiu       $a0, $a0, -0x5C8
    ctx->r4 = ADD32(ctx->r4, -0X5C8);
    // 0x80023230: j           L_80023248
    // 0x80023234: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
        goto L_80023248;
    // 0x80023234: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
L_80023238:
    // 0x80023238: addiu       $v0, $zero, 0x150
    ctx->r2 = ADD32(0, 0X150);
    // 0x8002323C: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    // 0x80023240: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80023244: addiu       $a0, $a0, -0x5FC
    ctx->r4 = ADD32(ctx->r4, -0X5FC);
L_80023248:
    // 0x80023248: jal         0x80037DDC
    // 0x8002324C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80037DDC(rdram, ctx);
        goto after_3;
    // 0x8002324C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80023250: j           L_80023274
    // 0x80023254: nop

        goto L_80023274;
    // 0x80023254: nop

L_80023258:
    // 0x80023258: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002325C: sh          $v0, 0x4764($at)
    MEM_H(0X4764, ctx->r1) = ctx->r2;
    // 0x80023260: beq         $s0, $zero, L_80023274
    if (ctx->r16 == 0) {
        // 0x80023264: addiu       $v0, $zero, 0x190
        ctx->r2 = ADD32(0, 0X190);
            goto L_80023274;
    }
    // 0x80023264: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
    // 0x80023268: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
L_8002326C:
    // 0x8002326C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80023270: sh          $zero, 0x4766($at)
    MEM_H(0X4766, ctx->r1) = 0;
L_80023274:
    // 0x80023274: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80023278: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002327C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80023280: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80023284: jr          $ra
    // 0x80023288: nop

    return;
    // 0x80023288: nop

;}
RECOMP_FUNC void func_8002328C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002328C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023290: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80023294: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80023298: addiu       $a0, $a0, 0x4760
    ctx->r4 = ADD32(ctx->r4, 0X4760);
    // 0x8002329C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800232A0: jal         0x8007DEC0
    // 0x800232A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_8007DEC0(rdram, ctx);
        goto after_0;
    // 0x800232A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800232A8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800232AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800232B0: jr          $ra
    // 0x800232B4: nop

    return;
    // 0x800232B4: nop

;}
RECOMP_FUNC void func_800232B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800232B8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800232BC: lhu         $v0, 0x46A8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X46A8);
    // 0x800232C0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800232C4: lhu         $v1, 0x3294($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X3294);
    // FALLTHROUGH: func_800232B8 falls into func_800232C8
    func_800232C8(rdram, ctx);
;}
RECOMP_FUNC void func_800232C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800232C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800232CC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800232D0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800232D4: lhu         $s1, 0x3E4($s1)
    ctx->r17 = MEM_HU(ctx->r17, 0X3E4);
    // 0x800232D8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800232DC: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800232E0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800232E4: addiu       $s2, $zero, 0x270F
    ctx->r18 = ADD32(0, 0X270F);
    // 0x800232E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800232EC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800232F0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800232F4: addiu       $v0, $v0, 0xC8
    ctx->r2 = ADD32(ctx->r2, 0XC8);
    // 0x800232F8: beq         $s1, $zero, L_8002339C
    if (ctx->r17 == 0) {
        // 0x800232FC: and         $v1, $v1, $v0
        ctx->r3 = ctx->r3 & ctx->r2;
            goto L_8002339C;
    }
    // 0x800232FC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80023300: sll         $s4, $v1, 16
    ctx->r20 = S32(ctx->r3 << 16);
    // 0x80023304: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80023308: addiu       $s0, $s0, -0x6C62
    ctx->r16 = ADD32(ctx->r16, -0X6C62);
L_8002330C:
    // 0x8002330C: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x80023310: sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x80023314: beq         $v0, $zero, L_80023388
    if (ctx->r2 == 0) {
        // 0x80023318: sra         $a1, $s4, 16
        ctx->r5 = S32(SIGNED(ctx->r20) >> 16);
            goto L_80023388;
    }
    // 0x80023318: sra         $a1, $s4, 16
    ctx->r5 = S32(SIGNED(ctx->r20) >> 16);
    // 0x8002331C: lh          $a0, -0xA($s0)
    ctx->r4 = MEM_H(ctx->r16, -0XA);
    // 0x80023320: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80023324: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80023328: jal         0x8003F1F0
    // 0x8002332C: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    func_8003F1F0(rdram, ctx);
        goto after_0;
    // 0x8002332C: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    after_0:
    // 0x80023330: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80023334: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
    // 0x80023338: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002333C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80023340: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023344: bltzl       $v0, L_80023360
    if (SIGNED(ctx->r2) < 0) {
        // 0x80023348: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_80023360;
    }
    goto skip_0;
    // 0x80023348: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_0:
    // 0x8002334C: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80023350: beq         $v0, $zero, L_80023370
    if (ctx->r2 == 0) {
        // 0x80023354: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80023370;
    }
    // 0x80023354: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80023358: j           L_8002338C
    // 0x8002335C: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
        goto L_8002338C;
    // 0x8002335C: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
L_80023360:
    // 0x80023360: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80023364: bne         $v0, $zero, L_8002338C
    if (ctx->r2 != 0) {
        // 0x80023368: addiu       $v0, $s1, -0x1
        ctx->r2 = ADD32(ctx->r17, -0X1);
            goto L_8002338C;
    }
    // 0x80023368: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x8002336C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80023370:
    // 0x80023370: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023374: bgez        $v0, L_80023380
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80023378: addu        $s2, $v0, $zero
        ctx->r18 = ADD32(ctx->r2, 0);
            goto L_80023380;
    }
    // 0x80023378: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8002337C: negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
L_80023380:
    // 0x80023380: slti        $v0, $v0, 0x1
    ctx->r2 = SIGNED(ctx->r2) < 0X1 ? 1 : 0;
    // 0x80023384: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_80023388:
    // 0x80023388: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
L_8002338C:
    // 0x8002338C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80023390: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80023394: bne         $v0, $zero, L_8002330C
    if (ctx->r2 != 0) {
        // 0x80023398: addiu       $s0, $s0, 0x584
        ctx->r16 = ADD32(ctx->r16, 0X584);
            goto L_8002330C;
    }
    // 0x80023398: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
L_8002339C:
    // 0x8002339C: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x800233A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800233A4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800233A8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800233AC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800233B0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800233B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800233B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800233BC: jr          $ra
    // 0x800233C0: nop

    return;
    // 0x800233C0: nop

;}
RECOMP_FUNC void func_800233C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800233C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800233C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800233CC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800233D0: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x800233D4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800233D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800233DC: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x800233E0: beq         $s0, $zero, L_80023440
    if (ctx->r16 == 0) {
        // 0x800233E4: nop
    
            goto L_80023440;
    }
    // 0x800233E4: nop

    // 0x800233E8: lhu         $v0, 0x5A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X5A);
    // 0x800233EC: xori        $v1, $v0, 0x2
    ctx->r3 = ctx->r2 ^ 0X2;
    // 0x800233F0: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800233F4: xori        $v0, $v0, 0x4E
    ctx->r2 = ctx->r2 ^ 0X4E;
    // 0x800233F8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800233FC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80023400: beq         $v1, $zero, L_80023420
    if (ctx->r3 == 0) {
        // 0x80023404: nop
    
            goto L_80023420;
    }
    // 0x80023404: nop

    // 0x80023408: lhu         $v0, 0x1BE($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1BE);
    // 0x8002340C: beq         $v0, $zero, L_80023420
    if (ctx->r2 == 0) {
        // 0x80023410: nop
    
            goto L_80023420;
    }
    // 0x80023410: nop

    // 0x80023414: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80023418: blez        $v0, L_80023440
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002341C: nop
    
            goto L_80023440;
    }
    // 0x8002341C: nop

L_80023420:
    // 0x80023420: lhu         $v1, 0x12C($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X12C);
    // 0x80023424: lhu         $v0, 0x80($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X80);
    // 0x80023428: beq         $v1, $v0, L_80023440
    if (ctx->r3 == ctx->r2) {
        // 0x8002342C: nop
    
            goto L_80023440;
    }
    // 0x8002342C: nop

    // 0x80023430: jal         0x8002461C
    // 0x80023434: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002461C(rdram, ctx);
        goto after_0;
    // 0x80023434: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80023438: jal         0x80024564
    // 0x8002343C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80024564(rdram, ctx);
        goto after_1;
    // 0x8002343C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
L_80023440:
    // 0x80023440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023444: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80023448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002344C: jr          $ra
    // 0x80023450: nop

    return;
    // 0x80023450: nop

;}
RECOMP_FUNC void func_80023454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023454: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80023458: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8002345C: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x80023460: andi        $v0, $v0, 0xFF90
    ctx->r2 = ctx->r2 & 0XFF90;
    // 0x80023464: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x80023468: jr          $ra
    // 0x8002346C: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    return;
    // 0x8002346C: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80023470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023470: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80023474: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80023478: beq         $v0, $zero, L_800234A4
    if (ctx->r2 == 0) {
        // 0x8002347C: nop
    
            goto L_800234A4;
    }
    // 0x8002347C: nop

    // 0x80023480: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80023484: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80023488: lhu         $v1, 0x22($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X22);
    // 0x8002348C: andi        $v1, $v1, 0xFFF0
    ctx->r3 = ctx->r3 & 0XFFF0;
    // 0x80023490: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // 0x80023494: andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // 0x80023498: bnel        $v0, $zero, L_800234A0
    if (ctx->r2 != 0) {
        // 0x8002349C: andi        $v1, $v1, 0xFF72
        ctx->r3 = ctx->r3 & 0XFF72;
            goto L_800234A0;
    }
    goto skip_0;
    // 0x8002349C: andi        $v1, $v1, 0xFF72
    ctx->r3 = ctx->r3 & 0XFF72;
    skip_0:
L_800234A0:
    // 0x800234A0: sh          $v1, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r3;
L_800234A4:
    // 0x800234A4: jr          $ra
    // 0x800234A8: nop

    return;
    // 0x800234A8: nop

;}
RECOMP_FUNC void func_800234AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800234AC: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x800234B0: lw          $v0, -0x307C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X307C);
    // FALLTHROUGH: func_800234AC falls into func_800234B4
    func_800234B4(rdram, ctx);
;}
RECOMP_FUNC void func_800234B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800234B4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800234B8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800234BC: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800234C0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800234C4: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x800234C8: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800234CC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800234D0: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800234D4: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x800234D8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800234DC: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800234E0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800234E4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800234E8: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800234EC: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x800234F0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800234F4: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800234F8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800234FC: beq         $v0, $zero, L_80023510
    if (ctx->r2 == 0) {
        // 0x80023500: sw          $zero, 0x14($sp)
        MEM_W(0X14, ctx->r29) = 0;
            goto L_80023510;
    }
    // 0x80023500: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80023504: jal         0x80027338
    // 0x80023508: nop

    func_80027338(rdram, ctx);
        goto after_0;
    // 0x80023508: nop

    after_0:
    // 0x8002350C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
L_80023510:
    // 0x80023510: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80023514: lhu         $s0, 0x46A8($s0)
    ctx->r16 = MEM_HU(ctx->r16, 0X46A8);
    // 0x80023518: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8002351C: lhu         $s7, 0x3A0($s7)
    ctx->r23 = MEM_HU(ctx->r23, 0X3A0);
    // 0x80023520: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80023524: bne         $s4, $v0, L_800237C4
    if (ctx->r20 != ctx->r2) {
        // 0x80023528: nop
    
            goto L_800237C4;
    }
    // 0x80023528: nop

    // 0x8002352C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80023530: lw          $v0, 0x57E4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X57E4);
    // 0x80023534: blez        $v0, L_800238D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80023538: nop
    
            goto L_800238D4;
    }
    // 0x80023538: nop

    // 0x8002353C: jal         0x8001F310
    // 0x80023540: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    func_8001F310(rdram, ctx);
        goto after_1;
    // 0x80023540: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_1:
    // 0x80023544: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80023548: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002354C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80023550: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80023554: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80023558: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8002355C: addiu       $v0, $v0, 0x3F94
    ctx->r2 = ADD32(ctx->r2, 0X3F94);
    // 0x80023560: addu        $s3, $v1, $v0
    ctx->r19 = ADD32(ctx->r3, ctx->r2);
    // 0x80023564: lw          $v0, 0x68($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X68);
    // 0x80023568: addiu       $a0, $s0, 0x131
    ctx->r4 = ADD32(ctx->r16, 0X131);
    // 0x8002356C: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80023570: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80023574: lh          $v1, 0x3294($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X3294);
    // 0x80023578: lhu         $s1, 0x14($v0)
    ctx->r17 = MEM_HU(ctx->r2, 0X14);
    // 0x8002357C: lhu         $s4, 0x18($v0)
    ctx->r20 = MEM_HU(ctx->r2, 0X18);
    // 0x80023580: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80023584: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023588: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8002358C: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80023590: beq         $v1, $zero, L_8002359C
    if (ctx->r3 == 0) {
        // 0x80023594: addu        $a2, $s1, $zero
        ctx->r6 = ADD32(ctx->r17, 0);
            goto L_8002359C;
    }
    // 0x80023594: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80023598: subu        $a3, $a0, $a1
    ctx->r7 = SUB32(ctx->r4, ctx->r5);
L_8002359C:
    // 0x8002359C: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x800235A0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800235A4: sll         $v1, $s0, 16
    ctx->r3 = S32(ctx->r16 << 16);
    // 0x800235A8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800235AC: slt         $a0, $v1, $v0
    ctx->r4 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800235B0: sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7 << 16);
    // 0x800235B4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800235B8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800235BC: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x800235C0: beq         $v0, $zero, L_800235D8
    if (ctx->r2 == 0) {
        // 0x800235C4: nop
    
            goto L_800235D8;
    }
    // 0x800235C4: nop

    // 0x800235C8: bne         $a0, $zero, L_800235D8
    if (ctx->r4 != 0) {
        // 0x800235CC: subu        $a2, $s1, $s0
        ctx->r6 = SUB32(ctx->r17, ctx->r16);
            goto L_800235D8;
    }
    // 0x800235CC: subu        $a2, $s1, $s0
    ctx->r6 = SUB32(ctx->r17, ctx->r16);
    // 0x800235D0: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x800235D4: addu        $a2, $s1, $v0
    ctx->r6 = ADD32(ctx->r17, ctx->r2);
L_800235D8:
    // 0x800235D8: lhu         $v1, 0x5A($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X5A);
    // 0x800235DC: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x800235E0: xori        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 ^ 0X2;
    // 0x800235E4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800235E8: xori        $v1, $v1, 0x19
    ctx->r3 = ctx->r3 ^ 0X19;
    // 0x800235EC: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800235F0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800235F4: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800235F8: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x800235FC: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023600: slti        $v0, $v1, 0x132
    ctx->r2 = SIGNED(ctx->r3) < 0X132 ? 1 : 0;
    // 0x80023604: bne         $v0, $zero, L_8002364C
    if (ctx->r2 != 0) {
        // 0x80023608: addu        $fp, $a0, $zero
        ctx->r30 = ADD32(ctx->r4, 0);
            goto L_8002364C;
    }
    // 0x80023608: addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // 0x8002360C: lw          $v0, 0x68($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X68);
    // 0x80023610: lhu         $v0, 0xC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XC);
    // 0x80023614: addiu       $v1, $v1, -0x131
    ctx->r3 = ADD32(ctx->r3, -0X131);
    // 0x80023618: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8002361C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80023620: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80023624: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023628: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002362C: bnel        $v1, $zero, L_80023634
    if (ctx->r3 != 0) {
        // 0x80023630: addiu       $s2, $s1, -0x131
        ctx->r18 = ADD32(ctx->r17, -0X131);
            goto L_80023634;
    }
    goto skip_0;
    // 0x80023630: addiu       $s2, $s1, -0x131
    ctx->r18 = ADD32(ctx->r17, -0X131);
    skip_0:
L_80023634:
    // 0x80023634: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80023638: addiu       $v1, $v1, 0x57E0
    ctx->r3 = ADD32(ctx->r3, 0X57E0);
    // 0x8002363C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80023640: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x80023644: j           L_8002367C
    // 0x80023648: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_8002367C;
    // 0x80023648: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8002364C:
    // 0x8002364C: slti        $v0, $v1, 0x5A
    ctx->r2 = SIGNED(ctx->r3) < 0X5A ? 1 : 0;
    // 0x80023650: beq         $v0, $zero, L_8002367C
    if (ctx->r2 == 0) {
        // 0x80023654: addiu       $v1, $v1, -0x5A
        ctx->r3 = ADD32(ctx->r3, -0X5A);
            goto L_8002367C;
    }
    // 0x80023654: addiu       $v1, $v1, -0x5A
    ctx->r3 = ADD32(ctx->r3, -0X5A);
    // 0x80023658: lw          $v0, 0x68($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X68);
    // 0x8002365C: lhu         $v0, 0xC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XC);
    // 0x80023660: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80023664: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80023668: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002366C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023670: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80023674: bnel        $v0, $zero, L_8002367C
    if (ctx->r2 != 0) {
        // 0x80023678: addiu       $s2, $s1, -0x5A
        ctx->r18 = ADD32(ctx->r17, -0X5A);
            goto L_8002367C;
    }
    goto skip_1;
    // 0x80023678: addiu       $s2, $s1, -0x5A
    ctx->r18 = ADD32(ctx->r17, -0X5A);
    skip_1:
L_8002367C:
    // 0x8002367C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80023680: addiu       $a2, $a2, 0x57E0
    ctx->r6 = ADD32(ctx->r6, 0X57E0);
    // 0x80023684: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80023688: andi        $v0, $a1, 0x200
    ctx->r2 = ctx->r5 & 0X200;
    // 0x8002368C: beq         $v0, $zero, L_800236D4
    if (ctx->r2 == 0) {
        // 0x80023690: addiu       $a0, $s4, -0xE1
        ctx->r4 = ADD32(ctx->r20, -0XE1);
            goto L_800236D4;
    }
    // 0x80023690: addiu       $a0, $s4, -0xE1
    ctx->r4 = ADD32(ctx->r20, -0XE1);
    // 0x80023694: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80023698: addiu       $a0, $a0, 0x46A8
    ctx->r4 = ADD32(ctx->r4, 0X46A8);
    // 0x8002369C: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800236A0: blez        $v0, L_800236BC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800236A4: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_800236BC;
    }
    // 0x800236A4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800236A8: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x800236AC: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800236B0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800236B4: bgtzl       $v0, L_800236D4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800236B8: addiu       $a0, $s4, -0xE1
        ctx->r4 = ADD32(ctx->r20, -0XE1);
            goto L_800236D4;
    }
    goto skip_2;
    // 0x800236B8: addiu       $a0, $s4, -0xE1
    ctx->r4 = ADD32(ctx->r20, -0XE1);
    skip_2:
L_800236BC:
    // 0x800236BC: addiu       $v0, $zero, -0x201
    ctx->r2 = ADD32(0, -0X201);
    // 0x800236C0: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x800236C4: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x800236C8: jal         0x80026278
    // 0x800236CC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    func_80026278(rdram, ctx);
        goto after_2;
    // 0x800236CC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    after_2:
    // 0x800236D0: addiu       $a0, $s4, -0xE1
    ctx->r4 = ADD32(ctx->r20, -0XE1);
L_800236D4:
    // 0x800236D4: sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23 << 16);
    // 0x800236D8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800236DC: sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4 << 16);
    // 0x800236E0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800236E4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800236E8: slti        $v0, $v0, 0x6F
    ctx->r2 = SIGNED(ctx->r2) < 0X6F ? 1 : 0;
    // 0x800236EC: beq         $v0, $zero, L_80023708
    if (ctx->r2 == 0) {
        // 0x800236F0: addu        $s4, $a0, $zero
        ctx->r20 = ADD32(ctx->r4, 0);
            goto L_80023708;
    }
    // 0x800236F0: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800236F4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800236F8: lw          $v0, 0x57E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X57E0);
    // 0x800236FC: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80023700: beq         $v0, $zero, L_80023774
    if (ctx->r2 == 0) {
        // 0x80023704: sll         $v0, $s4, 16
        ctx->r2 = S32(ctx->r20 << 16);
            goto L_80023774;
    }
    // 0x80023704: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
L_80023708:
    // 0x80023708: lhu         $v0, 0x5A($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X5A);
    // 0x8002370C: xori        $v1, $v0, 0x2
    ctx->r3 = ctx->r2 ^ 0X2;
    // 0x80023710: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80023714: xori        $v0, $v0, 0x2C
    ctx->r2 = ctx->r2 ^ 0X2C;
    // 0x80023718: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8002371C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80023720: beq         $v1, $zero, L_80023770
    if (ctx->r3 == 0) {
        // 0x80023724: addiu       $v1, $s7, -0x6E
        ctx->r3 = ADD32(ctx->r23, -0X6E);
            goto L_80023770;
    }
    // 0x80023724: addiu       $v1, $s7, -0x6E
    ctx->r3 = ADD32(ctx->r23, -0X6E);
    // 0x80023728: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8002372C: addiu       $a1, $a1, 0x57E0
    ctx->r5 = ADD32(ctx->r5, 0X57E0);
    // 0x80023730: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80023734: subu        $v1, $a0, $v1
    ctx->r3 = SUB32(ctx->r4, ctx->r3);
    // 0x80023738: addu        $s5, $v1, $zero
    ctx->r21 = ADD32(ctx->r3, 0);
    // 0x8002373C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80023740: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80023744: ori         $a0, $v0, 0x4
    ctx->r4 = ctx->r2 | 0X4;
    // 0x80023748: slti        $v0, $v1, -0x4
    ctx->r2 = SIGNED(ctx->r3) < -0X4 ? 1 : 0;
    // 0x8002374C: beq         $v0, $zero, L_8002375C
    if (ctx->r2 == 0) {
        // 0x80023750: sw          $a0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r4;
            goto L_8002375C;
    }
    // 0x80023750: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x80023754: j           L_800237CC
    // 0x80023758: addiu       $s5, $zero, -0x4
    ctx->r21 = ADD32(0, -0X4);
        goto L_800237CC;
    // 0x80023758: addiu       $s5, $zero, -0x4
    ctx->r21 = ADD32(0, -0X4);
L_8002375C:
    // 0x8002375C: bne         $v1, $zero, L_800237C4
    if (ctx->r3 != 0) {
        // 0x80023760: addiu       $v0, $zero, -0x5
        ctx->r2 = ADD32(0, -0X5);
            goto L_800237C4;
    }
    // 0x80023760: addiu       $v0, $zero, -0x5
    ctx->r2 = ADD32(0, -0X5);
    // 0x80023764: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x80023768: j           L_800237C4
    // 0x8002376C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_800237C4;
    // 0x8002376C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_80023770:
    // 0x80023770: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
L_80023774:
    // 0x80023774: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023778: sll         $v1, $s7, 16
    ctx->r3 = S32(ctx->r23 << 16);
    // 0x8002377C: sra         $a0, $v1, 16
    ctx->r4 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80023780: addiu       $v1, $a0, -0x32
    ctx->r3 = ADD32(ctx->r4, -0X32);
    // 0x80023784: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80023788: blez        $v0, L_800237C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002378C: addiu       $v0, $s7, -0x32
        ctx->r2 = ADD32(ctx->r23, -0X32);
            goto L_800237C4;
    }
    // 0x8002378C: addiu       $v0, $s7, -0x32
    ctx->r2 = ADD32(ctx->r23, -0X32);
    // 0x80023790: subu        $v0, $s4, $v0
    ctx->r2 = SUB32(ctx->r20, ctx->r2);
    // 0x80023794: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x80023798: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002379C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800237A0: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800237A4: beql        $v0, $zero, L_800237AC
    if (ctx->r2 == 0) {
        // 0x800237A8: addiu       $s5, $zero, 0x4
        ctx->r21 = ADD32(0, 0X4);
            goto L_800237AC;
    }
    goto skip_3;
    // 0x800237A8: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    skip_3:
L_800237AC:
    // 0x800237AC: sll         $v1, $s5, 16
    ctx->r3 = S32(ctx->r21 << 16);
    // 0x800237B0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800237B4: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
    // 0x800237B8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800237BC: bnel        $v0, $zero, L_800237C4
    if (ctx->r2 != 0) {
        // 0x800237C0: negu        $s5, $s7
        ctx->r21 = SUB32(0, ctx->r23);
            goto L_800237C4;
    }
    goto skip_4;
    // 0x800237C0: negu        $s5, $s7
    ctx->r21 = SUB32(0, ctx->r23);
    skip_4:
L_800237C4:
    // 0x800237C4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800237C8: addiu       $a1, $a1, 0x57E0
    ctx->r5 = ADD32(ctx->r5, 0X57E0);
L_800237CC:
    // 0x800237CC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800237D0: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800237D4: beq         $v0, $zero, L_80023824
    if (ctx->r2 == 0) {
        // 0x800237D8: sll         $v0, $s1, 16
        ctx->r2 = S32(ctx->r17 << 16);
            goto L_80023824;
    }
    // 0x800237D8: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x800237DC: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800237E0: slti        $v0, $v1, 0xAB
    ctx->r2 = SIGNED(ctx->r3) < 0XAB ? 1 : 0;
    // 0x800237E4: beq         $v0, $zero, L_800237F4
    if (ctx->r2 == 0) {
        // 0x800237E8: addiu       $v0, $s2, -0x5
        ctx->r2 = ADD32(ctx->r18, -0X5);
            goto L_800237F4;
    }
    // 0x800237E8: addiu       $v0, $s2, -0x5
    ctx->r2 = ADD32(ctx->r18, -0X5);
    // 0x800237EC: j           L_80023824
    // 0x800237F0: subu        $s2, $v0, $fp
    ctx->r18 = SUB32(ctx->r2, ctx->r30);
        goto L_80023824;
    // 0x800237F0: subu        $s2, $v0, $fp
    ctx->r18 = SUB32(ctx->r2, ctx->r30);
L_800237F4:
    // 0x800237F4: slti        $v0, $v1, 0xBE
    ctx->r2 = SIGNED(ctx->r3) < 0XBE ? 1 : 0;
    // 0x800237F8: bne         $v0, $zero, L_80023808
    if (ctx->r2 != 0) {
        // 0x800237FC: addiu       $v0, $s2, 0x5
        ctx->r2 = ADD32(ctx->r18, 0X5);
            goto L_80023808;
    }
    // 0x800237FC: addiu       $v0, $s2, 0x5
    ctx->r2 = ADD32(ctx->r18, 0X5);
    // 0x80023800: j           L_80023824
    // 0x80023804: addu        $s2, $fp, $v0
    ctx->r18 = ADD32(ctx->r30, ctx->r2);
        goto L_80023824;
    // 0x80023804: addu        $s2, $fp, $v0
    ctx->r18 = ADD32(ctx->r30, ctx->r2);
L_80023808:
    // 0x80023808: lw          $v0, 0x68($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X68);
    // 0x8002380C: lh          $v0, 0xC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0XC);
    // 0x80023810: bne         $v0, $zero, L_80023824
    if (ctx->r2 != 0) {
        // 0x80023814: addu        $s2, $v0, $zero
        ctx->r18 = ADD32(ctx->r2, 0);
            goto L_80023824;
    }
    // 0x80023814: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80023818: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    // 0x8002381C: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x80023820: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_80023824:
    // 0x80023824: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x80023828: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
    // 0x8002382C: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x80023830: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80023834: addiu       $a2, $a2, 0x46A8
    ctx->r6 = ADD32(ctx->r6, 0X46A8);
    // 0x80023838: lhu         $a0, 0x0($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X0);
    // 0x8002383C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80023840: addiu       $a1, $a1, 0x3A0
    ctx->r5 = ADD32(ctx->r5, 0X3A0);
    // 0x80023844: xori        $v1, $t0, 0x1
    ctx->r3 = ctx->r8 ^ 0X1;
    // 0x80023848: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8002384C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80023850: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80023854: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80023858: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8002385C: and         $v1, $s2, $v1
    ctx->r3 = ctx->r18 & ctx->r3;
    // 0x80023860: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80023864: sh          $a0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r4;
    // 0x80023868: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8002386C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x80023870: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80023874: lh          $v1, 0x3294($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X3294);
    // 0x80023878: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8002387C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023880: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80023884: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80023888: beq         $v1, $zero, L_80023898
    if (ctx->r3 == 0) {
        // 0x8002388C: nop
    
            goto L_80023898;
    }
    // 0x8002388C: nop

    // 0x80023890: j           L_800238A0
    // 0x80023894: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
        goto L_800238A0;
    // 0x80023894: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
L_80023898:
    // 0x80023898: bgez        $v0, L_800238A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002389C: addu        $v0, $a0, $a1
        ctx->r2 = ADD32(ctx->r4, ctx->r5);
            goto L_800238A4;
    }
    // 0x8002389C: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
L_800238A0:
    // 0x800238A0: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
L_800238A4:
    // 0x800238A4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800238A8: addiu       $v1, $v1, 0x3A0
    ctx->r3 = ADD32(ctx->r3, 0X3A0);
    // 0x800238AC: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800238B0: bgtzl       $v0, L_800238B8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800238B4: sh          $zero, 0x0($v1)
        MEM_H(0X0, ctx->r3) = 0;
            goto L_800238B8;
    }
    goto skip_5;
    // 0x800238B4: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    skip_5:
L_800238B8:
    // 0x800238B8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800238BC: addiu       $v1, $v1, 0x46A8
    ctx->r3 = ADD32(ctx->r3, 0X46A8);
    // 0x800238C0: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800238C4: slti        $v0, $v0, 0x667
    ctx->r2 = SIGNED(ctx->r2) < 0X667 ? 1 : 0;
    // 0x800238C8: bne         $v0, $zero, L_800238D4
    if (ctx->r2 != 0) {
        // 0x800238CC: addiu       $v0, $zero, 0x666
        ctx->r2 = ADD32(0, 0X666);
            goto L_800238D4;
    }
    // 0x800238CC: addiu       $v0, $zero, 0x666
    ctx->r2 = ADD32(0, 0X666);
    // 0x800238D0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_800238D4:
    // 0x800238D4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800238D8: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800238DC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800238E0: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800238E4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800238E8: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800238EC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800238F0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800238F4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800238F8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800238FC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80023900: jr          $ra
    // 0x80023904: nop

    return;
    // 0x80023904: nop

;}
RECOMP_FUNC void func_80023908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023908: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8002390C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80023910: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80023914: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80023918: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8002391C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80023920: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80023924: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80023928: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002392C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80023930: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80023934: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80023938: lw          $v0, 0xBC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XBC);
    // 0x8002393C: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x80023940: addiu       $s5, $s5, 0x31C0
    ctx->r21 = ADD32(ctx->r21, 0X31C0);
    // 0x80023944: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    // 0x80023948: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8002394C: bne         $v0, $zero, L_80023A30
    if (ctx->r2 != 0) {
        // 0x80023950: sw          $a2, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r6;
            goto L_80023A30;
    }
    // 0x80023950: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x80023954: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80023958: lw          $v0, -0x307C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X307C);
    // 0x8002395C: beq         $v0, $zero, L_8002396C
    if (ctx->r2 == 0) {
        // 0x80023960: andi        $v0, $v0, 0x7000
        ctx->r2 = ctx->r2 & 0X7000;
            goto L_8002396C;
    }
    // 0x80023960: andi        $v0, $v0, 0x7000
    ctx->r2 = ctx->r2 & 0X7000;
    // 0x80023964: beq         $v0, $zero, L_80023A30
    if (ctx->r2 == 0) {
        // 0x80023968: nop
    
            goto L_80023A30;
    }
    // 0x80023968: nop

L_8002396C:
    // 0x8002396C: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x80023970: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80023974: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x80023978: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x8002397C: lw          $s1, -0x1034($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X1034);
    // 0x80023980: jal         0x800306EC
    // 0x80023984: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80023984: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    after_0:
    // 0x80023988: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8002398C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023990: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x80023994: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
    // 0x80023998: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002399C: blez        $a0, L_80023A24
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800239A0: addiu       $v1, $s1, -0x2
        ctx->r3 = ADD32(ctx->r17, -0X2);
            goto L_80023A24;
    }
    // 0x800239A0: addiu       $v1, $s1, -0x2
    ctx->r3 = ADD32(ctx->r17, -0X2);
    // 0x800239A4: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800239A8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800239AC: sll         $fp, $v0, 3
    ctx->r30 = S32(ctx->r2 << 3);
    // 0x800239B0: lui         $s7, 0x4F00
    ctx->r23 = S32(0X4F00 << 16);
    // 0x800239B4: ori         $s7, $s7, 0x35B6
    ctx->r23 = ctx->r23 | 0X35B6;
    // 0x800239B8: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x800239BC: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    // 0x800239C0: addiu       $s1, $zero, 0x9B
    ctx->r17 = ADD32(0, 0X9B);
L_800239C4:
    // 0x800239C4: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
    // 0x800239C8: addu        $v0, $fp, $s1
    ctx->r2 = ADD32(ctx->r30, ctx->r17);
    // 0x800239CC: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    // 0x800239D0: sh          $a2, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r6;
    // 0x800239D4: addiu       $a2, $zero, 0x500
    ctx->r6 = ADD32(0, 0X500);
    // 0x800239D8: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // 0x800239DC: sw          $s7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r23;
    // 0x800239E0: sw          $a2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r6;
    // 0x800239E4: ori         $v1, $v1, 0x20
    ctx->r3 = ctx->r3 | 0X20;
    // 0x800239E8: jal         0x80023E44
    // 0x800239EC: sh          $v1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x800239EC: sh          $v1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r3;
    after_1:
    // 0x800239F0: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x800239F4: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x800239F8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800239FC: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80023A00: addiu       $v0, $v0, 0x790
    ctx->r2 = ADD32(ctx->r2, 0X790);
    // 0x80023A04: sh          $v0, 0x70($v1)
    MEM_H(0X70, ctx->r3) = ctx->r2;
    // 0x80023A08: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80023A0C: addiu       $s1, $s1, 0xF
    ctx->r17 = ADD32(ctx->r17, 0XF);
    // 0x80023A10: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80023A14: sw          $v0, 0xBC($s2)
    MEM_W(0XBC, ctx->r18) = ctx->r2;
    // 0x80023A18: slt         $v0, $s3, $s6
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80023A1C: bne         $v0, $zero, L_800239C4
    if (ctx->r2 != 0) {
        // 0x80023A20: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800239C4;
    }
    // 0x80023A20: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80023A24:
    // 0x80023A24: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x80023A28: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023A2C: sw          $a2, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r6;
L_80023A30:
    // 0x80023A30: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80023A34: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80023A38: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80023A3C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80023A40: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80023A44: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80023A48: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80023A4C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80023A50: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80023A54: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80023A58: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80023A5C: jr          $ra
    // 0x80023A60: nop

    return;
    // 0x80023A60: nop

    // 0x80023A64: nop

    // 0x80023A68: nop

    // 0x80023A6C: nop

;}
RECOMP_FUNC void func_80023A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023A70: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80023A74: lhu         $v0, 0x475C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X475C);
    // FALLTHROUGH: func_80023A70 falls into func_80023A78
    func_80023A78(rdram, ctx);
;}
RECOMP_FUNC void func_80023A78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023A78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023A7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023A80: beq         $v0, $zero, L_80023ACC
    if (ctx->r2 == 0) {
        // 0x80023A84: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80023ACC;
    }
    // 0x80023A84: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80023A88: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80023A8C: lhu         $v0, 0x3228($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3228);
    // 0x80023A90: bne         $v0, $zero, L_80023ACC
    if (ctx->r2 != 0) {
        // 0x80023A94: nop
    
            goto L_80023ACC;
    }
    // 0x80023A94: nop

    // 0x80023A98: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023A9C: sh          $zero, -0x59C0($at)
    MEM_H(-0X59C0, ctx->r1) = 0;
    // 0x80023AA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023AA4: sh          $zero, -0x59FC($at)
    MEM_H(-0X59FC, ctx->r1) = 0;
    // 0x80023AA8: jal         0x80023AE0
    // 0x80023AAC: nop

    func_80023AE0(rdram, ctx);
        goto after_0;
    // 0x80023AAC: nop

    after_0:
    // 0x80023AB0: jal         0x80023B08
    // 0x80023AB4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_80023B08(rdram, ctx);
        goto after_1;
    // 0x80023AB4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80023AB8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80023ABC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023AC0: sh          $s0, -0x59C0($at)
    MEM_H(-0X59C0, ctx->r1) = ctx->r16;
    // 0x80023AC4: jal         0x800158E0
    // 0x80023AC8: nop

    func_800158E0(rdram, ctx);
        goto after_2;
    // 0x80023AC8: nop

    after_2:
L_80023ACC:
    // 0x80023ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023AD0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80023AD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023AD8: jr          $ra
    // 0x80023ADC: nop

    return;
    // 0x80023ADC: nop

;}
RECOMP_FUNC void func_80023AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023AE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023AE4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80023AE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80023AEC: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, 0X120);
    // 0x80023AF0: jal         0x80023B30
    // 0x80023AF4: nop

    func_80023B30(rdram, ctx);
        goto after_0;
    // 0x80023AF4: nop

    after_0:
    // 0x80023AF8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80023AFC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80023B00: jr          $ra
    // 0x80023B04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80023B04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80023B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023B08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023B0C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80023B10: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80023B14: addiu       $a0, $a0, -0x7464
    ctx->r4 = ADD32(ctx->r4, -0X7464);
    // 0x80023B18: jal         0x80023B30
    // 0x80023B1C: nop

    func_80023B30(rdram, ctx);
        goto after_0;
    // 0x80023B1C: nop

    after_0:
    // 0x80023B20: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80023B24: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80023B28: jr          $ra
    // 0x80023B2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80023B2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80023B30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023B30: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80023B34: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80023B38: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80023B3C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80023B40: addu        $s5, $s0, $zero
    ctx->r21 = ADD32(ctx->r16, 0);
    // 0x80023B44: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80023B48: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80023B4C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80023B50: lui         $s1, 0xFFFF
    ctx->r17 = S32(0XFFFF << 16);
    // 0x80023B54: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80023B58: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x80023B5C: addiu       $s4, $s4, 0x4E0A
    ctx->r20 = ADD32(ctx->r20, 0X4E0A);
    // 0x80023B60: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80023B64: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x80023B68: addiu       $s3, $s3, 0x2580
    ctx->r19 = ADD32(ctx->r19, 0X2580);
    // 0x80023B6C: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
L_80023B70:
    // 0x80023B70: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80023B74:
    // 0x80023B74: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80023B78: sltiu       $v1, $s0, 0x1
    ctx->r3 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80023B7C: xor         $v0, $s0, $v0
    ctx->r2 = ctx->r16 ^ ctx->r2;
    // 0x80023B80: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80023B84: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80023B88: bne         $v1, $zero, L_80023E1C
    if (ctx->r3 != 0) {
        // 0x80023B8C: andi        $v0, $s2, 0xFFFF
        ctx->r2 = ctx->r18 & 0XFFFF;
            goto L_80023E1C;
    }
    // 0x80023B8C: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x80023B90: beq         $s0, $s5, L_80023E1C
    if (ctx->r16 == ctx->r21) {
        // 0x80023B94: nop
    
            goto L_80023E1C;
    }
    // 0x80023B94: nop

    // 0x80023B98: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x80023B9C: lhu         $a2, 0x6C($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X6C);
    // 0x80023BA0: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80023BA4: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80023BA8: and         $a0, $a0, $s1
    ctx->r4 = ctx->r4 & ctx->r17;
    // 0x80023BAC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80023BB0: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80023BB4: andi        $v0, $a2, 0x8000
    ctx->r2 = ctx->r6 & 0X8000;
    // 0x80023BB8: bne         $v0, $zero, L_80023B70
    if (ctx->r2 != 0) {
        // 0x80023BBC: sw          $v1, 0x30($s0)
        MEM_W(0X30, ctx->r16) = ctx->r3;
            goto L_80023B70;
    }
    // 0x80023BBC: sw          $v1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r3;
    // 0x80023BC0: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80023BC4: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x80023BC8: lw          $t1, 0x7C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X7C);
    // 0x80023BCC: andi        $v0, $a2, 0x20
    ctx->r2 = ctx->r6 & 0X20;
    // 0x80023BD0: bne         $v0, $zero, L_80023BFC
    if (ctx->r2 != 0) {
        // 0x80023BD4: addu        $t4, $a0, $zero
        ctx->r12 = ADD32(ctx->r4, 0);
            goto L_80023BFC;
    }
    // 0x80023BD4: addu        $t4, $a0, $zero
    ctx->r12 = ADD32(ctx->r4, 0);
    // 0x80023BD8: andi        $v0, $a2, 0x10
    ctx->r2 = ctx->r6 & 0X10;
    // 0x80023BDC: bne         $v0, $zero, L_80023BF0
    if (ctx->r2 != 0) {
        // 0x80023BE0: nop
    
            goto L_80023BF0;
    }
    // 0x80023BE0: nop

    // 0x80023BE4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80023BE8: lw          $v0, 0x46A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X46A8);
    // 0x80023BEC: subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
L_80023BF0:
    // 0x80023BF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80023BF4: lw          $v0, 0x3A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A0);
    // 0x80023BF8: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
L_80023BFC:
    // 0x80023BFC: srl         $v1, $a3, 16
    ctx->r3 = S32(U32(ctx->r7) >> 16);
    // 0x80023C00: srl         $v0, $a1, 16
    ctx->r2 = S32(U32(ctx->r5) >> 16);
    // 0x80023C04: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80023C08: or          $a3, $v1, $v0
    ctx->r7 = ctx->r3 | ctx->r2;
    // 0x80023C0C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80023C10: and         $a0, $a2, $s1
    ctx->r4 = ctx->r6 & ctx->r17;
    // 0x80023C14: subu        $v0, $a2, $t1
    ctx->r2 = SUB32(ctx->r6, ctx->r9);
    // 0x80023C18: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80023C1C: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80023C20: sra         $v1, $a0, 16
    ctx->r3 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80023C24: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80023C28: sra         $v0, $t1, 16
    ctx->r2 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80023C2C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80023C30: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80023C34: lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X22);
    // 0x80023C38: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x80023C3C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80023C40: beq         $v0, $zero, L_80023C58
    if (ctx->r2 == 0) {
        // 0x80023C44: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80023C58;
    }
    // 0x80023C44: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80023C48: and         $t1, $t1, $s1
    ctx->r9 = ctx->r9 & ctx->r17;
    // 0x80023C4C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80023C50: or          $t1, $t1, $v0
    ctx->r9 = ctx->r9 | ctx->r2;
    // 0x80023C54: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
L_80023C58:
    // 0x80023C58: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x80023C5C: subu        $v0, $a0, $t1
    ctx->r2 = SUB32(ctx->r4, ctx->r9);
    // 0x80023C60: and         $a0, $a0, $s1
    ctx->r4 = ctx->r4 & ctx->r17;
    // 0x80023C64: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80023C68: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80023C6C: sra         $v0, $a0, 16
    ctx->r2 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80023C70: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80023C74: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80023C78: subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x80023C7C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80023C80: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80023C84: addu        $t3, $a1, $zero
    ctx->r11 = ADD32(ctx->r5, 0);
    // 0x80023C88: addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // 0x80023C8C: and         $a1, $a1, $s1
    ctx->r5 = ctx->r5 & ctx->r17;
    // 0x80023C90: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80023C94: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x80023C98: sra         $v0, $a1, 16
    ctx->r2 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80023C9C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80023CA0: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80023CA4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80023CA8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80023CAC: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x80023CB0: sw          $a1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r5;
    // 0x80023CB4: lh          $v1, 0x0($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X0);
    // 0x80023CB8: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80023CBC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023CC0: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x80023CC4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80023CC8: beq         $v0, $zero, L_80023E0C
    if (ctx->r2 == 0) {
        // 0x80023CCC: nop
    
            goto L_80023E0C;
    }
    // 0x80023CCC: nop

    // 0x80023CD0: lh          $v0, -0x2($s4)
    ctx->r2 = MEM_H(ctx->r20, -0X2);
    // 0x80023CD4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80023CD8: slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80023CDC: beq         $v0, $zero, L_80023E0C
    if (ctx->r2 == 0) {
        // 0x80023CE0: addu        $v0, $a2, $a0
        ctx->r2 = ADD32(ctx->r6, ctx->r4);
            goto L_80023E0C;
    }
    // 0x80023CE0: addu        $v0, $a2, $a0
    ctx->r2 = ADD32(ctx->r6, ctx->r4);
    // 0x80023CE4: and         $a2, $a2, $s1
    ctx->r6 = ctx->r6 & ctx->r17;
    // 0x80023CE8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80023CEC: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x80023CF0: sra         $v0, $a2, 16
    ctx->r2 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80023CF4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80023CF8: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80023CFC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80023D00: lh          $v1, 0x0($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X0);
    // 0x80023D04: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x80023D08: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023D0C: addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    // 0x80023D10: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80023D14: beq         $v1, $zero, L_80023E0C
    if (ctx->r3 == 0) {
        // 0x80023D18: sll         $v0, $a2, 16
        ctx->r2 = S32(ctx->r6 << 16);
            goto L_80023E0C;
    }
    // 0x80023D18: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x80023D1C: lh          $v1, 0x2($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X2);
    // 0x80023D20: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023D24: addiu       $v1, $v1, -0x80
    ctx->r3 = ADD32(ctx->r3, -0X80);
    // 0x80023D28: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80023D2C: bnel        $v1, $zero, L_80023DFC
    if (ctx->r3 != 0) {
        // 0x80023D30: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80023DFC;
    }
    goto skip_0;
    // 0x80023D30: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80023D34: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80023D38: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x80023D3C: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x80023D40: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80023D44: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80023D48: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x80023D4C: and         $a0, $a0, $s1
    ctx->r4 = ctx->r4 & ctx->r17;
    // 0x80023D50: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80023D54: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80023D58: srl         $v0, $a0, 16
    ctx->r2 = S32(U32(ctx->r4) >> 16);
    // 0x80023D5C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80023D60: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80023D64: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80023D68: addu        $a1, $t3, $zero
    ctx->r5 = ADD32(ctx->r11, 0);
    // 0x80023D6C: subu        $v0, $a0, $t1
    ctx->r2 = SUB32(ctx->r4, ctx->r9);
    // 0x80023D70: and         $a0, $a0, $s1
    ctx->r4 = ctx->r4 & ctx->r17;
    // 0x80023D74: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80023D78: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80023D7C: sra         $v0, $a0, 16
    ctx->r2 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80023D80: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80023D84: subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x80023D88: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80023D8C: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80023D90: addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // 0x80023D94: and         $a1, $a1, $s1
    ctx->r5 = ctx->r5 & ctx->r17;
    // 0x80023D98: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80023D9C: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x80023DA0: sra         $v0, $a1, 16
    ctx->r2 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80023DA4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80023DA8: sra         $a3, $a0, 16
    ctx->r7 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80023DAC: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80023DB0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80023DB4: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x80023DB8: sw          $a1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r5;
    // 0x80023DBC: lh          $v1, 0x0($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X0);
    // 0x80023DC0: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80023DC4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023DC8: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x80023DCC: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80023DD0: beq         $v0, $zero, L_80023E0C
    if (ctx->r2 == 0) {
        // 0x80023DD4: addu        $a2, $t4, $zero
        ctx->r6 = ADD32(ctx->r12, 0);
            goto L_80023E0C;
    }
    // 0x80023DD4: addu        $a2, $t4, $zero
    ctx->r6 = ADD32(ctx->r12, 0);
    // 0x80023DD8: addu        $v0, $a2, $a0
    ctx->r2 = ADD32(ctx->r6, ctx->r4);
    // 0x80023DDC: lh          $v1, 0x2($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X2);
    // 0x80023DE0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80023DE4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023DE8: addiu       $v1, $v1, -0x80
    ctx->r3 = ADD32(ctx->r3, -0X80);
    // 0x80023DEC: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80023DF0: beq         $v1, $zero, L_80023E0C
    if (ctx->r3 == 0) {
        // 0x80023DF4: nop
    
            goto L_80023E0C;
    }
    // 0x80023DF4: nop

    // 0x80023DF8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80023DFC:
    // 0x80023DFC: jal         0x8005E784
    // 0x80023E00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8005E784(rdram, ctx);
        goto after_0;
    // 0x80023E00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80023E04: j           L_80023B74
    // 0x80023E08: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80023B74;
    // 0x80023E08: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80023E0C:
    // 0x80023E0C: jal         0x8005E750
    // 0x80023E10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8005E750(rdram, ctx);
        goto after_1;
    // 0x80023E10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80023E14: j           L_80023B74
    // 0x80023E18: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80023B74;
    // 0x80023E18: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80023E1C:
    // 0x80023E1C: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x80023E20: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80023E24: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80023E28: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80023E2C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80023E30: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80023E34: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80023E38: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80023E3C: jr          $ra
    // 0x80023E40: nop

    return;
    // 0x80023E40: nop

;}
RECOMP_FUNC void func_80023E44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023E44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80023E48: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80023E4C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80023E50: lw          $s0, 0x31DC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X31DC);
    // 0x80023E54: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80023E58: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80023E5C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80023E60: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023E64: sw          $v0, 0x31A4($at)
    MEM_W(0X31A4, ctx->r1) = ctx->r2;
    // 0x80023E68: jal         0x80024430
    // 0x80023E6C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    func_80024430(rdram, ctx);
        goto after_0;
    // 0x80023E6C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x80023E70: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80023E74: bne         $s1, $zero, L_80023E84
    if (ctx->r17 != 0) {
        // 0x80023E78: nop
    
            goto L_80023E84;
    }
    // 0x80023E78: nop

    // 0x80023E7C: jal         0x8005E178
    // 0x80023E80: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8005E178(rdram, ctx);
        goto after_1;
    // 0x80023E80: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
L_80023E84:
    // 0x80023E84: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80023E88: lw          $a1, 0x31A4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31A4);
    // 0x80023E8C: jal         0x80024858
    // 0x80023E90: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80024858(rdram, ctx);
        goto after_2;
    // 0x80023E90: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x80023E94: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80023E98: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80023E9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023EA0: sw          $v0, 0x3214($at)
    MEM_W(0X3214, ctx->r1) = ctx->r2;
    // 0x80023EA4: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x80023EA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023EAC: sw          $v1, 0x31E4($at)
    MEM_W(0X31E4, ctx->r1) = ctx->r3;
    // 0x80023EB0: lhu         $v0, 0x6C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6C);
    // 0x80023EB4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80023EB8: sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // 0x80023EBC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80023EC0: lw          $a1, 0x3214($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3214);
    // 0x80023EC4: andi        $v0, $a1, 0x10
    ctx->r2 = ctx->r5 & 0X10;
    // 0x80023EC8: beq         $v0, $zero, L_80023EEC
    if (ctx->r2 == 0) {
        // 0x80023ECC: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80023EEC;
    }
    // 0x80023ECC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80023ED0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80023ED4: lw          $a0, 0x31A4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31A4);
    // 0x80023ED8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80023EDC: jal         0x80016BA0
    // 0x80023EE0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80016BA0(rdram, ctx);
        goto after_3;
    // 0x80023EE0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_3:
    // 0x80023EE4: j           L_80023EF8
    // 0x80023EE8: nop

        goto L_80023EF8;
    // 0x80023EE8: nop

L_80023EEC:
    // 0x80023EEC: lhu         $v0, 0x22($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X22);
    // 0x80023EF0: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x80023EF4: sh          $v0, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r2;
L_80023EF8:
    // 0x80023EF8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80023EFC: addiu       $v0, $zero, 0x7FF
    ctx->r2 = ADD32(0, 0X7FF);
    // 0x80023F00: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023F04: sw          $v0, 0x31D8($at)
    MEM_W(0X31D8, ctx->r1) = ctx->r2;
    // 0x80023F08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023F0C: sw          $v1, 0x3200($at)
    MEM_W(0X3200, ctx->r1) = ctx->r3;
    // 0x80023F10: andi        $v1, $v1, 0x40
    ctx->r3 = ctx->r3 & 0X40;
    // 0x80023F14: beq         $v1, $zero, L_80023F38
    if (ctx->r3 == 0) {
        // 0x80023F18: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80023F38;
    }
    // 0x80023F18: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80023F1C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80023F20: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023F24: sw          $v0, 0x3214($at)
    MEM_W(0X3214, ctx->r1) = ctx->r2;
    // 0x80023F28: beq         $v0, $zero, L_80023F38
    if (ctx->r2 == 0) {
        // 0x80023F2C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80023F38;
    }
    // 0x80023F2C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80023F30: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023F34: sw          $v0, 0x31D8($at)
    MEM_W(0X31D8, ctx->r1) = ctx->r2;
L_80023F38:
    // 0x80023F38: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80023F3C: lw          $v0, 0x31D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31D8);
    // 0x80023F40: sh          $v0, 0x70($s1)
    MEM_H(0X70, ctx->r17) = ctx->r2;
    // 0x80023F44: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80023F48: lw          $v0, 0x3200($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3200);
    // 0x80023F4C: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x80023F50: beq         $v0, $zero, L_80023FEC
    if (ctx->r2 == 0) {
        // 0x80023F54: nop
    
            goto L_80023FEC;
    }
    // 0x80023F54: nop

    // 0x80023F58: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80023F5C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80023F60: lw          $v0, 0x31E4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31E4);
    // 0x80023F64: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80023F68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023F6C: sw          $a0, 0x31F4($at)
    MEM_W(0X31F4, ctx->r1) = ctx->r4;
    // 0x80023F70: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80023F74: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80023F78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023F7C: sw          $a1, 0x31F0($at)
    MEM_W(0X31F0, ctx->r1) = ctx->r5;
    // 0x80023F80: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80023F84: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x80023F88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023F8C: sw          $v1, 0x31EC($at)
    MEM_W(0X31EC, ctx->r1) = ctx->r3;
    // 0x80023F90: beq         $v0, $zero, L_80023FDC
    if (ctx->r2 == 0) {
        // 0x80023F94: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80023FDC;
    }
    // 0x80023F94: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80023F98: sra         $v1, $a0, 16
    ctx->r3 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80023F9C: sra         $v0, $a1, 16
    ctx->r2 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80023FA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023FA4: sw          $v1, 0x31F4($at)
    MEM_W(0X31F4, ctx->r1) = ctx->r3;
    // 0x80023FA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80023FAC: sw          $v0, 0x31F0($at)
    MEM_W(0X31F0, ctx->r1) = ctx->r2;
    // 0x80023FB0: lhu         $v0, 0x1E($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X1E);
    // 0x80023FB4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80023FB8: sh          $v1, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r3;
    // 0x80023FBC: sh          $v1, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r3;
    // 0x80023FC0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80023FC4: lw          $v0, 0x31F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31F0);
    // 0x80023FC8: lhu         $v1, 0x1C($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X1C);
    // 0x80023FCC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80023FD0: sh          $v0, 0x28($s1)
    MEM_H(0X28, ctx->r17) = ctx->r2;
    // 0x80023FD4: j           L_80023FEC
    // 0x80023FD8: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
        goto L_80023FEC;
    // 0x80023FD8: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
L_80023FDC:
    // 0x80023FDC: sw          $a0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r4;
    // 0x80023FE0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80023FE4: lw          $v0, 0x31F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31F0);
    // 0x80023FE8: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_80023FEC:
    // 0x80023FEC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80023FF0: lw          $v0, 0x3200($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3200);
    // 0x80023FF4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80023FF8: addiu       $v1, $v1, 0x31D8
    ctx->r3 = ADD32(ctx->r3, 0X31D8);
    // 0x80023FFC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80024000: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80024004: sw          $zero, 0x3214($at)
    MEM_W(0X3214, ctx->r1) = 0;
    // 0x80024008: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8002400C: beq         $v0, $zero, L_80024034
    if (ctx->r2 == 0) {
        // 0x80024010: nop
    
            goto L_80024034;
    }
    // 0x80024010: nop

    // 0x80024014: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80024018: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8002401C: sw          $v0, 0x3214($at)
    MEM_W(0X3214, ctx->r1) = ctx->r2;
    // 0x80024020: beq         $v0, $zero, L_80024034
    if (ctx->r2 == 0) {
        // 0x80024024: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80024034;
    }
    // 0x80024024: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80024028: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002402C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80024030: addiu       $v1, $v1, 0x31D8
    ctx->r3 = ADD32(ctx->r3, 0X31D8);
L_80024034:
    // 0x80024034: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80024038: sh          $v0, 0x82($s1)
    MEM_H(0X82, ctx->r17) = ctx->r2;
    // 0x8002403C: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    // 0x80024040: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80024044: beq         $v0, $zero, L_80024058
    if (ctx->r2 == 0) {
        // 0x80024048: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_80024058;
    }
    // 0x80024048: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8002404C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80024050: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80024054: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80024058:
    // 0x80024058: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002405C: sh          $v0, 0x80($s1)
    MEM_H(0X80, ctx->r17) = ctx->r2;
    // 0x80024060: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    // 0x80024064: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80024068: beq         $v0, $zero, L_8002408C
    if (ctx->r2 == 0) {
        // 0x8002406C: nop
    
            goto L_8002408C;
    }
    // 0x8002406C: nop

    // 0x80024070: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80024074: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80024078: sw          $a0, 0x3214($at)
    MEM_W(0X3214, ctx->r1) = ctx->r4;
    // 0x8002407C: beq         $a0, $zero, L_8002408C
    if (ctx->r4 == 0) {
        // 0x80024080: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8002408C;
    }
    // 0x80024080: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80024084: jal         0x80000540
    // 0x80024088: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80000540(rdram, ctx);
        goto after_4;
    // 0x80024088: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
L_8002408C:
    // 0x8002408C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80024090: lw          $v0, 0x3200($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3200);
    // 0x80024094: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80024098: beq         $v0, $zero, L_800240BC
    if (ctx->r2 == 0) {
        // 0x8002409C: nop
    
            goto L_800240BC;
    }
    // 0x8002409C: nop

    // 0x800240A0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800240A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800240A8: sw          $a1, 0x3214($at)
    MEM_W(0X3214, ctx->r1) = ctx->r5;
    // 0x800240AC: beq         $a1, $zero, L_800240BC
    if (ctx->r5 == 0) {
        // 0x800240B0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800240BC;
    }
    // 0x800240B0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800240B4: jal         0x800249B4
    // 0x800240B8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800249B4(rdram, ctx);
        goto after_5;
    // 0x800240B8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
L_800240BC:
    // 0x800240BC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800240C0: lw          $v0, 0x3200($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3200);
    // 0x800240C4: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800240C8: beq         $v0, $zero, L_800240F4
    if (ctx->r2 == 0) {
        // 0x800240CC: nop
    
            goto L_800240F4;
    }
    // 0x800240CC: nop

    // 0x800240D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800240D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800240D8: sw          $v0, 0x31F8($at)
    MEM_W(0X31F8, ctx->r1) = ctx->r2;
    // 0x800240DC: beq         $v0, $zero, L_800240F4
    if (ctx->r2 == 0) {
        // 0x800240E0: nop
    
            goto L_800240F4;
    }
    // 0x800240E0: nop

    // 0x800240E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800240E8: sw          $s1, 0x31A0($at)
    MEM_W(0X31A0, ctx->r1) = ctx->r17;
    // 0x800240EC: jalr        $v0
    // 0x800240F0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x800240F0: nop

    after_6:
L_800240F4:
    // 0x800240F4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800240F8: lw          $v0, 0x3200($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3200);
    // 0x800240FC: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80024100: beq         $v0, $zero, L_80024114
    if (ctx->r2 == 0) {
        // 0x80024104: addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
            goto L_80024114;
    }
    // 0x80024104: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x80024108: jal         0x80024564
    // 0x8002410C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80024564(rdram, ctx);
        goto after_7;
    // 0x8002410C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_7:
    // 0x80024110: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_80024114:
    // 0x80024114: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80024118: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002411C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80024120: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80024124: jr          $ra
    // 0x80024128: nop

    return;
    // 0x80024128: nop

;}
RECOMP_FUNC void func_8002412C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002412C: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x80024130: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x80024134: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x80024138: div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // 0x8002413C: bne         $v0, $zero, L_80024148
    if (ctx->r2 != 0) {
        // 0x80024140: nop
    
            goto L_80024148;
    }
    // 0x80024140: nop

    // 0x80024144: break       7
    do_break(2147631428);
L_80024148:
    // 0x80024148: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002414C: bne         $v0, $at, L_80024160
    if (ctx->r2 != ctx->r1) {
        // 0x80024150: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024160;
    }
    // 0x80024150: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024154: bne         $v1, $at, L_80024160
    if (ctx->r3 != ctx->r1) {
        // 0x80024158: nop
    
            goto L_80024160;
    }
    // 0x80024158: nop

    // 0x8002415C: break       6
    do_break(2147631452);
L_80024160:
    // 0x80024160: mflo        $v0
    ctx->r2 = lo;
    // 0x80024164: nop

    // 0x80024168: nop

    // 0x8002416C: sh          $v0, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r2;
    // 0x80024170: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x80024174: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80024178: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8002417C: div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // 0x80024180: bne         $v0, $zero, L_8002418C
    if (ctx->r2 != 0) {
        // 0x80024184: nop
    
            goto L_8002418C;
    }
    // 0x80024184: nop

    // 0x80024188: break       7
    do_break(2147631496);
L_8002418C:
    // 0x8002418C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024190: bne         $v0, $at, L_800241A4
    if (ctx->r2 != ctx->r1) {
        // 0x80024194: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800241A4;
    }
    // 0x80024194: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024198: bne         $v1, $at, L_800241A4
    if (ctx->r3 != ctx->r1) {
        // 0x8002419C: nop
    
            goto L_800241A4;
    }
    // 0x8002419C: nop

    // 0x800241A0: break       6
    do_break(2147631520);
L_800241A4:
    // 0x800241A4: mflo        $v0
    ctx->r2 = lo;
    // 0x800241A8: nop

    // 0x800241AC: nop

    // 0x800241B0: jr          $ra
    // 0x800241B4: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    return;
    // 0x800241B4: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
;}
RECOMP_FUNC void func_800241B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800241B8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800241BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800241C0: addiu       $t0, $t0, 0x120
    ctx->r8 = ADD32(ctx->r8, 0X120);
    // 0x800241C4: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x800241C8: j           L_80024210
    // 0x800241CC: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
        goto L_80024210;
    // 0x800241CC: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
L_800241D0:
    // 0x800241D0: lh          $v1, 0x80($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X80);
    // 0x800241D4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800241D8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800241DC: beq         $v0, $zero, L_80024208
    if (ctx->r2 == 0) {
        // 0x800241E0: addu        $a2, $v1, $zero
        ctx->r6 = ADD32(ctx->r3, 0);
            goto L_80024208;
    }
    // 0x800241E0: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800241E4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x800241E8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800241EC: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x800241F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800241F4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800241F8: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800241FC: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x80024200: j           L_80024210
    // 0x80024204: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
        goto L_80024210;
    // 0x80024204: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
L_80024208:
    // 0x80024208: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8002420C: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
L_80024210:
    // 0x80024210: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80024214: bne         $a0, $t0, L_800241D0
    if (ctx->r4 != ctx->r8) {
        // 0x80024218: sll         $v0, $a3, 16
        ctx->r2 = S32(ctx->r7 << 16);
            goto L_800241D0;
    }
    // 0x80024218: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x8002421C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80024220: jr          $ra
    // 0x80024224: nop

    return;
    // 0x80024224: nop

;}
RECOMP_FUNC void func_80024228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024228: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002422C: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, 0X120);
    // 0x80024230: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80024234: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80024238: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8002423C: beq         $v0, $a0, L_800242B8
    if (ctx->r2 == ctx->r4) {
        // 0x80024240: nop
    
            goto L_800242B8;
    }
    // 0x80024240: nop

    // 0x80024244: sw          $t0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r8;
    // 0x80024248: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002424C: sw          $t0, 0x124($at)
    MEM_W(0X124, ctx->r1) = ctx->r8;
    // 0x80024250: beq         $a0, $t0, L_800242B8
    if (ctx->r4 == ctx->r8) {
        // 0x80024254: nop
    
            goto L_800242B8;
    }
    // 0x80024254: nop

    // 0x80024258: addu        $t1, $t0, $zero
    ctx->r9 = ADD32(ctx->r8, 0);
L_8002425C:
    // 0x8002425C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80024260: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80024264: beq         $v1, $t1, L_80024294
    if (ctx->r3 == ctx->r9) {
        // 0x80024268: nop
    
            goto L_80024294;
    }
    // 0x80024268: nop

    // 0x8002426C: lhu         $a1, 0x80($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X80);
    // 0x80024270: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80024274: addiu       $a2, $a2, 0x120
    ctx->r6 = ADD32(ctx->r6, 0X120);
L_80024278:
    // 0x80024278: lhu         $v0, 0x80($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X80);
    // 0x8002427C: sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80024280: bne         $v0, $zero, L_80024294
    if (ctx->r2 != 0) {
        // 0x80024284: nop
    
            goto L_80024294;
    }
    // 0x80024284: nop

    // 0x80024288: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8002428C: bne         $v1, $a2, L_80024278
    if (ctx->r3 != ctx->r6) {
        // 0x80024290: nop
    
            goto L_80024278;
    }
    // 0x80024290: nop

L_80024294:
    // 0x80024294: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80024298: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8002429C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x800242A0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800242A4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800242A8: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800242AC: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x800242B0: bne         $a0, $t0, L_8002425C
    if (ctx->r4 != ctx->r8) {
        // 0x800242B4: nop
    
            goto L_8002425C;
    }
    // 0x800242B4: nop

L_800242B8:
    // 0x800242B8: jr          $ra
    // 0x800242BC: nop

    return;
    // 0x800242BC: nop

;}
RECOMP_FUNC void func_800242C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800242C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800242C4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800242C8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800242CC: addiu       $s0, $s0, 0x120
    ctx->r16 = ADD32(ctx->r16, 0X120);
    // 0x800242D0: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
    // 0x800242D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800242D8: sh          $v0, 0x4E0A($at)
    MEM_H(0X4E0A, ctx->r1) = ctx->r2;
    // 0x800242DC: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // 0x800242E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800242E4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800242E8: sh          $zero, 0x2582($at)
    MEM_H(0X2582, ctx->r1) = 0;
    // 0x800242EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800242F0: sh          $zero, 0x2580($at)
    MEM_H(0X2580, ctx->r1) = 0;
    // 0x800242F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800242F8: sh          $v0, 0x4E08($at)
    MEM_H(0X4E08, ctx->r1) = ctx->r2;
    // 0x800242FC: sw          $s0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r16;
    // 0x80024300: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024304: sw          $s0, 0x124($at)
    MEM_W(0X124, ctx->r1) = ctx->r16;
    // 0x80024308: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8002430C: addiu       $s0, $s0, -0x7464
    ctx->r16 = ADD32(ctx->r16, -0X7464);
    // 0x80024310: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x80024314: ori         $a2, $a2, 0x8E70
    ctx->r6 = ctx->r6 | 0X8E70;
    // 0x80024318: sw          $s0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r16;
    // 0x8002431C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80024320: sw          $s0, -0x7460($at)
    MEM_W(-0X7460, ctx->r1) = ctx->r16;
    // 0x80024324: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x80024328: addiu       $s0, $s0, 0x67A0
    ctx->r16 = ADD32(ctx->r16, 0X67A0);
    // 0x8002432C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80024330: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80024334: sw          $zero, 0x4708($at)
    MEM_W(0X4708, ctx->r1) = 0;
    // 0x80024338: jal         0x8007DEC0
    // 0x8002433C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8007DEC0(rdram, ctx);
        goto after_0;
    // 0x8002433C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80024340: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    // 0x80024344: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
    // 0x80024348: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002434C: sw          $s0, 0x404C($at)
    MEM_W(0X404C, ctx->r1) = ctx->r16;
    // 0x80024350: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80024354: sh          $v0, 0x4704($at)
    MEM_H(0X4704, ctx->r1) = ctx->r2;
L_80024358:
    // 0x80024358: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x8002435C: addiu       $s0, $s0, 0xCC
    ctx->r16 = ADD32(ctx->r16, 0XCC);
    // 0x80024360: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80024364: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80024368: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8002436C: bne         $v0, $zero, L_80024358
    if (ctx->r2 != 0) {
        // 0x80024370: sw          $s0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r16;
            goto L_80024358;
    }
    // 0x80024370: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x80024374: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80024378: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8002437C: sw          $v1, -0x6878($at)
    MEM_W(-0X6878, ctx->r1) = ctx->r3;
    // 0x80024380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024384: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80024388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002438C: jr          $ra
    // 0x80024390: nop

    return;
    // 0x80024390: nop

;}
RECOMP_FUNC void func_80024394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024398: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002439C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800243A0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800243A4: addiu       $v0, $v0, 0x67A0
    ctx->r2 = ADD32(ctx->r2, 0X67A0);
    // 0x800243A8: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800243AC: bne         $v0, $zero, L_800243C8
    if (ctx->r2 != 0) {
        // 0x800243B0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800243C8;
    }
    // 0x800243B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800243B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800243B8: addiu       $v0, $v0, -0x9F0
    ctx->r2 = ADD32(ctx->r2, -0X9F0);
    // 0x800243BC: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800243C0: bne         $v0, $zero, L_800243D0
    if (ctx->r2 != 0) {
        // 0x800243C4: nop
    
            goto L_800243D0;
    }
    // 0x800243C4: nop

L_800243C8:
    // 0x800243C8: jal         0x8005E178
    // 0x800243CC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_8005E178(rdram, ctx);
        goto after_0;
    // 0x800243CC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_0:
L_800243D0:
    // 0x800243D0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800243D4: addiu       $a0, $a0, 0x67A0
    ctx->r4 = ADD32(ctx->r4, 0X67A0);
    // 0x800243D8: subu        $a0, $s0, $a0
    ctx->r4 = SUB32(ctx->r16, ctx->r4);
    // 0x800243DC: lui         $v0, 0xA0A0
    ctx->r2 = S32(0XA0A0 << 16);
    // 0x800243E0: ori         $v0, $v0, 0xA0A1
    ctx->r2 = ctx->r2 | 0XA0A1;
    // 0x800243E4: multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800243E8: mfhi        $a1
    ctx->r5 = hi;
    // 0x800243EC: nop

    // 0x800243F0: nop

    // 0x800243F4: srl         $v1, $a1, 7
    ctx->r3 = S32(U32(ctx->r5) >> 7);
    // 0x800243F8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800243FC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024400: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80024404: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024408: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002440C: beq         $a0, $v0, L_8002441C
    if (ctx->r4 == ctx->r2) {
        // 0x80024410: nop
    
            goto L_8002441C;
    }
    // 0x80024410: nop

    // 0x80024414: jal         0x8005E178
    // 0x80024418: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_8005E178(rdram, ctx);
        goto after_1;
    // 0x80024418: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_1:
L_8002441C:
    // 0x8002441C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024420: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80024424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024428: jr          $ra
    // 0x8002442C: nop

    return;
    // 0x8002442C: nop

;}
