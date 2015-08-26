#include "SingleLinkedList_array_c.h"
/*		供调试用		*/
void ShowList(node **Node, cur **Cur)
{
	int i, k;
	printf("#Have %d nodes.These nodes were listed.\n#", CountList(Node, Cur));
	for (i = MAXSIZE - 1, k = 0; ; i = *(*Cur + i), ++k)
	{
		if (k > 0)
		{
			printf("%d", *(*Node + i));
		}
		if (0 == *(*Cur + i))
		{
			break;
		}
		else if (k > 0)
		{
			printf("\t");
		}
	}
	printf("\n");
}

/*		Cur[MAXSIZE - 1]为头指针，Cur[0]指向备用链表头节点，"0"代表空指针		*/
/*		使用了二阶指针，注意！！！		*/
status InitList(node **Node, cur **Cur)
{
	cur i;
	*Node = (node*)calloc(MAXSIZE, sizeof(node));
	*Cur = (cur*)calloc(MAXSIZE, sizeof(cur));
	if ((NULL == *Node) || (NULL == *Cur))
	{
		return (ERROR);
	}
	for (i = 0; i < MAXSIZE - 1; ++i)
	{
		*(*Cur + i) = i + 1;
	}
	*(*Cur + MAXSIZE - 1) = 0;
	return (OK);
}

status ReleaseList(node **Node, cur **Cur)
{
	free(*Node);
	free(*Cur);
	return (OK);
}

/*		分配一个空结点，返回值为空结点的下标，若备用链表为空则返回0		*/
cur MallocNode(node **Node, cur **Cur)
{
	cur flag;
	flag = **Cur;
	if (flag)
	{
		**Cur = *(*Cur + flag);
	}
	return (flag);
}

/*		释放对应下标的结点。注意，不要与删除混淆，并且也不会检查该结点是否已经在备用链表中		*/
status FreeNode(node **Node, cur **Cur, const cur k)
{
	*(*Cur + k) = **Cur;
	**Cur = k;
	return (OK);
}

cur CountList(node **Node, cur **Cur)
{
	cur flag = 0, i;
	for (i = *(*Cur + MAXSIZE - 1); i != 0; ++flag, i = *(*Cur + i))
	{
	}
	return (flag);
}

/*		插入结点。使用传值方式，使用头插法，插入第pos个元素之前。若pos小于1则插到最后。		*/
status InsertNode(node **Node, cur **Cur, const cur pos, const node ele)
{
	cur i, j = 0, k = 0;
	if (CountList(Node, Cur) >= pos)
	{
		/*		下标i指向待插入位置的上一个结点		*/
		if (pos < 1)
		{
			/*		找到已用链表的尾结点		*/
			for (i = MAXSIZE - 1; 0 != *(*Cur + i); i = *(*Cur + i))
			{
			}
		} 
		else
		{
			/*		循环pos - 1 次		*/
			for (i = MAXSIZE - 1, k = 0; k < pos - 1; i = *(*Cur + i), ++k)
			{
			}
		}

		/*		插入已用链表中		*/
		if ((j = MallocNode(Node, Cur)) != 0)
		{
			*(*Node + j) = ele;
			*(*Cur + j) = *(*Cur + i);
			*(*Cur + i) = j;
			return (OK);
		}
	}
	return (ERROR);
}

/*		删除结点。删除第pos个结点。pos的值大于0而小于等于结点个数。		*/
status DeleteNode(node **Node, cur **Cur, const cur pos)
{
	if (pos > 0 && pos <=  CountList(Node, Cur))
	{
		cur i, j;
		for (i = MAXSIZE - 1, j = 0; j < pos - 1; i = *(*Cur + i), ++j)
		{
		}
		j = *(*Cur + i);
		*(*Cur + i) = *(*Cur + j);
		FreeNode(Node, Cur, j);
		return (OK);
	}
	return (ERROR);
}
