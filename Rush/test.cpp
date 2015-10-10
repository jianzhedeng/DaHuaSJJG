#include <iostream>
using namespace std;
#include "SingleLinkedList_Linked_cpp.h"
#include "SingleLinkedQueue_Linked_cpp.h"
#include "SingleLinkedStack_Linked_cpp.h"
void main(void)
{
	SList<> sl;
	sl.Insert(2);
	sl.Insert(4);
	cout << sl << endl;
	sl.Print();
	
}