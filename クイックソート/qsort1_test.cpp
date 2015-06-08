/***********************************************************
	qsort1_test.cpp -- クイックソート　テスト用
***********************************************************/
#include "qsort1.h"
#include <iostream>
#include <cstdlib>

const int N = 20;

int main(void) {
    int a[N];

    std::cout << "Before:";
	for (int i = 0; i < N; i++) {
		a[i] = rand() / (RAND_MAX / 100 + 1);
		std::cout << " " << a[i];
	}

	std::cout << std::endl;
	quicksort(a, 0, N - 1);

    std::cout <<"After: ";
	for (int i = 0; i < N; i++) {
		std::cout << " " << a[i];
	}
	
    return EXIT_SUCCESS;
}
