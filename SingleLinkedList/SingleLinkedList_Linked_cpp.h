/*		Author: jianzhedeng		*/
/*		Date: 2015.8.25		*/
/*		Def: 用指针实现的简单的单向链表。这个类将用纯粹的C++实现，以供被更复杂的结构继承或调用。		*/
#pragma  once
#ifndef SINGLELINKEDLIST_LINKED_CPP
#define SINGLELINKEDLIST_LINKED_CPP
#include <iostream>
#include <cstdlib>
using namespace std;
#define OK (0)
#define ERROR (1)
typedef int status;
template <class T = int>
class SingleLinkedList
{
public:
	class Node;
private:
	Node *Head;
protected:
	status InitList()
	{
		Head = new Node();
		if (NULL != Head)
		{
			Head->next = NULL;
			return (OK);
		}
		return (ERROR);
	}
	status ReleaseList()
	{
		return (ERROR);
	}
	int GetLength()
	{
		int i = 0;
		Node *p = NULL;
		for (i = 0, p = this->Head; p->next != NULL; ++i, p = p->next)
		{
		}
		return (i);
	}
public:
	class Node
	{
	public:
		T data;
		Node *next;
		Node() :data(0), next(NULL){;}
		Node(T ele) :data(ele), next(NULL){;}
	};
	SingleLinkedList()
	{
		InitList();
	}
	~SingleLinkedList()
	{
		ReleaseList();
	}
	status Insert(Node &node, const int pos = 0)
	{
		/*	检查pos是否大于节点数量		*/
		/*	pos为零则插入最后		*/
		/*	pos不为零则插入相应节点之前		*/
		int i = 0;
		Node *p = NULL;
		if (pos > 0 && pos <= GetLength())
		{
			for (i = 0, p = this->Head; i < (pos - 1); ++i, p = p->next)
			{
			}
			node.next = p->next;
			p->next = &node;
			return (OK);
		}
		else if (pos == 0)
		{
			for (i = 0, p = this->Head; p->next != NULL; ++i, p = p->next)
			{
			}
			node.next = p->next;
			p->next = &node;
			return (OK);
		}
		return (ERROR);
	}
	status Insert(const T ele, const int pos = 0)
	{
		/*	此处应使用new关键字来申请结点空间		*/
		Node *p = new Node(ele);
		return (Insert(*p, pos));
	}
	void Print()
	{
		Node *p = NULL;
		int i = 0, len = GetLength();
		cout << "This is a SingleLinkedList, with " << len << " nodes." << endl;
		for (i = 0, p = this->Head; p->next != NULL; ++i, p = p->next)
		{
			cout << p->next->data;
			if (i < len - 1)
			{
				cout << "\t";
			} 
			else if (i == len - 1)
			{
				cout << endl;
			}
		}
	}
};


#endif
