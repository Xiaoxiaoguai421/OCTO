/*************************************************************************
    > File Name: Count_Key.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年03月13日 星期二 18时44分15秒
	归并后，按从大到小顺序排列
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
const int MaxSize = 5;
void Merge(int s[], int low, int middle, int high, int &cnt);
void MergeSort(int s[], int low, int high, int &cnt);
int main(void)
{
	int r[MaxSize];
	cout << "请输入" << MaxSize << "个数\n$:";
	for (int i = 0; i < MaxSize; i++)
		cin >> r[i];
	int count = 0;
	MergeSort(r, 0, MaxSize - 1, count);
	cout << "重要逆序对个数为：" << count << endl;
	return 0;
}

/*使用队列*/
void MergeSort(int s[], int low, int high, int &cnt)
{
	int middle;
	if (low < high)
	{
		middle = (low + high) / 2;
		MergeSort(s, low, middle, cnt);
		MergeSort(s, middle + 1, high, cnt);
		Merge(s, low, middle, high, cnt);
	}
}

void Merge(int s[], int low, int middle, int high, int &cnt)
{
	/*Count Key*/
	int l = low;
	int m = middle + 1;
	while (l <= low && m <= high)
	{
		if (s[l] > 2 * s[m])
		{
			cnt += high-m+1;
			l++;
		}
		else
			m++;
	}

	/*Merge*/
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
		if (buffer1.front() >= buffer2.front())
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