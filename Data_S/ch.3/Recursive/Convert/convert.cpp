/*************************************************************************
    > File Name: convert.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月02日 星期四 23时52分45秒
 ************************************************************************/

#include<iostream>
using namespace std;
void convert(int num, int S);
int main(void)
{
	int num;
	cout << "请输入十进制数(num)\n$:";
	cin >> num;
	cout << "转换成2进制数" << endl;
	convert(num, 2);
	cout << endl;
	cout << "转换成8进制数" << endl;
	convert(num, 8);
	cout << endl;
	cout << "转换成16进制数" << endl;
	convert(num, 16);
	cout << endl;
	return 0;
}

void convert(int num, int S)
{
	if (num == 0)
		return;
	convert(num / S, S);
	if (num % S < 9)
		cout << num % S;
	else
		cout << char(num % S + 55);
}
