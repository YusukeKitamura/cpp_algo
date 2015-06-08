/***********************************************************
	factanal.h -- 因子分析
***********************************************************/
#ifndef FACTANAL_H
#define FACTANAL_H
#include <iostream>
#include "statutil.h"     /* 多変量データ入力ルーチン */

const double EPS = 1E-6;  /* 非対角成分の許容誤差 */
const int MAX_ITER = 100;   /* 最大の繰返し数 */

class Factanal : public StatUtil {
public:
	Factanal();
	~Factanal();
	double house(int n, Vector& x);  // Householder変換
	void tridiagonalize(int n, Matrix& a, Vector& d, Vector& e); // 3重対角化
	int eigen(int n, Matrix& a, Vector& d, Vector& e);
	bool factor(int m, int nfac, Matrix r, Matrix q, Vector lambda, Vector work);

};

#endif
