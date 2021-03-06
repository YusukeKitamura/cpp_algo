/***********************************************************
	ishi1_test.cpp -- 石取りゲーム 1
***********************************************************/
#include <cstdlib>
#include <iostream>
#include "ishi.h"

int main()
{
	int n, m;
	bool lose;

	std::cout << "最後に石を取った側が負けです. パスはできません." << std::endl;
	std::cout << "石の数? " << std::endl;
	std::cin >> n;
	std::cout << "１回に取れる最大の石の数? " << std::endl;
	std::cin >> m;
	if (n < 1 || m < 1) {
		std::cerr << "石の数、１回に取れる数は１以上です" << std::endl;
		return EXIT_FAILURE;
	}
	
	lose = ishi1(n, m);
	
	if (lose) std::cout << "あなたの負けです!" << std::endl;
	else     std::cout << "私の負けです!" << std::endl;
	return EXIT_SUCCESS;
}
