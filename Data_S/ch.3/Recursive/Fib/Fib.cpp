/*************************************************************************
    > File Name: Fib.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月03日 星期五 20时06分39秒
 ************************************************************************/

#include<iostream>
#include<ctime>
using namespace std;
long Fib_1(int n);  //递归
long Fib_2(int n, long t0, long t1);    //递归改进
long Fib_3(int n);  //迭代
int main(void)
{
	clock_t start, end;
	int num = 0;
	long result = 0;
	cout << "请输入斐波那契数列的项\n$:";
	cin >> num;

	cout << "普通递归结果" << endl;
	start = clock();
	result = Fib_1(num);
	end = clock();
	cout << result << endl;
	cout << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

	cout << "改进递归结果" << endl;
	start = clock();
	result = Fib_2(num, 0, 1);
	end = clock();
	cout << result << endl;
	cout << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

	cout << "迭代结果" << endl;
	start = clock();
	result = Fib_3(num);
	end = clock();
	cout << result << endl;
	cout << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

	return 0;
}

long Fib_1(int n)
{
	if (n == 0 || n == 1)
		return n;
	return Fib_1(n - 2) + Fib_1(n - 1);
}

long Fib_2(int n, long t0, long t1)
{
	if (n == 0)
		return t0;
	if (n == 1)
		return t1;
	return Fib_2(n - 1, t1, t0 + t1);
}

long Fib_3(int n)
{
	long F_zero = 0;
	long F_one = 1;
	long FN = 0;
	if (n == 0 || n == 1)
		return n;
	for (int i = 2; i <= n; i++)
	{
		FN = F_zero + F_one;
		F_zero = F_one;
		F_one = FN;
	}
	return FN;
}
