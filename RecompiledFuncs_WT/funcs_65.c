#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80068018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006801C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80068020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068024: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80068028: jal         0x800679D0
    // 0x8006802C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_800679D0(rdram, ctx);
        goto after_0;
    // 0x8006802C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x80068030: bne         $v0, $zero, L_80068040
    if (ctx->r2 != 0) {
        // 0x80068034: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80068040;
    }
    // 0x80068034: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80068038: b           L_8006804C
    // 0x8006803C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006804C;
    // 0x8006803C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80068040:
    // 0x80068040: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80068044: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80068048: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
L_8006804C:
    // 0x8006804C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068050: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80068054: jr          $ra
    // 0x80068058: nop

    return;
    // 0x80068058: nop

;}
RECOMP_FUNC void func_8006805C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006805C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80068060: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068064: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80068068: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006806C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80068070: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80068074: sll         $t7, $t6, 0
    ctx->r15 = S32(ctx->r14 << 0);
    // 0x80068078: bgez        $t7, L_800680B4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8006807C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800680B4;
    }
    // 0x8006807C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80068080: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80068084: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80068088: and         $t9, $a1, $at
    ctx->r25 = ctx->r5 & ctx->r1;
    // 0x8006808C: srl         $t0, $t9, 1
    ctx->r8 = S32(U32(ctx->r25) >> 1);
    // 0x80068090: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80068094: lhu         $t8, -0x7840($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X7840);
    // 0x80068098: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8006809C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800680A0: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800680A4: sh          $t8, 0x20($at)
    MEM_H(0X20, ctx->r1) = ctx->r24;
    // 0x800680A8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800680AC: b           L_8006812C
    // 0x800680B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8006812C;
    // 0x800680B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800680B4:
    // 0x800680B4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800680B8: sw          $t2, 0x59D4($at)
    MEM_W(0X59D4, ctx->r1) = ctx->r10;
    // 0x800680BC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800680C0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800680C4: and         $s1, $a1, $at
    ctx->r17 = ctx->r5 & ctx->r1;
    // 0x800680C8: srl         $t3, $s1, 1
    ctx->r11 = S32(U32(ctx->r17) >> 1);
    // 0x800680CC: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x800680D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
L_800680D4:
    // 0x800680D4: jal         0x80068004
    // 0x800680D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80068004(rdram, ctx);
        goto after_0;
    // 0x800680D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800680DC: bne         $v0, $zero, L_800680F4
    if (ctx->r2 != 0) {
        // 0x800680E0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800680F4;
    }
    // 0x800680E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800680E4: jal         0x80067EB0
    // 0x800680E8: nop

    func_80067EB0(rdram, ctx);
        goto after_1;
    // 0x800680E8: nop

    after_1:
    // 0x800680EC: jal         0x80067FB8
    // 0x800680F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80067FB8(rdram, ctx);
        goto after_2;
    // 0x800680F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
L_800680F4:
    // 0x800680F4: beq         $s0, $zero, L_800680D4
    if (ctx->r16 == 0) {
        // 0x800680F8: nop
    
            goto L_800680D4;
    }
    // 0x800680F8: nop

    // 0x800680FC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80068100: sw          $zero, 0x59D4($at)
    MEM_W(0X59D4, ctx->r1) = 0;
    // 0x80068104: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80068108: lhu         $t4, -0x7840($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X7840);
    // 0x8006810C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80068110: sll         $t5, $s1, 1
    ctx->r13 = S32(ctx->r17 << 1);
    // 0x80068114: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80068118: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8006811C: sh          $t4, 0x20($at)
    MEM_H(0X20, ctx->r1) = ctx->r12;
    // 0x80068120: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80068124: nop

    // 0x80068128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006812C:
    // 0x8006812C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80068130: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80068134: jr          $ra
    // 0x80068138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80068138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006813C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006813C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80068140: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80068144: lw          $t6, 0x76F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X76F4);
    // 0x80068148: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006814C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80068150: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80068154: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80068158: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006815C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80068160: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80068164: beq         $t6, $zero, L_800681EC
    if (ctx->r14 == 0) {
        // 0x80068168: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800681EC;
    }
    // 0x80068168: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006816C: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80068170: addiu       $s6, $t7, 0x76F4
    ctx->r22 = ADD32(ctx->r15, 0X76F4);
    // 0x80068174: lui         $s4, 0xFF
    ctx->r20 = S32(0XFF << 16);
    // 0x80068178: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8006817C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x80068180: addiu       $s3, $s3, -0x7830
    ctx->r19 = ADD32(ctx->r19, -0X7830);
    // 0x80068184: ori         $s4, $s4, 0xFFFF
    ctx->r20 = ctx->r20 | 0XFFFF;
    // 0x80068188: lui         $s5, 0x800
    ctx->r21 = S32(0X800 << 16);
L_8006818C:
    // 0x8006818C: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x80068190: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80068194: beq         $s1, $zero, L_800681DC
    if (ctx->r17 == 0) {
        // 0x80068198: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_800681DC;
    }
    // 0x80068198: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8006819C: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
L_800681A0:
    // 0x800681A0: jal         0x80068374
    // 0x800681A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80068374(rdram, ctx);
        goto after_0;
    // 0x800681A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800681A8: and         $t8, $s2, $s4
    ctx->r24 = ctx->r18 & ctx->r20;
    // 0x800681AC: srl         $t9, $t8, 1
    ctx->r25 = S32(U32(ctx->r24) >> 1);
    // 0x800681B0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800681B4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800681B8: addu        $v1, $s3, $t0
    ctx->r3 = ADD32(ctx->r19, ctx->r8);
    // 0x800681BC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800681C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800681C4: or          $t2, $t1, $s5
    ctx->r10 = ctx->r9 | ctx->r21;
    // 0x800681C8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800681CC: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800681D0: nop

    // 0x800681D4: bne         $s1, $zero, L_800681A0
    if (ctx->r17 != 0) {
        // 0x800681D8: or          $s2, $s1, $zero
        ctx->r18 = ctx->r17 | 0;
            goto L_800681A0;
    }
    // 0x800681D8: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
L_800681DC:
    // 0x800681DC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x800681E0: nop

    // 0x800681E4: bne         $v0, $zero, L_8006818C
    if (ctx->r2 != 0) {
        // 0x800681E8: nop
    
            goto L_8006818C;
    }
    // 0x800681E8: nop

L_800681EC:
    // 0x800681EC: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800681F0: lw          $t3, 0x3C54($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3C54);
    // 0x800681F4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800681F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800681FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068200: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80068204: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80068208: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006820C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80068210: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80068214: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80068218: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8006821C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80068220: jr          $ra
    // 0x80068224: sw          $t3, 0x3C50($at)
    MEM_W(0X3C50, ctx->r1) = ctx->r11;
    return;
    // 0x80068224: sw          $t3, 0x3C50($at)
    MEM_W(0X3C50, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void func_80068228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068228: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006822C: sll         $t6, $a0, 0
    ctx->r14 = S32(ctx->r4 << 0);
    // 0x80068230: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80068234: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80068238: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006823C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068240: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80068244: bgez        $t6, L_80068254
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80068248: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80068254;
    }
    // 0x80068248: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8006824C: b           L_8006833C
    // 0x80068250: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8006833C;
    // 0x80068250: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80068254:
    // 0x80068254: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80068258: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8006825C: and         $s1, $a2, $at
    ctx->r17 = ctx->r6 & ctx->r1;
    // 0x80068260: srl         $t7, $s1, 1
    ctx->r15 = S32(U32(ctx->r17) >> 1);
    // 0x80068264: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80068268: addiu       $t9, $t9, -0x7830
    ctx->r25 = ADD32(ctx->r25, -0X7830);
    // 0x8006826C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80068270: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80068274: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80068278: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x8006827C: beq         $v0, $zero, L_80068294
    if (ctx->r2 == 0) {
        // 0x80068280: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80068294;
    }
    // 0x80068280: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80068284: lui         $at, 0xF7FF
    ctx->r1 = S32(0XF7FF << 16);
    // 0x80068288: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8006828C: b           L_80068310
    // 0x80068290: and         $v1, $v0, $at
    ctx->r3 = ctx->r2 & ctx->r1;
        goto L_80068310;
    // 0x80068290: and         $v1, $v0, $at
    ctx->r3 = ctx->r2 & ctx->r1;
L_80068294:
    // 0x80068294: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80068298: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8006829C: sw          $t0, 0x59D4($at)
    MEM_W(0X59D4, ctx->r1) = ctx->r8;
    // 0x800682A0: addiu       $s2, $s2, 0x3C54
    ctx->r18 = ADD32(ctx->r18, 0X3C54);
    // 0x800682A4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800682A8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800682AC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800682B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800682B4:
    // 0x800682B4: jal         0x800678A0
    // 0x800682B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800678A0(rdram, ctx);
        goto after_0;
    // 0x800682B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800682BC: bne         $v0, $zero, L_800682D4
    if (ctx->r2 != 0) {
        // 0x800682C0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800682D4;
    }
    // 0x800682C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800682C4: jal         0x80067EB0
    // 0x800682C8: nop

    func_80067EB0(rdram, ctx);
        goto after_1;
    // 0x800682C8: nop

    after_1:
    // 0x800682CC: jal         0x80067FB8
    // 0x800682D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80067FB8(rdram, ctx);
        goto after_2;
    // 0x800682D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
L_800682D4:
    // 0x800682D4: beq         $s0, $zero, L_800682B4
    if (ctx->r16 == 0) {
        // 0x800682D8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800682B4;
    }
    // 0x800682D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800682DC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800682E0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800682E4: sw          $zero, 0x59D4($at)
    MEM_W(0X59D4, ctx->r1) = 0;
    // 0x800682E8: sw          $s0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r16;
    // 0x800682EC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800682F0: lhu         $t2, -0x7840($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X7840);
    // 0x800682F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800682F8: sll         $t3, $s1, 1
    ctx->r11 = S32(ctx->r17 << 1);
    // 0x800682FC: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80068300: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80068304: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80068308: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8006830C: sh          $t2, 0x20($at)
    MEM_H(0X20, ctx->r1) = ctx->r10;
L_80068310:
    // 0x80068310: beq         $a3, $zero, L_8006833C
    if (ctx->r7 == 0) {
        // 0x80068314: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8006833C;
    }
    // 0x80068314: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80068318: lhu         $v0, 0x7C($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X7C);
    // 0x8006831C: sw          $a2, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r6;
    // 0x80068320: andi        $t4, $v0, 0x80
    ctx->r12 = ctx->r2 & 0X80;
    // 0x80068324: bne         $t4, $zero, L_80068338
    if (ctx->r12 != 0) {
        // 0x80068328: andi        $t5, $v0, 0x400
        ctx->r13 = ctx->r2 & 0X400;
            goto L_80068338;
    }
    // 0x80068328: andi        $t5, $v0, 0x400
    ctx->r13 = ctx->r2 & 0X400;
    // 0x8006832C: bne         $t5, $zero, L_80068338
    if (ctx->r13 != 0) {
        // 0x80068330: ori         $t6, $v0, 0x400
        ctx->r14 = ctx->r2 | 0X400;
            goto L_80068338;
    }
    // 0x80068330: ori         $t6, $v0, 0x400
    ctx->r14 = ctx->r2 | 0X400;
    // 0x80068334: sh          $t6, 0x7C($a3)
    MEM_H(0X7C, ctx->r7) = ctx->r14;
L_80068338:
    // 0x80068338: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8006833C:
    // 0x8006833C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80068340: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068344: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80068348: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006834C: jr          $ra
    // 0x80068350: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80068350: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80068354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068354: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006835C: jal         0x80068228
    // 0x80068360: nop

    func_80068228(rdram, ctx);
        goto after_0;
    // 0x80068360: nop

    after_0:
    // 0x80068364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006836C: jr          $ra
    // 0x80068370: nop

    return;
    // 0x80068370: nop

;}
RECOMP_FUNC void func_80068374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006837C: jal         0x80068228
    // 0x80068380: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80068228(rdram, ctx);
        goto after_0;
    // 0x80068380: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80068384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006838C: jr          $ra
    // 0x80068390: nop

    return;
    // 0x80068390: nop

;}
RECOMP_FUNC void func_80068394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068394: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80068398: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8006839C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800683A0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800683A4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800683A8: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800683AC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800683B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800683B4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800683B8: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800683BC: lui         $s5, 0x3
    ctx->r21 = S32(0X3 << 16);
    // 0x800683C0: lui         $s6, 0x1
    ctx->r22 = S32(0X1 << 16);
    // 0x800683C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800683C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800683CC: ori         $s6, $s6, 0x3880
    ctx->r22 = ctx->r22 | 0X3880;
    // 0x800683D0: ori         $s5, $s5, 0xD40
    ctx->r21 = ctx->r21 | 0XD40;
    // 0x800683D4: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x800683D8: addiu       $s3, $s3, -0x7840
    ctx->r19 = ADD32(ctx->r19, -0X7840);
    // 0x800683DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800683E0: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x800683E4: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_800683E8:
    // 0x800683E8: jal         0x80067EB0
    // 0x800683EC: nop

    func_80067EB0(rdram, ctx);
        goto after_0;
    // 0x800683EC: nop

    after_0:
    // 0x800683F0: beq         $v0, $s2, L_80068460
    if (ctx->r2 == ctx->r18) {
        // 0x800683F4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80068460;
    }
    // 0x800683F4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800683F8: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800683FC: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x80068400: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80068404: lhu         $t6, 0x0($s3)
    ctx->r14 = MEM_HU(ctx->r19, 0X0);
    // 0x80068408: nop

    // 0x8006840C: subu        $v1, $t6, $t9
    ctx->r3 = SUB32(ctx->r14, ctx->r25);
    // 0x80068410: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80068414: bne         $at, $zero, L_80068460
    if (ctx->r1 != 0) {
        // 0x80068418: slti        $at, $v1, 0x385
        ctx->r1 = SIGNED(ctx->r3) < 0X385 ? 1 : 0;
            goto L_80068460;
    }
    // 0x80068418: slti        $at, $v1, 0x385
    ctx->r1 = SIGNED(ctx->r3) < 0X385 ? 1 : 0;
    // 0x8006841C: bne         $at, $zero, L_80068438
    if (ctx->r1 != 0) {
        // 0x80068420: nop
    
            goto L_80068438;
    }
    // 0x80068420: nop

    // 0x80068424: jal         0x80065464
    // 0x80068428: nop

    func_80065464(rdram, ctx);
        goto after_1;
    // 0x80068428: nop

    after_1:
    // 0x8006842C: slt         $at, $v0, $s5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80068430: bne         $at, $zero, L_8006844C
    if (ctx->r1 != 0) {
        // 0x80068434: nop
    
            goto L_8006844C;
    }
    // 0x80068434: nop

L_80068438:
    // 0x80068438: jal         0x8006541C
    // 0x8006843C: nop

    func_8006541C(rdram, ctx);
        goto after_2;
    // 0x8006843C: nop

    after_2:
    // 0x80068440: slt         $at, $v0, $s6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80068444: beq         $at, $zero, L_80068454
    if (ctx->r1 == 0) {
        // 0x80068448: nop
    
            goto L_80068454;
    }
    // 0x80068448: nop

L_8006844C:
    // 0x8006844C: jal         0x80067FB8
    // 0x80068450: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80067FB8(rdram, ctx);
        goto after_3;
    // 0x80068450: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
L_80068454:
    // 0x80068454: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80068458: bne         $s0, $s7, L_800683E8
    if (ctx->r16 != ctx->r23) {
        // 0x8006845C: nop
    
            goto L_800683E8;
    }
    // 0x8006845C: nop

