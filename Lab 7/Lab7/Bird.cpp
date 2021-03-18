//Bird.cpp - function definitions for bird.h
//Author: Nate Douglas
#include "Bird.h"
#include <iostream>
using namespace std;

//Constructor defined in Bird.h

//Methods
void Bird::makeNoise() {
	cout << "The Bird " << getName() << " is chirping"<<endl;
}

void Bird::showInfo() {
	cout << "The Bird's name is: " << getName() << endl;
}