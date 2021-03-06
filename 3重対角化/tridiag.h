/***********************************************************
	tridiag.h -- 3重対角化
***********************************************************/
#ifndef TRIDIAG_H
#define TRIDIAG_H
#include <iostream>
#include "matutil.h"
#include <math.h>

double house(int n, Vector& x);  /* Householder変換 */

void tridiagonalize(int n, Matrix& a, Vector& d, Vector& e);

#endif
