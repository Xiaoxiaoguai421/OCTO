/*************************************************************************
    > File Name: brace_match.cpp
    > Author:
    > Mail:
    > Created Time: 2017年10月31日 星期二 20时34分23秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MaxSize = 20;
const int Max = 100;
class Match
{
public:
	Match();
	int Brace(char *ch);
private:
	char data[MaxSize];
	int top;
};

int main(void)
{
	char E[Max];
	cout << "请输入含有{[()]}的表达式\n$:";
	cin >> E;
	if (strlen(E) > Max)
	{
		cerr << "表达式过长" << endl;
		exit(1);
	}
	Match A;
	cout << A.Brace(E) << endl;
	return 0;
}

Match::Match()
{
	top = -1;
}

int Match::Brace(char *ch)
{
	char *p = ch;
	while ( (p - ch) <= strlen(ch))
	{
		if (top >= MaxSize)
		{
			cerr << "表达式过长" << endl;
			exit(1);
		}
		switch (*p)
		{
		case '(':
			if (data[++top] = '(')
				break;
		case '[':
			if (data[++top] = '[')
				break;
		case '{':
			if (data[++top] = '{')
				break;
		case ')':
			if (data[top--] == '(' )
				break;
			else
				return 0;
		case ']':
			if (data[top--] == '[')
				break;
			else
				return 0;
		case '}':
			if (data[top--] == '{')
				break;
			else
				return 0;
		default:
			break;
		}
		p++;
		if (top == -1)
			break;
	}
	if (top == -1)
		return 1;
	else
		return 0;
}
