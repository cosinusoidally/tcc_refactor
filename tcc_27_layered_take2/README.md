# TCC 0.9.27 Layered Bootstrap, Take 2

This directory contains the second layered refactor of Tiny C Compiler 0.9.27.
It is a working i386 Linux bootstrap, not a sketch of a future design. The
compiler is built in permanent layers from a small, auditable base dialect up
to the complete TCC frontend, i386 backend, ELF linker, and archive support.

The central property is that the lower compilers are not independent throwaway
implementations. `cc0.c`, `cc1.c`, and `cc2.c` remain linked into the final
layered TCC and provide services used by that final executable.

The inherited file named `README` is the upstream TCC document. This file
describes the layered take2 implementation and its bootstrap paths.

## Status And Contract

The implemented target is deliberately narrow:

- Linux on 32-bit i386 only.
- ELF32 little-endian objects and executables.
- The i386 System V C calling convention at typed-C and libc boundaries.
- Dynamic bootstrap tools using `/lib/ld-linux.so.2`.
- Final runtime dependencies on `libc.so.6` and `libm.so.6`.
- No `libgcc`, GNU linker, GCC CRT, or libc development-file dependency in the
  JavaScript or mawkcc layered bootstrap path.
- No `tccrun` or in-memory execution requirement.

Because in-memory execution is outside the supported target, cc2 contains no
`dlopen`, `dlsym`, or `dlclose` hooks and `tcc_layered.exe` does not depend on
`libdl`. Normal file-output linking is unaffected: TCC parses ELF shared
libraries itself through its `tcc_load_dll` path.

The compatibility contract is the repository-level `sums_tcc_27` file. A
successful full build reproduces all five stock TCC 0.9.27 artifacts without
changing that file:

- `artifacts/libc_boot4.o`
- `artifacts/libc_static.o`
- `artifacts/libtcc1.o`
- `artifacts/tcc.o`
- `artifacts/tcc_27_boot_static.exe`

The canonical `cc0.o`, `cc1_stubs.o`, and `cc0.exe` are byte-identical whether
the initial seed is SpiderMonkey JavaScript or self-hosted mawkcc. The canonical
`tcc_layered.exe` is byte-identical when produced by the native validation
script or by the compiler-only path through `cc0.exe`. Host shared-library
function sizes are deliberately not copied into undefined ELF function imports,
so changing the glibc version does not perturb the executable.

## Layer Model

The bootstrap has three permanent compiler layers. There is no `cc3`.

### cc0

`cc0.c` is the base compiler, object writer, small executable linker, shared
diagnostic implementation, and command-line entry point.

Its source dialect uses:

- `var name;` for globals.
- `function name(args) { ... }` for functions.
- Assignments and calls as the basic expression forms.
- Lowercase primitive calls such as `add`, `sub`, `eq`, `ri32`, and `wi8`
  instead of source-language operators.
- `mkC("x")` for byte-valued character constants.
- Inline `asm` limited to adjacent strings containing `.byte 0xNN` lists.
- Extra worker parameters as local storage where mawkcc has no local-variable
  declaration facility.
- Braces around every control-flow body.

The same `cc0.c` text has three relevant interpretations:

- GNU89 C maps `function` and `var` to `int` and obtains primitives from
  `prims.c` or libc.
- SpiderMonkey jsshell 45 loads the file directly and obtains primitives from
  `prims.js`.
- mawkcc parses the source dialect directly. A seed-only compatibility suffix
  supplies the few runtime spellings not built into mawkcc.

cc0 compiles the base dialect into i386 ELF relocatable objects. Its lower
linker merges those objects and resolves their symbols and relocations. An
object set defining `main` becomes a dynamic ELF image with a process-entry
adapter and direct dependencies on libc, libm, and libdl. A freestanding object
set defining `_start` and containing no unresolved imports becomes a static
ELF image with separate executable and writable load segments. The lower
linker is sufficient for the cc0, cc1, cc2 bootstrap executables and small
static runtime tests; the final compiler uses the full TCC ELF linker in cc2.

`main` is in `cc0.c`. Every layer therefore inherits the same help, usage,
file/line/column diagnostics, compile dispatch, and link dispatch. Higher
layers replace services through ordinary linked definitions rather than
conditional compilation.

### cc1

