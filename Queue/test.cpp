#include "StaticQueue_cpp.h"
#include <iostream>
using namespace std;
void main(void)
{
	StaticQueue<double> hi;
	hi.ShowQueue();
	for (int i = 0; i < 1024; ++i)
	{
		hi.Put(i);
	}
	hi.ShowQueue();
	for (int i = 0; i < 5; ++i)
	{
		cout << hi.Get() << endl;
	}
	hi.ShowQueue();
}
