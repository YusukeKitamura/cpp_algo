/***********************************************************
	bfs.h -- ‰¡Œ`’Tõi•—Dæ’Tõj
***********************************************************/
#ifndef BFS_H
#define BFS_H
#include <vector>
#include <queue>
#include "graph.h"

class BFS : public Graph {
public:
	BFS();
	void setData(int size);
	void BFS_run();
	std::vector<int> prev;
	std::vector<int> dist;
	
private:
	std::queue<int> BFSQueue;
	
};

#endif
