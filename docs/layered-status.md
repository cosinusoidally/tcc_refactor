# Layered Bootstrap Status

This tree is being refactored toward the staged compiler described in
`layered_bootstrap.txt`. The active compatibility target is still TinyCC
0.9.27 output for the selected bootstrap files: every step must keep
`sha256sum -c sums_tcc_27` passing without changing `sums_tcc_27`.

## Active Compiler Surface

The current `tcc_27_layered` build is a 32-bit Linux/ELF compiler built with
`-DONE_SOURCE`. It includes the shared front end, preprocessor, i386 code
generator, assembler support, ELF writer, and command-line driver. Its default
library directory is `lib32`, matching the i386 target used by the bootstrap
and allowing normal glibc dynamic links to find 32-bit crt and libc files on
the current host layout.

The baseline source tree in `tcc_27/` is read-only for this refactor. It is
compiled only as a fixture to prove that generated objects and the static
bootstrap executable still match the recorded hashes.

## Removed Surface

Bounds checking is not part of the layered bootstrap target. The old native
build auto-enabled `CONFIG_TCC_BCHECK` on i386/x86_64, which pulled in command
line handling and object metadata for `-b`. That configuration is now disabled
in `tcc_27_layered/tcc.h`, and the unused runtime implementation
`tcc_27_layered/lib/bcheck.c` has been removed.

This should not change normal compilation output because the bounds machinery
only affects builds that request `-b`. The required invariant is still the
hash check against `sums_tcc_27`.

## Verification

`mk_tcc_27_layered` is the required non-coverage verification path. In addition
to the static bootstrap hash checks, it now verifies that:

- `tcc_27_layered` can create its private runtime archive with `tcc -ar`.
- `tcc_27_layered` can build and start a normal glibc-linked executable of
  itself.
- `-nostdinc` remains usable on a source file that does not need host headers.
- The existing static `-nostdlib` path still produces the hash-checked
  bootstrap executable.
- `tcc_27_layered` can build and start a normal glibc-linked executable from
  the baseline `tcc_27` source fixture.
- `cc0.c` remains in the C/JavaScript dialect intersection by compiling as C
  with both GCC and the layered TCC using `-Dfunction=int -Dvar=int`, and by
  loading under SpiderMonkey `js`.

## cc0 Dialect Seed

`tcc_27_layered/cc0.c` is the initial placeholder for the base dialect. It is
not a compiler yet; it is a checked-in syntax contract. Function declarations
use JavaScript syntax, and the C build maps `function` and `var` to `int`.
Function arguments therefore use old-style C implicit `int` parameters, which
keeps the same file parseable by both SpiderMonkey and a C compiler.

## Internal Map

The current one-source build reaches the compiler through `tcc.c`, which
includes `libtcc.c` and `tcctools.c`.

`libtcc.c` owns high-level compilation and linking orchestration: creating a
`TCCState`, defining target macros, adding include and library paths, dispatching
source files by type, and writing the requested output.

`tccpp.c` owns preprocessing and tokenization. `tccgen.c` parses C and emits
target-independent code generation requests. The active backend is i386:
`i386-gen.c` emits code, `i386-link.c` applies i386 relocations, and
`i386-asm.c` handles inline and standalone assembly. `tccelf.c` owns ELF
sections, symbols, relocations, archives, dynamic linking metadata, and final
file output.
