/***********************************************************
	warshall.h -- „ˆÚ“I•Â•ï
***********************************************************/
#ifndef WARSHAL_H
#define WARSHAL_H

#include <vector>
#include "graph.h"

class Warshall : public Graph {
public:
	Warshall();
	std::vector< std::vector<int> > Warshall_run();
	
};

#endif
