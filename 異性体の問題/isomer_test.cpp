/***********************************************************
	isomer_test.cpp -- �ِ��̖̂��
***********************************************************/
#include <cstdlib>
#include <iostream>
#include "isomer.h"

int main()
{
	Isomer isomer;
	isomer.calcCount();
	for (int i = 1; i <= C; i++)
		std::cout << "�Y�f���q�� " << i << " �̂��̂� " << isomer.count[i] << " ���" << std::endl;
	return EXIT_SUCCESS;
}
