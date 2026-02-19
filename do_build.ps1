# PowerShell build script for Rampage Recompiled
$ErrorActionPreference = "Continue"

# Import MSVC environment
$vcvarsPath = "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat"
$envOutput = cmd /c "`"$vcvarsPath`" x64 >nul 2>&1 && set" 2>&1
foreach ($line in $envOutput) {
    if ($line -match "^([^=]+)=(.*)$") {
        [Environment]::SetEnvironmentVariable($matches[1], $matches[2], "Process")
    }
}

Set-Location D:\rampage

# Add LLVM to PATH so RT64 shader preprocessing can find bare 'clang'
$env:PATH = "C:\Program Files\LLVM\bin;$env:PATH"

# Use -clean flag to force clean build
$doClean = $args -contains "-clean"
if ($doClean -and (Test-Path build)) {
    Write-Host "====== CLEANING ======"
    Remove-Item -Recurse -Force build
}

# Configure if needed (build directory doesn't exist or was cleaned)
if (-not (Test-Path build\build.ninja)) {
    Write-Host "====== CONFIGURING ======"
    $ninjaPath = "C:\Users\nedch\AppData\Local\Programs\Python\Python311\Scripts\ninja.exe"
    $clangCl = "C:\Program Files\LLVM\bin\clang-cl.exe"
    $lldLink = "C:\Program Files\LLVM\bin\lld-link.exe"
    & cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release `
        "-DCMAKE_C_COMPILER=$clangCl" `
        "-DCMAKE_CXX_COMPILER=$clangCl" `
        "-DCMAKE_LINKER=$lldLink" `
        "-DCMAKE_MAKE_PROGRAM=$ninjaPath"

    if ($LASTEXITCODE -ne 0) {
        Write-Host "====== CONFIGURE FAILED ======"
        exit 1
    }

    # Patch SDL2 for Clang 12+ compatibility (_m_prefetch builtin conflict)
    $sdlEndian = "build\_deps\sdl2-src\include\SDL_endian.h"
    if (Test-Path $sdlEndian) {
        (Get-Content $sdlEndian -Raw) -replace '#ifdef __clang__\r?\n#ifndef __PRFCHWINTRIN_H', '#if defined(__clang__) && (__clang_major__ < 12)
#ifndef __PRFCHWINTRIN_H' | Set-Content $sdlEndian -NoNewline
        Write-Host "Patched SDL_endian.h for Clang 21 compatibility"
    }
}

Write-Host "====== BUILDING ======"
& cmake --build build --config Release
if ($LASTEXITCODE -ne 0) {
    Write-Host "====== BUILD FAILED ======"
    exit 1
}

Write-Host "====== BUILD SUCCEEDED ======"
