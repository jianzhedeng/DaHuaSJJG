/*		Author: jianzhedeng		*/
/*		Date: 2015.8.26		*/
/*		Def: 初步的双向链表。已封装。		*/
#pragma  once
#ifndef DOUBLELINKEDLIST_CPP_H
#define DOUBLELINKEDLIST_CPP_H
#include <iostream>
#include <cstdlib>
using namespace std;
#define OK (0)
#define ERROR (1)
typedef int status;

template <typename T>
class DLList
{
private:
	T *Head;
public:
	/*		生成带头结点的双向链表。返回值为头指针。		*/
	T *InitList()
	{
		T *Head = NULL;

		Head = (T *)calloc(1, sizeof(T));
		Head->next = NULL;
		Head->prev = NULL;

		this->Head = Head;
		return (Head);
	}

	T *ReleaseList()
	{
		for ( ; NULL != Head->next; DeleteNode(Head, 1))
		{
		}
		free(Head);
		return (NULL);
	}

	int CountList()
	{
		int i = 0;
		T *p = NULL;
		for (i = 0, p = Head; p->next != NULL; p = p->next, ++i)
		{
		}
		return (i);
	}

	/*		插入结点。插入第pos个结点之前。pos < 1时，插到链表的最后。ele为指向需插入结点的指针。		*/
	status InsertNode(const int pos, T *ele)
	{
		if (ele != NULL && Head != NULL && pos <= CountList())
		{
			int i = 0;
			T *p = NULL;

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
	status DeleteNode(const int pos)
	{
		if (Head != NULL && pos > 0 && pos <= CountList())
		{
			int i;
			T *p;
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
	T *CreateNode()
	{
		T *p;
		p = (T *)calloc(1, sizeof(T));
		return (p);
	}


};
#endif
