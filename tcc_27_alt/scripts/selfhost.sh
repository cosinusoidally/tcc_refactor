#!/bin/sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
cd "$ROOT"

OUT=build/selfhost
RUN_I386=${RUN_I386:-./scripts/run-i386.sh}
BOOTROOT=build/root
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
    bdir=$3
    "$RUN_I386" "$compiler" -B"$bdir" -nostdinc "$NOPP" -o "$output" -lm -ldl
}

build_runtime()
{
    compiler=$1
    bdir=$2
    mkdir -p "$bdir"
    "$RUN_I386" "$compiler" -B"$bdir" -Iinclude -I. -c lib/libtcc1.c -o "$bdir/libtcc1.o"
    "$RUN_I386" "$compiler" -B"$bdir" -Iinclude -I. -c lib/alloca86.S -o "$bdir/alloca86.o"
    "$RUN_I386" "$compiler" -ar rcs "$bdir/libtcc1.a" "$bdir/libtcc1.o" "$bdir/alloca86.o"
}

echo "building stage1 with $BOOTROOT/tcc"
build_tcc "$BOOTROOT/tcc" "$OUT/tcc.stage1" "$BOOTROOT"
chmod +x "$OUT/tcc.stage1"

if ! "$RUN_I386" "$OUT/tcc.stage1" -v >/dev/null 2>&1; then
    echo "selfhost skipped: built stage1, but this host cannot execute i386 binaries"
    exit 0
fi

echo "building runtime with stage1"
build_runtime "$OUT/tcc.stage1" "$OUT/stage1root"

echo "building stage2 with stage1"
build_tcc "$OUT/tcc.stage1" "$OUT/tcc.stage2" "$OUT/stage1root"
chmod +x "$OUT/tcc.stage2"

echo "building runtime with stage2"
build_runtime "$OUT/tcc.stage2" "$OUT/stage2root"

echo "building stage3 with stage2"
build_tcc "$OUT/tcc.stage2" "$OUT/tcc.stage3" "$OUT/stage2root"
chmod +x "$OUT/tcc.stage3"

cmp "$OUT/tcc.stage2" "$OUT/tcc.stage3"

echo "checking stage2 dynamic output"
"$RUN_I386" "$OUT/tcc.stage2" -B"$OUT/stage2root" -Iinclude -I. tests/hello.c -o "$OUT/hello"
file "$OUT/hello" | grep -q 'ELF 32-bit'
chmod +x "$OUT/hello"
"$RUN_I386" "$OUT/hello" > "$OUT/hello.stdout"
grep -q 'hello i386 42' "$OUT/hello.stdout"

echo "selfhost complete"
