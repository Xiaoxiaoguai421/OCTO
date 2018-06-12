/*
 * 最小延迟调度
*/

#include <iostream>
#include <stdio.h>
using namespace std;
#define N 100
struct Mission {
    int num;
    int last;
    int end;
};
void QuickSort(Mission* mi, int f, int t);

int main(void)
{
    int n;
    cout << "请输入任务总数:" << endl;
    cin >> n;
    Mission mi[N];    //Mission[0]~Mission[n-1]
    int start[N + 1]; //排好序的任务的开始时间，start[1]~start[n]
    int i;
    for (i = 0; i < n; i++) {
        mi[i].num = i + 1;
        cout << "任务" << i + 1 << "的持续时间为:";
        cin >> mi[i].last;
        cout << "任务" << i + 1 << "的截止时间为:";
        cin >> mi[i].end;
    }
    QuickSort(mi, 0, n - 1);
    int delay = 0;
    start[1] = 0;
    if (start[1] + mi[0].last > mi[0].end) {
        delay += start[1] + mi[0].last - mi[0].end; //如果开始时间+持续时间>截止时间，累计延迟
    }
    for (i = 1; i < n; i++) {
        start[i + 1] = start[i] + mi[i - 1].last;
        if (start[i + 1] + mi[i].last > mi[i].end) {
            delay += start[i + 1] + mi[i].last - mi[i].end;
        }
    }
    cout << "延迟最小为:" << delay << endl;
    for (i = 0; i < n; i++) {
        cout << "任务" << mi[i].num << "的执行时间:[" << start[i + 1] << "," << mi[i].last + start[i + 1] << "]" << endl;
    }
    char pause = getchar();
    return 0;
}

void QuickSort(Mission* mi, int f, int t)
{
    if (f < t) {
        int i = f - 1, j = f;
        Mission m = mi[t];
        while (j < t) {
            if (mi[j].end <= m.end) {
                i++;
                Mission tmp = mi[i];
                mi[i] = mi[j];
                mi[j] = tmp;
            }
            j++;
        }
        Mission tmp1 = mi[t];
        mi[t] = mi[i + 1];
        mi[i + 1] = tmp1;
        QuickSort(mi, f, i);
        QuickSort(mi, i + 2, t);
    }
}
