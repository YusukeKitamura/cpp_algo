/***********************************************************
	egypfrac.cpp -- �G�W�v�g�̕���
***********************************************************/
#include "egypfrac.h"

std::vector<int> egypfrac(int m, int n)
{
	int q;
	std::vector<int> v;

	while (n % m != 0) {
		q = n / m + 1;
		v.push_back(q);
		m = m * q - n;
		n *= q;
	}
	v.push_back(n / m);
	
	return v;
}
