/***********************************************************
	normal_test.cpp -- ���K���z�@�e�X�g�p
***********************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "normal.h"

int main()
{
	double z;

	std::cout << "���K���z�̉����m��" << std::endl;
	for (int i = 0; i <= 20; i++) {
		z = 0.2 * i;
		std::cout << std::setw(3) << z << " " << std::setw(8) << p_nor(z) << std::endl;
	}
	return EXIT_SUCCESS;
}
