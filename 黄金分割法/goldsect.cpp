/***********************************************************
	goldsect.cpp -- ‰©‹à•ªŠ„–@
***********************************************************/
#include "goldsect.h"

GoldSect::GoldSect()
{
}

double GoldSect::minimize(double a, double b,
				double tolerance, double (*f)(double x))
{
	double c, d, fc, fd, t;

	if (a > b) { 
		t = a;
		a = b;
		b = t; 
	}
	t = r * (b - a);
	c = a + t;
	d = b - t;
	fc = f(c);
	fd = f(d);
	for ( ; ; ) {
		if (fc > fd) {
			a = c;
			c = d;
			fc = fd;
			d = b - r * (b - a);
			if (d - c <= tolerance)
				return c;
			fd = f(d);
		} else {
			b = d;
			d = c;
			fd = fc;
			c = a + r * (b - a);
			if (d - c <= tolerance)
				return d;
			fc = f(c);
		}
	}
}
