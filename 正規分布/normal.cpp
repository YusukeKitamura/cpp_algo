/***********************************************************
	normal.cpp -- ���K���z
***********************************************************/
#include <cmath>
#include "normal.h"

// ���K���z�̉����m��
double p_nor(double z)
{
	double prev, p, t;
	double z2 = z * z;
	
	t = p = z * exp(-0.5 * z2) / sqrt(2 * PI);
	for (int i = 3; i < 200; i += 2) {
		prev = p;
		t *= z2 / i;
		p += t;
		if (p == prev)
			return 0.5 + p;
	}
	return (z > 0);
}

// ���K���z�̏㑤�m��
double q_nor(double z)  
{
	return 1 - p_nor(z);
}
