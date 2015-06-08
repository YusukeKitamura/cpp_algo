/***********************************************************
	crypt.cpp -- à√çÜ
***********************************************************/
#include "crypt.h"

bool Crypt::run(char* input, char* output, int seed)
{
	int c, r;
	FILE* fp_in;
	FILE* fp_out;
	srand(seed);

	if ((fp_in  = fopen(input, "rb")) == NULL ||
		(fp_out = fopen(output, "wb")) == NULL) {
		std::cout << "égópñ@: Vernam infile outfile [key]" << std::endl;
		return false;
	}

	while ((c = getc(fp_in)) != EOF) {
		do {
			r = rand() / ((RAND_MAX + 1U) / 256);
		} while (r >= 256);
		putc(c ^ r, fp_out);
	}

	return true;
}
