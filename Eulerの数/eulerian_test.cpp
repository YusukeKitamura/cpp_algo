/***********************************************************
	eulerian_test.cpp -- Euler (�I�C���[) �̐��@�e�X�g�p
***********************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "eulerian.h"

const int MaxVal = 9;

int main()
{
	int n, k;

	std::cout << "  k";
	for (k = 0; k <= MaxVal; k++)
		std::cout << std::setw(7) << k;
		
	std::cout << std::endl;
	std::cout << "n  ";
	
	for (k = 0; k <= MaxVal; k++)
		std::cout << "-------";
		
	std::cout << std::endl;
	for (n = 0; n <= MaxVal; n++) {
		std::cout << n << " |";
		for (k = 0; k <= n; k++) {
			int eul = Eulerian::Run(n, k);
			std::cout << std::setw(7) << eul;
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}
