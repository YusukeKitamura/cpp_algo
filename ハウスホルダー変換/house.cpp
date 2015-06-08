/***********************************************************
	house.cpp -- Householder (�n�E�X�z���_�[) �ϊ�
***********************************************************/
#include "house.h"

double house(int n, Vector& x)
{
	double s, t;

	s = sqrt(innerproduct(n, x, x));  /* ���ς̕�����, ���Ȃ킿�x�N�g�� $x$ �̑傫�� */
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
