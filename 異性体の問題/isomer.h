/***********************************************************
	isomer.h -- �ِ��̖̂��
***********************************************************/
#ifndef ISOMER_H
#define ISOMER_H

const int C = 21;		// �Y�f���q�̐��̏��
//const long int L = 2558;	// ���������̌��̏��
const long int L = 99999;	// ���������̌��̏��

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
