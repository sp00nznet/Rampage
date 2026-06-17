#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_8003CB24(uint8_t* rdram, recomp_context* ctx);
void func_8003CB7C(uint8_t* rdram, recomp_context* ctx);
void func_8003CD74(uint8_t* rdram, recomp_context* ctx);
void func_8003D064(uint8_t* rdram, recomp_context* ctx);
void func_8003D1FC(uint8_t* rdram, recomp_context* ctx);
void func_8003D330(uint8_t* rdram, recomp_context* ctx);
void func_8003D3A4(uint8_t* rdram, recomp_context* ctx);
void func_8003D3AC(uint8_t* rdram, recomp_context* ctx);
void func_8003D7D4(uint8_t* rdram, recomp_context* ctx);
void func_8003DB04(uint8_t* rdram, recomp_context* ctx);
void func_8003DB44(uint8_t* rdram, recomp_context* ctx);
void func_8003DB84(uint8_t* rdram, recomp_context* ctx);
void func_8003DBCC(uint8_t* rdram, recomp_context* ctx);
void func_8003DC34(uint8_t* rdram, recomp_context* ctx);
void func_8003DF40(uint8_t* rdram, recomp_context* ctx);
void func_8003E2C4(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_8003C908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003C90C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003C910: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003C914: bne         $v0, $zero, L_8003C9B0
    if (ctx->r2 != 0) {
        // 0x8003C918: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8003C9B0;
    }
    // 0x8003C918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003C91C: jal         0x8003DC34
    // 0x8003C920: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8003DC34(rdram, ctx);
        goto after_0;
    // 0x8003C920: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x8003C924: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003C928: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003C92C: bne         $v0, $v1, L_8003C93C
    if (ctx->r2 != ctx->r3) {
        // 0x8003C930: nop
    
            goto L_8003C93C;
    }
    // 0x8003C930: nop

    // 0x8003C934: j           L_8003C9F0
    // 0x8003C938: addiu       $s0, $zero, 0x200
    ctx->r16 = ADD32(0, 0X200);
        goto L_8003C9F0;
    // 0x8003C938: addiu       $s0, $zero, 0x200
    ctx->r16 = ADD32(0, 0X200);
L_8003C93C:
    // 0x8003C93C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8003C940: lh          $v0, 0x4716($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4716);
    // 0x8003C944: beq         $v0, $zero, L_8003C998
    if (ctx->r2 == 0) {
        // 0x8003C948: nop
    
            goto L_8003C998;
    }
    // 0x8003C948: nop

    // 0x8003C94C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8003C950: lh          $v0, 0x4718($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4718);
    // 0x8003C954: beq         $v0, $zero, L_8003C998
    if (ctx->r2 == 0) {
        // 0x8003C958: nop
    
            goto L_8003C998;
    }
    // 0x8003C958: nop

    // 0x8003C95C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8003C960: lh          $v0, 0x471A($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X471A);
    // 0x8003C964: beq         $v0, $zero, L_8003C998
    if (ctx->r2 == 0) {
        // 0x8003C968: nop
    
            goto L_8003C998;
    }
    // 0x8003C968: nop

    // 0x8003C96C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8003C970: lh          $v0, -0x1D66($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X1D66);
    // 0x8003C974: slti        $v0, $v0, 0x4B
    ctx->r2 = SIGNED(ctx->r2) < 0X4B ? 1 : 0;
    // 0x8003C978: beq         $v0, $zero, L_8003C998
    if (ctx->r2 == 0) {
        // 0x8003C97C: addiu       $v0, $zero, 0x4B
        ctx->r2 = ADD32(0, 0X4B);
            goto L_8003C998;
    }
    // 0x8003C97C: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
    // 0x8003C980: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003C984: sh          $v0, 0x128($at)
    MEM_H(0X128, ctx->r1) = ctx->r2;
    // 0x8003C988: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003C98C: sh          $v0, -0x1D66($at)
    MEM_H(-0X1D66, ctx->r1) = ctx->r2;
    // 0x8003C990: j           L_8003C9F4
    // 0x8003C994: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
        goto L_8003C9F4;
    // 0x8003C994: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_8003C998:
    // 0x8003C998: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8003C99C: lhu         $v0, 0x128($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X128);
    // 0x8003C9A0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8003C9A4: lhu         $v1, -0x1D66($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X1D66);
    // 0x8003C9A8: j           L_8003C9DC
    // 0x8003C9AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8003C9DC;
    // 0x8003C9AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8003C9B0:
    // 0x8003C9B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8003C9B4: lhu         $v0, 0x128($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X128);
    // 0x8003C9B8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8003C9BC: lhu         $v1, -0x1D66($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X1D66);
    // 0x8003C9C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8003C9C4: sw          $zero, -0x307C($at)
    MEM_W(-0X307C, ctx->r1) = 0;
    // 0x8003C9C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003C9CC: sh          $zero, 0x538($at)
    MEM_H(0X538, ctx->r1) = 0;
    // 0x8003C9D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003C9D4: sh          $zero, -0x59EC($at)
    MEM_H(-0X59EC, ctx->r1) = 0;
    // 0x8003C9D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8003C9DC:
    // 0x8003C9DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003C9E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003C9E4: sh          $v0, 0x128($at)
    MEM_H(0X128, ctx->r1) = ctx->r2;
    // 0x8003C9E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003C9EC: sh          $v1, -0x1D66($at)
    MEM_H(-0X1D66, ctx->r1) = ctx->r3;
L_8003C9F0:
    // 0x8003C9F0: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_8003C9F4:
    // 0x8003C9F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003C9F8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003C9FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003CA00: jr          $ra
    // 0x8003CA04: nop

    return;
    // 0x8003CA04: nop

;}
RECOMP_FUNC void func_8003CA08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CA08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003CA0C: sh          $zero, 0x128($at)
    MEM_H(0X128, ctx->r1) = 0;
    // 0x8003CA10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003CA14: sh          $zero, -0x1D66($at)
    MEM_H(-0X1D66, ctx->r1) = 0;
    // 0x8003CA18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003CA1C: sh          $zero, 0x118($at)
    MEM_H(0X118, ctx->r1) = 0;
    // 0x8003CA20: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8003CA24: sh          $zero, 0x2560($at)
    MEM_H(0X2560, ctx->r1) = 0;
    // 0x8003CA28: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8003CA2C: sh          $zero, 0x50F4($at)
    MEM_H(0X50F4, ctx->r1) = 0;
    // 0x8003CA30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003CA34: sh          $zero, 0x538($at)
    MEM_H(0X538, ctx->r1) = 0;
    // 0x8003CA38: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003CA3C: sh          $zero, -0x59EC($at)
    MEM_H(-0X59EC, ctx->r1) = 0;
    // 0x8003CA40: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8003CA44: sh          $zero, -0x3058($at)
    MEM_H(-0X3058, ctx->r1) = 0;
    // 0x8003CA48: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8003CA4C: sh          $zero, 0x53D8($at)
    MEM_H(0X53D8, ctx->r1) = 0;
    // 0x8003CA50: jr          $ra
    // 0x8003CA54: nop

    return;
    // 0x8003CA54: nop

;}
RECOMP_FUNC void func_8003CA58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CA58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003CA5C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003CA60: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x8003CA64: addiu       $s1, $s1, -0x6C70
    ctx->r17 = ADD32(ctx->r17, -0X6C70);
    // 0x8003CA68: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003CA6C: addiu       $s2, $zero, 0xD
    ctx->r18 = ADD32(0, 0XD);
    // 0x8003CA70: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8003CA74: addiu       $s3, $zero, 0xF
    ctx->r19 = ADD32(0, 0XF);
    // 0x8003CA78: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8003CA7C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003CA80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003CA84: sh          $zero, 0x3E4($at)
    MEM_H(0X3E4, ctx->r1) = 0;
    // 0x8003CA88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003CA8C: sh          $zero, -0x67C6($at)
    MEM_H(-0X67C6, ctx->r1) = 0;
    // 0x8003CA90: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003CA94: sh          $zero, -0x5AFC($at)
    MEM_H(-0X5AFC, ctx->r1) = 0;
L_8003CA98:
    // 0x8003CA98: jal         0x8003DB04
    // 0x8003CA9C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8003DB04(rdram, ctx);
        goto after_0;
    // 0x8003CA9C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8003CAA0: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
    // 0x8003CAA4: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_8003CAA8:
    // 0x8003CAA8: subu        $v0, $s3, $v0
    ctx->r2 = SUB32(ctx->r19, ctx->r2);
    // 0x8003CAAC: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x8003CAB0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8003CAB4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8003CAB8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8003CABC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8003CAC0: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    // 0x8003CAC4: jal         0x8003DB44
    // 0x8003CAC8: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    func_8003DB44(rdram, ctx);
        goto after_1;
    // 0x8003CAC8: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    after_1:
    // 0x8003CACC: addiu       $v0, $s0, -0x1
    ctx->r2 = ADD32(ctx->r16, -0X1);
    // 0x8003CAD0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8003CAD4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003CAD8: bne         $v0, $zero, L_8003CAA8
    if (ctx->r2 != 0) {
        // 0x8003CADC: andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
            goto L_8003CAA8;
    }
    // 0x8003CADC: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8003CAE0: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x8003CAE4: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8003CAE8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003CAEC: bne         $v0, $zero, L_8003CA98
    if (ctx->r2 != 0) {
        // 0x8003CAF0: addiu       $s1, $s1, 0x584
        ctx->r17 = ADD32(ctx->r17, 0X584);
            goto L_8003CA98;
    }
    // 0x8003CAF0: addiu       $s1, $s1, 0x584
    ctx->r17 = ADD32(ctx->r17, 0X584);
    // 0x8003CAF4: jal         0x8003CB24
    // 0x8003CAF8: nop

    func_8003CB24(rdram, ctx);
        goto after_2;
    // 0x8003CAF8: nop

    after_2:
    // 0x8003CAFC: jal         0x8000FFA0
    // 0x8003CB00: nop

    func_8000FFA0(rdram, ctx);
        goto after_3;
    // 0x8003CB00: nop

    after_3:
    // 0x8003CB04: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8003CB08: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8003CB0C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003CB10: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003CB14: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003CB18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003CB1C: jr          $ra
    // 0x8003CB20: nop

    return;
    // 0x8003CB20: nop

;}
RECOMP_FUNC void func_8003CB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CB24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003CB28: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003CB2C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8003CB30: addiu       $s1, $s1, 0x3E8
    ctx->r17 = ADD32(ctx->r17, 0X3E8);
    // 0x8003CB34: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003CB38: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x8003CB3C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8003CB40: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8003CB44: sw          $s1, -0x3064($at)
    MEM_W(-0X3064, ctx->r1) = ctx->r17;
L_8003CB48:
    // 0x8003CB48: jal         0x8003CB7C
    // 0x8003CB4C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8003CB7C(rdram, ctx);
        goto after_0;
    // 0x8003CB4C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8003CB50: addiu       $v0, $s0, -0x1
    ctx->r2 = ADD32(ctx->r16, -0X1);
    // 0x8003CB54: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8003CB58: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003CB5C: bne         $v0, $zero, L_8003CB48
    if (ctx->r2 != 0) {
        // 0x8003CB60: nop
    
            goto L_8003CB48;
    }
    // 0x8003CB60: nop

    // 0x8003CB64: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8003CB68: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003CB6C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003CB70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003CB74: jr          $ra
    // 0x8003CB78: nop

    return;
    // 0x8003CB78: nop

;}
RECOMP_FUNC void func_8003CB7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CB7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003CB80: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003CB84: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8003CB88: jal         0x8007DEC0
    // 0x8003CB8C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8007DEC0(rdram, ctx);
        goto after_0;
    // 0x8003CB8C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_0:
    // 0x8003CB90: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003CB94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003CB98: jr          $ra
    // 0x8003CB9C: nop

    return;
    // 0x8003CB9C: nop

;}
RECOMP_FUNC void func_8003CBA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CBA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003CBA4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003CBA8: jal         0x8003CA58
    // 0x8003CBAC: nop

    func_8003CA58(rdram, ctx);
        goto after_0;
    // 0x8003CBAC: nop

    after_0:
    // 0x8003CBB0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003CBB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003CBB8: jr          $ra
    // 0x8003CBBC: nop

    return;
    // 0x8003CBBC: nop

;}
RECOMP_FUNC void func_8003CBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CBC0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003CBC4: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8003CBC8: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8003CBCC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8003CBD0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8003CBD4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003CBD8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003CBDC: jal         0x8003CA58
    // 0x8003CBE0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8003CA58(rdram, ctx);
        goto after_0;
    // 0x8003CBE0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8003CBE4: lui         $s3, 0x8016
    ctx->r19 = S32(0X8016 << 16);
    // 0x8003CBE8: addiu       $s3, $s3, -0x6C70
    ctx->r19 = ADD32(ctx->r19, -0X6C70);
    // 0x8003CBEC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8003CBF0: addiu       $a0, $a0, -0x7EF0
    ctx->r4 = ADD32(ctx->r4, -0X7EF0);
    // 0x8003CBF4: jal         0x8003DBCC
    // 0x8003CBF8: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    func_8003DBCC(rdram, ctx);
        goto after_1;
    // 0x8003CBF8: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    after_1:
    // 0x8003CBFC: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8003CC00: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8003CC04: addiu       $s1, $s2, 0x10
    ctx->r17 = ADD32(ctx->r18, 0X10);
    // 0x8003CC08: addiu       $s0, $s3, 0x2A
    ctx->r16 = ADD32(ctx->r19, 0X2A);
L_8003CC0C:
    // 0x8003CC0C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003CC10: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8003CC14: sh          $s4, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r20;
    // 0x8003CC18: sw          $a0, -0xA($s0)
    MEM_W(-0XA, ctx->r16) = ctx->r4;
    // 0x8003CC1C: lhu         $v0, -0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, -0X4);
    // 0x8003CC20: sh          $v0, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r2;
    // 0x8003CC24: lhu         $v0, -0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, -0X6);
    // 0x8003CC28: sh          $v0, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r2;
    // 0x8003CC2C: lw          $v0, -0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, -0XC);
    // 0x8003CC30: sw          $v0, -0x12($s0)
    MEM_W(-0X12, ctx->r16) = ctx->r2;
    // 0x8003CC34: lhu         $v0, -0x8($s1)
    ctx->r2 = MEM_HU(ctx->r17, -0X8);
    // 0x8003CC38: sh          $v0, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r2;
    // 0x8003CC3C: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x8003CC40: sh          $v0, -0x20($s0)
    MEM_H(-0X20, ctx->r16) = ctx->r2;
    // 0x8003CC44: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x8003CC48: sh          $v0, -0x22($s0)
    MEM_H(-0X22, ctx->r16) = ctx->r2;
    // 0x8003CC4C: lhu         $v1, -0x22($s0)
    ctx->r3 = MEM_HU(ctx->r16, -0X22);
    // 0x8003CC50: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8003CC54: beq         $v1, $v0, L_8003CC70
    if (ctx->r3 == ctx->r2) {
        // 0x8003CC58: sh          $zero, -0x16($s0)
        MEM_H(-0X16, ctx->r16) = 0;
            goto L_8003CC70;
    }
    // 0x8003CC58: sh          $zero, -0x16($s0)
    MEM_H(-0X16, ctx->r16) = 0;
    // 0x8003CC5C: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x8003CC60: bne         $v1, $v0, L_8003CC74
    if (ctx->r3 != ctx->r2) {
        // 0x8003CC64: addiu       $v0, $zero, 0xC5
        ctx->r2 = ADD32(0, 0XC5);
            goto L_8003CC74;
    }
    // 0x8003CC64: addiu       $v0, $zero, 0xC5
    ctx->r2 = ADD32(0, 0XC5);
    // 0x8003CC68: j           L_8003CC74
    // 0x8003CC6C: addiu       $v0, $zero, 0xD5
    ctx->r2 = ADD32(0, 0XD5);
        goto L_8003CC74;
    // 0x8003CC6C: addiu       $v0, $zero, 0xD5
    ctx->r2 = ADD32(0, 0XD5);
