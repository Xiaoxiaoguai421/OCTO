/*************************************************************************
    > File Name: LinkStack.h
    > Author:
    > Mail:
    > Created Time: 2017年10月31日 星期二 09时52分12秒
 ************************************************************************/

#ifndef _LINKSTACK_H
#define _LINKSTACK_H
#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>
struct  Node
{
	T data;
	Node<T> *next;
};

template<class T>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
	void Push(T x);
	T Pop();
	T Top();
	bool isEmpty();
private:
	Node<T> *top;
};
#endif
