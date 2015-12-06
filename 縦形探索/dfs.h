/***********************************************************
	dfs.h -- �c�`�T���i�[���D��T���j
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
	std::vector<bool> visited;  // �K�ꂽ�Ȃ�true
	
};

#endif
