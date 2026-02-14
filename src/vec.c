#ifndef	ae2fpat_vec_auto_h
#define ae2fpat_vec_auto_h

#include <ae2f/pat/macro.h>
#include <ae2f/pat/allocarr.h>
#include <ae2f/pat/arrcfg.auto.h>
#include <ae2f/Keys.h>
#include <ae2f/cc.h>

#if	!__ae2f_MACRO_GENERATED
typedef int TYPE;
typedef int TYPE_DST;
typedef int TYPE_SRC;
#endif

ae2f_MAC((TYPE, )) ae2fpat_vec_init(
		fn_ae2fpat_allocarr_t	fn_alloc,
		TYPE*			rn,
		size_t			r_nel,
		size_t			r_nmax,

		const size_t		c_nel_new,
		const size_t		c_szel_new
		)
{
	(rn) = ae2f_reinterpret_cast(
			TYPE*, 
			fn_alloc(ae2f_static_cast(size_t, c_nel_new), c_szel_new)
			);

	(r_nel) = (r_nmax) = (c_nel_new);
}

#if	!__ae2f_MACRO_GENERATED

#define _ae2fpat_vec_init( \
	/** tparam */ \
		TYPE, \
 \
	/** param */ \
		/*    , fn_ae2fpat_allocarr_t */ fn_alloc, \
		/*    TYPE*    */ rn, \
		/*       count_t */ r_nel, \
		/*       count_t */ r_nmax, \
		/*      const  count_t */ c_nel_new, \
		/*     const  size_t    */ c_szel_new \
)	ae2fpat_vec_init(fn_alloc, rn, r_nel, r_nmax, c_nel_new, c_szel_new)

#endif

ae2f_MAC((L, TYPE, )) ae2fpat_vec_grow(
		fn_ae2fpat_allocarr_t	fn_alloc,
		fn_ae2fpat_reallocarr_t	fn_realloc,
		TYPE*			rcn,
		size_t			rc_nel,
		size_t			rc_nmax,

		const size_t		c_nel_new,
		const size_t		c_szel
		)
{
	unless(rcn) {
		_ae2fpat_vec_init(
				TYPE
				, fn_alloc
				, rcn
				, rc_nel, rc_nmax
				, c_nel_new, c_szel
				);
	} else if((rc_nmax) < (c_nel_new)) {
		TYPE* L$$new = fn_realloc(rcn, c_nel_new, c_szel);
		if(L$$new == (rcn)) {
			(rc_nel) = (rc_nmax) = (c_nel_new);
		} else if(L$$new) {
			(rc_nel) = (rc_nmax) = (c_nel_new);
			(rcn) = L$$new;
		}
	} else if ((rc_nel) < (c_nel_new)) {
		(rc_nel) = (c_nel_new);
	}
}

#if	!__ae2f_MACRO_GENERATED

#define _ae2fpat_vec_grow( \
	/** tparam */ \
		L,TYPE, \
 \
	/** param */ \
		/*    , fn_ae2fpat_allocarr_t */ fn_alloc, \
		/*     fn_ae2fpat_reallocarr_t */ fn_realloc, \
		/*    TYPE*    */ rcn, \
		/*       size_t */ rc_nel, \
		/*       size_t */ rc_nmax, \
		/*      const  size_t */ c_nel_new, \
		/*     const  size_t    */ c_szel \
)	ae2fpat_vec_grow(fn_alloc, fn_realloc, rcn, rc_nel, rc_nmax, c_nel_new, c_szel)

#endif

ae2f_MAC((TYPE_DST, TYPE_SRC, mempcy, memset, )) ae2fpat_vec_recfg(
		fn_ae2fpat_allocarr_t	fn_alloc,
		fn_ae2fpat_reallocarr_t	fn_realloc,
		TYPE_DST*		rn_dst,
		size_t			rc_nel_dst,
		size_t			rc_nmax_dst,
		const size_t		c_szel_dst,


		const TYPE_SRC*		rd_src,
		const size_t		c_nel_src,
		const size_t		c_szel_src
		)
{
	_ae2fpat_vec_grow(
			L$$L
			, TYPE_DST
			, fn_alloc
			, fn_realloc
			, rn_dst
			, rc_nel_dst
			, rc_nmax_dst
			, c_nel_src
			, c_szel_dst
			);

	ae2f_expected_if((rd_src) && (rn_dst)) {
		_ae2fpat_arrcfg(
				L$$L$$L
				, memcpy
				, memset
				, rn_dst
				, rc_nel_dst
				, c_szel_dst
				, rd_src
				, c_nel_src
				, c_szel_src
			       );
	} 
}

#endif
