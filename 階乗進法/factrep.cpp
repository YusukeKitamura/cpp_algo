/***********************************************************
	factrep.cpp -- �K��i�@
***********************************************************/
#include <vector>
#include <iostream>
#include "factrep.h"

// 0 ���� (n + 1)! - 1 �܂ł̐������K��i�@�ŏ����o��
void factrep(int n)
{
	std::vector<int> c(n + 2, 0);		// c[N+1] �͔Ԑl
	int k;

	int i = 0;
	do {
		std::cout << i << ":";
		i++;
		for (k = n; k >= 1; k--) {
			std::cout << " " << c.at(k);
		}
		std::cout << std::endl;
		
		k = 1;
		while (c.at(k) == k) {
			c.at(k)= 0;
			k++;
		}
		c.at(k)++;
	} while (k <= n);
	
}
