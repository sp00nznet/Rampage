#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_80060D70(uint8_t* rdram, recomp_context* ctx);
void func_80061230(uint8_t* rdram, recomp_context* ctx);
void func_80061500(uint8_t* rdram, recomp_context* ctx);
void func_8006170C(uint8_t* rdram, recomp_context* ctx);
void func_80061B00(uint8_t* rdram, recomp_context* ctx);
void func_800620C8(uint8_t* rdram, recomp_context* ctx);
void func_80062480(uint8_t* rdram, recomp_context* ctx);
void func_80062600(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_800605A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800605A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800605AC: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800605B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800605B4: addiu       $v0, $v0, -0x9E0
    ctx->r2 = ADD32(ctx->r2, -0X9E0);
    // 0x800605B8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800605BC: addu        $s2, $a0, $v0
    ctx->r18 = ADD32(ctx->r4, ctx->r2);
    // 0x800605C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800605C4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800605C8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800605CC: lhu         $a0, 0x4($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X4);
    // 0x800605D0: jal         0x8005DFF0
    // 0x800605D4: nop

    func_8005DFF0(rdram, ctx);
        goto after_0;
    // 0x800605D4: nop

    after_0:
    // 0x800605D8: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x800605DC: addiu       $s0, $s0, 0x67A0
    ctx->r16 = ADD32(ctx->r16, 0X67A0);
    // 0x800605E0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800605E4: beq         $s1, $zero, L_80060654
    if (ctx->r17 == 0) {
        // 0x800605E8: addu        $a2, $s0, $zero
        ctx->r6 = ADD32(ctx->r16, 0);
            goto L_80060654;
    }
    // 0x800605E8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800605EC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800605F0: lhu         $v0, 0x6($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X6);
    // 0x800605F4: lui         $a0, 0x11
    ctx->r4 = S32(0X11 << 16);
    // 0x800605F8: addiu       $a0, $a0, 0x1850
    ctx->r4 = ADD32(ctx->r4, 0X1850);
    // 0x800605FC: addiu       $a1, $zero, -0x2
    ctx->r5 = ADD32(0, -0X2);
    // 0x80060600: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x80060604: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80060608: jal         0x80060D70
    // 0x8006060C: and         $a1, $v0, $a1
    ctx->r5 = ctx->r2 & ctx->r5;
    func_80060D70(rdram, ctx);
        goto after_1;
    // 0x8006060C: and         $a1, $v0, $a1
    ctx->r5 = ctx->r2 & ctx->r5;
    after_1:
    // 0x80060610: lhu         $a2, 0x6($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X6);
    // 0x80060614: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80060618: jal         0x8005D328
    // 0x8006061C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8005D328(rdram, ctx);
        goto after_2;
    // 0x8006061C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // 0x80060620: lui         $v0, 0xDFFF
    ctx->r2 = S32(0XDFFF << 16);
    // 0x80060624: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80060628: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8006062C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80060630: lhu         $a2, 0x4($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X4);
    // 0x80060634: and         $v0, $s0, $v0
    ctx->r2 = ctx->r16 & ctx->r2;
    // 0x80060638: addu        $a1, $s1, $v0
    ctx->r5 = ADD32(ctx->r17, ctx->r2);
    // 0x8006063C: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x80060640: lui         $v0, 0x2000
    ctx->r2 = S32(0X2000 << 16);
    // 0x80060644: jal         0x8007DE54
    // 0x80060648: and         $s0, $s0, $v0
    ctx->r16 = ctx->r16 & ctx->r2;
    func_8007DE54(rdram, ctx);
        goto after_3;
    // 0x80060648: and         $s0, $s0, $v0
    ctx->r16 = ctx->r16 & ctx->r2;
    after_3:
    // 0x8006064C: j           L_80060658
    // 0x80060650: or          $v0, $s1, $s0
    ctx->r2 = ctx->r17 | ctx->r16;
        goto L_80060658;
    // 0x80060650: or          $v0, $s1, $s0
    ctx->r2 = ctx->r17 | ctx->r16;
L_80060654:
    // 0x80060654: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80060658:
    // 0x80060658: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006065C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80060660: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80060664: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80060668: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006066C: jr          $ra
    // 0x80060670: nop

    return;
    // 0x80060670: nop

    // 0x80060674: nop

    // 0x80060678: nop

    // 0x8006067C: nop

;}
RECOMP_FUNC void func_80060680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060680: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80060684: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80060688: sra         $v1, $v1, 8
    ctx->r3 = S32(SIGNED(ctx->r3) >> 8);
    // 0x8006068C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80060690: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80060694: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80060698: lw          $a1, -0x1034($at)
    ctx->r5 = MEM_W(ctx->r1, -0X1034);
    // 0x8006069C: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x800606A0: addiu       $a3, $a3, -0x69C
    ctx->r7 = ADD32(ctx->r7, -0X69C);
    // 0x800606A4: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x800606A8: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800606AC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800606B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800606B4: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800606B8: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800606BC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800606C0: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800606C4: mflo        $v1
    ctx->r3 = lo;
    // 0x800606C8: nop

    // 0x800606CC: nop

    // 0x800606D0: sra         $v1, $v1, 8
    ctx->r3 = S32(SIGNED(ctx->r3) >> 8);
    // 0x800606D4: jr          $ra
    // 0x800606D8: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    return;
    // 0x800606D8: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_800606DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800606DC: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800606E0: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x800606E4: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x800606E8: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x800606EC: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800606F0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800606F4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800606F8: lb          $a0, 0x3($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X3);
    // 0x800606FC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80060700: addiu       $v1, $v1, -0x678
    ctx->r3 = ADD32(ctx->r3, -0X678);
    // 0x80060704: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x80060708: slti        $v0, $a0, -0x1E
    ctx->r2 = SIGNED(ctx->r4) < -0X1E ? 1 : 0;
    // 0x8006070C: beq         $v0, $zero, L_80060774
    if (ctx->r2 == 0) {
        // 0x80060710: lui         $t1, 0x1
        ctx->r9 = S32(0X1 << 16);
            goto L_80060774;
    }
    // 0x80060710: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x80060714: lui         $a0, 0x6666
    ctx->r4 = S32(0X6666 << 16);
    // 0x80060718: lb          $v1, 0x3($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X3);
    // 0x8006071C: ori         $a0, $a0, 0x6667
    ctx->r4 = ctx->r4 | 0X6667;
    // 0x80060720: addiu       $v0, $zero, -0x1E
    ctx->r2 = ADD32(0, -0X1E);
    // 0x80060724: subu        $t1, $v0, $v1
    ctx->r9 = SUB32(ctx->r2, ctx->r3);
    // 0x80060728: sll         $v1, $t1, 16
    ctx->r3 = S32(ctx->r9 << 16);
    // 0x8006072C: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060730: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x80060734: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x80060738: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    // 0x8006073C: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x80060740: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x80060744: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x80060748: mfhi        $t3
    ctx->r11 = hi;
    // 0x8006074C: nop

    // 0x80060750: nop

    // 0x80060754: sra         $v0, $t3, 4
    ctx->r2 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80060758: subu        $t1, $v0, $v1
    ctx->r9 = SUB32(ctx->r2, ctx->r3);
    // 0x8006075C: slt         $a0, $a0, $t1
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80060760: beq         $a0, $zero, L_800607D4
    if (ctx->r4 == 0) {
        // 0x80060764: nop
    
            goto L_800607D4;
    }
    // 0x80060764: nop

    // 0x80060768: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8006076C: j           L_800607D4
    // 0x80060770: ori         $t1, $t1, 0x2000
    ctx->r9 = ctx->r9 | 0X2000;
        goto L_800607D4;
    // 0x80060770: ori         $t1, $t1, 0x2000
    ctx->r9 = ctx->r9 | 0X2000;
L_80060774:
    // 0x80060774: slti        $v0, $a0, 0x1F
    ctx->r2 = SIGNED(ctx->r4) < 0X1F ? 1 : 0;
    // 0x80060778: bne         $v0, $zero, L_800607D4
    if (ctx->r2 != 0) {
        // 0x8006077C: lui         $a0, 0x6666
        ctx->r4 = S32(0X6666 << 16);
            goto L_800607D4;
    }
    // 0x8006077C: lui         $a0, 0x6666
    ctx->r4 = S32(0X6666 << 16);
    // 0x80060780: lb          $v0, 0x3($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X3);
    // 0x80060784: ori         $a0, $a0, 0x6667
    ctx->r4 = ctx->r4 | 0X6667;
    // 0x80060788: addiu       $t0, $v0, -0x1E
    ctx->r8 = ADD32(ctx->r2, -0X1E);
    // 0x8006078C: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x80060790: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060794: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x80060798: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8006079C: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    // 0x800607A0: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x800607A4: ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // 0x800607A8: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x800607AC: mfhi        $t3
    ctx->r11 = hi;
    // 0x800607B0: nop

    // 0x800607B4: nop

    // 0x800607B8: sra         $v0, $t3, 4
    ctx->r2 = S32(SIGNED(ctx->r11) >> 4);
    // 0x800607BC: subu        $t0, $v0, $v1
    ctx->r8 = SUB32(ctx->r2, ctx->r3);
    // 0x800607C0: slt         $a0, $a0, $t0
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800607C4: beq         $a0, $zero, L_800607D4
    if (ctx->r4 == 0) {
        // 0x800607C8: nop
    
            goto L_800607D4;
    }
    // 0x800607C8: nop

    // 0x800607CC: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x800607D0: ori         $t0, $t0, 0x2000
    ctx->r8 = ctx->r8 | 0X2000;
L_800607D4:
    // 0x800607D4: lb          $v1, 0x2($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X2);
    // 0x800607D8: slti        $v0, $v1, -0x1E
    ctx->r2 = SIGNED(ctx->r3) < -0X1E ? 1 : 0;
    // 0x800607DC: beq         $v0, $zero, L_80060840
    if (ctx->r2 == 0) {
        // 0x800607E0: lui         $a0, 0x6666
        ctx->r4 = S32(0X6666 << 16);
            goto L_80060840;
    }
    // 0x800607E0: lui         $a0, 0x6666
    ctx->r4 = S32(0X6666 << 16);
    // 0x800607E4: lb          $v1, 0x2($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X2);
    // 0x800607E8: ori         $a0, $a0, 0x6667
    ctx->r4 = ctx->r4 | 0X6667;
    // 0x800607EC: addiu       $v0, $zero, -0x1E
    ctx->r2 = ADD32(0, -0X1E);
    // 0x800607F0: subu        $a3, $v0, $v1
    ctx->r7 = SUB32(ctx->r2, ctx->r3);
    // 0x800607F4: sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7 << 16);
    // 0x800607F8: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800607FC: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x80060800: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x80060804: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    // 0x80060808: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8006080C: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
    // 0x80060810: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x80060814: mfhi        $t3
    ctx->r11 = hi;
    // 0x80060818: nop

    // 0x8006081C: nop

    // 0x80060820: sra         $v0, $t3, 4
    ctx->r2 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80060824: subu        $a3, $v0, $v1
    ctx->r7 = SUB32(ctx->r2, ctx->r3);
    // 0x80060828: slt         $a0, $a0, $a3
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8006082C: beq         $a0, $zero, L_800608A8
    if (ctx->r4 == 0) {
        // 0x80060830: addu        $v0, $a3, $t0
        ctx->r2 = ADD32(ctx->r7, ctx->r8);
            goto L_800608A8;
    }
    // 0x80060830: addu        $v0, $a3, $t0
    ctx->r2 = ADD32(ctx->r7, ctx->r8);
    // 0x80060834: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x80060838: j           L_800608A4
    // 0x8006083C: ori         $a3, $a3, 0x2000
    ctx->r7 = ctx->r7 | 0X2000;
        goto L_800608A4;
    // 0x8006083C: ori         $a3, $a3, 0x2000
    ctx->r7 = ctx->r7 | 0X2000;
L_80060840:
    // 0x80060840: slti        $v0, $v1, 0x1F
    ctx->r2 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
    // 0x80060844: bne         $v0, $zero, L_800608A8
    if (ctx->r2 != 0) {
        // 0x80060848: addu        $v0, $a3, $t0
        ctx->r2 = ADD32(ctx->r7, ctx->r8);
            goto L_800608A8;
    }
    // 0x80060848: addu        $v0, $a3, $t0
    ctx->r2 = ADD32(ctx->r7, ctx->r8);
    // 0x8006084C: lb          $v0, 0x2($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X2);
    // 0x80060850: lui         $a0, 0x6666
    ctx->r4 = S32(0X6666 << 16);
    // 0x80060854: ori         $a0, $a0, 0x6667
    ctx->r4 = ctx->r4 | 0X6667;
    // 0x80060858: addiu       $t2, $v0, -0x1E
    ctx->r10 = ADD32(ctx->r2, -0X1E);
    // 0x8006085C: sll         $v1, $t2, 16
    ctx->r3 = S32(ctx->r10 << 16);
    // 0x80060860: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060864: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x80060868: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8006086C: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    // 0x80060870: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x80060874: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x80060878: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x8006087C: mfhi        $t3
    ctx->r11 = hi;
    // 0x80060880: nop

    // 0x80060884: nop

    // 0x80060888: sra         $v0, $t3, 4
    ctx->r2 = S32(SIGNED(ctx->r11) >> 4);
    // 0x8006088C: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x80060890: slt         $a0, $a0, $t2
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80060894: beq         $a0, $zero, L_800608A8
    if (ctx->r4 == 0) {
        // 0x80060898: addu        $v0, $a3, $t0
        ctx->r2 = ADD32(ctx->r7, ctx->r8);
            goto L_800608A8;
    }
    // 0x80060898: addu        $v0, $a3, $t0
    ctx->r2 = ADD32(ctx->r7, ctx->r8);
    // 0x8006089C: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x800608A0: ori         $t2, $t2, 0x2000
    ctx->r10 = ctx->r10 | 0X2000;
L_800608A4:
    // 0x800608A4: addu        $v0, $a3, $t0
    ctx->r2 = ADD32(ctx->r7, ctx->r8);
