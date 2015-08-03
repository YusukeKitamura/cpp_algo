/***********************************************************
	partit.cpp -- 分割数
***********************************************************/
#include "partit.h"

static int p(int n, int k)
{
	if (n < 0)
		return 0;
	if (n <= 1 || k == 1)
		return 1;
	
	int s = 0;
	for (int i = 1; i <= k; i++)
		s += p(n - i, i);
	
	return s;
}

int partition(int n)
{
	return p(n, n);
}
