#!/bin/sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
cd "$ROOT"

CC=${CC:-cc}
RUN_I386=${RUN_I386:-./scripts/run-i386.sh}
COVDIR=${COVDIR:-build/coverage}
ROOTDIR=${ROOTDIR:-$COVDIR/root}
REPORTDIR=${REPORTDIR:-$COVDIR/html}
SELFHOST=${SELFHOST:-1}
CFLAGS=${CFLAGS:-"-m32 -std=gnu99 -Wall -g -O0 --coverage -fno-strict-aliasing -Wno-pointer-sign -Wno-sign-compare -Wno-unused-result"}
LDFLAGS=${LDFLAGS:-"--coverage"}
LDLIBS=${LDLIBS:-"-lm -ldl"}

mkdir -p "$ROOTDIR" "$REPORTDIR"
find "$COVDIR" -name '*.gcda' -exec rm -f {} +

echo "building coverage compiler: $ROOTDIR/tcc"
# shellcheck disable=SC2086
$CC $CFLAGS -nostdinc -o "$ROOTDIR/tcc" tcc_nopp.c $LDFLAGS $LDLIBS
chmod +x "$ROOTDIR/tcc"

echo "running coverage checks"
OUT="$COVDIR/check" ROOTDIR="$ROOTDIR" RUN_I386="$RUN_I386" CC="$CC" ./scripts/test.sh

if [ "$SELFHOST" != 0 ]; then
    echo "running coverage selfhost"
    OUT="$COVDIR/selfhost" STAGE1ROOT="$ROOTDIR" RUN_I386="$RUN_I386" ./scripts/selfhost.sh
fi

echo "generating HTML coverage report"
if command -v gcovr >/dev/null 2>&1; then
    gcovr \
        --root "$ROOT" \
        --object-directory "$ROOTDIR" \
        --filter "$ROOT/tcc_nopp.c" \
        --html-details \
        --html-title "tcc_27_alt coverage" \
        -o "$REPORTDIR/index.html"
elif command -v lcov >/dev/null 2>&1 && command -v genhtml >/dev/null 2>&1; then
    lcov --capture --directory "$ROOTDIR" --output-file "$COVDIR/coverage.info"
    lcov --extract "$COVDIR/coverage.info" "$ROOT/tcc_nopp.c" --output-file "$COVDIR/coverage.filtered.info"
    genhtml "$COVDIR/coverage.filtered.info" --output-directory "$REPORTDIR"
else
    echo "error: install gcovr, or install both lcov and genhtml" >&2
    exit 1
fi

echo "coverage report: $REPORTDIR/index.html"
