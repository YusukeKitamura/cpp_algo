/***********************************************************
	marriage_test.cpp -- ����Ȍ����̖��@�e�X�g�p
***********************************************************/
#include "marriage.h"
#include <cstdlib>

const int N = 3;

int main()
{
	Marriage m(N);

	for (int g = 1; g <= N; g++) {  /* �e�����̍D�� */
		m.setGirl(g);
	}
	for (int b = 1; b <= N; b++) {  /* �e�j���̍D�� */
		m.setBoy(b);
	}
	
	m.calc();
	m.print();
	
	return EXIT_SUCCESS;
}
