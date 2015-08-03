/***********************************************************
	e_test.cpp -- 自然対数の底　テスト
***********************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "e.h"

int main()
{
	std::cout << "e = " << std::setprecision(18) << ee() << std::endl;
	return EXIT_SUCCESS;
}
