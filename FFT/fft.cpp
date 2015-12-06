/***********************************************************
	fft.cpp -- FFT (高速Fourier変換)
***********************************************************/
#include "fft.h"
#include <cmath>

FFT::FFT(int n):
	size(n)
{
	sintbl.resize(n + n/4);
	bitrev.resize(n);
}

/*
  関数{\tt fft()}の下請けとして三角関数表を作る.
*/
void FFT::make_sintbl()
{
	int n2, n4, n8;
	double c, s, dc, ds, t;

	n2 = size / 2;
	n4 = size / 4;
	n8 = size / 8;
	t = sin(PI / size);
	dc = 2 * t * t;
	ds = sqrt(dc * (2 - dc));
	t = 2 * dc;
	
	c = 1;
	s = 0;
	sintbl.at(n4) = c;
	sintbl.at(0) = s;
	for (int i = 1; i < n8; i++) {
		c -= dc;
		dc += t * c;
		s += ds;
		ds -= t * s;
		sintbl.at(i) = s;
		sintbl.at(n4 - i) = c;
	}
	if (n8 != 0) {
		sintbl.at(n8) = sqrt(0.5);
	}
	for (int i = 0; i < n4; i++) {
		sintbl.at(n2 - i) = sintbl.at(i);
	}
	for (int i = 0; i < n2 + n4; i++) {
		sintbl.at(i + n2) = - sintbl.at(i);
	}
}

/*
  関数{\tt fft()}の下請けとしてビット反転表を作る.
*/
void FFT::make_bitrev()
{
	int i, j, k, n2;
	n2 = size / 2;
	i = j = 0;
	for ( ; ; ) {
		bitrev[i] = j;
		if (++i >= size) break;
		k = n2;
		while (k <= j) {
			j -= k;
			k /= 2;
		}
		j += k;
	}
}

void FFT::fft_run(double x[], double y[])
{
	fft_proc(x, y, false);
}

void FFT::ifft_run(double x[], double y[])
{
	fft_proc(x, y, true);
	for (int i = 0; i < size; i++) {
		x[i] /= size;
		y[i] /= size;
	}
}

/*
  高速Fourier変換 (Cooley--Tukeyのアルゴリズム).
  標本点の数 {\tt n} は2の整数乗に限る.
  {\tt x[$k$]} が実部, {\tt y[$k$]} が虚部 ($k = 0$, $1$, $2$,
  \ldots, $|{\tt n}| - 1$).
  結果は {\tt x[]}, {\tt y[]} に上書きされる.
  ${\tt n} = 0$ なら表のメモリを解放する.
  ${\tt n} < 0$ なら逆変換を行う.
  前回と異なる $|{\tt n}|$ の値で呼び出すと,
  三角関数とビット反転の表を作るために多少余分に時間がかかる.
  この表のための記憶領域獲得に失敗すると1を返す (正常終了時
  の戻り値は0).
  これらの表の記憶領域を解放するには ${\tt n} = 0$ として
  呼び出す (このときは {\tt x[]}, {\tt y[]} の値は変わらない).
*/
void FFT::fft_proc(double x[], double y[], bool inv)
{
	int d, k2, n4;
	double s, c, dx, dy;
	
	n4 = size / 4;
	
	for (int i = 0; i < size; i++) {    /* ビット反転 */
		int j = bitrev[i];
		if (i < j) {
			swap(x[i], x[j]);
			swap(y[i], y[j]);
		}
	}
	
	for (int k = 1; k < size; k = k2) {    /* 変換 */
		int h = 0;
		k2 = k + k;
		d = size / k2;
		for (int j = 0; j < k; j++) {
			c = sintbl.at(h + n4);
			if (inv) {
				s = - sintbl.at(h);
			} else {
				s = sintbl.at(h);
			}
			for (int i = j; i < size; i += k2) {
				int ik = i + k;
				dx = s * y[ik] + c * x[ik];
				dy = c * y[ik] - s * x[ik];
				x[ik] = x[i] - dx;
				x[i] += dx;
				y[ik] = y[i] - dy;
				y[i] += dy;
			}
			h += d;
		}
	}
	
}
