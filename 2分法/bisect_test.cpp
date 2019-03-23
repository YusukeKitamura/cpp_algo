/**************************************************************
    bisect_test.cpp -- 2分法 テスト用
**************************************************************/
#include "bisect.h"

double func(double x) {
    return x * x - 2;
}

int main(void)  /* テスト */
{
    std::string error;
    //ゼロ点を求める関数
    std::function<double(double)> f = func;

    double val = bisect(1, 2, 0, f, error);  /* 1 < val < 2 の間で解を求める */
    if (error.size() > 0) std::cout << error << std::endl;
    else std::cout << val << std::endl;
    return 0;
}
