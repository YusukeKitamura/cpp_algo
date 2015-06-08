/***********************************************************
	komachi.cpp -- è¨í¨éZ
***********************************************************/
#include <iostream>
#include "komachi.h"

void komachi()
{
	int s, sign[10];
	long n, x;

	for (int i = 1; i <= 9; i++)
		sign[i] = -1;
	
	do {
		x = n = 0;
		s = 1;
		for (int i = 1; i <= 9; i++)
			if (sign[i] == 0) n = 10 * n + i;
			else {
				x += s * n;
				s = sign[i];
				n = i;
			}
		x += s * n;
		if (x == 100) {
			for (int i = 1; i <= 9; i++) {
				if      (sign[i] ==  1) std::cout << " + ";
				else if (sign[i] == -1) std::cout << " - ";
				std::cout <<  i;
			}
			std::cout << " = 100" << std::endl;
		}
		int i = 9;
		s = sign[i] + 1;
		while (s > 1) {
			sign[i] = -1;
			i--;
			s = sign[i] + 1;
		}
		sign[i] = s;
	} while (sign[1] < 1);
}
