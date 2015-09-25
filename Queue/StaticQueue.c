#include "StaticQueue.h"



QueueElemType * InitQueue(int *Head, int *Nail)
{
	QueueElemType *Queue = NULL;
	Queue = (QueueElemType *)calloc(MAXSIZE, sizeof(QueueElemType));
	if (NULL != Queue)
	{
		*Head = 0;
		*Nail = 0;
	}
	return (Queue);
}

QueueElemType * ReleaseQueue(QueueElemType *Queue, int *Head, int *Nail)
{
	free(Queue);
	*Head = 0;
	*Nail = 0;
	return (NULL);
}

QueueElemType Get(QueueElemType *Queue, int *Head, int *Nail)
{
	if (*Head != *Nail)
	{
		QueueElemType ele = *(Queue + *Head);
		*Head = (*Head + 1) % MAXSIZE;
		return (ele);
	}
	return (ERROR);
}

status Put(QueueElemType *Queue, int *Head, int *Nail, QueueElemType ele)
{
	if (*Nail + 1 != *Head)
	{
		*Nail = ele;
		*Nail = (*Nail + 1) % MAXSIZE;
		return (OK);
	}
	return (ERROR);
}

void ShowQueue(QueueElemType *Queue, int *Head, int *Nail)
{
	int i;
	int j;
	int len = (*Nail - *Head + MAXSIZE) % MAXSIZE;
	printf("#The length of queue is %d.These elements were listed.\n#", len);
	for (i = 0, j = *Head; i < len; ++j, ++i)
	{
		j %= MAXSIZE;
		printf("%d", *(Queue + j));
		if (i < len - 1)
		{
			printf("\t");
		}
	}
	printf("\n");
}
