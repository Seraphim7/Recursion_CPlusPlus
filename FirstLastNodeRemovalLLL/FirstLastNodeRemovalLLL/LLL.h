#pragma once

#include "node.h"

class LLL
{
public:
	LLL();
	int RemoveAllButEnds();
	void insert(int num);
private:
	int RemoveAllButEnds(node*& head, node*& tail);
	node* head;
	node* tail;
	int count;
};