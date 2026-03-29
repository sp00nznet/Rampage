#include <stdio.h>
#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_8005D8DC(uint8_t* rdram, recomp_context* ctx);
void func_8005D9F0(uint8_t* rdram, recomp_context* ctx);
void func_8005DA28(uint8_t* rdram, recomp_context* ctx);
void func_8005DB1C(uint8_t* rdram, recomp_context* ctx);
void func_8005DFF0(uint8_t* rdram, recomp_context* ctx);
void func_8005E06C(uint8_t* rdram, recomp_context* ctx);
void func_8005E0C8(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_8005D0A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D0A0: jr          $ra
    // 0x8005D0A4: nop

    return;
    // 0x8005D0A4: nop

;}
RECOMP_FUNC void func_8005D0A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D0A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D0AC: addu        $a0, $a1, $a2
    ctx->r4 = ADD32(ctx->r5, ctx->r6);
    // 0x8005D0B0: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    // 0x8005D0B4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8005D0B8: lw          $a2, -0x1D38($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X1D38);
    // 0x8005D0BC: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x8005D0C0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005D0C4: jal         0x8006FA08
    // 0x8005D0C8: ori         $a3, $a3, 0x86A0
    ctx->r7 = ctx->r7 | 0X86A0;
    func_8006FA08(rdram, ctx);
        goto after_0;
    // 0x8005D0C8: ori         $a3, $a3, 0x86A0
    ctx->r7 = ctx->r7 | 0X86A0;
    after_0:
    // 0x8005D0CC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005D0D0: bnel        $v0, $zero, L_8005D0D8
    if (ctx->r2 != 0) {
        // 0x8005D0D4: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8005D0D8;
    }
    goto skip_0;
    // 0x8005D0D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
L_8005D0D8:
    // 0x8005D0D8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005D0DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005D0E0: jr          $ra
    // 0x8005D0E4: nop

    return;
    // 0x8005D0E4: nop

;}
RECOMP_FUNC void func_8005D0E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D0E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D0EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D0F0: jal         0x8006CC0C
    // 0x8005D0F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8006CC0C(rdram, ctx);
        goto after_0;
    // 0x8005D0F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8005D0F8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005D0FC: jal         0x8006D730
    // 0x8005D100: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8006D730(rdram, ctx);
        goto after_1;
    // 0x8005D100: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8005D104: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005D108: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005D10C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8005D110: addiu       $a2, $a2, 0x3ED0
    ctx->r6 = ADD32(ctx->r6, 0X3ED0);
    // 0x8005D114: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005D118: jal         0x80070FF0
    // 0x8005D11C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80070FF0(rdram, ctx);
        goto after_2;
    // 0x8005D11C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x8005D120: jal         0x8006CC0C
    // 0x8005D124: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_8006CC0C(rdram, ctx);
        goto after_3;
    // 0x8005D124: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_3:
    // 0x8005D128: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005D12C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8005D130: jal         0x8006D7AC
    // 0x8005D134: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8006D7AC(rdram, ctx);
        goto after_4;
    // 0x8005D134: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8005D138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D13C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005D140: sw          $v0, -0x740($at)
    MEM_W(-0X740, ctx->r1) = ctx->r2;
    // 0x8005D144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D148: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005D14C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005D150: jr          $ra
    // 0x8005D154: nop

    return;
    // 0x8005D154: nop

;}
RECOMP_FUNC void func_8005D158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    fprintf(stderr, "[R2-D158] ENTERED\n"); fflush(stderr);
    // 0x8005D158: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8005D15C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005D160: addiu       $a0, $a0, 0x3ED0
    ctx->r4 = ADD32(ctx->r4, 0X3ED0);
    // 0x8005D164: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005D168: addiu       $a1, $a1, 0x560
    ctx->r5 = ADD32(ctx->r5, 0X560);
    // 0x8005D16C: lui         $a2, 0x3
    ctx->r6 = S32(0X3 << 16);
    // 0x8005D170: ori         $a2, $a2, 0x2000
    ctx->r6 = ctx->r6 | 0X2000;
    // 0x8005D174: sw          $ra, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r31;
    // 0x8005D178: sw          $s3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r19;
    // 0x8005D17C: sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
    // 0x8005D180: sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // 0x8005D184: jal         0x80070FB0
    // 0x8005D188: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    func_80070FB0(rdram, ctx);
        goto after_0;
    // 0x8005D188: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    after_0:
    fprintf(stderr, "[R2-D158] #0 osCreateMesgQueue done\n"); fflush(stderr);
    // 0x8005D18C: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8005D190: jal         0x8005DFF0
    // 0x8005D194: ori         $a0, $a0, 0x86A0
    ctx->r4 = ctx->r4 | 0X86A0;
    func_8005DFF0(rdram, ctx);
        goto after_1;
    // 0x8005D194: ori         $a0, $a0, 0x86A0
    ctx->r4 = ctx->r4 | 0X86A0;
    after_1:
    fprintf(stderr, "[R2-D158] #1 malloc done\n"); fflush(stderr);
    // 0x8005D198: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8005D19C: addiu       $a0, $a0, -0x2F60
    ctx->r4 = ADD32(ctx->r4, -0X2F60);
    // 0x8005D1A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D1A4: sw          $v0, -0x1D38($at)
    MEM_W(-0X1D38, ctx->r1) = ctx->r2;
    // 0x8005D1A8: jal         0x80068790
    // 0x8005D1AC: nop

    func_80068790(rdram, ctx);
        goto after_2;
    // 0x8005D1AC: nop

    after_2:
    fprintf(stderr, "[R2-D158] #2 func_80068790 done\n"); fflush(stderr);
    // 0x8005D1B0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005D1B4: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x8005D1B8: bne         $v0, $zero, L_8005D1D4
    if (ctx->r2 != 0) {
        // 0x8005D1BC: nop
    
            goto L_8005D1D4;
    }
    // 0x8005D1BC: nop

    // 0x8005D1C0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8005D1C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005D1C8: nop

    // 0x8005D1CC: j           L_8005D1E4
    // 0x8005D1D0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
        goto L_8005D1E4;
    // 0x8005D1D0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
L_8005D1D4:
    // 0x8005D1D4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8005D1D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005D1DC: nop

    // 0x8005D1E0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
L_8005D1E4:
    // 0x8005D1E4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8005D1E8: addiu       $v0, $zero, 0x5622
    ctx->r2 = ADD32(0, 0X5622);
    // 0x8005D1EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005D1F0: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // 0x8005D1F4: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x8005D1F8: addiu       $s2, $s2, 0x3ED0
    ctx->r18 = ADD32(ctx->r18, 0X3ED0);
    // 0x8005D1FC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8005D200: lui         $v0, 0x78
    ctx->r2 = S32(0X78 << 16);
    // 0x8005D204: addiu       $v0, $v0, -0x3C50
    ctx->r2 = ADD32(ctx->r2, -0X3C50);
    // 0x8005D208: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8005D20C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8005D210: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8005D214: jal         0x8006190C
    // 0x8005D218: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    func_8006190C(rdram, ctx);
        goto after_3;
    // 0x8005D218: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    after_3:
    fprintf(stderr, "[R2-D158] #3 func_8006190C done\n"); fflush(stderr);
    // 0x8005D21C: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8005D220: addiu       $a0, $a0, -0x2F58
    ctx->r4 = ADD32(ctx->r4, -0X2F58);
    // 0x8005D224: jal         0x800687C8
    // 0x8005D228: nop

    func_800687C8(rdram, ctx);
        goto after_4;
    // 0x8005D228: nop

    after_4:
    fprintf(stderr, "[R2-D158] #4 func_800687C8 done\n"); fflush(stderr);
    // 0x8005D22C: lui         $s1, 0x77
    ctx->r17 = S32(0X77 << 16);
    // 0x8005D230: addiu       $s1, $s1, -0x2D30
    ctx->r17 = ADD32(ctx->r17, -0X2D30);
    // 0x8005D234: jal         0x80062C70
    // 0x8005D238: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80062C70(rdram, ctx);
        goto after_5;
    // 0x8005D238: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    fprintf(stderr, "[R2-D158] #5 func_80062C70 done, ret=0x%08X\n", (unsigned)ctx->r2); fflush(stderr);
    // 0x8005D23C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005D240: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005D244: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8005D248: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005D24C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005D250: jal         0x80070FF0
    // 0x8005D254: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80070FF0(rdram, ctx);
        goto after_6;
    // 0x8005D254: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_6:
    fprintf(stderr, "[R2-D158] #6 alloc done\n"); fflush(stderr);
    // 0x8005D258: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005D25C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8005D260: jal         0x80062F3C
    // 0x8005D264: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80062F3C(rdram, ctx);
        goto after_7;
    // 0x8005D264: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_7:
    fprintf(stderr, "[R2-D158] #7 func_80062F3C done\n"); fflush(stderr);
    // 0x8005D268: jal         0x80062974
    // 0x8005D26C: nop

    func_80062974(rdram, ctx);
        goto after_8;
    // 0x8005D26C: nop

    after_8:
    fprintf(stderr, "[R2-D158] #8 func_80062974 done\n"); fflush(stderr);
    // 0x8005D270: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005D274: lui         $s3, 0x78
    ctx->r19 = S32(0X78 << 16);
    // 0x8005D278: addiu       $s3, $s3, -0x6190
    ctx->r19 = ADD32(ctx->r19, -0X6190);
    // 0x8005D27C: jal         0x8006D120
    // 0x8005D280: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8006D120(rdram, ctx);
        goto after_9;
    // 0x8005D280: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_9:
    fprintf(stderr, "[R2-D158] #9 func_8006D120 done\n"); fflush(stderr);
    // 0x8005D284: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005D288: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005D28C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8005D290: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005D294: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8005D298: jal         0x80070FF0
    // 0x8005D29C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80070FF0(rdram, ctx);
        goto after_10;
    // 0x8005D29C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_10:
    fprintf(stderr, "[R2-D158] #10 alloc2 done\n"); fflush(stderr);
    // 0x8005D2A0: jal         0x80062974
    // 0x8005D2A4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_80062974(rdram, ctx);
        goto after_11;
    // 0x8005D2A4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_11:
    fprintf(stderr, "[R2-D158] #11 func_80062974 done\n"); fflush(stderr);
    // 0x8005D2A8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005D2AC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8005D2B0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8005D2B4: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x8005D2B8: jal         0x8006D1E4
    // 0x8005D2BC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_8006D1E4(rdram, ctx);
        goto after_12;
    // 0x8005D2BC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_12:
    fprintf(stderr, "[R2-D158] #12 func_8006D1E4 done\n"); fflush(stderr);
    // 0x8005D2C0: jal         0x8005D0E8
    // 0x8005D2C4: nop

    func_8005D0E8(rdram, ctx);
        goto after_13;
    // 0x8005D2C4: nop

    after_13:
    fprintf(stderr, "[R2-D158] #13 func_8005D0E8 done\n"); fflush(stderr);
    // 0x8005D2C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005D2CC: lw          $a0, -0x1D38($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1D38);
    // 0x8005D2D0: jal         0x8005E06C
    // 0x8005D2D4: nop

    func_8005E06C(rdram, ctx);
        goto after_14;
    // 0x8005D2D4: nop

    after_14:
    fprintf(stderr, "[R2-D158] #14 func_8005E06C done, RETURNING\n"); fflush(stderr);
    // 0x8005D2D8: lw          $ra, 0x88($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X88);
    // 0x8005D2DC: lw          $s3, 0x84($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X84);
    // 0x8005D2E0: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x8005D2E4: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
    // 0x8005D2E8: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x8005D2EC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x8005D2F0: jr          $ra
    // 0x8005D2F4: nop

    return;
    // 0x8005D2F4: nop

    // 0x8005D2F8: nop

    // 0x8005D2FC: nop

