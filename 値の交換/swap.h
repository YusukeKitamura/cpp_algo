/***********************************************************
	swap.h -- �l�̌���
***********************************************************/
#ifndef SWAP_H
#define SWAP_H

// �e���v���[�g�^�Ȃ̂ŔC�ӂ̃f�[�^�^�ɑ΂��Ďg�p�\

template<class  T>
void swap(T& x, T& y)
{
	T temp;

	temp = x;
	x  = y;
	y = temp;
}

// �����̂�
void swap1(int *x, int *y);
void swap2(int *x, int *y);

#endif

