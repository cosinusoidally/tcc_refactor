# Layer Map

The final goal is a sequence of compiler layers, each with a unified build file
that includes the lower layers and the current layer implementation. The current
tree is not split that far yet, but it now has an explicit unified entry point
for the full TCC compatibility layer.

## Current Layers

`cc0.c` is the syntax seed for the base dialect. It is deliberately valid as
both JavaScript and C with `function` and `var` defined as `int`. It now owns
the first tiny compiler-shaped behavior: byte-oriented character/token
classification helpers plus a minimal scanner state machine. String and
character literals are written through wrapper calls: `mks("text")` stores a
NUL-terminated byte string on the C heap or JS virtual heap, and `mkc('A')`
normalizes a character literal/string to its byte code. The runtime-specific
support is kept in `cc0_support.c` and `cc0_support.js`, while shared cc0 code
uses named `CC0_CH_*` constants for byte values, including punctuation consumed
by upper layers. The scanner still accepts fixed eight-byte and sixteen-byte
source windows for regression coverage, and it can also scan strings allocated
through `mks("...")`. In C those strings live on the C heap; in JavaScript they
live in the cc0 virtual heap. The scanner skips whitespace and reports token
class, start offset, length, and decimal value where applicable for names,
decimal numbers, punctuation, and EOF. It also exposes token-word recognizers
for `function`, `var`, and `return`, keeping keyword checks in the same
byte-oriented layer as source access. This keeps the earliest phase below the
preprocessor and suitable for the JS/C dialect intersection. The active
`tccpp.c` tokenizer table now also gets its low ASCII space/name/number flags
from cc0, and the compiler's digit, octal digit, uppercase conversion, and
horizontal-whitespace checks are starting to call the cc0 helpers directly.
Layered TCC can also compile this dialect directly with `-std=cc0`, where the
parser asks cc0 to recognize `function` and `var` as integer type specifiers
instead of requiring preprocessor definitions. This is the first
compiler-front-end behavior migrated into the layered files.

`cc1.c` is the next-layer scaffold. It is also kept in the JavaScript/C
intersection and now consumes the cc0 scanner for a tiny expression grammar:
numbers, names, parentheses, `*`, `+`, `-`, equality, and relational
comparisons with normal precedence. Multi-byte operators such as `==`, `!=`,
`<=`, and `>=` are parsed from adjacent one-byte punctuation tokens, so cc0
remains a byte scanner and cc1 owns the grammar decision. It also has a
four-slot name/value table, a minimal `name = expr` assignment parser, and a
semicolon-separated assignment program parser. The parser can still take fixed
source windows for regression coverage, but the forward path uses `mks` strings
so source length is not capped by the original test cells. It now has the first
cc0-shaped function parser for `function name() { var x = expr; return expr; }`
style bodies. It also accepts simple comma-separated parameters and can bind
supplied argument values before evaluating the body. Parameters and local `var`
statements use the same four-slot name table used by expressions, and the
return expression reuses the expression parser. A narrow sequence of
`if (expr) return expr;` guards models cc0's common early-return control flow,
including equality and range tests, without adding full C statement
parsing yet. That is not a C parser yet, but it gives the layered
tree a tested lower-to-upper token stream and symbol-state boundary before
preprocessing exists.

`cc0_unified.c` is the C unified build for the cc0 scaffold. It maps
`function` and `var` to `int`, includes `cc0.c`, `cc1.c`, and `cc2.c`.

`cc0_unified_cc0.c` is the same lower-layer scaffold built through the cc0
dialect path. It includes `cc0.c`, `cc1.c`, and `cc2.c` without macro-mapping
`function` and `var`; layered TCC builds it with `-std=cc0`, then links in the
C literal-wrapper support.

`cc2.c` is the first scaffold used by the active historical compiler path. It
contains small archive-tool helpers used by `tcc -ar`: option character
classification, 32-bit archive index byte swapping, and exported-symbol
classification. These moved out of `tcctools.c` so that the archive tool can be
ported into staged layers without losing the current bootstrap archive check.

`tcc_unified.c` is the current full compiler layer. It maps the lower-layer
`function` and `var` spelling to C, includes the active cc0/cc2 helpers and the
C runtime support needed by cc0 heap strings, defines `ONE_SOURCE`, and includes
`tcc.c`, which in turn includes `libtcc.c` and `tcctools.c`. Direct `tcc.c`
one-source builds include the same lower helpers when `tcc_unified.c` has not
already done so. This makes the one-source build an explicit source file
instead of a command-line accident.

`tcc_unified_cc0.c` is the corresponding self-hosted dialect entry. It includes
the lower layers without macro-mapping `function` and `var`; layered TCC builds
it with `-std=cc0`, so those spellings are handled by the parser. This keeps the
GCC seed path and the cc0 self-host path separate while the compiler is still
being split into layers. The verification path also uses the cc0-built compiler
to rebuild this same object and compare it byte-for-byte.

## Current Full Compiler Modules

- `tcc.c`: command-line driver.
- `libtcc.c`: high-level compiler state, input dispatch, output selection, and
  library/include path setup.
- `tccpp.c`: preprocessor and tokenizer.
- `tccgen.c`: C parser and target-independent code generation orchestration.
- `i386-gen.c`: i386 machine code emission.
- `i386-asm.c`: i386 assembler parser and encoder.
- `i386-link.c`: i386 relocation handling.
- `tccelf.c`: ELF sections, symbols, archives, dynamic linking, and output.
- `tcctools.c`: archive mode and compiler-driver helpers. Several archive
  helpers now live in `cc2.c`.

## Removed From The Layered Target

The layered tree is now explicitly i386 Linux/ELF. Runtime files for ARM,
ARM64, x86_64, Win32, and bounds-check alloca variants have been removed from
`tcc_27_layered/lib`. The remaining runtime archive inputs are `libtcc1.c` and
`alloca86.S`.
