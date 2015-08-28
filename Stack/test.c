#include <stdio.h>
#include "StaticStack.h"
void main(void)
{
	int *stack = NULL, len;
	stack = InitStack(&len);
	Push(stack, &len, rand());
	Push(stack, &len, rand());
	Push(stack, &len, rand());
	ShowStack(stack, &len);
	Push(stack, &len, rand());
	Push(stack, &len, rand());
	Push(stack, &len, rand());
	ShowStack(stack, &len);
	printf("Pop: %d\n", Pop(stack, &len));
	printf("Pop: %d\n", Pop(stack, &len));
	printf("Pop: %d\n", Pop(stack, &len));
	ShowStack(stack, &len);
	printf("Pop: %d\n", Pop(stack, &len));
	printf("Pop: %d\n", Pop(stack, &len));
	printf("Pop: %d\n", Pop(stack, &len));
	ShowStack(stack, &len);
	printf("Pop: %d\n", Pop(stack, &len));
	printf("Pop: %d\n", Pop(stack, &len));
	printf("Pop: %d\n", Pop(stack, &len));
	ShowStack(stack, &len);
	stack = ReleaseStack(stack, &len);
}