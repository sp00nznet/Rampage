#include "recomp.h"
#include "funcs.h"
#include <stdio.h>
#include <string.h>

RECOMP_FUNC void func_8003614C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8003614C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80036150: lw          $v0, -0x44E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X44E0);
    // 0x80036154: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x80036158: lhu         $t6, 0x32($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X32);
    // 0x8003615C: nop

    // 0x80036160: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x80036164: beq         $t7, $zero, L_80036174
    if (ctx->r15 == 0) {
            // 0x80036168: nop

    func_80036174(rdram, ctx);
    return;
    }
    // 0x80036168: nop

    // 0x8003616C: jr          $ra
    // 0x80036170: sw          $t8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r24;
    return;
    // 0x80036170: sw          $t8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_80036174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036174: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    // 0x80036178: jr          $ra
    // 0x8003617C: nop

    return;
    // 0x8003617C: nop

;}
RECOMP_FUNC void func_80036180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036188: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x8003618C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80036190: beq         $v0, $zero, L_800362A0
    if (ctx->r2 == 0) {
        // 0x80036194: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800362A0;
    }
    // 0x80036194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036198: lw          $a0, 0x54($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X54);
    // 0x8003619C: nop

    // 0x800361A0: beq         $a0, $zero, L_800362A0
    if (ctx->r4 == 0) {
        // 0x800361A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800362A0;
    }
    // 0x800361A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800361A8: lhu         $t6, 0x44($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X44);
    // 0x800361AC: nop

    // 0x800361B0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800361B4: beq         $t7, $zero, L_800361D4
    if (ctx->r15 == 0) {
        // 0x800361B8: nop
    
            goto L_800361D4;
    }
    // 0x800361B8: nop

    // 0x800361BC: lhu         $v1, 0x46($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X46);
    // 0x800361C0: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x800361C4: beq         $v1, $at, L_800361D4
    if (ctx->r3 == ctx->r1) {
        // 0x800361C8: addiu       $at, $zero, 0x26
        ctx->r1 = ADD32(0, 0X26);
            goto L_800361D4;
    }
    // 0x800361C8: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x800361CC: bne         $v1, $at, L_80036250
    if (ctx->r3 != ctx->r1) {
        // 0x800361D0: nop
    
            goto L_80036250;
    }
    // 0x800361D0: nop

L_800361D4:
    // 0x800361D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800361D8: jal         0x8000D624
    // 0x800361DC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8000D624(rdram, ctx);
        goto after_0;
    // 0x800361DC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800361E0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800361E4: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x800361E8: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x800361EC: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x800361F0: beq         $v0, $zero, L_80036224
    if (ctx->r2 == 0) {
        // 0x800361F4: lui         $t3, 0x800C
        ctx->r11 = S32(0X800C << 16);
            goto L_80036224;
    }
    // 0x800361F4: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x800361F8: lhu         $t8, 0x44($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X44);
    // 0x800361FC: nop

    // 0x80036200: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80036204: beq         $t9, $zero, L_80036224
    if (ctx->r25 == 0) {
        // 0x80036208: nop
    
            goto L_80036224;
    }
    // 0x80036208: nop

    // 0x8003620C: lhu         $v1, 0x46($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X46);
    // 0x80036210: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x80036214: beq         $v1, $at, L_80036224
    if (ctx->r3 == ctx->r1) {
        // 0x80036218: addiu       $at, $zero, 0x26
        ctx->r1 = ADD32(0, 0X26);
            goto L_80036224;
    }
    // 0x80036218: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x8003621C: bne         $v1, $at, L_80036240
    if (ctx->r3 != ctx->r1) {
        // 0x80036220: nop
    
            goto L_80036240;
    }
    // 0x80036220: nop

L_80036224:
    // 0x80036224: sh          $t0, 0x28($a1)
    MEM_H(0X28, ctx->r5) = ctx->r8;
    // 0x80036228: lh          $t1, 0x614($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X614);
    // 0x8003622C: lh          $t3, -0x878($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X878);
    // 0x80036230: addiu       $t2, $t1, 0xC8
    ctx->r10 = ADD32(ctx->r9, 0XC8);
    // 0x80036234: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x80036238: b           L_8003629C
    // 0x8003623C: sh          $t4, 0x26($a1)
    MEM_H(0X26, ctx->r5) = ctx->r12;
        goto L_8003629C;
    // 0x8003623C: sh          $t4, 0x26($a1)
    MEM_H(0X26, ctx->r5) = ctx->r12;
L_80036240:
    // 0x80036240: lw          $v1, 0x54($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X54);
    // 0x80036244: nop

    // 0x80036248: beq         $v1, $zero, L_8003629C
    if (ctx->r3 == 0) {
        // 0x8003624C: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_8003629C;
    }
    // 0x8003624C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80036250:
    // 0x80036250: lh          $v0, 0x20($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X20);
    // 0x80036254: nop

    // 0x80036258: addiu       $v0, $v0, -0x16
    ctx->r2 = ADD32(ctx->r2, -0X16);
    // 0x8003625C: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x80036260: sra         $v0, $t5, 16
    ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80036264: slti        $at, $v0, 0xE1
    ctx->r1 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x80036268: bne         $at, $zero, L_80036274
    if (ctx->r1 != 0) {
        // 0x8003626C: nop
    
            goto L_80036274;
    }
    // 0x8003626C: nop

    // 0x80036270: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_80036274:
    // 0x80036274: sh          $v0, 0x28($a1)
    MEM_H(0X28, ctx->r5) = ctx->r2;
    // 0x80036278: lhu         $t7, 0x32($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X32);
    // 0x8003627C: lh          $v0, 0x1C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X1C);
    // 0x80036280: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x80036284: beq         $t8, $zero, L_80036298
    if (ctx->r24 == 0) {
        // 0x80036288: addiu       $t0, $v0, 0x10
        ctx->r8 = ADD32(ctx->r2, 0X10);
            goto L_80036298;
    }
    // 0x80036288: addiu       $t0, $v0, 0x10
    ctx->r8 = ADD32(ctx->r2, 0X10);
    // 0x8003628C: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80036290: b           L_8003629C
    // 0x80036294: sh          $t9, 0x26($a1)
    MEM_H(0X26, ctx->r5) = ctx->r25;
        goto L_8003629C;
    // 0x80036294: sh          $t9, 0x26($a1)
    MEM_H(0X26, ctx->r5) = ctx->r25;
L_80036298:
    // 0x80036298: sh          $t0, 0x26($a1)
    MEM_H(0X26, ctx->r5) = ctx->r8;
L_8003629C:
    // 0x8003629C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800362A0:
    // 0x800362A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800362A4: jr          $ra
    // 0x800362A8: nop

    return;
    // 0x800362A8: nop

;}
RECOMP_FUNC void func_800362AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800362AC: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800362B0: nop

    // 0x800362B4: beq         $v0, $zero, L_80036320
    if (ctx->r2 == 0) {
        // 0x800362B8: nop
    
            goto L_80036320;
    }
    // 0x800362B8: nop

    // 0x800362BC: lw          $v1, 0x54($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X54);
    // 0x800362C0: nop

    // 0x800362C4: beq         $v1, $zero, L_80036320
    if (ctx->r3 == 0) {
        // 0x800362C8: nop
    
            goto L_80036320;
    }
    // 0x800362C8: nop

    // 0x800362CC: lh          $t6, 0x20($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X20);
    // 0x800362D0: nop

    // 0x800362D4: addiu       $t7, $t6, -0x1E
    ctx->r15 = ADD32(ctx->r14, -0X1E);
    // 0x800362D8: sh          $t7, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r15;
    // 0x800362DC: lhu         $t8, 0x32($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X32);
    // 0x800362E0: nop

    // 0x800362E4: sh          $t8, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r24;
    // 0x800362E8: lhu         $t9, 0x32($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X32);
    // 0x800362EC: nop

    // 0x800362F0: andi        $t0, $t9, 0x10
    ctx->r8 = ctx->r25 & 0X10;
    // 0x800362F4: beq         $t0, $zero, L_80036310
    if (ctx->r8 == 0) {
        // 0x800362F8: nop
    
            goto L_80036310;
    }
    // 0x800362F8: nop

    // 0x800362FC: lh          $t1, 0x1C($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X1C);
    // 0x80036300: nop

    // 0x80036304: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80036308: jr          $ra
    // 0x8003630C: sh          $t2, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r10;
    return;
    // 0x8003630C: sh          $t2, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r10;
L_80036310:
    // 0x80036310: lh          $t3, 0x1C($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X1C);
    // 0x80036314: nop

    // 0x80036318: addiu       $t4, $t3, 0x10
    ctx->r12 = ADD32(ctx->r11, 0X10);
    // 0x8003631C: sh          $t4, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r12;
L_80036320:
    // 0x80036320: jr          $ra
    // 0x80036324: nop

    return;
    // 0x80036324: nop

;}
RECOMP_FUNC void func_80036328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036328: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x8003632C: nop

    // 0x80036330: beq         $v0, $zero, L_800363C4
    if (ctx->r2 == 0) {
        // 0x80036334: nop
    
            goto L_800363C4;
    }
    // 0x80036334: nop

    // 0x80036338: lw          $v1, 0x54($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X54);
    // 0x8003633C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80036340: beq         $v1, $zero, L_800363C8
    if (ctx->r3 == 0) {
        // 0x80036344: nop
    
            goto L_800363C8;
    }
    // 0x80036344: nop

    // 0x80036348: lh          $t6, 0x20($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X20);
    // 0x8003634C: lh          $t7, 0x40($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X40);
    // 0x80036350: lw          $a0, -0x44E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X44E0);
    // 0x80036354: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x80036358: lh          $t0, 0x20($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X20);
    // 0x8003635C: addiu       $t9, $v0, 0x1A
    ctx->r25 = ADD32(ctx->r2, 0X1A);
    // 0x80036360: subu        $v0, $t9, $t0
    ctx->r2 = SUB32(ctx->r25, ctx->r8);
    // 0x80036364: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x80036368: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8003636C: bgez        $t2, L_8003637C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80036370: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8003637C;
    }
    // 0x80036370: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80036374: b           L_80036380
    // 0x80036378: negu        $v1, $t2
    ctx->r3 = SUB32(0, ctx->r10);
        goto L_80036380;
    // 0x80036378: negu        $v1, $t2
    ctx->r3 = SUB32(0, ctx->r10);
L_8003637C:
    // 0x8003637C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80036380:
    // 0x80036380: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    // 0x80036384: beq         $at, $zero, L_80036398
    if (ctx->r1 == 0) {
        // 0x80036388: nop
    
            goto L_80036398;
    }
    // 0x80036388: nop

    // 0x8003638C: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x80036390: jr          $ra
    // 0x80036394: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80036394: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80036398:
    // 0x80036398: bgez        $v0, L_800363B4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003639C: lui         $t4, 0x1
        ctx->r12 = S32(0X1 << 16);
            goto L_800363B4;
    }
    // 0x8003639C: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x800363A0: lui         $t3, 0xFFFE
    ctx->r11 = S32(0XFFFE << 16);
    // 0x800363A4: ori         $t3, $t3, 0x8000
    ctx->r11 = ctx->r11 | 0X8000;
    // 0x800363A8: sw          $t3, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r11;
    // 0x800363AC: jr          $ra
    // 0x800363B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800363B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800363B4:
    // 0x800363B4: ori         $t4, $t4, 0x8000
    ctx->r12 = ctx->r12 | 0X8000;
    // 0x800363B8: sw          $t4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r12;
    // 0x800363BC: jr          $ra
    // 0x800363C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800363C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800363C4:
    // 0x800363C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800363C8:
    // 0x800363C8: jr          $ra
    // 0x800363CC: nop

    return;
    // 0x800363CC: nop

;}
RECOMP_FUNC void func_800363D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800363D0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800363D4: addiu       $a3, $a3, -0x4500
    ctx->r7 = ADD32(ctx->r7, -0X4500);
    ctx->hi = hi; ctx->lo = lo;
    func_800363D8(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_800363D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800363D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800363DC: lw          $v1, 0x20($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X20);
    // 0x800363E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800363E4: lhu         $t6, 0x28($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X28);
    // 0x800363E8: lh          $t7, 0x20($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X20);
    // 0x800363EC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800363F0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800363F4: sh          $t8, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r24;
    // 0x800363F8: lh          $t9, 0x24($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X24);
    // 0x800363FC: lh          $a1, 0x24($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X24);
    // 0x80036400: bgez        $t9, L_80036414
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80036404: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80036414;
    }
    // 0x80036404: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80036408: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8003640C: b           L_80036414
    // 0x80036410: negu        $v0, $t9
    ctx->r2 = SUB32(0, ctx->r25);
        goto L_80036414;
    // 0x80036410: negu        $v0, $t9
    ctx->r2 = SUB32(0, ctx->r25);
L_80036414:
    // 0x80036414: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80036418: beq         $at, $zero, L_80036434
    if (ctx->r1 == 0) {
        // 0x8003641C: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_80036434;
    }
    // 0x8003641C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80036420: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x80036424: lw          $t0, 0x20($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X20);
    // 0x80036428: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003642C: b           L_8003659C
    // 0x80036430: sw          $zero, 0x18($t0)
    MEM_W(0X18, ctx->r8) = 0;
        goto L_8003659C;
    // 0x80036430: sw          $zero, 0x18($t0)
    MEM_W(0X18, ctx->r8) = 0;
L_80036434:
    // 0x80036434: bltz        $a1, L_80036444
    if (SIGNED(ctx->r5) < 0) {
        // 0x80036438: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80036444;
    }
    // 0x80036438: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8003643C: b           L_80036444
    // 0x80036440: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_80036444;
    // 0x80036440: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80036444:
    // 0x80036444: addiu       $a1, $sp, 0x22
    ctx->r5 = ADD32(ctx->r29, 0X22);
    // 0x80036448: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8003644C: jal         0x80037430
    // 0x80036450: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80037430(rdram, ctx);
        goto after_0;
    // 0x80036450: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80036454: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80036458: lhu         $v1, 0x26($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X26);
    // 0x8003645C: lhu         $t1, 0x3C($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X3C);
    // 0x80036460: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80036464: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x80036468: beq         $t2, $zero, L_800364E0
    if (ctx->r10 == 0) {
        // 0x8003646C: addiu       $a3, $a3, -0x4500
        ctx->r7 = ADD32(ctx->r7, -0X4500);
            goto L_800364E0;
    }
    // 0x8003646C: addiu       $a3, $a3, -0x4500
    ctx->r7 = ADD32(ctx->r7, -0X4500);
    // 0x80036470: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    // 0x80036474: lh          $a1, 0x24($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X24);
    // 0x80036478: ori         $t3, $v1, 0x1
    ctx->r11 = ctx->r3 | 0X1;
    // 0x8003647C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80036480: beq         $at, $zero, L_80036490
    if (ctx->r1 == 0) {
        // 0x80036484: subu        $v0, $a0, $a1
        ctx->r2 = SUB32(ctx->r4, ctx->r5);
            goto L_80036490;
    }
    // 0x80036484: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // 0x80036488: b           L_8003654C
    // 0x8003648C: andi        $v1, $t3, 0xFFFF
    ctx->r3 = ctx->r11 & 0XFFFF;
        goto L_8003654C;
    // 0x8003648C: andi        $v1, $t3, 0xFFFF
    ctx->r3 = ctx->r11 & 0XFFFF;
L_80036490:
    // 0x80036490: bgez        $v0, L_800364A8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80036494: sll         $a0, $v0, 16
        ctx->r4 = S32(ctx->r2 << 16);
            goto L_800364A8;
    }
    // 0x80036494: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80036498: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x8003649C: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800364A0: b           L_800364B0
    // 0x800364A4: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
        goto L_800364B0;
    // 0x800364A4: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
L_800364A8:
    // 0x800364A8: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800364AC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_800364B0:
    // 0x800364B0: slti        $at, $a0, 0x60
    ctx->r1 = SIGNED(ctx->r4) < 0X60 ? 1 : 0;
    // 0x800364B4: beq         $at, $zero, L_800364C8
    if (ctx->r1 == 0) {
        // 0x800364B8: ori         $t8, $v1, 0x1
        ctx->r24 = ctx->r3 | 0X1;
            goto L_800364C8;
    }
    // 0x800364B8: ori         $t8, $v1, 0x1
    ctx->r24 = ctx->r3 | 0X1;
    // 0x800364BC: sh          $a0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r4;
    // 0x800364C0: b           L_8003654C
    // 0x800364C4: andi        $v1, $t8, 0xFFFF
    ctx->r3 = ctx->r24 & 0XFFFF;
        goto L_8003654C;
    // 0x800364C4: andi        $v1, $t8, 0xFFFF
    ctx->r3 = ctx->r24 & 0XFFFF;
