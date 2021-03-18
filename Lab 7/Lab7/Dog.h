//Dog.h - header file for child class dog
//Author: Nate Douglas
#pragma once
#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.h"
using namespace std;

class Dog : public Animal {
private:
	string breed;
public:
	Dog(string n, string b) : Animal(n), breed{ b }{
		cout << "A Dog " << getName() << " of breed " << breed << " has been created."<<endl;
	}
	string getBreed();
	void setBreed(string);
	void makeNoise();
	void showInfo();
};


#endif // !DOG_H

