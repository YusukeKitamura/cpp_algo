/***********************************************************
	neville_test.cpp -- Neville (ネヴィル) 補間　テスト用
***********************************************************/
#include "neville.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

int main()
{
	const int N = 5;	// データ点の数
	double x[N] =  {   0,      10,     20,     30,     40   };
	double y[N] = { 610.66, 1227.4, 2338.1, 4244.9, 7381.2 };  // データ
	
	std::cout << "Nevile interpolation:" << std::endl;
	for (int i = 10; i <= 30; i++)
		std::cout << i << " " << neville((double)i, x, y, N) << std::endl;
	
	std::cout << "Aitken interpolation:" << std::endl;
	for (int i = 10; i <= 30; i++)
		std::cout << i << " " << aitken((double)i, x, y, N) << std::endl;
	return EXIT_SUCCESS;
}
