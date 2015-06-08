/***********************************************************
	tridiag.h -- 3�d�Ίp��
***********************************************************/
#ifndef TRIDIAG_H
#define TRIDIAG_H
#include <iostream>
#include "matutil.h"
#include <math.h>

double house(int n, Vector& x);  /* Householder�ϊ� */

void tridiagonalize(int n, Matrix& a, Vector& d, Vector& e);

#endif
