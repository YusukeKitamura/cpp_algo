/***********************************************************
	ishi2_test.c -- Îæ‚èƒQ[ƒ€ 2
***********************************************************/
#include <cstdlib>
#include <iostream>
#include "ishi.h"

int main()
{
	int n;
	bool win;

	std::cout << "Î‚Ì” (2..10000)? " << std::endl;
	std::cin >> n;
	if (n < 2 || n > 10000) {
		std::cerr << "Î‚Ì”‚Í‚QˆÈã‚P‚O‚O‚O‚OˆÈ‰º‚Å‚·" << std::endl;
		return EXIT_FAILURE;
	}
	
	win = ishi2(n);
	
	if (win) std::cout << "‚ ‚È‚½‚ÌŸ‚¿‚Å‚·!" << std::endl;
	else     std::cout << "„‚ÌŸ‚¿‚Å‚·!" << std::endl;
	return EXIT_SUCCESS;
}
