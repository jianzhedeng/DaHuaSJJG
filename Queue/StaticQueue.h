/*		Author: jianzhedeng		*/
/*		Date: 2015.9.25		*/
/*		Def: ��̬���С���ͨ���׺в��ԡ�		*/
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

QueueElemType * InitQueue(int *Head, int *Nail);
QueueElemType * ReleaseQueue(QueueElemType *Queue, int *Head, int *Nail);
QueueElemType Get(QueueElemType *Queue, int *Head, int *Nail);
status Put(QueueElemType *Queue, int *Head, int *Nail, QueueElemType ele);
void ShowQueue(QueueElemType *Queue, int *Head, int *Nail);

#endif
