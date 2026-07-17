# TCC 0.9.27 Layered Bootstrap, Take 3

Take3 is a two-layer i386 Linux refactor of TCC 0.9.27. The retained cc1
routes start from a small source file that is valid C, SpiderMonkey 45
JavaScript, and mawkcc input. The direct cc2 routes instead execute or compile
the full typed compiler as the seed and skip cc1 completely.

The supported target is deliberately limited to 32-bit i386 Linux. The final
compiler provides TCC's i386 code generator, assembler, archive handling, and
ELF linker. It does not use a GNU linker or `libgcc` in the compiler-only
bootstrap paths. `tccrun` and dynamic-loader APIs are outside this bootstrap.

## Layers

### cc1

`cc1.c` is the standalone base compiler. It contains:

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

The source language is still referred to as the cc0 dialect, but full-compiler
builds now expose its declaration spellings explicitly with `-Dfunction=int`
and `-Dvar=int` rather than relying on the legacy `-std=cc0` shorthand.

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

In the retained cc1 routes, cc1 is used only to produce a transitional cc2
tool. In the direct routes, GCC or SpiderMonkey produces that disposable cc2
seed without compiling or running cc1. In both cases the seed builds every
object in canonical cc2 generation one; generation one rebuilds every object
and executable as generation two, and the scripts require byte identity for
each pair. No cc1-built object is linked into `cc2.exe`, `cc2_static.exe`, or
either final TCC.
cc2 owns its `main` entry point and the small lexical/number helper surface it
needs. Its object and typed bridge have no unresolved `cc0_*` or `cc1_*`
dependencies. The two layers are independently runnable compilers, not
cumulative executable links.

The first cc2 executable uses `cc2_boot_storage.c` and
`cc2_backend_stubs.c`. Build scripts concatenate `cc2.c` and the boot storage
into an artifact-local translation unit because cc1 deliberately has no
general C preprocessor. Full cc2 then compiles `tcc_unified.c`, whose typed C
bridge is in `cc2_tcc_prims.c`.

`cc2_runtime.c` provides the i386 arithmetic and floating helpers otherwise
supplied by libgcc. The static chain extends the libc in explicit levels:
the shared C/JavaScript `cc1_libc.c` and typed `cc2_libc.c`.
Native i386 vararg stack-address primitives live separately in
`cc1_libc_asm.c` so the libc source itself remains valid JavaScript.

## Bootstrap Graphs

The shortest dynamic graph is:

```text
GCC or SpiderMonkey
  -> disposable full cc2 seed (no cc1 source or object)
  -> cc2 generation 1 (all objects built by cc2)
  -> identical cc2 generation 2 (all objects rebuilt by generation 1)
  -> tcc_layered.exe
  -> stock TCC 0.9.27 outputs
  -> sums_tcc_27 verification
```

The direct static graph uses the same seed to build two bit-identical static
cc2 generations and publishes generation two as `tcc_layered_static.exe`.
Compiler objects are identical between the dynamic and static generations;
only startup and libc objects select the link mode.

The retained cc1 dynamic graph is:

```text
SpiderMonkey or mawkcc
  -> cc1.o + cc2_stubs.o
  -> cc1.exe
  -> independent cc2_boot.exe (no cc1.o)
  -> transitional full cc2
  -> cc2 generation 1 (all objects built by cc2)
  -> identical cc2 generation 2 (all objects rebuilt by generation 1)
  -> tcc_layered.exe (the canonical generation-2 cc2)
  -> stock TCC 0.9.27 outputs
  -> sums_tcc_27 verification
```

The retained cc1 fully static graph is independent after the seed:

