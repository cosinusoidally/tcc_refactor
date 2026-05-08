## In Progress

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
