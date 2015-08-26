#include <stdio.h>
#include "SingleLinkedList_array_c.h"

void main()
{
	cur *Cur = NULL;
	node *Node = NULL;
	InitList(&Node, &Cur);
	InsertNode(&Node, &Cur, 0, rand());
	InsertNode(&Node, &Cur, 1, rand());
	InsertNode(&Node, &Cur, 2, rand());
	DeleteNode(&Node, &Cur, 1);
	DeleteNode(&Node, &Cur, CountList(&Node, &Cur));
	DeleteNode(&Node, &Cur, 0);
 	ShowList(&Node, &Cur);
	ReleaseList(&Node, &Cur);
}
