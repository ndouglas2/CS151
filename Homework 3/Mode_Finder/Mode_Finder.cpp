/* Mode_Finder.cpp : Finds the mode of an array of integers
* Author: Nate Douglas
* Module : 3
* Project : Project 3
* Problem Statement : Create a program that dynamically allocates memory for an array of 30 responses, then finds the mode of those responses
*
*Algorithm / Plan :
    * 1. Create a function called sortArray that takes an array as a parameter, and sorts it into ascending order
    * 2. Create a function called modeFinder that takes an array as a parameter and finds its mode
    * 3. In main, dynamically create an array with size 30 in the heap using the new keyword
    * 4. For testing purposes, fill the array with random numbers between 1 and 100 to simulate responses
    * 5. Output the results of the functions using this array
*/

#include <iostream>
using namespace std;

void sortArray(int* arr, int* size) {
    int temp = 0;
    //Sorts the passed array using bubble sort
    for (int i = 0; i < *size - 1; i++) {
        for (int j = 0; j < *size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    //Prints the sorted array
    for (int k = 0; k < *size; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
}

void modeFinder(int* arr, int* size) {
    int current = arr[0];
    int mode = current;
    int count = 1;
    int countMode = 1;

    for (int i = 1; i < *size; i++) {
        if (arr[i] == current) {
            ++count;//Increases the count for the number in arr[i] as long as it remains equal
        }
        else{
            //Sets the mode to the number with the highest count
            if (count > countMode) {
                countMode = count;
                mode = current;
            }
            //Resets the count for the next number in the array
            count = 1;
            current = arr[i];
        }
    }

    cout << "The mode for this array is: " << mode << endl;
}

int main()
{
    int* size, * scorePtr;
    size = new int;
    
    *size = 30;
    scorePtr = new int[*size];

    //For retreiving 30 responses from the user use the following code:
    /*int response = 0;
    cout << "Now Please enter your scores followed by enter: " << endl;
    for (int i = 0; i < *size; i++) {
        cout << "Please enter score " << i + 1 << ": ";
        cin >> response;

        if (response < 0) {
            cout << "That is not a valid number of pieces. Please try again." << endl;
            i--;
            continue;
        }

        scorePtr[i] = response;
        cout << endl;
    }*/

    //Sets a random seed for the array
    srand(time(NULL));

    cout << "Array of responses before sorting:" << endl;
    for (int i = 0; i < *size; i++) {
        scorePtr[i] = rand() % 10 + 1;
        cout << scorePtr[i] << " ";
    }
    cout << endl;

    cout << "Array of responses after sorting:" << endl;
    sortArray(scorePtr, size);
    modeFinder(scorePtr, size);
}
