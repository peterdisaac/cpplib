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

int LinkedList::getLength() {
	return this->length;
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
	this->cur = this->head;
}

void LinkedList::prepend(int data)
{
	Node *newNode = new Node(data);
	if (!newNode) // newNode failed
		return;
	else
	{
		// Insert the node
		if (this->head == nullptr) // Special case, empty list
		{
			this->tail = newNode;
		}
		else
		{
			// Add the beginning of the list
			newNode->setNext(this->head);
			this->head->setPrev(newNode);
		}
		this->length++;
		this->head = newNode;
		this->cur = newNode;
	}
}

void LinkedList::append(int data)
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
		}
		else 
		{
			this->tail->setNext(newNode);
			newNode->setPrev(this->tail);
		}
		this->tail = newNode;
		this->cur = newNode;
		this->length++;
	}
}

void LinkedList::remove()
{
	if (!this->cur) // Cur is null, cannot remove
		return;
	else
	{
		Node *temp = this->cur; // Temporary node to store the cur node

		if (this->cur == this->head) // Remove from end
		{
			this->cur = this->cur->getNext();
			this->head = this->cur;
		}
		else // General case
		{
			Node *prev_temp = this->cur->getPrev();
			Node *next_temp = this->cur->getNext();
			if (next_temp == nullptr)
			{
				this->cur = prev_temp;
				this->cur->setNext(nullptr);
				this->tail = this->cur;
			}
			else
			{
				prev_temp->setNext(next_temp);
				next_temp->setPrev(prev_temp);
			}
			
		}
		this->length--;
	}
}

int LinkedList::find(int data)
{
	this->cur = this->head; // Move to beginning of the list
	int index = -1; // Preset to -1, returns -1 if not found;
	int counter = 0; // Keep tracks of our location

	while (cur)
	{
		if (cur->getData == data)
		{
			index = counter; // Match found, return index location
			break;
		}
		counter++;
	}
	return index;
}
