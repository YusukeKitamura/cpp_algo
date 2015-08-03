/***********************************************************
	chi2.cpp -- カイ2乗分布
***********************************************************/
#include <math.h>
#include "chi2.h"

/* 正規分布の下側累積確率 */
double p_nor(double z)  
{
	double z2, prev, p, t;

	z2 = z * z;
	t = p = z * exp(-0.5 * z2) / sqrt(2 * PI);
	for (int i = 3; i < 200; i += 2) {
		prev = p;
		t *= z2 / i;
		p += t;
		if (p == prev) return 0.5 + p;
	}
	return (z > 0);
}

/* 正規分布の上側累積確率 */
double q_nor(double z)  
{
	return 1 - p_nor(z);
}

/* 上側累積確率 */
double q_chi2(int df, double chi2)  
{
	int k;
	double s, t, chi;

	if (df & 1) {  	// 自由度が奇数
		chi = sqrt(chi2);
		if (df == 1) return 2 * q_nor(chi);
		s = t = chi * exp(-0.5 * chi2) / sqrt(2 * PI);
		for (k = 3; k < df; k += 2) {
			t *= chi2 / k;
			s += t;
		}
		return 2 * (q_nor(chi) + s);
	} else {      	// 自由度が偶数
		s = t = exp(-0.5 * chi2);
		for (k = 2; k < df; k += 2) {
			t *= chi2 / k;
			s += t;
		}
		return s;
	}
}

/* 下側累積確率 */
double p_chi2(int df, double chi2)  
{
	return 1 - q_chi2(df, chi2);
}