L_80068460:
    // 0x80068460: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80068464: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80068468: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006846C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80068470: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80068474: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80068478: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8006847C: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80068480: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80068484: jr          $ra
    // 0x80068488: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80068488: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006848C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006848C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80068490: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80068494: addiu       $t0, $t0, 0x90
    ctx->r8 = ADD32(ctx->r8, 0X90);
    // 0x80068498: addiu       $v1, $v1, -0x520
    ctx->r3 = ADD32(ctx->r3, -0X520);
    // 0x8006849C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800684A0: addiu       $a3, $zero, -0x8
    ctx->r7 = ADD32(0, -0X8);
L_800684A4:
    // 0x800684A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800684A8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800684AC: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800684B0: addiu       $t6, $v0, 0xB
    ctx->r14 = ADD32(ctx->r2, 0XB);
    // 0x800684B4: bne         $t7, $zero, L_800684F4
    if (ctx->r15 != 0) {
        // 0x800684B8: and         $a0, $t6, $a3
        ctx->r4 = ctx->r14 & ctx->r7;
            goto L_800684F4;
    }
    // 0x800684B8: and         $a0, $t6, $a3
    ctx->r4 = ctx->r14 & ctx->r7;
    // 0x800684BC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800684C0: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x800684C4: beq         $a1, $zero, L_800684F4
    if (ctx->r5 == 0) {
        // 0x800684C8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800684F4;
    }
    // 0x800684C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800684CC:
    // 0x800684CC: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x800684D0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800684D4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800684D8: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x800684DC: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x800684E0: sltu        $at, $a2, $a1
    ctx->r1 = ctx->r6 < ctx->r5 ? 1 : 0;
    // 0x800684E4: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x800684E8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800684EC: bne         $at, $zero, L_800684CC
    if (ctx->r1 != 0) {
        // 0x800684F0: sh          $t3, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r11;
            goto L_800684CC;
    }
    // 0x800684F0: sh          $t3, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r11;
L_800684F4:
    // 0x800684F4: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x800684F8: bne         $at, $zero, L_800684A4
    if (ctx->r1 != 0) {
        // 0x800684FC: nop
    
            goto L_800684A4;
    }
    // 0x800684FC: nop

    // 0x80068500: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80068504: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80068508: addiu       $a0, $a0, 0x90
    ctx->r4 = ADD32(ctx->r4, 0X90);
    // 0x8006850C: addiu       $v1, $v1, -0x520
    ctx->r3 = ADD32(ctx->r3, -0X520);
L_80068510:
    // 0x80068510: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80068514: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80068518: addiu       $t4, $v0, 0xB
    ctx->r12 = ADD32(ctx->r2, 0XB);
    // 0x8006851C: and         $t5, $t4, $a3
    ctx->r13 = ctx->r12 & ctx->r7;
    // 0x80068520: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80068524: sh          $zero, 0x0($t5)
    MEM_H(0X0, ctx->r13) = 0;
    // 0x80068528: lw          $v0, -0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, -0XC);
    // 0x8006852C: nop

    // 0x80068530: addiu       $t6, $v0, 0xB
    ctx->r14 = ADD32(ctx->r2, 0XB);
    // 0x80068534: and         $t7, $t6, $a3
    ctx->r15 = ctx->r14 & ctx->r7;
    // 0x80068538: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8006853C: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x80068540: lw          $v0, -0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X8);
    // 0x80068544: nop

    // 0x80068548: addiu       $t8, $v0, 0xB
    ctx->r24 = ADD32(ctx->r2, 0XB);
    // 0x8006854C: and         $t9, $t8, $a3
    ctx->r25 = ctx->r24 & ctx->r7;
    // 0x80068550: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80068554: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
    // 0x80068558: lw          $v0, -0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X4);
    // 0x8006855C: nop

    // 0x80068560: addiu       $t2, $v0, 0xB
    ctx->r10 = ADD32(ctx->r2, 0XB);
    // 0x80068564: and         $t3, $t2, $a3
    ctx->r11 = ctx->r10 & ctx->r7;
    // 0x80068568: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8006856C: bne         $v1, $a0, L_80068510
    if (ctx->r3 != ctx->r4) {
        // 0x80068570: sh          $zero, 0x0($t3)
        MEM_H(0X0, ctx->r11) = 0;
            goto L_80068510;
    }
    // 0x80068570: sh          $zero, 0x0($t3)
    MEM_H(0X0, ctx->r11) = 0;
    // 0x80068574: jr          $ra
    // 0x80068578: nop

    return;
    // 0x80068578: nop

;}
RECOMP_FUNC void func_8006857C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006857C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80068580: lw          $v1, 0x3C58($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3C58);
    // 0x80068584: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80068588: bne         $v1, $zero, L_8006859C
    if (ctx->r3 != 0) {
        // 0x8006858C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8006859C;
    }
    // 0x8006858C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80068590: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80068594: lw          $v1, 0x3C48($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3C48);
    // 0x80068598: nop

L_8006859C:
    // 0x8006859C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800685A0: lhu         $a0, 0x5B18($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X5B18);
    // 0x800685A4: lhu         $v0, -0x7840($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7840);
    // 0x800685A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800685AC: beq         $v0, $a0, L_800685BC
    if (ctx->r2 == ctx->r4) {
        // 0x800685B0: addiu       $a1, $v0, 0x1
        ctx->r5 = ADD32(ctx->r2, 0X1);
            goto L_800685BC;
    }
    // 0x800685B0: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x800685B4: bne         $a1, $a0, L_800685C8
    if (ctx->r5 != ctx->r4) {
            // 0x800685B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    func_800685C8(rdram, ctx);
    return;
    }
    // 0x800685B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800685BC:
    // 0x800685BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800685C0: jr          $ra
    // 0x800685C4: sw          $v1, 0x3C58($at)
    MEM_W(0X3C58, ctx->r1) = ctx->r3;
    return;
    // 0x800685C4: sw          $v1, 0x3C58($at)
    MEM_W(0X3C58, ctx->r1) = ctx->r3;
;}
RECOMP_FUNC void func_800685C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800685C8: lw          $v0, 0x3C48($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3C48);
    // 0x800685CC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800685D0: sh          $a1, 0x5B18($at)
    MEM_H(0X5B18, ctx->r1) = ctx->r5;
    // 0x800685D4: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800685D8: addiu       $t6, $v0, 0x200
    ctx->r14 = ADD32(ctx->r2, 0X200);
    // 0x800685DC: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x800685E0: bne         $at, $zero, L_800685EC
    if (ctx->r1 != 0) {
        // 0x800685E4: nop
    
            goto L_800685EC;
    }
    // 0x800685E4: nop

    // 0x800685E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800685EC:
    // 0x800685EC: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800685F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800685F4: sw          $v1, 0x3C58($at)
    MEM_W(0X3C58, ctx->r1) = ctx->r3;
    // 0x800685F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800685FC: jr          $ra
    // 0x80068600: nop

    return;
    // 0x80068600: nop

;}
RECOMP_FUNC void func_80068604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068604: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80068608: addiu       $t7, $t7, 0x5B1C
    ctx->r15 = ADD32(ctx->r15, 0X5B1C);
    // 0x8006860C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80068610: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80068614: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80068618: nop

    // 0x8006861C: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x80068620: bgez        $v1, L_80068630
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80068624: sw          $v1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r3;
            goto L_80068630;
    }
    // 0x80068624: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80068628: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8006862C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_80068630:
    // 0x80068630: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80068634: bne         $at, $zero, L_80068640
    if (ctx->r1 != 0) {
        // 0x80068638: nop
    
            goto L_80068640;
    }
    // 0x80068638: nop

    // 0x8006863C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80068640:
    // 0x80068640: jr          $ra
    // 0x80068644: nop

    return;
    // 0x80068644: nop

;}
RECOMP_FUNC void func_80068648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068648: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006864C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80068650: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80068654: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80068658: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8006865C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80068660: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x80068664: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80068668: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x8006866C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80068670: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80068674: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80068678: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006867C: addiu       $s7, $s7, 0x3C84
    ctx->r23 = ADD32(ctx->r23, 0X3C84);
    // 0x80068680: addiu       $s6, $s6, 0x5B28
    ctx->r22 = ADD32(ctx->r22, 0X5B28);
    // 0x80068684: addiu       $s5, $s5, 0x3C60
    ctx->r21 = ADD32(ctx->r21, 0X3C60);
    // 0x80068688: addiu       $s3, $sp, 0x5C
    ctx->r19 = ADD32(ctx->r29, 0X5C);
    // 0x8006868C: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_80068690:
    // 0x80068690: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80068694: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    // 0x80068698: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
L_8006869C:
    // 0x8006869C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800686A0: jal         0x80067628
    // 0x800686A4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80067628(rdram, ctx);
        goto after_0;
    // 0x800686A4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x800686A8: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800686AC: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800686B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800686B4: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800686B8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800686BC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800686C0: bne         $s0, $s4, L_8006869C
    if (ctx->r16 != ctx->r20) {
        // 0x800686C4: sh          $zero, 0x0($t7)
        MEM_H(0X0, ctx->r15) = 0;
            goto L_8006869C;
    }
    // 0x800686C4: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x800686C8: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    // 0x800686CC: bne         $s5, $s7, L_80068690
    if (ctx->r21 != ctx->r23) {
        // 0x800686D0: addiu       $s6, $s6, 0xC
        ctx->r22 = ADD32(ctx->r22, 0XC);
            goto L_80068690;
    }
    // 0x800686D0: addiu       $s6, $s6, 0xC
    ctx->r22 = ADD32(ctx->r22, 0XC);
    // 0x800686D4: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800686D8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800686DC: addiu       $a1, $a1, 0x3C48
    ctx->r5 = ADD32(ctx->r5, 0X3C48);
    // 0x800686E0: jal         0x80067628
    // 0x800686E4: addiu       $a0, $a0, -0x2424
    ctx->r4 = ADD32(ctx->r4, -0X2424);
    func_80067628(rdram, ctx);
        goto after_1;
    // 0x800686E4: addiu       $a0, $a0, -0x2424
    ctx->r4 = ADD32(ctx->r4, -0X2424);
    after_1:
    // 0x800686E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800686EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800686F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800686F4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800686F8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800686FC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80068700: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80068704: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80068708: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8006870C: jr          $ra
    // 0x80068710: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80068710: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80068714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068714: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x80068718: bne         $at, $zero, L_80068728
    if (ctx->r1 != 0) {
            // 0x8006871C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    func_80068728(rdram, ctx);
    return;
    }
    // 0x8006871C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80068720: jr          $ra
    // 0x80068724: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80068724: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_80068728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068728: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8006872C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80068730: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x80068734: lw          $v1, 0x5B1C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5B1C);
    // 0x80068738: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8006873C: bne         $v1, $zero, L_8006874C
    if (ctx->r3 != 0) {
            // 0x80068740: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    func_8006874C(rdram, ctx);
    return;
    }
    // 0x80068740: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80068744: jr          $ra
    // 0x80068748: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80068748: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_8006874C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006874C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80068750: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80068754: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80068758: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006875C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80068760: lw          $v0, 0x3C5C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3C5C);
    // 0x80068764: nop

    // 0x80068768: jr          $ra
    // 0x8006876C: nop

    return;
    // 0x8006876C: nop

;}
RECOMP_FUNC void func_80068770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068774: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x80068778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006877C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80068780: beq         $a0, $at, L_800687A4
    if (ctx->r4 == ctx->r1) {
        // 0x80068784: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800687A4;
    }
    // 0x80068784: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80068788: addiu       $at, $zero, 0x157
    ctx->r1 = ADD32(0, 0X157);
    // 0x8006878C: beq         $a0, $at, L_800687A4
    if (ctx->r4 == ctx->r1) {
        // 0x80068790: slti        $at, $a0, 0x84
        ctx->r1 = SIGNED(ctx->r4) < 0X84 ? 1 : 0;
            goto L_800687A4;
    }
    // 0x80068790: slti        $at, $a0, 0x84
    ctx->r1 = SIGNED(ctx->r4) < 0X84 ? 1 : 0;
    // 0x80068794: bne         $at, $zero, L_800687A8
    if (ctx->r1 != 0) {
        // 0x80068798: slti        $at, $a0, 0x137
        ctx->r1 = SIGNED(ctx->r4) < 0X137 ? 1 : 0;
            goto L_800687A8;
    }
    // 0x80068798: slti        $at, $a0, 0x137
    ctx->r1 = SIGNED(ctx->r4) < 0X137 ? 1 : 0;
    // 0x8006879C: beq         $at, $zero, L_800687A8
    if (ctx->r1 == 0) {
        // 0x800687A0: nop
    
            goto L_800687A8;
    }
    // 0x800687A0: nop

L_800687A4:
    // 0x800687A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800687A8:
    // 0x800687A8: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800687AC: addiu       $t7, $t7, -0x520
    ctx->r15 = ADD32(ctx->r15, -0X520);
    // 0x800687B0: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800687B4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800687B8: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800687BC: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800687C0: addiu       $a0, $a0, 0xB
    ctx->r4 = ADD32(ctx->r4, 0XB);
    // 0x800687C4: and         $t8, $a0, $at
    ctx->r24 = ctx->r4 & ctx->r1;
    // 0x800687C8: addiu       $at, $zero, 0x164
    ctx->r1 = ADD32(0, 0X164);
    // 0x800687CC: lw          $a1, -0xB($a0)
    ctx->r5 = MEM_W(ctx->r4, -0XB);
    // 0x800687D0: bne         $a2, $at, L_800687E8
    if (ctx->r6 != ctx->r1) {
        // 0x800687D4: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_800687E8;
    }
    // 0x800687D4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800687D8: jal         0x8006857C
    // 0x800687DC: nop

    func_8006857C(rdram, ctx);
        goto after_0;
    // 0x800687DC: nop

    after_0:
    // 0x800687E0: b           L_80068868
    // 0x800687E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80068868;
    // 0x800687E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800687E8:
    // 0x800687E8: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x800687EC: addiu       $t9, $t9, -0x498
    ctx->r25 = ADD32(ctx->r25, -0X498);
    // 0x800687F0: bne         $v1, $t9, L_80068814
    if (ctx->r3 != ctx->r25) {
        // 0x800687F4: lui         $t1, 0x800A
        ctx->r9 = S32(0X800A << 16);
            goto L_80068814;
    }
    // 0x800687F4: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x800687F8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800687FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80068800: lhu         $a3, 0x80($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X80);
    // 0x80068804: jal         0x80068714
    // 0x80068808: nop

    func_80068714(rdram, ctx);
        goto after_1;
    // 0x80068808: nop

    after_1:
    // 0x8006880C: b           L_80068868
    // 0x80068810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80068868;
    // 0x80068810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80068814:
    // 0x80068814: addiu       $t1, $t1, -0x4A0
    ctx->r9 = ADD32(ctx->r9, -0X4A0);
    // 0x80068818: bne         $v1, $t1, L_8006883C
    if (ctx->r3 != ctx->r9) {
        // 0x8006881C: lui         $t3, 0x800A
        ctx->r11 = S32(0X800A << 16);
            goto L_8006883C;
    }
    // 0x8006881C: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80068820: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80068824: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80068828: lhu         $a3, 0x80($t2)
    ctx->r7 = MEM_HU(ctx->r10, 0X80);
    // 0x8006882C: jal         0x80068714
    // 0x80068830: nop

    func_80068714(rdram, ctx);
        goto after_2;
    // 0x80068830: nop

    after_2:
    // 0x80068834: b           L_80068868
    // 0x80068838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80068868;
    // 0x80068838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006883C:
    // 0x8006883C: addiu       $t3, $t3, -0x494
    ctx->r11 = ADD32(ctx->r11, -0X494);
    // 0x80068840: bne         $v1, $t3, L_80068864
    if (ctx->r3 != ctx->r11) {
        // 0x80068844: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80068864;
    }
    // 0x80068844: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80068848: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8006884C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80068850: lhu         $a3, 0x80($t4)
    ctx->r7 = MEM_HU(ctx->r12, 0X80);
    // 0x80068854: jal         0x80068714
    // 0x80068858: nop

    func_80068714(rdram, ctx);
        goto after_3;
    // 0x80068858: nop

    after_3:
    // 0x8006885C: b           L_80068868
    // 0x80068860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80068868;
    // 0x80068860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80068864:
    // 0x80068864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80068868:
    // 0x80068868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006886C: jr          $ra
    // 0x80068870: nop

    return;
    // 0x80068870: nop

    // 0x80068874: nop

    // 0x80068878: nop

    // 0x8006887C: nop

