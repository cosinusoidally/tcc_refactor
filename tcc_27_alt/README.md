# tcc_27_alt

`tcc_27_alt` is a cut-down TinyCC 0.9.27 tree for one target only:
i386 Linux ELF. The self-hosting compiler input is a flattened C source that
does not contain `#include`, `#define`, or conditional preprocessing
directives. The tree still keeps the historical preprocessor source for now so
the flattened source can be regenerated while the code is reduced further.

Removed from this tree: non-i386 backends, PE/COFF output, Windows support,
ARM/AArch64/C67/x86_64 generators, examples, generated manuals, configure
machinery, and broad upstream test suites that are not relevant to this slice.
Bounds checking/backtrace support and the in-memory `-run` engine are disabled;
tests execute generated i386 ELF files through `scripts/run-i386.sh` instead.

## Build

```sh
./build.sh
```

This builds:

- `build/root/tcc`: a 32-bit i386 Linux executable that emits i386 Linux ELF.
- `build/root/libtcc1.a`: the minimal i386 runtime archive used when linking
  programs.

The bootstrap compiler is built with the host C compiler using `-m32`, and the
runtime archive is built with `build/root/tcc` itself. All generated files are
kept under `build/`.

## No-Preprocessor Source

The compiler source used for builds is `tcc_nopp.c`. It contains no
preprocessor directive lines and is compiled with `-nostdinc` and without
configuration `-D` flags.

`./scripts/gen-nopp.sh` can regenerate `build/nopp/tcc_nopp.c` from the old
split source while the transition is still in progress, but the normal build
and self-host path do not depend on generating it.

## Test

```sh
./check.sh
```

The check target verifies:

- selected preprocessor outputs;
- i386 relocatable ELF object output;
- selected compile-only C tests;
- dynamic i386 executable linking when i386 glibc CRT objects are available.

On an x86_64-only host without i386 glibc development files, the dynamic link
test is reported as skipped. Install the distribution's i386 libc development
package to enable it.

## Self-host

```sh
./selfhost.sh
```

Self-hosting means `build/root/tcc` can generate the no-preprocessor source,
compile it into a new i386 `tcc`, that new compiler can rebuild the i386
runtime archive and compile another copy from the same no-preprocessor source,
and two consecutive self-built compilers match byte-for-byte:

```text
host cc -m32 tcc_nopp.c -nostdinc -> build/root/tcc
build/root/tcc tcc_nopp.c -nostdinc -> build/selfhost/tcc.stage1
stage1 -> build/selfhost/stage1root/libtcc1.a
stage1 tcc_nopp.c -nostdinc -> build/selfhost/tcc.stage2
stage2 -> build/selfhost/stage2root/libtcc1.a
stage2 tcc_nopp.c -nostdinc -> build/selfhost/tcc.stage3
cmp stage2 stage3
```

Because this target emits and then runs i386 executables, it requires:

- i386 Linux execution support;
- i386 glibc development files, including `crt1.o`, `crti.o`, and `crtn.o`;
- i386 `libc.so`, `libm.so`, and `libdl.so` in `/usr/lib/i386-linux-gnu`,
  `/lib/i386-linux-gnu`, `/usr/lib32`, or `/lib32`.

If those prerequisites are missing, `./selfhost.sh` exits successfully after
printing a skip reason.

## Source Map

- `tcc.c`, `libtcc.c`, `tccpp.c`, `tccgen.c`: driver, library API,
  preprocessor, parser, and code-generation frontend.
- `tccelf.c`: ELF object, executable, shared library, archive, and dynamic
  linker support.
- `i386-gen.c`, `i386-link.c`, `i386-asm.c`: i386 backend and assembler.
- `lib/libtcc1.c`, `lib/alloca86.S`: minimal runtime routines and alloca
  support for linked output.
- `include/`: builtin headers supplied by TCC.
- `tests/`: retained smoke tests for this reduced i386/Linux compiler.
