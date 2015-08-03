/***********************************************************
	chi2_test.cpp -- カイ2乗分布
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "chi2.h"

int main(void)
{
	double chi2;

	std::cout << "***** p_chi2(df, chi2) *****" << std::endl;
	std::cout << "chi2       df=1    df=2    df=5    df=20"  << std::endl;
	for (int i = 0; i < 20; i++) {
		chi2 = 0.5 * i;
		std::cout << chi2 << "   " << p_chi2(1, chi2) << "   " << p_chi2(2, chi2) << "   ";
		std::cout << p_chi2(5, chi2) << "   " <<p_chi2(20, chi2) << "   " << std::endl;
	}
	
	return EXIT_SUCCESS;
}
