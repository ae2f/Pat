#ifndef	ae2fpat_dbg_h
#define ae2fpat_dbg_h

#include <assert.h>
#include "./dbgfunc.h"
#include <ae2f/cc/assume.h>
#include <ae2f/cc/branches/naive.h>

#define	ae2fpat_assertassume(a)	\
	assert(a);	ae2f_assume(a);

#define	ae2fpat_assertassume_strict(a)	\
	assert(a);	ae2f_assume_strict(a);

#define	ae2fpat_assertunless(a)	\
	assert(a);	ae2f_ifezerr(a)

#if	defined(NDEBUG)	&& NDEBUG
#define AE2FPAT_DBG	0
#else
#define	AE2FPAT_DBG	1
#endif

#endif
