/***********************************************************
	dfs.cpp -- 縦形探索（深さ優先探索）
***********************************************************/
#include <iostream>
#include "dfs.h"

DFS::DFS()
{
}

void DFS::setData(int size)
{
	visited.resize(size);
	for (int i = 0; i < size; i++) {
		visited.at(i) = false;
	}
}

void DFS::visit(int i) 		// 点 i を訪れる (再帰的) 
{
	std::cout << " " << i;
	visited.at(i) = true;
	for (int j = 0; j < size; j++) {
		if (adjacent.at(i).at(j) > 0 && !visited.at(j)) {
			visit(j);
		}
	}
}

void DFS::DFS_run()
{
	std::cout << "連結成分:" << std::endl;
	int count = 0;                                /* 連結成分を数える */
	for (int i = 0; i < size; i++) {
		if (!visited.at(i)) {
			count++;
			std::cout << " " << count << ":";
			visit(i);
			std::cout << std::endl;
		}
	}
}