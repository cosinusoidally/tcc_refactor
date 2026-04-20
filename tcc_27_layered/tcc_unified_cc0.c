/*
 * Full compiler entry for the cc0 dialect path.
 *
 * This file is compiled by layered TCC with -std=cc0. Unlike tcc_unified.c it
 * does not macro-map function/var before including the lower layers.
 */

#include "cc0.c"
#include "cc2.c"
#define TCC_LAYERED_LOWER_INCLUDED 1

#define ONE_SOURCE 1
#include "tcc.c"
