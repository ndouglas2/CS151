/*Homework 11 - A program that searches an array
* Author: Nate Douglas
* Module: 11
* Project: 2
* Problem Statement: Create a program that uses a recursive function to search through a user defined array of ints
* Algorithm:
* 1. Define a prototype for isMember that takes an array, the size, and a value to be searched as the parameters
* 2. In isMember, if the size = 0 and that first value does not equal the value, return false
* 3. If at any point, the index does equal the value, return true
* 4. Otherwise, call isMember again but with size - 1 as the middle parameter
* 5. In Main, prompt the user to input an array of numbers
* 6. In a do while loop, have the user input numbers to be searched for
* 7. With each number, call isMember and output the results to the screen
*
*/
#include <iostream>
using namespace std;

//Prototype
bool isMember(int arr[], int n, int value);

int main()
{
    //Necessary variables
    const int SIZE = 10;
    int array[SIZE];
    int number = 0;

    //Prompt for array input
    cout << "Please enter " <<SIZE<<" numbers: "<<endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> array[i];
    }

    //Allows the user to search for as many numbers as desired
    do {

        cout << "Please enter the number you wish to check for (Enter - 1 to quit): ";
        cin >> number;

        string result = isMember(array, SIZE, number) ? "True" : "False";
        cout << "Does the array contain " << number << "? " << result<<endl<<endl;

    } while (number != -1);
}

bool isMember(int arr[], int n, int value) {
    //If the last index has been reached, and it is not equal to the value, return false
    if (n == 0 && arr[0] != value) {
        return false;
    }

    //If the index and value are equal, return true
    if (arr[n] == value) {
        return true;
    }
    //call the function with size - 1 if not found yet
    else {
        isMember(arr, n - 1, value);
    }
}