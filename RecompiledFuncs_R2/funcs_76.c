#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_8007B960(uint8_t* rdram, recomp_context* ctx);
void func_8007BB60(uint8_t* rdram, recomp_context* ctx);
void func_8007BD80(uint8_t* rdram, recomp_context* ctx);
void func_8007BDEC(uint8_t* rdram, recomp_context* ctx);
void func_8007C7E0(uint8_t* rdram, recomp_context* ctx);
void func_8007C938(uint8_t* rdram, recomp_context* ctx);
void func_8007CAA0(uint8_t* rdram, recomp_context* ctx);
void func_8007CB90(uint8_t* rdram, recomp_context* ctx);
void func_8007CC24(uint8_t* rdram, recomp_context* ctx);
void func_8007CDB0(uint8_t* rdram, recomp_context* ctx);
void func_8007CEB8(uint8_t* rdram, recomp_context* ctx);
void func_8007D550(uint8_t* rdram, recomp_context* ctx);
void func_8007D5E8(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_8007939C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007939C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800793A0: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800793A4: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x800793A8: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x800793AC: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x800793B0: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x800793B4: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800793B8: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x800793BC: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x800793C0: addu        $fp, $a3, $zero
    ctx->r30 = ADD32(ctx->r7, 0);
    // 0x800793C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800793C8: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800793CC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800793D0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800793D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800793D8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800793DC: lw          $v1, 0x1C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X1C);
    // 0x800793E0: lw          $v0, 0x14($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X14);
    // 0x800793E4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800793E8: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x800793EC: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800793F0: beq         $v0, $zero, L_800793FC
    if (ctx->r2 == 0) {
        // 0x800793F4: addu        $a2, $s5, $zero
        ctx->r6 = ADD32(ctx->r21, 0);
            goto L_800793FC;
    }
    // 0x800793F4: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x800793F8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_800793FC:
    // 0x800793FC: sll         $a3, $fp, 1
    ctx->r7 = S32(ctx->r30 << 1);
    // 0x80079400: addu        $s1, $a0, $a3
    ctx->r17 = ADD32(ctx->r4, ctx->r7);
    // 0x80079404: sltu        $v0, $a1, $s1
    ctx->r2 = ctx->r5 < ctx->r17 ? 1 : 0;
    // 0x80079408: beq         $v0, $zero, L_8007948C
    if (ctx->r2 == 0) {
        // 0x8007940C: andi        $v0, $s6, 0xFFFF
        ctx->r2 = ctx->r22 & 0XFFFF;
            goto L_8007948C;
    }
    // 0x8007940C: andi        $v0, $s6, 0xFFFF
    ctx->r2 = ctx->r22 & 0XFFFF;
    // 0x80079410: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80079414: addu        $s4, $s5, $zero
    ctx->r20 = ADD32(ctx->r21, 0);
    // 0x80079418: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x8007941C: lui         $s3, 0x800
    ctx->r19 = S32(0X800 << 16);
    // 0x80079420: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x80079424: subu        $s0, $a1, $a0
    ctx->r16 = SUB32(ctx->r5, ctx->r4);
    // 0x80079428: sra         $s0, $s0, 1
    ctx->r16 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8007942C: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x80079430: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80079434: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x80079438: lui         $s2, 0x400
    ctx->r18 = S32(0X400 << 16);
    // 0x8007943C: subu        $s1, $s1, $a1
    ctx->r17 = SUB32(ctx->r17, ctx->r5);
    // 0x80079440: sra         $s1, $s1, 1
    ctx->r17 = S32(SIGNED(ctx->r17) >> 1);
    // 0x80079444: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80079448: jal         0x80070EA0
    // 0x8007944C: sw          $s2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r18;
    func_80070EA0(rdram, ctx);
        goto after_0;
    // 0x8007944C: sw          $s2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r18;
    after_0:
    // 0x80079450: addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
    // 0x80079454: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80079458: addu        $s0, $s6, $s0
    ctx->r16 = ADD32(ctx->r22, ctx->r16);
    // 0x8007945C: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80079460: or          $s0, $s0, $s3
    ctx->r16 = ctx->r16 | ctx->r19;
    // 0x80079464: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x80079468: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8007946C: sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // 0x80079470: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x80079474: addu        $s0, $s5, $zero
    ctx->r16 = ADD32(ctx->r21, 0);
    // 0x80079478: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x8007947C: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x80079480: lw          $a0, 0x14($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X14);
    // 0x80079484: j           L_800794B4
    // 0x80079488: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
        goto L_800794B4;
    // 0x80079488: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
L_8007948C:
    // 0x8007948C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80079490: addu        $s0, $s5, $zero
    ctx->r16 = ADD32(ctx->r21, 0);
    // 0x80079494: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80079498: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x8007949C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800794A0: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x800794A4: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x800794A8: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x800794AC: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x800794B0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800794B4:
    // 0x800794B4: jal         0x80070EA0
    // 0x800794B8: nop

    func_80070EA0(rdram, ctx);
        goto after_1;
    // 0x800794B8: nop

    after_1:
    // 0x800794BC: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800794C0: addiu       $v0, $s5, 0x8
    ctx->r2 = ADD32(ctx->r21, 0X8);
    // 0x800794C4: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800794C8: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x800794CC: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800794D0: sll         $v1, $fp, 1
    ctx->r3 = S32(ctx->r30 << 1);
    // 0x800794D4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800794D8: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x800794DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800794E0: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x800794E4: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800794E8: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800794EC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800794F0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800794F4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800794F8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800794FC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80079500: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80079504: jr          $ra
    // 0x80079508: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80079508: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8007950C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007950C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80079510: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80079514: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x80079518: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x8007951C: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x80079520: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80079524: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80079528: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x8007952C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80079530: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x80079534: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80079538: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8007953C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80079540: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80079544: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80079548: lw          $v1, 0x1C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X1C);
    // 0x8007954C: lw          $v0, 0x14($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X14);
    // 0x80079550: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80079554: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x80079558: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007955C: beq         $v0, $zero, L_80079568
    if (ctx->r2 == 0) {
        // 0x80079560: addu        $a2, $s5, $zero
        ctx->r6 = ADD32(ctx->r21, 0);
            goto L_80079568;
    }
    // 0x80079560: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x80079564: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_80079568:
    // 0x80079568: sll         $fp, $a3, 1
    ctx->r30 = S32(ctx->r7 << 1);
    // 0x8007956C: addu        $s0, $a0, $fp
    ctx->r16 = ADD32(ctx->r4, ctx->r30);
    // 0x80079570: sltu        $v0, $a1, $s0
    ctx->r2 = ctx->r5 < ctx->r16 ? 1 : 0;
    // 0x80079574: beq         $v0, $zero, L_80079614
    if (ctx->r2 == 0) {
        // 0x80079578: lui         $s2, 0x800
        ctx->r18 = S32(0X800 << 16);
            goto L_80079614;
    }
    // 0x80079578: lui         $s2, 0x800
    ctx->r18 = S32(0X800 << 16);
    // 0x8007957C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80079580: addu        $s4, $s5, $zero
    ctx->r20 = ADD32(ctx->r21, 0);
    // 0x80079584: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80079588: subu        $s1, $a1, $a0
    ctx->r17 = SUB32(ctx->r5, ctx->r4);
    // 0x8007958C: sra         $s1, $s1, 1
    ctx->r17 = S32(SIGNED(ctx->r17) >> 1);
    // 0x80079590: sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22 << 16);
    // 0x80079594: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x80079598: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
    // 0x8007959C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800795A0: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
    // 0x800795A4: subu        $s0, $s0, $a1
    ctx->r16 = SUB32(ctx->r16, ctx->r5);
    // 0x800795A8: sra         $s0, $s0, 1
    ctx->r16 = S32(SIGNED(ctx->r16) >> 1);
    // 0x800795AC: sw          $s2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r18;
    // 0x800795B0: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x800795B4: jal         0x80070EA0
    // 0x800795B8: sw          $s3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r19;
    func_80070EA0(rdram, ctx);
        goto after_0;
    // 0x800795B8: sw          $s3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r19;
    after_0:
    // 0x800795BC: addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
    // 0x800795C0: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800795C4: addu        $s1, $s6, $s1
    ctx->r17 = ADD32(ctx->r22, ctx->r17);
    // 0x800795C8: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x800795CC: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x800795D0: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x800795D4: or          $s1, $s1, $s0
    ctx->r17 = ctx->r17 | ctx->r16;
    // 0x800795D8: addu        $s0, $s5, $zero
    ctx->r16 = ADD32(ctx->r21, 0);
    // 0x800795DC: sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // 0x800795E0: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x800795E4: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x800795E8: sw          $s3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r19;
    // 0x800795EC: lw          $a0, 0x14($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X14);
    // 0x800795F0: jal         0x80070EA0
    // 0x800795F4: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    func_80070EA0(rdram, ctx);
        goto after_1;
    // 0x800795F4: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    after_1:
    // 0x800795F8: addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
    // 0x800795FC: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80079600: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80079604: andi        $v0, $fp, 0xFFFF
    ctx->r2 = ctx->r30 & 0XFFFF;
    // 0x80079608: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x8007960C: j           L_80079648
    // 0x80079610: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_80079648;
    // 0x80079610: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80079614:
    // 0x80079614: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80079618: addu        $s0, $s5, $zero
    ctx->r16 = ADD32(ctx->r21, 0);
    // 0x8007961C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80079620: lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
    // 0x80079624: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80079628: sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22 << 16);
    // 0x8007962C: andi        $v1, $fp, 0xFFFF
    ctx->r3 = ctx->r30 & 0XFFFF;
    // 0x80079630: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80079634: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80079638: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8007963C: jal         0x80070EA0
    // 0x80079640: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    func_80070EA0(rdram, ctx);
        goto after_2;
    // 0x80079640: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    after_2:
    // 0x80079644: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_80079648:
    // 0x80079648: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // 0x8007964C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80079650: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x80079654: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80079658: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8007965C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80079660: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80079664: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80079668: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8007966C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80079670: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80079674: jr          $ra
    // 0x80079678: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80079678: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8007967C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007967C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80079680: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80079684: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80079688: lui         $v1, 0xB00
    ctx->r3 = S32(0XB00 << 16);
    // 0x8007968C: ori         $v1, $v1, 0x20
    ctx->r3 = ctx->r3 | 0X20;
    // 0x80079690: addiu       $a0, $s1, 0x8
    ctx->r4 = ADD32(ctx->r17, 0X8);
    // 0x80079694: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80079698: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x8007969C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800796A0: lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
    // 0x800796A4: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // 0x800796A8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800796AC: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x800796B0: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x800796B4: or          $a1, $a1, $a2
    ctx->r5 = ctx->r5 | ctx->r6;
    // 0x800796B8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800796BC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800796C0: sw          $a1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r5;
    // 0x800796C4: jal         0x80070EA0
    // 0x800796C8: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    func_80070EA0(rdram, ctx);
        goto after_0;
    // 0x800796C8: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    after_0:
    // 0x800796CC: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x800796D0: lbu         $v0, 0x2F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2F);
    // 0x800796D4: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x800796D8: lui         $a0, 0xE00
    ctx->r4 = S32(0XE00 << 16);
    // 0x800796DC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800796E0: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x800796E4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800796E8: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x800796EC: jal         0x80070EA0
    // 0x800796F0: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    func_80070EA0(rdram, ctx);
        goto after_1;
    // 0x800796F0: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    after_1:
    // 0x800796F4: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800796F8: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x800796FC: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80079700: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x80079704: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80079708: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8007970C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80079710: jr          $ra
    // 0x80079714: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80079714: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80079718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079718: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8007971C: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x80079720: nop

    // 0x80079724: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80079728: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007972C: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80079730: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80079734: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80079738: ldc1        $f0, 0x2458($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X2458);
    // 0x8007973C: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80079740: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80079744: nop

    // 0x80079748: nop

    // 0x8007974C: bc1f        L_80079764
    if (!c1cs) {
        // 0x80079750: swc1        $f2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
            goto L_80079764;
    }
    // 0x80079750: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x80079754: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80079758: ldc1        $f0, 0x2460($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X2460);
    // 0x8007975C: sub.d       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f4.d - ctx->f0.d;
    // 0x80079760: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
L_80079764:
    // 0x80079764: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80079768: nop

    // 0x8007976C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80079770: mov.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.fl = ctx->f2.fl;
    // 0x80079774: nop

    // 0x80079778: bc1f        L_80079784
    if (!c1cs) {
        // 0x8007977C: swc1        $f2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
            goto L_80079784;
    }
    // 0x8007977C: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x80079780: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
L_80079784:
    // 0x80079784: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80079788: ldc1        $f0, 0x2468($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X2468);
    // 0x8007978C: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x80079790: sub.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d - ctx->f0.d;
    // 0x80079794: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80079798: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8007979C: jr          $ra
    // 0x800797A0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    return;
    // 0x800797A0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800797A4: nop

    // 0x800797A8: nop

    // 0x800797AC: nop

;}
RECOMP_FUNC void func_800797B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800797B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800797B4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800797B8: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x800797BC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800797C0: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800797C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800797C8: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x800797CC: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800797D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800797D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800797D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800797DC: lw          $s1, 0x0($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X0);
    // 0x800797E0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800797E4: bne         $s1, $zero, L_80079804
    if (ctx->r17 != 0) {
        // 0x800797E8: addu        $s4, $a3, $zero
        ctx->r20 = ADD32(ctx->r7, 0);
            goto L_80079804;
    }
    // 0x800797E8: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x800797EC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800797F0: addiu       $a0, $a0, 0x2470
    ctx->r4 = ADD32(ctx->r4, 0X2470);
    // 0x800797F4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800797F8: addiu       $a1, $a1, 0x2474
    ctx->r5 = ADD32(ctx->r5, 0X2474);
    // 0x800797FC: jal         0x80076600
    // 0x80079800: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    func_80076600(rdram, ctx);
        goto after_0;
    // 0x80079800: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    after_0:
L_80079804:
    // 0x80079804: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80079808: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007980C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80079810: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80079814: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x80079818: jalr        $v0
    // 0x8007981C: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8007981C: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_1:
    // 0x80079820: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80079824: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80079828: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007982C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80079830: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80079834: lui         $a3, 0x440
    ctx->r7 = S32(0X440 << 16);
    // 0x80079838: ori         $a3, $a3, 0x580
    ctx->r7 = ctx->r7 | 0X580;
    // 0x8007983C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80079840: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80079844: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x80079848: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x8007984C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80079850: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80079854: lui         $v0, 0xD00
    ctx->r2 = S32(0XD00 << 16);
    // 0x80079858: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8007985C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80079860: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x80079864: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80079868: sw          $a3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r7;
    // 0x8007986C: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80079870: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x80079874: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80079878: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8007987C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80079880: lw          $a0, 0x14($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X14);
    // 0x80079884: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80079888: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8007988C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80079890: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80079894: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80079898: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8007989C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800798A0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800798A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800798A8: jr          $ra
    // 0x800798AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800798AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800798B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800798B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800798B4: beq         $a1, $v0, L_800798CC
    if (ctx->r5 == ctx->r2) {
        // 0x800798B8: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_800798CC;
    }
    // 0x800798B8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800798BC: beql        $a1, $v0, L_800798D0
    if (ctx->r5 == ctx->r2) {
        // 0x800798C0: sw          $a2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r6;
            goto L_800798D0;
    }
    goto skip_0;
    // 0x800798C0: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800798C4: j           L_800798D0
    // 0x800798C8: nop

        goto L_800798D0;
    // 0x800798C8: nop

L_800798CC:
    // 0x800798CC: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_800798D0:
    // 0x800798D0: jr          $ra
    // 0x800798D4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800798D4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800798D8: nop

    // 0x800798DC: nop

;}
RECOMP_FUNC void func_800798E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800798E0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800798E4: blez        $a2, L_80079908
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800798E8: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80079908;
    }
    // 0x800798E8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800798EC:
    // 0x800798EC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800798F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800798F4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800798F8: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800798FC: slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80079900: bne         $v0, $zero, L_800798EC
    if (ctx->r2 != 0) {
        // 0x80079904: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800798EC;
    }
    // 0x80079904: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80079908:
    // 0x80079908: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8007990C: jr          $ra
    // 0x80079910: nop

    return;
    // 0x80079910: nop

    // 0x80079914: nop

    // 0x80079918: nop

    // 0x8007991C: nop

;}
RECOMP_FUNC void func_80079940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079940: lui         $v0, 0xA404
    ctx->r2 = S32(0XA404 << 16);
    // 0x80079944: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // 0x80079948: lw          $v0, 0x0($v0)
    ctx->r2 = 0; /* [R2 STUB] RCP SP_STATUS HW read -> report idle */
    // 0x8007994C: andi        $v0, $v0, 0x1C
    ctx->r2 = ctx->r2 & 0X1C;
    // 0x80079950: jr          $ra
    // 0x80079954: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x80079954: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80079958: nop

    // 0x8007995C: nop

;}
RECOMP_FUNC void func_80079960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079960: lui         $v0, 0xA404
    ctx->r2 = S32(0XA404 << 16);
    // 0x80079964: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // 0x80079968: jr          $ra
    // 0x8007996C: lw          $v0, 0x0($v0)
    ctx->r2 = 0; /* [R2 STUB] RCP SP_STATUS HW read -> report idle */
    return;
    // 0x8007996C: lw          $v0, 0x0($v0)
    ctx->r2 = 0; /* [R2 STUB] RCP SP_STATUS HW read -> report idle */
;}
RECOMP_FUNC void func_80079970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079970: lui         $v0, 0xA404
    ctx->r2 = S32(0XA404 << 16);
    // 0x80079974: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // 0x80079978: jr          $ra
    // 0x8007997C: sw          $a0, 0x0($v0)
    (void)ctx->r4; /* [R2 STUB] RCP SP_STATUS HW write skipped */
    return;
    // 0x8007997C: sw          $a0, 0x0($v0)
    (void)ctx->r4; /* [R2 STUB] RCP SP_STATUS HW write skipped */
;}
RECOMP_FUNC void func_80079980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079980: lui         $v0, 0xA404
    ctx->r2 = S32(0XA404 << 16);
    // 0x80079984: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // 0x80079988: lw          $v0, 0x0($v0)
    ctx->r2 = 0; /* [R2 STUB] RCP SP_STATUS HW read -> report idle */
    // 0x8007998C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80079990: beq         $v0, $zero, L_800799A4
    if (ctx->r2 == 0) {
        // 0x80079994: lui         $v0, 0xA408
        ctx->r2 = S32(0XA408 << 16);
            goto L_800799A4;
    }
    // 0x80079994: lui         $v0, 0xA408
    ctx->r2 = S32(0XA408 << 16);
    // 0x80079998: sw          $a0, 0x0($v0)
    (void)ctx->r4; /* [R2 STUB] RCP DP HW write skipped */
    // 0x8007999C: j           L_800799A8
    // 0x800799A0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800799A8;
    // 0x800799A0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800799A4:
    // 0x800799A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800799A8:
    // 0x800799A8: jr          $ra
    // 0x800799AC: nop

    return;
    // 0x800799AC: nop

;}
RECOMP_FUNC void func_800799B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800799B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800799B4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800799B8: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800799BC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800799C0: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800799C4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800799C8: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x800799CC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800799D0: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x800799D4: andi        $v0, $s2, 0x7
    ctx->r2 = ctx->r18 & 0X7;
    // 0x800799D8: beq         $v0, $zero, L_800799F8
    if (ctx->r2 == 0) {
        // 0x800799DC: sw          $ra, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r31;
            goto L_800799F8;
    }
    // 0x800799DC: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800799E0: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800799E4: addiu       $a0, $a0, 0x247C
    ctx->r4 = ADD32(ctx->r4, 0X247C);
    // 0x800799E8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800799EC: addiu       $a1, $a1, 0x2480
    ctx->r5 = ADD32(ctx->r5, 0X2480);
    // 0x800799F0: jal         0x80076600
    // 0x800799F4: addiu       $a2, $zero, 0x3A
    ctx->r6 = ADD32(0, 0X3A);
    func_80076600(rdram, ctx);
        goto after_0;
    // 0x800799F4: addiu       $a2, $zero, 0x3A
    ctx->r6 = ADD32(0, 0X3A);
    after_0:
L_800799F8:
    // 0x800799F8: andi        $v0, $s1, 0x7
    ctx->r2 = ctx->r17 & 0X7;
    // 0x800799FC: beq         $v0, $zero, L_80079A20
    if (ctx->r2 == 0) {
        // 0x80079A00: andi        $v0, $s0, 0x7
        ctx->r2 = ctx->r16 & 0X7;
            goto L_80079A20;
    }
    // 0x80079A00: andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
    // 0x80079A04: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80079A08: addiu       $a0, $a0, 0x247C
    ctx->r4 = ADD32(ctx->r4, 0X247C);
    // 0x80079A0C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80079A10: addiu       $a1, $a1, 0x2480
    ctx->r5 = ADD32(ctx->r5, 0X2480);
    // 0x80079A14: jal         0x80076600
    // 0x80079A18: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    func_80076600(rdram, ctx);
        goto after_1;
    // 0x80079A18: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    after_1:
    // 0x80079A1C: andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
L_80079A20:
    // 0x80079A20: beq         $v0, $zero, L_80079A40
    if (ctx->r2 == 0) {
        // 0x80079A24: nop
    
            goto L_80079A40;
    }
    // 0x80079A24: nop

    // 0x80079A28: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80079A2C: addiu       $a0, $a0, 0x247C
    ctx->r4 = ADD32(ctx->r4, 0X247C);
    // 0x80079A30: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80079A34: addiu       $a1, $a1, 0x2480
    ctx->r5 = ADD32(ctx->r5, 0X2480);
    // 0x80079A38: jal         0x80076600
    // 0x80079A3C: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_80076600(rdram, ctx);
        goto after_2;
    // 0x80079A3C: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_2:
L_80079A40:
    // 0x80079A40: jal         0x80079940
    // 0x80079A44: nop

    func_80079940(rdram, ctx);
        goto after_3;
    // 0x80079A44: nop

    after_3:
    // 0x80079A48: bne         $v0, $zero, L_80079A8C
    if (ctx->r2 != 0) {
        // 0x80079A4C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80079A8C;
    }
    // 0x80079A4C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80079A50: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80079A54: lui         $v0, 0xA404
    ctx->r2 = S32(0XA404 << 16);
    // 0x80079A58: jal         0x80070EA0
    // 0x80079A5C: sw          $s2, 0x0($v0)
    (void)ctx->r18; /* [R2 STUB] RCP SP_MEM_ADDR write skipped */
    func_80070EA0(rdram, ctx);
        goto after_4;
    // 0x80079A5C: sw          $s2, 0x0($v0)
    (void)ctx->r18; /* [R2 STUB] RCP SP_MEM_ADDR write skipped */
    after_4:
    // 0x80079A60: lui         $v1, 0xA404
    ctx->r3 = S32(0XA404 << 16);
    // 0x80079A64: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x80079A68: sw          $v0, 0x0($v1)
    (void)ctx->r2; /* [R2 STUB] RCP SP_DRAM_ADDR write skipped */
    // 0x80079A6C: bne         $s3, $zero, L_80079A7C
    if (ctx->r19 != 0) {
        // 0x80079A70: lui         $v1, 0xA404
        ctx->r3 = S32(0XA404 << 16);
            goto L_80079A7C;
    }
    // 0x80079A70: lui         $v1, 0xA404
    ctx->r3 = S32(0XA404 << 16);
    // 0x80079A74: j           L_80079A80
    // 0x80079A78: ori         $v1, $v1, 0xC
    ctx->r3 = ctx->r3 | 0XC;
        goto L_80079A80;
    // 0x80079A78: ori         $v1, $v1, 0xC
    ctx->r3 = ctx->r3 | 0XC;
L_80079A7C:
    // 0x80079A7C: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
L_80079A80:
    // 0x80079A80: addiu       $v0, $s0, -0x1
    ctx->r2 = ADD32(ctx->r16, -0X1);
    // 0x80079A84: sw          $v0, 0x0($v1)
    (void)ctx->r2; /* [R2 STUB] RCP SP_LEN (DMA kick) write skipped */
    // 0x80079A88: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80079A8C:
    // 0x80079A8C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80079A90: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80079A94: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80079A98: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80079A9C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80079AA0: jr          $ra
    // 0x80079AA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80079AA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80079AA8: nop

    // 0x80079AAC: nop

;}
RECOMP_FUNC void func_80079BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079BC0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80079BC4: jr          $ra
    // 0x80079BC8: lw          $v0, 0x25A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X25A0);
    return;
    // 0x80079BC8: lw          $v0, 0x25A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X25A0);
    // 0x80079BCC: nop

;}
RECOMP_FUNC void func_80079CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80079CD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80079CD8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80079CDC: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x80079CE0: addiu       $s0, $s0, -0x1050
    ctx->r16 = ADD32(ctx->r16, -0X1050);
    // 0x80079CE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80079CE8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80079CEC: addiu       $a1, $a1, 0x4680
    ctx->r5 = ADD32(ctx->r5, 0X4680);
    // 0x80079CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079CF4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80079CF8: sw          $v0, 0x25B0($at)
    MEM_W(0X25B0, ctx->r1) = ctx->r2;
    // 0x80079CFC: jal         0x80070490
    // 0x80079D00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80079D00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80079D04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80079D08: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80079D0C: jal         0x80070750
    // 0x80079D10: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80079D10: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x80079D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079D18: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80079D1C: jr          $ra
    // 0x80079D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80079D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80079D24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079D24: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80079D28: lw          $v0, 0x25B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X25B0);
    // FALLTHROUGH: func_80079D24 falls into func_80079D2C
    func_80079D2C(rdram, ctx);
;}
RECOMP_FUNC void func_80079D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079D2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80079D30: bne         $v0, $zero, L_80079D70
    if (ctx->r2 != 0) {
        // 0x80079D34: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80079D70;
    }
    // 0x80079D34: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80079D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80079D3C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80079D40: sw          $v0, 0x25B0($at)
    MEM_W(0X25B0, ctx->r1) = ctx->r2;
    // 0x80079D44: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80079D48: addiu       $a0, $a0, -0x1050
    ctx->r4 = ADD32(ctx->r4, -0X1050);
    // 0x80079D4C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80079D50: addiu       $a1, $a1, 0x4680
    ctx->r5 = ADD32(ctx->r5, 0X4680);
    // 0x80079D54: jal         0x80070490
    // 0x80079D58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80079D58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80079D5C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80079D60: addiu       $a0, $a0, -0x1050
    ctx->r4 = ADD32(ctx->r4, -0X1050);
    // 0x80079D64: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80079D68: jal         0x80070750
    // 0x80079D6C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80079D6C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
L_80079D70:
    // 0x80079D70: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80079D74: addiu       $a0, $a0, -0x1050
    ctx->r4 = ADD32(ctx->r4, -0X1050);
    // 0x80079D78: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80079D7C: jal         0x80070620
    // 0x80079D80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80079D80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80079D84: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80079D88: jr          $ra
    // 0x80079D8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80079D8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80079D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079D90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80079D94: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80079D98: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80079D9C: addiu       $a0, $a0, -0x1050
    ctx->r4 = ADD32(ctx->r4, -0X1050);
    // 0x80079DA0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80079DA4: jal         0x80070750
    // 0x80079DA8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80079DA8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x80079DAC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80079DB0: jr          $ra
    // 0x80079DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80079DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80079DB8: nop

    // 0x80079DBC: nop

;}
RECOMP_FUNC void func_80079F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079F30: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80079F34: lw          $v1, 0x1070($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1070);
    // 0x80079F38: beq         $v1, $zero, L_80079F48
    if (ctx->r3 == 0) {
        // 0x80079F3C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80079F48;
    }
    // 0x80079F3C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80079F40: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80079F44: lw          $v0, 0x1078($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1078);
L_80079F48:
    // 0x80079F48: jr          $ra
    // 0x80079F4C: nop

    return;
    // 0x80079F4C: nop

