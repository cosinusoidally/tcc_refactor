Aim of the game here is to provide an "overlay" of source code, scripts in
this directory that allows us to construct an alternative bootstrap path
for tcc_bootstrap_alt (which will be in `../../tcc_bootstrap_alt` relative to
this directory). You must not modify anything in the `tcc_bootstrap_alt` repo
all changes must be applied to this overlay directory.

Look through the `tcc_bootstrap_alt` README you will see that the bootstrap
path is currently:

```
tcc_js->1_7->1_8->1_9->2m->2->3->10->23->24->26->27
```
Our ultimate aim is to arrive at:

```
1_7_alt->10_alt->27
```
but we will likely need an intermediate step of:
```
1_7_alt->10_alt->23_alt->27
```

To test you will need to create alt versions of `mk_from_bootstrap_seed` and
`mk_otccelf` (call these `mk_from_bootstrap_seed_alt` and `mk_otccelf_alt`).
These will live in `tcc_bootstrap_alt_ovelay` and will be called from
`tcc_bootstrap_alt_ovelay`. Other important things to note are:

* `mk_otccelf` is a version that dynamically links to `glibc` it is useful for
  quick development, but everything must also pass with `mk_from_bootstrap_seed`
  (as that version uses its own libc wrappers and can run without glibc)
* `tcc_bootstrap_alt/sum` sha256sums must never change after each run you should
  get bit identical tcc_27 object code
* when running `mk_from_bootstrap_seed` and the alt version, you should get a
  bit identical copy of `tcc_bootstrap_alt/artifacts/tcc_27_boot_static.exe`
  each time.
  You should add a test
  for this.
* `mk_from_bootstrap_seed` is quite verbose so avoid consuming the whole log
  file if you can
* there are several scripts to clean out binary artifacts. `mk_really_clean`
  will clean everything. You should create an equivalent for the overlay.


## Detailed plan

This will be done incrementally. Commit frequently, and only passing code.

We will start by creating a `tcc_23_alt` tree in `tcc_bootstrap_alt_ovelay`.
Initially it will be a straight copy of `tcc_23` from `tcc_bootstrap_alt`.

Do the following:
* `mk_from_bootstrap_seed_alt` and `mk_otccelf_alt` (an an `_alt` clean script
  to clean up binaries).
* Update `mk_from_bootstrap_seed_alt` and `mk_otccelf_alt` so they can build
  the current bootstrap chain using `tcc_23_alt` in place of `tcc_23`
* make sure the tcc_27 builds are still bit identical and match the existing
  hashes (you will need to create a hash for
  `tcc_bootstrap_alt/artifacts/tcc_27_boot_static.exe` and verify that too).
* make sure the tcc_27 builds are still bit identical and match the existing
  hashes.

Important note, within Codex 32 bit code execution may be blocked by the sandbox
. You will need to use `../scripts/run-i386.sh` to run 32 bit code (which can
then be whitelisted once by me.
