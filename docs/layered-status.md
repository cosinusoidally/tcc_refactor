# Layered Bootstrap Status

This tree is being refactored toward the staged compiler described in
`layered_bootstrap.txt`. The active compatibility target is still TinyCC
0.9.27 output for the selected bootstrap files: every step must keep
`sha256sum -c sums_tcc_27` passing without changing `sums_tcc_27`.

## Active Compiler Surface

The current `tcc_27_layered` build is a 32-bit Linux/ELF compiler built through
`tcc_unified.c`. It includes the shared front end, preprocessor, i386 code
generator, assembler support, ELF writer, and command-line driver. Win32/PE
builds are rejected in `tcc.h`, and the default target is always i386 for this
layered tree. Its default library directory is `lib32`, matching the i386 target
used by the bootstrap and allowing normal glibc dynamic links to find 32-bit crt
and libc files on the current host layout. See `docs/layers.md` for the current
module map.

The baseline source tree in `tcc_27/` is read-only for this refactor. It is
compiled only as a fixture to prove that generated objects and the static
bootstrap executable still match the recorded hashes.

## Removed Surface

Bounds checking is not part of the layered bootstrap target. The old native
build auto-enabled `CONFIG_TCC_BCHECK` on i386/x86_64, which pulled in command
line handling and object metadata for `-b`. That configuration is now disabled
in `tcc_27_layered/tcc.h`, the command-line/runtime hooks have been removed
from the active compiler sources, and the unused runtime implementation
`tcc_27_layered/lib/bcheck.c` has been removed. Non-i386 runtime files have
also been removed from `tcc_27_layered/lib`.

This should not change normal compilation output because the bounds machinery
only affects builds that request `-b`. The required invariant is still the
hash check against `sums_tcc_27`.

## Verification

`mk_tcc_27_layered` is the required non-coverage verification path. In addition
to the static bootstrap hash checks, it now verifies that:

- `tcc_27_layered` can create its private runtime archive with `tcc -ar`.
- `tcc_27_layered` can build and start a normal glibc-linked executable of
  itself.
- `tcc_27_layered` can compile the full compiler through
  `tcc_unified_cc0.c` with `-std=cc0`, so the lower-layer `function` and `var`
  spellings are accepted by the parser instead of by macro substitution.
- The compiler produced through `tcc_unified_cc0.c` can rebuild the same cc0
  dialect full-compiler object byte-for-byte.
- `-nostdinc` remains usable on a source file that does not need host headers.
- The existing static `-nostdlib` path still produces the hash-checked
  bootstrap executable.
- `tcc_27_layered` can build and start a normal glibc-linked executable from
  the baseline `tcc_27` source fixture.
- `cc0.c` remains in the C/JavaScript dialect intersection by compiling as C
  with both GCC and the layered TCC using `-Dfunction=int -Dvar=int`, by
  compiling directly with layered TCC using `-std=cc0`, by
  building `cc0_unified.c` plus the C smoke test with both GCC and layered TCC,
  by building `cc0_unified_cc0.c` plus the C smoke test through both the normal
  layered compiler and the cc0-built compiler using `-std=cc0`, and by loading
  the dialect files under SpiderMonkey `js`.

## cc0 Dialect Seed

