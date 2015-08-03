/***********************************************************
	chi2.h -- カイ2乗分布
***********************************************************/
#ifndef CHI2_H
#define CHI2_H

const double PI = 3.14159265358979323846264;

double p_nor(double z);  				// 正規分布の下側累積確率
double q_nor(double z);  				// 正規分布の上側累積確率
double q_chi2(int df, double chi2);  	// 上側累積確率
double p_chi2(int df, double chi2);  	// 下側累積確率

#endif
