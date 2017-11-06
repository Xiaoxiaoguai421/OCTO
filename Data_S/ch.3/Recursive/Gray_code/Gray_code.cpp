/*************************************************************************
    > File Name: Gray_code.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月05日 星期日 19时43分59秒
    > n位格雷码制表 算法:
        当只有一位时，输出0/1
        递归后，当前列前一半置0，后一半置1，前几列逆置
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
const int MaxBit = 6;
const int Maxlength = 64;
void Gray(char Array_G[][MaxBit], int n);   //Array_G存放格雷码,n为格雷码位数
int main(void)
{
	int num = 0;
	cout << "请输入一个数(num<" << Maxlength << ")\n$:" << endl;
	cin >> num;
	if(num>Maxlength)
	{
		cerr<<"输入的数太大"<<endl;
		exit(1);
	}
	int count = 0, num_copy = num;
	if (num == 0)
		count = 1;
	while (num != 0)
	{
		num = num / 2;
		count++;
	}
	char array_g[Maxlength][MaxBit];
	Gray(array_g, count);   //获得格雷码表
	/*打印格雷码表
	int M=pow(2,count);
	for (int i = 0; i < M; i++)
	{
	    for(int j=N-1;j>=0;j--)
	        cout << array_g[i][j];
	    cout<<endl;
	}
	*/
	cout << num_copy << "的格雷码是" << endl;
	for (int j = count; j >= 0; j--)
		cout << array_g[num_copy][j];
	cout << endl;
	return 0;
}

void Gray(char Array_G[][MaxBit], int n)
{
	int length = pow(2, n);
	if (n == 1)
	{
		Array_G[0][0] = 48;
		Array_G[1][0] = 49;
	}
	else
	{
		Gray(Array_G, n - 1);
		for (int i = 0; i < length / 2; i++)
			Array_G[i][n - 1] = 48;
		for (int i = length / 2; i < length; i++)
			Array_G[i][n - 1] = 49;
		for (int i = length / 2; i < length; i++)
			for (int j = 0; j < n - 1; j++)
				Array_G[i][j] = Array_G[length - i - 1][j];
	}
}
