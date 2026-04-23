# tcc_27_alt

`tcc_27_alt` is a cut-down TinyCC 0.9.27 tree for one target only:
i386 Linux ELF. The self-hosting compiler input is a flattened C source that
does not contain `#include`, `#define`, or conditional preprocessing
directives.

The goal is still to keep this a generally useful compiler for a small,
explicit C subset. It is intended as the base for a heavily refactored TCC,
not only as a bootstrap stunt. Removed features should be ones outside that
subset or outside the i386/Linux/ELF scope.

Removed from this tree: non-i386 backends, PE/COFF output, Windows support,
ARM/AArch64/C67/x86_64 generators, examples, generated manuals, configure
machinery, and broad upstream test suites that are not relevant to this slice.
Bounds checking/backtrace support and the in-memory `-run` engine are disabled;
tests execute generated i386 ELF files through `scripts/run-i386.sh` instead.
Assembler input and inline assembler are not supported in this reduced tree.
The assembler parser has been stripped; assembly sources, inline `asm`, asm
labels, and register variables are outside the supported subset.
Variable length arrays are also outside the subset; array bounds must be
compile-time constants.
Bit-fields are outside the subset as well. The compiler source itself uses
plain integer fields so the self-host input stays in the smaller dialect.
`enum` and `union` declarations are outside the subset. The compiler source
uses numeric constants and plain structs instead.
GNU/MS declaration attributes are rejected; this removes section, alias,
visibility, packed/aligned, and non-cdecl calling-convention syntax from the
front end.
GNU `typeof`, C11 `_Generic`, labels-as-values, and computed-branch extensions are also
outside the supported subset.
The compiler source has been ported away from `inline`, and the reduced
frontend treats `inline` spellings as ordinary identifiers rather than storage
specifiers.
Wide string/character literals and floating-point types/constants are outside
the subset. Ordinary byte strings and character constants remain supported.
Compound literals are outside the subset; casts remain supported.
64-bit integer types and operations are also outside the subset. The reduced
dialect uses `int`/`unsigned int` for 32-bit integers. Unsupported type and
storage spellings such as `long`, explicit `signed`, `register`, `auto`, and
`_Bool` are not treated as keywords.

## Build

```sh
./build.sh
```

This builds `build/root/tcc`, a 32-bit i386 Linux executable that emits i386
Linux ELF. The bootstrap compiler is built with the host C compiler using
`-m32`. All generated files are kept under `build/`.

## No-Preprocessor Source

The compiler source used for builds is `tcc_nopp.c`. It contains no
preprocessor directive lines and is compiled without configuration `-D` flags.

The old split compiler source is intentionally not part of this reduced tree.

## Test

```sh
./check.sh
```

The check target verifies:

- i386 relocatable ELF object output;
- selected compile-only C tests;
- dynamic i386 executable linking when i386 glibc CRT objects are available.

On an x86_64-only host without i386 glibc development files, the dynamic link
test is reported as skipped. Install the distribution's i386 libc development
package to enable it.

## Coverage

```sh
./scripts/coverage-html.sh
```

This builds an instrumented compiler under `build/coverage/root`, runs the
normal checks, runs the 3-stage bootstrap, and writes an HTML report to
`build/coverage/html/index.html`. Set `SELFHOST=0` to skip the bootstrap during
a coverage run.

## Self-host

```sh
./selfhost.sh
```

The self-host test performs a standard 3-stage bootstrap. Stage 1 is the
compiler built by `./build.sh` using `cc -m32`. Stage 1 builds stage 2, stage 2
builds stage 3, and stage 2 and stage 3 must match byte-for-byte:

```text
host cc -m32 tcc_nopp.c -nostdinc -> build/root/tcc
stage1 = build/root/tcc
stage1 tcc_nopp.c -> build/selfhost/tcc.stage2
stage2 tcc_nopp.c -> build/selfhost/tcc.stage3
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

- `tcc_nopp.c`: the no-preprocessor compiler source, including driver,
  parser, ELF output/linking, and i386 code generator.
- `include/`: builtin headers supplied by TCC.
- `tests/`: retained smoke tests for this reduced i386/Linux compiler.
