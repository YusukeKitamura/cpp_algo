/***********************************************************
	swap_test.cpp -- �l�̌����@�e�X�g�p
***********************************************************/
#include "swap.h"
#include <iostream>
#include <cstdlib>

int main()
{
	std::cout << "�����ł̃e�X�g" << std::endl;
	int x, y;

	std::cout << "x = " << std::endl;
	std::cin >> x;
	std::cout << "y = " << std::endl;
	std::cin >> y;

	std::cout << "x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << "x = " << x << ", y = " << y << std::endl;
	swap1(&x, &y);
	std::cout << "x = " << x << ", y = " << y << std::endl;
	swap2(&x, &y);
	std::cout << "x = " << x << ", y = " << y << std::endl;

	std::cout << "�����ł̃e�X�g" << std::endl;
	double dx, dy;
	std::cout << "dx = " << std::endl;
	std::cin >> dx;
	std::cout << "dy = " << std::endl;
	std::cin >> dy;

	std::cout << "dx = " << dx << ", dy = " << dy << std::endl;
	swap(dx, dy);
	std::cout << "dx = " << dx << ", dy = " << dy << std::endl;
	
	return EXIT_SUCCESS;
}
