#include <ae2f/pat/arrcfg.auto.h>
#include <assert.h>
#include <stdio.h>

int main(void);
int main(void) {
	char	SRC[] = {1, 2, 3};
	int	DST[sizeof(SRC) / sizeof(SRC[0])] = { 4, 5, 6 };
	short	DST2[sizeof(SRC) / sizeof(SRC[0])] = { 4, 5, 6 };

	printf("OLD:\t\t%d %d %d\n", DST[0], DST[1], DST[2]);

	_ae2fpat_arrcfg(L
			, memcpy
			, memset
			, DST, sizeof(DST) / sizeof(DST[0]), sizeof(DST[0])
			, SRC, sizeof(SRC) / sizeof(SRC[0]), sizeof(SRC[0]));

	assert(DST[0] == 1);
	assert(DST[1] == 2);
	assert(DST[2] == 3);

	printf("char to int:\t%d %d %d\n", DST[0], DST[1], DST[2]);

	_ae2fpat_arrcfg(L
			, memcpy
			, memset
			, DST2, sizeof(DST2) / sizeof(DST2[0]), sizeof(DST2[0])
			, DST, sizeof(DST) / sizeof(DST[0]), sizeof(DST[0]));

	assert(DST2[0] == 1);
	assert(DST2[1] == 2);
	assert(DST2[2] == 3);

	printf("int to short:\t%d %d %d\n", DST[0], DST[1], DST[2]);

	return 0;
}
