/*homework1 project 1.cpp
* Author: Nate Douglas
* Module: 1
* Project: Homework 1
* Problem Statement: Create a vector of random numbers in descending order and then use the pop_back function to display them in ascending order
* 
* Algorithm/Plan:
* 1. Create a new seed based on the time to ensure that the numbers are random every time it is run
* 2. Use a for loop set to 30 iterations to generate 30 random numbers and add them to the vector
* 3. Sort the vector into descending order as the values are added. 
* 4. Print the vector in this order to show what values are used.
* 5. Use the pop_back function and a for loop set to 30 iterations to print the vector from the bottom, thus printing it in ascending order.

*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main()
{
	vector <int> randoms;
	int randomNum = 0;
	int highest = 0;
	int lowest = 0;
	
	//Random Seed
	srand(time(NULL));

	for (int i = 0; i < 30; i++) {
		//Generates Num between 1 and 10
		randomNum = rand() % 10 + 1;

		//If the vector is empty, puts the first value at the beginning
		if (randoms.size() == 0) {
			randoms.insert(randoms.begin(), randomNum);
		}
		//Otherwise sorts through vector to find position of highest number
		else {

			/*for (int j = 1; j < randoms.size(); j++) {
				if (randoms.at(highest) < randoms.at(j)) {
					highest = j;
				}
			}
			if (randoms.at(highest) < randomNum || randoms.at(highest) == randomNum) {
				randoms.insert(randoms.begin() + highest, randomNum);
			}
			else {
				
			}*/

			randoms.insert(randoms.begin(), randomNum);
		}
	}

	//I know you wanted the vector to be sorted at value added time, but for the life of me I could not figure it out. I commented out as far as I got though.
	sort(randoms.begin(), randoms.end(), greater<int>());

	cout << "Descending order:" << "\n";
	for (int k = 0; k < randoms.size(); k++) {
		cout << randoms.at(k) << " ";
	}
	
	//Adds space for readability
	cout << "\n";
	cout << "\n";

	cout << "Ascending order:" << "\n";
	for (int l = 0; l < 30; l++) {
		cout << randoms.back() <<" ";
		randoms.pop_back();
	}

}
