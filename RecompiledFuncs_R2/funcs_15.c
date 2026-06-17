#include "recomp.h"
#include "funcs.h"

// Forward declarations
void func_800091D8(uint8_t* rdram, recomp_context* ctx);
void func_80009448(uint8_t* rdram, recomp_context* ctx);
void func_80009668(uint8_t* rdram, recomp_context* ctx);
void func_80009720(uint8_t* rdram, recomp_context* ctx);
void func_80009A74(uint8_t* rdram, recomp_context* ctx);
void func_80009A8C(uint8_t* rdram, recomp_context* ctx);
void func_80009B80(uint8_t* rdram, recomp_context* ctx);
void func_80009E20(uint8_t* rdram, recomp_context* ctx);
void func_80009ED8(uint8_t* rdram, recomp_context* ctx);
void func_8000A0FC(uint8_t* rdram, recomp_context* ctx);
void func_8000A168(uint8_t* rdram, recomp_context* ctx);
void func_8000A180(uint8_t* rdram, recomp_context* ctx);
void func_8000A234(uint8_t* rdram, recomp_context* ctx);
void func_8000ABD4(uint8_t* rdram, recomp_context* ctx);
void func_8000ABEC(uint8_t* rdram, recomp_context* ctx);
void func_8000ACE8(uint8_t* rdram, recomp_context* ctx);
void func_8000AE14(uint8_t* rdram, recomp_context* ctx);
void func_8000AE78(uint8_t* rdram, recomp_context* ctx);
void func_8000AF08(uint8_t* rdram, recomp_context* ctx);
void func_8000AF58(uint8_t* rdram, recomp_context* ctx);
void func_8000AFE4(uint8_t* rdram, recomp_context* ctx);
void func_8000B070(uint8_t* rdram, recomp_context* ctx);
void func_8000B0C8(uint8_t* rdram, recomp_context* ctx);
void func_8000B12C(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80008CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008CC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008CCC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80008CD0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80008CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008CD8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80008CDC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80008CE0: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x80008CE4: jal         0x80023470
    // 0x80008CE8: nop

    func_80023470(rdram, ctx);
        goto after_0;
    // 0x80008CE8: nop

    after_0:
    // 0x80008CEC: jal         0x800091D8
    // 0x80008CF0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800091D8(rdram, ctx);
        goto after_1;
    // 0x80008CF0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80008CF4: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x80008CF8: addiu       $v1, $v0, -0x3
    ctx->r3 = ADD32(ctx->r2, -0X3);
    // 0x80008CFC: sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // 0x80008D00: beq         $v0, $zero, L_80008D94
    if (ctx->r2 == 0) {
        // 0x80008D04: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80008D94;
    }
    // 0x80008D04: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80008D08: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80008D0C: addu        $at, $at, $v0
    gpr jr_addend_80008D14 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80008D10: lw          $v0, 0x3528($at)
    ctx->r2 = ADD32(ctx->r1, 0X3528);
    // 0x80008D14: jr          $v0
    // 0x80008D18: nop

    switch (jr_addend_80008D14 >> 2) {
        case 0: goto L_80008D1C; break;
        case 1: goto L_80008D94; break;
        case 2: goto L_80008D94; break;
        case 3: goto L_80008D94; break;
        case 4: goto L_80008D94; break;
        case 5: goto L_80008D94; break;
        case 6: goto L_80008D94; break;
        case 7: goto L_80008D94; break;
        case 8: goto L_80008D94; break;
        case 9: goto L_80008D94; break;
        case 10: goto L_80008D94; break;
        case 11: goto L_80008D94; break;
        case 12: goto L_80008D4C; break;
        case 13: goto L_80008D94; break;
        case 14: goto L_80008D5C; break;
        case 15: goto L_80008D5C; break;
        case 16: goto L_80008D7C; break;
        case 17: goto L_80008D8C; break;
        case 18: goto L_80008D8C; break;
        case 19: goto L_80008D94; break;
        case 20: goto L_80008D94; break;
        case 21: goto L_80008D94; break;
        case 22: goto L_80008D94; break;
        case 23: goto L_80008D94; break;
        case 24: goto L_80008D94; break;
        case 25: goto L_80008D94; break;
        case 26: goto L_80008D94; break;
        case 27: goto L_80008D94; break;
        case 28: goto L_80008D94; break;
        case 29: goto L_80008D94; break;
        case 30: goto L_80008D94; break;
        case 31: goto L_80008D94; break;
        case 32: goto L_80008D94; break;
        case 33: goto L_80008D94; break;
        case 34: goto L_80008D94; break;
        case 35: goto L_80008D94; break;
        case 36: goto L_80008D94; break;
        case 37: goto L_80008D94; break;
        case 38: goto L_80008D94; break;
        case 39: goto L_80008D94; break;
        case 40: goto L_80008D94; break;
        case 41: goto L_80008D94; break;
        case 42: goto L_80008D94; break;
        case 43: goto L_80008D94; break;
        case 44: goto L_80008D94; break;
        case 45: goto L_80008D94; break;
        case 46: goto L_80008D6C; break;
        case 47: goto L_80008D94; break;
        case 48: goto L_80008D94; break;
        case 49: goto L_80008D94; break;
        case 50: goto L_80008D94; break;
        case 51: goto L_80008D94; break;
        case 52: goto L_80008D94; break;
        case 53: goto L_80008D94; break;
        case 54: goto L_80008D94; break;
        case 55: goto L_80008D94; break;
        case 56: goto L_80008D2C; break;
        case 57: goto L_80008D94; break;
        case 58: goto L_80008D94; break;
        case 59: goto L_80008D3C; break;
        case 60: goto L_80008D3C; break;
        case 61: goto L_80008D94; break;
        case 62: goto L_80008D94; break;
        case 63: goto L_80008D94; break;
        default: switch_error(__func__, 0x80008D14, 0x80093528);
    }
    // 0x80008D18: nop

L_80008D1C:
    // 0x80008D1C: jal         0x80011A60
    // 0x80008D20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80011A60(rdram, ctx);
        goto after_2;
    // 0x80008D20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80008D24: j           L_80008D94
    // 0x80008D28: nop

        goto L_80008D94;
    // 0x80008D28: nop

L_80008D2C:
    // 0x80008D2C: jal         0x8000ACE8
    // 0x80008D30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000ACE8(rdram, ctx);
        goto after_3;
    // 0x80008D30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80008D34: j           L_80008D94
    // 0x80008D38: nop

        goto L_80008D94;
    // 0x80008D38: nop

L_80008D3C:
    // 0x80008D3C: jal         0x8000B15C
    // 0x80008D40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000B15C(rdram, ctx);
        goto after_4;
    // 0x80008D40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80008D44: j           L_80008D94
    // 0x80008D48: nop

        goto L_80008D94;
    // 0x80008D48: nop

L_80008D4C:
    // 0x80008D4C: jal         0x8004C8F0
    // 0x80008D50: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004C8F0(rdram, ctx);
        goto after_5;
    // 0x80008D50: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80008D54: j           L_80008D94
    // 0x80008D58: nop

        goto L_80008D94;
    // 0x80008D58: nop

L_80008D5C:
    // 0x80008D5C: jal         0x8002A71C
    // 0x80008D60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002A71C(rdram, ctx);
        goto after_6;
    // 0x80008D60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x80008D64: j           L_80008D94
    // 0x80008D68: nop

        goto L_80008D94;
    // 0x80008D68: nop

L_80008D6C:
    // 0x80008D6C: jal         0x8004EFD0
    // 0x80008D70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004EFD0(rdram, ctx);
        goto after_7;
    // 0x80008D70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x80008D74: j           L_80008D94
    // 0x80008D78: nop

        goto L_80008D94;
    // 0x80008D78: nop

L_80008D7C:
    // 0x80008D7C: jal         0x8004F898
    // 0x80008D80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004F898(rdram, ctx);
        goto after_8;
    // 0x80008D80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // 0x80008D84: j           L_80008D94
    // 0x80008D88: nop

        goto L_80008D94;
    // 0x80008D88: nop

L_80008D8C:
    // 0x80008D8C: jal         0x8004F9DC
    // 0x80008D90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004F9DC(rdram, ctx);
        goto after_9;
    // 0x80008D90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
L_80008D94:
    // 0x80008D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008D98: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80008D9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008DA0: jr          $ra
    // 0x80008DA4: nop

    return;
    // 0x80008DA4: nop

;}
RECOMP_FUNC void func_80008DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008DA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80008DAC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80008DB0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80008DB4: addiu       $s0, $s0, -0x2048
    ctx->r16 = ADD32(ctx->r16, -0X2048);
    // 0x80008DB8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80008DBC: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
    // 0x80008DC0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_80008DC4:
    // 0x80008DC4: jal         0x80009448
    // 0x80008DC8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80009448(rdram, ctx);
        goto after_0;
    // 0x80008DC8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80008DCC: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x80008DD0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80008DD4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80008DD8: bne         $v0, $zero, L_80008DC4
    if (ctx->r2 != 0) {
        // 0x80008DDC: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_80008DC4;
    }
    // 0x80008DDC: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    // 0x80008DE0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80008DE4: sh          $s1, -0x74F0($at)
    MEM_H(-0X74F0, ctx->r1) = ctx->r17;
    // 0x80008DE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80008DEC: sh          $s1, -0x1D18($at)
    MEM_H(-0X1D18, ctx->r1) = ctx->r17;
    // 0x80008DF0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80008DF4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80008DF8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80008DFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80008E00: jr          $ra
    // 0x80008E04: nop

    return;
    // 0x80008E04: nop

;}
RECOMP_FUNC void func_80008E08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008E08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008E0C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80008E10: jal         0x80008DA8
    // 0x80008E14: nop

    func_80008DA8(rdram, ctx);
        goto after_0;
    // 0x80008E14: nop

    after_0:
    // 0x80008E18: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80008E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008E20: jr          $ra
    // 0x80008E24: nop

    return;
    // 0x80008E24: nop

;}
RECOMP_FUNC void func_80008E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008E28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80008E2C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80008E30: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80008E34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80008E38: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80008E3C: lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // 0x80008E40: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80008E44: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80008E48: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80008E4C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80008E50: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80008E54: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80008E58: jal         0x80001564
    // 0x80008E5C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80001564(rdram, ctx);
        goto after_0;
    // 0x80008E5C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x80008E60: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80008E64: lhu         $v1, 0x22($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X22);
    // 0x80008E68: addiu       $v0, $zero, -0x3E7
    ctx->r2 = ADD32(0, -0X3E7);
    // 0x80008E6C: sw          $v0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r2;
    // 0x80008E70: lhu         $v0, 0x6C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X6C);
    // 0x80008E74: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80008E78: sh          $s0, 0x80($a0)
    MEM_H(0X80, ctx->r4) = ctx->r16;
    // 0x80008E7C: andi        $v1, $v1, 0xFFDF
    ctx->r3 = ctx->r3 & 0XFFDF;
    // 0x80008E80: ori         $v1, $v1, 0x400
    ctx->r3 = ctx->r3 | 0X400;
    // 0x80008E84: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
    // 0x80008E88: sh          $v1, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r3;
    // 0x80008E8C: sh          $v0, 0x6C($a0)
    MEM_H(0X6C, ctx->r4) = ctx->r2;
    // 0x80008E90: jal         0x8002EB34
    // 0x80008E94: sw          $a0, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->r4;
    func_8002EB34(rdram, ctx);
        goto after_1;
    // 0x80008E94: sw          $a0, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->r4;
    after_1:
    // 0x80008E98: jal         0x800306EC
    // 0x80008E9C: nop

    func_800306EC(rdram, ctx);
        goto after_2;
    // 0x80008E9C: nop

    after_2:
    // 0x80008EA0: lui         $v1, 0x4F00
    ctx->r3 = S32(0X4F00 << 16);
    // 0x80008EA4: ori         $v1, $v1, 0x986
    ctx->r3 = ctx->r3 | 0X986;
    // 0x80008EA8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80008EAC: sw          $s0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r16;
    // 0x80008EB0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80008EB4: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x80008EB8: jal         0x80023E44
    // 0x80008EBC: nop

    func_80023E44(rdram, ctx);
        goto after_3;
    // 0x80008EBC: nop

    after_3:
    // 0x80008EC0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80008EC4: lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X22);
    // 0x80008EC8: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x80008ECC: sh          $v0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r2;
    // 0x80008ED0: jal         0x8002EB34
    // 0x80008ED4: sw          $a0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r4;
    func_8002EB34(rdram, ctx);
        goto after_4;
    // 0x80008ED4: sw          $a0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r4;
    after_4:
    // 0x80008ED8: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80008EDC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80008EE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80008EE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80008EE8: jr          $ra
    // 0x80008EEC: nop

    return;
    // 0x80008EEC: nop

;}
RECOMP_FUNC void func_80008EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008EF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008EF4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80008EF8: lw          $v1, -0x1D30($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1D30);
    // 0x80008EFC: addu        $t6, $a0, $zero
    ctx->r14 = ADD32(ctx->r4, 0);
    // 0x80008F00: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x80008F04: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80008F08: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80008F0C: ori         $v0, $zero, 0xA8BE
    ctx->r2 = 0 | 0XA8BE;
    // 0x80008F10: addiu       $v1, $v1, -0x5461
    ctx->r3 = ADD32(ctx->r3, -0X5461);
    // 0x80008F14: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80008F18: beq         $v0, $zero, L_800091B4
    if (ctx->r2 == 0) {
        // 0x80008F1C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800091B4;
    }
    // 0x80008F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008F20: lhu         $v0, 0x6C($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X6C);
    // 0x80008F24: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80008F28: bne         $v0, $zero, L_800091B4
    if (ctx->r2 != 0) {
        // 0x80008F2C: nop
    
            goto L_800091B4;
    }
    // 0x80008F2C: nop

    // 0x80008F30: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80008F34: addiu       $a1, $a1, 0x38F0
    ctx->r5 = ADD32(ctx->r5, 0X38F0);
    // 0x80008F38: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80008F3C: lw          $v1, 0x38($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X38);
    // 0x80008F40: beq         $v0, $v1, L_80008F68
    if (ctx->r2 == ctx->r3) {
        // 0x80008F44: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80008F68;
    }
    // 0x80008F44: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80008F48: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80008F4C: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x80008F50: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80008F54:
    // 0x80008F54: beq         $v0, $zero, L_800091B4
    if (ctx->r2 == 0) {
        // 0x80008F58: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800091B4;
    }
    // 0x80008F58: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80008F5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80008F60: bne         $v0, $a0, L_80008F54
    if (ctx->r2 != ctx->r4) {
        // 0x80008F64: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_80008F54;
    }
    // 0x80008F64: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_80008F68:
    // 0x80008F68: lhu         $v0, 0x22($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X22);
    // 0x80008F6C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80008F70: beq         $v0, $zero, L_80008F9C
    if (ctx->r2 == 0) {
        // 0x80008F74: sll         $v0, $t0, 2
        ctx->r2 = S32(ctx->r8 << 2);
            goto L_80008F9C;
    }
    // 0x80008F74: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80008F78: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008F7C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80008F80: lw          $v0, 0x38F8($at)
    ctx->r2 = MEM_W(ctx->r1, 0X38F8);
    // 0x80008F84: lw          $v1, 0x14($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X14);
    // 0x80008F88: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80008F8C: lw          $a0, 0x3294($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3294);
    // 0x80008F90: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80008F94: j           L_80008FBC
    // 0x80008F98: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
        goto L_80008FBC;
    // 0x80008F98: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
L_80008F9C:
    // 0x80008F9C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008FA0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80008FA4: lw          $v0, 0x38F8($at)
    ctx->r2 = MEM_W(ctx->r1, 0X38F8);
    // 0x80008FA8: lw          $v1, 0x14($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X14);
    // 0x80008FAC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80008FB0: lw          $a0, 0x3294($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3294);
    // 0x80008FB4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80008FB8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_80008FBC:
    // 0x80008FBC: and         $t2, $v1, $a0
    ctx->r10 = ctx->r3 & ctx->r4;
    // 0x80008FC0: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80008FC4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008FC8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80008FCC: lw          $v0, 0x38FC($at)
    ctx->r2 = MEM_W(ctx->r1, 0X38FC);
    // 0x80008FD0: lw          $v1, 0x18($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X18);
    // 0x80008FD4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80008FD8: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    // 0x80008FDC: lui         $v0, 0xE1
    ctx->r2 = S32(0XE1 << 16);
    // 0x80008FE0: subu        $t3, $v0, $t4
    ctx->r11 = SUB32(ctx->r2, ctx->r12);
    // 0x80008FE4: lui         $v1, 0xFFF6
    ctx->r3 = S32(0XFFF6 << 16);
    // 0x80008FE8: addu        $v1, $t3, $v1
    ctx->r3 = ADD32(ctx->r11, ctx->r3);
    // 0x80008FEC: lui         $v0, 0xE6
    ctx->r2 = S32(0XE6 << 16);
    // 0x80008FF0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80008FF4: bne         $v0, $zero, L_800091B4
    if (ctx->r2 != 0) {
        // 0x80008FF8: lui         $v0, 0x7FF
        ctx->r2 = S32(0X7FF << 16);
            goto L_800091B4;
    }
    // 0x80008FF8: lui         $v0, 0x7FF
    ctx->r2 = S32(0X7FF << 16);
    // 0x80008FFC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80009000: lw          $v1, 0x3294($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3294);
    // 0x80009004: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80009008: bne         $v1, $v0, L_80009018
    if (ctx->r3 != ctx->r2) {
        // 0x8000900C: addiu       $a3, $zero, 0x6
        ctx->r7 = ADD32(0, 0X6);
            goto L_80009018;
    }
    // 0x8000900C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80009010: j           L_80009028
    // 0x80009014: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
        goto L_80009028;
    // 0x80009014: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
L_80009018:
    // 0x80009018: lui         $v0, 0xFFF
    ctx->r2 = S32(0XFFF << 16);
    // 0x8000901C: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80009020: beql        $v1, $v0, L_80009028
    if (ctx->r3 == ctx->r2) {
        // 0x80009024: addiu       $a3, $zero, 0x4
        ctx->r7 = ADD32(0, 0X4);
            goto L_80009028;
    }
    goto skip_0;
    // 0x80009024: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    skip_0:
L_80009028:
    // 0x80009028: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8000902C: addiu       $t8, $t8, 0x46A8
    ctx->r24 = ADD32(ctx->r24, 0X46A8);
    // 0x80009030: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80009034: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80009038: addiu       $t9, $t9, 0x3A0
    ctx->r25 = ADD32(ctx->r25, 0X3A0);
    // 0x8000903C: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x80009040: subu        $v0, $t2, $v0
    ctx->r2 = SUB32(ctx->r10, ctx->r2);
    // 0x80009044: sllv        $v0, $v0, $a3
    ctx->r2 = S32(ctx->r2 << (ctx->r7 & 31));
    // 0x80009048: srav        $a0, $v0, $a3
    ctx->r4 = S32(SIGNED(ctx->r2) >> (ctx->r7 & 31));
    // 0x8000904C: subu        $a1, $t4, $v1
    ctx->r5 = SUB32(ctx->r12, ctx->r3);
    // 0x80009050: lui         $v1, 0x50
    ctx->r3 = S32(0X50 << 16);
    // 0x80009054: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80009058: lui         $v0, 0x230
    ctx->r2 = S32(0X230 << 16);
    // 0x8000905C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80009060: bne         $v0, $zero, L_800091B4
    if (ctx->r2 != 0) {
        // 0x80009064: lui         $t7, 0xFFFF
        ctx->r15 = S32(0XFFFF << 16);
            goto L_800091B4;
    }
    // 0x80009064: lui         $t7, 0xFFFF
    ctx->r15 = S32(0XFFFF << 16);
    // 0x80009068: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8000906C: srl         $v0, $a0, 16
    ctx->r2 = S32(U32(ctx->r4) >> 16);
    // 0x80009070: lui         $t5, 0x3
    ctx->r13 = S32(0X3 << 16);
    // 0x80009074: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80009078: and         $v1, $a1, $t7
    ctx->r3 = ctx->r5 & ctx->r15;
    // 0x8000907C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80009080: sw          $v0, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->r2;
    // 0x80009084: srl         $v0, $a0, 16
    ctx->r2 = S32(U32(ctx->r4) >> 16);
    // 0x80009088: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8000908C: sw          $v0, 0x54($t6)
    MEM_W(0X54, ctx->r14) = ctx->r2;
    // 0x80009090: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80009094: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80009098: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000909C: lw          $v1, 0x38F4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X38F4);
    // 0x800090A0: lhu         $v0, 0x22($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X22);
    // 0x800090A4: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800090A8: div         $zero, $t3, $v1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r3)));
    // 0x800090AC: bne         $v1, $zero, L_800090B8
    if (ctx->r3 != 0) {
        // 0x800090B0: nop
    
            goto L_800090B8;
    }
    // 0x800090B0: nop

    // 0x800090B4: break       7
    do_break(2147520692);
