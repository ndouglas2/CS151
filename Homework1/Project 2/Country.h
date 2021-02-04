#pragma once
//Country.h - Header for countries in South America 
//Author: Nate Douglas

#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
using namespace std;

class Country
{
public:
	string countryName;
	int area, pop;

public:
	//Constructors
	Country();
	Country(string, int, int);

	//Getters/Setters
	string getName();
	int getArea();
	int getPop();

}; //End Declaration

#endif // !COUNTRY_H