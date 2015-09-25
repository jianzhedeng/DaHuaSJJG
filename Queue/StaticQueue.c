#include "StaticQueue.h"



QueueElemType * InitQueue(int *QueueLength)
{
	QueueElemType *Queue = NULL;
	Queue = (QueueElemType *)calloc(MAXSIZE, sizeof(QueueElemType));
	if (NULL != Queue)
	{
		*QueueLength = 0;
	}
	return (Queue);
}

QueueElemType * ReleaseQueue(QueueElemType *Queue, int *QueueLength)
{
	free(Queue);
	*QueueLength = 0;
	return (NULL);
}

QueueElemType Get(QueueElemType *Queue, int *QueueLength)
{

}

status Put(QueueElemType *Queue, int *QueueLength, QueueElemType ele)
{

}

void ShowQueue(QueueElemType *Queue, int *QueueLength)
{

}
