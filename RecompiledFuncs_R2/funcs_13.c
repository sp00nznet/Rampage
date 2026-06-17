#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800060D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800060D0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800060D4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // FALLTHROUGH: func_800060D0 falls into func_800060D8
    func_800060D8(rdram, ctx);
;}
RECOMP_FUNC void func_800060D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800060D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800060DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // FALLTHROUGH: func_800060D8 falls into func_800060E0
    func_800060E0(rdram, ctx);
;}
RECOMP_FUNC void func_800060E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800060E0: jr          $ra
    // 0x800060E4: nop

    return;
    // 0x800060E4: nop

;}
RECOMP_FUNC void func_800060E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800060E8: nop

    // 0x800060EC: nop

;}
RECOMP_FUNC void func_800060F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800060F0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800060F4: lw          $v1, 0x4720($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4720);
    // FALLTHROUGH: func_800060F0 falls into func_800060F8
    func_800060F8(rdram, ctx);
;}
RECOMP_FUNC void func_800060F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800060F8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800060FC: lw          $v0, 0x2588($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2588);
    // FALLTHROUGH: func_800060F8 falls into func_80006100
    func_80006100(rdram, ctx);
;}
RECOMP_FUNC void func_80006100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006100: xor         $v0, $v1, $v0
    ctx->r2 = ctx->r3 ^ ctx->r2;
    // 0x80006104: jr          $ra
    return;
;}
RECOMP_FUNC void func_80006108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006108: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // FALLTHROUGH: func_80006108 falls into func_8000610C
    func_8000610C(rdram, ctx);
;}
RECOMP_FUNC void func_8000610C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000610C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // FALLTHROUGH: func_8000610C falls into func_80006110
    func_80006110(rdram, ctx);
;}
RECOMP_FUNC void func_80006110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006110: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // FALLTHROUGH: func_80006110 falls into func_80006118
    func_80006118(rdram, ctx);
;}
RECOMP_FUNC void func_80006118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006118: jal         0x800306EC
    // 0x8000611C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x8000611C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // FALLTHROUGH: func_80006118 falls into func_80006120
    func_80006120(rdram, ctx);
;}
RECOMP_FUNC void func_80006120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006120: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80006124: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // FALLTHROUGH: func_80006120 falls into func_80006128
    func_80006128(rdram, ctx);
;}
RECOMP_FUNC void func_80006128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006128: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000612C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // FALLTHROUGH: func_80006128 falls into func_80006130
    func_80006130(rdram, ctx);
;}
RECOMP_FUNC void func_80006130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006130: lh          $v1, 0x8($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X8);
    // 0x80006134: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // FALLTHROUGH: func_80006130 falls into func_80006138
    func_80006138(rdram, ctx);
;}
RECOMP_FUNC void func_80006138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006138: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x8000613C: lh          $v1, 0xA($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XA);
    // FALLTHROUGH: func_80006138 falls into func_80006140
    func_80006140(rdram, ctx);
;}
RECOMP_FUNC void func_80006140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006140: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80006144: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // FALLTHROUGH: func_80006140 falls into func_80006148
    func_80006148(rdram, ctx);
;}
RECOMP_FUNC void func_80006148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006148: lhu         $v1, 0x6($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6);
    // 0x8000614C: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    // FALLTHROUGH: func_80006148 falls into func_80006150
    func_80006150(rdram, ctx);
;}
RECOMP_FUNC void func_80006150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006150: ori         $v1, $v1, 0x20
    ctx->r3 = ctx->r3 | 0X20;
    // 0x80006154: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // FALLTHROUGH: func_80006150 falls into func_80006158
    func_80006158(rdram, ctx);
;}
RECOMP_FUNC void func_80006158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006158: jal         0x80023E44
    // 0x8000615C: sw          $a0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r4;
    func_80023E44(rdram, ctx);
        goto after_0;
    // 0x8000615C: sw          $a0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r4;
    after_0:
    // FALLTHROUGH: func_80006158 falls into func_80006160
    func_80006160(rdram, ctx);
;}
RECOMP_FUNC void func_80006160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006160: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80006164: lhu         $v1, 0x22($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X22);
    // FALLTHROUGH: func_80006160 falls into func_80006168
    func_80006168(rdram, ctx);
;}
RECOMP_FUNC void func_80006168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006168: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x8000616C: sh          $v1, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r3;
    // FALLTHROUGH: func_80006168 falls into func_80006170
    func_80006170(rdram, ctx);
;}
RECOMP_FUNC void func_80006170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006174: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // FALLTHROUGH: func_80006170 falls into func_80006178
    func_80006178(rdram, ctx);
;}
RECOMP_FUNC void func_80006178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006178: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000617C: jr          $ra
    return;
;}
RECOMP_FUNC void func_80006180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006180: nop


    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_80006184
    func_80006184(rdram, ctx);
}
RECOMP_FUNC void func_80006184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006184: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // FALLTHROUGH: func_80006184 falls into func_80006188
    func_80006188(rdram, ctx);
;}
RECOMP_FUNC void func_80006188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006188: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000618C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // FALLTHROUGH: func_80006188 falls into func_80006190
    func_80006190(rdram, ctx);
;}
RECOMP_FUNC void func_80006190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006190: jal         0x800306EC
    // 0x80006194: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80006194: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // FALLTHROUGH: func_80006190 falls into func_80006198
    func_80006198(rdram, ctx);
;}
RECOMP_FUNC void func_80006198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006198: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8000619C: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // FALLTHROUGH: func_80006198 falls into func_800061A0
    func_800061A0(rdram, ctx);
;}
RECOMP_FUNC void func_800061A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800061A0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800061A4: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // FALLTHROUGH: func_800061A0 falls into func_800061A8
    func_800061A8(rdram, ctx);
;}
RECOMP_FUNC void func_800061A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800061A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800061AC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // FALLTHROUGH: func_800061A8 falls into func_800061B0
    func_800061B0(rdram, ctx);
;}
RECOMP_FUNC void func_800061B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800061B0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800061B4: lh          $v1, 0x4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4);
    // FALLTHROUGH: func_800061B0 falls into func_800061B8
    func_800061B8(rdram, ctx);
;}
RECOMP_FUNC void func_800061B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800061B8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800061BC: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // FALLTHROUGH: func_800061B8 falls into func_800061C0
    func_800061C0(rdram, ctx);
;}
RECOMP_FUNC void func_800061C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800061C0: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    // 0x800061C4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // FALLTHROUGH: func_800061C0 falls into func_800061C8
    func_800061C8(rdram, ctx);
;}
RECOMP_FUNC void func_800061C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800061C8: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x800061CC: lhu         $v1, 0x6($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6);
    // FALLTHROUGH: func_800061C8 falls into func_800061D0
    func_800061D0(rdram, ctx);
;}
RECOMP_FUNC void func_800061D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800061D0: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
    // 0x800061D4: ori         $v1, $v1, 0x20
    ctx->r3 = ctx->r3 | 0X20;
    // FALLTHROUGH: func_800061D0 falls into func_800061D8
    func_800061D8(rdram, ctx);
;}
RECOMP_FUNC void func_800061D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800061D8: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // 0x800061DC: jal         0x80023E44
    func_80023E44(rdram, ctx);
        goto after_0;
    after_0:
    // MERGE: func_800061E0 merged for after_X labels
    // 0x800061E0: sw          $a0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r4;
    // 0x800061E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // FALLTHROUGH: func_800061D8 falls into func_800061E8
    func_800061E8(rdram, ctx);
;}
RECOMP_FUNC void func_800061E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800061E8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800061EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800061F0: jr          $ra
    // 0x800061F4: nop

    return;
    // 0x800061F4: nop

;}
RECOMP_FUNC void func_800061F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800061F8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800061FC: lhu         $v0, 0x4E66($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E66);
    // FALLTHROUGH: func_800061F8 falls into func_80006200
    func_80006200(rdram, ctx);
;}
RECOMP_FUNC void func_80006200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006204: bne         $v0, $zero, L_80006228
    if (ctx->r2 != 0) {
        // 0x80006208: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80006228;
    }
    // 0x80006208: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000620C: jal         0x8005F50C
    // 0x80006210: nop

    func_8005F50C(rdram, ctx);
        goto after_0;
    // 0x80006210: nop

    after_0:
    // 0x80006214: jal         0x8002A218
    // 0x80006218: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002A218(rdram, ctx);
        goto after_1;
    // 0x80006218: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x8000621C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006220: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80006224: sh          $v0, 0x4E66($at)
    MEM_H(0X4E66, ctx->r1) = ctx->r2;
L_80006228:
    // 0x80006228: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000622C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006230: jr          $ra
    // 0x80006234: nop

    return;
    // 0x80006234: nop

;}
RECOMP_FUNC void func_80006238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006238: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x8000623C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80006240: addiu       $v1, $v1, -0x6870
    ctx->r3 = ADD32(ctx->r3, -0X6870);
L_80006244:
    // 0x80006244: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80006248: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x8000624C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80006250: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80006254: bne         $v0, $zero, L_80006244
    if (ctx->r2 != 0) {
        // 0x80006258: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80006244;
    }
    // 0x80006258: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000625C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80006260: sh          $zero, 0x4E20($at)
    MEM_H(0X4E20, ctx->r1) = 0;
    // 0x80006264: jr          $ra
    // 0x80006268: nop

    return;
    // 0x80006268: nop

;}
RECOMP_FUNC void func_8000626C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000626C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80006270: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80006274: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80006278: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000627C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80006280: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80006284: addiu       $s2, $zero, 0xCC
    ctx->r18 = ADD32(0, 0XCC);
    // 0x80006288: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
