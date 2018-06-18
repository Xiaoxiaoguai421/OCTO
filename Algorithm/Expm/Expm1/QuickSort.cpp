/*************************************************************************
    > File Name: QuickSort.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年03月13日 星期二 19时02分36秒
 ************************************************************************/

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
const int MaxSize = 5;
int Partition_1(int r[], int i, int j);
void Swap(int &a, int &b);
int Partition_2(int s[], int l, int h);
void QuickSort_1(int r[], int i, int j);
void QuickSort_2(int s[], int l, int h);
int main(void)
{
	int r1[MaxSize];
	int r2[MaxSize];
	srand(time(NULL));
	for (int i = 0; i < MaxSize; i++)
		r1[i] = r2[i] = rand();

	QuickSort_1(r1, 0, MaxSize - 1);
	cout << "QuickSort_1:";
	for (int i = 0; i < MaxSize; i++)
		cout << r1[i] << '\t';
	cout << endl;

	QuickSort_2(r2, 0, MaxSize - 1);
	cout << "QuickSort_2:";
	for (int i = 0; i < MaxSize; i++)
		cout << r2[i] << '\t';
	cout << endl;

	return 0;
}

int Partition_1(int r[], int i, int j)
{
	int temp = r[i];
	while (i < j)
	{
		while (i < j && r[j] >= temp)
			j--;
		if (i < j)
			r[i++] = r[j];
		while (i < j && r[i] <= temp)
			i++;
		if (i < j)
			r[j--] = r[i];
	}
	r[i] = temp;
	return i;
}

void QuickSort_1(int r[], int i, int j)
{
	if (i < j)
	{
		int pivot = Partition_1(r, i, j);
		QuickSort_1(r, i, pivot - 1);
		QuickSort_1(r, pivot + 1, j);
	}
}


void Swap(int &a, int &b)
{
	int temp = b;
	b = a;
	a = temp;
}

int Partition_2(int s[], int l, int h)
{
	int i;
	int p = h;
	int first = l;
	for (i = l; i < h; i++)
		if (s[i] < s[p])
		{
			Swap(s[i], s[first]);
			first++;
		}
	Swap(s[p], s[first]);
	return first;
}

void QuickSort_2(int s[], int l, int h)
{
	if (l < h)
	{
		int pivot = Partition_2(s, l, h);
		QuickSort_2(s, l, pivot - 1);
		QuickSort_2(s, pivot + 1, h);
	}
}
