/***********************************************************
	ccurve.h -- Cã»ê¸
***********************************************************/
#ifndef CCURVE_H
#define CCURVE_H

#include "plotter.h"

class Ccurve : public Plotter
{
public:
	Ccurve();
	void Init(int i);
	void run(int i, double dx, double dy);
	int getOrder();
	double getDx();
	double getDy();

private:
	int order;
	double dx1;
	double dy1;

};

#endif
