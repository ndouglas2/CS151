// EnhancedString.cpp - Main file for Lab 6
// Author: Nate Douglas
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "EString.h"
using namespace std;

int main()
{
    EString estring1 = "Hello Miracosta!", estring2;
    estring2 = estring1;

    cout<< "First String: " << estring1 << endl << "Second string: " << estring2 << endl << endl; 
    
    EString new_string1 = "The party starts at Nate's house at 8.";
    EString new_string2 = "It will last for 5 hours.";
    
    //Testing prefix ++
    cout << "The string to all caps using prefix ++: " << ++new_string1<<endl;

    //Testing postfix ++
    cout << "String using the postfix ++ operator: " << new_string1++ << endl;
    cout << "The string now: " << new_string1 << endl;

    //Testing +
    cout << "Both strings combined: " << new_string1 + new_string2 << endl;

    //Testing []
    cout << "Original: ";
    for (int i = 0; i < new_string1.getSize(); i++) {
        cout << new_string1[i] << " ";
    }
    cout << endl;

    cout << "Updated: ";
    for (int i = 0; i < new_string1.getSize(); i++) {
        cout << ++new_string1[i] << " ";
    }
    cout << endl;
}


