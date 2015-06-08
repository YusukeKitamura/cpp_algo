/*    Insertion sort    */
#include "inssort.h"

void inssort(int n, int a[])  /* a[0..n-1] を昇順に */
{
	int x;
	int j;
	for (int i = 1; i < n; i++) {
		x = a[i];
		for (j = i - 1; j >= 0 && a[j] > x; j--)
			a[j + 1] = a[j];
		a[j + 1] = x;
	}
}
