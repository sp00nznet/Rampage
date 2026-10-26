#!/bin/bash
# The Android build (arm64 phones and handhelds with Vulkan), in the docker/android.Dockerfile image:
# one app per game scripts/recompile.sh turned into C. Puts SDL's Android project template together
# with android/ (our manifest and app module) and the ROM, and runs Gradle. Leaves
# builds/android/rampage-<game>.apk. RAMPAGE_ABI=x86_64 builds for the Android emulator instead.
set -e
cd "$(dirname "$0")/.."
export RAMPAGE_ROOT=$PWD
: "${ANDROID_HOME:?set ANDROID_HOME to the Android SDK}"
: "${SDL2_SRC:?set SDL2_SRC to an SDL2 2.32.x source tree}"
B=$RAMPAGE_ROOT/build-android
mkdir -p $B
rm -rf builds/android

# RT64 runs file_to_c while it builds, so it needs one for this machine, not the phone.
export HOST_FILE_TO_C=$B/file_to_c
[ -x $HOST_FILE_TO_C ] || c++ -O2 -std=c++17 -o $HOST_FILE_TO_C deps/rt64/src/tools/file_to_c/file_to_c.cpp

for g in $(python3 tools/find_rom.py . | cut -d' ' -f1); do
  case $g in wt) title="Rampage World Tour" rom="Rampage - World Tour (U) [!].z64" ;;
             r2) title="Rampage 2" rom="Rampage 2 - Universal Tour (U) [!].z64" ;; esac
  export RAMPAGE_GAME=$g
  P=$B/project-$g
  rm -rf $P && cp -r "$SDL2_SRC/android-project" $P
  rm -rf $P/app/jni
  cp -r android/app/. $P/app/
  printf '<?xml version="1.0" encoding="utf-8"?>\n<resources><string name="app_name">%s</string></resources>\n' "$title" \
    > $P/app/src/main/res/values/strings.xml
  # The game looks for baserom.z64 in its storage; on the first run it's taken out of the assets.
  mkdir -p $P/app/src/main/assets && cp "$rom" $P/app/src/main/assets/baserom.z64
  echo "sdk.dir=$ANDROID_HOME" > $P/local.properties
  # SDL's template pins Gradle 8.1.1, which can't run on the image's Java 21: Gradle 8.9 and AGP 8.7.
  sed -i 's|gradle-8.1.1-bin.zip|gradle-8.9-bin.zip|' $P/gradle/wrapper/gradle-wrapper.properties
  sed -i "s|com.android.tools.build:gradle:8.1.1|com.android.tools.build:gradle:8.7.3|" $P/build.gradle
  # The signing key lives here (ANDROID_USER_HOME), not in the container: the same key every build,
  # so a new APK installs over the last one and keeps your saves.
  GRADLE_USER_HOME=$B/.gradle ANDROID_USER_HOME=$B/android-home bash $P/gradlew -p $P assembleRelease --console=plain
  mkdir -p builds/android
  cp $P/app/build/outputs/apk/release/app-release.apk builds/android/rampage-$g.apk
done
ls -la builds/android
