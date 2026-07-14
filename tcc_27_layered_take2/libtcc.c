/*
 *  TCC - Tiny C Compiler
 *
 *  Copyright (c) 2001-2004 Fabrice Bellard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "tcc.h"

/********************************************************/
/* global variables */

/* use GNU C extensions */
ST_DATA int gnu_ext = 1;

/* use TinyCC extensions */
ST_DATA int tcc_ext = 1;

/* XXX: get rid of this ASAP */
ST_DATA struct TCCState *tcc_state;

static int nb_states;

/********************************************************/

#if ONE_SOURCE
#define malloc(s) use_tcc_malloc(s)
#include "cc2_tcc_prims.c"
/* EBX remains reserved, matching the historical i386 allocation. */
#define USE_EBX 0
ST_DATA const int reg_classes[NB_REGS] = {
    RC_INT | RC_EAX,
    RC_INT | RC_ECX,
    RC_INT | RC_EDX,
    (RC_INT | RC_EBX) * USE_EBX,
    RC_FLOAT | RC_ST0,
};
#include "cc2_i386_tables.c"
#endif /* ONE_SOURCE */

/********************************************************/
#ifndef CONFIG_TCC_ASM
ST_FUNC void asm_instr(void)
{
    tcc_error("inline asm() not supported");
}
ST_FUNC void asm_global_instr(void)
{
    tcc_error("inline asm() not supported");
}
#endif


#define free(p) use_tcc_free(p)
#define malloc(s) use_tcc_malloc(s)
#define realloc(p, s) use_tcc_realloc(p, s)

/********************************************************/

/********************************************************/
/* I/O layer */
