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
	SingleLinkedList<double>::Node bc[5] = { SingleLinkedList<double>::Node(3.14), SingleLinkedList<double>::Node(6.28) };
	SingleLinkedList<double>::Node *bb = new SingleLinkedList<double>::Node[5]{ SingleLinkedList<double>::Node(3.14), SingleLinkedList<double>::Node(6.28) };
	sll.Print();
}