#include <ae2f/pat/arrcfg.auto.h>
#include <ae2f/pat/dbg.h>
#include <stdio.h>

int main(void);
int main(void) {
	char	SRC[] = {1, 2, 3};
	int	DST[sizeof(SRC) / sizeof(SRC[0])] = { 4, 5, 6 };
	short	DST2[sizeof(SRC) / sizeof(SRC[0])] = { 4, 5, 6 };

	printf("OLD:\t\t%d %d %d\n", DST[0], DST[1], DST[2]);

	_ae2fpat_arrcfg_imp(L
			, memcpy
			, memset
			, DST, sizeof(DST) / sizeof(DST[0]), sizeof(DST[0])
			, SRC, sizeof(SRC) / sizeof(SRC[0]), sizeof(SRC[0]));

	ae2fpat_assertassume(DST);
	ae2fpat_assertassume(DST[0] == 1);
	ae2fpat_assertassume(DST[1] == 2);
	ae2fpat_assertassume(DST[2] == 3);

	printf("char to int:\t%d %d %d\n", DST[0], DST[1], DST[2]);

	_ae2fpat_arrcfg_imp(L
			, memcpy
			, memset
			, DST2, sizeof(DST2) / sizeof(DST2[0]), sizeof(DST2[0])
			, DST, sizeof(DST) / sizeof(DST[0]), sizeof(DST[0]));

	ae2fpat_assertassume(DST);
	ae2fpat_assertassume(DST2[0] == 1);
	ae2fpat_assertassume(DST2[1] == 2);
	ae2fpat_assertassume(DST2[2] == 3);

	printf("int to short:\t%d %d %d\n", DST[0], DST[1], DST[2]);

	return 0;
}