`cc1.c` adds the source-processing facilities needed to express cc2:

- Token records with source file, offset, line, and column origins.
- Include processing and macro expansion.
- Conditional preprocessing.
- Expression parsing and normalization.
- Scalar type and symbol records.
- Source lowering back into the cc0-compilable representation.
- Error remapping from normalized source to the original input location.

`cc1_stubs.c` lets cc0 stand alone before the real cc1 service is linked.
`cc2_stubs.c` lets cc1 stand alone before cc2 is available. The stubs preserve
the permanent dispatch shape; they do not select a hidden monolithic compiler.

cc1 continues to use cc0's object writer and lower linker. Its purpose is to
make the next source layer expressible, not to duplicate the final TCC backend.

### cc2

`cc2.c` is the full typed-C and TCC layer. It owns the remaining compiler and
toolchain facilities needed by the final executable, including:

- Typed declarations, typedefs, enums, arrays, structs, unions, pointers, and
  function types.
- Integer, long-long, floating-point, and x87 conversions.
- The TCC preprocessor, parser, initializer handling, and i386 code generator.
- Inline and standalone i386 assembly support.
- ELF object, archive, linker-script, and shared-library loading.
- ELF executable and shared-object layout, relocation, PLT, GOT, and dynamic
  symbol handling.
- Static archive creation through `-ar`.
- The final TCC-compatible command-line driver.

`cc2_boot_storage.c` and `cc2_backend_stubs.c` provide temporary representation
and backend services while cc1 is first compiling cc2. They are bootstrap
components, not alternative final compilers.

`cc2_tcc_prims.c` is the typed bridge between migrated cc2 code and the
remaining TCC representation declared through the inherited headers.
`cc2_i386_tables.c` contains immutable i386 data compiled into the typed
remainder. `cc2_runtime.c` supplies the small set of compiler-emitted i386
operations that cannot recursively implement themselves, including 64-bit
shift/division and extended-precision conversion helpers.

## Source Composition

The small unified files make the bootstrap composition explicit:

- `cc2_boot_unified.c` includes `cc2.c` and `cc2_boot_storage.c` so cc1 can
  build the temporary cc2 service in one translation unit.
- `tcc_unified.c` selects i386, includes `tcc.h`, and adds
  `cc2_tcc_prims.c` plus `cc2_i386_tables.c`.
- `tcc_unified_cc0.c` includes `tcc_unified.c` for the root script's cc0
  dialect-entry validation.

The directory still contains inherited TCC headers, tests, documentation, and
build files. Their presence does not imply that each inherited file is a
separate bootstrap component. The scripts listed below define the active
bootstrap graph.

## Bootstrap Sequence

After a seed has produced the canonical dynamic and static cc0 executables,
`mk_tcc_layered_via_cc0` performs this chain. The separate
`mk_tcc_layered_via_cc0_static` chain builds and uses both `cc0_static.exe`
and `cc1_static.exe`; it is kept independent so later static layers can
diverge cleanly.

```text
cc0.exe
  -> cc0.o + cc1.o + cc2_stubs.o
  -> cc1.exe

cc1.exe
  -> cc2_boot_unified.o + cc2.o + cc2_backend_stubs.o
  -> cc2_boot.exe

cc2_boot.exe
  -> tcc_rest.o + cc2_runtime_boot.o

cc0 linker
  -> cc0.o + cc1.o + cc2.o + tcc_rest.o + cc2_runtime_boot.o
  -> cc2.exe

cc2.exe
  -> prims_final.o
  -> cc0_final.o
  -> cc1_final.o
  -> cc2_final.o
  -> cc2_runtime_final.o
  -> tcc_rest_final.o

full cc2/TCC linker
  -> project crt1.o + every final object + libc + libm + libdl
  -> tcc_layered.exe

tcc_layered.exe
  -> stock TCC 0.9.27 compatibility objects and static executable
  -> sums_tcc_27 verification
```

The current static chain diverges through its first two executables:

```text
cc0_static.exe
  -> static runtime objects + cc0.o + cc1.o + cc2_stubs.o
  -> cc1_static.exe

cc1_static.exe
  -> cc2_boot_unified.o + cc2.o + cc2_backend_stubs.o
  -> cc2_boot.exe
```

