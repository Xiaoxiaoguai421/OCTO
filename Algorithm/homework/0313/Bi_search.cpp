/*************************************************************************
    > File Name: Bi_search.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年03月19日 星期一 20时52分00秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int MaxSize = 5;
int Bi_search(int A[], int key, int low, int high);
int main(void)
{
	int A[MaxSize];
	cout << "请输入" << MaxSize << "个数:\n$:";
	for (int i = 0; i < MaxSize; i++)
		cin >> A[i];
	int key;
	cout << "请输入要查询的数:";
	cin >> key;
	int post = Bi_search(A, key, 0, MaxSize - 1);
	if (post == -1)
		cout << "未找到" << endl;
	else
		cout << key << "位于数组中第" << post + 1 << "个" << endl;
	return 0;
}

int Bi_search(int A[], int key, int low, int high)
{
	if (low > high)
		return -1;
	if (low < high)
	{
		int midlle = low + (high - low) / 2;
		if (A[midlle] == key)
			return midlle;
		if (A[midlle] > key)
			return Bi_search(A, key, low, midlle - 1);
		else
			return Bi_search(A, key, midlle + 1, high);
	}
}
