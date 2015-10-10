/*	Author: jianzhedeng		*/
/*	Date: 2015.10.10		*/
/*	Def: ʹ����ʽ������ʵ�ֵ�ջ		*/
/*	Final Modified Date: 2015.10.10		*/
#pragma once
#ifndef SINGLELINKESTACK_LINKED_CPP
#define SINGLELINKESTACK_LINKED_CPP
#include <iostream>
#include "SingleLinkedList_Linked_cpp.h"
using namespace std;

template <class T = int>
class SingleLinkedStack
{
private:
	SingleLinkedList<T> *sll;
public:
	SingleLinkedStack();
	~SingleLinkedStack();
	template <class U>
	friend ostream& operator << (ostream &out, const SingleLinkedStack<U> &obj);
	template <class U>
	friend istream& operator >> (istream &in, const SingleLinkedStack<U> &obj);
	status Push(T ele) const;
	T Pop();
	int GetLength();
	void PrintStack();
	void Print();
};

template <class T = int>
using SStack = SingleLinkedStack<T>;

template <class T>
SingleLinkedStack<T>::SingleLinkedStack()
{
	sll = new SingleLinkedList<T>;
}

template <class T>
SingleLinkedStack<T>::~SingleLinkedStack()
{
	delete(sll);
}

template <class U>
inline ostream& operator << (ostream &out, const SingleLinkedStack<U> &obj)
{
	out << *obj.sll;
	return (out);
}

template <class U>
inline istream& operator >> (istream &in, const SingleLinkedStack<U> &obj)
{
	U ele;
	cin >> ele;
	obj.Push(ele);
	return (in);
}

template <class T>
status SingleLinkedStack<T>::Push(T ele) const
{
	return (sll->Insert(ele, 1));
}

template <class T>
T SingleLinkedStack<T>::Pop()
{
	T flag = sll->Get(1);
	sll->Delete(1);
	return (flag);
}

template <class T>
int SingleLinkedStack<T>::GetLength()
{
	return (sll->GetLength());
}

template <class T>
void SingleLinkedStack<T>::PrintStack()
{
	return (sll->PrintList());
}

template <class T>
void SingleLinkedStack<T>::Print()
{
	cout << "This is a SingleLinkedStack, with " << sll->GetLength() << " elements." << endl;
	sll->PrintList();
}

#endif