L_8000628C:
    // 0x8000628C: jal         0x8001F310
    // 0x80006290: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    func_8001F310(rdram, ctx);
        goto after_0;
    // 0x80006290: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    after_0:
    // 0x80006294: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80006298: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000629C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800062A0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800062A4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800062A8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800062AC: addiu       $v0, $v0, 0x3F94
    ctx->r2 = ADD32(ctx->r2, 0X3F94);
    // 0x800062B0: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x800062B4: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800062B8: beql        $v0, $zero, L_800063B8
    if (ctx->r2 == 0) {
        // 0x800062BC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800063B8;
    }
    goto skip_0;
    // 0x800062BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800062C0: lw          $a1, 0xA4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XA4);
    // 0x800062C4: lhu         $v0, 0x20($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X20);
    // 0x800062C8: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x800062CC: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800062D0: beq         $v0, $zero, L_80006310
    if (ctx->r2 == 0) {
        // 0x800062D4: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80006310;
    }
    // 0x800062D4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800062D8: sw          $v0, 0x64($a1)
    MEM_W(0X64, ctx->r5) = ctx->r2;
    // 0x800062DC: lw          $v1, 0xA4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XA4);
    // 0x800062E0: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
    // 0x800062E4: sltiu       $v0, $v0, 0x46
    ctx->r2 = ctx->r2 < 0X46 ? 1 : 0;
    // 0x800062E8: beq         $v0, $zero, L_80006310
    if (ctx->r2 == 0) {
        // 0x800062EC: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80006310;
    }
    // 0x800062EC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800062F0: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x800062F4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800062F8: addiu       $v0, $v0, 0xB
    ctx->r2 = ADD32(ctx->r2, 0XB);
    // 0x800062FC: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x80006300: lw          $v1, 0xA4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XA4);
    // 0x80006304: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
    // 0x80006308: subu        $v0, $s2, $v0
    ctx->r2 = SUB32(ctx->r18, ctx->r2);
    // 0x8000630C: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
L_80006310:
    // 0x80006310: lw          $a1, 0xA8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XA8);
    // 0x80006314: lhu         $v0, 0x24($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X24);
    // 0x80006318: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x8000631C: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80006320: beq         $v0, $zero, L_80006360
    if (ctx->r2 == 0) {
        // 0x80006324: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80006360;
    }
    // 0x80006324: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80006328: sw          $v0, 0x64($a1)
    MEM_W(0X64, ctx->r5) = ctx->r2;
    // 0x8000632C: lw          $v1, 0xA8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XA8);
    // 0x80006330: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
    // 0x80006334: sltiu       $v0, $v0, 0x46
    ctx->r2 = ctx->r2 < 0X46 ? 1 : 0;
    // 0x80006338: beq         $v0, $zero, L_80006360
    if (ctx->r2 == 0) {
        // 0x8000633C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80006360;
    }
    // 0x8000633C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80006340: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x80006344: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80006348: addiu       $v0, $v0, 0xB
    ctx->r2 = ADD32(ctx->r2, 0XB);
    // 0x8000634C: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x80006350: lw          $v1, 0xA8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XA8);
    // 0x80006354: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
    // 0x80006358: subu        $v0, $s2, $v0
    ctx->r2 = SUB32(ctx->r18, ctx->r2);
    // 0x8000635C: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
L_80006360:
    // 0x80006360: lw          $a1, 0xAC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XAC);
    // 0x80006364: lhu         $v0, 0x26($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X26);
    // 0x80006368: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x8000636C: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80006370: beql        $v0, $zero, L_800063B8
    if (ctx->r2 == 0) {
        // 0x80006374: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800063B8;
    }
    goto skip_1;
    // 0x80006374: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80006378: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8000637C: sw          $v0, 0x64($a1)
    MEM_W(0X64, ctx->r5) = ctx->r2;
    // 0x80006380: lw          $v1, 0xAC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XAC);
    // 0x80006384: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
    // 0x80006388: sltiu       $v0, $v0, 0x46
    ctx->r2 = ctx->r2 < 0X46 ? 1 : 0;
    // 0x8000638C: beq         $v0, $zero, L_800063B4
    if (ctx->r2 == 0) {
        // 0x80006390: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800063B4;
    }
    // 0x80006390: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80006394: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x80006398: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000639C: addiu       $v0, $v0, 0xB
    ctx->r2 = ADD32(ctx->r2, 0XB);
    // 0x800063A0: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x800063A4: lw          $v1, 0xAC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XAC);
    // 0x800063A8: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
    // 0x800063AC: subu        $v0, $s2, $v0
    ctx->r2 = SUB32(ctx->r18, ctx->r2);
    // 0x800063B0: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
L_800063B4:
    // 0x800063B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800063B8:
    // 0x800063B8: slti        $v0, $s0, 0x3
    ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x800063BC: bne         $v0, $zero, L_8000628C
    if (ctx->r2 != 0) {
        // 0x800063C0: nop
    
            goto L_8000628C;
    }
    // 0x800063C0: nop

    // 0x800063C4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800063C8: lhu         $v0, -0x68E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X68E0);
    // 0x800063CC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800063D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800063D4: sh          $v0, -0x68E0($at)
    MEM_H(-0X68E0, ctx->r1) = ctx->r2;
    // 0x800063D8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800063DC: bne         $v0, $zero, L_80006404
    if (ctx->r2 != 0) {
        // 0x800063E0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80006404;
    }
    // 0x800063E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800063E4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800063E8: lhu         $v0, 0x4E66($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4E66);
    // 0x800063EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800063F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800063F4: sh          $v0, 0x4E66($at)
    MEM_H(0X4E66, ctx->r1) = ctx->r2;
    // 0x800063F8: jal         0x800246DC
    // 0x800063FC: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    func_800246DC(rdram, ctx);
        goto after_1;
    // 0x800063FC: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_1:
    // 0x80006400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80006404:
    // 0x80006404: bne         $s1, $v0, L_80006554
    if (ctx->r17 != ctx->r2) {
        // 0x80006408: nop
    
            goto L_80006554;
    }
    // 0x80006408: nop

    // 0x8000640C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80006410: lw          $v0, -0x1D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1D70);
    // 0x80006414: bne         $v0, $s1, L_80006554
    if (ctx->r2 != ctx->r17) {
        // 0x80006418: nop
    
            goto L_80006554;
    }
    // 0x80006418: nop

    // 0x8000641C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80006420: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x80006424: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006428: sw          $zero, -0x1D70($at)
    MEM_W(-0X1D70, ctx->r1) = 0;
    // 0x8000642C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80006430: bnel        $v0, $zero, L_80006508
    if (ctx->r2 != 0) {
        // 0x80006434: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80006508;
    }
    goto skip_2;
    // 0x80006434: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    skip_2:
    // 0x80006438: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000643C: lw          $v0, 0x4E60($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4E60);
    // 0x80006440: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80006444: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80006448: bne         $v1, $v0, L_80006494
    if (ctx->r3 != ctx->r2) {
        // 0x8000644C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80006494;
    }
    // 0x8000644C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80006450: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80006454: lh          $v1, -0x1D3C($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X1D3C);
    // 0x80006458: addiu       $v0, $zero, 0x688
    ctx->r2 = ADD32(0, 0X688);
    // 0x8000645C: bne         $v1, $v0, L_80006474
    if (ctx->r3 != ctx->r2) {
        // 0x80006460: addiu       $v0, $zero, 0x68B
        ctx->r2 = ADD32(0, 0X68B);
            goto L_80006474;
    }
    // 0x80006460: addiu       $v0, $zero, 0x68B
    ctx->r2 = ADD32(0, 0X68B);
    // 0x80006464: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80006468: lw          $a0, 0x7748($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7748);
    // 0x8000646C: j           L_800064A4
    // 0x80006470: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
        goto L_800064A4;
    // 0x80006470: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
L_80006474:
    // 0x80006474: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80006478: addiu       $a0, $a0, 0x3450
    ctx->r4 = ADD32(ctx->r4, 0X3450);
    // 0x8000647C: bne         $v1, $v0, L_800064A4
    if (ctx->r3 != ctx->r2) {
        // 0x80006480: addiu       $a1, $zero, 0xC8
        ctx->r5 = ADD32(0, 0XC8);
            goto L_800064A4;
    }
    // 0x80006480: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80006484: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80006488: addiu       $a0, $a0, 0x3448
    ctx->r4 = ADD32(ctx->r4, 0X3448);
    // 0x8000648C: j           L_800064A8
    // 0x80006490: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
        goto L_800064A8;
    // 0x80006490: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
L_80006494:
    // 0x80006494: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80006498: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8000649C: lw          $a0, 0x772C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X772C);
    // 0x800064A0: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
L_800064A4:
    // 0x800064A4: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
L_800064A8:
    // 0x800064A8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800064AC: lh          $v0, 0x5524($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5524);
    // 0x800064B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800064B4: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x800064B8: addiu       $s1, $s1, 0xF20
    ctx->r17 = ADD32(ctx->r17, 0XF20);
    // 0x800064BC: addiu       $s0, $zero, 0x400
    ctx->r16 = ADD32(0, 0X400);
    // 0x800064C0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800064C4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800064C8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800064CC: jal         0x800010CC
    // 0x800064D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_2;
    // 0x800064D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x800064D4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800064D8: addiu       $a0, $a0, 0x345C
    ctx->r4 = ADD32(ctx->r4, 0X345C);
    // 0x800064DC: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x800064E0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800064E4: lh          $v0, 0x5524($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5524);
    // 0x800064E8: addiu       $a2, $zero, 0x8C
    ctx->r6 = ADD32(0, 0X8C);
    // 0x800064EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800064F0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800064F4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800064F8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800064FC: jal         0x800010CC
    // 0x80006500: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_3;
    // 0x80006500: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80006504: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80006508:
    // 0x80006508: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x8000650C: addiu       $s1, $s1, 0x3F94
    ctx->r17 = ADD32(ctx->r17, 0X3F94);
    // 0x80006510: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80006514:
    // 0x80006514: jal         0x8001F310
    // 0x80006518: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001F310(rdram, ctx);
        goto after_4;
    // 0x80006518: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8000651C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80006520: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80006524: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80006528: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8000652C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80006530: addu        $a0, $v1, $s1
    ctx->r4 = ADD32(ctx->r3, ctx->r17);
    // 0x80006534: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80006538: beq         $v0, $zero, L_8000654C
    if (ctx->r2 == 0) {
        // 0x8000653C: slti        $v0, $s0, 0x3
        ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
            goto L_8000654C;
    }
    // 0x8000653C: slti        $v0, $s0, 0x3
    ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80006540: sh          $zero, 0x20($a0)
    MEM_H(0X20, ctx->r4) = 0;
    // 0x80006544: sh          $zero, 0x24($a0)
    MEM_H(0X24, ctx->r4) = 0;
    // 0x80006548: sh          $zero, 0x26($a0)
    MEM_H(0X26, ctx->r4) = 0;
