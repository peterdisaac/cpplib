#include "pch.h"
#include "LinkedList.h"
#include <iostream>


LinkedList::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->cur = nullptr;
	this->length = 0;
}

LinkedList::~LinkedList()
{
	delete head;
	delete tail;
	delete cur;
}

void LinkedList::insert(int data)
{
	Node *newNode = new Node(data);
	if (!newNode) // newNode failed
		return;
	else
	{
		// Insert the node
		if (this->head == nullptr) // Special case, empty list
		{
			this->head = newNode;
			this->tail = newNode;
		}
		else if (this->cur == this->tail) // Special case, inserting at the end
		{	
			// Eventually replace with a call to append()...
			this->tail->setNext(newNode);
			newNode->setPrev(this->tail);
			this->tail = newNode;
		}	
		else // General case, insert after cur
		{
			Node *temp = cur->getNext(); // Temp to hold the unhooked portion of list
			cur->setNext(newNode); // Set cur's new next as the new node
			newNode->setPrev(cur); // Set the new node's previous as cur
			
			// re-attach the rest of the list
			newNode->setNext(temp);
			temp->setPrev(newNode);
		}
		this->cur = newNode;
		this->length++;
	}
}

void LinkedList::insert(int data, int index)
{
	Node *newNode = new Node(data);
	if (!newNode) // newNode failed
		return;
	else if (index < 0 || index > this->length) 
	{
		// Index out of range, insert at the end of the list
		// Eventually replace with a call to append()...
		this->tail->setNext(newNode);
		newNode->setPrev(this->tail);
		this->tail = newNode;
	}
	else
	{
		// Find the index location
		this->cur = this->head;
		for (int i = 0; i < this->length; i++)
		{
			if (index - 1 == i)
			{
				// Found the index, insert node
				this->insert(data);
			}
			this->cur = this->cur->getNext();
		}
	}
	this->cur = newNode;
	this->length++;
}

void LinkedList::printList()
{
	this->cur = head;
	while (cur)
	{
		std::cout << cur->getData() << ", ";
		cur = cur->getNext();
	}
	std::cout << "\n";
}