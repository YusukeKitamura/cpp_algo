/***********************************************************
	srchmat.h -- 2ŸŒ³‚Ì’Tõ
***********************************************************/
#ifndef SRCHMAT_H
#define SRCHMAT_H

#include <vector>
typedef std::vector<std::vector<int> > matrix;
bool searchmat(
	int x, matrix a,
	int imin, int imax,
	int jmin, int jmax,
	int *i, int *j);

#endif
