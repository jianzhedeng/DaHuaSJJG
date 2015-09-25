/*		Author: jianzhedeng		*/
/*		Date: 2015.9.25		*/
/*		Def: ¾²Ì¬Õ»¡£ÒÑÍ¨¹ý°×ºÐ²âÊÔ¡£		*/
#pragma once
#ifndef STATICQUEUE_H_
#define STATICQUEUE_H_
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAXSIZE (1024)
#define OK (0)
#define ERROR (1)
typedef int QueueElemType;
typedef int status;

QueueElemType *InitQueue(int *QueueLength);
QueueElemType *ReleaseQueue(QueueElemType *Queue, int *QueueLength);
QueueElemType Get(QueueElemType *Queue, int *QueueLength);
status Put(QueueElemType *Queue, int *QueueLength, QueueElemType ele);

void ShowQueue(QueueElemType *Queue, int *QueueLength);

#endif
