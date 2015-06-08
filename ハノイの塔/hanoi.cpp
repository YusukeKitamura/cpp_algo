/***********************************************************
	hanoi.cpp -- ƒnƒmƒC‚Ì“ƒ
***********************************************************/
#include "hanoi.h"
#include <iostream>

void movedisk(int n, int a, int b)
{
	if (n > 1)
		movedisk(n - 1, a, 6 - a - b);
		
	std::cout << "‰~”Õ " << n << " ‚ð " << a << " ‚©‚ç " << b << " ‚ÉˆÚ‚·" << std::endl;
	if (n > 1)
		movedisk(n - 1, 6 - a - b, b);
}
