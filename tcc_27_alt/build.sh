#!/bin/sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
cd "$ROOT"

CC=${CC:-cc}
CFLAGS=${CFLAGS:-"-m32 -std=gnu99 -Wall -g -O2 -fno-strict-aliasing -Wno-pointer-sign -Wno-sign-compare -Wno-unused-result"}
LDFLAGS=${LDFLAGS:-}
LDLIBS=${LDLIBS:-"-lm -ldl"}
RUN_I386=${RUN_I386:-./scripts/run-i386.sh}

if [ "${1:-}" = coverage ]; then
    CFLAGS="-m32 -std=gnu99 -Wall -g -O0 --coverage -fno-strict-aliasing -Wno-pointer-sign -Wno-sign-compare -Wno-unused-result"
    LDFLAGS="--coverage"
fi

mkdir -p build
ROOTDIR=build/root
mkdir -p "$ROOTDIR"

echo "building $ROOTDIR/tcc with ${CC}"
# shellcheck disable=SC2086
$CC $CFLAGS -nostdinc -o "$ROOTDIR/tcc" tcc_nopp.c $LDFLAGS $LDLIBS
chmod +x "$ROOTDIR/tcc"

echo "build complete"