L_800364C8:
    // 0x800364C8: slti        $at, $a0, 0x71
    ctx->r1 = SIGNED(ctx->r4) < 0X71 ? 1 : 0;
    // 0x800364CC: bne         $at, $zero, L_8003654C
    if (ctx->r1 != 0) {
        // 0x800364D0: sh          $a0, 0x22($sp)
        MEM_H(0X22, ctx->r29) = ctx->r4;
            goto L_8003654C;
    }
    // 0x800364D0: sh          $a0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r4;
    // 0x800364D4: ori         $t0, $v1, 0x2
    ctx->r8 = ctx->r3 | 0X2;
    // 0x800364D8: b           L_8003654C
    // 0x800364DC: andi        $v1, $t0, 0xFFFF
    ctx->r3 = ctx->r8 & 0XFFFF;
        goto L_8003654C;
    // 0x800364DC: andi        $v1, $t0, 0xFFFF
    ctx->r3 = ctx->r8 & 0XFFFF;
L_800364E0:
    // 0x800364E0: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    // 0x800364E4: lh          $a1, 0x24($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X24);
    // 0x800364E8: ori         $t2, $v1, 0x2
    ctx->r10 = ctx->r3 | 0X2;
    // 0x800364EC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800364F0: beq         $at, $zero, L_80036500
    if (ctx->r1 == 0) {
        // 0x800364F4: subu        $v0, $a0, $a1
        ctx->r2 = SUB32(ctx->r4, ctx->r5);
            goto L_80036500;
    }
    // 0x800364F4: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // 0x800364F8: b           L_8003654C
    // 0x800364FC: andi        $v1, $t2, 0xFFFF
    ctx->r3 = ctx->r10 & 0XFFFF;
        goto L_8003654C;
    // 0x800364FC: andi        $v1, $t2, 0xFFFF
    ctx->r3 = ctx->r10 & 0XFFFF;
L_80036500:
    // 0x80036500: bgez        $v0, L_80036518
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80036504: sll         $a0, $v0, 16
        ctx->r4 = S32(ctx->r2 << 16);
            goto L_80036518;
    }
    // 0x80036504: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80036508: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x8003650C: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x80036510: b           L_80036520
    // 0x80036514: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
        goto L_80036520;
    // 0x80036514: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
L_80036518:
    // 0x80036518: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003651C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_80036520:
    // 0x80036520: slti        $at, $a0, 0x60
    ctx->r1 = SIGNED(ctx->r4) < 0X60 ? 1 : 0;
    // 0x80036524: beq         $at, $zero, L_80036538
    if (ctx->r1 == 0) {
        // 0x80036528: ori         $t7, $v1, 0x2
        ctx->r15 = ctx->r3 | 0X2;
            goto L_80036538;
    }
    // 0x80036528: ori         $t7, $v1, 0x2
    ctx->r15 = ctx->r3 | 0X2;
    // 0x8003652C: sh          $a0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r4;
    // 0x80036530: b           L_8003654C
    // 0x80036534: andi        $v1, $t7, 0xFFFF
    ctx->r3 = ctx->r15 & 0XFFFF;
        goto L_8003654C;
    // 0x80036534: andi        $v1, $t7, 0xFFFF
    ctx->r3 = ctx->r15 & 0XFFFF;
L_80036538:
    // 0x80036538: slti        $at, $a0, 0x71
    ctx->r1 = SIGNED(ctx->r4) < 0X71 ? 1 : 0;
    // 0x8003653C: bne         $at, $zero, L_8003654C
    if (ctx->r1 != 0) {
        // 0x80036540: sh          $a0, 0x22($sp)
        MEM_H(0X22, ctx->r29) = ctx->r4;
            goto L_8003654C;
    }
    // 0x80036540: sh          $a0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r4;
    // 0x80036544: ori         $t9, $v1, 0x1
    ctx->r25 = ctx->r3 | 0X1;
    // 0x80036548: andi        $v1, $t9, 0xFFFF
    ctx->r3 = ctx->r25 & 0XFFFF;
L_8003654C:
    // 0x8003654C: beq         $v1, $zero, L_80036584
    if (ctx->r3 == 0) {
        // 0x80036550: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_80036584;
    }
    // 0x80036550: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80036554: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80036558: addiu       $t3, $t3, -0x4070
    ctx->r11 = ADD32(ctx->r11, -0X4070);
    // 0x8003655C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80036560: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x80036564: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80036568: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x8003656C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036570: sw          $t4, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r12;
    // 0x80036574: lw          $t7, 0x20($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X20);
    // 0x80036578: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8003657C: b           L_8003659C
    // 0x80036580: sw          $t6, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r14;
        goto L_8003659C;
    // 0x80036580: sw          $t6, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r14;
L_80036584:
    // 0x80036584: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x80036588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003658C: sw          $zero, 0x14($t8)
    MEM_W(0X14, ctx->r24) = 0;
    // 0x80036590: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x80036594: nop

    // 0x80036598: sw          $zero, 0x18($t9)
    MEM_W(0X18, ctx->r25) = 0;
L_8003659C:
    // 0x8003659C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800365A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800365A4: jr          $ra
    // 0x800365A8: nop

    return;
    // 0x800365A8: nop

;}
RECOMP_FUNC void func_800365AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800365AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800365B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800365B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800365B8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800365BC: addiu       $a0, $sp, 0x26
    ctx->r4 = ADD32(ctx->r29, 0X26);
    // 0x800365C0: jal         0x80037430
    // 0x800365C4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80037430(rdram, ctx);
        goto after_0;
    // 0x800365C4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800365C8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800365CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800365D0: lhu         $t7, 0x38($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X38);
    // 0x800365D4: lh          $v1, 0x24($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X24);
    // 0x800365D8: bne         $t7, $at, L_8003664C
    if (ctx->r15 != ctx->r1) {
        // 0x800365DC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003664C;
    }
    // 0x800365DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800365E0: lh          $v1, 0x24($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X24);
    // 0x800365E4: lh          $a0, 0x26($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X26);
    // 0x800365E8: nop

    // 0x800365EC: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800365F0: beq         $at, $zero, L_80036600
    if (ctx->r1 == 0) {
        // 0x800365F4: subu        $v0, $a0, $v1
        ctx->r2 = SUB32(ctx->r4, ctx->r3);
            goto L_80036600;
    }
    // 0x800365F4: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x800365F8: b           L_800366B0
    // 0x800365FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_800366B0;
    // 0x800365FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80036600:
    // 0x80036600: bgez        $v0, L_80036618
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80036604: sll         $v1, $v0, 16
        ctx->r3 = S32(ctx->r2 << 16);
            goto L_80036618;
    }
    // 0x80036604: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80036608: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8003660C: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x80036610: b           L_80036620
    // 0x80036614: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
        goto L_80036620;
    // 0x80036614: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
L_80036618:
    // 0x80036618: sra         $t0, $v1, 16
    ctx->r8 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003661C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80036620:
    // 0x80036620: slti        $at, $v1, 0x60
    ctx->r1 = SIGNED(ctx->r3) < 0X60 ? 1 : 0;
    // 0x80036624: beq         $at, $zero, L_8003663C
    if (ctx->r1 == 0) {
        // 0x80036628: slti        $at, $v1, 0x71
        ctx->r1 = SIGNED(ctx->r3) < 0X71 ? 1 : 0;
            goto L_8003663C;
    }
    // 0x80036628: slti        $at, $v1, 0x71
    ctx->r1 = SIGNED(ctx->r3) < 0X71 ? 1 : 0;
    // 0x8003662C: sh          $v1, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r3;
    // 0x80036630: b           L_800366B0
    // 0x80036634: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_800366B0;
    // 0x80036634: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80036638: slti        $at, $v1, 0x71
    ctx->r1 = SIGNED(ctx->r3) < 0X71 ? 1 : 0;
L_8003663C:
    // 0x8003663C: bne         $at, $zero, L_800366B0
    if (ctx->r1 != 0) {
        // 0x80036640: sh          $v1, 0x24($sp)
        MEM_H(0X24, ctx->r29) = ctx->r3;
            goto L_800366B0;
    }
    // 0x80036640: sh          $v1, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r3;
    // 0x80036644: b           L_800366B0
    // 0x80036648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800366B0;
    // 0x80036648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8003664C:
    // 0x8003664C: lh          $a0, 0x26($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X26);
    // 0x80036650: nop

    // 0x80036654: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80036658: beq         $at, $zero, L_80036668
    if (ctx->r1 == 0) {
        // 0x8003665C: subu        $v0, $a0, $v1
        ctx->r2 = SUB32(ctx->r4, ctx->r3);
            goto L_80036668;
    }
    // 0x8003665C: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x80036660: b           L_800366B0
    // 0x80036664: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800366B0;
    // 0x80036664: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80036668:
    // 0x80036668: bgez        $v0, L_80036680
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003666C: sll         $v1, $v0, 16
        ctx->r3 = S32(ctx->r2 << 16);
            goto L_80036680;
    }
    // 0x8003666C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80036670: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x80036674: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x80036678: b           L_80036688
    // 0x8003667C: sra         $v1, $t1, 16
    ctx->r3 = S32(SIGNED(ctx->r9) >> 16);
        goto L_80036688;
    // 0x8003667C: sra         $v1, $t1, 16
    ctx->r3 = S32(SIGNED(ctx->r9) >> 16);
L_80036680:
    // 0x80036680: sra         $t3, $v1, 16
    ctx->r11 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80036684: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
L_80036688:
    // 0x80036688: slti        $at, $v1, 0x60
    ctx->r1 = SIGNED(ctx->r3) < 0X60 ? 1 : 0;
    // 0x8003668C: beq         $at, $zero, L_800366A4
    if (ctx->r1 == 0) {
        // 0x80036690: slti        $at, $v1, 0x71
        ctx->r1 = SIGNED(ctx->r3) < 0X71 ? 1 : 0;
            goto L_800366A4;
    }
    // 0x80036690: slti        $at, $v1, 0x71
    ctx->r1 = SIGNED(ctx->r3) < 0X71 ? 1 : 0;
    // 0x80036694: sh          $v1, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r3;
    // 0x80036698: b           L_800366B0
    // 0x8003669C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800366B0;
    // 0x8003669C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800366A0: slti        $at, $v1, 0x71
    ctx->r1 = SIGNED(ctx->r3) < 0X71 ? 1 : 0;
L_800366A4:
    // 0x800366A4: bne         $at, $zero, L_800366B0
    if (ctx->r1 != 0) {
        // 0x800366A8: sh          $v1, 0x24($sp)
        MEM_H(0X24, ctx->r29) = ctx->r3;
            goto L_800366B0;
    }
    // 0x800366A8: sh          $v1, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r3;
    // 0x800366AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800366B0:
    // 0x800366B0: bne         $a1, $zero, L_800366D8
    if (ctx->r5 != 0) {
        // 0x800366B4: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800366D8;
    }
    // 0x800366B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800366B8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800366BC: addiu       $a1, $a1, -0x4500
    ctx->r5 = ADD32(ctx->r5, -0X4500);
    // 0x800366C0: lw          $t4, 0x20($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X20);
    // 0x800366C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800366C8: sw          $zero, 0x14($t4)
    MEM_W(0X14, ctx->r12) = 0;
    // 0x800366CC: lw          $t5, 0x20($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X20);
    // 0x800366D0: b           L_80036710
    // 0x800366D4: sw          $zero, 0x18($t5)
    MEM_W(0X18, ctx->r13) = 0;
        goto L_80036710;
    // 0x800366D4: sw          $zero, 0x18($t5)
    MEM_W(0X18, ctx->r13) = 0;
L_800366D8:
    // 0x800366D8: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x800366DC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800366E0: addiu       $t8, $t8, -0x4070
    ctx->r24 = ADD32(ctx->r24, -0X4070);
    // 0x800366E4: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800366E8: addiu       $a1, $a1, -0x4500
    ctx->r5 = ADD32(ctx->r5, -0X4500);
    // 0x800366EC: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800366F0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800366F4: lw          $t0, 0x20($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X20);
    // 0x800366F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800366FC: sw          $t9, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r25;
    // 0x80036700: lw          $t2, 0x20($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X20);
    // 0x80036704: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80036708: nop

    // 0x8003670C: sw          $t1, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r9;
L_80036710:
    // 0x80036710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036714: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80036718: jr          $ra
    // 0x8003671C: nop

    return;
    // 0x8003671C: nop

;}
RECOMP_FUNC void func_80036720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003672C: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80036730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036734: beq         $v1, $zero, L_80036934
    if (ctx->r3 == 0) {
        // 0x80036738: nop
    
            goto L_80036934;
    }
    // 0x80036738: nop

    // 0x8003673C: lw          $v0, 0x54($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X54);
    // 0x80036740: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80036744: beq         $v0, $zero, L_80036934
    if (ctx->r2 == 0) {
        // 0x80036748: addiu       $t0, $t0, -0x4500
        ctx->r8 = ADD32(ctx->r8, -0X4500);
            goto L_80036934;
    }
    // 0x80036748: addiu       $t0, $t0, -0x4500
    ctx->r8 = ADD32(ctx->r8, -0X4500);
    // 0x8003674C: lhu         $t7, 0x32($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X32);
    // 0x80036750: nop

    // 0x80036754: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x80036758: beq         $t8, $zero, L_80036780
    if (ctx->r24 == 0) {
        // 0x8003675C: nop
    
            goto L_80036780;
    }
    // 0x8003675C: nop

    // 0x80036760: lh          $t9, 0x1C($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X1C);
    // 0x80036764: lh          $t1, 0x42($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X42);
    // 0x80036768: nop

    // 0x8003676C: addu        $v1, $t9, $t1
    ctx->r3 = ADD32(ctx->r25, ctx->r9);
    // 0x80036770: addiu       $v1, $v1, -0xA
    ctx->r3 = ADD32(ctx->r3, -0XA);
    // 0x80036774: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x80036778: b           L_80036798
    // 0x8003677C: sra         $v1, $t2, 16
    ctx->r3 = S32(SIGNED(ctx->r10) >> 16);
        goto L_80036798;
    // 0x8003677C: sra         $v1, $t2, 16
    ctx->r3 = S32(SIGNED(ctx->r10) >> 16);
L_80036780:
    // 0x80036780: lh          $t4, 0x1C($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X1C);
    // 0x80036784: lh          $t5, 0x42($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X42);
    // 0x80036788: nop

    // 0x8003678C: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x80036790: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80036794: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
L_80036798:
    // 0x80036798: lw          $a2, 0x20($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X20);
    // 0x8003679C: nop

    // 0x800367A0: lhu         $a3, 0x32($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X32);
    // 0x800367A4: lh          $v0, 0x1C($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X1C);
    // 0x800367A8: andi        $t8, $a3, 0x10
    ctx->r24 = ctx->r7 & 0X10;
    // 0x800367AC: bne         $t8, $zero, L_800367C8
    if (ctx->r24 != 0) {
        // 0x800367B0: or          $a3, $t8, $zero
        ctx->r7 = ctx->r24 | 0;
            goto L_800367C8;
    }
    // 0x800367B0: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x800367B4: lh          $t9, 0x42($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X42);
    // 0x800367B8: nop

    // 0x800367BC: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800367C0: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x800367C4: sra         $v0, $t1, 16
    ctx->r2 = S32(SIGNED(ctx->r9) >> 16);
L_800367C8:
    // 0x800367C8: subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
    // 0x800367CC: bgez        $a0, L_800367DC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800367D0: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800367DC;
    }
    // 0x800367D0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800367D4: b           L_800367DC
    // 0x800367D8: negu        $a1, $a0
    ctx->r5 = SUB32(0, ctx->r4);
        goto L_800367DC;
    // 0x800367D8: negu        $a1, $a0
    ctx->r5 = SUB32(0, ctx->r4);
