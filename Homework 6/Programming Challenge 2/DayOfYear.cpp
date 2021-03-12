#include <iostream>
#include <iomanip>
#include <string>
#include "DayOfYear.h"
using namespace std;

//Definition of necessary arrays holding month names, days in a year in monthly increments, and days in each month
const string DayOfYear::months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const int DayOfYear::daysInYear[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
const int DayOfYear::daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

//Constructor
DayOfYear::DayOfYear(int d) {
	//Accepts a day d, and checks to be sure it is in the right range for the year
	if (d >= 1 && d <= 365) {
		setMonth(d);
		if (d > 31) {
			d %= daysInYear[index - 1];
		}
		day = d;
	}
	else {
		cout << "That is not a valid day, please enter a valid date.";
		exit(0);
	}
}

//Takes in a string m and a day d, and checks the month to make sure it is valid, and then the date to make sure it is within the range of days for that month
DayOfYear::DayOfYear(string m, int d) {
	if (isMonthName(m) == true) {
		month = m;
	}
	else {
		cout << "That month does not exist. Exit and try again.";
		exit(0);
	}

	if (d >= 1 && d <= daysInMonth[index]) {
		day = d;
	}
	else {
		cout << "That is not a proper amount of days for your month.";
		exit(0);
	}
}

//Getter
int DayOfYear::getDay() {
	return day;
}

string DayOfYear::getMonth() {
	return month;
}

//Methods
//Sets the month based on a given day value
void DayOfYear::setMonth(int d) {
	bool isFound = false;

	//Loops through the days in a year and sets the array Index and the month based on the day
	for (int i = 0; i < NUM_MONTHS && isFound != true; i++) {
		if (d <= daysInYear[i]) {
			index = i;
			month = months[i];
			isFound = true;
		}
	}
}

//Loops through the month array to determine that the month provided is real
bool DayOfYear::isMonthName(string m) {
	for (int i = 0; i < NUM_MONTHS; i++) {
		if (m == months[i]) {
			index = i;
			return true;
		}
	}
	return false;
}

//Helps Increment the proper day if it increments over 365, or if it goes over the day in a given month
void DayOfYear::helpIncrement() {
	if (month == "December" && day == 31) {
		index = 0;
		month = months[index];
		day = 0;
	}
	else if (day == daysInMonth[index]) {
		month = months[++index];
		day = 0;
	}
}

//Helps Decrement to the proper day if it goes below 0 or out of a month
void DayOfYear::helpDecrement() {
	if (month == "January" && day == 1) {
		index = 11;
		month = months[index];
		day = 31;
	}
	else {
		month = months[--index];
		day = 0;
	}
}

//Overloaded Operators

//Prefix ++
DayOfYear DayOfYear::operator++() {
	helpIncrement();
	++day;

	return *this;
}

//Postfix ++
//Saves the current object as a temp variable, changes the day, then returns the original
DayOfYear DayOfYear::operator++(int) {
	DayOfYear temp = *this;

	helpIncrement();
	day++;

	return temp;
}

//Prefix --
//Runs helpDecrement if the day is 1 and the month needs to be adjusted, otherwise subtracts the day
DayOfYear DayOfYear::operator--() {
	if (day == 1) {
		helpDecrement();
	}
	else {
		--day;
	}
	return *this;
}

//Postfix --
//Similar to above, runs helpDecrement as needed, also stores the object in a temp variable to be returned.
DayOfYear DayOfYear::operator--(int) {
	DayOfYear temp = *this;

	if (day == 1) {
		helpDecrement();
	}
	else {
		day--;
	}
	return temp;
}

//Overloading Stream Extraction
ostream& operator<<(ostream& out, const DayOfYear& output_DayOfYear) {
	out << output_DayOfYear.month << " " << output_DayOfYear.day << "."<<endl;
	return out;
}