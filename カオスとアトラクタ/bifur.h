/***********************************************************
	bifur.h -- カオスとアトラクタ
***********************************************************/
#ifndef BIFUR_H
#define BIFUR_H
#include "window.h"

class Bifur : public Window{
public:
	Bifur();
	void Init(double k_min, double k_max, double p_min, double p_max);
	void Draw();
	double kmin;
	double kmax;
	double pmin;
	double pmax;
};

#endif
