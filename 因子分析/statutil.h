/***********************************************************
	statutil.h -- 多変量データ
***********************************************************/
#ifndef STATUTIL_H
#define STATUTIL_H

#include "matutil.h"   /* 行列用の小道具集 */
#include <cerrno>     /* {\tt errno} */
#include <climits>    /* {\TT INT\_MAX} */
#include <cmath>      /* {\tt fabs()} */
#include <cstring>    /* {\tt strchr()} */
#include <string>    /* {\tt strchr()} */
#include <iostream>
#include <sstream>
#include <fstream>

const double READERROR = -1.00E+37;  /* 読込エラー */
const double MISSING  = -0.98E+37;  /* 欠測値 */

inline bool readerror(double x)
{
	return x < -0.99E+37;
}

inline bool missing(double x)
{
	return x < -0.97E+37;
}

class StatUtil
{
public:
	StatUtil();
	~StatUtil();
	int read_data(char* filename);
	//double getnum();

	std::ifstream datafile;
	int rows;
	int cols;
	Matrix mat;
	
};
#endif
