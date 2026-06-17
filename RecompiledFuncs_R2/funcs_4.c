#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80004078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004078: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8000407C: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80004078 falls into func_80004080
    func_80004080(rdram, ctx);
;}
RECOMP_FUNC void func_80004080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004084: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004088: addiu       $a0, $a0, -0x5EF8
    ctx->r4 = ADD32(ctx->r4, -0X5EF8);
    // 0x8000408C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004090: jal         0x80037DDC
    // 0x80004094: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x80004094: nop

    after_0:
    // 0x80004098: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000409C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800040A0: jr          $ra
    // 0x800040A4: nop

    return;
    // 0x800040A4: nop

;}
RECOMP_FUNC void func_800040A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800040A8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800040AC: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_800040A8 falls into func_800040B0
    func_800040B0(rdram, ctx);
;}
RECOMP_FUNC void func_800040B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800040B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800040B4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800040B8: addiu       $a0, $a0, -0x5EF8
    ctx->r4 = ADD32(ctx->r4, -0X5EF8);
    // 0x800040BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800040C0: jal         0x80037DDC
    // 0x800040C4: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800040C4: nop

    after_0:
    // 0x800040C8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800040CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800040D0: jr          $ra
    // 0x800040D4: nop

    return;
    // 0x800040D4: nop

;}
RECOMP_FUNC void func_800040D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800040D8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800040DC: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x800040E0: lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X22);
    // 0x800040E4: lui         $v1, 0xFFFE
    ctx->r3 = S32(0XFFFE << 16);
    // 0x800040E8: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800040EC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800040F0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800040F4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800040F8: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x800040FC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80004100: jr          $ra
    // 0x80004104: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    return;
    // 0x80004104: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80004108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004108: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000410C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80004110: jr          $ra
    // 0x80004114: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    return;
    // 0x80004114: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80004118: nop

    // 0x8000411C: nop

;}
RECOMP_FUNC void func_80004120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004120: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004124: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80004120 falls into func_80004128
    func_80004128(rdram, ctx);
;}
RECOMP_FUNC void func_80004128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000412C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004130: addiu       $a0, $a0, -0x5EF8
    ctx->r4 = ADD32(ctx->r4, -0X5EF8);
    // 0x80004134: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004138: jal         0x80037DDC
    // 0x8000413C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000413C: nop

    after_0:
    // 0x80004140: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004148: jr          $ra
    // 0x8000414C: nop

    return;
    // 0x8000414C: nop

;}
RECOMP_FUNC void func_80004150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004150: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004154: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80004150 falls into func_80004158
    func_80004158(rdram, ctx);
;}
RECOMP_FUNC void func_80004158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004158: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000415C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004160: addiu       $a0, $a0, -0x5EB8
    ctx->r4 = ADD32(ctx->r4, -0X5EB8);
    // 0x80004164: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004168: jal         0x80037DDC
    // 0x8000416C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000416C: nop

    after_0:
    // 0x80004170: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004178: jr          $ra
    // 0x8000417C: nop

    return;
    // 0x8000417C: nop

;}
RECOMP_FUNC void func_80004180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004180: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004184: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80004180 falls into func_80004188
    func_80004188(rdram, ctx);
;}
RECOMP_FUNC void func_80004188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000418C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004190: addiu       $a0, $a0, -0x5E80
    ctx->r4 = ADD32(ctx->r4, -0X5E80);
    // 0x80004194: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004198: jal         0x80037DDC
    // 0x8000419C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000419C: nop

    after_0:
    // 0x800041A0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800041A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800041A8: jr          $ra
    // 0x800041AC: nop

    return;
    // 0x800041AC: nop

;}
RECOMP_FUNC void func_800041B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800041B0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800041B4: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_800041B0 falls into func_800041B8
    func_800041B8(rdram, ctx);
