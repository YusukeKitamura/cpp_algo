/***********************************************************
	hanoi.cpp -- �n�m�C�̓�
***********************************************************/
#include "hanoi.h"
#include <iostream>

void movedisk(int n, int a, int b)
{
	if (n > 1)
		movedisk(n - 1, a, 6 - a - b);
		
	std::cout << "�~�� " << n << " �� " << a << " ���� " << b << " �Ɉڂ�" << std::endl;
	if (n > 1)
		movedisk(n - 1, 6 - a - b, b);
}
