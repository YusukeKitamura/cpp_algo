/***********************************************************
	pi2.cpp -- ‰~ü—¦
***********************************************************/
/* ‘Š‰Á‘Šæ•½‹Ï‚É‚æ‚é•û–@ */

#include "pi.h"
#include <iostream>
#include <limits>
#include <iomanip>

long double pi2(void)
{
	double a, b, s, t, last, pi;

	a = 1; 
	b = 1 / sqrt(2.0); 
	s = 1; 
	t = 4;
	for (int i = 0; i < 3; i++) {
		last = a;
		a = (a + b) / 2;
		b = sqrt(last * b);
		s -= t * (a - last) * (a - last);
		t *= 2;
		pi = (a + b) * (a + b) / s;
		std::cout << "i=" << i << std::setprecision(std::numeric_limits<long double>::digits10) << " pi=" << pi << std::endl;
	}
	
	return pi;
}