;}
RECOMP_FUNC void func_8005D300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D300: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D304: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005D308: jal         0x8005DFF0
    // 0x8005D30C: addiu       $a0, $zero, 0x1011
    ctx->r4 = ADD32(0, 0X1011);
    func_8005DFF0(rdram, ctx);
        goto after_0;
    // 0x8005D30C: addiu       $a0, $zero, 0x1011
    ctx->r4 = ADD32(0, 0X1011);
    after_0:
    // 0x8005D310: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005D314: sw          $v0, -0x67CC($at)
    MEM_W(-0X67CC, ctx->r1) = ctx->r2;
    // 0x8005D318: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005D31C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8005D320: jr          $ra
    // 0x8005D324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005D324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005D328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // (diagnostic removed - fallthrough fix should resolve NULL output issue)
    // 0x8005D328: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8005D32C: addu        $t4, $a1, $zero
    ctx->r12 = ADD32(ctx->r5, 0);
    // 0x8005D330: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8005D334: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
L_8005D338:
    // 0x8005D338: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005D33C: lw          $v0, -0x67CC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X67CC);
    // 0x8005D340: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8005D344: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005D348: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8005D34C: slti        $v0, $t0, 0xFEE
    ctx->r2 = SIGNED(ctx->r8) < 0XFEE ? 1 : 0;
    // 0x8005D350: bne         $v0, $zero, L_8005D338
    if (ctx->r2 != 0) {
        // 0x8005D354: addiu       $t2, $zero, 0xFEE
        ctx->r10 = ADD32(0, 0XFEE);
            goto L_8005D338;
    }
    // 0x8005D354: addiu       $t2, $zero, 0xFEE
    ctx->r10 = ADD32(0, 0XFEE);
    // 0x8005D358: j           L_8005D454
    // 0x8005D35C: subu        $v0, $a3, $a0
    ctx->r2 = SUB32(ctx->r7, ctx->r4);
        goto L_8005D454;
    // 0x8005D35C: subu        $v0, $a3, $a0
    ctx->r2 = SUB32(ctx->r7, ctx->r4);
L_8005D360:
    // 0x8005D360: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x8005D364: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8005D368: ori         $t5, $v1, 0xFF00
    ctx->r13 = ctx->r3 | 0XFF00;
    // 0x8005D36C: andi        $v0, $t5, 0x1
    ctx->r2 = ctx->r13 & 0X1;
L_8005D370:
    // 0x8005D370: beq         $v0, $zero, L_8005D3B0
    if (ctx->r2 == 0) {
        // 0x8005D374: subu        $v0, $a3, $a0
        ctx->r2 = SUB32(ctx->r7, ctx->r4);
            goto L_8005D3B0;
    }
    // 0x8005D374: subu        $v0, $a3, $a0
    ctx->r2 = SUB32(ctx->r7, ctx->r4);
    // 0x8005D378: slt         $v0, $v0, $a2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8005D37C: beq         $v0, $zero, L_8005D460
    if (ctx->r2 == 0) {
        // 0x8005D380: nop
    
            goto L_8005D460;
    }
    // 0x8005D380: nop

    // 0x8005D384: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x8005D388: sb          $v1, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r3;
    // 0x8005D38C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005D390: lw          $v0, -0x67CC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X67CC);
    // 0x8005D394: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8005D398: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8005D39C: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8005D3A0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8005D3A4: andi        $t2, $t2, 0xFFF
    ctx->r10 = ctx->r10 & 0XFFF;
    // 0x8005D3A8: j           L_8005D440
    // 0x8005D3AC: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
        goto L_8005D440;
    // 0x8005D3AC: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8005D3B0:
    // 0x8005D3B0: slt         $v0, $v0, $a2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8005D3B4: beq         $v0, $zero, L_8005D460
    if (ctx->r2 == 0) {
        // 0x8005D3B8: nop
    
            goto L_8005D460;
    }
    // 0x8005D3B8: nop

    // 0x8005D3BC: lbu         $t0, 0x0($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X0);
    // 0x8005D3C0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8005D3C4: subu        $v0, $a3, $a0
    ctx->r2 = SUB32(ctx->r7, ctx->r4);
    // 0x8005D3C8: slt         $v0, $v0, $a2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8005D3CC: beq         $v0, $zero, L_8005D460
    if (ctx->r2 == 0) {
        // 0x8005D3D0: nop
    
            goto L_8005D460;
    }
    // 0x8005D3D0: nop

    // 0x8005D3D4: lbu         $t3, 0x0($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X0);
    // 0x8005D3D8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8005D3DC: andi        $v0, $t3, 0xF0
    ctx->r2 = ctx->r11 & 0XF0;
    // 0x8005D3E0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8005D3E4: or          $t0, $t0, $v0
    ctx->r8 = ctx->r8 | ctx->r2;
    // 0x8005D3E8: andi        $v0, $t3, 0xF
    ctx->r2 = ctx->r11 & 0XF;
    // 0x8005D3EC: addiu       $t3, $v0, 0x2
    ctx->r11 = ADD32(ctx->r2, 0X2);
    // 0x8005D3F0: slti        $v0, $t3, 0x0
    ctx->r2 = SIGNED(ctx->r11) < 0X0 ? 1 : 0;
    // 0x8005D3F4: bne         $v0, $zero, L_8005D440
    if (ctx->r2 != 0) {
        // 0x8005D3F8: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_8005D440;
    }
    // 0x8005D3F8: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
L_8005D3FC:
    // 0x8005D3FC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8005D400: lw          $v1, -0x67CC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X67CC);
    // 0x8005D404: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8005D408: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8005D40C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005D410: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x8005D414: sb          $v1, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r3;
    // 0x8005D418: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005D41C: lw          $v0, -0x67CC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X67CC);
    // 0x8005D420: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005D424: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8005D428: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8005D42C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8005D430: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8005D434: slt         $v0, $t3, $t1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005D438: beq         $v0, $zero, L_8005D3FC
    if (ctx->r2 == 0) {
        // 0x8005D43C: andi        $t2, $t2, 0xFFF
        ctx->r10 = ctx->r10 & 0XFFF;
            goto L_8005D3FC;
    }
    // 0x8005D43C: andi        $t2, $t2, 0xFFF
    ctx->r10 = ctx->r10 & 0XFFF;
L_8005D440:
    // 0x8005D440: srl         $t5, $t5, 1
    ctx->r13 = S32(U32(ctx->r13) >> 1);
    // 0x8005D444: andi        $v0, $t5, 0x100
    ctx->r2 = ctx->r13 & 0X100;
    // 0x8005D448: bne         $v0, $zero, L_8005D370
    if (ctx->r2 != 0) {
        // 0x8005D44C: andi        $v0, $t5, 0x1
        ctx->r2 = ctx->r13 & 0X1;
            goto L_8005D370;
    }
    // 0x8005D44C: andi        $v0, $t5, 0x1
    ctx->r2 = ctx->r13 & 0X1;
    // 0x8005D450: subu        $v0, $a3, $a0
    ctx->r2 = SUB32(ctx->r7, ctx->r4);
L_8005D454:
    // 0x8005D454: slt         $v0, $v0, $a2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8005D458: bne         $v0, $zero, L_8005D360
    if (ctx->r2 != 0) {
        // 0x8005D45C: nop
    
            goto L_8005D360;
    }
    // 0x8005D45C: nop

L_8005D460:
    // 0x8005D460: jr          $ra
    // 0x8005D464: subu        $v0, $t4, $a1
    ctx->r2 = SUB32(ctx->r12, ctx->r5);
    return;
    // 0x8005D464: subu        $v0, $t4, $a1
    ctx->r2 = SUB32(ctx->r12, ctx->r5);
    // 0x8005D468: nop

    // 0x8005D46C: nop

;}
RECOMP_FUNC void func_8005D470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D470: jr          $ra
    // 0x8005D474: nop

    return;
    // 0x8005D474: nop

;}
RECOMP_FUNC void func_8005D478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D478: jr          $ra
    // 0x8005D47C: nop

    return;
    // 0x8005D47C: nop

;}
RECOMP_FUNC void func_8005D480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D480: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005D484: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005D488: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x8005D48C: lui         $a2, 0x4E32
    ctx->r6 = S32(0X4E32 << 16);
    // 0x8005D490: ori         $a2, $a2, 0x5045
    ctx->r6 = ctx->r6 | 0X5045;
    // 0x8005D494: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8005D498: bne         $v0, $zero, L_8005D4A8
    if (ctx->r2 != 0) {
        // 0x8005D49C: sw          $s0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r16;
            goto L_8005D4A8;
    }
    // 0x8005D49C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8005D4A0: lui         $a2, 0x4E32
    ctx->r6 = S32(0X4E32 << 16);
    // 0x8005D4A4: ori         $a2, $a2, 0x5050
    ctx->r6 = ctx->r6 | 0X5050;
