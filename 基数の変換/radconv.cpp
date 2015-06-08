/***********************************************************
	radconv.cpp -- 基数の変換
***********************************************************/
#include "radconv.h"

int conv1(int x, int d, int m, int c[])
{
	int i;
	for (i = 0; x != 0 && i < m; i++) {
		c[i] = x % d;
		x /= d;
	}
	
	if (x == 0) return i;   /* 桁数 */
	else        return -1;  /* エラー */
}

int conv2(int d1, int m1, int x1[], int d2, int m2, int x2[])
{
	int i, j;

	for (i = 0; m1 > 0 && i < m2; i++) {
		int r = 0;
		for (j = m1 - 1; j >= 0; j--) {
			int t = d1 * r + x1[j]; 
			x1[j] = t / d2;
			r = t % d2;
		}
		x2[i] = r;
		while (m1 > 0 && x1[m1 - 1] == 0) m1--;
	}
	if (m1 == 0) return i;   /* 桁数 */
	else         return -1;  /* エラー */
}
