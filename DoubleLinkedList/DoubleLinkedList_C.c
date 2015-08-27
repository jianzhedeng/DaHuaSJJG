#include "DoubleLinkedList_C.h"

void ShowList(pNode Head)
{
	int i;
	pNode p;
	printf("#Have %d nodes.These nodes were listed.\n#", CountList(Head));
	for (i = 0, p = Head; ; p = p->next, ++i)
	{
		if (i > 0)
		{
			printf("%d", p->date);
		}
		if (p->next == NULL)
		{
			break;
		} 
		else if (i > 0)
		{
			printf("\t");
		}
	}
	printf("\n");
}

/*		生成带头结点的双向链表。返回值为头指针。		*/
pNode InitList()
{
	pNode Head = NULL;

	Head = (pNode)calloc(1, sizeof(node));
	Head->next = NULL;
	Head->prev = NULL;

	return (Head);
}

pNode ReleaseList(pNode Head)
{
	for ( ; NULL != Head->next; DeleteNode(Head, 1))
	{
	}
	free(Head);
	return (NULL);
}

int CountList(pNode Head)
{
	int i;
	pNode p;
	for (i = 0, p = Head; p->next != NULL; p = p->next, ++i)
	{
	}
	return (i);
}

/*		插入结点。插入第pos个结点之前。pos < 1时，插到链表的最后。ele为指向需插入结点的指针。		*/
status InsertNode(pNode Head, const int pos, pNode ele)
{
	if (ele != NULL && Head != NULL && pos <= CountList(Head))
	{
		int i = 0;
		pNode p = NULL;

		/*		p指向被插入结点之前的结点 		*/
		if (pos < 1)
		{
			for (p = Head; p->next != NULL; p = p->next)
			{
			}
		} 
		else
		{
			/*		循环pos - 1次		*/
			for (p = Head, i = 0; i < pos - 1; p = p->next, ++i)
			{
			}
		}
		/*		插入结点		*/
		ele->next = p->next;
		ele->prev = p;
		if (ele->next != NULL)
		{
			ele->next->prev = ele;
		}
		p->next = ele;
		return (OK);
	}
	return (ERROR);
}

/*		删除结点。删除第pos个结点。		*/
status DeleteNode(pNode Head, const int pos)
{
	if (Head != NULL && pos > 0 && pos <= CountList(Head))
	{
		int i;
		pNode p;
		/*		循环pos - 1次		*/
		for (i = 0, p = Head; i < pos - 1; p = p->next, ++i)
		{
		}
		if (p->next->next == NULL)
		{
			free(p->next);
			p->next = NULL;
		} 
		else
		{
			p->next = p->next->next;
			free(p->next->prev);
			p->next->prev = p;
		}
		return (OK);
	}
	return (ERROR);
}

/*		生成一个结点，并使用rand函数初始化		*/
pNode CreateNode()
{
	pNode p;
	p = (pNode)calloc(1, sizeof(node));
	p->date = (ListElemType)rand();
	return (p);
}
