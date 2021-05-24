/*Homework 11 - A program that finds a factorial
* Author: Nate Douglas
* Module: 11
* Project: 1
* Problem Statement: Create a program that uses an iterative function to calculate a factorial
* Algorithm:
* 1. Define a prototype for factorial that returns a long long int and takes an int as its parameter
* 2. In factorial, if the parameter is 0, return 1. Otherwise, use a for loop starting at 1 and count up to the provided number. 
* 3. Each loop, use result = result * i to continue to calculate the factorial
* 4. In main, prompt the user for input of a number, and output the result of factorial to the screen. 
*
*/
#include <iostream>
using namespace std;

//Prototype
long long int factorial(int);

int main()
{
    int number;
    //User input version
    /*cout << "Enter a number and I will compute its factorial: ";
    cin >> number;
    cout << number << "! is: " << factorial(number);*/

    //Sample numbers for ease of this assignment
    number = 0;
    cout << number << "! is: " << factorial(number)<<endl;

    number = 1;
    cout << number << "! is: " << factorial(number) << endl;

    number = 2;
    cout << number << "! is: " << factorial(number) << endl;

    number = 5;
    cout << number << "! is: " << factorial(number) << endl;

    number = 10;
    cout << number << "! is: " << factorial(number) << endl;

    number = 20;
    cout << number << "! is: " << factorial(number) << endl;

}

//Definition
long long int factorial(int n) {
    long long int result = 1;
    //If the number submitted is 0, returns 1
    if (n == 0) {
        return result;
    }
    //Otherwise, multiplies result times i each loop
    else {
        for (int i = 1; i <= n; i++) {
            result = result * i;
        }
        return result;
    }
}