L_8005D4A8:
    // 0x8005D4A8: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8005D4AC: addiu       $s0, $s0, 0x40E0
    ctx->r16 = ADD32(ctx->r16, 0X40E0);
    // 0x8005D4B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005D4B4: addiu       $a1, $zero, 0x3544
    ctx->r5 = ADD32(0, 0X3544);
    // 0x8005D4B8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005D4BC: addiu       $v0, $v0, -0x6D0
    ctx->r2 = ADD32(ctx->r2, -0X6D0);
    // 0x8005D4C0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005D4C4: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x8005D4C8: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8005D4CC: addiu       $a3, $a3, -0x6E0
    ctx->r7 = ADD32(ctx->r7, -0X6E0);
    // 0x8005D4D0: jal         0x8005BFE0
    // 0x8005D4D4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_8005BFE0(rdram, ctx);
        goto after_0;
    // 0x8005D4D4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // 0x8005D4D8: beq         $v0, $zero, L_8005D508
    if (ctx->r2 == 0) {
        // 0x8005D4DC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8005D508;
    }
    // 0x8005D4DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005D4E0: jal         0x80074120
    // 0x8005D4E4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80074120(rdram, ctx);
        goto after_1;
    // 0x8005D4E4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x8005D4E8: bne         $v0, $zero, L_8005D544
    if (ctx->r2 != 0) {
        // 0x8005D4EC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8005D544;
    }
    // 0x8005D4EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8005D4F0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8005D4F4: sltiu       $v0, $v0, 0x300
    ctx->r2 = ctx->r2 < 0X300 ? 1 : 0;
    // 0x8005D4F8: beql        $v0, $zero, L_8005D510
    if (ctx->r2 == 0) {
        // 0x8005D4FC: sw          $zero, 0x38($sp)
        MEM_W(0X38, ctx->r29) = 0;
            goto L_8005D510;
    }
    goto skip_0;
    // 0x8005D4FC: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    skip_0:
    // 0x8005D500: j           L_8005D544
    // 0x8005D504: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8005D544;
    // 0x8005D504: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8005D508:
    // 0x8005D508: j           L_8005D544
    // 0x8005D50C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005D544;
    // 0x8005D50C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005D510:
    // 0x8005D510: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005D514: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005D518: addiu       $a0, $a0, 0x40E0
    ctx->r4 = ADD32(ctx->r4, 0X40E0);
    // 0x8005D51C: jal         0x80073F90
    // 0x8005D520: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_80073F90(rdram, ctx);
        goto after_2;
    // 0x8005D520: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8005D524: bne         $v0, $zero, L_8005D544
    if (ctx->r2 != 0) {
        // 0x8005D528: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8005D544;
    }
    // 0x8005D528: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8005D52C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8005D530: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005D534: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8005D538: slti        $v0, $v0, 0x10
    ctx->r2 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8005D53C: bne         $v0, $zero, L_8005D510
    if (ctx->r2 != 0) {
        // 0x8005D540: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8005D510;
    }
    // 0x8005D540: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8005D544:
    // 0x8005D544: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8005D548: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8005D54C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8005D550: jr          $ra
    // 0x8005D554: nop

    return;
    // 0x8005D554: nop

;}
RECOMP_FUNC void func_8005D558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D558: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D55C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005D560: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8005D564: addiu       $a0, $a0, 0x56A0
    ctx->r4 = ADD32(ctx->r4, 0X56A0);
    // 0x8005D568: jal         0x8005C200
    // 0x8005D56C: nop

    func_8005C200(rdram, ctx);
        goto after_0;
    // 0x8005D56C: nop

    after_0:
    // 0x8005D570: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D574: beq         $v1, $zero, L_8005D58C
    if (ctx->r3 == 0) {
        // 0x8005D578: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005D58C;
    }
    // 0x8005D578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D57C: beq         $v1, $v0, L_8005D590
    if (ctx->r3 == ctx->r2) {
        // 0x8005D580: nop
    
            goto L_8005D590;
    }
    // 0x8005D580: nop

    // 0x8005D584: j           L_8005D590
    // 0x8005D588: nop

        goto L_8005D590;
    // 0x8005D588: nop

L_8005D58C:
    // 0x8005D58C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005D590:
    // 0x8005D590: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005D594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005D598: jr          $ra
    // 0x8005D59C: nop

    return;
    // 0x8005D59C: nop

;}
RECOMP_FUNC void func_8005D5A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D5A0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005D5A4: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
;}
RECOMP_FUNC void func_8005D5A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D5A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005D5AC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005D5B0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8005D5B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005D5B8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005D5BC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005D5C0: lui         $s2, 0x4E32
    ctx->r18 = S32(0X4E32 << 16);
    // 0x8005D5C4: ori         $s2, $s2, 0x5045
    ctx->r18 = ctx->r18 | 0X5045;
    // 0x8005D5C8: bne         $v0, $zero, L_8005D5D8
    if (ctx->r2 != 0) {
        // 0x8005D5CC: sw          $ra, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r31;
            goto L_8005D5D8;
    }
    // 0x8005D5CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005D5D0: lui         $s2, 0x4E32
    ctx->r18 = S32(0X4E32 << 16);
    // 0x8005D5D4: ori         $s2, $s2, 0x5050
    ctx->r18 = ctx->r18 | 0X5050;
L_8005D5D8:
    // 0x8005D5D8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005D5DC: lw          $v0, -0x6CC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6CC);
    // 0x8005D5E0: bne         $v0, $zero, L_8005D5FC
    if (ctx->r2 != 0) {
        // 0x8005D5E4: nop
    
            goto L_8005D5FC;
    }
    // 0x8005D5E4: nop

    // 0x8005D5E8: jal         0x8005D8DC
    // 0x8005D5EC: nop

    func_8005D8DC(rdram, ctx);
        goto after_0;
    // 0x8005D5EC: nop

    after_0:
    // 0x8005D5F0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D5F4: bne         $v1, $zero, L_8005D700
    if (ctx->r3 != 0) {
        // 0x8005D5F8: nop
    
            goto L_8005D700;
    }
    // 0x8005D5F8: nop

L_8005D5FC:
    // 0x8005D5FC: beq         $s0, $zero, L_8005D614
    if (ctx->r16 == 0) {
        // 0x8005D600: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005D614;
    }
    // 0x8005D600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D604: beq         $s0, $v0, L_8005D670
    if (ctx->r16 == ctx->r2) {
        // 0x8005D608: addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
            goto L_8005D670;
    }
    // 0x8005D608: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8005D60C: j           L_8005D5FC
    // 0x8005D610: nop

        goto L_8005D5FC;
    // 0x8005D610: nop

L_8005D614:
    // 0x8005D614: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005D618: addiu       $a0, $a0, 0x40E0
    ctx->r4 = ADD32(ctx->r4, 0X40E0);
    // 0x8005D61C: addiu       $a1, $zero, 0x3544
    ctx->r5 = ADD32(0, 0X3544);
    // 0x8005D620: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8005D624: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005D628: addiu       $v0, $v0, -0x6D0
    ctx->r2 = ADD32(ctx->r2, -0X6D0);
    // 0x8005D62C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005D630: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x8005D634: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8005D638: addiu       $a3, $a3, -0x6E0
    ctx->r7 = ADD32(ctx->r7, -0X6E0);
    // 0x8005D63C: jal         0x8005BFE0
    // 0x8005D640: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_8005BFE0(rdram, ctx);
        goto after_1;
    // 0x8005D640: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // 0x8005D644: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D648: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x8005D64C: beq         $v0, $zero, L_8005D6FC
    if (ctx->r2 == 0) {
        // 0x8005D650: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8005D6FC;
    }
    // 0x8005D650: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005D654: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005D658: addu        $at, $at, $v0
    gpr jr_addend_8005D660 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005D65C: lw          $v0, 0x1E20($at)
    ctx->r2 = ADD32(ctx->r1, 0X1E20);
    // 0x8005D660: jr          $v0
    // 0x8005D664: nop

    switch (jr_addend_8005D660 >> 2) {
        case 0: goto L_8005D668; break;
        case 1: goto L_8005D6FC; break;
        case 2: goto L_8005D6D4; break;
        case 3: goto L_8005D6DC; break;
        case 4: goto L_8005D6DC; break;
        case 5: goto L_8005D6E4; break;
        default: switch_error(__func__, 0x8005D660, 0x800C1E20);
    }
    // 0x8005D664: nop

L_8005D668:
    // 0x8005D668: j           L_8005D5FC
    // 0x8005D66C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8005D5FC;
    // 0x8005D66C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8005D670:
    // 0x8005D670: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005D674: addiu       $a0, $a0, 0x40E0
    ctx->r4 = ADD32(ctx->r4, 0X40E0);
    // 0x8005D678: jal         0x8005C358
    // 0x8005D67C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8005C358(rdram, ctx);
        goto after_2;
    // 0x8005D67C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8005D680: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D684: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x8005D688: beq         $v0, $zero, L_8005D6FC
    if (ctx->r2 == 0) {
        // 0x8005D68C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8005D6FC;
    }
    // 0x8005D68C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005D690: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005D694: addu        $at, $at, $v0
    gpr jr_addend_8005D69C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005D698: lw          $v0, 0x1E38($at)
    ctx->r2 = ADD32(ctx->r1, 0X1E38);
    // 0x8005D69C: jr          $v0
    // 0x8005D6A0: nop

    switch (jr_addend_8005D69C >> 2) {
        case 0: goto L_8005D6A4; break;
        case 1: goto L_8005D6FC; break;
        case 2: goto L_8005D6D4; break;
        case 3: goto L_8005D6DC; break;
        case 4: goto L_8005D6DC; break;
        case 5: goto L_8005D6E4; break;
        case 6: goto L_8005D6F4; break;
        default: switch_error(__func__, 0x8005D69C, 0x800C1E38);
    }
    // 0x8005D6A0: nop

L_8005D6A4:
    // 0x8005D6A4: jal         0x8005D9F0
    // 0x8005D6A8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005D9F0(rdram, ctx);
        goto after_3;
    // 0x8005D6A8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x8005D6AC: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x8005D6B0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D6B4: bne         $v1, $a0, L_8005D700
    if (ctx->r3 != ctx->r4) {
        // 0x8005D6B8: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_8005D700;
    }
    // 0x8005D6B8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8005D6BC: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x8005D6C0: xori        $v0, $v0, 0x70
    ctx->r2 = ctx->r2 ^ 0X70;
    // 0x8005D6C4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8005D6C8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8005D6CC: j           L_8005D700
    // 0x8005D6D0: andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
        goto L_8005D700;
    // 0x8005D6D0: andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
L_8005D6D4:
    // 0x8005D6D4: j           L_8005D700
    // 0x8005D6D8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_8005D700;
    // 0x8005D6D8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_8005D6DC:
    // 0x8005D6DC: j           L_8005D700
    // 0x8005D6E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8005D700;
    // 0x8005D6E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8005D6E4:
    // 0x8005D6E4: jal         0x8005DA28
    // 0x8005D6E8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005DA28(rdram, ctx);
        goto after_4;
    // 0x8005D6E8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // 0x8005D6EC: j           L_8005D700
    // 0x8005D6F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005D700;
    // 0x8005D6F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005D6F4:
    // 0x8005D6F4: j           L_8005D700
    // 0x8005D6F8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_8005D700;
    // 0x8005D6F8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8005D6FC:
    // 0x8005D6FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005D700:
    // 0x8005D700: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D704: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005D708: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005D70C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005D710: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8005D714: jr          $ra
    // 0x8005D718: nop

    return;
    // 0x8005D718: nop

