/***********************************************************
	graph.h -- �O���t���C�u����
***********************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
	Graph();
	bool readGraph(char* filename, bool direction=false);		//�O���t����
	void output();
	int getSize();
	
protected:
	int size;			//�_�̐�
	std::vector< std::vector<int> > adjacent;		//�אڍs��
	
};

#endif
