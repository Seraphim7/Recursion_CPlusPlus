#include "LLL.h"

LLL::LLL()
{
	head = nullptr;
	tail = nullptr;
	count = 0;
}

void LLL::insert(int num)
{
	node* Node = new node;

	Node->number = num;
	Node->next = nullptr;

	if (head == nullptr)
	{
		head = Node;
		tail = Node;
	}
	else if (head->next == nullptr)
	{
		Node->next = head;
		head = Node;
		tail = Node->next;
	}
	else
	{
		Node->next = head;
		head = Node;
	}

	Node = nullptr;

	count++;
}

int LLL::RemoveAllButEnds()
{
	node* current = head->next;

	if (current == nullptr)
	{
		return 0;
	}

	int sumOfRemovedNodes = RemoveAllButEnds(current, tail);

	head->next = tail;

	return sumOfRemovedNodes / (count - 2);
}

int LLL::RemoveAllButEnds(node*& current, node*& tail)
{
	if (current->next != nullptr)
	{
		return RemoveAllButEnds(current->next, tail) + current->number;

		if (current != tail || current != head)
		{
			int num = current->number;
			delete current;
			return num;
		}
	}
	else
	{
		return 0;
	}
}