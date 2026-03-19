#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_80001884(uint8_t* rdram, recomp_context* ctx);
void func_80001A38(uint8_t* rdram, recomp_context* ctx);
void func_80001B40(uint8_t* rdram, recomp_context* ctx);
void func_80001FA0(uint8_t* rdram, recomp_context* ctx);
void func_800028FC(uint8_t* rdram, recomp_context* ctx);
void func_800029D0(uint8_t* rdram, recomp_context* ctx);
void func_800029F0(uint8_t* rdram, recomp_context* ctx);
void func_80002A10(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80001488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000148C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80001490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001494: jal         0x800012DC
    // 0x80001498: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_800012DC(rdram, ctx);
        goto after_0;
    // 0x80001498: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8000149C: lui         $a0, 0x40
    ctx->r4 = S32(0X40 << 16);
    // 0x800014A0: ori         $a0, $a0, 0x1005
    ctx->r4 = ctx->r4 | 0X1005;
    // 0x800014A4: srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // 0x800014A8: nop

    // 0x800014AC: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800014B0: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x800014B4: mfhi        $a0
    ctx->r4 = hi;
    // 0x800014B8: nop

    // 0x800014BC: nop

    // 0x800014C0: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
    // 0x800014C4: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x800014C8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800014CC: srl         $a0, $a0, 9
    ctx->r4 = S32(U32(ctx->r4) >> 9);
    // 0x800014D0: sll         $v1, $a0, 10
    ctx->r3 = S32(ctx->r4 << 10);
    // 0x800014D4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800014D8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800014DC: sltu        $s0, $v0, $s0
    ctx->r16 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x800014E0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800014E4: sh          $s0, 0x3218($at)
    MEM_H(0X3218, ctx->r1) = ctx->r16;
    // 0x800014E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800014EC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800014F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800014F4: jr          $ra
    // 0x800014F8: nop

    return;
    // 0x800014F8: nop

;}
RECOMP_FUNC void func_800014FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800014FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001500: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80001504: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80001508: lw          $s0, 0x46B0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X46B0);
    // 0x8000150C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001510: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80001514: sw          $zero, 0x46B0($at)
    MEM_W(0X46B0, ctx->r1) = 0;
    // 0x80001518: jal         0x800029D0
    // 0x8000151C: nop

    func_800029D0(rdram, ctx);
        goto after_0;
    // 0x8000151C: nop

    after_0:
    // 0x80001520: jal         0x800029F0
    // 0x80001524: nop

    func_800029F0(rdram, ctx);
        goto after_1;
    // 0x80001524: nop

    after_1:
    // 0x80001528: jal         0x800029D0
    // 0x8000152C: nop

    func_800029D0(rdram, ctx);
        goto after_2;
    // 0x8000152C: nop

    after_2:
    // 0x80001530: jal         0x800029F0
    // 0x80001534: nop

    func_800029F0(rdram, ctx);
        goto after_3;
    // 0x80001534: nop

    after_3:
    // 0x80001538: jal         0x800029D0
    // 0x8000153C: nop

    func_800029D0(rdram, ctx);
        goto after_4;
    // 0x8000153C: nop

    after_4:
    // 0x80001540: jal         0x800029F0
    // 0x80001544: nop

    func_800029F0(rdram, ctx);
        goto after_5;
    // 0x80001544: nop

    after_5:
    // 0x80001548: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000154C: sw          $s0, 0x46B0($at)
    MEM_W(0X46B0, ctx->r1) = ctx->r16;
    // 0x80001550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001554: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80001558: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000155C: jr          $ra
    // 0x80001560: nop

    return;
    // 0x80001560: nop

;}
RECOMP_FUNC void func_80001564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001564: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001568: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8000156C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80001570: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80001574: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80001578: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000157C: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x80001580: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80001584: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80001588: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8000158C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80001590: jal         0x800306EC
    // 0x80001594: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80001594: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80001598: addiu       $v1, $zero, 0x7000
    ctx->r3 = ADD32(0, 0X7000);
    // 0x8000159C: sh          $s2, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r18;
    // 0x800015A0: sh          $s3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r19;
    // 0x800015A4: jal         0x80023E44
    // 0x800015A8: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x800015A8: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    after_1:
    // 0x800015AC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800015B0: addiu       $a0, $a0, 0x31C0
    ctx->r4 = ADD32(ctx->r4, 0X31C0);
    // 0x800015B4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800015B8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800015BC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800015C0: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x800015C4: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800015C8: sw          $s0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r16;
    // 0x800015CC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800015D0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800015D4: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x800015D8: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800015DC: sw          $s1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r17;
    // 0x800015E0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800015E4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800015E8: sw          $s4, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r20;
    // 0x800015EC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800015F0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800015F4: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x800015F8: ori         $v0, $v0, 0xC
    ctx->r2 = ctx->r2 | 0XC;
    // 0x800015FC: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x80001600: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80001604: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80001608: lhu         $v0, 0x6C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6C);
    // 0x8000160C: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x80001610: sh          $v0, 0x6C($v1)
    MEM_H(0X6C, ctx->r3) = ctx->r2;
    // 0x80001614: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80001618: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000161C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80001620: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80001624: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80001628: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8000162C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80001630: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80001634: jr          $ra
    // 0x80001638: nop

    return;
    // 0x80001638: nop

;}
RECOMP_FUNC void func_8000163C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000163C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80001640: addiu       $a2, $a2, 0x120
    ctx->r6 = ADD32(ctx->r6, 0X120);
    // 0x80001644: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80001648: beq         $v1, $a2, L_80001668
    if (ctx->r3 == ctx->r6) {
        // 0x8000164C: nop
    
            goto L_80001668;
    }
    // 0x8000164C: nop

L_80001650:
    // 0x80001650: lhu         $v0, 0x70($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X70);
    // 0x80001654: beql        $v0, $a0, L_8000165C
    if (ctx->r2 == ctx->r4) {
        // 0x80001658: sh          $a1, 0x74($v1)
        MEM_H(0X74, ctx->r3) = ctx->r5;
            goto L_8000165C;
    }
    goto skip_0;
    // 0x80001658: sh          $a1, 0x74($v1)
    MEM_H(0X74, ctx->r3) = ctx->r5;
    skip_0:
L_8000165C:
    // 0x8000165C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80001660: bne         $v1, $a2, L_80001650
    if (ctx->r3 != ctx->r6) {
        // 0x80001664: nop
    
            goto L_80001650;
    }
    // 0x80001664: nop

L_80001668:
    // 0x80001668: jr          $ra
    // 0x8000166C: nop

    return;
    // 0x8000166C: nop

;}
RECOMP_FUNC void func_80001670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001670: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001674: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80001678: lui         $t1, 0x6666
    ctx->r9 = S32(0X6666 << 16);
    // 0x8000167C: ori         $t1, $t1, 0x6667
    ctx->r9 = ctx->r9 | 0X6667;
    // 0x80001680: addu        $a3, $sp, $zero
    ctx->r7 = ADD32(ctx->r29, 0);
L_80001684:
    // 0x80001684: nop

    // 0x80001688: mult        $a1, $t1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000168C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80001690: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80001694: sra         $v0, $a1, 31
    ctx->r2 = S32(SIGNED(ctx->r5) >> 31);
    // 0x80001698: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x8000169C: mfhi        $t2
    ctx->r10 = hi;
    // 0x800016A0: nop

    // 0x800016A4: nop

    // 0x800016A8: sra         $v1, $t2, 2
    ctx->r3 = S32(SIGNED(ctx->r10) >> 2);
    // 0x800016AC: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // 0x800016B0: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800016B4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800016B8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800016BC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800016C0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800016C4: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x800016C8: sltu        $v0, $zero, $a1
    ctx->r2 = 0 < ctx->r5 ? 1 : 0;
    // 0x800016CC: slt         $v1, $zero, $a2
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800016D0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800016D4: bne         $v0, $zero, L_80001684
    if (ctx->r2 != 0) {
        // 0x800016D8: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80001684;
    }
    // 0x800016D8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800016DC: addu        $a2, $a0, $t0
    ctx->r6 = ADD32(ctx->r4, ctx->r8);
    // 0x800016E0: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x800016E4: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x800016E8: blez        $t0, L_80001714
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800016EC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80001714;
    }
    // 0x800016EC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800016F0: addu        $a1, $sp, $zero
    ctx->r5 = ADD32(ctx->r29, 0);
L_800016F4:
    // 0x800016F4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800016F8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800016FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80001700: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x80001704: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80001708: slt         $v0, $v1, $t0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000170C: bne         $v0, $zero, L_800016F4
    if (ctx->r2 != 0) {
        // 0x80001710: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800016F4;
    }
    // 0x80001710: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80001714:
    // 0x80001714: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x80001718: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000171C: jr          $ra
    // 0x80001720: nop

    return;
    // 0x80001720: nop

    // 0x80001724: nop

    // 0x80001728: nop

    // 0x8000172C: nop

;}
RECOMP_FUNC void func_80001730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001730: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80001734: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80001738: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000173C: sh          $v0, -0x24BA($at)
    MEM_H(-0X24BA, ctx->r1) = ctx->r2;
    // 0x80001740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001744: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80001748: sh          $v0, -0x306E($at)
    MEM_H(-0X306E, ctx->r1) = ctx->r2;
    // 0x8000174C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80001750: sh          $v0, -0x306C($at)
    MEM_H(-0X306C, ctx->r1) = ctx->r2;
    // 0x80001754: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80001758: sh          $v0, -0x306A($at)
    MEM_H(-0X306A, ctx->r1) = ctx->r2;
    // 0x8000175C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80001760: sh          $v0, -0x3068($at)
    MEM_H(-0X3068, ctx->r1) = ctx->r2;
    // 0x80001764: addiu       $v0, $zero, 0x688
    ctx->r2 = ADD32(0, 0X688);
    // 0x80001768: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000176C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80001770: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80001774: sh          $zero, -0x3074($at)
    MEM_H(-0X3074, ctx->r1) = 0;
    // 0x80001778: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8000177C: sh          $zero, -0x3072($at)
    MEM_H(-0X3072, ctx->r1) = 0;
    // 0x80001780: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80001784: sh          $zero, -0x3070($at)
    MEM_H(-0X3070, ctx->r1) = 0;
    // 0x80001788: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000178C: sh          $zero, 0x5710($at)
    MEM_H(0X5710, ctx->r1) = 0;
    // 0x80001790: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001794: sh          $v0, -0x1D3C($at)
    MEM_H(-0X1D3C, ctx->r1) = ctx->r2;
L_80001798:
    // 0x80001798: jal         0x80001884
    // 0x8000179C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    func_80001884(rdram, ctx);
        goto after_0;
    // 0x8000179C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_0:
    // 0x800017A0: jal         0x80002A10
    // 0x800017A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80002A10(rdram, ctx);
        goto after_1;
    // 0x800017A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_800017A8:
    // YIELD: R2's render loop doesn't block on osRecvMesg like WT's does.
    // On real N64, Thread 3 (pri=90) preempts via hardware interrupts.
    // In ultramodern's cooperative scheduler, we must yield to let the
    // idle thread deliver external messages (VI, timer) to higher-priority threads.
    yield_self_1ms(rdram);
    // 0x800017A8: jal         0x800029D0
    // 0x800017AC: nop

    func_800029D0(rdram, ctx);
        goto after_2;
    // 0x800017AC: nop

    after_2:
    // 0x800017B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800017B4: lhu         $v0, -0x9F0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X9F0);
    // 0x800017B8: bne         $v0, $zero, L_80001820
    if (ctx->r2 != 0) {
        // 0x800017BC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80001820;
    }
    // 0x800017BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800017C0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800017C4: sh          $v0, -0x9F0($at)
    MEM_H(-0X9F0, ctx->r1) = ctx->r2;
    // 0x800017C8: jal         0x80001B40
    // 0x800017CC: nop

    func_80001B40(rdram, ctx);
        goto after_3;
    // 0x800017CC: nop

    after_3:
    // 0x800017D0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800017D4: lh          $v0, 0x4756($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4756);
    // 0x800017D8: blez        $v0, L_800017EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800017DC: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_800017EC;
    }
    // 0x800017DC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800017E0: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x800017E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800017E8: sh          $v0, 0x4756($at)
    MEM_H(0X4756, ctx->r1) = ctx->r2;
L_800017EC:
    // 0x800017EC: jal         0x80001FA0
    // 0x800017F0: nop

    func_80001FA0(rdram, ctx);
        goto after_4;
    // 0x800017F0: nop

    after_4:
    // 0x800017F4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800017F8: beq         $v0, $s0, L_80001798
    if (ctx->r2 == ctx->r16) {
        // 0x800017FC: nop
    
            goto L_80001798;
    }
    // 0x800017FC: nop

    // 0x80001800: jal         0x800006F4
    // 0x80001804: nop

    func_800006F4(rdram, ctx);
        goto after_5;
    // 0x80001804: nop

    after_5:
    // 0x80001808: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000180C: lhu         $v0, 0x1A2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1A2);
    // 0x80001810: bne         $v0, $zero, L_80001820
    if (ctx->r2 != 0) {
        // 0x80001814: nop
    
            goto L_80001820;
    }
    // 0x80001814: nop

    // 0x80001818: jal         0x8002E7A0
    // 0x8000181C: nop

    func_8002E7A0(rdram, ctx);
        goto after_6;
    // 0x8000181C: nop

    after_6:
L_80001820:
    // 0x80001820: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80001824: lhu         $v0, 0x32A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X32A0);
    // 0x80001828: beq         $v0, $zero, L_80001848
    if (ctx->r2 == 0) {
        // 0x8000182C: nop
    
            goto L_80001848;
    }
    // 0x8000182C: nop

    // 0x80001830: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80001834: sh          $zero, -0x9F0($at)
    MEM_H(-0X9F0, ctx->r1) = 0;
    // 0x80001838: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000183C: sh          $zero, 0x5574($at)
    MEM_H(0X5574, ctx->r1) = 0;
    // 0x80001840: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001844: sh          $zero, 0x32A0($at)
    MEM_H(0X32A0, ctx->r1) = 0;
