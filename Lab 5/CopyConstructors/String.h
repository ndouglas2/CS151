#pragma once
#ifndef STRING_H
#define STRING_H


class String {
private:
	char* string;
	int size;
public:
	String(const char* s = "");
	~String();
	void print();
	void change(const char*);
	String(const String&);
};

#endif