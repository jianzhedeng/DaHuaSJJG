#include "StaticQueue.h"

void main(void)
{
	QueueElemType *queue = NULL;
	int head, nail;
	int i;
	queue = InitQueue(&head, &nail);
	for (i = 0; i < 1024; ++i)
	{
		Put(queue, &head, &nail, i);
	}
	ShowQueue(queue, &head, &nail);
	for (i = 0; i < 10; ++i)
	{
		printf("%d\n", Get(queue, &head, &nail));
	}
	ShowQueue(queue, &head, &nail);
	ReleaseQueue(queue, &head, &nail);
}
