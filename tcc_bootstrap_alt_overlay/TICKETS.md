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
Status: in progress
Task: Make `tcc_23_alt` buildable by `tcc_3` and start removing `tcc_10` from the alternate bootstrap chain.
Start: 2026-05-08 15:11:00Z
End:
Notes: Added `mk_tcc3_tcc23_alt_probe` as the dedicated Phase 1 entrypoint for the `tcc_3 -> tcc_23_alt` jump and flattened the initial i386-only preprocessor branches in `tcc_23_alt`. The probe now succeeds: `tcc_3` can JIT-run `tcc_23_alt` help text. Added `mk_tcc3_tcc23_alt` for the next passing milestone: build temporary `tcc_3/a.out` with `gcc -m32`, use it to JIT `tcc_23_alt` and compile `libtcc1.o` and `tcc.o`, link those into `tcc_23/a.out`, and verify the resulting `tcc_23` binary runs under `scripts/run-i386.sh`. Next step is to extend that `tcc_23` result onward to `tcc_24` and start replacing the `tcc_10 -> tcc_23` section of the main alternate scripts.

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
