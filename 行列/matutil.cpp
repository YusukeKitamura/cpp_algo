/***********************************************************
	matutil.cpp -- �s��
	�s�񑀍�̏�����W
***********************************************************/
#include <iostream>
#include <valarray>
#include "matutil.h"

Vector::Vector()
{
	init(0);
}

Vector::Vector(size_t x)
{
	init(x); 
}

// �R�s�[�R���X�g���N�^
Vector::Vector(const Vector& a) { 
	init(a.n);
	*v = *(a.v);
}

void Vector::init(size_t x) {
	n = x;
	v = new std::valarray<double>(n);
}

Vector::~Vector() {
	delete v;
}

// �x�N�g�����o��
void vecprint(const Vector& a)  
{
	for (size_t i = 0; i < a.length(); i++) {
		std::cout << a(i) << std::endl;
	}
}

double innerproduct(int n, Vector u, Vector v)
{
	double s = 0; 
	int n5 = n % 5;
	for (int i = 0; i < n5; i++) s += u(i) * v(i);
	for (int i = n5; i < n; i += 5)
		s += u(i) * v(i) + u(i+1) * v(i+1) + u(i+2) * v(i+2)
				+ u(i+3) * v(i+3) + u(i+4) * v(i+4);
	return s;
}

double innerproduct(Vector u, Vector v)
{
	int n = u.length();
	if (n > v.length()) n = v.length();
	
	return innerproduct(n, u, v);
}

Matrix::Matrix() {
	init(0, 0);
}

Matrix::Matrix(size_t x, size_t y) {
	init(x, y); 
}

// �R�s�[�R���X�g���N�^
Matrix::Matrix(const Matrix& a) {
	init(a.r, a.c);
	*v = *(a.v);
}

void Matrix::init(size_t x, size_t y) {
	r = x;
	c = y;
	v = new std::valarray<double>(r * c);
}

Matrix::~Matrix() {
	delete v;
}

// �s����o��
void matprint(const Matrix& a)
{
    for (size_t i = 0; i < a.nrow(); i++) {
        for (size_t j = 0; j < a.ncol() - 1; j++)
            std::cout << a(i, j) << '\t';
        std::cout << a(i, a.ncol() - 1) << '\n';
    }
}
