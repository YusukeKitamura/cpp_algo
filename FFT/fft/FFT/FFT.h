/***********************************************************
	fft.h -- FFT (高速Fourier変換)
***********************************************************/
#ifndef FFT_H
#define FFT_H

#include <vector>
const double PI = 3.14159265358979323846;

inline void swap(double &x, double &y)
{
	double temp;
	temp = x;
	x  = y;
	y = temp;
}

class FFT{
public:
	FFT(int n);
	void make_sintbl();
	void make_bitrev();
	void fft_run(double x[], double y[]);
	void ifft_run(double x[], double y[]);
	int size;
	
private:
	void fft_proc(double x[], double y[], bool inv);
	std::vector<int> bitrev;	// ビット反転表
	std::vector<double> sintbl;	// 三角関数表
};

#endif
