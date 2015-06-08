/***********************************************************
	gencomb_test.cpp -- 組合せの生成　テスト用
***********************************************************/
#include "gencomb.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

int main()
{
	unsigned int N, K, x;
	int i = 1;
	Gencomb gen;
	
	std::cout << "N:" << std::endl;
	std::cin >> N;
	if (N < 1) {
		std::cout << "N is positive!" << std::endl;
		return EXIT_FAILURE;
	}
	
	std::cout << "K:" << std::endl;
	std::cin >> K;
	if (K < 1) {
		std::cout << "K is positive!" << std::endl;
		return EXIT_FAILURE;
	}
	if (K > N) {
		std::cout << "K is not bigger than N!" << std::endl;
		return EXIT_FAILURE;
	}
	
	x = gen.first(K);
	while (! (x & ~gen.first(N))) {
		std::cout << std::setw(4) << i << ":";
		gen.printset(x, N);
		x = gen.nextset(x);
		i++;
	}
	return EXIT_SUCCESS;
}
