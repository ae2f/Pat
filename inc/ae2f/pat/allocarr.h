/** 
 * @file allocarr.h 
 *
 * */

#ifndef	ae2fpat_allocarr_h
#define ae2fpat_allocarr_h

#include <stddef.h>
#include <stdlib.h>

typedef void*	fn_ae2fpat_allocarr_t(size_t c_nel, size_t c_szel);
typedef void*	fn_ae2fpat_reallocarr_t(void* y_ptr, size_t c_nel, size_t c_szel);
typedef void	fn_ae2fpat_freearr_t(void* d_ptr, size_t c_nel, size_t c_szel);


#define	ae2fpat_allocarr(c_nel, c_szel)	\
	calloc(c_nel, c_szel)
#define	ae2fpat_reallocarr(y_ptr, c_nel, c_szel)	\
	realloc(y_ptr, (c_nel) * (c_szel))
#define	ae2fpat_freearr(d_ptr, c_nel, c_szel)	\
	free(d_ptr)

#endif