L_800367DC:
    // 0x800367DC: slti        $at, $a1, 0x2BC
    ctx->r1 = SIGNED(ctx->r5) < 0X2BC ? 1 : 0;
    // 0x800367E0: bne         $at, $zero, L_80036820
    if (ctx->r1 != 0) {
        // 0x800367E4: lui         $a1, 0x800C
        ctx->r5 = S32(0X800C << 16);
            goto L_80036820;
    }
    // 0x800367E4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800367E8: lh          $a1, -0x878($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X878);
    // 0x800367EC: nop

    // 0x800367F0: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800367F4: bne         $at, $zero, L_80036810
    if (ctx->r1 != 0) {
        // 0x800367F8: nop
    
            goto L_80036810;
    }
    // 0x800367F8: nop

    // 0x800367FC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80036800: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x80036804: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80036808: b           L_80036820
    // 0x8003680C: subu        $a0, $v1, $t4
    ctx->r4 = SUB32(ctx->r3, ctx->r12);
        goto L_80036820;
    // 0x8003680C: subu        $a0, $v1, $t4
    ctx->r4 = SUB32(ctx->r3, ctx->r12);
L_80036810:
    // 0x80036810: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80036814: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x80036818: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8003681C: subu        $a0, $t6, $v0
    ctx->r4 = SUB32(ctx->r14, ctx->r2);
L_80036820:
    // 0x80036820: sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4 << 16);
    // 0x80036824: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80036828: bgez        $t7, L_80036838
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8003682C: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_80036838;
    }
    // 0x8003682C: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80036830: b           L_8003683C
    // 0x80036834: negu        $a1, $t7
    ctx->r5 = SUB32(0, ctx->r15);
        goto L_8003683C;
    // 0x80036834: negu        $a1, $t7
    ctx->r5 = SUB32(0, ctx->r15);
L_80036838:
    // 0x80036838: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8003683C:
    // 0x8003683C: slti        $at, $a1, 0x61
    ctx->r1 = SIGNED(ctx->r5) < 0X61 ? 1 : 0;
    // 0x80036840: beq         $at, $zero, L_800368B8
    if (ctx->r1 == 0) {
        // 0x80036844: nop
    
            goto L_800368B8;
    }
    // 0x80036844: nop

    // 0x80036848: bgtz        $v1, L_80036880
    if (SIGNED(ctx->r3) > 0) {
        // 0x8003684C: nop
    
            goto L_80036880;
    }
    // 0x8003684C: nop

    // 0x80036850: beq         $a3, $zero, L_800368AC
    if (ctx->r7 == 0) {
        // 0x80036854: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_800368AC;
    }
    // 0x80036854: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80036858: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003685C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80036860: sh          $t8, 0xC($t9)
    MEM_H(0XC, ctx->r25) = ctx->r24;
    // 0x80036864: lw          $a1, 0x20($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X20);
    // 0x80036868: jal         0x80047A20
    // 0x8003686C: addiu       $a0, $a0, -0x6420
    ctx->r4 = ADD32(ctx->r4, -0X6420);
    func_80047A20(rdram, ctx);
        goto after_0;
    // 0x8003686C: addiu       $a0, $a0, -0x6420
    ctx->r4 = ADD32(ctx->r4, -0X6420);
    after_0:
    // 0x80036870: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80036874: lw          $a2, -0x44E0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44E0);
    // 0x80036878: b           L_800368B0
    // 0x8003687C: sw          $zero, 0x14($a2)
    MEM_W(0X14, ctx->r6) = 0;
        goto L_800368B0;
    // 0x8003687C: sw          $zero, 0x14($a2)
    MEM_W(0X14, ctx->r6) = 0;
L_80036880:
    // 0x80036880: bne         $a3, $zero, L_800368AC
    if (ctx->r7 != 0) {
        // 0x80036884: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_800368AC;
    }
    // 0x80036884: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80036888: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8003688C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80036890: sh          $t1, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r9;
    // 0x80036894: lw          $a1, 0x20($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X20);
    // 0x80036898: jal         0x80047A20
    // 0x8003689C: addiu       $a0, $a0, -0x6420
    ctx->r4 = ADD32(ctx->r4, -0X6420);
    func_80047A20(rdram, ctx);
        goto after_1;
    // 0x8003689C: addiu       $a0, $a0, -0x6420
    ctx->r4 = ADD32(ctx->r4, -0X6420);
    after_1:
    // 0x800368A0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800368A4: lw          $a2, -0x44E0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44E0);
    // 0x800368A8: nop

L_800368AC:
    // 0x800368AC: sw          $zero, 0x14($a2)
    MEM_W(0X14, ctx->r6) = 0;
L_800368B0:
    // 0x800368B0: b           L_80036934
    // 0x800368B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80036934;
    // 0x800368B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800368B8:
    // 0x800368B8: bgtz        $v1, L_800368F0
    if (SIGNED(ctx->r3) > 0) {
        // 0x800368BC: nop
    
            goto L_800368F0;
    }
    // 0x800368BC: nop

    // 0x800368C0: bne         $a3, $zero, L_8003691C
    if (ctx->r7 != 0) {
        // 0x800368C4: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_8003691C;
    }
    // 0x800368C4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800368C8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800368CC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800368D0: sh          $t3, 0xC($t4)
    MEM_H(0XC, ctx->r12) = ctx->r11;
    // 0x800368D4: lw          $a1, 0x20($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X20);
    // 0x800368D8: jal         0x80047A20
    // 0x800368DC: addiu       $a0, $a0, -0x6420
    ctx->r4 = ADD32(ctx->r4, -0X6420);
    func_80047A20(rdram, ctx);
        goto after_2;
    // 0x800368DC: addiu       $a0, $a0, -0x6420
    ctx->r4 = ADD32(ctx->r4, -0X6420);
    after_2:
    // 0x800368E0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800368E4: lw          $a2, -0x44E0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44E0);
    // 0x800368E8: b           L_80036920
    // 0x800368EC: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
        goto L_80036920;
    // 0x800368EC: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
L_800368F0:
    // 0x800368F0: beq         $a3, $zero, L_8003691C
    if (ctx->r7 == 0) {
        // 0x800368F4: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_8003691C;
    }
    // 0x800368F4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800368F8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800368FC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80036900: sh          $t5, 0xC($t6)
    MEM_H(0XC, ctx->r14) = ctx->r13;
    // 0x80036904: lw          $a1, 0x20($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X20);
    // 0x80036908: jal         0x80047A20
    // 0x8003690C: addiu       $a0, $a0, -0x6420
    ctx->r4 = ADD32(ctx->r4, -0X6420);
    func_80047A20(rdram, ctx);
        goto after_3;
    // 0x8003690C: addiu       $a0, $a0, -0x6420
    ctx->r4 = ADD32(ctx->r4, -0X6420);
    after_3:
    // 0x80036910: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80036914: lw          $a2, -0x44E0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44E0);
    // 0x80036918: nop

L_8003691C:
    // 0x8003691C: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
L_80036920:
    // 0x80036920: sw          $zero, 0x18($a2)
    MEM_W(0X18, ctx->r6) = 0;
    // 0x80036924: jal         0x8003614C
    // 0x80036928: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    func_8003614C(rdram, ctx);
        goto after_4;
    // 0x80036928: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    after_4:
    // 0x8003692C: b           L_80036934
    // 0x80036930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036934;
    // 0x80036930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036934:
    // 0x80036934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003693C: jr          $ra
    // 0x80036940: nop

    return;
    // 0x80036940: nop

;}
RECOMP_FUNC void func_80036944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036944: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80036948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003694C: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80036950: nop

    // 0x80036954: beq         $v1, $zero, L_80036988
    if (ctx->r3 == 0) {
        // 0x80036958: nop
    
            goto L_80036988;
    }
    // 0x80036958: nop

    // 0x8003695C: lw          $v0, 0x54($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X54);
    // 0x80036960: nop

    // 0x80036964: bne         $v0, $zero, L_800369A0
    if (ctx->r2 != 0) {
        // 0x80036968: nop
    
            goto L_800369A0;
    }
    // 0x80036968: nop

    // 0x8003696C: jal         0x8000D624
    // 0x80036970: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8000D624(rdram, ctx);
        goto after_0;
    // 0x80036970: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80036974: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80036978: nop

    // 0x8003697C: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80036980: b           L_800369A0
    // 0x80036984: nop

        goto L_800369A0;
    // 0x80036984: nop

L_80036988:
    // 0x80036988: jal         0x8000D624
    // 0x8003698C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8000D624(rdram, ctx);
        goto after_1;
    // 0x8003698C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80036990: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80036994: nop

    // 0x80036998: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x8003699C: nop

L_800369A0:
    // 0x800369A0: beq         $v1, $zero, L_80036A40
    if (ctx->r3 == 0) {
        // 0x800369A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80036A40;
    }
    // 0x800369A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800369A8: lw          $v0, 0x54($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X54);
    // 0x800369AC: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800369B0: bne         $v0, $zero, L_800369D0
    if (ctx->r2 != 0) {
        // 0x800369B4: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800369D0;
    }
    // 0x800369B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800369B8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800369BC: lw          $t7, -0x44E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X44E0);
    // 0x800369C0: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x800369C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800369C8: b           L_80036A74
    // 0x800369CC: sw          $t6, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r14;
        goto L_80036A74;
    // 0x800369CC: sw          $t6, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r14;
L_800369D0:
    // 0x800369D0: lw          $a0, -0x44E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X44E0);
    // 0x800369D4: lh          $v1, 0x20($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X20);
    // 0x800369D8: lh          $t0, 0x20($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X20);
    // 0x800369DC: addiu       $t9, $v1, -0x58
    ctx->r25 = ADD32(ctx->r3, -0X58);
    // 0x800369E0: subu        $v1, $t9, $t0
    ctx->r3 = SUB32(ctx->r25, ctx->r8);
    // 0x800369E4: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x800369E8: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800369EC: bgez        $t2, L_800369FC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800369F0: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_800369FC;
    }
    // 0x800369F0: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x800369F4: b           L_80036A00
    // 0x800369F8: negu        $v0, $t2
    ctx->r2 = SUB32(0, ctx->r10);
        goto L_80036A00;
    // 0x800369F8: negu        $v0, $t2
    ctx->r2 = SUB32(0, ctx->r10);
L_800369FC:
    // 0x800369FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80036A00:
    // 0x80036A00: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80036A04: beq         $at, $zero, L_80036A14
    if (ctx->r1 == 0) {
        // 0x80036A08: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80036A14;
    }
    // 0x80036A08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80036A0C: b           L_80036A74
    // 0x80036A10: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
        goto L_80036A74;
    // 0x80036A10: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
L_80036A14:
    // 0x80036A14: bltz        $v1, L_80036A30
    if (SIGNED(ctx->r3) < 0) {
        // 0x80036A18: lui         $t4, 0xFFFE
        ctx->r12 = S32(0XFFFE << 16);
            goto L_80036A30;
    }
    // 0x80036A18: lui         $t4, 0xFFFE
    ctx->r12 = S32(0XFFFE << 16);
    // 0x80036A1C: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x80036A20: ori         $t3, $t3, 0x8000
    ctx->r11 = ctx->r11 | 0X8000;
    // 0x80036A24: sw          $t3, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r11;
    // 0x80036A28: b           L_80036A74
    // 0x80036A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036A74;
    // 0x80036A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036A30:
    // 0x80036A30: ori         $t4, $t4, 0x8000
    ctx->r12 = ctx->r12 | 0X8000;
    // 0x80036A34: sw          $t4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r12;
    // 0x80036A38: b           L_80036A74
    // 0x80036A3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036A74;
    // 0x80036A3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036A40:
    // 0x80036A40: lh          $v1, 0x1A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X1A);
    // 0x80036A44: lui         $t7, 0xFFFE
    ctx->r15 = S32(0XFFFE << 16);
    // 0x80036A48: bltz        $v1, L_80036A68
    if (SIGNED(ctx->r3) < 0) {
        // 0x80036A4C: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80036A68;
    }
    // 0x80036A4C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80036A50: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80036A54: lw          $t6, -0x44E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44E0);
    // 0x80036A58: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80036A5C: ori         $t5, $t5, 0x8000
    ctx->r13 = ctx->r13 | 0X8000;
    // 0x80036A60: b           L_80036A74
    // 0x80036A64: sw          $t5, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r13;
        goto L_80036A74;
    // 0x80036A64: sw          $t5, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r13;
L_80036A68:
    // 0x80036A68: lw          $t8, -0x44E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X44E0);
    // 0x80036A6C: ori         $t7, $t7, 0x8000
    ctx->r15 = ctx->r15 | 0X8000;
    // 0x80036A70: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
L_80036A74:
    // 0x80036A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036A78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80036A7C: jr          $ra
    // 0x80036A80: nop

    return;
    // 0x80036A80: nop

;}
RECOMP_FUNC void func_80036A84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036A84: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80036A88: lw          $v1, -0x44E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X44E0);
    // 0x80036A8C: lhu         $t6, 0x28($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X28);
    // 0x80036A90: lh          $t7, 0x20($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X20);
    // 0x80036A94: nop

    // 0x80036A98: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x80036A9C: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80036AA0: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80036AA4: bgez        $t9, L_80036AB4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80036AA8: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80036AB4;
    }
    // 0x80036AA8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80036AAC: b           L_80036AB8
    // 0x80036AB0: negu        $a0, $t9
    ctx->r4 = SUB32(0, ctx->r25);
        goto L_80036AB8;
    // 0x80036AB0: negu        $a0, $t9
    ctx->r4 = SUB32(0, ctx->r25);
L_80036AB4:
    // 0x80036AB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80036AB8:
    // 0x80036AB8: slti        $at, $a0, 0xB
    ctx->r1 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
    // 0x80036ABC: beq         $at, $zero, L_80036AD0
    if (ctx->r1 == 0) {
            // 0x80036AC0: nop

    func_80036AD0(rdram, ctx);
    return;
    }
    // 0x80036AC0: nop

    // 0x80036AC4: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x80036AC8: jr          $ra
    // 0x80036ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80036ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80036AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036AD0: bltz        $v0, L_80036AE8
    if (SIGNED(ctx->r2) < 0) {
        // 0x80036AD4: lui         $t1, 0xFFFE
        ctx->r9 = S32(0XFFFE << 16);
            goto L_80036AE8;
    }
    // 0x80036AD4: lui         $t1, 0xFFFE
    ctx->r9 = S32(0XFFFE << 16);
    // 0x80036AD8: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80036ADC: ori         $t0, $t0, 0x8000
    ctx->r8 = ctx->r8 | 0X8000;
    // 0x80036AE0: b           L_80036AF0
    // 0x80036AE4: sw          $t0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r8;
        goto L_80036AF0;
    // 0x80036AE4: sw          $t0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r8;
L_80036AE8:
    // 0x80036AE8: ori         $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 | 0X8000;
    // 0x80036AEC: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
L_80036AF0:
    // 0x80036AF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036AF4: jr          $ra
    // 0x80036AF8: nop

    return;
    // 0x80036AF8: nop

;}
RECOMP_FUNC void func_80036AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036AFC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80036B00: addiu       $a2, $a2, -0x4500
    ctx->r6 = ADD32(ctx->r6, -0X4500);
    ctx->hi = hi; ctx->lo = lo;
    func_80036B04(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_80036B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036B08: lw          $a1, 0x20($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X20);
    // 0x80036B0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036B10: lhu         $v0, 0x28($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X28);
    // 0x80036B14: lh          $t8, 0x20($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X20);
    // 0x80036B18: addiu       $t7, $v0, -0x6C
    ctx->r15 = ADD32(ctx->r2, -0X6C);
    // 0x80036B1C: subu        $v0, $t7, $t8
    ctx->r2 = SUB32(ctx->r15, ctx->r24);
    // 0x80036B20: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80036B24: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80036B28: bgez        $t0, L_80036B38
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80036B2C: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_80036B38;
    }
    // 0x80036B2C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80036B30: b           L_80036B3C
    // 0x80036B34: negu        $v1, $t0
    ctx->r3 = SUB32(0, ctx->r8);
        goto L_80036B3C;
    // 0x80036B34: negu        $v1, $t0
    ctx->r3 = SUB32(0, ctx->r8);
