/*		Author: jianzhedeng		*/
/*		Date: 2015.8.27		*/
/*		Def: ¾²Ì¬Õ»¡£ÒÑÍ¨¹ý°×ºÐ²âÊÔ¡£		*/
#pragma once
#ifndef STATICSTACK_H_
#define STATICSTACK_H_
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAXSIZE (1024)
#define OK (0)
#define ERROR (1)
typedef int StackElemType;
typedef int status;

StackElemType *InitStack(int *StackLength);
StackElemType *ReleaseStack(StackElemType *Stack, int *StackLength);
StackElemType Pop(StackElemType *Stack, int *StackLength);
status Push(StackElemType *Stack, int *StackLength, StackElemType ele);

void ShowStack(StackElemType *Stack, int *StackLength);

#endif
