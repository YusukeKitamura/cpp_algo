/***********************************************************
	dayweek_test.cpp -- 曜日 テスト用
***********************************************************/
#include "dayweek.h"
#include <iostream>
#include <cstdlib>

int main()
{
	DayWeek dw;
	int y, m, d;
	
	std::cout << "Year? " << std::endl;
	std::cin >> y;
	if (!dw.setYear(y)) return EXIT_FAILURE;
	
	std::cout << "Month?  " << std::endl;
	std::cin >> m;
	if (!dw.setMonth(m)) return EXIT_FAILURE;
	
	std::cout << "Day? " << std::endl;
	std::cin >> d;
	if (!dw.setDay(d)) return EXIT_FAILURE;
	
	std::cout << "It's " << dw.calcDayofweek() << std::endl;
	return EXIT_SUCCESS;
}
