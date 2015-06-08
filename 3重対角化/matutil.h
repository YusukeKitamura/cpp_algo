/***********************************************************
	matutil.h -- �s��
	�s�񑀍�̏�����W
***********************************************************/
#ifndef MATUTIL_H
#define MATUTIL_H
#include <iostream>
#include <cstdlib>
#include <valarray>

class Vector {
public:
	Vector();
	Vector(size_t x);
	Vector(const Vector& a);   // �R�s�[�R���X�g���N�^

	Vector& operator=(const Vector& a) { // ���
		if (this != &a) {
			delete v;
			init(a.n);
			*v = *(a.v);
		}
		return *this;
	}

	Vector operator+(const Vector& a) { // �a
		if (n!= a.n) {
			std::cerr << "Length not same!" << std::endl;
			exit(EXIT_FAILURE);
		}
		Vector vec(n);
		*(vec.v) = *v + *(a.v);
		return vec;
	}

	Vector operator-(const Vector& a) { // ��
		if (n!= a.n) {
			std::cerr << "Length not same!" << std::endl;
			exit(EXIT_FAILURE);
		}
		Vector vec(n);
		*(vec.v) = *v - *(a.v);
		return vec;
	}

	Vector operator*(double x) { // �萔�{
		Vector vec(n);
		*(vec.v) = x * (*v);
		return vec;
	}
	
	~Vector();     // �f�X�g���N�^
	
	double& operator()(size_t i) { // �Y��
        return (*v)[i];
    }
	
	const double& operator()(size_t i) const {
		return (*v)[i]; // ����
	}
    size_t length() const { return n; } 	// ����
	
private:
    size_t n;                // ����
    std::valarray<double>* v;        // �f�[�^
    void init(size_t x);
};

void vecprint(const Vector &v);
double innerproduct(int n, Vector u, Vector v);	//	����
double innerproduct(Vector u, Vector v);	//	����

class Matrix {
public:
    Matrix();
    Matrix(size_t x, size_t y);
    Matrix(const Matrix& a);   // �R�s�[�R���X�g���N�^

	Matrix& operator=(const Matrix& a) { // ���
		if (this != &a) {
			delete v;
			init(a.r, a.c);
			*v = *(a.v);
		}
		return *this;
	}

	Matrix operator+(const Matrix& a) { // �a
		if (r!= a.r || c != a.c) {
			std::cerr << "Row or Column not same!" << std::endl;
			exit(EXIT_FAILURE);
		}
		Matrix m(r, c);
		*(m.v) = *v + *(a.v);
		return m;
	}

	Matrix operator-(const Matrix& a) { // ��
		if (r!= a.r || c != a.c) {
			std::cerr << "Row or Column not same!" << std::endl;
			exit(EXIT_FAILURE);
		}
		Matrix m(r, c);
		*(m.v) = *v - *(a.v);
		return m;
	}

	Matrix operator*(double x) { // �萔�{
		Matrix m(r, c);
		*(m.v) = x * (*v);
		return m;
	}
	
    ~Matrix();     // �f�X�g���N�^
	
    double& operator()(size_t i, size_t j) { // �Y��
        return (*v)[i * c + j]; // �s����
        // �񂲂ƂȂ��� (*v)[j * r + i] �ƂȂ�
    }
	
    const double& operator()(size_t i, size_t j) const {
        return (*v)[i * c + j]; // ����
    }
	
    Vector& operator()(size_t i) { // �Y��
		Vector vec(i);
		for (int j = 0; j < c; j++) {
			vec(j) = (*v)[i * c + j];
		}
        return vec; // �s����
        // �񂲂ƂȂ��� (*v)[j * r + i] �ƂȂ�
    }
	
    size_t nrow() const { return r; } 	// �s��
    size_t ncol() const { return c; } 	// ��
	

private:
	size_t r, c;                // �s���C��
	std::valarray<double>* v;        // �f�[�^
	void init(size_t x, size_t y);
};

void matprint(const Matrix& a);	// �s����o��

#endif
