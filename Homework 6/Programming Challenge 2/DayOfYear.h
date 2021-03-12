#pragma once
#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <string>
using namespace std;

const int NUM_MONTHS = 12;

class DayOfYear {
private:
	int day;
	int index;
	string month;
	const static string months[NUM_MONTHS];
	const static int daysInYear[NUM_MONTHS];
	const static int daysInMonth[NUM_MONTHS];


public:
	//Constructors
	DayOfYear(int d);
	DayOfYear(string, int);
	//Getters
	string getMonth();
	int getDay();
	//Methods
	bool isMonthName(string);
	void setMonth(int);
	void helpIncrement();
	void helpDecrement();
	//Overloaded Operators
	friend ostream& operator<<(ostream&, const DayOfYear&);
	DayOfYear operator++();
	DayOfYear operator++(int);
	DayOfYear operator--();
	DayOfYear operator--(int);
};

#endif // !DAYOFYEAR_H