L_800090B8:
    // 0x800090B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800090BC: bne         $v1, $at, L_800090D0
    if (ctx->r3 != ctx->r1) {
        // 0x800090C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800090D0;
    }
    // 0x800090C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800090C4: bne         $t3, $at, L_800090D0
    if (ctx->r11 != ctx->r1) {
        // 0x800090C8: nop
    
            goto L_800090D0;
    }
    // 0x800090C8: nop

    // 0x800090CC: break       6
    do_break(2147520716);
L_800090D0:
    // 0x800090D0: mflo        $a2
    ctx->r6 = lo;
    // 0x800090D4: nop

    // 0x800090D8: nop

    // 0x800090DC: beq         $v0, $zero, L_800090E8
    if (ctx->r2 == 0) {
        // 0x800090E0: negu        $v0, $a2
        ctx->r2 = SUB32(0, ctx->r6);
            goto L_800090E8;
    }
    // 0x800090E0: negu        $v0, $a2
    ctx->r2 = SUB32(0, ctx->r6);
    // 0x800090E4: subu        $a2, $v0, $t5
    ctx->r6 = SUB32(ctx->r2, ctx->r13);
L_800090E8:
    // 0x800090E8: lw          $a1, 0x40($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X40);
    // 0x800090EC: addiu       $v0, $zero, -0x3E7
    ctx->r2 = ADD32(0, -0X3E7);
    // 0x800090F0: beq         $a1, $v0, L_80009118
    if (ctx->r5 == ctx->r2) {
        // 0x800090F4: addu        $v0, $t2, $a2
        ctx->r2 = ADD32(ctx->r10, ctx->r6);
            goto L_80009118;
    }
    // 0x800090F4: addu        $v0, $t2, $a2
    ctx->r2 = ADD32(ctx->r10, ctx->r6);
    // 0x800090F8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800090FC: lw          $v1, 0x3294($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3294);
    // 0x80009100: addu        $t2, $a1, $zero
    ctx->r10 = ADD32(ctx->r5, 0);
    // 0x80009104: and         $t0, $v0, $v1
    ctx->r8 = ctx->r2 & ctx->r3;
    // 0x80009108: subu        $v0, $t0, $t2
    ctx->r2 = SUB32(ctx->r8, ctx->r10);
    // 0x8000910C: sllv        $v0, $v0, $a3
    ctx->r2 = S32(ctx->r2 << (ctx->r7 & 31));
    // 0x80009110: addiu       $v1, $a3, 0x3
    ctx->r3 = ADD32(ctx->r7, 0X3);
    // 0x80009114: srav        $a2, $v0, $v1
    ctx->r6 = S32(SIGNED(ctx->r2) >> (ctx->r3 & 31));
L_80009118:
    // 0x80009118: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8000911C: lw          $t1, 0x3294($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3294);
    // 0x80009120: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80009124: addu        $t5, $t2, $a2
    ctx->r13 = ADD32(ctx->r10, ctx->r6);
    // 0x80009128: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x8000912C: addu        $t2, $t4, $t3
    ctx->r10 = ADD32(ctx->r12, ctx->r11);
    // 0x80009130: and         $t0, $t5, $t1
    ctx->r8 = ctx->r13 & ctx->r9;
    // 0x80009134: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x80009138: sllv        $v0, $v0, $a3
    ctx->r2 = S32(ctx->r2 << (ctx->r7 & 31));
    // 0x8000913C: srav        $a3, $v0, $a3
    ctx->r7 = S32(SIGNED(ctx->r2) >> (ctx->r7 & 31));
    // 0x80009140: subu        $a1, $t2, $v1
    ctx->r5 = SUB32(ctx->r10, ctx->r3);
    // 0x80009144: lui         $v0, 0x150
    ctx->r2 = S32(0X150 << 16);
    // 0x80009148: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000914C: srl         $v1, $a3, 31
    ctx->r3 = S32(U32(ctx->r7) >> 31);
    // 0x80009150: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80009154: beq         $v0, $zero, L_80009160
    if (ctx->r2 == 0) {
        // 0x80009158: addiu       $v0, $a3, 0x1
        ctx->r2 = ADD32(ctx->r7, 0X1);
            goto L_80009160;
    }
    // 0x80009158: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x8000915C: addu        $a3, $v0, $t1
    ctx->r7 = ADD32(ctx->r2, ctx->r9);
L_80009160:
    // 0x80009160: lui         $a2, 0xFFE8
    ctx->r6 = S32(0XFFE8 << 16);
    // 0x80009164: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x80009168: srl         $v1, $a3, 16
    ctx->r3 = S32(U32(ctx->r7) >> 16);
    // 0x8000916C: lui         $v0, 0x30
    ctx->r2 = S32(0X30 << 16);
    // 0x80009170: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x80009174: addu        $a0, $t6, $zero
    ctx->r4 = ADD32(ctx->r14, 0);
    // 0x80009178: and         $a1, $a1, $t7
    ctx->r5 = ctx->r5 & ctx->r15;
    // 0x8000917C: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // 0x80009180: srl         $v0, $a3, 16
    ctx->r2 = S32(U32(ctx->r7) >> 16);
    // 0x80009184: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x80009188: addu        $a2, $t5, $a2
    ctx->r6 = ADD32(ctx->r13, ctx->r6);
    // 0x8000918C: sw          $v1, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r3;
    // 0x80009190: sw          $v0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r2;
    // 0x80009194: sw          $t0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r8;
    // 0x80009198: sw          $a2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r6;
    // 0x8000919C: jal         0x8002EB50
    // 0x800091A0: sw          $t2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r10;
    func_8002EB50(rdram, ctx);
        goto after_0;
    // 0x800091A0: sw          $t2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r10;
    after_0:
    // 0x800091A4: jal         0x8002EB50
    // 0x800091A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002EB50(rdram, ctx);
        goto after_1;
    // 0x800091A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800091AC: j           L_800091C4
    // 0x800091B0: nop

        goto L_800091C4;
    // 0x800091B0: nop

L_800091B4:
    // 0x800091B4: jal         0x8002EB34
    // 0x800091B8: addu        $a0, $t6, $zero
    ctx->r4 = ADD32(ctx->r14, 0);
    func_8002EB34(rdram, ctx);
        goto after_2;
    // 0x800091B8: addu        $a0, $t6, $zero
    ctx->r4 = ADD32(ctx->r14, 0);
    after_2:
    // 0x800091BC: jal         0x8002EB34
    // 0x800091C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002EB34(rdram, ctx);
        goto after_3;
    // 0x800091C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
L_800091C4:
    // 0x800091C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800091C8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800091CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800091D0: jr          $ra
    // 0x800091D4: nop

    return;
    // 0x800091D4: nop

;}
RECOMP_FUNC void func_800091D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800091D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800091DC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800091E0: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x800091E4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800091E8: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x800091EC: beq         $v0, $zero, L_800091FC
    if (ctx->r2 == 0) {
        // 0x800091F0: nop
    
            goto L_800091FC;
    }
    // 0x800091F0: nop

    // 0x800091F4: jal         0x80008EF0
    // 0x800091F8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80008EF0(rdram, ctx);
        goto after_0;
    // 0x800091F8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_0:
L_800091FC:
    // 0x800091FC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80009200: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80009204: jr          $ra
    // 0x80009208: nop

    return;
    // 0x80009208: nop

;}
RECOMP_FUNC void func_8000920C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000920C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80009210: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80009214: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80009218: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000921C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80009220: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80009224: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80009228: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000922C: jal         0x80008DA8
    // 0x80009230: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80008DA8(rdram, ctx);
        goto after_0;
    // 0x80009230: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80009234: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80009238: addiu       $a0, $a0, 0x3D50
    ctx->r4 = ADD32(ctx->r4, 0X3D50);
    // 0x8000923C: jal         0x8003DBCC
    // 0x80009240: nop

    func_8003DBCC(rdram, ctx);
        goto after_1;
    // 0x80009240: nop

    after_1:
    // 0x80009244: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x80009248: lhu         $s5, 0x4($s4)
    ctx->r21 = MEM_HU(ctx->r20, 0X4);
    // 0x8000924C: andi        $v0, $s5, 0xFFFF
    ctx->r2 = ctx->r21 & 0XFFFF;
    // 0x80009250: beq         $v0, $zero, L_80009368
    if (ctx->r2 == 0) {
        // 0x80009254: addiu       $s4, $s4, 0x10
        ctx->r20 = ADD32(ctx->r20, 0X10);
            goto L_80009368;
    }
    // 0x80009254: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // 0x80009258: sltiu       $v0, $v0, 0x7
    ctx->r2 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x8000925C: beql        $v0, $zero, L_80009264
    if (ctx->r2 == 0) {
        // 0x80009260: addiu       $s5, $zero, 0x6
        ctx->r21 = ADD32(0, 0X6);
            goto L_80009264;
    }
    goto skip_0;
    // 0x80009260: addiu       $s5, $zero, 0x6
    ctx->r21 = ADD32(0, 0X6);
    skip_0:
L_80009264:
    // 0x80009264: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80009268: addiu       $s3, $s3, -0x2048
    ctx->r19 = ADD32(ctx->r19, -0X2048);
    // 0x8000926C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80009270: sh          $s5, -0x74F0($at)
    MEM_H(-0X74F0, ctx->r1) = ctx->r21;
    // 0x80009274: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80009278: addiu       $s2, $s3, 0x6
    ctx->r18 = ADD32(ctx->r19, 0X6);
    // 0x8000927C: addiu       $s1, $s4, 0xC
    ctx->r17 = ADD32(ctx->r20, 0XC);
L_80009280:
    // 0x80009280: jal         0x800306EC
    // 0x80009284: nop

    func_800306EC(rdram, ctx);
        goto after_2;
    // 0x80009284: nop

    after_2:
    // 0x80009288: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8000928C: sw          $v0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r2;
    // 0x80009290: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x80009294: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x80009298: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000929C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800092A0: sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // 0x800092A4: sh          $s6, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r22;
    // 0x800092A8: lhu         $v0, -0x8($s1)
    ctx->r2 = MEM_HU(ctx->r17, -0X8);
    // 0x800092AC: jal         0x80023E44
    // 0x800092B0: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    func_80023E44(rdram, ctx);
        goto after_3;
    // 0x800092B0: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    after_3:
    // 0x800092B4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800092B8: sw          $s0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r16;
    // 0x800092BC: sw          $s3, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r19;
    // 0x800092C0: lhu         $v0, -0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, -0X6);
    // 0x800092C4: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    // 0x800092C8: lhu         $v0, -0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, -0X4);
    // 0x800092CC: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // 0x800092D0: lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X22);
    // 0x800092D4: lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, -0X2);
    // 0x800092D8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800092DC: sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    // 0x800092E0: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x800092E4: addiu       $v0, $zero, 0x713
    ctx->r2 = ADD32(0, 0X713);
    // 0x800092E8: sh          $v0, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r2;
    // 0x800092EC: sh          $v1, 0x80($s0)
    MEM_H(0X80, ctx->r16) = ctx->r3;
    // 0x800092F0: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x800092F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800092F8: bne         $v1, $v0, L_80009314
    if (ctx->r3 != ctx->r2) {
        // 0x800092FC: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80009314;
    }
    // 0x800092FC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80009300: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80009304: jal         0x80001414
    // 0x80009308: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_80001414(rdram, ctx);
        goto after_4;
    // 0x80009308: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_4:
    // 0x8000930C: j           L_80009318
    // 0x80009310: sh          $v0, 0x16($s2)
    MEM_H(0X16, ctx->r18) = ctx->r2;
        goto L_80009318;
    // 0x80009310: sh          $v0, 0x16($s2)
    MEM_H(0X16, ctx->r18) = ctx->r2;
L_80009314:
    // 0x80009314: sh          $a0, 0x16($s2)
    MEM_H(0X16, ctx->r18) = ctx->r4;
L_80009318:
    // 0x80009318: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x8000931C: addiu       $v0, $v0, -0x11
    ctx->r2 = ADD32(ctx->r2, -0X11);
    // 0x80009320: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80009324: beql        $v0, $zero, L_80009340
    if (ctx->r2 == 0) {
        // 0x80009328: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80009340;
    }
    goto skip_1;
    // 0x80009328: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    skip_1:
    // 0x8000932C: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    // 0x80009330: jal         0x80008E28
    // 0x80009334: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_80008E28(rdram, ctx);
        goto after_5;
    // 0x80009334: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_5:
    // 0x80009338: j           L_8000934C
    // 0x8000933C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
        goto L_8000934C;
    // 0x8000933C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_80009340:
    // 0x80009340: lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18);
    // 0x80009344: addiu       $v0, $v0, 0xF23
    ctx->r2 = ADD32(ctx->r2, 0XF23);
    // 0x80009348: sh          $v0, 0x80($s0)
    MEM_H(0X80, ctx->r16) = ctx->r2;
L_8000934C:
    // 0x8000934C: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // 0x80009350: addiu       $s2, $s2, 0x78
    ctx->r18 = ADD32(ctx->r18, 0X78);
    // 0x80009354: addiu       $v0, $s5, -0x1
    ctx->r2 = ADD32(ctx->r21, -0X1);
    // 0x80009358: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x8000935C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80009360: bne         $v0, $zero, L_80009280
    if (ctx->r2 != 0) {
        // 0x80009364: addiu       $s3, $s3, 0x78
        ctx->r19 = ADD32(ctx->r19, 0X78);
            goto L_80009280;
    }
    // 0x80009364: addiu       $s3, $s3, 0x78
    ctx->r19 = ADD32(ctx->r19, 0X78);
L_80009368:
    // 0x80009368: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000936C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80009370: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80009374: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80009378: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000937C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80009380: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80009384: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80009388: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000938C: jr          $ra
    // 0x80009390: nop

    return;
    // 0x80009390: nop

;}
RECOMP_FUNC void func_80009394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009394: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009398: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8000939C: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x800093A0: lhu         $s2, -0x74F0($s2)
    ctx->r18 = MEM_HU(ctx->r18, -0X74F0);
    // 0x800093A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800093A8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800093AC: beq         $s2, $zero, L_80009424
    if (ctx->r18 == 0) {
        // 0x800093B0: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80009424;
    }
    // 0x800093B0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800093B4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800093B8: addiu       $s1, $s1, -0x2048
    ctx->r17 = ADD32(ctx->r17, -0X2048);
    // 0x800093BC: addiu       $s0, $s1, 0x74
    ctx->r16 = ADD32(ctx->r17, 0X74);
L_800093C0:
    // 0x800093C0: lw          $a0, -0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X24);
    // 0x800093C4: beq         $a0, $zero, L_800093D4
    if (ctx->r4 == 0) {
        // 0x800093C8: nop
    
            goto L_800093D4;
    }
    // 0x800093C8: nop

    // 0x800093CC: jal         0x80024764
    // 0x800093D0: nop

    func_80024764(rdram, ctx);
        goto after_0;
    // 0x800093D0: nop

    after_0:
L_800093D4:
    // 0x800093D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800093D8: beq         $a0, $zero, L_800093F0
    if (ctx->r4 == 0) {
        // 0x800093DC: nop
    
            goto L_800093F0;
    }
    // 0x800093DC: nop

    // 0x800093E0: jal         0x80024764
    // 0x800093E4: nop

    func_80024764(rdram, ctx);
        goto after_1;
    // 0x800093E4: nop

    after_1:
    // 0x800093E8: jal         0x80009448
    // 0x800093EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80009448(rdram, ctx);
        goto after_2;
    // 0x800093EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
L_800093F0:
    // 0x800093F0: lw          $a0, -0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X4);
    // 0x800093F4: beql        $a0, $zero, L_80009410
    if (ctx->r4 == 0) {
        // 0x800093F8: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_80009410;
    }
    goto skip_0;
    // 0x800093F8: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    skip_0:
    // 0x800093FC: jal         0x80024764
    // 0x80009400: nop

    func_80024764(rdram, ctx);
        goto after_3;
    // 0x80009400: nop

    after_3:
    // 0x80009404: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80009408: jal         0x80024764
    // 0x8000940C: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    func_80024764(rdram, ctx);
        goto after_4;
    // 0x8000940C: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    after_4:
L_80009410:
    // 0x80009410: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x80009414: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80009418: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000941C: bne         $v0, $zero, L_800093C0
    if (ctx->r2 != 0) {
        // 0x80009420: addiu       $s1, $s1, 0x78
        ctx->r17 = ADD32(ctx->r17, 0X78);
            goto L_800093C0;
    }
    // 0x80009420: addiu       $s1, $s1, 0x78
    ctx->r17 = ADD32(ctx->r17, 0X78);
L_80009424:
    // 0x80009424: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80009428: sh          $zero, -0x74F0($at)
    MEM_H(-0X74F0, ctx->r1) = 0;
    // 0x8000942C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80009430: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80009434: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80009438: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000943C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009440: jr          $ra
    // 0x80009444: nop

    return;
    // 0x80009444: nop

;}
RECOMP_FUNC void func_80009448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000944C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80009450: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80009454: jal         0x8007DEC0
    // 0x80009458: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    func_8007DEC0(rdram, ctx);
        goto after_0;
    // 0x80009458: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_0:
    // 0x8000945C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80009460: sh          $zero, -0x74F0($at)
    MEM_H(-0X74F0, ctx->r1) = 0;
    // 0x80009464: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80009468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000946C: jr          $ra
    // 0x80009470: nop

    return;
    // 0x80009470: nop

;}
RECOMP_FUNC void func_80009474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009474: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80009478: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8000947C: lui         $s4, 0x8016
    ctx->r20 = S32(0X8016 << 16);
    // 0x80009480: lhu         $s4, -0x74F0($s4)
    ctx->r20 = MEM_HU(ctx->r20, -0X74F0);
    // 0x80009484: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80009488: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8000948C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80009490: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80009494: addiu       $s1, $s1, -0x2048
    ctx->r17 = ADD32(ctx->r17, -0X2048);
    // 0x80009498: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8000949C: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800094A0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800094A4: beq         $s4, $zero, L_80009628
    if (ctx->r20 == 0) {
        // 0x800094A8: sw          $s2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r18;
            goto L_80009628;
    }
    // 0x800094A8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800094AC: addiu       $s5, $zero, 0x1E
    ctx->r21 = ADD32(0, 0X1E);
    // 0x800094B0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800094B4: addiu       $s2, $s1, 0x8
    ctx->r18 = ADD32(ctx->r17, 0X8);
L_800094B8:
    // 0x800094B8: lhu         $a0, -0x2($s2)
    ctx->r4 = MEM_HU(ctx->r18, -0X2);
    // 0x800094BC: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800094C0: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x800094C4: xori        $v1, $a1, 0x31
    ctx->r3 = ctx->r5 ^ 0X31;
    // 0x800094C8: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800094CC: xori        $v0, $a1, 0x13
    ctx->r2 = ctx->r5 ^ 0X13;
    // 0x800094D0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800094D4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800094D8: bnel        $v1, $zero, L_800094F0
    if (ctx->r3 != 0) {
        // 0x800094DC: addu        $a0, $a2, $zero
        ctx->r4 = ADD32(ctx->r6, 0);
            goto L_800094F0;
    }
    goto skip_0;
    // 0x800094DC: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    skip_0:
    // 0x800094E0: addiu       $v0, $a0, -0x14
    ctx->r2 = ADD32(ctx->r4, -0X14);
    // 0x800094E4: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800094E8: beq         $v0, $zero, L_80009508
    if (ctx->r2 == 0) {
        // 0x800094EC: addu        $a0, $a2, $zero
        ctx->r4 = ADD32(ctx->r6, 0);
            goto L_80009508;
    }
    // 0x800094EC: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
