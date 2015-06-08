/***********************************************************
	roundoff.cpp -- lÌŒÜ“ü
	a/b‚ğ¬”‘æ‚RˆÊ‚ÅlÌŒÜ“ü
***********************************************************/
#include <climits>
#include "roundoff.h"

//0 <= a <= b, b != 0
unsigned int round1000(unsigned long a, unsigned long b)
{
	unsigned int d;
	unsigned long bl, bh, rp, rm;

	if (a <= ULONG_MAX / 2000) {
		d = (unsigned int)(a * 2000 / b);
	} else {
		bl = b % 2000;
		bh = b / 2000;
		d = (unsigned int)(a / bh);
		rp = (a % bh) * 2000;
		rm = bl * d;
		if (rp < rm) {
			d--;
			rm-= rp;
			while (rm > b) {
				d--;
				rm-= b; 
			}
		}
	}
	return (d + 1) / 2;
}
