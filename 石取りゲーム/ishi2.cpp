/***********************************************************
	ishi2.cpp -- 石取りゲーム 2
***********************************************************/
#include <iostream>
#include "ishi.h"

bool ishi2(int n) {
	int max, x;
	int f[21];
	bool my_turn = true;

	f[1] = f[2] = 1;
	for (int i = 3; i <= 20; i++)
		f[i] = f[i - 1] + f[i - 2];
	
	max = n - 1;
	
	do {
		std::cout << max << " 個まで取れます." << std::endl;
		if (my_turn) {
			x = n;
			for (int i = 20; x != f[i]; i--) {
				if (x > f[i])
					x -= f[i];
			}
			if (x > max) x = 1;
			std::cout << "私は " << x << " 個の石をとります." << std::endl;
		} else do {
			std::cout << "何個とりますか? " << std::endl;
			std::cin >> x;
		} while (x < 1 || x > max);
		n -= x;
		max = 2 * x;
		if (max > n) max = n;
		std::cout << "残りは" <<  n << " 個です." << std::endl;
		my_turn = !my_turn;
	} while(n != 0);
	
	return my_turn;
}
