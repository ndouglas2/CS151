#include <iostream>
#include "EncryptableString.h"
using namespace std;

EncryptableString::EncryptableString(string i) {
	input = i;
}

void EncryptableString::encrypt() {
	int length = input.length() - 1;
	char asciiChar;

	for (int i = 0; i <= length; i++) {
		if (input[i] == '9') {
			input[i] = '0';
		}
		else if (input[i] == 'z') {
			input[i] = 'a';
		}
		else if (input[i] == 'Z') {
			input[i] = 'A';
		}
		else if (((input[i] >= 'a' && input[i] <= 'y') || (input[i] >= 'A' && input[i] <= 'Y') || (input[i] >= '0' && input[i] <= '8'))) {
			asciiChar = input[i] + 1;
			input[i] = asciiChar;
		}
		else {
			input[i] = input[i];
		}
	}

	cout << "That string encrypted is: ";
	for (int j = 0; j <= length; j++) {
		cout << input[j];
	}
	cout << endl;
}