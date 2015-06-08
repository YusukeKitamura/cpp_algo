/***********************************************************
	dayweek.cpp -- —j“ú
***********************************************************/
#include "dayweek.h"
#include <iostream>

DayWeek::DayWeek() :
	year(1),
	month(1),
	day(1),
	dayofweek(1)
{
}

bool DayWeek::setYear(int y)
{
	if (y < 1) {
		std::cout << "Year is  more than 0 !";
		return false;
	}
	
	year = y;
	return true;
}

bool DayWeek::setMonth(int m)
{
	if (m < 1 || m > 12) {
		std::cout << "Month is 1 - 12 !";
		return false;
	}
	
	month = m;
	return true;
}

bool DayWeek::setDay(int d)
{
	if (d < 1 || d > 31) {
		std::cout << "Day is 1 - 31 !";
		return false;
	}
	
	day = d;
	return true;
}

char* DayWeek::calcDayofweek(void)
{
	int y = year;
	int m = month;
	int d = day;
	
	// ‚PŒŽA‚QŒŽ‚Í‘O”N‚Ì‚P‚RŒŽA‚P‚SŒŽ‚Æ‚Ý‚È‚·
	if (m < 3) {
		y--; 
		m += 12; 
	}
	
	dayofweek = (y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7;
	
	return name[dayofweek];
}
