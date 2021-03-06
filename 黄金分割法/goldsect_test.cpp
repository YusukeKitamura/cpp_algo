/***********************************************************
	goldsect_test.cpp -- 黄金分割法
***********************************************************/
#include "goldsect.h"
#include <iostream>
#include <cstdlib>
#define TEST  1

double func(double x)  /* 最小化する関数 */
{
	static int count = 0;
	const double xmin = 0.314;
	double value;

	value = (x - xmin) * (x - xmin);
	#if TEST
		std::cout << ++count << ": f(" << x << ")= " << value << std::endl;
	#endif
	return value;
}

int main()
{
	GoldSect opt;
	double min = opt.minimize(0, 1, 1e-6, func);
	std::cout << "x= " << min << std::endl;
	
	return EXIT_SUCCESS;
}
