//EString.h - header file for EString class
//Author - Nate Douglas
#pragma once
#ifndef ESTRING_H
#define ESTRING_H
using namespace std;

class EString {
private:
	char* string;
	int size;
public:
	EString(const char* s = "");
	~EString();
	void print();
	void change(const char*);
	EString(const EString&);
	int getSize();
	EString& operator=(const EString&);
	friend ostream& operator<<(ostream &, const EString &);
	EString operator++();
	EString operator++(int);
	char& operator[](int);
	friend EString operator+(const EString&, const EString&);
};

#endif