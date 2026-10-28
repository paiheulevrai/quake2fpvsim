#!/bin/sh
# SPDX-License-Identifier: GPL-2.0-or-later
set -eu
export PATH="$HOME/.local/bin:$PATH"

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
BUILD="$ROOT/build/portmaster"
PACKAGE="$BUILD/package"

meson setup --wipe --cross-file "$ROOT/packaging/portmaster/aarch64-linux-gnu.ini" "$BUILD" "$ROOT" \
    -Dsystem-wide=false -Dlibcurl=disabled -Dx11=disabled -Dwayland=disabled \
    -Dsdl2=enabled -Dopenal=disabled -Davcodec=disabled
meson compile -C "$BUILD"

rm -rf "$PACKAGE"
mkdir -p "$PACKAGE/q2pro/baseq2"
cp "$BUILD/q2pro" "$PACKAGE/q2pro/q2pro_glsl"
cp "$BUILD/gamearm64.so" "$PACKAGE/q2pro/baseq2/"
cp "$ROOT/src/client/ui/q2pro.menu" "$PACKAGE/q2pro/baseq2/"
cp "$ROOT/packaging/portmaster/q2pro.gptk" "$ROOT/packaging/portmaster/README.md" \
    "$ROOT/packaging/portmaster/port.json" "$PACKAGE/q2pro/"
cp "$ROOT/packaging/portmaster/Q2PRO.sh" "$PACKAGE/"
cp "$ROOT/LICENSE" "$PACKAGE/q2pro/LICENSE"
chmod +x "$PACKAGE/Q2PRO.sh" "$PACKAGE/q2pro/q2pro_glsl"
(cd "$PACKAGE" && zip -qr "$BUILD/q2pro-portmaster-arm64.zip" .)
