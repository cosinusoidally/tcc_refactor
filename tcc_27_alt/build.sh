#!/bin/sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
cd "$ROOT"

CC=${CC:-cc}
CFLAGS=${CFLAGS:-"-m32 -Wall -g -O2 -fno-strict-aliasing -Wno-pointer-sign -Wno-sign-compare -Wno-unused-result"}
LDFLAGS=${LDFLAGS:-}
LDLIBS=${LDLIBS:-"-lm -ldl"}
RUN_I386=${RUN_I386:-./scripts/run-i386.sh}

DEFINES='
-DONE_SOURCE=1
-DTCC_TARGET_I386
-DCONFIG_TCCBOOT
-DCONFIG_TCC_NO_RUN
-DCONFIG_TRIPLET="i386-linux-gnu"
-DCONFIG_TCC_CRTPREFIX="/usr/lib/i386-linux-gnu:/lib/i386-linux-gnu:/usr/lib32:/lib32"
-DCONFIG_TCC_LIBPATHS="/usr/lib/i386-linux-gnu:/lib/i386-linux-gnu:/usr/lib32:/lib32"
-DTCC_LIBTCC1="libtcc1.a"
'

mkdir -p build
ROOTDIR=build/root
mkdir -p "$ROOTDIR"

echo "building $ROOTDIR/tcc with ${CC}"
# shellcheck disable=SC2086
$CC $CFLAGS $DEFINES -I. -o "$ROOTDIR/tcc" tcc.c $LDFLAGS $LDLIBS
chmod +x "$ROOTDIR/tcc"

echo "building $ROOTDIR/libtcc1.a with $ROOTDIR/tcc"
"$RUN_I386" "$ROOTDIR/tcc" -B"$ROOTDIR" -Iinclude -I. -c lib/libtcc1.c -o "$ROOTDIR/libtcc1.o"
"$RUN_I386" "$ROOTDIR/tcc" -B"$ROOTDIR" -Iinclude -I. -c lib/alloca86.S -o "$ROOTDIR/alloca86.o"
"$RUN_I386" "$ROOTDIR/tcc" -ar rcs "$ROOTDIR/libtcc1.a" "$ROOTDIR/libtcc1.o" "$ROOTDIR/alloca86.o"

echo "build complete"
