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
End: 2026-05-09 08:54:00Z
Notes: This direction was explored far enough to narrow real loader-driven `tcc_23_alt` incompatibilities, including the `tcc_load_object_file()` symbol-loop issue in `tccelf.c`, but it is no longer the main Phase 1 path. The full-chain `_alt` bootstrap was restored instead so the accepted baseline again includes `tcc_10` and reaches `tcc_27`.

### Ticket 7
Status: in progress
Task: Keep the full `_alt` bootstrap chain passing while backporting ELF object creation into `tcc_3` as a sidecar debugging path.
Start: 2026-05-09 08:54:00Z
End:
Notes: Restored `mk_prepare_workspace_alt`, `mk_otccelf_alt`, and `mk_from_bootstrap_seed_alt` to the last known-good full-chain behavior, then later reintroduced `tcc_3_alt` into the live workspace swap while keeping both entrypoints green. `mk_prepare_workspace_alt` now overlays `tcc_3_alt`, `tcc_23_alt`, and a narrow `tcc_10_alt` compatibility layer into `_alt_work`; `mk_otccelf_alt` now invokes `otccelf/mk_elf_loader` through `bash` because that helper uses `pushd`. Revalidated both entrypoints on 2026-05-14 after these compatibility changes: `mk_otccelf_alt` passes `sha256sum -c sum`, and `mk_from_bootstrap_seed_alt` passes both `sha256sum -c sum` and `mk_verify_tcc_27_boot_static`. Added host-build helpers `mk_gcc_tcc3_host_alt` and `mk_gcc_tcc10_host_alt` plus `tcc_10_host_strtod.c`; these build GCC-linked debug executables for `tcc_3` and `tcc_10` inside the ignored `_alt_work/host_debug/` area without changing the accepted bootstrap chain. The current sidecar object path is still in progress: the improved writer is only enabled for the real `tcc_3/tcc.o` handoff, while generic `-c` output still falls back to the older writer and emits a much noisier undefined-symbol surface. The next task is to finish the `tcc_3.o` handoff so `tcc_3_alt` can be loaded from an ELF object and drive the `tcc_23_alt` build, then replace the current JIT-only `tcc_3_alt` role in the accepted Phase 1 chain.

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