L_80001848:
    // 0x80001848: jal         0x800012DC
    // 0x8000184C: nop

    func_800012DC(rdram, ctx);
        goto after_7;
    // 0x8000184C: nop

    after_7:
    // 0x80001850: jal         0x800241B8
    // 0x80001854: nop

    func_800241B8(rdram, ctx);
        goto after_8;
    // 0x80001854: nop

    after_8:
    // 0x80001858: jal         0x80023A70
    // 0x8000185C: nop

    func_80023A70(rdram, ctx);
        goto after_9;
    // 0x8000185C: nop

    after_9:
    // 0x80001860: jal         0x800029F0
    // 0x80001864: nop

    func_800029F0(rdram, ctx);
        goto after_10;
    // 0x80001864: nop

    after_10:
    // 0x80001868: j           L_800017A8
    // 0x8000186C: nop

        goto L_800017A8;
    // 0x8000186C: nop

    // 0x80001870: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80001874: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001878: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000187C: jr          $ra
    // 0x80001880: nop

    return;
    // 0x80001880: nop

;}
RECOMP_FUNC void func_80001884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001884: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001888: addiu       $v0, $zero, 0x110
    ctx->r2 = ADD32(0, 0X110);
    // 0x8000188C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80001890: sh          $v0, 0x90($at)
    MEM_H(0X90, ctx->r1) = ctx->r2;
    // 0x80001894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001898: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000189C: addiu       $a0, $a0, 0x57E0
    ctx->r4 = ADD32(ctx->r4, 0X57E0);
    // 0x800018A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800018A4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800018A8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800018AC: sh          $zero, -0x6C80($at)
    MEM_H(-0X6C80, ctx->r1) = 0;
    // 0x800018B0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800018B4: sh          $zero, -0x68E0($at)
    MEM_H(-0X68E0, ctx->r1) = 0;
    // 0x800018B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800018BC: sh          $zero, 0x4E66($at)
    MEM_H(0X4E66, ctx->r1) = 0;
    // 0x800018C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800018C4: sw          $zero, 0x46B0($at)
    MEM_W(0X46B0, ctx->r1) = 0;
    // 0x800018C8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800018CC: sh          $v0, 0x2584($at)
    MEM_H(0X2584, ctx->r1) = ctx->r2;
    // 0x800018D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800018D4: sh          $zero, 0x98($at)
    MEM_H(0X98, ctx->r1) = 0;
    // 0x800018D8: jal         0x8007DEC0
    // 0x800018DC: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    func_8007DEC0(rdram, ctx);
        goto after_0;
    // 0x800018DC: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_0:
    // 0x800018E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800018E4: sw          $zero, -0x1030($at)
    MEM_W(-0X1030, ctx->r1) = 0;
    // 0x800018E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800018EC: sw          $zero, -0x102C($at)
    MEM_W(-0X102C, ctx->r1) = 0;
    // 0x800018F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800018F4: sw          $zero, -0x1028($at)
    MEM_W(-0X1028, ctx->r1) = 0;
    // 0x800018F8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800018FC: sw          $zero, -0x1024($at)
    MEM_W(-0X1024, ctx->r1) = 0;
    // 0x80001900: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80001904: sw          $zero, -0x1020($at)
    MEM_W(-0X1020, ctx->r1) = 0;
    // 0x80001908: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8000190C: sw          $zero, -0x101C($at)
    MEM_W(-0X101C, ctx->r1) = 0;
    // 0x80001910: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80001914: sw          $zero, -0x1018($at)
    MEM_W(-0X1018, ctx->r1) = 0;
    // 0x80001918: jal         0x8000074C
    // 0x8000191C: nop

    func_8000074C(rdram, ctx);
        goto after_1;
    // 0x8000191C: nop

    after_1:
    // 0x80001920: jal         0x800242C0
    // 0x80001924: nop

    func_800242C0(rdram, ctx);
        goto after_2;
    // 0x80001924: nop

    after_2:
    // 0x80001928: jal         0x800011B8
    // 0x8000192C: nop

    func_800011B8(rdram, ctx);
        goto after_3;
    // 0x8000192C: nop

    after_3:
    // 0x80001930: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80001934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001938: jr          $ra
    // 0x8000193C: nop

    return;
    // 0x8000193C: nop

;}
RECOMP_FUNC void func_80001940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001944: addiu       $v0, $zero, 0x55
    ctx->r2 = ADD32(0, 0X55);
    // 0x80001948: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8000194C: sh          $v0, -0x5634($at)
    MEM_H(-0X5634, ctx->r1) = ctx->r2;
    // 0x80001950: addiu       $v0, $zero, 0x72
    ctx->r2 = ADD32(0, 0X72);
    // 0x80001954: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80001958: sh          $v0, 0x416A($at)
    MEM_H(0X416A, ctx->r1) = ctx->r2;
    // 0x8000195C: addiu       $v0, $zero, 0x677
    ctx->r2 = ADD32(0, 0X677);
    // 0x80001960: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80001964: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80001968: sh          $zero, 0x4148($at)
    MEM_H(0X4148, ctx->r1) = 0;
    // 0x8000196C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80001970: sh          $zero, 0x3AC($at)
    MEM_H(0X3AC, ctx->r1) = 0;
    // 0x80001974: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80001978: sh          $zero, -0x305A($at)
    MEM_H(-0X305A, ctx->r1) = 0;
    // 0x8000197C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001980: sh          $zero, 0x3AC8($at)
    MEM_H(0X3AC8, ctx->r1) = 0;
    // 0x80001984: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001988: sh          $v0, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r2;
    // 0x8000198C: jal         0x8001F0B8
    // 0x80001990: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    func_8001F0B8(rdram, ctx);
        goto after_0;
    // 0x80001990: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    after_0:
    // 0x80001994: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80001998: lbu         $a0, -0x5633($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X5633);
    // 0x8000199C: jal         0x8001F098
    // 0x800019A0: nop

    func_8001F098(rdram, ctx);
        goto after_1;
    // 0x800019A0: nop

    after_1:
    // 0x800019A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800019A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800019AC: sw          $v0, 0x4DF8($at)
    MEM_W(0X4DF8, ctx->r1) = ctx->r2;
    // 0x800019B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800019B4: sw          $v0, 0x4DFC($at)
    MEM_W(0X4DFC, ctx->r1) = ctx->r2;
    // 0x800019B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800019BC: sw          $v0, 0x4E00($at)
    MEM_W(0X4E00, ctx->r1) = ctx->r2;
    // 0x800019C0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800019C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800019C8: jr          $ra
    // 0x800019CC: nop

    return;
    // 0x800019CC: nop

;}
RECOMP_FUNC void func_800019D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800019D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800019D4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800019D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800019DC: sh          $zero, -0x5B00($at)
    MEM_H(-0X5B00, ctx->r1) = 0;
    // 0x800019E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800019E4: sh          $zero, -0x1D04($at)
    MEM_H(-0X1D04, ctx->r1) = 0;
    // 0x800019E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800019EC: sh          $zero, -0x740A($at)
    MEM_H(-0X740A, ctx->r1) = 0;
    // 0x800019F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800019F4: sw          $zero, 0x46B0($at)
    MEM_W(0X46B0, ctx->r1) = 0;
    // 0x800019F8: jal         0x800014FC
    // 0x800019FC: nop

    func_800014FC(rdram, ctx);
        goto after_0;
    // 0x800019FC: nop

    after_0:
    // 0x80001A00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80001A04: sh          $zero, 0x148($at)
    MEM_H(0X148, ctx->r1) = 0;
    // 0x80001A08: jal         0x80002A10
    // 0x80001A0C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80002A10(rdram, ctx);
        goto after_1;
    // 0x80001A0C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x80001A10: jal         0x80001A38
    // 0x80001A14: nop

    func_80001A38(rdram, ctx);
        goto after_2;
    // 0x80001A14: nop

    after_2:
    // 0x80001A18: jal         0x800011B8
    // 0x80001A1C: nop

    func_800011B8(rdram, ctx);
        goto after_3;
    // 0x80001A1C: nop

    after_3:
    // 0x80001A20: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80001A24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001A28: jr          $ra
    // 0x80001A2C: nop

    return;
    // 0x80001A2C: nop

;}
RECOMP_FUNC void func_80001A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001A30: jr          $ra
    // 0x80001A34: nop

    return;
    // 0x80001A34: nop

;}
RECOMP_FUNC void func_80001A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001A38: jr          $ra
    // 0x80001A3C: nop

    return;
    // 0x80001A3C: nop

;}
RECOMP_FUNC void func_80001A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001A40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001A44: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80001A48: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80001A4C: addiu       $a0, $a0, 0x140
    ctx->r4 = ADD32(ctx->r4, 0X140);
    // 0x80001A50: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001A54: jal         0x8007DEC0
    // 0x80001A58: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_8007DEC0(rdram, ctx);
        goto after_0;
    // 0x80001A58: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_0:
    // 0x80001A5C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80001A60: addiu       $a0, $a0, -0x6C70
    ctx->r4 = ADD32(ctx->r4, -0X6C70);
    // 0x80001A64: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001A68: jal         0x8007DEC0
    // 0x80001A6C: addiu       $a2, $zero, 0x47B4
    ctx->r6 = ADD32(0, 0X47B4);
    func_8007DEC0(rdram, ctx);
        goto after_1;
    // 0x80001A6C: addiu       $a2, $zero, 0x47B4
    ctx->r6 = ADD32(0, 0X47B4);
    after_1:
    // 0x80001A70: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80001A74: addiu       $a0, $a0, 0x3E8
    ctx->r4 = ADD32(ctx->r4, 0X3E8);
    // 0x80001A78: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001A7C: jal         0x8007DEC0
    // 0x80001A80: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    func_8007DEC0(rdram, ctx);
        goto after_2;
    // 0x80001A80: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    after_2:
    // 0x80001A84: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80001A88: addiu       $a0, $a0, 0x41B0
    ctx->r4 = ADD32(ctx->r4, 0X41B0);
    // 0x80001A8C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001A90: jal         0x8007DEC0
    // 0x80001A94: addiu       $a2, $zero, 0xEC4
    ctx->r6 = ADD32(0, 0XEC4);
    func_8007DEC0(rdram, ctx);
        goto after_3;
    // 0x80001A94: addiu       $a2, $zero, 0xEC4
    ctx->r6 = ADD32(0, 0XEC4);
    after_3:
    // 0x80001A98: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80001A9C: addiu       $a0, $a0, 0x4760
    ctx->r4 = ADD32(ctx->r4, 0X4760);
    // 0x80001AA0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001AA4: jal         0x8007DEC0
    // 0x80001AA8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_8007DEC0(rdram, ctx);
        goto after_4;
    // 0x80001AA8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
    // 0x80001AAC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80001AB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001AB4: jr          $ra
    // 0x80001AB8: nop

    return;
    // 0x80001AB8: nop

;}
RECOMP_FUNC void func_80001ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001ABC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80001AC0: lhu         $v0, 0x1A2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1A2);
    // 0x80001AC4: bne         $v0, $zero, L_80001B1C
    if (ctx->r2 != 0) {
        // 0x80001AC8: nop
    
            goto L_80001B1C;
    }
    // 0x80001AC8: nop

    // 0x80001ACC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80001AD0: lhu         $a0, 0x15C($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X15C);
    // 0x80001AD4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80001AD8: lhu         $v0, 0x5574($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X5574);
    // 0x80001ADC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80001AE0: lhu         $a1, 0x4E50($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X4E50);
    // 0x80001AE4: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80001AE8: lw          $v1, -0x7338($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7338);
    // 0x80001AEC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80001AF0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80001AF4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80001AF8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80001AFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80001B00: sh          $a0, 0x15C($at)
    MEM_H(0X15C, ctx->r1) = ctx->r4;
    // 0x80001B04: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80001B08: sh          $v0, 0x5574($at)
    MEM_H(0X5574, ctx->r1) = ctx->r2;
    // 0x80001B0C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001B10: sw          $v1, -0x7338($at)
    MEM_W(-0X7338, ctx->r1) = ctx->r3;
    // 0x80001B14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80001B18: sh          $a1, 0x4E50($at)
    MEM_H(0X4E50, ctx->r1) = ctx->r5;
L_80001B1C:
    // 0x80001B1C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80001B20: lhu         $v0, 0x32A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X32A0);
    // 0x80001B24: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80001B28: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001B2C: sh          $v0, 0x32A0($at)
    MEM_H(0X32A0, ctx->r1) = ctx->r2;
    // 0x80001B30: jr          $ra
    // 0x80001B34: nop

    return;
    // 0x80001B34: nop

;}
RECOMP_FUNC void func_80001B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001B38: jr          $ra
    // 0x80001B3C: nop

    return;
    // 0x80001B3C: nop

;}
RECOMP_FUNC void func_80001B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001B40: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80001B44: lw          $a0, -0x68F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X68F0);
    // 0x80001B48: lui         $v0, 0x1004
    ctx->r2 = S32(0X1004 << 16);
    // 0x80001B4C: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x80001B50: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80001B54: lw          $a2, 0x3ACC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3ACC);
    // 0x80001B58: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x80001B5C: andi        $v0, $a0, 0x100
    ctx->r2 = ctx->r4 & 0X100;
    // 0x80001B60: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001B64: sw          $a0, 0x3ACC($at)
    MEM_W(0X3ACC, ctx->r1) = ctx->r4;
    // 0x80001B68: beq         $v0, $zero, L_80001B7C
    if (ctx->r2 == 0) {
        // 0x80001B6C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80001B7C;
    }
    // 0x80001B6C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80001B70: andi        $v0, $a2, 0x100
    ctx->r2 = ctx->r6 & 0X100;
    // 0x80001B74: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80001B78: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
