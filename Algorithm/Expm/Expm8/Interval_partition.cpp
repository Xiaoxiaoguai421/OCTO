/*
 *区间划分
*/

#include <iostream>
#include <stdio.h>
using namespace std;
#define N 100
struct Report {
    int num;       //报告编号
    int begin;     //开始时间
    int end;       //结束时间
    bool flag;     //是否已分配教室
    int classroom; //教室号
};

void QuickSort(Report* rep, int f, int t); //一开始将所有报告按结束时间排序
int select_room(Report* rep, int* time, int n);

int main(void)
{
    int n;
    Report rep[N];
    int time[N]; //每个教室最后一个报告的结束时间
    cout << "请输入报告数量:" << endl;
    cin >> n;
    int i;
    for (i = 0; i < n; i++) {
        //初始化
        time[i + 1] = 0;    //time[1]~time[10]
        rep[i].num = i + 1; //编号1~10
        rep[i].flag = false;
        rep[i].classroom = 0;
        cout << "报告" << i + 1 << "开始时间:";
        cin >> rep[i].begin;
        cout << "报告" << i + 1 << "结束时间:";
        cin >> rep[i].end;
    }
    QuickSort(rep, 0, n - 1);
    int roomNum = select_room(rep, time, n);
    cout << "所用教室总数为:" << roomNum << endl;
    for (i = 0; i < n; i++) {
        cout << "活动" << rep[i].num << "在教室" << rep[i].classroom << "中" << endl;
    }
    char pause;
    pause = getchar();
    return 0;
}

void QuickSort(Report* rep, int f, int t)
{
    if (f < t) {
        int i = f - 1, j = f;
        Report r = rep[t];
        while (j < t) {
            if (rep[j].end <= r.end) {
                i++;
                Report tmp = rep[i];
                rep[i] = rep[j];
                rep[j] = tmp;
            }
            j++;
        }
        Report tmp1 = rep[t];
        rep[t] = rep[i + 1];
        rep[i + 1] = tmp1;
        QuickSort(rep, f, i);
        QuickSort(rep, i + 2, t);
    }
}

int select_room(Report* rep, int* time, int n)
{
    //第一个报告分给第一个教室
    int i = 1, j = 1; //i报告，j教室
    int sumRoom = 1;
    int sumRep = 1; //教室已分配的报告数
    time[1] = rep[0].end;
    rep[0].classroom = 1;
    for (i = 1; i < n; i++) {
        for (j = 1; j <= sumRoom; j++) {
            if ((rep[i].begin >= time[j]) && (!rep[i].flag)) {
                rep[i].classroom = j;
                rep[i].flag = true;
                time[j] = rep[i].end;
                sumRep++;
            }
        }
        if (sumRep < n && i == n - 1) //报告没有分配完
        {
            i = 0;
            sumRoom++;
        }
    }
    return sumRoom;
}
