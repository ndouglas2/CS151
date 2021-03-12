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
}


