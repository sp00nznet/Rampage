#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_80033FD4(uint8_t* rdram, recomp_context* ctx);
void func_80034044(uint8_t* rdram, recomp_context* ctx);
void func_8003410C(uint8_t* rdram, recomp_context* ctx);
void func_8003417C(uint8_t* rdram, recomp_context* ctx);
void func_800341B4(uint8_t* rdram, recomp_context* ctx);
void func_80034308(uint8_t* rdram, recomp_context* ctx);
void func_80034378(uint8_t* rdram, recomp_context* ctx);
void func_80034440(uint8_t* rdram, recomp_context* ctx);
void func_80034480(uint8_t* rdram, recomp_context* ctx);
void func_800344B8(uint8_t* rdram, recomp_context* ctx);
void func_800344C0(uint8_t* rdram, recomp_context* ctx);
void func_80034558(uint8_t* rdram, recomp_context* ctx);
void func_800347E0(uint8_t* rdram, recomp_context* ctx);
void func_80034820(uint8_t* rdram, recomp_context* ctx);
void func_8003489C(uint8_t* rdram, recomp_context* ctx);
void func_800348DC(uint8_t* rdram, recomp_context* ctx);
void func_80034958(uint8_t* rdram, recomp_context* ctx);
void func_80034998(uint8_t* rdram, recomp_context* ctx);
void func_800349F0(uint8_t* rdram, recomp_context* ctx);
void func_80034A6C(uint8_t* rdram, recomp_context* ctx);
void func_80034B3C(uint8_t* rdram, recomp_context* ctx);
void func_80034B88(uint8_t* rdram, recomp_context* ctx);
void func_80034BB4(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80033C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033C74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033C78: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80033C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033C80: jal         0x800379E8
    // 0x80033C84: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_800379E8(rdram, ctx);
        goto after_0;
    // 0x80033C84: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80033C88: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80033C8C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80033C90: bne         $v0, $v1, L_80033CA8
    if (ctx->r2 != ctx->r3) {
        // 0x80033C94: nop
    
            goto L_80033CA8;
    }
    // 0x80033C94: nop

    // 0x80033C98: jal         0x80033580
    // 0x80033C9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80033580(rdram, ctx);
        goto after_1;
    // 0x80033C9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80033CA0: j           L_80033D18
    // 0x80033CA4: nop

        goto L_80033D18;
    // 0x80033CA4: nop

L_80033CA8:
    // 0x80033CA8: lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XA);
    // 0x80033CAC: beq         $v0, $zero, L_80033D18
    if (ctx->r2 == 0) {
        // 0x80033CB0: nop
    
            goto L_80033D18;
    }
    // 0x80033CB0: nop

    // 0x80033CB4: jal         0x80033514
    // 0x80033CB8: lui         $a0, 0xFFFE
    ctx->r4 = S32(0XFFFE << 16);
    func_80033514(rdram, ctx);
        goto after_2;
    // 0x80033CB8: lui         $a0, 0xFFFE
    ctx->r4 = S32(0XFFFE << 16);
    after_2:
    // 0x80033CBC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80033CC0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80033CC4: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x80033CC8: addiu       $v0, $v0, 0xF23
    ctx->r2 = ADD32(ctx->r2, 0XF23);
    // 0x80033CCC: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
    // 0x80033CD0: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x80033CD4: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // 0x80033CD8: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x80033CDC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80033CE0: bne         $v1, $v0, L_80033D00
    if (ctx->r3 != ctx->r2) {
        // 0x80033CE4: sh          $zero, 0xA($s0)
        MEM_H(0XA, ctx->r16) = 0;
            goto L_80033D00;
    }
    // 0x80033CE4: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x80033CE8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80033CEC: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80033CF0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80033CF4: addiu       $a0, $a0, -0xCC8
    ctx->r4 = ADD32(ctx->r4, -0XCC8);
    // 0x80033CF8: j           L_80033D10
    // 0x80033CFC: nop

        goto L_80033D10;
    // 0x80033CFC: nop

L_80033D00:
    // 0x80033D00: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80033D04: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80033D08: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80033D0C: addiu       $a0, $a0, 0xDE0
    ctx->r4 = ADD32(ctx->r4, 0XDE0);
L_80033D10:
    // 0x80033D10: jal         0x80037DDC
    // 0x80033D14: nop

    func_80037DDC(rdram, ctx);
        goto after_3;
    // 0x80033D14: nop

    after_3:
L_80033D18:
    // 0x80033D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033D1C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80033D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033D24: jr          $ra
    // 0x80033D28: nop

    return;
    // 0x80033D28: nop

;}
RECOMP_FUNC void func_80033D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033D2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033D30: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80033D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033D38: jal         0x800379E8
    // 0x80033D3C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_800379E8(rdram, ctx);
        goto after_0;
    // 0x80033D3C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80033D40: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80033D44: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80033D48: bne         $v0, $v1, L_80033D58
    if (ctx->r2 != ctx->r3) {
        // 0x80033D4C: nop
    
            goto L_80033D58;
    }
    // 0x80033D4C: nop

    // 0x80033D50: jal         0x80034B88
    // 0x80033D54: nop

    func_80034B88(rdram, ctx);
        goto after_1;
    // 0x80033D54: nop

    after_1:
L_80033D58:
    // 0x80033D58: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    // 0x80033D5C: beq         $v0, $zero, L_80033D74
    if (ctx->r2 == 0) {
        // 0x80033D60: nop
    
            goto L_80033D74;
    }
    // 0x80033D60: nop

    // 0x80033D64: jal         0x8003336C
    // 0x80033D68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003336C(rdram, ctx);
        goto after_2;
    // 0x80033D68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80033D6C: j           L_80033DF0
    // 0x80033D70: nop

        goto L_80033DF0;
    // 0x80033D70: nop

L_80033D74:
    // 0x80033D74: lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X22);
    // 0x80033D78: beq         $v0, $zero, L_80033DAC
    if (ctx->r2 == 0) {
        // 0x80033D7C: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80033DAC;
    }
    // 0x80033D7C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80033D80: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x80033D84: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80033D88: addiu       $a0, $a0, 0xDD4
    ctx->r4 = ADD32(ctx->r4, 0XDD4);
    // 0x80033D8C: bne         $v1, $v0, L_80033D9C
    if (ctx->r3 != ctx->r2) {
        // 0x80033D90: nop
    
            goto L_80033D9C;
    }
    // 0x80033D90: nop

    // 0x80033D94: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80033D98: addiu       $a0, $a0, -0xD8C
    ctx->r4 = ADD32(ctx->r4, -0XD8C);
L_80033D9C:
    // 0x80033D9C: jal         0x80036798
    // 0x80033DA0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80036798(rdram, ctx);
        goto after_3;
    // 0x80033DA0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80033DA4: j           L_80033DF0
    // 0x80033DA8: nop

        goto L_80033DF0;
    // 0x80033DA8: nop

L_80033DAC:
    // 0x80033DAC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80033DB0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80033DB4: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80033DB8: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x80033DBC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80033DC0: lw          $a1, 0x3294($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3294);
    // 0x80033DC4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80033DC8: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x80033DCC: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80033DD0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80033DD4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80033DD8: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80033DDC: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80033DE0: beq         $v0, $zero, L_80033DF0
    if (ctx->r2 == 0) {
        // 0x80033DE4: nop
    
            goto L_80033DF0;
    }
    // 0x80033DE4: nop

    // 0x80033DE8: jal         0x80033580
    // 0x80033DEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80033580(rdram, ctx);
        goto after_4;
    // 0x80033DEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
