/***********************************************************
	statutil_test.cpp -- 多変量データ テスト
***********************************************************/
#include <iostream>
#include "matutil.h"
#include "statutil.h"

int main()
{
	StatUtil stat;
	int errval = stat.read_data("test.csv");
	if (errval == 999) {
		std::cerr << "データ読み込み失敗！！" << std::endl;
		return EXIT_FAILURE;  /* 失敗 */
	}

	for (int i = 0; i < stat.rows; i++) {
		for (int j = 0; j < stat.cols; j++) {
			if (readerror(stat.mat(i, j) ))
				std::cout << "ERR,";  /* 読込失敗 */
			else if (missing(stat.mat(i, j)))
				std::cout << "_,";  /* 欠測値 */
			else
				std::cout << stat.mat(i, j) << ",";  /* 正常 */
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}
