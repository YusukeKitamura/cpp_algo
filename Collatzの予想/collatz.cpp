/***********************************************************
	collatz.cpp -- Collatz (コラッツ) の予想
***********************************************************/
#include <iostream>
#include "collatz.h"

std::vector<unsigned long> collatz(unsigned long n)
{
	std::vector<unsigned long> vec;
	vec.push_back(n);
	while (n > 1) {
		if (n & 1) {  // 奇数
			if (n > LIMIT) {
				std::cout << "Overflow" << std::endl;
				return vec;
			} else n = 3 * n + 1;
		} else n /= 2;
		vec.push_back(n);
	}
	
	return vec;
}
