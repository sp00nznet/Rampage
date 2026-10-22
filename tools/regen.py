#!/usr/bin/env python3
"""Recompile a Rampage ROM into gen/<game>/ (gitignored) with N64Recomp.

    py tools/regen.py wt     # Rampage: World Tour           (rampage_wt.toml)
    py tools/regen.py r2     # Rampage 2: Universal Tour     (rampage2_ut.toml)

The ROM must sit in the repo root under the name the .toml gives (the No-Intro name). The
generated C is derived from the ROM, so it stays local and is never committed.

N64Recomp is taken from $N64RECOMP, else ../N64Recomp/build/Release/N64Recomp.exe. It needs
sp00nznet/N64Recomp's fallthrough fix (docs/building.md); without it, functions that run into
the next one end early and the game breaks in odd places.
"""
import os
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GAMES = {"wt": "rampage_wt.toml", "r2": "rampage2_ut.toml"}


def main():
    if len(sys.argv) != 2 or sys.argv[1] not in GAMES:
        sys.exit(__doc__)
    game = sys.argv[1]
    exe = os.environ.get("N64RECOMP") or os.path.join(ROOT, "..", "N64Recomp", "build", "Release", "N64Recomp.exe")
    if not os.path.isfile(exe):
        sys.exit(f"N64Recomp not found at {exe}. Build it or set N64RECOMP.")

    out = os.path.join(ROOT, "gen", game)
    shutil.rmtree(out, ignore_errors=True)  # stale funcs_N.c files would be globbed into the build
    os.makedirs(out)

    log = os.path.join(ROOT, "gen", f"{game}.log")
    with open(log, "w") as f:
        rc = subprocess.call([exe, GAMES[game]], cwd=ROOT, stdout=f, stderr=subprocess.STDOUT)
    text = open(log).read()
    if rc != 0:
        sys.exit(f"N64Recomp failed (exit {rc}); see {log}")
    files = len([n for n in os.listdir(out) if n.endswith(".c")])
    print(f"{game}: {files} files in gen/{game}, {text.count('Fallthrough in')} fallthroughs, "
          f"{text.count('[Warn]')} warnings (full log: gen/{game}.log)")


if __name__ == "__main__":
    main()
