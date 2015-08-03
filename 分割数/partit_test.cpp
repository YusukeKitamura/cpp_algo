/***********************************************************
	partit_test.cpp -- 分割数　テスト用
***********************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "partit.h"

int main()
{
	for (int x = 1; x <= 20; x++)
		std::cout << std::setw(5) << x << "     " << std::setw(5) << partition(x) << std::endl;
	
	return EXIT_SUCCESS;
}
