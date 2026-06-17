#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_80039564(uint8_t* rdram, recomp_context* ctx);
void func_8003965C(uint8_t* rdram, recomp_context* ctx);
void func_800396C8(uint8_t* rdram, recomp_context* ctx);
void func_80039930(uint8_t* rdram, recomp_context* ctx);
void func_80039E68(uint8_t* rdram, recomp_context* ctx);
void func_8003A0CC(uint8_t* rdram, recomp_context* ctx);
void func_8003A2AC(uint8_t* rdram, recomp_context* ctx);
void func_8003A398(uint8_t* rdram, recomp_context* ctx);
void func_8003A478(uint8_t* rdram, recomp_context* ctx);
void func_8003A618(uint8_t* rdram, recomp_context* ctx);
void func_8003A688(uint8_t* rdram, recomp_context* ctx);
void func_8003A6E4(uint8_t* rdram, recomp_context* ctx);
void func_8003AA30(uint8_t* rdram, recomp_context* ctx);
void func_8003AA60(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80038DCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038DCC: lw          $a1, 0x68($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X68);
    // 0x80038DD0: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x80038DD4: lhu         $a0, 0x22($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X22);
    // 0x80038DD8: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80038DDC: andi        $v1, $a0, 0x10
    ctx->r3 = ctx->r4 & 0X10;
    // 0x80038DE0: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80038DE4: bne         $v1, $v0, L_80038DF0
    if (ctx->r3 != ctx->r2) {
        // 0x80038DE8: xori        $v0, $a0, 0x10
        ctx->r2 = ctx->r4 ^ 0X10;
            goto L_80038DF0;
    }
    // 0x80038DE8: xori        $v0, $a0, 0x10
    ctx->r2 = ctx->r4 ^ 0X10;
    // 0x80038DEC: sh          $v0, 0x22($a1)
    MEM_H(0X22, ctx->r5) = ctx->r2;
L_80038DF0:
    // 0x80038DF0: jr          $ra
    // 0x80038DF4: nop

    return;
    // 0x80038DF4: nop

;}
RECOMP_FUNC void func_80038DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038DF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038DFC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80038E00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038E04: jal         0x80038B84
    // 0x80038E08: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80038B84(rdram, ctx);
        goto after_0;
    // 0x80038E08: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80038E0C: lw          $v0, 0x104($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X104);
    // 0x80038E10: beq         $v0, $zero, L_80038E3C
    if (ctx->r2 == 0) {
        // 0x80038E14: nop
    
            goto L_80038E3C;
    }
    // 0x80038E14: nop

    // 0x80038E18: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80038E1C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80038E20: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x80038E24: bltz        $v0, L_80038E44
    if (SIGNED(ctx->r2) < 0) {
        // 0x80038E28: nop
    
            goto L_80038E44;
    }
    // 0x80038E28: nop

    // 0x80038E2C: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
    // 0x80038E30: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x80038E34: bne         $v0, $zero, L_80038E44
    if (ctx->r2 != 0) {
        // 0x80038E38: nop
    
            goto L_80038E44;
    }
    // 0x80038E38: nop

L_80038E3C:
    // 0x80038E3C: jal         0x8003AD80
    // 0x80038E40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AD80(rdram, ctx);
        goto after_1;
    // 0x80038E40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
L_80038E44:
    // 0x80038E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038E48: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80038E4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038E50: jr          $ra
    // 0x80038E54: nop

    return;
    // 0x80038E54: nop

;}
RECOMP_FUNC void func_80038E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038E58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038E5C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80038E60: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80038E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038E68: lw          $a2, 0x68($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X68);
    // 0x80038E6C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80038E70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80038E74: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    // 0x80038E78: lhu         $v0, 0x22($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X22);
    // 0x80038E7C: lui         $v1, 0xFFFE
    ctx->r3 = S32(0XFFFE << 16);
    // 0x80038E80: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80038E84: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80038E88: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80038E8C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80038E90: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80038E94: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x80038E98: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80038E9C: jal         0x800425D8
    // 0x80038EA0: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    func_800425D8(rdram, ctx);
        goto after_0;
    // 0x80038EA0: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    after_0:
    // 0x80038EA4: jal         0x8003C154
    // 0x80038EA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003C154(rdram, ctx);
        goto after_1;
    // 0x80038EA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80038EAC: jal         0x80038DF8
    // 0x80038EB0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80038DF8(rdram, ctx);
        goto after_2;
    // 0x80038EB0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80038EB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038EB8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80038EBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038EC0: jr          $ra
    // 0x80038EC4: nop

    return;
    // 0x80038EC4: nop

;}
RECOMP_FUNC void func_80038EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038EC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038ECC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80038ED0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80038ED4: addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    // 0x80038ED8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80038EDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038EE0: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    // 0x80038EE4: jal         0x800425D8
    // 0x80038EE8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800425D8(rdram, ctx);
        goto after_0;
    // 0x80038EE8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80038EEC: jal         0x8003C154
    // 0x80038EF0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003C154(rdram, ctx);
        goto after_1;
    // 0x80038EF0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80038EF4: jal         0x80038DF8
    // 0x80038EF8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80038DF8(rdram, ctx);
        goto after_2;
    // 0x80038EF8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80038EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038F00: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80038F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038F08: jr          $ra
    // 0x80038F0C: nop

    return;
    // 0x80038F0C: nop

;}
RECOMP_FUNC void func_80038F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038F14: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80038F18: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80038F1C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80038F20: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // 0x80038F24: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80038F28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038F2C: jal         0x80060F30
    // 0x80038F30: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
    func_80060F30(rdram, ctx);
        goto after_0;
    // 0x80038F30: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
    after_0:
    // 0x80038F34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80038F38: jal         0x800425D8
    // 0x80038F3C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800425D8(rdram, ctx);
        goto after_1;
    // 0x80038F3C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80038F40: jal         0x8003C154
    // 0x80038F44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003C154(rdram, ctx);
        goto after_2;
    // 0x80038F44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80038F48: jal         0x80038DF8
    // 0x80038F4C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80038DF8(rdram, ctx);
        goto after_3;
    // 0x80038F4C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80038F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038F54: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80038F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038F5C: jr          $ra
    // 0x80038F60: nop

    return;
    // 0x80038F60: nop

;}
RECOMP_FUNC void func_80038F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038F64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80038F68: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80038F6C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80038F70: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80038F74: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80038F78: jal         0x80038DCC
    // 0x80038F7C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    func_80038DCC(rdram, ctx);
        goto after_0;
    // 0x80038F7C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80038F80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80038F84: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80038F88: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80038F8C: jal         0x800425D8
    // 0x80038F90: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    func_800425D8(rdram, ctx);
        goto after_1;
    // 0x80038F90: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    after_1:
    // 0x80038F94: jal         0x8003C154
    // 0x80038F98: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8003C154(rdram, ctx);
        goto after_2;
    // 0x80038F98: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x80038F9C: lw          $v1, 0x68($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X68);
    // 0x80038FA0: lui         $v0, 0xFFFA
    ctx->r2 = S32(0XFFFA << 16);
    // 0x80038FA4: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80038FA8: lw          $a1, 0x68($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X68);
    // 0x80038FAC: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x80038FB0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80038FB4: lui         $v1, 0xFFFE
    ctx->r3 = S32(0XFFFE << 16);
    // 0x80038FB8: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80038FBC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80038FC0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80038FC4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80038FC8: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x80038FCC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80038FD0: jal         0x80038DF8
    // 0x80038FD4: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    func_80038DF8(rdram, ctx);
        goto after_3;
    // 0x80038FD4: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    after_3:
    // 0x80038FD8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80038FDC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80038FE0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80038FE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80038FE8: jr          $ra
    // 0x80038FEC: nop

    return;
    // 0x80038FEC: nop

;}
RECOMP_FUNC void func_80038FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038FF4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80038FF8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80038FFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039000: lw          $a2, 0x68($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X68);
    // 0x80039004: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80039008: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003900C: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    // 0x80039010: lhu         $v0, 0x22($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X22);
    // 0x80039014: lui         $v1, 0xFFFC
    ctx->r3 = S32(0XFFFC << 16);
    // 0x80039018: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8003901C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80039020: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80039024: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80039028: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8003902C: lui         $v1, 0x4
    ctx->r3 = S32(0X4 << 16);
    // 0x80039030: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80039034: jal         0x800425D8
    // 0x80039038: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    func_800425D8(rdram, ctx);
        goto after_0;
    // 0x80039038: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    after_0:
    // 0x8003903C: jal         0x8003C154
    // 0x80039040: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003C154(rdram, ctx);
        goto after_1;
    // 0x80039040: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80039044: jal         0x80038DF8
    // 0x80039048: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80038DF8(rdram, ctx);
        goto after_2;
    // 0x80039048: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8003904C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039050: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80039054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039058: jr          $ra
    // 0x8003905C: nop

    return;
    // 0x8003905C: nop

;}
RECOMP_FUNC void func_80039060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039060: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80039064: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80039068: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003906C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80039070: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80039074: lhu         $v0, 0x164($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X164);
    // 0x80039078: bne         $v0, $zero, L_800390DC
    if (ctx->r2 != 0) {
        // 0x8003907C: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_800390DC;
    }
    // 0x8003907C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80039080: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x80039084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80039088: sh          $v0, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r2;
    // 0x8003908C: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
    // 0x80039090: sh          $v0, 0x5A($s1)
    MEM_H(0X5A, ctx->r17) = ctx->r2;
    // 0x80039094: addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
    // 0x80039098: sh          $v1, 0xE4($s1)
    MEM_H(0XE4, ctx->r17) = ctx->r3;
    // 0x8003909C: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x800390A0: sh          $zero, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = 0;
    // 0x800390A4: sh          $zero, 0x18C($s1)
    MEM_H(0X18C, ctx->r17) = 0;
    // 0x800390A8: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x800390AC: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x800390B0: sh          $v0, 0x12A($s1)
    MEM_H(0X12A, ctx->r17) = ctx->r2;
    // 0x800390B4: sh          $v1, 0x12A($s0)
    MEM_H(0X12A, ctx->r16) = ctx->r3;
    // 0x800390B8: lw          $a0, 0x68($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X68);
    // 0x800390BC: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    // 0x800390C0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800390C4: jal         0x80041F70
    // 0x800390C8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80041F70(rdram, ctx);
        goto after_0;
    // 0x800390C8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800390CC: jal         0x80038DF8
    // 0x800390D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80038DF8(rdram, ctx);
        goto after_1;
    // 0x800390D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800390D4: j           L_80039100
    // 0x800390D8: nop

        goto L_80039100;
    // 0x800390D8: nop

L_800390DC:
    // 0x800390DC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800390E0: lh          $v0, 0x13E6($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X13E6);
    // 0x800390E4: beq         $v0, $zero, L_800390F4
    if (ctx->r2 == 0) {
        // 0x800390E8: lui         $a0, 0x3
        ctx->r4 = S32(0X3 << 16);
            goto L_800390F4;
    }
    // 0x800390E8: lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // 0x800390EC: jal         0x8003BA80
    // 0x800390F0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8003BA80(rdram, ctx);
        goto after_2;
    // 0x800390F0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
L_800390F4:
    // 0x800390F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800390F8: jal         0x80038F10
    // 0x800390FC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80038F10(rdram, ctx);
        goto after_3;
    // 0x800390FC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
L_80039100:
    // 0x80039100: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80039104: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80039108: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003910C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80039110: jr          $ra
    // 0x80039114: nop

    return;
    // 0x80039114: nop

;}
RECOMP_FUNC void func_80039118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003911C: addiu       $v0, $zero, 0x4F
    ctx->r2 = ADD32(0, 0X4F);
    // 0x80039120: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80039124: jal         0x80038DF8
    // 0x80039128: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    func_80038DF8(rdram, ctx);
        goto after_0;
    // 0x80039128: sh          $v0, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r2;
    after_0:
    // 0x8003912C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80039130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039134: jr          $ra
    // 0x80039138: nop

    return;
    // 0x80039138: nop

;}
RECOMP_FUNC void func_8003913C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003913C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039140: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80039144: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80039148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003914C: lw          $a0, 0x68($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X68);
    // 0x80039150: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80039154: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80039158: lhu         $v1, 0x22($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X22);
    // 0x8003915C: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80039160: andi        $v1, $v1, 0x10
    ctx->r3 = ctx->r3 & 0X10;
    // 0x80039164: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80039168: bne         $v1, $v0, L_80039180
    if (ctx->r3 != ctx->r2) {
        // 0x8003916C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80039180;
    }
    // 0x8003916C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80039170: jal         0x80039060
    // 0x80039174: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80039060(rdram, ctx);
        goto after_0;
    // 0x80039174: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80039178: j           L_800391D8
    // 0x8003917C: nop

        goto L_800391D8;
    // 0x8003917C: nop

L_80039180:
    // 0x80039180: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80039184: lw          $v1, 0x31A8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31A8);
    // 0x80039188: bne         $v1, $v0, L_800391B8
    if (ctx->r3 != ctx->r2) {
        // 0x8003918C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800391B8;
    }
    // 0x8003918C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80039190: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x80039194: bne         $v1, $v0, L_800391B8
    if (ctx->r3 != ctx->r2) {
        // 0x80039198: nop
    
            goto L_800391B8;
    }
    // 0x80039198: nop

    // 0x8003919C: lw          $v0, 0x104($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X104);
    // 0x800391A0: bne         $v0, $zero, L_800391B8
    if (ctx->r2 != 0) {
        // 0x800391A4: nop
    
            goto L_800391B8;
    }
    // 0x800391A4: nop

    // 0x800391A8: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x800391AC: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x800391B0: beq         $v0, $zero, L_800391C8
    if (ctx->r2 == 0) {
        // 0x800391B4: nop
    
            goto L_800391C8;
    }
    // 0x800391B4: nop

L_800391B8:
    // 0x800391B8: jal         0x80039118
    // 0x800391BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80039118(rdram, ctx);
        goto after_1;
    // 0x800391BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800391C0: j           L_800391D8
    // 0x800391C4: nop

        goto L_800391D8;
    // 0x800391C4: nop

L_800391C8:
    // 0x800391C8: jal         0x80041118
    // 0x800391CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80041118(rdram, ctx);
        goto after_2;
    // 0x800391CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800391D0: jal         0x80038DF8
    // 0x800391D4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80038DF8(rdram, ctx);
        goto after_3;
    // 0x800391D4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
L_800391D8:
    // 0x800391D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800391DC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800391E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800391E4: jr          $ra
    // 0x800391E8: nop

    return;
    // 0x800391E8: nop

