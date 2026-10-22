cmake_minimum_required(VERSION 3.20)

project(RampageRecompiled VERSION 0.2.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# =============================================================================
# Options
# =============================================================================
set(RAMPAGE_GAME "wt" CACHE STRING "Game to build: wt (World Tour) or r2 (Universal Tour)")
set_property(CACHE RAMPAGE_GAME PROPERTY STRINGS wt r2)
# Toolkits: deps/ when Setup fetched them there, else sibling checkouts (docs/building.md lists the
# branches each needs).
foreach(dep N64ModernRuntime rt64)
    if(EXISTS "${CMAKE_SOURCE_DIR}/deps/${dep}/CMakeLists.txt")
        set(default_${dep} "${CMAKE_SOURCE_DIR}/deps/${dep}")
    else()
        set(default_${dep} "${CMAKE_SOURCE_DIR}/../${dep}")
    endif()
endforeach()
set(N64_MODERN_RUNTIME_DIR "${default_N64ModernRuntime}" CACHE PATH "Path to N64ModernRuntime")
set(RT64_DIR "${default_rt64}" CACHE PATH "Path to RT64")

# Generated code: made locally from the player's ROM by tools/regen.py, never committed.
set(GEN_DIR "${CMAKE_SOURCE_DIR}/gen/${RAMPAGE_GAME}")
if(NOT EXISTS "${GEN_DIR}/recomp_overlays.inl")
    message(FATAL_ERROR "${GEN_DIR} is missing. Run: py tools/regen.py ${RAMPAGE_GAME}")
endif()

if(RAMPAGE_GAME STREQUAL "r2")
    set(EXE_NAME Rampage2)
else()
    set(EXE_NAME RampageWorldTour)
endif()

# =============================================================================
# Toolkits
# =============================================================================
# SDL2: the Windows build RT64 ships (and links against itself).
set(SDL2_DIR_WIN "${RT64_DIR}/src/contrib/mupen64plus-win32-deps/SDL2-2.26.3")

set(RT64_STATIC ON CACHE BOOL "Build RT64 as a static library" FORCE)
add_subdirectory(${RT64_DIR} ${CMAKE_BINARY_DIR}/rt64)

add_subdirectory(${N64_MODERN_RUNTIME_DIR} ${CMAKE_BINARY_DIR}/N64ModernRuntime)

# =============================================================================
# Recompiled game code, plus the hand-written functions it calls
# =============================================================================
file(GLOB GEN_SOURCES "${GEN_DIR}/funcs_*.c")
add_library(RecompiledFuncs STATIC ${GEN_SOURCES} src/${RAMPAGE_GAME}_stubs.c)
target_include_directories(RecompiledFuncs PRIVATE
    ${N64_MODERN_RUNTIME_DIR}/N64Recomp/include
    ${GEN_DIR}
    ${CMAKE_SOURCE_DIR}/src
)
# Hook text in the game's .toml calls helpers declared in hooks.h.
if(MSVC)
    target_compile_options(RecompiledFuncs PRIVATE /FI${CMAKE_SOURCE_DIR}/src/hooks.h /bigobj /wd4101 /wd4102 /wd4244)
else()
    target_compile_options(RecompiledFuncs PRIVATE -include ${CMAKE_SOURCE_DIR}/src/hooks.h -fno-strict-aliasing)
endif()

# =============================================================================
# Executable
# =============================================================================
add_executable(${EXE_NAME}
    src/main.cpp
    src/overlays.cpp
    src/rt64_render_context.cpp
    src/config.cpp
    src/input.cpp
    src/sn64_rom_helpers.cpp
    ${GEN_DIR}/lookup.cpp
)
target_include_directories(${EXE_NAME} PRIVATE
    ${N64_MODERN_RUNTIME_DIR}/N64Recomp/include
    ${N64_MODERN_RUNTIME_DIR}/librecomp/include
    ${N64_MODERN_RUNTIME_DIR}/ultramodern/include
    ${RT64_DIR}/src
    ${RT64_DIR}/src/contrib
    ${RT64_DIR}/src/contrib/hlslpp/include
    ${RT64_DIR}/src/contrib/plume
    ${RT64_DIR}/src/contrib/imgui
    ${GEN_DIR}
    ${CMAKE_SOURCE_DIR}/src
    ${SDL2_DIR_WIN}/include
)
# RT64's headers expect these (normally set at its directory scope).
target_compile_definitions(${EXE_NAME} PRIVATE NOMINMAX HLSL_CPU FFX_GCC
    RAMPAGE_VERSION="${PROJECT_VERSION}" $<$<STREQUAL:${RAMPAGE_GAME},r2>:RAMPAGE_R2>)

target_link_directories(${EXE_NAME} PRIVATE ${SDL2_DIR_WIN}/lib/x64)
target_link_libraries(${EXE_NAME} PRIVATE RecompiledFuncs librecomp ultramodern rt64 SDL2 SDL2main)

if(WIN32)
    target_link_libraries(${EXE_NAME} PRIVATE dxgi d3d12 d3dcompiler dbghelp)
    # The .map lets crash traces name recompiled functions (src/main.cpp).
    target_link_options(${EXE_NAME} PRIVATE /MAP)
    # RT64 loads the DXC runtime from next to the exe; without it setup silently skips init.
    add_custom_command(TARGET ${EXE_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${RT64_DIR}/src/contrib/dxc/bin/x64/dxil.dll ${RT64_DIR}/src/contrib/dxc/bin/x64/dxcompiler.dll
        ${SDL2_DIR_WIN}/lib/x64/SDL2.dll
        $<TARGET_FILE_DIR:${EXE_NAME}>)
endif()
