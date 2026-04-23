#!/bin/sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
cd "$ROOT"

OUT=${OUT:-build/selfhost}
RUN_I386=${RUN_I386:-./scripts/run-i386.sh}
STAGE1ROOT=${STAGE1ROOT:-build/root}
STAGE1=$STAGE1ROOT/tcc
STAGE2=$OUT/tcc.stage2
STAGE3=$OUT/tcc.stage3
NOPP=tcc_nopp.c
mkdir -p "$OUT"

if ! ./scripts/has-i386-glibc.sh; then
    echo "selfhost skipped: i386 glibc development files are required"
    echo "missing one of crt1.o, crti.o, crtn.o under /usr/lib/i386-linux-gnu, /lib/i386-linux-gnu, /usr/lib32, or /lib32"
    exit 0
fi

build_tcc()
{
    compiler=$1
    output=$2
    "$RUN_I386" "$compiler" "$NOPP" -o "$output" -lm -ldl
}

echo "checking stage1: $STAGE1"
if ! "$RUN_I386" "$STAGE1" -v >/dev/null 2>&1; then
    echo "selfhost skipped: stage1 exists, but this host cannot execute i386 binaries"
    exit 0
fi

echo "building stage2 with stage1"
build_tcc "$STAGE1" "$STAGE2"
chmod +x "$STAGE2"

echo "building stage3 with stage2"
build_tcc "$STAGE2" "$STAGE3"
chmod +x "$STAGE3"

echo "comparing stage2 and stage3"
cmp "$STAGE2" "$STAGE3"

echo "checking stage3 dynamic output"
"$RUN_I386" "$STAGE3" tests/hello.c -o "$OUT/hello"
file "$OUT/hello" | grep -q 'ELF 32-bit'
chmod +x "$OUT/hello"
"$RUN_I386" "$OUT/hello" > "$OUT/hello.stdout"
grep -q 'hello i386 42' "$OUT/hello.stdout"

echo "selfhost complete"
