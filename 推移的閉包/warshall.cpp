/***********************************************************
	warshall.cpp -- „ˆÚ“I•Â•ï
***********************************************************/
#include "warshall.h"

Warshall::Warshall()
{
}

std::vector< std::vector<int> > Warshall::Warshall_run()
{
	std::vector< std::vector<int> > closure = adjacent;
	
	for (int k = 0; k < size; k++) {
		for (int i = 0; i < size; i++) {
			if (closure.at(i).at(k) > 0) {
				for (int j = 0; j < size; j++) {
					closure.at(i).at(j) |= closure.at(k).at(j);
				}
			}
		}
	}
	
	return closure;
}
