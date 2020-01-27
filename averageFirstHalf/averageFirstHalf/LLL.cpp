#include "LLL.h"
#include "Node.h"
#include <math.h>

LLL::LLL()
{
	head = nullptr;
	tail = nullptr;
}

void LLL::insert(int num)
{
	Node* node = new Node;

	node->num = num;
	node->next = nullptr;

	if (head == nullptr)
	{
		head = node;
		tail = node;
	}
	else if (head->next == nullptr)
	{
		node->next = head;
		head = node;
		tail = node->next;
	}
	else
	{
		node->next = head;
		head = node;
	}

	node = nullptr;
}

float LLL::countFirstHalf()
{
	int count = 0;
	int firstHalfNodeData = 0;
	float avg = 0.0;
	int iteration = 0;
	bool startCounting = false;
	int firstHalfNodeCount = 0;

	countFirstHalf(head, tail, count, firstHalfNodeData, iteration, startCounting, firstHalfNodeCount);

	avg = (float) firstHalfNodeData / (float) firstHalfNodeCount;

	return avg;
}

int LLL::countFirstHalf(Node*& head, Node*& tail, int& count, int& firstHalfNodeData, int& iteration, bool& startCounting, int& firstHalfNodeCount)
{
	if (head == nullptr)
	{
		iteration = count;

		return 0;
	}
	else
	{
		count++;

		countFirstHalf(head->next, tail, count, firstHalfNodeData, iteration, startCounting, firstHalfNodeCount);

		if ((ceil(count / 2.0) == iteration) || startCounting)
		{
			firstHalfNodeData = head->num + firstHalfNodeData;

			firstHalfNodeCount++;

			startCounting = true;
		}

		iteration--;
	}
}
