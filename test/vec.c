#include <ae2f/pat/vec.auto.h>
#include <ae2f/pat/allocarr.h>
#include <ae2f/pat/dbg.h>
#include <stdio.h>

int main(void);
int main(void) {
	unsigned count_max	= 0;
	unsigned count		= 0;
	int* ptr		= 0;
	unsigned count_max2	= 0;
	unsigned count2		= 0;
	long* ptr2		= 0;

	_ae2fpat_vec_grow_imp(
			L
			, int
			, ae2fpat_allocarr
			, ae2fpat_reallocarr
			, ptr
			, count
			, count_max
			, 3
			, sizeof(int)
			);

	ae2fpat_assertassume(ptr);
	ae2fpat_assertassume(count_max == count);
	ae2fpat_assertassume(count_max == 3);


	_ae2fpat_vec_grow_imp(
			L
			, int
			, ae2fpat_allocarr
			, ae2fpat_reallocarr
			, ptr
			, count
			, count_max
			, 2
			, sizeof(int)
			);

	ae2fpat_assertassume(count_max == count);
	ae2fpat_assertassume(count_max == 3);
	ae2fpat_assertassume(ptr);

	ptr[0] = 3;
	ptr[1] = 5;
	ptr[2] = 8;


	_ae2fpat_vec_grow_imp(
			L
			, int
			, ae2fpat_allocarr
			, ae2fpat_reallocarr
			, ptr
			, count
			, count_max
			, 7
			, sizeof(int)
			);

	ae2fpat_assertassume(count_max == count);
	ae2fpat_assertassume(count_max == 7);
	ae2fpat_assertassume(ptr);
	ae2fpat_assertassume(ptr[0] == 3);
	ae2fpat_assertassume(ptr[1] == 5);
	ae2fpat_assertassume(ptr[2] == 8);

	_ae2fpat_vec_grow_imp(
			L
			, long
			, ae2fpat_allocarr
			, ae2fpat_reallocarr
			, ptr2
			, count2
			, count_max2
			, 4
			, sizeof(long)
			);
#if 1
	_ae2fpat_vec_recfg_imp(
			long		/* TYPE_DST */
			, int		/* TYPE_SRC */
			, mempcy
			, memset
			, ae2fpat_allocarr 
			, ae2fpat_reallocarr
			, ptr2 
			, count2
			, count_max2
			, sizeof(long) 
			, ptr 
			, 3 
			, sizeof(int)
			);

	printf("count2: %u\n", count2);

	ae2fpat_assertassume(count_max2 == count2);
	ae2fpat_assertassume(count2 >= 3);
	ae2fpat_assertassume(ptr);
	ae2fpat_assertassume(ptr2);
	ae2fpat_assertassume(ptr2[0] == 3);
	ae2fpat_assertassume(ptr2[1] == 5);
	ae2fpat_assertassume(ptr2[2] == 8);


	free(ptr);
	free(ptr2);
#endif


	return 0;
}
