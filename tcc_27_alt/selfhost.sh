#!/bin/sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
cd "$ROOT"

if [ ! -x build/root/tcc ]; then
    ./build.sh
fi

exec ./scripts/selfhost.sh
