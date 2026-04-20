# Layer Map

The final goal is a sequence of compiler layers, each with a unified build file
that includes the lower layers and the current layer implementation. The current
tree is not split that far yet, but it now has an explicit unified entry point
for the full TCC compatibility layer.

## Current Layers

`cc0.c` is the syntax seed for the base dialect. It is deliberately valid as
both JavaScript and C with `function` and `var` defined as `int`. It now owns
the first tiny compiler-shaped behavior: byte-oriented character/token
classification helpers plus a minimal scanner state machine. The scanner uses a
fixed eight-byte source window for now, skips whitespace, and reports token
class, start offset, length, and decimal value where applicable for names,
decimal numbers, punctuation, and EOF. This keeps the earliest phase below the
preprocessor and suitable for the JS/C dialect intersection.

`cc1.c` is the next-layer scaffold. It is also kept in the JavaScript/C
intersection and now consumes the cc0 scanner for a tiny expression grammar:
numbers, names, parentheses, `*`, and `+` with normal precedence. It also has a
four-slot name/value table and a minimal `name = expr` assignment parser. That
is not a C parser yet, but it gives the layered tree a tested lower-to-upper
token stream and symbol-state boundary before preprocessing exists.

`cc0_unified.c` is the C unified build for the cc0 scaffold. It maps
`function` and `var` to `int`, includes `cc0.c`, and then includes
`cc1.c`.

`tcc_unified.c` is the current full compiler layer. It defines `ONE_SOURCE` and
includes `tcc.c`, which in turn includes `libtcc.c` and `tcctools.c`. This makes
the one-source build an explicit source file instead of a command-line accident.

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
- `tcctools.c`: archive mode and compiler-driver helpers.

## Removed From The Layered Target

The layered tree is now explicitly i386 Linux/ELF. Runtime files for ARM,
ARM64, x86_64, Win32, and bounds-check alloca variants have been removed from
`tcc_27_layered/lib`. The remaining runtime archive inputs are `libtcc1.c` and
`alloca86.S`.
