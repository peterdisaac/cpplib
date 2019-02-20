#include "pch.h"
#include "Node.h"


Node::Node(int data)
{
	this->data = data;
	this->next = nullptr;
	this->prev = nullptr;
}

Node::~Node()
{
	delete this->next;
}

void Node::setData(int data)
{
	this->data = data;
}

void Node::setNext(Node *next)
{
	if (next != nullptr)
		this->next = next;
}

int Node::getData()
{
	if (this != nullptr)
		return this->data;
	else
		return -1;
}

Node* Node::getNext()
{
	return this->next;
}

Node* Node::getPrev()
{
	return this->next;
}

void Node::setPrev(Node *prev)
{
	if (prev != nullptr)
		this->prev = prev;
}