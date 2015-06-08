/***********************************************************
	fukumen_test.cpp -- 覆面算
***********************************************************/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "fukumen.h"

int main()
{
	int n;
	std::cout << "行数? ";
	std::cin >> n;
	Fukumen fukumen(n);
	fukumen.set();
	
	fukumen.search(0, 0, 0);
	if (fukumen.solution == 0)
		std::cout << "解はありません." << std::endl;
	return EXIT_SUCCESS;
}