;}
RECOMP_FUNC void func_8007A310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A314: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007A318: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8007A31C: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8007A320: addiu       $s0, $s0, 0x4150
    ctx->r16 = ADD32(ctx->r16, 0X4150);
    // 0x8007A324: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007A328: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007A32C: addiu       $a1, $a1, 0x4690
    ctx->r5 = ADD32(ctx->r5, 0X4690);
    // 0x8007A330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A334: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8007A338: sw          $v0, 0x26B0($at)
    MEM_W(0X26B0, ctx->r1) = ctx->r2;
    // 0x8007A33C: jal         0x80070490
    // 0x8007A340: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8007A340: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007A344: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007A348: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007A34C: jal         0x80070750
    // 0x8007A350: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8007A350: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x8007A354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A358: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8007A35C: jr          $ra
    // 0x8007A360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007A360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8007A364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A364: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8007A368: lw          $v0, 0x26B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26B0);
    // FALLTHROUGH: func_8007A364 falls into func_8007A36C
    func_8007A36C(rdram, ctx);
;}
RECOMP_FUNC void func_8007A36C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A36C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007A370: bne         $v0, $zero, L_8007A3B0
    if (ctx->r2 != 0) {
        // 0x8007A374: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_8007A3B0;
    }
    // 0x8007A374: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8007A378: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007A37C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8007A380: sw          $v0, 0x26B0($at)
    MEM_W(0X26B0, ctx->r1) = ctx->r2;
    // 0x8007A384: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8007A388: addiu       $a0, $a0, 0x4150
    ctx->r4 = ADD32(ctx->r4, 0X4150);
    // 0x8007A38C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007A390: addiu       $a1, $a1, 0x4690
    ctx->r5 = ADD32(ctx->r5, 0X4690);
    // 0x8007A394: jal         0x80070490
    // 0x8007A398: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8007A398: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007A39C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8007A3A0: addiu       $a0, $a0, 0x4150
    ctx->r4 = ADD32(ctx->r4, 0X4150);
    // 0x8007A3A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007A3A8: jal         0x80070750
    // 0x8007A3AC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8007A3AC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
L_8007A3B0:
    // 0x8007A3B0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8007A3B4: addiu       $a0, $a0, 0x4150
    ctx->r4 = ADD32(ctx->r4, 0X4150);
    // 0x8007A3B8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8007A3BC: jal         0x80070620
    // 0x8007A3C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8007A3C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8007A3C4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8007A3C8: jr          $ra
    // 0x8007A3CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8007A3CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8007A3D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A3D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A3D4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8007A3D8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8007A3DC: addiu       $a0, $a0, 0x4150
    ctx->r4 = ADD32(ctx->r4, 0X4150);
    // 0x8007A3E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007A3E4: jal         0x80070750
    // 0x8007A3E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8007A3E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x8007A3EC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8007A3F0: jr          $ra
    // 0x8007A3F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007A3F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007A3F8: nop

    // 0x8007A3FC: nop

;}
RECOMP_FUNC void func_8007A400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A400: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x8007A404: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x8007A408: bne         $at, $zero, L_8007A480
    if (ctx->r1 != 0) {
        // 0x8007A40C: nop
    
            goto L_8007A480;
    }
    // 0x8007A40C: nop

    // 0x8007A410: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8007A414: beq         $v1, $zero, L_8007A424
    if (ctx->r3 == 0) {
        // 0x8007A418: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_8007A424;
    }
    // 0x8007A418: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x8007A41C: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x8007A420: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_8007A424:
    // 0x8007A424: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x8007A428: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x8007A42C: beq         $a3, $zero, L_8007A460
    if (ctx->r7 == 0) {
        // 0x8007A430: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8007A460;
    }
    // 0x8007A430: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8007A434: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8007A438:
    // 0x8007A438: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8007A43C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007A440: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x8007A444: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8007A448: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8007A44C: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x8007A450: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x8007A454: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x8007A458: bne         $a0, $a3, L_8007A438
    if (ctx->r4 != ctx->r7) {
        // 0x8007A45C: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_8007A438;
    }
    // 0x8007A45C: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8007A460:
    // 0x8007A460: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8007A464: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x8007A468: beq         $a3, $zero, L_8007A480
    if (ctx->r7 == 0) {
        // 0x8007A46C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8007A480;
    }
    // 0x8007A46C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8007A470: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8007A474:
    // 0x8007A474: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8007A478: bne         $a0, $a3, L_8007A474
    if (ctx->r4 != ctx->r7) {
        // 0x8007A47C: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_8007A474;
    }
    // 0x8007A47C: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8007A480:
    // 0x8007A480: blez        $a1, L_8007A498
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8007A484: nop
    
            goto L_8007A498;
    }
    // 0x8007A484: nop

    // 0x8007A488: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_8007A48C:
    // 0x8007A48C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007A490: bne         $a0, $a1, L_8007A48C
    if (ctx->r4 != ctx->r5) {
        // 0x8007A494: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_8007A48C;
    }
    // 0x8007A494: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_8007A498:
    // 0x8007A498: jr          $ra
    // 0x8007A49C: nop

    return;
    // 0x8007A49C: nop

;}
RECOMP_FUNC void func_8007A4A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A4A0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8007A4A4: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x8007A4A8: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8007A4AC: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x8007A4B0: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8007A4B4: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x8007A4B8: sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // 0x8007A4BC: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x8007A4C0: addiu       $s5, $s5, 0x24E0
    ctx->r21 = ADD32(ctx->r21, 0X24E0);
    // 0x8007A4C4: sw          $ra, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r31;
    // 0x8007A4C8: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x8007A4CC: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x8007A4D0: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x8007A4D4: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x8007A4D8: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_8007A4DC:
    // 0x8007A4DC: lbu         $s1, 0x0($a1)
    ctx->r17 = MEM_BU(ctx->r5, 0X0);
    // 0x8007A4E0: j           L_8007A4EC
    // 0x8007A4E4: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
        goto L_8007A4EC;
    // 0x8007A4E4: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
L_8007A4E8:
    // 0x8007A4E8: lbu         $s1, 0x0($s2)
    ctx->r17 = MEM_BU(ctx->r18, 0X0);
L_8007A4EC:
    // 0x8007A4EC: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x8007A4F0: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x8007A4F4: xori        $v0, $v0, 0x25
    ctx->r2 = ctx->r2 ^ 0X25;
    // 0x8007A4F8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8007A4FC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8007A500: bnel        $v1, $zero, L_8007A4E8
    if (ctx->r3 != 0) {
        // 0x8007A504: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8007A4E8;
    }
    goto skip_0;
    // 0x8007A504: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x8007A508: subu        $s0, $s2, $a1
    ctx->r16 = SUB32(ctx->r18, ctx->r5);
    // 0x8007A50C: blez        $s0, L_8007A534
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8007A510: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_8007A534;
    }
    // 0x8007A510: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007A514: jalr        $s4
    // 0x8007A518: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x8007A518: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8007A51C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8007A520: beq         $s3, $zero, L_8007A9E8
    if (ctx->r19 == 0) {
        // 0x8007A524: nop
    
            goto L_8007A9E8;
    }
    // 0x8007A524: nop

    // 0x8007A528: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8007A52C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8007A530: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8007A534:
    // 0x8007A534: beq         $s1, $zero, L_8007A9E8
    if (ctx->r17 == 0) {
        // 0x8007A538: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8007A9E8;
    }
    // 0x8007A538: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007A53C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8007A540: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8007A544: addiu       $s0, $s0, 0x24E8
    ctx->r16 = ADD32(ctx->r16, 0X24E8);
L_8007A548:
    // 0x8007A548: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x8007A54C: jal         0x80073190
    // 0x8007A550: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_80073190(rdram, ctx);
        goto after_1;
    // 0x8007A550: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_1:
    // 0x8007A554: beq         $v0, $zero, L_8007A57C
    if (ctx->r2 == 0) {
        // 0x8007A558: subu        $v0, $v0, $s5
        ctx->r2 = SUB32(ctx->r2, ctx->r21);
            goto L_8007A57C;
    }
    // 0x8007A558: subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // 0x8007A55C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007A560: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8007A564: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8007A568: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007A56C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007A570: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8007A574: j           L_8007A548
    // 0x8007A578: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
        goto L_8007A548;
    // 0x8007A578: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
L_8007A57C:
    // 0x8007A57C: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
    // 0x8007A580: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x8007A584: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8007A588: bne         $v1, $v0, L_8007A5D0
    if (ctx->r3 != ctx->r2) {
        // 0x8007A58C: addiu       $v0, $a0, -0x30
        ctx->r2 = ADD32(ctx->r4, -0X30);
            goto L_8007A5D0;
    }
    // 0x8007A58C: addiu       $v0, $a0, -0x30
    ctx->r2 = ADD32(ctx->r4, -0X30);
    // 0x8007A590: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x8007A594: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
    // 0x8007A598: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8007A59C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8007A5A0: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x8007A5A4: sw          $v1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r3;
    // 0x8007A5A8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007A5AC: bgez        $v0, L_8007A5C8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007A5B0: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_8007A5C8;
    }
    // 0x8007A5B0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8007A5B4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8007A5B8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8007A5BC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8007A5C0: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x8007A5C4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
L_8007A5C8:
    // 0x8007A5C8: j           L_8007A620
    // 0x8007A5CC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8007A620;
    // 0x8007A5CC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8007A5D0:
    // 0x8007A5D0: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x8007A5D4: beq         $v0, $zero, L_8007A620
    if (ctx->r2 == 0) {
        // 0x8007A5D8: sw          $zero, 0x38($sp)
        MEM_W(0X38, ctx->r29) = 0;
            goto L_8007A620;
    }
    // 0x8007A5D8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_8007A5DC:
    // 0x8007A5DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8007A5E0: slti        $v0, $a0, 0x3E7
    ctx->r2 = SIGNED(ctx->r4) < 0X3E7 ? 1 : 0;
    // 0x8007A5E4: beql        $v0, $zero, L_8007A60C
    if (ctx->r2 == 0) {
        // 0x8007A5E8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8007A60C;
    }
    goto skip_1;
    // 0x8007A5E8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x8007A5EC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8007A5F0: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x8007A5F4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8007A5F8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8007A5FC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A600: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x8007A604: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8007A608: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8007A60C:
    // 0x8007A60C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8007A610: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x8007A614: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x8007A618: bne         $v0, $zero, L_8007A5DC
    if (ctx->r2 != 0) {
        // 0x8007A61C: nop
    
            goto L_8007A5DC;
    }
    // 0x8007A61C: nop

L_8007A620:
    // 0x8007A620: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x8007A624: addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // 0x8007A628: beq         $v1, $v0, L_8007A638
    if (ctx->r3 == ctx->r2) {
        // 0x8007A62C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8007A638;
    }
    // 0x8007A62C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8007A630: j           L_8007A6C8
    // 0x8007A634: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_8007A6C8;
    // 0x8007A634: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_8007A638:
    // 0x8007A638: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007A63C: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
    // 0x8007A640: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x8007A644: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8007A648: bne         $v1, $v0, L_8007A678
    if (ctx->r3 != ctx->r2) {
        // 0x8007A64C: addiu       $v0, $a0, -0x30
        ctx->r2 = ADD32(ctx->r4, -0X30);
            goto L_8007A678;
    }
    // 0x8007A64C: addiu       $v0, $a0, -0x30
    ctx->r2 = ADD32(ctx->r4, -0X30);
    // 0x8007A650: lw          $v1, 0x94($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X94);
    // 0x8007A654: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    // 0x8007A658: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x8007A65C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8007A660: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x8007A664: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x8007A668: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8007A66C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007A670: j           L_8007A6C8
    // 0x8007A674: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_8007A6C8;
    // 0x8007A674: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_8007A678:
    // 0x8007A678: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x8007A67C: beq         $v0, $zero, L_8007A6C8
    if (ctx->r2 == 0) {
        // 0x8007A680: sw          $zero, 0x34($sp)
        MEM_W(0X34, ctx->r29) = 0;
            goto L_8007A6C8;
    }
    // 0x8007A680: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8007A684:
    // 0x8007A684: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8007A688: slti        $v0, $a0, 0x3E7
    ctx->r2 = SIGNED(ctx->r4) < 0X3E7 ? 1 : 0;
    // 0x8007A68C: beql        $v0, $zero, L_8007A6B4
    if (ctx->r2 == 0) {
        // 0x8007A690: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8007A6B4;
    }
    goto skip_2;
    // 0x8007A690: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x8007A694: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8007A698: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x8007A69C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8007A6A0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8007A6A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A6A8: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x8007A6AC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8007A6B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8007A6B4:
    // 0x8007A6B4: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8007A6B8: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x8007A6BC: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x8007A6C0: bne         $v0, $zero, L_8007A684
    if (ctx->r2 != 0) {
        // 0x8007A6C4: nop
    
            goto L_8007A684;
    }
    // 0x8007A6C4: nop

L_8007A6C8:
    // 0x8007A6C8: lbu         $s0, 0x0($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X0);
    // 0x8007A6CC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8007A6D0: addiu       $a0, $a0, 0x2500
    ctx->r4 = ADD32(ctx->r4, 0X2500);
    // 0x8007A6D4: jal         0x80073190
    // 0x8007A6D8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80073190(rdram, ctx);
        goto after_2;
    // 0x8007A6D8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8007A6DC: beq         $v0, $zero, L_8007A6EC
    if (ctx->r2 == 0) {
        // 0x8007A6E0: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8007A6EC;
    }
    // 0x8007A6E0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007A6E4: j           L_8007A6F0
    // 0x8007A6E8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8007A6F0;
    // 0x8007A6E8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8007A6EC:
    // 0x8007A6EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8007A6F0:
    // 0x8007A6F0: sb          $a1, 0x44($sp)
    MEM_B(0X44, ctx->r29) = ctx->r5;
    // 0x8007A6F4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8007A6F8: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x8007A6FC: bne         $a1, $v0, L_8007A71C
    if (ctx->r5 != ctx->r2) {
        // 0x8007A700: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_8007A71C;
    }
    // 0x8007A700: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007A704: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8007A708: bne         $v0, $a1, L_8007A71C
    if (ctx->r2 != ctx->r5) {
        // 0x8007A70C: addiu       $v0, $zero, 0x4C
        ctx->r2 = ADD32(0, 0X4C);
            goto L_8007A71C;
    }
    // 0x8007A70C: addiu       $v0, $zero, 0x4C
    ctx->r2 = ADD32(0, 0X4C);
    // 0x8007A710: sb          $v0, 0x44($sp)
    MEM_B(0X44, ctx->r29) = ctx->r2;
    // 0x8007A714: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007A718: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_8007A71C:
    // 0x8007A71C: lbu         $a2, 0x0($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X0);
    // 0x8007A720: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8007A724: jal         0x8007AA10
    // 0x8007A728: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_3;
    // 0x8007A728: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x8007A72C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A730: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8007A734: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8007A738: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8007A73C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007A740: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A744: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8007A748: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8007A74C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8007A750: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8007A754: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8007A758: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8007A75C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8007A760: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x8007A764: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x8007A768: bne         $v0, $zero, L_8007A7C8
    if (ctx->r2 != 0) {
        // 0x8007A76C: sw          $a1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r5;
            goto L_8007A7C8;
    }
    // 0x8007A76C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8007A770: blez        $a1, L_8007A7C8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8007A774: nop
    
            goto L_8007A7C8;
    }
    // 0x8007A774: nop

    // 0x8007A778: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8007A77C: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8007A780:
    // 0x8007A780: beq         $v0, $zero, L_8007A78C
    if (ctx->r2 == 0) {
        // 0x8007A784: addiu       $s0, $zero, 0x20
        ctx->r16 = ADD32(0, 0X20);
            goto L_8007A78C;
    }
    // 0x8007A784: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x8007A788: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_8007A78C:
    // 0x8007A78C: blezl       $s0, L_8007A7C0
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8007A790: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8007A7C0;
    }
    goto skip_3;
    // 0x8007A790: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    skip_3:
    // 0x8007A794: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007A798: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8007A79C: addiu       $a1, $a1, 0x26C0
    ctx->r5 = ADD32(ctx->r5, 0X26C0);
    // 0x8007A7A0: jalr        $s4
    // 0x8007A7A4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_4;
    // 0x8007A7A4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8007A7A8: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8007A7AC: beq         $s3, $zero, L_8007A9E8
    if (ctx->r19 == 0) {
        // 0x8007A7B0: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8007A9E8;
    }
    // 0x8007A7B0: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8007A7B4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8007A7B8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8007A7BC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8007A7C0:
    // 0x8007A7C0: bgtz        $s1, L_8007A780
    if (SIGNED(ctx->r17) > 0) {
        // 0x8007A7C4: sltiu       $v0, $s1, 0x21
        ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8007A780;
    }
    // 0x8007A7C4: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8007A7C8:
    // 0x8007A7C8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A7CC: blez        $a2, L_8007A7F8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8007A7D0: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_8007A7F8;
    }
    // 0x8007A7D0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007A7D4: jalr        $s4
    // 0x8007A7D8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_5;
    // 0x8007A7D8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x8007A7DC: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8007A7E0: beq         $s3, $zero, L_8007A9E8
    if (ctx->r19 == 0) {
        // 0x8007A7E4: nop
    
            goto L_8007A9E8;
    }
    // 0x8007A7E4: nop

    // 0x8007A7E8: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8007A7EC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A7F0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A7F4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8007A7F8:
    // 0x8007A7F8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8007A7FC: blez        $v0, L_8007A854
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007A800: nop
    
            goto L_8007A854;
    }
    // 0x8007A800: nop

    // 0x8007A804: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8007A808: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8007A80C:
    // 0x8007A80C: beq         $v0, $zero, L_8007A818
    if (ctx->r2 == 0) {
        // 0x8007A810: addiu       $s0, $zero, 0x20
        ctx->r16 = ADD32(0, 0X20);
            goto L_8007A818;
    }
    // 0x8007A810: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x8007A814: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_8007A818:
    // 0x8007A818: blezl       $s0, L_8007A84C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8007A81C: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8007A84C;
    }
    goto skip_4;
    // 0x8007A81C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    skip_4:
    // 0x8007A820: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007A824: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8007A828: addiu       $a1, $a1, 0x26E4
    ctx->r5 = ADD32(ctx->r5, 0X26E4);
    // 0x8007A82C: jalr        $s4
    // 0x8007A830: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_6;
    // 0x8007A830: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8007A834: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8007A838: beq         $s3, $zero, L_8007A9E8
    if (ctx->r19 == 0) {
        // 0x8007A83C: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8007A9E8;
    }
    // 0x8007A83C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8007A840: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8007A844: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8007A848: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8007A84C:
    // 0x8007A84C: bgtz        $s1, L_8007A80C
    if (SIGNED(ctx->r17) > 0) {
        // 0x8007A850: sltiu       $v0, $s1, 0x21
        ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8007A80C;
    }
    // 0x8007A850: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8007A854:
    // 0x8007A854: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8007A858: blez        $a2, L_8007A888
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8007A85C: nop
    
            goto L_8007A888;
    }
    // 0x8007A85C: nop

    // 0x8007A860: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8007A864: jalr        $s4
    // 0x8007A868: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_7;
    // 0x8007A868: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_7:
    // 0x8007A86C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8007A870: beq         $s3, $zero, L_8007A9E8
    if (ctx->r19 == 0) {
        // 0x8007A874: nop
    
            goto L_8007A9E8;
    }
    // 0x8007A874: nop

    // 0x8007A878: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8007A87C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8007A880: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A884: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8007A888:
    // 0x8007A888: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8007A88C: blez        $v0, L_8007A8E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007A890: nop
    
            goto L_8007A8E4;
    }
    // 0x8007A890: nop

    // 0x8007A894: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8007A898: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8007A89C:
    // 0x8007A89C: beq         $v0, $zero, L_8007A8A8
    if (ctx->r2 == 0) {
        // 0x8007A8A0: addiu       $s0, $zero, 0x20
        ctx->r16 = ADD32(0, 0X20);
            goto L_8007A8A8;
    }
    // 0x8007A8A0: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x8007A8A4: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_8007A8A8:
    // 0x8007A8A8: blezl       $s0, L_8007A8DC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8007A8AC: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8007A8DC;
    }
    goto skip_5;
    // 0x8007A8AC: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    skip_5:
    // 0x8007A8B0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007A8B4: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8007A8B8: addiu       $a1, $a1, 0x26E4
    ctx->r5 = ADD32(ctx->r5, 0X26E4);
    // 0x8007A8BC: jalr        $s4
    // 0x8007A8C0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_8;
    // 0x8007A8C0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_8:
    // 0x8007A8C4: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8007A8C8: beq         $s3, $zero, L_8007A9E8
    if (ctx->r19 == 0) {
        // 0x8007A8CC: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8007A9E8;
    }
    // 0x8007A8CC: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8007A8D0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8007A8D4: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8007A8D8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8007A8DC:
    // 0x8007A8DC: bgtz        $s1, L_8007A89C
    if (SIGNED(ctx->r17) > 0) {
        // 0x8007A8E0: sltiu       $v0, $s1, 0x21
        ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8007A89C;
    }
    // 0x8007A8E0: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8007A8E4:
    // 0x8007A8E4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A8E8: blez        $a2, L_8007A91C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8007A8EC: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_8007A91C;
    }
    // 0x8007A8EC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007A8F0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8007A8F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8007A8F8: jalr        $s4
    // 0x8007A8FC: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_9;
    // 0x8007A8FC: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    after_9:
    // 0x8007A900: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8007A904: beq         $s3, $zero, L_8007A9E8
    if (ctx->r19 == 0) {
        // 0x8007A908: nop
    
            goto L_8007A9E8;
    }
    // 0x8007A908: nop

    // 0x8007A90C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8007A910: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A914: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A918: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8007A91C:
    // 0x8007A91C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8007A920: blez        $v0, L_8007A978
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007A924: nop
    
            goto L_8007A978;
    }
    // 0x8007A924: nop

    // 0x8007A928: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8007A92C: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8007A930:
    // 0x8007A930: beq         $v0, $zero, L_8007A93C
    if (ctx->r2 == 0) {
        // 0x8007A934: addiu       $s0, $zero, 0x20
        ctx->r16 = ADD32(0, 0X20);
            goto L_8007A93C;
    }
    // 0x8007A934: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x8007A938: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_8007A93C:
    // 0x8007A93C: blezl       $s0, L_8007A970
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8007A940: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8007A970;
    }
    goto skip_6;
    // 0x8007A940: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    skip_6:
    // 0x8007A944: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007A948: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8007A94C: addiu       $a1, $a1, 0x26E4
    ctx->r5 = ADD32(ctx->r5, 0X26E4);
    // 0x8007A950: jalr        $s4
    // 0x8007A954: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_10;
    // 0x8007A954: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_10:
    // 0x8007A958: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8007A95C: beq         $s3, $zero, L_8007A9E8
    if (ctx->r19 == 0) {
        // 0x8007A960: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8007A9E8;
    }
    // 0x8007A960: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8007A964: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8007A968: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8007A96C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8007A970:
    // 0x8007A970: bgtz        $s1, L_8007A930
    if (SIGNED(ctx->r17) > 0) {
        // 0x8007A974: sltiu       $v0, $s1, 0x21
        ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8007A930;
    }
    // 0x8007A974: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8007A978:
    // 0x8007A978: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8007A97C: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x8007A980: beq         $v0, $zero, L_8007A4DC
    if (ctx->r2 == 0) {
        // 0x8007A984: addiu       $a1, $s2, 0x1
        ctx->r5 = ADD32(ctx->r18, 0X1);
            goto L_8007A4DC;
    }
    // 0x8007A984: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
    // 0x8007A988: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8007A98C: blez        $v0, L_8007A4DC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007A990: addu        $s1, $v0, $zero
        ctx->r17 = ADD32(ctx->r2, 0);
            goto L_8007A4DC;
    }
    // 0x8007A990: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8007A994: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8007A998:
    // 0x8007A998: beq         $v0, $zero, L_8007A9A4
    if (ctx->r2 == 0) {
        // 0x8007A99C: addiu       $s0, $zero, 0x20
        ctx->r16 = ADD32(0, 0X20);
            goto L_8007A9A4;
    }
    // 0x8007A99C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x8007A9A0: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_8007A9A4:
    // 0x8007A9A4: blezl       $s0, L_8007A9D8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8007A9A8: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8007A9D8;
    }
    goto skip_7;
    // 0x8007A9A8: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    skip_7:
    // 0x8007A9AC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007A9B0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8007A9B4: addiu       $a1, $a1, 0x26C0
    ctx->r5 = ADD32(ctx->r5, 0X26C0);
    // 0x8007A9B8: jalr        $s4
    // 0x8007A9BC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_11;
    // 0x8007A9BC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_11:
    // 0x8007A9C0: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8007A9C4: beq         $s3, $zero, L_8007A9E8
    if (ctx->r19 == 0) {
        // 0x8007A9C8: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8007A9E8;
    }
    // 0x8007A9C8: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8007A9CC: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8007A9D0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8007A9D4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8007A9D8:
    // 0x8007A9D8: bgtz        $s1, L_8007A998
    if (SIGNED(ctx->r17) > 0) {
        // 0x8007A9DC: sltiu       $v0, $s1, 0x21
        ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8007A998;
    }
    // 0x8007A9DC: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
    // 0x8007A9E0: j           L_8007A4DC
    // 0x8007A9E4: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
        goto L_8007A4DC;
    // 0x8007A9E4: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
L_8007A9E8:
    // 0x8007A9E8: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8007A9EC: lw          $ra, 0x80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X80);
    // 0x8007A9F0: lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X7C);
    // 0x8007A9F4: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x8007A9F8: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x8007A9FC: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x8007AA00: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x8007AA04: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x8007AA08: jr          $ra
    // 0x8007AA0C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8007AA0C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_8007AED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AED0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007AED4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8007AED8: blez        $a1, L_8007AEF8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8007AEDC: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8007AEF8;
    }
    // 0x8007AEDC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8007AEE0:
    // 0x8007AEE0: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8007AEE4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007AEE8: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8007AEEC: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007AEF0: bne         $v0, $zero, L_8007AEE0
    if (ctx->r2 != 0) {
        // 0x8007AEF4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8007AEE0;
    }
    // 0x8007AEF4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8007AEF8:
    // 0x8007AEF8: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8007AEFC: jr          $ra
    // 0x8007AF00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007AF00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8007AF48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AF48: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8007AF4C: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x8007AF50: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8007AF54: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x8007AF58: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x8007AF5C: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x8007AF60: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8007AF64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8007AF68: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8007AF6C: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x8007AF70: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x8007AF74: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x8007AF78: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x8007AF7C: jal         0x80075FE0
    // 0x8007AF80: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x8007AF80: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    after_0:
    // 0x8007AF84: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x8007AF88: lw          $v0, 0x8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X8);
    // 0x8007AF8C: lw          $v1, 0xC($s5)
    ctx->r3 = MEM_W(ctx->r21, 0XC);
    // 0x8007AF90: sw          $v0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r2;
    // 0x8007AF94: sw          $v1, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r3;
    // 0x8007AF98: lw          $v0, 0x10($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X10);
    // 0x8007AF9C: lw          $v1, 0x14($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X14);
    // 0x8007AFA0: sw          $v0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r2;
    // 0x8007AFA4: sw          $v1, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r3;
    // 0x8007AFA8: lbu         $v0, 0x65($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X65);
    // 0x8007AFAC: beq         $v0, $zero, L_8007AFC8
    if (ctx->r2 == 0) {
        // 0x8007AFB0: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_8007AFC8;
    }
    // 0x8007AFB0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8007AFB4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007AFB8: jal         0x80074A60
    // 0x8007AFBC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80074A60(rdram, ctx);
        goto after_1;
    // 0x8007AFBC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8007AFC0: bne         $v0, $zero, L_8007B20C
    if (ctx->r2 != 0) {
        // 0x8007AFC4: nop
    
            goto L_8007B20C;
    }
    // 0x8007AFC4: nop

