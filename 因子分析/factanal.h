/***********************************************************
	factanal.h -- ���q����
***********************************************************/
#ifndef FACTANAL_H
#define FACTANAL_H
#include <iostream>
#include "statutil.h"     /* ���ϗʃf�[�^���̓��[�`�� */

const double EPS = 1E-6;  /* ��Ίp�����̋��e�덷 */
const int MAX_ITER = 100;   /* �ő�̌J�Ԃ��� */

class Factanal : public StatUtil {
public:
	Factanal();
	~Factanal();
	double house(int n, Vector& x);  // Householder�ϊ�
	void tridiagonalize(int n, Matrix& a, Vector& d, Vector& e); // 3�d�Ίp��
	int eigen(int n, Matrix& a, Vector& d, Vector& e);
	bool factor(int m, int nfac, Matrix r, Matrix q, Vector lambda, Vector work);

};

#endif