L_800094F0:
    // 0x800094F0: jal         0x800295C8
    // 0x800094F4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800295C8(rdram, ctx);
        goto after_0;
    // 0x800094F4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800094F8: beq         $v0, $zero, L_80009614
    if (ctx->r2 == 0) {
        // 0x800094FC: addiu       $s2, $s2, 0x78
        ctx->r18 = ADD32(ctx->r18, 0X78);
            goto L_80009614;
    }
    // 0x800094FC: addiu       $s2, $s2, 0x78
    ctx->r18 = ADD32(ctx->r18, 0X78);
    // 0x80009500: j           L_800095E4
    // 0x80009504: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_800095E4;
    // 0x80009504: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80009508:
    // 0x80009508: lhu         $v0, 0x6C($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6C);
    // 0x8000950C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80009510: bnel        $v0, $zero, L_80009614
    if (ctx->r2 != 0) {
        // 0x80009514: addiu       $s2, $s2, 0x78
        ctx->r18 = ADD32(ctx->r18, 0X78);
            goto L_80009614;
    }
    goto skip_1;
    // 0x80009514: addiu       $s2, $s2, 0x78
    ctx->r18 = ADD32(ctx->r18, 0X78);
    skip_1:
    // 0x80009518: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x8000951C: xori        $v1, $a0, 0x32
    ctx->r3 = ctx->r4 ^ 0X32;
    // 0x80009520: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80009524: xori        $v0, $a0, 0x2
    ctx->r2 = ctx->r4 ^ 0X2;
    // 0x80009528: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8000952C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80009530: bnel        $v1, $zero, L_80009544
    if (ctx->r3 != 0) {
        // 0x80009534: addiu       $v1, $a1, -0x3
        ctx->r3 = ADD32(ctx->r5, -0X3);
            goto L_80009544;
    }
    goto skip_2;
    // 0x80009534: addiu       $v1, $a1, -0x3
    ctx->r3 = ADD32(ctx->r5, -0X3);
    skip_2:
    // 0x80009538: bnel        $a0, $s5, L_80009614
    if (ctx->r4 != ctx->r21) {
        // 0x8000953C: addiu       $s2, $s2, 0x78
        ctx->r18 = ADD32(ctx->r18, 0X78);
            goto L_80009614;
    }
    goto skip_3;
    // 0x8000953C: addiu       $s2, $s2, 0x78
    ctx->r18 = ADD32(ctx->r18, 0X78);
    skip_3:
    // 0x80009540: addiu       $v1, $a1, -0x3
    ctx->r3 = ADD32(ctx->r5, -0X3);
L_80009544:
    // 0x80009544: sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // 0x80009548: beq         $v0, $zero, L_80009610
    if (ctx->r2 == 0) {
        // 0x8000954C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80009610;
    }
    // 0x8000954C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80009550: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80009554: addu        $at, $at, $v0
    gpr jr_addend_8000955C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80009558: lw          $v0, 0x3628($at)
    ctx->r2 = ADD32(ctx->r1, 0X3628);
    // 0x8000955C: jr          $v0
    // 0x80009560: nop

    switch (jr_addend_8000955C >> 2) {
        case 0: goto L_800095C4; break;
        case 1: goto L_80009610; break;
        case 2: goto L_80009610; break;
        case 3: goto L_80009610; break;
        case 4: goto L_80009610; break;
        case 5: goto L_80009610; break;
        case 6: goto L_80009610; break;
        case 7: goto L_80009610; break;
        case 8: goto L_80009610; break;
        case 9: goto L_80009610; break;
        case 10: goto L_80009610; break;
        case 11: goto L_80009610; break;
        case 12: goto L_800095C4; break;
        case 13: goto L_80009610; break;
        case 14: goto L_800095F4; break;
        case 15: goto L_800095F4; break;
        case 16: goto L_80009610; break;
        case 17: goto L_80009610; break;
        case 18: goto L_80009610; break;
        case 19: goto L_80009610; break;
        case 20: goto L_80009610; break;
        case 21: goto L_80009610; break;
        case 22: goto L_80009610; break;
        case 23: goto L_80009610; break;
        case 24: goto L_80009610; break;
        case 25: goto L_80009610; break;
        case 26: goto L_80009610; break;
        case 27: goto L_80009610; break;
        case 28: goto L_80009610; break;
        case 29: goto L_80009610; break;
        case 30: goto L_80009610; break;
        case 31: goto L_80009610; break;
        case 32: goto L_80009610; break;
        case 33: goto L_80009610; break;
        case 34: goto L_80009610; break;
        case 35: goto L_80009610; break;
        case 36: goto L_80009610; break;
        case 37: goto L_80009610; break;
        case 38: goto L_80009610; break;
        case 39: goto L_80009610; break;
        case 40: goto L_80009610; break;
        case 41: goto L_80009610; break;
        case 42: goto L_80009610; break;
        case 43: goto L_80009610; break;
        case 44: goto L_80009610; break;
        case 45: goto L_80009610; break;
        case 46: goto L_80009610; break;
        case 47: goto L_80009610; break;
        case 48: goto L_80009610; break;
        case 49: goto L_80009610; break;
        case 50: goto L_80009610; break;
        case 51: goto L_80009610; break;
        case 52: goto L_80009610; break;
        case 53: goto L_80009610; break;
        case 54: goto L_80009610; break;
        case 55: goto L_80009610; break;
        case 56: goto L_800095C4; break;
        case 57: goto L_800095C4; break;
        case 58: goto L_80009610; break;
        case 59: goto L_80009564; break;
        case 60: goto L_80009564; break;
        case 61: goto L_80009610; break;
        case 62: goto L_80009610; break;
        case 63: goto L_800095C4; break;
        default: switch_error(__func__, 0x8000955C, 0x80093628);
    }
    // 0x80009560: nop

L_80009564:
    // 0x80009564: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x80009568: beq         $v0, $s5, L_800095C4
    if (ctx->r2 == ctx->r21) {
        // 0x8000956C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800095C4;
    }
    // 0x8000956C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80009570: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80009574: jal         0x80009720
    // 0x80009578: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    func_80009720(rdram, ctx);
        goto after_1;
    // 0x80009578: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_1:
    // 0x8000957C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80009580: bnel        $v0, $s3, L_80009614
    if (ctx->r2 != ctx->r19) {
        // 0x80009584: addiu       $s2, $s2, 0x78
        ctx->r18 = ADD32(ctx->r18, 0X78);
            goto L_80009614;
    }
    goto skip_4;
    // 0x80009584: addiu       $s2, $s2, 0x78
    ctx->r18 = ADD32(ctx->r18, 0X78);
    skip_4:
    // 0x80009588: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x8000958C: bne         $v0, $s5, L_80009628
    if (ctx->r2 != ctx->r21) {
        // 0x80009590: nop
    
            goto L_80009628;
    }
    // 0x80009590: nop

    // 0x80009594: jal         0x8002614C
    // 0x80009598: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002614C(rdram, ctx);
        goto after_2;
    // 0x80009598: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8000959C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800095A0: jal         0x8003BB8C
    // 0x800095A4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003BB8C(rdram, ctx);
        goto after_3;
    // 0x800095A4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800095A8: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x800095AC: lh          $v1, 0x18($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X18);
    // 0x800095B0: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x800095B4: bne         $v1, $v0, L_80009628
    if (ctx->r3 != ctx->r2) {
        // 0x800095B8: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80009628;
    }
    // 0x800095B8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800095BC: j           L_80009628
    // 0x800095C0: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
        goto L_80009628;
    // 0x800095C0: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
L_800095C4:
    // 0x800095C4: lh          $a0, 0x120($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X120);
    // 0x800095C8: lh          $a1, 0x122($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X122);
    // 0x800095CC: jal         0x80009A74
    // 0x800095D0: nop

    func_80009A74(rdram, ctx);
        goto after_4;
    // 0x800095D0: nop

    after_4:
    // 0x800095D4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800095D8: bne         $v0, $s3, L_80009614
    if (ctx->r2 != ctx->r19) {
        // 0x800095DC: addiu       $s2, $s2, 0x78
        ctx->r18 = ADD32(ctx->r18, 0X78);
            goto L_80009614;
    }
    // 0x800095DC: addiu       $s2, $s2, 0x78
    ctx->r18 = ADD32(ctx->r18, 0X78);
    // 0x800095E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800095E4:
    // 0x800095E4: jal         0x80009B80
    // 0x800095E8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80009B80(rdram, ctx);
        goto after_5;
    // 0x800095E8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_5:
    // 0x800095EC: j           L_80009628
    // 0x800095F0: nop

        goto L_80009628;
    // 0x800095F0: nop

L_800095F4:
    // 0x800095F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800095F8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800095FC: jal         0x80009720
    // 0x80009600: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_80009720(rdram, ctx);
        goto after_6;
    // 0x80009600: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_6:
    // 0x80009604: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80009608: beq         $v0, $s3, L_80009628
    if (ctx->r2 == ctx->r19) {
        // 0x8000960C: nop
    
            goto L_80009628;
    }
    // 0x8000960C: nop

L_80009610:
    // 0x80009610: addiu       $s2, $s2, 0x78
    ctx->r18 = ADD32(ctx->r18, 0X78);
L_80009614:
    // 0x80009614: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // 0x80009618: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x8000961C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80009620: bne         $v0, $zero, L_800094B8
    if (ctx->r2 != 0) {
        // 0x80009624: addiu       $s1, $s1, 0x78
        ctx->r17 = ADD32(ctx->r17, 0X78);
            goto L_800094B8;
    }
    // 0x80009624: addiu       $s1, $s1, 0x78
    ctx->r17 = ADD32(ctx->r17, 0X78);
L_80009628:
    // 0x80009628: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8000962C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80009630: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80009634: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80009638: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8000963C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80009640: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80009644: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80009648: jr          $ra
    // 0x8000964C: nop

    return;
    // 0x8000964C: nop

;}
RECOMP_FUNC void func_80009650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009650: lh          $v0, 0x14($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X14);
    // 0x80009654: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80009658: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x8000965C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80009660: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80009664: beq         $v0, $zero, L_80009680
    if (ctx->r2 == 0) {
                func_80009668(rdram, ctx); return; // was goto L_80009680
    }
;}
RECOMP_FUNC void func_80009668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009668: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000966C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80009670: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x80009674: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80009678: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000967C: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x80009680: lhu         $v0, 0x32($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X32);
    // 0x80009684: subu        $v1, $a3, $a0
    ctx->r3 = SUB32(ctx->r7, ctx->r4);
    // 0x80009688: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8000968C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80009690: sra         $a0, $v0, 17
    ctx->r4 = S32(SIGNED(ctx->r2) >> 17);
    // 0x80009694: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80009698: bltzl       $v0, L_800096B4
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000969C: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_800096B4;
    }
    goto skip_0;
    // 0x8000969C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_0:
    // 0x800096A0: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800096A4: beq         $v0, $zero, L_800096C0
    if (ctx->r2 == 0) {
        // 0x800096A8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800096C0;
    }
    // 0x800096A8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800096AC: j           L_80009714
    // 0x800096B0: nop

        goto L_80009714;
    // 0x800096B0: nop

L_800096B4:
    // 0x800096B4: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800096B8: bne         $v0, $zero, L_80009714
    if (ctx->r2 != 0) {
        // 0x800096BC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009714;
    }
    // 0x800096BC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800096C0:
    // 0x800096C0: lhu         $v0, 0x30($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X30);
    // 0x800096C4: lhu         $a3, 0x18($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X18);
    // 0x800096C8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800096CC: sra         $v0, $v0, 18
    ctx->r2 = S32(SIGNED(ctx->r2) >> 18);
    // 0x800096D0: subu        $v1, $a3, $v0
    ctx->r3 = SUB32(ctx->r7, ctx->r2);
    // 0x800096D4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800096D8: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x800096DC: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x800096E0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800096E4: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800096E8: bltzl       $v0, L_80009704
    if (SIGNED(ctx->r2) < 0) {
        // 0x800096EC: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_80009704;
    }
    goto skip_1;
    // 0x800096EC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_1:
    // 0x800096F0: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800096F4: beq         $v0, $zero, L_80009714
    if (ctx->r2 == 0) {
        // 0x800096F8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80009714;
    }
    // 0x800096F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800096FC: j           L_80009714
    // 0x80009700: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80009714;
    // 0x80009700: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80009704:
    // 0x80009704: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009708: bne         $v0, $zero, L_80009714
    if (ctx->r2 != 0) {
        // 0x8000970C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009714;
    }
    // 0x8000970C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80009710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80009714:
    // 0x80009714: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80009718: jr          $ra
    // 0x8000971C: nop

    return;
    // 0x8000971C: nop

;}
RECOMP_FUNC void func_80009720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009720: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80009724: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80009728: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8000972C: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80009730: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80009734: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80009738: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x8000973C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80009740: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80009744: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80009748: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8000974C: lhu         $s2, 0x120($s0)
    ctx->r18 = MEM_HU(ctx->r16, 0X120);
    // 0x80009750: lhu         $s3, 0x122($s0)
    ctx->r19 = MEM_HU(ctx->r16, 0X122);
    // 0x80009754: jal         0x8000ABD4
    // 0x80009758: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    func_8000ABD4(rdram, ctx);
        goto after_0;
    // 0x80009758: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    after_0:
    // 0x8000975C: lhu         $a0, 0x3E($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X3E);
    // 0x80009760: lh          $v0, 0x3E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X3E);
    // 0x80009764: sll         $v1, $s2, 16
    ctx->r3 = S32(ctx->r18 << 16);
    // 0x80009768: sra         $a1, $v1, 16
    ctx->r5 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000976C: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009770: beq         $v0, $zero, L_800097B0
    if (ctx->r2 == 0) {
        // 0x80009774: addiu       $v0, $a0, -0x4
        ctx->r2 = ADD32(ctx->r4, -0X4);
            goto L_800097B0;
    }
    // 0x80009774: addiu       $v0, $a0, -0x4
    ctx->r2 = ADD32(ctx->r4, -0X4);
    // 0x80009778: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000977C: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80009780: slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80009784: beq         $v0, $zero, L_800097B0
    if (ctx->r2 == 0) {
        // 0x80009788: nop
    
            goto L_800097B0;
    }
    // 0x80009788: nop

    // 0x8000978C: lhu         $v0, 0xDE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XDE);
    // 0x80009790: beq         $v0, $zero, L_800098AC
    if (ctx->r2 == 0) {
        // 0x80009794: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800098AC;
    }
    // 0x80009794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80009798: lhu         $v1, 0xEA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XEA);
    // 0x8000979C: bne         $v1, $v0, L_800098AC
    if (ctx->r3 != ctx->r2) {
        // 0x800097A0: addiu       $v0, $a0, -0x19
        ctx->r2 = ADD32(ctx->r4, -0X19);
            goto L_800098AC;
    }
    // 0x800097A0: addiu       $v0, $a0, -0x19
    ctx->r2 = ADD32(ctx->r4, -0X19);
    // 0x800097A4: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800097A8: bne         $v0, $zero, L_800098AC
    if (ctx->r2 != 0) {
        // 0x800097AC: nop
    
            goto L_800098AC;
    }
    // 0x800097AC: nop

L_800097B0:
    // 0x800097B0: lhu         $a0, 0x40($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X40);
    // 0x800097B4: lh          $v0, 0x40($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X40);
    // 0x800097B8: sll         $v1, $s2, 16
    ctx->r3 = S32(ctx->r18 << 16);
    // 0x800097BC: sra         $a1, $v1, 16
    ctx->r5 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800097C0: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800097C4: beq         $v0, $zero, L_80009804
    if (ctx->r2 == 0) {
        // 0x800097C8: addiu       $v0, $a0, 0x4
        ctx->r2 = ADD32(ctx->r4, 0X4);
            goto L_80009804;
    }
    // 0x800097C8: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x800097CC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800097D0: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800097D4: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800097D8: beq         $v0, $zero, L_80009804
    if (ctx->r2 == 0) {
        // 0x800097DC: nop
    
            goto L_80009804;
    }
    // 0x800097DC: nop

    // 0x800097E0: lhu         $v0, 0xDE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XDE);
    // 0x800097E4: beq         $v0, $zero, L_800098AC
    if (ctx->r2 == 0) {
        // 0x800097E8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800098AC;
    }
    // 0x800097E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800097EC: lhu         $v1, 0xEA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XEA);
    // 0x800097F0: bne         $v1, $v0, L_800098AC
    if (ctx->r3 != ctx->r2) {
        // 0x800097F4: addiu       $v0, $a0, 0x19
        ctx->r2 = ADD32(ctx->r4, 0X19);
            goto L_800098AC;
    }
    // 0x800097F4: addiu       $v0, $a0, 0x19
    ctx->r2 = ADD32(ctx->r4, 0X19);
    // 0x800097F8: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800097FC: bne         $v0, $zero, L_800098AC
    if (ctx->r2 != 0) {
        // 0x80009800: nop
    
            goto L_800098AC;
    }
    // 0x80009800: nop

L_80009804:
    // 0x80009804: lhu         $a0, 0x44($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X44);
    // 0x80009808: lh          $v0, 0x44($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X44);
    // 0x8000980C: sll         $v1, $s3, 16
    ctx->r3 = S32(ctx->r19 << 16);
    // 0x80009810: sra         $a1, $v1, 16
    ctx->r5 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80009814: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009818: beq         $v0, $zero, L_80009858
    if (ctx->r2 == 0) {
        // 0x8000981C: addiu       $v0, $a0, -0x4
        ctx->r2 = ADD32(ctx->r4, -0X4);
            goto L_80009858;
    }
    // 0x8000981C: addiu       $v0, $a0, -0x4
    ctx->r2 = ADD32(ctx->r4, -0X4);
    // 0x80009820: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80009824: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80009828: slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000982C: beq         $v0, $zero, L_80009858
    if (ctx->r2 == 0) {
        // 0x80009830: nop
    
            goto L_80009858;
    }
    // 0x80009830: nop

    // 0x80009834: lhu         $v0, 0xDE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XDE);
    // 0x80009838: beq         $v0, $zero, L_800098AC
    if (ctx->r2 == 0) {
        // 0x8000983C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800098AC;
    }
    // 0x8000983C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80009840: lhu         $v1, 0xEA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XEA);
    // 0x80009844: bne         $v1, $v0, L_800098AC
    if (ctx->r3 != ctx->r2) {
        // 0x80009848: addiu       $v0, $a0, -0x19
        ctx->r2 = ADD32(ctx->r4, -0X19);
            goto L_800098AC;
    }
    // 0x80009848: addiu       $v0, $a0, -0x19
    ctx->r2 = ADD32(ctx->r4, -0X19);
    // 0x8000984C: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009850: bne         $v0, $zero, L_800098AC
    if (ctx->r2 != 0) {
        // 0x80009854: nop
    
            goto L_800098AC;
    }
    // 0x80009854: nop

