"""Finds the USA Rampage ROMs (big-endian .z64) in the given folders or their direct subfolders and
copies each into the first folder (the repo) under the name its .toml expects. Prints one line per
game found: "<id> <where it was>". Used by setup.sh and the Docker builds (tools/setup.ps1 does the
same in PowerShell).

    python3 tools/find_rom.py <repo> [<folder with your ROMs>]
"""
import os
import shutil
import sys

# id: (ROM header name at 0x20, CRC1 at 0x10, file name in the repo)
GAMES = {
    "wt": (b"RAMPAGE ", "C29FF9E4", "Rampage - World Tour (U) [!].z64"),
    "r2": (b"RAMPAGE2", "673D099B", "Rampage 2 - Universal Tour (U) [!].z64"),
}


def candidates(top):
    if os.path.isfile(top):
        top = os.path.dirname(top) or "."
    if not os.path.isdir(top):
        return
    for d in [top] + sorted(os.path.join(top, d) for d in os.listdir(top) if os.path.isdir(os.path.join(top, d))):
        for name in sorted(os.listdir(d)):
            p = os.path.join(d, name)
            if os.path.isfile(p) and name.lower().endswith(".z64"):
                yield p


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    repo = sys.argv[1]
    for gid, (header, crc, rom) in GAMES.items():
        for p in (c for top in sys.argv[1:] for c in candidates(top)):
            with open(p, "rb") as f:
                h = f.read(0x40)
            if len(h) == 0x40 and h[0x20:0x28] == header and h[0x10:0x14].hex().upper() == crc:
                dest = os.path.join(repo, rom)
                if os.path.abspath(p) != os.path.abspath(dest):
                    shutil.copyfile(p, dest)
                print(gid, p)
                break


if __name__ == "__main__":
    main()
