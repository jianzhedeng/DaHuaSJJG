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
	class Node;
private:
	Node *Head;
protected:
// 	status InitList()
// 	{
// 		Head = new Node<T>();
// 		if (NULL != Head)
// 		{
// 			Head->next = NULL;
// 			return (OK);
// 		}
// 		return (ERROR);
// 	}
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
	};
	SingleLinkedList()
	{
// 		InitList();
	}
	~SingleLinkedList()
	{
		ReleaseList();
	}

};


#endif