L_80009858:
    // 0x80009858: lhu         $a0, 0x42($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X42);
    // 0x8000985C: lh          $v0, 0x42($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X42);
    // 0x80009860: sll         $v1, $s3, 16
    ctx->r3 = S32(ctx->r19 << 16);
    // 0x80009864: sra         $a1, $v1, 16
    ctx->r5 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80009868: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000986C: beq         $v0, $zero, L_80009A40
    if (ctx->r2 == 0) {
        // 0x80009870: addiu       $v0, $a0, 0x4
        ctx->r2 = ADD32(ctx->r4, 0X4);
            goto L_80009A40;
    }
    // 0x80009870: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x80009874: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80009878: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000987C: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80009880: beql        $v0, $zero, L_80009A44
    if (ctx->r2 == 0) {
        // 0x80009884: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80009A44;
    }
    goto skip_0;
    // 0x80009884: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x80009888: lhu         $v0, 0xDE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XDE);
    // 0x8000988C: beq         $v0, $zero, L_800098AC
    if (ctx->r2 == 0) {
        // 0x80009890: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800098AC;
    }
    // 0x80009890: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80009894: lhu         $v1, 0xEA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XEA);
    // 0x80009898: bne         $v1, $v0, L_800098AC
    if (ctx->r3 != ctx->r2) {
        // 0x8000989C: addiu       $v0, $a0, 0x19
        ctx->r2 = ADD32(ctx->r4, 0X19);
            goto L_800098AC;
    }
    // 0x8000989C: addiu       $v0, $a0, 0x19
    ctx->r2 = ADD32(ctx->r4, 0X19);
    // 0x800098A0: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800098A4: beq         $v0, $zero, L_80009A50
    if (ctx->r2 == 0) {
        // 0x800098A8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80009A50;
    }
    // 0x800098A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800098AC:
    // 0x800098AC: lhu         $a0, 0x46($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X46);
    // 0x800098B0: lh          $v0, 0x46($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X46);
    // 0x800098B4: sll         $v1, $s2, 16
    ctx->r3 = S32(ctx->r18 << 16);
    // 0x800098B8: sra         $a1, $v1, 16
    ctx->r5 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800098BC: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800098C0: beq         $v0, $zero, L_80009904
    if (ctx->r2 == 0) {
        // 0x800098C4: addiu       $v0, $a0, -0x4
        ctx->r2 = ADD32(ctx->r4, -0X4);
            goto L_80009904;
    }
    // 0x800098C4: addiu       $v0, $a0, -0x4
    ctx->r2 = ADD32(ctx->r4, -0X4);
    // 0x800098C8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800098CC: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800098D0: slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800098D4: beq         $v0, $zero, L_80009904
    if (ctx->r2 == 0) {
        // 0x800098D8: nop
    
            goto L_80009904;
    }
    // 0x800098D8: nop

    // 0x800098DC: lhu         $v0, 0xDE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XDE);
    // 0x800098E0: beq         $v0, $zero, L_80009A0C
    if (ctx->r2 == 0) {
        // 0x800098E4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80009A0C;
    }
    // 0x800098E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800098E8: lhu         $v1, 0xEA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XEA);
    // 0x800098EC: bne         $v1, $v0, L_80009A50
    if (ctx->r3 != ctx->r2) {
        // 0x800098F0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009A50;
    }
    // 0x800098F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800098F4: addiu       $v0, $a0, -0x19
    ctx->r2 = ADD32(ctx->r4, -0X19);
    // 0x800098F8: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800098FC: bne         $v0, $zero, L_80009A50
    if (ctx->r2 != 0) {
        // 0x80009900: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009A50;
    }
    // 0x80009900: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80009904:
    // 0x80009904: lhu         $a0, 0x48($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X48);
    // 0x80009908: lh          $v0, 0x48($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X48);
    // 0x8000990C: sll         $v1, $s2, 16
    ctx->r3 = S32(ctx->r18 << 16);
    // 0x80009910: sra         $a1, $v1, 16
    ctx->r5 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80009914: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80009918: beq         $v0, $zero, L_8000995C
    if (ctx->r2 == 0) {
        // 0x8000991C: addiu       $v0, $a0, 0x4
        ctx->r2 = ADD32(ctx->r4, 0X4);
            goto L_8000995C;
    }
    // 0x8000991C: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x80009920: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80009924: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80009928: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000992C: beq         $v0, $zero, L_8000995C
    if (ctx->r2 == 0) {
        // 0x80009930: nop
    
            goto L_8000995C;
    }
    // 0x80009930: nop

    // 0x80009934: lhu         $v0, 0xDE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XDE);
    // 0x80009938: beq         $v0, $zero, L_80009A0C
    if (ctx->r2 == 0) {
        // 0x8000993C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80009A0C;
    }
    // 0x8000993C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80009940: lhu         $v1, 0xEA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XEA);
    // 0x80009944: bne         $v1, $v0, L_80009A50
    if (ctx->r3 != ctx->r2) {
        // 0x80009948: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009A50;
    }
    // 0x80009948: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8000994C: addiu       $v0, $a0, 0x19
    ctx->r2 = ADD32(ctx->r4, 0X19);
    // 0x80009950: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80009954: bne         $v0, $zero, L_80009A50
    if (ctx->r2 != 0) {
        // 0x80009958: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009A50;
    }
    // 0x80009958: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8000995C:
    // 0x8000995C: lhu         $a0, 0x4C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4C);
    // 0x80009960: lh          $v0, 0x4C($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4C);
    // 0x80009964: sll         $v1, $s3, 16
    ctx->r3 = S32(ctx->r19 << 16);
    // 0x80009968: sra         $a1, $v1, 16
    ctx->r5 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000996C: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009970: beq         $v0, $zero, L_800099B4
    if (ctx->r2 == 0) {
        // 0x80009974: addiu       $v0, $a0, -0x4
        ctx->r2 = ADD32(ctx->r4, -0X4);
            goto L_800099B4;
    }
    // 0x80009974: addiu       $v0, $a0, -0x4
    ctx->r2 = ADD32(ctx->r4, -0X4);
    // 0x80009978: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000997C: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80009980: slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80009984: beq         $v0, $zero, L_800099B4
    if (ctx->r2 == 0) {
        // 0x80009988: nop
    
            goto L_800099B4;
    }
    // 0x80009988: nop

    // 0x8000998C: lhu         $v0, 0xDE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XDE);
    // 0x80009990: beq         $v0, $zero, L_80009A0C
    if (ctx->r2 == 0) {
        // 0x80009994: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80009A0C;
    }
    // 0x80009994: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80009998: lhu         $v1, 0xEA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XEA);
    // 0x8000999C: bne         $v1, $v0, L_80009A50
    if (ctx->r3 != ctx->r2) {
        // 0x800099A0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009A50;
    }
    // 0x800099A0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800099A4: addiu       $v0, $a0, -0x19
    ctx->r2 = ADD32(ctx->r4, -0X19);
    // 0x800099A8: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800099AC: bne         $v0, $zero, L_80009A50
    if (ctx->r2 != 0) {
        // 0x800099B0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009A50;
    }
    // 0x800099B0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800099B4:
    // 0x800099B4: lhu         $a0, 0x4A($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4A);
    // 0x800099B8: lh          $v0, 0x4A($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4A);
    // 0x800099BC: sll         $v1, $s3, 16
    ctx->r3 = S32(ctx->r19 << 16);
    // 0x800099C0: sra         $a1, $v1, 16
    ctx->r5 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800099C4: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800099C8: beq         $v0, $zero, L_80009A14
    if (ctx->r2 == 0) {
        // 0x800099CC: addiu       $v0, $a0, 0x4
        ctx->r2 = ADD32(ctx->r4, 0X4);
            goto L_80009A14;
    }
    // 0x800099CC: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x800099D0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800099D4: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800099D8: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800099DC: beq         $v0, $zero, L_80009A14
    if (ctx->r2 == 0) {
        // 0x800099E0: nop
    
            goto L_80009A14;
    }
    // 0x800099E0: nop

    // 0x800099E4: lhu         $v0, 0xDE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XDE);
    // 0x800099E8: beq         $v0, $zero, L_80009A0C
    if (ctx->r2 == 0) {
        // 0x800099EC: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80009A0C;
    }
    // 0x800099EC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800099F0: lhu         $v1, 0xEA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XEA);
    // 0x800099F4: bne         $v1, $v0, L_80009A50
    if (ctx->r3 != ctx->r2) {
        // 0x800099F8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009A50;
    }
    // 0x800099F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800099FC: addiu       $v0, $a0, 0x19
    ctx->r2 = ADD32(ctx->r4, 0X19);
    // 0x80009A00: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80009A04: beq         $v0, $zero, L_80009A14
    if (ctx->r2 == 0) {
        // 0x80009A08: nop
    
            goto L_80009A14;
    }
    // 0x80009A08: nop

L_80009A0C:
    // 0x80009A0C: j           L_80009A50
    // 0x80009A10: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80009A50;
    // 0x80009A10: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80009A14:
    // 0x80009A14: lhu         $v0, 0x24($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X24);
    // 0x80009A18: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80009A1C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80009A20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80009A24: jal         0x8003C34C
    // 0x80009A28: sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    func_8003C34C(rdram, ctx);
        goto after_1;
    // 0x80009A28: sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    after_1:
    // 0x80009A2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80009A30: jal         0x80060F30
    // 0x80009A34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80060F30(rdram, ctx);
        goto after_2;
    // 0x80009A34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80009A38: j           L_80009A4C
    // 0x80009A3C: sh          $s4, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r20;
        goto L_80009A4C;
    // 0x80009A3C: sh          $s4, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r20;
L_80009A40:
    // 0x80009A40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80009A44:
    // 0x80009A44: jal         0x80009B80
    // 0x80009A48: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80009B80(rdram, ctx);
        goto after_3;
    // 0x80009A48: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
L_80009A4C:
    // 0x80009A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80009A50:
    // 0x80009A50: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80009A54: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80009A58: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80009A5C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80009A60: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80009A64: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80009A68: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80009A6C: jr          $ra
    // 0x80009A70: nop

    return;
    // 0x80009A70: nop

;}
RECOMP_FUNC void func_80009A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009A74: lh          $v0, 0x14($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X14);
    // 0x80009A78: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80009A7C: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x80009A80: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80009A84: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80009A88: beq         $v0, $zero, L_80009AA4
    if (ctx->r2 == 0) {
                func_80009A8C(rdram, ctx); return; // was goto L_80009AA4
    }
;}
RECOMP_FUNC void func_80009A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009A8C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80009A90: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80009A94: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x80009A98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80009A9C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80009AA0: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x80009AA4: lhu         $v0, 0x32($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X32);
    // 0x80009AA8: subu        $v1, $a3, $a0
    ctx->r3 = SUB32(ctx->r7, ctx->r4);
    // 0x80009AAC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80009AB0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80009AB4: sra         $a0, $v0, 17
    ctx->r4 = S32(SIGNED(ctx->r2) >> 17);
    // 0x80009AB8: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80009ABC: bltzl       $v0, L_80009AD8
    if (SIGNED(ctx->r2) < 0) {
        // 0x80009AC0: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_80009AD8;
    }
    goto skip_0;
    // 0x80009AC0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_0:
    // 0x80009AC4: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009AC8: beq         $v0, $zero, L_80009AE4
    if (ctx->r2 == 0) {
        // 0x80009ACC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009AE4;
    }
    // 0x80009ACC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80009AD0: j           L_80009B34
    // 0x80009AD4: nop

        goto L_80009B34;
    // 0x80009AD4: nop

L_80009AD8:
    // 0x80009AD8: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009ADC: bne         $v0, $zero, L_80009B34
    if (ctx->r2 != 0) {
        // 0x80009AE0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009B34;
    }
    // 0x80009AE0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80009AE4:
    // 0x80009AE4: lhu         $v1, 0x30($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X30);
    // 0x80009AE8: lhu         $a3, 0x18($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X18);
    // 0x80009AEC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80009AF0: sra         $v1, $v1, 17
    ctx->r3 = S32(SIGNED(ctx->r3) >> 17);
    // 0x80009AF4: subu        $v0, $a3, $v1
    ctx->r2 = SUB32(ctx->r7, ctx->r3);
    // 0x80009AF8: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80009AFC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80009B00: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80009B04: bltz        $v0, L_80009B20
    if (SIGNED(ctx->r2) < 0) {
        // 0x80009B08: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80009B20;
    }
    // 0x80009B08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80009B0C: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009B10: beq         $v0, $zero, L_80009B34
    if (ctx->r2 == 0) {
        // 0x80009B14: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80009B34;
    }
    // 0x80009B14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80009B18: j           L_80009B34
    // 0x80009B1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80009B34;
    // 0x80009B1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80009B20:
    // 0x80009B20: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80009B24: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009B28: bne         $v0, $zero, L_80009B34
    if (ctx->r2 != 0) {
        // 0x80009B2C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009B34;
    }
    // 0x80009B2C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80009B30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80009B34:
    // 0x80009B34: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80009B38: jr          $ra
    // 0x80009B3C: nop

    return;
    // 0x80009B3C: nop

;}
RECOMP_FUNC void func_80009B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009B40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80009B44: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80009B48: lhu         $v1, 0x6($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X6);
    // 0x80009B4C: addiu       $v0, $zero, 0x43
    ctx->r2 = ADD32(0, 0X43);
    // 0x80009B50: bne         $v1, $v0, L_80009B68
    if (ctx->r3 != ctx->r2) {
        // 0x80009B54: addiu       $v0, $zero, 0x16
        ctx->r2 = ADD32(0, 0X16);
            goto L_80009B68;
    }
    // 0x80009B54: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x80009B58: lhu         $v1, 0x5A($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X5A);
    // 0x80009B5C: bne         $v1, $v0, L_80009B68
    if (ctx->r3 != ctx->r2) {
        // 0x80009B60: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80009B68;
    }
    // 0x80009B60: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80009B64: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
L_80009B68:
    // 0x80009B68: jal         0x80009B80
    // 0x80009B6C: nop

    func_80009B80(rdram, ctx);
        goto after_0;
    // 0x80009B6C: nop

    after_0:
    // 0x80009B70: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80009B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80009B78: jr          $ra
    // 0x80009B7C: nop

    return;
    // 0x80009B7C: nop

;}
RECOMP_FUNC void func_80009B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009B80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009B84: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80009B88: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80009B8C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80009B90: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80009B94: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80009B98: lhu         $v0, 0x24($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X24);
    // 0x80009B9C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80009BA0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80009BA4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80009BA8: jal         0x8003C34C
    // 0x80009BAC: sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    func_8003C34C(rdram, ctx);
        goto after_0;
    // 0x80009BAC: sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    after_0:
    // 0x80009BB0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80009BB4: jal         0x80060F30
    // 0x80009BB8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80060F30(rdram, ctx);
        goto after_1;
    // 0x80009BB8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80009BBC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80009BC0: sh          $v0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r2;
    // 0x80009BC4: sw          $s0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r16;
    // 0x80009BC8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80009BCC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x80009BD0: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80009BD4: sh          $v0, 0x54($s1)
    MEM_H(0X54, ctx->r17) = ctx->r2;
    // 0x80009BD8: lhu         $v0, 0x120($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X120);
    // 0x80009BDC: sh          $v0, 0x5C($s1)
    MEM_H(0X5C, ctx->r17) = ctx->r2;
    // 0x80009BE0: lhu         $v0, 0x122($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X122);
    // 0x80009BE4: sh          $v0, 0x5E($s1)
    MEM_H(0X5E, ctx->r17) = ctx->r2;
    // 0x80009BE8: lhu         $v0, 0x142($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X142);
    // 0x80009BEC: beq         $v0, $zero, L_80009C04
    if (ctx->r2 == 0) {
        // 0x80009BF0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80009C04;
    }
    // 0x80009BF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80009BF4: lhu         $v0, 0x1A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X1A);
    // 0x80009BF8: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80009BFC: sh          $v0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r2;
    // 0x80009C00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80009C04:
    // 0x80009C04: sh          $v0, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r2;
    // 0x80009C08: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80009C0C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80009C10: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80009C14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009C18: jr          $ra
    // 0x80009C1C: nop

    return;
    // 0x80009C1C: nop

;}
RECOMP_FUNC void func_80009C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009C20: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80009C24: lhu         $t0, -0x74F0($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X74F0);
    // FALLTHROUGH: func_80009C20 falls into func_80009C28
    func_80009C28(rdram, ctx);
;}
RECOMP_FUNC void func_80009C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009C28: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80009C2C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80009C30: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80009C34: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80009C38: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80009C3C: addiu       $s2, $s2, -0x2048
    ctx->r18 = ADD32(ctx->r18, -0X2048);
    // 0x80009C40: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80009C44: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80009C48: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80009C4C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80009C50: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80009C54: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80009C58: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80009C5C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80009C60: bne         $t0, $zero, L_80009C78
    if (ctx->r8 != 0) {
        // 0x80009C64: sh          $t0, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r8;
            goto L_80009C78;
    }
    // 0x80009C64: sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    // 0x80009C68: j           L_80009DD4
    // 0x80009C6C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80009DD4;
    // 0x80009C6C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80009C70:
    // 0x80009C70: j           L_80009D7C
    // 0x80009C74: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
        goto L_80009D7C;
    // 0x80009C74: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
L_80009C78:
    // 0x80009C78: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80009C7C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80009C80: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80009C84: sra         $s5, $a0, 16
    ctx->r21 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80009C88: sll         $fp, $a1, 16
    ctx->r30 = S32(ctx->r5 << 16);
    // 0x80009C8C: sra         $s6, $fp, 16
    ctx->r22 = S32(SIGNED(ctx->r30) >> 16);
    // 0x80009C90: addiu       $s4, $s2, 0x6
    ctx->r20 = ADD32(ctx->r18, 0X6);
L_80009C94:
    // 0x80009C94: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80009C98: lhu         $v0, 0x6C($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X6C);
    // 0x80009C9C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80009CA0: bne         $v0, $zero, L_80009DB4
    if (ctx->r2 != 0) {
        // 0x80009CA4: nop
    
            goto L_80009DB4;
    }
    // 0x80009CA4: nop

    // 0x80009CA8: lhu         $v0, 0x2($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X2);
    // 0x80009CAC: xori        $v1, $v0, 0x32
    ctx->r3 = ctx->r2 ^ 0X32;
    // 0x80009CB0: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80009CB4: xori        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 ^ 0X2;
    // 0x80009CB8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80009CBC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80009CC0: beq         $v1, $zero, L_80009DB4
    if (ctx->r3 == 0) {
        // 0x80009CC4: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_80009DB4;
    }
    // 0x80009CC4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x80009CC8: lhu         $v1, 0x0($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X0);
    // 0x80009CCC: beq         $v1, $v0, L_80009D90
    if (ctx->r3 == ctx->r2) {
        // 0x80009CD0: slti        $v0, $v1, 0x13
        ctx->r2 = SIGNED(ctx->r3) < 0X13 ? 1 : 0;
            goto L_80009D90;
    }
    // 0x80009CD0: slti        $v0, $v1, 0x13
    ctx->r2 = SIGNED(ctx->r3) < 0X13 ? 1 : 0;
    // 0x80009CD4: beq         $v0, $zero, L_80009CEC
    if (ctx->r2 == 0) {
        // 0x80009CD8: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80009CEC;
    }
    // 0x80009CD8: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80009CDC: beq         $v1, $v0, L_80009D50
    if (ctx->r3 == ctx->r2) {
        // 0x80009CE0: nop
    
            goto L_80009D50;
    }
    // 0x80009CE0: nop

    // 0x80009CE4: j           L_80009DB4
    // 0x80009CE8: nop

        goto L_80009DB4;
    // 0x80009CE8: nop

L_80009CEC:
    // 0x80009CEC: addiu       $v0, $zero, 0x3E
    ctx->r2 = ADD32(0, 0X3E);
    // 0x80009CF0: beq         $v1, $v0, L_80009D50
    if (ctx->r3 == ctx->r2) {
        // 0x80009CF4: addiu       $v0, $zero, 0x42
        ctx->r2 = ADD32(0, 0X42);
            goto L_80009D50;
    }
    // 0x80009CF4: addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
    // 0x80009CF8: bne         $v1, $v0, L_80009DB4
    if (ctx->r3 != ctx->r2) {
        // 0x80009CFC: nop
    
            goto L_80009DB4;
    }
    // 0x80009CFC: nop

    // 0x80009D00: lhu         $v0, 0x18E($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X18E);
    // 0x80009D04: bne         $v0, $s7, L_80009D30
    if (ctx->r2 != ctx->r23) {
        // 0x80009D08: sra         $s0, $fp, 16
        ctx->r16 = S32(SIGNED(ctx->r30) >> 16);
            goto L_80009D30;
    }
    // 0x80009D08: sra         $s0, $fp, 16
    ctx->r16 = S32(SIGNED(ctx->r30) >> 16);
    // 0x80009D0C: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80009D10: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x80009D14: jal         0x8000A168
    // 0x80009D18: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    func_8000A168(rdram, ctx);
        goto after_0;
    // 0x80009D18: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    after_0:
    // 0x80009D1C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80009D20: bne         $v0, $s7, L_80009DB4
    if (ctx->r2 != ctx->r23) {
        // 0x80009D24: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_80009DB4;
    }
    // 0x80009D24: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80009D28: j           L_80009D7C
    // 0x80009D2C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
        goto L_80009D7C;
    // 0x80009D2C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
