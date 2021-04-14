// Lambda Encrypt.cpp : Encrypts a string using a lambda function
//Author: Nate Douglas

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//Encrypt function
void encrypt(char& character) {
    //Logic determines if it is a character that needs to be wrapped around
    if (character == '9') {
        character = '0';
    }
    else if (character == 'z') {
        character = 'a';
    }
    else if (character == 'Z') {
        character = 'A';
    }
    //If isalnum is true, it adds one to the character's value
    else if (isalnum(character)) {
        character = character + 1;
    }
    //If it is not an alphanum character, keeps it the same
    else {
        character = character;
    }
}

int main()
{
    //Necessary variables
    string input = "";
    string test = "";

    //Loop to continue the process until user quits
    do {
        
        //Intro and processing of input
        cout << "Please enter a string to be encrypted: (Enter quit to quit)" << endl;
        getline(cin, input);
        test = input;
        //Lambda function for converting to lower case
        for_each(test.begin(), test.end(), [](char& c) {c = tolower(c);});

        //If quit is detected, quits
        if (test == "quit") {
            exit(0);
        }

        //Lambda function for running encrypt() on each char of the input
        for_each(input.begin(), input.end(), [](char& c) {encrypt(c);});
        cout << "Your string encrypted is: " << input<<endl;

    } while (test != "quit");
    
}