;}
RECOMP_FUNC void func_80068880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068880: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80068884: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80068888: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8006888C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80068890: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x80068894: lbu         $t9, -0x153F($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X153F);
    // 0x80068898: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x8006889C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800688A0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800688A4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800688A8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800688AC: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x800688B0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800688B4: lw          $t3, 0x5B34($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5B34);
    // 0x800688B8: nop

    // 0x800688BC: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800688C0: mflo        $t4
    ctx->r12 = lo;
    // 0x800688C4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800688C8: sra         $t6, $t4, 8
    ctx->r14 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800688CC: jr          $ra
    // 0x800688D0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x800688D0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800688D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800688D4: lb          $t0, 0x3($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X3);
    // 0x800688D8: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x800688DC: slti        $at, $t0, -0x1E
    ctx->r1 = SIGNED(ctx->r8) < -0X1E ? 1 : 0;
    // 0x800688E0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800688E4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x800688E8: beq         $at, $zero, L_80068958
    if (ctx->r1 == 0) {
        // 0x800688EC: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_80068958;
    }
    // 0x800688EC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800688F0: addiu       $t8, $zero, -0x1E
    ctx->r24 = ADD32(0, -0X1E);
    // 0x800688F4: subu        $a3, $t8, $t0
    ctx->r7 = SUB32(ctx->r24, ctx->r8);
    // 0x800688F8: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x800688FC: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x80068900: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x80068904: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80068908: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x8006890C: ori         $t2, $t2, 0x2001
    ctx->r10 = ctx->r10 | 0X2001;
    // 0x80068910: ori         $t7, $t6, 0x400
    ctx->r15 = ctx->r14 | 0X400;
    // 0x80068914: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80068918: bne         $t1, $zero, L_80068924
    if (ctx->r9 != 0) {
        // 0x8006891C: nop
    
            goto L_80068924;
    }
    // 0x8006891C: nop

    // 0x80068920: break       7
    do_break(2147911968);
L_80068924:
    // 0x80068924: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80068928: bne         $t1, $at, L_8006893C
    if (ctx->r9 != ctx->r1) {
        // 0x8006892C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006893C;
    }
    // 0x8006892C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068930: bne         $t9, $at, L_8006893C
    if (ctx->r25 != ctx->r1) {
        // 0x80068934: nop
    
            goto L_8006893C;
    }
    // 0x80068934: nop

    // 0x80068938: break       6
    do_break(2147911992);
L_8006893C:
    // 0x8006893C: mflo        $a3
    ctx->r7 = lo;
    // 0x80068940: slt         $at, $a3, $t2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80068944: bne         $at, $zero, L_800689C0
    if (ctx->r1 != 0) {
        // 0x80068948: nop
    
            goto L_800689C0;
    }
    // 0x80068948: nop

    // 0x8006894C: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x80068950: b           L_800689C0
    // 0x80068954: ori         $a3, $a3, 0x2000
    ctx->r7 = ctx->r7 | 0X2000;
        goto L_800689C0;
    // 0x80068954: ori         $a3, $a3, 0x2000
    ctx->r7 = ctx->r7 | 0X2000;
L_80068958:
    // 0x80068958: slti        $at, $t0, 0x1F
    ctx->r1 = SIGNED(ctx->r8) < 0X1F ? 1 : 0;
    // 0x8006895C: bne         $at, $zero, L_800689C0
    if (ctx->r1 != 0) {
        // 0x80068960: addiu       $t1, $zero, 0x28
        ctx->r9 = ADD32(0, 0X28);
            goto L_800689C0;
    }
    // 0x80068960: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x80068964: addiu       $a2, $t0, -0x1E
    ctx->r6 = ADD32(ctx->r8, -0X1E);
    // 0x80068968: sll         $t5, $a2, 16
    ctx->r13 = S32(ctx->r6 << 16);
    // 0x8006896C: div         $zero, $t5, $t1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r9)));
    // 0x80068970: lhu         $t3, 0x0($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X0);
    // 0x80068974: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x80068978: ori         $t2, $t2, 0x2001
    ctx->r10 = ctx->r10 | 0X2001;
    // 0x8006897C: ori         $t4, $t3, 0x800
    ctx->r12 = ctx->r11 | 0X800;
    // 0x80068980: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x80068984: bne         $t1, $zero, L_80068990
    if (ctx->r9 != 0) {
        // 0x80068988: nop
    
            goto L_80068990;
    }
    // 0x80068988: nop

    // 0x8006898C: break       7
    do_break(2147912076);
L_80068990:
    // 0x80068990: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80068994: bne         $t1, $at, L_800689A8
    if (ctx->r9 != ctx->r1) {
        // 0x80068998: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800689A8;
    }
    // 0x80068998: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006899C: bne         $t5, $at, L_800689A8
    if (ctx->r13 != ctx->r1) {
        // 0x800689A0: nop
    
            goto L_800689A8;
    }
    // 0x800689A0: nop

    // 0x800689A4: break       6
    do_break(2147912100);
L_800689A8:
    // 0x800689A8: mflo        $a2
    ctx->r6 = lo;
    // 0x800689AC: slt         $at, $a2, $t2
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800689B0: bne         $at, $zero, L_800689C0
    if (ctx->r1 != 0) {
        // 0x800689B4: nop
    
            goto L_800689C0;
    }
    // 0x800689B4: nop

    // 0x800689B8: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x800689BC: ori         $a2, $a2, 0x2000
    ctx->r6 = ctx->r6 | 0X2000;
L_800689C0:
    // 0x800689C0: lb          $t0, 0x2($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X2);
    // 0x800689C4: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x800689C8: slti        $at, $t0, -0x1E
    ctx->r1 = SIGNED(ctx->r8) < -0X1E ? 1 : 0;
    // 0x800689CC: ori         $t2, $t2, 0x2001
    ctx->r10 = ctx->r10 | 0X2001;
    // 0x800689D0: beq         $at, $zero, L_80068A38
    if (ctx->r1 == 0) {
        // 0x800689D4: addiu       $t1, $zero, 0x28
        ctx->r9 = ADD32(0, 0X28);
            goto L_80068A38;
    }
    // 0x800689D4: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x800689D8: addiu       $t8, $zero, -0x1E
    ctx->r24 = ADD32(0, -0X1E);
    // 0x800689DC: subu        $v0, $t8, $t0
    ctx->r2 = SUB32(ctx->r24, ctx->r8);
    // 0x800689E0: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x800689E4: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x800689E8: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800689EC: nop

    // 0x800689F0: ori         $t7, $t6, 0x200
    ctx->r15 = ctx->r14 | 0X200;
    // 0x800689F4: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x800689F8: bne         $t1, $zero, L_80068A04
    if (ctx->r9 != 0) {
        // 0x800689FC: nop
    
            goto L_80068A04;
    }
    // 0x800689FC: nop

    // 0x80068A00: break       7
    do_break(2147912192);
L_80068A04:
    // 0x80068A04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80068A08: bne         $t1, $at, L_80068A1C
    if (ctx->r9 != ctx->r1) {
        // 0x80068A0C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80068A1C;
    }
    // 0x80068A0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068A10: bne         $t9, $at, L_80068A1C
    if (ctx->r25 != ctx->r1) {
        // 0x80068A14: nop
    
            goto L_80068A1C;
    }
    // 0x80068A14: nop

    // 0x80068A18: break       6
    do_break(2147912216);
L_80068A1C:
    // 0x80068A1C: mflo        $v0
    ctx->r2 = lo;
    // 0x80068A20: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80068A24: bne         $at, $zero, L_80068AA0
    if (ctx->r1 != 0) {
        // 0x80068A28: sll         $t6, $a1, 3
        ctx->r14 = S32(ctx->r5 << 3);
            goto L_80068AA0;
    }
    // 0x80068A28: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x80068A2C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80068A30: b           L_80068A9C
    // 0x80068A34: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
        goto L_80068A9C;
    // 0x80068A34: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
L_80068A38:
    // 0x80068A38: slti        $at, $t0, 0x1F
    ctx->r1 = SIGNED(ctx->r8) < 0X1F ? 1 : 0;
    // 0x80068A3C: bne         $at, $zero, L_80068A9C
    if (ctx->r1 != 0) {
        // 0x80068A40: nop
    
            goto L_80068A9C;
    }
    // 0x80068A40: nop

    // 0x80068A44: addiu       $v1, $t0, -0x1E
    ctx->r3 = ADD32(ctx->r8, -0X1E);
    // 0x80068A48: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x80068A4C: div         $zero, $t5, $t1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r9)));
    // 0x80068A50: lhu         $t3, 0x0($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X0);
    // 0x80068A54: nop

    // 0x80068A58: ori         $t4, $t3, 0x100
    ctx->r12 = ctx->r11 | 0X100;
    // 0x80068A5C: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x80068A60: bne         $t1, $zero, L_80068A6C
    if (ctx->r9 != 0) {
        // 0x80068A64: nop
    
            goto L_80068A6C;
    }
    // 0x80068A64: nop

    // 0x80068A68: break       7
    do_break(2147912296);
L_80068A6C:
    // 0x80068A6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80068A70: bne         $t1, $at, L_80068A84
    if (ctx->r9 != ctx->r1) {
        // 0x80068A74: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80068A84;
    }
    // 0x80068A74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068A78: bne         $t5, $at, L_80068A84
    if (ctx->r13 != ctx->r1) {
        // 0x80068A7C: nop
    
            goto L_80068A84;
    }
    // 0x80068A7C: nop

    // 0x80068A80: break       6
    do_break(2147912320);
L_80068A84:
    // 0x80068A84: mflo        $v1
    ctx->r3 = lo;
    // 0x80068A88: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80068A8C: bne         $at, $zero, L_80068AA0
    if (ctx->r1 != 0) {
        // 0x80068A90: sll         $t6, $a1, 3
        ctx->r14 = S32(ctx->r5 << 3);
            goto L_80068AA0;
    }
    // 0x80068A90: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x80068A94: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80068A98: ori         $v1, $v1, 0x2000
    ctx->r3 = ctx->r3 | 0X2000;
L_80068A9C:
    // 0x80068A9C: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
L_80068AA0:
    // 0x80068AA0: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80068AA4: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80068AA8: addiu       $t7, $t7, 0x5B58
    ctx->r15 = ADD32(ctx->r15, 0X5B58);
    // 0x80068AAC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80068AB0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80068AB4: addu        $t8, $v0, $a2
    ctx->r24 = ADD32(ctx->r2, ctx->r6);
    // 0x80068AB8: addu        $t3, $v0, $a3
    ctx->r11 = ADD32(ctx->r2, ctx->r7);
    // 0x80068ABC: addu        $t5, $v1, $a2
    ctx->r13 = ADD32(ctx->r3, ctx->r6);
    // 0x80068AC0: addu        $t7, $v1, $a3
    ctx->r15 = ADD32(ctx->r3, ctx->r7);
    // 0x80068AC4: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    // 0x80068AC8: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    // 0x80068ACC: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
    // 0x80068AD0: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x80068AD4: bgez        $t8, L_80068AE4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80068AD8: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_80068AE4;
    }
    // 0x80068AD8: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80068ADC: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x80068AE0: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80068AE4:
    // 0x80068AE4: sw          $t9, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r25;
    // 0x80068AE8: bgez        $t3, L_80068AF8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80068AEC: sra         $t4, $t3, 1
        ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
            goto L_80068AF8;
    }
    // 0x80068AEC: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80068AF0: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x80068AF4: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_80068AF8:
    // 0x80068AF8: sw          $t4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r12;
    // 0x80068AFC: bgez        $t5, L_80068B0C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80068B00: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_80068B0C;
    }
    // 0x80068B00: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80068B04: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x80068B08: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_80068B0C:
    // 0x80068B0C: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x80068B10: bgez        $t7, L_80068B20
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80068B14: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_80068B20;
    }
    // 0x80068B14: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80068B18: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x80068B1C: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80068B20:
    // 0x80068B20: jr          $ra
    // 0x80068B24: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    return;
    // 0x80068B24: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80068B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068B28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068B30: jal         0x80060418
    // 0x80068B34: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    func_80060418(rdram, ctx);
        goto after_0;
    // 0x80068B34: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    after_0:
    // 0x80068B38: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80068B3C: addiu       $v1, $v1, 0x5B54
    ctx->r3 = ADD32(ctx->r3, 0X5B54);
    // 0x80068B40: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80068B44: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80068B48: jal         0x800688D4
    // 0x80068B4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800688D4(rdram, ctx);
        goto after_1;
    // 0x80068B4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80068B50: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80068B54: lw          $t7, 0x5B54($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5B54);
    // 0x80068B58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80068B5C: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x80068B60: jal         0x800688D4
    // 0x80068B64: nop

    func_800688D4(rdram, ctx);
        goto after_2;
    // 0x80068B64: nop

    after_2:
    // 0x80068B68: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80068B6C: lw          $t8, 0x5B54($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5B54);
    // 0x80068B70: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80068B74: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    // 0x80068B78: jal         0x800688D4
    // 0x80068B7C: nop

    func_800688D4(rdram, ctx);
        goto after_3;
    // 0x80068B7C: nop

    after_3:
    // 0x80068B80: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80068B84: lw          $v0, 0x5B54($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5B54);
    // 0x80068B88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80068B8C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80068B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068B94: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80068B98: nop

    // 0x80068B9C: sw          $t0, -0x3B98($at)
    MEM_W(-0X3B98, ctx->r1) = ctx->r8;
    // 0x80068BA0: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80068BA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80068BA8: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80068BAC: nop

    // 0x80068BB0: sw          $t2, -0x3B94($at)
    MEM_W(-0X3B94, ctx->r1) = ctx->r10;
    // 0x80068BB4: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80068BB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80068BBC: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80068BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068BC4: jr          $ra
    // 0x80068BC8: sw          $t4, -0x3B90($at)
    MEM_W(-0X3B90, ctx->r1) = ctx->r12;
    return;
    // 0x80068BC8: sw          $t4, -0x3B90($at)
    MEM_W(-0X3B90, ctx->r1) = ctx->r12;
;}
RECOMP_FUNC void func_80068BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068BCC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80068BD0: lw          $a0, 0x5B54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5B54);
    // 0x80068BD4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80068BD8: ori         $a2, $zero, 0xA219
    ctx->r6 = 0 | 0XA219;
    // 0x80068BDC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_80068BE0:
    // 0x80068BE0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80068BE4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80068BE8: beq         $v0, $zero, L_80068C0C
    if (ctx->r2 == 0) {
        // 0x80068BEC: nop
    
            goto L_80068C0C;
    }
    // 0x80068BEC: nop

    // 0x80068BF0: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x80068BF4: nop

    // 0x80068BF8: andi        $t7, $t6, 0xA219
    ctx->r15 = ctx->r14 & 0XA219;
    // 0x80068BFC: bne         $a2, $t7, L_80068C0C
    if (ctx->r6 != ctx->r15) {
        // 0x80068C00: nop
    
            goto L_80068C0C;
    }
    // 0x80068C00: nop

    // 0x80068C04: jr          $ra
    // 0x80068C08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80068C08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80068C0C:
    // 0x80068C0C: bne         $v1, $a1, L_80068BE0
    if (ctx->r3 != ctx->r5) {
        // 0x80068C10: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80068BE0;
    }
    // 0x80068C10: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80068C14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80068C18: jr          $ra
    // 0x80068C1C: nop

    return;
    // 0x80068C1C: nop

