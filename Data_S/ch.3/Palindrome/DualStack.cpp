/*************************************************************************
    > File Name: DualStack.cpp
    > Author:
    > Mail:
    > Created Time: 2017年10月29日 星期日 14时57分44秒
 ************************************************************************/

#include"DualStack.h"
template<class T, int MaxSize>
DualStack<T, MaxSize>::DualStack()
{
	right_top = MaxSize;
	left_top = -1;
}

template<class T, int MaxSize>
void DualStack<T, MaxSize>::Push(T x, LR lr)
{
	if (isFull())
	{
		cerr << "栈满!" << endl;
		exit(1);
	}
	if (lr == Left)
		data[++left_top] = x;
	else if (lr == Right)
		data[--right_top] = x;
	else
		cout << "入栈失败" << endl;
}

template<class T, int MaxSize>
T DualStack<T, MaxSize>::Pop(LR lr)
{
	if (isEmpty(lr))
	{
		cerr << "栈空!" << endl;
		exit(1);
	}
	if (lr == Left)
		return data[left_top--];
	else if (lr == Right)
		return data[right_top++];
	else
	{
		cerr << "出栈失败" << endl;
		exit(1);
	}
}

template<class T, int MaxSize>
T DualStack<T, MaxSize>::Top(LR lr)
{
	if (isEmpty(lr))
	{
		cerr << "栈空!" << endl;
		exit(1);
	}
	if (lr == Left)
		return data[left_top];
	else if (lr == Right)
		return data[right_top];
	else
	{
		cerr << "取栈顶元素失败" << endl;
		exit(1);
	}
}

template<class T, int MaxSize>
bool DualStack<T, MaxSize>::isEmpty(LR lr)
{
	if (lr == Left)
		return left_top == -1;
	if (lr == Right)
		return right_top == MaxSize;
}

template<class T, int MaxSize>
bool DualStack<T, MaxSize>::isEmpty()
{
	return (isEmpty(Left) && isEmpty(Right)) ? true : false;
}

template<class T, int MaxSize>
bool DualStack<T, MaxSize>::isFull()
{
	return (right_top + 1 == left_top) ? true : false;
}

template<class T, int MaxSize>
bool DualStack<T, MaxSize>::isPalindrome(T *s, int length)
{
	const LR L = Left;
	const LR R = Right;
	int next = length / 2;
	//入栈
	for (int i = 0; i < next; i++)
		Push(s[i], L);
	if (length % 2 == 0)
		next--;
	for (int i = length - 1; i > next; i--)
		Push(s[i], R);
	//匹配
	while (!isEmpty(L) && !isEmpty(R))
		if (Pop(L) != Pop(R))
			return false;
	return true;
}
