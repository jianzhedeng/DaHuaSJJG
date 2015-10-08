#include "SingleLinkedList_Linked_cpp.h"



template <class T>
SingleLinkedList<T>::SingleLinkedList()
{
	InitList();
}

template <class T>
SingleLinkedList<T>::~SingleLinkedList()
{
	ReleaseList();
}

template <class T>
status SingleLinkedList<T>::Insert(Node &node, const int pos)
{
	/*	检查pos是否大于节点数量		*/
	/*	pos为零则插入最后		*/
	/*	pos不为零则插入相应节点之前		*/
	int i = 0;
	Node *p = NULL;
	if (pos > 0 && pos <= GetLength())
	{
		for (i = 0, p = this->Head; i < (pos - 1); ++i, p = p->next)
		{
		}
		node.next = p->next;
		p->next = &node;
		return (OK);
	}
	else if (pos == 0)
	{
		for (i = 0, p = this->Head; p->next != NULL; ++i, p = p->next)
		{
		}
		node.next = p->next;
		p->next = &node;
		return (OK);
	}
	return (ERROR);
}

template <class T>
status SingleLinkedList<T>::Insert(const T ele, const int pos)
{
	/*	此处应使用new关键字来申请结点空间		*/
	Node *p = new Node(ele);
	return (Insert(*p, pos));
}

template <class T>
Node * SingleLinkedList<T>::Take(const int pos)
{
	int i = 0;
	const int num = GetLength();
	Node *p = NULL, *q = NULL;
	if (pos > 0 && pos < num)
	{
		for (i = 0, p = this->Head; i < (pos - 1); ++i, p = p->next)
		{
		}
		q = p->next;
		p->next = p->next->next;
		q->next = NULL;
		return (q);
	}
	else if (pos == num || pos == 0)
	{
		for (i = 0, p = this->Head; i < (num - 1); ++i, p = p->next)
		{
		}
		q = p->next;
		p->next = p->next->next;
		return (q);
	}
	return (p);
}

template <class T>
status SingleLinkedList<T>::Delete(const int pos)
{
	Node *p = NULL;
	p = this->Take(pos);
	if (NULL != p)
	{
		/*	适时释放		*/
		return (OK);
	}
	else
	{
		return (ERROR);
	}
}

template <class T>
T SingleLinkedList<T>::Get(const int pos)
{
	int i = 0;
	int num = GetLength();
	Node *p = NULL;
	if (pos > 0 && pos < num)
	{
		for (i = 0, p = this->Head; i < pos; ++i, p = p->next)
		{
		}
		return (p->data);
	}
	else if (pos == 0 || pos == num)
	{
		for (i = 0, p = this->Head; i < num; ++i, p = p->next)
		{
		}
		return (p->data);
	}
	return (NULL);
}

template <class T>
status SingleLinkedList<T>::Set(const T ele, const int pos)
{
	Node *p = NULL;
	p = this->GetNode(pos);
	if (NULL != p)
	{
		p->data = ele;
		return (OK);
	}
	return (ERROR);
}
