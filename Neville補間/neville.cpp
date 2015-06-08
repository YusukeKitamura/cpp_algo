/***********************************************************
	neville.cpp -- Neville (ƒlƒ”ƒBƒ‹) •âŠÔ
***********************************************************/
#include "neville.h"
#include <iostream>

double neville(double t, double* x, double* y, int N)
{
	double* w = new double[N];

	for (int i = 0; i < N; i++) {
		w[i] = y[i];
		for (int j = i - 1; j >= 0; j--) {
			w[j] = w[j + 1] + (w[j + 1] - w[j]) * (t - x[i]) / (x[i] - x[j]);
		}
	}
	
	double val = w[0];
	delete [] w;
	return val;
}

double aitken(double t, double* x, double* y, int N)
{
	double* w = new double[N];

	for (int i = 0; i < N; i++)
		w[i] = y[i];
		
	for (int j = 1; j < N; j++) {
		for (int k = N - 1; k >= j; k--) {
			w[k] = (w[k-1]*(x[k]-t) - w[k]*(x[k-j]-t)) / (x[k]-x[k-j]);
		}
	}
			
	double val = w[N - 1];
	delete [] w;
	return val;
}
