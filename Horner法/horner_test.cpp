/***********************************************************
	horner_test.cpp -- Horner (�z�[�i�[) �@�@�e�X�g�p
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "horner.h"

int main()
{
	static double a[5] = { 1, 2, 3, 4, 5 };

	std::cout << "f(2) = " <<  horner(4, a, 2) << std::endl;
	return EXIT_SUCCESS;
}