The transitional `cc2.exe` is linked by cc0 because the full linker is being
brought into executable form at that point. The final `tcc_layered.exe` is
linked by the full TCC linker. It does not depend on a GNU linker.

## Seed Paths

All build products belong in the repository-level `artifacts/` directory.
Run the two-part seed scripts from `tcc_27_layered_take2`, as shown below.

### SpiderMonkey JavaScript Seed

Requirements:

- `js` in `PATH` must be SpiderMonkey jsshell 45 for i686 Linux.
- The shell must be able to execute i386 ELF programs.

From the repository root:

```sh
./mk_clean
cd tcc_27_layered_take2
./mk_cc0_js
```

`mk_cc0_js` loads `prims.js`, `cc0.c`, and `cc1_stubs.c` into JavaScript. The
in-process cc0 compiles its canonical objects and the static runtime, links
`artifacts/cc0_static.exe`, and then links `artifacts/cc0.exe`. It never runs
the dynamically linked executable.

The JavaScript host models integer-addressed memory with a growable typed
array. Compiler policy remains in `cc0.c`; `prims.js` implements only the host
meanings of otherwise inexpressible operations and file/memory services.

### Self-Hosted mawkcc Seed

Requirement:

```text
../ai_experiments/mawkcc/artifacts/mawkcc.self.exe
```

must exist relative to the repository root. It is a statically linked i386
self-hosted mawkcc executable.

From the repository root:

```sh
./mk_clean
cd tcc_27_layered_take2
./mk_cc0_mawkcc
```

The script concatenates these checked-in sources into the generated
`artifacts/cc0_mawkcc.c`:

```text
cc0.c
cc1_stubs.c
cc0_mawkcc_compat.c
```

mawkcc compiles that combined source into the disposable
`artifacts/cc0_mawkcc.exe`. The compatibility suffix contains only the seed's
arena allocation, copying reallocation, and primitive spelling adapters.

`cc0_mawkcc.exe` is not the canonical result. It compiles the unmodified
`cc0.c`, `cc1_stubs.c`, and static runtime, then links
`artifacts/cc0_static.exe` before linking `artifacts/cc0.exe`. It does not run
the dynamically linked executable or rebuild the objects a second time.

### Native Validation Seed

From the repository root:

```sh
./mk_tcc_27_layered_take2
```

This comprehensive script cleans `artifacts/` itself. It requires a host GCC
with working `-m32` support, i386 development CRT objects, libc development
files, and SpiderMonkey jsshell for its cross-check.

The native stages validate that the shared source compiles as GNU89 C, that the
unified compiler can reproduce its own objects, that the explicit cc0 -> cc1
-> cc2 chain works, and that help and source-location diagnostics work. Native
CRT and libgcc inputs are validation-only.

The script's published `tcc_layered.exe` is rebuilt with full cc2 and uses the
same project CRT, final object order, and versioned runtime DSOs as
`mk_tcc_layered_via_cc0`. It is therefore byte-identical to the compiler-only
bootstrap result.

## Full Compiler-Only Build

After either non-native seed, run:

```sh
./mk_clean
cd tcc_27_layered_take2
./mk_cc0_js
./mk_tcc_layered_via_cc0
```

To bootstrap through the statically linked cc0 instead, run:

```sh
./mk_clean
cd tcc_27_layered_take2
./mk_cc0_js
./mk_tcc_layered_via_cc0_static
```

or:

```sh
./mk_clean
cd tcc_27_layered_take2
./mk_cc0_mawkcc
./mk_tcc_layered_via_cc0
```

Do not run `mk_clean` between a seed script and either full-chain script. The
dynamic chain consumes `artifacts/cc0.exe`; the static chain consumes
`artifacts/cc0_static.exe`. Neither seed script cleans artifacts itself.

Neither full-chain script invokes GCC or a pre-existing TCC. The static-seed
chain is static through cc1, but cc2 and its upper layers are not static yet,
so both chains currently need the same versioned i386 runtime shared objects.
They search these directories in order:

```text
/lib/i386-linux-gnu
/usr/lib/i386-linux-gnu
```

The required files are:

```text
libc.so.6
libm.so.6
```

The explicit libm and libdl dependencies are intentional. Older glibc releases
such as Ubuntu Bionic keep those facilities in separate shared libraries,
whereas newer releases have merged many of their symbols into libc.

The full build also uses the repository sibling header tree:

