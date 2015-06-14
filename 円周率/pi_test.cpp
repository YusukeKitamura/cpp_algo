/***********************************************************
	pi_test.cpp -- â~é¸ó¶
***********************************************************/

#include "pi.h"
#include <cfloat>
#include <iostream>
#include <limits>
#include <iomanip>

int main()
{
	//long doubleÇæÇ∆Ç»Ç∫Ç©ê≥ÇµÇ≠ï\é¶Ç≈Ç´Ç»Ç¢
	//long double Pi1 = pi1();
	//long double Pi2 = pi2();
	double Pi1 = pi1();
	double Pi2 = pi2();
	
	std::cout << "MachinÇÃåˆéÆ" << std::endl;
	std::cout <<"pi = "  << std::setprecision(std::numeric_limits<long double>::digits10) << Pi1 << std::endl;
	
	std::cout << "ëäâ¡ëäèÊïΩãœÇ…ÇÊÇÈï˚ñ@" << std::endl;
	std::cout <<"pi = " << std::setprecision(std::numeric_limits<long double>::digits10) << Pi2 << std::endl;
	return EXIT_SUCCESS;
}