L_80033DF0:
    // 0x80033DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033DF4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80033DF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033DFC: jr          $ra
    // 0x80033E00: nop

    return;
    // 0x80033E00: nop

;}
RECOMP_FUNC void func_80033E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033E04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80033E08: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80033E0C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80033E10: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80033E14: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80033E18: lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18);
    // 0x80033E1C: beq         $v0, $zero, L_80033E54
    if (ctx->r2 == 0) {
        // 0x80033E20: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_80033E54;
    }
    // 0x80033E20: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80033E24: lw          $s0, 0x1C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X1C);
    // 0x80033E28: jal         0x8003BB8C
    // 0x80033E2C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003BB8C(rdram, ctx);
        goto after_0;
    // 0x80033E2C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80033E30: jal         0x8002614C
    // 0x80033E34: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002614C(rdram, ctx);
        goto after_1;
    // 0x80033E34: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80033E38: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80033E3C: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x80033E40: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80033E44: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80033E48: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x80033E4C: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80033E50: sh          $zero, 0x18($s1)
    MEM_H(0X18, ctx->r17) = 0;
L_80033E54:
    // 0x80033E54: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80033E58: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80033E5C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80033E60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80033E64: jr          $ra
    // 0x80033E68: nop

    return;
    // 0x80033E68: nop

;}
RECOMP_FUNC void func_80033E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033E6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80033E70: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80033E74: jal         0x800379E8
    // 0x80033E78: nop

    func_800379E8(rdram, ctx);
        goto after_0;
    // 0x80033E78: nop

    after_0:
    // 0x80033E7C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80033E80: bne         $v0, $zero, L_80033EB8
    if (ctx->r2 != 0) {
        // 0x80033E84: nop
    
            goto L_80033EB8;
    }
    // 0x80033E84: nop

    // 0x80033E88: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80033E8C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80033E90: lh          $a2, 0x18($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X18);
    // 0x80033E94: slti        $v0, $a2, 0x99
    ctx->r2 = SIGNED(ctx->r6) < 0X99 ? 1 : 0;
    // 0x80033E98: beq         $v0, $zero, L_80033EB8
    if (ctx->r2 == 0) {
        // 0x80033E9C: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_80033EB8;
    }
    // 0x80033E9C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80033EA0: lh          $a1, 0x14($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X14);
    // 0x80033EA4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80033EA8: addiu       $a3, $zero, 0x1004
    ctx->r7 = ADD32(0, 0X1004);
    // 0x80033EAC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80033EB0: jal         0x800333AC
    // 0x80033EB4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800333AC(rdram, ctx);
        goto after_1;
    // 0x80033EB4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
L_80033EB8:
    // 0x80033EB8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80033EBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80033EC0: jr          $ra
    // 0x80033EC4: nop

    return;
    // 0x80033EC4: nop

;}
RECOMP_FUNC void func_80033EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033EC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80033ECC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80033ED0: jal         0x800379E8
    // 0x80033ED4: nop

    func_800379E8(rdram, ctx);
        goto after_0;
    // 0x80033ED4: nop

    after_0:
    // 0x80033ED8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80033EDC: bne         $v0, $zero, L_80033F14
    if (ctx->r2 != 0) {
        // 0x80033EE0: nop
    
            goto L_80033F14;
    }
    // 0x80033EE0: nop

    // 0x80033EE4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80033EE8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80033EEC: lh          $a2, 0x18($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X18);
    // 0x80033EF0: slti        $v0, $a2, 0x99
    ctx->r2 = SIGNED(ctx->r6) < 0X99 ? 1 : 0;
    // 0x80033EF4: beq         $v0, $zero, L_80033F14
    if (ctx->r2 == 0) {
        // 0x80033EF8: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_80033F14;
    }
    // 0x80033EF8: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80033EFC: lh          $a1, 0x14($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X14);
    // 0x80033F00: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80033F04: addiu       $a3, $zero, 0x1004
    ctx->r7 = ADD32(0, 0X1004);
    // 0x80033F08: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80033F0C: jal         0x800333AC
    // 0x80033F10: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800333AC(rdram, ctx);
        goto after_1;
    // 0x80033F10: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
L_80033F14:
    // 0x80033F14: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80033F18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80033F1C: jr          $ra
    // 0x80033F20: nop

    return;
    // 0x80033F20: nop

;}
RECOMP_FUNC void func_80033F24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033F24: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80033F28: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80033F2C: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x80033F30: addiu       $v0, $v0, 0xF23
    ctx->r2 = ADD32(ctx->r2, 0XF23);
    // 0x80033F34: jr          $ra
    // 0x80033F38: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
    return;
    // 0x80033F38: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80033F3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033F3C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80033F40: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80033F44: lui         $v0, 0xFFFC
    ctx->r2 = S32(0XFFFC << 16);
    // 0x80033F48: jr          $ra
    // 0x80033F4C: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    return;
    // 0x80033F4C: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80033F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033F50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033F54: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80033F58: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x80033F5C: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x80033F60: beq         $v0, $zero, L_80033FC4
    if (ctx->r2 == 0) {
        // 0x80033F64: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80033FC4;
    }
    // 0x80033F64: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80033F68: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80033F6C: addu        $at, $at, $v0
    gpr jr_addend_80033F74 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80033F70: lw          $v0, 0x3DF0($at)
    ctx->r2 = ADD32(ctx->r1, 0X3DF0);
    // 0x80033F74: jr          $v0
    // 0x80033F78: nop

    switch (jr_addend_80033F74 >> 2) {
        case 0: goto L_80033F7C; break;
        case 1: goto L_80033F8C; break;
        case 2: goto L_80033F9C; break;
        case 3: goto L_80033FAC; break;
        case 4: goto L_80033FBC; break;
        default: switch_error(__func__, 0x80033F74, 0x80093DF0);
    }
    // 0x80033F78: nop

L_80033F7C:
    // 0x80033F7C: jal         0x80033FD4
    // 0x80033F80: nop

    func_80033FD4(rdram, ctx);
        goto after_0;
    // 0x80033F80: nop

    after_0:
    // 0x80033F84: j           L_80033FC4
    // 0x80033F88: nop

        goto L_80033FC4;
    // 0x80033F88: nop

L_80033F8C:
    // 0x80033F8C: jal         0x80034044
    // 0x80033F90: nop

    func_80034044(rdram, ctx);
        goto after_1;
    // 0x80033F90: nop

    after_1:
    // 0x80033F94: j           L_80033FC4
    // 0x80033F98: nop

        goto L_80033FC4;
    // 0x80033F98: nop

L_80033F9C:
    // 0x80033F9C: jal         0x8003410C
    // 0x80033FA0: nop

    func_8003410C(rdram, ctx);
        goto after_2;
    // 0x80033FA0: nop

    after_2:
    // 0x80033FA4: j           L_80033FC4
    // 0x80033FA8: nop

        goto L_80033FC4;
    // 0x80033FA8: nop

