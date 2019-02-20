#pragma once
class Node
{
private:
	int data;
	Node *next;
	Node *prev;

public:
	Node(int data);
	virtual ~Node();

	// Getters and Setters
	void setData(int data);
	void setNext(Node *next);
	void setPrev(Node *prev);
	int getData();
	Node* getNext();
	Node* getPrev();
};

