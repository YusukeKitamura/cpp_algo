/***********************************************************
	warshall_test.cpp -- ���ړI��@�e�X�g�p
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "warshall.h"

int main()
{
	Warshall warshall;
	char* filename = (char*)"warshall.dat";
	if (!warshall.readGraph(filename, true)) return EXIT_FAILURE;
	warshall.output();
	
	std::vector< std::vector<int> > closure = warshall.Warshall_run();
	std::cout << "���ړI��:" << std::endl;
	for (int i = 0; i < warshall.getSize(); i++) {
		for (int j = 0; j < warshall.getSize(); j++) {
			std::cout << " " << closure.at(i).at(j);
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}
