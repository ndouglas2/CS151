//LinkedList.h - header file for the LinkedList class
//Author: Nate Douglas
#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
	struct ListNode {
		ListNode* next;
		double value;
		//Constructor
		ListNode(double x, ListNode* p = nullptr) {
			value = x;
			next = p;
		}
	};
private:
	ListNode* head;

public:
	void add(double x);
	bool isMember(double x);
	void print();
	void reverse();
	int search(double x);
	void insert(double x, int pos);
	LinkedList();
};


#endif