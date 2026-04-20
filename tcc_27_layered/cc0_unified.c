/*
 * C unified build for the current cc0 scaffold.
 *
 * This is intentionally separate from the JS dialect files. It maps the shared
 * dialect keywords to C and then includes cc0 plus the next-layer stubs.
 */

#define function int
#define var int
#include "cc0.c"
#include "cc1_stubs.c"
