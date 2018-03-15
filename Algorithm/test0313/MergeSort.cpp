/*************************************************************************
    > File Name: MergeSort.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年03月13日 星期二 18时44分15秒
 ************************************************************************/

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
const int MaxSize = 5;
void Merge(int r[], int r1[], int s, int m, int t);
void MergePass(int r[], int r1[], int n, int h);
void MergeSort(int r[], int n);
int main(void)
{
	int r[MaxSize + 1];
	r[0] = 0;
	srand(time(NULL));
	for (int i = 1; i <= MaxSize; i++)
		r[i] = rand();
	MergeSort(r, MaxSize);
	for (int i = 1; i <= MaxSize; i++)
		cout << r[i] << '\t';
	cout << endl;
	return 0;
}

void Merge(int r[], int r1[], int s, int m, int t)
{
	int i = s;
	int j = m + 1;
	int k = s;
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

void MergePass(int r[], int r1[], int n, int h)
{
	int i = 1;
	while (i <= n - 2 * h + 1)
	{
		Merge(r, r1, i, i + h - 1, i + 2 * h - 1);
		i += 2 * h;
	}
	if (i < n - h + 1)
		Merge(r, r1, i, i + h - 1, n);
	else
		for (int k = i; k <= n; k++)
			r1[k] = r[k];
}

void MergeSort(int r[], int n)
{
	int h = 1;
	int r1[MaxSize + 1];
	while (h < n)
	{
		MergePass(r, r1, n, h);
		h = 2 * h;
		MergePass(r1, r, n, h);
		h = 2 * h;
	}
}
