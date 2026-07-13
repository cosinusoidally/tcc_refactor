# tcc_27_layered_take2 Development Rules

## Scope

- This tree is the second layered refactor of `tcc_27`.
- Support only 32-bit i386 Linux. Do not add portability abstractions for other
  targets to new layered code.
- Do not inspect, copy, or adapt code from `tcc_27_layered/`. That directory is
  not a reference for this implementation.
- Keep build artifacts in the repository-level `artifacts/` directory. Do not
  add build products to this source tree.
- `sums_tcc_27` is the compatibility contract. Do not change it to accommodate
  compiler output changes.

## Layering

- `cc0.c` is the minimal bootstrap dialect and must remain human-auditable.
- Higher `ccN.c` files add compiler facilities in explicit, reviewable layers.
- A lower layer must not depend on an implementation from a higher layer.
- Prefer ordinary source and direct function calls over generated tables,
  encoded programs, macro metaprogramming, or other opaque mechanisms.
- Keep unified entry files as simple ordered compositions of the layers.

## cc0 C/JavaScript Dialect

- The same `cc0.c` text must execute as SpiderMonkey jsshell 45 JavaScript and
  compile as GNU89 C and as TCC input.
- JavaScript reads `cc0.c` without preprocessing or source rewriting.
- When function or global declarations are added, use the shared source shape
  `function name(args) { ... }` and `var name;`. C builds may map `function`
  and `var` explicitly to `int`; do not hide additional translation in that
  mapping.
- Use `/* ... */` comments so comments have identical lexical meaning in both
  languages.
- Do not use arithmetic, comparison, logical, bitwise, or pointer operators in
  `cc0.c`. Use lowercase primitive calls such as `add(a, b)`, `eq(a, b)`, and
  `ri32(address)` instead. Assignment remains part of the cc0 statement syntax.
- Do not prefix primitive names with `CC0_` or provide uppercase aliases.
- Implement host meanings for otherwise inexpressible primitives in the small
  C and JavaScript support files. Those files must not contain compiler policy,
  parsing, data structures, or convenience helpers that can be written in the
  cc0 dialect.
- The self-hosted cc0 compiler must recognize the same primitives as builtins
  and emit their i386 implementations. Host support is only for running cc0
  before that self-hosted compiler exists.
- Treat compiler values as signed 32-bit integers unless a documented helper
  has different semantics.
- Keep host support primitives small, named, and documented. Compiler policy
  belongs in `cc0.c`, not in a host runner or compatibility shim.
- Do not depend on JavaScript features newer than SpiderMonkey 45.

## Auditability

- Every `if`, `else`, `while`, `for`, and similar control-flow body in new or
  migrated code must use braces. Never use an implicit single-statement body.
- Replace protocol numbers, token values, flags, sizes, offsets, and syscall
  numbers with descriptive names. Small conventional values such as `0` and
  `1` are acceptable when their meaning is obvious.
- Add short comments for representation choices, invariants, non-obvious
  control flow, and host-language compatibility techniques.
- Comments must explain why a mechanism exists, not restate each statement.
- Avoid compressed one-line algorithms and large repetitive blocks that could
  be generated from a clearer description.
- Keep functions focused and use descriptive names. Split code when doing so
  makes a layer boundary or invariant easier to review.

## Verification

- Do not embed source files in `mk_tcc_27_layered_take2` with here-documents or
  generated strings. Put take2-specific fixtures in `tests/layered/` and have
  the build script compile or execute those checked-in files.
- Run the repository-level `./mk_tcc_27_layered_take2` after changes affecting
  the compiler or build.
- Verify `cc0.c` with GCC, the self-hosted compiler, the `cc0` dialect path, and
  `/home/foo/src/jsshell/js`.
- Require consecutive self-hosted compiler objects to be byte-identical.
- Require every hash in `sums_tcc_27` to pass without updating the hash file.
