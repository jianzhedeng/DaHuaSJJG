/*		Author: jianzhedeng		*/
/*		Date: 2015.8.25		*/
/*		Def: 初步的双向链表。已通过白盒测试。		*/
#pragma  once
#ifndef DOUBLELINKEDLIST_C_H
#define DOUBLELINKEDLIST_C_H
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define OK (0)
#define ERROR (1)
typedef int status;
/*		定义数据类型，根据需要换成用户类型		*/
typedef int ListElemType;
/*		定义链表结点类型		*/
typedef struct DouNode
{
	ListElemType date;
	struct DouNode *prev;
	struct DouNode *next;
}node, *pNode;

pNode InitList();
pNode ReleaseList(pNode Head);
int CountList(pNode Head);
status InsertNode(pNode Head, const int pos, pNode ele);
status DeleteNode(pNode Head, const int pos);
pNode CreateNode();

void ShowList(pNode Head);

#endif