;}
RECOMP_FUNC void func_800391EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800391EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800391F0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800391F4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800391F8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800391FC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80039200: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80039204: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80039208: lh          $v0, 0x120($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X120);
    // 0x8003920C: beq         $v0, $zero, L_80039470
    if (ctx->r2 == 0) {
        // 0x80039210: nop
    
            goto L_80039470;
    }
    // 0x80039210: nop

    // 0x80039214: lhu         $v0, 0x1B0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X1B0);
    // 0x80039218: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x8003921C: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x80039220: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80039224: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80039228: beq         $v1, $zero, L_80039280
    if (ctx->r3 == 0) {
        // 0x8003922C: addiu       $s2, $zero, 0x7
        ctx->r18 = ADD32(0, 0X7);
            goto L_80039280;
    }
    // 0x8003922C: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
    // 0x80039230: j           L_80039470
    // 0x80039234: nop

        goto L_80039470;
    // 0x80039234: nop

L_80039238:
    // 0x80039238: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8003923C: jal         0x8003913C
    // 0x80039240: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003913C(rdram, ctx);
        goto after_0;
    // 0x80039240: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80039244: j           L_80039478
    // 0x80039248: nop

        goto L_80039478;
    // 0x80039248: nop

L_8003924C:
    // 0x8003924C: jal         0x80038EC8
    // 0x80039250: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80038EC8(rdram, ctx);
        goto after_1;
    // 0x80039250: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80039254: j           L_80039478
    // 0x80039258: nop

        goto L_80039478;
    // 0x80039258: nop

L_8003925C:
    // 0x8003925C: jal         0x80038F64
    // 0x80039260: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80038F64(rdram, ctx);
        goto after_2;
    // 0x80039260: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80039264: j           L_80039478
    // 0x80039268: nop

        goto L_80039478;
    // 0x80039268: nop

L_8003926C:
    // 0x8003926C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80039270: jal         0x80038F10
    // 0x80039274: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80038F10(rdram, ctx);
        goto after_3;
    // 0x80039274: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80039278: j           L_80039478
    // 0x8003927C: nop

        goto L_80039478;
    // 0x8003927C: nop

L_80039280:
    // 0x80039280: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x80039284: addiu       $s3, $s3, 0x31A8
    ctx->r19 = ADD32(ctx->r19, 0X31A8);
    // 0x80039288: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
L_8003928C:
    // 0x8003928C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80039290: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80039294: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80039298: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8003929C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800392A0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800392A4: addiu       $v0, $v0, 0x3F94
    ctx->r2 = ADD32(ctx->r2, 0X3F94);
    // 0x800392A8: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x800392AC: beq         $s0, $s1, L_800393E8
    if (ctx->r16 == ctx->r17) {
        // 0x800392B0: addiu       $v0, $s2, -0x1
        ctx->r2 = ADD32(ctx->r18, -0X1);
            goto L_800393E8;
    }
    // 0x800392B0: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x800392B4: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
    // 0x800392B8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800392BC: beq         $v0, $zero, L_800393E8
    if (ctx->r2 == 0) {
        // 0x800392C0: addiu       $v0, $s2, -0x1
        ctx->r2 = ADD32(ctx->r18, -0X1);
            goto L_800393E8;
    }
    // 0x800392C0: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x800392C4: lhu         $v0, 0xDC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XDC);
    // 0x800392C8: beq         $v0, $zero, L_800393E4
    if (ctx->r2 == 0) {
        // 0x800392CC: addiu       $v0, $zero, 0x37
        ctx->r2 = ADD32(0, 0X37);
            goto L_800393E4;
    }
    // 0x800392CC: addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
    // 0x800392D0: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x800392D4: beq         $v1, $v0, L_800393E4
    if (ctx->r3 == ctx->r2) {
        // 0x800392D8: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800393E4;
    }
    // 0x800392D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800392DC: jal         0x8003B5B4
    // 0x800392E0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003B5B4(rdram, ctx);
        goto after_4;
    // 0x800392E0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_4:
    // 0x800392E4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800392E8: beq         $v0, $zero, L_800393E4
    if (ctx->r2 == 0) {
        // 0x800392EC: sw          $v0, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r2;
            goto L_800393E4;
    }
    // 0x800392EC: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800392F0: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x800392F4: addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
    // 0x800392F8: beq         $v1, $v0, L_80039238
    if (ctx->r3 == ctx->r2) {
        // 0x800392FC: sw          $s1, 0x180($s0)
        MEM_W(0X180, ctx->r16) = ctx->r17;
            goto L_80039238;
    }
    // 0x800392FC: sw          $s1, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->r17;
    // 0x80039300: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80039304: jal         0x80060F30
    // 0x80039308: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80060F30(rdram, ctx);
        goto after_5;
    // 0x80039308: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x8003930C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80039310: lh          $v0, 0x13E6($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X13E6);
    // 0x80039314: beq         $v0, $zero, L_80039324
    if (ctx->r2 == 0) {
        // 0x80039318: lui         $a0, 0x3
        ctx->r4 = S32(0X3 << 16);
            goto L_80039324;
    }
    // 0x80039318: lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // 0x8003931C: jal         0x8003BA80
    // 0x80039320: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003BA80(rdram, ctx);
        goto after_6;
    // 0x80039320: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_6:
L_80039324:
    // 0x80039324: lhu         $v0, 0x18E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18E);
    // 0x80039328: bne         $v0, $zero, L_8003924C
    if (ctx->r2 != 0) {
        // 0x8003932C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8003924C;
    }
    // 0x8003932C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80039330: lhu         $v0, 0x164($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X164);
    // 0x80039334: bne         $v0, $zero, L_8003925C
    if (ctx->r2 != 0) {
        // 0x80039338: nop
    
            goto L_8003925C;
    }
    // 0x80039338: nop

    // 0x8003933C: lhu         $v0, 0x1B0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B0);
    // 0x80039340: bne         $v0, $zero, L_8003935C
    if (ctx->r2 != 0) {
        // 0x80039344: addiu       $v0, $zero, 0xE1
        ctx->r2 = ADD32(0, 0XE1);
            goto L_8003935C;
    }
    // 0x80039344: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x80039348: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    // 0x8003934C: lh          $v1, 0x18($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X18);
    // 0x80039350: beq         $v1, $v0, L_8003936C
    if (ctx->r3 == ctx->r2) {
        // 0x80039354: nop
    
            goto L_8003936C;
    }
    // 0x80039354: nop

    // 0x80039358: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8003935C:
    // 0x8003935C: jal         0x80038E58
    // 0x80039360: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80038E58(rdram, ctx);
        goto after_7;
    // 0x80039360: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_7:
    // 0x80039364: j           L_80039478
    // 0x80039368: nop

        goto L_80039478;
    // 0x80039368: nop

L_8003936C:
    // 0x8003936C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80039370: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80039374: lhu         $v1, 0x22($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X22);
    // 0x80039378: lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X22);
    // 0x8003937C: andi        $v1, $v1, 0x10
    ctx->r3 = ctx->r3 & 0X10;
    // 0x80039380: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80039384: beq         $v1, $v0, L_8003926C
    if (ctx->r3 == ctx->r2) {
        // 0x80039388: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003926C;
    }
    // 0x80039388: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003938C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80039390: bne         $v1, $v0, L_800393B4
    if (ctx->r3 != ctx->r2) {
        // 0x80039394: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800393B4;
    }
    // 0x80039394: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80039398: lhu         $v1, 0x5A($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X5A);
    // 0x8003939C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800393A0: bne         $v1, $v0, L_800393B4
    if (ctx->r3 != ctx->r2) {
        // 0x800393A4: nop
    
            goto L_800393B4;
    }
    // 0x800393A4: nop

    // 0x800393A8: lw          $v0, 0x104($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X104);
    // 0x800393AC: beq         $v0, $zero, L_800393C4
    if (ctx->r2 == 0) {
        // 0x800393B0: addiu       $v0, $zero, 0x28
        ctx->r2 = ADD32(0, 0X28);
            goto L_800393C4;
    }
    // 0x800393B0: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
L_800393B4:
    // 0x800393B4: jal         0x80038FF0
    // 0x800393B8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80038FF0(rdram, ctx);
        goto after_8;
    // 0x800393B8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_8:
    // 0x800393BC: j           L_80039478
    // 0x800393C0: nop

        goto L_80039478;
    // 0x800393C0: nop

L_800393C4:
    // 0x800393C4: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x800393C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800393CC: jal         0x800425D8
    // 0x800393D0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_800425D8(rdram, ctx);
        goto after_9;
    // 0x800393D0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_9:
    // 0x800393D4: jal         0x8003C0A0
    // 0x800393D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8003C0A0(rdram, ctx);
        goto after_10;
    // 0x800393D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // 0x800393DC: j           L_80039470
    // 0x800393E0: nop

        goto L_80039470;
    // 0x800393E0: nop

L_800393E4:
    // 0x800393E4: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
L_800393E8:
    // 0x800393E8: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800393EC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800393F0: bne         $v0, $zero, L_8003928C
    if (ctx->r2 != 0) {
        // 0x800393F4: andi        $v0, $s2, 0xFFFF
        ctx->r2 = ctx->r18 & 0XFFFF;
            goto L_8003928C;
    }
    // 0x800393F4: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x800393F8: lhu         $v0, 0x18A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18A);
    // 0x800393FC: bne         $v0, $zero, L_80039468
    if (ctx->r2 != 0) {
        // 0x80039400: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80039468;
    }
    // 0x80039400: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80039404: jal         0x80009474
    // 0x80039408: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80009474(rdram, ctx);
        goto after_11;
    // 0x80039408: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_11:
    // 0x8003940C: lhu         $v0, 0x18A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18A);
    // 0x80039410: bne         $v0, $zero, L_80039468
    if (ctx->r2 != 0) {
        // 0x80039414: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80039468;
    }
    // 0x80039414: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80039418: jal         0x800296B4
    // 0x8003941C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800296B4(rdram, ctx);
        goto after_12;
    // 0x8003941C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_12:
    // 0x80039420: lhu         $v0, 0x18A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18A);
    // 0x80039424: bne         $v0, $zero, L_80039468
    if (ctx->r2 != 0) {
        // 0x80039428: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80039468;
    }
    // 0x80039428: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8003942C: jal         0x800449C0
    // 0x80039430: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800449C0(rdram, ctx);
        goto after_13;
    // 0x80039430: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_13:
    // 0x80039434: lhu         $v0, 0x18A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18A);
    // 0x80039438: bne         $v0, $zero, L_80039468
    if (ctx->r2 != 0) {
        // 0x8003943C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80039468;
    }
    // 0x8003943C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80039440: jal         0x8003E4C0
    // 0x80039444: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8003E4C0(rdram, ctx);
        goto after_14;
    // 0x80039444: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_14:
    // 0x80039448: lhu         $v0, 0x18A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18A);
    // 0x8003944C: bne         $v0, $zero, L_80039468
    if (ctx->r2 != 0) {
        // 0x80039450: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80039468;
    }
    // 0x80039450: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80039454: jal         0x800361CC
    // 0x80039458: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800361CC(rdram, ctx);
        goto after_15;
    // 0x80039458: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_15:
    // 0x8003945C: lhu         $v0, 0x18A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18A);
    // 0x80039460: beq         $v0, $zero, L_80039470
    if (ctx->r2 == 0) {
        // 0x80039464: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80039470;
    }
    // 0x80039464: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80039468:
    // 0x80039468: jal         0x80060F30
    // 0x8003946C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80060F30(rdram, ctx);
        goto after_16;
    // 0x8003946C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_16:
L_80039470:
    // 0x80039470: jal         0x80038DF8
    // 0x80039474: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80038DF8(rdram, ctx);
        goto after_17;
    // 0x80039474: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_17:
L_80039478:
    // 0x80039478: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8003947C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80039480: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80039484: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80039488: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003948C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80039490: jr          $ra
    // 0x80039494: nop

    return;
    // 0x80039494: nop

;}
RECOMP_FUNC void func_80039498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003949C: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x800394A0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800394A4: sh          $zero, 0x1B0($a0)
    MEM_H(0X1B0, ctx->r4) = 0;
    // 0x800394A8: sh          $zero, 0x1B2($a0)
    MEM_H(0X1B2, ctx->r4) = 0;
    // 0x800394AC: sw          $v0, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->r2;
    // 0x800394B0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800394B4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x800394B8: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800394BC: blez        $v0, L_800394CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800394C0: nop
    
            goto L_800394CC;
    }
    // 0x800394C0: nop

    // 0x800394C4: jal         0x80039564
    // 0x800394C8: nop

    func_80039564(rdram, ctx);
        goto after_0;
    // 0x800394C8: nop

    after_0:
L_800394CC:
    // 0x800394CC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800394D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800394D4: jr          $ra
    // 0x800394D8: nop

    return;
    // 0x800394D8: nop

;}
RECOMP_FUNC void func_800394DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800394DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800394E0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800394E4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800394E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800394EC: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    // 0x800394F0: beq         $a0, $zero, L_80039504
    if (ctx->r4 == 0) {
        // 0x800394F4: nop
    
            goto L_80039504;
    }
    // 0x800394F4: nop

    // 0x800394F8: jal         0x80024764
    // 0x800394FC: nop

    func_80024764(rdram, ctx);
        goto after_0;
    // 0x800394FC: nop

    after_0:
    // 0x80039500: sw          $zero, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = 0;
L_80039504:
    // 0x80039504: lhu         $v0, 0x18E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18E);
    // 0x80039508: sh          $zero, 0x1B0($s0)
    MEM_H(0X1B0, ctx->r16) = 0;
    // 0x8003950C: beq         $v0, $zero, L_8003951C
    if (ctx->r2 == 0) {
        // 0x80039510: sh          $zero, 0x1B2($s0)
        MEM_H(0X1B2, ctx->r16) = 0;
            goto L_8003951C;
    }
    // 0x80039510: sh          $zero, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = 0;
    // 0x80039514: j           L_80039520
    // 0x80039518: ori         $v0, $zero, 0xC000
    ctx->r2 = 0 | 0XC000;
        goto L_80039520;
    // 0x80039518: ori         $v0, $zero, 0xC000
    ctx->r2 = 0 | 0XC000;
L_8003951C:
    // 0x8003951C: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
L_80039520:
    // 0x80039520: sw          $v0, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r2;
    // 0x80039524: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80039528: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003952C: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80039530: blez        $v0, L_80039548
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80039534: nop
    
            goto L_80039548;
    }
    // 0x80039534: nop

    // 0x80039538: jal         0x80039564
    // 0x8003953C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80039564(rdram, ctx);
        goto after_1;
    // 0x8003953C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80039540: j           L_80039550
    // 0x80039544: nop

        goto L_80039550;
    // 0x80039544: nop

L_80039548:
    // 0x80039548: jal         0x800396C8
    // 0x8003954C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800396C8(rdram, ctx);
        goto after_2;
    // 0x8003954C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_80039550:
    // 0x80039550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039554: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80039558: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003955C: jr          $ra
    // 0x80039560: nop

    return;
    // 0x80039560: nop

