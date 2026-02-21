"""Visualize texrect layout from frame dump diagnostics."""
import re
import struct

def main():
    lines = open('D:/rampage/build/gpu_render_stderr.txt').readlines()

    # Extract first frame texrects
    rects = []
    fill_count = 0
    for l in lines:
        if '[FRAME-DUMP]' not in l:
            continue
        if 'fillRect' in l:
            fill_count += 1
            if fill_count > 1:
                break
        m = re.search(r'drawTexRect: \(([0-9.]+),([0-9.]+)\)-\(([0-9.]+),([0-9.]+)\).*texAddr=(0x[0-9A-Fa-f]+)', l)
        if m:
            x1, y1, x2, y2 = float(m.group(1)), float(m.group(2)), float(m.group(3)), float(m.group(4))
            addr = int(m.group(5), 16)
            rects.append((x1, y1, x2, y2, addr))

    print(f"Total texrects: {len(rects)}")

    # Create a 400x240 image as raw PPM
    W, H = 400, 240
    img = bytearray(W * H * 3)  # RGB

    # Color each texrect based on its texture address for visual identification
    def addr_to_color(addr):
        """Generate a deterministic color from address."""
        h = (addr * 2654435761) & 0xFFFFFFFF
        r = 50 + (h & 0xFF) % 200
        g = 50 + ((h >> 8) & 0xFF) % 200
        b = 50 + ((h >> 16) & 0xFF) % 200
        return (r, g, b)

    for i, (x1, y1, x2, y2, addr) in enumerate(rects):
        r, g, b = addr_to_color(addr)
        # Clip to framebuffer bounds
        cx1 = max(0, min(W-1, int(x1)))
        cy1 = max(0, min(H-1, int(y1)))
        cx2 = max(0, min(W-1, int(x2)))
        cy2 = max(0, min(H-1, int(y2)))

        for y in range(cy1, cy2 + 1):
            for x in range(cx1, cx2 + 1):
                idx = (y * W + x) * 3
                img[idx] = r
                img[idx+1] = g
                img[idx+2] = b

    # Write as PPM
    out_path = 'D:/rampage/screenshots/frame_layout.ppm'
    with open(out_path, 'wb') as f:
        f.write(f"P6\n{W} {H}\n255\n".encode())
        f.write(img)
    print(f"Saved to {out_path}")

    # Also print a summary of what covers what
    print("\nDraw order (last drawn = visible on top):")
    # Group by address ranges
    groups = {}
    for i, (x1, y1, x2, y2, addr) in enumerate(rects):
        if addr not in groups:
            groups[addr] = {'first': i+1, 'last': i+1, 'rects': []}
        groups[addr]['last'] = i+1
        groups[addr]['rects'].append((x1, y1, x2, y2))

    # Show groups by last draw (what's on top)
    for addr in sorted(groups.keys(), key=lambda a: groups[a]['last']):
        g = groups[addr]
        all_rects = g['rects']
        min_x = min(r[0] for r in all_rects)
        min_y = min(r[1] for r in all_rects)
        max_x = max(r[2] for r in all_rects)
        max_y = max(r[3] for r in all_rects)
        print(f"  Addr 0x{addr:08X}: draw#{g['first']:3d}-#{g['last']:3d} ({len(all_rects):3d} tiles) "
              f"coverage ({min_x:.0f},{min_y:.0f})-({max_x:.0f},{max_y:.0f})")

if __name__ == '__main__':
    main()
