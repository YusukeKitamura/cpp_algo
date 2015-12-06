/***********************************************************
	dijkstra_test.cpp -- �ŒZ�H���@�e�X�g�p
***********************************************************/
#include <iostream>
#include <cstdlib>
#include "dijkstra.h"

int main()
{
	Dijkstra dijkstra;

	char* filename = (char*)"dijkstra.dat";
	if (!dijkstra.readGraph(filename)) return EXIT_FAILURE;
	dijkstra.output();
	
	dijkstra.init(0);
	dijkstra.Dijkstra_run(0);
	
	std::cout << "�_  ���O�̓_  �ŒZ����" << std::endl;
	for (int i = 0; i < dijkstra.getSize(); i++)
		if (i != 0 && dijkstra.visited.at(i))
			std::cout << i << "      " << dijkstra.prev.at(i) << 
			"      " << dijkstra.distance.at(i) << std::endl;
		
	return EXIT_SUCCESS;
}