L_800608A8:
    // 0x800608A8: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800608AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800608B0: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800608B4: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // 0x800608B8: addu        $v0, $a3, $t1
    ctx->r2 = ADD32(ctx->r7, ctx->r9);
    // 0x800608BC: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800608C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800608C4: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800608C8: sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
    // 0x800608CC: addu        $v0, $t2, $t0
    ctx->r2 = ADD32(ctx->r10, ctx->r8);
    // 0x800608D0: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800608D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800608D8: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800608DC: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x800608E0: addu        $v0, $t2, $t1
    ctx->r2 = ADD32(ctx->r10, ctx->r9);
    // 0x800608E4: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800608E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800608EC: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800608F0: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x800608F4: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x800608F8: sw          $a3, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r7;
    // 0x800608FC: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x80060900: jr          $ra
    // 0x80060904: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    return;
    // 0x80060904: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void func_80060908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006090C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80060910: jal         0x8005C180
    // 0x80060914: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    func_8005C180(rdram, ctx);
        goto after_0;
    // 0x80060914: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    after_0:
    // 0x80060918: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8006091C: sw          $v0, -0x67C($at)
    MEM_W(-0X67C, ctx->r1) = ctx->r2;
    // 0x80060920: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80060924: jal         0x800606DC
    // 0x80060928: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800606DC(rdram, ctx);
        goto after_1;
    // 0x80060928: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8006092C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80060930: lw          $v0, -0x67C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X67C);
    // 0x80060934: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80060938: jal         0x800606DC
    // 0x8006093C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800606DC(rdram, ctx);
        goto after_2;
    // 0x8006093C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80060940: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80060944: lw          $v0, -0x67C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X67C);
    // 0x80060948: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x8006094C: jal         0x800606DC
    // 0x80060950: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800606DC(rdram, ctx);
        goto after_3;
    // 0x80060950: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80060954: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80060958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006095C: jr          $ra
    // 0x80060960: nop

    return;
    // 0x80060960: nop

;}
RECOMP_FUNC void func_80060964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060964: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80060968: lw          $v0, -0x67C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X67C);
    // 0x8006096C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80060970: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80060974: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80060978: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006097C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80060980: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80060984: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80060988: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8006098C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80060990: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x80060994: lw          $t0, -0x4FC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4FC);
    // 0x80060998: bne         $a1, $zero, L_800609B8
    if (ctx->r5 != 0) {
        // 0x8006099C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800609B8;
    }
    // 0x8006099C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800609A0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800609A4: lhu         $v1, 0x90($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X90);
    // 0x800609A8: addiu       $v0, $zero, 0x120
    ctx->r2 = ADD32(0, 0X120);
    // 0x800609AC: bne         $v1, $v0, L_800609BC
    if (ctx->r3 != ctx->r2) {
        // 0x800609B0: sltu        $v0, $zero, $a0
        ctx->r2 = 0 < ctx->r4 ? 1 : 0;
            goto L_800609BC;
    }
    // 0x800609B0: sltu        $v0, $zero, $a0
    ctx->r2 = 0 < ctx->r4 ? 1 : 0;
    // 0x800609B4: sll         $a3, $v0, 8
    ctx->r7 = S32(ctx->r2 << 8);
L_800609B8:
    // 0x800609B8: sltu        $v0, $zero, $a0
    ctx->r2 = 0 < ctx->r4 ? 1 : 0;
L_800609BC:
    // 0x800609BC: slti        $v1, $a2, 0x10
    ctx->r3 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800609C0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800609C4: beq         $v0, $zero, L_80060A04
    if (ctx->r2 == 0) {
        // 0x800609C8: nop
    
            goto L_80060A04;
    }
    // 0x800609C8: nop

    // 0x800609CC: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800609D0: addu        $a1, $v0, $t0
    ctx->r5 = ADD32(ctx->r2, ctx->r8);
L_800609D4:
    // 0x800609D4: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800609D8: beq         $v0, $zero, L_800609E8
    if (ctx->r2 == 0) {
        // 0x800609DC: srl         $a0, $a0, 1
        ctx->r4 = S32(U32(ctx->r4) >> 1);
            goto L_800609E8;
    }
    // 0x800609DC: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x800609E0: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800609E4: or          $a3, $a3, $v0
    ctx->r7 = ctx->r7 | ctx->r2;
L_800609E8:
    // 0x800609E8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800609EC: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800609F0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800609F4: slti        $v1, $a2, 0x10
    ctx->r3 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800609F8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800609FC: bne         $v0, $zero, L_800609D4
    if (ctx->r2 != 0) {
        // 0x80060A00: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_800609D4;
    }
    // 0x80060A00: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_80060A04:
    // 0x80060A04: jr          $ra
    // 0x80060A08: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    return;
    // 0x80060A08: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
;}
RECOMP_FUNC void func_80060A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060A0C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80060A10: lw          $v0, -0x680($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X680);
    // FALLTHROUGH: func_80060A0C falls into func_80060A14
    func_80060A14(rdram, ctx);
;}
RECOMP_FUNC void func_80060A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060A14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80060A18: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80060A1C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80060A20: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80060A24: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80060A28: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80060A2C: bne         $v0, $zero, L_80060AC0
    if (ctx->r2 != 0) {
        // 0x80060A30: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80060AC0;
    }
    // 0x80060A30: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80060A34: jal         0x80060908
    // 0x80060A38: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    func_80060908(rdram, ctx);
        goto after_0;
    // 0x80060A38: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_0:
    // 0x80060A3C: andi        $s3, $s1, 0xFFFF
    ctx->r19 = ctx->r17 & 0XFFFF;
    // 0x80060A40: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80060A44: lw          $v0, -0x68F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68F0);
    // 0x80060A48: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80060A4C: addiu       $s2, $s2, 0x5BAC
    ctx->r18 = ADD32(ctx->r18, 0X5BAC);
    // 0x80060A50: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80060A54: addiu       $s1, $s1, 0x4DF8
    ctx->r17 = ADD32(ctx->r17, 0X4DF8);
    // 0x80060A58: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80060A5C: sw          $zero, -0x68F0($at)
    MEM_W(-0X68F0, ctx->r1) = 0;
    // 0x80060A60: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80060A64: sw          $v0, -0x68E4($at)
    MEM_W(-0X68E4, ctx->r1) = ctx->r2;
L_80060A68:
    // 0x80060A68: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x80060A6C: beq         $s3, $zero, L_80060A88
    if (ctx->r19 == 0) {
        // 0x80060A70: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80060A88;
    }
    // 0x80060A70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80060A74: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80060A78: lhu         $v0, 0x1A2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1A2);
    // 0x80060A7C: bne         $v0, $zero, L_80060A88
    if (ctx->r2 != 0) {
        // 0x80060A80: nop
    
            goto L_80060A88;
    }
    // 0x80060A80: nop

    // 0x80060A84: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
L_80060A88:
    // 0x80060A88: jal         0x80060964
    // 0x80060A8C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    func_80060964(rdram, ctx);
        goto after_1;
    // 0x80060A8C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    after_1:
    // 0x80060A90: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x80060A94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80060A98: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80060A9C: lw          $v1, -0x68F0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X68F0);
    // 0x80060AA0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80060AA4: sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2 << (ctx->r4 & 31));
    // 0x80060AA8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80060AAC: slti        $v0, $s0, 0x3
    ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80060AB0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80060AB4: sw          $v1, -0x68F0($at)
    MEM_W(-0X68F0, ctx->r1) = ctx->r3;
    // 0x80060AB8: bne         $v0, $zero, L_80060A68
    if (ctx->r2 != 0) {
        // 0x80060ABC: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_80060A68;
    }
    // 0x80060ABC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
L_80060AC0:
    // 0x80060AC0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80060AC4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80060AC8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80060ACC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80060AD0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80060AD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80060AD8: jr          $ra
    // 0x80060ADC: nop

    return;
    // 0x80060ADC: nop

;}
RECOMP_FUNC void func_80060AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060AE0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80060AE4: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80060AE8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80060AEC: addiu       $a1, $a1, 0x46A0
    ctx->r5 = ADD32(ctx->r5, 0X46A0);
    // 0x80060AF0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80060AF4: addiu       $a0, $a0, 0x3D8
    ctx->r4 = ADD32(ctx->r4, 0X3D8);
    // 0x80060AF8: addiu       $a3, $a1, 0x6
    ctx->r7 = ADD32(ctx->r5, 0X6);
    // 0x80060AFC: addiu       $a2, $a0, 0x6
    ctx->r6 = ADD32(ctx->r4, 0X6);
L_80060B00:
    // 0x80060B00: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80060B04: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80060B08: lbu         $v0, 0x4DE3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4DE3);
    // 0x80060B0C: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80060B10: beql        $v0, $zero, L_80060B2C
    if (ctx->r2 == 0) {
        // 0x80060B14: sh          $t0, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r8;
            goto L_80060B2C;
    }
    goto skip_0;
    // 0x80060B14: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    skip_0:
    // 0x80060B18: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x80060B1C: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x80060B20: addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    // 0x80060B24: j           L_80060B38
    // 0x80060B28: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
        goto L_80060B38;
    // 0x80060B28: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
L_80060B2C:
    // 0x80060B2C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x80060B30: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80060B34: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_80060B38:
    // 0x80060B38: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80060B3C: bgez        $v1, L_80060B00
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80060B40: nop
    
            goto L_80060B00;
    }
    // 0x80060B40: nop

    // 0x80060B44: jr          $ra
    // 0x80060B48: nop

    return;
    // 0x80060B48: nop

    // 0x80060B4C: nop

;}
RECOMP_FUNC void func_80060B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060B54: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80060B58: jal         0x800702A0
    // 0x80060B5C: nop

    func_800702A0(rdram, ctx);
        goto after_0;
    // 0x80060B5C: nop

    after_0:
    // 0x80060B60: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80060B64: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80060B68: jr          $ra
    // 0x80060B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80060B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80060B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060B70: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80060B74: ldc1        $f0, 0x1FD0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X1FD0);
    // 0x80060B78: mtc1        $a0, $f12
    ctx->f12.u32l = ctx->r4;
    // 0x80060B7C: nop

    // 0x80060B80: cvt.d.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.d = CVT_D_W(ctx->f12.u32l);
    // 0x80060B84: mul.d       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f0.d);
    // FALLTHROUGH: func_80060B70 falls into func_80060B88
    func_80060B88(rdram, ctx);
;}
RECOMP_FUNC void func_80060B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060B88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060B8C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80060B90: jal         0x80070100
    // 0x80060B94: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    func_80070100(rdram, ctx);
        goto after_0;
    // 0x80060B94: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    after_0:
    // 0x80060B98: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80060B9C: ldc1        $f2, 0x1FD8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X1FD8);
    // 0x80060BA0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80060BA4: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x80060BA8: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80060BAC: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80060BB0: nop

    // 0x80060BB4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80060BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060BBC: jr          $ra
    // 0x80060BC0: nop

    return;
    // 0x80060BC0: nop

;}
RECOMP_FUNC void func_80060BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060BC4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80060BC8: ldc1        $f0, 0x1FE0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X1FE0);
    // 0x80060BCC: mtc1        $a0, $f12
    ctx->f12.u32l = ctx->r4;
    // 0x80060BD0: nop

    // 0x80060BD4: cvt.d.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.d = CVT_D_W(ctx->f12.u32l);
    // 0x80060BD8: mul.d       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f0.d);
    // FALLTHROUGH: func_80060BC4 falls into func_80060BDC
    func_80060BDC(rdram, ctx);
;}
RECOMP_FUNC void func_80060BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060BDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060BE0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80060BE4: jal         0x80070100
    // 0x80060BE8: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    func_80070100(rdram, ctx);
        goto after_0;
    // 0x80060BE8: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    after_0:
    // 0x80060BEC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80060BF0: ldc1        $f2, 0x1FE8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X1FE8);
    // 0x80060BF4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80060BF8: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x80060BFC: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80060C00: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80060C04: nop

    // 0x80060C08: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80060C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060C10: jr          $ra
    // 0x80060C14: nop

    return;
    // 0x80060C14: nop

;}
RECOMP_FUNC void func_80060C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060C18: bgez        $a0, L_80060C30
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80060C1C: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80060C30;
    }
    // 0x80060C1C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80060C20: bgez        $a1, L_80060C38
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80060C24: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80060C38;
    }
    // 0x80060C24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80060C28: j           L_80060C38
    // 0x80060C2C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_80060C38;
    // 0x80060C2C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_80060C30:
    // 0x80060C30: bltzl       $a1, L_80060C38
    if (SIGNED(ctx->r5) < 0) {
        // 0x80060C34: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_80060C38;
    }
    goto skip_0;
    // 0x80060C34: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    skip_0:
L_80060C38:
    // 0x80060C38: bne         $a0, $zero, L_80060C50
    if (ctx->r4 != 0) {
        // 0x80060C3C: nop
    
            goto L_80060C50;
    }
    // 0x80060C3C: nop

    // 0x80060C40: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80060C44: lw          $a0, 0xB1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XB1C);
    // 0x80060C48: j           L_80060C7C
    // 0x80060C4C: nop

        goto L_80060C7C;
    // 0x80060C4C: nop

L_80060C50:
    // 0x80060C50: div         $zero, $a1, $a0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r4)));
    // 0x80060C54: bne         $a0, $zero, L_80060C60
    if (ctx->r4 != 0) {
        // 0x80060C58: nop
    
            goto L_80060C60;
    }
    // 0x80060C58: nop

    // 0x80060C5C: break       7
    do_break(2147880028);
L_80060C60:
    // 0x80060C60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80060C64: bne         $a0, $at, L_80060C78
    if (ctx->r4 != ctx->r1) {
        // 0x80060C68: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80060C78;
    }
    // 0x80060C68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80060C6C: bne         $a1, $at, L_80060C78
    if (ctx->r5 != ctx->r1) {
        // 0x80060C70: nop
    
            goto L_80060C78;
    }
    // 0x80060C70: nop

    // 0x80060C74: break       6
    do_break(2147880052);
L_80060C78:
    // 0x80060C78: mflo        $a0
    ctx->r4 = lo;
L_80060C7C:
    // 0x80060C7C: nop

    // 0x80060C80: nop

    // 0x80060C84: bltzl       $a0, L_80060C8C
    if (SIGNED(ctx->r4) < 0) {
        // 0x80060C88: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_80060C8C;
    }
    goto skip_1;
    // 0x80060C88: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    skip_1:
L_80060C8C:
    // 0x80060C8C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80060C90: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80060C94: addiu       $a2, $a2, -0x4DC
    ctx->r6 = ADD32(ctx->r6, -0X4DC);
