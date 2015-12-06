/***********************************************************
	dfs_test.cpp -- �c�`�T���i�[���D��T���j�@�e�X�g�p
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