L_80001B7C:
    // 0x80001B7C: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    // 0x80001B80: and         $v0, $a0, $a1
    ctx->r2 = ctx->r4 & ctx->r5;
    // 0x80001B84: beq         $v0, $zero, L_80001B94
    if (ctx->r2 == 0) {
        // 0x80001B88: and         $v0, $a2, $a1
        ctx->r2 = ctx->r6 & ctx->r5;
            goto L_80001B94;
    }
    // 0x80001B88: and         $v0, $a2, $a1
    ctx->r2 = ctx->r6 & ctx->r5;
    // 0x80001B8C: beql        $v0, $zero, L_80001B94
    if (ctx->r2 == 0) {
        // 0x80001B90: or          $v1, $v1, $a1
        ctx->r3 = ctx->r3 | ctx->r5;
            goto L_80001B94;
    }
    goto skip_0;
    // 0x80001B90: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    skip_0:
L_80001B94:
    // 0x80001B94: lui         $a1, 0x1000
    ctx->r5 = S32(0X1000 << 16);
    // 0x80001B98: and         $v0, $a0, $a1
    ctx->r2 = ctx->r4 & ctx->r5;
    // 0x80001B9C: beq         $v0, $zero, L_80001BAC
    if (ctx->r2 == 0) {
        // 0x80001BA0: and         $v0, $a2, $a1
        ctx->r2 = ctx->r6 & ctx->r5;
            goto L_80001BAC;
    }
    // 0x80001BA0: and         $v0, $a2, $a1
    ctx->r2 = ctx->r6 & ctx->r5;
    // 0x80001BA4: beql        $v0, $zero, L_80001BAC
    if (ctx->r2 == 0) {
        // 0x80001BA8: or          $v1, $v1, $a1
        ctx->r3 = ctx->r3 | ctx->r5;
            goto L_80001BAC;
    }
    goto skip_1;
    // 0x80001BA8: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    skip_1:
L_80001BAC:
    // 0x80001BAC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001BB0: sw          $v1, -0x7468($at)
    MEM_W(-0X7468, ctx->r1) = ctx->r3;
    // 0x80001BB4: jr          $ra
    // 0x80001BB8: nop

    return;
    // 0x80001BB8: nop

;}
RECOMP_FUNC void func_80001BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001BBC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80001BC0: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80001BC4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80001BC8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80001BCC: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80001BD0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80001BD4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80001BD8: lh          $a0, 0x4E12($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X4E12);
    // 0x80001BDC: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80001BE0: addiu       $v1, $v1, 0x3F94
    ctx->r3 = ADD32(ctx->r3, 0X3F94);
    // 0x80001BE4: bne         $a0, $zero, L_80001CB0
    if (ctx->r4 != 0) {
        // 0x80001BE8: addu        $a1, $v0, $v1
        ctx->r5 = ADD32(ctx->r2, ctx->r3);
            goto L_80001CB0;
    }
    // 0x80001BE8: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x80001BEC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80001BF0: lh          $v0, -0x5AFC($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5AFC);
    // 0x80001BF4: bne         $v0, $zero, L_80001CBC
    if (ctx->r2 != 0) {
        // 0x80001BF8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80001CBC;
    }
    // 0x80001BF8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80001BFC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80001C00: lh          $v0, 0x4756($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4756);
    // 0x80001C04: bgtz        $v0, L_80001CBC
    if (SIGNED(ctx->r2) > 0) {
        // 0x80001C08: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80001CBC;
    }
    // 0x80001C08: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80001C0C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80001C10: beq         $v0, $zero, L_80001CBC
    if (ctx->r2 == 0) {
        // 0x80001C14: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80001CBC;
    }
    // 0x80001C14: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80001C18: lhu         $a0, 0x5A($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X5A);
    // 0x80001C1C: xori        $v1, $a0, 0x1F
    ctx->r3 = ctx->r4 ^ 0X1F;
    // 0x80001C20: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80001C24: xori        $v0, $a0, 0x37
    ctx->r2 = ctx->r4 ^ 0X37;
    // 0x80001C28: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80001C2C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80001C30: bne         $v1, $zero, L_80001CBC
    if (ctx->r3 != 0) {
        // 0x80001C34: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80001CBC;
    }
    // 0x80001C34: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80001C38: addiu       $v0, $zero, 0x26
    ctx->r2 = ADD32(0, 0X26);
    // 0x80001C3C: beq         $a0, $v0, L_80001CBC
    if (ctx->r4 == ctx->r2) {
        // 0x80001C40: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80001CBC;
    }
    // 0x80001C40: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80001C44: lhu         $v0, 0x46($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X46);
    // 0x80001C48: bne         $v0, $zero, L_80001CBC
    if (ctx->r2 != 0) {
        // 0x80001C4C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80001CBC;
    }
    // 0x80001C4C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80001C50: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80001C54: lhu         $a0, 0x90($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X90);
    // 0x80001C58: xori        $v1, $a0, 0x240
    ctx->r3 = ctx->r4 ^ 0X240;
    // 0x80001C5C: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80001C60: xori        $v0, $a0, 0x150
    ctx->r2 = ctx->r4 ^ 0X150;
    // 0x80001C64: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80001C68: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80001C6C: beq         $v1, $zero, L_80001C7C
    if (ctx->r3 == 0) {
        // 0x80001C70: addiu       $v0, $zero, 0x220
        ctx->r2 = ADD32(0, 0X220);
            goto L_80001C7C;
    }
    // 0x80001C70: addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // 0x80001C74: bne         $a0, $v0, L_80001CBC
    if (ctx->r4 != ctx->r2) {
        // 0x80001C78: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80001CBC;
    }
    // 0x80001C78: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80001C7C:
    // 0x80001C7C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80001C80: lh          $v0, -0x67C6($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X67C6);
    // 0x80001C84: bne         $v0, $zero, L_80001C94
    if (ctx->r2 != 0) {
        // 0x80001C88: addiu       $v0, $zero, 0x150
        ctx->r2 = ADD32(0, 0X150);
            goto L_80001C94;
    }
    // 0x80001C88: addiu       $v0, $zero, 0x150
    ctx->r2 = ADD32(0, 0X150);
    // 0x80001C8C: beq         $a0, $v0, L_80001CBC
    if (ctx->r4 == ctx->r2) {
        // 0x80001C90: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80001CBC;
    }
    // 0x80001C90: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80001C94:
    // 0x80001C94: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80001C98: lh          $v0, -0x5872($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5872);
    // 0x80001C9C: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80001CA0: beq         $v0, $zero, L_80001CB8
    if (ctx->r2 == 0) {
        // 0x80001CA4: addiu       $v0, $zero, 0x220
        ctx->r2 = ADD32(0, 0X220);
            goto L_80001CB8;
    }
    // 0x80001CA4: addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // 0x80001CA8: bne         $a0, $v0, L_80001CBC
    if (ctx->r4 != ctx->r2) {
        // 0x80001CAC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80001CBC;
    }
    // 0x80001CAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80001CB0:
    // 0x80001CB0: j           L_80001CBC
    // 0x80001CB4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80001CBC;
    // 0x80001CB4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80001CB8:
    // 0x80001CB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80001CBC:
    // 0x80001CBC: jr          $ra
    // 0x80001CC0: nop

    return;
    // 0x80001CC0: nop

;}
RECOMP_FUNC void func_80001CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001CC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80001CC8: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80001CCC: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x80001CD0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80001CD4: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80001CD8: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x80001CDC: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80001CE0: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80001CE4: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x80001CE8: addiu       $s6, $s6, 0x46A0
    ctx->r22 = ADD32(ctx->r22, 0X46A0);
    // 0x80001CEC: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80001CF0: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80001CF4: addiu       $s5, $s5, 0x3D8
    ctx->r21 = ADD32(ctx->r21, 0X3D8);
    // 0x80001CF8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80001CFC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80001D00: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80001D04: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80001D08: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80001D0C:
    // 0x80001D0C: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80001D10: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    // 0x80001D14: beql        $v1, $v0, L_80001D64
    if (ctx->r3 == ctx->r2) {
        // 0x80001D18: addiu       $s6, $s6, 0x2
        ctx->r22 = ADD32(ctx->r22, 0X2);
            goto L_80001D64;
    }
    goto skip_0;
    // 0x80001D18: addiu       $s6, $s6, 0x2
    ctx->r22 = ADD32(ctx->r22, 0X2);
    skip_0:
    // 0x80001D1C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80001D20: addiu       $s4, $s3, 0x1
    ctx->r20 = ADD32(ctx->r19, 0X1);
    // 0x80001D24: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x80001D28: addiu       $s2, $s2, -0x1030
    ctx->r18 = ADD32(ctx->r18, -0X1030);
L_80001D2C:
    // 0x80001D2C: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80001D30: bnel        $s0, $s4, L_80001D54
    if (ctx->r16 != ctx->r20) {
        // 0x80001D34: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80001D54;
    }
    goto skip_1;
    // 0x80001D34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80001D38: addiu       $a0, $s1, 0x1
    ctx->r4 = ADD32(ctx->r17, 0X1);
    // 0x80001D3C: jal         0x80001BBC
    // 0x80001D40: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_80001BBC(rdram, ctx);
        goto after_0;
    // 0x80001D40: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80001D44: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80001D48: beql        $v0, $fp, L_80001D50
    if (ctx->r2 == ctx->r30) {
        // 0x80001D4C: addu        $s7, $s0, $zero
        ctx->r23 = ADD32(ctx->r16, 0);
            goto L_80001D50;
    }
    goto skip_2;
    // 0x80001D4C: addu        $s7, $s0, $zero
    ctx->r23 = ADD32(ctx->r16, 0);
    skip_2:
L_80001D50:
    // 0x80001D50: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80001D54:
    // 0x80001D54: slti        $v0, $s1, 0x7
    ctx->r2 = SIGNED(ctx->r17) < 0X7 ? 1 : 0;
    // 0x80001D58: bne         $v0, $zero, L_80001D2C
    if (ctx->r2 != 0) {
        // 0x80001D5C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80001D2C;
    }
    // 0x80001D5C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80001D60: addiu       $s6, $s6, 0x2
    ctx->r22 = ADD32(ctx->r22, 0X2);
L_80001D64:
    // 0x80001D64: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80001D68: slti        $v0, $s3, 0x3
    ctx->r2 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
    // 0x80001D6C: bne         $v0, $zero, L_80001D0C
    if (ctx->r2 != 0) {
        // 0x80001D70: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_80001D0C;
    }
    // 0x80001D70: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x80001D74: andi        $v0, $s7, 0xFFFF
    ctx->r2 = ctx->r23 & 0XFFFF;
    // 0x80001D78: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80001D7C: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x80001D80: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80001D84: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80001D88: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80001D8C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80001D90: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80001D94: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80001D98: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80001D9C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80001DA0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80001DA4: jr          $ra
    // 0x80001DA8: nop

    return;
    // 0x80001DA8: nop

;}
RECOMP_FUNC void func_80001DAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001DAC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80001DB0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80001DB4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80001DB8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80001DBC: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80001DC0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80001DC4: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80001DC8: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80001DCC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80001DD0: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80001DD4: addiu       $s0, $s0, 0x31C0
    ctx->r16 = ADD32(ctx->r16, 0X31C0);
    // 0x80001DD8: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80001DDC: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80001DE0: lw          $s5, 0x0($s0)
    ctx->r21 = MEM_W(ctx->r16, 0X0);
    // 0x80001DE4: jal         0x800306EC
    // 0x80001DE8: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80001DE8: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    after_0:
    // 0x80001DEC: addiu       $v1, $zero, 0x6FFF
    ctx->r3 = ADD32(0, 0X6FFF);
    // 0x80001DF0: sh          $s1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r17;
    // 0x80001DF4: sh          $s2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r18;
    // 0x80001DF8: jal         0x80023E44
    // 0x80001DFC: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x80001DFC: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    after_1:
    // 0x80001E00: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80001E04: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80001E08: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80001E0C: sw          $s3, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r19;
    // 0x80001E10: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80001E14: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80001E18: sw          $s4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r20;
    // 0x80001E1C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80001E20: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80001E24: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
    // 0x80001E28: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80001E2C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80001E30: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x80001E34: ori         $v0, $v0, 0x40C
    ctx->r2 = ctx->r2 | 0X40C;
    // 0x80001E38: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x80001E3C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80001E40: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80001E44: lhu         $v0, 0x6C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6C);
    // 0x80001E48: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x80001E4C: sh          $v0, 0x6C($v1)
    MEM_H(0X6C, ctx->r3) = ctx->r2;
    // 0x80001E50: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80001E54: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80001E58: addiu       $v0, $zero, 0x7FE
    ctx->r2 = ADD32(0, 0X7FE);
    // 0x80001E5C: sh          $v0, 0x70($v1)
    MEM_H(0X70, ctx->r3) = ctx->r2;
    // 0x80001E60: sw          $s5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r21;
    // 0x80001E64: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80001E68: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80001E6C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80001E70: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80001E74: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80001E78: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80001E7C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80001E80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80001E84: jr          $ra
    // 0x80001E88: nop

    return;
    // 0x80001E88: nop

;}
RECOMP_FUNC void func_80001E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001E8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001E90: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80001E94: jal         0x800246DC
    // 0x80001E98: addiu       $a0, $zero, 0x7FE
    ctx->r4 = ADD32(0, 0X7FE);
    func_800246DC(rdram, ctx);
        goto after_0;
    // 0x80001E98: addiu       $a0, $zero, 0x7FE
    ctx->r4 = ADD32(0, 0X7FE);
    after_0:
    // 0x80001E9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001EA0: sw          $zero, -0x68F0($at)
    MEM_W(-0X68F0, ctx->r1) = 0;
    // 0x80001EA4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80001EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001EAC: jr          $ra
    // 0x80001EB0: nop

    return;
    // 0x80001EB0: nop

