/***********************************************************
	egypfrac_test.cpp -- �G�W�v�g�̕���
***********************************************************/
#include "egypfrac.h"
#include <iostream>
#include <cstdlib>

int main()
{
	int m, n;

	std::cout << " ���q m = ";
	std::cin >> m;
	std::cout << " ���� n = ";
	std::cin >> n;
	
	std::cout << m << "/" << n << " = ";
	
	std::vector<int> v = egypfrac(m, n);
	for (std::size_t i = 0; i < v.size() - 1; i++) {
		std::cout << "1/" << v.at(i) << " + ";
	}
	std::cout << "1/" << v.at(v.size() - 1) << std::endl;
	
	return EXIT_SUCCESS;
}
