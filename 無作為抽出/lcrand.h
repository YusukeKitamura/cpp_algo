/***********************************************************
	lcrand.h -- 線形合同法
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
