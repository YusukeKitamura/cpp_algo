/***********************************************************
	toposort_test.cpp -- �g�|���W�J���E�\�[�e�B���O�@�e�X�g�p
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "toposort.h"

int main()
{
	TopoSort toposort;

	char* filename = (char*)"toposort.dat";
	if (!toposort.readGraph(filename, true)) return EXIT_FAILURE;
	toposort.output();
	
	toposort.init();
	
	std::cout << std::endl;
	std::cout << "�g�|���W�J���E�\\�[�e�B���O�̌���:" << std::endl;
	toposort.TopoSort_run();
	return EXIT_SUCCESS;
}
