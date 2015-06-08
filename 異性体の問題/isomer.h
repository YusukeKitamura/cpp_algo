/***********************************************************
	isomer.h -- ˆÙ«‘Ì‚Ì–â‘è
***********************************************************/
#ifndef ISOMER_H
#define ISOMER_H

const int C = 21;		// ’Y‘fŒ´q‚Ì”‚ÌãŒÀ
//const long int L = 2558;	// ¶¬‚·‚éŠî‚ÌŒÂ”‚ÌãŒÀ
const long int L = 99999;	// ¶¬‚·‚éŠî‚ÌŒÂ”‚ÌãŒÀ

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
