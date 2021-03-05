#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "String.h"

using namespace std;

//Constructor
String::String(const char* original) {
	size = strlen(original);
	string = new char[size + 1];
	strcpy(string, original);
}

void String::change(const char* original) {
	delete[] string;
	size = strlen(original);
	string = new char[size + 1];
	strcpy(string, original);
}

void String::print() {
	cout << string;
}

String::~String() {
	delete[] string;
}

String::String(const String& original) {
	size = original.size;
	string = new char[size + 1];
	strcpy(string, original.string);
}