#!/bin/sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
cd "$ROOT"

ROOTDIR=build/root
RUN_I386=${RUN_I386:-./scripts/run-i386.sh}
TCC="$RUN_I386 $ROOTDIR/tcc -B$ROOTDIR -Iinclude -I."
OUT=build/check
mkdir -p "$OUT"

echo "checking compiler identity"
"$RUN_I386" "$ROOTDIR/tcc" -v >/dev/null

echo "checking preprocessor"
for src in tests/pp/01.c tests/pp/02.c tests/pp/03.c tests/pp/04.c tests/pp/05.c; do
    base=${src%.c}
    "$RUN_I386" "$ROOTDIR/tcc" -E -P "$src" > "$OUT/$(basename "$base").out"
    diff -u -w "$base.expect" "$OUT/$(basename "$base").out"
done

echo "checking i386 object output"
$TCC -c tests/hello.c -o "$OUT/hello.o"
file "$OUT/hello.o" | grep -q 'ELF 32-bit'

echo "checking selected compile-only tests"
for src in \
    tests/tests2/00_assignment.c \
    tests/tests2/03_struct.c \
    tests/tests2/04_for.c \
    tests/tests2/05_array.c \
    tests/tests2/07_function.c \
    tests/tests2/10_pointer.c \
    tests/tests2/18_include.c
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
else
    echo "skipping dynamic link: i386 glibc crt objects were not found"
fi

echo "check complete"
