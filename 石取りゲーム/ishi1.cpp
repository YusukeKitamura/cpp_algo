/***********************************************************
	ishi1.cpp -- �Ύ��Q�[�� 1
***********************************************************/
#include <iostream>
#include "ishi.h"

bool ishi1(int n, int m)
{
	int x;
	bool my_turn = true;

	do {
		if (my_turn) {
			x = (n - 1) % (m + 1); 
			if (x == 0) x = 1;
			std::cout << "���� " << x << " �̐΂����܂��B" << std::endl;
		} else do {
			std::cout << "�����܂���? " << std::endl;
			std::cin >> x;
		} while (x <= 0 || x > m || x > n);
		n -= x; 
		std::cout << "�c���" <<  n << " �ł�." << std::endl;
		my_turn = !my_turn;
	} while(n != 0);
	
	return my_turn;
}
