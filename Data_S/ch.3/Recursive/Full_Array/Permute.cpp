/*************************************************************************
    > File Name: Permute.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月05日 星期日 18时33分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int MaxSize = 35;
void Swap(int *num_1, int *num_2);
void Permute(int *pNum, int begin, int length, int &count); //0～begin已经排列好的,排列数的长度length,共有多少种排列count
int main(void)
{
	int n = 0, count = 0;
	int Num[MaxSize];
	cout << "请输入n(n<"<<MaxSize<<")\n$:";
	cin >> n;
	for (int i = 0; i < n; i++)
		Num[i] = i + 1;
	cout << "1~" << n << "的全排列如下" << endl;
	Permute(Num, 0, n, count);
	cout << '\n' << "共有" << count << "个" << endl;
	return 0;
}

void Swap(int *num_1, int *num_2)
{
	int temp = *num_1;
	*num_1 = *num_2;
	*num_2 = temp;
}

void Permute(int *pNum, int begin, int length, int &count)
{
	if (begin == length)
	{
		for (int i = 0; i < length; i++)
		{
			if (pNum[i]  < 10)
				cout << pNum[i];
			else
				cout << char(pNum[i] + 55);
		}
		cout << '\t';
		count++;
		if (count % 6 == 0)
			cout << endl;
	}
	else
		for (int i = begin; i < length; i++)
		{
			Swap(pNum + begin, pNum + i);
			Permute(pNum, begin + 1, length, count);
			Swap(pNum + begin, pNum + i);
		}
}
