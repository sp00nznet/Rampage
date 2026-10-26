<#
Builds Rampage World Tour and Rampage 2 from your ROMs for the other machines in scripts\targets.tsv
(Linux arm64, Android), in Docker Desktop (Windows; Linux and macOS run setup-builds.sh, which
does the same). Every toolchain runs in a container.

    -Game <folder or file>   where your USA .z64s are
    -Yes                     install Docker Desktop if it's missing, no questions
    -Targets linux-arm64     build only these (comma-separated)

tools\setup.ps1 runs this for the targets besides "pc" (recomp-launcher's boxes besides "This
computer", launcher\launcher.json). Each step prints "[n/N] ...", and a failure ends with "Setup
stopped: ...". A build that fails doesn't stop the others; its log is in build-logs\. The results
land in builds\.
#>
param([switch]$Yes, [Alias('GameDir')][string]$Game = '', [string]$Targets = '')

# Continue: Windows PowerShell turns any docker stderr line into a terminating error under Stop,
# even redirected; every step checks docker's exit code instead.
$ErrorActionPreference = 'Continue'
$Root = Split-Path -Parent $PSScriptRoot
Set-Location $Root
New-Item -ItemType Directory -Force build-logs, builds | Out-Null

$only = @($Targets -split ',' | Where-Object { $_ })
$rows = @(Get-Content scripts\targets.tsv | Where-Object { $_ -and $_ -notmatch '^#' } | ForEach-Object {
    $c = $_ -split "`t"
    [pscustomobject]@{ T = $c[0]; Platform = $c[1]; Tag = $c[2]; Dockerfile = $c[3]; Script = $c[4]; Out = $c[5]; State = $c[6] }
} | Where-Object { $only.Count -eq 0 -or $only -contains $_.T })
# $Total, not $N: PowerShell names ignore case, and Step's $n would shadow it.
$Total = 3 + $rows.Count

function Step($n, $t) { Write-Host ''; Write-Host "[$n/$Total] $t" }
function Fail($t) {
    Write-Host ''; Write-Host "Setup stopped: $t" -ForegroundColor Red
    Write-Host "Details are in $Root\build-logs"
    exit 1
}
function Ask($q) { if ($Yes) { return $true }; (Read-Host "$q [Y/n]") -notmatch '^[nN]' }
# Runs a native command with its output in $log (appended), and returns its exit code.
function Exec($log, [string[]]$a) {
    & $a[0] $a[1..($a.Count - 1)] 2>&1 | ForEach-Object { "$_" } | Out-File $log -Append -Encoding utf8
    return $LASTEXITCODE
}
# Builds a toolchain image on first use (Docker caches it after that).
function Image($tag, $platform, $dockerfile, $log) {
    docker image inspect $tag *> $null
    if ($LASTEXITCODE -eq 0) { return 0 }
    $a = @('docker', 'build', '-t', $tag)
    if ($platform) { $a += @('--platform', $platform) }
    return Exec $log ($a + @('-f', "docker\$dockerfile.Dockerfile", 'docker'))
}

Step 1 'Checking Docker'
if (-not (Get-Command docker -ErrorAction SilentlyContinue)) {
    if (-not (Get-Command winget -ErrorAction SilentlyContinue)) { Fail 'Docker Desktop is needed: https://www.docker.com/products/docker-desktop/' }
    if (-not (Ask '  Docker Desktop runs the build toolchains in containers and is not installed. Install it with winget (about 600 MB, plus WSL 2)?')) {
        Fail 'Docker Desktop is needed: https://www.docker.com/products/docker-desktop/'
    }
    Exec "$Root\build-logs\docker-install.log" @('winget', 'install', '-e', '--id', 'Docker.DockerDesktop', '--accept-package-agreements', '--accept-source-agreements') | Out-Null
    Fail 'Docker Desktop was installed. Start it once (it finishes setting up and may ask to restart), then run this again.'
}
if ((Exec "$env:TEMP\rampage-docker-info.txt" @('docker', 'info')) -ne 0) { Fail 'Docker Desktop is not running. Start it, wait until it says it is running, then run this again.' }
if ($rows.Count -eq 0) { Fail "none of '$Targets' is in scripts\targets.tsv." }
Write-Host "  Docker $(docker version --format '{{.Server.Version}}')"

Step 2 'Finding your ROMs'
if ((Image 'rampage-linux' '' 'linux' "$Root\build-logs\image-linux.log") -ne 0) { Fail 'building the Linux toolchain image failed (build-logs\image-linux.log).' }
$mount = @()
$g = $Game.Trim('"', ' ')
if ($g) {
    if (-not (Test-Path -LiteralPath $g)) { Fail "there's nothing at '$g'." }
    if (Test-Path -LiteralPath $g -PathType Leaf) { $g = Split-Path -Parent $g }
    $mount = @('-v', "$((Resolve-Path -LiteralPath $g).Path):/game:ro")
}
$found = @(& docker run --rm -v "${Root}:/src" @mount -w /src rampage-linux python3 tools/find_rom.py /src /game)
if (-not $found) { Fail 'No Rampage ROM found. Choose the folder with your USA .z64 of Rampage World Tour or Rampage 2 (byte-swapped .v64/.n64 dumps need converting to .z64 first).' }
$found | ForEach-Object { Write-Host "  $($_ -replace '^wt ', 'Rampage World Tour: ' -replace '^r2 ', 'Rampage 2 Universal Tour: ' -replace '/(game|src)/', '')" }

Step 3 'Turning your ROMs into C (a few minutes; the first run also downloads the toolkits)'
if ((Exec "$Root\build-logs\recompile.log" @('docker', 'run', '--rm', '-v', "${Root}:/src", '-w', '/src', 'rampage-linux', 'bash', 'scripts/recompile.sh')) -ne 0) {
    Fail 'recompiling failed (build-logs\recompile.log).'
}

$n = 3; $ok = @(); $bad = @()
foreach ($r in $rows) {
    $n++
    Step $n "$($r.T): building (30 minutes to a few hours; the first run also downloads its toolchain)"
    $log = "$Root\build-logs\$($r.T).log"
    Remove-Item -LiteralPath $log -ErrorAction SilentlyContinue
    if ((Image $r.Tag $r.Platform $r.Dockerfile $log) -ne 0) { Write-Host "  Building the $($r.T) toolchain image failed."; $bad += $r.T; continue }
    $code = Exec $log @('docker', 'run', '--rm', '--platform', $r.Platform, '-v', "${Root}:/src", '-w', '/src', $r.Tag, 'bash', $r.Script)
    if ($code -eq 0 -and (Test-Path -LiteralPath $r.Out)) {
        $ok += $r.T; Write-Host "  Built: $($r.Out) ($($r.State))."
    } else {
        $bad += $r.T; Write-Host "  Failed. The last lines of build-logs\$($r.T).log:"
        Get-Content $log -Tail 5 | ForEach-Object { Write-Host "    $_" }
        if (Select-String -LiteralPath $log -Pattern 'exec format error' -Quiet) {
            Write-Host "  Docker can't run $($r.Platform) containers here. Turn on emulation once with:"
            Write-Host "    docker run --privileged --rm tonistiigi/binfmt --install all"
        }
    }
}

if ($ok.Count -eq 0) { Fail 'nothing built. The logs in build-logs\ say why.' }
"@echo off`r`nstart `"`" `"%~dp0builds`"`r`n" | Out-File (Join-Path $Root 'Other builds (recomp).cmd') -Encoding ascii
Write-Host ''
$failed = if ($bad.Count) { " (failed: $($bad -join ', '))" } else { '' }
Write-Host "Done: $($ok.Count) of $($rows.Count) built$failed. They're in builds\; docs\other-builds.md says how to install each."
