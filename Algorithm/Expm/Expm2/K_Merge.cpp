#include <iostream>
using namespace std;
void Merge(int r[], int r1[], int s, int m, int t); //一次归并算法
void MergePass(int r[], int r1[], int n, int h);    //一趟归并排序算法
void MergeSort(int r[], int num, int length);

int main(void)
{
    int num, length;
    cout << "请输入有序数组的个数：";
    cin >> num;
    cout << "请输入每个数组的长度：";
    cin >> length;
    int* array = new int[num * length + 1];
    for (int i = 0; i < num; i++) {
        cout << "请输入第" << i + 1 << "个数组中的元素：";
        for (int j = 1; j <= length; j++)
            cin >> array[length * i + j];
    }

    cout << "基于分治法的k路合并：" << endl;
    MergeSort(array, num, length);
    cout << '\t';
    for (int i = 1; i < num * length + 1; i++)
        cout << array[i] << ' ';
    cout << endl;

    return 0;
}

void Merge(int r[], int r1[], int s, int m, int t)
{
    int i, j, k;
    i = s;
    j = m + 1;
    k = s;
    while (i <= m && j <= t)
        if (r[i] < r[j])
            r1[k++] = r[i++];
        else
            r1[k++] = r[j++];
    while (i <= m)
        r1[k++] = r[i++];
    while (j <= t)
        r1[k++] = r[j++];
}

void MergePass(int r[], int r1[], int n, int h)
{
    int i = 1, k;
    while (i <= n - 2 * h + 1) {
        Merge(r, r1, i, i + h - 1, i + 2 * h - 1);
        i += 2 * h;
    }
    if (i < n - h + 1)
        Merge(r, r1, i, i + h - 1, n);
    else
        for (k = i; k <= n; k++)
            r1[k] = r[k];
}

void MergeSort(int r[], int num, int length)
{

    int n = num * length;
    int h = length;
    int* r1 = new int[n];
    while (h < n) {
        MergePass(r, r1, n, h);
        h = 2 * h;
        MergePass(r1, r, n, h);
        h = 2 * h;
    }
}
