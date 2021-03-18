/*Programming Chellenge 5 - A program that can detect a palindrome
* Author: Nate Douglas
* Module: 7
* Project: 1
* Problem Statement: Create a program that takes an input string from a user and determins if it is a palindrome
* Algorithm:
* 1. Create header and cpp files for the PString class
* 2. PString is a child of STL string
* 3. PString contains a member function isPalindrome
* 4. In isPalindrome:
*       convert the string to a lowercase string
*       create an if-else if statement that looks to see if the characters being compared are non-letters or numbers and if so, ignores them
*       iterate from both ends of the string, comparing their ascii values to see if they are the same
*       output false if at any time they are not equal
*       output true if the loop finishes successfully
*       
*       
* 5.In main, ask the user for input of a string
* 6. Output the results.
*
*/

#include <iostream>
#include "PString.h"
using namespace std;

int main()
{
    string input;

   
        cout << "Please enter a string." << endl;
        cin >> input;

        PString* userInput = new PString(input);

        if (userInput->isPalindrome(input)) {
            cout << "That string is a palindrome."<<endl;
        }
        else {
            cout << "That string is not a palindrome."<<endl;
        }
    
}
