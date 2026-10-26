#!/bin/bash
# Rampage Recompiled setup for Linux and macOS: from a plain download to a launcher for each game you
# own, using your own ROMs. The same steps as tools/setup.ps1 (Windows).
#
#   ./setup.sh                                        asks before installing anything
#   ./setup.sh --yes --game DIR                       no questions (recomp-launcher uses this)
#   ./setup.sh --targets pc,android,linux-arm64       also build for other machines, in Docker
#
# Targets: pc (this computer, the default) and the builds for other machines in scripts/targets.tsv,
# which setup-builds.sh makes after this computer's (docs/other-builds.md).
#
# It skips the steps already done (so a rerun after a failure resumes) and logs everything to
# logs/setup.log. The ROMs stay on this machine: they're copied into this folder (gitignored) and
# recompiled here. Nothing from the games is downloaded.
set -e
cd "$(dirname "$0")"
ROOT=$PWD
YES=0; GAME=""; TARGETS=pc
while [ $# -gt 0 ]; do
  case "$1" in
    --yes|-y) YES=1 ;;
    --game|--game-dir) GAME=$2; shift ;;
    --targets) TARGETS=$2; shift ;;
    *) echo "usage: ./setup.sh [--yes] [--game DIR] [--targets pc,android,linux-arm64]" >&2; exit 2 ;;
  esac
  shift
done
OTHERS=$(echo ",$TARGETS," | sed 's/,pc,/,/g; s/^,*//; s/,*$//')
builds() {
  args=(--targets "$OTHERS"); [ $YES = 1 ] && args+=(--yes); [ -n "$GAME" ] && args+=(--game "$GAME")
  exec bash "$ROOT/setup-builds.sh" "${args[@]}"
}
# Only other machines: that's setup-builds.sh's job alone.
case ",$TARGETS," in *,pc,*) ;; *) builds ;; esac

mkdir -p logs deps
LOG=$ROOT/logs/setup.log
echo "Rampage Recompiled setup, $(date)" > "$LOG"
STEPS=7
STEP=0

# "[n/7] what": recomp-launcher's progress bar reads these.
step() { STEP=$((STEP + 1)); echo "[$STEP/$STEPS] $*"; echo "[$STEP/$STEPS] $*" >> "$LOG"; }
fail() {
  echo ""; echo "Setup stopped: $*" >&2; echo "Details are in $LOG" >&2
  echo "Setup stopped: $*" >> "$LOG"; exit 1
}
# Runs a command with its output in the log; stops with $1 if it fails.
run() { why=$1; shift; echo "> $*" >> "$LOG"; "$@" >> "$LOG" 2>&1 || fail "$why"; }
ask() { [ "$YES" = 1 ] && return 0; read -r -p "$1 [Y/n] " r; case "$r" in [nN]*) return 1 ;; esac; return 0; }
have() { command -v "$1" >/dev/null 2>&1; }

# ---------------------------------------------------------------------------------------------
step "Checking the tools it needs"
MAC=0; [ "$(uname)" = Darwin ] && MAC=1
if [ $MAC = 1 ]; then
  # RT64 compiles its Metal shaders with Xcode's metal compiler (the Command Line Tools lack it).
  xcrun -sdk macosx metal --version >/dev/null 2>&1 ||
    fail "Xcode is needed (for its Metal shader compiler). Install Xcode from the App Store, open it once, run 'xcodebuild -downloadComponent MetalToolchain' if it asks for the Metal toolchain, then run Setup again."
  missing=""
  for t in cmake ninja python3; do have $t || missing="$missing $t"; done
  [ -e "$(brew --prefix 2>/dev/null)/lib/cmake/SDL2/SDL2Config.cmake" ] || missing="$missing sdl2"
  if [ -n "$missing" ]; then
    have brew || fail "these are missing:$missing. Install Homebrew (https://brew.sh), then run Setup again."
    ask "These are needed to build the games and aren't installed:$missing. Install them with Homebrew?" || fail "install$missing, then run Setup again."
    run "installing$missing with Homebrew failed" brew install $missing
  fi
