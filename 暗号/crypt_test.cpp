/***********************************************************
	crypt_test.cpp -- 暗号　テスト用
***********************************************************/
#include "crypt.h"

int main(int argc, char* argv[])
{
	int seed;
	char* input;
	char* output;

	if (argc < 3 || argc > 4) {
		std::cout << "使用法: Vernam infile outfile [key]" << std::endl;
		return EXIT_FAILURE;
	}

	input  = argv[1];
	output = argv[2];

	if (argc == 4)
		seed = atoi(argv[3]);
	else
		seed = 0;

	if (!Crypt::run(input, output, seed))
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}
