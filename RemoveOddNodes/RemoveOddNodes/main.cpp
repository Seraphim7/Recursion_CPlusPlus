#include <iostream>
#include "LLL.h"

using namespace std;

int main()
{
	LLL list;

	list.insert(3);  // 7
	list.insert(5);  // 6
	list.insert(8);  // 5
	list.insert(10); // 4
	list.insert(15); // 3
	list.insert(17); // 2
	list.insert(23); // 1

	cout << list.removeOddNodes() << endl;

	return 0;
}