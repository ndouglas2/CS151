/*Programming Chellenge 6 - A program that can encrypt a string
* Author: Nate Douglas
* Module: 7
* Project: 2
* Problem Statement: Create a program that takes an input string from a user and "encrypts" it by adding 1 to each ascii value
* Algorithm:
* 1. Create header and cpp files for EncryptableString 
* 2. In the cpp, define a function called encrypt that uses the member variable input as the string
* 3. In encrypt:
*   Check each character in a loop
*   if the character is between 0 and 8, a and z, or A and Z, add 1 to its ascii value and convert that back to a char
*   if the character is 9, make it 0, if it is z make it a and if it is Z make it A
*   otherwise, keep the character the same
*   output the new string to the console
* 4. In main, prompt the user for input in a do-while loop so you can continue the program as long as necessary
*/

#include <iostream>
#include "EncryptableString.h"
using namespace std;

int main()
{
    string input = "";

    do {
        cout << "Please enter a string to be encrypted: ";
        getline(cin, input, '\n');
        //Exits if sentinel is detected
        if (input == "-1") {
            exit(0);
        }
        //Creates new object and runs encrypt on it.
        EncryptableString* userInput = new EncryptableString(input);
        userInput->encrypt();
    } while (input != "-1");
    
}
