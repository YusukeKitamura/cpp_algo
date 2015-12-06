/***********************************************************
	dijkstra.cpp -- Å’Z˜H–â‘è
***********************************************************/
#include <climits>
#include "dijkstra.h"

Dijkstra::Dijkstra()
{
}

void Dijkstra::init(int start)
{
	visited.resize(size);
	distance.resize(size);
	prev.resize(size);
	
	for (int i = 0; i < size; i++) {
		visited.at(i) = false;
		distance.at(i) = INT_MAX;
		prev.at(i) = 0;
	}
	distance.at(start) = 0;
}

void Dijkstra::Dijkstra_run(int start)
{
	std::vector< std::vector<int> > weight = adjacent;
	//—×‚è‡‚Á‚Ä‚È‚¢—v‘f‚Ì‹——£‚ğ®”‚ÌÅ‘å’l‚É‚µ‚Ä‚¨‚­
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i != j && adjacent.at(i).at(j) == 0) {
				weight.at(i).at(j) = INT_MAX;
			}
		}
	}
	
	int next = start;
	int min = INT_MAX;
	do {
		int i = next;
		visited.at(i) = true;
		min = INT_MAX;
		for (int j = 0; j < size; j++) {
			if (visited.at(j)) continue;
			if (weight.at(i).at(j) < INT_MAX &&
					distance.at(i) + weight.at(i).at(j) < distance.at(j)) {
				distance.at(j) = distance.at(i) + weight.at(i).at(j);
				prev.at(j) = i;
			}
			if (distance.at(j) < min) {
				min = distance.at(j);
				next = j;
			}
		}
	} while (min < INT_MAX);
	
}
