#include "StaticQueue_cpp.h"

template <typename T>
T *StaticQueue<T>::InitQueue()
{
	QueueElemType *Queue = NULL;
	Queue = (QueueElemType *)calloc(MAXSIZE, sizeof(QueueElemType));
	if (NULL != Queue)
	{
		Head = 0;
		Nail = 0;
	}
	return (Queue);
}

template <typename T>
T *StaticQueue<T>::ReleaseQueue()
{
	free(this->Queue);
	Head = 0;
	Nail = 0;
	return (NULL);
}

template <typename T>
StaticQueue<T>::StaticQueue()
{
	this->Queue = InitQueue();
}

template <typename T>
StaticQueue<T>::~StaticQueue()
{
	this->Queue = ReleaseQueue();
}

template <typename T>
T *StaticQueue<T>::Get()
{
	if (Head != Nail)
	{
		T ele = *(Queue + Head);
		Head = (Head + 1) % MAXSIZE;
		return (ele);
	}
	return (ERROR);
}

template <typename T>
status StaticQueue<T>::Put(T ele)
{
	if ((Nail + 1) % MAXSIZE != Head)
	{
		*(Queue + Nail) = ele;
		Nail = (Nail + 1) % MAXSIZE;
		return (OK);
	}
	return (ERROR);
}

template <typename T>
void StaticQueue<T>::ShowQueue()
{
	int i;
	int j;
	int len = (Nail - Head + MAXSIZE) % MAXSIZE;
	printf("#The length of queue is %d.These elements were listed.\n#", len);
	for (i = 0, j = Head; i < len; ++j, ++i)
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
