/***********************************************************
	srchmat_test.cpp -- 2次元の探索 テスト用
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "srchmat.h"

int main()
{
	int i, j, x;
	//C++11でコンパイルする必要あり
	std::vector<int> a1{1, 2, 3, 4};
	std::vector<int> a2{2, 4, 6, 8};
	std::vector<int> a3{3, 6, 9, 12};
	matrix a{a1, a2, a3};

	std::cout << "    1  2  3  4" << std::endl;
	std::cout << "A = 2  4  6  8  (i = 0, 1, 2; j = 0, 1, 2, 3)" << std::endl;
	std::cout << "    3  6  9 12" << std::endl;
	std::cout << "? " << std::endl;
	std::cin >> x;

	if (searchmat(x, a, 0, 2, 0, 3, &i, &j) == true)
		std::cout << "(i, j) = (" << i << ", " << j << ")" << std::endl;
	else
		std::cout << "Not found." << std::endl;
	return EXIT_SUCCESS;
}
