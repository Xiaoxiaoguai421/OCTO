/*************************************************************************
    > File Name: Count_Key.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年03月13日 星期二 18时44分15秒
 ************************************************************************/

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
const int MaxSize = 5;
void Count_Key(int r[], int r1[], int s, int m, int t, int &cnt);
void MergePass(int r[], int r1[], int n, int h, int &cnt);
void Count(int r[], int n, int &cnt);
int main(void)
{
	int r[MaxSize + 1];
	cout << "请输入" << MaxSize << "个数\n$:";
	for (int i = 1; i <= MaxSize; i++)
		cin >> r[i];
	int count = 0;
	Count(r, MaxSize, count);
	cout << "重要逆序数个数为" << count << endl;
	return 0;
}

void Count_Key(int r[], int r1[], int s, int m, int t, int &cnt)
{
	int i = s;
	int j = m + 1;
	int k = s;
//数重要度量
	while (i <= m && j <= t)
	{
		if (r[i] > 2 * r[j])
		{
			cnt += m - i + 1;
			j++;
		}
		else
			i++;
	}
//归并排序部分
	i = s;
	j = m + 1;
	k = s;
	while (i <= m && j <= t)
	{
		if (r[i] < r[j])
			r1[k++] = r[i++];
		else
			r1[k++] = r[j++];
	}
	while (i <= m)
		r1[k++] = r[i++];
	while (j <= t)
		r1[k++] = r[j++];
}

void MergePass(int r[], int r1[], int n, int h, int &cnt)
{
	int i = 1;
	while (i <= n - 2 * h + 1)
	{
		Count_Key(r, r1, i, i + h - 1, i + 2 * h - 1, cnt);
		i += 2 * h;
	}
	if (i < n - h + 1)
		Count_Key(r, r1, i, i + h - 1, n, cnt);
	else
		for (int k = i; k <= n; k++)
			r1[k] = r[k];
}

void Count(int r[], int n, int &cnt)
{
	int h = 1;
	int r1[MaxSize + 1];
	while (h < n)
	{
		MergePass(r, r1, n, h, cnt);
		h = 2 * h;
		MergePass(r1, r, n, h, cnt);
		h = 2 * h;
	}
}