L_80036B38:
    // 0x80036B38: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80036B3C:
    // 0x80036B3C: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    // 0x80036B40: beq         $at, $zero, L_80036B54
    if (ctx->r1 == 0) {
        // 0x80036B44: nop
    
            goto L_80036B54;
    }
    // 0x80036B44: nop

    // 0x80036B48: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    // 0x80036B4C: b           L_80036BFC
    // 0x80036B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80036BFC;
    // 0x80036B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80036B54:
    // 0x80036B54: bltz        $v0, L_80036B6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80036B58: lui         $t2, 0xFFFE
        ctx->r10 = S32(0XFFFE << 16);
            goto L_80036B6C;
    }
    // 0x80036B58: lui         $t2, 0xFFFE
    ctx->r10 = S32(0XFFFE << 16);
    // 0x80036B5C: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x80036B60: ori         $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 | 0X8000;
    // 0x80036B64: b           L_80036B74
    // 0x80036B68: sw          $t1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r9;
        goto L_80036B74;
    // 0x80036B68: sw          $t1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r9;
L_80036B6C:
    // 0x80036B6C: ori         $t2, $t2, 0x8000
    ctx->r10 = ctx->r10 | 0X8000;
    // 0x80036B70: sw          $t2, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r10;
L_80036B74:
    // 0x80036B74: bgez        $v0, L_80036B84
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80036B78: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80036B84;
    }
    // 0x80036B78: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80036B7C: b           L_80036B84
    // 0x80036B80: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80036B84;
    // 0x80036B80: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80036B84:
    // 0x80036B84: slti        $at, $v1, 0x1F
    ctx->r1 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
    // 0x80036B88: beq         $at, $zero, L_80036BFC
    if (ctx->r1 == 0) {
        // 0x80036B8C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80036BFC;
    }
    // 0x80036B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036B90: lw          $t3, 0x20($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X20);
    // 0x80036B94: nop

    // 0x80036B98: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x80036B9C: nop

    // 0x80036BA0: bne         $t4, $zero, L_80036BFC
    if (ctx->r12 != 0) {
        // 0x80036BA4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80036BFC;
    }
    // 0x80036BA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036BA8: lhu         $t5, 0x38($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X38);
    // 0x80036BAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80036BB0: beq         $t5, $at, L_80036BDC
    if (ctx->r13 == ctx->r1) {
        // 0x80036BB4: sh          $zero, 0xC($a0)
        MEM_H(0XC, ctx->r4) = 0;
            goto L_80036BDC;
    }
    // 0x80036BB4: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x80036BB8: lw          $t7, 0x20($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X20);
    // 0x80036BBC: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80036BC0: sw          $t6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r14;
    // 0x80036BC4: lw          $a1, 0x20($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X20);
    // 0x80036BC8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80036BCC: jal         0x80047A20
    // 0x80036BD0: addiu       $a0, $a0, -0x6620
    ctx->r4 = ADD32(ctx->r4, -0X6620);
    func_80047A20(rdram, ctx);
        goto after_0;
    // 0x80036BD0: addiu       $a0, $a0, -0x6620
    ctx->r4 = ADD32(ctx->r4, -0X6620);
    after_0:
    // 0x80036BD4: b           L_80036BFC
    // 0x80036BD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036BFC;
    // 0x80036BD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036BDC:
    // 0x80036BDC: lw          $t9, 0x20($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X20);
    // 0x80036BE0: lui         $t8, 0xFFFF
    ctx->r24 = S32(0XFFFF << 16);
    // 0x80036BE4: sw          $t8, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r24;
    // 0x80036BE8: lw          $a1, 0x20($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X20);
    // 0x80036BEC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80036BF0: jal         0x80047A20
    // 0x80036BF4: addiu       $a0, $a0, -0x6520
    ctx->r4 = ADD32(ctx->r4, -0X6520);
    func_80047A20(rdram, ctx);
        goto after_1;
    // 0x80036BF4: addiu       $a0, $a0, -0x6520
    ctx->r4 = ADD32(ctx->r4, -0X6520);
    after_1:
    // 0x80036BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036BFC:
    // 0x80036BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036C00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036C04: jr          $ra
    // 0x80036C08: nop

    return;
    // 0x80036C08: nop

;}
RECOMP_FUNC void func_80036C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036C0C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80036C10: lw          $v1, -0x44E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X44E0);
    // 0x80036C14: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80036C18: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80036C1C: lh          $t8, 0x20($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X20);
    // 0x80036C20: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80036C24: subu        $a0, $t7, $t8
    ctx->r4 = SUB32(ctx->r15, ctx->r24);
    // 0x80036C28: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80036C2C: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80036C30: bgez        $t0, L_80036C40
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80036C34: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80036C40;
    }
    // 0x80036C34: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80036C38: b           L_80036C44
    // 0x80036C3C: negu        $v0, $t0
    ctx->r2 = SUB32(0, ctx->r8);
        goto L_80036C44;
    // 0x80036C3C: negu        $v0, $t0
    ctx->r2 = SUB32(0, ctx->r8);
L_80036C40:
    // 0x80036C40: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80036C44:
    // 0x80036C44: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80036C48: beq         $at, $zero, L_80036C5C
    if (ctx->r1 == 0) {
            // 0x80036C4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    func_80036C5C(rdram, ctx);
    return;
    }
    // 0x80036C4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036C50: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x80036C54: jr          $ra
    // 0x80036C58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80036C58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80036C5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036C5C: bltz        $a0, L_80036C74
    if (SIGNED(ctx->r4) < 0) {
        // 0x80036C60: lui         $t2, 0xFFFE
        ctx->r10 = S32(0XFFFE << 16);
            goto L_80036C74;
    }
    // 0x80036C60: lui         $t2, 0xFFFE
    ctx->r10 = S32(0XFFFE << 16);
    // 0x80036C64: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x80036C68: ori         $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 | 0X8000;
    // 0x80036C6C: b           L_80036C7C
    // 0x80036C70: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
        goto L_80036C7C;
    // 0x80036C70: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
L_80036C74:
    // 0x80036C74: ori         $t2, $t2, 0x8000
    ctx->r10 = ctx->r10 | 0X8000;
    // 0x80036C78: sw          $t2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r10;
L_80036C7C:
    // 0x80036C7C: jr          $ra
    // 0x80036C80: nop

    return;
    // 0x80036C80: nop

;}
RECOMP_FUNC void func_80036C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036C84: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80036C88: lw          $v1, -0x44E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X44E0);
    // 0x80036C8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80036C90: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80036C94: lw          $t7, 0x618($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X618);
    // 0x80036C98: lw          $t6, 0x20($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X20);
    // 0x80036C9C: lui         $at, 0x30
    ctx->r1 = S32(0X30 << 16);
    // 0x80036CA0: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x80036CA4: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80036CA8: beq         $at, $zero, L_80036CB8
    if (ctx->r1 == 0) {
            // 0x80036CAC: lui         $t8, 0xFFFE
    ctx->r24 = S32(0XFFFE << 16);
    func_80036CB8(rdram, ctx);
    return;
    }
    // 0x80036CAC: lui         $t8, 0xFFFE
    ctx->r24 = S32(0XFFFE << 16);
    // 0x80036CB0: jr          $ra
    // 0x80036CB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80036CB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80036CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036CB8: ori         $t8, $t8, 0x8000
    ctx->r24 = ctx->r24 | 0X8000;
    // 0x80036CBC: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
    // 0x80036CC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036CC4: jr          $ra
    // 0x80036CC8: nop

    return;
    // 0x80036CC8: nop

;}
RECOMP_FUNC void func_80036CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036CCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036CD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036CD4: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80036CD8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80036CDC: beq         $v0, $zero, L_80036DBC
    if (ctx->r2 == 0) {
        // 0x80036CE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80036DBC;
    }
    // 0x80036CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036CE4: lw          $a0, 0x54($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X54);
    // 0x80036CE8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80036CEC: beq         $a0, $zero, L_80036DB8
    if (ctx->r4 == 0) {
        // 0x80036CF0: addiu       $a3, $a3, -0x4500
        ctx->r7 = ADD32(ctx->r7, -0X4500);
            goto L_80036DB8;
    }
    // 0x80036CF0: addiu       $a3, $a3, -0x4500
    ctx->r7 = ADD32(ctx->r7, -0X4500);
    // 0x80036CF4: lw          $t7, 0x20($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X20);
    // 0x80036CF8: lh          $v0, 0x1C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X1C);
    // 0x80036CFC: lh          $v1, 0x1C($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X1C);
    // 0x80036D00: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80036D04: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80036D08: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80036D0C: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80036D10: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80036D14: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80036D18: bgez        $t9, L_80036D28
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80036D1C: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80036D28;
    }
    // 0x80036D1C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80036D20: b           L_80036D2C
    // 0x80036D24: negu        $a0, $t9
    ctx->r4 = SUB32(0, ctx->r25);
        goto L_80036D2C;
    // 0x80036D24: negu        $a0, $t9
    ctx->r4 = SUB32(0, ctx->r25);
L_80036D28:
    // 0x80036D28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80036D2C:
    // 0x80036D2C: slti        $at, $a0, 0x258
    ctx->r1 = SIGNED(ctx->r4) < 0X258 ? 1 : 0;
    // 0x80036D30: bne         $at, $zero, L_80036D78
    if (ctx->r1 != 0) {
        // 0x80036D34: lui         $t0, 0x800C
        ctx->r8 = S32(0X800C << 16);
            goto L_80036D78;
    }
    // 0x80036D34: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80036D38: lh          $t0, 0x614($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X614);
    // 0x80036D3C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80036D40: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80036D44: bne         $at, $zero, L_80036D64
    if (ctx->r1 != 0) {
        // 0x80036D48: lui         $t4, 0x800C
        ctx->r12 = S32(0X800C << 16);
            goto L_80036D64;
    }
    // 0x80036D48: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80036D4C: lh          $t1, -0x878($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X878);
    // 0x80036D50: nop

    // 0x80036D54: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80036D58: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x80036D5C: b           L_80036D78
    // 0x80036D60: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
        goto L_80036D78;
    // 0x80036D60: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
L_80036D64:
    // 0x80036D64: lh          $t4, -0x878($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X878);
    // 0x80036D68: nop

    // 0x80036D6C: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x80036D70: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x80036D74: sra         $v1, $t5, 16
    ctx->r3 = S32(SIGNED(ctx->r13) >> 16);
L_80036D78:
    // 0x80036D78: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80036D7C: bne         $at, $zero, L_80036DA4
    if (ctx->r1 != 0) {
        // 0x80036D80: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_80036DA4;
    }
    // 0x80036D80: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80036D84: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80036D88: sh          $t7, 0x38($a2)
    MEM_H(0X38, ctx->r6) = ctx->r15;
    // 0x80036D8C: lw          $a1, 0x20($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X20);
    // 0x80036D90: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80036D94: jal         0x80047A20
    // 0x80036D98: addiu       $a0, $a0, -0x6520
    ctx->r4 = ADD32(ctx->r4, -0X6520);
    func_80047A20(rdram, ctx);
        goto after_0;
    // 0x80036D98: addiu       $a0, $a0, -0x6520
    ctx->r4 = ADD32(ctx->r4, -0X6520);
    after_0:
    // 0x80036D9C: b           L_80036DBC
    // 0x80036DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80036DBC;
    // 0x80036DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036DA4:
    // 0x80036DA4: sh          $t8, 0x38($a2)
    MEM_H(0X38, ctx->r6) = ctx->r24;
    // 0x80036DA8: lw          $a1, 0x20($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X20);
    // 0x80036DAC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80036DB0: jal         0x80047A20
    // 0x80036DB4: addiu       $a0, $a0, -0x6620
    ctx->r4 = ADD32(ctx->r4, -0X6620);
    func_80047A20(rdram, ctx);
        goto after_1;
    // 0x80036DB4: addiu       $a0, $a0, -0x6620
    ctx->r4 = ADD32(ctx->r4, -0X6620);
    after_1:
L_80036DB8:
    // 0x80036DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036DBC:
    // 0x80036DBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036DC0: jr          $ra
    // 0x80036DC4: nop

    return;
    // 0x80036DC4: nop

;}
RECOMP_FUNC void func_80036DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036DC8: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80036DCC: lhu         $t6, -0x87C($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X87C);
    ctx->hi = hi; ctx->lo = lo;
    func_80036DD0(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_80036DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036DD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036DD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036DD8: bne         $t6, $zero, L_80036DF0
    if (ctx->r14 != 0) {
        // 0x80036DDC: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80036DF0;
    }
    // 0x80036DDC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80036DE0: jal         0x80036F28
    // 0x80036DE4: nop

    func_80036F28(rdram, ctx);
        goto after_0;
    // 0x80036DE4: nop

    after_0:
    // 0x80036DE8: b           L_80036F1C
    // 0x80036DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80036F1C;
    // 0x80036DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036DF0:
    // 0x80036DF0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80036DF4: lw          $a0, -0x44E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X44E0);
    // 0x80036DF8: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80036DFC: lw          $t8, 0x618($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X618);
    // 0x80036E00: lw          $t7, 0x20($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X20);
    // 0x80036E04: lui         $at, 0x30
    ctx->r1 = S32(0X30 << 16);
    // 0x80036E08: subu        $v0, $t7, $t8
    ctx->r2 = SUB32(ctx->r15, ctx->r24);
    // 0x80036E0C: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80036E10: beq         $at, $zero, L_80036ED0
    if (ctx->r1 == 0) {
        // 0x80036E14: nop
    
            goto L_80036ED0;
    }
    // 0x80036E14: nop

    // 0x80036E18: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80036E1C: nop

    // 0x80036E20: bne         $v0, $zero, L_80036E44
    if (ctx->r2 != 0) {
        // 0x80036E24: nop
    
            goto L_80036E44;
    }
    // 0x80036E24: nop

    // 0x80036E28: lhu         $t9, 0x7C($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X7C);
    // 0x80036E2C: nop

    // 0x80036E30: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x80036E34: bne         $t0, $zero, L_80036ED0
    if (ctx->r8 != 0) {
        // 0x80036E38: nop
    
            goto L_80036ED0;
    }
    // 0x80036E38: nop

    // 0x80036E3C: b           L_80036F1C
    // 0x80036E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80036F1C;
    // 0x80036E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036E44:
    // 0x80036E44: blez        $v0, L_80036E98
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80036E48: lui         $t4, 0x800C
        ctx->r12 = S32(0X800C << 16);
            goto L_80036E98;
    }
    // 0x80036E48: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80036E4C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80036E50: lw          $t1, 0x614($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X614);
    // 0x80036E54: lui         $at, 0x15E
    ctx->r1 = S32(0X15E << 16);
    // 0x80036E58: subu        $v1, $v0, $t1
    ctx->r3 = SUB32(ctx->r2, ctx->r9);
    // 0x80036E5C: bgez        $v1, L_80036E6C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80036E60: ori         $at, $at, 0x1
        ctx->r1 = ctx->r1 | 0X1;
            goto L_80036E6C;
    }
    // 0x80036E60: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80036E64: b           L_80036E70
    // 0x80036E68: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_80036E70;
    // 0x80036E68: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_80036E6C:
    // 0x80036E6C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80036E70:
    // 0x80036E70: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80036E74: beq         $at, $zero, L_80036ED0
    if (ctx->r1 == 0) {
        // 0x80036E78: nop
    
            goto L_80036ED0;
    }
    // 0x80036E78: nop

    // 0x80036E7C: lhu         $t2, 0x7C($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X7C);
    // 0x80036E80: nop

    // 0x80036E84: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x80036E88: bne         $t3, $zero, L_80036ED0
    if (ctx->r11 != 0) {
        // 0x80036E8C: nop
    
            goto L_80036ED0;
    }
    // 0x80036E8C: nop

    // 0x80036E90: b           L_80036F1C
    // 0x80036E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80036F1C;
    // 0x80036E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036E98:
    // 0x80036E98: lw          $t4, 0x614($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X614);
    // 0x80036E9C: nop

    // 0x80036EA0: subu        $v1, $v0, $t4
    ctx->r3 = SUB32(ctx->r2, ctx->r12);
    // 0x80036EA4: bgez        $v1, L_80036EB4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80036EA8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80036EB4;
    }
    // 0x80036EA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80036EAC: b           L_80036EB4
    // 0x80036EB0: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_80036EB4;
    // 0x80036EB0: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_80036EB4:
    // 0x80036EB4: bltz        $v0, L_80036ED0
    if (SIGNED(ctx->r2) < 0) {
        // 0x80036EB8: nop
    
            goto L_80036ED0;
    }
    // 0x80036EB8: nop

    // 0x80036EBC: lhu         $t5, 0x7C($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X7C);
    // 0x80036EC0: nop

    // 0x80036EC4: andi        $t6, $t5, 0x80
    ctx->r14 = ctx->r13 & 0X80;
    // 0x80036EC8: beq         $t6, $zero, L_80036F1C
    if (ctx->r14 == 0) {
        // 0x80036ECC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80036F1C;
    }
    // 0x80036ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036ED0:
    // 0x80036ED0: lhu         $t7, 0x7C($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X7C);
    // 0x80036ED4: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80036ED8: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x80036EDC: bne         $t8, $zero, L_80036EF4
    if (ctx->r24 != 0) {
        // 0x80036EE0: nop
    
            goto L_80036EF4;
    }
    // 0x80036EE0: nop

    // 0x80036EE4: lhu         $t9, -0x7A2($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X7A2);
    // 0x80036EE8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80036EEC: beq         $t9, $zero, L_80036F04
    if (ctx->r25 == 0) {
        // 0x80036EF0: nop
    
            goto L_80036F04;
    }
    // 0x80036EF0: nop