;}
RECOMP_FUNC void func_8005D71C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D71C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005D720: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
;}
RECOMP_FUNC void func_8005D724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D724: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005D728: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005D72C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8005D730: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005D734: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005D738: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005D73C: lui         $s1, 0x4E32
    ctx->r17 = S32(0X4E32 << 16);
    // 0x8005D740: ori         $s1, $s1, 0x5045
    ctx->r17 = ctx->r17 | 0X5045;
    // 0x8005D744: bne         $v0, $zero, L_8005D754
    if (ctx->r2 != 0) {
        // 0x8005D748: sw          $ra, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r31;
            goto L_8005D754;
    }
    // 0x8005D748: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005D74C: lui         $s1, 0x4E32
    ctx->r17 = S32(0X4E32 << 16);
    // 0x8005D750: ori         $s1, $s1, 0x5050
    ctx->r17 = ctx->r17 | 0X5050;
L_8005D754:
    // 0x8005D754: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005D758: lw          $v0, -0x6CC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6CC);
    // 0x8005D75C: bne         $v0, $zero, L_8005D77C
    if (ctx->r2 != 0) {
        // 0x8005D760: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005D77C;
    }
    // 0x8005D760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D764: jal         0x8005D8DC
    // 0x8005D768: nop

    func_8005D8DC(rdram, ctx);
        goto after_0;
    // 0x8005D768: nop

    after_0:
    // 0x8005D76C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D770: bne         $v1, $zero, L_8005D8C0
    if (ctx->r3 != 0) {
        // 0x8005D774: nop
    
            goto L_8005D8C0;
    }
    // 0x8005D774: nop

L_8005D778:
    // 0x8005D778: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005D77C:
    // 0x8005D77C: beq         $s0, $v0, L_8005D804
    if (ctx->r16 == ctx->r2) {
        // 0x8005D780: slti        $v0, $s0, 0x2
        ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_8005D804;
    }
    // 0x8005D780: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8005D784: beql        $v0, $zero, L_8005D79C
    if (ctx->r2 == 0) {
        // 0x8005D788: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8005D79C;
    }
    goto skip_0;
    // 0x8005D788: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8005D78C: beq         $s0, $zero, L_8005D7AC
    if (ctx->r16 == 0) {
        // 0x8005D790: addiu       $a1, $zero, 0x3544
        ctx->r5 = ADD32(0, 0X3544);
            goto L_8005D7AC;
    }
    // 0x8005D790: addiu       $a1, $zero, 0x3544
    ctx->r5 = ADD32(0, 0X3544);
    // 0x8005D794: j           L_8005D77C
    // 0x8005D798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005D77C;
    // 0x8005D798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005D79C:
    // 0x8005D79C: beq         $s0, $v0, L_8005D868
    if (ctx->r16 == ctx->r2) {
        // 0x8005D7A0: addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
            goto L_8005D868;
    }
    // 0x8005D7A0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8005D7A4: j           L_8005D77C
    // 0x8005D7A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005D77C;
    // 0x8005D7A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005D7AC:
    // 0x8005D7AC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005D7B0: addiu       $a0, $a0, 0x40E0
    ctx->r4 = ADD32(ctx->r4, 0X40E0);
    // 0x8005D7B4: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8005D7B8: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8005D7BC: addiu       $a3, $a3, -0x6E0
    ctx->r7 = ADD32(ctx->r7, -0X6E0);
    // 0x8005D7C0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005D7C4: addiu       $v0, $v0, -0x6D0
    ctx->r2 = ADD32(ctx->r2, -0X6D0);
    // 0x8005D7C8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005D7CC: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x8005D7D0: jal         0x8005BFE0
    // 0x8005D7D4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_8005BFE0(rdram, ctx);
        goto after_1;
    // 0x8005D7D4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // 0x8005D7D8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D7DC: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x8005D7E0: beq         $v0, $zero, L_8005D8BC
    if (ctx->r2 == 0) {
        // 0x8005D7E4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8005D8BC;
    }
    // 0x8005D7E4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005D7E8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005D7EC: addu        $at, $at, $v0
    gpr jr_addend_8005D7F4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005D7F0: lw          $v0, 0x1E58($at)
    ctx->r2 = ADD32(ctx->r1, 0X1E58);
    // 0x8005D7F4: jr          $v0
    // 0x8005D7F8: nop

    switch (jr_addend_8005D7F4 >> 2) {
        case 0: goto L_8005D858; break;
        case 1: goto L_8005D8BC; break;
        case 2: goto L_8005D8A4; break;
        case 3: goto L_8005D8AC; break;
        case 4: goto L_8005D8AC; break;
        case 5: goto L_8005D7FC; break;
        default: switch_error(__func__, 0x8005D7F4, 0x800C1E58);
    }
    // 0x8005D7F8: nop

L_8005D7FC:
    // 0x8005D7FC: j           L_8005D778
    // 0x8005D800: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8005D778;
    // 0x8005D800: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8005D804:
    // 0x8005D804: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005D808: addiu       $a0, $a0, 0x40E0
    ctx->r4 = ADD32(ctx->r4, 0X40E0);
    // 0x8005D80C: addiu       $a1, $zero, 0x3544
    ctx->r5 = ADD32(0, 0X3544);
    // 0x8005D810: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8005D814: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8005D818: addiu       $a3, $a3, -0x6E0
    ctx->r7 = ADD32(ctx->r7, -0X6E0);
    // 0x8005D81C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005D820: addiu       $v0, $v0, -0x6D0
    ctx->r2 = ADD32(ctx->r2, -0X6D0);
    // 0x8005D824: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005D828: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x8005D82C: jal         0x8005C0A4
    // 0x8005D830: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_8005C0A4(rdram, ctx);
        goto after_2;
    // 0x8005D830: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_2:
    // 0x8005D834: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D838: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x8005D83C: beq         $v0, $zero, L_8005D8BC
    if (ctx->r2 == 0) {
        // 0x8005D840: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8005D8BC;
    }
    // 0x8005D840: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005D844: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005D848: addu        $at, $at, $v0
    gpr jr_addend_8005D850 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005D84C: lw          $v0, 0x1E70($at)
    ctx->r2 = ADD32(ctx->r1, 0X1E70);
    // 0x8005D850: jr          $v0
    // 0x8005D854: nop

    switch (jr_addend_8005D850 >> 2) {
        case 0: goto L_8005D858; break;
        case 1: goto L_8005D8BC; break;
        case 2: goto L_8005D8A4; break;
        case 3: goto L_8005D8AC; break;
        case 4: goto L_8005D8AC; break;
        case 5: goto L_8005D8BC; break;
        case 6: goto L_8005D8BC; break;
        case 7: goto L_8005D860; break;
        case 8: goto L_8005D860; break;
        case 9: goto L_8005D860; break;
        default: switch_error(__func__, 0x8005D850, 0x800C1E70);
    }
    // 0x8005D854: nop

L_8005D858:
    // 0x8005D858: j           L_8005D778
    // 0x8005D85C: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_8005D778;
    // 0x8005D85C: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_8005D860:
    // 0x8005D860: j           L_8005D8C0
    // 0x8005D864: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8005D8C0;
    // 0x8005D864: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8005D868:
    // 0x8005D868: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005D86C: addiu       $a0, $a0, 0x40E0
    ctx->r4 = ADD32(ctx->r4, 0X40E0);
    // 0x8005D870: jal         0x8005C38C
    // 0x8005D874: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_8005C38C(rdram, ctx);
        goto after_3;
    // 0x8005D874: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_3:
    // 0x8005D878: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D87C: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x8005D880: beq         $v0, $zero, L_8005D8BC
    if (ctx->r2 == 0) {
        // 0x8005D884: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8005D8BC;
    }
    // 0x8005D884: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005D888: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005D88C: addu        $at, $at, $v0
    gpr jr_addend_8005D894 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005D890: lw          $v0, 0x1E98($at)
    ctx->r2 = ADD32(ctx->r1, 0X1E98);
    // 0x8005D894: jr          $v0
    // 0x8005D898: nop

    switch (jr_addend_8005D894 >> 2) {
        case 0: goto L_8005D89C; break;
        case 1: goto L_8005D8BC; break;
        case 2: goto L_8005D8A4; break;
        case 3: goto L_8005D8AC; break;
        case 4: goto L_8005D8AC; break;
        case 5: goto L_8005D8BC; break;
        case 6: goto L_8005D8B4; break;
        default: switch_error(__func__, 0x8005D894, 0x800C1E98);
    }
    // 0x8005D898: nop

L_8005D89C:
    // 0x8005D89C: j           L_8005D8C0
    // 0x8005D8A0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005D8C0;
    // 0x8005D8A0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005D8A4:
    // 0x8005D8A4: j           L_8005D8C0
    // 0x8005D8A8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_8005D8C0;
    // 0x8005D8A8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_8005D8AC:
    // 0x8005D8AC: j           L_8005D8C0
    // 0x8005D8B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8005D8C0;
    // 0x8005D8B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8005D8B4:
    // 0x8005D8B4: j           L_8005D8C0
    // 0x8005D8B8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_8005D8C0;
    // 0x8005D8B8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8005D8BC:
    // 0x8005D8BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005D8C0:
    // 0x8005D8C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D8C4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005D8C8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005D8CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005D8D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8005D8D4: jr          $ra
    // 0x8005D8D8: nop

    return;
    // 0x8005D8D8: nop

;}
RECOMP_FUNC void func_8005D8DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D8DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D8E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D8E4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_8005D8E8:
    // 0x8005D8E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005D8EC: sw          $zero, -0x6CC($at)
    MEM_W(-0X6CC, ctx->r1) = 0;
    // 0x8005D8F0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005D8F4: addiu       $a0, $a0, 0x40E0
    ctx->r4 = ADD32(ctx->r4, 0X40E0);
    // 0x8005D8F8: jal         0x8005C30C
    // 0x8005D8FC: nop

    func_8005C30C(rdram, ctx);
        goto after_0;
    // 0x8005D8FC: nop

    after_0:
    // 0x8005D900: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005D904: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8005D908: bne         $s0, $v0, L_8005D928
    if (ctx->r16 != ctx->r2) {
        // 0x8005D90C: sltiu       $v0, $s0, 0xB
        ctx->r2 = ctx->r16 < 0XB ? 1 : 0;
            goto L_8005D928;
    }
    // 0x8005D90C: sltiu       $v0, $s0, 0xB
    ctx->r2 = ctx->r16 < 0XB ? 1 : 0;
    // 0x8005D910: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8005D914: addiu       $a1, $a1, 0x56A0
    ctx->r5 = ADD32(ctx->r5, 0X56A0);
    // 0x8005D918: jal         0x8005C3C0
    // 0x8005D91C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8005C3C0(rdram, ctx);
        goto after_1;
    // 0x8005D91C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x8005D920: beq         $v0, $zero, L_8005D968
    if (ctx->r2 == 0) {
        // 0x8005D924: sltiu       $v0, $s0, 0xB
        ctx->r2 = ctx->r16 < 0XB ? 1 : 0;
            goto L_8005D968;
    }
    // 0x8005D924: sltiu       $v0, $s0, 0xB
    ctx->r2 = ctx->r16 < 0XB ? 1 : 0;