L_8000654C:
    // 0x8000654C: bne         $v0, $zero, L_80006514
    if (ctx->r2 != 0) {
        // 0x80006550: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80006514;
    }
    // 0x80006550: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80006554:
    // 0x80006554: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80006558: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000655C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80006560: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80006564: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80006568: jr          $ra
    // 0x8000656C: nop

    return;
    // 0x8000656C: nop

;}
RECOMP_FUNC void func_80006570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006570: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80006574: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80006578: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8000657C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80006580: addiu       $s5, $zero, 0xCC
    ctx->r21 = ADD32(0, 0XCC);
    // 0x80006584: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80006588: addiu       $s4, $zero, 0x19
    ctx->r20 = ADD32(0, 0X19);
    // 0x8000658C: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80006590: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80006594: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80006598: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000659C: addiu       $s3, $s2, 0x1
    ctx->r19 = ADD32(ctx->r18, 0X1);
L_800065A0:
    // 0x800065A0: jal         0x8001F310
    // 0x800065A4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8001F310(rdram, ctx);
        goto after_0;
    // 0x800065A4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_0:
    // 0x800065A8: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800065AC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800065B0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800065B4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800065B8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800065BC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800065C0: addiu       $v0, $v0, 0x3F94
    ctx->r2 = ADD32(ctx->r2, 0X3F94);
    // 0x800065C4: addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // 0x800065C8: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800065CC: beql        $v0, $zero, L_800066D8
    if (ctx->r2 == 0) {
        // 0x800065D0: addu        $s2, $s3, $zero
        ctx->r18 = ADD32(ctx->r19, 0);
            goto L_800066D8;
    }
    goto skip_0;
    // 0x800065D0: addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
    skip_0:
    // 0x800065D4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800065D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800065DC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800065E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800065E4: ori         $v0, $zero, 0xFF00
    ctx->r2 = 0 | 0XFF00;
    // 0x800065E8: jal         0x80001564
    // 0x800065EC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80001564(rdram, ctx);
        goto after_1;
    // 0x800065EC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x800065F0: sll         $s0, $s2, 4
    ctx->r16 = S32(ctx->r18 << 4);
    // 0x800065F4: subu        $s0, $s0, $s2
    ctx->r16 = SUB32(ctx->r16, ctx->r18);
    // 0x800065F8: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x800065FC: addiu       $v1, $s0, 0x2D
    ctx->r3 = ADD32(ctx->r16, 0X2D);
    // 0x80006600: sw          $v0, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = ctx->r2;
    // 0x80006604: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x80006608: lw          $v0, 0xA4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA4);
    // 0x8000660C: sh          $s5, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r21;
    // 0x80006610: lw          $v0, 0xA4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA4);
    // 0x80006614: sh          $s4, 0x80($v0)
    MEM_H(0X80, ctx->r2) = ctx->r20;
    // 0x80006618: lw          $v1, 0xA4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XA4);
    // 0x8000661C: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x80006620: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80006624: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006628: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x8000662C: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x80006630: lw          $v0, 0xA4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA4);
    // 0x80006634: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80006638: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8000663C: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x80006640: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80006644: jal         0x80001564
    // 0x80006648: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80001564(rdram, ctx);
        goto after_2;
    // 0x80006648: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x8000664C: addiu       $v1, $s0, 0x48
    ctx->r3 = ADD32(ctx->r16, 0X48);
    // 0x80006650: sw          $v0, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->r2;
    // 0x80006654: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x80006658: lw          $v0, 0xA8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA8);
    // 0x8000665C: sh          $s5, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r21;
    // 0x80006660: lw          $v0, 0xA8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA8);
    // 0x80006664: sh          $s4, 0x80($v0)
    MEM_H(0X80, ctx->r2) = ctx->r20;
    // 0x80006668: lw          $v1, 0xA8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XA8);
    // 0x8000666C: lui         $t0, 0xFF
    ctx->r8 = S32(0XFF << 16);
    // 0x80006670: ori         $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 | 0XFF;
    // 0x80006674: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x80006678: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000667C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006680: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x80006684: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x80006688: lw          $v0, 0xA8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA8);
    // 0x8000668C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80006690: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80006694: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x80006698: jal         0x80001564
    // 0x8000669C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80001564(rdram, ctx);
        goto after_3;
    // 0x8000669C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_3:
    // 0x800066A0: addiu       $s0, $s0, 0x65
    ctx->r16 = ADD32(ctx->r16, 0X65);
    // 0x800066A4: sw          $v0, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->r2;
    // 0x800066A8: sh          $s0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r16;
    // 0x800066AC: lw          $v0, 0xAC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XAC);
    // 0x800066B0: sh          $s5, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r21;
    // 0x800066B4: lw          $v0, 0xAC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XAC);
    // 0x800066B8: sh          $s4, 0x80($v0)
    MEM_H(0X80, ctx->r2) = ctx->r20;
    // 0x800066BC: lw          $v1, 0xAC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XAC);
    // 0x800066C0: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x800066C4: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x800066C8: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x800066CC: lw          $v0, 0xAC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XAC);
    // 0x800066D0: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x800066D4: addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
L_800066D8:
    // 0x800066D8: slti        $v0, $s2, 0x3
    ctx->r2 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x800066DC: bne         $v0, $zero, L_800065A0
    if (ctx->r2 != 0) {
        // 0x800066E0: addiu       $s3, $s2, 0x1
        ctx->r19 = ADD32(ctx->r18, 0X1);
            goto L_800065A0;
    }
    // 0x800066E0: addiu       $s3, $s2, 0x1
    ctx->r19 = ADD32(ctx->r18, 0X1);
    // 0x800066E4: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800066E8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800066EC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800066F0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800066F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800066F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800066FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006700: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80006704: jr          $ra
    // 0x80006708: nop

    return;
    // 0x80006708: nop

;}
RECOMP_FUNC void func_8000670C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000670C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80006710: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80006714: addiu       $a0, $a0, -0x2638
    ctx->r4 = ADD32(ctx->r4, -0X2638);
    // 0x80006718: lui         $a2, 0x60
    ctx->r6 = S32(0X60 << 16);
    // 0x8000671C: ori         $a2, $a2, 0x6060
    ctx->r6 = ctx->r6 | 0X6060;
    // 0x80006720: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80006724: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80006728: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8000672C: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80006730: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80006734: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80006738: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8000673C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80006740: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80006744: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80006748: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8000674C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80006750: sw          $zero, 0x46A8($at)
    MEM_W(0X46A8, ctx->r1) = 0;
    // 0x80006754: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80006758: sw          $zero, 0x3A0($at)
    MEM_W(0X3A0, ctx->r1) = 0;
    // 0x8000675C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006760: sw          $s0, -0x1D70($at)
    MEM_W(-0X1D70, ctx->r1) = ctx->r16;
    // 0x80006764: jal         0x80056B30
    // 0x80006768: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80056B30(rdram, ctx);
        goto after_0;
    // 0x80006768: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8000676C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80006770: lhu         $v1, -0x1D66($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X1D66);
    // 0x80006774: lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // 0x80006778: ori         $v0, $v0, 0x5556
    ctx->r2 = ctx->r2 | 0X5556;
    // 0x8000677C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80006780: sra         $a0, $v1, 16
    ctx->r4 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80006784: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006788: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x8000678C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80006790: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80006794: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x80006798: mfhi        $a3
    ctx->r7 = hi;
    // 0x8000679C: nop

    // 0x800067A0: nop

    // 0x800067A4: subu        $v1, $a3, $v1
    ctx->r3 = SUB32(ctx->r7, ctx->r3);
    // 0x800067A8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800067AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800067B0: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800067B4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800067B8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800067BC: beq         $a0, $s0, L_800067F0
    if (ctx->r4 == ctx->r16) {
        // 0x800067C0: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_800067F0;
    }
    // 0x800067C0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800067C4: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x800067C8: beql        $v0, $zero, L_800067E0
    if (ctx->r2 == 0) {
        // 0x800067CC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800067E0;
    }
    goto skip_0;
    // 0x800067CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x800067D0: beql        $a0, $zero, L_80006804
    if (ctx->r4 == 0) {
        // 0x800067D4: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_80006804;
    }
    goto skip_1;
    // 0x800067D4: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    skip_1:
    // 0x800067D8: j           L_80006808
    // 0x800067DC: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
        goto L_80006808;
    // 0x800067DC: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_800067E0:
    // 0x800067E0: beql        $a0, $v0, L_800067FC
    if (ctx->r4 == ctx->r2) {
        // 0x800067E4: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_800067FC;
    }
    goto skip_2;
    // 0x800067E4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    skip_2:
    // 0x800067E8: j           L_80006808
    // 0x800067EC: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
        goto L_80006808;
    // 0x800067EC: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_800067F0:
    // 0x800067F0: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x800067F4: j           L_80006804
    // 0x800067F8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_80006804;
    // 0x800067F8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800067FC:
    // 0x800067FC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80006800: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_80006804:
    // 0x80006804: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_80006808:
    // 0x80006808: addiu       $s5, $sp, 0x10
    ctx->r21 = ADD32(ctx->r29, 0X10);
    // 0x8000680C: addiu       $s7, $zero, 0x23
    ctx->r23 = ADD32(0, 0X23);
    // 0x80006810: addiu       $s6, $zero, 0x1E
    ctx->r22 = ADD32(0, 0X1E);
    // 0x80006814: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80006818: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000681C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
