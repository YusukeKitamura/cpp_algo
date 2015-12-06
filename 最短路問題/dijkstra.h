/***********************************************************
	dijkstra.h -- ç≈íZòHñ‚ëË
***********************************************************/
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include "graph.h"

class Dijkstra : public Graph {
public:
	Dijkstra();
	void init(int start);
	void Dijkstra_run(int start);
	
	std::vector<bool> visited;  // ñKÇÍÇΩÇ»ÇÁtrue
	std::vector<int> distance;
	std::vector<int> prev;
};


#endif