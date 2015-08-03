/***********************************************************
	e.cpp -- ©‘R‘Î”‚Ì’ê
***********************************************************/
#include "e.h"

//long double ee(void)
double ee(void)
{
	long double e = 0;
	long double a = 1;
	int n = 1;
	long double prev;
	
	do {
		prev = e;
		e += a;
		a /= n;
		n++;
	} while (e != prev);
	return e;
}
