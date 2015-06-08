/***********************************************************
	fukumen.h -- ���ʎZ
***********************************************************/
#ifndef FUKUMEN_H
#define FUKUMEN_H

const int N = 10;  // �ő�̍s��

class Fukumen {

public:
	Fukumen(int n);
	void found();  // ���̕\��
	void search(int sum, int i, int j);  // �ċA�I�Ɏ��݂�
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