L_8007AFC8:
    // 0x8007AFC8: addiu       $s4, $sp, 0x18
    ctx->r20 = ADD32(ctx->r29, 0X18);
    // 0x8007AFCC: addiu       $s6, $sp, 0x38
    ctx->r22 = ADD32(ctx->r29, 0X38);
    // 0x8007AFD0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8007AFD4:
    // 0x8007AFD4: jal         0x80074A60
    // 0x8007AFD8: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    func_80074A60(rdram, ctx);
        goto after_2;
    // 0x8007AFD8: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_2:
    // 0x8007AFDC: bne         $v0, $zero, L_8007B20C
    if (ctx->r2 != 0) {
        // 0x8007AFE0: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8007B20C;
    }
    // 0x8007AFE0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007AFE4: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8007AFE8: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8007AFEC: jal         0x8007B960
    // 0x8007AFF0: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_8007B960(rdram, ctx);
        goto after_3;
    // 0x8007AFF0: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_3:
    // 0x8007AFF4: bne         $v0, $zero, L_8007B20C
    if (ctx->r2 != 0) {
        // 0x8007AFF8: addiu       $v1, $s4, 0x1
        ctx->r3 = ADD32(ctx->r20, 0X1);
            goto L_8007B20C;
    }
    // 0x8007AFF8: addiu       $v1, $s4, 0x1
    ctx->r3 = ADD32(ctx->r20, 0X1);
    // 0x8007AFFC: ori         $v0, $s2, 0x80
    ctx->r2 = ctx->r18 | 0X80;
    // 0x8007B000: sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
    // 0x8007B004: addiu       $a0, $s4, 0x20
    ctx->r4 = ADD32(ctx->r20, 0X20);
L_8007B008:
    // 0x8007B008: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8007B00C: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8007B010: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8007B014: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007B018: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007B01C: bne         $v0, $zero, L_8007B008
    if (ctx->r2 != 0) {
        // 0x8007B020: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8007B008;
    }
    // 0x8007B020: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007B024: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007B028: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8007B02C: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8007B030: jal         0x8007BB60
    // 0x8007B034: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_8007BB60(rdram, ctx);
        goto after_4;
    // 0x8007B034: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_4:
    // 0x8007B038: bne         $v0, $zero, L_8007B20C
    if (ctx->r2 != 0) {
        // 0x8007B03C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8007B20C;
    }
    // 0x8007B03C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007B040: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8007B044: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8007B048: jal         0x8007B960
    // 0x8007B04C: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    func_8007B960(rdram, ctx);
        goto after_5;
    // 0x8007B04C: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_5:
    // 0x8007B050: bne         $v0, $zero, L_8007B20C
    if (ctx->r2 != 0) {
        // 0x8007B054: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8007B20C;
    }
    // 0x8007B054: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8007B058: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8007B05C: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
L_8007B060:
    // 0x8007B060: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8007B064: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8007B068: bne         $v1, $v0, L_8007B088
    if (ctx->r3 != ctx->r2) {
        // 0x8007B06C: addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
            goto L_8007B088;
    }
    // 0x8007B06C: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x8007B070: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007B074: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007B078: slti        $v0, $s0, 0x20
    ctx->r2 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x8007B07C: bne         $v0, $zero, L_8007B060
    if (ctx->r2 != 0) {
        // 0x8007B080: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8007B060;
    }
    // 0x8007B080: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007B084: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_8007B088:
    // 0x8007B088: bne         $s0, $v0, L_8007B0E0
    if (ctx->r16 != ctx->r2) {
        // 0x8007B08C: nop
    
            goto L_8007B0E0;
    }
    // 0x8007B08C: nop

    // 0x8007B090: blez        $s2, L_8007B0D0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8007B094: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8007B0D0;
    }
    // 0x8007B094: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007B098: jal         0x80074A60
    // 0x8007B09C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80074A60(rdram, ctx);
        goto after_6;
    // 0x8007B09C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_6:
    // 0x8007B0A0: bne         $v0, $zero, L_8007B20C
    if (ctx->r2 != 0) {
        // 0x8007B0A4: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8007B20C;
    }
    // 0x8007B0A4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007B0A8: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8007B0AC: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8007B0B0: jal         0x8007B960
    // 0x8007B0B4: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_8007B960(rdram, ctx);
        goto after_7;
    // 0x8007B0B4: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_7:
    // 0x8007B0B8: bne         $v0, $zero, L_8007B20C
    if (ctx->r2 != 0) {
        // 0x8007B0BC: nop
    
            goto L_8007B20C;
    }
    // 0x8007B0BC: nop

    // 0x8007B0C0: lbu         $v1, 0x18($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X18);
    // 0x8007B0C4: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8007B0C8: bne         $v1, $v0, L_8007B0E0
    if (ctx->r3 != ctx->r2) {
        // 0x8007B0CC: nop
    
            goto L_8007B0E0;
    }
    // 0x8007B0CC: nop

L_8007B0D0:
    // 0x8007B0D0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007B0D4: slti        $v0, $s2, 0x3E
    ctx->r2 = SIGNED(ctx->r18) < 0X3E ? 1 : 0;
    // 0x8007B0D8: bne         $v0, $zero, L_8007AFD4
    if (ctx->r2 != 0) {
        // 0x8007B0DC: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8007AFD4;
    }
    // 0x8007B0DC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8007B0E0:
    // 0x8007B0E0: lbu         $v0, 0x65($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X65);
    // 0x8007B0E4: beq         $v0, $zero, L_8007B0FC
    if (ctx->r2 == 0) {
        // 0x8007B0E8: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8007B0FC;
    }
    // 0x8007B0E8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007B0EC: jal         0x80074A60
    // 0x8007B0F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80074A60(rdram, ctx);
        goto after_8;
    // 0x8007B0F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_8:
    // 0x8007B0F4: bne         $v0, $zero, L_8007B20C
    if (ctx->r2 != 0) {
        // 0x8007B0F8: nop
    
            goto L_8007B20C;
    }
    // 0x8007B0F8: nop

L_8007B0FC:
    // 0x8007B0FC: lhu         $v0, 0x18($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X18);
    // 0x8007B100: addiu       $a2, $s3, 0x1E
    ctx->r6 = ADD32(ctx->r19, 0X1E);
    // 0x8007B104: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007B108: slt         $v1, $zero, $s2
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8007B10C: sb          $s2, 0x1A($s3)
    MEM_B(0X1A, ctx->r19) = ctx->r18;
    // 0x8007B110: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x8007B114: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8007B118: sh          $v1, 0x18($s3)
    MEM_H(0X18, ctx->r19) = ctx->r3;
    // 0x8007B11C: lbu         $v0, 0x1B($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X1B);
    // 0x8007B120: addiu       $a1, $s3, 0x1C
    ctx->r5 = ADD32(ctx->r19, 0X1C);
    // 0x8007B124: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8007B128: sh          $zero, 0x1E($s3)
    MEM_H(0X1E, ctx->r19) = 0;
    // 0x8007B12C: sh          $zero, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = 0;
    // 0x8007B130: sb          $v0, 0x1B($s3)
    MEM_B(0X1B, ctx->r19) = ctx->r2;
L_8007B134:
    // 0x8007B134: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8007B138: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8007B13C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007B140: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8007B144: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x8007B148: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8007B14C: nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // 0x8007B150: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007B154: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x8007B158: sltu        $v0, $a0, $a3
    ctx->r2 = ctx->r4 < ctx->r7 ? 1 : 0;
    // 0x8007B15C: bne         $v0, $zero, L_8007B134
    if (ctx->r2 != 0) {
        // 0x8007B160: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8007B134;
    }
    // 0x8007B160: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8007B164: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8007B168: addiu       $s2, $sp, 0x18
    ctx->r18 = ADD32(ctx->r29, 0X18);
    // 0x8007B16C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B170: sh          $v0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r2;
    // 0x8007B174: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8007B178: sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
    // 0x8007B17C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8007B180: sh          $v0, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r2;
    // 0x8007B184: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8007B188: sh          $v0, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r2;
L_8007B18C:
    // 0x8007B18C: lhu         $a2, 0x40($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X40);
    // 0x8007B190: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8007B194: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8007B198: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8007B19C: jal         0x8007BB60
    // 0x8007B1A0: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_8007BB60(rdram, ctx);
        goto after_9;
    // 0x8007B1A0: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_9:
    // 0x8007B1A4: bne         $v0, $zero, L_8007B20C
    if (ctx->r2 != 0) {
        // 0x8007B1A8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8007B20C;
    }
    // 0x8007B1A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007B1AC: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8007B1B0: bne         $v0, $zero, L_8007B18C
    if (ctx->r2 != 0) {
        // 0x8007B1B4: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_8007B18C;
    }
    // 0x8007B1B4: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8007B1B8: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8007B1BC: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8007B1C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007B1C4: jal         0x8007B960
    // 0x8007B1C8: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_8007B960(rdram, ctx);
        goto after_10;
    // 0x8007B1C8: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_10:
    // 0x8007B1CC: beq         $v0, $zero, L_8007B1E4
    if (ctx->r2 == 0) {
        // 0x8007B1D0: addu        $a2, $s3, $zero
        ctx->r6 = ADD32(ctx->r19, 0);
            goto L_8007B1E4;
    }
    // 0x8007B1D0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8007B1D4: j           L_8007B20C
    // 0x8007B1D8: nop

        goto L_8007B20C;
    // 0x8007B1D8: nop

L_8007B1DC:
    // 0x8007B1DC: j           L_8007B20C
    // 0x8007B1E0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_8007B20C;
    // 0x8007B1E0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8007B1E4:
    // 0x8007B1E4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007B1E8: addiu       $a1, $a2, 0x20
    ctx->r5 = ADD32(ctx->r6, 0X20);
L_8007B1EC:
    // 0x8007B1EC: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8007B1F0: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x8007B1F4: bne         $v1, $v0, L_8007B1DC
    if (ctx->r3 != ctx->r2) {
        // 0x8007B1F8: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8007B1DC;
    }
    // 0x8007B1F8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8007B1FC: slt         $v0, $a2, $a1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007B200: bne         $v0, $zero, L_8007B1EC
    if (ctx->r2 != 0) {
        // 0x8007B204: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8007B1EC;
    }
    // 0x8007B204: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007B208: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007B20C:
    // 0x8007B20C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8007B210: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x8007B214: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x8007B218: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x8007B21C: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x8007B220: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x8007B224: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x8007B228: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x8007B22C: jr          $ra
    // 0x8007B230: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8007B230: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8007B234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B234: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007B238: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8007B23C: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8007B240: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8007B244: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8007B248: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8007B24C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8007B250: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8007B254: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007B258: lbu         $v0, 0x65($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X65);
    // 0x8007B25C: beq         $v0, $zero, L_8007B274
    if (ctx->r2 == 0) {
        // 0x8007B260: addu        $s2, $a1, $zero
        ctx->r18 = ADD32(ctx->r5, 0);
            goto L_8007B274;
    }
    // 0x8007B260: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8007B264: jal         0x80074A60
    // 0x8007B268: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80074A60(rdram, ctx);
        goto after_0;
    // 0x8007B268: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8007B26C: bne         $v0, $zero, L_8007B374
    if (ctx->r2 != 0) {
        // 0x8007B270: nop
    
            goto L_8007B374;
    }
    // 0x8007B270: nop

L_8007B274:
    // 0x8007B274: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8007B278: addiu       $s0, $sp, 0x1A
    ctx->r16 = ADD32(ctx->r29, 0X1A);
    // 0x8007B27C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B280: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x8007B284: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8007B288: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x8007B28C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8007B290: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x8007B294: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8007B298: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
L_8007B29C:
    // 0x8007B29C: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
    // 0x8007B2A0: lw          $a1, 0x8($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X8);
    // 0x8007B2A4: lhu         $a2, 0x0($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X0);
    // 0x8007B2A8: jal         0x8007B960
    // 0x8007B2AC: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    func_8007B960(rdram, ctx);
        goto after_1;
    // 0x8007B2AC: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_1:
    // 0x8007B2B0: bne         $v0, $zero, L_8007B374
    if (ctx->r2 != 0) {
        // 0x8007B2B4: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_8007B374;
    }
    // 0x8007B2B4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8007B2B8: addiu       $a3, $s2, 0x1C
    ctx->r7 = ADD32(ctx->r18, 0X1C);
    // 0x8007B2BC: sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
    // 0x8007B2C0: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
L_8007B2C4:
    // 0x8007B2C4: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8007B2C8: lhu         $v1, 0x20($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X20);
    // 0x8007B2CC: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    // 0x8007B2D0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8007B2D4: addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
    // 0x8007B2D8: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8007B2DC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8007B2E0: sltu        $v0, $a1, $a3
    ctx->r2 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x8007B2E4: sh          $a2, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r6;
    // 0x8007B2E8: bne         $v0, $zero, L_8007B2C4
    if (ctx->r2 != 0) {
        // 0x8007B2EC: sh          $a0, 0x22($sp)
        MEM_H(0X22, ctx->r29) = ctx->r4;
            goto L_8007B2C4;
    }
    // 0x8007B2EC: sh          $a0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r4;
    // 0x8007B2F0: lhu         $v1, 0x1C($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X1C);
    // 0x8007B2F4: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8007B2F8: bnel        $v1, $v0, L_8007B314
    if (ctx->r3 != ctx->r2) {
        // 0x8007B2FC: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8007B314;
    }
    goto skip_0;
    // 0x8007B2FC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x8007B300: lhu         $v1, 0x1E($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X1E);
    // 0x8007B304: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8007B308: beq         $v1, $v0, L_8007B324
    if (ctx->r3 == ctx->r2) {
        // 0x8007B30C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8007B324;
    }
    // 0x8007B30C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8007B310: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8007B314:
    // 0x8007B314: slti        $v0, $s3, 0x4
    ctx->r2 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8007B318: bne         $v0, $zero, L_8007B29C
    if (ctx->r2 != 0) {
        // 0x8007B31C: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8007B29C;
    }
    // 0x8007B31C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8007B320: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8007B324:
    // 0x8007B324: bne         $s3, $v0, L_8007B334
    if (ctx->r19 != ctx->r2) {
        // 0x8007B328: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8007B334;
    }
    // 0x8007B328: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8007B32C: j           L_8007B374
    // 0x8007B330: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_8007B374;
    // 0x8007B330: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8007B334:
    // 0x8007B334: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8007B338: addiu       $s1, $sp, 0x18
    ctx->r17 = ADD32(ctx->r29, 0X18);
L_8007B33C:
    // 0x8007B33C: beql        $s0, $s3, L_8007B364
    if (ctx->r16 == ctx->r19) {
        // 0x8007B340: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8007B364;
    }
    goto skip_1;
    // 0x8007B340: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8007B344: lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X0);
    // 0x8007B348: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x8007B34C: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
    // 0x8007B350: lw          $a1, 0x8($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X8);
    // 0x8007B354: jal         0x8007BB60
    // 0x8007B358: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    func_8007BB60(rdram, ctx);
        goto after_2;
    // 0x8007B358: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_2:
    // 0x8007B35C: bne         $v0, $zero, L_8007B374
    if (ctx->r2 != 0) {
        // 0x8007B360: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8007B374;
    }
    // 0x8007B360: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8007B364:
    // 0x8007B364: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8007B368: bne         $v0, $zero, L_8007B33C
    if (ctx->r2 != 0) {
        // 0x8007B36C: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_8007B33C;
    }
    // 0x8007B36C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8007B370: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007B374:
    // 0x8007B374: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8007B378: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8007B37C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8007B380: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8007B384: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8007B388: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B38C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8007B390: jr          $ra
    // 0x8007B394: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007B394: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8007B398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B398: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8007B39C: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8007B3A0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8007B3A4: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x8007B3A8: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8007B3AC: lbu         $v0, 0x65($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X65);
    // 0x8007B3B0: beq         $v0, $zero, L_8007B3CC
    if (ctx->r2 == 0) {
        // 0x8007B3B4: nop
    
            goto L_8007B3CC;
    }
    // 0x8007B3B4: nop

    // 0x8007B3B8: jal         0x80074A60
    // 0x8007B3BC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80074A60(rdram, ctx);
        goto after_0;
    // 0x8007B3BC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8007B3C0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8007B3C4: bne         $v1, $zero, L_8007B550
    if (ctx->r3 != 0) {
        // 0x8007B3C8: nop
    
            goto L_8007B550;
    }
    // 0x8007B3C8: nop

L_8007B3CC:
    // 0x8007B3CC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8007B3D0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8007B3D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007B3D8: jal         0x8007B960
    // 0x8007B3DC: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_8007B960(rdram, ctx);
        goto after_1;
    // 0x8007B3DC: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x8007B3E0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8007B3E4: bne         $v1, $zero, L_8007B550
    if (ctx->r3 != 0) {
        // 0x8007B3E8: addiu       $a1, $sp, 0x10
        ctx->r5 = ADD32(ctx->r29, 0X10);
            goto L_8007B550;
    }
    // 0x8007B3E8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8007B3EC: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x8007B3F0: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
    // 0x8007B3F4: sh          $zero, 0x50($sp)
    MEM_H(0X50, ctx->r29) = 0;
L_8007B3F8:
    // 0x8007B3F8: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8007B3FC: lhu         $v1, 0x50($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X50);
    // 0x8007B400: lhu         $a0, 0x52($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X52);
    // 0x8007B404: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8007B408: addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
    // 0x8007B40C: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8007B410: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8007B414: sltu        $v0, $a1, $a3
    ctx->r2 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x8007B418: sh          $a2, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r6;
    // 0x8007B41C: bne         $v0, $zero, L_8007B3F8
    if (ctx->r2 != 0) {
        // 0x8007B420: sh          $a0, 0x52($sp)
        MEM_H(0X52, ctx->r29) = ctx->r4;
            goto L_8007B3F8;
    }
    // 0x8007B420: sh          $a0, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r4;
    // 0x8007B424: lhu         $v1, 0x2C($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2C);
    // 0x8007B428: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8007B42C: bne         $v1, $v0, L_8007B444
    if (ctx->r3 != ctx->r2) {
        // 0x8007B430: addiu       $s1, $sp, 0x10
        ctx->r17 = ADD32(ctx->r29, 0X10);
            goto L_8007B444;
    }
    // 0x8007B430: addiu       $s1, $sp, 0x10
    ctx->r17 = ADD32(ctx->r29, 0X10);
    // 0x8007B434: lhu         $v1, 0x2E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2E);
    // 0x8007B438: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8007B43C: beq         $v1, $v0, L_8007B48C
    if (ctx->r3 == ctx->r2) {
        // 0x8007B440: nop
    
            goto L_8007B48C;
    }
    // 0x8007B440: nop

L_8007B444:
    // 0x8007B444: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007B448: jal         0x8007B234
    // 0x8007B44C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8007B234(rdram, ctx);
        goto after_2;
    // 0x8007B44C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8007B450: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8007B454: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8007B458: bne         $v1, $v0, L_8007B484
    if (ctx->r3 != ctx->r2) {
        // 0x8007B45C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8007B484;
    }
    // 0x8007B45C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007B460: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8007B464: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x8007B468: jal         0x8007AF48
    // 0x8007B46C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8007AF48(rdram, ctx);
        goto after_3;
    // 0x8007B46C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_3:
    // 0x8007B470: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8007B474: beq         $v1, $zero, L_8007B48C
    if (ctx->r3 == 0) {
        // 0x8007B478: nop
    
            goto L_8007B48C;
    }
    // 0x8007B478: nop

    // 0x8007B47C: j           L_8007B550
    // 0x8007B480: nop

        goto L_8007B550;
    // 0x8007B480: nop

L_8007B484:
    // 0x8007B484: bne         $v1, $zero, L_8007B550
    if (ctx->r3 != 0) {
        // 0x8007B488: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8007B550;
    }
    // 0x8007B488: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8007B48C:
    // 0x8007B48C: lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18);
    // 0x8007B490: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8007B494: bne         $v0, $zero, L_8007B4D4
    if (ctx->r2 != 0) {
        // 0x8007B498: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8007B4D4;
    }
    // 0x8007B498: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007B49C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007B4A0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8007B4A4: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x8007B4A8: jal         0x8007AF48
    // 0x8007B4AC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8007AF48(rdram, ctx);
        goto after_4;
    // 0x8007B4AC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_4:
    // 0x8007B4B0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8007B4B4: bne         $v1, $zero, L_8007B550
    if (ctx->r3 != 0) {
        // 0x8007B4B8: nop
    
            goto L_8007B550;
    }
    // 0x8007B4B8: nop

    // 0x8007B4BC: lhu         $v0, 0x48($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X48);
    // 0x8007B4C0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8007B4C4: bne         $v0, $zero, L_8007B4D4
    if (ctx->r2 != 0) {
        // 0x8007B4C8: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8007B4D4;
    }
    // 0x8007B4C8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007B4CC: j           L_8007B550
    // 0x8007B4D0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_8007B550;
    // 0x8007B4D0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_8007B4D4:
    // 0x8007B4D4: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8007B4D8: jal         0x80072BD0
    // 0x8007B4DC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80072BD0(rdram, ctx);
        goto after_5;
    // 0x8007B4DC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_5:
    // 0x8007B4E0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8007B4E4: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8007B4E8: lbu         $v0, 0x1B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1B);
    // 0x8007B4EC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8007B4F0: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x8007B4F4: lbu         $v1, 0x1A($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1A);
    // 0x8007B4F8: addiu       $a3, $s0, 0x2C
    ctx->r7 = ADD32(ctx->r16, 0X2C);
    // 0x8007B4FC: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8007B500: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x8007B504: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8007B508: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x8007B50C: sb          $v1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r3;
    // 0x8007B510: lbu         $v0, 0x64($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X64);
    // 0x8007B514: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8007B518: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x8007B51C: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
    // 0x8007B520: lbu         $v1, 0x64($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X64);
    // 0x8007B524: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007B528: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8007B52C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8007B530: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x8007B534: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007B538: jal         0x8007B960
    // 0x8007B53C: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
    func_8007B960(rdram, ctx);
        goto after_6;
    // 0x8007B53C: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
    after_6:
    // 0x8007B540: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8007B544: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
    // 0x8007B548: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8007B54C: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
L_8007B550:
    // 0x8007B550: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x8007B554: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8007B558: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8007B55C: jr          $ra
    // 0x8007B560: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8007B560: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8007B564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B564: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007B568: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8007B56C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8007B570: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8007B574: lbu         $v0, 0x65($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X65);
    // 0x8007B578: beq         $v0, $zero, L_8007B5AC
    if (ctx->r2 == 0) {
        // 0x8007B57C: nop
    
            goto L_8007B5AC;
    }
    // 0x8007B57C: nop

    // 0x8007B580: jal         0x80074A60
    // 0x8007B584: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80074A60(rdram, ctx);
        goto after_0;
    // 0x8007B584: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8007B588: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8007B58C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007B590: bne         $v1, $v0, L_8007B5A4
    if (ctx->r3 != ctx->r2) {
        // 0x8007B594: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8007B5A4;
    }
    // 0x8007B594: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007B598: jal         0x80074A60
    // 0x8007B59C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80074A60(rdram, ctx);
        goto after_1;
    // 0x8007B59C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8007B5A0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8007B5A4:
    // 0x8007B5A4: bne         $v1, $zero, L_8007B60C
    if (ctx->r3 != 0) {
        // 0x8007B5A8: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8007B60C;
    }
    // 0x8007B5A8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8007B5AC:
    // 0x8007B5AC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8007B5B0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8007B5B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007B5B8: jal         0x8007B960
    // 0x8007B5BC: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_8007B960(rdram, ctx);
        goto after_2;
    // 0x8007B5BC: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x8007B5C0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8007B5C4: beq         $v1, $zero, L_8007B5F4
    if (ctx->r3 == 0) {
        // 0x8007B5C8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8007B5F4;
    }
    // 0x8007B5C8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007B5CC: bne         $v1, $v0, L_8007B60C
    if (ctx->r3 != ctx->r2) {
        // 0x8007B5D0: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8007B60C;
    }
    // 0x8007B5D0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8007B5D4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8007B5D8: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8007B5DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007B5E0: jal         0x8007B960
    // 0x8007B5E4: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_8007B960(rdram, ctx);
        goto after_3;
    // 0x8007B5E4: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x8007B5E8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8007B5EC: bne         $v1, $zero, L_8007B60C
    if (ctx->r3 != 0) {
        // 0x8007B5F0: nop
    
            goto L_8007B60C;
    }
    // 0x8007B5F0: nop

L_8007B5F4:
    // 0x8007B5F4: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x8007B5F8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8007B5FC: jal         0x8007CDB0
    // 0x8007B600: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8007CDB0(rdram, ctx);
        goto after_4;
    // 0x8007B600: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_4:
    // 0x8007B604: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8007B608: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8007B60C:
    // 0x8007B60C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8007B610: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8007B614: jr          $ra
    // 0x8007B618: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007B618: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8007B61C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B61C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8007B620: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8007B624: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8007B628: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8007B62C: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8007B630: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8007B634: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x8007B638: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8007B63C: addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // 0x8007B640: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x8007B644: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8007B648: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8007B64C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8007B650: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8007B654: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8007B658: bne         $v0, $zero, L_8007B6A0
    if (ctx->r2 != 0) {
        // 0x8007B65C: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_8007B6A0;
    }
    // 0x8007B65C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007B660: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8007B664: lbu         $v1, 0x2714($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2714);
    // 0x8007B668: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x8007B66C: bne         $v0, $v1, L_8007B6A0
    if (ctx->r2 != ctx->r3) {
        // 0x8007B670: nop
    
            goto L_8007B6A0;
    }
    // 0x8007B670: nop

    // 0x8007B674: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x8007B678: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8007B67C: lw          $v0, 0x2710($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2710);
    // 0x8007B680: bne         $v1, $v0, L_8007B6A0
    if (ctx->r3 != ctx->r2) {
        // 0x8007B684: nop
    
            goto L_8007B6A0;
    }
    // 0x8007B684: nop

    // 0x8007B688: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007B68C: addiu       $a0, $a0, -0x5630
    ctx->r4 = ADD32(ctx->r4, -0X5630);
    // 0x8007B690: jal         0x80072BD0
    // 0x8007B694: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    func_80072BD0(rdram, ctx);
        goto after_0;
    // 0x8007B694: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_0:
    // 0x8007B698: j           L_8007B924
    // 0x8007B69C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8007B924;
    // 0x8007B69C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007B6A0:
    // 0x8007B6A0: lbu         $v0, 0x65($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X65);
    // 0x8007B6A4: beq         $v0, $zero, L_8007B6C0
    if (ctx->r2 == 0) {
        // 0x8007B6A8: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8007B6C0;
    }
    // 0x8007B6A8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8007B6AC: jal         0x80074A60
    // 0x8007B6B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80074A60(rdram, ctx);
        goto after_1;
    // 0x8007B6B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8007B6B4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8007B6B8: bne         $v1, $zero, L_8007B924
    if (ctx->r3 != 0) {
        // 0x8007B6BC: nop
    
            goto L_8007B924;
    }
    // 0x8007B6BC: nop

L_8007B6C0:
    // 0x8007B6C0: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x8007B6C4: bne         $v0, $zero, L_8007B6D0
    if (ctx->r2 != 0) {
        // 0x8007B6C8: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_8007B6D0;
    }
    // 0x8007B6C8: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8007B6CC: lw          $s5, 0x60($s2)
    ctx->r21 = MEM_W(ctx->r18, 0X60);
L_8007B6D0:
    // 0x8007B6D0: andi        $v1, $s6, 0xFF
    ctx->r3 = ctx->r22 & 0XFF;
    // 0x8007B6D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B6D8: bne         $v1, $v0, L_8007B720
    if (ctx->r3 != ctx->r2) {
        // 0x8007B6DC: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8007B720;
    }
    // 0x8007B6DC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8007B6E0: sll         $v0, $s5, 1
    ctx->r2 = S32(ctx->r21 << 1);
    // 0x8007B6E4: addu        $a1, $v0, $s4
    ctx->r5 = ADD32(ctx->r2, ctx->r20);
    // 0x8007B6E8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007B6EC: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8007B6F0: subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // 0x8007B6F4: sll         $a2, $v0, 1
    ctx->r6 = S32(ctx->r2 << 1);
    // 0x8007B6F8: blez        $a2, L_8007B718
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8007B6FC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8007B718;
    }
    // 0x8007B6FC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8007B700:
    // 0x8007B700: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8007B704: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007B708: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8007B70C: slt         $v0, $a0, $a2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8007B710: bne         $v0, $zero, L_8007B700
    if (ctx->r2 != 0) {
        // 0x8007B714: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8007B700;
    }
    // 0x8007B714: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8007B718:
    // 0x8007B718: sb          $v1, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r3;
    // 0x8007B71C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8007B720:
    // 0x8007B720: andi        $fp, $s6, 0xFF
    ctx->r30 = ctx->r22 & 0XFF;
    // 0x8007B724: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x8007B728: sll         $s3, $v0, 3
    ctx->r19 = S32(ctx->r2 << 3);
    // 0x8007B72C: sll         $v0, $s0, 5
    ctx->r2 = S32(ctx->r16 << 5);
