/***********************************************************
	maxmin.h -- �ő�l�E�ŏ��l�imaxn, minn�͐����ȊO���Ƃ��܂������Ȃ��ł��j
***********************************************************/
#ifndef MAXMIN_H
#define MAXMIN_H

#include <climits>
#include <cstdarg>           /* �s��̈������g�� */

template<typename T>
inline T max2(T x, T y)
{
	if (x > y) return x;
	else return y;
 }

template<typename T> 
inline T min2(T x, T y)
{
	if (x < y) return x;
	else return y;
}

template<typename T> 
inline T findmax(int n, T a[])
{
	T max = a[0];
	
	for (int i = 1; i < n; i++)
		if (a[i] > max) max = a[i];
	
	return max;
}

template<typename T> 
inline T findmin(int n, T a[])
{
	T min = a[0];
	
	for (int i = 1; i < n; i++)
		if (a[i] < min) min = a[i];
		
	return min;
}

template<typename T> 
inline void findmaxmin(int n, T a[], T *pmax, T *pmin)
{
	T max, min, a1, a2;

	if (n & 1) max = min = a[0];
	else if (a[0] > a[1]) {
		max = a[0]; 
		min = a[1]; 
	} else { 
		max = a[1]; 
		min = a[0];
	}
	for (int i = 2 - (n & 1); i < n; i += 2) {
		a1 = a[i];  a2 = a[i + 1];
		if (a1 > a2) {
			if (a1 > max) max = a1;
			if (a2 < min) min = a2;
		} else {
			if (a2 > max) max = a2;
			if (a1 < min) min = a1;
		}
	}
	*pmax = max;  *pmin = min;
}

template<typename T> 
inline T maxn(T n, ...)          /* n �� T �̍ő�l */
{
	va_list ap;               /* �s��̈����ւ̃|�C���^ */
	T max, x;

	va_start(ap, n);          /* ap �̏����� */
	max = static_cast<T>(INT_MIN);
	while (--n >= 0) {
		x = va_arg(ap, int);  /* ap ����T�����o�� */
		if (x > max) max = x;
	}
	va_end(ap);               /* ap �̌�n�� */
	return max;
}

template<typename T> 
inline T minn(T n, ...)          /* n �� T �̍ŏ��l */
{
	va_list ap;               /* �s��̈����ւ̃|�C���^ */
	T min, x;

	va_start(ap, n);          /* ap �̏����� */
	min = static_cast<T>(INT_MAX);
	while (--n >= 0) {
		x = va_arg(ap, int);  /* ap ���� T �����o�� */
		if (x < min) min = x;
	}
	va_end(ap);               /* ap �̌�n�� */
	return min;
}

#endif