L_80033FAC:
    // 0x80033FAC: jal         0x8003417C
    // 0x80033FB0: nop

    func_8003417C(rdram, ctx);
        goto after_3;
    // 0x80033FB0: nop

    after_3:
    // 0x80033FB4: j           L_80033FC4
    // 0x80033FB8: nop

        goto L_80033FC4;
    // 0x80033FB8: nop

L_80033FBC:
    // 0x80033FBC: jal         0x800341B4
    // 0x80033FC0: nop

    func_800341B4(rdram, ctx);
        goto after_4;
    // 0x80033FC0: nop

    after_4:
L_80033FC4:
    // 0x80033FC4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80033FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033FCC: jr          $ra
    // 0x80033FD0: nop

    return;
    // 0x80033FD0: nop

;}
RECOMP_FUNC void func_80033FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033FD4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80033FD8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80033FD4 falls into func_80033FDC
    func_80033FDC(rdram, ctx);
;}
RECOMP_FUNC void func_80033FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033FDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033FE0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80033FE4: lh          $v0, 0x18($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X18);
    // 0x80033FE8: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x80033FEC: bne         $v0, $zero, L_80034000
    if (ctx->r2 != 0) {
        // 0x80033FF0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80034000;
    }
    // 0x80033FF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80033FF4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80033FF8: j           L_80034034
    // 0x80033FFC: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
        goto L_80034034;
    // 0x80033FFC: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
L_80034000:
    // 0x80034000: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    // 0x80034004: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80034008: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003400C: lui         $v0, 0xFFFE
    ctx->r2 = S32(0XFFFE << 16);
    // 0x80034010: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80034014: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80034018: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x8003401C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80034020: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80034024: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80034028: addiu       $a1, $a1, 0xB84
    ctx->r5 = ADD32(ctx->r5, 0XB84);
    // 0x8003402C: jal         0x800249B4
    // 0x80034030: nop

    func_800249B4(rdram, ctx);
        goto after_0;
    // 0x80034030: nop

    after_0:
L_80034034:
    // 0x80034034: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80034038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003403C: jr          $ra
    // 0x80034040: nop

    return;
    // 0x80034040: nop

;}
RECOMP_FUNC void func_80034044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034044: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80034048: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // FALLTHROUGH: func_80034044 falls into func_8003404C
    func_8003404C(rdram, ctx);
;}
RECOMP_FUNC void func_8003404C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003404C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034050: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80034054: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80034058: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x8003405C: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80034060: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80034064: lw          $a0, 0x3294($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3294);
    // 0x80034068: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8003406C: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x80034070: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80034074: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80034078: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x8003407C: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80034080: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80034084: addu        $a1, $v1, $v0
    ctx->r5 = ADD32(ctx->r3, ctx->r2);
    // 0x80034088: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x8003408C: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80034090: bnel        $v0, $zero, L_80034098
    if (ctx->r2 != 0) {
        // 0x80034094: lui         $a1, 0x4
        ctx->r5 = S32(0X4 << 16);
            goto L_80034098;
    }
    goto skip_0;
    // 0x80034094: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    skip_0:
L_80034098:
    // 0x80034098: sw          $a1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r5;
    // 0x8003409C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800340A0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800340A4: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x800340A8: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800340AC: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x800340B0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800340B4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800340B8: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
    // 0x800340BC: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x800340C0: bne         $v0, $zero, L_800340FC
    if (ctx->r2 != 0) {
        // 0x800340C4: addiu       $v0, $zero, 0xE1
        ctx->r2 = ADD32(0, 0XE1);
            goto L_800340FC;
    }
    // 0x800340C4: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x800340C8: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    // 0x800340CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800340D0: sh          $v0, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r2;
    // 0x800340D4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800340D8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800340DC: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800340E0: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x800340E4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800340E8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x800340EC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800340F0: addiu       $a0, $a0, 0xBB4
    ctx->r4 = ADD32(ctx->r4, 0XBB4);
    // 0x800340F4: jal         0x80037DDC
    // 0x800340F8: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800340F8: nop

    after_0:
L_800340FC:
    // 0x800340FC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80034100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034104: jr          $ra
    // 0x80034108: nop

    return;
    // 0x80034108: nop

;}
RECOMP_FUNC void func_8003410C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003410C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034110: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80034114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034118: jal         0x800379E8
    // 0x8003411C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_800379E8(rdram, ctx);
        goto after_0;
    // 0x8003411C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80034120: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80034124: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80034128: bne         $v0, $v1, L_80034140
    if (ctx->r2 != ctx->r3) {
        // 0x8003412C: nop
    
            goto L_80034140;
    }
    // 0x8003412C: nop

    // 0x80034130: jal         0x80033580
    // 0x80034134: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80033580(rdram, ctx);
        goto after_1;
    // 0x80034134: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80034138: j           L_80034168
    // 0x8003413C: nop

        goto L_80034168;
    // 0x8003413C: nop

L_80034140:
    // 0x80034140: lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XA);
    // 0x80034144: beq         $v0, $zero, L_80034168
    if (ctx->r2 == 0) {
        // 0x80034148: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80034168;
    }
    // 0x80034148: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8003414C: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x80034150: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80034154: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80034158: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8003415C: addiu       $a1, $a1, 0xC34
    ctx->r5 = ADD32(ctx->r5, 0XC34);
    // 0x80034160: jal         0x800249B4
    // 0x80034164: nop

    func_800249B4(rdram, ctx);
        goto after_2;
    // 0x80034164: nop

    after_2:
L_80034168:
    // 0x80034168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003416C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80034170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034174: jr          $ra
    // 0x80034178: nop

    return;
    // 0x80034178: nop

;}
RECOMP_FUNC void func_8003417C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003417C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80034180: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_8003417C falls into func_80034184
    func_80034184(rdram, ctx);
;}
RECOMP_FUNC void func_80034184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034184: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034188: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003418C: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80034190: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80034194: beq         $v0, $zero, L_800341A4
    if (ctx->r2 == 0) {
        // 0x80034198: nop
    
            goto L_800341A4;
    }
    // 0x80034198: nop

    // 0x8003419C: jal         0x80033580
    // 0x800341A0: nop

    func_80033580(rdram, ctx);
        goto after_0;
    // 0x800341A0: nop

    after_0:
L_800341A4:
    // 0x800341A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800341A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800341AC: jr          $ra
    // 0x800341B0: nop

    return;
    // 0x800341B0: nop

;}
RECOMP_FUNC void func_800341B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800341B4: jr          $ra
    // 0x800341B8: nop

    return;
    // 0x800341B8: nop

;}
RECOMP_FUNC void func_800341BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800341BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800341C0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800341C4: jal         0x800379E8
    // 0x800341C8: nop

    func_800379E8(rdram, ctx);
        goto after_0;
    // 0x800341C8: nop

    after_0:
    // 0x800341CC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800341D0: bne         $v0, $zero, L_80034218
    if (ctx->r2 != 0) {
        // 0x800341D4: nop
    
            goto L_80034218;
    }
    // 0x800341D4: nop

    // 0x800341D8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800341DC: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800341E0: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
    // 0x800341E4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800341E8: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x800341EC: beql        $v0, $zero, L_800341F4
    if (ctx->r2 == 0) {
        // 0x800341F0: addiu       $a2, $a2, -0x10
        ctx->r6 = ADD32(ctx->r6, -0X10);
            goto L_800341F4;
    }
    goto skip_0;
    // 0x800341F0: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    skip_0:
