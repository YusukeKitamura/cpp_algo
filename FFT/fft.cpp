/***********************************************************
	fft.cpp -- FFT (����Fourier�ϊ�)
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
  �֐�{\tt fft()}�̉������Ƃ��ĎO�p�֐��\�����.
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
  �֐�{\tt fft()}�̉������Ƃ��ăr�b�g���]�\�����.
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
  ����Fourier�ϊ� (Cooley--Tukey�̃A���S���Y��).
  �W�{�_�̐� {\tt n} ��2�̐�����Ɍ���.
  {\tt x[$k$]} ������, {\tt y[$k$]} ������ ($k = 0$, $1$, $2$,
  \ldots, $|{\tt n}| - 1$).
  ���ʂ� {\tt x[]}, {\tt y[]} �ɏ㏑�������.
  ${\tt n} = 0$ �Ȃ�\�̃��������������.
  ${\tt n} < 0$ �Ȃ�t�ϊ����s��.
  �O��ƈقȂ� $|{\tt n}|$ �̒l�ŌĂяo����,
  �O�p�֐��ƃr�b�g���]�̕\����邽�߂ɑ����]���Ɏ��Ԃ�������.
  ���̕\�̂��߂̋L���̈�l���Ɏ��s�����1��Ԃ� (����I����
  �̖߂�l��0).
  �����̕\�̋L���̈���������ɂ� ${\tt n} = 0$ �Ƃ���
  �Ăяo�� (���̂Ƃ��� {\tt x[]}, {\tt y[]} �̒l�͕ς��Ȃ�).
*/
void FFT::fft_proc(double x[], double y[], bool inv)
{
	int d, k2, n4;
	double s, c, dx, dy;
	
	n4 = size / 4;
	
	for (int i = 0; i < size; i++) {    /* �r�b�g���] */
		int j = bitrev[i];
		if (i < j) {
			swap(x[i], x[j]);
			swap(y[i], y[j]);
		}
	}
	
	for (int k = 1; k < size; k = k2) {    /* �ϊ� */
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