;}
RECOMP_FUNC void func_80068C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068C20: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80068C24: lw          $t6, 0x5B54($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5B54);
    // 0x80068C28: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80068C2C: lw          $v0, 0xC($t6)
    ctx->r2 = MEM_W(ctx->r14, 0XC);
    // 0x80068C30: nop

    // 0x80068C34: beq         $v0, $zero, L_80068C78
    if (ctx->r2 == 0) {
        // 0x80068C38: nop
    
            goto L_80068C78;
    }
    // 0x80068C38: nop

    // 0x80068C3C: lw          $t8, 0x5BCC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5BCC);
    // 0x80068C40: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x80068C44: nor         $t9, $t8, $zero
    ctx->r25 = ~(ctx->r24 | 0);
    // 0x80068C48: and         $v1, $t7, $t9
    ctx->r3 = ctx->r15 & ctx->r25;
    // 0x80068C4C: andi        $t0, $v1, 0x4000
    ctx->r8 = ctx->r3 & 0X4000;
    // 0x80068C50: beq         $t0, $zero, L_80068C68
    if (ctx->r8 == 0) {
        // 0x80068C54: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_80068C68;
    }
    // 0x80068C54: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80068C58: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80068C5C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80068C60: b           L_80068C6C
    // 0x80068C64: sh          $t1, 0x5BC8($at)
    MEM_H(0X5BC8, ctx->r1) = ctx->r9;
        goto L_80068C6C;
    // 0x80068C64: sh          $t1, 0x5BC8($at)
    MEM_H(0X5BC8, ctx->r1) = ctx->r9;
L_80068C68:
    // 0x80068C68: sh          $zero, 0x5BC8($at)
    MEM_H(0X5BC8, ctx->r1) = 0;
L_80068C6C:
    // 0x80068C6C: lhu         $t2, 0x0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X0);
    // 0x80068C70: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80068C74: sw          $t2, 0x5BCC($at)
    MEM_W(0X5BCC, ctx->r1) = ctx->r10;
L_80068C78:
    // 0x80068C78: jr          $ra
    // 0x80068C7C: nop

    return;
    // 0x80068C7C: nop

;}
RECOMP_FUNC void func_80068C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068C80: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80068C84: lw          $t8, 0x5B54($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5B54);
    // 0x80068C88: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80068C8C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80068C90: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80068C94: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80068C98: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x80068C9C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80068CA0: andi        $t7, $a1, 0xFFFF
    ctx->r15 = ctx->r5 & 0XFFFF;
    // 0x80068CA4: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x80068CA8: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80068CAC: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x80068CB0: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x80068CB4: lw          $a2, 0x5C50($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5C50);
    // 0x80068CB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80068CBC: beq         $t1, $zero, L_80068D04
    if (ctx->r9 == 0) {
        // 0x80068CC0: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80068D04;
    }
    // 0x80068CC0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80068CC4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80068CC8: andi        $t4, $t1, 0x1
    ctx->r12 = ctx->r9 & 0X1;
L_80068CCC:
    // 0x80068CCC: beq         $t4, $zero, L_80068CF0
    if (ctx->r12 == 0) {
        // 0x80068CD0: srl         $v1, $t1, 1
        ctx->r3 = S32(U32(ctx->r9) >> 1);
            goto L_80068CF0;
    }
    // 0x80068CD0: srl         $v1, $t1, 1
    ctx->r3 = S32(U32(ctx->r9) >> 1);
    // 0x80068CD4: sll         $t5, $t0, 1
    ctx->r13 = S32(ctx->r8 << 1);
    // 0x80068CD8: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x80068CDC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80068CE0: nop

    // 0x80068CE4: or          $a3, $a3, $t7
    ctx->r7 = ctx->r7 | ctx->r15;
    // 0x80068CE8: andi        $t8, $a3, 0xFFFF
    ctx->r24 = ctx->r7 & 0XFFFF;
    // 0x80068CEC: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
L_80068CF0:
    // 0x80068CF0: andi        $t1, $v1, 0xFFFF
    ctx->r9 = ctx->r3 & 0XFFFF;
    // 0x80068CF4: beq         $t1, $zero, L_80068D04
    if (ctx->r9 == 0) {
        // 0x80068CF8: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80068D04;
    }
    // 0x80068CF8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80068CFC: bne         $t0, $v0, L_80068CCC
    if (ctx->r8 != ctx->r2) {
        // 0x80068D00: andi        $t4, $t1, 0x1
        ctx->r12 = ctx->r9 & 0X1;
            goto L_80068CCC;
    }
    // 0x80068D00: andi        $t4, $t1, 0x1
    ctx->r12 = ctx->r9 & 0X1;
L_80068D04:
    // 0x80068D04: jr          $ra
    // 0x80068D08: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x80068D08: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
;}
RECOMP_FUNC void func_80068D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068D0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80068D10: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80068D14: lw          $t6, 0x5B50($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5B50);
    // 0x80068D18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068D1C: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
    // 0x80068D20: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    {
        // FIX: Force button mapping tables every frame.
        // The game's init code clears the gameplay tables (map1-3) during state transitions,
        // so a one-shot fix gets overwritten. Cheap to re-apply every frame.
        {
            gpr base = S32(0X8008 << 16); // 0x80080000
            // MEM_W upper half = entry at even offset, lower half = entry at odd offset (XOR 2 addressing)
            // map0 at 0x80085BD0 (menu mapping): entries 8-15
            MEM_W(0x5BE0, base) = 0x00080004; MEM_W(0x5BE4, base) = 0x00020001;
            MEM_W(0x5BE8, base) = 0x01000020; MEM_W(0x5BEC, base) = 0x00400010;
            // map1 at 0x80085BF0 (player 0): entry 2=0020, entries 8-15
            MEM_W(0x5BF4, base) = 0x00200000;
            MEM_W(0x5C00, base) = 0x00080004; MEM_W(0x5C04, base) = 0x00020001;
            MEM_W(0x5C08, base) = 0x01000000; MEM_W(0x5C0C, base) = 0x00100040;
            // map2 at 0x80085C10 (player 1): same layout as map1
            MEM_W(0x5C14, base) = 0x00200000;
            MEM_W(0x5C20, base) = 0x00080004; MEM_W(0x5C24, base) = 0x00020001;
            MEM_W(0x5C28, base) = 0x01000000; MEM_W(0x5C2C, base) = 0x00100040;
            // map3 at 0x80085C30 (player 2): same layout as map1
            MEM_W(0x5C34, base) = 0x00200000;
            MEM_W(0x5C40, base) = 0x00080004; MEM_W(0x5C44, base) = 0x00020001;
            MEM_W(0x5C48, base) = 0x01000000; MEM_W(0x5C4C, base) = 0x00100040;
        }
    }
    // 0x80068D24: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80068D28: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80068D2C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80068D30: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80068D34: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80068D38: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80068D3C: bne         $t6, $zero, L_80068DD8
    if (ctx->r14 != 0) {
        // 0x80068D40: sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
            goto L_80068DD8;
    }
    // 0x80068D40: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80068D44: jal         0x80068B28
    // 0x80068D48: nop

    func_80068B28(rdram, ctx);
        goto after_0;
    // 0x80068D48: nop

    after_0:
    // 0x80068D4C: jal         0x80068C20
    // 0x80068D50: nop

    func_80068C20(rdram, ctx);
        goto after_1;
    // 0x80068D50: nop

    after_1:
    // 0x80068D54: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x80068D58: addiu       $s3, $s3, -0x1524
    ctx->r19 = ADD32(ctx->r19, -0X1524);
    // 0x80068D5C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80068D60: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80068D64: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80068D68: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x80068D6C: sw          $t7, -0x1280($at)
    MEM_W(-0X1280, ctx->r1) = ctx->r15;
    // 0x80068D70: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x80068D74: addiu       $s5, $s5, -0x818
    ctx->r21 = ADD32(ctx->r21, -0X818);
    // 0x80068D78: addiu       $s2, $s2, -0x4B70
    ctx->r18 = ADD32(ctx->r18, -0X4B70);
    // 0x80068D7C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80068D80: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x80068D84: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
L_80068D88:
    // 0x80068D88: beq         $s4, $zero, L_80068DA8
    if (ctx->r20 == 0) {
        // 0x80068D8C: andi        $a0, $s1, 0xFFFF
        ctx->r4 = ctx->r17 & 0XFFFF;
            goto L_80068DA8;
    }
    // 0x80068D8C: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80068D90: lhu         $t8, 0x68($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X68);
    // FIX: Force player 0 as "active" during gameplay so per-player button mapping is used.
    if ((ctx->r17 & 0xFFFF) == 0) {
        ctx->r24 = 0;
    }
    // 0x80068D94: addiu       $s0, $s1, 0x1
    ctx->r16 = ADD32(ctx->r17, 0X1);
    // 0x80068D98: bne         $t8, $zero, L_80068DAC
    if (ctx->r24 != 0) {
        // 0x80068D9C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80068DAC;
    }
    // 0x80068D9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80068DA0: b           L_80068DB0
    // 0x80068DA4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80068DB0;
    // 0x80068DA4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80068DA8:
    // 0x80068DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80068DAC:
    // 0x80068DAC: addiu       $s0, $s1, 0x1
    ctx->r16 = ADD32(ctx->r17, 0X1);
L_80068DB0:
    // 0x80068DB0: jal         0x80068C80
    // 0x80068DB4: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    func_80068C80(rdram, ctx);
        goto after_2;
    // 0x80068DB4: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x80068DB8: lhu         $t0, 0x0($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X0);
    // 0x80068DBC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80068DC0: sllv        $t1, $v0, $t0
    ctx->r9 = S32(ctx->r2 << (ctx->r8 & 31));
    // 0x80068DC4: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80068DC8: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80068DCC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80068DD0: bne         $s0, $s6, L_80068D88
    if (ctx->r16 != ctx->r22) {
        // 0x80068DD4: sw          $t2, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r10;
            goto L_80068D88;
    }
    // 0x80068DD4: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
L_80068DD8:
    // 0x80068DD8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80068DDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068DE0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80068DE4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80068DE8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80068DEC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80068DF0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80068DF4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80068DF8: jr          $ra
    // 0x80068DFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80068DFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80068E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068E00: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80068E04: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80068E08: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80068E0C: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x80068E10: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80068E14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80068E18: addiu       $a2, $a2, -0x1568
    ctx->r6 = ADD32(ctx->r6, -0X1568);
    // 0x80068E1C: addiu       $a3, $a3, -0x1548
    ctx->r7 = ADD32(ctx->r7, -0X1548);
    // 0x80068E20: addiu       $t0, $t0, 0x2880
    ctx->r8 = ADD32(ctx->r8, 0X2880);
    // 0x80068E24: addiu       $a1, $a1, 0x288C
    ctx->r5 = ADD32(ctx->r5, 0X288C);
    // 0x80068E28: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80068E2C:
    // 0x80068E2C: lbu         $t6, 0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3);
    // 0x80068E30: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80068E34: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80068E38: beq         $t7, $zero, L_80068E5C
    if (ctx->r15 == 0) {
        // 0x80068E3C: sltu        $at, $a1, $t0
        ctx->r1 = ctx->r5 < ctx->r8 ? 1 : 0;
            goto L_80068E5C;
    }
    // 0x80068E3C: sltu        $at, $a1, $t0
    ctx->r1 = ctx->r5 < ctx->r8 ? 1 : 0;
    // 0x80068E40: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x80068E44: addu        $t8, $a2, $a0
    ctx->r24 = ADD32(ctx->r6, ctx->r4);
    // 0x80068E48: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
    // 0x80068E4C: addu        $t9, $a3, $a0
    ctx->r25 = ADD32(ctx->r7, ctx->r4);
    // 0x80068E50: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
    // 0x80068E54: b           L_80068E74
    // 0x80068E58: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80068E74;
    // 0x80068E58: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80068E5C:
    // 0x80068E5C: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    // 0x80068E60: addu        $t2, $a2, $a0
    ctx->r10 = ADD32(ctx->r6, ctx->r4);
    // 0x80068E64: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x80068E68: addu        $t3, $a3, $a0
    ctx->r11 = ADD32(ctx->r7, ctx->r4);
    // 0x80068E6C: sh          $t1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r9;
    // 0x80068E70: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80068E74:
    // 0x80068E74: beq         $at, $zero, L_80068E2C
    if (ctx->r1 == 0) {
        // 0x80068E78: nop
    
            goto L_80068E2C;
    }
    // 0x80068E78: nop

    // 0x80068E7C: jr          $ra
    // 0x80068E80: nop

    return;
    // 0x80068E80: nop

    // 0x80068E84: nop

    // 0x80068E88: nop

    // 0x80068E8C: nop

;}
RECOMP_FUNC void func_80068E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068E90: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80068E94: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80068E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068E9C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80068EA0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80068EA4: addiu       $t6, $t6, 0x5C80
    ctx->r14 = ADD32(ctx->r14, 0X5C80);
    // 0x80068EA8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80068EAC: addiu       $t0, $sp, 0x1C
    ctx->r8 = ADD32(ctx->r29, 0X1C);
    // 0x80068EB0: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80068EB4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80068EB8: nop

    // 0x80068EBC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80068EC0: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80068EC4: nop

    // 0x80068EC8: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x80068ECC: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x80068ED0: beq         $a0, $zero, L_80068F64
    if (ctx->r4 == 0) {
        // 0x80068ED4: sw          $t9, 0xC($t0)
        MEM_W(0XC, ctx->r8) = ctx->r25;
            goto L_80068F64;
    }
    // 0x80068ED4: sw          $t9, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r25;
    // 0x80068ED8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80068EDC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80068EE0: beq         $t1, $zero, L_80068F68
    if (ctx->r9 == 0) {
        // 0x80068EE4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80068F68;
    }
    // 0x80068EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068EE8: beq         $t2, $zero, L_80068F64
    if (ctx->r10 == 0) {
        // 0x80068EEC: lui         $v0, 0x800C
        ctx->r2 = S32(0X800C << 16);
            goto L_80068F64;
    }
    // 0x80068EEC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80068EF0: lhu         $v0, -0x87A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X87A);
    // 0x80068EF4: addiu       $at, $zero, 0x150
    ctx->r1 = ADD32(0, 0X150);
    // 0x80068EF8: beq         $v0, $at, L_80068F0C
    if (ctx->r2 == ctx->r1) {
        // 0x80068EFC: lui         $t3, 0x800C
        ctx->r11 = S32(0X800C << 16);
            goto L_80068F0C;
    }
    // 0x80068EFC: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80068F00: addiu       $at, $zero, 0x240
    ctx->r1 = ADD32(0, 0X240);
    // 0x80068F04: bne         $v0, $at, L_80068F68
    if (ctx->r2 != ctx->r1) {
        // 0x80068F08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80068F68;
    }
    // 0x80068F08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80068F0C:
    // 0x80068F0C: lhu         $t3, -0x182($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X182);
    // 0x80068F10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80068F14: beq         $t3, $at, L_80068F68
    if (ctx->r11 == ctx->r1) {
        // 0x80068F18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80068F68;
    }
    // 0x80068F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068F1C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80068F20: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80068F24: beq         $v0, $zero, L_80068F64
    if (ctx->r2 == 0) {
        // 0x80068F28: addu        $v1, $v1, $v0
        ctx->r3 = ADD32(ctx->r3, ctx->r2);
            goto L_80068F64;
    }
    // 0x80068F28: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80068F2C: lbu         $v1, -0x153F($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X153F);
    // 0x80068F30: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80068F34: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80068F38: bltz        $v1, L_80068F64
    if (SIGNED(ctx->r3) < 0) {
        // 0x80068F3C: sll         $t4, $v1, 2
        ctx->r12 = S32(ctx->r3 << 2);
            goto L_80068F64;
    }
    // 0x80068F3C: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80068F40: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80068F44: lw          $t5, 0x28B8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X28B8);
    // 0x80068F48: lbu         $a1, 0x37($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X37);
    // 0x80068F4C: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80068F50: addu        $t7, $t0, $t8
    ctx->r15 = ADD32(ctx->r8, ctx->r24);
    // 0x80068F54: lbu         $a0, 0x3($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X3);
    // 0x80068F58: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    // 0x80068F5C: jal         0x80063A60
    // 0x80068F60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80063A60(rdram, ctx);
        goto after_0;
    // 0x80068F60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
