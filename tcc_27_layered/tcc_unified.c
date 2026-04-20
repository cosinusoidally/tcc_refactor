/*
 * Unified source for the current full i386/ELF TCC layer.
 *
 * Later ccX_unified.c files should follow this shape: include the lower layers
 * in order, then include the current layer implementation and the next layer's
 * stubs. For now the historical TCC source still provides the full compiler
 * through tcc.c plus ONE_SOURCE, with migrated helper slices included as they
 * are used by the legacy path.
 */

#define function int
#define var int
#include "cc2.c"
#undef function
#undef var

#define ONE_SOURCE 1
#include "tcc.c"
