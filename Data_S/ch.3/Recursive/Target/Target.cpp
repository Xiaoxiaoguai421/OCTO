/*************************************************************************
    > File Name: Target.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月04日 星期六 16时48分31秒
 ************************************************************************/

#include<iostream>
using namespace std;
int Count(int sum, int time);
int main(void)
{
	cout << Count(90, 10) << endl;
	return 0;
}

int Count(int sum, int time) //sum目标环数,time打靶次数
{
	int cnt = 0;
	if (sum > time * 10)
		return 0;
	if (sum == time * 10)
		return 1;
	if (time == 1 && sum >= 0 && sum < 10)
		return 1;
	else
	{
		for (int i = 0; i <= 10; i++)
			cnt += Count(sum - i, time - 1);
		return cnt;
	}
}