L_8005D928:
    // 0x8005D928: beq         $v0, $zero, L_8005D968
    if (ctx->r2 == 0) {
        // 0x8005D92C: sll         $v0, $s0, 2
        ctx->r2 = S32(ctx->r16 << 2);
            goto L_8005D968;
    }
    // 0x8005D92C: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8005D930: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005D934: addu        $at, $at, $v0
    gpr jr_addend_8005D93C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005D938: lw          $v0, 0x1EB8($at)
    ctx->r2 = ADD32(ctx->r1, 0X1EB8);
    // 0x8005D93C: jr          $v0
    // 0x8005D940: nop

    switch (jr_addend_8005D93C >> 2) {
        case 0: goto L_8005D944; break;
        case 1: goto L_8005D968; break;
        case 2: goto L_8005D8E8; break;
        case 3: goto L_8005D958; break;
        case 4: goto L_8005D958; break;
        case 5: goto L_8005D968; break;
        case 6: goto L_8005D968; break;
        case 7: goto L_8005D968; break;
        case 8: goto L_8005D968; break;
        case 9: goto L_8005D968; break;
        case 10: goto L_8005D960; break;
        default: switch_error(__func__, 0x8005D93C, 0x800C1EB8);
    }
    // 0x8005D940: nop

L_8005D944:
    // 0x8005D944: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D948: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005D94C: sw          $v0, -0x6CC($at)
    MEM_W(-0X6CC, ctx->r1) = ctx->r2;
    // 0x8005D950: j           L_8005D96C
    // 0x8005D954: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005D96C;
    // 0x8005D954: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005D958:
    // 0x8005D958: j           L_8005D96C
    // 0x8005D95C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8005D96C;
    // 0x8005D95C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8005D960:
    // 0x8005D960: j           L_8005D96C
    // 0x8005D964: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8005D96C;
    // 0x8005D964: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8005D968:
    // 0x8005D968: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005D96C:
    // 0x8005D96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D970: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005D974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005D978: jr          $ra
    // 0x8005D97C: nop

    return;
    // 0x8005D97C: nop

;}
RECOMP_FUNC void func_8005D980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D984: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005D988: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005D98C: addiu       $a0, $a0, 0x40E0
    ctx->r4 = ADD32(ctx->r4, 0X40E0);
    // 0x8005D990: jal         0x8005C338
    // 0x8005D994: nop

    func_8005C338(rdram, ctx);
        goto after_0;
    // 0x8005D994: nop

    after_0:
    // 0x8005D998: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D99C: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x8005D9A0: beq         $v0, $zero, L_8005D9DC
    if (ctx->r2 == 0) {
        // 0x8005D9A4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8005D9DC;
    }
    // 0x8005D9A4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005D9A8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005D9AC: addu        $at, $at, $v0
    gpr jr_addend_8005D9B4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005D9B0: lw          $v0, 0x1EE8($at)
    ctx->r2 = ADD32(ctx->r1, 0X1EE8);
    // 0x8005D9B4: jr          $v0
    // 0x8005D9B8: nop

    switch (jr_addend_8005D9B4 >> 2) {
        case 0: goto L_8005D9BC; break;
        case 1: goto L_8005D9DC; break;
        case 2: goto L_8005D9C4; break;
        case 3: goto L_8005D9CC; break;
        case 4: goto L_8005D9CC; break;
        case 5: goto L_8005D9DC; break;
        case 6: goto L_8005D9DC; break;
        case 7: goto L_8005D9DC; break;
        case 8: goto L_8005D9DC; break;
        case 9: goto L_8005D9DC; break;
        case 10: goto L_8005D9D4; break;
        default: switch_error(__func__, 0x8005D9B4, 0x800C1EE8);
    }
    // 0x8005D9B8: nop

L_8005D9BC:
    // 0x8005D9BC: j           L_8005D9E0
    // 0x8005D9C0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005D9E0;
    // 0x8005D9C0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005D9C4:
    // 0x8005D9C4: j           L_8005D9E0
    // 0x8005D9C8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_8005D9E0;
    // 0x8005D9C8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_8005D9CC:
    // 0x8005D9CC: j           L_8005D9E0
    // 0x8005D9D0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8005D9E0;
    // 0x8005D9D0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8005D9D4:
    // 0x8005D9D4: j           L_8005D9E0
    // 0x8005D9D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8005D9E0;
    // 0x8005D9D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8005D9DC:
    // 0x8005D9DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005D9E0:
    // 0x8005D9E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005D9E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005D9E8: jr          $ra
    // 0x8005D9EC: nop

    return;
    // 0x8005D9EC: nop

;}
RECOMP_FUNC void func_8005D9F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D9F0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8005D9F4: lw          $a3, 0x38($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X38);
    // 0x8005D9F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005D9FC: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8005DA00: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
L_8005DA04:
    // 0x8005DA04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005DA08: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8005DA0C: xor         $a2, $a2, $v0
    ctx->r6 = ctx->r6 ^ ctx->r2;
    // 0x8005DA10: sltiu       $v0, $a1, 0xC0
    ctx->r2 = ctx->r5 < 0XC0 ? 1 : 0;
    // 0x8005DA14: bne         $v0, $zero, L_8005DA04
    if (ctx->r2 != 0) {
        // 0x8005DA18: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8005DA04;
    }
    // 0x8005DA18: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005DA1C: sw          $a3, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r7;
    // 0x8005DA20: jr          $ra
    // 0x8005DA24: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    return;
    // 0x8005DA24: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
;}
RECOMP_FUNC void func_8005DA28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DA28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005DA2C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005DA30: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005DA34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005DA38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005DA3C: jal         0x8007DEC0
    // 0x8005DA40: addiu       $a2, $zero, 0x300
    ctx->r6 = ADD32(0, 0X300);
    func_8007DEC0(rdram, ctx);
        goto after_0;
    // 0x8005DA40: addiu       $a2, $zero, 0x300
    ctx->r6 = ADD32(0, 0X300);
    after_0:
    // 0x8005DA44: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005DA48: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x8005DA4C: addiu       $v0, $s0, 0x14
    ctx->r2 = ADD32(ctx->r16, 0X14);
    // 0x8005DA50: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8005DA54:
    // 0x8005DA54: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8005DA58: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8005DA5C: bgez        $v1, L_8005DA54
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005DA60: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_8005DA54;
    }
    // 0x8005DA60: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8005DA64: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005DA68: addiu       $v0, $zero, 0x70
    ctx->r2 = ADD32(0, 0X70);
    // 0x8005DA6C: jal         0x8005D9F0
    // 0x8005DA70: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    func_8005D9F0(rdram, ctx);
        goto after_1;
    // 0x8005DA70: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    after_1:
    // 0x8005DA74: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x8005DA78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005DA7C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005DA80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005DA84: jr          $ra
    // 0x8005DA88: nop

    return;
    // 0x8005DA88: nop

    // 0x8005DA8C: nop

;}
RECOMP_FUNC void func_8005DA90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DA90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005DA94: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8005DA98: addiu       $v1, $v1, -0x270
    ctx->r3 = ADD32(ctx->r3, -0X270);
    // 0x8005DA9C: lui         $v0, 0x803A
    ctx->r2 = S32(0X803A << 16);
    // 0x8005DAA0: addiu       $v0, $v0, 0x2400
    ctx->r2 = ADD32(ctx->r2, 0X2400);
    // 0x8005DAA4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DAA8: sw          $v0, 0x678C($at)
    MEM_W(0X678C, ctx->r1) = ctx->r2;
    // 0x8005DAAC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DAB0: sw          $v0, 0x6790($at)
    MEM_W(0X6790, ctx->r1) = ctx->r2;
    // 0x8005DAB4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005DAB8: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x8005DABC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005DAC0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DAC4: sw          $v1, 0x6788($at)
    MEM_W(0X6788, ctx->r1) = ctx->r3;
    // 0x8005DAC8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DACC: sw          $v1, 0x6794($at)
    MEM_W(0X6794, ctx->r1) = ctx->r3;
    // 0x8005DAD0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005DAD4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8005DAD8: sw          $zero, -0x26C($at)
    MEM_W(-0X26C, ctx->r1) = 0;
    // 0x8005DADC: jal         0x8005DB1C
    // 0x8005DAE0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8005DB1C(rdram, ctx);
        goto after_0;
    // 0x8005DAE0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x8005DAE4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005DAE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005DAEC: jr          $ra
    // 0x8005DAF0: nop

    return;
    // 0x8005DAF0: nop

;}
RECOMP_FUNC void func_8005DAF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DAF4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DAF8: sw          $zero, 0x6788($at)
    MEM_W(0X6788, ctx->r1) = 0;
    // 0x8005DAFC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DB00: sw          $zero, 0x678C($at)
    MEM_W(0X678C, ctx->r1) = 0;
    // 0x8005DB04: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DB08: sw          $zero, 0x6790($at)
    MEM_W(0X6790, ctx->r1) = 0;
    // 0x8005DB0C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DB10: sw          $zero, 0x6794($at)
    MEM_W(0X6794, ctx->r1) = 0;
    // 0x8005DB14: jr          $ra
    // 0x8005DB18: nop

    return;
    // 0x8005DB18: nop

;}
RECOMP_FUNC void func_8005DB1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DB1C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005DB20: lw          $v0, -0x6BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BC);
    // 0x8005DB24: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005DB28: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005DB2C: sw          $v0, -0x6BC($at)
    MEM_W(-0X6BC, ctx->r1) = ctx->r2;
    // 0x8005DB30: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005DB34: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DB38: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005DB3C: sw          $a0, 0x6760($at)
    MEM_W(0X6760, ctx->r1) = ctx->r4;
    // 0x8005DB40: jr          $ra
    // 0x8005DB44: nop

    return;
    // 0x8005DB44: nop

;}
RECOMP_FUNC void func_8005DB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DB48: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005DB4C: lw          $v0, -0x6BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BC);
    // 0x8005DB50: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8005DB54: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8005DB58: sw          $v0, -0x6BC($at)
    MEM_W(-0X6BC, ctx->r1) = ctx->r2;
    // 0x8005DB5C: jr          $ra
    // 0x8005DB60: nop

    return;
    // 0x8005DB60: nop

