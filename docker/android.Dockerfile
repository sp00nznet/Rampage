# The Android toolchain for scripts/build_android.sh: SDK 34, NDK 27.2, CMake 3.22.1, a host C++
# compiler (for RT64's build-time file_to_c) and the SDL2 2.32.10 source. Built on first use by
# setup-builds; Docker caches it after that.
FROM ghcr.io/cirruslabs/android-sdk:34
RUN yes | sdkmanager --licenses >/dev/null && \
    sdkmanager "ndk;27.2.12479018" "cmake;3.22.1" "build-tools;34.0.0" "platforms;android-34" >/dev/null
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends g++ && \
    rm -rf /var/lib/apt/lists/*
RUN curl -fsSL https://github.com/libsdl-org/SDL/releases/download/release-2.32.10/SDL2-2.32.10.tar.gz \
      | tar -xz -C /opt
ENV SDL2_SRC=/opt/SDL2-2.32.10
