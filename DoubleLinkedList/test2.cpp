#include <iostream>
using namespace std;
#include "DoubleLinkedList_CPP.h"
typedef struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
}node;
void main(void)
{
	DLList<node> list;
	list.InitList();
	list.InsertNode(0, list.CreateNode());
}
