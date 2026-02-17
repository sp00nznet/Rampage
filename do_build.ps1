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

# Clean build directory
if (Test-Path build) {
    Remove-Item -Recurse -Force build
}

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

Write-Host "====== BUILDING ======"
& cmake --build build --config Release
if ($LASTEXITCODE -ne 0) {
    Write-Host "====== BUILD FAILED ======"
    exit 1
}

Write-Host "====== BUILD SUCCEEDED ======"
