/********************************************************************************
    > File Name: path_mgp.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年05月07日 星期一 17时12分37秒
********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
const int INFINITY = 99999;
int shortest_path(vector<vector<int> > w); //起点到终点的最短路程
int main(void)
{
    int n = 8;
    vector<vector<int> > w(n);
    for (int i = 0; i < n; i++)
        w[i].resize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            w[i][j] = 0;
    w[0][1] = 1;    w[0][2] = 2;    w[0][3] = 3;
    w[1][4] = 4;    w[1][5] = 11;
    w[2][4] = 19;   w[2][5] = 5;    w[2][6] = 16;
    w[3][6] = 2;
    w[4][7] = 18;
    w[5][7] = 13;
    w[6][7] = 2;

    cout << "最短路程: " << shortest_path(w) << endl;

    return 0;
}

int shortest_path(vector<vector<int> > w)
{
    int n = w.size();
    vector<int> d(n);
    //    base case
    d[0] = 0;
    for (int i = 1; i < n; i++)
        d[i] = INFINITY;
    //for
    for (int i = 1; i < n; i++) {
        int temp = d[i];
        for (int j = 0; j < i; j++) {
            if (w[j][i] != 0)
                temp = d[j] + w[j][i];
            if (temp < d[i])
                d[i] = temp;
        }
    }
    return d[n - 1];
}
