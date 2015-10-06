/*		Author: jianzhedeng		*/
/*		Date: 2015.8.25		*/
/*		Def: ��ָ��ʵ�ֵļ򵥵ĵ�����������ཫ�ô����C++ʵ�֣��Թ��������ӵĽṹ�̳л���á�		*/
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
		/*	���pos�Ƿ���ڽڵ�����		*/
		/*	posΪ����������		*/
		/*	pos��Ϊ���������Ӧ�ڵ�֮ǰ		*/
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
		/*	�˴�Ӧʹ��new�ؼ�����������ռ�		*/
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
