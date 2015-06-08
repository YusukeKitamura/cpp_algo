/***********************************************************
	qsort1.h -- クイックソート
***********************************************************/
#ifndef QSORT1_H
#define QSORT1_H

//整数版
void quicksort(keytype a[], int first, int last);

//テンプレート版
template <typename T> void quicksort_T(int n, T a[])
{
	T x, t;

	x = a[(first + last) / 2];
	int i = first;
	int j = last;
	for ( ; ; ) {
		while (a[i] < x) i++;
		while (x < a[j]) j--;
		if (i >= j) break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		i++;
		j--;
	}
	if (first  < i - 1) quicksort_T(a, first , i - 1);
	if (j + 1 < last) quicksort_T(a, j + 1, last);
}

#endif