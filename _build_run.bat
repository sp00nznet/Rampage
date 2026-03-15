@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
set PATH=C:\Program Files\LLVM\bin;%PATH%

cd /d D:\rampage

REM Parse arguments: "clean" for clean build, "r2" for Universal Tour
set CLEAN=0
set GAME=wt
for %%a in (%*) do (
    if "%%a"=="clean" set CLEAN=1
    if "%%a"=="r2" set GAME=r2
    if "%%a"=="wt" set GAME=wt
)

if %CLEAN%==1 (
    if exist build (
        rmdir /s /q build
    )
)

if "%GAME%"=="r2" (
    echo ====== BUILDING: Rampage 2 - Universal Tour ======
) else (
    echo ====== BUILDING: Rampage - World Tour ======
)

echo ====== CONFIGURING ======
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo ^
    -DCMAKE_C_COMPILER="C:/Program Files/LLVM/bin/clang-cl.exe" ^
    -DCMAKE_CXX_COMPILER="C:/Program Files/LLVM/bin/clang-cl.exe" ^
    -DCMAKE_LINKER="C:/Program Files/LLVM/bin/lld-link.exe" ^
    -DCMAKE_MAKE_PROGRAM="C:\Users\nedch\AppData\Local\Programs\Python\Python311\Scripts\ninja.exe" ^
    -DRAMPAGE_GAME=%GAME%

if %errorlevel% neq 0 (
    echo ====== CONFIGURE FAILED ======
    exit /b 1
)

echo ====== BUILDING ======
cmake --build build --config RelWithDebInfo

if %errorlevel% neq 0 (
    echo ====== BUILD FAILED ======
    exit /b 1
)

echo ====== BUILD SUCCEEDED ======
