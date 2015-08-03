/***********************************************************
	horner.cpp -- Horner (ホーナー) 法
***********************************************************/

#include "horner.h"

double horner(int n, double a[], double x)
{
	double p = a[n];
	for (int i = n - 1; i >= 0; i--)
		p = p * x + a[i];
	
	return p;
}