L_8007B730:
    // 0x8007B730: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007B734: bne         $fp, $t0, L_8007B78C
    if (ctx->r30 != ctx->r8) {
        // 0x8007B738: addu        $s1, $s4, $v0
        ctx->r17 = ADD32(ctx->r20, ctx->r2);
            goto L_8007B78C;
    }
    // 0x8007B738: addu        $s1, $s4, $v0
    ctx->r17 = ADD32(ctx->r20, ctx->r2);
    // 0x8007B73C: lw          $a2, 0x54($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X54);
    // 0x8007B740: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007B744: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x8007B748: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x8007B74C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x8007B750: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x8007B754: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x8007B758: jal         0x8007BB60
    // 0x8007B75C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_8007BB60(rdram, ctx);
        goto after_2;
    // 0x8007B75C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_2:
    // 0x8007B760: lw          $a2, 0x58($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X58);
    // 0x8007B764: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007B768: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x8007B76C: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x8007B770: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x8007B774: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x8007B778: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x8007B77C: jal         0x8007BB60
    // 0x8007B780: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_8007BB60(rdram, ctx);
        goto after_3;
    // 0x8007B780: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_3:
    // 0x8007B784: j           L_8007B7B0
    // 0x8007B788: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8007B7B0;
    // 0x8007B788: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8007B78C:
    // 0x8007B78C: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x8007B790: lw          $a2, 0x54($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X54);
    // 0x8007B794: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x8007B798: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x8007B79C: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x8007B7A0: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x8007B7A4: jal         0x8007B960
    // 0x8007B7A8: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_8007B960(rdram, ctx);
        goto after_4;
    // 0x8007B7A8: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_4:
    // 0x8007B7AC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8007B7B0:
    // 0x8007B7B0: bne         $v1, $zero, L_8007B8A8
    if (ctx->r3 != 0) {
        // 0x8007B7B4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8007B8A8;
    }
    // 0x8007B7B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007B7B8: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8007B7BC: bne         $v0, $zero, L_8007B730
    if (ctx->r2 != 0) {
        // 0x8007B7C0: sll         $v0, $s0, 5
        ctx->r2 = S32(ctx->r16 << 5);
            goto L_8007B730;
    }
    // 0x8007B7C0: sll         $v0, $s0, 5
    ctx->r2 = S32(ctx->r16 << 5);
    // 0x8007B7C4: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x8007B7C8: bnel        $v0, $zero, L_8007B8FC
    if (ctx->r2 != 0) {
        // 0x8007B7CC: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_8007B8FC;
    }
    goto skip_0;
    // 0x8007B7CC: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    skip_0:
    // 0x8007B7D0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8007B7D4: sll         $v0, $s5, 1
    ctx->r2 = S32(ctx->r21 << 1);
    // 0x8007B7D8: addu        $a1, $v0, $s4
    ctx->r5 = ADD32(ctx->r2, ctx->r20);
    // 0x8007B7DC: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8007B7E0: subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // 0x8007B7E4: sll         $a2, $v0, 1
    ctx->r6 = S32(ctx->r2 << 1);
    // 0x8007B7E8: slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8007B7EC: beq         $v0, $zero, L_8007B80C
    if (ctx->r2 == 0) {
        // 0x8007B7F0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8007B80C;
    }
    // 0x8007B7F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8007B7F4:
    // 0x8007B7F4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8007B7F8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007B7FC: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8007B800: slt         $v0, $a0, $a2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8007B804: bne         $v0, $zero, L_8007B7F4
    if (ctx->r2 != 0) {
        // 0x8007B808: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8007B7F4;
    }
    // 0x8007B808: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8007B80C:
    // 0x8007B80C: lbu         $v1, 0x1($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X1);
    // 0x8007B810: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x8007B814: beq         $v0, $v1, L_8007B8F8
    if (ctx->r2 == ctx->r3) {
        // 0x8007B818: andi        $v0, $s7, 0xFF
        ctx->r2 = ctx->r23 & 0XFF;
            goto L_8007B8F8;
    }
    // 0x8007B818: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x8007B81C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8007B820: sll         $s3, $v0, 3
    ctx->r19 = S32(ctx->r2 << 3);
    // 0x8007B824: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
L_8007B828:
    // 0x8007B828: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x8007B82C: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x8007B830: lw          $a2, 0x58($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X58);
    // 0x8007B834: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x8007B838: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x8007B83C: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x8007B840: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x8007B844: jal         0x8007B960
    // 0x8007B848: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_8007B960(rdram, ctx);
        goto after_5;
    // 0x8007B848: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_5:
    // 0x8007B84C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007B850: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8007B854: bne         $v0, $zero, L_8007B828
    if (ctx->r2 != 0) {
        // 0x8007B858: addiu       $v1, $zero, 0x80
        ctx->r3 = ADD32(0, 0X80);
            goto L_8007B828;
    }
    // 0x8007B858: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    // 0x8007B85C: sll         $v0, $s5, 1
    ctx->r2 = S32(ctx->r21 << 1);
    // 0x8007B860: addu        $a2, $v0, $s4
    ctx->r6 = ADD32(ctx->r2, ctx->r20);
    // 0x8007B864: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007B868: subu        $v1, $v1, $s5
    ctx->r3 = SUB32(ctx->r3, ctx->r21);
    // 0x8007B86C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8007B870: blez        $v1, L_8007B890
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007B874: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8007B890;
    }
    // 0x8007B874: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8007B878:
    // 0x8007B878: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x8007B87C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007B880: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8007B884: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007B888: bne         $v0, $zero, L_8007B878
    if (ctx->r2 != 0) {
        // 0x8007B88C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8007B878;
    }
    // 0x8007B88C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8007B890:
    // 0x8007B890: lbu         $v1, 0x1($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X1);
    // 0x8007B894: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8007B898: beq         $v0, $v1, L_8007B8B0
    if (ctx->r2 == ctx->r3) {
        // 0x8007B89C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8007B8B0;
    }
    // 0x8007B89C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8007B8A0: j           L_8007B924
    // 0x8007B8A4: nop

        goto L_8007B924;
    // 0x8007B8A4: nop

L_8007B8A8:
    // 0x8007B8A8: j           L_8007B924
    // 0x8007B8AC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8007B924;
    // 0x8007B8AC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8007B8B0:
    // 0x8007B8B0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8007B8B4: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x8007B8B8: sll         $s3, $v0, 3
    ctx->r19 = S32(ctx->r2 << 3);
    // 0x8007B8BC: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
L_8007B8C0:
    // 0x8007B8C0: lw          $a2, 0x54($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X54);
    // 0x8007B8C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007B8C8: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x8007B8CC: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x8007B8D0: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x8007B8D4: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x8007B8D8: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x8007B8DC: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x8007B8E0: jal         0x8007BB60
    // 0x8007B8E4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_8007BB60(rdram, ctx);
        goto after_6;
    // 0x8007B8E4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_6:
    // 0x8007B8E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007B8EC: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8007B8F0: bne         $v0, $zero, L_8007B8C0
    if (ctx->r2 != 0) {
        // 0x8007B8F4: nop
    
            goto L_8007B8C0;
    }
    // 0x8007B8F4: nop

L_8007B8F8:
    // 0x8007B8F8: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
L_8007B8FC:
    // 0x8007B8FC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8007B900: addiu       $a1, $a1, -0x5630
    ctx->r5 = ADD32(ctx->r5, -0X5630);
    // 0x8007B904: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8007B908: sb          $s7, 0x2714($at)
    MEM_B(0X2714, ctx->r1) = ctx->r23;
    // 0x8007B90C: jal         0x80072BD0
    // 0x8007B910: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    func_80072BD0(rdram, ctx);
        goto after_7;
    // 0x8007B910: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_7:
    // 0x8007B914: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x8007B918: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8007B91C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8007B920: sw          $v1, 0x2710($at)
    MEM_W(0X2710, ctx->r1) = ctx->r3;
L_8007B924:
    // 0x8007B924: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8007B928: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8007B92C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8007B930: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8007B934: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8007B938: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8007B93C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8007B940: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8007B944: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B948: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8007B94C: jr          $ra
    // 0x8007B950: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007B950: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8007B954: nop

    // 0x8007B958: nop

    // 0x8007B95C: nop

;}
RECOMP_FUNC void func_8007B960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B960: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8007B964: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8007B968: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x8007B96C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8007B970: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8007B974: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8007B978: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x8007B97C: addiu       $s3, $s3, 0x3250
    ctx->r19 = ADD32(ctx->r19, 0X3250);
    // 0x8007B980: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8007B984: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8007B988: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007B98C: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8007B990: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8007B994: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8007B998: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8007B99C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8007B9A0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8007B9A4: jal         0x80079D24
    // 0x8007B9A8: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    func_80079D24(rdram, ctx);
        goto after_0;
    // 0x8007B9A8: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    after_0:
    // 0x8007B9AC: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x8007B9B0: andi        $s7, $s0, 0xFFFF
    ctx->r23 = ctx->r16 & 0XFFFF;
    // 0x8007B9B4: sll         $s0, $s0, 5
    ctx->r16 = S32(ctx->r16 << 5);
    // 0x8007B9B8: addiu       $s2, $s3, 0x26
    ctx->r18 = ADD32(ctx->r19, 0X26);
    // 0x8007B9BC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
L_8007B9C0:
    // 0x8007B9C0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8007B9C4: lbu         $v0, -0x7450($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7450);
    // 0x8007B9C8: bne         $v0, $fp, L_8007B9E0
    if (ctx->r2 != ctx->r30) {
        // 0x8007B9CC: nop
    
            goto L_8007B9E0;
    }
    // 0x8007B9CC: nop

    // 0x8007B9D0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8007B9D4: lw          $v0, 0x2720($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2720);
    // 0x8007B9D8: beql        $v0, $s4, L_8007BA48
    if (ctx->r2 == ctx->r20) {
        // 0x8007B9DC: addu        $s2, $s2, $s4
        ctx->r18 = ADD32(ctx->r18, ctx->r20);
            goto L_8007BA48;
    }
    goto skip_0;
    // 0x8007B9DC: addu        $s2, $s2, $s4
    ctx->r18 = ADD32(ctx->r18, ctx->r20);
    skip_0:
L_8007B9E0:
    // 0x8007B9E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8007B9E4: sb          $fp, -0x7450($at)
    MEM_B(-0X7450, ctx->r1) = ctx->r30;
    // 0x8007B9E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8007B9EC: sw          $s4, 0x2720($at)
    MEM_W(0X2720, ctx->r1) = ctx->r20;
    // 0x8007B9F0: blez        $s4, L_8007BA10
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8007B9F4: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8007BA10;
    }
    // 0x8007B9F4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8007B9F8:
    // 0x8007B9F8: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x8007B9FC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007BA00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007BA04: slt         $v0, $v1, $s4
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8007BA08: bne         $v0, $zero, L_8007B9F8
    if (ctx->r2 != 0) {
        // 0x8007BA0C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8007B9F8;
    }
    // 0x8007BA0C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8007BA10:
    // 0x8007BA10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007BA14: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007BA18: sw          $v0, 0x328C($at)
    MEM_W(0X328C, ctx->r1) = ctx->r2;
    // 0x8007BA1C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8007BA20: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8007BA24: sb          $t0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r8;
    // 0x8007BA28: sb          $v0, -0x25($s2)
    MEM_B(-0X25, ctx->r18) = ctx->r2;
    // 0x8007BA2C: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // 0x8007BA30: sb          $v0, -0x24($s2)
    MEM_B(-0X24, ctx->r18) = ctx->r2;
    // 0x8007BA34: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x8007BA38: sb          $fp, -0x23($s2)
    MEM_B(-0X23, ctx->r18) = ctx->r30;
    // 0x8007BA3C: sb          $t0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r8;
    // 0x8007BA40: j           L_8007BA4C
    // 0x8007BA44: sb          $v0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r2;
        goto L_8007BA4C;
    // 0x8007BA44: sb          $v0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r2;
L_8007BA48:
    // 0x8007BA48: addu        $s3, $s3, $s4
    ctx->r19 = ADD32(ctx->r19, ctx->r20);
L_8007BA4C:
    // 0x8007BA4C: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x8007BA50: srl         $v0, $s7, 3
    ctx->r2 = S32(U32(ctx->r23) >> 3);
    // 0x8007BA54: jal         0x8007BD80
    // 0x8007BA58: sb          $v0, -0x22($s2)
    MEM_B(-0X22, ctx->r18) = ctx->r2;
    func_8007BD80(rdram, ctx);
        goto after_1;
    // 0x8007BA58: sb          $v0, -0x22($s2)
    MEM_B(-0X22, ctx->r18) = ctx->r2;
    after_1:
    // 0x8007BA5C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BA60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007BA64: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8007BA68: addiu       $a1, $a1, 0x3250
    ctx->r5 = ADD32(ctx->r5, 0X3250);
    // 0x8007BA6C: or          $v0, $v0, $t0
    ctx->r2 = ctx->r2 | ctx->r8;
    // 0x8007BA70: jal         0x80074C60
    // 0x8007BA74: sb          $v0, -0x21($s2)
    MEM_B(-0X21, ctx->r18) = ctx->r2;
    func_80074C60(rdram, ctx);
        goto after_2;
    // 0x8007BA74: sb          $v0, -0x21($s2)
    MEM_B(-0X21, ctx->r18) = ctx->r2;
    after_2:
    // 0x8007BA78: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8007BA7C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007BA80: jal         0x80070620
    // 0x8007BA84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8007BA84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8007BA88: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8007BA8C: addiu       $a1, $a1, 0x3250
    ctx->r5 = ADD32(ctx->r5, 0X3250);
    // 0x8007BA90: jal         0x80074C60
    // 0x8007BA94: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80074C60(rdram, ctx);
        goto after_4;
    // 0x8007BA94: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // 0x8007BA98: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8007BA9C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007BAA0: jal         0x80070620
    // 0x8007BAA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8007BAA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8007BAA8: lbu         $v0, -0x24($s2)
    ctx->r2 = MEM_BU(ctx->r18, -0X24);
    // 0x8007BAAC: andi        $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 & 0XC0;
    // 0x8007BAB0: srl         $s0, $v0, 4
    ctx->r16 = S32(U32(ctx->r2) >> 4);
    // 0x8007BAB4: bnel        $s0, $zero, L_8007BB0C
    if (ctx->r16 != 0) {
        // 0x8007BAB8: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_8007BB0C;
    }
    goto skip_1;
    // 0x8007BAB8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_1:
    // 0x8007BABC: addiu       $s1, $s3, 0x6
    ctx->r17 = ADD32(ctx->r19, 0X6);
    // 0x8007BAC0: jal         0x8007BDEC
    // 0x8007BAC4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8007BDEC(rdram, ctx);
        goto after_6;
    // 0x8007BAC4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
    // 0x8007BAC8: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x8007BACC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8007BAD0: beq         $v0, $v1, L_8007BAF4
    if (ctx->r2 == ctx->r3) {
        // 0x8007BAD4: addu        $a0, $s6, $zero
        ctx->r4 = ADD32(ctx->r22, 0);
            goto L_8007BAF4;
    }
    // 0x8007BAD4: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8007BAD8: jal         0x8007CAA0
    // 0x8007BADC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8007CAA0(rdram, ctx);
        goto after_7;
    // 0x8007BADC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_7:
    // 0x8007BAE0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8007BAE4: bne         $s0, $zero, L_8007BB20
    if (ctx->r16 != 0) {
        // 0x8007BAE8: nop
    
            goto L_8007BB20;
    }
    // 0x8007BAE8: nop

    // 0x8007BAEC: j           L_8007BB0C
    // 0x8007BAF0: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
        goto L_8007BB0C;
    // 0x8007BAF0: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_8007BAF4:
    // 0x8007BAF4: lw          $a1, 0x14($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14);
    // 0x8007BAF8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007BAFC: jal         0x80072BD0
    // 0x8007BB00: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80072BD0(rdram, ctx);
        goto after_8;
    // 0x8007BB00: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_8:
    // 0x8007BB04: j           L_8007BB10
    // 0x8007BB08: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8007BB10;
    // 0x8007BB08: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8007BB0C:
    // 0x8007BB0C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8007BB10:
    // 0x8007BB10: bne         $s0, $v0, L_8007BB20
    if (ctx->r16 != ctx->r2) {
        // 0x8007BB14: addu        $v0, $s5, $zero
        ctx->r2 = ADD32(ctx->r21, 0);
            goto L_8007BB20;
    }
    // 0x8007BB14: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // 0x8007BB18: bgez        $v0, L_8007B9C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007BB1C: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_8007B9C0;
    }
    // 0x8007BB1C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_8007BB20:
    // 0x8007BB20: jal         0x80079D90
    // 0x8007BB24: nop

    func_80079D90(rdram, ctx);
        goto after_9;
    // 0x8007BB24: nop

    after_9:
    // 0x8007BB28: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8007BB2C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8007BB30: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8007BB34: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8007BB38: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8007BB3C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8007BB40: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8007BB44: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8007BB48: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8007BB4C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8007BB50: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8007BB54: jr          $ra
    // 0x8007BB58: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007BB58: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8007BB5C: nop

;}
RECOMP_FUNC void func_8007BB60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BB60: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007BB64: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x8007BB68: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8007BB6C: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x8007BB70: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8007BB74: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8007BB78: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8007BB7C: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x8007BB80: addiu       $s2, $s2, 0x3250
    ctx->r18 = ADD32(ctx->r18, 0X3250);
    // 0x8007BB84: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8007BB88: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8007BB8C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8007BB90: addu        $fp, $a3, $zero
    ctx->r30 = ADD32(ctx->r7, 0);
    // 0x8007BB94: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007BB98: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8007BB9C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x8007BBA0: sltiu       $v1, $a0, 0x7
    ctx->r3 = ctx->r4 < 0X7 ? 1 : 0;
    // 0x8007BBA4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8007BBA8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8007BBAC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8007BBB0: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8007BBB4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8007BBB8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8007BBBC: beq         $v0, $zero, L_8007BBCC
    if (ctx->r2 == 0) {
        // 0x8007BBC0: sw          $s1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r17;
            goto L_8007BBCC;
    }
    // 0x8007BBC0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8007BBC4: bne         $a0, $zero, L_8007BD4C
    if (ctx->r4 != 0) {
        // 0x8007BBC8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8007BD4C;
    }
    // 0x8007BBC8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007BBCC:
    // 0x8007BBCC: jal         0x80079D24
    // 0x8007BBD0: andi        $s7, $s0, 0xFFFF
    ctx->r23 = ctx->r16 & 0XFFFF;
    func_80079D24(rdram, ctx);
        goto after_0;
    // 0x8007BBD0: andi        $s7, $s0, 0xFFFF
    ctx->r23 = ctx->r16 & 0XFFFF;
    after_0:
    // 0x8007BBD4: sll         $s0, $s0, 5
    ctx->r16 = S32(ctx->r16 << 5);
    // 0x8007BBD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007BBDC: addiu       $s1, $s2, 0x26
    ctx->r17 = ADD32(ctx->r18, 0X26);
L_8007BBE0:
    // 0x8007BBE0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8007BBE4: lbu         $v0, -0x7450($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7450);
    // 0x8007BBE8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8007BBEC: bne         $v0, $t0, L_8007BC04
    if (ctx->r2 != ctx->r8) {
        // 0x8007BBF0: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_8007BC04;
    }
    // 0x8007BBF0: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8007BBF4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8007BBF8: lw          $v0, 0x2720($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2720);
    // 0x8007BBFC: beql        $v0, $s3, L_8007BC74
    if (ctx->r2 == ctx->r19) {
        // 0x8007BC00: addu        $s1, $s1, $s3
        ctx->r17 = ADD32(ctx->r17, ctx->r19);
            goto L_8007BC74;
    }
    goto skip_0;
    // 0x8007BC00: addu        $s1, $s1, $s3
    ctx->r17 = ADD32(ctx->r17, ctx->r19);
    skip_0:
L_8007BC04:
    // 0x8007BC04: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8007BC08: sb          $t0, -0x7450($at)
    MEM_B(-0X7450, ctx->r1) = ctx->r8;
    // 0x8007BC0C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8007BC10: sw          $s3, 0x2720($at)
    MEM_W(0X2720, ctx->r1) = ctx->r19;
    // 0x8007BC14: blez        $s3, L_8007BC34
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8007BC18: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8007BC34;
    }
    // 0x8007BC18: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8007BC1C:
    // 0x8007BC1C: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x8007BC20: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007BC24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007BC28: slt         $v0, $v1, $s3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8007BC2C: bne         $v0, $zero, L_8007BC1C
    if (ctx->r2 != 0) {
        // 0x8007BC30: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8007BC1C;
    }
    // 0x8007BC30: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8007BC34:
    // 0x8007BC34: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007BC38: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007BC3C: sw          $t0, 0x328C($at)
    MEM_W(0X328C, ctx->r1) = ctx->r8;
    // 0x8007BC40: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8007BC44: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
    // 0x8007BC48: sb          $t0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r8;
    // 0x8007BC4C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007BC50: sb          $t0, -0x24($s1)
    MEM_B(-0X24, ctx->r17) = ctx->r8;
    // 0x8007BC54: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8007BC58: sb          $t0, -0x23($s1)
    MEM_B(-0X23, ctx->r17) = ctx->r8;
    // 0x8007BC5C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8007BC60: sb          $v0, -0x25($s1)
    MEM_B(-0X25, ctx->r17) = ctx->r2;
    // 0x8007BC64: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x8007BC68: sb          $t0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r8;
    // 0x8007BC6C: j           L_8007BC78
    // 0x8007BC70: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
        goto L_8007BC78;
    // 0x8007BC70: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
L_8007BC74:
    // 0x8007BC74: addu        $s2, $s2, $s3
    ctx->r18 = ADD32(ctx->r18, ctx->r19);
L_8007BC78:
    // 0x8007BC78: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x8007BC7C: srl         $v0, $s7, 3
    ctx->r2 = S32(U32(ctx->r23) >> 3);
    // 0x8007BC80: jal         0x8007BD80
    // 0x8007BC84: sb          $v0, -0x22($s1)
    MEM_B(-0X22, ctx->r17) = ctx->r2;
    func_8007BD80(rdram, ctx);
        goto after_1;
    // 0x8007BC84: sb          $v0, -0x22($s1)
    MEM_B(-0X22, ctx->r17) = ctx->r2;
    after_1:
    // 0x8007BC88: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // 0x8007BC8C: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x8007BC90: addiu       $a1, $s2, 0x6
    ctx->r5 = ADD32(ctx->r18, 0X6);
    // 0x8007BC94: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8007BC98: or          $v0, $v0, $t0
    ctx->r2 = ctx->r2 | ctx->r8;
    // 0x8007BC9C: jal         0x80072BD0
    // 0x8007BCA0: sb          $v0, -0x21($s1)
    MEM_B(-0X21, ctx->r17) = ctx->r2;
    func_80072BD0(rdram, ctx);
        goto after_2;
    // 0x8007BCA0: sb          $v0, -0x21($s1)
    MEM_B(-0X21, ctx->r17) = ctx->r2;
    after_2:
    // 0x8007BCA4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8007BCA8: addiu       $a1, $a1, 0x3250
    ctx->r5 = ADD32(ctx->r5, 0X3250);
    // 0x8007BCAC: jal         0x80074C60
    // 0x8007BCB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80074C60(rdram, ctx);
        goto after_3;
    // 0x8007BCB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8007BCB4: jal         0x8007BDEC
    // 0x8007BCB8: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    func_8007BDEC(rdram, ctx);
        goto after_4;
    // 0x8007BCB8: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    after_4:
    // 0x8007BCBC: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8007BCC0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007BCC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007BCC8: jal         0x80070620
    // 0x8007BCCC: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8007BCCC: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    after_5:
    // 0x8007BCD0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8007BCD4: addiu       $a1, $a1, 0x3250
    ctx->r5 = ADD32(ctx->r5, 0X3250);
    // 0x8007BCD8: jal         0x80074C60
    // 0x8007BCDC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80074C60(rdram, ctx);
        goto after_6;
    // 0x8007BCDC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_6:
    // 0x8007BCE0: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8007BCE4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007BCE8: jal         0x80070620
    // 0x8007BCEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x8007BCEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x8007BCF0: lbu         $v0, -0x24($s1)
    ctx->r2 = MEM_BU(ctx->r17, -0X24);
    // 0x8007BCF4: andi        $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 & 0XC0;
    // 0x8007BCF8: srl         $s0, $v0, 4
    ctx->r16 = S32(U32(ctx->r2) >> 4);
    // 0x8007BCFC: bnel        $s0, $zero, L_8007BD2C
    if (ctx->r16 != 0) {
        // 0x8007BD00: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_8007BD2C;
    }
    goto skip_1;
    // 0x8007BD00: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_1:
    // 0x8007BD04: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x8007BD08: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x8007BD0C: beq         $v0, $v1, L_8007BD2C
    if (ctx->r2 == ctx->r3) {
        // 0x8007BD10: addu        $a0, $s6, $zero
        ctx->r4 = ADD32(ctx->r22, 0);
            goto L_8007BD2C;
    }
    // 0x8007BD10: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8007BD14: jal         0x8007CAA0
    // 0x8007BD18: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8007CAA0(rdram, ctx);
        goto after_8;
    // 0x8007BD18: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_8:
    // 0x8007BD1C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8007BD20: bne         $s0, $zero, L_8007BD40
    if (ctx->r16 != 0) {
        // 0x8007BD24: nop
    
            goto L_8007BD40;
    }
    // 0x8007BD24: nop

    // 0x8007BD28: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_8007BD2C:
    // 0x8007BD2C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8007BD30: bne         $s0, $v0, L_8007BD40
    if (ctx->r16 != ctx->r2) {
        // 0x8007BD34: addu        $v0, $s5, $zero
        ctx->r2 = ADD32(ctx->r21, 0);
            goto L_8007BD40;
    }
    // 0x8007BD34: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // 0x8007BD38: bgez        $v0, L_8007BBE0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007BD3C: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_8007BBE0;
    }
    // 0x8007BD3C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_8007BD40:
    // 0x8007BD40: jal         0x80079D90
    // 0x8007BD44: nop

    func_80079D90(rdram, ctx);
        goto after_9;
    // 0x8007BD44: nop

    after_9:
    // 0x8007BD48: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8007BD4C:
    // 0x8007BD4C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8007BD50: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8007BD54: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8007BD58: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8007BD5C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8007BD60: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8007BD64: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8007BD68: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8007BD6C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8007BD70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007BD74: jr          $ra
    // 0x8007BD78: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007BD78: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8007BD7C: nop

;}
RECOMP_FUNC void func_8007BD80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BD80: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8007BD84: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x8007BD88: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8007BD8C: and         $v0, $a0, $a1
    ctx->r2 = ctx->r4 & ctx->r5;
L_8007BD90:
    // 0x8007BD90: beq         $v0, $zero, L_8007BDAC
    if (ctx->r2 == 0) {
        // 0x8007BD94: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_8007BDAC;
    }
    // 0x8007BD94: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8007BD98: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x8007BD9C: beql        $v0, $zero, L_8007BDB8
    if (ctx->r2 == 0) {
        // 0x8007BDA0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8007BDB8;
    }
    goto skip_0;
    // 0x8007BDA0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8007BDA4: j           L_8007BDB8
    // 0x8007BDA8: xori        $v1, $v1, 0x14
    ctx->r3 = ctx->r3 ^ 0X14;
        goto L_8007BDB8;
    // 0x8007BDA8: xori        $v1, $v1, 0x14
    ctx->r3 = ctx->r3 ^ 0X14;
