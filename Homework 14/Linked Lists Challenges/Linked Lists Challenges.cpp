/*Homework 14 - A series of linked list functions
* Author: Nate Douglas
* Module: 14
* Project: 1
* Problem Statement: Create a program that can add to, search, insert and print a linked list
* Algorithm:
* 1. Creat a new class LinkedList that contains the LinkNode struct from the book
* 2. Create prototypes for add, isMember, print, reverse, search, and insert
* 3. In LinkedList.cpp, define these functions.
* 4. Add simply adds a new node at the top of the list by setting the head equal to a new node
* 5. isMember traverses the list, and if the value of the node is equal to the passed value it returns true. If not found it returns false.
* 6. Print simply traverses through the list, and prints each node to the console. 
* 7. Insert traverses through the list position times, while swapping the previous and the next nodes in order to insert properly.
* 8. Search uses the same logic as is member, but returns the position instead of true/false
* 9. reverse sets the current node to the head, then the next node to current's next, then current's next to the previous node, then the previous node to the current node, and finally the current node to the next. 
* 10. Test these in main by creating a basic list with the example values and testing each method. 
*
*/

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList* list = new LinkedList();
    list->add(7.0);
    list->add(8.0);
    list->add(9.0);

    //Testing isMember
    string result;
    result = list->isMember(5.0) ? "True" : "False";
    cout << "Is 5.0 in the list? " << result<<endl ;
    result = list->isMember(7.0) ? "True" : "False";
    cout<<"Is 7.0 in the list? "<<result << endl;
    result = list->isMember(9.0) ? "True" : "False";
    cout<<"Is 9.0 in the list? "<<result<< endl;

    //Testing print
    LinkedList* emptyList = new LinkedList();
    cout << "This list should be empty: "<<endl;
    emptyList->print();
    cout << "This list has values: "<<endl;
    list->print();

    //Testing reverse
    cout << "The list before reversing: " << endl;
    list->print();
    cout << "The list after: " << endl;
    list->reverse();
    list->print();

    //Testing search
    cout << "Is 7.0 in the list?" << endl;
    int position = list->search(7.0);
    if (position >= 0) {
        cout << " Yes, and it is at index" << position<<endl;
    }
    else {
        cout << "No, it was not found."<<endl;
    }

    cout << "Is 5.0 in the list?" << endl;
    position = list->search(5.0);
    if (position >= 0) {
        cout << " Yes, and it is at index " << position<<endl;
    }
    else {
        cout << "No, it was not found." << endl;
    }

    //Testing insert
    cout << "The list before the insert: " << endl;
    list->print();
    cout << "The list after inserting 5 at position 1: " << endl;
    list->insert(5.0, 1);
    list->print();
    cout << "The list after inserting 2 at position 0: " << endl;
    list->insert(2.0, 0);
    list->print();


}

