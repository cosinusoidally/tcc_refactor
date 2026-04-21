#!/bin/sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
cd "$ROOT"

BOOTROOT=build/root
OUT=build/nopp
NOPP="$OUT/tcc_nopp.c"

if [ ! -x "$BOOTROOT/tcc" ] || [ ! -f "$BOOTROOT/libtcc1.a" ]; then
    ./build.sh
fi

mkdir -p "$OUT"

"$BOOTROOT/tcc" -B"$BOOTROOT" -Iinclude -I. \
    -DONE_SOURCE=1 \
    -DTCC_TARGET_I386 \
    '-DCONFIG_TRIPLET="i386-linux-gnu"' \
    '-DCONFIG_TCC_CRTPREFIX="/usr/lib/i386-linux-gnu:/lib/i386-linux-gnu:/usr/lib32:/lib32"' \
    '-DCONFIG_TCC_LIBPATHS="/usr/lib/i386-linux-gnu:/lib/i386-linux-gnu:/usr/lib32:/lib32"' \
    '-DTCC_LIBTCC1="libtcc1.a"' \
    -E -P tcc.c > "$NOPP"

if grep '^#' "$NOPP" >/dev/null; then
    echo "generated source still contains preprocessor directives" >&2
    exit 1
fi

echo "generated $NOPP"