```text
SpiderMonkey or mawkcc
  -> cc1_static.exe
  -> independent cc2_boot_static.exe (no cc1.o)
  -> cc2_static_boot.exe
  -> transitional full static cc2
  -> static cc2 generation 1 (all objects built by cc2)
  -> identical static cc2 generation 2
  -> tcc_layered_static.exe (the canonical generation-2 static cc2)
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
`prims.js`, `cc1_libc.c`, `cc1.c`, and `cc2_stubs.c` directly. JavaScript cc1
compiles the canonical `cc1.o` and `cc2_stubs.o`, compiles the static runtime,
and links:

```text
artifacts/cc1.exe
artifacts/cc1_static.exe
```

The seed script does not clean artifacts. Clean before testing it so stale
objects cannot conceal a failure.

To skip cc1 and execute `cc2.c` directly in SpiderMonkey, use:

```sh
./mk_clean
cd tcc_27_layered_take3
./mk_cc2_js
```

The JavaScript seed loads `prims.js`, `cc1_libc.c`, bootstrap storage, backend
stubs, and `cc2.c`. It compiles and links a disposable fully static cc2, then
`mk_cc2_from_seed` performs a complete two-generation static self-host check.
This path requires no i386 dynamic loader, glibc, libm, or libgcc. `prims.js`
provides only operator, byte-memory, and low-level host runtime meanings. The
shared libc implements allocation, strings, descriptor caching, and FILE
operations. Its unlink runtime primitive is deliberately inert in JavaScript.

SpiderMonkey also builds metadata-only shared objects from
`cc2_dynamic_libc_imports.c` and `cc2_dynamic_libm_imports.c`. They provide the
symbol names and `libc.so.6`/`libm.so.6` SONAMEs required by the ELF linker,
but none of their bodies enter `cc2.exe`. The two verified static cc2
generations use that metadata to build two identical dynamic generations.
Consequently `mk_cc2_js` always publishes the same dynamic `cc2.exe` and
static `cc2_static.exe`, even on an amd64 host with no i386 glibc files. The
dynamic executable naturally requires i386 glibc only when it is run.

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

Both mawkcc scripts first use that upstream executable to compile the vendored
`mawkcc_self_bugfix.c` into `artifacts/mawkcc_self_bugfix.exe`. Future
take3-specific mawkcc fixes belong in the vendored source; the upstream
`ai_experiments/mawkcc` tree remains unchanged until those fixes are ready to
be incorporated there.

`mk_cc1_mawkcc` then concatenates `cc1.c`, `cc2_stubs.c`, and
`cc0_mawkcc_compat.c` into `artifacts/cc1_mawkcc.c`. The bugfix compiler
produces the disposable `cc1_mawkcc.exe`, which compiles the canonical cc1
objects and links `cc1.exe` and `cc1_static.exe`. The compatibility suffix is
present only in the disposable seed.

`mk_cc2_mawkcc` is the corresponding direct-cc2 experiment. It contains no
cc1 input and is structured to feed a successful seed into the same
`mk_cc2_from_seed` self-host check. A current mawkcc probe does not yet compile
the full cc2 input: the bugfix compiler reports the unsupported true local
declarations and subsequently exhausts its unchanged relocation capacity.
This route is therefore retained for local-variable conversion and vendored
mawkcc-capacity work, but is not currently a passing bootstrap path.

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

To build cc2 directly with GCC and omit cc1 entirely, use:

```sh
./mk_clean
cd tcc_27_layered_take3
./mk_cc2_gcc
```

GCC builds only the disposable seed. That seed then builds both canonical
cc2 generations and their static counterparts; no GCC-built object survives
in either published executable.

## Full Builds

After either seed, build the dynamic compiler with:

```sh
./mk_tcc_layered_via_cc1
```

Build the completely static compiler chain with:

```sh
./mk_tcc_layered_via_cc1_static
```

After `mk_cc2_gcc` or `mk_cc2_js`, continue the direct dynamic chain with:

```sh
./mk_tcc_layered_via_cc2
```

The direct static chain is also available after either seed:

```sh
./mk_tcc_layered_via_cc2_static
```

These scripts read only canonical cc2 generation objects. They do not build,
execute, or link cc1. Both build the stock TCC outputs and verify the immutable
`sums_tcc_27` hashes.

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

The test loads production `prims.js`, `cc1_libc.c`, `cc1.c`, and `cc2.c`
without source rewriting, initializes both layers, and exercises
representative base, libc, and cc2 operations.

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
`cc0_static_start.c` and `cc1_static_start.c` provide seed startup.
`linux_i386_start.c`, `cc2_start.c`, and `cc2_static_start.c` provide ordinary
full-compiler i386 startup without depending on cc1's entry adapter.
`cc1_libc.c` provides both the base allocation and descriptor operations and
the stream/formatting surface needed to enter cc2. The allocator uses `brk` in
4 KiB increments. Descriptor caching avoids per-byte compiler I/O.

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
