/***********************************************************
	isomer_test.cpp -- ˆÙ«‘Ì‚Ì–â‘è
***********************************************************/
#include <cstdlib>
#include <iostream>
#include "isomer.h"

int main()
{
	Isomer isomer;
	isomer.calcCount();
	for (int i = 1; i <= C; i++)
		std::cout << "’Y‘fŒ´q‚ª " << i << " ŒÂ‚Ì‚à‚Ì‚Í " << isomer.count[i] << " í—Ş" << std::endl;
	return EXIT_SUCCESS;
}
