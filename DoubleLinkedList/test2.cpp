#include <iostream>
using namespace std;
#include "DoubleLinkedList_CPP.h"
typedef struct Node
{
	long long  data;
	struct Node *prev;
	struct Node *next;
}node;
void main(void)
{
	DLList<node> list;
	list.InitList();
	list.InsertNode(0, list.CreateNode());
	list.InsertNode(1, list.CreateNode());
	list.InsertNode(2, list.CreateNode());
	list.DeleteNode(2);
	list.DeleteNode(0);
	list.ShowList();
	list.ReleaseList();
}