L_80068F64:
    // 0x80068F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80068F68:
    // 0x80068F68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80068F6C: jr          $ra
    // 0x80068F70: nop

    return;
    // 0x80068F70: nop

;}
RECOMP_FUNC void func_80068F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068F74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068F7C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80068F80: jal         0x80068E90
    // 0x80068F84: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80068E90(rdram, ctx);
        goto after_0;
    // 0x80068F84: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_0:
    // 0x80068F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068F90: jr          $ra
    // 0x80068F94: nop

    return;
    // 0x80068F94: nop

;}
RECOMP_FUNC void func_80068F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068F98: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // FALLTHROUGH FIX: func_80068F98 falls through to func_80068F9C
    func_80068F9C(rdram, ctx);
;}
RECOMP_FUNC void func_80068F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068F9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068FA0: addiu       $t7, $t7, 0x5C60
    ctx->r15 = ADD32(ctx->r15, 0X5C60);
    // 0x80068FA4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80068FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068FAC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80068FB0: lhu         $t8, 0xF0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XF0);
    // 0x80068FB4: lh          $a3, 0x0($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X0);
    // 0x80068FB8: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80068FBC: beq         $t8, $zero, L_80069008
    if (ctx->r24 == 0) {
        // 0x80068FC0: nop
    
            goto L_80069008;
    }
    // 0x80068FC0: nop

    // 0x80068FC4: beq         $v0, $t7, L_80068FEC
    if (ctx->r2 == ctx->r15) {
        // 0x80068FC8: lui         $t9, 0x8008
        ctx->r25 = S32(0X8008 << 16);
            goto L_80068FEC;
    }
    // 0x80068FC8: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80068FCC: addiu       $t9, $t9, 0x5C64
    ctx->r25 = ADD32(ctx->r25, 0X5C64);
    // 0x80068FD0: beq         $v0, $t9, L_80068FEC
    if (ctx->r2 == ctx->r25) {
        // 0x80068FD4: lui         $t0, 0x8008
        ctx->r8 = S32(0X8008 << 16);
            goto L_80068FEC;
    }
    // 0x80068FD4: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80068FD8: addiu       $t0, $t0, 0x5C68
    ctx->r8 = ADD32(ctx->r8, 0X5C68);
    // 0x80068FDC: beq         $v0, $t0, L_80068FEC
    if (ctx->r2 == ctx->r8) {
        // 0x80068FE0: lui         $t1, 0x8008
        ctx->r9 = S32(0X8008 << 16);
            goto L_80068FEC;
    }
    // 0x80068FE0: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80068FE4: addiu       $t1, $t1, 0x5C6C
    ctx->r9 = ADD32(ctx->r9, 0X5C6C);
    // 0x80068FE8: bne         $v0, $t1, L_80069008
    if (ctx->r2 != ctx->r9) {
        // 0x80068FEC: sll         $t2, $a3, 1
        ctx->r10 = S32(ctx->r7 << 1);
            goto L_80069008;
    }
L_80068FEC:
    // 0x80068FEC: sll         $t2, $a3, 1
    ctx->r10 = S32(ctx->r7 << 1);
    // 0x80068FF0: slti        $at, $t2, 0x41
    ctx->r1 = SIGNED(ctx->r10) < 0X41 ? 1 : 0;
    // 0x80068FF4: bne         $at, $zero, L_80069000
    if (ctx->r1 != 0) {
        // 0x80068FF8: or          $a3, $t2, $zero
        ctx->r7 = ctx->r10 | 0;
            goto L_80069000;
    }
    // 0x80068FF8: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x80068FFC: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
L_80069000:
    // 0x80069000: sll         $t3, $a2, 1
    ctx->r11 = S32(ctx->r6 << 1);
    // 0x80069004: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
L_80069008:
    // 0x80069008: jal         0x80068E90
    // 0x8006900C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80068E90(rdram, ctx);
        goto after_0;
    // 0x8006900C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80069010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069018: jr          $ra
    // 0x8006901C: nop

    return;
    // 0x8006901C: nop

;}
RECOMP_FUNC void func_80069020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069020: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80069024: addiu       $t7, $t7, 0x5C60
    ctx->r15 = ADD32(ctx->r15, 0X5C60);
    // 0x80069028: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8006902C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80069030: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80069034: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // FALLTHROUGH FIX: func_80069020 falls through to func_80069038
    func_80069038(rdram, ctx);
;}
RECOMP_FUNC void func_80069038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006903C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069040: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80069044: addiu       $a0, $a0, -0x798
    ctx->r4 = ADD32(ctx->r4, -0X798);
    // 0x80069048: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006904C: jal         0x80068E90
    // 0x80069050: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80068E90(rdram, ctx);
        goto after_0;
    // 0x80069050: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80069054: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80069058: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006905C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80069060: jal         0x80068E90
    // 0x80069064: addiu       $a0, $a0, -0x5CC
    ctx->r4 = ADD32(ctx->r4, -0X5CC);
    func_80068E90(rdram, ctx);
        goto after_1;
    // 0x80069064: addiu       $a0, $a0, -0x5CC
    ctx->r4 = ADD32(ctx->r4, -0X5CC);
    after_1:
    // 0x80069068: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8006906C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80069070: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80069074: jal         0x80068E90
    // 0x80069078: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    func_80068E90(rdram, ctx);
        goto after_2;
    // 0x80069078: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    after_2:
    // 0x8006907C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069080: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80069084: jr          $ra
    // 0x80069088: nop

    return;
    // 0x80069088: nop

;}
RECOMP_FUNC void func_8006908C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006908C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069094: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80069098: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006909C: beq         $v0, $zero, L_80069114
    if (ctx->r2 == 0) {
        // 0x800690A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069114;
    }
    // 0x800690A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800690A4: lhu         $t6, 0x13C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X13C);
    // 0x800690A8: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x800690AC: beq         $t6, $zero, L_800690BC
    if (ctx->r14 == 0) {
        // 0x800690B0: nop
    
            goto L_800690BC;
    }
    // 0x800690B0: nop

    // 0x800690B4: b           L_800690BC
    // 0x800690B8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_800690BC;
    // 0x800690B8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_800690BC:
    // 0x800690BC: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800690C0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800690C4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800690C8: addiu       $v0, $v0, 0x5C90
    ctx->r2 = ADD32(ctx->r2, 0X5C90);
    // 0x800690CC: addiu       $a0, $a0, 0x5D28
    ctx->r4 = ADD32(ctx->r4, 0X5D28);
L_800690D0:
    // 0x800690D0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800690D4: nop

    // 0x800690D8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800690DC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800690E0: nop

    // 0x800690E4: bne         $a1, $t9, L_80069104
    if (ctx->r5 != ctx->r25) {
        // 0x800690E8: nop
    
            goto L_80069104;
    }
    // 0x800690E8: nop

    // 0x800690EC: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x800690F0: lh          $a2, 0x6($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X6);
    // 0x800690F4: jal         0x80068E90
    // 0x800690F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80068E90(rdram, ctx);
        goto after_0;
    // 0x800690F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800690FC: b           L_80069114
    // 0x80069100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80069114;
    // 0x80069100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069104:
    // 0x80069104: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80069108: bne         $v0, $a0, L_800690D0
    if (ctx->r2 != ctx->r4) {
        // 0x8006910C: nop
    
            goto L_800690D0;
    }
    // 0x8006910C: nop

    // 0x80069110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069114:
    // 0x80069114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069118: jr          $ra
    // 0x8006911C: nop

    return;
    // 0x8006911C: nop

;}
RECOMP_FUNC void func_80069A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069A80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069A84: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80069A88: addiu       $t6, $t6, 0x4EF0
    ctx->r14 = ADD32(ctx->r14, 0X4EF0);
    // 0x80069A8C: sb          $zero, 0x7($sp)
    MEM_B(0X7, ctx->r29) = 0;
    // 0x80069A90: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80069A94: blez        $t7, L_80069B38
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80069A98: sw          $zero, 0x8($sp)
        MEM_W(0X8, ctx->r29) = 0;
            goto L_80069B38;
    }
    // 0x80069A98: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
L_80069A9C:
    // 0x80069A9C: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80069AA0: addiu       $t8, $sp, 0xC
    ctx->r24 = ADD32(ctx->r29, 0XC);
    // 0x80069AA4: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x80069AA8: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x80069AAC: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80069AB0: lwl         $t1, 0x4($t9)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r25, 0X4);
    // 0x80069AB4: lwr         $t1, 0x7($t9)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r25, 0X7);
    // 0x80069AB8: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x80069ABC: lbu         $t2, 0xE($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XE);
    // 0x80069AC0: andi        $t3, $t2, 0xC0
    ctx->r11 = ctx->r10 & 0XC0;
    // 0x80069AC4: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80069AC8: sb          $t4, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r12;
    // 0x80069ACC: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x80069AD0: bne         $t5, $zero, L_80069B0C
    if (ctx->r13 != 0) {
        // 0x80069AD4: nop
    
            goto L_80069B0C;
    }
    // 0x80069AD4: nop

    // 0x80069AD8: lbu         $t6, 0x11($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X11);
    // 0x80069ADC: lbu         $t0, 0x10($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X10);
    // 0x80069AE0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80069AE4: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80069AE8: or          $t8, $t7, $t0
    ctx->r24 = ctx->r15 | ctx->r8;
    // 0x80069AEC: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80069AF0: lbu         $t9, 0x12($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X12);
    // 0x80069AF4: sb          $t9, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r25;
    // 0x80069AF8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x80069AFC: lbu         $t1, 0x7($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X7);
    // 0x80069B00: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x80069B04: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x80069B08: sb          $t5, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r13;
L_80069B0C:
    // 0x80069B0C: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x80069B10: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80069B14: lbu         $t9, 0x4F31($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4F31);
    // 0x80069B18: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x80069B1C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80069B20: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80069B24: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80069B28: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80069B2C: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80069B30: bne         $at, $zero, L_80069A9C
    if (ctx->r1 != 0) {
        // 0x80069B34: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80069A9C;
    }
    // 0x80069B34: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80069B38:
    // 0x80069B38: lbu         $t3, 0x7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X7);
    // 0x80069B3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069B40: jr          $ra
    // 0x80069B44: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    return;
    // 0x80069B44: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
;}
RECOMP_FUNC void func_80069F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069F00: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80069F04: addiu       $t6, $t6, 0x4EF0
    ctx->r14 = ADD32(ctx->r14, 0X4EF0);
    // 0x80069F08: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x80069F0C: blez        $t7, L_80069F94
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80069F10: sw          $zero, 0x0($sp)
        MEM_W(0X0, ctx->r29) = 0;
            goto L_80069F94;
    }
    // 0x80069F10: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_80069F14:
    // 0x80069F14: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x80069F18: addiu       $t8, $sp, 0x4
    ctx->r24 = ADD32(ctx->r29, 0X4);
    // 0x80069F1C: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x80069F20: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x80069F24: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80069F28: lwl         $t1, 0x4($t9)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r25, 0X4);
    // 0x80069F2C: lwr         $t1, 0x7($t9)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r25, 0X7);
    // 0x80069F30: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x80069F34: lbu         $t2, 0x6($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X6);
    // 0x80069F38: andi        $t3, $t2, 0xC0
    ctx->r11 = ctx->r10 & 0XC0;
    // 0x80069F3C: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80069F40: sb          $t4, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r12;
    // 0x80069F44: lbu         $t5, 0x4($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X4);
    // 0x80069F48: bne         $t5, $zero, L_80069F68
    if (ctx->r13 != 0) {
        // 0x80069F4C: nop
    
            goto L_80069F68;
    }
    // 0x80069F4C: nop

    // 0x80069F50: lhu         $t6, 0x8($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X8);
    // 0x80069F54: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x80069F58: lb          $t7, 0xA($sp)
    ctx->r15 = MEM_B(ctx->r29, 0XA);
    // 0x80069F5C: sb          $t7, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r15;
    // 0x80069F60: lb          $t0, 0xB($sp)
    ctx->r8 = MEM_B(ctx->r29, 0XB);
    // 0x80069F64: sb          $t0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r8;
L_80069F68:
    // 0x80069F68: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x80069F6C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80069F70: lbu         $t3, 0x4F31($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4F31);
    // 0x80069F74: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x80069F78: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80069F7C: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80069F80: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80069F84: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x80069F88: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x80069F8C: bne         $at, $zero, L_80069F14
    if (ctx->r1 != 0) {
        // 0x80069F90: addiu       $a0, $a0, 0x6
        ctx->r4 = ADD32(ctx->r4, 0X6);
            goto L_80069F14;
    }
    // 0x80069F90: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
L_80069F94:
    // 0x80069F94: jr          $ra
    // 0x80069F98: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80069F98: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80069F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069F9C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80069FA0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80069FA4: addiu       $t6, $t6, 0x4EF0
    ctx->r14 = ADD32(ctx->r14, 0X4EF0);
    // 0x80069FA8: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x80069FAC: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_80069FB0:
    // 0x80069FB0: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80069FB4: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80069FB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80069FBC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80069FC0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80069FC4: sw          $zero, 0x4EF0($at)
    MEM_W(0X4EF0, ctx->r1) = 0;
    // 0x80069FC8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80069FCC: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x80069FD0: bne         $at, $zero, L_80069FB0
    if (ctx->r1 != 0) {
        // 0x80069FD4: sw          $t0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r8;
            goto L_80069FB0;
    }
    // 0x80069FD4: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x80069FD8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80069FDC: lbu         $t9, 0x4F31($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4F31);
    // 0x80069FE0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80069FE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80069FE8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80069FEC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80069FF0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80069FF4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80069FF8: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80069FFC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8006A000: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8006A004: sw          $t1, 0x4F2C($at)
    MEM_W(0X4F2C, ctx->r1) = ctx->r9;
    // 0x8006A008: sb          $t2, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r10;
    // 0x8006A00C: sb          $t3, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r11;
    // 0x8006A010: sb          $t4, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r12;
    // 0x8006A014: sb          $t5, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r13;
    // 0x8006A018: sh          $t6, 0x8($sp)
    MEM_H(0X8, ctx->r29) = ctx->r14;
    // 0x8006A01C: sb          $t7, 0xA($sp)
    MEM_B(0XA, ctx->r29) = ctx->r15;
    // 0x8006A020: sb          $t8, 0xB($sp)
    MEM_B(0XB, ctx->r29) = ctx->r24;
    // 0x8006A024: blez        $t9, L_8006A074
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8006A028: sw          $zero, 0x0($sp)
        MEM_W(0X0, ctx->r29) = 0;
            goto L_8006A074;
    }
    // 0x8006A028: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8006A02C:
    // 0x8006A02C: addiu       $t1, $sp, 0x4
    ctx->r9 = ADD32(ctx->r29, 0X4);
    // 0x8006A030: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8006A034: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8006A038: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8006A03C: swl         $at, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r1);
    // 0x8006A040: swr         $at, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r1);
    // 0x8006A044: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x8006A048: swl         $t3, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r11);
    // 0x8006A04C: swr         $t3, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r11);
    // 0x8006A050: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8006A054: lbu         $t8, 0x4F31($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X4F31);
    // 0x8006A058: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8006A05C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8006A060: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8006A064: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8006A068: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8006A06C: bne         $at, $zero, L_8006A02C
    if (ctx->r1 != 0) {
        // 0x8006A070: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_8006A02C;
    }
    // 0x8006A070: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
