/***********************************************************
	105_test.cpp -- �S�܌��Z�@�e�X�g�p
***********************************************************/
#include "105.h"
#include <iostream>
#include <cstdlib>

int main()
{
	int a, b, c, x;

	std::cout << "1 ���� 100 �܂ł̐������P�l���Ă�������" << std::endl;
	std::cout <<"����� 3 �Ŋ������]��? ";
	std::cin >> a;
	std::cout <<"����� 5 �Ŋ������]��? ";
	std::cin >> b;
	std::cout <<"����� 7 �Ŋ������]��? ";
	std::cin >> c;
	
	x = (70 * a + 21 * b + 15 * c) % 105;
	std::cout << "���Ȃ��̍l��������" <<  x << "�ł��傤!" << std::endl;
	return EXIT_SUCCESS;
}