;}
RECOMP_FUNC void func_8005DB64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DB64: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8005DB68: lw          $a1, 0x6790($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6790);
    // 0x8005DB6C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8005DB70: lw          $v0, 0x678C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X678C);
    // 0x8005DB74: bnel        $a1, $v0, L_8005DB90
    if (ctx->r5 != ctx->r2) {
        // 0x8005DB78: sltu        $v0, $a0, $a1
        ctx->r2 = ctx->r4 < ctx->r5 ? 1 : 0;
            goto L_8005DB90;
    }
    goto skip_0;
    // 0x8005DB78: sltu        $v0, $a0, $a1
    ctx->r2 = ctx->r4 < ctx->r5 ? 1 : 0;
    skip_0:
    // 0x8005DB7C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8005DB80: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DB84: sw          $a0, 0x6790($at)
    MEM_W(0X6790, ctx->r1) = ctx->r4;
    // 0x8005DB88: j           L_8005DBCC
    // 0x8005DB8C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
        goto L_8005DBCC;
    // 0x8005DB8C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
L_8005DB90:
    // 0x8005DB90: beq         $v0, $zero, L_8005DBAC
    if (ctx->r2 == 0) {
        // 0x8005DB94: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8005DBAC;
    }
    // 0x8005DB94: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8005DB98: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x8005DB9C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DBA0: sw          $a0, 0x6790($at)
    MEM_W(0X6790, ctx->r1) = ctx->r4;
    // 0x8005DBA4: j           L_8005DBCC
    // 0x8005DBA8: nop

        goto L_8005DBCC;
    // 0x8005DBA8: nop

L_8005DBAC:
    // 0x8005DBAC: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x8005DBB0: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8005DBB4: bnel        $v0, $zero, L_8005DBAC
    if (ctx->r2 != 0) {
        // 0x8005DBB8: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_8005DBAC;
    }
    goto skip_1;
    // 0x8005DBB8: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    skip_1:
    // 0x8005DBBC: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8005DBC0: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x8005DBC4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8005DBC8: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
L_8005DBCC:
    // 0x8005DBCC: jr          $ra
    // 0x8005DBD0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    return;
    // 0x8005DBD0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
;}
RECOMP_FUNC void func_8005DBD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DBD4: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8005DBD8: lw          $v1, 0x6790($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6790);
    // 0x8005DBDC: bne         $v1, $a0, L_8005DBFC
    if (ctx->r3 != ctx->r4) {
        // 0x8005DBE0: nop
    
            goto L_8005DBFC;
    }
    // 0x8005DBE0: nop

    // 0x8005DBE4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8005DBE8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DBEC: sw          $v0, 0x6790($at)
    MEM_W(0X6790, ctx->r1) = ctx->r2;
    // 0x8005DBF0: j           L_8005DC14
    // 0x8005DBF4: nop

        goto L_8005DC14;
    // 0x8005DBF4: nop

L_8005DBF8:
    // 0x8005DBF8: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
L_8005DBFC:
    // 0x8005DBFC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8005DC00: bne         $v0, $a0, L_8005DBF8
    if (ctx->r2 != ctx->r4) {
        // 0x8005DC04: nop
    
            goto L_8005DBF8;
    }
    // 0x8005DC04: nop

    // 0x8005DC08: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8005DC0C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8005DC10: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8005DC14:
    // 0x8005DC14: jr          $ra
    // 0x8005DC18: nop

    return;
    // 0x8005DC18: nop

;}
RECOMP_FUNC void func_8005DC1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DC1C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8005DC20: lw          $a1, 0x6794($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6794);
    // 0x8005DC24: bne         $a1, $zero, L_8005DC40
    if (ctx->r5 != 0) {
        // 0x8005DC28: sltu        $v0, $a0, $a1
        ctx->r2 = ctx->r4 < ctx->r5 ? 1 : 0;
            goto L_8005DC40;
    }
    // 0x8005DC28: sltu        $v0, $a0, $a1
    ctx->r2 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8005DC2C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8005DC30: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DC34: sw          $a0, 0x6794($at)
    MEM_W(0X6794, ctx->r1) = ctx->r4;
    // 0x8005DC38: j           L_8005DC88
    // 0x8005DC3C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
        goto L_8005DC88;
    // 0x8005DC3C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8005DC40:
    // 0x8005DC40: beq         $v0, $zero, L_8005DC70
    if (ctx->r2 == 0) {
        // 0x8005DC44: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8005DC70;
    }
    // 0x8005DC44: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8005DC48: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x8005DC4C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DC50: sw          $a0, 0x6794($at)
    MEM_W(0X6794, ctx->r1) = ctx->r4;
    // 0x8005DC54: j           L_8005DC88
    // 0x8005DC58: nop

        goto L_8005DC88;
    // 0x8005DC58: nop

L_8005DC5C:
    // 0x8005DC5C: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x8005DC60: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8005DC64: beql        $v0, $zero, L_8005DC7C
    if (ctx->r2 == 0) {
        // 0x8005DC68: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_8005DC7C;
    }
    goto skip_0;
    // 0x8005DC68: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    skip_0:
    // 0x8005DC6C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_8005DC70:
    // 0x8005DC70: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8005DC74: bne         $v0, $zero, L_8005DC5C
    if (ctx->r2 != 0) {
        // 0x8005DC78: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_8005DC5C;
    }
    // 0x8005DC78: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_8005DC7C:
    // 0x8005DC7C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8005DC80: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8005DC84: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
L_8005DC88:
    // 0x8005DC88: jr          $ra
    // 0x8005DC8C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    return;
    // 0x8005DC8C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
;}
RECOMP_FUNC void func_8005DC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DC90: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8005DC94: lw          $v1, 0x6794($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6794);
    // 0x8005DC98: bne         $v1, $a0, L_8005DCB8
    if (ctx->r3 != ctx->r4) {
        // 0x8005DC9C: nop
    
            goto L_8005DCB8;
    }
    // 0x8005DC9C: nop

    // 0x8005DCA0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8005DCA4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DCA8: sw          $v0, 0x6794($at)
    MEM_W(0X6794, ctx->r1) = ctx->r2;
    // 0x8005DCAC: j           L_8005DCD0
    // 0x8005DCB0: nop

        goto L_8005DCD0;
    // 0x8005DCB0: nop

L_8005DCB4:
    // 0x8005DCB4: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
L_8005DCB8:
    // 0x8005DCB8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8005DCBC: bne         $v0, $a0, L_8005DCB4
    if (ctx->r2 != ctx->r4) {
        // 0x8005DCC0: nop
    
            goto L_8005DCB4;
    }
    // 0x8005DCC0: nop

    // 0x8005DCC4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8005DCC8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8005DCCC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8005DCD0:
    // 0x8005DCD0: jr          $ra
    // 0x8005DCD4: nop

    return;
    // 0x8005DCD4: nop

;}
RECOMP_FUNC void func_8005DCD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DCD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005DCDC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005DCE0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8005DCE4: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    // 0x8005DCE8: addiu       $v0, $zero, -0x8
    ctx->r2 = ADD32(0, -0X8);
    // 0x8005DCEC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8005DCF0: and         $s2, $a0, $v0
    ctx->r18 = ctx->r4 & ctx->r2;
    // 0x8005DCF4: sltiu       $v0, $s2, 0x10
    ctx->r2 = ctx->r18 < 0X10 ? 1 : 0;
    // 0x8005DCF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005DCFC: beq         $v0, $zero, L_8005DD08
    if (ctx->r2 == 0) {
        // 0x8005DD00: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_8005DD08;
    }
    // 0x8005DD00: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005DD04: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_8005DD08:
    // 0x8005DD08: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005DD0C: lw          $v0, -0x6BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BC);
    // 0x8005DD10: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005DD14: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DD18: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005DD1C: lw          $v0, 0x6760($at)
    ctx->r2 = MEM_W(ctx->r1, 0X6760);
    // 0x8005DD20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005DD24: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8005DD28: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005DD2C: lw          $v0, 0x1F18($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1F18);
    // 0x8005DD30: jalr        $v0
    // 0x8005DD34: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8005DD34: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // 0x8005DD38: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8005DD3C: beq         $s1, $zero, L_8005DDC8
    if (ctx->r17 == 0) {
        // 0x8005DD40: nop
    
            goto L_8005DDC8;
    }
    // 0x8005DD40: nop

    // 0x8005DD44: jal         0x8005DC90
    // 0x8005DD48: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005DC90(rdram, ctx);
        goto after_1;
    // 0x8005DD48: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8005DD4C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8005DD50: subu        $v0, $v1, $s2
    ctx->r2 = SUB32(ctx->r3, ctx->r18);
    // 0x8005DD54: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x8005DD58: beq         $v0, $zero, L_8005DD6C
    if (ctx->r2 == 0) {
        // 0x8005DD5C: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_8005DD6C;
    }
    // 0x8005DD5C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x8005DD60: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // 0x8005DD64: j           L_8005DDA8
    // 0x8005DD68: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
        goto L_8005DDA8;
    // 0x8005DD68: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8005DD6C:
    // 0x8005DD6C: beq         $v0, $zero, L_8005DD88
    if (ctx->r2 == 0) {
        // 0x8005DD70: addiu       $v0, $v1, -0x8
        ctx->r2 = ADD32(ctx->r3, -0X8);
            goto L_8005DD88;
    }
    // 0x8005DD70: addiu       $v0, $v1, -0x8
    ctx->r2 = ADD32(ctx->r3, -0X8);
    // 0x8005DD74: subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // 0x8005DD78: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8005DD7C: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8005DD80: j           L_8005DDA4
    // 0x8005DD84: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
        goto L_8005DDA4;
    // 0x8005DD84: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
L_8005DD88:
    // 0x8005DD88: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // 0x8005DD8C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005DD90: addu        $v1, $s0, $s2
    ctx->r3 = ADD32(ctx->r16, ctx->r18);
    // 0x8005DD94: addiu       $s1, $v1, 0x8
    ctx->r17 = ADD32(ctx->r3, 0X8);
    // 0x8005DD98: subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // 0x8005DD9C: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x8005DDA0: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
L_8005DDA4:
    // 0x8005DDA4: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
L_8005DDA8:
    // 0x8005DDA8: jal         0x8005DB64
    // 0x8005DDAC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8005DB64(rdram, ctx);
        goto after_2;
    // 0x8005DDAC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8005DDB0: beq         $s1, $zero, L_8005DDF0
    if (ctx->r17 == 0) {
        // 0x8005DDB4: addiu       $v0, $s0, 0x8
        ctx->r2 = ADD32(ctx->r16, 0X8);
            goto L_8005DDF0;
    }
    // 0x8005DDB4: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x8005DDB8: jal         0x8005DC1C
    // 0x8005DDBC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005DC1C(rdram, ctx);
        goto after_3;
    // 0x8005DDBC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x8005DDC0: j           L_8005DDF0
    // 0x8005DDC4: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
        goto L_8005DDF0;
    // 0x8005DDC4: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
