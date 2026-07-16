# TCC 0.9.27 Layered Bootstrap, Take 3

Take3 is a two-layer i386 Linux refactor of TCC 0.9.27. The compiler starts
from a source file that is simultaneously valid C, SpiderMonkey 45 JavaScript,
and mawkcc input, then advances directly to the full typed TCC layer.

The supported target is deliberately limited to 32-bit i386 Linux. The final
compiler provides TCC's i386 code generator, assembler, archive handling, and
ELF linker. It does not use a GNU linker or `libgcc` in the compiler-only
bootstrap paths. `tccrun` and dynamic-loader APIs are outside this bootstrap.

## Layers

### cc1

`cc1.c` is the permanent base compiler. It contains:

- The operator-free cc0 source dialect parser and i386 code generator.
- The ELF32 relocatable object writer.
- The lower ELF linker used before the full TCC linker is executable.
- Shared file/line/column diagnostics and the command-line driver.
- Dynamic storage throughout; it introduces no fixed compiler limits beyond
  limits already present in TCC.

The old take2 split between `cc0.c` and a separate preprocessing `cc1.c` is
gone. Once `cc2.c` became valid in the base dialect, the extra preprocessing
and enum/typedef/array lowering pass was redundant. Take3 therefore seeds
`cc1.c` directly and retains no `cc0.exe`, `cc0_static.exe`, or
`cc1_stubs.c` stage.

The dialect remains named `cc0` in the `-std=cc0` option. That name describes
the source language, not a compiler layer.

`cc1.c` uses `function`, `var`, assignments, calls, and lowercase primitives
such as `add`, `sub`, `ri32`, and `wi8`. Operators are implemented by host
support during seeding and by compiler builtins after self-hosting. Character
codes use `mkC("x")`; address formation uses `addr(name)`. Every control-flow
body uses braces.

### cc2

`cc2.c` is the complete typed-C and TCC layer. It contains the migrated TCC
preprocessor, parser, i386 backend, assembler, archive support, and ELF linker.
It is also directly valid SpiderMonkey JavaScript and directly compilable by
cc1.

The first cc2 executable uses `cc2_boot_storage.c` and
`cc2_backend_stubs.c`. Build scripts concatenate `cc2.c` and the boot storage
into an artifact-local translation unit because cc1 deliberately has no
general C preprocessor. Full cc2 then compiles `tcc_unified.c`, whose typed C
bridge is in `cc2_tcc_prims.c`.

`cc2_runtime.c` provides the i386 arithmetic and floating helpers otherwise
supplied by libgcc. The static chain extends the libc in explicit levels:
`cc0_libc.c`, `cc1_libc.c`, `cc2_libc_qsort.c`, and `cc2_libc.c`.

## Bootstrap Graph

The dynamic graph is:

```text
SpiderMonkey or mawkcc
  -> cc1.o + cc2_stubs.o
  -> cc1.exe
  -> cc2_boot.exe
  -> cc2.exe
  -> tcc_layered.exe
  -> stock TCC 0.9.27 outputs
  -> sums_tcc_27 verification
```

The fully static graph is independent after the seed:

```text
SpiderMonkey or mawkcc
  -> cc1_static.exe
  -> cc2_boot_static.exe
  -> cc2_static_boot.exe
  -> cc2_static.exe
  -> tcc_layered_static.exe
  -> stock TCC 0.9.27 outputs
  -> sums_tcc_27 verification
```

The temporary and provisional cc2 executables are links of the same cc2
compiler layer. They are needed to cross typed runtime and floating conversion
dependencies; they do not constitute another source layer.

## JavaScript Seed

Run from the repository root:

```sh
./mk_clean
cd tcc_27_layered_take3
./mk_cc1_js
```

`js` must be SpiderMonkey jsshell 45 for i686 Linux. The script loads
`prims.js`, `cc1.c`, and `cc2_stubs.c` directly. JavaScript cc1 compiles the
canonical `cc1.o` and `cc2_stubs.o`, compiles the static runtime, and links:

```text
artifacts/cc1.exe
artifacts/cc1_static.exe
```

The seed script does not clean artifacts. Clean before testing it so stale
objects cannot conceal a failure.

