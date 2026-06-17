#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_80005DC8(uint8_t* rdram, recomp_context* ctx);
void func_80005DD8(uint8_t* rdram, recomp_context* ctx);
void func_80005E10(uint8_t* rdram, recomp_context* ctx);
void func_80005E28(uint8_t* rdram, recomp_context* ctx);
void func_80005E58(uint8_t* rdram, recomp_context* ctx);
void func_80005E78(uint8_t* rdram, recomp_context* ctx);
void func_80005EEC(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80005D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D98: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80005D9C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80005D98 falls into func_80005DA0
    func_80005DA0(rdram, ctx);
;}
RECOMP_FUNC void func_80005DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005DA0: lh          $a2, 0x14($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X14);
    // 0x80005DA4: lh          $v1, 0x14($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X14);
    // FALLTHROUGH: func_80005DA0 falls into func_80005DA8
    func_80005DA8(rdram, ctx);
;}
RECOMP_FUNC void func_80005DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005DA8: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x80005DAC: subu        $v0, $a2, $v1
    ctx->r2 = SUB32(ctx->r6, ctx->r3);
    // FALLTHROUGH: func_80005DA8 falls into func_80005DB0
    func_80005DB0(rdram, ctx);
;}
RECOMP_FUNC void func_80005DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005DB0: bltz        $v0, L_80005DCC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80005DB4: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            func_80005DC8(rdram, ctx); return; // was goto L_80005DCC
    }
    // 0x80005DB4: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
;}
RECOMP_FUNC void func_80005DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005DB8: slti        $v0, $v0, 0x1C3
    ctx->r2 = SIGNED(ctx->r2) < 0X1C3 ? 1 : 0;
    // 0x80005DBC: beq         $v0, $zero, L_80005DDC
    if (ctx->r2 == 0) {
                func_80005DD8(rdram, ctx); return; // was goto L_80005DDC
    }
;}
RECOMP_FUNC void func_80005DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005DC0: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80005DC4: j           L_80005E28
    func_80005E28(rdram, ctx);
    return;
;}
RECOMP_FUNC void func_80005DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005DC8: nop

    // 0x80005DCC: subu        $v0, $v1, $a2
    ctx->r2 = SUB32(ctx->r3, ctx->r6);
    // FALLTHROUGH: func_80005DC8 falls into func_80005DD0
    func_80005DD0(rdram, ctx);
;}
RECOMP_FUNC void func_80005DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005DD0: slti        $v0, $v0, 0x1C3
    ctx->r2 = SIGNED(ctx->r2) < 0X1C3 ? 1 : 0;
    // 0x80005DD4: bne         $v0, $zero, L_80005E28
    if (ctx->r2 != 0) {
            func_80005E28(rdram, ctx);
    return;
    }
;}
RECOMP_FUNC void func_80005DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005DD8: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80005DDC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // FALLTHROUGH: func_80005DD8 falls into func_80005DE0
    func_80005DE0(rdram, ctx);
;}
RECOMP_FUNC void func_80005DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005DE0: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x80005DE4: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // FALLTHROUGH: func_80005DE0 falls into func_80005DE8
    func_80005DE8(rdram, ctx);
;}
RECOMP_FUNC void func_80005DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005DE8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80005DEC: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // FALLTHROUGH: func_80005DE8 falls into func_80005DF0
    func_80005DF0(rdram, ctx);
;}
RECOMP_FUNC void func_80005DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005DF0: bne         $v1, $zero, L_80005E10
    if (ctx->r3 != 0) {
            // 0x80005DF4: nop

    func_80005E10(rdram, ctx);
    return;
    }
    // 0x80005DF4: nop

;}
RECOMP_FUNC void func_80005DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005DF8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80005DFC: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // FALLTHROUGH: func_80005DF8 falls into func_80005E00
    func_80005E00(rdram, ctx);
;}
RECOMP_FUNC void func_80005E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E00: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80005E04: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // FALLTHROUGH: func_80005E00 falls into func_80005E10
    func_80005E10(rdram, ctx);
