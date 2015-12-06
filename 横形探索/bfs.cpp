/***********************************************************
	bfs.cpp -- 
***********************************************************/
#include "bfs.h"

BFS::BFS()
{
}

void BFS::setData(int size)
{
	prev.resize(size);
	dist.resize(size);
	for (int i = 0; i < size; i++) {
		dist.at(i) = -1;
	}
}

void BFS::BFS_run()
{
	BFSQueue.push(0);
	dist.at(0) = 0;
	do {
		int i = BFSQueue.front();
		BFSQueue.pop();
		for (int j = 0; j < size; j++)
			if (adjacent.at(i).at(j) > 0 && dist.at(j) < 0) {
				BFSQueue.push(j);
				dist.at(j) = dist.at(i) + adjacent.at(i).at(j);
				prev.at(j) = i;
			}
	} while (BFSQueue.size() > 0);
}
