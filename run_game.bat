@echo off
cd /d "%~dp0"

if not exist "build\RampageRecompiled.exe" (
    echo ERROR: build\RampageRecompiled.exe not found. Run _build_run.bat first.
    pause
    exit /b 1
)

echo Starting Rampage World Tour...
start "" "build\RampageRecompiled.exe"
