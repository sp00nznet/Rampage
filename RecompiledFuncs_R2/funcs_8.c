#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_800058E8(uint8_t* rdram, recomp_context* ctx);
void func_800058F8(uint8_t* rdram, recomp_context* ctx);
void func_80005930(uint8_t* rdram, recomp_context* ctx);
void func_80005990(uint8_t* rdram, recomp_context* ctx);
void func_80005998(uint8_t* rdram, recomp_context* ctx);
void func_80005A08(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_800058C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800058C8: j           L_800058F8
    // 0x800058CC: sw          $v0, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r2;
    func_800058F8(rdram, ctx);
    return;
    // 0x800058CC: sw          $v0, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_800058D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800058D0: lhu         $v1, 0xA($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XA);
    // 0x800058D4: beq         $v1, $v0, L_800058E8
    if (ctx->r3 == ctx->r2) {
            func_800058E8(rdram, ctx);
    return;
    }
;}
RECOMP_FUNC void func_800058D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800058D8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x800058DC: sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // FALLTHROUGH: func_800058D8 falls into func_800058E8
    func_800058E8(rdram, ctx);
;}
RECOMP_FUNC void func_800058E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800058E8: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x800058EC: sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // FALLTHROUGH: func_800058E8 falls into func_800058F0
    func_800058F0(rdram, ctx);
;}
RECOMP_FUNC void func_800058F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800058F0: addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
    // 0x800058F4: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // FALLTHROUGH: func_800058F0 falls into func_800058F8
    func_800058F8(rdram, ctx);
;}
RECOMP_FUNC void func_800058F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800058F8: jal         0x800055EC
    // 0x800058FC: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    func_800055EC(rdram, ctx);
        goto after_0;
    // 0x800058FC: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    after_0:
    // FALLTHROUGH: func_800058F8 falls into func_80005900
    func_80005900(rdram, ctx);
;}
RECOMP_FUNC void func_80005900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005900: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80005904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // FALLTHROUGH: func_80005900 falls into func_80005908
    func_80005908(rdram, ctx);
;}
RECOMP_FUNC void func_80005908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005908: jr          $ra
    // 0x8000590C: nop

    return;
    // 0x8000590C: nop

;}
RECOMP_FUNC void func_80005910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005914: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // FALLTHROUGH: func_80005910 falls into func_80005918
    func_80005918(rdram, ctx);
;}
RECOMP_FUNC void func_80005918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005918: lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XC);
    // 0x8000591C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // FALLTHROUGH: func_80005918 falls into func_80005920
    func_80005920(rdram, ctx);
;}
RECOMP_FUNC void func_80005920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005920: bne         $v1, $v0, L_8000593C
    if (ctx->r3 != ctx->r2) {
        // 0x80005924: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            func_80005930(rdram, ctx); return; // was goto L_8000593C
    }
    // 0x80005924: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
;}
RECOMP_FUNC void func_80005928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005928: sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // 0x8000592C: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // FALLTHROUGH: func_80005928 falls into func_80005930
    func_80005930(rdram, ctx);
;}
RECOMP_FUNC void func_80005930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005930: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x80005934: jal         0x800055EC
    func_800055EC(rdram, ctx);
        goto after_0;
    after_0:
    // MERGE: func_80005938 merged for after_X labels
    // 0x80005938: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // 0x8000593C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // FALLTHROUGH: func_80005930 falls into func_80005940
    func_80005940(rdram, ctx);
;}
RECOMP_FUNC void func_80005940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005940: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005944: jr          $ra
    return;
;}
RECOMP_FUNC void func_80005948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005948: nop


    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_8000594C
    func_8000594C(rdram, ctx);
}
RECOMP_FUNC void func_8000594C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000594C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // FALLTHROUGH: func_8000594C falls into func_80005950
    func_80005950(rdram, ctx);
;}
RECOMP_FUNC void func_80005950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005950: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005954: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // FALLTHROUGH: func_80005950 falls into func_80005958
    func_80005958(rdram, ctx);
;}
RECOMP_FUNC void func_80005958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005958: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8000595C: sh          $v1, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r3;
    // FALLTHROUGH: func_80005958 falls into func_80005960
    func_80005960(rdram, ctx);
;}
RECOMP_FUNC void func_80005960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005960: addiu       $v1, $zero, 0x46
    ctx->r3 = ADD32(0, 0X46);
    // 0x80005964: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // FALLTHROUGH: func_80005960 falls into func_80005968
    func_80005968(rdram, ctx);
;}
RECOMP_FUNC void func_80005968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005968: addiu       $v0, $v0, -0x17
    ctx->r2 = ADD32(ctx->r2, -0X17);
    // 0x8000596C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // FALLTHROUGH: func_80005968 falls into func_80005970
    func_80005970(rdram, ctx);
;}
RECOMP_FUNC void func_80005970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005970: bne         $v0, $zero, L_8000599C
    if (ctx->r2 != 0) {
        // 0x80005974: sh          $v1, 0x8($a1)
        MEM_H(0X8, ctx->r5) = ctx->r3;
            func_80005998(rdram, ctx); return; // was goto L_8000599C
    }
    // 0x80005974: sh          $v1, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r3;
;}
RECOMP_FUNC void func_80005978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005978: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000597C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // FALLTHROUGH: func_80005978 falls into func_80005980
    func_80005980(rdram, ctx);
;}
RECOMP_FUNC void func_80005980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005980: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x80005984: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // FALLTHROUGH: func_80005980 falls into func_80005988
    func_80005988(rdram, ctx);
