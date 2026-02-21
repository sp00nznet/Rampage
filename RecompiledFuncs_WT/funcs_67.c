#include "recomp.h"
#include "funcs.h"
#include "sn64_rom_helpers.h"
#include <stdio.h>

RECOMP_FUNC void stub_8013A128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_8013A650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_8013A89C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_8013ABB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_8013AE84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_8013B0D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_8013B3B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_8013B620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_8013B668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_8013BD28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_8013E750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_8013E788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_80142BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // Get/create SN64 handle. Returns a handle used by stub_801436F0/stub_8014376C.
    // Return a dummy non-zero handle so callers don't treat it as failure.
    static int sn64_handle_counter = 1;
    ctx->r2 = (uint64_t)(uint32_t)sn64_handle_counter++;
    fprintf(stderr, "[SN64] getHandle() -> %u\n", (unsigned)ctx->r2);
    fflush(stderr);
;}
RECOMP_FUNC void stub_801430E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // Get SN64 seq table size. a0 = handle (ignored), a1 = ROM address (0x9172D0).
    // Seq table runs from 0x9172D0 to approximately 0x9253C0 (sample data start).
    // Size = 0x9253C0 - 0x9172D0 = 0xE0F0.
    uint32_t rom_addr = (uint32_t)ctx->r5;
    ctx->r2 = (uint64_t)0xE0F0;
    fprintf(stderr, "[SN64] getSeqTableSize(ROM=0x%08X) -> 0x%X\n",
            rom_addr, (unsigned)ctx->r2);
    fflush(stderr);
;}
RECOMP_FUNC void stub_801431A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // Load SN64 seq table from ROM to RDRAM.
    // a0 = handle, a1 = ROM address (0x9172D0), a2 = flags (0), a3 = dest buffer
    // stack[0x10] = size (from stub_801430E0)
    uint32_t rom_addr = (uint32_t)ctx->r5;
    uint32_t rdram_dest = (uint32_t)ctx->r7;
    uint32_t size = MEM_W(0x10, ctx->r29);
    fprintf(stderr, "[SN64] loadSeqTable(ROM=0x%08X, dest=0x%08X, size=0x%X)\n",
            rom_addr, rdram_dest, size);
    fflush(stderr);
    if (size > 0 && rdram_dest != 0) {
        sn64_rom_to_rdram(rdram, rom_addr, rdram_dest, size);
    }
    ctx->r2 = 0; // return success
;}
RECOMP_FUNC void stub_801436F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // Create SN64 sequence player (BGM). a0 = channel (0), a1 = handle.
    // No-op stub - no real audio playback.
    fprintf(stderr, "[SN64] createSeqPlayer(ch=%u, handle=%u) (stub)\n",
            (unsigned)ctx->r4, (unsigned)ctx->r5);
    fflush(stderr);
    ctx->r2 = 0;
;}
RECOMP_FUNC void stub_8014376C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
    // Create SN64 sequence player (SFX). a0 = channel (0), a1 = handle, a2 = heap ptr.
    // No-op stub - no real audio playback.
    fprintf(stderr, "[SN64] createSfxPlayer(ch=%u, handle=%u) (stub)\n",
            (unsigned)ctx->r4, (unsigned)ctx->r5);
    fflush(stderr);
    ctx->r2 = 0;
;}
RECOMP_FUNC void stub_801459C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_8014F280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_8014F648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_802C1028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_80303030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_80543054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_80643068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_80703070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_80842084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_80842108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_80E59AB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_81002000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_81042080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_81043100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_8109FF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_81800030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_81880200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818C0000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818C1084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818C1180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818C2108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818C4184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818C5000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818C5294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818C5328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818C7000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818C8420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818C9000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818C9398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818C94A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818CA41C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818CF7BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void stub_818D394C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = ctx->hi, lo = ctx->lo, result = 0;
    int c1cs = 0;
;}
