#include <stdio.h>
#include "StaticStack_cpp.h"


void main()
{
	StaticStack<int> ss;
	ss.Pop();
	ss.Push(1);
	ss.Push(100);
	ss.Pop();
	ss.ShowStack();


}
