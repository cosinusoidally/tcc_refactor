#!/bin/sh
set -eu

if [ "$#" -eq 0 ]; then
    echo "usage: $0 PROGRAM [ARG...]" >&2
    exit 2
fi

if [ -x "$1" ]; then
    exec "$@"
fi

for loader in /lib/ld-linux.so.2 /lib32/ld-linux.so.2 /lib/i386-linux-gnu/ld-linux.so.2; do
    if [ -x "$loader" ]; then
        exec "$loader" "$@"
    fi
done

exec "$@"
