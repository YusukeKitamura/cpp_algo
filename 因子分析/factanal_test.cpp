/***********************************************************
	factanal_test.cpp -- 因子分析
***********************************************************/
#include "factanal.h"

/*
  因子分析のメインルーチン. 単に相関係数を求めるだけであるが,
  データを主記憶に一度に読み込むのでなく,
  漸化式を使って平均, 分散, 相関係数を更新する方法を用いている.
*/
int main(int argc, char *argv[])
{
	Factanal fact;
	int nfac;
	double t;

	if (argc != 2) {
		std::cerr << "使用法: factanal filename" << std::endl;
		return EXIT_FAILURE;
	}
	
	int errval = fact.read_data(argv[1]);
	if (errval == 999) {
		std::cerr << "データ読み込み失敗！！" << std::endl;
		return EXIT_FAILURE;  /* 失敗 */
	}
	
	Matrix r(fact.cols, fact.cols);		//相関係数
	Matrix q(fact.cols, fact.cols);		//固有ベクトル
	Vector mean(fact.cols);				//平均
	Vector lambda(fact.cols);			//固有値
	Vector work(fact.cols);				//作業用
	
	for (int j = 0; j < fact.cols; j++) {
		mean(j) = 0;
		for (int k = 0; k <= j; k++)
			r(j, k) = 0;
	}
	
	for (int i = 0; i < fact.rows; i++) {
		for (int j = 0; j < fact.cols; j++) {
			t = fact.mat(i, j);                          /* 数値入力 */
			if (missing(t)) {
				std::cerr << "データ不良" << std::endl;;           /* 欠測値かエラー */
				return EXIT_FAILURE;
			}
			work(j) = t - mean(j); 
			mean(j) += work(j) / (i + 1);
			for (int k = 0; k <= j; k++)
				r(j, k) += i * work(j) * work(k) / (i + 1);
		}
	}
	
	for (int j = 0; j < fact.cols; j++) {
		work(j) = sqrt(r(j, j)); 
		r(j, j) = 1;
		for (int k = 0; k < j; k++) {
			r(j, k) /= work(j) * work(k); 
			r(k, j) = r(j, k);
		}
	}
	
	t = 1 / sqrt(fact.rows - 1.0);
	std::cout << "変数  平均値        標準偏差" << std::endl;
	for (int j = 0; j < fact.cols; j++) {
		std::cout << j + 1 << " " << mean(j) << " " << t * work(j) << std::endl;
	}
	
	std::cout << "相関係数" << std::endl;                     /* 左下半分だけ表示 */
	for (int j = 0; j < fact.cols; j++) {
		for (int k = 0; k <= j; k++)
			std::cout << r(j, k) << " ";
		std::cout << std::endl;
	}
	
	for ( ; ; ) {
		std::cout << std::endl;
		std::cout << "共通因子の数 (0:実行終了) ? ";
		std::cin >> nfac;
		if (nfac > fact.cols)
			nfac = fact.cols;
		if (nfac < 1) break;
		fact.factor(fact.cols, nfac, r, q, lambda, work);
	}
	return EXIT_SUCCESS;
}
