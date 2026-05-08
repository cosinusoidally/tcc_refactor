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
- The seeded/static alt workspace path was validated by running the copied
  workspace through `./kaem.x86`, then checking:
  `sha256sum -c sum`
  and
  `./mk_verify_tcc_27_boot_static <workspace>`.
- The `otccelf` alt workspace path also needs the wrapper for
  `otccelf/mk_elf_loader`, because that script executes generated 32-bit tools.
