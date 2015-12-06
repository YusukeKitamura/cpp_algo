/***********************************************************
	dfs.cpp -- cŒ`’Tõi[‚³—Dæ’Tõj
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

void DFS::visit(int i) 		// “_ i ‚ğ–K‚ê‚é (Ä‹A“I) 
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
	std::cout << "˜AŒ‹¬•ª:" << std::endl;
	int count = 0;                                /* ˜AŒ‹¬•ª‚ğ”‚¦‚é */
	for (int i = 0; i < size; i++) {
		if (!visited.at(i)) {
			count++;
			std::cout << " " << count << ":";
			visit(i);
			std::cout << std::endl;
		}
	}
}