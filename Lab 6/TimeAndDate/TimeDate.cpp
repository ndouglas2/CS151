//TimeDate.cpp - Function Definition file for TimeDate class
//Author - Nate Douglas
#include <iostream>
#include <iomanip>
#include "TimeDate.h"

using namespace std;

string TimeDate::getTimeDate() {
	string print_hour = to_string(hour);
	string am_pm = (hour < 12 ? "am" : "pm");
	if (hour == 0) {
		print_hour = "12";
	}
	if (hour > 12) {
		print_hour = to_string(hour - 12);
	}
	return month + " " + to_string(day) + " at " + print_hour + ":" + (minute < 10 ? "0" : "") + to_string(minute) + am_pm;
}