L_8007BDAC:
    // 0x8007BDAC: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x8007BDB0: bnel        $v0, $zero, L_8007BDB8
    if (ctx->r2 != 0) {
        // 0x8007BDB4: xori        $v1, $v1, 0x15
        ctx->r3 = ctx->r3 ^ 0X15;
            goto L_8007BDB8;
    }
    goto skip_1;
    // 0x8007BDB4: xori        $v1, $v1, 0x15
    ctx->r3 = ctx->r3 ^ 0X15;
    skip_1:
L_8007BDB8:
    // 0x8007BDB8: srl         $a1, $a1, 1
    ctx->r5 = S32(U32(ctx->r5) >> 1);
    // 0x8007BDBC: bne         $a1, $zero, L_8007BD90
    if (ctx->r5 != 0) {
        // 0x8007BDC0: and         $v0, $a0, $a1
        ctx->r2 = ctx->r4 & ctx->r5;
            goto L_8007BD90;
    }
    // 0x8007BDC0: and         $v0, $a0, $a1
    ctx->r2 = ctx->r4 & ctx->r5;
    // 0x8007BDC4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8007BDC8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_8007BDCC:
    // 0x8007BDCC: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x8007BDD0: bnel        $v0, $zero, L_8007BDD8
    if (ctx->r2 != 0) {
        // 0x8007BDD4: xori        $v1, $v1, 0x15
        ctx->r3 = ctx->r3 ^ 0X15;
            goto L_8007BDD8;
    }
    goto skip_2;
    // 0x8007BDD4: xori        $v1, $v1, 0x15
    ctx->r3 = ctx->r3 ^ 0X15;
    skip_2:
L_8007BDD8:
    // 0x8007BDD8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8007BDDC: bnel        $a1, $zero, L_8007BDCC
    if (ctx->r5 != 0) {
        // 0x8007BDE0: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_8007BDCC;
    }
    goto skip_3;
    // 0x8007BDE0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    skip_3:
    // 0x8007BDE4: jr          $ra
    // 0x8007BDE8: andi        $v0, $v1, 0x1F
    ctx->r2 = ctx->r3 & 0X1F;
    return;
    // 0x8007BDE8: andi        $v0, $v1, 0x1F
    ctx->r2 = ctx->r3 & 0X1F;
;}
RECOMP_FUNC void func_8007BDEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BDEC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8007BDF0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
L_8007BDF4:
    // 0x8007BDF4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x8007BDF8: lbu         $a3, 0x0($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X0);
    // 0x8007BDFC: and         $v0, $a3, $a1
    ctx->r2 = ctx->r7 & ctx->r5;
L_8007BE00:
    // 0x8007BE00: beq         $v0, $zero, L_8007BE1C
    if (ctx->r2 == 0) {
        // 0x8007BE04: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_8007BE1C;
    }
    // 0x8007BE04: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8007BE08: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8007BE0C: beql        $v0, $zero, L_8007BE28
    if (ctx->r2 == 0) {
        // 0x8007BE10: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8007BE28;
    }
    goto skip_0;
    // 0x8007BE10: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8007BE14: j           L_8007BE28
    // 0x8007BE18: xori        $v1, $v1, 0x84
    ctx->r3 = ctx->r3 ^ 0X84;
        goto L_8007BE28;
    // 0x8007BE18: xori        $v1, $v1, 0x84
    ctx->r3 = ctx->r3 ^ 0X84;
L_8007BE1C:
    // 0x8007BE1C: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8007BE20: bnel        $v0, $zero, L_8007BE28
    if (ctx->r2 != 0) {
        // 0x8007BE24: xori        $v1, $v1, 0x85
        ctx->r3 = ctx->r3 ^ 0X85;
            goto L_8007BE28;
    }
    goto skip_1;
    // 0x8007BE24: xori        $v1, $v1, 0x85
    ctx->r3 = ctx->r3 ^ 0X85;
    skip_1:
L_8007BE28:
    // 0x8007BE28: srl         $a1, $a1, 1
    ctx->r5 = S32(U32(ctx->r5) >> 1);
    // 0x8007BE2C: bne         $a1, $zero, L_8007BE00
    if (ctx->r5 != 0) {
        // 0x8007BE30: and         $v0, $a3, $a1
        ctx->r2 = ctx->r7 & ctx->r5;
            goto L_8007BE00;
    }
    // 0x8007BE30: and         $v0, $a3, $a1
    ctx->r2 = ctx->r7 & ctx->r5;
    // 0x8007BE34: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8007BE38: bne         $a2, $zero, L_8007BDF4
    if (ctx->r6 != 0) {
        // 0x8007BE3C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8007BDF4;
    }
    // 0x8007BE3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007BE40: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_8007BE44:
    // 0x8007BE44: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8007BE48: bnel        $v0, $zero, L_8007BE50
    if (ctx->r2 != 0) {
        // 0x8007BE4C: xori        $v1, $v1, 0x85
        ctx->r3 = ctx->r3 ^ 0X85;
            goto L_8007BE50;
    }
    goto skip_2;
    // 0x8007BE4C: xori        $v1, $v1, 0x85
    ctx->r3 = ctx->r3 ^ 0X85;
    skip_2:
L_8007BE50:
    // 0x8007BE50: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8007BE54: sltiu       $v0, $a2, 0x8
    ctx->r2 = ctx->r6 < 0X8 ? 1 : 0;
    // 0x8007BE58: bnel        $v0, $zero, L_8007BE44
    if (ctx->r2 != 0) {
        // 0x8007BE5C: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_8007BE44;
    }
    goto skip_3;
    // 0x8007BE5C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    skip_3:
    // 0x8007BE60: jr          $ra
    // 0x8007BE64: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x8007BE64: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8007BE68: nop

    // 0x8007BE6C: nop

;}
RECOMP_FUNC void func_8007C380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C380: addiu       $sp, $sp, -0x4A0
    ctx->r29 = ADD32(ctx->r29, -0X4A0);
    // 0x8007C384: sw          $s1, 0x47C($sp)
    MEM_W(0X47C, ctx->r29) = ctx->r17;
    // 0x8007C388: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8007C38C: sw          $fp, 0x498($sp)
    MEM_W(0X498, ctx->r29) = ctx->r30;
    // 0x8007C390: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x8007C394: sw          $s6, 0x490($sp)
    MEM_W(0X490, ctx->r29) = ctx->r22;
    // 0x8007C398: addiu       $s6, $zero, 0xFE
    ctx->r22 = ADD32(0, 0XFE);
    // 0x8007C39C: sw          $ra, 0x49C($sp)
    MEM_W(0X49C, ctx->r29) = ctx->r31;
    // 0x8007C3A0: sw          $s7, 0x494($sp)
    MEM_W(0X494, ctx->r29) = ctx->r23;
    // 0x8007C3A4: sw          $s5, 0x48C($sp)
    MEM_W(0X48C, ctx->r29) = ctx->r21;
    // 0x8007C3A8: sw          $s4, 0x488($sp)
    MEM_W(0X488, ctx->r29) = ctx->r20;
    // 0x8007C3AC: sw          $s3, 0x484($sp)
    MEM_W(0X484, ctx->r29) = ctx->r19;
    // 0x8007C3B0: sw          $s2, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r18;
    // 0x8007C3B4: jal         0x8007B564
    // 0x8007C3B8: sw          $s0, 0x478($sp)
    MEM_W(0X478, ctx->r29) = ctx->r16;
    func_8007B564(rdram, ctx);
        goto after_0;
    // 0x8007C3B8: sw          $s0, 0x478($sp)
    MEM_W(0X478, ctx->r29) = ctx->r16;
    after_0:
    // 0x8007C3BC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8007C3C0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007C3C4: bne         $s0, $v0, L_8007C3D8
    if (ctx->r16 != ctx->r2) {
        // 0x8007C3C8: nop
    
            goto L_8007C3D8;
    }
    // 0x8007C3C8: nop

    // 0x8007C3CC: jal         0x8007B398
    // 0x8007C3D0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8007B398(rdram, ctx);
        goto after_1;
    // 0x8007C3D0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8007C3D4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_8007C3D8:
    // 0x8007C3D8: beq         $s0, $zero, L_8007C3E8
    if (ctx->r16 == 0) {
        // 0x8007C3DC: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8007C3E8;
    }
    // 0x8007C3DC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8007C3E0:
    // 0x8007C3E0: j           L_8007C7B0
    // 0x8007C3E4: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_8007C7B0;
    // 0x8007C3E4: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8007C3E8:
    // 0x8007C3E8: jal         0x8007C7E0
    // 0x8007C3EC: addiu       $a1, $sp, 0x258
    ctx->r5 = ADD32(ctx->r29, 0X258);
    func_8007C7E0(rdram, ctx);
        goto after_2;
    // 0x8007C3EC: addiu       $a1, $sp, 0x258
    ctx->r5 = ADD32(ctx->r29, 0X258);
    after_2:
    // 0x8007C3F0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8007C3F4: bne         $s0, $zero, L_8007C7B0
    if (ctx->r16 != 0) {
        // 0x8007C3F8: nop
    
            goto L_8007C7B0;
    }
    // 0x8007C3F8: nop

    // 0x8007C3FC: lw          $v0, 0x50($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X50);
    // 0x8007C400: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007C404: beq         $v0, $zero, L_8007C5B4
    if (ctx->r2 == 0) {
        // 0x8007C408: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_8007C5B4;
    }
    // 0x8007C408: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8007C40C: addiu       $s7, $sp, 0x18
    ctx->r23 = ADD32(ctx->r29, 0X18);
L_8007C410:
    // 0x8007C410: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8007C414: lw          $a2, 0x5C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X5C);
    // 0x8007C418: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8007C41C: addiu       $a3, $sp, 0x218
    ctx->r7 = ADD32(ctx->r29, 0X218);
    // 0x8007C420: addu        $a2, $a2, $s2
    ctx->r6 = ADD32(ctx->r6, ctx->r18);
    // 0x8007C424: jal         0x8007B960
    // 0x8007C428: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_8007B960(rdram, ctx);
        goto after_3;
    // 0x8007C428: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_3:
    // 0x8007C42C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8007C430: bne         $s0, $zero, L_8007C7B0
    if (ctx->r16 != 0) {
        // 0x8007C434: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8007C7B0;
    }
    // 0x8007C434: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8007C438: lhu         $v0, 0x21C($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X21C);
    // 0x8007C43C: bne         $v0, $zero, L_8007C458
    if (ctx->r2 != 0) {
        // 0x8007C440: nop
    
            goto L_8007C458;
    }
    // 0x8007C440: nop

    // 0x8007C444: lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X218);
    // 0x8007C448: beq         $v0, $zero, L_8007C5A0
    if (ctx->r2 == 0) {
        // 0x8007C44C: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_8007C5A0;
    }
    // 0x8007C44C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8007C450: j           L_8007C530
    // 0x8007C454: nop

        goto L_8007C530;
    // 0x8007C454: nop

L_8007C458:
    // 0x8007C458: lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X218);
    // 0x8007C45C: bne         $v0, $zero, L_8007C46C
    if (ctx->r2 != 0) {
        // 0x8007C460: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8007C46C;
    }
    // 0x8007C460: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007C464: j           L_8007C530
    // 0x8007C468: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_8007C530;
    // 0x8007C468: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_8007C46C:
    // 0x8007C46C: lhu         $s4, 0x21E($sp)
    ctx->r20 = MEM_HU(ctx->r29, 0X21E);
    // 0x8007C470: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x8007C474: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x8007C478: j           L_8007C510
    // 0x8007C47C: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
        goto L_8007C510;
    // 0x8007C47C: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
L_8007C480:
    // 0x8007C480: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x8007C484: sltiu       $v0, $v0, 0x80
    ctx->r2 = ctx->r2 < 0X80 ? 1 : 0;
    // 0x8007C488: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8007C48C: beq         $v1, $zero, L_8007C530
    if (ctx->r3 == 0) {
        // 0x8007C490: srl         $v1, $a0, 8
        ctx->r3 = S32(U32(ctx->r4) >> 8);
            goto L_8007C530;
    }
    // 0x8007C490: srl         $v1, $a0, 8
    ctx->r3 = S32(U32(ctx->r4) >> 8);
    // 0x8007C494: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x8007C498: andi        $a3, $v1, 0xFF
    ctx->r7 = ctx->r3 & 0XFF;
    // 0x8007C49C: beq         $v0, $a3, L_8007C4DC
    if (ctx->r2 == ctx->r7) {
        // 0x8007C4A0: andi        $v0, $s6, 0xFF
        ctx->r2 = ctx->r22 & 0XFF;
            goto L_8007C4DC;
    }
    // 0x8007C4A0: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x8007C4A4: beq         $v0, $a3, L_8007C4C4
    if (ctx->r2 == ctx->r7) {
        // 0x8007C4A8: addu        $s3, $v1, $zero
        ctx->r19 = ADD32(ctx->r3, 0);
            goto L_8007C4C4;
    }
    // 0x8007C4A8: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // 0x8007C4AC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007C4B0: addiu       $a1, $sp, 0x118
    ctx->r5 = ADD32(ctx->r29, 0X118);
    // 0x8007C4B4: jal         0x8007B61C
    // 0x8007C4B8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8007B61C(rdram, ctx);
        goto after_4;
    // 0x8007C4B8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
    // 0x8007C4BC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8007C4C0: addu        $s6, $s3, $zero
    ctx->r22 = ADD32(ctx->r19, 0);
L_8007C4C4:
    // 0x8007C4C4: sltu        $v1, $zero, $s0
    ctx->r3 = 0 < ctx->r16 ? 1 : 0;
    // 0x8007C4C8: xori        $v0, $s0, 0x3
    ctx->r2 = ctx->r16 ^ 0X3;
    // 0x8007C4CC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8007C4D0: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8007C4D4: bne         $v1, $zero, L_8007C7B0
    if (ctx->r3 != 0) {
        // 0x8007C4D8: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8007C7B0;
    }
    // 0x8007C4D8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8007C4DC:
    // 0x8007C4DC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007C4E0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8007C4E4: addiu       $a2, $sp, 0x258
    ctx->r6 = ADD32(ctx->r29, 0X258);
    // 0x8007C4E8: jal         0x8007C938
    // 0x8007C4EC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    func_8007C938(rdram, ctx);
        goto after_5;
    // 0x8007C4EC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    after_5:
    // 0x8007C4F0: subu        $a1, $v0, $s5
    ctx->r5 = SUB32(ctx->r2, ctx->r21);
    // 0x8007C4F4: bne         $a1, $zero, L_8007C548
    if (ctx->r5 != 0) {
        // 0x8007C4F8: andi        $v0, $s4, 0xFF
        ctx->r2 = ctx->r20 & 0XFF;
            goto L_8007C548;
    }
    // 0x8007C4F8: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x8007C4FC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8007C500: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8007C504: lhu         $s4, 0x100($v0)
    ctx->r20 = MEM_HU(ctx->r2, 0X100);
    // 0x8007C508: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x8007C50C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_8007C510:
    // 0x8007C510: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    // 0x8007C514: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007C518: bne         $v0, $zero, L_8007C530
    if (ctx->r2 != 0) {
        // 0x8007C51C: srl         $v0, $a0, 8
        ctx->r2 = S32(U32(ctx->r4) >> 8);
            goto L_8007C530;
    }
    // 0x8007C51C: srl         $v0, $a0, 8
    ctx->r2 = S32(U32(ctx->r4) >> 8);
    // 0x8007C520: lbu         $v1, 0x64($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X64);
    // 0x8007C524: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8007C528: bne         $v0, $zero, L_8007C480
    if (ctx->r2 != 0) {
        // 0x8007C52C: andi        $v0, $s4, 0xFF
        ctx->r2 = ctx->r20 & 0XFF;
            goto L_8007C480;
    }
    // 0x8007C52C: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
L_8007C530:
    // 0x8007C530: bnel        $a1, $zero, L_8007C54C
    if (ctx->r5 != 0) {
        // 0x8007C534: addiu       $a0, $sp, 0x218
        ctx->r4 = ADD32(ctx->r29, 0X218);
            goto L_8007C54C;
    }
    goto skip_0;
    // 0x8007C534: addiu       $a0, $sp, 0x218
    ctx->r4 = ADD32(ctx->r29, 0X218);
    skip_0:
    // 0x8007C538: andi        $v1, $s4, 0xFFFF
    ctx->r3 = ctx->r20 & 0XFFFF;
    // 0x8007C53C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007C540: beq         $v1, $v0, L_8007C5A0
    if (ctx->r3 == ctx->r2) {
        // 0x8007C544: nop
    
            goto L_8007C5A0;
    }
    // 0x8007C544: nop

L_8007C548:
    // 0x8007C548: addiu       $a0, $sp, 0x218
    ctx->r4 = ADD32(ctx->r29, 0X218);
L_8007C54C:
    // 0x8007C54C: jal         0x8007A400
    // 0x8007C550: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_8007A400(rdram, ctx);
        goto after_6;
    // 0x8007C550: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_6:
    // 0x8007C554: lbu         $v0, 0x65($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X65);
    // 0x8007C558: beq         $v0, $zero, L_8007C574
    if (ctx->r2 == 0) {
        // 0x8007C55C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8007C574;
    }
    // 0x8007C55C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007C560: jal         0x80074A60
    // 0x8007C564: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80074A60(rdram, ctx);
        goto after_7;
    // 0x8007C564: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_7:
    // 0x8007C568: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8007C56C: bne         $s0, $zero, L_8007C7B0
    if (ctx->r16 != 0) {
        // 0x8007C570: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8007C7B0;
    }
    // 0x8007C570: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8007C574:
    // 0x8007C574: lw          $a2, 0x5C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X5C);
    // 0x8007C578: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007C57C: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8007C580: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8007C584: addiu       $a3, $sp, 0x218
    ctx->r7 = ADD32(ctx->r29, 0X218);
    // 0x8007C588: addu        $a2, $a2, $s2
    ctx->r6 = ADD32(ctx->r6, ctx->r18);
    // 0x8007C58C: jal         0x8007BB60
    // 0x8007C590: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_8007BB60(rdram, ctx);
        goto after_8;
    // 0x8007C590: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_8:
    // 0x8007C594: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8007C598: bne         $s0, $zero, L_8007C3E0
    if (ctx->r16 != 0) {
        // 0x8007C59C: addiu       $fp, $fp, 0x1
        ctx->r30 = ADD32(ctx->r30, 0X1);
            goto L_8007C3E0;
    }
    // 0x8007C59C: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
L_8007C5A0:
    // 0x8007C5A0: lw          $v0, 0x50($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X50);
    // 0x8007C5A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007C5A8: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007C5AC: bne         $v0, $zero, L_8007C410
    if (ctx->r2 != 0) {
        // 0x8007C5B0: nop
    
            goto L_8007C410;
    }
    // 0x8007C5B0: nop

L_8007C5B4:
    // 0x8007C5B4: lw          $v0, 0x50($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X50);
    // 0x8007C5B8: blez        $v0, L_8007C630
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007C5BC: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_8007C630;
    }
    // 0x8007C5BC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8007C5C0: addiu       $s3, $sp, 0x238
    ctx->r19 = ADD32(ctx->r29, 0X238);
L_8007C5C4:
    // 0x8007C5C4: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8007C5C8: lw          $a2, 0x5C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X5C);
    // 0x8007C5CC: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8007C5D0: addiu       $a3, $sp, 0x218
    ctx->r7 = ADD32(ctx->r29, 0X218);
    // 0x8007C5D4: addu        $a2, $a2, $s2
    ctx->r6 = ADD32(ctx->r6, ctx->r18);
    // 0x8007C5D8: jal         0x8007B960
    // 0x8007C5DC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_8007B960(rdram, ctx);
        goto after_9;
    // 0x8007C5DC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_9:
    // 0x8007C5E0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8007C5E4: bne         $s0, $zero, L_8007C7B0
    if (ctx->r16 != 0) {
        // 0x8007C5E8: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8007C7B0;
    }
    // 0x8007C5E8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8007C5EC: lhu         $v0, 0x21C($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X21C);
    // 0x8007C5F0: beql        $v0, $zero, L_8007C61C
    if (ctx->r2 == 0) {
        // 0x8007C5F4: sh          $zero, 0x0($s3)
        MEM_H(0X0, ctx->r19) = 0;
            goto L_8007C61C;
    }
    goto skip_1;
    // 0x8007C5F4: sh          $zero, 0x0($s3)
    MEM_H(0X0, ctx->r19) = 0;
    skip_1:
    // 0x8007C5F8: lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X218);
    // 0x8007C5FC: beql        $v0, $zero, L_8007C61C
    if (ctx->r2 == 0) {
        // 0x8007C600: sh          $zero, 0x0($s3)
        MEM_H(0X0, ctx->r19) = 0;
            goto L_8007C61C;
    }
    goto skip_2;
    // 0x8007C600: sh          $zero, 0x0($s3)
    MEM_H(0X0, ctx->r19) = 0;
    skip_2:
    // 0x8007C604: lhu         $v1, 0x21E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X21E);
    // 0x8007C608: lhu         $v0, 0x62($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X62);
    // 0x8007C60C: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8007C610: bnel        $v0, $zero, L_8007C61C
    if (ctx->r2 != 0) {
        // 0x8007C614: sh          $zero, 0x0($s3)
        MEM_H(0X0, ctx->r19) = 0;
            goto L_8007C61C;
    }
    goto skip_3;
    // 0x8007C614: sh          $zero, 0x0($s3)
    MEM_H(0X0, ctx->r19) = 0;
    skip_3:
    // 0x8007C618: sh          $v1, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r3;
L_8007C61C:
    // 0x8007C61C: lw          $v0, 0x50($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X50);
    // 0x8007C620: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007C624: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007C628: bne         $v0, $zero, L_8007C5C4
    if (ctx->r2 != 0) {
        // 0x8007C62C: addiu       $s3, $s3, 0x2
        ctx->r19 = ADD32(ctx->r19, 0X2);
            goto L_8007C5C4;
    }
    // 0x8007C62C: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
L_8007C630:
    // 0x8007C630: lbu         $v0, 0x64($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X64);
    // 0x8007C634: beq         $v0, $zero, L_8007C78C
    if (ctx->r2 == 0) {
        // 0x8007C638: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_8007C78C;
    }
    // 0x8007C638: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8007C63C: addiu       $s4, $sp, 0x18
    ctx->r20 = ADD32(ctx->r29, 0X18);
    // 0x8007C640: addiu       $s6, $sp, 0x118
    ctx->r22 = ADD32(ctx->r29, 0X118);
    // 0x8007C644: addiu       $s5, $sp, 0x238
    ctx->r21 = ADD32(ctx->r29, 0X238);
    // 0x8007C648: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8007C64C:
    // 0x8007C64C: addiu       $a1, $sp, 0x118
    ctx->r5 = ADD32(ctx->r29, 0X118);
    // 0x8007C650: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007C654: andi        $s2, $s3, 0xFF
    ctx->r18 = ctx->r19 & 0XFF;
    // 0x8007C658: jal         0x8007B61C
    // 0x8007C65C: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    func_8007B61C(rdram, ctx);
        goto after_10;
    // 0x8007C65C: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_10:
    // 0x8007C660: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8007C664: sltu        $v1, $zero, $s0
    ctx->r3 = 0 < ctx->r16 ? 1 : 0;
    // 0x8007C668: xori        $v0, $s0, 0x3
    ctx->r2 = ctx->r16 ^ 0X3;
    // 0x8007C66C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8007C670: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8007C674: bnel        $v1, $zero, L_8007C7B0
    if (ctx->r3 != 0) {
        // 0x8007C678: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8007C7B0;
    }
    goto skip_4;
    // 0x8007C678: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    skip_4:
    // 0x8007C67C: bne         $s2, $zero, L_8007C688
    if (ctx->r18 != 0) {
        // 0x8007C680: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8007C688;
    }
    // 0x8007C680: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8007C684: lw          $a1, 0x60($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X60);
L_8007C688:
    // 0x8007C688: blez        $a1, L_8007C6B4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8007C68C: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_8007C6B4;
    }
    // 0x8007C68C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8007C690: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8007C694: addu        $v1, $s6, $zero
    ctx->r3 = ADD32(ctx->r22, 0);
L_8007C698:
    // 0x8007C698: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8007C69C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8007C6A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007C6A4: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8007C6A8: slt         $v0, $s2, $a1
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007C6AC: bne         $v0, $zero, L_8007C698
    if (ctx->r2 != 0) {
        // 0x8007C6B0: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_8007C698;
    }
    // 0x8007C6B0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_8007C6B4:
    // 0x8007C6B4: slti        $v0, $s2, 0x80
    ctx->r2 = SIGNED(ctx->r18) < 0X80 ? 1 : 0;
    // 0x8007C6B8: beq         $v0, $zero, L_8007C6DC
    if (ctx->r2 == 0) {
        // 0x8007C6BC: sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18 << 1);
            goto L_8007C6DC;
    }
    // 0x8007C6BC: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x8007C6C0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8007C6C4: addu        $v1, $v0, $s4
    ctx->r3 = ADD32(ctx->r2, ctx->r20);
L_8007C6C8:
    // 0x8007C6C8: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x8007C6CC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007C6D0: slti        $v0, $s2, 0x80
    ctx->r2 = SIGNED(ctx->r18) < 0X80 ? 1 : 0;
    // 0x8007C6D4: bne         $v0, $zero, L_8007C6C8
    if (ctx->r2 != 0) {
        // 0x8007C6D8: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8007C6C8;
    }
    // 0x8007C6D8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8007C6DC:
    // 0x8007C6DC: lw          $v0, 0x50($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X50);
    // 0x8007C6E0: blez        $v0, L_8007C758
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007C6E4: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_8007C758;
    }
    // 0x8007C6E4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8007C6E8: andi        $t0, $s3, 0xFF
    ctx->r8 = ctx->r19 & 0XFF;
    // 0x8007C6EC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007C6F0: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
L_8007C6F4:
    // 0x8007C6F4: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x8007C6F8: bne         $v0, $t0, L_8007C740
    if (ctx->r2 != ctx->r8) {
        // 0x8007C6FC: addu        $a1, $s5, $zero
        ctx->r5 = ADD32(ctx->r21, 0);
            goto L_8007C740;
    }
    // 0x8007C6FC: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
L_8007C700:
    // 0x8007C700: addu        $a0, $a1, $a2
    ctx->r4 = ADD32(ctx->r5, ctx->r6);
    // 0x8007C704: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8007C708: lhu         $v0, 0x62($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X62);
    // 0x8007C70C: sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8007C710: bnel        $v1, $zero, L_8007C744
    if (ctx->r3 != 0) {
        // 0x8007C714: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_8007C744;
    }
    goto skip_5;
    // 0x8007C714: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    skip_5:
    // 0x8007C718: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8007C71C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8007C720: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8007C724: lhu         $v1, 0x100($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X100);
    // 0x8007C728: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x8007C72C: addu        $v0, $a2, $s4
    ctx->r2 = ADD32(ctx->r6, ctx->r20);
    // 0x8007C730: sh          $v1, 0x220($v0)
    MEM_H(0X220, ctx->r2) = ctx->r3;
    // 0x8007C734: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8007C738: beq         $v0, $t0, L_8007C700
    if (ctx->r2 == ctx->r8) {
        // 0x8007C73C: nop
    
            goto L_8007C700;
    }
    // 0x8007C73C: nop

L_8007C740:
    // 0x8007C740: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8007C744:
    // 0x8007C744: lw          $v0, 0x50($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X50);
    // 0x8007C748: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007C74C: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007C750: bne         $v0, $zero, L_8007C6F4
    if (ctx->r2 != 0) {
        // 0x8007C754: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_8007C6F4;
    }
    // 0x8007C754: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
