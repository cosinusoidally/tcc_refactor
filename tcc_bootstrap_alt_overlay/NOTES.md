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
