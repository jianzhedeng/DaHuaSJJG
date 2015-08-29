#include "StaticStack.h"

void ShowStack(StackElemType *Stack, int *StackLength)
{
	int i;
	StackElemType *j;
	printf("#The length of stack is %d.These elements were listed.\n#", *StackLength);
	for (i = 0, j = Stack; i < (*StackLength); ++j, ++i)
	{
		printf("%d", *j);
		if (i < (*StackLength) - 1)
		{
			printf("\t");
		}
	}
	printf("\n");
}

StackElemType *InitStack(int *StackLength)
{
	StackElemType *Stack = NULL;
	Stack = (StackElemType *)calloc(MAXSIZE, sizeof(StackElemType));
	if (NULL != Stack)
	{
		*StackLength = 0;
	}

	return (Stack);
}

StackElemType *ReleaseStack(StackElemType *Stack, int *StackLength)
{
	free(Stack);
	*StackLength = 0;
	return (NULL);
}

StackElemType Pop(StackElemType *Stack, int *StackLength)
{
	if ((*StackLength) > 0)
	{
		return (*(Stack + --(*StackLength)));
	}
	return (ERROR);
}

status Push(StackElemType *Stack, int *StackLength, StackElemType ele)
{
	if ((*StackLength) < MAXSIZE)
	{
		*(Stack + (*StackLength)++) = ele;
		return (OK);
	}
	return (ERROR);
}
