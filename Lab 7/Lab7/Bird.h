//Bird.h - header file for child class bird
//Author: Nate Douglas
#pragma once
#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include "Animal.h"
using namespace std;

class Bird : public Animal {
public:
	Bird(string n) : Animal(n) {
		cout << "A Bird " << getName() << " has been created." << endl;
	} 
	void makeNoise();
	void showInfo();
};


#endif // !BIRD_H