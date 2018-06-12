/*************************************************************************
    > File Name: LIS.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月15日 星期日 21时14分27秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int INFINITY = 9999;
void LIS(vector<int> a);
void LIS(vector<int> a, vector<int>& result);
int main(void)
{
	vector<int> a(5);
	cout << "请输入5个数据:";
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	LIS(a);
	return 0;
}

void LIS(vector<int> a)
{
	int n = a.size();
	vector<int> L(n);
	L[0] = 1;
	vector<int> prev(n);    //前驱结点
	for (int i = 0; i < n; i++)
		prev[i] = INFINITY;

	//填L[]数组
	for (int i = 1; i < n; i++)
	{
		int max = 1;
		int u = 0;
		for (int k = 0; k < i; k++)
			if (a[k] < a[i])
			{
				u = L[k] + 1;
				if (max < u)
				{
					max = u;
					prev[i] = k;
				}
			}
		L[i] = max;
	}

	//找最长子序列的长度
	int max = 0;
	int index = 0;
	for (int i = 0; i < n; i++)
		if (max < L[i])
		{
			max = L[i];
			index = i;
		}
	cout << "最长递归子序列的长度为：" << max << endl;
	/*
	    cout << "输出L: ";
	    for (int i = 0; i < n; i++)
	        cout << L[i] << " ";
	    cout << endl;

	    cout << "输出prev: ";
	    for (int i = 0; i < n; i++)
	        cout << prev[i] << " ";
	    cout << endl;
	*/
	//输出最长递归子序列
	vector<int> substr(max);
	int k = 0;
	while (prev[index] != INFINITY)
	{
		substr[k++] = a[index];
		index = prev[index];
	}
	substr[k] = a[index];
	cout << "最长递增子序列为：";
	for (k = max - 1; k > 0; k--)
		cout << substr[k] << " ";
	cout << substr[k] << endl;
}





void  LIS(vector<int> a, vector<int>& result)
{
	vector<int> b(a);
	sort(b.begin() + 1, b.end());
	//LCS问题,得到表L[n][m]
	int n = a.size();
	int m = b.size();
	vector<vector<int> > L(n);
	for (int i = 0; i < n; i++)
		L[i].resize(m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || j == 0)  L[i][j] = 0;
			else if (a[i] == b[j])
				L[i][j] = L[i - 1][j - 1] + 1;
			else L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
		}
	//得到LCS
	int i = n - 1;
	int j = m - 1;;
	while (i > 0 && j > 0)
	{
		if (a[i] == b[j])
		{
			result.push_back(a[i]);
			i--;
			j--;
		}
		else if (L[i - 1][j] > L[i][j - 1])    j--;
		else    i--;
	}
}
