#!/usr/bin/env python3
"""Recompile a Rampage ROM into gen/<game>/ and its audio microcode into rsp/aspMain_<game>.cpp
(both gitignored) with N64Recomp and RSPRecomp.

    py tools/regen.py wt     # Rampage: World Tour           (rampage_wt.toml)
    py tools/regen.py r2     # Rampage 2: Universal Tour     (rampage2_ut.toml)

The ROM must sit in the repo root under the name the .toml gives (the No-Intro name). The
generated code is derived from the ROM, so it stays local and is never committed. Nothing is redone
while the inputs (the .toml, its symbol file, the microcode .toml) are unchanged since the last run;
--force redoes it anyway.

N64Recomp is taken from $N64RECOMP, else ../N64Recomp/build/Release/N64Recomp.exe; RSPRecomp from
$RSPRECOMP, else next to N64Recomp. N64Recomp needs sp00nznet/N64Recomp's fallthrough fix
(docs/building.md); without it, functions that run into the next one end early and the game
breaks in odd places.
"""
import hashlib
import os
import re
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GAMES = {"wt": "rampage_wt.toml", "r2": "rampage2_ut.toml"}


def main():
    args = [a for a in sys.argv[1:] if a != "--force"]
    if len(args) != 1 or args[0] not in GAMES:
        sys.exit(__doc__)
    game = args[0]
    exe = os.environ.get("N64RECOMP") or os.path.join(ROOT, "..", "N64Recomp", "build", "Release", "N64Recomp.exe")
    rsp_exe = os.environ.get("RSPRECOMP") or os.path.join(os.path.dirname(exe), "RSPRecomp" + os.path.splitext(exe)[1])
    for path, name in ((exe, "N64Recomp"), (rsp_exe, "RSPRecomp")):
        if not os.path.isfile(path):
            sys.exit(f"{name} not found at {path}. Build it or set {name.upper()}.")

    config = GAMES[game]
    symbols = re.search(r'symbols_file_path = "([^"]+)"', open(os.path.join(ROOT, config)).read()).group(1)
    rsp_toml = os.path.join("rsp", f"aspMain_{game}.toml")
    inputs = "".join(hashlib.sha256(open(os.path.join(ROOT, f), "rb").read()).hexdigest() for f in (config, symbols, rsp_toml))
    out = os.path.join(ROOT, "gen", game)
    stamp = os.path.join(out, "inputs.txt")
    rsp_out = os.path.join(ROOT, "rsp", f"aspMain_{game}.cpp")
    if "--force" not in sys.argv and os.path.isfile(stamp) and open(stamp).read() == inputs and os.path.isfile(rsp_out):
        print(f"{game}: up to date")
        return

    shutil.rmtree(out, ignore_errors=True)  # stale funcs_N.c files would be globbed into the build
    os.makedirs(out)
    log = os.path.join(ROOT, "gen", f"{game}.log")
    with open(log, "w") as f:
        rc = subprocess.call([exe, config], cwd=ROOT, stdout=f, stderr=subprocess.STDOUT)
        if rc == 0:
            rc = subprocess.call([rsp_exe, rsp_toml], cwd=ROOT, stdout=f, stderr=subprocess.STDOUT)
    text = open(log).read()
    if rc != 0:
        sys.exit(f"recompiling failed (exit {rc}); see {log}")
    open(stamp, "w").write(inputs)
    files = len([n for n in os.listdir(out) if n.endswith(".c")])
    print(f"{game}: {files} files in gen/{game}, {text.count('Fallthrough in')} fallthroughs, "
          f"{text.count('[Warn]')} warnings (full log: gen/{game}.log)")


if __name__ == "__main__":
    main()
