//Function Implementation for Country.h
//Author: Nate Douglas
#include "Country.h"

//Constructors
Country::Country() {
	countryName = "None";
	area = 0;
	pop = 0;
}

Country::Country(string n, int p, int a) {
	countryName = n;
	area = a;
	pop = p;
}

//Getters
string Country::getName() {
	return countryName;
}

int Country::getArea() {
	return area;
}

int Country::getPop() {
	return pop;
}