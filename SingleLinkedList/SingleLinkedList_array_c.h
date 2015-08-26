/*		Author: jianzhedeng		*/
/*		Date: 2015.8.25		*/
/*		Def: 静态的单链表的实现，白盒测试通过		*/
#pragma  once
#ifndef SINGLELINKEDLIST_ARRAY_C_H
#define SINGLELINKEDLIST_ARRAY_C_H
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define OK (0)
#define ERROR (1)
typedef int status;
/*		定义静态结点最大数量，已用链表和备用链表的头节点将各占用一个		*/
#define MAXSIZE (1024)
/*		定义结点类型，根据需要换成用户类型		*/
typedef int node;
/*		定义游标类型，通常使用int即可，不需要修改		*/
typedef int cur;

status InitList(node **Node, cur **Cur);
status ReleaseList(node **Node, cur **Cur);
cur MallocNode(node **Node, cur **Cur);
status FreeNode(node **Node, cur **Cur, const cur k);
cur CountList(node **Node, cur **Cur);
status InsertNode(node **Node, cur **Cur, const cur pos, const node ele);
status DeleteNode(node **Node, cur **Cur, const cur pos);

void ShowList(node **Node, cur **Cur);

#endif
