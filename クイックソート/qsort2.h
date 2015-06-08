/***********************************************************
	qsort1.h -- �N�C�b�N�\�[�g
***********************************************************/
#ifndef QSORT1_H
#define QSORT1_H

//������
void quicksort(keytype a[], int first, int last);

//�e���v���[�g��
template <typename T> void quicksort_T(int n, T a[])
{
	T x, t;

	x = a[(first + last) / 2];
	int i = first;
	int j = last;
	for ( ; ; ) {
		while (a[i] < x) i++;
		while (x < a[j]) j--;
		if (i >= j) break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		i++;
		j--;
	}
	if (first  < i - 1) quicksort_T(a, first , i - 1);
	if (j + 1 < last) quicksort_T(a, j + 1, last);
}

#endif