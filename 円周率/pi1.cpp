/***********************************************************
	pi1.cpp -- ‰~Žü—¦
***********************************************************/
#include "pi.h"

/* Machin‚ÌŒöŽ® */
long double pi1(void)
{
	int k;
	long double p, t, last;

	p = 0;
	k = 1;
	t = 16.0L / 5.0L;
	do {
		last = p;
		p += t / k;
		t /= -5.0L*5.0L;
		k += 2;
	} while (p != last);
	
	k = 1;
	t = 4.0L / 239.0L;
	do {
		last = p;
		p -= t / k;
		//t /= -239.0L*239.0L;
		t /= -239.0*239.0;
		k += 2;
	} while (p != last);
	
	return p;
}