L_8003CC70:
    // 0x8003CC70: addiu       $v0, $zero, 0xCD
    ctx->r2 = ADD32(0, 0XCD);
L_8003CC74:
    // 0x8003CC74: sh          $v0, -0x24($s0)
    MEM_H(-0X24, ctx->r16) = ctx->r2;
    // 0x8003CC78: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8003CC7C: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8003CC80: sh          $v0, -0x26($s0)
    MEM_H(-0X26, ctx->r16) = ctx->r2;
    // 0x8003CC84: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8003CC88: addiu       $v1, $v1, -0x9
    ctx->r3 = ADD32(ctx->r3, -0X9);
    // 0x8003CC8C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003CC90: sh          $v0, -0x1C($s0)
    MEM_H(-0X1C, ctx->r16) = ctx->r2;
    // 0x8003CC94: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8003CC98: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8003CC9C: beq         $v1, $v0, L_8003CD14
    if (ctx->r3 == ctx->r2) {
        // 0x8003CCA0: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8003CD14;
    }
    // 0x8003CCA0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8003CCA4: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8003CCA8: sw          $v0, 0x32($s0)
    MEM_W(0X32, ctx->r16) = ctx->r2;
    // 0x8003CCAC: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8003CCB0: sw          $v0, 0x36($s0)
    MEM_W(0X36, ctx->r16) = ctx->r2;
    // 0x8003CCB4: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x8003CCB8: sw          $v0, 0x3A($s0)
    MEM_W(0X3A, ctx->r16) = ctx->r2;
    // 0x8003CCBC: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8003CCC0: sw          $v0, 0x3E($s0)
    MEM_W(0X3E, ctx->r16) = ctx->r2;
    // 0x8003CCC4: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8003CCC8: sw          $v0, 0x62($s0)
    MEM_W(0X62, ctx->r16) = ctx->r2;
    // 0x8003CCCC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003CCD0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8003CCD4: jal         0x80001414
    // 0x8003CCD8: sh          $v0, -0x28($s0)
    MEM_H(-0X28, ctx->r16) = ctx->r2;
    func_80001414(rdram, ctx);
        goto after_2;
    // 0x8003CCD8: sh          $v0, -0x28($s0)
    MEM_H(-0X28, ctx->r16) = ctx->r2;
    after_2:
    // 0x8003CCDC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8003CCE0: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x8003CCE4: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x8003CCE8: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8003CCEC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8003CCF0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8003CCF4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003CCF8: sh          $v0, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r2;
    // 0x8003CCFC: sh          $s5, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r21;
    // 0x8003CD00: sh          $s5, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r21;
    // 0x8003CD04: jal         0x8003CD74
    // 0x8003CD08: sh          $s5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r21;
    func_8003CD74(rdram, ctx);
        goto after_3;
    // 0x8003CD08: sh          $s5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r21;
    after_3:
    // 0x8003CD0C: j           L_8003CD20
    // 0x8003CD10: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
        goto L_8003CD20;
    // 0x8003CD10: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
L_8003CD14:
    // 0x8003CD14: jal         0x8003D064
    // 0x8003CD18: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8003D064(rdram, ctx);
        goto after_4;
    // 0x8003CD18: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_4:
    // 0x8003CD1C: addiu       $s0, $s0, 0x584
    ctx->r16 = ADD32(ctx->r16, 0X584);
L_8003CD20:
    // 0x8003CD20: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x8003CD24: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8003CD28: addiu       $s3, $s3, 0x584
    ctx->r19 = ADD32(ctx->r19, 0X584);
    // 0x8003CD2C: bne         $v0, $zero, L_8003CC0C
    if (ctx->r2 != 0) {
        // 0x8003CD30: addiu       $s1, $s1, 0x18
        ctx->r17 = ADD32(ctx->r17, 0X18);
            goto L_8003CC0C;
    }
    // 0x8003CD30: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x8003CD34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003CD38: sh          $s4, 0x3E4($at)
    MEM_H(0X3E4, ctx->r1) = ctx->r20;
    // 0x8003CD3C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003CD40: sh          $s4, -0x67C6($at)
    MEM_H(-0X67C6, ctx->r1) = ctx->r20;
    // 0x8003CD44: jal         0x8003D7D4
    // 0x8003CD48: nop

    func_8003D7D4(rdram, ctx);
        goto after_5;
    // 0x8003CD48: nop

    after_5:
    // 0x8003CD4C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8003CD50: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8003CD54: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8003CD58: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8003CD5C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003CD60: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003CD64: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003CD68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003CD6C: jr          $ra
    // 0x8003CD70: nop

    return;
    // 0x8003CD70: nop

;}
RECOMP_FUNC void func_8003CD74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CD74: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003CD78: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003CD7C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8003CD80: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8003CD84: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8003CD88: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8003CD8C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8003CD90: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8003CD94: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8003CD98: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8003CD9C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003CDA0: jal         0x800306EC
    // 0x8003CDA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x8003CDA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8003CDA8: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // 0x8003CDAC: addiu       $v0, $zero, 0x710
    ctx->r2 = ADD32(0, 0X710);
    // 0x8003CDB0: sw          $v0, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r2;
    // 0x8003CDB4: lhu         $s5, 0x6($s1)
    ctx->r21 = MEM_HU(ctx->r17, 0X6);
    // 0x8003CDB8: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x8003CDBC: addiu       $s3, $s1, 0x98
    ctx->r19 = ADD32(ctx->r17, 0X98);
    // 0x8003CDC0: sh          $v0, 0x10($s6)
    MEM_H(0X10, ctx->r22) = ctx->r2;
    // 0x8003CDC4: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x8003CDC8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8003CDCC: lhu         $a2, 0x8($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X8);
    // 0x8003CDD0: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    // 0x8003CDD4: addiu       $s5, $s5, -0x1D
    ctx->r21 = ADD32(ctx->r21, -0X1D);
    // 0x8003CDD8: addiu       $s7, $v0, 0x20
    ctx->r23 = ADD32(ctx->r2, 0X20);
    // 0x8003CDDC: beq         $a0, $zero, L_8003CE80
    if (ctx->r4 == 0) {
        // 0x8003CDE0: sh          $a2, 0x16($sp)
        MEM_H(0X16, ctx->r29) = ctx->r6;
            goto L_8003CE80;
    }
    // 0x8003CDE0: sh          $a2, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r6;
    // 0x8003CDE4: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8003CDE8: addiu       $s0, $s1, 0xD8
    ctx->r16 = ADD32(ctx->r17, 0XD8);
L_8003CDEC:
    // 0x8003CDEC: sw          $a0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r4;
    // 0x8003CDF0: jal         0x8005F320
    // 0x8003CDF4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8005F320(rdram, ctx);
        goto after_1;
    // 0x8003CDF4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8003CDF8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8003CDFC: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8003CE00: sra         $s2, $v0, 16
    ctx->r18 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003CE04: beql        $s2, $fp, L_8003CE18
    if (ctx->r18 == ctx->r30) {
        // 0x8003CE08: sh          $s5, 0x14($s6)
        MEM_H(0X14, ctx->r22) = ctx->r21;
            goto L_8003CE18;
    }
    goto skip_0;
    // 0x8003CE08: sh          $s5, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r21;
    skip_0:
    // 0x8003CE0C: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x8003CE10: subu        $s5, $s5, $v0
    ctx->r21 = SUB32(ctx->r21, ctx->r2);
    // 0x8003CE14: sh          $s5, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r21;
L_8003CE18:
    // 0x8003CE18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003CE1C: sw          $s6, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r22;
    // 0x8003CE20: jal         0x80023E44
    // 0x8003CE24: nop

    func_80023E44(rdram, ctx);
        goto after_2;
    // 0x8003CE24: nop

    after_2:
    // 0x8003CE28: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8003CE2C: sw          $v1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r3;
    // 0x8003CE30: sw          $s3, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r19;
    // 0x8003CE34: lhu         $a2, 0x16($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X16);
    // 0x8003CE38: sh          $a2, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r6;
    // 0x8003CE3C: beq         $s2, $fp, L_8003CE50
    if (ctx->r18 == ctx->r30) {
        // 0x8003CE40: sh          $s4, -0x3C($s0)
        MEM_H(-0X3C, ctx->r16) = ctx->r20;
            goto L_8003CE50;
    }
    // 0x8003CE40: sh          $s4, -0x3C($s0)
    MEM_H(-0X3C, ctx->r16) = ctx->r20;
    // 0x8003CE44: lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X8);
    // 0x8003CE48: addiu       $v0, $v0, -0x9
    ctx->r2 = ADD32(ctx->r2, -0X9);
    // 0x8003CE4C: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
L_8003CE50:
    // 0x8003CE50: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8003CE54: sh          $a2, -0x18($s0)
    MEM_H(-0X18, ctx->r16) = ctx->r6;
    // 0x8003CE58: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8003CE5C: sw          $s1, -0x38($s0)
    MEM_W(-0X38, ctx->r16) = ctx->r17;
    // 0x8003CE60: sh          $fp, -0x30($s0)
    MEM_H(-0X30, ctx->r16) = ctx->r30;
    // 0x8003CE64: sh          $a2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r6;
    // 0x8003CE68: addiu       $s0, $s0, 0x54
    ctx->r16 = ADD32(ctx->r16, 0X54);
    // 0x8003CE6C: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x8003CE70: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    // 0x8003CE74: addiu       $s3, $s3, 0x54
    ctx->r19 = ADD32(ctx->r19, 0X54);
    // 0x8003CE78: bne         $a0, $zero, L_8003CDEC
    if (ctx->r4 != 0) {
        // 0x8003CE7C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8003CDEC;
    }
    // 0x8003CE7C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8003CE80:
    // 0x8003CE80: addiu       $s3, $s3, -0x54
    ctx->r19 = ADD32(ctx->r19, -0X54);
    // 0x8003CE84: sw          $s3, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->r19;
    // 0x8003CE88: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8003CE8C: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x8003CE90: lhu         $v1, 0x30($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X30);
    // 0x8003CE94: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8003CE98: addiu       $s0, $s4, -0x1
    ctx->r16 = ADD32(ctx->r20, -0X1);
    // 0x8003CE9C: sh          $zero, 0x14($s1)
    MEM_H(0X14, ctx->r17) = 0;
    // 0x8003CEA0: sh          $s0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r16;
    // 0x8003CEA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003CEA8: addiu       $v0, $v0, -0xC
    ctx->r2 = ADD32(ctx->r2, -0XC);
    // 0x8003CEAC: jal         0x8003DB84
    // 0x8003CEB0: sh          $v0, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r2;
    func_8003DB84(rdram, ctx);
        goto after_3;
    // 0x8003CEB0: sh          $v0, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r2;
    after_3:
    // 0x8003CEB4: jal         0x8003D3A4
    // 0x8003CEB8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8003D3A4(rdram, ctx);
        goto after_4;
    // 0x8003CEB8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // 0x8003CEBC: jal         0x8003D1FC
    // 0x8003CEC0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8003D1FC(rdram, ctx);
        goto after_5;
    // 0x8003CEC0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // 0x8003CEC4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8003CEC8: lhu         $a0, 0x2($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X2);
    // 0x8003CECC: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8003CED0: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8003CED4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8003CED8: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x8003CEDC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8003CEE0: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003CEE4: mflo        $v0
    ctx->r2 = lo;
    // 0x8003CEE8: nop

    // 0x8003CEEC: nop

    // 0x8003CEF0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8003CEF4: lh          $v1, 0x13E2($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X13E2);
    // 0x8003CEF8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8003CEFC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8003CF00: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003CF04: mflo        $v1
    ctx->r3 = lo;
    // 0x8003CF08: nop

    // 0x8003CF0C: nop

    // 0x8003CF10: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x8003CF14: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x8003CF18: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003CF1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003CF20: sw          $a0, 0x31B4($at)
    MEM_W(0X31B4, ctx->r1) = ctx->r4;
    // 0x8003CF24: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x8003CF28: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8003CF2C: mfhi        $a2
    ctx->r6 = hi;
    // 0x8003CF30: nop

    // 0x8003CF34: nop

    // 0x8003CF38: sra         $v0, $a2, 5
    ctx->r2 = S32(SIGNED(ctx->r6) >> 5);
    // 0x8003CF3C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8003CF40: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003CF44: beq         $a0, $zero, L_8003CF54
    if (ctx->r4 == 0) {
        // 0x8003CF48: sh          $v1, 0x12($s1)
        MEM_H(0X12, ctx->r17) = ctx->r3;
            goto L_8003CF54;
    }
    // 0x8003CF48: sh          $v1, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r3;
    // 0x8003CF4C: jal         0x8003D3AC
    // 0x8003CF50: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8003D3AC(rdram, ctx);
        goto after_6;
    // 0x8003CF50: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
L_8003CF54:
    // 0x8003CF54: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8003CF58: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8003CF5C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8003CF60: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8003CF64: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8003CF68: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8003CF6C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8003CF70: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003CF74: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003CF78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003CF7C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8003CF80: jr          $ra
    // 0x8003CF84: nop

    return;
    // 0x8003CF84: nop

;}
RECOMP_FUNC void func_8003CF88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003CF8C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003CF90: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x8003CF94: lw          $s2, 0x31C0($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X31C0);
    // 0x8003CF98: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003CF9C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003CFA0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003CFA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003CFA8: jal         0x800306EC
    // 0x8003CFAC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x8003CFAC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    after_0:
    // 0x8003CFB0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8003CFB4: lh          $v1, -0x1D66($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X1D66);
    // 0x8003CFB8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8003CFBC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003CFC0: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x8003CFC4: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x8003CFC8: bne         $v1, $v0, L_8003CFE0
    if (ctx->r3 != ctx->r2) {
        // 0x8003CFCC: nop
    
            goto L_8003CFE0;
    }
    // 0x8003CFCC: nop

    // 0x8003CFD0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8003CFD4: addiu       $v0, $v0, 0x5A4C
    ctx->r2 = ADD32(ctx->r2, 0X5A4C);
    // 0x8003CFD8: j           L_8003CFEC
    // 0x8003CFDC: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
        goto L_8003CFEC;
    // 0x8003CFDC: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
L_8003CFE0:
    // 0x8003CFE0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8003CFE4: addiu       $v0, $v0, 0x59FC
    ctx->r2 = ADD32(ctx->r2, 0X59FC);
    // 0x8003CFE8: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