L_8006A074:
    // 0x8006A074: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8006A078: addiu       $t9, $zero, 0xFE
    ctx->r25 = ADD32(0, 0XFE);
    // 0x8006A07C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8006A080: jr          $ra
    // 0x8006A084: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
    return;
    // 0x8006A084: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
    // 0x8006A088: nop

    // 0x8006A08C: nop

;}
RECOMP_FUNC void func_8006A1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A1E0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8006A1E4: lw          $t6, 0x5D90($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5D90);
    // FALLTHROUGH FIX: func_8006A1E0 falls through to func_8006A1E8
    func_8006A1E8(rdram, ctx);
;}
RECOMP_FUNC void func_8006A1E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A1E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006A1EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006A1F0: bne         $t6, $zero, L_8006A358
    if (ctx->r14 != 0) {
        // 0x8006A1F4: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_8006A358;
    }
    // 0x8006A1F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8006A1F8: jal         0x8006F440
    // 0x8006A1FC: nop

    func_8006F440(rdram, ctx);
        goto after_0;
    // 0x8006A1FC: nop

    after_0:
    // 0x8006A200: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006A204: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8006A208: addiu       $a1, $a1, 0x6148
    ctx->r5 = ADD32(ctx->r5, 0X6148);
    // 0x8006A20C: addiu       $a0, $a0, 0x6130
    ctx->r4 = ADD32(ctx->r4, 0X6130);
    // 0x8006A210: jal         0x800697E0
    // 0x8006A214: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8006A214: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x8006A218: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006A21C: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x8006A220: sh          $t7, 0x6160($at)
    MEM_H(0X6160, ctx->r1) = ctx->r15;
    // 0x8006A224: sb          $zero, 0x6162($at)
    MEM_B(0X6162, ctx->r1) = 0;
    // 0x8006A228: sw          $zero, 0x6164($at)
    MEM_W(0X6164, ctx->r1) = 0;
    // 0x8006A22C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006A230: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x8006A234: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8006A238: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8006A23C: sh          $t8, 0x6178($at)
    MEM_H(0X6178, ctx->r1) = ctx->r24;
    // 0x8006A240: sb          $zero, 0x617A($at)
    MEM_B(0X617A, ctx->r1) = 0;
    // 0x8006A244: sw          $zero, 0x617C($at)
    MEM_W(0X617C, ctx->r1) = 0;
    // 0x8006A248: addiu       $a2, $a2, 0x6160
    ctx->r6 = ADD32(ctx->r6, 0X6160);
    // 0x8006A24C: addiu       $a1, $a1, 0x6130
    ctx->r5 = ADD32(ctx->r5, 0X6130);
    // 0x8006A250: jal         0x80069810
    // 0x8006A254: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8006A254: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x8006A258: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8006A25C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8006A260: addiu       $a2, $a2, 0x6178
    ctx->r6 = ADD32(ctx->r6, 0X6178);
    // 0x8006A264: addiu       $a1, $a1, 0x6130
    ctx->r5 = ADD32(ctx->r5, 0X6130);
    // 0x8006A268: jal         0x80069810
    // 0x8006A26C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8006A26C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x8006A270: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8006A274: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8006A278: jal         0x8006E950
    // 0x8006A27C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadPri_recomp(rdram, ctx);
        goto after_4;
    // 0x8006A27C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8006A280: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8006A284: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8006A288: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8006A28C: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8006A290: beq         $at, $zero, L_8006A2A8
    if (ctx->r1 == 0) {
        // 0x8006A294: nop
    
            goto L_8006A2A8;
    }
    // 0x8006A294: nop

    // 0x8006A298: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8006A29C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006A2A0: jal         0x8006E970
    // 0x8006A2A4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_5;
    // 0x8006A2A4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_5:
L_8006A2A8:
    // 0x8006A2A8: jal         0x8006E620
    // 0x8006A2AC: nop

    __osDisableInt_recomp(rdram, ctx);
        goto after_6;
    // 0x8006A2AC: nop

    after_6:
    // 0x8006A2B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8006A2B4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8006A2B8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8006A2BC: addiu       $t4, $t4, 0x6130
    ctx->r12 = ADD32(ctx->r12, 0X6130);
    // 0x8006A2C0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8006A2C4: addiu       $t3, $t3, 0x4F80
    ctx->r11 = ADD32(ctx->r11, 0X4F80);
    // 0x8006A2C8: sw          $t2, 0x5D90($at)
    MEM_W(0X5D90, ctx->r1) = ctx->r10;
    // 0x8006A2CC: sw          $t3, 0x5D94($at)
    MEM_W(0X5D94, ctx->r1) = ctx->r11;
    // 0x8006A2D0: sw          $t4, 0x5D98($at)
    MEM_W(0X5D98, ctx->r1) = ctx->r12;
    // 0x8006A2D4: sw          $t4, 0x5D9C($at)
    MEM_W(0X5D9C, ctx->r1) = ctx->r12;
    // 0x8006A2D8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8006A2DC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8006A2E0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8006A2E4: addiu       $t5, $t5, 0x5130
    ctx->r13 = ADD32(ctx->r13, 0X5130);
    // 0x8006A2E8: addiu       $t6, $t5, 0x1000
    ctx->r14 = ADD32(ctx->r13, 0X1000);
    // 0x8006A2EC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8006A2F0: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8006A2F4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8006A2F8: sw          $zero, 0x5DA0($at)
    MEM_W(0X5DA0, ctx->r1) = 0;
    // 0x8006A2FC: sw          $zero, 0x5DA4($at)
    MEM_W(0X5DA4, ctx->r1) = 0;
    // 0x8006A300: sw          $zero, 0x5DA8($at)
    MEM_W(0X5DA8, ctx->r1) = 0;
    // 0x8006A304: addiu       $a3, $a3, 0x5D90
    ctx->r7 = ADD32(ctx->r7, 0X5D90);
    // 0x8006A308: addiu       $a2, $a2, -0x5C98
    ctx->r6 = ADD32(ctx->r6, -0X5C98);
    // 0x8006A30C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8006A310: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8006A314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006A318: jal         0x800693B0
    // 0x8006A31C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    osCreateThread_recomp(rdram, ctx);
        goto after_7;
    // 0x8006A31C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_7:
    // 0x8006A320: jal         0x8006F840
    // 0x8006A324: nop

    __osViInit_recomp(rdram, ctx);
        goto after_8;
    // 0x8006A324: nop

    after_8:
    // 0x8006A328: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006A32C: jal         0x80069500
    // 0x8006A330: addiu       $a0, $a0, 0x4F80
    ctx->r4 = ADD32(ctx->r4, 0X4F80);
    osStartThread_recomp(rdram, ctx);
        goto after_9;
    // 0x8006A330: addiu       $a0, $a0, 0x4F80
    ctx->r4 = ADD32(ctx->r4, 0X4F80);
    after_9:
    // 0x8006A334: jal         0x8006E640
    // 0x8006A338: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_10;
    // 0x8006A338: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x8006A33C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006A340: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006A344: beq         $t8, $at, L_8006A358
    if (ctx->r24 == ctx->r1) {
        // 0x8006A348: nop
    
            goto L_8006A358;
    }
    // 0x8006A348: nop

    // 0x8006A34C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006A350: jal         0x8006E970
    // 0x8006A354: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_11;
    // 0x8006A354: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_11:
L_8006A358:
    // 0x8006A358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A35C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006A360: jr          $ra
    // 0x8006A364: nop

    return;
    // 0x8006A364: nop

;}
RECOMP_FUNC void func_8006A368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A368: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006A36C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006A370: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006A374: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A378: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8006A37C: jal         0x8006F980
    // 0x8006A380: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    func_8006F980(rdram, ctx);
        goto after_0;
    // 0x8006A380: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_0:
    // 0x8006A384: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8006A388: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8006A38C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006A390: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x8006A394: bne         $t7, $zero, L_8006A3A8
    if (ctx->r15 != 0) {
        // 0x8006A398: sh          $t7, 0x6190($at)
        MEM_H(0X6190, ctx->r1) = ctx->r15;
            goto L_8006A3A8;
    }
    // 0x8006A398: sh          $t7, 0x6190($at)
    MEM_H(0X6190, ctx->r1) = ctx->r15;
    // 0x8006A39C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006A3A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006A3A4: sh          $t8, 0x6190($at)
    MEM_H(0X6190, ctx->r1) = ctx->r24;
L_8006A3A8:
    // 0x8006A3A8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8006A3AC: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
L_8006A3B0:
    // 0x8006A3B0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8006A3B4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8006A3B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006A3BC: jal         0x80069CF0
    // 0x8006A3C0: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8006A3C0: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    after_1:
    // 0x8006A3C4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A3C8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8006A3CC: lhu         $s0, 0x0($t1)
    ctx->r16 = MEM_HU(ctx->r9, 0X0);
    // 0x8006A3D0: beq         $s0, $at, L_8006A3E8
    if (ctx->r16 == ctx->r1) {
        // 0x8006A3D4: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_8006A3E8;
    }
    // 0x8006A3D4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8006A3D8: beq         $s0, $at, L_8006A4F8
    if (ctx->r16 == ctx->r1) {
        // 0x8006A3DC: nop
    
            goto L_8006A4F8;
    }
    // 0x8006A3DC: nop

    // 0x8006A3E0: b           L_8006A3B0
    // 0x8006A3E4: nop

        goto L_8006A3B0;
    // 0x8006A3E4: nop

L_8006A3E8:
    // 0x8006A3E8: jal         0x8006F990
    // 0x8006A3EC: nop

    __osViSwapContext_recomp(rdram, ctx);
        goto after_2;
    // 0x8006A3EC: nop

    after_2:
    // 0x8006A3F0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8006A3F4: lhu         $t2, 0x6190($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X6190);
    // 0x8006A3F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006A3FC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8006A400: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8006A404: bne         $t4, $zero, L_8006A448
    if (ctx->r12 != 0) {
        // 0x8006A408: sh          $t3, 0x6190($at)
        MEM_H(0X6190, ctx->r1) = ctx->r11;
            goto L_8006A448;
    }
    // 0x8006A408: sh          $t3, 0x6190($at)
    MEM_H(0X6190, ctx->r1) = ctx->r11;
    // 0x8006A40C: jal         0x8006F980
    // 0x8006A410: nop

    func_8006F980(rdram, ctx);
        goto after_3;
    // 0x8006A410: nop

    after_3:
    // 0x8006A414: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8006A418: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8006A41C: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x8006A420: beq         $t6, $zero, L_8006A438
    if (ctx->r14 == 0) {
        // 0x8006A424: nop
    
            goto L_8006A438;
    }
    // 0x8006A424: nop

    // 0x8006A428: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8006A42C: lw          $a1, 0x14($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X14);
    // 0x8006A430: jal         0x8006A090
    // 0x8006A434: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8006A434: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_8006A438:
    // 0x8006A438: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8006A43C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006A440: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x8006A444: sh          $t8, 0x6190($at)
    MEM_H(0X6190, ctx->r1) = ctx->r24;
L_8006A448:
    // 0x8006A448: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8006A44C: lw          $t9, 0x65CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X65CC);
    // 0x8006A450: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8006A454: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006A458: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8006A45C: beq         $t1, $zero, L_8006A490
    if (ctx->r9 == 0) {
        // 0x8006A460: sw          $t0, 0x65CC($at)
        MEM_W(0X65CC, ctx->r1) = ctx->r8;
            goto L_8006A490;
    }
    // 0x8006A460: sw          $t0, 0x65CC($at)
    MEM_W(0X65CC, ctx->r1) = ctx->r8;
    // 0x8006A464: jal         0x8006FCF0
    // 0x8006A468: nop

    osGetCount_recomp(rdram, ctx);
        goto after_5;
    // 0x8006A468: nop

    after_5:
    // 0x8006A46C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8006A470: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8006A474: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8006A478: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006A47C: sw          $t4, 0x65C0($at)
    MEM_W(0X65C0, ctx->r1) = ctx->r12;
    // 0x8006A480: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006A484: or          $t5, $t2, $zero
    ctx->r13 = ctx->r10 | 0;
    // 0x8006A488: sw          $t5, 0x65C4($at)
    MEM_W(0X65C4, ctx->r1) = ctx->r13;
    // 0x8006A48C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_8006A490:
    // 0x8006A490: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8006A494: lw          $t3, 0x65C8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X65C8);
    // 0x8006A498: jal         0x8006FCF0
    // 0x8006A49C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    osGetCount_recomp(rdram, ctx);
        goto after_6;
    // 0x8006A49C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_6:
    // 0x8006A4A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006A4A4: sw          $v0, 0x65C8($at)
    MEM_W(0X65C8, ctx->r1) = ctx->r2;
    // 0x8006A4A8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8006A4AC: lw          $t6, 0x65C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X65C8);
    // 0x8006A4B0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8006A4B4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8006A4B8: lw          $t3, 0x65C4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X65C4);
    // 0x8006A4BC: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8006A4C0: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x8006A4C4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8006A4C8: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x8006A4CC: lw          $t2, 0x65C0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X65C0);
    // 0x8006A4D0: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x8006A4D4: sltu        $at, $t5, $t3
    ctx->r1 = ctx->r13 < ctx->r11 ? 1 : 0;
    // 0x8006A4D8: addu        $t4, $at, $t0
    ctx->r12 = ADD32(ctx->r1, ctx->r8);
    // 0x8006A4DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006A4E0: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x8006A4E4: sw          $t4, 0x65C0($at)
    MEM_W(0X65C0, ctx->r1) = ctx->r12;
    // 0x8006A4E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8006A4EC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8006A4F0: b           L_8006A3B0
    // 0x8006A4F4: sw          $t5, 0x65C4($at)
    MEM_W(0X65C4, ctx->r1) = ctx->r13;
        goto L_8006A3B0;
    // 0x8006A4F4: sw          $t5, 0x65C4($at)
    MEM_W(0X65C4, ctx->r1) = ctx->r13;
L_8006A4F8:
    // 0x8006A4F8: jal         0x8006F4CC
    // 0x8006A4FC: nop

    func_8006F4CC(rdram, ctx);
        goto after_7;
    // 0x8006A4FC: nop

    after_7:
    // 0x8006A500: b           L_8006A3B0
    // 0x8006A504: nop

        goto L_8006A3B0;
    // 0x8006A504: nop

    // 0x8006A508: nop

    // 0x8006A50C: nop

    // 0x8006A510: nop

    // 0x8006A514: nop

    // 0x8006A518: nop

    // 0x8006A51C: nop

    // 0x8006A520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A524: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A528: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8006A52C: jr          $ra
    // 0x8006A530: nop

    return;
    // 0x8006A530: nop

    // 0x8006A534: nop

    // 0x8006A538: nop

    // 0x8006A53C: nop

;}
RECOMP_FUNC void func_8006A720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A720: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006A724: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006A728: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8006A72C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8006A730: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x8006A734: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x8006A738: dsrlv       $v0, $t6, $t7
    ctx->r2 = ctx->r14 >> (ctx->r15 & 63);
    // 0x8006A73C: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x8006A740: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x8006A744: jr          $ra
    // 0x8006A748: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x8006A748: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_8006A7F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A7F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006A7F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006A7F8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8006A7FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8006A800: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x8006A804: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x8006A808: ddivu       $zero, $t6, $t7
    DDIVU(U64(ctx->r14), U64(ctx->r15), &lo, &hi);
    // 0x8006A80C: bne         $t7, $zero, L_8006A818
    if (ctx->r15 != 0) {
        // 0x8006A810: nop
    
            goto L_8006A818;
    }
    // 0x8006A810: nop

    // 0x8006A814: break       7
    do_break(2147919892);
