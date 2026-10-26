# Other builds: Android and Linux arm64

Besides the games for the computer it's set up on, Rampage can be built for two other kinds of
machine. Tick **Android** and/or **Linux arm64** in the Rampage installer (next to, or instead of,
**This computer**), or run `./setup.sh --targets android,linux-arm64` (Linux, macOS) or
`tools\setup.ps1 -Targets android,linux-arm64` (Windows); add `pc` to build for this computer as
well. Both are built in Docker from your own USA `.z64`s, so Docker (Docker Desktop on Windows and
macOS) must be installed and running; on Windows setup offers to install it. Only the toolchains
for what you pick are downloaded. The results land in `builds/`, the logs in `build-logs/`, and
`Other builds (recomp)` opens the folder.

Each build contains your ROM (the game reads it at start), so it's yours to play, not to share.
Every game whose ROM setup found is built: one app per game on Android, both in one folder on
Linux arm64.

The scripts: `setup-builds.sh` / `tools/setup-builds.ps1` drive the targets in
`scripts/targets.tsv`; `scripts/recompile.sh` turns the ROMs into C in a container (sharing
`tools/regen.py`'s stamp with a native setup, so nothing is recompiled twice); each target's script
builds in its own image (`docker/*.Dockerfile`, the same toolchains as sp00nznet's Racer port).

Why only these two: the renderer, RT64, needs Vulkan, DirectX 12 or Metal with compute shaders,
and macOS can't be built in Docker (Apple's SDK is licensed for Macs only); build it on a Mac with
`setup.sh`.

## Android: `builds/android/rampage-wt.apk`, `rampage-r2.apk`

For arm64 phones and handhelds with Vulkan (most from 2018 on). Each game is its own app
(`net.sp00nz.rampage.wt`, `net.sp00nz.rampage.r2`), so both can be installed. Install like any APK
from outside the store: copy it over and open it (allowing installs from that app when asked), or
`adb install rampage-wt.apk`. Rebuilding signs with the same key (kept in `build-android/`), so a
newer build installs over the old one and keeps your saves.

- **It needs a controller**: a handheld's own buttons, or a Bluetooth or USB pad. There are no
  touch controls; the launcher and menus work by touch.
- The log is `Android/data/net.sp00nz.rampage.wt/files/rampage.log` (`rampage2.log` for
  Rampage 2), readable with a file manager or `adb shell cat`.
- `RAMPAGE_ABI=x86_64` when running `scripts/build_android.sh` builds for the Android emulator
  instead.

## Linux arm64: `builds/linux-arm64/rampage-linux-arm64.tar.gz`

For a Raspberry Pi 5, ARM handhelds and ARM laptops, on Debian 12 / Raspberry Pi OS 12 or anything
newer, with a Vulkan driver. On an x86 computer it builds in an emulated container and takes a
few hours; on Apple silicon it's native and much quicker.

```
tar -xzf rampage-linux-arm64.tar.gz
sudo apt install libsdl2-2.0-0 libgtk-3-0 mesa-vulkan-drivers
./rampage/"Rampage World Tour.sh"
```

Logs (`RampageWorldTour.log`, `Rampage2.log`), settings and saves sit next to the games.

## What's been tested

The builds complete, but neither has been played on a device yet. Racer's builds of the same
frontend and toolchains boot to the game in the Android emulator; Linux arm64 needs a real Pi (an
emulated arm64 container is too slow to get past a title screen, and Debian 12's own software
Vulkan crashes compiling RT64's shaders).
