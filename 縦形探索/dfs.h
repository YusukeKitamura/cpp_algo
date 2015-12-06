/***********************************************************
	dfs.h -- cŒ`’Tõi[‚³—Dæ’Tõj
***********************************************************/
#ifndef DFS_H
#define DFS_H
#include <vector>
#include "graph.h"

class DFS : public Graph {
public:
	DFS();
	void setData(int size);
	void visit(int i);
	void DFS_run();
	
private:
	std::vector<bool> visited;  // –K‚ê‚½‚È‚çtrue
	
};

#endif
