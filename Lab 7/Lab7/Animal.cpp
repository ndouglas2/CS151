//Animal.cpp - function definitions for animal.h
//Author: Nate Douglas
#include "Animal.h"
#include <iostream>
using namespace std;

//Constructor defined using list in Animal.h

//Getter
string Animal::getName() {
	return name;
}

//Setter
void Animal::setName(string n) {
	name = n;
}

//Functions
void Animal::sleep() {
	cout << "The Animal " << name << " is asleep." << endl;
}

void Animal::makeNoise() {
	cout << "The Animal " << name << " is making a noise." << endl;
}

void Animal::showInfo() {
	cout << "The animal's name is: " << name << endl;
}