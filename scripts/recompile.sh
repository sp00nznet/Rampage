#!/bin/bash
# Turns the ROMs in the repo folder into C (gen/<game>/, rsp/aspMain_<game>.cpp) for setup-builds:
# the same as setup.sh's steps 3 to 5, in the docker/linux.Dockerfile image. Its recompiler goes in
# build-tools/, apart from the one a native setup builds in deps/N64Recomp/build. regen.py keeps a
# stamp of its inputs, so a game a native setup already recompiled is skipped here.
set -e
cd "$(dirname "$0")/.."
for t in N64Recomp:fix/fallthrough-tail-call N64ModernRuntime:rampage rt64:rampage; do
  dir=deps/${t%%:*}
  [ -d "$dir/.git" ] || git clone -q --recurse-submodules --branch "${t#*:}" "https://github.com/sp00nznet/${t%%:*}" "$dir"
done
T=build-tools/N64Recomp
if [ ! -x $T/N64Recomp ] || [ ! -x $T/RSPRecomp ]; then
  cmake -S deps/N64Recomp -B $T -G Ninja -DCMAKE_BUILD_TYPE=Release
  cmake --build $T --target N64RecompCLI RSPRecomp
fi
export N64RECOMP=$PWD/$T/N64Recomp RSPRECOMP=$PWD/$T/RSPRecomp
for g in $(python3 tools/find_rom.py . | cut -d' ' -f1); do python3 tools/regen.py $g; done
