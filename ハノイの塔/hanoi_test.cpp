/***********************************************************
	hanoi_test.cpp -- �n�m�C�̓��@�e�X�g�p
***********************************************************/
#include "hanoi.h"
#include <iostream>
#include <cstdlib>

int main()
{
	int n;

	std::cout << "�~�Ղ̖���? "; 
	std::cin >> n;
	
	std::cout << "�~�� " << n << " ���� 1 ���璌 2 �Ɉڂ����@��";
	std::cout << "���� " << (1UL << n) - 1 << " ��ł�." << std::endl;
	
	movedisk(n, 1, 2);
	return EXIT_SUCCESS;
}