L_80006820:
    // 0x80006820: addiu       $a0, $s4, 0x1
    ctx->r4 = ADD32(ctx->r20, 0X1);
    // 0x80006824: jal         0x8001F310
    // 0x80006828: sh          $zero, 0x0($s5)
    MEM_H(0X0, ctx->r21) = 0;
    func_8001F310(rdram, ctx);
        goto after_1;
    // 0x80006828: sh          $zero, 0x0($s5)
    MEM_H(0X0, ctx->r21) = 0;
    after_1:
    // 0x8000682C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80006830: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80006834: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80006838: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8000683C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80006840: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80006844: addiu       $v0, $v0, 0x3F94
    ctx->r2 = ADD32(ctx->r2, 0X3F94);
    // 0x80006848: addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // 0x8000684C: lhu         $s1, 0x0($s2)
    ctx->r17 = MEM_HU(ctx->r18, 0X0);
    // 0x80006850: beql        $s1, $zero, L_8000691C
    if (ctx->r17 == 0) {
        // 0x80006854: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_8000691C;
    }
    goto skip_3;
    // 0x80006854: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    skip_3:
    // 0x80006858: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8000685C: addiu       $s0, $s0, 0x19EC
    ctx->r16 = ADD32(ctx->r16, 0X19EC);
    // 0x80006860: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80006864: addu        $s3, $s6, $zero
    ctx->r19 = ADD32(ctx->r22, 0);
    // 0x80006868: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8000686C:
    // 0x8000686C: jal         0x8000610C
    // 0x80006870: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    func_8000610C(rdram, ctx);
        goto after_2;
    // 0x80006870: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    after_2:
    // 0x80006874: sh          $s3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r19;
    // 0x80006878: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000687C: slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x80006880: bne         $v0, $zero, L_8000686C
    if (ctx->r2 != 0) {
        // 0x80006884: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8000686C;
    }
    // 0x80006884: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80006888: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000688C: addiu       $a0, $a0, 0x1A0C
    ctx->r4 = ADD32(ctx->r4, 0X1A0C);
    // 0x80006890: jal         0x8000610C
    // 0x80006894: nop

    func_8000610C(rdram, ctx);
        goto after_3;
    // 0x80006894: nop

    after_3:
    // 0x80006898: sh          $s7, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r23;
    // 0x8000689C: lhu         $v0, 0x20($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X20);
    // 0x800068A0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800068A4: mult        $v0, $a3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800068A8: mflo        $v0
    ctx->r2 = lo;
    // 0x800068AC: nop

    // 0x800068B0: nop

    // 0x800068B4: lhu         $a0, 0x26($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X26);
    // 0x800068B8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800068BC: mult        $a0, $a3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800068C0: mflo        $a0
    ctx->r4 = lo;
    // 0x800068C4: nop

    // 0x800068C8: nop

    // 0x800068CC: lhu         $v1, 0x24($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X24);
    // 0x800068D0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800068D4: mult        $v1, $a3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800068D8: mflo        $v1
    ctx->r3 = lo;
    // 0x800068DC: nop

    // 0x800068E0: nop

    // 0x800068E4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800068E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800068EC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800068F0: sll         $v1, $fp, 16
    ctx->r3 = S32(ctx->r30 << 16);
    // 0x800068F4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800068F8: sh          $v0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r2;
    // 0x800068FC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80006900: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80006904: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80006908: beq         $v1, $zero, L_8000691C
    if (ctx->r3 == 0) {
        // 0x8000690C: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_8000691C;
    }
    // 0x8000690C: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x80006910: addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // 0x80006914: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80006918: sw          $s2, 0x4E60($at)
    MEM_W(0X4E60, ctx->r1) = ctx->r18;
L_8000691C:
    // 0x8000691C: addiu       $s7, $s7, 0x78
    ctx->r23 = ADD32(ctx->r23, 0X78);
    // 0x80006920: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80006924: slti        $v0, $s4, 0x3
    ctx->r2 = SIGNED(ctx->r20) < 0X3 ? 1 : 0;
    // 0x80006928: bne         $v0, $zero, L_80006820
    if (ctx->r2 != 0) {
        // 0x8000692C: addiu       $s6, $s6, 0x78
        ctx->r22 = ADD32(ctx->r22, 0X78);
            goto L_80006820;
    }
    // 0x8000692C: addiu       $s6, $s6, 0x78
    ctx->r22 = ADD32(ctx->r22, 0X78);
    // 0x80006930: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x80006934: lui         $s7, 0x8015
    ctx->r23 = S32(0X8015 << 16);
    // 0x80006938: addiu       $s7, $s7, 0x3F94
    ctx->r23 = ADD32(ctx->r23, 0X3F94);
    // 0x8000693C: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80006940: addiu       $s6, $s6, 0x18FC
    ctx->r22 = ADD32(ctx->r22, 0X18FC);
    // 0x80006944: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x80006948: addiu       $s5, $s5, 0x196C
    ctx->r21 = ADD32(ctx->r21, 0X196C);
    // 0x8000694C: addiu       $s3, $zero, 0x4B
    ctx->r19 = ADD32(0, 0X4B);
L_80006950:
    // 0x80006950: jal         0x8001F310
    // 0x80006954: addiu       $a0, $s4, 0x1
    ctx->r4 = ADD32(ctx->r20, 0X1);
    func_8001F310(rdram, ctx);
        goto after_4;
    // 0x80006954: addiu       $a0, $s4, 0x1
    ctx->r4 = ADD32(ctx->r20, 0X1);
    after_4:
    // 0x80006958: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8000695C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80006960: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80006964: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80006968: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000696C: addu        $s2, $v1, $s7
    ctx->r18 = ADD32(ctx->r3, ctx->r23);
    // 0x80006970: lhu         $s1, 0x0($s2)
    ctx->r17 = MEM_HU(ctx->r18, 0X0);
    // 0x80006974: beql        $s1, $zero, L_800069EC
    if (ctx->r17 == 0) {
        // 0x80006978: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800069EC;
    }
    goto skip_4;
    // 0x80006978: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_4:
    // 0x8000697C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80006980: lw          $v0, 0x4E60($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4E60);
    // 0x80006984: bne         $v0, $s2, L_80006994
    if (ctx->r2 != ctx->r18) {
        // 0x80006988: sll         $v0, $s1, 4
        ctx->r2 = S32(ctx->r17 << 4);
            goto L_80006994;
    }
    // 0x80006988: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
    // 0x8000698C: j           L_80006998
    // 0x80006990: addu        $s0, $v0, $s6
    ctx->r16 = ADD32(ctx->r2, ctx->r22);
        goto L_80006998;
    // 0x80006990: addu        $s0, $v0, $s6
    ctx->r16 = ADD32(ctx->r2, ctx->r22);
L_80006994:
    // 0x80006994: addu        $s0, $v0, $s5
    ctx->r16 = ADD32(ctx->r2, ctx->r21);
L_80006998:
    // 0x80006998: jal         0x8000610C
    // 0x8000699C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000610C(rdram, ctx);
        goto after_5;
    // 0x8000699C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x800069A0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800069A4: lh          $a2, -0x1D3C($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X1D3C);
    // 0x800069A8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800069AC: xori        $v0, $s1, 0x7
    ctx->r2 = ctx->r17 ^ 0X7;
    // 0x800069B0: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800069B4: xori        $v1, $a2, 0x68B
    ctx->r3 = ctx->r6 ^ 0X68B;
    // 0x800069B8: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800069BC: and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // 0x800069C0: beq         $v1, $zero, L_800069D0
    if (ctx->r3 == 0) {
        // 0x800069C4: sh          $s3, 0x14($a0)
        MEM_H(0X14, ctx->r4) = ctx->r19;
            goto L_800069D0;
    }
    // 0x800069C4: sh          $s3, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r19;
    // 0x800069C8: j           L_800069E4
    // 0x800069CC: addiu       $v0, $zero, 0x686
    ctx->r2 = ADD32(0, 0X686);
        goto L_800069E4;
    // 0x800069CC: addiu       $v0, $zero, 0x686
    ctx->r2 = ADD32(0, 0X686);
L_800069D0:
    // 0x800069D0: xori        $v0, $a2, 0x68C
    ctx->r2 = ctx->r6 ^ 0X68C;
    // 0x800069D4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800069D8: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x800069DC: beq         $v0, $zero, L_800069E8
    if (ctx->r2 == 0) {
        // 0x800069E0: addiu       $v0, $zero, 0x687
        ctx->r2 = ADD32(0, 0X687);
            goto L_800069E8;
    }
    // 0x800069E0: addiu       $v0, $zero, 0x687
    ctx->r2 = ADD32(0, 0X687);
L_800069E4:
    // 0x800069E4: sh          $v0, 0x74($a0)
    MEM_H(0X74, ctx->r4) = ctx->r2;
L_800069E8:
    // 0x800069E8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800069EC:
    // 0x800069EC: slti        $v0, $s4, 0x3
    ctx->r2 = SIGNED(ctx->r20) < 0X3 ? 1 : 0;
    // 0x800069F0: bne         $v0, $zero, L_80006950
    if (ctx->r2 != 0) {
        // 0x800069F4: addiu       $s3, $s3, 0x78
        ctx->r19 = ADD32(ctx->r19, 0X78);
            goto L_80006950;
    }
    // 0x800069F4: addiu       $s3, $s3, 0x78
    ctx->r19 = ADD32(ctx->r19, 0X78);
    // 0x800069F8: jal         0x80006570
    // 0x800069FC: nop

    func_80006570(rdram, ctx);
        goto after_6;
    // 0x800069FC: nop

    after_6:
    // 0x80006A00: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    // 0x80006A04: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80006A08: sh          $v0, -0x68E0($at)
    MEM_H(-0X68E0, ctx->r1) = ctx->r2;
    // 0x80006A0C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80006A10: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80006A14: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80006A18: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80006A1C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80006A20: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80006A24: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80006A28: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80006A2C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80006A30: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80006A34: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80006A38: jr          $ra
    // 0x80006A3C: nop

    return;
    // 0x80006A3C: nop

;}
RECOMP_FUNC void func_80006A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006A40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80006A44: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006A48: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80006A4C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80006A50: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80006A54: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80006A58: addiu       $s5, $zero, 0xC8
    ctx->r21 = ADD32(0, 0XC8);
    // 0x80006A5C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80006A60: lui         $s4, 0x8009
    ctx->r20 = S32(0X8009 << 16);
    // 0x80006A64: addiu       $s4, $s4, 0x3468
    ctx->r20 = ADD32(ctx->r20, 0X3468);
    // 0x80006A68: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80006A6C: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
    // 0x80006A70: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80006A74: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80006A78: addiu       $s2, $s2, 0x119C
    ctx->r18 = ADD32(ctx->r18, 0X119C);
    // 0x80006A7C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
