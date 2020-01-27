#pragma once

#include "Node.h"

class LLL
{
public:
	LLL();
	void insert(int number);
	float countFirstHalf();

private:
	int countFirstHalf(Node*& head, Node*& tail, int& count, int& firstHalfNodeData, int& iteration, bool& startCounting, int& firstHalfNodeCount);
	Node* head;
	Node* tail;
};