L_80060C98:
    // 0x80060C98: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80060C9C: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80060CA0: bne         $v0, $zero, L_80060CBC
    if (ctx->r2 != 0) {
        // 0x80060CA4: sll         $v0, $a3, 10
        ctx->r2 = S32(ctx->r7 << 10);
            goto L_80060CBC;
    }
    // 0x80060CA4: sll         $v0, $a3, 10
    ctx->r2 = S32(ctx->r7 << 10);
    // 0x80060CA8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80060CAC: slti        $v0, $v1, 0x400
    ctx->r2 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x80060CB0: bne         $v0, $zero, L_80060C98
    if (ctx->r2 != 0) {
        // 0x80060CB4: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80060C98;
    }
    // 0x80060CB4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80060CB8: sll         $v0, $a3, 10
    ctx->r2 = S32(ctx->r7 << 10);
L_80060CBC:
    // 0x80060CBC: jr          $ra
    // 0x80060CC0: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    return;
    // 0x80060CC0: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
;}
RECOMP_FUNC void func_80060CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060CC4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80060CC8: ldc1        $f0, 0x1FF0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X1FF0);
    // 0x80060CCC: mtc1        $a0, $f12
    ctx->f12.u32l = ctx->r4;
    // 0x80060CD0: nop

    // 0x80060CD4: cvt.d.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.d = CVT_D_W(ctx->f12.u32l);
    // 0x80060CD8: mul.d       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f0.d);
    // FALLTHROUGH: func_80060CC4 falls into func_80060CDC
    func_80060CDC(rdram, ctx);
;}
RECOMP_FUNC void func_80060CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060CE0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80060CE4: jal         0x8006FAB0
    // 0x80060CE8: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    func_8006FAB0(rdram, ctx);
        goto after_0;
    // 0x80060CE8: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    after_0:
    // 0x80060CEC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80060CF0: ldc1        $f2, 0x1FF8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X1FF8);
    // 0x80060CF4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80060CF8: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x80060CFC: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80060D00: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80060D04: nop

    // 0x80060D08: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80060D0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060D10: jr          $ra
    // 0x80060D14: nop

    return;
    // 0x80060D14: nop

;}
RECOMP_FUNC void func_80060D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060D18: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80060D1C: ldc1        $f0, 0x2000($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X2000);
    // 0x80060D20: mtc1        $a0, $f12
    ctx->f12.u32l = ctx->r4;
    // 0x80060D24: nop

    // 0x80060D28: cvt.d.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.d = CVT_D_W(ctx->f12.u32l);
    // 0x80060D2C: mul.d       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f0.d);
    // FALLTHROUGH: func_80060D18 falls into func_80060D30
    func_80060D30(rdram, ctx);
;}
RECOMP_FUNC void func_80060D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060D34: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80060D38: jal         0x8006FAB0
    // 0x80060D3C: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    func_8006FAB0(rdram, ctx);
        goto after_0;
    // 0x80060D3C: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    after_0:
    // 0x80060D40: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80060D44: ldc1        $f2, 0x2008($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X2008);
    // 0x80060D48: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80060D4C: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x80060D50: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80060D54: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80060D58: nop

    // 0x80060D5C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80060D60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060D64: jr          $ra
    // 0x80060D68: nop

    return;
    // 0x80060D68: nop

    // 0x80060D6C: nop

;}
RECOMP_FUNC void func_80060D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060D70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80060D74: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80060D78: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80060D7C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80060D80: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80060D84: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80060D88: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80060D8C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80060D90: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80060D94: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80060D98: jal         0x800703E0
    // 0x80060D9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80060D9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x80060DA0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80060DA4: jal         0x800702D0
    // 0x80060DA8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_800702D0(rdram, ctx);
        goto after_1;
    // 0x80060DA8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80060DAC: beq         $s1, $zero, L_80060E10
    if (ctx->r17 == 0) {
        // 0x80060DB0: nop
    
            goto L_80060E10;
    }
    // 0x80060DB0: nop

    // 0x80060DB4: lui         $s4, 0x8016
    ctx->r20 = S32(0X8016 << 16);
    // 0x80060DB8: addiu       $s4, $s4, -0x74D8
    ctx->r20 = ADD32(ctx->r20, -0X74D8);
L_80060DBC:
    // 0x80060DBC: sltiu       $v0, $s1, 0x5001
    ctx->r2 = ctx->r17 < 0X5001 ? 1 : 0;
    // 0x80060DC0: beq         $v0, $zero, L_80060DCC
    if (ctx->r2 == 0) {
        // 0x80060DC4: addiu       $s0, $zero, 0x5000
        ctx->r16 = ADD32(0, 0X5000);
            goto L_80060DCC;
    }
    // 0x80060DC4: addiu       $s0, $zero, 0x5000
    ctx->r16 = ADD32(0, 0X5000);
    // 0x80060DC8: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_80060DCC:
    // 0x80060DCC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80060DD0: addiu       $a0, $a0, -0x2068
    ctx->r4 = ADD32(ctx->r4, -0X2068);
    // 0x80060DD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80060DD8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80060DDC: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // 0x80060DE0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80060DE4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80060DE8: jal         0x80072B20
    // 0x80060DEC: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    func_80072B20(rdram, ctx);
        goto after_2;
    // 0x80060DEC: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    after_2:
    // 0x80060DF0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80060DF4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80060DF8: jal         0x80070620
    // 0x80060DFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80060DFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80060E00: addu        $s3, $s3, $s0
    ctx->r19 = ADD32(ctx->r19, ctx->r16);
    // 0x80060E04: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80060E08: bne         $s1, $zero, L_80060DBC
    if (ctx->r17 != 0) {
        // 0x80060E0C: addu        $s2, $s2, $s0
        ctx->r18 = ADD32(ctx->r18, ctx->r16);
            goto L_80060DBC;
    }
    // 0x80060E0C: addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
L_80060E10:
    // 0x80060E10: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80060E14: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80060E18: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80060E1C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80060E20: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80060E24: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80060E28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80060E2C: jr          $ra
    // 0x80060E30: nop

    return;
    // 0x80060E30: nop

    // 0x80060E34: nop

    // 0x80060E38: nop

    // 0x80060E3C: nop

;}
RECOMP_FUNC void func_80060E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060E40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80060E44: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80060E48: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80060E4C: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x80060E50: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80060E54: addiu       $a1, $a1, 0x2010
    ctx->r5 = ADD32(ctx->r5, 0X2010);
    // 0x80060E58: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80060E5C: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80060E60: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x80060E64: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80060E68: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x80060E6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80060E70: sltiu       $v0, $a3, 0x1
    ctx->r2 = ctx->r7 < 0X1 ? 1 : 0;
    // 0x80060E74: sltiu       $v1, $t0, 0x1
    ctx->r3 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80060E78: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80060E7C: bne         $v0, $zero, L_80060EFC
    if (ctx->r2 != 0) {
        // 0x80060E80: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_80060EFC;
    }
    // 0x80060E80: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80060E84: beq         $a2, $zero, L_80060EFC
    if (ctx->r6 == 0) {
        // 0x80060E88: nop
    
            goto L_80060EFC;
    }
    // 0x80060E88: nop

    // 0x80060E8C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80060E90: lhu         $v0, 0x90($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X90);
    // 0x80060E94: xori        $v1, $v0, 0x150
    ctx->r3 = ctx->r2 ^ 0X150;
    // 0x80060E98: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80060E9C: xori        $v0, $v0, 0x240
    ctx->r2 = ctx->r2 ^ 0X240;
    // 0x80060EA0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80060EA4: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80060EA8: bne         $v1, $zero, L_80060EFC
    if (ctx->r3 != 0) {
        // 0x80060EAC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80060EFC;
    }
    // 0x80060EAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060EB0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80060EB4: lhu         $v1, 0x11E($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X11E);
    // 0x80060EB8: beq         $v1, $v0, L_80060EFC
    if (ctx->r3 == ctx->r2) {
        // 0x80060EBC: nop
    
            goto L_80060EFC;
    }
    // 0x80060EBC: nop

    // 0x80060EC0: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x80060EC4: beq         $v0, $zero, L_80060EFC
    if (ctx->r2 == 0) {
        // 0x80060EC8: sll         $v0, $v0, 2
        ctx->r2 = S32(ctx->r2 << 2);
            goto L_80060EFC;
    }
    // 0x80060EC8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80060ECC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80060ED0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80060ED4: lw          $v0, -0x1034($at)
    ctx->r2 = MEM_W(ctx->r1, -0X1034);
    // 0x80060ED8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80060EDC: bltz        $v0, L_80060EFC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80060EE0: sll         $v0, $v0, 2
        ctx->r2 = S32(ctx->r2 << 2);
            goto L_80060EFC;
    }
    // 0x80060EE0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80060EE4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80060EE8: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    // 0x80060EEC: andi        $a1, $t0, 0xFF
    ctx->r5 = ctx->r8 & 0XFF;
    // 0x80060EF0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80060EF4: jal         0x80061230
    // 0x80060EF8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80061230(rdram, ctx);
        goto after_0;
    // 0x80060EF8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
L_80060EFC:
    // 0x80060EFC: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80060F00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80060F04: jr          $ra
    // 0x80060F08: nop

    return;
    // 0x80060F08: nop

;}
RECOMP_FUNC void func_80060F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060F0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060F10: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80060F14: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80060F18: jal         0x80060E40
    // 0x80060F1C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80060E40(rdram, ctx);
        goto after_0;
    // 0x80060F1C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_0:
    // 0x80060F20: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80060F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060F28: jr          $ra
    // 0x80060F2C: nop

    return;
    // 0x80060F2C: nop

;}
RECOMP_FUNC void func_80060F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060F34: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80060F38: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80060F3C: lhu         $v1, 0x142($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X142);
    // 0x80060F40: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x80060F44: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x80060F48: lh          $a3, 0xB20($a3)
    ctx->r7 = MEM_H(ctx->r7, 0XB20);
    // 0x80060F4C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80060F50: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80060F54: lh          $a2, 0xB22($a2)
    ctx->r6 = MEM_H(ctx->r6, 0XB22);
    // 0x80060F58: beq         $v1, $zero, L_80060F94
    if (ctx->r3 == 0) {
        // 0x80060F5C: sltiu       $v1, $a1, 0x2
        ctx->r3 = ctx->r5 < 0X2 ? 1 : 0;
            goto L_80060F94;
    }
    // 0x80060F5C: sltiu       $v1, $a1, 0x2
    ctx->r3 = ctx->r5 < 0X2 ? 1 : 0;
    // 0x80060F60: xori        $v0, $a1, 0x2
    ctx->r2 = ctx->r5 ^ 0X2;
    // 0x80060F64: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80060F68: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80060F6C: bnel        $v1, $zero, L_80060F84
    if (ctx->r3 != 0) {
        // 0x80060F70: sll         $a3, $a3, 1
        ctx->r7 = S32(ctx->r7 << 1);
            goto L_80060F84;
    }
    goto skip_0;
    // 0x80060F70: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    skip_0:
    // 0x80060F74: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80060F78: bne         $a1, $v0, L_80060F94
    if (ctx->r5 != ctx->r2) {
        // 0x80060F7C: nop
    
            goto L_80060F94;
    }
    // 0x80060F7C: nop

    // 0x80060F80: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
L_80060F84:
    // 0x80060F84: slti        $v0, $a3, 0x41
    ctx->r2 = SIGNED(ctx->r7) < 0X41 ? 1 : 0;
    // 0x80060F88: beql        $v0, $zero, L_80060F90
    if (ctx->r2 == 0) {
        // 0x80060F8C: addiu       $a3, $zero, 0x40
        ctx->r7 = ADD32(0, 0X40);
            goto L_80060F90;
    }
    goto skip_1;
    // 0x80060F8C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    skip_1:
L_80060F90:
    // 0x80060F90: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
L_80060F94:
    // 0x80060F94: jal         0x80060E40
    // 0x80060F98: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    func_80060E40(rdram, ctx);
        goto after_0;
    // 0x80060F98: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    after_0:
    // 0x80060F9C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80060FA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060FA4: jr          $ra
    // 0x80060FA8: nop

    return;
    // 0x80060FA8: nop

;}
RECOMP_FUNC void func_80060FAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060FAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80060FB0: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80060FB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060FB8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80060FBC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80060FC0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80060FC4: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x80060FC8: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x80060FCC: lh          $s1, 0xB20($s1)
    ctx->r17 = MEM_H(ctx->r17, 0XB20);
    // 0x80060FD0: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80060FD4: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80060FD8: lh          $s2, 0xB22($s2)
    ctx->r18 = MEM_H(ctx->r18, 0XB22);
    // 0x80060FDC: jal         0x8001F310
    // 0x80060FE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001F310(rdram, ctx);
        goto after_0;
    // 0x80060FE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80060FE4: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x80060FE8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80060FEC: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80060FF0: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80060FF4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80060FF8: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80060FFC: addiu       $s0, $s0, 0x3F94
    ctx->r16 = ADD32(ctx->r16, 0X3F94);
    // 0x80061000: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x80061004: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80061008: jal         0x80060E40
    // 0x8006100C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80060E40(rdram, ctx);
        goto after_1;
    // 0x8006100C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_1:
    // 0x80061010: jal         0x8001F310
    // 0x80061014: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8001F310(rdram, ctx);
        goto after_2;
    // 0x80061014: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80061018: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x8006101C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80061020: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80061024: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80061028: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8006102C: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x80061030: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80061034: jal         0x80060E40
    // 0x80061038: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80060E40(rdram, ctx);
        goto after_3;
    // 0x80061038: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_3:
    // 0x8006103C: jal         0x8001F310
    // 0x80061040: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001F310(rdram, ctx);
        goto after_4;
    // 0x80061040: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x80061044: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x80061048: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006104C: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80061050: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80061054: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80061058: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x8006105C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80061060: jal         0x80060E40
    // 0x80061064: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80060E40(rdram, ctx);
        goto after_5;
    // 0x80061064: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_5:
    // 0x80061068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006106C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80061070: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80061074: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80061078: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006107C: jr          $ra
    // 0x80061080: nop

    return;
    // 0x80061080: nop

