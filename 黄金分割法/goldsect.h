/***********************************************************
	goldsect.h -- ‰©‹à•ªŠ„–@
***********************************************************/
#ifndef GOLDSECT_H
#define GOLDSECT_H

#include <cmath>

const double r = 2 / (3 + sqrt(5));
	
class GoldSect {
public:
	GoldSect();
	double minimize(double a, double b, double tolerance, double (*f)(double x));
	
};

#endif
