/***********************************************************
	factoriz_test.cpp -- 素因数分解　テスト用
***********************************************************/
#include "factoriz.h"
#include <cstdlib>

int main()
{
	for (int i = 1; i <= 100; i++)
		factorize(i);
	return EXIT_SUCCESS;
}
