/***********************************************************
	house_test.cpp -- Householder (ハウスホルダー) 変換
***********************************************************/
#include <limits.h>
#include <iostream>
#include <cstdio>
#include "house.h"

static unsigned long seed;

double rnd(void)  /* 乱数  0 < rnd() < 1 */
{
	return (seed *= 69069UL) / (ULONG_MAX + 1.0);
}

int main()
{
	int n;
	double s, x1;

	printf("n = ");  scanf("%d", &n);
	printf("乱数の種 (正の整数) = ");
	scanf("%ul", &seed);  seed |= 1;
	Vector x(n);  
	Vector v(n);
	s = 0;
	for (int i = 0; i < n; i++) {
		x(i) = v(i) = rnd() - rnd();
		s += x(i) * x(i);
	}
	printf("x:\n");
	vecprint(x);
	printf("||x|| = %g\n", sqrt(s));

	x1 = house(n, v);  /* Householder変換 */

	printf("x' = (%g, 0, ..., 0)\n", x1);  /* 変換後のベクトルを出力 */

	s = 0;  /* 以下は確認 */
	for (int i = 0; i < n; i++) s += v(i) * x(i);
	for (int i = 0; i < n; i++) x(i) -= s * v(i);
	s = (x(0)- x1) * (x(0) - x1);
	for (int i = 1; i < n; i++) s += x(i) * x(i);
	printf("二乗平均誤差: %g\n", sqrt(s / n));

	return EXIT_SUCCESS;
}
