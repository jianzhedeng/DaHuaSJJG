#include <iostream>
using namespace std;
#include "SingleLinkedList_Linked_cpp.h"
void main(void)
{
	SingleLinkedList<int> sll;
	SingleLinkedList<int>::Node bd, *pbd;
	SingleLinkedList<int>::Node bc[5] = { SingleLinkedList<int>::Node(3.14), SingleLinkedList<int>::Node(6.28) };
	SingleLinkedList<int>::Node *bb = new SingleLinkedList<int>::Node[5]{ SingleLinkedList<int>::Node(3.14), SingleLinkedList<int>::Node(6.28) };
	sll.Insert(0.1);
	sll.Insert(2);
	sll.Insert(128);
	sll.Print();
	pbd = sll.Take();
	cout << pbd->data << endl;
	sll.Print();
	sll.Delete();
	sll.Print();
	sll.Insert(bc[0]); sll.Print();
	sll.Delete(); sll.Print();
	cout << "EG2." << endl;
	cout << sll.Get(1) << endl;
	sll.Set(6666);
	sll.Print();
}