L_80009D30:
    // 0x80009D30: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80009D34: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80009D38: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x80009D3C: sra         $s1, $t0, 16
    ctx->r17 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80009D40: jal         0x8000A0FC
    // 0x80009D44: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8000A0FC(rdram, ctx);
        goto after_1;
    // 0x80009D44: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80009D48: j           L_80009D70
    // 0x80009D4C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
        goto L_80009D70;
    // 0x80009D4C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80009D50:
    // 0x80009D50: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80009D54: sra         $s0, $fp, 16
    ctx->r16 = S32(SIGNED(ctx->r30) >> 16);
    // 0x80009D58: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80009D5C: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    // 0x80009D60: sra         $s1, $t0, 16
    ctx->r17 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80009D64: jal         0x8000A168
    // 0x80009D68: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8000A168(rdram, ctx);
        goto after_2;
    // 0x80009D68: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x80009D6C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80009D70:
    // 0x80009D70: bne         $v0, $s7, L_80009DB4
    if (ctx->r2 != ctx->r23) {
        // 0x80009D74: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80009DB4;
    }
    // 0x80009D74: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80009D78: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_80009D7C:
    // 0x80009D7C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x80009D80: jal         0x8000A234
    // 0x80009D84: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    func_8000A234(rdram, ctx);
        goto after_3;
    // 0x80009D84: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_3:
    // 0x80009D88: j           L_80009DD4
    // 0x80009D8C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
        goto L_80009DD4;
    // 0x80009D8C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80009D90:
    // 0x80009D90: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80009D94: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80009D98: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x80009D9C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x80009DA0: jal         0x80009ED8
    // 0x80009DA4: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    func_80009ED8(rdram, ctx);
        goto after_4;
    // 0x80009DA4: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_4:
    // 0x80009DA8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80009DAC: beq         $v0, $s7, L_80009C70
    if (ctx->r2 == ctx->r23) {
        // 0x80009DB0: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_80009C70;
    }
    // 0x80009DB0: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
L_80009DB4:
    // 0x80009DB4: lhu         $t0, 0x1E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X1E);
    // 0x80009DB8: addiu       $s4, $s4, 0x78
    ctx->r20 = ADD32(ctx->r20, 0X78);
    // 0x80009DBC: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x80009DC0: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x80009DC4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80009DC8: bne         $v0, $zero, L_80009C94
    if (ctx->r2 != 0) {
        // 0x80009DCC: addiu       $s2, $s2, 0x78
        ctx->r18 = ADD32(ctx->r18, 0X78);
            goto L_80009C94;
    }
    // 0x80009DCC: addiu       $s2, $s2, 0x78
    ctx->r18 = ADD32(ctx->r18, 0X78);
    // 0x80009DD0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80009DD4:
    // 0x80009DD4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80009DD8: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80009DDC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80009DE0: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80009DE4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80009DE8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80009DEC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80009DF0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80009DF4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80009DF8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80009DFC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80009E00: jr          $ra
    // 0x80009E04: nop

    return;
    // 0x80009E04: nop

;}
RECOMP_FUNC void func_80009E08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009E08: lh          $v0, 0x14($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X14);
    // 0x80009E0C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80009E10: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x80009E14: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80009E18: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80009E1C: beq         $v0, $zero, L_80009E38
    if (ctx->r2 == 0) {
                func_80009E20(rdram, ctx); return; // was goto L_80009E38
    }
;}
RECOMP_FUNC void func_80009E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009E20: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80009E24: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80009E28: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x80009E2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80009E30: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80009E34: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x80009E38: lhu         $v0, 0x32($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X32);
    // 0x80009E3C: subu        $v1, $a3, $a0
    ctx->r3 = SUB32(ctx->r7, ctx->r4);
    // 0x80009E40: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80009E44: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80009E48: sra         $a0, $v0, 17
    ctx->r4 = S32(SIGNED(ctx->r2) >> 17);
    // 0x80009E4C: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80009E50: bltzl       $v0, L_80009E6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80009E54: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_80009E6C;
    }
    goto skip_0;
    // 0x80009E54: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_0:
    // 0x80009E58: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009E5C: beq         $v0, $zero, L_80009E78
    if (ctx->r2 == 0) {
        // 0x80009E60: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009E78;
    }
    // 0x80009E60: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80009E64: j           L_80009ECC
    // 0x80009E68: nop

        goto L_80009ECC;
    // 0x80009E68: nop

L_80009E6C:
    // 0x80009E6C: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009E70: bne         $v0, $zero, L_80009ECC
    if (ctx->r2 != 0) {
        // 0x80009E74: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009ECC;
    }
    // 0x80009E74: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80009E78:
    // 0x80009E78: lhu         $v0, 0x30($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X30);
    // 0x80009E7C: lhu         $a3, 0x18($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X18);
    // 0x80009E80: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80009E84: sra         $v0, $v0, 18
    ctx->r2 = S32(SIGNED(ctx->r2) >> 18);
    // 0x80009E88: subu        $v1, $a3, $v0
    ctx->r3 = SUB32(ctx->r7, ctx->r2);
    // 0x80009E8C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80009E90: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80009E94: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80009E98: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80009E9C: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80009EA0: bltzl       $v0, L_80009EBC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80009EA4: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_80009EBC;
    }
    goto skip_1;
    // 0x80009EA4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_1:
    // 0x80009EA8: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009EAC: beq         $v0, $zero, L_80009ECC
    if (ctx->r2 == 0) {
        // 0x80009EB0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80009ECC;
    }
    // 0x80009EB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80009EB4: j           L_80009ECC
    // 0x80009EB8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80009ECC;
    // 0x80009EB8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80009EBC:
    // 0x80009EBC: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009EC0: bne         $v0, $zero, L_80009ECC
    if (ctx->r2 != 0) {
        // 0x80009EC4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80009ECC;
    }
    // 0x80009EC4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80009EC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80009ECC:
    // 0x80009ECC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80009ED0: jr          $ra
    // 0x80009ED4: nop

    return;
    // 0x80009ED4: nop

;}
RECOMP_FUNC void func_80009ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009ED8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80009EDC: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80009EE0: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80009EE4: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x80009EE8: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80009EEC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80009EF0: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80009EF4: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80009EF8: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80009EFC: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x80009F00: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80009F04: sw          $ra, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r31;
    // 0x80009F08: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80009F0C: jal         0x8000ABD4
    // 0x80009F10: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    func_8000ABD4(rdram, ctx);
        goto after_0;
    // 0x80009F10: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    after_0:
    // 0x80009F14: lhu         $a0, 0x3E($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X3E);
    // 0x80009F18: addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
    // 0x80009F1C: lh          $v0, 0x3E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X3E);
    // 0x80009F20: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80009F24: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80009F28: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009F2C: beq         $v0, $zero, L_80009F4C
    if (ctx->r2 == 0) {
        // 0x80009F30: addu        $s5, $s3, $zero
        ctx->r21 = ADD32(ctx->r19, 0);
            goto L_80009F4C;
    }
    // 0x80009F30: addu        $s5, $s3, $zero
    ctx->r21 = ADD32(ctx->r19, 0);
    // 0x80009F34: addiu       $v0, $a0, -0x4
    ctx->r2 = ADD32(ctx->r4, -0X4);
    // 0x80009F38: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80009F3C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80009F40: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009F44: bne         $v0, $zero, L_80009FCC
    if (ctx->r2 != 0) {
        // 0x80009F48: nop
    
            goto L_80009FCC;
    }
    // 0x80009F48: nop

L_80009F4C:
    // 0x80009F4C: lh          $v0, 0x40($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X40);
    // 0x80009F50: lhu         $a0, 0x40($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X40);
    // 0x80009F54: slt         $v0, $v0, $s0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80009F58: beq         $v0, $zero, L_80009F74
    if (ctx->r2 == 0) {
        // 0x80009F5C: addiu       $v0, $a0, 0x4
        ctx->r2 = ADD32(ctx->r4, 0X4);
            goto L_80009F74;
    }
    // 0x80009F5C: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x80009F60: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80009F64: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80009F68: slt         $v0, $v0, $s0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80009F6C: bne         $v0, $zero, L_80009FCC
    if (ctx->r2 != 0) {
        // 0x80009F70: nop
    
            goto L_80009FCC;
    }
    // 0x80009F70: nop

L_80009F74:
    // 0x80009F74: lhu         $a0, 0x44($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X44);
    // 0x80009F78: lh          $v0, 0x44($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X44);
    // 0x80009F7C: sll         $v1, $s3, 16
    ctx->r3 = S32(ctx->r19 << 16);
    // 0x80009F80: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80009F84: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009F88: beq         $v0, $zero, L_80009FA4
    if (ctx->r2 == 0) {
        // 0x80009F8C: addiu       $v0, $a0, -0x4
        ctx->r2 = ADD32(ctx->r4, -0X4);
            goto L_80009FA4;
    }
    // 0x80009F8C: addiu       $v0, $a0, -0x4
    ctx->r2 = ADD32(ctx->r4, -0X4);
    // 0x80009F90: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80009F94: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80009F98: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009F9C: bne         $v0, $zero, L_80009FCC
    if (ctx->r2 != 0) {
        // 0x80009FA0: nop
    
            goto L_80009FCC;
    }
    // 0x80009FA0: nop

L_80009FA4:
    // 0x80009FA4: lh          $v0, 0x42($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X42);
    // 0x80009FA8: lhu         $a0, 0x42($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X42);
    // 0x80009FAC: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80009FB0: beq         $v0, $zero, L_8000A0B4
    if (ctx->r2 == 0) {
        // 0x80009FB4: addiu       $v0, $a0, 0x4
        ctx->r2 = ADD32(ctx->r4, 0X4);
            goto L_8000A0B4;
    }
    // 0x80009FB4: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x80009FB8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80009FBC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80009FC0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80009FC4: beq         $v0, $zero, L_8000A0B8
    if (ctx->r2 == 0) {
        // 0x80009FC8: sll         $a0, $s4, 16
        ctx->r4 = S32(ctx->r20 << 16);
            goto L_8000A0B8;
    }
    // 0x80009FC8: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
L_80009FCC:
    // 0x80009FCC: lhu         $a0, 0x46($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X46);
    // 0x80009FD0: lh          $v0, 0x46($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X46);
    // 0x80009FD4: sll         $v1, $s4, 16
    ctx->r3 = S32(ctx->r20 << 16);
    // 0x80009FD8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80009FDC: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009FE0: beq         $v0, $zero, L_80009FFC
    if (ctx->r2 == 0) {
        // 0x80009FE4: addiu       $v0, $a0, -0x4
        ctx->r2 = ADD32(ctx->r4, -0X4);
            goto L_80009FFC;
    }
    // 0x80009FE4: addiu       $v0, $a0, -0x4
    ctx->r2 = ADD32(ctx->r4, -0X4);
    // 0x80009FE8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80009FEC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80009FF0: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009FF4: bne         $v0, $zero, L_8000A0D4
    if (ctx->r2 != 0) {
        // 0x80009FF8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8000A0D4;
    }
    // 0x80009FF8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80009FFC:
    // 0x80009FFC: lhu         $a0, 0x48($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X48);
    // 0x8000A000: lh          $v0, 0x48($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X48);
    // 0x8000A004: sll         $v1, $s4, 16
    ctx->r3 = S32(ctx->r20 << 16);
    // 0x8000A008: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000A00C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000A010: beq         $v0, $zero, L_8000A02C
    if (ctx->r2 == 0) {
        // 0x8000A014: addiu       $v0, $a0, 0x4
        ctx->r2 = ADD32(ctx->r4, 0X4);
            goto L_8000A02C;
    }
    // 0x8000A014: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x8000A018: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000A01C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A020: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000A024: bne         $v0, $zero, L_8000A0D4
    if (ctx->r2 != 0) {
        // 0x8000A028: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8000A0D4;
    }
    // 0x8000A028: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8000A02C:
    // 0x8000A02C: lhu         $a0, 0x4C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4C);
    // 0x8000A030: lh          $v0, 0x4C($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4C);
    // 0x8000A034: sll         $v1, $s5, 16
    ctx->r3 = S32(ctx->r21 << 16);
    // 0x8000A038: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000A03C: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000A040: beq         $v0, $zero, L_8000A05C
    if (ctx->r2 == 0) {
        // 0x8000A044: addiu       $v0, $a0, -0x4
        ctx->r2 = ADD32(ctx->r4, -0X4);
            goto L_8000A05C;
    }
    // 0x8000A044: addiu       $v0, $a0, -0x4
    ctx->r2 = ADD32(ctx->r4, -0X4);
    // 0x8000A048: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000A04C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A050: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000A054: bne         $v0, $zero, L_8000A0D4
    if (ctx->r2 != 0) {
        // 0x8000A058: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8000A0D4;
    }
    // 0x8000A058: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8000A05C:
    // 0x8000A05C: lhu         $a0, 0x4A($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4A);
    // 0x8000A060: lh          $v0, 0x4A($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4A);
    // 0x8000A064: sll         $v1, $s5, 16
    ctx->r3 = S32(ctx->r21 << 16);
    // 0x8000A068: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000A06C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000A070: beq         $v0, $zero, L_8000A08C
    if (ctx->r2 == 0) {
        // 0x8000A074: addiu       $v0, $a0, 0x4
        ctx->r2 = ADD32(ctx->r4, 0X4);
            goto L_8000A08C;
    }
    // 0x8000A074: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x8000A078: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000A07C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A080: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000A084: bne         $v0, $zero, L_8000A0D4
    if (ctx->r2 != 0) {
        // 0x8000A088: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8000A0D4;
    }
    // 0x8000A088: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8000A08C:
    // 0x8000A08C: beq         $s2, $zero, L_8000A0B4
    if (ctx->r18 == 0) {
        // 0x8000A090: addiu       $a0, $zero, 0x28
        ctx->r4 = ADD32(0, 0X28);
            goto L_8000A0B4;
    }
    // 0x8000A090: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8000A094: lhu         $v0, 0x24($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X24);
    // 0x8000A098: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8000A09C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000A0A0: jal         0x8003C34C
    // 0x8000A0A4: sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    func_8003C34C(rdram, ctx);
        goto after_1;
    // 0x8000A0A4: sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    after_1:
    // 0x8000A0A8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8000A0AC: jal         0x80060F30
    // 0x8000A0B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80060F30(rdram, ctx);
        goto after_2;
    // 0x8000A0B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
L_8000A0B4:
    // 0x8000A0B4: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
L_8000A0B8:
    // 0x8000A0B8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8000A0BC: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x8000A0C0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8000A0C4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8000A0C8: jal         0x8000A234
    // 0x8000A0CC: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    func_8000A234(rdram, ctx);
        goto after_3;
    // 0x8000A0CC: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_3:
    // 0x8000A0D0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_8000A0D4:
    // 0x8000A0D4: lw          $ra, 0x68($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X68);
    // 0x8000A0D8: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8000A0DC: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x8000A0E0: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8000A0E4: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8000A0E8: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8000A0EC: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8000A0F0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8000A0F4: jr          $ra
    // 0x8000A0F8: nop

    return;
    // 0x8000A0F8: nop

;}
RECOMP_FUNC void func_8000A0FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A0FC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A100: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_8000A0FC falls into func_8000A104
    func_8000A104(rdram, ctx);
;}
RECOMP_FUNC void func_8000A104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A108: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000A10C: lw          $v0, 0x94($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X94);
    // 0x8000A110: beql        $v0, $zero, L_8000A158
    if (ctx->r2 == 0) {
        // 0x8000A114: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8000A158;
    }
    goto skip_0;
    // 0x8000A114: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
    // 0x8000A118: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8000A11C: lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X90);
    // 0x8000A120: beql        $v0, $a2, L_8000A158
    if (ctx->r2 == ctx->r6) {
        // 0x8000A124: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8000A158;
    }
    goto skip_1;
    // 0x8000A124: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_1:
    // 0x8000A128: lhu         $v1, 0xA($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XA);
    // 0x8000A12C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000A130: beq         $v1, $v0, L_8000A154
    if (ctx->r3 == ctx->r2) {
        // 0x8000A134: sll         $a0, $a0, 16
        ctx->r4 = S32(ctx->r4 << 16);
            goto L_8000A154;
    }
    // 0x8000A134: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8000A138: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8000A13C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8000A140: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8000A144: jal         0x8000A168
    // 0x8000A148: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    func_8000A168(rdram, ctx);
        goto after_0;
    // 0x8000A148: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    after_0:
    // 0x8000A14C: j           L_8000A158
    // 0x8000A150: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
        goto L_8000A158;
    // 0x8000A150: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_8000A154:
    // 0x8000A154: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8000A158:
    // 0x8000A158: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000A15C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A160: jr          $ra
    // 0x8000A164: nop

    return;
    // 0x8000A164: nop

;}
RECOMP_FUNC void func_8000A168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A168: lh          $v0, 0x14($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X14);
    // 0x8000A16C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000A170: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x8000A174: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x8000A178: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000A17C: beq         $v0, $zero, L_8000A198
    if (ctx->r2 == 0) {
                func_8000A180(rdram, ctx); return; // was goto L_8000A198
    }
;}
RECOMP_FUNC void func_8000A180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A180: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000A184: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A188: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x8000A18C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000A190: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A194: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8000A198: lhu         $v0, 0x32($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X32);
    // 0x8000A19C: subu        $v1, $a3, $a0
    ctx->r3 = SUB32(ctx->r7, ctx->r4);
    // 0x8000A1A0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8000A1A4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000A1A8: sra         $a0, $v0, 17
    ctx->r4 = S32(SIGNED(ctx->r2) >> 17);
    // 0x8000A1AC: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000A1B0: bltzl       $v0, L_8000A1CC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000A1B4: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_8000A1CC;
    }
    goto skip_0;
    // 0x8000A1B4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_0:
    // 0x8000A1B8: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000A1BC: beq         $v0, $zero, L_8000A1D8
    if (ctx->r2 == 0) {
        // 0x8000A1C0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8000A1D8;
    }
    // 0x8000A1C0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8000A1C4: j           L_8000A228
    // 0x8000A1C8: nop

        goto L_8000A228;
    // 0x8000A1C8: nop

L_8000A1CC:
    // 0x8000A1CC: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000A1D0: bne         $v0, $zero, L_8000A228
    if (ctx->r2 != 0) {
        // 0x8000A1D4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8000A228;
    }
    // 0x8000A1D4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8000A1D8:
    // 0x8000A1D8: lhu         $v1, 0x30($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X30);
    // 0x8000A1DC: lhu         $a3, 0x18($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X18);
    // 0x8000A1E0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8000A1E4: sra         $v1, $v1, 17
    ctx->r3 = S32(SIGNED(ctx->r3) >> 17);
    // 0x8000A1E8: subu        $v0, $a3, $v1
    ctx->r2 = SUB32(ctx->r7, ctx->r3);
    // 0x8000A1EC: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8000A1F0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000A1F4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A1F8: bltz        $v0, L_8000A214
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000A1FC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000A214;
    }
    // 0x8000A1FC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000A200: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000A204: beq         $v0, $zero, L_8000A228
    if (ctx->r2 == 0) {
        // 0x8000A208: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000A228;
    }
    // 0x8000A208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A20C: j           L_8000A228
    // 0x8000A210: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8000A228;
    // 0x8000A210: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8000A214:
    // 0x8000A214: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8000A218: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000A21C: bne         $v0, $zero, L_8000A228
    if (ctx->r2 != 0) {
        // 0x8000A220: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8000A228;
    }
    // 0x8000A220: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8000A224: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000A228:
    // 0x8000A228: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8000A22C: jr          $ra
    // 0x8000A230: nop

    return;
    // 0x8000A230: nop

;}
RECOMP_FUNC void func_8000A234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A234: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000A238: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000A23C: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x8000A240: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000A244: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x8000A248: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8000A24C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8000A250: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8000A254: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8000A258: beq         $s1, $zero, L_8000A2C8
    if (ctx->r17 == 0) {
        // 0x8000A25C: sw          $ra, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r31;
            goto L_8000A2C8;
    }
    // 0x8000A25C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8000A260: lhu         $v0, 0x24($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X24);
    // 0x8000A264: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8000A268: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8000A26C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000A270: jal         0x8003C34C
    // 0x8000A274: sh          $v0, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r2;
    func_8003C34C(rdram, ctx);
        goto after_0;
    // 0x8000A274: sh          $v0, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r2;
    after_0:
    // 0x8000A278: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8000A27C: jal         0x80060F30
    // 0x8000A280: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80060F30(rdram, ctx);
        goto after_1;
    // 0x8000A280: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x8000A284: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000A288: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x8000A28C: sw          $s1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r17;
    // 0x8000A290: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A294: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000A298: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x8000A29C: sh          $s2, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r18;
    // 0x8000A2A0: sh          $s3, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r19;
    // 0x8000A2A4: sh          $v0, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r2;
    // 0x8000A2A8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A2AC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000A2B0: sw          $s0, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r16;
    // 0x8000A2B4: lhu         $v1, 0x1A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X1A);
    // 0x8000A2B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A2BC: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x8000A2C0: j           L_8000A2CC
    // 0x8000A2C4: sh          $v1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r3;
        goto L_8000A2CC;
    // 0x8000A2C4: sh          $v1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r3;
