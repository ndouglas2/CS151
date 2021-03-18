//Animal.h - header file for parent class Animal
//Author: Nate Douglas
#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal {
private:
	string name;
public:
	//Constructor
	Animal(string n) : name{n} {
		cout << "The Animal " << name << " has been created." << endl;
	}
	//Getters
	string getName();
	//Setters
	void setName(string);
	//Functions
	void sleep();
	void makeNoise();
	void showInfo();
};


#endif // !ANIMAL_H