L_8003CFEC:
    // 0x8003CFEC: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x8003CFF0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003CFF4: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x8003CFF8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8003CFFC: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x8003D000: addiu       $v0, $v0, 0x2F
    ctx->r2 = ADD32(ctx->r2, 0X2F);
    // 0x8003D004: sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // 0x8003D008: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x8003D00C: addiu       $v0, $v0, -0x3A
    ctx->r2 = ADD32(ctx->r2, -0X3A);
    // 0x8003D010: sh          $v0, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r2;
    // 0x8003D014: lhu         $v0, 0x80($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X80);
    // 0x8003D018: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003D01C: jal         0x80023E44
    // 0x8003D020: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x8003D020: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
    after_1:
    // 0x8003D024: addiu       $v1, $zero, 0x728
    ctx->r3 = ADD32(0, 0X728);
    // 0x8003D028: sh          $v1, 0x70($v0)
    MEM_H(0X70, ctx->r2) = ctx->r3;
    // 0x8003D02C: lhu         $v1, 0x80($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X80);
    // 0x8003D030: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003D034: sw          $v0, -0x74E4($at)
    MEM_W(-0X74E4, ctx->r1) = ctx->r2;
    // 0x8003D038: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003D03C: sh          $v1, 0x80($v0)
    MEM_H(0X80, ctx->r2) = ctx->r3;
    // 0x8003D040: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003D044: sw          $s2, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r18;
    // 0x8003D048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D04C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003D050: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003D054: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003D058: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003D05C: jr          $ra
    // 0x8003D060: nop

    return;
    // 0x8003D060: nop

;}
RECOMP_FUNC void func_8003D064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D064: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003D068: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003D06C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003D070: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8003D074: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8003D078: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8003D07C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8003D080: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003D084: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003D088: lw          $s2, 0x20($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X20);
    // 0x8003D08C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8003D090: sh          $s5, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r21;
    // 0x8003D094: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x8003D098: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
    // 0x8003D09C: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x8003D0A0: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8003D0A4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8003D0A8: jal         0x800306EC
    // 0x8003D0AC: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x8003D0AC: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    after_0:
    // 0x8003D0B0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8003D0B4: addiu       $v0, $zero, 0x728
    ctx->r2 = ADD32(0, 0X728);
    // 0x8003D0B8: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8003D0BC: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x8003D0C0: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
    // 0x8003D0C4: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x8003D0C8: sh          $v0, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r2;
    // 0x8003D0CC: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x8003D0D0: lhu         $s4, 0x8($s0)
    ctx->r20 = MEM_HU(ctx->r16, 0X8);
    // 0x8003D0D4: beq         $v0, $zero, L_8003D1D4
    if (ctx->r2 == 0) {
        // 0x8003D0D8: addiu       $s3, $s0, 0x98
        ctx->r19 = ADD32(ctx->r16, 0X98);
            goto L_8003D1D4;
    }
    // 0x8003D0D8: addiu       $s3, $s0, 0x98
    ctx->r19 = ADD32(ctx->r16, 0X98);
    // 0x8003D0DC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8003D0E0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003D0E4: sw          $v1, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r3;
    // 0x8003D0E8: jal         0x80023E44
    // 0x8003D0EC: nop

    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x8003D0EC: nop

    after_1:
    // 0x8003D0F0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8003D0F4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8003D0F8: addiu       $v0, $v0, 0x5990
    ctx->r2 = ADD32(ctx->r2, 0X5990);
    // 0x8003D0FC: sw          $s1, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r17;
    // 0x8003D100: sw          $s3, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r19;
    // 0x8003D104: sh          $s4, 0x80($s1)
    MEM_H(0X80, ctx->r17) = ctx->r20;
    // 0x8003D108: sw          $s0, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r16;
    // 0x8003D10C: sh          $s5, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r21;
    // 0x8003D110: sh          $s5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r21;
    // 0x8003D114: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x8003D118: bne         $s2, $v0, L_8003D154
    if (ctx->r18 != ctx->r2) {
        // 0x8003D11C: sw          $s3, 0x70($s0)
        MEM_W(0X70, ctx->r16) = ctx->r19;
            goto L_8003D154;
    }
    // 0x8003D11C: sw          $s3, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r19;
    // 0x8003D120: lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18);
    // 0x8003D124: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003D128: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8003D12C: addiu       $v0, $v0, -0x5C
    ctx->r2 = ADD32(ctx->r2, -0X5C);
    // 0x8003D130: sh          $v0, 0x74($s0)
    MEM_H(0X74, ctx->r16) = ctx->r2;
    // 0x8003D134: addiu       $v0, $zero, 0x72A
    ctx->r2 = ADD32(0, 0X72A);
    // 0x8003D138: sh          $v0, 0x70($s1)
    MEM_H(0X70, ctx->r17) = ctx->r2;
    // 0x8003D13C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8003D140: sh          $v0, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r2;
    // 0x8003D144: jal         0x8003CF88
    // 0x8003D148: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    func_8003CF88(rdram, ctx);
        goto after_2;
    // 0x8003D148: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    after_2:
    // 0x8003D14C: j           L_8003D1CC
    // 0x8003D150: nop

        goto L_8003D1CC;
    // 0x8003D150: nop

L_8003D154:
    // 0x8003D154: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8003D158: addiu       $v0, $v0, -0x73DC
    ctx->r2 = ADD32(ctx->r2, -0X73DC);
    // 0x8003D15C: bne         $s2, $v0, L_8003D18C
    if (ctx->r18 != ctx->r2) {
        // 0x8003D160: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8003D18C;
    }
    // 0x8003D160: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8003D164: lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18);
    // 0x8003D168: addiu       $v0, $v0, -0x3E
    ctx->r2 = ADD32(ctx->r2, -0X3E);
    // 0x8003D16C: sh          $v0, 0x74($s0)
    MEM_H(0X74, ctx->r16) = ctx->r2;
    // 0x8003D170: addiu       $v0, $zero, 0x72A
    ctx->r2 = ADD32(0, 0X72A);
    // 0x8003D174: sh          $v0, 0x70($s1)
    MEM_H(0X70, ctx->r17) = ctx->r2;
    // 0x8003D178: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8003D17C: sh          $v0, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r2;
    // 0x8003D180: addiu       $v0, $zero, 0x7D
    ctx->r2 = ADD32(0, 0X7D);
    // 0x8003D184: j           L_8003D1CC
    // 0x8003D188: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
        goto L_8003D1CC;
    // 0x8003D188: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
L_8003D18C:
    // 0x8003D18C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8003D190: lw          $v1, -0x307C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X307C);
    // 0x8003D194: beq         $v1, $zero, L_8003D1C0
    if (ctx->r3 == 0) {
        // 0x8003D198: sh          $v0, 0x12($s0)
        MEM_H(0X12, ctx->r16) = ctx->r2;
            goto L_8003D1C0;
    }
    // 0x8003D198: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    // 0x8003D19C: jal         0x80027338
    // 0x8003D1A0: nop

    func_80027338(rdram, ctx);
        goto after_3;
    // 0x8003D1A0: nop

    after_3:
    // 0x8003D1A4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8003D1A8: bne         $v0, $v1, L_8003D1C0
    if (ctx->r2 != ctx->r3) {
        // 0x8003D1AC: nop
    
            goto L_8003D1C0;
    }
    // 0x8003D1AC: nop

    // 0x8003D1B0: lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18);
    // 0x8003D1B4: sh          $zero, 0x58($s0)
    MEM_H(0X58, ctx->r16) = 0;
    // 0x8003D1B8: j           L_8003D1C8
    // 0x8003D1BC: addiu       $v0, $v0, -0x1F
    ctx->r2 = ADD32(ctx->r2, -0X1F);
        goto L_8003D1C8;
    // 0x8003D1BC: addiu       $v0, $v0, -0x1F
    ctx->r2 = ADD32(ctx->r2, -0X1F);
L_8003D1C0:
    // 0x8003D1C0: lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18);
    // 0x8003D1C4: addiu       $v0, $v0, -0x3E
    ctx->r2 = ADD32(ctx->r2, -0X3E);
L_8003D1C8:
    // 0x8003D1C8: sh          $v0, 0x74($s0)
    MEM_H(0X74, ctx->r16) = ctx->r2;
L_8003D1CC:
    // 0x8003D1CC: jal         0x8003D1FC
    // 0x8003D1D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003D1FC(rdram, ctx);
        goto after_4;
    // 0x8003D1D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
L_8003D1D4:
    // 0x8003D1D4: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8003D1D8: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8003D1DC: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8003D1E0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D1E4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003D1E8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003D1EC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003D1F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003D1F4: jr          $ra
    // 0x8003D1F8: nop

    return;
    // 0x8003D1F8: nop

;}
RECOMP_FUNC void func_8003D1FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D1FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003D200: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003D204: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8003D208: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8003D20C: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x8003D210: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8003D214: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8003D218: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8003D21C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8003D220: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003D224: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003D228: lw          $s6, 0x20($s1)
    ctx->r22 = MEM_W(ctx->r17, 0X20);
    // 0x8003D22C: jal         0x8003D330
    // 0x8003D230: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8003D330(rdram, ctx);
        goto after_0;
    // 0x8003D230: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8003D234: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8003D238: addiu       $s0, $s0, 0x7BA0
    ctx->r16 = ADD32(ctx->r16, 0X7BA0);
    // 0x8003D23C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003D240: beq         $v0, $zero, L_8003D300
    if (ctx->r2 == 0) {
        // 0x8003D244: ori         $s3, $zero, 0xFFFF
        ctx->r19 = 0 | 0XFFFF;
            goto L_8003D300;
    }
    // 0x8003D244: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x8003D248: lui         $s5, 0xFFFF
    ctx->r21 = S32(0XFFFF << 16);
    // 0x8003D24C: ori         $s5, $s5, 0x10
    ctx->r21 = ctx->r21 | 0X10;
    // 0x8003D250: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8003D254: lui         $s4, 0xFFFE
    ctx->r20 = S32(0XFFFE << 16);
    // 0x8003D258: ori         $s4, $s4, 0x3
    ctx->r20 = ctx->r20 | 0X3;
    // 0x8003D25C: lui         $s7, 0x2
    ctx->r23 = S32(0X2 << 16);
L_8003D260:
    // 0x8003D260: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003D264: bnel        $v0, $s6, L_8003D2F4
    if (ctx->r2 != ctx->r22) {
        // 0x8003D268: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8003D2F4;
    }
    goto skip_0;
    // 0x8003D268: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    skip_0:
    // 0x8003D26C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8003D270: bne         $v1, $s3, L_8003D28C
    if (ctx->r3 != ctx->r19) {
        // 0x8003D274: addu        $v0, $v1, $s5
        ctx->r2 = ADD32(ctx->r3, ctx->r21);
            goto L_8003D28C;
    }
    // 0x8003D274: addu        $v0, $v1, $s5
    ctx->r2 = ADD32(ctx->r3, ctx->r21);
    // 0x8003D278: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8003D27C: jal         0x8003D330
    // 0x8003D280: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003D330(rdram, ctx);
        goto after_1;
    // 0x8003D280: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8003D284: j           L_8003D2F4
    // 0x8003D288: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_8003D2F4;
    // 0x8003D288: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8003D28C:
    // 0x8003D28C: sltiu       $v0, $v0, 0xF
    ctx->r2 = ctx->r2 < 0XF ? 1 : 0;
    // 0x8003D290: beq         $v0, $zero, L_8003D2C4
    if (ctx->r2 == 0) {
        // 0x8003D294: addiu       $a0, $s1, 0x98
        ctx->r4 = ADD32(ctx->r17, 0X98);
            goto L_8003D2C4;
    }
    // 0x8003D294: addiu       $a0, $s1, 0x98
    ctx->r4 = ADD32(ctx->r17, 0X98);
    // 0x8003D298: subu        $v1, $s3, $v1
    ctx->r3 = SUB32(ctx->r19, ctx->r3);
    // 0x8003D29C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8003D2A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003D2A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003D2A8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003D2AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003D2B0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8003D2B4: sh          $s2, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r18;
    // 0x8003D2B8: sh          $s2, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r18;
    // 0x8003D2BC: j           L_8003D2F0
    // 0x8003D2C0: sh          $s2, 0x50($a0)
    MEM_H(0X50, ctx->r4) = ctx->r18;
        goto L_8003D2F0;
    // 0x8003D2C0: sh          $s2, 0x50($a0)
    MEM_H(0X50, ctx->r4) = ctx->r18;
L_8003D2C4:
    // 0x8003D2C4: addu        $v0, $v1, $s4
    ctx->r2 = ADD32(ctx->r3, ctx->r20);
    // 0x8003D2C8: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8003D2CC: beq         $v0, $zero, L_8003D2E4
    if (ctx->r2 == 0) {
        // 0x8003D2D0: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8003D2E4;
    }
    // 0x8003D2D0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8003D2D4: jal         0x8003D330
    // 0x8003D2D8: subu        $a1, $s7, $v1
    ctx->r5 = SUB32(ctx->r23, ctx->r3);
    func_8003D330(rdram, ctx);
        goto after_2;
    // 0x8003D2D8: subu        $a1, $s7, $v1
    ctx->r5 = SUB32(ctx->r23, ctx->r3);
    after_2:
    // 0x8003D2DC: j           L_8003D2F4
    // 0x8003D2E0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_8003D2F4;
    // 0x8003D2E0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8003D2E4:
    // 0x8003D2E4: addiu       $v0, $v1, 0x98
    ctx->r2 = ADD32(ctx->r3, 0X98);
    // 0x8003D2E8: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8003D2EC: sh          $s2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r18;
L_8003D2F0:
    // 0x8003D2F0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8003D2F4:
    // 0x8003D2F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003D2F8: bne         $v0, $zero, L_8003D260
    if (ctx->r2 != 0) {
        // 0x8003D2FC: nop
    
            goto L_8003D260;
    }
    // 0x8003D2FC: nop

L_8003D300:
    // 0x8003D300: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8003D304: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D308: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8003D30C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8003D310: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8003D314: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D318: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003D31C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003D320: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003D324: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8003D328: jr          $ra
    // 0x8003D32C: nop

    return;
    // 0x8003D32C: nop

;}
RECOMP_FUNC void func_8003D330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D330: lhu         $a2, 0x0($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X0);
    // 0x8003D334: beq         $a2, $zero, L_8003D39C
    if (ctx->r6 == 0) {
        // 0x8003D338: nop
    
            goto L_8003D39C;
    }
    // 0x8003D338: nop

    // 0x8003D33C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8003D340: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8003D344: beq         $v0, $zero, L_8003D39C
    if (ctx->r2 == 0) {
        // 0x8003D348: sltiu       $v0, $a1, 0x1
        ctx->r2 = ctx->r5 < 0X1 ? 1 : 0;
            goto L_8003D39C;
    }
    // 0x8003D348: sltiu       $v0, $a1, 0x1
    ctx->r2 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x8003D34C: sltiu       $t1, $a1, 0x2
    ctx->r9 = ctx->r5 < 0X2 ? 1 : 0;
    // 0x8003D350: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8003D354: xori        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 ^ 0X3;
    // 0x8003D358: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8003D35C: or          $t0, $v0, $v1
    ctx->r8 = ctx->r2 | ctx->r3;
    // 0x8003D360: xori        $v1, $a1, 0x2
    ctx->r3 = ctx->r5 ^ 0X2;
    // 0x8003D364: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8003D368: or          $v1, $v0, $v1
    ctx->r3 = ctx->r2 | ctx->r3;
    // 0x8003D36C: addiu       $a0, $a0, 0xE8
    ctx->r4 = ADD32(ctx->r4, 0XE8);
L_8003D370:
    // 0x8003D370: bnel        $t1, $zero, L_8003D378
    if (ctx->r9 != 0) {
        // 0x8003D374: sh          $a3, -0x30($a0)
        MEM_H(-0X30, ctx->r4) = ctx->r7;
            goto L_8003D378;
    }
    goto skip_0;
    // 0x8003D374: sh          $a3, -0x30($a0)
    MEM_H(-0X30, ctx->r4) = ctx->r7;
    skip_0:
