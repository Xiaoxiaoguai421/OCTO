/*************************************************************************
    > File Name: LCS.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月17日 星期二 19时15分44秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
void Print_LCS(vector<vector<int> > D, const char *x, int i, int j);
void LCS(string x, string y);
int main(void)
{
	string str1;
	string str2;
	cout << "请输入两端字符串" << endl;
	cin >> str1 >> str2;
	LCS(str1, str2);
	return 0;
}

void Print_LCS(vector<vector<int> > D, const char *x, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (D[i][j] == 0)
	{
		Print_LCS(D, x, i - 1, j - 1);
		cout << x[i - 1];
	}
	else if (D[i][j] == 1)     Print_LCS(D, x, i - 1, j);
	else    Print_LCS(D, x, i, j - 1);
}

void LCS(string x, string y)
{
	const char *s1 = x.data();
	const char *s2 = y.data();
	int n = x.length();
	int m = y.length();

	vector<vector<int> > L(n + 1);
	for (int i = 0; i <= n; i++)
		L[i].resize(m + 1);

	vector<vector<int> > D(n + 1);
	for (int i = 0; i <= n; i++)
		D[i].resize(m + 1);


	//填L[][]表格,记录每次选择D[][]
	for (int i = 0; i <= n; i++)
		L[i][0] = 0;
	for (int i = 0; i <= m; i++)
		L[0][i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (s1[i-1] == s2[j-1])
			{
				L[i][j] = L[i - 1][j - 1] + 1;
				D[i][j] = 0;
			}
			else if (L[i - 1][j] > L[i][j - 1])
			{
				L[i][j] = L[i - 1][j];
				D[i][j] = 1;
			}
			else
			{
				L[i][j] = L[i][j - 1];
				D[i][j] = -1;
			}
		}
	cout << "最大公共子串的长度为：" << L[n][m] << endl;
	cout << "最大公共子串为：";
	Print_LCS(D, s1, n, m);
	cout << endl;
}