L_80006A80:
    // 0x80006A80: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x80006A84: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80006A88: sltiu       $v1, $a0, 0x1
    ctx->r3 = ctx->r4 < 0X1 ? 1 : 0;
    // 0x80006A8C: xori        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 ^ 0X3;
    // 0x80006A90: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80006A94: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80006A98: beq         $v1, $zero, L_80006AC0
    if (ctx->r3 == 0) {
        // 0x80006A9C: sll         $v1, $s1, 16
        ctx->r3 = S32(ctx->r17 << 16);
            goto L_80006AC0;
    }
    // 0x80006A9C: sll         $v1, $s1, 16
    ctx->r3 = S32(ctx->r17 << 16);
    // 0x80006AA0: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80006AA4: srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // 0x80006AA8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80006AAC: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80006AB0: subu        $v0, $s5, $v0
    ctx->r2 = SUB32(ctx->r21, ctx->r2);
    // 0x80006AB4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80006AB8: j           L_80006B1C
    // 0x80006ABC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_80006B1C;
    // 0x80006ABC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80006AC0:
    // 0x80006AC0: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x80006AC4: sltiu       $v0, $v1, 0xC
    ctx->r2 = ctx->r3 < 0XC ? 1 : 0;
    // 0x80006AC8: beq         $v0, $zero, L_80006AE8
    if (ctx->r2 == 0) {
        // 0x80006ACC: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80006AE8;
    }
    // 0x80006ACC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80006AD0: addu        $v0, $v0, $s4
    gpr jr_addend_80006AD8 = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80006AD4: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x80006AD8: jr          $v0
    // 0x80006ADC: nop

    switch (jr_addend_80006AD8 >> 2) {
        case 0: goto L_80006B14; break;
        case 1: goto L_80006B14; break;
        case 2: goto L_80006AE8; break;
        case 3: goto L_80006AE0; break;
        case 4: goto L_80006AE0; break;
        case 5: goto L_80006B14; break;
        case 6: goto L_80006B14; break;
        case 7: goto L_80006B14; break;
        case 8: goto L_80006B14; break;
        case 9: goto L_80006B14; break;
        case 10: goto L_80006AE0; break;
        case 11: goto L_80006B14; break;
        default: switch_error(__func__, 0x80006AD8, 0x80093468);
    }
    // 0x80006ADC: nop

L_80006AE0:
    // 0x80006AE0: j           L_80006B14
    // 0x80006AE4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80006B14;
    // 0x80006AE4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80006AE8:
    // 0x80006AE8: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80006AEC: beq         $v0, $s3, L_80006B10
    if (ctx->r2 == ctx->r19) {
        // 0x80006AF0: sll         $v0, $v0, 2
        ctx->r2 = S32(ctx->r2 << 2);
            goto L_80006B10;
    }
    // 0x80006AF0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80006AF4: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80006AF8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80006AFC: jal         0x8005F360
    // 0x80006B00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_8005F360(rdram, ctx);
        goto after_0;
    // 0x80006B00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_0:
    // 0x80006B04: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x80006B08: j           L_80006A80
    // 0x80006B0C: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
        goto L_80006A80;
    // 0x80006B0C: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
L_80006B10:
    // 0x80006B10: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80006B14:
    // 0x80006B14: j           L_80006A80
    // 0x80006B18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80006A80;
    // 0x80006B18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80006B1C:
    // 0x80006B1C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80006B20: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80006B24: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80006B28: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80006B2C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80006B30: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80006B34: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80006B38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80006B3C: jr          $ra
    // 0x80006B40: nop

    return;
    // 0x80006B40: nop

;}
RECOMP_FUNC void func_80006B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006B44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006B48: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80006B4C: jal         0x800246DC
    // 0x80006B50: addiu       $a0, $zero, 0x410
    ctx->r4 = ADD32(0, 0X410);
    func_800246DC(rdram, ctx);
        goto after_0;
    // 0x80006B50: addiu       $a0, $zero, 0x410
    ctx->r4 = ADD32(0, 0X410);
    after_0:
    // 0x80006B54: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80006B58: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80006B5C: addiu       $v0, $v0, -0x6860
    ctx->r2 = ADD32(ctx->r2, -0X6860);
L_80006B60:
    // 0x80006B60: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80006B64: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80006B68: bgez        $v1, L_80006B60
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80006B6C: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_80006B60;
    }
    // 0x80006B6C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80006B70: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80006B74: sh          $zero, -0x7456($at)
    MEM_H(-0X7456, ctx->r1) = 0;
    // 0x80006B78: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80006B7C: sh          $zero, -0x7342($at)
    MEM_H(-0X7342, ctx->r1) = 0;
    // 0x80006B80: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80006B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006B88: jr          $ra
    // 0x80006B8C: nop

    return;
    // 0x80006B8C: nop

;}
RECOMP_FUNC void func_80006B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006B90: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80006B94: lh          $v0, -0x7456($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X7456);
    // FALLTHROUGH: func_80006B90 falls into func_80006B98
    func_80006B98(rdram, ctx);
;}
RECOMP_FUNC void func_80006B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006B98: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80006B9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80006BA0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80006BA4: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80006BA8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80006BAC: beq         $v0, $zero, L_80006BC8
    if (ctx->r2 == 0) {
        // 0x80006BB0: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80006BC8;
    }
    // 0x80006BB0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80006BB4: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80006BB8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80006BBC: sh          $v0, -0x7456($at)
    MEM_H(-0X7456, ctx->r1) = ctx->r2;
L_80006BC0:
    // 0x80006BC0: j           L_80006ED4
    // 0x80006BC4: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80006ED4;
    // 0x80006BC4: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80006BC8:
    // 0x80006BC8: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80006BCC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80006BD0: lw          $v0, 0x4720($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4720);
    // 0x80006BD4: lui         $v1, 0x1004
    ctx->r3 = S32(0X1004 << 16);
    // 0x80006BD8: ori         $v1, $v1, 0x100
    ctx->r3 = ctx->r3 | 0X100;
    // 0x80006BDC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80006BE0: bnel        $v0, $zero, L_80006BE8
    if (ctx->r2 != 0) {
        // 0x80006BE4: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_80006BE8;
    }
    goto skip_0;
    // 0x80006BE4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    skip_0:
L_80006BE8:
    // 0x80006BE8: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80006BEC: sltiu       $v0, $v1, 0xD
    ctx->r2 = ctx->r3 < 0XD ? 1 : 0;
    // 0x80006BF0: beq         $v0, $zero, L_80006DE4
    if (ctx->r2 == 0) {
        // 0x80006BF4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80006DE4;
    }
    // 0x80006BF4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80006BF8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80006BFC: addu        $at, $at, $v0
    gpr jr_addend_80006C04 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80006C00: lw          $v0, 0x3498($at)
    ctx->r2 = ADD32(ctx->r1, 0X3498);
    // 0x80006C04: jr          $v0
    // 0x80006C08: nop

    switch (jr_addend_80006C04 >> 2) {
        case 0: goto L_80006BC0; break;
        case 1: goto L_80006C0C; break;
        case 2: goto L_80006DE4; break;
        case 3: goto L_80006CD4; break;
        case 4: goto L_80006C40; break;
        case 5: goto L_80006D00; break;
        case 6: goto L_80006D4C; break;
        case 7: goto L_80006DB4; break;
        case 8: goto L_80006CC4; break;
        case 9: goto L_80006CA0; break;
        case 10: goto L_80006D70; break;
        case 11: goto L_80006D80; break;
        case 12: goto L_80006DD0; break;
        default: switch_error(__func__, 0x80006C04, 0x80093498);
    }
    // 0x80006C08: nop

