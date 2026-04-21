#!/bin/sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
cd "$ROOT"

if [ ! -x build/root/tcc ] || [ ! -f build/root/libtcc1.o ]; then
    ./build.sh
fi

exec ./scripts/test.sh
