/***********************************************************
	marriage.cpp -- ����Ȍ����̖��
***********************************************************/
#include "marriage.h"
#include <iostream>

Marriage::Marriage(int n) :
	num(n)
{
	std::vector<int> tmp1(1, 0);
	std::vector<int> tmp2(1, n + 1);
	for (int i = 0; i < n + 1; i++) {
		boy.push_back(0);
		position.push_back(0);
		girl.push_back(tmp1);
		rank.push_back(tmp2);
		for (int j = 1; j < n + 1; j++) {
			girl[i].push_back(0);
			rank[i].push_back(n + 1);
		}
	}
}

// �e�����̍D��
void Marriage::setGirl(int g)
{
	int b;
	std::cout << "��" << g << ":" << std::endl;
	for (int r = 1; r <= num; r++) {
		std::cin >> b; 
		rank[g][b] = r;
	}
}

// �e�j���̍D��
void Marriage::setBoy(int b)
{
	std::cout << "�j" << b << ":" << std::endl;
	for (int r = 1; r <= num; r++)
		std::cin >> girl[b][r]; 
}

// �œK�Ȓj���̑g�ݍ��킹���v�Z
void Marriage::calc()
{
	for (int b = 1; b <= num; b++) {
		int s = b;
		while (s != 0) {
			int g = girl[s][++position[s]];
			if (rank[g][s] < rank[g][boy[g]]) {
				int t = boy[g]; 
				boy[g] = s;
				s = t;
			}
		}
	}
}

// ���ʂ��o��
void Marriage::print()
{
	for (int g = 1; g <= num; g++)
		std::cout << "�� " << g << " - �j "<< boy[g] << std::endl;
}
