// Lab 9 part 2.cpp : Main file for Part 2
//Author: Nate Douglas

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;



int main()
{
    const string fileName = "array.dat";
    double multiplier;
    fstream data_file(fileName, ios::binary | ios::in | ios::out);
    if (!data_file) {
        cout << "Sorry, that file cannot be opened.";
        exit(1);
    }
    //Prompt user
    cout << "Please enter the multiplier: ";
    cin >> multiplier;
    
    //Read ints, multiply, and store back in file
    cout << "Reading and updating ints..." << endl;
    for (int i = 1; i <= 10; i++) {
        int data;
        long long position = data_file.tellg();
        data_file.read(reinterpret_cast<char*>(&data), sizeof(int));
        cout << data << " -> ";
        data = round(data * multiplier);
        cout << data << endl;
        data_file.seekp(position, ios::beg);//write updated number
        data_file.write(reinterpret_cast<char*>(&data), sizeof(int));
    }

    //Read doubles, multiply, and store back in file
    cout << "Reading and updating doubles..." << endl;
    for (int i = 1; i <= 10; i++) {
        double data;
        long long position = data_file.tellg();
        data_file.read(reinterpret_cast<char*>(&data), sizeof(data));
        cout << data << " -> ";
        data = round(data * multiplier);
        cout << data << endl;
        data_file.seekp(position, ios::beg);//write updated number
        data_file.write(reinterpret_cast<char*>(&data), sizeof(data));
    }
    data_file.close();
}