;}
RECOMP_FUNC void func_80061084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80061088: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8006108C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80061090: beq         $v0, $zero, L_800610E0
    if (ctx->r2 == 0) {
        // 0x80061094: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800610E0;
    }
    // 0x80061094: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80061098: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006109C: sll         $a3, $v0, 2
    ctx->r7 = S32(ctx->r2 << 2);
    // 0x800610A0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800610A4: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
L_800610A8:
    // 0x800610A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800610AC: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x800610B0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800610B4: bne         $v0, $a1, L_800610D4
    if (ctx->r2 != ctx->r5) {
        // 0x800610B8: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800610D4;
    }
    // 0x800610B8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800610BC: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x800610C0: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x800610C4: jal         0x80060E40
    // 0x800610C8: nop

    func_80060E40(rdram, ctx);
        goto after_0;
    // 0x800610C8: nop

    after_0:
    // 0x800610CC: j           L_800610E0
    // 0x800610D0: nop

        goto L_800610E0;
    // 0x800610D0: nop

L_800610D4:
    // 0x800610D4: sltiu       $v0, $a2, 0x13
    ctx->r2 = ctx->r6 < 0X13 ? 1 : 0;
    // 0x800610D8: bne         $v0, $zero, L_800610A8
    if (ctx->r2 != 0) {
        // 0x800610DC: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800610A8;
    }
    // 0x800610DC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_800610E0:
    // 0x800610E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800610E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800610E8: jr          $ra
    // 0x800610EC: nop

    return;
    // 0x800610EC: nop

;}
RECOMP_FUNC void func_800610F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800610F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800610F4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800610F8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800610FC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80061100:
    // 0x80061100: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80061104: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80061108: sw          $a2, -0x7408($at)
    MEM_W(-0X7408, ctx->r1) = ctx->r6;
    // 0x8006110C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80061110: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80061114: sw          $a3, -0x7404($at)
    MEM_W(-0X7404, ctx->r1) = ctx->r7;
    // 0x80061118: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8006111C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80061120: sw          $zero, -0x7400($at)
    MEM_W(-0X7400, ctx->r1) = 0;
    // 0x80061124: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80061128: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8006112C: sw          $zero, -0x73FC($at)
    MEM_W(-0X73FC, ctx->r1) = 0;
    // 0x80061130: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80061134: slti        $v0, $a0, 0x3
    ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80061138: bne         $v0, $zero, L_80061100
    if (ctx->r2 != 0) {
        // 0x8006113C: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_80061100;
    }
    // 0x8006113C: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x80061140: jr          $ra
    // 0x80061144: nop

    return;
    // 0x80061144: nop

;}
RECOMP_FUNC void func_80061148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061148: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006114C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80061150: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80061154: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80061158: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8006115C: addiu       $s4, $zero, 0x0
    ctx->r20 = ADD32(0, 0X0);
    // 0x80061160: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80061164: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80061168: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x8006116C: addiu       $s2, $s2, -0x7408
    ctx->r18 = ADD32(ctx->r18, -0X7408);
    // 0x80061170: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80061174: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80061178: addiu       $s0, $s0, -0x6DB8
    ctx->r16 = ADD32(ctx->r16, -0X6DB8);
    // 0x8006117C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80061180: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80061184: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
L_80061188:
    // 0x80061188: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8006118C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80061190: sw          $zero, -0x7400($at)
    MEM_W(-0X7400, ctx->r1) = 0;
    // 0x80061194: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80061198: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8006119C: sw          $zero, -0x73FC($at)
    MEM_W(-0X73FC, ctx->r1) = 0;
    // 0x800611A0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800611A4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800611A8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800611AC: sw          $a2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r6;
    // 0x800611B0: sw          $a3, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r7;
    // 0x800611B4: jal         0x8005C3C0
    // 0x800611B8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8005C3C0(rdram, ctx);
        goto after_0;
    // 0x800611B8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800611BC: bnel        $v0, $zero, L_800611F4
    if (ctx->r2 != 0) {
        // 0x800611C0: addiu       $s2, $s2, 0x30
        ctx->r18 = ADD32(ctx->r18, 0X30);
            goto L_800611F4;
    }
    goto skip_0;
    // 0x800611C0: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
    skip_0:
    // 0x800611C4: sw          $s4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r20;
    // 0x800611C8: sw          $s5, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r21;
    // 0x800611CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800611D0: jal         0x800735B0
    // 0x800611D4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800735B0(rdram, ctx);
        goto after_1;
    // 0x800611D4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x800611D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800611DC: jal         0x800735B0
    // 0x800611E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800735B0(rdram, ctx);
        goto after_2;
    // 0x800611E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x800611E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800611E8: jal         0x800735B0
    // 0x800611EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800735B0(rdram, ctx);
        goto after_3;
    // 0x800611EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_3:
    // 0x800611F0: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
L_800611F4:
    // 0x800611F4: addiu       $s0, $s0, 0x68
    ctx->r16 = ADD32(ctx->r16, 0X68);
    // 0x800611F8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800611FC: slti        $v0, $s3, 0x3
    ctx->r2 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
    // 0x80061200: bne         $v0, $zero, L_80061188
    if (ctx->r2 != 0) {
        // 0x80061204: addiu       $s1, $s1, 0x30
        ctx->r17 = ADD32(ctx->r17, 0X30);
            goto L_80061188;
    }
    // 0x80061204: addiu       $s1, $s1, 0x30
    ctx->r17 = ADD32(ctx->r17, 0X30);
    // 0x80061208: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8006120C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80061210: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80061214: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80061218: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8006121C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80061220: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80061224: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80061228: jr          $ra
    // 0x8006122C: nop

    return;
    // 0x8006122C: nop

;}
RECOMP_FUNC void func_80061230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061230: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80061234: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80061238: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8006123C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80061240: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80061244: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80061248: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8006124C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80061250: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80061254: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80061258: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006125C: jal         0x80061500
    // 0x80061260: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80061500(rdram, ctx);
        goto after_0;
    // 0x80061260: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80061264: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80061268: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006126C: jr          $ra
    // 0x80061270: nop

    return;
    // 0x80061270: nop

;}
RECOMP_FUNC void func_80061274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061274: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80061278: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8006127C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80061280: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80061284: jal         0x8006170C
    // 0x80061288: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8006170C(rdram, ctx);
        goto after_0;
    // 0x80061288: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x8006128C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80061290: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80061294: jr          $ra
    // 0x80061298: nop

    return;
    // 0x80061298: nop

;}
RECOMP_FUNC void func_8006129C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006129C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800612A0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800612A4: sll         $s0, $a0, 1
    ctx->r16 = S32(ctx->r4 << 1);
    // 0x800612A8: addu        $s0, $s0, $a0
    ctx->r16 = ADD32(ctx->r16, ctx->r4);
    // 0x800612AC: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x800612B0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800612B4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800612B8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800612BC: addiu       $a0, $a0, -0x6DB8
    ctx->r4 = ADD32(ctx->r4, -0X6DB8);
    // 0x800612C0: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x800612C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800612C8: jal         0x800735B0
    // 0x800612CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800735B0(rdram, ctx);
        goto after_0;
    // 0x800612CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800612D0: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x800612D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800612D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800612DC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800612E0: sw          $v0, -0x73FC($at)
    MEM_W(-0X73FC, ctx->r1) = ctx->r2;
    // 0x800612E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800612E8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800612EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800612F0: jr          $ra
    // 0x800612F4: nop

    return;
    // 0x800612F4: nop

;}
RECOMP_FUNC void func_800612F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800612F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800612FC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80061300: sll         $s1, $a0, 1
    ctx->r17 = S32(ctx->r4 << 1);
    // 0x80061304: addu        $s1, $s1, $a0
    ctx->r17 = ADD32(ctx->r17, ctx->r4);
    // 0x80061308: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006130C: sll         $s0, $s1, 2
    ctx->r16 = S32(ctx->r17 << 2);
    // 0x80061310: addu        $s0, $s0, $a0
    ctx->r16 = ADD32(ctx->r16, ctx->r4);
    // 0x80061314: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x80061318: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8006131C: addiu       $v0, $v0, -0x6DB8
    ctx->r2 = ADD32(ctx->r2, -0X6DB8);
    // 0x80061320: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80061324: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80061328: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8006132C: jal         0x800735B0
    // 0x80061330: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800735B0(rdram, ctx);
        goto after_0;
    // 0x80061330: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80061334: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80061338: jal         0x800735B0
    // 0x8006133C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800735B0(rdram, ctx);
        goto after_1;
    // 0x8006133C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x80061340: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80061344: jal         0x800735B0
    // 0x80061348: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800735B0(rdram, ctx);
        goto after_2;
    // 0x80061348: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x8006134C: sll         $s1, $s1, 4
    ctx->r17 = S32(ctx->r17 << 4);
    // 0x80061350: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80061354: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80061358: sw          $zero, -0x73FC($at)
    MEM_W(-0X73FC, ctx->r1) = 0;
    // 0x8006135C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80061360: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80061364: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80061368: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006136C: jr          $ra
    // 0x80061370: nop

    return;
    // 0x80061370: nop

;}
RECOMP_FUNC void func_80061374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80061378: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8006137C: sll         $a1, $a0, 1
    ctx->r5 = S32(ctx->r4 << 1);
    // 0x80061380: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x80061384: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80061388: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x8006138C: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x80061390: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80061394: addiu       $v0, $v0, -0x6DB8
    ctx->r2 = ADD32(ctx->r2, -0X6DB8);
    // 0x80061398: jal         0x8005C3C0
    // 0x8006139C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    func_8005C3C0(rdram, ctx);
        goto after_0;
    // 0x8006139C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    after_0:
    // 0x800613A0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800613A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800613A8: jr          $ra
    // 0x800613AC: nop

    return;
    // 0x800613AC: nop

;}
RECOMP_FUNC void func_800613B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800613B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800613B4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800613B8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800613BC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800613C0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800613C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800613C8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_800613CC:
    // 0x800613CC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800613D0: addiu       $v0, $v0, -0x7408
    ctx->r2 = ADD32(ctx->r2, -0X7408);
    // 0x800613D4: addu        $s0, $s2, $v0
    ctx->r16 = ADD32(ctx->r18, ctx->r2);
    // 0x800613D8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800613DC: beql        $v0, $zero, L_800614D8
    if (ctx->r2 == 0) {
        // 0x800613E0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800614D8;
    }
    goto skip_0;
    // 0x800613E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800613E4: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800613E8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800613EC: beq         $v0, $zero, L_800614B8
    if (ctx->r2 == 0) {
        // 0x800613F0: sw          $v0, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r2;
            goto L_800614B8;
    }
    // 0x800613F0: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x800613F4: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800613F8: bne         $v0, $zero, L_8006140C
    if (ctx->r2 != 0) {
        // 0x800613FC: nop
    
            goto L_8006140C;
    }
    // 0x800613FC: nop

    // 0x80061400: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80061404: beq         $v0, $zero, L_800614B8
    if (ctx->r2 == 0) {
        // 0x80061408: nop
    
            goto L_800614B8;
    }
    // 0x80061408: nop

L_8006140C:
    // 0x8006140C: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80061410: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x80061414: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80061418: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x8006141C: sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // 0x80061420: bne         $v0, $zero, L_8006144C
    if (ctx->r2 != 0) {
        // 0x80061424: nop
    
            goto L_8006144C;
    }
    // 0x80061424: nop

    // 0x80061428: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8006142C: bne         $v0, $zero, L_8006143C
    if (ctx->r2 != 0) {
        // 0x80061430: nop
    
            goto L_8006143C;
    }
    // 0x80061430: nop

    // 0x80061434: jal         0x8006129C
    // 0x80061438: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8006129C(rdram, ctx);
        goto after_0;
    // 0x80061438: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
L_8006143C:
    // 0x8006143C: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80061440: addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    // 0x80061444: j           L_80061460
    // 0x80061448: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
        goto L_80061460;
    // 0x80061448: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
L_8006144C:
    // 0x8006144C: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80061450: beq         $v0, $zero, L_80061460
    if (ctx->r2 == 0) {
        // 0x80061454: nop
    
            goto L_80061460;
    }
    // 0x80061454: nop

    // 0x80061458: jal         0x800612F8
    // 0x8006145C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800612F8(rdram, ctx);
        goto after_1;
    // 0x8006145C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
L_80061460:
    // 0x80061460: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80061464: beq         $v0, $zero, L_80061498
    if (ctx->r2 == 0) {
        // 0x80061468: nop
    
            goto L_80061498;
    }
    // 0x80061468: nop

    // 0x8006146C: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80061470: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x80061474: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80061478: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006147C: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80061480: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80061484: bnel        $v0, $zero, L_800614D8
    if (ctx->r2 != 0) {
        // 0x80061488: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800614D8;
    }
    goto skip_1;
    // 0x80061488: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x8006148C: sw          $a0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r4;
    // 0x80061490: j           L_800614D4
    // 0x80061494: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
        goto L_800614D4;
    // 0x80061494: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
L_80061498:
    // 0x80061498: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x8006149C: beql        $v0, $zero, L_800614D8
    if (ctx->r2 == 0) {
        // 0x800614A0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800614D8;
    }
    goto skip_2;
    // 0x800614A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x800614A4: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x800614A8: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x800614AC: sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x800614B0: bne         $v0, $zero, L_800614D0
    if (ctx->r2 != 0) {
        // 0x800614B4: subu        $v0, $v1, $a0
        ctx->r2 = SUB32(ctx->r3, ctx->r4);
            goto L_800614D0;
    }
    // 0x800614B4: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
L_800614B8:
    // 0x800614B8: jal         0x80061374
    // 0x800614BC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80061374(rdram, ctx);
        goto after_2;
    // 0x800614BC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x800614C0: jal         0x800612F8
    // 0x800614C4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800612F8(rdram, ctx);
        goto after_3;
    // 0x800614C4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x800614C8: j           L_800614D4
    // 0x800614CC: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
        goto L_800614D4;
    // 0x800614CC: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
L_800614D0:
    // 0x800614D0: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
L_800614D4:
    // 0x800614D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800614D8:
    // 0x800614D8: slti        $v0, $s1, 0x3
    ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x800614DC: bne         $v0, $zero, L_800613CC
    if (ctx->r2 != 0) {
        // 0x800614E0: addiu       $s2, $s2, 0x30
        ctx->r18 = ADD32(ctx->r18, 0X30);
            goto L_800613CC;
    }
    // 0x800614E0: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
    // 0x800614E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800614E8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800614EC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800614F0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800614F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800614F8: jr          $ra
    // 0x800614FC: nop

    return;
    // 0x800614FC: nop

