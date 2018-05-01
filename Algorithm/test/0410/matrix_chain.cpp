/*************************************************************************
    > File Name: matrix_chain.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月24日 星期二 15时04分51秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;
const int INFINITY = 99999;
int matrix_chain(vector<int> p);
int main(void)
{
	int num = 0;
	cout << "请输入矩阵数量：";
	cin >> num;
	vector<int> p(num + 1);
	cout << "请输入"<<num+1<<"个矩阵信息：";
	for (int i = 0; i <= num; i++)
		cin >> p[i];
	cout << "相乘的最少次数为：" << matrix_chain(p) << endl;
	return 0;
}

int matrix_chain(vector<int> p)
{
	int n = p.size()-1;
	vector<vector<int> > m(n + 1);
	vector<vector<int> > s(n + 1);  //记录k值
	for (int i = 1; i <= n; i++)
	{
		m[i].resize(n + 1);
		s[i].resize(n + 1);
	}
	for (int i = 1; i <= n; i++)
		m[i][i] = 0;
	for (int len = 2; len <= n; len++)
		for (int i = 1; i <= n - len+1; i++)
		{
			int j = i + len-1;
			m[i][j]= INFINITY;
			for (int k = i; k < j; k++)
			{
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j]=k;
				}
			}
		}
	return m[1][n];
}
