<#
Rampage Recompiled setup: from a plain download to a launcher for each game you own.

    Setup.cmd                          double-click; asks before installing anything
    powershell -File tools\setup.ps1 -Yes -Game "D:\roms"   no questions (recomp-launcher uses this)
    ... -Targets pc,android,linux-arm64                   also build for other machines, in Docker

Targets: pc (this computer, the default) and the builds for other machines in scripts\targets.tsv,
which tools\setup-builds.ps1 makes after this computer's (docs/other-builds.md).

It runs exactly the steps docs/building.md lists, skips the ones already done (so a rerun after a
failure resumes), and logs everything to logs\setup.log. The ROMs stay on this machine: they are
copied into the repo folder (gitignored) and recompiled here. Nothing from the games is downloaded.
#>
param(
    [switch]$Yes,          # install missing prerequisites without asking
    [string]$Game = "",    # folder holding the ROMs (default: the repo folder)
    [string]$Targets = "pc" # comma-separated: pc and/or scripts\targets.tsv's ids
)

$ErrorActionPreference = "Stop"
$Root = Split-Path -Parent $PSScriptRoot
Set-Location $Root
New-Item -ItemType Directory -Force logs, deps | Out-Null
$Log = Join-Path $Root "logs\setup.log"
"Rampage Recompiled setup, $(Get-Date)" | Out-File $Log -Encoding utf8

# Toolkits, pinned: each is sp00nznet's fork carrying the fixes Rampage needs (docs/building.md).
$Toolkits = @(
    @{ Dir = "N64Recomp";        Repo = "https://github.com/sp00nznet/N64Recomp";        Ref = "fix/fallthrough-tail-call" },
    @{ Dir = "N64ModernRuntime"; Repo = "https://github.com/sp00nznet/N64ModernRuntime"; Ref = "rampage" },
    @{ Dir = "rt64";             Repo = "https://github.com/sp00nznet/rt64";             Ref = "rampage" }
)
$Games = @(
    @{ Id = "wt"; Title = "Rampage World Tour";       Header = "RAMPAGE ";  Crc = "C29FF9E4"; Rom = "Rampage - World Tour (U) [!].z64";       Exe = "RampageWorldTour.exe" },
    @{ Id = "r2"; Title = "Rampage 2 Universal Tour"; Header = "RAMPAGE2";  Crc = "673D099B"; Rom = "Rampage 2 - Universal Tour (U) [!].z64"; Exe = "Rampage2.exe" }
)
$Steps = 7
$picked = @($Targets -split ',' | ForEach-Object { $_.Trim() } | Where-Object { $_ })
$others = @($picked | Where-Object { $_ -ne 'pc' })
# Only other machines: that's tools\setup-builds.ps1's job alone.
if ($picked -notcontains 'pc') {
    & (Join-Path $PSScriptRoot "setup-builds.ps1") -Yes:$Yes -Game $Game -Targets ($others -join ',')
    exit $LASTEXITCODE
}

function Step($n, $what) { $line = "[$n/$Steps] $what"; Write-Host $line; $line | Out-File $Log -Append -Encoding utf8 }
function Stop-Setup($why) {
    Write-Host ""
    Write-Host "Setup stopped: $why" -ForegroundColor Red
    Write-Host "Details are in $Log"
    "Setup stopped: $why" | Out-File $Log -Append -Encoding utf8
    exit 1
}
# Runs a native command with its output in the log; stops with $why if it fails.
function Run($why, $exe, [string[]]$arguments) {
    "> $exe $($arguments -join ' ')" | Out-File $Log -Append -Encoding utf8
    # Windows PowerShell turns a native program's stderr into errors; only the exit code counts.
    $old = $ErrorActionPreference
    $ErrorActionPreference = "Continue"
    $global:LASTEXITCODE = 0
    & $exe @arguments 2>&1 | ForEach-Object { "$_" } | Out-File $Log -Append -Encoding utf8
    $code = $LASTEXITCODE
    $ErrorActionPreference = $old
    if ($code -ne 0) { Stop-Setup $why }
}
function Ask($question) {
    if ($Yes) { return $true }
    return (Read-Host "$question [Y/n]") -notmatch '^[nN]'
}
function Refresh-Path {
    $env:PATH = [Environment]::GetEnvironmentVariable("PATH", "Machine") + ";" + [Environment]::GetEnvironmentVariable("PATH", "User")
}
function Find-VS {
    $vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
    if (-not (Test-Path $vswhere)) { return $null }
    return & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
}

# ---------------------------------------------------------------------------------------------
Step 1 "Checking the tools it needs"
$need = @()
if (-not (Get-Command git -ErrorAction SilentlyContinue))   { $need += @{ Name = "Git"; Id = "Git.Git"; Size = "about 300 MB" } }
if (-not (Get-Command py -ErrorAction SilentlyContinue))    { $need += @{ Name = "Python 3"; Id = "Python.Python.3.12"; Size = "about 100 MB" } }
if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) { $need += @{ Name = "CMake"; Id = "Kitware.CMake"; Size = "about 100 MB" } }
if (-not (Find-VS)) { $need += @{ Name = "Visual Studio 2022 Build Tools (C++)"; Id = "Microsoft.VisualStudio.2022.BuildTools"; Size = "about 3 GB";
    Extra = @("--override", "--add Microsoft.VisualStudio.Workload.VCTools --includeRecommended --passive --wait") } }
