//PString.h - header file for PString class
//Author: Nate Douglas
#pragma once
#ifndef PSTRING_H
#define PSTRING_H
#include <iomanip>
#include <string>
using namespace std;

class PString : public string {
public:
	PString(string s) : string(s){}
	bool isPalindrome(string s);
};


#endif