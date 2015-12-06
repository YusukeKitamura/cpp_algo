/***********************************************************
	fft_test.cpp -- FFT (高速Fourier変換)
***********************************************************/
#include "fft.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

const int N = 64;

int main(void)
{
	FFT fft(N);
	fft.make_sintbl();
	fft.make_bitrev();
	static double x1[N], y1[N], x2[N], y2[N], x3[N], y3[N];

	for (int i = 0; i < N; i++) {
		x1[i] = x2[i] = 6 * cos( 6 * PI * i / N)
					  + 4 * sin(18 * PI * i / N);
		y1[i] = y2[i] = 0;
	}
	
	fft.fft_run(x2, y2);
	for (int i = 0; i < N; i++) {
		x3[i] = x2[i];
		y3[i] = y2[i];
	}
	fft.ifft_run(x3, y3);
	std::cout << "      元のデータ    フーリエ変換  逆変換" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << std::setw(4) << i << " | " << std::fixed << std::setw(10) << x1[i] << " "
			 << y1[i] << " | " << x2[i] << " " << y2[i] << " | " << x3[i] << " " << y3[i] << std::endl;
	}
	return EXIT_SUCCESS;
}
