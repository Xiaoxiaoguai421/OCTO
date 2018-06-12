/*
 * 区间调度
 * 贪心算法
 * 每次递归，规模减小1~n
*/

#include <iostream>
using namespace std;
void GetSet(int* si, int* fi, int i, int n);
int main(void)
{
    int si[] = { -1, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12 };
    int fi[] = { -1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int n = 11;
    GetSet(si, fi, 0, 11);
}

void GetSet(int* si, int* fi, int i, int n)
{
    int m = i + 1;
    while (m <= n && si[m] < fi[i]) //找第一个符合的
        m = m + 1;
    if (m <= n) {
        cout << m << "\t";
        GetSet(si, fi, m, n);
    }
}
