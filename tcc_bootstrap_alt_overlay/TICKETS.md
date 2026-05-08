## In Progress

### Ticket 2
Status: in progress
Task: Create the initial Phase 1 alternate workspace path with `tcc_23_alt` and `_alt` bootstrap entrypoints.
Start: 2026-05-08 11:37:42Z
End:
Notes: Build in a throwaway workspace copied from `../../tcc_bootstrap_alt`, replace workspace `tcc_23` with overlay `tcc_23_alt`, and verify the final static artifact against the overlay-local checksum fixture.

## Done

### Ticket 1
Status: done
Task: Establish Phase 1 overlay scaffolding and static artifact checksum verification.
Start: 2026-05-08 11:27:10Z
End: 2026-05-08 11:37:42Z
Notes: Added an overlay-local SHA-256 fixture for `../../tcc_bootstrap_alt/artifacts/tcc_27_boot_static.exe`, added a verifier helper, and confirmed the checksum survives a wrapped rerun of `tcc_27/run_27_static.kaem`.
