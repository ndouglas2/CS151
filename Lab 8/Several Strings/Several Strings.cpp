// Several Strings.cpp : Uses several string functions to manipulate input
//Author: Nate Douglas

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{ 
    int sentinel = 0;
    do {
        //Prompt for integer
        int original = 0;
        cout << "Please enter an integer: (Enter - 1 to quit)";
        cin >> original;
        sentinel = original;

        //Exits if -1 is detected
        if (sentinel == -1) {
            exit(0);
        }

        //Converts it to a string
        string original_as_string = to_string(original) + " rah!";
        cout << original_as_string << endl;

        //Converts it back into an int
        istringstream inpstr(original_as_string);
        int original_copy;
        inpstr >> original_copy;
        cout << "The original number: " << original_copy << endl;

        //Converts to binary
        char* binary = new char[33];
        *(binary + 32) = '\0';
        int index = 32;
        do {
            *(binary + (--index)) = (char)(original_copy % 2 + '0');
            original_copy /= 2;
        } while (original_copy > 0);
        cout << "That number in binary is: " << (binary + index) << endl;

        //Converts back to decimal
        original_copy = stoi((binary + index), nullptr, 2);
        cout << "The original number again: " << original_copy << endl;

        //Converts to hex
        stringstream iostr;
        iostr << hex << original;
        cout << "The number in hexadecimal: " << hex << original << endl;

        //Converts back to decimal
        iostr >> hex >> original_copy;
        cout << "Back to decimal: " << dec << original_copy << endl;
    } while (sentinel != -1);
    
}

