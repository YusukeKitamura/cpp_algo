/***********************************************************
	roundoff_test.cpp -- 四捨五入　テスト用
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "roundoff.h"

int main()
{
	unsigned long a, b;
	unsigned int r;

	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;
	r = round1000(a, b);
	std::cout << "a / b = " << (float)(r) / 1000 << " " << r % 1000;
	return EXIT_SUCCESS;
}
