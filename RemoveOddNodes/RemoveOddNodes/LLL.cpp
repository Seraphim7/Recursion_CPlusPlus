#include "LLL.h"
#include "Node.h"

LLL::LLL()
{
	head = nullptr;
	tail = nullptr;
	count = 1;
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

int LLL::removeOddNodes()
{
	Node* current = head;

	if (current == nullptr)
	{
		return 0;
	}

	return removeOddNodes(current, tail);
}

int LLL::removeOddNodes(Node*& head, Node*& tail)
{
	if (head == nullptr)
	{
		return 0;
	}
	else
	{
		Node* removalPtr = head;

		if (count % 2 == 1)
		{
			head = removalPtr->next;
			removalPtr->next = nullptr;
			delete removalPtr;
			removalPtr = nullptr;
			count++;
			return removeOddNodes(head, tail) + 1;
		}
		else
		{
			count++;
			return removeOddNodes(head->next, tail);
		}
	}
}