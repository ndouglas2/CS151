//LinkedList Enhancer.cpp- driver file for Lab 14
//Author: Nate Douglas

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    //Generating new list of ints
    LinkedList<int>* list = new LinkedList<int>();
    list->addFirst(1);
    list->addFirst(2);
    list->addFirst(3);
    list->addFirst(4);
    list->addFirst(5);
    list->addFirst(6);

    //Testing display
    cout << "The list contains: " << endl;
    list->display();

    //Testing remove by data value
    cout << "Removing 6 from the list: " << endl;
    list->remove(6);
    list->display();

    //Testing remove by index
    cout << "Removing index 2 from the list:" << endl;
    list->removeAt(3);
    list->display();

    //New list to test with more values
    LinkedList<int>* newList = new LinkedList<int>();
    newList->addFirst(1);
    newList->addFirst(2);
    newList->addFirst(6);
    newList->addFirst(3);
    newList->addFirst(4);
    newList->addFirst(6);
    newList->addFirst(5);
    newList->addFirst(6);

    cout << "new list going forward: " << endl;
    newList->display();

    //testing last index finder
    cout << "Is 6 in the list? " << endl;
    int position = newList->lastIndexOf(6);
    if (position >= 0) {
        cout << "Yes, and its last index is " << position<< endl;
    }
    else {
        cout << "No, it is not." << endl;
    }

    //testing contains
    string result;
    result = newList->contains(10) ? "True" : "False";
    cout << "Is 10 in the list? " << result<<endl;
    result = newList->contains(6) ? "True" : "False";
    cout << "Is 6 in the list? " << result<<endl;

    //Testing change at index
    cout << "Changing index 3 to 10: ";
    newList->set(3, 10);
    newList->display();

}