;}
RECOMP_FUNC void func_80039564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039568: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003956C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80039570: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80039574: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80039578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003957C: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x80039580: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x80039584: beq         $v0, $zero, L_8003959C
    if (ctx->r2 == 0) {
        // 0x80039588: addiu       $v1, $zero, 0xE1
        ctx->r3 = ADD32(0, 0XE1);
            goto L_8003959C;
    }
    // 0x80039588: addiu       $v1, $zero, 0xE1
    ctx->r3 = ADD32(0, 0XE1);
    // 0x8003958C: jal         0x8003965C
    // 0x80039590: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003965C(rdram, ctx);
        goto after_0;
    // 0x80039590: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80039594: j           L_80039648
    // 0x80039598: nop

        goto L_80039648;
    // 0x80039598: nop

L_8003959C:
    // 0x8003959C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800395A0: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x800395A4: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800395A8: bne         $v0, $zero, L_800395CC
    if (ctx->r2 != 0) {
        // 0x800395AC: sh          $v1, 0x18($a0)
        MEM_H(0X18, ctx->r4) = ctx->r3;
            goto L_800395CC;
    }
    // 0x800395AC: sh          $v1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r3;
    // 0x800395B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800395B4: lw          $v1, 0x3A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3A0);
    // 0x800395B8: beq         $v1, $zero, L_800395CC
    if (ctx->r3 == 0) {
        // 0x800395BC: lui         $v0, 0xFFF0
        ctx->r2 = S32(0XFFF0 << 16);
            goto L_800395CC;
    }
    // 0x800395BC: lui         $v0, 0xFFF0
    ctx->r2 = S32(0XFFF0 << 16);
    // 0x800395C0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800395C4: beq         $v0, $zero, L_80039640
    if (ctx->r2 == 0) {
        // 0x800395C8: nop
    
            goto L_80039640;
    }
    // 0x800395C8: nop

L_800395CC:
    // 0x800395CC: jal         0x8000B8E8
    // 0x800395D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000B8E8(rdram, ctx);
        goto after_1;
    // 0x800395D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800395D4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800395D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800395DC: bne         $v0, $v1, L_80039600
    if (ctx->r2 != ctx->r3) {
        // 0x800395E0: addiu       $v0, $zero, 0x17
        ctx->r2 = ADD32(0, 0X17);
            goto L_80039600;
    }
    // 0x800395E0: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
    // 0x800395E4: addiu       $v0, $zero, 0x35
    ctx->r2 = ADD32(0, 0X35);
    // 0x800395E8: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x800395EC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800395F0: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x800395F4: addiu       $v0, $zero, 0xED
    ctx->r2 = ADD32(0, 0XED);
    // 0x800395F8: j           L_80039630
    // 0x800395FC: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
        goto L_80039630;
    // 0x800395FC: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
L_80039600:
    // 0x80039600: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x80039604: beq         $v1, $v0, L_8003961C
    if (ctx->r3 == ctx->r2) {
        // 0x80039608: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_8003961C;
    }
    // 0x80039608: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8003960C: jal         0x80022888
    // 0x80039610: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80022888(rdram, ctx);
        goto after_2;
    // 0x80039610: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x80039614: j           L_80039628
    // 0x80039618: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_80039628;
    // 0x80039618: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_8003961C:
    // 0x8003961C: jal         0x80022888
    // 0x80039620: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80022888(rdram, ctx);
        goto after_3;
    // 0x80039620: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_3:
    // 0x80039624: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
L_80039628:
    // 0x80039628: jal         0x80046B74
    // 0x8003962C: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    func_80046B74(rdram, ctx);
        goto after_4;
    // 0x8003962C: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    after_4:
L_80039630:
    // 0x80039630: jal         0x8003AD80
    // 0x80039634: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AD80(rdram, ctx);
        goto after_5;
    // 0x80039634: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80039638: j           L_80039648
    // 0x8003963C: nop

        goto L_80039648;
    // 0x8003963C: nop

L_80039640:
    // 0x80039640: jal         0x8003A398
    // 0x80039644: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003A398(rdram, ctx);
        goto after_6;
    // 0x80039644: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
L_80039648:
    // 0x80039648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003964C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80039650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039654: jr          $ra
    // 0x80039658: nop

    return;
    // 0x80039658: nop

;}
RECOMP_FUNC void func_8003965C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003965C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039660: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80039664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039668: jal         0x8000A7DC
    // 0x8003966C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8000A7DC(rdram, ctx);
        goto after_0;
    // 0x8003966C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80039670: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x80039674: addiu       $v0, $zero, 0x53
    ctx->r2 = ADD32(0, 0X53);
    // 0x80039678: bne         $v1, $v0, L_80039690
    if (ctx->r3 != ctx->r2) {
        // 0x8003967C: nop
    
            goto L_80039690;
    }
    // 0x8003967C: nop

    // 0x80039680: jal         0x8003AD80
    // 0x80039684: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AD80(rdram, ctx);
        goto after_1;
    // 0x80039684: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80039688: j           L_800396B4
    // 0x8003968C: nop

        goto L_800396B4;
    // 0x8003968C: nop

L_80039690:
    // 0x80039690: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80039694: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80039698: lhu         $v0, 0x18($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X18);
    // 0x8003969C: addiu       $v0, $v0, -0xC8
    ctx->r2 = ADD32(ctx->r2, -0XC8);
    // 0x800396A0: sltiu       $v0, $v0, 0x11
    ctx->r2 = ctx->r2 < 0X11 ? 1 : 0;
    // 0x800396A4: beq         $v0, $zero, L_800396B4
    if (ctx->r2 == 0) {
        // 0x800396A8: nop
    
            goto L_800396B4;
    }
    // 0x800396A8: nop

    // 0x800396AC: jal         0x8003C1FC
    // 0x800396B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003C1FC(rdram, ctx);
        goto after_2;
    // 0x800396B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_800396B4:
    // 0x800396B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800396B8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800396BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800396C0: jr          $ra
    // 0x800396C4: nop

    return;
    // 0x800396C4: nop

;}
RECOMP_FUNC void func_800396C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800396C8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800396CC: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x800396D0: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800396D4: bgtz        $v0, L_800396F4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800396D8: nop
    
            goto L_800396F4;
    }
    // 0x800396D8: nop

    // 0x800396DC: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x800396E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800396E4: lw          $v0, 0x3A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A0);
    // 0x800396E8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800396EC: beql        $v0, $zero, L_800396F4
    if (ctx->r2 == 0) {
        // 0x800396F0: sw          $zero, 0x10($a0)
        MEM_W(0X10, ctx->r4) = 0;
            goto L_800396F4;
    }
    goto skip_0;
    // 0x800396F0: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    skip_0:
L_800396F4:
    // 0x800396F4: jr          $ra
    // 0x800396F8: nop

    return;
    // 0x800396F8: nop

;}
RECOMP_FUNC void func_800396FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800396FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039700: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80039704: lhu         $v0, 0xC8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC8);
    // 0x80039708: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x8003970C: bne         $v0, $zero, L_80039718
    if (ctx->r2 != 0) {
        // 0x80039710: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80039718;
    }
    // 0x80039710: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80039714: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
L_80039718:
    // 0x80039718: jal         0x80039930
    // 0x8003971C: nop

    func_80039930(rdram, ctx);
        goto after_0;
    // 0x8003971C: nop

    after_0:
    // 0x80039720: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80039724: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039728: jr          $ra
    // 0x8003972C: nop

    return;
    // 0x8003972C: nop

;}
RECOMP_FUNC void func_80039730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039730: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80039734: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_80039730 falls into func_80039738
    func_80039738(rdram, ctx);
;}
RECOMP_FUNC void func_80039738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039738: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003973C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039740: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80039744: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80039748: bltz        $v0, L_800397CC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8003974C: addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
            goto L_800397CC;
    }
    // 0x8003974C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80039750: jal         0x8000B8E8
    // 0x80039754: nop

    func_8000B8E8(rdram, ctx);
        goto after_0;
    // 0x80039754: nop

    after_0:
    // 0x80039758: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003975C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80039760: bne         $v0, $v1, L_80039784
    if (ctx->r2 != ctx->r3) {
        // 0x80039764: addiu       $v0, $zero, 0x35
        ctx->r2 = ADD32(0, 0X35);
            goto L_80039784;
    }
    // 0x80039764: addiu       $v0, $zero, 0x35
    ctx->r2 = ADD32(0, 0X35);
    // 0x80039768: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x8003976C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80039770: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80039774: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80039778: addiu       $v0, $zero, 0xED
    ctx->r2 = ADD32(0, 0XED);
    // 0x8003977C: j           L_800397C4
    // 0x80039780: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
        goto L_800397C4;
    // 0x80039780: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
L_80039784:
    // 0x80039784: lhu         $v0, 0x5A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X5A);
    // 0x80039788: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8003978C: addiu       $a1, $a1, 0x31B4
    ctx->r5 = ADD32(ctx->r5, 0X31B4);
    // 0x80039790: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80039794: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x80039798: addiu       $v0, $zero, 0x4E
    ctx->r2 = ADD32(0, 0X4E);
    // 0x8003979C: beq         $v1, $v0, L_800397B4
    if (ctx->r3 == ctx->r2) {
        // 0x800397A0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800397B4;
    }
    // 0x800397A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800397A4: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // 0x800397A8: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
    // 0x800397AC: j           L_800397C0
    // 0x800397B0: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
        goto L_800397C0;
    // 0x800397B0: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_800397B4:
    // 0x800397B4: addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
    // 0x800397B8: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
    // 0x800397BC: addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
L_800397C0:
    // 0x800397C0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_800397C4:
    // 0x800397C4: jal         0x8003AD80
    // 0x800397C8: nop

    func_8003AD80(rdram, ctx);
        goto after_1;
    // 0x800397C8: nop

    after_1:
L_800397CC:
    // 0x800397CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800397D0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800397D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800397D8: jr          $ra
    // 0x800397DC: nop

    return;
    // 0x800397DC: nop

;}
RECOMP_FUNC void func_800397E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800397E0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800397E4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_800397E0 falls into func_800397E8
    func_800397E8(rdram, ctx);
;}
RECOMP_FUNC void func_800397E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800397E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800397EC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800397F0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800397F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800397F8: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800397FC: blez        $v0, L_80039900
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80039800: addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
            goto L_80039900;
    }
    // 0x80039800: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80039804: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80039808: beq         $v0, $zero, L_80039918
    if (ctx->r2 == 0) {
        // 0x8003980C: addiu       $v0, $zero, 0x4E
        ctx->r2 = ADD32(0, 0X4E);
            goto L_80039918;
    }
    // 0x8003980C: addiu       $v0, $zero, 0x4E
    ctx->r2 = ADD32(0, 0X4E);
    // 0x80039810: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80039814: addiu       $s1, $s1, 0x31B4
    ctx->r17 = ADD32(ctx->r17, 0X31B4);
    // 0x80039818: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8003981C: beq         $v1, $v0, L_8003983C
    if (ctx->r3 == ctx->r2) {
        // 0x80039820: nop
    
            goto L_8003983C;
    }
    // 0x80039820: nop

    // 0x80039824: jal         0x8001D744
    // 0x80039828: nop

    func_8001D744(rdram, ctx);
        goto after_0;
    // 0x80039828: nop

    after_0:
    // 0x8003982C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80039830: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80039834: bne         $v1, $v0, L_800398E8
    if (ctx->r3 != ctx->r2) {
        // 0x80039838: addiu       $v0, $zero, 0x2C
        ctx->r2 = ADD32(0, 0X2C);
            goto L_800398E8;
    }
    // 0x80039838: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
L_8003983C:
    // 0x8003983C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80039840: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80039844: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
    // 0x80039848: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x8003984C: beq         $v0, $zero, L_80039864
    if (ctx->r2 == 0) {
        // 0x80039850: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80039864;
    }
    // 0x80039850: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80039854: jal         0x8003965C
    // 0x80039858: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003965C(rdram, ctx);
        goto after_1;
    // 0x80039858: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003985C: j           L_80039918
    // 0x80039860: nop

        goto L_80039918;
    // 0x80039860: nop

L_80039864:
    // 0x80039864: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x80039868: jal         0x8000A7DC
    // 0x8003986C: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    func_8000A7DC(rdram, ctx);
        goto after_2;
    // 0x8003986C: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    after_2:
    // 0x80039870: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x80039874: addiu       $v0, $zero, 0x53
    ctx->r2 = ADD32(0, 0X53);
    // 0x80039878: beq         $v1, $v0, L_800398F0
    if (ctx->r3 == ctx->r2) {
        // 0x8003987C: nop
    
            goto L_800398F0;
    }
    // 0x8003987C: nop

    // 0x80039880: jal         0x8003E2E8
    // 0x80039884: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003E2E8(rdram, ctx);
        goto after_3;
    // 0x80039884: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80039888: jal         0x80036104
    // 0x8003988C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80036104(rdram, ctx);
        goto after_4;
    // 0x8003988C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80039890: jal         0x80044AB4
    // 0x80039894: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80044AB4(rdram, ctx);
        goto after_5;
    // 0x80039894: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80039898: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003989C: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x800398A0: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800398A4: bne         $v0, $zero, L_800398C8
    if (ctx->r2 != 0) {
        // 0x800398A8: nop
    
            goto L_800398C8;
    }
    // 0x800398A8: nop

    // 0x800398AC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800398B0: lw          $v1, 0x3A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3A0);
    // 0x800398B4: beq         $v1, $zero, L_800398C8
    if (ctx->r3 == 0) {
        // 0x800398B8: lui         $v0, 0xFFE0
        ctx->r2 = S32(0XFFE0 << 16);
            goto L_800398C8;
    }
    // 0x800398B8: lui         $v0, 0xFFE0
    ctx->r2 = S32(0XFFE0 << 16);
    // 0x800398BC: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800398C0: beq         $v0, $zero, L_800398D8
    if (ctx->r2 == 0) {
        // 0x800398C4: nop
    
            goto L_800398D8;
    }
    // 0x800398C4: nop

L_800398C8:
    // 0x800398C8: jal         0x80039730
    // 0x800398CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80039730(rdram, ctx);
        goto after_6;
    // 0x800398CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x800398D0: j           L_80039918
    // 0x800398D4: nop

        goto L_80039918;
    // 0x800398D4: nop

L_800398D8:
    // 0x800398D8: jal         0x8003A398
    // 0x800398DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003A398(rdram, ctx);
        goto after_7;
    // 0x800398DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x800398E0: j           L_80039918
    // 0x800398E4: nop

        goto L_80039918;
    // 0x800398E4: nop

L_800398E8:
    // 0x800398E8: beq         $v1, $v0, L_80039918
    if (ctx->r3 == ctx->r2) {
        // 0x800398EC: nop
    
            goto L_80039918;
    }
    // 0x800398EC: nop

L_800398F0:
    // 0x800398F0: jal         0x8003AD80
    // 0x800398F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AD80(rdram, ctx);
        goto after_8;
    // 0x800398F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // 0x800398F8: j           L_80039918
    // 0x800398FC: nop

        goto L_80039918;
    // 0x800398FC: nop

