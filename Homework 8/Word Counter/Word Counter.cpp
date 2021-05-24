/*Homework 8 - C-String Word Counter
* Author: Nate Douglas
* Module: 8
* Project: 1
* Problem Statement: Create a program that can count the number of words in a user input sentance.
* Algorithm:
* 1. Define a prototype for the function wordCounter that takes in a c-string input and returns an int value
* 2. In wordCounter, iterate through the passed string using a while loop and if a space is encountered, increment the count
* 3. Afterwards, increment the count one more time to account for the last word that has no space after it.
* 4. Return the count
* 5. In main, define a constant that is the length allowed for the input string, and then define a char array using that length
* 6. Prompt the user for input of a sentance, and pass it to wordCounter.
* 7. Output the results.
*
*/
#include <iostream>
using namespace std;

//Prototype
int wordCounter(const char* str);


int main()
{
    //Defines the array for input
    const int STR_LENGTH = 41;
    char input[STR_LENGTH];
    //Prompt for input by the user
    cout << "Please enter a sentance of no more than " << STR_LENGTH - 1 << " characters: ";
    cin.getline(input, STR_LENGTH);
    //Output
    cout<<"The number of words in that sentance is: " <<wordCounter(input);
}

//Definition
int wordCounter(const char* str) {
    int count = 0;
    int i = 0;

    //Iterates through the passed string
    while (str[i] != '\0') {
        //If a space is detected, that means a word has passed, so it increases the count
        if (str[i] == ' ') {
            count++;
        }
        i++;
    }
    //Accounts for the last word
    count++;

    return count;
}