;}
RECOMP_FUNC void func_80061500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061500: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80061504: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80061508: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8006150C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80061510: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80061514: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80061518: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8006151C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80061520: lui         $s3, 0x8016
    ctx->r19 = S32(0X8016 << 16);
    // 0x80061524: addiu       $s3, $s3, -0x73F0
    ctx->r19 = ADD32(ctx->r19, -0X73F0);
    // 0x80061528: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006152C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80061530: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_80061534:
    // 0x80061534: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80061538: sllv        $v1, $s4, $s2
    ctx->r3 = S32(ctx->r20 << (ctx->r18 & 31));
    // 0x8006153C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80061540: beql        $v0, $zero, L_800616D8
    if (ctx->r2 == 0) {
        // 0x80061544: addiu       $s3, $s3, 0x30
        ctx->r19 = ADD32(ctx->r19, 0X30);
            goto L_800616D8;
    }
    goto skip_0;
    // 0x80061544: addiu       $s3, $s3, 0x30
    ctx->r19 = ADD32(ctx->r19, 0X30);
    skip_0:
    // 0x80061548: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8006154C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80061550: lw          $v0, -0x7408($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7408);
    // 0x80061554: bne         $v0, $zero, L_80061570
    if (ctx->r2 != 0) {
        // 0x80061558: nop
    
            goto L_80061570;
    }
    // 0x80061558: nop

    // 0x8006155C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80061560: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80061564: lw          $v0, -0x7404($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7404);
    // 0x80061568: beql        $v0, $zero, L_800616D8
    if (ctx->r2 == 0) {
        // 0x8006156C: addiu       $s3, $s3, 0x30
        ctx->r19 = ADD32(ctx->r19, 0X30);
            goto L_800616D8;
    }
    goto skip_1;
    // 0x8006156C: addiu       $s3, $s3, 0x30
    ctx->r19 = ADD32(ctx->r19, 0X30);
    skip_1:
L_80061570:
    // 0x80061570: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80061574: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80061578: lw          $v0, -0x7400($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7400);
    // 0x8006157C: beq         $v0, $zero, L_800615C4
    if (ctx->r2 == 0) {
        // 0x80061580: nop
    
            goto L_800615C4;
    }
    // 0x80061580: nop

    // 0x80061584: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x80061588: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8006158C: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x80061590: lw          $v1, -0x73E4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X73E4);
    // 0x80061594: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80061598: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8006159C: beq         $v0, $zero, L_800615C4
    if (ctx->r2 == 0) {
        // 0x800615A0: nop
    
            goto L_800615C4;
    }
    // 0x800615A0: nop

    // 0x800615A4: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800615A8: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800615AC: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x800615B0: lw          $v1, -0x73EC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X73EC);
    // 0x800615B4: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x800615B8: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800615BC: bnel        $v0, $zero, L_800616D8
    if (ctx->r2 != 0) {
        // 0x800615C0: addiu       $s3, $s3, 0x30
        ctx->r19 = ADD32(ctx->r19, 0X30);
            goto L_800616D8;
    }
    goto skip_2;
    // 0x800615C0: addiu       $s3, $s3, 0x30
    ctx->r19 = ADD32(ctx->r19, 0X30);
    skip_2:
L_800615C4:
    // 0x800615C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800615C8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800615CC: sw          $s4, -0x7400($at)
    MEM_W(-0X7400, ctx->r1) = ctx->r20;
    // 0x800615D0: jal         0x80061374
    // 0x800615D4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80061374(rdram, ctx);
        goto after_0;
    // 0x800615D4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // 0x800615D8: jal         0x800612F8
    // 0x800615DC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_800612F8(rdram, ctx);
        goto after_1;
    // 0x800615DC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x800615E0: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800615E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800615E8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800615EC: sw          $v0, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->r2;
    // 0x800615F0: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800615F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800615F8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800615FC: sw          $v0, -0x73E4($at)
    MEM_W(-0X73E4, ctx->r1) = ctx->r2;
    // 0x80061600: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80061604: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80061608: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8006160C: sw          $v0, -0x73F8($at)
    MEM_W(-0X73F8, ctx->r1) = ctx->r2;
    // 0x80061610: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80061614: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80061618: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8006161C: sw          $zero, -0x73E0($at)
    MEM_W(-0X73E0, ctx->r1) = 0;
    // 0x80061620: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80061624: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80061628: sw          $v0, -0x73F4($at)
    MEM_W(-0X73F4, ctx->r1) = ctx->r2;
    // 0x8006162C: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x80061630: bne         $v1, $zero, L_80061644
    if (ctx->r3 != 0) {
        // 0x80061634: nop
    
            goto L_80061644;
    }
    // 0x80061634: nop

    // 0x80061638: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8006163C: beq         $v0, $zero, L_800616B8
    if (ctx->r2 == 0) {
        // 0x80061640: nop
    
            goto L_800616B8;
    }
    // 0x80061640: nop

L_80061644:
    // 0x80061644: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80061648: beq         $v0, $zero, L_80061668
    if (ctx->r2 == 0) {
        // 0x8006164C: nop
    
            goto L_80061668;
    }
    // 0x8006164C: nop

    // 0x80061650: beq         $v1, $zero, L_80061668
    if (ctx->r3 == 0) {
        // 0x80061654: nop
    
            goto L_80061668;
    }
    // 0x80061654: nop

    // 0x80061658: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x8006165C: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x80061660: j           L_80061670
    // 0x80061664: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
        goto L_80061670;
    // 0x80061664: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
L_80061668:
    // 0x80061668: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x8006166C: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
L_80061670:
    // 0x80061670: divu        $zero, $v1, $v0
    lo = S32(U32(ctx->r3) / U32(ctx->r2)); hi = S32(U32(ctx->r3) % U32(ctx->r2));
    // 0x80061674: bne         $v0, $zero, L_80061680
    if (ctx->r2 != 0) {
        // 0x80061678: nop
    
            goto L_80061680;
    }
    // 0x80061678: nop

    // 0x8006167C: break       7
    do_break(2147882620);
L_80061680:
    // 0x80061680: mflo        $v1
    ctx->r3 = lo;
    // 0x80061684: nop

    // 0x80061688: nop

    // 0x8006168C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80061690: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80061694: sw          $v1, -0x73E8($at)
    MEM_W(-0X73E8, ctx->r1) = ctx->r3;
    // 0x80061698: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8006169C: beq         $v0, $zero, L_800616AC
    if (ctx->r2 == 0) {
        // 0x800616A0: nop
    
            goto L_800616AC;
    }
    // 0x800616A0: nop

    // 0x800616A4: j           L_800616D4
    // 0x800616A8: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
        goto L_800616D4;
    // 0x800616A8: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_800616AC:
    // 0x800616AC: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800616B0: j           L_800616D4
    // 0x800616B4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
        goto L_800616D4;
    // 0x800616B4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
L_800616B8:
    // 0x800616B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800616BC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800616C0: sw          $zero, -0x73E8($at)
    MEM_W(-0X73E8, ctx->r1) = 0;
    // 0x800616C4: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800616C8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800616CC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800616D0: sw          $v0, -0x73F0($at)
    MEM_W(-0X73F0, ctx->r1) = ctx->r2;
L_800616D4:
    // 0x800616D4: addiu       $s3, $s3, 0x30
    ctx->r19 = ADD32(ctx->r19, 0X30);
L_800616D8:
    // 0x800616D8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800616DC: slti        $v0, $s2, 0x3
    ctx->r2 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x800616E0: bne         $v0, $zero, L_80061534
    if (ctx->r2 != 0) {
        // 0x800616E4: addiu       $s0, $s0, 0x30
        ctx->r16 = ADD32(ctx->r16, 0X30);
            goto L_80061534;
    }
    // 0x800616E4: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x800616E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800616EC: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800616F0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800616F4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800616F8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800616FC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80061700: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80061704: jr          $ra
    // 0x80061708: nop

    return;
    // 0x80061708: nop

;}
RECOMP_FUNC void func_8006170C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006170C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80061710: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80061714: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80061718: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006171C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80061720: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80061724: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80061728: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8006172C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80061730: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80061734: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80061738: addiu       $s0, $s0, -0x6DB8
    ctx->r16 = ADD32(ctx->r16, -0X6DB8);
    // 0x8006173C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_80061740:
    // 0x80061740: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80061744: sllv        $v1, $s4, $s1
    ctx->r3 = S32(ctx->r20 << (ctx->r17 & 31));
    // 0x80061748: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006174C: beq         $v0, $zero, L_80061798
    if (ctx->r2 == 0) {
        // 0x80061750: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80061798;
    }
    // 0x80061750: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80061754: jal         0x8005C3C0
    // 0x80061758: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8005C3C0(rdram, ctx);
        goto after_0;
    // 0x80061758: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8006175C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80061760: jal         0x8005C3C0
    // 0x80061764: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8005C3C0(rdram, ctx);
        goto after_1;
    // 0x80061764: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80061768: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006176C: jal         0x800735B0
    // 0x80061770: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800735B0(rdram, ctx);
        goto after_2;
    // 0x80061770: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x80061774: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80061778: jal         0x800735B0
    // 0x8006177C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800735B0(rdram, ctx);
        goto after_3;
    // 0x8006177C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_3:
    // 0x80061780: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80061784: jal         0x800735B0
    // 0x80061788: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800735B0(rdram, ctx);
        goto after_4;
    // 0x80061788: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
    // 0x8006178C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80061790: jal         0x800735B0
    // 0x80061794: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800735B0(rdram, ctx);
        goto after_5;
    // 0x80061794: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
L_80061798:
    // 0x80061798: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8006179C: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x800617A0: sw          $zero, -0x7400($at)
    MEM_W(-0X7400, ctx->r1) = 0;
    // 0x800617A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800617A8: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x800617AC: sw          $zero, -0x73FC($at)
    MEM_W(-0X73FC, ctx->r1) = 0;
    // 0x800617B0: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
    // 0x800617B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800617B8: slti        $v0, $s1, 0x3
    ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x800617BC: bne         $v0, $zero, L_80061740
    if (ctx->r2 != 0) {
        // 0x800617C0: addiu       $s0, $s0, 0x68
        ctx->r16 = ADD32(ctx->r16, 0X68);
            goto L_80061740;
    }
    // 0x800617C0: addiu       $s0, $s0, 0x68
    ctx->r16 = ADD32(ctx->r16, 0X68);
    // 0x800617C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800617C8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800617CC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800617D0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800617D4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800617D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800617DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800617E0: jr          $ra
    // 0x800617E4: nop

    return;
    // 0x800617E4: nop

    // 0x800617E8: nop

    // 0x800617EC: nop

;}
RECOMP_FUNC void func_800617F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800617F0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800617F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800617F8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800617FC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80061800: beq         $a2, $zero, L_8006181C
    if (ctx->r6 == 0) {
        // 0x80061804: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8006181C;
    }
    // 0x80061804: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80061808:
    // 0x80061808: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8006180C: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x80061810: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80061814: bne         $a2, $zero, L_80061808
    if (ctx->r6 != 0) {
        // 0x80061818: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_80061808;
    }
    // 0x80061818: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8006181C:
    // 0x8006181C: jr          $ra
    // 0x80061820: nop

    return;
    // 0x80061820: nop

;}
RECOMP_FUNC void func_80061824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061824: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80061828: lw          $t6, 0xBF4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XBF4);
    // FALLTHROUGH: func_80061824 falls into func_8006182C
    func_8006182C(rdram, ctx);
;}
RECOMP_FUNC void func_8006182C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006182C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80061830: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80061834: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80061838: bne         $t6, $zero, L_80061848
    if (ctx->r14 != 0) {
        // 0x8006183C: sw          $a1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r5;
            goto L_80061848;
    }
    // 0x8006183C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80061840: b           L_800618B0
    // 0x80061844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800618B0;
    // 0x80061844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061848:
    // 0x80061848: bne         $a2, $zero, L_80061858
    if (ctx->r6 != 0) {
        // 0x8006184C: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80061858;
    }
    // 0x8006184C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80061850: b           L_800618B0
    // 0x80061854: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800618B0;
    // 0x80061854: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061858:
    // 0x80061858: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8006185C: jal         0x800702D0
    // 0x80061860: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    func_800702D0(rdram, ctx);
        goto after_0;
    // 0x80061860: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_0:
    // 0x80061864: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80061868: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8006186C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80061870: addiu       $t9, $t9, -0x17B8
    ctx->r25 = ADD32(ctx->r25, -0X17B8);
    // 0x80061874: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80061878: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8006187C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80061880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80061884: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80061888: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006188C: jal         0x80072B20
    // 0x80061890: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_80072B20(rdram, ctx);
        goto after_1;
    // 0x80061890: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_1:
    // 0x80061894: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80061898: addiu       $a0, $a0, -0x17B8
    ctx->r4 = ADD32(ctx->r4, -0X17B8);
    // 0x8006189C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800618A0: jal         0x80070620
    // 0x800618A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800618A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800618A8: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x800618AC: nop

L_800618B0:
    // 0x800618B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800618B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800618B8: jr          $ra
    // 0x800618BC: nop

    return;
    // 0x800618BC: nop

;}
RECOMP_FUNC void func_800618C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800618C0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800618C4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800618C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800618CC: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800618D0: div.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800618D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800618D8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800618DC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800618E0: nop

    // 0x800618E4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800618E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800618EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800618F0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800618F4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800618F8: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x800618FC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80061900: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x80061904: jr          $ra
    // 0x80061908: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80061908: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
