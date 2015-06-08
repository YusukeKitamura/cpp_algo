/***********************************************************
	matutil_test.cpp -- 行列
	行列操作の小道具集　テスト用
***********************************************************/
#include <iostream>
#include <valarray>
#include "matutil.h"

int main()
{
    Matrix a(3, 4);             // 3×4 行列
    for (size_t i = 0; i < a.nrow(); i++)
        for (size_t j = 0; j < a.ncol(); j++)
            a(i, j) = i * 10 + j + 11;
			
	std::cout << "Matrix a:" << std::endl;
    matprint(a);                // 出力
    Matrix b;                   // 名前だけ確保
    b = a;                      // 代入
	std::cout << "Matrix b:" << std::endl;
    matprint(b);                // 出力
	
	Matrix ab = a + b;
	std::cout << "Matrix ab:" << std::endl;
    matprint(ab);                // 出力
	
	Vector c(4);
	Vector d(4);
    for (size_t i = 0; i < c.length(); i++) {
		c(i) = 2 * i + 3;
		d(i) = 3 * i + 4;
	}
	std::cout << "Vector c:" << std::endl;
	vecprint(c);
	std::cout << "Vector d:" << std::endl;
	vecprint(d);
	double ip = innerproduct(c, d);
	std::cout << "innerproduct(c,d)=" << ip << std::endl;
	
	Vector f = a(2);
	std::cout << "Vector f:" << std::endl;
	std::cout << "length:" << f.length() <<  std::endl;
	vecprint(f);
}
