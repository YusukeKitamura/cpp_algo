/***********************************************************
	srchmat.cpp -- 2������õ��
***********************************************************/
#include "srchmat.h"

bool searchmat(
	int x, matrix a,
	int imin, int imax,
	int jmin, int jmax,
	int *i, int *j)
{
	*i = imax;
	*j = jmin;
	while (a[*i][*j] != x) {
		if (a[*i][*j] < x) (*j)++;
		else (*i)--;
		if (*i < imin || *j > jmax) return false;
	}
	return true;
}
