# n64frontend: config, input, RT64 hookup, launcher/menu and netplay shared by our N64 recomps.
# The including project sets RT64_DIR and N64_MODERN_RUNTIME_DIR and adds rt64, librecomp,
# ultramodern and SDL2 first.

add_library(n64frontend STATIC
    src/app.cpp
    src/audio.cpp
    src/cheats.cpp
    src/config.cpp
    src/det.cpp
    src/input.cpp
    src/netplay.cpp
    src/rt64_context.cpp
    src/ui.cpp
)

target_include_directories(n64frontend
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${N64_MODERN_RUNTIME_DIR}/N64Recomp/include
        ${N64_MODERN_RUNTIME_DIR}/librecomp/include
        ${N64_MODERN_RUNTIME_DIR}/ultramodern/include
    PRIVATE
        ${RT64_DIR}/src
        ${RT64_DIR}/src/contrib
        ${RT64_DIR}/src/contrib/hlslpp/include
        ${RT64_DIR}/src/contrib/plume
        ${RT64_DIR}/src/contrib/imgui
        ${RT64_DIR}/src/contrib/mupen64plus-core/src/api
)

# RT64's headers expect these (RT64 sets them at directory scope).
target_compile_definitions(n64frontend PRIVATE NOMINMAX HLSL_CPU FFX_GCC IMGUI_IMPL_VULKAN_NO_PROTOTYPES)
if(APPLE)
    # ImGui's Metal backend in its metal-cpp form, as RT64 builds it.
    target_compile_definitions(n64frontend PRIVATE IMGUI_IMPL_METAL_CPP)
    target_include_directories(n64frontend PRIVATE ${RT64_DIR}/src/contrib/plume/contrib/metal-cpp)
endif()

target_link_libraries(n64frontend PUBLIC librecomp ultramodern rt64 SDL2::SDL2)
if(WIN32)
    target_link_libraries(n64frontend PUBLIC ws2_32 d3d12 dxgi)
endif()
