/*Programming Chellenges 2 & 3 - A program that converts from day number to month/day and vice versa
* Author: Nate Douglas
* Module: 6
* Project: 1
* Problem Statement: Create a program that translates from an entered day number to month and day
* Algorithm:
* 1. Create header and .cpp files for the DayOfYear class
* 2 In the header file, create prototypes for the following methods:
*       two constructors, one that just takes an int and one that takes a string and an int
*       getters for the month and day
*       a bollean checker for a valid month
*       a setter for the month
*       two helpers that decrement and increment the month and day
*       Overloaded methods for the prefix and postfix ++ and --, as well as <<
* 3. In the .cpp file define these methods with their necessary functions.
* 4. For instance, the constructors will check to see if the input is even correct, before setting the month and dates.
* 5. The month checker will check the input month against the month array to see if it is valid. 
* 6. The two helpers will handle if the date goes below 0 or above 365
* 7. In main, test these methods with 15, 31, 59, 180 and 360. 
* 8. Demonstrate that both the prefix and postfix operators change the values.
* 9. Demonstrate that the << operator can print an object now. 
* 

*/

#include <iostream>
#include "DayOfYear.h"
using namespace std;

int main()
{
    int day = 0;
    string monthName = "";

    cout << "This Program will translate day numbers to Month-Day Format and vice versa."<<endl;

    //Creating objects for the required days so that I don't have to do multiple user inputs
    cout << "Day 15: " << endl;
    DayOfYear day15(15);
    cout << day15;

    cout << "Day 31: " << endl;
    DayOfYear day31(31);
    cout << day31;

    cout << "Day 59: " << endl;
    DayOfYear day59(59);
    cout << day59;

    cout << "Day 180: " << endl;
    DayOfYear day180(180);
    cout << day180;

    cout << "Day 360: " << endl;
    DayOfYear day360(360);
    cout << day360;

    //Demonstrating User input
    cout << "Please enter a day and I will translate it to month and day" << endl;
    cin >> day;
    DayOfYear day1(day);

    cout << "That day translated is: " << endl;
    cout << day1;

    //Demonstrates decrement operators
    cout << "The day before is: " << endl;
    (--day1);
    cout << day1;

    cout << "And the day before that is: " << endl;
    (day1--);
    cout << day1;

    //Demonstrates input of month and dat
    cout << "Please enter a month name: "<<endl;
    cin >> monthName;

    cout << "Now enter a day of this month: "<<endl;
    cin >> day;

    DayOfYear day2(monthName, day);
    cout << "Demonstrating the overloaded << operator: " << endl;
    cout << " The month and day you entered is: " << endl;
    cout << day2;

    //Demonstrates increment operators
    cout << "Demonstrating the overloaded ++ operators" << endl;
    cout << "The next day after your date is: " << endl;
    ++day2;
    cout << day2;

    cout << "The day after that is: " << endl;
    day2++;
    cout << day2;
}

