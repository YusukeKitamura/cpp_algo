/***********************************************************
	pi_test.cpp -- �~����
***********************************************************/

#include "pi.h"
#include <cfloat>
#include <iostream>
#include <limits>
#include <iomanip>

int main()
{
	//long double���ƂȂ����������\���ł��Ȃ�
	//long double Pi1 = pi1();
	//long double Pi2 = pi2();
	double Pi1 = pi1();
	double Pi2 = pi2();
	
	std::cout << "Machin�̌���" << std::endl;
	std::cout <<"pi = "  << std::setprecision(std::numeric_limits<long double>::digits10) << Pi1 << std::endl;
	
	std::cout << "�������敽�ςɂ����@" << std::endl;
	std::cout <<"pi = " << std::setprecision(std::numeric_limits<long double>::digits10) << Pi2 << std::endl;
	return EXIT_SUCCESS;
}
