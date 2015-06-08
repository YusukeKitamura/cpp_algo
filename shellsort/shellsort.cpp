/*    Shell sort    */
#include "shellsort.h"

shellsort::shellsort() {
    data = new int[N];
    for (int i = 0; i < N; i++) 
		data[i] = rand() / (RAND_MAX / 100 + 1);
}

void shellsort::view() {
    for (int i = 0; i < N-1; i++) {
        std::cout <<  data[i] << " ";
    }
    std::cout <<"\n";
}

void shellsort::sort(int num[], int n) {
	int h = 1;
	while (h < n) h = 3*h + 1;		/* Deside interval "h" */
	while (h > 0) {
		for (int i = h; i < n; i++) {
			int x = num[i];
			for (int j = i-h; j >= 0 && num[j] > x; j -= h)
				num[j + h] = num[j];
			num[j + h] = x;
		}
		h /= 3;
	}
}

selectsort::~selectsort() {
    delete [] data;
}
