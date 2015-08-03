/***********************************************************
	mccarthy.cpp -- McCarthy (マッカーシー) 関数
***********************************************************/
#include "mccarthy.h"

int McCarthy(int x)
{
	if (x > N)
		return x - 10;
	
	// else
	return McCarthy(McCarthy(x + 11));
}
