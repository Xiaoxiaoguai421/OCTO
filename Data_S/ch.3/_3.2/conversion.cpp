/*************************************************************************
    > File Name: conversion.cpp
    > Author:
    > Mail:
    > Created Time: 2017年10月31日 星期二 10时33分13秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int MaxSize = 20;
class Convert
{
public:
	Convert()
	{
		top = -1;
	}
	void Convert_D(int D, int Radix);   //把十进制的D转换成radix进制输出
private:
	int data[MaxSize];
	int top;
};

int main(void)
{
	Convert A;
	int temp = 0;
	cout << "请输入要转换的十进制数\n$:";
	cin >> temp;
	int radix = 10;
	cout << "请输入要转化的进制(2～16)\n$:";
	cin >> radix;
	cout << temp << "对应的" << radix << "进制如下" << endl;
	A.Convert_D(temp, radix);
	cout << endl;
	return 0;
}

void Convert::Convert_D(int D, int Radix)
{
	while (D != 0)
	{
		data[++top] = D % Radix;
		D /= Radix;
	}
	while (top != -1)
	{
		if (data[top] < 10)
			cout << data[top--];
		else
			cout << char(data[top--] % Radix + 55);
	}
}
