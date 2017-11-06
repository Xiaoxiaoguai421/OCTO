/*************************************************************************
    > File Name: DualStack.h
    > Author:
    > Mail:
    > Created Time: 2017年10月29日 星期日 14时39分44秒
 ************************************************************************/

#ifndef _DUALSTACK_H
#define _DUALSTACK_H
#include<iostream>
#include<cstdlib>
using namespace std;
template<class T, int MaxSize>
class DualStack
{
public:
	DualStack();
	void Push(T x, int LR); //LR选择入左栈或右栈
	T Pop(int LR);
	T Top(int LR);
	bool isEmpty(int LR);
	bool isEmpty();
	bool isFull();
private:
	T data[MaxSize];
	int right_top;
	int left_top;
};
#endif