```text
../tcc_bootstrap_alt/woody/usr/include
```

All bootstrap compile commands use `-nostdinc` with explicit include paths so
they do not scan or silently depend on host headers. `-nostdinc` is not the
compiler default for normal user invocations.

## CRT And Runtime

`crt1.c` is the project process-startup source. cc0 recognizes the specifically
named `_start` function and emits the small i386 stack adapter that presents
the kernel's initial stack as ordinary `(argc, argv)` C arguments. The source
body calls `main` and then glibc `exit`.

The JavaScript-generated cc0 lower linker is the irreducible base case and
generates its own entry adapter. Once canonical cc0 exists, `crt1.c` is
compiled by cc0 and used by the full linker for `tcc_layered.exe`.

`cc2_runtime.c` replaces compiler helper dependencies that would otherwise be
provided by libgcc. It implements those operations from explicit 32-bit words
and the i386 x87 extended representation. The layered bootstrap never links
`libgcc_s.so.1` or a static `libgcc.a` into its canonical result.

The developing static cc0 runtime is kept in replaceable layers:

- `linux_i386_syscalls.c` contains the `.byte` implementation of the single
  five-argument `int 0x80` entry.
- `cc0_static_syscalls.c` implements private open, read, write, close, brk, and
  exit runtime operations in terms of that entry.
- `cc0_dynamic_syscalls.c` adapts the same operations to glibc.
- `cc0_static_start.c` supplies the initial freestanding `_start` policy.
- `cc0_libc.c` contains environment-neutral libc functions. String length,
  `puts`, `write`, `open`, `exit`, and a monotonic `brk`-backed `malloc` work
  now. `realloc` grows those allocations while preserving their contents, and
  `close` completes the file-descriptor surface needed by cc0.

`mk_libc_test` compiles each matrix entry's `cc0_libc.o` and
`hello_world_test.o` once and feeds those exact objects to both its static and
dynamic links. The JavaScript and mawkcc compiler seeds use that runtime to
emit the fully static `cc0_static.exe` without running dynamic cc0.

The static allocator remains based on `brk`. It reserves break space in 4 KiB
growth quanta and serves allocations from a bump cursor, while allowing
allocations larger than a quantum to extend to their required end.
Seekable input descriptors have dynamically allocated 64 KiB read caches so
the compiler does not issue one raw syscall per source byte. Non-seekable
descriptors bypass the cache, and `lseek`, `write`, and `close` reconcile or
discard cached state as required. Descriptors opened writable through
`cc0_libc` also receive dynamically allocated 64 KiB output buffers, avoiding
one raw syscall per emitted object byte. Reads, seeks, closes, and process
shutdown flush pending output; descriptors not opened through the wrapper,
including standard output and standard error, retain direct-write behavior.

## Important Artifacts

The bootstrap may create these files under `artifacts/`:

| Artifact | Purpose |
| --- | --- |
| `cc0_mawkcc.c` | Generated mawkcc-compatible seed translation unit. |
| `cc0_mawkcc.exe` | Disposable compiler seed produced by mawkcc. |
| `cc0.exe` | Canonical self-hosted base compiler and lower linker. |
| `cc0_static.exe` | Canonical statically linked base compiler. |
| `cc1.exe` | Preprocessing and scalar-source layer. |
| `cc2_boot.exe` | Transitional typed layer with bootstrap services. |
| `cc2.exe` | Full typed TCC compiler used for the final rebuild. |
| `tcc_layered.exe` | Canonical final layered TCC executable. |
| `tcc_27_boot_static.exe` | Stock compatibility executable covered by `sums_tcc_27`. |
| `syscall_test/` | GCC, TCC, mixed cc0, and cc0-self raw-syscall tests. |
| `libc_test/` | Matching static/dynamic libc tests across the same matrix. |
| `libc_cc0_test/` | Static/dynamic libc smoke and cc0 compiler executables. |

Names ending in `_boot.o` or `_final.o` make the producing stage explicit.
Generated source and binaries must not be added to this directory.

## Verification

The main verification command is:

```sh
./mk_tcc_27_layered_take2
```

It checks, among other things:

