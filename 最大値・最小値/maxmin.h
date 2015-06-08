/***********************************************************
	maxmin.h -- 最大値・最小値（maxn, minnは整数以外だとうまくいかないです）
***********************************************************/
#ifndef MAXMIN_H
#define MAXMIN_H

#include <climits>
#include <cstdarg>           /* 不定個の引数を使う */

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
inline T maxn(T n, ...)          /* n 個の T の最大値 */
{
	va_list ap;               /* 不定個の引数へのポインタ */
	T max, x;

	va_start(ap, n);          /* ap の初期化 */
	max = static_cast<T>(INT_MIN);
	while (--n >= 0) {
		x = va_arg(ap, int);  /* ap からTを取り出す */
		if (x > max) max = x;
	}
	va_end(ap);               /* ap の後始末 */
	return max;
}

template<typename T> 
inline T minn(T n, ...)          /* n 個の T の最小値 */
{
	va_list ap;               /* 不定個の引数へのポインタ */
	T min, x;

	va_start(ap, n);          /* ap の初期化 */
	min = static_cast<T>(INT_MAX);
	while (--n >= 0) {
		x = va_arg(ap, int);  /* ap から T を取り出す */
		if (x < min) min = x;
	}
	va_end(ap);               /* ap の後始末 */
	return min;
}

#endif