;}
RECOMP_FUNC void func_800041B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800041B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800041BC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800041C0: addiu       $a0, $a0, -0x5E74
    ctx->r4 = ADD32(ctx->r4, -0X5E74);
    // 0x800041C4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800041C8: jal         0x80037DDC
    // 0x800041CC: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800041CC: nop

    after_0:
    // 0x800041D0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800041D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800041D8: jr          $ra
    // 0x800041DC: nop

    return;
    // 0x800041DC: nop

;}
RECOMP_FUNC void func_800041E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800041E0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800041E4: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_800041E0 falls into func_800041E8
    func_800041E8(rdram, ctx);
;}
RECOMP_FUNC void func_800041E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800041E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800041EC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800041F0: addiu       $a0, $a0, -0x5E04
    ctx->r4 = ADD32(ctx->r4, -0X5E04);
    // 0x800041F4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800041F8: jal         0x80037DDC
    // 0x800041FC: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800041FC: nop

    after_0:
    // 0x80004200: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004208: jr          $ra
    // 0x8000420C: nop

    return;
    // 0x8000420C: nop

;}
RECOMP_FUNC void func_80004210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004210: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004214: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80004210 falls into func_80004218
    func_80004218(rdram, ctx);
;}
RECOMP_FUNC void func_80004218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000421C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004220: addiu       $a0, $a0, -0x5D3C
    ctx->r4 = ADD32(ctx->r4, -0X5D3C);
    // 0x80004224: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004228: jal         0x80037DDC
    // 0x8000422C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000422C: nop

    after_0:
    // 0x80004230: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004238: jr          $ra
    // 0x8000423C: nop

    return;
    // 0x8000423C: nop

;}
RECOMP_FUNC void func_80004240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004240: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004244: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80004240 falls into func_80004248
    func_80004248(rdram, ctx);
;}
RECOMP_FUNC void func_80004248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000424C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004250: addiu       $a0, $a0, -0x5C1C
    ctx->r4 = ADD32(ctx->r4, -0X5C1C);
    // 0x80004254: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004258: jal         0x80037DDC
    // 0x8000425C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000425C: nop

    after_0:
    // 0x80004260: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004268: jr          $ra
    // 0x8000426C: nop

    return;
    // 0x8000426C: nop

;}
RECOMP_FUNC void func_80004270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004270: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004274: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80004270 falls into func_80004278
    func_80004278(rdram, ctx);
;}
RECOMP_FUNC void func_80004278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004278: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000427C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004280: addiu       $a0, $a0, -0x5C10
    ctx->r4 = ADD32(ctx->r4, -0X5C10);
    // 0x80004284: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004288: jal         0x80037DDC
    // 0x8000428C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000428C: nop

    after_0:
    // 0x80004290: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004298: jr          $ra
    // 0x8000429C: nop

    return;
    // 0x8000429C: nop

;}
RECOMP_FUNC void func_800042A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800042A0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800042A4: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_800042A0 falls into func_800042A8
    func_800042A8(rdram, ctx);
;}
RECOMP_FUNC void func_800042A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800042A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800042AC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800042B0: addiu       $a0, $a0, -0x5BF8
    ctx->r4 = ADD32(ctx->r4, -0X5BF8);
    // 0x800042B4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800042B8: jal         0x80037DDC
    // 0x800042BC: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800042BC: nop

    after_0:
    // 0x800042C0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800042C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800042C8: jr          $ra
    // 0x800042CC: nop

    return;
    // 0x800042CC: nop

;}
RECOMP_FUNC void func_800042D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800042D0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800042D4: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_800042D0 falls into func_800042D8
    func_800042D8(rdram, ctx);
;}
RECOMP_FUNC void func_800042D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800042D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800042DC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800042E0: addiu       $a0, $a0, -0x5BE0
    ctx->r4 = ADD32(ctx->r4, -0X5BE0);
    // 0x800042E4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800042E8: jal         0x80037DDC
    // 0x800042EC: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800042EC: nop

    after_0:
    // 0x800042F0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800042F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800042F8: jr          $ra
    // 0x800042FC: nop

    return;
    // 0x800042FC: nop

