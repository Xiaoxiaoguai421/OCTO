/*************************************************************************
    > File Name: main.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月02日 星期四 21时35分35秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include"DualStack.cpp"
using namespace std;
const int MaxSize = 100;
int main(void)
{
	DualStack<char, MaxSize> A;
	char s[MaxSize / 2];
	cout << "请输入一组数据(少于" << MaxSize / 2 << "个)\n$:";
	cin>>s;
	if (A.isPalindrome(s,strlen(s)))
		cout << "是回文" << endl;
	else
		cout << "不是回文" << endl;
	return 0;

}
