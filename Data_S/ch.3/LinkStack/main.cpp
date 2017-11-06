/*************************************************************************
    > File Name: main.cpp
    > Author:
    > Mail:
    > Created Time: 2017年10月31日 星期二 10时11分23秒
 ************************************************************************/

#include<iostream>
#include"LinkStack.cpp"
using namespace std;
int main(void)
{
	LinkStack<int> A;
	int x = 0, num = 0;
	cout << "请输入入栈元素个数\n$:";
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> x;
		A.Push(x);
	}

	cout << "取栈顶元素" << endl;
	cout << A.Top() << endl;

	cout << "出栈" << endl;
	for (int i = 0; i < num; i++)
		cout << A.Pop() << endl;
	return 0;
}