L_8006A818:
    // 0x8006A818: mfhi        $v0
    ctx->r2 = hi;
    // 0x8006A81C: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x8006A820: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x8006A824: jr          $ra
    // 0x8006A828: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x8006A828: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_8006AB50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AB50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006AB54: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8006AB58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006AB5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006AB60: addiu       $t6, $t6, 0x61A0
    ctx->r14 = ADD32(ctx->r14, 0X61A0);
    // 0x8006AB64: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8006AB68: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8006AB6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006AB70: jal         0x8006FD20
    // 0x8006AB74: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8006FD20(rdram, ctx);
        goto after_0;
    // 0x8006AB74: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
    // 0x8006AB78: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AB7C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8006AB80: beq         $t8, $zero, L_8006AB98
    if (ctx->r24 == 0) {
        // 0x8006AB84: nop
    
            goto L_8006AB98;
    }
    // 0x8006AB84: nop

    // 0x8006AB88: jal         0x80070030
    // 0x8006AB8C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x8006AB8C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x8006AB90: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AB94: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
L_8006AB98:
    // 0x8006AB98: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AB9C: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x8006ABA0: beq         $t1, $zero, L_8006ABB8
    if (ctx->r9 == 0) {
        // 0x8006ABA4: nop
    
            goto L_8006ABB8;
    }
    // 0x8006ABA4: nop

    // 0x8006ABA8: jal         0x80070030
    // 0x8006ABAC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x8006ABAC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_2:
    // 0x8006ABB0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8006ABB4: sw          $v0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r2;
L_8006ABB8:
    // 0x8006ABB8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8006ABBC: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x8006ABC0: beq         $t4, $zero, L_8006ABD8
    if (ctx->r12 == 0) {
        // 0x8006ABC4: nop
    
            goto L_8006ABD8;
    }
    // 0x8006ABC4: nop

    // 0x8006ABC8: jal         0x80070030
    // 0x8006ABCC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x8006ABCC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_3:
    // 0x8006ABD0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8006ABD4: sw          $v0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r2;
L_8006ABD8:
    // 0x8006ABD8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8006ABDC: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x8006ABE0: beq         $t7, $zero, L_8006ABF8
    if (ctx->r15 == 0) {
        // 0x8006ABE4: nop
    
            goto L_8006ABF8;
    }
    // 0x8006ABE4: nop

    // 0x8006ABE8: jal         0x80070030
    // 0x8006ABEC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x8006ABEC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_4:
    // 0x8006ABF0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8006ABF4: sw          $v0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r2;
L_8006ABF8:
    // 0x8006ABF8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8006ABFC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8006AC00: beq         $t0, $zero, L_8006AC18
    if (ctx->r8 == 0) {
        // 0x8006AC04: nop
    
            goto L_8006AC18;
    }
    // 0x8006AC04: nop

    // 0x8006AC08: jal         0x80070030
    // 0x8006AC0C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x8006AC0C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_5:
    // 0x8006AC10: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AC14: sw          $v0, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r2;
L_8006AC18:
    // 0x8006AC18: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AC1C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8006AC20: beq         $t3, $zero, L_8006AC38
    if (ctx->r11 == 0) {
        // 0x8006AC24: nop
    
            goto L_8006AC38;
    }
    // 0x8006AC24: nop

    // 0x8006AC28: jal         0x80070030
    // 0x8006AC2C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_6;
    // 0x8006AC2C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_6:
    // 0x8006AC30: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AC34: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
L_8006AC38:
    // 0x8006AC38: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AC3C: lw          $t6, 0x38($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X38);
    // 0x8006AC40: beq         $t6, $zero, L_8006AC58
    if (ctx->r14 == 0) {
        // 0x8006AC44: nop
    
            goto L_8006AC58;
    }
    // 0x8006AC44: nop

    // 0x8006AC48: jal         0x80070030
    // 0x8006AC4C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_7;
    // 0x8006AC4C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_7:
    // 0x8006AC50: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AC54: sw          $v0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r2;
L_8006AC58:
    // 0x8006AC58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006AC5C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AC60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006AC64: jr          $ra
    // 0x8006AC68: nop

    return;
    // 0x8006AC68: nop

;}
RECOMP_FUNC void func_8006AED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AED0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006AED4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006AED8: jal         0x8006E620
    // 0x8006AEDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x8006AEDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006AEE0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8006AEE4: lw          $t6, 0x6BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BB4);
    // 0x8006AEE8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8006AEEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006AEF0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8006AEF4: jal         0x8006E640
    // 0x8006AEF8: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x8006AEF8: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_1:
    // 0x8006AEFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AF00: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8006AF04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006AF08: jr          $ra
    // 0x8006AF0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006AF0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006AF1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AF1C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8006AF20: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8006AF24: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006AF28: bgez        $a0, L_8006AF40
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006AF2C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8006AF40;
    }
    // 0x8006AF2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006AF30: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006AF34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006AF38: nop

    // 0x8006AF3C: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8006AF40:
    // 0x8006AF40: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8006AF44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006AF48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006AF4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006AF50: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8006AF54: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8006AF58: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x8006AF5C: nop

    // 0x8006AF60: cvt.w.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    ctx->f8.u32l = CVT_W_S(ctx->f12.fl);
    // 0x8006AF64: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x8006AF68: nop

    // 0x8006AF6C: andi        $at, $a1, 0x4
    ctx->r1 = ctx->r5 & 0X4;
    // 0x8006AF70: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x8006AF74: beq         $a1, $zero, L_8006AFC4
    if (ctx->r5 == 0) {
        // 0x8006AF78: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_8006AFC4;
    }
    // 0x8006AF78: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8006AF7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006AF80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006AF84: sub.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8006AF88: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x8006AF8C: nop

    // 0x8006AF90: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8006AF94: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x8006AF98: nop

    // 0x8006AF9C: andi        $at, $a1, 0x4
    ctx->r1 = ctx->r5 & 0X4;
    // 0x8006AFA0: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x8006AFA4: bne         $a1, $zero, L_8006AFBC
    if (ctx->r5 != 0) {
        // 0x8006AFA8: nop
    
            goto L_8006AFBC;
    }
    // 0x8006AFA8: nop

    // 0x8006AFAC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8006AFB0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006AFB4: b           L_8006AFD4
    // 0x8006AFB8: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_8006AFD4;
    // 0x8006AFB8: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_8006AFBC:
    // 0x8006AFBC: b           L_8006AFD4
    // 0x8006AFC0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_8006AFD4;
    // 0x8006AFC0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_8006AFC4:
    // 0x8006AFC4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8006AFC8: nop

    // 0x8006AFCC: bltz        $a1, L_8006AFBC
    if (SIGNED(ctx->r5) < 0) {
        // 0x8006AFD0: nop
    
            goto L_8006AFBC;
    }
    // 0x8006AFD0: nop

L_8006AFD4:
    // 0x8006AFD4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8006AFD8: sltiu       $at, $a1, 0x84
    ctx->r1 = ctx->r5 < 0X84 ? 1 : 0;
    // 0x8006AFDC: beq         $at, $zero, L_8006AFEC
    if (ctx->r1 == 0) {
        // 0x8006AFE0: nop
    
            goto L_8006AFEC;
    }
    // 0x8006AFE0: nop

    // 0x8006AFE4: b           L_8006B068
    // 0x8006AFE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B068;
    // 0x8006AFE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AFEC:
    // 0x8006AFEC: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8006AFF0: divu        $zero, $a1, $at
    lo = S32(U32(ctx->r5) / U32(ctx->r1)); hi = S32(U32(ctx->r5) % U32(ctx->r1));
    // 0x8006AFF4: mflo        $a2
    ctx->r6 = lo;
    // 0x8006AFF8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8006AFFC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8006B000: slti        $at, $a2, 0x11
    ctx->r1 = SIGNED(ctx->r6) < 0X11 ? 1 : 0;
    // 0x8006B004: bne         $at, $zero, L_8006B010
    if (ctx->r1 != 0) {
        // 0x8006B008: nop
    
            goto L_8006B010;
    }
    // 0x8006B008: nop

    // 0x8006B00C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
L_8006B010:
    // 0x8006B010: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x8006B014: lui         $t0, 0xA450
    ctx->r8 = S32(0XA450 << 16);
    // 0x8006B018: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x8006B01C: addiu       $t1, $a2, -0x1
    ctx->r9 = ADD32(ctx->r6, -0X1);
    // 0x8006B020: lui         $t2, 0xA450
    ctx->r10 = S32(0XA450 << 16);
    // 0x8006B024: sw          $t1, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r9;
    // 0x8006B028: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006B02C: lui         $t4, 0xA450
    ctx->r12 = S32(0XA450 << 16);
    // 0x8006B030: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
    // 0x8006B034: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8006B038: lw          $t5, 0x5D38($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5D38);
    // 0x8006B03C: div         $zero, $t5, $a1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r5)));
    // 0x8006B040: mflo        $v0
    ctx->r2 = lo;
    // 0x8006B044: bne         $a1, $zero, L_8006B050
    if (ctx->r5 != 0) {
        // 0x8006B048: nop
    
            goto L_8006B050;
    }
    // 0x8006B048: nop

    // 0x8006B04C: break       7
    do_break(2147921996);
L_8006B050:
    // 0x8006B050: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006B054: bne         $a1, $at, L_8006B068
    if (ctx->r5 != ctx->r1) {
        // 0x8006B058: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006B068;
    }
    // 0x8006B058: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006B05C: bne         $t5, $at, L_8006B068
    if (ctx->r13 != ctx->r1) {
        // 0x8006B060: nop
    
            goto L_8006B068;
    }
    // 0x8006B060: nop

    // 0x8006B064: break       6
    do_break(2147922020);
L_8006B068:
    // 0x8006B068: jr          $ra
    // 0x8006B06C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8006B06C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8006B070: nop

    // 0x8006B074: nop

    // 0x8006B078: nop

    // 0x8006B07C: nop

    // 0x8006B080: nop

    // 0x8006B084: nop

    // 0x8006B088: nop

    // 0x8006B08C: nop

    // 0x8006B090: nop

    // 0x8006B094: nop

    // 0x8006B098: nop

    // 0x8006B09C: nop

    // 0x8006B0A0: nop

    // 0x8006B0A4: nop

    // 0x8006B0A8: nop

    // 0x8006B0AC: nop

    // 0x8006B0B0: nop

    // 0x8006B0B4: nop

    // 0x8006B0B8: nop

    // 0x8006B0BC: nop

    // 0x8006B0C0: nop

    // 0x8006B0C4: nop

    // 0x8006B0C8: nop

    // 0x8006B0CC: nop

;}
RECOMP_FUNC void memcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B450: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006B454: beq         $a2, $zero, L_8006B474
    if (ctx->r6 == 0) {
        // 0x8006B458: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8006B474;
    }
    // 0x8006B458: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8006B45C:
    // 0x8006B45C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8006B460: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8006B464: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006B468: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006B46C: bne         $a2, $zero, L_8006B45C
    if (ctx->r6 != 0) {
        // 0x8006B470: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_8006B45C;
    }
    // 0x8006B470: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
L_8006B474:
    // 0x8006B474: jr          $ra
    // 0x8006B478: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006B478: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void strlen_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B47C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8006B480: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8006B484: beq         $t6, $zero, L_8006B49C
    if (ctx->r14 == 0) {
        // 0x8006B488: nop
    
            goto L_8006B49C;
    }
    // 0x8006B488: nop

    // 0x8006B48C: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
L_8006B490:
    // 0x8006B490: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006B494: bnel        $t7, $zero, L_8006B490
    if (ctx->r15 != 0) {
        // 0x8006B498: lbu         $t7, 0x1($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X1);
            goto L_8006B490;
    }
    goto skip_0;
    // 0x8006B498: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    skip_0:
L_8006B49C:
    // 0x8006B49C: jr          $ra
    // 0x8006B4A0: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    return;
    // 0x8006B4A0: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
;}
RECOMP_FUNC void strchr_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B4A4: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8006B4A8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8006B4AC: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8006B4B0: beql        $t6, $v1, L_8006B4DC
    if (ctx->r14 == ctx->r3) {
        // 0x8006B4B4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8006B4DC;
    }
    goto skip_0;
    // 0x8006B4B4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
L_8006B4B8:
    // 0x8006B4B8: bnel        $v1, $zero, L_8006B4CC
    if (ctx->r3 != 0) {
        // 0x8006B4BC: lbu         $v1, 0x1($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X1);
            goto L_8006B4CC;
    }
    goto skip_1;
    // 0x8006B4BC: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x8006B4C0: jr          $ra
    // 0x8006B4C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006B4C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B4C8: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
L_8006B4CC:
    // 0x8006B4CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006B4D0: bne         $v0, $v1, L_8006B4B8
    if (ctx->r2 != ctx->r3) {
        // 0x8006B4D4: nop
    
            goto L_8006B4B8;
    }
    // 0x8006B4D4: nop

    // 0x8006B4D8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006B4DC:
    // 0x8006B4DC: jr          $ra
    // 0x8006B4E0: nop

    return;
    // 0x8006B4E0: nop

    // 0x8006B4E4: nop

    // 0x8006B4E8: nop

    // 0x8006B4EC: nop

;}
RECOMP_FUNC void func_8006B4F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B4F0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8006B4F4: lw          $a0, 0x6AD0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6AD0);
    // 0x8006B4F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8006B4FC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8006B500: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x8006B504: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x8006B508: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006B50C: mflo        $a1
    ctx->r5 = lo;
    // 0x8006B510: srl         $v0, $a1, 2
    ctx->r2 = S32(U32(ctx->r5) >> 2);
    // 0x8006B514: jr          $ra
    // 0x8006B518: sw          $v0, 0x6AD0($at)
    MEM_W(0X6AD0, ctx->r1) = ctx->r2;
    return;
    // 0x8006B518: sw          $v0, 0x6AD0($at)
    MEM_W(0X6AD0, ctx->r1) = ctx->r2;
    // 0x8006B51C: nop

