/*    Shell sort    */
#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <iostream>
#include <cstdlib>

const int N = 20;

class shellsort {
private:
    int* data;
public:
    shellsort();
	void view();											// View list
	void sort();
	~shellsort();
};

#endif
