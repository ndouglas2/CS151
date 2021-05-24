//EString.cpp - function definition file for EString class
//Author - Nate Douglas
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
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

int EString::getSize() {
	return size;
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

//Prefix ++ operator overloading
EString EString::operator++() {
	//Iterates through the string, and uppercases each letter
	for (int i = 0; i < strlen(string); i++) {
		string[i] = toupper(string[i]);
	}

	return *this;
}

//Postfix ++ operator overloading;

EString EString::operator++(int) {
	//Creates a copy of the calling object
	EString copy = *this;

	//Iterates through the string, and lowercases each letter
	for (int i = 0; i < strlen(string); i++) {
		string[i] = tolower(string[i]);
	}

	return copy;
}

//[] Operator overloading

char& EString::operator[](int index) {
	//If the index is less than 0 or greater than the length, quits the program
	if (index < 0 || index>strlen(string)) {
		cout << "ERROR: Invalid Index.";
		exit(0);
	}
	//return *addressof(string[index]);
	return string[index];
}

//+ operator overloading
EString operator+(const EString& first, const EString& second) {
	char* temp = new char[first.size + second.size + 1];
	strcpy(temp, first.string);
	strcat(temp, second.string);
	EString* both = new EString(temp);
	return *both;
}