L_8000A2C8:
    // 0x8000A2C8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8000A2CC:
    // 0x8000A2CC: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8000A2D0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A2D4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8000A2D8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8000A2DC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000A2E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000A2E4: jr          $ra
    // 0x8000A2E8: nop

    return;
    // 0x8000A2E8: nop

;}
RECOMP_FUNC void func_8000A2EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A2EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000A2F0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000A2F4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8000A2F8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8000A2FC: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x8000A300: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000A304: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000A308: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000A30C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000A310: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000A314: lh          $v1, 0x14($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X14);
    // 0x8000A318: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000A31C: lh          $v0, 0x46A8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X46A8);
    // 0x8000A320: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000A324: bne         $v0, $zero, L_8000A338
    if (ctx->r2 != 0) {
        // 0x8000A328: addu        $s3, $v1, $zero
        ctx->r19 = ADD32(ctx->r3, 0);
            goto L_8000A338;
    }
    // 0x8000A328: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // 0x8000A32C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A330: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x8000A334: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
L_8000A338:
    // 0x8000A338: lhu         $v0, 0x32($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X32);
    // 0x8000A33C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8000A340: addiu       $s2, $s2, -0x2048
    ctx->r18 = ADD32(ctx->r18, -0X2048);
    // 0x8000A344: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8000A348: lhu         $a1, -0x74F0($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X74F0);
    // 0x8000A34C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000A350: sra         $v0, $v0, 17
    ctx->r2 = S32(SIGNED(ctx->r2) >> 17);
    // 0x8000A354: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x8000A358: subu        $v0, $s3, $v0
    ctx->r2 = SUB32(ctx->r19, ctx->r2);
    // 0x8000A35C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8000A360: beq         $a1, $zero, L_8000A498
    if (ctx->r5 == 0) {
        // 0x8000A364: addu        $s4, $v1, $zero
        ctx->r20 = ADD32(ctx->r3, 0);
            goto L_8000A498;
    }
    // 0x8000A364: addu        $s4, $v1, $zero
    ctx->r20 = ADD32(ctx->r3, 0);
    // 0x8000A368: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000A36C: sra         $a3, $v0, 16
    ctx->r7 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A370: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8000A374: sra         $a2, $v0, 16
    ctx->r6 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A378: addiu       $s0, $s2, 0x1A
    ctx->r16 = ADD32(ctx->r18, 0X1A);
L_8000A37C:
    // 0x8000A37C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8000A380: lhu         $v0, 0x6C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X6C);
    // 0x8000A384: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8000A388: bnel        $v0, $zero, L_8000A484
    if (ctx->r2 != 0) {
        // 0x8000A38C: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_8000A484;
    }
    goto skip_0;
    // 0x8000A38C: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    skip_0:
    // 0x8000A390: lhu         $v0, -0x12($s0)
    ctx->r2 = MEM_HU(ctx->r16, -0X12);
    // 0x8000A394: xori        $v1, $v0, 0x32
    ctx->r3 = ctx->r2 ^ 0X32;
    // 0x8000A398: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8000A39C: xori        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 ^ 0X2;
    // 0x8000A3A0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8000A3A4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8000A3A8: beql        $v1, $zero, L_8000A484
    if (ctx->r3 == 0) {
        // 0x8000A3AC: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_8000A484;
    }
    goto skip_1;
    // 0x8000A3AC: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    skip_1:
    // 0x8000A3B0: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x8000A3B4: slti        $v0, $v0, 0xE1
    ctx->r2 = SIGNED(ctx->r2) < 0XE1 ? 1 : 0;
    // 0x8000A3B8: bnel        $v0, $zero, L_8000A484
    if (ctx->r2 != 0) {
        // 0x8000A3BC: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_8000A484;
    }
    goto skip_2;
    // 0x8000A3BC: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    skip_2:
    // 0x8000A3C0: lh          $v0, 0x14($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X14);
    // 0x8000A3C4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000A3C8: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x8000A3CC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000A3D0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000A3D4: beq         $v0, $zero, L_8000A3F4
    if (ctx->r2 == 0) {
        // 0x8000A3D8: sll         $v1, $a0, 16
        ctx->r3 = S32(ctx->r4 << 16);
            goto L_8000A3F4;
    }
    // 0x8000A3D8: sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4 << 16);
    // 0x8000A3DC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A3E0: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x8000A3E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000A3E8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A3EC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8000A3F0: sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4 << 16);
L_8000A3F4:
    // 0x8000A3F4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000A3F8: slt         $v0, $v1, $a3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8000A3FC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8000A400: slt         $v1, $v1, $a2
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8000A404: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000A408: beq         $v0, $zero, L_8000A480
    if (ctx->r2 == 0) {
        // 0x8000A40C: addiu       $a0, $zero, 0x28
        ctx->r4 = ADD32(0, 0X28);
            goto L_8000A480;
    }
    // 0x8000A40C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8000A410: lhu         $v0, 0x24($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X24);
    // 0x8000A414: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8000A418: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000A41C: jal         0x8003C34C
    // 0x8000A420: sh          $v0, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r2;
    func_8003C34C(rdram, ctx);
        goto after_0;
    // 0x8000A420: sh          $v0, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r2;
    after_0:
    // 0x8000A424: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8000A428: jal         0x80060F30
    // 0x8000A42C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80060F30(rdram, ctx);
        goto after_1;
    // 0x8000A42C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x8000A430: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000A434: sh          $v0, -0x12($s0)
    MEM_H(-0X12, ctx->r16) = ctx->r2;
    // 0x8000A438: sw          $s1, 0x46($s0)
    MEM_W(0X46, ctx->r16) = ctx->r17;
    // 0x8000A43C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A440: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000A444: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x8000A448: sh          $s3, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r19;
    // 0x8000A44C: sh          $s4, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r20;
    // 0x8000A450: sh          $v0, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r2;
    // 0x8000A454: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A458: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000A45C: sw          $s2, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r18;
    // 0x8000A460: lhu         $v1, -0x14($s0)
    ctx->r3 = MEM_HU(ctx->r16, -0X14);
    // 0x8000A464: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x8000A468: addiu       $v0, $zero, 0x43
    ctx->r2 = ADD32(0, 0X43);
    // 0x8000A46C: bne         $v1, $v0, L_8000A478
    if (ctx->r3 != ctx->r2) {
        // 0x8000A470: addiu       $v0, $a0, 0xA
        ctx->r2 = ADD32(ctx->r4, 0XA);
            goto L_8000A478;
    }
    // 0x8000A470: addiu       $v0, $a0, 0xA
    ctx->r2 = ADD32(ctx->r4, 0XA);
    // 0x8000A474: addiu       $v0, $a0, 0x5
    ctx->r2 = ADD32(ctx->r4, 0X5);
L_8000A478:
    // 0x8000A478: j           L_8000A498
    // 0x8000A47C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_8000A498;
    // 0x8000A47C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_8000A480:
    // 0x8000A480: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
L_8000A484:
    // 0x8000A484: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x8000A488: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8000A48C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000A490: bne         $v0, $zero, L_8000A37C
    if (ctx->r2 != 0) {
        // 0x8000A494: addiu       $s2, $s2, 0x78
        ctx->r18 = ADD32(ctx->r18, 0X78);
            goto L_8000A37C;
    }
    // 0x8000A494: addiu       $s2, $s2, 0x78
    ctx->r18 = ADD32(ctx->r18, 0X78);
L_8000A498:
    // 0x8000A498: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000A49C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000A4A0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A4A4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000A4A8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000A4AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000A4B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000A4B4: jr          $ra
    // 0x8000A4B8: nop

    return;
    // 0x8000A4B8: nop

;}
RECOMP_FUNC void func_8000A4BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A4BC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A4C0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000A4C4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8000A4C8: lh          $a0, 0x46A8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X46A8);
    // FALLTHROUGH: func_8000A4BC falls into func_8000A4CC
    func_8000A4CC(rdram, ctx);
;}
RECOMP_FUNC void func_8000A4CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A4CC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000A4D0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000A4D4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8000A4D8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8000A4DC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8000A4E0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000A4E4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000A4E8: lh          $v1, 0x14($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X14);
    // 0x8000A4EC: lhu         $a1, 0x14($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X14);
    // 0x8000A4F0: lw          $s1, 0x90($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X90);
    // 0x8000A4F4: slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000A4F8: beq         $v1, $zero, L_8000A50C
    if (ctx->r3 == 0) {
        // 0x8000A4FC: nop
    
            goto L_8000A50C;
    }
    // 0x8000A4FC: nop

    // 0x8000A500: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A504: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x8000A508: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
L_8000A50C:
    // 0x8000A50C: lui         $s3, 0x8016
    ctx->r19 = S32(0X8016 << 16);
    // 0x8000A510: lhu         $s3, -0x74F0($s3)
    ctx->r19 = MEM_HU(ctx->r19, -0X74F0);
    // 0x8000A514: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8000A518: addiu       $s2, $s2, -0x2048
    ctx->r18 = ADD32(ctx->r18, -0X2048);
    // 0x8000A51C: beq         $s3, $zero, L_8000A67C
    if (ctx->r19 == 0) {
        // 0x8000A520: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_8000A67C;
    }
    // 0x8000A520: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8000A524: sra         $s4, $v0, 16
    ctx->r20 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A528: addiu       $s0, $s2, 0x1A
    ctx->r16 = ADD32(ctx->r18, 0X1A);
L_8000A52C:
    // 0x8000A52C: lhu         $v1, -0x14($s0)
    ctx->r3 = MEM_HU(ctx->r16, -0X14);
    // 0x8000A530: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8000A534: beq         $v1, $zero, L_8000A664
    if (ctx->r3 == 0) {
        // 0x8000A538: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_8000A664;
    }
    // 0x8000A538: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x8000A53C: bne         $v1, $v0, L_8000A550
    if (ctx->r3 != ctx->r2) {
        // 0x8000A540: addiu       $v0, $zero, 0x63
        ctx->r2 = ADD32(0, 0X63);
            goto L_8000A550;
    }
    // 0x8000A540: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x8000A544: lhu         $v1, -0x12($s0)
    ctx->r3 = MEM_HU(ctx->r16, -0X12);
    // 0x8000A548: beql        $v1, $v0, L_8000A668
    if (ctx->r3 == ctx->r2) {
        // 0x8000A54C: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_8000A668;
    }
    goto skip_0;
    // 0x8000A54C: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    skip_0:
L_8000A550:
    // 0x8000A550: lhu         $v0, 0x6C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X6C);
    // 0x8000A554: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8000A558: bnel        $v0, $zero, L_8000A668
    if (ctx->r2 != 0) {
        // 0x8000A55C: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_8000A668;
    }
    goto skip_1;
    // 0x8000A55C: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    skip_1:
    // 0x8000A560: lh          $v0, 0x14($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X14);
    // 0x8000A564: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000A568: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x8000A56C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8000A570: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000A574: beq         $v0, $zero, L_8000A5BC
    if (ctx->r2 == 0) {
        // 0x8000A578: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_8000A5BC;
    }
    // 0x8000A578: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8000A57C: subu        $v0, $a1, $a0
    ctx->r2 = SUB32(ctx->r5, ctx->r4);
    // 0x8000A580: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000A584: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A588: bltzl       $v0, L_8000A5A4
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000A58C: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_8000A5A4;
    }
    goto skip_2;
    // 0x8000A58C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_2:
    // 0x8000A590: slti        $v0, $v0, 0xC8
    ctx->r2 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x8000A594: beq         $v0, $zero, L_8000A5B0
    if (ctx->r2 == 0) {
        // 0x8000A598: nop
    
            goto L_8000A5B0;
    }
    // 0x8000A598: nop

    // 0x8000A59C: j           L_8000A5BC
    // 0x8000A5A0: nop

        goto L_8000A5BC;
    // 0x8000A5A0: nop

L_8000A5A4:
    // 0x8000A5A4: slti        $v0, $v0, 0xC8
    ctx->r2 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x8000A5A8: bne         $v0, $zero, L_8000A5BC
    if (ctx->r2 != 0) {
        // 0x8000A5AC: nop
    
            goto L_8000A5BC;
    }
    // 0x8000A5AC: nop

L_8000A5B0:
    // 0x8000A5B0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A5B4: lhu         $v0, 0x3294($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3294);
    // 0x8000A5B8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
L_8000A5BC:
    // 0x8000A5BC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A5C0: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000A5C4: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x8000A5C8: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8000A5CC: beq         $v0, $zero, L_8000A5EC
    if (ctx->r2 == 0) {
        // 0x8000A5D0: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_8000A5EC;
    }
    // 0x8000A5D0: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8000A5D4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A5D8: slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000A5DC: beq         $v0, $zero, L_8000A5FC
    if (ctx->r2 == 0) {
        // 0x8000A5E0: nop
    
            goto L_8000A5FC;
    }
    // 0x8000A5E0: nop

    // 0x8000A5E4: j           L_8000A668
    // 0x8000A5E8: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
        goto L_8000A668;
    // 0x8000A5E8: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
L_8000A5EC:
    // 0x8000A5EC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A5F0: slt         $v0, $v0, $s4
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8000A5F4: bnel        $v0, $zero, L_8000A668
    if (ctx->r2 != 0) {
        // 0x8000A5F8: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_8000A668;
    }
    goto skip_3;
    // 0x8000A5F8: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    skip_3:
L_8000A5FC:
    // 0x8000A5FC: lhu         $v0, 0x24($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X24);
    // 0x8000A600: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8000A604: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8000A608: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000A60C: jal         0x8003C34C
    // 0x8000A610: sh          $v0, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r2;
    func_8003C34C(rdram, ctx);
        goto after_0;
    // 0x8000A610: sh          $v0, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r2;
    after_0:
    // 0x8000A614: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8000A618: jal         0x80060F30
    // 0x8000A61C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80060F30(rdram, ctx);
        goto after_1;
    // 0x8000A61C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x8000A620: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000A624: sh          $v0, -0x12($s0)
    MEM_H(-0X12, ctx->r16) = ctx->r2;
    // 0x8000A628: sw          $s1, 0x46($s0)
    MEM_W(0X46, ctx->r16) = ctx->r17;
    // 0x8000A62C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A630: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000A634: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x8000A638: sh          $v0, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r2;
    // 0x8000A63C: lhu         $v0, 0x120($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X120);
    // 0x8000A640: sh          $v0, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r2;
    // 0x8000A644: lhu         $v0, 0x122($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X122);
    // 0x8000A648: sh          $v0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r2;
    // 0x8000A64C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A650: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000A654: sw          $s2, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r18;
    // 0x8000A658: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8000A65C: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x8000A660: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_8000A664:
    // 0x8000A664: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
L_8000A668:
    // 0x8000A668: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x8000A66C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8000A670: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000A674: bne         $v0, $zero, L_8000A52C
    if (ctx->r2 != 0) {
        // 0x8000A678: addiu       $s2, $s2, 0x78
        ctx->r18 = ADD32(ctx->r18, 0X78);
            goto L_8000A52C;
    }
    // 0x8000A678: addiu       $s2, $s2, 0x78
    ctx->r18 = ADD32(ctx->r18, 0X78);
L_8000A67C:
    // 0x8000A67C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000A680: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8000A684: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8000A688: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8000A68C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A690: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000A694: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000A698: jr          $ra
    // 0x8000A69C: nop

    return;
    // 0x8000A69C: nop

;}
RECOMP_FUNC void func_8000A6A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A6A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000A6A4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8000A6A8: lui         $s3, 0x8016
    ctx->r19 = S32(0X8016 << 16);
    // 0x8000A6AC: lhu         $s3, -0x74F0($s3)
    ctx->r19 = MEM_HU(ctx->r19, -0X74F0);
    // 0x8000A6B0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000A6B4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8000A6B8: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8000A6BC: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x8000A6C0: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8000A6C4: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8000A6C8: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8000A6CC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8000A6D0: beq         $s3, $zero, L_8000A7AC
    if (ctx->r19 == 0) {
        // 0x8000A6D4: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8000A7AC;
    }
    // 0x8000A6D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000A6D8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8000A6DC: addiu       $s2, $s2, -0x2048
    ctx->r18 = ADD32(ctx->r18, -0X2048);
    // 0x8000A6E0: addiu       $s7, $zero, 0x12
    ctx->r23 = ADD32(0, 0X12);
    // 0x8000A6E4: addiu       $s6, $zero, 0x63
    ctx->r22 = ADD32(0, 0X63);
    // 0x8000A6E8: sltiu       $s4, $s1, 0x1
    ctx->r20 = ctx->r17 < 0X1 ? 1 : 0;
    // 0x8000A6EC: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x8000A6F0: addiu       $s0, $s2, 0x1A
    ctx->r16 = ADD32(ctx->r18, 0X1A);
L_8000A6F4:
    // 0x8000A6F4: lhu         $v0, -0x14($s0)
    ctx->r2 = MEM_HU(ctx->r16, -0X14);
    // 0x8000A6F8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A6FC: beql        $v0, $zero, L_8000A798
    if (ctx->r2 == 0) {
        // 0x8000A700: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_8000A798;
    }
    goto skip_0;
    // 0x8000A700: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    skip_0:
    // 0x8000A704: bne         $v0, $s7, L_8000A718
    if (ctx->r2 != ctx->r23) {
        // 0x8000A708: nop
    
            goto L_8000A718;
    }
    // 0x8000A708: nop

    // 0x8000A70C: lhu         $v0, -0x12($s0)
    ctx->r2 = MEM_HU(ctx->r16, -0X12);
    // 0x8000A710: beql        $v0, $s6, L_8000A798
    if (ctx->r2 == ctx->r22) {
        // 0x8000A714: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_8000A798;
    }
    goto skip_1;
    // 0x8000A714: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    skip_1:
L_8000A718:
    // 0x8000A718: lhu         $v0, 0x6C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6C);
    // 0x8000A71C: srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // 0x8000A720: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8000A724: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000A728: or          $v0, $v0, $s4
    ctx->r2 = ctx->r2 | ctx->r20;
    // 0x8000A72C: beql        $v0, $zero, L_8000A798
    if (ctx->r2 == 0) {
        // 0x8000A730: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_8000A798;
    }
    goto skip_2;
    // 0x8000A730: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    skip_2:
    // 0x8000A734: beq         $s1, $zero, L_8000A75C
    if (ctx->r17 == 0) {
        // 0x8000A738: addiu       $a0, $zero, 0x28
        ctx->r4 = ADD32(0, 0X28);
            goto L_8000A75C;
    }
    // 0x8000A738: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8000A73C: lhu         $v0, 0x24($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X24);
    // 0x8000A740: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8000A744: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000A748: jal         0x8003C34C
    // 0x8000A74C: sh          $v0, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r2;
    func_8003C34C(rdram, ctx);
        goto after_0;
    // 0x8000A74C: sh          $v0, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r2;
    after_0:
    // 0x8000A750: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8000A754: jal         0x80060F30
    // 0x8000A758: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80060F30(rdram, ctx);
        goto after_1;
    // 0x8000A758: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
L_8000A75C:
    // 0x8000A75C: sh          $s5, -0x12($s0)
    MEM_H(-0X12, ctx->r16) = ctx->r21;
    // 0x8000A760: sw          $s1, 0x46($s0)
    MEM_W(0X46, ctx->r16) = ctx->r17;
    // 0x8000A764: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A768: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000A76C: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x8000A770: sh          $zero, 0x42($s0)
    MEM_H(0X42, ctx->r16) = 0;
    // 0x8000A774: sh          $zero, 0x44($s0)
    MEM_H(0X44, ctx->r16) = 0;
    // 0x8000A778: sh          $v0, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r2;
    // 0x8000A77C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A780: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000A784: sw          $s2, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r18;
    // 0x8000A788: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8000A78C: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x8000A790: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8000A794: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