;}
RECOMP_FUNC void func_80001EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001EB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001EB8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80001EBC: jal         0x800306EC
    // 0x80001EC0: nop

    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80001EC0: nop

    after_0:
    // 0x80001EC4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80001EC8: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x80001ECC: lhu         $a0, 0x6($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X6);
    // 0x80001ED0: lui         $v1, 0x4F00
    ctx->r3 = S32(0X4F00 << 16);
    // 0x80001ED4: ori         $v1, $v1, 0x3E78
    ctx->r3 = ctx->r3 | 0X3E78;
    // 0x80001ED8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80001EDC: lui         $v1, 0xA0
    ctx->r3 = S32(0XA0 << 16);
    // 0x80001EE0: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80001EE4: lui         $v1, 0xD7
    ctx->r3 = S32(0XD7 << 16);
    // 0x80001EE8: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x80001EEC: addiu       $v1, $zero, 0x7000
    ctx->r3 = ADD32(0, 0X7000);
    // 0x80001EF0: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x80001EF4: ori         $a0, $a0, 0x20
    ctx->r4 = ctx->r4 | 0X20;
    // 0x80001EF8: jal         0x80023E44
    // 0x80001EFC: sh          $a0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r4;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x80001EFC: sh          $a0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r4;
    after_1:
    // 0x80001F00: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001F04: sw          $v0, -0x74EC($at)
    MEM_W(-0X74EC, ctx->r1) = ctx->r2;
    // 0x80001F08: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80001F0C: lw          $v1, -0x74EC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X74EC);
    // 0x80001F10: addiu       $v0, $zero, 0x550
    ctx->r2 = ADD32(0, 0X550);
    // 0x80001F14: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80001F18: addiu       $a0, $a0, 0x3220
    ctx->r4 = ADD32(ctx->r4, 0X3220);
    // 0x80001F1C: addiu       $a1, $zero, 0xB9
    ctx->r5 = ADD32(0, 0XB9);
    // 0x80001F20: addiu       $a2, $zero, 0xD6
    ctx->r6 = ADD32(0, 0XD6);
    // 0x80001F24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80001F28: sh          $v0, 0x70($v1)
    MEM_H(0X70, ctx->r3) = ctx->r2;
    // 0x80001F2C: addiu       $v0, $zero, 0x678
    ctx->r2 = ADD32(0, 0X678);
    // 0x80001F30: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80001F34: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80001F38: addiu       $v0, $v0, 0x10A0
    ctx->r2 = ADD32(ctx->r2, 0X10A0);
    // 0x80001F3C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80001F40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001F44: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80001F48: addiu       $v0, $zero, 0x550
    ctx->r2 = ADD32(0, 0X550);
    // 0x80001F4C: jal         0x800010CC
    // 0x80001F50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800010CC(rdram, ctx);
        goto after_2;
    // 0x80001F50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80001F54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80001F58: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, 0X120);
    // 0x80001F5C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80001F60: beq         $v1, $a0, L_80001F88
    if (ctx->r3 == ctx->r4) {
        // 0x80001F64: addiu       $a2, $zero, 0x550
        ctx->r6 = ADD32(0, 0X550);
            goto L_80001F88;
    }
    // 0x80001F64: addiu       $a2, $zero, 0x550
    ctx->r6 = ADD32(0, 0X550);
    // 0x80001F68: lui         $a1, 0x80
    ctx->r5 = S32(0X80 << 16);
    // 0x80001F6C: ori         $a1, $a1, 0x8080
    ctx->r5 = ctx->r5 | 0X8080;
L_80001F70:
    // 0x80001F70: lhu         $v0, 0x70($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X70);
    // 0x80001F74: beql        $v0, $a2, L_80001F7C
    if (ctx->r2 == ctx->r6) {
        // 0x80001F78: sw          $a1, 0x78($v1)
        MEM_W(0X78, ctx->r3) = ctx->r5;
            goto L_80001F7C;
    }
    goto skip_0;
    // 0x80001F78: sw          $a1, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->r5;
    skip_0:
L_80001F7C:
    // 0x80001F7C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80001F80: bne         $v1, $a0, L_80001F70
    if (ctx->r3 != ctx->r4) {
        // 0x80001F84: nop
    
            goto L_80001F70;
    }
    // 0x80001F84: nop

L_80001F88:
    // 0x80001F88: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80001F8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80001F90: jr          $ra
    // 0x80001F94: nop

    return;
    // 0x80001F94: nop

;}
RECOMP_FUNC void func_80001F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001F98: jr          $ra
    // 0x80001F9C: nop

    return;
    // 0x80001F9C: nop

;}
RECOMP_FUNC void func_80001FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001FA0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80001FA4: lw          $v0, 0x1428($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1428);
    // FALLTHROUGH into func_80001FA8 (frame processing)
    func_80001FA8(rdram, ctx);
;}
RECOMP_FUNC void func_80001FA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001FA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001FAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80001FB0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80001FB4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80001FB8: beq         $v0, $zero, L_80001FCC
    if (ctx->r2 == 0) {
        // 0x80001FBC: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80001FCC;
    }
    // 0x80001FBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80001FC0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80001FC4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001FC8: sw          $v0, 0x1428($at)
    MEM_W(0X1428, ctx->r1) = ctx->r2;
L_80001FCC:
    // 0x80001FCC: jal         0x80001CC4
    // 0x80001FD0: nop

    func_80001CC4(rdram, ctx);
        goto after_0;
    // 0x80001FD0: nop

    after_0:
    // 0x80001FD4: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80001FD8: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x80001FDC: beq         $v0, $zero, L_80002010
    if (ctx->r2 == 0) {
        // 0x80001FE0: nop
    
            goto L_80002010;
    }
    // 0x80001FE0: nop

    // 0x80001FE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80001FE8: lhu         $a0, 0x90($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X90);
    // 0x80001FEC: xori        $v1, $a0, 0x150
    ctx->r3 = ctx->r4 ^ 0X150;
    // 0x80001FF0: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80001FF4: xori        $v0, $a0, 0x240
    ctx->r2 = ctx->r4 ^ 0X240;
    // 0x80001FF8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80001FFC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80002000: bne         $v1, $zero, L_80002028
    if (ctx->r3 != 0) {
        // 0x80002004: addiu       $v0, $zero, 0x220
        ctx->r2 = ADD32(0, 0X220);
            goto L_80002028;
    }
    // 0x80002004: addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // 0x80002008: beq         $a0, $v0, L_80002028
    if (ctx->r4 == ctx->r2) {
        // 0x8000200C: nop
    
            goto L_80002028;
    }
    // 0x8000200C: nop

L_80002010:
    // 0x80002010: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80002014: addiu       $s2, $s2, 0x1A2
    ctx->r18 = ADD32(ctx->r18, 0X1A2);
    // 0x80002018: lhu         $s0, 0x0($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0X0);
    // 0x8000201C: andi        $v0, $s0, 0xF00
    ctx->r2 = ctx->r16 & 0XF00;
    // 0x80002020: beq         $v0, $zero, L_800021F8
    if (ctx->r2 == 0) {
        // 0x80002024: andi        $v1, $s0, 0x3
        ctx->r3 = ctx->r16 & 0X3;
            goto L_800021F8;
    }
    // 0x80002024: andi        $v1, $s0, 0x3
    ctx->r3 = ctx->r16 & 0X3;
L_80002028:
    // 0x80002028: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000202C: addiu       $s0, $s0, 0x1A2
    ctx->r16 = ADD32(ctx->r16, 0X1A2);
    // 0x80002030: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80002034: andi        $v0, $v0, 0xF00
    ctx->r2 = ctx->r2 & 0XF00;
    // 0x80002038: bne         $v0, $zero, L_800020DC
    if (ctx->r2 != 0) {
        // 0x8000203C: srl         $v1, $v0, 8
        ctx->r3 = S32(U32(ctx->r2) >> 8);
            goto L_800020DC;
    }
    // 0x8000203C: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x80002040: jal         0x800028FC
    // 0x80002044: nop

    func_800028FC(rdram, ctx);
        goto after_1;
    // 0x80002044: nop

    after_1:
    // 0x80002048: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8000204C: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80002050: beq         $v0, $zero, L_80002088
    if (ctx->r2 == 0) {
        // 0x80002054: nop
    
            goto L_80002088;
    }
    // 0x80002054: nop

    // 0x80002058: jal         0x800246DC
    // 0x8000205C: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    func_800246DC(rdram, ctx);
        goto after_2;
    // 0x8000205C: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_2:
    // 0x80002060: jal         0x800246DC
    // 0x80002064: addiu       $a0, $zero, 0x301
    ctx->r4 = ADD32(0, 0X301);
    func_800246DC(rdram, ctx);
        goto after_3;
    // 0x80002064: addiu       $a0, $zero, 0x301
    ctx->r4 = ADD32(0, 0X301);
    after_3:
    // 0x80002068: jal         0x800246DC
    // 0x8000206C: addiu       $a0, $zero, 0x302
    ctx->r4 = ADD32(0, 0X302);
    func_800246DC(rdram, ctx);
        goto after_4;
    // 0x8000206C: addiu       $a0, $zero, 0x302
    ctx->r4 = ADD32(0, 0X302);
    after_4:
    // 0x80002070: jal         0x800246DC
    // 0x80002074: addiu       $a0, $zero, 0x303
    ctx->r4 = ADD32(0, 0X303);
    func_800246DC(rdram, ctx);
        goto after_5;
    // 0x80002074: addiu       $a0, $zero, 0x303
    ctx->r4 = ADD32(0, 0X303);
    after_5:
    // 0x80002078: jal         0x800246DC
    // 0x8000207C: addiu       $a0, $zero, 0x304
    ctx->r4 = ADD32(0, 0X304);
    func_800246DC(rdram, ctx);
        goto after_6;
    // 0x8000207C: addiu       $a0, $zero, 0x304
    ctx->r4 = ADD32(0, 0X304);
    after_6:
    // 0x80002080: jal         0x800246DC
    // 0x80002084: addiu       $a0, $zero, 0x305
    ctx->r4 = ADD32(0, 0X305);
    func_800246DC(rdram, ctx);
        goto after_7;
    // 0x80002084: addiu       $a0, $zero, 0x305
    ctx->r4 = ADD32(0, 0X305);
    after_7:
L_80002088:
    // 0x80002088: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8000208C: addiu       $a0, $a0, 0x58BC
    ctx->r4 = ADD32(ctx->r4, 0X58BC);
    // 0x80002090: jal         0x80000760
    // 0x80002094: nop

    func_80000760(rdram, ctx);
        goto after_8;
    // 0x80002094: nop

    after_8:
    // 0x80002098: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8000209C: addiu       $a0, $a0, 0x58E0
    ctx->r4 = ADD32(ctx->r4, 0X58E0);
    // 0x800020A0: jal         0x80000760
    // 0x800020A4: nop

    func_80000760(rdram, ctx);
        goto after_9;
    // 0x800020A4: nop

    after_9:
    // 0x800020A8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800020AC: addiu       $a0, $a0, 0x5918
    ctx->r4 = ADD32(ctx->r4, 0X5918);
    // 0x800020B0: jal         0x80000760
    // 0x800020B4: nop

    func_80000760(rdram, ctx);
        goto after_10;
    // 0x800020B4: nop

    after_10:
    // 0x800020B8: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x800020BC: sll         $v1, $s1, 8
    ctx->r3 = S32(ctx->r17 << 8);
    // 0x800020C0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800020C4: jal         0x8004C78C
    // 0x800020C8: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    func_8004C78C(rdram, ctx);
        goto after_11;
    // 0x800020C8: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    after_11:
    // 0x800020CC: jal         0x8001F290
    // 0x800020D0: nop

    func_8001F290(rdram, ctx);
        goto after_12;
    // 0x800020D0: nop

    after_12:
    // 0x800020D4: j           L_800028AC
    // 0x800020D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800028AC;
    // 0x800020D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800020DC:
    // 0x800020DC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800020E0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800020E4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800020E8: lhu         $a0, 0x469E($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X469E);
    // 0x800020EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800020F0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800020F4: lhu         $v0, 0x3D6($at)
    ctx->r2 = MEM_HU(ctx->r1, 0X3D6);
    // 0x800020F8: bne         $a0, $v0, L_800028A8
    if (ctx->r4 != ctx->r2) {
        // 0x800020FC: addu        $s1, $v1, $zero
        ctx->r17 = ADD32(ctx->r3, 0);
            goto L_800028A8;
    }
    // 0x800020FC: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
    // 0x80002100: jal         0x800246DC
    // 0x80002104: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    func_800246DC(rdram, ctx);
        goto after_13;
    // 0x80002104: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_13:
    // 0x80002108: jal         0x800246DC
    // 0x8000210C: addiu       $a0, $zero, 0x550
    ctx->r4 = ADD32(0, 0X550);
    func_800246DC(rdram, ctx);
        goto after_14;
    // 0x8000210C: addiu       $a0, $zero, 0x550
    ctx->r4 = ADD32(0, 0X550);
    after_14:
    // 0x80002110: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80002114: andi        $v0, $v0, 0xF0FF
    ctx->r2 = ctx->r2 & 0XF0FF;
    // 0x80002118: jal         0x8004C794
    // 0x8000211C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    func_8004C794(rdram, ctx);
        goto after_15;
    // 0x8000211C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    after_15:
    // 0x80002120: jal         0x8001F2B4
    // 0x80002124: nop

    func_8001F2B4(rdram, ctx);
        goto after_16;
    // 0x80002124: nop

    after_16:
    // 0x80002128: jal         0x800028FC
    // 0x8000212C: nop

    func_800028FC(rdram, ctx);
        goto after_17;
    // 0x8000212C: nop

    after_17:
    // 0x80002130: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80002134: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x80002138: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000213C: beq         $v1, $v0, L_80002154
    if (ctx->r3 == ctx->r2) {
        // 0x80002140: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80002154;
    }
    // 0x80002140: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80002144: beq         $v1, $v0, L_800021BC
    if (ctx->r3 == ctx->r2) {
        // 0x80002148: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800021BC;
    }
    // 0x80002148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000214C: j           L_800022B0
    // 0x80002150: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_800022B0;
    // 0x80002150: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80002154:
    // 0x80002154: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002158: addiu       $a0, $a0, 0x57F8
    ctx->r4 = ADD32(ctx->r4, 0X57F8);
    // 0x8000215C: addiu       $v0, $zero, 0x676
    ctx->r2 = ADD32(0, 0X676);
    // 0x80002160: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002164: sh          $v0, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r2;
    // 0x80002168: jal         0x80000760
    // 0x8000216C: nop

    func_80000760(rdram, ctx);
        goto after_18;
    // 0x8000216C: nop

    after_18:
    // 0x80002170: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80002174: lhu         $v0, 0x4AAC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4AAC);
    // 0x80002178: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8000217C: addiu       $a0, $a0, 0x5840
    ctx->r4 = ADD32(ctx->r4, 0X5840);
    // 0x80002180: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002184: sh          $v0, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r2;
    // 0x80002188: jal         0x80000760
    // 0x8000218C: nop

    func_80000760(rdram, ctx);
        goto after_19;
    // 0x8000218C: nop

    after_19:
    // 0x80002190: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002194: addiu       $a0, $a0, 0x5864
    ctx->r4 = ADD32(ctx->r4, 0X5864);
    // 0x80002198: addiu       $v0, $zero, 0x679
    ctx->r2 = ADD32(0, 0X679);
    // 0x8000219C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800021A0: sh          $v0, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r2;
    // 0x800021A4: jal         0x80000760
    // 0x800021A8: nop

    func_80000760(rdram, ctx);
        goto after_20;
    // 0x800021A8: nop

    after_20:
    // 0x800021AC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800021B0: sw          $zero, 0x1424($at)
    MEM_W(0X1424, ctx->r1) = 0;
    // 0x800021B4: j           L_800028AC
    // 0x800021B8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800028AC;
    // 0x800021B8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800021BC:
    // 0x800021BC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800021C0: addiu       $a0, $a0, 0x581C
    ctx->r4 = ADD32(ctx->r4, 0X581C);
    // 0x800021C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800021C8: sw          $v0, 0x1424($at)
    MEM_W(0X1424, ctx->r1) = ctx->r2;
    // 0x800021CC: addiu       $v0, $zero, 0x676
    ctx->r2 = ADD32(0, 0X676);
    // 0x800021D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800021D4: sh          $v0, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r2;
    // 0x800021D8: jal         0x80000760
    // 0x800021DC: nop

    func_80000760(rdram, ctx);
        goto after_21;
    // 0x800021DC: nop

    after_21:
    // 0x800021E0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800021E4: lhu         $v0, 0x4AAC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4AAC);
    // 0x800021E8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800021EC: addiu       $a0, $a0, 0x58A0
    ctx->r4 = ADD32(ctx->r4, 0X58A0);
    // 0x800021F0: j           L_8000287C
    // 0x800021F4: nop

        goto L_8000287C;
    // 0x800021F4: nop

