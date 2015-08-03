/***********************************************************
	endian.cpp -- �G���f�B�A���l�X
***********************************************************/
#include "endian.h"

int endian()
{
	int i = 1;
	if (*((char *)&i))
		return LITTLE;
	else if (*((char *)&i + (sizeof(int) - 1)))
		return BIG;
	else
		return UNKNOWN;
		
}
