/***********************************************************
	bernoull.h -- Bernoulli (ƒxƒ‹ƒk[ƒC) ”
***********************************************************/
#ifndef BERNOULL_H
#define BERNOULL_H
#include <cmath>
#include <cfloat>

double gcd(double x, double y);  /* Å‘åŒö–ñ” */
class Bernoull{
public:
	Bernoull();
	double run(int n);
	int denominator;
	int numerator;
};

#endif