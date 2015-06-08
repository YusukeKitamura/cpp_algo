/***********************************************************
	bubsort.h -- バブルソート
***********************************************************/
#ifndef BUBSORT_H
#define BUBSORT_H

//整数版
void bubblesort(int n, int a[]);

//テンプレート版
template <typename T> void bubblesort_T(int n, T a[])  {
	T x;

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

#endif