foreach ($t in $need) {
    if (-not (Get-Command winget -ErrorAction SilentlyContinue)) {
        Stop-Setup "$($t.Name) is missing and winget isn't available to install it. Install $($t.Name) yourself, then run Setup again."
    }
    if (-not (Ask "$($t.Name) is needed to build the game and isn't installed. Install it with winget ($($t.Size))?")) {
        Stop-Setup "$($t.Name) is needed. Install it, then run Setup again."
    }
    $args_ = @("install", "--id", $t.Id, "-e", "--accept-source-agreements", "--accept-package-agreements") + $t.Extra
    Run "installing $($t.Name) failed" "winget" $args_
    Refresh-Path
}
$vs = Find-VS
if (-not $vs) { Stop-Setup "Visual Studio's C++ build tools didn't install. Install the 'Desktop development with C++' workload, then run Setup again." }

# ---------------------------------------------------------------------------------------------
Step 2 "Finding your ROMs"
$searchDirs = @($Root) + $(if ($Game) { @($Game) } else { @() })
$found = @()
foreach ($g in $Games) {
    $target = Join-Path $Root $g.Rom
    $match = $null
    foreach ($dir in $searchDirs) {
        foreach ($f in Get-ChildItem -Path $dir -File -Include *.z64 -Recurse -Depth 1 -ErrorAction SilentlyContinue) {
            $bytes = [IO.File]::ReadAllBytes($f.FullName)
            if ($bytes.Length -lt 0x40) { continue }
            $name = [Text.Encoding]::ASCII.GetString($bytes, 0x20, 8)
            $crc = ($bytes[0x10..0x13] | ForEach-Object { $_.ToString("X2") }) -join ""
            if ($name -eq $g.Header -and $crc -eq $g.Crc) { $match = $f.FullName; break }
        }
        if ($match) { break }
    }
    if (-not $match) { "  $($g.Title): no ROM found" | Out-File $Log -Append -Encoding utf8; continue }
    if ($match -ne $target) { Copy-Item $match $target -Force }
    Write-Host "  $($g.Title): $match"
    $found += $g
}
if (-not $found) {
    Stop-Setup "No Rampage ROM found. Put your USA .z64 of Rampage World Tour or Rampage 2 in this folder (or pass -Game <folder>), then run Setup again."
}

# ---------------------------------------------------------------------------------------------
Step 3 "Getting the recompiler, runtime and renderer"
foreach ($t in $Toolkits) {
    $dir = Join-Path "deps" $t.Dir
    if (Test-Path (Join-Path $dir ".git")) {
        # From an earlier setup: bring it up to the pinned branch (an update may need newer fixes).
        Run "updating $($t.Dir) failed (no internet, or see the log)" "git" @("-C", $dir, "fetch", "-q", "origin", $t.Ref)
        Run "updating $($t.Dir) failed" "git" @("-C", $dir, "checkout", "-q", "FETCH_HEAD")
        Run "updating $($t.Dir) failed" "git" @("-C", $dir, "-c", "core.longpaths=true", "submodule", "update", "-q", "--init", "--recursive")
        continue
    }
    # core.longpaths: the toolkits' submodules have paths past Windows' 260-character limit.
    Run "downloading $($t.Dir) failed (no internet, or see the log)" "git" @("-c", "core.longpaths=true", "clone", "--recurse-submodules", "--branch", $t.Ref, $t.Repo, $dir)
}

# ---------------------------------------------------------------------------------------------
Step 4 "Building the recompiler"
$recomp = Join-Path $Root "deps\N64Recomp\build\Release\N64Recomp.exe"
$rsprecomp = Join-Path $Root "deps\N64Recomp\build\Release\RSPRecomp.exe"
if (-not (Test-Path $recomp) -or -not (Test-Path $rsprecomp)) {
    Run "configuring N64Recomp failed" "cmake" @("-S", "deps\N64Recomp", "-B", "deps\N64Recomp\build", "-G", "Visual Studio 17 2022", "-A", "x64")
    Run "building N64Recomp failed" "cmake" @("--build", "deps\N64Recomp\build", "--config", "Release", "--target", "N64RecompCLI", "RSPRecomp", "--parallel")
}
$env:N64RECOMP = $recomp
$env:RSPRECOMP = $rsprecomp

# ---------------------------------------------------------------------------------------------
Step 5 "Recompiling your games (a minute each)"
# regen.py skips a game whose inputs haven't changed since its last run.
foreach ($g in $found) {
    Run "recompiling $($g.Title) failed" "py" @("tools\regen.py", $g.Id)
}

# ---------------------------------------------------------------------------------------------
Step 6 "Building (the first build takes 20 to 40 minutes)"
foreach ($g in $found) {
    $build = "build\$($g.Id)"
    Run "configuring $($g.Title) failed" "cmake" @("-S", ".", "-B", $build, "-G", "Visual Studio 17 2022", "-A", "x64", "-DRAMPAGE_GAME=$($g.Id)")
    Run "building $($g.Title) failed" "cmake" @("--build", $build, "--config", "Release", "--parallel")
}

# ---------------------------------------------------------------------------------------------
Step 7 "Making launchers"
foreach ($g in $found) {
    $launcher = Join-Path $Root "$($g.Title) (recomp).cmd"
    "@echo off`r`ncd /d `"%~dp0`"`r`nstart `"`" `"build\$($g.Id)\Release\$($g.Exe)`" %*`r`n" | Out-File $launcher -Encoding ascii
    Write-Host "  $($g.Title) (recomp).cmd"
}
Write-Host ""
Write-Host "Done. Double-click a launcher above to play."
if ($others) {
    Write-Host ""
    & (Join-Path $PSScriptRoot "setup-builds.ps1") -Yes:$Yes -Game $Game -Targets ($others -join ',')
    exit $LASTEXITCODE
}
