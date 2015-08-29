/*		Author: jianzhedeng		*/
/*		Date: 2015.8.29	*/
/*		Def: 静态栈。已封装。已通过白盒测试。		*/
#pragma once
#ifndef STATICSTACK_CPP_H_
#define STATICSTACK_CPP_H_
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAXSIZE (1024)
#define OK (0)
#define ERROR (1)
typedef int status;

template <typename T>
class StaticStack
{
private:
	T* Stack;
	int StackLength;
protected:
	T* InitStack()
	{
		T *Stack = NULL;
		Stack = (T*)calloc(MAXSIZE, sizeof(T));
		if (NULL != Stack)
		{
			StackLength = 0;
		}
		return (Stack);
	}
	T* ReleaseStack()
	{
		free(this->Stack);
		StackLength = 0;
		return (NULL);
	}
public:
	StaticStack():StackLength(0)
	{
		this->Stack = InitStack();
	}
	~StaticStack()
	{
		this->Stack = ReleaseStack();
	}
	T Pop()
	{
		if (StackLength > 0)
		{
			return (*(Stack + --StackLength));
		}
		return (ERROR);
	}

	status Push(T ele)
	{
		if (StackLength < MAXSIZE)
		{
			*(Stack + StackLength++) = ele;
			return (OK);
		}
		return (ERROR);
	}

	void ShowStack()
	{
		int i;
		T *j;
		printf("#The length of stack is %d.These elements were listed.\n#", this->StackLength);
		for (i = 0, j = this->Stack; i < (this->StackLength); ++j, ++i)
		{
			printf("%d", *j);
			if (i < (this->StackLength) - 1)
			{
				printf("\t");
			}
		}
		printf("\n");

	}
};

#endif
