/*************************************************************************
    > File Name: main.cpp
    > Author:
    > Mail:
    > Created Time: 2017年10月29日 星期日 15时29分02秒
 ************************************************************************/

#include"DualStack.cpp"
#include<iostream>
using namespace std;
const int MaxSize = 10;
int main(void)
{
	DualStack<int, MaxSize> A;
	int x = 0;
	int num = 0;
	int LR = -1;
	while (1)
	{
		cout << "************************************************" << endl;
		cout << "0 -- 入栈\t1 -- 取栈顶元素\t2 -- 出栈\t3 -- 退出" << endl;
		cout << "************************************************" << endl;
		int choose = -1;
		cout << "请选择功能\n$:";
		cin >> choose;
		switch (choose)
		{
		case 0:
			cout << "请选择入栈元素位置(LR 0--左栈  1-- 右栈)\n$:";
			cin >> LR;
			cout << "请选择入栈元素的个数(num)\n$:";
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				cin >> x;
				A.Push(x, LR);
			}
			break;
		case 1:
		{
			LR = -1;
			cout << "请选择栈(LR 0--左栈  1-- 右栈)\n$:";
			cin >> LR;
			cout << A.Top(LR) << endl;
			break;
		}
		case 2:
		{
			LR = -1;
			cout << "请选择栈(LR 0--左栈  1-- 右栈)\n$:";
			cin >> LR;
			while (LR == 0 && !A.isEmpty(LR))
				cout << "左栈元素：" << A.Pop(LR) << endl;
			while (LR == 1 && !A.isEmpty(LR))
				cout << "右栈元素：" << A.Pop(LR) << endl;
			break;
		}
		case 3:
			return 0;
		default:
			break;
		}
	}
	return 0;
}
