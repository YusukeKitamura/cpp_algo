/***********************************************************
	mccarthy_test.cpp -- McCarthy (�}�b�J�[�V�[) �֐��@�e�X�g�p
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "mccarthy.h"

int main()
{
	int x;

	for ( ; ; ) {
		std::cout << "0 �ȏ� " << N << " �ȉ��̐��� x: " << std::endl;
		std::cin >> x;
		if (x < 0) {
			std::cout << "0�ȏ�̐������ĉ�����";
			break;
		}
		
		std::cout << "McCarthy(x) = " << McCarthy(x) << std::endl;
		if (x > N)
			break;
	}
	return EXIT_SUCCESS;
}