else
  missing_cmd=""
  for t in git cmake ninja clang++ python3 pkg-config; do have $t || missing_cmd="$missing_cmd $t"; done
  missing_lib=""
  for p in sdl2 gtk+-3.0 x11 xrandr; do have pkg-config && pkg-config --exists $p || missing_lib="$missing_lib $p"; done
  if [ -n "$missing_cmd$missing_lib" ]; then
    if have apt-get; then pm="apt-get install -y"; pkgs="git cmake ninja-build clang python3 pkg-config libsdl2-dev libgtk-3-dev libx11-dev libxrandr-dev"
    elif have dnf; then pm="dnf install -y"; pkgs="git cmake ninja-build clang python3 pkgconf-pkg-config SDL2-devel gtk3-devel libX11-devel libXrandr-devel"
    elif have pacman; then pm="pacman -S --needed --noconfirm"; pkgs="git cmake ninja clang python pkgconf sdl2 gtk3 libx11 libxrandr"
    else fail "missing:$missing_cmd$missing_lib. Install them (the SDL2, GTK 3, X11 and Xrandr development packages, clang, cmake, ninja), then run Setup again."
    fi
    ask "Some build tools and libraries are missing:$missing_cmd$missing_lib. Install them with 'sudo $pm' (asks for your password)?" ||
      fail "install them with: sudo $pm $pkgs"
    [ "$pm" = "apt-get install -y" ] && run "updating the package list failed" sudo apt-get update
    run "installing the build tools failed" sudo $pm $pkgs
  fi
fi

# ---------------------------------------------------------------------------------------------
step "Finding your ROMs"
found=$(python3 tools/find_rom.py "$ROOT" ${GAME:+"$GAME"})
[ -n "$found" ] || fail "No Rampage ROM found. Put your USA .z64 of Rampage World Tour or Rampage 2 in this folder (or pass --game <folder>), then run Setup again. Byte-swapped .v64/.n64 dumps need converting to .z64 first."
echo "$found" | sed 's/^wt /  Rampage World Tour: /; s/^r2 /  Rampage 2 Universal Tour: /'
GAMES=$(echo "$found" | cut -d' ' -f1)

# ---------------------------------------------------------------------------------------------
step "Getting the recompiler, runtime and renderer"
# sp00nznet's forks, on the branches carrying the fixes Rampage needs (docs/building.md).
for t in N64Recomp:fix/fallthrough-tail-call N64ModernRuntime:rampage rt64:rampage; do
  dir=deps/${t%%:*} ref=${t#*:}
  if [ -d "$dir/.git" ]; then
    # From an earlier setup: bring it up to the pinned branch (an update may need newer fixes).
    run "updating ${t%%:*} failed (no internet, or see the log)" git -C "$dir" fetch -q origin "$ref"
    run "updating ${t%%:*} failed" git -C "$dir" checkout -q FETCH_HEAD
    run "updating ${t%%:*} failed" git -C "$dir" submodule update -q --init --recursive
  else
    run "downloading ${t%%:*} failed (no internet, or see the log)" git clone --recurse-submodules --branch "$ref" "https://github.com/sp00nznet/${t%%:*}" "$dir"
  fi
done

# ---------------------------------------------------------------------------------------------
step "Building the recompiler"
export N64RECOMP=$ROOT/deps/N64Recomp/build/N64Recomp RSPRECOMP=$ROOT/deps/N64Recomp/build/RSPRecomp
if [ ! -x "$N64RECOMP" ] || [ ! -x "$RSPRECOMP" ]; then
  run "configuring N64Recomp failed" cmake -S deps/N64Recomp -B deps/N64Recomp/build -G Ninja -DCMAKE_BUILD_TYPE=Release
  run "building N64Recomp failed" cmake --build deps/N64Recomp/build --target N64RecompCLI RSPRecomp
fi

# ---------------------------------------------------------------------------------------------
step "Recompiling your games (a minute each)"
# regen.py skips a game whose inputs haven't changed since its last run.
for g in $GAMES; do run "recompiling $g failed" python3 tools/regen.py $g; done

# ---------------------------------------------------------------------------------------------
step "Building (the first build takes 20 to 40 minutes)"
compilers=""; [ $MAC = 0 ] && compilers="-DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++"
exe_of() { [ $1 = r2 ] && echo Rampage2 || echo RampageWorldTour; }
for g in $GAMES; do
  run "configuring $g failed" cmake -S . -B build/$g -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo -DRAMPAGE_GAME=$g $compilers
  run "building $g failed" cmake --build build/$g --target $(exe_of $g)
done

# ---------------------------------------------------------------------------------------------
step "Making launchers"
# A .command opens from Finder; recomp-launcher runs either with /bin/sh.
ext=sh; [ $MAC = 1 ] && ext=command
for g in $GAMES; do
  case $g in wt) title="Rampage World Tour" exe=RampageWorldTour ;; r2) title="Rampage 2 Universal Tour" exe=Rampage2 ;; esac
  launcher="$title (recomp).$ext"
  # Run from here, like the Windows launchers: settings, saves and texture-packs/ live beside it.
  printf '#!/bin/sh\ncd "$(dirname "$0")"\nexec build/%s/%s "$@" 2> logs/%s.log\n' "$g" "$exe" "$exe" > "$launcher"
  chmod +x "$launcher"
  echo "  $launcher"
done
echo ""
echo "Done. Run a launcher above to play."
[ -z "$OTHERS" ] || { echo ""; builds; }