L_80036EF4:
    // 0x80036EF4: jal         0x80036F28
    // 0x80036EF8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80036F28(rdram, ctx);
        goto after_1;
    // 0x80036EF8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80036EFC: b           L_80036F1C
    // 0x80036F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80036F1C;
    // 0x80036F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036F04:
    // 0x80036F04: sh          $zero, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = 0;
    // 0x80036F08: sh          $zero, 0x22($a1)
    MEM_H(0X22, ctx->r5) = 0;
    // 0x80036F0C: sh          $zero, 0xA($a1)
    MEM_H(0XA, ctx->r5) = 0;
    // 0x80036F10: jal         0x8000D624
    // 0x80036F14: sh          $zero, 0x2A($a1)
    MEM_H(0X2A, ctx->r5) = 0;
    func_8000D624(rdram, ctx);
        goto after_2;
    // 0x80036F14: sh          $zero, 0x2A($a1)
    MEM_H(0X2A, ctx->r5) = 0;
    after_2:
    // 0x80036F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036F1C:
    // 0x80036F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036F20: jr          $ra
    // 0x80036F24: nop

    return;
    // 0x80036F24: nop

;}
RECOMP_FUNC void func_80036F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036F2C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80036F30: lw          $t6, -0x44E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44E0);
    // 0x80036F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036F38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80036F3C: lhu         $t7, 0x7C($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X7C);
    // 0x80036F40: nop

    // 0x80036F44: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x80036F48: beq         $t8, $zero, L_80036F68
    if (ctx->r24 == 0) {
        // 0x80036F4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80036F68;
    }
    // 0x80036F4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036F50: jal         0x80037294
    // 0x80036F54: nop

    func_80037294(rdram, ctx);
        goto after_0;
    // 0x80036F54: nop

    after_0:
    // 0x80036F58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80036F5C: jal         0x80035ED8
    // 0x80036F60: nop

    func_80035ED8(rdram, ctx);
        goto after_1;
    // 0x80036F60: nop

    after_1:
    // 0x80036F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036F68:
    // 0x80036F68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036F6C: jr          $ra
    // 0x80036F70: nop

    return;
    // 0x80036F70: nop

;}
RECOMP_FUNC void func_80036F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036F74: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80036F78: lhu         $t6, -0x87C($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X87C);
    ctx->hi = hi; ctx->lo = lo;
    func_80036F7C(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_80036F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80036F7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036F80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036F84: bne         $t6, $zero, L_80036F9C
    if (ctx->r14 != 0) {
        // 0x80036F88: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80036F9C;
    }
    // 0x80036F88: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80036F8C: jal         0x80037094
    // 0x80036F90: nop

    func_80037094(rdram, ctx);
        goto after_0;
    // 0x80036F90: nop

    after_0:
    // 0x80036F94: b           L_80037088
    // 0x80036F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80037088;
    // 0x80036F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036F9C:
    // 0x80036F9C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80036FA0: addiu       $v1, $v1, -0x4500
    ctx->r3 = ADD32(ctx->r3, -0X4500);
    // 0x80036FA4: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x80036FA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80036FAC: lw          $t7, 0x14($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14);
    // 0x80036FB0: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80036FB4: beq         $t7, $zero, L_80037014
    if (ctx->r15 == 0) {
        // 0x80036FB8: nop
    
            goto L_80037014;
    }
    // 0x80036FB8: nop

    // 0x80036FBC: jal         0x80035F70
    // 0x80036FC0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80035F70(rdram, ctx);
        goto after_1;
    // 0x80036FC0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80036FC4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80036FC8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80036FCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80036FD0: bne         $v0, $at, L_80037084
    if (ctx->r2 != ctx->r1) {
        // 0x80036FD4: addiu       $v1, $v1, -0x4500
        ctx->r3 = ADD32(ctx->r3, -0X4500);
            goto L_80037084;
    }
    // 0x80036FD4: addiu       $v1, $v1, -0x4500
    ctx->r3 = ADD32(ctx->r3, -0X4500);
    // 0x80036FD8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80036FDC: sh          $t8, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r24;
    // 0x80036FE0: sh          $zero, 0x2A($a2)
    MEM_H(0X2A, ctx->r6) = 0;
    // 0x80036FE4: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x80036FE8: lui         $t0, 0xFFFD
    ctx->r8 = S32(0XFFFD << 16);
    // 0x80036FEC: sw          $zero, 0x14($t9)
    MEM_W(0X14, ctx->r25) = 0;
    // 0x80036FF0: lw          $t1, 0x20($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X20);
    // 0x80036FF4: ori         $t0, $t0, 0x8000
    ctx->r8 = ctx->r8 | 0X8000;
    // 0x80036FF8: sw          $t0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r8;
    // 0x80036FFC: lw          $a1, 0x20($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X20);
    // 0x80037000: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80037004: jal         0x80047A20
    // 0x80037008: addiu       $a0, $a0, -0x6420
    ctx->r4 = ADD32(ctx->r4, -0X6420);
    func_80047A20(rdram, ctx);
        goto after_2;
    // 0x80037008: addiu       $a0, $a0, -0x6420
    ctx->r4 = ADD32(ctx->r4, -0X6420);
    after_2:
    // 0x8003700C: b           L_80037088
    // 0x80037010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80037088;
    // 0x80037010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80037014:
    // 0x80037014: lw          $t2, 0x20($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X20);
    // 0x80037018: lw          $t3, 0x618($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X618);
    // 0x8003701C: lui         $at, 0x30
    ctx->r1 = S32(0X30 << 16);
    // 0x80037020: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80037024: slt         $at, $t4, $at
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80037028: beq         $at, $zero, L_80037088
    if (ctx->r1 == 0) {
        // 0x8003702C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80037088;
    }
    // 0x8003702C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037030: lhu         $t5, 0x7C($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X7C);
    // 0x80037034: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80037038: andi        $t6, $t5, 0x80
    ctx->r14 = ctx->r13 & 0X80;
    // 0x8003703C: bne         $t6, $zero, L_80037054
    if (ctx->r14 != 0) {
        // 0x80037040: nop
    
            goto L_80037054;
    }
    // 0x80037040: nop

    // 0x80037044: lhu         $t7, -0x7A2($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X7A2);
    // 0x80037048: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8003704C: beq         $t7, $zero, L_80037064
    if (ctx->r15 == 0) {
        // 0x80037050: nop
    
            goto L_80037064;
    }
    // 0x80037050: nop

L_80037054:
    // 0x80037054: jal         0x80037094
    // 0x80037058: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80037094(rdram, ctx);
        goto after_3;
    // 0x80037058: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x8003705C: b           L_80037088
    // 0x80037060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80037088;
    // 0x80037060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80037064:
    // 0x80037064: sh          $zero, 0x1C($a2)
    MEM_H(0X1C, ctx->r6) = 0;
    // 0x80037068: sh          $zero, 0x22($a2)
    MEM_H(0X22, ctx->r6) = 0;
    // 0x8003706C: sh          $zero, 0x2A($a2)
    MEM_H(0X2A, ctx->r6) = 0;
    // 0x80037070: jal         0x8000D624
    // 0x80037074: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8000D624(rdram, ctx);
        goto after_4;
    // 0x80037074: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_4:
    // 0x80037078: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8003707C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80037080: sh          $t8, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r24;
L_80037084:
    // 0x80037084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80037088:
    // 0x80037088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003708C: jr          $ra
    // 0x80037090: nop

    return;
    // 0x80037090: nop

;}
RECOMP_FUNC void func_80037094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80037094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037098: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8003709C: lw          $t6, -0x44E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44E0);
    // 0x800370A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800370A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800370A8: lhu         $t7, 0x7C($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X7C);
    // 0x800370AC: nop

    // 0x800370B0: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x800370B4: beq         $t8, $zero, L_800370D4
    if (ctx->r24 == 0) {
        // 0x800370B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800370D4;
    }
    // 0x800370B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800370BC: jal         0x80037294
    // 0x800370C0: nop

    func_80037294(rdram, ctx);
        goto after_0;
    // 0x800370C0: nop

    after_0:
    // 0x800370C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800370C8: jal         0x80035ED8
    // 0x800370CC: nop

    func_80035ED8(rdram, ctx);
        goto after_1;
    // 0x800370CC: nop

    after_1:
    // 0x800370D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800370D4:
    // 0x800370D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800370D8: jr          $ra
    // 0x800370DC: nop

    return;
    // 0x800370DC: nop

;}
RECOMP_FUNC void func_800370E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800370E0: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x800370E4: lhu         $t6, -0x7A2($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X7A2);
    ctx->hi = hi; ctx->lo = lo;
    func_800370E8(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_800370E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800370E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800370EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800370F0: bne         $t6, $zero, L_800371E8
    if (ctx->r14 != 0) {
        // 0x800370F4: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_800371E8;
    }
    // 0x800370F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800370F8: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x800370FC: lhu         $a2, -0x200($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X200);
    // 0x80037100: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80037104: andi        $t7, $a2, 0x7
    ctx->r15 = ctx->r6 & 0X7;
    // 0x80037108: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8003710C: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80037110: bne         $a2, $at, L_8003711C
    if (ctx->r6 != ctx->r1) {
        // 0x80037114: addiu       $a0, $zero, 0x1F
        ctx->r4 = ADD32(0, 0X1F);
            goto L_8003711C;
    }
    // 0x80037114: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80037118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8003711C:
    // 0x8003711C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80037120: jal         0x80000688
    // 0x80037124: sh          $a2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r6;
    func_80000688(rdram, ctx);
        goto after_0;
    // 0x80037124: sh          $a2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r6;
    after_0:
    // 0x80037128: andi        $a0, $v0, 0x3
    ctx->r4 = ctx->r2 & 0X3;
    // 0x8003712C: sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4 << 16);
    // 0x80037130: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x80037134: sra         $t0, $v1, 16
    ctx->r8 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80037138: lh          $a2, 0x26($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X26);
    // 0x8003713C: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80037140: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80037144: bne         $t2, $at, L_80037150
    if (ctx->r10 != ctx->r1) {
        // 0x80037148: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_80037150;
    }
    // 0x80037148: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8003714C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80037150:
    // 0x80037150: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80037154: addiu       $v0, $v0, -0x3FF0
    ctx->r2 = ADD32(ctx->r2, -0X3FF0);
L_80037158:
    // 0x80037158: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
L_8003715C:
    // 0x8003715C: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80037160: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80037164: nop

    // 0x80037168: and         $t6, $t5, $a2
    ctx->r14 = ctx->r13 & ctx->r6;
    // 0x8003716C: beq         $t6, $zero, L_80037198
    if (ctx->r14 == 0) {
        // 0x80037170: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_80037198;
    }
    // 0x80037170: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80037174: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80037178: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8003717C: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80037180: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80037184: bne         $at, $zero, L_8003715C
    if (ctx->r1 != 0) {
        // 0x80037188: sll         $t3, $v1, 1
        ctx->r11 = S32(ctx->r3 << 1);
            goto L_8003715C;
    }
    // 0x80037188: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x8003718C: b           L_80037158
    // 0x80037190: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80037158;
    // 0x80037190: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80037194: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
L_80037198:
    // 0x80037198: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8003719C: bne         $v1, $zero, L_800371AC
    if (ctx->r3 != 0) {
        // 0x800371A0: sh          $v1, 0x24($t9)
        MEM_H(0X24, ctx->r25) = ctx->r3;
            goto L_800371AC;
    }
    // 0x800371A0: sh          $v1, 0x24($t9)
    MEM_H(0X24, ctx->r25) = ctx->r3;
    // 0x800371A4: b           L_800371C0
    // 0x800371A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800371C0;
    // 0x800371A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800371AC:
    // 0x800371AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800371B0: bne         $v1, $at, L_800371C0
    if (ctx->r3 != ctx->r1) {
        // 0x800371B4: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800371C0;
    }
    // 0x800371B4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800371B8: b           L_800371C0
    // 0x800371BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800371C0;
    // 0x800371BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800371C0:
    // 0x800371C0: or          $t1, $a2, $v0
    ctx->r9 = ctx->r6 | ctx->r2;
    // 0x800371C4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800371C8: sh          $t1, -0x200($at)
    MEM_H(-0X200, ctx->r1) = ctx->r9;
    // 0x800371CC: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    // 0x800371D0: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x800371D4: jal         0x8005D3B8
    // 0x800371D8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_8005D3B8(rdram, ctx);
        goto after_1;
    // 0x800371D8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x800371DC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800371E0: b           L_80037204
    // 0x800371E4: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
        goto L_80037204;
    // 0x800371E4: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
L_800371E8:
    // 0x800371E8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800371EC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800371F0: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    // 0x800371F4: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    // 0x800371F8: jal         0x8005D3B8
    // 0x800371FC: sh          $t2, 0x24($t3)
    MEM_H(0X24, ctx->r11) = ctx->r10;
    func_8005D3B8(rdram, ctx);
        goto after_2;
    // 0x800371FC: sh          $t2, 0x24($t3)
    MEM_H(0X24, ctx->r11) = ctx->r10;
    after_2:
    // 0x80037200: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80037204:
    // 0x80037204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037208: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003720C: jr          $ra
    // 0x80037210: nop

    return;
    // 0x80037210: nop

;}
RECOMP_FUNC void func_80037214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80037214: lh          $v0, 0x24($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X24);
    // 0x80037218: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003721C: beq         $v0, $at, L_8003725C
    if (ctx->r2 == ctx->r1) {
        // 0x80037220: lui         $v1, 0x800C
        ctx->r3 = S32(0X800C << 16);
            goto L_8003725C;
    }
    // 0x80037220: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80037224: bne         $v0, $zero, L_80037234
    if (ctx->r2 != 0) {
        // 0x80037228: addiu       $v1, $v1, -0x200
        ctx->r3 = ADD32(ctx->r3, -0X200);
            goto L_80037234;
    }
    // 0x80037228: addiu       $v1, $v1, -0x200
    ctx->r3 = ADD32(ctx->r3, -0X200);
    // 0x8003722C: b           L_8003724C
    // 0x80037230: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003724C;
    // 0x80037230: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037234:
    // 0x80037234: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80037238: bne         $v0, $at, L_8003724C
    if (ctx->r2 != ctx->r1) {
        // 0x8003723C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8003724C;
    }
    // 0x8003723C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80037240: b           L_8003724C
    // 0x80037244: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8003724C;
    // 0x80037244: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80037248: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8003724C:
    // 0x8003724C: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x80037250: nop

    // 0x80037254: or          $t7, $t6, $v0
    ctx->r15 = ctx->r14 | ctx->r2;
    // 0x80037258: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
L_8003725C:
    // 0x8003725C: jr          $ra
    // 0x80037260: nop

    return;
    // 0x80037260: nop

;}
RECOMP_FUNC void func_80037264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80037264: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80037268: lhu         $t6, -0x48A0($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X48A0);
    ctx->hi = hi; ctx->lo = lo;
    func_8003726C(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_8003726C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8003726C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037270: slti        $at, $t6, 0x259
    ctx->r1 = SIGNED(ctx->r14) < 0X259 ? 1 : 0;
    // 0x80037274: bne         $at, $zero, L_80037284
    if (ctx->r1 != 0) {
        // 0x80037278: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80037284;
    }
    // 0x80037278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003727C: jal         0x80043C14
    // 0x80037280: nop

    func_80043C14(rdram, ctx);
        goto after_0;
    // 0x80037280: nop

    after_0:
L_80037284:
    // 0x80037284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003728C: jr          $ra
    // 0x80037290: nop

    return;
    // 0x80037290: nop

;}
RECOMP_FUNC void func_80037294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80037294: jr          $ra
    // 0x80037298: nop

    return;
    // 0x80037298: nop

