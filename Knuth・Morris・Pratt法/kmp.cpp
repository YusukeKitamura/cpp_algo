/***********************************************************
	kmp.cpp -- Knuth--Morris--Pratt–@
***********************************************************/
#include <iostream>
#include "kmp.h"
#define DEMO
const int M = 9;  // M >= strlen(pattern) 

int position(std::string text, std::string pattern)
{
	int tLen = text.length();
	int pLen = pattern.length();
	if (pLen > tLen) {
		std::cerr << "pattern ‚ª’·‰ß‚¬‚Ü‚·I" << std::endl;
		return -1;
	}
	if (pLen == 0) return 0;
	int* next = new int[pLen + 1];

	int i = 1;
	int j = 0; 
	next[1] = 0;
	while (i < pLen) {
		if (pattern[i] == pattern[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else if (j == 0) {
			i++;
			next[i] = j;
		}
		else j = next[j];
	}
#ifdef DEMO
	for (j = 0; j < pLen; j++)
		std::cout << "pattern[" << j << "] = " << pattern[j] << 
			", next[" << (j + 1) << "] = " << next[j + 1] << std::endl;
#endif
	i = j = 0;
	while (i < tLen && j < pLen) {
		if (text[i] == pattern[j]) {
			i++;
			j++;
		}
		else if (j == 0) i++;
		else j = next[j];
	}
	if (j == pLen) return i - j;
	return -1;  // Œ©‚Â‚©‚ç‚È‚¢
}