L_8005DDC8:
    // 0x8005DDC8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8005DDCC: lw          $v0, -0x6C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C0);
    // 0x8005DDD0: bne         $v0, $zero, L_8005DDF0
    if (ctx->r2 != 0) {
        // 0x8005DDD4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8005DDF0;
    }
    // 0x8005DDD4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8005DDD8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8005DDDC: addiu       $a0, $a0, 0x1F1C
    ctx->r4 = ADD32(ctx->r4, 0X1F1C);
    // 0x8005DDE0: jal         0x8005E0C8
    // 0x8005DDE4: nop

    func_8005E0C8(rdram, ctx);
        goto after_4;
    // 0x8005DDE4: nop

    after_4:
L_8005DDE8:
    // 0x8005DDE8: j           L_8005DDE8
    pause_self(rdram);
    // 0x8005DDEC: nop

L_8005DDF0:
    // 0x8005DDF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005DDF4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8005DDF8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005DDFC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005DE00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005DE04: jr          $ra
    // 0x8005DE08: nop

    return;
    // 0x8005DE08: nop

;}
RECOMP_FUNC void func_8005DE0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DE0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005DE10: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005DE14: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8005DE18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005DE1C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8005DE20: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8005DE24: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8005DE28: beq         $s1, $zero, L_8005DED4
    if (ctx->r17 == 0) {
        // 0x8005DE2C: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8005DED4;
    }
    // 0x8005DE2C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005DE30: addiu       $s0, $s1, -0x8
    ctx->r16 = ADD32(ctx->r17, -0X8);
    // 0x8005DE34: jal         0x8005DBD4
    // 0x8005DE38: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8005DBD4(rdram, ctx);
        goto after_0;
    // 0x8005DE38: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8005DE3C: jal         0x8005DC1C
    // 0x8005DE40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8005DC1C(rdram, ctx);
        goto after_1;
    // 0x8005DE40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8005DE44: lw          $v1, -0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, -0X8);
    // 0x8005DE48: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8005DE4C: lw          $s3, -0x4($s1)
    ctx->r19 = MEM_W(ctx->r17, -0X4);
    // 0x8005DE50: addu        $s4, $s0, $v1
    ctx->r20 = ADD32(ctx->r16, ctx->r3);
    // 0x8005DE54: addiu       $v0, $s4, 0x8
    ctx->r2 = ADD32(ctx->r20, 0X8);
    // 0x8005DE58: bne         $s3, $v0, L_8005DE8C
    if (ctx->r19 != ctx->r2) {
        // 0x8005DE5C: nop
    
            goto L_8005DE8C;
    }
    // 0x8005DE5C: nop

    // 0x8005DE60: jal         0x8005DC90
    // 0x8005DE64: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8005DC90(rdram, ctx);
        goto after_2;
    // 0x8005DE64: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8005DE68: jal         0x8005DC90
    // 0x8005DE6C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8005DC90(rdram, ctx);
        goto after_3;
    // 0x8005DE6C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_3:
    // 0x8005DE70: lw          $v0, -0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X8);
    // 0x8005DE74: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x8005DE78: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005DE7C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8005DE80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005DE84: jal         0x8005DC1C
    // 0x8005DE88: sw          $v0, -0x8($s1)
    MEM_W(-0X8, ctx->r17) = ctx->r2;
    func_8005DC1C(rdram, ctx);
        goto after_4;
    // 0x8005DE88: sw          $v0, -0x8($s1)
    MEM_W(-0X8, ctx->r17) = ctx->r2;
    after_4:
L_8005DE8C:
    // 0x8005DE8C: beq         $s2, $zero, L_8005DED4
    if (ctx->r18 == 0) {
        // 0x8005DE90: nop
    
            goto L_8005DED4;
    }
    // 0x8005DE90: nop

    // 0x8005DE94: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8005DE98: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x8005DE9C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8005DEA0: bne         $v0, $s0, L_8005DED4
    if (ctx->r2 != ctx->r16) {
        // 0x8005DEA4: nop
    
            goto L_8005DED4;
    }
    // 0x8005DEA4: nop

    // 0x8005DEA8: jal         0x8005DC90
    // 0x8005DEAC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8005DC90(rdram, ctx);
        goto after_5;
    // 0x8005DEAC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_5:
    // 0x8005DEB0: jal         0x8005DC90
    // 0x8005DEB4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8005DC90(rdram, ctx);
        goto after_6;
    // 0x8005DEB4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8005DEB8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8005DEBC: lw          $v1, -0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, -0X8);
    // 0x8005DEC0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005DEC4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8005DEC8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005DECC: jal         0x8005DC1C
    // 0x8005DED0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    func_8005DC1C(rdram, ctx);
        goto after_7;
    // 0x8005DED0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    after_7:
L_8005DED4:
    // 0x8005DED4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005DED8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8005DEDC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8005DEE0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8005DEE4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005DEE8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005DEEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005DEF0: jr          $ra
    // 0x8005DEF4: nop

    return;
    // 0x8005DEF4: nop

;}
RECOMP_FUNC void func_8005DEF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DEF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005DEFC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005DF00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8005DF04: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8005DF08: jal         0x8005DCD8
    // 0x8005DF0C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8005DCD8(rdram, ctx);
        goto after_0;
    // 0x8005DF0C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x8005DF10: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005DF14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005DF18: jr          $ra
    // 0x8005DF1C: nop

    return;
    // 0x8005DF1C: nop

;}
RECOMP_FUNC void func_8005DF20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DF20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005DF24: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005DF28: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005DF2C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8005DF30: jal         0x8005DCD8
    // 0x8005DF34: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8005DCD8(rdram, ctx);
        goto after_0;
    // 0x8005DF34: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x8005DF38: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005DF3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005DF40: jr          $ra
    // 0x8005DF44: nop

    return;
    // 0x8005DF44: nop

;}
RECOMP_FUNC void func_8005DF48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DF48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005DF4C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005DF50: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005DF54: jal         0x8005DE0C
    // 0x8005DF58: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8005DE0C(rdram, ctx);
        goto after_0;
    // 0x8005DF58: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x8005DF5C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005DF60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005DF64: jr          $ra
    // 0x8005DF68: nop

    return;
    // 0x8005DF68: nop

;}
RECOMP_FUNC void func_8005DF6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DF6C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8005DF70: lw          $v1, 0x6794($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6794);
    // 0x8005DF74: beq         $v1, $zero, L_8005DF98
    if (ctx->r3 == 0) {
        // 0x8005DF78: nop
    
            goto L_8005DF98;
    }
    // 0x8005DF78: nop

L_8005DF7C:
    // 0x8005DF7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005DF80: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8005DF84: beq         $v0, $zero, L_8005DF98
    if (ctx->r2 == 0) {
        // 0x8005DF88: nop
    
            goto L_8005DF98;
    }
    // 0x8005DF88: nop

    // 0x8005DF8C: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x8005DF90: bne         $v1, $zero, L_8005DF7C
    if (ctx->r3 != 0) {
        // 0x8005DF94: nop
    
            goto L_8005DF7C;
    }
    // 0x8005DF94: nop

L_8005DF98:
    // 0x8005DF98: jr          $ra
    // 0x8005DF9C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    return;
    // 0x8005DF9C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
;}
RECOMP_FUNC void func_8005DFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DFA0: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8005DFA4: lw          $v1, 0x6790($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6790);
    // 0x8005DFA8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8005DFAC: lw          $a0, 0x678C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X678C);
    // 0x8005DFB0: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8005DFB4: beq         $v0, $zero, L_8005DFCC
    if (ctx->r2 == 0) {
        // 0x8005DFB8: nop
    
            goto L_8005DFCC;
    }
    // 0x8005DFB8: nop

L_8005DFBC:
    // 0x8005DFBC: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x8005DFC0: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8005DFC4: bne         $v0, $zero, L_8005DFBC
    if (ctx->r2 != 0) {
        // 0x8005DFC8: nop
    
            goto L_8005DFBC;
    }
    // 0x8005DFC8: nop

L_8005DFCC:
    // 0x8005DFCC: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8005DFD0: lw          $v1, 0x6794($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6794);
    // 0x8005DFD4: beq         $v1, $zero, L_8005DFE8
    if (ctx->r3 == 0) {
        // 0x8005DFD8: nop
    
            goto L_8005DFE8;
    }
    // 0x8005DFD8: nop

L_8005DFDC:
    // 0x8005DFDC: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x8005DFE0: bne         $v1, $zero, L_8005DFDC
    if (ctx->r3 != 0) {
        // 0x8005DFE4: nop
    
            goto L_8005DFDC;
    }
    // 0x8005DFE4: nop

L_8005DFE8:
    // 0x8005DFE8: jr          $ra
    // 0x8005DFEC: nop

    return;
    // 0x8005DFEC: nop

;}
RECOMP_FUNC void func_8005DFF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DFF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005DFF4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005DFF8: jal         0x8005DF20
    // 0x8005DFFC: nop

    func_8005DF20(rdram, ctx);
        goto after_0;
    // 0x8005DFFC: nop

    after_0:
    // 0x8005E000: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005E004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005E008: jr          $ra
    // 0x8005E00C: nop

    return;
    // 0x8005E00C: nop

;}
RECOMP_FUNC void func_8005E010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E010: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005E014: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005E018: nop

    // 0x8005E01C: mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E020: mflo        $s1
    ctx->r17 = lo;
    // 0x8005E024: nop

    // 0x8005E028: nop

    // 0x8005E02C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8005E030: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005E034: jal         0x8005DF20
    // 0x8005E038: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005DF20(rdram, ctx);
        goto after_0;
    // 0x8005E038: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8005E03C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005E040: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005E044: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E048: jal         0x8007DEC0
    // 0x8005E04C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8007DEC0(rdram, ctx);
        goto after_1;
    // 0x8005E04C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8005E050: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8005E054: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005E058: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005E05C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005E060: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005E064: jr          $ra
    // 0x8005E068: nop

    return;
    // 0x8005E068: nop

;}
RECOMP_FUNC void func_8005E06C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E06C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005E070: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005E074: jal         0x8005DF48
    // 0x8005E078: nop

    func_8005DF48(rdram, ctx);
        goto after_0;
    // 0x8005E078: nop

    after_0:
    // 0x8005E07C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005E080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005E084: jr          $ra
    // 0x8005E088: nop

    return;
    // 0x8005E088: nop

;}
RECOMP_FUNC void func_8005E08C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E08C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8005E090: lw          $v1, 0x6788($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6788);
    // 0x8005E094: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8005E098: lw          $a0, 0x678C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X678C);
    // 0x8005E09C: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8005E0A0: beq         $v0, $zero, L_8005E0C0
    if (ctx->r2 == 0) {
        // 0x8005E0A4: nop
    
            goto L_8005E0C0;
    }
    // 0x8005E0A4: nop

