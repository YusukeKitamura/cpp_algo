/***********************************************************
	bubsort.cpp -- バブルソート
***********************************************************/
#include "bubsort.h"

void bubblesort(int n, int a[])
{
	int x;

	int k = n - 1;
	while (k >= 0) {
		int j = -1;
		for (int i = 1; i <= k; i++)
			if (a[i - 1] > a[i]) {
				j = i - 1;
				x = a[j];
				a[j] = a[i];
				a[i] = x;
			}
		k = j;
	}
}