;}
RECOMP_FUNC void func_8006190C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006190C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80061910: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80061914: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80061918: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006191C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80061920: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80061924: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80061928: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006192C: addiu       $a1, $a1, -0x17A0
    ctx->r5 = ADD32(ctx->r5, -0X17A0);
    // 0x80061930: addiu       $a0, $a0, -0x17B8
    ctx->r4 = ADD32(ctx->r4, -0X17B8);
    // 0x80061934: jal         0x80070490
    // 0x80061938: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80061938: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x8006193C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80061940: sw          $zero, 0xBEC($at)
    MEM_W(0XBEC, ctx->r1) = 0;
    // 0x80061944: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80061948: sw          $zero, 0xBF0($at)
    MEM_W(0XBF0, ctx->r1) = 0;
    // 0x8006194C: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    // 0x80061950: jal         0x8006AC88
    // 0x80061954: nop

    func_8006AC88(rdram, ctx);
        goto after_1;
    // 0x80061954: nop

    after_1:
    // 0x80061958: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8006195C: lw          $v0, 0xC8C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC8C);
    // 0x80061960: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80061964: lw          $t6, 0xC90($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XC90);
    // 0x80061968: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8006196C: addiu       $t7, $t7, 0x244C
    ctx->r15 = ADD32(ctx->r15, 0X244C);
    // 0x80061970: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x80061974: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80061978: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x8006197C: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x80061980: lw          $t8, 0x14($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X14);
    // 0x80061984: nop

    // 0x80061988: sb          $t8, 0x78($sp)
    MEM_B(0X78, ctx->r29) = ctx->r24;
    // 0x8006198C: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x80061990: jal         0x8006AC50
    // 0x80061994: nop

    func_8006AC50(rdram, ctx);
        goto after_2;
    // 0x80061994: nop

    after_2:
    // 0x80061998: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x8006199C: jal         0x800732B0
    // 0x800619A0: nop

    osCartRomInit_recomp(rdram, ctx);
        goto after_3;
    // 0x800619A0: nop

    after_3:
    // 0x800619A4: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x800619A8: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x800619AC: lbu         $t0, 0x78($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X78);
    // 0x800619B0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800619B4: bne         $t0, $at, L_80061AC0
    if (ctx->r8 != ctx->r1) {
        // 0x800619B8: sw          $t9, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r25;
            goto L_80061AC0;
    }
    // 0x800619B8: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x800619BC: lw          $t2, 0x4($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X4);
    // 0x800619C0: lw          $t1, 0x18($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X18);
    // 0x800619C4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800619C8: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x800619CC: bgez        $t2, L_800619E4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800619D0: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800619E4;
    }
    // 0x800619D0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800619D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800619D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800619DC: nop

    // 0x800619E0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800619E4:
    // 0x800619E4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800619E8: jal         0x800618C0
    // 0x800619EC: nop

    func_800618C0(rdram, ctx);
        goto after_4;
    // 0x800619EC: nop

    after_4:
    // 0x800619F0: lw          $t3, 0x18($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X18);
    // 0x800619F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800619F8: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x800619FC: lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X18);
    // 0x80061A00: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x80061A04: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80061A08: nop

    // 0x80061A0C: blez        $t4, L_80061ABC
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80061A10: nop
    
            goto L_80061ABC;
    }
    // 0x80061A10: nop

L_80061A14:
    // 0x80061A14: lw          $t6, 0x4($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X4);
    // 0x80061A18: addu        $t5, $v1, $s0
    ctx->r13 = ADD32(ctx->r3, ctx->r16);
    // 0x80061A1C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80061A20: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80061A24: bgez        $t6, L_80061A3C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80061A28: cvt.s.w     $f8, $f8
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80061A3C;
    }
    // 0x80061A28: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80061A2C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80061A30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80061A34: nop

    // 0x80061A38: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80061A3C:
    // 0x80061A3C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80061A40: jal         0x800618C0
    // 0x80061A44: nop

    func_800618C0(rdram, ctx);
        goto after_5;
    // 0x80061A44: nop

    after_5:
    // 0x80061A48: lw          $t7, 0x18($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X18);
    // 0x80061A4C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80061A50: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80061A54: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x80061A58: lw          $t1, 0x4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X4);
    // 0x80061A5C: lw          $t9, 0x18($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X18);
    // 0x80061A60: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80061A64: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80061A68: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x80061A6C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80061A70: bgez        $t1, L_80061A84
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80061A74: cvt.s.w     $f16, $f16
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80061A84;
    }
    // 0x80061A74: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80061A78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80061A7C: nop

    // 0x80061A80: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80061A84:
    // 0x80061A84: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80061A88: jal         0x800618C0
    // 0x80061A8C: nop

    func_800618C0(rdram, ctx);
        goto after_6;
    // 0x80061A8C: nop

    after_6:
    // 0x80061A90: lw          $t2, 0x18($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X18);
    // 0x80061A94: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80061A98: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80061A9C: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x80061AA0: lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X18);
    // 0x80061AA4: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x80061AA8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80061AAC: nop

    // 0x80061AB0: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80061AB4: bne         $at, $zero, L_80061A14
    if (ctx->r1 != 0) {
        // 0x80061AB8: nop
    
            goto L_80061A14;
    }
    // 0x80061AB8: nop

L_80061ABC:
    // 0x80061ABC: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
L_80061AC0:
    // 0x80061AC0: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80061AC4: jal         0x80061B00
    // 0x80061AC8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80061B00(rdram, ctx);
        goto after_7;
    // 0x80061AC8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80061ACC: jal         0x80062600
    // 0x80061AD0: nop

    func_80062600(rdram, ctx);
        goto after_8;
    // 0x80061AD0: nop

    after_8:
    // 0x80061AD4: jal         0x80062AA4
    // 0x80061AD8: nop

    func_80062AA4(rdram, ctx);
        goto after_9;
    // 0x80061AD8: nop

    after_9:
    // 0x80061ADC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80061AE0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80061AE4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80061AE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80061AEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80061AF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80061AF4: sw          $t5, 0xBF4($at)
    MEM_W(0XBF4, ctx->r1) = ctx->r13;
    // 0x80061AF8: jr          $ra
    // 0x80061AFC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80061AFC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80061B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061B00: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80061B04: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80061B08: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80061B0C: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80061B10: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80061B14: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80061B18: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80061B1C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80061B20: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80061B24: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80061B28: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80061B2C: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80061B30: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80061B34: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80061B38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80061B3C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80061B40: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80061B44: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80061B48: addiu       $v1, $v1, -0x17EC
    ctx->r3 = ADD32(ctx->r3, -0X17EC);
    // 0x80061B4C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80061B50: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80061B54: addiu       $s0, $s0, 0xC8C
    ctx->r16 = ADD32(ctx->r16, 0XC8C);
    // 0x80061B58: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80061B5C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80061B60: nop

    // 0x80061B64: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80061B68: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80061B6C: nop

    // 0x80061B70: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80061B74: beq         $t8, $zero, L_80061BC0
    if (ctx->r24 == 0) {
        // 0x80061B78: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80061BC0;
    }
    // 0x80061B78: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80061B7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80061B80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80061B84: sub.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80061B88: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80061B8C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80061B90: nop

    // 0x80061B94: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80061B98: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80061B9C: nop

    // 0x80061BA0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80061BA4: bne         $t8, $zero, L_80061BB8
    if (ctx->r24 != 0) {
        // 0x80061BA8: nop
    
            goto L_80061BB8;
    }
    // 0x80061BA8: nop

    // 0x80061BAC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80061BB0: b           L_80061BD0
    // 0x80061BB4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80061BD0;
    // 0x80061BB4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80061BB8:
    // 0x80061BB8: b           L_80061BD0
    // 0x80061BBC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80061BD0;
    // 0x80061BBC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80061BC0:
    // 0x80061BC0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80061BC4: nop

    // 0x80061BC8: bltz        $t8, L_80061BB8
    if (SIGNED(ctx->r24) < 0) {
        // 0x80061BCC: nop
    
            goto L_80061BB8;
    }
    // 0x80061BCC: nop

L_80061BD0:
    // 0x80061BD0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80061BD4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80061BD8: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80061BDC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80061BE0: bgez        $t8, L_80061BF8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80061BE4: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80061BF8;
    }
    // 0x80061BE4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80061BE8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80061BEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80061BF0: nop

    // 0x80061BF4: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80061BF8:
    // 0x80061BF8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80061BFC: nop

    // 0x80061C00: bc1f        L_80061C10
    if (!c1cs) {
        // 0x80061C04: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_80061C10;
    }
    // 0x80061C04: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80061C08: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80061C0C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80061C10:
    // 0x80061C10: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x80061C14: beq         $t0, $zero, L_80061C28
    if (ctx->r8 == 0) {
        // 0x80061C18: addiu       $at, $zero, -0x10
        ctx->r1 = ADD32(0, -0X10);
            goto L_80061C28;
    }
    // 0x80061C18: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80061C1C: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x80061C20: addiu       $v0, $t1, 0x10
    ctx->r2 = ADD32(ctx->r9, 0X10);
    // 0x80061C24: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80061C28:
    // 0x80061C28: addiu       $t3, $v0, -0x10
    ctx->r11 = ADD32(ctx->r2, -0X10);
    // 0x80061C2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80061C30: sw          $t3, -0x17F0($at)
    MEM_W(-0X17F0, ctx->r1) = ctx->r11;
    // 0x80061C34: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80061C38: addiu       $s1, $zero, 0x1C
    ctx->r17 = ADD32(0, 0X1C);
    // 0x80061C3C: multu       $t7, $s1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061C40: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80061C44: lw          $t4, 0xC84($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XC84);
    // 0x80061C48: lui         $s7, 0x800D
    ctx->r23 = S32(0X800D << 16);
    // 0x80061C4C: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80061C50: addiu       $s7, $s7, -0x17E8
    ctx->r23 = ADD32(ctx->r23, -0X17E8);
    // 0x80061C54: addiu       $t6, $t5, 0x10
    ctx->r14 = ADD32(ctx->r13, 0X10);
    // 0x80061C58: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x80061C5C: lw          $a2, 0x14($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X14);
    // 0x80061C60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80061C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061C68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80061C6C: mflo        $t8
    ctx->r24 = lo;
    // 0x80061C70: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80061C74: jal         0x80070FF0
    // 0x80061C78: nop

    func_80070FF0(rdram, ctx);
        goto after_0;
    // 0x80061C78: nop

    after_0:
    // 0x80061C7C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80061C80: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80061C84: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061C88: addiu       $v1, $v1, -0x17E0
    ctx->r3 = ADD32(ctx->r3, -0X17E0);
    // 0x80061C8C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80061C90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80061C94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061C98: mflo        $a2
    ctx->r6 = lo;
    // 0x80061C9C: jal         0x800617F0
    // 0x80061CA0: nop

    func_800617F0(rdram, ctx);
        goto after_1;
    // 0x80061CA0: nop

    after_1:
    // 0x80061CA4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80061CA8: lw          $a2, 0x14($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X14);
    // 0x80061CAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80061CB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061CB4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80061CB8: jal         0x80070FF0
    // 0x80061CBC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80070FF0(rdram, ctx);
        goto after_2;
    // 0x80061CBC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
    // 0x80061CC0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80061CC4: addiu       $v1, $v1, -0x17DC
    ctx->r3 = ADD32(ctx->r3, -0X17DC);
    // 0x80061CC8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80061CCC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80061CD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80061CD4: jal         0x800617F0
    // 0x80061CD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800617F0(rdram, ctx);
        goto after_3;
    // 0x80061CD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80061CDC: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x80061CE0: addiu       $s5, $s5, 0xC78
    ctx->r21 = ADD32(ctx->r21, 0XC78);
    // 0x80061CE4: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x80061CE8: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
    // 0x80061CEC: multu       $t1, $s0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061CF0: lw          $a2, 0x14($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X14);
    // 0x80061CF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80061CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061CFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80061D00: mflo        $t2
    ctx->r10 = lo;
    // 0x80061D04: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80061D08: jal         0x80070FF0
    // 0x80061D0C: nop

    func_80070FF0(rdram, ctx);
        goto after_4;
    // 0x80061D0C: nop

    after_4:
    // 0x80061D10: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x80061D14: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80061D18: multu       $t3, $s0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061D1C: addiu       $s1, $s1, -0x17F4
    ctx->r17 = ADD32(ctx->r17, -0X17F4);
    // 0x80061D20: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80061D24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80061D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061D2C: mflo        $a2
    ctx->r6 = lo;
    // 0x80061D30: jal         0x800617F0
    // 0x80061D34: nop

    func_800617F0(rdram, ctx);
        goto after_5;
    // 0x80061D34: nop

    after_5:
    // 0x80061D38: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80061D3C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80061D40: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80061D44: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80061D48: nop

    // 0x80061D4C: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x80061D50: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80061D54: nop

    // 0x80061D58: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80061D5C: beq         $t7, $zero, L_80061DDC
    if (ctx->r15 == 0) {
        // 0x80061D60: lui         $s3, 0x8009
        ctx->r19 = S32(0X8009 << 16);
            goto L_80061DDC;
    }
    // 0x80061D60: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80061D64: addiu       $s3, $s3, 0xC80
    ctx->r19 = ADD32(ctx->r19, 0XC80);
    // 0x80061D68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80061D6C:
    // 0x80061D6C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80061D70: nop

    // 0x80061D74: addu        $a1, $s0, $t8
    ctx->r5 = ADD32(ctx->r16, ctx->r24);
    // 0x80061D78: jal         0x80070F5C
    // 0x80061D7C: addiu       $a0, $a1, 0x14
    ctx->r4 = ADD32(ctx->r5, 0X14);
    func_80070F5C(rdram, ctx);
        goto after_6;
    // 0x80061D7C: addiu       $a0, $a1, 0x14
    ctx->r4 = ADD32(ctx->r5, 0X14);
    after_6:
    // 0x80061D80: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80061D84: lw          $a2, 0x14($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X14);
    // 0x80061D88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80061D8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061D90: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80061D94: jal         0x80070FF0
    // 0x80061D98: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80070FF0(rdram, ctx);
        goto after_7;
    // 0x80061D98: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_7:
    // 0x80061D9C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80061DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061DA4: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80061DA8: sw          $v0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r2;
    // 0x80061DAC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80061DB0: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x80061DB4: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80061DB8: lw          $a0, 0x10($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X10);
    // 0x80061DBC: jal         0x800617F0
    // 0x80061DC0: nop

    func_800617F0(rdram, ctx);
        goto after_8;
    // 0x80061DC0: nop

    after_8:
    // 0x80061DC4: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x80061DC8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80061DCC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80061DD0: sltu        $at, $s2, $t5
    ctx->r1 = ctx->r18 < ctx->r13 ? 1 : 0;
    // 0x80061DD4: bne         $at, $zero, L_80061D6C
    if (ctx->r1 != 0) {
        // 0x80061DD8: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_80061D6C;
    }
    // 0x80061DD8: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_80061DDC:
    // 0x80061DDC: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80061DE0: addiu       $s3, $s3, 0xC80
    ctx->r19 = ADD32(ctx->r19, 0XC80);
    // 0x80061DE4: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80061DE8: sll         $s0, $s2, 2
    ctx->r16 = S32(ctx->r18 << 2);
    // 0x80061DEC: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    // 0x80061DF0: lw          $a2, 0x14($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X14);
    // 0x80061DF4: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80061DF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80061DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061E00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80061E04: jal         0x80070FF0
    // 0x80061E08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80070FF0(rdram, ctx);
        goto after_9;
    // 0x80061E08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_9:
    // 0x80061E0C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80061E10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061E14: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80061E18: sw          $v0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r2;
    // 0x80061E1C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80061E20: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x80061E24: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x80061E28: lw          $a0, 0x10($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X10);
    // 0x80061E2C: jal         0x800617F0
    // 0x80061E30: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    func_800617F0(rdram, ctx);
        goto after_10;
    // 0x80061E30: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_10:
    // 0x80061E34: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80061E38: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80061E3C: addiu       $s1, $s1, -0x1858
    ctx->r17 = ADD32(ctx->r17, -0X1858);
    // 0x80061E40: addiu       $s0, $s0, -0x1860
    ctx->r16 = ADD32(ctx->r16, -0X1860);
