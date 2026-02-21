Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing

Add-Type @"
using System;
using System.Runtime.InteropServices;
public class Win32Cap {
    [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr hWnd, out RECT lpRect);
    [DllImport("user32.dll")] public static extern bool PrintWindow(IntPtr hWnd, IntPtr hdcBlt, uint nFlags);
    [StructLayout(LayoutKind.Sequential)] public struct RECT { public int Left, Top, Right, Bottom; }
}
"@

function Capture-GameWindow($hwnd, $path) {
    $r = New-Object Win32Cap+RECT
    [Win32Cap]::GetWindowRect($hwnd, [ref]$r) | Out-Null
    $w = $r.Right - $r.Left; $h = $r.Bottom - $r.Top
    if ($w -le 0 -or $h -le 0) { Write-Host "Invalid window size for $path"; return }
    $bmp = New-Object System.Drawing.Bitmap($w, $h)
    $g = [System.Drawing.Graphics]::FromImage($bmp)
    $hdc = $g.GetHdc()
    [Win32Cap]::PrintWindow($hwnd, $hdc, 2) | Out-Null
    $g.ReleaseHdc($hdc)
    $g.Dispose()
    $bmp.Save($path, [System.Drawing.Imaging.ImageFormat]::Png)
    $bmp.Dispose()
    Write-Host "Saved: $path"
}

$outDir = "D:\rampage\screenshots\reference"
if (-not (Test-Path $outDir)) { New-Item -ItemType Directory -Path $outDir | Out-Null }

$suffix = $args[0]
if (-not $suffix) { $suffix = "capture" }

# Capture simple64
$s64 = Get-Process -Name "simple64-gui" -ErrorAction SilentlyContinue
if ($s64) {
    Capture-GameWindow $s64.MainWindowHandle "$outDir\simple64_$suffix.png"
} else { Write-Host "simple64 not found" }

# Capture Rampage Recomp
$rc = Get-Process -Name "RampageRecompiled" -ErrorAction SilentlyContinue
if ($rc) {
    Capture-GameWindow $rc.MainWindowHandle "$outDir\recomp_$suffix.png"
} else { Write-Host "RampageRecompiled not found" }