L_8003D378:
    // 0x8003D378: bnel        $t0, $zero, L_8003D380
    if (ctx->r8 != 0) {
        // 0x8003D37C: sh          $a3, -0x18($a0)
        MEM_H(-0X18, ctx->r4) = ctx->r7;
            goto L_8003D380;
    }
    goto skip_1;
    // 0x8003D37C: sh          $a3, -0x18($a0)
    MEM_H(-0X18, ctx->r4) = ctx->r7;
    skip_1:
L_8003D380:
    // 0x8003D380: bnel        $v1, $zero, L_8003D388
    if (ctx->r3 != 0) {
        // 0x8003D384: sh          $a3, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r7;
            goto L_8003D388;
    }
    goto skip_2;
    // 0x8003D384: sh          $a3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r7;
    skip_2:
L_8003D388:
    // 0x8003D388: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x8003D38C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8003D390: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003D394: bne         $v0, $zero, L_8003D370
    if (ctx->r2 != 0) {
        // 0x8003D398: addiu       $a0, $a0, 0x54
        ctx->r4 = ADD32(ctx->r4, 0X54);
            goto L_8003D370;
    }
    // 0x8003D398: addiu       $a0, $a0, 0x54
    ctx->r4 = ADD32(ctx->r4, 0X54);
L_8003D39C:
    // 0x8003D39C: jr          $ra
    // 0x8003D3A0: nop

    return;
    // 0x8003D3A0: nop

;}
RECOMP_FUNC void func_8003D3A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D3A4: jr          $ra
    // 0x8003D3A8: nop

    return;
    // 0x8003D3A8: nop

;}
RECOMP_FUNC void func_8003D3AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D3AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003D3B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003D3B4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8003D3B8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8003D3BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003D3C0: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x8003D3C4: beq         $v0, $zero, L_8003D4F0
    if (ctx->r2 == 0) {
        // 0x8003D3C8: nop
    
            goto L_8003D4F0;
    }
    // 0x8003D3C8: nop

    // 0x8003D3CC: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8003D3D0: lw          $s0, -0x3064($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X3064);
    // 0x8003D3D4: jal         0x800306EC
    // 0x8003D3D8: nop

    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x8003D3D8: nop

    after_0:
    // 0x8003D3DC: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8003D3E0: addiu       $v0, $zero, 0x719
    ctx->r2 = ADD32(0, 0X719);
    // 0x8003D3E4: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x8003D3E8: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x8003D3EC: sw          $v0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r2;
    // 0x8003D3F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8003D3F4: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // 0x8003D3F8: lhu         $v0, 0xE($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XE);
    // 0x8003D3FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003D400: sh          $v0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r2;
    // 0x8003D404: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x8003D408: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    // 0x8003D40C: lh          $v1, 0x8A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8A);
    // 0x8003D410: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003D414: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x8003D418: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x8003D41C: lhu         $a1, 0x30($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X30);
    // 0x8003D420: lhu         $v0, 0x18($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X18);
    // 0x8003D424: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8003D428: slti        $v1, $v1, 0x2
    ctx->r3 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8003D42C: addu        $a2, $v0, $a1
    ctx->r6 = ADD32(ctx->r2, ctx->r5);
    // 0x8003D430: beq         $v1, $zero, L_8003D43C
    if (ctx->r3 == 0) {
        // 0x8003D434: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_8003D43C;
    }
    // 0x8003D434: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8003D438: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_8003D43C:
    // 0x8003D43C: sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7 << 16);
    // 0x8003D440: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003D444: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8003D448: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003D44C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003D450: bnel        $v0, $zero, L_8003D458
    if (ctx->r2 != 0) {
        // 0x8003D454: addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
            goto L_8003D458;
    }
    goto skip_0;
    // 0x8003D454: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    skip_0:
L_8003D458:
    // 0x8003D458: sh          $a3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r7;
    // 0x8003D45C: j           L_8003D468
    // 0x8003D460: subu        $v0, $a0, $a3
    ctx->r2 = SUB32(ctx->r4, ctx->r7);
        goto L_8003D468;
    // 0x8003D460: subu        $v0, $a0, $a3
    ctx->r2 = SUB32(ctx->r4, ctx->r7);
L_8003D464:
    // 0x8003D464: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
L_8003D468:
    // 0x8003D468: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8003D46C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003D470: bnel        $v0, $zero, L_8003D464
    if (ctx->r2 != 0) {
        // 0x8003D474: addiu       $a2, $a2, 0x18
        ctx->r6 = ADD32(ctx->r6, 0X18);
            goto L_8003D464;
    }
    goto skip_1;
    // 0x8003D474: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    skip_1:
    // 0x8003D478: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x8003D47C: sh          $a2, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r6;
    // 0x8003D480: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x8003D484: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003D488: sw          $v0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r2;
    // 0x8003D48C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003D490: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8003D494: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x8003D498: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8003D49C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8003D4A0: lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X8);
    // 0x8003D4A4: sw          $v0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r2;
    // 0x8003D4A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003D4AC: sw          $t0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r8;
    // 0x8003D4B0: jal         0x80023E44
    // 0x8003D4B4: nop

    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x8003D4B4: nop

    after_1:
    // 0x8003D4B8: lhu         $v1, 0x18($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X18);
    // 0x8003D4BC: lhu         $a0, 0x1C($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X1C);
    // 0x8003D4C0: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8003D4C4: sh          $v1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r3;
    // 0x8003D4C8: lhu         $a0, 0x30($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X30);
    // 0x8003D4CC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8003D4D0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8003D4D4: sh          $v1, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r3;
    // 0x8003D4D8: sw          $s0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r16;
    // 0x8003D4DC: sw          $s0, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r16;
    // 0x8003D4E0: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8003D4E4: sw          $s1, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->r17;
    // 0x8003D4E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8003D4EC: sw          $s0, -0x3064($at)
    MEM_W(-0X3064, ctx->r1) = ctx->r16;
L_8003D4F0:
    // 0x8003D4F0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8003D4F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D4F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003D4FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003D500: jr          $ra
    // 0x8003D504: nop

    return;
    // 0x8003D504: nop

;}
RECOMP_FUNC void func_8003D508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D50C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003D510: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003D514: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D518: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8003D51C: beq         $a0, $zero, L_8003D52C
    if (ctx->r4 == 0) {
        // 0x8003D520: nop
    
            goto L_8003D52C;
    }
    // 0x8003D520: nop

    // 0x8003D524: jal         0x80024764
    // 0x8003D528: nop

    func_80024764(rdram, ctx);
        goto after_0;
    // 0x8003D528: nop

    after_0:
L_8003D52C:
    // 0x8003D52C: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x8003D530: beq         $a0, $zero, L_8003D540
    if (ctx->r4 == 0) {
        // 0x8003D534: nop
    
            goto L_8003D540;
    }
    // 0x8003D534: nop

    // 0x8003D538: jal         0x80024764
    // 0x8003D53C: nop

    func_80024764(rdram, ctx);
        goto after_1;
    // 0x8003D53C: nop

    after_1:
L_8003D540:
    // 0x8003D540: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8003D544: beq         $a0, $zero, L_8003D554
    if (ctx->r4 == 0) {
        // 0x8003D548: nop
    
            goto L_8003D554;
    }
    // 0x8003D548: nop

    // 0x8003D54C: jal         0x80024764
    // 0x8003D550: nop

    func_80024764(rdram, ctx);
        goto after_2;
    // 0x8003D550: nop

    after_2:
L_8003D554:
    // 0x8003D554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D558: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003D55C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D560: jr          $ra
    // 0x8003D564: nop

    return;
    // 0x8003D564: nop

;}
RECOMP_FUNC void func_8003D568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D56C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003D570: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003D574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D578: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x8003D57C: beq         $a0, $zero, L_8003D58C
    if (ctx->r4 == 0) {
        // 0x8003D580: nop
    
            goto L_8003D58C;
    }
    // 0x8003D580: nop

    // 0x8003D584: jal         0x80024764
    // 0x8003D588: nop

    func_80024764(rdram, ctx);
        goto after_0;
    // 0x8003D588: nop

    after_0:
L_8003D58C:
    // 0x8003D58C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8003D590: beq         $a0, $zero, L_8003D5A0
    if (ctx->r4 == 0) {
        // 0x8003D594: nop
    
            goto L_8003D5A0;
    }
    // 0x8003D594: nop

    // 0x8003D598: jal         0x80024764
    // 0x8003D59C: nop

    func_80024764(rdram, ctx);
        goto after_1;
    // 0x8003D59C: nop

    after_1:
L_8003D5A0:
    // 0x8003D5A0: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x8003D5A4: beq         $a0, $zero, L_8003D5B4
    if (ctx->r4 == 0) {
        // 0x8003D5A8: nop
    
            goto L_8003D5B4;
    }
    // 0x8003D5A8: nop

    // 0x8003D5AC: jal         0x80024764
    // 0x8003D5B0: nop

    func_80024764(rdram, ctx);
        goto after_2;
    // 0x8003D5B0: nop

    after_2:
L_8003D5B4:
    // 0x8003D5B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D5B8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003D5BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D5C0: jr          $ra
    // 0x8003D5C4: nop

    return;
    // 0x8003D5C4: nop

;}
RECOMP_FUNC void func_8003D5C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D5C8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8003D5CC: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x8003D5D0: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x8003D5D4: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
    // 0x8003D5D8: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x8003D5DC: jr          $ra
    // 0x8003D5E0: sw          $zero, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = 0;
    return;
    // 0x8003D5E0: sw          $zero, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = 0;
;}
RECOMP_FUNC void func_8003D5E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D5E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003D5E8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003D5EC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003D5F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003D5F4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003D5F8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003D5FC: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x8003D600: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8003D604: addiu       $s1, $s1, 0x31C0
    ctx->r17 = ADD32(ctx->r17, 0X31C0);
    // 0x8003D608: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8003D60C: beq         $a0, $zero, L_8003D620
    if (ctx->r4 == 0) {
        // 0x8003D610: nop
    
            goto L_8003D620;
    }
    // 0x8003D610: nop

    // 0x8003D614: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003D618: jal         0x80036CD0
    // 0x8003D61C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    func_80036CD0(rdram, ctx);
        goto after_0;
    // 0x8003D61C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    after_0:
L_8003D620:
    // 0x8003D620: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x8003D624: beq         $a0, $zero, L_8003D638
    if (ctx->r4 == 0) {
        // 0x8003D628: nop
    
            goto L_8003D638;
    }
    // 0x8003D628: nop

    // 0x8003D62C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003D630: jal         0x80036CD0
    // 0x8003D634: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    func_80036CD0(rdram, ctx);
        goto after_1;
    // 0x8003D634: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    after_1:
L_8003D638:
    // 0x8003D638: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x8003D63C: beql        $a0, $zero, L_8003D654
    if (ctx->r4 == 0) {
        // 0x8003D640: sw          $s2, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r18;
            goto L_8003D654;
    }
    goto skip_0;
    // 0x8003D640: sw          $s2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r18;
    skip_0:
    // 0x8003D644: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003D648: jal         0x80036CD0
    // 0x8003D64C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    func_80036CD0(rdram, ctx);
        goto after_2;
    // 0x8003D64C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    after_2:
    // 0x8003D650: sw          $s2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r18;
L_8003D654:
    // 0x8003D654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D658: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003D65C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003D660: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003D664: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003D668: jr          $ra
    // 0x8003D66C: nop

    return;
    // 0x8003D66C: nop

;}
RECOMP_FUNC void func_8003D670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D674: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003D678: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003D67C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D680: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x8003D684: beq         $a0, $zero, L_8003D694
    if (ctx->r4 == 0) {
        // 0x8003D688: nop
    
            goto L_8003D694;
    }
    // 0x8003D688: nop

    // 0x8003D68C: jal         0x80031F94
    // 0x8003D690: nop

    func_80031F94(rdram, ctx);
        goto after_0;
    // 0x8003D690: nop

    after_0:
L_8003D694:
    // 0x8003D694: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x8003D698: beq         $a0, $zero, L_8003D6A8
    if (ctx->r4 == 0) {
        // 0x8003D69C: nop
    
            goto L_8003D6A8;
    }
    // 0x8003D69C: nop

    // 0x8003D6A0: jal         0x80031F94
    // 0x8003D6A4: nop

    func_80031F94(rdram, ctx);
        goto after_1;
    // 0x8003D6A4: nop

    after_1:
L_8003D6A8:
    // 0x8003D6A8: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x8003D6AC: beq         $a0, $zero, L_8003D6BC
    if (ctx->r4 == 0) {
        // 0x8003D6B0: nop
    
            goto L_8003D6BC;
    }
    // 0x8003D6B0: nop

    // 0x8003D6B4: jal         0x80031F94
    // 0x8003D6B8: nop

    func_80031F94(rdram, ctx);
        goto after_2;
    // 0x8003D6B8: nop

    after_2:
L_8003D6BC:
    // 0x8003D6BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D6C0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003D6C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D6C8: jr          $ra
    // 0x8003D6CC: nop

    return;
    // 0x8003D6CC: nop

;}
RECOMP_FUNC void func_8003D6D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D6D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D6D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003D6D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D6DC: jal         0x8003D508
    // 0x8003D6E0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8003D508(rdram, ctx);
        goto after_0;
    // 0x8003D6E0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8003D6E4: jal         0x8003D568
    // 0x8003D6E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003D568(rdram, ctx);
        goto after_1;
    // 0x8003D6E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003D6EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D6F0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003D6F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D6F8: jr          $ra
    // 0x8003D6FC: nop

    return;
    // 0x8003D6FC: nop

;}
RECOMP_FUNC void func_8003D700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D704: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003D708: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003D70C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D710: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8003D714: beq         $a0, $zero, L_8003D744
    if (ctx->r4 == 0) {
        // 0x8003D718: nop
    
            goto L_8003D744;
    }
    // 0x8003D718: nop

    // 0x8003D71C: jal         0x80024764
    // 0x8003D720: nop

    func_80024764(rdram, ctx);
        goto after_0;
    // 0x8003D720: nop

    after_0:
    // 0x8003D724: jal         0x8003D508
    // 0x8003D728: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003D508(rdram, ctx);
        goto after_1;
    // 0x8003D728: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003D72C: jal         0x8003D568
    // 0x8003D730: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003D568(rdram, ctx);
        goto after_2;
    // 0x8003D730: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8003D734: jal         0x8003D5E4
    // 0x8003D738: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003D5E4(rdram, ctx);
        goto after_3;
    // 0x8003D738: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8003D73C: jal         0x8003D670
    // 0x8003D740: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003D670(rdram, ctx);
        goto after_4;
    // 0x8003D740: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
L_8003D744:
    // 0x8003D744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D748: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003D74C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D750: jr          $ra
    // 0x8003D754: nop

    return;
    // 0x8003D754: nop

;}
RECOMP_FUNC void func_8003D758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D75C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003D760: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003D764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D768: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003D76C: beq         $v0, $zero, L_8003D794
    if (ctx->r2 == 0) {
        // 0x8003D770: nop
    
            goto L_8003D794;
    }
    // 0x8003D770: nop

    // 0x8003D774: jal         0x8003D508
    // 0x8003D778: nop

    func_8003D508(rdram, ctx);
        goto after_0;
    // 0x8003D778: nop

    after_0:
    // 0x8003D77C: jal         0x8003D568
    // 0x8003D780: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003D568(rdram, ctx);
        goto after_1;
    // 0x8003D780: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003D784: jal         0x8003D5E4
    // 0x8003D788: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003D5E4(rdram, ctx);
        goto after_2;
    // 0x8003D788: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8003D78C: jal         0x8003D670
    // 0x8003D790: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003D670(rdram, ctx);
        goto after_3;
    // 0x8003D790: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
