#include "LinkedList.h"
#include <iostream>


void Print(const List& lst) {
	std::cout << "*****" << std::endl;
	Node *it = lst.pHead;
	while (it) {
		std::cout << *(it->data) << '\t';
		it = it->pNext;
	}
	std::cout << "*****" << std::endl;
}

void Add(List& lst, int data) {
	Node *new_node = new Node;
	new_node->data = new int (data);
	new_node->pNext = lst.pHead;
	lst.pHead = new_node;
	++lst.len;
}

int Pop(List &lst) {
	if (lst.len == 0) {
		return -1;
	}
	Node *pop_item = lst.pHead;
	int ret_val = *(pop_item->data);
	lst.pHead = lst.pHead->pNext;
	delete pop_item;
	--lst.len;
	return ret_val;
}

void Insert(List &lst, int data, int pos) {
	if (lst.len < pos) {
		return;
	}

	Node *new_node = new Node;
	new_node->data = new int (data);


	Node *it = lst.pHead;
	int count = 0;
	while (it && count != pos) {
		++count;
		it = it->pNext;
	}
	new_node->pNext = it->pNext;
	it->pNext = new_node;
	++lst.len;
}

Node * GetData(List & lst, int index)
{
	if (!IsInRange(lst, index) )
	{
		return nullptr;

	}
	Node *it = lst.pHead;
	int count = 0;
	while (it) {
		++count;
		it = it->pNext;
	}
	
	return it;
}

void Swap(List & lst,int a, int b)
{
	Node *obj_a = GetData(lst, a);
	Node *obj_b = GetData(lst, b);
	std::swap(obj_a->data, obj_b->data);

	Node *parent_a = nullptr;
	
	if (a != 0) {
		parent_a = GetData(lst, a - 1);
	}
	Node *parent_b = nullptr;
	
	if (a != 0) {
		parent_a = GetData(lst, a - 1);
	}
}

void Sort(List & lst, bool(*pred)(int, int))
{
	Node *it = lst.pHead;
	Node *second = lst.pHead;
	while (it != nullptr) {
		while (second != nullptr) {
			if (pred(*it->data, *second->data)) {
				std::swap(it->data, second->data);
			}
			second = second->pNext;
		}
		it = it->pNext;
		second = lst.pHead;
	}
}

bool IsInRange(const List & lst, int index)
{
 	return !(index > lst.len - 1 && index < 0);
}
