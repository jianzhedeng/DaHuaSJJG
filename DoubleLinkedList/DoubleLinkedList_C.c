#include "DoubleLinkedList_C.h"

void ShowList(pNode Head)
{
	int i;
	pNode p;
	printf("#Have %d nodes.These nodes were listed.\n#", CountList(Head));
	for (i = 0, p = Head; ; p = p->next, ++i)
	{
		if (i > 0)
		{
			printf("%d", p->date);
		}
		if (p->next == NULL)
		{
			break;
		} 
		else if (i > 0)
		{
			printf("\t");
		}
	}
	printf("\n");
}

/*		���ɴ�ͷ����˫����������ֵΪͷָ�롣		*/
pNode InitList()
{
	pNode Head = NULL;

	Head = (pNode)calloc(1, sizeof(node));
	if (NULL != Head)
	{
		Head->next = NULL;
		Head->prev = NULL;
	}

	return (Head);
}

pNode ReleaseList(pNode Head)
{
	for ( ; NULL != Head->next; DeleteNode(Head, 1))
	{
	}
	free(Head);
	return (NULL);
}

int CountList(pNode Head)
{
	int i;
	pNode p;
	for (i = 0, p = Head; p->next != NULL; p = p->next, ++i)
	{
	}
	return (i);
}

/*		�����㡣�����pos�����֮ǰ��pos < 1ʱ���嵽��������eleΪָ����������ָ�롣		*/
status InsertNode(pNode Head, const int pos, pNode ele)
{
	if (ele != NULL && Head != NULL && pos <= CountList(Head))
	{
		int i = 0;
		pNode p = NULL;

		/*		pָ�򱻲�����֮ǰ�Ľ�� 		*/
		if (pos < 1)
		{
			for (p = Head; p->next != NULL; p = p->next)
			{
			}
		} 
		else
		{
			/*		ѭ��pos - 1��		*/
			for (p = Head, i = 0; i < pos - 1; p = p->next, ++i)
			{
			}
		}
		/*		������		*/
		ele->next = p->next;
		ele->prev = p;
		if (ele->next != NULL)
		{
			ele->next->prev = ele;
		}
		if (NULL != p)
		{
			p->next = ele;
		}
		return (OK);
	}
	return (ERROR);
}

/*		ɾ����㡣ɾ����pos����㡣		*/
status DeleteNode(pNode Head, const int pos)
{
	if (Head != NULL && pos > 0 && pos <= CountList(Head))
	{
		int i;
		pNode p;
		/*		ѭ��pos - 1��		*/
		for (i = 0, p = Head; i < pos - 1; p = p->next, ++i)
		{
		}
		if (p->next->next == NULL)
		{
			free(p->next);
			p->next = NULL;
		} 
		else
		{
			p->next = p->next->next;
			free(p->next->prev);
			p->next->prev = p;
		}
		return (OK);
	}
	return (ERROR);
}

/*		����һ����㣬��ʹ��rand������ʼ��		*/
pNode CreateNode()
{
	pNode p;
	p = (pNode)calloc(1, sizeof(node));
	if (NULL != p)
	{
		p->date = (ListElemType)rand();
	}
	return (p);
}
