/***********************************************************
	matutil.h -- 行列
	行列操作の小道具集
***********************************************************/
#ifndef MATUTIL_H
#define MATUTIL_H
#include <iostream>
#include <cstdlib>
#include <valarray>

class Matrix {
public:
    Matrix();
    Matrix(size_t x, size_t y);
    Matrix(const Matrix& a);   // コピーコンストラクタ

	Matrix& operator=(const Matrix& a) { // 代入
		if (this != &a) {
			delete v;
			init(a.r, a.c);
			*v = *(a.v);
		}
		return *this;
	}

	Matrix operator+(const Matrix& a) { // 和
		if (r!= a.r || c != a.c) {
			std::cerr << "Row or Column not same!" << std::endl;
			exit(EXIT_FAILURE);
		}
		Matrix m(r, c);
		*(m.v) = *v + *(a.v);
		return m;
	}

	Matrix operator-(const Matrix& a) { // 差
		if (r!= a.r || c != a.c) {
			std::cerr << "Row or Column not same!" << std::endl;
			exit(EXIT_FAILURE);
		}
		Matrix m(r, c);
		*(m.v) = *v - *(a.v);
		return m;
	}

	Matrix operator*(double x) { // 定数倍
		Matrix m(r, c);
		*(m.v) = x * (*v);
		return m;
	}
	
    ~Matrix();     // デストラクタ
	
    double& operator()(size_t i, size_t j) { // 添字
		if (i > r || j > c) {
			std::cerr << "i=" << i << ",row=" << r << ",j=" << j << ",col=" << c << std::endl;
			std::cerr << "Access error!!!" << std::endl;
			exit(EXIT_FAILURE);
		}
        return (*v)[i * c + j]; // 行ごと
        // 列ごとなら上は (*v)[j * r + i] となる
    }
	
    const double& operator()(size_t i, size_t j) const {
		if (i > r || j > c) {
			std::cerr << "i=" << i << ",row=" << r << ",j=" << j << ",col=" << c << std::endl;
			std::cerr << "Access error!!!" << std::endl;
			exit(EXIT_FAILURE);
		}
        return (*v)[i * c + j]; // 同上
    }
	
    size_t nrow() const { return r; } 	// 行数
    size_t ncol() const { return c; } 	// 列数
	

private:
	size_t r, c;                // 行数，列数
	std::valarray<double>* v;        // データ
	void init(size_t x, size_t y);
};

void matprint(const Matrix& a);	// 行列を出力

class Vector {
public:
	Vector();
	Vector(size_t x);
	Vector(const Vector& a);   // コピーコンストラクタ

	Vector& operator=(const Vector& a) { // 代入
		if (this != &a) {
			delete v;
			init(a.n);
			*v = *(a.v);
		}
		return *this;
	}

	Vector operator+(const Vector& a) { // 和
		if (n!= a.n) {
			std::cerr << "Length not same!" << std::endl;
			exit(EXIT_FAILURE);
		}
		Vector vec(n);
		*(vec.v) = *v + *(a.v);
		return vec;
	}

	Vector operator-(const Vector& a) { // 差
		if (n!= a.n) {
			std::cerr << "Length not same!" << std::endl;
			exit(EXIT_FAILURE);
		}
		Vector vec(n);
		*(vec.v) = *v - *(a.v);
		return vec;
	}

	Vector operator*(double x) { // 定数倍
		Vector vec(n);
		*(vec.v) = x * (*v);
		return vec;
	}
	
	~Vector();     // デストラクタ
	
	double& operator()(size_t i) { // 添字
		if (i > n) {
			std::cerr << "i=" << i << ",length=" << n << std::endl;
			std::cerr << "Access error!!!" << std::endl;
			exit(EXIT_FAILURE);
		}
        return (*v)[i];
    }
	
	const double& operator()(size_t i) const {
		if (i > n) {
			std::cerr << "i=" << i << ",length=" << n << std::endl;
			std::cerr << "Access error!!!" << std::endl;
			exit(EXIT_FAILURE);
		}
		return (*v)[i]; // 同上
	}
    size_t length() const { return n; } 	// 長さ
	
private:
    size_t n;                // 長さ
    std::valarray<double>* v;        // データ
    void init(size_t x);
};

void vecprint(const Vector &v);
double innerproduct(int n, Vector u, Vector v);	//	内積
double innerproduct(Vector u, Vector v);	//	内積

#endif
