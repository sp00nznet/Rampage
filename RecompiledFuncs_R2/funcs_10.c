#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_80005C48(uint8_t* rdram, recomp_context* ctx);
void func_80005C78(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80005BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005BE8: j           L_80005C0C
    // 0x80005BEC: sh          $v0, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r2;
        goto L_80005C0C;
    // 0x80005BEC: sh          $v0, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r2;
    // 0x80005BF0: lhu         $v1, 0xA($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0XA);
    // 0x80005BF4: beq         $v1, $v0, L_80005C0C
    if (ctx->r3 == ctx->r2) {
        // 0x80005BF8: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_80005C0C;
    }
    // 0x80005BF8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80005BFC: sh          $v0, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r2;
    // 0x80005C00: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x80005C04: jal         0x800055EC
    // 0x80005C08: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    func_800055EC(rdram, ctx);
        goto after_0;
    // 0x80005C08: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    after_0:
L_80005C0C:
    // 0x80005C0C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80005C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005C14: jr          $ra
    // 0x80005C18: nop

    return;
    // 0x80005C18: nop

;}
RECOMP_FUNC void func_80005C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // FALLTHROUGH: func_80005C1C falls into func_80005C20
    func_80005C20(rdram, ctx);
;}
RECOMP_FUNC void func_80005C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C20: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005C24: lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XC);
    // FALLTHROUGH: func_80005C20 falls into func_80005C28
    func_80005C28(rdram, ctx);
;}
RECOMP_FUNC void func_80005C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80005C2C: bne         $v1, $v0, L_80005C48
    if (ctx->r3 != ctx->r2) {
            func_80005C48(rdram, ctx);
    return;
    }
;}
RECOMP_FUNC void func_80005C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C30: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x80005C34: sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // FALLTHROUGH: func_80005C30 falls into func_80005C38
    func_80005C38(rdram, ctx);
;}
RECOMP_FUNC void func_80005C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C38: addiu       $v0, $zero, 0x4C
    ctx->r2 = ADD32(0, 0X4C);
    // 0x80005C3C: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // FALLTHROUGH: func_80005C38 falls into func_80005C40
    func_80005C40(rdram, ctx);
;}
RECOMP_FUNC void func_80005C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C40: jal         0x800055EC
    // 0x80005C44: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    func_800055EC(rdram, ctx);
        goto after_0;
    // 0x80005C44: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    after_0:
    // FALLTHROUGH: func_80005C40 falls into func_80005C48
    func_80005C48(rdram, ctx);
;}
RECOMP_FUNC void func_80005C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C48: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80005C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // FALLTHROUGH: func_80005C48 falls into func_80005C50
    func_80005C50(rdram, ctx);
;}
RECOMP_FUNC void func_80005C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C50: jr          $ra
    // 0x80005C54: nop

    return;
    // 0x80005C54: nop

;}
RECOMP_FUNC void func_80005C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005C5C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // FALLTHROUGH: func_80005C58 falls into func_80005C60
    func_80005C60(rdram, ctx);
;}
RECOMP_FUNC void func_80005C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C60: lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XC);
    // 0x80005C64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // FALLTHROUGH: func_80005C60 falls into func_80005C68
    func_80005C68(rdram, ctx);
;}
RECOMP_FUNC void func_80005C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C68: bne         $v1, $v0, L_80005C84
    if (ctx->r3 != ctx->r2) {
        // 0x80005C6C: addiu       $v0, $zero, 0x13
        ctx->r2 = ADD32(0, 0X13);
            func_80005C78(rdram, ctx); return; // was goto L_80005C84
    }
    // 0x80005C6C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
;}
RECOMP_FUNC void func_80005C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C70: sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // 0x80005C74: addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
    // FALLTHROUGH: func_80005C70 falls into func_80005C78
    func_80005C78(rdram, ctx);
;}
RECOMP_FUNC void func_80005C78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C78: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x80005C7C: jal         0x800055EC
    func_800055EC(rdram, ctx);
        goto after_0;
    after_0:
    // MERGE: func_80005C80 merged for after_X labels
    // 0x80005C80: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // 0x80005C84: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // FALLTHROUGH: func_80005C78 falls into func_80005C88
    func_80005C88(rdram, ctx);
;}
RECOMP_FUNC void func_80005C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005C8C: jr          $ra
    return;
;}
RECOMP_FUNC void func_80005C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C90: nop


    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_80005C94
    func_80005C94(rdram, ctx);
}
RECOMP_FUNC void func_80005C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // FALLTHROUGH: func_80005C94 falls into func_80005C98
    func_80005C98(rdram, ctx);
;}
RECOMP_FUNC void func_80005C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C98: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005C9C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // FALLTHROUGH: func_80005C98 falls into func_80005CA0
    func_80005CA0(rdram, ctx);
;}
RECOMP_FUNC void func_80005CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CA0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80005CA4: addiu       $a0, $a0, 0x1490
    ctx->r4 = ADD32(ctx->r4, 0X1490);
    // FALLTHROUGH: func_80005CA0 falls into func_80005CA8
    func_80005CA8(rdram, ctx);
;}
RECOMP_FUNC void func_80005CA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CA8: jal         0x80005230
    // 0x80005CAC: nop

    func_80005230(rdram, ctx);
        goto after_0;
    // 0x80005CAC: nop

    after_0:
;}
RECOMP_FUNC void func_80005CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CB0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80005CB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // FALLTHROUGH: func_80005CB0 falls into func_80005CB8
    func_80005CB8(rdram, ctx);
