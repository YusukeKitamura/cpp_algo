/***********************************************************
	toposort.cpp -- トポロジカル・ソーティング
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "toposort.h"

TopoSort::TopoSort()
{
}

void TopoSort::init()
{
	visited.resize(size);
	for (int i = 0; i < size; i++) {
		visited.at(i) = NEVER;
	}
}

void TopoSort::visit(int i)
{
	visited.at(i) = JUST;
	for (int j = 0; j < size; j++) {
		if (adjacent.at(j).at(i) == 0) continue;
		if (visited.at(j) == NEVER) {
			visit(j);
		} else if (visited.at(j) == JUST) {
			std::cout << std::endl;
			std::cout << "サイクルあり!" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	visited.at(i) = ONCE;
	std::cout << " " << i;
}

void TopoSort::TopoSort_run()
{
	for (int i = 0; i < size; i++)
		if (visited.at(i) == NEVER) visit(i);
}
