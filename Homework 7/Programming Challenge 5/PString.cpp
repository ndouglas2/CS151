//PString.cpp - function definitions for PString class
//Author: Nate Douglas

#include <iomanip>
#include <string>
#include "PString.h"
using namespace std;

//constructor defined in PString.h

//Methods
bool PString::isPalindrome(string s) {
	int current = 0;
	int end = s.length() - 1;

	//converts the string to lower case
	for (int i = 0; i <= end; i++) {
		s[i] = tolower(s[i]);
	}

	//compares characters until the current meets the end
	while (current <= end) {
		//accounts for a possible non letter or number at the front by moving up a space without comparison
		if (!((s[current] >= '0' && s[current] <= '9') || (s[current] >= 'a' && s[current] <= 'z'))) {
			current++;
		}
		//accounts for the same but at the end of the string and moves it down a space without comparison
		else if (!((s[end] >= '0' && s[end] <= '9') || (s[end] >= 'a' && s[end] <= 'z'))) {
			end--;
		}
		//If the two are equal, moves both to compare the next sequence
		else if (s[current] == s[end]) {
			current++, end--;
		}
		//returns false if the characters are not equal at any time
		else {
			return false;
		}
	}
	//returns true if the string is a palindrome
	return true;
}