#ifndef CRYPT_H
#define CRYPT_H
/***********************************************************
	crypt.h -- ƒo[ƒiƒ€ˆÃ†
***********************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

class Crypt {

public:
	static bool run(char* input, char* output, int seed);
};

#endif
