/*************************************************************************
    > File Name: Find_K.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月01日 星期日 21时45分06秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int Find_k(vector<int> a, int a_low, int a_high, vector<int> b, int b_low, int b_high, int k);
int main(void)
{
	int m, n, k;
	cin >> m >> n >> k;
	vector<int> a;
	a.resize(m);
	vector<int> b;
	b.resize(n);
	cout << "输入有序数列a：";
	for (int i = 0; i < m; i++)
		cin >> a[i];
	cout << "输入有序数列b: ";
	for (int i = 0; i < n; i++)
		cin >> b[i];
	cout << "合并序列中第" << k << "小的数为:" << Find_k(a, 0, m - 1, b, 0, n - 1, k) << endl;
	return 0;
}

int Find_k(vector<int> a, int a_low, int a_high, vector<int> b, int b_low, int b_high, int k)
{
	if (a_low > a_high)    return b[b_low + k - 1];
	if (b_low > b_high)    return a[a_low + k - 1];

	int a_mid = (a_low + a_high) / 2;
	int b_mid = (b_low + b_high) / 2;
	int half = a_mid - a_low + b_mid - b_low + 2;

	if (a[a_mid] < b[b_mid])
	{
		if (k < half)  return Find_k(a, a_low, a_high, b, b_low, b_mid - 1, k);
		else    return Find_k(a, a_mid + 1, a_high, b, b_low, b_high, k - (a_mid - a_low + 1));
	}
	else
	{
		if (k < half)  return Find_k(a, a_low, a_mid - 1, b, b_low, b_high, k);
		else return Find_k(a, a_low, a_high, b, b_mid + 1, b_high, k - (b_mid - b_low + 1));
	}
}
