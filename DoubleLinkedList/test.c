#include <stdio.h>
#include "DoubleLinkedList_C.h"

void main(void)
{
	pNode head = InitList();
	InsertNode(head, 0, CreateNode());
	InsertNode(head, 1, CreateNode());
	InsertNode(head, 2, CreateNode());
	DeleteNode(head, 1);
	DeleteNode(head, 2);
	DeleteNode(head, 1);
	ShowList(head);
	head = ReleaseList(head);
}