L_8000A798:
    // 0x8000A798: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x8000A79C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8000A7A0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000A7A4: bne         $v0, $zero, L_8000A6F4
    if (ctx->r2 != 0) {
        // 0x8000A7A8: addiu       $s2, $s2, 0x78
        ctx->r18 = ADD32(ctx->r18, 0X78);
            goto L_8000A6F4;
    }
    // 0x8000A7A8: addiu       $s2, $s2, 0x78
    ctx->r18 = ADD32(ctx->r18, 0X78);
L_8000A7AC:
    // 0x8000A7AC: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8000A7B0: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A7B4: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8000A7B8: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8000A7BC: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8000A7C0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A7C4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8000A7C8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8000A7CC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000A7D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000A7D4: jr          $ra
    // 0x8000A7D8: nop

    return;
    // 0x8000A7D8: nop

;}
RECOMP_FUNC void func_8000A7DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A7DC: jr          $ra
    // 0x8000A7E0: nop

    return;
    // 0x8000A7E0: nop

;}
RECOMP_FUNC void func_8000A7E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A7E4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8000A7E8: addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // 0x8000A7EC: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8000A7F0: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8000A7F4: addiu       $t4, $t4, 0x3F94
    ctx->r12 = ADD32(ctx->r12, 0X3F94);
    // 0x8000A7F8: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x8000A7FC: andi        $v0, $t2, 0xFFFF
    ctx->r2 = ctx->r10 & 0XFFFF;
L_8000A800:
    // 0x8000A800: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8000A804: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000A808: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8000A80C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8000A810: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000A814: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x8000A818: lhu         $v0, 0x58($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X58);
    // 0x8000A81C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000A820: beq         $v0, $zero, L_8000A834
    if (ctx->r2 == 0) {
        // 0x8000A824: nop
    
            goto L_8000A834;
    }
    // 0x8000A824: nop

    // 0x8000A828: lhu         $v0, 0x1DE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1DE);
    // 0x8000A82C: beq         $v0, $zero, L_8000A8F0
    if (ctx->r2 == 0) {
        // 0x8000A830: addiu       $v0, $t2, -0x1
        ctx->r2 = ADD32(ctx->r10, -0X1);
            goto L_8000A8F0;
    }
    // 0x8000A830: addiu       $v0, $t2, -0x1
    ctx->r2 = ADD32(ctx->r10, -0X1);
L_8000A834:
    // 0x8000A834: lw          $t1, 0x68($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X68);
    // 0x8000A838: lh          $v0, 0x18($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X18);
    // 0x8000A83C: lhu         $a1, 0x14($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0X14);
    // 0x8000A840: bltz        $v0, L_8000A8EC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000A844: addu        $t0, $v0, $zero
        ctx->r8 = ADD32(ctx->r2, 0);
            goto L_8000A8EC;
    }
    // 0x8000A844: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8000A848: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000A84C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8000A850: lhu         $v0, 0x32($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X32);
    // 0x8000A854: lh          $a0, 0x14($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X14);
    // 0x8000A858: lhu         $a2, 0x18($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X18);
    // 0x8000A85C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000A860: sra         $a3, $v0, 18
    ctx->r7 = S32(SIGNED(ctx->r2) >> 18);
    // 0x8000A864: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8000A868: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8000A86C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A870: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8000A874: bltzl       $a0, L_8000A880
    if (SIGNED(ctx->r4) < 0) {
        // 0x8000A878: subu        $v1, $a1, $v1
        ctx->r3 = SUB32(ctx->r5, ctx->r3);
            goto L_8000A880;
    }
    goto skip_0;
    // 0x8000A878: subu        $v1, $a1, $v1
    ctx->r3 = SUB32(ctx->r5, ctx->r3);
    skip_0:
    // 0x8000A87C: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
L_8000A880:
    // 0x8000A880: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8000A884: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000A888: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x8000A88C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A890: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000A894: bne         $v0, $zero, L_8000A8F0
    if (ctx->r2 != 0) {
        // 0x8000A898: addiu       $v0, $t2, -0x1
        ctx->r2 = ADD32(ctx->r10, -0X1);
            goto L_8000A8F0;
    }
    // 0x8000A898: addiu       $v0, $t2, -0x1
    ctx->r2 = ADD32(ctx->r10, -0X1);
    // 0x8000A89C: lhu         $v0, 0x30($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X30);
    // 0x8000A8A0: sll         $v1, $a2, 16
    ctx->r3 = S32(ctx->r6 << 16);
    // 0x8000A8A4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000A8A8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000A8AC: sra         $a3, $v0, 18
    ctx->r7 = S32(SIGNED(ctx->r2) >> 18);
    // 0x8000A8B0: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x8000A8B4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A8B8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8000A8BC: bgez        $v1, L_8000A8C8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000A8C0: subu        $v1, $a2, $t0
        ctx->r3 = SUB32(ctx->r6, ctx->r8);
            goto L_8000A8C8;
    }
    // 0x8000A8C0: subu        $v1, $a2, $t0
    ctx->r3 = SUB32(ctx->r6, ctx->r8);
    // 0x8000A8C4: subu        $v1, $t0, $a2
    ctx->r3 = SUB32(ctx->r8, ctx->r6);
L_8000A8C8:
    // 0x8000A8C8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8000A8CC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000A8D0: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x8000A8D4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A8D8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000A8DC: bne         $v0, $zero, L_8000A8F0
    if (ctx->r2 != 0) {
        // 0x8000A8E0: addiu       $v0, $t2, -0x1
        ctx->r2 = ADD32(ctx->r10, -0X1);
            goto L_8000A8F0;
    }
    // 0x8000A8E0: addiu       $v0, $t2, -0x1
    ctx->r2 = ADD32(ctx->r10, -0X1);
    // 0x8000A8E4: j           L_8000A900
    // 0x8000A8E8: sh          $t5, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r13;
        goto L_8000A900;
    // 0x8000A8E8: sh          $t5, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r13;
L_8000A8EC:
    // 0x8000A8EC: addiu       $v0, $t2, -0x1
    ctx->r2 = ADD32(ctx->r10, -0X1);
L_8000A8F0:
    // 0x8000A8F0: addu        $t2, $v0, $zero
    ctx->r10 = ADD32(ctx->r2, 0);
    // 0x8000A8F4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000A8F8: bne         $v0, $zero, L_8000A800
    if (ctx->r2 != 0) {
        // 0x8000A8FC: andi        $v0, $t2, 0xFFFF
        ctx->r2 = ctx->r10 & 0XFFFF;
            goto L_8000A800;
    }
    // 0x8000A8FC: andi        $v0, $t2, 0xFFFF
    ctx->r2 = ctx->r10 & 0XFFFF;
L_8000A900:
    // 0x8000A900: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8000A904: jr          $ra
    // 0x8000A908: nop

    return;
    // 0x8000A908: nop

;}
RECOMP_FUNC void func_8000A90C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A90C: lhu         $v1, 0x8($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X8);
    // 0x8000A910: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000A914: bne         $v1, $v0, L_8000A9C8
    if (ctx->r3 != ctx->r2) {
                return; // L_8000A9C8 is jr $ra
    }

    // [R2-FALLTHROUGH FIX auto] N64Recomp split: fall through to func_8000A918
    func_8000A918(rdram, ctx);
}
RECOMP_FUNC void func_8000A918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A918: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8000A91C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A920: lh          $v0, -0x67CE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X67CE);
    // 0x8000A924: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8000A928: lhu         $a1, -0x67CE($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X67CE);
    // 0x8000A92C: beq         $v0, $zero, L_8000A960
    if (ctx->r2 == 0) {
        // 0x8000A930: nop
    
            goto L_8000A960;
    }
    // 0x8000A930: nop

    // 0x8000A934: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000A938: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8000A93C: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x8000A940: lhu         $v1, 0x14($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X14);
    // 0x8000A944: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8000A948: beq         $v0, $zero, L_8000A9B4
    if (ctx->r2 == 0) {
        // 0x8000A94C: subu        $v0, $a1, $v1
        ctx->r2 = SUB32(ctx->r5, ctx->r3);
            goto L_8000A9B4;
    }
    // 0x8000A94C: subu        $v0, $a1, $v1
    ctx->r2 = SUB32(ctx->r5, ctx->r3);
    // 0x8000A950: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8000A954: lhu         $v0, -0x7344($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7344);
    // 0x8000A958: j           L_8000A9B0
    // 0x8000A95C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
        goto L_8000A9B0;
    // 0x8000A95C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8000A960:
    // 0x8000A960: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A964: lhu         $v0, 0x11C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X11C);
    // 0x8000A968: bne         $v0, $zero, L_8000A9C8
    if (ctx->r2 != 0) {
        // 0x8000A96C: nop
    
            goto L_8000A9C8;
    }
    // 0x8000A96C: nop

    // 0x8000A970: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000A974: lh          $v0, 0x5A2A($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5A2A);
    // 0x8000A978: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8000A97C: lhu         $a1, 0x5A2A($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X5A2A);
    // 0x8000A980: beq         $v0, $zero, L_8000A9C8
    if (ctx->r2 == 0) {
        // 0x8000A984: nop
    
            goto L_8000A9C8;
    }
    // 0x8000A984: nop

    // 0x8000A988: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000A98C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8000A990: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x8000A994: lhu         $v1, 0x14($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X14);
    // 0x8000A998: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8000A99C: beq         $v0, $zero, L_8000A9B4
    if (ctx->r2 == 0) {
        // 0x8000A9A0: subu        $v0, $a1, $v1
        ctx->r2 = SUB32(ctx->r5, ctx->r3);
            goto L_8000A9B4;
    }
    // 0x8000A9A0: subu        $v0, $a1, $v1
    ctx->r2 = SUB32(ctx->r5, ctx->r3);
    // 0x8000A9A4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000A9A8: lhu         $v0, -0x671C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X671C);
    // 0x8000A9AC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8000A9B0:
    // 0x8000A9B0: addiu       $v0, $v0, 0x31
    ctx->r2 = ADD32(ctx->r2, 0X31);
L_8000A9B4:
    // 0x8000A9B4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000A9B8: sltiu       $v0, $v0, 0x32
    ctx->r2 = ctx->r2 < 0X32 ? 1 : 0;
    // 0x8000A9BC: beq         $v0, $zero, L_8000A9C8
    if (ctx->r2 == 0) {
        // 0x8000A9C0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000A9C8;
    }
    // 0x8000A9C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A9C4: sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
L_8000A9C8:
    // 0x8000A9C8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8000A9CC: jr          $ra
    // 0x8000A9D0: nop

    return;
    // 0x8000A9D0: nop

;}
RECOMP_FUNC void func_8000A9D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A9D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A9D8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000A9DC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8000A9E0: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x8000A9E4: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    // 0x8000A9E8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000A9EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A9F0: jal         0x8003BB8C
    // 0x8000A9F4: sh          $zero, 0x126($s0)
    MEM_H(0X126, ctx->r16) = 0;
    func_8003BB8C(rdram, ctx);
        goto after_0;
    // 0x8000A9F4: sh          $zero, 0x126($s0)
    MEM_H(0X126, ctx->r16) = 0;
    after_0:
    // 0x8000A9F8: lhu         $v0, 0x5C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X5C);
    // 0x8000A9FC: xori        $v1, $v0, 0x2
    ctx->r3 = ctx->r2 ^ 0X2;
    // 0x8000AA00: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8000AA04: xori        $v0, $v0, 0x4E
    ctx->r2 = ctx->r2 ^ 0X4E;
    // 0x8000AA08: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8000AA0C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8000AA10: beq         $v1, $zero, L_8000AA1C
    if (ctx->r3 == 0) {
        // 0x8000AA14: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_8000AA1C;
    }
    // 0x8000AA14: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8000AA18: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
L_8000AA1C:
    // 0x8000AA1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000AA20: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000AA24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000AA28: jr          $ra
    // 0x8000AA2C: nop

    return;
    // 0x8000AA2C: nop

;}
RECOMP_FUNC void func_8000AA30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AA30: lhu         $v0, 0x58($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X58);
    // 0x8000AA34: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8000AA38: lhu         $v1, -0x6DF0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6DF0);
    // 0x8000AA3C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8000AA40: bne         $v1, $zero, L_8000AA54
    if (ctx->r3 != 0) {
        // 0x8000AA44: sh          $v0, 0x58($a0)
        MEM_H(0X58, ctx->r4) = ctx->r2;
            goto L_8000AA54;
    }
    // 0x8000AA44: sh          $v0, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r2;
    // 0x8000AA48: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x8000AA4C: j           L_8000ABCC
    // 0x8000AA50: sh          $zero, 0x56($a0)
    MEM_H(0X56, ctx->r4) = 0;
        goto L_8000ABCC;
    // 0x8000AA50: sh          $zero, 0x56($a0)
    MEM_H(0X56, ctx->r4) = 0;
L_8000AA54:
    // 0x8000AA54: bne         $v0, $zero, L_8000AACC
    if (ctx->r2 != 0) {
        // 0x8000AA58: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_8000AACC;
    }
    // 0x8000AA58: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8000AA5C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8000AA60: lhu         $a1, 0x4($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X4);
    // 0x8000AA64: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8000AA68: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8000AA6C: addiu       $a3, $a3, 0x3F94
    ctx->r7 = ADD32(ctx->r7, 0X3F94);
    // 0x8000AA70: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8000AA74:
    // 0x8000AA74: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8000AA78: sltu        $v0, $v0, $t0
    ctx->r2 = ctx->r2 < ctx->r8 ? 1 : 0;
    // 0x8000AA7C: beql        $v0, $zero, L_8000AA84
    if (ctx->r2 == 0) {
        // 0x8000AA80: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8000AA84;
    }
    goto skip_0;
    // 0x8000AA80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_0:
L_8000AA84:
    // 0x8000AA84: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8000AA88: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8000AA8C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000AA90: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8000AA94: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8000AA98: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000AA9C: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x8000AAA0: lhu         $v0, 0x58($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X58);
    // 0x8000AAA4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000AAA8: bne         $v0, $zero, L_8000AAC0
    if (ctx->r2 != 0) {
        // 0x8000AAAC: addiu       $v0, $a2, -0x1
        ctx->r2 = ADD32(ctx->r6, -0X1);
            goto L_8000AAC0;
    }
    // 0x8000AAAC: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x8000AAB0: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8000AAB4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000AAB8: bnel        $v0, $zero, L_8000AA74
    if (ctx->r2 != 0) {
        // 0x8000AABC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8000AA74;
    }
    goto skip_1;
    // 0x8000AABC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
L_8000AAC0:
    // 0x8000AAC0: sw          $v1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r3;
    // 0x8000AAC4: j           L_8000ABCC
    // 0x8000AAC8: sh          $a1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r5;
        goto L_8000ABCC;
    // 0x8000AAC8: sh          $a1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r5;
L_8000AACC:
    // 0x8000AACC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8000AAD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000AAD4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000AAD8: addiu       $t0, $t0, 0x3F94
    ctx->r8 = ADD32(ctx->r8, 0X3F94);
L_8000AADC:
    // 0x8000AADC: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8000AAE0: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8000AAE4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000AAE8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8000AAEC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8000AAF0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000AAF4: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8000AAF8: lhu         $v0, 0x58($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X58);
    // 0x8000AAFC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000AB00: beq         $v0, $zero, L_8000AB2C
    if (ctx->r2 == 0) {
        // 0x8000AB04: addiu       $v0, $a2, -0x1
        ctx->r2 = ADD32(ctx->r6, -0X1);
            goto L_8000AB2C;
    }
    // 0x8000AB04: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x8000AB08: lw          $v1, 0x40($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X40);
    // 0x8000AB0C: slti        $v0, $v1, 0x1C20
    ctx->r2 = SIGNED(ctx->r3) < 0X1C20 ? 1 : 0;
    // 0x8000AB10: bne         $v0, $zero, L_8000AB2C
    if (ctx->r2 != 0) {
        // 0x8000AB14: addiu       $v0, $a2, -0x1
        ctx->r2 = ADD32(ctx->r6, -0X1);
            goto L_8000AB2C;
    }
    // 0x8000AB14: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x8000AB18: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8000AB1C: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000AB20: beql        $v0, $zero, L_8000AB28
    if (ctx->r2 == 0) {
        // 0x8000AB24: addu        $a3, $v1, $zero
        ctx->r7 = ADD32(ctx->r3, 0);
            goto L_8000AB28;
    }
    goto skip_2;
    // 0x8000AB24: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    skip_2:
L_8000AB28:
    // 0x8000AB28: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
L_8000AB2C:
    // 0x8000AB2C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8000AB30: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000AB34: bne         $v0, $zero, L_8000AADC
    if (ctx->r2 != 0) {
        // 0x8000AB38: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8000AADC;
    }
    // 0x8000AB38: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000AB3C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8000AB40: lhu         $a1, 0x56($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X56);
    // 0x8000AB44: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8000AB48: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000AB4C: addiu       $t0, $t0, 0x3F94
    ctx->r8 = ADD32(ctx->r8, 0X3F94);
    // 0x8000AB50: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8000AB54: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8000AB58:
    // 0x8000AB58: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8000AB5C: sltu        $v0, $v0, $t1
    ctx->r2 = ctx->r2 < ctx->r9 ? 1 : 0;
    // 0x8000AB60: beql        $v0, $zero, L_8000AB68
    if (ctx->r2 == 0) {
        // 0x8000AB64: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8000AB68;
    }
    goto skip_3;
    // 0x8000AB64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_3:
L_8000AB68:
    // 0x8000AB68: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8000AB6C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8000AB70: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000AB74: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8000AB78: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8000AB7C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000AB80: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8000AB84: lhu         $v0, 0x58($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X58);
    // 0x8000AB88: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000AB8C: beql        $v0, $zero, L_8000ABB0
    if (ctx->r2 == 0) {
        // 0x8000AB90: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8000ABB0;
    }
    goto skip_4;
    // 0x8000AB90: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_4:
    // 0x8000AB94: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
    // 0x8000AB98: addiu       $v0, $v0, 0x12C
    ctx->r2 = ADD32(ctx->r2, 0X12C);
    // 0x8000AB9C: slt         $v0, $v0, $a3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8000ABA0: beql        $v0, $zero, L_8000ABC8
    if (ctx->r2 == 0) {
        // 0x8000ABA4: sw          $v1, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->r3;
            goto L_8000ABC8;
    }
    goto skip_5;
    // 0x8000ABA4: sw          $v1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r3;
    skip_5:
    // 0x8000ABA8: j           L_8000ABB4
    // 0x8000ABAC: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
        goto L_8000ABB4;
    // 0x8000ABAC: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
L_8000ABB0:
    // 0x8000ABB0: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
L_8000ABB4:
    // 0x8000ABB4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8000ABB8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000ABBC: bnel        $v0, $zero, L_8000AB58
    if (ctx->r2 != 0) {
        // 0x8000ABC0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8000AB58;
    }
    goto skip_6;
    // 0x8000ABC0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_6:
    // 0x8000ABC4: sw          $v1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r3;
L_8000ABC8:
    // 0x8000ABC8: sh          $a1, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r5;
L_8000ABCC:
    // 0x8000ABCC: jr          $ra
    // 0x8000ABD0: nop

    return;
    // 0x8000ABD0: nop

;}
RECOMP_FUNC void func_8000ABD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ABD4: lh          $v0, 0x14($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X14);
    // 0x8000ABD8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000ABDC: lh          $v1, 0x46A8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X46A8);
    // 0x8000ABE0: addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // 0x8000ABE4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000ABE8: beq         $v0, $zero, L_8000AC04
    if (ctx->r2 == 0) {
                func_8000ABEC(rdram, ctx); return; // was goto L_8000AC04
    }
;}
RECOMP_FUNC void func_8000ABEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ABEC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000ABF0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000ABF4: lw          $v0, 0x3294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3294);
    // 0x8000ABF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000ABFC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000AC00: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x8000AC04: lw          $t0, 0x34($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X34);
    // 0x8000AC08: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x8000AC0C: lhu         $t2, 0x18($a1)
    ctx->r10 = MEM_HU(ctx->r5, 0X18);
    // 0x8000AC10: lhu         $a3, 0x10($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X10);
    // 0x8000AC14: lhu         $v1, 0x12($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X12);
    // 0x8000AC18: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8000AC1C: bnel        $v0, $zero, L_8000AC24
    if (ctx->r2 != 0) {
        // 0x8000AC20: negu        $a3, $a3
        ctx->r7 = SUB32(0, ctx->r7);
            goto L_8000AC24;
    }
    goto skip_0;
    // 0x8000AC20: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    skip_0:
