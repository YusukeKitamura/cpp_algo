/***********************************************************
	graph.cpp -- グラフライブラリ
***********************************************************/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <climits>
#include "graph.h"

Graph::Graph():
	size(0)
{
}

bool Graph::readGraph(char* filename, bool direction)		//グラフ入力
{
	std::ifstream ifs(filename);
	if( !ifs ) {
		std::cerr << "データファイルが読めません" << std::endl;
		return false;
	}
	
	std::string strsize;
	getline(ifs, strsize);
	size = atoi(strsize.c_str());
	if (size <= 0) {
		std::cerr << "ノード数が読み込めないか、０以下です" << std::endl;
		return false;
	}
	adjacent.resize(size);
	for (int i = 0; i < size; i++) {
		adjacent.at(i).resize(size);
		for (int j = 0; j < size; j++) {
			adjacent.at(i).at(j) = 0;
		}
	}
	
	std::string str;
	while( getline( ifs, str ) ){
		std::string str_src, str_dst, src_dat;
		int src, dst, dat;
		std::istringstream stream( str );
		getline( stream, str_src, ' ' );
		getline( stream, str_dst, ' ' );
		getline( stream, src_dat, ' ' );
		
		src = atoi(str_src.c_str());
		dst = atoi(str_dst.c_str());
		dat = atoi(src_dat.c_str());
		if (src < size && dst < size) {
			adjacent.at(src).at(dst) = dat;
			//無向グラフの時は逆方向にも同じ値を入れる
			if (!direction) {
				adjacent.at(dst).at(src) = dat;
			}
		} else {
			std::cerr << "ノードインデックスは0,1,...,size-1です" << std::endl;
		}
	}
	
	return true;
}

int Graph::getSize()
{
	return size;
}

void Graph::output()
{
	std::cout << "Adjacent matrix:" << std::endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << " " << adjacent.at(i).at(j);
		} 
		std::cout << std::endl;
	}
}
