#pragma once
#ifndef ENCRYPTABLESTRING_H
#define ENCRYPTABLESTRING_H
#include <iomanip>
#include <string>
using namespace std;

class EncryptableString : public string {
private:
	string input;
public:
	EncryptableString(string);
	void encrypt();
};



#endif // !ENCRYPTABLESTRING_H