L_800021F8:
    // 0x800021F8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800021FC: beq         $v1, $s1, L_80002384
    if (ctx->r3 == ctx->r17) {
        // 0x80002200: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80002384;
    }
    // 0x80002200: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80002204: beql        $v0, $zero, L_8000221C
    if (ctx->r2 == 0) {
        // 0x80002208: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8000221C;
    }
    goto skip_0;
    // 0x80002208: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8000220C: beq         $v1, $zero, L_80002234
    if (ctx->r3 == 0) {
        // 0x80002210: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80002234;
    }
    // 0x80002210: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80002214: j           L_800028AC
    // 0x80002218: nop

        goto L_800028AC;
    // 0x80002218: nop

L_8000221C:
    // 0x8000221C: beq         $v1, $v0, L_800023C4
    if (ctx->r3 == ctx->r2) {
        // 0x80002220: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800023C4;
    }
    // 0x80002220: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80002224: beq         $v1, $v0, L_80002594
    if (ctx->r3 == ctx->r2) {
        // 0x80002228: andi        $s0, $s0, 0x3000
        ctx->r16 = ctx->r16 & 0X3000;
            goto L_80002594;
    }
    // 0x80002228: andi        $s0, $s0, 0x3000
    ctx->r16 = ctx->r16 & 0X3000;
    // 0x8000222C: j           L_800028AC
    // 0x80002230: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800028AC;
    // 0x80002230: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80002234:
    // 0x80002234: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80002238: lw          $v0, -0x7468($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7468);
    // 0x8000223C: beq         $v0, $zero, L_800028A8
    if (ctx->r2 == 0) {
        // 0x80002240: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800028A8;
    }
    // 0x80002240: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80002244: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
L_80002248:
    // 0x80002248: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x8000224C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80002250: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80002254: lh          $v1, -0x102E($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X102E);
    // 0x80002258: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8000225C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80002260: lw          $a0, -0x1030($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1030);
    // 0x80002264: beq         $v1, $zero, L_80002360
    if (ctx->r3 == 0) {
        // 0x80002268: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_80002360;
    }
    // 0x80002268: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8000226C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80002270: sra         $v0, $v0, 12
    ctx->r2 = S32(SIGNED(ctx->r2) >> 12);
    // 0x80002274: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80002278: lw          $v1, -0x7468($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7468);
    // 0x8000227C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002280: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80002284: lw          $v0, 0x13F4($at)
    ctx->r2 = MEM_W(ctx->r1, 0X13F4);
    // 0x80002288: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8000228C: beq         $v1, $zero, L_80002360
    if (ctx->r3 == 0) {
        // 0x80002290: addu        $s1, $a0, $zero
        ctx->r17 = ADD32(ctx->r4, 0);
            goto L_80002360;
    }
    // 0x80002290: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80002294: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x80002298: jal         0x80001BBC
    // 0x8000229C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_80001BBC(rdram, ctx);
        goto after_22;
    // 0x8000229C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_22:
    // 0x800022A0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800022A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800022A8: bne         $v0, $v1, L_80002364
    if (ctx->r2 != ctx->r3) {
        // 0x800022AC: addiu       $v0, $s0, 0x1
        ctx->r2 = ADD32(ctx->r16, 0X1);
            goto L_80002364;
    }
    // 0x800022AC: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_800022B0:
    // 0x800022B0: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x800022B4: sra         $v0, $v0, 12
    ctx->r2 = S32(SIGNED(ctx->r2) >> 12);
    // 0x800022B8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800022BC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800022C0: lhu         $v1, 0x1400($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X1400);
    // 0x800022C4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800022C8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800022CC: sw          $zero, 0x1424($at)
    MEM_W(0X1424, ctx->r1) = 0;
    // 0x800022D0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800022D4: sw          $v0, 0x1428($at)
    MEM_W(0X1428, ctx->r1) = ctx->r2;
    // 0x800022D8: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x800022DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800022E0: sh          $v1, 0x1A2($at)
    MEM_H(0X1A2, ctx->r1) = ctx->r3;
    // 0x800022E4: jal         0x80061274
    // 0x800022E8: nop

    func_80061274(rdram, ctx);
        goto after_23;
    // 0x800022E8: nop

    after_23:
    // 0x800022EC: jal         0x8001F290
    // 0x800022F0: nop

    func_8001F290(rdram, ctx);
        goto after_24;
    // 0x800022F0: nop

    after_24:
    // 0x800022F4: jal         0x8004C78C
    // 0x800022F8: nop

    func_8004C78C(rdram, ctx);
        goto after_25;
    // 0x800022F8: nop

    after_25:
    // 0x800022FC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002300: addiu       $a0, $a0, 0x57F8
    ctx->r4 = ADD32(ctx->r4, 0X57F8);
    // 0x80002304: addiu       $v0, $zero, 0x676
    ctx->r2 = ADD32(0, 0X676);
    // 0x80002308: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000230C: sh          $v0, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r2;
    // 0x80002310: jal         0x80000760
    // 0x80002314: nop

    func_80000760(rdram, ctx);
        goto after_26;
    // 0x80002314: nop

    after_26:
    // 0x80002318: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    // 0x8000231C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80002320: addiu       $a2, $zero, 0xDC
    ctx->r6 = ADD32(0, 0XDC);
    // 0x80002324: jal         0x80001DAC
    // 0x80002328: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    func_80001DAC(rdram, ctx);
        goto after_27;
    // 0x80002328: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    after_27:
    // 0x8000232C: jal         0x80001EB4
    // 0x80002330: nop

    func_80001EB4(rdram, ctx);
        goto after_28;
    // 0x80002330: nop

    after_28:
    // 0x80002334: addiu       $a0, $zero, 0x411
    ctx->r4 = ADD32(0, 0X411);
    // 0x80002338: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000233C: jal         0x80028B7C
    // 0x80002340: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80028B7C(rdram, ctx);
        goto after_29;
    // 0x80002340: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_29:
    // 0x80002344: addiu       $a0, $zero, 0x412
    ctx->r4 = ADD32(0, 0X412);
    // 0x80002348: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000234C: jal         0x80028B7C
    // 0x80002350: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80028B7C(rdram, ctx);
        goto after_30;
    // 0x80002350: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_30:
    // 0x80002354: addiu       $a0, $zero, 0x7B4
    ctx->r4 = ADD32(0, 0X7B4);
    // 0x80002358: j           L_80002664
    // 0x8000235C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
        goto L_80002664;
    // 0x8000235C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80002360:
    // 0x80002360: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_80002364:
    // 0x80002364: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80002368: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000236C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80002370: slti        $v0, $v0, 0x7
    ctx->r2 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80002374: bne         $v0, $zero, L_80002248
    if (ctx->r2 != 0) {
        // 0x80002378: sll         $v0, $s0, 16
        ctx->r2 = S32(ctx->r16 << 16);
            goto L_80002248;
    }
    // 0x80002378: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x8000237C: j           L_800028AC
    // 0x80002380: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800028AC;
    // 0x80002380: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80002384:
    // 0x80002384: andi        $v0, $s0, 0xFFFC
    ctx->r2 = ctx->r16 & 0XFFFC;
    // 0x80002388: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x8000238C: jal         0x800028FC
    // 0x80002390: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    func_800028FC(rdram, ctx);
        goto after_31;
    // 0x80002390: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    after_31:
    // 0x80002394: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80002398: lhu         $v0, 0x4AAC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4AAC);
    // 0x8000239C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800023A0: addiu       $a0, $a0, 0x5840
    ctx->r4 = ADD32(ctx->r4, 0X5840);
    // 0x800023A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800023A8: sh          $v0, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r2;
    // 0x800023AC: jal         0x80000760
    // 0x800023B0: nop

    func_80000760(rdram, ctx);
        goto after_32;
    // 0x800023B0: nop

    after_32:
    // 0x800023B4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800023B8: addiu       $a0, $a0, 0x5864
    ctx->r4 = ADD32(ctx->r4, 0X5864);
    // 0x800023BC: j           L_80002898
    // 0x800023C0: addiu       $v0, $zero, 0x679
    ctx->r2 = ADD32(0, 0X679);
        goto L_80002898;
    // 0x800023C0: addiu       $v0, $zero, 0x679
    ctx->r2 = ADD32(0, 0X679);
L_800023C4:
    // 0x800023C4: andi        $s0, $s0, 0x3000
    ctx->r16 = ctx->r16 & 0X3000;
    // 0x800023C8: jal         0x800028FC
    // 0x800023CC: srl         $s0, $s0, 12
    ctx->r16 = S32(U32(ctx->r16) >> 12);
    func_800028FC(rdram, ctx);
        goto after_33;
    // 0x800023CC: srl         $s0, $s0, 12
    ctx->r16 = S32(U32(ctx->r16) >> 12);
    after_33:
    // 0x800023D0: sll         $v1, $s0, 4
    ctx->r3 = S32(ctx->r16 << 4);
    // 0x800023D4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800023D8: lw          $v0, -0x68F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68F0);
    // 0x800023DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800023E0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800023E4: lw          $v1, 0x13F8($at)
    ctx->r3 = MEM_W(ctx->r1, 0X13F8);
    // 0x800023E8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800023EC: beq         $v0, $zero, L_800024B8
    if (ctx->r2 == 0) {
        // 0x800023F0: sll         $v0, $s0, 16
        ctx->r2 = S32(ctx->r16 << 16);
            goto L_800024B8;
    }
    // 0x800023F0: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x800023F4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800023F8: lw          $v0, 0x1428($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1428);
    // 0x800023FC: bne         $v0, $zero, L_800024B8
    if (ctx->r2 != 0) {
        // 0x80002400: sll         $v0, $s0, 16
        ctx->r2 = S32(ctx->r16 << 16);
            goto L_800024B8;
    }
    // 0x80002400: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x80002404: jal         0x800246DC
    // 0x80002408: addiu       $a0, $zero, 0x302
    ctx->r4 = ADD32(0, 0X302);
    func_800246DC(rdram, ctx);
        goto after_34;
    // 0x80002408: addiu       $a0, $zero, 0x302
    ctx->r4 = ADD32(0, 0X302);
    after_34:
    // 0x8000240C: jal         0x800246DC
    // 0x80002410: addiu       $a0, $zero, 0x303
    ctx->r4 = ADD32(0, 0X303);
    func_800246DC(rdram, ctx);
        goto after_35;
    // 0x80002410: addiu       $a0, $zero, 0x303
    ctx->r4 = ADD32(0, 0X303);
    after_35:
    // 0x80002414: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80002418: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000241C: sw          $v0, 0x1428($at)
    MEM_W(0X1428, ctx->r1) = ctx->r2;
    // 0x80002420: jal         0x8004C79C
    // 0x80002424: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_8004C79C(rdram, ctx);
        goto after_36;
    // 0x80002424: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_36:
    // 0x80002428: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000242C: lw          $v0, 0x1424($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1424);
    // 0x80002430: bne         $v0, $zero, L_8000246C
    if (ctx->r2 != 0) {
        // 0x80002434: addiu       $a0, $zero, 0x301
        ctx->r4 = ADD32(0, 0X301);
            goto L_8000246C;
    }
    // 0x80002434: addiu       $a0, $zero, 0x301
    ctx->r4 = ADD32(0, 0X301);
    // 0x80002438: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // 0x8000243C: jal         0x800246DC
    // 0x80002440: addiu       $a0, $zero, 0x301
    ctx->r4 = ADD32(0, 0X301);
    func_800246DC(rdram, ctx);
        goto after_37;
    // 0x80002440: addiu       $a0, $zero, 0x301
    ctx->r4 = ADD32(0, 0X301);
    after_37:
    // 0x80002444: jal         0x800246DC
    // 0x80002448: addiu       $a0, $zero, 0x550
    ctx->r4 = ADD32(0, 0X550);
    func_800246DC(rdram, ctx);
        goto after_38;
    // 0x80002448: addiu       $a0, $zero, 0x550
    ctx->r4 = ADD32(0, 0X550);
    after_38:
    // 0x8000244C: jal         0x8004C794
    // 0x80002450: nop

    func_8004C794(rdram, ctx);
        goto after_39;
    // 0x80002450: nop

    after_39:
    // 0x80002454: jal         0x8001F2B4
    // 0x80002458: nop

    func_8001F2B4(rdram, ctx);
        goto after_40;
    // 0x80002458: nop

    after_40:
    // 0x8000245C: jal         0x80001F98
    // 0x80002460: nop

    func_80001F98(rdram, ctx);
        goto after_41;
    // 0x80002460: nop

    after_41:
    // 0x80002464: j           L_80002628
    // 0x80002468: nop

        goto L_80002628;
    // 0x80002468: nop

