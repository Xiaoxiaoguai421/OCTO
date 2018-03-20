/*************************************************************************
    > File Name: Remove_Dup.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年03月13日 星期二 18时44分15秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
int MaxSize = 6;
void Remove_Dup(int s[], int &length);
void Merge(int s[], int low, int middle, int high);
void MergeSort(int s[], int low, int high);
int main(void)
{
	int r[MaxSize];
	cout << "请输入" << MaxSize << "个数：\n$:";
	for (int i = 0; i < MaxSize; i++)
		cin >> r[i];
	Remove_Dup(r, MaxSize);
	cout << "删除重复值后" << endl;
	for (int i = 0; i < MaxSize; i++)
		cout << r[i] << '\t';
	cout << endl;
	return 0;
}

/*使用队列*/
void Remove_Dup(int s[], int &length)
{
	int i = 0;
	int count = 0;
	MergeSort(s, 0, length - 1);
	queue<int> buffer;
	for (i = 0; i < length - 1; i++)
	{
		if (s[i] != s[i + 1])
			buffer.push(s[i]);
		else
			count++;
	}
	buffer.push(s[i]);
	i = 0;
	while (!buffer.empty())
	{
		s[i++] = buffer.front();
		buffer.pop();
	}
	length = length - count;
}

void MergeSort(int s[], int low, int high)
{
	int middle;
	if (low < high)
	{
		middle = (low + high) / 2;
		MergeSort(s, low, middle);
		MergeSort(s, middle + 1, high);
		Merge(s, low, middle, high);
	}
}

void Merge(int s[], int low, int middle, int high)
{
	int i;
	queue<int> buffer1;
	queue<int> buffer2;
	for (i = low; i <= middle; i++)
		buffer1.push(s[i]);
	for (i = middle + 1; i <= high; i++)
		buffer2.push(s[i]);
	i = low;
	while (!(buffer1.empty() || buffer2.empty()))
	{
		if (buffer1.front() <= buffer2.front())
		{
			s[i++] = buffer1.front();
			buffer1.pop();
		}
		else
		{
			s[i++] = buffer2.front();
			buffer2.pop();
		}
	}
	while (!buffer1.empty())
	{
		s[i++] = buffer1.front();
		buffer1.pop();
	}
	while (!buffer2.empty())
	{
		s[i++] = buffer2.front();
		buffer2.pop();
	}
}