L_80039900:
    // 0x80039900: beq         $v0, $zero, L_80039918
    if (ctx->r2 == 0) {
        // 0x80039904: nop
    
            goto L_80039918;
    }
    // 0x80039904: nop

    // 0x80039908: lw          $v0, 0x104($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X104);
    // 0x8003990C: bne         $v0, $zero, L_80039918
    if (ctx->r2 != 0) {
        // 0x80039910: ori         $v0, $zero, 0xA000
        ctx->r2 = 0 | 0XA000;
            goto L_80039918;
    }
    // 0x80039910: ori         $v0, $zero, 0xA000
    ctx->r2 = 0 | 0XA000;
    // 0x80039914: sw          $v0, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r2;
L_80039918:
    // 0x80039918: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8003991C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80039920: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80039924: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80039928: jr          $ra
    // 0x8003992C: nop

    return;
    // 0x8003992C: nop

;}
RECOMP_FUNC void func_80039930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039934: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80039938: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003993C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039940: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    // 0x80039944: beq         $a0, $zero, L_80039958
    if (ctx->r4 == 0) {
        // 0x80039948: nop
    
            goto L_80039958;
    }
    // 0x80039948: nop

    // 0x8003994C: jal         0x80024764
    // 0x80039950: nop

    func_80024764(rdram, ctx);
        goto after_0;
    // 0x80039950: nop

    after_0:
    // 0x80039954: sw          $zero, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = 0;
L_80039958:
    // 0x80039958: lhu         $v0, 0xCC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XCC);
    // 0x8003995C: sh          $zero, 0x1B0($s0)
    MEM_H(0X1B0, ctx->r16) = 0;
    // 0x80039960: sh          $zero, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = 0;
    // 0x80039964: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80039968: sw          $v0, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = ctx->r2;
    // 0x8003996C: lhu         $v0, 0xCC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XCC);
    // 0x80039970: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80039974: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x80039978: beq         $v0, $zero, L_800399F0
    if (ctx->r2 == 0) {
        // 0x8003997C: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_800399F0;
    }
    // 0x8003997C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80039980: lhu         $v1, 0x168($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X168);
    // 0x80039984: bne         $v1, $v0, L_800399C8
    if (ctx->r3 != ctx->r2) {
        // 0x80039988: nop
    
            goto L_800399C8;
    }
    // 0x80039988: nop

    // 0x8003998C: jal         0x8001DCBC
    // 0x80039990: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001DCBC(rdram, ctx);
        goto after_1;
    // 0x80039990: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80039994: lhu         $v0, 0x5A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X5A);
    // 0x80039998: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003999C: sw          $v0, 0x31B4($at)
    MEM_W(0X31B4, ctx->r1) = ctx->r2;
    // 0x800399A0: lhu         $v0, 0x5A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X5A);
    // 0x800399A4: xori        $v1, $v0, 0x2
    ctx->r3 = ctx->r2 ^ 0X2;
    // 0x800399A8: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800399AC: xori        $v0, $v0, 0x4E
    ctx->r2 = ctx->r2 ^ 0X4E;
    // 0x800399B0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800399B4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800399B8: beq         $v1, $zero, L_80039A00
    if (ctx->r3 == 0) {
        // 0x800399BC: nop
    
            goto L_80039A00;
    }
    // 0x800399BC: nop

    // 0x800399C0: j           L_800399F0
    // 0x800399C4: nop

        goto L_800399F0;
    // 0x800399C4: nop

L_800399C8:
    // 0x800399C8: jal         0x8001D9FC
    // 0x800399CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D9FC(rdram, ctx);
        goto after_2;
    // 0x800399CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800399D0: lhu         $v0, 0x5A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X5A);
    // 0x800399D4: xori        $v1, $v0, 0x2
    ctx->r3 = ctx->r2 ^ 0X2;
    // 0x800399D8: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800399DC: xori        $v0, $v0, 0x4E
    ctx->r2 = ctx->r2 ^ 0X4E;
    // 0x800399E0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800399E4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800399E8: beq         $v1, $zero, L_80039A00
    if (ctx->r3 == 0) {
        // 0x800399EC: nop
    
            goto L_80039A00;
    }
    // 0x800399EC: nop

L_800399F0:
    // 0x800399F0: jal         0x800397E0
    // 0x800399F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800397E0(rdram, ctx);
        goto after_3;
    // 0x800399F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800399F8: j           L_80039A08
    // 0x800399FC: nop

        goto L_80039A08;
    // 0x800399FC: nop

L_80039A00:
    // 0x80039A00: jal         0x8003AD80
    // 0x80039A04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AD80(rdram, ctx);
        goto after_4;
    // 0x80039A04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
L_80039A08:
    // 0x80039A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039A0C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80039A10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039A14: jr          $ra
    // 0x80039A18: nop

    return;
    // 0x80039A18: nop

;}
RECOMP_FUNC void func_80039A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039A1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80039A20: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80039A24: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80039A28: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80039A2C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80039A30: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80039A34: lw          $a0, 0x68($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X68);
    // 0x80039A38: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80039A3C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80039A40: lhu         $v1, 0x22($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X22);
    // 0x80039A44: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80039A48: andi        $v1, $v1, 0x10
    ctx->r3 = ctx->r3 & 0X10;
    // 0x80039A4C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80039A50: bne         $v1, $v0, L_80039A90
    if (ctx->r3 != ctx->r2) {
        // 0x80039A54: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80039A90;
    }
    // 0x80039A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80039A58: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80039A5C: lh          $v0, 0x13E6($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X13E6);
    // 0x80039A60: beq         $v0, $zero, L_80039A74
    if (ctx->r2 == 0) {
        // 0x80039A64: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80039A74;
    }
    // 0x80039A64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80039A68: jal         0x8003BA80
    // 0x80039A6C: lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    func_8003BA80(rdram, ctx);
        goto after_0;
    // 0x80039A6C: lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    after_0:
    // 0x80039A70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80039A74:
    // 0x80039A74: jal         0x800425D8
    // 0x80039A78: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800425D8(rdram, ctx);
        goto after_1;
    // 0x80039A78: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80039A7C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80039A80: jal         0x80060F30
    // 0x80039A84: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80060F30(rdram, ctx);
        goto after_2;
    // 0x80039A84: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80039A88: j           L_80039AE8
    // 0x80039A8C: nop

        goto L_80039AE8;
    // 0x80039A8C: nop

L_80039A90:
    // 0x80039A90: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80039A94: lw          $v1, 0x31A8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31A8);
    // 0x80039A98: beq         $v1, $v0, L_80039AC8
    if (ctx->r3 == ctx->r2) {
        // 0x80039A9C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80039AC8;
    }
    // 0x80039A9C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80039AA0: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x80039AA4: beq         $v1, $v0, L_80039ACC
    if (ctx->r3 == ctx->r2) {
        // 0x80039AA8: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80039ACC;
    }
    // 0x80039AA8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80039AAC: lw          $v0, 0x104($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X104);
    // 0x80039AB0: bne         $v0, $zero, L_80039ACC
    if (ctx->r2 != 0) {
        // 0x80039AB4: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80039ACC;
    }
    // 0x80039AB4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80039AB8: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x80039ABC: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x80039AC0: beq         $v0, $zero, L_80039AE0
    if (ctx->r2 == 0) {
        // 0x80039AC4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80039AE0;
    }
    // 0x80039AC4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80039AC8:
    // 0x80039AC8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80039ACC:
    // 0x80039ACC: sh          $v0, 0x5A($s1)
    MEM_H(0X5A, ctx->r17) = ctx->r2;
    // 0x80039AD0: jal         0x8003C154
    // 0x80039AD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003C154(rdram, ctx);
        goto after_3;
    // 0x80039AD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80039AD8: j           L_80039AE8
    // 0x80039ADC: nop

        goto L_80039AE8;
    // 0x80039ADC: nop

L_80039AE0:
    // 0x80039AE0: jal         0x80041118
    // 0x80039AE4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80041118(rdram, ctx);
        goto after_4;
    // 0x80039AE4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
L_80039AE8:
    // 0x80039AE8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80039AEC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80039AF0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80039AF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80039AF8: jr          $ra
    // 0x80039AFC: nop

    return;
    // 0x80039AFC: nop

;}
RECOMP_FUNC void func_80039B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039B00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80039B04: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80039B08: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80039B0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80039B10: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80039B14: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80039B18: lh          $v0, 0x120($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X120);
    // 0x80039B1C: beq         $v0, $zero, L_80039CB8
    if (ctx->r2 == 0) {
        // 0x80039B20: nop
    
            goto L_80039CB8;
    }
    // 0x80039B20: nop

    // 0x80039B24: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
    // 0x80039B28: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
L_80039B2C:
    // 0x80039B2C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80039B30: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80039B34: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80039B38: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80039B3C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80039B40: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80039B44: addiu       $v0, $v0, 0x3F94
    ctx->r2 = ADD32(ctx->r2, 0X3F94);
    // 0x80039B48: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80039B4C: beq         $s0, $s1, L_80039CA8
    if (ctx->r16 == ctx->r17) {
        // 0x80039B50: addiu       $v0, $s2, -0x1
        ctx->r2 = ADD32(ctx->r18, -0X1);
            goto L_80039CA8;
    }
    // 0x80039B50: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x80039B54: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
    // 0x80039B58: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80039B5C: beq         $v0, $zero, L_80039CA8
    if (ctx->r2 == 0) {
        // 0x80039B60: addiu       $v0, $s2, -0x1
        ctx->r2 = ADD32(ctx->r18, -0X1);
            goto L_80039CA8;
    }
    // 0x80039B60: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x80039B64: lhu         $v0, 0xDC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XDC);
    // 0x80039B68: beq         $v0, $zero, L_80039CA4
    if (ctx->r2 == 0) {
        // 0x80039B6C: addiu       $v0, $zero, 0x37
        ctx->r2 = ADD32(0, 0X37);
            goto L_80039CA4;
    }
    // 0x80039B6C: addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
    // 0x80039B70: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x80039B74: beq         $v1, $v0, L_80039CA4
    if (ctx->r3 == ctx->r2) {
        // 0x80039B78: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80039CA4;
    }
    // 0x80039B78: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80039B7C: jal         0x8003B5B4
    // 0x80039B80: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003B5B4(rdram, ctx);
        goto after_0;
    // 0x80039B80: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80039B84: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80039B88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80039B8C: sw          $v0, 0x31A8($at)
    MEM_W(0X31A8, ctx->r1) = ctx->r2;
    // 0x80039B90: beq         $v0, $zero, L_80039CA4
    if (ctx->r2 == 0) {
        // 0x80039B94: addiu       $v0, $zero, 0x4D
        ctx->r2 = ADD32(0, 0X4D);
            goto L_80039CA4;
    }
    // 0x80039B94: addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
    // 0x80039B98: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x80039B9C: bne         $v1, $v0, L_80039BB4
    if (ctx->r3 != ctx->r2) {
        // 0x80039BA0: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80039BB4;
    }
    // 0x80039BA0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80039BA4: jal         0x80039A1C
    // 0x80039BA8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80039A1C(rdram, ctx);
        goto after_1;
    // 0x80039BA8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80039BAC: j           L_80039CB8
    // 0x80039BB0: nop

        goto L_80039CB8;
    // 0x80039BB0: nop

L_80039BB4:
    // 0x80039BB4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80039BB8: lh          $v0, 0x13E6($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X13E6);
    // 0x80039BBC: beq         $v0, $zero, L_80039BCC
    if (ctx->r2 == 0) {
        // 0x80039BC0: lui         $a0, 0x3
        ctx->r4 = S32(0X3 << 16);
            goto L_80039BCC;
    }
    // 0x80039BC0: lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // 0x80039BC4: jal         0x8003BA80
    // 0x80039BC8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003BA80(rdram, ctx);
        goto after_2;
    // 0x80039BC8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
L_80039BCC:
    // 0x80039BCC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80039BD0: jal         0x80060F30
    // 0x80039BD4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80060F30(rdram, ctx);
        goto after_3;
    // 0x80039BD4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x80039BD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80039BDC: jal         0x800425D8
    // 0x80039BE0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_800425D8(rdram, ctx);
        goto after_4;
    // 0x80039BE0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // 0x80039BE4: lhu         $v0, 0x1B0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B0);
    // 0x80039BE8: bne         $v0, $zero, L_80039C00
    if (ctx->r2 != 0) {
        // 0x80039BEC: addiu       $v0, $zero, 0xE1
        ctx->r2 = ADD32(0, 0XE1);
            goto L_80039C00;
    }
    // 0x80039BEC: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x80039BF0: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    // 0x80039BF4: lh          $v1, 0x18($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X18);
    // 0x80039BF8: beq         $v1, $v0, L_80039C30
    if (ctx->r3 == ctx->r2) {
        // 0x80039BFC: nop
    
            goto L_80039C30;
    }
    // 0x80039BFC: nop

L_80039C00:
    // 0x80039C00: lw          $a1, 0x68($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X68);
    // 0x80039C04: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80039C08: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x80039C0C: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x80039C10: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80039C14: lui         $v1, 0xFFFE
    ctx->r3 = S32(0XFFFE << 16);
    // 0x80039C18: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80039C1C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80039C20: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80039C24: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80039C28: j           L_80039C90
    // 0x80039C2C: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
        goto L_80039C90;
    // 0x80039C2C: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
L_80039C30:
    // 0x80039C30: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80039C34: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80039C38: lhu         $v1, 0x22($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X22);
    // 0x80039C3C: lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X22);
    // 0x80039C40: andi        $v1, $v1, 0x10
    ctx->r3 = ctx->r3 & 0X10;
    // 0x80039C44: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80039C48: bne         $v1, $v0, L_80039C68
    if (ctx->r3 != ctx->r2) {
        // 0x80039C4C: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80039C68;
    }
    // 0x80039C4C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80039C50: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // 0x80039C54: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x80039C58: jal         0x8003C154
    // 0x80039C5C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8003C154(rdram, ctx);
        goto after_5;
    // 0x80039C5C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // 0x80039C60: j           L_80039CB8
    // 0x80039C64: nop

        goto L_80039CB8;
    // 0x80039C64: nop

L_80039C68:
    // 0x80039C68: lw          $a1, 0x68($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X68);
    // 0x80039C6C: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x80039C70: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x80039C74: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80039C78: lui         $v1, 0xFFFC
    ctx->r3 = S32(0XFFFC << 16);
    // 0x80039C7C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80039C80: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80039C84: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80039C88: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80039C8C: lui         $v1, 0x4
    ctx->r3 = S32(0X4 << 16);
L_80039C90:
    // 0x80039C90: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80039C94: jal         0x8003C154
    // 0x80039C98: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    func_8003C154(rdram, ctx);
        goto after_6;
    // 0x80039C98: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    after_6:
    // 0x80039C9C: j           L_80039CB8
    // 0x80039CA0: nop

        goto L_80039CB8;
    // 0x80039CA0: nop

