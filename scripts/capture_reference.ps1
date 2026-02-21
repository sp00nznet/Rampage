# Launch simple64 with Rampage World Tour and capture screenshots at key moments
# Usage: powershell -ExecutionPolicy Bypass -File scripts/capture_reference.ps1

$rom = "D:\rampage\Rampage - World Tour (U) [!].z64"
$simple64 = "D:\rampage\tools\simple64\simple64\simple64-gui.exe"
$outDir = "D:\rampage\screenshots\reference"

if (-not (Test-Path $outDir)) { New-Item -ItemType Directory -Path $outDir | Out-Null }

Write-Host "Starting simple64 with Rampage World Tour..."
Write-Host "ROM: $rom"
Write-Host ""
Write-Host "Instructions:"
Write-Host "  1. The emulator will open with the game"
Write-Host "  2. Press F5 in simple64 to take a screenshot (saved to simple64's screenshot dir)"
Write-Host "  3. Or this script will use PrintWindow to capture at intervals"
Write-Host ""
Write-Host "Capturing screenshots at 5s intervals for 60s..."

# Start emulator
$proc = Start-Process -FilePath $simple64 -ArgumentList "`"$rom`"" -PassThru

Start-Sleep -Seconds 3

# Find the window
Add-Type @"
using System;
using System.Runtime.InteropServices;
using System.Drawing;
using System.Drawing.Imaging;

public class ScreenCapture {
    [DllImport("user32.dll")]
    public static extern bool PrintWindow(IntPtr hwnd, IntPtr hdc, uint nFlags);

    [DllImport("user32.dll")]
    public static extern bool GetWindowRect(IntPtr hwnd, out RECT rect);

    [DllImport("user32.dll")]
    public static extern bool SetWindowPos(IntPtr hWnd, IntPtr hWndInsertAfter, int X, int Y, int cx, int cy, uint uFlags);

    [StructLayout(LayoutKind.Sequential)]
    public struct RECT {
        public int Left, Top, Right, Bottom;
    }

    public static void CaptureWindow(IntPtr hwnd, string path) {
        RECT r;
        GetWindowRect(hwnd, out r);
        int w = r.Right - r.Left;
        int h = r.Bottom - r.Top;
        if (w <= 0 || h <= 0) return;

        using (Bitmap bmp = new Bitmap(w, h)) {
            using (Graphics g = Graphics.FromImage(bmp)) {
                IntPtr hdc = g.GetHdc();
                PrintWindow(hwnd, hdc, 2);
                g.ReleaseHdc(hdc);
            }
            bmp.Save(path, ImageFormat.Png);
        }
    }
}
"@ -ReferencedAssemblies System.Drawing, System.Drawing.Primitives, System.Runtime

$captures = @(
    @{delay=5;  name="ref_01_boot"},
    @{delay=10; name="ref_02_title"},
    @{delay=15; name="ref_03_title2"},
    @{delay=20; name="ref_04_after20s"},
    @{delay=30; name="ref_05_after30s"},
    @{delay=45; name="ref_06_after45s"},
    @{delay=60; name="ref_07_after60s"}
)

$elapsed = 3  # already waited 3s
foreach ($cap in $captures) {
    $wait = $cap.delay - $elapsed
    if ($wait -gt 0) { Start-Sleep -Seconds $wait }
    $elapsed = $cap.delay

    $hwnd = $proc.MainWindowHandle
    if ($hwnd -ne [IntPtr]::Zero) {
        $path = Join-Path $outDir "$($cap.name).png"
        try {
            [ScreenCapture]::CaptureWindow($hwnd, $path)
            Write-Host "Captured: $($cap.name).png at ${elapsed}s"
        } catch {
            Write-Host "Failed to capture at ${elapsed}s: $_"
        }
    } else {
        Write-Host "No window handle at ${elapsed}s"
    }
}

Write-Host ""
Write-Host "Done! Screenshots saved to $outDir"
Write-Host "Press any key to close the emulator..."
$null = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")

if (-not $proc.HasExited) {
    $proc.Kill()
}
