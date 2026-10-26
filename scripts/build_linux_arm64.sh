#!/bin/bash
# The Linux arm64 build (Raspberry Pi 5, ARM handhelds and laptops with a Vulkan driver), in the
# docker/linux.Dockerfile image run as linux/arm64. Builds every game scripts/recompile.sh turned
# into C and leaves builds/linux-arm64/rampage-linux-arm64.tar.gz.
set -e
cd "$(dirname "$0")/.."
P=build-linux-arm64/rampage
rm -rf $P && mkdir -p $P
for g in $(python3 tools/find_rom.py . | cut -d' ' -f1); do
  case $g in wt) title="Rampage World Tour" exe=RampageWorldTour rom="Rampage - World Tour (U) [!].z64" ;;
             r2) title="Rampage 2 Universal Tour" exe=Rampage2 rom="Rampage 2 - Universal Tour (U) [!].z64" ;; esac
  B=build-linux-arm64/$g
  cmake -S . -B $B -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo -DRAMPAGE_GAME=$g \
    -DN64_MODERN_RUNTIME_DIR="$PWD/deps/N64ModernRuntime" -DRT64_DIR="$PWD/deps/rt64"
  cmake --build $B --target $exe
  # The game, your ROM (it looks next to itself) and a launcher, in one folder.
  cp $B/$exe $P/ && strip $P/$exe
  cp "$rom" $P/
  printf '#!/bin/sh\n# Needs SDL2, GTK 3 and a Vulkan driver: sudo apt install libsdl2-2.0-0 libgtk-3-0 mesa-vulkan-drivers\ncd "$(dirname "$0")"\nexec ./%s "$@" 2> %s.log\n' $exe $exe > "$P/$title.sh"
  chmod +x "$P/$title.sh"
  file $P/$exe
done
mkdir -p builds/linux-arm64
tar -C build-linux-arm64 -czf builds/linux-arm64/rampage-linux-arm64.tar.gz rampage
