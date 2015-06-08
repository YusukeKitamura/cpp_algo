/***********************************************************
	neville.h -- Neville (ネヴィル) 補間
***********************************************************/
#ifndef NEVILLE_H
#define NEVILLE_H

double neville(double t, double* x, double* y, int N);		//Neville (ネヴィル) 補間
double aitken(double t, double* x, double* y, int N);		//Aitken (エイトケン) 補間

#endif