;}
RECOMP_FUNC void func_80004300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004300: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004304: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80004300 falls into func_80004308
    func_80004308(rdram, ctx);
;}
RECOMP_FUNC void func_80004308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000430C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004310: addiu       $a0, $a0, -0x5C1C
    ctx->r4 = ADD32(ctx->r4, -0X5C1C);
    // 0x80004314: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004318: jal         0x80037DDC
    // 0x8000431C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000431C: nop

    after_0:
    // 0x80004320: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004328: jr          $ra
    // 0x8000432C: nop

    return;
    // 0x8000432C: nop

;}
RECOMP_FUNC void func_80004330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004330: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004334: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80004330 falls into func_80004338
    func_80004338(rdram, ctx);
;}
RECOMP_FUNC void func_80004338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000433C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004340: addiu       $a0, $a0, -0x5B60
    ctx->r4 = ADD32(ctx->r4, -0X5B60);
    // 0x80004344: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004348: jal         0x80037DDC
    // 0x8000434C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000434C: nop

    after_0:
    // 0x80004350: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004358: jr          $ra
    // 0x8000435C: nop

    return;
    // 0x8000435C: nop

;}
RECOMP_FUNC void func_80004360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004360: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004364: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80004360 falls into func_80004368
    func_80004368(rdram, ctx);
;}
RECOMP_FUNC void func_80004368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004368: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000436C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004370: addiu       $a0, $a0, -0x5B48
    ctx->r4 = ADD32(ctx->r4, -0X5B48);
    // 0x80004374: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004378: jal         0x80037DDC
    // 0x8000437C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000437C: nop

    after_0:
    // 0x80004380: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004388: jr          $ra
    // 0x8000438C: nop

    return;
    // 0x8000438C: nop

;}
RECOMP_FUNC void func_80004390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004390: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004394: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80004390 falls into func_80004398
    func_80004398(rdram, ctx);
;}
RECOMP_FUNC void func_80004398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000439C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800043A0: addiu       $a0, $a0, -0x5B30
    ctx->r4 = ADD32(ctx->r4, -0X5B30);
    // 0x800043A4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800043A8: jal         0x80037DDC
    // 0x800043AC: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800043AC: nop

    after_0:
    // 0x800043B0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800043B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800043B8: jr          $ra
    // 0x800043BC: nop

    return;
    // 0x800043BC: nop

;}
RECOMP_FUNC void func_800043C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800043C0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800043C4: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_800043C0 falls into func_800043C8
    func_800043C8(rdram, ctx);
;}
RECOMP_FUNC void func_800043C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800043C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800043CC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800043D0: addiu       $a0, $a0, -0x5C1C
    ctx->r4 = ADD32(ctx->r4, -0X5C1C);
    // 0x800043D4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800043D8: jal         0x80037DDC
    // 0x800043DC: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800043DC: nop

    after_0:
    // 0x800043E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800043E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800043E8: jr          $ra
    // 0x800043EC: nop

    return;
    // 0x800043EC: nop

;}
RECOMP_FUNC void func_800043F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800043F0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800043F4: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_800043F0 falls into func_800043F8
    func_800043F8(rdram, ctx);
;}
RECOMP_FUNC void func_800043F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800043F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800043FC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004400: addiu       $a0, $a0, -0x59C4
    ctx->r4 = ADD32(ctx->r4, -0X59C4);
    // 0x80004404: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004408: jal         0x80037DDC
    // 0x8000440C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000440C: nop

    after_0:
    // 0x80004410: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004418: jr          $ra
    // 0x8000441C: nop

    return;
    // 0x8000441C: nop

;}
RECOMP_FUNC void func_80004420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004420: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004424: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80004420 falls into func_80004428
    func_80004428(rdram, ctx);
