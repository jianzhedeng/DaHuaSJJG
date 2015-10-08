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
template <class T>
class SingleLinkedList
{
public:
	class Node;
private:
	Node *Head;
protected:
	status InitList();
	status ReleaseList();

	int GetLength();
	Node *GetNode(const int pos = 0)
	{
		int i = 0;
		int num = GetLength();
		Node *p = NULL;
		if (pos > 0 && pos < num)
		{
			for (i = 0, p = this->Head; i < pos; ++i, p = p->next)
			{
			}
			return (p);
		}
		else if (pos == 0 || pos == num)
		{
			for (i = 0, p = this->Head; i < num; ++i, p = p->next)
			{
			}
			return (p);
		}
		return (NULL);

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
	Node *Take(const int pos = 0)
	{
		int i = 0;
		const int num = GetLength();
		Node *p = NULL, *q = NULL;
		if (pos > 0 && pos < num)
		{
			for (i = 0, p = this->Head; i < (pos - 1); ++i, p = p->next)
			{
			}
			q = p->next;
			p->next = p->next->next;
			q->next = NULL;
			return (q);
		}
		else if (pos == num || pos == 0)
		{
			for (i = 0, p = this->Head; i < (num - 1); ++i, p = p->next)
			{
			}
			q = p->next;
			p->next = p->next->next;
			return (q);
		}
		return (p);
	}
	status Delete(const int pos = 0)
	{
		Node *p = NULL;
		p = this->Take(pos);
		if (NULL != p)
		{
			/*	��ʱ�ͷ�		*/
			return (OK);
		} 
		else
		{
			return (ERROR);
		}
	}
	T Get(const int pos = 0)
	{
		int i = 0;
		int num = GetLength();
		Node *p = NULL;
		if (pos > 0 && pos < num)
		{
			for (i = 0, p = this->Head; i < pos; ++i, p = p->next)
			{
			}
			return (p->data);
		}
		else if (pos == 0 || pos == num)
		{
			for (i = 0, p = this->Head; i < num; ++i, p = p->next)
			{
			}
			return (p->data);
		}
		return (NULL);
	}
	status Set(const T ele, const int pos = 0)
	{
		Node *p = NULL;
		p = this->GetNode(pos);
		if (NULL != p)
		{
			p->data = ele;
			return (OK);
		}
		return (ERROR);
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

template <class T>
status SingleLinkedList<T>::InitList()
{
	Head = new Node();
	if (NULL != Head)
	{
		Head->next = NULL;
		return (OK);
	}
	return (ERROR);
}

template <class T>
status SingleLinkedList<T>::ReleaseList()
{
	Node *p = NULL, *q = NULL;
	for (p = this->Head->next; NULL != p;)
	{
		q = p->next;
		/*	delete pָ��Ķ���		*/
		p = q;
	}
	delete (this->Head);
	return (OK);
}

template <class T>
int SingleLinkedList<T>::GetLength()
{
	int i = 0;
	Node *p = NULL;
	for (i = 0, p = this->Head; p->next != NULL; ++i, p = p->next)
	{
	}
	return (i);
}



#endif