L_8000246C:
    // 0x8000246C: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x80002470: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002474: sw          $s1, 0x1424($at)
    MEM_W(0X1424, ctx->r1) = ctx->r17;
    // 0x80002478: ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    // 0x8000247C: jal         0x800246DC
    // 0x80002480: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    func_800246DC(rdram, ctx);
        goto after_42;
    // 0x80002480: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    after_42:
    // 0x80002484: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002488: addiu       $a0, $a0, 0x581C
    ctx->r4 = ADD32(ctx->r4, 0X581C);
    // 0x8000248C: addiu       $v0, $zero, 0x676
    ctx->r2 = ADD32(0, 0X676);
    // 0x80002490: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002494: sh          $v0, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r2;
    // 0x80002498: jal         0x80000760
    // 0x8000249C: nop

    func_80000760(rdram, ctx);
        goto after_43;
    // 0x8000249C: nop

    after_43:
    // 0x800024A0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800024A4: lhu         $v0, 0x4AAC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4AAC);
    // 0x800024A8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800024AC: addiu       $a0, $a0, 0x58A0
    ctx->r4 = ADD32(ctx->r4, 0X58A0);
    // 0x800024B0: j           L_8000287C
    // 0x800024B4: nop

        goto L_8000287C;
    // 0x800024B4: nop

L_800024B8:
    // 0x800024B8: sra         $v0, $v0, 12
    ctx->r2 = S32(SIGNED(ctx->r2) >> 12);
    // 0x800024BC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800024C0: lw          $v1, -0x68F0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X68F0);
    // 0x800024C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800024C8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800024CC: lw          $v0, 0x13FC($at)
    ctx->r2 = MEM_W(ctx->r1, 0X13FC);
    // 0x800024D0: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800024D4: beq         $v1, $zero, L_800028AC
    if (ctx->r3 == 0) {
        // 0x800024D8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800028AC;
    }
    // 0x800024D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800024DC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800024E0: lw          $v0, 0x1428($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1428);
    // 0x800024E4: bne         $v0, $zero, L_800028AC
    if (ctx->r2 != 0) {
        // 0x800024E8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800028AC;
    }
    // 0x800024E8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800024EC: jal         0x800246DC
    // 0x800024F0: addiu       $a0, $zero, 0x302
    ctx->r4 = ADD32(0, 0X302);
    func_800246DC(rdram, ctx);
        goto after_44;
    // 0x800024F0: addiu       $a0, $zero, 0x302
    ctx->r4 = ADD32(0, 0X302);
    after_44:
    // 0x800024F4: jal         0x800246DC
    // 0x800024F8: addiu       $a0, $zero, 0x303
    ctx->r4 = ADD32(0, 0X303);
    func_800246DC(rdram, ctx);
        goto after_45;
    // 0x800024F8: addiu       $a0, $zero, 0x303
    ctx->r4 = ADD32(0, 0X303);
    after_45:
    // 0x800024FC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80002500: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002504: sw          $v0, 0x1428($at)
    MEM_W(0X1428, ctx->r1) = ctx->r2;
    // 0x80002508: jal         0x8004C79C
    // 0x8000250C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_8004C79C(rdram, ctx);
        goto after_46;
    // 0x8000250C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_46:
    // 0x80002510: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80002514: lw          $v0, 0x1424($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1424);
    // 0x80002518: bne         $v0, $zero, L_8000255C
    if (ctx->r2 != 0) {
        // 0x8000251C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000255C;
    }
    // 0x8000251C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002520: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002524: addiu       $a0, $a0, 0x5840
    ctx->r4 = ADD32(ctx->r4, 0X5840);
    // 0x80002528: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000252C: sw          $v0, 0x1424($at)
    MEM_W(0X1424, ctx->r1) = ctx->r2;
    // 0x80002530: addiu       $v0, $zero, 0x679
    ctx->r2 = ADD32(0, 0X679);
    // 0x80002534: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002538: sh          $v0, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r2;
    // 0x8000253C: jal         0x80000760
    // 0x80002540: nop

    func_80000760(rdram, ctx);
        goto after_47;
    // 0x80002540: nop

    after_47:
    // 0x80002544: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80002548: lhu         $v0, 0x4AAC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4AAC);
    // 0x8000254C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002550: addiu       $a0, $a0, 0x5864
    ctx->r4 = ADD32(ctx->r4, 0X5864);
    // 0x80002554: j           L_80002898
    // 0x80002558: nop

        goto L_80002898;
    // 0x80002558: nop

L_8000255C:
    // 0x8000255C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80002560: lhu         $v0, 0x4AAC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4AAC);
    // 0x80002564: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002568: addiu       $a0, $a0, 0x5840
    ctx->r4 = ADD32(ctx->r4, 0X5840);
    // 0x8000256C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002570: sw          $zero, 0x1424($at)
    MEM_W(0X1424, ctx->r1) = 0;
    // 0x80002574: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002578: sh          $v0, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r2;
    // 0x8000257C: jal         0x80000760
    // 0x80002580: nop

    func_80000760(rdram, ctx);
        goto after_48;
    // 0x80002580: nop

    after_48:
    // 0x80002584: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002588: addiu       $a0, $a0, 0x5864
    ctx->r4 = ADD32(ctx->r4, 0X5864);
    // 0x8000258C: j           L_80002898
    // 0x80002590: addiu       $v0, $zero, 0x679
    ctx->r2 = ADD32(0, 0X679);
        goto L_80002898;
    // 0x80002590: addiu       $v0, $zero, 0x679
    ctx->r2 = ADD32(0, 0X679);
L_80002594:
    // 0x80002594: jal         0x800028FC
    // 0x80002598: srl         $s0, $s0, 12
    ctx->r16 = S32(U32(ctx->r16) >> 12);
    func_800028FC(rdram, ctx);
        goto after_49;
    // 0x80002598: srl         $s0, $s0, 12
    ctx->r16 = S32(U32(ctx->r16) >> 12);
    after_49:
    // 0x8000259C: sll         $v1, $s0, 4
    ctx->r3 = S32(ctx->r16 << 4);
    // 0x800025A0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800025A4: lw          $v0, -0x68F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68F0);
    // 0x800025A8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800025AC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800025B0: lw          $v1, 0x13F8($at)
    ctx->r3 = MEM_W(ctx->r1, 0X13F8);
    // 0x800025B4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800025B8: beq         $v0, $zero, L_800027C0
    if (ctx->r2 == 0) {
        // 0x800025BC: sll         $v0, $s0, 16
        ctx->r2 = S32(ctx->r16 << 16);
            goto L_800027C0;
    }
    // 0x800025BC: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x800025C0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800025C4: lw          $v0, 0x1428($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1428);
    // 0x800025C8: bne         $v0, $zero, L_800027C0
    if (ctx->r2 != 0) {
        // 0x800025CC: sll         $v0, $s0, 16
        ctx->r2 = S32(ctx->r16 << 16);
            goto L_800027C0;
    }
    // 0x800025CC: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x800025D0: jal         0x800246DC
    // 0x800025D4: addiu       $a0, $zero, 0x304
    ctx->r4 = ADD32(0, 0X304);
    func_800246DC(rdram, ctx);
        goto after_50;
    // 0x800025D4: addiu       $a0, $zero, 0x304
    ctx->r4 = ADD32(0, 0X304);
    after_50:
    // 0x800025D8: jal         0x800246DC
    // 0x800025DC: addiu       $a0, $zero, 0x305
    ctx->r4 = ADD32(0, 0X305);
    func_800246DC(rdram, ctx);
        goto after_51;
    // 0x800025DC: addiu       $a0, $zero, 0x305
    ctx->r4 = ADD32(0, 0X305);
    after_51:
    // 0x800025E0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800025E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800025E8: sw          $v0, 0x1428($at)
    MEM_W(0X1428, ctx->r1) = ctx->r2;
    // 0x800025EC: jal         0x8004C79C
    // 0x800025F0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_8004C79C(rdram, ctx);
        goto after_52;
    // 0x800025F0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_52:
    // 0x800025F4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800025F8: lw          $v0, 0x1424($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1424);
    // 0x800025FC: bne         $v0, $s1, L_80002674
    if (ctx->r2 != ctx->r17) {
        // 0x80002600: nop
    
            goto L_80002674;
    }
    // 0x80002600: nop

    // 0x80002604: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // 0x80002608: jal         0x800246DC
    // 0x8000260C: addiu       $a0, $zero, 0x301
    ctx->r4 = ADD32(0, 0X301);
    func_800246DC(rdram, ctx);
        goto after_53;
    // 0x8000260C: addiu       $a0, $zero, 0x301
    ctx->r4 = ADD32(0, 0X301);
    after_53:
    // 0x80002610: jal         0x800246DC
    // 0x80002614: addiu       $a0, $zero, 0x550
    ctx->r4 = ADD32(0, 0X550);
    func_800246DC(rdram, ctx);
        goto after_54;
    // 0x80002614: addiu       $a0, $zero, 0x550
    ctx->r4 = ADD32(0, 0X550);
    after_54:
    // 0x80002618: jal         0x8004C794
    // 0x8000261C: nop

    func_8004C794(rdram, ctx);
        goto after_55;
    // 0x8000261C: nop

    after_55:
    // 0x80002620: jal         0x8001F2B4
    // 0x80002624: nop

    func_8001F2B4(rdram, ctx);
        goto after_56;
    // 0x80002624: nop

    after_56:
L_80002628:
    // 0x80002628: jal         0x80001E8C
    // 0x8000262C: nop

    func_80001E8C(rdram, ctx);
        goto after_57;
    // 0x8000262C: nop

    after_57:
    // 0x80002630: addiu       $a0, $zero, 0x411
    ctx->r4 = ADD32(0, 0X411);
    // 0x80002634: lui         $a1, 0x80
    ctx->r5 = S32(0X80 << 16);
    // 0x80002638: ori         $a1, $a1, 0x8080
    ctx->r5 = ctx->r5 | 0X8080;
    // 0x8000263C: jal         0x80028B7C
    // 0x80002640: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80028B7C(rdram, ctx);
        goto after_58;
    // 0x80002640: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_58:
    // 0x80002644: addiu       $a0, $zero, 0x412
    ctx->r4 = ADD32(0, 0X412);
    // 0x80002648: lui         $a1, 0x80
    ctx->r5 = S32(0X80 << 16);
    // 0x8000264C: ori         $a1, $a1, 0x8080
    ctx->r5 = ctx->r5 | 0X8080;
    // 0x80002650: jal         0x80028B7C
    // 0x80002654: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80028B7C(rdram, ctx);
        goto after_59;
    // 0x80002654: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_59:
    // 0x80002658: addiu       $a0, $zero, 0x7B4
    ctx->r4 = ADD32(0, 0X7B4);
    // 0x8000265C: lui         $a1, 0x80
    ctx->r5 = S32(0X80 << 16);
    // 0x80002660: ori         $a1, $a1, 0x8080
    ctx->r5 = ctx->r5 | 0X8080;
L_80002664:
    // 0x80002664: jal         0x80028B7C
    // 0x80002668: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80028B7C(rdram, ctx);
        goto after_60;
    // 0x80002668: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_60:
    // 0x8000266C: j           L_800028AC
    // 0x80002670: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800028AC;
    // 0x80002670: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80002674:
    // 0x80002674: jal         0x8004C760
    // 0x80002678: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    func_8004C760(rdram, ctx);
        goto after_61;
    // 0x80002678: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    after_61:
    // 0x8000267C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80002680: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80002684: addiu       $v1, $v1, -0x1030
    ctx->r3 = ADD32(ctx->r3, -0X1030);
    // 0x80002688: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000268C: sh          $zero, 0x4716($at)
    MEM_H(0X4716, ctx->r1) = 0;
    // 0x80002690: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80002694: sh          $zero, 0x4718($at)
    MEM_H(0X4718, ctx->r1) = 0;
    // 0x80002698: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000269C: sh          $zero, 0x471A($at)
    MEM_H(0X471A, ctx->r1) = 0;
    // 0x800026A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800026A4: sh          $zero, 0x471C($at)
    MEM_H(0X471C, ctx->r1) = 0;
    // 0x800026A8: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