;}
RECOMP_FUNC void func_80004428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000442C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004430: addiu       $a0, $a0, -0x5994
    ctx->r4 = ADD32(ctx->r4, -0X5994);
    // 0x80004434: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004438: jal         0x80037DDC
    // 0x8000443C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000443C: nop

    after_0:
    // 0x80004440: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004448: jr          $ra
    // 0x8000444C: nop

    return;
    // 0x8000444C: nop

;}
RECOMP_FUNC void func_80004450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004450: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004454: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80004450 falls into func_80004458
    func_80004458(rdram, ctx);
;}
RECOMP_FUNC void func_80004458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000445C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004460: addiu       $a0, $a0, -0x596C
    ctx->r4 = ADD32(ctx->r4, -0X596C);
    // 0x80004464: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004468: jal         0x80037DDC
    // 0x8000446C: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x8000446C: nop

    after_0:
    // 0x80004470: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004478: jr          $ra
    // 0x8000447C: nop

    return;
    // 0x8000447C: nop

;}
RECOMP_FUNC void func_80004480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004484: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004488: jal         0x80014DEC
    // 0x8000448C: nop

    func_80014DEC(rdram, ctx);
        goto after_0;
    // 0x8000448C: nop

    after_0:
    // 0x80004490: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80004494: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x80004498: beq         $v0, $zero, L_800044F4
    if (ctx->r2 == 0) {
        // 0x8000449C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800044F4;
    }
    // 0x8000449C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800044A0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800044A4: addu        $at, $at, $v0
    gpr jr_addend_800044AC = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800044A8: lw          $v0, 0x3330($at)
    ctx->r2 = ADD32(ctx->r1, 0X3330);
    // 0x800044AC: jr          $v0
    // 0x800044B0: nop

    switch (jr_addend_800044AC >> 2) {
        case 0: goto L_800044B4; break;
        case 1: goto L_800044C4; break;
        case 2: goto L_800044C4; break;
        case 3: goto L_800044D4; break;
        case 4: goto L_800044D4; break;
        case 5: goto L_800044E4; break;
        case 6: goto L_800044E4; break;
        default: switch_error(__func__, 0x800044AC, 0x80093330);
    }
    // 0x800044B0: nop

L_800044B4:
    // 0x800044B4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800044B8: addiu       $a0, $a0, -0x5960
    ctx->r4 = ADD32(ctx->r4, -0X5960);
    // 0x800044BC: j           L_800044FC
    // 0x800044C0: nop

        goto L_800044FC;
    // 0x800044C0: nop

L_800044C4:
    // 0x800044C4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800044C8: addiu       $a0, $a0, -0x58D4
    ctx->r4 = ADD32(ctx->r4, -0X58D4);
    // 0x800044CC: j           L_800044FC
    // 0x800044D0: nop

        goto L_800044FC;
    // 0x800044D0: nop

L_800044D4:
    // 0x800044D4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800044D8: addiu       $a0, $a0, -0x5848
    ctx->r4 = ADD32(ctx->r4, -0X5848);
    // 0x800044DC: j           L_800044FC
    // 0x800044E0: nop

        goto L_800044FC;
    // 0x800044E0: nop

L_800044E4:
    // 0x800044E4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800044E8: addiu       $a0, $a0, -0x57BC
    ctx->r4 = ADD32(ctx->r4, -0X57BC);
    // 0x800044EC: j           L_800044FC
    // 0x800044F0: nop

        goto L_800044FC;
    // 0x800044F0: nop

L_800044F4:
    // 0x800044F4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800044F8: addiu       $a0, $a0, -0x5730
    ctx->r4 = ADD32(ctx->r4, -0X5730);
L_800044FC:
    // 0x800044FC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004500: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80004504: jal         0x80037DDC
    // 0x80004508: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x80004508: nop

    after_1:
    // 0x8000450C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004510: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004514: jr          $ra
    // 0x80004518: nop

    return;
    // 0x80004518: nop