L_800341F4:
    // 0x800341F4: lh          $a1, 0x14($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X14);
    // 0x800341F8: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800341FC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80034200: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80034204: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80034208: addiu       $a3, $zero, 0x1004
    ctx->r7 = ADD32(0, 0X1004);
    // 0x8003420C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80034210: jal         0x800333AC
    // 0x80034214: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800333AC(rdram, ctx);
        goto after_1;
    // 0x80034214: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
L_80034218:
    // 0x80034218: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8003421C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80034220: jr          $ra
    // 0x80034224: nop

    return;
    // 0x80034224: nop

;}
RECOMP_FUNC void func_80034228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034228: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003422C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80034230: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x80034234: addiu       $v0, $v0, 0xF23
    ctx->r2 = ADD32(ctx->r2, 0XF23);
    // 0x80034238: jr          $ra
    // 0x8003423C: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
    return;
    // 0x8003423C: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80034240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034240: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80034244: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80034248: addiu       $v0, $zero, 0x1001
    ctx->r2 = ADD32(0, 0X1001);
    // 0x8003424C: jr          $ra
    // 0x80034250: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
    return;
    // 0x80034250: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80034254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034258: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003425C: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x80034260: sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x80034264: beq         $v0, $zero, L_800342F0
    if (ctx->r2 == 0) {
        // 0x80034268: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800342F0;
    }
    // 0x80034268: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8003426C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80034270: addu        $at, $at, $v0
    gpr jr_addend_80034278 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80034274: lw          $v0, 0x3E08($at)
    ctx->r2 = ADD32(ctx->r1, 0X3E08);
    // 0x80034278: jr          $v0
    // 0x8003427C: nop

    switch (jr_addend_80034278 >> 2) {
        case 0: goto L_80034280; break;
        case 1: goto L_80034290; break;
        case 2: goto L_800342A0; break;
        case 3: goto L_800342B0; break;
        case 4: goto L_800342F0; break;
        case 5: goto L_800342C0; break;
        case 6: goto L_800342D0; break;
        case 7: goto L_800342E0; break;
        default: switch_error(__func__, 0x80034278, 0x80093E08);
    }
    // 0x8003427C: nop

L_80034280:
    // 0x80034280: jal         0x80034308
    // 0x80034284: nop

    func_80034308(rdram, ctx);
        goto after_0;
    // 0x80034284: nop

    after_0:
    // 0x80034288: j           L_800342F8
    // 0x8003428C: nop

        goto L_800342F8;
    // 0x8003428C: nop

L_80034290:
    // 0x80034290: jal         0x80034378
    // 0x80034294: nop

    func_80034378(rdram, ctx);
        goto after_1;
    // 0x80034294: nop

    after_1:
    // 0x80034298: j           L_800342F8
    // 0x8003429C: nop

        goto L_800342F8;
    // 0x8003429C: nop

L_800342A0:
    // 0x800342A0: jal         0x80034440
    // 0x800342A4: nop

    func_80034440(rdram, ctx);
        goto after_2;
    // 0x800342A4: nop

    after_2:
    // 0x800342A8: j           L_800342F8
    // 0x800342AC: nop

        goto L_800342F8;
    // 0x800342AC: nop

L_800342B0:
    // 0x800342B0: jal         0x80034480
    // 0x800342B4: nop

    func_80034480(rdram, ctx);
        goto after_3;
    // 0x800342B4: nop

    after_3:
    // 0x800342B8: j           L_800342F8
    // 0x800342BC: nop

        goto L_800342F8;
    // 0x800342BC: nop

L_800342C0:
    // 0x800342C0: jal         0x800344B8
    // 0x800342C4: nop

    func_800344B8(rdram, ctx);
        goto after_4;
    // 0x800342C4: nop

    after_4:
    // 0x800342C8: j           L_800342F8
    // 0x800342CC: nop

        goto L_800342F8;
    // 0x800342CC: nop

L_800342D0:
    // 0x800342D0: jal         0x800344C0
    // 0x800342D4: nop

    func_800344C0(rdram, ctx);
        goto after_5;
    // 0x800342D4: nop

    after_5:
    // 0x800342D8: j           L_800342F8
    // 0x800342DC: nop

        goto L_800342F8;
    // 0x800342DC: nop

L_800342E0:
    // 0x800342E0: jal         0x80034558
    // 0x800342E4: nop

    func_80034558(rdram, ctx);
        goto after_6;
    // 0x800342E4: nop

    after_6:
    // 0x800342E8: j           L_800342F8
    // 0x800342EC: nop

        goto L_800342F8;
    // 0x800342EC: nop

L_800342F0:
    // 0x800342F0: jal         0x80033580
    // 0x800342F4: nop

    func_80033580(rdram, ctx);
        goto after_7;
    // 0x800342F4: nop

    after_7:
L_800342F8:
    // 0x800342F8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800342FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034300: jr          $ra
    // 0x80034304: nop

    return;
    // 0x80034304: nop

;}
RECOMP_FUNC void func_80034308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034308: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003430C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80034308 falls into func_80034310
    func_80034310(rdram, ctx);
;}
RECOMP_FUNC void func_80034310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034314: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80034318: lh          $v0, 0x18($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X18);
    // 0x8003431C: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x80034320: bne         $v0, $zero, L_80034334
    if (ctx->r2 != 0) {
        // 0x80034324: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80034334;
    }
    // 0x80034324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80034328: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8003432C: j           L_80034368
    // 0x80034330: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
        goto L_80034368;
    // 0x80034330: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
L_80034334:
    // 0x80034334: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    // 0x80034338: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003433C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80034340: lui         $v0, 0xFFFE
    ctx->r2 = S32(0XFFFE << 16);
    // 0x80034344: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80034348: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x8003434C: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x80034350: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80034354: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80034358: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8003435C: addiu       $a1, $a1, 0xAF0
    ctx->r5 = ADD32(ctx->r5, 0XAF0);
    // 0x80034360: jal         0x800249B4
    // 0x80034364: nop

    func_800249B4(rdram, ctx);
        goto after_0;
    // 0x80034364: nop

    after_0:
L_80034368:
    // 0x80034368: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003436C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034370: jr          $ra
    // 0x80034374: nop

    return;
    // 0x80034374: nop

;}
RECOMP_FUNC void func_80034378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034378: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003437C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // FALLTHROUGH: func_80034378 falls into func_80034380
    func_80034380(rdram, ctx);
;}
RECOMP_FUNC void func_80034380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034384: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80034388: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003438C: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x80034390: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80034394: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80034398: lw          $a0, 0x3294($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3294);
    // 0x8003439C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800343A0: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x800343A4: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x800343A8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800343AC: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x800343B0: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x800343B4: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x800343B8: addu        $a1, $v1, $v0
    ctx->r5 = ADD32(ctx->r3, ctx->r2);
    // 0x800343BC: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x800343C0: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800343C4: bnel        $v0, $zero, L_800343CC
    if (ctx->r2 != 0) {
        // 0x800343C8: lui         $a1, 0x4
        ctx->r5 = S32(0X4 << 16);
            goto L_800343CC;
    }
    goto skip_0;
    // 0x800343C8: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    skip_0:
