/*		Author: jianzhedeng		*/
/*		Date: 2015.8.25		*/
/*		Def: ��ָ��ʵ�ֵļ򵥵ĵ�����������ཫ�ô����C++ʵ�֣��Թ��������ӵĽṹ�̳л���á�		*/
#pragma  once
#ifndef SINGLELINKEDLIST_LINKED_CPP
#define SINGLELINKEDLIST_LINKED_CPP
#include <iostream>
// #include <cstdlib>
using namespace std;
#define OK (0)
#define ERROR (1)
typedef int status;
 
template <class T>
class SingleLinkedQueue;

template <class T = int>
class SingleLinkedList
{
public:
	class Node;
 	friend void SingleLinkedQueue<T>::Print();
private:
	Node *Head;
protected:
	status InitList();
	status ReleaseList();
	Node *GetNode(const int pos = 0);
	void PrintList();
public:
	class Node;
	SingleLinkedList();
	~SingleLinkedList();
	status Insert(Node &node, const int pos = 0);
	status Insert(const T ele, const int pos = 0);
	Node *Take(const int pos = 0);
	status Delete(const int pos = 0);
	T Get(const int pos = 0);
	status Set(const T ele, const int pos = 0);
	int Seek(const T ele);
	int GetLength();
	void Print();
};

/*	C++11��ģ�������VS2013��ʼ֧�ָ����ԣ��Ͱ汾������Ӧ���ÿ�ע�͵���		*/
template <class T = int>
using SList = SingleLinkedList<T>;

template <class T>
class SingleLinkedList<T>::Node
{
public:
	T data;
	Node *next;
	int AutoDelete;
	Node() :data(0), next(NULL), AutoDelete(0){ ; }
	Node(T ele) :data(ele), next(NULL), AutoDelete(0){ ; }
	Node(T ele, int iAutoDelete) :data(ele), next(NULL), AutoDelete(iAutoDelete){ ; }
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
		/*	��ʱdelete pָ��Ķ���		*/
		if (p->AutoDelete)
		{
			delete(p);
		}
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

template <class T>
typename SingleLinkedList<T>::Node *SingleLinkedList<T>::GetNode(const int pos)
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

template <class T>
SingleLinkedList<T>::SingleLinkedList()
{
	InitList();
}

template <class T>
SingleLinkedList<T>::~SingleLinkedList()
{
	ReleaseList();
}

template <class T>
status SingleLinkedList<T>::Insert(Node &node, const int pos)
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

template <class T>
status SingleLinkedList<T>::Insert(const T ele, const int pos)
{
	/*	�˴�Ӧʹ��new�ؼ�����������ռ�		*/
	Node *p = new Node(ele, 1);
	return (Insert(*p, pos));
}

template <class T>
typename SingleLinkedList<T>::Node *SingleLinkedList<T>::Take(const int pos)
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

template <class T>
status SingleLinkedList<T>::Delete(const int pos)
{
	Node *p = NULL;
	p = this->Take(pos);
	if (NULL != p)
	{
		/*	��ʱ�ͷ�		*/
		if (p->AutoDelete)
		{
			delete(p);
		}
		return (OK);
	}
	else
	{
		return (ERROR);
	}
}

template <class T>
T SingleLinkedList<T>::Get(const int pos)
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

template <class T>
status SingleLinkedList<T>::Set(const T ele, const int pos)
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

template <class T>
int SingleLinkedList<T>::Seek(const T ele)
{
	/*	����C++�� == �ж���ʽ�����Ի������������á���Ҫ���� == �������		*/
	int i = 0;
	Node *p = NULL;
	for (i = 0, p = this->Head; NULL != p->next; ++i, p = p->next)
	{
		if (ele == p->next->data)
		{
			return (i + 1);
		}
	}
	return (0);
}

template <class T>
void SingleLinkedList<T>::PrintList()
{
	Node *p = NULL;
	int i = 0;
	int len = this->GetLength();
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

template <class T>
void SingleLinkedList<T>::Print()
{
	int len = GetLength();
	cout << "This is a SingleLinkedList, with " << len << " nodes." << endl;
	this->PrintList();
}

#endif
