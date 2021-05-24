/*Homework 8 - C-String Password Verifyer
* Author: Nate Douglas
* Module: 8
* Project: 2
* Problem Statement: Create a program that verifies a password meets the provided conditions
* Algorithm:
* 1. Define a prototype for the function verifyPassword that takes in a c-string and returns true or false
* 2. In verifyPassword, define variables for the counter, the length, uppercase count, lowercase count, number count, and blanks count
* 3. Iterate through the string, and if any of the above conditions is met, increment the appropriate counter
* 4. Define an If else statement, where the If condition is that if length is less than 6, or uppercase is less than 1 or lowercase is less than 1 or digits is less than 1 or blanks is more than 1
* 5. If any of these conditions are met, output the appropriate message(s) to the screen and return false
* 6. Otherwise, return true
* 7. In main, prompt the user for input and store it in a password char array
* 8. Call verifyPassword on the input, and if it is false, exit the program with the messages output to the screen
* 9. If it is true, tell the user it is acceptable and then exit
*
*/
#include <iostream>
#include <cctype>
using namespace std;

//Function prototype
bool verifyPassword(const char*);

int main()
{
    const int PASSWORD_LENGTH = 20;
    char password[PASSWORD_LENGTH];

    cout << "Please enter your password now and I will verify that it is acceptable: ";
    cin.getline(password, PASSWORD_LENGTH);

    cout << "Your password failed for the following reasons: " << endl;
    if (!verifyPassword(password)) {
        exit(0);
    }
    else {
        cout << "NONE" << endl;
        cout << "Your password is acceptable!"<<endl;
    }
}

//Function Definition
bool verifyPassword(const char* password) {
    int i = 0;
    int length = strlen(password);
    int upperCount = 0;
    int lowerCount = 0;
    int digitCount = 0;
    int blanksCount = 0;

    //Loops through the password, incrementing the necessary counts if those characters are detected
    while (password[i] != '\0') {
        if (isupper(password[i])) {
            upperCount++;
        }
        if (islower(password[i])) {
            lowerCount++;
        }
        if (isdigit(password[i])) {
            digitCount++;
        }
        if (password[i] == ' ') {
            blanksCount++;
        }
        i++;
    }

    //Logic to determine if the password is acceptable
    if (length < 6 || upperCount < 1 || lowerCount < 1 || digitCount < 1 || blanksCount > 0) {
        if (length < 6) {
            cout << "Password too short" << endl;
        }
        if (upperCount < 1) {
            cout << "No uppercase characters" << endl;
        }
        if (lowerCount < 1) {
            cout << "No lowercase characters" << endl;
        }
        if (digitCount < 1) {
            cout << "No numbers" << endl;
        }
        if (blanksCount > 0) {
            cout << "Password cannot contain blanks" << endl;
        }
        return false;
    }
    //Returns true if meets parameters
    else {
        return true;
    }
    

}

