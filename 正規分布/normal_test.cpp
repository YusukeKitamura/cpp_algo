/***********************************************************
	normal_test.cpp -- 正規分布　テスト用
***********************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "normal.h"

int main()
{
	double z;

	std::cout << "正規分布の下側確率" << std::endl;
	for (int i = 0; i <= 20; i++) {
		z = 0.2 * i;
		std::cout << std::setw(3) << z << " " << std::setw(8) << p_nor(z) << std::endl;
	}
	return EXIT_SUCCESS;
}
