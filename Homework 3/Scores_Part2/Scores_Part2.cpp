/*Scores_Part2.cpp : Modify the program from Part 1 to accept class objects with names and scores
* Author: Nate Douglas
* Module : 3
* Project : Project 2
* Problem Statement : Create a program that dynamically allocates memory for a user defined array of test scores, and allows the user to input name-score pairings
*
*Algorithm / Plan :
    * 1. For part 2, create a class called Students that has variables and constructors for name and score
    * 2. Modify the functions from part 1 to sort using Student objects.
    * 3. Run the program again, but this time prompting the user for names and scores
    * 4. Output the results
*/

#include <iostream>
using namespace std;

class Students {
    public:
        void setName(string n);
        void setScore(int s);
        string getName();
        int getScore();
        Students();
        Students(string n, int s);
        ~Students();
        void sortObjects(Students* arr, int* size);
        void objectAvg(Students* arr, int* size);
    private:
        string name;
        int score;
};

//Students Functions
//Constructors and Destructor
Students::Students() {
    name = "null";
    score = 0;
}
Students::Students(string n, int s) {
    name = n;
    score = s;
}
Students::~Students() {

}
//Setters
void Students::setName(string n) {
    name = n;
}
void Students::setScore(int s) {
    score = s;
}
//Getters
string Students::getName() {
    return name;
}
int Students::getScore() {
    return score;
}
//Array Functions
void Students::sortObjects(Students* arr, int* size) {
    Students temp;
    //Sorts the passed array using bubble sort
    for (int i = 0; i < *size - 1; i++) {
        for (int j = 0; j < *size - i - 1; j++) {
            if (arr[j].score > arr[j + 1].score) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    //Prints the sorted array
    for (int k = 0; k < *size; k++) {
        cout << "Name: "<<arr[k].name<<" Score: "<<arr[k].score << endl;
    }
}

void Students::objectAvg(Students* arr, int* size) {
    int total = 0;
    int avg = 0;
    int arrSize = *size;

    //Use if you need to determine that the size is being passed correctly
    //cout << "Array Size = " << arrSize << endl;

    //Runs through each score and adds it to the total
    for (int i = 0; i < arrSize; i++) {
        total += arr[i].score;
    }

    //Calculates average
    avg = total / arrSize;

    cout << endl << " The average for the " << arrSize << " scores in this list is: " << avg;
}

int main()
{
    int* size;
    Students* scorePtr;
    size = new int;
    int score = 0;
    string name = "";
    Students obj;

    cout << " Welcome to test score averager. Please input the number of scores you will be entering: ";
    cin >> *size;
    scorePtr = new Students[*size];

    for (int i = 0; i < *size; i++) {
        cout << "Please enter name " << i + 1 << ": ";
        cin >> name;
        cout << "Please enter the score for " << name << ": ";
        cin >> score;

        if (score < 0 || score > 100) {
            cout << "That is not a valid score, please enter a proper score." << endl;
            i--;
            continue;
        }

        scorePtr[i].setName(name);
        scorePtr[i].setScore(score);
        cout << endl;
    }

    cout << "Scores from lowest to highest: " << endl;
    obj.sortObjects(scorePtr, size);
    obj.objectAvg(scorePtr, size);
    cout << endl << endl;

    delete[] scorePtr;
}