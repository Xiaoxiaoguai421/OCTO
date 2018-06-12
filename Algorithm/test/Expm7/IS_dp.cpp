/*
 * 区间调度
 * 动态规划
*/

#include <iostream>
using namespace std;
int GetSet(int* start, int* finish, int n);

int main()
{
    //已经按完成时间排好序
    int start[] = { -1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 1000 };
    int finish[] = { 0, 5, 6, 7, 8, 9, 10, 11, 12, 13, 10000 };
    int n = 11; //活动只有9个
    cout << "最大兼容活动子集的大小为：" << GetSet(start, finish, n) << endl;
    return 0;
}

int GetSet(int* start, int* finish, int n)
{
    //c[i][j]表示第i个工作结束后到第j个工作开始前之间存在的可兼容的工作个数
    //new c[i][j]
    int** c = new int*[n];
    for (int i = 0; i < n; i++)
        c[i] = new int[n];
    //c[i][j]初始赋值
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (i < j) {
                int s = finish[i];
                int f = start[j];
                for (int k = i + 1; k < j; k++)
                    if (start[k] >= s && finish[k] <= f) {
                        if (c[i][j] < (c[i][k] + c[k][j] + 1))
                            c[i][j] = c[i][k] + c[k][j] + 1; //分解成更小子问题
                    }
            }
        }
    }
    return c[0][n - 1]; //最终目标
}
