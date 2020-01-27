#include "LLL.h"
#include "Node.h"

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

int LLL::removeEvenNodesIfMultiple()
{
	int count = 0;
	int avg = 0;
	int sumEvenNodeNum = 0;
	int evenNodeCount = 0;
	bool waitingToDelete = false;
	int removed = 0;

	removeEvenNodesIfMultiple(head, tail, count, avg, sumEvenNodeNum, evenNodeCount, waitingToDelete, removed);

	return removed;
}

int LLL::removeEvenNodesIfMultiple(Node*& head, Node*& tail, int& count, int& avg, int& sumEvenNodeNum, int& evenNodeCount, bool& waitingToDelete, int& removed)
{
	if (head == nullptr)
	{
		avg = sumEvenNodeNum / count;
		return 0;
	}
	else
	{
		count++;

		if (count % 2 == 0)
		{
			evenNodeCount++;

			sumEvenNodeNum = sumEvenNodeNum + head->num;

			removeEvenNodesIfMultiple(head->next, tail, count, avg, sumEvenNodeNum, evenNodeCount, waitingToDelete, removed);

			Node* removalPtr = head->next;

			if (head->next != nullptr || waitingToDelete == true)
			{
				if (head->next->num % avg == 0)
				{
					head->next = head->next->next;
					removalPtr->next = nullptr;
					delete removalPtr;
					removalPtr = nullptr;

					removed++;
				}
				else if (head->next == nullptr && ((avg % head->num) == 0))
				{
					waitingToDelete = true;
				}
			}
		}
		else
		{
			removeEvenNodesIfMultiple(head->next, tail, count, avg, sumEvenNodeNum, evenNodeCount, waitingToDelete, removed);
		}
	}
}
