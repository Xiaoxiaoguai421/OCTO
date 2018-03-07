/*************************************************************************
    > File Name: Sort.cpp
    > Author:
    > Mail:
    > Created Time: 2018年02月27日 星期二 20时13分24秒
 ************************************************************************/

#ifndef _SORT_CPP
#define _SORT_CPP

#include"Sort.h"
void ShellSort(int r[], int n)
{
	int i = 0;
	int j = 0;
	for (int d = n / 2; d >= 1; d = d / 2)
		for (i = d; i < n; i++)
		{
			int temp = r[i];
			for ( j = i - d; j >= 0 && temp < r[i]; j = j - d)
				r[j + d] = r[j];
			r[j + d] = temp;
		}
}

int Partition(int r[], int i, int j)
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
void QuickSort(int r[], int i, int j)
{
	if (i < j)
	{
		int pivot = Partition(r, i, j);
		QuickSort(r, i, pivot - 1);
		QuickSort(r, pivot + 1, j);
	}
}

void Shif(int r[], int k, int m)
{
	int i = k;
	int j = 2 * i;
	while (j <= m)
	{
		if (j < m && r[j] < r[j + 1])
			j++;
		if (r[i] > r[j])
			break;
		else
		{
			int temp = r[j];
			r[j] = r[i];
			r[i] = temp;

			i = j;
			j = 2 * i;
		}
	}
}
void HeapSort(int r[], int n)
{
	for (int i = n / 2; i >= 1; i--)
		Shif(r, i, n);
	for (int i = 1; i < n; i++)
	{
		int temp = r[n - i + 1];
		r[n - i + 1] = r[1];
		r[1] = temp;

		Shif(r, 1, n - i);
	}
}

void Merge(int r[], int r1[], int s, int m, int t)
{
	int i = s;
	int j = m + 1;
	int k = s;
	while (i <= m && j <= t)
	{
		if (r[i] <= r[j])
			r1[k++] = r[i++];
		else
			r1[k++] = r[j++];
	}
	while (i <= m)
		r1[k++] = r[i++];
	while (i > m && j <= t)
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
		for (int k = 1; k <= n; k++)
			r1[k] = r[k];
}
void MergeSort(int r[], int n)
{
	int *r1 = new int[MaxNum];
	int h = 1;
	while (h < n)
	{
		MergePass(r, r1, n, h);
		h = 2 * h;
		MergePass(r, r1, n, h);
		h = 2 * h;
	}
	delete []r1;
}
#endif