;}
RECOMP_FUNC void func_8006BAE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BAE4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006BAE8: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8006BAEC: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8006BAF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BAF4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8006BAF8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8006BAFC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8006BB00: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8006BB04: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_8006BB08:
    // 0x8006BB08: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006BB0C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8006BB10: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006BB14: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8006BB18: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8006BB1C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006BB20: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8006BB24: slti        $at, $t2, 0xF
    ctx->r1 = SIGNED(ctx->r10) < 0XF ? 1 : 0;
    // 0x8006BB28: bne         $at, $zero, L_8006BB08
    if (ctx->r1 != 0) {
        // 0x8006BB2C: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_8006BB08;
    }
    // 0x8006BB2C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8006BB30: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8006BB34: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006BB38: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8006BB3C: sw          $t3, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r11;
    // 0x8006BB40: addiu       $t6, $zero, 0x23
    ctx->r14 = ADD32(0, 0X23);
    // 0x8006BB44: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006BB48: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8006BB4C: sb          $t5, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r13;
    // 0x8006BB50: sb          $t6, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r14;
    // 0x8006BB54: sb          $t8, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r24;
    // 0x8006BB58: sb          $t7, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r15;
    // 0x8006BB5C: jal         0x80071F90
    // 0x8006BB60: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    __osContAddressCrc_recomp(rdram, ctx);
        goto after_0;
    // 0x8006BB60: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    after_0:
    // 0x8006BB64: lhu         $t9, 0x4E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X4E);
    // 0x8006BB68: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8006BB6C: sb          $t2, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r10;
    // 0x8006BB70: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8006BB74: or          $t1, $v0, $t0
    ctx->r9 = ctx->r2 | ctx->r8;
    // 0x8006BB78: sh          $t1, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r9;
    // 0x8006BB7C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8006BB80:
    // 0x8006BB80: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8006BB84: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8006BB88: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8006BB8C: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x8006BB90: sb          $t4, 0x22($t6)
    MEM_B(0X22, ctx->r14) = ctx->r12;
    // 0x8006BB94: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8006BB98: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8006BB9C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8006BBA0: slti        $at, $t0, 0x20
    ctx->r1 = SIGNED(ctx->r8) < 0X20 ? 1 : 0;
    // 0x8006BBA4: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8006BBA8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8006BBAC: bne         $at, $zero, L_8006BB80
    if (ctx->r1 != 0) {
        // 0x8006BBB0: sw          $t7, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r15;
            goto L_8006BB80;
    }
    // 0x8006BBB0: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8006BBB4: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8006BBB8: beq         $t1, $zero, L_8006BBF4
    if (ctx->r9 == 0) {
        // 0x8006BBBC: nop
    
            goto L_8006BBF4;
    }
    // 0x8006BBBC: nop

    // 0x8006BBC0: blez        $t1, L_8006BBF4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8006BBC4: sw          $zero, 0x18($sp)
        MEM_W(0X18, ctx->r29) = 0;
            goto L_8006BBF4;
    }
    // 0x8006BBC4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8006BBC8:
    // 0x8006BBC8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8006BBCC: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x8006BBD0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8006BBD4: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8006BBD8: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8006BBDC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8006BBE0: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8006BBE4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8006BBE8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8006BBEC: bne         $at, $zero, L_8006BBC8
    if (ctx->r1 != 0) {
        // 0x8006BBF0: sw          $t4, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r12;
            goto L_8006BBC8;
    }
    // 0x8006BBF0: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_8006BBF4:
    // 0x8006BBF4: addiu       $t9, $sp, 0x1C
    ctx->r25 = ADD32(ctx->r29, 0X1C);
    // 0x8006BBF8: addiu       $t1, $t9, 0x24
    ctx->r9 = ADD32(ctx->r25, 0X24);
    // 0x8006BBFC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_8006BC00:
    // 0x8006BC00: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x8006BC04: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8006BC08: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8006BC0C: swl         $at, -0xC($t7)
    do_swl(rdram, -0XC, ctx->r15, ctx->r1);
    // 0x8006BC10: swr         $at, -0x9($t7)
    do_swr(rdram, -0X9, ctx->r15, ctx->r1);
    // 0x8006BC14: lw          $at, -0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X8);
    // 0x8006BC18: swl         $at, -0x8($t7)
    do_swl(rdram, -0X8, ctx->r15, ctx->r1);
    // 0x8006BC1C: swr         $at, -0x5($t7)
    do_swr(rdram, -0X5, ctx->r15, ctx->r1);
    // 0x8006BC20: lw          $at, -0x4($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X4);
    // 0x8006BC24: swl         $at, -0x4($t7)
    do_swl(rdram, -0X4, ctx->r15, ctx->r1);
    // 0x8006BC28: bne         $t9, $t1, L_8006BC00
    if (ctx->r25 != ctx->r9) {
        // 0x8006BC2C: swr         $at, -0x1($t7)
        do_swr(rdram, -0X1, ctx->r15, ctx->r1);
            goto L_8006BC00;
    }
    // 0x8006BC2C: swr         $at, -0x1($t7)
    do_swr(rdram, -0X1, ctx->r15, ctx->r1);
    // 0x8006BC30: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x8006BC34: addiu       $t4, $zero, 0xFE
    ctx->r12 = ADD32(0, 0XFE);
    // 0x8006BC38: swl         $at, 0x0($t7)
    do_swl(rdram, 0X0, ctx->r15, ctx->r1);
    // 0x8006BC3C: swr         $at, 0x3($t7)
    do_swr(rdram, 0X3, ctx->r15, ctx->r1);
    // 0x8006BC40: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8006BC44: addiu       $t3, $t2, 0x28
    ctx->r11 = ADD32(ctx->r10, 0X28);
    // 0x8006BC48: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8006BC4C: sb          $t4, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r12;
    // 0x8006BC50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BC54: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8006BC58: jr          $ra
    // 0x8006BC5C: nop

    return;
    // 0x8006BC5C: nop

;}
RECOMP_FUNC void func_8006C0D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C0D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C0D8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8006C0DC: addiu       $t6, $t6, 0x6420
    ctx->r14 = ADD32(ctx->r14, 0X6420);
    // 0x8006C0E0: sb          $zero, 0x7($sp)
    MEM_B(0X7, ctx->r29) = 0;
    // 0x8006C0E4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8006C0E8: blez        $t7, L_8006C18C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8006C0EC: sw          $zero, 0x8($sp)
        MEM_W(0X8, ctx->r29) = 0;
            goto L_8006C18C;
    }
    // 0x8006C0EC: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
L_8006C0F0:
    // 0x8006C0F0: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8006C0F4: addiu       $t8, $sp, 0xC
    ctx->r24 = ADD32(ctx->r29, 0XC);
    // 0x8006C0F8: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x8006C0FC: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x8006C100: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x8006C104: lwl         $t1, 0x4($t9)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r25, 0X4);
    // 0x8006C108: lwr         $t1, 0x7($t9)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r25, 0X7);
    // 0x8006C10C: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8006C110: lbu         $t2, 0xE($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XE);
    // 0x8006C114: andi        $t3, $t2, 0xC0
    ctx->r11 = ctx->r10 & 0XC0;
    // 0x8006C118: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x8006C11C: sb          $t4, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r12;
    // 0x8006C120: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x8006C124: bne         $t5, $zero, L_8006C160
    if (ctx->r13 != 0) {
        // 0x8006C128: nop
    
            goto L_8006C160;
    }
    // 0x8006C128: nop

    // 0x8006C12C: lbu         $t6, 0x11($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X11);
    // 0x8006C130: lbu         $t0, 0x10($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X10);
    // 0x8006C134: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006C138: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8006C13C: or          $t8, $t7, $t0
    ctx->r24 = ctx->r15 | ctx->r8;
    // 0x8006C140: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8006C144: lbu         $t9, 0x12($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X12);
    // 0x8006C148: sb          $t9, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r25;
    // 0x8006C14C: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8006C150: lbu         $t1, 0x7($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X7);
    // 0x8006C154: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x8006C158: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x8006C15C: sb          $t5, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r13;
L_8006C160:
    // 0x8006C160: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8006C164: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8006C168: lbu         $t9, 0x4F31($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4F31);
    // 0x8006C16C: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x8006C170: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8006C174: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8006C178: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x8006C17C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8006C180: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8006C184: bne         $at, $zero, L_8006C0F0
    if (ctx->r1 != 0) {
        // 0x8006C188: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8006C0F0;
    }
    // 0x8006C188: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8006C18C:
    // 0x8006C18C: lbu         $t3, 0x7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X7);
    // 0x8006C190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C194: jr          $ra
    // 0x8006C198: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    return;
    // 0x8006C198: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // 0x8006C19C: nop

;}
RECOMP_FUNC void __osPfsDeclearPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CA84: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006CA88: lbu         $t6, 0x63($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X63);
    // 0x8006CA8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CA90: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8006CA94: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8006CA98: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8006CA9C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8006CAA0: blez        $t6, L_8006CAB4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8006CAA4: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_8006CAB4;
    }
    // 0x8006CAA4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8006CAA8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006CAAC: b           L_8006CAC0
    // 0x8006CAB0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
        goto L_8006CAC0;
    // 0x8006CAB0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_8006CAB4:
    // 0x8006CAB4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8006CAB8: lw          $t9, 0x60($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X60);
    // 0x8006CABC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_8006CAC0:
    // 0x8006CAC0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8006CAC4: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x8006CAC8: beq         $at, $zero, L_8006CB04
    if (ctx->r1 == 0) {
        // 0x8006CACC: sw          $t0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r8;
            goto L_8006CB04;
    }
    // 0x8006CACC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_8006CAD0:
    // 0x8006CAD0: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CAD4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8006CAD8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006CADC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8006CAE0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8006CAE4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8006CAE8: beq         $t5, $at, L_8006CB04
    if (ctx->r13 == ctx->r1) {
        // 0x8006CAEC: nop
    
            goto L_8006CB04;
    }
    // 0x8006CAEC: nop

    // 0x8006CAF0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CAF4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8006CAF8: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x8006CAFC: bne         $at, $zero, L_8006CAD0
    if (ctx->r1 != 0) {
        // 0x8006CB00: sw          $t7, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r15;
            goto L_8006CAD0;
    }
    // 0x8006CB00: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_8006CB04:
    // 0x8006CB04: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CB08: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8006CB0C: bne         $t8, $at, L_8006CB28
    if (ctx->r24 != ctx->r1) {
        // 0x8006CB10: nop
    
            goto L_8006CB28;
    }
    // 0x8006CB10: nop

    // 0x8006CB14: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8006CB18: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8006CB1C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8006CB20: b           L_8006CCD8
    // 0x8006CB24: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_8006CCD8;
    // 0x8006CB24: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8006CB28:
    // 0x8006CB28: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_8006CB2C:
    // 0x8006CB2C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8006CB30: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x8006CB34: sb          $zero, 0x24($t1)
    MEM_B(0X24, ctx->r9) = 0;
    // 0x8006CB38: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8006CB3C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8006CB40: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x8006CB44: bne         $at, $zero, L_8006CB2C
    if (ctx->r1 != 0) {
        // 0x8006CB48: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_8006CB2C;
    }
    // 0x8006CB48: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8006CB4C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CB50: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8006CB54: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006CB58: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x8006CB5C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8006CB60: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CB64: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8006CB68: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8006CB6C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8006CB70: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x8006CB74: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8006CB78: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x8006CB7C: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8006CB80: beq         $at, $zero, L_8006CC54
    if (ctx->r1 == 0) {
        // 0x8006CB84: slti        $at, $t9, 0x80
        ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
            goto L_8006CC54;
    }
    // 0x8006CB84: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x8006CB88: beq         $at, $zero, L_8006CC54
    if (ctx->r1 == 0) {
        // 0x8006CB8C: nop
    
            goto L_8006CC54;
    }
    // 0x8006CB8C: nop

L_8006CB90:
    // 0x8006CB90: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CB94: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8006CB98: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006CB9C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8006CBA0: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8006CBA4: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8006CBA8: bne         $t7, $at, L_8006CC20
    if (ctx->r15 != ctx->r1) {
        // 0x8006CBAC: nop
    
            goto L_8006CC20;
    }
    // 0x8006CBAC: nop

    // 0x8006CBB0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8006CBB4: lbu         $t8, 0x63($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X63);
    // 0x8006CBB8: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x8006CBBC: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x8006CBC0: addu        $t1, $t3, $t0
    ctx->r9 = ADD32(ctx->r11, ctx->r8);
    // 0x8006CBC4: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
    // 0x8006CBC8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8006CBCC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8006CBD0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CBD4: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8006CBD8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8006CBDC: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x8006CBE0: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x8006CBE4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8006CBE8: jal         0x8006CCE8
    // 0x8006CBEC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_8006CCE8(rdram, ctx);
        goto after_0;
    // 0x8006CBEC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x8006CBF0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8006CBF4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CBF8: beq         $t2, $zero, L_8006CC08
    if (ctx->r10 == 0) {
        // 0x8006CBFC: nop
    
            goto L_8006CC08;
    }
    // 0x8006CBFC: nop

    // 0x8006CC00: b           L_8006CCD8
    // 0x8006CC04: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_8006CCD8;
    // 0x8006CC04: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8006CC08:
    // 0x8006CC08: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CC0C: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8006CC10: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8006CC14: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8006CC18: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x8006CC1C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
L_8006CC20:
    // 0x8006CC20: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CC24: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8006CC28: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8006CC2C: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8006CC30: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x8006CC34: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8006CC38: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006CC3C: beq         $at, $zero, L_8006CC54
    if (ctx->r1 == 0) {
        // 0x8006CC40: nop
    
            goto L_8006CC54;
    }
    // 0x8006CC40: nop

    // 0x8006CC44: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CC48: slti        $at, $t2, 0x80
    ctx->r1 = SIGNED(ctx->r10) < 0X80 ? 1 : 0;
    // 0x8006CC4C: bne         $at, $zero, L_8006CB90
    if (ctx->r1 != 0) {
        // 0x8006CC50: nop
    
            goto L_8006CB90;
    }
    // 0x8006CC50: nop

L_8006CC54:
    // 0x8006CC54: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8006CC58: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8006CC5C: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8006CC60: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8006CC64: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CC68: bne         $t1, $at, L_8006CC9C
    if (ctx->r9 != ctx->r1) {
        // 0x8006CC6C: nop
    
            goto L_8006CC9C;
    }
    // 0x8006CC6C: nop

    // 0x8006CC70: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8006CC74: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8006CC78: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x8006CC7C: slt         $at, $t4, $t0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8006CC80: beq         $at, $zero, L_8006CC9C
    if (ctx->r1 == 0) {
        // 0x8006CC84: nop
    
            goto L_8006CC9C;
    }
    // 0x8006CC84: nop

    // 0x8006CC88: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8006CC8C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8006CC90: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8006CC94: b           L_8006CCD8
    // 0x8006CC98: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_8006CCD8;
    // 0x8006CC98: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8006CC9C:
    // 0x8006CC9C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8006CCA0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8006CCA4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006CCA8: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x8006CCAC: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x8006CCB0: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x8006CCB4: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x8006CCB8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8006CCBC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8006CCC0: jal         0x8006CCE8
    // 0x8006CCC4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8006CCE8(rdram, ctx);
        goto after_1;
    // 0x8006CCC4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8006CCC8: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8006CCCC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8006CCD0: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x8006CCD4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8006CCD8:
    // 0x8006CCD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CCDC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8006CCE0: jr          $ra
    // 0x8006CCE4: nop

    return;
    // 0x8006CCE4: nop

;}
RECOMP_FUNC void func_8006CCE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CCE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006CCEC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006CCF0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8006CCF4: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x8006CCF8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8006CCFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006CD00: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006CD04: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8006CD08: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8006CD0C: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x8006CD10: jal         0x8007112C
    // 0x8006CD14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x8006CD14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x8006CD18: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8006CD1C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8006CD20: beq         $t8, $zero, L_8006CD30
    if (ctx->r24 == 0) {
        // 0x8006CD24: nop
    
            goto L_8006CD30;
    }
    // 0x8006CD24: nop

    // 0x8006CD28: b           L_8006CD98
    // 0x8006CD2C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8006CD98;
    // 0x8006CD2C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006CD30:
    // 0x8006CD30: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8006CD34:
    // 0x8006CD34: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8006CD38: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CD3C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8006CD40: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x8006CD44: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x8006CD48: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8006CD4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8006CD50: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8006CD54: jal         0x80072110
    // 0x8006CD58: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_1;
    // 0x8006CD58: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x8006CD5C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8006CD60: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8006CD64: bne         $t3, $zero, L_8006CD80
    if (ctx->r11 != 0) {
        // 0x8006CD68: nop
    
            goto L_8006CD80;
    }
    // 0x8006CD68: nop

    // 0x8006CD6C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8006CD70: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8006CD74: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x8006CD78: bne         $at, $zero, L_8006CD34
    if (ctx->r1 != 0) {
        // 0x8006CD7C: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_8006CD34;
    }
    // 0x8006CD7C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_8006CD80:
    // 0x8006CD80: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006CD84: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x8006CD88: jal         0x8007112C
    // 0x8006CD8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x8006CD8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8006CD90: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8006CD94: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_8006CD98:
    // 0x8006CD98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CD9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006CDA0: jr          $ra
    // 0x8006CDA4: nop

    return;
    // 0x8006CDA4: nop

    // 0x8006CDA8: nop

    // 0x8006CDAC: nop

;}
