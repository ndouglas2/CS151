//LinkedList.cpp - Definition file for the LinkedList class
//Author: Nate Douglas
#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
	head = nullptr;
}

void LinkedList::add(double x) {
	head = new ListNode(x, head);
}

bool LinkedList::isMember(double x) {
	ListNode* p = head;
	while (p != nullptr) {
		if (p->value == x) {
			return true;
		}
		p = p->next;
	}
	return false;
}

void LinkedList::print() {
	ListNode* p = head;
	//Prints a message for an empty list
	if (p == nullptr) {
		cout << "The list is empty"<<endl;
	}
	//Prints the contents of the list
	while (p != nullptr) {
		cout << p->value<<endl;
		p = p->next;
	}
}

void LinkedList::reverse() {
	ListNode* current = head;
	ListNode* previous = nullptr;
	ListNode* next = nullptr;

	while (current != nullptr) {
		//Stores the next pointer
		next = current->next;
		//Sets the current pointer's next node to the previous one
		current->next = previous;
		//Sets the previous node to the current one
		previous = current;
		//Sets the current one to the next one
		current = next;
	}
	head = previous;
}

int LinkedList::search(double x) {
	ListNode* p = head;
	int position = 0;
	//Uses the same logic as isMember, but instead of returning true, it increments position until found and returns the position
	while (p != nullptr) {
		if (p->value == x) {
			return position;
		}
		position++;
		p = p->next;
	}
	return -1;
}

void LinkedList::insert(double x, int pos) {
	ListNode* previous = head;
	
	//If the position is the head, uses the same logic as Add
	if (pos == 0) {
		head = new ListNode(x, head);
	}
	//Otherwise, it iterates through the list, swapping the previous for the add node until position is found.
	else {
		ListNode* addNode = new ListNode(x, head);
		for (int i = 0; i < pos; i++) {
			addNode->next = previous->next;
			previous->next = addNode;
		}
	}
	
}