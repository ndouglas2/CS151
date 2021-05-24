//Sets.cpp - Driver Program for lab 15
//Author: Nate Douglas

#include <iostream>
#include<vector>
#include "SetLinkedList.h"
using namespace std;

int main()
{
    Set<string> set1_A;
    set1_A.insert("C");
    set1_A.insert("G");
    set1_A.insert("E");
    set1_A.insert("A");

    Set<string> set1_B;
    set1_B.insert("E");
    set1_B.insert("C");
    set1_B.insert("F");

    //Output for comparing Test sets 1
    cout << "Test 1: " << endl;
    Set<string>::runTests(set1_A, set1_B);
    cout << endl;

    Set<string> set2_A;
    set2_A.insert("Carlos");
    set2_A.insert("John");
    set2_A.insert("Alice");

    Set<string> set2_B;
    set2_B.insert("John");
    set2_B.insert("Henry");
    set2_B.insert("Maria");

    //Output for comparing test sets 2
    cout << "Test 2: " << endl;
    Set<string>::runTests(set2_A, set2_B);
    cout << endl;

    Set<int> set3_A;
    set3_A.insert(5);
    set3_A.insert(1);
    set3_A.insert(3);

    Set<int> set3_B;
    set3_B.insert(1);
    set3_B.insert(3);
    set3_B.insert(5);
    set3_B.insert(7);
    set3_B.insert(9);

    //Output for comparing test sets 3;
    cout << "Test 3: " << endl;
    Set<int>::runTests(set3_A, set3_B);
    cout << endl;

    Set<int> set4_A;
    set4_A.insert(5);

    Set<int> set4_B;

    //Output for comparing test sets 4;
    cout << "Test 4: " << endl;
    Set<int>::runTests(set4_A, set4_B);
    cout << endl;
}