L_80006C0C:
    // 0x80006C0C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80006C10: lh          $v0, -0x7342($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X7342);
    // 0x80006C14: slti        $v0, $v0, 0xAA
    ctx->r2 = SIGNED(ctx->r2) < 0XAA ? 1 : 0;
    // 0x80006C18: beq         $v0, $zero, L_80006C30
    if (ctx->r2 == 0) {
        // 0x80006C1C: nop
    
            goto L_80006C30;
    }
    // 0x80006C1C: nop

    // 0x80006C20: jal         0x800555F0
    // 0x80006C24: addiu       $a0, $zero, 0x410
    ctx->r4 = ADD32(0, 0X410);
    func_800555F0(rdram, ctx);
        goto after_0;
    // 0x80006C24: addiu       $a0, $zero, 0x410
    ctx->r4 = ADD32(0, 0X410);
    after_0:
    // 0x80006C28: j           L_80006ED4
    // 0x80006C2C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80006ED4;
    // 0x80006C2C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80006C30:
    // 0x80006C30: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80006C34: sh          $zero, -0x7342($at)
    MEM_H(-0X7342, ctx->r1) = 0;
    // 0x80006C38: j           L_80006ED4
    // 0x80006C3C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
        goto L_80006ED4;
    // 0x80006C3C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_80006C40:
    // 0x80006C40: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80006C44: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80006C48: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80006C4C: lw          $v0, 0x4720($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4720);
    // 0x80006C50: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x80006C54: ori         $v1, $v1, 0x4010
    ctx->r3 = ctx->r3 | 0X4010;
    // 0x80006C58: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80006C5C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80006C60: sh          $a0, -0x7456($at)
    MEM_H(-0X7456, ctx->r1) = ctx->r4;
    // 0x80006C64: beq         $v0, $zero, L_80006ED0
    if (ctx->r2 == 0) {
        // 0x80006C68: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_80006ED0;
    }
    // 0x80006C68: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80006C6C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80006C70: lh          $v1, 0x13EE($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X13EE);
    // 0x80006C74: beq         $v1, $v0, L_80006ED0
    if (ctx->r3 == ctx->r2) {
        // 0x80006C78: lui         $v0, 0x5555
        ctx->r2 = S32(0X5555 << 16);
            goto L_80006ED0;
    }
    // 0x80006C78: lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // 0x80006C7C: ori         $v0, $v0, 0x5556
    ctx->r2 = ctx->r2 | 0X5556;
    // 0x80006C80: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006C84: mfhi        $t0
    ctx->r8 = hi;
    // 0x80006C88: nop

    // 0x80006C8C: nop

    // 0x80006C90: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80006C94: sh          $t0, -0x7456($at)
    MEM_H(-0X7456, ctx->r1) = ctx->r8;
    // 0x80006C98: j           L_80006ED4
    // 0x80006C9C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
        goto L_80006ED4;
    // 0x80006C9C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_80006CA0:
    // 0x80006CA0: jal         0x80006A40
    // 0x80006CA4: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    func_80006A40(rdram, ctx);
        goto after_1;
    // 0x80006CA4: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    after_1:
    // 0x80006CA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80006CAC: sh          $v0, 0x3D2($at)
    MEM_H(0X3D2, ctx->r1) = ctx->r2;
    // 0x80006CB0: addiu       $v0, $zero, 0xA4
    ctx->r2 = ADD32(0, 0XA4);
    // 0x80006CB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80006CB8: sh          $v0, 0x46C8($at)
    MEM_H(0X46C8, ctx->r1) = ctx->r2;
    // 0x80006CBC: j           L_80006ED4
    // 0x80006CC0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
        goto L_80006ED4;
    // 0x80006CC0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_80006CC4:
    // 0x80006CC4: jal         0x800246DC
    // 0x80006CC8: addiu       $a0, $zero, 0x410
    ctx->r4 = ADD32(0, 0X410);
    func_800246DC(rdram, ctx);
        goto after_2;
    // 0x80006CC8: addiu       $a0, $zero, 0x410
    ctx->r4 = ADD32(0, 0X410);
    after_2:
    // 0x80006CCC: j           L_80006ED4
    // 0x80006CD0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
        goto L_80006ED4;
    // 0x80006CD0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_80006CD4:
    // 0x80006CD4: jal         0x80006A40
    // 0x80006CD8: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    func_80006A40(rdram, ctx);
        goto after_3;
    // 0x80006CD8: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    after_3:
    // 0x80006CDC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80006CE0: lhu         $v1, 0x46C8($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X46C8);
    // 0x80006CE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80006CE8: sh          $v0, 0x3D2($at)
    MEM_H(0X3D2, ctx->r1) = ctx->r2;
    // 0x80006CEC: addiu       $v1, $v1, 0xB
    ctx->r3 = ADD32(ctx->r3, 0XB);
    // 0x80006CF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80006CF4: sh          $v1, 0x46C8($at)
    MEM_H(0X46C8, ctx->r1) = ctx->r3;
    // 0x80006CF8: j           L_80006ED4
    // 0x80006CFC: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
        goto L_80006ED4;
    // 0x80006CFC: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_80006D00:
    // 0x80006D00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80006D04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80006D08: lui         $a2, 0x80
    ctx->r6 = S32(0X80 << 16);
    // 0x80006D0C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80006D10: ori         $a2, $a2, 0x8080
    ctx->r6 = ctx->r6 | 0X8080;
    // 0x80006D14: addiu       $a3, $zero, 0x520
    ctx->r7 = ADD32(0, 0X520);
    // 0x80006D18: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80006D1C: addiu       $a0, $a0, 0x278C
    ctx->r4 = ADD32(ctx->r4, 0X278C);
    // 0x80006D20: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80006D24: jal         0x80056AA4
    // 0x80006D28: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80056AA4(rdram, ctx);
        goto after_4;
    // 0x80006D28: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_4:
    // 0x80006D2C: addiu       $a0, $zero, 0x520
    ctx->r4 = ADD32(0, 0X520);
    // 0x80006D30: jal         0x80055180
    // 0x80006D34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80055180(rdram, ctx);
        goto after_5;
    // 0x80006D34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // 0x80006D38: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80006D3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80006D40: sh          $v0, 0x3E2($at)
    MEM_H(0X3E2, ctx->r1) = ctx->r2;
    // 0x80006D44: j           L_80006ED4
    // 0x80006D48: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
        goto L_80006ED4;
    // 0x80006D48: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_80006D4C:
    // 0x80006D4C: addiu       $a0, $zero, 0x520
    ctx->r4 = ADD32(0, 0X520);
    // 0x80006D50: lui         $a1, 0x80
    ctx->r5 = S32(0X80 << 16);
    // 0x80006D54: jal         0x80055180
    // 0x80006D58: ori         $a1, $a1, 0x8080
    ctx->r5 = ctx->r5 | 0X8080;
    func_80055180(rdram, ctx);
        goto after_6;
    // 0x80006D58: ori         $a1, $a1, 0x8080
    ctx->r5 = ctx->r5 | 0X8080;
    after_6:
    // 0x80006D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006D60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80006D64: sh          $v0, 0x3E2($at)
    MEM_H(0X3E2, ctx->r1) = ctx->r2;
    // 0x80006D68: j           L_80006ED4
    // 0x80006D6C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
        goto L_80006ED4;
    // 0x80006D6C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_80006D70:
    // 0x80006D70: jal         0x800246DC
    // 0x80006D74: addiu       $a0, $zero, 0x520
    ctx->r4 = ADD32(0, 0X520);
    func_800246DC(rdram, ctx);
        goto after_7;
    // 0x80006D74: addiu       $a0, $zero, 0x520
    ctx->r4 = ADD32(0, 0X520);
    after_7:
    // 0x80006D78: j           L_80006ED4
    // 0x80006D7C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
        goto L_80006ED4;
    // 0x80006D7C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_80006D80:
    // 0x80006D80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80006D84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80006D88: lui         $a2, 0x80
    ctx->r6 = S32(0X80 << 16);
    // 0x80006D8C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80006D90: ori         $a2, $a2, 0x8080
    ctx->r6 = ctx->r6 | 0X8080;
    // 0x80006D94: addiu       $a3, $zero, 0x520
    ctx->r7 = ADD32(0, 0X520);
    // 0x80006D98: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80006D9C: addiu       $a0, $a0, 0x278C
    ctx->r4 = ADD32(ctx->r4, 0X278C);
    // 0x80006DA0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80006DA4: jal         0x80056AA4
    // 0x80006DA8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80056AA4(rdram, ctx);
        goto after_8;
    // 0x80006DA8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_8:
    // 0x80006DAC: j           L_80006ED4
    // 0x80006DB0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
        goto L_80006ED4;
    // 0x80006DB0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_80006DB4:
    // 0x80006DB4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80006DB8: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x80006DBC: addiu       $a2, $zero, 0x154
    ctx->r6 = ADD32(0, 0X154);
    // 0x80006DC0: jal         0x80001DAC
    // 0x80006DC4: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    func_80001DAC(rdram, ctx);
        goto after_9;
    // 0x80006DC4: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_9:
    // 0x80006DC8: j           L_80006ED4
    // 0x80006DCC: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
        goto L_80006ED4;
    // 0x80006DCC: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_80006DD0:
    // 0x80006DD0: addiu       $v0, $zero, 0x65
    ctx->r2 = ADD32(0, 0X65);
    // 0x80006DD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80006DD8: sh          $v0, 0x4E66($at)
    MEM_H(0X4E66, ctx->r1) = ctx->r2;
    // 0x80006DDC: j           L_80006ED4
    // 0x80006DE0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
        goto L_80006ED4;
    // 0x80006DE0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_80006DE4:
    // 0x80006DE4: andi        $s1, $a0, 0xFF
    ctx->r17 = ctx->r4 & 0XFF;
    // 0x80006DE8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80006DEC: beq         $s1, $v0, L_80006E80
    if (ctx->r17 == ctx->r2) {
        // 0x80006DF0: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80006E80;
    }
    // 0x80006DF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80006DF4: jal         0x800306EC
    // 0x80006DF8: nop

    func_800306EC(rdram, ctx);
        goto after_10;
    // 0x80006DF8: nop

    after_10:
    // 0x80006DFC: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x80006E00: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80006E04: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x80006E08: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80006E0C: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x80006E10: lw          $a2, 0x119C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X119C);
    // 0x80006E14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80006E18: lh          $a0, 0x3D2($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X3D2);
    // 0x80006E1C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80006E20: lh          $a1, 0x46C8($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X46C8);
    // 0x80006E24: addiu       $v1, $zero, 0x7000
    ctx->r3 = ADD32(0, 0X7000);
    // 0x80006E28: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x80006E2C: ori         $v1, $zero, 0x8101
    ctx->r3 = 0 | 0X8101;
    // 0x80006E30: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // 0x80006E34: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80006E38: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80006E3C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x80006E40: sw          $a0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r4;
    // 0x80006E44: jal         0x80023E44
    // 0x80006E48: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
    func_80023E44(rdram, ctx);
        goto after_11;
    // 0x80006E48: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
    after_11:
    // 0x80006E4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80006E50: lhu         $a0, 0x3D2($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X3D2);
    // 0x80006E54: lhu         $a1, 0x32($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X32);
    // 0x80006E58: addiu       $v1, $zero, 0x410
    ctx->r3 = ADD32(0, 0X410);
    // 0x80006E5C: sh          $v1, 0x70($v0)
    MEM_H(0X70, ctx->r2) = ctx->r3;
    // 0x80006E60: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80006E64: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80006E68: sh          $v0, -0x7456($at)
    MEM_H(-0X7456, ctx->r1) = ctx->r2;
    // 0x80006E6C: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x80006E70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80006E74: sh          $a0, 0x3D2($at)
    MEM_H(0X3D2, ctx->r1) = ctx->r4;
    // 0x80006E78: j           L_80006E9C
    // 0x80006E7C: nop

        goto L_80006E9C;
    // 0x80006E7C: nop

L_80006E80:
    // 0x80006E80: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006E84: lhu         $v0, 0x3D2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3D2);
    // 0x80006E88: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80006E8C: sh          $v1, -0x7456($at)
    MEM_H(-0X7456, ctx->r1) = ctx->r3;
    // 0x80006E90: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80006E94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80006E98: sh          $v0, 0x3D2($at)
    MEM_H(0X3D2, ctx->r1) = ctx->r2;
