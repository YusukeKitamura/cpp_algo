/***********************************************************
	e_test.cpp -- ���R�ΐ��̒�@�e�X�g
***********************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "e.h"

int main()
{
	std::cout << "e = " << std::setprecision(18) << ee() << std::endl;
	return EXIT_SUCCESS;
}
