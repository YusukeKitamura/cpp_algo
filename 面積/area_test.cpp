/***********************************************************
	area_test.cpp -- 面積　テスト用
***********************************************************/
#include "area.h"
#include <iostream>
#include <cstdlib>

int main()
{
	double x[4] = { 1, 3, 2, 0 };
	double y[4] = { 1, 2, 4, 2 };
	double a = area(4, x, y);
	std::cout << "面積 = " << a << std::endl;
	
	return EXIT_SUCCESS;
}