L_8005E0A8:
    // 0x8005E0A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005E0AC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8005E0B0: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8005E0B4: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8005E0B8: bne         $v0, $zero, L_8005E0A8
    if (ctx->r2 != 0) {
        // 0x8005E0BC: nop
    
            goto L_8005E0A8;
    }
    // 0x8005E0BC: nop

L_8005E0C0:
    // 0x8005E0C0: jr          $ra
    // 0x8005E0C4: nop

    return;
    // 0x8005E0C4: nop

;}
RECOMP_FUNC void func_8005E0C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E0C8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8005E0CC: lw          $v0, 0x6794($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6794);
    // 0x8005E0D0: beq         $v0, $zero, L_8005E0E4
    if (ctx->r2 == 0) {
        // 0x8005E0D4: nop
    
            goto L_8005E0E4;
    }
    // 0x8005E0D4: nop

L_8005E0D8:
    // 0x8005E0D8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8005E0DC: bne         $v0, $zero, L_8005E0D8
    if (ctx->r2 != 0) {
        // 0x8005E0E0: nop
    
            goto L_8005E0D8;
    }
    // 0x8005E0E0: nop

L_8005E0E4:
    // 0x8005E0E4: jr          $ra
    // 0x8005E0E8: nop

    return;
    // 0x8005E0E8: nop

;}
RECOMP_FUNC void func_8005E0EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E0EC: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8005E0F0: lw          $v1, 0x6794($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6794);
    // 0x8005E0F4: beq         $v1, $zero, L_8005E11C
    if (ctx->r3 == 0) {
        // 0x8005E0F8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8005E11C;
    }
    // 0x8005E0F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8005E0FC:
    // 0x8005E0FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005E100: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x8005E104: slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005E108: bnel        $v0, $zero, L_8005E110
    if (ctx->r2 != 0) {
        // 0x8005E10C: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_8005E110;
    }
    goto skip_0;
    // 0x8005E10C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    skip_0:
L_8005E110:
    // 0x8005E110: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x8005E114: bne         $v1, $zero, L_8005E0FC
    if (ctx->r3 != 0) {
        // 0x8005E118: nop
    
            goto L_8005E0FC;
    }
    // 0x8005E118: nop

L_8005E11C:
    // 0x8005E11C: jr          $ra
    // 0x8005E120: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    return;
    // 0x8005E120: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
;}
RECOMP_FUNC void func_8005E124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E124: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8005E128: lw          $v1, 0x6794($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6794);
    // 0x8005E12C: beq         $v1, $zero, L_8005E148
    if (ctx->r3 == 0) {
        // 0x8005E130: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8005E148;
    }
    // 0x8005E130: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8005E134:
    // 0x8005E134: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005E138: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x8005E13C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8005E140: bne         $v1, $zero, L_8005E134
    if (ctx->r3 != 0) {
        // 0x8005E144: addu        $a0, $a0, $v0
        ctx->r4 = ADD32(ctx->r4, ctx->r2);
            goto L_8005E134;
    }
    // 0x8005E144: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_8005E148:
    // 0x8005E148: jr          $ra
    // 0x8005E14C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x8005E14C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void func_8005E150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E150: jr          $ra
    // 0x8005E154: nop

    return;
    // 0x8005E154: nop

;}
RECOMP_FUNC void func_8005E158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E158: jr          $ra
    // 0x8005E15C: nop

    return;
    // 0x8005E15C: nop

;}
RECOMP_FUNC void func_8005E160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E160: jr          $ra
    // 0x8005E164: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8005E164: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8005E168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E168: jr          $ra
    // 0x8005E16C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8005E16C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8005E170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E170: jr          $ra
    // 0x8005E174: nop

    return;
    // 0x8005E174: nop

;}
RECOMP_FUNC void func_8005E178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_8005E178:
    // 0x8005E178: j           L_8005E178
    pause_self(rdram);
    // 0x8005E17C: nop

    // 0x8005E180: jr          $ra
    // 0x8005E184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8005E184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8005E188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E188: jr          $ra
    // 0x8005E18C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8005E18C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8005E190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E190: jr          $ra
    // 0x8005E194: nop

    return;
    // 0x8005E194: nop

;}
RECOMP_FUNC void func_8005E198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E198: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005E19C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005E1A0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8005E1A4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8005E1A8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8005E1AC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8005E1B0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005E1B4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005E1B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005E1BC: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x8005E1C0: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x8005E1C4: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x8005E1C8: jal         0x8005D300
    // 0x8005E1CC: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    func_8005D300(rdram, ctx);
        goto after_0;
    // 0x8005E1CC: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    after_0:
    // 0x8005E1D0: jal         0x80060400
    // 0x8005E1D4: addiu       $s6, $zero, -0xC8
    ctx->r22 = ADD32(0, -0XC8);
    func_80060400(rdram, ctx);
        goto after_1;
    // 0x8005E1D4: addiu       $s6, $zero, -0xC8
    ctx->r22 = ADD32(0, -0XC8);
    after_1:
    // 0x8005E1D8: jal         0x8005E7FC
    // 0x8005E1DC: addiu       $s5, $zero, 0xC8
    ctx->r21 = ADD32(0, 0XC8);
    func_8005E7FC(rdram, ctx);
        goto after_2;
    // 0x8005E1DC: addiu       $s5, $zero, 0xC8
    ctx->r21 = ADD32(0, 0XC8);
    after_2:
    // 0x8005E1E0: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8005E1E4: addiu       $a0, $a0, 0x1ABC
    ctx->r4 = ADD32(ctx->r4, 0X1ABC);
    // 0x8005E1E8: jal         0x8005CD84
    // 0x8005E1EC: addiu       $s1, $zero, -0x102
    ctx->r17 = ADD32(0, -0X102);
    func_8005CD84(rdram, ctx);
        goto after_3;
    // 0x8005E1EC: addiu       $s1, $zero, -0x102
    ctx->r17 = ADD32(0, -0X102);
    after_3:
    // 0x8005E1F0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005E1F4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8005E1F8: nop

    // 0x8005E1FC: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8005E200: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8005E204: nop

    // 0x8005E208: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x8005E20C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8005E210: nop

    // 0x8005E214: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005E218: addiu       $v0, $v0, -0x1CA0
    ctx->r2 = ADD32(ctx->r2, -0X1CA0);
    // 0x8005E21C: addiu       $s3, $v0, -0x40
    ctx->r19 = ADD32(ctx->r2, -0X40);
    // 0x8005E220: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8005E224: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8005E228:
    // 0x8005E228: jal         0x80070010
    // 0x8005E22C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80070010(rdram, ctx);
        goto after_4;
    // 0x8005E22C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_4:
    // 0x8005E230: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005E234: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005E238: nop

    // 0x8005E23C: lui         $a1, 0xC348
    ctx->r5 = S32(0XC348 << 16);
    // 0x8005E240: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x8005E244: lui         $a3, 0xC2F0
    ctx->r7 = S32(0XC2F0 << 16);
    // 0x8005E248: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8005E24C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8005E250: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8005E254: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8005E258: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8005E25C: jal         0x8006FD30
    // 0x8005E260: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_8006FD30(rdram, ctx);
        goto after_5;
    // 0x8005E260: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8005E264: ori         $v0, $zero, 0xC240
    ctx->r2 = 0 | 0XC240;
    // 0x8005E268: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x8005E26C: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x8005E270: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005E274: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8005E278: sh          $s6, -0x60E0($at)
    MEM_H(-0X60E0, ctx->r1) = ctx->r22;
    // 0x8005E27C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005E280: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8005E284: sh          $s5, -0x60D0($at)
    MEM_H(-0X60D0, ctx->r1) = ctx->r21;
    // 0x8005E288: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005E28C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8005E290: sh          $s5, -0x60C0($at)
    MEM_H(-0X60C0, ctx->r1) = ctx->r21;
    // 0x8005E294: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005E298: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8005E29C: sh          $s6, -0x60B0($at)
    MEM_H(-0X60B0, ctx->r1) = ctx->r22;
    // 0x8005E2A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005E2A4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8005E2A8: sh          $s6, -0x60A0($at)
    MEM_H(-0X60A0, ctx->r1) = ctx->r22;
    // 0x8005E2AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005E2B0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8005E2B4: sh          $s5, -0x6090($at)
    MEM_H(-0X6090, ctx->r1) = ctx->r21;
    // 0x8005E2B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005E2BC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8005E2C0: sh          $s1, -0x60DC($at)
    MEM_H(-0X60DC, ctx->r1) = ctx->r17;
    // 0x8005E2C4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005E2C8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8005E2CC: sh          $s1, -0x60CC($at)
    MEM_H(-0X60CC, ctx->r1) = ctx->r17;
    // 0x8005E2D0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005E2D4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8005E2D8: sh          $s1, -0x60BC($at)
    MEM_H(-0X60BC, ctx->r1) = ctx->r17;
    // 0x8005E2DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005E2E0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8005E2E4: sh          $s1, -0x60AC($at)
    MEM_H(-0X60AC, ctx->r1) = ctx->r17;
    // 0x8005E2E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005E2EC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8005E2F0: sh          $s1, -0x609C($at)
    MEM_H(-0X609C, ctx->r1) = ctx->r17;
    // 0x8005E2F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005E2F8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8005E2FC: sh          $s1, -0x608C($at)
    MEM_H(-0X608C, ctx->r1) = ctx->r17;
    // 0x8005E300: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8005E304: slti        $v0, $s4, 0x2
    ctx->r2 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
    // 0x8005E308: bne         $v0, $zero, L_8005E228
    if (ctx->r2 != 0) {
        // 0x8005E30C: nop
    
            goto L_8005E228;
    }
    // 0x8005E30C: nop

    // 0x8005E310: jal         0x8005C158
    // 0x8005E314: nop

    func_8005C158(rdram, ctx);
        goto after_6;
    // 0x8005E314: nop

    after_6:
    // 0x8005E318: jal         0x80002A20
    // 0x8005E31C: nop

    func_80002A20(rdram, ctx);
        goto after_7;
    // 0x8005E31C: nop

    after_7:
    // 0x8005E320: jal         0x8005C158
    // 0x8005E324: nop

    func_8005C158(rdram, ctx);
        goto after_8;
    // 0x8005E324: nop

    after_8:
    // 0x8005E328: jal         0x8005E398
    // 0x8005E32C: nop

    func_8005E398(rdram, ctx);
        goto after_9;
    // 0x8005E32C: nop

    after_9:
    // 0x8005E330: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E334: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8005E338: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8005E33C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8005E340: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E344: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005E348: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005E34C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005E350: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x8005E354: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x8005E358: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x8005E35C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8005E360: jr          $ra
    // 0x8005E364: nop

    return;
    // 0x8005E364: nop

;}
RECOMP_FUNC void func_8005E368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E368: jr          $ra
    // 0x8005E36C: nop

    return;
    // 0x8005E36C: nop

;}