;}
RECOMP_FUNC void func_8000451C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000451C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004520: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004524: jal         0x80014DEC
    // 0x80004528: nop

    func_80014DEC(rdram, ctx);
        goto after_0;
    // 0x80004528: nop

    after_0:
    // 0x8000452C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80004530: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80004534: beq         $v0, $zero, L_800045A0
    if (ctx->r2 == 0) {
        // 0x80004538: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800045A0;
    }
    // 0x80004538: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8000453C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80004540: addu        $at, $at, $v0
    gpr jr_addend_80004548 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80004544: lw          $v0, 0x3350($at)
    ctx->r2 = ADD32(ctx->r1, 0X3350);
    // 0x80004548: jr          $v0
    // 0x8000454C: nop

    switch (jr_addend_80004548 >> 2) {
        case 0: goto L_80004550; break;
        case 1: goto L_80004550; break;
        case 2: goto L_80004560; break;
        case 3: goto L_80004570; break;
        case 4: goto L_80004580; break;
        case 5: goto L_80004590; break;
        default: switch_error(__func__, 0x80004548, 0x80093350);
    }
    // 0x8000454C: nop

L_80004550:
    // 0x80004550: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004554: addiu       $a0, $a0, -0x55A4
    ctx->r4 = ADD32(ctx->r4, -0X55A4);
    // 0x80004558: j           L_800045A8
    // 0x8000455C: nop

        goto L_800045A8;
    // 0x8000455C: nop

L_80004560:
    // 0x80004560: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004564: addiu       $a0, $a0, -0x54A4
    ctx->r4 = ADD32(ctx->r4, -0X54A4);
    // 0x80004568: j           L_800045A8
    // 0x8000456C: nop

        goto L_800045A8;
    // 0x8000456C: nop

L_80004570:
    // 0x80004570: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004574: addiu       $a0, $a0, -0x53A4
    ctx->r4 = ADD32(ctx->r4, -0X53A4);
    // 0x80004578: j           L_800045A8
    // 0x8000457C: nop

        goto L_800045A8;
    // 0x8000457C: nop

L_80004580:
    // 0x80004580: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004584: addiu       $a0, $a0, -0x52A4
    ctx->r4 = ADD32(ctx->r4, -0X52A4);
    // 0x80004588: j           L_800045A8
    // 0x8000458C: nop

        goto L_800045A8;
    // 0x8000458C: nop

L_80004590:
    // 0x80004590: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004594: addiu       $a0, $a0, -0x51A4
    ctx->r4 = ADD32(ctx->r4, -0X51A4);
    // 0x80004598: j           L_800045A8
    // 0x8000459C: nop

        goto L_800045A8;
    // 0x8000459C: nop

L_800045A0:
    // 0x800045A0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800045A4: addiu       $a0, $a0, -0x50A4
    ctx->r4 = ADD32(ctx->r4, -0X50A4);
L_800045A8:
    // 0x800045A8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800045AC: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x800045B0: jal         0x80037DDC
    // 0x800045B4: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x800045B4: nop

    after_1:
    // 0x800045B8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800045BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800045C0: jr          $ra
    // 0x800045C4: nop

    return;
    // 0x800045C4: nop

;}
RECOMP_FUNC void func_800045C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800045C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800045CC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800045D0: jal         0x80014DEC
    // 0x800045D4: nop

    func_80014DEC(rdram, ctx);
        goto after_0;
    // 0x800045D4: nop

    after_0:
    // 0x800045D8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x800045DC: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x800045E0: beq         $v0, $zero, L_8000464C
    if (ctx->r2 == 0) {
        // 0x800045E4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8000464C;
    }
    // 0x800045E4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800045E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800045EC: addu        $at, $at, $v0
    gpr jr_addend_800045F4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800045F0: lw          $v0, 0x3368($at)
    ctx->r2 = ADD32(ctx->r1, 0X3368);
    // 0x800045F4: jr          $v0
    // 0x800045F8: nop

    switch (jr_addend_800045F4 >> 2) {
        case 0: goto L_800045FC; break;
        case 1: goto L_800045FC; break;
        case 2: goto L_8000460C; break;
        case 3: goto L_8000461C; break;
        case 4: goto L_8000462C; break;
        case 5: goto L_8000463C; break;
        default: switch_error(__func__, 0x800045F4, 0x80093368);
    }
    // 0x800045F8: nop

