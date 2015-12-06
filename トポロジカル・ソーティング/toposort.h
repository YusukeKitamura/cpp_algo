/***********************************************************
	toposort.h -- �g�|���W�J���E�\�[�e�B���O
***********************************************************/
#ifndef TOPOSORT_H
#define TOPOSORT_H

#include <vector>
#include "graph.h"

enum {NEVER, JUST, ONCE};

class TopoSort : public Graph {
public:
	TopoSort();
	void init();
	void TopoSort_run();
	
	std::vector<int> visited;  // �K�ꂽ�Ȃ�true
	
private:
	void visit(int i);
};


#endif
