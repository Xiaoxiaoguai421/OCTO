/*************************************************************************
    > File Name: Str.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月06日 星期一 19时26分20秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MaxSize = 100;
void StrCat(char *target, char *source);
int StrCmp(char *s1, char *s2);
void StrCpy(char *target, char *source);
void StrRev(char *s);
void StrSet(char *target, char item);
int main(void)
{
	char str_1[MaxSize];
	char str_2[MaxSize];
	cout << "请输入字符串(str_1)\n$:";
	cin >> str_1;
	cout << "请输入字符串（str_2)\n$:";
	cin >> str_2;

	if (StrCmp(str_1, str_2) == 0)
		cout << "输入的两个串相等" << endl;

	cout << "将str_1倒排" << endl;
	StrRev(str_1);
	cout << str_1<<endl;

	cout << "str_2拷贝到str_1" << endl;
	StrCpy(str_1, str_2);
	cout << "str_1:" << str_1 << endl;
	cout << "str_2:" << str_2 << endl;

	cout << "str_2连接到str_1上" << endl;
	StrCat(str_1, str_2);
	cout << "str_1" << str_1 << endl;

	char item;
	cout << "将str_1全置为\n$:";
	cin >> item;
	cout << "全置结果为" << endl;
	StrSet(str_1, item);
	cout << str_1 << endl;

	return 0;
}
//字符串链接
void StrCat(char *target, char *source)
{
	int len_target = strlen(target);
	int len_source = strlen(source);
	if (len_target + len_source > MaxSize - 1)
	{
		cerr << "超长" << endl;
		exit(1);
	}
	int i = 0;
	while (source[i] != '\0')
	{
		target[i + len_target] = source[i];
		i++;
	}
	target[i + len_target] = '\0';
}
//字符串比较
int StrCmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
//字符串拷贝
void StrCpy(char *target, char *source)
{
	int len = strlen(source);
	if (len > MaxSize - 1)
	{
		cerr << "超长" << endl;
		exit(1);
	}
	while (*target++ = *source++);
}
//字符串倒置
void StrRev(char *s)
{
	int length = strlen(s);
	char temp;
	for (int i = 0; i < length / 2; i++)
	{
		temp = s[i];
		s[i] = s[length - 1 - i];
		s[length - 1 - i] = temp;
	}
}
//将target全置为item
void StrSet(char *target, char item)
{
	while (*target != '\0')
		*target++ = item;
}
