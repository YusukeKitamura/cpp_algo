/***********************************************************
	cuberoot.cpp -- —§•ûª
***********************************************************/
#include "cuberoot.h"

double Cuberoot::cuberoot(double x)  /* $\sqrt[3]{x}$ */
{
	double s, prev;
	int positive;

	if (x == 0)
		return 0;
	if (x > 0) {
		positive = 1;
	} else {
		positive = 0; 
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
	
	if (positive)
		return prev;
	else
		return -prev;
}

double Cuberoot::cuberoot2(double x)  /* $\sqrt[3]{x}$ */
{
	double s, t, prev;
	int positive;

	if (x == 0) return 0;
	if (x > 0) positive = 1; 
	else { 
		positive = 0; 
		x = -x; 
	}
	if (x > 1) s = x; 
	else s = 1;
	
	do {
		prev = s;
		t = s * s;
		s += (x - t * s) / (2 * t + x / s);
	} while (s < prev);
	
	if (positive) return prev; 
	else return -prev;
}

long double Cuberoot::lcuberoot(long double x)
{
	if (x == 0) return 0;
	long double s = cuberoot(x);
	
	return (x / (s * s) + 2 * s) / 3;
}