L_800343CC:
    // 0x800343CC: sw          $a1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r5;
    // 0x800343D0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800343D4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800343D8: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x800343DC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800343E0: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x800343E4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800343E8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800343EC: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
    // 0x800343F0: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x800343F4: bne         $v0, $zero, L_80034430
    if (ctx->r2 != 0) {
        // 0x800343F8: addiu       $v0, $zero, 0xE1
        ctx->r2 = ADD32(0, 0XE1);
            goto L_80034430;
    }
    // 0x800343F8: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x800343FC: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    // 0x80034400: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80034404: sh          $v0, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r2;
    // 0x80034408: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003440C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80034410: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80034414: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x80034418: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8003441C: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80034420: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80034424: addiu       $a0, $a0, 0xB20
    ctx->r4 = ADD32(ctx->r4, 0XB20);
    // 0x80034428: jal         0x80037DDC
    // 0x8003442C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8003442C: nop

    after_0:
L_80034430:
    // 0x80034430: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80034434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034438: jr          $ra
    // 0x8003443C: nop

    return;
    // 0x8003443C: nop

;}
RECOMP_FUNC void func_80034440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034444: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80034448: lhu         $v0, 0xA($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XA);
    // 0x8003444C: beq         $v0, $zero, L_80034470
    if (ctx->r2 == 0) {
        // 0x80034450: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80034470;
    }
    // 0x80034450: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80034454: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    // 0x80034458: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8003445C: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80034460: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80034464: addiu       $a1, $a1, 0xB78
    ctx->r5 = ADD32(ctx->r5, 0XB78);
    // 0x80034468: jal         0x800249B4
    // 0x8003446C: nop

    func_800249B4(rdram, ctx);
        goto after_0;
    // 0x8003446C: nop

    after_0:
L_80034470:
    // 0x80034470: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80034474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034478: jr          $ra
    // 0x8003447C: nop

    return;
    // 0x8003447C: nop

;}
RECOMP_FUNC void func_80034480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034480: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80034484: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80034480 falls into func_80034488
    func_80034488(rdram, ctx);
;}
RECOMP_FUNC void func_80034488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003448C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80034490: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80034494: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80034498: beq         $v0, $zero, L_800344A8
    if (ctx->r2 == 0) {
        // 0x8003449C: nop
    
            goto L_800344A8;
    }
    // 0x8003449C: nop

    // 0x800344A0: jal         0x80033580
    // 0x800344A4: nop

    func_80033580(rdram, ctx);
        goto after_0;
    // 0x800344A4: nop

    after_0:
L_800344A8:
    // 0x800344A8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800344AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800344B0: jr          $ra
    // 0x800344B4: nop

    return;
    // 0x800344B4: nop

;}
RECOMP_FUNC void func_800344B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800344B8: jr          $ra
    // 0x800344BC: nop

    return;
    // 0x800344BC: nop

;}
RECOMP_FUNC void func_800344C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800344C0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800344C4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_800344C0 falls into func_800344C8
    func_800344C8(rdram, ctx);
;}
RECOMP_FUNC void func_800344C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800344C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800344CC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800344D0: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x800344D4: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800344D8: beq         $v0, $zero, L_800344F0
    if (ctx->r2 == 0) {
        // 0x800344DC: nop
    
            goto L_800344F0;
    }
    // 0x800344DC: nop

    // 0x800344E0: jal         0x80033580
    // 0x800344E4: nop

    func_80033580(rdram, ctx);
        goto after_0;
    // 0x800344E4: nop

    after_0:
    // 0x800344E8: j           L_80034548
    // 0x800344EC: nop

        goto L_80034548;
    // 0x800344EC: nop

L_800344F0:
    // 0x800344F0: lhu         $v0, 0x16($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X16);
    // 0x800344F4: beq         $v0, $zero, L_80034520
    if (ctx->r2 == 0) {
        // 0x800344F8: nop
    
            goto L_80034520;
    }
    // 0x800344F8: nop

    // 0x800344FC: sh          $zero, 0x16($a0)
    MEM_H(0X16, ctx->r4) = 0;
    // 0x80034500: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80034504: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80034508: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8003450C: addiu       $a1, $a1, 0xA4C
    ctx->r5 = ADD32(ctx->r5, 0XA4C);
    // 0x80034510: jal         0x800249B4
    // 0x80034514: nop

    func_800249B4(rdram, ctx);
        goto after_1;
    // 0x80034514: nop

    after_1:
    // 0x80034518: j           L_80034548
    // 0x8003451C: nop

        goto L_80034548;
    // 0x8003451C: nop

L_80034520:
    // 0x80034520: lhu         $v0, 0xA($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XA);
    // 0x80034524: beq         $v0, $zero, L_80034548
    if (ctx->r2 == 0) {
        // 0x80034528: nop
    
            goto L_80034548;
    }
    // 0x80034528: nop

    // 0x8003452C: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // 0x80034530: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80034534: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80034538: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8003453C: addiu       $a0, $a0, 0xAE4
    ctx->r4 = ADD32(ctx->r4, 0XAE4);
    // 0x80034540: jal         0x80037DDC
    // 0x80034544: nop

    func_80037DDC(rdram, ctx);
        goto after_2;
    // 0x80034544: nop

    after_2:
L_80034548:
    // 0x80034548: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003454C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034550: jr          $ra
    // 0x80034554: nop

    return;
    // 0x80034554: nop

;}
RECOMP_FUNC void func_80034558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034558: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003455C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80034558 falls into func_80034560
    func_80034560(rdram, ctx);
;}
RECOMP_FUNC void func_80034560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034564: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80034568: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x8003456C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80034570: beq         $v0, $zero, L_80034588
    if (ctx->r2 == 0) {
        // 0x80034574: nop
    
            goto L_80034588;
    }
    // 0x80034574: nop

    // 0x80034578: jal         0x80033580
    // 0x8003457C: nop

    func_80033580(rdram, ctx);
        goto after_0;
    // 0x8003457C: nop

    after_0:
    // 0x80034580: j           L_800345E0
    // 0x80034584: nop

        goto L_800345E0;
    // 0x80034584: nop

L_80034588:
    // 0x80034588: lhu         $v0, 0x16($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X16);
    // 0x8003458C: beq         $v0, $zero, L_800345B8
    if (ctx->r2 == 0) {
        // 0x80034590: nop
    
            goto L_800345B8;
    }
    // 0x80034590: nop

    // 0x80034594: sh          $zero, 0x16($a0)
    MEM_H(0X16, ctx->r4) = 0;
    // 0x80034598: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8003459C: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x800345A0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800345A4: addiu       $a1, $a1, 0xA08
    ctx->r5 = ADD32(ctx->r5, 0XA08);
    // 0x800345A8: jal         0x800249B4
    // 0x800345AC: nop

    func_800249B4(rdram, ctx);
        goto after_1;
    // 0x800345AC: nop

    after_1:
    // 0x800345B0: j           L_800345E0
    // 0x800345B4: nop

        goto L_800345E0;
    // 0x800345B4: nop

