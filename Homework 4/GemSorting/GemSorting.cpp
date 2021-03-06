/*GemSorting.css - Sorts 10 gems randomly into slots in an array
* Author: Nate Douglas
* Module: 4
* Project: 1
* Problem Statement: Create a program that finds an empty slot in an array, and places a new stone in it.
* Algorithm: 
* 1. Create a Stone struct that houses the necessary variables for the slot and the num of attempts
* 2. Create a constructor that sets the name of the slot and the number of attempts
* 3. Create a seed for the random number using srand(time(NULL))
* 4. Create an array of unique pointers
* 5. Create an array of letters to be assigned to slots
* 6. Create a for loop that iterates once for each gem
* 7. Inside that for loop, create a do while loop with an arbitrary attempt limit
* 8. Inside that loop create an if statement that determins if a random slot is empty. If it is, it fills it with a gem. 
* 9. Once the outer loop has finished, output a report to the screen. 

*/
#include <iostream>
#include <iomanip>
#include <memory>
#include <ctime>
using namespace std;

struct Stone {
    char slot;
    int attempts;

    Stone(char slot, int attempts) {
        this->slot = slot;
        this->attempts = attempts;
    }
};


int main() {
    srand(time(NULL));
    unique_ptr<Stone> slots[10];
    char letters[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G','H', 'I', 'J' };
    int randNum = 0;
    int numAttempts = 0;
    int totalAttempts = 0;
    int counter = 0;

    for (int i = 0; i < 10; i++) {
        numAttempts = 1;
        
        do {
            randNum = rand() % 10;
            if (!slots[randNum]) {
                //unique_ptr new_stone(new Stone(letters[i], numAttempts));
                auto new_stone = make_unique<Stone>(letters[i], numAttempts);
                slots[randNum] = move(new_stone);
                //slots[randNum] = unique_ptr<Stone>(new Stone(letters[i], numAttempts));
                break;
            }
            numAttempts++;
        } while (numAttempts<10);

        totalAttempts += numAttempts;
    }

    cout << setw(5) << "Slot" << setw(10) << "Stone" << setw(12) << "Attempts" << endl;

    for (const auto &i : slots) {
        if (i == NULL) {
            cout << "NULL" << endl;;
        }
        else {
            cout <<setw(5)<<counter<<setw(10)<<i->slot<<setw(10)<<i->attempts<<endl;
            
        }
        counter++;
    }

    cout << setw(5) << "Total Attempts: " << totalAttempts;
    




}