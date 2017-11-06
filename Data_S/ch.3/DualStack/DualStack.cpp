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
void DualStack<T, MaxSize>::Push(T x, int LR)
{
	if (isFull())
	{
		cerr << "栈满!" << endl;
		exit(1);
	}
	if (LR == 0)
		data[++left_top] = x;
	else if (LR == 1)
		data[--right_top] = x;
	else
		cout << "入栈失败" << endl;
}

template<class T, int MaxSize>
T DualStack<T, MaxSize>::Pop(int LR)
{
	if (isEmpty(LR))
	{
		cerr << "栈空!" << endl;
		exit(1);
	}
	if (LR == 0)
		return data[left_top--];
	else if (LR == 1)
		return data[right_top++];
	else
	{
		cerr << "出栈失败" << endl;
		exit(1);
	}
}

template<class T, int MaxSize>
T DualStack<T, MaxSize>::Top(int LR)
{
	if (isEmpty(LR))
	{
		cerr << "栈空!" << endl;
		exit(1);
	}
	if (LR == 0)
		return data[left_top];
	else if (LR == 1)
		return data[right_top];
	else
	{
		cerr << "取栈顶元素失败" << endl;
		exit(1);
	}
}

template<class T, int MaxSize>
bool DualStack<T, MaxSize>::isEmpty(int LR)
{
	if (LR == 0)
		return left_top == -1;
	if (LR == 1)
		return right_top == MaxSize;
}

template<class T, int MaxSize>
bool DualStack<T, MaxSize>::isEmpty()
{
	return (isEmpty(0) && isEmpty(1)) ? true : false;
}

template<class T, int MaxSize>
bool DualStack<T, MaxSize>::isFull()
{
	return (right_top + 1 == left_top) ? true : false;
}
