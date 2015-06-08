/***********************************************************
	marriage.h -- ����Ȍ����̖��
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
	int num;		 // �e���̐l��
	std::vector<int> boy;
	std::vector<std::vector<int> > girl; 
	std::vector<int> position; 
	std::vector<std::vector<int> > rank;

};

#endif