L_80061E44:
    // 0x80061E44: lw          $t1, 0x8($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X8);
    // 0x80061E48: lw          $a2, 0x14($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X14);
    // 0x80061E4C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80061E50: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80061E54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80061E58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061E5C: jal         0x80070FF0
    // 0x80061E60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80070FF0(rdram, ctx);
        goto after_11;
    // 0x80061E60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // 0x80061E64: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80061E68: lw          $a2, 0x8($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X8);
    // 0x80061E6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80061E70: sll         $t3, $a2, 3
    ctx->r11 = S32(ctx->r6 << 3);
    // 0x80061E74: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80061E78: jal         0x800617F0
    // 0x80061E7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800617F0(rdram, ctx);
        goto after_12;
    // 0x80061E7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80061E80: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80061E84: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80061E88: bne         $at, $zero, L_80061E44
    if (ctx->r1 != 0) {
        // 0x80061E8C: nop
    
            goto L_80061E44;
    }
    // 0x80061E8C: nop

    // 0x80061E90: lw          $t4, 0x8($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X8);
    // 0x80061E94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80061E98: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80061E9C: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80061EA0: addiu       $s1, $s1, -0x1854
    ctx->r17 = ADD32(ctx->r17, -0X1854);
    // 0x80061EA4: addiu       $s0, $s0, -0x1860
    ctx->r16 = ADD32(ctx->r16, -0X1860);
    // 0x80061EA8: sw          $t4, -0x17E4($at)
    MEM_W(-0X17E4, ctx->r1) = ctx->r12;
L_80061EAC:
    // 0x80061EAC: lw          $a2, 0x14($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X14);
    // 0x80061EB0: addiu       $t5, $zero, 0x48
    ctx->r13 = ADD32(0, 0X48);
    // 0x80061EB4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80061EB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80061EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061EC0: jal         0x80070FF0
    // 0x80061EC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80070FF0(rdram, ctx);
        goto after_13;
    // 0x80061EC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_13:
    // 0x80061EC8: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80061ECC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80061ED0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061ED4: jal         0x800617F0
    // 0x80061ED8: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    func_800617F0(rdram, ctx);
        goto after_14;
    // 0x80061ED8: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    after_14:
    // 0x80061EDC: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80061EE0: lw          $a2, 0x14($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X14);
    // 0x80061EE4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80061EE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80061EEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80061EF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061EF4: jal         0x80070FF0
    // 0x80061EF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80070FF0(rdram, ctx);
        goto after_15;
    // 0x80061EF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_15:
    // 0x80061EFC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80061F00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061F04: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x80061F08: lw          $a2, 0x0($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X0);
    // 0x80061F0C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80061F10: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x80061F14: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80061F18: jal         0x800617F0
    // 0x80061F1C: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    func_800617F0(rdram, ctx);
        goto after_16;
    // 0x80061F1C: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_16:
    // 0x80061F20: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80061F24: bne         $s0, $s1, L_80061EAC
    if (ctx->r16 != ctx->r17) {
        // 0x80061F28: nop
    
            goto L_80061EAC;
    }
    // 0x80061F28: nop

    // 0x80061F2C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80061F30: addiu       $s0, $s0, 0xC7C
    ctx->r16 = ADD32(ctx->r16, 0XC7C);
    // 0x80061F34: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80061F38: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    // 0x80061F3C: multu       $t1, $s1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061F40: lw          $a2, 0x14($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X14);
    // 0x80061F44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80061F48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061F4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80061F50: mflo        $t2
    ctx->r10 = lo;
    // 0x80061F54: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80061F58: jal         0x80070FF0
    // 0x80061F5C: nop

    func_80070FF0(rdram, ctx);
        goto after_17;
    // 0x80061F5C: nop

    after_17:
    // 0x80061F60: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80061F64: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80061F68: multu       $t3, $s1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061F6C: addiu       $v1, $v1, -0x17C0
    ctx->r3 = ADD32(ctx->r3, -0X17C0);
    // 0x80061F70: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80061F74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80061F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061F7C: mflo        $a2
    ctx->r6 = lo;
    // 0x80061F80: jal         0x800617F0
    // 0x80061F84: nop

    func_800617F0(rdram, ctx);
        goto after_18;
    // 0x80061F84: nop

    after_18:
    // 0x80061F88: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80061F8C: lw          $a2, 0x14($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X14);
    // 0x80061F90: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80061F94: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80061F98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80061F9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061FA0: jal         0x80070FF0
    // 0x80061FA4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80070FF0(rdram, ctx);
        goto after_19;
    // 0x80061FA4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_19:
    // 0x80061FA8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80061FAC: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80061FB0: addiu       $s1, $s1, -0x17BC
    ctx->r17 = ADD32(ctx->r17, -0X17BC);
    // 0x80061FB4: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80061FB8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80061FBC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80061FC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80061FC4: jal         0x800617F0
    // 0x80061FC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800617F0(rdram, ctx);
        goto after_20;
    // 0x80061FC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80061FCC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80061FD0: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80061FD4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80061FD8: jal         0x80070490
    // 0x80061FDC: addiu       $a0, $a0, -0x17D8
    ctx->r4 = ADD32(ctx->r4, -0X17D8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_21;
    // 0x80061FDC: addiu       $a0, $a0, -0x17D8
    ctx->r4 = ADD32(ctx->r4, -0X17D8);
    after_21:
    // 0x80061FE0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80061FE4: addiu       $a0, $a0, -0x184C
    ctx->r4 = ADD32(ctx->r4, -0X184C);
    // 0x80061FE8: jal         0x80070F00
    // 0x80061FEC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80070F00(rdram, ctx);
        goto after_22;
    // 0x80061FEC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_22:
    // 0x80061FF0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80061FF4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80061FF8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80061FFC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80062000: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80062004: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80062008: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8006200C: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80062010: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80062014: jr          $ra
    // 0x80062018: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80062018: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8006201C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006201C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80062020: lw          $t6, 0xBF4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XBF4);
    // FALLTHROUGH: func_8006201C falls into func_80062024
    func_80062024(rdram, ctx);
;}
RECOMP_FUNC void func_80062024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062028: bne         $t6, $zero, L_80062038
    if (ctx->r14 != 0) {
        // 0x8006202C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80062038;
    }
    // 0x8006202C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062030: b           L_800620B8
    // 0x80062034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800620B8;
    // 0x80062034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80062038:
    // 0x80062038: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8006203C: addiu       $a1, $a1, 0xBEC
    ctx->r5 = ADD32(ctx->r5, 0XBEC);
    // 0x80062040: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80062044: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80062048: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006204C: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80062050: lw          $a0, -0x1858($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1858);
    // 0x80062054: jal         0x800620C8
    // 0x80062058: nop

    func_800620C8(rdram, ctx);
        goto after_0;
    // 0x80062058: nop

    after_0:
    // 0x8006205C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80062060: addiu       $a1, $a1, 0xBEC
    ctx->r5 = ADD32(ctx->r5, 0XBEC);
    // 0x80062064: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80062068: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8006206C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80062070: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80062074: lw          $t0, -0x1858($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1858);
    // 0x80062078: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8006207C: sw          $t0, 0xBF0($at)
    MEM_W(0XBF0, ctx->r1) = ctx->r8;
    // 0x80062080: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80062084: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x80062088: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006208C: bne         $t1, $at, L_80062098
    if (ctx->r9 != ctx->r1) {
        // 0x80062090: sw          $t1, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r9;
            goto L_80062098;
    }
    // 0x80062090: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80062094: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80062098:
    // 0x80062098: beq         $v0, $zero, L_800620B4
    if (ctx->r2 == 0) {
        // 0x8006209C: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_800620B4;
    }
    // 0x8006209C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800620A0: addiu       $v0, $v0, 0xBE8
    ctx->r2 = ADD32(ctx->r2, 0XBE8);
    // 0x800620A4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800620A8: nop

    // 0x800620AC: xori        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 ^ 0X1;
    // 0x800620B0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_800620B4:
    // 0x800620B4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800620B8:
    // 0x800620B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800620BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800620C0: jr          $ra
    // 0x800620C4: nop

    return;
    // 0x800620C4: nop

;}
RECOMP_FUNC void func_800620C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800620C8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800620CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800620D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800620D4: jal         0x80062480
    // 0x800620D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80062480(rdram, ctx);
        goto after_0;
    // 0x800620D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800620DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800620E0: jal         0x80070EA0
    // 0x800620E4: nop

    func_80070EA0(rdram, ctx);
        goto after_1;
    // 0x800620E4: nop

    after_1:
    // 0x800620E8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800620EC: lw          $v1, 0xBF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XBF0);
    // 0x800620F0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800620F4: beq         $v1, $zero, L_80062110
    if (ctx->r3 == 0) {
        // 0x800620F8: nop
    
            goto L_80062110;
    }
    // 0x800620F8: nop

    // 0x800620FC: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x80062100: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80062104: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80062108: jal         0x80071DD0
    // 0x8006210C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_80071DD0(rdram, ctx);
        goto after_2;
    // 0x8006210C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_2:
L_80062110:
    // 0x80062110: jal         0x80071DC0
    // 0x80062114: nop

    func_80071DC0(rdram, ctx);
        goto after_3;
    // 0x80062114: nop

    after_3:
    // 0x80062118: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006211C: lw          $t7, -0x17EC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X17EC);
    // 0x80062120: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80062124: lw          $t0, 0xC84($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XC84);
    // 0x80062128: srl         $t8, $v0, 2
    ctx->r24 = S32(U32(ctx->r2) >> 2);
    // 0x8006212C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80062130: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80062134: andi        $t2, $t1, 0xFFF0
    ctx->r10 = ctx->r9 & 0XFFF0;
    // 0x80062138: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x8006213C: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
    // 0x80062140: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80062144: lw          $v1, -0x17F0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X17F0);
    // 0x80062148: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x8006214C: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80062150: sltu        $at, $a3, $v1
    ctx->r1 = ctx->r7 < ctx->r3 ? 1 : 0;
    // 0x80062154: beq         $at, $zero, L_80062168
    if (ctx->r1 == 0) {
        // 0x80062158: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_80062168;
    }
    // 0x80062158: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006215C: sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    // 0x80062160: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x80062164: nop

L_80062168:
    // 0x80062168: lw          $t4, 0xBE8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XBE8);
    // 0x8006216C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80062170: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80062174: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80062178: lw          $a0, -0x1860($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1860);
    // 0x8006217C: jal         0x8007130C
    // 0x80062180: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8007130C(rdram, ctx);
        goto after_4;
    // 0x80062180: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x80062184: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80062188: lw          $t6, -0x17E4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X17E4);
    // 0x8006218C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80062190: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80062194: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x80062198: beq         $at, $zero, L_800621BC
    if (ctx->r1 == 0) {
        // 0x8006219C: lui         $a0, 0x800C
        ctx->r4 = S32(0X800C << 16);
            goto L_800621BC;
    }
    // 0x8006219C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800621A0: addiu       $a0, $a0, 0x2034
    ctx->r4 = ADD32(ctx->r4, 0X2034);
    // 0x800621A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800621A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800621AC: jal         0x8006879C
    // 0x800621B0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_8006879C(rdram, ctx);
        goto after_5;
    // 0x800621B0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_5:
    // 0x800621B4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800621B8: nop

L_800621BC:
    // 0x800621BC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800621C0: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800621C4: addiu       $a0, $a0, -0x1AC0
    ctx->r4 = ADD32(ctx->r4, -0X1AC0);
    // 0x800621C8: addiu       $t9, $t9, -0x19F0
    ctx->r25 = ADD32(ctx->r25, -0X19F0);
    // 0x800621CC: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x800621D0: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x800621D4: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x800621D8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800621DC: subu        $t0, $t9, $a0
    ctx->r8 = SUB32(ctx->r25, ctx->r4);
    // 0x800621E0: addiu       $t1, $t1, -0x5C0
    ctx->r9 = ADD32(ctx->r9, -0X5C0);
    // 0x800621E4: addiu       $t2, $t2, 0x2F60
    ctx->r10 = ADD32(ctx->r10, 0X2F60);
    // 0x800621E8: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x800621EC: addiu       $a2, $a2, 0xBE8
    ctx->r6 = ADD32(ctx->r6, 0XBE8);
    // 0x800621F0: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800621F4: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800621F8: sw          $a0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r4;
    // 0x800621FC: sw          $t0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r8;
    // 0x80062200: sw          $t1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r9;
    // 0x80062204: sw          $t2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r10;
    // 0x80062208: sw          $t3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r11;
    // 0x8006220C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80062210: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80062214: addiu       $a1, $a1, -0x1860
    ctx->r5 = ADD32(ctx->r5, -0X1860);
    // 0x80062218: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8006221C: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x80062220: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80062224: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x80062228: sw          $t7, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r15;
    // 0x8006222C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80062230: nop

    // 0x80062234: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80062238: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x8006223C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80062240: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80062244: subu        $t2, $v1, $t1
    ctx->r10 = SUB32(ctx->r3, ctx->r9);
    // 0x80062248: sra         $t3, $t2, 3
    ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8006224C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80062250: sw          $t4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r12;
    // 0x80062254: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x80062258: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x8006225C: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x80062260: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x80062264: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x80062268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006226C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062270: jr          $ra
    // 0x80062274: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80062274: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80062278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062278: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006227C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80062280: addiu       $t0, $t0, -0x1800
    ctx->r8 = ADD32(ctx->r8, -0X1800);
    // 0x80062284: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80062288: lw          $s0, 0x4($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X4);
    // 0x8006228C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80062290: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80062294: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80062298: beq         $s0, $zero, L_800622FC
    if (ctx->r16 == 0) {
        // 0x8006229C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800622FC;
    }
    // 0x8006229C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800622A0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800622A4: lw          $a0, 0xC80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC80);
    // 0x800622A8: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
