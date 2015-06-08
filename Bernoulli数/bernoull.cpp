/***********************************************************
	bernoull.cpp -- Bernoulli (ƒxƒ‹ƒk[ƒC) ”
	http://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0
***********************************************************/
#include "bernoull.h"

double gcd(double x, double y)  /* Å‘åŒö–ñ” */
{
	double t;

	while (y != 0) {
		t = fmod(x, y);
		x = y; 
		y = t; 
	}
	return x;
}

Bernoull::Bernoull() :
	denominator(1),
	numerator(0)
{
}

double Bernoull::run(int n)
{
	double b1, b2, d;
	static double t[N + 1];

	double q = 1;
	t[1] = 1;
	for (int n = 2; n <= N; n++) {
		for (int i = 1; i < n; i++) t[i - 1] = i * t[i];
		t[n - 1] = 0;
		for (i = n; i >= 2; i--) t[i] += t[i - 2];
		if (n % 2 == 0) {
			q *= 4;
			b1 = n * t[0]; 
			b2 = q * (q - 1);
			if (b1 < 1 / DBL_EPSILON && b2 < 1 / DBL_EPSILON) {
				d = gcd(b1, b2);  b1 /= d;  b2 /= d;
				printf("|B(%2d)| = %.0f/%.0f\n", n, b1, b2);
			} else
				printf("|B(%2d)| = %g\n", n, b1 / b2);
		}
	}
	return EXIT_SUCCESS;
}
