param(
    [string]$OutputPath = "D:\rampage\screenshots",
    [string]$Filename = "screenshot.png",
    [int]$DelaySeconds = 8
)

Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing

# Create output directory if needed
if (-not (Test-Path $OutputPath)) {
    New-Item -ItemType Directory -Path $OutputPath | Out-Null
}

# Wait for the game window to appear and render
Write-Host "Waiting $DelaySeconds seconds for game to render..."
Start-Sleep -Seconds $DelaySeconds

# Find the game window
$proc = Get-Process -Name "RampageRecompiled" -ErrorAction SilentlyContinue
if (-not $proc) {
    Write-Host "Game process not found!"
    exit 1
}

# Use user32.dll for window operations
Add-Type @"
using System;
using System.Runtime.InteropServices;

public class Win32 {
    [DllImport("user32.dll")]
    public static extern bool GetClientRect(IntPtr hWnd, out RECT lpRect);

    [DllImport("user32.dll")]
    public static extern bool GetWindowRect(IntPtr hWnd, out RECT lpRect);

    [DllImport("user32.dll")]
    public static extern bool SetForegroundWindow(IntPtr hWnd);

    [DllImport("user32.dll")]
    public static extern bool PrintWindow(IntPtr hWnd, IntPtr hdcBlt, uint nFlags);

    [DllImport("user32.dll")]
    public static extern bool MoveWindow(IntPtr hWnd, int X, int Y, int nWidth, int nHeight, bool bRepaint);

    [StructLayout(LayoutKind.Sequential)]
    public struct RECT {
        public int Left, Top, Right, Bottom;
    }
}
"@

$hwnd = $proc.MainWindowHandle
if ($hwnd -eq [IntPtr]::Zero) {
    Write-Host "No main window handle found!"
    exit 1
}

# Move window to top-left so it's fully visible
$winRect = New-Object Win32+RECT
[Win32]::GetWindowRect($hwnd, [ref]$winRect) | Out-Null
$winWidth = $winRect.Right - $winRect.Left
$winHeight = $winRect.Bottom - $winRect.Top
Write-Host "Window size: ${winWidth}x${winHeight}"

# Move to (50, 50) to ensure it's on screen
[Win32]::MoveWindow($hwnd, 50, 50, $winWidth, $winHeight, $true) | Out-Null
Start-Sleep -Milliseconds 500

# Bring window to front
[Win32]::SetForegroundWindow($hwnd) | Out-Null
Start-Sleep -Milliseconds 500

# Use PrintWindow to capture the window content (flag 2 = PW_RENDERFULLCONTENT)
$bitmap = New-Object System.Drawing.Bitmap($winWidth, $winHeight)
$graphics = [System.Drawing.Graphics]::FromImage($bitmap)
$hdc = $graphics.GetHdc()

# Try PW_RENDERFULLCONTENT (2) first, fallback to PW_CLIENTONLY (1), then default (0)
$result = [Win32]::PrintWindow($hwnd, $hdc, 2)
if (-not $result) {
    Write-Host "PrintWindow with PW_RENDERFULLCONTENT failed, trying default..."
    $result = [Win32]::PrintWindow($hwnd, $hdc, 0)
}

$graphics.ReleaseHdc($hdc)
$graphics.Dispose()

if ($result) {
    $fullPath = Join-Path $OutputPath $Filename
    $bitmap.Save($fullPath, [System.Drawing.Imaging.ImageFormat]::Png)
    Write-Host "Screenshot saved to: $fullPath"
} else {
    Write-Host "PrintWindow failed, falling back to screen capture..."
    # Fallback: capture the screen region where window is now
    [Win32]::GetWindowRect($hwnd, [ref]$winRect) | Out-Null
    $bitmap2 = New-Object System.Drawing.Bitmap($winWidth, $winHeight)
    $g2 = [System.Drawing.Graphics]::FromImage($bitmap2)
    $g2.CopyFromScreen($winRect.Left, $winRect.Top, 0, 0, [System.Drawing.Size]::new($winWidth, $winHeight))
    $g2.Dispose()
    $fullPath = Join-Path $OutputPath $Filename
    $bitmap2.Save($fullPath, [System.Drawing.Imaging.ImageFormat]::Png)
    $bitmap2.Dispose()
    Write-Host "Screenshot (fallback) saved to: $fullPath"
}
$bitmap.Dispose()