L_8003D794:
    // 0x8003D794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D798: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003D79C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D7A0: jr          $ra
    // 0x8003D7A4: nop

    return;
    // 0x8003D7A4: nop

;}
RECOMP_FUNC void func_8003D7A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D7A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D7AC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003D7B0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8003D7B4: beq         $a0, $zero, L_8003D7C4
    if (ctx->r4 == 0) {
        // 0x8003D7B8: nop
    
            goto L_8003D7C4;
    }
    // 0x8003D7B8: nop

    // 0x8003D7BC: jal         0x80024764
    // 0x8003D7C0: nop

    func_80024764(rdram, ctx);
        goto after_0;
    // 0x8003D7C0: nop

    after_0:
L_8003D7C4:
    // 0x8003D7C4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003D7C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D7CC: jr          $ra
    // 0x8003D7D0: nop

    return;
    // 0x8003D7D0: nop

;}
RECOMP_FUNC void func_8003D7D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D7D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8003D7D8: lhu         $a0, 0x3E4($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X3E4);
    // 0x8003D7DC: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x8003D7E0: addiu       $a3, $a3, -0x6C70
    ctx->r7 = ADD32(ctx->r7, -0X6C70);
    // 0x8003D7E4: beq         $a0, $zero, L_8003D9FC
    if (ctx->r4 == 0) {
                return; // L_8003D9FC is jr $ra
    }

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_8003D7E8
    func_8003D7E8(rdram, ctx);
}
RECOMP_FUNC void func_8003D7E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D7E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003D7EC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8003D7F0: lhu         $a1, -0x6C68($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X6C68);
    // 0x8003D7F4: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8003D7F8: andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // 0x8003D7FC: beq         $v1, $v0, L_8003D834
    if (ctx->r3 == ctx->r2) {
        // 0x8003D800: addiu       $v1, $zero, 0x200
        ctx->r3 = ADD32(0, 0X200);
            goto L_8003D834;
    }
    // 0x8003D800: addiu       $v1, $zero, 0x200
    ctx->r3 = ADD32(0, 0X200);
    // 0x8003D804: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
L_8003D808:
    // 0x8003D808: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8003D80C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003D810: beq         $v0, $zero, L_8003D824
    if (ctx->r2 == 0) {
        // 0x8003D814: addiu       $a3, $a3, 0x584
        ctx->r7 = ADD32(ctx->r7, 0X584);
            goto L_8003D824;
    }
    // 0x8003D814: addiu       $a3, $a3, 0x584
    ctx->r7 = ADD32(ctx->r7, 0X584);
    // 0x8003D818: lhu         $a1, 0x8($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0X8);
    // 0x8003D81C: bne         $a1, $v1, L_8003D808
    if (ctx->r5 != ctx->r3) {
        // 0x8003D820: addiu       $v0, $a0, -0x1
        ctx->r2 = ADD32(ctx->r4, -0X1);
            goto L_8003D808;
    }
    // 0x8003D820: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
L_8003D824:
    // 0x8003D824: andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // 0x8003D828: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8003D82C: bne         $v1, $v0, L_8003D9FC
    if (ctx->r3 != ctx->r2) {
        // 0x8003D830: nop
    
            goto L_8003D9FC;
    }
    // 0x8003D830: nop

L_8003D834:
    // 0x8003D834: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8003D838: lhu         $t7, 0x3E4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X3E4);
L_8003D83C:
    // 0x8003D83C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8003D840: addiu       $t4, $t4, -0x6C70
    ctx->r12 = ADD32(ctx->r12, -0X6C70);
    // 0x8003D844: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x8003D848: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003D84C: addiu       $t5, $t4, 0xE
    ctx->r13 = ADD32(ctx->r12, 0XE);
L_8003D850:
    // 0x8003D850: lhu         $v0, -0x6($t5)
    ctx->r2 = MEM_HU(ctx->r13, -0X6);
    // 0x8003D854: sltu        $v0, $t9, $v0
    ctx->r2 = ctx->r25 < ctx->r2 ? 1 : 0;
    // 0x8003D858: beql        $v0, $zero, L_8003D9AC
    if (ctx->r2 == 0) {
        // 0x8003D85C: addiu       $t5, $t5, 0x584
        ctx->r13 = ADD32(ctx->r13, 0X584);
            goto L_8003D9AC;
    }
    goto skip_0;
    // 0x8003D85C: addiu       $t5, $t5, 0x584
    ctx->r13 = ADD32(ctx->r13, 0X584);
    skip_0:
    // 0x8003D860: lh          $t0, -0xA($t5)
    ctx->r8 = MEM_H(ctx->r13, -0XA);
    // 0x8003D864: lh          $a2, 0x4($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X4);
    // 0x8003D868: lh          $a1, 0x0($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X0);
    // 0x8003D86C: lh          $a0, 0xE($a3)
    ctx->r4 = MEM_H(ctx->r7, 0XE);
    // 0x8003D870: addu        $t6, $t0, $zero
    ctx->r14 = ADD32(ctx->r8, 0);
    // 0x8003D874: addu        $t3, $a2, $zero
    ctx->r11 = ADD32(ctx->r6, 0);
    // 0x8003D878: slt         $v1, $a2, $t0
    ctx->r3 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8003D87C: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x8003D880: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003D884: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8003D888: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8003D88C: beq         $v1, $zero, L_8003D970
    if (ctx->r3 == 0) {
        // 0x8003D890: addu        $t2, $a0, $zero
        ctx->r10 = ADD32(ctx->r4, 0);
            goto L_8003D970;
    }
    // 0x8003D890: addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // 0x8003D894: slt         $v0, $t0, $a2
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8003D898: beq         $v0, $zero, L_8003D8FC
    if (ctx->r2 == 0) {
        // 0x8003D89C: slt         $v0, $a2, $a1
        ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8003D8FC;
    }
    // 0x8003D89C: slt         $v0, $a2, $a1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003D8A0: beql        $v0, $zero, L_8003D9AC
    if (ctx->r2 == 0) {
        // 0x8003D8A4: addiu       $t5, $t5, 0x584
        ctx->r13 = ADD32(ctx->r13, 0X584);
            goto L_8003D9AC;
    }
    goto skip_1;
    // 0x8003D8A4: addiu       $t5, $t5, 0x584
    ctx->r13 = ADD32(ctx->r13, 0X584);
    skip_1:
    // 0x8003D8A8: lhu         $a0, 0x0($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X0);
    // 0x8003D8AC: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x8003D8B0: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8003D8B4: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8003D8B8: bne         $v0, $zero, L_8003D8C8
    if (ctx->r2 != 0) {
        // 0x8003D8BC: nop
    
            goto L_8003D8C8;
    }
    // 0x8003D8BC: nop

    // 0x8003D8C0: j           L_8003D8D4
    // 0x8003D8C4: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
        goto L_8003D8D4;
    // 0x8003D8C4: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
L_8003D8C8:
    // 0x8003D8C8: bne         $v1, $t8, L_8003D8D4
    if (ctx->r3 != ctx->r24) {
        // 0x8003D8CC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8003D8D4;
    }
    // 0x8003D8CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003D8D0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_8003D8D4:
    // 0x8003D8D4: sll         $v1, $t1, 16
    ctx->r3 = S32(ctx->r9 << 16);
    // 0x8003D8D8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003D8DC: sll         $v0, $t3, 16
    ctx->r2 = S32(ctx->r11 << 16);
    // 0x8003D8E0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003D8E4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8003D8E8: slti        $v1, $v1, 0x29
    ctx->r3 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    // 0x8003D8EC: bne         $v1, $zero, L_8003D9A8
    if (ctx->r3 != 0) {
        // 0x8003D8F0: sh          $a0, 0x24($a3)
        MEM_H(0X24, ctx->r7) = ctx->r4;
            goto L_8003D9A8;
    }
    // 0x8003D8F0: sh          $a0, 0x24($a3)
    MEM_H(0X24, ctx->r7) = ctx->r4;
    // 0x8003D8F4: j           L_8003D9A8
    // 0x8003D8F8: sh          $a0, 0x26($a3)
    MEM_H(0X26, ctx->r7) = ctx->r4;
        goto L_8003D9A8;
    // 0x8003D8F8: sh          $a0, 0x26($a3)
    MEM_H(0X26, ctx->r7) = ctx->r4;
L_8003D8FC:
    // 0x8003D8FC: slt         $v0, $t0, $a0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003D900: beq         $v0, $zero, L_8003D9A8
    if (ctx->r2 == 0) {
        // 0x8003D904: slt         $v0, $a1, $a0
        ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8003D9A8;
    }
    // 0x8003D904: slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003D908: beq         $v0, $zero, L_8003D91C
    if (ctx->r2 == 0) {
        // 0x8003D90C: subu        $v0, $a0, $a1
        ctx->r2 = SUB32(ctx->r4, ctx->r5);
            goto L_8003D91C;
    }
    // 0x8003D90C: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // 0x8003D910: slti        $v0, $v0, 0x14
    ctx->r2 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8003D914: beql        $v0, $zero, L_8003D9AC
    if (ctx->r2 == 0) {
        // 0x8003D918: addiu       $t5, $t5, 0x584
        ctx->r13 = ADD32(ctx->r13, 0X584);
            goto L_8003D9AC;
    }
    goto skip_2;
    // 0x8003D918: addiu       $t5, $t5, 0x584
    ctx->r13 = ADD32(ctx->r13, 0X584);
    skip_2:
L_8003D91C:
    // 0x8003D91C: lhu         $a0, 0x0($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X0);
    // 0x8003D920: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x8003D924: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8003D928: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8003D92C: bne         $v0, $zero, L_8003D93C
    if (ctx->r2 != 0) {
        // 0x8003D930: nop
    
            goto L_8003D93C;
    }
    // 0x8003D930: nop

    // 0x8003D934: j           L_8003D948
    // 0x8003D938: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
        goto L_8003D948;
    // 0x8003D938: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
L_8003D93C:
    // 0x8003D93C: bne         $v1, $t8, L_8003D948
    if (ctx->r3 != ctx->r24) {
        // 0x8003D940: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8003D948;
    }
    // 0x8003D940: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003D944: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_8003D948:
    // 0x8003D948: sll         $v1, $t2, 16
    ctx->r3 = S32(ctx->r10 << 16);
    // 0x8003D94C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003D950: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x8003D954: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003D958: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8003D95C: slti        $v1, $v1, 0x29
    ctx->r3 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    // 0x8003D960: bne         $v1, $zero, L_8003D9A8
    if (ctx->r3 != 0) {
        // 0x8003D964: sh          $a0, 0x28($a3)
        MEM_H(0X28, ctx->r7) = ctx->r4;
            goto L_8003D9A8;
    }
    // 0x8003D964: sh          $a0, 0x28($a3)
    MEM_H(0X28, ctx->r7) = ctx->r4;
    // 0x8003D968: j           L_8003D9A8
    // 0x8003D96C: sh          $a0, 0x26($a3)
    MEM_H(0X26, ctx->r7) = ctx->r4;
        goto L_8003D9A8;
    // 0x8003D96C: sh          $a0, 0x26($a3)
    MEM_H(0X26, ctx->r7) = ctx->r4;
L_8003D970:
    // 0x8003D970: lhu         $a0, 0x0($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X0);
    // 0x8003D974: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x8003D978: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8003D97C: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8003D980: bne         $v0, $zero, L_8003D990
    if (ctx->r2 != 0) {
        // 0x8003D984: nop
    
            goto L_8003D990;
    }
    // 0x8003D984: nop

    // 0x8003D988: j           L_8003D99C
    // 0x8003D98C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
        goto L_8003D99C;
    // 0x8003D98C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
L_8003D990:
    // 0x8003D990: bne         $v1, $t8, L_8003D99C
    if (ctx->r3 != ctx->r24) {
        // 0x8003D994: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8003D99C;
    }
    // 0x8003D994: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003D998: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_8003D99C:
    // 0x8003D99C: sh          $a0, 0x24($a3)
    MEM_H(0X24, ctx->r7) = ctx->r4;
    // 0x8003D9A0: sh          $a0, 0x28($a3)
    MEM_H(0X28, ctx->r7) = ctx->r4;
    // 0x8003D9A4: sh          $a0, 0x26($a3)
    MEM_H(0X26, ctx->r7) = ctx->r4;
L_8003D9A8:
    // 0x8003D9A8: addiu       $t5, $t5, 0x584
    ctx->r13 = ADD32(ctx->r13, 0X584);
L_8003D9AC:
    // 0x8003D9AC: addiu       $v0, $t7, -0x1
    ctx->r2 = ADD32(ctx->r15, -0X1);
    // 0x8003D9B0: addu        $t7, $v0, $zero
    ctx->r15 = ADD32(ctx->r2, 0);
    // 0x8003D9B4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003D9B8: bne         $v0, $zero, L_8003D850
    if (ctx->r2 != 0) {
        // 0x8003D9BC: addiu       $t4, $t4, 0x584
        ctx->r12 = ADD32(ctx->r12, 0X584);
            goto L_8003D850;
    }
    // 0x8003D9BC: addiu       $t4, $t4, 0x584
    ctx->r12 = ADD32(ctx->r12, 0X584);
    // 0x8003D9C0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8003D9C4: lhu         $t7, 0x3E4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X3E4);
    // 0x8003D9C8: lhu         $v0, 0x1E($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X1E);
    // 0x8003D9CC: andi        $v1, $t7, 0xFFFF
    ctx->r3 = ctx->r15 & 0XFFFF;
    // 0x8003D9D0: beq         $v0, $v1, L_8003D9FC
    if (ctx->r2 == ctx->r3) {
        // 0x8003D9D4: addiu       $a2, $zero, 0x200
        ctx->r6 = ADD32(0, 0X200);
            goto L_8003D9FC;
    }
    // 0x8003D9D4: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    // 0x8003D9D8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8003D9DC: addiu       $v1, $a3, 0x1E
    ctx->r3 = ADD32(ctx->r7, 0X1E);
    // 0x8003D9E0: addiu       $v1, $v1, 0x584
    ctx->r3 = ADD32(ctx->r3, 0X584);
L_8003D9E4:
    // 0x8003D9E4: lhu         $a1, -0x16($v1)
    ctx->r5 = MEM_HU(ctx->r3, -0X16);
    // 0x8003D9E8: beq         $a1, $a2, L_8003D83C
    if (ctx->r5 == ctx->r6) {
        // 0x8003D9EC: addiu       $a3, $a3, 0x584
        ctx->r7 = ADD32(ctx->r7, 0X584);
            goto L_8003D83C;
    }
    // 0x8003D9EC: addiu       $a3, $a3, 0x584
    ctx->r7 = ADD32(ctx->r7, 0X584);
    // 0x8003D9F0: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8003D9F4: bne         $v0, $a0, L_8003D9E4
    if (ctx->r2 != ctx->r4) {
        // 0x8003D9F8: addiu       $v1, $v1, 0x584
        ctx->r3 = ADD32(ctx->r3, 0X584);
            goto L_8003D9E4;
    }
    // 0x8003D9F8: addiu       $v1, $v1, 0x584
    ctx->r3 = ADD32(ctx->r3, 0X584);
L_8003D9FC:
    // 0x8003D9FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003DA00: jr          $ra
    // 0x8003DA04: nop

    return;
    // 0x8003DA04: nop

