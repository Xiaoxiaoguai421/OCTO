/*
 * 区间调度问题
 * 贪心
 * 迭代
*/

#include <cstring>
#include <iostream>
using namespace std;
int GetSet(int* si, int* fi, int n);

int main(void)
{
    int si[] = { 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12 };
    int fi[] = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int n = 11;
    cout << endl
         << "省去排序过程,最兼容活动子集的数目为：" << GetSet(si, fi, n);
    return 0;
}

int GetSet(int* si, int* fi, int n)
{
    //创建一个记录数组，用于最后判定是否选取
    bool* result = new bool[n];
    memset(result, false, sizeof(result));
    result[0] = true;       //初始设定
    int selected_index = 0; //第一个选中的
    for (int i = 1; i < n; i++) {
        if (fi[selected_index] <= si[i]) //这种情况下是能够兼容的
        {
            result[i] = true;
            selected_index = i;
        }
    }
    //输出
    int nct = 0;
    cout << "最大兼容子集为：";
    for (int i = 0; i < n; i++) {
        if (result[i] == true) {
            cout << i + 1 << "\t";
            nct++;
        }
    }
    return nct;
}
