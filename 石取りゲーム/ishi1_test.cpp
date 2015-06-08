/***********************************************************
	ishi1_test.cpp -- Îæ‚èƒQ[ƒ€ 1
***********************************************************/
#include <cstdlib>
#include <iostream>
#include "ishi.h"

int main()
{
	int n, m;
	bool lose;

	std::cout << "ÅŒã‚ÉÎ‚ğæ‚Á‚½‘¤‚ª•‰‚¯‚Å‚·. ƒpƒX‚Í‚Å‚«‚Ü‚¹‚ñ." << std::endl;
	std::cout << "Î‚Ì”? " << std::endl;
	std::cin >> n;
	std::cout << "‚P‰ñ‚Éæ‚ê‚éÅ‘å‚ÌÎ‚Ì”? " << std::endl;
	std::cin >> m;
	if (n < 1 || m < 1) {
		std::cerr << "Î‚Ì”A‚P‰ñ‚Éæ‚ê‚é”‚Í‚PˆÈã‚Å‚·" << std::endl;
		return EXIT_FAILURE;
	}
	
	lose = ishi1(n, m);
	
	if (lose) std::cout << "‚ ‚È‚½‚Ì•‰‚¯‚Å‚·!" << std::endl;
	else     std::cout << "„‚Ì•‰‚¯‚Å‚·!" << std::endl;
	return EXIT_SUCCESS;
}