;}
RECOMP_FUNC void func_8003DA08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DA08: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003DA0C: lh          $v0, -0x67C6($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X67C6);
    // 0x8003DA10: bne         $v0, $zero, L_8003DA28
    if (ctx->r2 != 0) {
        // 0x8003DA14: addiu       $v0, $zero, 0x160
        ctx->r2 = ADD32(0, 0X160);
            goto L_8003DA28;
    }
    // 0x8003DA14: addiu       $v0, $zero, 0x160
    ctx->r2 = ADD32(0, 0X160);
    // 0x8003DA18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003DA1C: sh          $zero, 0x4E66($at)
    MEM_H(0X4E66, ctx->r1) = 0;
    // 0x8003DA20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003DA24: sh          $v0, 0x90($at)
    MEM_H(0X90, ctx->r1) = ctx->r2;
L_8003DA28:
    // 0x8003DA28: jr          $ra
    // 0x8003DA2C: nop

    return;
    // 0x8003DA2C: nop

;}
RECOMP_FUNC void func_8003DA30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DA30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003DA34: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8003DA38: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8003DA3C: lhu         $s4, 0x3E4($s4)
    ctx->r20 = MEM_HU(ctx->r20, 0X3E4);
    // 0x8003DA40: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8003DA44: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8003DA48: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8003DA4C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003DA50: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003DA54: beq         $s4, $zero, L_8003DADC
    if (ctx->r20 == 0) {
        // 0x8003DA58: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8003DADC;
    }
    // 0x8003DA58: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003DA5C: lui         $s3, 0x8016
    ctx->r19 = S32(0X8016 << 16);
    // 0x8003DA60: addiu       $s3, $s3, -0x6C70
    ctx->r19 = ADD32(ctx->r19, -0X6C70);
    // 0x8003DA64: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x8003DA68: addiu       $s5, $zero, 0x11
    ctx->r21 = ADD32(0, 0X11);
L_8003DA6C:
    // 0x8003DA6C: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x8003DA70: lhu         $s1, 0x0($s0)
    ctx->r17 = MEM_HU(ctx->r16, 0X0);
    // 0x8003DA74: lhu         $s2, 0x14($s0)
    ctx->r18 = MEM_HU(ctx->r16, 0X14);
    // 0x8003DA78: beq         $a0, $zero, L_8003DA8C
    if (ctx->r4 == 0) {
        // 0x8003DA7C: nop
    
            goto L_8003DA8C;
    }
    // 0x8003DA7C: nop

    // 0x8003DA80: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8003DA84: jal         0x80024764
    // 0x8003DA88: nop

    func_80024764(rdram, ctx);
        goto after_0;
    // 0x8003DA88: nop

    after_0:
L_8003DA8C:
    // 0x8003DA8C: jal         0x8003DB04
    // 0x8003DA90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003DB04(rdram, ctx);
        goto after_1;
    // 0x8003DA90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003DA94: addiu       $s0, $s0, 0x98
    ctx->r16 = ADD32(ctx->r16, 0X98);
    // 0x8003DA98: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
L_8003DA9C:
    // 0x8003DA9C: jal         0x8003D700
    // 0x8003DAA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003D700(rdram, ctx);
        goto after_2;
    // 0x8003DAA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8003DAA4: jal         0x8003DB44
    // 0x8003DAA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003DB44(rdram, ctx);
        goto after_3;
    // 0x8003DAA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8003DAAC: beq         $s2, $s5, L_8003DAC4
    if (ctx->r18 == ctx->r21) {
        // 0x8003DAB0: addiu       $v0, $s1, -0x1
        ctx->r2 = ADD32(ctx->r17, -0X1);
            goto L_8003DAC4;
    }
    // 0x8003DAB0: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x8003DAB4: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8003DAB8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003DABC: bne         $v0, $zero, L_8003DA9C
    if (ctx->r2 != 0) {
        // 0x8003DAC0: addiu       $s0, $s0, 0x54
        ctx->r16 = ADD32(ctx->r16, 0X54);
            goto L_8003DA9C;
    }
    // 0x8003DAC0: addiu       $s0, $s0, 0x54
    ctx->r16 = ADD32(ctx->r16, 0X54);
L_8003DAC4:
    // 0x8003DAC4: addiu       $s3, $s3, 0x584
    ctx->r19 = ADD32(ctx->r19, 0X584);
    // 0x8003DAC8: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // 0x8003DACC: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x8003DAD0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003DAD4: bne         $v0, $zero, L_8003DA6C
    if (ctx->r2 != 0) {
        // 0x8003DAD8: addu        $s0, $s3, $zero
        ctx->r16 = ADD32(ctx->r19, 0);
            goto L_8003DA6C;
    }
    // 0x8003DAD8: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
L_8003DADC:
    // 0x8003DADC: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8003DAE0: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8003DAE4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8003DAE8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DAEC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003DAF0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003DAF4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003DAF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003DAFC: jr          $ra
    // 0x8003DB00: nop

    return;
    // 0x8003DB00: nop

;}
RECOMP_FUNC void func_8003DB04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DB04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DB08: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8003DB0C: addiu       $v1, $v1, -0x6C70
    ctx->r3 = ADD32(ctx->r3, -0X6C70);
    // 0x8003DB10: sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x8003DB14: bne         $v0, $zero, L_8003DB34
    if (ctx->r2 != 0) {
        // 0x8003DB18: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8003DB34;
    }
    // 0x8003DB18: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003DB1C: addiu       $v0, $v1, 0x47B4
    ctx->r2 = ADD32(ctx->r3, 0X47B4);
    // 0x8003DB20: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8003DB24: beq         $v0, $zero, L_8003DB34
    if (ctx->r2 == 0) {
        // 0x8003DB28: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8003DB34;
    }
    // 0x8003DB28: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8003DB2C: jal         0x8007DEC0
    // 0x8003DB30: addiu       $a2, $zero, 0x98
    ctx->r6 = ADD32(0, 0X98);
    func_8007DEC0(rdram, ctx);
        goto after_0;
    // 0x8003DB30: addiu       $a2, $zero, 0x98
    ctx->r6 = ADD32(0, 0X98);
    after_0:
L_8003DB34:
    // 0x8003DB34: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003DB38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DB3C: jr          $ra
    // 0x8003DB40: nop

    return;
    // 0x8003DB40: nop

;}
RECOMP_FUNC void func_8003DB44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DB44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DB48: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8003DB4C: addiu       $v1, $v1, -0x6C70
    ctx->r3 = ADD32(ctx->r3, -0X6C70);
    // 0x8003DB50: sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x8003DB54: bne         $v0, $zero, L_8003DB74
    if (ctx->r2 != 0) {
        // 0x8003DB58: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8003DB74;
    }
    // 0x8003DB58: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003DB5C: addiu       $v0, $v1, 0x47B4
    ctx->r2 = ADD32(ctx->r3, 0X47B4);
    // 0x8003DB60: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8003DB64: bne         $v0, $zero, L_8003DB74
    if (ctx->r2 != 0) {
        // 0x8003DB68: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8003DB74;
    }
    // 0x8003DB68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8003DB6C: jal         0x8007DEC0
    // 0x8003DB70: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    func_8007DEC0(rdram, ctx);
        goto after_0;
    // 0x8003DB70: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    after_0:
L_8003DB74:
    // 0x8003DB74: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003DB78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DB7C: jr          $ra
    // 0x8003DB80: nop

    return;
    // 0x8003DB80: nop

;}
RECOMP_FUNC void func_8003DB84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DB84: lhu         $v0, 0x38($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X38);
    // 0x8003DB88: bne         $v0, $zero, L_8003DBC4
    if (ctx->r2 != 0) {
        // 0x8003DB8C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003DBC4;
    }
    // 0x8003DB8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003DB90: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8003DB94: addiu       $a1, $a0, 0x3A
    ctx->r5 = ADD32(ctx->r4, 0X3A);
    // 0x8003DB98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003DB9C: sh          $v0, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r2;
    // 0x8003DBA0: addiu       $v0, $v1, 0x9
    ctx->r2 = ADD32(ctx->r3, 0X9);
    // 0x8003DBA4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8003DBA8: sh          $v0, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r2;
L_8003DBAC:
    // 0x8003DBAC: sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
    // 0x8003DBB0: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8003DBB4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8003DBB8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003DBBC: bne         $v0, $zero, L_8003DBAC
    if (ctx->r2 != 0) {
        // 0x8003DBC0: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_8003DBAC;
    }
    // 0x8003DBC0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_8003DBC4:
    // 0x8003DBC4: jr          $ra
    // 0x8003DBC8: nop

    return;
    // 0x8003DBC8: nop

;}
RECOMP_FUNC void func_8003DBCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DBCC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8003DBD0: lhu         $v1, 0x538($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X538);
    // 0x8003DBD4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8003DBD8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003DBDC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8003DBE0: beq         $v1, $zero, L_8003DBF8
    if (ctx->r3 == 0) {
        // 0x8003DBE4: nop
    
            goto L_8003DBF8;
    }
    // 0x8003DBE4: nop

    // 0x8003DBE8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8003DBEC: lhu         $v0, 0x2560($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2560);
    // 0x8003DBF0: j           L_8003DC04
    // 0x8003DBF4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
        goto L_8003DC04;
    // 0x8003DBF4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_8003DBF8:
    // 0x8003DBF8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8003DBFC: lhu         $v0, -0x1D66($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X1D66);
    // 0x8003DC00: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_8003DC04:
    // 0x8003DC04: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003DC08: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003DC0C: jr          $ra
    // 0x8003DC10: nop

    return;
    // 0x8003DC10: nop

;}
RECOMP_FUNC void func_8003DC14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DC14: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8003DC18: lhu         $v0, 0x538($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X538);
    // 0x8003DC1C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003DC20: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003DC24: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003DC28: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003DC2C: jr          $ra
    // 0x8003DC30: nop

    return;
    // 0x8003DC30: nop

;}
RECOMP_FUNC void func_8003DC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DC34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8003DC38: lhu         $v0, -0x1D66($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X1D66);
    // 0x8003DC3C: lui         $a0, 0x51EB
    ctx->r4 = S32(0X51EB << 16);
    // 0x8003DC40: ori         $a0, $a0, 0x851F
    ctx->r4 = ctx->r4 | 0X851F;
    // 0x8003DC44: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003DC48: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003DC4C: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
;}
RECOMP_FUNC void func_8003DC50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DC50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DC54: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8003DC58: mfhi        $a1
    ctx->r5 = hi;
    // 0x8003DC5C: nop

    // 0x8003DC60: nop

    // 0x8003DC64: sra         $a0, $a1, 3
    ctx->r4 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8003DC68: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8003DC6C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8003DC70: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003DC74: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003DC78: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003DC7C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8003DC80: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8003DC84: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8003DC88: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003DC8C: sltiu       $v0, $v1, 0x14
    ctx->r2 = ctx->r3 < 0X14 ? 1 : 0;
    // 0x8003DC90: beq         $v0, $zero, L_8003DD68
    if (ctx->r2 == 0) {
        // 0x8003DC94: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8003DD68;
    }
    // 0x8003DC94: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003DC98: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8003DC9C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8003DCA0: addu        $at, $at, $v0
    gpr jr_addend_8003DCA8 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003DCA4: lw          $v0, 0x40A0($at)
    ctx->r2 = ADD32(ctx->r1, 0X40A0);
    // 0x8003DCA8: jr          $v0
    // 0x8003DCAC: nop

    switch (jr_addend_8003DCA8 >> 2) {
        case 0: goto L_8003DCB0; break;
        case 1: goto L_8003DD68; break;
        case 2: goto L_8003DD68; break;
        case 3: goto L_8003DD68; break;
        case 4: goto L_8003DD68; break;
        case 5: goto L_8003DCCC; break;
        case 6: goto L_8003DD68; break;
        case 7: goto L_8003DD68; break;
        case 8: goto L_8003DD68; break;
        case 9: goto L_8003DD68; break;
        case 10: goto L_8003DCE8; break;
        case 11: goto L_8003DD68; break;
        case 12: goto L_8003DD68; break;
        case 13: goto L_8003DD68; break;
        case 14: goto L_8003DD68; break;
        case 15: goto L_8003DD18; break;
        case 16: goto L_8003DD68; break;
        case 17: goto L_8003DD68; break;
        case 18: goto L_8003DD68; break;
        case 19: goto L_8003DD34; break;
        default: switch_error(__func__, 0x8003DCA8, 0x800940A0);
    }
    // 0x8003DCAC: nop

L_8003DCB0:
    // 0x8003DCB0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003DCB4: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x8003DCB8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8003DCBC: lw          $a0, -0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X307C);
    // 0x8003DCC0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003DCC4: j           L_8003DD00
    // 0x8003DCC8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_8003DD00;
    // 0x8003DCC8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8003DCCC:
    // 0x8003DCCC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003DCD0: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x8003DCD4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8003DCD8: lw          $a0, -0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X307C);
    // 0x8003DCDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003DCE0: j           L_8003DD00
    // 0x8003DCE4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
        goto L_8003DD00;
    // 0x8003DCE4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_8003DCE8:
    // 0x8003DCE8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003DCEC: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x8003DCF0: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8003DCF4: lw          $a0, -0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X307C);
    // 0x8003DCF8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003DCFC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_8003DD00:
    // 0x8003DD00: sllv        $v1, $v1, $v0
    ctx->r3 = S32(ctx->r3 << (ctx->r2 & 31));
    // 0x8003DD04: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8003DD08: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8003DD0C: sw          $a0, -0x307C($at)
    MEM_W(-0X307C, ctx->r1) = ctx->r4;
    // 0x8003DD10: j           L_8003DD68
    // 0x8003DD14: nop

        goto L_8003DD68;
    // 0x8003DD14: nop

L_8003DD18:
    // 0x8003DD18: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8003DD1C: lhu         $a0, -0x6DF0($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X6DF0);
    // 0x8003DD20: sltiu       $v0, $a0, 0x2
    ctx->r2 = ctx->r4 < 0X2 ? 1 : 0;
    // 0x8003DD24: bnel        $v0, $zero, L_8003DD4C
    if (ctx->r2 != 0) {
        // 0x8003DD28: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8003DD4C;
    }
    goto skip_0;
    // 0x8003DD28: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    skip_0:
    // 0x8003DD2C: j           L_8003DD4C
    // 0x8003DD30: addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
        goto L_8003DD4C;
    // 0x8003DD30: addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
L_8003DD34:
    // 0x8003DD34: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8003DD38: lhu         $a0, -0x6DF0($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X6DF0);
    // 0x8003DD3C: sltiu       $v0, $a0, 0x2
    ctx->r2 = ctx->r4 < 0X2 ? 1 : 0;
    // 0x8003DD40: bnel        $v0, $zero, L_8003DD4C
    if (ctx->r2 != 0) {
        // 0x8003DD44: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_8003DD4C;
    }
    goto skip_1;
    // 0x8003DD44: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    skip_1:
    // 0x8003DD48: addiu       $a0, $a0, 0xB
    ctx->r4 = ADD32(ctx->r4, 0XB);
L_8003DD4C:
    // 0x8003DD4C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8003DD50: lw          $v1, -0x307C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X307C);
    // 0x8003DD54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003DD58: sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2 << (ctx->r4 & 31));
    // 0x8003DD5C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8003DD60: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8003DD64: sw          $v1, -0x307C($at)
    MEM_W(-0X307C, ctx->r1) = ctx->r3;
