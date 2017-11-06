/*************************************************************************
    > File Name: main.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月05日 星期日 22时34分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include"SeqStack.cpp"
using namespace std;
const int MaxSize = 50; //表达式最大长度
char Precede(char str_1, char str_2);
double Operate(double a, char op, double b);
double Expression_Eval();
int main(void)
{
	cout << "请输入表达式" << endl;
	double result = Expression_Eval();
	cout << "=" << result << endl;
	return 0;
}

char Precede(char str_1, char str_2)
{
	int r = 0;
	int c = 0;
	char Prority[][8] =
	{
		{' ', '+', '-', '*', '/', '(', ')', '@'},
		{'+', '>', '>', '<', '<', '<', '>', '>'},
		{'-', '>', '>', '<', '<', '<', '>', '>'},
		{'*', '>', '>', '>', '>', '<', '>', '>'},
		{'/', '>', '>', '>', '>', '<', '>', '>'},
		{'(', '<', '<', '<', '<', '<', '=', ' '},
		{')', '>', '>', '>', '>', ' ', '>', '>'},
		{'@', '<', '<', '<', '<', '<', ' ', '='}
	};
	for (int i = 0; i < 8; i++)
	{
		if (Prority[0][i] == str_1)
			c = i;
		if ((Prority[i][0] == str_2))
			r = i;
	}
	return Prority[c][r];
}

double Operate(double a, char op, double b)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
}

double Expression_Eval()
{
	SeqStack<char, 100> OPTR;
	SeqStack<double, 100> OPND;
	OPTR.Push('@');
	char ch = getchar();
	while (ch != '@' || OPTR.Top() != '@')
	{
		if (ch >= '0' && ch <= '9')
		{
			OPND.Push(ch - '0');
			ch = getchar();
		}
		else
		{
			char pre_op = OPTR.Top();
			switch (Precede(pre_op, ch))
			{
			case '<':
				OPTR.Push(ch);
				ch = getchar();
				break;
			case '=':
				OPTR.Pop();
				ch = getchar();
				break;
			case '>':
				char b = OPND.Pop();
				char a = OPND.Pop();
				pre_op = OPTR.Pop();
				OPND.Push(Operate(a, pre_op, b));
				break;
			}
		}
	}
	return OPND.Pop();
}
