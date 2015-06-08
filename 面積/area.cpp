/***********************************************************
	area.cpp -- –ÊÏ
***********************************************************/
#include "area.h"

double area(int n, double x[], double y[])
{
	double a;

	a = x[n - 1] * y[0] - x[0] * y[n - 1];
	for (int i = 1; i < n; i++)
		a += x[i - 1] * y[i] - x[i] * y[i - 1];

	return 0.5 * a;
}
