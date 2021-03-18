// Lab7.cpp : Main file for the Animal class lab
//Author: Nate Douglas
//Questions:
//1. The base class is Animal
//2. The child (derived) classes are Bird and Dog
//3. Animal does not have a parent class
//4.showInfo and makeNoise are overridden in the child classes, but sleep is not.
//5. If the instance variable name was protected, I believe you would not need to use getters as protected allows access via child classes. 
//but if the access was set to protected, you would still need to use getters.

#include <iostream>
#include "Animal.h"
#include "Bird.h"
#include "Dog.h"
using namespace std;

int main()
{
    Animal* oscar = new Animal("Oscar");
    Dog* inka = new Dog("Inka", "Mutt");
    Bird* tweety = new Bird("Tweety");

    oscar->showInfo();
    inka->showInfo();
    tweety->showInfo();

    oscar->makeNoise();
    inka->makeNoise();
    tweety->makeNoise();

    oscar->sleep();
    inka->sleep();
    tweety->sleep();
}
