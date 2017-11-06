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
typedef enum _LR{Left,Right}LR;
template<class T, int MaxSize>
class DualStack
{
public:
	DualStack();
	void Push(T x,LR lr); //LR选择入左栈或右栈
	T Pop(LR lr);
	T Top(LR lr);
	bool isEmpty(LR lr);
	bool isEmpty();
	bool isFull();
	bool isPalindrome(T *s,int length);  
private:
	T data[MaxSize];
	int right_top;
	int left_top;
};
#endif
