/***********************************************************
	collatz_test.cpp -- Collatz (コラッツ) の予想　テスト用
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "collatz.h"

int main()
{
	unsigned long n;
	
	std::cout << "n = ";
	std::cin >> n;
	
	std::vector<unsigned long> vec = collatz(n);
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec.at(i) << " ";
	}
	
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