L_80006E9C:
    // 0x80006E9C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80006EA0: lw          $v0, 0x4720($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4720);
    // 0x80006EA4: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x80006EA8: ori         $v1, $v1, 0x4010
    ctx->r3 = ctx->r3 | 0X4010;
    // 0x80006EAC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80006EB0: beq         $v0, $zero, L_80006ED0
    if (ctx->r2 == 0) {
        // 0x80006EB4: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_80006ED0;
    }
    // 0x80006EB4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80006EB8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80006EBC: lh          $v1, 0x13EE($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X13EE);
    // 0x80006EC0: beq         $v1, $v0, L_80006ED4
    if (ctx->r3 == ctx->r2) {
        // 0x80006EC4: addiu       $v0, $s0, 0x1
        ctx->r2 = ADD32(ctx->r16, 0X1);
            goto L_80006ED4;
    }
    // 0x80006EC4: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x80006EC8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80006ECC: sh          $zero, -0x7456($at)
    MEM_H(-0X7456, ctx->r1) = 0;
L_80006ED0:
    // 0x80006ED0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_80006ED4:
    // 0x80006ED4: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80006ED8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80006EDC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80006EE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80006EE4: jr          $ra
    // 0x80006EE8: nop

    return;
    // 0x80006EE8: nop

;}
RECOMP_FUNC void func_80006EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006EEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80006EF0: sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4 << 6);
    // 0x80006EF4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80006EF8: addiu       $v0, $v0, 0x265C
    ctx->r2 = ADD32(ctx->r2, 0X265C);
    // 0x80006EFC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80006F00: addu        $s1, $a0, $v0
    ctx->r17 = ADD32(ctx->r4, ctx->r2);
    // 0x80006F04: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80006F08: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80006F0C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80006F10: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x80006F14: addiu       $s2, $s2, 0x4918
    ctx->r18 = ADD32(ctx->r18, 0X4918);
    // 0x80006F18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006F1C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80006F20: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
L_80006F24:
    // 0x80006F24: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80006F28: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x80006F2C: sh          $v0, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r2;
    // 0x80006F30: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x80006F34: sh          $v0, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r2;
    // 0x80006F38: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80006F3C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80006F40: sh          $v0, 0x80($a2)
    MEM_H(0X80, ctx->r6) = ctx->r2;
    // 0x80006F44: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80006F48: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80006F4C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80006F50: sh          $a1, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r5;
    // 0x80006F54: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80006F58: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80006F5C: jal         0x80016BA0
    // 0x80006F60: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    func_80016BA0(rdram, ctx);
        goto after_0;
    // 0x80006F60: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_0:
    // 0x80006F64: slti        $v0, $s3, 0x4
    ctx->r2 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x80006F68: bne         $v0, $zero, L_80006F24
    if (ctx->r2 != 0) {
        // 0x80006F6C: nop
    
            goto L_80006F24;
    }
    // 0x80006F6C: nop

    // 0x80006F70: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80006F74: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80006F78: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80006F7C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80006F80: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80006F84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80006F88: jr          $ra
    // 0x80006F8C: nop

    return;
    // 0x80006F8C: nop

;}
RECOMP_FUNC void func_80006F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006F90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80006F94: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80006F98: lw          $a0, 0x4720($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4720);
    // 0x80006F9C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80006FA0: lw          $v0, -0x68F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68F0);
    // 0x80006FA4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80006FA8: lh          $a1, 0x39E($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X39E);
    // 0x80006FAC: lui         $v1, 0x3FFF
    ctx->r3 = S32(0X3FFF << 16);
    // 0x80006FB0: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80006FB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80006FB8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80006FBC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80006FC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006FC4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80006FC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80006FCC: sw          $v0, 0x4720($at)
    MEM_W(0X4720, ctx->r1) = ctx->r2;
    // 0x80006FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006FD4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80006FD8: sw          $a0, 0x2588($at)
    MEM_W(0X2588, ctx->r1) = ctx->r4;
    // 0x80006FDC: beq         $a1, $v0, L_80006FF4
    if (ctx->r5 == ctx->r2) {
        // 0x80006FE0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80006FF4;
    }
    // 0x80006FE0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80006FE4: beq         $a1, $v0, L_80007188
    if (ctx->r5 == ctx->r2) {
        // 0x80006FE8: nop
    
            goto L_80007188;
    }
    // 0x80006FE8: nop

    // 0x80006FEC: j           L_80007314
    // 0x80006FF0: nop

        goto L_80007314;
    // 0x80006FF0: nop

L_80006FF4:
    // 0x80006FF4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80006FF8: lh          $v1, 0x13EE($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X13EE);
    // 0x80006FFC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80007000: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007004: sh          $v0, 0x39E($at)
    MEM_H(0X39E, ctx->r1) = ctx->r2;
    // 0x80007008: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x8000700C: beq         $v0, $zero, L_80007144
    if (ctx->r2 == 0) {
        // 0x80007010: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80007144;
    }
    // 0x80007010: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80007014: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80007018: addu        $at, $at, $v0
    gpr jr_addend_80007020 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000701C: lw          $v0, 0x34D0($at)
    ctx->r2 = ADD32(ctx->r1, 0X34D0);
    // 0x80007020: jr          $v0
    // 0x80007024: nop

    switch (jr_addend_80007020 >> 2) {
        case 0: goto L_80007028; break;
        case 1: goto L_80007038; break;
        case 2: goto L_80007048; break;
        case 3: goto L_80007058; break;
        case 4: goto L_80007068; break;
        case 5: goto L_80007078; break;
        case 6: goto L_800070A8; break;
        default: switch_error(__func__, 0x80007020, 0x800934D0);
    }
    // 0x80007024: nop

L_80007028:
    // 0x80007028: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000702C: addiu       $v0, $v0, -0x6744
    ctx->r2 = ADD32(ctx->r2, -0X6744);
    // 0x80007030: j           L_80007080
    // 0x80007034: nop

        goto L_80007080;
    // 0x80007034: nop

L_80007038:
    // 0x80007038: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000703C: addiu       $v0, $v0, -0x64B8
    ctx->r2 = ADD32(ctx->r2, -0X64B8);
    // 0x80007040: j           L_80007080
    // 0x80007044: nop

        goto L_80007080;
    // 0x80007044: nop

L_80007048:
    // 0x80007048: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000704C: addiu       $v0, $v0, -0x63E8
    ctx->r2 = ADD32(ctx->r2, -0X63E8);
    // 0x80007050: j           L_80007080
    // 0x80007054: nop

        goto L_80007080;
    // 0x80007054: nop

L_80007058:
    // 0x80007058: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000705C: addiu       $v0, $v0, -0x6314
    ctx->r2 = ADD32(ctx->r2, -0X6314);
    // 0x80007060: j           L_80007080
    // 0x80007064: nop

        goto L_80007080;
    // 0x80007064: nop

L_80007068:
    // 0x80007068: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000706C: addiu       $v0, $v0, -0x626C
    ctx->r2 = ADD32(ctx->r2, -0X626C);
    // 0x80007070: j           L_80007080
    // 0x80007074: nop

        goto L_80007080;
    // 0x80007074: nop

L_80007078:
    // 0x80007078: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000707C: addiu       $v0, $v0, -0x6168
    ctx->r2 = ADD32(ctx->r2, -0X6168);
L_80007080:
    // 0x80007080: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007084: sw          $v0, -0x2070($at)
    MEM_W(-0X2070, ctx->r1) = ctx->r2;
    // 0x80007088: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000708C: addiu       $a0, $a0, 0x25AC
    ctx->r4 = ADD32(ctx->r4, 0X25AC);
    // 0x80007090: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80007094: lui         $a2, 0x80
    ctx->r6 = S32(0X80 << 16);
    // 0x80007098: jal         0x80056B30
    // 0x8000709C: ori         $a2, $a2, 0x8080
    ctx->r6 = ctx->r6 | 0X8080;
    func_80056B30(rdram, ctx);
        goto after_0;
    // 0x8000709C: ori         $a2, $a2, 0x8080
    ctx->r6 = ctx->r6 | 0X8080;
    after_0:
    // 0x800070A0: j           L_80007144
    // 0x800070A4: nop

        goto L_80007144;
    // 0x800070A4: nop

L_800070A8:
    // 0x800070A8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800070AC: addiu       $v0, $v0, -0x6074
    ctx->r2 = ADD32(ctx->r2, -0X6074);
    // 0x800070B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800070B4: sw          $v0, -0x2070($at)
    MEM_W(-0X2070, ctx->r1) = ctx->r2;
    // 0x800070B8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800070BC: addiu       $a0, $a0, 0x25EC
    ctx->r4 = ADD32(ctx->r4, 0X25EC);
    // 0x800070C0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800070C4: lui         $a2, 0x80
    ctx->r6 = S32(0X80 << 16);
    // 0x800070C8: jal         0x80056B30
    // 0x800070CC: ori         $a2, $a2, 0x8080
    ctx->r6 = ctx->r6 | 0X8080;
    func_80056B30(rdram, ctx);
        goto after_1;
    // 0x800070CC: ori         $a2, $a2, 0x8080
    ctx->r6 = ctx->r6 | 0X8080;
    after_1:
    // 0x800070D0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800070D4: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800070D8: addiu       $s1, $s1, 0x4918
    ctx->r17 = ADD32(ctx->r17, 0X4918);
    // 0x800070DC: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x800070E0: addiu       $s0, $s0, 0x265C
    ctx->r16 = ADD32(ctx->r16, 0X265C);