`tcc_27_layered/cc0.c` is the initial base dialect. It is not a compiler yet,
but it now contains token-classification primitives and a minimal byte scanner
used by both the C and JS smoke tests. The scanner intentionally sits before
preprocessing: it still operates over fixed eight-byte and sixteen-byte source
windows for regression coverage, and it can now scan strings allocated through
`mks("...")`, which removes the first source-length cap from the lower-layer
path. It skips whitespace and records the class/start/length of name, decimal
number, character literal, string literal, punctuation, and EOF tokens. String
literal tokens copy their bytes back into the same C heap or JS virtual heap
model used by `mks`, so later layers can evaluate wrapper literals without
needing a preprocessor. It also recognizes the current token as `function`,
`var`, `return`, `if`, `mkc`, or `mks` without leaving the byte scanner layer.
Function declarations use JavaScript
syntax, and the C build maps `function` and `var` to `int`. Function arguments
therefore use old-style C implicit `int` parameters, which keeps the same file
parseable by both SpiderMonkey and a C compiler. The cc0 dialect can use string
and character literals through wrapper calls: `mks("text")` copies the string
to the C heap or the JS virtual heap, and `mkc('A')` returns the character code.
The support implementations live in `cc0_support.c` and `cc0_support.js`; the
shared dialect source keeps character codes behind named `CC0_CH_*` constants
so the low-level byte logic remains auditable; cc1 also consumes those names for
its punctuation grammar. cc0 also keeps named TCC token constants for the
historical multi-character preprocessing token spellings, including both
two-byte operators and the three-byte `<<=`, `>>=`, and `...` tokens. `tccpp.c`
now uses cc0 to print those tokens and to classify the matching tokenizer
operator cases instead of carrying a private encoded table and switch-local
operator map. The
support layer also exposes a small integer-cell
heap, backed by `malloc` in C and by the existing virtual heap in JS, so later
layers can build tables without leaving the shared dialect. The active TCC preprocessor now calls cc0 for the low
ASCII character flags used to seed its tokenizer table, for decimal and octal
digit checks, for hexadecimal digit values, for ASCII uppercase conversion, for
simple C escape-name values in string and character literals, and for
whitespace checks that must exclude newlines. It also calls cc0 to recognize
the `function` and `var` type words used by the cc0 dialect parser mode. The
cc0 layer is starting to replace front-end logic in the legacy compiler instead
of only being a standalone smoke target.

Layered TCC also accepts `-std=cc0`. In that mode the parser treats the
identifier spellings `function` and `var` as integer type specifiers, so
`cc0.c` can be compiled without preprocessor defines. Other `-std` values
remain ignored for compatibility with the historical TCC command line.

