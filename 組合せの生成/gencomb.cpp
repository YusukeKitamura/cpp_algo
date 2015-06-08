/***********************************************************
	gencomb.cpp -- ‘g‡‚¹‚Ì¶¬
***********************************************************/
#include "gencomb.h"
#include <iostream>

Gencomb::Gencomb()
{
}

unsigned int Gencomb::first(unsigned int n)
{
	return (1U << n) - 1U;
}

unsigned int Gencomb::nextset(unsigned int x)
{
	unsigned int smallest, ripple, new_smallest, ones;

	smallest = x & -x;
	ripple = x + smallest;
	new_smallest = ripple & -ripple;
	ones = ((new_smallest / smallest) >> 1) - 1;
	return ripple | ones;
}

void Gencomb::printset(unsigned int s, unsigned int N)
{
	for (int i = 1; i <= N; i++) {
		if (s & 1) std::cout << " " << i ;
		s >>= 1;
	}
	std::cout << std::endl;;
}
