/***********************************************************
	bifur.cpp -- カオスとアトラクタ
***********************************************************/
#include "bifur.h"
#include <GL/glut.h>

Bifur::Bifur() :
	kmin(0.0),
	kmax(1.0),
	pmin(0.0),
	pmax(1.0)
{
}


void Bifur::Init(double k_min, double k_max, double p_min, double p_max)
{
	kmin = k_min;
	kmax = k_max;
	pmin = p_min;
	pmax = p_max;
}

void Bifur::Draw()
{
	double dk = (kmax - kmin) / (XMAX - 1);
	for (double k = kmin; k <= kmax; k += dk) {
		double p = 0.3;
		for (int i = 1; i <= 50; i++)
			p += k * p * (1 - p);
		for (int i = 51; i <= 100; i++) {
			if (p >= pmin && p <= pmax){
				//gr_wdot(k*(2*(kmax - kmin)-1), p*(2*(pmax-pmin)-1), WHITE);
				gr_wdot(k*(2*(kmax - kmin)-1), p*(2*(pmax-pmin)-1), 7);
			}
			p += k * p * (1 - p);
		}
	}
}
