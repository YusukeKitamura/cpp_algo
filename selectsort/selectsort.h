/*    Selection sort    */
#ifndef SELECTSORT_H
#define SELECTSORT_H

#include <iostream>
#include <cstdlib>

const int N = 20;

class selectsort {
private:
    int* data;
public:
    selectsort();
	void view();											// View list
	void sort();
	~selectsort();
};

#endif
