/*************************************************************************
    > File Name: SeqStack.h
    > Author:
    > Mail:
    > Created Time: 2017年10月22日 星期日 15时27分03秒
 ************************************************************************/

#ifndef _SEQSTACK_H
#define _SEQSTACK_H
#include<iostream>
#include<cstdlib>
template<class T, int MaxSize>
class SeqStack
{
public:
	SeqStack();
	void Push(T x);
	T Pop();    //出栈
	T Top();    //取栈顶元素
	bool isEmpty();
	bool isFull();
private:
	T data[MaxSize];
	int top;
};
#endif
