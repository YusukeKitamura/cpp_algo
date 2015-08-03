/***********************************************************
	collatz.h -- Collatz (コラッツ) の予想
***********************************************************/
#ifndef COLLATZ_H
#define COLLATZ_H

#include <climits>
#include <vector>

const long LIMIT =((ULONG_MAX - 1) / 3);
std::vector<unsigned long> collatz(unsigned long n);

#endif
