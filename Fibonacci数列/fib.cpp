/***********************************************************
	fib.cpp -- Fibonacci (�t�B�{�i�b�`) ����
	http://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A3%E3%83%9C%E3%83%8A%E3%83%83%E3%83%81%E6%95%B0
***********************************************************/
#include "fib.h"

// ��ʍ��𒼐ڌv�Z������@
unsigned long Fib::fib1(int n)
{
	unsigned long ret = (unsigned long)(pow((1 + sqrt(5)) / 2, n) / sqrt(5) + 0.5);
	return ret;
}

// �s��̗ݏ�v�Z��W�J���Čv�Z���AO(log n)�ŋ��߂���@
unsigned long Fib::fib2(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;
	int a1, b1, c1;
	unsigned long x = 1;
	unsigned long y = 0;
	unsigned long x1, y1;
	n--;
	while (n > 0) {
		if (n & 1) {
			x1 = x;
			y1 = y;
			x = a * x1 + b * y1;
			y = b * x1 + c * y1;
		}
		n /= 2;
		a1 = a;
		b1 = b;
		c1 = c;
		a = a1 * a1 + b1 * b1;
		b = b1 * (a1 + c1);
		c = b1 * b1 + c1 * c1;
	}
	return x;
}

// ��`����ċA�Ōv�Z����BO(2^n)
unsigned long Fib::fib3(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib3(n - 1) + fib3(n - 2);
}

// ���I�v��@�Ōv�Z����BO(n)
unsigned long Fib::fib4(int n)
{
	unsigned long *tmp = new unsigned long[n+1];
	tmp[0] = 0;
	if (n >= 1)
		tmp[1] = 1;
		
	if (n >= 2) {
		for (int i = 2; i <= n; i++) {
			tmp[i] = tmp[i - 1] + tmp[i - 2];
		}
	}
	
    return tmp[n];
}
