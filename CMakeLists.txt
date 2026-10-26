cmake_minimum_required(VERSION 3.20)

project(RampageRecompiled VERSION 0.3.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# The RSP vector unit code (librecomp, aspMain) uses SSE4.1 on x86; MSVC needs no flag for it.
if(NOT MSVC AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64")
    add_compile_options(-msse4.1)
endif()

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
set(ASPMAIN "${CMAKE_SOURCE_DIR}/rsp/aspMain_${RAMPAGE_GAME}.cpp")
if(NOT EXISTS "${ASPMAIN}")
    message(FATAL_ERROR "${ASPMAIN} is missing. Run: RSPRecomp rsp/aspMain_${RAMPAGE_GAME}.toml (setup does it)")
endif()

if(RAMPAGE_GAME STREQUAL "r2")
    set(EXE_NAME Rampage2)
else()
    set(EXE_NAME RampageWorldTour)
endif()

# =============================================================================
# SDL2: on Windows the build RT64 ships (RT64 links it by bare name from this folder); on Linux and
# macOS the system's (apt/dnf/pacman libsdl2, brew sdl2); on Android SDL's source, staged by
# scripts/build_android.sh
# =============================================================================
if(ANDROID)
    # Shared: SDL's Java side loads libSDL2.so before libmain.so.
    set(SDL_SHARED ON CACHE BOOL "" FORCE)
    set(SDL_STATIC OFF CACHE BOOL "" FORCE)
    add_subdirectory(${SDL2_SOURCE_DIR} ${CMAKE_BINARY_DIR}/SDL)
    set(SDL2_INCLUDE_DIRS "${SDL2_SOURCE_DIR}/include") # RT64 reads it
elseif(NOT WIN32)
    find_package(SDL2 REQUIRED)
    if(NOT TARGET SDL2::SDL2main)
        add_library(SDL2::SDL2main INTERFACE IMPORTED)
    endif()
else()
    set(SDL2_DIR_WIN "${RT64_DIR}/src/contrib/mupen64plus-win32-deps/SDL2-2.26.3")
    link_directories("${SDL2_DIR_WIN}/lib/x64")
    add_library(SDL2::SDL2 SHARED IMPORTED)
    set_target_properties(SDL2::SDL2 PROPERTIES
        IMPORTED_LOCATION "${SDL2_DIR_WIN}/lib/x64/SDL2.dll"
        IMPORTED_IMPLIB "${SDL2_DIR_WIN}/lib/x64/SDL2.lib"
        INTERFACE_INCLUDE_DIRECTORIES "${SDL2_DIR_WIN}/include")
    add_library(SDL2::SDL2main STATIC IMPORTED)
    set_target_properties(SDL2::SDL2main PROPERTIES IMPORTED_LOCATION "${SDL2_DIR_WIN}/lib/x64/SDL2main.lib")
endif()

# =============================================================================
# Toolkits
# =============================================================================
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
    target_compile_options(RecompiledFuncs PRIVATE -include ${CMAKE_SOURCE_DIR}/src/hooks.h -fno-strict-aliasing -Wno-implicit-function-declaration)
endif()

# =============================================================================
# Executable (on Android, libmain.so: SDL's Java side loads it and calls its SDL_main)
# =============================================================================
add_subdirectory(frontend)

set(GAME_SOURCES src/main.cpp src/overlays.cpp ${GEN_DIR}/lookup.cpp ${ASPMAIN})
if(ANDROID)
    add_library(${EXE_NAME} SHARED ${GAME_SOURCES})
    set_target_properties(${EXE_NAME} PROPERTIES OUTPUT_NAME main)
else()
    add_executable(${EXE_NAME} ${GAME_SOURCES})
endif()
target_include_directories(${EXE_NAME} PRIVATE
    ${N64_MODERN_RUNTIME_DIR}/N64Recomp/include
    ${N64_MODERN_RUNTIME_DIR}/librecomp/include
    ${N64_MODERN_RUNTIME_DIR}/ultramodern/include
    ${GEN_DIR}
    ${CMAKE_SOURCE_DIR}/src
)
target_compile_definitions(${EXE_NAME} PRIVATE NOMINMAX
    RAMPAGE_VERSION="${PROJECT_VERSION}" $<$<STREQUAL:${RAMPAGE_GAME},r2>:RAMPAGE_R2>)
target_link_libraries(${EXE_NAME} PRIVATE RecompiledFuncs librecomp ultramodern n64frontend rt64 SDL2::SDL2 SDL2::SDL2main)

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
