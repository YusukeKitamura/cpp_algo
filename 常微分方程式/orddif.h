/***********************************************************
	orddif.h -- 常微分方程式
***********************************************************/
#ifndef ORDDIF_H
#define ORDDIF_H

double euler(int n, int nprint, double x0, double y0, double xn);  /* Euler法 */
double tayl3(int n, int nprint, double x0, double y0, double xn);  /* 3次Taylor級数 */
double runge4(int n, int nprint, double x0, double y0, double xn);  /* 4次Runge-Kutta法 */

#endif