L_800026AC:
    // 0x800026AC: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x800026B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800026B4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800026B8: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x800026BC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800026C0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800026C4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800026C8: slti        $v0, $v0, 0x7
    ctx->r2 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x800026CC: bne         $v0, $zero, L_800026AC
    if (ctx->r2 != 0) {
        // 0x800026D0: sll         $v0, $s0, 16
        ctx->r2 = S32(ctx->r16 << 16);
            goto L_800026AC;
    }
    // 0x800026D0: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x800026D4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800026D8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x800026DC: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
L_800026E0:
    // 0x800026E0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800026E4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800026E8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800026EC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800026F0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x800026F4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800026F8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800026FC: sh          $s0, -0xA24($at)
    MEM_H(-0XA24, ctx->r1) = ctx->r16;
    // 0x80002700: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80002704: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80002708: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000270C: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80002710: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80002714: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80002718: sh          $zero, -0xA22($at)
    MEM_H(-0XA22, ctx->r1) = 0;
    // 0x8000271C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80002720: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80002724: sh          $a0, -0xA20($at)
    MEM_H(-0XA20, ctx->r1) = ctx->r4;
    // 0x80002728: bnel        $v0, $zero, L_800026E0
    if (ctx->r2 != 0) {
        // 0x8000272C: sll         $v0, $s0, 16
        ctx->r2 = S32(ctx->r16 << 16);
            goto L_800026E0;
    }
    goto skip_1;
    // 0x8000272C: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    skip_1:
    // 0x80002730: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80002734: addiu       $a0, $a0, 0x57E0
    ctx->r4 = ADD32(ctx->r4, 0X57E0);
    // 0x80002738: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000273C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80002740: sh          $zero, -0x67C8($at)
    MEM_H(-0X67C8, ctx->r1) = 0;
    // 0x80002744: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002748: sh          $zero, -0x1D66($at)
    MEM_H(-0X1D66, ctx->r1) = 0;
    // 0x8000274C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80002750: sh          $zero, 0x538($at)
    MEM_H(0X538, ctx->r1) = 0;
    // 0x80002754: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80002758: sw          $zero, -0x307C($at)
    MEM_W(-0X307C, ctx->r1) = 0;
    // 0x8000275C: jal         0x8007DEC0
    // 0x80002760: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    func_8007DEC0(rdram, ctx);
        goto after_62;
    // 0x80002760: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_62:
    // 0x80002764: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80002768: sw          $zero, 0x46B0($at)
    MEM_W(0X46B0, ctx->r1) = 0;
    // 0x8000276C: jal         0x8003075C
    // 0x80002770: nop

    func_8003075C(rdram, ctx);
        goto after_63;
    // 0x80002770: nop

    after_63:
    // 0x80002774: jal         0x80024AB0
    // 0x80002778: nop

    func_80024AB0(rdram, ctx);
        goto after_64;
    // 0x80002778: nop

    after_64:
    // 0x8000277C: jal         0x80030764
    // 0x80002780: nop

    func_80030764(rdram, ctx);
        goto after_65;
    // 0x80002780: nop

    after_65:
    // 0x80002784: jal         0x8003C8C0
    // 0x80002788: nop

    func_8003C8C0(rdram, ctx);
        goto after_66;
    // 0x80002788: nop

    after_66:
    // 0x8000278C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80002790: lhu         $v0, 0x6AF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6AF0);
    // 0x80002794: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80002798: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000279C: sh          $v0, 0x6AF0($at)
    MEM_H(0X6AF0, ctx->r1) = ctx->r2;
    // 0x800027A0: jal         0x8003055C
    // 0x800027A4: nop

    func_8003055C(rdram, ctx);
        goto after_67;
    // 0x800027A4: nop

    after_67:
    // 0x800027A8: jal         0x800014FC
    // 0x800027AC: nop

    func_800014FC(rdram, ctx);
        goto after_68;
    // 0x800027AC: nop

    after_68:
    // 0x800027B0: jal         0x80002A10
    // 0x800027B4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80002A10(rdram, ctx);
        goto after_69;
    // 0x800027B4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_69:
    // 0x800027B8: j           L_800028AC
    // 0x800027BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800028AC;
    // 0x800027BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800027C0:
    // 0x800027C0: sra         $v0, $v0, 12
    ctx->r2 = S32(SIGNED(ctx->r2) >> 12);
    // 0x800027C4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800027C8: lw          $v1, -0x68F0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X68F0);
    // 0x800027CC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800027D0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800027D4: lw          $v0, 0x13FC($at)
    ctx->r2 = MEM_W(ctx->r1, 0X13FC);
    // 0x800027D8: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800027DC: beq         $v1, $zero, L_800028AC
    if (ctx->r3 == 0) {
        // 0x800027E0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800028AC;
    }
    // 0x800027E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800027E4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800027E8: lw          $v0, 0x1428($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1428);
    // 0x800027EC: bne         $v0, $zero, L_800028AC
    if (ctx->r2 != 0) {
        // 0x800027F0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800028AC;
    }
    // 0x800027F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800027F4: jal         0x800246DC
    // 0x800027F8: addiu       $a0, $zero, 0x304
    ctx->r4 = ADD32(0, 0X304);
    func_800246DC(rdram, ctx);
        goto after_70;
    // 0x800027F8: addiu       $a0, $zero, 0x304
    ctx->r4 = ADD32(0, 0X304);
    after_70:
    // 0x800027FC: jal         0x800246DC
    // 0x80002800: addiu       $a0, $zero, 0x305
    ctx->r4 = ADD32(0, 0X305);
    func_800246DC(rdram, ctx);
        goto after_71;
    // 0x80002800: addiu       $a0, $zero, 0x305
    ctx->r4 = ADD32(0, 0X305);
    after_71:
    // 0x80002804: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80002808: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000280C: sw          $v0, 0x1428($at)
    MEM_W(0X1428, ctx->r1) = ctx->r2;
    // 0x80002810: jal         0x8004C79C
    // 0x80002814: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_8004C79C(rdram, ctx);
        goto after_72;
    // 0x80002814: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_72:
    // 0x80002818: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000281C: lw          $v0, 0x1424($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1424);
    // 0x80002820: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80002824: bne         $v0, $v1, L_80002864
    if (ctx->r2 != ctx->r3) {
        // 0x80002828: addiu       $v0, $zero, 0x679
        ctx->r2 = ADD32(0, 0X679);
            goto L_80002864;
    }
    // 0x80002828: addiu       $v0, $zero, 0x679
    ctx->r2 = ADD32(0, 0X679);
    // 0x8000282C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002830: addiu       $a0, $a0, 0x58A0
    ctx->r4 = ADD32(ctx->r4, 0X58A0);
    // 0x80002834: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002838: sw          $zero, 0x1424($at)
    MEM_W(0X1424, ctx->r1) = 0;
    // 0x8000283C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002840: sh          $v0, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r2;
    // 0x80002844: jal         0x80000760
    // 0x80002848: nop

    func_80000760(rdram, ctx);
        goto after_73;
    // 0x80002848: nop

    after_73:
    // 0x8000284C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80002850: lhu         $v0, 0x4AAC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4AAC);
    // 0x80002854: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002858: addiu       $a0, $a0, 0x5884
    ctx->r4 = ADD32(ctx->r4, 0X5884);
    // 0x8000285C: j           L_80002898
    // 0x80002860: nop

        goto L_80002898;
    // 0x80002860: nop

L_80002864:
    // 0x80002864: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80002868: lhu         $v0, 0x4AAC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4AAC);
    // 0x8000286C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002870: addiu       $a0, $a0, 0x58A0
    ctx->r4 = ADD32(ctx->r4, 0X58A0);
    // 0x80002874: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002878: sw          $v1, 0x1424($at)
    MEM_W(0X1424, ctx->r1) = ctx->r3;
L_8000287C:
    // 0x8000287C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002880: sh          $v0, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r2;
    // 0x80002884: jal         0x80000760
    // 0x80002888: nop

    func_80000760(rdram, ctx);
        goto after_74;
    // 0x80002888: nop

    after_74:
    // 0x8000288C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002890: addiu       $a0, $a0, 0x5884
    ctx->r4 = ADD32(ctx->r4, 0X5884);
    // 0x80002894: addiu       $v0, $zero, 0x679
    ctx->r2 = ADD32(0, 0X679);
L_80002898:
    // 0x80002898: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000289C: sh          $v0, -0x1D0A($at)
    MEM_H(-0X1D0A, ctx->r1) = ctx->r2;
    // 0x800028A0: jal         0x80000760
    // 0x800028A4: nop

    func_80000760(rdram, ctx);
        goto after_75;
    // 0x800028A4: nop

    after_75:
L_800028A8:
    // 0x800028A8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800028AC:
    // 0x800028AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800028B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800028B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800028B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800028BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800028C0: jr          $ra
    // 0x800028C4: nop

    return;
    // 0x800028C4: nop

;}
RECOMP_FUNC void func_800028C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800028C8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800028CC: addiu       $a2, $a2, 0x120
    ctx->r6 = ADD32(ctx->r6, 0X120);
    // 0x800028D0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800028D4: beq         $v1, $a2, L_800028F4
    if (ctx->r3 == ctx->r6) {
        // 0x800028D8: nop
    
            goto L_800028F4;
    }
    // 0x800028D8: nop

L_800028DC:
    // 0x800028DC: lhu         $v0, 0x74($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X74);
    // 0x800028E0: beql        $v0, $a0, L_800028E8
    if (ctx->r2 == ctx->r4) {
        // 0x800028E4: sh          $a1, 0x74($v1)
        MEM_H(0X74, ctx->r3) = ctx->r5;
            goto L_800028E8;
    }
    goto skip_0;
    // 0x800028E4: sh          $a1, 0x74($v1)
    MEM_H(0X74, ctx->r3) = ctx->r5;
    skip_0:
L_800028E8:
    // 0x800028E8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800028EC: bne         $v1, $a2, L_800028DC
    if (ctx->r3 != ctx->r6) {
        // 0x800028F0: nop
    
            goto L_800028DC;
    }
    // 0x800028F0: nop

L_800028F4:
    // 0x800028F4: jr          $ra
    // 0x800028F8: nop

    return;
    // 0x800028F8: nop

;}
RECOMP_FUNC void func_800028FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800028FC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80002900: lhu         $v0, -0x733C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X733C);
;}
RECOMP_FUNC void func_80002904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002908: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000290C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80002910: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80002914: sh          $v0, -0x733C($at)
    MEM_H(-0X733C, ctx->r1) = ctx->r2;
    // 0x80002918: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000291C: bgtz        $v0, L_800029A0
    if (SIGNED(ctx->r2) > 0) {
        // 0x80002920: nop
    
            goto L_800029A0;
    }
    // 0x80002920: nop

    // 0x80002924: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80002928: lhu         $a1, -0x1D10($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X1D10);
    // 0x8000292C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80002930: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002934: sh          $v0, -0x1D10($at)
    MEM_H(-0X1D10, ctx->r1) = ctx->r2;
    // 0x80002938: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000293C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80002940: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80002944: bne         $v0, $zero, L_80002954
    if (ctx->r2 != 0) {
        // 0x80002948: nop
    
            goto L_80002954;
    }
    // 0x80002948: nop

    // 0x8000294C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002950: sh          $zero, -0x1D10($at)
    MEM_H(-0X1D10, ctx->r1) = 0;
L_80002954:
    // 0x80002954: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80002958: lh          $v1, -0x1D10($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X1D10);
    // 0x8000295C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80002960: addiu       $a0, $a0, 0x142C
    ctx->r4 = ADD32(ctx->r4, 0X142C);
    // 0x80002964: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80002968: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8000296C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80002970: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80002974: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80002978: lhu         $a2, 0x0($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X0);
    // 0x8000297C: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80002980: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x80002984: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80002988: sh          $a2, 0x4AAC($at)
    MEM_H(0X4AAC, ctx->r1) = ctx->r6;
    // 0x8000298C: jal         0x800028C8
    // 0x80002990: nop

    func_800028C8(rdram, ctx);
        goto after_0;
    // 0x80002990: nop

    after_0:
    // 0x80002994: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80002998: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000299C: sh          $v0, -0x733C($at)
    MEM_H(-0X733C, ctx->r1) = ctx->r2;
L_800029A0:
    // 0x800029A0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800029A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800029A8: jr          $ra
    // 0x800029AC: nop

    return;
    // 0x800029AC: nop

;}
RECOMP_FUNC void func_800029B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800029B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800029B4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800029B8: jal         0x8005E190
    // 0x800029BC: nop

    func_8005E190(rdram, ctx);
        goto after_0;
    // 0x800029BC: nop

    after_0:
    // 0x800029C0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800029C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800029C8: jr          $ra
    // 0x800029CC: nop

    return;
    // 0x800029CC: nop

;}
RECOMP_FUNC void func_800029D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800029D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800029D4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800029D8: jal         0x8005E678
    // 0x800029DC: nop

    func_8005E678(rdram, ctx);
        goto after_0;
    // 0x800029DC: nop

    after_0:
    // 0x800029E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800029E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800029E8: jr          $ra
    // 0x800029EC: nop

    return;
    // 0x800029EC: nop

;}
RECOMP_FUNC void func_800029F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800029F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800029F4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800029F8: jal         0x8005E520
    // 0x800029FC: nop

    func_8005E520(rdram, ctx);
        goto after_0;
    // 0x800029FC: nop

    after_0:
    // 0x80002A00: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80002A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002A08: jr          $ra
    // 0x80002A0C: nop

    return;
    // 0x80002A0C: nop

