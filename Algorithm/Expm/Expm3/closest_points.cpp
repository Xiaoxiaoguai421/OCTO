#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef struct point {
    int x;
    int y;
    void Print()
    {
        cout << '(' << x << ',' << y << ')';
    }
} Point;

double Distance(Point a, Point b)

{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Point Closet[2];

int Pivot(int r[], int n) //求长度为n的序列中位数的近似值
{
    if (n <= 5) //如果序列长度在5以内,通过插入排序求中位数
    {
        int i, j, temp;
        for (i = 1; i < n; i++) {
            temp = r[i];
            for (j = i - 1; j >= 0 && temp < r[j]; j--)
                r[j + 1] = r[j];
            r[j + 1] = temp;
        }
        return r[(n - 1) / 2];
    }

    if (n % 5 == 0) //所有子序列的长度都为5
    {
        int* subMedian = new int[n / 5];
        for (int k = 0; k < n / 5; k++) {
            int temp[5];
            for (int i = 0; i < 5; i++)
                temp[i] = r[5 * k + i];
            subMedian[k] = Pivot(temp, 5);
        }
        return Pivot(subMedian, n / 5);
    } else //最后一个子序列的长度小于5
    {
        int* subMedian = new int[n / 5 + 1];
        for (int k = 0; k < n / 5; k++) {
            int temp[5];
            for (int i = 0; i < 5; i++)
                temp[i] = r[5 * k + i];
            subMedian[k] = Pivot(temp, 5);
        }

        int* temp = new int[n % 5]; //求最后一个子序列的中位数
        for (int i = 0; i < n % 5; i++)
            temp[i] = r[n - n % 5 + i];
        subMedian[n / 5] = Pivot(temp, n % 5);
        return Pivot(subMedian, n / 5 + 1);
    }
}

void SplitTo3(Point r[], int n, int pivot) //将点数为n的点集划分为横坐标<pivot,=pivot,>pivot三个部
{
    int i = 0;
    int j = n - 1; //将点数为n的点集划分为横坐标<pivot,>=pivot两个部分
    Point temp;
    while (i < j) {
        while (i < j && r[i].x < pivot)
            i++;
        while (i < j && r[j].x >= pivot)
            j--;
        temp = r[i];
        r[i] = r[j];
        r[j] = temp;
    }
    j = n - 1; //将点集横坐标>=pivot部分划分为横坐标=pivot,>pivot两个部分
    while (i < j) {
        while (i < j && r[i].x == pivot)
            i++;
        while (i < j && r[j].x > pivot)
            j--;
        temp = r[i];
        r[i] = r[j];
        r[j] = temp;
    }
}

int Select(Point r[], int n, int k) //求点数为n的点集中的横坐标第k小的点,k取(n + 1) / 2时,即求点集横坐标的中位数
{
    int* r_x = new int[n];
    for (int i = 0; i < n; i++)
        r_x[i] = r[i].x;
    int pivot = Pivot(r_x, n); //求点集横坐标中位数的近似值
    SplitTo3(r, n, pivot);     //将点集划分为横坐标<pivot,=pivot,>pivot三个部分
    int s1 = 0, s2 = 0;        //计算点集中横坐标<pivot(s1),<=pivot(s2)的点的个数
    for (int i = 0; i < n; i++)
        if (r[i].x < pivot) {
            s1++;
            s2++;
        } else if (r[i].x == pivot)
            s2++;
    if (k <= s1) {
        Point* r1 = new Point[s1];
        for (int i = 0; i < s1; i++)
            r1[i] = r[i];
        return Select(r1, s1, k);
    } else if (k <= s2)
        return pivot;
    else {
        Point* r2 = new Point[n - s2];
        for (int i = 0; i < n - s2; i++)
            r2[i] = r[i + s2];
        return Select(r2, n - s2, k - s2);
    }
}

int Partition(Point r[], int i, int j)
{
    Point temp;
    temp = r[i];
    while (i < j) {
        while (i < j && r[j].y >= temp.y)
            j--;
        if (i < j)
            r[i++] = r[j];
        while (i < j && r[i].y <= temp.y)
            i++;
        if (i < j)
            r[j--] = r[i];
    }
    r[i] = temp;
    return i;
}

void QuickSort(Point r[], int i, int j)
{
    int pivot;
    if (i < j) {
        pivot = Partition(r, i, j);
        QuickSort(r, i, pivot - 1);
        QuickSort(r, pivot + 1, j);
    }
}

double ClosetPair(Point r[], int n)
{
    Point temp;
    if (n == 2) {
        if (r[0].y > r[1].y) {
            temp = r[0];
            r[0] = r[1];
            r[1] = temp;
        }
        Closet[0] = r[0];
        Closet[1] = r[1];
        return Distance(r[0], r[1]);
    }
    if (n == 3) {
        if (r[0].y > r[1].y) {
            temp = r[0];
            r[0] = r[1];
            r[1] = temp;
        }
        if (r[1].y > r[2].y) {
            temp = r[1];
            r[1] = r[2];
            r[2] = temp;
        }
        if (r[0].y > r[1].y) {
            temp = r[0];
            r[0] = r[1];
            r[1] = temp;
        }

        double d[3] = { Distance(r[0], r[1]), Distance(r[0], r[2]), Distance(r[1], r[2]) };
        double dmin = d[0];
        Closet[0] = r[0];
        Closet[1] = r[1];
        for (int i = 1; i < 3; i++)
            if (d[i] < dmin) {
                dmin = d[i];
                Closet[0] = r[i - 1];
                Closet[1] = r[2];
            }
        return dmin;
    }

    int median = Select(r, n, (n + 1) / 2); //求点集横坐标的中位数
    SplitTo3(r, n, median);
    double d1, d2;

    Point* r1 = new Point[(n + 1) / 2];
    for (int i = 0; i < (n + 1) / 2; i++)
        r1[i] = r[i];
    d1 = ClosetPair(r1, (n + 1) / 2);

    Point Closet1[2];
    for (int i = 0; i < 2; i++)
        Closet1[i] = Closet[i];

    Point* r2 = new Point[n - (n + 1) / 2];
    for (int i = 0; i < n - (n + 1) / 2; i++)
        r2[i] = r[i + (n + 1) / 2];
    d2 = ClosetPair(r2, n - (n + 1) / 2);

    Point Closet2[2];
    for (int i = 0; i < 2; i++)
        Closet2[i] = Closet[i];

    double d;
    if (d1 <= d2) {
        d = d1;
        for (int i = 0; i < 2; i++)
            Closet[i] = Closet1[i];
    } else {
        d = d2;
        for (int i = 0; i < 2; i++)
            Closet[i] = Closet2[i];
    }
    int s = 0;
    for (int i = 0; i < n; i++)
        if (r[i].x >= median - d && r[i].x <= median + d)
            s++;
    Point* r1_2 = new Point[s];
    int k = 0;
    for (int i = 0; k < s; i++)
        if (r[i].x >= median - d && r[i].x <= median + d) {
            r1_2[k] = r[i];
            k++;
        }
    QuickSort(r1_2, 0, s - 1);
    for (int i = 0; i < s - 1; i++) //求点集中所有点中最邻近点对距离
        for (int j = i + 1; j < i + 11 && j < s; j++)
            if (Distance(r1_2[i], r1_2[j]) < d) {
                d = Distance(r1_2[i], r1_2[j]);
                Closet[0] = r1_2[i];
                Closet[1] = r1_2[j];
            }
    return d;
}

int main(void)
{
    int n;
    srand(unsigned(time(NULL)));
    n = 10 + rand() % 20;
    cout << "随机生成" << n << "个点:" << endl;
    Point* Points = new Point[n];
    for (int i = 0; i < n; i++) {
        Points[i].x = rand() % 100;
        Points[i].y = rand() % 100;
    }
    for (int i = 0; i < n; i++) {
        Points[i].Print();
        if ((i + 1) % 10 == 0)
            cout << endl;
        else
            cout << ' ';
    }
    cout << endl;
    double distance = ClosetPair(Points, n);
    cout << "最邻近点对为:";
    Closet[0].Print();
    cout << "--";
    Closet[1].Print();
    cout << " 它们之间的距离为:" << distance << endl;
    return 0;
}