;}
RECOMP_FUNC void func_80005988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005988: bne         $v0, $zero, L_80005994
    if (ctx->r2 != 0) {
        // 0x8000598C: lui         $v0, 0x2
        ctx->r2 = S32(0X2 << 16);
            func_80005990(rdram, ctx); return; // was goto L_80005994
    }
    // 0x8000598C: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
;}
RECOMP_FUNC void func_80005990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005990: lui         $v0, 0xFFFD
    ctx->r2 = S32(0XFFFD << 16);
    // 0x80005994: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // FALLTHROUGH: func_80005990 falls into func_80005998
    func_80005998(rdram, ctx);
;}
RECOMP_FUNC void func_80005998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005998: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8000599C: jal         0x800055EC
    func_800055EC(rdram, ctx);
        goto after_0;
    after_0:
    // MERGE: func_800059A0 merged for after_X labels
    // 0x800059A0: nop

    // 0x800059A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // FALLTHROUGH: func_80005998 falls into func_800059A8
    func_800059A8(rdram, ctx);
;}
RECOMP_FUNC void func_800059A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800059A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800059AC: jr          $ra
    return;
;}
RECOMP_FUNC void func_800059B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800059B0: nop

;}
RECOMP_FUNC void func_800059B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800059B4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // FALLTHROUGH: func_800059B4 falls into func_800059B8
    func_800059B8(rdram, ctx);
;}
RECOMP_FUNC void func_800059B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800059B8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // FALLTHROUGH: func_800059B8 falls into func_800059BC
    func_800059BC(rdram, ctx);
;}
RECOMP_FUNC void func_800059BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800059BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // FALLTHROUGH: func_800059BC falls into func_800059C0
    func_800059C0(rdram, ctx);
;}
RECOMP_FUNC void func_800059C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800059C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800059C4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // FALLTHROUGH: func_800059C0 falls into func_800059C8
    func_800059C8(rdram, ctx);
;}
RECOMP_FUNC void func_800059C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800059C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800059CC: sw          $zero, 0x31EC($at)
    MEM_W(0X31EC, ctx->r1) = 0;
    // FALLTHROUGH: func_800059C8 falls into func_800059D0
    func_800059D0(rdram, ctx);
;}
RECOMP_FUNC void func_800059D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800059D0: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x800059D4: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // FALLTHROUGH: func_800059D0 falls into func_800059D8
    func_800059D8(rdram, ctx);
;}
RECOMP_FUNC void func_800059D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800059D8: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x800059DC: beq         $v0, $zero, L_80005A08
    if (ctx->r2 == 0) {
            func_80005A08(rdram, ctx);
    return;
    }
;}
RECOMP_FUNC void func_800059E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800059E0: nop

    // 0x800059E4: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // FALLTHROUGH: func_800059E0 falls into func_800059E8
    func_800059E8(rdram, ctx);
;}
RECOMP_FUNC void func_800059E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800059E8: lui         $v0, 0xFFFD
    ctx->r2 = S32(0XFFFD << 16);
    // 0x800059EC: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // FALLTHROUGH: func_800059E8 falls into func_800059F0
    func_800059F0(rdram, ctx);
;}
RECOMP_FUNC void func_800059F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800059F0: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800059F4: beql        $v0, $zero, L_80005A08
    if (ctx->r2 == 0) {
            func_80005A08(rdram, ctx);
    return;
    }
;}
RECOMP_FUNC void func_800059F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800059F8: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x800059FC: lui         $a1, 0xFFFD
    ctx->r5 = S32(0XFFFD << 16);
    // FALLTHROUGH: func_800059F8 falls into func_80005A00
    func_80005A00(rdram, ctx);
;}
RECOMP_FUNC void func_80005A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005A00: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80005A04: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // FALLTHROUGH: func_80005A00 falls into func_80005A08
    func_80005A08(rdram, ctx);
;}
RECOMP_FUNC void func_80005A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005A08: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80005A0C: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // FALLTHROUGH: func_80005A08 falls into func_80005A10
    func_80005A10(rdram, ctx);
;}
RECOMP_FUNC void func_80005A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005A10: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80005A14: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // FALLTHROUGH: func_80005A10 falls into func_80005A18
    func_80005A18(rdram, ctx);
;}
RECOMP_FUNC void func_80005A18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005A18: lw          $v1, 0x3294($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3294);
    // 0x80005A1C: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // FALLTHROUGH: func_80005A18 falls into func_80005A20
    func_80005A20(rdram, ctx);
;}
RECOMP_FUNC void func_80005A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005A20: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80005A24: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // FALLTHROUGH: func_80005A20 falls into func_80005A28
    func_80005A28(rdram, ctx);
;}
RECOMP_FUNC void func_80005A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005A28: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80005A2C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // FALLTHROUGH: func_80005A28 falls into func_80005A30
    func_80005A30(rdram, ctx);
;}
RECOMP_FUNC void func_80005A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005A30: lhu         $v0, 0x6C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6C);
    // 0x80005A34: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // FALLTHROUGH: func_80005A30 falls into func_80005A38
    func_80005A38(rdram, ctx);
;}
RECOMP_FUNC void func_80005A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005A38: beq         $v0, $zero, L_80005A80
    if (ctx->r2 == 0) {
            // 0x80005A3C: nop

    func_80005A80(rdram, ctx);
    return;
    }
    // 0x80005A3C: nop

;}
RECOMP_FUNC void func_80005A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005A40: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x80005A44: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
;}
