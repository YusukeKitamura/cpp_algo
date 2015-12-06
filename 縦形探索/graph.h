/***********************************************************
	graph.h -- グラフライブラリ
***********************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
	Graph();
	bool readGraph(char* filename, bool direction=false);		//グラフ入力
	void output();
	int getSize();
	
protected:
	int size;			//点の数
	std::vector< std::vector<int> > adjacent;		//隣接行列
	
};

#endif