L_8003DD68:
    // 0x8003DD68: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8003DD6C: lw          $v0, -0x307C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X307C);
    // 0x8003DD70: beq         $v0, $zero, L_8003DDA8
    if (ctx->r2 == 0) {
        // 0x8003DD74: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8003DDA8;
    }
    // 0x8003DD74: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003DD78: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003DD7C: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x8003DD80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003DD84: sh          $v0, 0x538($at)
    MEM_H(0X538, ctx->r1) = ctx->r2;
    // 0x8003DD88: jal         0x80027338
    // 0x8003DD8C: nop

    func_80027338(rdram, ctx);
        goto after_0;
    // 0x8003DD8C: nop

    after_0:
    // 0x8003DD90: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8003DD94: sh          $v0, 0x2560($at)
    MEM_H(0X2560, ctx->r1) = ctx->r2;
    // 0x8003DD98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003DD9C: addiu       $v1, $zero, 0x63
    ctx->r3 = ADD32(0, 0X63);
    // 0x8003DDA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003DDA4: sh          $v1, 0x4E66($at)
    MEM_H(0X4E66, ctx->r1) = ctx->r3;
L_8003DDA8:
    // 0x8003DDA8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003DDAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DDB0: jr          $ra
    // 0x8003DDB4: nop

    return;
    // 0x8003DDB4: nop

;}
RECOMP_FUNC void func_8003DDB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DDB8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8003DDBC: lh          $a0, 0x118($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X118);
    // 0x8003DDC0: slti        $v0, $a0, 0xB
    ctx->r2 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
    // 0x8003DDC4: bne         $v0, $zero, L_8003DDF4
    if (ctx->r2 != 0) {
        // 0x8003DDC8: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8003DDF4;
    }
    // 0x8003DDC8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8003DDCC: slti        $v0, $a0, 0x1F
    ctx->r2 = SIGNED(ctx->r4) < 0X1F ? 1 : 0;
    // 0x8003DDD0: bne         $v0, $zero, L_8003DDF4
    if (ctx->r2 != 0) {
        // 0x8003DDD4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8003DDF4;
    }
    // 0x8003DDD4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003DDD8: slti        $v0, $a0, 0x33
    ctx->r2 = SIGNED(ctx->r4) < 0X33 ? 1 : 0;
    // 0x8003DDDC: bne         $v0, $zero, L_8003DDF4
    if (ctx->r2 != 0) {
        // 0x8003DDE0: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8003DDF4;
    }
    // 0x8003DDE0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8003DDE4: slti        $v0, $a0, 0x47
    ctx->r2 = SIGNED(ctx->r4) < 0X47 ? 1 : 0;
    // 0x8003DDE8: bne         $v0, $zero, L_8003DDF4
    if (ctx->r2 != 0) {
        // 0x8003DDEC: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_8003DDF4;
    }
    // 0x8003DDEC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8003DDF0: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_8003DDF4:
    // 0x8003DDF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003DDF8: sh          $v1, 0x5650($at)
    MEM_H(0X5650, ctx->r1) = ctx->r3;
    // 0x8003DDFC: jr          $ra
    // 0x8003DE00: nop

    return;
    // 0x8003DE00: nop

;}
RECOMP_FUNC void func_8003DE04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DE04: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003DE08: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003DE0C: lw          $v0, 0x94($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X94);
    // 0x8003DE10: lhu         $v0, 0x10($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X10);
    // 0x8003DE14: beq         $v0, $zero, L_8003DE38
    if (ctx->r2 == 0) {
        // 0x8003DE18: nop
    
            goto L_8003DE38;
    }
    // 0x8003DE18: nop

    // 0x8003DE1C: lw          $a0, 0x5C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X5C);
    // 0x8003DE20: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003DE24: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
    // 0x8003DE28: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003DE2C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003DE30: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003DE34: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
L_8003DE38:
    // 0x8003DE38: jr          $ra
    // 0x8003DE3C: nop

    return;
    // 0x8003DE3C: nop

;}
RECOMP_FUNC void func_8003DE40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DE40: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003DE44: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_8003DE40 falls into func_8003DE48
    func_8003DE48(rdram, ctx);
;}
RECOMP_FUNC void func_8003DE48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DE48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DE4C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003DE50: lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X90);
    // 0x8003DE54: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x8003DE58: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003DE5C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003DE60: lw          $a0, 0x94($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X94);
    // 0x8003DE64: jal         0x8003CB7C
    // 0x8003DE68: nop

    func_8003CB7C(rdram, ctx);
        goto after_0;
    // 0x8003DE68: nop

    after_0:
    // 0x8003DE6C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8003DE70: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x8003DE74: jal         0x80024764
    // 0x8003DE78: nop

    func_80024764(rdram, ctx);
        goto after_1;
    // 0x8003DE78: nop

    after_1:
    // 0x8003DE7C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003DE80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DE84: jr          $ra
    // 0x8003DE88: nop

    return;
    // 0x8003DE88: nop

;}
RECOMP_FUNC void func_8003DE8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DE8C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003DE90: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003DE94: lw          $v1, 0x94($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X94);
    // 0x8003DE98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003DE9C: jr          $ra
    // 0x8003DEA0: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
    return;
    // 0x8003DEA0: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_8003DEA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DEA4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003DEA8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003DEAC: lw          $v0, 0x94($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X94);
    // 0x8003DEB0: jr          $ra
    // 0x8003DEB4: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    return;
    // 0x8003DEB4: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x8003DEB8: nop

    // 0x8003DEBC: nop

;}
RECOMP_FUNC void func_8003DEC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DEC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003DEC4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003DEC8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8003DECC: lhu         $s1, 0x3A6($s1)
    ctx->r17 = MEM_HU(ctx->r17, 0X3A6);
    // 0x8003DED0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003DED4: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x8003DED8: lw          $s2, 0x31C0($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X31C0);
    // 0x8003DEDC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003DEE0: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8003DEE4: addiu       $s0, $s0, 0x4AB0
    ctx->r16 = ADD32(ctx->r16, 0X4AB0);
    // 0x8003DEE8: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x8003DEEC: beq         $v0, $zero, L_8003DF1C
    if (ctx->r2 == 0) {
        // 0x8003DEF0: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8003DF1C;
    }
    // 0x8003DEF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003DEF4: sltiu       $v0, $v0, 0xD
    ctx->r2 = ctx->r2 < 0XD ? 1 : 0;
    // 0x8003DEF8: beql        $v0, $zero, L_8003DF00
    if (ctx->r2 == 0) {
        // 0x8003DEFC: addiu       $s1, $zero, 0xC
        ctx->r17 = ADD32(0, 0XC);
            goto L_8003DF00;
    }
    goto skip_0;
    // 0x8003DEFC: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    skip_0:
L_8003DF00:
    // 0x8003DF00: jal         0x8003DF40
    // 0x8003DF04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003DF40(rdram, ctx);
        goto after_0;
    // 0x8003DF04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8003DF08: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x8003DF0C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8003DF10: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003DF14: bne         $v0, $zero, L_8003DF00
    if (ctx->r2 != 0) {
        // 0x8003DF18: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_8003DF00;
    }
    // 0x8003DF18: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
L_8003DF1C:
    // 0x8003DF1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003DF20: sw          $s2, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r18;
    // 0x8003DF24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DF28: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003DF2C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003DF30: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003DF34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003DF38: jr          $ra
    // 0x8003DF3C: nop

    return;
    // 0x8003DF3C: nop

;}
RECOMP_FUNC void func_8003DF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DF40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DF44: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003DF48: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003DF4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DF50: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003DF54: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003DF58: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x8003DF5C: jal         0x80023470
    // 0x8003DF60: nop

    func_80023470(rdram, ctx);
        goto after_0;
    // 0x8003DF60: nop

    after_0:
    // 0x8003DF64: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x8003DF68: beq         $v0, $zero, L_8003DFD4
    if (ctx->r2 == 0) {
        // 0x8003DF6C: nop
    
            goto L_8003DFD4;
    }
    // 0x8003DF6C: nop

    // 0x8003DF70: lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6);
    // 0x8003DF74: sltiu       $v0, $a0, 0x11
    ctx->r2 = ctx->r4 < 0X11 ? 1 : 0;
    // 0x8003DF78: beq         $v0, $zero, L_8003DFBC
    if (ctx->r2 == 0) {
        // 0x8003DF7C: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_8003DFBC;
    }
    // 0x8003DF7C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8003DF80: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x8003DF84: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x8003DF88: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003DF8C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8003DF90: beq         $v1, $zero, L_8003DFD4
    if (ctx->r3 == 0) {
        // 0x8003DF94: nop
    
            goto L_8003DFD4;
    }
    // 0x8003DF94: nop

    // 0x8003DF98: jalr        $v1
    // 0x8003DF9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_1;
    // 0x8003DF9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003DFA0: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x8003DFA4: beq         $v0, $zero, L_8003DFD4
    if (ctx->r2 == 0) {
        // 0x8003DFA8: nop
    
            goto L_8003DFD4;
    }
    // 0x8003DFA8: nop

    // 0x8003DFAC: lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6);
    // 0x8003DFB0: sltiu       $v0, $a0, 0x11
    ctx->r2 = ctx->r4 < 0X11 ? 1 : 0;
    // 0x8003DFB4: bne         $v0, $zero, L_8003DFCC
    if (ctx->r2 != 0) {
        // 0x8003DFB8: nop
    
            goto L_8003DFCC;
    }
    // 0x8003DFB8: nop

L_8003DFBC:
    // 0x8003DFBC: jal         0x80040F70
    // 0x8003DFC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80040F70(rdram, ctx);
        goto after_2;
    // 0x8003DFC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8003DFC4: j           L_8003DFD4
    // 0x8003DFC8: nop

        goto L_8003DFD4;
    // 0x8003DFC8: nop

L_8003DFCC:
    // 0x8003DFCC: jal         0x80040EEC
    // 0x8003DFD0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80040EEC(rdram, ctx);
        goto after_3;
    // 0x8003DFD0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
L_8003DFD4:
    // 0x8003DFD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DFD8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003DFDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DFE0: jr          $ra
    // 0x8003DFE4: nop

    return;
    // 0x8003DFE4: nop

;}
RECOMP_FUNC void func_8003DFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DFE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003DFEC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003DFF0: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8003DFF4: addiu       $s0, $s0, 0x4AB0
    ctx->r16 = ADD32(ctx->r16, 0X4AB0);
    // 0x8003DFF8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003DFFC: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x8003E000: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_8003E004:
    // 0x8003E004: jal         0x8003E2C4
    // 0x8003E008: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003E2C4(rdram, ctx);
        goto after_0;
    // 0x8003E008: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8003E00C: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x8003E010: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8003E014: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003E018: bne         $v0, $zero, L_8003E004
    if (ctx->r2 != 0) {
        // 0x8003E01C: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_8003E004;
    }
    // 0x8003E01C: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x8003E020: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003E024: sh          $zero, 0x3A6($at)
    MEM_H(0X3A6, ctx->r1) = 0;
    // 0x8003E028: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8003E02C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003E030: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003E034: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003E038: jr          $ra
    // 0x8003E03C: nop

    return;
    // 0x8003E03C: nop

;}
RECOMP_FUNC void func_8003E040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E044: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003E048: jal         0x8003DFE8
    // 0x8003E04C: nop

    func_8003DFE8(rdram, ctx);
        goto after_0;
    // 0x8003E04C: nop

    after_0:
    // 0x8003E050: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003E054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E058: jr          $ra
    // 0x8003E05C: nop

    return;
    // 0x8003E05C: nop

;}
RECOMP_FUNC void func_8003E060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E060: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003E064: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8003E068: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8003E06C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8003E070: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8003E074: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003E078: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003E07C: jal         0x8003DFE8
    // 0x8003E080: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8003DFE8(rdram, ctx);
        goto after_0;
    // 0x8003E080: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8003E084: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8003E088: addiu       $a0, $a0, -0x77C0
    ctx->r4 = ADD32(ctx->r4, -0X77C0);
    // 0x8003E08C: jal         0x8003DBCC
    // 0x8003E090: nop

    func_8003DBCC(rdram, ctx);
        goto after_1;
    // 0x8003E090: nop

    after_1:
    // 0x8003E094: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8003E098: lhu         $s4, 0x0($s2)
    ctx->r20 = MEM_HU(ctx->r18, 0X0);
    // 0x8003E09C: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
    // 0x8003E0A0: bne         $v0, $zero, L_8003E0B8
    if (ctx->r2 != 0) {
        // 0x8003E0A4: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_8003E0B8;
    }
    // 0x8003E0A4: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8003E0A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003E0AC: sh          $zero, 0x3A6($at)
    MEM_H(0X3A6, ctx->r1) = 0;
    // 0x8003E0B0: j           L_8003E214
    // 0x8003E0B4: nop

        goto L_8003E214;
    // 0x8003E0B4: nop

L_8003E0B8:
    // 0x8003E0B8: sltiu       $v0, $v0, 0xD
    ctx->r2 = ctx->r2 < 0XD ? 1 : 0;
    // 0x8003E0BC: beql        $v0, $zero, L_8003E0C4
    if (ctx->r2 == 0) {
        // 0x8003E0C0: addiu       $s4, $zero, 0xC
        ctx->r20 = ADD32(0, 0XC);
            goto L_8003E0C4;
    }
    goto skip_0;
    // 0x8003E0C0: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    skip_0:
L_8003E0C4:
    // 0x8003E0C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003E0C8: sh          $s4, 0x3A6($at)
    MEM_H(0X3A6, ctx->r1) = ctx->r20;
    // 0x8003E0CC: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x8003E0D0: addiu       $s3, $s3, 0x4AB0
    ctx->r19 = ADD32(ctx->r19, 0X4AB0);
    // 0x8003E0D4: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x8003E0D8: addiu       $s5, $s5, 0x31DC
    ctx->r21 = ADD32(ctx->r21, 0X31DC);
    // 0x8003E0DC: addiu       $s1, $s3, 0x34
    ctx->r17 = ADD32(ctx->r19, 0X34);
