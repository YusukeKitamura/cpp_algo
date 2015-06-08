/***********************************************************
	radconv_test.cpp -- 基数の変換　テスト用
***********************************************************/
#include "radconv.h"
#include <iostream>
#include <cstdlib>

const int M = 1000;

int main()
{
	int x, m1, m2;
	int *x1 = new int[M];
	int *x2 = new int[M];

	std::cout << "x = ";
	std::cin >> x;

	m1 = conv1(x, 8, M, x1);
	if (m1 < 0) {
		std::cerr << "conv1: error" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "8進(octal): ";
	for (int i = m1 - 1; i >= 0; i--) 
		std::cout << x1[i];
	std::cout << std::endl;
	
	m2 = conv2(8, m1, x1, 2, M, x2);
	if (m1 < 0) {
		std::cerr << "conv2: error" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "2進(binary): ";
	for (int i = m2 - 1; i >= 0; i--)
		std::cout << x2[i];
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
