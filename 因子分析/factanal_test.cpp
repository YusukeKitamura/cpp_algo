/***********************************************************
	factanal_test.cpp -- ���q����
***********************************************************/
#include "factanal.h"

/*
  ���q���͂̃��C�����[�`��. �P�ɑ��֌W�������߂邾���ł��邪,
  �f�[�^����L���Ɉ�x�ɓǂݍ��ނ̂łȂ�,
  �Q�������g���ĕ���, ���U, ���֌W�����X�V������@��p���Ă���.
*/
int main(int argc, char *argv[])
{
	Factanal fact;
	int nfac;
	double t;

	if (argc != 2) {
		std::cerr << "�g�p�@: factanal filename" << std::endl;
		return EXIT_FAILURE;
	}
	
	int errval = fact.read_data(argv[1]);
	if (errval == 999) {
		std::cerr << "�f�[�^�ǂݍ��ݎ��s�I�I" << std::endl;
		return EXIT_FAILURE;  /* ���s */
	}
	
	Matrix r(fact.cols, fact.cols);		//���֌W��
	Matrix q(fact.cols, fact.cols);		//�ŗL�x�N�g��
	Vector mean(fact.cols);				//����
	Vector lambda(fact.cols);			//�ŗL�l
	Vector work(fact.cols);				//��Ɨp
	
	for (int j = 0; j < fact.cols; j++) {
		mean(j) = 0;
		for (int k = 0; k <= j; k++)
			r(j, k) = 0;
	}
	
	for (int i = 0; i < fact.rows; i++) {
		for (int j = 0; j < fact.cols; j++) {
			t = fact.mat(i, j);                          /* ���l���� */
			if (missing(t)) {
				std::cerr << "�f�[�^�s��" << std::endl;;           /* �����l���G���[ */
				return EXIT_FAILURE;
			}
			work(j) = t - mean(j); 
			mean(j) += work(j) / (i + 1);
			for (int k = 0; k <= j; k++)
				r(j, k) += i * work(j) * work(k) / (i + 1);
		}
	}
	
	for (int j = 0; j < fact.cols; j++) {
		work(j) = sqrt(r(j, j)); 
		r(j, j) = 1;
		for (int k = 0; k < j; k++) {
			r(j, k) /= work(j) * work(k); 
			r(k, j) = r(j, k);
		}
	}
	
	t = 1 / sqrt(fact.rows - 1.0);
	std::cout << "�ϐ�  ���ϒl        �W���΍�" << std::endl;
	for (int j = 0; j < fact.cols; j++) {
		std::cout << j + 1 << " " << mean(j) << " " << t * work(j) << std::endl;
	}
	
	std::cout << "���֌W��" << std::endl;                     /* �������������\�� */
	for (int j = 0; j < fact.cols; j++) {
		for (int k = 0; k <= j; k++)
			std::cout << r(j, k) << " ";
		std::cout << std::endl;
	}
	
	for ( ; ; ) {
		std::cout << std::endl;
		std::cout << "���ʈ��q�̐� (0:���s�I��) ? ";
		std::cin >> nfac;
		if (nfac > fact.cols)
			nfac = fact.cols;
		if (nfac < 1) break;
		fact.factor(fact.cols, nfac, r, q, lambda, work);
	}
	return EXIT_SUCCESS;
}
