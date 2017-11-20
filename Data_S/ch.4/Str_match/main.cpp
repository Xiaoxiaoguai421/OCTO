/*************************************************************************
    > File Name: main.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月16日 星期四 17时18分31秒
 ************************************************************************/

#include<iostream>
#include"match.cpp"
#include"FUNC.h"
using namespace std;
const int MaxSize = 100;
int main(void)
{
	char source[MaxSize];
	int next[MaxSize];
	fstream file("data", ios::in);
	Read(source, file);
	file.close();
	char pattern[MaxSize];
	cout << "请输入模式串\n$:";
	cin >> pattern;
	int result = 0;
	clock_t start, end;
	//BF
	start = clock();
	result = BFmatching(source, pattern);
	end = clock();
	if (result == -1)
		cout << "未找到" << endl;
	else
		cout << "模式串在源串首次出现位置" << result << endl;
	cout << "BF用时:" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
	//KMP
	start = clock();
	Getnext(pattern, next);
	result = KMPmatching(source, pattern, next);
	end = clock();
	if (result == -1)
		cout << "未找到" << endl;
	else
		cout << "模式串在源串首次出现位置" << result << endl;
	cout << "KMP用时:" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
	//优化next
	start = clock();
	Getnextval(pattern, next);
	result = KMPmatching(source, pattern, next);
	end = clock();
	if (result == -1)
		cout << "未找到" << endl;
	else
		cout << "模式串在源串中首次出现的位置" << result << endl;
	cout << "KMP(优化next数组)用时：" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

	return 0;
}
