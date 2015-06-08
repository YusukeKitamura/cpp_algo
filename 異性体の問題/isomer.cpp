/***********************************************************
	isomer.cpp -- ˆÙ«‘Ì‚Ì–â‘è
***********************************************************/
#include <cstdlib>
#include <iostream>
#include "isomer.h"

Isomer::Isomer()
{
	size = new long int[L];
	length = new long int[L];
	count = new long int[C + 1];
	for (int i = 0; i < C + 1; i++) {
		count[i] = 0;
	}
}

bool Isomer::calcCount() {
	int len, n, si, sj, sk, sh;

	n = size[0] = length[0] = 0;
	for (long int i = 0; i < L; i++) {
		len = length[i] + 1;
		if (len > C / 2)
			break;
			
		si = size[i] + 1;
		if (si + len > C)
			continue;
			
		for (int j = 0; j <= i; j++) {
			sj = si + size[j];
			if (sj + len > C)
				continue;
				
			for (int k = 0; k <= j; k++) {
				sk = sj + size[k];
				if (sk + len > C)
					continue;
				if (++n >= L)
					return false;
				size[n] = sk;
				length[n] = len;
			}
		}
	}
	
	std::cout << "len=" << len << ",n=" << n << std::endl;
	if (len <= C / 2)
		return false;
	
	for (int i = 0; i <= n; i++) {
		si = size[i];
		for (int j = 0; j <= i; j++) {
			if (length[i] != length[j])
				continue;
				
			sj = si + size[j];
			if (sj > C)
				continue;
			count[sj]++;  	// ‹ô”
			for (int k = 0; k <= j; k++) {
				sk = sj + size[k] + 1;
				if (sk > C)
					continue;
				for (int h = 0; h <= k; h++) {
					sh = sk + size[h];
					if (sh <= C) count[sh]++;  // Šï”
				}
			}
		}
	}
	
	return true;
}

Isomer::~Isomer()
{
	delete [] size;
	delete [] length;
	delete [] count;
}