L_8000AC24:
    // 0x8000AC24: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // 0x8000AC28: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8000AC2C: sh          $a3, 0x3E($a0)
    MEM_H(0X3E, ctx->r4) = ctx->r7;
    // 0x8000AC30: sh          $v1, 0x44($a0)
    MEM_H(0X44, ctx->r4) = ctx->r3;
    // 0x8000AC34: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x8000AC38: lhu         $a2, 0x14($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X14);
    // 0x8000AC3C: lhu         $v1, 0x16($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X16);
    // 0x8000AC40: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8000AC44: bnel        $v0, $zero, L_8000AC4C
    if (ctx->r2 != 0) {
        // 0x8000AC48: negu        $a2, $a2
        ctx->r6 = SUB32(0, ctx->r6);
            goto L_8000AC4C;
    }
    goto skip_1;
    // 0x8000AC48: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    skip_1:
L_8000AC4C:
    // 0x8000AC4C: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x8000AC50: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8000AC54: sh          $a2, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r6;
    // 0x8000AC58: sh          $v1, 0x42($a0)
    MEM_H(0X42, ctx->r4) = ctx->r3;
    // 0x8000AC5C: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x8000AC60: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8000AC64: beq         $v0, $zero, L_8000AC74
    if (ctx->r2 == 0) {
        // 0x8000AC68: nop
    
            goto L_8000AC74;
    }
    // 0x8000AC68: nop

    // 0x8000AC6C: sh          $a3, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r7;
    // 0x8000AC70: sh          $a2, 0x3E($a0)
    MEM_H(0X3E, ctx->r4) = ctx->r6;
L_8000AC74:
    // 0x8000AC74: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x8000AC78: lhu         $a3, 0x18($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X18);
    // 0x8000AC7C: lhu         $v1, 0x1A($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X1A);
    // 0x8000AC80: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8000AC84: bnel        $v0, $zero, L_8000AC8C
    if (ctx->r2 != 0) {
        // 0x8000AC88: negu        $a3, $a3
        ctx->r7 = SUB32(0, ctx->r7);
            goto L_8000AC8C;
    }
    goto skip_2;
    // 0x8000AC88: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    skip_2:
L_8000AC8C:
    // 0x8000AC8C: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // 0x8000AC90: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8000AC94: sh          $a3, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r7;
    // 0x8000AC98: sh          $v1, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = ctx->r3;
    // 0x8000AC9C: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x8000ACA0: lhu         $a2, 0x1C($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X1C);
    // 0x8000ACA4: lhu         $v1, 0x1E($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X1E);
    // 0x8000ACA8: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8000ACAC: bnel        $v0, $zero, L_8000ACB4
    if (ctx->r2 != 0) {
        // 0x8000ACB0: negu        $a2, $a2
        ctx->r6 = SUB32(0, ctx->r6);
            goto L_8000ACB4;
    }
    goto skip_3;
    // 0x8000ACB0: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    skip_3:
L_8000ACB4:
    // 0x8000ACB4: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x8000ACB8: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8000ACBC: sh          $a2, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r6;
    // 0x8000ACC0: sh          $v1, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r3;
    // 0x8000ACC4: lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X22);
    // 0x8000ACC8: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8000ACCC: beq         $v0, $zero, L_8000ACDC
    if (ctx->r2 == 0) {
        // 0x8000ACD0: nop
    
            goto L_8000ACDC;
    }
    // 0x8000ACD0: nop

    // 0x8000ACD4: sh          $a3, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r7;
    // 0x8000ACD8: sh          $a2, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r6;
L_8000ACDC:
    // 0x8000ACDC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8000ACE0: jr          $ra
    // 0x8000ACE4: nop

    return;
    // 0x8000ACE4: nop

;}
RECOMP_FUNC void func_8000ACE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ACE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000ACEC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000ACF0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8000ACF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000ACF8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000ACFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8000AD00: sw          $v0, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r2;
    // 0x8000AD04: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x8000AD08: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8000AD0C: beq         $v1, $v0, L_8000ADB4
    if (ctx->r3 == ctx->r2) {
        // 0x8000AD10: slti        $v0, $v1, 0x6
        ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
            goto L_8000ADB4;
    }
    // 0x8000AD10: slti        $v0, $v1, 0x6
    ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x8000AD14: beq         $v0, $zero, L_8000AD3C
    if (ctx->r2 == 0) {
        // 0x8000AD18: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000AD3C;
    }
    // 0x8000AD18: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000AD1C: beq         $v1, $v0, L_8000AD84
    if (ctx->r3 == ctx->r2) {
        // 0x8000AD20: slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_8000AD84;
    }
    // 0x8000AD20: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8000AD24: beq         $v0, $zero, L_8000ADC4
    if (ctx->r2 == 0) {
        // 0x8000AD28: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000ADC4;
    }
    // 0x8000AD28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000AD2C: beq         $v1, $v0, L_8000ADA4
    if (ctx->r3 == ctx->r2) {
        // 0x8000AD30: nop
    
            goto L_8000ADA4;
    }
    // 0x8000AD30: nop

    // 0x8000AD34: j           L_8000ADD4
    // 0x8000AD38: nop

        goto L_8000ADD4;
    // 0x8000AD38: nop

L_8000AD3C:
    // 0x8000AD3C: addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // 0x8000AD40: beq         $v1, $v0, L_8000AE00
    if (ctx->r3 == ctx->r2) {
        // 0x8000AD44: slti        $v0, $v1, 0x34
        ctx->r2 = SIGNED(ctx->r3) < 0X34 ? 1 : 0;
            goto L_8000AE00;
    }
    // 0x8000AD44: slti        $v0, $v1, 0x34
    ctx->r2 = SIGNED(ctx->r3) < 0X34 ? 1 : 0;
    // 0x8000AD48: beq         $v0, $zero, L_8000AD60
    if (ctx->r2 == 0) {
        // 0x8000AD4C: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_8000AD60;
    }
    // 0x8000AD4C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x8000AD50: beq         $v1, $v0, L_8000AD94
    if (ctx->r3 == ctx->r2) {
        // 0x8000AD54: nop
    
            goto L_8000AD94;
    }
    // 0x8000AD54: nop

    // 0x8000AD58: j           L_8000ADD4
    // 0x8000AD5C: nop

        goto L_8000ADD4;
    // 0x8000AD5C: nop

L_8000AD60:
    // 0x8000AD60: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
    // 0x8000AD64: beq         $v1, $v0, L_8000ADA4
    if (ctx->r3 == ctx->r2) {
        // 0x8000AD68: addiu       $v0, $zero, 0x64
        ctx->r2 = ADD32(0, 0X64);
            goto L_8000ADA4;
    }
    // 0x8000AD68: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x8000AD6C: bne         $v1, $v0, L_8000ADD4
    if (ctx->r3 != ctx->r2) {
        // 0x8000AD70: nop
    
            goto L_8000ADD4;
    }
    // 0x8000AD70: nop

    // 0x8000AD74: jal         0x8000AE14
    // 0x8000AD78: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000AE14(rdram, ctx);
        goto after_0;
    // 0x8000AD78: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8000AD7C: j           L_8000AE00
    // 0x8000AD80: nop

        goto L_8000AE00;
    // 0x8000AD80: nop

L_8000AD84:
    // 0x8000AD84: jal         0x8000AF08
    // 0x8000AD88: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000AF08(rdram, ctx);
        goto after_1;
    // 0x8000AD88: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8000AD8C: j           L_8000AE00
    // 0x8000AD90: nop

        goto L_8000AE00;
    // 0x8000AD90: nop

L_8000AD94:
    // 0x8000AD94: jal         0x8000AFE4
    // 0x8000AD98: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000AFE4(rdram, ctx);
        goto after_2;
    // 0x8000AD98: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8000AD9C: j           L_8000AE00
    // 0x8000ADA0: nop

        goto L_8000AE00;
    // 0x8000ADA0: nop

L_8000ADA4:
    // 0x8000ADA4: jal         0x8000AE78
    // 0x8000ADA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000AE78(rdram, ctx);
        goto after_3;
    // 0x8000ADA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8000ADAC: j           L_8000AE00
    // 0x8000ADB0: nop

        goto L_8000AE00;
    // 0x8000ADB0: nop

L_8000ADB4:
    // 0x8000ADB4: jal         0x8000B070
    // 0x8000ADB8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000B070(rdram, ctx);
        goto after_4;
    // 0x8000ADB8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8000ADBC: j           L_8000AE00
    // 0x8000ADC0: nop

        goto L_8000AE00;
    // 0x8000ADC0: nop

L_8000ADC4:
    // 0x8000ADC4: jal         0x8000B0C8
    // 0x8000ADC8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000B0C8(rdram, ctx);
        goto after_5;
    // 0x8000ADC8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x8000ADCC: j           L_8000AE00
    // 0x8000ADD0: nop

        goto L_8000AE00;
    // 0x8000ADD0: nop

L_8000ADD4:
    // 0x8000ADD4: lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XA);
    // 0x8000ADD8: beq         $v0, $zero, L_8000ADF0
    if (ctx->r2 == 0) {
        // 0x8000ADDC: nop
    
            goto L_8000ADF0;
    }
    // 0x8000ADDC: nop

    // 0x8000ADE0: jal         0x8000B12C
    // 0x8000ADE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000B12C(rdram, ctx);
        goto after_6;
    // 0x8000ADE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8000ADE8: j           L_8000AE00
    // 0x8000ADEC: nop

        goto L_8000AE00;
    // 0x8000ADEC: nop

L_8000ADF0:
    // 0x8000ADF0: jal         0x8002A5F0
    // 0x8000ADF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002A5F0(rdram, ctx);
        goto after_7;
    // 0x8000ADF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x8000ADF8: jal         0x8000A90C
    // 0x8000ADFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000A90C(rdram, ctx);
        goto after_8;
    // 0x8000ADFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
L_8000AE00:
    // 0x8000AE00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000AE04: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000AE08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000AE0C: jr          $ra
    // 0x8000AE10: nop

    return;
    // 0x8000AE10: nop

;}
RECOMP_FUNC void func_8000AE14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AE14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000AE18: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8000AE1C: lh          $v0, 0x1C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X1C);
    // 0x8000AE20: bne         $v0, $zero, L_8000AE38
    if (ctx->r2 != 0) {
        // 0x8000AE24: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8000AE38;
    }
    // 0x8000AE24: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000AE28: jal         0x8000AE78
    // 0x8000AE2C: nop

    func_8000AE78(rdram, ctx);
        goto after_0;
    // 0x8000AE2C: nop

    after_0:
    // 0x8000AE30: j           L_8000AE68
    // 0x8000AE34: nop

        goto L_8000AE68;
    // 0x8000AE34: nop

L_8000AE38:
    // 0x8000AE38: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8000AE3C: sh          $v0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r2;
    // 0x8000AE40: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000AE44: lw          $v0, 0x46A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X46A8);
    // 0x8000AE48: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8000AE4C: lw          $a0, 0x31C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C0);
    // 0x8000AE50: lui         $v1, 0xFE66
    ctx->r3 = S32(0XFE66 << 16);
    // 0x8000AE54: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000AE58: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x8000AE5C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000AE60: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000AE64: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
L_8000AE68:
    // 0x8000AE68: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8000AE6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000AE70: jr          $ra
    // 0x8000AE74: nop

    return;
    // 0x8000AE74: nop

;}
RECOMP_FUNC void func_8000AE78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AE78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000AE7C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000AE80: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8000AE84: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8000AE88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000AE8C: lh          $v0, 0x1C($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X1C);
    // 0x8000AE90: beq         $v0, $zero, L_8000AEB4
    if (ctx->r2 == 0) {
        // 0x8000AE94: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8000AEB4;
    }
    // 0x8000AE94: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000AE98: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8000AE9C: sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
    // 0x8000AEA0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000AEA4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8000AEA8: lui         $v0, 0x190
    ctx->r2 = S32(0X190 << 16);
    // 0x8000AEAC: j           L_8000AEF0
    // 0x8000AEB0: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
        goto L_8000AEF0;
    // 0x8000AEB0: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
L_8000AEB4:
    // 0x8000AEB4: jal         0x80018A10
    // 0x8000AEB8: nop

    func_80018A10(rdram, ctx);
        goto after_0;
    // 0x8000AEB8: nop

    after_0:
    // 0x8000AEBC: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8000AEC0: addiu       $s0, $s0, 0x31C0
    ctx->r16 = ADD32(ctx->r16, 0X31C0);
    // 0x8000AEC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000AEC8: jal         0x8000B2F8
    // 0x8000AECC: nop

    func_8000B2F8(rdram, ctx);
        goto after_1;
    // 0x8000AECC: nop

    after_1:
    // 0x8000AED0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000AED4: sh          $v0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r2;
    // 0x8000AED8: sh          $zero, 0x22($s1)
    MEM_H(0X22, ctx->r17) = 0;
    // 0x8000AEDC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8000AEE0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8000AEE4: addiu       $a0, $a0, 0x5BD0
    ctx->r4 = ADD32(ctx->r4, 0X5BD0);
    // 0x8000AEE8: jal         0x80037DDC
    // 0x8000AEEC: nop

    func_80037DDC(rdram, ctx);
        goto after_2;
    // 0x8000AEEC: nop

    after_2:
L_8000AEF0:
    // 0x8000AEF0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8000AEF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AEF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000AEFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000AF00: jr          $ra
    // 0x8000AF04: nop

    return;
    // 0x8000AF04: nop

;}
RECOMP_FUNC void func_8000AF08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AF08: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000AF0C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // FALLTHROUGH: func_8000AF08 falls into func_8000AF10
    func_8000AF10(rdram, ctx);
;}
RECOMP_FUNC void func_8000AF10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AF10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000AF14: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000AF18: lhu         $v1, 0x54($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X54);
    // 0x8000AF1C: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x8000AF20: xor         $v0, $v0, $v1
    ctx->r2 = ctx->r2 ^ ctx->r3;
    // 0x8000AF24: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8000AF28: beq         $v0, $zero, L_8000AF40
    if (ctx->r2 == 0) {
        // 0x8000AF2C: nop
    
            goto L_8000AF40;
    }
    // 0x8000AF2C: nop

    // 0x8000AF30: jal         0x8000B070
    // 0x8000AF34: nop

    func_8000B070(rdram, ctx);
        goto after_0;
    // 0x8000AF34: nop

    after_0:
    // 0x8000AF38: j           L_8000AF48
    // 0x8000AF3C: nop

        goto L_8000AF48;
    // 0x8000AF3C: nop

L_8000AF40:
    // 0x8000AF40: jal         0x8000AF58
    // 0x8000AF44: nop

    func_8000AF58(rdram, ctx);
        goto after_1;
    // 0x8000AF44: nop

    after_1:
L_8000AF48:
    // 0x8000AF48: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000AF4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000AF50: jr          $ra
    // 0x8000AF54: nop

    return;
    // 0x8000AF54: nop

;}
RECOMP_FUNC void func_8000AF58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AF58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000AF5C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000AF60: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8000AF64: lui         $a0, 0x5
    ctx->r4 = S32(0X5 << 16);
    // 0x8000AF68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AF6C: jal         0x80017468
    // 0x8000AF70: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    func_80017468(rdram, ctx);
        goto after_0;
    // 0x8000AF70: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    after_0:
    // 0x8000AF74: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000AF78: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8000AF7C: lui         $v0, 0xFFF9
    ctx->r2 = S32(0XFFF9 << 16);
    // 0x8000AF80: ori         $v0, $v0, 0xAAD7
    ctx->r2 = ctx->r2 | 0XAAD7;
    // 0x8000AF84: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8000AF88: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000AF8C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8000AF90: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x8000AF94: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x8000AF98: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000AF9C: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8000AFA0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000AFA4: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8000AFA8: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x8000AFAC: sh          $v0, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r2;
    // 0x8000AFB0: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x8000AFB4: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x8000AFB8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8000AFBC: lw          $a1, 0x31C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31C0);
    // 0x8000AFC0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8000AFC4: addiu       $a0, $a0, 0x5BF4
    ctx->r4 = ADD32(ctx->r4, 0X5BF4);
    // 0x8000AFC8: jal         0x80037DDC
    // 0x8000AFCC: nop

    func_80037DDC(rdram, ctx);
        goto after_1;
    // 0x8000AFCC: nop

    after_1:
    // 0x8000AFD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000AFD4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000AFD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000AFDC: jr          $ra
    // 0x8000AFE0: nop

    return;
    // 0x8000AFE0: nop

;}
RECOMP_FUNC void func_8000AFE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AFE4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000AFE8: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // FALLTHROUGH: func_8000AFE4 falls into func_8000AFEC
    func_8000AFEC(rdram, ctx);
;}
RECOMP_FUNC void func_8000AFEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AFEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000AFF0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8000AFF4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000AFF8: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x8000AFFC: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x8000B000: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000B004: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8000B008: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000B00C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8000B010: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8000B014: addiu       $v0, $v0, 0x6000
    ctx->r2 = ADD32(ctx->r2, 0X6000);
    // 0x8000B018: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8000B01C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000B020: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8000B024: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x8000B028: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x8000B02C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000B030: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x8000B034: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000B038: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8000B03C: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8000B040: bltz        $v0, L_8000B060
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000B044: lui         $v0, 0xE1
        ctx->r2 = S32(0XE1 << 16);
            goto L_8000B060;
    }
    // 0x8000B044: lui         $v0, 0xE1
    ctx->r2 = S32(0XE1 << 16);
    // 0x8000B048: lw          $v1, 0x18($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X18);
    // 0x8000B04C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000B050: beq         $v0, $zero, L_8000B060
    if (ctx->r2 == 0) {
        // 0x8000B054: nop
    
            goto L_8000B060;
    }
    // 0x8000B054: nop

    // 0x8000B058: jal         0x8000B070
    // 0x8000B05C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_8000B070(rdram, ctx);
        goto after_0;
    // 0x8000B05C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_0:
L_8000B060:
    // 0x8000B060: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000B064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000B068: jr          $ra
    // 0x8000B06C: nop

    return;
    // 0x8000B06C: nop

;}
RECOMP_FUNC void func_8000B070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B074: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000B078: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8000B07C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B080: jal         0x8004C79C
    // 0x8000B084: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_8004C79C(rdram, ctx);
        goto after_0;
    // 0x8000B084: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_0:
    // 0x8000B088: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000B08C: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000B090: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8000B094: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000B098: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000B09C: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8000B0A0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8000B0A4: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x8000B0A8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000B0AC: jal         0x80016F14
    // 0x8000B0B0: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    func_80016F14(rdram, ctx);
        goto after_1;
    // 0x8000B0B0: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    after_1:
    // 0x8000B0B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B0B8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000B0BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000B0C0: jr          $ra
    // 0x8000B0C4: nop

    return;
    // 0x8000B0C4: nop

;}
RECOMP_FUNC void func_8000B0C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B0C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B0CC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8000B0D0: lh          $v0, 0x1C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X1C);
    // 0x8000B0D4: beq         $v0, $zero, L_8000B0E8
    if (ctx->r2 == 0) {
        // 0x8000B0D8: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8000B0E8;
    }
    // 0x8000B0D8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000B0DC: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8000B0E0: j           L_8000B11C
    // 0x8000B0E4: sh          $v0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r2;
        goto L_8000B11C;
    // 0x8000B0E4: sh          $v0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r2;
L_8000B0E8:
    // 0x8000B0E8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000B0EC: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000B0F0: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8000B0F4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8000B0F8: lw          $v0, 0x31C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C0);
    // 0x8000B0FC: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8000B100: addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // 0x8000B104: sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
    // 0x8000B108: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000B10C: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8000B110: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8000B114: jal         0x8000B5D0
    // 0x8000B118: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    func_8000B5D0(rdram, ctx);
        goto after_0;
    // 0x8000B118: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    after_0:
L_8000B11C:
    // 0x8000B11C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8000B120: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000B124: jr          $ra
    // 0x8000B128: nop

    return;
    // 0x8000B128: nop

;}
RECOMP_FUNC void func_8000B12C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B12C: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // 0x8000B130: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000B134: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8000B138: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8000B13C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8000B140: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8000B144: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8000B148: lw          $v1, 0x31C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C0);
    // 0x8000B14C: lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X22);
    // 0x8000B150: xori        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 ^ 0X10;
    // 0x8000B154: jr          $ra
    // 0x8000B158: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    return;
    // 0x8000B158: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
;}
