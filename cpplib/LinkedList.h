#pragma once
#include "Node.h"

/*
 * Double Linked List
 *   This will allow for constant
 *	 time insertions and deletions
 */
class LinkedList
{

private:
	Node *head;
	Node *tail;
	Node *cur;
	int length;

public:
	LinkedList();
	virtual ~LinkedList();

	// Different insertions and deletion operations

	void insert(int data); // Insert after the current node
	void insert(int data, int index); // Insert at the index location
	void add(int data); // Insert before the current node
	void prepend(int data); // Insert at the beginning of the list
	void append(int data); // Insert at the end of the list

	void remove(); // Remove the current node
	void remove(int index); // Remove at the index location
	
	int pop(); // Remove and return the first element
	int push(); // Push function for treating list as a stack

	int find(int data); // Returns the index locaiton of first occurence of data
	void removeDuplicates(); // Remove all duplicate values in the list.
	void reverse(); // Reverses the list

	int getLength(); // Returns length of list
	void printList();


};

