# Phase 1 Notes

- The overlay must not modify `../../tcc_bootstrap_alt`; checksum fixtures and verification scripts need to live here.
- The baseline static artifact target is `../../tcc_bootstrap_alt/artifacts/tcc_27_boot_static.exe`.
- The baseline full static path is driven by `../../tcc_bootstrap_alt/kaem.x86`, which runs `after.kaem` and ends in `tcc_27/run_27_static.kaem`.
- The alternate shell entrypoint `../../tcc_bootstrap_alt/alt_kaem.x86` only reaches the `tcc_js` leg via `alt_after.kaem`; it does not produce the final static `tcc_27` artifact.
- In this environment, the seeded i386 stages must be launched through the approved `scripts/run-i386.sh` wrapper from the `tcc_refactor` repo root.
- Frozen Phase 1 static artifact checksum:
  `68339f674652b934929568b613a74f75668d3fee6664b4d528781d764f5e7750  tcc_27_boot_static.exe`
- Re-running the final static stage with
  `scripts/run-i386.sh /bin/sh -c 'cd /home/foo/src/gpt/tcc_bootstrap_alt && ./x86/bin/cdrun ./tcc_27/ ../x86/artifact/kaem-0 ./run_27_static.kaem'`
  reproduced the same checksum.
- The simplest non-invasive overlay mechanism for Phase 1 is a throwaway copy of
  `../../tcc_bootstrap_alt` under `tcc_bootstrap_alt_overlay/_alt_work/`, with
  workspace `tcc_23/` replaced by overlay `tcc_23_alt/`.
- `mk_from_bootstrap_seed_alt` and `mk_otccelf_alt` are implemented in terms of
  that throwaway workspace. They do not modify the upstream checkout.
- The main `_alt` entrypoints are again the full upstream bootstrap chain with
  only `tcc_23/` overlaid:
  `mk_otccelf_alt` runs
  `x86/artifact/kaem-optional-seed ./alt_kaem.x86`
  then `otccelf/mk_elf_loader`,
  and `mk_from_bootstrap_seed_alt` runs the copied workspace
  `x86/artifact/kaem-optional-seed`.
- On the current branch tip, both restored full-chain entrypoints are passing
  again:
  `mk_otccelf_alt` passes `sha256sum -c sum`,
  and `mk_from_bootstrap_seed_alt` passes both
  `sha256sum -c sum`
  and
  `mk_verify_tcc_27_boot_static`.
- The earlier host-linked `mk_tcc3_chain_workspace_alt` approach was the wrong
  architecture for Phase 1 and has been removed.
- The current Phase 1 direction is a workspace-local kaem path:
  `phase1_kaem.x86` -> `phase1_after.kaem` -> `tcc_js/build_phase1.kaem`
  -> `tcc_23/build_phase1.kaem` -> later stage scripts.
- `mk_prepare_workspace_alt` now removes `tcc_10` from `_alt_work` entirely and
  injects overlay-local replacement files, including `phase1_support/`.
- `tcc_js/build_phase1.kaem` now builds local `tcc_boot.o`, copies it into
  `tcc_23/tcc_boot.o`, and then builds `loader_cc_x86.exe` and
  `elf_loader_cc_x86.exe`.
- `mk_from_bootstrap_seed_alt` and `mk_otccelf_alt` both now invoke the new
  kaem path instead of any host-built `gcc`/glibc `tcc_3` helper.
- The dedicated Phase 1 `tcc_3 -> tcc_23_alt` probe is
  `tcc_bootstrap_alt_overlay/mk_tcc3_tcc23_alt_probe`.
- That probe currently works by:
  `mk_prepare_workspace_alt`
  then building `tcc_3/a.out` in the throwaway workspace with
  `gcc -m32 -D__thread=__threadp`
  then JIT-running `../tcc_3/a.out tcc.c -h` inside workspace `tcc_23/`
  through `scripts/run-i386.sh`.
- For the current refactor pass, `tcc_23_alt` can be treated as i386-only.
  The compatibility work is therefore allowed to collapse target-selection
  preprocessor branches down to their i386 paths instead of preserving ARM/C67.
- The next passing milestone script is
  `tcc_bootstrap_alt_overlay/mk_tcc3_tcc23_alt`.
- That script currently proves:
  `gcc -m32` can build a temporary `tcc_3/a.out`,
  `tcc_3` can JIT-run `tcc_23_alt` to compile `libtcc1.o` and `tcc.o`,
  and those objects can be linked into a runnable `tcc_23/a.out`.
- The next extension script is
  `tcc_bootstrap_alt_overlay/mk_tcc3_tcc24_alt`.
- That script currently proves the `tcc_3`-bootstrapped `tcc_23/a.out`
  can compile `tcc_24/tcc.o` and `tcc_24/libtcc1.o`, and that those objects
  link into a runnable `tcc_24/a.out`.
