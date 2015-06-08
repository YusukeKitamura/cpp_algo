/***********************************************************
	factoriz.cpp -- ‘fˆö”•ª‰ğ
***********************************************************/
#include "factoriz.h"
#include <iostream>

void factorize(int x)
{
	std::cout << x << " = ";
	while (x >= 4 && x % 2 == 0) {
		std::cout << "2 * ";
		x /= 2;
	}
	int d = 3;
	int q = x / d;
	while (q >= d) {
		if (x % d == 0) {
			std::cout << d << " * ";
			x = q;
		} else
			d += 2;
		q = x / d;
	}
	std::cout << x << std::endl;
}
