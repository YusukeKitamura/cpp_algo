/**************************************************************
    bisect.cpp -- 2分法
**************************************************************/
#include "bisect.h"

double bisect(
    double a,
    double b,
    double tolerance,
    std::function<double(double)> f,
    std::string &error
) {
    double c, fa, fb, fc;

    error = "";
    if (tolerance < 0) tolerance = 0;
    if (b < a) {
        c = a;
        a = b;
        b = c;
    }
    fa = f(a);
    if (fa == 0) return a;

    fb = f(b);
    if (fb == 0) return b;
    if (samesign(fa, fb)) {
        error = "区間の両端で関数値が同符号です.";
        return 0;
    }
    for ( ; ; ) {
        c = (a + b) / 2;
        if (c - a <= tolerance || b - c <= tolerance) break;
        fc = f(c);
        if (fc == 0) return c;
        if (samesign<double>(fc, fa)) {
            a = c;
            fa = fc;
        } else {
            b = c;
            fb = fc;
        }
    }
    return c;
}
