#pragma once

#include "Node.h"

class LLL
{
public:
	LLL();
	void insert(int number);
	int removeEvenNodesIfMultiple();

private:
	int removeEvenNodesIfMultiple(Node*& head, Node*& tail, int& count, int& avg, int& sumEvenNodeNum, int& evenNodeCount, bool& waitingToDelete, int& removed);
	Node* head;
	Node* tail;
};