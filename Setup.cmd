@echo off
rem Rampage Recompiled: builds the games from your own ROMs. See README.md, Getting Started.
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0tools\setup.ps1" %*
set RC=%ERRORLEVEL%
if not defined RECOMP_LAUNCHER pause
exit /b %RC%
