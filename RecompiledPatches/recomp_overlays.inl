#include "recomp.h"
#include "librecomp/sections.h"

// Empty patches for Rampage - no function patches
static SectionTableEntry section_table[] = {
    { .rom_addr = 0, .ram_addr = 0, .size = 0, .funcs = nullptr, .num_funcs = 0, .relocs = nullptr, .num_relocs = 0, .index = 0 },
};
static FunctionExport export_table[] = {
    { .name = nullptr, .ram_addr = 0 },
};
static const char* event_names[] = {
    nullptr,
};
static ManualPatchSymbol manual_patch_symbols[] = {
    { .ram_addr = 0, .func = nullptr },
};
