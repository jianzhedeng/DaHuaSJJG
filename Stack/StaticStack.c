#include "StaticStack.h"

void ShowStack(StackElemType *Stack, int *StackLength)
{
	int i;
	StackElemType *j;
	printf("#The length of stack is %d.These elements were listed.\n#", *StackLength);
	for (i = 0, j = Stack; ; ++j, ++i)
	{
		printf("%d", *j);
		if (i >= *StackLength)
		{
			printf("\n");
			break;
		}
		printf("\t");
	}
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
	free(StackElemType);
	*StackLength = 0;
	return (NULL);
}

status Pop(StackElemType *Stack, int *StackLength)