;}
RECOMP_FUNC void func_8003729C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8003729C: jr          $ra
    // 0x800372A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800372A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800372A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800372A4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800372A8: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x800372AC: lw          $t6, 0x614($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X614);
    // 0x800372B0: addiu       $v0, $v0, -0x4500
    ctx->r2 = ADD32(ctx->r2, -0X4500);
    // 0x800372B4: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x800372B8: lui         $at, 0xFE44
    ctx->r1 = S32(0XFE44 << 16);
    // 0x800372BC: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800372C0: sw          $t7, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r15;
    // 0x800372C4: lw          $t0, 0x20($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X20);
    // 0x800372C8: lui         $t9, 0x200
    ctx->r25 = S32(0X200 << 16);
    // 0x800372CC: jr          $ra
    // 0x800372D0: sw          $t9, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r25;
    return;
    // 0x800372D0: sw          $t9, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r25;
;}
RECOMP_FUNC void func_800372D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800372D4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800372D8: lw          $a1, -0x44E0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X44E0);
    ctx->hi = hi; ctx->lo = lo;
    func_800372DC(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_800372DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800372DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800372E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800372E4: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x800372E8: lh          $t7, 0x614($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X614);
    // 0x800372EC: lh          $a2, 0x1C($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X1C);
    // 0x800372F0: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x800372F4: subu        $v0, $a2, $t7
    ctx->r2 = SUB32(ctx->r6, ctx->r15);
    // 0x800372F8: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x800372FC: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80037300: bgez        $t9, L_80037310
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80037304: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80037310;
    }
    // 0x80037304: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80037308: b           L_80037314
    // 0x8003730C: negu        $v1, $t9
    ctx->r3 = SUB32(0, ctx->r25);
        goto L_80037314;
    // 0x8003730C: negu        $v1, $t9
    ctx->r3 = SUB32(0, ctx->r25);
L_80037310:
    // 0x80037310: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80037314:
    // 0x80037314: slti        $at, $v1, 0x2BC
    ctx->r1 = SIGNED(ctx->r3) < 0X2BC ? 1 : 0;
    // 0x80037318: bne         $at, $zero, L_80037334
    if (ctx->r1 != 0) {
        // 0x8003731C: lui         $v1, 0x800C
        ctx->r3 = S32(0X800C << 16);
            goto L_80037334;
    }
    // 0x8003731C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80037320: lh          $t0, -0x878($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X878);
    // 0x80037324: nop

    // 0x80037328: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8003732C: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x80037330: sra         $v0, $t1, 16
    ctx->r2 = S32(SIGNED(ctx->r9) >> 16);
L_80037334:
    // 0x80037334: lhu         $t3, 0x32($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X32);
    // 0x80037338: slti        $at, $v0, -0x96
    ctx->r1 = SIGNED(ctx->r2) < -0X96 ? 1 : 0;
    // 0x8003733C: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x80037340: beq         $t4, $zero, L_80037370
    if (ctx->r12 == 0) {
        // 0x80037344: nop
    
            goto L_80037370;
    }
    // 0x80037344: nop

    // 0x80037348: lh          $v1, -0x878($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X878);
    // 0x8003734C: slti        $at, $v0, 0x259
    ctx->r1 = SIGNED(ctx->r2) < 0X259 ? 1 : 0;
    // 0x80037350: bne         $at, $zero, L_80037368
    if (ctx->r1 != 0) {
        // 0x80037354: addu        $t7, $v0, $v1
        ctx->r15 = ADD32(ctx->r2, ctx->r3);
            goto L_80037368;
    }
    // 0x80037354: addu        $t7, $v0, $v1
    ctx->r15 = ADD32(ctx->r2, ctx->r3);
    // 0x80037358: addiu       $v0, $v0, -0x258
    ctx->r2 = ADD32(ctx->r2, -0X258);
    // 0x8003735C: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x80037360: sra         $v0, $t5, 16
    ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80037364: addu        $t7, $v0, $v1
    ctx->r15 = ADD32(ctx->r2, ctx->r3);
L_80037368:
    // 0x80037368: b           L_8003737C
    // 0x8003736C: sh          $t7, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r15;
        goto L_8003737C;
    // 0x8003736C: sh          $t7, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r15;
L_80037370:
    // 0x80037370: beq         $at, $zero, L_8003737C
    if (ctx->r1 == 0) {
        // 0x80037374: addiu       $t8, $a2, 0x96
        ctx->r24 = ADD32(ctx->r6, 0X96);
            goto L_8003737C;
    }
    // 0x80037374: addiu       $t8, $a2, 0x96
    ctx->r24 = ADD32(ctx->r6, 0X96);
    // 0x80037378: sh          $t8, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r24;
L_8003737C:
    // 0x8003737C: jal         0x80037574
    // 0x80037380: nop

    func_80037574(rdram, ctx);
        goto after_0;
    // 0x80037380: nop

    after_0:
    // 0x80037384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003738C: jr          $ra
    // 0x80037390: nop

    return;
    // 0x80037390: nop

;}
RECOMP_FUNC void func_80037394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80037394: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80037398: lh          $v0, 0x26($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X26);
    // 0x8003739C: lh          $v1, 0x614($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X614);
    // 0x800373A0: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x800373A4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800373A8: beq         $at, $zero, L_800373C4
    if (ctx->r1 == 0) {
        // 0x800373AC: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800373C4;
    }
    // 0x800373AC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800373B0: lh          $t6, -0x878($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X878);
    // 0x800373B4: nop

    // 0x800373B8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800373BC: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x800373C0: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
L_800373C4:
    // 0x800373C4: lw          $t9, -0x44E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X44E0);
    // 0x800373C8: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x800373CC: lh          $a0, 0x1C($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X1C);
    // 0x800373D0: nop

    // 0x800373D4: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800373D8: beq         $at, $zero, L_800373F4
    if (ctx->r1 == 0) {
        // 0x800373DC: nop
    
            goto L_800373F4;
    }
    // 0x800373DC: nop

    // 0x800373E0: lh          $t0, -0x878($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X878);
    // 0x800373E4: nop

    // 0x800373E8: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x800373EC: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x800373F0: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
L_800373F4:
    // 0x800373F4: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800373F8: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x800373FC: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80037400: bgez        $t4, L_80037410
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80037404: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_80037410;
    }
    // 0x80037404: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80037408: b           L_80037414
    // 0x8003740C: negu        $v0, $t4
    ctx->r2 = SUB32(0, ctx->r12);
        goto L_80037414;
    // 0x8003740C: negu        $v0, $t4
    ctx->r2 = SUB32(0, ctx->r12);
L_80037410:
    // 0x80037410: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80037414:
    // 0x80037414: slti        $at, $v0, 0x60
    ctx->r1 = SIGNED(ctx->r2) < 0X60 ? 1 : 0;
    // 0x80037418: beq         $at, $zero, L_80037428
    if (ctx->r1 == 0) {
            // 0x8003741C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    func_80037428(rdram, ctx);
    return;
    }
    // 0x8003741C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80037420: jr          $ra
    // 0x80037424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80037424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80037428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80037428: jr          $ra
    // 0x8003742C: nop

    return;
    // 0x8003742C: nop

;}
RECOMP_FUNC void func_80037430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80037430: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80037434: lw          $t8, -0x44E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X44E0);
    // 0x80037438: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003743C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80037440: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80037444: lh          $v1, -0x878($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X878);
    // 0x80037448: lh          $a3, 0x26($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X26);
    // 0x8003744C: lh          $t0, 0x1C($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X1C);
    // 0x80037450: sra         $v0, $v1, 1
    ctx->r2 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80037454: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x80037458: subu        $t1, $a3, $t0
    ctx->r9 = SUB32(ctx->r7, ctx->r8);
    // 0x8003745C: bgez        $t1, L_80037474
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80037460: sra         $v0, $t6, 16
        ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
            goto L_80037474;
    }
    // 0x80037460: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80037464: negu        $a0, $t1
    ctx->r4 = SUB32(0, ctx->r9);
    // 0x80037468: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8003746C: b           L_80037480
    // 0x80037470: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
        goto L_80037480;
    // 0x80037470: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
L_80037474:
    // 0x80037474: sll         $a0, $t1, 16
    ctx->r4 = S32(ctx->r9 << 16);
    // 0x80037478: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003747C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_80037480:
    // 0x80037480: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80037484: bne         $at, $zero, L_800374E0
    if (ctx->r1 != 0) {
        // 0x80037488: lui         $t4, 0x800C
        ctx->r12 = S32(0X800C << 16);
            goto L_800374E0;
    }
    // 0x80037488: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8003748C: lh          $t4, 0x614($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X614);
    // 0x80037490: nop

    // 0x80037494: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x80037498: bgez        $a1, L_800374B0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8003749C: sll         $a0, $a1, 16
        ctx->r4 = S32(ctx->r5 << 16);
            goto L_800374B0;
    }
    // 0x8003749C: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x800374A0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    // 0x800374A4: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800374A8: b           L_800374B8
    // 0x800374AC: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
        goto L_800374B8;
    // 0x800374AC: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
L_800374B0:
    // 0x800374B0: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800374B4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_800374B8:
    // 0x800374B8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800374BC: bne         $at, $zero, L_800374D4
    if (ctx->r1 != 0) {
        // 0x800374C0: nop
    
            goto L_800374D4;
    }
    // 0x800374C0: nop

    // 0x800374C4: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x800374C8: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x800374CC: b           L_800374E0
    // 0x800374D0: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
        goto L_800374E0;
    // 0x800374D0: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
L_800374D4:
    // 0x800374D4: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x800374D8: sll         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8 << 16);
    // 0x800374DC: sra         $t0, $t2, 16
    ctx->r8 = S32(SIGNED(ctx->r10) >> 16);
L_800374E0:
    // 0x800374E0: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x800374E4: nop

    // 0x800374E8: sh          $a3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r7;
    // 0x800374EC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800374F0: jr          $ra
    // 0x800374F4: sh          $t0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r8;
    return;
    // 0x800374F4: sh          $t0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r8;
;}
RECOMP_FUNC void func_800374F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800374F8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800374FC: addiu       $t0, $t0, -0x4500
    ctx->r8 = ADD32(ctx->r8, -0X4500);
    // 0x80037500: lw          $v0, 0x20($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X20);
    ctx->hi = hi; ctx->lo = lo;
    func_80037504(rdram, ctx); // fall-through
;}
RECOMP_FUNC void func_80037504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80037504: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80037508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003750C: lw          $v1, 0x98($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X98);
    // 0x80037510: lw          $t2, 0x6C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X6C);
    // 0x80037514: lw          $a3, 0x50($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X50);
    // 0x80037518: ori         $a1, $zero, 0x8002
    ctx->r5 = 0 | 0X8002;
    // 0x8003751C: beq         $a3, $zero, L_80037544
    if (ctx->r7 == 0) {
        // 0x80037520: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_80037544;
    }
    // 0x80037520: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80037524: sw          $a3, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r7;
    // 0x80037528: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8003752C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80037530: jal         0x80022F38
    // 0x80037534: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_80022F38(rdram, ctx);
        goto after_0;
    // 0x80037534: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x80037538: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003753C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80037540: addiu       $t0, $t0, -0x4500
    ctx->r8 = ADD32(ctx->r8, -0X4500);
L_80037544:
    // 0x80037544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037548: sw          $t1, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r9;
    // 0x8003754C: jr          $ra
    // 0x80037550: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80037550: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80037554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80037554: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003755C: jal         0x8003759C
    // 0x80037560: nop

    func_8003759C(rdram, ctx);
        goto after_0;
    // 0x80037560: nop

    after_0:
    // 0x80037564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037568: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003756C: jr          $ra
    // 0x80037570: nop

    return;
    // 0x80037570: nop

;}
RECOMP_FUNC void func_80037574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80037574: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003757C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80037580: lw          $a0, 0x50($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X50);
    // 0x80037584: jal         0x8003759C
    // 0x80037588: nop

    func_8003759C(rdram, ctx);
        goto after_0;
    // 0x80037588: nop

    after_0:
    // 0x8003758C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037590: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80037594: jr          $ra
    // 0x80037598: nop

    return;
    // 0x80037598: nop

;}
RECOMP_FUNC void func_8003759C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x8003759C: beq         $a0, $zero, L_80037660
    if (ctx->r4 == 0) {
        // 0x800375A0: sw          $a1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r5;
            goto L_80037660;
    }
    // 0x800375A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800375A4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800375A8: addiu       $t0, $t0, -0x4500
    ctx->r8 = ADD32(ctx->r8, -0X4500);
    // 0x800375AC: lw          $v1, 0x20($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X20);
    // 0x800375B0: nop

    // 0x800375B4: lw          $v0, 0x48($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X48);
    // 0x800375B8: nop

    // 0x800375BC: beq         $v0, $zero, L_80037660
    if (ctx->r2 == 0) {
        // 0x800375C0: nop
    
            goto L_80037660;
    }
    // 0x800375C0: nop

    // 0x800375C4: lhu         $t1, 0x32($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X32);
    // 0x800375C8: lh          $t6, 0x26($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X26);
    // 0x800375CC: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x800375D0: lh          $t8, 0x24($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X24);
    // 0x800375D4: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
    // 0x800375D8: lh          $a3, 0x1C($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X1C);
    // 0x800375DC: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x800375E0: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    // 0x800375E4: beq         $t2, $zero, L_80037600
    if (ctx->r10 == 0) {
        // 0x800375E8: subu        $a2, $t8, $t9
        ctx->r6 = SUB32(ctx->r24, ctx->r25);
            goto L_80037600;
    }
    // 0x800375E8: subu        $a2, $t8, $t9
    ctx->r6 = SUB32(ctx->r24, ctx->r25);
    // 0x800375EC: lhu         $t3, 0x32($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X32);
    // 0x800375F0: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x800375F4: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x800375F8: b           L_80037610
    // 0x800375FC: sh          $t4, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r12;
        goto L_80037610;
    // 0x800375FC: sh          $t4, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r12;
L_80037600:
    // 0x80037600: lhu         $t5, 0x32($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X32);
    // 0x80037604: nop

    // 0x80037608: andi        $t6, $t5, 0xFFEF
    ctx->r14 = ctx->r13 & 0XFFEF;
    // 0x8003760C: sh          $t6, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r14;
L_80037610:
    // 0x80037610: lw          $t8, 0x20($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X20);
    // 0x80037614: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x80037618: lhu         $t9, 0x7C($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X7C);
    // 0x8003761C: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80037620: andi        $t1, $t9, 0x80
    ctx->r9 = ctx->r25 & 0X80;
    // 0x80037624: beq         $t1, $zero, L_80037634
    if (ctx->r9 == 0) {
        // 0x80037628: or          $a3, $t7, $zero
        ctx->r7 = ctx->r15 | 0;
            goto L_80037634;
    }
    // 0x80037628: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8003762C: b           L_80037648
    // 0x80037630: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
        goto L_80037648;
    // 0x80037630: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
L_80037634:
    // 0x80037634: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80037638: lw          $t2, -0x878($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X878);
    // 0x8003763C: nop

    // 0x80037640: and         $t3, $a3, $t2
    ctx->r11 = ctx->r7 & ctx->r10;
    // 0x80037644: sw          $t3, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r11;
L_80037648:
    // 0x80037648: lw          $t4, 0x20($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X20);
    // 0x8003764C: nop

    // 0x80037650: lh          $t5, 0x20($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X20);
    // 0x80037654: nop

    // 0x80037658: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x8003765C: sh          $t6, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r14;
L_80037660:
    // 0x80037660: jr          $ra
    // 0x80037664: nop

    return;
    // 0x80037664: nop

    // 0x80037668: nop

    // 0x8003766C: nop

