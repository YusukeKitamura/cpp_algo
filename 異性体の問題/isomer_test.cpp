/***********************************************************
	isomer_test.cpp -- 異性体の問題
***********************************************************/
#include <cstdlib>
#include <iostream>
#include "isomer.h"

int main()
{
	Isomer isomer;
	isomer.calcCount();
	for (int i = 1; i <= C; i++)
		std::cout << "炭素原子が " << i << " 個のものは " << isomer.count[i] << " 種類" << std::endl;
	return EXIT_SUCCESS;
}
