/***********************************************************
	dfs_test.cpp -- 縦形探索（深さ優先探索）　テスト用
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "dfs.h"

int main()
{
	DFS dfs;
	char* filename = (char*)"dfs.dat";
	if (!dfs.readGraph(filename)) return EXIT_FAILURE;
	dfs.output();
	
	int n = dfs.getSize();
	dfs.setData(n);
	dfs.DFS_run();

	return EXIT_SUCCESS;
}
