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
	status Insert(const Node &node, const int pos)
	{
		/*	���pos�Ƿ���ڽڵ�����		*/

		/*	posΪ����������		*/

		/*	pos��Ϊ���������Ӧ�ڵ�֮ǰ		*/

		return (ERROR);
	}

};


#endif
