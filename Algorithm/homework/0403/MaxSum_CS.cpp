/*************************************************************************
    > File Name: MaxSum_CS.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月09日 星期一 21时46分30秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int MaxSum_CS(vector<int> a);
int main(void)
{
	int n = 0;
	cout << "请输入元素个数：";
	cin >> n;
	vector<int> a;
	a.resize(n + 1);
	a[0] = 0;
	cout << "请输入整数数据：";
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << "最大子序列之和为：" << MaxSum_CS(a) << endl;
	return 0;
}

int MaxSum_CS(vector<int> a)
{
	int n=a.size();
	int sum = 0;
	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s > 0) s += a[i];
		else    s = a[i];
		if (s > sum)   sum = s;
	}
	return sum;
}
