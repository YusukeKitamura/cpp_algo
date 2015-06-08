/***********************************************************
	fukumen.h -- 覆面算
***********************************************************/
#ifndef FUKUMEN_H
#define FUKUMEN_H

const int N = 10;  // 最大の行数

class Fukumen {

public:
	Fukumen(int n);
	void found();  // 解の表示
	void search(int sum, int i, int j);  // 再帰的に試みる
	void set();
	int solution;
	int low[256];

private:
	int imax;
	int jmax;
	int word[N][128];
	int digit[256];
	bool ok[10];
};

#endif
