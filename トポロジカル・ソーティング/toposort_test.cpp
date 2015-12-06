/***********************************************************
	toposort_test.cpp -- トポロジカル・ソーティング　テスト用
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
	std::cout << "トポロジカル・ソ\ーティングの結果:" << std::endl;
	toposort.TopoSort_run();
	return EXIT_SUCCESS;
}
