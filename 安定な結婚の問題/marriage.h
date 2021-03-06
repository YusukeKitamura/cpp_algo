/***********************************************************
	marriage.h -- 安定な結婚の問題
***********************************************************/
#ifndef MARRIAGE_H
#define MARRIAGE_H

#include <vector> 

class Marriage
{
public:
	Marriage(int n);
	void setGirl(int g);
	void setBoy(int b);
	void calc();
	void print();
	
private:
	int num;		 // 各性の人数
	std::vector<int> boy;
	std::vector<std::vector<int> > girl; 
	std::vector<int> position; 
	std::vector<std::vector<int> > rank;

};

#endif
