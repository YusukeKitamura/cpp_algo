/***********************************************************
	105_test.cpp -- 百五減算　テスト
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "105.h"

int main()
{
	int a, b, c, x;

	std::cout << "1 から 100 までの整数を１つ考えてください。" << std::endl;
	std::cout << "それを 3 で割った余り? ";
	std::cin >> a;
	std::cout << "それを 5 で割った余り? ";
	std::cin >> b;
	std::cout << "それを 7 で割った余り? ";
	std::cin >> c;
	
	x = hyakugo(a, b, c);
	std::cout << "あなたの考えた数は " << x << " でしょう!" << std::endl;
	return EXIT_SUCCESS;
}
