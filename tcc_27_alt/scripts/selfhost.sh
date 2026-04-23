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
NOSTD_STAGE2=$OUT/tcc.nostdlib.stage2
NOSTD_STAGE3=$OUT/tcc.nostdlib.stage3
NOSTD_STAGE2_OBJ=$OUT/tcc.nostdlib.stage2.o
NOSTD_STAGE3_OBJ=$OUT/tcc.nostdlib.stage3.o
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

find_crt_dir()
{
    for dir in \
        /usr/lib/i386-linux-gnu \
        /lib/i386-linux-gnu \
        /usr/lib32 \
        /lib32
    do
        if [ -f "$dir/crt1.o" ] && [ -f "$dir/crti.o" ] && [ -f "$dir/crtn.o" ]; then
            printf '%s\n' "$dir"
            return 0
        fi
    done
    return 1
}

build_tcc_nostdlib()
{
    compiler=$1
    object=$2
    output=$3
    crt_dir=$4
    "$RUN_I386" "$compiler" -c "$NOPP" -o "$object"
    file "$object" | grep -q 'ELF 32-bit'
    "$RUN_I386" "$compiler" \
        -nostdlib \
        "$crt_dir/crt1.o" \
        "$crt_dir/crti.o" \
        "$object" \
        "$crt_dir/crtn.o" \
        -o "$output" \
        -lc -lm -ldl
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

CRT_DIR=$(find_crt_dir)
echo "building nostdlib stage2 with stage1"
build_tcc_nostdlib "$STAGE1" "$NOSTD_STAGE2_OBJ" "$NOSTD_STAGE2" "$CRT_DIR"
chmod +x "$NOSTD_STAGE2"

echo "building nostdlib stage3 with nostdlib stage2"
build_tcc_nostdlib "$NOSTD_STAGE2" "$NOSTD_STAGE3_OBJ" "$NOSTD_STAGE3" "$CRT_DIR"
chmod +x "$NOSTD_STAGE3"

echo "comparing nostdlib stage2 and stage3"
cmp "$NOSTD_STAGE2" "$NOSTD_STAGE3"

echo "checking nostdlib stage3 dynamic output"
"$RUN_I386" "$NOSTD_STAGE3" tests/hello.c -o "$OUT/hello-nostdlib"
file "$OUT/hello-nostdlib" | grep -q 'ELF 32-bit'
chmod +x "$OUT/hello-nostdlib"
"$RUN_I386" "$OUT/hello-nostdlib" > "$OUT/hello-nostdlib.stdout"
grep -q 'hello i386 42' "$OUT/hello-nostdlib.stdout"

echo "selfhost complete"
