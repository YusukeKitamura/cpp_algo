/*    Insertion sort    */
#include <iostream>
#include <cstdlib>
#include "inssort.h"

const int N = 20;

int main(void) {
    int a[N];

    std::cout << "Before:";
	for (int i = 0; i < N; i++) {
		a[i] = rand() / (RAND_MAX / 100 + 1);
		std::cout << " " << a[i];
	}

	std::cout << std::endl;
	inssort(N, a);

    std::cout <<"After: ";
	for (int i = 0; i < N; i++) {
		std::cout << " " << a[i];
	}
	
    return EXIT_SUCCESS;
}
