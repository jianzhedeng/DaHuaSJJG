#include <iostream>
using namespace std;
#include "SingleLinkedList_Linked_cpp.h"
void main(void)
{
	SingleLinkedList<double> sll;
	SingleLinkedList<int>::Node bd;
	sll.Insert(0.1);
	sll.Insert(2);
	sll.Insert(128);
	sll.Print();
}