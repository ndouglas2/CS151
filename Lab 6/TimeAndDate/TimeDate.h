//TimeDate.h - Header file for the TimeDate class
//Author- Nate Douglas
#pragma once
#ifndef TIMEDATE_h
#define TIMEDATE_h
#include <string>
using namespace std;

class TimeDate {
private:
	int hour, minute, day;
	string month;
public:
	TimeDate(int hour, int minute, int day, string month) :
		hour(hour),
		minute(minute),
		day(day),
		month(month) {};
	string getTimeDate();
};


#endif // !TIMEDATE.h
