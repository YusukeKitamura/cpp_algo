/***********************************************************
	orddif.h -- �����������
***********************************************************/
#ifndef ORDDIF_H
#define ORDDIF_H

double euler(int n, int nprint, double x0, double y0, double xn);  /* Euler�@ */
double tayl3(int n, int nprint, double x0, double y0, double xn);  /* 3��Taylor���� */
double runge4(int n, int nprint, double x0, double y0, double xn);  /* 4��Runge-Kutta�@ */

#endif
