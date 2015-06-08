/***********************************************************
	maxmin_test.cpp -- 最大値・最小値　テスト用
***********************************************************/
#include "maxmin.h"
//#include "maxmin.cpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	// 整数
	int max, min;
	static int a[] = { 1, 7, 4 };

	std::cout << "max2(1, 7) = "<< max2<int>(1, 7) << std::endl;
	std::cout << "min2(1, 7) = "<< min2<int>(1, 7) << std::endl;

	std::cout << "a[] = { 1, 7, 4 }" << std::endl;
	std::cout << "findmax(3, a) = "<< findmax<int>(3, a) << std::endl;
	std::cout << "findmin(3, a) = "<< findmin<int>(3, a) << std::endl;

	findmaxmin<int>(3, a, &max, &min);
	std::cout << "findmaxmin(3, a, &max, &min)" << std::endl;
	std::cout << "max = " << max << " min =" << min << std::endl;

	std::cout << "maxn(3, 1, 7, 4) = "<< maxn<int>(3, 1, 7, 4) << std::endl;
	std::cout << "minn(3, 1, 7, 4) = "<< minn<int>(3, 1, 7, 4) << std::endl;

	// 浮動小数点型
	double maxf, minf;
	static double b[] = { 23.1, 11.4, 19.2 };

	std::cout << "max2(4.4, 2.7) = " << max2<double>(4.4, 2.7) << std::endl;
	std::cout << "min2(4.4, 2.7) = " << min2<double>(4.4, 2.7) << std::endl;

	std::cout << "b[] = { 23.1, 11.4, 19.2}" << std::endl;
	std::cout << "findmax(3, b) = "<< findmax<double>(3, b) << std::endl;
	std::cout << "findmin(3, b) = "<< findmin<double>(3, b) << std::endl;

	findmaxmin<double>(3, b, &maxf, &minf);
	std::cout << "findmaxmin(3, b, &max, &min)" << std::endl;
	std::cout << "max = " << maxf << " min =" << minf << std::endl;

	//うまくいかない
	//std::cout << "maxn(4.3, 11.1, 2.7, 9.4) = " << maxn<double>(4.3, 11.1, 2.7, 9.4) << std::endl;
	//std::cout << "minn(4.3, 11.1, 2.7, 9.4) = "<< minn<double>(4.3, 11.1, 2.7, 9.4) << std::endl;
	
	return EXIT_SUCCESS;
}