L_800345B8:
    // 0x800345B8: lhu         $v0, 0xA($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XA);
    // 0x800345BC: beq         $v0, $zero, L_800345E0
    if (ctx->r2 == 0) {
        // 0x800345C0: nop
    
            goto L_800345E0;
    }
    // 0x800345C0: nop

    // 0x800345C4: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // 0x800345C8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800345CC: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x800345D0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800345D4: addiu       $a0, $a0, 0xA40
    ctx->r4 = ADD32(ctx->r4, 0XA40);
    // 0x800345D8: jal         0x80037DDC
    // 0x800345DC: nop

    func_80037DDC(rdram, ctx);
        goto after_2;
    // 0x800345DC: nop

    after_2:
L_800345E0:
    // 0x800345E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800345E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800345E8: jr          $ra
    // 0x800345EC: nop

    return;
    // 0x800345EC: nop

;}
RECOMP_FUNC void func_800345F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800345F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800345F4: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800345F8: jal         0x800379E8
    // 0x800345FC: nop

    func_800379E8(rdram, ctx);
        goto after_0;
    // 0x800345FC: nop

    after_0:
    // 0x80034600: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80034604: bne         $v0, $zero, L_8003464C
    if (ctx->r2 != 0) {
        // 0x80034608: nop
    
            goto L_8003464C;
    }
    // 0x80034608: nop

    // 0x8003460C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80034610: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80034614: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
    // 0x80034618: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8003461C: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x80034620: beql        $v0, $zero, L_80034628
    if (ctx->r2 == 0) {
        // 0x80034624: addiu       $a2, $a2, -0x10
        ctx->r6 = ADD32(ctx->r6, -0X10);
            goto L_80034628;
    }
    goto skip_0;
    // 0x80034624: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    skip_0:
L_80034628:
    // 0x80034628: lh          $a1, 0x14($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X14);
    // 0x8003462C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80034630: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80034634: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80034638: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8003463C: addiu       $a3, $zero, 0x1004
    ctx->r7 = ADD32(0, 0X1004);
    // 0x80034640: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80034644: jal         0x800333AC
    // 0x80034648: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800333AC(rdram, ctx);
        goto after_1;
    // 0x80034648: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
L_8003464C:
    // 0x8003464C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80034650: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80034654: jr          $ra
    // 0x80034658: nop

    return;
    // 0x80034658: nop

;}
RECOMP_FUNC void func_8003465C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003465C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80034660: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80034664: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x80034668: addiu       $v0, $v0, 0xF23
    ctx->r2 = ADD32(ctx->r2, 0XF23);
    // 0x8003466C: jr          $ra
    // 0x80034670: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
    return;
    // 0x80034670: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80034674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034678: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003467C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80034680: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80034684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034688: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003468C: lw          $s0, 0x90($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X90);
    // 0x80034690: jal         0x80001414
    // 0x80034694: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80001414(rdram, ctx);
        goto after_0;
    // 0x80034694: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80034698: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8003469C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800346A0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800346A4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800346A8: lhu         $v0, 0x7320($at)
    ctx->r2 = MEM_HU(ctx->r1, 0X7320);
    // 0x800346AC: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x800346B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800346B4: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x800346B8: sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // 0x800346BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800346C0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800346C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800346C8: jr          $ra
    // 0x800346CC: nop

    return;
    // 0x800346CC: nop

;}
RECOMP_FUNC void func_800346D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800346D0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800346D4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800346D8: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x800346DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800346E0: jr          $ra
    // 0x800346E4: sh          $v0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r2;
    return;
    // 0x800346E4: sh          $v0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_800346E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800346E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800346EC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800346F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800346F4: jal         0x8007DEC0
    // 0x800346F8: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    func_8007DEC0(rdram, ctx);
        goto after_0;
    // 0x800346F8: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    after_0:
    // 0x800346FC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80034700: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034704: jr          $ra
    // 0x80034708: nop

    return;
    // 0x80034708: nop

;}
RECOMP_FUNC void func_8003470C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003470C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034710: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80034714: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x80034718: sltiu       $v0, $v1, 0xF
    ctx->r2 = ctx->r3 < 0XF ? 1 : 0;
    // 0x8003471C: beq         $v0, $zero, L_800347C8
    if (ctx->r2 == 0) {
        // 0x80034720: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800347C8;
    }
    // 0x80034720: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80034724: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80034728: addu        $at, $at, $v0
    gpr jr_addend_80034730 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003472C: lw          $v0, 0x3E28($at)
    ctx->r2 = ADD32(ctx->r1, 0X3E28);
    // 0x80034730: jr          $v0
    // 0x80034734: nop

    switch (jr_addend_80034730 >> 2) {
        case 0: goto L_80034758; break;
        case 1: goto L_80034788; break;
        case 2: goto L_80034768; break;
        case 3: goto L_80034778; break;
        case 4: goto L_800347C8; break;
        case 5: goto L_80034798; break;
        case 6: goto L_800347C8; break;
        case 7: goto L_800347C8; break;
        case 8: goto L_800347C8; break;
        case 9: goto L_800347A8; break;
        case 10: goto L_800347B8; break;
        case 11: goto L_800347C8; break;
        case 12: goto L_800347C8; break;
        case 13: goto L_80034748; break;
        case 14: goto L_80034738; break;
        default: switch_error(__func__, 0x80034730, 0x80093E28);
    }
    // 0x80034734: nop

L_80034738:
    // 0x80034738: jal         0x80036848
    // 0x8003473C: nop

    func_80036848(rdram, ctx);
        goto after_0;
    // 0x8003473C: nop

    after_0:
    // 0x80034740: j           L_800347D0
    // 0x80034744: nop

        goto L_800347D0;
    // 0x80034744: nop

L_80034748:
    // 0x80034748: jal         0x80035ECC
    // 0x8003474C: nop

    func_80035ECC(rdram, ctx);
        goto after_1;
    // 0x8003474C: nop

    after_1:
    // 0x80034750: j           L_800347D0
    // 0x80034754: nop

        goto L_800347D0;
    // 0x80034754: nop

L_80034758:
    // 0x80034758: jal         0x800347E0
    // 0x8003475C: nop

    func_800347E0(rdram, ctx);
        goto after_2;
    // 0x8003475C: nop

    after_2:
    // 0x80034760: j           L_800347D0
    // 0x80034764: nop

        goto L_800347D0;
    // 0x80034764: nop

L_80034768:
    // 0x80034768: jal         0x800348DC
    // 0x8003476C: nop

    func_800348DC(rdram, ctx);
        goto after_3;
    // 0x8003476C: nop

    after_3:
    // 0x80034770: j           L_800347D0
    // 0x80034774: nop

        goto L_800347D0;
    // 0x80034774: nop

L_80034778:
    // 0x80034778: jal         0x80034A6C
    // 0x8003477C: nop

    func_80034A6C(rdram, ctx);
        goto after_4;
    // 0x8003477C: nop

    after_4:
    // 0x80034780: j           L_800347D0
    // 0x80034784: nop

        goto L_800347D0;
    // 0x80034784: nop

L_80034788:
    // 0x80034788: jal         0x80034820
    // 0x8003478C: nop

    func_80034820(rdram, ctx);
        goto after_5;
    // 0x8003478C: nop

    after_5:
    // 0x80034790: j           L_800347D0
    // 0x80034794: nop

        goto L_800347D0;
    // 0x80034794: nop

