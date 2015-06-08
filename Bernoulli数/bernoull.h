/***********************************************************
	bernoull.h -- Bernoulli (�x���k�[�C) ��
***********************************************************/
#ifndef BERNOULL_H
#define BERNOULL_H
#include <cmath>
#include <cfloat>

double gcd(double x, double y);  /* �ő���� */
class Bernoull{
public:
	Bernoull();
	double run(int n);
	int denominator;
	int numerator;
};

#endif