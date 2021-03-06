/***********************************************************
	pi_test.cpp -- 円周率
***********************************************************/

#include "pi.h"
#include <cfloat>
#include <iostream>
#include <limits>
#include <iomanip>

int main()
{
	//long doubleだとなぜか正しく表示できない
	//long double Pi1 = pi1();
	//long double Pi2 = pi2();
	double Pi1 = pi1();
	double Pi2 = pi2();
	
	std::cout << "Machinの公式" << std::endl;
	std::cout <<"pi = "  << std::setprecision(std::numeric_limits<long double>::digits10) << Pi1 << std::endl;
	
	std::cout << "相加相乗平均による方法" << std::endl;
	std::cout <<"pi = " << std::setprecision(std::numeric_limits<long double>::digits10) << Pi2 << std::endl;
	return EXIT_SUCCESS;
}
