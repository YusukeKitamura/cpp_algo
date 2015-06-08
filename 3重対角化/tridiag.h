/***********************************************************
	tridiag.h -- 3d‘ÎŠp‰»
***********************************************************/
#ifndef TRIDIAG_H
#define TRIDIAG_H
#include <iostream>
#include "matutil.h"
#include <math.h>

double house(int n, Vector& x);  /* Householder•ÏŠ· */

void tridiagonalize(int n, Matrix& a, Vector& d, Vector& e);

#endif
