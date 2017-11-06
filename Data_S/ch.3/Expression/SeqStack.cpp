/*************************************************************************
    > File Name: SeqStack.cpp
    > Author:
    > Mail:
    > Created Time: 2017年10月24日 星期二 09时46分10秒
 ************************************************************************/
//ifndef _SEQSTACK_CPP
//define _SEQSTACK_CPP

#include"SeqStack.h"
using namespace std;
template<class T, int MaxSize>
SeqStack<T, MaxSize>::SeqStack()
{
	top = -1;
}

template<class T, int MaxSize>
void SeqStack<T, MaxSize>::Push(T x)
{
	if ( isFull() )
	{
		cerr << "上溢";
		exit(1);
	}
	data[++top] = x;
}

template<class T, int MaxSize>
T SeqStack<T, MaxSize>::Pop()
{
	if ( isEmpty() )
	{
		cerr << "下溢";
		exit(1);
	}
	T x = data[top--];
	return x;
}

template<class T, int MaxSize>
T SeqStack<T, MaxSize>::Top()
{
	if ( isEmpty() )
	{
		cerr << "下溢";
		exit(1);
	}
	return data[top];
}

template<class T, int MaxSize>
bool SeqStack<T, MaxSize>::isEmpty()
{
	return top == -1;
}

template<class T, int MaxSize>
bool SeqStack<T, MaxSize>::isFull()
{
	return top == MaxSize - 1;
}

//endif
