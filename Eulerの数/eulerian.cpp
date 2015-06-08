/***********************************************************
	eulerian.cpp -- Euler (ƒIƒCƒ‰[) ‚Ì”
	http://en.wikipedia.org/wiki/Eulerian_number
***********************************************************/
#include "eulerian.h"

/* n >= 0 */
int Eulerian::Run(int n, int k)
{
	if (k == 0) return 1;
	if (k < 0 || k >= n) return 0;
	return (k + 1) * Run(n - 1, k)
		 + (n - k) * Run(n - 1, k - 1);
}