;}
RECOMP_FUNC void func_80005CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CB8: jr          $ra
    // 0x80005CBC: nop

    return;
    // 0x80005CBC: nop

;}
RECOMP_FUNC void func_80005CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005CC4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005CC8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80005CCC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // FALLTHROUGH: func_80005CC0 falls into func_80005CD0
    func_80005CD0(rdram, ctx);
;}
RECOMP_FUNC void func_80005CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CD0: addiu       $a0, $a0, 0x1540
    ctx->r4 = ADD32(ctx->r4, 0X1540);
    // 0x80005CD4: jal         0x80005230
    func_80005230(rdram, ctx);
        goto after_0;
    after_0:
    // MERGE: func_80005CD8 merged for after_X labels
    // 0x80005CD8: nop

    // 0x80005CDC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // FALLTHROUGH: func_80005CD0 falls into func_80005CE0
    func_80005CE0(rdram, ctx);
;}
RECOMP_FUNC void func_80005CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005CE4: jr          $ra
    return;
;}
RECOMP_FUNC void func_80005CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CE8: nop


    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_80005CEC
    func_80005CEC(rdram, ctx);
}
RECOMP_FUNC void func_80005CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // FALLTHROUGH: func_80005CEC falls into func_80005CF0
    func_80005CF0(rdram, ctx);
;}
RECOMP_FUNC void func_80005CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CF0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005CF4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // FALLTHROUGH: func_80005CF0 falls into func_80005CF8
    func_80005CF8(rdram, ctx);
;}
RECOMP_FUNC void func_80005CF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CF8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80005CFC: addiu       $a0, $a0, 0x1598
    ctx->r4 = ADD32(ctx->r4, 0X1598);
    // FALLTHROUGH: func_80005CF8 falls into func_80005D00
    func_80005D00(rdram, ctx);
;}
RECOMP_FUNC void func_80005D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D00: jal         0x80005230
    // 0x80005D04: nop

    func_80005230(rdram, ctx);
        goto after_0;
    // 0x80005D04: nop

    after_0:
;}
RECOMP_FUNC void func_80005D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D08: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80005D0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // FALLTHROUGH: func_80005D08 falls into func_80005D10
    func_80005D10(rdram, ctx);
;}
RECOMP_FUNC void func_80005D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D10: jr          $ra
    // 0x80005D14: nop

    return;
    // 0x80005D14: nop

;}
RECOMP_FUNC void func_80005D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005D1C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // FALLTHROUGH: func_80005D18 falls into func_80005D20
    func_80005D20(rdram, ctx);
;}
RECOMP_FUNC void func_80005D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D20: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80005D24: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // FALLTHROUGH: func_80005D20 falls into func_80005D28
    func_80005D28(rdram, ctx);
;}
RECOMP_FUNC void func_80005D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D28: addiu       $a0, $a0, 0x1750
    ctx->r4 = ADD32(ctx->r4, 0X1750);
    // 0x80005D2C: jal         0x80005230
    func_80005230(rdram, ctx);
        goto after_0;
    after_0:
    // MERGE: func_80005D30 merged for after_X labels
    // 0x80005D30: nop

    // 0x80005D34: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // FALLTHROUGH: func_80005D28 falls into func_80005D38
    func_80005D38(rdram, ctx);
;}
RECOMP_FUNC void func_80005D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005D3C: jr          $ra
    return;
;}
RECOMP_FUNC void func_80005D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D40: nop


    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_80005D44
    func_80005D44(rdram, ctx);
}
RECOMP_FUNC void func_80005D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // FALLTHROUGH: func_80005D44 falls into func_80005D48
    func_80005D48(rdram, ctx);
;}
RECOMP_FUNC void func_80005D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D48: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005D4C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // FALLTHROUGH: func_80005D48 falls into func_80005D50
    func_80005D50(rdram, ctx);
;}
RECOMP_FUNC void func_80005D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D50: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80005D54: addiu       $a0, $a0, 0x17A8
    ctx->r4 = ADD32(ctx->r4, 0X17A8);
    // FALLTHROUGH: func_80005D50 falls into func_80005D58
    func_80005D58(rdram, ctx);
;}
RECOMP_FUNC void func_80005D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D58: jal         0x80005230
    // 0x80005D5C: nop

    func_80005230(rdram, ctx);
        goto after_0;
    // 0x80005D5C: nop

    after_0:
;}
RECOMP_FUNC void func_80005D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D60: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80005D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // FALLTHROUGH: func_80005D60 falls into func_80005D68
    func_80005D68(rdram, ctx);
;}
RECOMP_FUNC void func_80005D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D68: jr          $ra
    // 0x80005D6C: nop

    return;
    // 0x80005D6C: nop

;}
RECOMP_FUNC void func_80005D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80005D74: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // FALLTHROUGH: func_80005D70 falls into func_80005D78
    func_80005D78(rdram, ctx);
;}
RECOMP_FUNC void func_80005D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D78: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80005D7C: beq         $v0, $zero, L_80005E84
    if (ctx->r2 == 0) {
                func_80005E78(rdram, ctx); return; // was goto L_80005E84
    }
;}
RECOMP_FUNC void func_80005D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D80: nop

    // 0x80005D84: lw          $v1, 0x68($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X68);
    // FALLTHROUGH: func_80005D80 falls into func_80005D88
    func_80005D88(rdram, ctx);
;}
RECOMP_FUNC void func_80005D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D88: bne         $v1, $zero, L_80005D98
    if (ctx->r3 != 0) {
            // 0x80005D8C: nop

    func_80005D98(rdram, ctx);
    return;
    }
    // 0x80005D8C: nop

;}
