#include <iostream>
using namespace std;
#include "SingleLinkedList_Linked_cpp.h"
#include "SingleLinkedQueue_Linked_cpp.h"
void main(void)
{
	SQueue<> sq;
	sq.Print();
	sq.Put(2);
	sq.Put(4);
	sq.Put(5);
	sq.Put(16);
	sq.Print();
	sq.Get(); sq.Print();
	sq.Get(); sq.Print();
	sq.Get(); sq.Print();
	sq.Get(); sq.Print();
}