/***********************************************************
	fukumen.cpp -- 覆面算
	※オブジェクト指向で作ろうとしたらなかなかうまく行かなかったので、結果的に色々いじりました。
	　ある程度Javaの方のソースも参考にしました。
***********************************************************/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include "fukumen.h"

Fukumen::Fukumen(int n):
	imax(n - 1),
	jmax(0),
	solution(0)
{
	for (int i = 0; i <= 9; i++)
		ok[i] = true;
	for (int j = 0; j <= 255; j++)
		digit[j] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 128; j++)
			word[i][j]=0;
	}
		
}

void Fukumen::found()  /* 解の表示 */
{
	std::cout << std::endl;
	std::cout << "解 " << ++solution << std::endl;
	for (int i = 0; i <= imax; i++) {
		for (int j = jmax; j >= 0; j--) {
			int c = word[i][j];
			if (c != '\0') std::cout << digit[c];
			else           std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void Fukumen::search(int sum, int i, int j)  /* 再帰的に試みる */
{
	int c, d, carry;
	c = word[i][j];
	if (i < imax) {
		if ((d = digit[c]) < 0) {  /* 定まっていないなら */
			for (d = low[c]; d <= 9; d++)
				if (ok[d]) {
					digit[c] = d;
					ok[d] = false;
					search(sum + d, i + 1, j);
					ok[d] = true;
				}
			digit[c] = -1;
		} else search(sum + d, i + 1, j);
	} else {
		d = sum % 10;
		carry = sum / 10;
		if (digit[c] == d) {
			if (j + 1 <= jmax) search(carry, 0, j + 1);
			else if (carry == 0) found();
		} else if (digit[c] < 0 && ok[d] && d >= low[c]) {
			digit[c] = d;
			ok[d] = false;
			if (j + 1 <= jmax) search(carry, 0, j + 1);
			else if (carry == 0) found();
			digit[c] = -1;
			ok[d] = true;
		}
	}
}

void Fukumen::set()
{
	int k, c;
	static unsigned char buffer[128];

	for (int i = 0; i < N && i <= imax; i++) {
		std::cout << i + 1 << ":" << std::endl;
		scanf("%127s%*[^\n]", buffer);
		//std::cin >> buffer;
		low[buffer[0]] = 1;
		k = strlen((char *)buffer) - 1;
		if (k > jmax) jmax = k;
		for (int j = 0; j <= k; j++) {
			c = word[i][j] = buffer[k - j];
			if (isalpha(c)) digit[c] = -1;
			else if (isdigit(c)) digit[c] = c - '0';
		}
	}
}
