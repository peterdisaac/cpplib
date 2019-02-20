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

}

void Node::setData(int data)
{
	this->data = data;
}

void Node::setNext(Node *next)
{
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
	return this->prev;
}

void Node::setPrev(Node *prev)
{
		this->prev = prev;
}