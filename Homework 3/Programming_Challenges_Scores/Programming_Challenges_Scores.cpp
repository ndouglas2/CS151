/*Programming_Challenges_Scores.cpp : Dynamically creates an array for test scores, lets the user define size and scores.
* Author: Nate Douglas
* Module : 3
* Project : Project 1
* Problem Statement : Create a program that dynamically allocates memory for a user defined array of test scores, and allows the user to input scores
*
*Algorithm / Plan :
    * 1. Create a function called sortArray that takes an array as a parameter, and sorts it into ascending order
    * 2. Create a function called arrayAvg that takes the array as a parameter and outputs the average of all scores.
    * 3. In main, dynamically create an array in the heap using the new keyword
    * 4. Ask the user for the number of scores they will be inputting, and set the array to that size.
    * 5. Output the results of the functions using this array

 */

#include <iostream>
using namespace std;

void sortArray(int *arr, int *size) {
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
        cout << arr[k] << endl;
    }
}

void arrayAvg(int *arr, int *size) {
    int total = 0;
    int avg = 0;
    int arrSize = *size;

    //Use if you need to determine that the size is being passed correctly
    //cout << "Array Size = " << arrSize << endl;

    //Runs through each score and adds it to the total
    for (int i = 0; i < arrSize; i++) {
        total += arr[i];
    }

    //Calculates average
    avg = total / arrSize;

    cout <<endl<< " The average for the " << arrSize << " scores in this list is: " << avg;
}

int main()
{
    int *size, *scorePtr;
    size = new int;
    int score = 0;

    cout << " Welcome to test score averager. Please input the number of scores you will be entering: ";
    cin >> *size;
    scorePtr = new int[*size];

    cout << "Now Please enter your scores followed by enter: " << endl;
    for (int i = 0; i < *size; i++) {
        cout << "Please enter score " << i + 1 <<": ";
        cin >> score;

        if (score < 0 || score > 100) {
            cout << "That is not a valid score, please enter a proper score."<< endl;
            i--;
            continue;
        }

        scorePtr[i] = score;
        //cout << scorePtr[i]<<endl;
        cout << endl;
    }

    cout << "The scores you entered sorted from lowest to highest: "<<endl;
    sortArray(scorePtr, size);
    arrayAvg(scorePtr, size);

    delete[] scorePtr;
}
