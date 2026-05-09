## In Progress

### Ticket 3
Status: done
Task: Isolate and backport the `tcc_23_alt` fix for non-deterministic `tcc_24` output hashes.
Start: 2026-05-08 11:47:29Z
End: 2026-05-08 14:58:00Z
Notes: Reproduced the drift with repeated `otccelf` rebuilds and narrowed it to `tcc_23/tcc.o`, with `tcc_24/tcc.o` only changing downstream. The root cause was non-deterministic i386 `long double` constant emission in `tcc.c`: one path copied raw `vtop->c.tab` bytes into `.data`, and another stored `long double` initializers without clearing the destination first. Fixed both sites in `tcc_23_alt/tcc.c`. Verified three consecutive `otccelf` rebuilds now produce identical `tcc_23/tcc.o` and `tcc_24/tcc.o` hashes, and reran `mk_otccelf_alt` successfully with the workspace `sum` check passing.

### Ticket 4
Status: done
Task: Revalidate the seeded/static `_alt` lane after the deterministic `tcc_23_alt` fix, then continue the next Phase 1 bootstrap reduction step.
Start: 2026-05-08 14:58:00Z
End: 2026-05-08 15:11:00Z
Notes: Reran `mk_from_bootstrap_seed_alt` to completion after the `tcc_23_alt` determinism fixes. The workspace `sha256sum -c sum` check passed, and `mk_verify_tcc_27_boot_static` confirmed the rebuilt `artifacts/tcc_27_boot_static.exe` still matches the overlay checksum fixture.

### Ticket 5
Status: done
Task: Make `tcc_23_alt` buildable by `tcc_3` and start removing `tcc_10` from the alternate bootstrap chain.
Start: 2026-05-08 15:11:00Z
End: 2026-05-08 17:42:00Z
Notes: Added `mk_tcc3_tcc23_alt_probe` as the dedicated Phase 1 entrypoint for the `tcc_3 -> tcc_23_alt` jump and flattened the initial i386-only preprocessor branches in `tcc_23_alt` and `tccelf.c`. The probe now succeeds: `tcc_3` can JIT-run `tcc_23_alt` help text. Added `mk_tcc3_tcc23_alt` for the first passing milestone: build temporary `tcc_3/a.out` with `gcc -m32`, use it to JIT `tcc_23_alt` and compile `libtcc1.o` and `tcc.o`, link those into `tcc_23/a.out`, and verify the resulting `tcc_23` binary runs under `scripts/run-i386.sh`. Extended the same direct path one step further to a runnable `tcc_24`, then added `mk_tcc3_chain_workspace_alt` to carry the glibc-linked compiler chain through `tcc_26` and `tcc_27` without any `tcc_10` compiler step. `mk_otccelf_alt` now runs `alt_kaem.x86` only for the `tcc_js` leg and then switches to the direct `tcc_3 -> tcc_23 -> tcc_24 -> tcc_26 -> tcc_27` climb; `mk_from_bootstrap_seed_alt` now runs only the seed and mescc bootstrap phases before the same direct climb with static output enabled. Wrapped smoke tests of both main `_alt` entrypoints now pass, with `sha256sum -c sum` succeeding in both lanes and `mk_verify_tcc_27_boot_static` succeeding in the seeded/static lane. The remaining caveat is that the static leg still prints `libc_boot4_new.o: error: '_sys_call3' defined twice` even though the command returns success and the final static artifact checksum still matches the frozen overlay fixture.

### Ticket 6
Status: in progress
Task: Replace the incorrect host-linked Phase 1 `_alt` handoff with a workspace-local kaem path that removes `tcc_10` entirely.
Start: 2026-05-08 18:40:00Z
End:
Notes: Reworked the Phase 1 direction so `mk_from_bootstrap_seed_alt` and `mk_otccelf_alt` no longer call the removed host-linked `mk_tcc3_chain_workspace_alt`. Added checked-in phase files `phase1_kaem.x86`, `phase1_after.kaem`, `tcc_js/build_phase1.kaem`, `tcc_23/build_phase1.kaem`, `tcc_23/run_23_phase1.kaem`, and `tcc_26/run_26_phase1.kaem`, plus overlay-local support copies of `tcc_dummy_strtod.c`, `libc_boot2.c`, and `libc_boot3.c`. Updated `mk_prepare_workspace_alt` so `_alt_work` removes `tcc_10` entirely and injects the Phase 1 replacement files instead. The new path successfully builds through the seed and `tcc_js` stages, builds `loader_cc_x86.exe` and `elf_loader_cc_x86.exe`, copies the generated `tcc_boot.o` into `tcc_23/`, and reaches the intended `tcc_3 -> tcc_23_alt` bootstrap boundary. The original `invalid option -- '%s'` failure was fixed by correcting the final-stage command shape, and a follow-up host-linked control run showed that `loader_cc_x86.exe ... tcc.c -h` exiting with status `1` is normal for this compiler family. Restoring the original loader-side `tcc_3` staging with the two `-DNO_LONG_LONG` steps removed the `integer constant overflow` regression introduced by the shorter suffix. From there I narrowed a real loader-only source issue: `tcc_23_alt/tcc.c` was pulling in `<math.h>`, which forced the broken loader `strtod` stub through glibc decimal float constants and aborted the bootstrap before `tcc_23` finished parsing its own source. `tcc_23_alt/tcc.c` now avoids `<math.h>`, declares `ldexp()` directly, and removes the `do_bench` decimal-float literals. I also flattened `tcc_23_alt/tccelf.c` to the i386/Linux path and made `tcc_23_alt/elf.h` self-contained so it no longer includes glibc `inttypes.h`/`stdint.h`. The next narrowing step found a real `tccelf.c` compatibility issue in `tcc_load_object_file()`: the top of the symbol-resolution loop (`sym->st_shndx` checks plus `sm = &sm_table[sym->st_shndx]`) prevents the loader-driven `tcc_3` path from getting past `tccelf.c`, even though host-linked `tcc_3` accepts it. Rewriting that loop to use an explicit `shndx` temporary and `sm_table + shndx` moves the in-memory compile materially forward: with the temporary patch in `_alt_work`, the probe reaches the post-`tccelf.c` portion of `tcc.c` and can be shown to get at least as far as the `tcc_output_file()` call site in `main()`. The current blocker is now later than `tccelf.c`; the next task is to isolate the next `tcc.c` construct that still makes the loader-driven `tcc_3 -> tcc_23_alt` handoff return non-zero.

### Ticket 2
Status: done
Task: Create the initial Phase 1 alternate workspace path with `tcc_23_alt` and `_alt` bootstrap entrypoints.
Start: 2026-05-08 11:37:42Z
End: 2026-05-08 11:47:29Z
Notes: Added throwaway-workspace helpers plus `_alt` entrypoints for the seeded and `otccelf` paths. Verified the `otccelf` lane with the overlay `tcc_23_alt`, and verified the seeded/static lane produced `tcc_27` object hashes matching `sum` plus a `tcc_27_boot_static.exe` matching the overlay-local checksum fixture.

## Done

### Ticket 1
Status: done
Task: Establish Phase 1 overlay scaffolding and static artifact checksum verification.
Start: 2026-05-08 11:27:10Z
End: 2026-05-08 11:37:42Z
Notes: Added an overlay-local SHA-256 fixture for `../../tcc_bootstrap_alt/artifacts/tcc_27_boot_static.exe`, added a verifier helper, and confirmed the checksum survives a wrapped rerun of `tcc_27/run_27_static.kaem`.
