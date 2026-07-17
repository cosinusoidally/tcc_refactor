# TCC 0.9.27 Layered Bootstrap, Take 3

Take3 is a single-compiler-layer i386 Linux refactor of TCC 0.9.27. `cc2.c`
is valid C, SpiderMonkey 45 JavaScript, and mawkcc input, allowing each host to
produce a disposable seed without an earlier compiler layer.

The supported target is deliberately limited to 32-bit i386 Linux. The final
compiler provides TCC's i386 code generator, assembler, archive handling, and
ELF linker. It does not use a GNU linker or `libgcc` in the compiler-only
bootstrap paths. `tccrun` and dynamic-loader APIs are outside this bootstrap.

## Compiler Layer

There are no cc0 or cc1 compiler source files or executables. `cc2.c` owns the
operator-free base dialect parser, preprocessing, typed C parser, i386 code
generator, assembler, archive support, ELF linker, diagnostics, and driver.
Its dynamic data structures introduce no additional fixed compiler limits.

The source language is still referred to as the cc0 dialect, but full-compiler
builds now expose its declaration spellings explicitly with `-Dfunction=int`
and `-Dvar=int` rather than relying on the legacy `-std=cc0` shorthand.

The base portions use `function`, `var`, assignments, calls, and primitives
such as `add`, `sub`, `ri32`, and `wi8`. Operators are implemented by host
support during seeding and by compiler builtins after self-hosting. Character
codes use `mkC("x")`; address formation uses `addr(name)`. Every control-flow
body uses braces.

GCC, SpiderMonkey, or mawkcc produces a disposable cc2 seed. The seed builds
every object in canonical generation one; generation one rebuilds every
object and executable as generation two, and the scripts require byte
identity for each pair. No host-built object is retained in `cc2.exe`,
`cc2_static.exe`, or either final TCC.

The first cc2 executable uses `cc2_boot_storage.c` and
`cc2_backend_stubs.c`. Build scripts concatenate `cc2.c` and the boot storage
into an artifact-local translation unit for seed environments without a C
preprocessor. Full cc2 then compiles `tcc_unified.c`, whose typed C bridge is
in `cc2_tcc_prims.c`.

`cc2_runtime.c` provides the i386 arithmetic and floating helpers otherwise
supplied by libgcc. The static chain extends the libc in explicit levels:
the shared C/JavaScript `cc1_libc.c` and typed `cc2_libc.c`.
Native i386 vararg stack-address primitives live separately in
`cc1_libc_asm.c` so the libc source itself remains valid JavaScript.

## Bootstrap Graphs

The shortest dynamic graph is:

```text
GCC, SpiderMonkey, or mawkcc
  -> disposable full cc2 seed
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

The temporary and provisional cc2 executables are links of the same cc2
compiler layer. They are needed to cross typed runtime and floating conversion
dependencies; they do not constitute another source layer.

## JavaScript Seed

Run from the repository root:

```sh
./mk_clean
cd tcc_27_layered_take3
./mk_cc2_js
```

`js` must be SpiderMonkey jsshell 45. The script loads `prims.js`,
`cc1_libc.c`, bootstrap storage, backend stubs, and `cc2.c` directly. It
compiles and links a disposable fully static cc2, then
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
./mk_cc2_mawkcc
```

The required upstream seed is:

```text
../ai_experiments/mawkcc/artifacts/mawkcc.self.exe
```

The script first uses that upstream executable to compile the vendored
`mawkcc_self_bugfix.c` into `artifacts/mawkcc_self_bugfix.exe`. Future
take3-specific mawkcc fixes belong in the vendored source; the upstream
`ai_experiments/mawkcc` tree remains unchanged until those fixes are ready to
be incorporated there.

`mk_cc2_mawkcc` uses `cc1_libc.c` for allocation, strings, streams, and
descriptor buffering; `cc0_mawkcc_compat.c` contains only low-level operations
that mawkcc cannot express. Its disposable mawkcc runner
compiles the existing static startup, syscall, libc, floating-runtime, cc2,
and TCC bridge sources, then links `cc2_mawkcc_static_seed.exe`. The runner
also creates metadata-only `libc.so.6` and `libm.so.6` import objects. A small
cc2-built ELF utility localizes TCC-generated boundary symbols in that
metadata before `mk_cc2_from_seed` performs the normal two-generation static
and dynamic self-host checks. The result is bit-identical to the GCC and
SpiderMonkey routes and requires no host i386 glibc files or library symlinks.

The vendored mawkcc relocation and standalone data-patch arrays grow as
required. `mk_mawkcc_relocation_test` verifies 12,288 entries, above the
10,888 conservative upper bound calculated for cc2.

## GCC Seed

Run from the repository root:

```sh
./mk_clean
cd tcc_27_layered_take3
./mk_cc2_gcc
```

GCC must support `-m32`. It builds only the disposable seed, which builds both
canonical cc2 generations and their static counterparts; no GCC-built object
survives in either published executable.

## Full Builds

After any cc2 seed, continue the dynamic chain with:

```sh
./mk_tcc_layered_via_cc2
```

The static chain is also available after any seed:

```sh
./mk_tcc_layered_via_cc2_static
```

These scripts read only canonical cc2 generation objects. Both build the stock
TCC outputs and verify the immutable `sums_tcc_27` hashes.

Do not run `mk_clean` between the seed and full-chain script. Neither full
chain invokes GCC or a pre-existing TCC. The dynamic chain links against the
versioned i386 `libc.so.6` and `libm.so.6` runtime DSOs so it also works with
older split glibc installations. The static chain has no host runtime
dependency.

The native validation entry point is:

```sh
./mk_tcc_27_layered_take3
```

It starts with `mk_clean`, validates cc2 as GNU89 C, loads the compiler sources
directly in SpiderMonkey, seeds canonical cc2 through JavaScript, verifies two
bit-identical self-host generations, runs the complete dynamic chain, and
checks every fixed stock hash.

## JavaScript Source Test

From this directory:

```sh
./mk_js_layers_test
```

The test loads production `prims.js`, `cc1_libc.c`, bootstrap support, and
`cc2.c` without source rewriting, then exercises representative base, libc,
and typed compiler operations.

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
cc2 never inlines syscalls.

`cc0_static_syscalls.c` implements the low-level file and break operations.
`cc0_static_start.c` provides the minimal libc-test startup.
`linux_i386_start.c`, `cc2_start.c`, and `cc2_static_start.c` provide ordinary
full-compiler i386 startup without a lower-layer entry adapter.
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
- Keep `cc2.c` directly valid SpiderMonkey 45 JavaScript and mawkcc input.
- Keep base-dialect code operator-free and use `mkC` for character codes.
- Do not introduce arbitrary implementation limits.
- Keep all control-flow bodies braced.
- Do not use the discarded `tcc_27_layered` directory as a reference.
- Never change `sums_tcc_27` to accommodate output changes.

## Licensing

This tree is derived from TinyCC 0.9.27. See `COPYING` and `RELICENSING` for
the inherited licensing terms and provenance.