`tcc_27_layered/cc1.c` is the next-layer scaffold. It stays in the same
C/JS intersection and now contains a tiny expression parser over cc0 tokens for
numbers, names, parentheses, unary `!`, `*`, `+`, `-`, equality, and relational
comparisons with normal precedence. The scanner still reports punctuation one
byte at a time; cc1 recognizes adjacent multi-byte operators such as `==`,
`!=`, `<=`, and `>=` so the byte scanner stays simple. It
also has a
four-slot name/value table, a minimal `name = expr` assignment parser, and a
semicolon-separated assignment program parser. The old fixed-window entry
points remain, but cc1 now also parses expressions, assignments, and simple
programs from `mks` strings in both C and JavaScript. It also has the first
cc0-shaped function parser for `function name() { var x = expr; return expr; }`
style bodies, with local `var` assignments feeding the return expression
through the same cc1 name/value table. It now accepts simple comma-separated
parameters and can bind supplied argument values before evaluating the body.
Those runtime bindings now use the same bounded full-name hashes as the source
tables, while `cc1_last_name` still reports the first byte for simple smoke
diagnostics; this lets early function evaluation distinguish names such as
`when_true` and `when_false` without adding string objects to the evaluator.
The body parser also accepts a narrow sequence of `if (expr) return expr;`
early-return guards, including equality and range-test conditions, matching a
common cc0 control-flow shape. It also accepts one nested guard,
`if (expr) if (expr) return expr;`, which matches cc0's byte range classifiers
and can resolve the first named `CC0_CH_*` digit constants used by those
classifiers. The first expression-level helper call, `cc0_is_digit(expr)`, is
evaluated through the real cc0 helper without taking on full C statement
parsing yet. cc1 also evaluates `mkc('A')`, `mks("text")`, and
`cc0_heap_get(expr, expr)`, so the wrapper-literal convention needed by cc0
self-hosting is executable in both C and JavaScript smoke paths. cc1 can now
also run a whole-source cc0 shell parse over the real `cc0.c`: comments are
skipped by the cc0 scanner, top-level `var` declarations and assignments are
recognized, and function signatures plus recursive statement-shell bodies are
parsed. The body pass recognizes block statements, `return`, `if`, `while`,
local `var`, and generic semicolon-terminated statements, so malformed bodies
such as missing semicolons or unbalanced conditions fail before expression
lowering exists. The SpiderMonkey smoke test checks the actual
control-flow/declaration counts for the current `cc0.c` source. It also checks
balanced parentheses within each function body, total semicolon-terminated body
statements, maximum nested body depth, body call-site count, and maximum body
call arity. The same scan now distinguishes body assignment operators from
comparison operators and records maximum nested expression-parenthesis depth.
It also records the maximum statement count and local declaration count seen in
any single function body. Function signature parsing also records total and
maximum parameter counts for the real cc0 source. Semicolon-terminated tails are
now also classified into plain expression statements, call-bearing expression
statements, return statements whose expression contains a call, and `var`
declarations with initializers. Assignment tails are further checked for simple
name targets, and expression scans record the observed `+`, `-`, `*`,
comparison, and unary-not operator families used by cc0 bodies. The source pass
also records aggregate function/global name lengths and stable bounded hashes,
plus the maximum function source span. cc1 now also keeps fixed probes for the
first four function and global symbols by source order, recording each symbol's
bounded hash and length, so the next step toward a real symbol table has tested
ordered source identity data. In parallel, it writes the first bounded source
symbols into a cc0 heap-backed table with kind, hash, length, and ordinal
fields; overflow is recorded explicitly once the bootstrap-sized table fills.
Function signatures and body spans are also copied into a bounded heap-backed
function table, recording each function's name hash/length, parameter count,
source start, source span, and ordinal. Function body scans now additionally
emit bounded statement records with statement kind, nesting depth, source start,
and owning function ordinal, giving later lowering passes a replayable body
skeleton. Signature parameters and local `var` declarations are recorded in
their own heap-backed tables with name hash/length, declaration ordinal, and
owning function ordinal, so the shell parse now exposes the first scoped-name
inventory cc0 lowering will need. Semicolon-terminated body tails also produce
expression-slice records with tail kind, source start, source span, and owning
function ordinal. Each expression slice carries a compact operator flag word for
assignment, call, arithmetic, comparison, and unary-not shapes, giving the next
expression lowering step bounded source ranges and a routing key to consume.
`cc1_compile_unit(source_id)` is no longer a success stub: in the current
bootstrap harness `source_id` is a cc0 heap string pointer, and the entry point
drives the same whole-source cc0 parser used by the source-walk tests. cc1 can now seek the cc0 scanner back to an expression-slice start and evaluate
simple return and initializer slices through the real expression parser, so
recorded body data is beginning to feed executable lowering instead of only
metrics. The bounded cc1 tables now have named capacities large enough to hold
the whole current `cc0.c` source walk, so the smoke path records all 42
functions, 389 body-statement skeleton records, 91 parameter records, 253
expression slices, and their source symbols without overflow. It can also seek from a bounded function-table record and evaluate
simple cc0-shaped functions through the existing cc1 function evaluator; the
smoke tests use this path for synthetic functions and the real `cc0_add`,
`cc0_select`, `cc0_not`, and `cc0_is_word_function_chars` records in `cc0.c`.
The function evaluator now has explicit argument and name slots for the
observed nine-parameter cc0 word recognizers, and can resolve single-character
`CC0_CH_*` constants plus `CC0_CH_NUL` while evaluating guards. Expression
evaluation can also dispatch a call to another recorded function-table entry
and then restore the caller's scanner and binding state; this is pinned by a
synthetic nested-call test and by evaluating the real `cc0_is_alpha` record
through its calls to `cc0_is_upper` and `cc0_is_lower`.
The same evaluator now handles unary minus and non-`var` assignment statements
for the cc0 scanner-state globals. Those global writes are deferred while a
recorded function body is being parsed, then applied after the return path is
known, which lets source-state helpers such as `cc0_source_set8`,
`cc0_source_set_string`, and `cc0_source_seek` run without changing the source
stream out from under the evaluator.
cc1 now keeps a small mirrored cc0 runtime scanner state for those side
effects. The parser still uses the real cc0 scanner to read source, while
recorded cc0 runtime getters such as `cc0_get_tok_class`,
`cc0_get_tok_start`, `cc0_get_tok_len`, and `cc0_get_tok_value` read the
mirror. This avoids treating cc1's current parser token as the cc0 program's
runtime token.
This is
intentionally below C syntax and below the
preprocessor; its purpose is to make the cc0-to-cc1 boundary executable and
self-checking in both runtimes before larger grammar work is moved over.

