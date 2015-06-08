/*    Selection sort    */
#include "selectsort.h"

selectsort::selectsort() {
    data = new int[N];
    for (int i = 0; i < N; i++) 
		data[i] = rand() / (RAND_MAX / 100 + 1);
}

void selectsort::view() {
    for (int i = 0; i < N-1; i++) {
        std::cout <<  data[i] << " ";
    }
    std::cout <<"\n";
}

void selectsort::sort() {
	int j, k, min = 0;

	for (int i=0; i<N-1; i++) {
		min = data[i];
		k = i;
		for (j=i+1; j<N; j++) {
			if (data[j] < min) {
				min = data[j];
				k = j;
			}
		}
		data[k] = data[i];
		data[i] = min;
	}
}

selectsort::~selectsort() {
    delete [] data;
}
