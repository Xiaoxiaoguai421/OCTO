/********************************************************************************
    > File Name: kp.cpp
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年05月06日 星期日 15时06分14秒
********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
const int W = 50;
int Max_value(int w,vector<int> price, vector<int> weight);
int main(void)
{
    vector<int> price(3);
    price[0] = 60;
    price[1] = 100;
    price[2] = 120;
    vector<int> weight(3);
    weight[0] = 10;
    weight[1] = 20;
    weight[2] = 30;

    cout << "背包问题的解是：" << Max_value(W,price, weight) << endl;
    return 0;
}

int Max_value(int w,vector<int> price, vector<int> weight)
{
    int n=weight.size();
    vector<vector<int> > a(w + 1);
    for (int i = 0; i < w + 1; i++) {
        a[i].resize(n + 1);
    }

    //base case
    for (int i = 0; i < w + 1; i++)
        a[i][0] = 0;
    for (int i = 0; i < n + 1; i++)
        a[0][i] = 0;

    for (int i = 1; i < w + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (i < weight[j - 1]) //当前背包重量小于物品，不装
            {
                a[i][j] = a[i][j - 1];
            } else {
                if (a[i][j - 1] <= a[i - weight[j - 1]][j - 1] + price[j - 1]) {
                    a[i][j] = a[i - weight[j - 1]][j - 1] + price[j - 1];
                } else
                    a[i][j] = a[i][j - 1];
            }
        }
    }

    return a[w][n];
}