## mawkcc Seed

Run from the repository root:

```sh
./mk_clean
cd tcc_27_layered_take3
./mk_cc1_mawkcc
```

The required seed is:

```text
../ai_experiments/mawkcc/artifacts/mawkcc.self.exe
```

The script concatenates `cc1.c`, `cc2_stubs.c`, and
`cc0_mawkcc_compat.c` into `artifacts/cc1_mawkcc.c`. mawkcc produces the
disposable `cc1_mawkcc.exe`, which then compiles the canonical cc1 objects and
links `cc1.exe` and `cc1_static.exe`. The compatibility suffix is present only
in the disposable seed.

## GCC Seed

Run from the repository root:

```sh
./mk_clean
cd tcc_27_layered_take3
./mk_cc1_gcc
```

GCC must support `-m32`. It compiles `prims.c`, `cc1.c`, and `cc2_stubs.c` as
GNU89 C and links the disposable `artifacts/cc1_gcc.exe`. That seed, rather
than GCC, produces the canonical `cc1.o`, `cc2_stubs.o`, `cc1.exe`, and
`cc1_static.exe`. Those canonical artifacts are byte-identical to the
JavaScript and mawkcc seed results.

## Full Builds

After either seed, build the dynamic compiler with:

```sh
./mk_tcc_layered_via_cc1
```

Build the completely static compiler chain with:

```sh
./mk_tcc_layered_via_cc1_static
```

Do not run `mk_clean` between the seed and full-chain script. Neither full
chain invokes GCC or a pre-existing TCC. The dynamic chain links against the
versioned i386 `libc.so.6` and `libm.so.6` runtime DSOs so it also works with
older split glibc installations. The static chain has no host runtime
dependency.

The native validation entry point is:

```sh
./mk_tcc_27_layered_take3
```

It starts with `mk_clean`, builds the two permanent layers as GNU89 C, loads
both shared sources directly in SpiderMonkey, seeds canonical cc1 through
JavaScript, verifies a self-compiled `cc1.o`, runs the complete dynamic chain,
and checks every fixed stock hash.

## JavaScript Source Test

From this directory:

```sh
./mk_js_layers_test
```

The test loads production `prims.js`, `cc1.c`, and `cc2.c` without source
rewriting, initializes both layers, and exercises representative base and cc2
operations.

## Compatibility Contract

The repository-level `sums_tcc_27` file is immutable. Every successful full
build reproduces:

- `artifacts/libc_boot4.o`
- `artifacts/libc_static.o`
- `artifacts/libtcc1.o`
- `artifacts/tcc.o`
- `artifacts/tcc_27_boot_static.exe`

All generated objects, executables, and combined sources belong under the
repository-level `artifacts/` directory.

## Static Runtime

`linux_i386_syscalls.c` contains the auditable `.byte` implementation of the
five-argument i386 `int 0x80` entry. Higher syscall wrappers call that function;
cc1 never inlines syscalls.

`cc0_static_syscalls.c` implements the low-level file and break operations.
`cc0_static_start.c` and `cc1_static_start.c` provide process startup.
`cc0_libc.c` provides the base allocation and descriptor operations, while
`cc1_libc.c` adds the libc surface needed to enter cc2. The allocator uses
`brk` in 4 KiB increments. Descriptor caching avoids per-byte compiler I/O.

The dynamic and static links consume identical compiler objects. Runtime and
startup objects determine link mode; compiler source files do not contain
conditional dynamic/static implementations.

## Development Rules

See `AGENTS.md`. In particular:

- Modify take3 compiler code only in this directory and the permitted root
  build script.
- Support only i386 Linux.
- Keep `cc1.c` and `cc2.c` directly valid SpiderMonkey 45 JavaScript.
- Keep base-dialect code operator-free and use `mkC` for character codes.
- Do not introduce arbitrary implementation limits.
- Keep all control-flow bodies braced.
- Do not use the discarded `tcc_27_layered` directory as a reference.
- Never change `sums_tcc_27` to accommodate output changes.

## Licensing

This tree is derived from TinyCC 0.9.27. See `COPYING` and `RELICENSING` for
the inherited licensing terms and provenance.
