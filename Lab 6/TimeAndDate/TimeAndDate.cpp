// TimeAndDate.cpp - Main file for Lab 6, Project 2
//Author - Nate Douglas

#include <iostream>
#include "TimeDate.h"
#include <string>
using namespace std;

class Event {
private:
    TimeDate start_time, end_time;
    string description;
public:
    Event(int start_hour, int start_minute, int start_day, string start_month, int end_hour, int end_minute, int end_day, string end_month, string description) :
        start_time(start_hour, start_minute, start_day, start_month),
        end_time(end_hour, end_minute, end_day, end_month),
        description(description) {};
    string getEvent() {
        return description + " starts on " + start_time.getTimeDate() + ", ends on " + end_time.getTimeDate();
    }

};

int main()
{
    Event party(17, 30, 14, "Oct.", 20, 30, 14, "Oct.", "My Birthday Party");
    cout << party.getEvent() << endl;
    Event csClass(17, 30, 11, "Mar.", 21, 20, 11, "Mar.", "C++ Class");
    cout << csClass.getEvent() << endl;
}

