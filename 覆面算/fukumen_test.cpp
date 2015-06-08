/***********************************************************
	fukumen_test.cpp -- •¢–ÊŽZ
***********************************************************/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "fukumen.h"

int main()
{
	int n;
	std::cout << "s”? ";
	std::cin >> n;
	Fukumen fukumen(n);
	fukumen.set();
	
	fukumen.search(0, 0, 0);
	if (fukumen.solution == 0)
		std::cout << "‰ð‚Í‚ ‚è‚Ü‚¹‚ñ." << std::endl;
	return EXIT_SUCCESS;
}
