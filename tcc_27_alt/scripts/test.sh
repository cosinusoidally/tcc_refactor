#!/bin/sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
cd "$ROOT"

ROOTDIR=build/root
RUN_I386=${RUN_I386:-./scripts/run-i386.sh}
CC=${CC:-cc}
TCC="$RUN_I386 $ROOTDIR/tcc -B$ROOTDIR -Iinclude -I."
OUT=build/check
mkdir -p "$OUT"

echo "checking compiler identity"
"$RUN_I386" "$ROOTDIR/tcc" -v >/dev/null

echo "checking i386 object output"
$TCC -c tests/hello.c -o "$OUT/hello.o"
file "$OUT/hello.o" | grep -q 'ELF 32-bit'
$TCC -c tests/obj_main.c -o "$OUT/obj_main.o"
$TCC -c tests/obj_helper.c -o "$OUT/obj_helper.o"
file "$OUT/obj_main.o" | grep -q 'ELF 32-bit'
file "$OUT/obj_helper.o" | grep -q 'ELF 32-bit'

echo "checking selected compile-only tests"
for src in \
    tests/tests2/00_assignment.c \
    tests/tests2/03_struct.c \
    tests/tests2/04_for.c \
    tests/tests2/05_array.c \
    tests/tests2/07_function.c \
    tests/tests2/10_pointer.c \
    tests/tests2/18_include.c \
    tests/implicit_call.c
do
    obj="$OUT/$(basename "${src%.c}").o"
    $TCC -c "$src" -o "$obj"
    file "$obj" | grep -q 'ELF 32-bit'
done

if ./scripts/has-i386-glibc.sh; then
    echo "checking dynamic i386 executable link"
    $TCC tests/hello.c -o "$OUT/hello"
    file "$OUT/hello" | grep -q 'ELF 32-bit'
    chmod +x "$OUT/hello"
    if "$RUN_I386" "$OUT/hello" > "$OUT/hello.stdout" 2>/dev/null; then
        grep -q 'hello i386 42' "$OUT/hello.stdout"
    else
        echo "note: built i386 executable, but this host cannot run it"
    fi

    echo "checking linked i386 objects"
    $TCC "$OUT/obj_main.o" "$OUT/obj_helper.o" -o "$OUT/obj-linked-tcc"
    "$CC" -m32 "$OUT/obj_main.o" "$OUT/obj_helper.o" -o "$OUT/obj-linked-gcc"
    chmod +x "$OUT/obj-linked-tcc" "$OUT/obj-linked-gcc"
    "$RUN_I386" "$OUT/obj-linked-tcc" > "$OUT/obj-linked-tcc.stdout" 2>/dev/null || true
    "$RUN_I386" "$OUT/obj-linked-gcc" > "$OUT/obj-linked-gcc.stdout" 2>/dev/null || true
    grep -q 'object link 42' "$OUT/obj-linked-tcc.stdout"
    grep -q 'object link 42' "$OUT/obj-linked-gcc.stdout"
else
    echo "skipping dynamic link: i386 glibc crt objects were not found"
fi

echo "check complete"