L_80039CA4:
    // 0x80039CA4: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
L_80039CA8:
    // 0x80039CA8: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80039CAC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80039CB0: bne         $v0, $zero, L_80039B2C
    if (ctx->r2 != 0) {
        // 0x80039CB4: andi        $v0, $s2, 0xFFFF
        ctx->r2 = ctx->r18 & 0XFFFF;
            goto L_80039B2C;
    }
    // 0x80039CB4: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
L_80039CB8:
    // 0x80039CB8: lhu         $v0, 0x18A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18A);
    // 0x80039CBC: bne         $v0, $zero, L_80039D10
    if (ctx->r2 != 0) {
        // 0x80039CC0: nop
    
            goto L_80039D10;
    }
    // 0x80039CC0: nop

    // 0x80039CC4: jal         0x80009474
    // 0x80039CC8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80009474(rdram, ctx);
        goto after_7;
    // 0x80039CC8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_7:
    // 0x80039CCC: lhu         $v0, 0x18A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18A);
    // 0x80039CD0: bne         $v0, $zero, L_80039D10
    if (ctx->r2 != 0) {
        // 0x80039CD4: nop
    
            goto L_80039D10;
    }
    // 0x80039CD4: nop

    // 0x80039CD8: jal         0x800296B4
    // 0x80039CDC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800296B4(rdram, ctx);
        goto after_8;
    // 0x80039CDC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_8:
    // 0x80039CE0: lhu         $v0, 0x18A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18A);
    // 0x80039CE4: bne         $v0, $zero, L_80039D10
    if (ctx->r2 != 0) {
        // 0x80039CE8: nop
    
            goto L_80039D10;
    }
    // 0x80039CE8: nop

    // 0x80039CEC: jal         0x800449C0
    // 0x80039CF0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800449C0(rdram, ctx);
        goto after_9;
    // 0x80039CF0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_9:
    // 0x80039CF4: lhu         $v0, 0x18A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18A);
    // 0x80039CF8: bne         $v0, $zero, L_80039D10
    if (ctx->r2 != 0) {
        // 0x80039CFC: nop
    
            goto L_80039D10;
    }
    // 0x80039CFC: nop

    // 0x80039D00: jal         0x8003E4C0
    // 0x80039D04: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8003E4C0(rdram, ctx);
        goto after_10;
    // 0x80039D04: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // 0x80039D08: jal         0x800361CC
    // 0x80039D0C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800361CC(rdram, ctx);
        goto after_11;
    // 0x80039D0C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_11:
L_80039D10:
    // 0x80039D10: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80039D14: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80039D18: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
    // 0x80039D1C: slti        $v0, $v0, 0xD1
    ctx->r2 = SIGNED(ctx->r2) < 0XD1 ? 1 : 0;
    // 0x80039D20: bne         $v0, $zero, L_80039D40
    if (ctx->r2 != 0) {
        // 0x80039D24: nop
    
            goto L_80039D40;
    }
    // 0x80039D24: nop

    // 0x80039D28: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x80039D2C: bltz        $v0, L_80039D40
    if (SIGNED(ctx->r2) < 0) {
        // 0x80039D30: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80039D40;
    }
    // 0x80039D30: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80039D34: sh          $v0, 0x5A($s1)
    MEM_H(0X5A, ctx->r17) = ctx->r2;
    // 0x80039D38: jal         0x80048420
    // 0x80039D3C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80048420(rdram, ctx);
        goto after_12;
    // 0x80039D3C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_12:
L_80039D40:
    // 0x80039D40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80039D44: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80039D48: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80039D4C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80039D50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80039D54: jr          $ra
    // 0x80039D58: nop

    return;
    // 0x80039D58: nop

;}
RECOMP_FUNC void func_80039D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039D5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039D60: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80039D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039D68: jal         0x80038B84
    // 0x80039D6C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80038B84(rdram, ctx);
        goto after_0;
    // 0x80039D6C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80039D70: jal         0x8003AD80
    // 0x80039D74: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AD80(rdram, ctx);
        goto after_1;
    // 0x80039D74: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80039D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039D7C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80039D80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039D84: jr          $ra
    // 0x80039D88: nop

    return;
    // 0x80039D88: nop

;}
RECOMP_FUNC void func_80039D8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039D8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039D90: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80039D94: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80039D98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039D9C: lh          $v0, 0x122($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X122);
    // 0x80039DA0: beq         $v0, $zero, L_80039E38
    if (ctx->r2 == 0) {
        // 0x80039DA4: nop
    
            goto L_80039E38;
    }
    // 0x80039DA4: nop

    // 0x80039DA8: lhu         $v0, 0xDE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XDE);
    // 0x80039DAC: beq         $v0, $zero, L_80039E38
    if (ctx->r2 == 0) {
        // 0x80039DB0: nop
    
            goto L_80039E38;
    }
    // 0x80039DB0: nop

    // 0x80039DB4: lhu         $v0, 0x18A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18A);
    // 0x80039DB8: bne         $v0, $zero, L_80039E38
    if (ctx->r2 != 0) {
        // 0x80039DBC: nop
    
            goto L_80039E38;
    }
    // 0x80039DBC: nop

    // 0x80039DC0: jal         0x80009474
    // 0x80039DC4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80009474(rdram, ctx);
        goto after_0;
    // 0x80039DC4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80039DC8: lhu         $v0, 0x18A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18A);
    // 0x80039DCC: bne         $v0, $zero, L_80039E38
    if (ctx->r2 != 0) {
        // 0x80039DD0: nop
    
            goto L_80039E38;
    }
    // 0x80039DD0: nop

    // 0x80039DD4: jal         0x800296B4
    // 0x80039DD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800296B4(rdram, ctx);
        goto after_1;
    // 0x80039DD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80039DDC: lhu         $v0, 0x18A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18A);
    // 0x80039DE0: bne         $v0, $zero, L_80039E38
    if (ctx->r2 != 0) {
        // 0x80039DE4: nop
    
            goto L_80039E38;
    }
    // 0x80039DE4: nop

    // 0x80039DE8: jal         0x80045450
    // 0x80039DEC: nop

    func_80045450(rdram, ctx);
        goto after_2;
    // 0x80039DEC: nop

    after_2:
    // 0x80039DF0: lhu         $v0, 0x18A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18A);
    // 0x80039DF4: bne         $v0, $zero, L_80039E4C
    if (ctx->r2 != 0) {
        // 0x80039DF8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80039E4C;
    }
    // 0x80039DF8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80039DFC: jal         0x80044C44
    // 0x80039E00: nop

    func_80044C44(rdram, ctx);
        goto after_3;
    // 0x80039E00: nop

    after_3:
    // 0x80039E04: lhu         $v0, 0x18A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18A);
    // 0x80039E08: bne         $v0, $zero, L_80039E4C
    if (ctx->r2 != 0) {
        // 0x80039E0C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80039E4C;
    }
    // 0x80039E0C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80039E10: jal         0x8003EA34
    // 0x80039E14: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003EA34(rdram, ctx);
        goto after_4;
    // 0x80039E14: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80039E18: lhu         $v0, 0x18A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18A);
    // 0x80039E1C: bne         $v0, $zero, L_80039E4C
    if (ctx->r2 != 0) {
        // 0x80039E20: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80039E4C;
    }
    // 0x80039E20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80039E24: jal         0x80036384
    // 0x80039E28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80036384(rdram, ctx);
        goto after_5;
    // 0x80039E28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80039E2C: lhu         $v0, 0x18A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18A);
    // 0x80039E30: bne         $v0, $zero, L_80039E4C
    if (ctx->r2 != 0) {
        // 0x80039E34: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80039E4C;
    }
    // 0x80039E34: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80039E38:
    // 0x80039E38: jal         0x80039E68
    // 0x80039E3C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80039E68(rdram, ctx);
        goto after_6;
    // 0x80039E3C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x80039E40: lhu         $v0, 0x18A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18A);
    // 0x80039E44: beq         $v0, $zero, L_80039E54
    if (ctx->r2 == 0) {
        // 0x80039E48: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80039E54;
    }
    // 0x80039E48: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80039E4C:
    // 0x80039E4C: jal         0x80060F30
    // 0x80039E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80060F30(rdram, ctx);
        goto after_7;
    // 0x80039E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
L_80039E54:
    // 0x80039E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039E58: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80039E5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039E60: jr          $ra
    // 0x80039E64: nop

    return;
    // 0x80039E64: nop

;}
RECOMP_FUNC void func_80039E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039E68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039E6C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80039E70: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80039E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039E78: sh          $zero, 0x1B0($s0)
    MEM_H(0X1B0, ctx->r16) = 0;
    // 0x80039E7C: sh          $zero, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = 0;
    // 0x80039E80: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80039E84: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80039E88: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x80039E8C: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x80039E90: bne         $v0, $zero, L_80039F18
    if (ctx->r2 != 0) {
        // 0x80039E94: addiu       $v1, $zero, 0xE1
        ctx->r3 = ADD32(0, 0XE1);
            goto L_80039F18;
    }
    // 0x80039E94: addiu       $v1, $zero, 0xE1
    ctx->r3 = ADD32(0, 0XE1);
    // 0x80039E98: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80039E9C: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x80039EA0: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80039EA4: bne         $v0, $zero, L_80039EC8
    if (ctx->r2 != 0) {
        // 0x80039EA8: sh          $v1, 0x18($a0)
        MEM_H(0X18, ctx->r4) = ctx->r3;
            goto L_80039EC8;
    }
    // 0x80039EA8: sh          $v1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r3;
    // 0x80039EAC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80039EB0: lw          $v1, 0x3A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3A0);
    // 0x80039EB4: beq         $v1, $zero, L_80039EC8
    if (ctx->r3 == 0) {
        // 0x80039EB8: lui         $v0, 0xFFF0
        ctx->r2 = S32(0XFFF0 << 16);
            goto L_80039EC8;
    }
    // 0x80039EB8: lui         $v0, 0xFFF0
    ctx->r2 = S32(0XFFF0 << 16);
    // 0x80039EBC: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80039EC0: beq         $v0, $zero, L_80039F10
    if (ctx->r2 == 0) {
        // 0x80039EC4: nop
    
            goto L_80039F10;
    }
    // 0x80039EC4: nop

L_80039EC8:
    // 0x80039EC8: jal         0x8000B8E8
    // 0x80039ECC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000B8E8(rdram, ctx);
        goto after_0;
    // 0x80039ECC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80039ED0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80039ED4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80039ED8: bne         $v0, $v1, L_80039EFC
    if (ctx->r2 != ctx->r3) {
        // 0x80039EDC: addiu       $v0, $zero, 0x19
        ctx->r2 = ADD32(0, 0X19);
            goto L_80039EFC;
    }
    // 0x80039EDC: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // 0x80039EE0: addiu       $v0, $zero, 0x35
    ctx->r2 = ADD32(0, 0X35);
    // 0x80039EE4: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x80039EE8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80039EEC: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80039EF0: addiu       $v0, $zero, 0xED
    ctx->r2 = ADD32(0, 0XED);
    // 0x80039EF4: j           L_80039F00
    // 0x80039EF8: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
        goto L_80039F00;
    // 0x80039EF8: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
L_80039EFC:
    // 0x80039EFC: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
L_80039F00:
    // 0x80039F00: jal         0x8003AD80
    // 0x80039F04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AD80(rdram, ctx);
        goto after_1;
    // 0x80039F04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80039F08: j           L_80039F18
    // 0x80039F0C: nop

        goto L_80039F18;
    // 0x80039F0C: nop

L_80039F10:
    // 0x80039F10: jal         0x8003A398
    // 0x80039F14: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003A398(rdram, ctx);
        goto after_2;
    // 0x80039F14: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_80039F18:
    // 0x80039F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039F1C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80039F20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039F24: jr          $ra
    // 0x80039F28: nop

    return;
    // 0x80039F28: nop

;}
RECOMP_FUNC void func_80039F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039F2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039F30: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80039F34: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80039F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039F3C: sh          $zero, 0x1B0($s0)
    MEM_H(0X1B0, ctx->r16) = 0;
    // 0x80039F40: sh          $zero, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = 0;
    // 0x80039F44: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80039F48: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x80039F4C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80039F50: blez        $v0, L_80039FCC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80039F54: nop
    
            goto L_80039FCC;
    }
    // 0x80039F54: nop

    // 0x80039F58: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x80039F5C: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x80039F60: bne         $v0, $zero, L_80039FCC
    if (ctx->r2 != 0) {
        // 0x80039F64: addiu       $v1, $zero, 0xE1
        ctx->r3 = ADD32(0, 0XE1);
            goto L_80039FCC;
    }
    // 0x80039F64: addiu       $v1, $zero, 0xE1
    ctx->r3 = ADD32(0, 0XE1);
    // 0x80039F68: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80039F6C: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x80039F70: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80039F74: bne         $v0, $zero, L_80039F98
    if (ctx->r2 != 0) {
        // 0x80039F78: sh          $v1, 0x18($a0)
        MEM_H(0X18, ctx->r4) = ctx->r3;
            goto L_80039F98;
    }
    // 0x80039F78: sh          $v1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r3;
    // 0x80039F7C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80039F80: lw          $v1, 0x3A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3A0);
    // 0x80039F84: beq         $v1, $zero, L_80039F98
    if (ctx->r3 == 0) {
        // 0x80039F88: lui         $v0, 0xFFF0
        ctx->r2 = S32(0XFFF0 << 16);
            goto L_80039F98;
    }
    // 0x80039F88: lui         $v0, 0xFFF0
    ctx->r2 = S32(0XFFF0 << 16);
    // 0x80039F8C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80039F90: beq         $v0, $zero, L_80039FCC
    if (ctx->r2 == 0) {
        // 0x80039F94: nop
    
            goto L_80039FCC;
    }
    // 0x80039F94: nop

L_80039F98:
    // 0x80039F98: jal         0x8000B8E8
    // 0x80039F9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000B8E8(rdram, ctx);
        goto after_0;
    // 0x80039F9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80039FA0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80039FA4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80039FA8: bne         $v0, $v1, L_80039FCC
    if (ctx->r2 != ctx->r3) {
        // 0x80039FAC: addiu       $v0, $zero, 0x35
        ctx->r2 = ADD32(0, 0X35);
            goto L_80039FCC;
    }
    // 0x80039FAC: addiu       $v0, $zero, 0x35
    ctx->r2 = ADD32(0, 0X35);
    // 0x80039FB0: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x80039FB4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80039FB8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x80039FBC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80039FC0: addiu       $v0, $zero, 0xED
    ctx->r2 = ADD32(0, 0XED);
    // 0x80039FC4: jal         0x8003AD80
    // 0x80039FC8: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    func_8003AD80(rdram, ctx);
        goto after_1;
    // 0x80039FC8: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    after_1:
L_80039FCC:
    // 0x80039FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039FD0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80039FD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039FD8: jr          $ra
    // 0x80039FDC: nop

    return;
    // 0x80039FDC: nop

