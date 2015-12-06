/***********************************************************
	graph.cpp -- �O���t���C�u����
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

bool Graph::readGraph(char* filename, bool direction)		//�O���t����
{
	std::ifstream ifs(filename);
	if( !ifs ) {
		std::cerr << "�f�[�^�t�@�C�����ǂ߂܂���" << std::endl;
		return false;
	}
	
	std::string strsize;
	getline(ifs, strsize);
	size = atoi(strsize.c_str());
	if (size <= 0) {
		std::cerr << "�m�[�h�����ǂݍ��߂Ȃ����A�O�ȉ��ł�" << std::endl;
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
			//�����O���t�̎��͋t�����ɂ������l������
			if (!direction) {
				adjacent.at(dst).at(src) = dat;
			}
		} else {
			std::cerr << "�m�[�h�C���f�b�N�X��0,1,...,size-1�ł�" << std::endl;
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