L_800045FC:
    // 0x800045FC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004600: addiu       $a0, $a0, -0x4D30
    ctx->r4 = ADD32(ctx->r4, -0X4D30);
    // 0x80004604: j           L_80004654
    // 0x80004608: nop

        goto L_80004654;
    // 0x80004608: nop

L_8000460C:
    // 0x8000460C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004610: addiu       $a0, $a0, -0x4BBC
    ctx->r4 = ADD32(ctx->r4, -0X4BBC);
    // 0x80004614: j           L_80004654
    // 0x80004618: nop

        goto L_80004654;
    // 0x80004618: nop

L_8000461C:
    // 0x8000461C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004620: addiu       $a0, $a0, -0x4A48
    ctx->r4 = ADD32(ctx->r4, -0X4A48);
    // 0x80004624: j           L_80004654
    // 0x80004628: nop

        goto L_80004654;
    // 0x80004628: nop

L_8000462C:
    // 0x8000462C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004630: addiu       $a0, $a0, -0x48D4
    ctx->r4 = ADD32(ctx->r4, -0X48D4);
    // 0x80004634: j           L_80004654
    // 0x80004638: nop

        goto L_80004654;
    // 0x80004638: nop

L_8000463C:
    // 0x8000463C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004640: addiu       $a0, $a0, -0x4760
    ctx->r4 = ADD32(ctx->r4, -0X4760);
    // 0x80004644: j           L_80004654
    // 0x80004648: nop

        goto L_80004654;
    // 0x80004648: nop

L_8000464C:
    // 0x8000464C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004650: addiu       $a0, $a0, -0x45EC
    ctx->r4 = ADD32(ctx->r4, -0X45EC);
L_80004654:
    // 0x80004654: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004658: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x8000465C: jal         0x80037DDC
    // 0x80004660: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x80004660: nop

    after_1:
    // 0x80004664: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000466C: jr          $ra
    // 0x80004670: nop

    return;
    // 0x80004670: nop

;}
RECOMP_FUNC void func_80004674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004674: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80004678: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_80004674 falls into func_8000467C
    func_8000467C(rdram, ctx);
;}
RECOMP_FUNC void func_8000467C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000467C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004680: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80004684: addiu       $a0, $a0, -0x5AD0
    ctx->r4 = ADD32(ctx->r4, -0X5AD0);
    // 0x80004688: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000468C: jal         0x80037DDC
    // 0x80004690: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x80004690: nop

    after_0:
    // 0x80004694: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000469C: jr          $ra
    // 0x800046A0: nop

    return;
    // 0x800046A0: nop

;}
RECOMP_FUNC void func_800046A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800046A4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800046A8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // FALLTHROUGH: func_800046A4 falls into func_800046AC
    func_800046AC(rdram, ctx);
;}
RECOMP_FUNC void func_800046AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800046AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800046B0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800046B4: addiu       $a0, $a0, -0x5AA8
    ctx->r4 = ADD32(ctx->r4, -0X5AA8);
    // 0x800046B8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800046BC: jal         0x80037DDC
    // 0x800046C0: nop

    func_80037DDC(rdram, ctx);
        goto after_0;
    // 0x800046C0: nop

    after_0:
    // 0x800046C4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800046C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800046CC: jr          $ra
    // 0x800046D0: nop

    return;
    // 0x800046D0: nop

;}
RECOMP_FUNC void func_800046D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800046D4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800046D8: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_800046DC
    func_800046DC(rdram, ctx);
}
