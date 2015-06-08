/***********************************************************
	fib_test.cpp -- Fibonacci (フィボナッチ) 数列　テスト用
***********************************************************/
#include "fib.h"
#include <iostream>
#include <cstdlib.>

int main()
{
	for (int i = 1; i <= 11; i++) {
		unsigned long fib_1 = Fib::fib1(i);
		std::cout << fib_1 << " ";
	}
	std::cout << std::endl;
	
	for (int i = 1; i <= 11; i++) {
		unsigned long fib_2 = Fib::fib2(i);
		std::cout << fib_2 << " ";
	}
	std::cout << std::endl;

	for (int i = 1; i <= 11; i++) {
		unsigned long fib_3 = Fib::fib3(i);
		std::cout << fib_3 << " ";
	}
	std::cout << std::endl;
	
	for (int i = 1; i <= 11; i++) {
		unsigned long fib_4 = Fib::fib4(i);
		std::cout << fib_4 << " ";
	}

	return EXIT_SUCCESS;
}
