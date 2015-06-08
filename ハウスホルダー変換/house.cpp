/***********************************************************
	house.cpp -- Householder (ハウスホルダー) 変換
***********************************************************/
#include "house.h"

double house(int n, Vector& x)
{
	double s, t;

	s = sqrt(innerproduct(n, x, x));  /* 内積の平方根, すなわちベクトル $x$ の大きさ */
	if (s != 0) {
		if (x(0) < 0)
			s = -s;
		x(0) += s; 
		t = 1 / sqrt(x(0) * s);
		
		for (int i = 0; i < n; i++)
			x(i) *= t;
	}
	return -s;
}