;}
RECOMP_FUNC void func_80005E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E10: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80005E14: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // FALLTHROUGH: func_80005E10 falls into func_80005E18
    func_80005E18(rdram, ctx);
;}
RECOMP_FUNC void func_80005E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80005E1C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // FALLTHROUGH: func_80005E18 falls into func_80005E20
    func_80005E20(rdram, ctx);
;}
RECOMP_FUNC void func_80005E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E20: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80005E24: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // FALLTHROUGH: func_80005E20 falls into func_80005E28
    func_80005E28(rdram, ctx);
;}
RECOMP_FUNC void func_80005E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E28: sra         $a1, $v0, 16
    ctx->r5 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80005E2C: addiu       $v0, $a1, -0xE
    ctx->r2 = ADD32(ctx->r5, -0XE);
    // FALLTHROUGH: func_80005E28 falls into func_80005E30
    func_80005E30(rdram, ctx);
;}
RECOMP_FUNC void func_80005E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E30: sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4 << 16);
    // 0x80005E34: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // FALLTHROUGH: func_80005E30 falls into func_80005E38
    func_80005E38(rdram, ctx);
;}
RECOMP_FUNC void func_80005E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E38: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80005E3C: beq         $v0, $zero, L_80005E5C
    if (ctx->r2 == 0) {
                func_80005E58(rdram, ctx); return; // was goto L_80005E5C
    }
;}
RECOMP_FUNC void func_80005E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E40: slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80005E44: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // FALLTHROUGH: func_80005E40 falls into func_80005E48
    func_80005E48(rdram, ctx);
;}
RECOMP_FUNC void func_80005E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E48: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80005E4C: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // FALLTHROUGH: func_80005E48 falls into func_80005E50
    func_80005E50(rdram, ctx);
;}
RECOMP_FUNC void func_80005E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E50: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80005E54: bne         $v0, $zero, L_80005E7C
    if (ctx->r2 != 0) {
                func_80005E78(rdram, ctx); return; // was goto L_80005E7C
    }
;}
RECOMP_FUNC void func_80005E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E58: slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80005E5C: beq         $v0, $zero, L_80005E84
    if (ctx->r2 == 0) {
                func_80005E78(rdram, ctx); return; // was goto L_80005E84
    }
;}
RECOMP_FUNC void func_80005E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E60: nop

    // 0x80005E64: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // FALLTHROUGH: func_80005E60 falls into func_80005E68
    func_80005E68(rdram, ctx);
;}
RECOMP_FUNC void func_80005E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E68: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80005E6C: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // FALLTHROUGH: func_80005E68 falls into func_80005E70
    func_80005E70(rdram, ctx);
;}
RECOMP_FUNC void func_80005E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E70: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80005E74: bne         $v0, $zero, L_80005E84
    if (ctx->r2 != 0) {
                func_80005E78(rdram, ctx); return; // was goto L_80005E84
    }
;}
RECOMP_FUNC void func_80005E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E78: nop

    // 0x80005E7C: jal         0x80046288
    func_80046288(rdram, ctx);
        goto after_0;
    after_0:
    // MERGE: func_80005E80 merged for after_X labels
    // 0x80005E80: nop

    // 0x80005E84: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // FALLTHROUGH: func_80005E78 falls into func_80005E88
    func_80005E88(rdram, ctx);
;}
RECOMP_FUNC void func_80005E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80005E8C: jr          $ra
    // 0x80005E90: nop

    return;
    // 0x80005E90: nop

;}
RECOMP_FUNC void func_80005E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // FALLTHROUGH: func_80005E94 falls into func_80005E98
    func_80005E98(rdram, ctx);
;}
RECOMP_FUNC void func_80005E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E98: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005E9C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // FALLTHROUGH: func_80005E98 falls into func_80005EA0
    func_80005EA0(rdram, ctx);
