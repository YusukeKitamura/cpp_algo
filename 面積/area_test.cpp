/***********************************************************
	area_test.cpp -- �ʐρ@�e�X�g�p
***********************************************************/
#include "area.h"
#include <iostream>
#include <cstdlib>

int main()
{
	double x[4] = { 1, 3, 2, 0 };
	double y[4] = { 1, 2, 4, 2 };
	double a = area(4, x, y);
	std::cout << "�ʐ� = " << a << std::endl;
	
	return EXIT_SUCCESS;
}
