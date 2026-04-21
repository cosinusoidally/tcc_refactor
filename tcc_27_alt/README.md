# tcc_27_alt

`tcc_27_alt` is a cut-down TinyCC 0.9.27 tree for one target only:
i386 Linux ELF. It keeps the C compiler, preprocessor, ELF linker, i386 code
generator, i386 assembler, minimal builtin headers, and the small i386 runtime
archive needed by generated binaries.

Removed from this tree: non-i386 backends, PE/COFF output, Windows support,
ARM/AArch64/C67/x86_64 generators, examples, generated manuals, configure
machinery, and broad upstream test suites that are not relevant to this slice.

## Build

```sh
./build.sh
```

This builds:

- `build/root/tcc`: a host executable that emits i386 Linux ELF.
- `build/root/libtcc1.a`: the minimal i386 runtime archive used when linking
  programs.

The bootstrap compiler is built with the host C compiler, but the runtime
archive is built with `build/root/tcc` itself. All generated files are kept
under `build/`.

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

Self-hosting means `build/root/tcc` can compile `tcc.c` into a new i386 `tcc`, that new
compiler can rebuild the i386 runtime archive and compile another copy, and two
consecutive self-built compilers match byte-for-byte:

```text
host cc -> build/root/tcc
build/root/tcc -> build/selfhost/tcc.stage1
stage1 -> build/selfhost/stage1root/libtcc1.a
stage1 -> build/selfhost/tcc.stage2
stage2 -> build/selfhost/stage2root/libtcc1.a
stage2 -> build/selfhost/tcc.stage3
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