;}
RECOMP_FUNC void func_80005EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005EA0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80005EA4: addiu       $a0, $a0, 0x18A4
    ctx->r4 = ADD32(ctx->r4, 0X18A4);
    // FALLTHROUGH: func_80005EA0 falls into func_80005EA8
    func_80005EA8(rdram, ctx);
;}
RECOMP_FUNC void func_80005EA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005EA8: jal         0x80005EEC
    // 0x80005EAC: nop

    func_80005EEC(rdram, ctx);
        goto after_0;
    // 0x80005EAC: nop

    after_0:
;}
RECOMP_FUNC void func_80005EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005EB0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80005EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // FALLTHROUGH: func_80005EB0 falls into func_80005EB8
    func_80005EB8(rdram, ctx);
;}
RECOMP_FUNC void func_80005EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005EB8: jr          $ra
    // 0x80005EBC: nop

    return;
    // 0x80005EBC: nop

;}
RECOMP_FUNC void func_80005EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005EC4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // FALLTHROUGH: func_80005EC0 falls into func_80005EC8
    func_80005EC8(rdram, ctx);
;}
RECOMP_FUNC void func_80005EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005EC8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80005ECC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // FALLTHROUGH: func_80005EC8 falls into func_80005ED0
    func_80005ED0(rdram, ctx);
;}
RECOMP_FUNC void func_80005ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005ED0: addiu       $a0, $a0, 0x184C
    ctx->r4 = ADD32(ctx->r4, 0X184C);
    // 0x80005ED4: jal         0x80005EEC
    func_80005EEC(rdram, ctx);
        goto after_0;
    after_0:
    // MERGE: func_80005ED8 merged for after_X labels
    // 0x80005ED8: nop

    // 0x80005EDC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // FALLTHROUGH: func_80005ED0 falls into func_80005EE0
    func_80005EE0(rdram, ctx);
;}
RECOMP_FUNC void func_80005EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005EE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005EE4: jr          $ra
    return;
;}
RECOMP_FUNC void func_80005EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005EE8: nop


    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_80005EEC
    func_80005EEC(rdram, ctx);
}
RECOMP_FUNC void func_80005EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005EEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // FALLTHROUGH: func_80005EEC falls into func_80005EF0
    func_80005EF0(rdram, ctx);
;}
RECOMP_FUNC void func_80005EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005EF0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80005EF4: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // FALLTHROUGH: func_80005EF0 falls into func_80005EF8
    func_80005EF8(rdram, ctx);
;}
RECOMP_FUNC void func_80005EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005EF8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80005EFC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // FALLTHROUGH: func_80005EF8 falls into func_80005F00
    func_80005F00(rdram, ctx);
;}
RECOMP_FUNC void func_80005F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005F00: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x80005F04: addiu       $v0, $zero, 0x36
    ctx->r2 = ADD32(0, 0X36);
    // FALLTHROUGH: func_80005F00 falls into func_80005F08
    func_80005F08(rdram, ctx);
;}
RECOMP_FUNC void func_80005F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005F08: beq         $v1, $v0, L_80005FE0
    if (ctx->r3 == ctx->r2) {
            // 0x80005F0C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    func_80005FE0(rdram, ctx);
    return;
    }
    // 0x80005F0C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void func_80005F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005F10: slti        $v0, $v1, 0x37
    ctx->r2 = SIGNED(ctx->r3) < 0X37 ? 1 : 0;
    // 0x80005F14: beq         $v0, $zero, L_80005F60
    if (ctx->r2 == 0) {
            func_80005F60(rdram, ctx);
    return;
    }
;}
RECOMP_FUNC void func_80005F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005F18: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x80005F1C: beq         $v1, $v0, L_80006008
    if (ctx->r3 == ctx->r2) {
            func_80006008(rdram, ctx);
    return;
    }
;}
RECOMP_FUNC void func_80005F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005F20: slti        $v0, $v1, 0x1F
    ctx->r2 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
    // 0x80005F24: beq         $v0, $zero, L_80005F44
    if (ctx->r2 == 0) {
                func_80005F40(rdram, ctx); return; // was goto L_80005F44
    }
;}