L_800070E4:
    // 0x800070E4: jal         0x8000610C
    // 0x800070E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000610C(rdram, ctx);
        goto after_2;
    // 0x800070E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800070EC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800070F0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800070F4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800070F8: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x800070FC: bne         $v0, $zero, L_800070E4
    if (ctx->r2 != 0) {
        // 0x80007100: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800070E4;
    }
    // 0x80007100: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80007104: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80007108: addiu       $s0, $s0, 0x275C
    ctx->r16 = ADD32(ctx->r16, 0X275C);
    // 0x8000710C: jal         0x8000610C
    // 0x80007110: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000610C(rdram, ctx);
        goto after_3;
    // 0x80007110: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80007114: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80007118: sw          $v0, 0x3238($at)
    MEM_W(0X3238, ctx->r1) = ctx->r2;
    // 0x8000711C: jal         0x8000610C
    // 0x80007120: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_8000610C(rdram, ctx);
        goto after_4;
    // 0x80007120: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_4:
    // 0x80007124: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80007128: addiu       $a0, $a0, 0x277C
    ctx->r4 = ADD32(ctx->r4, 0X277C);
    // 0x8000712C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80007130: sw          $v0, 0x323C($at)
    MEM_W(0X323C, ctx->r1) = ctx->r2;
    // 0x80007134: jal         0x8000610C
    // 0x80007138: nop

    func_8000610C(rdram, ctx);
        goto after_5;
    // 0x80007138: nop

    after_5:
    // 0x8000713C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80007140: sw          $v0, 0x4050($at)
    MEM_W(0X4050, ctx->r1) = ctx->r2;
L_80007144:
    // 0x80007144: jal         0x80006B44
    // 0x80007148: nop

    func_80006B44(rdram, ctx);
        goto after_6;
    // 0x80007148: nop

    after_6:
    // 0x8000714C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80007150: lw          $a0, -0x2070($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2070);
    // 0x80007154: jal         0x80006A40
    // 0x80007158: nop

    func_80006A40(rdram, ctx);
        goto after_7;
    // 0x80007158: nop

    after_7:
    // 0x8000715C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80007160: sh          $v0, 0x3D2($at)
    MEM_H(0X3D2, ctx->r1) = ctx->r2;
    // 0x80007164: addiu       $v0, $zero, 0xA4
    ctx->r2 = ADD32(0, 0XA4);
    // 0x80007168: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000716C: sh          $v0, 0x46C8($at)
    MEM_H(0X46C8, ctx->r1) = ctx->r2;
    // 0x80007170: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007174: sh          $zero, -0x1CF0($at)
    MEM_H(-0X1CF0, ctx->r1) = 0;
    // 0x80007178: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000717C: sh          $zero, 0x3E2($at)
    MEM_H(0X3E2, ctx->r1) = 0;
    // 0x80007180: j           L_80007314
    // 0x80007184: nop

        goto L_80007314;
    // 0x80007184: nop

L_80007188:
    // 0x80007188: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000718C: lhu         $v0, -0x1CF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X1CF0);
    // 0x80007190: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80007194: lh          $v1, 0x13EE($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X13EE);
    // 0x80007198: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x8000719C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800071A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800071A4: sh          $a0, -0x1CF0($at)
    MEM_H(-0X1CF0, ctx->r1) = ctx->r4;
    // 0x800071A8: bne         $v1, $v0, L_800072F4
    if (ctx->r3 != ctx->r2) {
        // 0x800071AC: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_800072F4;
    }
    // 0x800071AC: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x800071B0: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800071B4: addiu       $v0, $zero, 0x337
    ctx->r2 = ADD32(0, 0X337);
    // 0x800071B8: beq         $v1, $v0, L_80007214
    if (ctx->r3 == ctx->r2) {
        // 0x800071BC: slti        $v0, $v1, 0x338
        ctx->r2 = SIGNED(ctx->r3) < 0X338 ? 1 : 0;
            goto L_80007214;
    }
    // 0x800071BC: slti        $v0, $v1, 0x338
    ctx->r2 = SIGNED(ctx->r3) < 0X338 ? 1 : 0;
    // 0x800071C0: beq         $v0, $zero, L_800071D8
    if (ctx->r2 == 0) {
        // 0x800071C4: addiu       $v0, $zero, 0x334
        ctx->r2 = ADD32(0, 0X334);
            goto L_800071D8;
    }
    // 0x800071C4: addiu       $v0, $zero, 0x334
    ctx->r2 = ADD32(0, 0X334);
    // 0x800071C8: beq         $v1, $v0, L_800071EC
    if (ctx->r3 == ctx->r2) {
        // 0x800071CC: addiu       $v1, $zero, 0x258
        ctx->r3 = ADD32(0, 0X258);
            goto L_800071EC;
    }
    // 0x800071CC: addiu       $v1, $zero, 0x258
    ctx->r3 = ADD32(0, 0X258);
    // 0x800071D0: j           L_80007234
    // 0x800071D4: nop

        goto L_80007234;
    // 0x800071D4: nop

L_800071D8:
    // 0x800071D8: addiu       $v0, $zero, 0x33A
    ctx->r2 = ADD32(0, 0X33A);
    // 0x800071DC: beq         $v1, $v0, L_80007224
    if (ctx->r3 == ctx->r2) {
        // 0x800071E0: nop
    
            goto L_80007224;
    }
    // 0x800071E0: nop

    // 0x800071E4: j           L_80007234
    // 0x800071E8: nop

        goto L_80007234;
    // 0x800071E8: nop

L_800071EC:
    // 0x800071EC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800071F0: lw          $v0, 0x3238($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3238);
    // 0x800071F4: sh          $v1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r3;
    // 0x800071F8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800071FC: lw          $v0, 0x323C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X323C);
    // 0x80007200: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80007204: jal         0x80006EEC
    // 0x80007208: sh          $v1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r3;
    func_80006EEC(rdram, ctx);
        goto after_8;
    // 0x80007208: sh          $v1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r3;
    after_8:
    // 0x8000720C: j           L_800072F4
    // 0x80007210: nop

        goto L_800072F4;
    // 0x80007210: nop

L_80007214:
    // 0x80007214: jal         0x80006EEC
    // 0x80007218: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80006EEC(rdram, ctx);
        goto after_9;
    // 0x80007218: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_9:
    // 0x8000721C: j           L_800072F4
    // 0x80007220: nop

        goto L_800072F4;
    // 0x80007220: nop

L_80007224:
    // 0x80007224: jal         0x80006EEC
    // 0x80007228: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80006EEC(rdram, ctx);
        goto after_10;
    // 0x80007228: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_10:
    // 0x8000722C: j           L_800072F4
    // 0x80007230: nop

        goto L_800072F4;
    // 0x80007230: nop

L_80007234:
    // 0x80007234: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80007238: lh          $v0, -0x1CF0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X1CF0);
    // 0x8000723C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80007240: slti        $v0, $v0, 0xC8
    ctx->r2 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x80007244: beq         $v0, $zero, L_80007264
    if (ctx->r2 == 0) {
        // 0x80007248: addiu       $v0, $v1, -0x105
        ctx->r2 = ADD32(ctx->r3, -0X105);
            goto L_80007264;
    }
    // 0x80007248: addiu       $v0, $v1, -0x105
    ctx->r2 = ADD32(ctx->r3, -0X105);
    // 0x8000724C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80007250: lw          $v1, 0x4050($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4050);
    // 0x80007254: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x80007258: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8000725C: j           L_80007294
    // 0x80007260: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
        goto L_80007294;
    // 0x80007260: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
L_80007264:
    // 0x80007264: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80007268: sltiu       $v0, $v0, 0x211
    ctx->r2 = ctx->r2 < 0X211 ? 1 : 0;
    // 0x8000726C: beq         $v0, $zero, L_80007294
    if (ctx->r2 == 0) {
        // 0x80007270: nop
    
            goto L_80007294;
    }
    // 0x80007270: nop

    // 0x80007274: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80007278: lw          $v0, 0x4050($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4050);
    // 0x8000727C: lhu         $v1, 0x14($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X14);
    // 0x80007280: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80007284: addiu       $v1, $v1, -0x3
    ctx->r3 = ADD32(ctx->r3, -0X3);
    // 0x80007288: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x8000728C: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x80007290: sw          $a0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r4;
L_80007294:
    // 0x80007294: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80007298: lh          $v0, -0x1CF0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X1CF0);
    // 0x8000729C: slti        $v0, $v0, 0x317
    ctx->r2 = SIGNED(ctx->r2) < 0X317 ? 1 : 0;
    // 0x800072A0: bne         $v0, $zero, L_800072F4
    if (ctx->r2 != 0) {
        // 0x800072A4: nop
    
            goto L_800072F4;
    }
    // 0x800072A4: nop

    // 0x800072A8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800072AC: lw          $v1, 0x3238($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3238);
    // 0x800072B0: lhu         $v0, 0x14($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X14);
    // 0x800072B4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800072B8: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
    // 0x800072BC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800072C0: lw          $v1, 0x323C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X323C);
    // 0x800072C4: lhu         $v0, 0x14($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X14);
    // 0x800072C8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800072CC: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
    // 0x800072D0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800072D4: lw          $v1, 0x3238($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3238);
    // 0x800072D8: lh          $v0, 0x14($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X14);
    // 0x800072DC: blez        $v0, L_800072F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800072E0: addiu       $v0, $zero, 0x83
        ctx->r2 = ADD32(0, 0X83);
            goto L_800072F4;
    }
    // 0x800072E0: addiu       $v0, $zero, 0x83
    ctx->r2 = ADD32(0, 0X83);
    // 0x800072E4: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x800072E8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800072EC: lw          $v1, 0x323C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X323C);
    // 0x800072F0: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
L_800072F4:
    // 0x800072F4: jal         0x800521B0
    // 0x800072F8: nop

    func_800521B0(rdram, ctx);
        goto after_11;
    // 0x800072F8: nop

    after_11:
    // 0x800072FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80007300: lw          $a0, -0x2070($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2070);
    // 0x80007304: jal         0x80006B90
    // 0x80007308: nop

    func_80006B90(rdram, ctx);
        goto after_12;
    // 0x80007308: nop

    after_12:
    // 0x8000730C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007310: sw          $v0, -0x2070($at)
    MEM_W(-0X2070, ctx->r1) = ctx->r2;
L_80007314:
    // 0x80007314: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80007318: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000731C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80007320: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80007324: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80007328: jr          $ra
    // 0x8000732C: nop

    return;
    // 0x8000732C: nop

;}
