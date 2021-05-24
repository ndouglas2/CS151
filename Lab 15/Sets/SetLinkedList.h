#pragma once
/* SetLinkedList.h - Emulates a set in C++
 * Author:     Chris Merrill
 * Module:     15
 * Project:    Lab
 * Problem statement:  Use a linked list to create a class template which
 *      performs the following set functions:
 *
 *    constructor - creates an empty set
 *    contains - returns true if an item is in the set (uses = operator)
 *    insert - adds an item (in sorted order) to the set (duplicates not allowed)
 *    display - shows the contents of the set on the screen
 *    toVector - returns a vector with the elements contained in the set
 *    setUnion - returns another set containing all items from two sets
 *    setIntersect - returns another sets containing items only in both sets
 */

#ifndef SET_LINKEDLIST_H
#define SET_LINKEDLIST_H

#include <vector>
using namespace std;


// Node for each element in the set
template<typename T>
struct SetNode {

    T data;
    SetNode* next;

    SetNode(T new_data, SetNode* link) {     // full constructor
        data = new_data;
        next = link;
    }
};

template<class T>
class Set {

private:
    SetNode<T>* head;

public:
    Set();                                // no-arg constructor
    bool contains(T search_item) const;
    bool insert(T new_item);
    Set<T> setIntersect(Set<T> other_set) const;
    Set<T> setUnion(Set<T> other_set) const;
    void display() const;
    vector<T>* toVector() const;
    Set<T> minus(Set<T> other_set);
    bool equals(Set<T> other_set);
    static void runTests(Set<T> A, Set<T> B);
};

// No-argument constructor creates an empty set (linked list)
template<class T>
Set<T>::Set() {
    head = nullptr;
}

// Returns true if the set contains a specified data element
template<typename T>
bool Set<T>::contains(T search_item) const {
    SetNode<T>* ptr = head;
    while (ptr != nullptr) {
        if (ptr->data == search_item) {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

// Function to add a name to a sorted list.
template<typename T>
bool Set<T>::insert(T new_item) {

    if (contains(new_item))
        return false;                    // already in the list

    // Add to front of the list of if the list is empty or comes before first item
    if (head == nullptr || (head->data > new_item)) {
        head = new SetNode<T>(new_item, head);
        return true;                    // item was added
    }

    // Find the position to insert.  Keep pointers before and after insertion point
    SetNode<T>* after = head;               // will come after the new node
    SetNode<T>* before = nullptr;           // node prior to the insertion point
    while (after != nullptr && after->data <= new_item) {
        before = after;
        after = after->next;
    }
    before->next = new SetNode<T>(new_item, after);
    return true;
}

// Create a third set which is the intersection of two other sets
// Intersection will contain only those elements in both sets
template<typename T>
Set<T> Set<T>::setIntersect(Set<T> other_set) const {

    Set<T> common_set;     // New set to return
    SetNode<T>* pos = head;
    while (pos != nullptr) {
        if (other_set.contains(pos->data))
            common_set.insert(pos->data);
        pos = pos->next;
    }
    return common_set;
}

// Return the union of this set with another set
template<typename T>
Set<T> Set<T>::setUnion(Set<T> other_set) const {

    Set<T> union_set;     // new set to be returned

    // Add contains of calling object set to the new set
    SetNode<T>* pos = head;
    while (pos != nullptr) {
        union_set.insert(pos->data);
        pos = pos->next;
    }

    // Add the elements of the "other_set", avoid duplicates
    pos = other_set.head;
    while (pos != nullptr) {
        union_set.insert(pos->data);
        pos = pos->next;
    }
    return union_set;
}

template<typename T>
void Set<T>::display() const {
    SetNode<T>* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

template<typename T>
vector<T>* Set<T>::toVector() const {
    vector<T>* items = new vector<T>();
    SetNode<T>* ptr = head;
    while (ptr != nullptr) {
        items->push_back(ptr->data);
        ptr = ptr->next;
    }
    return items;
}

template<typename T>
Set<T> Set<T>::minus(Set<T> other_set) { //Iterate through calling set, and only add to new set if it is not contained in parameter set
    Set<T> minus_set; //New set to be returned

    SetNode<T>* ptr = head;
    while (ptr != nullptr) {
        if (other_set.contains(ptr->data)) { //Skips any element that is also contained in the other set. 
            ptr = ptr->next;
            continue;
        }
        minus_set.insert(ptr->data); //Otherwise adds it to the new set.
        ptr = ptr->next;
    }
    return minus_set;
}

template<typename T>
bool Set<T>::equals(Set<T> other_set) {
    //Iterates through calling set first, returning false if any different value is detected
    SetNode<T>* ptr = head;
    while (ptr != nullptr) {
        if (!other_set.contains(ptr->data)) {
            return false;
        }
        ptr = ptr->next;
    }

    ptr = other_set.head; //Then iterates through the other set to ensure it does not simply have more values and some equal
    while (ptr != nullptr) {
        if (!this->contains(ptr->data)) {
            return false;
        }
        ptr = ptr->next;
    }

    return true;
}

template<typename T>
void Set<T>::runTests(Set<T> A, Set<T> B) {
    cout << "The calling set (A): ";
    A.display();
    
    cout << "The parameter set (B): ";
    B.display();

    cout << "The minus set (A-B): ";
    A.minus(B).display();

    cout << "The Intersect set: ";
    A.setIntersect(B).display();

    cout << "The Union of the minus set and the intersect set: ";
    A.minus(B).setUnion(A.setIntersect(B)).display();

    string result;
    result = A.minus(B).setUnion(A.setIntersect(B)).equals(A) ? "True" : "False";
    cout << "Are the union set above and A equal? "<< result<<endl;

}

#endif

