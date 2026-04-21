#!/bin/sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
cd "$ROOT"

CC=${CC:-cc}
CFLAGS=${CFLAGS:-"-m32 -std=gnu99 -Wall -g -O2 -fno-strict-aliasing -Wno-pointer-sign -Wno-sign-compare -Wno-unused-result"}
LDFLAGS=${LDFLAGS:-}
LDLIBS=${LDLIBS:-"-lm -ldl"}
RUN_I386=${RUN_I386:-./scripts/run-i386.sh}

mkdir -p build
ROOTDIR=build/root
mkdir -p "$ROOTDIR"

echo "building $ROOTDIR/tcc with ${CC}"
# shellcheck disable=SC2086
$CC $CFLAGS -nostdinc -o "$ROOTDIR/tcc" tcc_nopp.c $LDFLAGS $LDLIBS
chmod +x "$ROOTDIR/tcc"

echo "building $ROOTDIR/libtcc1.a with $ROOTDIR/tcc"
"$RUN_I386" "$ROOTDIR/tcc" -B"$ROOTDIR" -nostdinc -c lib/libtcc1_nopp.c -o "$ROOTDIR/libtcc1.o"
"$RUN_I386" "$ROOTDIR/tcc" -B"$ROOTDIR" -Iinclude -I. -c lib/alloca86.S -o "$ROOTDIR/alloca86.o"
"$RUN_I386" "$ROOTDIR/tcc" -ar rcs "$ROOTDIR/libtcc1.a" "$ROOTDIR/libtcc1.o" "$ROOTDIR/alloca86.o"

echo "build complete"