;}
RECOMP_FUNC void func_80037670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80037670: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80037674: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80037678: addiu       $a1, $a1, -0x153E
    ctx->r5 = ADD32(ctx->r5, -0X153E);
    // 0x8003767C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80037680: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_80037684:
    // 0x80037684: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80037688: nop

    // 0x8003768C: bne         $a0, $t6, L_80037698
    if (ctx->r4 != ctx->r14) {
        // 0x80037690: nop
    
            goto L_80037698;
    }
    // 0x80037690: nop

    // 0x80037694: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80037698:
    // 0x80037698: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003769C: bne         $v0, $a2, L_80037684
    if (ctx->r2 != ctx->r6) {
        // 0x800376A0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80037684;
    }
    // 0x800376A0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800376A4: jr          $ra
    // 0x800376A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800376A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800376AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    static int world_call = 0;
    static uint16_t prev_game_state = 0;
    world_call++;
    // 0x800376AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800376B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800376B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800376B8: jal         0x8002BAE8
    // 0x800376BC: sh          $zero, 0x662C($at)
    MEM_H(0X662C, ctx->r1) = 0;
    func_8002BAE8(rdram, ctx);
        goto after_0;
    // 0x800376BC: sh          $zero, 0x662C($at)
    MEM_H(0X662C, ctx->r1) = 0;
    after_0:
    // 0x800376C0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800376C4: lhu         $v0, -0x87A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X87A);
    // PATCH: Reset rendering state on state change so each screen starts fresh.
    // Without SN64 audio callbacks, screen transitions don't properly clear content.
    {
        uint16_t cur_state = (uint16_t)ctx->r2;
        if (cur_state != prev_game_state && prev_game_state != 0) {
            fprintf(stderr, "[STATE-CHANGE] 0x%04X -> 0x%04X: clearing framebuffers + render flags\n",
                    prev_game_state, cur_state);
            fflush(stderr);
            // Clear the "initialized" flag at 0x800CBE96 so func_80037C48 reloads texture tables
            MEM_H(ADD32(S32(0X800C << 16), -0X16A), 0X0) = 0;
            // Clear the countdown counter at 0x800CBE8E
            MEM_H(ADD32(S32(0X800C << 16), -0X172), 0X0) = 0;
            // Clear the secondary init flag at 0x800BED98
            MEM_H(ADD32(S32(0X800C << 16), -0X1268), 0X0) = 0;
            // Clear BOTH framebuffers in RDRAM to black (16-bit 5551 format, 0=black)
            // FB_A at physical 0x001A5EC0, FB_B at physical 0x001770C0
            // Each is 400*240*2 = 192000 bytes = 0x2EE00
            memset(rdram + 0x001A5EC0, 0, 0x2EE00);
            memset(rdram + 0x001770C0, 0, 0x2EE00);
        }
        prev_game_state = cur_state;
    }
    if (world_call <= 20 || (world_call % 60 == 0)) {
        fprintf(stderr, "[WORLD] #%d: game_state=0x%04X\n", world_call, (unsigned)ctx->r2);
        fflush(stderr);
    }
    // 0x800376C8: nop

    // 0x800376CC: slti        $at, $v0, 0x271
    ctx->r1 = SIGNED(ctx->r2) < 0X271 ? 1 : 0;
    // 0x800376D0: bne         $at, $zero, L_80037700
    if (ctx->r1 != 0) {
        // 0x800376D4: addiu       $at, $zero, 0x280
        ctx->r1 = ADD32(0, 0X280);
            goto L_80037700;
    }
    // 0x800376D4: addiu       $at, $zero, 0x280
    ctx->r1 = ADD32(0, 0X280);
    // 0x800376D8: beq         $v0, $at, L_80037814
    if (ctx->r2 == ctx->r1) {
        // 0x800376DC: addiu       $at, $zero, 0x290
        ctx->r1 = ADD32(0, 0X290);
            goto L_80037814;
    }
    // 0x800376DC: addiu       $at, $zero, 0x290
    ctx->r1 = ADD32(0, 0X290);
    // 0x800376E0: beq         $v0, $at, L_800378A0
    if (ctx->r2 == ctx->r1) {
        // 0x800376E4: addiu       $at, $zero, 0x300
        ctx->r1 = ADD32(0, 0X300);
            goto L_800378A0;
    }
    // 0x800376E4: addiu       $at, $zero, 0x300
    ctx->r1 = ADD32(0, 0X300);
    // 0x800376E8: beq         $v0, $at, L_80037844
    if (ctx->r2 == ctx->r1) {
        // 0x800376EC: addiu       $at, $zero, 0x310
        ctx->r1 = ADD32(0, 0X310);
            goto L_80037844;
    }
    // 0x800376EC: addiu       $at, $zero, 0x310
    ctx->r1 = ADD32(0, 0X310);
    // 0x800376F0: beq         $v0, $at, L_800378C0
    if (ctx->r2 == ctx->r1) {
        // 0x800376F4: nop
    
            goto L_800378C0;
    }
    // 0x800376F4: nop

    // 0x800376F8: b           L_800378E8
    // 0x800376FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x800376FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80037700:
    // 0x80037700: slti        $at, $v0, 0x241
    ctx->r1 = SIGNED(ctx->r2) < 0X241 ? 1 : 0;
    // 0x80037704: bne         $at, $zero, L_80037724
    if (ctx->r1 != 0) {
        // 0x80037708: addiu       $at, $zero, 0x260
        ctx->r1 = ADD32(0, 0X260);
            goto L_80037724;
    }
    // 0x80037708: addiu       $at, $zero, 0x260
    ctx->r1 = ADD32(0, 0X260);
    // 0x8003770C: beq         $v0, $at, L_800378D0
    if (ctx->r2 == ctx->r1) {
        // 0x80037710: addiu       $at, $zero, 0x270
        ctx->r1 = ADD32(0, 0X270);
            goto L_800378D0;
    }
    // 0x80037710: addiu       $at, $zero, 0x270
    ctx->r1 = ADD32(0, 0X270);
    // 0x80037714: beq         $v0, $at, L_8003777C
    if (ctx->r2 == ctx->r1) {
        // 0x80037718: nop
    
            goto L_8003777C;
    }
    // 0x80037718: nop

    // 0x8003771C: b           L_800378E8
    // 0x80037720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x80037720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80037724:
    // 0x80037724: slti        $at, $v0, 0x181
    ctx->r1 = SIGNED(ctx->r2) < 0X181 ? 1 : 0;
    // 0x80037728: bne         $at, $zero, L_80037758
    if (ctx->r1 != 0) {
        // 0x8003772C: addiu       $t7, $v0, -0x110
        ctx->r15 = ADD32(ctx->r2, -0X110);
            goto L_80037758;
    }
    // 0x8003772C: addiu       $t7, $v0, -0x110
    ctx->r15 = ADD32(ctx->r2, -0X110);
    // 0x80037730: addiu       $t6, $v0, -0x200
    ctx->r14 = ADD32(ctx->r2, -0X200);
    // 0x80037734: sltiu       $at, $t6, 0x41
    ctx->r1 = ctx->r14 < 0X41 ? 1 : 0;
    // 0x80037738: beq         $at, $zero, L_800378E4
    if (ctx->r1 == 0) {
        // 0x8003773C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800378E4;
    }
    // 0x8003773C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80037740: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80037744: addu        $at, $at, $t6
    gpr jr_addend_80037750 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80037748: lw          $t6, 0x79F0($at)
    ctx->r14 = ADD32(ctx->r1, 0X79F0);
    // 0x8003774C: nop

    // 0x80037750: jr          $t6
    // 0x80037754: nop

    switch (jr_addend_80037750 >> 2) {
        case 0: goto L_800377E8; break;
        case 1: goto L_800378E4; break;
        case 2: goto L_800378E4; break;
        case 3: goto L_800378E4; break;
        case 4: goto L_800378E4; break;
        case 5: goto L_800378E4; break;
        case 6: goto L_800378E4; break;
        case 7: goto L_800378E4; break;
        case 8: goto L_800378E4; break;
        case 9: goto L_800378E4; break;
        case 10: goto L_800378E4; break;
        case 11: goto L_800378E4; break;
        case 12: goto L_800378E4; break;
        case 13: goto L_800378E4; break;
        case 14: goto L_800378E4; break;
        case 15: goto L_800378E4; break;
        case 16: goto L_800377FC; break;
        case 17: goto L_800378E4; break;
        case 18: goto L_800378E4; break;
        case 19: goto L_800378E4; break;
        case 20: goto L_800378E4; break;
        case 21: goto L_800378E4; break;
        case 22: goto L_800378E4; break;
        case 23: goto L_800378E4; break;
        case 24: goto L_800378E4; break;
        case 25: goto L_800378E4; break;
        case 26: goto L_800378E4; break;
        case 27: goto L_800378E4; break;
        case 28: goto L_800378E4; break;
        case 29: goto L_800378E4; break;
        case 30: goto L_800378E4; break;
        case 31: goto L_800378E4; break;
        case 32: goto L_80037890; break;
        case 33: goto L_800378E4; break;
        case 34: goto L_800378E4; break;
        case 35: goto L_800378E4; break;
        case 36: goto L_800378E4; break;
        case 37: goto L_800378E4; break;
        case 38: goto L_800378E4; break;
        case 39: goto L_800378E4; break;
        case 40: goto L_800378E4; break;
        case 41: goto L_800378E4; break;
        case 42: goto L_800378E4; break;
        case 43: goto L_800378E4; break;
        case 44: goto L_800378E4; break;
        case 45: goto L_800378E4; break;
        case 46: goto L_800378E4; break;
        case 47: goto L_800378E4; break;
        case 48: goto L_8003782C; break;
        case 49: goto L_800378E4; break;
        case 50: goto L_800378E4; break;
        case 51: goto L_800378E4; break;
        case 52: goto L_800378E4; break;
        case 53: goto L_800378E4; break;
        case 54: goto L_800378E4; break;
        case 55: goto L_800378E4; break;
        case 56: goto L_800378E4; break;
        case 57: goto L_800378E4; break;
        case 58: goto L_800378E4; break;
        case 59: goto L_800378E4; break;
        case 60: goto L_800378E4; break;
        case 61: goto L_800378E4; break;
        case 62: goto L_800378E4; break;
        case 63: goto L_800378E4; break;
        case 64: goto L_800378B0; break;
        default: switch_error(__func__, 0x80037750, 0x800879F0);
    }
    // 0x80037754: nop

L_80037758:
    // 0x80037758: sltiu       $at, $t7, 0x71
    ctx->r1 = ctx->r15 < 0X71 ? 1 : 0;
    // 0x8003775C: beq         $at, $zero, L_800378E4
    if (ctx->r1 == 0) {
        // 0x80037760: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800378E4;
    }
    // 0x80037760: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80037764: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80037768: addu        $at, $at, $t7
    gpr jr_addend_80037774 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8003776C: lw          $t7, 0x7AF4($at)
    ctx->r15 = ADD32(ctx->r1, 0X7AF4);
    // 0x80037770: nop

    // 0x80037774: jr          $t7
    // 0x80037778: nop

    switch (jr_addend_80037774 >> 2) {
        case 0: goto L_80037794; break;
        case 1: goto L_800378E4; break;
        case 2: goto L_800378E4; break;
        case 3: goto L_800378E4; break;
        case 4: goto L_800378E4; break;
        case 5: goto L_800378E4; break;
        case 6: goto L_800378E4; break;
        case 7: goto L_800378E4; break;
        case 8: goto L_800378E4; break;
        case 9: goto L_800378E4; break;
        case 10: goto L_800378E4; break;
        case 11: goto L_800378E4; break;
        case 12: goto L_800378E4; break;
        case 13: goto L_800378E4; break;
        case 14: goto L_800378E4; break;
        case 15: goto L_800378E4; break;
        case 16: goto L_800377AC; break;
        case 17: goto L_800378E4; break;
        case 18: goto L_800378E4; break;
        case 19: goto L_800378E4; break;
        case 20: goto L_800378E4; break;
        case 21: goto L_800378E4; break;
        case 22: goto L_800378E4; break;
        case 23: goto L_800378E4; break;
        case 24: goto L_800378E4; break;
        case 25: goto L_800378E4; break;
        case 26: goto L_800378E4; break;
        case 27: goto L_800378E4; break;
        case 28: goto L_800378E4; break;
        case 29: goto L_800378E4; break;
        case 30: goto L_800378E4; break;
        case 31: goto L_800378E4; break;
        case 32: goto L_800377C0; break;
        case 33: goto L_800378E4; break;
        case 34: goto L_800378E4; break;
        case 35: goto L_800378E4; break;
        case 36: goto L_800378E4; break;
        case 37: goto L_800378E4; break;
        case 38: goto L_800378E4; break;
        case 39: goto L_800378E4; break;
        case 40: goto L_800378E4; break;
        case 41: goto L_800378E4; break;
        case 42: goto L_800378E4; break;
        case 43: goto L_800378E4; break;
        case 44: goto L_800378E4; break;
        case 45: goto L_800378E4; break;
        case 46: goto L_800378E4; break;
        case 47: goto L_800378E4; break;
        case 48: goto L_800377D4; break;
        case 49: goto L_800378E4; break;
        case 50: goto L_800378E4; break;
        case 51: goto L_800378E4; break;
        case 52: goto L_800378E4; break;
        case 53: goto L_800378E4; break;
        case 54: goto L_800378E4; break;
        case 55: goto L_800378E4; break;
        case 56: goto L_800378E4; break;
        case 57: goto L_800378E4; break;
        case 58: goto L_800378E4; break;
        case 59: goto L_800378E4; break;
        case 60: goto L_800378E4; break;
        case 61: goto L_800378E4; break;
        case 62: goto L_800378E4; break;
        case 63: goto L_800378E4; break;
        case 64: goto L_8003785C; break;
        case 65: goto L_800378E4; break;
        case 66: goto L_800378E4; break;
        case 67: goto L_800378E4; break;
        case 68: goto L_800378E4; break;
        case 69: goto L_800378E4; break;
        case 70: goto L_800378E4; break;
        case 71: goto L_800378E4; break;
        case 72: goto L_800378E4; break;
        case 73: goto L_800378E4; break;
        case 74: goto L_800378E4; break;
        case 75: goto L_800378E4; break;
        case 76: goto L_800378E4; break;
        case 77: goto L_800378E4; break;
        case 78: goto L_800378E4; break;
        case 79: goto L_800378E4; break;
        case 80: goto L_8003786C; break;
        case 81: goto L_800378E4; break;
        case 82: goto L_800378E4; break;
        case 83: goto L_800378E4; break;
        case 84: goto L_800378E4; break;
        case 85: goto L_800378E4; break;
        case 86: goto L_800378E4; break;
        case 87: goto L_800378E4; break;
        case 88: goto L_800378E4; break;
        case 89: goto L_800378E4; break;
        case 90: goto L_800378E4; break;
        case 91: goto L_800378E4; break;
        case 92: goto L_800378E4; break;
        case 93: goto L_800378E4; break;
        case 94: goto L_800378E4; break;
        case 95: goto L_800378E4; break;
        case 96: goto L_8003787C; break;
        case 97: goto L_800378E4; break;
        case 98: goto L_800378E4; break;
        case 99: goto L_800378E4; break;
        case 100: goto L_800378E4; break;
        case 101: goto L_800378E4; break;
        case 102: goto L_800378E4; break;
        case 103: goto L_800378E4; break;
        case 104: goto L_800378E4; break;
        case 105: goto L_800378E4; break;
        case 106: goto L_800378E4; break;
        case 107: goto L_800378E4; break;
        case 108: goto L_800378E4; break;
        case 109: goto L_800378E4; break;
        case 110: goto L_800378E4; break;
        case 111: goto L_800378E4; break;
        case 112: goto L_800378E4; break;
        default: switch_error(__func__, 0x80037774, 0x80087AF4);
    }
    // 0x80037778: nop

L_8003777C:
    // 0x8003777C: jal         0x8003A808
    // 0x80037780: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8003A808(rdram, ctx);
        goto after_1;
    // 0x80037780: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80037784: addiu       $t8, $zero, 0x110
    ctx->r24 = ADD32(0, 0X110);
    // 0x80037788: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003778C: b           L_800378E4
    // 0x80037790: sh          $t8, -0x87A($at)
    MEM_H(-0X87A, ctx->r1) = ctx->r24;
        goto L_800378E4;
    // 0x80037790: sh          $t8, -0x87A($at)
    MEM_H(-0X87A, ctx->r1) = ctx->r24;
