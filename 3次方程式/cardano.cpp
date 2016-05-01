/***********************************************************
	cardano.cpp -- 3次方程式
***********************************************************/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "cardano.h"

//３乗根
double cuberoot(double x)
{
	double s, prev;
	int pos;

	if (x == 0)
		return 0;
	if (x > 0) {
		pos = 1;
	} else {
		pos = 0;
		x = -x;
	}

	if (x > 1)
		s = x;
	else
		s = 1;
	do {
		prev = s;
		s = (x / (s * s) + 2 * s) / 3;
	} while (s < prev);
	if (pos)
		return prev;
	else
		return -prev;
}

// ax^3 + bx^2 + cx + d = 0
void cardano(double a, double b, double c, double d)
{
	double p, q, t, a3, b3, x1, x2, x3;

	b /= (3 * a);
	c /= a;
	d /= a;
	p = b * b - c / 3;
	q = (b * (c - 2 * b * b) - d) / 2;
	a = q * q - p * p * p;
	if (a == 0) {
		q = cuberoot(q);
		x1 = 2 * q - b;
		x2 = -q - b;
		std::cout << "x = " << x1 << ", " << x2 << " (重解)" << std::endl;
#ifdef CHECK
		std::cout << "f(x1) = " << x1 * (x1 * (x1 + 3 * b) + c) + d << std::endl;
		std::cout << "f(x2) = " << x2 * (x2 * (x2 + 3 * b) + c) + d << std::endl;
#endif
	} else if (a > 0) {
		if (q > 0)
			a3 = cuberoot(q + sqrt(a));
		else
			a3 = cuberoot(q - sqrt(a));
		b3 = p / a3;
		x1 = a3 + b3 - b;  x2 = -0.5 * (a3 + b3) - b;
		x3 = fabs(a3 - b3) * sqrt(3.0) / 2;
		std::cout << "x = " << x1 << "; " << x2 << " +- " << x3 << " i" << std::endl;
#ifdef CHECK
		std::cout << "f(x1) = " << x1 * (x1 * (x1 + 3 * b) + c) + d << std::endl;
		std::cout << "f(x2+-x3i) = " << 
			((x2 + 3 * b) * x2 - x3 * x3 + c) * x2 - (2 * x2 + 3 * b) * x3 * x3 + d << 
			" +- " << ((3 * x2 + 6 * b) * x2 - x3 * x3 + c) * x3 << " i" << std::endl;
#endif
	} else {
		a = sqrt(p);
		t = acos(q / (p * a));
		a *= 2;
		x1 = a * cos( t           / 3) - b;
		x2 = a * cos((t + 2 * PI) / 3) - b;
		x3 = a * cos((t + 4 * PI) / 3) - b;
		std::cout << "x = " << x1  << " , " << x2 << ", " << x3 << std::endl;
#ifdef CHECK
		std::cout << "f(x1) = " << x1 * (x1 * (x1 + 3 * b) + c) + d << std::endl;
		std::cout << "f(x2) = " << x2 * (x2 * (x2 + 3 * b) + c) + d << std::endl;
		std::cout << "f(x3) = " << x3 * (x3 * (x3 + 3 * b) + c) + d << std::endl;
#endif
	}
}
