/***********************************************************
	cuberoot_test.cpp -- 立方根　テスト用
***********************************************************/
#include "cuberoot.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cfloat>

int main()
{
	for (int i = 0; i <= 20; i++) {
		std::cout << std::setw(7) << std::setprecision(5)  << i << " " << DBL_DIG - 1 << " " << Cuberoot::cuberoot(i);
		std::cout << " " << LDBL_DIG - 1 << " " << Cuberoot::lcuberoot(i) << std::endl;
	}
	
	return EXIT_SUCCESS;
}
