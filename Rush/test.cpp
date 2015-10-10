#include <iostream>
using namespace std;
#include "SingleLinkedList_Linked_cpp.h"
#include "SingleLinkedQueue_Linked_cpp.h"
#include "SingleLinkedStack_Linked_cpp.h"
void main(void)
{
	SStack<> ss;
	ss.Push(1);
	ss.Push(2);
	ss.Push(3);
	ss.Print();
	cout << ss.Pop() << endl;
	ss.Print();
	cout << ss.Pop() << endl;
	ss.Print();
	cout << ss.Pop() << endl;
	ss.Print();
	SQueue<> sq;
	sq.Put(23);
	sq.PrintQueue();
}