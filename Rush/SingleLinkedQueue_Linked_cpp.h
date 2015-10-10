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
	template <class U>
	friend ostream& operator << (ostream &out, const SingleLinkedQueue<U> &obj);
	template <class U>
	friend istream& operator >> (istream &in, const SingleLinkedQueue<U> &obj);
	status Put(T ele) const;
	T Get();
	int GetLength();
	void PrintQueue();
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

template <class U>
inline ostream& operator << (ostream &out, const SingleLinkedQueue<U> &obj)
{
	out << *obj.sll;
	return (out);
}

template <class U>
inline istream& operator >> (istream &in, const SingleLinkedQueue<U> &obj)
{
	U ele;
	cin >> ele;
	obj.Put(ele);
	return (in);
}

template <class T>
status SingleLinkedQueue<T>::Put(T ele) const
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
int SingleLinkedQueue<T>::GetLength()
{
	return (sll->GetLength());
}

template <class T>
void SingleLinkedQueue<T>::PrintQueue()
{
	return (sll->PrintList());
}

template <class T>
void SingleLinkedQueue<T>::Print()
{
	cout << "This is a SingleLinkedQueue, with " << sll->GetLength() << " elements." << endl;
	sll->PrintList();
}

#endif
