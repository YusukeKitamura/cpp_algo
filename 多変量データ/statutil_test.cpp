/***********************************************************
	statutil_test.cpp -- ���ϗʃf�[�^ �e�X�g
***********************************************************/
#include <iostream>
#include "matutil.h"
#include "statutil.h"

int main()
{
	StatUtil stat;
	int errval = stat.read_data("test.csv");
	if (errval == 999) {
		std::cerr << "�f�[�^�ǂݍ��ݎ��s�I�I" << std::endl;
		return EXIT_FAILURE;  /* ���s */
	}

	for (int i = 0; i < stat.rows; i++) {
		for (int j = 0; j < stat.cols; j++) {
			if (readerror(stat.mat(i, j) ))
				std::cout << "ERR,";  /* �Ǎ����s */
			else if (missing(stat.mat(i, j)))
				std::cout << "_,";  /* �����l */
			else
				std::cout << stat.mat(i, j) << ",";  /* ���� */
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}
