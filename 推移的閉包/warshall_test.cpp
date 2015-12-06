/***********************************************************
	warshall_test.cpp -- 推移的閉包　テスト用
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
	std::cout << "推移的閉包:" << std::endl;
	for (int i = 0; i < warshall.getSize(); i++) {
		for (int j = 0; j < warshall.getSize(); j++) {
			std::cout << " " << closure.at(i).at(j);
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}
