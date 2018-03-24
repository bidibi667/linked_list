#pragma once

struct Node {
	Node* pNext = nullptr;
	int  *data;
};
	

struct List {
	int len = 0;
	Node *pHead = nullptr;
};

void Print(const List& lst);
void Add(List& lst, int data);
int Pop(List &lst);
void Insert(List &lst, int data, int pos);
Node* GetData(List& lst, int index);
void Swap(List& lst, int a, int b);
void Sort(List &lst, bool(*pred)(int, int));

bool IsInRange(const List &lst, int index);
