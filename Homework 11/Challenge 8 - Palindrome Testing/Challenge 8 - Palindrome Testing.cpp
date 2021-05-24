/*Homework 11 - A program that validates a palindrome
* Author: Nate Douglas
* Module: 11
* Project: 3
* Problem Statement: Create a program that uses a recursive function to validate if a string is a palindrome or not
* Algorithm:
* 1. Define a prototype for isPalindrome, as well as remove_punct_and_spaces
* 2. In the remove function, loop through the string, and if a punctuation mark or space is detected, remove it and return the new string
* 3. In isPalindrome, while the lower value is less than the upper value, compare the two indexes
* 4. If they are equal, increment lower, decrement upper, and call isPalindrome again with the new values
* 5. If they are not equal at any time, return false
* 6. If the entire string has been parsed, return true
* 7. In main, prompt for user input. If the string is empty, quit the program. 
* 8. Pass the input to the remove function. 
* 9. Then, create an if else structure that returns the correct output for isPalindrome.
*
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Function prototype 
bool isPalindrome(string str, int lower, int upper);
string remove_punct_and_spaces(string str, int size);

int main()
{
    string input;

    do {
        //Sets input back to length 0
        //Prompt for user input
        input = "";
        cout << "Please enter your word / sentance (Simply press enter to quit) : ";
        getline(cin, input);
        if (input.length() == 0) {
            exit(0);
        }
        //Removes spaces and punctuation
        input = remove_punct_and_spaces(input, input.size());
        
        //Output based on palindrome or not
        if (isPalindrome(input, 0, input.length() - 1)) {
            cout << "That is a palindrome!" << endl<<endl;
        }
        else {
            cout << "That is not a palindrome, sorry." << endl<<endl;
        }

    } while (input.length() != 0);
}

//Definition
string remove_punct_and_spaces(string str, int size) {
    for (int i = 0; i < size; i++) {
        //Erases any punctuation or spaces
        if (ispunct(str[i]) || str[i] == ' ') {
            str.erase(i--, 1);
            size = str.size();
        }
    }

    //Converts string to lower case
    for (int k = 0; k < size; k++) {
        str[k] = tolower(str[k]);
    }
    return str;
}


bool isPalindrome(string str, int lower, int upper) {
    //Logic for detecting palindrome
    while (lower <= upper) {
        if (str[lower] == str[upper]) {
            lower++, upper--;
            isPalindrome(str, lower, upper);
        }
        else {
            return false;
        }
    }
    return true;
}