L_8007C758:
    // 0x8007C758: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007C75C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8007C760: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007C764: jal         0x8007B61C
    // 0x8007C768: andi        $a3, $s3, 0xFF
    ctx->r7 = ctx->r19 & 0XFF;
    func_8007B61C(rdram, ctx);
        goto after_11;
    // 0x8007C768: andi        $a3, $s3, 0xFF
    ctx->r7 = ctx->r19 & 0XFF;
    after_11:
    // 0x8007C76C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8007C770: bne         $s0, $zero, L_8007C3E0
    if (ctx->r16 != 0) {
        // 0x8007C774: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8007C3E0;
    }
    // 0x8007C774: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8007C778: lbu         $v1, 0x64($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X64);
    // 0x8007C77C: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x8007C780: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8007C784: bne         $v0, $zero, L_8007C64C
    if (ctx->r2 != 0) {
        // 0x8007C788: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8007C64C;
    }
    // 0x8007C788: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8007C78C:
    // 0x8007C78C: beq         $fp, $zero, L_8007C7A0
    if (ctx->r30 == 0) {
        // 0x8007C790: addiu       $v1, $zero, -0x3
        ctx->r3 = ADD32(0, -0X3);
            goto L_8007C7A0;
    }
    // 0x8007C790: addiu       $v1, $zero, -0x3
    ctx->r3 = ADD32(0, -0X3);
    // 0x8007C794: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8007C798: j           L_8007C7A8
    // 0x8007C79C: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
        goto L_8007C7A8;
    // 0x8007C79C: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
L_8007C7A0:
    // 0x8007C7A0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8007C7A4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
L_8007C7A8:
    // 0x8007C7A8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8007C7AC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007C7B0:
    // 0x8007C7B0: lw          $ra, 0x49C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X49C);
    // 0x8007C7B4: lw          $fp, 0x498($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X498);
    // 0x8007C7B8: lw          $s7, 0x494($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X494);
    // 0x8007C7BC: lw          $s6, 0x490($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X490);
    // 0x8007C7C0: lw          $s5, 0x48C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48C);
    // 0x8007C7C4: lw          $s4, 0x488($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X488);
    // 0x8007C7C8: lw          $s3, 0x484($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X484);
    // 0x8007C7CC: lw          $s2, 0x480($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X480);
    // 0x8007C7D0: lw          $s1, 0x47C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X47C);
    // 0x8007C7D4: lw          $s0, 0x478($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X478);
    // 0x8007C7D8: jr          $ra
    // 0x8007C7DC: addiu       $sp, $sp, 0x4A0
    ctx->r29 = ADD32(ctx->r29, 0X4A0);
    return;
    // 0x8007C7DC: addiu       $sp, $sp, 0x4A0
    ctx->r29 = ADD32(ctx->r29, 0X4A0);
;}
RECOMP_FUNC void func_8007C7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C7E0: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x8007C7E4: sw          $s2, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r18;
    // 0x8007C7E8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8007C7EC: sw          $s4, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r20;
    // 0x8007C7F0: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8007C7F4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8007C7F8: addiu       $v0, $s4, 0xFF
    ctx->r2 = ADD32(ctx->r20, 0XFF);
    // 0x8007C7FC: sw          $ra, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r31;
    // 0x8007C800: sw          $s6, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r22;
    // 0x8007C804: sw          $s5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r21;
    // 0x8007C808: sw          $s3, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r19;
    // 0x8007C80C: sw          $s1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r17;
    // 0x8007C810: sw          $s0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r16;
L_8007C814:
    // 0x8007C814: sb          $zero, 0x101($v0)
    MEM_B(0X101, ctx->r2) = 0;
    // 0x8007C818: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8007C81C: bgez        $a1, L_8007C814
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8007C820: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8007C814;
    }
    // 0x8007C820: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8007C824: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8007C828: sb          $v0, 0x100($s4)
    MEM_B(0X100, ctx->r20) = ctx->r2;
    // 0x8007C82C: lbu         $v0, 0x64($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X64);
    // 0x8007C830: beq         $v0, $zero, L_8007C90C
    if (ctx->r2 == 0) {
        // 0x8007C834: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_8007C90C;
    }
    // 0x8007C834: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8007C838: addiu       $s5, $sp, 0x10
    ctx->r21 = ADD32(ctx->r29, 0X10);
    // 0x8007C83C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8007C840: andi        $s0, $s3, 0xFF
    ctx->r16 = ctx->r19 & 0XFF;
L_8007C844:
    // 0x8007C844: bne         $s0, $zero, L_8007C850
    if (ctx->r16 != 0) {
        // 0x8007C848: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_8007C850;
    }
    // 0x8007C848: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8007C84C: lw          $s1, 0x60($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X60);
L_8007C850:
    // 0x8007C850: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8007C854: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8007C858: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007C85C: jal         0x8007B61C
    // 0x8007C860: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_8007B61C(rdram, ctx);
        goto after_0;
    // 0x8007C860: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8007C864: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8007C868: sltu        $v1, $zero, $a0
    ctx->r3 = 0 < ctx->r4 ? 1 : 0;
    // 0x8007C86C: xori        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 ^ 0X3;
    // 0x8007C870: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8007C874: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8007C878: bne         $v1, $zero, L_8007C910
    if (ctx->r3 != 0) {
        // 0x8007C87C: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_8007C910;
    }
    // 0x8007C87C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x8007C880: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8007C884: slti        $v0, $a1, 0x80
    ctx->r2 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x8007C888: beq         $v0, $zero, L_8007C8F4
    if (ctx->r2 == 0) {
        // 0x8007C88C: andi        $v0, $s0, 0x7
        ctx->r2 = ctx->r16 & 0X7;
            goto L_8007C8F4;
    }
    // 0x8007C88C: andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
    // 0x8007C890: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x8007C894: sllv        $t0, $s6, $v0
    ctx->r8 = S32(ctx->r22 << (ctx->r2 & 31));
    // 0x8007C898: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8007C89C: addu        $a2, $v0, $s5
    ctx->r6 = ADD32(ctx->r2, ctx->r21);
L_8007C8A0:
    // 0x8007C8A0: lhu         $a0, 0x0($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X0);
    // 0x8007C8A4: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x8007C8A8: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8007C8AC: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007C8B0: bne         $v0, $zero, L_8007C8E8
    if (ctx->r2 != 0) {
        // 0x8007C8B4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8007C8E8;
    }
    // 0x8007C8B4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007C8B8: srl         $v1, $v1, 8
    ctx->r3 = S32(U32(ctx->r3) >> 8);
    // 0x8007C8BC: beq         $v1, $a3, L_8007C8E8
    if (ctx->r3 == ctx->r7) {
        // 0x8007C8C0: nop
    
            goto L_8007C8E8;
    }
    // 0x8007C8C0: nop

    // 0x8007C8C4: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8007C8C8: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x8007C8CC: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8007C8D0: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x8007C8D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007C8D8: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x8007C8DC: lbu         $v1, 0x101($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X101);
    // 0x8007C8E0: or          $v1, $v1, $t0
    ctx->r3 = ctx->r3 | ctx->r8;
    // 0x8007C8E4: sb          $v1, 0x101($v0)
    MEM_B(0X101, ctx->r2) = ctx->r3;
L_8007C8E8:
    // 0x8007C8E8: slti        $v0, $a1, 0x80
    ctx->r2 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x8007C8EC: bne         $v0, $zero, L_8007C8A0
    if (ctx->r2 != 0) {
        // 0x8007C8F0: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_8007C8A0;
    }
    // 0x8007C8F0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8007C8F4:
    // 0x8007C8F4: lbu         $v1, 0x64($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X64);
    // 0x8007C8F8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8007C8FC: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x8007C900: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8007C904: bne         $v0, $zero, L_8007C844
    if (ctx->r2 != 0) {
        // 0x8007C908: andi        $s0, $s3, 0xFF
        ctx->r16 = ctx->r19 & 0XFF;
            goto L_8007C844;
    }
    // 0x8007C908: andi        $s0, $s3, 0xFF
    ctx->r16 = ctx->r19 & 0XFF;
L_8007C90C:
    // 0x8007C90C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007C910:
    // 0x8007C910: lw          $ra, 0x12C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X12C);
    // 0x8007C914: lw          $s6, 0x128($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X128);
    // 0x8007C918: lw          $s5, 0x124($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X124);
    // 0x8007C91C: lw          $s4, 0x120($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X120);
    // 0x8007C920: lw          $s3, 0x11C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X11C);
    // 0x8007C924: lw          $s2, 0x118($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X118);
    // 0x8007C928: lw          $s1, 0x114($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X114);
    // 0x8007C92C: lw          $s0, 0x110($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X110);
    // 0x8007C930: jr          $ra
    // 0x8007C934: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x8007C934: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}
RECOMP_FUNC void func_8007C938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C938: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // FALLTHROUGH: func_8007C938 falls into func_8007C93C
    func_8007C93C(rdram, ctx);
;}
RECOMP_FUNC void func_8007C93C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C93C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007C940: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007C944: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8007C948: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007C94C: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x8007C950: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007C954: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8007C958: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007C95C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8007C960: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x8007C964: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x8007C968: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8007C96C: srl         $a2, $a1, 8
    ctx->r6 = S32(U32(ctx->r5) >> 8);
    // 0x8007C970: andi        $v0, $a2, 0x7
    ctx->r2 = ctx->r6 & 0X7;
    // 0x8007C974: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x8007C978: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8007C97C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8007C980: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8007C984: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007C988: lbu         $a0, 0x64($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X64);
    // 0x8007C98C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8007C990: beq         $a0, $zero, L_8007CA70
    if (ctx->r4 == 0) {
        // 0x8007C994: addu        $s7, $v1, $v0
        ctx->r23 = ADD32(ctx->r3, ctx->r2);
            goto L_8007CA70;
    }
    // 0x8007C994: addu        $s7, $v1, $v0
    ctx->r23 = ADD32(ctx->r3, ctx->r2);
    // 0x8007C998: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x8007C99C: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x8007C9A0: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
L_8007C9A4:
    // 0x8007C9A4: bne         $a3, $zero, L_8007C9B0
    if (ctx->r7 != 0) {
        // 0x8007C9A8: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_8007C9B0;
    }
    // 0x8007C9A8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8007C9AC: lw          $s3, 0x60($s4)
    ctx->r19 = MEM_W(ctx->r20, 0X60);
L_8007C9B0:
    // 0x8007C9B0: beq         $a3, $s6, L_8007C9D0
    if (ctx->r7 == ctx->r22) {
        // 0x8007C9B4: addu        $v0, $s1, $s7
        ctx->r2 = ADD32(ctx->r17, ctx->r23);
            goto L_8007C9D0;
    }
    // 0x8007C9B4: addu        $v0, $s1, $s7
    ctx->r2 = ADD32(ctx->r17, ctx->r23);
    // 0x8007C9B8: lbu         $v0, 0x101($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X101);
    // 0x8007C9BC: andi        $v1, $a3, 0x7
    ctx->r3 = ctx->r7 & 0X7;
    // 0x8007C9C0: srav        $v0, $v0, $v1
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r3 & 31));
    // 0x8007C9C4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8007C9C8: beq         $v0, $zero, L_8007CA58
    if (ctx->r2 == 0) {
        // 0x8007C9CC: nop
    
            goto L_8007CA58;
    }
    // 0x8007C9CC: nop

L_8007C9D0:
    // 0x8007C9D0: lbu         $v0, 0x100($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X100);
    // 0x8007C9D4: beq         $a3, $v0, L_8007CA08
    if (ctx->r7 == ctx->r2) {
        // 0x8007C9D8: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_8007CA08;
    }
    // 0x8007C9D8: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8007C9DC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8007C9E0: jal         0x8007B61C
    // 0x8007C9E4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8007B61C(rdram, ctx);
        goto after_0;
    // 0x8007C9E4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x8007C9E8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8007C9EC: sltu        $v1, $zero, $a0
    ctx->r3 = 0 < ctx->r4 ? 1 : 0;
    // 0x8007C9F0: xori        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 ^ 0X3;
    // 0x8007C9F4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8007C9F8: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8007C9FC: bne         $v1, $zero, L_8007CA74
    if (ctx->r3 != 0) {
        // 0x8007CA00: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_8007CA74;
    }
    // 0x8007CA00: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x8007CA04: sb          $s2, 0x100($s1)
    MEM_B(0X100, ctx->r17) = ctx->r18;
L_8007CA08:
    // 0x8007CA08: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007CA0C: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8007CA10: slti        $v1, $a1, 0x80
    ctx->r3 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x8007CA14: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8007CA18: beq         $v0, $zero, L_8007CA4C
    if (ctx->r2 == 0) {
        // 0x8007CA1C: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_8007CA4C;
    }
    // 0x8007CA1C: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8007CA20: addu        $a0, $v0, $s1
    ctx->r4 = ADD32(ctx->r2, ctx->r17);
L_8007CA24:
    // 0x8007CA24: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8007CA28: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007CA2C: slti        $v1, $a1, 0x80
    ctx->r3 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x8007CA30: xor         $v0, $v0, $s5
    ctx->r2 = ctx->r2 ^ ctx->r21;
    // 0x8007CA34: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007CA38: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8007CA3C: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8007CA40: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8007CA44: bne         $v0, $zero, L_8007CA24
    if (ctx->r2 != 0) {
        // 0x8007CA48: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_8007CA24;
    }
    // 0x8007CA48: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_8007CA4C:
    // 0x8007CA4C: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8007CA50: beq         $v0, $zero, L_8007CA74
    if (ctx->r2 == 0) {
        // 0x8007CA54: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8007CA74;
    }
    // 0x8007CA54: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8007CA58:
    // 0x8007CA58: lbu         $v1, 0x64($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X64);
    // 0x8007CA5C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007CA60: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x8007CA64: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8007CA68: bne         $v0, $zero, L_8007C9A4
    if (ctx->r2 != 0) {
        // 0x8007CA6C: andi        $a3, $s2, 0xFF
        ctx->r7 = ctx->r18 & 0XFF;
            goto L_8007C9A4;
    }
    // 0x8007CA6C: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
L_8007CA70:
    // 0x8007CA70: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8007CA74:
    // 0x8007CA74: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x8007CA78: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8007CA7C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8007CA80: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8007CA84: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007CA88: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8007CA8C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007CA90: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CA94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007CA98: jr          $ra
    // 0x8007CA9C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8007CA9C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8007CAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CAA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007CAA4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8007CAA8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8007CAAC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8007CAB0: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8007CAB4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007CAB8: addiu       $v0, $zero, 0xFA
    ctx->r2 = ADD32(0, 0XFA);
    // 0x8007CABC: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8007CAC0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8007CAC4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007CAC8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8007CACC: sb          $v0, 0x2714($at)
    MEM_B(0X2714, ctx->r1) = ctx->r2;
    // 0x8007CAD0: jal         0x8007CB90
    // 0x8007CAD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8007CB90(rdram, ctx);
        goto after_0;
    // 0x8007CAD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8007CAD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007CADC: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8007CAE0: addiu       $s1, $s1, 0x3250
    ctx->r17 = ADD32(ctx->r17, 0X3250);
    // 0x8007CAE4: jal         0x80074C60
    // 0x8007CAE8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80074C60(rdram, ctx);
        goto after_1;
    // 0x8007CAE8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8007CAEC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8007CAF0: addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // 0x8007CAF4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007CAF8: jal         0x80070620
    // 0x8007CAFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8007CAFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8007CB00: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007CB04: jal         0x80074C60
    // 0x8007CB08: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80074C60(rdram, ctx);
        goto after_3;
    // 0x8007CB08: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
    // 0x8007CB0C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8007CB10: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007CB14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007CB18: jal         0x80070620
    // 0x8007CB1C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8007CB1C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_4:
    // 0x8007CB20: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007CB24: jal         0x8007CC24
    // 0x8007CB28: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8007CC24(rdram, ctx);
        goto after_5;
    // 0x8007CB28: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x8007CB2C: lbu         $v1, 0x12($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X12);
    // 0x8007CB30: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8007CB34: beq         $v0, $zero, L_8007CB44
    if (ctx->r2 == 0) {
        // 0x8007CB38: andi        $v0, $v1, 0x2
        ctx->r2 = ctx->r3 & 0X2;
            goto L_8007CB44;
    }
    // 0x8007CB38: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x8007CB3C: bne         $v0, $zero, L_8007CB74
    if (ctx->r2 != 0) {
        // 0x8007CB40: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8007CB74;
    }
    // 0x8007CB40: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8007CB44:
    // 0x8007CB44: lhu         $v0, 0x12($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X12);
    // 0x8007CB48: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // 0x8007CB4C: andi        $v0, $v0, 0x1FF
    ctx->r2 = ctx->r2 & 0X1FF;
    // 0x8007CB50: beq         $v0, $v1, L_8007CB60
    if (ctx->r2 == ctx->r3) {
        // 0x8007CB54: nop
    
            goto L_8007CB60;
    }
    // 0x8007CB54: nop

    // 0x8007CB58: j           L_8007CB74
    // 0x8007CB5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007CB74;
    // 0x8007CB5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007CB60:
    // 0x8007CB60: lbu         $v1, 0x12($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X12);
    // 0x8007CB64: andi        $v1, $v1, 0x4
    ctx->r3 = ctx->r3 & 0X4;
    // 0x8007CB68: bne         $v1, $zero, L_8007CB74
    if (ctx->r3 != 0) {
        // 0x8007CB6C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8007CB74;
    }
    // 0x8007CB6C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8007CB70: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8007CB74:
    // 0x8007CB74: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8007CB78: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8007CB7C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8007CB80: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8007CB84: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007CB88: jr          $ra
    // 0x8007CB8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007CB8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8007CB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CB90: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8007CB94: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8007CB98: addiu       $v1, $v1, 0x328C
    ctx->r3 = ADD32(ctx->r3, 0X328C);
    // 0x8007CB9C: addiu       $a2, $v1, -0x3C
    ctx->r6 = ADD32(ctx->r3, -0X3C);
    // 0x8007CBA0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8007CBA4: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x8007CBA8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8007CBAC: sb          $v0, -0x7450($at)
    MEM_B(-0X7450, ctx->r1) = ctx->r2;
    // 0x8007CBB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007CBB4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8007CBB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007CBBC: sb          $v0, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r2;
    // 0x8007CBC0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8007CBC4: sb          $v0, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r2;
    // 0x8007CBC8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8007CBCC: sb          $a1, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r5;
    // 0x8007CBD0: sb          $v0, 0x3($sp)
    MEM_B(0X3, ctx->r29) = ctx->r2;
    // 0x8007CBD4: sb          $v0, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r2;
    // 0x8007CBD8: blez        $a0, L_8007CBF4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007CBDC: sb          $v0, 0x5($sp)
        MEM_B(0X5, ctx->r29) = ctx->r2;
            goto L_8007CBF4;
    }
    // 0x8007CBDC: sb          $v0, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r2;
L_8007CBE0:
    // 0x8007CBE0: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8007CBE4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8007CBE8: slt         $v0, $a3, $a0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007CBEC: bne         $v0, $zero, L_8007CBE0
    if (ctx->r2 != 0) {
        // 0x8007CBF0: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8007CBE0;
    }
    // 0x8007CBF0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8007CBF4:
    // 0x8007CBF4: lwl         $v0, 0x0($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r29, 0X0);
    // 0x8007CBF8: lwr         $v0, 0x3($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r29, 0X3);
    // 0x8007CBFC: lb          $v1, 0x4($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X4);
    // 0x8007CC00: lb          $a0, 0x5($sp)
    ctx->r4 = MEM_B(ctx->r29, 0X5);
    // 0x8007CC04: swl         $v0, 0x0($a2)
    do_swl(rdram, 0X0, ctx->r6, ctx->r2);
    // 0x8007CC08: swr         $v0, 0x3($a2)
    do_swr(rdram, 0X3, ctx->r6, ctx->r2);
    // 0x8007CC0C: sb          $v1, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r3;
    // 0x8007CC10: sb          $a0, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r4;
    // 0x8007CC14: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x8007CC18: sb          $v0, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r2;
    // 0x8007CC1C: jr          $ra
    // 0x8007CC20: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8007CC20: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8007CC24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CC24: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8007CC28: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8007CC2C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8007CC30: addiu       $a2, $a2, 0x3250
    ctx->r6 = ADD32(ctx->r6, 0X3250);
    // 0x8007CC34: blez        $a0, L_8007CC4C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007CC38: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8007CC4C;
    }
    // 0x8007CC38: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8007CC3C:
    // 0x8007CC3C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007CC40: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007CC44: bne         $v0, $zero, L_8007CC3C
    if (ctx->r2 != 0) {
        // 0x8007CC48: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8007CC3C;
    }
    // 0x8007CC48: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8007CC4C:
    // 0x8007CC4C: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x8007CC50: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x8007CC54: lb          $v1, 0x4($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X4);
    // 0x8007CC58: lb          $a0, 0x5($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X5);
    // 0x8007CC5C: swl         $v0, 0x0($sp)
    do_swl(rdram, 0X0, ctx->r29, ctx->r2);
    // 0x8007CC60: swr         $v0, 0x3($sp)
    do_swr(rdram, 0X3, ctx->r29, ctx->r2);
    // 0x8007CC64: sb          $v1, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r3;
    // 0x8007CC68: sb          $a0, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r4;
    // 0x8007CC6C: lbu         $v0, 0x1($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1);
    // 0x8007CC70: andi        $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 & 0XC0;
    // 0x8007CC74: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x8007CC78: bne         $v0, $zero, L_8007CC9C
    if (ctx->r2 != 0) {
        // 0x8007CC7C: sb          $v0, 0x3($a3)
        MEM_B(0X3, ctx->r7) = ctx->r2;
            goto L_8007CC9C;
    }
    // 0x8007CC7C: sb          $v0, 0x3($a3)
    MEM_B(0X3, ctx->r7) = ctx->r2;
    // 0x8007CC80: lbu         $v0, 0x4($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X4);
    // 0x8007CC84: lbu         $v1, 0x3($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X3);
    // 0x8007CC88: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8007CC8C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8007CC90: sh          $v1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r3;
    // 0x8007CC94: lbu         $v0, 0x5($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X5);
    // 0x8007CC98: sb          $v0, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r2;
L_8007CC9C:
    // 0x8007CC9C: jr          $ra
    // 0x8007CCA0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8007CCA0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8007CCA4: nop

    // 0x8007CCA8: nop

    // 0x8007CCAC: nop

;}
RECOMP_FUNC void func_8007CCB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CCB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007CCB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8007CCB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007CCBC: jal         0x80076080
    // 0x8007CCC0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x8007CCC0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8007CCC4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8007CCC8: lw          $v1, 0x2280($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2280);
    // 0x8007CCCC: nor         $s0, $zero, $s0
    ctx->r16 = ~(0 | ctx->r16);
    // 0x8007CCD0: ori         $s0, $s0, 0x401
    ctx->r16 = ctx->r16 | 0X401;
    // 0x8007CCD4: and         $v1, $v1, $s0
    ctx->r3 = ctx->r3 & ctx->r16;
    // 0x8007CCD8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8007CCDC: sw          $v1, 0x2280($at)
    MEM_W(0X2280, ctx->r1) = ctx->r3;
    // 0x8007CCE0: jal         0x800760A0
    // 0x8007CCE4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x8007CCE4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8007CCE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007CCEC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8007CCF0: jr          $ra
    // 0x8007CCF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007CCF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007CCF8: nop

    // 0x8007CCFC: nop

;}
RECOMP_FUNC void func_8007CD00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CD00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007CD04: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8007CD08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007CD0C: jal         0x80076080
    // 0x8007CD10: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x8007CD10: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8007CD14: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8007CD18: lw          $v1, 0x2280($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2280);
    // 0x8007CD1C: or          $v1, $v1, $s0
    ctx->r3 = ctx->r3 | ctx->r16;
    // 0x8007CD20: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8007CD24: sw          $v1, 0x2280($at)
    MEM_W(0X2280, ctx->r1) = ctx->r3;
    // 0x8007CD28: jal         0x800760A0
    // 0x8007CD2C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x8007CD2C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8007CD30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007CD34: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8007CD38: jr          $ra
    // 0x8007CD3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007CD3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8007CD40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CD40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007CD44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007CD48: jal         0x80076080
    // 0x8007CD4C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x8007CD4C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8007CD50: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8007CD54: lw          $v1, 0x1020($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1020);
    // 0x8007CD58: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8007CD5C: addiu       $a0, $a0, 0x1018
    ctx->r4 = ADD32(ctx->r4, 0X1018);
    // 0x8007CD60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8007CD64: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8007CD68: jal         0x800759DC
    // 0x8007CD6C: sh          $a1, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r5;
    func_800759DC(rdram, ctx);
        goto after_1;
    // 0x8007CD6C: sh          $a1, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r5;
    after_1:
    // 0x8007CD70: jal         0x800760A0
    // 0x8007CD74: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_2;
    // 0x8007CD74: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8007CD78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007CD7C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8007CD80: jr          $ra
    // 0x8007CD84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007CD84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007CD88: nop

    // 0x8007CD8C: nop

;}
RECOMP_FUNC void func_8007CDB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CDB0: xor         $v0, $a0, $a1
    ctx->r2 = ctx->r4 ^ ctx->r5;
    // 0x8007CDB4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x8007CDB8: bne         $at, $zero, L_8007CE8C
    if (ctx->r1 != 0) {
        // 0x8007CDBC: nop
    
            goto L_8007CE8C;
    }
    // 0x8007CDBC: nop

    // 0x8007CDC0: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8007CDC4: bne         $v0, $zero, L_8007CE28
    if (ctx->r2 != 0) {
        // 0x8007CDC8: negu        $t8, $a0
        ctx->r24 = SUB32(0, ctx->r4);
            goto L_8007CE28;
    }
    // 0x8007CDC8: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x8007CDCC: andi        $t8, $t8, 0x3
    ctx->r24 = ctx->r24 & 0X3;
    // 0x8007CDD0: beq         $t8, $zero, L_8007CDF0
    if (ctx->r24 == 0) {
        // 0x8007CDD4: subu        $a2, $a2, $t8
        ctx->r6 = SUB32(ctx->r6, ctx->r24);
            goto L_8007CDF0;
    }
    // 0x8007CDD4: subu        $a2, $a2, $t8
    ctx->r6 = SUB32(ctx->r6, ctx->r24);
    // 0x8007CDD8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8007CDDC: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    // 0x8007CDE0: lwl         $v1, 0x0($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0X0);
    // 0x8007CDE4: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8007CDE8: bne         $v0, $v1, L_8007CEB8
    if (ctx->r2 != ctx->r3) {
            // 0x8007CDEC: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    func_8007CEB8(rdram, ctx);
    return;
    }
    // 0x8007CDEC: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
L_8007CDF0:
    // 0x8007CDF0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8007CDF4: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x8007CDF8: beq         $a3, $zero, L_8007CE8C
    if (ctx->r7 == 0) {
        // 0x8007CDFC: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8007CE8C;
    }
    // 0x8007CDFC: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8007CE00: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8007CE04:
    // 0x8007CE04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007CE08: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8007CE0C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8007CE10: bne         $v0, $v1, L_8007CEB8
    if (ctx->r2 != ctx->r3) {
            // 0x8007CE14: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_8007CEB8(rdram, ctx);
    return;
    }
    // 0x8007CE14: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8007CE18: bne         $a0, $a3, L_8007CE04
    if (ctx->r4 != ctx->r7) {
        // 0x8007CE1C: nop
    
            goto L_8007CE04;
    }
    // 0x8007CE1C: nop

    // 0x8007CE20: b           L_8007CE8C
    // 0x8007CE24: nop

        goto L_8007CE8C;
    // 0x8007CE24: nop

