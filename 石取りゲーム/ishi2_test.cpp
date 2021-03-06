/***********************************************************
	ishi2_test.c -- 石取りゲーム 2
***********************************************************/
#include <cstdlib>
#include <iostream>
#include "ishi.h"

int main()
{
	int n;
	bool win;

	std::cout << "石の数 (2..10000)? " << std::endl;
	std::cin >> n;
	if (n < 2 || n > 10000) {
		std::cerr << "石の数は２以上１００００以下です" << std::endl;
		return EXIT_FAILURE;
	}
	
	win = ishi2(n);
	
	if (win) std::cout << "あなたの勝ちです!" << std::endl;
	else     std::cout << "私の勝ちです!" << std::endl;
	return EXIT_SUCCESS;
}
