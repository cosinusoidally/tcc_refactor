#!/bin/sh
set -eu

for dir in \
    /usr/lib/i386-linux-gnu \
    /lib/i386-linux-gnu \
    /usr/lib32 \
    /lib32
do
    if [ -f "$dir/crt1.o" ] && [ -f "$dir/crti.o" ] && [ -f "$dir/crtn.o" ]; then
        exit 0
    fi
done

exit 1