L_800622AC:
    // 0x800622AC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800622B0: addu        $t6, $a3, $a1
    ctx->r14 = ADD32(ctx->r7, ctx->r5);
    // 0x800622B4: sltu        $at, $a3, $v0
    ctx->r1 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x800622B8: bne         $at, $zero, L_800622FC
    if (ctx->r1 != 0) {
        // 0x800622BC: addu        $v1, $v0, $a0
        ctx->r3 = ADD32(ctx->r2, ctx->r4);
            goto L_800622FC;
    }
    // 0x800622BC: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x800622C0: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800622C4: bne         $at, $zero, L_800622EC
    if (ctx->r1 != 0) {
        // 0x800622C8: or          $a2, $s0, $zero
        ctx->r6 = ctx->r16 | 0;
            goto L_800622EC;
    }
    // 0x800622C8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800622CC: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x800622D0: lw          $t7, 0xBE0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XBE0);
    // 0x800622D4: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x800622D8: subu        $a0, $t9, $v0
    ctx->r4 = SUB32(ctx->r25, ctx->r2);
    // 0x800622DC: jal         0x80070EA0
    // 0x800622E0: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    func_80070EA0(rdram, ctx);
        goto after_0;
    // 0x800622E0: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    after_0:
    // 0x800622E4: b           L_80062440
    // 0x800622E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80062440;
    // 0x800622E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800622EC:
    // 0x800622EC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800622F0: nop

    // 0x800622F4: bne         $s0, $zero, L_800622AC
    if (ctx->r16 != 0) {
        // 0x800622F8: nop
    
            goto L_800622AC;
    }
    // 0x800622F8: nop

L_800622FC:
    // 0x800622FC: lw          $s0, 0x8($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X8);
    // 0x80062300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80062304: bne         $s0, $zero, L_80062338
    if (ctx->r16 != 0) {
        // 0x80062308: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80062338;
    }
    // 0x80062308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006230C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80062310: addiu       $a0, $a0, 0x2040
    ctx->r4 = ADD32(ctx->r4, 0X2040);
    // 0x80062314: jal         0x8006879C
    // 0x80062318: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8006879C(rdram, ctx);
        goto after_1;
    // 0x80062318: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8006231C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80062320: addiu       $t0, $t0, -0x1800
    ctx->r8 = ADD32(ctx->r8, -0X1800);
    // 0x80062324: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    // 0x80062328: jal         0x80070EA0
    // 0x8006232C: nop

    func_80070EA0(rdram, ctx);
        goto after_2;
    // 0x8006232C: nop

    after_2:
    // 0x80062330: b           L_80062440
    // 0x80062334: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80062440;
    // 0x80062334: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80062338:
    // 0x80062338: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8006233C: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x80062340: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80062344: jal         0x80070F7C
    // 0x80062348: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
    func_80070F7C(rdram, ctx);
        goto after_3;
    // 0x80062348: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
    after_3:
    // 0x8006234C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80062350: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80062354: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80062358: beq         $a2, $zero, L_8006237C
    if (ctx->r6 == 0) {
        // 0x8006235C: addiu       $t0, $t0, -0x1800
        ctx->r8 = ADD32(ctx->r8, -0X1800);
            goto L_8006237C;
    }
    // 0x8006235C: addiu       $t0, $t0, -0x1800
    ctx->r8 = ADD32(ctx->r8, -0X1800);
    // 0x80062360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80062364: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80062368: jal         0x80070F5C
    // 0x8006236C: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    func_80070F5C(rdram, ctx);
        goto after_4;
    // 0x8006236C: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    after_4:
    // 0x80062370: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80062374: b           L_800623B0
    // 0x80062378: andi        $v0, $a3, 0x1
    ctx->r2 = ctx->r7 & 0X1;
        goto L_800623B0;
    // 0x80062378: andi        $v0, $a3, 0x1
    ctx->r2 = ctx->r7 & 0X1;
L_8006237C:
    // 0x8006237C: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x80062380: nop

    // 0x80062384: beq         $v0, $zero, L_800623A0
    if (ctx->r2 == 0) {
        // 0x80062388: nop
    
            goto L_800623A0;
    }
    // 0x80062388: nop

    // 0x8006238C: sw          $s0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r16;
    // 0x80062390: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80062394: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80062398: b           L_800623AC
    // 0x8006239C: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
        goto L_800623AC;
    // 0x8006239C: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_800623A0:
    // 0x800623A0: sw          $s0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r16;
    // 0x800623A4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800623A8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_800623AC:
    // 0x800623AC: andi        $v0, $a3, 0x1
    ctx->r2 = ctx->r7 & 0X1;
L_800623B0:
    // 0x800623B0: lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10);
    // 0x800623B4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800623B8: subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    // 0x800623BC: sw          $a3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r7;
    // 0x800623C0: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x800623C4: lw          $t3, 0xBE0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XBE0);
    // 0x800623C8: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x800623CC: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    // 0x800623D0: addiu       $t1, $t1, 0xBE4
    ctx->r9 = ADD32(ctx->r9, 0XBE4);
    // 0x800623D4: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800623D8: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800623DC: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800623E0: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800623E4: lw          $t6, 0xC80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XC80);
    // 0x800623E8: lw          $t5, -0x17C0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X17C0);
    // 0x800623EC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800623F0: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x800623F4: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800623F8: addiu       $t7, $t7, -0x17D8
    ctx->r15 = ADD32(ctx->r15, -0X17D8);
    // 0x800623FC: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80062400: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80062404: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80062408: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006240C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80062410: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80062414: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80062418: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8006241C: jal         0x80072B20
    // 0x80062420: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    func_80072B20(rdram, ctx);
        goto after_5;
    // 0x80062420: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_5:
    // 0x80062424: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80062428: jal         0x80070EA0
    // 0x8006242C: nop

    func_80070EA0(rdram, ctx);
        goto after_6;
    // 0x8006242C: nop

    after_6:
    // 0x80062430: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80062434: nop

    // 0x80062438: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8006243C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80062440:
    // 0x80062440: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80062444: jr          $ra
    // 0x80062448: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80062448: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8006244C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006244C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80062450: addiu       $v0, $v0, -0x1800
    ctx->r2 = ADD32(ctx->r2, -0X1800);
    // 0x80062454: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80062458: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006245C: bne         $t6, $zero, L_80062474
    if (ctx->r14 != 0) {
        // 0x80062460: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80062474;
    }
    // 0x80062460: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80062464: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80062468: lw          $t7, -0x17F4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X17F4);
    // 0x8006246C: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x80062470: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
L_80062474:
    // 0x80062474: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x80062478: jr          $ra
    // 0x8006247C: addiu       $v0, $v0, 0x2278
    ctx->r2 = ADD32(ctx->r2, 0X2278);
    return;
    // 0x8006247C: addiu       $v0, $v0, 0x2278
    ctx->r2 = ADD32(ctx->r2, 0X2278);
;}
RECOMP_FUNC void func_80062480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062480: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80062484: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80062488: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x8006248C: addiu       $s5, $s5, 0xBE4
    ctx->r21 = ADD32(ctx->r21, 0XBE4);
    // 0x80062490: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80062494: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80062498: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006249C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800624A0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800624A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800624A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800624AC: beq         $t6, $zero, L_80062504
    if (ctx->r14 == 0) {
        // 0x800624B0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80062504;
    }
    // 0x800624B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800624B4: lui         $s4, 0x800C
    ctx->r20 = S32(0X800C << 16);
    // 0x800624B8: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800624BC: addiu       $s1, $s1, -0x17D8
    ctx->r17 = ADD32(ctx->r17, -0X17D8);
    // 0x800624C0: addiu       $s4, $s4, 0x204C
    ctx->r20 = ADD32(ctx->r20, 0X204C);
    // 0x800624C4: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800624C8: addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // 0x800624CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800624D0:
    // 0x800624D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800624D4: jal         0x80070620
    // 0x800624D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800624D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800624DC: bne         $v0, $s3, L_800624F0
    if (ctx->r2 != ctx->r19) {
        // 0x800624E0: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800624F0;
    }
    // 0x800624E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800624E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800624E8: jal         0x8006879C
    // 0x800624EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8006879C(rdram, ctx);
        goto after_1;
    // 0x800624EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_800624F0:
    // 0x800624F0: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x800624F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800624F8: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x800624FC: bne         $at, $zero, L_800624D0
    if (ctx->r1 != 0) {
        // 0x80062500: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800624D0;
    }
    // 0x80062500: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80062504:
    // 0x80062504: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x80062508: addiu       $s2, $s2, -0x1800
    ctx->r18 = ADD32(ctx->r18, -0X1800);
    // 0x8006250C: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x80062510: lui         $s4, 0x8009
    ctx->r20 = S32(0X8009 << 16);
    // 0x80062514: beq         $s0, $zero, L_80062594
    if (ctx->r16 == 0) {
        // 0x80062518: addiu       $s4, $s4, 0xBE0
        ctx->r20 = ADD32(ctx->r20, 0XBE0);
            goto L_80062594;
    }
    // 0x80062518: addiu       $s4, $s4, 0xBE0
    ctx->r20 = ADD32(ctx->r20, 0XBE0);
    // 0x8006251C: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80062520: addiu       $s3, $s3, 0xC88
    ctx->r19 = ADD32(ctx->r19, 0XC88);
L_80062524:
    // 0x80062524: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80062528: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8006252C: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80062530: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80062534: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80062538: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x8006253C: beq         $at, $zero, L_8006258C
    if (ctx->r1 == 0) {
        // 0x80062540: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8006258C;
    }
    // 0x80062540: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80062544: lw          $t2, 0x4($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X4);
    // 0x80062548: nop

    // 0x8006254C: bne         $s0, $t2, L_80062558
    if (ctx->r16 != ctx->r10) {
        // 0x80062550: nop
    
            goto L_80062558;
    }
    // 0x80062550: nop

    // 0x80062554: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
L_80062558:
    // 0x80062558: jal         0x80070F7C
    // 0x8006255C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80070F7C(rdram, ctx);
        goto after_2;
    // 0x8006255C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80062560: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x80062564: nop

    // 0x80062568: beq         $a1, $zero, L_80062580
    if (ctx->r5 == 0) {
        // 0x8006256C: nop
    
            goto L_80062580;
    }
    // 0x8006256C: nop

    // 0x80062570: jal         0x80070F5C
    // 0x80062574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80070F5C(rdram, ctx);
        goto after_3;
    // 0x80062574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80062578: b           L_8006258C
    // 0x8006257C: nop

        goto L_8006258C;
    // 0x8006257C: nop

L_80062580:
    // 0x80062580: sw          $s0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r16;
    // 0x80062584: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80062588: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_8006258C:
    // 0x8006258C: bne         $s1, $zero, L_80062524
    if (ctx->r17 != 0) {
        // 0x80062590: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80062524;
    }
    // 0x80062590: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80062594:
    // 0x80062594: lui         $s4, 0x8009
    ctx->r20 = S32(0X8009 << 16);
    // 0x80062598: addiu       $s4, $s4, 0xBE0
    ctx->r20 = ADD32(ctx->r20, 0XBE0);
    // 0x8006259C: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800625A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800625A4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800625A8: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x800625AC: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x800625B0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800625B4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800625B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800625BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800625C0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800625C4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800625C8: jr          $ra
    // 0x800625CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800625CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800625D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800625D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800625D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800625D8: jal         0x80062B08
    // 0x800625DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80062B08(rdram, ctx);
        goto after_0;
    // 0x800625DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800625E0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800625E4: jal         0x80070F2C
    // 0x800625E8: addiu       $a0, $a0, -0x184C
    ctx->r4 = ADD32(ctx->r4, -0X184C);
    func_80070F2C(rdram, ctx);
        goto after_1;
    // 0x800625E8: addiu       $a0, $a0, -0x184C
    ctx->r4 = ADD32(ctx->r4, -0X184C);
    after_1:
    // 0x800625EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800625F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800625F4: jr          $ra
    // 0x800625F8: nop

    return;
    // 0x800625F8: nop

    // 0x800625FC: nop

;}
RECOMP_FUNC void func_80062600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062600: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80062604: addiu       $a1, $a1, -0x1780
    ctx->r5 = ADD32(ctx->r5, -0X1780);
    // 0x80062608: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8006260C: addiu       $t6, $t6, 0x2654
    ctx->r14 = ADD32(ctx->r14, 0X2654);
    // 0x80062610: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80062614: sw          $t6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r14;
    // 0x80062618: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006261C: lw          $t7, -0x176C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X176C);

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_80062620
    func_80062620(rdram, ctx);
}
RECOMP_FUNC void func_80062620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062624: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x80062628: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x8006262C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80062630: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80062634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062638: lw          $a0, 0x1040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1040);
    // 0x8006263C: jal         0x800716E0
    // 0x80062640: nop

    func_800716E0(rdram, ctx);
        goto after_0;
    // 0x80062640: nop

    after_0:
    // 0x80062644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006264C: jr          $ra
    // 0x80062650: nop

    return;
    // 0x80062650: nop

;}
RECOMP_FUNC void func_80062654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062654: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006265C: jal         0x80068958
    // 0x80062660: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80068958(rdram, ctx);
        goto after_0;
    // 0x80062660: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80062664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006266C: jr          $ra
    // 0x80062670: addiu       $v0, $zero, 0x208D
    ctx->r2 = ADD32(0, 0X208D);
    return;
    // 0x80062670: addiu       $v0, $zero, 0x208D
    ctx->r2 = ADD32(0, 0X208D);
    // 0x80062674: nop

    // 0x80062678: nop

    // 0x8006267C: nop

;}