L_80034798:
    // 0x80034798: jal         0x80034998
    // 0x8003479C: nop

    func_80034998(rdram, ctx);
        goto after_6;
    // 0x8003479C: nop

    after_6:
    // 0x800347A0: j           L_800347D0
    // 0x800347A4: nop

        goto L_800347D0;
    // 0x800347A4: nop

L_800347A8:
    // 0x800347A8: jal         0x800349F0
    // 0x800347AC: nop

    func_800349F0(rdram, ctx);
        goto after_7;
    // 0x800347AC: nop

    after_7:
    // 0x800347B0: j           L_800347D0
    // 0x800347B4: nop

        goto L_800347D0;
    // 0x800347B4: nop

L_800347B8:
    // 0x800347B8: jal         0x80034B3C
    // 0x800347BC: nop

    func_80034B3C(rdram, ctx);
        goto after_8;
    // 0x800347BC: nop

    after_8:
    // 0x800347C0: j           L_800347D0
    // 0x800347C4: nop

        goto L_800347D0;
    // 0x800347C4: nop

L_800347C8:
    // 0x800347C8: jal         0x80033580
    // 0x800347CC: nop

    func_80033580(rdram, ctx);
        goto after_9;
    // 0x800347CC: nop

    after_9:
L_800347D0:
    // 0x800347D0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800347D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800347D8: jr          $ra
    // 0x800347DC: nop

    return;
    // 0x800347DC: nop

;}
RECOMP_FUNC void func_800347E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800347E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800347E4: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    // 0x800347E8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800347EC: sh          $v0, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r2;
    // 0x800347F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800347F4: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    // 0x800347F8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800347FC: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80034800: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80034804: addiu       $a1, $a1, 0x94C
    ctx->r5 = ADD32(ctx->r5, 0X94C);
    // 0x80034808: jal         0x800249B4
    // 0x8003480C: nop

    func_800249B4(rdram, ctx);
        goto after_0;
    // 0x8003480C: nop

    after_0:
    // 0x80034810: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80034814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034818: jr          $ra
    // 0x8003481C: nop

    return;
    // 0x8003481C: nop

;}
RECOMP_FUNC void func_80034820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034824: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80034828: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003482C: lhu         $v0, 0x20($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X20);
    // 0x80034830: beq         $v0, $zero, L_80034848
    if (ctx->r2 == 0) {
        // 0x80034834: nop
    
            goto L_80034848;
    }
    // 0x80034834: nop

    // 0x80034838: jal         0x8003336C
    // 0x8003483C: nop

    func_8003336C(rdram, ctx);
        goto after_0;
    // 0x8003483C: nop

    after_0:
    // 0x80034840: j           L_8003488C
    // 0x80034844: nop

        goto L_8003488C;
    // 0x80034844: nop

L_80034848:
    // 0x80034848: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x8003484C: beq         $v0, $zero, L_8003486C
    if (ctx->r2 == 0) {
        // 0x80034850: nop
    
            goto L_8003486C;
    }
    // 0x80034850: nop

    // 0x80034854: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80034858: addiu       $a0, $a0, 0x97C
    ctx->r4 = ADD32(ctx->r4, 0X97C);
    // 0x8003485C: jal         0x80036798
    // 0x80034860: nop

    func_80036798(rdram, ctx);
        goto after_1;
    // 0x80034860: nop

    after_1:
    // 0x80034864: j           L_8003488C
    // 0x80034868: nop

        goto L_8003488C;
    // 0x80034868: nop

L_8003486C:
    // 0x8003486C: lhu         $v0, 0x14($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X14);
    // 0x80034870: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80034874: sh          $v0, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r2;
    // 0x80034878: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003487C: bgez        $v0, L_8003488C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80034880: nop
    
            goto L_8003488C;
    }
    // 0x80034880: nop

    // 0x80034884: jal         0x8003489C
    // 0x80034888: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_8003489C(rdram, ctx);
        goto after_2;
    // 0x80034888: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_2:
L_8003488C:
    // 0x8003488C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80034890: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034894: jr          $ra
    // 0x80034898: nop

    return;
    // 0x80034898: nop

;}
RECOMP_FUNC void func_8003489C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003489C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800348A0: addiu       $v0, $zero, 0x141
    ctx->r2 = ADD32(0, 0X141);
    // 0x800348A4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800348A8: sh          $v0, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r2;
    // 0x800348AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800348B0: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    // 0x800348B4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800348B8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x800348BC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800348C0: addiu       $a0, $a0, 0x958
    ctx->r4 = ADD32(ctx->r4, 0X958);
    // 0x800348C4: jal         0x80037DDC
    // 0x800348C8: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800348C8: nop

    after_0:
    // 0x800348CC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800348D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800348D4: jr          $ra
    // 0x800348D8: nop

    return;
    // 0x800348D8: nop

;}
RECOMP_FUNC void func_800348DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800348DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800348E0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800348E4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800348E8: lhu         $v0, 0x20($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X20);
    // 0x800348EC: beq         $v0, $zero, L_80034904
    if (ctx->r2 == 0) {
        // 0x800348F0: nop
    
            goto L_80034904;
    }
    // 0x800348F0: nop

    // 0x800348F4: jal         0x8003336C
    // 0x800348F8: nop

    func_8003336C(rdram, ctx);
        goto after_0;
    // 0x800348F8: nop

    after_0:
    // 0x800348FC: j           L_80034948
    // 0x80034900: nop

        goto L_80034948;
    // 0x80034900: nop

L_80034904:
    // 0x80034904: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x80034908: beq         $v0, $zero, L_80034928
    if (ctx->r2 == 0) {
        // 0x8003490C: nop
    
            goto L_80034928;
    }
    // 0x8003490C: nop

    // 0x80034910: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80034914: addiu       $a0, $a0, 0x97C
    ctx->r4 = ADD32(ctx->r4, 0X97C);
    // 0x80034918: jal         0x80036798
    // 0x8003491C: nop

    func_80036798(rdram, ctx);
        goto after_1;
    // 0x8003491C: nop

    after_1:
    // 0x80034920: j           L_80034948
    // 0x80034924: nop

        goto L_80034948;
    // 0x80034924: nop

L_80034928:
    // 0x80034928: lhu         $v0, 0x14($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X14);
    // 0x8003492C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80034930: sh          $v0, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r2;
    // 0x80034934: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80034938: bgez        $v0, L_80034948
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003493C: nop
    
            goto L_80034948;
    }
    // 0x8003493C: nop

    // 0x80034940: jal         0x80034958
    // 0x80034944: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_80034958(rdram, ctx);
        goto after_2;
    // 0x80034944: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_2:
L_80034948:
    // 0x80034948: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003494C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034950: jr          $ra
    // 0x80034954: nop

    return;
    // 0x80034954: nop

;}
RECOMP_FUNC void func_80034958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003495C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80034960: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80034964: sh          $v0, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r2;
    // 0x80034968: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8003496C: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    // 0x80034970: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80034974: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80034978: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8003497C: addiu       $a0, $a0, 0x964
    ctx->r4 = ADD32(ctx->r4, 0X964);
    // 0x80034980: jal         0x80037DDC
    // 0x80034984: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x80034984: nop

    after_0:
    // 0x80034988: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003498C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034990: jr          $ra
    // 0x80034994: nop

    return;
    // 0x80034994: nop

;}
RECOMP_FUNC void func_80034998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034998: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003499C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80034998 falls into func_800349A0
    func_800349A0(rdram, ctx);
