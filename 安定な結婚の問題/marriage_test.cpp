/***********************************************************
	marriage_test.cpp -- 安定な結婚の問題　テスト用
***********************************************************/
#include "marriage.h"
#include <cstdlib>

const int N = 3;

int main()
{
	Marriage m(N);

	for (int g = 1; g <= N; g++) {  /* 各女性の好み */
		m.setGirl(g);
	}
	for (int b = 1; b <= N; b++) {  /* 各男性の好み */
		m.setBoy(b);
	}
	
	m.calc();
	m.print();
	
	return EXIT_SUCCESS;
}