L_80037794:
    if (world_call <= 15) {
        fprintf(stderr, "[WORLD] #%d: calling func_80067DE4(1)\n", world_call);
        fflush(stderr);
    }
    // 0x80037794: jal         0x80067DE4
    // 0x80037798: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80067DE4(rdram, ctx);
        goto after_2;
    // 0x80037798: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    if (world_call <= 15) {
        fprintf(stderr, "[WORLD] #%d: after func_80067DE4, calling func_80037C48\n", world_call);
        fflush(stderr);
    }
    // 0x8003779C: jal         0x80037C48
    // 0x800377A0: nop

    func_80037C48(rdram, ctx);
        goto after_3;
    // 0x800377A0: nop

    after_3:
    // 0x800377A4: b           L_800378E8
    // 0x800377A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x800377A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800377AC:
    // 0x800377AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800377B0: jal         0x80037E0C
    // 0x800377B4: sh          $zero, -0x486E($at)
    MEM_H(-0X486E, ctx->r1) = 0;
    func_80037E0C(rdram, ctx);
        goto after_4;
    // 0x800377B4: sh          $zero, -0x486E($at)
    MEM_H(-0X486E, ctx->r1) = 0;
    after_4:
    // 0x800377B8: b           L_800378E8
    // 0x800377BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x800377BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800377C0:
    // 0x800377C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800377C4: jal         0x80037F44
    // 0x800377C8: sh          $zero, -0x486E($at)
    MEM_H(-0X486E, ctx->r1) = 0;
    func_80037F44(rdram, ctx);
        goto after_5;
    // 0x800377C8: sh          $zero, -0x486E($at)
    MEM_H(-0X486E, ctx->r1) = 0;
    after_5:
    // 0x800377CC: b           L_800378E8
    // 0x800377D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x800377D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800377D4:
    // 0x800377D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800377D8: jal         0x800382B4
    // 0x800377DC: sh          $zero, -0x486E($at)
    MEM_H(-0X486E, ctx->r1) = 0;
    func_800382B4(rdram, ctx);
        goto after_6;
    // 0x800377DC: sh          $zero, -0x486E($at)
    MEM_H(-0X486E, ctx->r1) = 0;
    after_6:
    // 0x800377E0: b           L_800378E8
    // 0x800377E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x800377E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800377E8:
    // 0x800377E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800377EC: jal         0x80038384
    // 0x800377F0: sh          $zero, -0x486E($at)
    MEM_H(-0X486E, ctx->r1) = 0;
    func_80038384(rdram, ctx);
        goto after_7;
    // 0x800377F0: sh          $zero, -0x486E($at)
    MEM_H(-0X486E, ctx->r1) = 0;
    after_7:
    // 0x800377F4: b           L_800378E8
    // 0x800377F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x800377F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800377FC:
    // 0x800377FC: jal         0x80067DE4
    // 0x80037800: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067DE4(rdram, ctx);
        goto after_8;
    // 0x80037800: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x80037804: jal         0x80039064
    // 0x80037808: nop

    func_80039064(rdram, ctx);
        goto after_9;
    // 0x80037808: nop

    after_9:
    // 0x8003780C: b           L_800378E8
    // 0x80037810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x80037810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80037814:
    // 0x80037814: jal         0x80067DE4
    // 0x80037818: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067DE4(rdram, ctx);
        goto after_10;
    // 0x80037818: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8003781C: jal         0x80007448
    // 0x80037820: nop

    func_80007448(rdram, ctx);
        goto after_11;
    // 0x80037820: nop

    after_11:
    // 0x80037824: b           L_800378E8
    // 0x80037828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x80037828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003782C:
    // 0x8003782C: jal         0x80067DE4
    // 0x80037830: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067DE4(rdram, ctx);
        goto after_12;
    // 0x80037830: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x80037834: jal         0x8000569C
    // 0x80037838: nop

    func_8000569C(rdram, ctx);
        goto after_13;
    // 0x80037838: nop

    after_13:
    // 0x8003783C: b           L_800378E8
    // 0x80037840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x80037840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80037844:
    // 0x80037844: jal         0x80067DE4
    // 0x80037848: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067DE4(rdram, ctx);
        goto after_14;
    // 0x80037848: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x8003784C: jal         0x8000626C
    // 0x80037850: nop

    func_8000626C(rdram, ctx);
        goto after_15;
    // 0x80037850: nop

    after_15:
    // 0x80037854: b           L_800378E8
    // 0x80037858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x80037858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003785C:
    // 0x8003785C: jal         0x80039310
    // 0x80037860: nop

    func_80039310(rdram, ctx);
        goto after_16;
    // 0x80037860: nop

    after_16:
    // 0x80037864: b           L_800378E8
    // 0x80037868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x80037868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003786C:
    // 0x8003786C: jal         0x800398C0
    // 0x80037870: nop

    func_800398C0(rdram, ctx);
        goto after_17;
    // 0x80037870: nop

    after_17:
    // 0x80037874: b           L_800378E8
    // 0x80037878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x80037878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003787C:
    // 0x8003787C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80037880: jal         0x80039AAC
    // 0x80037884: sh          $zero, -0x486E($at)
    MEM_H(-0X486E, ctx->r1) = 0;
    func_80039AAC(rdram, ctx);
        goto after_18;
    // 0x80037884: sh          $zero, -0x486E($at)
    MEM_H(-0X486E, ctx->r1) = 0;
    after_18:
    // 0x80037888: b           L_800378E8
    // 0x8003788C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x8003788C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80037890:
    // 0x80037890: jal         0x800393A4
    // 0x80037894: nop

    func_800393A4(rdram, ctx);
        goto after_19;
    // 0x80037894: nop

    after_19:
    // 0x80037898: b           L_800378E8
    // 0x8003789C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x8003789C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800378A0:
    // 0x800378A0: jal         0x80007A60
    // 0x800378A4: nop

    func_80007A60(rdram, ctx);
        goto after_20;
    // 0x800378A4: nop

    after_20:
    // 0x800378A8: b           L_800378E8
    // 0x800378AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x800378AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800378B0:
    // 0x800378B0: jal         0x800058F0
    // 0x800378B4: nop

    func_800058F0(rdram, ctx);
        goto after_21;
    // 0x800378B4: nop

    after_21:
    // 0x800378B8: b           L_800378E8
    // 0x800378BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x800378BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800378C0:
    // 0x800378C0: jal         0x800064A4
    // 0x800378C4: nop

    func_800064A4(rdram, ctx);
        goto after_22;
    // 0x800378C4: nop

    after_22:
    // 0x800378C8: b           L_800378E8
    // 0x800378CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800378E8;
    // 0x800378CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800378D0:
    // 0x800378D0: jal         0x80067DE4
    // 0x800378D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80067DE4(rdram, ctx);
        goto after_23;
    // 0x800378D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_23:
    // 0x800378D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800378DC: jal         0x800030D0
    // 0x800378E0: sh          $zero, -0x486E($at)
    MEM_H(-0X486E, ctx->r1) = 0;
    func_800030D0(rdram, ctx);
        goto after_24;
    // 0x800378E0: sh          $zero, -0x486E($at)
    MEM_H(-0X486E, ctx->r1) = 0;
    after_24:
L_800378E4:
    // 0x800378E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800378E8:
    // 0x800378E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800378EC: jr          $ra
    // 0x800378F0: nop

    return;
    // 0x800378F0: nop

;}
RECOMP_FUNC void func_800378F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800378F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800378F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800378FC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80037900: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80037904: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80037908: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8003790C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80037910: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x80037914: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80037918: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8003791C: addiu       $s1, $s1, -0x798
    ctx->r17 = ADD32(ctx->r17, -0X798);
    // 0x80037920: addiu       $s2, $zero, 0x1CC
    ctx->r18 = ADD32(0, 0X1CC);
    // 0x80037924: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80037928: addiu       $s4, $zero, 0x37
    ctx->r20 = ADD32(0, 0X37);
    // 0x8003792C: addiu       $s5, $zero, 0x26
    ctx->r21 = ADD32(0, 0X26);
    // 0x80037930: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80037934:
    // 0x80037934: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037938: mflo        $t6
    ctx->r14 = lo;
    // 0x8003793C: addu        $v0, $s1, $t6
    ctx->r2 = ADD32(ctx->r17, ctx->r14);
    // 0x80037940: lhu         $t7, -0x19A($v0)
    ctx->r15 = MEM_HU(ctx->r2, -0X19A);
    // 0x80037944: addiu       $a0, $v0, -0x1CC
    ctx->r4 = ADD32(ctx->r2, -0X1CC);
    // 0x80037948: beq         $t7, $zero, L_80037960
    if (ctx->r15 == 0) {
        // 0x8003794C: nop
    
            goto L_80037960;
    }
    // 0x8003794C: nop

    // 0x80037950: jal         0x800379E4
    // 0x80037954: addiu       $a0, $v0, -0x1CC
    ctx->r4 = ADD32(ctx->r2, -0X1CC);
    func_800379E4(rdram, ctx);
        goto after_0;
    // 0x80037954: addiu       $a0, $v0, -0x1CC
    ctx->r4 = ADD32(ctx->r2, -0X1CC);
    after_0:
    // 0x80037958: b           L_800379B4
    // 0x8003795C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_800379B4;
    // 0x8003795C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80037960:
    // 0x80037960: lhu         $t8, 0x190($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X190);
    // 0x80037964: nop

    // 0x80037968: beq         $s3, $t8, L_800379B0
    if (ctx->r19 == ctx->r24) {
        // 0x8003796C: nop
    
            goto L_800379B0;
    }
    // 0x8003796C: nop

    // 0x80037970: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x80037974: nop

    // 0x80037978: beq         $t9, $zero, L_800379B0
    if (ctx->r25 == 0) {
        // 0x8003797C: nop
    
            goto L_800379B0;
    }
    // 0x8003797C: nop

    // 0x80037980: lhu         $v0, 0x46($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X46);
    // 0x80037984: nop

    // 0x80037988: beq         $s4, $v0, L_80037998
    if (ctx->r20 == ctx->r2) {
        // 0x8003798C: nop
    
            goto L_80037998;
    }
    // 0x8003798C: nop

    // 0x80037990: bne         $s5, $v0, L_800379B0
    if (ctx->r21 != ctx->r2) {
        // 0x80037994: nop
    
            goto L_800379B0;
    }
    // 0x80037994: nop

L_80037998:
    // 0x80037998: lw          $t0, 0x1A8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1A8);
    // 0x8003799C: nop

    // 0x800379A0: bne         $t0, $zero, L_800379B0
    if (ctx->r8 != 0) {
        // 0x800379A4: nop
    
            goto L_800379B0;
    }
    // 0x800379A4: nop

    // 0x800379A8: jal         0x80037B18
    // 0x800379AC: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    func_80037B18(rdram, ctx);
        goto after_1;
    // 0x800379AC: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    after_1:
L_800379B0:
    // 0x800379B0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_800379B4:
    // 0x800379B4: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x800379B8: bgtz        $v1, L_80037934
    if (SIGNED(ctx->r3) > 0) {
        // 0x800379BC: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_80037934;
    }
    // 0x800379BC: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800379C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800379C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800379C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800379CC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800379D0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800379D4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800379D8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800379DC: jr          $ra
    // 0x800379E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800379E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800379E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x800379E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800379E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800379EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800379F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800379F4: lw          $a0, 0x64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64);
    // 0x800379F8: jal         0x80037AF8
    // 0x800379FC: nop

    func_80037AF8(rdram, ctx);
        goto after_0;
    // 0x800379FC: nop

    after_0:
    // 0x80037A00: lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X5C);
    // 0x80037A04: jal         0x80037AF8
    // 0x80037A08: nop

    func_80037AF8(rdram, ctx);
        goto after_1;
    // 0x80037A08: nop

    after_1:
    // 0x80037A0C: lw          $a0, 0x60($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X60);
    // 0x80037A10: jal         0x80037AF8
    // 0x80037A14: nop

    func_80037AF8(rdram, ctx);
        goto after_2;
    // 0x80037A14: nop

    after_2:
    // 0x80037A18: lw          $a0, 0x104($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X104);
    // 0x80037A1C: jal         0x80037AF8
    // 0x80037A20: nop

    func_80037AF8(rdram, ctx);
        goto after_3;
    // 0x80037A20: nop

    after_3:
    // 0x80037A24: lw          $a0, 0x108($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X108);
    // 0x80037A28: jal         0x80037AF8
    // 0x80037A2C: nop

    func_80037AF8(rdram, ctx);
        goto after_4;
    // 0x80037A2C: nop

    after_4:
    // 0x80037A30: lw          $a0, 0x10C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10C);
    // 0x80037A34: jal         0x80037AF8
    // 0x80037A38: nop

    func_80037AF8(rdram, ctx);
        goto after_5;
    // 0x80037A38: nop

    after_5:
    // 0x80037A3C: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    // 0x80037A40: jal         0x80037AF8
    // 0x80037A44: nop

    func_80037AF8(rdram, ctx);
        goto after_6;
    // 0x80037A44: nop

    after_6:
    // 0x80037A48: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80037A4C: jal         0x80037AF8
    // 0x80037A50: nop

    func_80037AF8(rdram, ctx);
        goto after_7;
    // 0x80037A50: nop

    after_7:
    // 0x80037A54: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x80037A58: jal         0x80037AF8
    // 0x80037A5C: nop

    func_80037AF8(rdram, ctx);
        goto after_8;
    // 0x80037A5C: nop

    after_8:
    // 0x80037A60: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x80037A64: jal         0x80037AF8
    // 0x80037A68: nop

    func_80037AF8(rdram, ctx);
        goto after_9;
    // 0x80037A68: nop

    after_9:
    // 0x80037A6C: lw          $a0, 0x78($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X78);
    // 0x80037A70: jal         0x80037AF8
    // 0x80037A74: nop

    func_80037AF8(rdram, ctx);
        goto after_10;
    // 0x80037A74: nop

    after_10:
    // 0x80037A78: lw          $a0, 0x7C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7C);
    // 0x80037A7C: jal         0x80037AF8
    // 0x80037A80: nop

    func_80037AF8(rdram, ctx);
        goto after_11;
    // 0x80037A80: nop

    after_11:
    // 0x80037A84: lw          $a0, 0x1A8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1A8);
    // 0x80037A88: nop

    // 0x80037A8C: beq         $a0, $zero, L_80037AA4
    if (ctx->r4 == 0) {
        // 0x80037A90: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80037AA4;
    }
    // 0x80037A90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80037A94: jal         0x8002F750
    // 0x80037A98: nop

    func_8002F750(rdram, ctx);
        goto after_12;
    // 0x80037A98: nop

    after_12:
    // 0x80037A9C: sw          $zero, 0x1A8($s0)
    MEM_W(0X1A8, ctx->r16) = 0;
    // 0x80037AA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80037AA4:
    // 0x80037AA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80037AA8: jr          $ra
    // 0x80037AAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80037AAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80037AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80037AB0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80037AB4: lw          $t7, -0x44E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X44E0);
    // 0x80037AB8: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x80037ABC: jr          $ra
    // 0x80037AC0: sh          $t6, 0x20($t7)
    MEM_H(0X20, ctx->r15) = ctx->r14;
    return;
    // 0x80037AC0: sh          $t6, 0x20($t7)
    MEM_H(0X20, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_80037AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80037AC4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80037AC8: lw          $t7, -0x44E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X44E0);
    // 0x80037ACC: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x80037AD0: jr          $ra
    // 0x80037AD4: sh          $t6, 0x20($t7)
    MEM_H(0X20, ctx->r15) = ctx->r14;
    return;
    // 0x80037AD4: sh          $t6, 0x20($t7)
    MEM_H(0X20, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_80037AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // 0x80037AD8: beq         $a0, $zero, L_80037AF0
    if (ctx->r4 == 0) {
        // 0x80037ADC: nop
    
            goto L_80037AF0;
    }
    // 0x80037ADC: nop

    // 0x80037AE0: lh          $t6, 0x20($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X20);
    // 0x80037AE4: nop

    // 0x80037AE8: ori         $t7, $t6, 0xC000
    ctx->r15 = ctx->r14 | 0XC000;
    // 0x80037AEC: sh          $t7, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r15;
L_80037AF0:
    // 0x80037AF0: jr          $ra
    // 0x80037AF4: nop

    return;
    // 0x80037AF4: nop

;}