`tcc_27_layered/cc2.c` starts moving active legacy tool behavior into the
layered files. The archive writer still lives in `tcctools.c`, but the option
character checks, 32-bit archive index byte swapping, and exported-symbol
classification used by `tcc -ar` are now implemented in cc2 and exercised by
the C and JS smoke tests.

`tcc_27_layered/cc3.c` starts moving active parser behavior out of
`tccgen.c`. It is a real TCC-layer file rather than a standalone smoke
compiler: the one-source build includes it after `tcc.h` and before
`tccgen.c`. The current split moves the cc0 dialect type-token check used by
`parse_btype`, the assignment-token predicate used by `expr_eq`, and the
compound-assignment base-token mapping used before `gen_op`. It also owns the
shift, comparison, and equality token predicates used by the expression
precedence parser. The first full parser slice has moved too:
multiplicative, additive, shift, comparison, equality, bitwise AND, bitwise
XOR, bitwise OR, logical AND, logical OR, conditional, assignment, comma, and
integer constant-expression parsing now live in `cc3.c`.

## Current Legacy Shrink

`tccpp.c` no longer owns the low ASCII tokenizer-table classifier directly; it
gets those space/name/number flags from cc0. Its decimal digit checks and
preprocessor whitespace checks are also moving onto cc0 helpers. String and
character literal escape parsing now asks cc0 for hexadecimal digit values and
for the simple named escape values such as `\n`, `\t`, `\\`, and GNU `\e`.
The
multi-character preprocessing-token map for operators such as `<=`, `!=`,
`&&`, `->`, `##`, `<<=`, `>>=`, and `...` is also in cc0 now, and `tccpp.c`
uses that map both when spelling tokens and when lexing those operator cases.
The old
`isid`, `isnum`, `isoct`, `toup`, and newline-excluding `is_space` helper copies
have been removed from `tcc.h`; the remaining layered compiler uses call cc0
classification helpers instead. `tcctools.c` no longer owns the archive option
character classifier, the PE import-definition tool, or the Win32
cross-exec/wildcard helpers. The layered target is i386 Linux/ELF, and the active
archive path now calls into cc2 for the first migrated piece of tool behavior.
`tccgen.c` has also started shrinking: cc0 dialect type-token recognition and
assignment-operator recognition now live in `cc3.c`, along with the expression
parser's shift, comparison, and equality token predicates. The multiplicative
through constant-expression parser functions have also moved out of `tccgen.c`,
so the legacy file now resumes at label detection and declaration/statement
handling. The parser calls through that layer instead of open-coding those
token decisions locally.

## Removed Run Surface

The layered compiler no longer supports TCC's native `-run` mode or libtcc's
in-memory relocation API. The bootstrap checks build and execute normal ELF
files instead, which keeps the layered path focused on reproducible compile and
link behavior.

## Internal Map

The current one-source build reaches the compiler through `tcc_unified.c`,
which includes the lower-layer helpers before `tcc.c`; `tcc.c` includes
`libtcc.c` and `tcctools.c`. If `tcc.c` is used directly as a `ONE_SOURCE`
entry point, it includes the same lower helpers itself.

`tcc_unified_cc0.c` is the self-hosted dialect entry for the same full compiler.
It is built by layered TCC with `-std=cc0` and includes `cc0.c`, `cc2.c`, and
the C cc0 runtime support without defining `function` or `var` as macros first.
`libtcc.c` then includes `cc3.c` before `tccgen.c` on both full-compiler entry
points. The GCC seed still uses `tcc_unified.c` because host compilers do not
understand the cc0 dialect.

`libtcc.c` owns high-level compilation and linking orchestration: creating a
`TCCState`, defining target macros, adding include and library paths, dispatching
source files by type, and writing the requested output.

`tccpp.c` owns preprocessing and tokenization. `tccgen.c` parses C and emits
target-independent code generation requests. The active backend is i386:
`i386-gen.c` emits code, `i386-link.c` applies i386 relocations, and
`i386-asm.c` handles inline and standalone assembly. `tccelf.c` owns ELF
sections, symbols, relocations, archives, dynamic linking metadata, and final
file output.