L_8003E0E0:
    // 0x8003E0E0: jal         0x800306EC
    // 0x8003E0E4: nop

    func_800306EC(rdram, ctx);
        goto after_2;
    // 0x8003E0E4: nop

    after_2:
    // 0x8003E0E8: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x8003E0EC: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x8003E0F0: sll         $s0, $v1, 2
    ctx->r16 = S32(ctx->r3 << 2);
    // 0x8003E0F4: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x8003E0F8: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8003E0FC: sh          $v1, -0x30($s1)
    MEM_H(-0X30, ctx->r17) = ctx->r3;
    // 0x8003E100: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8003E104: addiu       $v1, $v1, -0x5638
    ctx->r3 = ADD32(ctx->r3, -0X5638);
    // 0x8003E108: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x8003E10C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E110: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x8003E114: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8003E118: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8003E11C: sh          $zero, -0x2C($s1)
    MEM_H(-0X2C, ctx->r17) = 0;
    // 0x8003E120: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x8003E124: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8003E128: sh          $v1, -0x2E($s1)
    MEM_H(-0X2E, ctx->r17) = ctx->r3;
    // 0x8003E12C: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x8003E130: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8003E134: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x8003E138: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x8003E13C: addiu       $a0, $zero, 0x745
    ctx->r4 = ADD32(0, 0X745);
    // 0x8003E140: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x8003E144: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x8003E148: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8003E14C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003E150: addiu       $v1, $v1, 0xF23
    ctx->r3 = ADD32(ctx->r3, 0XF23);
    // 0x8003E154: jal         0x80023E44
    // 0x8003E158: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_3;
    // 0x8003E158: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    after_3:
    // 0x8003E15C: sw          $v0, -0x1C($s5)
    MEM_W(-0X1C, ctx->r21) = ctx->r2;
    // 0x8003E160: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8003E164: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003E168: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003E16C: sw          $s3, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->r19;
    // 0x8003E170: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003E174: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003E178: lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X14);
    // 0x8003E17C: sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
    // 0x8003E180: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8003E184: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x8003E188: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8003E18C: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x8003E190: lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X22);
    // 0x8003E194: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8003E198: sh          $v0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r2;
    // 0x8003E19C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8003E1A0: sw          $v0, -0x14($s1)
    MEM_W(-0X14, ctx->r17) = ctx->r2;
    // 0x8003E1A4: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8003E1A8: sw          $v0, -0x10($s1)
    MEM_W(-0X10, ctx->r17) = ctx->r2;
    // 0x8003E1AC: lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X10);
    // 0x8003E1B0: sh          $v0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r2;
    // 0x8003E1B4: lhu         $v0, -0x30($s1)
    ctx->r2 = MEM_HU(ctx->r17, -0X30);
    // 0x8003E1B8: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8003E1BC: lhu         $v1, 0x12($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X12);
    // 0x8003E1C0: addiu       $v0, $v0, -0x54
    ctx->r2 = ADD32(ctx->r2, -0X54);
    // 0x8003E1C4: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8003E1C8: beq         $v0, $zero, L_8003E1FC
    if (ctx->r2 == 0) {
        // 0x8003E1CC: sh          $v1, -0x20($s1)
        MEM_H(-0X20, ctx->r17) = ctx->r3;
            goto L_8003E1FC;
    }
    // 0x8003E1CC: sh          $v1, -0x20($s1)
    MEM_H(-0X20, ctx->r17) = ctx->r3;
    // 0x8003E1D0: jal         0x8000EB98
    // 0x8003E1D4: nop

    func_8000EB98(rdram, ctx);
        goto after_4;
    // 0x8003E1D4: nop

    after_4:
    // 0x8003E1D8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8003E1DC: beq         $a0, $zero, L_8003E1FC
    if (ctx->r4 == 0) {
        // 0x8003E1E0: sw          $a0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r4;
            goto L_8003E1FC;
    }
    // 0x8003E1E0: sw          $a0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r4;
    // 0x8003E1E4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003E1E8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003E1EC: lhu         $a0, 0x4($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X4);
    // 0x8003E1F0: lhu         $v1, 0x14($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X14);
    // 0x8003E1F4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8003E1F8: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
L_8003E1FC:
    // 0x8003E1FC: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x8003E200: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // 0x8003E204: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x8003E208: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003E20C: bne         $v0, $zero, L_8003E0E0
    if (ctx->r2 != 0) {
        // 0x8003E210: addiu       $s3, $s3, 0x40
        ctx->r19 = ADD32(ctx->r19, 0X40);
            goto L_8003E0E0;
    }
    // 0x8003E210: addiu       $s3, $s3, 0x40
    ctx->r19 = ADD32(ctx->r19, 0X40);
L_8003E214:
    // 0x8003E214: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8003E218: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8003E21C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8003E220: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E224: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003E228: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003E22C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003E230: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003E234: jr          $ra
    // 0x8003E238: nop

    return;
    // 0x8003E238: nop

;}
RECOMP_FUNC void func_8003E23C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E23C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003E240: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003E244: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8003E248: lhu         $s1, 0x3A6($s1)
    ctx->r17 = MEM_HU(ctx->r17, 0X3A6);
    // 0x8003E24C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8003E250: beq         $s1, $zero, L_8003E2A4
    if (ctx->r17 == 0) {
        // 0x8003E254: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8003E2A4;
    }
    // 0x8003E254: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003E258: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8003E25C: addiu       $s0, $s0, 0x4AB0
    ctx->r16 = ADD32(ctx->r16, 0X4AB0);
L_8003E260:
    // 0x8003E260: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x8003E264: beq         $a0, $zero, L_8003E274
    if (ctx->r4 == 0) {
        // 0x8003E268: nop
    
            goto L_8003E274;
    }
    // 0x8003E268: nop

    // 0x8003E26C: jal         0x80024764
    // 0x8003E270: nop

    func_80024764(rdram, ctx);
        goto after_0;
    // 0x8003E270: nop

    after_0:
L_8003E274:
    // 0x8003E274: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8003E278: beq         $a0, $zero, L_8003E288
    if (ctx->r4 == 0) {
        // 0x8003E27C: nop
    
            goto L_8003E288;
    }
    // 0x8003E27C: nop

    // 0x8003E280: jal         0x80024764
    // 0x8003E284: nop

    func_80024764(rdram, ctx);
        goto after_1;
    // 0x8003E284: nop

    after_1:
L_8003E288:
    // 0x8003E288: jal         0x8003E2C4
    // 0x8003E28C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003E2C4(rdram, ctx);
        goto after_2;
    // 0x8003E28C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8003E290: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x8003E294: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8003E298: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003E29C: bne         $v0, $zero, L_8003E260
    if (ctx->r2 != 0) {
        // 0x8003E2A0: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_8003E260;
    }
    // 0x8003E2A0: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
L_8003E2A4:
    // 0x8003E2A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003E2A8: sh          $s1, 0x3A6($at)
    MEM_H(0X3A6, ctx->r1) = ctx->r17;
    // 0x8003E2AC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8003E2B0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003E2B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003E2B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003E2BC: jr          $ra
    // 0x8003E2C0: nop

    return;
    // 0x8003E2C0: nop

;}
RECOMP_FUNC void func_8003E2C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E2C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E2C8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003E2CC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8003E2D0: jal         0x8007DEC0
    // 0x8003E2D4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8007DEC0(rdram, ctx);
        goto after_0;
    // 0x8003E2D4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
    // 0x8003E2D8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003E2DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E2E0: jr          $ra
    // 0x8003E2E4: nop

    return;
    // 0x8003E2E4: nop

;}
RECOMP_FUNC void func_8003E2E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E2E8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8003E2EC: lhu         $t1, 0x3A6($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X3A6);
    // FALLTHROUGH: func_8003E2E8 falls into func_8003E2F0
    func_8003E2F0(rdram, ctx);
;}
RECOMP_FUNC void func_8003E2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E2F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003E2F4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8003E2F8: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x8003E2FC: lw          $s2, 0x31C0($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X31C0);
    // 0x8003E300: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8003E304: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8003E308: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8003E30C: addiu       $a1, $a1, 0x4AB0
    ctx->r5 = ADD32(ctx->r5, 0X4AB0);
    // 0x8003E310: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8003E314: beq         $t1, $zero, L_8003E49C
    if (ctx->r9 == 0) {
        // 0x8003E318: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_8003E49C;
    }
    // 0x8003E318: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003E31C: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    // 0x8003E320: lh          $t2, 0x14($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X14);
    // 0x8003E324: addiu       $s0, $a1, 0x28
    ctx->r16 = ADD32(ctx->r5, 0X28);
    // 0x8003E328: addu        $t0, $t2, $zero
    ctx->r8 = ADD32(ctx->r10, 0);
L_8003E32C:
    // 0x8003E32C: lw          $a3, 0x0($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X0);
    // 0x8003E330: lhu         $v0, 0x6C($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X6C);
    // 0x8003E334: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8003E338: bnel        $v0, $zero, L_8003E488
    if (ctx->r2 != 0) {
        // 0x8003E33C: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_8003E488;
    }
    goto skip_0;
    // 0x8003E33C: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    skip_0:
    // 0x8003E340: lhu         $v0, -0x16($s0)
    ctx->r2 = MEM_HU(ctx->r16, -0X16);
    // 0x8003E344: bnel        $v0, $zero, L_8003E488
    if (ctx->r2 != 0) {
        // 0x8003E348: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_8003E488;
    }
    goto skip_1;
    // 0x8003E348: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    skip_1:
    // 0x8003E34C: lhu         $v1, -0x24($s0)
    ctx->r3 = MEM_HU(ctx->r16, -0X24);
    // 0x8003E350: addiu       $v0, $v1, -0x54
    ctx->r2 = ADD32(ctx->r3, -0X54);
    // 0x8003E354: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8003E358: bnel        $v0, $zero, L_8003E488
    if (ctx->r2 != 0) {
        // 0x8003E35C: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_8003E488;
    }
    goto skip_2;
    // 0x8003E35C: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    skip_2:
    // 0x8003E360: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x8003E364: xori        $v1, $v0, 0x56
    ctx->r3 = ctx->r2 ^ 0X56;
    // 0x8003E368: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8003E36C: xori        $v0, $v0, 0x8E
    ctx->r2 = ctx->r2 ^ 0X8E;
    // 0x8003E370: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8003E374: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8003E378: beql        $v1, $zero, L_8003E488
    if (ctx->r3 == 0) {
        // 0x8003E37C: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_8003E488;
    }
    goto skip_3;
    // 0x8003E37C: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    skip_3:
    // 0x8003E380: lh          $a0, -0x22($s0)
    ctx->r4 = MEM_H(ctx->r16, -0X22);
    // 0x8003E384: sltu        $v1, $zero, $a0
    ctx->r3 = 0 < ctx->r4 ? 1 : 0;
    // 0x8003E388: xori        $v0, $a0, 0xB
    ctx->r2 = ctx->r4 ^ 0XB;
    // 0x8003E38C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8003E390: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8003E394: beq         $v1, $zero, L_8003E484
    if (ctx->r3 == 0) {
        // 0x8003E398: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_8003E484;
    }
    // 0x8003E398: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8003E39C: xori        $v1, $a0, 0xE
    ctx->r3 = ctx->r4 ^ 0XE;
    // 0x8003E3A0: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8003E3A4: xori        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 ^ 0X1;
    // 0x8003E3A8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8003E3AC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8003E3B0: beq         $v1, $zero, L_8003E484
    if (ctx->r3 == 0) {
        // 0x8003E3B4: addiu       $v0, $a2, -0x5
        ctx->r2 = ADD32(ctx->r6, -0X5);
            goto L_8003E484;
    }
    // 0x8003E3B4: addiu       $v0, $a2, -0x5
    ctx->r2 = ADD32(ctx->r6, -0X5);
    // 0x8003E3B8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003E3BC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8003E3C0: bnel        $v0, $zero, L_8003E488
    if (ctx->r2 != 0) {
        // 0x8003E3C4: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_8003E488;
    }
    goto skip_4;
    // 0x8003E3C4: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    skip_4:
    // 0x8003E3C8: xori        $v1, $a0, 0x7
    ctx->r3 = ctx->r4 ^ 0X7;
    // 0x8003E3CC: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8003E3D0: xori        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 ^ 0X3;
    // 0x8003E3D4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8003E3D8: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8003E3DC: beql        $v1, $zero, L_8003E488
    if (ctx->r3 == 0) {
        // 0x8003E3E0: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_8003E488;
    }
    goto skip_5;
    // 0x8003E3E0: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    skip_5:
    // 0x8003E3E4: lh          $v0, 0x14($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X14);
    // 0x8003E3E8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8003E3EC: subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x8003E3F0: bltzl       $v0, L_8003E3FC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8003E3F4: subu        $v1, $t0, $v1
        ctx->r3 = SUB32(ctx->r8, ctx->r3);
            goto L_8003E3FC;
    }
    goto skip_6;
    // 0x8003E3F4: subu        $v1, $t0, $v1
    ctx->r3 = SUB32(ctx->r8, ctx->r3);
    skip_6:
    // 0x8003E3F8: subu        $v1, $v1, $t0
    ctx->r3 = SUB32(ctx->r3, ctx->r8);
L_8003E3FC:
    // 0x8003E3FC: lhu         $v0, 0x32($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X32);
    // 0x8003E400: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8003E404: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003E408: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003E40C: sra         $v0, $v0, 17
    ctx->r2 = S32(SIGNED(ctx->r2) >> 17);
    // 0x8003E410: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8003E414: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003E418: bnel        $v0, $zero, L_8003E488
    if (ctx->r2 != 0) {
        // 0x8003E41C: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_8003E488;
    }
    goto skip_7;
    // 0x8003E41C: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    skip_7:
    // 0x8003E420: lh          $v1, -0x22($s0)
    ctx->r3 = MEM_H(ctx->r16, -0X22);
    // 0x8003E424: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8003E428: beq         $v1, $v0, L_8003E44C
    if (ctx->r3 == ctx->r2) {
        // 0x8003E42C: addiu       $v0, $zero, 0xE2
        ctx->r2 = ADD32(0, 0XE2);
            goto L_8003E44C;
    }
    // 0x8003E42C: addiu       $v0, $zero, 0xE2
    ctx->r2 = ADD32(0, 0XE2);
    // 0x8003E430: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8003E434: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003E438: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x8003E43C: jal         0x80040EEC
    // 0x8003E440: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_80040EEC(rdram, ctx);
        goto after_0;
    // 0x8003E440: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x8003E444: j           L_8003E49C
    // 0x8003E448: nop

        goto L_8003E49C;
    // 0x8003E448: nop

L_8003E44C:
    // 0x8003E44C: lh          $v1, 0x18($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X18);
    // 0x8003E450: bne         $v1, $v0, L_8003E49C
    if (ctx->r3 != ctx->r2) {
        // 0x8003E454: addiu       $a0, $zero, 0x28
        ctx->r4 = ADD32(0, 0X28);
            goto L_8003E49C;
    }
    // 0x8003E454: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8003E458: jal         0x8003C34C
    // 0x8003E45C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8003C34C(rdram, ctx);
        goto after_1;
    // 0x8003E45C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8003E460: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8003E464: jal         0x80060F30
    // 0x8003E468: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80060F30(rdram, ctx);
        goto after_2;
    // 0x8003E468: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x8003E46C: lhu         $v0, 0x24($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X24);
    // 0x8003E470: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003E474: sh          $v0, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r2;
    // 0x8003E478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003E47C: j           L_8003E49C
    // 0x8003E480: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_8003E49C;
    // 0x8003E480: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_8003E484:
    // 0x8003E484: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
L_8003E488:
    // 0x8003E488: addiu       $v0, $t1, -0x1
    ctx->r2 = ADD32(ctx->r9, -0X1);
    // 0x8003E48C: addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // 0x8003E490: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003E494: bne         $v0, $zero, L_8003E32C
    if (ctx->r2 != 0) {
        // 0x8003E498: addiu       $a1, $a1, 0x40
        ctx->r5 = ADD32(ctx->r5, 0X40);
            goto L_8003E32C;
    }
    // 0x8003E498: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
L_8003E49C:
    // 0x8003E49C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003E4A0: sw          $s2, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r18;
    // 0x8003E4A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8003E4A8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8003E4AC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8003E4B0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003E4B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8003E4B8: jr          $ra
    // 0x8003E4BC: nop

    return;
    // 0x8003E4BC: nop

;}
RECOMP_FUNC void func_8003E4C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E4C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003E4C4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003E4C8: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8003E4CC: addiu       $s0, $s0, 0x31C0
    ctx->r16 = ADD32(ctx->r16, 0X31C0);
    // 0x8003E4D0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8003E4D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003E4D8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8003E4DC: jal         0x8003E500
    // 0x8003E4E0: nop

    func_8003E500(rdram, ctx);
        goto after_0;
    // 0x8003E4E0: nop

    after_0:
    // 0x8003E4E4: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    // 0x8003E4E8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8003E4EC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003E4F0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003E4F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003E4F8: jr          $ra
    // 0x8003E4FC: nop

    return;
    // 0x8003E4FC: nop

;}
