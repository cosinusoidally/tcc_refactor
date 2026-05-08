# tcc_bootstrap_alt_ovelay plan

Aim of the game here is to provide an "overlay" of source code / scripts in
this directory that allows us to construct an alternative bootstrap path
for tcc_bootstrap_alt (which will be in `../../tcc_bootstrap_alt` relative to
this directory). You must not modify anything in the `tcc_bootstrap_alt` repo
all changes must be applied to this overlay directory.

Look through the `tcc_bootstrap_alt` README you will see that the bootstrap
path is currently:

```
tcc_js->1_7->1_8->1_9->2m->2->3->10->23->24->26->27
```
Our ultimate aim is to arrive at a shorter bootstrap path such as:

```
1_7_alt->10_alt->27
```
(where 1_7_alt will also be valid JS, if function was defined as int and
var was defined as int)
but we will likely need an intermediate steps like:
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

# Detailed plan

## Phase 1

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

Next you will notice that there is a non-deterministic compilation issue with
tcc_23_alt. Each time it builds tcc_24 the hashes are different. I think
this is due to some bug in tcc_23 where some data is not being correctly
initialised. This issue is fixed in tcc_24, so you should be able to back port
it. This is the first issue to fix.

Next fix tcc_23_alt so it can be compiled by tcc_3. You will likely need to
remove some preprocessor usage from tcc_23_alt. You should then eliminate the
use of tcc_10.

Next back port ELF output to tcc_3 from tcc_10. Create a tcc_3_alt source tree
for this and wire that into the `_alt` build paths.

At every stage you must retain the ability to compile C code with gcc and a
stock tcc_27. For testing create yourself a glibc linked tcc_27 binary by
linking `tcc_27/tcc.o` and `tcc_27/libtcc1.o` into a tcc_27_glibc.exe binary,
you can generate that binary once (via a checked in script, and place it in
`../../tcc_bin`). For gcc you must use `-m32`.

At this stage the bootstrap chain should look like:

```
tcc_js->1_7->1_8->1_9->2m->2->3_alt->23_alt->24->26->27
```
and `3_alt` will be emitting elf object code files rather than running code
from memory.

## Phase 2

Eliminate `tcc_24`. This will require backporting features from `tcc_24` to
`tcc_23_alt` until it is capable of compiling `tcc_26`.

## Phase 3

Eliminate `tcc_26` by backporting features from `tcc_26` until it is capable
of compiling `tcc_27`.

## Phase 4

Eliminate `tcc_2`. This will mean `tcc_3_alt` will have to be able to be built
in an integer only mode.

## Phase 5

Port `tcc_3_alt` to the dialect of C that is implemented by `tcc_1_7`

## Phase 6

At this point the bootstrap chain should look like this:
```
tcc_js->1_7->3_alt->23_alt->27
```

The next step should be to port `tcc_3_alt` to the dialect of C that is
supported by `tcc_js` this should eliminate `tcc_1_7`.

## Phase 7

Port `tcc_3_alt` to the `tcc_js` subset of JS. This should allow it to be used
as an alternative to `tcc_js` (and should also allow it to be run in a JS vm)

After this the bootstrap path will look like:

```
3_alt->23_alt->27
```

Note at this point `tcc_3_alt` will need to be buildable by `cc_x86`, `nodejs`,
`js` (spidermonkey`), `gcc, and `tcc_27`. In fact `tcc_3_alt`

## Phase 8

Ultimate aim should be to eliminate `tcc_23_alt` and go straight from
`tcc_3_alt`to `tcc_27`.

Possible we might need to do this in a layered form with individual tests for
features as I think this might be a complex task. When I say layered I mean
maybe `tcc_3_alt` is built with stubs for a particular feature, and then it
is rebuild again with itself with to enable the additional features. The tests
should probably derive from the `tcc_27` codebase so we can bring online the
required features in order.

## Important notes

Important note, within Codex 32 bit code execution may be blocked by the sandbox
. You will need to use `../scripts/run-i386.sh` to run 32 bit code (which can
then be whitelisted once by me.

You will notice that the build process uses `kaem` scripts. This is a trivial
command interpreter. You must retain this ability, and the ability to run
the entire bootstrap via `x86/artifact/kaem-optional-seed` (which is called
in `mk_from_bootstrap_seed`).

In your path you will have nodejs `node`. You will also have `js` which is the
i686 Mozilla Spidermonkey 45 jsshell binary. You will also have mawk if useful.
For auxiliary test scripts and debugging prefer JS/AWK (and EcmaScript 5.1) to
things like python. Ideally never use python.

Do not make any changes to `tcc_bootstrap_alt` and do not modify `human_plan.md`

Track your work in a `TICKETS.md` file where you create an entry for each task
mark it as in progress/done (move the completed tasks to the bottom of the file)
. Make sure you mark the start/end time/date for each task. Also give each
ticket a number.
