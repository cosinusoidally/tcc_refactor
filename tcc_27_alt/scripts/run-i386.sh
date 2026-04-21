#!/bin/sh
set -eu

if [ "$#" -eq 0 ]; then
    echo "usage: $0 PROGRAM [ARG...]" >&2
    exit 2
fi

exec "$@"
