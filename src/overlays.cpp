// Registers the section table N64Recomp generates for the selected game (gen/<game>/recomp_overlays.inl).
#include "librecomp/overlays.hpp"
#include "librecomp/sections.h"

#include "recomp_overlays.inl"

void register_rampage_overlays() {
    recomp::overlays::overlay_section_table_data_t sections{
        .code_sections = section_table,
        .num_code_sections = ARRLEN(section_table),
        .total_num_sections = num_sections,
    };
    recomp::overlays::overlays_by_index_t overlays{
        .table = overlay_sections_by_index,
        .len = ARRLEN(overlay_sections_by_index),
    };
    recomp::overlays::register_overlays(sections, overlays);
}
