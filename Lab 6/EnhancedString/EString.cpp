//EString.cpp - function definition file for EString class
//Author - Nate Douglas
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "EString.h"

using namespace std;

//Constructor
EString::EString(const char* original) {
	size = strlen(original);
	string = new char[size + 1];
	strcpy(string, original);
}

void EString::change(const char* original) {
	delete[] string;
	size = strlen(original);
	string = new char[size + 1];
	strcpy(string, original);
}

void EString::print() {
	cout << string;
}

EString::~EString() {
	delete[] string;
}

//Copy Constructor
EString::EString(const EString& original) {
	size = original.size;
	string = new char[size + 1];
	strcpy(string, original.string);
}
//Assignment Operator overloading
EString& EString::operator=(const EString& original) {
	delete[] string;
	size = original.size;
	string = new char[size + 1];
	strcpy(string, original.string);
	return *this;
}
//Stream Extraction operator Overloading
ostream &operator<<(ostream& out, const EString& output_EString) {
	out << output_EString.string;
	return out;
}