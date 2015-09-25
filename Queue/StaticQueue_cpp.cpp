/*		Author: jianzhedeng		*/
/*		Date: 2015.9.25	*/
/*		Def: 静态队列。已通过白盒测试。封装为类。		*/
#pragma once
#ifndef STATICQUEUE_CPP_H_
#define STATICQUEUE_CPP_H_
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAXSIZE (1024)
#define OK (0)
#define ERROR (1)
typedef int status;

template <typename T>
class StaticQueue
{
private:
	T *Queue;
	int Head;
	int Nail;
protected:
	T *InitQueue()
	{}
	T *ReleaseQueue()
	{}
public:
	StaticQueue()
	{
		this->Queue = InitQueue();
	}
	~StaticQueue()
	{
		this->Queue = ReleaseQueue();
	}
};
#endif
