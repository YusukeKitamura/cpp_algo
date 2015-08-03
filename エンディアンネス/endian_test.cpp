/***********************************************************
	endian_test.cpp -- エンディアンネス
***********************************************************/
#include "endian.h"
#include <iostream>
#include <cstdlib>

int main()
{
	int n = endian();
	switch (n) {
		case LITTLE:
			std::cout << "little-endian" << std::endl;
			break;
		case BIG:
			std::cout << "big-endian" << std::endl;
			break;
		default:
			std::cout << "不明" << std::endl;
			break;
	}
			
	return EXIT_SUCCESS;
}
