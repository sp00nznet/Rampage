#include "ovl_patches.hpp"
#include "../../RecompiledPatches/patches_bin.h"
#include "../../RecompiledPatches/recomp_overlays.inl"

#include "librecomp/overlays.hpp"
#include "librecomp/game.hpp"

void zelda64::register_patches() {
    // No function patches for Rampage - register empty tables
    recomp::overlays::register_patches(reinterpret_cast<const char*>(rampage_patches_bin), 0, section_table, 0);
    recomp::overlays::register_base_exports(export_table);
    recomp::overlays::register_base_events(event_names);
    recomp::overlays::register_manual_patch_symbols(manual_patch_symbols);
}