- GNU89 C compilation of the cc0/cc1/cc2 sources.
- Repeated full-compiler object identity.
- `-std=cc0` equivalence for cc0 source.
- Consecutive `cc0.o` and `cc1_stubs.o` self-host identity.
- cc1 and cc2 smoke compilation.
- Help output from cc0, cc1, and cc2.
- File, line, and column information for intentional errors.
- SpiderMonkey reproduction of canonical cc0 objects and executable.
- Full stock TCC compatibility hashes.

For a cross-seed cc0 comparison:

```sh
./mk_clean
cd tcc_27_layered_take2
./mk_cc0_mawkcc
cp ../artifacts/cc0.exe /tmp/cc0.mawkcc.exe
cd ..
./mk_clean
cd tcc_27_layered_take2
./mk_cc0_js
cmp /tmp/cc0.mawkcc.exe ../artifacts/cc0.exe
```

For the strongest non-native test, build cc0 from either seed and then run the
entire compiler-only chain through `mk_tcc_layered_via_cc0`.

The focused freestanding tests are run from this directory after cleaning:

```sh
./mk_syscall_test
./mk_libc_test
./mk_libc_cc0_test
```

These scripts build missing compiler prerequisites automatically. The libc test
produces static and glibc-linked hello executables for GCC, layered TCC, the
stock static bootstrap TCC, mixed cc0, and cc0-self object paths. Every pair
must print identical output; the script also checks that static images have no
interpreter and dynamic images have both an interpreter and a needed DSO.

`mk_libc_cc0_test` links the canonical `cc0.o` and `cc1_stubs.o` against the
cc0-built runtime objects. Before that compiler check, it builds static and
dynamic copies of `tests/layered/libc_smoke.c` against the same runtime. The
smoke test checks `argc`/`argv`, writable aligned `malloc` allocations,
`open`/`read`/`lseek`/`close`, and direct `write` plus `puts` output. It must
succeed identically in both modes.
The retained `cc0_static.exe` and `cc0_dynamic.exe` compile the smoke source as
their probe; both compilations must succeed and produce byte-identical objects.
Static cc0 then compiles canonical `cc1.o` and `cc2_stubs.o`. Those same
objects are linked into `cc1_static.exe` and `cc1_dynamic.exe`; both cc1 images
must compile the smoke source byte-identically, and their ELF interpreter state
must match their declared link mode.
The static compiler then recompiles every source and object needed for itself,
links `cc0_static_self/cc0_static.exe`, and requires the rebuilt objects and
executable to be byte-identical. The rebuilt executable performs one more
`cc0.c` compilation to close the self-hosting loop.

When testing either seed script, clean first. This prevents an old canonical
object from hiding a failed seed build.

## Development Rules

The detailed repository-local rules are in `AGENTS.md`. The most important
constraints are:

- Modify layered compiler code only in this directory and the permitted root
  build script.
- Keep every build product in `artifacts/`.
- Do not use `tcc_27_layered` as a reference implementation.
- Do not change `sums_tcc_27` to accommodate compiler output changes.
- Do not add target abstraction for architectures other than i386 Linux.
- Do not introduce fixed compiler capacities or other implementation limits
  absent from TCC; storage must grow dynamically.
- Keep cc0 operator-free and use lowercase primitive calls.
- Keep all control-flow bodies braced.
- Initialize cc0 global constants through initialization functions rather than
  at declaration sites.
- Keep low-level host support in `prims.c`, `prims.js`, or a seed-only
  compatibility file; compiler policy belongs in the permanent layers.
- Keep the full TCC linker responsible for the final layered executable.
- Verify the standard build and the relevant non-native seed before every
  commit that changes a bootstrap path.

## Scope Boundaries

This project is not trying to make TCC portable to every host during the
bootstrap. It intentionally assumes i386 Linux process, ELF, and dynamic-loader
semantics. Portability mechanisms that obscure those assumptions make the
bootstrap harder to audit and are out of scope.

The project also does not treat the mawkcc compatibility suffix as another
compiler layer. It is a host adapter for producing the first executable. The
canonical cc0 immediately recompiles the shared source without that suffix,
and every later executable is built from the permanent layered sources.

## Licensing

This tree is derived from TinyCC 0.9.27. See `COPYING` for the inherited GNU
Lesser General Public License 2.1 terms and `RELICENSING` for TinyCC's ongoing
relicensing record. Source provenance and copyright notices in inherited files
remain authoritative for those files.
