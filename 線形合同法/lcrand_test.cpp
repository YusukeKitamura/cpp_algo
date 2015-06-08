/***********************************************************
	lcrand_test.cpp -- ���`�����@ �e�X�g�p�v���O����
***********************************************************/
#include "lcrand.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>

int main(int argc, char *argv[])
{
	if (argc <= 1) {
		std::cout << "�����ɗ����̎�i�����j��^���Ă�������" << std::endl;
		return EXIT_FAILURE;
	}
	
	unsigned long seed = atoi(argv[1]);
	LCRand lcr(seed);  /* �C�ӂ� unsigned long �ŏ�����. */
	for (int i = 0; i < 80; i++) {
		double data = lcr.rnd();
		std::cout << std::setw(9) << std::setprecision(6) << data << " ";
		if (i % 10 == 9) std::cout << std::endl;
	}
		
	return EXIT_SUCCESS;
}
