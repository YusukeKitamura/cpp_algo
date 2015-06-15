/***********************************************************
	egypfrac_test.cpp -- エジプトの分数
***********************************************************/
#include "egypfrac.h"
#include <iostream>
#include <cstdlib>

int main()
{
	int m, n;

	std::cout << " 分子 m = ";
	std::cin >> m;
	std::cout << " 分母 n = ";
	std::cin >> n;
	
	std::cout << m << "/" << n << " = ";
	
	std::vector<int> v = egypfrac(m, n);
	for (std::size_t i = 0; i < v.size() - 1; i++) {
		std::cout << "1/" << v.at(i) << " + ";
	}
	std::cout << "1/" << v.at(v.size() - 1) << std::endl;
	
	return EXIT_SUCCESS;
}
