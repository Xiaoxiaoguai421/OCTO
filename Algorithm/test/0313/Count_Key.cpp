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
const int MaxSize = 6;
int Count(int s[], int low, int middle, int high);
int Count_Key(int s[], int low, int high);
int main(void)
{
	int r[MaxSize];
	cout << "请输入" << MaxSize << "个数\n$:";
	for (int i = 0; i < MaxSize; i++)
		cin >> r[i];
	int count = Count_Key(r, 0, MaxSize - 1);
	cout << "重要逆序对个数为：" << count << endl;
	return 0;
}

/*使用队列*/
int Count_Key(int s[], int low, int high)
{
	int front = 0;
	int back = 0;
	int between = 0;
	int middle;
	if (low < high)
	{
		middle = (low + high) / 2;
		front = Count_Key(s, low, middle);
		back = Count_Key(s, middle + 1, high);
		between = Count(s, low, middle, high);
	}
	return front + back + between;
}

int Count(int s[], int low, int middle, int high)
{
	/*Count Key*/
	int cnt = 0;
	int l = low;
	int m = middle + 1;
	int h = high;
	while (l <= middle && m <= h)
	{
		if (s[l] > 2 * s[m])
		{
			cnt += middle - l + 1;
			m++;
		}
		else
			l++;
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
	return cnt;
}
