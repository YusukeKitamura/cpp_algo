/***********************************************************
	ishi2_test.c -- �Ύ��Q�[�� 2
***********************************************************/
#include <cstdlib>
#include <iostream>
#include "ishi.h"

int main()
{
	int n;
	bool win;

	std::cout << "�΂̐� (2..10000)? " << std::endl;
	std::cin >> n;
	if (n < 2 || n > 10000) {
		std::cerr << "�΂̐��͂Q�ȏ�P�O�O�O�O�ȉ��ł�" << std::endl;
		return EXIT_FAILURE;
	}
	
	win = ishi2(n);
	
	if (win) std::cout << "���Ȃ��̏����ł�!" << std::endl;
	else     std::cout << "���̏����ł�!" << std::endl;
	return EXIT_SUCCESS;
}
