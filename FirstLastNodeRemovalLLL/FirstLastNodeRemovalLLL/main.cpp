#include <iostream>
#include "LLL.h"

using namespace std;

int main()
{
	LLL list;

	list.insert(10);
	list.insert(7);
	list.insert(3);
	list.insert(3);

	int avg = list.RemoveAllButEnds();

	cout << avg << endl;
}