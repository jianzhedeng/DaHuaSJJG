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
	{
		T *Queue = NULL;
		Queue = (T *)calloc(MAXSIZE, sizeof(T));
		if (NULL != Queue)
		{
			Head = 0;
			Nail = 0;
		}
		return (Queue);
	}

	T *ReleaseQueue()
	{
		free(this->Queue);
		Head = 0;
		Nail = 0;
		return (NULL);
	}

public:
	StaticQueue()
	{
		this->Queue = this->InitQueue();
	}

	~StaticQueue()
	{
		this->Queue = this->ReleaseQueue();
	}

	T Get()
	{
		if (Head != Nail)
		{
			T ele = *(Queue + Head);
			Head = (Head + 1) % MAXSIZE;
			return (ele);
		}
		return (T)(ERROR);
	}

	status Put(T ele)
	{
		if ((Nail + 1) % MAXSIZE != Head)
		{
			*(Queue + Nail) = ele;
			Nail = (Nail + 1) % MAXSIZE;
			return (OK);
		}
		return (ERROR);
	}


	void ShowQueue()
	{
		int i;
		int j;
		int len = (Nail - Head + MAXSIZE) % MAXSIZE;
		printf("#The length of queue is %d.These elements were listed.\n#", len);
		for (i = 0, j = Head; i < len; ++j, ++i)
		{
			j %= MAXSIZE;
			printf("%.0lf", *(Queue + j));
			if (i < len - 1)
			{
				printf("\t");
			}
		}
		printf("\n");
	}

};
#endif