L_8007CE28:
    // 0x8007CE28: negu        $a3, $a1
    ctx->r7 = SUB32(0, ctx->r5);
    // 0x8007CE2C: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x8007CE30: beq         $a3, $zero, L_8007CE58
    if (ctx->r7 == 0) {
        // 0x8007CE34: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8007CE58;
    }
    // 0x8007CE34: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8007CE38: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8007CE3C:
    // 0x8007CE3C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8007CE40: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8007CE44: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007CE48: bne         $v0, $v1, L_8007CEB8
    if (ctx->r2 != ctx->r3) {
            // 0x8007CE4C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_8007CEB8(rdram, ctx);
    return;
    }
    // 0x8007CE4C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007CE50: bne         $a0, $a3, L_8007CE3C
    if (ctx->r4 != ctx->r7) {
        // 0x8007CE54: nop
    
            goto L_8007CE3C;
    }
    // 0x8007CE54: nop

L_8007CE58:
    // 0x8007CE58: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8007CE5C: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x8007CE60: beq         $a3, $zero, L_8007CE8C
    if (ctx->r7 == 0) {
        // 0x8007CE64: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8007CE8C;
    }
    // 0x8007CE64: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8007CE68: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8007CE6C:
    // 0x8007CE6C: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    // 0x8007CE70: lwr         $v0, 0x3($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r4, 0X3);
    // 0x8007CE74: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8007CE78: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8007CE7C: bne         $v0, $v1, L_8007CEB8
    if (ctx->r2 != ctx->r3) {
            // 0x8007CE80: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_8007CEB8(rdram, ctx);
    return;
    }
    // 0x8007CE80: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8007CE84: bne         $a0, $a3, L_8007CE6C
    if (ctx->r4 != ctx->r7) {
        // 0x8007CE88: nop
    
            goto L_8007CE6C;
    }
    // 0x8007CE88: nop

L_8007CE8C:
    // 0x8007CE8C: blez        $a2, L_8007CEB0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8007CE90: addu        $a3, $a2, $a0
        ctx->r7 = ADD32(ctx->r6, ctx->r4);
            goto L_8007CEB0;
    }
    // 0x8007CE90: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
L_8007CE94:
    // 0x8007CE94: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8007CE98: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8007CE9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007CEA0: bne         $v0, $v1, L_8007CEB8
    if (ctx->r2 != ctx->r3) {
            // 0x8007CEA4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_8007CEB8(rdram, ctx);
    return;
    }
    // 0x8007CEA4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007CEA8: bne         $a0, $a3, L_8007CE94
    if (ctx->r4 != ctx->r7) {
        // 0x8007CEAC: nop
    
            goto L_8007CE94;
    }
    // 0x8007CEAC: nop

L_8007CEB0:
    // 0x8007CEB0: jr          $ra
    // 0x8007CEB4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8007CEB4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8007CEB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CEB8: jr          $ra
    // 0x8007CEBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8007CEBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8007CEC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CEC0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8007CEC4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8007CEC8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8007CECC: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8007CED0: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x8007CED4: addiu       $s6, $s6, 0x2730
    ctx->r22 = ADD32(ctx->r22, 0X2730);
    // 0x8007CED8: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x8007CEDC: addiu       $v0, $zero, 0x58
    ctx->r2 = ADD32(0, 0X58);
    // 0x8007CEE0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8007CEE4: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8007CEE8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8007CEEC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8007CEF0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8007CEF4: bne         $a0, $v0, L_8007CF04
    if (ctx->r4 != ctx->r2) {
        // 0x8007CEF8: sw          $s0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r16;
            goto L_8007CF04;
    }
    // 0x8007CEF8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8007CEFC: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x8007CF00: addiu       $s6, $s6, 0x2744
    ctx->r22 = ADD32(ctx->r22, 0X2744);
L_8007CF04:
    // 0x8007CF04: addiu       $v0, $zero, 0x6F
    ctx->r2 = ADD32(0, 0X6F);
    // 0x8007CF08: beq         $a0, $v0, L_8007CF30
    if (ctx->r4 == ctx->r2) {
        // 0x8007CF0C: xori        $v1, $a0, 0x78
        ctx->r3 = ctx->r4 ^ 0X78;
            goto L_8007CF30;
    }
    // 0x8007CF0C: xori        $v1, $a0, 0x78
    ctx->r3 = ctx->r4 ^ 0X78;
    // 0x8007CF10: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8007CF14: xori        $v0, $a0, 0x58
    ctx->r2 = ctx->r4 ^ 0X58;
    // 0x8007CF18: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8007CF1C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8007CF20: beq         $v1, $zero, L_8007CF34
    if (ctx->r3 == 0) {
        // 0x8007CF24: addiu       $s3, $zero, 0x10
        ctx->r19 = ADD32(0, 0X10);
            goto L_8007CF34;
    }
    // 0x8007CF24: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x8007CF28: j           L_8007CF34
    // 0x8007CF2C: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
        goto L_8007CF34;
    // 0x8007CF2C: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
L_8007CF30:
    // 0x8007CF30: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_8007CF34:
    // 0x8007CF34: lw          $s4, 0x0($s1)
    ctx->r20 = MEM_W(ctx->r17, 0X0);
    // 0x8007CF38: lw          $s5, 0x4($s1)
    ctx->r21 = MEM_W(ctx->r17, 0X4);
    // 0x8007CF3C: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8007CF40: xori        $v1, $v0, 0x64
    ctx->r3 = ctx->r2 ^ 0X64;
    // 0x8007CF44: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8007CF48: xori        $v0, $v0, 0x69
    ctx->r2 = ctx->r2 ^ 0X69;
    // 0x8007CF4C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007CF50: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8007CF54: beq         $v1, $zero, L_8007CF78
    if (ctx->r3 == 0) {
        // 0x8007CF58: addiu       $s2, $zero, 0x18
        ctx->r18 = ADD32(0, 0X18);
            goto L_8007CF78;
    }
    // 0x8007CF58: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
    // 0x8007CF5C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8007CF60: bgez        $v0, L_8007CF78
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007CF64: nop
    
            goto L_8007CF78;
    }
    // 0x8007CF64: nop

    // 0x8007CF68: negu        $s5, $s5
    ctx->r21 = SUB32(0, ctx->r21);
    // 0x8007CF6C: negu        $s4, $s4
    ctx->r20 = SUB32(0, ctx->r20);
    // 0x8007CF70: sltu        $v0, $zero, $s5
    ctx->r2 = 0 < ctx->r21 ? 1 : 0;
    // 0x8007CF74: subu        $s4, $s4, $v0
    ctx->r20 = SUB32(ctx->r20, ctx->r2);
L_8007CF78:
    // 0x8007CF78: bnel        $s4, $zero, L_8007CF98
    if (ctx->r20 != 0) {
        // 0x8007CF7C: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8007CF98;
    }
    goto skip_0;
    // 0x8007CF7C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x8007CF80: bnel        $s5, $zero, L_8007CF98
    if (ctx->r21 != 0) {
        // 0x8007CF84: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8007CF98;
    }
    goto skip_1;
    // 0x8007CF84: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_1:
    // 0x8007CF88: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8007CF8C: beq         $v0, $zero, L_8007CFC4
    if (ctx->r2 == 0) {
        // 0x8007CF90: addu        $a3, $s3, $zero
        ctx->r7 = ADD32(ctx->r19, 0);
            goto L_8007CFC4;
    }
    // 0x8007CF90: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // 0x8007CF94: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8007CF98:
    // 0x8007CF98: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // 0x8007CF9C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007CFA0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8007CFA4: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8007CFA8: addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // 0x8007CFAC: jal         0x8007E500
    // 0x8007CFB0: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    func_8007E500(rdram, ctx);
        goto after_0;
    // 0x8007CFB0: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    after_0:
    // 0x8007CFB4: addu        $v0, $s6, $v1
    ctx->r2 = ADD32(ctx->r22, ctx->r3);
    // 0x8007CFB8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8007CFBC: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8007CFC0: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
L_8007CFC4:
    // 0x8007CFC4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007CFC8: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8007CFCC: jal         0x8007E4E0
    // 0x8007CFD0: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8007E4E0(rdram, ctx);
        goto after_1;
    // 0x8007CFD0: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_1:
    // 0x8007CFD4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8007CFD8: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x8007CFDC: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x8007CFE0: addu        $s0, $s2, $v0
    ctx->r16 = ADD32(ctx->r18, ctx->r2);
L_8007CFE4:
    // 0x8007CFE4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8007CFE8: bgtz        $v0, L_8007D004
    if (SIGNED(ctx->r2) > 0) {
        // 0x8007CFEC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8007D004;
    }
    // 0x8007CFEC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8007CFF0: bne         $v0, $zero, L_8007D00C
    if (ctx->r2 != 0) {
        // 0x8007CFF4: slt         $v0, $zero, $s2
        ctx->r2 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_8007D00C;
    }
    // 0x8007CFF4: slt         $v0, $zero, $s2
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8007CFF8: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8007CFFC: beq         $v0, $zero, L_8007D00C
    if (ctx->r2 == 0) {
        // 0x8007D000: slt         $v0, $zero, $s2
        ctx->r2 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_8007D00C;
    }
    // 0x8007D000: slt         $v0, $zero, $s2
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
L_8007D004:
    // 0x8007D004: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007D008: slt         $v0, $zero, $s2
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
L_8007D00C:
    // 0x8007D00C: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8007D010: beq         $v0, $zero, L_8007D064
    if (ctx->r2 == 0) {
        // 0x8007D014: addu        $v1, $s3, $zero
        ctx->r3 = ADD32(ctx->r19, 0);
            goto L_8007D064;
    }
    // 0x8007D014: addu        $v1, $s3, $zero
    ctx->r3 = ADD32(ctx->r19, 0);
    // 0x8007D018: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x8007D01C: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x8007D020: sra         $v0, $s3, 31
    ctx->r2 = S32(SIGNED(ctx->r19) >> 31);
    // 0x8007D024: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007D028: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8007D02C: jal         0x8007DC14
    // 0x8007D030: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_8007DC14(rdram, ctx);
        goto after_2;
    // 0x8007D030: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x8007D034: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8007D038: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8007D03C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8007D040: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x8007D044: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8007D048: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8007D04C: addu        $v0, $s6, $v1
    ctx->r2 = ADD32(ctx->r22, ctx->r3);
    // 0x8007D050: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8007D054: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8007D058: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8007D05C: j           L_8007CFE4
    // 0x8007D060: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
        goto L_8007CFE4;
    // 0x8007D060: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_8007D064:
    // 0x8007D064: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x8007D068: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8007D06C: addu        $a1, $a1, $s2
    ctx->r5 = ADD32(ctx->r5, ctx->r18);
    // 0x8007D070: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8007D074: subu        $a2, $a2, $s2
    ctx->r6 = SUB32(ctx->r6, ctx->r18);
    // 0x8007D078: jal         0x800731EC
    // 0x8007D07C: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    func_800731EC(rdram, ctx);
        goto after_3;
    // 0x8007D07C: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    after_3:
    // 0x8007D080: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8007D084: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8007D088: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007D08C: beq         $v0, $zero, L_8007D098
    if (ctx->r2 == 0) {
        // 0x8007D090: subu        $v0, $v1, $a0
        ctx->r2 = SUB32(ctx->r3, ctx->r4);
            goto L_8007D098;
    }
    // 0x8007D090: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x8007D094: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
L_8007D098:
    // 0x8007D098: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8007D09C: bgez        $v0, L_8007D0DC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007D0A0: addiu       $v1, $zero, 0x10
        ctx->r3 = ADD32(0, 0X10);
            goto L_8007D0DC;
    }
    // 0x8007D0A0: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8007D0A4: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8007D0A8: andi        $v0, $v0, 0x14
    ctx->r2 = ctx->r2 & 0X14;
    // 0x8007D0AC: bne         $v0, $v1, L_8007D0DC
    if (ctx->r2 != ctx->r3) {
        // 0x8007D0B0: nop
    
            goto L_8007D0DC;
    }
    // 0x8007D0B0: nop

    // 0x8007D0B4: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x8007D0B8: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x8007D0BC: lw          $a1, 0x10($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X10);
    // 0x8007D0C0: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8007D0C4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007D0C8: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8007D0CC: subu        $s2, $v0, $a0
    ctx->r18 = SUB32(ctx->r2, ctx->r4);
    // 0x8007D0D0: blez        $s2, L_8007D0DC
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8007D0D4: addu        $v0, $a1, $s2
        ctx->r2 = ADD32(ctx->r5, ctx->r18);
            goto L_8007D0DC;
    }
    // 0x8007D0D4: addu        $v0, $a1, $s2
    ctx->r2 = ADD32(ctx->r5, ctx->r18);
    // 0x8007D0D8: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
L_8007D0DC:
    // 0x8007D0DC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8007D0E0: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8007D0E4: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8007D0E8: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8007D0EC: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D0F0: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8007D0F4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8007D0F8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8007D0FC: jr          $ra
    // 0x8007D100: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8007D100: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8007D104: nop

    // 0x8007D108: nop

    // 0x8007D10C: nop

;}
RECOMP_FUNC void func_8007D110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D110: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8007D114: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8007D118: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8007D11C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8007D120: addiu       $s1, $sp, 0x18
    ctx->r17 = ADD32(ctx->r29, 0X18);
    // 0x8007D124: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x8007D128: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8007D12C: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8007D130: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8007D134: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8007D138: sdc1        $f24, 0x78($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X78, ctx->r29);
    // 0x8007D13C: sdc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X70, ctx->r29);
    // 0x8007D140: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x8007D144: lw          $v0, 0x24($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X24);
    // 0x8007D148: ldc1        $f20, 0x0($s3)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r19, 0X0);
    // 0x8007D14C: bgez        $v0, L_8007D15C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007D150: addu        $s5, $a1, $zero
        ctx->r21 = ADD32(ctx->r5, 0);
            goto L_8007D15C;
    }
    // 0x8007D150: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x8007D154: j           L_8007D184
    // 0x8007D158: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_8007D184;
    // 0x8007D158: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8007D15C:
    // 0x8007D15C: bne         $v0, $zero, L_8007D18C
    if (ctx->r2 != 0) {
        // 0x8007D160: addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
            goto L_8007D18C;
    }
    // 0x8007D160: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8007D164: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x8007D168: xori        $v1, $v0, 0x67
    ctx->r3 = ctx->r2 ^ 0X67;
    // 0x8007D16C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8007D170: xori        $v0, $v0, 0x47
    ctx->r2 = ctx->r2 ^ 0X47;
    // 0x8007D174: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007D178: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8007D17C: beq         $v1, $zero, L_8007D18C
    if (ctx->r3 == 0) {
        // 0x8007D180: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007D18C;
    }
    // 0x8007D180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007D184:
    // 0x8007D184: sw          $v0, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->r2;
    // 0x8007D188: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
L_8007D18C:
    // 0x8007D18C: jal         0x8007D550
    // 0x8007D190: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8007D550(rdram, ctx);
        goto after_0;
    // 0x8007D190: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_0:
    // 0x8007D194: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8007D198: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007D19C: blez        $v1, L_8007D1E0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007D1A0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8007D1E0;
    }
    // 0x8007D1A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007D1A4: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8007D1A8: addiu       $a2, $a2, 0x26BC
    ctx->r6 = ADD32(ctx->r6, 0X26BC);
    // 0x8007D1AC: lw          $a3, 0x8($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X8);
    // 0x8007D1B0: bne         $v1, $v0, L_8007D1C0
    if (ctx->r3 != ctx->r2) {
        // 0x8007D1B4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8007D1C0;
    }
    // 0x8007D1B4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8007D1B8: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8007D1BC: addiu       $a2, $a2, 0x26B8
    ctx->r6 = ADD32(ctx->r6, 0X26B8);
L_8007D1C0:
    // 0x8007D1C0: sw          $v0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r2;
    // 0x8007D1C4: lb          $v0, 0x0($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X0);
    // 0x8007D1C8: lb          $v1, 0x1($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X1);
    // 0x8007D1CC: lb          $a0, 0x2($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X2);
    // 0x8007D1D0: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x8007D1D4: sb          $v1, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r3;
    // 0x8007D1D8: j           L_8007D520
    // 0x8007D1DC: sb          $a0, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r4;
        goto L_8007D520;
    // 0x8007D1DC: sb          $a0, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r4;
L_8007D1E0:
    // 0x8007D1E0: bne         $v1, $zero, L_8007D1F0
    if (ctx->r3 != 0) {
        // 0x8007D1E4: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_8007D1F0;
    }
    // 0x8007D1E4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8007D1E8: j           L_8007D500
    // 0x8007D1EC: sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
        goto L_8007D500;
    // 0x8007D1EC: sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
L_8007D1F0:
    // 0x8007D1F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007D1F4: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x8007D1F8: nop

    // 0x8007D1FC: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x8007D200: nop

    // 0x8007D204: nop

    // 0x8007D208: bc1tl       L_8007D210
    if (c1cs) {
        // 0x8007D20C: neg.d       $f20, $f20
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
            goto L_8007D210;
    }
    goto skip_0;
    // 0x8007D20C: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
    skip_0:
L_8007D210:
    // 0x8007D210: lh          $v1, 0x38($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X38);
    // 0x8007D214: addiu       $v0, $zero, 0x7597
    ctx->r2 = ADD32(0, 0X7597);
    // 0x8007D218: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007D21C: mflo        $v1
    ctx->r3 = lo;
    // 0x8007D220: lui         $v0, 0x14F8
    ctx->r2 = S32(0X14F8 << 16);
    // 0x8007D224: ori         $v0, $v0, 0xB589
    ctx->r2 = ctx->r2 | 0XB589;
    // 0x8007D228: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007D22C: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8007D230: mfhi        $t0
    ctx->r8 = hi;
    // 0x8007D234: sra         $v0, $t0, 13
    ctx->r2 = S32(SIGNED(ctx->r8) >> 13);
    // 0x8007D238: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007D23C: addiu       $v1, $v0, -0x4
    ctx->r3 = ADD32(ctx->r2, -0X4);
    // 0x8007D240: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8007D244: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007D248: bgez        $v0, L_8007D298
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007D24C: sh          $v1, 0x38($sp)
        MEM_H(0X38, ctx->r29) = ctx->r3;
            goto L_8007D298;
    }
    // 0x8007D24C: sh          $v1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r3;
    // 0x8007D250: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8007D254: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8007D258: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
    // 0x8007D25C: and         $v1, $v0, $v1
    ctx->r3 = ctx->r2 & ctx->r3;
    // 0x8007D260: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x8007D264: blez        $v1, L_8007D2E4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007D268: sh          $v0, 0x38($sp)
        MEM_H(0X38, ctx->r29) = ctx->r2;
            goto L_8007D2E4;
    }
    // 0x8007D268: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // 0x8007D26C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8007D270: addiu       $a0, $a0, 0x2670
    ctx->r4 = ADD32(ctx->r4, 0X2670);
L_8007D274:
    // 0x8007D274: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8007D278: beq         $v0, $zero, L_8007D288
    if (ctx->r2 == 0) {
        // 0x8007D27C: sra         $v1, $v1, 1
        ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8007D288;
    }
    // 0x8007D27C: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8007D280: ldc1        $f0, 0x0($a0)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r4, 0X0);
    // 0x8007D284: mul.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = MUL_D(ctx->f20.d, ctx->f0.d);
L_8007D288:
    // 0x8007D288: bgtz        $v1, L_8007D274
    if (SIGNED(ctx->r3) > 0) {
        // 0x8007D28C: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_8007D274;
    }
    // 0x8007D28C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007D290: j           L_8007D2E4
    // 0x8007D294: nop

        goto L_8007D2E4;
    // 0x8007D294: nop

L_8007D298:
    // 0x8007D298: blez        $v0, L_8007D2E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007D29C: addiu       $v0, $zero, -0x4
        ctx->r2 = ADD32(0, -0X4);
            goto L_8007D2E4;
    }
    // 0x8007D29C: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    // 0x8007D2A0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8007D2A4: ldc1        $f2, 0x26C0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X26C0);
    // 0x8007D2A8: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8007D2AC: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8007D2B0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8007D2B4: blez        $v1, L_8007D2E0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007D2B8: sh          $v0, 0x38($sp)
        MEM_H(0X38, ctx->r29) = ctx->r2;
            goto L_8007D2E0;
    }
    // 0x8007D2B8: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // 0x8007D2BC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8007D2C0: addiu       $a0, $a0, 0x2670
    ctx->r4 = ADD32(ctx->r4, 0X2670);
L_8007D2C4:
    // 0x8007D2C4: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8007D2C8: beq         $v0, $zero, L_8007D2D8
    if (ctx->r2 == 0) {
        // 0x8007D2CC: sra         $v1, $v1, 1
        ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8007D2D8;
    }
    // 0x8007D2CC: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8007D2D0: ldc1        $f0, 0x0($a0)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r4, 0X0);
    // 0x8007D2D4: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
L_8007D2D8:
    // 0x8007D2D8: bgtz        $v1, L_8007D2C4
    if (SIGNED(ctx->r3) > 0) {
        // 0x8007D2DC: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_8007D2C4;
    }
    // 0x8007D2DC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8007D2E0:
    // 0x8007D2E0: div.d       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f20.d = DIV_D(ctx->f20.d, ctx->f2.d);
L_8007D2E4:
    // 0x8007D2E4: lw          $a0, 0x24($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X24);
    // 0x8007D2E8: andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    // 0x8007D2EC: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x8007D2F0: bne         $v1, $v0, L_8007D304
    if (ctx->r3 != ctx->r2) {
        // 0x8007D2F4: addiu       $s2, $a0, 0x6
        ctx->r18 = ADD32(ctx->r4, 0X6);
            goto L_8007D304;
    }
    // 0x8007D2F4: addiu       $s2, $a0, 0x6
    ctx->r18 = ADD32(ctx->r4, 0X6);
    // 0x8007D2F8: lh          $v1, 0x38($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X38);
    // 0x8007D2FC: addiu       $v0, $a0, 0xA
    ctx->r2 = ADD32(ctx->r4, 0XA);
    // 0x8007D300: addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
L_8007D304:
    // 0x8007D304: slti        $v0, $s2, 0x14
    ctx->r2 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
    // 0x8007D308: beql        $v0, $zero, L_8007D310
    if (ctx->r2 == 0) {
        // 0x8007D30C: addiu       $s2, $zero, 0x13
        ctx->r18 = ADD32(0, 0X13);
            goto L_8007D310;
    }
    goto skip_1;
    // 0x8007D30C: addiu       $s2, $zero, 0x13
    ctx->r18 = ADD32(0, 0X13);
    skip_1:
L_8007D310:
    // 0x8007D310: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x8007D314: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x8007D318: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007D31C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8007D320: mtc1        $zero, $f25
    ctx->f_odd[(25 - 1) * 2] = 0;
    // 0x8007D324: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8007D328: ldc1        $f22, 0x26C8($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, 0X26C8);
    // 0x8007D32C: addiu       $s4, $zero, 0x30
    ctx->r20 = ADD32(0, 0X30);
L_8007D330:
    // 0x8007D330: c.lt.d      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.d < ctx->f20.d;
    // 0x8007D334: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007D338: nop

    // 0x8007D33C: bc1t        L_8007D348
    if (c1cs) {
        // 0x8007D340: slt         $v0, $zero, $s2
        ctx->r2 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_8007D348;
    }
    // 0x8007D340: slt         $v0, $zero, $s2
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8007D344: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8007D348:
    // 0x8007D348: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8007D34C: beq         $v0, $zero, L_8007D3D4
    if (ctx->r2 == 0) {
        // 0x8007D350: addiu       $s2, $s2, -0x8
        ctx->r18 = ADD32(ctx->r18, -0X8);
            goto L_8007D3D4;
    }
    // 0x8007D350: addiu       $s2, $s2, -0x8
    ctx->r18 = ADD32(ctx->r18, -0X8);
    // 0x8007D354: trunc.w.d   $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.u32l = TRUNC_W_D(ctx->f20.d);
    // 0x8007D358: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007D35C: nop

    // 0x8007D360: blez        $s2, L_8007D37C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8007D364: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_8007D37C;
    }
    // 0x8007D364: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8007D368: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x8007D36C: nop

    // 0x8007D370: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8007D374: sub.d       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f20.d - ctx->f0.d;
    // 0x8007D378: mul.d       $f20, $f0, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f22.d); 
    ctx->f20.d = MUL_D(ctx->f0.d, ctx->f22.d);
L_8007D37C:
    // 0x8007D37C: blez        $a1, L_8007D3C0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8007D380: addiu       $s0, $zero, 0x8
        ctx->r16 = ADD32(0, 0X8);
            goto L_8007D3C0;
    }
    // 0x8007D380: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x8007D384: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8007D388:
    // 0x8007D388: bltz        $s0, L_8007D3C0
    if (SIGNED(ctx->r16) < 0) {
        // 0x8007D38C: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_8007D3C0;
    }
    // 0x8007D38C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8007D390: jal         0x8007DB90
    // 0x8007D394: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_8007DB90(rdram, ctx);
        goto after_1;
    // 0x8007D394: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x8007D398: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8007D39C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8007D3A0: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x8007D3A4: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x8007D3A8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8007D3AC: bgtz        $a1, L_8007D388
    if (SIGNED(ctx->r5) > 0) {
        // 0x8007D3B0: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_8007D388;
    }
    // 0x8007D3B0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8007D3B4: j           L_8007D3C4
    // 0x8007D3B8: nop

        goto L_8007D3C4;
    // 0x8007D3B8: nop

L_8007D3BC:
    // 0x8007D3BC: sb          $s4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r20;
L_8007D3C0:
    // 0x8007D3C0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8007D3C4:
    // 0x8007D3C4: bgezl       $s0, L_8007D3BC
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8007D3C8: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8007D3BC;
    }
    goto skip_2;
    // 0x8007D3C8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_2:
    // 0x8007D3CC: j           L_8007D330
    // 0x8007D3D0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
        goto L_8007D330;
    // 0x8007D3D0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_8007D3D4:
    // 0x8007D3D4: addiu       $v1, $s1, -0x1
    ctx->r3 = ADD32(ctx->r17, -0X1);
    // 0x8007D3D8: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x8007D3DC: subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
    // 0x8007D3E0: lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X38);
    // 0x8007D3E4: lbu         $v1, 0x19($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X19);
    // 0x8007D3E8: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x8007D3EC: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // 0x8007D3F0: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x8007D3F4: bne         $v1, $v0, L_8007D41C
    if (ctx->r3 != ctx->r2) {
        // 0x8007D3F8: addiu       $s1, $sp, 0x19
        ctx->r17 = ADD32(ctx->r29, 0X19);
            goto L_8007D41C;
    }
    // 0x8007D3F8: addiu       $s1, $sp, 0x19
    ctx->r17 = ADD32(ctx->r29, 0X19);
    // 0x8007D3FC: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
L_8007D400:
    // 0x8007D400: lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X38);
    // 0x8007D404: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007D408: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8007D40C: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // 0x8007D410: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x8007D414: beq         $v0, $v1, L_8007D400
    if (ctx->r2 == ctx->r3) {
        // 0x8007D418: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8007D400;
    }
    // 0x8007D418: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8007D41C:
    // 0x8007D41C: lw          $a1, 0x24($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X24);
    // 0x8007D420: andi        $a0, $s5, 0xFF
    ctx->r4 = ctx->r21 & 0XFF;
    // 0x8007D424: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x8007D428: bne         $a0, $v0, L_8007D440
    if (ctx->r4 != ctx->r2) {
        // 0x8007D42C: xori        $v1, $a0, 0x65
        ctx->r3 = ctx->r4 ^ 0X65;
            goto L_8007D440;
    }
    // 0x8007D42C: xori        $v1, $a0, 0x65
    ctx->r3 = ctx->r4 ^ 0X65;
    // 0x8007D430: lh          $v1, 0x38($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X38);
    // 0x8007D434: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8007D438: j           L_8007D454
    // 0x8007D43C: addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
        goto L_8007D454;
    // 0x8007D43C: addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
L_8007D440:
    // 0x8007D440: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8007D444: xori        $v0, $a0, 0x45
    ctx->r2 = ctx->r4 ^ 0X45;
    // 0x8007D448: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007D44C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8007D450: addu        $a3, $a1, $v1
    ctx->r7 = ADD32(ctx->r5, ctx->r3);
