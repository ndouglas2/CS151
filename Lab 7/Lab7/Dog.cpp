//Dog.cpp - function definitions for dog.h
//Author - Nate Douglas
#include "Dog.h"
#include <iostream>
using namespace std;

//constructor defined in dog.h

//Getter
string Dog::getBreed() {
	return breed;
}

//Setter
void Dog::setBreed(string b) {
	breed = b;
}

//Methods
void Dog::makeNoise() {
	cout << "The Dog " << getName() << " is barking." << endl;
}

void Dog::showInfo() {
	cout << "The dog's name is " << getName() << " and is of breed " << breed << endl;
}