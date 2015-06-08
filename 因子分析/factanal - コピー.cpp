/***********************************************************
	factanal.c -- 因子分析
***********************************************************/
#include <iomanip>
#include "factanal.h"

Factanal::Factanal()
{
}

Factanal::~Factanal()
{
}

double Factanal::house(int n, Vector& x)  /* Householder変換 */
{
	double s, t;

	s = sqrt(innerproduct(n, x, x));  /* 内積の平方根, すなわち大きさ */
	if (s != 0) {
		if (x(0) < 0)
			s = -s;
		x(0) += s;
		t = 1 / sqrt(x(0) * s);
		for (int i = 0; i < n; i++)
			x(i) *= t;
	}
	
	return -s;
}

void Factanal::tridiagonalize(int n, Matrix& a, Vector& d, Vector& e) /* 3重対角化 */
{
	double s, t, p, q, r;
	Vector v, w;
	
	std::cout << "before" << std::endl;
	for (int j = 0; j < a.nrow(); j++) {
		for (int i = 0; i < a.ncol(); i++) {
			std::cout << a(j, i) << " ";
		}
		std::cout << std::endl;
	}
	for (int k = 0; k < n - 2; k++) {
		v = a(k);
		d(k) = v(k);
		
		Vector v2(n - k - 1);
		for (int i = 0; i < n - k - 1; i++)
			v2(i) = v(i + k + 1);
		e(k) = house(n - k - 1, v2);
		printf("house=%f\n", e(k));
		for (int i = 0; i < n - k - 1; i++)
			a(k, i + k + 1) = v2(i);
		for (int i = 0; i < n - k - 1; i++)
			v(i + k + 1) = v2(i);
			
		if (e(k) == 0) continue;
		for (int i = k + 1; i < n; i++) {
			s = 0;
			for (int j = k + 1; j < i; j++)
				s += a(j, i) * v(j);
			for (int j = i; j < n; j++)
				s += a(i, j) * v(j);
			d(i) = s;
		}
		
		Vector vv(n-k-1), dd(n-k-1);
		for (int i = 0; i < n-k-1; i++) {
			vv(i) = v(i + k + 1);
			dd(i) = d(i + k + 1);
		}
		t = innerproduct(n-k-1, vv, dd) / 2;
		printf("t=%f\n", t);
		
		for (int i = n - 1; i > k; i--) {
			p = v(i); 
			q = d(i) - t * p; 
			d(i) = q;
			for (int j = i; j < n; j++) {
				r = a(i, j) - p * d(j) + q * v(j);
				a(i, j) = r;
			}
		}
	}
	std::cout << "middle" << std::endl;
	for (int j = 0; j < a.nrow(); j++) {
		for (int i = 0; i < a.ncol(); i++) {
			std::cout << a(j, i) << " ";
		}
		std::cout << std::endl;
	}
		std::cout << std::endl;
		std::cout << "d " ;
	for (int i=0; i<d.length(); i++) {
		std::cout << d(i) <<  " ";
	}
		std::cout << std::endl;
	std::cout << "e ";
	for (int i=0; i<e.length(); i++) {
		std::cout << e(i) <<  " ";
	}
		std::cout << std::endl;
	
	if (n >= 2) { 
		d(n - 2) = a(n - 2, n - 2);
	    e(n - 2) = a(n - 2, n - 1); 
	}
	if (n >= 1) 
		d(n - 1) = a(n - 1, n - 1);
	for (int k = n - 1; k >= 0; k--) {
		v = a(k);
		if (k < n - 2) {
			for (int i = k + 1; i < n; i++) {
				w = a(i);
				
				Vector vv(n-k-1), ww(n-k-1);
				for (int j = 0; j < n-k-1; j++) {
					vv(j) = v(j+k+1);
					ww(j) = w(j+k+1);
				}
				t = innerproduct(n - k - 1, vv, ww);
				
				for (int j = k + 1; j < n; j++) {
					w(j) -= t * v(j);
					a(i, j) -= t * v(j);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			v(i) = 0;
			a(k, i)  = 0;
		}
		v(k) = 1;
		a(k, k) = 1;
	}
		std::cout << "after" << std::endl;
	for (int j = 0; j < a.nrow(); j++) {
		for (int i = 0; i < a.ncol(); i++) {
			std::cout << a(j, i) << " ";
		}
		std::cout << std::endl;
	}
}

int Factanal::eigen(int n, Matrix& a, Vector& d, Vector& e)
{
	int h, iter;
	double c, s, t, w, x, y;
	Vector v(a.ncol());

	//tridiagonalize(n, a, d, &e(1));  /* 3重対角化 */
	Vector ee(e.length()-1);
	
	tridiagonalize(n, a, d, ee);  /* 3重対角化 */
	for (int i=0; i<e.length()-1; i++) {
		e(i+1) = ee(i);
	}
	
	e(0) = 0;  /* 番人 */
	std::cout << std::endl;
	std::cout << "d ";
	for (int i=0; i<d.length(); i++) {
		std::cout <<  d(i) <<  " ";
	}
	std::cout << std::endl;
	std::cout << "e " ;
	for (int i=0; i<e.length(); i++) {
		std::cout << e(i) <<  " ";
	}
	std::cout << std::endl;
	for (h = n - 1; h > 0; h--) {  /* 行列のサイズを小さくしていく */
		int j = h;
		// e(j) != 0 のブロックの始点を見つける
		while (j > 0 && fabs(e(j)) > EPS * (fabs(d(j - 1)) + fabs(d(j)) ) ) {
			j--;
		}
		if (j == h) continue;
		iter = 0;
		
		do {
			if (++iter > MAX_ITER)	
				return EXIT_FAILURE;
			w = (d(h - 1) - d(h)) / 2;
			t = e(h) * e(h);
			s = sqrt(w * w + t); 
			if (w < 0)
				s = -s;
			x = d(j) - d(h) + t / (w + s); 
			y = e(j + 1);
			for (int k = j; k < h; k++) {
				if (fabs(x) >= fabs(y)) {
					t = -y / x;
					c = 1 / sqrt(t * t + 1);
					s = t * c;
				} else {
					t = -x / y;
					s = 1 / sqrt(t * t + 1);
					c = t * s;
				}
				w = d(k) - d(k + 1);
				t = (w * s + 2 * c * e(k + 1)) * s;
				d(k) -= t; 
				d(k + 1) += t;
				if (k > j)
					e(k) = c * e(k) - s * y;
				e(k + 1) += s * (c * w - 2 * s * e(k + 1));
				//固有ベクトルを求めないなら不要
				for (int i = 0; i < n; i++) {
					x = a(k, i); 
					y = a(k + 1, i);
					std::cout << "k=" << k << " i=" << i << " c=" << c << " s=" << s << " x= " << x << " y=" << y << std::endl;
					a(k, i) = c * x - s * y;
					a(k + 1, i) = s * x + c * y;
				}
				if (k < h - 1) {
					x = e(k + 1); 
					y = -s * e(k + 2);
					e(k + 2) *= c;
				}
			}
		} while (fabs(e(h)) > EPS * (fabs(d(h - 1)) + fabs(d(h))));
	}
	
		std::cout << "******" << std::endl;
		for (int j = 0; j < a.nrow(); j++) {
			for (int i = 0; i < a.ncol(); i++) {
				std::cout << a(j, i) << " ";
			}
			std::cout << std::endl;
		}
	for (int k = 0; k < n - 1; k++) {
		h = k; 
		t = d(h);
		for (int i = k + 1; i < n; i++) {
			if (d(i) > t) {
				h = i;
				t = d(h);
			}
		}
		d(h) = d(k);
		d(k) = t;
		
		for (int j = 0; j < a.ncol(); j++) {
			v(j) = a(h, j);
			a(h, j) = a(k, j);
			a(k, j) = v(j);
		}
	}
	
		std::cout << "%%%%%%%" << std::endl;
		for (int j = 0; j < a.nrow(); j++) {
			for (int i = 0; i < a.ncol(); i++) {
				std::cout << a(j, i) << " ";
			}
			std::cout << std::endl;
		}
	return EXIT_SUCCESS;
}

/*
  {\tt r[0..m-1][0..m-1]} に入った相関係数の行列に対して因子分析を行い,
  {\tt nfac} ($< {\tt m}) 個の共通因子を抽出する.
  {\tt r} の対角成分は共通性の推定値で上書きされる.
  {\tt q[$k$][$j$]} には第 $j + 1$ 変数の第 $k + 1$ 因子負荷量 ($0 \le
  k < {\tt nfac}$, $0 \le j < {\tt m}$ が入る.
*/
bool Factanal::factor(int m, int nfac, Matrix r, Matrix q, Vector lambda, Vector work)
{
	int n, iter, maxiter;
	double s, t, percent;

	iter = maxiter = 0;
	for ( ; ; ) {
		if (++iter > maxiter) {
			std::cout << "繰返し数 (0:繰返し終了) ? ";
			std::cin >> n;
			
			if (n <= 0) break;
			maxiter += n;
		}
		
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++)
				q(j, k) = r(j, k);
		}
		
		if (eigen(m, q, lambda, work)) {
			std::cerr << "収束しません" << std::endl;
			return false;
		}

		Vector lambda2(m - nfac);
		for (int j = 0; j < m - nfac; j++) {
			lambda2(j) = lambda(j + nfac);
		}
		s = innerproduct(m - nfac, lambda2, lambda2);
		// RMS: root mean square (2乗の平均の平方根) 
		std::cout << iter << ": 非対角成分のRMS誤差 " << sqrt(s / (m * (m - 1))) << std::endl;
		
		for (int j = 0; j < m; j++) {
			s = 0;
			for (int k = 0; k < nfac; k++) {
				s += lambda(k) * q(k, j) * q(k, j);
				std::cout << "lambda:" << lambda(k) << " q:" << q(k, j) << std::endl;
			}
			r(j, j) = s;  /* 共通性 */
		}
	}
	
	t = 0;  /* trace */
	for (int k = 0; k < m; k++)
		t += lambda(k);
		
	std::cout << " 因子        固有値       ％    累積％" << std::endl;
	s = 0;
	for (int k = 0; k < m; k++) {
		if (k < nfac)
			std::cout << std::setprecision(6) << std::setw(4) << " " << k + 1 << " ";
		else 
			std::cout << std::setprecision(6) << std::setw(3) <<  "(" << k + 1 << ")" ;
		percent = 100.0 * lambda(k) / t;
		s += percent;
		std::cout << std::setprecision(6) << " " << std::setw(8) << lambda(k) << "  " ;
		std::cout << std::setprecision(6) << std::setw(8)  << percent << "  " << std::setw(8)  << s << std::endl;
	}
	
	std::cout << "合計  " << t << "  " << s << std::endl;
	for (int k = 0; k < nfac; k++)
		work(k) = sqrt(fabs(lambda(k)));    /* {\tt lambda[k]} は負かも */
		
	std::cout << "    変数    共通性     因子負荷量" << std::endl;
	for (int j = 0; j < m; j++) {
		std::cout << std::setw(4) << std::setprecision(6) << j + 1 << "  " << std::setw(8) << r(j, j) << " ";
		for (int k = 0; k < nfac; k++) {
			q(k, j) *= work(k);
			if (k < 9)
				std::cout << std::setprecision(4) << std::setw(8) << q(k, j);
		}
		std::cout << std::endl;
	}
	
#ifdef CHECK  /* 誤差のチェック用 */
	t = 0;
	for (int j = 0; j < m; j++) {
		for (int k = 0; k < j; k++) {
			s = 0;
			for (int i = 0; i < nfac; i++)
				s += q(i, j) * q(i, k);
			t += (r(j, k)- s) * (r(j, k) - s);
		}
	}
	std::cout << "因子負荷量から再現した相関係数のRMS誤差: " << sqrt(t / (m * (m - 1) / 2)) << std::endl;
#endif /* CHECK */

	return true;
}
