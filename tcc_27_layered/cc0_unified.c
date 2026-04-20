/*
 * C unified build for the current cc0 scaffold.
 *
 * This is intentionally separate from the JS dialect files. It maps the shared
 * dialect keywords to C and then includes the active staged scaffolds.
 */

#define function int
#define var int
#include "cc0.c"
#include "cc1.c"
#include "cc2.c"
