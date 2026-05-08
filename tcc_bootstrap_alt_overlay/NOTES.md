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
