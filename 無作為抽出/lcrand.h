/***********************************************************
	lcrand.h -- üŒ`‡“¯–@
***********************************************************/
#include <climits>

class LCRand {

public:
	LCRand(unsigned long x);
	double rnd(void);

private:
	unsigned long seed;
	unsigned long irnd(void);

};
