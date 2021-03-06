/***********************************************************
	isomer.h -- 異性体の問題
***********************************************************/
#ifndef ISOMER_H
#define ISOMER_H

const int C = 21;		// 炭素原子の数の上限
//const long int L = 2558;	// 生成する基の個数の上限
const long int L = 99999;	// 生成する基の個数の上限

class Isomer{
public:
	Isomer();
	~Isomer();
	int isomer(int c);
	bool calcCount();
	
	long int* size;
	long int* length;
	long int* count;

};
#endif
