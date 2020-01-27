#include <iostream>
#include "LLL.h"

using namespace std;

int main()
{
	LLL list;

	list.insert(7);
	list.insert(8);
	list.insert(9);
	list.insert(10);

	int nodesRemoved = list.removeEvenNodesIfMultiple();

	cout << nodesRemoved << endl;
}