;}
RECOMP_FUNC void func_800349A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800349A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800349A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800349A8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800349AC: lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
    // 0x800349B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800349B4: jal         0x80033514
    // 0x800349B8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    func_80033514(rdram, ctx);
        goto after_0;
    // 0x800349B8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    after_0:
    // 0x800349BC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800349C0: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x800349C4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800349C8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x800349CC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800349D0: addiu       $a0, $a0, 0x988
    ctx->r4 = ADD32(ctx->r4, 0X988);
    // 0x800349D4: jal         0x80037DDC
    // 0x800349D8: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x800349D8: nop

    after_1:
    // 0x800349DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800349E0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800349E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800349E8: jr          $ra
    // 0x800349EC: nop

    return;
    // 0x800349EC: nop

;}
RECOMP_FUNC void func_800349F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800349F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800349F4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800349F8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800349FC: lhu         $v0, 0x20($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X20);
    // 0x80034A00: beq         $v0, $zero, L_80034A18
    if (ctx->r2 == 0) {
        // 0x80034A04: nop
    
            goto L_80034A18;
    }
    // 0x80034A04: nop

    // 0x80034A08: jal         0x8003336C
    // 0x80034A0C: nop

    func_8003336C(rdram, ctx);
        goto after_0;
    // 0x80034A0C: nop

    after_0:
    // 0x80034A10: j           L_80034A5C
    // 0x80034A14: nop

        goto L_80034A5C;
    // 0x80034A14: nop

L_80034A18:
    // 0x80034A18: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x80034A1C: beq         $v0, $zero, L_80034A3C
    if (ctx->r2 == 0) {
        // 0x80034A20: nop
    
            goto L_80034A3C;
    }
    // 0x80034A20: nop

    // 0x80034A24: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80034A28: addiu       $a0, $a0, 0x97C
    ctx->r4 = ADD32(ctx->r4, 0X97C);
    // 0x80034A2C: jal         0x80036798
    // 0x80034A30: nop

    func_80036798(rdram, ctx);
        goto after_1;
    // 0x80034A30: nop

    after_1:
    // 0x80034A34: j           L_80034A5C
    // 0x80034A38: nop

        goto L_80034A5C;
    // 0x80034A38: nop

L_80034A3C:
    // 0x80034A3C: lhu         $v0, 0x14($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X14);
    // 0x80034A40: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80034A44: sh          $v0, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r2;
    // 0x80034A48: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80034A4C: bgez        $v0, L_80034A5C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80034A50: nop
    
            goto L_80034A5C;
    }
    // 0x80034A50: nop

    // 0x80034A54: jal         0x80034998
    // 0x80034A58: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_80034998(rdram, ctx);
        goto after_2;
    // 0x80034A58: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_2:
L_80034A5C:
    // 0x80034A5C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80034A60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034A64: jr          $ra
    // 0x80034A68: nop

    return;
    // 0x80034A68: nop

;}
RECOMP_FUNC void func_80034A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034A6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80034A70: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80034A74: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80034A78: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80034A7C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80034A80: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    // 0x80034A84: beq         $v0, $zero, L_80034A9C
    if (ctx->r2 == 0) {
        // 0x80034A88: nop
    
            goto L_80034A9C;
    }
    // 0x80034A88: nop

    // 0x80034A8C: jal         0x8003336C
    // 0x80034A90: nop

    func_8003336C(rdram, ctx);
        goto after_0;
    // 0x80034A90: nop

    after_0:
    // 0x80034A94: j           L_80034B24
    // 0x80034A98: nop

        goto L_80034B24;
    // 0x80034A98: nop

L_80034A9C:
    // 0x80034A9C: lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X22);
    // 0x80034AA0: beq         $v0, $zero, L_80034AC0
    if (ctx->r2 == 0) {
        // 0x80034AA4: nop
    
            goto L_80034AC0;
    }
    // 0x80034AA4: nop

    // 0x80034AA8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80034AAC: addiu       $a0, $a0, 0x97C
    ctx->r4 = ADD32(ctx->r4, 0X97C);
    // 0x80034AB0: jal         0x80036798
    // 0x80034AB4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80036798(rdram, ctx);
        goto after_1;
    // 0x80034AB4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80034AB8: j           L_80034B24
    // 0x80034ABC: nop

        goto L_80034B24;
    // 0x80034ABC: nop

L_80034AC0:
    // 0x80034AC0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80034AC4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80034AC8: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80034ACC: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x80034AD0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80034AD4: lw          $a1, 0x3294($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3294);
    // 0x80034AD8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80034ADC: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x80034AE0: jal         0x80034BB4
    // 0x80034AE4: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    func_80034BB4(rdram, ctx);
        goto after_2;
    // 0x80034AE4: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    after_2:
    // 0x80034AE8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80034AEC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80034AF0: bne         $v0, $s1, L_80034B08
    if (ctx->r2 != ctx->r17) {
        // 0x80034AF4: nop
    
            goto L_80034B08;
    }
    // 0x80034AF4: nop

    // 0x80034AF8: jal         0x80033580
    // 0x80034AFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80033580(rdram, ctx);
        goto after_3;
    // 0x80034AFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80034B00: j           L_80034B24
    // 0x80034B04: nop

        goto L_80034B24;
    // 0x80034B04: nop

L_80034B08:
    // 0x80034B08: jal         0x800379E8
    // 0x80034B0C: nop

    func_800379E8(rdram, ctx);
        goto after_4;
    // 0x80034B0C: nop

    after_4:
    // 0x80034B10: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80034B14: bne         $v0, $s1, L_80034B24
    if (ctx->r2 != ctx->r17) {
        // 0x80034B18: nop
    
            goto L_80034B24;
    }
    // 0x80034B18: nop

    // 0x80034B1C: jal         0x80034B88
    // 0x80034B20: nop

    func_80034B88(rdram, ctx);
        goto after_5;
    // 0x80034B20: nop

    after_5:
L_80034B24:
    // 0x80034B24: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80034B28: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80034B2C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80034B30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80034B34: jr          $ra
    // 0x80034B38: nop

    return;
    // 0x80034B38: nop

;}
RECOMP_FUNC void func_80034B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034B40: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80034B44: sh          $zero, 0x14($a0)
    MEM_H(0X14, ctx->r4) = 0;
    // 0x80034B48: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80034B4C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80034B50: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80034B54: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80034B58: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80034B5C: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80034B60: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80034B64: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80034B68: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80034B6C: addiu       $a0, $a0, 0x9AC
    ctx->r4 = ADD32(ctx->r4, 0X9AC);
    // 0x80034B70: jal         0x80037DDC
    // 0x80034B74: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x80034B74: nop

    after_0:
    // 0x80034B78: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80034B7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034B80: jr          $ra
    // 0x80034B84: nop

    return;
    // 0x80034B84: nop

;}
RECOMP_FUNC void func_80034B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034B88: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80034B8C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80034B90: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80034B94: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80034B98: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80034B9C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80034BA0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80034BA4: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x80034BA8: xori        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 ^ 0X10;
    // 0x80034BAC: jr          $ra
    // 0x80034BB0: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    return;
    // 0x80034BB0: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80034BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034BB4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80034BB8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_80034BBC
    func_80034BBC(rdram, ctx);
}
