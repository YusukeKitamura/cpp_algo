/***********************************************************
	cardano_test.cpp -- 3次方程式 テスト用
***********************************************************/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "cardano.h"

int main()
{
	double a, b, c, d;

	std::cout << "a b c d = " << std::endl;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	if (a == 0) {
		std::cout << "３次方程式ではありません." << std::endl;
		return EXIT_FAILURE;
	}
	cardano(a, b, c, d);
	return EXIT_SUCCESS;
}
