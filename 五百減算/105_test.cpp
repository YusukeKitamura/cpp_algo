/***********************************************************
	105_test.cpp -- �S�܌��Z�@�e�X�g
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "105.h"

int main()
{
	int a, b, c, x;

	std::cout << "1 ���� 100 �܂ł̐������P�l���Ă��������B" << std::endl;
	std::cout << "����� 3 �Ŋ������]��? ";
	std::cin >> a;
	std::cout << "����� 5 �Ŋ������]��? ";
	std::cin >> b;
	std::cout << "����� 7 �Ŋ������]��? ";
	std::cin >> c;
	
	x = hyakugo(a, b, c);
	std::cout << "���Ȃ��̍l�������� " << x << " �ł��傤!" << std::endl;
	return EXIT_SUCCESS;
}
