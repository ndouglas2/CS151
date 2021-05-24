/*NumberstoEnglish.cpp - A program that converts an integer to its text equivalent
* Author: Nate Douglas
* Module: 5
* Project: 1
* Problem Statement: Create a program that can convert a user entered int to its text equivalent
* Algorithm:
* 1. Define a Numbers class, with a single instance variable number, and a series of static constants that contain the text required for the conversions
* 2. The constructor takes one int argument, and exits the program if it is negative.
* 3. There should be one member function, print(), that contains all of the conversion logic.
* 4. In print, define variables for thousands, hundreds, tens, and the remainder as well as the output as a string. 
* 5. Similar to the change problem for vending machines, start with the highest value(thousands) and do a series of divisions and modulo operations to determine the individual place numbers and the remainder afterwards
* 6. Use the individual place numbers as the index of the lessThan20 array to determine the number that gets displayed.
* 7. Finally, in the 10s place, include logic for a remainder that is greater than 20, between 0 and 20, and equal to 20
* 8. In main, create a do while loop that continues until a negative number is detected.
* 9. Prompt for user input, create a new Numbers object with that input, and call print() with that number.
*
*/
#include <iostream>
using namespace std;

class Numbers {
private:
    int number;
    static const string lessThan20[];
    static const string tens[];
    static const string hundred;
    static const string thousand;
public:
    Numbers(int n) {
        //Exists the program if the number entered is negative
        if (n < 0) {
            cout << "The number cannot be negative.";
            exit(0);
        }
        cout << "Initialized: " << n << endl;
        number = n;
    }
    void print() {
        int thousands;
        int hundreds;
        int ten;
        int remainder;
        string output = "";

        //Creates the thousands place
        thousands = number / 1000;
        if (thousands > 0) {
            output = output + lessThan20[thousands] + " " + thousand + " ";
        }

        //Creates the hundreds place
        remainder = number % 1000;
        hundreds = remainder / 100;
        if (hundreds > 0) {
            output = output + lessThan20[hundreds] + " " + hundred + " ";
        }

        //Creates the tens and ones places
        remainder = remainder % 100;
        ten = remainder / 10;
        if (remainder >= 20) {
            //Prevents the output from putting zero at the end
            if (remainder % 10 == 0) {
                output = output + tens[ten - 2];
            }
            else {
                output = output + tens[ten - 2] + " " + lessThan20[remainder % 10];
            }
        }
        else if (remainder < 20 && remainder>0) {
            output = output + lessThan20[remainder];
        }
        else if (remainder == 0) {
            output = output;
        }

        //Outputs to console
        cout <<number<<" In words: "<< output<<endl<<endl;
    }
    
};

//Constants declarations
const string Numbers::lessThan20[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty" };
const string Numbers::tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const string Numbers::hundred = "hundred";
const string Numbers::thousand = "thousand";

int main()
{
    //the one variable for input
    int input;
    
    //Loop to allow multiple entries
    do {
        cout << "Please enter a number between 0 and 9999. Enter a negative to quit ";
        cin >> input;
        //Declares new object with the input
        Numbers* userInput = new Numbers(input);
        userInput->print();
    } while (input > 0);

}

