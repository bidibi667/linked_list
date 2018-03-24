#include "LinkedList.h"
#include <iostream>



bool max(int a, int b) {
	return a > b;
}

int main() {
	List my_list;
	Add(my_list, 0);
	Add(my_list, 1);
	Add(my_list, 2);
	Add(my_list, 3);
	Add(my_list, 4);
	Add(my_list, 5);
	Print(my_list);
	Insert(my_list, 99, 3);
	Sort(my_list, [](int a, int b)->bool {return a > b; });
	Print(my_list);
	return 0;
}