;}
RECOMP_FUNC void func_80002A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80002A14: sh          $a0, 0x475C($at)
    MEM_H(0X475C, ctx->r1) = ctx->r4;
    // 0x80002A18: jr          $ra
    // 0x80002A1C: nop

    return;
    // 0x80002A1C: nop

;}
RECOMP_FUNC void func_80002A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A20: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80002A24: lhu         $a1, 0x90($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X90);
;}
RECOMP_FUNC void func_80002A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002A2C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80002A30: xori        $v1, $a1, 0x150
    ctx->r3 = ctx->r5 ^ 0X150;
    // 0x80002A34: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80002A38: xori        $v0, $a1, 0x220
    ctx->r2 = ctx->r5 ^ 0X220;
    // 0x80002A3C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80002A40: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80002A44: bne         $v1, $zero, L_80002A58
    if (ctx->r3 != 0) {
        // 0x80002A48: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80002A58;
    }
    // 0x80002A48: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80002A4C: addiu       $v0, $zero, 0x240
    ctx->r2 = ADD32(0, 0X240);
    // 0x80002A50: bne         $a1, $v0, L_80002A5C
    if (ctx->r5 != ctx->r2) {
        // 0x80002A54: nop
    
            goto L_80002A5C;
    }
    // 0x80002A54: nop

L_80002A58:
    // 0x80002A58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80002A5C:
    // 0x80002A5C: jal         0x80060A0C
    // 0x80002A60: nop

    func_80060A0C(rdram, ctx);
        goto after_0;
    // 0x80002A60: nop

    after_0:
    // 0x80002A64: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80002A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002A6C: jr          $ra
    // 0x80002A70: nop

    return;
    // 0x80002A70: nop

    // 0x80002A74: nop

    // 0x80002A78: nop

    // 0x80002A7C: nop

;}
RECOMP_FUNC void func_80002A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A80: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80002A84: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80002A88: lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X90);
    // 0x80002A8C: jr          $ra
    // 0x80002A90: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    return;
    // 0x80002A90: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80002A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A94: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80002A98: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80002A9C: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x80002AA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002AA4: jr          $ra
    // 0x80002AA8: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
    return;
    // 0x80002AA8: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80002AAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002AAC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80002AB0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80002AB4: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x80002AB8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80002ABC: jr          $ra
    // 0x80002AC0: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
    return;
    // 0x80002AC0: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80002AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002AC4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80002AC8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80002ACC: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x80002AD0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80002AD4: jr          $ra
    // 0x80002AD8: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
    return;
    // 0x80002AD8: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80002ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002ADC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80002AE0: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80002AE4: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x80002AE8: lw          $a1, 0x90($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X90);
    // 0x80002AEC: lw          $v1, 0x44($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X44);
    // 0x80002AF0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80002AF4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80002AF8: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80002AFC: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80002B00: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80002B04: sw          $v1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r3;
    // 0x80002B08: lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XC);
    // 0x80002B0C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80002B10: beq         $v1, $v0, L_80002B5C
    if (ctx->r3 == ctx->r2) {
        // 0x80002B14: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_80002B5C;
    }
    // 0x80002B14: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80002B18: beq         $v0, $zero, L_80002B30
    if (ctx->r2 == 0) {
        // 0x80002B1C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80002B30;
    }
    // 0x80002B1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002B20: beq         $v1, $v0, L_80002B44
    if (ctx->r3 == ctx->r2) {
        // 0x80002B24: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80002B44;
    }
    // 0x80002B24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002B28: j           L_80002B90
    // 0x80002B2C: nop

        goto L_80002B90;
    // 0x80002B2C: nop

L_80002B30:
    // 0x80002B30: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80002B34: beq         $v1, $v0, L_80002B78
    if (ctx->r3 == ctx->r2) {
        // 0x80002B38: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80002B78;
    }
    // 0x80002B38: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80002B3C: j           L_80002B90
    // 0x80002B40: nop

        goto L_80002B90;
    // 0x80002B40: nop

L_80002B44:
    // 0x80002B44: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80002B48: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80002B4C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80002B50: sh          $v0, -0x5874($at)
    MEM_H(-0X5874, ctx->r1) = ctx->r2;
    // 0x80002B54: j           L_80002B98
    // 0x80002B58: sw          $t0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r8;
        goto L_80002B98;
    // 0x80002B58: sw          $t0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r8;
L_80002B5C:
    // 0x80002B5C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80002B60: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80002B64: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80002B68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80002B6C: sh          $v0, -0x5874($at)
    MEM_H(-0X5874, ctx->r1) = ctx->r2;
    // 0x80002B70: j           L_80002B98
    // 0x80002B74: sw          $a2, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r6;
        goto L_80002B98;
    // 0x80002B74: sw          $a2, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r6;
L_80002B78:
    // 0x80002B78: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80002B7C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80002B80: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80002B84: sh          $v0, -0x5874($at)
    MEM_H(-0X5874, ctx->r1) = ctx->r2;
    // 0x80002B88: j           L_80002B98
    // 0x80002B8C: sw          $a3, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r7;
        goto L_80002B98;
    // 0x80002B8C: sw          $a3, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r7;
L_80002B90:
    // 0x80002B90: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80002B94: sh          $zero, -0x5874($at)
    MEM_H(-0X5874, ctx->r1) = 0;
L_80002B98:
    // 0x80002B98: jr          $ra
    // 0x80002B9C: nop

    return;
    // 0x80002B9C: nop

;}
RECOMP_FUNC void func_80002BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002BA0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80002BA4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
;}
RECOMP_FUNC void func_80002BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002BAC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80002BB0: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x80002BB4: addiu       $v0, $v0, 0x32
    ctx->r2 = ADD32(ctx->r2, 0X32);
    // 0x80002BB8: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    // 0x80002BBC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80002BC0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80002BC4: lw          $v0, 0x34($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X34);
    // 0x80002BC8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80002BCC: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x80002BD0: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80002BD4: jal         0x80000540
    // 0x80002BD8: nop

    func_80000540(rdram, ctx);
        goto after_0;
    // 0x80002BD8: nop

    after_0:
    // 0x80002BDC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80002BE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002BE4: jr          $ra
    // 0x80002BE8: nop

    return;
    // 0x80002BE8: nop

;}
RECOMP_FUNC void func_80002BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002BEC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80002BF0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80002BF4: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    // 0x80002BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002BFC: jr          $ra
    // 0x80002C00: sh          $v0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r2;
    return;
    // 0x80002C00: sh          $v0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80002C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002C04: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80002C08: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80002C0C: lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X90);
    // 0x80002C10: jr          $ra
    // 0x80002C14: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    return;
    // 0x80002C14: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80002C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002C18: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80002C1C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80002C20: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x80002C24: addiu       $v0, $v0, 0x300
    ctx->r2 = ADD32(ctx->r2, 0X300);
    // 0x80002C28: jr          $ra
    // 0x80002C2C: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    return;
    // 0x80002C2C: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80002C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002C30: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80002C34: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80002C38: addiu       $v0, $zero, 0xDA
    ctx->r2 = ADD32(0, 0XDA);
    // 0x80002C3C: jr          $ra
    // 0x80002C40: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    return;
    // 0x80002C40: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    // 0x80002C44: nop

    // 0x80002C48: nop

    // 0x80002C4C: nop

;}
RECOMP_FUNC void func_80002C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002C50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002C54: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80002C58: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80002C5C: addiu       $s0, $s0, 0x31C0
    ctx->r16 = ADD32(ctx->r16, 0X31C0);
    // 0x80002C60: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80002C64: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80002C68: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80002C6C: jal         0x800306EC
    // 0x80002C70: nop

    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80002C70: nop

    after_0:
    // 0x80002C74: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80002C78: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80002C7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80002C80: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x80002C84: lhu         $v1, 0x14($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X14);
    // 0x80002C88: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x80002C8C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80002C90: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80002C94: lhu         $v1, 0x18($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X18);
    // 0x80002C98: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x80002C9C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80002CA0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80002CA4: lhu         $v1, 0x80($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X80);
    // 0x80002CA8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002CAC: addiu       $a0, $a0, 0x7EB0
    ctx->r4 = ADD32(ctx->r4, 0X7EB0);
    // 0x80002CB0: sw          $a0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r4;
    // 0x80002CB4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80002CB8: jal         0x80023E44
    // 0x80002CBC: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x80002CBC: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    after_1:
    // 0x80002CC0: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    // 0x80002CC4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80002CC8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80002CCC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80002CD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80002CD4: jr          $ra
    // 0x80002CD8: nop

    return;
    // 0x80002CD8: nop

;}
RECOMP_FUNC void func_80002CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002CDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80002CE0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80002CE4: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80002CE8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80002CEC: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80002CF0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80002CF4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80002CF8: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x80002CFC: addiu       $s3, $s3, 0x31C0
    ctx->r19 = ADD32(ctx->r19, 0X31C0);
    // 0x80002D00: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80002D04: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80002D08: lw          $s4, 0x0($s3)
    ctx->r20 = MEM_W(ctx->r19, 0X0);
    // 0x80002D0C: jal         0x800306EC
    // 0x80002D10: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80002D10: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    after_0:
    // 0x80002D14: addiu       $v1, $zero, 0x7000
    ctx->r3 = ADD32(0, 0X7000);
    // 0x80002D18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80002D1C: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x80002D20: sh          $s0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r16;
    // 0x80002D24: sh          $s1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r17;
    // 0x80002D28: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x80002D2C: sw          $s2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r18;
    // 0x80002D30: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80002D34: jal         0x80023E44
    // 0x80002D38: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x80002D38: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    after_1:
    // 0x80002D3C: sw          $s4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r20;
    // 0x80002D40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80002D44: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80002D48: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80002D4C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80002D50: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80002D54: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80002D58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80002D5C: jr          $ra
    // 0x80002D60: nop

    return;
    // 0x80002D60: nop

;}
RECOMP_FUNC void func_80002D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002D64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002D68: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80002D6C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80002D70: addiu       $s0, $s0, 0x31C0
    ctx->r16 = ADD32(ctx->r16, 0X31C0);
    // 0x80002D74: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80002D78: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80002D7C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80002D80: jal         0x800306EC
    // 0x80002D84: nop

    func_800306EC(rdram, ctx);
        goto after_0;
    // 0x80002D84: nop

    after_0:
    // 0x80002D88: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80002D8C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80002D90: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80002D94: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x80002D98: lhu         $v1, 0x14($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X14);
    // 0x80002D9C: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x80002DA0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80002DA4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80002DA8: lhu         $v1, 0x18($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X18);
    // 0x80002DAC: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x80002DB0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80002DB4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80002DB8: lhu         $v1, 0x80($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X80);
    // 0x80002DBC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002DC0: addiu       $a0, $a0, 0x7EF0
    ctx->r4 = ADD32(ctx->r4, 0X7EF0);
    // 0x80002DC4: sw          $a0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r4;
    // 0x80002DC8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80002DCC: jal         0x80023E44
    // 0x80002DD0: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    func_80023E44(rdram, ctx);
        goto after_1;
    // 0x80002DD0: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    after_1:
    // 0x80002DD4: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    // 0x80002DD8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80002DDC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80002DE0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80002DE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80002DE8: jr          $ra
    // 0x80002DEC: nop

    return;
    // 0x80002DEC: nop

;}
RECOMP_FUNC void func_80002DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002DF0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80002DF4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
;}
RECOMP_FUNC void func_80002DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002DF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002DFC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80002E00: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80002E04: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x80002E08: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80002E0C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80002E10: bne         $v0, $zero, L_80002E50
    if (ctx->r2 != 0) {
        // 0x80002E14: addiu       $v0, $zero, 0x220
        ctx->r2 = ADD32(0, 0X220);
            goto L_80002E50;
    }
    // 0x80002E14: addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // 0x80002E18: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80002E1C: lhu         $v1, 0x90($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X90);
    // 0x80002E20: bne         $v1, $v0, L_80002E48
    if (ctx->r3 != ctx->r2) {
        // 0x80002E24: nop
    
            goto L_80002E48;
    }
    // 0x80002E24: nop

    // 0x80002E28: addiu       $a0, $zero, 0x1FF
    ctx->r4 = ADD32(0, 0X1FF);
    // 0x80002E2C: jal         0x80001414
    // 0x80002E30: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80001414(rdram, ctx);
        goto after_0;
    // 0x80002E30: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80002E34: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x80002E38: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80002E3C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80002E40: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80002E44: lhu         $a0, 0x1440($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X1440);
L_80002E48:
    // 0x80002E48: jal         0x8004C79C
    // 0x80002E4C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_8004C79C(rdram, ctx);
        goto after_1;
    // 0x80002E4C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_1:
L_80002E50:
    // 0x80002E50: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80002E54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002E58: jr          $ra
    // 0x80002E5C: nop

    return;
    // 0x80002E5C: nop

;}
RECOMP_FUNC void func_80002E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002E60: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80002E64: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80002E68: lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X90);
    // 0x80002E6C: lhu         $v0, 0x28($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X28);
    // 0x80002E70: bne         $v0, $zero, L_80002E84
    if (ctx->r2 != 0) {
        // 0x80002E74: nop
    
            goto L_80002E84;
    }
    // 0x80002E74: nop

    // 0x80002E78: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x80002E7C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80002E80: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
L_80002E84:
    // 0x80002E84: jr          $ra
    // 0x80002E88: nop

    return;
    // 0x80002E88: nop

;}
RECOMP_FUNC void func_80002E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002E8C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80002E90: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80002E94: lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X90);
    // 0x80002E98: lhu         $v0, 0x28($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X28);
    // 0x80002E9C: beq         $v0, $zero, L_80002EB0
    if (ctx->r2 == 0) {
        // 0x80002EA0: nop
    
            goto L_80002EB0;
    }
    // 0x80002EA0: nop

    // 0x80002EA4: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x80002EA8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80002EAC: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
L_80002EB0:
    // 0x80002EB0: jr          $ra
    // 0x80002EB4: nop

    return;
    // 0x80002EB4: nop

;}
