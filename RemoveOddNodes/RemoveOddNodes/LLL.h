#pragma once

#include "Node.h"

class LLL
{
public:
	LLL();
	void insert(int number);
	int removeEvenNodesIfMultiple();

private:
	int removeEvenNodesIfMultiple(Node*& head, Node*& tail);
	Node* head;
	Node* tail;
	int count;
};