- The earlier `invalid option -- '%s'` failure was a command-shape bug in
  `tcc_23/build_phase1.kaem`; that is fixed.
- `loader_cc_x86.exe ... tcc.c -h` returning status `1` is not by itself a
  bootstrap failure. The host-linked control path
  `../tcc_3/a.out tcc.c -h` prints help text and also exits with status `1`.
- The reduced `mk_3`-style suffix without the two `-DNO_LONG_LONG`
  `tcc_3/tcc.c` stages was a regression for the loader path. It caused
  `tcc_2` to fail while compiling `tcc_3` with `integer constant overflow`.
- Restoring the original loader staging (`-DNO_LONG_LONG`, `-DNO_LONG_LONG`,
  then three plain `tcc_3/tcc.c` stages before `tcc_23`) gets the in-memory
  bootstrap back to the actual `tcc_23` source.
- The next real blocker was the loader runtime's broken decimal-float parsing.
  `tcc_23_alt/tcc.c` previously pulled in `<math.h>`, which caused the loader
  path to spam `strtod_tramp called` on glibc math constants and abort before
  getting through `tcc.c`.
- The current Phase 1 `tcc_23_alt/tcc.c` now avoids `<math.h>`, declares
  `ldexp()` directly, and removes the `do_bench` decimal-float literals so the
  source only retains the existing special `4294967296.0` literal.
- Those changes move the short `mk_otccelf_alt` lane materially forward: the
  loader path now gets through `tcc.c`, `i386-gen.c`, `i386-asm.c`, and
  `tccasm.c`, then enters `tccelf.c`.
- `tcc_23_alt/tccelf.c` has now been flattened to the i386/Linux path, and
  `tcc_23_alt/elf.h` no longer includes glibc `inttypes.h`/`stdint.h`.
- The first concrete `tccelf.c` incompatibility is in
  `tcc_load_object_file()`, at the top of the symbol-resolution loop:
  the direct `sym->st_shndx` tests plus `sm = &sm_table[sym->st_shndx]`
  prevent the loader-driven `tcc_3` path from getting through the file.
- Rewriting that loop in `_alt_work` to use an explicit `shndx` temporary and
  `sm = sm_table + shndx` moves the compile past `tccelf.c`; a bogus include
  marker after `#include "tccelf.c"` then fires, which did not happen before.
- With that temporary loop simplification in place, the loader-driven compile
  can also be shown to reach the `tcc_output_file()` call site in `main()`.
- The current blocker is now later than `tccelf.c`, somewhere in the remaining
  tail of `tcc.c` between the end of `#include "tccelf.c"` and the final
  object-output path.
- The next debugging direction is no longer to replace `tcc_10` immediately.
  The full `tcc_10 -> ... -> tcc_27` chain stays as the acceptance path while
  ELF object creation is backported into `tcc_3` as a sidecar effort.
- For that sidecar work, the overlay now includes host-build helpers:
  `mk_gcc_tcc3_host_alt` builds a GCC-linked `tcc_3`,
  `mk_gcc_tcc10_host_alt` builds a GCC-linked `tcc_10`,
  and `tcc_10_host_strtod.c` provides the host-side `strtod` shim needed to
  compile `tcc_10` outside the bootstrap chain.
- On the current local Phase 1 branch state, `mk_prepare_workspace_alt`
  overlays all of:
  `tcc_3_alt -> _alt_work/.../tcc_3`,
  `tcc_10_alt -> _alt_work/.../tcc_10`,
  and
  `tcc_23_alt -> _alt_work/.../tcc_23`.
- `tcc_10_alt` is intentionally narrow. It currently only carries
  Phase 1 compatibility edits needed for `tcc_3_alt` to compile the live
  `tcc_10` stage:
  a fallback `#define CONFIG_TCC_PREFIX "/usr"`
  and a temporary `sig_error()` simplification on i386.
- As of 2026-05-14, both accepted `_alt` entrypoints still pass with those
  overlays in place:
  `mk_otccelf_alt` passes the workspace `sum` check,
  and
  `mk_from_bootstrap_seed_alt` passes both the workspace `sum` check and
  `mk_verify_tcc_27_boot_static`.
- The host-side control comparison also clarified the current object-writer
  split in `tcc_3_alt`:
  the newer experimental writer is only enabled for the true `tcc_3/tcc.o`
  handoff path,
  while generic `-c` outputs still use the older writer and therefore emit
  large numbers of unused undefined externs from headers.
- That means the remaining Phase 1 work should stay focused on the real
  `tcc_3.o` -> loader -> `tcc_23_alt` handoff path, not on making the generic
  fallback writer produce tidy host-side objects yet.
