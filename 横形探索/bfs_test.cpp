/***********************************************************
	bfs_test.cpp -- 横形探索（幅優先探索）　テスト用
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "bfs.h"

int main()
{

	BFS bfs;
	char* filename = (char*)"bfs.dat";
	if (!bfs.readGraph(filename)) return EXIT_FAILURE;
	bfs.output();
	
	int n = bfs.getSize();
	bfs.setData(n);
	bfs.BFS_run();
	
	std::cout << "点  直前の点  最短距離" << std::endl;
	for (int i = 0; i < n; i++) {
		if (bfs.dist.at(i) > 0) {
			std::cout << i << " " << bfs.prev.at(i) << " " << bfs.dist.at(i) << std::endl;
		}
	}
	return EXIT_SUCCESS;
}
