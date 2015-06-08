/***********************************************************
	ccurve.cpp -- Cã»ê¸
***********************************************************/
#include "ccurve.h"

Ccurve::Ccurve():
	order(1),
	dx1(-0.5),
	dy1(-0.5)
{
}

void Ccurve::Init(int i)
{
	order = i;
	move(0.5, 0.5);
}

int Ccurve::getOrder()
{
	return order;
}

double Ccurve::getDx()
{
	return dx1;
}

double Ccurve::getDy()
{
	return dy1;
}

void Ccurve::run(int i, double dx, double dy)
{
	if (i == 0) draw_rel(dx, dy);
	else {
		run(i - 1, (dx + dy) / 2, (dy - dx) / 2);
		run(i - 1, (dx - dy) / 2, (dy + dx) / 2);
	}
}
