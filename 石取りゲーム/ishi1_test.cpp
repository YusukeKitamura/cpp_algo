/***********************************************************
	ishi1_test.cpp -- �Ύ��Q�[�� 1
***********************************************************/
#include <cstdlib>
#include <iostream>
#include "ishi.h"

int main()
{
	int n, m;
	bool lose;

	std::cout << "�Ō�ɐ΂���������������ł�. �p�X�͂ł��܂���." << std::endl;
	std::cout << "�΂̐�? " << std::endl;
	std::cin >> n;
	std::cout << "�P��Ɏ���ő�̐΂̐�? " << std::endl;
	std::cin >> m;
	if (n < 1 || m < 1) {
		std::cerr << "�΂̐��A�P��Ɏ��鐔�͂P�ȏ�ł�" << std::endl;
		return EXIT_FAILURE;
	}
	
	lose = ishi1(n, m);
	
	if (lose) std::cout << "���Ȃ��̕����ł�!" << std::endl;
	else     std::cout << "���̕����ł�!" << std::endl;
	return EXIT_SUCCESS;
}
