/***********************************************************
	hanoi_test.cpp -- ハノイの塔　テスト用
***********************************************************/
#include "hanoi.h"
#include <iostream>
#include <cstdlib>

int main()
{
	int n;

	std::cout << "円盤の枚数? "; 
	std::cin >> n;
	
	std::cout << "円盤 " << n << " 枚を柱 1 から柱 2 に移す方法は";
	std::cout << "次の " << (1UL << n) - 1 << " 手です." << std::endl;
	
	movedisk(n, 1, 2);
	return EXIT_SUCCESS;
}
