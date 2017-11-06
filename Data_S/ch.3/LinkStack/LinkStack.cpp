/*************************************************************************
    > File Name: LinkStack.cpp
    > Author:
    > Mail:
    > Created Time: 2017年10月31日 星期二 09时59分20秒
 ************************************************************************/

#include"LinkStack.h"
template<class T>
LinkStack<T>::LinkStack()
{
	top = NULL;
}

template<class T>
LinkStack<T>::~LinkStack()
{
	Node<T> *p = top;
	while (p)
	{
		Node<T> *q = p;
		p = p->next;
		delete q;
	}
	top = NULL;
}

template<class T>
void LinkStack<T>::Push(T x)
{
	Node<T> *s = new Node<T>;
	s->data = x;
	s->next = top;
	top = s;
}

template<class T>
T LinkStack<T>::Pop()
{
	if (top == NULL)
	{
		cerr << "下溢" << endl;
		exit(1);
	}
	T x = top->data;
	Node<T> *p = top;
	top = top->next;
	delete p;
	return x;
}

template<class T>
T LinkStack<T>::Top()
{
	if (top == NULL)
	{
		cerr << "下溢" << endl;
		exit(1);
	}
	return top->data;
}

template<class T>
bool LinkStack<T>::isEmpty()
{
	return top == NULL;
}
