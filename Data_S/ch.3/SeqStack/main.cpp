/*************************************************************************
    > File Name: main.cpp
    > Author:
    > Mail:
    > Created Time: 2017年10月24日 星期二 10时28分59秒
 ************************************************************************/

#include<iostream>
#include"SeqStack.cpp"
using namespace std;
const int MaxSize = 100;
int main(void)
{
	int num = 0;
	SeqStack<int, MaxSize> A;
	cout << "请输入待输入数据的个数\n$:";
	cin >> num;
	int x = 0;

	//测试入栈
	cout << "输入数据\n$:";
	for (int i = 0; i < num; i++)
	{
		cin >> x;
		A.push(x);
	}
	if (A.isEmpty())
		cout << "入栈失败" << endl;

	//测试取栈顶元素
	cout << "取栈顶元素" << endl;
	cout << A.Top() << endl;

	//测试出栈，同时打印出栈元素
	cout << "遍历/出栈" << endl;
	for (int i = 0; i < num; i++)
		cout << A.Pop() << endl;
	if (A.isEmpty())
	{
		cout << "栈空，出栈成功" << endl;
		exit(1);
	}

	return 0;
}
