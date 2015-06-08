/***********************************************************
	lcrand.h -- üŒ`‡“¯–@
***********************************************************/
#ifndef LCRAND_H
#define LCRAND_H

#include <climits>

class LCRand {

public:
	LCRand(unsigned long x);
	double rnd(void);

private:
	unsigned long seed;
	unsigned long irnd(void);

};

#endif
