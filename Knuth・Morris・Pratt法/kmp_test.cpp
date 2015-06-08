/***********************************************************
	kmp_test.cpp -- Knuth--Morris--Pratt法　テスト用
***********************************************************/
#include <cstdlib>
#include <iostream>
#include "kmp.h"

int main()
{
	std::string text = "ABCABCABABC";
	std::string pattern = "ABCABA";

	std::cout << "position(\" " << text << "\", \"" << pattern << 
		"\") = " << position(text, pattern) << std::endl;
	return EXIT_SUCCESS;
}
