/*	Author: jianzhedeng		*/
/*	Date: 2015.10.9		*/
/*	Def: 使用链式单链表实现的队列		*/
/*	Final Modified Date: 2015.10.9		*/
#pragma once
#ifndef SINGLELINKEDQUEUE_LINKED_CPP
#define SINGLELINKEDQUEUE_LINKED_CPP
#include <iostream>
#include "SingleLinkedList_Linked_cpp.h"
using namespace std;

template <class T = int>
class SingleLinkedQueue
{
private:
	SingleLinkedList<T> *sll;
public:
	SingleLinkedQueue();
	~SingleLinkedQueue();
	status Put(T ele);
	T Get();
	void Print();
};

template <class T = int>
using SQueue = SingleLinkedQueue<T>;

template <class T>
SingleLinkedQueue<T>::SingleLinkedQueue()
{
	sll = new SingleLinkedList<T>;
}

template <class T>
SingleLinkedQueue<T>::~SingleLinkedQueue()
{
	delete(sll);
}

template <class T>
status SingleLinkedQueue<T>::Put(T ele)
{
	return (sll->Insert(ele));
}

template <class T>
T SingleLinkedQueue<T>::Get()
{
	T flag = sll->Get(1);
	sll->Delete(1);
	return (flag);
}

template <class T>
void SingleLinkedQueue<T>::Print()
{
	cout << "This is a SingleLinkedQueue, with " << sll->GetLength() << " elements." << endl;
	sll->PrintList();
}

#endif
