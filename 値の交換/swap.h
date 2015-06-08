/***********************************************************
	swap.h -- 値の交換
***********************************************************/
#ifndef SWAP_H
#define SWAP_H

// テンプレート型なので任意のデータ型に対して使用可能

template<class  T>
void swap(T& x, T& y)
{
	T temp;

	temp = x;
	x  = y;
	y = temp;
}

// 整数のみ
void swap1(int *x, int *y);
void swap2(int *x, int *y);

#endif

