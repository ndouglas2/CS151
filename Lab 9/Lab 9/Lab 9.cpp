// Lab 9.cpp : Main file for lab 9
//Author: Nate Douglas

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;



int main()
{
    const string fileName = "array.dat";
    ofstream data_file(fileName, ios::binary | ios::out);
    if (!data_file) {
        cout << "Sorry, that file cannot be opened.";
        exit(1);
    }
    //Nums 1-10
    for (int i = 1; i <= 10; i++) {
        data_file.write(reinterpret_cast<char*>(&i), sizeof(int));
    }
    //Square Roots
    for (int i = 1; i <= 10; i++) {
        double squareRoot = sqrt(i);
        data_file.write(reinterpret_cast<char*>(&squareRoot), sizeof(squareRoot));
    }
    data_file.close();
}

