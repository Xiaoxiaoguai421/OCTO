/*************************************************************************
    > File Name: Find_kth.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月03日 星期二 16时03分32秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
using namespace std;
int Partition(vector<int> &s, int low, int high);
int Find_kth(vector<int> &s, int low, int high, int kth);
int main(void)
{
	int n = 0;
	cout << "请输入n:";
	cin >> n;
	vector<int> A;
	A.resize(n);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		A[i] = (int)rand() % 10;
		cout << A[i] << " ";
	}
	cout << endl;
	int mid = Find_kth(A, 0, n - 1, n / 2);
	cout << "这组数的中位数是:" << mid << endl;
	return 0;
}

int Find_kth(vector<int> &s, int low, int high, int kth)
{
	if (low >= high)
		return s[low];
	else
	{
		int pvot = Partition(s, low, high);
		if ( kth == pvot)
			return s[pvot];
		else if (kth < pvot)   return Find_kth(s, low, pvot - 1, kth);
		else if (kth > pvot)   return Find_kth(s, pvot + 1, high, kth);
	}
}

int Partition(vector<int> &s, int low, int high)
{
	int key = s[low];
	int l = low;
	int h = high;

	while (l < h)
	{
		while ((l < h) && (s[h] >= key))
			h--;
		if (l < h)
			s[l++] = s[h];
		while ((l < h) && (s[l] <= key))
			l++;
		if (l < h)
			s[h--] = s[l];
	}
	s[l] = key;
	return l;
}