;}
RECOMP_FUNC void func_80039FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039FE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039FE4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80039FE8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80039FEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039FF0: sh          $zero, 0x1B0($s0)
    MEM_H(0X1B0, ctx->r16) = 0;
    // 0x80039FF4: sh          $zero, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = 0;
    // 0x80039FF8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80039FFC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003A000: lh          $v0, 0x18($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X18);
    // 0x8003A004: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x8003A008: bne         $v0, $zero, L_8003A0A0
    if (ctx->r2 != 0) {
        // 0x8003A00C: nop
    
            goto L_8003A0A0;
    }
    // 0x8003A00C: nop

    // 0x8003A010: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003A014: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x8003A018: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8003A01C: bne         $v0, $zero, L_8003A040
    if (ctx->r2 != 0) {
        // 0x8003A020: nop
    
            goto L_8003A040;
    }
    // 0x8003A020: nop

    // 0x8003A024: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8003A028: lw          $v1, 0x3A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3A0);
    // 0x8003A02C: beq         $v1, $zero, L_8003A040
    if (ctx->r3 == 0) {
        // 0x8003A030: lui         $v0, 0xFFF0
        ctx->r2 = S32(0XFFF0 << 16);
            goto L_8003A040;
    }
    // 0x8003A030: lui         $v0, 0xFFF0
    ctx->r2 = S32(0XFFF0 << 16);
    // 0x8003A034: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8003A038: beq         $v0, $zero, L_8003A088
    if (ctx->r2 == 0) {
        // 0x8003A03C: nop
    
            goto L_8003A088;
    }
    // 0x8003A03C: nop

L_8003A040:
    // 0x8003A040: jal         0x8000B8E8
    // 0x8003A044: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000B8E8(rdram, ctx);
        goto after_0;
    // 0x8003A044: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8003A048: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003A04C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003A050: bne         $v0, $v1, L_8003A078
    if (ctx->r2 != ctx->r3) {
        // 0x8003A054: nop
    
            goto L_8003A078;
    }
    // 0x8003A054: nop

    // 0x8003A058: jal         0x8003A0CC
    // 0x8003A05C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003A0CC(rdram, ctx);
        goto after_1;
    // 0x8003A05C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003A060: addiu       $v0, $zero, 0x35
    ctx->r2 = ADD32(0, 0X35);
    // 0x8003A064: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x8003A068: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003A06C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003A070: addiu       $v0, $zero, 0xED
    ctx->r2 = ADD32(0, 0XED);
    // 0x8003A074: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
L_8003A078:
    // 0x8003A078: jal         0x8003AD80
    // 0x8003A07C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AD80(rdram, ctx);
        goto after_2;
    // 0x8003A07C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8003A080: j           L_8003A0B0
    // 0x8003A084: nop

        goto L_8003A0B0;
    // 0x8003A084: nop

L_8003A088:
    // 0x8003A088: jal         0x8003A0CC
    // 0x8003A08C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003A0CC(rdram, ctx);
        goto after_3;
    // 0x8003A08C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8003A090: jal         0x8003A398
    // 0x8003A094: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003A398(rdram, ctx);
        goto after_4;
    // 0x8003A094: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8003A098: j           L_8003A0B0
    // 0x8003A09C: nop

        goto L_8003A0B0;
    // 0x8003A09C: nop

L_8003A0A0:
    // 0x8003A0A0: lw          $v0, 0x104($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X104);
    // 0x8003A0A4: bne         $v0, $zero, L_8003A0B0
    if (ctx->r2 != 0) {
        // 0x8003A0A8: addiu       $v0, $zero, 0x4000
        ctx->r2 = ADD32(0, 0X4000);
            goto L_8003A0B0;
    }
    // 0x8003A0A8: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x8003A0AC: sw          $v0, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r2;
L_8003A0B0:
    // 0x8003A0B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A0B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003A0B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A0BC: jr          $ra
    // 0x8003A0C0: nop

    return;
    // 0x8003A0C0: nop

;}
RECOMP_FUNC void func_8003A0C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A0C4: jr          $ra
    // 0x8003A0C8: nop

    return;
    // 0x8003A0C8: nop

;}
RECOMP_FUNC void func_8003A0CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A0CC: jr          $ra
    // 0x8003A0D0: nop

    return;
    // 0x8003A0D0: nop

;}
RECOMP_FUNC void func_8003A0D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A0D4: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // 0x8003A0D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003A0DC: sw          $v0, 0x31B4($at)
    MEM_W(0X31B4, ctx->r1) = ctx->r2;
    // 0x8003A0E0: lhu         $v1, 0xCC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XCC);
    // 0x8003A0E4: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // 0x8003A0E8: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
    // 0x8003A0EC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8003A0F0: sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x8003A0F4: beq         $v0, $zero, L_8003A120
    if (ctx->r2 == 0) {
        // 0x8003A0F8: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8003A120;
    }
    // 0x8003A0F8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8003A0FC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8003A100: addu        $at, $at, $v0
    gpr jr_addend_8003A108 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003A104: lw          $v0, 0x4040($at)
    ctx->r2 = ADD32(ctx->r1, 0X4040);
    // 0x8003A108: jr          $v0
    // 0x8003A10C: nop

    switch (jr_addend_8003A108 >> 2) {
        case 0: goto L_8003A118; break;
        case 1: goto L_8003A118; break;
        case 2: goto L_8003A120; break;
        case 3: goto L_8003A110; break;
        case 4: goto L_8003A110; break;
        case 5: goto L_8003A110; break;
        case 6: goto L_8003A120; break;
        case 7: goto L_8003A118; break;
        default: switch_error(__func__, 0x8003A108, 0x80094040);
    }
    // 0x8003A10C: nop

L_8003A110:
    // 0x8003A110: j           L_8003A124
    // 0x8003A114: lui         $v1, 0xFFF7
    ctx->r3 = S32(0XFFF7 << 16);
        goto L_8003A124;
    // 0x8003A114: lui         $v1, 0xFFF7
    ctx->r3 = S32(0XFFF7 << 16);
L_8003A118:
    // 0x8003A118: j           L_8003A124
    // 0x8003A11C: lui         $v1, 0xFFFB
    ctx->r3 = S32(0XFFFB << 16);
        goto L_8003A124;
    // 0x8003A11C: lui         $v1, 0xFFFB
    ctx->r3 = S32(0XFFFB << 16);
L_8003A120:
    // 0x8003A120: lui         $v1, 0xFFF9
    ctx->r3 = S32(0XFFF9 << 16);
L_8003A124:
    // 0x8003A124: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003A128: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003A12C: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x8003A130: jr          $ra
    // 0x8003A134: sw          $zero, 0x104($a0)
    MEM_W(0X104, ctx->r4) = 0;
    return;
    // 0x8003A134: sw          $zero, 0x104($a0)
    MEM_W(0X104, ctx->r4) = 0;
;}
RECOMP_FUNC void func_8003A138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A13C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003A140: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003A144: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8003A148: lhu         $v0, 0x19E($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X19E);
    // 0x8003A14C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8003A150: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003A154: addiu       $v1, $v1, 0x31C4
    ctx->r3 = ADD32(ctx->r3, 0X31C4);
    // 0x8003A158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A15C: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8003A160: bne         $v0, $zero, L_8003A178
    if (ctx->r2 != 0) {
        // 0x8003A164: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_8003A178;
    }
    // 0x8003A164: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8003A168: jal         0x8003A478
    // 0x8003A16C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003A478(rdram, ctx);
        goto after_0;
    // 0x8003A16C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8003A170: j           L_8003A220
    // 0x8003A174: nop

        goto L_8003A220;
    // 0x8003A174: nop

L_8003A178:
    // 0x8003A178: lhu         $v0, 0xCC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XCC);
    // 0x8003A17C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8003A180: lhu         $v1, 0xCC($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XCC);
    // 0x8003A184: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x8003A188: bne         $v0, $zero, L_8003A1A8
    if (ctx->r2 != 0) {
        // 0x8003A18C: sltiu       $v0, $v1, 0x5
        ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
            goto L_8003A1A8;
    }
    // 0x8003A18C: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8003A190: beq         $v0, $zero, L_8003A1A0
    if (ctx->r2 == 0) {
        // 0x8003A194: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8003A1A0;
    }
    // 0x8003A194: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8003A198: j           L_8003A1A8
    // 0x8003A19C: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
        goto L_8003A1A8;
    // 0x8003A19C: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
L_8003A1A0:
    // 0x8003A1A0: bnel        $v1, $v0, L_8003A1A8
    if (ctx->r3 != ctx->r2) {
        // 0x8003A1A4: addiu       $a0, $zero, -0x8000
        ctx->r4 = ADD32(0, -0X8000);
            goto L_8003A1A8;
    }
    goto skip_0;
    // 0x8003A1A4: addiu       $a0, $zero, -0x8000
    ctx->r4 = ADD32(0, -0X8000);
    skip_0:
L_8003A1A8:
    // 0x8003A1A8: lhu         $v1, 0xCC($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XCC);
    // 0x8003A1AC: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x8003A1B0: sw          $a0, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->r4;
    // 0x8003A1B4: sw          $v0, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r2;
    // 0x8003A1B8: sh          $zero, 0x1B0($s0)
    MEM_H(0X1B0, ctx->r16) = 0;
    // 0x8003A1BC: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8003A1C0: sltiu       $v1, $v1, 0x3
    ctx->r3 = ctx->r3 < 0X3 ? 1 : 0;
    // 0x8003A1C4: beq         $v1, $zero, L_8003A1F4
    if (ctx->r3 == 0) {
        // 0x8003A1C8: sh          $zero, 0x1B2($s0)
        MEM_H(0X1B2, ctx->r16) = 0;
            goto L_8003A1F4;
    }
    // 0x8003A1C8: sh          $zero, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = 0;
    // 0x8003A1CC: jal         0x8001DEEC
    // 0x8003A1D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001DEEC(rdram, ctx);
        goto after_1;
    // 0x8003A1D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003A1D4: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x8003A1D8: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // 0x8003A1DC: beq         $v1, $v0, L_8003A1F4
    if (ctx->r3 == ctx->r2) {
        // 0x8003A1E0: nop
    
            goto L_8003A1F4;
    }
    // 0x8003A1E0: nop

    // 0x8003A1E4: jal         0x8003AD80
    // 0x8003A1E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AD80(rdram, ctx);
        goto after_2;
    // 0x8003A1E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8003A1EC: j           L_8003A220
    // 0x8003A1F0: nop

        goto L_8003A220;
    // 0x8003A1F0: nop

L_8003A1F4:
    // 0x8003A1F4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003A1F8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003A1FC: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8003A200: blez        $v0, L_8003A218
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003A204: nop
    
            goto L_8003A218;
    }
    // 0x8003A204: nop

    // 0x8003A208: jal         0x8003A2AC
    // 0x8003A20C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003A2AC(rdram, ctx);
        goto after_3;
    // 0x8003A20C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8003A210: j           L_8003A220
    // 0x8003A214: nop

        goto L_8003A220;
    // 0x8003A214: nop

L_8003A218:
    // 0x8003A218: jal         0x800396C8
    // 0x8003A21C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800396C8(rdram, ctx);
        goto after_4;
    // 0x8003A21C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
L_8003A220:
    // 0x8003A220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A224: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003A228: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A22C: jr          $ra
    // 0x8003A230: nop

    return;
    // 0x8003A230: nop

;}
RECOMP_FUNC void func_8003A234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A234: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A238: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003A23C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A240: jal         0x8000B8E8
    // 0x8003A244: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8000B8E8(rdram, ctx);
        goto after_0;
    // 0x8003A244: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8003A248: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003A24C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003A250: bne         $v0, $v1, L_8003A27C
    if (ctx->r2 != ctx->r3) {
        // 0x8003A254: addiu       $v0, $zero, 0x35
        ctx->r2 = ADD32(0, 0X35);
            goto L_8003A27C;
    }
    // 0x8003A254: addiu       $v0, $zero, 0x35
    ctx->r2 = ADD32(0, 0X35);
    // 0x8003A258: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x8003A25C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003A260: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003A264: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003A268: addiu       $v0, $zero, 0xED
    ctx->r2 = ADD32(0, 0XED);
    // 0x8003A26C: jal         0x8003AD80
    // 0x8003A270: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    func_8003AD80(rdram, ctx);
        goto after_1;
    // 0x8003A270: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    after_1:
    // 0x8003A274: j           L_8003A298
    // 0x8003A278: nop

        goto L_8003A298;
    // 0x8003A278: nop

L_8003A27C:
    // 0x8003A27C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8003A280: lhu         $v0, 0x19E($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X19E);
    // 0x8003A284: sltiu       $v0, $v0, 0x7
    ctx->r2 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x8003A288: bne         $v0, $zero, L_8003A294
    if (ctx->r2 != 0) {
        // 0x8003A28C: addiu       $v1, $zero, 0x19
        ctx->r3 = ADD32(0, 0X19);
            goto L_8003A294;
    }
    // 0x8003A28C: addiu       $v1, $zero, 0x19
    ctx->r3 = ADD32(0, 0X19);
    // 0x8003A290: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
L_8003A294:
    // 0x8003A294: sh          $v1, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r3;
L_8003A298:
    // 0x8003A298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A29C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003A2A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A2A4: jr          $ra
    // 0x8003A2A8: nop

    return;
    // 0x8003A2A8: nop

;}
RECOMP_FUNC void func_8003A2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A2AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A2B0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003A2B4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003A2B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A2BC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8003A2C0: beq         $v0, $zero, L_8003A2F0
    if (ctx->r2 == 0) {
        // 0x8003A2C4: nop
    
            goto L_8003A2F0;
    }
    // 0x8003A2C4: nop

    // 0x8003A2C8: jal         0x8001D744
    // 0x8003A2CC: nop

    func_8001D744(rdram, ctx);
        goto after_0;
    // 0x8003A2CC: nop

    after_0:
    // 0x8003A2D0: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x8003A2D4: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // 0x8003A2D8: beq         $v1, $v0, L_8003A2F0
    if (ctx->r3 == ctx->r2) {
        // 0x8003A2DC: nop
    
            goto L_8003A2F0;
    }
    // 0x8003A2DC: nop

    // 0x8003A2E0: jal         0x8003AD80
    // 0x8003A2E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AD80(rdram, ctx);
        goto after_1;
    // 0x8003A2E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003A2E8: j           L_8003A384
    // 0x8003A2EC: nop

        goto L_8003A384;
    // 0x8003A2EC: nop

L_8003A2F0:
    // 0x8003A2F0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003A2F4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003A2F8: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
    // 0x8003A2FC: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x8003A300: beq         $v0, $zero, L_8003A318
    if (ctx->r2 == 0) {
        // 0x8003A304: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8003A318;
    }
    // 0x8003A304: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003A308: jal         0x8003965C
    // 0x8003A30C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003965C(rdram, ctx);
        goto after_2;
    // 0x8003A30C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8003A310: j           L_8003A384
    // 0x8003A314: nop

        goto L_8003A384;
    // 0x8003A314: nop

