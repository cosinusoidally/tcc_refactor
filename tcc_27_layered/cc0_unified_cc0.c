/*
 * cc0 dialect unified build for the current lower-layer scaffold.
 *
 * This entry is compiled with layered TCC using -std=cc0. It includes the
 * shared dialect layers without macro-mapping function/var first, then includes
 * the C runtime support for wrapper literals.
 */

#include "cc0.c"
#include "cc1.c"
#include "cc2.c"
#include "cc0_support.c"
