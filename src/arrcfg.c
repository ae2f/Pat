/** @file arrcfg.c */

#ifndef	ae2fpat_arrcfg_auto_h
#define ae2fpat_arrcfg_auto_h

#include <ae2f/pat/macro.h>
#include <ae2f/c90/StdInt.h>
#include <string.h>
#include <stddef.h>
#include <ae2f/Cast.h>
#include <ae2f/Keys.h>

/**
 * @fn		ae2fpat_arrcfg_imp
 * @brief	naive copy of array from `src` to `dst`.
 * @tparam	L
 * @tparam	memcpy
 * @tparam	memset
 * @param	wr_dst
 * @param	c_dst_nel
 * @param	c_dst_szel
 * @param	rd_src
 * @param	c_src_nel
 * @param	c_src_szel
 * */
ae2f_MAC((L, memcpy, memset, )) ae2fpat_arrcfg_imp(
		void*		wr_dst,
		const size_t	c_dst_nel,
		const size_t	c_dst_szel,
		const void*	rd_src,
		const size_t	c_src_nel,
		const size_t	c_src_szel
		)
{
	if((wr_dst) != 0 && (rd_src) != 0)
	{
		size_t	L$$cpyidx = 
			(c_dst_nel) < (c_src_nel) && 1 ? (c_dst_nel) : (c_src_nel);

		const size_t	L$$cpysz =
			(c_dst_szel) < (c_src_szel) && 1 ? (c_dst_szel) : (c_src_szel);

		memset(wr_dst, 0, ae2f_static_cast(size_t, c_dst_nel) * (c_dst_szel));

		while(L$$cpyidx--)
		{
			memcpy(
					ae2f_reinterpret_cast(char*, wr_dst) + (c_dst_szel) 
					* ae2f_static_cast(size_t, L$$cpyidx) /**/
					, ae2f_reinterpret_cast(const char*, rd_src) + (c_src_szel) 
					* ae2f_static_cast(size_t, L$$cpyidx) /**/
					, L$$cpysz
					);
		}
	}
}

#endif