L_8003A318:
    // 0x8003A318: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x8003A31C: jal         0x8000A7DC
    // 0x8003A320: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    func_8000A7DC(rdram, ctx);
        goto after_3;
    // 0x8003A320: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    after_3:
    // 0x8003A324: jal         0x8003E2E8
    // 0x8003A328: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003E2E8(rdram, ctx);
        goto after_4;
    // 0x8003A328: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8003A32C: jal         0x80036104
    // 0x8003A330: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80036104(rdram, ctx);
        goto after_5;
    // 0x8003A330: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x8003A334: jal         0x80044AB4
    // 0x8003A338: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80044AB4(rdram, ctx);
        goto after_6;
    // 0x8003A338: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8003A33C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003A340: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x8003A344: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8003A348: bne         $v0, $zero, L_8003A36C
    if (ctx->r2 != 0) {
        // 0x8003A34C: nop
    
            goto L_8003A36C;
    }
    // 0x8003A34C: nop

    // 0x8003A350: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8003A354: lw          $v1, 0x3A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3A0);
    // 0x8003A358: beq         $v1, $zero, L_8003A36C
    if (ctx->r3 == 0) {
        // 0x8003A35C: lui         $v0, 0xFFE0
        ctx->r2 = S32(0XFFE0 << 16);
            goto L_8003A36C;
    }
    // 0x8003A35C: lui         $v0, 0xFFE0
    ctx->r2 = S32(0XFFE0 << 16);
    // 0x8003A360: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8003A364: beq         $v0, $zero, L_8003A37C
    if (ctx->r2 == 0) {
        // 0x8003A368: nop
    
            goto L_8003A37C;
    }
    // 0x8003A368: nop

L_8003A36C:
    // 0x8003A36C: jal         0x8003A234
    // 0x8003A370: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003A234(rdram, ctx);
        goto after_7;
    // 0x8003A370: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x8003A374: j           L_8003A384
    // 0x8003A378: nop

        goto L_8003A384;
    // 0x8003A378: nop

L_8003A37C:
    // 0x8003A37C: jal         0x8003A398
    // 0x8003A380: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003A398(rdram, ctx);
        goto after_8;
    // 0x8003A380: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
L_8003A384:
    // 0x8003A384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A388: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003A38C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A390: jr          $ra
    // 0x8003A394: nop

    return;
    // 0x8003A394: nop

;}
RECOMP_FUNC void func_8003A398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A39C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003A3A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A3A4: jal         0x8002656C
    // 0x8003A3A8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8002656C(rdram, ctx);
        goto after_0;
    // 0x8003A3A8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8003A3AC: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8003A3B0: beq         $v0, $zero, L_8003A3CC
    if (ctx->r2 == 0) {
        // 0x8003A3B4: nop
    
            goto L_8003A3CC;
    }
    // 0x8003A3B4: nop

    // 0x8003A3B8: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x8003A3BC: sw          $zero, 0x100($s0)
    MEM_W(0X100, ctx->r16) = 0;
    // 0x8003A3C0: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8003A3C4: j           L_8003A464
    // 0x8003A3C8: sh          $zero, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = 0;
        goto L_8003A464;
    // 0x8003A3C8: sh          $zero, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = 0;
L_8003A3CC:
    // 0x8003A3CC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003A3D0: lh          $v0, 0x3EFA($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X3EFA);
    // 0x8003A3D4: slti        $v0, $v0, 0x89
    ctx->r2 = SIGNED(ctx->r2) < 0X89 ? 1 : 0;
    // 0x8003A3D8: beq         $v0, $zero, L_8003A3F0
    if (ctx->r2 == 0) {
        // 0x8003A3DC: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8003A3F0;
    }
    // 0x8003A3DC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8003A3E0: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x8003A3E4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003A3E8: bne         $v0, $zero, L_8003A404
    if (ctx->r2 != 0) {
        // 0x8003A3EC: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_8003A404;
    }
    // 0x8003A3EC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_8003A3F0:
    // 0x8003A3F0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8003A3F4: jal         0x80022888
    // 0x8003A3F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80022888(rdram, ctx);
        goto after_1;
    // 0x8003A3F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x8003A3FC: j           L_8003A464
    // 0x8003A400: sh          $zero, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = 0;
        goto L_8003A464;
    // 0x8003A400: sh          $zero, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = 0;
L_8003A404:
    // 0x8003A404: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8003A408: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // 0x8003A40C: jal         0x80022888
    // 0x8003A410: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    func_80022888(rdram, ctx);
        goto after_2;
    // 0x8003A410: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    after_2:
    // 0x8003A414: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003A418: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003A41C: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8003A420: lui         $v0, 0x6
    ctx->r2 = S32(0X6 << 16);
    // 0x8003A424: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003A428: bne         $v0, $zero, L_8003A438
    if (ctx->r2 != 0) {
        // 0x8003A42C: lui         $v0, 0xB
        ctx->r2 = S32(0XB << 16);
            goto L_8003A438;
    }
    // 0x8003A42C: lui         $v0, 0xB
    ctx->r2 = S32(0XB << 16);
    // 0x8003A430: j           L_8003A458
    // 0x8003A434: lui         $v1, 0xFFFA
    ctx->r3 = S32(0XFFFA << 16);
        goto L_8003A458;
    // 0x8003A434: lui         $v1, 0xFFFA
    ctx->r3 = S32(0XFFFA << 16);
L_8003A438:
    // 0x8003A438: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x8003A43C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003A440: beq         $v0, $zero, L_8003A450
    if (ctx->r2 == 0) {
        // 0x8003A444: lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
            goto L_8003A450;
    }
    // 0x8003A444: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8003A448: j           L_8003A458
    // 0x8003A44C: lui         $v1, 0xFFF4
    ctx->r3 = S32(0XFFF4 << 16);
        goto L_8003A458;
    // 0x8003A44C: lui         $v1, 0xFFF4
    ctx->r3 = S32(0XFFF4 << 16);
L_8003A450:
    // 0x8003A450: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003A454: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_8003A458:
    // 0x8003A458: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003A45C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003A460: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
L_8003A464:
    // 0x8003A464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A468: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003A46C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A470: jr          $ra
    // 0x8003A474: nop

    return;
    // 0x8003A474: nop

;}
RECOMP_FUNC void func_8003A478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A478: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003A47C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003A480: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003A484: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003A488: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003A48C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003A490: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x8003A494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003A498: beq         $v1, $v0, L_8003A510
    if (ctx->r3 == ctx->r2) {
        // 0x8003A49C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8003A510;
    }
    // 0x8003A49C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8003A4A0: beq         $v1, $v0, L_8003A518
    if (ctx->r3 == ctx->r2) {
        // 0x8003A4A4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8003A518;
    }
    // 0x8003A4A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8003A4A8:
    // 0x8003A4A8: jal         0x8001F310
    // 0x8003A4AC: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    func_8001F310(rdram, ctx);
        goto after_0;
    // 0x8003A4AC: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    after_0:
    // 0x8003A4B0: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8003A4B4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003A4B8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8003A4BC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8003A4C0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8003A4C4: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x8003A4C8: addiu       $s2, $s2, 0x3F94
    ctx->r18 = ADD32(ctx->r18, 0X3F94);
    // 0x8003A4CC: addu        $a1, $v1, $s2
    ctx->r5 = ADD32(ctx->r3, ctx->r18);
    // 0x8003A4D0: lhu         $v0, 0x1B0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1B0);
    // 0x8003A4D4: beq         $v0, $s1, L_8003A58C
    if (ctx->r2 == ctx->r17) {
        // 0x8003A4D8: nop
    
            goto L_8003A58C;
    }
    // 0x8003A4D8: nop

    // 0x8003A4DC: jal         0x8001F310
    // 0x8003A4E0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8001F310(rdram, ctx);
        goto after_1;
    // 0x8003A4E0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8003A4E4: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8003A4E8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003A4EC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8003A4F0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8003A4F4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8003A4F8: addu        $a1, $v1, $s2
    ctx->r5 = ADD32(ctx->r3, ctx->r18);
    // 0x8003A4FC: lhu         $v0, 0x1B0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1B0);
    // 0x8003A500: beq         $v0, $s1, L_8003A58C
    if (ctx->r2 == ctx->r17) {
        // 0x8003A504: nop
    
            goto L_8003A58C;
    }
    // 0x8003A504: nop

    // 0x8003A508: j           L_8003A57C
    // 0x8003A50C: nop

        goto L_8003A57C;
    // 0x8003A50C: nop

L_8003A510:
    // 0x8003A510: j           L_8003A4A8
    // 0x8003A514: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_8003A4A8;
    // 0x8003A514: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8003A518:
    // 0x8003A518: jal         0x8001F310
    // 0x8003A51C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001F310(rdram, ctx);
        goto after_2;
    // 0x8003A51C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8003A520: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8003A524: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003A528: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8003A52C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8003A530: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8003A534: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x8003A538: addiu       $s2, $s2, 0x3F94
    ctx->r18 = ADD32(ctx->r18, 0X3F94);
    // 0x8003A53C: addu        $a1, $v1, $s2
    ctx->r5 = ADD32(ctx->r3, ctx->r18);
    // 0x8003A540: lhu         $v0, 0x1B0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1B0);
    // 0x8003A544: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x8003A548: beq         $v0, $s1, L_8003A58C
    if (ctx->r2 == ctx->r17) {
        // 0x8003A54C: nop
    
            goto L_8003A58C;
    }
    // 0x8003A54C: nop

    // 0x8003A550: jal         0x8001F310
    // 0x8003A554: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001F310(rdram, ctx);
        goto after_3;
    // 0x8003A554: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x8003A558: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8003A55C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003A560: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8003A564: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8003A568: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8003A56C: addu        $a1, $v1, $s2
    ctx->r5 = ADD32(ctx->r3, ctx->r18);
    // 0x8003A570: lhu         $v0, 0x1B0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1B0);
    // 0x8003A574: beq         $v0, $s1, L_8003A58C
    if (ctx->r2 == ctx->r17) {
        // 0x8003A578: nop
    
            goto L_8003A58C;
    }
    // 0x8003A578: nop

L_8003A57C:
    // 0x8003A57C: jal         0x8003A688
    // 0x8003A580: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003A688(rdram, ctx);
        goto after_4;
    // 0x8003A580: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8003A584: j           L_8003A598
    // 0x8003A588: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8003A598;
    // 0x8003A588: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8003A58C:
    // 0x8003A58C: jal         0x8003A618
    // 0x8003A590: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003A618(rdram, ctx);
        goto after_5;
    // 0x8003A590: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x8003A594: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8003A598:
    // 0x8003A598: sw          $v0, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->r2;
    // 0x8003A59C: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x8003A5A0: sw          $v0, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r2;
    // 0x8003A5A4: sh          $zero, 0x1B0($s0)
    MEM_H(0X1B0, ctx->r16) = 0;
    // 0x8003A5A8: jal         0x8001DEEC
    // 0x8003A5AC: sh          $zero, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = 0;
    func_8001DEEC(rdram, ctx);
        goto after_6;
    // 0x8003A5AC: sh          $zero, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = 0;
    after_6:
    // 0x8003A5B0: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x8003A5B4: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // 0x8003A5B8: bne         $v1, $v0, L_8003A5F4
    if (ctx->r3 != ctx->r2) {
        // 0x8003A5BC: nop
    
            goto L_8003A5F4;
    }
    // 0x8003A5BC: nop

    // 0x8003A5C0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003A5C4: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003A5C8: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8003A5CC: blez        $v0, L_8003A5E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003A5D0: nop
    
            goto L_8003A5E4;
    }
    // 0x8003A5D0: nop

    // 0x8003A5D4: jal         0x8003A6E4
    // 0x8003A5D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003A6E4(rdram, ctx);
        goto after_7;
    // 0x8003A5D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x8003A5DC: j           L_8003A5FC
    // 0x8003A5E0: nop

        goto L_8003A5FC;
    // 0x8003A5E0: nop

L_8003A5E4:
    // 0x8003A5E4: jal         0x800396C8
    // 0x8003A5E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800396C8(rdram, ctx);
        goto after_8;
    // 0x8003A5E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // 0x8003A5EC: j           L_8003A5FC
    // 0x8003A5F0: nop

        goto L_8003A5FC;
    // 0x8003A5F0: nop

L_8003A5F4:
    // 0x8003A5F4: jal         0x8003AD80
    // 0x8003A5F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AD80(rdram, ctx);
        goto after_9;
    // 0x8003A5F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
L_8003A5FC:
    // 0x8003A5FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003A600: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003A604: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003A608: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003A60C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003A610: jr          $ra
    // 0x8003A614: nop

    return;
    // 0x8003A614: nop

;}
RECOMP_FUNC void func_8003A618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A618: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8003A61C: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x8003A620: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003A624: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8003A628: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003A62C: lw          $v0, -0x1034($at)
    ctx->r2 = MEM_W(ctx->r1, -0X1034);
    // 0x8003A630: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8003A634: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8003A638: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8003A63C: lw          $v1, -0x1034($at)
    ctx->r3 = MEM_W(ctx->r1, -0X1034);
    // 0x8003A640: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003A644: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003A648: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003A64C: lw          $v0, 0x174($at)
    ctx->r2 = MEM_W(ctx->r1, 0X174);
    // 0x8003A650: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8003A654: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003A658: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8003A65C: lw          $v1, 0x174($at)
    ctx->r3 = MEM_W(ctx->r1, 0X174);

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_8003A660
    func_8003A660(rdram, ctx);
}
RECOMP_FUNC void func_8003A660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A660: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8003A664: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003A668: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8003A66C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8003A670: addiu       $v1, $zero, -0x8000
    ctx->r3 = ADD32(0, -0X8000);
    // 0x8003A674: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8003A678: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // 0x8003A67C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8003A680: jr          $ra
    // 0x8003A684: nop

    return;
    // 0x8003A684: nop

;}
RECOMP_FUNC void func_8003A688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A688: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8003A68C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003A690: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8003A694: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003A698: lw          $v0, -0x1034($at)
    ctx->r2 = MEM_W(ctx->r1, -0X1034);
    // 0x8003A69C: lw          $a0, 0x100($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X100);
    // 0x8003A6A0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8003A6A4: addiu       $v1, $v1, 0x174
    ctx->r3 = ADD32(ctx->r3, 0X174);
    // 0x8003A6A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003A6AC: bgez        $a0, L_8003A6C0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8003A6B0: addu        $v0, $v0, $v1
        ctx->r2 = ADD32(ctx->r2, ctx->r3);
            goto L_8003A6C0;
    }
    // 0x8003A6B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003A6B4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003A6B8: j           L_8003A6CC
    // 0x8003A6BC: lui         $v0, 0x64
    ctx->r2 = S32(0X64 << 16);
        goto L_8003A6CC;
    // 0x8003A6BC: lui         $v0, 0x64
    ctx->r2 = S32(0X64 << 16);
