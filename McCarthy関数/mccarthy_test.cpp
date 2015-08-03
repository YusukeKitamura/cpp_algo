/***********************************************************
	mccarthy_test.cpp -- McCarthy (マッカーシー) 関数　テスト用
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "mccarthy.h"

int main()
{
	int x;

	for ( ; ; ) {
		std::cout << "0 以上 " << N << " 以下の整数 x: " << std::endl;
		std::cin >> x;
		if (x < 0) {
			std::cout << "0以上の数を入れて下さい";
			break;
		}
		
		std::cout << "McCarthy(x) = " << McCarthy(x) << std::endl;
		if (x > N)
			break;
	}
	return EXIT_SUCCESS;
}