L_8007D454:
    // 0x8007D454: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x8007D458: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007D45C: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007D460: bnel        $v0, $zero, L_8007D468
    if (ctx->r2 != 0) {
        // 0x8007D464: addu        $a3, $s2, $zero
        ctx->r7 = ADD32(ctx->r18, 0);
            goto L_8007D468;
    }
    goto skip_3;
    // 0x8007D464: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    skip_3:
L_8007D468:
    // 0x8007D468: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x8007D46C: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007D470: blez        $a0, L_8007D500
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007D474: slt         $v0, $a0, $s2
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_8007D500;
    }
    // 0x8007D474: slt         $v0, $a0, $s2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8007D478: beq         $v0, $zero, L_8007D49C
    if (ctx->r2 == 0) {
        // 0x8007D47C: addiu       $v1, $zero, 0x30
        ctx->r3 = ADD32(0, 0X30);
            goto L_8007D49C;
    }
    // 0x8007D47C: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x8007D480: addu        $v0, $s1, $a0
    ctx->r2 = ADD32(ctx->r17, ctx->r4);
    // 0x8007D484: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8007D488: sltiu       $v0, $v0, 0x35
    ctx->r2 = ctx->r2 < 0X35 ? 1 : 0;
    // 0x8007D48C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8007D490: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8007D494: andi        $v0, $v0, 0x39
    ctx->r2 = ctx->r2 & 0X39;
    // 0x8007D498: ori         $v1, $v0, 0x30
    ctx->r3 = ctx->r2 | 0X30;
L_8007D49C:
    // 0x8007D49C: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x8007D4A0: addu        $a0, $s1, $a1
    ctx->r4 = ADD32(ctx->r17, ctx->r5);
    // 0x8007D4A4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8007D4A8: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    // 0x8007D4AC: bnel        $v0, $a2, L_8007D4CC
    if (ctx->r2 != ctx->r6) {
        // 0x8007D4B0: andi        $v1, $v1, 0xFF
        ctx->r3 = ctx->r3 & 0XFF;
            goto L_8007D4CC;
    }
    goto skip_4;
    // 0x8007D4B0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    skip_4:
L_8007D4B4:
    // 0x8007D4B4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8007D4B8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8007D4BC: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8007D4C0: beq         $v0, $a2, L_8007D4B4
    if (ctx->r2 == ctx->r6) {
        // 0x8007D4C4: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_8007D4B4;
    }
    // 0x8007D4C4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8007D4C8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8007D4CC:
    // 0x8007D4CC: addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    // 0x8007D4D0: bne         $v1, $v0, L_8007D4E4
    if (ctx->r3 != ctx->r2) {
        // 0x8007D4D4: addu        $v1, $s1, $a1
        ctx->r3 = ADD32(ctx->r17, ctx->r5);
            goto L_8007D4E4;
    }
    // 0x8007D4D4: addu        $v1, $s1, $a1
    ctx->r3 = ADD32(ctx->r17, ctx->r5);
    // 0x8007D4D8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8007D4DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007D4E0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8007D4E4:
    // 0x8007D4E4: bgez        $a1, L_8007D504
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8007D4E8: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_8007D504;
    }
    // 0x8007D4E8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007D4EC: lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X38);
    // 0x8007D4F0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8007D4F4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8007D4F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007D4FC: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
L_8007D500:
    // 0x8007D500: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_8007D504:
    // 0x8007D504: lh          $v0, 0x38($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X38);
    // 0x8007D508: andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
    // 0x8007D50C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8007D510: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8007D514: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8007D518: jal         0x8007D5E8
    // 0x8007D51C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8007D5E8(rdram, ctx);
        goto after_2;
    // 0x8007D51C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
L_8007D520:
    // 0x8007D520: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x8007D524: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8007D528: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8007D52C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8007D530: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8007D534: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D538: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8007D53C: ldc1        $f24, 0x78($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X78);
    // 0x8007D540: ldc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X70);
    // 0x8007D544: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x8007D548: jr          $ra
    // 0x8007D54C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8007D54C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8007D550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D550: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x8007D554: andi        $v0, $v1, 0x7FF0
    ctx->r2 = ctx->r3 & 0X7FF0;
    // 0x8007D558: srl         $a3, $v0, 4
    ctx->r7 = S32(U32(ctx->r2) >> 4);
    // 0x8007D55C: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    // 0x8007D560: addiu       $v0, $zero, 0x7FF
    ctx->r2 = ADD32(0, 0X7FF);
    // 0x8007D564: bne         $a2, $v0, L_8007D5AC
    if (ctx->r6 != ctx->r2) {
        // 0x8007D568: addu        $t0, $a1, $zero
        ctx->r8 = ADD32(ctx->r5, 0);
            goto L_8007D5AC;
    }
    // 0x8007D568: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8007D56C: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8007D570: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8007D574: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8007D578: bne         $v0, $zero, L_8007D5E0
    if (ctx->r2 != 0) {
        // 0x8007D57C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8007D5E0;
    }
    // 0x8007D57C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007D580: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8007D584: bne         $v0, $zero, L_8007D5E0
    if (ctx->r2 != 0) {
        // 0x8007D588: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8007D5E0;
    }
    // 0x8007D588: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007D58C: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x8007D590: bne         $v0, $zero, L_8007D5E0
    if (ctx->r2 != 0) {
        // 0x8007D594: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8007D5E0;
    }
    // 0x8007D594: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007D598: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // 0x8007D59C: bne         $v0, $zero, L_8007D5E0
    if (ctx->r2 != 0) {
        // 0x8007D5A0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8007D5E0;
    }
    // 0x8007D5A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007D5A4: j           L_8007D5E0
    // 0x8007D5A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007D5E0;
    // 0x8007D5A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007D5AC:
    // 0x8007D5AC: blez        $a2, L_8007D5CC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8007D5B0: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8007D5CC;
    }
    // 0x8007D5B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8007D5B4: andi        $v1, $v1, 0x800F
    ctx->r3 = ctx->r3 & 0X800F;
    // 0x8007D5B8: ori         $v1, $v1, 0x3FF0
    ctx->r3 = ctx->r3 | 0X3FF0;
    // 0x8007D5BC: sh          $v1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r3;
    // 0x8007D5C0: addiu       $v1, $a3, -0x3FE
    ctx->r3 = ADD32(ctx->r7, -0X3FE);
    // 0x8007D5C4: j           L_8007D5E0
    // 0x8007D5C8: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
        goto L_8007D5E0;
    // 0x8007D5C8: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
L_8007D5CC:
    // 0x8007D5CC: bltz        $a2, L_8007D5DC
    if (SIGNED(ctx->r6) < 0) {
        // 0x8007D5D0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8007D5DC;
    }
    // 0x8007D5D0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8007D5D4: j           L_8007D5E0
    // 0x8007D5D8: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
        goto L_8007D5E0;
    // 0x8007D5D8: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
L_8007D5DC:
    // 0x8007D5DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8007D5E0:
    // 0x8007D5E0: jr          $ra
    // 0x8007D5E4: nop

    return;
    // 0x8007D5E4: nop

;}
RECOMP_FUNC void func_8007D5E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D5E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007D5EC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8007D5F0: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8007D5F4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8007D5F8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8007D5FC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8007D600: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8007D604: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8007D608: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8007D60C: addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // 0x8007D610: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8007D614: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8007D618: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8007D61C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8007D620: bgtz        $a3, L_8007D634
    if (SIGNED(ctx->r7) > 0) {
        // 0x8007D624: addu        $s4, $a1, $zero
        ctx->r20 = ADD32(ctx->r5, 0);
            goto L_8007D634;
    }
    // 0x8007D624: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8007D628: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8007D62C: lui         $s2, 0x800C
    ctx->r18 = S32(0X800C << 16);
    // 0x8007D630: addiu       $s2, $s2, 0x26D0
    ctx->r18 = ADD32(ctx->r18, 0X26D0);
L_8007D634:
    // 0x8007D634: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8007D638: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8007D63C: beq         $a0, $a2, L_8007D67C
    if (ctx->r4 == ctx->r6) {
        // 0x8007D640: xori        $v1, $a0, 0x67
        ctx->r3 = ctx->r4 ^ 0X67;
            goto L_8007D67C;
    }
    // 0x8007D640: xori        $v1, $a0, 0x67
    ctx->r3 = ctx->r4 ^ 0X67;
    // 0x8007D644: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8007D648: xori        $v0, $a0, 0x47
    ctx->r2 = ctx->r4 ^ 0X47;
    // 0x8007D64C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007D650: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8007D654: beq         $v1, $zero, L_8007D924
    if (ctx->r3 == 0) {
        // 0x8007D658: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_8007D924;
    }
    // 0x8007D658: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8007D65C: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007D660: slti        $v0, $v1, -0x4
    ctx->r2 = SIGNED(ctx->r3) < -0X4 ? 1 : 0;
    // 0x8007D664: bne         $v0, $zero, L_8007D8D4
    if (ctx->r2 != 0) {
        // 0x8007D668: andi        $v0, $s3, 0xFF
        ctx->r2 = ctx->r19 & 0XFF;
            goto L_8007D8D4;
    }
    // 0x8007D668: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x8007D66C: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8007D670: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007D674: beq         $v0, $zero, L_8007D8D4
    if (ctx->r2 == 0) {
        // 0x8007D678: andi        $v0, $s3, 0xFF
        ctx->r2 = ctx->r19 & 0XFF;
            goto L_8007D8D4;
    }
    // 0x8007D678: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
L_8007D67C:
    // 0x8007D67C: beq         $a0, $a2, L_8007D6C4
    if (ctx->r4 == ctx->r6) {
        // 0x8007D680: addiu       $s4, $a1, 0x1
        ctx->r20 = ADD32(ctx->r5, 0X1);
            goto L_8007D6C4;
    }
    // 0x8007D680: addiu       $s4, $a1, 0x1
    ctx->r20 = ADD32(ctx->r5, 0X1);
    // 0x8007D684: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8007D688: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8007D68C: bne         $v0, $zero, L_8007D6A8
    if (ctx->r2 != 0) {
        // 0x8007D690: sll         $v1, $s5, 16
        ctx->r3 = S32(ctx->r21 << 16);
            goto L_8007D6A8;
    }
    // 0x8007D690: sll         $v1, $s5, 16
    ctx->r3 = S32(ctx->r21 << 16);
    // 0x8007D694: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8007D698: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8007D69C: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007D6A0: bnel        $v0, $zero, L_8007D6A8
    if (ctx->r2 != 0) {
        // 0x8007D6A4: sw          $v1, 0x24($s1)
        MEM_W(0X24, ctx->r17) = ctx->r3;
            goto L_8007D6A8;
    }
    goto skip_0;
    // 0x8007D6A4: sw          $v1, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r3;
    skip_0:
L_8007D6A8:
    // 0x8007D6A8: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8007D6AC: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8007D6B0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007D6B4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8007D6B8: bgez        $v1, L_8007D6C4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007D6BC: sw          $v1, 0x24($s1)
        MEM_W(0X24, ctx->r17) = ctx->r3;
            goto L_8007D6C4;
    }
    // 0x8007D6BC: sw          $v1, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r3;
    // 0x8007D6C0: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
L_8007D6C4:
    // 0x8007D6C4: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8007D6C8: sra         $s3, $v0, 16
    ctx->r19 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007D6CC: bgtz        $s3, L_8007D7A8
    if (SIGNED(ctx->r19) > 0) {
        // 0x8007D6D0: sll         $v0, $s5, 16
        ctx->r2 = S32(ctx->r21 << 16);
            goto L_8007D7A8;
    }
    // 0x8007D6D0: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x8007D6D4: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8007D6D8: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x8007D6DC: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8007D6E0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8007D6E4: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8007D6E8: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x8007D6EC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8007D6F0: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8007D6F4: bgtz        $v0, L_8007D70C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8007D6F8: nop
    
            goto L_8007D70C;
    }
    // 0x8007D6F8: nop

    // 0x8007D6FC: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8007D700: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8007D704: beq         $v0, $zero, L_8007D72C
    if (ctx->r2 == 0) {
        // 0x8007D708: sll         $v0, $s4, 16
        ctx->r2 = S32(ctx->r20 << 16);
            goto L_8007D72C;
    }
    // 0x8007D708: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
L_8007D70C:
    // 0x8007D70C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8007D710: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x8007D714: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8007D718: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8007D71C: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8007D720: addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // 0x8007D724: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8007D728: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
L_8007D72C:
    // 0x8007D72C: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8007D730: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007D734: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8007D738: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007D73C: bnel        $v0, $zero, L_8007D744
    if (ctx->r2 != 0) {
        // 0x8007D740: negu        $s4, $v1
        ctx->r20 = SUB32(0, ctx->r3);
            goto L_8007D744;
    }
    goto skip_1;
    // 0x8007D740: negu        $s4, $v1
    ctx->r20 = SUB32(0, ctx->r3);
    skip_1:
L_8007D744:
    // 0x8007D744: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8007D748: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x8007D74C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007D750: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8007D754: sw          $v1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r3;
    // 0x8007D758: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8007D75C: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x8007D760: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007D764: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007D768: beq         $v0, $zero, L_8007D774
    if (ctx->r2 == 0) {
        // 0x8007D76C: sw          $a0, 0x24($s1)
        MEM_W(0X24, ctx->r17) = ctx->r4;
            goto L_8007D774;
    }
    // 0x8007D76C: sw          $a0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r4;
    // 0x8007D770: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
L_8007D774:
    // 0x8007D774: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8007D778: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8007D77C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8007D780: sll         $s0, $s5, 16
    ctx->r16 = S32(ctx->r21 << 16);
    // 0x8007D784: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8007D788: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8007D78C: sw          $s0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r16;
    // 0x8007D790: jal         0x800731EC
    // 0x8007D794: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_800731EC(rdram, ctx);
        goto after_0;
    // 0x8007D794: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // 0x8007D798: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8007D79C: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x8007D7A0: j           L_8007DB18
    // 0x8007D7A4: sw          $v0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r2;
        goto L_8007DB18;
    // 0x8007D7A4: sw          $v0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r2;
L_8007D7A8:
    // 0x8007D7A8: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007D7AC: slt         $v0, $s0, $s3
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8007D7B0: beq         $v0, $zero, L_8007D824
    if (ctx->r2 == 0) {
        // 0x8007D7B4: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_8007D824;
    }
    // 0x8007D7B4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8007D7B8: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8007D7BC: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8007D7C0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8007D7C4: jal         0x800731EC
    // 0x8007D7C8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_800731EC(rdram, ctx);
        goto after_1;
    // 0x8007D7C8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_1:
    // 0x8007D7CC: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x8007D7D0: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x8007D7D4: subu        $v0, $s3, $s0
    ctx->r2 = SUB32(ctx->r19, ctx->r16);
    // 0x8007D7D8: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x8007D7DC: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x8007D7E0: bgtz        $a0, L_8007D7F8
    if (SIGNED(ctx->r4) > 0) {
        // 0x8007D7E4: sw          $v1, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->r3;
            goto L_8007D7F8;
    }
    // 0x8007D7E4: sw          $v1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r3;
    // 0x8007D7E8: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8007D7EC: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8007D7F0: beq         $v0, $zero, L_8007D818
    if (ctx->r2 == 0) {
        // 0x8007D7F4: nop
    
            goto L_8007D818;
    }
    // 0x8007D7F4: nop

L_8007D7F8:
    // 0x8007D7F8: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8007D7FC: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x8007D800: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007D804: addiu       $v1, $zero, 0x2E
    ctx->r3 = ADD32(0, 0X2E);
    // 0x8007D808: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8007D80C: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x8007D810: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007D814: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_8007D818:
    // 0x8007D818: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8007D81C: j           L_8007DB18
    // 0x8007D820: sw          $v0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r2;
        goto L_8007DB18;
    // 0x8007D820: sw          $v0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r2;
L_8007D824:
    // 0x8007D824: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8007D828: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8007D82C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8007D830: jal         0x800731EC
    // 0x8007D834: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_800731EC(rdram, ctx);
        goto after_2;
    // 0x8007D834: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_2:
    // 0x8007D838: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x8007D83C: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8007D840: subu        $s5, $s5, $s4
    ctx->r21 = SUB32(ctx->r21, ctx->r20);
    // 0x8007D844: addu        $a2, $v0, $s3
    ctx->r6 = ADD32(ctx->r2, ctx->r19);
    // 0x8007D848: bgtz        $v1, L_8007D860
    if (SIGNED(ctx->r3) > 0) {
        // 0x8007D84C: sw          $a2, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->r6;
            goto L_8007D860;
    }
    // 0x8007D84C: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x8007D850: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8007D854: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8007D858: beq         $v0, $zero, L_8007D878
    if (ctx->r2 == 0) {
        // 0x8007D85C: nop
    
            goto L_8007D878;
    }
    // 0x8007D85C: nop

L_8007D860:
    // 0x8007D860: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8007D864: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x8007D868: sw          $v1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r3;
    // 0x8007D86C: addiu       $v1, $zero, 0x2E
    ctx->r3 = ADD32(0, 0X2E);
    // 0x8007D870: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8007D874: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8007D878:
    // 0x8007D878: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8007D87C: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x8007D880: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007D884: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007D888: bnel        $v0, $zero, L_8007D890
    if (ctx->r2 != 0) {
        // 0x8007D88C: addu        $s5, $v1, $zero
        ctx->r21 = ADD32(ctx->r3, 0);
            goto L_8007D890;
    }
    goto skip_2;
    // 0x8007D88C: addu        $s5, $v1, $zero
    ctx->r21 = ADD32(ctx->r3, 0);
    skip_2:
L_8007D890:
    // 0x8007D890: sll         $a1, $s4, 16
    ctx->r5 = S32(ctx->r20 << 16);
    // 0x8007D894: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8007D898: addu        $a1, $s2, $a1
    ctx->r5 = ADD32(ctx->r18, ctx->r5);
    // 0x8007D89C: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8007D8A0: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8007D8A4: sll         $s0, $s5, 16
    ctx->r16 = S32(ctx->r21 << 16);
    // 0x8007D8A8: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8007D8AC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8007D8B0: jal         0x800731EC
    // 0x8007D8B4: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_800731EC(rdram, ctx);
        goto after_3;
    // 0x8007D8B4: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_3:
    // 0x8007D8B8: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x8007D8BC: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8007D8C0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8007D8C4: subu        $v1, $v1, $s0
    ctx->r3 = SUB32(ctx->r3, ctx->r16);
    // 0x8007D8C8: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8007D8CC: j           L_8007DB18
    // 0x8007D8D0: sw          $v1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r3;
        goto L_8007DB18;
    // 0x8007D8D0: sw          $v1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r3;
L_8007D8D4:
    // 0x8007D8D4: xori        $v1, $v0, 0x67
    ctx->r3 = ctx->r2 ^ 0X67;
    // 0x8007D8D8: sltiu       $a0, $v1, 0x1
    ctx->r4 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8007D8DC: xori        $v0, $v0, 0x47
    ctx->r2 = ctx->r2 ^ 0X47;
    // 0x8007D8E0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007D8E4: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x8007D8E8: beq         $v0, $zero, L_8007D924
    if (ctx->r2 == 0) {
        // 0x8007D8EC: sll         $v1, $s5, 16
        ctx->r3 = S32(ctx->r21 << 16);
            goto L_8007D924;
    }
    // 0x8007D8EC: sll         $v1, $s5, 16
    ctx->r3 = S32(ctx->r21 << 16);
    // 0x8007D8F0: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8007D8F4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8007D8F8: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007D8FC: bnel        $v0, $zero, L_8007D904
    if (ctx->r2 != 0) {
        // 0x8007D900: sw          $v1, 0x24($s1)
        MEM_W(0X24, ctx->r17) = ctx->r3;
            goto L_8007D904;
    }
    goto skip_3;
    // 0x8007D900: sw          $v1, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r3;
    skip_3:
L_8007D904:
    // 0x8007D904: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8007D908: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8007D90C: bgez        $v0, L_8007D918
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007D910: sw          $v0, 0x24($s1)
        MEM_W(0X24, ctx->r17) = ctx->r2;
            goto L_8007D918;
    }
    // 0x8007D910: sw          $v0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r2;
    // 0x8007D914: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
L_8007D918:
    // 0x8007D918: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
    // 0x8007D91C: andi        $v0, $v0, 0x65
    ctx->r2 = ctx->r2 & 0X65;
    // 0x8007D920: ori         $s3, $v0, 0x45
    ctx->r19 = ctx->r2 | 0X45;
L_8007D924:
    // 0x8007D924: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8007D928: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8007D92C: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8007D930: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8007D934: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x8007D938: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8007D93C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8007D940: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8007D944: bgtz        $v0, L_8007D95C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8007D948: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8007D95C;
    }
    // 0x8007D948: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007D94C: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8007D950: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8007D954: beq         $v0, $zero, L_8007D978
    if (ctx->r2 == 0) {
        // 0x8007D958: nop
    
            goto L_8007D978;
    }
    // 0x8007D958: nop

L_8007D95C:
    // 0x8007D95C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8007D960: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x8007D964: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8007D968: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8007D96C: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8007D970: addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // 0x8007D974: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8007D978:
    // 0x8007D978: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8007D97C: blez        $v1, L_8007D9D4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007D980: addiu       $v0, $s5, -0x1
        ctx->r2 = ADD32(ctx->r21, -0X1);
            goto L_8007D9D4;
    }
    // 0x8007D980: addiu       $v0, $s5, -0x1
    ctx->r2 = ADD32(ctx->r21, -0X1);
    // 0x8007D984: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x8007D988: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8007D98C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007D990: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007D994: bnel        $v0, $zero, L_8007D99C
    if (ctx->r2 != 0) {
        // 0x8007D998: addu        $s5, $v1, $zero
        ctx->r21 = ADD32(ctx->r3, 0);
            goto L_8007D99C;
    }
    goto skip_4;
    // 0x8007D998: addu        $s5, $v1, $zero
    ctx->r21 = ADD32(ctx->r3, 0);
    skip_4:
L_8007D99C:
    // 0x8007D99C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8007D9A0: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8007D9A4: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8007D9A8: sll         $s0, $s5, 16
    ctx->r16 = S32(ctx->r21 << 16);
    // 0x8007D9AC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8007D9B0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8007D9B4: jal         0x800731EC
    // 0x8007D9B8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_800731EC(rdram, ctx);
        goto after_4;
    // 0x8007D9B8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_4:
    // 0x8007D9BC: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x8007D9C0: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8007D9C4: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8007D9C8: subu        $v1, $v1, $s0
    ctx->r3 = SUB32(ctx->r3, ctx->r16);
    // 0x8007D9CC: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8007D9D0: sw          $v1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r3;
L_8007D9D4:
    // 0x8007D9D4: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8007D9D8: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x8007D9DC: addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // 0x8007D9E0: sb          $s3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r19;
    // 0x8007D9E4: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8007D9E8: bltz        $v0, L_8007DA00
    if (SIGNED(ctx->r2) < 0) {
        // 0x8007D9EC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8007DA00;
    }
    // 0x8007D9EC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007D9F0: addiu       $v0, $zero, 0x2B
    ctx->r2 = ADD32(0, 0X2B);
    // 0x8007D9F4: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x8007D9F8: j           L_8007DA10
    // 0x8007D9FC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8007DA10;
    // 0x8007D9FC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8007DA00:
    // 0x8007DA00: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    // 0x8007DA04: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x8007DA08: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007DA0C: negu        $s4, $s4
    ctx->r20 = SUB32(0, ctx->r20);
L_8007DA10:
    // 0x8007DA10: sll         $a1, $s4, 16
    ctx->r5 = S32(ctx->r20 << 16);
    // 0x8007DA14: sra         $a0, $a1, 16
    ctx->r4 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8007DA18: slti        $v0, $a0, 0x64
    ctx->r2 = SIGNED(ctx->r4) < 0X64 ? 1 : 0;
    // 0x8007DA1C: bne         $v0, $zero, L_8007DABC
    if (ctx->r2 != 0) {
        // 0x8007DA20: lui         $v1, 0x6666
        ctx->r3 = S32(0X6666 << 16);
            goto L_8007DABC;
    }
    // 0x8007DA20: lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // 0x8007DA24: slti        $v0, $a0, 0x3E8
    ctx->r2 = SIGNED(ctx->r4) < 0X3E8 ? 1 : 0;
    // 0x8007DA28: bne         $v0, $zero, L_8007DA74
    if (ctx->r2 != 0) {
        // 0x8007DA2C: lui         $v1, 0x51EB
        ctx->r3 = S32(0X51EB << 16);
            goto L_8007DA74;
    }
    // 0x8007DA2C: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x8007DA30: lui         $v0, 0x1062
    ctx->r2 = S32(0X1062 << 16);
    // 0x8007DA34: ori         $v0, $v0, 0x4DD3
    ctx->r2 = ctx->r2 | 0X4DD3;
    // 0x8007DA38: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007DA3C: sra         $v0, $a1, 31
    ctx->r2 = S32(SIGNED(ctx->r5) >> 31);
    // 0x8007DA40: mfhi        $t0
    ctx->r8 = hi;
    // 0x8007DA44: sra         $v1, $t0, 6
    ctx->r3 = S32(SIGNED(ctx->r8) >> 6);
    // 0x8007DA48: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8007DA4C: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8007DA50: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x8007DA54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007DA58: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x8007DA5C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007DA60: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007DA64: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007DA68: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8007DA6C: subu        $s4, $a0, $v0
    ctx->r20 = SUB32(ctx->r4, ctx->r2);
    // 0x8007DA70: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
L_8007DA74:
    // 0x8007DA74: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x8007DA78: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8007DA7C: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007DA80: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007DA84: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8007DA88: mfhi        $t0
    ctx->r8 = hi;
    // 0x8007DA8C: sra         $v1, $t0, 5
    ctx->r3 = S32(SIGNED(ctx->r8) >> 5);
    // 0x8007DA90: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8007DA94: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8007DA98: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x8007DA9C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007DAA0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8007DAA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007DAA8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8007DAAC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007DAB0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007DAB4: subu        $s4, $a0, $v0
    ctx->r20 = SUB32(ctx->r4, ctx->r2);
    // 0x8007DAB8: lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
L_8007DABC:
    // 0x8007DABC: ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // 0x8007DAC0: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8007DAC4: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007DAC8: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007DACC: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8007DAD0: mfhi        $t0
    ctx->r8 = hi;
    // 0x8007DAD4: sra         $v1, $t0, 2
    ctx->r3 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007DAD8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8007DADC: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8007DAE0: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x8007DAE4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007DAE8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8007DAEC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007DAF0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8007DAF4: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8007DAF8: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x8007DAFC: sb          $a0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r4;
    // 0x8007DB00: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8007DB04: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x8007DB08: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007DB0C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007DB10: subu        $v0, $s2, $v0
    ctx->r2 = SUB32(ctx->r18, ctx->r2);
    // 0x8007DB14: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_8007DB18:
    // 0x8007DB18: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8007DB1C: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8007DB20: andi        $v0, $v0, 0x14
    ctx->r2 = ctx->r2 & 0X14;
    // 0x8007DB24: bne         $v0, $v1, L_8007DB64
    if (ctx->r2 != ctx->r3) {
        // 0x8007DB28: nop
    
            goto L_8007DB64;
    }
    // 0x8007DB28: nop

    // 0x8007DB2C: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8007DB30: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x8007DB34: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x8007DB38: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007DB3C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8007DB40: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x8007DB44: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x8007DB48: lw          $a1, 0x28($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X28);
    // 0x8007DB4C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007DB50: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x8007DB54: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007DB58: beq         $v0, $zero, L_8007DB64
    if (ctx->r2 == 0) {
        // 0x8007DB5C: subu        $v0, $a1, $v1
        ctx->r2 = SUB32(ctx->r5, ctx->r3);
            goto L_8007DB64;
    }
    // 0x8007DB5C: subu        $v0, $a1, $v1
    ctx->r2 = SUB32(ctx->r5, ctx->r3);
    // 0x8007DB60: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
L_8007DB64:
    // 0x8007DB64: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8007DB68: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8007DB6C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8007DB70: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8007DB74: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8007DB78: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8007DB7C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8007DB80: jr          $ra
    // 0x8007DB84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007DB84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007DB88: nop

    // 0x8007DB8C: nop

;}
