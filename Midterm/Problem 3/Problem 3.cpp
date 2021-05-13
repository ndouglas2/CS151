// Problem 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

void reverse() {
    char ch;
    ofstream out_stream;

    //Gets length of file
    out_stream.open("JFK Speech.txt", ios::out);
    out_stream.seekp(0, out_stream.end);
    int length = out_stream.tellp();
    out_stream.close();

    //Opens for input and appending
    fstream input_stream;
    input_stream.open("JFK Speech.txt", ios::in | ios::app);
    input_stream.seekg(--length);

    //Reverses through file and appends to the end
    while (length >= 0) {
        input_stream.get(ch);
        input_stream.seekp(0, input_stream.end);
        input_stream.put(ch);
        length--;
        input_stream.seekg(length);
    }
    input_stream.close();
}


int main() {

    //Problem 1 (Question: 3)
    reverse();
    cout << "Ended program.";

}
