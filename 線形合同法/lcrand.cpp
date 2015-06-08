/***********************************************************
	lcrand.cpp -- üŒ`‡“¯–@
	http://ja.wikipedia.org/wiki/%E7%B7%9A%E5%BD%A2%E5%90%88%E5%90%8C%E6%B3%95
***********************************************************/
#include "lcrand.h"

LCRand::LCRand(unsigned long x) :
	seed(x)
{
}

unsigned long LCRand::irnd(void)
{
	seed = seed * 1566083941UL + 1;
	return seed;
}

double LCRand::rnd(void)  /* 0 <= rnd() < 1 */
{
	return (1.0 / (ULONG_MAX + 1.0)) * irnd();
}
