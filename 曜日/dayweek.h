/***********************************************************
	dayweek.h -- —j“ú
***********************************************************/
#ifndef DAYWEEK_H
#define DAYWEEK_H

static char name[7][10] = {
	"Sunday", "Monday", "Tuesday", "Wednesday",
	"Thursday", "Friday", "Saturday" };

class DayWeek {
private:
	int year;
	int month;
	int day;
	int dayofweek;

public:
	DayWeek();
	bool setYear(int y);
	bool setMonth(int m);
	bool setDay(int d);
	char* calcDayofweek(void);
};

#endif