L_8003A6C0:
    // 0x8003A6C0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003A6C4: lui         $v0, 0x12B
    ctx->r2 = S32(0X12B << 16);
    // 0x8003A6C8: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
L_8003A6CC:
    // 0x8003A6CC: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003A6D0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8003A6D4: addiu       $v1, $zero, -0x8000
    ctx->r3 = ADD32(0, -0X8000);
    // 0x8003A6D8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8003A6DC: jr          $ra
    // 0x8003A6E0: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    return;
    // 0x8003A6E0: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
;}
RECOMP_FUNC void func_8003A6E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A6E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A6E8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003A6EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A6F0: jal         0x8001D744
    // 0x8003A6F4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8001D744(rdram, ctx);
        goto after_0;
    // 0x8003A6F4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8003A6F8: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x8003A6FC: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // 0x8003A700: beq         $v1, $v0, L_8003A718
    if (ctx->r3 == ctx->r2) {
        // 0x8003A704: nop
    
            goto L_8003A718;
    }
    // 0x8003A704: nop

    // 0x8003A708: jal         0x8003AD80
    // 0x8003A70C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AD80(rdram, ctx);
        goto after_1;
    // 0x8003A70C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003A710: j           L_8003A7C4
    // 0x8003A714: nop

        goto L_8003A7C4;
    // 0x8003A714: nop

L_8003A718:
    // 0x8003A718: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003A71C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003A720: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
    // 0x8003A724: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x8003A728: beq         $v0, $zero, L_8003A740
    if (ctx->r2 == 0) {
        // 0x8003A72C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8003A740;
    }
    // 0x8003A72C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003A730: jal         0x8003965C
    // 0x8003A734: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003965C(rdram, ctx);
        goto after_2;
    // 0x8003A734: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8003A738: j           L_8003A7C4
    // 0x8003A73C: nop

        goto L_8003A7C4;
    // 0x8003A73C: nop

L_8003A740:
    // 0x8003A740: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x8003A744: jal         0x8000A7DC
    // 0x8003A748: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    func_8000A7DC(rdram, ctx);
        goto after_3;
    // 0x8003A748: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    after_3:
    // 0x8003A74C: jal         0x8003E2E8
    // 0x8003A750: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003E2E8(rdram, ctx);
        goto after_4;
    // 0x8003A750: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8003A754: jal         0x80036104
    // 0x8003A758: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80036104(rdram, ctx);
        goto after_5;
    // 0x8003A758: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x8003A75C: jal         0x80044AB4
    // 0x8003A760: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80044AB4(rdram, ctx);
        goto after_6;
    // 0x8003A760: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8003A764: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003A768: lhu         $v0, -0x6DF0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6DF0);
    // 0x8003A76C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8003A770: bne         $v0, $zero, L_8003A794
    if (ctx->r2 != 0) {
        // 0x8003A774: nop
    
            goto L_8003A794;
    }
    // 0x8003A774: nop

    // 0x8003A778: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8003A77C: lw          $v1, 0x3A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3A0);
    // 0x8003A780: beq         $v1, $zero, L_8003A794
    if (ctx->r3 == 0) {
        // 0x8003A784: lui         $v0, 0xFFE8
        ctx->r2 = S32(0XFFE8 << 16);
            goto L_8003A794;
    }
    // 0x8003A784: lui         $v0, 0xFFE8
    ctx->r2 = S32(0XFFE8 << 16);
    // 0x8003A788: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8003A78C: beq         $v0, $zero, L_8003A7A4
    if (ctx->r2 == 0) {
        // 0x8003A790: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_8003A7A4;
    }
    // 0x8003A790: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_8003A794:
    // 0x8003A794: jal         0x8003A234
    // 0x8003A798: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003A234(rdram, ctx);
        goto after_7;
    // 0x8003A798: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x8003A79C: j           L_8003A7C4
    // 0x8003A7A0: nop

        goto L_8003A7C4;
    // 0x8003A7A0: nop

L_8003A7A4:
    // 0x8003A7A4: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // 0x8003A7A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8003A7AC: jal         0x80022888
    // 0x8003A7B0: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    func_80022888(rdram, ctx);
        goto after_8;
    // 0x8003A7B0: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    after_8:
    // 0x8003A7B4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003A7B8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003A7BC: lui         $v0, 0xFFF1
    ctx->r2 = S32(0XFFF1 << 16);
    // 0x8003A7C0: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
L_8003A7C4:
    // 0x8003A7C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A7C8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003A7CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A7D0: jr          $ra
    // 0x8003A7D4: nop

    return;
    // 0x8003A7D4: nop

;}
RECOMP_FUNC void func_8003A7D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A7D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A7DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003A7E0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003A7E4: addiu       $a0, $zero, 0x700
    ctx->r4 = ADD32(0, 0X700);
    // 0x8003A7E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A7EC: jal         0x8003BA80
    // 0x8003A7F0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003BA80(rdram, ctx);
        goto after_0;
    // 0x8003A7F0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8003A7F4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003A7F8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003A7FC: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8003A800: lhu         $v0, 0xCC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XCC);
    // 0x8003A804: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003A808: sw          $v0, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = ctx->r2;
    // 0x8003A80C: lhu         $a0, 0xCC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XCC);
    // 0x8003A810: sltiu       $v0, $a0, 0x2
    ctx->r2 = ctx->r4 < 0X2 ? 1 : 0;
    // 0x8003A814: bne         $v0, $zero, L_8003A83C
    if (ctx->r2 != 0) {
        // 0x8003A818: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8003A83C;
    }
    // 0x8003A818: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8003A81C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8003A820: beq         $a0, $v0, L_8003A83C
    if (ctx->r4 == ctx->r2) {
        // 0x8003A824: sltiu       $v0, $a0, 0x5
        ctx->r2 = ctx->r4 < 0X5 ? 1 : 0;
            goto L_8003A83C;
    }
    // 0x8003A824: sltiu       $v0, $a0, 0x5
    ctx->r2 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x8003A828: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8003A82C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8003A830: sll         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2 << 17);
    // 0x8003A834: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x8003A838: or          $v1, $v0, $v1
    ctx->r3 = ctx->r2 | ctx->r3;
L_8003A83C:
    // 0x8003A83C: sw          $v1, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->r3;
    // 0x8003A840: jal         0x8000B8E8
    // 0x8003A844: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000B8E8(rdram, ctx);
        goto after_1;
    // 0x8003A844: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003A848: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003A84C: bne         $v0, $zero, L_8003A860
    if (ctx->r2 != 0) {
        // 0x8003A850: addiu       $v0, $zero, 0x36
        ctx->r2 = ADD32(0, 0X36);
            goto L_8003A860;
    }
    // 0x8003A850: addiu       $v0, $zero, 0x36
    ctx->r2 = ADD32(0, 0X36);
    // 0x8003A854: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x8003A858: jal         0x8003AA30
    // 0x8003A85C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AA30(rdram, ctx);
        goto after_2;
    // 0x8003A85C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_8003A860:
    // 0x8003A860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A864: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003A868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A86C: jr          $ra
    // 0x8003A870: nop

    return;
    // 0x8003A870: nop

;}
RECOMP_FUNC void func_8003A874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A878: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003A87C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003A880: addiu       $a0, $zero, 0x700
    ctx->r4 = ADD32(0, 0X700);
    // 0x8003A884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A888: jal         0x8003BA80
    // 0x8003A88C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003BA80(rdram, ctx);
        goto after_0;
    // 0x8003A88C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8003A890: jal         0x8003AD80
    // 0x8003A894: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AD80(rdram, ctx);
        goto after_1;
    // 0x8003A894: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003A898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A89C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003A8A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A8A4: jr          $ra
    // 0x8003A8A8: nop

    return;
    // 0x8003A8A8: nop

;}
RECOMP_FUNC void func_8003A8AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A8AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A8B0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003A8B4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003A8B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A8BC: lhu         $v1, 0x1CC($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X1CC);
    // 0x8003A8C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003A8C4: beq         $v1, $zero, L_8003A978
    if (ctx->r3 == 0) {
        // 0x8003A8C8: sh          $v0, 0x1C8($s0)
        MEM_H(0X1C8, ctx->r16) = ctx->r2;
            goto L_8003A978;
    }
    // 0x8003A8C8: sh          $v0, 0x1C8($s0)
    MEM_H(0X1C8, ctx->r16) = ctx->r2;
    // 0x8003A8CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003A8D0: bne         $v1, $v0, L_8003A958
    if (ctx->r3 != ctx->r2) {
        // 0x8003A8D4: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8003A958;
    }
    // 0x8003A8D4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8003A8D8: lhu         $v0, 0xC8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC8);
    // 0x8003A8DC: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8003A8E0: beq         $v0, $zero, L_8003A934
    if (ctx->r2 == 0) {
        // 0x8003A8E4: nop
    
            goto L_8003A934;
    }
    // 0x8003A8E4: nop

    // 0x8003A8E8: jal         0x80025818
    // 0x8003A8EC: nop

    func_80025818(rdram, ctx);
        goto after_0;
    // 0x8003A8EC: nop

    after_0:
    // 0x8003A8F0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8003A8F4: beq         $v1, $zero, L_8003A934
    if (ctx->r3 == 0) {
        // 0x8003A8F8: addiu       $a0, $zero, 0x82
        ctx->r4 = ADD32(0, 0X82);
            goto L_8003A934;
    }
    // 0x8003A8F8: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    // 0x8003A8FC: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8003A900: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8003A904: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x8003A908: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8003A90C: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8003A910: jal         0x8004C79C
    // 0x8003A914: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    func_8004C79C(rdram, ctx);
        goto after_1;
    // 0x8003A914: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    after_1:
    // 0x8003A918: lui         $v0, 0x44
    ctx->r2 = S32(0X44 << 16);
    // 0x8003A91C: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x8003A920: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
    // 0x8003A924: sh          $zero, 0x1CC($s0)
    MEM_H(0X1CC, ctx->r16) = 0;
    // 0x8003A928: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x8003A92C: j           L_8003A980
    // 0x8003A930: sh          $zero, 0xDC($s0)
    MEM_H(0XDC, ctx->r16) = 0;
        goto L_8003A980;
    // 0x8003A930: sh          $zero, 0xDC($s0)
    MEM_H(0XDC, ctx->r16) = 0;
L_8003A934:
    // 0x8003A934: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003A938: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8003A93C: lhu         $v0, 0x6C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6C);
    // 0x8003A940: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8003A944: bne         $v0, $zero, L_8003A958
    if (ctx->r2 != 0) {
        // 0x8003A948: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8003A958;
    }
    // 0x8003A948: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8003A94C: lhu         $v0, 0xE4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE4);
    // 0x8003A950: beq         $v0, $zero, L_8003A980
    if (ctx->r2 == 0) {
        // 0x8003A954: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8003A980;
    }
    // 0x8003A954: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8003A958:
    // 0x8003A958: sh          $v0, 0x1CC($s0)
    MEM_H(0X1CC, ctx->r16) = ctx->r2;
    // 0x8003A95C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003A960: sh          $v0, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r2;
    // 0x8003A964: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003A968: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8003A96C: addiu       $v0, $zero, 0x500
    ctx->r2 = ADD32(0, 0X500);
    // 0x8003A970: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    // 0x8003A974: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
L_8003A978:
    // 0x8003A978: jal         0x8003AD80
    // 0x8003A97C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AD80(rdram, ctx);
        goto after_2;
    // 0x8003A97C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_8003A980:
    // 0x8003A980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A984: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003A988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A98C: jr          $ra
    // 0x8003A990: nop

    return;
    // 0x8003A990: nop

;}
RECOMP_FUNC void func_8003A994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A998: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003A99C: jal         0x8003AD80
    // 0x8003A9A0: nop

    func_8003AD80(rdram, ctx);
        goto after_0;
    // 0x8003A9A0: nop

    after_0:
    // 0x8003A9A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003A9A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A9AC: jr          $ra
    // 0x8003A9B0: nop

    return;
    // 0x8003A9B0: nop

;}
RECOMP_FUNC void func_8003A9B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A9B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A9B8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003A9BC: jal         0x8003AD80
    // 0x8003A9C0: nop

    func_8003AD80(rdram, ctx);
        goto after_0;
    // 0x8003A9C0: nop

    after_0:
    // 0x8003A9C4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003A9C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A9CC: jr          $ra
    // 0x8003A9D0: nop

    return;
    // 0x8003A9D0: nop

;}
RECOMP_FUNC void func_8003A9D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A9D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A9D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003A9DC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003A9E0: jal         0x8003AD80
    // 0x8003A9E4: sh          $v0, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r2;
    func_8003AD80(rdram, ctx);
        goto after_0;
    // 0x8003A9E4: sh          $v0, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r2;
    after_0:
    // 0x8003A9E8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003A9EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A9F0: jr          $ra
    // 0x8003A9F4: nop

    return;
    // 0x8003A9F4: nop

;}
RECOMP_FUNC void func_8003A9F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A9F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A9FC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003AA00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AA04: jal         0x8003AD80
    // 0x8003AA08: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8003AD80(rdram, ctx);
        goto after_0;
    // 0x8003AA08: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8003AA0C: lhu         $v1, 0x5A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X5A);
    // 0x8003AA10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003AA14: beql        $v1, $v0, L_8003AA1C
    if (ctx->r3 == ctx->r2) {
        // 0x8003AA18: sh          $zero, 0x5A($s0)
        MEM_H(0X5A, ctx->r16) = 0;
            goto L_8003AA1C;
    }
    goto skip_0;
    // 0x8003AA18: sh          $zero, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = 0;
    skip_0:
L_8003AA1C:
    // 0x8003AA1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AA20: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003AA24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003AA28: jr          $ra
    // 0x8003AA2C: nop

    return;
    // 0x8003AA2C: nop

;}
RECOMP_FUNC void func_8003AA30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AA30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003AA34: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003AA38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AA3C: jal         0x8003AD80
    // 0x8003AA40: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8003AD80(rdram, ctx);
        goto after_0;
    // 0x8003AA40: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8003AA44: jal         0x8003AA60
    // 0x8003AA48: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003AA60(rdram, ctx);
        goto after_1;
    // 0x8003AA48: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8003AA4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AA50: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003AA54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003AA58: jr          $ra
    // 0x8003AA5C: nop

    return;
    // 0x8003AA5C: nop

;}
RECOMP_FUNC void func_8003AA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AA60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003AA64: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003AA68: lhu         $a0, 0xCC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XCC);
    // 0x8003AA6C: jal         0x8003B480
    // 0x8003AA70: nop

    func_8003B480(rdram, ctx);
        goto after_0;
    // 0x8003AA70: nop

    after_0:
    // 0x8003AA74: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003AA78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003AA7C: jr          $ra
    // 0x8003AA80: nop

    return;
    // 0x8003AA80: nop

;}
