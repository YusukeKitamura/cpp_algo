/***********************************************************
	inssort.h -- 挿入ソート
***********************************************************/
#ifndef INSSORT_H
#define INSSORT_H

//整数版
void inssort(int n, int a[]);

//テンプレート版
template <typename T> void inssort_T(int n, T a[])  {
	T x;
	int j;
	for (int i = 1; i < n; i++) {
		x = a[i];
		for (j = i - 1; j >= 0 && a[j] > x; j--)
			a[j + 1] = a[j];
		a[j + 1] = x;
	}
}

#endif
