/***********************************************************
	qsort1.cpp -- クイックソート
***********************************************************/
#include "qsort1.h"

void quicksort(int a[], int first, int last)
{
	int x, t;

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
	if (first  < i - 1) quicksort(a, first , i - 1);
	if (j + 1 < last) quicksort(a, j + 1, last);
}
