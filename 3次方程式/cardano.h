/***********************************************************
	cardano.h -- 3次方程式
***********************************************************/
#ifndef CARDANO_H
#define CARDANO_H

#define CHECK
const double PI = 3.14159265358979323846264;  // 円周率

// 3乗根
double cuberoot(double x);
// ax^3 + bx^2 + cx + d = 0
void cardano(double a, double b, double c, double d);

#endif
