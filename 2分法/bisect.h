/**************************************************************
    bisect.h -- 2分法
**************************************************************/
#ifndef BISECT_H
#define BISECT_H
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <functional>   // C++11以降

//同符号なら真
template<typename T>
inline T samesign(T x, T y)
{
    return ((x) > 0) == ((y) > 0);
}

double bisect(
    double a,
    double b,
    double tolerance,
    std::function<double(double)> f,
    std::string &error
);

#endif
