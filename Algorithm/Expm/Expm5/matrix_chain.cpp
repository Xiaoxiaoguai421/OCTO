/*************************************************************************
    > File Name: matrix_chain.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月24日 星期二 15时04分51秒
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;
const int INFINITY = 99999;
void matrix_chain(vector<int> p);
void print_matrix(int i, int j, vector<vector<int> > s);
int main(void)
{
    int num = 0;
    cout << "请输入矩阵数量：";
    cin >> num;
    vector<int> p(num + 1);
    cout << "请输入矩阵信息:";
    for (int i = 0; i < num + 1; i++)
        cin >> p[i];
    /*
    srand((unsigned)time(0));
    for (int i = 0; i < num; i++)
        p[i]=rand()%50+1;*/
    matrix_chain(p);
    return 0;
}

void matrix_chain(vector<int> p)
{
    int n = p.size();
    vector<vector<int> > m(n);
    vector<vector<int> > s(n); //记录k值
    for (int i = 0; i < n; i++) {
        m[i].resize(n);
        s[i].resize(n);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
            s[i][j] = 0;
        }

    for (int len = 1; len <= n - 1; len++)
        for (int i = 1; i <= n - 1 - len; i++) {
            int j = i + len;
            m[i][j] = INFINITY;
            s[i][j] = i;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    cout << "相乘的最少次数为：" << m[1][n - 1] << endl;
    print_matrix(1, n - 1, s);
}

void print_matrix(int i, int j, vector<vector<int> > s)
{
    if (i == j)
        cout << "A" << i;
    else {
        cout << "(";
        print_matrix(i, s[i][j], s);
        print_matrix(s[i][j] + 1, j, s);
        cout << ")";
    }
}
