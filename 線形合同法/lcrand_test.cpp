/***********************************************************
	lcrand_test.cpp -- 線形合同法 テスト用プログラム
***********************************************************/
#include "lcrand.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>

int main(int argc, char *argv[])
{
	if (argc <= 1) {
		std::cout << "引数に乱数の種（整数）を与えてください" << std::endl;
		return EXIT_FAILURE;
	}
	
	unsigned long seed = atoi(argv[1]);
	LCRand lcr(seed);  /* 任意の unsigned long で初期化. */
	for (int i = 0; i < 80; i++) {
		double data = lcr.rnd();
		std::cout << std::setw(9) << std::setprecision(6) << data << " ";
		if (i % 10 == 9) std::cout << std::endl;
	}
		
	return EXIT_SUCCESS;
}
