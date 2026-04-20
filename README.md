# tcc_refactor

This repository is an experiment in refactoring TinyCC into a layered,
self-hosting bootstrap path.

The current tree keeps two TCC source layouts:

- `tcc_27/`: the baseline TinyCC 0.9.27 source tree used for comparison.
- `tcc_27_layered/`: the refactored source tree being shaped into a layered
  bootstrap.

The goal is to keep the bootstrap chain within one understandable codebase
rather than relying on a sequence of throwaway compilers. See
`layered_bootstrap.txt` for the design sketch behind that direction. Current
implementation notes are tracked in `docs/layered-status.md` and
`docs/layers.md`.

## Repository Layout

- `mk_tcc_27_layered`: build and verify the layered TCC experiment.
- `mk_coverage`: build the layered TCC with GCC coverage instrumentation and
  generate an HTML coverage report.
- `mk_clean`: reset `artifacts/` to a clean placeholder state.
- `sums_tcc_27`: expected hashes for outputs produced during verification.
- `artifacts/`: generated build outputs. Only `artifacts/placeholder` is meant
  to be tracked.

## Requirements

The scripts assume a Linux-like environment with:

- `gcc` with 32-bit build support (`-m32`)
- `diff`
- `sha256sum`
- `gcovr` and `firefox` for `mk_coverage`

`mk_tcc_27_layered` also references the sibling checkout
`../tcc_bootstrap_alt/woody/usr/include/` for bootstrap headers.

## Build

From the repository root:

```sh
./mk_tcc_27_layered
```

The build script:

1. Cleans `artifacts/`.
2. Builds `tcc_27_layered` with GCC.
3. Rebuilds `tcc_27_layered` with the GCC-built binary.
4. Rebuilds it a second time with the self-built binary.
5. Compares the two self-built object files.
6. Uses the layered compiler's `-ar` mode to create `libtcc1.a`.
7. Builds and starts a glibc-linked `tcc_27_layered` executable.
8. Smoke-tests `-nostdinc`.
9. Checks that `cc0.c`, `cc1.c`, and `cc0_unified.c` remain valid in the
   staged C and JavaScript dialects.
10. Builds selected baseline `tcc_27` files with the layered compiler.
11. Builds and starts a glibc-linked baseline `tcc_27` executable.
12. Checks the generated hash fixtures against `sums_tcc_27`.

## Coverage

To generate a coverage report for the layered compiler build path:

```sh
./mk_coverage
```

The report is written under `artifacts/` and opened as
`artifacts/example.html`.

## Clean

```sh
./mk_clean
```

This removes generated artifacts and recreates `artifacts/placeholder`.
