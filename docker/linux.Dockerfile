# The Linux toolchain for setup-builds: the recompiler step (host CPU) and the Linux arm64
# build (--platform linux/arm64). Debian 12, so the arm64 build runs on Raspberry Pi OS 12 and
# anything newer (an older glibc than Ubuntu 24.04's).
FROM debian:bookworm
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
      ca-certificates git cmake ninja-build clang-16 lld-16 python3 pkg-config file \
      libsdl2-dev libgtk-3-dev libx11-dev libxrandr-dev && \
    rm -rf /var/lib/apt/lists/*
ENV CC=clang-16 CXX=clang++-16
